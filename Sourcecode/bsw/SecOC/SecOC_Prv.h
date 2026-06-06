/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

#ifndef SECOC_PRV_H
#define SECOC_PRV_H

/**
 * \brief Private Header file for the SecOC module.
 * \addtogroup SecOC
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "PduR.h"        /* interface to Pdu router, common part */
#include "PduR_SecOC.h"  /* interface to Pdu router, SecOC part */
#include "Rte_Type.h"    /* RTE types */
#include "Os.h" /* interface to OS for multicore */
#include "SecOC_Prv_CryptIF.h"  /* private abstract cryptographic interface of SecOC */
#include "SecOC_Prv_FreshIF.h"  /* private abstract freshness interface of SecOC */
#include "SecOC_Cfg_SchM.h"     /* lock interface of SecOC */

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
#define SECOC_NUMBER_AUTH_PDU 1U
#define SECOC_MAX_AUTHENTIC_PDU_ID 0U
#define SECOC_MAX_TX_PDU_ID 0U
#define SECOC_NUMBER_TX_PDU_ID 1U
#define SECOC_MAX_RX_PDU_ID 3U
#define SECOC_NUMBER_RX_PDU 4U
#define SECOC_MAX_RX_SECURED_PDU_ID 3U
#define SECOC_MAX_TX_SECURED_PDU_ID 0U
#define SECOC_MAX_TX_CRYPTOGRAPHIC_PDU_ID 0U
#define SECOC_MAX_RX_CRYPTOGRAPHIC_PDU_ID 0U
#define SECOC_NUMBER_TX_COLLECTION_PDU 0U
#define SECOC_NUMBER_RX_COLLECTION_PDU 0U

#define SECOC_MAX_VERIFY_STATUS_OVERRIDE 4U

/* Default (legacy) Tx partition is always generated first */
#define SECOC_DEFAULT_TX_PDU_PARTITION_INDEX    (0u)
/* Default (legacy) Rx partition is always generated first */
#define SECOC_DEFAULT_RX_PDU_PARTITION_INDEX    (0u)
#define SECOC_MAX_TX_PDU_PARTITION_CONFIG 1U
#define SECOC_MAX_RX_PDU_PARTITION_CONFIG 1U

/**
  * Defines for SecOC_VerifyStatusOverride
  * ValueID is handled as DataId: false
  */
#define SECOC_OVERRIDE_TO_PASS 43U

/* Define of block length of CMAC AES128v21 */
#define SECOC_CMAC_AES128v21_BLOCK_LEN 16u

/* Define the offset for the authentic payload in the
 * DataToAuthenticator to be the size of the data Id
 */
#define SECOC_PRV_DATAID_BIT_LENGTH  16u
#define SECOC_PRV_PAYLOAD_OFFSET SECOC_PRV_DATAID_BIT_LENGTH

#define SECOC_PRV_NO_CSM_JOB_ID 0U

/**
 * Defines for mapping PDU name to config index in the config buffer
 */
#define SECOC_PRV_SECOCTXPDUPROCESSING_TX_CONFIG_INDEX 0u

#define SECOC_PRV_IP_CSCBCMCORE_SECCANFRAME01_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX 0u
#define SECOC_PRV_IP_CSCBCMCORE_SECCANFRAME02_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX 1u
#define SECOC_PRV_IP_CSCBCMCORE_SECCANFRAME03_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX 2u
#define SECOC_PRV_IP_CSCBCMCORE_SPECIALSECFRAME01_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX 3u


/* PDU types */
#define SECOC_COLLECTION_CRYPTOGRAPHIC_PDU   0X01U
#define SECOC_COLLECTION_AUTHENTIC_PDU       0X02U
#define SECOC_SECURED_PDU                    0X03U

#define SECOC_PRV_NO_PENDING_CALLBACK 0xFFu
#define SECOC_PRV_NO_PENDING_INDICATION 0xFFu

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/**
 * Type for definition of verification status propagation mode
 */
typedef enum
{
    SECOC_BOTH_E         = 0x00U,   /* Propagate each verification state */
    SECOC_FAILURE_ONLY_E = 0x01U,   /* Propagate unsuccessful verification state */
    SECOC_NONE_E         = 0x02U    /* No propagation of verification state */
} SecOC_Prv_VerifyPropType_en;

typedef struct
{
    const SecOC_Prv_VerifyPropType_en** value_pace;  /* Pointer to PBS variant value */
    const PduIdType idx_cuo;                         /* Index of Pdu according to location in PBS variant */
}SecOC_Prv_IdxEnumPropType_st;


typedef enum
{
    SECOC_CRYPTIF_CSM_RBA_CRYPTOCCL = 0x01u,
    SECOC_CRYPTIF_CSM_RBA_CRYPTOHSM = 0x02u,
    
    SECOC_CRYPTIF_NONE = 0x03u,
    SECOC_CRYPTIF_CSM_CRYPTO = 0x04u
    
} SecOC_Prv_CryptIf_en;

typedef struct
{
    const SecOC_Prv_CryptIf_en** value_pace;     /* Pointer to PBS variant value */
    const PduIdType idx_cuo;                     /* Index of Pdu according to location in PBS variant */
}SecOC_Prv_IdxEnumCryIfType_st;

typedef enum
{
    SECOC_RX_QUEUE_E           = 0x0U, /* Subsequent received message will be queued */
    SECOC_RX_REJECT_E          = 0x1U, /* Subsequent received message will be discarded */
    SECOC_RX_REPLACE_E         = 0x2U  /* Subsequent received message will replace the currently processed message*/
} SecOC_Prv_RxOvrflwStrat_en;

typedef uint8 SecOC_Prv_RxSecuredPduState_tu8;
typedef uint8 SecOC_Prv_RxAuthenticPduState_tu8;

/**
 * Definition of states for Rx communication with the scheduled main task
 */
/* secured Rx PDU state, type SecOC_Prv_RxSecuredPduState_tu8 */
#define SECOC_RX_STATE_SECURED_IDLE_E          0x10U /* Secured RxPDU is ready for reception */
#define SECOC_RX_STATE_RECEIVING_E             0x11U /* Secured RxPDU is receiving data through transport protocol */
#define SECOC_RX_STATE_RECEIVED_E              0x12U /* Secured RxPDU was received successfully */
/* authentic Rx PDU state, type SecOC_Prv_RxAuthenticPduState_tu8 */
#define SECOC_RX_STATE_AUTHENTIC_IDLE_E        0x20U /* Authentic RxPDU is waiting for new Secured RxPDU */
#define SECOC_RX_STATE_VERIFY_E                0x21U /* Prepare and start verification of RxPDU */
#define SECOC_RX_STATE_MAC_VERIFY_FINISHED_E   0x22U /* CSM has finished verifying the MAC */
#define SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E 0x23U /* Waiting for the CSM to finish verification */
#define SECOC_RX_STATE_WAIT_ABORT_VERIFY_E     0x24U /* Abort verification */

typedef uint8 SecOC_Prv_TxAuthenticPduState_tu8;
typedef uint8 SecOC_Prv_TxSecuredPduState_tu8;

/**
 * Definition of states for Tx communication with the scheduled main task
 */
/* authentic Tx PDU state, type SecOC_Prv_TxAuthenticPduState_tu8 */
#define SECOC_TX_STATE_AUTHENTIC_IDLE_E        0x10U /* TxPdu Context is currently not in use. */
#define SECOC_TX_STATE_FETCH_TP_DATA_E         0x11U /* Authentic data still to be fetched from upper layer */
#define SECOC_TX_STATE_SENDING_E               0x12U /* Authentic I-PDU is successfully received */
/* secured Tx PDU state, type SecOC_Prv_TxSecuredPduState_tu8 */
#define SECOC_TX_STATE_SECURED_IDLE_E          0x20U /* TxPdu Context is currently not in use. */
#define SECOC_TX_STATE_GENERATE_E              0x21U /* Start authentication of I-PDU */
#define SECOC_TX_STATE_SENT_E                  0x22U /* I-PDU is successfully forwarded to pdu router */
#define SECOC_TX_STATE_CANCEL_PENDING_E        0x23U /* TxPDU transmission was canceled */
#define SECOC_TX_STATE_WAIT_FOR_CSM_CALLBACK_E 0x24U /* Authentication of I-PDU is started */

/**
 * Definition of the configuration structure for Rx PDU
 */
typedef struct
{
    boolean authDataFresh_b : 1;  /* Usage of autentic PDU data freshness */
    boolean pduColl_b       : 1;  /* Pdu is a pduCollection */
    boolean dynPdu_b        : 1;  /* secured/authentic pdu part is dynamic */
    boolean dynCryptoPdu_b  : 1;  /* crypto Pdu part is dynamic */
    boolean bitHeader_b     : 1;  /* Secured Header value is represented in bits */
    boolean syncMod_b       : 1;  /* CSM Job is synchronous */
    boolean pduTpType_b     : 1;  /* Pdu is handeled via transport protocol */
}SecOC_Prv_packedRxCfg_tstb;

/* MR12 RULE 2.4 VIOLATION: struct is used for typedef in SecOC_Types.h */
struct SecOC_Prv_RxPduConfig_st
{
    uint8 *pduBufferIn_pu8;                         /*< Buffer for the secured or collection authentic PDU of this RxPduProcessing context */
    uint8 *cryptographicPduBufferIn_pu8;            /*< Buffer for the cryptographic PDU of this RxPduProcessing context */
    uint8 *authenticPduBufferOut_pu8;               /*< Buffer for the authentic PDU of this TxPduProcessing context */
    uint8 *authenticator_pu8;                       /*< Buffer for the authenticator from the secured PDU */
    uint8 *authDataBuffer_pu8;                      /*< Buffer for the data that is given to the CSM for verification */
    Crypto_VerifyResultType *macVerifyResult_pen;   /*< Pointer to the MAC verification result from the CSM */
    PduIdType *sameBufferRefInUsePduId_puo;         /*< Pointer to identifer of PDU which PDU uses the shared buffer */
    boolean *isSameBufferRefInUse_pb;               /*< Pointer to a flag that indicates if the buffers are shared
                                                         with some other context */
    uint32 jobId_u32;                               /*< Id of the CSM job */
    SecOC_Prv_IdxVar32_tst securedRxPduOffset_cst;  /*< Start position of secured area within the PDU payload (in bytes) */
    SecOC_Prv_IdxVar32_tst securedRxPduLength_cst;  /*< Length of the secured area (in bytes) */
    PduLengthType pduLength_uo;                     /*< Length of the secured PDU or the collection authentic PDU */
    PduLengthType cryptographicPduLength_uo;        /*< Length of the cryptographic PDU */
    PduLengthType authenticPduLength_uo;            /*< Length of the authentic PDU */
    PduIdType pduRAuthenticPduId_uo;                /*< PduId of the authentic PDU from the PduR */
    uint16 authenticationBuildAttempts_u16;         /*< Maximum number of failed authentication build attempts before failing to send PDU */
    uint16 authenticationVerifyAttempts_u16;        /*< Maximum number of failed verification attempts before failing to send PDU */
    SecOC_Prv_IdxVar16_tst authInfoTruncLen_cst;    /*< Length of the transmitted authenticator in bits */
    SecOC_Prv_IdxVar16_tst dataId_cst;              /*< Data Id structure of the PDU  */
    SecOC_Prv_IdxVar16_tst freshnessValueId_cst;    /*< Freshness Value Id of the PDU  */
    uint16 authDataFreshnessLength_u16;             /*< Length in bits of the authentic data freshness value  */
    uint16 authDataFreshnessStartPosition_u16;      /*< Start position in bits of authentic data freshness value */
    uint16 messageLinkPos_u16;                      /*< Position of message linker inside the payload in bits */
    uint16 messageLinkLength_u16;                   /*< Length of message linker inside the payload in bits */
    SecOC_Prv_packedRxCfg_tstb packedBits_stb;      /*< packed bits struct */
    SecOC_Prv_IdxVar8_tst freshValTruncLen_cst;     /*< Length of the truncated freshness value in bits */
    uint8  metaDataLen_u8;                          /*< numbers of MetaData to be copied */
    uint8  securedHeaderLength_u8;                  /*< Length of secured I-PDU header in bytes  */
 
    boolean useRxPduSecuredArea_b;                  /*< Flag that indicates if the SecOCRxPduSecuredArea is used */
    SecOC_Prv_IdxEnumCryIfType_st cryptIf_cst;      /*< Enum that indicates the configured crypt interface (CCL, HSM, None) */
    SecOC_Prv_IdxEnumPropType_st verifyPropMode_cst;/*< VerificationStatusPropagationMode for this PDU */
    SecOC_Prv_RxOvrflwStrat_en rxOvrflwStrat_e;     /*< QUEUE, REJECT, REPLACE */
};

/* MR12 RULE 2.4 VIOLATION: struct is used for typedef in SecOC_Types.h */
struct SecOC_Prv_RxSecuredPduContext_st
{
    const SecOC_Prv_RxPduConfig_tst *pduConfig_pst;     /*< Reference to the PDU config for this PDU context */
    uint8* metaData_pu8;                                /*< MetaData pointer */
    PduLengthType actualAuthenticPduLengthInBits_uo;    /*< Actual length of the authentic PDU */
    PduLengthType bufferPosition_uo;                    /*< Position inside the pduBufferIn_pu8 for TP PDUs */
    PduLengthType cryptographicPduBufferPosition_uo;    /*< Position inside the cryptographicPduBufferIn_pu8 for TP PDUs */
    PduLengthType upTpBufSize_uo;
    volatile SecOC_Prv_RxSecuredPduState_tu8 status_u8;                 /*< State of the PDU (idle, receiving, ...) */
    volatile SecOC_Prv_RxSecuredPduState_tu8 cryptographicPduStatus_u8; /*< State of the PDU (idle, receiving, ...) */
    boolean received_CryptographicPdu_b;                /*< Flag indicates if cryptogaphic PDU received */
    boolean received_AuthenticPdu_b;                    /*< Flag inidicates if collection Authentic PDU received */
    boolean isLocked_b;                                 /*< Flag that locks this context for multi-core protection */
};

/* MR12 RULE 2.4 VIOLATION: struct is used for typedef in SecOC_Types.h */
struct SecOC_Prv_RxAuthenticPduContext_st
{
    const SecOC_Prv_RxPduConfig_tst *pduConfig_pst;     /*< Reference to the PDU config for this PDU context */
    uint8* metaData_pu8;                                /*< MetaData pointer*/
    uint32 authDataBufferLength_u32;                    /*< Length of the authDataBuffer_pu8 buffer in bytes */
    uint32 pduIndex_u32;                                /*< Index to the internal pdu structures, stored during allocating context */
    uint16 verifyAttempts_u16;                          /*< Number of failed verification attempts since the last reception */
    uint16 authAttempts_u16;                            /*< Number of failed authentication build attempts since the
                                                            last reception */
    PduLengthType actualAuthenticPduLengthInBits_uo;    /*< Actual length of the authentic PDU */
    PduLengthType upTpBufSize_uo;
    uint8 freshnessTruncValue_au8[SECOC_MAX_FRESHNESS_SIZE]; /*< Buffer for the truncated freshness value */
    uint8 authDataFreshnessValue_au8[SECOC_MAX_FRESHNESS_SIZE]; /*< Buffer for the authentic freshness value */
    SecOC_Prv_ctxIdxVar8_tst freshnessValueLength_st;   /*< Length of the complete freshness value in bits */
    SecOC_VerificationResultType verificationStatus_u8; /*< Verification result type */
    volatile SecOC_Prv_RxAuthenticPduState_tu8 status_u8; /*< State of the PDU (idle, receiving, ...) */
    boolean isLocked_b;                                 /*< Flag that locks this context for multi-core protection */
};
/**
 * Definition of the configuration structure for Tx PDU
 */
typedef struct
{
    boolean bitHeader_b  : 1;  /* Secured Header value is represented in bits */
    boolean clrTxBuf_b   : 1;  /* Buffers are cleared after transmit to PduR */
    boolean txConfirm_b  : 1;  /* Function SecOC_SPduTxConfirmation shall be called for PDU */
    boolean truncFresh_b : 1;  /* Freshness function provides the truncated freshness */
    boolean pduColl_b    : 1;  /* Pdu is a pduCollection */
    boolean syncMod_b    : 1;  /* CSM Job is synchronous */
    boolean pduTpType_b  : 1;  /* Pdu is handeled via transport protocol */
}SecOC_Prv_packedTxCfg_tstb;

/* MR12 RULE 2.4 VIOLATION: struct is used for typedef in SecOC_Types.h */
struct SecOC_Prv_TxPduConfig_st
{
    uint8 *authenticator_pu8;                 /*< Buffer for the authenticator created by the CSM */
    uint8 *authDataBuffer_pu8;                /*< Buffer for the data that is given to the CSM for authentication */
    uint8 *pduBufferOut_pu8;                  /*< Buffer for the secured or collection authentic PDU of this
                                                  TxPduProcessing context */
    uint8 *cryptographicPduBufferOut_pu8;     /*< Buffer for the cryptographic PDU of this TxPduProcessing context */
    uint8 *authenticPduBufferIn_pu8;          /*< Buffer for the authentic PDU of this TxPduProcessing context */
    boolean *isSameBufferRefInUse_pb;         /*< Pointer to a flag that indicates if the buffers are shared
                                                  with some other context */
    PduIdType *sameBufferRefInUsePduId_puo;   /*< Pointer to identifer of PDU which PDU uses the shared buffer */
    PduIdType pduRId_uo;                      /*< PduId of the secured PDU or collection authentic PDU from the PduR */
    PduLengthType pduLength_uo;               /*< Length of the secured PDU or collection authentic PDU */
    PduIdType pduRCryptographicPduId_uo;      /*< PduId of the cryptographic PDU from the PduR */
    PduLengthType cryptographicPduLength_uo;  /*< Length of the cryptographic PDU */
    PduIdType pduRAuthenticPduId_uo;          /*< PduId of the authentic PDU from the PduR */
    PduLengthType authenticPduLength_uo;      /*< Length of the authentic PDU */
    uint32 securedTxPduOffset_u32;            /*< Start position of secured area within the authentic PDU (in bytes) */
    uint32 securedTxPduLength_u32;            /*< Length of the secured area (in bytes) */
    uint16 authenticationBuildAttempts_u16;   /*< Maximum number of failed build attempts before failing to send PDU */
    uint16 authInfoTxLength_u16;              /*< Length of the transmitted authenticator in bits */
    uint16 dataId_u16;                        /*< Data Id of the PDU  */
    uint16 freshnessValueId_u16;              /*< Freshness Value Id of the PDU  */
    uint16 messageLinkPos_u16;                /*< Position of message linker inside the payload in bits */
    uint16 messageLinkLength_u16;             /*< Length of message linker inside the payload in bits */
    SecOC_Prv_packedTxCfg_tstb packedBits_stb;/*< packed bits struct */
    uint8  freshnessValueTxLength_u8;         /*< Length of the truncated freshness value in bits */
    uint8  securedHeaderLength_u8;            /*< Length of secured I-PDU header in bytes  */
 
    boolean useTxPduSecuredArea_b;            /*< Flag that indicates if the SecOCTxPduSecuredArea is used */
    uint8  unusedAreaDef_u8;                  /*< Default pattern for unused areas in secured and cryptographic PDU */
    SecOC_Prv_CryptIf_en cryptInterface_e;    /*< Enum that indicates the configured crypt interface (CCL, HSM, None) */
};

/* MR12 RULE 2.4 VIOLATION: struct is used for typedef in SecOC_Types.h */
struct SecOC_Prv_TxAuthenticPduContext_st
{
    const SecOC_Prv_TxPduConfig_tst *pduConfig_pst;         /*< Reference to the PDU config for this PDU context */
    uint8 *MetaDataPtr_pu8;                                 /*< Pointer to MetaData */
    PduLengthType payloadLength_uo;                         /*< Length of the payload in bits */
    volatile SecOC_Prv_TxAuthenticPduState_tu8 status_u8;   /*< State of the PDU (idle, sending, ...) */
    boolean isLocked_b;                                     /*< Flag that locks this context for multi-core protection */
};

/* MR12 RULE 2.4 VIOLATION: struct is used for typedef in SecOC_Types.h */
struct SecOC_Prv_TxSecuredPduContext_st
{
    const SecOC_Prv_TxPduConfig_tst *pduConfig_pst;     /*< Reference to the PDU config for this PDU context */
    uint8 *MetaDataPtr_pu8;                             /*< Pointer to MetaData */
    uint32 authDataBufferLength_u32;                    /*< Length of the authDataBuffer_pu8 buffer in bytes */
    uint32 jobId_u32;                                   /*< Id of the CSM job */
    uint32 pduIndex_u32;                                /*< Index to the internal pdu structures, stored during allocating context */
    PduLengthType payloadLength_uo;                     /*< Length of the payload in bits */
    PduLengthType actualPduLength_uo;                   /*< Length of the actual secured Pdu in bytes */
    PduLengthType bufferPosition_uo;                    /*< Position inside the pduBufferOut_pu8 for TP PDUs */
    PduLengthType cryptographicPduBufferPosition_uo;    /*< Position inside the cryptographicPduBufferOut_pu8 for TP PDUs */
    uint16 authAttempts_u16;                            /*< Number of failed authentication attempts since the last transmit request */
    volatile SecOC_Prv_TxSecuredPduState_tu8 status_u8; /*< State of the PDU (idle, sending, ...) */
    uint8 freshnessTruncValue_au8[SECOC_MAX_FRESHNESS_SIZE]; /*< Buffer for the truncated freshness value for this PDU */
    uint8 freshnessValueTxLength_u8;                    /*< Length of the truncated freshness value in bits */
    uint8 freshnessValueLength_u8;                      /*< Length of the complete freshness value in bits */
    boolean isLocked_b;                                 /*< Flag that locks this context for multi-core protection */
    boolean received_CryptographicPdu_b;                /*< Flag indicates if cryptogaphic PDU received */
    boolean received_AuthenticPdu_b;                    /*< Flag inidicates if collection Authentic PDU received */
};

/**
 * Definitions of data for verify status override
 */
typedef struct
{
    SecOC_OverrideStatusType overrideStatus_u8;
    uint8   numberOfMessagesToOverride_u8;
    uint8   numberOfOverriddenMessages_u8;
} SecOC_Prv_VerifyStatusOverrideType_tst;

/* MR12 RULE 2.4 VIOLATION: struct is used for typedef in SecOC_Types.h */
struct SecOC_Prv_GenConfigType_st {
    boolean ignoreVerificationResult_b;
    boolean rbRetryVerifyImmediately_b;
    boolean enableForcedPassOverride_b;
    boolean devErrorDetect_b;
};

/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/
#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
extern SecOC_GenConfigType SecOC_Prv_CurrentGenConfig_st;
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
extern SecOC_StateType SecOC_State_en;
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_CONST_8
#include "SecOC_MemMap.h"
#define SECOC_STOP_SEC_CONST_8
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
extern SecOC_Prv_TxAuthenticPduContext_tst SecOC_Prv_TxAuthenticPduContext_ast[];
extern SecOC_Prv_TxSecuredPduContext_tst SecOC_Prv_TxSecuredPduContext_ast[];
extern SecOC_Prv_RxSecuredPduContext_tst SecOC_Prv_RxSecuredPduContext_ast[];
extern SecOC_Prv_RxAuthenticPduContext_tst SecOC_Prv_RxAuthenticPduContext_ast[];
/* Verify status override buffer */
extern SecOC_Prv_VerifyStatusOverrideType_tst SecOC_Prv_VerifyStatusOverride_ast[];
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"
extern uint8 SecOC_Prv_RxCbkPending_au8[];
extern uint8 SecOC_Prv_RxTpRxIndPending[];
extern uint8 SecOC_Prv_TxCbkPending_au8[];
#define SECOC_STOP_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"


extern const SecOC_GenConfigType SecOC_Prv_DefaultGenConfig;


#define SECOC_START_SEC_VAR_CLEARED_32
#include "SecOC_MemMap.h"

/* Look up Rx freshness value id */
extern const uint16* SecOC_Prv_Rx_Lookup_ValueId_pcu16;

#define SECOC_STOP_SEC_VAR_CLEARED_32
#include "SecOC_MemMap.h"

/* MainFunction partition configuration for Tx/Rx PDUs */
/**
  * MainFunction partition configuration for Authentic Tx PDU instances
  */
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
/* Array of Tx pdu main function partitions */
extern const PduIdType* const SecOC_Prv_TxPduPartition_apcuo[SECOC_MAX_TX_PDU_PARTITION_CONFIG];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"


/**
  * MainFunction partition configuration for Secured Rx PDU instances
  */
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
/* Array of Rx pdu main function partitions */
extern const PduIdType* const SecOC_Prv_RxPduPartition_apcuo[SECOC_MAX_RX_PDU_PARTITION_CONFIG];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"


extern void SecOC_Prv_MemCopy(void* dst_p,
                       const void* src_p,
                       uint32 length_u32);

extern void SecOC_Prv_MemZero(void* const dst_cpv, uint32 length_u32);

extern void SecOC_Prv_CopyBits(uint8* dst_pu8,
                               uint32 dstBitPosition_u32,
                               const uint8* src_pcu8,
                               uint32 srcBitPosition_u32,
                               uint32 bitLength_u32);

extern void SecOC_Prv_SetBitsInByteBuffer(uint8 *dest_pu8,
                                          uint8 src_u8,
                                          uint32 position_u32,
                                          uint8 size_u8);

extern void SecOC_Prv_resetSameBufferTxRefInUse(uint32 configIndex_u32);
extern void SecOC_Prv_createSecPdu(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst,
                                   const uint8 *authenticator_pu8);

extern void SecOC_Prv_createPduCollection(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst,
                                          const uint8 *authenticator_pu8);

uint8 SecOC_Prv_TxGetSecuredHeaderLength(const SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pcst);


extern boolean SecOC_Prv_CheckAuthenticationResult(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst,
                                                   Std_ReturnType authResult);

extern void SecOC_Prv_AuthenticationRetry(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst);

extern Std_ReturnType SecOC_Prv_createDataforAuthenticationTx(SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst);

extern SecOC_Prv_TxSecuredPduContext_tst* SecOC_Prv_TxSecuredContextBufferAllocate(PduIdType pduIndex);
extern void SecOC_Prv_TxSecuredContextBufferRelease(SecOC_Prv_TxSecuredPduContext_tst** txPduContext_ppst);
extern SecOC_Prv_TxAuthenticPduContext_tst* SecOC_Prv_TxAuthenticContextBufferAllocate(PduIdType pduIndex);
extern void SecOC_Prv_TxAuthenticContextBufferRelease(SecOC_Prv_TxAuthenticPduContext_tst** txPduContext_ppst);
extern uint8 SecOC_Prv_TxGetPduType(PduIdType id);
extern void SecOC_Prv_handlePenTxCbk(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst);
extern Std_ReturnType SecOC_Prv_TpCopyTxData(SecOC_Prv_TxAuthenticPduContext_tst* txAuthenticPduCtx_pst);

extern boolean SecOC_Prv_HandleVerificationResult(SecOC_Prv_RxAuthenticPduContext_tst* rxPduCtx_pst, Std_ReturnType authResult);
extern void SecOC_Prv_createDataforAuthenticationRx(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst);
extern Std_ReturnType SecOC_Prv_getFreshnessValueRx(const SecOC_Prv_RxAuthenticPduContext_tst * const rxPduCtx_pst);
extern SecOC_Prv_RxSecuredPduContext_tst* SecOC_Prv_RxSecuredContextBufferAllocate(PduIdType pduIndex);
extern SecOC_Prv_RxAuthenticPduContext_tst* SecOC_Prv_RxAuthenticContextBufferAllocate(PduIdType pduIndex);
extern void SecOC_Prv_RxSecuredContextBufferRelease(SecOC_Prv_RxSecuredPduContext_tst** rxPduContext_ppst);
extern void SecOC_Prv_RxAuthenticContextBufferRelease(SecOC_Prv_RxAuthenticPduContext_tst** rxPduContext_ppst);
extern void SecOC_Prv_VerificationRetry(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst, SecOC_VerificationResultType verificationStatus,
                                  uint16* counter, uint16 maxValue);
extern void SecOC_Prv_VerificationSuccessful(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst);
extern void SecOC_Prv_VerificationFailed(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst, SecOC_VerificationResultType verificationStatus);
extern void SecOC_Prv_CopyPduFromSecuredCtxToAuthenticCtx(const SecOC_Prv_RxSecuredPduContext_tst * const rxSecuredPduCtx_cpcst,
                                                   SecOC_Prv_RxAuthenticPduContext_tst * const rxAuthenticPduCtx_cpst);
extern void SecOC_Prv_SaveVerifyStatusOverride(uint32 index_u32, SecOC_OverrideStatusType overrideStatus, uint8 numberOfMessagesToOverride);
extern void SecOC_Prv_CounterNumberOfMessagesAndSetState(uint32 index_u32);
extern SecOC_VerificationResultType SecOC_Prv_HandleVerifyStatusOverride(uint16 valueId, SecOC_VerificationResultType verificationStatus);
extern void SecOC_Prv_WriteVerificationStatus(const SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst);
extern Std_ReturnType SecOC_Prv_RxCheckAndSetAuthPduLengthFromSecuredHeader(SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst, const uint8* securedPduData_pcu8);
extern Std_ReturnType SecOC_Prv_RxCalculateAuthenticPduLength(SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst, uint32 securedLength_u32);
extern uint8 SecOC_Prv_RxGetAuthenticPduOffset(const SecOC_Prv_RxPduConfig_tst *rxPduCfg_pst);
extern uint8 SecOC_Prv_RxGetPduType(PduIdType id);
extern boolean SecOC_Prv_RxCheckMessageLinks(const SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst);
extern void SecOC_Prv_handlePenRxCbk(SecOC_Prv_RxAuthenticPduContext_tst *rxAuthPduCtx_pst);
extern SecOC_OverrideStatusType SecOC_Prv_fetchOverrideStatus(uint16  valueID_u16);
extern void SecOC_Prv_TpRxIndication( PduIdType id, Std_ReturnType result );



/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/

/**
 ***********************************************************************************************************************
 * \brief  Returns the current state of the PDU referenced by pduId.
 * \warning  pduId is assumed to be valid, no range check is done!
 *
 * \param[in]    pduId   identifier of the Tx secured PDU
 *
 * \return       current state
 ***********************************************************************************************************************
*/
LOCAL_INLINE SecOC_Prv_TxSecuredPduState_tu8 SecOC_Prv_TxSecuredContextBufferGetState(PduIdType pduId)
{
    return (SecOC_Prv_TxSecuredPduContext_ast[pduId].status_u8);
}

/**
 ***********************************************************************************************************************
 * \brief  Returns the current state of the PDU referenced by pduId.
 * \warning  pduId is assumed to be valid, no range check is done!
 *
 * \param[in]    pduId   identifier of the Tx authentic PDU
 *
 * \return       current state
 ***********************************************************************************************************************
*/
LOCAL_INLINE SecOC_Prv_TxAuthenticPduState_tu8 SecOC_Prv_TxAuthenticContextBufferGetState(PduIdType pduId)
{
    return (SecOC_Prv_TxAuthenticPduContext_ast[pduId].status_u8);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_clearTxSecuredPduContext
 *
 * \brief  The function cleares all buffers containing data of the authentic PDU.
 *         The PDU is specified by the PDU identifier. The buffers are hold in the buffer configuration structure which
 *         is identified via the PDU identifier.
 *
 * \param[inout]    SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst     pointer to the context buffer of the authentic
 *                                                                      pdu
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_clearTxSecuredPduContext(SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst)
{
    /* clear internal buffers of authentic Pdu */
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)txPduCtx_pst->pduConfig_pst->pduBufferOut_pu8, (uint32)txPduCtx_pst->pduConfig_pst->pduLength_uo);
    if (NULL_PTR != txPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8)
    {
        /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
        SecOC_Prv_MemZero((void*)txPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8, (uint32)txPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo);
    }
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)txPduCtx_pst->pduConfig_pst->authDataBuffer_pu8, (uint32)(txPduCtx_pst->authDataBufferLength_u32));
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)txPduCtx_pst->pduConfig_pst->authenticator_pu8, (uint32)(SECOC_CMAC_AES128v21_BLOCK_LEN));

    /* reset internal state for the Pdu */
    txPduCtx_pst->authAttempts_u16 = 0u;
    txPduCtx_pst->bufferPosition_uo = 0u;
    txPduCtx_pst->cryptographicPduBufferPosition_uo = 0u;
    txPduCtx_pst->status_u8 = SECOC_TX_STATE_SECURED_IDLE_E;
    txPduCtx_pst->received_AuthenticPdu_b = FALSE;
    txPduCtx_pst->received_CryptographicPdu_b = FALSE;
    txPduCtx_pst->MetaDataPtr_pu8 = NULL_PTR;
    SecOC_Prv_TxCbkPending_au8[txPduCtx_pst->pduIndex_u32] = SECOC_PRV_NO_PENDING_CALLBACK;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_clearAllTxPduContexts
 *
 * \brief  The function cleares all buffers containing data of all authentic PDUs.
 *
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_clearAllTxPduContexts(void)
{
    PduIdType configIndex_uo;
    SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst;
    SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst;


    /* initialize all internal buffers of authentic PDUs */
    for(configIndex_uo = 0; configIndex_uo < SECOC_NUMBER_AUTH_PDU; configIndex_uo++)
    {
        txSecuredPduCtx_pst  = &SecOC_Prv_TxSecuredPduContext_ast[configIndex_uo];
        SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
        txSecuredPduCtx_pst->isLocked_b = FALSE;
        txSecuredPduCtx_pst->received_CryptographicPdu_b = FALSE;
        txSecuredPduCtx_pst->received_AuthenticPdu_b = FALSE;
        txSecuredPduCtx_pst->MetaDataPtr_pu8 = NULL_PTR;
        txAuthenticPduCtx_pst  = &SecOC_Prv_TxAuthenticPduContext_ast[configIndex_uo];
        txAuthenticPduCtx_pst->status_u8 = SECOC_TX_STATE_AUTHENTIC_IDLE_E;
        SecOC_Prv_resetSameBufferTxRefInUse(configIndex_uo);
        txAuthenticPduCtx_pst->isLocked_b = FALSE;
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_CopyLengthInSecuredHeader
 *
 * \brief  The function copies the payload length into secured header
 *
 * \param[in]    SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst                  pointer to the context buffer of the secured pdu
 * \param[in]    uint8                              securedHeaderLengthInBits_u8         secured header length in bits
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_CopyLengthInSecuredHeader(const SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst)
{
    uint8 index_u8 = 0;
    uint8 securedHeaderLengthInBytes_u8 = 0u;
    PduLengthType securedHeaderValue_u32 = 0u;

    securedHeaderLengthInBytes_u8 = txSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8;
    securedHeaderValue_u32 = txSecuredPduCtx_pst->payloadLength_uo;

    if(FALSE == txSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.bitHeader_b)
    {
        securedHeaderValue_u32 = (securedHeaderValue_u32 + 7u) >> 3u;
    }

    /* Copy payload length into secured header */
    for(index_u8 = 0; index_u8 < securedHeaderLengthInBytes_u8; index_u8++)
    {
        SecOC_Prv_SetBitsInByteBuffer(
                txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8,          /* out: destination buffer */
                (uint8)((securedHeaderValue_u32 >> ((uint8)(securedHeaderLengthInBytes_u8 - 1u - index_u8) * 8u)) & 0xFFu) ,  /* in: source byte */
                (uint32)index_u8 * 8u,                                         /* in: start position of the data in the buffer in bits */
                8u                                                             /* in: size of data in bits */
        );
    }

}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_VerificationResultSuccess
 *
 * \brief  The function checks the verification result from csm.
 *         For PDUs with crypt interface NONE no verification result is available e.g. verifyResult_e is NULL_PTR.
 *
 * \param[in]    SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst  pointer to private context buffer of the pdu
 * \param[in]    uint16  valueID_u16                       value identifier of the pdu (freshness id or data id)
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE boolean SecOC_Prv_VerificationResultSuccess(const SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst,
                                                         uint16  valueID_u16)
{
    boolean result = FALSE;
    PduIdType idx_cuo = rxPduCtx_pst->pduConfig_pst->cryptIf_cst.idx_cuo;
    SecOC_Prv_CryptIf_en cryptIf_e = (*rxPduCtx_pst->pduConfig_pst->cryptIf_cst.value_pace)[idx_cuo];
    SecOC_OverrideStatusType overrideStatus_u8 = SecOC_Prv_fetchOverrideStatus(valueID_u16);
    /* If one PBV contains a CRYPTIF != SECOC_CRYPTIF_NONE => rxPduCtx_pst->pduConfig_pst->macVerifyResult_pen
       must be provided for all PVBs */
    if (SECOC_CRYPTIF_NONE == cryptIf_e)
    {
        result = TRUE;
    }
    else
    {
        if ((CRYPTO_E_VER_OK == *(rxPduCtx_pst->pduConfig_pst->macVerifyResult_pen))
             || (SECOC_OVERRIDE_TO_PASS  == overrideStatus_u8)
            )
        {
            result = TRUE;
        }
    }

    return (result);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_setRxTpRxIndPending
 *
 * \brief  The function sets the SecOC_Prv_RxTpRxIndPending to the given result
 *
 * \param[in]   PduIdType id           Pdu identifier
 * \param[in]   uint8 pduType_u8       Pdu type
 * \param[in]   td_ReturnType result   result of TpRxIndication
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_setRxTpRxIndPending(PduIdType id, uint8 pduType_u8, Std_ReturnType result)
{
    (void)pduType_u8;
    SecOC_Prv_RxTpRxIndPending[id] = result;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_resetRxTpRxIndPending
 *
 * \brief  The function resets the SecOC_Prv_RxTpRxIndPending
 *
 * \param[in]   PduIdType id         Pdu identifier
 * \param[in]   uint8 pduType_u8     Pdu type
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_resetRxTpRxIndPending(PduIdType id, uint8 pduType_u8)
{
    (void)pduType_u8;
    SecOC_Prv_RxTpRxIndPending[id] = SECOC_PRV_NO_PENDING_INDICATION;
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_resetSameBufferRxRefInUse
 *
 * \brief  The function resets the flag isSameBufferRefInUse_pb and the variable sameBufferRefInUsePduId_puo
 *         hold in the private context buffer
 *
 * \param[in]   SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst         pointer to the context buffer of the secured pdu
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_resetSameBufferRxRefInUse(const SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst)
{
    SchM_Enter_SecOC_SameBuffer();
    if (NULL_PTR != rxPduCtx_pst->pduConfig_pst->isSameBufferRefInUse_pb)
    {
        *(rxPduCtx_pst->pduConfig_pst->isSameBufferRefInUse_pb) = FALSE;
    }
    if (NULL_PTR != rxPduCtx_pst->pduConfig_pst->sameBufferRefInUsePduId_puo)
    {
        *(rxPduCtx_pst->pduConfig_pst->sameBufferRefInUsePduId_puo) = 0;
    }
    SchM_Exit_SecOC_SameBuffer();
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_clearRxSecuredPduContext
 *
 * \brief  The function cleares all buffers containing data of a secured PDU.
 *         The PDU is specified by the pointer to the context buffer.
 *         The function is called by SecOC_TxConfirmation and SecOC_TpRxIndication, after confirming the transmission of
 *         a secured PDU.
 *
 * \param[in]    SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst  pointer to the context buffer of the secured pdu
 *
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_clearRxSecuredPduContext(SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst)
{
    uint8_least idx_qu8;
    /* TRACE[SWS_SecOC_00212] */
    for(idx_qu8 = 0; idx_qu8 < rxPduCtx_pst->pduConfig_pst->metaDataLen_u8 ; idx_qu8++)
    {
        rxPduCtx_pst->metaData_pu8[idx_qu8] = 0;
    }

    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)rxPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,(uint32)rxPduCtx_pst->pduConfig_pst->pduLength_uo);
    if(NULL_PTR != rxPduCtx_pst->pduConfig_pst->cryptographicPduBufferIn_pu8)
    {
        /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
        SecOC_Prv_MemZero((void*)rxPduCtx_pst->pduConfig_pst->cryptographicPduBufferIn_pu8,
                          (uint32)rxPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo);
    }
    SecOC_Prv_resetSameBufferRxRefInUse(rxPduCtx_pst);
    rxPduCtx_pst->received_CryptographicPdu_b = FALSE;
    rxPduCtx_pst->received_AuthenticPdu_b = FALSE;
    rxPduCtx_pst->status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
    rxPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
    rxPduCtx_pst->isLocked_b = FALSE;
 }

/**
 ***********************************************************************************************************************
 * SecOC_Prv_clearRxAuthenticPduContext
 *
 * \brief  The function cleares all buffers containing data of a secured PDU.
 *         The PDU is specified by the pointer to the context buffer.
 *         The function is called by SecOC_TxConfirmation and SecOC_TpRxIndication, after confirming the transmission of
 *         a secured PDU.
 *
 * \param[in]    void *rxPduCtx_pst         pointer to the context buffer of the secured pdu
 * \param[in]    uint8 pduType_u8           pdu type
 *
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_clearRxAuthenticPduContext(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst)
{
    uint8_least idx_qu8;
    /* TRACE[SWS_SecOC_00212] */
    for(idx_qu8 = 0; idx_qu8 < rxPduCtx_pst->pduConfig_pst->metaDataLen_u8 ; idx_qu8++)
    {
        rxPduCtx_pst->metaData_pu8[idx_qu8] = 0;
    }
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,(uint32)rxPduCtx_pst->authDataBufferLength_u32);
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)rxPduCtx_pst->pduConfig_pst->authenticator_pu8,(uint32)(SECOC_CMAC_AES128v21_BLOCK_LEN));
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)rxPduCtx_pst->pduConfig_pst->authenticPduBufferOut_pu8,(uint32)rxPduCtx_pst->pduConfig_pst->authenticPduLength_uo);
    rxPduCtx_pst->verifyAttempts_u16 = 0;
    rxPduCtx_pst->authAttempts_u16 = 0;
    rxPduCtx_pst->verificationStatus_u8 = SECOC_VERIFICATIONFAILURE;
    rxPduCtx_pst->status_u8 = SECOC_RX_STATE_AUTHENTIC_IDLE_E;
    rxPduCtx_pst->isLocked_b = FALSE;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_clearAllRxPduContexts
 *
 * \brief  The function cleares all buffers containing data of all secured PDUs.
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_clearAllRxPduContexts(void)
{
    PduIdType configIndex_uo;
    SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst;
    SecOC_Prv_RxAuthenticPduContext_tst *rxAuthenticPduCtx_pst;

    /* initialize all internal buffers of secured PDUs */
    for(configIndex_uo = 0; configIndex_uo < SECOC_NUMBER_RX_PDU; configIndex_uo++)
    {
        rxSecuredPduCtx_pst  = &SecOC_Prv_RxSecuredPduContext_ast[configIndex_uo];
        SecOC_Prv_clearRxSecuredPduContext(rxSecuredPduCtx_pst);
        rxAuthenticPduCtx_pst  = &SecOC_Prv_RxAuthenticPduContext_ast[configIndex_uo];
        SecOC_Prv_clearRxAuthenticPduContext(rxAuthenticPduCtx_pst);
        SecOC_Prv_RxCbkPending_au8[configIndex_uo] = SECOC_PRV_NO_PENDING_CALLBACK;
        SecOC_Prv_resetRxTpRxIndPending(configIndex_uo, SecOC_Prv_RxGetPduType(configIndex_uo));
    }
}

/**
 ***********************************************************************************************************************
 * \brief  Returns the current state of the whole PDU buffer context (Secured Pdu or Secured Collection PDU)
 *         referenced by pduId.
 *         In case of collection PDU, the Collection Secured PDU state is composed from state of Authentic PDU (status_u8)
 *         and state of Cryptographic PDU (cryptographicPduStatus_u8).
 *         This function is used by MainFunctionRx to check if the Secured Pdu or Secured Pdu Collection is ready for
 *         verification.
 * \warning  pduId is assumed to be valid, no range check is done!
 *
 * \param[in]    pduId   identifier of the PDU
 *
 * \return       current state
 ***********************************************************************************************************************
*/
LOCAL_INLINE SecOC_Prv_RxSecuredPduState_tu8 SecOC_Prv_RxSecuredContextBufferGetState(PduIdType pduId)
{
    SecOC_Prv_RxSecuredPduState_tu8 status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;

    if (FALSE == SecOC_Prv_RxSecuredPduContext_ast[pduId].pduConfig_pst->packedBits_stb.pduColl_b)
    {
        status_u8 = SecOC_Prv_RxSecuredPduContext_ast[pduId].status_u8;
    }
    else
    {
        /* Collection PDU */
        if ((SECOC_RX_STATE_RECEIVED_E == SecOC_Prv_RxSecuredPduContext_ast[pduId].status_u8) &&
            (SECOC_RX_STATE_RECEIVED_E == SecOC_Prv_RxSecuredPduContext_ast[pduId].cryptographicPduStatus_u8))
        {
            status_u8 = SECOC_RX_STATE_RECEIVED_E;
        }
        else if ((SECOC_RX_STATE_SECURED_IDLE_E == SecOC_Prv_RxSecuredPduContext_ast[pduId].status_u8) &&
                 (SECOC_RX_STATE_SECURED_IDLE_E == SecOC_Prv_RxSecuredPduContext_ast[pduId].cryptographicPduStatus_u8))
        {
            status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
        }
        else
        {
            status_u8 = SECOC_RX_STATE_RECEIVING_E;
        }
    }
    return (status_u8);
}

/**
 ***********************************************************************************************************************
 * \brief  Returns the current state of the PDU referenced by pduId.
 * \warning  pduId is assumed to be valid, no range check is done!
 *
 * \param[in]    pduId   identifier of the PDU
 *
 * \return       current state
 ***********************************************************************************************************************
*/
LOCAL_INLINE SecOC_Prv_RxAuthenticPduState_tu8 SecOC_Prv_RxAuthenticContextBufferGetState(PduIdType pduId)
{
    return (SecOC_Prv_RxAuthenticPduContext_ast[pduId].status_u8);
}

/**
 ***********************************************************************************************************************
 * \brief  Returns the current state of the individual PDU buffer referenced by pduId.
 *         This function is used by RxIndication, StartOfReception, CopyRxData and TPRxIndication to check the status
 *         of Secured Pdu, Collection Authentic Pdu or Collection Cryptographic Pdu.
 * \warning  pduId is assumed to be valid, no range check is done!
 *
 * \param[in]    pduId          identifier of the PDU
 * \param[in]    PduIdType id   pdu type of secured PDU / cryptographic PDU / secured PDU
 *
 * \return       current state
 ***********************************************************************************************************************
*/
LOCAL_INLINE SecOC_Prv_RxSecuredPduState_tu8 SecOC_Prv_RxPduContextBufferGetState(PduIdType pduId, uint8 pduType_u8)
{
    SecOC_Prv_RxSecuredPduState_tu8 status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;

    if((SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8) || (SECOC_SECURED_PDU == pduType_u8))
    {
        status_u8 = SecOC_Prv_RxSecuredPduContext_ast[pduId].status_u8;
    }
    else
    {
        status_u8 = SecOC_Prv_RxSecuredPduContext_ast[pduId].cryptographicPduStatus_u8;
    }

    return status_u8;
}
/**
 ***********************************************************************************************************************
 * SecOC_Prv_clearVerifyStatusOverrideBuffer
 *
 * \brief        This function initializes the SecOC_Prv_VerifyStatusOverride_ast buffer
 *
 *
 ***********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_clearVerifyStatusOverrideBuffer(void)
{
    uint32 index_u32;
    for (index_u32 = 0; index_u32 < SECOC_MAX_VERIFY_STATUS_OVERRIDE; index_u32++)
    {
        SecOC_Prv_VerifyStatusOverride_ast[index_u32].overrideStatus_u8 = SECOC_OVERRIDE_CANCEL;
        SecOC_Prv_VerifyStatusOverride_ast[index_u32].numberOfMessagesToOverride_u8 = 0;
        SecOC_Prv_VerifyStatusOverride_ast[index_u32].numberOfOverriddenMessages_u8 = 0;
    }
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_getState
 *
 * \brief  The function returnes the global state of SecOC which is hold in the file SecOC.c.
 *         The state is set in the initialization function SecOC_Init and reset in the function SecOC_DeInit.
 *         The private interfaces of SecOC for PduR handling (SecOC_Prv_PduRIF) and for key handling (SecOC_Prv_KeyIF)
 *         need to know if the gobal variables of SecOC is initialized because the requests from PduR and for key
 *         handling must be rejected in an unitialized state.
 *
 * \return       SecOC_StateType     Result of the function call:
 *                                   - E_UNINIT: module SecOC is uninitialized
 *                                   - E_INIT  : module SecOC is initialized
 ***********************************************************************************************************************
*/
LOCAL_INLINE SecOC_StateType SecOC_Prv_getState(void)
{
    return(SecOC_State_en);
}

/**
 ***********************************************************************************************************************
 * In case the PDU referenced by \a cfgBuf_pst uses a shared buffer (SecOCSameBufferPduCollection) check
 * if it is available for use. If it is lock the buffer and store the PDU identifier.
 * Always returns TRUE if no shared buffer is configured.
 *
 * \param  boolean       *isSameBufferRefInUse_pb        pointer to a flag that indicates if shared buffer is used
 * \param  PduIdType     *IsSameBufferRefInUse_ps        pointer to a identifier of the PDU which uses the buffer

 * \param  PduIdType      pdu                            PDU identifier
 * \return TRUE if buffer is available, FALSE otherwise
 ***********************************************************************************************************************
*/
LOCAL_INLINE boolean SecOC_Prv_lockSameBuffer(boolean *isSameBufferRefInUse_pb,
                                                        PduIdType *sameBufferRefInUsePduId_puo, PduIdType pdu)
{
    boolean isAvailable_b = FALSE;

    SchM_Enter_SecOC_SameBuffer();
    if (NULL_PTR == isSameBufferRefInUse_pb)
    {
        // no buffer shared
        isAvailable_b = TRUE;
    }
    else if (!*isSameBufferRefInUse_pb)
    {
        *isSameBufferRefInUse_pb = TRUE;
        *sameBufferRefInUsePduId_puo = pdu;
        isAvailable_b = TRUE;
    }
    else if (*sameBufferRefInUsePduId_puo == pdu)
    {
        isAvailable_b = TRUE;
    }
    else
    {
        /* MR12 RULE 15.7 VIOLATION: Final else in if-else-if construct is always required. */
    }
    SchM_Exit_SecOC_SameBuffer();

    return (isAvailable_b);
}


#endif /* SECOC_PRV_H */

