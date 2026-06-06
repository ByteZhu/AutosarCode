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
//TRACE[SWS_Csm_91100]
#include "CryIf.h"
#include "Csm_Prv.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/

#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"

/**
 **********************************************************************************************************************
 * Csm_CancelJob
 *
 * \brief Cancels the job processing from asynchronous or streaming jobs.
 *
 * \param[in] jobId            Holds the identifier of the job to be canceled
 * \param[in] mode             Not used, just for interface compatibility provided.
 *
 * \retval Std_ReturnType       E_OK: Request successful. Job removed.
 *                              E_NOT_OK: Request failed
 *                              CRYPTO_E_JOB_CANCELED: Immediate cancelation not possible.
 *                                                     The cancelation will be done at next suitable processing step.
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00968]
Std_ReturnType Csm_CancelJob(uint32 jobId, Crypto_OperationModeType mode)
{
    Std_ReturnType result_en = E_NOT_OK;


    CSM_PARAM_UNUSED(mode);
    // check jobId
    if (!Csm_Prv_IsJobIdInRange(jobId))
    {
        //TRACE[SWS_Csm_91011]|0
    }
    else if (CRYPTO_JOBSTATE_IDLE == Csm_Prv_Jobs_ast[jobId].jobState)
    {
        // nothing to do, job is not active
        result_en = E_OK;
    }
    else
    {
        //TRACE[SWS_Csm_01021]
        // CryIf_CancelJob always called, because cancel request registered by the crypto component
        {
            //TRACE[SWS_Csm_01087] Async jobs always return CRYPTO_E_JOB_CANCELED and callbacks are
            // triggered from the crypto component
            result_en = CryIf_CancelJob(Csm_Prv_QueueChanneldIdMapping_acu32[Csm_Prv_JobQueueIdMapping_acu32[jobId]],
                                        (Crypto_JobType*) &Csm_Prv_Jobs_ast[jobId]);
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_CallbackNotification
 *
 * \brief Notifies the CSM that a job has finished. This function is used by the underlying layer (CRYIF).
 *
 * \param[in] job           Holds a pointer to the job, which has finished.
 * \param[in] result        Contains the result of the cryptographic operation.
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00970] TRACE[SWS_Csm_00039]
/* MR12 RULE 8.13 VIOLATION: job can not be const because this interface is defined by AUTOSAR */
void Csm_CallbackNotification(Crypto_JobType* job, Crypto_ResultType result)
{
    uint32 callBackId_u32;
    const uint32 jobId_cu32 = job->jobId;


    {
        callBackId_u32 = job->jobPrimitiveInfo->callbackId;

        //TRACE[SWS_Csm_01090]
        Csm_Prv_Callback(callBackId_u32, jobId_cu32, result);
    }
}

/**
 **********************************************************************************************************************
 * Csm_Rb_Deinit
 *
 * \brief Deinitializes the CSM module.
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_Rb_04890]
void Csm_Rb_Deinit(void)
{
    Csm_Initialized_b = FALSE;
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

