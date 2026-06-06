
#include "Dem_Internal.h"
#include "Rte_Dem.h"

#include "Dem_EventStatus.h"
#include "Dem_MonitorStatus.h"

#include "Dem_Mapping.h"
#include "Dem_Events.h"
#include "Dem_Cfg_Main.h"
#include "Dem_Cfg_EvBuff.h"
#include "Dem_Dependencies.h"
#include "Dem_Nvm.h"
#include "Dem_EventFHandling.h"
#if(DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
#include "FiM.h"
#endif
#include "Dem_Prv_CallEvtStChngdCbk.h"
#include "Dem_Obd.h"
#include "Dem_Prv_CallDtcStChngdCbk.h"
#include "Dem_MonitorStatus.h"

#define DEM_START_SEC_VAR_SAVED_ZONE
#include "Dem_MemMap.h"

DEM_ARRAY_DEFINE(      uint8, Dem_AllEventsStatusByte, DEM_EVENTID_ARRAYLENGTH);

#define DEM_STOP_SEC_VAR_SAVED_ZONE
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

#if DEM_CFG_CUSTOMIZABLEDTCSTATUSBYTE
DEM_ARRAY_DEFINE(      uint8, Dem_AllEventsStatusByteCust, DEM_EVENTID_ARRAYLENGTH);
#endif

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"


/* Called from Dem_Init to validate the Nv block */
void Dem_EventStatusInitCheckNvM(void)
{
    Dem_NvmResultType NvmResult;

    /* Get the Result of the NvM-Read (NvM_ReadAll) */
    NvmResult = Dem_NvmGetStatus (DEM_NVM_ID_EVT_STATUSBYTE);

    /* Data read successfully */
    if (NvmResult != DEM_NVM_SUCCESS)
    {
        /* Set the EventStatus to its default value */
        DEM_MEMSET( &Dem_AllEventsStatusByte, (sint32)DEM_ISO14229BYTE_INITVALUE, DEM_SIZEOF_VAR(Dem_AllEventsStatusByte));

        //Set the Dirty flag
        Dem_NvMWriteBlockImmediate(DEM_NVM_ID_EVT_STATUSBYTE);
    }
}

/* HIS METRIC PATH,v(G) VIOLATION IN Dem_GetEventUdsStatus: Analysis of received payload can not be avoided */
Std_ReturnType Dem_GetEventUdsStatus(Dem_EventIdType EventId,
        Dem_UdsStatusByteType* EventStatusExtended)
{
    DEM_ENTRY_CONDITION_CHECK_DEMINIT_OR_FIM_IS_IN_INIT_OR_OPMO_ALLFAILUREINFOLOCKED_EVTIDVALID_EVTAVAILABLE(EventId, DEM_DET_APIID_DEM_GETEVENTSTATUS , E_NOT_OK);
	DEM_ENTRY_CONDITION_CHECK_NOT_NULL_PTR_WITHEVENTID(EventId,EventStatusExtended,DEM_DET_APIID_DEM_GETEVENTSTATUS,E_NOT_OK);

    *EventStatusExtended = Dem_EvtGetIsoByte(EventId);
    return E_OK;
}

#ifdef RTE_TYPE_H
Std_ReturnType Dem_GetEventUdsStatus_GeneralEvtInfo(Dem_EventIdType EventId,
        Dem_UdsStatusByteType* EventStatusExtended)
{
    return Dem_GetEventUdsStatus(EventId, EventStatusExtended);
}
#endif /* RTE_TYPE_H */

/* Function to query the Last Reported Event Status */

Dem_EventStatusType Dem_EvtGetLastReportedEventStatus (Dem_EventIdType EventId)
{
    return Dem_EvtGetLastReportedEvent(EventId);
}

void Dem_ClearEvent(Dem_EventIdType eventId, boolean ClearFully)
{
    Dem_UdsStatusByteType statusOld, statusNew;
    Dem_UdsStatusByteType dtcStByteOld;

    statusOld = DEM_ISO14229BYTE_INITVALUE;
    statusNew = DEM_ISO14229BYTE_INITVALUE;
    dtcStByteOld = DEM_ISO14229BYTE_INITVALUE;

    if (!Dem_EvtIsSuppressed(eventId))
    {
        DEM_ENTERLOCK_MON();
        Dem_StatusChange_GetOldStatus(eventId, &statusOld, &dtcStByteOld);
        if (ClearFully)
        {
            Dem_EvtSt_HandleClear(eventId);

            statusNew = Dem_EvtGetIsoByte(eventId);

            Dem_EvtSetCausal(eventId, FALSE);
            Dem_EvtSetInitMonitoring(eventId, DEM_INIT_MONITOR_CLEAR);
            Dem_EvtSetLastReportedEvent(eventId, DEM_EVENT_STATUS_INVALIDREPORT);
            Dem_EvtRequestResetFailureFilter(eventId, TRUE);

#if (DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING == DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING_ON)
            if(Dem_EvtParam_GetDebounceMethodIndex (eventId) == DEM_DEBMETH_IDX_ARTIME)
            {
                Dem_DebArTimeDebugValues[Dem_EvtParam_GetDebounceParamSettingIndex(eventId)][0] = 0;
                Dem_DebArTimeDebugValues[Dem_EvtParam_GetDebounceParamSettingIndex(eventId)][1] = 0;
            }
#endif

            /*Reset FDC-Threshold_reached-flags whenever the event is cleared from the event memory*/
           #if(DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD == DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD_ON)
               Dem_EvtSetFDCThresholdReachedTOC(eventId,FALSE);
           #endif
           #if(DEM_CFG_SUPPORT_EVENT_FDCTHRESHOLDREACHED)
               Dem_EvtSetFDCThresholdReached(eventId,FALSE);
           #endif

            if (statusNew != statusOld)
            {
                Dem_ClearIndicatorAttributes(eventId,statusOld,statusNew);
                Dem_ComponentSetRecheckOnClear(Dem_ComponentIdFromEventId(eventId), TRUE);
            }
        }
        else
        {
            Dem_EvtSt_HandleClear_OnlyThisCycleAndReadiness(eventId);
            statusNew = Dem_EvtGetIsoByte(eventId);
        }

        Dem_MonitorStatusHandleClear(eventId, ClearFully);
        DEM_EXITLOCK_MON();
        Dem_TriggerOn_EventStatusChange(eventId,statusOld,statusNew,dtcStByteOld);
    }
}

#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
DEM_INLINE void Dem_InitializeDTCStatusAndUpdateInfo(Dem_DTCStatusAndUpdateInfoType* Dem_DTCStatusAndUpdateInfo)
{
    Dem_DtcIdIterator dtcIt;
    Dem_DtcIdType DtcId;

    for(Dem_DtcIdIteratorNew(&dtcIt); Dem_DtcIdIteratorIsValid(&dtcIt); Dem_DtcIdIteratorNext(&dtcIt))
    {
        DtcId = Dem_DtcIdIteratorCurrent(&dtcIt);
        Dem_DTCStatusAndUpdateInfo[DtcId].isStatusChangeToBeCalculated = FALSE;	/* Initialzing for all DTC Ids done intentionally */
        if(Dem_DtcUsesOrigin(DtcId, DEM_DTC_ORIGIN_PRIMARY_MEMORY))
        {
        	Dem_DTCStatusAndUpdateInfo[DtcId].status = Dem_DtcStatusByteRetrieve (DtcId) & Dem_DtcGetStatusAvailabiltiyMask(DEM_CFG_EVMEM_MEMID_PRIMARY);
		}
    }
}
#endif

void Dem_EvtAdvanceOperationCycle(Dem_OperationCycleList operationCycleList)
{
    Dem_EventIdIterator eventIt;
    Dem_EventIdType eventId;
    Dem_UdsStatusByteType statusNew,statusOld;
    Dem_EventIdType CBeventId[DEM_CFG_ADVANCEOPERATIONCYCLE_EVENTSPERLOCK] = {0};
    Dem_UdsStatusByteType CBStatusOld[DEM_CFG_ADVANCEOPERATIONCYCLE_EVENTSPERLOCK] = {0};
    Dem_UdsStatusByteType CBStatusNew[DEM_CFG_ADVANCEOPERATIONCYCLE_EVENTSPERLOCK] = {0};
    uint32 CBindex=0;
    uint32 i;
    uint32 eventsProcessed = 0;
    Dem_DTCStatusAndUpdateInfoType Dem_DTCStatusAndUpdateInfo[DEM_DTCID_ARRAYLENGTH];

#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
    Dem_InitializeDTCStatusAndUpdateInfo(Dem_DTCStatusAndUpdateInfo);
#endif
    DEM_ENTERLOCK_MON();
    for (Dem_EventIdIteratorNew(&eventIt); Dem_EventIdIteratorIsValid(&eventIt); Dem_EventIdIteratorNext(&eventIt))
    {
        eventsProcessed++;
        eventId = Dem_EventIdIteratorCurrent(&eventIt);
        if (Dem_isEventAffectedByOperationCycleList(eventId, operationCycleList))
        {
            /* Set iso status-byte to next operation cycle */
            statusOld = Dem_EvtGetIsoByte(eventId);
            Dem_EvtSt_HandleNewOperationCycle(eventId);

            Dem_SetIndicatorDeActivation_OnOperationCycleChange(eventId, statusOld, Dem_EvtGetIsoByte(eventId));

            /* Updated Status */
            statusNew = Dem_EvtGetIsoByte(eventId);

            //Reset FDC-Threshold_reached-flag whenever the operation cycle starts/restarts
#if(DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD == DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD_ON)
            Dem_EvtSetFDCThresholdReachedTOC(eventId,FALSE);
#endif
            Dem_EvtSetInitMonitoring(eventId, DEM_INIT_MONITOR_RESTART);
            Dem_EvtRequestResetFailureFilter(eventId, TRUE);
            Dem_EvtSetLastReportedEvent(eventId,DEM_EVENT_STATUS_INVALIDREPORT);

            CBeventId[CBindex]=eventId;
            CBStatusOld[CBindex]=statusOld;
            CBStatusNew[CBindex]=statusNew;
            CBindex++;

        }


        if (eventsProcessed >= DEM_CFG_ADVANCEOPERATIONCYCLE_EVENTSPERLOCK)
        {
            eventsProcessed=0;
            DEM_EXITLOCK_MON();
            for(i=0; i<CBindex; i++)
            {
                Dem_TriggerOn_MultipleEventStatusChange(CBeventId[i],CBStatusOld[i],CBStatusNew[i], Dem_DTCStatusAndUpdateInfo);
            }
            CBindex=0;
            DEM_ENTERLOCK_MON();
        }
    }
    DEM_EXITLOCK_MON();
    for(i=0; i<CBindex; i++)
    {
        Dem_TriggerOn_MultipleEventStatusChange(CBeventId[i],CBStatusOld[i],CBStatusNew[i], Dem_DTCStatusAndUpdateInfo);
    }
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
    Dem_TriggerOn_MultipleDTCStatusChange(Dem_DTCStatusAndUpdateInfo);
#endif
}

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
void Dem_ComponentAdvanceOperationCycle(Dem_OperationCycleList operationCycleList)
{
    Dem_ComponentIdIterator componentIt;
    Dem_ComponentIdType currentComponent;

    Dem_EventIdListIterator2 evtIt;
    Dem_EventIdType eventId;
    uint32 componentProcessed = 0;

    DEM_ENTERLOCK_MON();

    for (Dem_ComponentIdIteratorNew(&componentIt); Dem_ComponentIdIteratorIsValid(&componentIt); Dem_ComponentIdIteratorNext(&componentIt))
    {
        componentProcessed++;
        currentComponent = Dem_ComponentIdIteratorCurrent(&componentIt);

        if (Dem_ComponentIsResetPerformedRecoveriesValueAllowed(currentComponent)){

            for (Dem_EventIdListIterator2NewFromComponentId(&evtIt, currentComponent); Dem_EventIdListIterator2IsValid(&evtIt);
            Dem_EventIdListIterator2Next(&evtIt))
            {
                eventId = Dem_EventIdListIterator2Current(&evtIt);
                if (Dem_isEventAffectedByOperationCycleList(eventId, operationCycleList)) {
                    Dem_ComponentResetPerformedRecoveries(currentComponent);
                    break;
                }
            }
        }
        if (componentProcessed >= DEM_CFG_ADVANCEOPERATIONCYCLE_EVENTSPERLOCK)
        {
            componentProcessed=0;
            DEM_EXITLOCK_MON();
            DEM_ENTERLOCK_MON();
        }
    }

    DEM_EXITLOCK_MON();
}
#endif

Std_ReturnType Dem_OverwriteWIRStatus( Dem_EventIdType EventId, boolean WIRStatus )
{
    Std_ReturnType ret_val = E_NOT_OK;

    if( Dem_isEventIdValid(EventId) )
    {
        DEM_ENTERLOCK_MON();

        if (WIRStatus)
        {
            Dem_EvtSt_HandleIndicatorOn(EventId);
        }
        else
        {
            Dem_EvtSt_HandleIndicatorOff(EventId);
        }

        DEM_EXITLOCK_MON();
        ret_val = E_OK;
    }

    return ret_val;
}

void Dem_UpdateEventStatus(void)
{
    Dem_boolean_least reportIsFailed;
    Dem_EventIdType EventId;
    Dem_EventIdIterator eventIt;
    Dem_UdsStatusByteType isoByteOld, isoByteNew;
    Dem_UdsStatusByteType dtcStByteOld = 0;

    for (Dem_EventIdIteratorNew(&eventIt); Dem_EventIdIteratorIsValid(&eventIt); Dem_EventIdIteratorNext(&eventIt))
    {
        EventId = Dem_EventIdIteratorCurrent(&eventIt);
        isoByteOld = Dem_EvtGetIsoByte(EventId);

        if(Dem_IsMonitorStatusChanged[EventId])
        {
            reportIsFailed = Dem_MonitorStatusByteIsTestFailed(EventId);

            DEM_ENTERLOCK_MON();
            Dem_IsMonitorStatusChanged[EventId] = FALSE;
            /* check event suppression here again to avoid race-conditions to SetEventSuppression */
            if (!Dem_EvtIsSuppressed(EventId))
            {
                reportIsFailed = Dem_MonitorStatusByteIsTestFailed(EventId);    //Calculating the value again to make sure Monitor Status was not changed externally
                Dem_StatusChange_GetOldStatus(EventId, &isoByteOld, &dtcStByteOld);

                if (reportIsFailed)
                {
                    Dem_EvtSt_HandleFailed(EventId);
                    Dem_SetIndicatorActivation(EventId,isoByteOld,Dem_EvtGetIsoByte(EventId));
                }
                else
                {
                    Dem_EvtSt_HandlePassed(EventId);
                    Dem_SetIndicatorDeActivation(EventId, isoByteOld, Dem_EvtGetIsoByte(EventId));
                }
            }
            DEM_EXITLOCK_MON();
        }

        isoByteNew = Dem_EvtGetIsoByte(EventId);

        if(isoByteOld != isoByteNew)
        {
            Dem_TriggerOn_EventStatusChange(EventId,isoByteOld,isoByteNew,dtcStByteOld);
        }
    }
}


#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
