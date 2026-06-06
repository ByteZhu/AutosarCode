
#ifndef DEM_ENVFFRECNUMERATION_H
#define DEM_ENVFFRECNUMERATION_H


#include "Dem_Types.h"
#include "Dem_Cfg_EnvFFRecNumeration.h"
#include "Dem_Events.h"
#include "Dem_EvMem.h"
#include "Dem_Cfg_Events_DataStructures.h"

/* At least one memory is configured as DEM_CFG_FFRECNUM_CONFIGURED */
#if (DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CONFIGURED)

#define DEM_ENV_FFRECNUM_INDEX_INVALID   0xFF

typedef struct
{
   uint8 recordNumber;
   Dem_TriggerType trigger;
   boolean update;
} Dem_EnvFFRec;

typedef uint8 Dem_EvMemFFRECNUMType;

#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
extern const uint8 Dem_Cfg_EnvFFRecNumConf[DEM_CFG_FFRECCLASS_NUMBEROF_FFRECCLASSES][DEM_CFG_FFRECCLASS_MAXNUMBEROF_FFFRECNUMS];
#if DEM_CFG_FFRECCLASS_NUMBEROF_FFRECCLASSES > 1
DEM_ARRAY_DECLARE_CONST(uint8, Dem_Cfg_EnvEventId2FrecNumClass, DEM_EVENTID_ARRAYLENGTH);
#endif
DEM_ARRAY_DECLARE_CONST(Dem_EvMemFFRECNUMType, Dem_Cfg_EVMemFFRECNUMType, DEM_CFG_EVMEM_FFRECNUM_SIZE);
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
uint8 Dem_EnvGetIndexOfFFRecConf(Dem_EventIdType EventId, uint8 RecNumber);
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

extern const Dem_EnvFFRec Dem_Cfg_EnvFFRec[DEM_CFG_ENVFFREC_ARRAYLENGTH];

/** these functions should not be called unless the memory is configured as DEM_CFG_FFRECNUM_CONFIGURED **/

/* This function should be called only if memId is valid */
DEM_INLINE uint8 Dem_EnvGetEvMemFFRecNumType (uint16_least memId)
{
    return Dem_Cfg_EVMemFFRECNUMType[memId];
}

DEM_INLINE uint8 Dem_EnvGetFFRecNumClassIndex (Dem_EventIdType EventId)
{
#if DEM_CFG_FFRECCLASS_NUMBEROF_FFRECCLASSES > 1
    return Dem_Cfg_EnvEventId2FrecNumClass[EventId];
#else
    return 0;
#endif
}

DEM_INLINE Dem_TriggerType Dem_EnvGetFFRecordTrigger (uint8 RecNumber)
{
    uint8 indx;

    for(indx = 1 ; indx < DEM_CFG_ENVFFREC_ARRAYLENGTH ; indx++)
    {
        if(Dem_Cfg_EnvFFRec[indx].recordNumber == RecNumber)
        {
            return Dem_Cfg_EnvFFRec[indx].trigger;
        }
    }

    return 0;
}

DEM_INLINE void Dem_EnvGetFFRecordTriggerAndUpdate (uint8 RecNumber, Dem_TriggerType* Trigger, boolean* Update)
{
    uint8 indx;

   for(indx = 1 ; indx < DEM_CFG_ENVFFREC_ARRAYLENGTH ; indx++)
   {
       if(Dem_Cfg_EnvFFRec[indx].recordNumber == RecNumber)
       {
           *Trigger = Dem_Cfg_EnvFFRec[indx].trigger;
           *Update = Dem_Cfg_EnvFFRec[indx].update;
           return;
       }
   }
   *Trigger = 0;
   *Update = FALSE;
}
#endif

/* The code is optimized to not compile code if no memory is configured with as specific configuration */

DEM_INLINE Dem_boolean_least Dem_EnvIsFFRecNumValid(Dem_EventIdType EventId, uint8 RecNumber)
{
#if(DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CONFIGURED)
    uint8 RecNumberIndex;
    uint16_least memId;
#endif
    if(Dem_isEventIdValid(EventId))
    {
#if(DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CONFIGURED)
        memId = Dem_EvMemGetMemIdForEvent(EventId);
        /* Check if memId is valid and the memory is configured as DEM_CFG_FFRECNUM_CONFIGURED */
        if((memId < DEM_CFG_EVMEM_FFRECNUM_SIZE) && (Dem_Cfg_EVMemFFRECNUMType[memId] == DEM_CFG_FFRECNUM_CONFIGURED))
        {
            RecNumberIndex = Dem_EnvGetIndexOfFFRecConf(EventId,RecNumber);
            return (Dem_boolean_least)((RecNumber > 0) && (RecNumberIndex != DEM_ENV_FFRECNUM_INDEX_INVALID));
        }
        /* memory is configured as DEM_CFG_FFRECNUM_CALCULATED */
        else
#endif
        {
#if(DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CALCULATED)
            return ((RecNumber > 0) && (RecNumber <= Dem_EvtParam_GetMaxNumberFreezeFrameRecords(EventId)));
#endif
        }
    }
    /* This case is if memId is invalid */
    return FALSE;
}

DEM_INLINE uint8 Dem_EnvGetIndexFromFFRecNum(Dem_EventIdType EventId, uint8 RecNumber)
{
#if(DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CONFIGURED)
    uint8 RecNumberIndex;
    uint16_least memId = Dem_EvMemGetMemIdForEvent(EventId);

    /* Check if memId is valid and the memory is configured as DEM_CFG_FFRECNUM_CONFIGURED */
    if((memId < DEM_CFG_EVMEM_FFRECNUM_SIZE) && (Dem_Cfg_EVMemFFRECNUMType[memId] == DEM_CFG_FFRECNUM_CONFIGURED))
    {
        RecNumberIndex = Dem_EnvGetIndexOfFFRecConf(EventId,RecNumber);
        DEM_ASSERT(RecNumberIndex != DEM_ENV_FFRECNUM_INDEX_INVALID,DEM_DET_APIID_ENVGETINDEXFROMFFRECNUM,0x0);
        return RecNumberIndex;
    }
    else
#endif
    {
        /* Default return in case of memory configured as calculated or memory is invalid */
        DEM_UNUSED_PARAM(EventId);
        return (RecNumber - 1u);
    }
}


DEM_INLINE uint8 Dem_EnvGetFFRecNumFromIndex(Dem_EventIdType EventId, uint8 idx)
{
#if(DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CONFIGURED)
    uint16_least memId = Dem_EvMemGetMemIdForEvent(EventId);

    /* Check if memId is valid and the memory is configured as DEM_CFG_FFRECNUM_CONFIGURED */
    if((memId < DEM_CFG_EVMEM_FFRECNUM_SIZE) && (Dem_Cfg_EVMemFFRECNUMType[memId] == DEM_CFG_FFRECNUM_CONFIGURED))
    {
        DEM_ASSERT(idx < Dem_EvtParam_GetMaxNumberFreezeFrameRecords(EventId),DEM_DET_APIID_ENVGETFFRECNUMFROMINDEX,0x0);
        return Dem_Cfg_EnvFFRecNumConf [Dem_EnvGetFFRecNumClassIndex(EventId)][idx];
    }
    else
#endif
    {
        /* Default return in case of memory configured as calculated or memory is invalid */
        DEM_UNUSED_PARAM(EventId);
        return (idx + 1u);
    }
}

DEM_INLINE Dem_boolean_least Dem_EnvIsFFRecNumStored(const Dem_EvMemEventMemoryType *EventMemory, Dem_EventIdType EventId, uint8 RecNumber)
{
#if(DEM_CFG_IS_ANY_EVMEM_FFRECNUM_CONFIGURED)
    uint8 indx;
    uint16_least memId = Dem_EvMemGetMemIdForEvent(EventId);

    /* Check if memId is valid and the memory is configured as DEM_CFG_FFRECNUM_CONFIGURED */
    if((memId < DEM_CFG_EVMEM_FFRECNUM_SIZE) && (Dem_Cfg_EVMemFFRECNUMType[memId] == DEM_CFG_FFRECNUM_CONFIGURED))
    {
        for(indx = 1 ; indx < DEM_CFG_ENVFFREC_ARRAYLENGTH ; indx++)
        {
            if(Dem_Cfg_EnvFFRec[indx].recordNumber == RecNumber)
            {
                return (Dem_EnvIsTriggerSet(Dem_Cfg_EnvFFRec[indx].trigger , Dem_EvMemGetEventMemTriggerByPtr(EventMemory)));
            }
        }
        return FALSE;
    }
    else
#endif
    {
        /* Default action */
        return (Dem_EnvGetIndexFromFFRecNum(EventId, RecNumber) < Dem_EvMemGetEventMemFreezeFrameCounterByPtr(EventMemory));
    }
}

#endif
