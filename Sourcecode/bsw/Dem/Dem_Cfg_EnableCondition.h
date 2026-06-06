
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENABLECONDITION_H
#define DEM_CFG_ENABLECONDITION_H


#include "Std_Types.h"


#define DEM_CFG_ENABLECONDITION_ON    STD_ON
#define DEM_CFG_ENABLECONDITION_OFF   STD_OFF

#define DEM_CFG_ENABLECONDITIONS_AVAILABLE DEM_CFG_ENABLECONDITION_OFF



#define DEM_ENABLECONDITION_COUNT         0u
#define DEM_ENCOBITMASK_ARRAYLENGTH        (0u+1u)
#define DEM_ENABLECONDITION_MAXBIT_LENGTH  32u   /**Since the Enable conditions are calculated with array bit mask, the max bit length is calculated to mask the EnCos to the respective array element. 
                                                    *The value is hardcoded to 32 because the array elements will be more than one and Dem_EnCoList is uint32, only when the Enable Conditions are configured more than 32. **/ 
#define DEM_ENCOGROUP_ARRAYLENGTH          (0u+1u)


/* define type depends on projectspecific number of enableconditions */
/* if no enable conditions are support use uint8 to allow empty inline functions */
#if (DEM_ENABLECONDITION_COUNT <= 8) \
    || (DEM_CFG_ENABLECONDITIONS_AVAILABLE == DEM_CFG_ENABLECONDITION_OFF)
typedef uint8 Dem_EnCoList;
#elif (DEM_ENABLECONDITION_COUNT <= 16)
typedef uint16 Dem_EnCoList;
#elif (DEM_ENABLECONDITION_COUNT <= 255)
typedef uint32 Dem_EnCoList;
#else
#error DEM currently only supports up to 255 EnableConditions
#endif


#if (DEM_CFG_ENABLECONDITIONS_AVAILABLE == DEM_CFG_ENABLECONDITION_ON)




/* The Enable Conditions in the Groups are calculated left shifting 1 by EncoID and added to respective array element  */
#define DEM_ENCOGROUP_NONE     {0u }



#define DEM_ENABLECONDITIONGROUPS        \
{ \
    DEM_ENCOGROUP_NONE \
};

/* The Index for each group */
#define DEM_ENCOGRPIDX_NONE        0u


/* The active Enable Conditions are calculated left shifting 1 by encoID and added(OR) to respective array element  */
#define DEM_CFG_ENCO_INITIALSTATE    {0u}

#endif

#endif

