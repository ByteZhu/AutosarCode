
#ifndef FEE_PRV_DBG_H
#define FEE_PRV_DBG_H

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))
#include "Fee_Prv_DbgTypes.h"
#include "Fee_PrvTypes.h"
#include "rba_MemLib.h"
#include "Fee_Prv_Config.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

LOCAL_INLINE void Fee_Prv_DbgDummyFunc(void)
{
}

#  if(TRUE == FEE_PRV_CFG_DBG)
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
extern void Fee_Prv_DbgMainFunction(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*
 * \brief init function for the variables used in the Dbg unit
 * To save code size + delay due to calling of function with parameter, the function is made inline.
 *
 * \param   deviceConfigTable_pcst   Pointer to the config table which has to be initialized.
 */
LOCAL_INLINE void Fee_Prv_DbgInit(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst);
LOCAL_INLINE void Fee_Prv_DbgInit(Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst)
{
    /* The contents of dbgInfo_pst depends on compiler switch settings,
     * i.e. an initialization with rba_MemLib_MemSet is easiest. */
    Fee_Prv_DbgInfo_tst *   dbgInfo_pst = &deviceConfigTable_pcst->feeData_pst->dbgData_st.dbgInfo_st;
    Fee_Prv_Dbg_tst *       dbg_pst     = &deviceConfigTable_pcst->feeData_pst->dbgData_st.dbg_st;
#  if(TRUE == FEE_PRV_CFG_DBG_BLOCK)
    uint8 *                 dbgBfr_pau8 = &deviceConfigTable_pcst->feeData_pst->dbgData_st.dbgBfr_au8[0];
#  endif

    rba_MemLib_MemSet((uint8 *)(dbgInfo_pst), 0u, sizeof(Fee_Prv_DbgInfo_tst));

    /* The contents of dbg_pst doesn't depend on compiler switch settings, i.e. can be intialized directly. */
    dbg_pst->nrDump_u32 = 0u;
    dbg_pst->nrDbgBlockWrites_u32 = 0u;
    dbg_pst->isDebugBlockWriteRequested_b = FALSE;
    dbg_pst->freeze_b = FALSE;

#  if(TRUE == FEE_PRV_CFG_DBG_BLOCK)
    rba_MemLib_MemSet(dbgBfr_pau8, 0u, FEE_PRV_CFG_DBG_BLOCK_SIZE);
#  endif

    return;
}

#  else
#define Fee_Prv_DbgMainFunction(deviceConfigTable_pcst)   Fee_Prv_DbgDummyFunc()
#define Fee_Prv_DbgInit(dbgData_pst)           Fee_Prv_DbgDummyFunc()
#  endif

#  if(defined(RBA_FEEFS2_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS2_PRV_CFG_ENABLED))
#   if(defined(FEE_PRV_CFG_DBG_GRAY_BOX_TEST) && (TRUE == FEE_PRV_CFG_DBG_GRAY_BOX_TEST))
extern void Fee_Test_Prv_UTIL_05_CheckFatEntries(void);
#define Fee_Dbg_CallOut_CheckFatEntries() Fee_Test_Prv_UTIL_05_CheckFatEntries()
#  else
#define Fee_Dbg_CallOut_CheckFatEntries()   Fee_Prv_DbgDummyFunc()
#  endif
# endif

#  if(TRUE == FEE_PRV_CFG_DBG_TIME)

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
extern void Fee_Prv_DbgWatchStart(Fee_Rb_DeviceName_ten deviceName_en, Fee_Prv_DgbTimeAccessEnum_ten timer_en);
extern void Fee_Prv_DbgWatchStop(Fee_Rb_DeviceName_ten deviceName_en, Fee_Prv_DgbTimeAccessEnum_ten timer_en, boolean updateDebugBlock_b);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#  else

#define Fee_Prv_DbgWatchStart(A, B)    Fee_Prv_DbgDummyFunc()
#define Fee_Prv_DbgWatchStop(A, B, C)  Fee_Prv_DbgDummyFunc()

#  endif

#  if(TRUE == FEE_PRV_CFG_DBG_DUMP)

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
extern void Fee_Prv_DbgDump(Fee_Rb_DeviceName_ten deviceName_en);
extern void Fee_Prv_DbgFailDump(Fee_Rb_DeviceName_ten deviceName_en, MemIf_JobResultType result_en);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#  else

#define Fee_Prv_DbgDump(A)       Fee_Prv_DbgDummyFunc()
#define Fee_Prv_DbgFailDump(A, B)  Fee_Prv_DbgDummyFunc()

#  endif

#  if(TRUE == FEE_PRV_CFG_DBG_BLOCK)

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
extern void Fee_Prv_DbgBlockRead(Fee_Rb_DeviceName_ten deviceName_en);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#  else

#define Fee_Prv_DbgBlockRead(A)  Fee_Prv_DbgDummyFunc()

#  endif

# endif

/* FEE_PRV_DBG_H */
#endif
