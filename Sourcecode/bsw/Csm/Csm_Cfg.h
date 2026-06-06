/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CSM_CFG_H
#define CSM_CFG_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Crypto_GeneralTypes.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

// API availability

// Hash Interface
#define CSM_CFG_HASH_API_AVAIL                        (STD_OFF)
// MAC Interface
#define CSM_CFG_MACGENERATE_API_AVAIL                 (STD_ON)
#define CSM_CFG_MACVERIFY_API_AVAIL                   (STD_ON)
// Cipher Interface
#define CSM_CFG_ENCRYPT_API_AVAIL                     (STD_OFF)
#define CSM_CFG_DECRYPT_API_AVAIL                     (STD_OFF)
// Signature Interface
#define CSM_CFG_SIGNATUREGENERATE_API_AVAIL           (STD_OFF)
#define CSM_CFG_SIGNATUREVERIFY_API_AVAIL             (STD_OFF)
// Keyexchange calc pub val interface
#define CSM_CFG_KEYEXCHANGE_CALCPUBVAL_API_AVAIL      (STD_OFF)
// Keyexchange calc secret interface
#define CSM_CFG_KEYEXCHANGE_CALCSECRET_API_AVAIL      (STD_OFF)
// Key Derive interface
#define CSM_CFG_KEYDERIVE_API_AVAIL                   (STD_OFF)
// Key Element Get
#define CSM_CFG_KEYELEMENTGET_API_AVAIL               (STD_OFF)
// Key Element Set
#define CSM_CFG_KEYELEMENTSET_API_AVAIL               (STD_OFF)
// Keygenerate interface
#define CSM_CFG_KEYGENERATE_API_AVAIL                 (STD_OFF)
// AEAD Interface
#define CSM_CFG_AEAD_ENCRYPT_API_AVAIL                (STD_ON)
#define CSM_CFG_AEAD_DECRYPT_API_AVAIL                (STD_ON)
// Random Interface
#define CSM_CFG_RANDOM_GENERATE_API_AVAIL             (STD_OFF)
// Random seed interface
#define CSM_CFG_RANDOM_SEED_API_AVAIL                 (STD_OFF)
// Key Set Valid interface
#define CSM_CFG_KEYSETVALID_API_AVAIL                 (STD_OFF)
// KeyManagement Interface
#define CSM_CFG_KEYMANAGEMENT_API_AVAIL               (STD_ON)
// SHE key management interfaces
#define CSM_CFG_SHE_GETID_API_AVAIL                   (STD_OFF)
#define CSM_CFG_SHE_LOADKEY_API_AVAIL                 (STD_OFF)
#define CSM_CFG_SHE_LOADKEYSLOT_API_AVAIL             (STD_OFF)
#define CSM_CFG_SHE_LOADPLAINKEY_API_AVAIL            (STD_OFF)
#define CSM_CFG_SHE_EXPORTRAMKEY_API_AVAIL            (STD_OFF)

#define CSM_CFG_JOB_COUNT               (11U)
#define CSM_CFG_ASYNC_JOB_COUNT         (11U)
#define CSM_CFG_KEY_COUNT               (3U)
#define CSM_CFG_PRIMITIVE_COUNT         (6U)
#define CSM_CFG_JOB_REDIRECTION_COUNT   (0U)
#define CSM_CFG_QUEUE_COUNT             (4U)
#define CSM_CFG_CALLBACK_COUNT          (11U)
#define CSM_CFG_RTE_CALLBACK_COUNT      (0U)

#define CSM_CFG_QUEUEING_AVAIL          (STD_ON)

#define CSM_CFG_PARTITION_COUNT         (1U)
#define CSM_CFG_FIRST_NONLEGACY_PARTITION_INDEX        (1U)

#define CSM_CFG_MAINFUNCTION

//Defines of AUTOSAR Symbolic Name values
//TRACE[SWS_BSW_00200]TRACE[TPS_ECUC_02108]
#define CsmConf_CsmJob_CsmJob_GCM_ENC   (0U)
#define CsmConf_CsmJob_CsmJob_GCM_DEC   (1U)
#define CsmConf_CsmJob_CsmJob_Gen_SecOC   (2U)
#define CsmConf_CsmJob_CsmJob_Ver_SecOC   (3U)
#define CsmConf_CsmJob_CsmJob_Gen_SecOC_1   (4U)
#define CsmConf_CsmJob_CsmJob_Ver_SecOC_1   (5U)
#define CsmConf_CsmJob_CsmJob_SecOCTxPduProcessing_TxCallback   (6U)
#define CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback   (7U)
#define CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback   (8U)
#define CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback   (9U)
#define CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback   (10U)
#define CsmConf_CsmKey_CsmKey_DevKey   (0U)
#define CsmConf_CsmKey_CsmKey_SecOC_CMAC_Ele   (1U)
#define CsmConf_CsmKey_CsmKey_SecOC_CMAC_Ele1   (2U)

//Defines of Rb specific Symbolic Name values
#define CsmConf_CsmRbQueue_CsmQueue_GCM_DEC   (0U)
#define CsmConf_CsmRbQueue_CsmQueue_GCM_ENC   (1U)
#define CsmConf_CsmRbQueue_CsmQueue_Gen   (2U)
#define CsmConf_CsmRbQueue_CsmQueue_Ver   (3U)

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Exports
 **********************************************************************************************************************
*/

#define CSM_START_SEC_CONST_32
#include "Csm_MemMap.h"
// key mappings
extern const uint32 Csm_Prv_KeyIdMapping_acu32[CSM_CFG_KEY_COUNT];

// job mappings
extern const uint32 Csm_Prv_JobQueueIdMapping_acu32[CSM_CFG_JOB_COUNT];

// queue mappings
extern const uint32 Csm_Prv_QueueChanneldIdMapping_acu32[CSM_CFG_QUEUE_COUNT];

#define CSM_STOP_SEC_CONST_32
#include "Csm_MemMap.h"

#define CSM_START_SEC_VAR_CLEARED_32
#include "Csm_MemMap.h"
#define CSM_STOP_SEC_VAR_CLEARED_32
#include "Csm_MemMap.h"

#endif /* CSM_CFG_H */

