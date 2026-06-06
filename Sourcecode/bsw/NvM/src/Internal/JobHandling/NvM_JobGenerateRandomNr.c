
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"

#include "NvM_Prv_Job.h"
#include "NvM_Prv_JobResource.h"

/*
 **********************************************************************************************************************
 * Declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

static void NvM_Prv_JobGenerateRandomNr_DoCrypto(NvM_Prv_stJob_ten* stJob_pen,
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
 * This private function returns the pointer to the job step for the current state of the random number generation job.
 * \details
 * This function returns a NULL pointer if passed random number generation job state is invalid.
 * In this case the random number generation job will fail.
 *
 * \param [inout] stJob_en
 * Pointer to the current state of the random number generation job
 *
 * \return
 * Pointer to the job step function or NULL pointer for invalid random number generation job state
 */
NvM_Prv_Job_State_tpfct NvM_Prv_JobGenerateRandomNr_GetStateFct(NvM_Prv_stJob_ten* stJob_pen)
{
    NvM_Prv_Job_State_tpfct JobGenerateRandomNr_State_pfct = NULL_PTR;

    switch (*stJob_pen)
    {
        case NvM_Prv_stJob_Idle_e:
            JobGenerateRandomNr_State_pfct = NvM_Prv_JobGenerateRandomNr_DoCrypto;
            // set job state to ease debugging and to avoid MISRA warning that stJob_pen can be a pointer to const
            *stJob_pen = NvM_Prv_stJob_DoCrypto_e;
        break;

        case NvM_Prv_stJob_DoCrypto_e:
        case NvM_Prv_stJobGenerateRandomNr_CryptoStart_e:
        case NvM_Prv_stJobGenerateRandomNr_CryptoPoll_e:
            JobGenerateRandomNr_State_pfct = NvM_Prv_JobGenerateRandomNr_DoCrypto;
        break;

        default:
            JobGenerateRandomNr_State_pfct = NULL_PTR;
        break;
    }

    return JobGenerateRandomNr_State_pfct;
}

/**
 * \brief
 * This local private function is a random number generation job step function and handles cryptographic services
 * if configured.
 * \details
 * The NvM reaches this job step if random number generation job has been started.
 *
 * This function executes the state machine for cryptographic random number generation job
 * (see NvM_Prv_Crypto_DoStateMachine and NvM_Prv_Crypto_GetJobStateGenerateRandom).
 *
 * \param [inout] stJob_pen
 * Pointer to the current job state
 * \param [inout] JobResult_pst
 * Pointer to the job results,  possible values:
 * - NvM_Prv_JobResult_Pending_e   = Cryptographic services are still pending -> wait 1 cycle
 * - NvM_Prv_JobResult_Failed_e    = Cryptographic services has failed -> finish job
 * - NvM_Prv_JobResult_Succeeded_e = Cryptographic services has succeeded -> finish job
 * \param [in] JobData_pcst
 * Constant pointer to the job data
 */
static void NvM_Prv_JobGenerateRandomNr_DoCrypto(NvM_Prv_stJob_ten* stJob_pen,
                                                 NvM_Prv_JobResult_tst* JobResult_pst,
                                                 NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_Prv_JobResource_DoStateMachine(NvM_Prv_JobResource_Cluster_Crypto_e, stJob_pen, JobResult_pst, JobData_pcst);

    if (NvM_Prv_JobResult_Succeeded_e == JobResult_pst->Result_en)
    {
        // Cryptographic services for random number generation job have succeeded or are not configured ->
        // finish random number generation job
        *stJob_pen = NvM_Prv_stJob_Finished_e;
    }
    else if (NvM_Prv_JobResult_Pending_e == JobResult_pst->Result_en)
    {
        // Random number generation job is still pending -> remain in this state, do not update final job result
    }
    else
    {
        // Cryptographic services for random number generation job have failed ->
        // finish random number generation job, update final job result
        JobResult_pst->Result_en = NvM_Prv_JobResult_Failed_e;
        *stJob_pen = NvM_Prv_stJob_Finished_e;
    }
}


#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

