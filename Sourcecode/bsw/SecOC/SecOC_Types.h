/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef SECOC_TYPES_H
#define SECOC_TYPES_H

/**
 * \file
 * \brief TRACE[SWS_SecOC_00002]: Definition of the types (particularly configuration types) for the SecOC module
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "ComStack_Types.h"  /* TRACE[SWS_SecOC_00103]: ComStack types */
#include "Rte_SecOC_Type.h"

/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/

/* Warning "unused parameter",
 * systematically produced as the abstract interfaces (if) have more parameters than the specific ones */
#define SECOC_PARAM_UNUSED(param)          (void)(param)

/* Version information parameters */
#define SECOC_VENDOR_ID                   6U
#define SECOC_MODULE_ID                   150U
#define SECOC_INSTANCE_ID                 0U
#define SECOC_SW_MAJOR_VERSION            2U
#define SECOC_SW_MINOR_VERSION            0U
#define SECOC_SW_PATCH_VERSION            0U
#define SECOC_AR_RELEASE_MAJOR_VERSION    4U
#define SECOC_AR_RELEASE_MINOR_VERSION    5U
#define SECOC_AR_RELEASE_REVISION_VERSION 0U

/* TRACE[SWS_SecOC_00101]: DET Error IDs */
#define SECOC_E_PARAM_POINTER              1U
#define SECOC_E_UNINIT                     2U
#define SECOC_E_INVALID_PDU_SDU_ID         3U
#define SECOC_E_CRYPTO_FAILURE             4U
#define SECOC_E_INIT_FAILED                7U
/* TRACE[SWS_RB_SecOC_00101]: additional DET Error IDs */
#define SECOC_E_FRESHNESS_FAILURE          8U
#define SECOC_E_INVALID_INTERNAL_STATE     9U
#define SECOC_E_SAME_BUFFER_BLOCKED       10U
#define SECOC_E_INVALID_SECURED_AREA      11U
#define SECOC_E_INVALID_PARTITION         12U

#define SECOC_E_PARAM                    255U

#define SECOC_E_BUSY                     2U

/* Service IDs */
#define SECOC_SERVICE_ID_INIT                   0x01U
#define SECOC_SERVICE_ID_GET_VERSION_INFO       0x02U
#define SECOC_SERVICE_ID_MAIN_FUNCTION_TX       0x03U
#define SECOC_SERVICE_ID_DEINIT                 0x05U
#define SECOC_SERVICE_ID_MAIN_FUNCTION_RX       0x06U
#define SECOC_SERVICE_ID_FRESHNESS_VALUE_READ   0x08U
#define SECOC_SERVICE_ID_FRESHNESS_VALUE_WRITE  0x09U
#define SECOC_SERVICE_ID_VERIFY_STATUS_OVERRIDE 0x0BU
#define SECOC_SERVICE_ID_TX_CONFIRMATION        0x40U
#define SECOC_SERVICE_ID_TRIGGER_TRANSMIT       0x41U
#define SECOC_SERVICE_ID_RX_INDICATION          0x42U
#define SECOC_SERVICE_ID_COPY_TX_DATA           0x43U
#define SECOC_SERVICE_ID_COPY_RX_DATA           0x44U
#define SECOC_SERVICE_ID_TP_RX_INDICATION       0x45U
#define SECOC_SERVICE_ID_START_OF_RECEPTION     0x46U
#define SECOC_SERVICE_ID_TP_TX_CONFIRMATION     0x48U
#define SECOC_SERVICE_ID_IF_CANCEL_TRANSMIT     0x4AU
#define SECOC_SERVICE_ID_CANCEL_RECEIVE         0x4CU
#define SECOC_SERVICE_ID_IFTRANSMIT             0x49U
#define SECOC_SERVICE_ID_TPTRANSMIT             0x53U
#define SECOC_SERVICE_ID_TP_CANCEL_TRANSMIT     0x54U

/* Defines for freshness */
#define SECOC_MAX_FRESHNESS_SIZE 8u /* 64 bit maximum complete freshness length as per AUTOSAR specification. */

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/
/**
  * TRACE[SWS_SecOC_00104]: Definition of Configuration Type
*/
typedef struct
{
    const uint32**  value_pacu32;   /* Pointer to PBS variant value */
    const PduIdType idx_cuo;        /* Index of Pdu according to location in PBS variant */
}SecOC_Prv_IdxVar32_tst;

typedef struct
{
    const uint16**  value_pacu16;   /* Pointer to PBS variant value */
    const PduIdType idx_cuo;        /* Index of Pdu according to location in PBS variant */
}SecOC_Prv_IdxVar16_tst;

typedef struct
{
    const uint8**   value_pacu8;    /* Pointer to PBS variant value */
    const PduIdType idx_cuo;        /* Index of Pdu according to location in PBS variant */
}SecOC_Prv_IdxVar8_tst;

typedef struct
{
          uint8**   value_pau8;     /* Pointer to PBS variant value */
    const PduIdType idx_cuo;        /* Index of Pdu according to location in PBS variant */
}SecOC_Prv_ctxIdxVar8_tst;

/* MR12 RULE 2.4 VIOLATION: structures are used for type definitions which are used in code */
typedef struct
{
    const uint16 idxPBV_cu16;
} SecOC_ConfigType;
typedef struct SecOC_Prv_GenConfigType_st SecOC_GenConfigType;
typedef struct SecOC_Prv_RxPduConfig_st SecOC_Prv_RxPduConfig_tst;
typedef struct SecOC_Prv_RxSecuredPduContext_st SecOC_Prv_RxSecuredPduContext_tst;
typedef struct SecOC_Prv_RxAuthenticPduContext_st SecOC_Prv_RxAuthenticPduContext_tst;
typedef struct SecOC_Prv_TxPduConfig_st SecOC_Prv_TxPduConfig_tst;
typedef struct SecOC_Prv_TxAuthenticPduContext_st SecOC_Prv_TxAuthenticPduContext_tst;
typedef struct SecOC_Prv_TxSecuredPduContext_st SecOC_Prv_TxSecuredPduContext_tst;
#endif /* SECOC_TYPES_H */
