
#ifndef RBA_FEEFS1X_PRV_READJOB_H
#define RBA_FEEFS1X_PRV_READJOB_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
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

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern void rba_FeeFs1x_RdJob_init(void);
extern void rba_FeeFs1x_RdJob_initJob(uint16 length_u16, uint16 offset_u16, uint8* userbuffer_pu8);

/* checkRdJob functions */
extern void rba_FeeFs1x_RdJob_checkRdReq(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);
extern rba_FeeFs1x_BlockJob_ReturnType_ten rba_FeeFs1x_RdJob_checkRdReqDo(void);

/* execRdJob functions */
extern void rba_FeeFs1x_RdJob_execRd(rba_FeeFs1x_Searcher_RetVal_ten retValSearch_en);
extern rba_FeeFs1x_BlockJob_ReturnType_ten rba_FeeFs1x_RdJob_execRdDo(void);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif

