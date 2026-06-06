
#ifndef RBA_FEEFS1X_PRV_BLOCKJOB_H
#define RBA_FEEFS1X_PRV_BLOCKJOB_H
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

typedef enum
{
    rba_FeeFs1x_BlockJob_execWr_jobType_write,
    rba_FeeFs1x_BlockJob_execWr_jobType_invalidate,
    rba_FeeFs1x_BlockJob_execWr_jobType_maintain
}rba_FeeFs1x_BlockJob_execWr_jobType_ten;

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
// jobfunctions are published in rba_FeeFs1x.h
extern void rba_FeeFs1x_BlockJob_init(void);

extern void rba_FeeFs1x_BlockJob_execWr(
        uint32 dataCRC_u32,
        rba_FeeFs1x_BlockJob_execWr_jobType_ten jobType_en,
        boolean isCpyRed_b,
        boolean isCopy1Destroyed_b,
        boolean isCopy2Destroyed_b
        );

extern void rba_FeeFs1x_BlockJob_execWrMaintain(
        boolean isCopy1Destroyed_b,
        boolean isCopy2Destroyed_b,
        boolean isNoFB_b,
        boolean writeTwice_b
        );

#  if(defined(RBA_FEEFS1X_PRV_CFG_DETAILED_BLK_INFO_API) && (TRUE == RBA_FEEFS1X_PRV_CFG_DETAILED_BLK_INFO_API))
extern void rba_FeeFs1x_BlockJob_ReportBlkDataCrcError(void);
#  else
#define rba_FeeFs1x_BlockJob_ReportBlkDataCrcError()
#  endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

# endif
#endif

