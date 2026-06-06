
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
 * Defines/Macros
 **********************************************************************************************************************
 */

#define DCM_SID_LENGTH                                              0x01u
#define DCM_SUPPRESPOSITIVERESP_MASK                                0x80u


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
 */
static void Dcm_Dsd_Prv_CheckSupressPositiveResponse(void);
static void Dcm_PrepareDcmMsgContext(void);
static Std_ReturnType Dcm_CallService(void);
static void Dcm_SetOpstatus(Std_ReturnType serviceResult,uint8 *Opstatus_u8);

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_MsgContextType Dcm_MsgContext_st;
static const Dcm_DsdServiceTableConfigType_tst *Dcm_DsdSrvTableCfg_pst;
static Dcm_DsdStatesType_ten Dcm_DsdState_en;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static Dcm_NegativeResponseCodeType Dcm_NegativeResponseCode;
Dcm_SrvOpStatusType Dcm_SrvOpstatus_u8; /* Global Opstatus used by all services within Dcm*/
Dcm_OpStatusType    Dcm_ExtSrvOpStatus_u8; /* Dcm OpStatus, set by Dcm to be used by all services outside Dcm */
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
 */
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"


static boolean Dcm_Prv_DsdIsServiceRunning(void)
{
    boolean IsServiceRunning_b = FALSE;
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
    /* If ROE Type 2 event is being processed */
    IsServiceRunning_b = ((Dcm_DsdRoe2State_en != DSD_IDLE_E) &&
                         (Dcm_Roe2MesContext_st.idContext == Dcm_MsgContext_st.idContext));
#endif
    /* In case parallel processing is already ongoing
     * and a session change request is to be processed
     * then delay the processing of session change request until OBD service
     * has finished processing */
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if((Dcm_Dsd_Prv_GetIdContext() == DCM_SID_DIAGNOSTICSESSIONCONTROL) &&
        (Dcm_Prv_GetOBDState()!= DCM_OBD_IDLE ))
    {
        IsServiceRunning_b = TRUE;
    }
#endif
    return IsServiceRunning_b;
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3100] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3102] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3746] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3747] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3144] */
void Dcm_Dsd_Prv_StateMachine(void)
{
    Std_ReturnType result = DCM_E_REQUEST_NOT_ACCEPTED;

    switch(Dcm_DsdState_en)
    {
        case DSD_VERIFICATION_E:
            Dcm_PrepareDcmMsgContext();
            result = Dcm_Dsd_Prv_Verification(&Dcm_MsgContext_st,&Dcm_NegativeResponseCode);
            if(E_OK == result)
            {
                Dcm_DsdSrvTableCfg_pst= Dcm_Prv_GetServiceTable();
                Dcm_Dsd_Prv_CheckSupressPositiveResponse();
                Dcm_SrvOpstatus_u8 = DCM_INITIAL;
                Dcm_ExtSrvOpStatus_u8 = DCM_INITIAL;
                Dcm_DsdState_en = DSD_CALL_SERVICE_E;
            }
            else if(DCM_E_REQUEST_NOT_ACCEPTED == result)
            {
                Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest();
                Dcm_Prv_ReloadS3Timer();
                if (Dcm_Prv_GetActiveSessionIdx()==DCM_DEFAULT_SESSION_IDX)
                {
                    ComM_DCM_InactiveDiagnostic(Dcm_Prv_GetActiveComMChannelId());
                }
                break;
            }
            else
            {
                Dcm_Prv_SetResponsebyDSD(TRUE);
                break;
            }
            /* MR12 RULE 16.3 VIOLATION: break statement intentionally not added her for Execution to fall through */
        case DSD_CALL_SERVICE_E:
            result = Dcm_CallService();
            break;
        case DSD_CANCEL_E:
            Dcm_Dsd_Prv_CancelService();
            break;
        case DSD_WAITFORTXCONF_E:
            break;
        case DSD_SENDTXCONF_APPL_E:
            Dcm_Dsd_Prv_SendTx_Confirmation();
            Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest();
        default:
            //DSD_IDLE_E State
            break;
    }

    if((result != DCM_E_PENDING) && (result !=DCM_E_REQUEST_NOT_ACCEPTED) && (Dcm_Prv_DsdIsServiceRunning() == FALSE))
    {
        if(result != DCM_E_FORCE_RCRRP)
        {
            Dcm_DsdState_en = DSD_WAITFORTXCONF_E;
        }
        Dcm_Dsd_Prv_AssembleResponse(result,Dcm_NegativeResponseCode);
    }
}


/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4063] */
static Std_ReturnType Dcm_CallService(void)
{
    Std_ReturnType serviceResult=E_NOT_OK;

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_PagedBufferTimeout();
#endif

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    Dcm_DsldRoeTimeOut();
#endif


    /* Check whether an ROE Type 2 Event is not being processed by calling Dcm_Prv_DsdIsServiceRunning
     * If DSD State is changed (by above TimeOutfunction calls) then no need to call service  */
    if(Dcm_Prv_DsdIsServiceRunning() == FALSE)
    {
        if(Dcm_DsdSrvTableCfg_pst->serviceHandler_fp != NULL_PTR)
        {
            if(Dcm_DsdSrvTableCfg_pst->internalDspService_b == TRUE)
            {
                serviceResult = (*Dcm_DsdSrvTableCfg_pst->serviceHandler_fp)(Dcm_SrvOpstatus_u8,&Dcm_MsgContext_st,
                        &Dcm_NegativeResponseCode);

                Dcm_SetOpstatus(serviceResult,&Dcm_SrvOpstatus_u8);

            }
            else
            {
                serviceResult = (*Dcm_DsdSrvTableCfg_pst->serviceHandler_fp)(Dcm_ExtSrvOpStatus_u8,&Dcm_MsgContext_st,
                        &Dcm_NegativeResponseCode);

                Dcm_SetOpstatus(serviceResult,&Dcm_ExtSrvOpStatus_u8);
            }
        }
    }

    return serviceResult;
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3749] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3747] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4154] */
static void Dcm_SetOpstatus(Std_ReturnType serviceResult,uint8 *Opstatus_u8)
{
    if(Dcm_DsdSrvTableCfg_pst->internalDspService_b != FALSE)
    {
        if((serviceResult != DCM_E_PENDING) && (serviceResult != DCM_E_FORCE_RCRRP))
        {
            *Opstatus_u8 = DCM_INITIAL;
        }
    }
    else
    {
        if(serviceResult == DCM_E_PENDING)
        {
            *Opstatus_u8 = DCM_PENDING;
        }
        else if(serviceResult == DCM_E_FORCE_RCRRP)
        {
            *Opstatus_u8 = DCM_FORCE_RCRRP_OK;
        }
        else
        {
            *Opstatus_u8 = DCM_INITIAL;
        }
    }
}


/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3105] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3107] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4065] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4066] */
static void Dcm_PrepareDcmMsgContext(void)
{
    Dcm_MsgType reqData =  Dcm_Prv_GetActiveRxBuffer();
    Dcm_MsgType rspData = Dcm_Prv_GetActiveTxBuffer();

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();

    if(DSL_STATE_ROETYPE1_RECEIVED_E == Dcm_Dsl_Prv_GetDslState())
    {
        Dcm_MsgContext_st.resData = &ActiveRoeConnection->buffer_ptr[DCM_RESPONSEBUFFER_INDEX];
        Dcm_MsgContext_st.resMaxDataLen = ActiveRoeConnection->txBufferSize_u32-DCM_SID_LENGTH;
        Dcm_MsgContext_st.reqData = &ActiveRoeConnection->buffer_ptr[DCM_SUBFUNC_INDEX];
        Dcm_MsgContext_st.idContext = ActiveRoeConnection->buffer_ptr[DCM_SID_INDEX];

        /*Start ROE timer */
        DCM_TimerStart(dataTimerTimeout_u32,DCM_CFG_GET_TIMEOUT,Dcm_TimerStartTick_u32,Dcm_CounterValueTimerStatus_uchr);
    }
    else
#endif
    {
        Dcm_MsgContext_st.msgAddInfo.sourceofRequest = DCM_UDS_TESTER_SOURCE;
        Dcm_MsgContext_st.resMaxDataLen  =  Dcm_Prv_GetActiveTxBufferMaxLen()-DCM_SID_LENGTH;
        Dcm_MsgContext_st.reqData        =  &reqData[DCM_SUBFUNC_INDEX];
        Dcm_MsgContext_st.resData        =  &rspData[DCM_RESPONSEBUFFER_INDEX];
        Dcm_MsgContext_st.idContext      =  reqData[DCM_SID_INDEX];
    }

    Dcm_MsgContext_st.msgAddInfo.suppressPosResponse = FALSE;
    Dcm_MsgContext_st.msgAddInfo.reqType = Dcm_Prv_GetActiveReqType();
    Dcm_MsgContext_st.dcmRxPduId     =  Dcm_Prv_GetActiveRxPduId();
    Dcm_MsgContext_st.reqDataLen     =  Dcm_Dsl_Prv_GetActiveRequestDataLen()-DCM_SID_LENGTH;
    Dcm_MsgContext_st.resDataLen     =  DCM_DEFAULT_VALUE;
}

static void Dcm_Dsd_Prv_CheckSupressPositiveResponse(void)
{
    if(Dcm_DsdSrvTableCfg_pst->subFncAvail_b == TRUE)
    {
        if((Dcm_MsgContext_st.reqData[DCM_REQUESTWITHOUT_SID] & DCM_SUPPRESPOSITIVERESP_MASK) ==
                DCM_SUPPRESPOSITIVERESP_MASK)
        {
            Dcm_MsgContext_st.msgAddInfo.suppressPosResponse = TRUE;
            Dcm_MsgContext_st.reqData[DCM_REQUESTWITHOUT_SID] = (Dcm_MsgContext_st.reqData[DCM_REQUESTWITHOUT_SID] &
                    DCM_REMOVESUPPRESSRESPONSEBIT_MASK);
        }
    }
}


void Dcm_Dsd_Prv_CancelService(void)
{
   if(Dcm_DsdSrvTableCfg_pst->serviceHandler_fp != NULL_PTR)
   {
       (void)(*Dcm_DsdSrvTableCfg_pst->serviceHandler_fp)(DCM_CANCEL,&Dcm_MsgContext_st,
               &Dcm_NegativeResponseCode);
   }

   Dcm_SrvOpstatus_u8 = DCM_INITIAL;
   Dcm_ExtSrvOpStatus_u8 = DCM_INITIAL;
}

void Dcm_Dsd_Prv_SetDsdState(Dcm_DsdStatesType_ten dsdState_en)
{
    Dcm_DsdState_en = dsdState_en;
}

Dcm_DsdStatesType_ten Dcm_Dsd_Prv_GetDsdState(void)
{
    return Dcm_DsdState_en;
}

Dcm_MsgLenType Dcm_Dsd_Prv_GetRespLength(void)
{
    return Dcm_MsgContext_st.resDataLen;
}

Dcm_MsgLenType Dcm_Dsd_Prv_GetRespMaxLength(void)
{
    return Dcm_MsgContext_st.resMaxDataLen;
}

boolean Dcm_Dsd_Prv_GetsuppressPosResponse(void)
{
    return Dcm_MsgContext_st.msgAddInfo.suppressPosResponse;
}

void Dcm_Dsd_Prv_ResetsuppressPosResponse(void)
{
    Dcm_MsgContext_st.msgAddInfo.suppressPosResponse = FALSE;
}

uint8 Dcm_Dsd_Prv_GetReqType(void)
{
    return Dcm_MsgContext_st.msgAddInfo.reqType;
}

void Dcm_Dsd_Prv_SetSourceofReq(uint8 RequestSource)
{
    Dcm_MsgContext_st.msgAddInfo.sourceofRequest = RequestSource;
}

uint8 Dcm_Dsd_Prv_GetSourceofReq(void)
{
    return Dcm_MsgContext_st.msgAddInfo.sourceofRequest;
}

Dcm_IdContextType Dcm_Dsd_Prv_GetIdContext(void)
{
    return Dcm_MsgContext_st.idContext;

}

PduIdType Dcm_Dsd_Prv_GetdcmRxPduId(void)
{
    return Dcm_MsgContext_st.dcmRxPduId;
}

Dcm_MsgContextType Dcm_Dsd_Prv_GetUdsMsgContext(void)
{
    return Dcm_MsgContext_st;
}

void Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest(void)
{
    if(Dcm_Dsl_Prv_GetDslState()!= DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E)
    {
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
    }
    Dcm_Dsd_Prv_SetDsdState(DSD_IDLE_E);
    Dcm_Prv_SetResponsebyDSD(FALSE);
    Dcm_Prv_SetResponsetype(DCM_POS_RESPONSE);
    Dcm_Prv_SetInfinitePendingFlag(FALSE);
    Dcm_Dsl_SetForcePendingFlag(FALSE);

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    if(Dcm_Prv_Get_PagedBufferTxOn())
    {
        Dcm_Prv_Set_PagedBufferTxOn(FALSE);
        Dcm_adrUpdatePage_pfct = NULL_PTR;
    }
#endif
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
