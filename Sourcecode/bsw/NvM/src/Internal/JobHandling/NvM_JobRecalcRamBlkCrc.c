/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"
#include "NvM_Cfg_SchM.h"

#include "NvM_Prv_Job.h"
#include "NvM_Prv_Crc.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ExplicitSynchronization.h"
#include "NvM_Prv_JobResource.h"


/*
 **********************************************************************************************************************
 * Declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

static void NvM_Prv_JobRecalcRamBlkCrc_ExplicitSyncWriteToNvM(NvM_Prv_stJob_ten* stJob_pen,
                                                              NvM_Prv_JobResult_tst* JobResult_pst,
                                                              NvM_Prv_JobData_tst const* JobData_pcst);

static void NvM_Prv_JobRecalcRamBlkCrc_DoCrc(NvM_Prv_stJob_ten* stJob_pen,
                                             NvM_Prv_JobResult_tst* JobResult_pst,
                                             NvM_Prv_JobData_tst const* JobData_pcst);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/**
 * \brief
 * This private function returns the pointer to the job step for the current state of the job for the recalculation
 * of the CRC over the data in the permanent RAM block .
 * \details
 * This function returns a NULL pointer if passed job state is invalid. In this case the job will fail.
 *
 * \param[INOUT] stJob_pen
 * Pointer to the current state of the read job
 *
 * \return
 * Pointer to the job step function or NULL pointer for invalid job state
 */
NvM_Prv_Job_State_tpfct NvM_Prv_JobRecalcRamBlkCrc_GetStateFct(NvM_Prv_stJob_ten* stJob_pen)
{
    NvM_Prv_Job_State_tpfct JobRecalcRamBlkCrc_State_pfct = NULL_PTR;

    switch (*stJob_pen)
    {
        case NvM_Prv_stJob_Idle_e:
        case NvM_Prv_stRecalcRamBlkCrc_ExplicitSyncWriteToNvM_e:
            JobRecalcRamBlkCrc_State_pfct = NvM_Prv_JobRecalcRamBlkCrc_ExplicitSyncWriteToNvM;
            *stJob_pen = NvM_Prv_stRecalcRamBlkCrc_ExplicitSyncWriteToNvM_e;
        break;

        case NvM_Prv_stRecalcRamBlkCrc_Do_e:
            JobRecalcRamBlkCrc_State_pfct = NvM_Prv_JobRecalcRamBlkCrc_DoCrc;
            // set job state to ease debugging and to avoid MISRA warning that stJob_pen can be a pointer to const
            *stJob_pen = NvM_Prv_stRecalcRamBlkCrc_Do_e;
        break;

        default:
            JobRecalcRamBlkCrc_State_pfct = NULL_PTR;
        break;
    }

    return JobRecalcRamBlkCrc_State_pfct;
}


/**
 * \brief
 * This local private function is a job step function and gets user data for a CRC recalculation if required.
 * \details
 * Before starting the CRC recalculation this function ensures that the job buffer contains user data.
 *
 * The NvM has to copy user data into the job buffer only if current block is configured for explicit configuration.
 *
 * \param [inout] stJob_pen
 * State of the job
 * \param [inout] JobResult_pst
 * Pointer to the job results, possible values:
 * - NvM_Prv_JobResult_Succeeded_e  = Copying of user data has succeeded or is not required -> recalculate CRC over the user data
 * - NvM_Prv_JobResult_Pending_e    = Copying data into the job buffer is still in progress -> wait 1 cycle
 * - NvM_Prv_JobResult_Failed_e     = Copying of user data has failed -> finish job
 * \param [in] JobData_pcst
 * Pointer to the data of the current NvM job
 */
static void NvM_Prv_JobRecalcRamBlkCrc_ExplicitSyncWriteToNvM(NvM_Prv_stJob_ten* stJob_pen,
                                                              NvM_Prv_JobResult_tst* JobResult_pst,
                                                              NvM_Prv_JobData_tst const* JobData_pcst)
{
    JobResult_pst->Result_en = NvM_Prv_JobResult_Succeeded_e;

#if (defined(NVM_CALC_RAM_BLOCK_CRC) && (NVM_CALC_RAM_BLOCK_CRC == STD_ON))

    if (NvM_Prv_BlkDesc_IsBlockSelected(JobData_pcst->idBlock_uo, NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM))
    {
        // TRACE[SWS_NvM_00362] Before NvM can check the RAM block CRC for blocks with configured explicit
        //                      synchronization the RAM block data must be copied into the NvM RAM mirror
        //                      via write callback,
        JobResult_pst->Result_en = NvM_Prv_ExplicitSync_CopyData(NvM_Prv_BlkDesc_GetCopyFctForWrite(JobData_pcst->idBlock_uo,
                                                                                                    JobData_pcst->IntBuffer_st.Buffer_pu8),
                                                                 JobData_pcst->idBlock_uo,
                                                                 &JobData_pcst->cntrExpSyncOperations_u8,
                                                                 JobData_pcst->IntBuffer_st.Buffer_pu8);
    }

    if (NvM_Prv_JobResult_Succeeded_e == JobResult_pst->Result_en)
    {
        // TRACE[SWS_NvM_00362] Copying data for explicit synchronization has succeeded or
        //                      current block is not configured for explicit synchronization ->
        //                      Initiate RAM block CRC recalculation
        *stJob_pen = NvM_Prv_stRecalcRamBlkCrc_Do_e;

        // Prepare CRC recalculation over the user data
        JobResult_pst->CrcData_st.Calculation_st.stCalculation_en = NvM_Prv_JobResult_Succeeded_e;
        JobResult_pst->CrcData_st.Calculation_st.isFirstCall_b = TRUE;
        JobResult_pst->CrcData_st.Calculation_st.Length_u16 = NvM_Prv_BlkDesc_GetSize(JobData_pcst->idBlock_uo);
        JobResult_pst->CrcData_st.Calculation_st.Crc_un.Crc32_u32 = 0u;
        JobResult_pst->CrcData_st.Calculation_st.Buffer_pu8 = JobData_pcst->IntBuffer_st.Buffer_pu8;
    }
    else if (NvM_Prv_JobResult_Failed_e == JobResult_pst->Result_en)
    {
        // If copying data for explicit synchronization has failed then no CRC check can be done
        // -> Signal that it failed so that in NvM_Prv_UpdateBlockStatus_RecalcRamBlkCrc()
        // the further processing can be done the same way as if data has been changed.
        *stJob_pen = NvM_Prv_stJob_Finished_e;
    }
    else
    {
        // If copying data for explicit synchronization is still pending do nothing
    }

#else
    (void)JobData_pcst;
    *stJob_pen = NvM_Prv_stJob_Finished_e;
#endif
}


/**
 * \brief
 * This local private function is a job step function and recalculates the CRC over the user data in permanent RAM block.
 * \details
 * The NvM reaches this job step only if following preconditions are true:
 * - job buffer contains user data
 *
 * \param [inout] stJob_pen
 * State of the job
 * \param [inout] JobResult_pst
 * Pointer to the job results, possible values:
 * - NvM_Prv_JobResult_Pending_e   = CRC recalculation is still in progress -> wait 1 cycle
 * - NvM_Prv_JobResult_Succeeded_e = CRC recalculation completed -> finish job
 * \param [in] JobData_pcst
 * Pointer to the data of the current NvM job
 */
static void NvM_Prv_JobRecalcRamBlkCrc_DoCrc(NvM_Prv_stJob_ten* stJob_pen,
                                             NvM_Prv_JobResult_tst* JobResult_pst,
                                             NvM_Prv_JobData_tst const* JobData_pcst)
{
    JobResult_pst->Result_en = NvM_Prv_JobResult_Succeeded_e;

#if (defined(NVM_CALC_RAM_BLOCK_CRC) && (NVM_CALC_RAM_BLOCK_CRC == STD_ON))

    *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16 = NvM_Prv_BlkDesc_GetSize(JobData_pcst->idBlock_uo);
    NvM_Prv_Crc_Calculate(stJob_pen, JobResult_pst, JobData_pcst);
    *stJob_pen = NvM_Prv_stRecalcRamBlkCrc_Do_e;

    if (NvM_Prv_JobResult_Pending_e != JobResult_pst->Result_en)
    {
        *stJob_pen = NvM_Prv_stJob_Finished_e;

        // Copy CRC over the user data for later usage
        JobResult_pst->CrcData_st.CrcRamBlk_un.Crc32_u32 = JobResult_pst->CrcData_st.Calculation_st.Crc_un.Crc32_u32;
    }

#else
    (void)JobData_pcst;
    *stJob_pen = NvM_Prv_stJob_Finished_e;
#endif
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

