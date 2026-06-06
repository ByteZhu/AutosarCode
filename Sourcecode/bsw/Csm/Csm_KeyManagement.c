/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
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

#include "Csm.h"
//TRACE[SWS_Csm_91101]
#include "Det.h"
//TRACE[SWS_Csm_91100]
#include "CryIf.h"
#include "Csm_Prv.h"


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Local Prototype
 **********************************************************************************************************************
*/
Std_ReturnType Csm_StorePermanently(Csm_KeyStorageUseCaseType keyStorageUseCase, Csm_KeyStorageTaskType keyStorageTask);

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"
/**
 **********************************************************************************************************************
 * Csm_KeyElementSet
 *
 * \brief Sets the given key element bytes to the key identified by keyId.
 *
 * \param[in]  keyId            Holds the identifier of the key for which a new material shall be set.
 * \param[in]  keyElementId     Holds the identifier of the key element to be written.
 * \param[in]  keyPtr           Holds the pointer to the key element bytes to be processed.
 * \param[in]  keyLength        Contains the number of key element bytes.
 * \return     Std_ReturnType   E_OK: Request successful
 *                              E_NOT_OK: Request failed
 *                              CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
 *                              CRYPTO_E_KEY_WRITE_FAIL:Request failed because write access was denied
 *                              CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not available.
 *                              CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element size does not match size of
 *                              provided data.
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00957][SWS_Csm_01092]
Std_ReturnType Csm_KeyElementSet(uint32 keyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (NULL_PTR == keyPtr)
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_KeyElementSet(keyId_u32, keyElementId, keyPtr, keyLength);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_KeySetValid
 *
 * \brief Sets the key state of the key identified by keyId to valid.
 *
 * \param[in]  keyId            Holds the identifier of the key for which a new material shall be validated.
 * \return     Std_ReturnType     E_OK: Request successful
 *                                E_NOT_OK: Request Failed
 *                                CRYPTO_E_BUSY: Request Failed, Crypro Driver Object is Busy
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00958]
Std_ReturnType Csm_KeySetValid(uint32 keyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_KeySetValid(keyId_u32);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_KeyGetStatus
 *
 * \brief      Returns the key state of the key identified by keyId
 *
 * \param[in]  keyId              Holds the identifier of the key for which the key state shall be returned.
 * \param[out] keyStatusPtr       Contains the pointer to the data where the status of the key shall be stored.
 * \return     Std_ReturnType     E_OK: Request successful
 *                                E_NOT_OK: Request Failed
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_91047]
Std_ReturnType Csm_KeyGetStatus (uint32 keyId, Crypto_KeyStatusType* keyStatusPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_KeyGetStatus(keyId_u32, keyStatusPtr);
    }


    return result_en;
}
/**
 **********************************************************************************************************************
 * Csm_KeyElementGet
 *
 * \brief Retrieves the key element bytes from a specific key element of the key identified by the keyId and stores
 *        the key element in the memory location pointed by the key pointer.
 *
 * \param[in]    keyId          Holds the identifier of the key from which a key element shall be extracted.
 * \param[in]    keyElementId   Holds the identifier of the key element to be extracted.
 * \param[out]   keyPtr         Holds the pointer to the memory location where the key shall be copied to.
 * \param[inout] keyLengthPtr   Holds a pointer to the memory location in which the output buffer length in bytes is
 *                              stored. On calling this function, this parameter shall contain the buffer length in
 *                              bytes of the keyPtr. When the request has finished, the actual size of the written
 *                              input bytes shall be stored.
 * \return       Std_ReturnType  E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 *                               CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                               CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is not available
 *                               CRYPTO_E_KEY_READ_FAIL: Request failed because read access was denied
 *                               CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00959]
/* HIS METRIC LEVEL VIOLATION IN Csm_KeyElementGet: Function contains most simple "else if" implementation of
   Autosar specified functionality. HIS metric compliance would decrease readability and maintainability. */
Std_ReturnType Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, uint8* keyPtr, uint32* keyLengthPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if ((NULL_PTR == keyPtr) || (NULL_PTR == keyLengthPtr))
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_KeyElementGet(keyId_u32, keyElementId, keyPtr, keyLengthPtr);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_KeyElementCopy
 *
 * \brief This function shall copy a key elements from one key to a target key.
 *
 * \param[in]    keyId                Holds the identifier of the key whose key element shall be the source element.
 * \param[in]    keyElementId         Holds the identifier of the key element which shall be the source for the copy
 *                                    operation.
 * \param[in]    targetKeyId          Holds the identifier of the key whose key element shall be the destination element
 * \param[in]    targetKeyElementId   Holds the identifier of the key element which shall be the destination for the
 *                                    copy operation.
 * \return       Std_ReturnType        E_OK: Request successful
 *                                     E_NOT_OK: Request Failed
 *                                     CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                     CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is
 *                                     not available
 *                                     CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
 *                                     CRYPTO_E_KEY_EXTRACT_DENIED: Request failed, not allowed to extract key element
 *                                     CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element.
 *                                     CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible
 *                                     CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00969]
Std_ReturnType Csm_KeyElementCopy(uint32 keyId, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;
    uint32 targetKeyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(targetKeyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        targetKeyId_u32 = Csm_Prv_KeyIdMapping_acu32[targetKeyId];
        //Call CryIf key service function
        result_en = CryIf_KeyElementCopy(keyId_u32, keyElementId, targetKeyId_u32, targetKeyElementId);
    }


    return result_en;
}


/**
 **********************************************************************************************************************
 * Csm_KeyElementCopyPartial
 *
 * \brief Copies a key element to another key element in the same crypto driver.
 *        The keyElementSourceOffset and keyElementCopyLength allows to copy just a part of
 *        the source key element into the destination. The offset into the target key is also specified with this function.
 *
 * \param[in]    keyId                      Holds the identifier of the key whose key element shall be the source element.
 * \param[in]    keyElementId               Holds the identifier of the key element which shall be the source for the copy
 * \param[in]    keyElementSourceOffset     Holds the offset value to be used for the source element
 * \param[in]    keyElementTargetOffset     Holds the offset value to be used for the target element
 * \param[in]    keyElementCopyLength       Holds the nummber of bytes to be copied
 * \param[in]    targetKeyId                Holds the identifier of the key whose key element shall be the destination element
 * \param[in]    targetKeyElementId         Holds the identifier of the key element which shall be the destination for the
 *                                          copy operation.
 * \return       Std_ReturnType             E_OK: Request successful
 *                                          E_NOT_OK: Request Failed
 *                                          CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                          CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is
 *                                          not available
 *                                          CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
 *                                          CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element.
 *                                          CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible
 *                                          CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_91025]
Std_ReturnType Csm_KeyElementCopyPartial(uint32 keyId, uint32 keyElementId,
                                         uint32 keyElementSourceOffset, uint32 keyElementTargetOffset,
                                         uint32 keyElementCopyLength, uint32 targetKeyId,
                                         uint32 targetKeyElementId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;
    uint32 targetKeyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(targetKeyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if ((keyId == targetKeyId) &&
             (keyElementId == targetKeyElementId))
    {
        //Extended Developer Error
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        targetKeyId_u32 = Csm_Prv_KeyIdMapping_acu32[targetKeyId];
        //Call CryIf key service function
        result_en = CryIf_KeyElementCopyPartial(keyId_u32, keyElementId, keyElementSourceOffset, keyElementTargetOffset, keyElementCopyLength, targetKeyId_u32, targetKeyElementId);
    }


    return result_en;
}


/**
 **********************************************************************************************************************
 * Csm_KeyCopy
 *
 * \brief This function shall copy all key elements from the source key to a target key.
 *
 * \param[in]    keyId                Holds the identifier of the key whose key element shall be the source element.
 * \param[in]    targetKeyId          Holds the identifier of the key whose key element shall be the destination element
 * \return       Std_ReturnType       E_OK: Request successful
 *                                    E_NOT_OK: Request Failed
 *                                    CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                    CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element
 *                                                                is not available
 *                                    CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
 *                                    CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element.
 *                                    CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible
 *                                    CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_01034]
Std_ReturnType Csm_KeyCopy(uint32 keyId, uint32 targetKeyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;
    uint32 targetKeyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(targetKeyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        targetKeyId_u32 = Csm_Prv_KeyIdMapping_acu32[targetKeyId];
        //Call CryIf key service function
        result_en = CryIf_KeyCopy(keyId_u32, targetKeyId_u32);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_RandomSeed
 *
 * \brief Feeds the key element CRYPTO_KE_RANDOM_SEED with a random seed.
 *
 * \param[in]  keyId            Holds the identifier of the key for which a new seed shall be generated.
 * \param[in]  seedPtr          Holds a pointer to the memory location which contains the data to feed the seed.
 * \param[in]  seedLength       Contains the length of the seed in bytes.
 * \return     Std_ReturnType   E_OK: Request successful
 *                              E_NOT_OK: Request failed
 *                              CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
 *                              CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state is "invalid"
 **********************************************************************************************************************
 */
//[TRACE[SWS_Csm_01051]
Std_ReturnType Csm_RandomSeed(uint32 keyId, const uint8* seedPtr, uint32 seedLength)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (NULL_PTR == seedPtr)
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        {
            //Perform keyId mapping
            keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
            //Call CryIf key service function
            result_en = CryIf_RandomSeed(keyId_u32, seedPtr, seedLength);
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_KeyGenerate
 *
 * \brief Generates new key material and store it in the key identified by keyId.
 *
 * \param[in]  keyId            Holds the identifier of the key for which a new material shall be generated.
 * \return     Std_ReturnType   E_OK: Request successful
 *                              E_NOT_OK: Request Failed
 *                              CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
 *                              CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state is "invalid"
 *                              CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00955]
Std_ReturnType Csm_KeyGenerate(uint32 keyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_KeyGenerate(keyId_u32);
    }


    return result_en;
}
/**
 **********************************************************************************************************************
 * Csm_KeyDerive
 *
 * \brief Derives a new key by using the key elements in the given key identified by the keyId. The given key contains
 *        the key elements for the password and salt. The derived key is stored in the key element with the id 1 of
 *        the key identified by targetCryptoKeyId.
 *
 * \param[in]    keyId                Holds the identifier of the key which is used for key derivation.
 * \param[in]    targetKeyId          Holds the identifier of the key which is used to store the derived key.
 * \return       Std_ReturnType       E_OK: Request successful
 *                                    E_NOT_OK: Request Failed
 *                                    CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                    CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
 *                                    CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element
 *                                    CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state is "invalid"
 *                                    CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible
 *                                    CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00956]
Std_ReturnType Csm_KeyDerive(uint32 keyId, uint32 targetKeyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;
    uint32 targetKeyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(targetKeyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        targetKeyId_u32 = Csm_Prv_KeyIdMapping_acu32[targetKeyId];
        //Call CryIf key service function
        result_en = CryIf_KeyDerive(keyId_u32, targetKeyId_u32);
    }


    return result_en;
}
/**
 **********************************************************************************************************************
 * Csm_KeyExchangeCalcPubVal
 *
 * \brief Calculates the public value of the current user for the key exchange and stores the public key in the
 *        memory location pointed by the public value pointer.
 *
 * \param[in]    keyId                  Holds the identifier of the key which shall be used for the key exchange
 *                                      protocol.
 * \param[out]   publicValuePtr         Holds the pointer to the memory location where the key shall be copied to.
 * \param[inout] publicValueLengthPtr   Holds a pointer to the memory location in which the public value length
                                        information is stored. On calling this function, this parameter shall contain
                                        the size of the buffer provided by publicValuePtr. When the request has
                                        finished, the actual length of the returned value shall be stored.
 * \return       Std_ReturnType  E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 *                               CRYPTO_E_KEY_NOT_VALID: request failed, the key's state is "invalid"
 *                               CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state is "invalid"
 *                               CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00966]
Std_ReturnType Csm_KeyExchangeCalcPubVal(uint32 keyId, uint8* publicValuePtr, uint32* publicValueLengthPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if ((NULL_PTR == publicValuePtr) || (NULL_PTR == publicValueLengthPtr))
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_KeyExchangeCalcPubVal(keyId_u32, publicValuePtr, publicValueLengthPtr);
        //Try to store the calculated public key internally
        //TRACE[SWS_Csm_Rb_4944]
        if (E_OK == result_en)
        {
            //Ignore store result, application may want to store the key elsewhere
            (void)CryIf_KeyElementSet(keyId_u32, CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY,
                                      publicValuePtr, *publicValueLengthPtr);
        }
    }

    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_KeyExchangeCalcSecret
 *
 * \brief Calculates the shared secret key for the key exchange with the key material of the key identified by the
 *        keyId and the partner public key. The shared secret key is stored as a key element in the same key.
 *
 * \param[in]  keyId                    Holds the identifier of the key which shall be used for the key exchange
 *                                      protocol.
 * \param[in]  partnerPublicValuePtr    Holds the pointer to the memory location which contains the partner's
 *                                      public value.
 * \param[in]  partnerPublicValueLength Contains the length of the partner's public value in bytes.
 * \return     Std_ReturnType    E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 *                               CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                               CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state is "invalid"
 *                               CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00967]
Std_ReturnType Csm_KeyExchangeCalcSecret(uint32 keyId, const uint8* partnerPublicValuePtr,
                                         uint32 partnerPublicValueLength)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (NULL_PTR == partnerPublicValuePtr)
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_KeyExchangeCalcSecret(keyId_u32, partnerPublicValuePtr,
                                                          partnerPublicValueLength);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_CertificateParse
 *
 * \brief This function shall dispatch the certificate parse function to the CRYIF.
 *
 * \param[in]  keyId            Holds the identifier of the key to be used for the certificate parsing.
 * \return     Std_ReturnType   E_OK: Request successful
 *                              E_NOT_OK: Request Failed
 *                              CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy.
 *                              CRYPTO_E_KEY_NOT_VALID: request failed, the key's state is "invalid"
 *                              CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_Rb_01036]
Std_ReturnType Csm_CertificateParse(uint32 keyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        //Call CryIf key service function
        result_en = CryIf_CertificateParse(keyId_u32);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_CertificateVerify
 *
 * \brief Verifies the certificate stored in the key referenced by verifyKeyId with the certificate stored in the key
 *        referenced by keyId. Note: Only certificates stored in the same Crypto Driver can be verified against each
 *        other. If the key element CRYPTO_KE_CERTIFICATE_CURRENT_TIME is used for the verification of the validity
 *        period of the certificate indentified by verifyKeyId, it shall have the same format as the timestamp in the
 *        certificate.
 *
 * \param[in]    keyId                Holds the identifier of the key which shall be used to validate the certificate.
 * \param[in]    verifyKeyId          Holds the identifier of the key containing the certificate to be verified.
 * \param[out]   verifyPtr            Holds a pointer to the memory location which will contain the result of the
 *                                    certificate verification.
 * \return       Std_ReturnType       E_OK: Request successful
 *                                    E_NOT_OK: Request Failed
 *                                    CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy.
 *                                    CRYPTO_E_KEY_NOT_VALID: request failed, the key's state is "invalid"
 *                                    CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_Rb_01038]
Std_ReturnType Csm_CertificateVerify(uint32 keyId, uint32 verifyKeyId, Crypto_VerifyResultType* verifyPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 keyId_u32;
    uint32 verifyKeyId_u32;


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    else if (NULL_PTR == verifyPtr)
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(keyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (!Csm_Prv_IsKeyIdInRange(verifyKeyId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else
    {
        //Perform keyId mapping
        keyId_u32 = Csm_Prv_KeyIdMapping_acu32[keyId];
        verifyKeyId_u32 = Csm_Prv_KeyIdMapping_acu32[verifyKeyId];
        //Call CryIf key service function
        result_en = CryIf_CertificateVerify(keyId_u32, verifyKeyId_u32, verifyPtr);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_StorePermanently
 *
 * \brief Rte interface wrapper for Csm_Rb_StorePermanentData function to trigger Permanent Data store and poll its status
 *        Always all permament data will be saved. On first call or in idle state store operation automatically started,
 *        on consequent calls the status polled.
 *
 * \param[in]    keyStorageUseCase    Hold the data type id to be stored
 * \param[in]    keyStorageTask       Task type to be requested.
 * \return       Std_ReturnType       E_OK: Request done
 *                                    E_NOT_OK: Request Failed
 *                                    CRYPTO_E_PENDING: Request in progress
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_Rb_06489]
Std_ReturnType Csm_StorePermanently(Csm_KeyStorageUseCaseType keyStorageUseCase, Csm_KeyStorageTaskType keyStorageTask)
{
    Std_ReturnType result_en = E_OK;


    // not used in cryptostack
    CSM_PARAM_UNUSED(keyStorageUseCase);
    //Check if cancel requested
    if(SSA_KEYSTORAGE_TASK_CANCEL == keyStorageTask)
    {
        result_en = E_NOT_OK;
    }
    else
    {
        // Trigger operation or get status
        result_en = Csm_Rb_StorePermanentData();
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_Rb_StorePermanentData
 *
 * \brief Function to trigger Permanent Data store and poll its status. Always all permament data will be saved.
 *        On first call store operation automatically started, on consequent calls the status polled.
 *
 * \return       Std_ReturnType       E_OK: Request done
 *                                    E_NOT_OK: Request Failed
 *                                    CRYPTO_E_PENDING: Request in progress
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_Rb_06492]
Std_ReturnType Csm_Rb_StorePermanentData(void)
{
    return CryIf_Rb_StorePermanentData();
}
#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

