
#include "DHCryptlib.h"
#include "stdio.h"
#include "string.h"
#include "Crypto_SW.h"


#define _MaxText_Length_ 1024  //���ӽ������ݳ��� 

void xor_block_aligned(void *r, const void *p, const void *q)
{
	rep3_u4(f_xor, UNIT_PTR(r), UNIT_PTR(p), UNIT_PTR(q), UNIT_VAL);
}
void gf_mulx1_lb(gf_t r, const gf_t x)
{   
	gf_unit_t _tt;
	_tt = gf_tab[(UNIT_PTR(x)[3] >> 17) & MASK(0x80)];

	rep2_d4(f1_lb, UNIT_PTR(r), UNIT_PTR(x));
	UNIT_PTR(r)[0] ^= _tt;
}
void init_4k_table(const gf_t g, gf_t4k_t t)
{   
	int j, k;

	memset(t[0], 0, GF_BYTE_LEN);

	memcpy(t[128], g, GF_BYTE_LEN);
	for(j = 64; j >= 1; j >>= 1)
		gf_mulx1(gcm_mode)(t[j], t[j + j]);
	for(j = 2; j < 256; j += j)
		for(k = 1; k < j; ++k)
			xor_block_aligned(t[j + k], t[j], t[k]);
}

#define xor_4k(i,ap,t,r) gf_mulx8(gcm_mode)(r); xor_block_aligned(r, r, t[ap[GF_INDEX(i)]])

#define inc_ctr(x)  \
{   int i = BLOCK_SIZE; while(i-- > CTR_POS && !++(UI8_PTR(x)[i])) ; }

ret_type gcm_init_and_key(          /* initialise mode and set key  */
	const unsigned char key[],      /* the key value                */
	unsigned long key_len,          /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{
	memset(ctx->ghash_h, 0, sizeof(ctx->ghash_h));

	//aes_encrypt_key(key, key_len, ctx->aes);
	aes_setkey_enc(ctx->aes, key, key_len * 8);

	/* compute E(0) (for the hash function)     */
	//aes_encrypt(UI8_PTR(ctx->ghash_h), UI8_PTR(ctx->ghash_h), ctx->aes);
	aes_encrypt(ctx->aes, UI8_PTR(ctx->ghash_h), UI8_PTR(ctx->ghash_h));

#if defined( TABLES_4K )
	init_4k_table(ctx->ghash_h, ctx->gf_t4k);
#endif
	return RETURN_GOOD;
}
void copy_block_aligned(void *p, const void *q)
{
	 rep2_u4(f_copy,UNIT_PTR(p),UNIT_PTR(q));
}
void gf_mulx8_lb(gf_t x)
{   gf_unit_t _tt;

   _tt = gf_tab[UNIT_PTR(x)[3] >> 24];

   rep2_d4(f8_lb, UNIT_PTR(x), UNIT_PTR(x));
   UNIT_PTR(x)[0] ^= _tt;
}

#define xor_4k(i,ap,t,r) gf_mulx8(gcm_mode)(r); xor_block_aligned(r, r, t[ap[GF_INDEX(i)]])
void gf_mul_4k(gf_t a, const gf_t4k_t t, gf_t r)
{   
	uint_8t *ap = (uint_8t*)a;
	memset(r, 0, GF_BYTE_LEN);
	xor_4k(15, ap, t, r); xor_4k(14, ap, t, r);
	xor_4k(13, ap, t, r); xor_4k(12, ap, t, r);
	xor_4k(11, ap, t, r); xor_4k(10, ap, t, r);
	xor_4k( 9, ap, t, r); xor_4k( 8, ap, t, r);
	xor_4k( 7, ap, t, r); xor_4k( 6, ap, t, r);
	xor_4k( 5, ap, t, r); xor_4k( 4, ap, t, r);
	xor_4k( 3, ap, t, r); xor_4k( 2, ap, t, r);
	xor_4k( 1, ap, t, r); xor_4k( 0, ap, t, r);
	copy_block_aligned(a, r);
}
void gf_mul_hh(gf_t a, gcm_ctx ctx[1])
{
	gf_t    scr;
	gf_mul_4k(a, ctx->gf_t4k, scr);
}
ret_type gcm_init_message(                  /* initialise a new message     */
	const unsigned char iv[],       /* the initialisation vector    */
	unsigned long iv_len,           /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{   
	uint_32t i, n_pos = 0;
	uint_8t *p;

	memset(ctx->ctr_val, 0, BLOCK_SIZE);
	if(iv_len == CTR_POS)
	{
		memcpy(ctx->ctr_val, iv, CTR_POS); UI8_PTR(ctx->ctr_val)[15] = 0x01;
	}
	else
	{   n_pos = iv_len;
	while(n_pos >= BLOCK_SIZE)
	{
		xor_block_aligned(ctx->ctr_val, ctx->ctr_val, iv);
		n_pos -= BLOCK_SIZE;
		iv += BLOCK_SIZE;
		gf_mul_hh(ctx->ctr_val, ctx);
	}

	if(n_pos)
	{
		p = UI8_PTR(ctx->ctr_val);
		while(n_pos-- > 0)
			*p++ ^= *iv++;
		gf_mul_hh(ctx->ctr_val, ctx);
	}
	n_pos = (iv_len << 3);
	for(i = BLOCK_SIZE - 1; n_pos; --i, n_pos >>= 8)
		UI8_PTR(ctx->ctr_val)[i] ^= (unsigned char)n_pos;
	gf_mul_hh(ctx->ctr_val, ctx);
	}

	ctx->y0_val = *UI32_PTR(UI8_PTR(ctx->ctr_val) + CTR_POS);
	memset(ctx->hdr_ghv, 0, BLOCK_SIZE);
	memset(ctx->txt_ghv, 0, BLOCK_SIZE);
	ctx->hdr_cnt = 0;
	ctx->txt_ccnt = ctx->txt_acnt = 0;
	return RETURN_GOOD;
}
void xor_block(void *r, const void* p, const void* q)
{
	rep3_u16(f_xor, UI8_PTR(r), UI8_PTR(p), UI8_PTR(q), UI8_VAL);
}

ret_type gcm_auth_header(                   /* authenticate the header      */
	const unsigned char hdr[],      /* the header buffer            */
	unsigned long hdr_len,          /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{  
	uint_32t cnt = 0, b_pos = (uint_32t)ctx->hdr_cnt & BLK_ADR_MASK;

	if(!hdr_len)
		return RETURN_GOOD;

	if(ctx->hdr_cnt && b_pos == 0)
		gf_mul_hh(ctx->hdr_ghv, ctx);

	if(!((hdr - (UI8_PTR(ctx->hdr_ghv) + b_pos)) & BUF_ADRMASK))
	{
		while(cnt < hdr_len && (b_pos & BUF_ADRMASK))
			UI8_PTR(ctx->hdr_ghv)[b_pos++] ^= hdr[cnt++];

		while(cnt + BUF_INC <= hdr_len && b_pos <= BLOCK_SIZE - BUF_INC)
		{
			*UNIT_PTR(UI8_PTR(ctx->hdr_ghv) + b_pos) ^= *UNIT_PTR(hdr + cnt);
			cnt += BUF_INC; b_pos += BUF_INC;
		}

		while(cnt + BLOCK_SIZE <= hdr_len)
		{
			gf_mul_hh(ctx->hdr_ghv, ctx);
			xor_block_aligned(ctx->hdr_ghv, ctx->hdr_ghv, hdr + cnt);
			cnt += BLOCK_SIZE;
		}
	}
	else
	{
		while(cnt < hdr_len && b_pos < BLOCK_SIZE)
			UI8_PTR(ctx->hdr_ghv)[b_pos++] ^= hdr[cnt++];

		while(cnt + BLOCK_SIZE <= hdr_len)
		{
			gf_mul_hh(ctx->hdr_ghv, ctx);
			xor_block(ctx->hdr_ghv, ctx->hdr_ghv, hdr + cnt);
			cnt += BLOCK_SIZE;
		}
	}

	while(cnt < hdr_len)
	{
		if(b_pos == BLOCK_SIZE)
		{
			gf_mul_hh(ctx->hdr_ghv, ctx);
			b_pos = 0;
		}
		UI8_PTR(ctx->hdr_ghv)[b_pos++] ^= hdr[cnt++];
	}

	ctx->hdr_cnt += cnt;
	return RETURN_GOOD;
}

//////////////////////////////////////////////////////////////////////////

ret_type gcm_crypt_data(                    /* encrypt or decrypt data      */
	unsigned char data[],           /* the data buffer              */
	unsigned long data_len,         /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{   
	uint_32t cnt = 0, b_pos = (uint_32t)ctx->txt_ccnt & BLK_ADR_MASK;

	if(!data_len)
		return RETURN_GOOD;

	if(!((data - (UI8_PTR(ctx->enc_ctr) + b_pos)) & BUF_ADRMASK))
	{
		if(b_pos)
		{
			while(cnt < data_len && (b_pos & BUF_ADRMASK))
				data[cnt++] ^= UI8_PTR(ctx->enc_ctr)[b_pos++];

			while(cnt + BUF_INC <= data_len && b_pos <= BLOCK_SIZE - BUF_INC)
			{
				*UNIT_PTR(data + cnt) ^= *UNIT_PTR(UI8_PTR(ctx->enc_ctr) + b_pos);
				cnt += BUF_INC; b_pos += BUF_INC;
			}
		}

		while(cnt + BLOCK_SIZE <= data_len)
		{
			inc_ctr(ctx->ctr_val);
			//aes_encrypt(UI8_PTR(ctx->ctr_val), UI8_PTR(ctx->enc_ctr), ctx->aes);
			aes_encrypt(ctx->aes,UI8_PTR(ctx->ctr_val), UI8_PTR(ctx->enc_ctr));
			xor_block_aligned(data + cnt, data + cnt, ctx->enc_ctr);
			cnt += BLOCK_SIZE;
		}
	}
	else
	{
		if(b_pos)
			while(cnt < data_len && b_pos < BLOCK_SIZE)
				data[cnt++] ^= UI8_PTR(ctx->enc_ctr)[b_pos++];

		while(cnt + BLOCK_SIZE <= data_len)
		{
			inc_ctr(ctx->ctr_val);
			//aes_encrypt(UI8_PTR(ctx->ctr_val), UI8_PTR(ctx->enc_ctr), ctx->aes);
			aes_encrypt(ctx->aes, UI8_PTR(ctx->ctr_val), UI8_PTR(ctx->enc_ctr));
			xor_block(data + cnt, data + cnt, ctx->enc_ctr);
			cnt += BLOCK_SIZE;
		}
	}

	while(cnt < data_len)
	{
		if(b_pos == BLOCK_SIZE || !b_pos)
		{
			inc_ctr(ctx->ctr_val);
			//aes_encrypt(UI8_PTR(ctx->ctr_val), UI8_PTR(ctx->enc_ctr), ctx->aes);
			aes_encrypt(ctx->aes, UI8_PTR(ctx->ctr_val), UI8_PTR(ctx->enc_ctr));
			b_pos = 0;
		}
		data[cnt++] ^= UI8_PTR(ctx->enc_ctr)[b_pos++];
	}

	ctx->txt_ccnt += cnt;
	return RETURN_GOOD;
}

ret_type gcm_auth_data(                     /* authenticate ciphertext data */
	const unsigned char data[],     /* the data buffer              */
	unsigned long data_len,         /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{   
	uint_32t cnt = 0, b_pos = (uint_32t)ctx->txt_acnt & BLK_ADR_MASK;

	if(!data_len)
		return RETURN_GOOD;

	if(ctx->txt_acnt && b_pos == 0)
		gf_mul_hh(ctx->txt_ghv, ctx);

	if(!((data - (UI8_PTR(ctx->txt_ghv) + b_pos)) & BUF_ADRMASK))
	{
		while(cnt < data_len && (b_pos & BUF_ADRMASK))
			UI8_PTR(ctx->txt_ghv)[b_pos++] ^= data[cnt++];

		while(cnt + BUF_INC <= data_len && b_pos <= BLOCK_SIZE - BUF_INC)
		{
			*UNIT_PTR(UI8_PTR(ctx->txt_ghv) + b_pos) ^= *UNIT_PTR(data + cnt);
			cnt += BUF_INC; b_pos += BUF_INC;
		}

		while(cnt + BLOCK_SIZE <= data_len)
		{
			gf_mul_hh(ctx->txt_ghv, ctx);
			xor_block_aligned(ctx->txt_ghv, ctx->txt_ghv, data + cnt);
			cnt += BLOCK_SIZE;
		}
	}
	else
	{
		while(cnt < data_len && b_pos < BLOCK_SIZE)
			UI8_PTR(ctx->txt_ghv)[b_pos++] ^= data[cnt++];

		while(cnt + BLOCK_SIZE <= data_len)
		{
			gf_mul_hh(ctx->txt_ghv, ctx);
			xor_block(ctx->txt_ghv, ctx->txt_ghv, data + cnt);
			cnt += BLOCK_SIZE;
		}
	}

	while(cnt < data_len)
	{
		if(b_pos == BLOCK_SIZE)
		{
			gf_mul_hh(ctx->txt_ghv, ctx);
			b_pos = 0;
		}
		UI8_PTR(ctx->txt_ghv)[b_pos++] ^= data[cnt++];
	}

	ctx->txt_acnt += cnt;
	return RETURN_GOOD;
}

ret_type gcm_encrypt(                       /* encrypt & authenticate data  */
	unsigned char data[],           /* the data buffer              */
	unsigned long data_len,         /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{
	gcm_crypt_data(data, data_len, ctx);
	gcm_auth_data(data, data_len, ctx);
	return RETURN_GOOD;
}


/* A slow field multiplier */

void gf_mul(gf_t a, const gf_t b)
{   
	gf_t p[8];
	uint_8t *q, ch;
	int i;

	copy_block_aligned(p[0], a);
	for(i = 0; i < 7; ++i)
		gf_mulx1(gcm_mode)(p[i + 1], p[i]);

	q = (uint_8t*)(a == b ? p[0] : b);
	memset(a, 0, GF_BYTE_LEN);
	for(i = 15 ;  ; )
	{
		ch = q[GF_INDEX(i)];
		if(ch & X_0)
			xor_block_aligned(a, a, p[0]);
		if(ch & X_1)
			xor_block_aligned(a, a, p[1]);
		if(ch & X_2)
			xor_block_aligned(a, a, p[2]);
		if(ch & X_3)
			xor_block_aligned(a, a, p[3]);
		if(ch & X_4)
			xor_block_aligned(a, a, p[4]);
		if(ch & X_5)
			xor_block_aligned(a, a, p[5]);
		if(ch & X_6)
			xor_block_aligned(a, a, p[6]);
		if(ch & X_7)
			xor_block_aligned(a, a, p[7]);
		if(!i--)
			break;
		gf_mulx8(gcm_mode)(a);
	}
}

ret_type gcm_compute_tag(                   /* compute authentication tag   */
	unsigned char tag[],            /* the buffer for the tag       */
	unsigned long tag_len,          /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{  
	uint_32t i, ln;
	gf_t tbuf;

	if(ctx->txt_acnt != ctx->txt_ccnt && ctx->txt_ccnt > 0)
		return RETURN_ERROR;

	gf_mul_hh(ctx->hdr_ghv, ctx);
	gf_mul_hh(ctx->txt_ghv, ctx);

	if(ctx->hdr_cnt)
	{
		ln = (uint_32t)((ctx->txt_acnt + BLOCK_SIZE - 1) / BLOCK_SIZE);
		if(ln)
		{
			/* alternative versions of the exponentiation operation */
			memcpy(tbuf, ctx->ghash_h, BLOCK_SIZE);

			for( ; ; )
			{
				if(ln & 1)
				{
					gf_mul(ctx->hdr_ghv, tbuf);
				}
				if(!(ln >>= 1))
					break;
				gf_mul(tbuf, tbuf);
			}
		}
	}

	i = BLOCK_SIZE; 

	{   uint_64t tm = ((uint_64t)ctx->txt_acnt) << 3;
	while(i-- > 0)
	{
		UI8_PTR(ctx->hdr_ghv)[i] ^= UI8_PTR(ctx->txt_ghv)[i] ^ (unsigned char)tm;
		tm = (i == 8 ? (((uint_64t)ctx->hdr_cnt) << 3) : tm >> 8);
	}
	}


	gf_mul_hh(ctx->hdr_ghv, ctx);

	memcpy(ctx->enc_ctr, ctx->ctr_val, BLOCK_SIZE);
	*UI32_PTR(UI8_PTR(ctx->enc_ctr) + CTR_POS) = ctx->y0_val;
	//aes_encrypt(UI8_PTR(ctx->enc_ctr), UI8_PTR(ctx->enc_ctr), ctx->aes);
	aes_encrypt(ctx->aes, UI8_PTR(ctx->enc_ctr), UI8_PTR(ctx->enc_ctr));
	for(i = 0; i < (unsigned int)tag_len; ++i)
		tag[i] = (unsigned char)(UI8_PTR(ctx->hdr_ghv)[i] ^ UI8_PTR(ctx->enc_ctr)[i]);

	return (ctx->txt_ccnt == ctx->txt_acnt ? RETURN_GOOD : RETURN_WARN);
}

ret_type gcm_end(                           /* clean up and end operation   */
	gcm_ctx ctx[1])                 /* the mode context             */
{
	memset(ctx, 0, sizeof(gcm_ctx));
	return RETURN_GOOD;
}
//////////////////////////////////////////////////////////////////////////
ret_type gcm_decrypt(                       /* authenticate & decrypt data  */
	unsigned char data[],           /* the data buffer              */
	unsigned long data_len,         /* and its length in bytes      */
	gcm_ctx ctx[1])                 /* the mode context             */
{
	gcm_auth_data(data, data_len, ctx);
	gcm_crypt_data(data, data_len, ctx);
	return RETURN_GOOD;
}

//////////////////////////////////////////////////////////////////////////
void GetBCDFrom16Xchar(char *fromText,unsigned char *toData,int toDatalen)
{
	unsigned char data = 0,pos;
	memset(toData,0,toDatalen);
	for(int i=strlen(fromText)-1;i>=0;i--)
	{
		data = 0;
		if(*(fromText+i)>='0' && *(fromText+i)<='9')
			data = (*(fromText+i)-'0');
		else if(*(fromText+i)>='a' && *(fromText+i)<='f')
			data = (*(fromText+i)-'a'+10);
		else if(*(fromText+i)>='A' && *(fromText+i)<='F')
			data = (*(fromText+i)-'A'+10);
		if( (int)((strlen(fromText)-i-1)/2) > (toDatalen-1)) break;
		pos = strlen(fromText)-i-1;
		if(pos%2==0)
			*(toData+pos/2) = *(toData+pos/2)+data;
		else
			*(toData+pos/2) = *(toData+pos/2)+0x10*data;
	}
}
//��CString �����ݵ��뵽 Byte * ��
//����ֽ�����Ϊż������ȱ��λǰ��0
//���CString���� < BYTE *ָ�����ȣ���BYTE*��λ��AA
int CopyCharToByte(char* pfrom,unsigned char* todata,int datalen)
{	
	memset(todata,0X00,datalen);
	int nlen=strlen(pfrom);
	if(nlen<1||nlen%2!=0)return -1;
	char temChar[3]="";
	int nDataLen=datalen;
	if(nDataLen>(nlen+1)/2)
		nDataLen = (nlen+1)/2;
	for(int i=0;i<nDataLen;i++)
	{
		if(i<nDataLen)
		{
			temChar[0] =  pfrom[i*2]; // pfrom[nlen-2-i*2];
		    temChar[1]  = pfrom[i*2+1];
		}
		else
			continue;
		unsigned char bbtmp;
		GetBCDFrom16Xchar(temChar,&bbtmp,1);
		memcpy(todata+i,&bbtmp,1);
	}
	return 1;
}
int Encrypt_ByteData(unsigned char* pKey/*��Կ*/,int nKeyLen,unsigned char* pIV/*��ʼ������*/,int nIVLen,unsigned char* pHDR, int nHdrLen,unsigned char* pPlaintext/*����*/,int nPtextLen,unsigned char* pOutCiphertext/*����*/,unsigned char* pOutTag/*��֤ʶ����*/)
{
	unsigned char   key[16], iv[12], hdr[_MaxText_Length_], ptx[_MaxText_Length_], tbuf[16];
	int             key_len, iv_len, hdr_len, ptx_len, ctx_len, tag_len;

	//��Կ���ȹ̶�Ϊ16�ֽ�
	key_len=nKeyLen;
	if(key_len!=16)return -1;
	memcpy(key,pKey,key_len);
	//��ʼ�������̶�Ϊ12�ֽ�
	iv_len=nIVLen;
	if(iv_len!=12)return -1;
	memcpy(iv,pIV,iv_len);

	if(nHdrLen>=_MaxText_Length_)return -1;
	hdr_len=nHdrLen;
	if(hdr_len>0)
	   memcpy(hdr,pHDR,hdr_len);

	//����
	ptx_len=0;
	memset(ptx,0,_MaxText_Length_);
	if(nPtextLen>=_MaxText_Length_)return -1;
	ptx_len=nPtextLen;
	if(ptx_len>0)
	   memcpy(ptx,pPlaintext,ptx_len);
	
	ctx_len=ptx_len;
	pOutTag[0]=0;

	//���ܿ�ʼ
	gcm_ctx contx[1];
	//////////////////////////////////////////////////////////////////////////
	gcm_init_and_key(key, key_len,contx);
	gcm_init_message(iv, iv_len, contx);

	gcm_auth_header(hdr, hdr_len, contx);

	memcpy(pOutCiphertext, ptx, ptx_len);
	gcm_encrypt(pOutCiphertext, ptx_len, contx);

	//����Tag
	tag_len=AEAD_GCM_TAGLEN;
	gcm_compute_tag(tbuf, tag_len,contx);
	memcpy(pOutTag,tbuf, tag_len);

	gcm_end(contx);

	return 1;
}
int Encrypt_StringData(char* pKey/*��Կ*/,char* pIV/*��ʼ������*/,char* pHDR,char* pPlaintext/*����*/,char* pOutCiphertext/*����*/,char* pOutTag/*��֤ʶ����*/)
{
	unsigned char   key[16], iv[12], hdr[_MaxText_Length_], ptx[_MaxText_Length_], ctx[_MaxText_Length_],tag[AEAD_GCM_TAGLEN];
	int             key_len, iv_len, hdr_len, ptx_len, tag_len, i;
	//Tag����Ϊ12�ֽ�
	tag_len=AEAD_GCM_TAGLEN;
	//��Կ���ȹ̶�Ϊ16�ֽ�
	key_len=strlen(pKey)/2;
	if(key_len!=16)return -1;
	CopyCharToByte(pKey,key,key_len);

	//��ʼ�������̶�Ϊ12�ֽ�
	iv_len=strlen(pIV)/2;
	if(iv_len!=12)return -1;
	CopyCharToByte(pIV,iv,iv_len);

	hdr_len=strlen(pHDR)/2;
	if(hdr_len>=_MaxText_Length_)return -1;
	if(hdr_len>0)
	{
		
		CopyCharToByte(pHDR,hdr,hdr_len);
	}
	else
	{
		hdr_len=0;
		hdr[0]=0;
	}

	//����
	ptx_len=strlen(pPlaintext)/2;
	if(ptx_len>=_MaxText_Length_)return -1;
	if(ptx_len>0)
	{
		CopyCharToByte(pPlaintext,ptx,ptx_len);
	}
	else
	{
		ptx_len=0;
	}
	int nRet= Encrypt_ByteData(key,key_len,iv,iv_len,hdr,hdr_len,ptx,ptx_len,ctx,tag);
	if(nRet==1)
	{//��������
		pOutCiphertext[0]=0;
		char temp[10]="";
		for (i=0;i<ptx_len;i++)
		{
			sprintf(temp,"%02X",ctx[i]);
			strcat(pOutCiphertext,temp);
		}
		//����Tag
		pOutTag[0]=0;
		for (i=0;i<tag_len;i++)
		{
			sprintf(temp,"%02x",tag[i]);
			strcat(pOutTag,temp);
		}
	}
	return nRet;
}
int Decrypt_ByteData(unsigned char* pKey, int nKeyLen, unsigned char* pIV, int nIVLen, unsigned char* pHDR/*ͷ-��������*/,int nHdrLen,unsigned char* pCiphertext /*����*/,int nCtextLen,unsigned char* pTag /*��֤ʶ����*/,unsigned char* pOutPlaintext/*����*/)
{//���� -1�������������0�����ܴ��� 1��������ȷ
	unsigned char   key[16], iv[12], hdr[_MaxText_Length_],  ctx[_MaxText_Length_], tbuf[16];
	int             key_len, iv_len, hdr_len, ctx_len, tag_len, i;
	//��Կ���ȹ̶�Ϊ16�ֽ�
	key_len=nKeyLen;
	if(key_len!=16)return -1;
	memcpy(key,pKey,key_len);
	//��ʼ�������̶�Ϊ12�ֽ�
	iv_len=nIVLen;
	if(iv_len!=12)return -1;
	memcpy(iv,pIV,iv_len);

	hdr_len=nHdrLen;
	if(hdr_len>=100)return -1;
	if(hdr_len>0)
		memcpy(hdr,pHDR,nHdrLen);

	//����
	if(nCtextLen>=_MaxText_Length_)return -1;
	ctx_len=nCtextLen;
	if(ctx_len>0)
		memcpy(ctx,pCiphertext,ctx_len);

// 	ctx_len=0;
// 	pTag[0]=0;

	//���ܿ�ʼ
	gcm_ctx contx[1];
	//buf[0]=0;
	gcm_init_and_key(key, key_len,(gcm_ctx*) contx);
	gcm_init_message(iv, iv_len,(gcm_ctx*) contx);

	gcm_auth_header(hdr, hdr_len,(gcm_ctx*) contx);

	memcpy(pOutPlaintext, ctx, ctx_len);
	gcm_decrypt(pOutPlaintext, ctx_len,(gcm_ctx*) contx);
	//memcpy(pOutPlaintext,buf, ctx_len);
	//Tag����Ϊ12�ֽ�
	int nOKFlag=1;
	if(pTag)
	{
		tag_len=AEAD_GCM_TAGLEN;
		gcm_compute_tag(tbuf, tag_len,(gcm_ctx*) contx);
		for (i=0;i<tag_len;i++)
		{
			/*if(pTag[i]!=tbuf[i])
			{
				nOKFlag=0;
				break;
			}*/
			pTag[i] = tbuf[i];
		}
	}
	gcm_end((gcm_ctx*)contx);
	return nOKFlag;
}
int Decrypt_StringData(char* pKey/*��Կ*/,char* pIV/*��ʼ������*/,char* pHDR,char* pCiphertext/*����*/,char* pTag/*��֤ʶ����*/,char* pOutPlaintext/*����*/)
{
	unsigned char   key[16], iv[12], hdr[_MaxText_Length_],  ctx[_MaxText_Length_], buf[_MaxText_Length_], tbuf[16];
	int             key_len, iv_len, hdr_len, ptx_len, ctx_len, tag_len, i;

	//��Կ���ȹ̶�Ϊ16�ֽ�
	key_len=strlen(pKey)/2;
	if(key_len!=16) return -1;
	CopyCharToByte(pKey,key,key_len);
	
	//��ʼ�������̶�Ϊ12�ֽ�
	iv_len=strlen(pIV)/2;
	if(iv_len!=12) return -1;
	CopyCharToByte(pIV,iv,iv_len);

	hdr_len=strlen(pHDR)/2;
	if(hdr_len>100)return -1;
	if(hdr_len>0)
	{
		CopyCharToByte(pHDR,hdr,hdr_len);
	}
	else
	{
		hdr_len=0;
		hdr[0]=0;
	}
	//����
	if(strlen(pCiphertext)>0)
	{
		CopyCharToByte(pCiphertext,ctx,strlen(pCiphertext));
		ctx_len=strlen(pCiphertext)/2;
	}
	else
	{
		ctx_len=0;
	}
	ptx_len=0;
	tag_len=AEAD_GCM_TAGLEN;
	pTag[0]=0;

	//���ܿ�ʼ
	gcm_ctx contx[1];
	buf[0]=0;
	gcm_init_and_key(key, key_len,(gcm_ctx*) contx);
	gcm_init_message(iv, iv_len,(gcm_ctx*) contx);

	gcm_auth_header(hdr, hdr_len,(gcm_ctx*) contx);

	memcpy(buf, ctx, ctx_len);
	gcm_decrypt(buf, ctx_len,(gcm_ctx*) contx);
	char temp[5]="";
	for (i=0;i<ctx_len;i++)
	{
		sprintf(temp,"%02x",buf[i]);
		strcat(pOutPlaintext,temp);
	}

	gcm_compute_tag(tbuf, tag_len,(gcm_ctx*) contx);
	for (i=0;i<tag_len;i++)
	{
		sprintf(temp,"%02x",tbuf[i]);
		strcat(pTag,temp);
	}
	gcm_end((gcm_ctx*)contx);
	return 1;
}
/**
 * aes_wrap - Wrap keys with AES Key Wrap Algorithm (128-bit KEK) (RFC3394)
 * @kek: 16-octet Key encryption key (KEK)
 * @n: Length of the plaintext key in 64-bit units; e.g., 2 = 128-bit = 16
 * bytes
 * @plain: Plaintext key to be wrapped, n * 64 bits
 * @cipher: Wrapped key, (n + 1) * 64 bits
 *@gcm_ctx:ctx
 * Returns: 0 on success, -1 on failure
 */
int aes_wrap(const unsigned char *kek, int n, const unsigned char *plain, unsigned char *cipher,aes_context aes[1])
{
	unsigned char *a, *r, b[16];
	int i, j;


	a = cipher;
	r = cipher + 8;

	/* 1) Initialize variables. */
	memset(a, 0xa6, 8);
	memcpy(r, plain, 8 * n);


	/* set the AES key                          */
	//aes_encrypt_key(kek, 16, aes);
	aes_setkey_enc(aes, kek, 16 * 8);

	/* 2) Calculate intermediate values.
	 * For j = 0 to 5
	 *     For i=1 to n
	 *         B = AES(K, A | R[i])
	 *         A = MSB(64, B) ^ t where t = (n*j)+i
	 *         R[i] = LSB(64, B)
	 */
	for (j = 0; j <= 5; j++) {
		r = cipher + 8;
		for (i = 1; i <= n; i++) {
			memcpy(b, a, 8);
			memcpy(b + 8, r, 8);
			/* compute E(0) (for the hash function)     */
			//aes_encrypt(b, b, aes);
			aes_encrypt(aes, b, b);
			memcpy(a, b, 8);
			a[7] ^= n * j + i;
			memcpy(r, b + 8, 8);
			r += 8;
		}
	}
	memset(aes, 0, sizeof(aes_encrypt_ctx));

	/* 3) Output the results.
	 *
	 * These are already in @cipher due to the location of temporary
	 * variables.
	 */

	return 0;
}
int aes_wrap_String(char* pKey,char* pPlain,char* pCipher)
{
	aes_context contx[1];
	unsigned char kek[16];
	memset(&kek,0,16);
	int nKeyLen=16;//strlen(pKey)/2;
	unsigned char Plaintext[50];
	int nPlainLen=16;//strlen(pPlain)/2;
	memset(&Plaintext,0,50);
	CopyCharToByte(pKey,kek,nKeyLen);
	CopyCharToByte(pPlain,Plaintext,nPlainLen);
	unsigned char Cipher[50];
	memset(&Cipher,0,50);
	
	int nRet=aes_wrap(kek,2,Plaintext,Cipher,contx);

	pCipher[0]=0;
	char temp[10]="";
	for (int i=0;i<24;i++)
	{
		sprintf(temp,"%02X",Cipher[i]);
		strcat(pCipher,temp);
	}
	return nRet;
}
int aes_wrap_byte(unsigned char* pKey,unsigned char* pPlain,unsigned char* pCipher)
{
	aes_context contx[1];
	int nRet=aes_wrap(pKey,2,pPlain,pCipher,contx);
	return nRet;
}
/**
 * aes_unwrap - Unwrap key with AES Key Wrap Algorithm (128-bit KEK) (RFC3394)
 * @kek: Key encryption key (KEK)
 * @n: Length of the plaintext key in 64-bit units; e.g., 2 = 128-bit = 16
 * bytes
 * @cipher: Wrapped key to be unwrapped, (n + 1) * 64 bits
 * @plain: Plaintext key, n * 64 bits
 * Returns: 0 on success, -1 on failure (e.g., integrity verification failed)
 */
int aes_unwrap(const unsigned char *kek, int n, const unsigned char *cipher, unsigned char *plain,aes_context aes[1])
{
	unsigned char a[8], *r, b[16];
	int i, j;

	/* 1) Initialize variables. */
	memcpy(a, cipher, 8);
	r = plain;
	memcpy(r, cipher + 8, 8 * n);

	//aes_decrypt_key(kek, 16,aes);
	aes_setkey_dec(aes, kek, 16 * 8);
	if (aes == NULL)
		return -1;

	/* 2) Compute intermediate values.
	 * For j = 5 to 0
	 *     For i = n to 1
	 *         B = AES-1(K, (A ^ t) | R[i]) where t = n*j+i
	 *         A = MSB(64, B)
	 *         R[i] = LSB(64, B)
	 */
	for (j = 5; j >= 0; j--) {
		r = plain + (n - 1) * 8;
		for (i = n; i >= 1; i--) {
			memcpy(b, a, 8);
			b[7] ^= n * j + i;

		    memcpy(b + 8, r, 8);
			//aes_decrypt(b, b, aes);
			aes_decrypt(aes, b, b);
		//	aes_decrypt(ctx, b, b);
			memcpy(a, b, 8);
			memcpy(r, b + 8, 8);
			r -= 8;
		}
	}
	memset(aes, 0, sizeof(aes_decrypt_ctx));

	/* 3) Output results.
	 *
	 * These are already in @plain due to the location of temporary
	 * variables. Just verify that the IV matches with the expected value.
	 */
	for (i = 0; i < 8; i++) {
		if (a[i] != 0xa6)
			return -1;
	}

	return 0;
}
int aes_unwrap_string(char* pKey,char* pCipher,char* pPlain)
{
	aes_context contx[1];
	int nCipherLen=24;
	int nPlainLen=16;
	unsigned char kek[16];
	memset(&kek,0,16);
	CopyCharToByte(pKey,kek,16);
	unsigned char Plaintext[50];
	memset(&Plaintext,0,50);
	unsigned char Cipher[50];
	memset(&Cipher,0,50);
	CopyCharToByte(pCipher,Cipher,24);
	pPlain[0]=0;
	int nRet=aes_unwrap(kek,2,Cipher,Plaintext,contx);
	char temp[5]="";
	for (int i=0;i<16;i++)
	{
		sprintf(temp,"%02X",Plaintext[i]);
		strcat(pPlain,temp);
	}
	return nRet;
}
int aes_unwrap_byte(unsigned char* pKey,unsigned char* pCipher,unsigned char* pPlain)
{
	aes_context contx[1];
	return aes_unwrap(pKey,2,pCipher,pPlain,contx);
}

