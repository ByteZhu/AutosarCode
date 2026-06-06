


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Com_Prv.h"
#include "Com_PBcfg_Common.h"
#include "Com_PBcfg_Variant.h"
#include "PduR_Com.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
/* #defines for matching Com module configurations */

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
const Com_ConfigType Com_Config =
{
    /* MR12 DIR 1.1 VIOLATION: pointer structure types are not exported via com public header, hence it is stored as 
    void pointer and be dereferenced with correct internal type in com initialization. */
    NULL_PTR,
    NULL_PTR,

#ifdef COM_PRV_ENABLECONFIGINTERFACES
    &Com_GlobalConfig_cst,
#endif
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"




