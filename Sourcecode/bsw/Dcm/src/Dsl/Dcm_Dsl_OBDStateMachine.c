#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#if(DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
#include "SchM_Dcm.h"
#endif
#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)
#include "rba_DiagAdapt.h"
#endif
#include "Dcm_Prv.h"
#include "Dcm_Dsd_Verification.h"


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)


#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
boolean Dcm_OBDisGeneralRejectSent_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
Dcm_SrvOpStatusType Dcm_OBDSrvOpstatus_u8;
uint8 Dcm_CurOBDProtocol_u8; /* To store OBD Protocol information */
uint8 stObdSubState_en;     /* SubState Machine variable for OBD */
static uint8 Dcm_OBDWaitPendBuffer_au8[8];
Dcm_SrvOpStatusType Dcm_OBDExtSrvOpStatus_u8; /* Dcm OpStatus, set by Dcm to be used by all services outside Dcm */
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"
static uint16 s_Dcm_DslOBDCurrentTesterSourceAddress_u16 = 0;
static uint16 s_Dcm_DslOBDCurrentConnectionId_u16 = 0;
#define DCM_STOP_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
Dcm_OBDStateMachine_tst Dcm_OBDState_en; /* OBD State Machine variable */
Dcm_OBDStateMachine_tst Dcm_OBD_PreviousState;
PduInfoType Dcm_OBDPduInfo_st;
const Dcm_DsdServiceTableConfigType_tst* Dcm_OBDSrvTable_pcst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

boolean Dcm_Prv_IsRxPduIdOBD(PduIdType DcmRxPduId)
{
    uint8 Counter;
    boolean IsRxPduIdObd_b = FALSE;

    for(Counter = 0u;Counter < DCM_OBD_RXSIZE;Counter++)
    {
        if(Dcm_Dsl_OBDRxPduIds[Counter] == DcmRxPduId)
        {
            IsRxPduIdObd_b = TRUE;
            break;
        }
    }
    return IsRxPduIdObd_b;
}


boolean Dcm_Prv_IsTxPduIdOBD(PduIdType DcmTxPduId)
{
    uint8 Counter;
    boolean IsTxPduIdObd_b = FALSE;

    for(Counter = 0u;Counter < DCM_OBD_TXSIZE;Counter++)
    {
        if(Dcm_Dsl_OBDTxPduIds[Counter] == DcmTxPduId)
        {
            IsTxPduIdObd_b = TRUE;
            break;
        }
    }
    return IsTxPduIdObd_b;
}



/***********************************************************************************************************************
 Function name    : Dcm_Prv_CancelTransmitOnParallelOBDReq
 Description      : During Cancellation if transmission is already initiated
                    then we need to invoke Cancel transmit to stop the same
 Parameter        : Dcm_DsdStatesType_ten
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_CancelTransmitOnParallelOBDReq(Dcm_DsdStatesType_ten DsdState)
{
    Dcm_DslStatesType_ten DslState_en = Dcm_Dsl_Prv_GetDslState();

    if((DslState_en == DSL_STATE_WAITFOR_TXCONFIRMATION_E) || \
            ((DslState_en == DSL_STATE_ROETYPE1_RECEIVED_E) && (DsdState == DSD_WAITFORTXCONF_E)))
    {
        /* Set the status to Cancel the transmission */
        /*Set the cancel transmit status flag to True */
        Dcm_IsCancelTransmitInvoked_b = TRUE;
    }

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    if(Dcm_Prv_Get_PagedBufferTxOn() != FALSE)
    {
        /* Cancel the paged buffer processing for the active Service */
        DcmAppl_DcmCancelPagedBufferProcessing(Dcm_Dsd_Prv_GetIdContext());
        Dcm_IsCancelTransmitInvoked_b = TRUE;
    }
#endif

    if(Dcm_IsCancelTransmitInvoked_b == TRUE)
    {
        /* Set this flag to False as Cancellation was unsuccessful by lower layer ,
         * so a Txconfirmation call cannot be expected for cancelled transmit */
        if(PduR_DcmCancelTransmit(Dcm_Prv_GetActiveTxPduId()) != E_OK)
        {
            Dcm_IsCancelTransmitInvoked_b = FALSE;
        }
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_CancelService
 Description      : Cancel the execution of an ongoing UDS service
                    After cancellation the UDS State Machine will be Reset
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_CancelService(void)
{
    Dcm_NegativeResponseCodeType TempNrc_u8 = 0x00;
    Dcm_MsgContextType Dcm_MsgContext_st = Dcm_Dsd_Prv_GetUdsMsgContext();
    Dcm_DsdStatesType_ten DsdState = Dcm_Dsd_Prv_GetDsdState();
    const Dcm_DsdServiceTableConfigType_tst *Dcm_SrvTableCfg_pst = Dcm_Prv_GetServiceTable();

    Dcm_Prv_CancelTransmitOnParallelOBDReq(DsdState);
    if((DsdState == DSD_CALL_SERVICE_E) && (Dcm_SrvTableCfg_pst->serviceHandler_fp != NULL_PTR))
    {
        /* Invoke the service with OpStatus set to DCM_CANCEL */
        (void)(*Dcm_SrvTableCfg_pst->serviceHandler_fp)(DCM_CANCEL,&Dcm_MsgContext_st,&TempNrc_u8);
        Dcm_SrvOpstatus_u8 = DCM_INITIAL;
    }

    /* Reset UDS StateMachine */
    Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest();
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_CheckSession
 Description      : If a non-default session is active during OBD request processing then,
                    cancel any ongoing service and switch to default session
                    If a request to change to non-default session is being processed, then cancel that request
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_CheckSession(void)
{
    /* Currently active session is not default session */
    if(Dcm_Prv_GetActiveSession()!=DCM_DEFAULT_SESSION)
    {
        // Cancel ongoing service execution, if any
        Dcm_Prv_CancelService();

        // Switch to Default Session
#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED!=DCM_CFG_OFF)
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (void)SchM_Switch_Dcm_DcmDiagnosticSessionControl(RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION);
#endif
        (void)DcmAppl_Switch_DcmDiagnosticSessionControl(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));
#endif
        Dcm_Prv_SetSesCtrlType(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));

    }
    /* If a session request processing is ongoing, then cancel the request */
    else
    {
        Dcm_DslStatesType_ten DslState_en = Dcm_Dsl_Prv_GetDslState();
        Dcm_IdContextType   idContext = Dcm_Dsd_Prv_GetIdContext();
        if((DslState_en !=  DSL_STATE_IDLE_E) && (idContext == DCM_SID_DIAGNOSTICSESSIONCONTROL))
        {
            Dcm_Prv_CancelService();
        }
    }
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDTriggerNRCForProtocolFailure
 Description      : Function to transmit Conditions Not Correct for StartProtocol failure
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_OBDTriggerNRCForProtocolFailure(void)
{
    Dcm_NegativeResponseCodeType dataNrc_u8 = DCM_E_CONDITIONSNOTCORRECT;          /* Variable to store error code */
    Dcm_MsgItemType *adrRxBuffer_pu8 = Dcm_Prv_GetObdActiveProtocolRow()->rxBuffer_u8;

    Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8 = Dcm_Prv_GetObdActiveProtocolRow()->txBuffer_u8;
    Dcm_OBDGlobal_st.dataResponseByDsd_b = TRUE;
    Dcm_OBDGlobal_st.dataSid_u8     = adrRxBuffer_pu8[0];
    Dcm_OBDMsgContext_st.idContext  = Dcm_OBDGlobal_st.dataSid_u8;
    Dcm_OBDMsgContext_st.dcmRxPduId = Dcm_OBDGlobal_st.dataActiveRxPduId_u8;
    Dcm_OBDMsgContext_st.resDataLen = 0u;
    Dcm_OBDMsgContext_st.msgAddInfo.reqType = (Dcm_OBDGlobal_st.dataActiveRxPduId_u8 >= DCM_FUNCTIONAL_REQUEST)?
            DCM_PRV_FUNCTIONAL_REQUEST:DCM_PRV_PHYSICAL_REQUEST;

    /* By default make the response type as Positive response */
    Dcm_OBDGlobal_st.stResponseType_en = DCM_POS_RESPONSE;
    Dcm_OBDGlobal_st.dataActiveTxPduId_u8 = Dcm_Prv_GetObdActiveTxPduId();
    Dcm_OBDGlobal_st.cntrWaitpendCounter_u8 = 0;

    /* Set NRC and Trigger the response */
    Dcm_Prv_SetOBDNegResponse(&Dcm_OBDMsgContext_st,dataNrc_u8);
    Dcm_OBDProcessingDone(&Dcm_OBDMsgContext_st);
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_StartOBDProtocol
 Description      : Start the requested OBD protocol
 Parameter        : void
 Return value     : Std_ReturnType
 ***********************************************************************************************************************/
static Std_ReturnType Dcm_Prv_StartOBDProtocol(void)
{
    Std_ReturnType StartProtocol_u8;

    // If the previously active protocol was an OBD Protocol,only then stop the protocol
    if(Dcm_CurOBDProtocol_u8 != DCM_NO_ACTIVE_PROTOCOL)
    {
        //  Call API to inform application
        (void)Dcm_StopProtocol(Dcm_CurOBDProtocol_u8,s_Dcm_DslOBDCurrentTesterSourceAddress_u16,s_Dcm_DslOBDCurrentConnectionId_u16);
    }

    // Activate the protocol
    StartProtocol_u8 = Dcm_StartProtocol(Dcm_Prv_GetObdActiveProtocolRow()->protocolType,Dcm_Prv_GetObdActiveTesterSrcAddress(),Dcm_Prv_GetObdActiveConnection()->rxConnId_u16);
    if(StartProtocol_u8 == E_OK)
    {
        Dcm_OBDGlobal_st.flgCommActive_b = TRUE;
        Dcm_OBDGlobal_st.datActiveSrvtable_u8 = Dcm_Prv_GetObdActiveProtocolRow()->srvTableId_u8;
        Dcm_OBDSrvTable_pcst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[Dcm_Prv_GetObdActiveProtocolRow()->srvTableId_u8].srvTable_pcast;
        Dcm_Dsd_Prv_ServiceInit(Dcm_Prv_GetObdActiveProtocolRow()->srvTableId_u8);

        // Set default session
#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED!=DCM_CFG_OFF)
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (void)SchM_Switch_Dcm_DcmDiagnosticSessionControl(RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION);
#endif
        (void)DcmAppl_Switch_DcmDiagnosticSessionControl(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));
#endif
        Dcm_Prv_SetSesCtrlType(Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX));
        Dcm_CurOBDProtocol_u8 = Dcm_Prv_GetObdActiveProtocolRow()->protocolType;
        s_Dcm_DslOBDCurrentTesterSourceAddress_u16 = Dcm_Prv_GetObdActiveTesterSrcAddress();
        s_Dcm_DslOBDCurrentConnectionId_u16 =Dcm_Prv_GetObdActiveConnection()->rxConnId_u16;
    }
    // Protocol cannot be started , trigger NRC 0x22
    else
    {
        Dcm_Prv_OBDTriggerNRCForProtocolFailure();
    }
    return StartProtocol_u8;
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_CheckOBDRequest
 Description      : After the request is received, this function is called to check two aspects:
                     1 : Start of Protocol on which the request was received
                     2 : Whether Channel is in full communication mode
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_CheckOBDRequest(void)
{
    /* Flag to check whether Protocol is started or not
     * If not yet started, then call Dcm_Prv_StartOBDProtocol to start the protocol */
    Std_ReturnType Flag = (Dcm_OBDGlobal_st.flgCommActive_b != TRUE)?Dcm_Prv_StartOBDProtocol():E_OK;
    if(E_OK == Flag)
    {
        // If channel is in full communication mode
        if(FALSE !=DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetObdActiveConnection()->channel_idx_u8))
        {
            // Initialize WaitPend
            Dcm_OBDGlobal_st.cntrWaitpendCounter_u8 = 0x0u;
            // Update state to Verify Data State
            Dcm_Prv_SetOBDState((DCM_OBD_VERIFYDATA));
        }
    }
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDVerifyDataStateMachine
 Description      : Verify the received OBD Data - the DSD portion of the checks are carried out here
 Parameter        : void
 Return value     : Std_ReturnType
 ***********************************************************************************************************************/
static Std_ReturnType Dcm_Prv_OBDVerifyDataStateMachine(void)
{
    Std_ReturnType VerificationResult_u8 = E_OK;
    Dcm_NegativeResponseCodeType negativeResponseCode = DCM_DEFAULT_VALUE;
    switch(stObdSubState_en)
    {
        /* Perform Service table initialization and invoke Manufacturer indication */
        case OBDSUBSTATE_SERVICETABLE_INI:
        {
            Dcm_Prv_OBDServiceTableInit();
#if (DCM_CFG_MANUFACTURER_NOTIFICATION_ENABLED != DCM_CFG_OFF)
            stObdSubState_en = OBDSUBSTATE_MANUFACTURER_NOTIFICATION;
#else
            stObdSubState_en = OBDSUBSTATE_VERIFYDATA;
#endif
        }
#if (DCM_CFG_MANUFACTURER_NOTIFICATION_ENABLED != DCM_CFG_OFF)
        /* MR12 RULE 16.3 VIOLATION: break statement intentionally not added for Execution to fall through */
        /* Verify the requested service data */
        case OBDSUBSTATE_MANUFACTURER_NOTIFICATION:
        {
            VerificationResult_u8 = DCM_MANUFACTURER_NOTIFICATION(&Dcm_OBDMsgContext_st,&negativeResponseCode,DCM_OBDCONTEXT);

            if(VerificationResult_u8 != E_OK)
            {
                break;
            }
            else
            {
                stObdSubState_en = OBDSUBSTATE_VERIFYDATA;
            }
        }
#endif
/* MR12 RULE 16.3 VIOLATION: break statement intentionally not added for Execution to fall through */
        /* Verify the requested service data */
        case OBDSUBSTATE_VERIFYDATA:
        {
            if(Dcm_Prv_OBDVerifyData() != E_OK)
            {
                VerificationResult_u8 = E_NOT_OK;
                break;
            }
            else
            {
#if (DCM_CFG_SUPPLIER_NOTIFICATION_ENABLED != DCM_CFG_OFF)
                stObdSubState_en = OBDSUBSTATE_SUPPLIER_NOTIFICATION;
#else
                break;
#endif
            }
        }
        /* MR12 RULE 16.3 VIOLATION: break statement intentionally not added for Execution to fall through */
        /* Invoke Supplier notification for tester triggered requests */
#if (DCM_CFG_SUPPLIER_NOTIFICATION_ENABLED != DCM_CFG_OFF)
        case OBDSUBSTATE_SUPPLIER_NOTIFICATION:
        {
            VerificationResult_u8 = DCM_SUPPLIER_NOTIFICATION(&Dcm_OBDMsgContext_st,&negativeResponseCode,DCM_OBDCONTEXT);
            break;
        }
#endif
        /* Should never reach here */
        default:
        {
            VerificationResult_u8 = E_NOT_OK;
        }
        break;
    }
    /* If Pending is returned ,only then continue in the same state */
    if(VerificationResult_u8 != DCM_E_PENDING)
    {
        stObdSubState_en = OBDSUBSTATE_SERVICETABLE_INI;
    }
    return VerificationResult_u8;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDFrameIntermediateResponse
 Description      : Function to Frame response for NRC0x78 transmission
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_OBDFrameIntermediateResponse(void)
{
    /* frame intermediate Negative response for send Pending response
     * For this a separate buffer should be used */
    Dcm_OBDWaitPendBuffer_au8[0] = DCM_NEGRESPONSE_INDICATOR;
    Dcm_OBDWaitPendBuffer_au8[1] = Dcm_OBDGlobal_st.dataSid_u8;
    Dcm_OBDWaitPendBuffer_au8[2] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_OBDPduInfo_st.SduDataPtr = Dcm_OBDWaitPendBuffer_au8;
    Dcm_OBDPduInfo_st.SduLength = 0x03;
    Dcm_Prv_SetOBDPreviousState();
    Dcm_Prv_SetOBDState((DCM_OBD_WAITFORTXCONF));
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDSendGeneralReject
 Description      : Function to transmit General Reject due to exceeding configured Response Pend
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_OBDSendGeneralReject(void)
{
    const Dcm_DsdServiceTableConfigType_tst* adrServiceTable_pcst;
    uint8 TempNrc_u8 =0x00u;
    Dcm_OBDMsgContext_st.msgAddInfo.suppressPosResponse = FALSE;

    /* Configured number of wait pend is sent, Now send general reject */
    adrServiceTable_pcst = &Dcm_OBDSrvTable_pcst[Dcm_OBDGlobal_st.idxService_u8];
    if(adrServiceTable_pcst->serviceHandler_fp != NULL_PTR)
    {
        /* Cancel ongoing service execution */
        Dcm_OBDSrvOpstatus_u8 = DCM_CANCEL;
        (void)(*(adrServiceTable_pcst)->serviceHandler_fp)
                                                  (Dcm_OBDSrvOpstatus_u8,&Dcm_OBDMsgContext_st,&TempNrc_u8);

    }
    /* Assign the opstatus to DCM_INITIAL after cancellation */
    Dcm_OBDSrvOpstatus_u8 = DCM_INITIAL;
    Dcm_OBDExtSrvOpStatus_u8 = DCM_INITIAL;
    Dcm_ResetOBDSubStateMachine();
    Dcm_OBDGlobal_st.idxService_u8 = 0x00u;
    Dcm_OBDGlobal_st.dataResponseByDsd_b = TRUE;
    Dcm_Prv_SetOBDNegResponse(&Dcm_OBDMsgContext_st,DCM_E_GENERALREJECT);
    Dcm_OBDisGeneralRejectSent_b = TRUE;

#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)
    /* Call to indicate the trigger of NRC 0x10 from State machine to reset the rba_DiagAdapt */
    rba_DiagAdapt_Confirmation_GeneralReject(Dcm_OBDGlobal_st.dataSid_u8);
#endif
    Dcm_OBDProcessingDone(&Dcm_OBDMsgContext_st);
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SendOBDPendingResponse
 Description      : Function to transmit pending response, either NRC0x78 or 0x10 when timer elapses
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_SendOBDPendingResponse(void)
{
    const uint8* MaxNumRespPending = Dcm_Prv_GetMaxNumRespPending();
    Dcm_Prv_UpdateMetaDataPointer(Dcm_Prv_GetObdActiveRxPduId(),&Dcm_OBDPduInfo_st.MetaDataPtr);

    if(NULL_PTR == MaxNumRespPending)
    {
        /* Frame pending response and trigger pending response transmission infinitely.*/
        Dcm_OBDMsgContext_st.msgAddInfo.suppressPosResponse = FALSE;
        Dcm_Prv_OBDFrameIntermediateResponse();
        Dcm_Prv_OBDSendResponse(&Dcm_OBDPduInfo_st);
    }
    else if(Dcm_OBDGlobal_st.cntrWaitpendCounter_u8 < (*MaxNumRespPending))
    {
        Dcm_OBDMsgContext_st.msgAddInfo.suppressPosResponse = FALSE;
        Dcm_Prv_OBDFrameIntermediateResponse();

        /* Increment wait pend counter to indicate one wait pend is sent */
        Dcm_OBDGlobal_st.cntrWaitpendCounter_u8++;
        Dcm_Prv_OBDSendResponse(&Dcm_OBDPduInfo_st);
    }
    else
    {
        // Send General reject for exceeding number of response pend
        Dcm_Prv_OBDSendGeneralReject();
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDTimerElapsed
 Description      : Function to update OBD timer count and check whether OBD timer has elapsed
                     Returns TRUE - If Timer has elapsed
                     Returns FALSE - If Timer has not yet elapsed
 Parameter        : Dcm_OBDStateMachine_tst
 Return value     : boolean
 ***********************************************************************************************************************/
static boolean Dcm_Prv_OBDTimerElapsed(Dcm_OBDStateMachine_tst ObdState)
{
    boolean TimerElapsed = FALSE;
    // Timer monitoring is required only for these states
    if((ObdState == DCM_OBD_REQUESTRECEIVED)||(ObdState == DCM_OBD_VERIFYDATA)||(ObdState == DCM_OBD_PROCESSSERVICE))
    {
        // Monitor the timer count
        DCM_TimerProcess(Dcm_OBDGlobal_st.dataTimeoutMonitor_u32,Dcm_OBDP2OrS3StartTick_u32,Dcm_OBDP2OrS3TimerStatus_uchr)

                /* Check P2 max expired or not */
                if(DCM_TimerElapsed(Dcm_OBDGlobal_st.dataTimeoutMonitor_u32))
                {
                    TimerElapsed = TRUE;
                }
    }
    return TimerElapsed;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDTimerProcessing
 Description      : Central timer for processing P2/P2* timers for OBD
                    In case Timer has elapsed, StateMachine is updated to necessary state
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_OBDTimerProcessing(void)
{
    Dcm_OBDStateMachine_tst ObdState = Dcm_Prv_GetOBDState();

    // Check whether Timer has elapsed
    if(FALSE != Dcm_Prv_OBDTimerElapsed(ObdState))
    {
        // Only happens for communication mode check
        if((ObdState == DCM_OBD_REQUESTRECEIVED) && (Dcm_OBDGlobal_st.flgCommActive_b == TRUE))
        {
            // Unable to move to FULL Communication mode, reject the request
            DcmAppl_DcmComModeError(Dcm_Prv_GetObdActiveConnection()->comMChannelId_u8);
            Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
        }
        else
        {
            /* Service processing is ongoing. Trigger NRC 0x78/0x10 */
            Dcm_Prv_SendOBDPendingResponse();
        }
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ConfirmationToOBDApl
 Description      : After confirmation is received, this function is called to Send Confirmation to application.
                    Called in Main Function context
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_ConfirmationToOBDApl(void)
{
    /* Update based on the Type of response sent and whether the response was sent successfully */
    Dcm_ConfirmationStatusType ConfirmationStatus_u8 =  (Dcm_OBDGlobal_st.dataResult_u8 == E_OK)?
            ((Dcm_OBDGlobal_st.stResponseType_en == DCM_POS_RESPONSE)?DCM_RES_POS_OK:DCM_RES_NEG_OK) :
            ((Dcm_OBDGlobal_st.stResponseType_en == DCM_POS_RESPONSE)?DCM_RES_POS_NOT_OK:DCM_RES_NEG_NOT_OK);


    uint8 ReqType_u8                  = Dcm_OBDMsgContext_st.msgAddInfo.reqType;
    uint16 ConnectionId_u16           = Dcm_Prv_GetObdActiveConnection()->rxConnId_u16;
    uint16 TesterSourceAddress_u16    = Dcm_Prv_GetObdActiveTesterSrcAddress();
    Dcm_IdContextType idContext_u8    = Dcm_OBDMsgContext_st.idContext;
    Dcm_ProtocolType ProtocolType_u8  = Dcm_Prv_GetObdActiveProtocolRow()->protocolType;

    /* Check if the response is given by service or not */
    if (Dcm_OBDGlobal_st.dataResponseByDsd_b == FALSE)
    {
        /* Service exists outside the DSP. Give the confirmation to Application */
        DcmAppl_DcmConfirmation(idContext_u8, ReqType_u8, ConnectionId_u16,\
                ConfirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);
    }
    else
    {
        /* Check if the max number of configured NRC 0x78 is transmitted */
        if(Dcm_OBDisGeneralRejectSent_b != FALSE)
        {
            DcmAppl_DcmConfirmation_GeneralReject(idContext_u8, ReqType_u8, ConnectionId_u16,\
                    ConfirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);
            Dcm_OBDisGeneralRejectSent_b = FALSE;
        }
        else
        {
            /* Negative response created inside DSD. Give separate confirmation to application. */
            DcmAppl_DcmConfirmation_DcmNegResp(idContext_u8, ReqType_u8, ConnectionId_u16,\
                    ConfirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);
        }
    }
#if ((DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS != 0u) || (DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS !=0u))
    Dcm_Dsd_Prv_CallRTEConfirmation(ConfirmationStatus_u8,TesterSourceAddress_u16, DCM_OBDCONTEXT);
#endif
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_UpdateOpStatus
 Description      : Used to update the OpStatus based on Service return
                    - If Service is processed within Dcm
                    - If Service is processed outside Dcm, Update Dcm_ExtSrvOpStatus_u8 based on return
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_UpdateOBDOpStatus(Std_ReturnType ServiceResult_u8)
{
    if(Dcm_OBDSrvTable_pcst[Dcm_OBDGlobal_st.idxService_u8].internalDspService_b != FALSE)
    {
        if(ServiceResult_u8 != DCM_E_PENDING)
        {
            Dcm_OBDSrvOpstatus_u8 = DCM_INITIAL;
        }
    }
    else
    {
        if(ServiceResult_u8 == DCM_E_PENDING)
        {
            Dcm_OBDExtSrvOpStatus_u8 = DCM_PENDING;
        }
        else
        {
            Dcm_OBDExtSrvOpStatus_u8 = DCM_INITIAL;
        }
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessOBDService
 Description      : Function for invoking OBD service and processing its result
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_ProcessOBDService(void)
{
    Dcm_NegativeResponseCodeType ErrorCode_u8 = DCM_DEFAULT_VALUE;
    const Dcm_DsdServiceTableConfigType_tst* adrServiceTable_pcst = &Dcm_OBDSrvTable_pcst[Dcm_OBDGlobal_st.idxService_u8];

    Std_ReturnType ServiceResult_u8;

    if(Dcm_OBDSrvTable_pcst[Dcm_OBDGlobal_st.idxService_u8].internalDspService_b != FALSE)
    {
        ServiceResult_u8 = (*(adrServiceTable_pcst)->serviceHandler_fp)(Dcm_OBDSrvOpstatus_u8,
                &Dcm_OBDMsgContext_st,&ErrorCode_u8);
    }
    else
    {
        ServiceResult_u8 = (*(adrServiceTable_pcst)->serviceHandler_fp)(Dcm_OBDExtSrvOpStatus_u8
                ,&Dcm_OBDMsgContext_st,&ErrorCode_u8);
    }

    Dcm_Prv_UpdateOBDOpStatus(ServiceResult_u8);
    /* Do Further processing based on service return value */
    if(ServiceResult_u8 == DCM_E_PENDING)
    {
        /* Do nothing here, The Global Opstatus will be set to required state by the service */
    }
    else
    {
        if(ServiceResult_u8 != E_OK)
        {
            /* If no NRC is set by the service, send NRC 0x22 */
            if(ErrorCode_u8 == DCM_DEFAULT_VALUE)
            {
                ErrorCode_u8 = DCM_E_CONDITIONSNOTCORRECT;
            }
            /* Trigger transmission of negative response */
            Dcm_Prv_SetOBDNegResponse(&Dcm_OBDMsgContext_st, ErrorCode_u8);
        }


        Dcm_OBDProcessingDone(&Dcm_OBDMsgContext_st);
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDStateMachine
 Description      : State Machine for parallel processing of OBD request in parallel with other requests
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_OBDStateMachine(void)
{
    switch(Dcm_OBDState_en)
    {
        // OBD request is completely received. Perform Protocol checks
        case DCM_OBD_REQUESTRECEIVED:
        {
            Dcm_Prv_CheckSession();
            Dcm_Prv_CheckOBDRequest();

            if(Dcm_OBDState_en != DCM_OBD_VERIFYDATA)
            {
                break;
            }
        }

        // Perform Service related checks
        /* MR12 RULE 16.3 VIOLATION: break statement intentionally not added for Execution to fall through */
        case DCM_OBD_VERIFYDATA:
        {
            if(Dcm_Prv_OBDVerifyDataStateMachine() != E_OK)
            {
                break;
            }
            else
            {
                Dcm_Prv_SetOBDState((DCM_OBD_PROCESSSERVICE));
            }
        }

        // All checks are done, Invoke the OBD service
        /* MR12 RULE 16.3 VIOLATION: break statement intentionally not added for Execution to fall through */
        case DCM_OBD_PROCESSSERVICE:
            Dcm_Prv_ProcessOBDService();
            break;

        default:
            /* Do nothing. This state is for
             * DCM_OBD_IDLE,
             * DCM_OBD_REQUESTRECEIVING as well as
             * DCM_OBD_WAITFORTXCONF  */
            break;
    }
}


#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#endif /* (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF) */
