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
#include "CryIf.h"
#include "CryIf_Prv.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CRYIF_START_SEC_CODE
#include "CryIf_MemMap.h"

//Dummy functions, which are used for mapping when the target crypto component dosen't support the required api
/* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_Prv_Dummy_ProcessJob(uint32 objectId, Crypto_JobType* job)
{
    CRYIF_PARAM_UNUSED(objectId);
    CRYIF_PARAM_UNUSED(job);


    return E_NOT_OK;
}

/* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_Prv_Dummy_CancelJob(uint32 objectId, Crypto_JobType* job)
{
    CRYIF_PARAM_UNUSED(objectId);
    CRYIF_PARAM_UNUSED(job);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeyElementSet(uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength)
{
    CRYIF_PARAM_UNUSED(cryptoKeyId);
    CRYIF_PARAM_UNUSED(keyElementId);
    CRYIF_PARAM_UNUSED(keyPtr);
    CRYIF_PARAM_UNUSED(keyLength);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeySetValid(uint32 cryIfKeyId)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);


    return E_NOT_OK;
}

/* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_Prv_Dummy_KeyElementGet(uint32 cryIfKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(keyElementId);
    CRYIF_PARAM_UNUSED(resultPtr);
    CRYIF_PARAM_UNUSED(resultLengthPtr);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeyElementCopy(uint32 cryIfKeyId, uint32 keyElementId, uint32 targetCryIfKeyId, uint32 targetKeyElementId)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(keyElementId);
    CRYIF_PARAM_UNUSED(targetCryIfKeyId);
    CRYIF_PARAM_UNUSED(targetKeyElementId);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeyElementCopyPartial(uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(keyElementId);
    CRYIF_PARAM_UNUSED(keyElementSourceOffset);
    CRYIF_PARAM_UNUSED(keyElementTargetOffset);
    CRYIF_PARAM_UNUSED(keyElementCopyLength);
    CRYIF_PARAM_UNUSED(targetCryIfKeyId);
    CRYIF_PARAM_UNUSED(targetKeyElementId);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeyCopy(uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(targetCryIfKeyId);


    return E_NOT_OK;
}

/* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_Prv_Dummy_KeyElementIdsGet(uint32 cryIfKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(keyElementIdsPtr);
    CRYIF_PARAM_UNUSED(keyElementIdsLengthPtr);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_RandomSeed(uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(seedPtr);
    CRYIF_PARAM_UNUSED(seedLength);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeyGenerate(uint32 cryIfKeyId)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeyDerive(uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(targetCryIfKeyId);


    return E_NOT_OK;
}


/* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_Prv_Dummy_KeyGetStatus(uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(keyStatusPtr);


    return E_NOT_OK;
}


/* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_Prv_Dummy_KeyExchangeCalcPubVal(uint32 cryIfKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(publicValuePtr);
    CRYIF_PARAM_UNUSED(publicValueLengthPtr);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_KeyExchangeCalcSecret(uint32 cryIfKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(partnerPublicValuePtr);
    CRYIF_PARAM_UNUSED(partnerPublicValueLength);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_CertificateParse(uint32 cryIfKeyId)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);


    return E_NOT_OK;
}

/* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_Prv_Dummy_CertificateVerify(uint32 cryIfKeyId, uint32 verifyCryIfKeyId, Crypto_VerifyResultType* verifyPtr)
{
    CRYIF_PARAM_UNUSED(cryIfKeyId);
    CRYIF_PARAM_UNUSED(verifyCryIfKeyId);
    CRYIF_PARAM_UNUSED(verifyPtr);


    return E_NOT_OK;
}

Std_ReturnType CryIf_Prv_Dummy_Rb_StorePermanentData(void)
{
    return E_NOT_OK;
}

#define CRYIF_STOP_SEC_CODE
#include "CryIf_MemMap.h"

