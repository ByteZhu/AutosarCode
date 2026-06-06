
/*
 * The Job unit stores the received orders in internal job slots.
 * The main function will poll jobs from the Job unit and inform the Job unit if a job is finished.
 */

#ifndef FEE_PRV_JOB_H
#define FEE_PRV_JOB_H

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

#include "MemIf_Types.h"
#include "Fee_Cfg.h"
#include "Fee_Prv_Config.h"
#include "Fee_PrvTypes.h"
#include "Fee_Prv_JobTypes.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
extern Fee_Prv_JobDesc_tst *  Fee_Prv_JobNext(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
extern void                   Fee_Prv_JobEnd(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, MemIf_JobResultType result_en, Fee_Prv_JobChunkInfo_tst const * chunkInfo_pcst);
extern void                   Fee_Prv_JobChunkEnd(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, Fee_Prv_JobChunkInfo_tst const * chunkInfo_pcst);

extern Fee_Rb_ChunkResult_ten Fee_Prv_JobGetChunkResult(Fee_Rb_DeviceName_ten deviceName_en);
extern uint32                 Fee_Prv_JobGetChunkNrBytProc(Fee_Rb_DeviceName_ten deviceName_en);

Fee_Prv_JobDesc_tst const *   Fee_Prv_JobGetActv(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, Fee_Prv_ConfigRequester_ten requester_en);
extern Fee_Rb_JobType_ten     Fee_Prv_JobGetActvType(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst, Fee_Prv_ConfigRequester_ten requester_en);

extern Std_ReturnType         Fee_Prv_JobPut(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, Fee_Prv_JobDesc_tst const * jobDesc_pcst);
extern MemIf_JobResultType    Fee_Prv_JobGetResult(Fee_Rb_DeviceName_ten deviceName_en, Fee_Prv_ConfigRequester_ten requester_en);

#  if(FALSE != FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE)
extern Fee_Rb_JobMode_ten     Fee_Prv_JobGetJobMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, Fee_Rb_JobType_ten jobType_en);
extern void                   Fee_Prv_JobSetJobMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, Fee_Rb_JobType_ten jobType_en, Fee_Rb_JobMode_ten jobMode_en);
#  endif

extern void                   Fee_Prv_JobSetModesBasedOnDriverMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, MemIf_ModeType mode);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
*/
LOCAL_INLINE void Fee_Prv_JobInit(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);

#  if((FALSE == FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE) || (STD_OFF == FEE_PRV_CFG_SET_MODE_SUPPORTED))
LOCAL_INLINE Fee_Rb_JobMode_ten Fee_Prv_JobGetJobMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, Fee_Rb_JobType_ten jobType_en);
#  endif
/*
 **********************************************************************************************************************
 * Inline functions implementation
 **********************************************************************************************************************
*/
/**
 * \brief   Function called during Fee_Init(). Initializes all the variables of this unit.
 * To save code size + delay due to calling of function with parameter, the function is made inline.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table which has to be initialized.
 */
LOCAL_INLINE void Fee_Prv_JobInit(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    Fee_Prv_JobData_tst *    jobData_pst = &deviceConfigTable_pcst->feeData_pst->jobData_st;
    uint8_least              idxLoop_qu8;

    /* Init the job queue */
    for(idxLoop_qu8 = 0u; idxLoop_qu8 < (uint8_least)FEE_PRV_REQUESTER_MAX_E; idxLoop_qu8++)
    {
        jobData_pst->job_st.jobs_ast[idxLoop_qu8].type_en = FEE_RB_JOBTYPE_MAX_E;
        jobData_pst->job_st.results_aen[idxLoop_qu8]      = MEMIF_JOB_OK;
    }

    /* Init the status of a chunk-wise job */
    jobData_pst->chunkInfo_st.nrBytProc_u32 = 0uL;
    jobData_pst->chunkInfo_st.result_en     = FEE_RB_CHUNK_ALL_OK_E;

#  if((FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE != FALSE) || (STD_ON == FEE_PRV_CFG_SET_MODE_SUPPORTED))
    /* set the mode of different jobs to default mode */
    for(idxLoop_qu8 = 0; idxLoop_qu8 < (uint8_least)FEE_RB_JOBTYPE_MAX_E; idxLoop_qu8++)
    {
        jobData_pst->job_st.jobMode_en[idxLoop_qu8] = FEE_RB_ALLJOBS_ALLSTEPS_E;
    }
#  endif
}

/**
 * \brief The Fee_Prv_JobGetJobMode API should always be present, even when both the SetMode and JobMode features are disabled.
 * As this function is called in all job orders to get the mode in which the job has to be performed.
 * In such situtation to save code its better to make this inline function and always return default job mode.
 *
 * \param   deviceConfigTable_pcst  Pointer to the config table which has to be initialized.
 * \param   jobType_en              Job type for which mode has to be set
 *
 * \return  FEE_RB_ALLJOBS_ALLSTEPS_E for all jobs
 */
#  if((FALSE == FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE) || (STD_OFF == FEE_PRV_CFG_SET_MODE_SUPPORTED))
LOCAL_INLINE Fee_Rb_JobMode_ten Fee_Prv_JobGetJobMode(Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst, Fee_Rb_JobType_ten jobType_en)
{
    (void)deviceConfigTable_pcst;
    (void)jobType_en;

    return(FEE_RB_ALLJOBS_ALLSTEPS_E);
}
#  endif

# endif

/* FEE_PRV_JOB_H */
#endif
