/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Private source file providing configuration parameters for the SecOC module.
 * \addtogroup SecOC
 */


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"
#include "SecOC_Prv.h"
#include "SecOC_Prv_PduRIF.h"
#include "SecOC_Prv_PbCfg.h"
#include "Rte_SecOC.h"
#include "Csm.h"
/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
const SecOC_GenConfigType SecOC_Prv_DefaultGenConfig = {
    FALSE, /* secOCIgnoreVerificationResult_b */
    FALSE, /* secOCrbRetryVerifyImmediately_b */
    FALSE, /* secOCenableForcedPassOverride_b */
    FALSE            /* secOCdevErrorDetect_b */
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"



/**
  * global states of SecOC
  */
#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
SecOC_GenConfigType SecOC_Prv_CurrentGenConfig_st = {0};
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
SecOC_StateType SecOC_State_en = SECOC_UNINIT;
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"


/**
 *  Authenticator buffer for CsmMacGenerate for HSM jobs.
 */
#define SECOC_START_SEC_VAR_HSM_SHARED_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"


/**
 *  Authenticator buffer for CsmMacGenerate for CCL jobs.
 */

#define SECOC_STOP_SEC_VAR_HSM_SHARED_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"

/**
 *  Authenticator buffer for CsmMacGenerate for CSM_CRYPTO jobs.
 */
#define SECOC_START_SEC_VAR_CSM_CRYPTO_SHARED_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"
/* PSCMSACM_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_TxPDU0_authenticator_pu8[SECOC_CMAC_AES128v21_BLOCK_LEN];
#define SECOC_STOP_SEC_VAR_CSM_CRYPTO_SHARED_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"



/* Verification Results for
   _____  _____ __  __    _____ _______     _______ _______ ____  
  / ____|/ ____|  \/  |  / ____|  __ \ \   / /  __ \__   __/ __ \ 
 | |    | (___ | \  / | | |    | |__) \ \_/ /| |__) | | | | |  | |
 | |     \___ \| |\/| | | |    |  _  / \   / |  ___/  | | | |  | |
 | |____ ____) | |  | | | |____| | \ \  | |  | |      | | | |__| |
  \_____|_____/|_|  |_|  \_____|_|  \_\ |_|  |_|      |_|  \____/ - jobs*/

#define SECOC_START_SEC_VAR_CSM_CRYPTO_SHARED_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
/* CSCBCMCore_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static Crypto_VerifyResultType SecOC_Prv_RxPDU0_VerifyResult_Secured  = CRYPTO_E_VER_NOT_OK;
/* CSCBCMCore_SecCanFrame02_PduR2SecOC_Can_Network_0_Channel_CAN */
static Crypto_VerifyResultType SecOC_Prv_RxPDU1_VerifyResult_Secured  = CRYPTO_E_VER_NOT_OK;
/* CSCBCMCore_SecCanFrame03_PduR2SecOC_Can_Network_0_Channel_CAN */
static Crypto_VerifyResultType SecOC_Prv_RxPDU2_VerifyResult_Secured  = CRYPTO_E_VER_NOT_OK;
/* CSCBCMCore_SpecialSecFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static Crypto_VerifyResultType SecOC_Prv_RxPDU3_VerifyResult_Secured  = CRYPTO_E_VER_NOT_OK;
#define SECOC_STOP_SEC_VAR_CSM_CRYPTO_SHARED_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"
/* CSCBCMCore_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_RxPDU0_Authenticator_Secured_pu8[SECOC_CMAC_AES128v21_BLOCK_LEN];
/* CSCBCMCore_SecCanFrame02_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_RxPDU1_Authenticator_Secured_pu8[SECOC_CMAC_AES128v21_BLOCK_LEN];
/* CSCBCMCore_SecCanFrame03_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_RxPDU2_Authenticator_Secured_pu8[SECOC_CMAC_AES128v21_BLOCK_LEN];
/* CSCBCMCore_SpecialSecFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_RxPDU3_Authenticator_Secured_pu8[SECOC_CMAC_AES128v21_BLOCK_LEN];
#define SECOC_STOP_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_CLEARED_8
#include "SecOC_MemMap.h"
/**
  * TRACE[SWS_SecOC_00033], TRACE[SWS_SecOC_00057], TRACE[SWS_SecOC_00146], TRACE[SWS_SecOC_00110], TRACE[SWS_SecOC_00058],
  * TRACE[SWS_SecOC_Rb_00111], TRACE[SWS_SecOC_00082]:
  * Buffers for Secured PDUs
  * Bufferlength in bits for RxPduBuffer: equal length of secured I-PDU
  */
/* CSCBCMCore_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8  SecOC_Prv_PDU0_RxPduInBuffer_Secured_au8[48];
static uint8  SecOC_Prv_PDU0_RxPduOutBuffer_Authentic_au8[35];
/* CSCBCMCore_SecCanFrame02_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8  SecOC_Prv_PDU1_RxPduInBuffer_Secured_au8[32];
static uint8  SecOC_Prv_PDU1_RxPduOutBuffer_Authentic_au8[19];
/* CSCBCMCore_SecCanFrame03_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8  SecOC_Prv_PDU2_RxPduInBuffer_Secured_au8[64];
static uint8  SecOC_Prv_PDU2_RxPduOutBuffer_Authentic_au8[51];
/* CSCBCMCore_SpecialSecFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8  SecOC_Prv_PDU3_RxPduInBuffer_Secured_au8[16];
static uint8  SecOC_Prv_PDU3_RxPduOutBuffer_Authentic_au8[5];

/** TRACE[SWS_SecOC_00212]
  * MetaData buffer
  */
#define SECOC_STOP_SEC_VAR_CLEARED_8
#include "SecOC_MemMap.h"

/**
  * TRACE[SWS_SecOC_00033], TRACE[SWS_SecOC_00057], TRACE[SWS_SecOC_00146], TRACE[SWS_SecOC_00110], TRACE[SWS_SecOC_00058],
  * TRACE[SWS_SecOC_Rb_00111], TRACE[SWS_SecOC_00058]:
  * Buffers for Authentic PDUs
  * Bufferlength in bits for TxPduBuffer: equal length of secured I-PDU
  */
#define SECOC_START_SEC_VAR_CLEARED_8
#include "SecOC_MemMap.h"
/* PSCMSACM_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_PDU0_TxPduOutBuffer_Secured_au8[32];
static uint8 SecOC_Prv_PDU0_AuthenticPduBuffer_au8[19];
#define SECOC_STOP_SEC_VAR_CLEARED_8
#include "SecOC_MemMap.h"
/**
  * TRACE[SWS_SecOC_00033], TRACE[SWS_SecOC_00057], TRACE[SWS_SecOC_00146], TRACE[SWS_SecOC_00110], TRACE[SWS_SecOC_00058],
  * TRACE[SWS_SecOC_Rb_00111]:
  * Buffers for Authentic PDUs
  * Bufferlength in bits for TxAuthDataBuffer:
  *     length of Pdu payload + length of DataId (16 bits) + max. length of freshness value
  */
#define SECOC_START_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"
/* PSCMSACM_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_PDU0_TxAuthDataBuffer_au8[28];
#define SECOC_STOP_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"

/**
  * TRACE[SWS_SecOC_00033], TRACE[SWS_SecOC_00057], TRACE[SWS_SecOC_00146], TRACE[SWS_SecOC_00110], TRACE[SWS_SecOC_00058],
  * TRACE[SWS_SecOC_Rb_00111], TRACE[SWS_SecOC_00082]:
  * Buffers for Secured PDUs
  * Bufferlength in bits for RxAuthDataBuffer:
  *     length of Pdu payload + length of DataId (16 bits) + max. length of freshness value
  */
#define SECOC_START_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"
/* CSCBCMCore_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_PDU0_RxAuthDataBuffer_au8[44];
/* CSCBCMCore_SecCanFrame02_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_PDU1_RxAuthDataBuffer_au8[28];
/* CSCBCMCore_SecCanFrame03_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_PDU2_RxAuthDataBuffer_au8[60];
/* CSCBCMCore_SpecialSecFrame01_PduR2SecOC_Can_Network_0_Channel_CAN */
static uint8 SecOC_Prv_PDU3_RxAuthDataBuffer_au8[7];
#define SECOC_STOP_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
#include "SecOC_MemMap.h"

/**
  * Configuration structures of TxPDUs (SecOCTxPduProcessing)
  */
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
static const SecOC_Prv_TxPduConfig_tst SecOC_Prv_TxPduConfig_ast[SECOC_NUMBER_AUTH_PDU] =
{
  { /** PSCMSACM_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN, Authentic Pdu Id 0 **/
    SecOC_Prv_TxPDU0_authenticator_pu8, /* .authenticator_pu8 */
    SecOC_Prv_PDU0_TxAuthDataBuffer_au8, /* .authDataBuffer_pu8 */
    SecOC_Prv_PDU0_TxPduOutBuffer_Secured_au8, /* .pduBufferOut_pu8 */
    NULL_PTR, /* .cryptographicPduBufferOut_pu8 */
    SecOC_Prv_PDU0_AuthenticPduBuffer_au8, /* .authenticPduBufferIn_pu8 */
    NULL_PTR, /* .isSameBufferRefInUse_pb */
    NULL_PTR, /* .sameBufferRefInUsePduId_puo */
    PduRConf_PduRSrcPdu_PduRSrcPdu, /* pduRId_uo */
    32U, /*  pduLength_uo */
    0U, /* pduRCryptographicPduId_uo */
    0U, /* cryptographicPduLength_uo */
    PduRConf_PduRDestPdu_PSCMSACM_SecCanFrame01_PduR2CanIf_Can_Network_0_Channel_CAN, /* pduRAuthenticPduId_uo */
    19U, /* authenticPduLength_uo */
    0U, /* securedTxPduOffset_u32 */
    0U, /* securedTxPduLength_u32 */
    3U, /* authenticationBuildAttempts_u16 */
    88U, /* authInfoTxLength_u16 */
    258U, /* dataId_u16 */
    5U, /* freshnessValueId_u16 */
    0U, /*< .messageLinkPos_u16 */
    0U, /*< .messageLinkLength_u16 */
    { // packedBits_stb
        FALSE, /* bitHeader_b*/
        FALSE, /* clrTxBuf_b */
        TRUE, /* txConfirm_b */
        FALSE, /* truncFresh_b */
        FALSE, /* pduColl_b */
        FALSE, /* syncMod_b */
        FALSE  /*pduTpType_b  */
    },
    16U, /* freshnessValueTxLength_u8 */
    0U, /* securedHeaderLength_u8 */

    FALSE, /* useTxPduSecuredArea_b */

    0,  /* unusedAreaDef_u8 */
    SECOC_CRYPTIF_CSM_CRYPTO /* cryptInterface_e */
  }
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
/**
  * Structure of private context buffers for TxPDUs (SecOCTxPduProcessing)
  */
#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
SecOC_Prv_TxAuthenticPduContext_tst SecOC_Prv_TxAuthenticPduContext_ast[SECOC_NUMBER_AUTH_PDU] =
{
  { /* SecOCTxPduProcessing (SecOC Authentic PduId 0, SecOC Secured PduId 0) */
    &SecOC_Prv_TxPduConfig_ast[0], /* .pduConfig_pst */
    NULL_PTR, /* .MetaDataPtr_pu8 */
    152U, /* .payloadLength_uo */
    SECOC_TX_STATE_AUTHENTIC_IDLE_E, /* .status_u8 */
    FALSE /* .isLocked_b */
  }
};

SecOC_Prv_TxSecuredPduContext_tst SecOC_Prv_TxSecuredPduContext_ast[SECOC_NUMBER_AUTH_PDU] =
{
  { /* SecOCTxPduProcessing (SecOC Authentic PduId 0, SecOC Secured PduId 0) */
    &SecOC_Prv_TxPduConfig_ast[0], /* .pduConfig_pst */
    NULL_PTR, /* .MetaDataPtr_pu8 */
    28U, /* .authDataBufferLength_u32 */
    CsmConf_CsmJob_CsmJob_SecOCTxPduProcessing_TxCallback, /* JobId */
    0U,     /* pduIndex_u32 */
    152U, /* .payloadLength_uo */
    0U, /* .actualPduLength_uo */
    0U, /* .bufferPosition_uo */
    0U, /* .cryptographicPduBufferPosition_uo */
    0U, /* .authAttempts_u16 */
    SECOC_TX_STATE_SECURED_IDLE_E, /* .status_u8 */
    {0U}, /* .freshnessTruncValue_au8 */
    16U, /* freshnessValueTxLength_u8 */
    56U, /* freshnessValueLength_u8 */
    FALSE,  /* .isLocked_b */
    FALSE,  /* .received_CryptographicPdu_b */
    FALSE   /* .received_AuthenticPdu_b */
  }
};
#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"
uint8 SecOC_Prv_TxCbkPending_au8[SECOC_NUMBER_AUTH_PDU] =
{
  SECOC_PRV_NO_PENDING_CALLBACK};
#define SECOC_STOP_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"

/**
  * Configuration structures of RxPDUs (SecOCRxPduProcessing)
  */
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
static const SecOC_Prv_RxPduConfig_tst SecOC_Prv_RxSecuredPduConfig_ast[SECOC_NUMBER_RX_PDU]=
{
  { /** CSCBCMCore_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN, ID 0 **/
    SecOC_Prv_PDU0_RxPduInBuffer_Secured_au8, /* .pduBufferIn_pu8 */
    NULL_PTR,   /* .cryptographicPduBufferIn_pu8 */
    SecOC_Prv_PDU0_RxPduOutBuffer_Authentic_au8, /* .authenticPduBufferOut_pu8 */
    SecOC_Prv_RxPDU0_Authenticator_Secured_pu8, /* .authenticator_pu8 */
    SecOC_Prv_PDU0_RxAuthDataBuffer_au8, /* .authDataBuffer_pu8 */
    &SecOC_Prv_RxPDU0_VerifyResult_Secured, /* .macVerifyResult_pen */
    NULL_PTR, /* .sameBufferRefInUsePduId_puo */
    NULL_PTR, /* .isSameBufferRefInUse_pb */
    CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback, /*< .jobId_u32 */
    { NULL_PTR, 0u},    /* securedRxPduOffset_cst */
    { NULL_PTR, 0u},    /* securedRxPduLength_cst */
    48U, /*< .pduLength_uo */
    0U, /*< .cryptographicPduLength_uo */
    35U, /*< .authenticPduLength_uo */
    PduRConf_PduRSrcPdu_PduRSrcPdu_1, /*< .pduRAuthenticPduId_uo */
    3U, /*< .authenticationBuildAttempts_u16 */
    3U, /*< .authenticationVerifyAttempts_u16 */
    {&SecOC_Prv_RxAuthTruncLen_Common_pcu16, 0U}, /*< .authInfoTruncLen_cst */
    {&SecOC_Prv_RxDataId_Common_pcu16, 0U}, /*< .dataId_cst */
    {&SecOC_Prv_RxFreshValId_Common_pcu16, 0U}, /*< .freshnessValueId_cst */
    0U, /*< .authDataFreshnessLength_u16 */
    0U, /*< .authDataFreshnessStartPosition_u16 */
    0U, /*< .messageLinkPos_u16 */
    0U, /*< .messageLinkLength_u16 */
    { // packedBits_stb
        FALSE, /*< .authDataFresh_b */
        FALSE, /*< .pduColl_b */
        FALSE, /*< .dynPdu_b */
        FALSE, /*< .dynCryptoPdu_b  */
        FALSE, /* bitHeader_b*/
        FALSE, /* syncMod_b */
        FALSE  /*pduTpType_b  */
    },
    {&SecOC_Prv_RxFreshValTruncLen_Common_pcu8, 0U}, /*< .freshValTruncLen_cst */
    0U, /*< .metaDataLen_u8 of referenced secured Pdu */
    0U, /* securedHeaderLength_u8 */

    FALSE, /* useRxPduSecuredArea_b */

    {&SecOC_Prv_RxVerifyCryIf_Common_pcen, 0U}, /*< .cryptIf_cst */
    {&SecOC_Prv_RxPropMode_Common_pcen, 0U}, /*< .verifyPropMode_cst */
    SECOC_RX_QUEUE_E /*< QUEUE, REJECT, REPLACE */
  }
  ,
  { /** CSCBCMCore_SecCanFrame02_PduR2SecOC_Can_Network_0_Channel_CAN, ID 1 **/
    SecOC_Prv_PDU1_RxPduInBuffer_Secured_au8, /* .pduBufferIn_pu8 */
    NULL_PTR,   /* .cryptographicPduBufferIn_pu8 */
    SecOC_Prv_PDU1_RxPduOutBuffer_Authentic_au8, /* .authenticPduBufferOut_pu8 */
    SecOC_Prv_RxPDU1_Authenticator_Secured_pu8, /* .authenticator_pu8 */
    SecOC_Prv_PDU1_RxAuthDataBuffer_au8, /* .authDataBuffer_pu8 */
    &SecOC_Prv_RxPDU1_VerifyResult_Secured, /* .macVerifyResult_pen */
    NULL_PTR, /* .sameBufferRefInUsePduId_puo */
    NULL_PTR, /* .isSameBufferRefInUse_pb */
    CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback, /*< .jobId_u32 */
    { NULL_PTR, 0u},    /* securedRxPduOffset_cst */
    { NULL_PTR, 0u},    /* securedRxPduLength_cst */
    32U, /*< .pduLength_uo */
    0U, /*< .cryptographicPduLength_uo */
    19U, /*< .authenticPduLength_uo */
    PduRConf_PduRSrcPdu_PduRSrcPdu_2, /*< .pduRAuthenticPduId_uo */
    3U, /*< .authenticationBuildAttempts_u16 */
    3U, /*< .authenticationVerifyAttempts_u16 */
    {&SecOC_Prv_RxAuthTruncLen_Common_pcu16, 1U}, /*< .authInfoTruncLen_cst */
    {&SecOC_Prv_RxDataId_Common_pcu16, 1U}, /*< .dataId_cst */
    {&SecOC_Prv_RxFreshValId_Common_pcu16, 1U}, /*< .freshnessValueId_cst */
    0U, /*< .authDataFreshnessLength_u16 */
    0U, /*< .authDataFreshnessStartPosition_u16 */
    0U, /*< .messageLinkPos_u16 */
    0U, /*< .messageLinkLength_u16 */
    { // packedBits_stb
        FALSE, /*< .authDataFresh_b */
        FALSE, /*< .pduColl_b */
        FALSE, /*< .dynPdu_b */
        FALSE, /*< .dynCryptoPdu_b  */
        FALSE, /* bitHeader_b*/
        FALSE, /* syncMod_b */
        FALSE  /*pduTpType_b  */
    },
    {&SecOC_Prv_RxFreshValTruncLen_Common_pcu8, 1U}, /*< .freshValTruncLen_cst */
    0U, /*< .metaDataLen_u8 of referenced secured Pdu */
    0U, /* securedHeaderLength_u8 */

    FALSE, /* useRxPduSecuredArea_b */

    {&SecOC_Prv_RxVerifyCryIf_Common_pcen, 1U}, /*< .cryptIf_cst */
    {&SecOC_Prv_RxPropMode_Common_pcen, 1U}, /*< .verifyPropMode_cst */
    SECOC_RX_QUEUE_E /*< QUEUE, REJECT, REPLACE */
  }
  ,
  { /** CSCBCMCore_SecCanFrame03_PduR2SecOC_Can_Network_0_Channel_CAN, ID 2 **/
    SecOC_Prv_PDU2_RxPduInBuffer_Secured_au8, /* .pduBufferIn_pu8 */
    NULL_PTR,   /* .cryptographicPduBufferIn_pu8 */
    SecOC_Prv_PDU2_RxPduOutBuffer_Authentic_au8, /* .authenticPduBufferOut_pu8 */
    SecOC_Prv_RxPDU2_Authenticator_Secured_pu8, /* .authenticator_pu8 */
    SecOC_Prv_PDU2_RxAuthDataBuffer_au8, /* .authDataBuffer_pu8 */
    &SecOC_Prv_RxPDU2_VerifyResult_Secured, /* .macVerifyResult_pen */
    NULL_PTR, /* .sameBufferRefInUsePduId_puo */
    NULL_PTR, /* .isSameBufferRefInUse_pb */
    CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback, /*< .jobId_u32 */
    { NULL_PTR, 0u},    /* securedRxPduOffset_cst */
    { NULL_PTR, 0u},    /* securedRxPduLength_cst */
    64U, /*< .pduLength_uo */
    0U, /*< .cryptographicPduLength_uo */
    51U, /*< .authenticPduLength_uo */
    PduRConf_PduRSrcPdu_PduRSrcPdu_3, /*< .pduRAuthenticPduId_uo */
    3U, /*< .authenticationBuildAttempts_u16 */
    3U, /*< .authenticationVerifyAttempts_u16 */
    {&SecOC_Prv_RxAuthTruncLen_Common_pcu16, 2U}, /*< .authInfoTruncLen_cst */
    {&SecOC_Prv_RxDataId_Common_pcu16, 2U}, /*< .dataId_cst */
    {&SecOC_Prv_RxFreshValId_Common_pcu16, 2U}, /*< .freshnessValueId_cst */
    0U, /*< .authDataFreshnessLength_u16 */
    0U, /*< .authDataFreshnessStartPosition_u16 */
    0U, /*< .messageLinkPos_u16 */
    0U, /*< .messageLinkLength_u16 */
    { // packedBits_stb
        FALSE, /*< .authDataFresh_b */
        FALSE, /*< .pduColl_b */
        FALSE, /*< .dynPdu_b */
        FALSE, /*< .dynCryptoPdu_b  */
        FALSE, /* bitHeader_b*/
        FALSE, /* syncMod_b */
        FALSE  /*pduTpType_b  */
    },
    {&SecOC_Prv_RxFreshValTruncLen_Common_pcu8, 2U}, /*< .freshValTruncLen_cst */
    0U, /*< .metaDataLen_u8 of referenced secured Pdu */
    0U, /* securedHeaderLength_u8 */

    FALSE, /* useRxPduSecuredArea_b */

    {&SecOC_Prv_RxVerifyCryIf_Common_pcen, 2U}, /*< .cryptIf_cst */
    {&SecOC_Prv_RxPropMode_Common_pcen, 2U}, /*< .verifyPropMode_cst */
    SECOC_RX_QUEUE_E /*< QUEUE, REJECT, REPLACE */
  }
  ,
  { /** CSCBCMCore_SpecialSecFrame01_PduR2SecOC_Can_Network_0_Channel_CAN, ID 3 **/
    SecOC_Prv_PDU3_RxPduInBuffer_Secured_au8, /* .pduBufferIn_pu8 */
    NULL_PTR,   /* .cryptographicPduBufferIn_pu8 */
    SecOC_Prv_PDU3_RxPduOutBuffer_Authentic_au8, /* .authenticPduBufferOut_pu8 */
    SecOC_Prv_RxPDU3_Authenticator_Secured_pu8, /* .authenticator_pu8 */
    SecOC_Prv_PDU3_RxAuthDataBuffer_au8, /* .authDataBuffer_pu8 */
    &SecOC_Prv_RxPDU3_VerifyResult_Secured, /* .macVerifyResult_pen */
    NULL_PTR, /* .sameBufferRefInUsePduId_puo */
    NULL_PTR, /* .isSameBufferRefInUse_pb */
    CsmConf_CsmJob_CsmJob_IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback, /*< .jobId_u32 */
    { NULL_PTR, 0u},    /* securedRxPduOffset_cst */
    { NULL_PTR, 0u},    /* securedRxPduLength_cst */
    16U, /*< .pduLength_uo */
    0U, /*< .cryptographicPduLength_uo */
    5U, /*< .authenticPduLength_uo */
    PduRConf_PduRSrcPdu_PduRSrcPdu_4, /*< .pduRAuthenticPduId_uo */
    3U, /*< .authenticationBuildAttempts_u16 */
    3U, /*< .authenticationVerifyAttempts_u16 */
    {&SecOC_Prv_RxAuthTruncLen_Common_pcu16, 3U}, /*< .authInfoTruncLen_cst */
    {&SecOC_Prv_RxDataId_Common_pcu16, 3U}, /*< .dataId_cst */
    {&SecOC_Prv_RxFreshValId_Common_pcu16, 3U}, /*< .freshnessValueId_cst */
    0U, /*< .authDataFreshnessLength_u16 */
    0U, /*< .authDataFreshnessStartPosition_u16 */
    0U, /*< .messageLinkPos_u16 */
    0U, /*< .messageLinkLength_u16 */
    { // packedBits_stb
        FALSE, /*< .authDataFresh_b */
        FALSE, /*< .pduColl_b */
        FALSE, /*< .dynPdu_b */
        FALSE, /*< .dynCryptoPdu_b  */
        FALSE, /* bitHeader_b*/
        FALSE, /* syncMod_b */
        FALSE  /*pduTpType_b  */
    },
    {&SecOC_Prv_RxFreshValTruncLen_Common_pcu8, 3U}, /*< .freshValTruncLen_cst */
    0U, /*< .metaDataLen_u8 of referenced secured Pdu */
    0U, /* securedHeaderLength_u8 */

    FALSE, /* useRxPduSecuredArea_b */

    {&SecOC_Prv_RxVerifyCryIf_Common_pcen, 3U}, /*< .cryptIf_cst */
    {&SecOC_Prv_RxPropMode_Common_pcen, 3U}, /*< .verifyPropMode_cst */
    SECOC_RX_QUEUE_E /*< QUEUE, REJECT, REPLACE */
  }
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"

/**
  * Structure of private context buffers for RxPDUs (SecOCRxPduProcessing)
  */
#define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
SecOC_Prv_RxSecuredPduContext_tst SecOC_Prv_RxSecuredPduContext_ast[SECOC_NUMBER_RX_PDU] =
{
  { /** IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 0) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[0], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init */
    0U, /* .bufferPosition_uo */
    0U, /* .cryptographicPduBufferPosition_uo */
    0u, /* upTpBufSize_uo */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .status_u8 */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .cryptographicPduStatus_u8 */
    FALSE,  /* .received_CryptographicPdu_b */
    FALSE,  /* .received_AuthenticPdu_b */
    FALSE   /* .isLocked_b */
  }
  ,
  { /** IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 1) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[1], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init */
    0U, /* .bufferPosition_uo */
    0U, /* .cryptographicPduBufferPosition_uo */
    0u, /* upTpBufSize_uo */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .status_u8 */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .cryptographicPduStatus_u8 */
    FALSE,  /* .received_CryptographicPdu_b */
    FALSE,  /* .received_AuthenticPdu_b */
    FALSE   /* .isLocked_b */
  }
  ,
  { /** IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 2) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[2], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init */
    0U, /* .bufferPosition_uo */
    0U, /* .cryptographicPduBufferPosition_uo */
    0u, /* upTpBufSize_uo */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .status_u8 */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .cryptographicPduStatus_u8 */
    FALSE,  /* .received_CryptographicPdu_b */
    FALSE,  /* .received_AuthenticPdu_b */
    FALSE   /* .isLocked_b */
  }
  ,
  { /** IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 3) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[3], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init */
    0U, /* .bufferPosition_uo */
    0U, /* .cryptographicPduBufferPosition_uo */
    0u, /* upTpBufSize_uo */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .status_u8 */
    SECOC_RX_STATE_SECURED_IDLE_E, /* .cryptographicPduStatus_u8 */
    FALSE,  /* .received_CryptographicPdu_b */
    FALSE,  /* .received_AuthenticPdu_b */
    FALSE   /* .isLocked_b */
  }
};

SecOC_Prv_RxAuthenticPduContext_tst SecOC_Prv_RxAuthenticPduContext_ast[SECOC_NUMBER_RX_PDU] =
{
  { /** IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 0) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[0], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /* .authDataBufferLength_u32 calculate in SecOC_Prv_createDataforAuthenticationRx*/
    0U, /* pduIndex_u32 */
    0U, /* .verifyAttempts_u16 */
    0U, /* .authAttempts_u16 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init*/
    0U,   /* .upTpBufSize_uo */
    {0U}, /* .freshnessTruncValue_au8 */
    {0U}, /* .authDataFreshnessValue_au8 */
    {&SecOC_Prv_RxFreshValLen_Common_pu8, 0U}, /*< .freshnessValueLength_u8 */
    SECOC_VERIFICATIONFAILURE, /* .verificationStatus */
    SECOC_RX_STATE_AUTHENTIC_IDLE_E, /* .status_u8 */
    FALSE  /* .isLocked_b */
  }
  ,
  { /** IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 1) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[1], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /* .authDataBufferLength_u32 calculate in SecOC_Prv_createDataforAuthenticationRx*/
    0U, /* pduIndex_u32 */
    0U, /* .verifyAttempts_u16 */
    0U, /* .authAttempts_u16 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init*/
    0U,   /* .upTpBufSize_uo */
    {0U}, /* .freshnessTruncValue_au8 */
    {0U}, /* .authDataFreshnessValue_au8 */
    {&SecOC_Prv_RxFreshValLen_Common_pu8, 1U}, /*< .freshnessValueLength_u8 */
    SECOC_VERIFICATIONFAILURE, /* .verificationStatus */
    SECOC_RX_STATE_AUTHENTIC_IDLE_E, /* .status_u8 */
    FALSE  /* .isLocked_b */
  }
  ,
  { /** IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 2) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[2], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /* .authDataBufferLength_u32 calculate in SecOC_Prv_createDataforAuthenticationRx*/
    0U, /* pduIndex_u32 */
    0U, /* .verifyAttempts_u16 */
    0U, /* .authAttempts_u16 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init*/
    0U,   /* .upTpBufSize_uo */
    {0U}, /* .freshnessTruncValue_au8 */
    {0U}, /* .authDataFreshnessValue_au8 */
    {&SecOC_Prv_RxFreshValLen_Common_pu8, 2U}, /*< .freshnessValueLength_u8 */
    SECOC_VERIFICATIONFAILURE, /* .verificationStatus */
    SECOC_RX_STATE_AUTHENTIC_IDLE_E, /* .status_u8 */
    FALSE  /* .isLocked_b */
  }
  ,
  { /** IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx (SecOC Secured PduId 3) **/
    &SecOC_Prv_RxSecuredPduConfig_ast[3], /* .pduConfig_pst */
    NULL_PTR, /* .metaData_pu8 */
    0U, /* .authDataBufferLength_u32 calculate in SecOC_Prv_createDataforAuthenticationRx*/
    0U, /* pduIndex_u32 */
    0U, /* .verifyAttempts_u16 */
    0U, /* .authAttempts_u16 */
    0U, /*< .actualAuthenticPduLengthInBits_uo calculate in Init*/
    0U,   /* .upTpBufSize_uo */
    {0U}, /* .freshnessTruncValue_au8 */
    {0U}, /* .authDataFreshnessValue_au8 */
    {&SecOC_Prv_RxFreshValLen_Common_pu8, 3U}, /*< .freshnessValueLength_u8 */
    SECOC_VERIFICATIONFAILURE, /* .verificationStatus */
    SECOC_RX_STATE_AUTHENTIC_IDLE_E, /* .status_u8 */
    FALSE  /* .isLocked_b */
  }
};

/* Verify status override buffer */
SecOC_Prv_VerifyStatusOverrideType_tst SecOC_Prv_VerifyStatusOverride_ast[SECOC_MAX_VERIFY_STATUS_OVERRIDE] =
{
    {SECOC_OVERRIDE_CANCEL, 0U, 0U},
    {SECOC_OVERRIDE_CANCEL, 0U, 0U},
    {SECOC_OVERRIDE_CANCEL, 0U, 0U},
    {SECOC_OVERRIDE_CANCEL, 0U, 0U}
};

#define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"

#define SECOC_START_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"
uint8 SecOC_Prv_RxCbkPending_au8[SECOC_NUMBER_RX_PDU] =
{
  SECOC_PRV_NO_PENDING_CALLBACK,
  SECOC_PRV_NO_PENDING_CALLBACK,
  SECOC_PRV_NO_PENDING_CALLBACK,
  SECOC_PRV_NO_PENDING_CALLBACK};

uint8 SecOC_Prv_RxTpRxIndPending[4] =
{
  SECOC_PRV_NO_PENDING_INDICATION,
  SECOC_PRV_NO_PENDING_INDICATION,
  SECOC_PRV_NO_PENDING_INDICATION,
  SECOC_PRV_NO_PENDING_INDICATION};
#define SECOC_STOP_SEC_VAR_INIT_8
#include "SecOC_MemMap.h"


/* MainFunction partition configuration for Tx/Rx PDUs */
/**
  * MainFunction partition configuration for Authentic Tx PDU instances
  */
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
/* Array of Tx PDU IDs with no reference to a SecOCMainFunctionTx container */
static const PduIdType SecOC_Prv_TxPduPartition_Default_acuo[1] =
{
    0,
};

/* Array of Tx pdu main function partitions */
const PduIdType* const SecOC_Prv_TxPduPartition_apcuo[SECOC_MAX_TX_PDU_PARTITION_CONFIG] =
{
    &SecOC_Prv_TxPduPartition_Default_acuo[0u],
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"



/**
  * MainFunction partition configuration for Secured Rx PDU instances
  */
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"

/* Array of Rx PDU IDs with no reference to a SecOCMainFunctionRx container */
static const PduIdType SecOC_Prv_RxPduPartition_Default_acuo[4] =
{
    0,
    1,
    2,
    3,
};

/* Array of Rx pdu main function partitions */
const PduIdType* const SecOC_Prv_RxPduPartition_apcuo[SECOC_MAX_RX_PDU_PARTITION_CONFIG] =
{
    &SecOC_Prv_RxPduPartition_Default_acuo[0u],
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"


