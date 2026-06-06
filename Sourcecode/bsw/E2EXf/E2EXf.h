
#ifndef E2EXF_H
#define E2EXF_H

/*
**********************************************************************************************************************
* Includes
**********************************************************************************************************************
*/
/* TRACE[SWS_E2EXf_00047] */
#include "E2E.h"           /* E2E Profiles, public interfaces */
#include "E2EXf_Types.h"     /* AUTOSAR standard type definitions */
#include "E2EXf_Lcfg.h"     /* Link time configuration */


/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/

/* Version information parameters */
#define E2EXF_VENDOR_ID                   6U
#define E2EXF_MODULE_ID                   176U
#define E2EXF_SW_MAJOR_VERSION            1U
#define E2EXF_SW_MINOR_VERSION            0U
#define E2EXF_SW_PATCH_VERSION            0U
#define E2EXF_AR_RELEASE_MAJOR_VERSION    4U
#define E2EXF_AR_RELEASE_MINOR_VERSION    5U
#define E2EXF_AR_RELEASE_REVISION_VERSION 0U

/* Warning "unused parameter",
 * systematically produced as the abstract interfaces (if) have more parameters than the specific ones */
/*
**********************************************************************************************************************
* Type definitions
**********************************************************************************************************************
*/

/*
**********************************************************************************************************************
* Variables
**********************************************************************************************************************
*/

/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern void E2EXf_GetVersionInfo(Std_VersionInfoType * VersionInfo);
extern void E2EXf_Init(const E2EXf_ConfigType* config);
extern void E2EXf_DeInit(void);
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"


/* E2EXF_H */
#endif

