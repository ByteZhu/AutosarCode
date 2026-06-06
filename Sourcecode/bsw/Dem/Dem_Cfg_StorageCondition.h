
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_STORAGECONDITION_H
#define DEM_CFG_STORAGECONDITION_H


#include "Std_Types.h"


#define DEM_CFG_STORAGECONDITION_ON    STD_ON
#define DEM_CFG_STORAGECONDITION_OFF   STD_OFF

#define DEM_CFG_STORAGECONDITIONS_AVAILABLE DEM_CFG_STORAGECONDITION_OFF



#define DEM_STORAGECONDITION_COUNT          0u
#define DEM_STOCOBITMASK_ARRAYLENGTH        (0u+1u)
#define DEM_STORAGECONDITION_MAXBIT_LENGTH  32u   /**Since the storage conditions are calculated with array bit mask, the max bit length is calculated to mask the StoCos to the respective array element. 
                                                    *The value is hardcoded to 32, because the array elements will be more than one and Dem_StoCoList is uint32, only when the Storage Conditions are configured more than 32. **/
#define DEM_STOCOGROUP_ARRAYLENGTH          (0u+1u)     /* As the first element of the array 'Dem_StorageConditionGroups' is defined as 'none', the total number of groups are calculated and, one is added*/


/* define type depends on projectspecific number of storageconditions */
/* if no storage conditions are support use uint8 to allow empty inline functions */
#if (DEM_STORAGECONDITION_COUNT <= 8) \
	|| (DEM_CFG_STORAGECONDITIONS_AVAILABLE == DEM_CFG_STORAGECONDITION_OFF)
typedef uint8 Dem_StoCoList;
#elif (DEM_STORAGECONDITION_COUNT <= 16)
typedef uint16 Dem_StoCoList;
#elif (DEM_STORAGECONDITION_COUNT <= 255)
typedef uint32 Dem_StoCoList;
#else
#error DEM currently only supports up to 255 StorageConditions
#endif

#if (DEM_CFG_STORAGECONDITIONS_AVAILABLE == DEM_CFG_STORAGECONDITION_ON)





/* Each group is defined with list of storage conditions mapped to it */
#define DEM_STOCOGROUP_NONE                            {0u }



#define DEM_STORAGECONDITIONGROUPS        \
{ \
    DEM_STOCOGROUP_NONE \
};


/* Storage Condition group index */
#define DEM_STOCOGRPIDX_NONE                                0u




/* Initial state of all the Storage Conditions */
#define DEM_CFG_STOCO_INITIALSTATE    {0u}


/* definition of replacement failures */
#define DEM_CFG_STOCO_PARAMS \
{ \
   { \
   } \
}


#endif

#endif

