
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_COMPONENTID_H
#define DEM_CFG_COMPONENTID_H

#include "Std_Types.h"

#define DEM_COMPONENTID_INVALID             0
#define DEM_COMPONENTID_COUNT               0u
#define DEM_COMPONENTID_ARRAYLENGTH         (DEM_COMPONENTID_COUNT+1u)

/* define type depends on projectspecific number of components */
#if (DEM_COMPONENTID_ARRAYLENGTH <= 255)
typedef uint8 Dem_ComponentIdType;
#else
typedef uint16 Dem_ComponentIdType;
#endif






#endif

