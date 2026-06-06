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
#include "Csm_Cbk.h"
//TRACE[SWS_Csm_91100]
#include "CryIf.h"
#include "Csm_Prv.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/

#define CSM_START_SEC_CONST_8
#include "Csm_MemMap.h"

const uint8 Csm_Prv_ServiceInfoTypeToServiceIdMapping_acu8[] =
{
    0x5DU,//CRYPTO_HASH                  = 0x00
    0x60U,//CRYPTO_MACGENERATE           = 0x01
    0x61U,//CRYPTO_MACVERIFY             = 0x02
    0x5EU,//CRYPTO_ENCRYPT               = 0x03
    0x5FU,//CRYPTO_DECRYPT               = 0x04
    0x62U,//CRYPTO_AEADENCRYPT           = 0x05
    0x63U,//CRYPTO_AEADDECRYPT           = 0x06
    0x76U,//CRYPTO_SIGNATUREGENERATE     = 0x07
    0x64U,//CRYPTO_SIGNATUREVERIFY       = 0x08
    0x00U,//UNUSED                       = 0x09
    0x00U,//UNUSED                       = 0x0A
    0x72U,//CRYPTO_RANDOMGENERATE        = 0x0B
    0x7BU,//CRYPTO_RANDOMSEED            = 0x0C
    0x7CU,//CRYPTO_KEYGENERATE           = 0x0D
    0x7DU,//CRYPTO_KEYDERIVE             = 0x0E
    0x7EU,//CRYPTO_KEYEXCHANGECALCPUBVAL = 0x0F
    0x7FU,//CRYPTO_KEYEXCHANGECALCSECRET = 0x10
    0x6EU,//CRYPTO_CERTIFICATEPARSE      = 0x11
    0x74U,//CRYPTO_CERTIFICATEVERIFY     = 0x12
    0x7AU,//CRYPTO_KEYSETVALID           = 0x13
    0xFEU,//CRYPTO_SHEGETID              = 0x14
    0xFDU,//CRYPTO_SHELOADKEY            = 0x15
    0xFCU,//CRYPTO_SHELOADKEYSLOT        = 0x16
    0xFBU,//CRYPTO_SHELOADPLAINKEY       = 0x17
    0xFAU,//CRYPTO_SHEEXPORTRAMKEY       = 0x18
    0x8AU,//CRYPTO_KEYELEMENTGET         = 0x19
    0x8BU,//CRYPTO_KEYELEMENTSET         = 0x1A
};

#define CSM_STOP_SEC_CONST_8
#include "Csm_MemMap.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"

/**
 **********************************************************************************************************************
 * Csm_Prv_MainFunction
 *
 * \brief This private function performs the asynchronous job processing of the CSM module.
 *
 * \param[in] partitionIndex_u32       Index of the partition group of jobs/queues to be processed
 *
 **********************************************************************************************************************
 */
/* HIS METRIC PATH, v(G), CALLS, LEVEL VIOLATION IN Csm_MainFunction: Function contains most simple "else if"
implementation of Autosar specified functionality.
HIS metric compliance would decrease readability and maintainability. */
void Csm_Prv_MainFunction(uint32 partitionIndex_u32)
{
    uint32 i;
    Crypto_JobType* job_pst;
    Std_ReturnType result_en;
    const Crypto_Queue_tst* queue_pst;
    uint32 callbackId_u32;


    if (Csm_Prv_IsInitialized())
    {
        //TRACE[SWS_Csm_91065]
        for (i = Csm_Prv_PartitionConfig_cast[partitionIndex_u32].queueStartId_u32;
             i <= Csm_Prv_PartitionConfig_cast[partitionIndex_u32].queueEndId_u32;
             i++)
        {
            /* Process waiting job requests */
            queue_pst = Csm_Prv_QueueRefs_apst[i];

            // check if queue is not empty
            if (NULL_PTR != queue_pst)
            {
                while (E_OK == Csm_Prv_Queue_Peek(queue_pst, &job_pst))
                {
                    // check if job is canceled
                    if (FALSE != job_pst->jobCanceled_b)
                    {
                        // no call needed to CryIf_CancelJob because job found in Csm queue
                        // get callbackId of the job
                        callbackId_u32 = Csm_Prv_JobPrimitiveInfos_acst[job_pst->jobId].callbackId;
                        // call async job callback TRACE[SWS_Crypto_00028]TRACE[SWS_Csm_01030]
                        Csm_Prv_Callback(callbackId_u32,job_pst->jobId,CRYPTO_E_JOB_CANCELED);
                        // switch job into idle state
                        job_pst->jobState = CRYPTO_JOBSTATE_IDLE;
                        // must clear cancel flag when job is in IDLE state, because in this state
                        // cancel requests are declined and the flag cannot be set concurrently to TRUE
                        job_pst->jobCanceled_b = FALSE;
                    }
                    else
                    {
                        //TRACE[SWS_Csm_00036]
                        // drop const due to AR interface
                        {
                            //TRACE[SWS_Csm_01093] no additional checking needed, both key ids
                            //                     are statically generated from configuration
                            result_en = CryIf_ProcessJob(Csm_Prv_QueueChanneldIdMapping_acu32[i], job_pst);
                        }

                        if (CRYPTO_E_BUSY == result_en)
                        {
                            // external callout state needs to be changed back to WAITING
                            // normal calls not affected, state stays the same
                            job_pst->jobState = CRYPTO_JOBSTATE_WAITING;
                            // leave job in queue
                            break;
                        }
                    }
                    // job successfully dispatched or canceled, remove from queue
                    // return is always E_OK because job_pst is get using Queue_Peek function
                    (void)Csm_Prv_Queue_Remove(queue_pst, job_pst);
                }
            }
        }
    }
}

/**
 **********************************************************************************************************************
 * Csm_Prv_IsModeBitsOk
 *
 * \brief validate mode bits, white listing
 *  000  undefined, fail
 *  001  start
 *  010  update
 *  011  streamstart
 *  100  finish
 *  101  forbidden [SWS_Csm_01045]
 *  110  update and finish
 *  111  singlecall
 *
 * \param[in] mode       mode bits
 *
 * \retval TRUE          validation successful
 * \retval FALSE         validation failed
 *
 **********************************************************************************************************************
 */
 //TRACE[SWS_Csm_01045]
boolean Csm_Prv_IsModeBitsOk(Crypto_OperationModeType mode)
{
    boolean result_b;


    switch (mode)
    {
        case CRYPTO_OPERATIONMODE_SINGLECALL :
        case CRYPTO_OPERATIONMODE_UPDATE :
        case CRYPTO_OPERATIONMODE_START :
        case CRYPTO_OPERATIONMODE_FINISH :
        case CRYPTO_OPERATIONMODE_STREAMSTART :
        {
            result_b = TRUE;
            break;
        }
        default :
        {
            result_b = FALSE;
            break;
        }
    }


    return result_b;
}

/**
 **********************************************************************************************************************
 * Csm_Prv_DispatchJob
 *
 * \brief job processing according to [SWS_Csm_01041] with minor deviation: if async job prio is highest then first
 *        try to process it and after processing try to queue it if rejected
 *
 * \param[in] jobId             Holds the identifier of the job to be dispatched
 *
 * \retval E_OK: request successful
 * \retval E_NOT_OK: request failed
 * \retval CRYPTO_E_BUSY: request failed, service is still busy
 * \retval CRYPTO_E_KEY_NOT_VALID, Request failed, the key is not valid
 * \retval CRYPTO_E_KEY_SIZE_MISMATCH, Request failed, a key element has the wrong size.
 * \retval CRYPTO_E_JOB_CANCELED: Immediate cancelation not possible.
 *                                The cancelation will be done at next suitable processing step.
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_01041]TRACE[SWS_Csm_00022]TRACE[SWS_Csm_00945]
 /* HIS METRIC v(G),LEVEL VIOLATION IN Csm_Prv_DispatchJob: Function contains most simple "else if" implementation of
 Autosar specified functionality. HIS metric compliance would decrease readability and maintainability. */
Std_ReturnType Csm_Prv_DispatchJob(uint32 jobId)
{
    Std_ReturnType result_en = E_NOT_OK;
    const uint32 queueId_cu32 = Csm_Prv_JobQueueIdMapping_acu32[jobId];
    const uint32 channelId_cu32 = Csm_Prv_QueueChanneldIdMapping_acu32[queueId_cu32];
    Crypto_JobType * job_pst = &Csm_Prv_Jobs_ast[jobId];
    boolean processJob_b;
    const Crypto_Queue_tst * const queue_pst = Csm_Prv_QueueRefs_apst[queueId_cu32];
    const Crypto_ProcessingType processingType_ce = job_pst->jobPrimitiveInfo->processingType;
    const Crypto_ServiceInfoType serviceInfoType_ce = job_pst->jobPrimitiveInfo->primitiveInfo->service;
    uint32 i;

    //TRACE[SWS_Csm_00017][SWS_Csm_Rb_00037][SWS_Csm_00035]
    // execute processjob if
    // job is already active or there is no queue configured
    if ((CRYPTO_JOBSTATE_ACTIVE == job_pst->jobState) ||
        (NULL_PTR == queue_pst))
    {
        processJob_b = TRUE;
    }
    // the job is async then the queue need to be empty
    else if (CRYPTO_PROCESSING_ASYNC == processingType_ce)
    {
        processJob_b = (CRYPTO_INVALID_PRIO_LEVEL == Csm_Prv_Queue_HighestPrioLevelWaiting(queue_pst));
    }
    // the job must be here sync so the job has to have higher priority as any waiting job in the queue
    else
    {
        processJob_b = Csm_Prv_IsJobPriorityHigh(queue_pst, job_pst);
    }

    if (processJob_b)
    {
        {
            //TRACE[SWS_Csm_01093] no additional checking needed, both key ids
            //                     are statically generated from configuration
            result_en = CryIf_ProcessJob(channelId_cu32, job_pst);
        }
    }
    else
    {
        //TRACE[SWS_Csm_91007]
        result_en = CRYPTO_E_BUSY;
    }

    //TRACE[SWS_Crypto_00033][SWS_Crypto_00121][SWS_Crypto_00034]
    // check if crypto is busy and job is async, operation mode already checked
    if ((CRYPTO_E_BUSY == result_en) &&
        (CRYPTO_PROCESSING_ASYNC == processingType_ce))
    {
        // check if queue is available
        if (NULL_PTR != queue_pst)
        {
            /* Try to lock the job queue realted to crypto driver object */
            SchM_Enter_Csm_JobQueueAccess(queueId_cu32);

            //TRACE[SWS_Crypto_00029][SWS_Csm_00940][SWS_Csm_00944]
            result_en = Csm_Prv_EnqueueAndUpdateJob(queue_pst, job_pst);

            /* Exit critical section */
            SchM_Exit_Csm_JobQueueAccess(queueId_cu32);

            // indication of a queue overrun
            if (CRYPTO_E_BUSY == result_en)
            {
                //TRACE[SWS_Csm_01088]|1
                (void)Det_ReportRuntimeError(CSM_MODULE_ID, CSM_INSTANCE_ID, Csm_Prv_ServiceInfoTypeToServiceIdMapping_acu8[serviceInfoType_ce], CSM_E_QUEUE_FULL);
            }
        }
        else
        {
            // there is no queue so return busy
        }
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_Prv_Callback
 *
 * \brief Call Normal or RTE Callback function based on callbackId
 *
 * \param[in] callBackId_cu32             Id of the callback
 * \param[in] jobId                       Id of the job
 * \param[in] result                      Status value of the operation
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_01090]
void Csm_Prv_Callback(uint32 callBackId_cu32, uint32 jobId, Crypto_ResultType result)
{
    //TRACE[SWS_Csm_01095]
    {
        //TRACE[SWS_Csm_00971]
        Csm_Prv_CallbackConfig_acpfct[callBackId_cu32](jobId, result);
    }
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

