
#include "Dem_Cfg_EventId.h"
#include "Dem_Cfg_ComponentId.h"
#include "Dem_Cfg_DtcId.h"
#include "Dem_Mapping.h"
#include "Dem_Array.h"

#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"

/*** DTCID *******************************************************************/

DEM_MAP_EVENTID_DTCID
DEM_MAP_DTCID_EVENTID

/*** J1939DCMNode *******************************************************************/
#if(DEM_CFG_J1939DCM != DEM_CFG_J1939DCM_OFF)

/*  MR12 DIR 1.1 VIOLATION: Array is generated, always initialized and cannot be empty. */

/* MR12 RULE 1.2, 10.4 VIOLATION:
   1.2: Array is generated and initialized only if it is not empty (DTCs maps to eventId)
   10.4: Variable is defined the struct Dem_MapDtcIdToEventIdType as uint16, no coversion issue */
Dem_MAP_J1939MEMIDTODTCID
Dem_ALL_J1939DTCID

#endif

/*** COMPONENTID ******************************************************************/

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)

DEM_MAP_EVENTID_COMPONENTID
DEM_MAP_COMPONENTID_EVENTID
DEM_MAP_COMPONENTID_CHILDCOMPONENTID
DEM_CFG_COMPONENTTOCHILDCOMPONENTINDEX
#endif

/* Two dimensional array converted to one dimensional array using multiplication */
/* MR12 RULE 20.7 VIOLATION: Functions like MACROS do not need to be parenthesized.*/
DEM_ARRAY_DEFINE_CONST(Dem_DtcGroupIdMapToDtcIdType, Dem_DtcGroupIdMapToDtcId, DEM_DTCGROUPID_ARRAYLENGTH, DEM_MAP_DTCGROUPID_DTCID);
/* MR12 RULE 20.7 VIOLATION: Functions like MACROS do not need to be parenthesized.*/
DEM_ARRAY_DEFINE_CONST(uint8,Dem_MapEvMemToDTCGroupCount,DEM_CFG_EVMEM_DTCGROUPS_SIZE,DEM_DTCGROUPID_COUNT);
/* MR12 RULE 20.7 VIOLATION: Functions like MACROS do not need to be parenthesized.*/
DEM_ARRAY_DEFINE_CONST(uint8,Dem_MapEvMemToDTCGroupOffset,DEM_CFG_EVMEM_DTCGROUPS_SIZE,DEM_DTCGROUPID_EVMEM_OFFSET);


#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"
