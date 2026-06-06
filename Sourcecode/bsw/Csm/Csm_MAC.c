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
 * Csm_MacGenerate
 *
 * \brief Uses the given data to perform a MAC generation and stores the MAC in the memory location pointed to by the
 *        MAC pointer.
 *
 * \param[in] jobId              Holds the identifier of the job using the CSM service.
 * \param[in] mode               Indicates which operation mode(s) to perfom.
 * \param[in] dataPtr            Contains the pointer to the data for which the MAC shall be computed.
 * \param[in] dataLength         Contains the number of data bytes for which the MAC shall be computed
 * \param[inout] macLengthPtr    Holds a pointer to the memory location in which the output length in bytes is stored
 *                               On calling this function, this parameter shall contain the size of the buffer provided
 *                               by macPtr. When the request has finished, the actual length of the returned MAC shall
 *                               be stored.
 * \param[out] macPtr            Contains the pointer to the data where the MAC shall be stored.
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
 //TRACE[SWS_Csm_00982]
/* HIS METRIC PARAM,LEVEL VIOLATION IN Csm_MacGenerate: Function contains most simple "else if" implementation of
   Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.
   Interface parameters are defined in AR specification and cannot be modified.*/
Std_ReturnType Csm_MacGenerate(uint32 jobId, Crypto_OperationModeType mode, const uint8* dataPtr, uint32 dataLength,
                               uint8* macPtr, uint32* macLengthPtr )
{
    Std_ReturnType result_en = E_NOT_OK;
    uint8 redirectionConfig_u8;
    uint8 primaryInputRedirection_u8    = 0U;
    uint8 primaryOutputRedirection_u8   = 0U;

    // Get redirection configuration for each input/output
    if ((Csm_Prv_IsJobIdInRange(jobId)) && (NULL_PTR != Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef))
    {
        redirectionConfig_u8 = Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef->redirectionConfig;
        primaryInputRedirection_u8   = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT);
        primaryOutputRedirection_u8  = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT);
    }


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    /* MR12 RULE 13.5 VIOLATION: some compilers does not support #pragma PRQA_NO_SIDE_EFFECTS (for Csm_Prv_IsParamOK) */
    else if (((0U != (mode & CRYPTO_OPERATIONMODE_UPDATE)) &&
              (!Csm_Prv_IsParamOk(primaryInputRedirection_u8, dataPtr, &dataLength))) ||
             ((0U != (mode & CRYPTO_OPERATIONMODE_FINISH)) &&
              (!Csm_Prv_IsParamOk(primaryOutputRedirection_u8, macPtr, macLengthPtr))))
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
    else if (!Csm_Prv_IsJobServiceOk(jobId, CRYPTO_MACGENERATE))
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

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputPtr = dataPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputLength = dataLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.outputPtr = macPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.outputLengthPtr = macLengthPtr;
        // job dispatch
        result_en = Csm_Prv_DispatchJob(jobId);
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_MacVerify
 *
 * \brief Verifies the given MAC by comparing if the MAC is generated with the given data.
 *
 * \param[in] jobId               Holds the identifier of the job using the CSM service.
 * \param[in] mode                Indicates which operation mode(s) to perfom.
 * \param[in] dataPtr             Contains the pointer to the data for which the MAC shall be verified.
 * \param[in] dataLength          Contains the number of data bytes for which the MAC shall be verified.
 * \param[in] macPtr              Holds a pointer to the MAC to be verified.
 * \param[in] macLength           Contains the MAC length in BITS to be verified.
 * \param[out] verifyPtr          Holds a pointer to the memory location, which will hold the result of
 *                                the MAC verification.
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
 //TRACE[SWS_Csm_01050]
/* HIS METRIC PARAM,LEVEL VIOLATION IN Csm_MacVerify: Function contains most simple "else if" implementation of
   Autosar specified functionality. HIS metric compliance would decrease readability and maintainability.
   Interface parameters are defined in AR specification and cannot be modified.*/
Std_ReturnType Csm_MacVerify( uint32 jobId, Crypto_OperationModeType mode, const uint8* dataPtr, uint32 dataLength,
                              const uint8* macPtr, const uint32 macLength, Crypto_VerifyResultType* verifyPtr )
{
    Std_ReturnType result_en = E_NOT_OK;
    uint8 redirectionConfig_u8;
    uint8 primaryInputRedirection_u8    = 0U;
    uint8 secondaryInputRedirection_u8  = 0U;

    // Get redirection configuration for each input/output
    if ((Csm_Prv_IsJobIdInRange(jobId)) && (NULL_PTR != Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef))
    {
        redirectionConfig_u8 = Csm_Prv_Jobs_ast[jobId].jobRedirectionInfoRef->redirectionConfig;
        primaryInputRedirection_u8   = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT);
        secondaryInputRedirection_u8 = (redirectionConfig_u8 & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT);
    }


    if (!Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91008]|0
    }
    /* MR12 RULE 13.5 VIOLATION: some compilers does not support #pragma PRQA_NO_SIDE_EFFECTS (for Csm_Prv_IsParamOK) */
    else if (((0U != (mode & CRYPTO_OPERATIONMODE_UPDATE)) &&
              (!Csm_Prv_IsParamOk(primaryInputRedirection_u8, dataPtr, &dataLength))) ||
             ((0U != (mode & CRYPTO_OPERATIONMODE_FINISH)) &&
              ((!Csm_Prv_IsParamOk(secondaryInputRedirection_u8, macPtr, &macLength)) || (NULL_PTR == verifyPtr))))
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
    else if (!Csm_Prv_IsJobServiceOk(jobId, CRYPTO_MACVERIFY))
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

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputPtr = dataPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.inputLength = dataLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryInputPtr = macPtr;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.secondaryInputLength = macLength;

        Csm_Prv_Jobs_ast[jobId].jobPrimitiveInputOutput.verifyPtr = verifyPtr;
        // job dispatch
        result_en = Csm_Prv_DispatchJob(jobId);
    }


    return result_en;
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

