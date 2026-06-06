
#ifndef CRYPTO_CDD_H
#define CRYPTO_CDD_H

#include "Std_Types.h"
#include "Crypto_GeneralTypes.h"

#define CRYPTO_KEY_IV_SIZE        12
#define BSW_FEE_BLOCK_SIZE        1024

#define AEAD_GCM_TAGLEN      16

typedef union
{
	uint32 U32;
	uint8 Arry[4];
}U32_Arry4_Union;

extern uint8 Nvm_Bsw_Data[1024];


int Decrypt_ByteData(
	        unsigned char* pKey,            /*��Կ*/
            int nKeyLen,
			unsigned char* pIV ,            /*��ʼ������*/
            int nIVLen,
			unsigned char* pHDR,            /*ͷ-��������*/
			int nHdrLen,
			unsigned char* pCiphertext,     /*����*/
			int nCtextLen,
			unsigned char* pTag,            /*��֤ʶ����*/
			unsigned char* pOutPlaintext);  /*����*/

int Encrypt_ByteData(
	        unsigned char* pKey,            /*��Կ*/
			int nKeyLen,
			unsigned char* pIV,             /*��ʼ������*/
			int nIVLen,
			unsigned char* pHDR,
			int nHdrLen,
			unsigned char* pPlaintext,     /*����*/
			int nPtextLen,
			unsigned char* pOutCiphertext, /*����*/
			unsigned char* pOutTag);       /*��֤ʶ����*/

Std_ReturnType Crypto_SW_UpLoadKeyConvert(uint8* SrcKeyPtr, uint32* DstKeyptr);
Std_ReturnType Crypto_SW_ProcessJob(uint32 objectId, Crypto_JobType* job);
Std_ReturnType Crypto_SW_CancelJob (uint32 objectId, Crypto_JobType* job);
Std_ReturnType Crypto_SW_KeyElementSet (uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength);
Std_ReturnType Crypto_SW_KeySetValid (uint32 cryIfKeyId);
Std_ReturnType Crypto_SW_KeyElementGet (uint32 cryIfKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr);
Std_ReturnType Crypto_SW_KeyElementCopy (uint32 cryIfKeyId, uint32 keyElementId, uint32 targetCryIfKeyId, uint32 targetKeyElementId);
Std_ReturnType Crypto_SW_KeyElementCopyPartial (uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId) ;
Std_ReturnType Crypto_SW_KeyCopy (uint32 cryIfKeyId, uint32 targetCryIfKeyId);
Std_ReturnType Crypto_SW_RandomSeed (uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength);
Std_ReturnType Crypto_SW_KeyGenerate (uint32 cryIfKeyId) ;
Std_ReturnType Crypto_SW_KeyDerive (uint32 cryIfKeyId, uint32 targetCryIfKeyId);
Std_ReturnType Crypto_SW_KeyExchangeCalcPubVal (uint32 cryIfKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr);
Std_ReturnType Crypto_SW_KeyExchangeCalcSecret (uint32 cryIfKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength);
Std_ReturnType Crypto_SW_CertificateParse (uint32 cryIfKeyId);
Std_ReturnType Crypto_SW_CertificateVerify (uint32 cryIfKeyId, uint32 verifyCryIfKeyId, Crypto_VerifyResultType* verifyPtr);
Std_ReturnType Crypto_SW_KeyElementIdsGet(uint32 cryIfKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr);
Std_ReturnType CryIf_Prv_Dummy_KeyGetStatus(uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr);
Std_ReturnType CryIf_SW_Prv_Dummy_Rb_StorePermanentData(void);

uint16 Crypto_GetKeyIndex(uint32 KeyId);













#endif
