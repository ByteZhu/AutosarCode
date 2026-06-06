
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#if(DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
#include "SchM_Dcm.h"
#endif
#include "Rte_Dcm.h"
#include "ComM_Dcm.h"
#include "Dcm_Prv.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define DCM_START_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"
static uint8 s_Dcm_DslCurrentProtocol_u8 = DCM_NO_ACTIVE_PROTOCOL;
#define DCM_STOP_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"
static uint16 s_Dcm_DslCurrentTesterSourceAddress_u16 = 0;
static uint16 s_Dcm_DslCurrentConnectionId_u16 = 0;
#define DCM_STOP_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static uint8 s_Dcm_DslRespPendingCounter_u8;
static uint8 s_activeSession_u8;
static Std_ReturnType s_cancelTransmit;

static uint8 Dcm_Dsl_MaxNumRespPendingBuffer_au8[DCM_NEGATIVE_RESPONSE_LENGTH];
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
#endif
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
static boolean s_Dcm_isStopProtocolInvoked_b;
static boolean s_RetryTransmission_b;
static boolean s_isResponsePending_b;
static boolean s_Dcm_InfinitePendingFlag_b;
#if(DCM_ROE_ENABLED == DCM_CFG_ON)
static boolean flgRoeOn_b;
static boolean flgPersistRoe_b;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_DslStatesType_ten s_Dcm_DslState_en;
static Dcm_DslSubStatesType_ten s_Dcm_DslSubState_en;
static Dcm_DslProtocolPreemptionStatesType_ten s_Dcm_DslPreemptionState_en;
static const PduInfoType* Dcm_Dsl_RetryRespTransmission_st;
Dcm_DsldTimingsType_tst Dcm_DsldTimer_st;
StatusType Dcm_P2OrS3TimerStatus_uchr;
static PduIdType s_activeTxPduId;

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
StatusType Dcm_OBDP2OrS3TimerStatus_uchr;
#endif

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
Dcm_Dsld_KwpTimerServerType Dcm_DsldKwpReqTiming_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
#endif

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
 */
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/***********************************************************************************************************************
 Function name    : Dcm_Prv_Check_PendingResponseForKWP
 Syntax           : Dcm_Prv_Check_PendingResponseForKWP(void)
 Description      : This inline function is used to check whether pending response is for KWP service
 Parameter        : None
 Return value     : boolean
 ***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_Check_PendingResponseForKWP(void)
{
    boolean RetVal_b = TRUE;

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))

    if((DCM_IS_KWPPROT_ACTIVE() != FALSE) && (Dcm_isFirstReponseSent_b != FALSE))
    {
        Dcm_KWPConfirmationForSplitResp(DCM_RES_POS_NOT_OK);
        Dcm_isFirstReponseSent_b = FALSE;
    }
    else
#endif
    {
        RetVal_b = FALSE;
    }

    return RetVal_b;
}

void Dcm_Prv_SetInfinitePendingFlag(boolean value)
{
    s_Dcm_InfinitePendingFlag_b = value;
}

boolean Dcm_Prv_GetInfinitePendingFlag(void)
{
    return s_Dcm_InfinitePendingFlag_b;
}

void Dcm_Prv_NoActiveProtocol(void)
{
    s_Dcm_DslCurrentProtocol_u8 = DCM_NO_ACTIVE_PROTOCOL;
}

uint8 Dcm_Prv_GetCurrentProtocol(void)
{
    return s_Dcm_DslCurrentProtocol_u8;
}

uint16 Dcm_Prv_GetCurrentTesterSourceAddress(void)
{
    return s_Dcm_DslCurrentTesterSourceAddress_u16;
}

uint16 Dcm_Prv_GetCurrentConnectionID(void)
{
    return s_Dcm_DslCurrentConnectionId_u16;
}

void Dcm_Prv_SetCurrentProtocol(uint8 Dcm_ActiveProtocol)
{
    s_Dcm_DslCurrentProtocol_u8 = Dcm_ActiveProtocol;
}

void Dcm_Dsl_Prv_SetDslState(Dcm_DslStatesType_ten DslState_en)
{
    s_Dcm_DslState_en = DslState_en;
}

Dcm_DslStatesType_ten Dcm_Dsl_Prv_GetDslState(void)
{
    return s_Dcm_DslState_en;
}

void Dcm_Dsl_Prv_SetDslSubState(Dcm_DslSubStatesType_ten DslSubState_en)
{
    s_Dcm_DslSubState_en = DslSubState_en;
}

Dcm_DslSubStatesType_ten Dcm_Dsl_Prv_GetDslSubState(void)
{
    return s_Dcm_DslSubState_en;
}



void Dcm_Dsl_Prv_SetPreemptionState(Dcm_DslProtocolPreemptionStatesType_ten dslPreemptionState_en)
{
    s_Dcm_DslPreemptionState_en = dslPreemptionState_en;
}

Dcm_DslProtocolPreemptionStatesType_ten Dcm_Dsl_Prv_GetPreemptionState(void)
{
    return s_Dcm_DslPreemptionState_en;
}

void Dcm_Dsl_Prv_SetRespPendingCounterValue(uint8 RespPendingCounter_u8)
{
    s_Dcm_DslRespPendingCounter_u8 = RespPendingCounter_u8;
}

uint8 Dcm_Dsl_Prv_GetRespPendingCounterValue(void)
{
    return s_Dcm_DslRespPendingCounter_u8;
}

void Dcm_Dsl_Prv_isRetryTransmission(const PduInfoType * retryRespTransission_pcst, boolean retryTransmission_b)
{
    Dcm_Dsl_RetryRespTransmission_st = retryRespTransission_pcst;
    s_RetryTransmission_b = retryTransmission_b;
}

boolean Dcm_Dsl_Prv_isItPendingResponse(void)
{
    return s_isResponsePending_b;
}

void Dcm_Dsl_Prv_SetPendingResponse(boolean pendingResponseStatus)
{
    s_isResponsePending_b = pendingResponseStatus;
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3313] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3989] */
void Dcm_Dsl_Prv_CheckFor_ProtocolPreemption(void)
{
    if(DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E == s_Dcm_DslPreemptionState_en)
    {
        s_cancelTransmit = Dcm_Dsl_Prv_CancelOnGoingTransmission(s_activeTxPduId, s_Dcm_DslCurrentProtocol_u8);
        if(E_NOT_OK == s_cancelTransmit)
        {
            /* When cancellation of ongoing transmission is not successfull Dcm_StopProtocol() would be
             * called with active protocol information */
            s_Dcm_isStopProtocolInvoked_b = TRUE;
        }

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
        if(DSL_STATE_ROETYPE1_RECEIVED_E == s_Dcm_DslState_en)
        {
            flgRoeOn_b = TRUE;
        }
#endif

        s_Dcm_DslState_en = DSL_STATE_PREEMPTION_STOPPROTOCOL_E;
    }
#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    else
    {
        if(DSL_PREEMPTION_STOP_ROE_E == s_Dcm_DslPreemptionState_en)
        {
            if(DSL_STATE_ROETYPE1_RECEIVED_E == s_Dcm_DslState_en)
            {
                flgPersistRoe_b = TRUE;
                s_cancelTransmit = Dcm_Dsl_Prv_CancelOnGoingTransmission(s_activeTxPduId, s_Dcm_DslCurrentProtocol_u8);
                if(E_NOT_OK == s_cancelTransmit)
                {
                    /* When cancellation of ongoing transmission is not successfull Dcm_StopProtocol() would be
                     * called with active protocol information */
                    s_Dcm_isStopProtocolInvoked_b = TRUE;
                }
            }

            /* If high priority protocol request is arrived, stop ROE */
            s_Dcm_DslState_en = DSL_STATE_PREMMPTION_STOPROE_E;
        }
    }
#endif
}

static void Dcm_DslState_Preemption_StopROE(void)
{
#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    uint32 DataTimeoutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();
    PduIdType DcmRxPduId_u16          = Dcm_Prv_GetActiveRxPduId();
    uint8 ReqType_u8                  = Dcm_Prv_GetActiveReqType();
    uint16 ConnectionId_u16           = Dcm_Prv_GetActiveConnectionId();
    Dcm_IdContextType idContext_u8    = Dcm_Dsd_Prv_GetIdContext();
    Dcm_ProtocolType ProtocolType_u8  = Dcm_Prv_GetActiveProtocolType();
    PduIdType activeTxPduId;

    if(TRUE == flgPersistRoe_b)
    {

        /* Call  ROE confirmation because DCM killing ROE requested service */
        DcmAppl_DcmConfirmation(idContext_u8,ReqType_u8,ConnectionId_u16,DCM_RES_POS_NOT_OK,ProtocolType_u8,
                Dcm_Dsld_RoeRxToTestSrcMappingTable[DcmRxPduId_u16].testsrcaddr_u16);

        /* Go to next state to start protocol */
        s_Dcm_DslState_en = DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E;
        Dcm_Dsd_Prv_SetDsdState(DSD_IDLE_E);
        s_Dcm_DslPreemptionState_en = DSL_PREEMPTION_STATE_IDLE_E;

        /* If the ongoing transmission was cancelled in this state, the new request should not be processed in the
            current cycle as there is a chance that service can finish the processing in the same cycle and
            PduR_Transmit can return E_NOT_OK as transmission of old protocol is under progress */
        activeTxPduId = Dcm_Prv_GetActiveTxPduId();
        if((E_OK == s_cancelTransmit) && (s_activeTxPduId == activeTxPduId))
        {
            /* Break out of the state machine and the request will be processed in the next DCM cycle */
            DCM_TimerProcess(DataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr);
            Dcm_Prv_Set_DataTimeOut(DataTimeoutMonitor_u32);
        }
    }
#endif
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3313] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3989] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4502] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4503] */
static void Dcm_DslState_Preemption_StopProtocol(void)
{
    uint32 DataTimeoutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();
    PduIdType activeTxPduId;
#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    PduIdType DcmRxPduId_u16          = Dcm_Prv_GetActiveRxPduId();
    uint8 ReqType_u8                  = Dcm_Prv_GetActiveReqType();
    uint16 ConnectionId_u16           = Dcm_Prv_GetActiveConnectionId();
    Dcm_IdContextType idContext_u8    = Dcm_Dsd_Prv_GetIdContext();
    Dcm_ProtocolType ProtocolType_u8  = Dcm_Prv_GetActiveProtocolType();
#endif

    if(DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E == s_Dcm_DslPreemptionState_en)
    {
        if(DSD_IDLE_E != Dcm_Dsd_Prv_GetDsdState())
        {
            Dcm_Dsd_Prv_SetDsdState(DSD_CANCEL_E);
        }

#if(DCM_PAGEDBUFFER_ENABLED == DCM_CFG_ON)
        if(Dcm_Prv_Get_PagedBufferTxOn())
        {
            Dcm_StopProtocol(s_Dcm_DslCurrentProtocol_u8,s_Dcm_DslCurrentTesterSourceAddress_u16,s_Dcm_DslCurrentConnectionId_u16);
            s_Dcm_isStopProtocolInvoked_b = TRUE;
            Dcm_Prv_Set_PagedBufferTxOn(FALSE);
        }
#endif

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
        /* This variable will be TRUE when either ROE type1 is under processing */
        if(TRUE == flgRoeOn_b)
        {
            if(DCM_ROE_SOURCE == Dcm_Dsd_Prv_GetSourceofReq())
            {
                /* Call  ROE confirmation because DCM killing ROE requested service */
                DcmAppl_DcmConfirmation(idContext_u8,ReqType_u8,ConnectionId_u16,DCM_RES_POS_NOT_OK,ProtocolType_u8,
                        Dcm_Dsld_RoeRxToTestSrcMappingTable[DcmRxPduId_u16].testsrcaddr_u16);
            }
        }
#endif

        if(DCM_DEFAULT_SESSION != s_activeSession_u8)
        {
            Dcm_Prv_SetSesCtrlType(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));
        }

        Dcm_Prv_SetProtocolStatus(FALSE);
        s_Dcm_DslState_en = DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E;
        s_Dcm_DslPreemptionState_en = DSL_PREEMPTION_STATE_IDLE_E;
        activeTxPduId = Dcm_Prv_GetActiveTxPduId();
        if((E_OK == s_cancelTransmit) && (s_activeTxPduId == activeTxPduId))
        {
            DCM_TimerProcess(DataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr);
            Dcm_Prv_Set_DataTimeOut(DataTimeoutMonitor_u32);
        }
    }
}

static void Dcm_DslState_ResponseTransmission(void)
{
    Dcm_Dsl_Respone_st.SduDataPtr = &Dcm_Prv_GetActiveTxBuffer()[2];
    Dcm_Prv_UpdateMetaDataPointer(Dcm_Prv_GetActiveRxPduId(),&Dcm_Dsl_Respone_st.MetaDataPtr);

    if(DCM_NEG_RESPONSE == Dcm_Prv_GetResponsetype())
    {
        Dcm_Dsl_Respone_st.SduLength = DCM_NEGATIVE_RESPONSE_LENGTH;
    }
    else
    {
        Dcm_Dsl_Respone_st.SduLength = (PduLengthType) (Dcm_Dsd_Prv_GetRespLength()+DCM_SID_LENGTH);
    }
#if (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    if(TRUE == Dcm_Prv_Get_PagedBufferTxOn())
    {
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION_E);
        Dcm_Dsl_Prv_SetDslSubState(DSL_SUBSTATE_DATA_READY_E);
    }
    else
#endif
    {
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_WAITFOR_TXCONFIRMATION_E);
    }
    Dcm_Dsl_Prv_SetRespPendingCounterValue(DCM_DEFAULT_VALUE);
    Dcm_Prv_SendResponse(&Dcm_Dsl_Respone_st);
}

static void Dcm_Dsl_SendGeneralReject(void)
{
    PduLengthType ResponseLength = DCM_DEFAULT_VALUE;
    uint8 Sid_u8 = Dcm_Dsd_Prv_GetIdContext();
    uint8* ResponseBuffer_u8 = &Dcm_Prv_GetActiveTxBuffer()[2];


    /* Update DSD state to DSD_CANCEL_E, so that DSD will call the service with OpStatus DCM_CANCEL */
    Dcm_Dsd_Prv_CancelService();
    Dcm_Dsd_Prv_SetDsdState(DSD_WAITFORTXCONF_E);
    Dcm_Prv_SetResponsebyDSD(TRUE); /* This is added so that DcmAppl_DcmConfirmation_GeneralReject will get called in confirmation*/

    /* In case of negative response suppression update response length as 0x00 otherwise 0x03 */
    if(!Dcm_Dsd_isNegativeResponseSupressed(DCM_E_GENERALREJECT))
    {
        ResponseBuffer_u8[0] = DCM_NEGRESPONSE_INDICATOR;
        ResponseBuffer_u8[1] = Sid_u8;
        ResponseBuffer_u8[2] = DCM_E_GENERALREJECT;
        ResponseLength = DCM_NEGATIVE_RESPONSE_LENGTH;
    }

    Dcm_Prv_TriggerTransmit(ResponseLength);

}

static void Dcm_Dsl_TriggerPendingResponse(void)
{
    uint8 Sid_u8 = Dcm_Dsd_Prv_GetIdContext();

    /* Frame pending response in seperate buffer */
    Dcm_Dsl_MaxNumRespPendingBuffer_au8[0] = DCM_NEGRESPONSE_INDICATOR;
    Dcm_Dsl_MaxNumRespPendingBuffer_au8[1] = Sid_u8;
    Dcm_Dsl_MaxNumRespPendingBuffer_au8[2] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;

    /* Update SduDataPtr */
    Dcm_Dsl_Respone_st.SduDataPtr = Dcm_Dsl_MaxNumRespPendingBuffer_au8;
    Dcm_Dsl_Respone_st.SduLength = DCM_NEGATIVE_RESPONSE_LENGTH;
    Dcm_Prv_UpdateMetaDataPointer(Dcm_Prv_GetActiveRxPduId(),&Dcm_Dsl_Respone_st.MetaDataPtr);

    s_Dcm_DslState_en = DSL_STATE_WAITFOR_TXCONFIRMATION_E;

    if(Dcm_Prv_isForcePendingResponse() == FALSE)
    {
        /* Flag to indicate Pending response is being transmitted */
        s_isResponsePending_b = TRUE;
    }

    Dcm_Prv_SendResponse(&Dcm_Dsl_Respone_st);

    /* Reset flag once pending response is transmitted */
    s_isResponsePending_b = FALSE;

}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3244] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3703] */
void Dcm_Dsl_Prv_SendPendingResponse(void)
{

    const uint8* MaxNumRespPending = Dcm_Prv_GetMaxNumRespPending();
    if(FALSE == Dcm_Prv_Check_PendingResponseForKWP())
    {


        /*Suppress positive response flag to be reset if pending response is sent*/
        Dcm_Dsd_Prv_ResetsuppressPosResponse();

        if(NULL_PTR == MaxNumRespPending)
        {
            Dcm_Prv_SetInfinitePendingFlag(TRUE);
            /* Frame pending response and trigger pending response transmission infinitely.*/
            Dcm_Dsl_TriggerPendingResponse();
        }
        else if((*MaxNumRespPending) > 0x00u)
        {
            if(s_Dcm_DslRespPendingCounter_u8 < (*MaxNumRespPending))
            {
                /* Frame pending response, increment the pending counter and trigger pending response transmission */
                s_Dcm_DslRespPendingCounter_u8++;
                Dcm_Dsl_TriggerPendingResponse();
            }
            else
            {
                Dcm_Prv_SetResponsetype(DCM_MAXPENDING_EXEEDED);
                /* Number of pending responses exceeded the maximum value. Send NRC 0x10. */
                Dcm_Dsl_SendGeneralReject();
            }
        }
        else
        {
            Dcm_Dsl_SetForcePendingFlag(FALSE);
            /* MaxNumRespPending is 0 so, do not transmit pending response */
            Dcm_Prv_SetResponsetype(DCM_MAXPENDING_EXEEDED);
            /* Number of pending responses exceeded the maximum value. Send NRC 0x10. */
            Dcm_Dsl_SendGeneralReject();
        }
    }
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4037] */
static void Dcm_DslState_MonitorP2Max(void)
{
    uint32 DataTimeoutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();
    DCM_TimerProcess(DataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
    /* Update the data time out timer */
    Dcm_Prv_Set_DataTimeOut(DataTimeoutMonitor_u32);

    if(FALSE != DCM_TimerElapsed(DataTimeoutMonitor_u32))
    {
        /* Timer expired, send pending response(NRC 0x78) */
        Dcm_Dsl_Prv_SendPendingResponse();
    }
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3174] */
static void Dcm_Dsl_UpdateStatesForStartProtocol(void)
{
    uint32 DataTimeoutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();

    if(!DCM_TimerElapsed(DataTimeoutMonitor_u32))
    {
        /* Protocol started successfully, monitor P2 timer */
        s_Dcm_DslState_en = DSL_STATE_P2MAX_TIMEMONITORING_E;
        Dcm_Dsd_Prv_SetDsdState(DSD_VERIFICATION_E);
        s_activeTxPduId = Dcm_Prv_GetActiveTxPduId();
        s_Dcm_DslRespPendingCounter_u8 = 0x00;
    }
    else if(DCM_DEFAULT_SESSION != s_activeSession_u8)
    {
        s_Dcm_DslState_en = DSL_STATE_IDLE_E;
        Dcm_Dsd_Prv_SetDsdState(DSD_IDLE_E);
    }
    else
    {
        /* Monitor timer */
        DCM_TimerProcess(DataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
                /* Update the data time out timer */
                Dcm_Prv_Set_DataTimeOut(DataTimeoutMonitor_u32);
    }
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3335] */
static void Dcm_Dsl_SendNrcforStartProtocolFailure(void)
{
    PduLengthType ResponseLength = DCM_DEFAULT_VALUE;
    const Dcm_MsgItemType * RequestBuffer = Dcm_Prv_GetActiveRxBuffer();
    uint8 Sid_u8 = RequestBuffer[0];
    Dcm_MsgType responseBuffer = &Dcm_Prv_GetActiveTxBuffer()[2];

    s_Dcm_DslState_en = DSL_STATE_P2MAX_TIMEMONITORING_E;

    if(!Dcm_Dsd_isNegativeResponseSupressed(DCM_E_CONDITIONSNOTCORRECT))
    {
        responseBuffer[0] = DCM_NEGRESPONSE_INDICATOR;
        responseBuffer[1] = Sid_u8;
        responseBuffer[2] = DCM_E_CONDITIONSNOTCORRECT;
        ResponseLength = DCM_NEGATIVE_RESPONSE_LENGTH;
    }
    Dcm_Prv_SetResponsebyDSD(TRUE);
    Dcm_Prv_SetResponsetype(DCM_NEG_RESPONSE);
    Dcm_Prv_TriggerTransmit(ResponseLength);

}

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetDefaultTimerValues
 Syntax           : Dcm_Prv_SetDefaultTimerValues(void)
 Description      : This function is used to set timer values after protocol is started.
 Parameter        : None
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_SetDefaultTimerValues(void)
{
    uint8 idxKwpTiming_u8 = 0u;
    /* Lock is needed here to have P2Max, P3Max and P2StrMax to be consistent as a unit */
    /* BSWEXT-533 */
    SchM_Enter_Dcm_DsldTimer();
    if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
    {
        const Dcm_DslProtocolRowConfigType_tst * protocol_table_pcs; /* Pointer to protocol table */
        PduIdType rxPduId = Dcm_Prv_GetActiveRxPduId();
        protocol_table_pcs = Dcm_Prv_GetProtocolRow(rxPduId);
        idxKwpTiming_u8 = protocol_table_pcs->timings_idx_u8;

        Dcm_DsldTimer_st.dataTimeoutP2max_u32 = Dcm_Dsld_default_timings_acs[idxKwpTiming_u8].P2_max_u32;
        Dcm_DsldTimer_st.dataTimeoutP3max_u32 = Dcm_Dsld_default_timings_acs[idxKwpTiming_u8].P3_max_u32;
        Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 = Dcm_DsldTimer_st.dataTimeoutP3max_u32;
    }
    else
    {
        Dcm_DsldTimer_st.dataTimeoutP2max_u32    =  DCM_CFG_DEFAULT_P2MAX_TIME;
        Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 =  DCM_CFG_DEFAULT_P2STARMAX_TIME;
    }
    /* BSWEXT-533 */
    SchM_Exit_Dcm_DsldTimer();
}
#endif

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3329] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3333] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3334] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4036] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4504] */
static Std_ReturnType Dcm_Dsl_StartProtocol(void)
{
    Std_ReturnType StartProtocolResult = E_NOT_OK;

    if((DCM_NO_ACTIVE_PROTOCOL != s_Dcm_DslCurrentProtocol_u8) && (!s_Dcm_isStopProtocolInvoked_b))
    {
        /* Previous protocol is still active. So stop the protocol by calling Dcm_StopProtocol() */
        Dcm_StopProtocol(s_Dcm_DslCurrentProtocol_u8,s_Dcm_DslCurrentTesterSourceAddress_u16,s_Dcm_DslCurrentConnectionId_u16);
    }

    StartProtocolResult = Dcm_StartProtocol(Dcm_Prv_GetActiveProtocolType(),Dcm_Prv_GetActiveTesterSrcAddress(),Dcm_Prv_GetActiveConnectionId());

    if(E_OK == StartProtocolResult)
    {
        Dcm_Prv_SetProtocolStatus(TRUE);

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
        Dcm_Prv_SetDefaultTimerValues();
#endif

#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED!=DCM_CFG_OFF)
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (void)SchM_Switch_Dcm_DcmDiagnosticSessionControl(RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION);
#endif
        (void)DcmAppl_Switch_DcmDiagnosticSessionControl(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));
#endif
        Dcm_Prv_SetSesCtrlType(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));

        Dcm_Dsd_Prv_ServiceInit(Dcm_Prv_GetActiveSrvTabId());
        s_Dcm_DslCurrentProtocol_u8 = Dcm_Prv_GetActiveProtocolType();
        s_Dcm_DslCurrentTesterSourceAddress_u16 = Dcm_Prv_GetActiveTesterSrcAddress();
        s_Dcm_DslCurrentConnectionId_u16 = Dcm_Prv_GetActiveConnectionId();
    }

    return StartProtocolResult;
}

static boolean Dcm_Dsl_RequestReceived_StartProtocol(void)
{
    boolean Result_b = FALSE;

    if(!Dcm_Prv_IsProtocolStarted())
    {
        if(E_OK != Dcm_Dsl_StartProtocol())
        {
            /* Send NRC 0x21 when protocol could not be started */
            Dcm_Dsl_SendNrcforStartProtocolFailure();
        }

        s_Dcm_isStopProtocolInvoked_b = FALSE;
    }

    if(Dcm_Prv_IsProtocolStarted())
    {
        Dcm_Dsl_UpdateStatesForStartProtocol();
        Result_b = TRUE;
    }

    return Result_b;
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3296] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3367] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3990] */
static void Dcm_Dsl_Idle(void)
{
    uint32 DataTimeoutMonitor_u32;
    boolean P3TimerMonitorRequired_b;
    /* Fetch active session */
    s_activeSession_u8 = Dcm_Prv_GetActiveSession();
    DataTimeoutMonitor_u32 = Dcm_Prv_Get_DataTimeOut(); /* S3 timer variable- rework */
    P3TimerMonitorRequired_b = Dcm_Prv_IsP3TimerMonitorRequired();

    if((DCM_DEFAULT_SESSION_IDX != Dcm_Prv_GetActiveSessionIdx())||(P3TimerMonitorRequired_b))
    {
        if(!DCM_TimerElapsed(DataTimeoutMonitor_u32))
        {
            /* Process S3 or P3 timer */
            DCM_TimerProcess(DataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr);
            Dcm_Prv_Set_DataTimeOut(DataTimeoutMonitor_u32);
        }
        else
        {
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
            if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
            {
                Dcm_Prv_SetCommunicationState(FALSE);
                DcmAppl_P3TimeoutIndication();
            }
#endif
            /* Full communication mode is not required when in non default session*/
            if (Dcm_Prv_GetActiveSessionIdx()!=DCM_DEFAULT_SESSION_IDX)
            {
                /*TRACE[SWS_Dcm_00168]*/
                ComM_DCM_InactiveDiagnostic(Dcm_Prv_GetActiveComMChannelId());
            }

#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED!=DCM_CFG_OFF)

#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)

            (void)SchM_Switch_Dcm_DcmDiagnosticSessionControl(RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION);
#endif
            (void)DcmAppl_Switch_DcmDiagnosticSessionControl(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));
#endif

            Dcm_Prv_SetSesCtrlType(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));
            Dcm_Prv_SetP3TimerMonitorFlag(FALSE);
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED != DCM_CFG_OFF)
            Dcm_Prv_AuthS3ServerTimeout();
#endif
        }
    }

}

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
static void Dcm_Prv_DslState_PagedBufferTransmission(void)
{
    uint16 pageLen_u16 = 0u;
    uint32 dataPagedBufferTimeoutMonitor_u32 = Dcm_Prv_Get_DataPagedBufferTimeOut();

    if(Dcm_Dsl_Prv_GetDslSubState() == DSL_SUBSTATE_WAIT_FOR_DATA_E)
    {
        if(Dcm_Dsd_Prv_GetDsdState() == DSD_WAITFORTXCONF_E)
        {
            /* Start Paged buffer timeout timer */
            DCM_TimerStart(dataPagedBufferTimeoutMonitor_u32,DCM_PAGEDBUFFER_TIMEOUT,Dcm_PagedBufferStartTick_u32,Dcm_PagedBufferTimerStatus_uchr);
            Dcm_Prv_Set_DataPagedBufferTimeOut(dataPagedBufferTimeoutMonitor_u32);

            /* Call the service in DSD state machine  */
            Dcm_Dsd_Prv_SetDsdState(DSD_CALL_SERVICE_E);

            /* Inform the service to fill the data into page */
            if(Dcm_adrUpdatePage_pfct != NULL_PTR)
            {
                pageLen_u16 = (uint16)(Dcm_Prv_GetActiveTxBufferMaxLen());

                (*Dcm_adrUpdatePage_pfct)(&Dcm_Prv_GetActiveTxBuffer()[2],pageLen_u16);
            }
        }
    }
    else
    {
        if((Dcm_Dsl_Prv_GetDslSubState() == DSL_SUBSTATE_DATA_READY_E) || \
                (Dcm_Dsl_Prv_GetDslSubState() == DSL_SUBSTATE_WAIT_PAGE_TXCONFIRM_E))
        {
            /*do nothing*/
        }
    }

}
#endif
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3346] */
void Dcm_Dsl_Prv_StateMachine(void)
{

    switch(s_Dcm_DslState_en)
    {
        case DSL_STATE_IDLE_E:
        case DSL_STATE_ROETYPE1_RECEIVED_E:
        {
            Dcm_Dsl_Idle();
            break;
        }

        case DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E:
        {
            if(!Dcm_Dsl_RequestReceived_StartProtocol())
            {
                break;
            }
            else
            {
                s_Dcm_DslState_en = DSL_STATE_P2MAX_TIMEMONITORING_E;
            }
        }

        /* MR12 RULE 16.3 VIOLATION: break statement intentionally not added her for Execution to fall through */
        case DSL_STATE_P2MAX_TIMEMONITORING_E:
        {
            Dcm_DslState_MonitorP2Max();
            break;
        }

        case DSL_STATE_PREEMPTION_STOPPROTOCOL_E:
        {
            Dcm_DslState_Preemption_StopProtocol();
            break;
        }

        case DSL_STATE_PREMMPTION_STOPROE_E:
        {
            Dcm_DslState_Preemption_StopROE();
            break;
        }

        case DSL_STATE_WAITFOR_TXCONFIRMATION_E:
        {
            if(s_RetryTransmission_b)
            {
                Dcm_Prv_SendResponse(Dcm_Dsl_RetryRespTransmission_st);
            }
            break;
        }

        case DSL_STATE_RESPONSETRANSMISSION_E:
        {
            Dcm_DslState_ResponseTransmission();
            break;
        }

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
        case DSL_STATE_PAGEDBUFFER_TRANSMISSION_E:
        {
            Dcm_Prv_DslState_PagedBufferTransmission();
            break;
        }
#endif
        default:
        {
            /* Dcm would be waiting for RxIndication */
            break;
        }

    }
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
