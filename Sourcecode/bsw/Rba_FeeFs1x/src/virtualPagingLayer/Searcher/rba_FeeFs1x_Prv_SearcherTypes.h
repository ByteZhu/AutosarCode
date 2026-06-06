#ifndef RBA_FEEFS1X_PRV_SEARCHERTYPES_H
#define RBA_FEEFS1X_PRV_SEARCHERTYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "rba_FeeFs1x_Prv.h"
#include "rba_FeeFs1x_Prv_BC.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
#define RBA_FEEFS1X_SEARCHER_NR_BYTES_PREFETCH_UNKWN_BLK (32uL)


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */




typedef enum
{
    rba_FeeFs1x_Searcher_find1LatestConsistentCopy_Known_e,
    rba_FeeFs1x_Searcher_find2LatestCopies_Known_e,
    rba_FeeFs1x_Searcher_SR_find1LatestConsistentCopy_Known_e,
    rba_FeeFs1x_Searcher_SR_find1LatestConsistentCopy_Unknown_e,
    rba_FeeFs1x_Searcher_SR_find2LatestCopies_Known_e,
    rba_FeeFs1x_Searcher_SR_find2LatestCopies_Unknown_e
}rba_FeeFs1x_Searcher_findCopyJob_ten;


typedef enum
{
    rba_FeeFs1x_Searcher_findCopyStm_idle_e,
    rba_FeeFs1x_Searcher_findCopyStm_initCopy_e
}rba_FeeFs1x_Searcher_findCopyStm_ten;

typedef enum
{
    rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_idle_e,
    rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_isCacheValid_e,
    rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_initBlockCopy_e,
    rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_checkDataConsistency_e,
    rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_restoreRedundantBlockData_e,
    rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_manualSearchAndCacheUpdate_e
}rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_ten;

typedef enum
{
    rba_FeeFs1x_Searcher_searchManuallyStm_idle_e,
    rba_FeeFs1x_Searcher_searchManuallyStm_analysePageContent_e,
    rba_FeeFs1x_Searcher_searchManuallyStm_checkPersId_e,
    rba_FeeFs1x_Searcher_searchManuallyStm_validateHeader_e,
    rba_FeeFs1x_Searcher_searchManuallyStm_checkCont_e,
    rba_FeeFs1x_Searcher_searchManuallyStm_error_e
}rba_FeeFs1x_Searcher_searchManuallyStm_ten;

typedef enum
{
    rba_FeeFs1x_Searcher_cacheTypeKwn_e,
    rba_FeeFs1x_Searcher_cacheTypeUnkwn_e
} rba_FeeFs1x_Searcher_cacheTypes_ten;


typedef struct
{
    uint32 pageNr_u32;
    uint16 feeIdx_u16;
    uint16 persistentId_u16;
    rba_FeeFs1x_Searcher_cacheTypes_ten cacheType_en;
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en;
    rba_FeeFs1x_Searcher_findLatestConsistentCopyStm_ten state_en;
    boolean entry_b;
}rba_FeeFs1x_Searcher_findLatestConsistentCopy_tst;

typedef struct
{
    uint32 * pageNr_pu32;
    uint32  currPageNr_u32;
    uint16 persistentId_u16;
    rba_FeeFs1x_Searcher_searchManuallyStm_ten state_en;
    boolean entry_b;
    uint8 allowedRetries_u8;
}rba_FeeFs1x_Searcher_searchManually_tst;

typedef enum
{
    rba_FeeFs1x_Searcher_buildupCacheStates_idle_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_extractHdr_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_extractHdrSync_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_isCachingReq_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_valHdr_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_addCache_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_updRedCache_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_checkCont_e,
    rba_FeeFs1x_Searcher_buildupCacheStates_exit_e
}rba_FeeFs1x_Searcher_buildupCacheStates_ten;



typedef struct
{
    uint32 currentPage_u32;
    uint8 allowedRetries_u8;

    uint16 ctrFinishedNatCacheEntries_u16;
    uint16 ctrFinishedRedCacheEntries_u16;
    uint32 highestProgrPageNr_u32;

    uint16 feeIndex_u16;
    boolean redCopyToBeUpdated_b;

    rba_FeeFs1x_Searcher_buildupCacheStates_ten state_en;
    boolean entry_b;

    boolean isUnkwnBlkDetected_b;
    boolean  isSynchrounousExecution_b;
}rba_FeeFs1x_Searcher_buildupCache_tst;


typedef enum
{
    rba_FeeFs1x_Searcher_findCopiesDo_stm_idle_e,
    rba_FeeFs1x_Searcher_findCopiesDo_stm_findLatestCpy_e,
    rba_FeeFs1x_Searcher_findCopiesDo_stm_findRedCpy_e
}rba_FeeFs1x_Searcher_findCopiesDo_stm_ten;

typedef struct
{
    boolean isSecondCopyRequested_b;
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copyNat_en;
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copyRed_en;
    rba_FeeFs1x_Searcher_cacheTypes_ten cacheType_en;
    uint16 feeIdx_u16;

    rba_FeeFs1x_Searcher_findCopiesDo_stm_ten state_en;
    boolean entry_b;

}rba_FeeFs1x_Searcher_findCopiesDo_data_tst;

typedef enum
{
    rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_stm_idle_e,
    rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_stm_isCacheValid_e,
    rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_stm_initCpy_e,
    rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_stm_manual_e,
    rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_stm_cacheUpdAfterManual_e
}rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_stm_ten;

typedef struct
{
    rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_stm_ten state_en;
    boolean entry_b;

    uint16 feeIdx_u16;
    uint16 persistentId_u16;
    rba_FeeFs1x_Searcher_cacheTypes_ten cacheType_en;

    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en;
    uint32 pageNr_u32;
}rba_FeeFs1x_Searcher_findLatestRedundantCopyDo_data_tst;



typedef enum
{
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_idle_e          ,
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_extractHdr_e    ,
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_isCachingReq_e  ,
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_valHdr_e        ,
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_addCache_e      ,
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_updRedCache_e   ,
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_checkCont_e     ,
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_exit_e

}rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_ten;

typedef struct
{
    rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_stm_ten state_en;
    boolean entry_b;
    uint8 allowedRetries_u8;
    uint32 currPage_u32;
    boolean isCacheFull_b;

    uint16 persIDCurrBlock_u16;
    boolean isCachedAlready_b;

}rba_FeeFs1x_Searcher_buildUpUnknownBlkCache_data_tst;
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

