/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Csm_Cfg.h"
#include "Csm.h"
#include "Csm_Prv.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/

#define CSM_START_SEC_CONST_32
#include "Csm_MemMap.h"
const uint32 Csm_Prv_KeyIdMapping_acu32[CSM_CFG_KEY_COUNT] =
{
    0U,
    1U,
    2U,
};

// Job-QueueId-Mappings (enumeration by jobId)
const uint32 Csm_Prv_JobQueueIdMapping_acu32[CSM_CFG_JOB_COUNT] =
{
    1U,
    0U,
    2U,
    3U,
    2U,
    3U,
    2U,
    3U,
    3U,
    3U,
    3U,
};

// Queue-ChannelId-Mappings (enumeration by jobId)
const uint32 Csm_Prv_QueueChanneldIdMapping_acu32[CSM_CFG_QUEUE_COUNT] =
{
    3U,
    2U,
    0U,
    1U,
};

#define CSM_STOP_SEC_CONST_32
#include "Csm_MemMap.h"

#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
// Jobs (constant types), enumeration by jobId
const Crypto_JobInfoType Csm_Prv_JobInfos_acst[CSM_CFG_JOB_COUNT] =
{
    { //CsmJob_GCM_ENC
       0U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_GCM_DEC
       1U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_Gen_SecOC
       2U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_Ver_SecOC
       3U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_Gen_SecOC_1
       4U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_Ver_SecOC_1
       5U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_SecOCTxPduProcessing_TxCallback
       6U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback
       7U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback
       8U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback
       9U, //jobId
       0U, //jobPriority
    },
    { //CsmJob_IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback
       10U, //jobId
       0U, //jobPriority
    },
};

// Primitives
//TRACE[SWS_Csm_00028][SWS_Csm_91005]
const Crypto_PrimitiveInfoType Csm_Prv_Primitives_acst[CSM_CFG_PRIMITIVE_COUNT] =
{
    { //CsmPrimitives_CBC_DEC
        1024U, //resultLength
        CRYPTO_DECRYPT, //service
        { //algorithm
            128U, //keyLength
            CRYPTO_ALGOFAM_AES, //family
            CRYPTO_ALGOFAM_NOT_SET, //secondaryFamily
            CRYPTO_ALGOMODE_CBC_NONE, //mode
        },
    },
    { //CsmPrimitives_CBC_ENC
        1024U, //resultLength
        CRYPTO_ENCRYPT, //service
        { //algorithm
            128U, //keyLength
            CRYPTO_ALGOFAM_AES, //family
            CRYPTO_ALGOFAM_NOT_SET, //secondaryFamily
            CRYPTO_ALGOMODE_CBC_NONE, //mode
        },
    },
    { //CsmPrimitives_GCM_DEC
        1024U, //resultLength
        CRYPTO_AEADDECRYPT, //service
        { //algorithm
            128U, //keyLength
            CRYPTO_ALGOFAM_AES, //family
            CRYPTO_ALGOFAM_NOT_SET, //secondaryFamily
            CRYPTO_ALGOMODE_GCM, //mode
        },
    },
    { //CsmPrimitives_GCM_ENC
        1024U, //resultLength
        CRYPTO_AEADENCRYPT, //service
        { //algorithm
            128U, //keyLength
            CRYPTO_ALGOFAM_AES, //family
            CRYPTO_ALGOFAM_NOT_SET, //secondaryFamily
            CRYPTO_ALGOMODE_GCM, //mode
        },
    },
    { //CsmPrimitives_GEN
        16U, //resultLength
        CRYPTO_MACGENERATE, //service
        { //algorithm
            128U, //keyLength
            CRYPTO_ALGOFAM_AES, //family
            CRYPTO_ALGOFAM_NOT_SET, //secondaryFamily
            CRYPTO_ALGOMODE_CMAC, //mode
        },
    },
    { //CsmPrimitives_VER
        1U, //resultLength
        CRYPTO_MACVERIFY, //service
        { //algorithm
            128U, //keyLength
            CRYPTO_ALGOFAM_AES, //family
            CRYPTO_ALGOFAM_NOT_SET, //secondaryFamily
            CRYPTO_ALGOMODE_CMAC, //mode
        },
    },
};

// Job-Primitive-Mappings, enumeration by jobId
//TRACE[SWS_Csm_91006]
const Crypto_JobPrimitiveInfoType Csm_Prv_JobPrimitiveInfos_acst[CSM_CFG_JOB_COUNT] =
{
    { //CsmJob_GCM_ENC
       1U, //callbackId
       &Csm_Prv_Primitives_acst[3], //primitiveInfo
       0U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_GCM_DEC
       0U, //callbackId
       &Csm_Prv_Primitives_acst[2], //primitiveInfo
       0U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_Gen_SecOC
       2U, //callbackId
       &Csm_Prv_Primitives_acst[4], //primitiveInfo
       1U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_Ver_SecOC
       4U, //callbackId
       &Csm_Prv_Primitives_acst[5], //primitiveInfo
       1U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_Gen_SecOC_1
       3U, //callbackId
       &Csm_Prv_Primitives_acst[4], //primitiveInfo
       2U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_Ver_SecOC_1
       5U, //callbackId
       &Csm_Prv_Primitives_acst[5], //primitiveInfo
       2U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_SecOCTxPduProcessing_TxCallback
       10U, //callbackId
       &Csm_Prv_Primitives_acst[4], //primitiveInfo
       1U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback
       6U, //callbackId
       &Csm_Prv_Primitives_acst[5], //primitiveInfo
       1U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback
       7U, //callbackId
       &Csm_Prv_Primitives_acst[5], //primitiveInfo
       1U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback
       8U, //callbackId
       &Csm_Prv_Primitives_acst[5], //primitiveInfo
       1U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
    { //CsmJob_IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback
       9U, //callbackId
       &Csm_Prv_Primitives_acst[5], //primitiveInfo
       1U, //cryIfKeyId
       CRYPTO_PROCESSING_ASYNC, //processingType
    },
};


const Csm_Prv_PartitionConfig_st Csm_Prv_PartitionConfig_cast[CSM_CFG_PARTITION_COUNT] =
{
    {
        0U, // queueStartId_u32
        3U // queueEndId_u32
    },
};

#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"
// jobs (variable types)
//TRACE[SWS_Csm_00941]
/* MR12 DIR 1.1 VIOLATION: Larger than 32767 bytes object is not causing any issues */
Crypto_JobType Csm_Prv_Jobs_ast[CSM_CFG_JOB_COUNT] =
{
    { //CsmJob_GCM_ENC
        0U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[0], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[0], //jobInfo
        0U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_GCM_DEC
        1U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[1], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[1], //jobInfo
        0U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_Gen_SecOC
        2U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[2], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[2], //jobInfo
        1U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_Ver_SecOC
        3U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[3], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[3], //jobInfo
        1U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_Gen_SecOC_1
        4U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[4], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[4], //jobInfo
        2U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_Ver_SecOC_1
        5U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[5], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[5], //jobInfo
        2U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_SecOCTxPduProcessing_TxCallback
        6U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[6], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[6], //jobInfo
        1U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback
        7U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[7], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[7], //jobInfo
        1U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback
        8U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[8], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[8], //jobInfo
        1U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback
        9U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[9], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[9], //jobInfo
        1U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
    { //CsmJob_IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback
        10U, //jobId
        &Csm_Prv_JobPrimitiveInfos_acst[10], //jobPrimitiveInfo
        &Csm_Prv_JobInfos_acst[10], //jobInfo
        1U, //cryptoKeyId
        NULL_PTR, //jobRedirectionInfoRef
        0xFFFFFFFFU, //targetCryptoKeyId
        { //PrimitiveInputOutput
            NULL_PTR, //inputPtr
            0U, //inputLength
            NULL_PTR, //secondaryInputPtr
            0U, //secondaryInputLength
            NULL_PTR, //tertiaryInputPtr
            0U, //tertiaryInputLength
            NULL_PTR, //outputPtr
            NULL_PTR, //outputLengthPtr
            NULL_PTR, //secondaryOutputPtr
            NULL_PTR, //secondaryOutputLengthPtr
            NULL_PTR, //verifyPtr
            0U, //mode
            0xFFFFFFFFU, //cryIfKeyId
            0xFFFFFFFFU, //targetCryIfKeyId
            0xFFFFFFFFU, //keyElementId
            // elements from RFC 77701 not implemented because unused
        },
        CRYPTO_JOBSTATE_IDLE, //state
        FALSE, // jobCanceled_b
        TRUE, // callbackFinished_b
        FALSE, // bufferedCallbackEnabled_cb
        E_NOT_OK, // result_en
    },
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"

// FIFO buffers (variables, cleared to zero at reset)
#define CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Csm_MemMap.h"
/***
 * Waiting job queues
 ***/
static Crypto_JobType * Csm_Prv_FifoBuffer_0_0_CsmQueue_GCM_DEC_au32[2];
static Crypto_JobType * Csm_Prv_FifoBuffer_1_0_CsmQueue_GCM_ENC_au32[2];
static Crypto_JobType * Csm_Prv_FifoBuffer_2_0_CsmQueue_Gen_au32[3];
static Crypto_JobType * Csm_Prv_FifoBuffer_3_0_CsmQueue_Ver_au32[3];
#define CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Csm_MemMap.h"

// Queues(Multi level FIFOs) and job-FIFOs
#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"
/***
 * Waiting job queues
 ***/
static Crypto_FIFO_tst Csm_Prv_Fifo_0_0_CsmQueue_GCM_DEC_st =
{
    2U, // FIFO size equals queue size + 1 (one lost for 'full' detection)
    &Csm_Prv_FifoBuffer_0_0_CsmQueue_GCM_DEC_au32[0], // entries (requests)
    0U, // writeIndex_vu32
    0U, // readIndex_vu32
};
static Crypto_FIFO_tst Csm_Prv_Fifo_1_0_CsmQueue_GCM_ENC_st =
{
    2U, // FIFO size equals queue size + 1 (one lost for 'full' detection)
    &Csm_Prv_FifoBuffer_1_0_CsmQueue_GCM_ENC_au32[0], // entries (requests)
    0U, // writeIndex_vu32
    0U, // readIndex_vu32
};
static Crypto_FIFO_tst Csm_Prv_Fifo_2_0_CsmQueue_Gen_st =
{
    3U, // FIFO size equals queue size + 1 (one lost for 'full' detection)
    &Csm_Prv_FifoBuffer_2_0_CsmQueue_Gen_au32[0], // entries (requests)
    0U, // writeIndex_vu32
    0U, // readIndex_vu32
};
static Crypto_FIFO_tst Csm_Prv_Fifo_3_0_CsmQueue_Ver_st =
{
    3U, // FIFO size equals queue size + 1 (one lost for 'full' detection)
    &Csm_Prv_FifoBuffer_3_0_CsmQueue_Ver_au32[0], // entries (requests)
    0U, // writeIndex_vu32
    0U, // readIndex_vu32
};
#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"

#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
/***
 * Waiting job queues
 ***/
static const Crypto_FIFO_tst * const Csm_Prv_Cfg_FIFOs_0_CsmQueue_GCM_DEC_apst[] =
{
    &Csm_Prv_Fifo_0_0_CsmQueue_GCM_DEC_st,
};
static const Crypto_Queue_tst Csm_Prv_Queue_0_CsmQueue_GCM_DEC_st =
{
    1U, //levels_cu32
    /* MR12 RULE 11.3 VIOLATION:Casting is necesarry for variable array lengths and will not
     * impact on any functionality */
    (Crypto_FIFO_tst * const *)&Csm_Prv_Cfg_FIFOs_0_CsmQueue_GCM_DEC_apst,
};
static const Crypto_FIFO_tst * const Csm_Prv_Cfg_FIFOs_1_CsmQueue_GCM_ENC_apst[] =
{
    &Csm_Prv_Fifo_1_0_CsmQueue_GCM_ENC_st,
};
static const Crypto_Queue_tst Csm_Prv_Queue_1_CsmQueue_GCM_ENC_st =
{
    1U, //levels_cu32
    /* MR12 RULE 11.3 VIOLATION:Casting is necesarry for variable array lengths and will not
     * impact on any functionality */
    (Crypto_FIFO_tst * const *)&Csm_Prv_Cfg_FIFOs_1_CsmQueue_GCM_ENC_apst,
};
static const Crypto_FIFO_tst * const Csm_Prv_Cfg_FIFOs_2_CsmQueue_Gen_apst[] =
{
    &Csm_Prv_Fifo_2_0_CsmQueue_Gen_st,
};
static const Crypto_Queue_tst Csm_Prv_Queue_2_CsmQueue_Gen_st =
{
    1U, //levels_cu32
    /* MR12 RULE 11.3 VIOLATION:Casting is necesarry for variable array lengths and will not
     * impact on any functionality */
    (Crypto_FIFO_tst * const *)&Csm_Prv_Cfg_FIFOs_2_CsmQueue_Gen_apst,
};
static const Crypto_FIFO_tst * const Csm_Prv_Cfg_FIFOs_3_CsmQueue_Ver_apst[] =
{
    &Csm_Prv_Fifo_3_0_CsmQueue_Ver_st,
};
static const Crypto_Queue_tst Csm_Prv_Queue_3_CsmQueue_Ver_st =
{
    1U, //levels_cu32
    /* MR12 RULE 11.3 VIOLATION:Casting is necesarry for variable array lengths and will not
     * impact on any functionality */
    (Crypto_FIFO_tst * const *)&Csm_Prv_Cfg_FIFOs_3_CsmQueue_Ver_apst,
};

#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
/***
 * Waiting job queues
 ***/
const Crypto_Queue_tst* const Csm_Prv_QueueRefs_apst[CSM_CFG_QUEUE_COUNT] =
{
    &Csm_Prv_Queue_0_CsmQueue_GCM_DEC_st,
    &Csm_Prv_Queue_1_CsmQueue_GCM_ENC_st,
    &Csm_Prv_Queue_2_CsmQueue_Gen_st,
    &Csm_Prv_Queue_3_CsmQueue_Ver_st
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

/*
 **********************************************************************************************************************
 * Local definitions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"

//RTE Wrapper functions

// Prototype
Std_ReturnType Csm_KeyElementSet_CsmKey_DevKey(uint32 keyId, uint32 keyElementId,
                                                  const uint8* keyPtr, uint32 keyLength);

Std_ReturnType Csm_KeyElementSet_CsmKey_DevKey(uint32 keyId, uint32 keyElementId,
                                                  const uint8* keyPtr, uint32 keyLength)
{
    return Csm_KeyElementSet(keyId, keyElementId, keyPtr, keyLength);
}

// Prototype
Std_ReturnType Csm_KeyElementGet_CsmKey_DevKey(uint32 keyId, uint32 keyElementId,
                                                  uint8* keyPtr, uint32* keyLengthPtr);

Std_ReturnType Csm_KeyElementGet_CsmKey_DevKey(uint32 keyId, uint32 keyElementId,
                                                  uint8* keyPtr, uint32* keyLengthPtr)
{
    return Csm_KeyElementGet(keyId, keyElementId, keyPtr, keyLengthPtr);
}

// Prototype
Std_ReturnType Csm_RandomSeed_CsmKey_DevKey(uint32 keyId, const uint8* seedPtr,
                                               uint32 seedLength);

Std_ReturnType Csm_RandomSeed_CsmKey_DevKey(uint32 keyId, const uint8* seedPtr,
                                               uint32 seedLength)
{
    return Csm_RandomSeed(keyId, seedPtr, seedLength);
}

// Prototype
Std_ReturnType Csm_KeyExchangeCalcPubVal_CsmKey_DevKey(uint32 keyId, uint8* publicValuePtr,
                                                          uint32* publicValueLengthPtr);

Std_ReturnType Csm_KeyExchangeCalcPubVal_CsmKey_DevKey(uint32 keyId, uint8* publicValuePtr,
                                                          uint32* publicValueLengthPtr)
{
    return Csm_KeyExchangeCalcPubVal(keyId, publicValuePtr, publicValueLengthPtr);
}

// Prototype
Std_ReturnType Csm_KeyExchangeCalcSecret_CsmKey_DevKey(uint32 keyId, const uint8* partnerPublicValuePtr,
                                                          uint32 partnerPublicValueLength);

Std_ReturnType Csm_KeyExchangeCalcSecret_CsmKey_DevKey(uint32 keyId, const uint8* partnerPublicValuePtr,
                                                          uint32 partnerPublicValueLength)
{
    return Csm_KeyExchangeCalcSecret(keyId, partnerPublicValuePtr, partnerPublicValueLength);
}

// Prototype
Std_ReturnType Csm_KeyElementSet_CsmKey_SecOC_CMAC_Ele(uint32 keyId, uint32 keyElementId,
                                                  const uint8* keyPtr, uint32 keyLength);

Std_ReturnType Csm_KeyElementSet_CsmKey_SecOC_CMAC_Ele(uint32 keyId, uint32 keyElementId,
                                                  const uint8* keyPtr, uint32 keyLength)
{
    return Csm_KeyElementSet(keyId, keyElementId, keyPtr, keyLength);
}

// Prototype
Std_ReturnType Csm_KeyElementGet_CsmKey_SecOC_CMAC_Ele(uint32 keyId, uint32 keyElementId,
                                                  uint8* keyPtr, uint32* keyLengthPtr);

Std_ReturnType Csm_KeyElementGet_CsmKey_SecOC_CMAC_Ele(uint32 keyId, uint32 keyElementId,
                                                  uint8* keyPtr, uint32* keyLengthPtr)
{
    return Csm_KeyElementGet(keyId, keyElementId, keyPtr, keyLengthPtr);
}

// Prototype
Std_ReturnType Csm_RandomSeed_CsmKey_SecOC_CMAC_Ele(uint32 keyId, const uint8* seedPtr,
                                               uint32 seedLength);

Std_ReturnType Csm_RandomSeed_CsmKey_SecOC_CMAC_Ele(uint32 keyId, const uint8* seedPtr,
                                               uint32 seedLength)
{
    return Csm_RandomSeed(keyId, seedPtr, seedLength);
}

// Prototype
Std_ReturnType Csm_KeyExchangeCalcPubVal_CsmKey_SecOC_CMAC_Ele(uint32 keyId, uint8* publicValuePtr,
                                                          uint32* publicValueLengthPtr);

Std_ReturnType Csm_KeyExchangeCalcPubVal_CsmKey_SecOC_CMAC_Ele(uint32 keyId, uint8* publicValuePtr,
                                                          uint32* publicValueLengthPtr)
{
    return Csm_KeyExchangeCalcPubVal(keyId, publicValuePtr, publicValueLengthPtr);
}

// Prototype
Std_ReturnType Csm_KeyExchangeCalcSecret_CsmKey_SecOC_CMAC_Ele(uint32 keyId, const uint8* partnerPublicValuePtr,
                                                          uint32 partnerPublicValueLength);

Std_ReturnType Csm_KeyExchangeCalcSecret_CsmKey_SecOC_CMAC_Ele(uint32 keyId, const uint8* partnerPublicValuePtr,
                                                          uint32 partnerPublicValueLength)
{
    return Csm_KeyExchangeCalcSecret(keyId, partnerPublicValuePtr, partnerPublicValueLength);
}

// Prototype
Std_ReturnType Csm_KeyElementSet_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, uint32 keyElementId,
                                                  const uint8* keyPtr, uint32 keyLength);

Std_ReturnType Csm_KeyElementSet_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, uint32 keyElementId,
                                                  const uint8* keyPtr, uint32 keyLength)
{
    return Csm_KeyElementSet(keyId, keyElementId, keyPtr, keyLength);
}

// Prototype
Std_ReturnType Csm_KeyElementGet_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, uint32 keyElementId,
                                                  uint8* keyPtr, uint32* keyLengthPtr);

Std_ReturnType Csm_KeyElementGet_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, uint32 keyElementId,
                                                  uint8* keyPtr, uint32* keyLengthPtr)
{
    return Csm_KeyElementGet(keyId, keyElementId, keyPtr, keyLengthPtr);
}

// Prototype
Std_ReturnType Csm_RandomSeed_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, const uint8* seedPtr,
                                               uint32 seedLength);

Std_ReturnType Csm_RandomSeed_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, const uint8* seedPtr,
                                               uint32 seedLength)
{
    return Csm_RandomSeed(keyId, seedPtr, seedLength);
}

// Prototype
Std_ReturnType Csm_KeyExchangeCalcPubVal_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, uint8* publicValuePtr,
                                                          uint32* publicValueLengthPtr);

Std_ReturnType Csm_KeyExchangeCalcPubVal_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, uint8* publicValuePtr,
                                                          uint32* publicValueLengthPtr)
{
    return Csm_KeyExchangeCalcPubVal(keyId, publicValuePtr, publicValueLengthPtr);
}

// Prototype
Std_ReturnType Csm_KeyExchangeCalcSecret_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, const uint8* partnerPublicValuePtr,
                                                          uint32 partnerPublicValueLength);

Std_ReturnType Csm_KeyExchangeCalcSecret_CsmKey_SecOC_CMAC_Ele1(uint32 keyId, const uint8* partnerPublicValuePtr,
                                                          uint32 partnerPublicValueLength)
{
    return Csm_KeyExchangeCalcSecret(keyId, partnerPublicValuePtr, partnerPublicValueLength);
}


// Prototype
Std_ReturnType Csm_AEADDecrypt_CsmPrimitives_GCM_DEC_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                                 Csm_DataPtr ciphertextPtr, uint32 ciphertextLength,
                                                 Csm_DataPtr associatedDataPtr, uint32 associatedDataLength,
                                                 Csm_DataPtr tagPtr, uint32 tagLength, Csm_DataPtr plaintextPtr,
                                                 uint32* plaintextLengthPtr, Crypto_VerifyResultType* verifyPtr);

/* HIS METRIC PARAM VIOLATION IN Csm_AEADDecrypt_CsmPrimitives_GCM_DEC_OPTIMIZED: Interface parameters
are defined in AR specification and cannot be modified.*/
Std_ReturnType Csm_AEADDecrypt_CsmPrimitives_GCM_DEC_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                                 Csm_DataPtr ciphertextPtr, uint32 ciphertextLength,
                                                 Csm_DataPtr associatedDataPtr, uint32 associatedDataLength,
                                                 Csm_DataPtr tagPtr, uint32 tagLength, Csm_DataPtr plaintextPtr,
                                                 uint32* plaintextLengthPtr, Crypto_VerifyResultType* verifyPtr)
{
    /* MR12 RULE 11.8 VIOLATION: cast cannot be avoided because of AUTOSAR definition */
    return Csm_AEADDecrypt(jobId, mode, ciphertextPtr, ciphertextLength, associatedDataPtr,
                          associatedDataLength, tagPtr, tagLength, (uint8*)plaintextPtr, plaintextLengthPtr, verifyPtr);
}

// Prototype
Std_ReturnType Csm_AEADEncrypt_CsmPrimitives_GCM_ENC_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                                 Csm_DataPtr plaintextPtr, uint32 plaintextLength,
                                                 Csm_DataPtr associatedDataPtr, uint32 associatedDataLength,
                                                 Csm_DataPtr ciphertextPtr, uint32* ciphertextLengthPtr,
                                                 Csm_DataPtr tagPtr, uint32* tagLengthPtr);

/* HIS METRIC PARAM VIOLATION IN Csm_AEADEncrypt_CsmPrimitives_GCM_ENC_OPTIMIZED: Interface parameters
are defined in AR specification and cannot be modified.*/
Std_ReturnType Csm_AEADEncrypt_CsmPrimitives_GCM_ENC_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                                 Csm_DataPtr plaintextPtr, uint32 plaintextLength,
                                                 Csm_DataPtr associatedDataPtr, uint32 associatedDataLength,
                                                 Csm_DataPtr ciphertextPtr, uint32* ciphertextLengthPtr,
                                                 Csm_DataPtr tagPtr, uint32* tagLengthPtr)
{
    /* MR12 RULE 11.8 VIOLATION: cast cannot be avoided because of AUTOSAR definition */
    return Csm_AEADEncrypt(jobId, mode, plaintextPtr, plaintextLength, associatedDataPtr,
                        associatedDataLength, (uint8*)ciphertextPtr, ciphertextLengthPtr, (uint8*)tagPtr, tagLengthPtr);
}
// Prototype
Std_ReturnType Csm_MacGenerate_CsmPrimitives_GEN_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                                 Csm_DataPtr dataPtr, uint32 dataLength, Csm_DataPtr macPtr,
                                                 uint32* macLengthPtr);

/* HIS METRIC PARAM VIOLATION IN Csm_MacGenerate_CsmPrimitives_GEN_OPTIMIZED: Interface parameters
are defined in AR specification and cannot be modified.*/
Std_ReturnType Csm_MacGenerate_CsmPrimitives_GEN_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                                 Csm_DataPtr dataPtr, uint32 dataLength, Csm_DataPtr macPtr,
                                                 uint32* macLengthPtr)
{
    /* MR12 RULE 11.8 VIOLATION: cast cannot be avoided because of AUTOSAR definition */
    return Csm_MacGenerate(jobId, mode, dataPtr, dataLength, (uint8*)macPtr, macLengthPtr);
}

// Prototype
Std_ReturnType Csm_MacVerify_CsmPrimitives_VER_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                               Csm_DataPtr dataPtr, uint32 dataLength, Csm_DataPtr macPtr,
                                               const uint32 macLength, Crypto_VerifyResultType* verifyPtr);

/* HIS METRIC PARAM VIOLATION IN Csm_MacVerify_CsmPrimitives_VER_OPTIMIZED: Interface parameters
are defined in AR specification and cannot be modified.*/
Std_ReturnType Csm_MacVerify_CsmPrimitives_VER_OPTIMIZED(uint32 jobId, Crypto_OperationModeType mode,
                                               Csm_DataPtr dataPtr, uint32 dataLength, Csm_DataPtr macPtr,
                                               const uint32 macLength, Crypto_VerifyResultType* verifyPtr)
{
    return Csm_MacVerify(jobId, mode, dataPtr, dataLength, macPtr, macLength, verifyPtr);
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

