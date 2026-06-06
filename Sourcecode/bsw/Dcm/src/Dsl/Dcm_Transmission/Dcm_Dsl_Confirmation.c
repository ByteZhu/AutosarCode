
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "ComM_Dcm.h"
#include "Dcm_Prv.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
Dcm_OBDTxType_tst Dcm_OBDTransmit_st;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
boolean Dcm_isFirstReponseSent_b;  /* flag for KWP first response sent when the split response feature is enabled */
static boolean Dcm_isApplicationCalled_b;   /* flag to indicate whether DcmAppl_DcmConfirmation has been called or not in case of splitting of responses */
#endif
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
LOCAL_INLINE boolean Dcm_isConfirmationReceivedForNrc21Response(PduIdType DcmTxPduId,PduIdType idxRxPduId);
LOCAL_INLINE boolean Dcm_isConfirmationForPendingResponse(void);
static void Dcm_ConfirmationForPendingResponse (Std_ReturnType Result);



/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 *    Inline Function Definitions
 **********************************************************************************************************************
 */

/***********************************************************************************************************************
 Function name    : Dcm_Prv_isNormalResponseConfirmationProcessed
 Syntax           : Dcm_Prv_isNormalResponseConfirmationProcessed(void)
 Description      : This Inline function is used to check whether processing of confirmation for the Normal response is
                    Completed
 Parameter        : None
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isNormalResponseConfirmationProcessed(void)
{
    Dcm_DsdStatesType_ten DsdState_en = Dcm_Dsd_Prv_GetDsdState();
    uint8 sourceofRequest = Dcm_Dsd_Prv_GetSourceofReq();
    Dcm_SesCtrlType ActiveSession =  Dcm_Prv_GetActiveSession();
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    Dcm_DslProtocolPreemptionStatesType_ten PreemptionState_en =  Dcm_Dsl_Prv_GetPreemptionState();
#endif
    return((DsdState_en == DSD_SENDTXCONF_APPL_E) && \
       (sourceofRequest == DCM_UDS_TESTER_SOURCE) && \
       (ActiveSession == DCM_DEFAULT_SESSION)
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
       && (PreemptionState_en != DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E)
#endif
        );
}


#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isHighPriorityRequestReceiving
 Syntax           : Dcm_Prv_isHighPriorityRequestReceiving(void)
 Description      : This Function is used to check whether High priority request is being received.
 Parameter        : None
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isHighPriorityRequestReceiving(void)
{
    boolean isRequestReceiving_b = FALSE;
    Dcm_DsdStatesType_ten stDsdStateTemp_en  = Dcm_Dsd_Prv_GetDsdState();
    Dcm_DslProtocolPreemptionStatesType_ten PreemptionState_en = Dcm_Dsl_Prv_GetPreemptionState();

    if(((PreemptionState_en == DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E) ||\
             (PreemptionState_en == DSL_PREEMPTION_HIGHPRIORITY_REQUESTRECEIVED_E))          &&\
             (stDsdStateTemp_en == DSD_WAITFORTXCONF_E))
    {
        isRequestReceiving_b = TRUE;
    }

    return isRequestReceiving_b;
}
#endif


#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isConfirmationForKWPResponse
 Syntax           : Dcm_Prv_isConfirmationForKWPResponse(Result)
 Description      : This Inline function is used to check if Confirmation received is for KWP request
 Parameter        : Result
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isConfirmationForKWPResponse(Std_ReturnType Result)
{
    boolean ResponseByDsd_b = Dcm_Prv_GetResponsebyDSD();
    Dcm_DsdResponseType_ten ResponseType_en = Dcm_Prv_GetResponsetype();
    boolean isKwpActive_b =  DCM_IS_KWPPROT_ACTIVE() ;
    return ((Result == E_OK) && \
            (isKwpActive_b != FALSE) && \
            (ResponseByDsd_b == FALSE) && \
            (ResponseType_en == DCM_POS_RESPONSE));
}
#endif

LOCAL_INLINE boolean Dcm_isConfirmationReceivedForNrc21Response(PduIdType DcmTxPduId,PduIdType idxRxPduId)
{
    uint8 ServiceId;
    PduIdType TxPduId = Dcm_Prv_GetTxPduId(idxRxPduId);

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    ServiceId = Dcm_Prv_IsTxPduIdOBD(DcmTxPduId)?
                Dcm_DslOBDRxPduArray_ast[idxRxPduId].Dcm_DslServiceId_u8:
                Dcm_ReceptionInfo_ast[idxRxPduId].Dcm_ServiceId_u8;
#else
    ServiceId = Dcm_ReceptionInfo_ast[idxRxPduId].Dcm_ServiceId_u8;
#endif

    return ((FALSE !=Dcm_Prv_GetRespOnSecondDeclinedRequest(idxRxPduId)) &&
            (DCM_SERVICEID_DEFAULT_VALUE != ServiceId) &&
            (DcmTxPduId == TxPduId));
}


LOCAL_INLINE boolean Dcm_isConfirmationForPendingResponse(void)
{
    boolean InfinitePendingFlag_b = Dcm_Prv_GetInfinitePendingFlag();

    return ((Dcm_Dsl_Prv_GetRespPendingCounterValue()>0u) || \
            (InfinitePendingFlag_b !=FALSE));
}


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isOBDConfirmationOnActiveConnection
 Syntax           : Dcm_Prv_isOBDConfirmationOnActiveConnection(DcmTxPduId)
 Description      : This Inline function is used to check confirmation received on active connection for OBD
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
/* Check whether OBD TxConfirmation received is for the active connection */
LOCAL_INLINE boolean Dcm_Prv_isOBDConfirmationOnActiveConnection(PduIdType DcmTxPduId)
{
    return (DcmTxPduId == Dcm_OBDGlobal_st.dataActiveTxPduId_u8);
}

/*
 **********************************************************************************************************************
 *   Function Definitions
 **********************************************************************************************************************
 */


boolean Dcm_Prv_CanComMBeInactivated(boolean Context)
{
    boolean AllowInactivation = FALSE;
    const Dcm_DslMainConnConfigType_tst * ActiveObdMainConnCfg_pcast = Dcm_Prv_GetObdActiveConnection();
    const Dcm_DslMainConnConfigType_tst * ActiveMainConnCfg_pcast = Dcm_Prv_GetActiveConnection();

    /* If same channel is not shared, then channel can be inactivated */
    if((ActiveObdMainConnCfg_pcast != NULL_PTR) && (ActiveMainConnCfg_pcast != NULL_PTR))
    {
        if(Dcm_Prv_GetObdActiveConnection()->comMChannelId_u8 !=  Dcm_Prv_GetActiveConnection()->comMChannelId_u8)
        {
            AllowInactivation = TRUE;
        }
    }
    /* Check whether Dcm State Machine is free, only then inactive the channel */
    else if(Context == DCM_OBDCONTEXT)
    {
        if(Dcm_Dsl_Prv_GetDslState() == DSL_STATE_IDLE_E)
        {
            AllowInactivation = TRUE;
        }
    }
    /* Check whether OBD State Machine is free, only then inactive the channel */
    else
    {
        if(Dcm_Prv_GetOBDState() == DCM_OBD_IDLE)
        {
            AllowInactivation = TRUE;
        }
    }
    return AllowInactivation;
}



/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBD_ProcessConfirmationForPendingResponse
 Description      : Confirmation is received for Pending Transmission (NRC0x78)
 Parameter        : Std_ReturnType
 Return value     : None
***********************************************************************************************************************/
static void Dcm_Prv_OBD_ProcessConfirmationForPendingResponse(Std_ReturnType Result)
{
    if(E_OK == Result)
    {
        /* extend the time to Spl p2max, start SplP2 timer */
       DCM_TimerStart(Dcm_OBDGlobal_st.dataTimeoutMonitor_u32, \
             (DCM_CFG_DEFAULT_P2STARMAX_TIME - \
                     Dcm_Prv_GetObdActiveProtocolRow()->timStrP2ServerAdjust_u32),\
             Dcm_OBDP2OrS3StartTick_u32,Dcm_OBDP2OrS3TimerStatus_uchr);
    }
    // Let OBD State Machine continue processing in its previous state before P2 timeout occured
    Dcm_Prv_SetOBDState((Dcm_Prv_GetOBDPreviousState()));
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDProcessConfirmationForCurrentResponse
 Description      : Confirmation is received for Normal Response transmission
                    No need to reset S3 timer as OBD is always processed in only default session
 Parameter        : Std_ReturnType
 Return value     : None
***********************************************************************************************************************/
static void Dcm_Prv_OBDProcessConfirmationForCurrentResponse(Std_ReturnType Result)
{
   // Store the Result of Transmission. This is later on used to inform application
    Dcm_OBDGlobal_st.dataResult_u8 = Result;

   // Set OBD State to Send Confirmation to Application
   Dcm_ObdSendTxConfirmation_b = TRUE;
   Dcm_Prv_ResetObdActiveRxPduId();
   Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
   /* If UDS State Machine is also free only then release */
   if(FALSE != Dcm_Prv_CanComMBeInactivated(DCM_OBDCONTEXT))
   {
      ComM_DCM_InactiveDiagnostic(Dcm_Prv_GetObdActiveConnection()->comMChannelId_u8);
   }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDProcessTxConfirmation
 Description      :  Tx Confirmation has come for an OBD protocol triggered Response
 Parameter        : PduIdType, Std_ReturnType
 Return value     : None
***********************************************************************************************************************/
static void Dcm_Prv_OBDProcessTxConfirmation(PduIdType DcmTxPduId,Std_ReturnType Result)
{
    PduIdType RxPduidCounter;
    /* Is confirmation received on active connection?
       Can be False in case of Busy Repeat request confirmation for different client */
    if(FALSE != Dcm_Prv_isOBDConfirmationOnActiveConnection(DcmTxPduId))
    {
        // Confirmation of NRC 0x78 due to P2/P2* timeout?
       if(Dcm_OBDGlobal_st.cntrWaitpendCounter_u8 > 0x0u)
       {
           Dcm_Prv_OBD_ProcessConfirmationForPendingResponse(Result);
       }
       else
       {
           Dcm_Prv_OBDProcessConfirmationForCurrentResponse(Result);
       }
    }

    /* If confirmation obtained is due to NRC21 transmission when Dcm is busy processing another request
       Loop through all RxPduIds and match with TxPduId for which confirmation is received */
    for (RxPduidCounter = 0x00u; RxPduidCounter < DCM_CFG_TOTAL_RX_PDUID; RxPduidCounter++)
    {
        if(FALSE != Dcm_isConfirmationReceivedForNrc21Response(DcmTxPduId,RxPduidCounter))
        {
            // Reset ServiceId as confirmation is received. Should be set only in case of NRC21 transmission
            Dcm_DslOBDRxPduArray_ast[RxPduidCounter].Dcm_DslServiceId_u8 = DCM_SERVICEID_DEFAULT_VALUE;
            break;
        }
    }
}


#endif

/***********************************************************************************************************************
 Function name    : Dcm_Prv_InactivateComMChannel
 Syntax           : Dcm_Prv_InactivateComMChannel(void)
 Description      : This Function is used to release ComM channel after the reception of confirmation is processed.
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
/*TRACE[SWS_Dcm_00165][SWS_Dcm_00166][SWS_Dcm_00697][SWS_Dcm_00168][SWS_Dcm_00170]*/
void Dcm_Prv_InactivateComMChannel(void)
{

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(FALSE != Dcm_Prv_CanComMBeInactivated(DCM_UDSCONTEXT))
#endif
    {
        if(FALSE != Dcm_Prv_isNormalResponseConfirmationProcessed())
        {
            ComM_DCM_InactiveDiagnostic(Dcm_active_commode_e[Dcm_Prv_GetActiveComMChannelIndex()].ComMChannelId);
        }

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
        if(FALSE != Dcm_Prv_isKWPSplitResponseTimeout())
        {
            ComM_DCM_InactiveDiagnostic(Dcm_active_commode_e[Dcm_Prv_GetActiveComMChannelIndex()].ComMChannelId);
        }
#endif
    }
}


#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF) )
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isResponseSentForDSCService
 Syntax           : Dcm_Prv_isResponseSentForDSCService(void)
 Description      : This Inline function is used to check if response sent for DSC service
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_isResponseSentForDSCService(void)
{
    Dcm_IdContextType IdContext          =  Dcm_Dsd_Prv_GetIdContext();
    Dcm_DsdResponseType_ten Responsetype =  Dcm_Prv_GetResponsetype();
    uint8 SourceofReq  =  Dcm_Dsd_Prv_GetSourceofReq();

    return ((IdContext == DCM_SID_DIAGNOSTICSESSIONCONTROL) &&\
            (Responsetype == DCM_POS_RESPONSE) &&\
            (SourceofReq  == DCM_UDS_TESTER_SOURCE));
}
#endif

/*
 **********************************************************************************************************************
 *   Function Definitions
 **********************************************************************************************************************
 */

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
/***********************************************************************************************************************
 Function name    : Dcm_KWPConfirmationForSplitResp
 Syntax           : Dcm_KWPConfirmationForSplitResp(status)
 Description      : This function is called for the handling of DSL,DSD states, Timer and the ComM channel when either
                    the entire response is sent or when the timeout between the responses occurs in the KWP split
                    response feature
 Parameter        : Dcm_ConfirmationStatusType
 Return value     : None
***********************************************************************************************************************/
void Dcm_KWPConfirmationForSplitResp(Dcm_ConfirmationStatusType status)
{
    /*TRACE[SWS_Dcm_00141]*/
    Dcm_Prv_ReloadS3Timer();
    Dcm_Prv_InactivateComMChannel();

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_ProcessRequestInQueue();
#else
    Dcm_Dsl_Prv_SetDslState((DSL_STATE_IDLE_E));
#endif

    if(Dcm_isApplicationCalled_b == FALSE)
    {
        uint8 ReqType_u8                  = Dcm_Prv_GetActiveReqType();
        uint16 ConnectionId_u16           = Dcm_Prv_GetActiveConnectionId();
        uint16 TesterSourceAddress_u16    = Dcm_Prv_GetActiveTesterSrcAddress();
        Dcm_IdContextType idContext_u8    = Dcm_Dsd_Prv_GetIdContext();
        Dcm_ProtocolType ProtocolType_u8  = Dcm_Prv_GetActiveProtocolType();
        DcmAppl_DcmConfirmation(idContext_u8, ReqType_u8, ConnectionId_u16,\
                status, ProtocolType_u8,TesterSourceAddress_u16);
    }

#if ((DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS != 0) || (DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS !=0))
    Dcm_Dsd_Prv_CallRTEConfirmation(status, Dcm_Prv_GetActiveTesterSrcAddress(), DCM_UDSCONTEXT);
#endif
    /* make DSD state as IDLE */
    Dcm_Dsd_Prv_SetDsdState(DSD_IDLE_E);
}
#endif




#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessConfirmationForKWPResponse
 Syntax           : Dcm_Prv_ProcessConfirmationForKWPResponse(void)
 Description      : This Function is used to Process Confirmation received for KWP Response
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
static void Dcm_Prv_ProcessConfirmationForKWPResponse(void)
{
    PduLengthType ResponseLength = 0u;
    uint8 ReqType_u8                  = Dcm_Prv_GetActiveReqType();
    uint16 ConnectionId_u16           = Dcm_Prv_GetActiveConnectionId();
    uint16 TesterSourceAddress_u16    = Dcm_Prv_GetActiveTesterSrcAddress();
    Dcm_IdContextType idContext_u8    = Dcm_Dsd_Prv_GetIdContext();
    Dcm_ProtocolType ProtocolType_u8  = Dcm_Prv_GetActiveProtocolType();
    uint32 dataTimeOutMonitor_u32;

    DcmAppl_DcmConfirmation(idContext_u8, ReqType_u8, ConnectionId_u16,\
            DCM_RES_POS_OK, ProtocolType_u8,TesterSourceAddress_u16);

    /* call the application to know if some more response bytes are to be sent yet by splitting of responses. */
    DcmAppl_DcmGetRemainingResponseLength(idContext_u8,&ResponseLength);

    if(0u != ResponseLength)
    {
        /* If the KWP service has some responses to be sent, then
        call the service again in the next main cycle if it is scheduled by Dcm */
        if(Dcm_isFirstReponseSent_b == FALSE)
        {
            /* set the below flag to TRUE when the Confirmation for the first split response is received */
            Dcm_isFirstReponseSent_b = TRUE;
        }

        /* start the split response timer - DCM_CFG_SPLITRESPONSETIMEFORKWP (configured) */
        dataTimeOutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();
        DCM_TimerStart(dataTimeOutMonitor_u32,(DCM_CFG_SPLITRESPONSETIMEFORKWP),
        Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)

        Dcm_Prv_Set_DataTimeOut(dataTimeOutMonitor_u32);

        /* Multicore: No lock needed here as Dsl state is an atomic operation and
        at this point the DCM statemachine is already blocked so there is no question of accepting
        a parallel request thus no locks needed*/
        Dcm_Dsl_Prv_SetDslState((DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E));
        Dcm_Dsd_Prv_SetDsdState(DSD_CALL_SERVICE_E);
    }
    else
    {
        /* DcmAppl_DcmConfirmation is already called above.Hence do not call again. */
        Dcm_isApplicationCalled_b = TRUE;

        Dcm_KWPConfirmationForSplitResp(DCM_RES_POS_OK);

        /* in case of negative Tx confirmation or if all the split responses have been sent */
        Dcm_isFirstReponseSent_b = FALSE;
        Dcm_isApplicationCalled_b = FALSE;
    }
}
#endif

#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF) )
/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetNewSession
 Syntax           : Dcm_Prv_SetNewSession(void)
 Description      : In this function the session is changed immediately to avoid delays in setting
                    a new session there by ensuring that the new request coming in with lower priority or same priority
                    is not accepted for reception. Also this function shall be called only from the DSC confirmation results
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
void Dcm_Prv_SetNewSession(void)
{
    uint8 nrSessions_u8 = 0u;
    uint8 idxSession_u8 = 0u;

    if(FALSE != Dcm_isResponseSentForDSCService())
    {
        /* store old session for invoking the session change later in next MainFunction to get new timings */
        Dcm_Prv_SetPreviousSessionIdx(Dcm_Prv_GetActiveSessionIdx());

        /* Calculate the number of sessions configured in ECU for particular protocol*/
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
        if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
        {
            nrSessions_u8 = DCM_CFG_NUM_KWP_SESSIONS;
        }
        else
        {
            nrSessions_u8 = DCM_CFG_NUM_UDS_SESSIONS;
        }
#else
        nrSessions_u8 = DCM_CFG_NUM_UDS_SESSIONS;
#endif

        /* get the index of requested session id in session look up table */
        for(idxSession_u8 = 0x0; idxSession_u8 < nrSessions_u8 ; idxSession_u8++)
        {
            if(Dcm_Prv_GetSession(idxSession_u8)== Dcm_Dsp_Session[Dcm_ctDiaSess_u8].session_level)
            {
                /* session found - Set the new session to ensure that there are no requests of lower/same
                 * priority protocol received*/
                Dcm_Prv_SetActiveSessionIdx(idxSession_u8);
                break;
            }
        }
        /* Update the status flag to identify that the session is stored in confirmation */
        Dcm_Prv_SetSessionStoreFlag(TRUE);
    }
}
#endif

/*This Function is used to Process confirmation received for pending response*/
static void Dcm_ConfirmationForPendingResponse (Std_ReturnType Result)
{
    Dcm_ConfirmationStatusType confirmationStatus = DCM_RES_NEG_NOT_OK;
    uint32 DataTimeOutMonitor_u32;
    uint32 DataP2StrTimerServerAdjust_u32;
    Dcm_DsdStatesType_ten getDsdstatus_u8;
    boolean isforcepending_b;

    if(E_OK == Result)
    {
        confirmationStatus = DCM_RES_NEG_OK;

        DataP2StrTimerServerAdjust_u32 = Dcm_Prv_GetActive_P2StrServerTimeAdjust();
        DCM_TimerStart(DataTimeOutMonitor_u32,
                          (Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 - DataP2StrTimerServerAdjust_u32),
                           Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
        Dcm_Prv_Set_DataTimeOut(DataTimeOutMonitor_u32);
    }
    if(FALSE != Dcm_Prv_isForcePendingResponse())
    {
#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)
       Dcm_Prv_ConfirmationRespPendForBootloader(confirmationStatus);
#endif
       (void)Dcm_ConfirmationRespPend(confirmationStatus);
    }
    if(DSL_STATE_WAITFOR_TXCONFIRMATION_E == Dcm_Dsl_Prv_GetDslState())
    {
        getDsdstatus_u8=Dcm_Dsd_Prv_GetDsdState();
        isforcepending_b=Dcm_Prv_isForcePendingResponse();
        if((DSD_WAITFORTXCONF_E == getDsdstatus_u8) && (FALSE == isforcepending_b ))
        {
            Dcm_Dsl_Prv_SetDslState(DSL_STATE_RESPONSETRANSMISSION_E);
        }
        else
        {
            Dcm_Dsl_Prv_SetDslState(DSL_STATE_P2MAX_TIMEMONITORING_E);
        }
    }

}


/*This Function is used to Process Confirmation received for current Response*/
void Dcm_Dsl_Prv_ConfirmationForCurrentResponse (Std_ReturnType Result)
{
    /* Reset S3 Timer*/
    Dcm_Prv_ReloadS3Timer();
#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF) )
    Dcm_Prv_SetNewSession();
#endif

    Dcm_Dsd_Prv_Confirmation(Result);
}

#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isConfirmationForRoeType2Response
 Syntax           : Dcm_Prv_isConfirmationForRoeType2Response(DcmTxPduId)
 Description      : This Inline function is used to check if confirmation for Roe Type2 is to be processed
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
static boolean Dcm_Prv_isConfirmationForRoeType2Response(PduIdType id)
{
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();
    if(NULL_PTR != ActiveRoeConnection)
    {
        return ((ActiveRoeConnection->roeTxPduId == id) && (Dcm_DsdRoe2State_en == DSD_WAITFORTXCONF_E));
    }
    else
    {
        return FALSE;
    }

}
#endif

/*This function is called by the lower layer (in general the PDU Router):
 Result = E_OK after the complete DCM I-PDU has successfully been transmitted,i.e. at the very endof the segmented
 TP transmit cycle.Within this function, the DCM shall unlock the transmit buffer.
Result = E_NOT_OK if an error (e.g. timeout) has occurred during the transmission of the DCM  I-PDU.
This enables unlocking of the transmit buffer and error handling.*/
void Dcm_TpTxConfirmation (PduIdType id,Std_ReturnType result)
{
    PduIdType idxRxPduId;
    PduIdType txPduId = Dcm_Prv_GetTxPduIdFromTxIndex(id);
/* BSWEXT-500 */
#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
    boolean isConfirmationForKWPResponse = FALSE;
#endif
/* END BSWEXT-500 */
    if(id >= DCM_CFG_INVALID_TX_PDUINDEX)
    {
        Dcm_Prv_Det(DCM_TPTXCONFIRMATION_ID,DCM_E_PARAM);
    }
    else
    {
        /* BSWEXT-533 */
        SchM_Enter_Dcm_Global();
#if(DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
        /* Received TxPduId belongs to OBD? */
        if(Dcm_Prv_IsTxPduIdOBD(txPduId))
        {
            Dcm_Prv_OBDProcessTxConfirmation(txPduId,result);
        }
        else
#endif
        {
            if(txPduId == Dcm_Prv_GetActiveTxPduId())
            {
                if(FALSE != Dcm_isConfirmationForPendingResponse())
                {
                    Dcm_Prv_SetInfinitePendingFlag(FALSE);
                    Dcm_ConfirmationForPendingResponse(result);

                    if(Dcm_Prv_isForcePendingResponse() != FALSE)
                    {
                        Dcm_Dsl_SetForcePendingFlag(FALSE);
                    }
                }
                else
                {
#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
                    if(FALSE != Dcm_Prv_isConfirmationForKWPResponse(result))
                    {
                        /* BSWEXT-500 */
                        isConfirmationForKWPResponse = TRUE;
                    }
                    else
#endif
                    {
                        Dcm_Dsl_Prv_ConfirmationForCurrentResponse(result);
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)

                        if(FALSE == Dcm_Prv_isHighPriorityRequestReceiving())
                        {
                            Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
                        }
#endif
                    }
                }
            }
#if((DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF))
            else
            {
                if(FALSE != Dcm_Prv_isConfirmationForRoeType2Response(txPduId))
                {
                    Dcm_Roe2TxResult_u8 = result;
                    Dcm_DsdRoe2State_en = DSD_SENDTXCONF_APPL_E;
                }
            }
#endif
            for(idxRxPduId = 0;idxRxPduId< DCM_CFG_TOTAL_RX_PDUID ; idxRxPduId++)
            {
                if(FALSE != Dcm_isConfirmationReceivedForNrc21Response(txPduId,idxRxPduId))
                {
                    Dcm_Prv_SetServiceId(DCM_SERVICEID_DEFAULT_VALUE,idxRxPduId);
                    break;
                }
            }
        }
        /* BSWEXT-533 */
        SchM_Exit_Dcm_Global();
/* BSWEXT-500 */
/* [$DD_BSWCODE 40607] */
#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
        if(isConfirmationForKWPResponse)
        {
            Dcm_Prv_ProcessConfirmationForKWPResponse();
        }
#endif
/* END BSWEXT-500 */
    }
    /*解决1ms不响应问题-202400313-lv(原因是诊断模块周期调用，接收太快，内部状态不能够及时的置位导致)-ETAS*/
    if(Dcm_Dsd_Prv_GetDsdState()== DSD_SENDTXCONF_APPL_E)
     {
		Dcm_Dsd_Prv_SendTx_Confirmation();
		Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest();
		#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
		Dcm_Prv_ProcessRequestInQueue();
		#endif
     }
}
/*The lower layer communication interface module confirms the transmission of a PDU,or the failure to transmit a PDU
 * for periodic transmission e.g RDPI*/
void Dcm_TxConfirmation (PduIdType TxPduId, Std_ReturnType result)
{

#if(DCM_CFG_RDPI_ENABLED == DCM_CFG_ON)
    const Dcm_DslPeriodicConnConfigType_tst* ActiveperiodicConnection = Dcm_Prv_GetActivePeriodicConnection();
    Dcm_DslPeriodicType2ConfigType_tst* ActivePeriodicType2Info = ActiveperiodicConnection->periodicType2Config_past;
    uint8 RdpiTxPduidIndex_u8 = 0u;
#endif

    (void)result;
    if(TxPduId >= DCM_CFG_INVALID_TX_PDUINDEX)
    {
        Dcm_Prv_Det(DCM_TXCONFIRMATION_ID,DCM_E_PARAM);
    }

#if(DCM_CFG_RDPI_ENABLED == DCM_CFG_ON)
    else
    {
        for(RdpiTxPduidIndex_u8 = 0; RdpiTxPduidIndex_u8 < ActiveperiodicConnection->totalTxPduId_u16; RdpiTxPduidIndex_u8++)
        {
            if(ActivePeriodicType2Info[RdpiTxPduidIndex_u8].txPduId == Dcm_Prv_GetTxPduIdFromTxIndex(TxPduId))
            {
                ActivePeriodicType2Info[RdpiTxPduidIndex_u8].isTxPduId_Busy = FALSE;
                break;
            }
        }
    }
#endif

}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
