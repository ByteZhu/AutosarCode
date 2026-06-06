
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if (defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

#include "Fee_Cfg_SchM.h"
#include "Fee_Rb_Types.h"
#include "Fee_Cfg.h"
#include "Fee_Rb_Idx.h"
#include "Fee_Prv_Chunk.h"
#include "Fee_Prv_Dbg.h"
#include "Fee_Prv_FsIf.h"
#include "Fee_Prv_Job.h"
#include "Fee_Prv_Lib.h"
#include "Fee_Prv_Order.h"
#include "Fee_Prv_Config.h"
#include "Fee_Prv_Proc.h"

# if (STD_ON == FEE_PRV_CFG_DEV_ERROR_DETECT)
#include "Det.h"
# endif

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/* Protection selectable via Fee_Cfg_SchM.h to save code */
# ifndef FEE_RB_USE_PROTECTION
#define FEE_RB_USE_PROTECTION   (TRUE)
# endif

# if(!defined(FEE_PRV_CFG_RB_CHUNK_JOBS) || (FALSE == FEE_PRV_CFG_RB_CHUNK_JOBS))
#define Fee_Prv_ProcChunkReadDo(deviceConfigTable_pcst)    Fee_Prv_FsIfReadDo(deviceConfigTable_pcst)
# endif

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
*/

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

LOCAL_INLINE void Fee_Prv_ProcMainFunctionIntern(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
LOCAL_INLINE void Fee_Prv_ProcStartExtJob(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
LOCAL_INLINE void Fee_Prv_ProcProcessIdle(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
LOCAL_INLINE void Fee_Prv_ProcProcessBackground(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
# if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS))
LOCAL_INLINE MemIf_JobResultType Fee_Prv_ProcChunkReadDo(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
LOCAL_INLINE boolean Fee_Prv_ProcIsJobDone(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, MemIf_JobResultType result_en, Fee_Prv_JobChunkInfo_tst * chunkInfo_pst);
# endif
LOCAL_INLINE void Fee_Prv_ProcProcessExtJob(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
LOCAL_INLINE Fee_Rb_WorkingStateType_ten Fee_Prv_ProcCalcWorkingState(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
LOCAL_INLINE boolean Fee_Prv_ProcTryToGetLock(Fee_Rb_DeviceName_ten deviceName_en, Fee_Prv_ProcLock_tst * procLock_pst);
LOCAL_INLINE void Fee_Prv_ProcReleaseLock(Fee_Prv_ProcLock_tst * procLock_pst);
LOCAL_INLINE MemIf_JobResultType Fee_Prv_ProcEnterStopModeDo(Fee_Prv_Proc_tst * proc_pst);

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
 */

/*
 * \brief   Disables execution of background operations.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which the background has to be disabled.
 */
void Fee_Prv_ProcDisableBackground(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    Fee_Prv_Proc_tst* proc_pst = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    proc_pst->backgroundState_en = FEE_PRV_PROC_BACKGROUNDSTATE_DISABLED;

    return;
}

/*
 * \brief   Enables execution of background operations.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which the background has to be enabled.
 */
void Fee_Prv_ProcEnableBackground(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    Fee_Prv_Proc_tst* proc_pst = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    proc_pst->backgroundState_en = FEE_PRV_PROC_BACKGROUNDSTATE_ENABLED_ACTIVE;

    return;
}

/*
 * \brief   Set the state of the driver.
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table for which the background has to be enabled.
 * \param   driverState_en          The state which shall be entered
 */
void Fee_Prv_ProcSetDriverState(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, Fee_Prv_ProcDriverState_ten driverState_en)
{
    deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.driverState_en = driverState_en;

    return;
}

/*
 * \brief   Return the current state of the driver.
 *
 * \param   deviceName_en   Device instance for which the driver state has to be returned
 *
 * \return  Current state of the driver
 */
Fee_Prv_ProcDriverState_ten Fee_Prv_ProcGetDriverState(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Get the pointer to config data model */
    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
    Fee_Prv_Proc_tst*                    proc_pst               = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    return(proc_pst->driverState_en);
}

/* \brief   Return the current driver execution mode
 *
 * \param   deviceName_en   Device instance for which the driver mode has to be returned
 *
 * \return  MEMIF_MODE_SLOW: Driver executes in slow mode
 * \return  MEMIF_MODE_FAST: Driver executes in fast mode
 */
MemIf_ModeType Fee_Prv_ProcGetDriverMode(Fee_Rb_DeviceName_ten deviceName_en)
{
    MemIf_ModeType retVal_en;
    /* Get the pointer to config data model */
    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
    Fee_Prv_Proc_tst*                    proc_pst               = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    /* According to the prerequisites that RTA-BSW has to run on >= 32 bit controllers and data are always aligned,
     * atomic access is guaranteed by the hardware for 32 bit memory access
     */
    retVal_en = proc_pst->driverModeActv_en;

   return(retVal_en);
}

# if(STD_ON == FEE_PRV_CFG_SET_MODE_SUPPORTED)
/**
 * \brief   Set the mode of the Fee and the underlying flash driver
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table for which the driver mode has to be set
 * \param   mode                    requested mode to set
 */
void Fee_Prv_ProcSetDriverMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, MemIf_ModeType mode)
{
    Fls_Rb_FlsDevice_ten flsDeviceId_en = Fls_Rb_GetDeviceIdFromDrvIndex(deviceConfigTable_pcst->deviceIdx_u8);
    Fee_Prv_Proc_tst*    proc_pst       = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    Fee_Prv_Lib_Fls_SetMode(flsDeviceId_en, mode);

    /* According to the prerequisites that RTA-BSW has to run on >= 32 bit controllers and data are always aligned,
     * atomic access is guaranteed by the hardware for 32 bit memory access
     */
    proc_pst->driverModeActv_en = mode;

    /* Set the modes for each of the job types */
    Fee_Prv_JobSetModesBasedOnDriverMode(deviceConfigTable_pcst, mode);

    return;
}

#  if (FEE_PRV_CFG_AR_RELEASE_MAJOR_VERSION == 4) && (FEE_PRV_CFG_AR_RELEASE_MINOR_VERSION >= 4)
/* \brief   Set the driver execution mode request
 *
 * \param deviceConfigTable_pcst   Pointer to the config table for which the driver mode has to be set
 * \param driverModeReq_en        MEMIF_MODE_SLOW: Driver executes in slow mode
 *                                MEMIF_MODE_FAST: Driver executes in fast mode
 */
void Fee_Prv_ProcSetDriverModeReq(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, MemIf_ModeType driverModeReq_en)
{
    /* According to the prerequisites that RTA-BSW has to run on >= 32 bit controllers and data are always aligned,
     * atomic access is guaranteed by the hardware for 32 bit memory access
     */
    Fee_Prv_Proc_tst* proc_pst = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    proc_pst->driverModeReqd_en = driverModeReq_en;

    return;
}
#  endif

# endif

/*
 * \brief   Returns the current Fee working state.
 *
 * \param deviceConfigTable_pcst   Pointer to the config table for which the working set has to be returned
 *
 * \return  Current working state of the driver
 */
Fee_Rb_WorkingStateType_ten Fee_Prv_ProcGetWorkingState(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst)
{
    Fee_Prv_ProcData_tst * procData_pst = &deviceConfigTable_pcst->feeData_pst->procData_st;

    return(procData_pst->procWorkingState_en);
}

/*
 * \brief   Activates the stop mode.
 *
 * \param   proc_pst   Pointer to the common variables of the proc unit
 */
LOCAL_INLINE MemIf_JobResultType Fee_Prv_ProcEnterStopModeDo(Fee_Prv_Proc_tst * proc_pst)
{
    proc_pst->stopModeActive_b = TRUE;

    return(MEMIF_JOB_OK);
}

/*
 * \brief   Check if the stop mode is activated for given Fee device instance.
 *
 * \param   deviceName_en    Device instance for which check has to be performed
 * \return  Returns true if stop mode is activated
 */
boolean Fee_Prv_ProcIsStopModeActive(Fee_Rb_DeviceName_ten deviceName_en)
{
    return Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en)->feeData_pst->procData_st.proc_st.stopModeActive_b;
}

/*
 * \brief   Starts the job requested from the job unit by triggering the filesystem specific handler function.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table, for which the job has to be started
 */
LOCAL_INLINE void Fee_Prv_ProcStartExtJob(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    Fee_Prv_JobDesc_tst const * newExtJob_pcst = deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.currentExtJob_pst;

    /* Check pending order type */
    switch(newExtJob_pcst->type_en)
    {
        case FEE_RB_JOBTYPE_READ_E:              Fee_Prv_FsIfRead(deviceConfigTable_pcst);              break;
        case FEE_RB_JOBTYPE_WRITE_E:             Fee_Prv_FsIfWrite(deviceConfigTable_pcst);             break;
        case FEE_RB_JOBTYPE_INVALIDATE_E:        Fee_Prv_FsIfInvalidateBlock(deviceConfigTable_pcst);   break;
        case FEE_RB_JOBTYPE_BLOCKMAINTENANCE_E:  Fee_Prv_FsIfRbMaintainBlock(deviceConfigTable_pcst);   break;
        case FEE_RB_JOBTYPE_TRIGGERREORG_E:      Fee_Prv_FsIfRbTriggerReorg(deviceConfigTable_pcst);    break;
        case FEE_RB_JOBTYPE_STOP_MODE_E:
        default:                                 /* Do nothing */                                       break;
    }

    return;
}

# if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS))
/*
 * \brief   Processes an ongoing (chunk-wise) read job.
 *          If the chunk-wise read has been waiting for the next chunk, the job is restarted to process it afterwards.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table, for which the job status has to be processed
 *
 * \return  Job result
 */
LOCAL_INLINE MemIf_JobResultType Fee_Prv_ProcChunkReadDo(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    /* Return variable */
    MemIf_JobResultType    result_en;

    /* Local variable */
    boolean *   isWaitForNextChunk_pb = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.isWaitForNextChunk_b;

    /* Waiting for next chunk? */
    if(*isWaitForNextChunk_pb)
    {
        /* If we have received the next chunk, restart job */
        *isWaitForNextChunk_pb = FALSE;
        Fee_Prv_FsIfRead(deviceConfigTable_pcst);
        result_en = MEMIF_JOB_PENDING;
    }
    else
    {
        result_en = Fee_Prv_FsIfReadDo(deviceConfigTable_pcst);
    }

    return(result_en);
}

/*
 * \brief   Checks if a (chunk-wise) job is done
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table, for which the job has to be checked
 * \param   result_en                Job result
 * \param   chunkInfo_pst            Pointer to status of chunk-wise job
 *
 * \return  Job done status
 * \retval  TRUE   if job is done (in case of a chunk-wise job, this means all chunks are done)
 * \retval  FALSE  otherwise
 */
LOCAL_INLINE boolean Fee_Prv_ProcIsJobDone(
        Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst,
        MemIf_JobResultType result_en,
        Fee_Prv_JobChunkInfo_tst * chunkInfo_pst)
{
    /* Return variable */
    boolean    isDone_b;

    /* Local variable */
    Fee_Prv_Proc_tst *    proc_pst = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    /* Chunk-wise job? */
    if(proc_pst->currentExtJob_pst->isChunkJob_b)
    {
        /* Callback into chunk-unit */
        Fee_Prv_ChunkDoneCbk(deviceConfigTable_pcst->deviceName_en, proc_pst->currentExtJob_pst, result_en, chunkInfo_pst);

        /* Current chunk is done? */
        if(FEE_RB_CHUNK_PART_OK_E == chunkInfo_pst->result_en)
        {
            /* Update status of chunk-wise job, and wait for next chunk */
            Fee_Prv_JobChunkEnd(deviceConfigTable_pcst, chunkInfo_pst);
            proc_pst->isWaitForNextChunk_b = TRUE;
            isDone_b = FALSE;
        }
        else
        {
            /* Chunk-wise job is done */
            proc_pst->isWaitForNextChunk_b = FALSE;
            isDone_b = TRUE;
        }
    }
    else
    {
        /* Normal job is done */
        isDone_b = TRUE;
    }

    return(isDone_b);
}
# endif

/*
 * \brief   Processes the current external job based on the selected job descriptor.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table, for which the job has to be processed
 */
LOCAL_INLINE void Fee_Prv_ProcProcessExtJob(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    MemIf_JobResultType         result_en;
    /* Zero-initialization required to avoid MISRA C:2012 Rule 9.1 warning for call of Fee_Prv_JobEnd: "Passing
     * address of uninitialized object 'chunkInfo_st' to a function parameter declared as a pointer to const."  */
    Fee_Prv_JobChunkInfo_tst    chunkInfo_st = {0, FEE_RB_CHUNK_ALL_OK_E};
    Fee_Prv_Proc_tst *          proc_pst     = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    switch(proc_pst->currentExtJob_pst->type_en)
    {
        case FEE_RB_JOBTYPE_READ_E:             result_en = Fee_Prv_ProcChunkReadDo(deviceConfigTable_pcst);       break;
        case FEE_RB_JOBTYPE_WRITE_E:            result_en = Fee_Prv_FsIfWriteDo(deviceConfigTable_pcst);           break;
        case FEE_RB_JOBTYPE_INVALIDATE_E:       result_en = Fee_Prv_FsIfInvalidateBlockDo(deviceConfigTable_pcst); break;
        case FEE_RB_JOBTYPE_BLOCKMAINTENANCE_E: result_en = Fee_Prv_FsIfRbMaintainBlockDo(deviceConfigTable_pcst); break;
        case FEE_RB_JOBTYPE_TRIGGERREORG_E:     result_en = Fee_Prv_FsIfRbTriggerReorgDo(deviceConfigTable_pcst);  break;
        case FEE_RB_JOBTYPE_STOP_MODE_E:        result_en = Fee_Prv_ProcEnterStopModeDo(proc_pst);                 break;

        case FEE_RB_JOBTYPE_WAIT_NEXT_CHUNK_E:  result_en = MEMIF_JOB_PENDING;                                     break;
        case FEE_RB_JOBTYPE_TERMINATE_CHUNK_E:  result_en = MEMIF_JOB_CANCELED;                                    break;
        default:                                result_en = MEMIF_JOB_FAILED;                                      break;
    }

    /* Job done? */
    if(MEMIF_JOB_PENDING != result_en)
    {
# if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS))
        /* A chunk-wise job is only done after all chunks have been processed; is this the case here? */
        if(Fee_Prv_ProcIsJobDone(deviceConfigTable_pcst, result_en, &chunkInfo_st))
# endif
        {
            /* Reset the environment after the job has been finished */
            proc_pst->driverState_en = FEE_PRV_PROC_DRIVERSTATE_IDLE_E;
            Fee_Prv_JobEnd(deviceConfigTable_pcst, result_en, &chunkInfo_st);
            proc_pst->currentExtJob_pst = NULL_PTR;

            /* Background enabled but sleeping? */
            if(FEE_PRV_PROC_BACKGROUNDSTATE_ENABLED_SLEEPING == proc_pst->backgroundState_en)
            {
                /* Activate background */
                proc_pst->backgroundState_en = FEE_PRV_PROC_BACKGROUNDSTATE_ENABLED_ACTIVE;
            }

            /* Using the function Fee_Prv_ConfigGetFSFromDeviceName() has the advantage
             * that it leads to code optimization when only one instance is used. */
            if(FEE_FS2 == Fee_Prv_ConfigGetFSFromDeviceName(deviceConfigTable_pcst->deviceName_en))
            {
                /* Wind up debounce counter for Fee2 */
                proc_pst->backgroundDebounceCntr_u16 = FEE_PRV_PROC_MFCALLS_BEFORE_BACKGROUND_ACTION;
            }
            else
            {
                /* For Fee1x (same as Fee1.0) and Fee3, there is no delay in background task execution */
                proc_pst->backgroundDebounceCntr_u16 = 0u;
            }
        }
    }

    return;
}

/*
 * \brief   Covers all actions to be done when the driver state is idle.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which main function has to called
 */
LOCAL_INLINE void Fee_Prv_ProcProcessIdle(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    MemIf_JobResultType result_en = MEMIF_JOB_PENDING;
    Fee_Prv_Proc_tst *  proc_pst  = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

# if (FEE_PRV_CFG_AR_RELEASE_MAJOR_VERSION == 4) && (FEE_PRV_CFG_AR_RELEASE_MINOR_VERSION >= 4) && (STD_ON == FEE_PRV_CFG_SET_MODE_SUPPORTED)
    /* From Autosar 4.4 and newer
     * Check if the user has requested a driver mode change
     * According to the prerequisites that RTA-BSW has to run on >= 32 bit controllers and data are always aligned,
     * atomic access is guaranteed by the hardware for 32 bit memory access
     */
    MemIf_ModeType      driverModeReqdLocal_en = proc_pst->driverModeReqd_en;

    if(proc_pst->driverModeActv_en != driverModeReqdLocal_en)
    {
        /* Change driver mode */
        Fee_Prv_ProcSetDriverMode(deviceConfigTable_pcst, driverModeReqdLocal_en);
    }
# endif
    /* Is a new user job available? */
    if(NULL_PTR != proc_pst->currentExtJob_pst)
    {
        /* Yes -> Start the job processing in the Fs and set the appropriate driver state */
        Fee_Prv_ProcStartExtJob(deviceConfigTable_pcst);
        proc_pst->driverState_en = FEE_PRV_PROC_DRIVERSTATE_EXT_JOB_E;
    }
    else
    {
        /* No -> Check whether any maintenance functions can be executed in the background */
        if(FEE_PRV_PROC_BACKGROUNDSTATE_ENABLED_ACTIVE == proc_pst->backgroundState_en)
        {
            /* Debouncing done? */
            if(0u == proc_pst->backgroundDebounceCntr_u16)
            {
                /* Call Fs-specific background function */
                result_en = Fee_Prv_FsIfBackground(deviceConfigTable_pcst);

                /* Fs-specific background function has already completed successfully? */
                if(MEMIF_JOB_OK == result_en)
                {
                    /* Put background operations back to sleep */
                    proc_pst->backgroundState_en = FEE_PRV_PROC_BACKGROUNDSTATE_ENABLED_SLEEPING;
                }
                /* Fs-specific background function not yet complete? */
                else if(MEMIF_JOB_PENDING == result_en)
                {
                    /* Continue the Fs-specific background processing */
                    proc_pst->driverState_en = FEE_PRV_PROC_DRIVERSTATE_BACKGROUND_E;
                }
                /* Fs-specific background function has failed? */
                else
                {
                    /* Do nothing */
                }
            }
            /* Debouncing not yet done? */
            else
            {
                /* Before starting a background action, debounce a little to ensure that it does not start immediately */
                proc_pst->backgroundDebounceCntr_u16--;
            }
        }
        else
        {
            /* FEE_PRV_BACKGROUNDSTATE_DISABLED / FEE_PRV_BACKGROUNDSTATE_ENABLED_SLEEPING : Do nothing */
        }
    }

    return;
}

/*
 * \brief   Covers all background actions.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which main function has to called
 */
LOCAL_INLINE void Fee_Prv_ProcProcessBackground(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    /* Return variable */
    MemIf_JobResultType result_en;
    Fee_Prv_Proc_tst * proc_pst = &deviceConfigTable_pcst->feeData_pst->procData_st.proc_st;

    /* Is a new job available or background operations just disabled and background cancel not yet started? */
    if(((NULL_PTR != proc_pst->currentExtJob_pst) || (FEE_PRV_PROC_BACKGROUNDSTATE_DISABLED == proc_pst->backgroundState_en)) &&
       (!proc_pst->backgroundCancelOngoing_b))
    {
        /* Cancel background activity */
        Fee_Prv_FsIfCancel(deviceConfigTable_pcst);
        proc_pst->backgroundCancelOngoing_b = TRUE;
    }

    /* Call Fs-specific background function */
    result_en = Fee_Prv_FsIfBackground(deviceConfigTable_pcst);

    if(MEMIF_JOB_PENDING != result_en)
    {
        proc_pst->backgroundCancelOngoing_b = FALSE;
        /* Background job is finished -> switch the driver state to idle */
        proc_pst->driverState_en = FEE_PRV_PROC_DRIVERSTATE_IDLE_E;
    }

    return;
}

/*
 * \brief   Calculates the current Fee working state.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which main function has to called
 *
 * \return  Returns the ongoing Fee activity.
 */
LOCAL_INLINE Fee_Rb_WorkingStateType_ten Fee_Prv_ProcCalcWorkingState(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    Fee_Rb_WorkingStateType_ten stRetVal_en;
    Fee_Prv_ProcDriverState_ten driverState_en     = deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.driverState_en;
    boolean                     stopModeActive_b   = deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.stopModeActive_b;
    Fee_Prv_JobDesc_tst const * currentExtJob_pcst = deviceConfigTable_pcst->feeData_pst->procData_st.proc_st.currentExtJob_pst;

    switch(driverState_en)
    {
        case FEE_PRV_PROC_DRIVERSTATE_UNINIT_E:
        case FEE_PRV_PROC_DRIVERSTATE_INIT_E:
        {
            stRetVal_en = FEE_RB_IDLE_E;

        }
        break;

        case FEE_PRV_PROC_DRIVERSTATE_IDLE_E:
        {
            if(stopModeActive_b)
            {
                stRetVal_en = FEE_RB_STOPMODE_E;
            }
            else
            {
                stRetVal_en = FEE_RB_IDLE_E;
            }
        }
        break;

        case FEE_PRV_PROC_DRIVERSTATE_BACKGROUND_E:
        {
            /* Check if background erase operation is ongoing */
            if(Fee_Prv_FsIfRbIsSectorEraseOngoing(deviceConfigTable_pcst))
            {
                stRetVal_en = FEE_RB_SECTOR_ERASE_E;
            }
            /* Check if background soft reorganisation operation is ongoing */
            else if (Fee_Prv_FsIfRbIsSoftReorgOngoing(deviceConfigTable_pcst))
            {
                stRetVal_en = FEE_RB_SOFT_SECTOR_REORG_MODE_E;
            }
            else
            {
                stRetVal_en = FEE_RB_IDLE_E;
            }
        }
        break;

        case FEE_PRV_PROC_DRIVERSTATE_EXT_JOB_E:
        {
            switch(currentExtJob_pcst->type_en)
            {
                case FEE_RB_JOBTYPE_READ_E:
                {
                    stRetVal_en = FEE_RB_READ_MODE_E;
                }
                break;

                case FEE_RB_JOBTYPE_STOP_MODE_E:
                {
                    stRetVal_en = FEE_RB_STOPMODE_E;
                }
                break;

                case FEE_RB_JOBTYPE_WRITE_E:
                case FEE_RB_JOBTYPE_INVALIDATE_E:
                case FEE_RB_JOBTYPE_BLOCKMAINTENANCE_E:
                case FEE_RB_JOBTYPE_TRIGGERREORG_E:
                default:
                {
                    /* Check for hard reorg, because this can happen during a write, invalidate or maintain job */
                    if(Fee_Prv_FsIfRbIsHardReorgOngoing(deviceConfigTable_pcst))
                    {
                        stRetVal_en = FEE_RB_HARD_SECTOR_REORG_MODE_E;
                    }
                    else if(Fee_Prv_FsIfRbIsSectorEraseOngoing(deviceConfigTable_pcst))
                    {
                        stRetVal_en = FEE_RB_SECTOR_ERASE_E;
                    }
                    else
                    {
                        switch(currentExtJob_pcst->type_en)
                        {
                            case FEE_RB_JOBTYPE_WRITE_E:
                            {
                                /* All FSx */
                                stRetVal_en = FEE_RB_WRITE_MODE_E;
                            }
                            break;

                            case FEE_RB_JOBTYPE_INVALIDATE_E:
                            {
                                /* All FSx */
                                stRetVal_en = FEE_RB_INVALIDATE_MODE_E;
                            }
                            break;

                            case FEE_RB_JOBTYPE_BLOCKMAINTENANCE_E:
                            {
                                /* FS1x + FS3 only */
                                stRetVal_en = FEE_RB_MAINTAIN_MODE_E;
                            }
                            break;

                            /* FEE_RB_JOBTYPE_TRIGGERREORG_E - Fs1x only */
                            default:
                            {
                                stRetVal_en = FEE_RB_IDLE_E;
                            }
                            break;
                        }
                    }
                }
                break;
            }
        }
        break;

        default:
        {
            stRetVal_en = FEE_RB_IDLE_E;
        }
        break;
    }

    return(stRetVal_en);
}

/*
 * \brief   The internal main function does the actual work of the Fee.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table for which main function has to called
 */
LOCAL_INLINE void Fee_Prv_ProcMainFunctionIntern(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    /*
     * Measure main function execution time.
     * Attention: The result is not the actual time the main function really needed since it can be interrupted.
     *            Nevertheless it is a good indicator for debugging purposes.
     */
    Fee_Prv_ProcData_tst * procData_pst = &deviceConfigTable_pcst->feeData_pst->procData_st;
    Fee_Prv_Proc_tst *     proc_pst     = &procData_pst->proc_st;

    /* avoid warning when debug feature is deactivated */
    Fee_Prv_DbgWatchStart(deviceConfigTable_pcst->deviceName_en, FEE_PRV_DBG_TIMER_PROCMAIN_E);

    /* Reset the effort limitation */
    Fee_Prv_LibEffortReset(deviceConfigTable_pcst);

    /* Is an external job request already accepted? (condition can only apply in idle or background state) */
    if(NULL_PTR == proc_pst->currentExtJob_pst)
    {
        /* No -> Check for a new request */
        proc_pst->currentExtJob_pst = Fee_Prv_JobNext(deviceConfigTable_pcst);
    }

    /* Based on the driver state let the Fs process external or internal jobs */
    switch(proc_pst->driverState_en)
    {
        case FEE_PRV_PROC_DRIVERSTATE_IDLE_E:        Fee_Prv_ProcProcessIdle(deviceConfigTable_pcst);        break;
        case FEE_PRV_PROC_DRIVERSTATE_BACKGROUND_E:  Fee_Prv_ProcProcessBackground(deviceConfigTable_pcst);  break;
        case FEE_PRV_PROC_DRIVERSTATE_EXT_JOB_E:     Fee_Prv_ProcProcessExtJob(deviceConfigTable_pcst);      break;
        default:                                     /* Do nothing */                                        break;
    }

    /* Background enabled? */
    if(FEE_PRV_PROC_BACKGROUNDSTATE_DISABLED != proc_pst->backgroundState_en)
    {
        /* Execute cyclic debugging actions */
        Fee_Prv_DbgMainFunction(deviceConfigTable_pcst);
    }

    /* Call working state calculation and set private copy */
    procData_pst->procWorkingState_en = Fee_Prv_ProcCalcWorkingState(deviceConfigTable_pcst);

    /* Stop timing measurement of main function */
    Fee_Prv_DbgWatchStop(deviceConfigTable_pcst->deviceName_en, FEE_PRV_DBG_TIMER_PROCMAIN_E, FALSE);

    return;
}

/*
 * \brief   Checks global flag for re-entrant invocation of main function, and reports such error to DET if enabled.
 *
 * \param   deviceName_en    Device instance for which lock has to be acquired
 * \param   procLock_pst     Pointer to the variables related to the reentrancy detection
 *
 * \return  Availability of lock
 * \return  TRUE                if lock is available, i.e. no re-entrant invocation of main function.
 * \return  FALSE               if lock is not available, i.e. re-entrant invocation of main function.
 */
LOCAL_INLINE boolean Fee_Prv_ProcTryToGetLock(Fee_Rb_DeviceName_ten deviceName_en, Fee_Prv_ProcLock_tst * procLock_pst)
{
    /* Return variable */
    boolean isLockAvailable_b = FALSE;

# if(FEE_RB_USE_PROTECTION != FALSE)
    /* Disable interrupts */
    SchM_Enter_Fee_Order();
# endif

    /* Is the main function not invoked yet? */
    if(!procLock_pst->flgUsedSema_vb)
    {
        /* Reserve it and allow its execution */
        procLock_pst->flgUsedSema_vb = TRUE;
        isLockAvailable_b = TRUE;
    }

# if(FEE_RB_USE_PROTECTION != FALSE)
    /* Enable interrupts */
    SchM_Exit_Fee_Order();
# endif

    /* Re-entrant invocation of main function? */
    if(!isLockAvailable_b)
    {
        /* Set the debug flag for the detection of reentrant main function */
        procLock_pst->dbgReentrantMainFunction_vb = TRUE;

        Fee_Prv_LibDetReport(deviceName_en, FEE_SID_MAINFUNCTION, FEE_E_BUSY);
    }

# if(FEE_RB_USE_PROTECTION == FALSE)
    /* Protection disabled, only detection by default */
    isLockAvailable_b = TRUE;
# endif

    return(isLockAvailable_b);
}

/**
 * \brief   Resets the flag having re-entrant information.
 *
 * \param   procLock_pst   Pointer to the variables related to the reentrancy detection
 */
LOCAL_INLINE void Fee_Prv_ProcReleaseLock(Fee_Prv_ProcLock_tst * procLock_pst)
{
    /* Reset the access flag */
    procLock_pst->flgUsedSema_vb = FALSE;

    return;
}

/*
 * \brief   The main function does the actual work of the Fee. The more often it is scheduled the faster the Fee is.
 *
 * \param   deviceName_en       Device instance for which job has to be performed
 */
void Fee_Rb_Idx_MainFunction(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Check parameter */
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_MAINFUNCTION))
    {
        /* Below code is needed only for multi instance with Fee1.0.
         * To be removed when either Fee1.0 is removed or multi instance support with Fee1.0 is removed. */
#  if (defined( RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if (Fee_Rb_DeviceName == deviceName_en)
        {
            /* This request is for device index = 0, this means route this request to Fee1.0 */
            Fee_MainFunction();
        }
        else
#  endif
        {
            /* Local flag to store the lock accuring status */
            boolean flgUsed_b = FALSE;
            /* Get the pointer to config data model */
            Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
            Fee_Prv_ProcData_tst *               procData_pst           = &deviceConfigTable_pcst->feeData_pst->procData_st;
            Fee_Prv_Proc_tst *                   proc_pst               = &procData_pst->proc_st;
            Fee_Prv_ProcLock_tst *               procLock_pst           = &procData_pst->procLock_st;

            /* Check for re-entrant invocation of main function */
            flgUsed_b = Fee_Prv_ProcTryToGetLock(deviceName_en, procLock_pst);

            /* Lock obtained, i.e. no re-entrant invocation of main function? */
            if(flgUsed_b)
            {
                if(!proc_pst->stopModeActive_b)
                {
                    /* Main function can be invoked */
                    Fee_Prv_ProcMainFunctionIntern(deviceConfigTable_pcst);
                }

                /* Release the lock */
                Fee_Prv_ProcReleaseLock(procLock_pst);
            }
        }
    }
    return;
}

/*
 * \brief   This function invokes the Fee Mainfunction and its lower layers.
 *
 * \param   deviceName_en       Device instance for which job has to be performed
 */
void Fee_Rb_Idx_MainFunctionAndDependency(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Check parameter */
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_MAINFUNCTION))
    {
        /* Below code is needed only for multi instance with Fee1.0.
         * To be removed when either Fee1.0 is removed or multi instance support with Fee1.0 is removed. */
# if (defined( RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if (Fee_Rb_DeviceName == deviceName_en)
        {
            /* This request is for device index = 0, this means route this request to Fls MainFunction */
            Fee_MainFunction();
            Fls_Rb_MainFunctionAndDependency();
        }
        else
# endif
        {
            /* Get the pointer to config data model */
            Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
            Fee_Prv_Medium_tst const *            medium_pst             = &deviceConfigTable_pcst->feeData_pst->mediumData_st.medium_st;

            Fee_Rb_Idx_MainFunction(deviceName_en);
            Fee_Prv_Lib_Fls_MainFunction(medium_pst->flsDevId_en);
        }
    }

    return;
}


#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif
