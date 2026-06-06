

#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */



#include "Wdg.h"
/*
#if (!defined(WDG_AR_RELEASE_MAJOR_VERSION) || (WDG_AR_RELEASE_MAJOR_VERSION != 4))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(WDG_AR_RELEASE_MINOR_VERSION) || (WDG_AR_RELEASE_MINOR_VERSION != 2))
#error "AUTOSAR minor version undefined or mismatched"
#endif
*/


#include "WdgIf_Types.h"

/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */
#define WDGIF_AR_RELEASE_MAJOR_VERSION                               (4)
#define WDGIF_AR_RELEASE_MINOR_VERSION                               (5)
#define WDGIF_AR_RELEASE_REVISION_VERSION                            (0)


#define WDGIF_DEV_ERROR_DETECT                                       (STD_ON)
#define WDGIF_VERSION_INFO_API                                       (STD_OFF)
#define WDGIF_NUMBER_OF_DEVICES                                      (1)
#define WDGIF_VARIANT_PRE_COMPILE                                    (1)

/* Symbolic names for Watchdog instances */
#define WdgIfConf_WdgIfDevice_WdgIfDevice                            ((uint8) (0))

/*
 ***************************************************************************************************
 * Type definitions
 ***************************************************************************************************
 */
 
typedef WdgIf_Rb_ExtWdgdriver_tst WdgIf_ConfigType;






/*     According to WDGIF020 it is a case of single watchdog driver, to have
    efficient mechanisms to map the API calls to the appropriate watchdog
    driver without additional overhead, DeviceIndex is ignored */

#define WdgIf_SetMode(DeviceIndex, WdgMode)  Wdg_SetMode(WdgMode)
#define WdgIf_SetTriggerCondition(DeviceIndex, WdgTimeout)  Wdg_SetTriggerCondition(WdgTimeout)

/*
***************************************************************************************************
* External declaration
***************************************************************************************************
*/




#endif /*WDGIF_CFG_H*/
