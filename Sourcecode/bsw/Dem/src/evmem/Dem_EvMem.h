

#ifndef DEM_EVMEM_H
#define DEM_EVMEM_H


#include "Dem_Types.h"
#include "Dem_Cfg_EvMem.h"
#include "Dem_Cfg_EnvMain.h"
#include "Dem_OperationCycle.h"

#include "Dem_EvMemTypes.h"
#include "Dem_EvMemBase.h"

#include "Dem_EvMemApi.h"
#include "Dem_EvMemAging.h"
#if (DEM_CFG_EVMEM_AGING_METHOD == DEM_CFG_EVMEM_AGING_METHOD_USER)
#include "Dem_PrjEvMemAging.h"
#endif
#include "Dem_Cfg_Events_DataStructures.h"

typedef uint16 Dem_EvMemMapOrigin2IdType;

typedef struct {
    Dem_DTCOriginType dtcOrigin;
    uint16 evMemId;
} Dem_EvMemUserDefinedMapType;

#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
DEM_ARRAY_DECLARE_CONST(Dem_EvMemMapOrigin2IdType, Dem_EvMemMapOrigin2Id, DEM_CFG_EVMEM_ORIGIN2ID_LENGTH);
/* If there is a user memory defined create mapping table */
#if (DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0)
DEM_ARRAY_DECLARE_CONST(Dem_EvMemUserDefinedMapType, Dem_EvMemUserDefinedMapList, DEM_CFG_USERDEFINED_MEMORIES_NUMBER);
#endif
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"

/* ----------------------------------------------------------------------------
   Interface Functions
   ----------------------------------------------------------------------------
*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
void          Dem_EvMemInit(void);
void          Dem_EvMemInitCausality(void);
void          Dem_EvMemMainFunction(void);

void          Dem_EvMemClearEvent(Dem_EventIdType EventId, uint16_least MemId);
void          Dem_EvMemEraseEventMemory(uint16_least MemId);

void          Dem_EvMemSetEventPassed(Dem_EventIdType EventId, uint16_least MemId, const uint8 *EnvData);
void          Dem_EvMemSetEventFailed(Dem_EventIdType EventId, uint16_least MemId, const uint8 *EnvData);
#if(DEM_CFG_IS_EVERY_TEST_FAILED_TRIGGER_CONFIGURED)
void          Dem_EvMemUpdateFFOnTestFailed(Dem_EventIdType EventId, uint16_least MemId, const uint8 *EnvData);
#endif
void          Dem_EvMemSetEventUnRobust(Dem_EventIdType EventId, uint16_least MemId, const uint8 *EnvData);
void          Dem_EvMemStartOperationCycle(Dem_OperationCycleList operationCycleList, uint16_least MemId);

void          Dem_EvMem_ResetEvent_ForOBDConsistency(uint16_least EvMemLocId);

uint16_least  Dem_EvMemGetEventMemoryOrReaderCopyLocIdOfDtcWithVisibility(Dem_DtcIdType DtcId, uint16_least MemId, Dem_boolean_least ShadowEntriesVisible, Dem_boolean_least SearchInReaderCopy);
uint16_least  Dem_EvMemGetEventMemoryStatusOfDtc(Dem_DtcIdType DtcId, uint16_least MemId);
uint16_least  Dem_EvMemGetEventMemoryStatusOfEvent(Dem_EventIdType EventId, uint16_least MemId);
uint16_least  Dem_EvMemGetEventMemoryLocIdOfEvent (Dem_EventIdType EventId, uint16_least MemId);
Std_ReturnType Dem_EvMemGetReaderCopyOfEvent(Dem_EvMemEventMemoryType* ReaderCopy, Dem_EventIdType EventId, uint16_least MemId);
void          Dem_EvMemSetStatusWithNotifications(uint16_least LocId, uint16_least StatusNew, uint16_least WriteSts, Dem_EvMemActionType actionType);
void          Dem_EvMemSetNextReportRelevantForStorageFilteredEventsForEvCombOnStorage(Dem_EventIdType EventId);

#if DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED
void          Dem_EvMemClearShadowMemory(Dem_EventIdType EventId, uint16_least MemId);
uint16_least  Dem_EvMemGetShadowMemoryLocIdOfDtc(Dem_DtcIdType DtcId, uint16_least MemId);
#endif

uint16_least  Dem_EvMemGetMemoryLocIdOfDtcAndOriginWithVisibility(Dem_DtcIdType DtcId, Dem_DTCOriginType DTCOrigin, Dem_boolean_least ShadowEntriesVisible);


Dem_NvmBlockIdType     Dem_EvMemGetNvmIdFromLocId(uint16_least LocId);

#if (DEM_CFG_READDEM_MAX_FDC_DURING_CURRENT_CYCLE_SUPPORTED || DEM_CFG_READDEM_MAX_FDC_SINCE_LAST_CLEAR_SUPPORTED)
void            Dem_EvMemFdcUpdate(void);
#else
DEM_INLINE void Dem_EvMemFdcUpdate(void) {}
#endif
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"
extern boolean Dem_EvMemIsLocked;
#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"
/* ----------------------------------------------------------------------------
   Inline
   ----------------------------------------------------------------------------
*/
#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
DEM_INLINE uint8_least Dem_EvMemFetchUserMemoryIndexFromOrigin (Dem_DTCOriginType origin)
{
    /* Default value will be zero which is the first userdefined memory */
    uint8_least i,index_userdefined = 0;

    for(i = 0; i < DEM_CFG_USERDEFINED_MEMORIES_NUMBER; i++)
    {
        /* this function is used in memGen so invalid DTC origin should not be the case */
        if(Dem_EvMemUserDefinedMapList[i].dtcOrigin == origin)
        {
            index_userdefined = i;
            break;
        }
    }
    return index_userdefined;
}

DEM_INLINE uint16_least Dem_EvMemGetUserDefinedEvMemIdFromOrigin (Dem_DTCOriginType origin)
{
    uint16_least memId = DEM_EVMEM_INVALID_MEMID;
    uint8_least i = 0;

    for(i = 0; i < DEM_CFG_USERDEFINED_MEMORIES_NUMBER; i++)
    {
        if(Dem_EvMemUserDefinedMapList[i].dtcOrigin == origin)
        {
            memId = Dem_EvMemUserDefinedMapList[i].evMemId;
            break;
        }
    }
    return memId;
}
#endif

DEM_INLINE uint16_least Dem_EvMemGetMemIdForDTCOrigin (Dem_DTCOriginType origin)
{
    uint16_least memId = DEM_EVMEM_INVALID_MEMID;

#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
    if(origin >= DEM_CFG_EVMEM_USERDEFINED_DTC_ORIGIN_OFFSET)
    {
        memId = Dem_EvMemGetUserDefinedEvMemIdFromOrigin(origin);
    }
    else
#endif
    if(origin < DEM_CFG_EVMEM_ORIGIN2ID_LENGTH)
    {
        memId = Dem_EvMemMapOrigin2Id[origin];
    }else{
        /* do nothing */
    }

    return memId;
}

#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
DEM_INLINE void Dem_EvMemGetUserDefinedDTCOriginFromMemId (uint16_least MemId, Dem_DTCOriginType * origin)
{
    uint8_least i = 0;

    /* Check if memId is valid */
    if(Dem_EvMemIsMemIdValid(MemId))
    {
        for(i = 0; i < DEM_CFG_USERDEFINED_MEMORIES_NUMBER; i++)
        {
            if(Dem_EvMemUserDefinedMapList[i].evMemId == MemId)
            {
                *origin = Dem_EvMemUserDefinedMapList[i].dtcOrigin;
                break;
            }
        }
    }
    else
    {
        /* DTCOrigin will be filled by either mirror or primary in the caller function */
    }
}
#endif

DEM_INLINE Dem_boolean_least Dem_EvMemIsDtcOriginValid (Dem_DTCOriginType *  DTCOrigin)
{
    if(*DTCOrigin == DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY)
    {
        *DTCOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
    }
    return (
               (*DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
               /* Permanent was and is not supported in this function */
            || ((*DTCOrigin >= DEM_CFG_EVMEM_USERDEFINED_DTC_ORIGIN_OFFSET)
                    && (Dem_EvMemGetUserDefinedEvMemIdFromOrigin(*DTCOrigin) != DEM_EVMEM_INVALID_MEMID))
#endif
#if (DEM_CFG_MAX_NUMBER_EVENT_ENTRY_MIRROR > 0) || DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED
            || (*DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY)
#endif
           );
}

DEM_INLINE uint16_least Dem_EvMemGetEventMemoryLocIdOfDtcWithVisibility(Dem_DtcIdType DtcId, uint16_least MemId, Dem_boolean_least ShadowEntriesVisible)
{
    return Dem_EvMemGetEventMemoryOrReaderCopyLocIdOfDtcWithVisibility(DtcId, MemId, ShadowEntriesVisible, FALSE);
}


DEM_INLINE void Dem_EvMemSetEventFailedAllMem(Dem_EventIdType EventId, const uint8 *EnvData)
{
   if (Dem_EvtParam_GetIsEventDestPrimary(EventId))
   {
      Dem_EvMemSetEventFailed(EventId,DEM_CFG_EVMEM_MEMID_PRIMARY,EnvData);
   }
#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
   if (Dem_EvtParam_GetIsEventDestUserDefined(EventId))
   {
       Dem_EvMemSetEventFailed(EventId,
						       /* This function will return a valid value */
						       Dem_EvMemGetMemIdForDTCOrigin(Dem_EvtParam_GetEventUserDefinedDTCOrigin(EventId)),EnvData);
   }
#endif
}

#if(DEM_CFG_IS_EVERY_TEST_FAILED_TRIGGER_CONFIGURED)
/* This function purpose is to update the freeze frame in case of trigger on every test failed */
DEM_INLINE void Dem_EvMemUpdateEventFreezeFrameAllMem(Dem_EventIdType EventId, const uint8 *EnvData)
{
    if (Dem_EvtParam_GetIsEventDestPrimary(EventId))
    {
        Dem_EvMemUpdateFFOnTestFailed(EventId,DEM_CFG_EVMEM_MEMID_PRIMARY,EnvData);
    }
#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
   if (Dem_EvtParam_GetIsEventDestUserDefined(EventId))
    {
        Dem_EvMemUpdateFFOnTestFailed(EventId,
							        /* This function will return a valid value */
							        Dem_EvMemGetMemIdForDTCOrigin(Dem_EvtParam_GetEventUserDefinedDTCOrigin(EventId)),EnvData);
    }
 #endif
}
#endif
DEM_INLINE void Dem_EvMemSetEventPassedAllMem(Dem_EventIdType EventId, const uint8 *EnvData)
{
   if (Dem_EvtParam_GetIsEventDestPrimary(EventId))
   {
      Dem_EvMemSetEventPassed(EventId,DEM_CFG_EVMEM_MEMID_PRIMARY,EnvData);
   }
#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
   if (Dem_EvtParam_GetIsEventDestUserDefined(EventId))
   {
       Dem_EvMemSetEventPassed(EventId,
						       /* This function will return a valid value */
						       Dem_EvMemGetMemIdForDTCOrigin(Dem_EvtParam_GetEventUserDefinedDTCOrigin(EventId)),EnvData);
   }
#endif
}


DEM_INLINE void Dem_EvMemSetEventUnRobustAllMem(Dem_EventIdType EventId, const uint8 *EnvData)
{
   if (Dem_EvtParam_GetIsEventDestPrimary(EventId))
   {
      Dem_EvMemSetEventUnRobust(EventId,DEM_CFG_EVMEM_MEMID_PRIMARY,EnvData);
   }
#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
   if (Dem_EvtParam_GetIsEventDestUserDefined(EventId))
   {
       Dem_EvMemSetEventUnRobust(EventId,
						       /* This function will return a valid value */
						       Dem_EvMemGetMemIdForDTCOrigin(Dem_EvtParam_GetEventUserDefinedDTCOrigin(EventId)),EnvData);
   }
#endif
}

DEM_INLINE void Dem_EvMemStartOperationCycleAllMem(Dem_OperationCycleList operationCycleList)
{
#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
    uint8 i = 0;
#endif

    Dem_EvMemStartOperationCycle(operationCycleList, DEM_CFG_EVMEM_MEMID_PRIMARY);

#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
    for(i = 0; i < DEM_CFG_USERDEFINED_MEMORIES_NUMBER; i++)
    {
        /* All memories defined are valid */
        Dem_EvMemStartOperationCycle(operationCycleList,
                                     Dem_EvMemUserDefinedMapList[i].evMemId);
    }
#endif
}

DEM_INLINE void Dem_EvMemClearEventAndOrigin(Dem_EventIdType EventId, Dem_DTCOriginType DTCOrigin)
{
    uint16_least MemId = Dem_EvMemGetMemIdForDTCOrigin(DTCOrigin);
    if (!Dem_EvMemIsMemIdValid(MemId))
    {
        return;
    }

#if DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED
    if (DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY)
    {
        Dem_EvMemClearShadowMemory(EventId, MemId);
        return;
    }
#endif

    Dem_EvMemClearEvent(EventId, MemId);


}

DEM_INLINE uint16_least  Dem_EvMemGetEventMemoryStatusOfDtcAndOrigin(Dem_DtcIdType DtcId, Dem_DTCOriginType DTCOrigin)
{
    uint16_least MemId = Dem_EvMemGetMemIdForDTCOrigin(DTCOrigin);
    if (!Dem_EvMemIsMemIdValid(MemId) ||
            (Dem_LibGetParamBool(DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED) && (DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY))
       )
    {
        return 0;
    }

    return Dem_EvMemGetEventMemoryStatusOfDtc(DtcId, MemId);
}

DEM_INLINE uint16_least  Dem_EvMemGetEventMemoryStatusOfEventAndOrigin(Dem_EventIdType EventId, Dem_DTCOriginType DTCOrigin)
{
    uint16_least MemId = Dem_EvMemGetMemIdForDTCOrigin(DTCOrigin);
    if (!Dem_EvMemIsMemIdValid(MemId) ||
            (Dem_LibGetParamBool(DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED) && (DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY))
       )
    {
        return 0;
    }

    return Dem_EvMemGetEventMemoryStatusOfEvent(EventId, MemId);
}

DEM_INLINE uint16_least Dem_EvMemGetMemIdForEvent(Dem_EventIdType EventId)
{
    if(Dem_EvtParam_GetIsEventDestPrimary(EventId))
    {
        return DEM_CFG_EVMEM_MEMID_PRIMARY;
    }

#if DEM_CFG_USERDEFINED_MEMORIES_NUMBER > 0
    if(Dem_EvtParam_GetIsEventDestUserDefined(EventId))
    {
        return Dem_EvMemGetMemIdForDTCOrigin(Dem_EvtParam_GetEventUserDefinedDTCOrigin(EventId));
    }
#endif

    return DEM_EVMEM_INVALID_MEMID;
}

DEM_INLINE uint16_least Dem_EvMemGetLocationOfEventFromEventMemory(Dem_EventIdType EventId)
{
    uint16_least MemId = Dem_EvMemGetMemIdForEvent(EventId);
    if (!Dem_EvMemIsMemIdValid(MemId))
    {
        return DEM_EVMEM_INVALID_LOCID;
    }

    return Dem_EvMemGetEventMemoryLocIdOfEvent(EventId, MemId);

}

DEM_INLINE Std_ReturnType Dem_EvMemGetReaderCopyOfEventFromEventMemory(
        Dem_EvMemEventMemoryType* ReaderCopy,
        Dem_EventIdType EventId
)
{
    uint16_least MemId = Dem_EvMemGetMemIdForEvent(EventId);
    if (!Dem_EvMemIsMemIdValid(MemId))
    {
        return E_NOT_OK;
    }

    return Dem_EvMemGetReaderCopyOfEvent(ReaderCopy, EventId, MemId);
}

DEM_INLINE boolean Dem_GetEvMemLockInternal(void)
{
    return Dem_EvMemIsLocked;
}
DEM_INLINE uint16_least Dem_EvMemGetMemoryLocIdOfDtcAndOrigin(Dem_DtcIdType DtcId, Dem_DTCOriginType DTCOrigin)
{
    /* do not report deleted DTCs */
    return Dem_EvMemGetMemoryLocIdOfDtcAndOriginWithVisibility(DtcId,DTCOrigin,FALSE);
}
DEM_INLINE uint16_least Dem_EvMemGetEventMemoryLocIdOfDtc(Dem_DtcIdType DtcId, uint16_least MemId)
{
    /* do not report deleted DTCs */
    return Dem_EvMemGetEventMemoryLocIdOfDtcWithVisibility(DtcId,MemId,FALSE);
}

DEM_INLINE void Dem_EvMemReaderCopiesEnterLock(void)
{
    /* We do not need to lock if we access the reader copy location only within the same task */
    if (Dem_LibGetParamBool(DEM_CFG_EVMEM_READ_FROM_DIFFERENT_TASK))
    {
        DEM_ENTERLOCK_MON();
    }
}

DEM_INLINE void Dem_EvMemReaderCopiesExitLock(void)
{
    if (Dem_LibGetParamBool(DEM_CFG_EVMEM_READ_FROM_DIFFERENT_TASK))
    {
        DEM_EXITLOCK_MON();
    }
}

DEM_INLINE void Dem_EvMemClearNvm(void)
{
    uint16_least LocId;

    for (Dem_EvMemEventMemoryAllLocIteratorNew    (&LocId);
         Dem_EvMemEventMemoryAllLocIteratorIsValid(&LocId);
         Dem_EvMemEventMemoryAllLocIteratorNext   (&LocId))
    {
        DEM_EVMEM_CLEAROBJ(Dem_EvMemEventMemory[LocId]);
        Dem_NvMClearBlockByInvalidate(Dem_EvMemGetNvmIdFromLocId (LocId));
    }
}

#endif
