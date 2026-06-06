
#ifndef RBA_FEEFS1X_PRV_CACHEKWN_H
#define RBA_FEEFS1X_PRV_CACHEKWN_H
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

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern void             rba_FeeFs1x_CacheKwn_init(void);

extern void             rba_FeeFs1x_CacheKwn_addNewerCopy(uint16 feeIndex_u16, boolean dataValidated_b, uint32 pageNumber_u32 , boolean hasRedBitActive_b);

extern uint32           rba_FeeFs1x_CacheKwn_getLatestEntry(uint16 feeIndex_u16);

extern boolean          rba_FeeFs1x_CacheKwn_isCacheValid(    uint16 feeIndex_u16);

extern Std_ReturnType   rba_FeeFs1x_CacheKwn_isCachedCopyRedundantBitActive(uint16 feeIndex_u16 , boolean * const isRed_pb);

extern void             rba_FeeFs1x_CacheKwn_invalidateCache(uint16 feeIndex_u16);
extern void             rba_FeeFs1x_CacheKwn_invalidateCaches_NatAndRed(uint16 feeIndex_u16);

extern void             rba_FeeFs1x_CacheKwn_invalidateCacheEntriesFromPageNoAndHighestPageNoLeft(uint32 page_u32);
extern Std_ReturnType   rba_FeeFs1x_CacheKwn_reduceOwnPages(uint32 amountOfPages_u32);

extern void             rba_FeeFs1x_CacheKwn_restoreRed(uint16 feeIndex_u16);

extern void             rba_FeeFs1x_CacheKwn_setDataValid(uint16 feeIndex_u16);

# if (RBA_FEEFS1X_PRV_CFG_NR_RDNT_BLOCKS != 0u)
extern Std_ReturnType   rba_FeeFs1x_CacheKwn_getLatestEntry_Red(uint16 feeIndex_u16, uint32* const pageOfLatest_pu32);
extern Std_ReturnType   rba_FeeFs1x_CacheKwn_isCacheValid_Red(uint16 feeIndex_u16 , boolean * const isCV_pb);
extern Std_ReturnType   rba_FeeFs1x_CacheKwn_invalidateCache_Red(uint16 feeIndex_u16);
extern Std_ReturnType   rba_FeeFs1x_CacheKwn_updateRed(uint16 feeIndex_u16, uint32 newRedundantCopyPage_u32,
        boolean isDataValid_b , boolean hasRedBitActive_b);
# else
/* There are no redundant blocks configured, replace all public functions with dummy functions */
#define   rba_FeeFs1x_CacheKwn_getLatestEntry_Red(feeIndex_u16, pageOfLatest_pu32)  E_NOT_OK  /* This function should never be called, hence return NOT OK*/
#define   rba_FeeFs1x_CacheKwn_isCacheValid_Red(feeIndex_u16, isCV_pb)              E_NOT_OK  /* This function should never be called, hence return NOT OK*/
#define   rba_FeeFs1x_CacheKwn_invalidateCache_Red(feeIndex_u16)                    E_OK      /* Its ok to return that the operation was successful, as all the access functions for getting the information for redundant cache would return E_NOT_OK */
#define   rba_FeeFs1x_CacheKwn_updateRed(feeIndex_u16, newRedundantCopyPage_u32, isDataValid_b, hasRedBitActive_b) E_OK /* Its ok to return that the operation was successful, as all the access functions for getting the information for redundant cache would return E_NOT_OK */
# endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

# endif
#endif

