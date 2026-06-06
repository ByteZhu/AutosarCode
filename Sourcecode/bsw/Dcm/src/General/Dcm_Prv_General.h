
#ifndef DCM_PRV_GENERAL_H
#define DCM_PRV_GENERAL_H

/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
*/

/* Macros for the service identifiers in DSP */

#define  DCM_DSP_SID_ECURESET                           0x11u
#define  DCM_DSP_SID_TESTERPRESENT                      0x3Eu
#define  DCM_DSP_SID_SECURITYACCESS                     0x27u
#define  DCM_DSP_SID_CONTROLDTCSETTING                  0x85u
#define  DCM_DSP_SID_READDTCINFORMATION                 0x19u
#define  DCM_DSP_SID_COMMUNICATIONCONTROL               0x28u
#define  DCM_DSP_SID_READDATABYIDENTIFIER               0x22u
#define  DCM_DSP_SID_READDATABYPERIODICIDENTIFIER       0x2Au
#define  DCM_DSP_SID_WRITEDATABYIDENTIFIER              0x2Eu
#define  DCM_DSP_SID_DIAGNOSTICSESSIONCONTROL           0x10u
#define  DCM_DSP_SID_CLEARDIAGNOSTICINFORMATION         0x14u
#define  DCM_DSP_SID_DYNAMICALLYDEFINEDATAIDENTIFIER    0x2Cu
#define  DCM_DSP_SID_INPUTOUTPUTCONTROLBYIDENTIFIER     0x2Fu
#define  DCM_DSP_SID_REQUESTDOWNLOAD                    0x34u
#define  DCM_DSP_SID_REQUESTUPLOAD                      0x35u
#define  DCM_DSP_SID_REQUESTTRANSFEREXIT                0x37u
#define  DCM_MINSIZE                                    0x00u
#define  DCM_MAXSIZE                                    0x04u
#define  DCM_IOCBI_INIT                                 0xFFu
#define  DCM_VALUE_NULL                                 0x00u

/* API Id to report development errors to DET module. */
#define DCM_GETVERSIONINFO_ID       0x24u
#define DCM_MAINFUNCTION_ID         0x25u


#define DCM_DEFAULT_VALUE                   0x00u
#define DCM_NEGRESPONSE_INDICATOR           0x7Fu
#define DCM_NEGATIVE_RESPONSE_LENGTH        0x03u

/* API ID for OBD services in order to report development errors to DET module */
#define DCM_OBDMODE01_ID    0x81u
#define DCM_OBDMODE02_ID    0x82u
#define DCM_OBDMODE37A_ID   0x83u
#define DCM_OBDMODE04_ID    0x84u
#define DCM_OBDMODE06_ID    0x86u
#define DCM_OBDMODE08_ID    0x88u
#define DCM_OBDMODE09_ID    0x89u

/* error ids for DET API interfaces, OBD services report the development errors to DET module */
#define DCM_E_INTERFACE_TIMEOUT                   0x01u
#define DCM_E_INTERFACE_RETURN_VALUE              0x02u
#define DCM_E_INTERFACE_BUFFER_OVERFLOW           0x03u
#define DCM_E_UNINIT                              0x05u
#define DCM_E_PARAM                               0x06u
#define DCM_E_PARAM_POINTER                       0x07u
#define DCM_E_INIT_FAILED                         0x08u
#define DCM_E_SET_PROG_CONDITIONS_FAIL            0x09u
#define DCM_E_MIXED_MODE                          0x0Au
#define DCM_E_WRONG_STATUSVALUE                   0x0Bu
#define DCM_E_PROTOCOL_NOT_FOUND                  0x0Cu
#define DCM_E_NVM_UPDATION_NOT_OK                 0x0Du
#define DCM_E_FULLCOMM_DISABLED                   0x0Eu
#define DCM_E_PROTOCOL_NOT_STARTED                0x10u
#define DCM_E_PSUEDO_RECEPTION                    0x11u
#define DCM_E_SERVICE_TABLE_NOT_SET               0x12u
#define DCM_E_SESSION_NOT_CONFIGURED              0x13u
#define DCM_E_SUBNET_NOT_SUPPORTED                0x14u
#define DCM_E_DDDI_NOT_CONFIGURED                 0x15u
#define DCM_E_EXCEEDED_MAX_RECORDS                0x16u
#define DCM_E_NOT_SUPPORTED_IN_CURRENT_SESSION    0x17u
#define DCM_E_INVALID_ADDRLENGTH_FORMAT           0x18u
#define DCM_E_CONTROL_FUNC_NOT_CONFIGURED         0x19u
#define DCM_E_INVALID_CONTROL_PARAM               0x1Au
#define DCM_E_NO_WRITE_ACCESS                     0x1Bu
#define DCM_E_RET_E_INFRASTRUCTURE_ERROR          0x1Cu
#define DCM_E_INVALID_CONTROL_DATA                0x1Du
/* error Ids for DET API interfaces, Rdbi service report the development errors to DET module */
#define DCM_E_RET_E_NOT_OK                        0x1Eu
#define DCM_E_DCMRXPDUID_RANGE_EXCEED             0x20u
#define DCM_E_DCMTXPDUID_RANGE_EXCEED             0x21u
#define DCM_E_NO_READ_ACCESS                      0x22u
#define DCM_E_SERVICE_TABLE_OUTOFBOUNDS           0x23u
#define DCM_E_SECURITYLEVEL_OUTOFBOUNDS           0x24u
#define DCM_E_RET_E_PENDING                       0x25u
#define DCM_E_INVALID_LENGTH                      0x26u
#define DCM_E_FORCE_RCRRP_IN_SILENT_COMM          0x27u
#define DCM_E_ENABLEDTCRECORD_FAILED              0x28U
#define DCM_E_SUBNODE_NOT_SUPPORTED               0x29u

/* error ids for DET Runtime errors according to AR 19-11 */
#define DCM_E_INVALID_VALUE                       0x01U


#define DCM_MAXNUMRESPONSEPENDING                 0xFFu

#define DCM_SERVICEID_DEFAULT_VALUE         0xFFu

#define DCM_ENDIANNESSCONVERSION16(data) ((data) = rba_BswSrv_ByteOrderSwap16((uint16)(data)))
#define DCM_ENDIANNESSCONVERSION32(data) ((data) = rba_BswSrv_ByteOrderSwap32(data))

/* Abstraction to the MemSet and MemCopy Library function */
#define DCM_MEMCOPY(xDest_pv,xSrc_pcv,numBytes_u32)         (void)rba_BswSrv_MemCopy((xDest_pv),(xSrc_pcv),(uint32)(numBytes_u32))
#define DCM_MEMSET(xDest_pv,xPattern_u32,numBytes_u32)              (void)rba_BswSrv_MemSet((xDest_pv),(xPattern_u32),(uint32)(numBytes_u32))
#define DCM_UNUSED_PARAM(P)   ((void)(P))

/* Types of storing used for Jump to Boot */
#define DCM_NOTVALID_TYPE     0x00u  /* Boot Loader is not active */
#define DCM_WARMREQUEST_TYPE  0x01u  /* Warm Request Type */
#define DCM_WARMINIT_TYPE     0x02u  /* Warm Init Type */
#define DCM_WARMRESPONSE_TYPE 0x03u  /* Warm Response Type */

#define DCM_JUMPTOOEMBOOTLOADER            0x00u
#define DCM_JUMPTOSYSSUPPLIERBOOTLOADER 0x01u
#define DCM_JUMPDRIVETODRIVE            0x02u


#define DCM_NEGRESPONSE_INDICATOR       0x7Fu         /* Indication byte of negative response */

/*Service handler uses below mentioned DET API interface function to report the development error to DET Module */
#if (DCM_CFG_DET_SUPPORT_ENABLED == TRUE)
#define     DCM_DET_ERROR(DCM_ApiId, DCM_ErrorId)                                 \
                                        (void)Det_ReportError(DCM_MODULE_ID, DCM_INSTANCE_ID, DCM_ApiId, DCM_ErrorId);
#else
#define     DCM_DET_ERROR(DCM_ApiId, DCM_ErrorId)
#endif


#define     DCM_DET_RUNTIME_ERROR(DCM_ApiId, DCM_ErrorId)                                 \
                                        (void)Det_ReportRuntimeError(DCM_MODULE_ID, DCM_INSTANCE_ID, DCM_ApiId, DCM_ErrorId);



/**
 **************************************************************************************************
 * Dcm_ConfirmationRespPend: Function to call all RTE configured functions on reception of a forced response pend.
 *
 * \param           status: ConfirmationStatus of the forced resp pend
 *
 * \retval          Std_ReturnType
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

LOCAL_INLINE Std_ReturnType Dcm_ConfirmationRespPend(
        Dcm_ConfirmationStatusType status
);
LOCAL_INLINE Std_ReturnType Dcm_ConfirmationRespPend(
        Dcm_ConfirmationStatusType status
)
{

    /* Call DcmAppl function for response pend */
    DcmAppl_ConfirmationRespPend(status);
    return(E_OK);
}
/*
 **********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************
 */
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
boolean Dcm_Prv_IsDcmInitialized(void);
void Dcm_Prv_DcmInitialize(boolean value);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

void Dcm_Prv_Det(uint8 DCM_ApiId,uint8 DCM_ErrorId);

const Dcm_DslProtocolRowConfigType_tst* Dcm_Prv_GetProtocolRow(PduIdType rxpduId);

uint8 Dcm_Prv_GetProtocolIndex(uint8 connectionIdx_u8);

void Dcm_Prv_SetProtocolIndex(uint8 connectionIdx_u8, uint8 IdxCurrentProtocol_u8);

PduIdType Dcm_Prv_GetConnectionIndex(PduIdType rxpduId);

uint32 Dcm_Prv_GetRxBufferMaxLen(PduIdType rxpduId);

uint8 Dcm_Prv_GetsrvTabId(uint16 connectionIdx_u8);

void Dcm_Prv_SetActiveRxPduId(PduIdType rxpduId, PduLengthType requestLength);

extern PduIdType Dcm_Prv_GetActiveRxPduId(void);
Dcm_MsgType Dcm_Prv_GetActiveRxBuffer(void);

Dcm_MsgType Dcm_Prv_GetActiveTxBuffer(void);

PduIdType Dcm_Prv_GetActiveConnectionIndex(void);

void Dcm_General_Init(void);

uint32 Dcm_Prv_GetActiveRxBufferMaxLen(void);

uint32 Dcm_Prv_GetActiveTxBufferMaxLen(void);

uint8 Dcm_Prv_GetActiveSrvTabId(void);

uint8 Dcm_Prv_GetActiveReqType(void);

extern Dcm_ProtocolType Dcm_Prv_GetActiveProtocolType(void);

uint16 Dcm_Prv_GetProtocolMaxResponseSize(void);

uint8 Dcm_Prv_GetActiveDemClientId(void);

uint8 Dcm_Prv_GetActiveProtocolPriority(void);

uint32 Dcm_Prv_GetActive_P2ServerTimeAdjust(void);

uint32 Dcm_Prv_GetActive_P2StrServerTimeAdjust(void);

uint16 Dcm_Prv_GetActiveConnectionId(void);

uint8 Dcm_Prv_GetActiveComMChannelId(void);

uint8 Dcm_Prv_GetActiveComMChannelIndex(void);

PduIdType Dcm_Prv_GetActiveTxPduId(void);

PduIdType Dcm_Prv_GetTxPduId(PduIdType rxpduId);

uint16 Dcm_Prv_GetActiveTesterSrcAddress(void);

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
uint16 Dcm_Prv_GetObdActiveTesterSrcAddress(void);
#endif

uint16 Dcm_Prv_GetTesterSrcAddress(uint8 connectionIdx_u8);

uint16 Dcm_Prv_GetTesterSrcAddressFromRxPduId(PduIdType rxpduId);

const Dcm_DslPeriodicConnConfigType_tst* Dcm_Prv_GetActivePeriodicConnection(void);

const Dcm_DslRoeConnConfigType_tst* Dcm_Prv_GetActiveRoeConnection(void);

const Dcm_DslProtocolRowConfigType_tst* Dcm_Prv_GetActiveRdpiProtocolRow(void);

const Dcm_DslProtocolRowConfigType_tst* Dcm_Prv_GetActiveRoeProtocolRow(void);

const uint8* Dcm_Prv_GetMaxNumRespPending(void);
boolean Dcm_Prv_GetRespOnSecondDeclinedRequest(PduIdType rxpduId);

void Dcm_Prv_SetProtocolStatus(boolean protocolStatus_b);

boolean Dcm_Prv_IsProtocolStarted(void);

PduLengthType Dcm_Dsl_Prv_GetActiveRequestDataLen(void);
void Dcm_Dsl_Prv_SetActiveRequestDataLen(PduLengthType reqDataLength);

void Dcm_Prv_SetActiveConnectionIdx(PduIdType rxpduId, PduIdType connectionIdx);
void Dcm_Prv_SetMainConnection(PduIdType connectionIdx);

uint8_least Dcm_Prv_Get_CurrentProtocolIndex(void);
void Dcm_Prv_Update_ProtocolIndex(uint8_least idxCurrentProtocol_u8);

const Dcm_DslMainConnConfigType_tst* Dcm_Prv_GetMainConnection(PduIdType rxpduId);
const Dcm_DslMainConnConfigType_tst * Dcm_Prv_GetActiveConnection(void);
const uint8 * Dcm_GetSecurityLookupTable(void);
const uint8 * Dcm_GetSessionLookupTable(void);
const uint8 * Dcm_GetKWPSessionLookupTable(void);

boolean Dcm_Prv_IsCommunicationActive(void);
void Dcm_Prv_SetCommunicationState(boolean flagCommActive_b);
boolean Dcm_Prv_IsP3TimerMonitorRequired(void);
void Dcm_Prv_SetP3TimerMonitorFlag(boolean flgMonitorP3timer_b);
uint32 Dcm_Prv_Get_DataTimeOut(void);
void Dcm_Prv_Set_DataTimeOut(uint32 dataTimeOutMonitor_u32);
boolean DCM_IS_KWPPROT_ACTIVE(void);
void Dcm_Prv_ReloadS3Timer (void);
boolean Dcm_Prv_isForcePendingResponse(void);

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
const Dcm_DslProtocolRowConfigType_tst * Dcm_Prv_GetObdActiveProtocolRow(void);
const Dcm_DslMainConnConfigType_tst * Dcm_Prv_GetObdActiveConnection(void);
void Dcm_Prv_SetObdActiveRxPduId(PduIdType rxpduId, PduLengthType requestLength);
PduIdType Dcm_Prv_GetObdActiveTxPduId(void);
void Dcm_Prv_ResetObdActiveRxPduId(void);
uint8 Dcm_Prv_GetObdActiveProtocolPriority(void);
PduIdType Dcm_Prv_GetObdActiveRxPduId(void);
#endif


#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
void Dcm_Prv_SetRxBuffer(Dcm_MsgType  Dcm_DslBufferPtr_pu8);
#endif

/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 * Dcm_IsInfrastructureErrorPresent_b : API to check for infrastructure error
 * @param           dataInfrastrutureCode_u8 : Parameter to be checked for infrastructure Error
 * @retval          boolean
 *                  TRUE : if infrastructure error is present
 *                  FALSE : if infrastructure error is not present
 */

boolean Dcm_IsInfrastructureErrorPresent_b(uint8 dataInfrastrutureCode_u8);

boolean Dcm_Prv_IsDcmDslConnectionGeneric(PduIdType DcmRxPduId);
void Dcm_Prv_UpdateMetaData_Nrc21(PduIdType DcmRxPduId,uint8** MetaDataPtr);
void Dcm_Prv_UpdateMetaDataPointer(PduIdType DcmRxPduId,uint8** MetaDataPtr);
void Dcm_Prv_SetSourceAndTargetAddress(PduIdType DcmRxPduId, const PduInfoType* info);
void Dcm_Prv_SetSourceAndTargetAddress_NRC21(PduIdType DcmRxPduId, const PduInfoType* info);
void Dcm_Prv_SetSourceAndTargetAddressWarmStart(PduIdType DcmDslConnectionIdx, uint16 TesterSourceAddress);
#endif

