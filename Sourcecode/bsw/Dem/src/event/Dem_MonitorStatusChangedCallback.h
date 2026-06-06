
#ifndef DEM_MONITORSTATUSCHANGEDCALLBACK_H
#define DEM_MONITORSTATUSCHANGEDCALLBACK_H

#if(DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
#include "FiM.h"
#endif
#include "Dem_Cfg_EventsCallback.h"
#include "Dem_EventStatus.h"
#include "Dem_MonitorStatus.h"

DEM_INLINE void Dem_CallBackTriggerOnMonitorStatus(Dem_EventIdType EventId)
{
    DEM_ASSERT_ISNOTLOCKED();
    DEM_UNUSED_PARAM(EventId);
#if (DEM_CFG_MONITOR_STATUS_CHANGE_NUM_CALLBACKS > 0)
    Dem_CallMonitorStatusChangedCallBack(EventId);
#endif
#if (DEM_CFG_GENERAL_MONITOR_ST_CH_CALLBACK == DEM_CFG_GENERAL_MONITOR_ST_CH_CALLBACK_ON)
    Dem_GeneralTriggerOnMonitorStatus(EventId);
#endif
#if (DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
    FiM_DemTriggerOnMonitorStatus(EventId);
#endif
}

#endif
