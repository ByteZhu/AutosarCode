

#ifndef DEM_STORAGECONDITION_H
#define DEM_STORAGECONDITION_H



#include "Dem_Cfg_StorageCondition.h"
#include "Dem_Mapping.h"
#include "Dem_Lock.h"
#include "Dem_Helpers.h"
#include "Dem_Cfg_Events.h"





#if (DEM_CFG_STORAGECONDITIONS_AVAILABLE == DEM_CFG_STORAGECONDITION_ON)


typedef struct {
   Dem_StoCoList isActive[DEM_STOCOBITMASK_ARRAYLENGTH];
   Dem_StoCoList isReplacementEventRequested[DEM_STOCOBITMASK_ARRAYLENGTH];
   Dem_StoCoList isReplacementEventStored[DEM_STOCOBITMASK_ARRAYLENGTH];

   Dem_EventIdType eventId[DEM_STORAGECONDITION_COUNT];
   /* MR12 RULE 1.2 VIOLATION: The compiler treats the array of length 1 as the final member. But a change of the sequence leads to padding, because different values are based on configuration. This warning can be ignored. */
   Dem_MonitorDataType monitorData1[DEM_STORAGECONDITION_COUNT];

} Dem_StoCoState;


typedef struct {
   /* MR12 RULE 1.2 VIOLATION: Parameter DEM_STORAGECONDITION_COUNT is generated with different value based on configuration. This warning can be ignored. */
   Dem_EventIdType replacementEvent[DEM_STORAGECONDITION_COUNT];
} Dem_StoCoParam;

#define DEM_START_SEC_VAR_INIT
#include "Dem_MemMap.h"

extern Dem_StoCoState Dem_StoCoAllStates;
extern const Dem_StoCoList  Dem_StorageConditionGroups[DEM_STOCOGROUP_ARRAYLENGTH][DEM_STOCOBITMASK_ARRAYLENGTH];

#define DEM_STOP_SEC_VAR_INIT
#include "Dem_MemMap.h"


#endif



#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"


/*** INTERNAL FUNCTIONS *******************************************************/

Dem_EventIdType Dem_Stoco_GetReplacementEventID(Dem_StoCoList replacementIdIndex);

DEM_INLINE boolean Dem_StoCoAreAllFulfilled(uint8 groupIndex)
{
#if (DEM_CFG_STORAGECONDITIONS_AVAILABLE == DEM_CFG_STORAGECONDITION_ON)
    boolean retVal=TRUE;
    uint8 i;
    for(i=0;i<DEM_STOCOBITMASK_ARRAYLENGTH;i++)
    {
        retVal = retVal && ((Dem_StorageConditionGroups[groupIndex][i] & Dem_StoCoAllStates.isActive[i]) == Dem_StorageConditionGroups[groupIndex][i]);
    }
   return retVal;
#else
   DEM_UNUSED_PARAM(groupIndex);
   return TRUE;
#endif
}

#if (DEM_CFG_STORAGECONDITIONS_AVAILABLE == DEM_CFG_STORAGECONDITION_ON)

void Dem_StoCoMainFunction(void);
void Dem_StoCoRecheckReplacementStorage(uint8 groupIndex);
void Dem_StoCoClearReplacementStoredFlag(void);
void Dem_StoCoSetHasFilteredEvent(uint8 groupIndex, Dem_MonitorDataType EventId, Dem_MonitorDataType monitorData1);


#else

DEM_INLINE void Dem_StoCoMainFunction(void) {}
DEM_INLINE void Dem_StoCoRecheckReplacementStorage(uint8 groupIndex) { DEM_UNUSED_PARAM(groupIndex); }
DEM_INLINE void Dem_StoCoSetHasFilteredEvent(uint8 groupIndex, Dem_MonitorDataType EventId, Dem_MonitorDataType monitorData1){

   DEM_UNUSED_PARAM(groupIndex);
   DEM_UNUSED_PARAM(EventId);
   DEM_UNUSED_PARAM(monitorData1);
}

#endif


#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"



#endif

