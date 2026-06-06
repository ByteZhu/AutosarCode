
#include "Dem_Internal.h"
#include "Rte_Dem.h"

#include "Dem_StorageCondition.h"
#include "Dem_EventStatus.h"
#include "Dem_EventFHandling.h"
#include "Dem_EventRecheck.h"

#if (DEM_CFG_STORAGECONDITIONS_AVAILABLE == DEM_CFG_STORAGECONDITION_ON)


#define DEM_START_SEC_VAR_INIT
#include "Dem_MemMap.h"

const Dem_StoCoList  Dem_StorageConditionGroups[DEM_STOCOGROUP_ARRAYLENGTH][DEM_STOCOBITMASK_ARRAYLENGTH] = DEM_STORAGECONDITIONGROUPS
Dem_StoCoState Dem_StoCoAllStates = { DEM_CFG_STOCO_INITIALSTATE, {0}, {0}, {0}, {0} };

#define DEM_STOP_SEC_VAR_INIT
#include "Dem_MemMap.h"



#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"

static const Dem_StoCoParam Dem_StoCoAllParams = DEM_CFG_STOCO_PARAMS;

Dem_EventIdType Dem_Stoco_GetReplacementEventID(Dem_StoCoList replacementIdIndex)
{
   return Dem_StoCoAllParams.replacementEvent[replacementIdIndex];
}

#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"
#endif


#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_CFG_STORAGECONDITIONS_AVAILABLE == DEM_CFG_STORAGECONDITION_ON)

Std_ReturnType Dem_SetStorageCondition (uint8 StorageConditionID, boolean ConditionFulfilled)
{

    Dem_StoCoList storageConditionBitmask= 0;
    /*As the storage conditions can be configured 0-255, the bit position is calculated to mask it to a corresponding array element*/
    uint8 bitpos = 0;
    uint8 stoCoArrayIndex = 0;

    /* Entry Condition Check */
    DEM_ENTRY_CONDITION_CHECK_DEM_STOCO_ID_VALID((StorageConditionID), (DEM_DET_APIID_SETSTORAGECONDITION),(E_NOT_OK));

    /*As the storage conditions can be configured 0-255, the bit position is calculated to mask it to a corresponding array element*/
    bitpos = (StorageConditionID%DEM_STORAGECONDITION_MAXBIT_LENGTH);
    /*From the storage condition ID requested, Index is calculated to update the state of corresponding array element*/
    stoCoArrayIndex = (StorageConditionID/DEM_STORAGECONDITION_MAXBIT_LENGTH);

    storageConditionBitmask = (1u<<bitpos);

    DEM_ENTERLOCK_MON();

    if (ConditionFulfilled)
    {
      Dem_StoCoAllStates.isActive[stoCoArrayIndex] |= storageConditionBitmask;
    }
    else
    {
      Dem_StoCoAllStates.isActive[stoCoArrayIndex] &= (~storageConditionBitmask);
    }

    DEM_EXITLOCK_MON();

    return E_OK;

}

/* MR12 RULE 8.13 VIOLATION: The pointer will be modified based on the configuration. */
Std_ReturnType Dem_GetStorageCondition (uint8 StorageConditionID, boolean* ConditionFulfilled)
{
    Dem_StoCoList storageConditionBitmask = 0;
    uint8 bitpos = 0;
    uint8 stoCoArrayIndex = 0;

    /* Entry Condition Check */
    DEM_ENTRY_CONDITION_CHECK_NOT_NULL_PTR(ConditionFulfilled,DEM_DET_APIID_GETSTORAGECONDITION,E_NOT_OK);
    DEM_ENTRY_CONDITION_CHECK_DEM_STOCO_ID_VALID((StorageConditionID), (DEM_DET_APIID_GETSTORAGECONDITION),(E_NOT_OK));

    /*As the storage conditions can be configured 0-255, the bit position is calculated to mask it to a corresponding array element*/
    bitpos = (StorageConditionID%DEM_STORAGECONDITION_MAXBIT_LENGTH);
    /*From the storage condition ID requested, Index is calculated to update the state of corresponding array element*/
    stoCoArrayIndex = (StorageConditionID/DEM_STORAGECONDITION_MAXBIT_LENGTH);

    storageConditionBitmask = (1u<<bitpos);

    *ConditionFulfilled = (0u != (Dem_StoCoAllStates.isActive[stoCoArrayIndex] & storageConditionBitmask));

    return E_OK;
}

void Dem_StoCoMainFunction(void)
{
   uint8 stoCo=0;
   uint8 bitpos=0;
   uint8 stoCoArrayIndex=0;
   Dem_StoCoList stoco_mask=0;
   for (stoCo=0; stoCo<DEM_STORAGECONDITION_COUNT; stoCo++) /*Iterates for all the Storage Conditions*/
   {
       /*As the storage conditions can be configured 0-255, the bit position and array index is calculated to mask the StoCo with respective array element */
      stoCoArrayIndex = (stoCo/DEM_STORAGECONDITION_MAXBIT_LENGTH);
      bitpos = (stoCo%DEM_STORAGECONDITION_MAXBIT_LENGTH);
      stoco_mask = (1u <<bitpos);

      if (Dem_StoCoAllParams.replacementEvent[stoCo] != DEM_EVENTID_INVALID)
      {
         if( (stoco_mask & Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex]) != 0u )
         {

           (void) Dem_SetEventStatusWithMonitorData(Dem_StoCoAllParams.replacementEvent[stoCo], DEM_EVENT_STATUS_FAILED,
                  (Dem_MonitorDataType) (Dem_StoCoAllStates.eventId[stoCo]),Dem_StoCoAllStates.monitorData1[stoCo]);

            DEM_ENTERLOCK_MON();       /* DSM_D_212 */

            Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex] &=    (~stoco_mask);
            Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex] |= stoco_mask;

            DEM_EXITLOCK_MON();       /* DSM_D_212 */
         }

         if( (stoco_mask & Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex] & Dem_StoCoAllStates.isActive[stoCoArrayIndex]) != 0u )
         {
            (void)Dem_SetEventStatusWithMonitorData (Dem_StoCoAllParams.replacementEvent[stoCo], DEM_EVENT_STATUS_PASSED,0,0);

            DEM_ENTERLOCK_MON();       /* DSM_D_212 */

            Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex] &= (~stoco_mask);
            Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex] &=    (~stoco_mask);

            DEM_EXITLOCK_MON();       /* DSM_D_212 */
         }

         if (((stoco_mask & Dem_StoCoAllStates.isActive[stoCoArrayIndex]) != 0u) && (!Dem_EvtSt_GetTestCompleteTOC(Dem_StoCoAllParams.replacementEvent[stoCo])))
         {
            (void) Dem_SetEventStatusWithMonitorData(Dem_StoCoAllParams.replacementEvent[stoCo], DEM_EVENT_STATUS_PASSED, 0, 0);
         }
      }
      else
      {
         if( (stoco_mask & Dem_StoCoAllStates.isActive[stoCoArrayIndex]) != 0u )
         {
            DEM_ENTERLOCK_MON();       /* DSM_D_212 */
            {
               Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex] &= (~stoco_mask);
               Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex] &=    (~stoco_mask);
            }
            DEM_EXITLOCK_MON();       /* DSM_D_212 */
         }
      }
   }
}

void Dem_StoCoRecheckReplacementStorage(uint8 groupIndex)
{
    uint8 stoCoArrayIndex=0;
    DEM_ASSERT_ISLOCKED();

    for(stoCoArrayIndex=0; stoCoArrayIndex<DEM_STOCOBITMASK_ARRAYLENGTH; stoCoArrayIndex++)
    {
        /* if (any storagecondition is disabled) AND (none of the disabled stoco has stored or requested the replacement failure) */
        if (    ((Dem_StorageConditionGroups[groupIndex][stoCoArrayIndex] & (~Dem_StoCoAllStates.isActive[stoCoArrayIndex])) > 0u)
             && ((Dem_StorageConditionGroups[groupIndex][stoCoArrayIndex] & (~Dem_StoCoAllStates.isActive[stoCoArrayIndex]) & (Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex] | Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex])) == 0u)
           )
        {
            Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex] |= (Dem_StorageConditionGroups[groupIndex][stoCoArrayIndex] & (~Dem_StoCoAllStates.isActive[stoCoArrayIndex]));
        }
    }
}

void Dem_StoCoClearReplacementStoredFlag(void)
{
    uint8 stoCo=0;
    uint8 stoCoArrayIndex=0;
    uint8 bitpos=0;
    Dem_StoCoList stoco_mask = 0;

    for (stoCo=0; stoCo < DEM_STORAGECONDITION_COUNT; stoCo++)  /*Iterates for all the Storage Conditions*/
    {
        /*As the storage conditions can be configured 0-255, the bit position and array index is calculated to mask the StoCo with respective array element */
        stoCoArrayIndex = (stoCo/DEM_STORAGECONDITION_MAXBIT_LENGTH);
        bitpos = (stoCo%DEM_STORAGECONDITION_MAXBIT_LENGTH);
        stoco_mask = (1u <<bitpos);

        if ( ( (stoco_mask & Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex]) != 0u) &&
             ( !Dem_EvtSt_GetTestFailedTOC(Dem_StoCoAllParams.replacementEvent[stoCo] ) ) )
        {
            Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex] &= (~stoco_mask);
            Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex] &= (~stoco_mask);
        }
    }
}


/* may only be used within interrupt lock */
void Dem_StoCoSetHasFilteredEvent(uint8 groupIndex, Dem_MonitorDataType EventId, Dem_MonitorDataType monitorData1)
{


    Dem_StoCoList stoco_mask = 0;
    uint8 stoCo = 0;
    uint8 stoCoArrayIndex = 0;
    uint8 bitpos = 0;
    Dem_StoCoList replaceEv_TCTOC = 0;
    uint8 oldArrayIndex = 0;

    DEM_ASSERT_ISLOCKED ();

    for (stoCo=0; stoCo < DEM_STORAGECONDITION_COUNT; stoCo++)   /*Iterates for all the Storage Conditions*/
    {
        /*As the storage conditions can be configured 0-255, the bit position and the array index is calculated to mask the StoCo with respective array element */
        stoCoArrayIndex = (stoCo/DEM_STORAGECONDITION_MAXBIT_LENGTH);
        if(oldArrayIndex != stoCoArrayIndex)
        {
            oldArrayIndex = stoCoArrayIndex;
            replaceEv_TCTOC = 0;
        }
        bitpos = (stoCo%DEM_STORAGECONDITION_MAXBIT_LENGTH);
        stoco_mask = (1u << bitpos);

        if((stoco_mask & Dem_StorageConditionGroups[groupIndex][stoCoArrayIndex] & (~Dem_StoCoAllStates.isActive[stoCoArrayIndex]))!=0u)
        {
	        Dem_StoCoAllStates.eventId[stoCo] = ((Dem_EventIdType)EventId);
	        Dem_StoCoAllStates.monitorData1[stoCo]  = monitorData1;
        }
        if(!Dem_MonitorStatusByteIsTestNotCompleteTOC(Dem_Stoco_GetReplacementEventID(stoCo)))
        {
            replaceEv_TCTOC |= stoco_mask;
        }
        Dem_StoCoAllStates.isReplacementEventRequested[stoCoArrayIndex] |= (Dem_StorageConditionGroups[groupIndex][stoCoArrayIndex]
                                                                      &  (~Dem_StoCoAllStates.isActive[stoCoArrayIndex])
                                                                      &  ((~Dem_StoCoAllStates.isReplacementEventStored[stoCoArrayIndex])|(~replaceEv_TCTOC)) );
   }
}

#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"


