
#ifndef RBA_FEEFS1X_PRV_WRITEJOB_H
#define RBA_FEEFS1X_PRV_WRITEJOB_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

# if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))

#include "rba_FeeFs1x_Prv_Cfg.h"
#include "rba_FeeFs1x_Prv_BlockJobTypes.h"
#include "rba_FeeFs1x_Prv_Searcher.h"

#include "Fee_Prv_Job.h"

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
extern void rba_FeeFs1x_WrJob_init(void);
extern void rba_FeeFs1x_WrJob_initJob(Fee_Prv_JobDesc_tst const * orderStruct_pcst);

/* checkWrJob functions */
extern void rba_FeeFs1x_WrJob_checkWrReq(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);

/* execWrJob functions */
extern void rba_FeeFs1x_WrJob_execWr_Native(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);
#  if(RBA_FEEFS1X_PRV_CFG_NR_RDNT_BLOCKS != 0u)
extern void rba_FeeFs1x_WrJob_execWr_Red(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);
#  else
/* Dummy function when there are no redundant blocks present */
#define rba_FeeFs1x_WrJob_execWr_Red NULL_PTR
#  endif

/* checkWrJob_Do functions */
extern rba_FeeFs1x_BlockJob_ReturnType_ten rba_FeeFs1x_WrJob_checkWrReqDo(void);

/* execWrJob_NoFB Funtions */
extern void rba_FeeFs1x_WrJob_execWr_NoFBNative(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);
#  if(RBA_FEEFS1X_PRV_CFG_NR_RDNT_BLOCKS != 0u)
extern void rba_FeeFs1x_WrJob_execWr_NoFBRed(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);
#  else
/* Dummy function when there are no redundant blocks present */
#define rba_FeeFs1x_WrJob_execWr_NoFBRed NULL_PTR
#  endif

#  if((TRUE == RBA_FEEFS1X_PRV_CFG_UNKNOWN_BLOCK_WRITE) || (TRUE == RBA_FEEFS1X_PRV_CFG_UNKNOWN_SURVIVAL_BLOCK_WRITE))
extern void rba_FeeFs1x_WrJob_execWr_UnknownBlk(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);
#  else
/* Dummy function when there are no unknown block write */
#define rba_FeeFs1x_WrJob_execWr_UnknownBlk NULL_PTR
#  endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

# endif
#endif /* RBA_FEEFS1X_PRV_WRITEJOB_H */

