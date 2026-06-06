#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"
#define DEFAULT_VALUE                   0x00u
#define DEFAULT_MASKVALUE               0x00000001uL /* Mask value which will be varied depending on active session/security */

#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* Pointer to hold the active Extended protocol conf structure */
const Dcm_ProtocolExtendedInfo_type * Dcm_DsldRoe_pcst;
static PduIdType s_RoeProtocolPduId;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
StatusType Dcm_CounterValueTimerStatus_uchr; /* global variable to get the return value of GetCounterValue for Timer related funtions*/
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
StatusType Dcm_RoeType2TimerStatus_uchr; /* global variable to get the return value of GetCounterValue for Timer related funtions*/
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
uint32 dataTimerTimeout_u32;
uint32 Dcm_TimerStartTick_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
static Dcm_NegativeResponseCodeType s_dataNrc_u8;
#endif
uint8 DcmRoeQueueIndex_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
Dcm_DsdStatesType_ten Dcm_DsdRoe2State_en; /* ROE2 DSD state */
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
Dcm_MsgContextType Dcm_Roe2MesContext_st; /* ROE2 message context table */
Dcm_DsdResponseType_ten Dcm_Roe2ResponseType_en; /* ROE2 response type */
PduInfoType Dcm_DsldRoe2PduInfo_st; /* ROE2 PDU info structure*/
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
uint8 Dcm_DsldSrvIndex_u8; /* ROE2 Index to service in table*/
Std_ReturnType Dcm_Roe2TxResult_u8; /* ROE2 Tx confirmation result */
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
uint32 datRoeType2Timeout_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

void Dcm_Prv_SetRoeProtocolPduid(PduIdType RxpduId)
{
    s_RoeProtocolPduId = RxpduId;
}

PduIdType Dcm_Prv_GetRoeProtocolPduid(void)
{
    return s_RoeProtocolPduId;
}

/**
 **************************************************************************************************
 * Dcm_UpdateROEQueue:
 * This function will be invoked incase any of the event needs to be queued and postpone the processing
 * since DCM is busy currently.
 *
 * \parameters           RoeEventId
 *                       RxPdu
 * \return value         void
 *
 **************************************************************************************************
 */
static Dcm_StatusType Dcm_UpdateROEQueue( uint8 RoeEventId, PduIdType RxPdu)
{
    uint8 index_u8;
    Dcm_StatusType dataReturnValue_u8;
    dataReturnValue_u8=DCM_E_ROE_NOT_ACCEPTED;

    for(index_u8=0;index_u8<DCM_MAX_SETUPROEEVENTS;index_u8++)
    {
        if(Dcm_DcmDspEventQueue[index_u8].EventId_u8 == RoeEventId)
        {
            Dcm_DcmDspEventQueue[index_u8].Is_Queued = TRUE;
            Dcm_DcmDspEventQueue[index_u8].RxPduId_u8 = RxPdu;
            dataReturnValue_u8 = DCM_E_OK;
            break;
        }
    }
    return dataReturnValue_u8;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ROEResetOnConfirmation
 Syntax           : Dcm_Prv_ROEResetOnConfirmation(void)
 Description      : Reset on ROE message confiramtion
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_ROEResetOnConfirmation(void)
{
    /* BSWEXT-505 */ /* [$DD_BSWCODE 40590] */
    if(DcmRoeQueueIndex_u8<DCM_MAX_SETUPROEEVENTS)
    {
        Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].Is_Processed = FALSE;
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_DsdVerifySubFncID
 Syntax           : Dcm_Prv_DsdVerifySubFncID(idxSubservice_u8,ErrorCode)
 Description      : Check whether at least one sub-function byte exists and extract
                    requested sub-function index
 Parameter        : uint8,Dcm_NegativeResponseCodeType
 Return value     : Std_ReturnType
 ***********************************************************************************************************************/
LOCAL_INLINE Std_ReturnType Dcm_Prv_DsdVerifyROESubFncID(
        const Dcm_MsgContextType * Msgcontext_s,
        uint8* idxSubservice_u8,
        const Dcm_DsdServiceTableConfigType_tst* service_pcs,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
    const Dcm_DsdSubServiceConfigType_tst* adrSubservice_pcst;
    Std_ReturnType VerificationResult_u8 = E_NOT_OK;
    /* Variable to store the sub-function byte from the request */
    uint8 dataSubfunction_u8 = Msgcontext_s->reqData[0];
    *idxSubservice_u8 = 0u;
    *ErrorCode = DEFAULT_VALUE;  /* Reset the error code to 0x00 */

    /* Check if there is at least one byte (sub function byte exists) */
    if (Msgcontext_s->reqDataLen > DEFAULT_VALUE)
    {
        /* Get the sub service configuration structure */
        adrSubservice_pcst = service_pcs->subSrvCfg_pcast;
        if(Dcm_Dsd_Prv_GetIdContext() ==0x86)
        {
            dataSubfunction_u8 =  (dataSubfunction_u8 & ((uint8)(~(0x40u))));
        }

        /* Loop through to check , whether requested SubFunction is configured */
        while(*idxSubservice_u8 < service_pcs->numOfSubFnc_u8)
        {
            if (dataSubfunction_u8 == adrSubservice_pcst[*idxSubservice_u8].subServiceId_u8)
            {
                break;
            }
            (*idxSubservice_u8)++;
        }
        /* If sub service is configured*/
        if (*idxSubservice_u8 < service_pcs->numOfSubFnc_u8)
        {
            VerificationResult_u8 = E_OK;
        }
        /* If the sub service is not supported */
        else
        {
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
    }
    else
    {
        /* If service is outside DSP */
        if (service_pcs->internalDspService_b == FALSE)
        {
            /* Call the DcmAppl API to get the NRC to be returned in case minimum length check fails for project/vendor specific services  */
            DcmAppl_DcmGetNRCForMinLengthCheck(Dcm_Prv_GetActiveProtocolType(), service_pcs->sid_u8,ErrorCode);
        }
        if (*ErrorCode == DEFAULT_VALUE)
        {
            /* If no ErrorCode is set , then NRC to 0x13 as sub function byte is missing in the service request */
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
    }
    return VerificationResult_u8;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_DsdCheckSubFunction
 Syntax           : Dcm_Prv_DsdCheckSubFunction()
 Description      : Function to do subservice specific checks in DSD
 Parameter        : void
 Return value     : Std_ReturnType
 ***********************************************************************************************************************/
LOCAL_INLINE Std_ReturnType Dcm_CheckRoeSubFunction(const Dcm_MsgContextType * Msgcontext_s,
        const Dcm_DsdServiceTableConfigType_tst * service_pcs,
        uint8 * ErrorCode_u8 )
{
    uint8 idxSubservice_u8; /* Index to loop through the sub-service table */
    Std_ReturnType VerificationResult_u8 = Dcm_Prv_DsdVerifyROESubFncID(Msgcontext_s,&idxSubservice_u8,service_pcs,ErrorCode_u8);
    /* local pointer to sub-service configuration structure*/
    const Dcm_DsdSubServiceConfigType_tst* adrSubservice_pcst = service_pcs->subSrvCfg_pcast;
    *ErrorCode_u8 = 0u;


    if(VerificationResult_u8 == E_OK)
    {
        VerificationResult_u8 = Dcm_Prv_CheckAccessRights(DCM_CHECK_SUBSERVICE,adrSubservice_pcst[idxSubservice_u8].allowedRole_u32,
                Msgcontext_s,ErrorCode_u8);

        if(E_OK == VerificationResult_u8)
        {
            VerificationResult_u8 = E_NOT_OK; /* Set it to E_NOT_OK again */

            /* Check requested sub service is allowed in this session */
            if(E_OK == Dcm_Dsl_Prv_VerifySessionAccess(adrSubservice_pcst[idxSubservice_u8].allowedSession_u32))
            {
                /* Check if the requested sub-service is allowed in current security */
                if(E_OK == Dcm_Dsl_Prv_VerifySecurityAccess(adrSubservice_pcst[idxSubservice_u8].allowedSecurity_u32,ErrorCode_u8))
                {
                    /* DcmAppl_UserSubServiceModeRuleService will be invoked in case no mode rule is configured */
                    VerificationResult_u8 = (*adrSubservice_pcst[idxSubservice_u8].subServiceUserModeRule_pfct)(ErrorCode_u8,
                            service_pcs->sid_u8, adrSubservice_pcst[idxSubservice_u8].subServiceId_u8);
                    /* If the function returns any other value other than E_OK or a set NRC value */
                    *ErrorCode_u8=((VerificationResult_u8 != E_OK) && (*ErrorCode_u8 == 0x00))?DCM_E_CONDITIONSNOTCORRECT:*ErrorCode_u8;
#if(DCM_CFG_DSD_MODERULESUBFNC_ENABLED == DCM_CFG_ON)
                    /* Check if the mode rule is configured for the sub function */
                    if((adrSubservice_pcst[idxSubservice_u8].subServiceModeRule_pfct != NULL_PTR) && (VerificationResult_u8==E_OK))
                    {
                        /* Call the mode rule API configured */
                        VerificationResult_u8 = ((*adrSubservice_pcst[idxSubservice_u8].subServiceModeRule_pfct)(ErrorCode_u8) == TRUE)?E_OK:E_NOT_OK;
                    }
#endif
                }
                else
                {
                    *ErrorCode_u8 = DCM_E_SECURITYACCESSDENIED;
                }
            }
            /* If sub service is not allowed in current session */
            else
            {
                *ErrorCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
            }
        }
    }
    return VerificationResult_u8;
}



/**
 **************************************************************************************************
 * Dcm_GetRoeProtValidity : This function is used only to Check if the protocol corresponding to the
 *                          RxPduId passed supports ROE
 *
 * \param           DcmRxPduId
 *                  idxProtocol_u8
 *
 *
 *
 * \retval         Dcm_StatusType
 *
 * \seealso
 *
 **************************************************************************************************
 **/
static Dcm_StatusType Dcm_GetRoeProtValidity(const Dcm_DslProtocolRowConfigType_tst* ActiveRoeProtocolRow,
        const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection
)
{
    Dcm_StatusType dataReturnValue_u8;

    /* Check if the protocol corresponding to the RxPduId passed supports ROE */
    dataReturnValue_u8 = ((ActiveRoeProtocolRow != NULL_PTR)&&(ActiveRoeConnection != NULL_PTR) )? E_OK : DCM_E_ROE_NOT_ACCEPTED;

    return dataReturnValue_u8;
}


#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#if(DCM_CFG_ROETYPE2_ENABLED == DCM_CFG_ON)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/***********************************************************************************************************************
 Function name    : Dcm_Prv_TransmitRoeType2Response
 Syntax           : Dcm_Prv_TransmitRoeType2Response(void)
 Description      : This Function is used to transmit RoeType2 Response to the lower layer
 Parameter        : None
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_TransmitRoeType2Response(void)
{
    boolean TransmitSuccess_b = TRUE;
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();

    Dcm_DsdRoe2State_en = DSD_WAITFORTXCONF_E;

    if(Dcm_Roe2ResponseType_en == DCM_POS_RESPONSE)
    {
        /* Check if Response is supressed*/
        if(FALSE == Dcm_Roe2MesContext_st.msgAddInfo.suppressPosResponse)
        {
            ActiveRoeConnection->buffer_ptr[2] = Dcm_Roe2MesContext_st.idContext|DCM_SERVICEID_ADDEND;
            Dcm_DsldRoe2PduInfo_st.SduLength   = (PduLengthType) Dcm_Roe2MesContext_st.resDataLen + 1u ;
            Dcm_DsldRoe2PduInfo_st.SduDataPtr  = &ActiveRoeConnection->buffer_ptr[2];
        }
        else
        {
            Dcm_DsldRoe2PduInfo_st.SduLength = 0x00u;
        }
    }
    else
    {
        /* Check if Negative Response is supressed*/
        if((Dcm_Roe2MesContext_st.dcmRxPduId >= DCM_CFG_INDEX_FUNC_RX_PDUID) && \
                (DCM_CFG_SUPPRESS_NRC(ActiveRoeConnection->buffer_ptr[2])))
        {
            Dcm_DsldRoe2PduInfo_st.SduLength = 0x00;
        }
        else
        {
            Dcm_DsldRoe2PduInfo_st.SduLength = (PduLengthType) ( Dcm_Roe2MesContext_st.resDataLen + 3u ) ;
            Dcm_DsldRoe2PduInfo_st.SduDataPtr = &ActiveRoeConnection->buffer_ptr[0];
        }
    }



    /* Check if Response is Suppressed*/
    if(0x00u == Dcm_DsldRoe2PduInfo_st.SduLength)
    {
        /* No need to trigger Tx in PduR. Give confirmation */
        Dcm_Roe2TxResult_u8 = E_OK;
        Dcm_DsdRoe2State_en = DSD_SENDTXCONF_APPL_E;
    }
    else
    {
        if(TRUE == DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetMainConnection(Dcm_Roe2MesContext_st.dcmRxPduId)->channel_idx_u8))
        {
            if(E_NOT_OK == PduR_DcmTransmit(ActiveRoeConnection->roeTxPduId,&Dcm_DsldRoe2PduInfo_st))
            {
                TransmitSuccess_b  = FALSE;
                Dcm_Prv_Det(DCM_PROCESSINGDONE_ID , DCM_E_RET_E_NOT_OK );
            }
        }
        else
        {
            TransmitSuccess_b  = FALSE;
            Dcm_Prv_Det(DCM_PROCESSINGDONE_ID , DCM_E_FULLCOMM_DISABLED );
        }

        if(FALSE == TransmitSuccess_b)
        {
            /* Tx failed in PduR. Give confirmation */
            Dcm_Roe2TxResult_u8 = E_NOT_OK;
            Dcm_DsdRoe2State_en = DSD_SENDTXCONF_APPL_E;
        }
    }
}

static void Dcm_SetROENegResponse(Dcm_NegativeResponseCodeType ErrorCode)
{
    Dcm_MsgType responseBuf_pu8;
    if(Dcm_Roe2ResponseType_en == DCM_POS_RESPONSE)
    {
        /* Set the negative response type  */
        Dcm_Roe2ResponseType_en = DCM_NEG_RESPONSE;
        responseBuf_pu8 = Dcm_Prv_GetActiveRoeConnection()->buffer_ptr;

        responseBuf_pu8[0] = DCM_NEGRESPONSE_INDICATOR;
        responseBuf_pu8[1] = Dcm_Dsd_Prv_GetIdContext();
        responseBuf_pu8[2] = ErrorCode;
    }
}

/**
 **************************************************************************************************
 * Dcm_DsldRoeInitiateResponseTransmission :
 * The  function is a generic library introduced to invoke the triggering of positive, negative
 * response or Response Pending operation (NRC0x78) or PENDING return
 * \param           retVal_u8    :   Type of operation to be carried out
 *
 * \retval          None
 *
 **************************************************************************************************
 */
static void Dcm_DsldRoeInitiateResponseTransmission(Std_ReturnType retVal_u8)
{
    if(retVal_u8 == E_OK)
    {
        /*Trigger transmission of positive response*/
        Dcm_Prv_TransmitRoeType2Response();
    }
    else if (retVal_u8 == DCM_E_PENDING)
    {
        /*Do nothing here, just set opstatus to pendin operation*/
    }
    else if (retVal_u8 == DCM_E_FORCE_RCRRP)
    {
        (void)Dcm_Prv_SendForcePendingResponse();
    }
    else
    {
        /*If no NRC is set by the service send NRC22 as default service, ideally this should nevery occur*/
        if(s_dataNrc_u8 ==0x00)
        {
            s_dataNrc_u8 = DCM_E_CONDITIONSNOTCORRECT;
        }
        /*Trigger transmission of negative response*/
        Dcm_SetROENegResponse(s_dataNrc_u8);
        Dcm_Prv_TransmitRoeType2Response();
    }
}
/**
 *********************************************************************************************************************
 * Dcm_ChkIfDidServiceIsActive :  This API is called from ROE Type2 state machine/DSD to check if  DID service is active
 * for Roe Event and in DslDsd for tester request. Also this API checks if the tester request is processing DID
 * service and ROE events also wants to access the DID service. There is no possibility to run the DID services in
 * parallel due to re-enterancy/data consistency issues
 *
 * \param           TesterReqSid_u8: Service ID of the active tester request
 *                  RoeType2Sid_u8 : Service ID of the Roe Type2 event triggered
 *
 * \retval          TRUE : Parallel processing of tester request and ROE event is possible
 *                  FALSE: Parallel processing of tester request and ROE event is not possible
 * \seealso
 * \usedresources
 *********************************************************************************************************************
 */
boolean Dcm_ChkIfDidServiceIsActive(uint8 TesterReqSid_u8,
        uint8 RoeType2Sid_u8)
{
    boolean retval_b;
    const Dcm_DsdServiceTableConfigType_tst* ActiveServiceTable = Dcm_Prv_GetServiceTable();
    const Dcm_DsdServiceTableConfigType_tst * adrSrvTable_pcst;
    adrSrvTable_pcst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[Dcm_Prv_GetActiveRoeConnection()->srvTableId_u8].srvTable_pcast;
    /*initialize the return value to true*/
    retval_b = TRUE;

    /* If the Service requested by tester and the service triggered by ROE are both located in DCM */
    if((ActiveServiceTable->internalDspService_b)&&
            (adrSrvTable_pcst->internalDspService_b))
    {
        /* If the tester requested service is same as the ROE requested service */
        if(TesterReqSid_u8 == RoeType2Sid_u8)
        {
            /*Initialize the return val to false*/
            retval_b = FALSE;
        }
        /* If the tester requested service and ROE requested service are both DID services */
        else if(
                ((TesterReqSid_u8 == DCM_DSP_SID_READDATABYIDENTIFIER) ||
                        (TesterReqSid_u8 == DCM_DSP_SID_WRITEDATABYIDENTIFIER)||
                        (TesterReqSid_u8 == DCM_DSP_SID_DYNAMICALLYDEFINEDATAIDENTIFIER)||
                        (TesterReqSid_u8 == DCM_DSP_SID_INPUTOUTPUTCONTROLBYIDENTIFIER))
                        &&
                        ((RoeType2Sid_u8 == DCM_DSP_SID_READDATABYIDENTIFIER) ||
                                (RoeType2Sid_u8 == DCM_DSP_SID_WRITEDATABYIDENTIFIER)||
                                (RoeType2Sid_u8 == DCM_DSP_SID_DYNAMICALLYDEFINEDATAIDENTIFIER)||
                                (RoeType2Sid_u8 == DCM_DSP_SID_INPUTOUTPUTCONTROLBYIDENTIFIER))
        )
        {
            /*Initialize the return value to false*/
            retval_b = FALSE;
        }
        else
        {
            /* nothing to set */
        }
    }
    return(retval_b);
}

/**
 **************************************************************************************************
 * Dcm_Prv_DsldRoe2StateMachine_DSD_VERIFY_DIAGNOSTIC_DATA :  This function called from Dcm_DsldRoe2StateMachine() to
 * process ROE requested service to verify diagnostic data
 *
 * \param           adrSrvTable_pcst
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
static void Dcm_Prv_DsldRoe2StateMachine_DSD_VERIFY_DIAGNOSTIC_DATA(
        const Dcm_DsdServiceTableConfigType_tst * adrSrvTable_pcst,
        const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection)
{
    uint8 dataNrc_u8; /* Variable to store negative response code */
    Std_ReturnType dataRetVal_u8;

    /* Initializing the negative response code */
    dataNrc_u8=0x00;

    /* Fill the addressing mode info (physical or functional) */
    if(Dcm_Roe2MesContext_st.dcmRxPduId >= DCM_CFG_INDEX_FUNC_RX_PDUID)
    {
        Dcm_Roe2MesContext_st.msgAddInfo.reqType = DCM_PRV_FUNCTIONAL_REQUEST;
    }
    else
    {
        Dcm_Roe2MesContext_st.msgAddInfo.reqType = DCM_PRV_PHYSICAL_REQUEST;
    }

    /* Fill the Rx buffer pointer excluding Sid */
    Dcm_Roe2MesContext_st.reqData = &(ActiveRoeConnection->buffer_ptr[1]);

    /* Fill the Tx buffer pointer */
    Dcm_Roe2MesContext_st.resData = &(ActiveRoeConnection->buffer_ptr[3]);

    /* Fill the maximum possible response length */
    Dcm_Roe2MesContext_st.resMaxDataLen = ActiveRoeConnection->txBufferSize_u32 - 1u;

    /* Check whether the suppressed positive bit is enabled for this request*/

    if((adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].subFncAvail_b != FALSE)&&
            ((ActiveRoeConnection->buffer_ptr[1]&0x80u) == 0x80u))
    {
        /*suppressed positive bit is always set to true*/
        Dcm_Roe2MesContext_st.msgAddInfo.suppressPosResponse = TRUE;

        /* Remove the suppress positive bit from the sub-function byte*/
        (*Dcm_Roe2MesContext_st.reqData) = ((*Dcm_Roe2MesContext_st.reqData) & 0x7Fu);
    }
    /* If sub-function is supported and sub-services are configured in DSD */

    if((adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].subFncAvail_b!= FALSE) &&
            (adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].numOfSubFnc_u8!=0))
    {
        /* Call the API to do sub-function related checks */
        dataRetVal_u8 = Dcm_CheckRoeSubFunction(&Dcm_Roe2MesContext_st,&adrSrvTable_pcst[Dcm_DsldSrvIndex_u8],&dataNrc_u8);
        if(dataRetVal_u8 != E_OK)
        {
            dataNrc_u8 = (dataNrc_u8==0u)?DCM_E_CONDITIONSNOTCORRECT:dataNrc_u8;
        }
        else
        {
            dataNrc_u8 = 0u;
        }
    }
    if(dataNrc_u8 == 0x00)
    {
        /* Change state to call the service */
        Dcm_DsdRoe2State_en = DSD_CALL_SERVICE_E;

        /* Start ROE2 timer */

        DCM_TimerStart(datRoeType2Timeout_u32,DCM_CFG_GET_TIMEOUT,
                Dcm_Roe2StartTick_u32,Dcm_RoeType2TimerStatus_uchr);

        /* Call the service first time */
        dataRetVal_u8=(*adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].serviceHandler_fp)
                        (DCM_INITIAL,&Dcm_Roe2MesContext_st,&dataNrc_u8);

        Dcm_DsldRoeInitiateResponseTransmission(dataRetVal_u8);
    }
    else
    {
        Dcm_SetROENegResponse(dataNrc_u8);
        Dcm_Prv_TransmitRoeType2Response();
    }
}

/**
 **************************************************************************************************
 * Dcm_Prv_DsldRoe2StateMachine_DSD_CALL_SERVICE :  This function called from Dcm_DsldRoe2StateMachine() to
 * process and call ROE requested service
 *
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
static void Dcm_Prv_DsldRoe2StateMachine_DSD_CALL_SERVICE(
        const Dcm_DsdServiceTableConfigType_tst * adrSrvTable_pcst)
{
    uint8 dataNrc_u8; /* Variable to store negative response code */
    Std_ReturnType dataRetVal_u8;

    /* Check whether the ROE timeout has occurred  */
    if(DCM_TimerElapsed(datRoeType2Timeout_u32)== FALSE)
    {
        /* Start ROE2 timer */
        DCM_TimerProcess(datRoeType2Timeout_u32,Dcm_Roe2StartTick_u32,
                Dcm_RoeType2TimerStatus_uchr);

        /* Call the service if it located inside the DCM */
        /*Is Service existing in DSP*/
        if(adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].internalDspService_b != FALSE)
        {
            dataRetVal_u8=(*adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].serviceHandler_fp)
                            (DCM_INITIAL,&Dcm_Roe2MesContext_st,&dataNrc_u8);

            Dcm_DsldRoeInitiateResponseTransmission(dataRetVal_u8);
        }
    }
    else
    {
        /* Give the confirmation to ROE application */
        DcmAppl_DcmConfirmation(Dcm_Roe2MesContext_st.idContext,Dcm_Prv_GetActiveReqType(),
                Dcm_Prv_GetConnectionIndex(Dcm_Roe2MesContext_st.dcmRxPduId),DCM_RES_POS_NOT_OK,
                Dcm_Prv_GetActiveProtocolType(),
                Dcm_Dsld_RoeRxToTestSrcMappingTable[Dcm_Roe2MesContext_st.dcmRxPduId].testsrcaddr_u16);

        if(adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].serviceInit_fp != NULL_PTR)
        {
            /* Call initialization of the active service */
            (*adrSrvTable_pcst[Dcm_DsldSrvIndex_u8].serviceInit_fp)();
        }
        /* reset the DCM states */
        Dcm_DsdRoe2State_en = DSD_IDLE_E;
    }
}

/**
 **************************************************************************************************
 * Dcm_Prv_DsldRoe2StateMachine_DSD_TX_CONFIRMATION :  This function called from Dcm_DsldRoe2StateMachine() to
 * process ROE requested service TX CONFIRMATION
 *
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
static void Dcm_Prv_DsldRoe2StateMachine_DSD_TX_CONFIRMATION(void)
{
    Dcm_ConfirmationStatusType stConfirm_u8;

    /* Is previous response sent successfully by PduR? */
    if(Dcm_Roe2TxResult_u8 == E_OK)
    {
        if(Dcm_Roe2ResponseType_en == DCM_POS_RESPONSE)
        {
            /* POS response sent successfully */
            stConfirm_u8 = DCM_RES_POS_OK;
        }
        else
        {
            /* NEG response sent successfully */
            stConfirm_u8 = DCM_RES_NEG_OK;
        }
    }
    else
    {
        if(Dcm_Roe2ResponseType_en == DCM_POS_RESPONSE )
        {
            /* Unable to send positive response */
            stConfirm_u8 = DCM_RES_POS_NOT_OK;
        }
        else
        {
            /* Unable to send negative response response */
            stConfirm_u8 = DCM_RES_NEG_NOT_OK;
        }
    }

    /* BSWEXT-505 */ /* [$DD_BSWCODE 40591] */
    if(DcmRoeQueueIndex_u8<DCM_MAX_SETUPROEEVENTS)
    {
        Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].Is_Processed = FALSE;
    }

    /* Give the confirmation to application */
    DcmAppl_DcmConfirmation(Dcm_Roe2MesContext_st.idContext,Dcm_Prv_GetActiveReqType(),
            Dcm_Prv_GetConnectionIndex(Dcm_Roe2MesContext_st.dcmRxPduId),stConfirm_u8,
            Dcm_Prv_GetActiveProtocolType(),
            Dcm_Dsld_RoeRxToTestSrcMappingTable[Dcm_Roe2MesContext_st.dcmRxPduId].testsrcaddr_u16);

    /* DSD state made to Idle */
    Dcm_DsdRoe2State_en = DSD_IDLE_E;
    /* Start ROE2 timer */
    DCM_TimerStart(datRoeType2Timeout_u32,
            DCM_CFG_ROETYPE2_INTERMSGTIME,Dcm_Roe2StartTick_u32,Dcm_RoeType2TimerStatus_uchr);

}

/**
 **************************************************************************************************
 * Dcm_DsldRoe2StateMachine :  This function called from Dcm_MainFunction() to process ROE requested
 *                              service in parallel to normal tester request
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

void Dcm_DsldRoe2StateMachine(void)
{
    uint8 nrService_u8;
    uint8 idxIndex_u8;
    uint8 dataNrc_u8; /* Variable to store negative response code */
    Dcm_DsdStatesType_ten DsdState_en;
    const Dcm_DsdServiceTableConfigType_tst * adrSrvTable_pcst;
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();
    Dcm_DslStatesType_ten getDslstate;

    switch(Dcm_DsdRoe2State_en)
    {
        case DSD_IDLE_E:
            break;

        case DSD_VERIFICATION_E:
            /* Initializing the negative response code */
            dataNrc_u8=0x00;

            /* Fill the default response type */
            Dcm_Roe2ResponseType_en = DCM_POS_RESPONSE;

            /* Response length (filled by the service) */
            Dcm_Roe2MesContext_st.resDataLen = 0x0u;

            /* Get the number of services present in the ROE service table */
            nrService_u8 = Dcm_Cfg_Dsd_pcst->sidTables_pcast[ActiveRoeConnection->srvTableId_u8].numOfServices_u8;;

            /* Get the pointer to service table*/
            adrSrvTable_pcst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[ActiveRoeConnection->srvTableId_u8].srvTable_pcast;

            /* Fill the Sid */
            Dcm_Roe2MesContext_st.idContext = ActiveRoeConnection->buffer_ptr[0];

            /* This is ROE requested service */
            Dcm_Roe2MesContext_st.msgAddInfo.sourceofRequest = DCM_ROE_SOURCE;
            /* Search the requested service in ROE service table */
            for(idxIndex_u8 = 0x00; idxIndex_u8 != nrService_u8; idxIndex_u8++)
            {
                if(Dcm_Roe2MesContext_st.idContext == adrSrvTable_pcst[idxIndex_u8].sid_u8)
                {
                    /* SID Found, break the loop */
                    break;
                }
            }

            /* Is SID exists in table? */
            if(idxIndex_u8 != nrService_u8)
            {
                DsdState_en = Dcm_Dsd_Prv_GetDsdState();
                getDslstate= Dcm_Dsl_Prv_GetDslState();
                /* Multicore: No lock needed here as Dsl state is an atomic operation */
                /* DSL state machine handling ensures that there is no data consistency issues*/
                /* If there is a parallel update to DSL state there is no functionality problems observed*/

                boolean ChkDidServiceActive_b = Dcm_ChkIfDidServiceIsActive(Dcm_Dsd_Prv_GetIdContext(),Dcm_Roe2MesContext_st.idContext);
                if(((getDslstate == DSL_STATE_IDLE_E) && (DsdState_en == DSD_IDLE_E))\
                        || (ChkDidServiceActive_b != FALSE))
                {
                    Dcm_Prv_DsldRoe2StateMachine_DSD_VERIFY_DIAGNOSTIC_DATA(adrSrvTable_pcst,ActiveRoeConnection);
                }
                else
                {
                    /* SID not found, send the negative response */
                    Dcm_SetROENegResponse(DCM_E_SERVICENOTSUPPORTED);
                    Dcm_Prv_TransmitRoeType2Response();
                }
            }
            break;

        case DSD_CALL_SERVICE_E:

            /* Get the pointer to service table*/
            adrSrvTable_pcst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[ActiveRoeConnection->srvTableId_u8].srvTable_pcast;
            Dcm_Prv_DsldRoe2StateMachine_DSD_CALL_SERVICE(adrSrvTable_pcst);
            break;

        case DSD_WAITFORTXCONF_E:
            /* DCM is sending the response */
            break;

        case DSD_SENDTXCONF_APPL_E:

            Dcm_Prv_DsldRoe2StateMachine_DSD_TX_CONFIRMATION();
            break;

        default:
            /* Intentionally Empty */
            break;
    }
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 **************************************************************************************************
 * Dcm_ROE_StartProtocol : Function called by the ROE service whene the application function is
 *                         request is received.
 *
 * \param
 *
 * \retval         DCM_E_OK: ResponseOnOneEvent request is accepted by DCM ,
 *                 DCM_E_ROE_NOT_ACCEPTED: ResponseOnOneEvent request is not accepted by DCM
 * \seealso
 *
 **************************************************************************************************
 **/
static Dcm_StatusType Dcm_Prv_ROE_StartProtocol(uint8 srvTableId_u8,PduIdType dcmRxPduId_u8)
{
    const Dcm_DslProtocolRowConfigType_tst* CurrentProtocol = Dcm_Prv_GetProtocolRow(dcmRxPduId_u8);
    Dcm_StatusType dataReturnValue_u8;
    /* Initialize the value to ROE not accepted */
    dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;
    /* Start the application function */
    if (Dcm_StartProtocol(CurrentProtocol->protocolType,Dcm_Prv_GetActiveTesterSrcAddress(),Dcm_Prv_GetActiveConnectionId()) == E_OK)
    {
        /* Call the Initialisation function of service */
        Dcm_Dsd_Prv_ServiceInit(srvTableId_u8);
        dataReturnValue_u8 = DCM_E_OK;
    }
    else
    {
        /* reject the request because unable to start protocol */
        /* Report development error "DCM_E_PROTOCOL_NOT_STARTED " to DET module if the DET module is enabled */
        Dcm_Prv_Det(DCM_ROE_ID, DCM_E_PROTOCOL_NOT_STARTED);

        /*Initialize the Comm Active flag to the value false*/
        Dcm_Prv_SetProtocolStatus(FALSE);
        dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;
    }
    return (dataReturnValue_u8);
}
/**
 **************************************************************************************************
 * Dcm_ROE_TYPE1 : Function called by the ROE service whenever the ROE_TYPE1 request is received.
 *
 * \param          Dcm_MsgType MsgPtr :    Pointer to buffer which contains the request
 *                 Dcm_MsgLenType MsgLen : Length of the request
 *
 * \retval         DCM_E_OK: ResponseOnOneEvent request is accepted by DCM ,
 *                 DCM_E_ROE_NOT_ACCEPTED: ResponseOnOneEvent request is not accepted by DCM
 * \seealso
 *
 **************************************************************************************************
 **/


static Dcm_StatusType Dcm_Prv_ROE_TYPE1(uint8 srvTableId_u8, Dcm_MsgType adrSrc_pu8,
        /* MR12 RULE 8.13 VIOLATION: The pointers cannot be made constants since MsgPtr is been assigned to adrDest_pu8 and is being modified  */
        const Dcm_MsgType MsgPtr,
        Dcm_MsgLenType MsgLen,
        PduIdType dcmRxPduId_u8)
{
    Dcm_MsgType adrDest_pu8;
    Dcm_StatusType dataReturnValue_u8;
    uint16_least idxIndex_qu16;
    boolean roeReqAccepted_b;
    uint8 idxProtocol_u8;
    Dcm_DsdStatesType_ten DsdState_en = Dcm_Dsd_Prv_GetDsdState();
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    Dcm_DslProtocolPreemptionStatesType_ten DslPreemptionStateTemp_u8;
#endif
    adrDest_pu8 = MsgPtr;
    idxProtocol_u8 = 0x0;
    /* Initialize the flag to reject ROE event during initialization */

    roeReqAccepted_b = FALSE;

    /* Initialize the value to ROE not accepted */
    dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;
    /* Check whether the DCM is free */
    /* Below section of the code is to protect the state transition from IDLE or
     * READY_FOR_RECEPTION to ROETYPE1_RECEIVED, it is possible that other state
     * transitions from these states can also be triggered in parallel from other
     * contexts, thus this lock is needed
     */

    /* Multicore: Lock needed here to avoid parallel DSL state update in Rx and Tx confirmation calls */
    if ((Dcm_Dsl_Prv_GetDslState() == DSL_STATE_IDLE_E) && (DsdState_en== DSD_IDLE_E)
            && (adrDest_pu8 != NULL_PTR) && (adrSrc_pu8 != NULL_PTR))
    {
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
        DslPreemptionStateTemp_u8 = Dcm_Dsl_Prv_GetPreemptionState();
        if(DslPreemptionStateTemp_u8 != DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E)
#endif
        {
            /* By moving the DSL state ignore request from tester */
            Dcm_Dsl_Prv_SetDslState(DSL_STATE_ROETYPE1_RECEIVED_E);
            Dcm_Dsd_Prv_SetDsdState(DSD_VERIFICATION_E);
            /*Initialize the flag to accept ROE event during initialization*/
            roeReqAccepted_b = TRUE;
        }
    }


    if (roeReqAccepted_b)
    {
        /* Multicore: No lock necessary as the DSL state machine will ensure data consistency */
        /* Only when Dcm is free there is a possibility that code reaches here */
        Dcm_Prv_SetActiveRxPduId(dcmRxPduId_u8,(PduLengthType) MsgLen);
        Dcm_Prv_SetServiceTable(srvTableId_u8);

        /* Multicore: No locking necessary as Dcm_DsldGlobal_st.dataActiveRxPduId_u8 is an atomic variable and
         there is no parallel writing due to DSL state machine handling */

        /* This is ROE requested service */
        Dcm_Dsd_Prv_SetSourceofReq(DCM_ROE_SOURCE);

        /* Copy the request and free the buffer */
        for (idxIndex_qu16 = (uint16) MsgLen; idxIndex_qu16 != 0x00u; idxIndex_qu16--)
        {

            *adrSrc_pu8 = *adrDest_pu8;

            adrSrc_pu8++;

            adrDest_pu8++;

        }
        dataReturnValue_u8 = DCM_E_OK;
    }
    else
    {
        /* pass the event Id to the function Dcm_UpdateROEQueue ()to queue the event since DCM is currently busy. */
        dataReturnValue_u8 = Dcm_UpdateROEQueue(*(MsgPtr + MsgLen), dcmRxPduId_u8);
    }

    return (dataReturnValue_u8);
}

#if(DCM_CFG_ROETYPE2_ENABLED == DCM_CFG_ON)
/**
 **************************************************************************************************
 * Dcm_ROE_TYPE2 : Function called by the ROE service whenever the ROE_TYPE2 request is received.
 *
 * \param          Dcm_MsgLenType MsgLen : Length of the request
 *
 *
 * \retval         DCM_E_OK: ResponseOnOneEvent request is accepted by DCM ,
 *                 DCM_E_ROE_NOT_ACCEPTED: ResponseOnOneEvent request is not accepted by DCM
 * \seealso
 *
 **************************************************************************************************
 **/

static Dcm_StatusType Dcm_Prv_ROE_TYPE2(Dcm_StatusType dataReturnValue_u8,
        Dcm_MsgType adrSrc_pu8,
        /* MR12 RULE 8.13 VIOLATION: The pointers cannot be made constants since MsgPtr is been assigned to adrDest_pu8 and is being modified  */
        const Dcm_MsgType MsgPtr,
        Dcm_MsgLenType MsgLen,
        PduIdType dcmRxPduId_u8)
{
    Dcm_MsgType adrDest_pu8;
    uint8 idxProtocol_u8;
    uint8 idxIndex_u8;
    uint16_least idxIndex_qu16;

#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
    uint8 nrService_u8;
    const Dcm_DsdServiceTableConfigType_tst * adrSrvTable_pcst;
#endif
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();
    adrDest_pu8 = MsgPtr;
    idxProtocol_u8 = 0x0;

    /* Check if any event response under processing*/
    if((Dcm_DsdRoe2State_en == DSD_IDLE_E) &&
            (dataReturnValue_u8 == DCM_E_OK) &&
            (adrDest_pu8 != NULL_PTR) && (adrSrc_pu8 != NULL_PTR))
    {

        /* Copy the request and free the buffer */
        for(idxIndex_qu16 = (uint16)MsgLen; idxIndex_qu16 != 0x00u; idxIndex_qu16--)
        {
            *adrSrc_pu8 = *adrDest_pu8;

            adrSrc_pu8++;

            adrDest_pu8++;
        }
        /* Get the ROE structure */
        /* Store the request length */
        Dcm_Roe2MesContext_st.reqDataLen = MsgLen - 1u;
        /* Store the RxPdu Id */
        Dcm_Roe2MesContext_st.dcmRxPduId = dcmRxPduId_u8;
        /* Get the number of services present in the ROE service table */
        nrService_u8 = Dcm_Cfg_Dsd_pcst->sidTables_pcast[ActiveRoeConnection->srvTableId_u8].numOfServices_u8;;
        /* Get the pointer to service table*/
        adrSrvTable_pcst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[ActiveRoeConnection->srvTableId_u8].srvTable_pcast;

        Dcm_Roe2MesContext_st.idContext = ActiveRoeConnection->buffer_ptr[0];

        /* Search the requested service in ROE service table */
        for(idxIndex_u8 = 0x00u; idxIndex_u8 != nrService_u8; idxIndex_u8++)
        {
            if(Dcm_Roe2MesContext_st.idContext == adrSrvTable_pcst[idxIndex_u8].sid_u8)
            {
                /* SID Found, break the loop */
                break;
            }
        }
        /* Is SID exists in table? */
        if(idxIndex_u8 != nrService_u8)
        {
            /* Store the index of the service */
            Dcm_DsldSrvIndex_u8 = idxIndex_u8;
            /* Process the request in next call of Dcm_MainFunction() */
            Dcm_DsdRoe2State_en = DSD_VERIFICATION_E;
        }
        else
        {
            /* Service requested by ROE is not configured in ROE service table */
            dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;
        }
    }
    else
    {
        /* pass the event Id to the function Dcm_UpdateROEQueue ()to queue the event since DCM is currently busy. */
        /*MR12 RULE 21.18,18.1,DIR 4.1 VIOLATION : adrDest_pu8 will never be out of bound as the MsgLen is either
         * 2bytes(DTC) or 3bytes(DID) and the size of adrDest_pu8 is 3bytes in case of DTC and 4bytes in case of DID */
        dataReturnValue_u8= Dcm_UpdateROEQueue(*(adrDest_pu8+MsgLen+1) , dcmRxPduId_u8);
    }
    return(dataReturnValue_u8);
}
#endif

/**
 **************************************************************************************************
 * Dcm_Prv_ROE_CheckLength : Function called by the ROE service when the request is received and check
 * for the length.
 * \param
 *
 * \retval         DCM_E_OK: ResponseOnOneEvent request is accepted by DCM ,
 *                 DCM_E_ROE_NOT_ACCEPTED: ResponseOnOneEvent request is not accepted by DCM
 * \seealso
 *
 **************************************************************************************************
 **/
static Dcm_StatusType Dcm_Prv_ROE_CheckLength(const Dcm_MsgType MsgPtr,
        Dcm_MsgLenType MsgLen,
        PduIdType dcmRxPduId_u8)
{
    const Dcm_DslProtocolRowConfigType_tst* ActiveRoeProtocolRow = Dcm_Prv_GetActiveRoeProtocolRow();
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();
    Dcm_StatusType dataReturnValue_u8;
    boolean dataStartProtocol_b;
    Dcm_MsgType adrSrc_pu8;
    boolean ChkFullComMode_b;
    Dcm_DslStatesType_ten DslState_en;
    boolean statusofProtocolstarted_b;
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    Dcm_DslProtocolPreemptionStatesType_ten DslprotocolPreemptionState;
#endif
    /* Initialize the value to ROE not accepted */
    dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;

    /* Copy the buffer pointer */
    dataStartProtocol_b = FALSE;
    adrSrc_pu8 = NULL_PTR;

    /* Check for validity of RxPdu before accepting for processing */
    if (dcmRxPduId_u8 < DCM_CFG_TOTAL_RX_PDUID)
    { /* Update the local variables */
        dataReturnValue_u8 = Dcm_GetRoeProtValidity(ActiveRoeProtocolRow, ActiveRoeConnection);
    }

    /* Protocols buffer should be greater than or equal to request length and check if the protocol is available
     in the current active config set*/
    ChkFullComMode_b = DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetMainConnection(dcmRxPduId_u8)->channel_idx_u8);
    if ((dataReturnValue_u8 == DCM_E_OK)&& (TRUE == ChkFullComMode_b)&&(MsgLen <= ActiveRoeConnection->txBufferSize_u32))
    {
        adrSrc_pu8 = ActiveRoeConnection->buffer_ptr;

        /* check whether any protocol is active in DCM */
        /*Check if Dsl state is ready for receving the request*/
        statusofProtocolstarted_b=Dcm_Prv_IsProtocolStarted();
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
        DslprotocolPreemptionState=Dcm_Dsl_Prv_GetPreemptionState();
#endif
        DslState_en=Dcm_Dsl_Prv_GetDslState();
        if ((statusofProtocolstarted_b == FALSE) && (DslState_en == DSL_STATE_IDLE_E)
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
                &&
                (DslprotocolPreemptionState != DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E)
#endif
        )
        {
            /*Initialize the flag for Comm Active protocol*/
            Dcm_Prv_SetProtocolStatus(TRUE);
            /*Initialize the data start protocol to get protocol id*/
            dataStartProtocol_b = TRUE;
        }
        /*Dcm is busy, queue the DTCs*/

        /*Check if the data protocol id is set to get the protocol id*/
        if (dataStartProtocol_b != FALSE)
        {
            dataReturnValue_u8 = Dcm_Prv_ROE_StartProtocol(ActiveRoeConnection->srvTableId_u8,dcmRxPduId_u8);
        }

        /* Check the type of ROE */
        if ((DCM_TRANSTYPE1_E == ActiveRoeProtocolRow->transType_en)
                && (dataReturnValue_u8 == DCM_E_OK))
        {
            dataReturnValue_u8 = Dcm_Prv_ROE_TYPE1(ActiveRoeConnection->srvTableId_u8,adrSrc_pu8, MsgPtr, MsgLen, dcmRxPduId_u8);
        }
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
        else if((dataReturnValue_u8 == DCM_E_OK) &&
                (DCM_TRANSTYPE2_E == ActiveRoeProtocolRow->transType_en))
        {
            dataReturnValue_u8 = Dcm_Prv_ROE_TYPE2(dataReturnValue_u8, adrSrc_pu8, MsgPtr, MsgLen, dcmRxPduId_u8);
        }
#endif
        else
        {
            /* Reject the request because unable to start protocol */
            dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;
        }
    }
    else
    {
        /* reject the request because unable to buffer is not enough to hold request */
        dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;
    }
    return (dataReturnValue_u8);
}

/**
 **************************************************************************************************
 * Dcm_Prv_ResponseOnOneEvent : Function called by the ROE service whenever the event occurred.
 *                          This function is not re-entrant function and it not called in other than
 *                          Dcm_MainFunction() task.
 *
 * \param          Dcm_MsgType MsgPtr :    Pointer to buffer which contains the request
 *                 Dcm_MsgLenType MsgLen : Length of the request
 *                 PduIdType DcmRxPduId  : Rx PDU id on which ROE request is received.
 *
 * \retval         DCM_E_OK: ResponseOnOneEvent request is accepted by DCM ,
 *                 DCM_E_ROE_NOT_ACCEPTED: ResponseOnOneEvent request is not accepted by DCM
 * \seealso
 *
 **************************************************************************************************
 **/

Dcm_StatusType Dcm_Prv_ResponseOnOneEvent( const Dcm_MsgType MsgPtr,
        Dcm_MsgLenType MsgLen,
        uint16 TesterSrcAddr
)
{
    Dcm_StatusType dataReturnValue_u8;

    PduIdType idxIndex;

    PduIdType dcmRxPduId_u8;


    /* Initialize the value to ROE not accepted */
    dataReturnValue_u8 = DCM_E_ROE_NOT_ACCEPTED;

    for (idxIndex = 0; idxIndex < DCM_CFG_TOTAL_RX_PDUID; idxIndex++)
    {
        if (Dcm_Dsld_RoeRxToTestSrcMappingTable[idxIndex].testsrcaddr_u16 == TesterSrcAddr)
        {
            break;
        }

    }
    if (idxIndex < DCM_CFG_TOTAL_RX_PDUID)
    {
        /*Copy the RxPduID corresponding to the tester source address */
        dcmRxPduId_u8 = Dcm_Dsld_RoeRxToTestSrcMappingTable[idxIndex].rxpduid_num_u8;

        /* Check if Dcm is initialized and ready to accept the the request */
        if ((Dcm_Prv_IsDcmInitialized() != FALSE) && (Dcm_BootSeqComplete_b != FALSE))
        {
            dataReturnValue_u8 = Dcm_Prv_ROE_CheckLength(MsgPtr, MsgLen, dcmRxPduId_u8);
        }

    }
    return (dataReturnValue_u8);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/**
 **************************************************************************************************
 * Dcm_DsldRoeTimeOut :  Monitoring of ROE timer
 *
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
void Dcm_DsldRoeTimeOut(void)
{
    /* Is this ROE call */
    /* Multicore: No lock needed here as Dsl state is an atomic operation */
    /* DSL state machine handling ensures that there is no data consistency issues */
    /* And this API is called only when DSL is processing ROE event and hence no parallel write is possible */
    if(Dcm_Dsl_Prv_GetDslState() == DSL_STATE_ROETYPE1_RECEIVED_E)
    {
        /* Is ROE timeout occurred? */
        if(DCM_TimerElapsed(dataTimerTimeout_u32)== FALSE)
        {
            /* Start ROE2 timer */
            DCM_TimerProcess(dataTimerTimeout_u32,Dcm_TimerStartTick_u32,
                    Dcm_CounterValueTimerStatus_uchr);
        }
        else
        {
            /* Give the confirmation to ROE application */
            DcmAppl_DcmConfirmation(Dcm_Dsd_Prv_GetIdContext(),Dcm_Dsd_Prv_GetReqType(),
                    Dcm_Prv_GetConnectionIndex(Dcm_Dsd_Prv_GetdcmRxPduId()),DCM_RES_POS_NOT_OK,
                    Dcm_Prv_GetActiveProtocolType(),
                    Dcm_Prv_GetTesterSrcAddressFromRxPduId(Dcm_Dsd_Prv_GetdcmRxPduId()));

            /* reset the DCM states */
            Dcm_Dsd_Prv_SetDsdState(DSD_IDLE_E);

            /* Multicore: No lock needed here as Dsl state is an atomic operation */
            /* DSL state machine handling ensures that there is no data consistency issues */
            /* Also this API is called from DSD state machine after DSL state machine, hence no parallel write */
            Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
        }
    }
}
#endif

/**
 **************************************************************************************************
 * Dcm_TriggerOnEvent:
 * The call to this function allows to trigger an event linked to a ResponseOnEvent request.
 * On the function call, the DCM will execute the associated service. This function
 * shall be called only if the associated event has been activated through a
 * xxx_ActivateEvent() call.
 *
 * \parameters           RoeEventId
 * \return value         Std_ReturnType
 *
 **************************************************************************************************
 */
Std_ReturnType Dcm_TriggerOnEvent( uint8 RoeEventId)
{
#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_ROE_ENABLED != DCM_CFG_OFF) &&\
        (DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_ROEDID_ENABLED != DCM_CFG_OFF))
    uint16 idxRoeDid_u8;
    Std_ReturnType dataRetStartFunc_u8;
    Dcm_StatusType dataRoeStatus_u8;
    uint8 dataSrc_u8[4];
    uint32 datatMsgLen_u32;

    idxRoeDid_u8=0x0;
    dataRetStartFunc_u8=E_NOT_OK;
    datatMsgLen_u32=0;

    /* BSWEXT-533 */
    SchM_Enter_Dcm_Global();

    /*Loop through all the ROE dids and chk if the event id is valid*/
    for(idxRoeDid_u8=0;idxRoeDid_u8<DCM_MAX_DIDROEEVENTS;idxRoeDid_u8++)
    {
        if(RoeEventId==DcmDspRoeDidEvents[idxRoeDid_u8].RoeEventId_u8)
        {
            /*Valid ROEEVENT ID*/
            break;
        }
    }
    /*Check if the event is valid and is in the started state & if not return value is already
     * set to E_NOT_OK if the event is not found or cleared.*/
    if(idxRoeDid_u8<DCM_MAX_DIDROEEVENTS)
    {
        /*Chk if the event is started*/
        if(DCM_ROE_STARTED==DcmDspRoeDidStateVariables[idxRoeDid_u8].RoeEventStatus)
        {
            /*Enters here only if the event is started and the event id is valid*/
            dataRetStartFunc_u8=E_OK;
        }
    }

    if(E_OK==dataRetStartFunc_u8)
    {
        /**Simulate the request in the buffer and invoke Dcm_Prv_ResponseOnOneEvent*/
        dataSrc_u8[0]=0x22u; /*RDBI service ID*/
        dataSrc_u8[1]=(uint8)((DcmDspRoeDidStateVariables[idxRoeDid_u8].stSrvToRespDid_u16)>>8u); /*DID high byte*/
        dataSrc_u8[2]=(uint8)(DcmDspRoeDidStateVariables[idxRoeDid_u8].stSrvToRespDid_u16); /*DID low byte*/
        dataSrc_u8[3]= RoeEventId;/*Roe Event ID is passed to the Dcm_Prv_ResponseOnOneEvent as an implicit parameter,
         the datatMsgLen_u32 will not be changed,it is intentional*/
        datatMsgLen_u32=3;
        dataRoeStatus_u8=Dcm_Prv_ResponseOnOneEvent(dataSrc_u8,datatMsgLen_u32,
                DcmDspRoeDidStateVariables[idxRoeDid_u8].SourceAddress_u16);
        /*  Check if DCM Is free or busy processing another request, if DCM is busy return E_NOT_OK*/
        if(dataRoeStatus_u8!=DCM_E_OK)
        {
            dataRetStartFunc_u8=E_NOT_OK;
        }
    }
    /* BSWEXT-533 */
    SchM_Exit_Dcm_Global();
    return dataRetStartFunc_u8;
#else
    (void) RoeEventId;
    return E_NOT_OK;
#endif
}

/**
 **************************************************************************************************
 * Dcm_DemTriggerOnDTCStatus :  This function is invoked by Dem on an interrupt context to inform DCM about the
 * status mask change for a particular DTC, this information can be used by DTC
 * to check if RDTC service has to be invoked or not based on the DTC if it was
 * setup by tester for ROE onchangeofDTC.
 *
 * \param           Dtc                 :   This is the DTC the change trigger is assigned
 *                  DTCStatusOld        :   Old Status
 *                  DTCStatusNew        :   New Status
 * \retval          E_OK          :   This value is always returned
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
Std_ReturnType Dcm_DemTriggerOnDTCStatus( uint32 Dtc,
        uint8 DTCStatusOld,
        uint8 DTCStatusNew )
{
#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF)&&\
        (DCM_ROE_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_ROEONDTCSTATUSCHANGE_ENABLED != DCM_CFG_OFF))
    uint8 dataSid_u8;
    uint8 dataSrc_u8[3];
    uint32 datatMsgLen_u32;


    /* BSWEXT-533 */
    SchM_Enter_Dcm_Global();
    dataSid_u8=Dcm_Dsd_Prv_GetIdContext();


    /*Make sure the current active service is not CDI service and SID variable is not in init state (SID value as 0)*/
    if((dataSid_u8 != 0x14) && (dataSid_u8 != 0x0))
    {
        /*Check if ROE for DTC is already started*/
        if(DCM_ROE_STARTED==DcmDspRoeDtcStateVariable.RoeEventStatus)
        {
            /*Has the DTC status changed and if the mask bit provided by the tester is changed*/
            if(((DTCStatusOld & DcmDspRoeDtcStateVariable.testerReqDTCStatusMask_u8) ^\
                    (DTCStatusNew & DcmDspRoeDtcStateVariable.testerReqDTCStatusMask_u8)) != 0x0)
            {
                /**Simulate the request in the buffer and invoke Dcm_Prv_ResponseOnOneEvent*/
                dataSrc_u8[0]=0x19u; /*RDTC service ID*/
                dataSrc_u8[1]=0x0Eu; /*DID high byte*/
                dataSrc_u8[2]= DcmDspRoeDtcEvent.RoeEventId_u8;/*Roe Event ID is passed to the Dcm_Prv_ResponseOnOneEvent
                 as an implicit parameter,the datatMsgLen_u32 will not be changed,it is intentional*/
                datatMsgLen_u32=0x02u;
                (void)Dcm_Prv_ResponseOnOneEvent(dataSrc_u8,datatMsgLen_u32,
                        DcmDspRoeDtcStateVariable.SourceAddress_u16);
            }
        }
    }
#else

    (void)(DTCStatusOld);
    (void)(DTCStatusNew);
#endif

    (void)(Dtc);

    /* BSWEXT-533 */
    SchM_Exit_Dcm_Global();
    return E_OK;
}

#if(DCM_ROE_ENABLED == DCM_CFG_ON && DCM_CFG_DSP_RESPONSEONEVENT_ENABLED == DCM_CFG_ON)

/**
 **************************************************************************************************
 * Dcm_CheckDTCEventWindowTimeROE_STARTED:
 * This function will be invoked from the Dcm_Init().
 * In this function handling of the DTC event window time when the ROE event is STARTED
 * \parameters           None
 * \return value         None
 *
 *
 **************************************************************************************************
 */
static void Dcm_Prv_CheckDTCEventWindowTimeROE_STARTED(uint8 roeEventWindowTime_u8)
{
    if((roeEventWindowTime_u8 == 0x02u) || (roeEventWindowTime_u8 == 0x04u))
    {
        /*Restart the events which are started in the default session ans the storage state is set TRUE for
         both the control start request and the set up request and the event window  time supports the
         storage state(event window time is infinity(0x02) or current and following cycle(0x04u))*/
        if((TRUE == DcmDspRoeDtcStateVariable.stDspRoeSessionIsDefault_b )&&
                (TRUE == DcmDspRoeDtcStateVariable.stDspRoeCtrlStorageState_b)&&
                (TRUE == DcmDspRoeDtcStateVariable.stDspRoeStorageState_b))
        {
            /*Inform application to restsrt the roe event*/
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DCM_ROE_STARTED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,DCM_ROE_STARTED);

        }
        else
        {
            /*Conditions does not support  to restart the ROE ,therefore stop it and inform application*/
            DcmDspRoeDtcStateVariable.RoeEventStatus =DCM_ROE_STOPPED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DCM_ROE_STOPPED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,DCM_ROE_STOPPED);
        }
    }
    /*Check if the event window time is CURRENT_CYCLE, then the window period is over .Stop the event and
     inform the application */
    else if(roeEventWindowTime_u8 == 0x03u)
    {
        /*Check whether the event is preconfigured*/
        if(FALSE != DcmDspRoeDtcStateVariable.Is_PreConfigured_b)
        {
            DcmDspRoeDtcStateVariable.RoeEventStatus =DCM_ROE_STOPPED;
        }
        else
        {
            /*The set up is done by the tester,if the set up is stored in NVM update the status as stopped,
             else cleared*/
            if(FALSE == DcmDspRoeDtcStateVariable.stDspRoeStorageState_b)
            {
                DcmDspRoeDtcStateVariable.RoeEventStatus = DCM_ROE_CLEARED;
            }
            else
            {
                DcmDspRoeDtcStateVariable.RoeEventStatus = DCM_ROE_STOPPED;
            }
        }
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DcmDspRoeDtcStateVariable.RoeEventStatus);
#endif
        DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,
                DcmDspRoeDtcStateVariable.RoeEventStatus);
    }
    else
    {

        /*dummy else*/
    }
}

/**
 **************************************************************************************************
 * Dcm_CheckDTCEventWindowTimeROE_STOPPED:
 * This function will be invoked from the Dcm_Init().
 * In this function handling of the DTC event window time when the ROE event is STOPPED
 * \parameters           None
 * \return value         None
 *
 *
 **************************************************************************************************
 */
static void Dcm_Prv_CheckDTCEventWindowTimeROE_STOPPED(uint8 roeEventWindowTime_u8)
{
    /*Remain in the stopped state if the  the events are stopped in the default session ans the storage state
     is set TRUE fro both the control start request and the set up request and the event window  time
     supports the storage state(event window time is infinity(0x02) or current and following cycle(0x04u))*/

    if(((roeEventWindowTime_u8 == 0x02u) ||(roeEventWindowTime_u8 == 0x04u)) &&
            (TRUE == DcmDspRoeDtcStateVariable.stDspRoeCtrlStorageState_b) &&
            (TRUE == DcmDspRoeDtcStateVariable.stDspRoeStorageState_b) )
    {

#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DCM_ROE_STOPPED);
#endif
        DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,DCM_ROE_STOPPED);
    }
    else
    {
        /*Conditions does not support  to continue in the stopped state of  ROE ,therefore clear it and
         inform application*/
        if(FALSE == DcmDspRoeDtcStateVariable.Is_PreConfigured_b)
        {
            DcmDspRoeDtcStateVariable.RoeEventStatus =DCM_ROE_CLEARED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DcmDspRoeDtcStateVariable.RoeEventStatus);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,
                    DcmDspRoeDtcStateVariable.RoeEventStatus);
        }
    }
}

/**
 **************************************************************************************************
 * Dcm_Prv_CheckDTCEventWindowTime:
 * The function handling of the DTC event window time
 * \parameters           None
 * \return value         None
 *
 *
 **************************************************************************************************
 */
static void Dcm_Prv_CheckDTCEventWindowTime(uint8 roeEventWindowTime_u8)
{
    /*Status change in conbination with current staus STARTED*/
    if((DCM_ROE_STARTED==DcmDspRoeDtcStateVariable.RoeEventStatus))
    {
        Dcm_Prv_CheckDTCEventWindowTimeROE_STARTED(roeEventWindowTime_u8);
    }
    else if(DCM_ROE_STOPPED == DcmDspRoeDtcStateVariable.RoeEventStatus)
    {
        Dcm_Prv_CheckDTCEventWindowTimeROE_STOPPED(roeEventWindowTime_u8);
    }
    else
    {
        /*Event status is cleared*/
        if(FALSE==DcmDspRoeDtcStateVariable.Is_PreConfigured_b)
        {

            DcmDspRoeDtcStateVariable.RoeEventStatus =DCM_ROE_CLEARED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DCM_ROE_CLEARED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,DCM_ROE_CLEARED);
        }
    }
    if(roeEventWindowTime_u8 == 0x04u)
    {
        /*Now one cycle is already over ,reset the event windowtime CURRENT_FOLLOWING_CYCLE to CURRENT_CYCLE*/
        DcmAppl_DcmStoreROEcycleCounter(DcmDspRoeDtcEvent.RoeEventId_u8,0x03u);
    }
}

#if(DCM_CFG_DSP_ROEDID_ENABLED != DCM_CFG_OFF)
/**
 **************************************************************************************************
 * Dcm_CheckDIDEventWindowTimeROE_STARTED:
 * This function will be invoked from the Dcm_Init().
 * In this function handling of the DID event window time when the ROE event is STARTED
 *
 * \parameters           None
 * \return value         None
 *
 *
 **************************************************************************************************
 */
static void Dcm_Prv_CheckDIDEventWindowTimeROE_STARTED(uint8 roeEventWindowTime_u8,
        uint8 dataidxLoop_u8)
{
    if((roeEventWindowTime_u8 == 0x02u) || (roeEventWindowTime_u8 == 0x04u))
    {
        /*Restart the events which are started in the default session ans the storage state is set TRUE for
         both the control start request and the set up request and the event window  time supports the
         storage state(event window time is infinity(0x02) or current and following cycle(0x04u))*/
        if((TRUE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeSessionIsDefault_b )&&
                (TRUE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeCtrlStorageState_b)&&
                (TRUE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeStorageState_b) )
        {
            /*Inform application to restsrt the roe event*/
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DCM_ROE_STARTED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,DCM_ROE_STARTED);

        }
        else
        {
            /*Conditions does not support  to restart the ROE ,therefore stop it and inform application*/
            DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus =DCM_ROE_STOPPED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DCM_ROE_STOPPED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,DCM_ROE_STOPPED);
        }
    }
    /*Check if the event window time is CURRENT_CYCLE, then the window period is over .Stop the event and
     inform the application */
    else
    {
        if(roeEventWindowTime_u8 == 0x03u)
        {
            if(FALSE != DcmDspRoeDidStateVariables[dataidxLoop_u8].Is_PreConfigured_b)
            {
                DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus =DCM_ROE_STOPPED;
            }
            else
            {
                /*The set up is done by the tester,if the set up is stored in NVM update the status as
                 stopped,else cleared*/
                if(FALSE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeStorageState_b)
                {
                    DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus = DCM_ROE_CLEARED;
                }
                else
                {
                    DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus = DCM_ROE_STOPPED;
                }
            }
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,
                    DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus);
        }
    }
}

/**
 **************************************************************************************************
 * Dcm_CheckDIDEventWindowTimeROE_STOPPED:
 * This function will be invoked from the Dcm_Init().
 * In this function handling of the DID event window time when the ROE event is STOPPED
 *
 * \parameters           None
 * \return value         None
 *
 *
 **************************************************************************************************
 */
static void Dcm_Prv_CheckDIDEventWindowTimeROE_STOPPED(uint8 roeEventWindowTime_u8,
        uint8 dataidxLoop_u8)
{
    /*Remain in the stopped state if the  the events are stopped in the default session and the storage
     state is set TRUE fro both the control start request and the set up request and the event window
     time supports the storage state(event window time is infinity(0x02) or current and
     following cycle(0x04u))*/
    if(((roeEventWindowTime_u8 == 0x02u) ||(roeEventWindowTime_u8 == 0x04u)) &&
            (TRUE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeCtrlStorageState_b) &&
            (TRUE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeStorageState_b))
    {

#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DCM_ROE_STOPPED);
#endif
        DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,DCM_ROE_STOPPED);

    }
    else
    {
        /*Conditions does not support  to continue in the stopped state of  ROE ,therefore clear it and
         inform application*/
        if(FALSE == DcmDspRoeDidStateVariables[dataidxLoop_u8].Is_PreConfigured_b)
        {
            DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus =DCM_ROE_CLEARED;

#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,
                    DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus);
        }
    }
}
/**
 **************************************************************************************************
 * Dcm_Prv_CheckDIDEventWindowTime:
 * The function handling of the DID event window time
 * \parameters           None
 * \return value         None
 *
 *
 **************************************************************************************************
 */
static void Dcm_Prv_CheckDIDEventWindowTime(uint8 roeEventWindowTime_u8,
        uint8 dataidxLoop_u8)
{
    /*Status change in conbination with current staus STARTED*/
    if ((DCM_ROE_STARTED == DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus))
    {
        Dcm_Prv_CheckDIDEventWindowTimeROE_STARTED(roeEventWindowTime_u8, dataidxLoop_u8);
    }
    else if (DCM_ROE_STOPPED == DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus)
    {
        Dcm_Prv_CheckDIDEventWindowTimeROE_STOPPED(roeEventWindowTime_u8, dataidxLoop_u8);
    }
    else
    {
        if (FALSE == DcmDspRoeDidStateVariables[dataidxLoop_u8].Is_PreConfigured_b)
        {

            DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus = DCM_ROE_CLEARED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DCM_ROE_CLEARED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8, DCM_ROE_CLEARED);
        }
    }

    if (roeEventWindowTime_u8 == 0x04u)
    {
        /*Now one cycle is already over ,reset the event windowtime CURRENT_FOLLOWING_CYCLE to CURRENT_CYCLE*/
        DcmAppl_DcmStoreROEcycleCounter(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8, 0x03u);
    }
}
#endif
/**
 **************************************************************************************************
 * Dcm_RestoreROEDtcEvents:
 * This function will be invoked from the Dcm_Init().
 * In this function handling of the event window time restoring and storing of DTC information from and to
 * application happens.
 * \parameters           None
 * \return value         None
 *
 **************************************************************************************************
 */
#if(DCM_CFG_DSP_ROEONDTCSTATUSCHANGE_ENABLED != DCM_CFG_OFF)
void Dcm_RestoreROEDtcEvents(void)
{
    uint8 roeEventWindowTime_u8;/*local varaible to store the event windowtime*/
    Std_ReturnType dataResult_u8;/* local variable to store the return value from the application */
    roeEventWindowTime_u8 =0x0u;/*initialize the local variable*/

    /*Check the initial event status from the configuration ,if the event is preconfigured inform the application
     through API call*/
    if(TRUE==DcmDspRoeDtcStateVariable.Is_PreConfigured_b)
    {

#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DCM_ROE_STOPPED);
#endif
        DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,DCM_ROE_STOPPED);
    }
    if((TRUE == DcmDspRoeDtcStateVariable.stDspRoeSessionIsDefault_b )&&
            (FALSE == DcmDspRoeDtcStateVariable.stDspRoeCtrlStorageState_b))
    {
        /*Call the application API to retrieve the roe evnet information stored in the NvM*/
        dataResult_u8 = E_NOT_OK;
    }
    else
    {
        /*Call the application API to retrieve the roe evnet information stored in the NvM*/
        dataResult_u8 = DcmAppl_DcmGetRoeDTCInfo(DcmDspRoeDtcEvent.RoeEventId_u8,
                &DcmDspRoeDtcStateVariable.RoeEventStatus,
                &roeEventWindowTime_u8,
                &DcmDspRoeDtcStateVariable.SourceAddress_u16,
                &DcmDspRoeDtcStateVariable.testerReqDTCStatusMask_u8,
                &DcmDspRoeDtcStateVariable.stDspRoeCtrlStorageState_b,
                &DcmDspRoeDtcStateVariable.stDspRoeStorageState_b,
                &DcmDspRoeDtcStateVariable.stDspRoeSessionIsDefault_b);
    }
    if(E_OK == dataResult_u8)
    {
        Dcm_Prv_CheckDTCEventWindowTime(roeEventWindowTime_u8);
    }
    else
    {
        if(FALSE==DcmDspRoeDtcStateVariable.Is_PreConfigured_b)
        {
            /*The information could not be taken from the Nvm,move evnt status to CLEARED*/
            DcmDspRoeDtcStateVariable.RoeEventStatus =DCM_ROE_CLEARED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DCM_ROE_CLEARED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,DCM_ROE_CLEARED);
        }
    }
}
#endif
/**
 **************************************************************************************************
 * Dcm_RestoreROEDidEvents:
 * This function will be invoked from the Dcm_Init().
 * In this function handling of the event window time restoring and storing of DID information from and to
 * application happens.
 * \parameters           None
 * \return value         None
 *
 **************************************************************************************************
 */

#if(DCM_CFG_DSP_ROEDID_ENABLED!=DCM_CFG_OFF)
void Dcm_RestoreROEDidEvents(void)
{

    Std_ReturnType dataResult_u8;/* local variable to store the return value from the application */
    uint8 dataidxLoop_u8;
    uint8 roeEventWindowTime_u8;/*local varaible to store the event windowtime*/

    for(dataidxLoop_u8 =0x0u;dataidxLoop_u8<DCM_MAX_DIDROEEVENTS;dataidxLoop_u8++)
    {
        roeEventWindowTime_u8 =0x0u;/*Reset the loacal variable*/

        /*Check the initial event status from the configuration ,if the event is preconfigured inform the
         application through API call*/
        if(TRUE==DcmDspRoeDidStateVariables[dataidxLoop_u8].Is_PreConfigured_b)
        {

#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DCM_ROE_STOPPED);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,DCM_ROE_STOPPED);
        }
        if((TRUE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeSessionIsDefault_b )&&
                (FALSE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeCtrlStorageState_b))
        {
            /*Call the application API to retrieve the roe evnet information stored in the NvM*/
            dataResult_u8 = E_NOT_OK;
        }
        else
        {
            /*Call the application API to retrieve the roe evnet information stored in the NvM*/
            dataResult_u8 = DcmAppl_DcmGetROEDidInfo(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventDid_u16,
                    DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,
                    &DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus,
                    &roeEventWindowTime_u8,
                    &DcmDspRoeDidStateVariables[dataidxLoop_u8].SourceAddress_u16,
                    &DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeCtrlStorageState_b,
                    &DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeStorageState_b,
                    &DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeSessionIsDefault_b);
        }

        if(E_OK == dataResult_u8)
        {
            Dcm_Prv_CheckDIDEventWindowTime(roeEventWindowTime_u8, dataidxLoop_u8);
        }
        else
        {
            if(FALSE==DcmDspRoeDidStateVariables[dataidxLoop_u8].Is_PreConfigured_b)
            {
                /*The information could not be taken from the Nvm,move evnt status to CLEARED*/
                DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus =DCM_ROE_CLEARED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
                (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DCM_ROE_CLEARED);
#endif
                DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,DCM_ROE_CLEARED);
            }
        }
    }

}
#endif
/**
 **************************************************************************************************
 * Dcm_ResetROEEvents:
 * This function will be invoked whenever a session change occurs from Dcm_DspConfirmation.
 * In this function will stop all the events which are already started in the previous session.
 * \parameters           None
 * \return value         None
 *
 **************************************************************************************************
 */
void Dcm_ResetROEEvents(void)
{
#if(DCM_CFG_DSP_ROEDID_ENABLED!=DCM_CFG_OFF)
    uint8 dataidxLoop_u8;/*Loop index*/
#endif

#if(DCM_CFG_DSP_ROEONDTCSTATUSCHANGE_ENABLED != DCM_CFG_OFF)
    /*Move the already started ROE events to the STOPPED state if it is started in any non-default session */
    if((DCM_ROE_STARTED==DcmDspRoeDtcStateVariable.RoeEventStatus) &&
            (DcmDspRoeDtcStateVariable.stDspRoeSessionIsDefault_b == FALSE))
    {
        DcmDspRoeDtcStateVariable.RoeEventStatus =DCM_ROE_STOPPED;
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
        (*(DcmDspRoeDtcEvent.ROEDTC_fp))(DcmDspRoeDtcStateVariable.RoeEventStatus);
#endif
        DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDtcEvent.RoeEventId_u8,DcmDspRoeDtcStateVariable.RoeEventStatus);
    }
#endif

#if(DCM_CFG_DSP_ROEDID_ENABLED!=DCM_CFG_OFF)
    for(dataidxLoop_u8 =0x0u;dataidxLoop_u8<DCM_MAX_DIDROEEVENTS;dataidxLoop_u8++)
    {
        if((DCM_ROE_STARTED==DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus) &&
                (FALSE == DcmDspRoeDidStateVariables[dataidxLoop_u8].stDspRoeSessionIsDefault_b ))
        {
            DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus =DCM_ROE_STOPPED;
            /*Inform application to reset the roe event*/
#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
            (*(DcmDspRoeDidEvents[dataidxLoop_u8].ROEDID_fp))(DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus);
#endif
            DcmAppl_Switch_DcmResponseOnEvent(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8,
                    DcmDspRoeDidStateVariables[dataidxLoop_u8].RoeEventStatus);
        }
    }
#endif
}

#if(DCM_CFG_ROETYPE2_ENABLED == DCM_CFG_OFF)
/**
 **************************************************************************************************
 * Dcm_Prv_CheckRoeType1StartProtocol:
 * The API will be invoked from the Dcm_DsldProcessRoeType1(),this will intern trigger the processing of the
 * start protocol RoeType1.
 *
 * \parameters           None
 * \return value         None
 *
 **************************************************************************************************
 */
static void Dcm_Prv_CheckRoeType1StartProtocol(PduIdType rxpduId)
{
    const Dcm_DslProtocolRowConfigType_tst* CurrentProtocolRow = Dcm_Prv_GetProtocolRow(rxpduId);
    /* Start the application function */
    if(Dcm_StartProtocol(CurrentProtocolRow->protocolType,Dcm_Prv_GetTesterSrcAddressFromRxPduId(rxpduId),Dcm_Prv_GetMainConnection(rxpduId)->rxConnId_u16)== E_OK )
    {
        /* Call the Initialisation function of service */
        Dcm_Dsd_Prv_ServiceInit(CurrentProtocolRow->srvTableId_u8);

    }
    else
    {
        /*Initialize the Comm Active flag to false*/
        Dcm_Prv_SetProtocolStatus(FALSE);
    }
}

/**
 **************************************************************************************************
 * Dcm_DsldProcessRoeType1:
 * The API will be invoked from the Dcm_DsldProcessRoeQueue(),this will intern trigger the processing of the RoeType1.
 *
 * \parameters           None
 * \return value         None
 *
 **************************************************************************************************
 */
static void Dcm_DsldProcessRoeType1(void)
{
    Dcm_MsgType adrSrc_pu8; /* static source address variable */
    PduIdType RxPduId_u8;
    Dcm_DslStatesType_ten DslState_en;
    Dcm_DsdStatesType_ten DsdState_en;
#if(DCM_CFG_DSP_ROEDID_ENABLED != DCM_CFG_OFF)
    uint8 dataidxLoop_u8;/*Loop index*/
#endif

#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
        Dcm_DslProtocolPreemptionStatesType_ten PreemptionState_en;
#endif

    boolean dataStartProtocol_b = FALSE;
    Dcm_DslProtocolPreemptionStatesType_ten DslPreemptionStateTemp_u8;
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();

    /* BSWEXT-505: DcmRoeQueueIndex_u8 will always have a valid index here, as this function is called only if (DcmRoeQueueIndex_u8<DCM_MAX_SETUPROEEVENTS) */
    RxPduId_u8 = (uint8)Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].RxPduId_u8;

    if(TRUE == DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetMainConnection(RxPduId_u8)->channel_idx_u8))
    {
        adrSrc_pu8 = ActiveRoeConnection->buffer_ptr;

        /* check whether any protocol is active in DCM */
        /*If the Dsl state is Ready for receving the request*/
        DslState_en = Dcm_Dsl_Prv_GetDslState();
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
        PreemptionState_en = Dcm_Dsl_Prv_GetPreemptionState();
#endif
        if((Dcm_Prv_IsProtocolStarted() == FALSE) && (DSL_STATE_IDLE_E == DslState_en)
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
                &&
                (DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E == PreemptionState_en)
#endif
        )
        {

            /*Initialize the Comm Active flag to value true */
            Dcm_Prv_SetProtocolStatus(TRUE);
            /*Initialize the data start protocol value to true */
            dataStartProtocol_b = TRUE;
        }
        /*Dcm is busy, queue the DTCs*/

        /*Check if data start protocol value is set to get the protocol id*/
        if(dataStartProtocol_b != FALSE)
        {
            Dcm_Prv_CheckRoeType1StartProtocol(RxPduId_u8);
        }


        DslState_en = Dcm_Dsl_Prv_GetDslState();
        DsdState_en = Dcm_Dsd_Prv_GetDsdState();
        if((DSL_STATE_IDLE_E == DslState_en)&& (DSD_IDLE_E == DsdState_en) &&(adrSrc_pu8 != NULL_PTR))
        {
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
            DslPreemptionStateTemp_u8 = Dcm_Dsl_Prv_GetPreemptionState();
            if((DslPreemptionStateTemp_u8 != DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E)&& (DslPreemptionStateTemp_u8 != DSL_PREEMPTION_STOP_ROE_E))
#endif
            {
                /* By moving the DSL state ignore request from tester */
                Dcm_Dsl_Prv_SetDslState(DSL_STATE_ROETYPE1_RECEIVED_E);
                Dcm_Dsd_Prv_SetDsdState(DSD_VERIFICATION_E);
            }
        }


#if(DCM_CFG_DSP_ROEONDTCSTATUSCHANGE_ENABLED != DCM_CFG_OFF)
        if( Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].EventId_u8 == DCM_ROE_DTCEVENTID)
        {
            (*adrSrc_pu8)= 0x19;
            adrSrc_pu8++;
            *adrSrc_pu8 = 0x0Eu;
            Dcm_Prv_SetActiveRxPduId(RxPduId_u8,(PduLengthType)2u);
        }
        else
#endif
        {
#if(DCM_CFG_DSP_ROEDID_ENABLED != DCM_CFG_OFF)

            for(dataidxLoop_u8 =0x0u;dataidxLoop_u8<DCM_MAX_DIDROEEVENTS;dataidxLoop_u8++)
            {
                if(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventId_u8 == Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].EventId_u8)
                {
                    break;
                }
            }
            (*adrSrc_pu8)= 0x22;
            adrSrc_pu8++;
            if (dataidxLoop_u8 != DCM_MAX_DIDROEEVENTS)
            {
                *(adrSrc_pu8) = (uint8)(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventDid_u16>>8u);
                adrSrc_pu8++;
                *(adrSrc_pu8) = (uint8)(DcmDspRoeDidEvents[dataidxLoop_u8].RoeEventDid_u16);
            }
            Dcm_Prv_SetActiveRxPduId(RxPduId_u8,(PduLengthType)3u);
#endif
        }

        /* This is ROE requested service */
        Dcm_Dsd_Prv_SetSourceofReq(DCM_ROE_SOURCE);
    }
}

#endif

/**
 **************************************************************************************************
 * Dcm_DsldProcessRoeQueue:
 * The API will be invoked from the Dcm_main(),this will intern trigger the processing of the RoeType1 and RoeType2
 *
 * \parameters           None
 * \return value         None
 *
 **************************************************************************************************
 */
void Dcm_DsldProcessRoeQueue(void)
{
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
    /*Check if ROE timeout is occured?*/
    if(DCM_TimerElapsed(datRoeType2Timeout_u32)== FALSE)
    {
        /* Start ROE2 timer */
        DCM_TimerProcess(datRoeType2Timeout_u32,Dcm_Roe2StartTick_u32,Dcm_RoeType2TimerStatus_uchr)
    }
    else
#endif
    {
        if(DcmRoeQueueIndex_u8 == DCM_MAX_SETUPROEEVENTS)
        {
            DcmRoeQueueIndex_u8 = 0x00u;
        }
        while(DcmRoeQueueIndex_u8<DCM_MAX_SETUPROEEVENTS)
        {
            if(Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].Is_Queued == TRUE)
            {
                Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].Is_Queued = FALSE;
                Dcm_DcmDspEventQueue[DcmRoeQueueIndex_u8].Is_Processed = TRUE;
                break;
            }
            DcmRoeQueueIndex_u8++;
        }
        /* BSWEXT-505 */ /* [$DD_BSWCODE 40592] */
        if(DcmRoeQueueIndex_u8 < DCM_MAX_SETUPROEEVENTS)
        {

#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
            if(Dcm_DsdRoe2State_en == DSD_IDLE_E)
            {
                Dcm_DsdRoe2State_en = DSD_VERIFICATION_E;
                /* Roe type 2 handling */
                Dcm_DsldRoe2StateMachine();
            }
#else
            Dcm_DsldProcessRoeType1();
#endif
        }
    }
}
#endif
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_ON)
/**
 **************************************************************************************************
 * Dcm_DsldPersistentRoeHandling_en : Function to do the persistent ROE handling
 * \param           adrArrivedProt_pcst (in):  Pointer to protocol table (for newly arrived request)
 *                  nrTpSduLength_u16 (in) : Length of the request.
 *                  RxPduid     (in) : Rx PDU id of arrived request.
 *  If a high priority request is to be taken; and ROE events are invoked - there is a chance ROE would reject the
 * high priority protocols request. IS0 specifies ROE to work persistently as application demands. But when a higher
 * priority protocol preempts the ROE protocol. THe high priority protocols requests are not to be ignored.
 * \retval          BufReq_ReturnType : same as above function
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

BufReq_ReturnType Dcm_DsldPersistentRoeHandling_en(PduLengthType nrTpSduLength_u16, PduIdType DcmRxPduId)

{
    /* Local variable for return value */
    BufReq_ReturnType dataReturnVal_en = BUFREQ_E_NOT_OK;

    const Dcm_DslProtocolRowConfigType_tst* ActiveRoeProtocolRow = Dcm_Prv_GetActiveRoeProtocolRow();
    const Dcm_DslProtocolRowConfigType_tst* CurrentProtocolRow = Dcm_Prv_GetProtocolRow(DcmRxPduId);
    Dcm_ProtocolType ActiveProtocolType = Dcm_Prv_GetActiveProtocolType();

    /* If the request has not arrived on the active protocol yet */
    if((DCM_CFG_INVALID_RX_PDUID) == (s_RoeProtocolPduId))
    {
        /* Check the size of the buffer */
        if((uint32)nrTpSduLength_u16 <= CurrentProtocolRow->rxBufferSize_u32)
        {
            /* Check arrived request has higher priority */
            if(ActiveRoeProtocolRow->priority_u8 > CurrentProtocolRow->priority_u8)
            {
                /* case when the incoming request is from a same protocol which is active.*/
                /* ROE might stop the preemption*/
                /* this check is for the incoming requests protocol id with the active protocol */
                if(ActiveProtocolType == CurrentProtocolRow->protocolType)
                {
                    /* Store the Rx pduid, request length and ready to receive buffer */
                    Dcm_Prv_SetActiveRxPduId(DcmRxPduId,nrTpSduLength_u16);
                    Dcm_Prv_SetRoeProtocolPduid(DcmRxPduId);
                    Dcm_PduInfo_ast[DcmRxPduId].SduLength  = nrTpSduLength_u16;
                    Dcm_Prv_Set_CurrentRequestLength(nrTpSduLength_u16);
                    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId=DcmRxPduId;
                    /*Initialize the CopyRxData status to the value true*/
                    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b = TRUE;
                    dataReturnVal_en = BUFREQ_OK;

                    /* The Trasmit_s Dsl Next State is pushed to DSL_STATE_WAITING_FOR_RXINDICATION ,since if ROE TxConfirmation arrives */
                    /* before RxIndication for this provide Rx Buffer call; DCM has to wait for the RxIndication of */
                    /* current provide Rx Buffer call */
                }
            }
            else
            {
                if(ActiveProtocolType == CurrentProtocolRow->protocolType)
                {
                    /* ROE type1 request under processing and tester request comes. Reset S3 timer */
                    Dcm_Prv_ReloadS3Timer();
                }
                /* But ignore the request */
                dataReturnVal_en = BUFREQ_E_NOT_OK;
            }

        }
        else
        {
            /* buffer is not big enough, ignore the request */
            dataReturnVal_en = BUFREQ_E_OVFL;
        }
    }
    return dataReturnVal_en;
}
#endif
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif
