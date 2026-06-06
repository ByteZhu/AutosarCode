#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "ComM_Dcm.h"
#include "Dcm_Prv.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
#define DCM_KWP_PROTOCOL         (0x80u)
#define DCM_KWP_MASK             (0xF0u)


#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isRequestQueued
 Syntax           : Dcm_Prv_isRequestQueued(DcmRxPduId,Result)
 Description      : This function is used to check whether request is queued and update the Dcm Queue state
 Parameter        : PduIdType,Std_ReturnType
 Return value     : boolean
 ***********************************************************************************************************************/
static boolean Dcm_Prv_isRequestQueued(PduIdType DcmRxPduId,
        Std_ReturnType Result)
{
    boolean isRequestQueued = TRUE;
    Dcm_DslStatesType_ten getDslstate;
    if((Dcm_QueueStructure_st.Dcm_QueHandling_en == DCM_QUEUE_IDLE) ||\
            (Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_FuncTesterPresent_b != FALSE))
    {
        isRequestQueued = FALSE;
    }
    else
    {
        getDslstate=Dcm_Dsl_Prv_GetDslState();
        /* if the Rx indication is for the queued request */
        if((Dcm_QueueStructure_st.Dcm_QueHandling_en == DCM_QUEUE_RUNNING) && \
                (getDslstate != DSL_STATE_IDLE_E))
        {
            if(E_OK == Result)
            {
                /* Queing of the second request is completed */
                Dcm_QueueStructure_st.Dcm_QueHandling_en = DCM_QUEUE_COMPLETED;
            }
            else
            {
                (void)Dcm_Prv_ProvideFreeBuffer(DcmRxPduId,TRUE);
                Dcm_QueueStructure_st.Dcm_QueHandling_en = DCM_QUEUE_IDLE;
            }
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b = FALSE;
        }
    }

    return isRequestQueued;
}
#endif


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDSendNRC21
 Description      : This Function sends NRC21
 Parameter        : PduIdType
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_OBDSendNRC21(PduIdType DcmRxPduId)
{
    PduInfoType pduInfo_st = {NULL_PTR,NULL_PTR,DCM_NEGATIVE_RESPONSE_LENGTH};
    Dcm_Prv_UpdateMetaData_Nrc21(DcmRxPduId,&pduInfo_st.MetaDataPtr);

    if(DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetMainConnection(DcmRxPduId)->channel_idx_u8))
    {
        if(E_OK != PduR_DcmTransmit(Dcm_Prv_GetMainConnection(DcmRxPduId)->txPduId,&pduInfo_st))
        {
            Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslServiceId_u8 = DCM_SERVICEID_DEFAULT_VALUE;
        }
    }
    else
    {
        Dcm_Prv_Det(DCM_TPRXINDICATION_ID , DCM_E_FULLCOMM_DISABLED );
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ResetOBDCopyRxDataStatus
 Description      : Reset OBDRxPduArray CopyRxData to false for all ID's except for the one received
 Parameter        : PduIdType
 Return value     : None
 ***********************************************************************************************************************/
void Dcm_Prv_ResetOBDCopyRxDataStatus(PduIdType id)
{
    PduIdType idxRxPduid = 0x00u;

    while(idxRxPduid < DCM_CFG_TOTAL_RX_PDUID)
    {
        /* Reset CopyRxData status for all RxPduId's except the one passed to this function */
        if(idxRxPduid != id)
        {
            Dcm_DslOBDRxPduArray_ast[idxRxPduid].Dcm_DslCopyRxData_b = FALSE;
        }
        idxRxPduid++;
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_AcceptOBDRequest
 Description      : This Function
                    1)updates OBD StateMachine
                    2)Start P2 timer
 Parameter        : PduIdType
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_AcceptOBDRequest(PduIdType id)
{
    if(id == Dcm_OBDGlobal_st.dataActiveRxPduId_u8)
    {
        Dcm_Prv_SetOBDState((DCM_OBD_REQUESTRECEIVED));
        DCM_TimerStart(Dcm_OBDGlobal_st.dataTimeoutMonitor_u32,\
                (DCM_CFG_DEFAULT_P2MAX_TIME - \
                        Dcm_Prv_GetObdActiveProtocolRow()->timStrP2ServerAdjust_u32),\
                        Dcm_OBDP2OrS3StartTick_u32,Dcm_OBDP2OrS3TimerStatus_uchr)
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_DiscardOBDRequest
 Description      : If reception of OBD request was unsuccessful, discard the request
                    and update the Global variables
 Parameter        : PduIdType,Std_ReturnType
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_DiscardOBDRequest(PduIdType id,Std_ReturnType Result)
{
#if(DCM_CALLAPPLICATIONONREQRX_ENABLED != DCM_CFG_OFF)
    if(FALSE != Dcm_DslOBDRxPduArray_ast[id].Dcm_DslCopyRxData_b)
    {
        (void)DcmAppl_TpRxIndication(id,Result);
    }
#else
    (void)Result;
#endif

    Dcm_DslOBDRxPduArray_ast[id].Dcm_DslServiceId_u8 = DCM_SERVICEID_DEFAULT_VALUE;

    if((Dcm_OBDGlobal_st.dataActiveRxPduId_u8 == id) && \
            (Dcm_Prv_GetOBDState() == DCM_OBD_REQUESTRECEIVING))
    {
        Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDRxIndication
 Description      : Based on the Id on which confirmation is received this function either
                    1: Accepts the request (in this case Active Diagnosis call is made)
                    2: Or Sends NRC21
 Parameter        : PduIdType
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_OBDRxIndication(PduIdType DcmRxPduId)
{
    if(FALSE == Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b)
    {
        if(FALSE != Dcm_Prv_GetProtocolRow(DcmRxPduId)->nrc21_b)
        {
            Dcm_Prv_OBDSendNRC21(DcmRxPduId);
        }
    }
    else
    {
        Dcm_CheckActiveDiagnosticStatus(Dcm_Prv_GetMainConnection(DcmRxPduId)->channel_idx_u8);
#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
        (void)DcmAppl_TpRxIndication(DcmRxPduId,E_OK);
#endif
        Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslServiceId_u8 = DCM_SERVICEID_DEFAULT_VALUE;
        Dcm_Prv_AcceptOBDRequest(DcmRxPduId);
    }
}

#endif  /* (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF) */

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isConsecutiveRequestReceived
 Syntax           : Dcm_Prv_isConsecutiveRequestReceived(DcmRxPduId)
 Description      : This Inline Function is used to check whether request is consecutive request
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isConsecutiveRequestReceived(PduIdType DcmRxPduId)
{
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_OFF)
    (void)DcmRxPduId;
#endif

    /*If the Communication Protocol is Active */

    return((Dcm_Prv_IsProtocolStarted() != FALSE)
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
            && (DcmRxPduId != Dcm_Prv_GetHighPrioPduid())
#endif
    );
}
#endif




#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isKWPRequestReceived
 Syntax           : Dcm_Prv_isKWPRequestReceived(idxProtocol_u8)
 Description      : This Inline function is used to Check if Request received is of KWP protocol
 Parameter        : uint8
 Return value     : boolean
 ***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isKWPRequestReceived(void)
{
    return(((Dcm_Prv_GetActiveProtocolType()) & DCM_KWP_MASK) == DCM_KWP_PROTOCOL);
}
#endif

/***********************************************************************************************************************
 Function name   : Dcm_Prv_ReloadP2maxValue
 Syntax          : Dcm_Prv_ReloadP2maxValue(DcmRxPduId,idxProtocol_u8)
 Description     : If it is new UDS protocol then we need to start P2 timer with default P2 max.
                   If it is new KWP then we need to start P2 timer with P2 max from corresponding protocol
                   Do nothing for consecutive requests.
                   If protocol preemption is not enabled and KWP protocol is not present then only UDS protocol is present
                   So already the UDS P2 timing is updated during Initialization. As a result no need to load the time again
                   Also after transition from non default to default session, default P2 timer is loaded in Dcm_Prv_SetSesCtrlType API
 Parameter       : PduIdType,uint8
 Return value    : None
 ***********************************************************************************************************************/
static void Dcm_Prv_ReloadP2maxValue(PduIdType DcmRxPduId)
{
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    uint8 idxKwpTiming_u8 = 0u;
    const Dcm_DslProtocolRowConfigType_tst * protocol_table_pcs; /* Pointer to protocol table */
    PduIdType rxPduId;
    rxPduId = Dcm_Prv_GetActiveRxPduId();
    protocol_table_pcs = Dcm_Prv_GetProtocolRow(rxPduId);
#endif

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    if(FALSE == Dcm_Prv_isConsecutiveRequestReceived(DcmRxPduId))
    {
        if(FALSE != Dcm_Prv_isKWPRequestReceived())
        {
            /* This is required for the first request of KWP. For consecutive requests  "Dcm_DsldTimer_st.dataTimeoutP2max_u32"
             *  get updated in protocol activation and might be get modified by ATP service */
            idxKwpTiming_u8 = protocol_table_pcs->timings_idx_u8;
            Dcm_DsldTimer_st.dataTimeoutP2max_u32 = Dcm_Dsld_default_timings_acs[idxKwpTiming_u8].P2_max_u32;
        }
        else
        {
            Dcm_DsldTimer_st.dataTimeoutP2max_u32 = DCM_CFG_DEFAULT_P2MAX_TIME;
        }
    }
#else
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    if(DcmRxPduId == Dcm_Prv_GetHighPrioPduid())
    {
        Dcm_DsldTimer_st.dataTimeoutP2max_u32 = DCM_CFG_DEFAULT_P2MAX_TIME;
    }
#endif
#endif

#if((DCM_CFG_KWP_ENABLED == DCM_CFG_OFF) && (DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_OFF))
    (void)DcmRxPduId;
#endif

}

static void Dcm_StartP2Timer(PduIdType DcmRxPduId)
{
    uint32 DataTimeOutMonitor_u32; /* To store the data timeout timer */
    uint32 DataP2TimerServerAdjust_u32;   /* To store the P2 server time adjust */
    (void)DcmRxPduId;

    DataP2TimerServerAdjust_u32 = Dcm_Prv_GetActive_P2ServerTimeAdjust();

    DCM_TimerStart(DataTimeOutMonitor_u32,
            (Dcm_DsldTimer_st.dataTimeoutP2max_u32 - DataP2TimerServerAdjust_u32),
            Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)

    /* Update the timeout timer */
    Dcm_Prv_Set_DataTimeOut(DataTimeOutMonitor_u32);
}

/***********************************************************************************************************************
 Function name    : Dcm_SetuptimerhighprioId
 Syntax           : Dcm_SetuptimerhighprioId(DcmRxPduId)
 Description      : This is to set the p2timer , and pduid
 Parameter        : PduIdType
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_SetuptimerhighprioId (PduIdType DcmRxPduId)
{
    Dcm_StartP2Timer(DcmRxPduId);
    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b=FALSE;
    Dcm_Prv_SetHighPrioPduid(DCM_CFG_INVALID_RX_PDUID);
}

/***********************************************************************************************************************
 Function name    : Dcm_SendNrc21
 Syntax           : Dcm_SendNrc21(DcmRxPduId)
 Description      : This is the indication of faking complete reception of the low-priority protocol, now trigger NRC-21
 Parameter        : PduIdType
 Return value     : None
 ***********************************************************************************************************************/

/*TRACE BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3321*/
static void Dcm_SendNrc21(PduIdType DcmRxPduId)
{
    PduInfoType pduInfo_st;

    if(TRUE==DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetActiveComMChannelIndex()))
    {
        pduInfo_st.SduDataPtr = NULL_PTR;
        pduInfo_st.MetaDataPtr = NULL_PTR;
        pduInfo_st.SduLength = DCM_NEGATIVE_LENGTH_RESPONSE;
        Dcm_Prv_UpdateMetaData_Nrc21(DcmRxPduId, &pduInfo_st.MetaDataPtr);

        if(E_OK != PduR_DcmTransmit(Dcm_Prv_GetTxPduId(DcmRxPduId), &pduInfo_st))
        {
            Dcm_Prv_SetServiceId(DCM_DEFAULT_SERVICEID,DcmRxPduId);
        }
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessFunctionalTP
 Syntax           : Dcm_Prv_ProcessFunctionalTP(DcmRxPduId)
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/

static void Dcm_Prv_ProcessFunctionalTP(PduIdType DcmRxPduId)
{
    DcmAppl_DcmIndicationFuncTpr();

    Dcm_Prv_SetFunctionalTPStatusFlag(DcmRxPduId,FALSE);

    if(FALSE == Dcm_Prv_isRequestReceivedOnOtherConnection(DcmRxPduId))
    {
        if(DSL_STATE_IDLE_E == Dcm_Dsl_Prv_GetDslState())
        {
            Dcm_Prv_ReloadS3Timer();
        }
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED != DCM_CFG_OFF)
        Dcm_Prv_AuthTimerHandling(DCM_TIMER_STOP,DcmRxPduId);
#endif
    }
}


static void Dcm_DiscardRequest(PduIdType DcmRxPduId,Std_ReturnType Result)
{
    PduIdType ActiveRxpduId;
    Dcm_DslStatesType_ten DslState_en;

#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
    if(Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b)
    {
        (void)DcmAppl_TpRxIndication(DcmRxPduId,Result);
    }
#else
    (void)Result;
#endif

    /*Reset Request info present in Dcm_PduInfo_st and Dcm_RequestInfo_ast associated with DcmRxPduId*/
    Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr=NULL_PTR;
    Dcm_PduInfo_ast[DcmRxPduId].SduLength=0x00u;

    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_FuncTesterPresent_b=FALSE;
    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b=FALSE;
    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId=DCM_CFG_INVALID_RX_PDUID;
    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_ServiceId_u8=DCM_DEFAULT_SERVICEID;
    Dcm_Prv_SetFunctionalTPStatusFlag(DcmRxPduId,FALSE);

    ActiveRxpduId = Dcm_Prv_GetActiveRxPduId();
    DslState_en   = Dcm_Dsl_Prv_GetDslState();
    if((DcmRxPduId == ActiveRxpduId) && (DSL_STATE_WAITFOR_RXINDICATION_E == DslState_en))
    {
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
        /*Reset S3 Timer*/
        Dcm_Prv_ReloadS3Timer();
    }

#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    if(DcmRxPduId == Dcm_Prv_GetHighPrioPduid())
    {
        Dcm_Prv_SetHighPrioPduid(DCM_CFG_INVALID_RX_PDUID);
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
        /*Reset S3 Timer*/
        Dcm_Prv_ReloadS3Timer();
        Dcm_Dsl_Prv_SetPreemptionState(DSL_PREEMPTION_STATE_IDLE_E);
    }
#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    if(DcmRxPduId == Dcm_Prv_GetRoeProtocolPduid())
    {
        Dcm_Prv_SetRoeProtocolPduid(DCM_CFG_INVALID_RX_PDUID);
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
        Dcm_Prv_ReloadS3Timer();
    }
#endif
#endif

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_AuthTimerHandling(DCM_TIMER_STOP,DcmRxPduId);
#endif

}
/***********************************************************************************************************************
 Function name    : Dcm_CheckDiagnosticStatus
 Syntax           : Dcm_CheckDiagnosticStatus()
 Description      : This function is used to Check the Diagnostic status and inform ComM module so that channel enters in
                    full communication mode.
 Parameter        :
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_CheckDiagnosticStatus(PduIdType DcmRxPduId,
        uint8 idxProtocol_u8,const uint8 * RxBuffer_pu8)
{
    if(FALSE == Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_FuncTesterPresent_b)
    {
        if (idxProtocol_u8 == Dcm_Prv_GetActiveProtocolType())
        {
            if((Dcm_Prv_GetActiveSessionIdx() == DCM_DEFAULT_SESSION_IDX) && (RxBuffer_pu8 != NULL_PTR))
            {
                Dcm_CheckActiveDiagnosticStatus(Dcm_active_commode_e[Dcm_Prv_GetMainConnection(DcmRxPduId)->channel_idx_u8].ComMChannelId);
            }
        }
        else
        {
            if(FALSE != Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b)
            {
                Dcm_CheckActiveDiagnosticStatus(Dcm_active_commode_e[Dcm_Prv_GetMainConnection(DcmRxPduId)->channel_idx_u8].ComMChannelId);
            }
        }
    }

}

#if((DCM_ROE_ENABLED == DCM_CFG_ON) && (DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_ON))
static void Dcm_Prv_ProcessHighPriorityReqWhileRoeEvent(PduIdType DcmRxPduId)
{
    if(DSL_STATE_WAITFOR_RXINDICATION_E == Dcm_Dsl_Prv_GetDslState())
    {
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E);
        Dcm_Prv_SetActiveRxPduId(DcmRxPduId,Dcm_Dsl_Prv_GetActiveRequestDataLen());
        Dcm_Prv_SetRoeProtocolPduid(DCM_CFG_INVALID_RX_PDUID);
    }
    else
    {

        Dcm_Dsl_Prv_SetPreemptionState(DSL_PREEMPTION_STOP_ROE_E);
        Dcm_Prv_SetActiveRxPduId(DcmRxPduId,Dcm_Dsl_Prv_GetActiveRequestDataLen());
        Dcm_Prv_SetRoeProtocolPduid(DCM_CFG_INVALID_RX_PDUID);
    }

    /* Start timer */
    Dcm_StartP2Timer(DcmRxPduId);
}
#endif

/***********************************************************************************************************************
 Function name    : Dcm_ProcessRxIndication
 Syntax           : Dcm_ProcessRxIndication(DcmRxPduId)
 Description      : This Function is used to Process the request funrther based on the Indication received from the
                    Lower layer
 Parameter        : PduIdType
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_ProcessRxIndication(PduIdType DcmRxPduId)
{
    Dcm_Prv_ReloadP2maxValue(DcmRxPduId);

#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_ON)
    if((DCM_CFG_INVALID_RX_PDUID) != Dcm_Prv_GetHighPrioPduid())
    {
        uint8 currentcomChannelId;
        /*Get the active com channel Id*/
        uint8 activecomChannelId=Dcm_Prv_GetActiveComMChannelId();
        /*update the Dcm_Prv_SetActiveRxPduId with the highPrio pduid*/
        Dcm_Prv_SetActiveRxPduId(DcmRxPduId,Dcm_Prv_Get_CurrentRequestLength());
        /*Get the hignprio or current comchannel Id*/
        currentcomChannelId=Dcm_Prv_GetActiveComMChannelId();
        /*Check if channel is active for current protocol*/
        if(activecomChannelId !=currentcomChannelId)
        {
            ComM_DCM_InactiveDiagnostic(activecomChannelId);
        }
        Dcm_Dsl_Prv_SetPreemptionState(DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E);
        Dcm_SetuptimerhighprioId (DcmRxPduId);
#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
        Dcm_Prv_SetRoeProtocolPduid(DCM_CFG_INVALID_RX_PDUID);
#endif
#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
        (void)DcmAppl_TpRxIndication(DcmRxPduId,E_OK);
#endif
    }
#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    else if(DcmRxPduId == Dcm_Prv_GetRoeProtocolPduid())
    {
        Dcm_Prv_ProcessHighPriorityReqWhileRoeEvent(DcmRxPduId);
    }
#endif
    else
#endif
    {
        if(DcmRxPduId!=Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId)
        {
            Dcm_Prv_Det(DCM_TPRXINDICATION_ID ,DCM_E_PARAM);
        }
        else
        {
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
            Dcm_Prv_SetRxBuffer(Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8);
#endif
            Dcm_Dsl_Prv_SetDslState(DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E);
            Dcm_SetuptimerhighprioId (DcmRxPduId);
#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
            (void)DcmAppl_TpRxIndication(DcmRxPduId,E_OK);
#endif
        }

    }
}

#if(DCM_CFG_RXPDU_SHARING_ENABLED == DCM_CFG_ON)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessSharedPduId
 Syntax           : Dcm_Prv_ProcessSharedPduId(&RxPduIdPtr)
 Description      : This Function is used to update the shared Pduid
 Parameter        : PduIdType*
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_ProcessSharedPduId(PduIdType * RxPduIdPtr)
{
    if(((*RxPduIdPtr) < (DCM_CFG_TOTAL_RX_PDUID-1u)) && ((*RxPduIdPtr) == DCM_CFG_SHARED_RX_PDUID) && \
            (Dcm_isObdRequestReceived_b == TRUE))
    {
        *RxPduIdPtr = (DCM_CFG_TOTAL_RX_PDUID-1u);
        Dcm_isObdRequestReceived_b = FALSE;
    }
}
#endif

/*
 ***********************************************************************************************************
 *  Dcm_TpRxIndication :This function is called by the lower layer (in general the PDU Router):
 *  - with Result = E_OK after the complete DCM I-PDU has successfully been received, i.e. at the very
 *    end of the segmented TP receive cycle or after receiving an unsegmented N-PDU.
 *  - with Result = E_NOT_OK it is indicated that an error (e.g. timeout) has occurred during
 *    the reception of the DCM I-PDU. This passes the receive buffer back to DCM and allows error handling.
 *    It is undefined which part of the buffer contains valid data in this case, so the DCM shall not evaluate
 *    that buffer. By calling this service only the DCM is allowed to access the buffer.
 *
 *  \param:   id             ID of DCM I-PDU that has been received. Identifies the data that has been received.
 *            result         Result of the N-PDU reception:
 *                           E_OK if the complete N-PDU has been received.
 *                           E_NOT_OK if an error occurred during reception, used to enable
 *                           unlocking of the receive buffer.
 *  \retval   None
 *  \seealso
 *  \usedresources
 ***********************************************************************************************************/
void Dcm_TpRxIndication (
        PduIdType id,
        Std_ReturnType result
)
/*TRACE BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3190
 *      BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3383*/
{
    uint8 idxProtocol_u8 ;
    const uint8 * rxBuffer_pu8 = NULL_PTR;

    if(DCM_CFG_TOTAL_RX_PDUID <= id)
    {
        Dcm_Prv_Det(DCM_TPRXINDICATION_ID,DCM_E_PARAM);
    }
    else
    {
#if(DCM_CFG_RXPDU_SHARING_ENABLED == DCM_CFG_ON)
        /* BSWEXT-533 */
        SchM_Enter_Dcm_Global();
        Dcm_Prv_ProcessSharedPduId(&id);
        /* BSWEXT-533 */
        SchM_Exit_Dcm_Global();
#endif
        idxProtocol_u8  = Dcm_Prv_GetProtocolRow(id)->protocolType;
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
        rxBuffer_pu8 = (Dcm_ReceptionInfo_ast[id].Dcm_DslBufferPtr_pu8);
#else
        rxBuffer_pu8 = Dcm_Prv_GetProtocolRow(id)->rxBuffer_u8;
#endif
        /* BSWEXT-533 */
        SchM_Enter_Dcm_Global();

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
        if(FALSE == Dcm_Prv_isRequestQueued(id,result))
#endif
        {

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
            if(Dcm_Prv_IsRxPduIdOBD(id))
            {
                (E_OK == result)?Dcm_Prv_OBDRxIndication(id):Dcm_Prv_DiscardOBDRequest(id,result);
            }
            else
#endif
            {
                if(E_OK==result)
                {
                    Dcm_CheckDiagnosticStatus(id,idxProtocol_u8,rxBuffer_pu8);

                    if(TRUE!=Dcm_Prv_GetRequestProcessingFlag(id))
                    {
                        if(FALSE!=Dcm_Prv_GetFunctionalTPStatusFlag(id))
                        {
                            Dcm_Prv_ProcessFunctionalTP(id);
                        }
                        else if (FALSE != Dcm_Prv_GetRespOnSecondDeclinedRequest(id))
                        {
                            Dcm_SendNrc21(id);
                        }
                        else
                        {
                            /*do nothing*/
                        }
                    }
                    else
                    {
                        Dcm_ProcessRxIndication(id);
                    }
                }
                /*TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3190]*/
                else
                {
                    Dcm_DiscardRequest(id,result);
                }
            }

        }
        /* BSWEXT-533 */
        SchM_Exit_Dcm_Global();
    }
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
