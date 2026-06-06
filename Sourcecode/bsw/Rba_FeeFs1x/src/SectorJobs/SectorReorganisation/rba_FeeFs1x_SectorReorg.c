#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

#if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "rba_FeeFs1x_Prv_Cfg.h"

#include "rba_FeeFs1x_Prv_SectorReorg.h"
#include "rba_FeeFs1x_Prv_SectorReorgTypes.h"

#include "Fee_Prv_Lib.h"

#include "rba_FeeFs1x_Prv_Sector.h"
#include "rba_FeeFs1x_Prv_PAMap.h"
#include "rba_FeeFs1x_Prv_PASrv.h"

#include "rba_FeeFs1x_Prv_Searcher.h"
#include "rba_FeeFs1x_Prv_BC.h"

#include "rba_FeeFs1x_Prv_CacheKwn.h"
#include "rba_FeeFs1x_Prv_CacheUnkwn.h"



/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
#define RBA_FEEFS1X_REORG_LOGSECTOR_TO_BE_REORGED  0u  // Currently, only the oldest sector is always reorgd
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

/* MR12 RULE 8.5 VIOLATION: warning arises only in test environment, not in productive code. Warning has no impact. */
RBA_FEEFS1X_VAR_SCOPE(rba_FeeFs1x_Reorg_stm_tst         rba_FeeFs1x_Reorg_stm_st)
/* MR12 RULE 8.5 VIOLATION: warning arises only in test environment, not in productive code. Warning has no impact. */
RBA_FEEFS1X_VAR_SCOPE(rba_FeeFs1x_Reorg_Known_data_tst  rba_FeeFs1x_Reorg_Known_data_st)

static rba_FeeFs1x_Reorg_transferCopies_data_tst        rba_FeeFs1x_Reorg_transfer1Copy_data_st;
static rba_FeeFs1x_Reorg_transferCopies_data_tst        rba_FeeFs1x_Reorg_transfer2Copies_data_st;

static rba_FeeFs1x_Reorg_repairSectOverflow_data_tst    rba_FeeFs1x_Reorg_repairSectOverflow_data_st;
static rba_FeeFs1x_Reorg_reorgUnknown_data_tst          rba_FeeFs1x_Reorg_reorgUnknown_data_st;
static rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st;

#define FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
 */

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_checkAndFillSect0End(rba_FeeFs1x_Reorg_stm_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_known(rba_FeeFs1x_Reorg_stm_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_unknown(rba_FeeFs1x_Reorg_stm_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_sectorOverflow(rba_FeeFs1x_Reorg_stm_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_end(rba_FeeFs1x_Reorg_stm_tst * fsm_pst);

LOCAL_INLINE void                     rba_FeeFs1x_Reorg_reorgKnown(boolean isSoftReorg_b);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgKnownDo(void);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgKnownDo_selectBlk(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgKnownDo_searchBlk(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgKnownDo_checkReq(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst);
LOCAL_INLINE void                     rba_FeeFs1x_Reorg_reorgKnownDo_checkReq_checkRedCpy(
        rba_FeeFs1x_Reorg_Known_data_tst const * fsm_pcst , uint8 * cntcpiesReqForRed_pu8);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgKnownDo_copy1(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgKnownDo_copy2(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst);
LOCAL_INLINE boolean                  rba_FeeFs1x_Reorg_reorgKnown_isSoftOngoing(void);

LOCAL_INLINE void                     rba_FeeFs1x_Reorg_reorgUnknown(boolean isSoftReorg_b);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo(void);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo_checkCacheRebuildReq  (rba_FeeFs1x_Reorg_reorgUnknown_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo_cacheRebuild          (rba_FeeFs1x_Reorg_reorgUnknown_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo_reorgCachedBlocks     (rba_FeeFs1x_Reorg_reorgUnknown_data_tst * fsm_pst);
LOCAL_INLINE boolean                  rba_FeeFs1x_Reorg_reorgUnknown_isSoftOngoing(void);

LOCAL_INLINE void                     rba_FeeFs1x_Reorg_reorgUnknownCached(boolean isSoftReorg_b);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownCachedDo(void);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownCachedDo_selectBlk      (rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownCachedDo_searchBlk      (rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq       (rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst);
LOCAL_INLINE void                     rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq_checkRedCpy(
        rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst const * fsm_pcst , uint8 * cntCpiesReqForRed_pu8);

LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy1          (rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy2          (rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst);
LOCAL_INLINE boolean                  rba_FeeFs1x_Reorg_reorgUnknownCached_isSoftOngoing(void);

static void rba_FeeFs1x_Reorg_transferCopyDo_updCache(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en, uint16 feeIndex_u16 , boolean isKnownBlock_b);

static void rba_FeeFs1x_Reorg_transfer1Copy(boolean isKnownBlock_b, uint16 feeIdx_u16)                                         ;
static rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo(void)                                                          ;
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo_init1 (rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst)    ;
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo_copy1 (rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst)    ;
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo_error1(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst)    ;

static void rba_FeeFs1x_Reorg_transfer2Copies(boolean isKnownBlock_b, uint16 feeIdx_u16)                                       ;
static rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo(void)                                                        ;

LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo_init(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst,rba_FeeFs1x_Reorg_transferCopy_ten copy_en);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo_copy(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst,rba_FeeFs1x_Reorg_transferCopy_ten copy_en);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo_error(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst,rba_FeeFs1x_Reorg_transferCopy_ten copy_en);

LOCAL_INLINE Std_ReturnType rba_FeeFs1x_Reorg_updatePages(uint32 amountOfPages_u32);

LOCAL_INLINE void                     rba_FeeFs1x_Reorg_repairSectOverflow(void);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_repairSectOverflowDo(void);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_repairSectOverflowDo_erase       (rba_FeeFs1x_Reorg_repairSectOverflow_data_tst * fsm_pst);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_repairSectOverflowDo_cacheBuildup(rba_FeeFs1x_Reorg_repairSectOverflow_data_tst * fsm_pst);

static void                     rba_FeeFs1x_Reorg_switchToHardReorg(void);

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
 */


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_init
 * initializes the unit internal variables
 * \seealso
 * \usedresources
 *********************************************************************
 */

void rba_FeeFs1x_Reorg_init(void)
{

    rba_FeeFs1x_Reorg_stm_st.state_en = rba_FeeFs1x_Reorg_stm_idle_e;
    rba_FeeFs1x_Reorg_stm_st.isSoftReorgOngoing_b = FALSE;

    rba_FeeFs1x_Reorg_Known_data_st.state_en = rba_FeeFs1x_Reorg_Known_stm_idle_e;
    rba_FeeFs1x_Reorg_Known_data_st.isSoftReorgOngoing_b    = FALSE;


    rba_FeeFs1x_Reorg_transfer1Copy_data_st.state_en = rba_FeeFs1x_Reorg_transferCopies_stm_idle_e;

    rba_FeeFs1x_Reorg_transfer2Copies_data_st.state_en = rba_FeeFs1x_Reorg_transferCopies_stm_idle_e;

    rba_FeeFs1x_Reorg_repairSectOverflow_data_st.state_en = rba_FeeFs1x_Reorg_repairSectOverflow_stm_idle_e;

    rba_FeeFs1x_Reorg_reorgUnknown_data_st.state_en = rba_FeeFs1x_Reorg_reorgUnknown_stm_idle_e;
    rba_FeeFs1x_Reorg_reorgUnknown_data_st.isSoftReorgOngoing_b = FALSE;

    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.state_en = rba_FeeFs1x_Reorg_reorgUnknownCached_stm_idle_e;
    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.isSoftReorgOngoing_b   = FALSE;

}



/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseSector
 * job init function for trigggering a reorganisation of log. sector 0
 * \param   isSoftReorg_b : is it a request for a soft or a hard sector reorg
 * \return  void
 * \seealso
 * \usedresources
 *********************************************************************
 */
void rba_FeeFs1x_Reorg_reorganiseSector(boolean isSoftReorg_b)
{
    if(rba_FeeFs1x_Reorg_stm_st.isSoftReorgOngoing_b)
    {
        // Soft Reorg Calls should not cause any action while the state should be changed
        // for a hard reorg call
        if(isSoftReorg_b)
        {
            // The job init function is called during an already ongoing soft reorg; do not reset the state machine
            // continue the previous state
        }
        else
        {
            // A external request during a soft reorg caused a hard reorg
            rba_FeeFs1x_Reorg_switchToHardReorg();

            // Attention: If a soft reorg is ongoing, the reorg state is not allowed to be idle.
            // Otherwise, the hard reorg is going to exit with an error internal
        }
    }
    else
    {
        // No reorg ongoing, trigger the reorg and set the soft reorg flag according to the parameter
        rba_FeeFs1x_Reorg_stm_st.state_en = rba_FeeFs1x_Reorg_stm_checkAndFillSect0End_e;
        rba_FeeFs1x_Reorg_stm_st.entry_b  = TRUE;

        rba_FeeFs1x_Reorg_stm_st.isSoftReorgOngoing_b = isSoftReorg_b;
        rba_FeeFs1x_Reorg_stm_st.sectorOverflowAttemptCtr_u8 = 0u;
    }
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseSectorDo
 * jobDo function for asynchronously processing the sector reorganisation
 * Some errors will be never reported from known, unknown and sector overflow states
 * This will always cause a restart of the reorg from the beginning
 * If reorg can never be finished this may cause an endless loop of reorgs
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_JobFailed_e : reorg finished and can be restarted
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    switch (rba_FeeFs1x_Reorg_stm_st.state_en)
    {
        case rba_FeeFs1x_Reorg_stm_checkAndFillSect0End_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorganiseSectorDo_checkAndFillSect0End(&rba_FeeFs1x_Reorg_stm_st);
        }break;
        case rba_FeeFs1x_Reorg_stm_known_e:
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_reorganiseSectorDo_known(&rba_FeeFs1x_Reorg_stm_st);
        } break;
        case rba_FeeFs1x_Reorg_stm_unknown_e:
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_reorganiseSectorDo_unknown(&rba_FeeFs1x_Reorg_stm_st);
        } break;
        case rba_FeeFs1x_Reorg_stm_sectorOverFlowHandler_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorganiseSectorDo_sectorOverflow(&rba_FeeFs1x_Reorg_stm_st);
        }break;
        case rba_FeeFs1x_Reorg_stm_end_e:
        {
            // trigger the sector marking R2E, reordering and reduceOwnPages trigger
            retVal_en = rba_FeeFs1x_Reorg_reorganiseSectorDo_end(&rba_FeeFs1x_Reorg_stm_st);
        } break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        } break;
    }

    if( (retVal_en != rba_FeeFs1x_Pending_e) && !(rba_FeeFs1x_Reorg_stm_st.isSoftReorgOngoing_b))
    {
        // reset on job exit if no soft reorg is ongoing
        rba_FeeFs1x_Reorg_stm_st.state_en = rba_FeeFs1x_Reorg_stm_idle_e;
        // isSoftReorgOngoing_b explicitly not reset to prevent soft reorgs getting reset
    }


    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseSectorDo_checkAndFillSect0End
 * state function for filling up sector 0 in case the actual write page is in sector 0
 *
 * \param   fsm_pst : pointer to the statemachine data
 * \return  is the job accepted?
 * \retval  rba_FeeFs1x_JobOK_e: job finished successful
 * \retval  rba_FeeFs1x_Pending_e: job ongoing, call the function again
 * \retval  rba_FeeFs1x_ErrorInternal_e: sector reorg job failed, internal error
 * \retval  rba_FeeFs1x_ErrorExternal_e: sector reorg job failed, external error
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_checkAndFillSect0End(rba_FeeFs1x_Reorg_stm_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValFill_en;

    if(rba_FeeFs1x_PAMap_getCurrWrPage() < RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR)
    {
        // current write page is in sector 0 => fill up sector 0 to assure that the write page is above sector 0
        if(FEE_PRV_LIBENTRY)
        {
            rba_FeeFs1x_PAMap_fillSectorEnd();
        }

        // Call the do-function of the job
        retValFill_en =  rba_FeeFs1x_PAMap_fillSectorEndDo();

        // evaluate the job result
        switch (retValFill_en)
        {
            case rba_FeeFs1x_JobOK_e:
            {
                // as soon as the state's job is finished, transit to next state
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_known_e);
                retVal_en = rba_FeeFs1x_Pending_e;
            }break;
            case rba_FeeFs1x_Pending_e:
            case rba_FeeFs1x_ErrorInternal_e:
            case rba_FeeFs1x_ErrorExternal_e:
            {
                retVal_en = retValFill_en;
            }break;
            default:
            {
                // on error or unexpected return value, return error to the caller and stop the state machine
                retVal_en = rba_FeeFs1x_ErrorInternal_e;
            }break;
        }
    }
    else
    {
        // current write page is above sector 0 => reorganize sector without filling up sector 0
        FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_known_e);
        retVal_en = rba_FeeFs1x_Pending_e;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseSectorDo_known
 * statefunction of reorganiseSectorDo executing the known block reorg
 * Errors will be never reported and will always cause a restart of the reorg
 * If reorg can never be finished this may cause an endless loop of reorgs
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_known(rba_FeeFs1x_Reorg_stm_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValKnown_en;
    if(FEE_PRV_LIBENTRY)
    {
        rba_FeeFs1x_Reorg_reorgKnown(fsm_pst->isSoftReorgOngoing_b);
    }
    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValKnown_en = rba_FeeFs1x_Reorg_reorgKnownDo();

    switch(retValKnown_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {

            if(rba_FeeFs1x_Reorg_reorgKnown_isSoftOngoing())
            {
                // soft reorg is pending but interruptible; repeat this state during the next background cycle
                // no state transition --> don't call the reorgKnown init function again
                retVal_en = rba_FeeFs1x_JobOK_e;
            }
            else
            {
                // known reorg is finished successfully, switch to unknown reorg
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_unknown_e);
                retVal_en = rba_FeeFs1x_Pending_e;
            }

        }break;
        case rba_FeeFs1x_JobFailed_e:
        {
            // sector overflow occured, switch to overflow handler state
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_sectorOverFlowHandler_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Pending_e:
        {
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            // error during reorg --> restart the whole reorg
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_checkAndFillSect0End_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;

        default:
        {
            //unexpected return value
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseSectorDo_unknown
 * statefunction of reorganiseSectorDo executing the unknown block reorg
 * Errors will be never reported and will always cause a restart of the reorg
 * If reorg can never be finished this may cause an endless loop of reorgs
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_unknown(rba_FeeFs1x_Reorg_stm_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    if(rba_FeeFs1x_Prv_isReorgUnknown() || rba_FeeFs1x_Prv_isSurvivalActive())
    {
        rba_FeeFs1x_RetVal_ten retValInner_en;
        if(FEE_PRV_LIBENTRY)
        {
            rba_FeeFs1x_Reorg_reorgUnknown(fsm_pst->isSoftReorgOngoing_b);
        }
        /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
        retValInner_en = rba_FeeFs1x_Reorg_reorgUnknownDo();

        switch(retValInner_en)
        {
            case rba_FeeFs1x_JobOK_e:
            {
                if(rba_FeeFs1x_Reorg_reorgUnknown_isSoftOngoing())
                {
                    // soft reorg is pending but unknown reorg is interruptible
                    // repeat this state during the next background cycle
                    // no state transition --> don't call the reorgUnknown init function again
                    retVal_en = rba_FeeFs1x_JobOK_e;
                }
                else
                {
                    // unknown reorg is finished successfully, switch to end
                    FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_end_e);
                    retVal_en = rba_FeeFs1x_Pending_e;
                }
            }break;
            case rba_FeeFs1x_JobFailed_e:
            {
                // sector overflow occured, switch to overflow handler state
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_sectorOverFlowHandler_e);
                retVal_en = rba_FeeFs1x_Pending_e;
            }break;
            case rba_FeeFs1x_Pending_e:
            {
                retVal_en = rba_FeeFs1x_Pending_e;
            }break;
            case rba_FeeFs1x_ErrorExternal_e:
            case rba_FeeFs1x_ErrorInternal_e:
            {
                // error during reorg --> restart the whole reorg
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_checkAndFillSect0End_e);
                retVal_en = rba_FeeFs1x_Pending_e;
            }break;

            default:
            {
                //unexpected return value
                retVal_en = rba_FeeFs1x_ErrorInternal_e;
            }break;
        }
    }
    else
    {
        FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_end_e);
        retVal_en = rba_FeeFs1x_Pending_e;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseSectorDo_sectorOverflow
 * statefunction of reorganiseSectorDo handling sector overflows
 * External errors will be never reported and will always cause a restart of the reorg
 * If reorg can never be finished this may cause an endless loop of reorgs
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_sectorOverflow(rba_FeeFs1x_Reorg_stm_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValKnown_en;

    if(0u == fsm_pst->sectorOverflowAttemptCtr_u8)
    {
        //This is the first attempt to come out of sector overflow, so proceed with recovery attempt
        if(FEE_PRV_LIBENTRY)
        {
            rba_FeeFs1x_Reorg_repairSectOverflow();
        }
        retValKnown_en = rba_FeeFs1x_Reorg_repairSectOverflowDo();

        switch(retValKnown_en)
        {
            case rba_FeeFs1x_Pending_e:
            case rba_FeeFs1x_ErrorInternal_e:
            {
                retVal_en = retValKnown_en;
            }break;
            case rba_FeeFs1x_JobOK_e:
            {
                // This is first attempt to come out of memory full, restart the reorg
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_checkAndFillSect0End_e);
                fsm_pst->sectorOverflowAttemptCtr_u8++;
                retVal_en = rba_FeeFs1x_Pending_e;
            }break;
            case rba_FeeFs1x_ErrorExternal_e:
            {
                // external error during execution --> restart the sector overflow handler
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_sectorOverFlowHandler_e);
                retVal_en = rba_FeeFs1x_Pending_e;
            }break;
            default:
            {
                //unexpected return value
                retVal_en = rba_FeeFs1x_ErrorInternal_e;
            }break;
        }
    }
    else
    {
        // This is second attempt of recovery, do not proceed with recovery, instead just continue to end the reorganisation
        FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_stm_end_e);
        fsm_pst->sectorOverflowAttemptCtr_u8++;
        retVal_en = rba_FeeFs1x_Pending_e;
    }
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseSectorDo_end
 * statefunction of reorganiseSectorDo executing the final steps of the sector reorganisation
 *
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e       : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e         : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorganiseSectorDo_end(rba_FeeFs1x_Reorg_stm_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValMark_en;
    Std_ReturnType         retValUpdatePages_en;

    if(FEE_PRV_LIBENTRY)
    {
        // trigger the marker write
        rba_FeeFs1x_Sector_markReady4Erase(RBA_FEEFS1X_REORG_LOGSECTOR_TO_BE_REORGED);
    }

    // Cyclic Do function Call
    retValMark_en = rba_FeeFs1x_Sector_markSectorDo();

    //evaluate the result
    switch(retValMark_en)
    {
        /* case JobFailed: writing of the R2E marker in flash failed, but state in RAM is set
           if in this driving cycle an erase is triggered, sector will be erased, due to the correct state in RAM
           if a reset occurs, complete reorg will be reexecuted, and sector will be finally detected again as R2E
           -> treat this case as if it was JobOK */
        case rba_FeeFs1x_JobFailed_e:
        case rba_FeeFs1x_JobOK_e:
        {
            // reset the soft reorg flag
            fsm_pst->isSoftReorgOngoing_b = FALSE;

            // marker write finished successfully; update pages
            retValUpdatePages_en = rba_FeeFs1x_Reorg_updatePages(RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR);

            // on second attempt of sector overflow, there could be one block not transferred and leading to block loss
            // this is a known limitation and so continue with the reordering of the sector and finishing the reorganisation successfully
            if ((E_OK == retValUpdatePages_en) || (1u < fsm_pst->sectorOverflowAttemptCtr_u8))
            {
                // reorder sector states
                rba_FeeFs1x_Sector_reorderLogSect0();
                retVal_en = rba_FeeFs1x_JobOK_e;
            }
            else
            {
                // error during update of pages. return error, to restart complete reorganisation.
                retVal_en = rba_FeeFs1x_ErrorInternal_e;
            }
        }break;

        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            retVal_en = retValMark_en;
        }break;

        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseKnown
 * job init function for executing the known block reorg
 * \return  is the job accepted?
 * \retval  E_OK     : job accepted, do function allowed to be called
 * \retval  E_NOT_OK : job not accepted, do not call the do function
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_Reorg_reorgKnown(boolean isSoftReorg_b)
{
    // no soft reorg is ongoing; reset the statemachine
    rba_FeeFs1x_Reorg_Known_data_st.nextBlockIndex_u16 = 0u;

    rba_FeeFs1x_Reorg_Known_data_st.state_en = rba_FeeFs1x_Reorg_Known_stm_selectBlk_e;
    rba_FeeFs1x_Reorg_Known_data_st.entry_b = TRUE;

    rba_FeeFs1x_Reorg_Known_data_st.isSoftReorgOngoing_b = isSoftReorg_b;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseKnownDo
 * job do function for executing the known block reorg
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgKnownDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    switch(rba_FeeFs1x_Reorg_Known_data_st.state_en)
    {
        case rba_FeeFs1x_Reorg_Known_stm_selectBlk_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgKnownDo_selectBlk(&rba_FeeFs1x_Reorg_Known_data_st);
        }break;
        case rba_FeeFs1x_Reorg_Known_stm_searchBlk_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgKnownDo_searchBlk(&rba_FeeFs1x_Reorg_Known_data_st);
        }break;
        case rba_FeeFs1x_Reorg_Known_stm_checkReq_e :
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgKnownDo_checkReq(&rba_FeeFs1x_Reorg_Known_data_st);
        }break;
        case rba_FeeFs1x_Reorg_Known_stm_copy1_e     :
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_reorgKnownDo_copy1(&rba_FeeFs1x_Reorg_Known_data_st);
        }break;
        case rba_FeeFs1x_Reorg_Known_stm_copy2_e     :
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_reorgKnownDo_copy2(&rba_FeeFs1x_Reorg_Known_data_st);
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    if((retVal_en != rba_FeeFs1x_Pending_e) && !(rba_FeeFs1x_Reorg_Known_data_st.isSoftReorgOngoing_b))
    {
        rba_FeeFs1x_Reorg_Known_data_st.state_en = rba_FeeFs1x_Reorg_Known_stm_idle_e;
    }

    return retVal_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgKnownDo_selectBlk
 * statefunction of reorgKnownDo
 * selects the next known block for checking the reorg necessity
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgKnownDo_selectBlk(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    fsm_pst->currentBlockIndex_u16 = fsm_pst->nextBlockIndex_u16;
    fsm_pst->nextBlockIndex_u16++;

    if(fsm_pst->currentBlockIndex_u16 < RBA_FEEFS1X_PRV_CFG_NR_OF_BLOCKS)
    {
        boolean cpyHasRedBitActive_b;

        // block is to be checked for reorg necessity

        // if the block is configured as redundant block, search for two copies instead of one
        if(E_OK == rba_FeeFs1x_CacheKwn_isCachedCopyRedundantBitActive(fsm_pst->currentBlockIndex_u16, &cpyHasRedBitActive_b))
        {
            // cache element redundancy extraction successful
            fsm_pst->isRedundantBlock_b = cpyHasRedBitActive_b;

            // switch to search that block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_searchBlk_e);

            if(fsm_pst->isSoftReorgOngoing_b)
            {
                // on soft reorg, pause for the possibility of accepting jobs
                retVal_en = rba_FeeFs1x_JobOK_e;
            }
            else
            {
                // on hard reorg, directly continue with the search during the next cycle
                retVal_en = rba_FeeFs1x_Pending_e;
            }

        }
        else
        {
            // cache element is not allowed to be accessed.
            // Either an OOB against the RBA_FEEFS1X_PRV_CFG_NR_OF_BLOCKS occured( catched at upper position)
            // or the current block doesn't have a valid cache entry.

            // no cache entry found --> reenter the state to select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }
    }
    else
    {
        // end of known block reorg reached
        // reset the soft reorg status
        fsm_pst->isSoftReorgOngoing_b = FALSE;

        retVal_en = rba_FeeFs1x_JobOK_e;
    }
    return retVal_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgKnownDo_searchBlk
 * statefunction of reorgKnownDo
 * searches block copies of the current block
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgKnownDo_searchBlk(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en;

    if(FEE_PRV_LIBENTRY)
    {
        if(fsm_pst->isRedundantBlock_b)
        {
            // for blocks the latest known copy is redundant, search for the 2 newest copies
            rba_FeeFs1x_Searcher_SR_find2LatestCopies_Known(fsm_pst->currentBlockIndex_u16);
        }
        else
        {
            // for blocks the latest known copy isn't redundant, search only the latest consistent copy
            rba_FeeFs1x_Searcher_SR_find1LatestConsistentCopy_Known(fsm_pst->currentBlockIndex_u16);
        }
    }

    // Cyclic Do function Call
    retValSearch_en = rba_FeeFs1x_Searcher_findCopiesDo();

    switch(retValSearch_en)
    {
        case rba_FeeFs1x_Searcher_RetVal_Pending_e:
        {
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Searcher_RetVal_NoCopyFound_e:
        {
            // no copy found --> no reorg necessity. Switch state to select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Searcher_RetVal_OneCopyFound_e:
        case rba_FeeFs1x_Searcher_RetVal_TwoCopiesFound_e:
        {
            // copie(s) were found --> check reorg necessity for this block
            fsm_pst->retValSearch_en = retValSearch_en;
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_checkReq_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Searcher_RetVal_ErrorInternal_e:
        default:
        {
            // unexpected search return or error
            // --> exit the known reorg, restart the whole reorg
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgKnownDo_checkReq
 * statefunction of reorgKnownDo
 * checks based on the search result whether the block needs to be reorged (0/1/2 times)
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgKnownDo_checkReq(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst)
{
    uint8 ctrCopiesRequired_u8 = 0u;
    uint8 ctrCopiesReqForRed_u8;
    rba_FeeFs1x_RetVal_ten retVal_en;

    uint32 pageNrLatest_u32;

    pageNrLatest_u32 = rba_FeeFs1x_BC_getPageNo(rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);

    // access the pageNr
    if(pageNrLatest_u32 < RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR)
    {
        ctrCopiesRequired_u8++;
    }

    rba_FeeFs1x_Reorg_reorgKnownDo_checkReq_checkRedCpy(fsm_pst , &ctrCopiesReqForRed_u8);

    // both native and redundant checks were successful
    ctrCopiesRequired_u8 += ctrCopiesReqForRed_u8;
    // select the required action based on the amount of copies to be transferred

    switch(ctrCopiesRequired_u8)
    {
        case 0u:
        {
            // no latest copy of this block is located within the sector 0
            // continue with the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case 1u:
        {
            // one transfer of the latest consistent copy required
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_copy1_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case 2u:
        {
            // two transfers of the latest consistent copy required
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_copy2_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        default:
        {
            // unexpected amount of writes
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgKnownDo_checkReq_checkRedCpy
 * subfunction of  of rba_FeeFs1x_Reorg_reorgKnownDo_checkReq
 * checks the redundant copy reorg necessity
 * \param   fsm_pcst : reference to stm data
 * \param   cntcpiesReqForRed_pu8: call by reference return for the amount of copies required for the redundant copy
 * \return  void
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_Reorg_reorgKnownDo_checkReq_checkRedCpy(
        rba_FeeFs1x_Reorg_Known_data_tst const * fsm_pcst ,
        uint8 * cntcpiesReqForRed_pu8)
{
    uint32 pageNrRed_u32;

    if(fsm_pcst->isRedundantBlock_b)
    {
        if(fsm_pcst->retValSearch_en == rba_FeeFs1x_Searcher_RetVal_TwoCopiesFound_e)
        {
            // two copies were found, get the pageNr of the redundant copy

            pageNrRed_u32 = rba_FeeFs1x_BC_getPageNo(rba_FeeFs1x_BC_Cpy_SectorReorg_Redundant_e);

            // access the pageNrRed and alter the amount of required copies
            if(pageNrRed_u32 < RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR)
            {
                *cntcpiesReqForRed_pu8 = 1u;
            }
            else
            {
                *cntcpiesReqForRed_pu8 = 0u;
            }
        }
        else
        {
            // redundant copy should have been found, write once for this missing copy
            *cntcpiesReqForRed_pu8 = 1u;
        }
    }
    else
    {
        // override the error flag; non-redundant copies don't need to get the redundant BC page
        *cntcpiesReqForRed_pu8 = 0u;
    }
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgKnownDo_copy1
 * statefunction of reorgKnownDo
 * 1-time transfer for the current block
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgKnownDo_copy1(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValCopy_en;

    if(FEE_PRV_LIBENTRY)
    {
        rba_FeeFs1x_Reorg_transfer1Copy(TRUE, fsm_pst->currentBlockIndex_u16);
    }

    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValCopy_en = rba_FeeFs1x_Reorg_transfer1CopyDo();

    switch(retValCopy_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // copying finished successfully, select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_JobFailed_e:
            // sector overflow detected, stop the known reorg
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            retVal_en = retValCopy_en;
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;

}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgKnownDo_copy2
 * statefunction of reorgKnownDo
 * 2-time transfer for the current block
 * \param   fsm_pst : reference to stm data
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgKnownDo_copy2(rba_FeeFs1x_Reorg_Known_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValCopy_en;

    if(FEE_PRV_LIBENTRY)
    {
        rba_FeeFs1x_Reorg_transfer2Copies(TRUE, fsm_pst->currentBlockIndex_u16);
    }

    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValCopy_en = rba_FeeFs1x_Reorg_transfer2CopiesDo();


    switch(retValCopy_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // copying finished successfully, select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_Known_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_JobFailed_e:
            // sector overflow detected, stop the known reorg
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            retVal_en = retValCopy_en;
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;

}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgKnown_isSoftOngoing
 * function returing whether the known reorg is ongoing during a soft reorg
 * \return  is the soft reorg ongoing?
 * \retval  TRUE  : call the function again during the next background cycle
 * \retval  FALSE : job exited completely
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE boolean  rba_FeeFs1x_Reorg_reorgKnown_isSoftOngoing(void)
{
    return rba_FeeFs1x_Reorg_Known_data_st.isSoftReorgOngoing_b;
}



/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer1Copy
 * job init function for transferring one block copy during reorg
 * \param   isKnownBlock_b : is the block a known or unknown block
 * \param   feeIdx_u16     : fee index of the block
 * \seealso
 * \usedresources
 *********************************************************************
 */
static void rba_FeeFs1x_Reorg_transfer1Copy(boolean isKnownBlock_b, uint16 feeIdx_u16)
{
    rba_FeeFs1x_Reorg_transfer1Copy_data_st.state_en = rba_FeeFs1x_Reorg_transferCopies_stm_init1_e;
    rba_FeeFs1x_Reorg_transfer1Copy_data_st.entry_b = TRUE;

    rba_FeeFs1x_Reorg_transfer1Copy_data_st.feeIdx_u16 = feeIdx_u16;
    rba_FeeFs1x_Reorg_transfer1Copy_data_st.allowedRetries_u8 = RBA_FEEFS1X_PRV_MAX_RD_WR_COMP_RETRIES;
    rba_FeeFs1x_Reorg_transfer1Copy_data_st.isKnownBlock_b = isKnownBlock_b;

}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer1CopyDo
 *  job do function for transferring one block copy during reorg
 * \return  job result of the copy operation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : copy created
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
static rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    switch(rba_FeeFs1x_Reorg_transfer1Copy_data_st.state_en)
    {
        case rba_FeeFs1x_Reorg_transferCopies_stm_init1_e :
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_transfer1CopyDo_init1(&rba_FeeFs1x_Reorg_transfer1Copy_data_st);
        }break;
        case rba_FeeFs1x_Reorg_transferCopies_stm_copy1_e :
        {
            retVal_en = rba_FeeFs1x_Reorg_transfer1CopyDo_copy1(&rba_FeeFs1x_Reorg_transfer1Copy_data_st);
        }break;
        case rba_FeeFs1x_Reorg_transferCopies_stm_error1_e :
        {
            retVal_en = rba_FeeFs1x_Reorg_transfer1CopyDo_error1(&rba_FeeFs1x_Reorg_transfer1Copy_data_st);
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    if(retVal_en != rba_FeeFs1x_Pending_e)
    {
        rba_FeeFs1x_Reorg_transfer1Copy_data_st.state_en = rba_FeeFs1x_Reorg_transferCopies_stm_idle_e;

        // finalize the copies before exit
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_SectorReorg_Redundant_e);
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e);
    }

    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer1CopyDo_init1
 *  statefunction of transfer1Copy initing the new block copy
 * \return  job result of the copy operation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : copy created
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo_init1(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValInit_en;
    if(FEE_PRV_LIBENTRY)
    {
        uint16 length_u16;
        uint16 persID_u16;
        uint8 DFLASHStatusByte_u8;

        length_u16 =          rba_FeeFs1x_BC_getBlkLength (rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);
        persID_u16 =          rba_FeeFs1x_BC_getPersID   (rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);
        DFLASHStatusByte_u8 = rba_FeeFs1x_BC_getBlkDFLASHStatusByte (rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);

        rba_FeeFs1x_BC_initCopySectReorgWr
                (
                        rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e,
                        length_u16,
                        persID_u16,
                        (uint16)DFLASHStatusByte_u8
                );
    }

    /* Cyclic Do function Call */
    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValInit_en = rba_FeeFs1x_BC_initCopySectReorgWrDo();

    switch(retValInit_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // init done, start the transfer
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_copy1_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_JobFailed_e:
            // sector overflow detected, stop the known reorg
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            retVal_en = retValInit_en;
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;

}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer1CopyDo_copy1
 *  statefunction of transfer1Copy copying Fls2Fls
 * \return  job result of the copy operation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : copy created
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo_copy1(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValWr_en;

    if(FEE_PRV_LIBENTRY)
    {
        // always execute in fast mode -> in Fee_Medium only the blank check before writing will be skipped
        rba_FeeFs1x_BC_wrFls2Fls(rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e,
                                 rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e,
                                 FALSE, 0x0,
                                 FEE_RB_WRITEJOB_WRITE_VERIFY_E);
    }

    /* Cyclic Call for Do Function */
    retValWr_en = rba_FeeFs1x_BC_wrFls2FlsDo();

    switch(retValWr_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // write done, update chache
            rba_FeeFs1x_Reorg_transferCopyDo_updCache
            (
                    rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e,
                    fsm_pst->feeIdx_u16,
                    fsm_pst->isKnownBlock_b
            );
            retVal_en = rba_FeeFs1x_JobOK_e;
        }break;
        case rba_FeeFs1x_ErrorExternal_e:
        {
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_error1_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            retVal_en = retValWr_en;
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer1CopyDo_error1
 * statefunction of rba_FeeFs1x_Reorg_transfer1CopyDo
 * \param   fsm_pst : statemachine data pointer
 * \return  job result
 * \retval  rba_FeeFs1x_Pending_e: ongoing, call again during next cycle
 * \retval  rba_FeeFs1x_ErrorExternal_e: transfer of the copy failed
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer1CopyDo_error1(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    // check whether a retry is allowed
    if(fsm_pst->allowedRetries_u8 > 0u)
    {
        fsm_pst->allowedRetries_u8--;
        // retry counter doesn't forbid another retry --> restart the write
        retVal_en = rba_FeeFs1x_Pending_e;
        FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_init1_e);
    }
    else
    {
        // retry maximum reached, exit the job with an error
        retVal_en = rba_FeeFs1x_ErrorExternal_e;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transferCopyDo_updCache
 * Function for updating the cache after the transfer of the copy to new sector. Same function could be used for both
 * first copy and second copy transfer.
 *
 * \param   copy_en     : Block copy object which was just transferred for cache update is required
 * \param   feeIndex_u16: Fee index of the block was just transferred
 * \return  void
 * \seealso
 * \usedresources
 *********************************************************************
 */
static void rba_FeeFs1x_Reorg_transferCopyDo_updCache(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en,
        uint16 feeIndex_u16 ,
        boolean isKnownBlock_b)
{
    uint32 pageNr_u32;
    boolean isRed_b;

    pageNr_u32 = rba_FeeFs1x_BC_getPageNo(copy_en);
    isRed_b    = rba_FeeFs1x_BC_getCpyRedBit(copy_en);

    // Job finished successfully, update the cache to finalize the operation
    if(isKnownBlock_b)
    {
        // known cache update
        rba_FeeFs1x_CacheKwn_addNewerCopy(
                feeIndex_u16,
                TRUE,
                pageNr_u32,
                isRed_b);
    }
    else
    {
        // unknown cache update
        rba_FeeFs1x_CacheUnkwn_addNewerCopy(feeIndex_u16, TRUE, pageNr_u32, isRed_b);
    }
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer2Copies
 *  job init function for copying a block copy twice during reorg
 * \param   isKnownBlock_b : is the block a known or unknown block
 * \param   feeIdx_u16     : fee index of the block
 * \seealso
 * \usedresources
 *********************************************************************
 */
static void rba_FeeFs1x_Reorg_transfer2Copies(boolean isKnownBlock_b, uint16 feeIdx_u16)
{
    rba_FeeFs1x_Reorg_transfer2Copies_data_st.state_en = rba_FeeFs1x_Reorg_transferCopies_stm_init1_e;
    rba_FeeFs1x_Reorg_transfer2Copies_data_st.entry_b = TRUE;

    rba_FeeFs1x_Reorg_transfer2Copies_data_st.feeIdx_u16 = feeIdx_u16;
    rba_FeeFs1x_Reorg_transfer2Copies_data_st.allowedRetries_u8 = RBA_FEEFS1X_PRV_MAX_RD_WR_COMP_RETRIES;
    rba_FeeFs1x_Reorg_transfer2Copies_data_st.isKnownBlock_b = isKnownBlock_b;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer2CopiesDo
 *  job do function for copying a block copy twice during reorg
 * \return  job result of the copy operation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : copy created
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
static rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo(void)
{
    rba_FeeFs1x_Reorg_transferCopies_stm_ten state_en = rba_FeeFs1x_Reorg_transfer2Copies_data_st.state_en;
    rba_FeeFs1x_Reorg_transferCopy_ten copy_en;
    rba_FeeFs1x_RetVal_ten retVal_en;

    switch(state_en)
    {
        case rba_FeeFs1x_Reorg_transferCopies_stm_init1_e :
        case rba_FeeFs1x_Reorg_transferCopies_stm_copy1_e :
        case rba_FeeFs1x_Reorg_transferCopies_stm_error1_e :
        {
            copy_en = rba_FeeFs1x_Reorg_transferCopy_1_e;
        } break;
        case rba_FeeFs1x_Reorg_transferCopies_stm_init2_e :
        case rba_FeeFs1x_Reorg_transferCopies_stm_copy2_e :
        case rba_FeeFs1x_Reorg_transferCopies_stm_error2_e :
        {
            copy_en = rba_FeeFs1x_Reorg_transferCopy_2_e;
        } break;
        default:
        {
            state_en = rba_FeeFs1x_Reorg_transferCopies_stm_idle_e;
        } break;

    }

    switch(state_en)
    {
        case rba_FeeFs1x_Reorg_transferCopies_stm_init1_e :
        case rba_FeeFs1x_Reorg_transferCopies_stm_init2_e :
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_transfer2CopiesDo_init(&rba_FeeFs1x_Reorg_transfer2Copies_data_st,copy_en);
        }break;
        case rba_FeeFs1x_Reorg_transferCopies_stm_copy1_e :
        case rba_FeeFs1x_Reorg_transferCopies_stm_copy2_e :
        {
            retVal_en = rba_FeeFs1x_Reorg_transfer2CopiesDo_copy(&rba_FeeFs1x_Reorg_transfer2Copies_data_st,copy_en);
        }break;
        case rba_FeeFs1x_Reorg_transferCopies_stm_error1_e :
        case rba_FeeFs1x_Reorg_transferCopies_stm_error2_e :
        {
            retVal_en = rba_FeeFs1x_Reorg_transfer2CopiesDo_error(&rba_FeeFs1x_Reorg_transfer2Copies_data_st,copy_en);
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;

    }

    if(retVal_en != rba_FeeFs1x_Pending_e)
    {
        rba_FeeFs1x_Reorg_transfer2Copies_data_st.state_en = rba_FeeFs1x_Reorg_transferCopies_stm_idle_e;

        // finalize the copies before exit
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_SectorReorg_Redundant_e);
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e);
        rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_SectorReorg_NewRedundant_e);
    }

    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer2CopiesDo_init
 *  statefunction of transfer2Copies initing the earlier of both new copies
 * \param   type_en : Block copy object type to be handeled
 * \return  job result of the copy operation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : copy created
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */

LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo_init(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst, rba_FeeFs1x_Reorg_transferCopy_ten copy_en)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValInit_en;
    if(FEE_PRV_LIBENTRY)
    {
        uint16 length_u16;
        uint16 persID_u16;
        uint8 DFLASHStatusByte_u8;
        rba_FeeFs1x_BC_Cpy_blockCopyObject_ten BlockCopyObj;

        length_u16          = rba_FeeFs1x_BC_getBlkLength           (rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);
        persID_u16          = rba_FeeFs1x_BC_getPersID              (rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);
        DFLASHStatusByte_u8 = rba_FeeFs1x_BC_getBlkDFLASHStatusByte (rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);

        if(rba_FeeFs1x_Reorg_transferCopy_1_e == copy_en)
        {
            BlockCopyObj = rba_FeeFs1x_BC_Cpy_SectorReorg_NewRedundant_e;
        }
        else
        {
            BlockCopyObj = rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e;
        }

        rba_FeeFs1x_BC_initCopySectReorgWr
                (
                        BlockCopyObj,
                        length_u16,
                        persID_u16,
                        (uint16)DFLASHStatusByte_u8
                );
    }

    /* Cyclic call for Do function */
    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValInit_en = rba_FeeFs1x_BC_initCopySectReorgWrDo();

    switch(retValInit_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // init done, start the transfer
            if(rba_FeeFs1x_Reorg_transferCopy_1_e == copy_en)
            {
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_copy1_e);
            }
            else
            {
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_copy2_e);
            }
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_JobFailed_e:
        case rba_FeeFs1x_ErrorExternal_e:
        {
            retVal_en = retValInit_en;
        }break;
        case rba_FeeFs1x_ErrorInternal_e:
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;

}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer2CopiesDo_copy
 *  statefunction of transfer2Copies writing the earlier of both new copies
 * \param   type_en : Block copy object type to be handeled
 * \return  job result of the copy operation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : copy created
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo_copy(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst,rba_FeeFs1x_Reorg_transferCopy_ten copy_en)
{
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten BlockCopyObj;
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValWr_en;

    if(rba_FeeFs1x_Reorg_transferCopy_1_e == copy_en)
    {
        BlockCopyObj = rba_FeeFs1x_BC_Cpy_SectorReorg_NewRedundant_e;
    }
    else
    {
        BlockCopyObj = rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e;
    }

    if(FEE_PRV_LIBENTRY)
    {
        // always execute in fast mode -> in Fee_Medium only the blank check before writing will be skipped
        rba_FeeFs1x_BC_wrFls2Fls(rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e,
                                            BlockCopyObj,
                                            FALSE, 0x0,
                                            FEE_RB_WRITEJOB_WRITE_VERIFY_E);
    }

    /* Cyclic call for Do function */
    retValWr_en = rba_FeeFs1x_BC_wrFls2FlsDo();

    switch(retValWr_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // write done, update chache
            rba_FeeFs1x_Reorg_transferCopyDo_updCache
            (
                    BlockCopyObj,
                    fsm_pst->feeIdx_u16,
                    fsm_pst->isKnownBlock_b
            );
            if(rba_FeeFs1x_Reorg_transferCopy_1_e == copy_en)
            {
                // go to next copy transfer
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_init2_e);
                retVal_en = rba_FeeFs1x_Pending_e;
            }
            else
            {
                retVal_en = rba_FeeFs1x_JobOK_e;
            }
        }break;
        case rba_FeeFs1x_ErrorExternal_e:
        {
            // switch to the error handler
            if(rba_FeeFs1x_Reorg_transferCopy_1_e == copy_en)
            {
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_error1_e);
            }
            else
            {
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_error2_e);
            }
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Pending_e:
        {
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_ErrorInternal_e:
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_transfer2CopiesDo_error
 * statefunction of rba_FeeFs1x_Reorg_transfer2CopiesDo
 * \param   type_en : Block copy object type to be handeled
 * \param   fsm_pst : statemachine data pointer
 * \return  job result
 * \retval  rba_FeeFs1x_Pending_e: ongoing, call again during next cycle
 * \retval  rba_FeeFs1x_ErrorExternal_e: transfer of the copy failed
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_transfer2CopiesDo_error(rba_FeeFs1x_Reorg_transferCopies_data_tst * fsm_pst, rba_FeeFs1x_Reorg_transferCopy_ten copy_en)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    // check whether a retry is allowed
    if(fsm_pst->allowedRetries_u8 > 0u)
    {
        fsm_pst->allowedRetries_u8--;
        // retry counter doesn't forbid another retry --> restart the write
        retVal_en = rba_FeeFs1x_Pending_e;

        if(rba_FeeFs1x_Reorg_transferCopy_1_e == copy_en)
        {
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_init1_e);
        }
        else
        {
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_transferCopies_stm_init2_e);
        }
    }
    else
    {
        // retry maximum reached, exit the job with an error
        retVal_en = rba_FeeFs1x_ErrorExternal_e;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_checkHSRNecessity
 * \param   lastPageOfNewBlock_u32 : last page number the block would occupy
 * \return  returns whether an HSR execution is required due to HSR threshold crossing
 * \retval  TRUE  : HSR needs to be executed
 * \retval  FALSE : HSR is not required
 * \seealso
 * \usedresources
 *********************************************************************
 */
boolean rba_FeeFs1x_Reorg_checkHSRNecessity(uint32 lastPageOfNewBlock_u32)
{
    boolean retVal_b;

    if(lastPageOfNewBlock_u32 < RBA_FEEFS1X_PRV_CFG_HSR_THRESHOLD_PAGE)
    {
        // The last page is not crossing the HSR
        retVal_b = FALSE;
    }
    else
    {
        // the last page is crossing the HSR
        retVal_b = TRUE;
    }

    return retVal_b;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_isSoftReorgRequired
 *
 * \return returns whether a soft reorg should be executed in background
 * \retval  TRUE : soft reorg should be executed
 * \retval  FALSE: soft reorg doesn't need to be executed
 * \seealso
 * \usedresources
 *********************************************************************
 */
boolean rba_FeeFs1x_Reorg_isSoftReorgRequired(void)
{
    boolean retVal_b;
    uint32 currWrPage_u32;

    currWrPage_u32 = rba_FeeFs1x_PAMap_getCurrWrPage();

    // if the current write page is succeeding the threshold, return TRUE
    if(currWrPage_u32 >= RBA_FEEFS1X_PRV_CFG_SSR_THRESHOLD_PAGE)
    {
        retVal_b = TRUE;
    }
    else
    {
        retVal_b = FALSE;
    }

    return retVal_b;
}

/**
 *********************************************************************
 * call subscriber functions
 * \param   amountOfPages_u32: reduction number of pages after sector reorganisation
 * \return  return of all subscriber functions
 * \retval  E_OK: all subscriber functions returned without an error
 * \retval  E_NOT_OK: at least one subscriber function returned with an error
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE Std_ReturnType rba_FeeFs1x_Reorg_updatePages(uint32 amountOfPages_u32)
{
    Std_ReturnType PAMap_retVal_en;
    Std_ReturnType retValSearcher_en;
    Std_ReturnType retValCacheKwn_en;
    Std_ReturnType retValCacheUnkwn_en;
    Std_ReturnType retVal_en;

    PAMap_retVal_en = rba_FeeFs1x_PAMap_reduceOwnPages(amountOfPages_u32);
    rba_FeeFs1x_BC_reduceOwnPages(amountOfPages_u32);
    retValSearcher_en = rba_FeeFs1x_Searcher_reduceOwnPages(amountOfPages_u32);
    retValCacheKwn_en = rba_FeeFs1x_CacheKwn_reduceOwnPages(amountOfPages_u32);
    retValCacheUnkwn_en = rba_FeeFs1x_CacheUnkwn_reduceOwnPages(amountOfPages_u32);

    if((E_OK == PAMap_retVal_en) && (E_OK == retValSearcher_en) && (E_OK == retValCacheKwn_en) && (E_OK == retValCacheUnkwn_en))
    {
        retVal_en = E_OK;
    }
    else
    {
        retVal_en = E_NOT_OK;
    }

    return(retVal_en);
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_repairSectOverflow
 *  job init function for handling robust sector overflows
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_Reorg_repairSectOverflow(void)
{
    rba_FeeFs1x_Reorg_repairSectOverflow_data_st.state_en = rba_FeeFs1x_Reorg_repairSectOverflow_stm_eraseClone_e;
    rba_FeeFs1x_Reorg_repairSectOverflow_data_st.entry_b = TRUE;
}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_repairSectOverflowDo
 *  job do function for handling robust sector overflows
 * \return  job result to be returned by the job do function
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobFailed_e : overflow cleaned up, reorg can be restarted
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_repairSectOverflowDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    switch(rba_FeeFs1x_Reorg_repairSectOverflow_data_st.state_en)
    {
        case rba_FeeFs1x_Reorg_repairSectOverflow_stm_eraseClone_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_repairSectOverflowDo_erase(&rba_FeeFs1x_Reorg_repairSectOverflow_data_st);
        }break;
        case rba_FeeFs1x_Reorg_repairSectOverflow_stm_cacheBuildup_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_repairSectOverflowDo_cacheBuildup(&rba_FeeFs1x_Reorg_repairSectOverflow_data_st);
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    if(retVal_en != rba_FeeFs1x_Pending_e)
    {
        rba_FeeFs1x_Reorg_repairSectOverflow_data_st.state_en = rba_FeeFs1x_Reorg_repairSectOverflow_stm_idle_e;
    }
    return retVal_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_repairSectOverflowDo_erase
 *  statefunction of repairSectOverflow
 *  erases the latest sector
 * \return  job result to be returned by the job do function
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : overflow cleaned up, reorg can be restarted
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_repairSectOverflowDo_erase(rba_FeeFs1x_Reorg_repairSectOverflow_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValErase_en;
    if(FEE_PRV_LIBENTRY)
    {
        rba_FeeFs1x_Sector_erase(RBA_FEEFS1X_PRV_CFG_NR_FLASH_BANKS_AVAILABLE - 1u, TRUE);
    }

    /* Cyclic call the Do function */
    retValErase_en = rba_FeeFs1x_Sector_eraseDo();

    switch (retValErase_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // finished, switch to next state
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_repairSectOverflow_stm_cacheBuildup_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            // map possible return values
            retVal_en = retValErase_en;
        }break;
        // if sector erase fails, it is retried infinite times. No external error is reported
        // so error external must not occur and is mapped to default
        default:
        {
            // unexpected returns
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }


    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_repairSectOverflowDo_cacheBuildup
 *  statefunction of repairSectOverflow
 *  rebuilds the cache for all elements previously stored behind HSR threshold
 * \return  job result to be returned by the job do function
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : overflow cleaned up successfully, reorg can be restarted
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_repairSectOverflowDo_cacheBuildup(rba_FeeFs1x_Reorg_repairSectOverflow_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValInner_en;
    uint32 adr_newWr_u32;

    if(FEE_PRV_LIBENTRY)
    {
        // new write address is the start of the last logical sector
        adr_newWr_u32 = RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR * (RBA_FEEFS1X_PRV_CFG_NR_FLASH_BANKS_AVAILABLE - 1u);
        rba_FeeFs1x_PAMap_setCurrWrPage(adr_newWr_u32);

        // invalidate cache entries pointing to the last logical sector
        // invalidate cache entry with highest page no left, because to avoid a data CRC fail/block search when this entry was
        // pointing to an overlapping block, which got destroyed partially
        rba_FeeFs1x_CacheKwn_invalidateCacheEntriesFromPageNoAndHighestPageNoLeft(adr_newWr_u32);

        // invalidate complete unknown cache
        rba_FeeFs1x_CacheUnkwn_invalidateCompleteCache();

        // after cloning, all already cached unknown blocks (starting from sector 0) are deleted,
        // so unknown cache build up has to be completely restarted from sector 0
        rba_FeeFs1x_Searcher_resetSearchForUnknownCacheBuildup();

        // rebuild the cache for the recently invalidated copies
        (void) rba_FeeFs1x_Searcher_buildupCache(FALSE);
    }

    /* Cyclic call the Do-function */
    retValInner_en = rba_FeeFs1x_Searcher_buildupCacheDo();

    switch (retValInner_en)
    {
        case rba_FeeFs1x_JobOK_e:
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorInternal_e:
        case rba_FeeFs1x_ErrorExternal_e:
        {
            // map possible return values
            retVal_en = retValInner_en;
        }break;
        default:
        {
            // unexpected returns
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknown
 * job init function for executing the unknown block reorg
 * \return  is the job accepted?
 * \retval  E_OK     : job accepted, do function allowed to be called
 * \retval  E_NOT_OK : job not accepted, do not call the do function
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_Reorg_reorgUnknown(boolean isSoftReorg_b)
{
    // no soft reorg is ongoing
    // reset the statemachine to the first state
    rba_FeeFs1x_Reorg_reorgUnknown_data_st.state_en = rba_FeeFs1x_Reorg_reorgUnknown_stm_reorgCachedBlocks_e;
    rba_FeeFs1x_Reorg_reorgUnknown_data_st.entry_b = TRUE;
    rba_FeeFs1x_Reorg_reorgUnknown_data_st.isSoftReorgOngoing_b = isSoftReorg_b;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorganiseKnownDo
 * job do function for executing the unknown block reorg
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    switch(rba_FeeFs1x_Reorg_reorgUnknown_data_st.state_en)
    {
        case rba_FeeFs1x_Reorg_reorgUnknown_stm_checkCacheRebuildReq_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownDo_checkCacheRebuildReq (&rba_FeeFs1x_Reorg_reorgUnknown_data_st);
        }break;
        case rba_FeeFs1x_Reorg_reorgUnknown_stm_cacheRebuild_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownDo_cacheRebuild(&rba_FeeFs1x_Reorg_reorgUnknown_data_st);
        }break;
        case rba_FeeFs1x_Reorg_reorgUnknown_stm_reorgCachedBlocks_e:
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownDo_reorgCachedBlocks(&rba_FeeFs1x_Reorg_reorgUnknown_data_st);
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    // on job exit without running soft reorg, reset the statemachine
    if( (retVal_en != rba_FeeFs1x_Pending_e) && !(rba_FeeFs1x_Reorg_reorgUnknown_data_st.isSoftReorgOngoing_b))
    {
        rba_FeeFs1x_Reorg_reorgUnknown_data_st.state_en = rba_FeeFs1x_Reorg_reorgUnknown_stm_idle_e;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownDo_checkCacheRebuildReq
 * statefunction of reorgUnknownDo
 * Checks the current unknown cache buildup page and state for necessity to execute another buildup in this reorg
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo_checkCacheRebuildReq  (rba_FeeFs1x_Reorg_reorgUnknown_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    if(rba_FeeFs1x_Searcher_isUnknownBlkCacheBuildupRequired())
    {
        // The cache buildup is required
        uint32 pageLimitLastUnknownReorg_u32;
        pageLimitLastUnknownReorg_u32 = rba_FeeFs1x_Searcher_getUnknownBlkReorgLimit();

        // Is the cache built up
        if(pageLimitLastUnknownReorg_u32 < RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR)
        {
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknown_stm_cacheRebuild_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }
        else
        {
            // further rebuild is not required during this reorg, because all blocks with copies in the 0th sector are covered
            fsm_pst->isSoftReorgOngoing_b = FALSE;
            retVal_en = rba_FeeFs1x_JobOK_e;
        }
    }
    else
    {
        // further cache buildup is not required and the cached unknown blocks already are checked before this state
        // reset the soft reorg state
        fsm_pst->isSoftReorgOngoing_b = FALSE;
        retVal_en = rba_FeeFs1x_JobOK_e;
    }
    return retVal_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownDo_cacheRebuild
 * statefunction of reorgUnknownDo
 * executes the unknown cache buildup
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo_cacheRebuild          (rba_FeeFs1x_Reorg_reorgUnknown_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValInner_en;
    if(FEE_PRV_LIBENTRY)
    {
        // free the unknown cache
        rba_FeeFs1x_CacheUnkwn_invalidateCompleteCache();

        // buildup the unknown cache starting at the previous page
        rba_FeeFs1x_Searcher_buildUpUnknownBlkCache();
    }

    // Cyclic call the Do-function
    retValInner_en = rba_FeeFs1x_Searcher_buildUpUnknownBlkCacheDo();

    // evaluate the job result
    switch (retValInner_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // after finishing the cache buildup, reorg all cached copies
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknown_stm_reorgCachedBlocks_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_ErrorExternal_e:

        {
            retVal_en = retValInner_en;
        }break;
        case rba_FeeFs1x_ErrorInternal_e:
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownDo_reorgCachedBlocks
 * statefunction of reorgUnknownDo
 * executes the blockwise check for all cache elements
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownDo_reorgCachedBlocks     (rba_FeeFs1x_Reorg_reorgUnknown_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValInner_en;
    if(FEE_PRV_LIBENTRY)
    {
        // trigger the reorg of all cached elements
        rba_FeeFs1x_Reorg_reorgUnknownCached(fsm_pst->isSoftReorgOngoing_b);
    }
    // state-do: execute the reorg of cached elements
    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValInner_en = rba_FeeFs1x_Reorg_reorgUnknownCachedDo();

    // evaluate the job result
    switch (retValInner_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            if(rba_FeeFs1x_Reorg_reorgUnknownCached_isSoftOngoing())
            {
                // cache check only interrupted due to soft reorg, repeat this state in next background cycle
                retVal_en = rba_FeeFs1x_JobOK_e;
            }
            else
            {
                // cache check finished, check the necessity of further cache buildups
                FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknown_stm_checkCacheRebuildReq_e);
                retVal_en = rba_FeeFs1x_Pending_e;
            }
        }break;
        case rba_FeeFs1x_Pending_e:
        case rba_FeeFs1x_JobFailed_e:
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_ErrorInternal_e:
        {
            // propagate the given return value
            retVal_en = retValInner_en;
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;

        }break;
    }
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknown_isSoftOngoing
 * function returing whether the unknown reorg is ongoing during a soft reorg
 * \return  is the soft reorg ongoing?
 * \retval  TRUE  : call the function again during the next background cycle
 * \retval  FALSE : job exited completely
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE boolean rba_FeeFs1x_Reorg_reorgUnknown_isSoftOngoing(void)
{
    return rba_FeeFs1x_Reorg_reorgUnknown_data_st.isSoftReorgOngoing_b;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCached
 * job init function for checking and if required transferring the cached unknown blocks
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_Reorg_reorgUnknownCached(boolean isSoftReorg_b)
{

    // no soft reorg is ongoing
    // reset the counters to the current cache state
    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.nextCacheIdx_u16 = 0u;
    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.cntCachedElements_u16 = rba_FeeFs1x_CacheUnkwn_getUnknownBlkCacheLevel();

    // init the statemachine
    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.state_en = rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e;
    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.entry_b  = TRUE;
    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.isSoftReorgOngoing_b = isSoftReorg_b;


}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCachedDo
 * job do function to reorg all cached unknown blocks
 * executes the blockwise check for all cache elements
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_Reorg_reorgUnknownCachedDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    switch(rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.state_en)
    {
        case rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownCachedDo_selectBlk(&rba_FeeFs1x_Reorg_reorgUnknownCached_data_st);
        }break;
        case rba_FeeFs1x_Reorg_reorgUnknownCached_stm_searchBlk_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownCachedDo_searchBlk(&rba_FeeFs1x_Reorg_reorgUnknownCached_data_st);
        }break;
        case rba_FeeFs1x_Reorg_reorgUnknownCached_stm_checkReq_e:
        {
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq(&rba_FeeFs1x_Reorg_reorgUnknownCached_data_st);
        }break;
        case rba_FeeFs1x_Reorg_reorgUnknownCached_stm_copy1_e:
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy1(&rba_FeeFs1x_Reorg_reorgUnknownCached_data_st);
        }break;
        case rba_FeeFs1x_Reorg_reorgUnknownCached_stm_copy2_e:
        {
            /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
            retVal_en = rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy2(&rba_FeeFs1x_Reorg_reorgUnknownCached_data_st);
        }break;
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    // as soon as any of the states exits the whole job, reset the state machine to idle
    if((retVal_en != rba_FeeFs1x_Pending_e) && !(rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.isSoftReorgOngoing_b))
    {
        rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.state_en = rba_FeeFs1x_Reorg_reorgUnknownCached_stm_idle_e;
    }

    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCachedDo_selectBlk
 * statefunction of reorgUnknownCachedDo
 * checks how many cached blocks are left unchecked and decides whether all elements are checked
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgUnknownCachedDo_selectBlk(rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    // select the next cache element to be checked
    fsm_pst->currCacheIdx_u16 = fsm_pst->nextCacheIdx_u16;

    // prepare the cycle by selecting the next block to be checked
    fsm_pst->nextCacheIdx_u16++;

    // if the current index is still inbound of the cached copies
    if(fsm_pst->currCacheIdx_u16 < fsm_pst->cntCachedElements_u16)
    {
        Std_ReturnType retValCacheUnkwn_en;
        boolean cpyHasRedBitActive_b = FALSE;     /* The default value is set to avoid warning when there are no redundant blocks configured */

        retValCacheUnkwn_en = rba_FeeFs1x_CacheUnkwn_isCachedCopyRedundantBitActive(fsm_pst->currCacheIdx_u16, &cpyHasRedBitActive_b);

        // block is to be checked for reorg necessity
        // if the block is configured as redundant block, search for two copies instead of one
        if(E_OK == retValCacheUnkwn_en)
        {
            // cache element redundancy extraction successful
            fsm_pst->isRedundantBlock_b = cpyHasRedBitActive_b;

            // switch to search that block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_searchBlk_e);

            if(fsm_pst->isSoftReorgOngoing_b)
            {
                // on soft reorg, pause for the possibility of accepting jobs
                retVal_en = rba_FeeFs1x_JobOK_e;
            }
            else
            {
                // on hard reorg, directly continue with the search during the next cycle
                retVal_en = rba_FeeFs1x_Pending_e;
            }
        }
        else
        {
            // cache element is not allowed to be accessed.
            // Either an OOB against the RBA_FEEFS1X_PRV_CFG_NR_OF_BLOCKS occured( catched at upper position)
            // or the current block doesn't have a valid cache entry.

            // no cache entry found --> reenter the state to select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e);
            if(fsm_pst->isSoftReorgOngoing_b)
            {
                // on soft reorg, pause for the possibility of accepting jobs
                retVal_en = rba_FeeFs1x_JobOK_e;
            }
            else
            {
                // on hard reorg, directly continue with the search during the next cycle
                retVal_en = rba_FeeFs1x_Pending_e;
            }
        }
    }
    else
    {
        // if all cached blocks are done ( also if 0 copies are cached), end the cache scan
        // end of known block reorg reached

        // reset the soft reorg state
        fsm_pst->isSoftReorgOngoing_b = FALSE;

        retVal_en = rba_FeeFs1x_JobOK_e;
    }
    return retVal_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCachedDo_searchBlk
 * statefunction of reorgUnknownCachedDo
 * searches the selected block including consistency check
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgUnknownCachedDo_searchBlk(rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en;

    if(FEE_PRV_LIBENTRY)
    {
        // first state call
        // select the search type required for this block
        // isRedundant is extracted from unknown cache in the state before (selectBllk)
        if(fsm_pst->isRedundantBlock_b)
        {
            // for blocks the latest known copy is redundant, search for the 2 newest copies
            rba_FeeFs1x_Searcher_SR_find2LatestCopies_Unknown(fsm_pst->currCacheIdx_u16);
        }
        else
        {
            // for blocks the latest known copy isn't redundant, search only the latest consistent copy
            rba_FeeFs1x_Searcher_SR_find1LatestConsistentCopy_Unknown(fsm_pst->currCacheIdx_u16);
        }
    }

    // Clyclic call for Do function
    retValSearch_en = rba_FeeFs1x_Searcher_findCopiesDo();

    // evaluate the search result
    switch(retValSearch_en)
    {
        case rba_FeeFs1x_Searcher_RetVal_Pending_e:
        {
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Searcher_RetVal_NoCopyFound_e:
        {
            // no copy found --> no reorg necessity. Switch state to select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Searcher_RetVal_OneCopyFound_e:
        case rba_FeeFs1x_Searcher_RetVal_TwoCopiesFound_e:
        {
            // copie(s) were found --> check reorg necessity for this block
            fsm_pst->retValSearch_en = retValSearch_en;
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_checkReq_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_Searcher_RetVal_ErrorInternal_e:
        default:
        {
            // unexpected search return or error
            // --> exit the known reorg, restart the whole reorg
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }
    return retVal_en;
}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq
 * statefunction of reorgUnknownCachedDo
 * checks whether the found latest consistent copy is supposed to be reorged
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq(rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst)
{
    uint8 ctrCopiesRequired_u8 = 0u;
    uint8 ctrCpiesReqForRed_u8;
    rba_FeeFs1x_RetVal_ten retVal_en;

    uint32 pageNrLatest_u32;

    // try to extract the page number from the found native copy
    pageNrLatest_u32 = rba_FeeFs1x_BC_getPageNo(rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e);

    // access the pageNr if getPageNo
    // if this copy is within the 0th sector, reorg once for it
    if(pageNrLatest_u32 < RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR)
    {
        ctrCopiesRequired_u8++;
    }

    rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq_checkRedCpy(fsm_pst , &ctrCpiesReqForRed_u8);

    // both native and redundant checks were successful
    ctrCopiesRequired_u8 += ctrCpiesReqForRed_u8;

    // select the required action based on the amount of copies to be transferred

    switch(ctrCopiesRequired_u8)
    {
        case 0u:
        {
            // no latest copy of this block is located within the sector 0
            // continue with the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case 1u:
        {
            // one transfer of the latest consistent copy required
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_copy1_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case 2u:
        {
            // two transfers of the latest consistent copy required
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_copy2_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        default:
        {
            // unexpected amount of writes
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq_checkRedCpy
 * subfunction of  of rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq
 * checks the redundant copy reorg necessity
 * \param   fsm_pcst : reference to stm data
 * \param   cntcpiesReqForRed_pu8: call by reference return for the amount of copies required for the redundant copy
 * \return  void
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_Reorg_reorgUnknownCachedDo_checkReq_checkRedCpy(
        rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst const * fsm_pcst , uint8 * cntCpiesReqForRed_pu8)
{
    uint32 pageNrRed_u32;

    // for redundant copies, check the found redundant copie's page number
    if(fsm_pcst->isRedundantBlock_b)
    {
        if(fsm_pcst->retValSearch_en == rba_FeeFs1x_Searcher_RetVal_TwoCopiesFound_e)
        {
            // two copies were found, get the pageNr of the redundant copy

            pageNrRed_u32 = rba_FeeFs1x_BC_getPageNo(rba_FeeFs1x_BC_Cpy_SectorReorg_Redundant_e);
            // access the pageNrRed and the cntCpiesReqForRed_pu8
            // if this copy is within the 0th sector, reorg once for it
            if(pageNrRed_u32 < RBA_FEEFS1X_PRV_CFG_LOGL_PAGES_PER_SECTOR)
            {
                *cntCpiesReqForRed_pu8 = 1u;
            }
            else
            {
                *cntCpiesReqForRed_pu8 = 0u;
            }
        }
        else
        {
            // redundant copy should have been found, write once for this missing copy
            // search return "no copy found" doesn't get into this state of checking the reorg necessity
            *cntCpiesReqForRed_pu8 = 1u;
        }
    }
    else
    {
        // Set the correctness of getting the redundant page to E_OK
        // --> non-redundant copies don't need to get the redundant BC page
        *cntCpiesReqForRed_pu8 = 0u;
    }
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy1
 * statefunction of reorgUnknownCachedDo
 * transfers the latest consistent copy once
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy1(rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValCopy_en;

    if(FEE_PRV_LIBENTRY)
    {
        // initial state call, trigger a copy operation for one copy
        rba_FeeFs1x_Reorg_transfer1Copy(FALSE, fsm_pst->currCacheIdx_u16);
    }
    // state-do
    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValCopy_en = rba_FeeFs1x_Reorg_transfer1CopyDo();

    // evaluate the job result
    switch(retValCopy_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // copying finished successfully, select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_JobFailed_e:
            // sector overflow detected, stop the reorg
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_Pending_e:
        {
            retVal_en = retValCopy_en;
        }break;
        case rba_FeeFs1x_ErrorInternal_e:
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;

}
/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy2
 * statefunction of reorgUnknownCachedDo
 * transfers the latest consistent copy twice
 * \return  job result of the reorganisation
 * \retval  rba_FeeFs1x_Pending_e : job needs more cyclic calls
 * \retval  rba_FeeFs1x_JobOK_e : reorg finished
 * \retval  rba_FeeFs1x_ErrorInternal_e : internal processing error lead to a stop of the reorg
 * \retval  rba_FeeFs1x_ErrorExternal_e : error returned by external components, e.g. Fls
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Reorg_reorgUnknownCachedDo_copy2(rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst * fsm_pst)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValCopy_en;

    if(FEE_PRV_LIBENTRY)
    {
        // initial state call: init the transfer of two copies
        rba_FeeFs1x_Reorg_transfer2Copies(FALSE, fsm_pst->currCacheIdx_u16);
    }

    // state do
    /* MR12 RULE 17.2 VIOLATION: The reorg function can be called only once at a time, so there is no recursive function call possibility * */
    retValCopy_en = rba_FeeFs1x_Reorg_transfer2CopiesDo();


    // evaluate the search result
    switch(retValCopy_en)
    {
        case rba_FeeFs1x_JobOK_e:
        {
            // copying finished successfully, select the next block
            FEE_PRV_LIBSC(rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e);
            retVal_en = rba_FeeFs1x_Pending_e;
        }break;
        case rba_FeeFs1x_JobFailed_e:
            // sector overflow detected, stop the known reorg
        case rba_FeeFs1x_ErrorExternal_e:
        case rba_FeeFs1x_Pending_e:
        {
            retVal_en = retValCopy_en;
        }break;
        case rba_FeeFs1x_ErrorInternal_e:
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;
    }

    return retVal_en;
}


/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_reorgUnknownCached_isSoftOngoing
 * function returing whether the unknown reorg cache scan is ongoing during a soft reorg
 * \return  is the soft reorg ongoing?
 * \retval  TRUE  : call the function again during the next background cycle
 * \retval  FALSE : job exited completely
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE boolean rba_FeeFs1x_Reorg_reorgUnknownCached_isSoftOngoing(void)
{
    return rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.isSoftReorgOngoing_b;
}

/**
 *********************************************************************
 * rba_FeeFs1x_Reorg_switchToHardReorg
 * reset all isSoftReorg flags to ensure a continuous reorg execution
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_Reorg_switchToHardReorg(void)
{
    rba_FeeFs1x_Reorg_stm_st.isSoftReorgOngoing_b                       = FALSE;
    rba_FeeFs1x_Reorg_Known_data_st.isSoftReorgOngoing_b                = FALSE;
    rba_FeeFs1x_Reorg_reorgUnknown_data_st.isSoftReorgOngoing_b         = FALSE;
    rba_FeeFs1x_Reorg_reorgUnknownCached_data_st.isSoftReorgOngoing_b   = FALSE;
}

/**
 *********************************************************************
 *
 * Get current state of Soft reorg
 *
 * \return  TRUE = Soft reorg is running, FALSE =  Soft reorg not running
 * \seealso
 * \usedresources
 *********************************************************************
 */
boolean rba_FeeFs1x_Reorg_isSoftReorgOngoing(void)
{
    return ((rba_FeeFs1x_Reorg_stm_idle_e != rba_FeeFs1x_Reorg_stm_st.state_en)
            && (rba_FeeFs1x_Reorg_stm_st.isSoftReorgOngoing_b));
}

/**
 *********************************************************************
 *
 * Get current state of Hard reorg
 *
 * \return  TRUE = Hard reorg is running, FALSE =  Hard reorg not running
 * \seealso
 * \usedresources
 *********************************************************************
 */
boolean rba_FeeFs1x_Reorg_isHardReorgOngoing(void)
{
    return ((rba_FeeFs1x_Reorg_stm_idle_e != rba_FeeFs1x_Reorg_stm_st.state_en)
            && (!rba_FeeFs1x_Reorg_stm_st.isSoftReorgOngoing_b));
}


#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif

