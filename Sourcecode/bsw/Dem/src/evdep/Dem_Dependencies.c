
#include "Dem_Internal.h"
#include "Rte_Dem.h"
#include "Dem_Dependencies.h"

#include "Dem_Events.h"
#include "Dem_EventStatus.h"
#include "Dem_Mapping.h"
#include "Dem_Cfg_ExtPrototypes.h"

#include "Dem_Obd.h"

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

DEM_ARRAY_DEFINE(Dem_ComponentState, Dem_AllComponentsState, DEM_COMPONENTID_ARRAYLENGTH);

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"



#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"

/* MR12 RULE 1.3, 20.7 VIOLATION:
 * 1.3 : A function-like macro shall not be invoked without all of its arguments, hence some of the arguments are optional based on configuration.
 * 20.7: The MACRO is expanded into several commans/lines, this cannot be encapsulated with braces.
*/
DEM_ARRAY_DEFINE_CONST(Dem_ComponentParam, Dem_AllComponentsParam, DEM_COMPONENTID_ARRAYLENGTH, DEM_CFG_COMPONENTPARAMS);
#if (DEM_CFG_COMPONENTFAILEDCALLBACK_COUNT > 0)
/* MR12 RULE 20.7 VIOLATION: The MACRO is expanded into several commans/lines, this cannot be encapsulated with braces. */
DEM_ARRAY_DEFINE_CONST(Dem_ComponentFailedCallbackType, Dem_ComponentFailedCallbacks, DEM_CFG_COMPONENTFAILEDCALLBACK_ARRAYLENGTH, DEM_CFG_COMPONENTFAILEDCALLBACKS);
#endif

#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"



#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

void Dem_SetComponentStatus (const Dem_ComponentIdType ComponentId, uint8 statusIndex)
{
    Dem_ComponentIdListIterator childIt;
    Dem_ComponentIdType CurrentComponentId;

    DEM_ASSERT_ISLOCKED();
	if (!Dem_ComponentStatusIsSet(Dem_AllComponentsState[ComponentId].status[statusIndex]))
	{
		Dem_ComponentStatusSet(&(Dem_AllComponentsState[ComponentId].status[statusIndex]));
#if (DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
        if ( Dem_Is_Fim_Initialized()
                && ((statusIndex==DEM_COMPONENTSTATUS_FAILED)&&(!Dem_ComponentStatusIsAnyAncestorSet(Dem_AllComponentsState[ComponentId].status[statusIndex]))))
        {
            FiM_DemTriggerOnComponentStatus(ComponentId, TRUE);
        }
#endif

		for (Dem_ComponentIdListIteratorNewFromComponentId (&childIt, ComponentId);
				Dem_ComponentIdListIteratorIsValid (&childIt);
				Dem_ComponentIdListIteratorNext (&childIt))
		{
		    CurrentComponentId = Dem_ComponentIdListIteratorCurrent(&childIt);

			Dem_AllComponentsState[CurrentComponentId].status[statusIndex]++;
#if (DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
            if (  Dem_Is_Fim_Initialized() &&
                    ((statusIndex==DEM_COMPONENTSTATUS_FAILED)&&(Dem_AllComponentsState[CurrentComponentId].status[statusIndex] == 1)))
            {
                FiM_DemTriggerOnComponentStatus(CurrentComponentId, TRUE);
            }
#endif
		}
	}
}

static void Dem_ResetComponentStatus (const Dem_ComponentIdType ComponentId, uint8 statusIndex)
{
    Dem_ComponentIdListIterator childIt;
    Dem_ComponentIdType CurrentComponentId;

    DEM_ASSERT_ISLOCKED();
	if (Dem_ComponentStatusIsSet(Dem_AllComponentsState[ComponentId].status[statusIndex]))
	{
		Dem_ComponentStatusReset(&(Dem_AllComponentsState[ComponentId].status[statusIndex]));
#if (DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
        if (  Dem_Is_Fim_Initialized() &&
                ((statusIndex==DEM_COMPONENTSTATUS_FAILED)&&(!Dem_ComponentStatusIsAnyAncestorSet(Dem_AllComponentsState[ComponentId].status[statusIndex]))))
        {
            FiM_DemTriggerOnComponentStatus(ComponentId, FALSE);
        }
#endif

		for (Dem_ComponentIdListIteratorNewFromComponentId (&childIt, ComponentId);
				Dem_ComponentIdListIteratorIsValid (&childIt);
				Dem_ComponentIdListIteratorNext (&childIt))
		{
		    CurrentComponentId = Dem_ComponentIdListIteratorCurrent(&childIt);

			Dem_AllComponentsState[CurrentComponentId].status[statusIndex]--;
#if (DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
            if (  Dem_Is_Fim_Initialized() &&
                    ((statusIndex==DEM_COMPONENTSTATUS_FAILED)&&(Dem_AllComponentsState[CurrentComponentId].status[statusIndex] == 0)))
            {
                FiM_DemTriggerOnComponentStatus(CurrentComponentId, FALSE);
            }
#endif
		}
	}
}

/* MR12 RULE 13.5, 20.7 VIOLATION:
 * 13.5: Boolean returning function is identified as an expression causing side effect. This warning can be ignored.
 * 20.7: Macro parameter FUNCTIONNAME may not be enclosed in (), because the MACRO is expanded into several commans/lines.
*/
#define DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE(EVTIT, COMPONENTID, FUNCTIONNAME, STATEVAR)             \
do {                                                                        \
	(STATEVAR) = FALSE;                                                     \
	for (Dem_EventIdListIterator2NewFromComponentId(&(EVTIT), COMPONENTID);             \
			Dem_EventIdListIterator2IsValid(&(EVTIT));                        \
			Dem_EventIdListIterator2Next(&(EVTIT)))                           \
	{                                                                       \
		(STATEVAR) = (STATEVAR) || FUNCTIONNAME(Dem_EventIdListIterator2Current(&(EVTIT)));   \
	}                                                                       \
} while (FALSE)




typedef Dem_boolean_least (*DemEvtStatusFuncptr)(Dem_EventIdType EventId);

DEM_INLINE Dem_boolean_least Dem_Dependencies_CheckEventIsCausalGeneric(Dem_EventIdType EventId, Dem_ComponentIdType ComponentId, uint8 StatusIndex, DemEvtStatusFuncptr FuncPointer)
{
    Dem_EventIdListIterator2 evtIt;

    DEM_ASSERT_ISLOCKED();

    if (!Dem_ComponentIdIsValid(ComponentId))
    {
        return TRUE;
    }

    /* DSM_D_37: failure sequential, if one ancestor is invalid */
    if ( Dem_ComponentStatusIsAnyAncestorSet(Dem_AllComponentsState[ComponentId].status[StatusIndex]) )
    {
        return FALSE;
    }
    else
    {
        if (Dem_ComponentIgnorePriority(ComponentId))
        {
            return TRUE;
        }
        else
        {
            Dem_EventIdListIterator2NewFromComponentId (&evtIt, ComponentId);

            /* DSM_D_37: failure sequential, if monitoring with higher */
            /* prio at component has reported failure */
            while (Dem_EventIdListIterator2IsValid(&evtIt))
            {
                /* only check events with higher prio at component; not event itself nor lower prio events, therefore cancel loop */
                if (Dem_EventIdListIterator2Current(&evtIt) == EventId)
                {
                    return TRUE;
                }

                if (FuncPointer(Dem_EventIdListIterator2Current(&evtIt)))
                {
                    return FALSE;
                }

                Dem_EventIdListIterator2Next (&evtIt);
            }
        }
    }

    /* should never be reached */
    DEM_ASSERT(Dem_LibGetParamBool(FALSE), DEM_DET_APIID_EVENTDEPENDENCIES_ISCAUSAL, 0);
    return TRUE;
}

Dem_boolean_least Dem_Dependencies_CheckEventIsCausal(Dem_EventIdType EventId, Dem_ComponentIdType ComponentId)
{
    return Dem_Dependencies_CheckEventIsCausalGeneric(EventId, ComponentId, DEM_COMPONENTSTATUS_FAILED, &Dem_MonitorStatusByteIsTestFailed);
}

#if DEM_CFG_DEPENDENCY_PENDING_ON
/*To check the event is not having any stored pending OBD event(s) which is of higher prio to it in the graph .TRUE - no high prio pending OBD events*/
Dem_boolean_least Dem_Dependencies_CheckEventIsCausalPending(Dem_EventIdType EventId, Dem_ComponentIdType ComponentId)
{
    return Dem_Dependencies_CheckEventIsCausalGeneric(EventId, ComponentId, DEM_COMPONENTSTATUS_PENDING, &Dem_EvtSt_GetPending);
}

static void Dem_ComponentSetPending(Dem_ComponentIdType ComponentId, Dem_boolean_least IsPending)
{
    Dem_boolean_least anyEvtStoredPending;
    Dem_EventIdListIterator2 evtIt;

    DEM_ASSERT_ISLOCKED();

    if(IsPending)
    {
        Dem_SetComponentStatus (ComponentId, DEM_COMPONENTSTATUS_PENDING);
    }
    else
    {
        /* MR12 RULE 20.7 VIOLATION: Due to the fact that array content and array size are both generated based on the same input it is ensured that the data always fit in to the array */
        DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE (evtIt, ComponentId, Dem_EvtSt_GetPending, anyEvtStoredPending);

        if(!anyEvtStoredPending)
        {
            Dem_ResetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_PENDING);
        }

    }
}

void Dem_Dependencies_SetComponentPending(Dem_EventIdType EventId , Dem_boolean_least setBit)
{

    Dem_ComponentIdType ComponentId;

    ComponentId = Dem_ComponentIdFromEventId(EventId);

    if (!Dem_ComponentIdIsValid(ComponentId))
    {
        return;
    }

    /* to Set/reset Component Status Pending */
    Dem_ComponentSetPending( ComponentId ,setBit);
}
#endif

void Dem_Dependencies_SetComponentFailed(Dem_ComponentIdType ComponentId, boolean EventIsCausal, boolean EventStorageFiltered, boolean EventIsRecoverable)
{
    DEM_ASSERT_ISLOCKED();

    DEM_ASSERT(!(EventIsCausal && EventStorageFiltered), DEM_DET_APIID_EVENTDEPENDENCIES, 0);

    if (!Dem_ComponentIdIsValid(ComponentId))
    {
        return;
    }

    /* calculate statemachine */
    if (Dem_ComponentIsFailedItself(ComponentId))
    {
        if (Dem_ComponentIsFailedFilteredItself(ComponentId))
        {
            /* state FailedFiltered */
            if (EventIsCausal && !(EventStorageFiltered))
            {
                Dem_ResetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDFILTERED);
                if (!EventIsRecoverable)
                {
                    Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE);
                }
            }
        } else
        {
            /* state Failed */
            if (EventIsCausal && !EventIsRecoverable)
            {
                Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE);
            }
            else if (EventStorageFiltered)
            {
                Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDFILTERED);
            }
            else
            {
                /* Do nothing */
            }
        }
    } else
    {
        /* state Valid */
        Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILED);
        if (EventIsCausal && !EventIsRecoverable)
        {
            Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE);
        } else
        {
            if (EventStorageFiltered)
            {
                Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDFILTERED);
            }
        }
        /*  add to diagram */
        Dem_ComponentCallFailedCallback(ComponentId, TRUE);
    }
}


void Dem_Dependencies_ResetComponentFailed(Dem_ComponentIdType ComponentId)
{
    Dem_boolean_least anyMonFailed;
    Dem_EventIdListIterator2 evtIt;

    if (!Dem_ComponentIdIsValid(ComponentId))
    {
        return;
    }

    DEM_ASSERT_ISLOCKED();

    /* MR12 RULE 20.7 VIOLATION: Macro parameter FUNCTIONNAME in DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE may not be enclosed in ().*/
    DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE (evtIt, ComponentId, Dem_MonitorStatusByteIsTestFailed, anyMonFailed);

    if (!anyMonFailed)
    {
        Dem_ResetComponentStatus(ComponentId,DEM_COMPONENTSTATUS_FAILED);
        Dem_ResetComponentStatus(ComponentId,DEM_COMPONENTSTATUS_FAILEDFILTERED);
        Dem_ResetComponentStatus(ComponentId,DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE);
        Dem_ComponentCallFailedCallback(ComponentId, FALSE);
    }
}


void Dem_Dependencies_SetComponentFailedFiltered(Dem_ComponentIdType ComponentId)
{
    if (!Dem_ComponentIdIsValid(ComponentId))
    {
        return;
    }

    DEM_ASSERT_ISLOCKED();
    Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDFILTERED);
}

void Dem_Dependencies_ResetComponentFailedFiltered(Dem_ComponentIdType ComponentId)
{
    DEM_ASSERT_ISLOCKED();
    Dem_ResetComponentStatus(ComponentId,DEM_COMPONENTSTATUS_FAILEDFILTERED);
}


void Dem_Dependencies_ResetComponentFailedNotRecoverable(Dem_ComponentIdType ComponentId)
{
    Dem_boolean_least anyMonNotRecoverable;
    Dem_EventIdListIterator2 evtIt;

    if (!Dem_ComponentIdIsValid(ComponentId))
    {
        return;
    }

    DEM_ASSERT_ISLOCKED();

    /* MR12 RULE 13.5, 20.7 VIOLATION:
     * 13.5: Boolean returning function is identified as an expression causing side effect. This warning can be ignored.
     * 20.7: Macro parameter FUNCTIONNAME in DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE may not be enclosed in (), because the MACRO is expanded into several commans/lines.
    */
    DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE (evtIt, ComponentId, Dem_EvtIsNotRecoverableTOC, anyMonNotRecoverable);

    if (!anyMonNotRecoverable)
    {
        Dem_ResetComponentStatus(ComponentId,DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE);

        if (Dem_ComponentIsResetPerformedRecoveriesValueAllowed(ComponentId))
        {
            Dem_ComponentResetPerformedRecoveries(ComponentId);
        }
    }
}

void Dem_Dependencies_SetComponentFailedNotRecoverable(Dem_ComponentIdType ComponentId)
{
    if (!Dem_ComponentIdIsValid(ComponentId))
    {
        return;
    }

    DEM_ASSERT_ISLOCKED();
    Dem_SetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE);
}

void Dem_ComponentSetSuspicious(Dem_ComponentIdType ComponentId, Dem_boolean_least suspicious)
{
	Dem_boolean_least anyMonSuspicious;
	Dem_EventIdListIterator2 evtIt;

	DEM_ASSERT_ISLOCKED();

	if (suspicious)
	{
		Dem_SetComponentStatus (ComponentId, DEM_COMPONENTSTATUS_SUSPICIOUS);
	}
	else
	{
		/* check if any event is testfailed at component */
	    /* MR12 RULE 20.7 VIOLATION: Macro parameter FUNCTIONNAME in DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE may not be enclosed in (), because the MACRO is expanded into several commans/lines.*/
	    DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE (evtIt, ComponentId, Dem_EvtIsSuspicious, anyMonSuspicious);

		if (!anyMonSuspicious)
		{
			Dem_ResetComponentStatus(ComponentId,DEM_COMPONENTSTATUS_SUSPICIOUS);
		}
	}
}



void Dem_ComponentSetHasCausalFault (const Dem_ComponentIdType ComponentId, Dem_boolean_least causalFault)
{
	Dem_EventIdListIterator2 evtIt;
	Dem_boolean_least hasCausalFault;


	DEM_ASSERT_ISLOCKED();

	if (causalFault)
	{
	    rba_DiagLib_Bit8OverwriteBit(&(Dem_AllComponentsState[ComponentId].stateFlags), DEM_COMPONENT_STATEFLAG_HASCAUSALFAULT, TRUE);
	}
	else
	{
	    /* MR12 RULE 20.7 VIOLATION: Macro parameter FUNCTIONNAME in DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE may not be enclosed in (), because the MACRO is expanded into several commans/lines.*/
		DEM_COMPONENT_CHECK_EVENTS_ATTRIBUTE (evtIt, ComponentId, Dem_EvtIsCausal, hasCausalFault);
		rba_DiagLib_Bit8OverwriteBit(&(Dem_AllComponentsState[ComponentId].stateFlags), DEM_COMPONENT_STATEFLAG_HASCAUSALFAULT, hasCausalFault);
	}
}


void Dem_ComponentSetAvailable (Dem_ComponentIdType ComponentId, boolean AvailableStatus)
{
	DEM_ENTERLOCK_MON();

	if (!AvailableStatus)
	{
		Dem_SetComponentStatus (ComponentId, DEM_COMPONENTSTATUS_NOTAVAILABLE);
	}
	else
	{
		Dem_ResetComponentStatus(ComponentId, DEM_COMPONENTSTATUS_NOTAVAILABLE);
	}

	DEM_EXITLOCK_MON();
}


void Dem_ComponentRecheckOnClear (void)
{
	Dem_ComponentIdIterator componentIt;
	for (Dem_ComponentIdIteratorNew(&componentIt); Dem_ComponentIdIteratorIsValid(&componentIt); Dem_ComponentIdIteratorNext(&componentIt))
	{
		if (Dem_ComponentIsRecheckOnClear(Dem_ComponentIdIteratorCurrent(&componentIt)))
		{
		    DEM_ENTERLOCK_MON();
		    Dem_ComponentSetRecheckOnClear (Dem_ComponentIdIteratorCurrent(&componentIt), FALSE);
			Dem_Dependencies_ResetComponentFailed(Dem_ComponentIdIteratorCurrent(&componentIt));
			Dem_ComponentSetHasCausalFault(Dem_ComponentIdIteratorCurrent(&componentIt), FALSE);
            DEM_EXITLOCK_MON();
		}
	}
}

DEM_INLINE void Dem_SetEventAvailableFromComponent(Dem_ComponentIdType ComponentId, boolean AvailableStatus)
{
#if((DEM_CFG_SUPPRESSION == DEM_EVENT_SUPPRESSION) || (DEM_CFG_SUPPRESSION == DEM_EVENT_AND_DTC_SUPPRESSION))
    Dem_ComponentIdListIterator childIt;
    Dem_EventIdListIterator2 evtIt;
    Dem_EventIdType eventId;

    for (Dem_EventIdListIterator2NewFromComponentId(&evtIt, ComponentId); Dem_EventIdListIterator2IsValid(&evtIt);
            Dem_EventIdListIterator2Next(&evtIt))
    {
        eventId = Dem_EventIdListIterator2Current(&evtIt);
        if (AvailableStatus == Dem_EvtIsSuppressed(eventId))
        {
            (void)Dem_SetEventAvailable(eventId, AvailableStatus);
        }
    }

    for (Dem_ComponentIdListIteratorNewFromComponentId(&childIt, ComponentId); Dem_ComponentIdListIteratorIsValid(&childIt);
            Dem_ComponentIdListIteratorNext(&childIt))
    {
        for (Dem_EventIdListIterator2NewFromComponentId(&evtIt, Dem_ComponentIdListIteratorCurrent(&childIt));
                Dem_EventIdListIterator2IsValid(&evtIt);
                Dem_EventIdListIterator2Next(&evtIt))
        {
            eventId = Dem_EventIdListIterator2Current(&evtIt);
            if (AvailableStatus == Dem_EvtIsSuppressed(eventId))
            {
                (void)Dem_SetEventAvailable(eventId, AvailableStatus);
            }
        }
    }
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(AvailableStatus);
#endif

}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

Std_ReturnType Dem_SetComponentAvailable(Dem_ComponentIdType ComponentId, boolean AvailableStatus)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    /*  Entry Condition Check */
    DEM_ENTRY_CONDITION_CHECK_DEM_PREINITIALIZED(DEM_DET_APIID_DEM_SETCOMPONENTAVAILABLE,E_NOT_OK);
    DEM_ENTRY_CONDITION_CHECK_COMPONENT_ID_VALID(ComponentId , DEM_DET_APIID_DEM_SETCOMPONENTAVAILABLE , E_NOT_OK);

    Dem_ComponentSetAvailable(ComponentId, AvailableStatus);
    Dem_SetEventAvailableFromComponent(ComponentId, AvailableStatus);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(AvailableStatus);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentSuspicious (Dem_ComponentIdType ComponentId, boolean* ComponentSuspicious)
{
#if ((DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON) && (DEM_CFG_SUSPICIOUS_SUPPORT))
    if ((!Dem_ComponentIdIsValid(ComponentId)) && (!Dem_ComponentIsAvailable (ComponentId)))
    {
        return E_NOT_OK;
    }

    *ComponentSuspicious = Dem_ComponentIsSuspicious(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentSuspicious);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentUsable (Dem_ComponentIdType ComponentId, boolean* ComponentUsable)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    if(!Dem_ComponentIdIsValid(ComponentId))
    {
        return E_NOT_OK;
    }

    *ComponentUsable = Dem_ComponentIsUsable(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentUsable);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentRestrictedUsable (Dem_ComponentIdType ComponentId, boolean* ComponentRestrictedUsable)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    if(!Dem_ComponentIdIsValid(ComponentId))
    {
        return E_NOT_OK;
    }

   *ComponentRestrictedUsable = Dem_ComponentIsRestrictedUsable(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentRestrictedUsable);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentInitialized (Dem_ComponentIdType ComponentId, boolean* ComponentInitialized)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    if(!Dem_ComponentIdIsValid(ComponentId))
    {
        return E_NOT_OK;
    }

    *ComponentInitialized = Dem_ComponentIsInitialized(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentInitialized);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentFailed (Dem_ComponentIdType ComponentId, boolean* ComponentFailed)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)

    /*  Entry Condition Check    */
    DEM_ENTRY_CONDITION_CHECK_DEM_INITIALIZED_OR_FIM_IS_IN_INIT(DEM_DET_APIID_DEM_GETCOMPONENTFAILED, E_NOT_OK );
    DEM_ENTRY_CONDITION_CHECK_NOT_NULL_PTR(ComponentFailed,DEM_DET_APIID_DEM_GETCOMPONENTFAILED,E_NOT_OK );
    DEM_ENTRY_CONDITION_CHECK_COMPONENT_ID_VALID(ComponentId , DEM_DET_APIID_DEM_SETCOMPONENTAVAILABLE , E_NOT_OK);

    *ComponentFailed = Dem_ComponentIsFailed(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentFailed);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentFailedItself(Dem_ComponentIdType ComponentId, boolean* ComponentFailedItself)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    if(!Dem_ComponentIdIsValid(ComponentId))
    {
        return E_NOT_OK;
    }

   *ComponentFailedItself = Dem_ComponentIsFailedItself(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentFailedItself);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentSuspiciousItself(Dem_ComponentIdType ComponentId, boolean* ComponentSuspiciousItself)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    if(!Dem_ComponentIdIsValid(ComponentId))
    {
        return E_NOT_OK;
    }

   *ComponentSuspiciousItself = Dem_ComponentIsSuspiciousItself(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentSuspiciousItself);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentAvailable(Dem_ComponentIdType ComponentId, boolean* ComponentAvailable)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    if(!Dem_ComponentIdIsValid(ComponentId))
    {
        return E_NOT_OK;
    }

   *ComponentAvailable = Dem_ComponentIsAvailable(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentAvailable);
    return E_NOT_OK;
#endif
}

/* MR12 RULE 8.13 VIOLATION: parameter not made const, as it is depending on compiler switch setting */
Std_ReturnType Dem_GetComponentAreAncestorsInitialized(Dem_ComponentIdType ComponentId, boolean* ComponentAreAncestorsInitialized)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    if(!Dem_ComponentIdIsValid(ComponentId))
    {
        return E_NOT_OK;
    }
   *ComponentAreAncestorsInitialized = Dem_ComponentAreAncestorsInitialized(ComponentId);
    return E_OK;
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(ComponentAreAncestorsInitialized);
    return E_NOT_OK;
#endif
}


void Dem_SetComponentInitialized(Dem_ComponentIdType ComponentId, boolean init)
{
#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
    DEM_ENTERLOCK_MON();

    if (!init)
    {
        Dem_SetComponentStatus (ComponentId, DEM_COMPONENTSTATUS_NOTINIT);
    }
    else
    {
        Dem_ResetComponentStatus(ComponentId,DEM_COMPONENTSTATUS_NOTINIT);
    }

    DEM_EXITLOCK_MON();
#else
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(init);
#endif
}



/*************************************************************************************
 * simple querry functions, which are also provided publically
 */

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)

boolean Dem_GetComponentAreAncestorsFailed(Dem_ComponentIdType ComponentId)
{
    return Dem_ComponentStatusIsAnyAncestorSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILED]);
}

boolean Dem_GetComponentAreAncestorsSuspicious(Dem_ComponentIdType ComponentId)
{
    return Dem_ComponentStatusIsAnyAncestorSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_SUSPICIOUS]);
}

boolean Dem_GetComponentAreAncestorsAvailable(Dem_ComponentIdType ComponentId)
{
    return !Dem_ComponentStatusIsAnyAncestorSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_NOTAVAILABLE]);
}

boolean Dem_GetComponentAreAncestorsRestrictedUsable(Dem_ComponentIdType ComponentId)
{
    return (   (Dem_ComponentAreAncestorsInitialized(ComponentId))
            && (Dem_GetComponentAreAncestorsAvailable(ComponentId))
            && (!Dem_GetComponentAreAncestorsFailed(ComponentId))
            );
}

boolean Dem_GetComponentAreAncestorsUsable(Dem_ComponentIdType ComponentId)
{
    return (   (Dem_GetComponentAreAncestorsRestrictedUsable(ComponentId))
            && (!Dem_GetComponentAreAncestorsSuspicious(ComponentId))
            );
}

boolean Dem_GetComponentHasCausalFault (Dem_ComponentIdType ComponentId)
{
    return rba_DiagLib_Bit8IsBitSet(Dem_AllComponentsState[ComponentId].stateFlags, DEM_COMPONENT_STATEFLAG_HASCAUSALFAULT);
}

boolean Dem_GetComponentAreAllFailedFiltered(Dem_ComponentIdType ComponentId)
{
    return (   (Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILEDFILTERED] != 0)
            && (   Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILEDFILTERED]
                == Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILED]
               )
            );
}

#else /* DEM_CFG_DEPENDENCY */

boolean Dem_GetComponentAreAllFailedFiltered(Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
    return FALSE;
}

#endif /* DEM_CFG_DEPENDENCY */



#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

