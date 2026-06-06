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

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CRYIF_START_SEC_CODE
#include "CryIf_MemMap.h"
/**
 **********************************************************************************************************************
 * CryIf_ProcessJob
 *
 * \brief This interface dispatches the received jobs to the configured crypto driver object.
 *
 * \param[in]    channelId      Holds the identifier of the crypto channel.
 * \param[inout] job            Pointer to the configuration of the job. Contains structures with user and primitive
 *                              relevant information.
 * \return       Std_ReturnType E_OK: Request successful
 *                              E_NOT_OK: Request Failed
 *                              CRYPTO_E_BUSY: Request Failed, Crypro Driver Object is Busy
 *                              CRYPTO_E_KEY_NOT_VALID, Request failed, the key is not valid
 *                              CRYPTO_E_KEY_SIZE_MISMATCH, Request failed, a key element has the wrong size.
 *                              CRYIF_E_QUEUE_FULL: Request failed, the queue is full
 *                              CRYPTO_E_KEY_READ_FAIL: Request failed, because key element extraction is not allowed
 *                              CRYPTO_E_KEY_WRITE_FAIL: Request failed because the writing access failed
 *                              CRYPTO_E_JOB_CANCELED: Request failed because the synchronous Job has been canceled.
 *                              CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
 *                              CRYPTO_E_ENTROPY_EXHAUSTED: Request failed because the entropy of the random number
 *                                                          generator is exhausted
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91003]
/* MR12 RULE 8.13 VIOLATION: job can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_ProcessJob(uint32 channelId, Crypto_JobType* job)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 driverObjectId_u32 = CSM_INVALID_ID;
    Crypto_ServiceInfoType serviceType_en;
    boolean keyCheckFailed_b = FALSE;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00027]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_PROCESS_JOB, CRYIF_E_UNINIT);
    }
    //Check if channelId is invalid
    else if (!CryIf_Prv_IsChannelIdInRange(channelId))
    {
        //TRACE[SWS_CryIf_00028]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_PROCESS_JOB, CRYIF_E_PARAM_HANDLE);
    }
    //Check if job is invalid
    else if (NULL_PTR == job)
    {
        //TRACE[SWS_CryIf_00029]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_PROCESS_JOB, CRYIF_E_PARAM_POINTER);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get channel mapping parameters
        moduleIndex_u32 = CryIf_ChannelMapping_acst[channelId].CryptoModuleIndex_u16;
        driverObjectId_u32 = CryIf_ChannelMapping_acst[channelId].CryptoDriverObjectId_u32;
        //Perform key id mapping for cryptoKeyId
        //TRACE[SWS_CryIf_00133]
        serviceType_en = job->jobPrimitiveInfo->primitiveInfo->service;
        if (CryIf_Prv_IsKeyIdInRange(job->jobPrimitiveInputOutput.cryIfKeyId))
        {
            //TRACE[[SWS_CryIf_00136]
            job->cryptoKeyId = CryIf_KeyMapping_acst[job->jobPrimitiveInputOutput.cryIfKeyId].CryptoKeyId_u32;
        }
        //TRACE[SWS_CryIf_00134]TRACE[SWS_CryIf_00141]
        else if((CRYPTO_KEYSETVALID == serviceType_en) ||
                (CRYPTO_RANDOMSEED == serviceType_en) ||
                (CRYPTO_KEYGENERATE == serviceType_en) ||
                (CRYPTO_KEYDERIVE == serviceType_en) ||
                (CRYPTO_KEYELEMENTGET == serviceType_en) ||
                (CRYPTO_KEYELEMENTSET == serviceType_en) ||
                (CRYPTO_KEYEXCHANGECALCPUBVAL == serviceType_en) ||
                (CRYPTO_KEYEXCHANGECALCSECRET == serviceType_en) ||
                (CRYPTO_CERTIFICATEPARSE == serviceType_en) ||
                (CRYPTO_CERTIFICATEVERIFY == serviceType_en))
        {
            //TRACE[SWS_CryIf_00134][SWS_CryIf_00141]]|1
            (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_PROCESS_JOB, CRYIF_E_PARAM_HANDLE);
            //Signal key check failed
            keyCheckFailed_b = TRUE;
        }
        else
        {
           //Nothing to do, the job don't require a key parameter
        }
        //TRACE[SWS_CryIf_00142]
        // set operation of job->cryptoKeyId based on job->jobPrimitiveInfo->cryIfKeyId
        // not performed because both values are static and already initialised with correct values
        // on startup (only when Post Build configurations used this operation needed)
        //TRACE[SWS_CryIf_00143]
        // no mapping performed during runtime so the validity check of job->jobPrimitiveInfo->cryIfKeyId
        // is not needed

        //Perform key id mapping for targetCryptoKeyId
        //TRACE[SWS_CryIf_00133]
        if (CryIf_Prv_IsKeyIdInRange(job->jobPrimitiveInputOutput.targetCryIfKeyId))
        {
            //TRACE[[SWS_CryIf_00136]
            job->targetCryptoKeyId = CryIf_KeyMapping_acst[job->jobPrimitiveInputOutput.targetCryIfKeyId].CryptoKeyId_u32;
        }
        //TRACE[SWS_CryIf_00135]TRACE[SWS_CryIf_00141]
        else if((CRYPTO_KEYDERIVE == serviceType_en) ||
                (CRYPTO_CERTIFICATEVERIFY == serviceType_en))
        {
            //TRACE[SWS_CryIf_00135][SWS_CryIf_00141]|1
            (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_PROCESS_JOB, CRYIF_E_PARAM_HANDLE);
            //Signal key check failed
            keyCheckFailed_b = TRUE;
        }
        else
        {
           //Nothing to do, the job don't require a targetKey parameter
        }
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00044]
        if (FALSE == keyCheckFailed_b)
        {
            //Call Crypto function
            result_en = CryIf_ProcessJob_acpfct[moduleIndex_u32](driverObjectId_u32 , job);
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * CryIf_CancelJob
 *
 * \brief This interface dispatches the job cancellation function to the configured crypto driver object.
 *
 * \param[in]    channelId      Holds the identifier of the crypto channel.
 * \param[inout] job            Pointer to the configuration of the job. Contains structures with user and primitive
 *                              relevant information.
 * \return       Std_ReturnType E_OK: Request successful, job has been removed
 *                              E_NOT_OK: Request Failed, job couldn't be removed
 **********************************************************************************************************************
 */
//TRACE[SWS_CryIf_91014]
/* MR12 RULE 8.13 VIOLATION: job can not be const because this interface is defined by AUTOSAR */
Std_ReturnType CryIf_CancelJob(uint32 channelId, Crypto_JobType* job)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 moduleIndex_u32 = CSM_INVALID_ID;
    uint32 driverObjectId_u32 = CSM_INVALID_ID;


    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00129]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CANCEL_JOB, CRYIF_E_UNINIT);
    }
    //Check if channelId is invalid
    else if (!CryIf_Prv_IsChannelIdInRange(channelId))
    {
        //TRACE[SWS_CryIf_00130]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CANCEL_JOB, CRYIF_E_PARAM_HANDLE);
    }
    //Check if job is invalid
    else if (NULL_PTR == job)
    {
        //TRACE[SWS_CryIf_00131]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CANCEL_JOB, CRYIF_E_PARAM_POINTER);
    }
    //Perform Id mapping and function mapping then call crypto
    else
    {
        //Get channel mapping parameters
        moduleIndex_u32 = CryIf_ChannelMapping_acst[channelId].CryptoModuleIndex_u16;
        driverObjectId_u32 = CryIf_ChannelMapping_acst[channelId].CryptoDriverObjectId_u32;
        //TRACE[SWS_CryIf_00144][SWS_CryIf_00145]
        //Call forwarding and mapping do not care about the execution contexts
        //[SWS_CryIf_00132]
        //Call Crypto function
        result_en = CryIf_CancelJob_acpfct[moduleIndex_u32](driverObjectId_u32 , job);
    }


    return result_en;
}
#define CRYIF_STOP_SEC_CODE
#include "CryIf_MemMap.h"

