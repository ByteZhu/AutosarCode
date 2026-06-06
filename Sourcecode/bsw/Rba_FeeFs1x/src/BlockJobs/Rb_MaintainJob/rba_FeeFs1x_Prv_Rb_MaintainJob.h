
#ifndef RBA_FEEFS1X_PRV_RB_MAINTAINJOB_H
#define RBA_FEEFS1X_PRV_RB_MAINTAINJOB_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

# if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))

#include "rba_FeeFs1x_Prv_Cfg.h"
#include "rba_FeeFs1x_Prv_Searcher.h"
#include "rba_FeeFs1x_Prv_BlockJobTypes.h"

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

#  if(RBA_FEEFS1X_PRV_CFG_MAINTAIN != FALSE)

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern void rba_FeeFs1x_MtJob_init(void);
extern void rba_FeeFs1x_MtJob_initJob(uint16 feeIndex_u16);


extern void rba_FeeFs1x_MtJob_checkMtReq(rba_FeeFs1x_Searcher_RetVal_ten searchresult_en);

extern void rba_FeeFs1x_MtJob_execMt(rba_FeeFs1x_Searcher_RetVal_ten searchresult_en);
extern void rba_FeeFs1x_MtJob_execMt_NoFB(rba_FeeFs1x_Searcher_RetVal_ten searchresult_en);

extern rba_FeeFs1x_BlockJob_ReturnType_ten rba_FeeFs1x_MtJob_checkMtReqDo(void);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#  else
/* Maintain is deactivated, replace all public function calls with dummy functions or null pointer. */
#define rba_FeeFs1x_MtJob_init()
#define rba_FeeFs1x_MtJob_initJob(feeIndex_u16)
#define rba_FeeFs1x_MtJob_checkMtReq     NULL_PTR
#define rba_FeeFs1x_MtJob_execMt         NULL_PTR
#define rba_FeeFs1x_MtJob_execMt_NoFB    NULL_PTR
#define rba_FeeFs1x_MtJob_checkMtReqDo   NULL_PTR

#  endif // (RBA_FEEFS1X_PRV_CFG_MAINTAIN != FALSE)
# endif
#endif // #ifndef RBA_FEEFS1X_PRV_RB_MAINTAINJOB_H
