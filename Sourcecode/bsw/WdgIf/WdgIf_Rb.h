

#ifndef WDGIF_RB_H
#define WDGIF_RB_H 

#include "Std_Types.h"
#include "rba_BswSrv.h"

/*
 **************************************************************************************************************************
 * Function Definitions
 **************************************************************************************************************************
 */

#define WDGIF_START_SEC_CODE
#include "WdgIf_MemMap.h"

extern uint16 WdgIf_Rb_GetHwTimeOut(void);
extern void WdgIf_Rb_SetHwTimeOut(void);
extern void WdgIf_Rb_SetHwTimeOut_Trigger(uint16 timeout_u16);
extern void WdgIf_Rb_IndicateShutdown(void);
extern void WdgIf_Rb_PeriodicService(void);
extern void WdgIf_Rb_ServiceWatchdog(void);

#define WDGIF_STOP_SEC_CODE
#include "WdgIf_MemMap.h"


#endif /*WDGIF_RB_H*/

