
#ifndef DEM_PRV_CALLEVTSTCHNGDCBK_H
#define DEM_PRV_CALLEVTSTCHNGDCBK_H

#if(DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
#include "FiM.h"
#endif
#if (DEM_CFG_J1939DCM == DEM_CFG_J1939DCM_ON)
#include "Dem_Prv_J1939Dcm.h"
#endif
#include "Dem_DTCs.h"
#include "Dem_Cfg_EventsCallback.h"
#include "Dem_EventStatus.h"
#include "Dem_Prv_CallDtcStChngdCbk.h"

DEM_INLINE void Dem_CallBackTriggerOnEventStatus (
		Dem_EventIdType EventId,
		Dem_UdsStatusByteType EventStatusOld,
		Dem_UdsStatusByteType EventStatusNew,
		Dem_UdsStatusByteType dtcStByteOld
)
{
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )||(DEM_CFG_J1939DCM == DEM_CFG_J1939DCM_ON)
    Dem_DtcIdType dtcId;
    Dem_UdsStatusByteType dtcStByteNew;
    Dem_DtcCodeType dtcCode;
#endif

    DEM_ASSERT_ISNOTLOCKED();
    DEM_UNUSED_PARAM(dtcStByteOld);
    DEM_UNUSED_PARAM(EventId);
    DEM_UNUSED_PARAM(EventStatusOld);
    DEM_UNUSED_PARAM(EventStatusNew);

#if (DEM_CFG_EVT_UDS_STATUS_CHANGE_NUM_CALLBACKS > 0)
    Dem_CallEventUdsStatusChangedCallBack(EventId, EventStatusOld, EventStatusNew);
#endif

#if (DEM_CFG_GLOBAL_EVT_ST_CH_CALLBACK == DEM_CFG_GLOBAL_EVT_ST_CH_CALLBACK_ON)
    Dem_CallGlobalEventStatusChangedCallBack(EventId, EventStatusOld, EventStatusNew);
#endif

#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )||(DEM_CFG_J1939DCM == DEM_CFG_J1939DCM_ON)
    if ( Dem_EventIdIsDtcAssigned(EventId) )
    {
        dtcId = Dem_DtcIdFromEventId(EventId);
        if ( Dem_DtcIsSupported(dtcId) && (Dem_DtcUsesOrigin(dtcId, DEM_DTC_ORIGIN_PRIMARY_MEMORY)))
        {
            dtcStByteNew = (uint8)(Dem_DtcStatusByteRetrieve (dtcId) & Dem_DtcGetStatusAvailabiltiyMask(DEM_CFG_EVMEM_MEMID_PRIMARY));
            if (dtcStByteNew != dtcStByteOld)
            {
                dtcCode = Dem_GetDtcCode(dtcId);
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
                Dem_CallbackDTCStatusChangedIndication( dtcCode, dtcStByteOld, dtcStByteNew);
#endif
#if (DEM_CFG_J1939DCM == DEM_CFG_J1939DCM_ON)
                Dem_J1939DTCStatusChangedIndicationCallback(dtcId, dtcStByteOld, dtcStByteNew);
#endif
            }
        }
    }
#endif
}

/* MR12 RULE 8.13 VIOLATION: The object addressed by pointer will be changed based on configuration, so it cannot be made constant. This warning can be ignored. */
DEM_INLINE void Dem_CallBackTriggerOnMultipleEventStatus(
        Dem_EventIdType EventId,
        Dem_UdsStatusByteType EventStatusOld,
        Dem_UdsStatusByteType EventStatusNew,
        Dem_DTCStatusAndUpdateInfoType* Dem_DTCStatusAndUpdateInfo)
{
    DEM_UNUSED_PARAM(EventId);
    DEM_UNUSED_PARAM(EventStatusOld);
    DEM_UNUSED_PARAM(EventStatusNew);
    DEM_UNUSED_PARAM(Dem_DTCStatusAndUpdateInfo);

#if (DEM_CFG_EVT_UDS_STATUS_CHANGE_NUM_CALLBACKS > 0)
    Dem_CallEventUdsStatusChangedCallBack(EventId, EventStatusOld, EventStatusNew);
#endif
#if (DEM_CFG_GLOBAL_EVT_ST_CH_CALLBACK == DEM_CFG_GLOBAL_EVT_ST_CH_CALLBACK_ON)
    Dem_CallGlobalEventStatusChangedCallBack(EventId, EventStatusOld, EventStatusNew);
#endif
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
    if ( Dem_EventIdIsDtcAssigned(EventId) )
    {
        Dem_DtcIdType dtcId = Dem_DtcIdFromEventId(EventId);
        if ( Dem_DtcIsSupported(dtcId) && (Dem_DtcUsesOrigin(dtcId, DEM_DTC_ORIGIN_PRIMARY_MEMORY)))
        {
            Dem_DTCStatusAndUpdateInfo[dtcId].isStatusChangeToBeCalculated = TRUE;
        }
    }
#endif
}

DEM_INLINE void Dem_StatusChange_GetOldStatus (
		Dem_EventIdType EventId,
		Dem_UdsStatusByteType *isoByteOld,
		Dem_UdsStatusByteType *dtcStByteOld
)
{
/* BSWEXT-193 */ /* [$DD_BSWCODE 14934] */
#if (( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON ) ||(DEM_CFG_J1939DCM == DEM_CFG_J1939DCM_ON))
/* END BSWEXT-193 */
	Dem_DtcIdType dtcId;
	uint16_least memId;
#endif
	*(isoByteOld) = Dem_EvtGetIsoByte(EventId);
    *dtcStByteOld = 0;
/* BSWEXT-193 */ /* [$DD_BSWCODE 14934] */
#if (( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON ) ||(DEM_CFG_J1939DCM == DEM_CFG_J1939DCM_ON))
/* END BSWEXT-193 */
	if ( Dem_EventIdIsDtcAssigned(EventId) )
	{
		dtcId = Dem_DtcIdFromEventId(EventId);
		if ( Dem_DtcIsSupported(dtcId) )
		{
		    memId = Dem_EvMemGetMemIdForEvent(EventId);
            *(dtcStByteOld) = (uint8)(Dem_DtcStatusByteRetrieve(dtcId) & Dem_DtcGetStatusAvailabiltiyMask(memId));
		}
	}
#else
	(void) dtcStByteOld;
#endif
}

DEM_INLINE void Dem_TriggerOn_EventStatusChange (
        Dem_EventIdType EventId,
        Dem_UdsStatusByteType isoByteOld,
        Dem_UdsStatusByteType isoByteNew,
        Dem_UdsStatusByteType dtcStByteOld
)
{
    if ( isoByteNew != isoByteOld )
    {
        Dem_CallBackTriggerOnEventStatus(EventId,isoByteOld,isoByteNew,dtcStByteOld);
    }
}

DEM_INLINE void Dem_TriggerOn_MultipleEventStatusChange(
        Dem_EventIdType EventId,
        Dem_UdsStatusByteType isoByteOld,
        Dem_UdsStatusByteType isoByteNew,
        Dem_DTCStatusAndUpdateInfoType* Dem_DTCStatusAndUpdateInfo)
{
    if ( isoByteNew != isoByteOld )
    {
        Dem_CallBackTriggerOnMultipleEventStatus(EventId,isoByteOld,isoByteNew, Dem_DTCStatusAndUpdateInfo);
    }
}
#endif

