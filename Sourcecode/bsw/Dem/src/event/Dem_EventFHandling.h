
#ifndef DEM_EVENTFHANDLING_H
#define DEM_EVENTFHANDLING_H

#include "Dem_Types.h"
#include "Dem_Cfg_Events.h"
#include "Dem_Cfg_EvBuff.h"
#include "Dem_Array.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

DEM_ARRAY_DECLARE(boolean, Dem_IsMonitorStatusChanged, DEM_EVENTID_ARRAYLENGTH);

void Dem_ReportErrorStatusDisableQueue (void);
void Dem_ReportErrorStatusEnableQueue (void);
void Dem_PreInitErrorQueue(void);

/* -- Special handling for timebased debouncing -- */
#if (DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING == DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING_ON)
extern Dem_MonitorDataType Dem_DebArTimeDebugValues[DEM_CFG_DEBARTIME_PARAMSET1_LENGTH][2];
#endif
/* ------------------------------------------------*/


/*-- FAILURE HANDLING --------------------------------------------------------*/


#if (DEM_CFG_CHECKAPICONSISTENCY == TRUE)
/*MR12 RULE 8.5 VIOLATION: Duplicate of Dem_GetEventFailed to make it also available in the GeneralDiagnosticInfo RTE interface */
Std_ReturnType Dem_GetEventFailed_GeneralEvtInfo(Dem_EventIdType EventId, boolean* EventFailed);
#endif /* DEM_CFG_CHECKAPICONSISTENCY */


void Dem_EvtProcessPassedAndFailed (Dem_EventIdType EventId, Dem_EventStatusType EventStatus, Dem_MonitorDataType monitorData0, Dem_MonitorDataType monitorData1);

Dem_boolean_least Dem_EvtsRestoreFailurefromPreviousIC (Dem_EventIdType EventId);




/*-- SUSPICION HANDLING ------------------------------------------------------*/

#if(DEM_CFG_SUSPICIOUS_SUPPORT)
void Dem_SetEventSuspicion_Internal (Dem_EventIdType EventId, boolean suspicion);
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif
