#ifndef RBA_FEEFS1X_PRV_SEARCHER_H
#define RBA_FEEFS1X_PRV_SEARCHER_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

# if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))

#include "rba_FeeFs1x_Prv_Cfg.h"
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

typedef enum
{
    rba_FeeFs1x_Searcher_RetVal_NoCopyFound_e,
    rba_FeeFs1x_Searcher_RetVal_OneCopyFound_e,
    rba_FeeFs1x_Searcher_RetVal_TwoCopiesFound_e,
    rba_FeeFs1x_Searcher_RetVal_ErrorInternal_e,
    rba_FeeFs1x_Searcher_RetVal_ErrorExternal_e,
    rba_FeeFs1x_Searcher_RetVal_Pending_e
}rba_FeeFs1x_Searcher_RetVal_ten;


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern Std_ReturnType rba_FeeFs1x_Searcher_init(void);

extern Std_ReturnType         rba_FeeFs1x_Searcher_buildupCache(boolean isSynchrounousExecution_b);
extern rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Searcher_buildupCacheDo(void);

extern void           rba_FeeFs1x_Searcher_find1LatestConsistentCopy_Known(uint16 feeIdx_u16);
extern void           rba_FeeFs1x_Searcher_find2LatestCopies_Known(uint16 feeIndex_u16);

extern void           rba_FeeFs1x_Searcher_SR_find1LatestConsistentCopy_Known(uint16 feeIndex_u16);
extern void           rba_FeeFs1x_Searcher_SR_find1LatestConsistentCopy_Unknown(uint16 feeIndex_u16);
extern void           rba_FeeFs1x_Searcher_SR_find2LatestCopies_Known(uint16 feeIndex_u16);
extern void           rba_FeeFs1x_Searcher_SR_find2LatestCopies_Unknown(uint16 feeIndex_u16);

extern rba_FeeFs1x_Searcher_RetVal_ten rba_FeeFs1x_Searcher_findCopiesDo(void);

extern void           rba_FeeFs1x_Searcher_resetSearchForUnknownCacheBuildup(void);
extern void           rba_FeeFs1x_Searcher_buildUpUnknownBlkCache(void);
extern rba_FeeFs1x_RetVal_ten rba_FeeFs1x_Searcher_buildUpUnknownBlkCacheDo(void);

extern uint32         rba_FeeFs1x_Searcher_getUnknownBlkReorgLimit(void);
extern void           rba_FeeFs1x_Searcher_checkUnknownBlkCacheFullAndSetReorgLimit(uint32 pageNr_u32);
extern boolean        rba_FeeFs1x_Searcher_isUnknownBlkCacheBuildupRequired(void);
extern boolean        rba_FeeFs1x_Searcher_isUnknownBlkCacheBuilt(void);

#  if(RBA_FEEFS1X_PRV_CFG_UNKNOWN_BLK_CACHE_ARRAY_SIZE != 0u)
extern Std_ReturnType rba_FeeFs1x_Searcher_reduceOwnPages(uint32 amountOfPages_u32);
#  else
#define rba_FeeFs1x_Searcher_reduceOwnPages(amountOfPages_u32) E_OK // no pages to be updated when no unblocks are required to be handled -> return OK
#  endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

# endif
#endif

