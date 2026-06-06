
#ifndef DEM_MONITORSTATUS_H
#define DEM_MONITORSTATUS_H

#include "Dem.h"
#include "Dem_Array.h"
#include "Dem_Cfg_Events.h"
#include "Dem_Cfg_EventId.h"
#include "Dem_Cfg_OperationCycle.h"

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

DEM_ARRAY_DECLARE(uint8, Dem_AllEventsMonitorStatus, DEM_EVENTID_ARRAYLENGTH);

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

#define DEM_MONITOR_STATUS_TF_BIT_POS         0u
#define DEM_MONITOR_STATUS_TNCTOC_BIT_POS     1u

void Dem_MonitorStatusInit(void);

#if (DEM_CFG_CHECKAPICONSISTENCY == TRUE)
/*MR12 RULE 8.5 VIOLATION: Duplicate of Dem_GetMonitorStatus to make it also available in the GeneralDiagnosticInfo RTE interface */
Std_ReturnType Dem_GetMonitorStatus_GeneralDiagnosticInfo(Dem_EventIdType EventID, Dem_MonitorStatusType* MonitorStatus);
#endif /* DEM_CFG_CHECKAPICONSISTENCY */
Dem_boolean_least Dem_MonSt_IsUpdateNeeded(Dem_EventIdType EventId, Dem_boolean_least reportIsFailed);
/* Query functions */
DEM_INLINE Dem_boolean_least Dem_MonitorStatusByteIsTestFailed(Dem_EventIdType EventId)
{
    return rba_DiagLib_Bit8IsBitSet (Dem_AllEventsMonitorStatus[EventId], DEM_MONITOR_STATUS_TF_BIT_POS);
}

DEM_INLINE Dem_boolean_least Dem_MonitorStatusByteIsTestNotCompleteTOC (Dem_EventIdType EventId)
{
    return rba_DiagLib_Bit8IsBitSet (Dem_AllEventsMonitorStatus[EventId], DEM_MONITOR_STATUS_TNCTOC_BIT_POS);
}

/* Set methods */

DEM_INLINE void Dem_MonitorStatusByte_SetTestFailed(Dem_EventIdType EventId, Dem_boolean_least setBit)
{
    rba_DiagLib_Bit8OverwriteBit (&(Dem_AllEventsMonitorStatus[EventId]), DEM_MONITOR_STATUS_TF_BIT_POS, setBit);
}

DEM_INLINE void Dem_MonitorStatusByte_SetTestCompleteTOC(Dem_EventIdType EventId, Dem_boolean_least setBit)
{
    rba_DiagLib_Bit8OverwriteBit (&(Dem_AllEventsMonitorStatus[EventId]), DEM_MONITOR_STATUS_TNCTOC_BIT_POS, !setBit);
}

DEM_INLINE void Dem_MonitorStatusHandleClear (Dem_EventIdType EventId, Dem_boolean_least ClearFully)
{
#if DEM_CFG_CLEARDTCCLEARSALLBITS
    if (ClearFully)
    {
        Dem_MonitorStatusByte_SetTestFailed(EventId, FALSE);
    }
#else
    DEM_UNUSED_PARAM(ClearFully);
#endif
    Dem_MonitorStatusByte_SetTestCompleteTOC(EventId, FALSE);
}

DEM_INLINE Dem_MonitorStatusType Dem_EvtGetMonitorStatusByte (Dem_EventIdType EventId)
{
    return Dem_AllEventsMonitorStatus[EventId];
}

DEM_INLINE void Dem_MonitorStatus_HandleFailed (Dem_EventIdType EventId)
{
    Dem_MonitorStatusByte_SetTestFailed(EventId, TRUE);
    Dem_MonitorStatusByte_SetTestCompleteTOC(EventId, TRUE);
}

DEM_INLINE void Dem_MonitorStatus_HandlePassed (Dem_EventIdType EventId)
{
    Dem_MonitorStatusByte_SetTestFailed(EventId, FALSE);
    Dem_MonitorStatusByte_SetTestCompleteTOC(EventId, TRUE);
}

#endif /* DEM_MONITORSTATUS_H */
