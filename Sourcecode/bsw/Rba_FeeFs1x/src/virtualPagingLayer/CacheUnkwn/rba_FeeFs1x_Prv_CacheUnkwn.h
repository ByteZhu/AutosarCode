
#ifndef RBA_FEEFS1X_PRV_CACHEUNKWN_H
#define RBA_FEEFS1X_PRV_CACHEUNKWN_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

# if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))

#include "rba_FeeFs1x_Prv_Cfg.h"

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


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#  if(RBA_FEEFS1X_PRV_CFG_UNKNOWN_BLK_CACHE_ARRAY_SIZE != 0u)

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern void             rba_FeeFs1x_CacheUnkwn_init(void);

extern void             rba_FeeFs1x_CacheUnkwn_addNewerCopy(uint16 feeIndex_u16, boolean isDataValidated_b, uint32 pageNr_u32, boolean hasRedBitActive_b);
extern Std_ReturnType   rba_FeeFs1x_CacheUnkwn_addNewerCopyByPersID(uint16 persID_u16, boolean isDataValidated_b, uint32 pageNr_u32, boolean hasRedBitActive_b);

extern uint32           rba_FeeFs1x_CacheUnkwn_getLatestEntry(uint16 feeIndex_u16);
extern Std_ReturnType   rba_FeeFs1x_CacheUnkwn_getLatestEntry_Red(uint16 idxRedBlk_u16, uint32* const nrPageOfLatestRed_cpu32);
extern uint16           rba_FeeFs1x_CacheUnkwn_getUnknownBlkCacheLevel(void);
extern uint16           rba_FeeFs1x_CacheUnkwn_getPersID(uint16 feeIdx_u16);

extern boolean          rba_FeeFs1x_CacheUnkwn_isCacheValid(uint16 feeIndex_u16);
extern Std_ReturnType   rba_FeeFs1x_CacheUnkwn_isCacheValid_Red(uint16 idxRedBlk_u16, boolean * const isCV_pb);

extern Std_ReturnType   rba_FeeFs1x_CacheUnkwn_isCachedCopyRedundantBitActive(uint16 idxRedBlk_u16, boolean * const isRed_pb);

extern void             rba_FeeFs1x_CacheUnkwn_invalidateCache(uint16 feeIndex_u16);
extern void             rba_FeeFs1x_CacheUnkwn_invalidateCache_Red(uint16 feeIndex_u16);
extern void             rba_FeeFs1x_CacheUnkwn_invalidateCaches_NatAndRed(uint16 feeIndex_u16);

extern void             rba_FeeFs1x_CacheUnkwn_invalidateCompleteCache(void);
extern Std_ReturnType   rba_FeeFs1x_CacheUnkwn_reduceOwnPages(uint32 amountOfPages_u32);

extern boolean          rba_FeeFs1x_CacheUnkwn_isBlockCached(uint16 persID_u16);

extern void             rba_FeeFs1x_CacheUnkwn_restoreRed(uint16 idxRedBlk_u16);

extern void             rba_FeeFs1x_CacheUnkwn_setDataValid(uint16 feeIndex_u16);

extern void rba_FeeFs1x_CacheUnkwn_updateRed(uint16 feeIndex_u16, uint32 newRedundantCopyPage_u32, boolean isDataValid_b , boolean hasRedBitActive_b);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#  else

/* There is no unknown block handling requried, replace all public function calls with dummy functions.
 * None of the functions from this unit should be called, so return failure when the function is called accidently. */
#define   rba_FeeFs1x_CacheUnkwn_init()

#define   rba_FeeFs1x_CacheUnkwn_addNewerCopy(feeIndex_u16, isDataValidated_b, pageNr_u32, hasRedBitActive_b)

LOCAL_INLINE Std_ReturnType rba_FeeFs1x_CacheUnkwn_addNewerCopyByPersID(uint16 persID_u16, boolean isDataValidated_b, uint32 pageNr_u32, boolean hasRedBitActive_b);
LOCAL_INLINE Std_ReturnType rba_FeeFs1x_CacheUnkwn_addNewerCopyByPersID(uint16 persID_u16, boolean isDataValidated_b, uint32 pageNr_u32, boolean hasRedBitActive_b)
{
    // supress compiler warnings by void cast for unused parameters
    (void) persID_u16;
    (void) isDataValidated_b;
    (void) pageNr_u32;
    (void) hasRedBitActive_b;
    return E_NOT_OK;
}

#define   rba_FeeFs1x_CacheUnkwn_getLatestEntry(feeIndex_u16)                               0u
#define   rba_FeeFs1x_CacheUnkwn_getLatestEntry_Red(idxRedBlk_u16, nrPageOfLatestRed_cpu32) E_NOT_OK
#define   rba_FeeFs1x_CacheUnkwn_getUnknownBlkCacheLevel()                                  0u
#define   rba_FeeFs1x_CacheUnkwn_getPersID(feeIdx_u16)                                      0xFFFF

#define   rba_FeeFs1x_CacheUnkwn_isCacheValid(feeIndex_u16)                                 FALSE
#define   rba_FeeFs1x_CacheUnkwn_isCacheValid_Red(idxRedBlk_u16,  isCV_pb)                  E_NOT_OK

#define   rba_FeeFs1x_CacheUnkwn_isCachedCopyRedundantBitActive(idxRedBlk_u16, isRed_pb)    E_NOT_OK

#define   rba_FeeFs1x_CacheUnkwn_invalidateCache(feeIndex_u16)
#define   rba_FeeFs1x_CacheUnkwn_invalidateCache_Red(feeIndex_u16)
#define   rba_FeeFs1x_CacheUnkwn_invalidateCaches_NatAndRed(feeIndex_u16)

#define   rba_FeeFs1x_CacheUnkwn_invalidateCompleteCache()
#define   rba_FeeFs1x_CacheUnkwn_reduceOwnPages(amountOfPages_u32)                          E_OK       /* return OK, to avoid error during reorg -> this function is always called during reorg */

#define   rba_FeeFs1x_CacheUnkwn_isBlockCached(persID_u16)                                  FALSE

#define   rba_FeeFs1x_CacheUnkwn_restoreRed(idxRedBlk_u16)

#define   rba_FeeFs1x_CacheUnkwn_setDataValid(feeIndex_u16)

#define   rba_FeeFs1x_CacheUnkwn_updateRed(feeIdx_u16, newRedundantCopyPage_u32, isDataValid_b, hasRedBitActive_b)

#  endif
# endif
#endif

