
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "ComM_Dcm.h"
#include "Dcm_Prv.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
PduInfoType Dcm_Dsl_Respone_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
boolean Dcm_isFirstReponseSent_b;  /* flag for KWP first response sent when the split response feature is enabled */
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
#endif


/***********************************************************************************************************************
 *    Inline Function Definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 Function name    : Dcm_Prv_isDcmWaitingForTxConfirmation
 Syntax           : Dcm_Prv_isDcmWaitingForTxConfirmation(void)
 Description      : This Inline Function is used to check if Dcm is wating for the Confirmation from the lower layer
 Parameter        : None
 Return value     : None
 ***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isDcmWaitingForTxConfirmation(void)
{
    Dcm_DslStatesType_ten Dcm_DslState_en =  Dcm_Dsl_Prv_GetDslState();

    return (!((Dcm_DslState_en == DSL_STATE_P2MAX_TIMEMONITORING_E) || \
            (Dcm_DslState_en == DSL_STATE_RESPONSETRANSMISSION_E) || \
            (Dcm_DslState_en == DSL_STATE_ROETYPE1_RECEIVED_E)));
}


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
 */

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"


#if((DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF) && (DCM_CALLAPPLICATIONONREQRX_ENABLED != DCM_CFG_OFF))
/***********************************************************************************************************************
 Function name    : Dcm_Prv_InformApplicationAfterQueueComplete
 Syntax           : Dcm_Prv_InformApplicationAfterQueueComplete(QueueHandlingTemp_en)
 Description      : This Function is used to inform application when Queued request is processed
 Parameter        : Dcm_DsldQueHandling_ten
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_InformApplicationAfterQueueComplete (Dcm_DsldQueHandling_ten QueueHandlingTemp_en)
{
    const Dcm_MsgItemType * RequestBuffer = Dcm_Prv_GetActiveRxBuffer();

    if(QueueHandlingTemp_en == DCM_QUEUE_RUNNING)
    {
        /*TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-7412]*/
        (void)DcmAppl_StartOfReception(Dcm_ReceptionInfo_ast[Dcm_Prv_GetActiveRxPduId()].Dcm_DslBufferPtr_pu8[0],\
                Dcm_Prv_GetActiveRxPduId(),\
                Dcm_Dsl_Prv_GetActiveRequestDataLen(),\
                ((Dcm_ReceptionInfo_ast[Dcm_Prv_GetActiveRxPduId()].Dcm_DslBufferPtr_pu8)));

        (void)DcmAppl_CopyRxData(Dcm_Prv_GetActiveRxPduId(),\
                ((Dcm_QueueStructure_st.dataQueueReqLength_u16 - Dcm_PduInfo_ast[Dcm_Prv_GetActiveRxPduId()].SduLength)));
    }
    else
    {
        if(QueueHandlingTemp_en == DCM_QUEUE_COMPLETED)
        {
            /*TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-7412]*/
            (void)DcmAppl_StartOfReception(RequestBuffer[0],\
                    Dcm_Prv_GetActiveRxPduId(),\
                    Dcm_Dsl_Prv_GetActiveRequestDataLen(),\
                    (Dcm_Prv_GetActiveRxBuffer()));

            (void)DcmAppl_CopyRxData(Dcm_Prv_GetActiveRxPduId(),Dcm_Dsl_Prv_GetActiveRequestDataLen());

            (void)DcmAppl_TpRxIndication(Dcm_Prv_GetActiveRxPduId(),E_OK);
        }
    }
}
#endif





#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessRequestInQueue
 Syntax           : Dcm_Prv_ProcessRequestInQueue(void)
 Description      : This Function is used to take up the Queued request for processing
 Parameter        : None
 Return value     : None
 ***********************************************************************************************************************/
void Dcm_Prv_ProcessRequestInQueue(void)
{
    Dcm_DsldQueHandling_ten QueueHandlingTemp_en;

    uint32 dataTimeOutMonitor_u32; /* To store the data timeout timer */
    uint32 DataP2TimerServerAdjust_u32;   /* To store the P2 server time adjust */

    /* BSWEXT-533 */
    SchM_Enter_Dcm_Global();
    QueueHandlingTemp_en = Dcm_QueueStructure_st.Dcm_QueHandling_en;
    /* BSWEXT-533 */
    SchM_Exit_Dcm_Global();

    switch(QueueHandlingTemp_en)
    {
        case DCM_QUEUE_IDLE :
            /* BSWEXT-533 */
            SchM_Enter_Dcm_Global();

            Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);

            /* BSWEXT-533 */
            SchM_Exit_Dcm_Global();
            break;

        case DCM_QUEUE_RUNNING :

            /* BSWEXT-533 */
            SchM_Enter_Dcm_Global();

            Dcm_Prv_SetActiveRxPduId(Dcm_QueueStructure_st.dataQueueRxPduId_u8,Dcm_QueueStructure_st.dataQueueReqLength_u16);

            Dcm_ReceptionInfo_ast[Dcm_Prv_GetActiveRxPduId()].Dcm_DslBufferPtr_pu8 = Dcm_QueueStructure_st.adrBufferPtr_pu8;

            Dcm_QueueStructure_st.Dcm_QueHandling_en = DCM_QUEUE_IDLE;

            Dcm_Dsl_Prv_SetDslState(DSL_STATE_WAITFOR_RXINDICATION_E);

            /* BSWEXT-533 */
            SchM_Exit_Dcm_Global();

#if(DCM_CALLAPPLICATIONONREQRX_ENABLED != DCM_CFG_OFF)
            Dcm_Prv_InformApplicationAfterQueueComplete(DCM_QUEUE_RUNNING);
#endif

            break;

        case DCM_QUEUE_COMPLETED :

            /* BSWEXT-533 */
            SchM_Enter_Dcm_Global();
            if (Dcm_Prv_GetActiveSession() == DCM_DEFAULT_SESSION)
            {
                Dcm_CheckActiveDiagnosticStatus(Dcm_active_commode_e[Dcm_Prv_GetMainConnection(Dcm_QueueStructure_st.dataQueueRxPduId_u8)->channel_idx_u8].ComMChannelId);
            }

            /* move all the Dcm Queue variables to active variable */
            Dcm_Prv_SetActiveRxPduId(Dcm_QueueStructure_st.dataQueueRxPduId_u8,Dcm_QueueStructure_st.dataQueueReqLength_u16);

            Dcm_Prv_SetRxBuffer(Dcm_QueueStructure_st.adrBufferPtr_pu8);

            Dcm_Dsl_Prv_SetDslState(DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E);


            Dcm_QueueStructure_st.Dcm_QueHandling_en = DCM_QUEUE_IDLE;

            /* BSWEXT-533 */
            SchM_Exit_Dcm_Global();

            dataTimeOutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();

            DataP2TimerServerAdjust_u32 = Dcm_Prv_GetActive_P2ServerTimeAdjust();

            DCM_TimerStart(dataTimeOutMonitor_u32,(Dcm_DsldTimer_st.dataTimeoutP2max_u32-Dcm_Prv_GetActive_P2ServerTimeAdjust()), \
                    Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)

            /* Update the timeout timer */
            Dcm_Prv_Set_DataTimeOut(dataTimeOutMonitor_u32);

#if(DCM_CALLAPPLICATIONONREQRX_ENABLED != DCM_CFG_OFF)
            Dcm_Prv_InformApplicationAfterQueueComplete(DCM_QUEUE_COMPLETED);
#endif
            break;

        default :
            /*Do nothing*/
            break;
    }
}
#endif



#if(DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDSendResponse
 Description      : Transmit the stored OBD Response
 Parameter        : const PduInfoType*
 Return value     : None
 ***********************************************************************************************************************/

void Dcm_Prv_OBDSendResponse(const PduInfoType* adrPduStrucutre_pcst)
{
    boolean dataResult_b = TRUE;

    /* ComM should be in FULL COM mode to sending the response */
    if(DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetObdActiveConnection()->channel_idx_u8))
    {
        /* Trigger response in PduR */
        if(PduR_DcmTransmit(Dcm_OBDGlobal_st.dataActiveTxPduId_u8,adrPduStrucutre_pcst) == E_NOT_OK)
        {
            dataResult_b = FALSE; // Unable to Transmit
        }
    }
    else
    {
        dataResult_b = FALSE; /* COMM not in Full Communication Mode */
    }

    if(dataResult_b == FALSE)
    {
        // Transmission is unsuccessful for wait pend transmission
        if(Dcm_OBDGlobal_st.cntrWaitpendCounter_u8 > 0x0u)
        {
            /* Unable to send wait pend, again go to P2 max monitoring */
            Dcm_Prv_SetOBDState((Dcm_Prv_GetOBDPreviousState()));
        }
        else
        {
            /* Triggering of Tx fails */
            Dcm_OBDGlobal_st.dataResult_u8 = E_NOT_OK;
            Dcm_OBDisGeneralRejectSent_b = FALSE;
            Dcm_ObdSendTxConfirmation_b = TRUE;
            Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
            if(FALSE != Dcm_Prv_CanComMBeInactivated(DCM_OBDCONTEXT))
            {
                ComM_DCM_InactiveDiagnostic(Dcm_Prv_GetObdActiveConnection()->comMChannelId_u8);
            }
        }
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDTriggerTransmit
 Description      : Function to prepare the response in case of OBD reponse for parallel OBD/UDS transmission
 Parameter        : void
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_OBDTriggerTransmit(void)
{
    /* Check if the call is for Suppression of Response */
    if(Dcm_OBDTransmit_st.TxResponseLength_u32 != 0x00u)
    {
        /* Multicore: Lock necessary here to block DSL/DSD state changes when parallel Rx or Dcm_MainFunction is running */
        /* BSWEXT-533 */
        SchM_Enter_Dcm_Global();
        /* update data in pdu structure */
        Dcm_OBDPduInfo_st.SduDataPtr = Dcm_OBDTransmit_st.TxBuffer_tpu8;
        Dcm_OBDPduInfo_st.SduLength = (PduLengthType) Dcm_OBDTransmit_st.TxResponseLength_u32;
        Dcm_Prv_UpdateMetaDataPointer(Dcm_Prv_GetObdActiveRxPduId(),&Dcm_OBDPduInfo_st.MetaDataPtr);
        /* final response comes now. reset the wait pend counter */
        Dcm_OBDGlobal_st.cntrWaitpendCounter_u8 = 0x0u;
        // Update OBD State to Wait for Tx Confirmation
        /* BSWEXT-533 */
        SchM_Exit_Dcm_Global();
        /* Trigger  response */
        Dcm_Prv_OBDSendResponse(&Dcm_OBDPduInfo_st);
    }
    else
    {
        /* simulate successful transmission of response */
        Dcm_OBDGlobal_st.dataResult_u8 = E_OK;
        /* indicate to DSD  */
        Dcm_ObdSendTxConfirmation_b = TRUE;
        Dcm_OBDMsgContext_st.msgAddInfo.suppressPosResponse = FALSE;
        Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
        if(FALSE != Dcm_Prv_CanComMBeInactivated(DCM_OBDCONTEXT))
        {
            ComM_DCM_InactiveDiagnostic(Dcm_Prv_GetObdActiveConnection()->comMChannelId_u8);
        }
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetOBDNegResponse
 Description      : Function to set Negative response for OBD
 Parameter        : const Dcm_MsgContextType*,Dcm_NegativeResponseCodeType
 Return value     : None
 ***********************************************************************************************************************/
void Dcm_Prv_SetOBDNegResponse(const Dcm_MsgContextType* pMsgContext,
        Dcm_NegativeResponseCodeType ErrorCode)
{
    if(pMsgContext->dcmRxPduId == Dcm_OBDGlobal_st.dataActiveRxPduId_u8)
    {
        /* check if this is the first call of Dcm_SetNegResponse() response */
        if(Dcm_OBDGlobal_st.stResponseType_en == DCM_POS_RESPONSE)
        {
            Dcm_OBDGlobal_st.stResponseType_en = DCM_NEG_RESPONSE;
            Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[0]= DCM_NEGRESPONSE_INDICATOR;
            Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[1]= Dcm_OBDGlobal_st.dataSid_u8;
            Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[2]= ErrorCode;
        }
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_OBDProcessingDone
 Description      : Function to initialize the transmission structure before response transmission for OBD
 Parameter        : const Dcm_MsgContextType*
 Return value     : None
 ***********************************************************************************************************************/
void Dcm_OBDProcessingDone(const Dcm_MsgContextType* pMsgContext)
{
    uint8 dataNrc_u8 = 0x00;
    uint32 AvailBufSize_u32 = 0x00;

    /* Ensure transmission is for an accepted request of a client (DcmRxPduId)
     * Should not be processed in other cases (eg: BusyRepeatRequest Tx) for a different client */
    if(pMsgContext->dcmRxPduId == Dcm_OBDGlobal_st.dataActiveRxPduId_u8)
    {
        Dcm_Prv_SetOBDState((DCM_OBD_WAITFORTXCONF));
        // Remaining buffer size in Dcm after entire response is filled
        AvailBufSize_u32 = pMsgContext->resMaxDataLen - pMsgContext->resDataLen;
        if(Dcm_OBDGlobal_st.stResponseType_en == DCM_POS_RESPONSE)
        {
            /* Response is not triggered by DSD */
            if(Dcm_OBDGlobal_st.dataResponseByDsd_b == FALSE )
            {
                // Application can add extra bytes at the end of response
                DcmAppl_DcmModifyResponse(Dcm_OBDGlobal_st.dataSid_u8,dataNrc_u8,
                        &(pMsgContext->resData[pMsgContext->resDataLen]),&AvailBufSize_u32);
            }
            if(FALSE != (pMsgContext->msgAddInfo).suppressPosResponse)
            {
                Dcm_OBDTransmit_st.TxBuffer_tpu8 = NULL_PTR;
                Dcm_OBDTransmit_st.TxResponseLength_u32 = 0x00u;
            }
            else
            {
                /* Frame the positive response. For positive response 0x40 is added to SID */
                Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[2] = Dcm_OBDGlobal_st.dataSid_u8 | 0x40u;
                Dcm_OBDTransmit_st.TxBuffer_tpu8 = & Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[2];
                /* Fill the total response length including Sid */
                Dcm_OBDTransmit_st.TxResponseLength_u32 = pMsgContext->resDataLen + 1u + AvailBufSize_u32;
            }
        }
        else
        {
            /* Negative response not triggered by DSD */
            if(Dcm_OBDGlobal_st.dataResponseByDsd_b == FALSE )
            {
                // Application can modify the NRC value
                DcmAppl_DcmModifyResponse(Dcm_OBDGlobal_st.dataSid_u8, Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[2],
                        &(Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[2]),&AvailBufSize_u32);
            }
            if(pMsgContext->dcmRxPduId >= DCM_CFG_INDEX_FUNC_RX_PDUID)
            {
                dataNrc_u8 = Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[2];
                /*Check for the negative response code and whether Wait pend counter is set to 0*/
                if((Dcm_Dsd_isObdNegativeResponseSupressed(dataNrc_u8))
                        &&(Dcm_OBDGlobal_st.cntrWaitpendCounter_u8 == 0x00u))
                {
                    /* Reset the P2 timer and DSL state machine and get the confirmation
                     suppress the Negative response */
                    Dcm_OBDTransmit_st.TxBuffer_tpu8 = NULL_PTR;
                    Dcm_OBDTransmit_st.TxResponseLength_u32 = 0x00u;
                }
                else
                {
                    /* give the Tx pointer from the starting of the tx buffer */
                    Dcm_OBDTransmit_st.TxBuffer_tpu8 = Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8;
                    Dcm_OBDTransmit_st.TxResponseLength_u32 = 0x03u;
                }
            }
            else
            {
                /* This is Physical request, suppression is not allowed.Send Negative response */
                Dcm_OBDTransmit_st.TxBuffer_tpu8 = Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8;
                /* response data length including 0x7f, Sid, NRC */
                Dcm_OBDTransmit_st.TxResponseLength_u32 = 0x03u;
            }
        }
        Dcm_Prv_OBDTriggerTransmit();
    }
}
#endif

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isKWPSplitResponseTimeout
 Syntax           : Dcm_Prv_isKWPSplitResponseTimeout(void)
 Description      : This Inline function is used to check check if KWP split response timeout has occured
 Parameter        : None
 Return value     : boolean
 ***********************************************************************************************************************/
boolean Dcm_Prv_isKWPSplitResponseTimeout(void)
{
    boolean isResponseTimeout_b = FALSE;
    Dcm_DsdStatesType_ten stDsdStateTemp_en  = Dcm_Dsd_Prv_GetDsdState();
    Dcm_SesCtrlType getActiveSession;
    getActiveSession=Dcm_Prv_GetActiveSession();

    if((DCM_IS_KWPPROT_ACTIVE() != FALSE) && (Dcm_isFirstReponseSent_b!=FALSE) && \
            (getActiveSession == DCM_DEFAULT_SESSION_IDX) && \
            ((stDsdStateTemp_en == DSD_CALL_SERVICE_E)||(stDsdStateTemp_en == DSD_WAITFORTXCONF_E)))
    {
        isResponseTimeout_b = TRUE;
    }

    return isResponseTimeout_b;
}
#endif


void Dcm_Dsl_SetForcePendingFlag(boolean value)
{
    Dcm_DslTransmit_st.isForceResponsePendRequested_b = value;
}

/***********************************************************************************************************************
 Function name    : Dcm_Dsl_ResponseTypeCheck
 Syntax           : Dcm_Dsl_ResponseTypeCheck(void)
 Description      : This Function is used to Check whether the response is pending response or force pending and
                    updating the state machine accordingly
 Parameter        : None
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Dsl_ResponseTypeCheck(void)
{
    if(FALSE==Dcm_Dsl_Prv_isItPendingResponse())
    {
        if (FALSE==Dcm_Prv_isForcePendingResponse())
        {
            Dcm_Dsl_Prv_ConfirmationForCurrentResponse(E_NOT_OK);

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
            Dcm_Prv_ProcessRequestInQueue();
#else
            Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
#endif
        }
        else
        {
#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)
            Dcm_Prv_ConfirmationRespPendForBootloader(DCM_RES_NEG_NOT_OK);
#endif
            Dcm_Dsl_SetForcePendingFlag(FALSE);
            Dcm_Prv_SetResponsetype(DCM_NEG_RESPONSE);
            Dcm_Dsd_Prv_Confirmation(E_NOT_OK);
        }
    }
    else
    {
        /*Update DSL state so that Dcm can again monitor P2 timer*/
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_P2MAX_TIMEMONITORING_E);
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_CheckP2StarTimer
 Syntax           : Dcm_CheckP2StarTimer(void)
 Description      : This Function is used toCheck if time difference between two pending responses is greater than half
                    of P2*Max
 Parameter        : None
 Return value     : Boolean
 ***********************************************************************************************************************/

static boolean Dcm_CheckP2StarTimer(void)
{
    boolean halfP2timeStatus = FALSE;
    uint32 halfP2timer_u32   = 0u;

#if(DCM_CFG_OSTIMER_USE != FALSE)
    uint32 currentOSTimerTicks_u32 = 0u;
#endif

    if(Dcm_Dsl_Prv_GetRespPendingCounterValue() == 0u)
    {
        halfP2timeStatus = TRUE;
    }
    else
    {
        halfP2timer_u32 = Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 >> 1u;

#if(DCM_CFG_OSTIMER_USE != FALSE)
        /* Get the current ticks from system timer  */
        Dcm_P2OrS3TimerStatus_uchr = Dcm_GetCounterValue(DCM_CFG_COUNTERID, (&currentOSTimerTicks_u32));

        if (E_OK == Dcm_P2OrS3TimerStatus_uchr)
        {
            if((DCM_CFG_TICKS2US_COUNTER(currentOSTimerTicks_u32 - Dcm_P2OrS3StartTick_u32)) >= (halfP2timer_u32))
            {
                halfP2timeStatus = TRUE;
            }
        }
        else
        {
            if(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32 < (halfP2timer_u32/DCM_CFG_TASK_TIME_US))
            {
                halfP2timeStatus = TRUE;
            }
        }
#else
        if(Dcm_Prv_Get_DataTimeOut() < (halfP2timer_u32/DCM_CFG_TASK_TIME_US))
        {
            halfP2timeStatus = TRUE;
        }
#endif
    }
    return(halfP2timeStatus);
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_TriggerTransmit
 Syntax           : void Dcm_Prv_TriggerTransmit(PduLengthType Sdulength)
 Description      : This Function is used to Transmit the Response
 Parameter        : PduLengthType Sdulength
 Return value     : None
 ***********************************************************************************************************************/
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3770]*/
void Dcm_Prv_TriggerTransmit(PduLengthType Sdulength)
{
    if (0x00u!=Sdulength)
    {
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
        if(FALSE == Dcm_Prv_isProtocolPreemptionInitiated())
#endif
        {
            if(FALSE == Dcm_Prv_isDcmWaitingForTxConfirmation())
            {
                Dcm_Dsl_Prv_SetRespPendingCounterValue(DCM_DEFAULT_VALUE);
                Dcm_Prv_SetInfinitePendingFlag(FALSE);
                Dcm_Dsl_Respone_st.SduDataPtr=&Dcm_Prv_GetActiveTxBuffer()[2];
                Dcm_Dsl_Respone_st.SduLength=Sdulength;
                Dcm_Prv_UpdateMetaDataPointer(Dcm_Prv_GetActiveRxPduId(),&Dcm_Dsl_Respone_st.MetaDataPtr);

                if(DSL_STATE_ROETYPE1_RECEIVED_E != Dcm_Dsl_Prv_GetDslState())
                {
                    Dcm_Dsl_Prv_SetDslState(DSL_STATE_WAITFOR_TXCONFIRMATION_E);
                }
                Dcm_Prv_SendResponse(&Dcm_Dsl_Respone_st);
            }

        }
    }
    else
    {
        Dcm_Prv_ReloadS3Timer();
#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF) )
        Dcm_Prv_SetNewSession();
#endif
        Dcm_Dsd_Prv_Confirmation(E_OK);
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
        Dcm_Prv_ProcessRequestInQueue();
#else
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
        Dcm_Dsl_Prv_SetPreemptionState(DSL_PREEMPTION_STATE_IDLE_E);
#endif

    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SendForcePendingResponse
 Syntax           : void Dcm_Prv_SendForcePendingResponse(void);
 Description      : This Function is used to send forcepending response
 Parameter        : None
 Return value     : None
 ***********************************************************************************************************************/
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3673]*/
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3674]*/

Std_ReturnType Dcm_Prv_SendForcePendingResponse(void)
{
    Std_ReturnType dataRetValue_u8 = E_NOT_OK;
    Dcm_DsdStatesType_ten DsdState_en = Dcm_Dsd_Prv_GetDsdState();
    uint8 datasourceofRequest =Dcm_Dsd_Prv_GetSourceofReq();

    /*Do not Proceed further if the call is triggered by ROE/RDPI ,or if the call is from application and none of the Dcm service is active */
     if((datasourceofRequest != DCM_ROE_SOURCE) && (datasourceofRequest!= DCM_RDPI_SOURCE) && (DSD_CALL_SERVICE_E  == DsdState_en))
     {
        if(!Dcm_Prv_isForcePendingResponse())
        {
            /*Check if time difference between two pending responses is greater than half of P2*Max*/
            if(TRUE==Dcm_CheckP2StarTimer())
            {
        #if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
                if(FALSE == Dcm_Prv_isProtocolPreemptionInitiated())
        #endif
                {
                    Dcm_Dsl_SetForcePendingFlag(TRUE);
                    Dcm_Dsl_Prv_SendPendingResponse();
                }
            }
            else
            {
                Dcm_Dsl_SetForcePendingFlag(FALSE);
                Dcm_Prv_SetResponsetype(DCM_NEG_RESPONSE);
#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)
                Dcm_Prv_ConfirmationRespPendForBootloader(DCM_RES_NEG_OK);
#endif
                (void)Dcm_ConfirmationRespPend(DCM_RES_NEG_OK);

            }
            /* Update return value */
            dataRetValue_u8 = E_OK;
        }
     }
    return(dataRetValue_u8);
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SendResponse
 Syntax           : Dcm_Prv_SendResponse(PduInfoType * PduInfoPcst)
 Description      : This Function is used to Send ALL types of responses to Lower layer by calling PduR_DcmTransmit
 Parameter        : const PduInfoType*
 Return value     : None
 ***********************************************************************************************************************/
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3750]*/
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3771]*/

void Dcm_Prv_SendResponse(const PduInfoType * PduInfoPcst)
{
    uint32 dataTimeOutMonitor_u32;
    if(TRUE==DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetActiveComMChannelIndex()))
    {
        if(E_NOT_OK == PduR_DcmTransmit(Dcm_Prv_GetActiveTxPduId(), PduInfoPcst))
        {
            Dcm_Dsl_ResponseTypeCheck();
        }
    }
    else
    {
        dataTimeOutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();
        DCM_TimerProcess(dataTimeOutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
        /* Update the data time out timer */
        Dcm_Prv_Set_DataTimeOut(dataTimeOutMonitor_u32);
        /*Check if P2 timer is expired?*/
        if(TRUE == DCM_TimerElapsed(dataTimeOutMonitor_u32))
        {
            Dcm_Dsl_ResponseTypeCheck();
            Dcm_Dsl_Prv_isRetryTransmission(NULL_PTR,FALSE);
        }
        else
        {
            Dcm_Dsl_Prv_isRetryTransmission(PduInfoPcst,TRUE);
        }
    }

}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

