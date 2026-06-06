
#include "Dem_Internal.h"
#include "Rte_Dem.h"

#include "Dem_Events.h"
#include "Dem_EnableCondition.h"
#include "Dem_Lock.h"
#include "Dem_Prv_Det.h"
#include "Dem_Cfg_Events_DataStructures.h"

#define DEM_START_SEC_VAR_INIT
#include "Dem_MemMap.h"

#if (DEM_CFG_ENABLECONDITIONS_AVAILABLE == DEM_CFG_ENABLECONDITION_ON)
const Dem_EnCoList  Dem_EnableConditionGroups[DEM_ENCOGROUP_ARRAYLENGTH][DEM_ENCOBITMASK_ARRAYLENGTH] = DEM_ENABLECONDITIONGROUPS
Dem_EnCoState Dem_EnCoAllStates = { DEM_CFG_ENCO_INITIALSTATE };
static Dem_EnCoList Dem_EnCoReEnabledBitMask[DEM_ENCOBITMASK_ARRAYLENGTH] = {0};
#endif

#define DEM_STOP_SEC_VAR_INIT
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_CFG_ENABLECONDITIONS_AVAILABLE == DEM_CFG_ENABLECONDITION_ON)
Std_ReturnType Dem_SetEnableCondition (uint8 EnableConditionID,
                                       boolean ConditionFulfilled)
{
    Dem_EnCoList enableConditionBitmask = 0;
    uint8 bitpos = 0;
    uint8 arrayIndex = (EnableConditionID/DEM_ENABLECONDITION_MAXBIT_LENGTH); /*From the enable condition ID requested, Index is calculated to update the state of corresponding array element*/
    Dem_boolean_least isEnCoAlreadyFulfilled;

    DEM_ENTRY_CONDITION_CHECK_DEM_ENCO_ID_VALID((EnableConditionID), (DEM_DET_APIID_SETENABLECONDITION),(E_NOT_OK));

    bitpos = (EnableConditionID%DEM_ENABLECONDITION_MAXBIT_LENGTH);
    enableConditionBitmask = (1u<<bitpos);

    DEM_ENTERLOCK_MON();

    if (ConditionFulfilled)
    {
        isEnCoAlreadyFulfilled = ((enableConditionBitmask & Dem_EnCoAllStates.isActive[arrayIndex]) == enableConditionBitmask);

        if(!isEnCoAlreadyFulfilled)
        {
            Dem_EnCoReEnabledBitMask[arrayIndex] |= enableConditionBitmask;
        }
        Dem_EnCoAllStates.isActive[arrayIndex] |= enableConditionBitmask;
    }
    else
    {
        Dem_EnCoAllStates.isActive[arrayIndex] &= (~enableConditionBitmask);
    }

    DEM_EXITLOCK_MON();

    return E_OK;
}

/* MR12 RULE 8.13 VIOLATION: The pointer will be modified based on the configuration. */
Std_ReturnType Dem_GetEnableCondition (uint8 EnableConditionID,
                                       boolean* ConditionFulfilled)
{
    Dem_EnCoList enableConditionBitmask = 0;
    uint8 bitpos=0;
    uint8 arrayIndex = (EnableConditionID/DEM_ENABLECONDITION_MAXBIT_LENGTH); /* Index is calculated to select the array element in which the Enable condition state availble for a requested EnCo Id */

    /* Entry Condition Check */
    DEM_ENTRY_CONDITION_CHECK_NOT_NULL_PTR((ConditionFulfilled),(DEM_DET_APIID_GETENABLECONDITION),(E_NOT_OK));
    DEM_ENTRY_CONDITION_CHECK_DEM_ENCO_ID_VALID((EnableConditionID), (DEM_DET_APIID_GETENABLECONDITION),(E_NOT_OK));

    /*As the enable conditions can be configured 0-255, the bit position is calculated to mask it to a corresponding array element*/
    bitpos = (EnableConditionID%DEM_ENABLECONDITION_MAXBIT_LENGTH);
    enableConditionBitmask = (1u<<bitpos);

    *ConditionFulfilled = (0u != (Dem_EnCoAllStates.isActive[arrayIndex] & enableConditionBitmask));

    return E_OK;
}

void Dem_EnCoCallbacks(void)
{
    Dem_EventIdIterator eventIt;
    Dem_EventIdType eventId;
    uint8 groupIndex;
    Dem_EnCoList currentEnCoReEnabledBitMask = 0;
    uint8 enCo;

  for(enCo=0;enCo<DEM_ENCOBITMASK_ARRAYLENGTH;enCo++)
  {
    if(Dem_EnCoReEnabledBitMask[enCo] != 0u)
    {
        DEM_ENTERLOCK_MON();

        currentEnCoReEnabledBitMask = Dem_EnCoReEnabledBitMask[enCo];
        Dem_EnCoReEnabledBitMask[enCo] = 0;

        DEM_EXITLOCK_MON();

        for (Dem_EventIdIteratorNew(&eventIt); Dem_EventIdIteratorIsValid(&eventIt); Dem_EventIdIteratorNext(&eventIt))
        {
            eventId = Dem_EventIdIteratorCurrent(&eventIt);
            groupIndex = Dem_EvtParam_GetEnableConditionGroupIndex(eventId);


            /** Ensure Enable condition is Valid and currentEnCoReEnabledBitMask is in the Enablecondition List **/
            if((Dem_EnableConditionGroups[groupIndex][enCo] != 0u) && ((currentEnCoReEnabledBitMask & Dem_EnableConditionGroups[groupIndex][enCo]) != 0u))
            {
                if(Dem_EnCoAreAllFulfilled(groupIndex))
                {
                    DEM_ENTERLOCK_MON();
                    Dem_EvtSetInitMonitoring (eventId, DEM_INIT_MONITOR_REENABLED);
                    DEM_EXITLOCK_MON();
                }
            }

        }
    }
}
}
#endif
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
