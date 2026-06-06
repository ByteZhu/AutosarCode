/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef SECOC_H
#define SECOC_H

/**
 * \file
 * \brief TRACE[SWS_SecOC_00001]: module header of component SecOC
 */

/*
**********************************************************************************************************************
* Includes
**********************************************************************************************************************
*/
#include "SecOC_Cfg.h"         /* Configuration header file of SecOC */
#include "SecOC_PduRIF.h"      /* AUTOSAR interface of SecOC to PduR */
#include "Det.h"                /* module header of default error tracer */


/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"

extern void SecOC_MainFunctionTx(void);

extern void SecOC_MainFunctionRx(void);

extern void SecOC_Init(const SecOC_ConfigType *config);
extern void SecOC_DeInit(void);
extern void SecOC_GetVersionInfo(Std_VersionInfoType * versioninfo);


#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"


/* SECOC_H */
#endif
