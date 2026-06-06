

#ifndef DEM_ENABLECONDITION_H
#define DEM_ENABLECONDITION_H


#include "Dem_Types.h"
#include "Dem_Cfg_EnableCondition.h"


#if (DEM_CFG_ENABLECONDITIONS_AVAILABLE == DEM_CFG_ENABLECONDITION_ON)

typedef struct {
    Dem_EnCoList isActive[DEM_ENCOBITMASK_ARRAYLENGTH];
} Dem_EnCoState;

#define DEM_START_SEC_VAR_INIT
#include "Dem_MemMap.h"
extern Dem_EnCoState Dem_EnCoAllStates;
extern const Dem_EnCoList  Dem_EnableConditionGroups[DEM_ENCOGROUP_ARRAYLENGTH][DEM_ENCOBITMASK_ARRAYLENGTH];
#define DEM_STOP_SEC_VAR_INIT
#include "Dem_MemMap.h"

#endif

/* Dem449: If one enable condition is not fulfilled, all status reports from SW-Cs
   (Dem_SetEventStatus and Dem_ResetEventStatus) and BSW modules
   for those events being assigned to this condition shall be ignored (no change of
   UDS DTC status byte) by the DEM.
 */

DEM_INLINE Dem_boolean_least Dem_EnCoAreAllFulfilled (uint8 groupIndex)
{
#if (DEM_CFG_ENABLECONDITIONS_AVAILABLE == DEM_CFG_ENABLECONDITION_ON)
    boolean retVal=TRUE;
    uint8 i;
    for(i=0;i<DEM_ENCOBITMASK_ARRAYLENGTH;i++)
    {
        retVal = retVal && (((Dem_EnableConditionGroups[groupIndex][i]) & (Dem_EnCoAllStates.isActive[i])) == Dem_EnableConditionGroups[groupIndex][i]);
    }
    return retVal;
#else
   DEM_UNUSED_PARAM(groupIndex);
   return TRUE;
#endif
}


#if (DEM_CFG_ENABLECONDITIONS_AVAILABLE == DEM_CFG_ENABLECONDITION_ON)
void Dem_EnCoCallbacks(void);
#endif

#endif

