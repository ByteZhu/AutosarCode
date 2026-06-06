

#ifndef DCM_PRV_TYPES_H
#define DCM_PRV_TYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Rte_Dcm_Type.h"

/*
 **********************************************************************************************************************
 * Typedefs
 **********************************************************************************************************************
 */

typedef enum
{
    DCM_POS_RESPONSE,                          /* POS response */
    DCM_NEG_RESPONSE,                          /* NEG response */
    DCM_MAXPENDING_EXEEDED                     /*General Reject after Max Resp Pend*/
}Dcm_DsdResponseType_ten;



typedef struct
{
    boolean dataResponseByDsd_b;
    Dcm_DsdResponseType_ten stResponseType_en;           /* Type of response (POS/NEG) */

}Dcm_DsdInternalStructureType_tst;


/*####################types from Dcm_Prv_Dsd.h ##############################*/
typedef enum
{
    DCM_BOOT_IDLE = 0,           /* IDLE state */
    DCM_BOOT_PROCESS_RESET,      /* Process the Store Type and Trigger Force Response Pend */
    DCM_BOOT_SENDFORCEDRESPPEND, /* State where ForcedRespPend can be triggered */
    DCM_BOOT_WAIT,               /* Wait for confirmation of Response Pend */
    DCM_BOOT_STORE_WARMREQ,      /* Store Request for Warm Request type */
    DCM_BOOT_STORE_WARMINIT,     /* Store protocol information for Warm Init Type */
    DCM_BOOT_STORE_WARMRESP,     /* Store Response for Warm Response Type */
    DCM_BOOT_ERROR,              /* Process the error happened before the jump */
    DCM_BOOT_WAIT_FOR_RESET,     /* Wait till the reset happens*/
    DCM_BOOT_PERFORM_RESET,       /* State to do reset in case of Warm Request/Response */
    DCM_BOOT_PREPARE_RESET       /* State to check for conditions to send Forced RespPend before reset for  Warm Request/Response */
}Dcm_BootLoaderStates_ten;



typedef enum
{
    DCM_QUEUE_IDLE,                          /* Queue is idle */
    DCM_QUEUE_RUNNING,                       /* QUeuing is taking place */
    DCM_QUEUE_COMPLETED                      /* QUeuing is completed, i.e. the second request is received */
}Dcm_DsldQueHandling_ten;


typedef struct
{
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    Dcm_MsgType  adrBufferPtr_pu8;                      /* pointer to hold the address of the processing request buffer */
#endif
    PduIdType dataActiveRxPduId_u8;                     /* Rx PDU Id on which request received  */
    uint8 nrActiveConn_u8;                            /* Active Connection number  */
    uint8 idxActiveSession_u8;                     /* Active sessions index in session lookup table  */
    boolean flgMonitorP3timer_b;                       /* Bit to indicate P3 timer monitoring required  */
    uint8 idxCurrentProtocol_u8;                       /* Active protocol index */
    PduIdType dataActiveTxPduId_u8;                     /* Tx PDU Id on which request received  */
    uint8 datActiveSrvtable_u8;                        /* Active service table */
    boolean flgCommActive_b;                           /* Is communication or protocol active? */
    uint8 cntrWaitpendCounter_u8;                       /* Wait pend counter */
    Dcm_DsdResponseType_ten stResponseType_en;           /* Type of response (POS/NEG) */
    uint8 idxActiveSecurity_u8;                    /* Active security index in security lookup table */
    Std_ReturnType dataResult_u8;                       /* Confirmation result */
    uint8 idxService_u8;                            /* Active services index in active service table */
    boolean dataResponseByDsd_b;                        /* Response given by DSD                         */
    uint8 dataSid_u8;                                    /* Requested Sid  */
#if((DCM_ROE_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF))
    uint8  dataOldSrvtable_u8;                          /* Service table which is running when event response */
#endif
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    boolean flgPagedBufferTxOn_b;                      /* Bit to indicate Paged buffer Tx in progress         */
#endif
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    PduIdType dataNewRxPduId_u8;                        /* High protocols Rx PDU id */
#if((DCM_ROE_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF))
    PduIdType dataPassRxPduId_u8;                       /* Active Roe's Rx PDU id */
#endif
#endif
    PduLengthType dataRequestLength_u16;                /* Length of request */
    PduIdType dataOldtxPduId_u8;                         /* Copy of the old active Tx PDU in DCM */
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    Dcm_MsgLenType dataCurrentPageRespLength_u32;          /* Amount of data filled by the service       */
#endif
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    PduLengthType dataNewdataRequestLength_u16;             /* Request length of high priority protocols request */
#endif
#if((DCM_ROE_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF))
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    PduLengthType dataPassdataRequestLength_u16;            /* Request length of bypassing ROE request */
#endif
    uint32 dataTimerTimeout_u32;                      /* If ROE requested service unable to send */
#endif
    Dcm_MsgType adrActiveTxBuffer_tpu8;                /* Active Tx buffer pointer */
    uint32 dataTimeoutMonitor_u32;                      /* It holds the timeout time */
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
    uint32 datRoeType2Timeout_u32;                   /* Roe timer for type2 */
#endif
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    uint32 dataPagedBufferTimeout_u32;                 /* Paged buffer timer                                  */
#endif
    uint8  PreviousSessionIndex;                     /*sessions index for old Session   */

}Dcm_DsldInternalStructureType_tst;


typedef struct
{
    PduIdType dataActiveRxPduId_u8;                     /* Rx PDU Id on which request received  */
    uint8 nrActiveConn_u8;                              /* Active Connection number  */
    uint8 idxCurrentProtocol_u8;                        /* Active protocol index */
    PduIdType dataActiveTxPduId_u8;                     /* Tx PDU Id on which request received  */
    uint8 datActiveSrvtable_u8;                         /* Active service table */
    boolean flgCommActive_b;                            /* Is communication or protocol active? */
    uint8 cntrWaitpendCounter_u8;                       /* Wait pend counter */
    Dcm_DsdResponseType_ten stResponseType_en;         /* Type of response (POS/NEG) */
    Std_ReturnType dataResult_u8;                       /* Confirmation result */
    uint8 idxService_u8;                                /* Active services index in active service table */
    boolean dataResponseByDsd_b;                        /* Response given by DSD */
    uint8 dataSid_u8;                                   /* Requested Sid  */
    PduLengthType dataRequestLength_u16;                /* Length of request */
    PduIdType dataOldtxPduId_u8;                        /* Copy of the old active Tx PDU in DCM */
    Dcm_MsgType adrActiveTxBuffer_tpu8;                 /* Active Tx buffer pointer */
    uint32 dataTimeoutMonitor_u32;                      /* It holds the timeout time */
}Dcm_OBDInternalStructureType_tst;


typedef enum
{
    DCM_OBD_IDLE,                   /* Default state */
    DCM_OBD_REQUESTRECEIVING,       /* Reception of OBD request in ongoing */
    DCM_OBD_REQUESTRECEIVED,        /* Reception of OBD request is completed */
    DCM_OBD_VERIFYDATA,             /* Verification of received OBD request */
    DCM_OBD_PROCESSSERVICE,         /* Service Interpreter is called here */
    DCM_OBD_WAITFORTXCONF           /* Response is Transmitted , waiting for Confirmation */
} Dcm_OBDStateMachine_tst;

typedef struct
{
    PduInfoType Dcm_DslRxPduBuffer_st;
    uint8       Dcm_DslServiceId_u8;
    boolean     Dcm_DslCopyRxData_b;
    PduIdType   Dcm_RxPduId;
}Dcm_DslOBDRxPduArray_tst;

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
typedef struct
{
    Dcm_DsldQueHandling_ten Dcm_QueHandling_en;         /* State handler for queue */
    Dcm_MsgType  adrBufferPtr_pu8;                      /* pointer to hold the address of the queuing buffer */
    PduLengthType dataQueueReqLength_u16;                /* Length of request */
    PduIdType dataQueueRxPduId_u8;                     /* Rx PDU Id on which request received  */
    uint8 idxBufferIndex_u8;                          /* index to point to the buffer */
}Dcm_QueueStructure_tst;
#endif

typedef struct
{
    PduInfoType Dcm_DslRxPduBuffer_st;
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    Dcm_MsgType  Dcm_DslBufferPtr_pu8;        /* pointer to hold the address of the normal buffer(non-queue) */
#endif
    uint8      Dcm_DslServiceId_u8;
    boolean     Dcm_DslFuncTesterPresent_b;
    boolean     Dcm_DslCopyRxData_b;
}Dcm_DslRxPduArray_tst;

typedef struct
{
    uint32 dataTimeoutP2StrMax_u32;                     /* P2* max time in us */
    uint32 dataTimeoutP2max_u32;                        /* P2 max time in us */
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    uint32 dataTimeoutP3max_u32;                        /* P3 max time in us */
#endif
}Dcm_DsldTimingsType_tst;

typedef struct
{
    Dcm_MsgType TxBuffer_tpu8;                        /* Pointer to Tx buffer */
    Dcm_MsgLenType TxResponseLength_u32 ;             /* Length of response including Sid */
    boolean  isForceResponsePendRequested_b;          /* Application triggered wait pend */
}Dcm_DslTxType_tst;

typedef struct
{
    Dcm_MsgType TxBuffer_tpu8;                        /* Pointer to Tx buffer */
    Dcm_MsgLenType TxResponseLength_u32 ;             /* Length of response including Sid */
}Dcm_OBDTxType_tst;


typedef struct
{
    uint8   EventId_u8;/*Event Id reported from the apllication*/
    boolean Is_Queued;/*Will indocate whether the event is waiting to trigger the service to respond to*/
    boolean Is_Processed;/*Will indocate whether the event is waiting to trigger the service to respond to*/
    PduIdType   RxPduId_u8;/*protocol id tobe used for the reported event*/

} Dcm_DcmDspEventWaitlist_t;

typedef enum
{
    DCM_RDPI_NO_TRANMISSION,
    DCM_RDPI_SLOW_RATE,
    DCM_RDPI_MEDIUM_RATE,
    DCM_RDPI_FAST_RATE
}Dcm_RdpiTxModeType_ten;

typedef struct
{
  uint32 cntrTime_u32;         /* Increment in each time raster if the overflowValue > 0 */
  uint16 dataId_u16;             /* periodicId */ /*---dataRdpiId_u16 */
  uint16 idxPeriodicId_u16;          /* Index of the periodic ID in Dcm_DIDConfig Table */
  Dcm_RdpiTxModeType_ten dataOverflowValue_en;  /* Off: -1, SlowRate, MediumRate, FastRate */
  boolean dataRange_b;          /*Flag to indicate if the did is a range did or not*/
  PduIdType dcmRxPduId;         /* The PduId in which the RDPI request is received - needed for authentication checks */
} Dcm_PeriodicInfoType_tst;


typedef uint8  Dcm_ReturnClearDTCType_tu8;

/*####################end types from Dcm_Prv.h  ##########################################*/




































/* Confirmation types */
typedef enum
{
    DSD_MANUFACTURE_CONFIRMATION_E=0,
    DSD_SUPPLIER_CONFIRMATION_E
}Dcm_DsdConfirmationType_ten;

typedef struct
{
Dcm_ProtocolType protocolType;
Dcm_MsgType reqData;
Dcm_MsgType rspData;
uint8 reqType_u8;
uint8 srvTabId_u8;
uint16 connectionId_u16;
uint16 testerSrcAddress_u16;
PduIdType dcmRxPduId;
Dcm_MsgLenType reqDataLen;
Dcm_MsgLenType resMaxDataLen;
}Dcm_DsdContextType;








/* DSL State Machine */
typedef enum
{
    DSL_STATE_IDLE_E=0,
    DSL_STATE_WAITFOR_RXINDICATION_E,
    DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E,
    DSL_STATE_P2MAX_TIMEMONITORING_E,
    DSL_STATE_PREEMPTION_STOPPROTOCOL_E,
    DSL_STATE_PREMMPTION_STOPROE_E,
    DSL_STATE_WAITFOR_TXCONFIRMATION_E,
    DSL_STATE_ROETYPE1_RECEIVED_E,
    DSL_STATE_RESPONSETRANSMISSION_E,
#if (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    DSL_STATE_PAGEDBUFFER_TRANSMISSION_E
#endif
}Dcm_DslStatesType_ten;

/* DSL Protocol Preemption State Machine */
typedef enum
{
    DSL_PREEMPTION_STATE_IDLE_E = 0,
    DSL_PREEMPTION_HIGHPRIORITY_REQUESTRECEIVED_E,
    DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E,
    DSL_PREEMPTION_STOP_ROE_E
}Dcm_DslProtocolPreemptionStatesType_ten;


typedef enum
{
    DSL_SUBSTATE_DATA_READY_E =0,
    DSL_SUBSTATE_WAIT_FOR_DATA_E,
    DSL_SUBSTATE_WAIT_PAGE_TXCONFIRM_E

}Dcm_DslSubStatesType_ten;


/* Private types needed for Service 0x29 - Authentication */

typedef enum
{
    DCM_CHECK_SERVICE = 1,
    DCM_CHECK_SUBSERVICE = 2,
    DCM_CHECK_DID = 3,
    DCM_CHECK_RID = 4,
    DCM_CHECK_MEMSELN = 5
}Dcm_AccessRightsCheckType_ten;














typedef enum
{
    DCM_DEAUTHENTICATE = 0x00u,
    DCM_VERIFY_CERTIFICATE_UNIDIRECTIONAL = 0x01u,
    DCM_VERIFY_CERTIFICATE_BIDIRECTIONAL = 0x02u,
    DCM_PROOF_OF_OWNERSHIP = 0x03u,
    DCM_AUTHENTICATION_CONFIGURATION = 0x08u
}Dcm_AuthSubServiceType_ten;

typedef enum
{
    DCM_AUTH_REQUEST_ACCEPTED = 0x00u,
    DCM_AUTH_GENERAL_REJECT = 0x01u,
    DCM_AUTHENTICATION_CONFIG_APCE = 0x02u,
    DCM_AUTHENTICATION_CONFIG_ACR_ASYMMETRIC = 0x03u,
    DCM_AUTHENTICATION_CONFIG_ACR_SYMMETRIC = 0x04u,
    DCM_DEAUTHENTICATION_SUCCESSFUL = 0x10u,
    DCM_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY = 0x11u,
    DCM_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE = 0x12u,
    DCM_CERTIFICATE_VERIFIED = 0x13u
}Dcm_AuthReturnParameterType_ten;

typedef enum
{
    DCM_ASYNCH_OPERATION_INACTIVE = 0x00u,
    DCM_ASYNCH_OPERATION_ACTIVE = 0x01u,
    DCM_ASYNCH_OPERATION_COMPLETED = 0x02u
}Dcm_AuthAsynchOpStatusType_ten;

typedef enum
{
    DCM_CSMASYNCJOBFINISHED_API_ID = 0x24,
    DCM_KEYMASYNCCERTIFICATEVERIFYFINISHED_API_ID = 0x25
}Dcm_DetReportApiIdType_ten;

typedef enum
{
    DCM_ACCESSRIGHTS_READ = 0x01,
    DCM_ACCESSRIGHTS_WRITE = 0x02
}Dcm_AuthAccessType_ten;

typedef enum
{
    DCM_ROLE = 0x00,  /* DCM_ROLE shall always the first element with value 0. This is used a a reference to loop over all the certificate element types */
    DCM_WHITELIST_SERVICE = 0x01,
    DCM_WHITELIST_DID = 0x02,
    DCM_WHITELIST_RID = 0x03,
    DCM_WHITELIST_MEMSELN = 0x04,
    DCM_NUM_CERT_ELEMENT_TYPE = 0x05, /* Used to determine the number of certificate element types. Place this always after the last valid certificate element type */
    DCM_INVALID_CERT_ELEMENT = 0x06
}Dcm_CertElementType_ten;

typedef struct
{
    Dcm_CertElementType_ten type_en;
    uint16 id_u16;
    uint8 *data_pau8;
    uint8 *dataNumEntry_pu8;
    uint8 dataLength_u8;
    uint8 dataMaxLength_u8;
    uint8 childDataMaxLength_u8;
    uint8 *offset_pau8;
    uint8 offsetLength_u8;
}Dcm_CertElementType_tst;

typedef enum
{
    DCM_READ_CERT_ELEMENT_FIRST = 0x00u,
    DCM_READ_CERT_ELEMENT_NEXT = 0x01u
}Dcm_CertElementInstanceType_ten;

typedef enum
{
    READ_CERT_ELEMENT_CHILD_NOT_OK = 0x00u,
    READ_CERT_ELEMENT_CHILD_OK_CONTINUE = 0x01u,
    READ_CERT_ELEMENT_CHILD_NOT_AVAILABLE_STOP = 0x02u
}Dcm_AuthReadChildReturnType_ten;

typedef enum
{
    DCM_VERIFY_CERTIFICATE_IDLE = 0u,
    DCM_VERIFY_CERTIFICATE_CLIENT = 1u,
    DCM_GENERATE_CHALLENGE_SERVER = 2u,
    DCM_GENERATE_PROOF_OF_OWNERSHIP_SERVER = 3u
}Dcm_stVerfiyCertificate_ten;

typedef enum
{
    DCM_TIMER_START = 1,
    DCM_TIMER_PROCESS = 2,
    DCM_TIMER_STOP = 3
}Dcm_TimerActionType_ten;



typedef struct
{
    boolean isTimerActive_b;
    StatusType timerCounterStatus;
    uint32 timer_u32;
    uint32 startTick_u32;
}Dcm_AuthDefaultSessionIdleTimerInfoType_tst;

/*end Private types needed for Service 0x29 - Authentication */



/* Private types needed for Service 0x31 - RoutineControl */





typedef enum
{
    DCM_ROUTINE_IDLE = 0,
    DCM_ROUTINE_STARTED = 1,
    DCM_ROUTINE_STOPPED = 2,
    DCM_ROUTINE_STOP_PENDING = 3
} Dcm_RoutineStatusType_ten;

typedef enum
{
    DCM_START_ROUTINE = 1,
    DCM_STOP_ROUTINE = 2,
    DCM_REQUEST_RESULTS = 3
} Dcm_RoutineSubFunctionType_ten;

/* end Private types needed for Service 0x31 - RoutineControl */

/* start  Private types from DcmDspUds_Uds_Prot.h */

#endif /* DCM_PRV_TYPES_H */
