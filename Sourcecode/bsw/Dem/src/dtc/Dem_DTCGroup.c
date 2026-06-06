
#include "Dem_Dcm_Internal.h"
#include "Dem_DTCGroup.h"

#include "Dem_DTCs.h"

#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
/* MR12 RULE 20.7 VIOLATION: Functions like MACROS do not need to be parenthesized.*/
DEM_ARRAY_DEFINE_CONST(Dem_DtcGroupParam, Dem_AllDTCGroupsParam,DEM_DTCGROUPID_ARRAYLENGTH, DEM_CFG_DTCGROUPPARAMS);
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"

/*-- DTC GROUP CODE-------------------------------------------------------------*/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
Dem_DTCGroupIdType Dem_DtcGroupIdFromDtcGroupCode (Dem_DTCGroupType dtcGrpCode, Dem_DTCOriginType DTCOrigin)
{
   Dem_DtcGroupIdIterator dtcGroupId;
   uint16_least memId;

   memId = Dem_EvMemGetMemIdForDTCOrigin(DTCOrigin);
   if(memId < DEM_CFG_EVMEM_DTCGROUPS_SIZE)
   {
       for (Dem_DtcGroupIdIteratorNew(&dtcGroupId);
            Dem_DtcGroupIdIteratorIsValid(&dtcGroupId, memId);
            Dem_DtcGroupIdIteratorNext(&dtcGroupId))
       {
          if (Dem_DtcGroupGetCode(Dem_DtcGroupIdIteratorCurrent(&dtcGroupId), memId) == dtcGrpCode)
          {
             return Dem_DtcGroupIdIteratorCurrent(&dtcGroupId);
          }
       }
   }

   return DEM_DTCGROUPID_INVALID;
}

void Dem_DtcsClearDtcInGroup(uint8 GroupId, Dem_DTCOriginType DTCOrigin, uint16_least memId, Dem_ClientClearMachineType *Dem_ClientClearMachinePtr)
{
    Dem_DtcIdType dtcId;

    /* Check whether the Clear is requested newly */
    if (Dem_ClientClearMachinePtr->IsNewClearRequest)
    {
        Dem_DtcIdListIteratorNewFromDtcGroup(&(Dem_ClientClearMachinePtr->DtcIt), GroupId, memId);
    }

    while (Dem_DtcIdListIteratorIsValid(&(Dem_ClientClearMachinePtr->DtcIt)))
    {
        dtcId = Dem_DtcIdListIteratorCurrent(&(Dem_ClientClearMachinePtr->DtcIt));
        Dem_ClearSingleDTC(dtcId, DTCOrigin, Dem_ClientClearMachinePtr);
        /* Check whether the number of events processed reached the Max limit */
        if (Dem_ClientClearMachinePtr->IsClearInterrupted)
        {
            return;
        }
        Dem_DtcIdListIteratorNext(&(Dem_ClientClearMachinePtr->DtcIt));
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
