/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

#ifndef SECOC_PRV_PBCFG_H
#define SECOC_PRV_PBCFG_H

/**
 * \brief Private Header file for post build configuration parameters of the SecOC module.
 * \addtogroup SecOC
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Platform_Types.h"
#include "PduR.h"
#include "SecOC_Prv.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/
#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
extern const uint16* SecOC_Prv_RxDataId_Common_pcu16; // Pre compile
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
extern const uint16* SecOC_Prv_RxFreshValId_Common_pcu16; // Pre compile
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
extern uint8* SecOC_Prv_RxFreshValLen_Common_pu8; // Pre compile
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
extern const uint8* SecOC_Prv_RxFreshValTruncLen_Common_pcu8; // Pre compile
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"
extern const uint16* SecOC_Prv_RxAuthTruncLen_Common_pcu16; // Pre compile
#define SECOC_STOP_SEC_VAR_INIT_32
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
extern const SecOC_Prv_VerifyPropType_en* SecOC_Prv_RxPropMode_Common_pcen; // Pre compile
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
extern const SecOC_Prv_CryptIf_en* SecOC_Prv_RxVerifyCryIf_Common_pcen; // Pre compile
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"




#define SECOC_START_SEC_CONST_32
#include "SecOC_MemMap.h"
extern const uint16 * const SecOC_Prv_Rx_Lookup_ValueId_acpcu16[];
#define SECOC_STOP_SEC_CONST_32
#include "SecOC_MemMap.h"
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/


#endif /* SECOC_PRV_PBCFG_H */

