
#ifndef RBA_FEEFS1X_PRV_SECTORREORGTYPES_H
#define RBA_FEEFS1X_PRV_SECTORREORGTYPES_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "rba_FeeFs1x_Prv_Searcher.h"

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
    rba_FeeFs1x_Reorg_stm_idle_e,
    rba_FeeFs1x_Reorg_stm_checkAndFillSect0End_e,
    rba_FeeFs1x_Reorg_stm_known_e,
    rba_FeeFs1x_Reorg_stm_unknown_e,
    rba_FeeFs1x_Reorg_stm_sectorOverFlowHandler_e,
    rba_FeeFs1x_Reorg_stm_end_e
}rba_FeeFs1x_Reorg_stm_ten;

typedef struct
{
    rba_FeeFs1x_Reorg_stm_ten state_en;
    boolean entry_b;

    boolean isSoftReorgOngoing_b;
    uint8 sectorOverflowAttemptCtr_u8;
}rba_FeeFs1x_Reorg_stm_tst;


typedef enum
{
    rba_FeeFs1x_Reorg_Known_stm_idle_e,
    rba_FeeFs1x_Reorg_Known_stm_selectBlk_e,
    rba_FeeFs1x_Reorg_Known_stm_searchBlk_e,
    rba_FeeFs1x_Reorg_Known_stm_checkReq_e,
    rba_FeeFs1x_Reorg_Known_stm_copy1_e,
    rba_FeeFs1x_Reorg_Known_stm_copy2_e
}rba_FeeFs1x_Reorg_Known_stm_ten;


typedef struct
{
    rba_FeeFs1x_Reorg_Known_stm_ten state_en;
    boolean                         entry_b;

    uint16                          currentBlockIndex_u16;
    uint16                          nextBlockIndex_u16;
    boolean                         isRedundantBlock_b;
    rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en;

    boolean isSoftReorgOngoing_b;
}rba_FeeFs1x_Reorg_Known_data_tst;


typedef enum
{
    rba_FeeFs1x_Reorg_transferCopies_stm_idle_e,
    rba_FeeFs1x_Reorg_transferCopies_stm_init1_e,
    rba_FeeFs1x_Reorg_transferCopies_stm_copy1_e,
    rba_FeeFs1x_Reorg_transferCopies_stm_error1_e,
    rba_FeeFs1x_Reorg_transferCopies_stm_init2_e,
    rba_FeeFs1x_Reorg_transferCopies_stm_copy2_e,
    rba_FeeFs1x_Reorg_transferCopies_stm_error2_e

}rba_FeeFs1x_Reorg_transferCopies_stm_ten;

typedef enum
{
    rba_FeeFs1x_Reorg_transferCopy_1_e,
    rba_FeeFs1x_Reorg_transferCopy_2_e
}rba_FeeFs1x_Reorg_transferCopy_ten;

typedef struct
{
    rba_FeeFs1x_Reorg_transferCopies_stm_ten state_en;
    boolean entry_b;

    uint16  feeIdx_u16;
    uint8   allowedRetries_u8;
    boolean isKnownBlock_b;
}rba_FeeFs1x_Reorg_transferCopies_data_tst;

typedef enum
{
    rba_FeeFs1x_Reorg_repairSectOverflow_stm_idle_e,
    rba_FeeFs1x_Reorg_repairSectOverflow_stm_eraseClone_e,
    rba_FeeFs1x_Reorg_repairSectOverflow_stm_cacheBuildup_e
}rba_FeeFs1x_Reorg_repairSectOverflow_stm_ten;

typedef struct
{
    rba_FeeFs1x_Reorg_repairSectOverflow_stm_ten state_en;
    boolean entry_b;
}rba_FeeFs1x_Reorg_repairSectOverflow_data_tst;


typedef enum
{
    rba_FeeFs1x_Reorg_reorgUnknown_stm_idle_e,
    rba_FeeFs1x_Reorg_reorgUnknown_stm_checkCacheRebuildReq_e,
    rba_FeeFs1x_Reorg_reorgUnknown_stm_cacheRebuild_e,
    rba_FeeFs1x_Reorg_reorgUnknown_stm_reorgCachedBlocks_e
} rba_FeeFs1x_Reorg_reorgUnknown_stm_ten;

typedef struct
{
    rba_FeeFs1x_Reorg_reorgUnknown_stm_ten state_en;
    boolean entry_b;

    boolean isRedundantBlock_b;
    rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en;

    boolean isSoftReorgOngoing_b;
}rba_FeeFs1x_Reorg_reorgUnknown_data_tst;

typedef enum
{
    rba_FeeFs1x_Reorg_reorgUnknownCached_stm_idle_e,
    rba_FeeFs1x_Reorg_reorgUnknownCached_stm_selectBlk_e,
    rba_FeeFs1x_Reorg_reorgUnknownCached_stm_searchBlk_e,
    rba_FeeFs1x_Reorg_reorgUnknownCached_stm_checkReq_e,
    rba_FeeFs1x_Reorg_reorgUnknownCached_stm_copy1_e,
    rba_FeeFs1x_Reorg_reorgUnknownCached_stm_copy2_e
}rba_FeeFs1x_Reorg_reorgUnknownCached_stm_ten;

typedef struct
{
    rba_FeeFs1x_Reorg_reorgUnknownCached_stm_ten state_en;
    boolean entry_b;

    uint16 cntCachedElements_u16;
    uint16 currCacheIdx_u16;
    uint16 nextCacheIdx_u16;
    boolean isRedundantBlock_b;
    rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en;

    boolean isSoftReorgOngoing_b;
}rba_FeeFs1x_Reorg_reorgUnknownCached_data_tst;

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




#endif

