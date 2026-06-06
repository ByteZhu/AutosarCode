#include "Crypto.h"
#include "CryIf_Crypto_Wrapper.h"
#include "CryIf_Prv.h"
#include "Crypto_Cfg.h"
#include "Csm.h"
#include "c_mac.h"
#include "string.h"
#include "Crc.h"
#include "NvM_Cfg.h"
#include "Dcm.h"
#include "Dem.h"
#include "NvM.h"
#include "MemIf.h"
#include "string.h"
#include "SecOC_Cfg.h"

#include "IdsM.h"

uint8 Secoc_KEY_judge(uint8* key,uint8*comparekey);
tp_SecOC_KeyId_Mapping SecOC_KeyId_Mapping[2] = 
{//  req   cfg
	{1,   	1},
	{2,     2}
};
uint16 SecOC_KeyId_Mapping_Size = sizeof(SecOC_KeyId_Mapping) / sizeof(tp_SecOC_KeyId_Mapping);

uint16 getSecOCRealKeyId(uint16 reqKeyId)
{
	int i;
	for(i = 0; i != SecOC_KeyId_Mapping_Size; i++)
	{
		if(SecOC_KeyId_Mapping[i].ReqKeyId == reqKeyId)
		{
			return SecOC_KeyId_Mapping[i].CfgKeyId;
		}
	}
	return 0xFFFF;
}

Std_ReturnType DeviceKey_Deal_2E_D0E9 (uint8* Data, uint8* ErrorCode)
{
	Std_ReturnType retValue_t = E_OK;
	static uint16 ContentWrited = 0;
	static uint16 WaitCount = 0;
	static uint8 bMainfunc_Called = 0;

	if(ContentWrited == 0)      // 淇濊瘉涓�娆¤皟鐢ㄥ彧鎵ц涓�娆�
	{
		uint8 key[16] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
		uint8 Out[64] = {0};
		int outlen = 64;
		int ret_cbc = 0;
		ret_cbc =  aes_decrypt_cbc_no_padding(key, 16, Data, Data + 16, 32, Out, &outlen);
		if(!ret_cbc && (32 == outlen))   //sucsess
		{
			int i;
			for(i = 0; i != 16; i++)
			{
				if(0 != *(Out + 16 + i))
				{
					break;
				}
			}
			if(i != 16)
			{

				Ids_Evt_AuthFreshValVerifFail data;
				data.sensitiveData = IDS_SENSITIVE_DATE_SYMMETRIC;
				data.sensitiveOp = IDS_SENSITIVE_OP_READ;
				data.did = 0x01;
				data.sensitiveOpRes = IDS_SENSITIVE_OP_RES_UNKNOWN;

				Ids_SetSecurityEventWithContextData(IDS_COMPROMISE_SENSITIVE_DATA, (uint8_t *)&data, sizeof(Ids_Evt_AuthFreshValVerifFail));
				#if(DemEvent_D0C451 != 65535)
					Dem_SetEventStatus(DemEvent_D0C451, DEM_EVENT_STATUS_FAILED);
				#endif
				ContentWrited = 0;
				WaitCount = 0;
				bMainfunc_Called = 0;
				*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_CONDITIONSNOTCORRECT;
				return (retValue_t = E_NOT_OK);
			}

			Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_DevKey, 1, Out, 128);
			ContentWrited = 1;
		}
		else
		{
			Ids_Evt_AuthFreshValVerifFail data;
			data.sensitiveData = IDS_SENSITIVE_DATE_SYMMETRIC;
			data.sensitiveOp = IDS_SENSITIVE_OP_READ;
			data.did = 0x01;
			data.sensitiveOpRes = IDS_SENSITIVE_OP_RES_UNKNOWN;

			Ids_SetSecurityEventWithContextData(IDS_COMPROMISE_SENSITIVE_DATA, (uint8_t *)&data, sizeof(Ids_Evt_AuthFreshValVerifFail));
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_CONDITIONSNOTCORRECT;
			return (retValue_t = E_NOT_OK);
		}		
	}

	if(ContentWrited == 1)
	{
		NvM_Rb_StatusType status_NvM;
		MemIf_StatusType stMemIf_en;

		if(0 == bMainfunc_Called)//鑷冲皯纭鎴愬姛璋冪敤MAINFUNCTION 涓�娆�
		{
			if(Cdd_SafeNVM_MainFunction())    
			{
				*ErrorCode = ( Dcm_NegativeResponseCodeType )E_OK;
				return (retValue_t = DCM_E_PENDING);
			}
			else
			{
				bMainfunc_Called = 1;
			}
		}
	
		NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();

		if((status_NvM != NVM_RB_STATUS_BUSY ) && (stMemIf_en != MEMIF_BUSY))
		{
			// #if(DemEvent_D0C451 != 65535)                                    //鐩墠杩樹笉纭浠�涔堟椂鍊欒缃负鎴愬姛
			// 	Dem_SetEventStatus(DemEvent_D0C451, DEM_EVENT_STATUS_PASSED);
			// #endif
			*ErrorCode = ( Dcm_NegativeResponseCodeType )E_OK;
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			return (retValue_t = E_OK);
		}
		else
		{
			WaitCount ++;
			if(WaitCount < (20000 / DcmMainFunc_Cycle))                //濡侾ENDING璁剧疆涓轰笉闄愬埗娆℃暟锛岄偅涔堟澶勪篃浼氶檺鍒舵渶澶�20S
			{
				*ErrorCode = ( Dcm_NegativeResponseCodeType )E_OK;
				return (retValue_t = DCM_E_PENDING);
			}
			else
			{
				Ids_Evt_AuthFreshValVerifFail data;
				data.sensitiveData = IDS_SENSITIVE_DATE_SYMMETRIC;
				data.sensitiveOp = IDS_SENSITIVE_OP_READ;
				data.did = 0x01;
				data.sensitiveOpRes = IDS_SENSITIVE_OP_RES_UNKNOWN;

				Ids_SetSecurityEventWithContextData(IDS_COMPROMISE_SENSITIVE_DATA, (uint8_t *)&data, sizeof(Ids_Evt_AuthFreshValVerifFail));

				*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_GENERALPROGRAMMINGFAILURE;
				ContentWrited = 0;
				WaitCount = 0;
				bMainfunc_Called = 0;
				return (retValue_t = E_NOT_OK);
			}
		}

	}
	return retValue_t;
}

Std_ReturnType SecOCKey_Deal_2E_C05D (uint8* Data, uint8* ErrorCode)
{
	Std_ReturnType retValue_t = E_OK;
	static uint16 ContentWrited = 0;
	static uint16 WaitCount = 0;
	static uint8 bMainfunc_Called = 0;
	uint8 key[16] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	uint8 PlainText[64] = {0};
	if(ContentWrited == 0)      // 淇濊瘉涓�娆¤皟鐢ㄥ彧鎵ц涓�娆�
	{

		uint32 PlainTextLen = 64;
		uint8 verify = 0;
		uint16 cfgKeyId = getSecOCRealKeyId((uint16)Data[0]);
		if(0xFFFF == cfgKeyId)
		{
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL);
			*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_REQUESTOUTOFRANGE;
			return (retValue_t = E_NOT_OK);
		}

		if(0xFFFF == Crypto_GetKeyIndex((uint32)cfgKeyId))
		{
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL);
			*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_REQUESTOUTOFRANGE;
			return (retValue_t = E_NOT_OK);
		}
		if(Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_DevKey, 5, Data + 1, 12 * 8))
		{
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL);
			*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_CONDITIONSNOTCORRECT;
			return (retValue_t = E_NOT_OK);
		}

		if(Csm_AEADDecrypt(CsmConf_CsmJob_CsmJob_GCM_DEC, CRYPTO_OPERATIONMODE_SINGLECALL, Data + 21, 16, Data + 13, 8, Data + 37, 128, PlainText, &PlainTextLen, &verify))
		{
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			if(Secoc_KEY_judge(key,PlainText)==E_NOT_OK)
			{
				Ids_SetSecurityEvent(IDS_SECOC_KEY_RESET_FAIL);
			}
			else
			{
				Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL);
			}

			*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_CONDITIONSNOTCORRECT;
			return (retValue_t = E_NOT_OK);
		}

		if((verify != CRYPTO_E_VER_OK) || (16 != PlainTextLen))
		{
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			if(Secoc_KEY_judge(key,PlainText)==E_NOT_OK)
			{
				Ids_SetSecurityEvent(IDS_SECOC_KEY_RESET_FAIL);
			}
			else
			{
				Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL);
			}
			*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_CONDITIONSNOTCORRECT;
			return (retValue_t = E_NOT_OK);
		}
		Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_SecOC_CMAC_Ele, 1, PlainText, PlainTextLen * 8);
		ContentWrited = 1;
	}

	if(ContentWrited == 1)
	{
		NvM_Rb_StatusType status_NvM;
		MemIf_StatusType stMemIf_en;

		if(0 == bMainfunc_Called)//鑷冲皯纭鎴愬姛璋冪敤MAINFUNCTION 涓�娆�
		{
			if(Cdd_SafeNVM_MainFunction())    
			{
				*ErrorCode = ( Dcm_NegativeResponseCodeType )E_OK;
				return (retValue_t = DCM_E_PENDING);
			}
			else
			{
				bMainfunc_Called = 1;
			}
		}
	
		NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();

		if((status_NvM != NVM_RB_STATUS_BUSY ) && (stMemIf_en != MEMIF_BUSY))
		{
			*ErrorCode = ( Dcm_NegativeResponseCodeType )E_OK;
			ContentWrited = 0;
			WaitCount = 0;
			bMainfunc_Called = 0;
			if(Secoc_KEY_judge(key,PlainText)==E_NOT_OK)
			{
			Ids_SetSecurityEvent(IDS_SECOC_KEY_RESET_SUCCESS);
			}
			else
			{
			Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_SUCCESS);
			}
			return (retValue_t = E_OK);
		}
		else
		{
			WaitCount ++;
			if(WaitCount < (20000 / DcmMainFunc_Cycle))                //濡侾ENDING璁剧疆涓轰笉闄愬埗娆℃暟锛岄偅涔堟澶勪篃浼氶檺鍒舵渶澶�20S
			{
				*ErrorCode = ( Dcm_NegativeResponseCodeType )E_OK;
				return (retValue_t = DCM_E_PENDING);
			}
			else
			{
				*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_GENERALPROGRAMMINGFAILURE;
				ContentWrited = 0;
				WaitCount = 0;
				bMainfunc_Called = 0;
				if(Secoc_KEY_judge(key,PlainText)==E_NOT_OK)
				{
					Ids_SetSecurityEvent(IDS_SECOC_KEY_RESET_FAIL);
				}
				else
				{
					Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL);
				}
				return (retValue_t = E_NOT_OK);
			}
		}

	}
	return retValue_t;
}

Std_ReturnType SysKeyTest_Deal_31_B050(uint8  dataIn1, uint8 OpStatus, uint8 * dataOut1, uint8 * ErrorCode)
{
	Std_ReturnType retValue_t = E_OK;
	uint16 CfgKeyId;
	uint8 MacKey_key[20] = {0};
	uint32 MacKey_keylen = 160;
	uint8 Input[16] = {0xFF, 0xFF, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0x5A, 0xFF, 0xFF};
	uint8 Output[16] = {0};
	CfgKeyId = getSecOCRealKeyId((uint16)dataIn1);
	if(0xFFFF == CfgKeyId)
	{
		*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_REQUESTOUTOFRANGE;
		return (retValue_t = E_NOT_OK);
	}
	if(Csm_KeyElementGet(CfgKeyId, 1, MacKey_key, &MacKey_keylen))
	{
		*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_REQUESTOUTOFRANGE;
		return (retValue_t = E_NOT_OK);
	}
	if(MacKey_keylen != 128)
	{
		*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_REQUESTOUTOFRANGE;
		return (retValue_t = E_NOT_OK);
	}
	AES_CMAC(MacKey_key, Input, 16, Output);

	memcpy(dataOut1, Output, 16);

	*ErrorCode = ( Dcm_NegativeResponseCodeType )E_OK;
	return (retValue_t = E_OK);
}


void SecOC_DefaultKey_CheckRoutine(void)
{
	int i,j;
	for(i = 0; i != CRYPTO_KEY_NUM; i++)
	{
		if(CryptoKeys[i].KeyType == ENUM_KEYTYPE_SECOC)
		{
			uint8 MacKey_key[40] = {0};
			uint32 MacKey_keylen = 40 * 8;
			if(Csm_KeyElementGet(CryptoKeys[i].KeyId, 1, MacKey_key, &MacKey_keylen))
			{

				#if(DemEvent_D0C451 != 65535)                                    
	 				Dem_SetEventStatus(DemEvent_D0C451, DEM_EVENT_STATUS_FAILED);
				#endif
				return;
			}
			if(MacKey_keylen != 128)
			{

				#if(DemEvent_D0C451 != 65535)                                    
	 				Dem_SetEventStatus(DemEvent_D0C451, DEM_EVENT_STATUS_FAILED);
				#endif
				return;
			}
			for(j = 0; j != MacKey_keylen/8; j++)
			{
				if(MacKey_key[j] != 0xFF)
				{
					break;
				}
			}
			if(j >= MacKey_keylen/8)
			{

				#if(DemEvent_D0C451 != 65535)                                    
	 				Dem_SetEventStatus(DemEvent_D0C451, DEM_EVENT_STATUS_FAILED);
				#endif
				return;
			}
		}
	}

	 #if(DemEvent_D0C451 != 65535)                                    
	 	Dem_SetEventStatus(DemEvent_D0C451, DEM_EVENT_STATUS_PASSED);
	 #endif
	 return;
}

//*******************************************************************************************************
void Crypto_CheckNvmValid(void)
{
	int i,j;
	U32_Arry4_Union tmpCrc = {0};
	uint32 NvmRealCrc;
	
	memcpy(tmpCrc.Arry, Nvm_Bsw_Data + BSW_FEE_BLOCK_SIZE - 4, 4);
	NvmRealCrc = Crc_CalculateCRC32(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE - 4, 0, TRUE);
	if(tmpCrc.U32 != NvmRealCrc)
	{
		return;
	}
	
	for(i = 0; i != CRYPTO_KEY_NUM; i++ )
	{
		for(j = 0; j != CRYPTO_KEYELEMENT_NUM; j++)
		{

			U32_Arry4_Union tmpKeyValid = {0};
			if( NULL_PTR == CryptoKeys[i].KeyElements[j].ValidCheck_pt)
			{
				continue;
			}
			memcpy(tmpKeyValid.Arry, Nvm_Bsw_Data + CryptoKeys[i].KeyElements[j].NvmOffset + CryptoKeys[i].KeyElements[j].ElementSize, 4);
			if(0x5A5AA5A5 == tmpKeyValid.U32)
			{
				memcpy(CryptoKeys[i].KeyElements[j].ValidCheck_pt, tmpKeyValid.Arry, 4);
				CryptoKeys[i].KeyElements[j].NvmEleKeyValid = TRUE;
			}
		}
	}
}



void Crypto_LoadNvmKeys(void)
{
	int i,j;
	for(i = 0; i != CRYPTO_KEY_NUM; i++)
	{
		for(j = 0; j != CRYPTO_KEYELEMENT_NUM; j++)
		{
			if(TRUE == CryptoKeys[i].KeyElements[j].NvmEleKeyValid)
			{
				memcpy(CryptoKeys[i].KeyElements[j].Element_Pt, Nvm_Bsw_Data + CryptoKeys[i].KeyElements[j].NvmOffset, CryptoKeys[i].KeyElements[j].ElementSize);
				CryptoKeys[i].KeyElements[j].KeyEleValid = TRUE;
			}
		}
	}
}

void Crypto_Init(void)
{
	Crypto_CheckNvmValid();
	Crypto_LoadNvmKeys();

	CryIf_Init(NULL_PTR);
	Csm_Init(NULL_PTR);
	SecOC_Init (&SecOC_Config);
}

//****************************************************************************
extern uint32 My_TestAndSet(uint32* var);
Std_ReturnType Cdd_SafeNVM_MainFunction(void)
{
	static uint8 Mutext_flg = 1;
	static uint32 Os_lock_Nvm = 0;
	DISABLE();
	while (0U != My_TestAndSet(&Os_lock_Nvm)) {}
	if(Mutext_flg == 1)
	{
		Mutext_flg = 0;
		Os_lock_Nvm = 0;
		DSYNC();
		ENABLE();

		NvM_MainFunction();
		MemIf_Rb_MainFunction();

		Mutext_flg = 1;

		return E_OK;
	}
	else
	{
		Os_lock_Nvm = 0;
		DSYNC();
		ENABLE();
		return E_NOT_OK;
	}
}
uint32 My_TestAndSet(uint32* var)
{
	return __swap(var, 1U);
}
uint8 Secoc_KEY_judge(uint8* key,uint8*comparekey)
{
	uint8 i = 0;
	for(i=0;i<16;i++)
	{
		if(key[i] == comparekey[i])
		{
			return E_OK;
		}
		else
		{
			return E_NOT_OK;
		}
	}

}
//*********************************************************

