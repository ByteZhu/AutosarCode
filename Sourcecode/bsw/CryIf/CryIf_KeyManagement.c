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
//TRACE[SWS_CryIf_91101]TRACE[SWS_CryIf_91100]
#include "Det.h"
#include "CryIf_Prv.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

#define CRYIF_START_SEC_VAR_CLEARED_8
#include "CryIf_MemMap.h"

static uint8 CryIf_KeyManagement_sourceKeyElement_au8[CRYIF_CFG_KEY_ELEMENT_COPY_MAX_SIZE];
static uint8 CryIf_KeyManagement_targetKeyElement_au8[CRYIF_CFG_KEY_ELEMENT_COPY_MAX_SIZE];

#define CRYIF_STOP_SEC_VAR_CLEARED_8
#include "CryIf_MemMap.h"
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CRYIF_START_SEC_CODE
#include "CryIf_MemMap.h"
/**
 **********************************************************************************************************************
 * CryIf_KeyElementSet
 *
 * \brief This function shall dispatch the set key element function to the configured crypto driver object.
 *
 * \param[in]  cryIfKeyId       Holds the identifier of the key whose key element shall be set.
 * \param[in]  keyElementId     Holds the identifier of the key element which shall be set.
 * \param[in]  keyPtr           Holds the pointer to the key data which shall be set as key element.
 * \param[in]  keyLength        Contains the length of the key element in bytes.
 * \return     Std_ReturnType   E_OK: Request successful
 *                              E_NOT_OK: Request failed
 *                              CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
 *                              CRYPTO_E_KEY_WRITE_FAIL:Request failed because write access was denied
 *                              CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not available.
 *                              CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element size does not match
 *                                                          size of provided data.
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91004]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyElementSet: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
Std_ReturnType CryIf_KeyElementSet(uint32 cryIfKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00049]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_SET, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00050]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_SET, CRYIF_E_PARAM_HANDLE);
    }
    //Check if keyPtr is invalid
    else if (NULL_PTR == keyPtr)
    {
        //TRACE[SWS_CryIf_00052]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_SET, CRYIF_E_PARAM_POINTER);
    }
    //Check if keyLength is invalid
    else if (0U == keyLength)
    {
        //TRACE[SWS_CryIf_00053]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_SET, CRYIF_E_PARAM_VALUE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00055]
        //Call Crypto function
        result_en = CryIf_KeyElementSet_acpfct[moduleIndex_u32](keyId_u32 , keyElementId, keyPtr, keyLength);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeySetValid
 *
 * \brief This function shall dispatch the set key valid function to the configured crypto driver object.
 *
 * \param[in]  cryIfKeyId         Holds the identifier of the key whose key elements shall be set to valid.
 * \return     Std_ReturnType     E_OK: Request successful
 *                                E_NOT_OK: Request Failed
 *                                CRYPTO_E_BUSY: Request Failed, Crypro Driver Object is Busy
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91005]
Std_ReturnType CryIf_KeySetValid(uint32 cryIfKeyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00056]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_SET_VALID, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00057]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_SET_VALID, CRYIF_E_PARAM_HANDLE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00058]
        //Call Crypto function
        result_en = CryIf_KeySetValid_acpfct[moduleIndex_u32](keyId_u32);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyGetStatus
 *
 * \brief Returns the key state of the key identified by cryIfKeyId.
 *
 * \param[in]   cryIfKeyId         Holds the identifier of the key for which the key state shall be returned.
 * \param[out]  keyStatusPtr      Contains the pointer to the data where the status of the key shall be stored.
 * \return      Std_ReturnType     E_OK: Request successful
 *                                E_NOT_OK: Request Failed
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91012]
/* MR12 RULE 8.13 VIOLATION : keyStatusPtr can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_KeyGetStatus (uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00146]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_GET_STATUS, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00147]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_GET_STATUS, CRYIF_E_PARAM_HANDLE);
    }
    // Check if output pointer is valid
    else if (NULL_PTR == keyStatusPtr)
    {
        //TRACE[SWS_CryIf_00148]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_GET_STATUS, CRYIF_E_PARAM_POINTER);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00149]
        //Call Crypto function
        result_en = CryIf_KeyGetStatus_acpfct[moduleIndex_u32](keyId_u32, keyStatusPtr);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyElementGet
 *
 * \brief This function shall dispatch the get key element function to the configured crypto driver object.
 *
 * \param[in]    cryIfKeyId      Holds the identifier of the key whose key element shall be returned.
 * \param[in]    keyElementId    Holds the identifier of the key element which shall be returned.
 * \param[out]   resultPtr       Holds the pointer of the buffer for the returned key element
 * \param[inout] resultLengthPtr Holds a pointer to a memory location in which the length information is stored.
 *                               On calling this function this parameter shall contain the size of the buffer provided
 *                               by resultPtr. If the key element is configured to allow partial access, this parameter
 *                               contains the amount of data which should be read from the key element. The size may
 *                               not be equal to the size of the provided buffer anymore. When the request has finished,
 *                               the amount of data that has been stored shall be stored.
 * \return       Std_ReturnType  E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 *                               CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                               CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is not available
 *                               CRYPTO_E_KEY_READ_FAIL: Request failed because read access was denied
 *                               CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91006]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyElementGet: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
/* MR12 RULE 8.13 VIOLATION : resultPtr and resultLengthPtr can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_KeyElementGet(uint32 cryIfKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00059]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_GET, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00060]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_GET, CRYIF_E_PARAM_HANDLE);
    }
    //Check if resultPtr or resultLengthPtr is invalid
    else if ((NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr))
    {
        //TRACE[SWS_CryIf_00062][SWS_CryIf_00063]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_GET, CRYIF_E_PARAM_POINTER);
    }
    //Check if resultLength value is invalid
    else if (0U == (*resultLengthPtr))
    {
        //TRACE[SWS_CryIf_00064]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_GET, CRYIF_E_PARAM_VALUE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00065]
        //Call Crypto function
        result_en = CryIf_KeyElementGet_acpfct[moduleIndex_u32](keyId_u32 , keyElementId, resultPtr, resultLengthPtr);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyElementCopy
 *
 * \brief This function shall copy a key elements from one key to a target key.
 *
 * \param[in]    cryIfKeyId            Holds the identifier of the key whose key element shall be the source element.
 * \param[in]    keyElementId          Holds the identifier of the key element which shall be the source for the
 *                                     copy operation.
 * \param[in]    targetCryIfKeyId      Holds the identifier of the key whose key element shall be the destination
 *                                     element.
 * \param[in]    targetKeyElementId    Holds the identifier of the key element which shall be the destination for
 *                                     the copy operation.
 * \return       Std_ReturnType        E_OK: Request successful
 *                                     E_NOT_OK: Request Failed
 *                                     CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                     CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is
 *                                                                 not available
 *                                     CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
 *                                     CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element.
 *                                     CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible.
 *                                     CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91015]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyElementCopy: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
Std_ReturnType CryIf_KeyElementCopy(uint32 cryIfKeyId, uint32 keyElementId, uint32 targetCryIfKeyId,
                                    uint32 targetKeyElementId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;
    uint32 targetKeyId_u32 = CSM_INVALID_ID;
    uint32 targetModuleIndex_u32 = CSM_INVALID_ID;
    uint32 keyElementSize_u32 = CRYIF_CFG_KEY_ELEMENT_COPY_MAX_SIZE;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00110]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_COPY, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00111]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_COPY, CRYIF_E_PARAM_HANDLE);
    }
    //Check if targetCryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(targetCryIfKeyId))
    {
        //TRACE[SWS_CryIf_00112]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_COPY, CRYIF_E_PARAM_HANDLE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        targetModuleIndex_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoModuleIndex_u16;
        targetKeyId_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoKeyId_u32;
        //Check if both keyIds are on the same crypto
        if (moduleIndex_u32 == targetModuleIndex_u32)
        {
            //TRACE[SWS_CryIf_00121] Fulfilled in Crypto function
            //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
            //Call forwarding and mapping do not care about the execution contexts
            //[SWS_CryIf_00113]
            //Call Crypto function
            result_en = CryIf_KeyElementCopy_acpfct[moduleIndex_u32](keyId_u32 , keyElementId, targetKeyId_u32, targetKeyElementId);
        }
        else
        {
            //[SWS_CryIf_00114]
            //Get source key element data
            result_en = CryIf_KeyElementGet_acpfct[moduleIndex_u32](keyId_u32,
                                                                    keyElementId,
                                                                    CryIf_KeyManagement_sourceKeyElement_au8,
                                                                    &keyElementSize_u32);

            if (E_OK == result_en)
            {
                //Write key element data to target
                result_en = CryIf_KeyElementSet_acpfct[targetModuleIndex_u32](targetKeyId_u32,
                                                                              targetKeyElementId,
                                                                              CryIf_KeyManagement_sourceKeyElement_au8,
                                                                              keyElementSize_u32);
            }
        }

        //TRACE[SWS_CryIf_00115]
        //Check if size mismatch or key not available was reported from Crypto
        if (CRYPTO_E_KEY_SIZE_MISMATCH == result_en)
        {
            //TRACE[SWS_CryIf_00115]|1
            (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_COPY, CRYIF_E_KEY_SIZE_MISMATCH);
        }
    }


    return result_en;
}


/**
 **********************************************************************************************************************
 * CryIf_KeyElementCopyPartial
 *
 * \brief This function shall copy a key elements from one key to a target key.
 *
 * \param[in]    cryIfKeyId                Holds the identifier of the key whose key element shall be the source element.
 * \param[in]    keyElementId              Holds the identifier of the key element which shall be the source for the
 *                                         copy operation.
 * \param[in]    keyElementSourceOffset    This is the offset of the source key element indicating the start index
                                           of the copy operation
 * \param[in]    keyElementTargetOffset    This is the offset of the target key element indicating the start index
                                           of the copy operation.
 * \param[in]    keyElementCopyLength      Specifies the number of bytes that shall be copied
 *                                         copy operation.
 * \param[in]    targetCryIfKeyId          Holds the identifier of the key whose key element shall be the destination
 *                                         element.
 * \param[in]    targetKeyElementId        Holds the identifier of the key element which shall be the destination for
 *                                         the copy operation.
 * \return       Std_ReturnType            E_OK: Request successful
 *                                         E_NOT_OK: Request Failed
 *                                         CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is
 *                                                                     not available
 *                                         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
 *                                         CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element.
 *                                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible.
 *                                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91018]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyElementCopyPartial: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
Std_ReturnType CryIf_KeyElementCopyPartial(uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset,
                                           uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;
    uint32 targetKeyId_u32 = CSM_INVALID_ID;
    uint32 targetModuleIndex_u32 = CSM_INVALID_ID;
    uint32 keyElementSize_u32 = CRYIF_CFG_KEY_ELEMENT_COPY_MAX_SIZE;
    uint32 targetKeyElementSize_u32 = CRYIF_CFG_KEY_ELEMENT_COPY_MAX_SIZE;
    uint32 i_u32;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00137]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_COPY_PARTIAL, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00138]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_COPY_PARTIAL, CRYIF_E_PARAM_HANDLE);
    }
    //Check if targetCryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(targetCryIfKeyId))
    {
        //TRACE[SWS_CryIf_00138]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_ELEMENT_COPY_PARTIAL, CRYIF_E_PARAM_HANDLE);
    }
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        targetModuleIndex_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoModuleIndex_u16;
        targetKeyId_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoKeyId_u32;
        //Check if both keyIds are on the same crypto
        if (moduleIndex_u32 == targetModuleIndex_u32)
        {
            // Call crypto to perform copy
            //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
            //Call forwarding and mapping do not care about the execution contexts
            //[SWS_CryIf_00139]
            //Call Crypto function
            result_en = CryIf_KeyElementCopyPartial_acpfct[moduleIndex_u32](keyId_u32, keyElementId, keyElementSourceOffset, keyElementTargetOffset, keyElementCopyLength, targetKeyId_u32, targetKeyElementId);
        }
        else
        {
            //[SWS_CryIf_00140]
            //Call Crypto function
            result_en = CryIf_KeyElementGet_acpfct[moduleIndex_u32](keyId_u32 , keyElementId, CryIf_KeyManagement_sourceKeyElement_au8, &keyElementSize_u32);

            if (E_OK == result_en)
            {
                //Call Crypto function
                result_en = CryIf_KeyElementGet_acpfct[targetModuleIndex_u32](targetKeyId_u32 , targetKeyElementId, CryIf_KeyManagement_targetKeyElement_au8, &targetKeyElementSize_u32);

                if (E_OK == result_en)
                {
 
                    //check if copy is possible considering given offsets and lengths
                    if (CRYIF_PRV_CHECK_U32_ADD_OVERFLOW(keyElementSourceOffset, keyElementCopyLength) ||
                        CRYIF_PRV_CHECK_U32_ADD_OVERFLOW(keyElementTargetOffset, keyElementCopyLength) ||
                        ((keyElementSourceOffset + keyElementCopyLength) > keyElementSize_u32) ||
                         ((keyElementTargetOffset + keyElementCopyLength) > targetKeyElementSize_u32))
                         
                    {
                        result_en = CRYPTO_E_KEY_SIZE_MISMATCH;
                    }
                    else
                    {
                        for (i_u32 = 0U; i_u32 < keyElementCopyLength; i_u32++)
                        {
                            CryIf_KeyManagement_targetKeyElement_au8[i_u32 + keyElementTargetOffset] = CryIf_KeyManagement_sourceKeyElement_au8[i_u32 + keyElementSourceOffset];
                        }

                        //Call Crypto function
                        result_en = CryIf_KeyElementSet_acpfct[targetModuleIndex_u32](targetKeyId_u32 , targetKeyElementId, CryIf_KeyManagement_targetKeyElement_au8, targetKeyElementSize_u32);
                    }
                }
            }
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyCopy
 *
 * \brief This function shall copy all key elements from the source key to a target key.
 *
 * \param[in]   cryIfKeyId        Holds the identifier of the key whose key element shall be the source element.
 * \param[in]   targetCryIfKeyId  Holds the identifier of the key whose key element shall be the destination element.
 * \return      Std_ReturnType    E_OK: Request successful
 *                                E_NOT_OK: Request Failed
 *                                CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is not available
 *                                CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
 *                                CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element.
 *                                CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible.
 *                                CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
 //TRACE[SWS_CryIf_91016]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyCopy: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
Std_ReturnType CryIf_KeyCopy(uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;
    uint32 targetKeyId_u32 = CSM_INVALID_ID;
    uint32 targetModuleIndex_u32 = CSM_INVALID_ID;
    uint32 sourceKeyElementIds_au32[CRYIF_PRV_COPY_MAX_KEYELEMENT_COUNT];
    uint32 sourceKeyElementIdsSize_u32 = CRYIF_PRV_COPY_MAX_KEYELEMENT_COUNT;
    uint32 targetKeyElementIds_au32[CRYIF_PRV_COPY_MAX_KEYELEMENT_COUNT];
    uint32 targetKeyElementIdsSize_u32 = CRYIF_PRV_COPY_MAX_KEYELEMENT_COUNT;
    uint32 i_u32;
    uint32 j_u32;
    uint32 keyElementSize_u32;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00116]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_COPY, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00117]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_COPY, CRYIF_E_PARAM_HANDLE);
    }
    //Check if targetCryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(targetCryIfKeyId))
    {
        //TRACE[SWS_CryIf_00118]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_COPY, CRYIF_E_PARAM_HANDLE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        targetModuleIndex_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoModuleIndex_u16;
        targetKeyId_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoKeyId_u32;
        //Check if both keyIds are on the same crypto
        if (moduleIndex_u32 == targetModuleIndex_u32)
        {
            //TRACE[SWS_CryIf_00115] Fulfilled in Crypto function
            //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
            //Call forwarding and mapping do not care about the execution contexts
            //[SWS_CryIf_00119]
            //Call Crypto function
            result_en = CryIf_KeyCopy_acpfct[moduleIndex_u32](keyId_u32, targetKeyId_u32);
        }
        else
        {
            //TRACE[SWS_CryIf_00120]
            //Get keyelement Ids from source crypto
            result_en = CryIf_KeyElementIdsGet_acpfct[moduleIndex_u32](keyId_u32,
                                                                       &sourceKeyElementIds_au32[0],
                                                                       &sourceKeyElementIdsSize_u32);
            //Get keyelement Ids from target crypto if source KeyElementIdsGet call not failed
            if (E_OK == result_en)
            {
                result_en = CryIf_KeyElementIdsGet_acpfct[targetModuleIndex_u32](targetKeyId_u32,
                                                                                 &targetKeyElementIds_au32[0],
                                                                                 &targetKeyElementIdsSize_u32);
            }
            //Try to copy all keyelements found in source key
            for (i_u32 = 0U; (i_u32 < sourceKeyElementIdsSize_u32) && (E_OK == result_en); i_u32++)
            {
                //Only perform copy for keyelement which is also present in target key
                for (j_u32 = 0U; (j_u32 < targetKeyElementIdsSize_u32); j_u32++)
                {
                    if (sourceKeyElementIds_au32[i_u32] == targetKeyElementIds_au32[j_u32])
                    {
                        //Reset provided buffer size for keyElementGet call
                        keyElementSize_u32 = CRYIF_CFG_KEY_ELEMENT_COPY_MAX_SIZE;
                        //Get source keyelement data
                        result_en = CryIf_KeyElementGet_acpfct[moduleIndex_u32](keyId_u32,
                                                                                sourceKeyElementIds_au32[i_u32],
                                                                                CryIf_KeyManagement_sourceKeyElement_au8,
                                                                                &keyElementSize_u32);

                        if (E_OK == result_en)
                        {
                            //Write keyelement data to target
                            result_en = CryIf_KeyElementSet_acpfct[targetModuleIndex_u32](targetKeyId_u32,
                                                                                          targetKeyElementIds_au32[j_u32],
                                                                                          CryIf_KeyManagement_sourceKeyElement_au8,
                                                                                          keyElementSize_u32);
                        }
                        //Target keyelement found and copy performed, stop search for target keyelement
                        break;
                    }
                }
            }
        }

        //TRACE[SWS_CryIf_00121]
        //Check if size mismatch or key not available was reported from Crypto
        if (CRYPTO_E_KEY_SIZE_MISMATCH == result_en)
        {
            //TRACE[SWS_CryIf_00121]|1
            (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_COPY, CRYIF_E_KEY_SIZE_MISMATCH);
            result_en = E_NOT_OK;
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyDerive
 *
 * \brief This function shall dispatch the key derive function to the configured crypto driver object.
 *
 * \param[in]    cryIfKeyId            Holds the identifier of the key which is used for key derivation.
 * \param[in]    targetCryIfKeyId      Holds the identifier of the key which is used to store the derived key.
 * \return       Std_ReturnType        E_OK: Request successful
 *                                     E_NOT_OK: Request Failed
 *                                     CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 *                                     CRYPTO_E_BUSY: Crypto Driver Object has returned CRYPTO_E_BUSY.
 **********************************************************************************************************************
 */
 //TRACE[SWS_CryIf_91009]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyDerive: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
Std_ReturnType CryIf_KeyDerive(uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;
    uint32 targetKeyId_u32 = CSM_INVALID_ID;
    uint32 targetModuleIndex_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00076]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_DERIVE, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00077]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_DERIVE, CRYIF_E_PARAM_HANDLE);
    }
    //Check if targetCryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(targetCryIfKeyId))
    {
        //TRACE[SWS_CryIf_00122]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_DERIVE, CRYIF_E_PARAM_HANDLE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        targetModuleIndex_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoModuleIndex_u16;
        targetKeyId_u32 = CryIf_KeyMapping_acst[targetCryIfKeyId].CryptoKeyId_u32;
        //Check if both keyIds are on the same crypto
        if (moduleIndex_u32 == targetModuleIndex_u32)
        {
            //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
            //Call forwarding and mapping do not care about the execution contexts
            //[SWS_CryIf_00081]
            //Call Crypto function
            result_en = CryIf_KeyDerive_acpfct[moduleIndex_u32](keyId_u32, targetKeyId_u32);
        }
        else
        {
            //Not supported return E_NOT_OK
            //Extended Developer Error
            (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_DERIVE, RBA_CRYIF_E_NOT_SUPPORTED);
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_CertificateVerify
 *
 * \brief Verifies the certificate stored in the key referenced by verifyCryIfKeyId with the certificate stored in
 *        the key referenced by cryIfKeyId.
 *
 * \param[in]    cryIfKeyId            Holds the identifier of the key which shall be used to validate the certificate.
 * \param[in]    verifyCryIfKeyId      Holds the identifier of the key containing the certificate to be verified.
 * \param[out]   verifyPtr             Holds a pointer to the memory location which will contain the result of the
 *                                     certificate verification.
 * \return       Std_ReturnType        E_OK: Request successful
 *                                     E_NOT_OK: Request Failed
 *                                     CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
 //TRACE[SWS_CryIf_Rb_91017]
/* HIS METRIC LEVEL VIOLATION IN CryIf_CertificateVerify: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
/* MR12 RULE 8.13 VIOLATION: verifyPtr can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_CertificateVerify(uint32 cryIfKeyId, uint32 verifyCryIfKeyId, Crypto_VerifyResultType* verifyPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;
    uint32 verifyKeyId_u32 = CSM_INVALID_ID;
    uint32 verifyModuleIndex_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_Rb_00123]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CERTIFICATE_VERIFY, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_Rb_00124]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CERTIFICATE_VERIFY, CRYIF_E_PARAM_HANDLE);
    }
    //Check if verifyCryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(verifyCryIfKeyId))
    {
        //TRACE[SWS_CryIf_Rb_00125]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CERTIFICATE_VERIFY, CRYIF_E_PARAM_HANDLE);
    }
    //Check if verifyPtr is invalid
    else if (NULL_PTR == verifyPtr)
    {
        //TRACE[SWS_CryIf_Rb_00127]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CERTIFICATE_VERIFY, CRYIF_E_PARAM_POINTER);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        verifyModuleIndex_u32 = CryIf_KeyMapping_acst[verifyCryIfKeyId].CryptoModuleIndex_u16;
        verifyKeyId_u32 = CryIf_KeyMapping_acst[verifyCryIfKeyId].CryptoKeyId_u32;
        //Check if both keyIds are on the same crypto
        if (moduleIndex_u32 == verifyModuleIndex_u32)
        {
            //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
            //Call forwarding and mapping do not care about the execution contexts
            //[SWS_CryIf_Rb_00128]
            //Call Crypto function
            result_en = CryIf_CertificateVerify_acpfct[moduleIndex_u32](keyId_u32, verifyKeyId_u32, verifyPtr);
        }
        else
        {
            //TRACE[SWS_CryIf_Rb_00126]|1
            (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CERTIFICATE_VERIFY, CRYIF_E_PARAM_HANDLE);
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_RandomSeed
 *
 * \brief This function shall dispatch the random seed function to the configured crypto driver object.
 *
 * \param[in]    cryIfKeyId      Holds the identifier of the key for which a new seed shall be generated.
 * \param[in]    seedPtr         Holds a pointer to the memory location which contains the data to feed the seed.
 * \param[in]    seedLength      Contains the length of the seed in bytes.
 * \return       Std_ReturnType  E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91007]
/* HIS METRIC LEVEL VIOLATION IN CryIf_RandomSeed: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
Std_ReturnType CryIf_RandomSeed(uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00068]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_RANDOM_SEED, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00069]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_RANDOM_SEED, CRYIF_E_PARAM_HANDLE);
    }
    //Check if seedPtr is invalid
    else if (NULL_PTR == seedPtr)
    {
        //TRACE[SWS_CryIf_00070]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_RANDOM_SEED, CRYIF_E_PARAM_POINTER);
    }
    //Check if seedLength value is invalid
    else if (0U == seedLength)
    {
        //TRACE[SWS_CryIf_00071]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_RANDOM_SEED, CRYIF_E_PARAM_VALUE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00072]
        //Call Crypto function
        result_en = CryIf_RandomSeed_acpfct[moduleIndex_u32](keyId_u32 , seedPtr, seedLength);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyGenerate
 *
 * \brief This function shall dispatch the key generate function to the configured crypto driver object.
 *
 * \param[in]    cryIfKeyId      Holds the identifier of the key which is to be updated with the generated value.
 * \return       Std_ReturnType  E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 *                               CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                               CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91008]
Std_ReturnType CryIf_KeyGenerate(uint32 cryIfKeyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00073]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_GENERATE, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00074]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_GENERATE, CRYIF_E_PARAM_HANDLE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00075]
        //Call Crypto function
        result_en = CryIf_KeyGenerate_acpfct[moduleIndex_u32](keyId_u32);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyExchangeCalcPubVal
 *
 * \brief This function shall dispatch the key exchange public value calculation function to the configured crypto
 *        driver object.
 *
 * \param[in]    cryIfKeyId           Holds the identifier of the key which shall be used for the key exchange protocol.
 * \param[out]   publicValuePtr       Contains the pointer to the data where the public value shall be stored.
 * \param[inout] publicValueLengthPtr Holds a pointer to the memory location in which the public value length
 *                                    information is stored. On calling this function, this parameter shall contain
 *                                    the size of the buffer provided by publicValuePtr. When the request has finished,
 *                                    the actual length of the returned value shall be stored.
 * \return       Std_ReturnType  E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 *                               CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                               CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91010]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyExchangeCalcPubVal: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
/* MR12 RULE 8.13 VIOLATION: parameter can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_KeyExchangeCalcPubVal(uint32 cryIfKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00082]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_PUB_VAL, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00083]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_PUB_VAL, CRYIF_E_PARAM_HANDLE);
    }
    //Check if publicValuePtr or publicValueLengthPtr is invalid
    else if ((NULL_PTR == publicValuePtr) || (NULL_PTR == publicValueLengthPtr))
    {
        //TRACE[SWS_CryIf_00084][SWS_CryIf_00085]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_PUB_VAL, CRYIF_E_PARAM_POINTER);
    }
    //Check if publicValueLength value is invalid
    else if (0U == (*publicValueLengthPtr))
    {
        //TRACE[SWS_CryIf_00086]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_PUB_VAL, CRYIF_E_PARAM_VALUE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00087]
        //Call Crypto function
        result_en = CryIf_KeyExchangeCalcPubVal_acpfct[moduleIndex_u32](keyId_u32 , publicValuePtr, publicValueLengthPtr);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_KeyExchangeCalcSecret
 *
 * \brief This function shall dispatch the key exchange common shared secret calculation function to the configured
 *        crypto driver object.
 *
 * \param[in]  cryIfKeyId               Holds the identifier of the key which shall be used for the key
 *                                      exchange protocol.
 * \param[in]  partnerPublicValuePtr    Holds the pointer to the memory location which contains the partner's
 *                                      public value.
 * \param[in]  partnerPublicValueLength Contains the length of the partner's public value in bytes.
 * \return     Std_ReturnType           E_OK: Request successful
 *                                      E_NOT_OK: Request Failed
 *                                      CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                                      CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91011]
/* HIS METRIC LEVEL VIOLATION IN CryIf_KeyExchangeCalcSecret: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.*/
Std_ReturnType CryIf_KeyExchangeCalcSecret(uint32 cryIfKeyId, const uint8* partnerPublicValuePtr,
                                           uint32 partnerPublicValueLength)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00090]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_SECRET, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_00091]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_SECRET, CRYIF_E_PARAM_HANDLE);
    }
    //Check if partnerPublicValuePtr is invalid
    else if (NULL_PTR == partnerPublicValuePtr)
    {
        //TRACE[SWS_CryIf_00092]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_SECRET, CRYIF_E_PARAM_POINTER);
    }
    //Check if partnerPublicValueLength value is invalid
    else if (0U == partnerPublicValueLength)
    {
        //TRACE[SWS_CryIf_00094]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_SECRET, CRYIF_E_PARAM_VALUE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00095]
        //Call Crypto function
        result_en = CryIf_KeyExchangeCalcSecret_acpfct[moduleIndex_u32](keyId_u32 , partnerPublicValuePtr, partnerPublicValueLength);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_CertificateParse
 *
 * \brief This function shall dispatch the certificate parse function to the configured crypto driver object.
 *
 * \param[in]    cryIfKeyId      Holds the identifier of the key which shall be parsed.
 * \return       Std_ReturnType  E_OK: Request successful
 *                               E_NOT_OK: Request Failed
 *                               CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 *                               CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_Rb_91012]
Std_ReturnType CryIf_CertificateParse(uint32 cryIfKeyId)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 keyId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_Rb_00098]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CERTIFICATE_PARSE, CRYIF_E_UNINIT);
    }
    //Check if cryIfKeyId is invalid
    else if (!CryIf_Prv_IsKeyIdInRange(cryIfKeyId))
    {
        //TRACE[SWS_CryIf_Rb_00099]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CERTIFICATE_PARSE, CRYIF_E_PARAM_HANDLE);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get key mapping parameters
        moduleIndex_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoModuleIndex_u16;
        keyId_u32 = CryIf_KeyMapping_acst[cryIfKeyId].CryptoKeyId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_Rb_00104]
        //Call Crypto function
        result_en = CryIf_CertificateParse_acpfct[moduleIndex_u32](keyId_u32);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_Rb_StorePermanentData
 *
 * \brief This function shall dispatch the store request to all crypto drivers.
 *
 * \return       Std_ReturnType       E_OK: Request done
 *                                    E_NOT_OK: Request Failed
 *                                    CRYPTO_E_PENDING: Request in progress
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_Rb_08197]
Std_ReturnType CryIf_Rb_StorePermanentData(void)
{
    Std_ReturnType result_en = E_OK;


    //Call all cryptos ( OR operation can be performed, possible return values are 0-E_OK, 1-E_NOT_OK, 2-E_PENDING
    //All cryptos are expected to provide this interface
    result_en |= CryIf_Rb_StorePermanentData_acpfct[0]();
    //Evaluate return value
    if(E_NOT_OK  == (result_en & E_NOT_OK))
    {
        //Error status is set, clear other state flag
        result_en = E_NOT_OK;
    }


    return result_en;
}

#define CRYIF_STOP_SEC_CODE
#include "CryIf_MemMap.h"

