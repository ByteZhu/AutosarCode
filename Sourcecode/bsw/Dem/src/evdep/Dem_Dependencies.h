
#ifndef DEM_COMPONENTS_H
#define DEM_COMPONENTS_H


#include "Dem_Types.h"
#include "Dem_Cfg_Components.h"
#include "Dem_Cfg_ComponentId.h"
#include "Dem_Cfg_StorageCondition.h"
#include "Dem_Array.h"
#include "rba_DiagLib_Bits8.h"


#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)


#define DEM_COMPONENT_INFINITE_RECOVERIES  255
#define DEM_COMPONENT_NO_RECOVERIES          0

#define DEM_COMPONENTSTATUS_FAILED                   0
#define DEM_COMPONENTSTATUS_SUSPICIOUS               1
#define DEM_COMPONENTSTATUS_NOTINIT                  2
#define DEM_COMPONENTSTATUS_NOTAVAILABLE             3
#define DEM_COMPONENTSTATUS_FAILEDFILTERED           4
#define DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE     5
#define DEM_COMPONENTSTATUS_PENDING                  6

#if DEM_CFG_DEPENDENCY_PENDING_ON
#define DEM_COMPONENTSTATUS_COUNT                    7
#else
#define DEM_COMPONENTSTATUS_COUNT                    6
#endif

#define DEM_COMPONENTSTATUS__COMPONENTMASK               ((uint8)0x80)
#define DEM_COMPONENTSTATUS__ANCESTORMASK           ((uint8)0x7F)


DEM_INLINE void Dem_ComponentStatusSet(uint8 *status)            { (*status) |= DEM_COMPONENTSTATUS__COMPONENTMASK;  }
DEM_INLINE void Dem_ComponentStatusReset(uint8 *status)          { (*status) &= (uint8)~DEM_COMPONENTSTATUS__COMPONENTMASK; }
DEM_INLINE Dem_boolean_least Dem_ComponentStatusIsSet(uint8 status)  { return ((status) & DEM_COMPONENTSTATUS__COMPONENTMASK) > 0; }
DEM_INLINE Dem_boolean_least Dem_ComponentStatusIsAnyAncestorSet (uint8 status) { return ((status) & DEM_COMPONENTSTATUS__ANCESTORMASK) > 0; }


typedef struct
{
	uint8 status[DEM_COMPONENTSTATUS_COUNT];
#if (DEM_CFG_DEPRECOVERYLIMIT == DEM_CFG_DEPRECOVERYLIMIT_ON)
	uint8 performedRecoveries;
#endif
	uint8 stateFlags;
} Dem_ComponentState;

#define DEM_COMPONENT_STATEFLAG_RECHECKONCLEAR    0
#define DEM_COMPONENT_STATEFLAG_HASCAUSALFAULT    1
#define DEM_COMPONENT_STATEFLAG_RECOVERYBLOCKED    2


typedef struct
{
#if (DEM_CFG_DEPRECOVERYLIMIT == DEM_CFG_DEPRECOVERYLIMIT_ON)
	uint8 allowedRecoveries;
#endif
#if (DEM_CFG_COMPONENTFAILEDCALLBACK_COUNT > 0)
	uint8 componentFailedCallbackIdx;
#endif
	uint8 paramFlags;
} Dem_ComponentParam;

typedef Std_ReturnType (*Dem_ComponentFailedCallbackType)(boolean testFailed);


#define DEM_COMPONENT_PARAMFLAG_IGNOREPRIORITY    0
#define DEM_COMPONENT_PARAMFLAG_UPDATERECOVERY    1

#if (DEM_CFG_DEPRECOVERYLIMIT == DEM_CFG_DEPRECOVERYLIMIT_ON)
	#define DEM_COMPONENTS_INIT_ALLOWEDRECOVERIES(X)    (X),
#else
	#define DEM_COMPONENTS_INIT_ALLOWEDRECOVERIES(X)
#endif
#if (DEM_CFG_COMPONENTFAILEDCALLBACK_COUNT > 0)
	#define DEM_COMPONENTS_INIT_COMPONENTFAILEDCALLBACK(X)    (X),
#else
	#define DEM_COMPONENTS_INIT_COMPONENTFAILEDCALLBACK(X)
#endif

#define DEM_COMPONENTS_INIT_PARAMFLAGS(X,Y) (((uint8)(X)<<DEM_COMPONENT_PARAMFLAG_IGNOREPRIORITY)|((uint8)(Y)<<DEM_COMPONENT_PARAMFLAG_UPDATERECOVERY))

#define DEM_COMPONENTS_INIT(ALLOWEDRECOVERIES,UPDATERECOVERYVALUE,IGNORES_PRIO,COMPONENTFAILEDCALLBACK)        \
    {                                              			  \
		DEM_COMPONENTS_INIT_ALLOWEDRECOVERIES(ALLOWEDRECOVERIES)   \
		DEM_COMPONENTS_INIT_COMPONENTFAILEDCALLBACK(COMPONENTFAILEDCALLBACK)  \
		DEM_COMPONENTS_INIT_PARAMFLAGS(IGNORES_PRIO,UPDATERECOVERYVALUE)   \
    }



#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

DEM_ARRAY_DECLARE(      Dem_ComponentState, Dem_AllComponentsState, DEM_COMPONENTID_ARRAYLENGTH);

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"



#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"

DEM_ARRAY_DECLARE_CONST(Dem_ComponentParam, Dem_AllComponentsParam, DEM_COMPONENTID_ARRAYLENGTH);
DEM_ARRAY_DECLARE_CONST(Dem_ComponentFailedCallbackType, Dem_ComponentFailedCallbacks, DEM_CFG_COMPONENTFAILEDCALLBACK_ARRAYLENGTH);

#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"



#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

void Dem_SetComponentStatus (const Dem_ComponentIdType ComponentId, uint8 statusIndex);

Dem_boolean_least Dem_Dependencies_CheckEventIsCausal(Dem_EventIdType EventId, Dem_ComponentIdType ComponentId);

#if DEM_CFG_DEPENDENCY_PENDING_ON
Dem_boolean_least Dem_Dependencies_CheckEventIsCausalPending(Dem_EventIdType EventId, Dem_ComponentIdType ComponentId);
void Dem_Dependencies_SetComponentPending(Dem_EventIdType EventId , Dem_boolean_least setBit);
#endif


/*************   Status Querries   ***************/

DEM_INLINE boolean Dem_ComponentIsFailed(Dem_ComponentIdType ComponentId)
{
	return (Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILED] != 0);
}

DEM_INLINE boolean Dem_ComponentIsFailedItself(Dem_ComponentIdType ComponentId)
{
	return Dem_ComponentStatusIsSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILED]);
}


DEM_INLINE boolean Dem_ComponentIsSuspicious(Dem_ComponentIdType ComponentId)
{
   return (Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_SUSPICIOUS] != 0);
}

DEM_INLINE boolean Dem_ComponentIsSuspiciousItself(Dem_ComponentIdType ComponentId)
{
   return Dem_ComponentStatusIsSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_SUSPICIOUS]);
}


DEM_INLINE boolean Dem_ComponentIsFailedFilteredItself(Dem_ComponentIdType ComponentId)
{
   return (Dem_ComponentStatusIsSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILEDFILTERED]));
}


DEM_INLINE boolean Dem_ComponentIsFailedNotRecoverable(Dem_ComponentIdType ComponentId)
{
    return (Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE] != 0);
}

DEM_INLINE boolean Dem_ComponentIsFailedNotRecoverableItself(Dem_ComponentIdType ComponentId)
{
    return Dem_ComponentStatusIsSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_FAILEDNOTRECOVERABLE]);
}


DEM_INLINE boolean Dem_ComponentIsAvailable(Dem_ComponentIdType ComponentId)
{
	   return (Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_NOTAVAILABLE] == 0);
}


DEM_INLINE boolean Dem_ComponentIsInitialized(Dem_ComponentIdType ComponentId)
{
	   return (Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_NOTINIT] == 0);
}

DEM_INLINE boolean Dem_ComponentAreAncestorsInitialized(Dem_ComponentIdType ComponentId)
{
	return !Dem_ComponentStatusIsAnyAncestorSet(Dem_AllComponentsState[ComponentId].status[DEM_COMPONENTSTATUS_NOTINIT]);
}

DEM_INLINE boolean Dem_ComponentIsRestrictedUsable(Dem_ComponentIdType ComponentId)
{
	return (   (Dem_ComponentIsInitialized(ComponentId))
			&& (Dem_ComponentIsAvailable(ComponentId))
			&& (!Dem_ComponentIsFailed(ComponentId))
			);
}

DEM_INLINE boolean Dem_ComponentIsUsable(Dem_ComponentIdType ComponentId)
{
	return (   (Dem_ComponentIsRestrictedUsable(ComponentId))
			&& (!Dem_ComponentIsSuspicious(ComponentId))
			);
}



DEM_INLINE boolean Dem_ComponentRecoveryAllowed (Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);

    return (TRUE
#if (DEM_CFG_DEPRECOVERYLIMIT == DEM_CFG_DEPRECOVERYLIMIT_ON)
            && (    (Dem_AllComponentsState[ComponentId].performedRecoveries < Dem_AllComponentsParam[ComponentId].allowedRecoveries)
                 || (DEM_COMPONENT_INFINITE_RECOVERIES == Dem_AllComponentsParam[ComponentId].allowedRecoveries)
               )

#endif
           );
}


DEM_INLINE void Dem_ComponentResetPerformedRecoveries (Dem_ComponentIdType ComponentId)

{
#if (DEM_CFG_DEPRECOVERYLIMIT == DEM_CFG_DEPRECOVERYLIMIT_ON)
    {
        Dem_AllComponentsState[ComponentId].performedRecoveries = 0;
    }
#else
    DEM_UNUSED_PARAM(ComponentId);
#endif
}

DEM_INLINE void Dem_ComponentCallFailedCallback (Dem_ComponentIdType ComponentId, boolean failed)
{
#if (DEM_CFG_COMPONENTFAILEDCALLBACK_COUNT > 0)
	if (Dem_AllComponentsParam[ComponentId].componentFailedCallbackIdx != 0)
	{
		(Dem_ComponentFailedCallbacks[Dem_AllComponentsParam[ComponentId].componentFailedCallbackIdx])(failed);
	}
#else
	DEM_UNUSED_PARAM(ComponentId);
	DEM_UNUSED_PARAM(failed);
#endif
}


void Dem_Dependencies_SetComponentFailed(Dem_ComponentIdType ComponentId, boolean EventIsCausal, boolean EventStorageFiltered, boolean EventIsRecoverable);
void Dem_Dependencies_ResetComponentFailed(Dem_ComponentIdType ComponentId);
void Dem_Dependencies_SetComponentFailedFiltered(Dem_ComponentIdType ComponentId);
void Dem_Dependencies_ResetComponentFailedFiltered(Dem_ComponentIdType ComponentId);
void Dem_Dependencies_ResetComponentFailedNotRecoverable(Dem_ComponentIdType ComponentId);
void Dem_Dependencies_SetComponentFailedNotRecoverable(Dem_ComponentIdType ComponentId);
void Dem_ComponentSetSuspicious(Dem_ComponentIdType ComponentId, Dem_boolean_least suspicious);
void Dem_ComponentSetHasCausalFault (const Dem_ComponentIdType ComponentId, Dem_boolean_least causalFault);

void Dem_ComponentSetAvailable(Dem_ComponentIdType ComponentId, boolean AvailableStatus);


DEM_INLINE void Dem_ComponentSetRecovered(Dem_ComponentIdType ComponentId)
{
	DEM_UNUSED_PARAM(ComponentId);
#if (DEM_CFG_DEPRECOVERYLIMIT == DEM_CFG_DEPRECOVERYLIMIT_ON)
	if (Dem_AllComponentsState[ComponentId].performedRecoveries < Dem_AllComponentsParam[ComponentId].allowedRecoveries)
	{
		Dem_AllComponentsState[ComponentId].performedRecoveries++;
	}
#endif
}

DEM_INLINE void Dem_ComponentSetRecheckOnClear (Dem_ComponentIdType ComponentId, Dem_boolean_least newRecheckOnClear)
{
    rba_DiagLib_Bit8OverwriteBit(&(Dem_AllComponentsState[ComponentId].stateFlags), DEM_COMPONENT_STATEFLAG_RECHECKONCLEAR, newRecheckOnClear);
}

DEM_INLINE Dem_boolean_least Dem_ComponentIsRecheckOnClear (Dem_ComponentIdType ComponentId)
{
	return rba_DiagLib_Bit8IsBitSet(Dem_AllComponentsState[ComponentId].stateFlags, DEM_COMPONENT_STATEFLAG_RECHECKONCLEAR);
}

DEM_INLINE Dem_boolean_least Dem_ComponentIgnorePriority(Dem_ComponentIdType ComponentId)
{
	return rba_DiagLib_Bit8IsBitSet(Dem_AllComponentsParam[ComponentId].paramFlags, DEM_COMPONENT_PARAMFLAG_IGNOREPRIORITY);
}

DEM_INLINE Dem_boolean_least Dem_ComponentIsResetPerformedRecoveriesValueAllowed(Dem_ComponentIdType ComponentId)
{
    return rba_DiagLib_Bit8IsBitSet(Dem_AllComponentsParam[ComponentId].paramFlags, DEM_COMPONENT_PARAMFLAG_UPDATERECOVERY);
}



void Dem_ComponentRecheckOnClear (void);






#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"


#else

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"


DEM_INLINE Dem_boolean_least Dem_Dependencies_CheckEventIsCausal(Dem_EventIdType EventId, Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(EventId);
    DEM_UNUSED_PARAM(ComponentId);
    return TRUE;
}
DEM_INLINE void Dem_Dependencies_ResetComponentFailed(Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
}

DEM_INLINE void Dem_Dependencies_SetComponentFailed(Dem_ComponentIdType ComponentId, boolean EventIsCausal, boolean EventStorageFiltered, boolean EventIsRecoverable)
{
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(EventIsCausal);
    DEM_UNUSED_PARAM(EventStorageFiltered);
    DEM_UNUSED_PARAM(EventIsRecoverable);
}

DEM_INLINE void Dem_Dependencies_ResetComponentFailedFiltered(Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
}

DEM_INLINE void Dem_Dependencies_SetComponentFailedFiltered(Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
}

DEM_INLINE boolean Dem_ComponentIsAvailable(Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
    return TRUE;
}


DEM_INLINE boolean Dem_ComponentRecoveryAllowed (Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
    return TRUE;
}

DEM_INLINE void Dem_ComponentSetRecovered(Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
}

DEM_INLINE void Dem_ComponentSetSuspicious(Dem_ComponentIdType ComponentId, Dem_boolean_least suspicious)
{
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(suspicious);
}

DEM_INLINE Std_ReturnType Dem_ComponentSetAvailable (Dem_ComponentIdType ComponentId, boolean AvailableStatus)
{
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(AvailableStatus);
    return E_OK;
}

DEM_INLINE void Dem_ComponentSetHasCausalFault (const Dem_ComponentIdType ComponentId, Dem_boolean_least causalFault)
{
    DEM_UNUSED_PARAM(ComponentId);
    DEM_UNUSED_PARAM(causalFault);
}

DEM_INLINE void Dem_ComponentSetRecheckOnClear (Dem_ComponentIdType ComponentId, Dem_boolean_least newRecheckOnClear) { DEM_UNUSED_PARAM(ComponentId); DEM_UNUSED_PARAM(newRecheckOnClear); }
DEM_INLINE void Dem_ComponentRecheckOnClear (void) {}

DEM_INLINE void Dem_Dependencies_SetComponentFailedNotRecoverable(Dem_ComponentIdType ComponentId)
{
    DEM_UNUSED_PARAM(ComponentId);
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif


#endif
