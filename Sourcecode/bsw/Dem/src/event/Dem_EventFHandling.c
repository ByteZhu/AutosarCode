
#include "Dem_Internal.h"
#include "Rte_Dem.h"

#include "Dem_EventFHandling.h"

#include "Dem_Cfg_Events.h"
#include "Dem_Cfg_Main.h"
#include "Dem_Cfg_Components.h"
#include "Dem_Dependencies.h"
#include "Dem_EventRecheck.h"
#include "Dem_EvBuff.h"
#include "Dem_Deb.h"
#include "Dem_Main.h"
#include "Dem_EventStatus.h"
#include "Dem_ISO14229Byte.h"
#include "Dem_DTCs.h"
#include "Dem_OperationCycle.h"
#if (DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
#include "FiM.h"
#endif
#include "Dem_EvMemGen.h"
#include "Dem_DTCGroup.h"
#include "Dem_Prv_CallEvtStChngdCbk.h"
#include "Dem_MonitorStatusChangedCallback.h"
#include "Dem_Obd.h"
#include "Dem_Events.h"
#include "Dem_RingBuffer.h"
#if (DEM_CFG_EVT_PROJECT_EXTENSION)
#include "Dem_PrjEvtProjectExtension.h"
#endif
#include "Dem_Lib.h"
#include "Dem_Cfg_Events_DataStructures.h"
#include "Dem_MonitorStatus.h"

/***** REPORT ERRORSTATUS *****************************************************/

typedef struct
{
   Dem_EventStatusType EventStatus;
   Dem_EventIdType EventId;
#if(DEM_CFG_MONITORDATA_BEFOREINIT == DEM_CFG_MONITORDATA_BEFOREINIT_ON)
   Dem_MonitorDataType monitorData0;
   Dem_MonitorDataType monitorData1;
#endif
} Dem_ErrorQueueType;

#if(DEM_CFG_MONITORDATA_BEFOREINIT == DEM_CFG_MONITORDATA_BEFOREINIT_ON)
#define DEM_ERRORQUEUETYPE_INIT {0,DEM_EVENTID_INVALID,0,0}
#else
#define DEM_ERRORQUEUETYPE_INIT {0,DEM_EVENTID_INVALID}
#endif


typedef struct
{
   uint8 overflowcounter;
   boolean isQueueEnabled;
} Dem_ErrorQueueControlType;

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

/* Variable which holds the indexing information of the ring buffer */
/* MR12 RULE 20.7 VIOLATION: Functions like MACROS do not need to be parenthesized.*/
DEM_DEFINE_RINGBUFFER(Dem_ErrorQueueType, Dem_ErrorQueue, DEM_CFG_BSWERRORBUFFERSIZE);
/* ring buffer for queueing of events reporting unrobust before the Dem has been initialized */
#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)
/* MR12 RULE 20.7 VIOLATION: Functions like MACROS do not need to be parenthesized.*/
DEM_DEFINE_RINGBUFFER(Dem_ErrorQueueType, Dem_UnrobustErrorQueue, DEM_CFG_BSWERRORBUFFERSIZE);
static Dem_ErrorQueueControlType Dem_UnrobustQueueControl;
#endif
static Dem_ErrorQueueControlType Dem_ErrorQueueControl;

#if(DEM_CFG_ALLOW_HISTORY == DEM_CFG_ALLOW_HISTORY_ON)
static boolean Dem_HistoryStatusAllowed;
#endif

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

/* -- Special handling for timebased debouncing -- */
#if (DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING == DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING_ON)
Dem_MonitorDataType Dem_DebArTimeDebugValues[DEM_CFG_DEBARTIME_PARAMSET1_LENGTH][2];
#endif
/* ------------------------------------------------*/

DEM_ARRAY_DEFINE(boolean, Dem_IsMonitorStatusChanged, DEM_EVENTID_ARRAYLENGTH);

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_CFG_TESTMODE_SUPPORT == DEM_CFG_TESTMODE_SUPPORT_ON)
/* Offset to increment EventId in case Test Mode is active */
#define DEM_TESTMODE_EVENTID_OFFSET     10000u
#define DEM_DECODE_SUCCESSFULL         TRUE
#define DEM_DECODE_NOT_SUCCESSFULL     FALSE

#define DEM_START_SEC_VAR_INIT
#include "Dem_MemMap.h"
/* Variable which provides information on the reporting - Normal reporting (FALSE)/ Test Mode reporting (TRUE)*/
static boolean Dem_TestModeActive=FALSE;
#define DEM_STOP_SEC_VAR_INIT
#include "Dem_MemMap.h"
#endif

/* The flag is set to TRUE if the API Dem_SetEventStatus is called, in order to identifier which service DET function to be called  */
#define DEM_START_SEC_VAR_INIT
#include "Dem_MemMap.h"
static boolean Dem_isSetEventStatusCalled = FALSE;
#define DEM_STOP_SEC_VAR_INIT
#include "Dem_MemMap.h"

#if (DEM_CFG_TESTMODE_SUPPORT == DEM_CFG_TESTMODE_SUPPORT_ON)
DEM_INLINE boolean Dem_DecodeTestModeEventId (Dem_EventIdType *EventId)
{
    if(Dem_TestModeActive)
    {
        /* Check if event ID is valid for Test Mode */
        if(*EventId >= DEM_TESTMODE_EVENTID_OFFSET)
        {   /* Remove Offset from EventId in Test Mode*/
            *EventId = *EventId-DEM_TESTMODE_EVENTID_OFFSET;
            return DEM_DECODE_SUCCESSFULL;
        }
        else
        {   /* Event ID sent is invalid */
            return DEM_DECODE_NOT_SUCCESSFULL;
        }
    }
    else
    {
        /* Check if event ID is valid for Test Mode */
        if(*EventId >= DEM_TESTMODE_EVENTID_OFFSET)
        {   /* Event ID sent is invalid in Normal mode */
            return DEM_DECODE_NOT_SUCCESSFULL;
        }
        else
        {
            return DEM_DECODE_SUCCESSFULL;
        }
    }
}

/* This API needs to be called only for Test Mode */
DEM_INLINE void Dem_EncodeTestModeEventId (Dem_EventIdType *EventId)
{
    *EventId = (*EventId + DEM_TESTMODE_EVENTID_OFFSET);
}
#endif

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Std_ReturnType  Dem_SetEventStatus(Dem_EventIdType     EventId,
                                              Dem_EventStatusType EventStatus)
{
   Dem_isSetEventStatusCalled = TRUE;
   return Dem_SetEventStatusWithMonitorData (EventId, EventStatus, 0, 0);
}


/*-- FAILURE HANDLING --------------------------------------------------------*/

/* HIS METRIC PATH,v(G) VIOLATION IN Dem_UpdateEventStatusWithMonitorData: Analysis of received payload can not be avoided */
static Std_ReturnType Dem_UpdateEventStatusWithMonitorData (Dem_EventIdType EventId,
                                                            Dem_EventStatusType EventStatus,
                                                            Dem_MonitorDataType monitorData0,
                                                            Dem_MonitorDataType monitorData1)
{
	uint8_least debAction;
	Dem_boolean_least continueProcessing = TRUE;
#if (DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING == DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING_ON)
	uint16 indexMonDataTimeBased = 0;
#endif
	uint8 ApiId = DEM_DET_APIID_SETEVENTSTATUSWITHMONITORDATA;

 #if (DEM_CFG_TESTMODE_SUPPORT == DEM_CFG_TESTMODE_SUPPORT_ON)
    /* Decode the Event ID depending on whether Test mode is active/inactive */
    if(Dem_DecodeTestModeEventId(&EventId) == DEM_DECODE_NOT_SUCCESSFULL)
    {
        return E_NOT_OK;
    }

 #endif

#if(DEM_CFG_LOCK_ALLFAILUREINFO == DEM_CFG_LOCK_ALLFAILUREINFO_ON)
	if (Dem_OpMoIsAllFailureInfoLocked())
	{
		return E_NOT_OK;
	}
#endif

	if (Dem_isSetEventStatusCalled)
	{
	    Dem_isSetEventStatusCalled = FALSE;
	    ApiId = DEM_DET_APIID_SETEVENTSTATUS;
	}
    DEM_ENTRY_CONDITION_CHECK_INIT_EVTIDVALID_EVTAVAILABLE(EventId, ApiId,E_NOT_OK);

	if (Dem_IsPendingClearEvent(EventId))
    {
        return E_NOT_OK;
    }

	DEM_ENTERLOCK_MON();
	continueProcessing = Dem_DebHandleResetConditions(EventId);
	DEM_EXITLOCK_MON();
    if(!continueProcessing)
    {
        return E_NOT_OK;
    }

	/* [SWS_Dem_01279] */
	debAction = Dem_DebCallFilter(EventId, &EventStatus);
	/*set the last reported event status*/
	Dem_EvtSetLastReportedEvent (EventId, EventStatus);

#if (DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING == DEM_CFG_MONITORDATA_FORTIMEBASEDDEBOUNCING_ON)
    if(Dem_EvtParam_GetDebounceMethodIndex (EventId) == DEM_DEBMETH_IDX_ARTIME)
    {
        indexMonDataTimeBased = Dem_EvtParam_GetDebounceParamSettingIndex(EventId);
        if (indexMonDataTimeBased < DEM_CFG_DEBARTIME_PARAMSET1_LENGTH)
        {
            if( EventStatus == DEM_EVENT_STATUS_PREFAILED)
            {

                Dem_DebArTimeDebugValues[indexMonDataTimeBased][0] = monitorData0;
                Dem_DebArTimeDebugValues[indexMonDataTimeBased][1] = monitorData1;
            }
            else if( EventStatus == DEM_EVENT_STATUS_PREPASSED)
            {
                Dem_DebArTimeDebugValues[indexMonDataTimeBased][0] = 0;
                Dem_DebArTimeDebugValues[indexMonDataTimeBased][1] = 0;
            }else{
                /* nothing to do */
            }
        }
        else
        {
            /* Should never happen */
            indexMonDataTimeBased = 0;
        }
    }
#endif


	if (debAction != DEM_DEBACTION_NOOP)
	{
		Dem_DebHandleDebounceAction(EventId, debAction, monitorData0, monitorData1);
	}

#if (DEM_CFG_EVT_PROJECT_EXTENSION)
	Dem_EvtProjectExtensionSetEventStatus(EventId, EventStatus, debAction);
#endif

	if ((EventStatus == DEM_EVENT_STATUS_PASSED) || (EventStatus == DEM_EVENT_STATUS_FAILED))
	{

#if (DEM_CFG_SETEVENTSTATUSALLOWEDCALLBACK == DEM_CFG_SETEVENTSTATUSALLOWEDCALLBACK_ON)
		if (Dem_SetEventStatusAllowedHook(EventId, EventStatus) == E_OK)
#endif
		{
			Dem_EvtProcessPassedAndFailed (EventId, EventStatus, monitorData0, monitorData1);
		}
	}

	/*--------DISTURBANCE_MEMORY---------------------------------------------------------------------------------*/
#if(DEM_CFG_DISTURBANCE_MEMORY == DEM_CFG_DISTURBANCE_MEMORY_ON)
	if(Dem_DistMemIsReportFailedNecessary(EventId, EventStatus))
	{
		Dem_DistMemReportFailed(EventId, monitorData0, monitorData1);
	}
#endif

	if (EventStatus == DEM_EVENT_STATUS_FAILED)
	{
		Dem_EvMemGenReportFailedEvent(EventId);
	}

	return E_OK;
}



Std_ReturnType Dem_GetEventFailed(Dem_EventIdType EventId, boolean* EventFailed)
{
    DEM_ENTRY_CONDITION_CHECK_EVENT_ID_VALID_AVAILABLE(EventId,DEM_DET_APIID_DEM_GETEVENTFAILED,E_NOT_OK);
    DEM_ENTRY_CONDITION_CHECK_NOT_NULL_PTR_WITHEVENTID(EventId,EventFailed,DEM_DET_APIID_DEM_GETEVENTFAILED,E_NOT_OK);

    if(Dem_GetTestFailedInitState() == FALSE)
    {
        DEM_DET(DEM_DET_APIID_DEM_GETEVENTFAILED, DEM_E_UNINIT,EventId);
        return E_NOT_OK;
    }
    else
    {
        *EventFailed = (boolean)Dem_EvtSt_GetTestFailed(EventId);
        return E_OK;
    }
}

#ifdef RTE_TYPE_H
Std_ReturnType Dem_GetEventFailed_GeneralEvtInfo(Dem_EventIdType EventId, boolean* EventFailed)
{
    return Dem_GetEventFailed(EventId, EventFailed);
}
#endif /* RTE_TYPE_H */

/* MR12 RULE 8.13 VIOLATION: The object addressed by pointer will be changed based on configuration, so it cannot be made constant. This warning can be ignored. */
Std_ReturnType Dem_GetEventFdcThresholdReached(Dem_EventIdType EventId, boolean* FdcThresholdReached)
{
#if (DEM_CFG_SUPPORT_EVENT_FDCTHRESHOLDREACHED)
    if(Dem_EvtIsSuppressed(EventId))
    {
        return E_NOT_OK;
    }

    *FdcThresholdReached = (boolean)Dem_EvtGetFDCThresholdReached(EventId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(EventId);
    DEM_UNUSED_PARAM(FdcThresholdReached);
    return E_NOT_OK;
#endif
}

void Dem_PreInitErrorQueue(void)
{
    //Initialize the Dem_ErrorQueue ring buffer
    Dem_RingBuffer__Init(Dem_ErrorQueue);
#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)
    Dem_RingBuffer__Init(Dem_UnrobustErrorQueue);
#endif
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/* MR12 RULE 2.7 VIOLATION: Based on the config of the macro using the parameter ApiId, it might not be used in the function*/
static void Dem_FillDataInRingBuffer(Dem_ErrorQueueType ErrorEvent,Dem_ErrorQueueType *ErrorQue,Dem_RingBuffer *ErrorQueue_Handler,
        Dem_ErrorQueueControlType *ErrorQueueControl,uint8 Apild)
{
   uint16 indx;
   boolean islocationvalid = TRUE;
   boolean isInBuffer = FALSE;

   DEM_ASSERT_ISLOCKED();
   /* MR12 RULE 14.2 VIOLATION: Ring buffer implementation needs a loop control variable of file scope */
    for (Dem_RingBuffer__NewIterator (ErrorQueue_Handler); Dem_RingBuffer__IteratorIsValid (ErrorQueue_Handler);
    Dem_RingBuffer__IteratorNext(ErrorQueue_Handler))
    {
        if((ErrorQue[ErrorQueue_Handler->RingBuffLocIt].EventId) == ErrorEvent.EventId)
        {
            indx = ErrorQueue_Handler->RingBuffLocIt;
            isInBuffer = TRUE;
            break;
        }
    }

   if(!isInBuffer)
   {
       if(!Dem_RingBuffer__insert(ErrorQueue_Handler, &indx))
       {
           ErrorQueueControl->overflowcounter++;

           /* MR12 RULE 2.7 VIOLATION: Based on the config of the macro using the parameter ApiId, it might not be used in the function*/
           DEM_DET(Apild,ErrorQueueControl->overflowcounter,ErrorEvent.EventId);
           islocationvalid = FALSE;
       }
   }

   if(islocationvalid)
   {
       ErrorQue[indx].EventId = ErrorEvent.EventId;
       ErrorQue[indx].EventStatus = ErrorEvent.EventStatus;
#if(DEM_CFG_MONITORDATA_BEFOREINIT == DEM_CFG_MONITORDATA_BEFOREINIT_ON)
       ErrorQue[indx].monitorData0 = ErrorEvent.monitorData0;
       ErrorQue[indx].monitorData1 = ErrorEvent.monitorData1;

#endif
   }
}


DEM_INLINE void Dem_ReportErrorStatusEnqueue( Dem_EventIdType EventId, Dem_EventStatusType EventStatus,
        Dem_MonitorDataType monitorData0, Dem_MonitorDataType monitorData1)
{

    Dem_ErrorQueueType TempErrorEvent = DEM_ERRORQUEUETYPE_INIT;

    TempErrorEvent.EventId = EventId;
    TempErrorEvent.EventStatus = EventStatus;
#if(DEM_CFG_MONITORDATA_BEFOREINIT == DEM_CFG_MONITORDATA_BEFOREINIT_ON)
    TempErrorEvent.monitorData0 = monitorData0;
    TempErrorEvent.monitorData1 = monitorData1;
#else
    DEM_UNUSED_PARAM(monitorData0);
    DEM_UNUSED_PARAM(monitorData1);
#endif

    /* Call Ring Buffer API to update the error data  */
    Dem_FillDataInRingBuffer(TempErrorEvent,&Dem_ErrorQueue[0],&Dem_ErrorQueue_Handler,
            &Dem_ErrorQueueControl,DEM_DET_APIID_REPORERRORSTATUSQUEUE);
}


#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)

DEM_INLINE void Dem_UnrobustEventEnqueue(Dem_EventIdType EventId, Dem_EventStatusType EventStatus,
       Dem_MonitorDataType monitorData0, Dem_MonitorDataType monitorData1)
{
    Dem_ErrorQueueType TempErrorEvent = DEM_ERRORQUEUETYPE_INIT;

       TempErrorEvent.EventId = EventId;
       TempErrorEvent.EventStatus = EventStatus;
#if(DEM_CFG_MONITORDATA_BEFOREINIT == DEM_CFG_MONITORDATA_BEFOREINIT_ON)
       TempErrorEvent.monitorData0 = monitorData0;
       TempErrorEvent.monitorData1 = monitorData1;
#else
       DEM_UNUSED_PARAM(monitorData0);
       DEM_UNUSED_PARAM(monitorData1);
#endif
    /* Call Ring Buffer API to update the error data  */
    Dem_FillDataInRingBuffer(TempErrorEvent,&Dem_UnrobustErrorQueue[0],&Dem_UnrobustErrorQueue_Handler,
                              &Dem_UnrobustQueueControl,DEM_DET_APIID_REPORTUNROBUSTQUEUEOVERFLOW);
}

#endif

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_CFG_EVT_PROJECT_EXTENSION)
static void Dem_PrjEvtStatusCallTrigger(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    uint8_least debAction = DEM_DEBACTION_NOOP;
#if(DEM_CFG_SUPPORT_EVENT_FDCTHRESHOLDREACHED)
    if(EventStatus == DEM_EVENT_STATUS_FAILED)
    {
        debAction |= DEM_DEBACTION_SETFDCTHRESHOLDREACHED;
   }
    else if(EventStatus == DEM_EVENT_STATUS_PASSED)
    {
            debAction |= DEM_DEBACTION_RESETFDCTHRESHOLDREACHED;
    }
   else
    {
            /* do nothing */
            /* prepassed and prefailed are not possible during init phase */
    }
#endif

    Dem_EvtProjectExtensionSetEventStatus(EventId, EventStatus, debAction);
}
#endif

static void Dem_ReportErrorStatusDequeue(Dem_ErrorQueueControlType *queueControl, Dem_RingBuffer *queueHandler,
        DEM_ARRAY_CONSTFUNCPARAM(Dem_ErrorQueueType,queue))
{
    Dem_ErrorQueueType tmpErrorEvent = DEM_ERRORQUEUETYPE_INIT;
    uint16 removedIndex = 0;
    boolean eventAvailableForProcessing = TRUE;
    Dem_MonitorDataType mData0, mData1;


    while (queueControl->isQueueEnabled)
    {
        /*Check whether the event is removed or not from RingBuffer*/
        DEM_ENTERLOCK_MON();
        if(Dem_RingBuffer__remove(queueHandler,&removedIndex))
        {
            /* an event was removed and now is copied for processing*/
            DEM_MEMCPY( &tmpErrorEvent, &queue[removedIndex], DEM_SIZEOF_TYPE(Dem_ErrorQueueType));
        }
        else
        {
            /* there was no further event in the queue (remove failed)*/
            queueControl->isQueueEnabled = FALSE;
            queueControl->overflowcounter = 0;

            /*Set the flag to FALSE as there are no further events to be processed*/
            eventAvailableForProcessing = FALSE;
        }
        DEM_EXITLOCK_MON();

        if(eventAvailableForProcessing && !Dem_EvtIsSuppressed(tmpErrorEvent.EventId))
        {
#if (DEM_CFG_EVT_PROJECT_EXTENSION)
            Dem_PrjEvtStatusCallTrigger(tmpErrorEvent.EventId, tmpErrorEvent.EventStatus);
#endif

#if(DEM_CFG_MONITORDATA_BEFOREINIT == DEM_CFG_MONITORDATA_BEFOREINIT_ON)
            mData0 = tmpErrorEvent.monitorData0;
            mData1 = tmpErrorEvent.monitorData1;
#else
            mData0 = 0;
            mData1 = 0;
#endif

                if (&queue[0] == &Dem_ErrorQueue[0])
                {
                    Dem_EvtProcessPassedAndFailed (tmpErrorEvent.EventId, tmpErrorEvent.EventStatus, mData0, mData1);
                }

#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)
            else
                /* unrobustness queue */
            {
                    (void)Dem_EvBuffInsert(C_EVENTTYPE_UNROBUST, tmpErrorEvent.EventId, mData0, mData1);
            }
#endif

            if (&queue[0] == &Dem_ErrorQueue[0])
            {
#if(DEM_CFG_DISTURBANCE_MEMORY == DEM_CFG_DISTURBANCE_MEMORY_ON)
                if(Dem_DistMemIsReportFailedNecessary(tmpErrorEvent.EventId, tmpErrorEvent.EventStatus))
                {
                    Dem_DistMemReportFailed(tmpErrorEvent.EventId, mData0, mData1);
                }
#endif
            }
        }
    }
}


void Dem_ReportErrorStatusDisableQueue(void)
{
    Dem_ReportErrorStatusDequeue(&Dem_ErrorQueueControl, &Dem_ErrorQueue_Handler, Dem_ErrorQueue);
#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)
    Dem_ReportErrorStatusDequeue(&Dem_UnrobustQueueControl, &Dem_UnrobustErrorQueue_Handler, Dem_UnrobustErrorQueue);
#endif
}


void Dem_ReportErrorStatusEnableQueue(void)
{
    DEM_ENTERLOCK_MON();
	if (!Dem_ErrorQueueControl.isQueueEnabled)
	{
		Dem_ErrorQueueControl.isQueueEnabled = TRUE;
		Dem_ErrorQueueControl.overflowcounter = 0;
	}

#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)
	if (!Dem_UnrobustQueueControl.isQueueEnabled)
	{
	    Dem_UnrobustQueueControl.isQueueEnabled = TRUE;
	    Dem_UnrobustQueueControl.overflowcounter = 0;
	}
#endif

	DEM_EXITLOCK_MON();
}


/*----------------------------------------------------------------------------*/

/* HIS METRIC PATH,v(G) VIOLATION IN Dem_SetEventStatusWithMonitorData: Analysis of received payload can not be avoided */
Std_ReturnType Dem_SetEventStatusWithMonitorData( Dem_EventIdType EventId,
		                               Dem_EventStatusType EventStatus,
                                       Dem_MonitorDataType monitorData0,
                                       Dem_MonitorDataType monitorData1)
{
	uint8_least debAction;
    Dem_boolean_least callSetEventStatus;
    uint8 ApiId = DEM_DET_APIID_SETEVENTSTATUSWITHMONITORDATA;

#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)
	const uint8_least allowEnqueueUnrobust = (DEM_DEBACTION_ALLOW_BUFFER_INSERT | DEM_DEBACTION_SETFDCTHRESHOLDREACHED);
#endif

#if(DEM_CFG_LOCK_ALLFAILUREINFO == DEM_CFG_LOCK_ALLFAILUREINFO_ON)
    if (Dem_OpMoIsAllFailureInfoLocked())
    {
        return E_NOT_OK;
    }
#endif


    #if (DEM_CFG_TESTMODE_SUPPORT == DEM_CFG_TESTMODE_SUPPORT_ON)
	/* Decode the Event ID depending on whether Test mode is active/inactive */
	if(Dem_DecodeTestModeEventId(&EventId) == DEM_DECODE_NOT_SUCCESSFULL)
	{
	    return E_NOT_OK;
	}
    #endif

	if (Dem_isSetEventStatusCalled)
	{
	    Dem_isSetEventStatusCalled = FALSE;
	    ApiId = DEM_DET_APIID_SETEVENTSTATUS;
	}

	DEM_ENTRY_CONDITION_CHECK_PREINIT_EVTIDVALID_EVTAVAILABLE(EventId,ApiId,E_NOT_OK);

	if ((Dem_OpMoState != DEM_OPMO_STATE_INITIALIZED) && (!Dem_EvtParam_GetIsKindBSW(EventId)))
	{
	    DEM_DET(ApiId, DEM_E_UNINIT,EventId);
	    return E_NOT_OK;
	}

   /* due to runtime issues during normal operation, the case isInit shall be checked first */
   if(!Dem_ErrorQueueControl.isQueueEnabled)
   {
        #if (DEM_CFG_TESTMODE_SUPPORT == DEM_CFG_TESTMODE_SUPPORT_ON)
        if(Dem_TestModeActive)
		{
		    Dem_EncodeTestModeEventId(&EventId);
		}
        #endif
	    return(Dem_UpdateEventStatusWithMonitorData(EventId,EventStatus ,monitorData0,monitorData1));

	} else
	{


      /* MR12 RULE 13.5 VIOLATION: Getter function is identified as an expression causing side effect. This warning can be ignored. */
      if(Dem_EvtAllEnableConditionsFulfilled(EventId) &&
              Dem_IsEventReportingEnabledByDtcSetting(EventId))
        {
         debAction = Dem_DebCallFilter(EventId, &EventStatus);
         /*set the last reported event status*/
         Dem_EvtSetLastReportedEvent (EventId, EventStatus);

         if (debAction != DEM_DEBACTION_NOOP)
         {
           Dem_DebHandleDebounceAction(EventId, debAction, monitorData0, monitorData1);
#if (DEM_CFG_QUEUEING_UNROBUST_EVENTS_SUPPORTED)
           if((debAction & allowEnqueueUnrobust) == allowEnqueueUnrobust)
           {
               DEM_ENTERLOCK_MON();
               if(Dem_UnrobustQueueControl.isQueueEnabled)
               {
                   Dem_UnrobustEventEnqueue(EventId, EventStatus, monitorData0, monitorData1);

               }
               DEM_EXITLOCK_MON();
           }
#endif
         }
         if ((EventStatus == DEM_EVENT_STATUS_PASSED) || (EventStatus == DEM_EVENT_STATUS_FAILED))
         {
             DEM_ENTERLOCK_MON();
             /* insert to FIFO and check preinit-status again => needs to be atomic */
             if(Dem_ErrorQueueControl.isQueueEnabled)
             {
                 /* MR12 RULE 20.7 VIOLATION: Functions like MACROS do not need to be parenthesized.*/
                 Dem_ReportErrorStatusEnqueue(EventId, EventStatus,monitorData0,monitorData1);
                 /* do not call Dem_DistMemReportFailed as the NVM probably was not read yet */
                 callSetEventStatus = FALSE;
             }
             else
             {
                 callSetEventStatus = TRUE;
             }

             DEM_EXITLOCK_MON();

             if (callSetEventStatus)
             {
                 return(Dem_UpdateEventStatusWithMonitorData(EventId,EventStatus ,monitorData0,monitorData1));
             }

         }

        }

	}
	/* Return E_OK  in  following cases
	 *    Sucessful stoarage of queuing events
	 *    If enable conditions are not fullfiled(as event status update to be ignored)
	 *    Also if DTC reporting is disbaled (as event status update to be ignored)
	 */
	return E_OK;
}


/* HIS METRIC PATH VIOLATION IN Dem_ResetEventStatus: Analysis of received payload can not be avoided */
Std_ReturnType Dem_ResetEventStatus(Dem_EventIdType EventId)
{
	Dem_UdsStatusByteType isoByteOld, isoByteNew, evtStatus;
	Dem_UdsStatusByteType dtcStByteOld = 0;

#if(DEM_CFG_LOCK_ALLFAILUREINFO == DEM_CFG_LOCK_ALLFAILUREINFO_ON)
	if (Dem_OpMoIsAllFailureInfoLocked())
	{
		return E_NOT_OK;
	}
#endif

	DEM_ENTRY_CONDITION_CHECK_INIT_EVTIDVALID_EVTAVAILABLE(EventId, DEM_DET_APIID_RESETEVENTSTATUS,E_NOT_OK);

	evtStatus = Dem_EvtGetIsoByte(EventId);

	if(Dem_ISO14229ByteIsTestCompleteTOC(evtStatus))
	{
	    return E_NOT_OK;
	}

	if (Dem_EnCoAreAllFulfilled(Dem_EvtParam_GetEnableConditionGroupIndex(EventId)))
	{
		DEM_ENTERLOCK_MON();
		Dem_StatusChange_GetOldStatus(EventId, &isoByteOld, &dtcStByteOld);
		Dem_EvtRequestResetFailureFilter(EventId, TRUE);
		Dem_EvtSetLastReportedEvent(EventId, DEM_EVENT_STATUS_INVALIDREPORT);
		Dem_EvtSt_HandleResetEventStatus(EventId);
		isoByteNew = Dem_EvtGetIsoByte(EventId);


		DEM_EXITLOCK_MON();

		Dem_TriggerOn_EventStatusChange(EventId,isoByteOld,isoByteNew,dtcStByteOld);

		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}


DEM_INLINE void Dem_SetHistoryStatus (Dem_EventIdType EventId)
{
#if(DEM_CFG_ALLOW_HISTORY == DEM_CFG_ALLOW_HISTORY_ON)
    if (Dem_HistoryStatusAllowed && (!Dem_EvtGetHistoryStatus(EventId)))
    {
        DEM_ENTERLOCK_MON();
        Dem_EvtSetHistoryStatus(EventId, TRUE);
        DEM_EXITLOCK_MON();
    }
#else
    DEM_UNUSED_PARAM (EventId);
#endif
}

#if(DEM_CFG_IS_EVERY_TEST_FAILED_TRIGGER_CONFIGURED)
DEM_INLINE void Dem_UpdateEvBufferOnEveryTestFailed(Dem_EventIdType EventId, boolean reportIsFailed,
        Dem_MonitorDataType monitorData0, Dem_MonitorDataType monitorData1)
{
    if((Dem_EvtParam_GetisTriggerOnEveryTestFailedConfigured(EventId)) && (reportIsFailed))
    {
        /* update event type */
        (void)Dem_EvBuffInsert (C_EVENTTYPE_UPDATE_FREEZE_FRAME, EventId,monitorData0,monitorData1);
    }
}
#endif

/* HIS METRIC PATH,v(G) VIOLATION IN Dem_EvtProcessPassedAndFailed: Analysis of received payload can not be avoided */
void Dem_EvtProcessPassedAndFailed (Dem_EventIdType EventId, Dem_EventStatusType EventStatus,
        Dem_MonitorDataType monitorData0, Dem_MonitorDataType monitorData1)
{
    Dem_ComponentIdType ComponentId;
    Dem_boolean_least reportIsFailed = FALSE;
    boolean oldCausal, newCausal, storageFiltered;
    Dem_MonitorStatusType monitorStatusByteNew;
    Dem_EvBuffEventType eventType = C_EVENTTYPE_NOEVENT;
    Dem_UdsStatusByteType isoByteOld;
    Dem_UdsStatusByteType dtcStByteOld = 0;

    if (EventStatus != DEM_EVENT_STATUS_PASSED)
    {
        reportIsFailed = TRUE;
        Dem_SetHistoryStatus(EventId);
    }

    if (   (!Dem_MonSt_IsUpdateNeeded(EventId, reportIsFailed))
        && (!Dem_EvtIsStorageFiltered(EventId))
        && (!Dem_EvtIsRecheckedAndWaitingForMonResult(EventId))
        && (!Dem_EvtIsNextReportRelevantForMemories(EventId))
       )
    {
        /* In case the trigger on every test failed is configured a freeze frame update is needed */
#if(DEM_CFG_IS_EVERY_TEST_FAILED_TRIGGER_CONFIGURED)
        Dem_UpdateEvBufferOnEveryTestFailed (EventId, reportIsFailed, monitorData0, monitorData1);
#endif
        return;
    }


    ComponentId = Dem_ComponentIdFromEventId(EventId);
    Dem_StatusChange_GetOldStatus(EventId, &isoByteOld, &dtcStByteOld);

    /*  move hint to uml diagram
     * HINT: CausalFailure influences failure recovery.
     *       If causalfailure is not set, an unrecoverable failure may be healed
     */

    /*********************************************************
     * isobyte-calculation and status change notification
     */

    DEM_ENTERLOCK_MON();
    if (EventStatus != DEM_EVENT_STATUS_PASSED)
    {
		/* [SWS_Dem_01280] */
        Dem_MonitorStatus_HandleFailed(EventId);
        Dem_IsMonitorStatusChanged[EventId] = TRUE;
    }
    else
    {
        if(Dem_EvtIsRecoverable(EventId))		/* [SWS_Dem_01208] */
        {
			/* [SWS_Dem_01280] */
            Dem_MonitorStatus_HandlePassed(EventId);
            Dem_IsMonitorStatusChanged[EventId] = TRUE;
        }
    }
    DEM_EXITLOCK_MON();

    monitorStatusByteNew = Dem_EvtGetMonitorStatusByte(EventId);
    Dem_CallBackTriggerOnMonitorStatus(EventId);

    if (    reportIsFailed
         && Dem_EvtIsCausal(EventId)
         && !Dem_StoCoAreAllFulfilled(Dem_EvtParam_GetStorageConditionGroupIndex(EventId))
       )
    {
        /* Do not consider failure report if monitoring already is causal and currently
         * storageconditions are not fulfilled;     Do consider reset-fault   => CSCRM00213362
         */
        return;
    }
    /*********************************************************
     * failure dependency related calculation */

    DEM_ENTERLOCK_MON();
    if (monitorStatusByteNew == Dem_EvtGetMonitorStatusByte(EventId)) /* consider multitasking: event might be cleared inbetween */
    {

        if (reportIsFailed)
        {
            boolean checkIsCausal = Dem_Dependencies_CheckEventIsCausal(EventId, ComponentId);
            /* MR12 RULE 13.5 VIOLATION: Getter function is identified as an expression causing side effect. This warning can be ignored. */
            storageFiltered = !Dem_StoCoAreAllFulfilled(Dem_EvtParam_GetStorageConditionGroupIndex(EventId))
                            || (Dem_GetComponentAreAllFailedFiltered(ComponentId) && !checkIsCausal);
            oldCausal = Dem_EvtIsCausal(EventId);
            newCausal = oldCausal || (checkIsCausal && !storageFiltered);

            Dem_EvtSetStorageFiltered (EventId, storageFiltered);
            Dem_EvtSetCausal (EventId, newCausal);
            Dem_Dependencies_SetComponentFailed ( ComponentId, newCausal, storageFiltered, (Dem_EvtParam_GetIsRecoverable(EventId) && Dem_ComponentRecoveryAllowed(Dem_ComponentIdFromEventId(EventId))) );

            if (checkIsCausal)
            {
                if (!storageFiltered)
                {
                    eventType = C_EVENTTYPE_SET;
                    if (oldCausal)
                    {
                        eventType = C_EVENTTYPE_SET_RECONFIRMED;
                    }
                } else
                {
                    Dem_StoCoSetHasFilteredEvent(Dem_EvtParam_GetStorageConditionGroupIndex(EventId),(Dem_MonitorDataType)EventId,monitorData1);
                }
            } else
            {
                if (oldCausal) {
                    eventType = C_EVENTTYPE_SET_RECONFIRMED;
                }
            }
        }
        else
        {
            if (!Dem_MonitorStatusByteIsTestFailed(EventId))
            {
                    if (Dem_EvtIsCausal(EventId))
                    {
                        Dem_EvtSetCausal (EventId, FALSE);
                        Dem_ComponentSetRecovered(ComponentId);
                    }
#if(DEM_CFG_STORAGECONDITIONBLOCKSPASSEDREPORTS)
                    if (Dem_StoCoAreAllFulfilled(Dem_EvtParam_GetStorageConditionGroupIndex(EventId)) )
#endif
                    {
                        /* if event is stored from prev OC and testfailed was not stored */
                        if (  (
                                (Dem_ISO14229ByteIsTestFailed(isoByteOld)
                                        || Dem_ISO14229ByteIsConfirmedDTC(isoByteOld)
                                        || Dem_ISO14229ByteIsPendingDTC(isoByteOld))
                                        && (!Dem_EvtIsStorageFiltered(EventId))
                               )
                                        ||Dem_EvtIsNextReportRelevantForMemories(EventId)
                            )
                        {
                            eventType = C_EVENTTYPE_RESET;
                        }
                        Dem_EvtSetStorageFiltered (EventId, FALSE);
                    }
                    Dem_Dependencies_ResetComponentFailed (ComponentId);
            }
        }

    }

    DEM_EXITLOCK_MON();


    /*********************************************************
    * storage to event memory */

    if (Dem_ComponentIsAvailable (ComponentId))
    {
        /* MR12 RULE 13.5 VIOLATION: to improve software quality and mantainability, the bit-manipulation operations
         * of element-attributes are encapsulated in getter/setter functions. Qac is incapable of recognizing, that
         * a getter function just retrieves information and does not manipulate any data. therefore it produces
         * lots of false warnings.*/
        if ((eventType != C_EVENTTYPE_NOEVENT) && (Dem_IsEventStorageEnabledByDtcSetting (EventId)))
        {
            if (!Dem_EvBuffInsert (eventType, EventId,monitorData0,monitorData1))
            {
                DEM_ENTERLOCK_MON();
                Dem_EvtSetCausal (EventId, FALSE);
                if (eventType == C_EVENTTYPE_RESET)
                {
                    Dem_EvtSetPassedWasReported (EventId, TRUE);
                }
                DEM_EXITLOCK_MON();
            }
        }
    }
}


#if(DEM_CFG_SUSPICIOUS_SUPPORT)
void Dem_SetEventSuspicion_Internal (Dem_EventIdType EventId, boolean suspicion)
{
    Dem_ComponentIdType ComponentId = Dem_ComponentIdFromEventId(EventId);

    DEM_ASSERT_ISLOCKED();

    /* do not set suspicion if the event is suppressed*/
    if(Dem_EvtIsSuppressed(EventId))
    {
        return;
    }

    /* do not set supicion, if the event is already set as failed (optimization); suspicious is not required when testfailed is already set */
    if (suspicion && Dem_EvtSt_GetTestFailed(EventId))
    {
        return;
    }
    if((Dem_EvtIsSuspicious(EventId)) == suspicion)
    {
        return;
    }

    Dem_EvtSetSuspicionLevel(EventId,suspicion);

    if (Dem_ComponentIdIsValid(ComponentId) && Dem_ComponentIsAvailable (ComponentId))
    {
        Dem_ComponentSetSuspicious(ComponentId, suspicion);
    }

}

void Dem_SetEventSuspicion (Dem_EventIdType EventId, boolean suspicion)
{
	DEM_ENTERLOCK_MON();
	Dem_SetEventSuspicion_Internal(EventId, suspicion);
    DEM_EXITLOCK_MON();
}
#endif

/* MR12 RULE 8.13 VIOLATION: the parameters might be unused due to the configuration */
Std_ReturnType Dem_GetEventSuspicious(Dem_EventIdType EventId, boolean* EventSuspicious)
{
#if(DEM_CFG_SUSPICIOUS_SUPPORT)
    if(Dem_EvtIsSuppressed(EventId))
    {
        return E_NOT_OK;
    }

    *EventSuspicious = (boolean)Dem_EvtIsSuspicious(EventId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(EventId);
    DEM_UNUSED_PARAM(EventSuspicious);
    return E_NOT_OK;
#endif
}

#if((DEM_CFG_SUPPRESSION == DEM_EVENT_SUPPRESSION) || (DEM_CFG_SUPPRESSION == DEM_EVENT_AND_DTC_SUPPRESSION))
Std_ReturnType Dem_SetEventAvailable(Dem_EventIdType EventId, boolean AvailableStatus)
{
    Std_ReturnType retval;
	retval = Dem_SetEventSuppression(EventId, !AvailableStatus);
    return retval;
}
#endif


Std_ReturnType Dem_GetEventAvailable(Dem_EventIdType EventId, boolean* AvailableStatus)
{
    if(AvailableStatus == NULL_PTR)
    {
        return E_NOT_OK;
    }
    if(!Dem_isEventIdValid(EventId))
    {
        return E_NOT_OK;
    }

    *AvailableStatus = (boolean)Dem_EvtIsSuppressed(EventId);
    return E_OK;
}

Std_ReturnType Dem_SetEventSuppression(Dem_EventIdType EventId, boolean SuppressionStatus)
{
    Std_ReturnType returnVal;
    Dem_UdsStatusByteType evtStatus;

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    Dem_ComponentIdType ComponentId;
#endif

	DEM_ENTRY_CONDITION_CHECK_PREINIT_EVTIDVALID(EventId,DEM_DET_APIID_DEM_SETEVENTAVAILABLE,E_NOT_OK);

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)

    ComponentId = Dem_ComponentIdFromEventId(EventId);

    if((!SuppressionStatus) && (!Dem_ComponentIsAvailable(ComponentId)))
    {
        return E_NOT_OK;
    }
#endif

	DEM_ENTERLOCK_MON();

	evtStatus = Dem_EvtGetIsoByte(EventId);

    if(    Dem_ISO14229ByteIsTestFailed(evtStatus)
        || Dem_ISO14229ByteIsPendingDTC(evtStatus)
        || Dem_ISO14229ByteIsConfirmedDTC(evtStatus)
        || Dem_ISO14229ByteIsWarningIndicatorRequested(evtStatus))
	{
	    returnVal =  E_NOT_OK;
	}
	else
	{
#if((DEM_CFG_SUPPRESSION == DEM_EVENT_SUPPRESSION) || (DEM_CFG_SUPPRESSION == DEM_EVENT_AND_DTC_SUPPRESSION))
	    Dem_EvtSetSuppression(EventId, SuppressionStatus);
#else
	    DEM_UNUSED_PARAM(SuppressionStatus);
#endif
	    returnVal = E_OK;
	}

	DEM_EXITLOCK_MON();

	return returnVal;
}

Std_ReturnType Dem_SetEventSuppressionByDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, boolean SuppressionStatus)
{
#if((DEM_CFG_SUPPRESSION == DEM_EVENT_SUPPRESSION) || (DEM_CFG_SUPPRESSION == DEM_EVENT_AND_DTC_SUPPRESSION))

    Dem_EventIdListIterator eventIt;
    Dem_EventIdType eventId;
    Std_ReturnType retval;
    Dem_DtcIdType dtcId;

    if (DTCFormat == DEM_DTC_FORMAT_UDS)
    {
        dtcId = Dem_DtcIdFromDtcCode(DTC);
    }
    else /* DEM_DTC_FORMAT_OBD */
    {
        /* not implemented, DEM specification not clear eg: regarding handling of readiness */
        return E_NOT_OK;
    }

    if (!Dem_isDtcIdValid(dtcId))
    {
        return E_NOT_OK;
    }

    retval = E_OK;
    for (Dem_EventIdListIteratorNewFromDtcId(&eventIt, dtcId);
            Dem_EventIdListIteratorIsValid(&eventIt);
            Dem_EventIdListIteratorNext(&eventIt))
    {
        eventId = Dem_EventIdListIteratorCurrent(&eventIt);

        if (Dem_SetEventSuppression(eventId, SuppressionStatus) == E_NOT_OK)
        {
            retval = E_NOT_OK;
        }
    }

    return retval;

#else
    DEM_UNUSED_PARAM(DTC);
    DEM_UNUSED_PARAM(DTCFormat);
    DEM_UNUSED_PARAM(SuppressionStatus);
    return E_NOT_OK;
#endif
}

/* HIS METRIC STMT VIOLATION IN Dem_AllowHistoryStatus: None of the function calls and the switch cases can be avoided or merged */
void Dem_AllowHistoryStatus(void)
{
#if(DEM_CFG_ALLOW_HISTORY == DEM_CFG_ALLOW_HISTORY_ON)
	Dem_HistoryStatusAllowed = TRUE;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter historyStatus not made const, as it is modified by Dem_EvtGetHistoryStatus() subfunction */
Std_ReturnType Dem_GetHistoryStatus ( Dem_EventIdType EventId, boolean* historyStatus)
{
#if(DEM_CFG_ALLOW_HISTORY == DEM_CFG_ALLOW_HISTORY_ON)
	 if(Dem_EvtIsSuppressed(EventId))
	 {
	  return E_NOT_OK;
	 }

	if(historyStatus != NULL_PTR)
	{
		*historyStatus = (boolean)Dem_EvtGetHistoryStatus(EventId);
		return E_OK;
	}
	else
	{
		DEM_DET(DEM_DET_APIID_GETHISTORYSTATUS, DEM_E_PARAM_POINTER,EventId);
		return E_NOT_OK;
	}
#else
	DEM_UNUSED_PARAM(EventId);
	DEM_UNUSED_PARAM(historyStatus);

	return E_NOT_OK;
#endif
}

/* Enabled if Test Mode reporting is enabled */
#if (DEM_CFG_TESTMODE_SUPPORT == DEM_CFG_TESTMODE_SUPPORT_ON)

/*  API for Test Mode reporting and setting Event status by application */
Std_ReturnType  Dem_SetEventStatus_TestMode (Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    Dem_EncodeTestModeEventId(&EventId);
    return (Dem_SetEventStatusWithMonitorData(EventId, EventStatus, 0, 0));
}

/* API for Test Mode reporting and setting Event status by application */
Std_ReturnType Dem_SetEventStatusWithMonitorData_TestMode (Dem_EventIdType EventId, Dem_EventStatusType EventStatus, Dem_MonitorDataType monitorData0, Dem_MonitorDataType monitorData1)
{
    Dem_EncodeTestModeEventId(&EventId);
    return (Dem_SetEventStatusWithMonitorData(EventId, EventStatus, monitorData0, monitorData1));
}

/* API which allows activate or deactivate Test Mode Reporting */
void Dem_EnableTestMode (boolean TestModeStatus)
{
    Dem_TestModeActive = TestModeStatus;
}
#endif


#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
