
#include "Dem_Internal.h"
#include "Rte_Dem.h"
#include "Dem_EventStatus.h"
#include "Dem_MonitorStatus.h"
#include "Dem_Events.h"
#include "Dem_Cfg_Main.h"

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

DEM_ARRAY_DEFINE(uint8, Dem_AllEventsMonitorStatus, DEM_EVENTID_ARRAYLENGTH);

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

/* Called from Dem_Init to reconstruct MonitorStatus From AllEventStatusByte.
 * The MonitorStatusInit is called in Dem_Init before Fim_DemInit.
 * */
void Dem_MonitorStatusInit(void)
{
    Dem_EventIdType EventId;
    Dem_EventIdIterator eventIt;
    for (Dem_EventIdIteratorNew(&eventIt); Dem_EventIdIteratorIsValid(&eventIt); Dem_EventIdIteratorNext(&eventIt))
        {
            EventId = Dem_EventIdIteratorCurrent(&eventIt);
            if(!Dem_EvtIsSuppressed(EventId))
            {
                /*Clear the Monitor status, This is done to avoid the merging of Monitor Status on recursion of same Events */
                DEM_MONITORSTATUS_CLEARALL(&Dem_AllEventsMonitorStatus[EventId]);

            	if(Dem_ISO14229ByteIsTestFailed(Dem_AllEventsStatusByte[EventId]))
                {
                    Dem_AllEventsMonitorStatus[EventId]=DEM_MONITOR_STATUS_TF;
                }
                if(Dem_ISO14229ByteIsTestNotCompleteTOC(Dem_AllEventsStatusByte[EventId]))
                {
                    Dem_AllEventsMonitorStatus[EventId]|=DEM_MONITOR_STATUS_TNCTOC;
                }
            }
        }
}

/* MR12 RULE 8.3 VIOLATION: due to the RTE there is an additional declaration with P2VAR for this function, it is ensured that the internal declarations are correct */
/* HIS METRIC PATH VIOLATION IN Dem_GetMonitorStatus: Analysis of received payload can not be avoided */
Std_ReturnType Dem_GetMonitorStatus(Dem_EventIdType EventID, Dem_MonitorStatusType* MonitorStatus)
{
    /*  Entry Condition Check    */
    DEM_ENTRY_CONDITION_CHECK_DEM_INITIALIZED_OR_FIM_IS_IN_INIT_WITHEVENTID(EventID,DEM_DET_APIID_DEM_GETMONITORSTATUS, E_NOT_OK);
    DEM_ENTRY_CONDITION_CHECK_NOT_NULL_PTR(MonitorStatus, DEM_DET_APIID_DEM_GETMONITORSTATUS, E_NOT_OK);
    DEM_ENTRY_CONDITION_CHECK_EVENT_ID_VALID_AVAILABLE(EventID,DEM_DET_APIID_DEM_GETMONITORSTATUS,E_NOT_OK);

    *MonitorStatus = Dem_AllEventsMonitorStatus[EventID];
    return E_OK;

}

#ifdef RTE_TYPE_H
/* MR12 RULE 8.3 VIOLATION: due to the RTE there is an additional declaration with P2VAR for this function, it is ensured that the internal declarations are correct */
Std_ReturnType Dem_GetMonitorStatus_GeneralDiagnosticInfo(Dem_EventIdType EventID, Dem_MonitorStatusType* MonitorStatus)
{
    return Dem_GetMonitorStatus(EventID, MonitorStatus);
}
#endif /* RTE_TYPE_H */
/*
 * Called in Dem_EvtProcessPassedAndFailed() to check whether the reported status would change the event status information
 */
Dem_boolean_least Dem_MonSt_IsUpdateNeeded(Dem_EventIdType EventId, Dem_boolean_least reportIsFailed)
{
    return (
           (Dem_MonitorStatusByteIsTestFailed(EventId) != reportIsFailed)
        || (Dem_MonitorStatusByteIsTestNotCompleteTOC(EventId))

#if (DEM_CFG_CUSTOMIZABLEDTCSTATUSBYTE)
        || (Dem_ISO14229ByteIsTestFailed(Dem_AllEventsStatusByteCust[EventId]) != reportIsFailed)
        || (!Dem_ISO14229ByteIsTestCompleteTOC(Dem_AllEventsStatusByteCust[EventId]))
#endif
    );
}
