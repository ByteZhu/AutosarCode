#include "CryIf_Crypto_Wrapper.h"
#include "CryIf_Prv.h"
#include "Crypto_Cfg.h"
#include "Csm_Cfg.h"
#include "Crc.h"
#include "NvM_Cfg.h"
#include "string.h"
#include "NvM.h"
#include "c_mac.h"
//#include "CDD_FVM.h"
//#include "Fee_User.h"




Std_ReturnType  NvmSecuredDataWrite(uint8* BlockAddr, uint16 BlockSize)
{
	U32_Arry4_Union tmpCrc = {0};
	tmpCrc.U32 = Crc_CalculateCRC32(BlockAddr,(uint32)(BlockSize-4U),0,TRUE);

	BlockAddr[BlockSize-4U] = tmpCrc.Arry[0];
	BlockAddr[BlockSize-3U] = tmpCrc.Arry[1];
	BlockAddr[BlockSize-2U] = tmpCrc.Arry[2];
	BlockAddr[BlockSize-1U] = tmpCrc.Arry[3];

	NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_NativeBlock_2, BlockAddr);
	//NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_NATIVE_IDS_1024, BlockAddr);

	return E_OK;
}

Std_ReturnType  NvmSIDSDataWrite(uint8* BlockAddr, uint16 BlockSize)
{
	/*U32_Arry4_Union tmpCrc = {0};
	tmpCrc.U32 = Crc_CalculateCRC32(BlockAddr,(uint32)(BlockSize-4U),0,TRUE);

	BlockAddr[BlockSize-4U] = tmpCrc.Arry[0];
	BlockAddr[BlockSize-3U] = tmpCrc.Arry[1];
	BlockAddr[BlockSize-2U] = tmpCrc.Arry[2];
	BlockAddr[BlockSize-1U] = tmpCrc.Arry[3];*/
	NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_NATIVE_IDS_1024, BlockAddr);

	return E_OK;
}

uint16 Crypto_GetObjIndex(uint32 objectId)
{
	uint16 i;
	for(i = 0; i != CRYPTO_OBJ_NUM; i++)
	{
		if(objectId == Crypto_Objects[i].CryptoDriverObjectId)
		{
			return i;
		}
	}
	return 0xffff;
}

uint16 Crypto_GetKeyIndex(uint32 KeyId)
{
	uint16 i;
	for(i = 0; i != CRYPTO_KEY_NUM; i++)
	{
		if(KeyId == CryptoKeys[i].KeyId)
		{
			return i;
		}
	}
	return 0xffff;
}

uint16 Crypto_GetKeyElementIndex(uint32 KeyIndex, uint32 keyElementId)
{
	uint16 i;
	for(i = 0; i != CRYPTO_KEYELEMENT_NUM; i++)
	{
		if(keyElementId == CryptoKeys[KeyIndex].KeyElements[i].KeyElementId)
		{
			return i;
		}
	}
	return 0xffff;
}


Std_ReturnType Crypto_SW_AEADEncrypt(uint8* KeyP, uint32 KeyLenth, uint8* KeyIv, Crypto_JobPrimitiveInputOutputType* InputOutputP, Crypto_AlgorithmFamilyType Req_family, Crypto_AlgorithmFamilyType Req_secondaryFamily, Crypto_AlgorithmModeType Req_mode)
{

	if((NULL_PTR == KeyP) || ((KeyLenth != 128) && (KeyLenth != 192) && (KeyLenth != 256)))
	{
		return CRYPTO_E_KEY_NOT_AVAILABLE;
	}
	if((NULL_PTR == InputOutputP->inputPtr) || (NULL_PTR == InputOutputP->secondaryInputPtr) || (NULL_PTR == InputOutputP->outputPtr) || (NULL_PTR == InputOutputP->secondaryOutputPtr))
	{
		return E_NOT_OK;
	}
	if((NULL_PTR == InputOutputP->outputLengthPtr) || (NULL_PTR == InputOutputP->secondaryOutputLengthPtr))
	{
		return E_NOT_OK;
	}
	
	if(Req_family != CRYPTO_ALGOFAM_AES)
	{
		return E_NOT_OK;
	}

	switch(Req_mode)
	{
	case CRYPTO_ALGOMODE_GCM:
	{
		if(*(InputOutputP->outputLengthPtr) < InputOutputP->inputLength)
		{
			return E_NOT_OK;
		}
		if(NULL_PTR == KeyIv)
		{
			return E_NOT_OK;
		}

		Encrypt_ByteData(KeyP, KeyLenth/8 ,KeyIv ,CRYPTO_KEY_IV_SIZE, (unsigned char*)InputOutputP->secondaryInputPtr,InputOutputP->secondaryInputLength, (unsigned char*)InputOutputP->inputPtr, InputOutputP->inputLength, InputOutputP->outputPtr, InputOutputP->secondaryOutputPtr);			

		*(InputOutputP->outputLengthPtr) = InputOutputP->inputLength;
		*(InputOutputP->secondaryOutputLengthPtr) = AEAD_GCM_TAGLEN;
	}
	break;
	default:
	{

	}
	break;
	}
	
	return E_OK;

}

Std_ReturnType Crypto_SW_AEADDecrypt(uint8* KeyP, uint32 KeyLenth, uint8* KeyIv, Crypto_JobPrimitiveInputOutputType* InputOutputP, Crypto_AlgorithmFamilyType Req_family, Crypto_AlgorithmFamilyType Req_secondaryFamily, Crypto_AlgorithmModeType Req_mode)
{
	uint8 MacOutTemp[16] = {0};
	uint16 i = 0;

	if((NULL_PTR == KeyP) || ((KeyLenth != 128) && (KeyLenth != 192) && (KeyLenth != 256)))
	{
		return CRYPTO_E_KEY_NOT_AVAILABLE;
	}
	if((NULL_PTR == InputOutputP->inputPtr) || (NULL_PTR == InputOutputP->secondaryInputPtr) || (NULL_PTR == InputOutputP->secondaryInputPtr) || (NULL_PTR == InputOutputP->outputPtr) || (NULL_PTR == InputOutputP->verifyPtr))
	{
		return E_NOT_OK;
	}

	if(NULL_PTR == InputOutputP->outputLengthPtr)
	{
		return E_NOT_OK;
	}
	
	if(Req_family != CRYPTO_ALGOFAM_AES)
	{
		return E_NOT_OK;
	}
	switch(Req_mode)
	{
	case CRYPTO_ALGOMODE_GCM:
	{
		if(*(InputOutputP->outputLengthPtr) < InputOutputP->inputLength)
		{
			return E_NOT_OK;
		}
		if(NULL_PTR == KeyIv)
		{
			return E_NOT_OK;
		}

		Decrypt_ByteData(KeyP, KeyLenth/8 ,KeyIv , CRYPTO_KEY_IV_SIZE, (unsigned char*)InputOutputP->secondaryInputPtr,InputOutputP->secondaryInputLength, (unsigned char*)InputOutputP->inputPtr,InputOutputP->inputLength, MacOutTemp,InputOutputP->outputPtr);	
		
		*(InputOutputP->outputLengthPtr) = InputOutputP->inputLength;
		
		for(i = 0; i != InputOutputP->tertiaryInputLength/8; i++)
		{
			if(MacOutTemp[i] != InputOutputP->tertiaryInputPtr[i])
			{
				*(InputOutputP->verifyPtr) = CRYPTO_E_VER_NOT_OK;
				return E_OK;			
			}
		}
		*(InputOutputP->verifyPtr) = CRYPTO_E_VER_OK;
		return E_OK;
	}
	default:
	{

	}
	break;
	}
	
	return E_OK;


}

Std_ReturnType Crypto_SW_Encrypt(uint8* KeyP, uint32 KeyLenth, Crypto_JobPrimitiveInputOutputType* InputOutputP, Crypto_AlgorithmFamilyType Req_family, Crypto_AlgorithmFamilyType Req_secondaryFamily, Crypto_AlgorithmModeType Req_mode)
{
	if((NULL_PTR == KeyP) || ((KeyLenth != 128) && (KeyLenth != 192) && (KeyLenth != 256)))
	{
		return CRYPTO_E_KEY_NOT_AVAILABLE;
	}
	if((NULL_PTR == InputOutputP->inputPtr) || (NULL_PTR == InputOutputP->outputPtr))
	{
		return E_NOT_OK;
	}
	
	if(Req_family != CRYPTO_ALGOFAM_AES)
	{
		return E_NOT_OK;
	}
	switch(Req_mode)
	{
	case CRYPTO_ALGOMODE_ECB_NONE:
	{
		if(*(InputOutputP->outputLengthPtr) < InputOutputP->inputLength)
		{
			return E_NOT_OK;
		}
		
		aes_encrypt_ecb_no_padding(KeyP, KeyLenth/8 , InputOutputP->inputPtr, InputOutputP->inputLength,  InputOutputP->outputPtr, (int*)InputOutputP->outputLengthPtr);
		
		return E_OK;
	}
	default:
	{

	}
	break;
	}
	
	return E_OK;

}


Std_ReturnType Crypto_SW_Decrypt(uint8* KeyP, uint32 KeyLenth, Crypto_JobPrimitiveInputOutputType* InputOutputP, Crypto_AlgorithmFamilyType Req_family, Crypto_AlgorithmFamilyType Req_secondaryFamily, Crypto_AlgorithmModeType Req_mode)
{

	if((NULL_PTR == KeyP) || ((KeyLenth != 128) && (KeyLenth != 192) && (KeyLenth != 256)))
	{
		return CRYPTO_E_KEY_NOT_AVAILABLE;
	}
	if((NULL_PTR == InputOutputP->inputPtr) || (NULL_PTR == InputOutputP->outputPtr))
	{
		return E_NOT_OK;
	}
	
	if(Req_family != CRYPTO_ALGOFAM_AES)
	{
		return E_NOT_OK;
	}
	switch(Req_mode)
	{
	case CRYPTO_ALGOMODE_ECB_NONE:
	{
		if(*(InputOutputP->outputLengthPtr) < InputOutputP->inputLength)
		{
			return E_NOT_OK;
		}
		
		aes_decrypt_ecb_no_padding(KeyP, KeyLenth/8 , InputOutputP->inputPtr, InputOutputP->inputLength,  InputOutputP->outputPtr, (int*)InputOutputP->outputLengthPtr);
		
		return E_OK;
	}
	default:
	{

	}
	break;
	}
	
	return E_OK;


}


Std_ReturnType Crypto_SW_MacGen(uint8* KeyP, uint32 KeyLenth, uint8* KeyIv, Crypto_JobPrimitiveInputOutputType* InputOutputP, Crypto_AlgorithmFamilyType Req_family, Crypto_AlgorithmFamilyType Req_secondaryFamily, Crypto_AlgorithmModeType Req_mode)
{
	if((NULL_PTR == KeyP) || (KeyLenth != 128))
	{
		return CRYPTO_E_KEY_NOT_AVAILABLE;
	}
	if((NULL_PTR == InputOutputP->inputPtr) || (NULL_PTR == InputOutputP->outputPtr))
	{
		return E_NOT_OK;
	}
	if(*(InputOutputP->outputLengthPtr) < 16)
	{
		return E_NOT_OK;
	}

	switch(Req_mode)
	{
		case CRYPTO_ALGOMODE_GMAC:
		{
			uint8 chiper[512] = {0};
			if(InputOutputP->inputLength > 512)
			{
				return E_NOT_OK;
			}
			if(NULL_PTR == KeyIv)
			{
				return E_NOT_OK;
			}
		  	Encrypt_ByteData(KeyP, KeyLenth/8 ,KeyIv ,CRYPTO_KEY_IV_SIZE, NULL_PTR, 0 ,(unsigned char*)InputOutputP->inputPtr,InputOutputP->inputLength,chiper,InputOutputP->outputPtr);
		    *(InputOutputP->outputLengthPtr) = AEAD_GCM_TAGLEN;
		}
		break;
		case CRYPTO_ALGOMODE_CMAC:
		{
			AES_CMAC((unsigned char*)KeyP, (unsigned char *)InputOutputP->inputPtr, InputOutputP->inputLength, InputOutputP->outputPtr);
			*(InputOutputP->outputLengthPtr) = 16;
		}
		break;
		default:break;
	}
	return E_OK;
}


Std_ReturnType Crypto_SW_MacVerify(uint8* KeyP, uint32 KeyLenth, uint8* KeyIv, Crypto_JobPrimitiveInputOutputType* InputOutputP, Crypto_AlgorithmFamilyType Req_family, Crypto_AlgorithmFamilyType Req_secondaryFamily, Crypto_AlgorithmModeType Req_mode)
{
	
	uint8 MacOutTemp[16] = {0};
	uint8 i;
	if((NULL_PTR == KeyP) || (KeyLenth != 128))
	{
		return CRYPTO_E_KEY_NOT_AVAILABLE;
	}
	if((NULL_PTR == InputOutputP->inputPtr) || (NULL_PTR == InputOutputP->secondaryInputPtr) || (NULL_PTR == InputOutputP->verifyPtr))
	{
		return E_NOT_OK;
	}

	switch(Req_mode)
	{
		case CRYPTO_ALGOMODE_GMAC:
		{
			uint8 chiper[512] = {0};
			if(InputOutputP->inputLength > 512)
			{
				return E_NOT_OK;
			}
			if(NULL_PTR == KeyIv)
			{
				return E_NOT_OK;
			}
		  	Encrypt_ByteData(KeyP, KeyLenth/8 ,KeyIv ,CRYPTO_KEY_IV_SIZE, NULL_PTR, 0 , (unsigned char*)InputOutputP->inputPtr, InputOutputP->inputLength, chiper, MacOutTemp);
			
			if(InputOutputP->secondaryInputLength/8 != AEAD_GCM_TAGLEN)
			{
				return E_NOT_OK;
			}

			for(i = 0; i != InputOutputP->secondaryInputLength/8; i++)
			{
				if(MacOutTemp[i] != InputOutputP->secondaryInputPtr[i])
				{
					*(InputOutputP->verifyPtr) = CRYPTO_E_VER_NOT_OK;
					return E_OK;			
				}
			}
		}
		break;
		case CRYPTO_ALGOMODE_CMAC:
		{
			AES_CMAC((unsigned char*)KeyP, (unsigned char *)InputOutputP->inputPtr, InputOutputP->inputLength, MacOutTemp);
			
			for(i = 0; i != InputOutputP->secondaryInputLength/8; i++)
			{
				if(MacOutTemp[i] != InputOutputP->secondaryInputPtr[i])
				{
					*(InputOutputP->verifyPtr) = CRYPTO_E_VER_NOT_OK;
					return E_OK;			
				}
			}			
		}
		break;
		default:break;
	}

	*(InputOutputP->verifyPtr) = CRYPTO_E_VER_OK;

	return E_OK;

}

Std_ReturnType Crypto_SW_ProcessJob(uint32 objectId, Crypto_JobType* job)
{

	Std_ReturnType ret = E_NOT_OK;
	uint32 jobId;
	uint16 objIndex;
	uint32 Req_CsmKeyId;
	Crypto_ServiceInfoType Req_service;
	Crypto_AlgorithmFamilyType Req_family;
	Crypto_AlgorithmFamilyType Req_secondaryFamily;
	Crypto_AlgorithmModeType Req_mode;
	uint32 Req_KeyLength;

	uint32 Targ_CryptoKeyId;
	uint16 KeyIndex;
	uint16 KeyEleIndex;
	Crypto_ServiceInfoType Targ_service;
	Crypto_AlgorithmFamilyType Targ_family;
	Crypto_AlgorithmFamilyType Targ_secondaryFamily;
	Crypto_AlgorithmModeType Targ_mode;
	uint8* KeyP = NULL_PTR;
	uint8* KeyP_IV = NULL_PTR;
	
	
	jobId = job->jobId;
	objIndex = Crypto_GetObjIndex(objectId);
	if(0xffff == objIndex)
	{
		return E_NOT_OK;
	}
	
	Req_CsmKeyId = job->cryptoKeyId;
	Req_service = job->jobPrimitiveInfo->primitiveInfo->service;
	Req_family = job->jobPrimitiveInfo->primitiveInfo->algorithm.family;
	Req_secondaryFamily = job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily;
	Req_mode = job->jobPrimitiveInfo->primitiveInfo->algorithm.mode;
	Req_KeyLength = job->jobPrimitiveInfo->primitiveInfo->algorithm.keyLength;
	
	Targ_service = Crypto_Objects[objIndex].Crypto_PrimitiveRef->service;
	Targ_family = Crypto_Objects[objIndex].Crypto_PrimitiveRef->family;
	Targ_secondaryFamily = Crypto_Objects[objIndex].Crypto_PrimitiveRef->secondaryFamily;
	Targ_mode = Crypto_Objects[objIndex].Crypto_PrimitiveRef->mode;
	
	if((Req_service != Targ_service) || (Req_family != Targ_family) || (Req_secondaryFamily != Targ_secondaryFamily) || (Req_mode != Targ_mode))
	{
		return E_NOT_OK;;
	}
	Targ_CryptoKeyId = CryIf_KeyMapping_acst[Csm_Prv_KeyIdMapping_acu32[Req_CsmKeyId]].CryptoKeyId_u32; 
	KeyIndex = Crypto_GetKeyIndex(Targ_CryptoKeyId);
	if(0xffff == KeyIndex)
	{
		return E_NOT_OK;
	}

	KeyEleIndex = Crypto_GetKeyElementIndex(KeyIndex, 1);
	if(0xffff == KeyEleIndex)
	{
		return E_NOT_OK;
	}
	if(FALSE == CryptoKeys[KeyIndex].KeyElements[KeyEleIndex].KeyEleValid)
	{
		return CRYPTO_E_KEY_NOT_VALID;
	}
	if(Req_KeyLength != CryptoKeys[KeyIndex].KeyElements[KeyEleIndex].ElementSize * 8)
	{
		return CRYPTO_E_KEY_SIZE_MISMATCH;
	}
	KeyP = CryptoKeys[KeyIndex].KeyElements[KeyEleIndex].Element_Pt;

	KeyEleIndex = Crypto_GetKeyElementIndex(KeyIndex, 5);
	if(0xffff != KeyEleIndex)
	{
		if(FALSE != CryptoKeys[KeyIndex].KeyElements[KeyEleIndex].KeyEleValid)
		{
			if(CRYPTO_KEY_IV_SIZE == CryptoKeys[KeyIndex].KeyElements[KeyEleIndex].ElementSize)
			{
				KeyP_IV = CryptoKeys[KeyIndex].KeyElements[KeyEleIndex].Element_Pt;
			}
		}
	}


	switch(Req_service)
	{
		case CRYPTO_MACGENERATE:
		{
			ret = Crypto_SW_MacGen(KeyP, Req_KeyLength, KeyP_IV, &(job->jobPrimitiveInputOutput), Req_family, Req_secondaryFamily, Req_mode);
		}
		break;
		case CRYPTO_MACVERIFY:
		{
			ret = Crypto_SW_MacVerify(KeyP, Req_KeyLength, KeyP_IV, &(job->jobPrimitiveInputOutput), Req_family, Req_secondaryFamily, Req_mode);
		}
		break;
		case CRYPTO_AEADENCRYPT:
		{
			ret = Crypto_SW_AEADEncrypt(KeyP, Req_KeyLength, KeyP_IV, &(job->jobPrimitiveInputOutput), Req_family, Req_secondaryFamily, Req_mode);
		}
		break;
		case CRYPTO_AEADDECRYPT:
		{
			ret = Crypto_SW_AEADDecrypt(KeyP, Req_KeyLength, KeyP_IV, &(job->jobPrimitiveInputOutput), Req_family, Req_secondaryFamily, Req_mode);
		}
		break;
		case CRYPTO_ENCRYPT:
		{
			ret = Crypto_SW_Encrypt(KeyP, Req_KeyLength, &(job->jobPrimitiveInputOutput), Req_family, Req_secondaryFamily, Req_mode);
		}
		break;
		case CRYPTO_DECRYPT:
		{
			ret = Crypto_SW_Decrypt(KeyP, Req_KeyLength, &(job->jobPrimitiveInputOutput), Req_family, Req_secondaryFamily, Req_mode);
		}
		break;
		default: break;
	}
	
	if(job->jobPrimitiveInfo->callbackId < CSM_CFG_CALLBACK_COUNT)
	{
		CryIf_CallbackNotification(job, ret);
	}
	
	return ret;
}


Std_ReturnType Crypto_SW_CancelJob (uint32 objectId, Crypto_JobType* job)
{
	Std_ReturnType ret = E_NOT_OK;
		
	return ret;
};


Std_ReturnType Crypto_SW_KeyElementSet (uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength)
{
	Std_ReturnType ret = E_NOT_OK;
	uint16 KeyIndex;
	uint16 keyElementIndex;
	uint16 ElementSize;
	uint8 *Element_Pt;
	uint8 *ValidCheck_pt;
	boolean ReadAuth;
	boolean WriteAuth;
	uint32 NvmOffset;

	if(NULL_PTR == keyPtr)
	{
		return E_NOT_OK;
	}
	
	KeyIndex = Crypto_GetKeyIndex(cryptoKeyId);
	if(0xffff == KeyIndex)
	{
		return E_NOT_OK;
	}

	keyElementIndex = Crypto_GetKeyElementIndex(KeyIndex, keyElementId);
	if(0xffff == keyElementIndex)
	{
		return E_NOT_OK;
	}

	ReadAuth = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].ReadAuth;
	WriteAuth = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].WriteAuth;
	ElementSize = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].ElementSize;
	Element_Pt = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].Element_Pt;
	ValidCheck_pt = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].ValidCheck_pt;
	NvmOffset = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].NvmOffset;


	if(!WriteAuth)
	{
		return CRYPTO_E_KEY_WRITE_FAIL;
	}
	
	if((Element_Pt == NULL_PTR))
	{
		return E_NOT_OK;
	}

	if(keyLength/8 != ElementSize)
	{
		return CRYPTO_E_KEY_SIZE_MISMATCH;
	}

	memcpy(Element_Pt, keyPtr, keyLength/8);

	if(ValidCheck_pt != NULL_PTR)
	{
		ValidCheck_pt[0] = 0xA5;
		ValidCheck_pt[1] = 0xA5;
		ValidCheck_pt[2] = 0x5A;
		ValidCheck_pt[3] = 0x5A;
		memcpy(Nvm_Bsw_Data + NvmOffset, Element_Pt, ElementSize);
		memcpy(Nvm_Bsw_Data + NvmOffset + ElementSize, ValidCheck_pt, 4);
	}

	CryptoKeys[KeyIndex].KeyElements[keyElementId].KeyEleValid = TRUE;

	
	NvmSecuredDataWrite(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE);
	
//	SecOC_KeyClear_CallOut(cryptoKeyId, keyElementId);

	return (ret = E_OK);
};


Std_ReturnType Crypto_SW_KeySetValid (uint32 cryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};

Std_ReturnType Crypto_SW_KeyElementGet (uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	uint16 KeyIndex;
	uint16 keyElementIndex;
	uint16 ElementSize;
	uint8 *Element_Pt;
	uint8 *ValidCheck_pt;
	boolean ReadAuth;
	boolean WriteAuth;
	boolean KeyValid;
	uint32 NvmOffset;

	if(NULL_PTR == resultPtr)
	{
		return E_NOT_OK;
	}
	
	KeyIndex = Crypto_GetKeyIndex(cryptoKeyId);
	if(0xffff == KeyIndex)
	{
		return E_NOT_OK;
	}

	keyElementIndex = Crypto_GetKeyElementIndex(KeyIndex, keyElementId);
	if(0xffff == keyElementIndex)
	{
		return E_NOT_OK;
	}

	ReadAuth = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].ReadAuth;
	WriteAuth = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].WriteAuth;
	ElementSize = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].ElementSize;
	Element_Pt = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].Element_Pt;
	ValidCheck_pt = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].ValidCheck_pt;
	NvmOffset = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].NvmOffset;
	KeyValid = CryptoKeys[KeyIndex].KeyElements[keyElementIndex].KeyEleValid;

	if(!ReadAuth)
	{
		return CRYPTO_E_KEY_READ_FAIL;
	}

	if(KeyValid != TRUE)
	{
		return CRYPTO_E_KEY_NOT_AVAILABLE;
	}
	
	if(*resultLengthPtr < ElementSize * 8)
	{
		return E_NOT_OK;
	}


	memcpy(resultPtr, Element_Pt, ElementSize);
	*resultLengthPtr = ElementSize * 8;	

	return (ret = E_OK);
};


Std_ReturnType Crypto_SW_KeyElementCopy (uint32 cryIfKeyId, uint32 keyElementId, uint32 targetCryIfKeyId, uint32 targetKeyElementId)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};

Std_ReturnType Crypto_SW_KeyElementCopyPartial (uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};

Std_ReturnType Crypto_SW_KeyCopy (uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};


Std_ReturnType Crypto_SW_RandomSeed (uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};

Std_ReturnType Crypto_SW_KeyGenerate (uint32 cryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};

Std_ReturnType Crypto_SW_KeyDerive (uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};

Std_ReturnType Crypto_SW_KeyExchangeCalcPubVal (uint32 cryIfKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};


Std_ReturnType Crypto_SW_KeyExchangeCalcSecret (uint32 cryIfKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};


Std_ReturnType Crypto_SW_CertificateParse (uint32 cryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};


Std_ReturnType Crypto_SW_CertificateVerify (uint32 cryIfKeyId, uint32 verifyCryIfKeyId, Crypto_VerifyResultType* verifyPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
};

Std_ReturnType Crypto_SW_KeyElementIdsGet(uint32 cryIfKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
}

Std_ReturnType CryIf_Prv_Dummy_KeyGetStatus(uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
}

Std_ReturnType CryIf_SW_Prv_Dummy_Rb_StorePermanentData(void)
{
	Std_ReturnType ret = E_NOT_OK;
	
	return ret;
}


Std_ReturnType Crypto_SW_UpLoadKeyConvert(uint8* SrcKeyPtr, uint32* DstKeyptr)
{
	Std_ReturnType ret = E_OK;
	U32_Arry4_Union tmpvar;

	tmpvar.Arry[0] = SrcKeyPtr[3];
	tmpvar.Arry[1] = SrcKeyPtr[2];
	tmpvar.Arry[2] = SrcKeyPtr[1];
	tmpvar.Arry[3] = SrcKeyPtr[0];
	DstKeyptr[0] =  tmpvar.U32;
	
	tmpvar.Arry[0] = SrcKeyPtr[7];
	tmpvar.Arry[1] = SrcKeyPtr[6];
	tmpvar.Arry[2] = SrcKeyPtr[5];
	tmpvar.Arry[3] = SrcKeyPtr[4];
	DstKeyptr[1] =  tmpvar.U32;

	tmpvar.Arry[0] = SrcKeyPtr[11];
	tmpvar.Arry[1] = SrcKeyPtr[10];
	tmpvar.Arry[2] = SrcKeyPtr[9];
	tmpvar.Arry[3] = SrcKeyPtr[8];
	DstKeyptr[2] =  tmpvar.U32;

	tmpvar.Arry[0] = SrcKeyPtr[15];
	tmpvar.Arry[1] = SrcKeyPtr[14];
	tmpvar.Arry[2] = SrcKeyPtr[13];
	tmpvar.Arry[3] = SrcKeyPtr[12];
	DstKeyptr[3] =  tmpvar.U32;
	
	return ret;
}





































