/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.CryIf
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "CryIf_Cfg.h"



#include "CryIf_Crypto_Wrapper.h"


#include "CryIf_Prv.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/

#define CRYIF_START_SEC_CONST_UNSPECIFIED
#include "CryIf_MemMap.h"

//CryIfChannel to CryptoDriverObject mapping
const CryIf_Prv_ChannelMappingType CryIf_ChannelMapping_acst[CRYIF_CFG_CHANNEL_COUNT] =
{
{0U,0U}
,{0U,1U}
,{0U,2U}
,{0U,3U}
};

//CryIfKey to CryptoKey mapping
const CryIf_Prv_KeyMappingType CryIf_KeyMapping_acst[CRYIF_CFG_KEY_COUNT] =
{
{0U,0U}
,{0U,1U}
,{0U,2U}
};

//Crypto_ProcessJob function pointers
Std_ReturnType (*const CryIf_ProcessJob_acpfct[]) (uint32 objectId, Crypto_JobType* job) =
{
&Crypto_ProcessJob
};

//Crypto_CancelJob function pointers
Std_ReturnType (*const CryIf_CancelJob_acpfct[]) (uint32 objectId, Crypto_JobType* job) =
{
&Crypto_CancelJob
};

//Crypto_KeyElementSet function pointers
Std_ReturnType (*const CryIf_KeyElementSet_acpfct[]) (uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength) =
{
&Crypto_KeyElementSet
};

//Crypto_KeySetValid function pointers
Std_ReturnType (*const CryIf_KeySetValid_acpfct[]) (uint32 cryIfKeyId) =
{
&Crypto_KeySetValid
};

//Crypto_KeyGetStatus function pointers
Std_ReturnType (*const CryIf_KeyGetStatus_acpfct[]) (uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr) =
{
&CryIf_Prv_Dummy_KeyGetStatus
};

//Crypto_KeyElementGet function pointers
Std_ReturnType (*const CryIf_KeyElementGet_acpfct[]) (uint32 cryIfKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr) =
{
&Crypto_KeyElementGet
};

//Crypto_KeyElementCopy function pointers
Std_ReturnType (*const CryIf_KeyElementCopy_acpfct[]) (uint32 cryIfKeyId, uint32 keyElementId, uint32 targetCryIfKeyId, uint32 targetKeyElementId) =
{
&Crypto_KeyElementCopy
};

//Crypto_KeyElementCopyPartial function pointers
Std_ReturnType (*const CryIf_KeyElementCopyPartial_acpfct[]) (uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId) =
{
&Crypto_KeyElementCopyPartial
};

//Crypto_KeyCopy function pointers
Std_ReturnType (*const CryIf_KeyCopy_acpfct[]) (uint32 cryIfKeyId, uint32 targetCryIfKeyId) =
{
&Crypto_KeyCopy
};

//Crypto_KeyElementIdsGet function pointers
Std_ReturnType (*const CryIf_KeyElementIdsGet_acpfct[]) (uint32 cryIfKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr) =
{
&Crypto_KeyElementIdsGet
};

//Crypto_RandomSeed function pointers
Std_ReturnType (*const CryIf_RandomSeed_acpfct[]) (uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength) =
{
&Crypto_RandomSeed
};

//Crypto_KeyGenerate function pointers
Std_ReturnType (*const CryIf_KeyGenerate_acpfct[]) (uint32 cryIfKeyId) =
{
&Crypto_KeyGenerate
};

//Crypto_KeyDerive function pointers
Std_ReturnType (*const CryIf_KeyDerive_acpfct[]) (uint32 cryIfKeyId, uint32 targetCryIfKeyId) =
{
&Crypto_KeyDerive
};

//Crypto_KeyExchangeCalcPubVal function pointers
Std_ReturnType (*const CryIf_KeyExchangeCalcPubVal_acpfct[]) (uint32 cryIfKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr) =
{
&Crypto_KeyExchangeCalcPubVal
};

//Crypto_KeyExchangeCalcSecret function pointers
Std_ReturnType (*const CryIf_KeyExchangeCalcSecret_acpfct[]) (uint32 cryIfKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength) =
{
&Crypto_KeyExchangeCalcSecret
};

//Crypto_CertificateParse function pointers
Std_ReturnType (*const CryIf_CertificateParse_acpfct[]) (uint32 cryIfKeyId) =
{
&Crypto_CertificateParse
};

//Crypto_CertificateVerify function pointers
Std_ReturnType (*const CryIf_CertificateVerify_acpfct[]) (uint32 cryIfKeyId, uint32 verifyCryIfKeyId, Crypto_VerifyResultType* verifyPtr) =
{
&Crypto_CertificateVerify
};

//Crypto_Rb_StorePermanentData function pointers
Std_ReturnType (*const CryIf_Rb_StorePermanentData_acpfct[]) (void) =
{
&CryIf_Prv_Dummy_Rb_StorePermanentData
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
#include "CryIf_MemMap.h"

