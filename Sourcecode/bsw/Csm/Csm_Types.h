/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CSM_TYPES_H
#define CSM_TYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
//TRACE[SWS_Csm_00068] Standard types included through common types header
#include "Crypto_GeneralTypes.h"
#include "Rte_Csm_Type.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/* Warning "unused parameter",
 * systematically produced as the abstract interfaces (if) have more parameters than the specific ones */
#define CSM_PARAM_UNUSED(param)          (void)(param)

/* Invalid Id value */
#define CSM_INVALID_ID                  0xFFFFFFFFU

/* Autosar Version definition */
/* Publish module IDs */
#define CSM_VENDOR_ID                   (6)
#define CSM_MODULE_ID                   (110)
#define CSM_INSTANCE_ID                 (0)
/* Publish Autosar versions */
#define CSM_AR_RELEASE_MAJOR_VERSION    (4)
#define CSM_AR_RELEASE_MINOR_VERSION    (5)
#define CSM_AR_RELEASE_REVISION_VERSION (0)
/* Publish sofware version numbers */
#define CSM_SW_MAJOR_VERSION            (2U)
#define CSM_SW_MINOR_VERSION            (0U)
#define CSM_SW_PATCH_VERSION            (0U)

/* Service IDs for DET interface */
#define CSM_SERVICE_ID_INIT                          0x00U
#define CSM_SERVICE_ID_GET_VERSION_INFO              0x3BU
#define CSM_SERVICE_ID_HASH                          0x5DU
#define CSM_SERVICE_ID_MAC_GENERATE                  0x60U
#define CSM_SERVICE_ID_MAC_VERIFY                    0x61U
#define CSM_SERVICE_ID_ENCRYPT                       0x5EU
#define CSM_SERVICE_ID_DECRYPT                       0x5FU
#define CSM_SERVICE_ID_AEAD_ENCRYPT                  0x62U
#define CSM_SERVICE_ID_AEAD_DECRYPT                  0x63U
#define CSM_SERVICE_ID_SIGNATURE_GENERATE            0x76U
#define CSM_SERVICE_ID_SIGNATURE_VERIFY              0x64U
#define CSM_SERVICE_ID_CANCEL_JOB                    0x6FU
#define CSM_SERVICE_ID_RANDOMGENERATE                0x72U
#define CSM_SERVICE_ID_KEY_ELEMENT_SET               0x78U
#define CSM_SERVICE_ID_KEY_SET_VALID                 0x67U
#define CSM_SERVICE_ID_JOB_KEY_SET_VALID             0x7AU
#define CSM_SERVICE_ID_KEY_ELEMENT_GET               0x68U
#define CSM_SERVICE_ID_KEY_ELEMENT_COPY              0x71U
#define CSM_SERVICE_ID_KEY_ELEMENT_COPY_PARTIAL      0x79U
#define CSM_SERVICE_ID_KEY_COPY                      0x73U
#define CSM_SERVICE_ID_RANDOM_SEED                   0x69U
#define CSM_SERVICE_ID_JOB_RANDOM_SEED               0x7BU
#define CSM_SERVICE_ID_KEY_GENERATE                  0x6AU
#define CSM_SERVICE_ID_JOB_KEY_GENERATE              0x7CU
#define CSM_SERVICE_ID_KEY_DERIVE                    0x6BU
#define CSM_SERVICE_ID_JOB_KEY_DERIVE                0x7DU
#define CSM_SERVICE_ID_KEY_EXCHANGE_CALC_PUB_VAL     0x6CU
#define CSM_SERVICE_ID_KEY_EXCHANGE_CALC_SECRET      0x6DU
#define CSM_SERVICE_ID_JOB_KEY_EXCHANGE_CALC_PUB_VAL 0x7EU
#define CSM_SERVICE_ID_JOB_KEY_EXCHANGE_CALC_SECRET  0x7FU
#define CSM_SERVICE_ID_CERTIFICATE_PARSE             0x6EU
#define CSM_SERVICE_ID_CERTIFICATE_VERIFY            0x74U
#define CSM_SERVICE_ID_CALLBACK_NOTIFICATION         0x70U
#define CSM_SERVICE_ID_KEY_GET_STATUS                0x83U
#define CSM_SERVICE_ID_PROCESS_JOB_EXTERNAL_CALLOUT  0x85U
#define CSM_SERVICE_ID_CANCEL_JOB_EXTERNAL_CALLOUT   0x86U
#define CSM_SERVICE_ID_RANDOM_SEED_EXTERNAL_CALLOUT  0x87U
#define CSM_SERVICE_ID_MAINFUNCTION                  0x88U
#define CSM_SERVICE_ID_JOB_DISPATCH                  0x89U
#define CSM_SERVICE_ID_JOB_KEY_ELEMENT_GET           0x8AU
#define CSM_SERVICE_ID_JOB_KEY_ELEMENT_SET           0x8BU
#define CSM_SERVICE_ID_SHE_GET_ID                    0xFEU
#define CSM_SERVICE_ID_SHE_LOAD_KEY                  0xFDU
#define CSM_SERVICE_ID_SHE_LOAD_KEY_SLOT             0xFCU
#define CSM_SERVICE_ID_SHE_LOAD_PLAIN_KEY            0xFBU
#define CSM_SERVICE_ID_SHE_EXPORT_RAM_KEY            0xFAU


/* Runtime Errors */
//TRACE[SWS_Csm_01089]
#define CSM_E_QUEUE_FULL          0x01U  /* Queue overrun */

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/* Configuration data structure of Csm module */
//TRACE[SWS_Csm_01085]
typedef struct
{
   uint8 dummy_u8;
} Csm_ConfigType;

#endif /* CSM_TYPES_H */


