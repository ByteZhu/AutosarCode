/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CSM_PRV_H
#define CSM_PRV_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Csm.h"
#include "Csm_Cfg.h"
#include "Csm_Cfg_SchM.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

// partition configuration (queues must be ordered with respect of the partition)
typedef struct
{
    uint32 queueStartId_u32;
    uint32 queueEndId_u32;
} Csm_Prv_PartitionConfig_st;

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"
extern boolean Csm_Prv_IsModeBitsOk(Crypto_OperationModeType mode);
extern Std_ReturnType Csm_Prv_DispatchJob(uint32 jobId);
extern void Csm_Prv_Callback(uint32 callBackId_cu32, uint32 jobId, Crypto_ResultType result);
extern void Csm_Prv_MainFunction(uint32 partitionIndex_u32);

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

#define CSM_START_SEC_CONST_8
#include "Csm_MemMap.h"

extern const uint8 Csm_Prv_ServiceInfoTypeToServiceIdMapping_acu8[];

#define CSM_STOP_SEC_CONST_8
#include "Csm_MemMap.h"

#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

// jobs
extern const Crypto_JobInfoType Csm_Prv_JobInfos_acst[CSM_CFG_JOB_COUNT];
extern const Crypto_JobPrimitiveInfoType Csm_Prv_JobPrimitiveInfos_acst[CSM_CFG_JOB_COUNT];

// primitives
extern const Crypto_PrimitiveInfoType Csm_Prv_Primitives_acst[CSM_CFG_PRIMITIVE_COUNT];

// service C callback functions
extern void (* const Csm_Prv_CallbackConfig_acpfct[CSM_CFG_CALLBACK_COUNT])(uint32 jobId, Crypto_ResultType result);

extern const Csm_Prv_PartitionConfig_st Csm_Prv_PartitionConfig_cast[CSM_CFG_PARTITION_COUNT];

#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
extern const Crypto_Queue_tst* const Csm_Prv_QueueRefs_apst[CSM_CFG_QUEUE_COUNT];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"


#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"

extern boolean Csm_Initialized_b;
// jobs
extern Crypto_JobType Csm_Prv_Jobs_ast[CSM_CFG_JOB_COUNT];

#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"

/*
 **********************************************************************************************************************
 * Implementations
 **********************************************************************************************************************
*/

/**
 ***********************************************************************************************************************
 * Csm_Prv_IsInitialized
 *
 * \brief  The function returns the global init state of the component.
 *
 * \return boolean     Init state: TRUE, FALSE
 ***********************************************************************************************************************
*/
LOCAL_INLINE boolean Csm_Prv_IsInitialized(void)
{
    return (Csm_Initialized_b);
}

/**
 **********************************************************************************************************************
 * Csm_Prv_IsJobIdInRange
 *
 * \brief check to enable prevention out-of-bounds access for job array
 *
 * \param[in]  jobId     id of the job
 * \return boolean       TRUE: Ok  FALSE: Not ok
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean Csm_Prv_IsJobIdInRange(uint32 jobId)
{
    return (jobId < CSM_CFG_JOB_COUNT);
}

/**
 **********************************************************************************************************************
 * Csm_Prv_IsJobStateOk
 *
 * \brief check if a job is in a state where it can be updated from application
 *
 * \param[in]  jobId     id of the job
 * \return boolean       TRUE: Ok  FALSE: Not ok
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean Csm_Prv_IsJobStateOk(uint32 jobId)
{
    return (((CRYPTO_JOBSTATE_IDLE == Csm_Prv_Jobs_ast[jobId].jobState) ||
             (CRYPTO_JOBSTATE_ACTIVE == Csm_Prv_Jobs_ast[jobId].jobState)) &&
            (FALSE != Csm_Prv_Jobs_ast[jobId].callbackFinished_b) &&
            (FALSE == Csm_Prv_Jobs_ast[jobId].jobCanceled_b));
}

/**
 **********************************************************************************************************************
 * Csm_Prv_IsJobServiceOk
 *
 * \brief check if a job service has the expected value
 *
 * \param[in]  jobId     id of the job
 * \param[in]  service   enum of the service
 * \return boolean       TRUE: Match  FALSE: Not match
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean Csm_Prv_IsJobServiceOk(uint32 jobId, Crypto_ServiceInfoType service)
{
    return (service == Csm_Prv_Jobs_ast[jobId].jobPrimitiveInfo->primitiveInfo->service);
}

/**
 **********************************************************************************************************************
 * Csm_Prv_IsKeyIdInRange
 *
 * \brief check to enable prevention out-of-bounds access for key mapping array
 *
 * \param[in]  keyId     id of the key
 * \return boolean       TRUE: Ok  FALSE: Not ok
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean Csm_Prv_IsKeyIdInRange(uint32 keyId)
{
    return (keyId < CSM_CFG_KEY_COUNT);
}

/**
 **********************************************************************************************************************
 * Csm_Prv_IsParamOk
 *
 * \brief validate output parameter pointer and length according SWS_Csm_91009 and SWS_Csm_91014
 *
 * \param[in] redirectionCfgBit     Redirection parameter to be checked
 * \param[in] paramPtr              Pointer to the input / output data
 * \param[in] paramLengthPtr        Length of the input / output data
 * \return boolean                  TRUE: Ok  FALSE: Not ok
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean Csm_Prv_IsParamOk(const uint8 redirectionCfgBit_cu8, const uint8* paramPtr_pcu8,
                                       const uint32* paramLengthPtr_pcu32)
{
    boolean result_b = FALSE;


    if (0U != redirectionCfgBit_cu8)
    {
         //TRACE[SWS_Csm_91014]
         /* additional to AUTOSAR: if parameter length pointer is set to NULL_PTR, no error is detected */
        if ((NULL_PTR == paramLengthPtr_pcu32) || (0U == *paramLengthPtr_pcu32))
        {
            result_b = TRUE;
        }
    }
    else if ((NULL_PTR != paramPtr_pcu8) && (NULL_PTR != paramLengthPtr_pcu32))
    {
        result_b = TRUE;
    }
    else
    {
        //parameters are not ok
    }


    return result_b;
}

/**
 **********************************************************************************************************************
 * Csm_Prv_Queue_IsEmptyAtPrioLevel
 *
 * \brief returns whether the FIFO at a prioirity level is empty in the Queue
 *
 * \param[in] queue_cpst      reference to the queue
 * \param[in] prioLevel_cu32  job's priority level
 *
 * \retval TRUE: FIFO is empty
 * \retval FALSE: FIFO is not empty
 *
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean Csm_Prv_Queue_IsEmptyAtPrioLevel(const Crypto_Queue_tst * const queue_cpst, const uint32 prioLevel_cu32)
{
    // local buffering needed, because the index variables are volatile
    uint32 writeIndex_u32 = queue_cpst->fifos_capst[prioLevel_cu32]->writeIndex_vu32;
    uint32 readIndex_u32 = queue_cpst->fifos_capst[prioLevel_cu32]->readIndex_vu32;


    // if both of the indexes are the same, then the FIFO is empty
    return ( writeIndex_u32 == readIndex_u32);
}

/**
 **********************************************************************************************************************
 * Csm_Prv_Queue_HighestPrioLevelWaiting
 *
 * \brief Returns the highest job priority in the queue
 *
 * \param[in] queue_cpst    reference to the queue
 *
 * \retval priority level of the job (if no job found ,then invalid prio value returned)
 *
 **********************************************************************************************************************
 */
LOCAL_INLINE uint32 Csm_Prv_Queue_HighestPrioLevelWaiting(const Crypto_Queue_tst * const queue_cpst)
{
    uint32 level_u32 = CRYPTO_INVALID_PRIO_LEVEL; // Init with invalid priority level
    uint32 i;


    for (i = queue_cpst->levels_cu32 - 1U; i != CRYPTO_INVALID_PRIO_LEVEL; --i)
    {
        if (!Csm_Prv_Queue_IsEmptyAtPrioLevel(queue_cpst,i))
        {
            level_u32 = i;
            break;
        }
    }


    return level_u32;
}

/**
 **********************************************************************************************************************
 * Csm_Prv_Queue_Add
 *
 * \brief check if FIFO full, insert request if possible
 *
 * \param[inout] queueref_pcst  Reference to the queue
 * \param[in] job_cpst          Reference to the job
 *
 * \retval Std_ReturnType  E_OK  request has been inserted
 *                         CRYPTO_E_BUSY  run request has not been inserted because FIFO is full
 *
 **********************************************************************************************************************
 */
LOCAL_INLINE Std_ReturnType Csm_Prv_Queue_Add(const Crypto_Queue_tst * const queue_cpst,
                                        Crypto_JobType * const job_cpst)
{
    Std_ReturnType result_en;
    const uint32 prioLevel_cu32 = job_cpst->jobInfo->jobPriority;
    Crypto_FIFO_tst * fifo_pst = queue_cpst->fifos_capst[prioLevel_cu32];
    uint32 nextWriteIndex_u32;


    //calculate next index
    nextWriteIndex_u32 = fifo_pst->writeIndex_vu32 + 1U;

    if(nextWriteIndex_u32 == fifo_pst->fifoSize_cu32)
    {
        nextWriteIndex_u32 = 0U;
    }
    // check if FIFO has room for a job
    if (nextWriteIndex_u32 != fifo_pst->readIndex_vu32)
    {
        // insert request
        fifo_pst->jobs_apst[fifo_pst->writeIndex_vu32] = job_cpst;
        fifo_pst->writeIndex_vu32 = nextWriteIndex_u32;    // update lastWritten in FIFO
        // request was placed
        result_en = E_OK;
    }
    else
    {
        //TRACE[SWS_Csm_00018] cannot insert the FIFO is full
        result_en = CRYPTO_E_BUSY;
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_Prv_Queue_Peek
 *
 * \brief returns JobInfo reference with highest prio without removing it from queue
 *
 * \param[in] queue_cpst    reference to the queue
 * \param[out] job_ppst     reference to the JobType reference
 *
 * \retval E_OK: request successful
 * \retval E_NOT_OK: request failed
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_Crypto_00030]
LOCAL_INLINE Std_ReturnType Csm_Prv_Queue_Peek(const Crypto_Queue_tst * const queue_cpst, Crypto_JobType** job_ppst)
{
    Std_ReturnType result_en;
    uint32 level_u32 = Csm_Prv_Queue_HighestPrioLevelWaiting(queue_cpst);
    Crypto_FIFO_tst * FIFO_tst;


    // check if job found on any prio levels
    if (CRYPTO_INVALID_PRIO_LEVEL == level_u32)
    {
        result_en = E_NOT_OK;
    }
    else
    {
        // return job found in highest prio level
        FIFO_tst = queue_cpst->fifos_capst[level_u32];
        *job_ppst = FIFO_tst->jobs_apst[FIFO_tst->readIndex_vu32];
        result_en = E_OK;
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_Prv_Queue_Remove
 *
 * \brief deletes job from a given FIFO level of the queue
 *
 * \param[in] queue_cpst         reference to the queue
 * \param[in] job_cpst           reference to the job
 *
 * \retval E_OK: request successful, queued job found and removed
 * \retval E_NOT_OK: request failed, job could not be removed
 *
 **********************************************************************************************************************
 */
LOCAL_INLINE Std_ReturnType Csm_Prv_Queue_Remove(const Crypto_Queue_tst * const queue_cpst, const Crypto_JobType* const job_cpst)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 prioLevel_cu32 = job_cpst->jobInfo->jobPriority;
    Crypto_FIFO_tst * fifo_pst = queue_cpst->fifos_capst[prioLevel_cu32];


    // check if FIFO has the job at the first position
    if ((FALSE == Csm_Prv_Queue_IsEmptyAtPrioLevel(queue_cpst, prioLevel_cu32)) &&
        (fifo_pst->jobs_apst[fifo_pst->readIndex_vu32] == job_cpst))
    {
        // remove first element from the FIFO
        // calculate next index
        fifo_pst->readIndex_vu32 = fifo_pst->readIndex_vu32 + 1U;

        if(fifo_pst->readIndex_vu32 == fifo_pst->fifoSize_cu32)
        {
            fifo_pst->readIndex_vu32 = 0U;
        }
        result_en = E_OK;
    }


    return result_en;
}

/**
 **********************************************************************************************************************
 * Csm_Prv_InitQueues
 *
 * \param[in] Csm_QueueRefs_apst         reference to the queuerefs array
 * \param[in] Csm_QueueRefsLength_u32    length of the queuerefs array
 *
 * \brief init all queues states
 *
 *
 **********************************************************************************************************************
 */
LOCAL_INLINE void Csm_Prv_InitQueues(const Crypto_Queue_tst* const* Csm_QueueRefs_apst,
                                                 const uint32 Csm_QueueRefsLength_u32)
{
    uint32_least i;
    uint32_least j;
    uint32_least k;


    // init all job queues
    for (i = 0U; i < Csm_QueueRefsLength_u32; ++i)
    {
        //TRACE[SWS_Crypto_00179]
        // check if reference has a queue
        if (NULL_PTR != Csm_QueueRefs_apst[i])
        {
            for (j = 0U; j < Csm_QueueRefs_apst[i]->levels_cu32; ++j)
            {
                Csm_QueueRefs_apst[i]->fifos_capst[j]->writeIndex_vu32 = 0U;
                Csm_QueueRefs_apst[i]->fifos_capst[j]->readIndex_vu32 = 0U;

                for (k = 0U; k < Csm_QueueRefs_apst[i]->fifos_capst[j]->fifoSize_cu32; ++k)
                {
                    Csm_QueueRefs_apst[i]->fifos_capst[j]->jobs_apst[k] = NULL_PTR;
                }
            }
        }
    }
}

/***********************************************************************************************************************
 * Csm_Prv_IsJobPriorityHigh
 *
 * \brief Check if the job has higher as any waiting job in the queue
 *
 * \param[in]    const Crypto_Queue_tst * const queue_cpst  Holds the reference of the queue
 * \param[in]    Crypto_JobType* job_pst                     Holds the reference of the Crypto Job.
 *
 * \return boolean:
 *         - FALSE: Queue has higher prio job waiting
 *         - TRUE: Requested job has the highest priority
 *
 **********************************************************************************************************************/
LOCAL_INLINE boolean Csm_Prv_IsJobPriorityHigh(const Crypto_Queue_tst * const queue_cpst, const Crypto_JobType* job_pst)
{
    boolean result_b = TRUE;
    uint32 prioLevel_u32;


    // get highest priority level where waiting job found
    prioLevel_u32 = Csm_Prv_Queue_HighestPrioLevelWaiting(queue_cpst);

    // check if priority is valid and higher than the job
    if ((CRYPTO_INVALID_PRIO_LEVEL != prioLevel_u32) &&
        (job_pst->jobInfo->jobPriority <= prioLevel_u32))
    {
      result_b = FALSE;
    }


    return result_b;
}

/***********************************************************************************************************************
 * Csm_Prv_EnqueueAndUpdateJob
 *
 * \brief Try to put the job into the queue, on success update its state
 *
 * \param[in]    const Crypto_Queue_tst * const queue_cpst  Holds the reference of the queue
 * \param[in]    Crypto_JobType* job_pst        Holds the reference of the Crypto Job.
 *
 * \return Std_ReturnType:
 *         - E_OK: Request Successful, job put into the queue
 *         - CRYPTO_E_BUSY: Queue is full
 *
 **********************************************************************************************************************/
LOCAL_INLINE Std_ReturnType Csm_Prv_EnqueueAndUpdateJob(const Crypto_Queue_tst * const queue_cpst, Crypto_JobType* job_pst)
{
    Std_ReturnType result_en;


    // try to queue up the job
    result_en = Csm_Prv_Queue_Add(queue_cpst, job_pst);

    // if job is queued then set its status to waiting
    if (E_OK == result_en)
    {
        //TRACE[SWS_Csm_00016] TRACE[SWS_Csm_Rb_04928]
        // switch job state to block further requests
        job_pst->jobState = CRYPTO_JOBSTATE_WAITING;
    }


    return result_en;
}

#endif /* CSM_PRV_H */

