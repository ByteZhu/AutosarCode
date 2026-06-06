
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
#if (defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

#include "MemIf_Types.h"
#include "Fee_Cfg_SchM.h"
#include "Fee_Prv_Config.h"
#include "Fee_Prv_Lib.h"
#include "Fee_Prv_FsIf.h"
#include "Fee_Prv_Job.h"
#include "Fee_PrvTypes.h"
#include "Fee_Prv_Config.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
 */

/**
 * \brief   Try to place an order in the internal job slot.
 *          Based on block configuration the right job slot is chosen.
 *          If the Fee is not ready or the job slot is occupied E_NOT_OK is returned.
 *
 * \param   deviceName_en       Device instance for which job has to be performed
 * \param   apiId_u8            The ID of the API which places the job
 * \param   jobDesc_pcst        The order that shall be placed
 *
 * \return  E_OK                Order placed successfully
 * \return  E_NOT_OK            Order could not be placed
 */
Std_ReturnType Fee_Prv_JobPut(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, Fee_Prv_JobDesc_tst const * jobDesc_pcst)
{
    Std_ReturnType              result_en       = E_NOT_OK;
    Fee_Prv_ConfigRequester_ten requester_en;

    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst  const* blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    /* Get the pointer to config data model */
    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
    Fee_Prv_Job_tst *                    job_pst                = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;
    Fee_Prv_JobChunkInfo_tst *           chunkInfo_pst          = &deviceConfigTable_pcst->feeData_pst->jobData_st.chunkInfo_st;;

    /* Select the requester based on the type of the job. */
    if((FEE_RB_JOBTYPE_TRIGGERREORG_E == jobDesc_pcst->type_en) || (FEE_RB_JOBTYPE_STOP_MODE_E == jobDesc_pcst->type_en))
    {
        /* This is not a block related job, mark all such jobs as Adapter jobs */
        requester_en = FEE_PRV_REQUESTER_ADAPTER_E;
    }
    else if(jobDesc_pcst->isChunkJob_b)
    {
        /* Chunk-wise job operations also have their own slot/requester */
        requester_en = FEE_PRV_REQUESTER_CHUNK_E;
    }
    else
    {
        /* Check block configuration to find out who is the user */
        requester_en = Fee_Prv_ConfigGetBlockRequesterByBlockNr(jobDesc_pcst->blockNumber_u16, blockPropertiesTable_past);
    }

    SchM_Enter_Fee_Order();
    /*
     * Make sure the job slot is free.
     * A spin lock is needed since the main function might want to finish a job asynchronous.
     */
    if(    (FEE_RB_JOBTYPE_MAX_E             == job_pst->jobs_ast[requester_en].type_en)
        || (FEE_RB_JOBTYPE_WAIT_NEXT_CHUNK_E == job_pst->jobs_ast[requester_en].type_en) )
    {
        /* Reset last chunk(-wise job) results */
        if(FEE_PRV_REQUESTER_CHUNK_E == requester_en)
        {
            chunkInfo_pst->nrBytProc_u32 = 0uL;
            chunkInfo_pst->result_en     = FEE_RB_CHUNK_PENDING_E;
        }

        /* Set job and result of the current job */
        job_pst->jobs_ast   [requester_en] = *jobDesc_pcst;
        job_pst->results_aen[requester_en] = MEMIF_JOB_PENDING;

        result_en = E_OK;
    }
    SchM_Exit_Fee_Order();

    /*
     * In case placing the order did not work trigger Det error.
     * Do not do this for internal orders.
     * Do not do this under interrupt lock!
     */
    if(E_NOT_OK == result_en)
    {
        switch(requester_en)
        {
            case FEE_PRV_REQUESTER_NVM_E:     Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_BUSY         ); break;
            case FEE_PRV_REQUESTER_ADAPTER_E:
            case FEE_PRV_REQUESTER_CHUNK_E:   Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_BUSY_INTERNAL); break;
            default:                            /* Not DET report for internal orders */                          break;
        }
    }

    return(result_en);
}

/**
 * \brief   Called by the main function if it wants to begin an order.
 *          NvM orders have priority over normal adapter orders.
 *          If a stop mode or a trigger reorg request is pending, this request gets prioritized over all normal jobs.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which the next job has to searched and returned.
 *
 * \return  The next job that shall be started.
 */
Fee_Prv_JobDesc_tst * Fee_Prv_JobNext(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    uint32                  idxRequesterLoop_u32;
    Fee_Prv_JobDesc_tst *   result_pst = NULL_PTR;
    uint32                  idxRequesterNextJob_u32 = (uint32)FEE_PRV_REQUESTER_MAX_E;
    Fee_Prv_Job_tst *       job_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    for(idxRequesterLoop_u32 = (uint32)FEE_PRV_REQUESTER_NVM_E;
        (idxRequesterLoop_u32 < (uint32)FEE_PRV_REQUESTER_MAX_E);
        idxRequesterLoop_u32++ )
    {
        if(FEE_RB_JOBTYPE_MAX_E != job_pst->jobs_ast[idxRequesterLoop_u32].type_en)
        {
            /* The requester index for the next job to be processed will be set:
             * - if a job in the current user slot available but no job of a higher priority slot already selected
             * - if stop mode shall be entered or a reorg shall be triggered (may overwrite an already selected block oriented job)
             */
            if(((uint32)FEE_PRV_REQUESTER_MAX_E   == idxRequesterNextJob_u32) ||
               (FEE_RB_JOBTYPE_STOP_MODE_E == job_pst->jobs_ast[idxRequesterLoop_u32].type_en) ||
               (FEE_RB_JOBTYPE_TRIGGERREORG_E    == job_pst->jobs_ast[idxRequesterLoop_u32].type_en))
            {
                idxRequesterNextJob_u32 = idxRequesterLoop_u32;
            }
        }
    }

    /* If a new job is available return the pointer to the appropriate job decriptor */
    if((uint32)FEE_PRV_REQUESTER_MAX_E != idxRequesterNextJob_u32)
    {
        /* Begin job under interrupt lock since at the same time an external requester might modify the job. */
        SchM_Enter_Fee_Order();
        result_pst = &job_pst->jobs_ast[idxRequesterNextJob_u32];
        SchM_Exit_Fee_Order();
    }

    return(result_pst);
}

/**
 * \brief   Called by the main function if it wants to finish a job.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which the job has to be finished.
 * \param   result_en                Result of that job
 * \param   chunkInfo_pcst           Pointer to status of chunk-wise job
 */
void Fee_Prv_JobEnd(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, MemIf_JobResultType result_en, Fee_Prv_JobChunkInfo_tst const * chunkInfo_pcst)
{
    Fee_Prv_ConfigRequester_ten requester_en;
    Fee_Prv_JobDesc_tst *       jobDesc_pst = deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.currentExtJob_pst;
    Fee_Prv_Job_tst *           job_pst     = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    /* get the block pointer to the block properties table for the validaiton checks */
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past =
                                            Fee_Prv_FsIfGetBlockPropertiesTable(deviceConfigTable_pcst->deviceName_en);

    /* Select the requester based on the type of the job. */
    if((FEE_RB_JOBTYPE_TRIGGERREORG_E == jobDesc_pst->type_en) || (FEE_RB_JOBTYPE_STOP_MODE_E == jobDesc_pst->type_en))
    {
        /* This is not a block related job, mark all such jobs as Adapter jobs */
        requester_en = FEE_PRV_REQUESTER_ADAPTER_E;
    }
    else if(jobDesc_pst->isChunkJob_b)
    {
        /* Chunk-wise job operations also have their own slot/requester */
        requester_en = FEE_PRV_REQUESTER_CHUNK_E;
    }
    else
    {
        /* Check block configuration to find out who is the user */
        requester_en = Fee_Prv_ConfigGetBlockRequesterByBlockNr(jobDesc_pst->blockNumber_u16, blockPropertiesTable_past);
    }

    /* Finish job under spin lock */
    SchM_Enter_Fee_Order();

    if(FEE_PRV_REQUESTER_CHUNK_E == requester_en)
    {
        /* For a completed chunk-wise job, update its status (i.e. result and number of processed bytes) */
        deviceConfigTable_pcst->feeData_pst->jobData_st.chunkInfo_st = *chunkInfo_pcst;
    }
    else
    {
        /* Keep deviceConfigTable_pcst->feeData_pst->jobData_st.chunkInfo_st as is */
    }

    job_pst->results_aen[requester_en] = result_en;

    jobDesc_pst->cntrBytDone_u16 = jobDesc_pst->nrBytTot_u16;
    jobDesc_pst->type_en         = FEE_RB_JOBTYPE_MAX_E;

    SchM_Exit_Fee_Order();

    return;
}

# if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS))
/**
 * \brief   Called by the main function if a chunk is done, but the chunk-wise job is incomplete.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which the job has to be finished.
 * \param   chunkInfo_pcst           Pointer to status of chunk-wise job
 */
void Fee_Prv_JobChunkEnd(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, Fee_Prv_JobChunkInfo_tst const * chunkInfo_pcst)
{
    Fee_Prv_JobDesc_tst *         jobDesc_pst   =  deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.currentExtJob_pst;
    Fee_Prv_JobChunkInfo_tst *    chunkInfo_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st.chunkInfo_st;

    /* Finish chunk under spin lock */
    SchM_Enter_Fee_Order();

    *chunkInfo_pst = *chunkInfo_pcst;

    jobDesc_pst->cntrBytDone_u16 += jobDesc_pst->length_u16;
    jobDesc_pst->type_en          = FEE_RB_JOBTYPE_WAIT_NEXT_CHUNK_E;

    SchM_Exit_Fee_Order();

    return;
}

/**
 * \brief   Returns the result of the current/last chunk(-wise job)
 *
 * \param   deviceName_en  Device instance, for which the result has to be returned
 *
 * \return  Result of the current/last chunk(-wise job)
 * \retval  FEE_RB_CHUNK_ALL_OK_E      Processing of all chunks has succeeded, complete chunk-wise job is done
 * \retval  FEE_RB_CHUNK_PART_OK_E     Processing of last chunk has succeeded, ready for next chunk
 * \retval  FEE_RB_CHUNK_FAILED_E      Processing of chunk-wise job has failed
 * \retval  FEE_RB_CHUNK_PENDING_E     Processing of last/current chunk hasn't finished yet
 * \retval  FEE_RB_CHUNK_TERMINATED_E  Processing of chunk-wise job has been terminated by the user
*/
Fee_Rb_ChunkResult_ten Fee_Prv_JobGetChunkResult(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Get the pointer to config data model */
    Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

    /* Return result of the current/last chunk(-wise job) */
    return(deviceConfigTable_pcst->feeData_pst->jobData_st.chunkInfo_st.result_en);
}

/**
 * \brief   Returns the number of bytes that have been processed in the current/last chunk
 *
 * \param   deviceName_en  Device instance, for which number of bytes has to be returned
 *
 * \return  Number of bytes that have been processed in the current/last chunk
*/
uint32 Fee_Prv_JobGetChunkNrBytProc(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Get the pointer to config data model */
    Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

    /* Return number of bytes that have been processed in the current/last chunk */
    return(deviceConfigTable_pcst->feeData_pst->jobData_st.chunkInfo_st.nrBytProc_u32);
}

/**
 * \brief   Returns the job which is currently active in the job slot of the given requester.
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table for which the currently active job slot has to be returned.
 * \param   requester_en            Select the job slot to be checked (NvM, Adapter, Debug, Chunk)
 *
 * \return  Pointer to job which is currently active
 */
Fee_Prv_JobDesc_tst const * Fee_Prv_JobGetActv(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, Fee_Prv_ConfigRequester_ten requester_en)
{
    Fee_Prv_JobDesc_tst const * activeJob_pcst;

    Fee_Prv_Job_tst * job_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    activeJob_pcst = &(job_pst->jobs_ast[requester_en]);

    return(activeJob_pcst);
}
# endif

/**
 * \brief   Returns the job type which is currently active in the job slot of the given requester.
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table for which the currently active job slot has to be returned.
 * \param   requester_en            Select the job slot to be checked (NvM, Adapter, Debug, Chunk)
 *
 * \return  Job type which is currently active
 */
Fee_Rb_JobType_ten Fee_Prv_JobGetActvType(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, Fee_Prv_ConfigRequester_ten requester_en)
{
    Fee_Rb_JobType_ten activeJobType_en;

    Fee_Prv_Job_tst * job_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    activeJobType_en = job_pst->jobs_ast[requester_en].type_en;

    return(activeJobType_en);
}

/**
 * \brief   Returns the result of the job for the given requester.
 *
 * \param   deviceName_en               Device instance for which job result has to be returned
 * \param   requester_en                Select the job slot to be checked (NvM, Adapter, Debug, Chunk)
 *
 * \return  MEMIF_JOB_OK                Last job executed successfully
 * \return  MEMIF_JOB_FAILED            Last job failed unexpected
 * \return  MEMIF_JOB_PENDING           Last job is still running
 * \return  MEMIF_BLOCK_INCONSISTENT    Last job was a read and
 *                                      a) Not a single instance of all instances has consistent data
 *                                      b) The block is not present at all
 * \return  MEMIF_BLOCK_INVALIDATED     Last job was a read and the block was invalidated intentionally
 *
 * \attention   Since the job result can change asynchronously a time consuming spin lock is needed!
 *              Please consider this when creating do/while wait loops for the Fee.
 */
MemIf_JobResultType Fee_Prv_JobGetResult(Fee_Rb_DeviceName_ten deviceName_en, Fee_Prv_ConfigRequester_ten requester_en)
{
    MemIf_JobResultType result_en;

    /* Get the pointer to config data model */
    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
    Fee_Prv_Job_tst                      job_st                 = deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    /* According to the prerequisites that RTA-BSW has to run on >= 32 bit controllers and data are always aligned,
     * atomic access is guaranteed by the hardware for 32 bit memory access
     */
    result_en = job_st.results_aen[requester_en];

    return(result_en);
}

# if(FALSE != FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE)
/* \brief   Return the current job mode for the passed job
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table for which the driver mode has to be set
 * \param   jobType_en              Job type for which mode has to be set
 *
 * \return
 *          jobMode_en      Currently active mode for the passed job type
 */
Fee_Rb_JobMode_ten Fee_Prv_JobGetJobMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, Fee_Rb_JobType_ten jobType_en)
{
    Fee_Rb_JobMode_ten jobMode_en;
    Fee_Prv_Job_tst* job_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    jobMode_en = job_pst->jobMode_en[jobType_en];

    return(jobMode_en);
}

/* \brief   Store the requested job mode for the passed job
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table for which the driver mode has to be set
 * \param   jobType_en              Job type for which mode has to be set
 * \param   jobMode_en              Mode that is requested to be set for the passed job type
 */
void Fee_Prv_JobSetJobMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, Fee_Rb_JobType_ten jobType_en, Fee_Rb_JobMode_ten jobMode_en)
{
    Fee_Prv_Job_tst* job_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    job_pst->jobMode_en[jobType_en] = jobMode_en;

    return;
}
# endif

# if(STD_ON == FEE_PRV_CFG_SET_MODE_SUPPORTED)
/**
 * \brief   Set the modes of all the jobs based on the passed driver mode
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table for which the driver mode has to be set
 * \param   mode                    Driver mode
 */
void Fee_Prv_JobSetModesBasedOnDriverMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, MemIf_ModeType mode)
{
    uint8            i_u8;
    Fee_Prv_Job_tst* job_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st.job_st;

    /* Set the modes for each of the job types */
    if (MEMIF_MODE_SLOW == mode)
    {
        /* Set all the jobs to the default mode */
        for(i_u8 = 0; i_u8 < (uint8)FEE_RB_JOBTYPE_MAX_E; i_u8++)
        {
            job_pst->jobMode_en[i_u8] = FEE_RB_ALLJOBS_ALLSTEPS_E;
        }
    }
    else
    {
        /* It could be possible that the job modes are different for different file system (due to some modes not yet
         * supported in the file system or customer requirement). So get the mode to be set from the respective file system  */
        for(i_u8 = 0; i_u8 < (uint8)FEE_RB_JOBTYPE_MAX_E; i_u8++)
        {
            /* MR12 RULE 10.5 VIOLATION: cast from unsigned to enum is safe */
            job_pst->jobMode_en[i_u8] = Fee_Prv_FsIfGetJobModeForFastDriverMode(deviceConfigTable_pcst, (Fee_Rb_JobType_ten)i_u8);
        }
    }

    return;
}
# endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif
