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
#include "Csm_Prv.h"


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
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"
/**
 **********************************************************************************************************************
 * Csm_AEADEncrypt
 *
 * \brief Uses the given input data to perform a AEAD encryption and stores the ciphertext and the MAC in the memory
 *        locations pointed by the ciphertext pointer and Tag pointer.
 *
 * \param[in] jobId                     Holds the identifier of the job using the CSM service.
 * \param[in] mode                      Indicates which operation mode(s) to perfom.
 * \param[in] plaintextPtr              Contains the pointer to the data to be encrypted.
 * \param[in] plaintextLength           Holds a pointer to the memory location in which the output length in bytes of
 *                                      the paintext is stored. On calling this function, this parameter shall contain
 *                                      the size of the buffer provided by plaintextPtr.
 * \param[in] associatedDataPtr         Contains the pointer to the associated data.
 * \param[in] associatedDataLength      Contains the number of bytes of the associated data.
 * \param[out] ciphertextPtr            Contains the pointer to the data where the encrypted data shall be stored.
 * \param[inout] ciphertextLengthPtr    Holds a pointer to the memory location in which the output length in bytes of
 *                                      the ciphertext is stored. On calling this function, this parameter shall
 *                                      contain the size of the buffer in bytes provided by resultPtr. When the request
 *                                      has finished, the actual length of the returned value shall be stored.
 * \param[out] tagPtr                   Contains the pointer to the data where the Tag shall be stored.
 * \param[inout] tagLengthPtr           Holds a pointer to the memory location in which the output length in bytes of
 *                                      the Tag is stored. On calling this function, this parameter shall contain the
 *                                      size of the buffer in bytes provided by resultPtr. When the request has
 *                                      finished, the actual length of the returned value shall be stored.
 *
 * \retval E_OK: request successful
 * \retval E_NOT_OK: request failed
 * \retval CRYPTO_E_BUSY: request failed, service is still busy
 * \retval CRYPTO_E_KEY_NOT_VALID: request failed, the key's state is "invalid"
 * \retval CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element has the wrong size
 * \retval CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 *
 **********************************************************************************************************************
 */
 //TRACE[SWS_Csm_01023]
/* HIS METRIC PARAM,LEVEL VIOLATION IN Csm_AEADEncrypt: Function contains most simple "else if" implementation of
   Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.
   Interface parameters are defined in AR specification and cannot be modified.*/
/* MR12 RULE 8.13 VIOLATION: tagPtr, tagLengthPtr can not be const because this interface is defined by AUTOSAR */
Std_ReturnType Csm_AEADEncrypt( uint32 jobId, Crypto_OperationModeType mode, const uint8* plaintextPtr,
                                uint32 plaintextLength, const uint8* associatedDataPtr, uint32 associatedDataLength,
                                uint8* ciphertextPtr, uint32* ciphertextLengthPtr, uint8* tagPtr, uint32* tagLengthPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint8 redirectionConfig_u8;
    uint8 primaryInputRedirection_u8    = 0U;
    uint8 secondaryInputRedirection_u8  = 0U;
    uint8 primaryOutputRedirection_u8   = 0U;
    uint8 secondaryOutputRedirection_u8 = 0U;

    // Get redirection configuration for each input/output
    if ((Csm_Prv_IsJobIdInRange(jobId)) && (NULL_PTR != Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef))
    {
        redirectionConfig_u8 = Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef->redirectionConfig;
        primaryInputRedirection_u8   = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT);
        secondaryInputRedirection_u8 = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT);
        primaryOutputRedirection_u8  = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT);
        secondaryOutputRedirection_u8 = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT);
    }

    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    /* MR12 RULE 13.5 VIOLATION: some compilers does not support #pragma PRQA_NO_SIDE_EFFECTS (for Csm_Prv_IsParamOK) */
    else if ((0U != (mode & CRYPTO_OPERATIONMODE_UPDATE)) &&
             (((!Csm_Prv_IsParamOk(primaryInputRedirection_u8, plaintextPtr, &plaintextLength)) &&
               (!Csm_Prv_IsParamOk(secondaryInputRedirection_u8, associatedDataPtr, &associatedDataLength))) ||
              ((Csm_Prv_IsParamOk(primaryInputRedirection_u8, plaintextPtr, &plaintextLength)) &&
               (!Csm_Prv_IsParamOk(primaryOutputRedirection_u8, ciphertextPtr, ciphertextLengthPtr)))))
    {
        //TRACE[SWS_Csm_91009]|0
    }
    /* MR12 RULE 13.5 VIOLATION: some compilers does not support #pragma PRQA_NO_SIDE_EFFECTS (for Csm_Prv_IsParamOK) */
    else if (((0U != (mode & CRYPTO_OPERATIONMODE_FINISH)) &&
             ((!Csm_Prv_IsParamOk(secondaryOutputRedirection_u8, tagPtr, tagLengthPtr)) ||
              (!Csm_Prv_IsParamOk(primaryOutputRedirection_u8, ciphertextPtr, ciphertextLengthPtr)))))
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsModeBitsOk(mode))
    {
        //TRACE[SWS_Csm_01045]|0
    }
    else if (!Csm_Prv_IsJobIdInRange(jobId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (!Csm_Prv_IsJobServiceOk(jobId, CRYPTO_AEADENCRYPT))
    {
        //TRACE[SWS_Csm_01091]|0
    }
    else if (!Csm_Prv_IsJobStateOk(jobId))
    {
        //TRACE[SWS_Csm_00016]|0
        result_en = CRYPTO_E_BUSY;
    }
    // Redirection only supports SINGLECALL operation mode.
    else if ((NULL_PTR != Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef) &&
             (CRYPTO_OPERATIONMODE_SINGLECALL != mode))
    {
        //TRACE[SWS_Csm_01045]|0
    }
    else
    {
        // set job parameters: TRACE[SWS_Crypto_00073]

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.mode = mode;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputPtr = plaintextPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputLength = plaintextLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.outputPtr = ciphertextPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.outputLengthPtr = ciphertextLengthPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryOutputPtr = tagPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryOutputLengthPtr = tagLengthPtr;
        // job dispatch
        result_en = Csm_Prv_DispatchJob(jobId);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_AEADDecrypt
 *
 * \brief Uses the given data to perform an AEAD encryption and stores the ciphertext and the MAC in the memory
 *        locations pointed by the ciphertext pointer and Tag pointer.
 *
 * \param[in] jobId                     Holds the identifier of the job using the CSM service.
 * \param[in] mode                      Indicates which operation mode(s) to perfom.
 * \param[in] ciphertextPtr             Contains the pointer to the data to be decrypted.
 * \param[in] ciphertextLength          Contains the number of bytes to decrypt.
 * \param[in] associatedDataPtr         Contains the pointer to the associated data.
 * \param[in] associatedDataLength      Contains the length in bytes of the associated data.
 * \param[in] tagPtr                    Contains the pointer to the Tag to be verified.
 * \param[in] tagLength                 Contains the length in bytes of the Tag to be verified.
 * \param[out] plaintextPtr             Contains the pointer to the data where the decrypted data shall be stored.
 * \param[inout] plaintextLengthPtr     Holds a pointer to the memory location in which the output length in bytes of
 *                                      the paintext is stored. On calling this function, this parameter shall contain
 *                                      the size of the buffer provided by plaintextPtr. When the request has finished,
 *                                      the actual length of the returned value shall be stored.
 * \param[out] verifyPtr                Contains the pointer to the result of the verification.
 *
 * \retval E_OK: request successful
 * \retval E_NOT_OK: request failed
 * \retval CRYPTO_E_BUSY: request failed, service is still busy
 * \retval CRYPTO_E_KEY_NOT_VALID: request failed, the key's state is "invalid"
 * \retval CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element has the wrong size
 * \retval CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 *
 **********************************************************************************************************************
 */
 //TRACE[SWS_Csm_01026]
/* HIS METRIC PARAM,LEVEL VIOLATION IN Csm_AEADDecrypt: Function contains most simple "else if" implementation of
   Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.
   Interface parameters are defined in AR specification and cannot be modified.*/
/* MR12 RULE 8.13 VIOLATION: verifyPtr can not be const because this interface is defined by AUTOSAR */
Std_ReturnType Csm_AEADDecrypt( uint32 jobId, Crypto_OperationModeType mode, const uint8* ciphertextPtr,
                                uint32 ciphertextLength, const uint8* associatedDataPtr, uint32 associatedDataLength,
                                const uint8* tagPtr, uint32 tagLength, uint8* plaintextPtr, uint32* plaintextLengthPtr,
                                Crypto_VerifyResultType* verifyPtr)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint8 redirectionConfig_u8;
    uint8 primaryInputRedirection_u8    = 0U;
    uint8 secondaryInputRedirection_u8  = 0U;
    uint8 tertiaryInputRedirection_u8   = 0U;
    uint8 primaryOutputRedirection_u8   = 0U;

    // Get redirection configuration for each input/output
    if ((Csm_Prv_IsJobIdInRange(jobId)) && (NULL_PTR != Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef))
    {
        redirectionConfig_u8 = Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef->redirectionConfig;
        primaryInputRedirection_u8   = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT);
        secondaryInputRedirection_u8 = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT);
        tertiaryInputRedirection_u8  = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT);
        primaryOutputRedirection_u8  = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT);
    }

    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    /* MR12 RULE 13.5 VIOLATION: some compilers does not support #pragma PRQA_NO_SIDE_EFFECTS (for Csm_Prv_IsParamOK) */
    else if ((0U != (mode & CRYPTO_OPERATIONMODE_UPDATE)) &&
             (((!Csm_Prv_IsParamOk(primaryInputRedirection_u8, ciphertextPtr, &ciphertextLength)) &&
               (!Csm_Prv_IsParamOk(secondaryInputRedirection_u8, associatedDataPtr, &associatedDataLength))) ||
              ((Csm_Prv_IsParamOk(primaryInputRedirection_u8, ciphertextPtr, &ciphertextLength)) &&
               (!Csm_Prv_IsParamOk(primaryOutputRedirection_u8, plaintextPtr, plaintextLengthPtr)))))
    {
        //TRACE[SWS_Csm_91009]|0
    }
    /* MR12 RULE 13.5 VIOLATION: some compilers does not support #pragma PRQA_NO_SIDE_EFFECTS (for Csm_Prv_IsParamOK) */
    else if ((0U != (mode & CRYPTO_OPERATIONMODE_FINISH)) &&
             ((!Csm_Prv_IsParamOk(tertiaryInputRedirection_u8, tagPtr, &tagLength)) ||
              (!Csm_Prv_IsParamOk(primaryOutputRedirection_u8, plaintextPtr, plaintextLengthPtr))))
    {
        //TRACE[SWS_Csm_91009]|0
    }
    else if (!Csm_Prv_IsModeBitsOk(mode))
    {
        //TRACE[SWS_Csm_01045]|0
    }
    else if (!Csm_Prv_IsJobIdInRange(jobId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (!Csm_Prv_IsJobServiceOk(jobId, CRYPTO_AEADDECRYPT))
    {
        //TRACE[SWS_Csm_01091]|0
    }
    else if (!Csm_Prv_IsJobStateOk(jobId))
    {
        //TRACE[SWS_Csm_00016]|0
        result_en = CRYPTO_E_BUSY;
    }
    // Redirection only supports SINGLECALL operation mode.
    else if ((NULL_PTR != Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef) &&
             (CRYPTO_OPERATIONMODE_SINGLECALL != mode))
    {
        //TRACE[SWS_Csm_01045]|0
    }
    else
    {
        // set job parameters: TRACE[SWS_Crypto_00073]

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.mode = mode;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputPtr = ciphertextPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputLength = ciphertextLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.tertiaryInputPtr = tagPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.tertiaryInputLength = tagLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.outputPtr = plaintextPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.outputLengthPtr = plaintextLengthPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.verifyPtr = verifyPtr;
        // job dispatch
        result_en = Csm_Prv_DispatchJob(jobId);
    }


    return result_en;
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

