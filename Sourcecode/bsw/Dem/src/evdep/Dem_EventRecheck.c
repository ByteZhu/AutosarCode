
#include "Dem_EventRecheck.h"
#include "Dem_Types.h"
#include "Dem_Events.h"
#include "Dem_EventStatus.h"
#include "Dem_EvBuffEvent.h"
#include "Dem_EvBuff.h"
#include "Dem_Lock.h"
#include "Dem_Mapping.h"
#include "Dem_Dependencies.h"
#include "Dem_Helpers.h"
#include "Dem_Obd.h"
#include "Dem_Cfg_Events_DataStructures.h"

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)


#define DEM_START_SEC_VAR_INIT
#include "Dem_MemMap.h"

#define DEM_RECHECK_DECREASE_VALUE_FOR_RECHECKED_EVENT  5

static boolean Dem_RecheckComponentNotRecoverableRequested = FALSE;

#define DEM_STOP_SEC_VAR_INIT
#include "Dem_MemMap.h"




#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

void Dem_DependencyInit(void)
{
	Dem_EventIdListIterator2 evtIt;
	Dem_ComponentIdIterator componentIt;
	Dem_ComponentIdType currentComponent;
    Dem_boolean_least setFailed;

#if DEM_CFG_DEPENDENCY_PENDING_ON
    Dem_boolean_least setPending;
#endif

	/* set Failed state of all components according to failed state of events restored from NVM */
	for (Dem_ComponentIdIteratorNew(&componentIt); Dem_ComponentIdIteratorIsValid(&componentIt); Dem_ComponentIdIteratorNext(&componentIt))
	{
		currentComponent = Dem_ComponentIdIteratorCurrent(&componentIt);
		setFailed = FALSE;
#if DEM_CFG_DEPENDENCY_PENDING_ON
        setPending = FALSE;
#endif

		DEM_ENTERLOCK_MON();

		for (Dem_EventIdListIterator2NewFromComponentId (&evtIt, currentComponent);
				Dem_EventIdListIterator2IsValid(&evtIt);
				Dem_EventIdListIterator2Next (&evtIt))
		{
			if ( Dem_EvtSt_GetTestFailed(Dem_EventIdListIterator2Current(&evtIt)) && (!setFailed))
			{
			    Dem_SetComponentStatus (currentComponent, DEM_COMPONENTSTATUS_FAILED);
                setFailed = TRUE;
				/* explicitly requested to have the same behavior on startup and on failed-report according callback */
				Dem_ComponentCallFailedCallback(currentComponent, TRUE);
			}

#if DEM_CFG_DEPENDENCY_PENDING_ON
            if (Dem_EvtSt_GetPending(Dem_EventIdListIterator2Current(&evtIt)) && (!setPending))
            {
                (void)Dem_SetComponentStatus (currentComponent, DEM_COMPONENTSTATUS_PENDING);
                setPending = TRUE;
            }
#endif

            if( setFailed
#if DEM_CFG_DEPENDENCY_PENDING_ON
                    && setPending
#endif
            )
            {
                break; /* if at lest one event is failed (and pending), the Component is failed (and pending) and no further event of this
                            component needs to be checked */
            }
        }

		DEM_EXITLOCK_MON();
	}
}



/********************************************************************************************************
 * Recheck of the Component recoverable information
 */

void Dem_RecheckComponentNotRecoverableRequest(void)
{
    Dem_RecheckComponentNotRecoverableRequested = TRUE;
}

static void Dem_RecheckComponentNotRecoverable(void)
{
    /** perform a recheck of ComponentNotRecoverable information after a change of operationcycle,
     * as events may become recoverable due to the OpCycle change
     */

    Dem_ComponentIdIterator  componentIt;
    Dem_ComponentIdType component;

    if (Dem_RecheckComponentNotRecoverableRequested)
    {
        for (Dem_ComponentIdIteratorNew(&componentIt); Dem_ComponentIdIteratorIsValid(&componentIt); Dem_ComponentIdIteratorNext(&componentIt))
        {
            component = Dem_ComponentIdIteratorCurrent(&componentIt);
            if (Dem_ComponentIsFailedNotRecoverableItself(component))
            {
                DEM_ENTERLOCK_MON();
                Dem_Dependencies_ResetComponentFailedNotRecoverable(component);
                DEM_EXITLOCK_MON();
            }
        }

        Dem_RecheckComponentNotRecoverableRequested = FALSE;
    }
}



/********************************************************************************************************
 * Recheck of the event is causal information
 */

/* The restart of cyclic check (Dem_DependencyRestartCyclicCheck) is no longer required, as the function
 * Dem_Dependencies_CheckEventIsCausal always checks the status of the ancestors and all events with higher
 * priority at same Component. Therefore a reenabling of storage condition will properly be considered
 */


static void Dem_DependencyRecheckCausalityOfEvent (Dem_EventIdType EventId, Dem_ComponentIdType ComponentId)
{
    Dem_EvBuffEventType eventType = C_EVENTTYPE_SET_WAITINGFORMONITORING;
    Dem_boolean_least triggerEvBuffInsert = FALSE;
    Dem_boolean_least newIsCausal, areAllFulfilled;

    DEM_ENTERLOCK_MON();

    if (    Dem_EvtSt_GetTestFailed(EventId)
            && Dem_ComponentIsAvailable (ComponentId)
            && !Dem_EvtIsSuppressed(EventId)
       )
    {
        /* SEQUENTIAL and STORAGEISFILTERED */
        if (!Dem_EvtIsCausal(EventId))
        {
            newIsCausal = Dem_Dependencies_CheckEventIsCausal(EventId, ComponentId);
            areAllFulfilled = Dem_StoCoAreAllFulfilled(Dem_EvtParam_GetStorageConditionGroupIndex(EventId));


            /* STORAGEISFILTERED -> ISCAUSAL   and  SEQUENTIAL -> ISCAUSAL */
            if (newIsCausal)
            {
                if (areAllFulfilled)
                {
                    Dem_EvtSetCausal (EventId, TRUE);
                    Dem_EvtSetIsRecheckedAndWaitingForMonResult(EventId, TRUE);
                    Dem_EvtSetStorageFiltered (EventId, FALSE);

                    Dem_EvtSetInitMonitoring (EventId, DEM_INIT_MONITOR_STORAGE_REENABLED);

                    if(!(Dem_EvtParam_GetIsRecoverable(EventId) &&
                         Dem_ComponentRecoveryAllowed(ComponentId)))
                    {
                        Dem_Dependencies_SetComponentFailedNotRecoverable(ComponentId);
                    }

                    Dem_Dependencies_ResetComponentFailedFiltered(ComponentId);
                    triggerEvBuffInsert = TRUE;
                }
                else
                {
                    Dem_Dependencies_SetComponentFailedFiltered(ComponentId);
                    Dem_StoCoRecheckReplacementStorage(Dem_EvtParam_GetStorageConditionGroupIndex(EventId));
                }
            }

            /* SEQUENTIAL -> STORAGEISFILTERED */
            if (!Dem_EvtIsStorageFiltered(EventId) && newIsCausal && !areAllFulfilled)
            {
                Dem_Dependencies_SetComponentFailedFiltered(ComponentId);
                Dem_StoCoSetHasFilteredEvent(Dem_EvtParam_GetStorageConditionGroupIndex(EventId), (Dem_MonitorDataType)EventId,0);
            }
        }

        /* INVALID_STATE: Causal & StorageFiltered shall not occure, but must be rechecked! */
        if (   Dem_EvtIsCausal(EventId)
            && Dem_EvtIsStorageFiltered(EventId)
        )
        {
            if (Dem_StoCoAreAllFulfilled(Dem_EvtParam_GetStorageConditionGroupIndex(EventId)))
            {
                Dem_EvtSetStorageFiltered (EventId, FALSE);
            }
            else
            {
                Dem_EvtSetCausal (EventId, FALSE);
                Dem_StoCoSetHasFilteredEvent(Dem_EvtParam_GetStorageConditionGroupIndex(EventId),
                                            (Dem_MonitorDataType)EventId,0);
            }
        }
    }

    DEM_EXITLOCK_MON();

    if (triggerEvBuffInsert)
    {
        if (!Dem_EvBuffInsert (eventType, EventId,(Dem_MonitorDataType)0xffffffffu, (Dem_MonitorDataType)0xffffffffu))
        {
            DEM_ENTERLOCK_MON();
            Dem_EvtSetCausal (EventId, FALSE);
            Dem_EvtSetIsRecheckedAndWaitingForMonResult(EventId, FALSE);
            DEM_EXITLOCK_MON();
        }
   }
}


static void Dem_Dependency_RecheckCausalityMain (void)
{
    /* check all EventIds; whether they were not stored due to an evbuffer overflow */

    static Dem_EventIdIterator Dem_RecheckEventIterator = DEM_EVENTIDITERATORNEW;
    Dem_EventIdType eventId;
    sint16_least eventsCheckedCounter = (sint16_least)(DEM_MIN(DEM_CFG_FAILUREDEPENDENCY_RECHECK_LIMIT, DEM_EVENTID_COUNT)); // search configured number, but at maximum number of events

    while (eventsCheckedCounter > 0)
    {
        eventsCheckedCounter--;
        eventId = Dem_EventIdIteratorCurrent(&Dem_RecheckEventIterator);

        /* if event is failed and either filtered or not causal  then perform recheck */
        if (   Dem_EvtSt_GetTestFailed(eventId)
            && (   !Dem_EvtIsCausal(eventId)
                || Dem_EvtIsStorageFiltered(eventId)
               )
           )
        {
            /* recheck causality, insert into SFB and set GCT */
            Dem_DependencyRecheckCausalityOfEvent(eventId, Dem_ComponentIdFromEventId(eventId));

            /* the actual check is more time consuming so additionally dec the counter (load-balancing of mainfunction) */
            eventsCheckedCounter -= DEM_RECHECK_DECREASE_VALUE_FOR_RECHECKED_EVENT  ;
        }

        Dem_EventIdIteratorNext(&Dem_RecheckEventIterator);
        if (!Dem_EventIdIteratorIsValid(&Dem_RecheckEventIterator))
        {
            Dem_EventIdIteratorNew(&Dem_RecheckEventIterator);
        }
    }
}



void Dem_DependencyMainFunction(void)
{
    Dem_Dependency_RecheckCausalityMain ();
    Dem_RecheckComponentNotRecoverable();
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

