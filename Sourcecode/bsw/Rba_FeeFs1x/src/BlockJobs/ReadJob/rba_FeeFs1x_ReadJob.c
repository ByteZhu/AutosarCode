

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"


#if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "rba_FeeFs1x_Prv_ReadJob.h"
#include "rba_FeeFs1x_Prv_ReadJobTypes.h"
#include "rba_FeeFs1x_Prv_BC.h"
#include "rba_FeeFs1x_Prv.h"

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



/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"


static rba_FeeFs1x_RdJob_JobData_tst rba_FeeFs1x_RdJob_JobData_st;

static rba_FeeFs1x_Searcher_RetVal_ten rba_FeeFs1x_RdJob_searchReturnValue_en;


#define FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"
/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
 */

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

/**
 *********************************************************************
 * rba_FeeFs1x_RdJob_checkRdReq
 * Function matching the blockjob function typedef for state init functions for passing parameters
 * to an asynchronous job. This specific checkRdReq initializes a read job
 * \param   retValSearch_en : defines how many copies were found during the search
 * \return  Job accepted
 * \retval  E_OK : job accepted, checkRdReqDo should be called now
 * \retval  E_NOT_OK : job not accepted, don't call checkRdReqDo
 * \seealso
 * \usedresources
 *********************************************************************
 */
void rba_FeeFs1x_RdJob_checkRdReq(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en)
{
    rba_FeeFs1x_RdJob_searchReturnValue_en = retValSearch_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_RdJob_checkRdReqDo
 * asynchronous part of the checkRdReq function

 * \return  result of the checking for necessity/ possiblility of reading this block
 * \retval  rba_FeeFs1x_BlockJob_ReturnType_inconsistent_e : no copy with valid data found
 * \retval  rba_FeeFs1x_BlockJob_ReturnType_invalidated_e : valid copy explicitly invalidated found
 * \retval  rba_FeeFs1x_BlockJob_ReturnType_execute_e : read can be executed
 * \retval  rba_FeeFs1x_BlockJob_ReturnType_error_e : internal error leading to job abort
 * \seealso
 * \usedresources
 *********************************************************************
 */
rba_FeeFs1x_BlockJob_ReturnType_ten rba_FeeFs1x_RdJob_checkRdReqDo(void)
{
    rba_FeeFs1x_BlockJob_ReturnType_ten retVal_en;
    switch(rba_FeeFs1x_RdJob_searchReturnValue_en)
    {
        case rba_FeeFs1x_Searcher_RetVal_OneCopyFound_e:
        {
            boolean hasInvBitSet_b = FALSE;
            hasInvBitSet_b = rba_FeeFs1x_BC_getCpyInvBitActive(rba_FeeFs1x_BC_Cpy_BlockJobs_Latest_e);
            if(hasInvBitSet_b)
            {
                // invalidated copy
                retVal_en = rba_FeeFs1x_BlockJob_ReturnType_invalidated_e;
            }
            else
            {
                // not invalidated copy --> read allowed
                retVal_en = rba_FeeFs1x_BlockJob_ReturnType_execute_e;
            }
            break;
        }
        case rba_FeeFs1x_Searcher_RetVal_NoCopyFound_e:
        {
            // If no copies are found, the copy is inconsistent
            retVal_en = rba_FeeFs1x_BlockJob_ReturnType_inconsistent_e;
            break;
        }
        default:
        {
            // If not explicitly 0 or 1 copy is found by the searcher, the return value is unexpected --> error
            retVal_en = rba_FeeFs1x_BlockJob_ReturnType_error_e;
            break;
        }
    }
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_RdJob_execRd
 * \param   retValSearch_en : defines how many copies were found during the search
 * \seealso
 * \usedresources
 *********************************************************************
 */
void rba_FeeFs1x_RdJob_execRd(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en)
{
    rba_FeeFs1x_RdJob_searchReturnValue_en = retValSearch_en;

    // start the BC read
    rba_FeeFs1x_BC_readFls2Ram(rba_FeeFs1x_BC_Cpy_BlockJobs_Latest_e,
                               rba_FeeFs1x_RdJob_JobData_st.length_u16,
                               rba_FeeFs1x_RdJob_JobData_st.offset_u16,
                               rba_FeeFs1x_RdJob_JobData_st.userbuffer_pu8);
}
/**
 *********************************************************************
 * rba_FeeFs1x_RdJob_execRdDo
 * \return  read finished successfully?
 * \retval  rba_FeeFs1x_BlockJob_ReturnType_JobOK_e : read finished
 * \retval  rba_FeeFs1x_BlockJob_ReturnType_pending_e : ongoing, call again during next cycle
 * \retval  rba_FeeFs1x_BlockJob_ReturnType_error_e : job aborted due to internal errors
 * \seealso
 * \usedresources
 *********************************************************************
 */
rba_FeeFs1x_BlockJob_ReturnType_ten rba_FeeFs1x_RdJob_execRdDo(void)
{
    rba_FeeFs1x_RetVal_ten retValRd_en;
    rba_FeeFs1x_BlockJob_ReturnType_ten retVal_en;


    retValRd_en = rba_FeeFs1x_BC_readFls2RamDo();


    switch(retValRd_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // job finished successfully
            retVal_en = rba_FeeFs1x_BlockJob_ReturnType_JobOK_e;
            break;
        }
        case rba_FeeFs1x_Pending_e:
        {
            // read needs to be called during the next cycle
            retVal_en = rba_FeeFs1x_BlockJob_ReturnType_pending_e;
            break;
        }
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_ErrorInternal_e:
        default:
        {
            // Error during read or unexpected return value
            retVal_en = rba_FeeFs1x_BlockJob_ReturnType_error_e;
            break;
        }
    }

    if(retVal_en != rba_FeeFs1x_BlockJob_ReturnType_pending_e)
    {
        // finalise the copies before exit
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_BlockJobs_Latest_e);

        rba_FeeFs1x_RdJob_JobData_st.length_u16 = 0u;
        rba_FeeFs1x_RdJob_JobData_st.offset_u16 = 0u;
        rba_FeeFs1x_RdJob_JobData_st.userbuffer_pu8 = NULL_PTR;
    }
    return  retVal_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_RdJob_init
 * resets the RdJob internal variables
 * \seealso
 * \usedresources
 *********************************************************************
 */
void rba_FeeFs1x_RdJob_init(void)
{
    rba_FeeFs1x_RdJob_JobData_st.length_u16     = 0u;
    rba_FeeFs1x_RdJob_JobData_st.offset_u16     = 0u;
    rba_FeeFs1x_RdJob_JobData_st.userbuffer_pu8 = NULL_PTR;

    rba_FeeFs1x_RdJob_searchReturnValue_en      = rba_FeeFs1x_Searcher_RetVal_ErrorInternal_e;
}
/**
 *********************************************************************
 * rba_FeeFs1x_RdJob_initJob
 * function for passing the read relevant data from the job acceptor function in BlockJob unit
 * \param   length_u16 : amount of bytes to be read
 * \param   offset_u16 : offset within the block to be read
 * \param   userbuffer_pu8 : location to store to after the copy is validated
 * \seealso
 * \usedresources
 *********************************************************************
 */
void rba_FeeFs1x_RdJob_initJob(uint16 length_u16, uint16 offset_u16, uint8* userbuffer_pu8)
{
    rba_FeeFs1x_RdJob_JobData_st.length_u16     = length_u16;
    rba_FeeFs1x_RdJob_JobData_st.offset_u16     = offset_u16;
    rba_FeeFs1x_RdJob_JobData_st.userbuffer_pu8 = userbuffer_pu8;
}

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif

