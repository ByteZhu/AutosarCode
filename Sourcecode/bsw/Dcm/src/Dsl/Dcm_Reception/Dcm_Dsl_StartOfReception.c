
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
PduIdType Dcm_HighPriorityPduId_u8=DCM_CFG_INVALID_RX_PDUID;
static PduIdType LowPrioNrc21RxPduId=DCM_CFG_INVALID_RX_PDUID;
static PduLengthType RequestLength=0x00;
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
PduInfoType Dcm_PduInfo_ast[DCM_CFG_TOTAL_RX_PDUID];
Dcm_RequestInfoType_tst Dcm_ReceptionInfo_ast[DCM_CFG_TOTAL_RX_PDUID];
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
Dcm_QueueStructure_tst Dcm_QueueStructure_st;
#endif
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
Dcm_DslOBDRxPduArray_tst Dcm_DslOBDRxPduArray_ast[DCM_CFG_TOTAL_RX_PDUID];
#endif

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
boolean Dcm_LowPrioReject_b = FALSE;
#define DCM_STOP_SEC_VAR_INIT_BOOLEAN
#include "Dcm_MemMap.h"

#if(DCM_CFG_RXPDU_SHARING_ENABLED == DCM_CFG_ON)
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
boolean Dcm_isObdRequestReceived_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
#endif



/***********************************************************************************************************************
 *    Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/**
 ****************************************************************************************************************
 * Dcm_Prv_CheckValidEcuAddress : API to check valid Target Address received for the corresponding Protocol Row.
 * \param           DcmRxPduId : Received RxPDUID
 *                  info       : Recieved RxPDUInfo Pointer
 *
 * \retval          BUFREQ_E_NOT_OK : Invalid Target Address recieved
 *                  BUFREQ_OK :  Valid Target Address recieved.
 * \seealso
 * \usedresources
 ***************************************************************************************************************
 */

LOCAL_INLINE BufReq_ReturnType Dcm_Prv_CheckValidEcuAddress(PduIdType DcmRxPduId, const PduInfoType* info)
{
    BufReq_ReturnType retVal_en = BUFREQ_OK;
    /* MR12 RULE 12.2 VIOLATION: Right hand operand of shift operator is greater than or equal to the width of the underlying type */
    uint16 receivedDcmDslProtocolEcuAddr_u16 = ((uint16)(info->MetaDataPtr[2]<<8u)|(info->MetaDataPtr[3]));

    /* MR12 RULE 13.5 VIOLATION: The right hand operand of '&&' or '||' has side effects - The statements inside needs to be executed only if all the conditions are satisfied */
    if((DcmRxPduId < DCM_CFG_INDEX_FUNC_RX_PDUID)&&(Dcm_Prv_GetProtocolRow(DcmRxPduId)->dcmDspProtocolEcuAddr_u16 != receivedDcmDslProtocolEcuAddr_u16))
    {
        /*Physical request with incorrect Target Address has been receievd*/
        retVal_en = BUFREQ_E_NOT_OK;
    }
    return retVal_en;
}

/**
 ****************************************************************************************************************
 * Dcm_Prv_ValidMetaDataReceived : API to check if valid MetaDataPtr is received for the corresponding Protocol Row.
 * \param           DcmRxPduId : Received RxPDUID
 *                  info       : Recieved RxPDUInfo Pointer
 *
 * \retval          BUFREQ_E_NOT_OK : Invalid MetaData recieved
 *                  BUFREQ_OK :  Valid MetaData recieved.
 * \seealso
 * \usedresources
 ***************************************************************************************************************
 */
LOCAL_INLINE BufReq_ReturnType Dcm_Prv_ValidMetaDataReceived(PduIdType DcmRxPduId, const PduInfoType* info)
{
    BufReq_ReturnType retVal_en = BUFREQ_OK;

    if(FALSE!=Dcm_Prv_IsDcmDslConnectionGeneric(DcmRxPduId))
    {
        /*Request received on a Generic Connection*/
        /* MR12 RULE 13.5 VIOLATION: The right hand operand of '&&' or '||' has side effects - The statements inside needs to be executed if any of the three conditions are satisfied in this exact order*/
        if((NULL_PTR==info)||(info->MetaDataPtr==NULL_PTR)||(BUFREQ_OK!=Dcm_Prv_CheckValidEcuAddress(DcmRxPduId,info)))
        {
            /*Invalid MetaDataPointer received*/
            retVal_en = BUFREQ_E_NOT_OK;
        }
    }

    return retVal_en;
}

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProvideFreeBuffer
 Syntax           : Dcm_Prv_ProvideFreeBuffer(idxProtocolIndex_u8,isQueuedReq_b)
 Description      : The function to provide the buffer when there is a new request.
                    This function provides the buffer as the index if it is a normal request.
                    If it is a queuing request, it will switch the index and provides the other buffer which is free,
                    So that the queuing of the request can happen in this buffer
 Parameter        : uint8,boolean
 Return value     : Dcm_MsgItemType
***********************************************************************************************************************/
Dcm_MsgItemType* Dcm_Prv_ProvideFreeBuffer(PduIdType DcmRxPduId,boolean isQueuedReq_b)
{
    uint8 * RxBuffer_pu8 = NULL_PTR;

    /* It is for the queued request switch the buffer */
    if(isQueuedReq_b == TRUE)
    {
        if(Dcm_QueueStructure_st.idxBufferIndex_u8 == 1)
        {
            Dcm_QueueStructure_st.idxBufferIndex_u8 = 2u;
        }
        else
        {
            Dcm_QueueStructure_st.idxBufferIndex_u8 = 1u;
        }
    }

    /* return the buffer based on the index */
    if(Dcm_QueueStructure_st.idxBufferIndex_u8 == 1u)
    {
        RxBuffer_pu8 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBuffer_u8;
    }
    else
    {
        RxBuffer_pu8 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->rx_reserveBuffer_pa;
    }

    return (RxBuffer_pu8);
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_isRxQueueFree
 Syntax           : Dcm_Prv_isRxQueueFree(ConnectionId,ReturnValue_en)
 Description      : This INLINE API is used to check whether DCM Queue is free to accept new request.
 Parameter        : PduIdType, BufReq_ReturnType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isRxQueueFree(
        PduIdType ConnectionId,
        BufReq_ReturnType ReturnValue_en)
{
    uint16 rxActiveConnId_u16=Dcm_Prv_GetMainConnection(Dcm_Prv_GetActiveRxPduId())->rxConnId_u16;
    Dcm_DslStatesType_ten getDslstate=Dcm_Dsl_Prv_GetDslState();
    return ((Dcm_QueueStructure_st.Dcm_QueHandling_en == DCM_QUEUE_IDLE) && \
            (ReturnValue_en != BUFREQ_E_OVFL)                            && \
            (rxActiveConnId_u16 == ConnectionId)          && \
            (getDslstate  != DSL_STATE_WAITFOR_RXINDICATION_E));
}
#endif


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ReceiveNewReqWhenOBDIdle
 Description      : The request details are stored in Global variables in this function for future use.
                    OBD StateMachine is updated to Request Receiving state to not allow other OBD requests.
 Parameter        : PduIdType, const PduInfoType*, PduLengthType, const uint8
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_ReceiveNewReqWhenOBDIdle(PduIdType DcmRxPduId,
        const PduInfoType* info,PduLengthType TpSduLength,const uint8 idxProtocol_u8)
{
    PduIdType connectionId_u8 = Dcm_Prv_GetConnectionIndex(DcmRxPduId);

    Dcm_Prv_SetOBDState((DCM_OBD_REQUESTRECEIVING));
    /* If the Protocol is not yet started update here
     * It will started in OBD StateMachine when the request is completely received */
    if(Dcm_OBDGlobal_st.idxCurrentProtocol_u8 != idxProtocol_u8)
    {
        Dcm_OBDGlobal_st.flgCommActive_b    = FALSE;
    }
    Dcm_OBDGlobal_st.idxCurrentProtocol_u8  = idxProtocol_u8;
    Dcm_OBDGlobal_st.dataActiveRxPduId_u8   = DcmRxPduId;
    Dcm_OBDGlobal_st.dataActiveTxPduId_u8   = Dcm_Prv_GetTxPduId(DcmRxPduId);
    Dcm_OBDGlobal_st.dataRequestLength_u16  = TpSduLength;
    Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b = TRUE;
    Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_RxPduId = DcmRxPduId;
    Dcm_Prv_ResetOBDCopyRxDataStatus(DcmRxPduId);
    Dcm_Prv_SetObdActiveRxPduId(DcmRxPduId,TpSduLength);
    Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength = TpSduLength;
    Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduDataPtr = Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBuffer_u8;

    /*Store SA and TA for transmission of the final response*/
    Dcm_Prv_SetSourceAndTargetAddress(DcmRxPduId,info);

#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
    (void)DcmAppl_StartOfReception(info->SduDataPtr[0],DcmRxPduId,TpSduLength,\
            (Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduDataPtr));
#else
    (void)info;
#endif
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessNewObdRequest
 Description      : The Received OBD request is further checked
                     - If OBD Specific State Machine is free, then allow reception of the request.
                     - If State Machine is Busy, then check whether NRC21 is needed and return accordingly.
 Parameter        : PduIdType, const PduInfoType*, PduLengthType, PduLengthType*
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/
static BufReq_ReturnType Dcm_Prv_ProcessNewObdRequest(PduIdType DcmRxPduId,
        const PduInfoType* info,PduLengthType TpSduLength,PduLengthType* RxBufferSizePtr)
{
    BufReq_ReturnType Result = BUFREQ_OK;
    uint8 idxProtocol_u8 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->protocolType;

    if(DCM_OBD_IDLE == Dcm_Prv_GetOBDState())
    {
        Dcm_Prv_ReceiveNewReqWhenOBDIdle(DcmRxPduId,info,TpSduLength,idxProtocol_u8);
    }
    else
    {

        Result = (FALSE != Dcm_Prv_GetProtocolRow(DcmRxPduId)->nrc21_b)?BUFREQ_OK:BUFREQ_E_NOT_OK;
        if(Result==BUFREQ_OK)
        {
            Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_RxPduId = DcmRxPduId;
            Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength = TpSduLength;
            Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduDataPtr = Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBuffer_u8;
            Dcm_Prv_SetLowPrioNrc21RxPduId(DcmRxPduId);
            /*Store SA and TA for transmission of NRC 21 response*/
            Dcm_Prv_SetSourceAndTargetAddress_NRC21(DcmRxPduId,info);
        }
    }

    if(BUFREQ_OK == Result)
    {
        *(RxBufferSizePtr) = TpSduLength;
    }
    /* For request on Shared Id , update Obd Request received Flag to TRUE */
    #if(DCM_CFG_RXPDU_SHARING_ENABLED != DCM_CFG_OFF)
        if( (Result == BUFREQ_OK) && (DcmRxPduId == (DCM_CFG_TOTAL_RX_PDUID-1u)))
        {
            Dcm_isObdRequestReceived_b = TRUE;
        }
    #endif
    return Result;
}

#endif  /* (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF) */

/***********************************************************************************************************************
 Function name    : Dcm_Prv_Set_CurrentRequestLength
 Syntax           : void Dcm_Prv_Set_CurrentRequestLength(PduInfoType currentrequestlength)
 Description      : This Function is used to set the TpsduLength

 Parameter        : PduIdType
 Return value     : void
 ***********************************************************************************************************************/

void Dcm_Prv_Set_CurrentRequestLength(PduLengthType currentrequestlength)
{
    RequestLength=currentrequestlength;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_Set_CurrentRequestLength
 Syntax           : PduIdType Dcm_Prv_GetLowPrioNrc21RxPduId(void)
 Description      : This Function is used to get the the TpsduLength

 Parameter        : void
 Return value     : PduInfoType
 ***********************************************************************************************************************/
PduLengthType Dcm_Prv_Get_CurrentRequestLength(void)
{
    return RequestLength;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetLowPrioNrc21RxPduId
 Syntax           : void Dcm_Prv_SetLowPrioNrc21RxPduId(PduIdType DcmRxPduId)
 Description      : This Function is used to set the RxpduId when a high prio is in progress and alow prio is received
                    When Nrc1 is TRUE
 Parameter        : PduIdType
 Return value     : void
 ***********************************************************************************************************************/

void Dcm_Prv_SetLowPrioNrc21RxPduId(PduIdType DcmRxPduId)
{
    LowPrioNrc21RxPduId=DcmRxPduId;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_GetLowPrioNrc21RxPduId
 Syntax           : PduIdType Dcm_Prv_GetLowPrioNrc21RxPduId(void)
 Description      : This Function is used to get the RxpduId when a high prio is in progress and alow prio is received
                    When Nrc1 is TRUE
 Parameter        : void
 Return value     : PduIdType
 ***********************************************************************************************************************/
PduIdType Dcm_Prv_GetLowPrioNrc21RxPduId(void)
{
    return LowPrioNrc21RxPduId;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ResetCopyRxDataStatus
 Syntax           : Dcm_Prv_ResetCopyRxDataStatus(Result)
 Description      : Function to reset CopyRxData status of all other dataRxPduId_u8 except that dataRxPduId_u8 which
                    has been passed as parameter
 Parameter        : PduIdType
 Return value     : None
***********************************************************************************************************************/
static void Dcm_Prv_ResetCopyRxDataStatus (PduIdType RxPduId)
{
    PduIdType idxRxPduid;

    for ( idxRxPduid = 0 ; idxRxPduid < DCM_CFG_TOTAL_RX_PDUID ; idxRxPduid++ )
    {
        /*Check if the CopyRxData status is set and dataRxPduId_u8 which has been not passed as parameter */
        if ((idxRxPduid != RxPduId) && (Dcm_ReceptionInfo_ast[idxRxPduid].Dcm_RequestProcessingFlag_b != FALSE))
        {
            Dcm_ReceptionInfo_ast[idxRxPduid].Dcm_RequestProcessingFlag_b = FALSE;
        }
    }
}

#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)

/***********************************************************************************************************************
 Function name    : Dcm_Prv_CancelLowPrioRequestReception
 Syntax           : void Dcm_Prv_CancelLowPrioRequestReception(PduIdType LowPrioPduId)
 Description      : Function to Cancel low priority request reception.
 Parameter        : PduIdType
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_CancelLowPrioRequestReception(PduIdType LowPrioPduId)
{
    Std_ReturnType CancelReceptionStatus = E_NOT_OK;

    CancelReceptionStatus = PduR_DcmCancelReceive(LowPrioPduId);

    if(E_NOT_OK == CancelReceptionStatus)
    {
        /* When lower layer could not cancel low priority request reception, set the flag so that Dcm can reject
         * low priority protocol request */
        Dcm_LowPrioReject_b = TRUE;
    }
    else
    {
        /* Low priority protocol reception cancelled successfully by lower layer. So no need for Dcm to reject low
         * priority protocol as lower layer will call Dcm_TpRxIndication with parameter result set to E_NOT_OK. */
        Dcm_LowPrioReject_b = FALSE;
        Dcm_ReceptionInfo_ast[LowPrioPduId].Dcm_RxPduId = DCM_CFG_INVALID_RX_PDUID;
    }

}

/***********************************************************************************************************************
 Function name    : Dcm_CheckPriority
 Syntax           : BufReq_ReturnType Dcm_CheckPriority  (PduIdType DcmRxPduId,PduLengthType TpSduLength)
 Description      : This Function is used to check the protocol prio when new request come
 Parameter        : PduIdType,PduInfoType
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/

static BufReq_ReturnType Dcm_CheckPriority  (PduIdType DcmRxPduId,PduLengthType TpSduLength)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
    PduIdType highPrioPduId;
    boolean checkNRC21_b = FALSE;
    highPrioPduId=Dcm_Prv_GetHighPrioPduid();

    if((DCM_CFG_INVALID_RX_PDUID)==highPrioPduId)
    {
        /*Check if the priority of arrived request protocol is higher than the running protocol*/
        if(Dcm_Prv_GetProtocolRow(DcmRxPduId)->priority_u8 < Dcm_Prv_GetActiveProtocolPriority())
        {
            Dcm_PduInfo_ast[DcmRxPduId].SduLength=TpSduLength;
            Dcm_Prv_Set_CurrentRequestLength(TpSduLength);
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8 = Dcm_Prv_ProvideFreeBuffer(DcmRxPduId,FALSE);
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr = Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8;
#else
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr=Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBuffer_u8;
#endif
            if(Dcm_Dsl_Prv_GetDslState() == DSL_STATE_WAITFOR_RXINDICATION_E)
            {
                /* Prepare to cancel the ongoing low priorty request reception,
                 * when a high priority request is arrived */
                Dcm_Prv_CancelLowPrioRequestReception(Dcm_Prv_GetActiveRxPduId());
            }
            Dcm_Prv_SetHighPrioPduid(DcmRxPduId);
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId=DcmRxPduId;
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b=TRUE;
            Dcm_Dsl_Prv_SetPreemptionState(DSL_PREEMPTION_HIGHPRIORITY_REQUESTRECEIVED_E);
            Dcm_Prv_ResetCopyRxDataStatus(DcmRxPduId);
            bufRequestStatus_en = BUFREQ_OK;
        }
        else
        {
            checkNRC21_b = TRUE;
        }
    }
    else
    {
        /*Check if the priority of arrived request protocol is higher than the previous high priority,
         * then store the high prio protocol*/
        if(Dcm_Prv_GetProtocolRow(DcmRxPduId)->priority_u8 <Dcm_Prv_GetActiveProtocolPriority())
        {

            Dcm_PduInfo_ast[DcmRxPduId].SduLength=TpSduLength;
            Dcm_Prv_Set_CurrentRequestLength(TpSduLength);
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8 = Dcm_Prv_ProvideFreeBuffer(DcmRxPduId,FALSE);
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr = Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8;
#else
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr=Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBuffer_u8;
#endif
            if(Dcm_Dsl_Prv_GetPreemptionState() == DSL_PREEMPTION_HIGHPRIORITY_REQUESTRECEIVED_E)
            {
                /* Prepare to cancel the ongoing low priorty request reception,
                 * when a high priority request is arrived */
                Dcm_Prv_CancelLowPrioRequestReception(Dcm_Prv_GetHighPrioPduid());
            }
            Dcm_Prv_SetHighPrioPduid(DcmRxPduId);
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId=DcmRxPduId;
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b=TRUE;
            Dcm_Dsl_Prv_SetPreemptionState(DSL_PREEMPTION_HIGHPRIORITY_REQUESTRECEIVED_E);
            Dcm_Prv_ResetCopyRxDataStatus(DcmRxPduId);
            bufRequestStatus_en = BUFREQ_OK;
        }
        else
        {
            checkNRC21_b = TRUE;
        }
    }
    if ((TRUE == Dcm_Prv_GetRespOnSecondDeclinedRequest(DcmRxPduId)) && (checkNRC21_b))
    {
        Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId=DcmRxPduId;
        Dcm_Prv_SetLowPrioNrc21RxPduId(DcmRxPduId);
        bufRequestStatus_en = BUFREQ_OK;
    }
    return bufRequestStatus_en;
}
#endif

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isDcmProcessingRoeEvent
 Syntax           : Dcm_Prv_isDcmProcessingRoeEvent  (PduIdType DcmRxPduId)
 Description      : This function is check whether DCM is handling any RoE event
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/
static boolean Dcm_Prv_isDcmProcessingRoeEvent(PduIdType DcmRxPduId)
{

#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_ON)
    const Dcm_DslProtocolRowConfigType_tst* CurrentProtocolRow = Dcm_Prv_GetProtocolRow(DcmRxPduId);
#endif
    boolean isRoeEventOn_b = FALSE;

    if(DSL_STATE_ROETYPE1_RECEIVED_E == Dcm_Dsl_Prv_GetDslState())
    {
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_ON)
        if(CurrentProtocolRow->priority_u8 == Dcm_Prv_GetActiveProtocolPriority())
#else
        if(Dcm_Prv_GetConnectionIndex(DcmRxPduId) == Dcm_Prv_GetActiveConnectionIndex())
#endif
        {
            isRoeEventOn_b = TRUE;
        }
    }

    return isRoeEventOn_b;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessRequestWhileRoeEvent
 Syntax           : Dcm_Prv_ProcessRequestWhileRoeEvent(DcmRxPduId,TpSduLength)
 Description      : This API is used to process the new request received in API Dcm_StartOfReception while
                    DCM is busy processing an RoE event.
 Parameter        : PduIdType,PduLengthType
 Return value     : BufReq_ReturnType
***********************************************************************************************************************/
static BufReq_ReturnType Dcm_Prv_ProcessRequestWhileRoeEvent(PduIdType DcmRxPduId,PduLengthType TpSduLength)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
    const Dcm_DslProtocolRowConfigType_tst* CurrentProtocolRow = Dcm_Prv_GetProtocolRow(DcmRxPduId);

#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_ON)
    if(CurrentProtocolRow->priority_u8 == Dcm_Prv_GetActiveProtocolPriority())
    {
        boolean nrc21Flag_b;
        /* Check for high priority request on persistent ROE*/
        bufRequestStatus_en = Dcm_DsldPersistentRoeHandling_en(TpSduLength,DcmRxPduId);
        nrc21Flag_b = Dcm_Prv_GetRespOnSecondDeclinedRequest(DcmRxPduId);

        if ((BUFREQ_E_NOT_OK == bufRequestStatus_en) && (TRUE == nrc21Flag_b))
        {
            bufRequestStatus_en = BUFREQ_OK;
        }
    }
#else
    if(Dcm_Prv_GetConnectionIndex(DcmRxPduId) == Dcm_Prv_GetActiveConnectionIndex())
    {
        /* ROE type1 request under processing and tester request comes. Reset S3 timer */
        Dcm_Prv_ReloadS3Timer();

        bufRequestStatus_en = (TRUE == Dcm_Prv_GetRespOnSecondDeclinedRequest(DcmRxPduId)) ? BUFREQ_OK : BUFREQ_E_NOT_OK;
    }
#endif

    return bufRequestStatus_en;
}
#endif

/***********************************************************************************************************************
 Function name    : Dcm_ProcessRequestWhileDslBusy
 Syntax           : BufReq_ReturnType Dcm_ProcessRequestWhileDslBusy(PduIdType DcmRxPduId)
 Description      : This API is used to process the new request received in API Dcm_StartOfReception while
                    Dcm is busy to processing with previous request.
 Parameter        : PduIdType
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/

static BufReq_ReturnType Dcm_ProcessRequestWhileDslBusy(PduIdType DcmRxPduId,PduLengthType TpSduLength)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    if(TRUE == Dcm_Prv_isDcmProcessingRoeEvent(DcmRxPduId))
    {
        bufRequestStatus_en = Dcm_Prv_ProcessRequestWhileRoeEvent(DcmRxPduId,TpSduLength);
        if((bufRequestStatus_en == BUFREQ_OK)&&(Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b))
        {
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8 = Dcm_Prv_ProvideFreeBuffer(DcmRxPduId,FALSE);
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr = Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8;
#else
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr=Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBuffer_u8;
#endif
        }
    }
    else
#endif
    {
        if(Dcm_Prv_GetConnectionIndex(DcmRxPduId)!=Dcm_Prv_GetActiveConnectionIndex())
        {
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
            bufRequestStatus_en=Dcm_CheckPriority(DcmRxPduId,TpSduLength);
#else
            (void)TpSduLength;
            if(TRUE == Dcm_Prv_GetRespOnSecondDeclinedRequest(DcmRxPduId))
            {
                bufRequestStatus_en = BUFREQ_OK;
            }
#endif
        }
        else
        {
            bufRequestStatus_en = BUFREQ_E_NOT_OK;
        }
    }
    return bufRequestStatus_en;
}

/***********************************************************************************************************************
 Function name    : Dcm_CheckFunctionalTesterPresent
 Syntax           : static boolean Dcm_CheckFunctionalTesterPresent(
                    PduIdType DcmRxPduId,
                    const PduInfoType* info,
                    PduLengthType TpSduLength)
 Description      : This API is used to check whether the received request is Functional Tester Present
 Parameter        : PduIdType, const PduInfoType*,PduLengthType
 Return value     : boolean
 ***********************************************************************************************************************/
static boolean Dcm_CheckFunctionalTesterPresent(
        PduIdType DcmRxPduId,
        const PduInfoType* info,
        PduLengthType TpSduLength)
{
    boolean isFuncTesterPresent_b=FALSE;
    if(NULL_PTR!=info)
    {
        if((DcmRxPduId >= DCM_CFG_INDEX_FUNC_RX_PDUID)&&
                (TpSduLength == DCM_DSLD_PARALLEL_DCM_TPR_REQ_LENGTH)&&
                (info->SduDataPtr[0] == DCM_DSLD_PARALLEL_TPR_BYTE1)&&
                (info->SduDataPtr[1] == DCM_DSLD_PARALLEL_TPR_BYTE2)
        )
        {
            isFuncTesterPresent_b=TRUE;
            Dcm_Prv_SetFunctionalTPStatusFlag(DcmRxPduId,isFuncTesterPresent_b);
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId=DcmRxPduId;
            Dcm_PduInfo_ast[DcmRxPduId].SduLength=TpSduLength;
        }
    }
    return  isFuncTesterPresent_b;
}

/***********************************************************************************************************************
 Function name    : Dcm_ProcessStartOfReception
 Syntax           :  BufReq_ReturnType Dcm_ProcessStartOfReception (
                     PduIdType DcmRxPduId,
                     const PduInfoType* info,
                     PduLengthType TpSduLength)
 Description      : The Acutal functionalites will start from this function
 Parameter        : PduIdType, const PduInfoType*,PduLengthType
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/
static BufReq_ReturnType Dcm_ProcessStartOfReception (
        PduIdType DcmRxPduId,
        const PduInfoType* info,
        PduLengthType TpSduLength
)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
    if(FALSE==Dcm_CheckFunctionalTesterPresent(DcmRxPduId,info,TpSduLength))
    {
        /*Check if (Request received on different connection when Dcm is in non-default session)
         *  OR (Dcm is Busy Processing a Request)*/
        PduIdType activeIndex= Dcm_Prv_GetActiveConnectionIndex();
        PduIdType currentIndex=Dcm_Prv_GetConnectionIndex(DcmRxPduId);
        Dcm_DslStatesType_ten dcm_DslState=Dcm_Dsl_Prv_GetDslState();
        if(((Dcm_Prv_GetActiveSessionIdx()!=DCM_DEFAULT_SESSION_IDX)&&
                (currentIndex !=activeIndex))||
                (dcm_DslState!=DSL_STATE_IDLE_E))
        {
            bufRequestStatus_en= Dcm_ProcessRequestWhileDslBusy(DcmRxPduId,TpSduLength);
            if(BUFREQ_OK==bufRequestStatus_en)
            {
                if((DSL_PREEMPTION_HIGHPRIORITY_REQUESTRECEIVED_E==Dcm_Dsl_Prv_GetPreemptionState()))
                {
                    /*Store SA and TA for transmission of Final response*/
                    Dcm_Prv_SetSourceAndTargetAddress(DcmRxPduId,info);
                }
                else
                {
                    /*Store SA and TA for transmission of NRC 21 response*/
                    Dcm_Prv_SetSourceAndTargetAddress_NRC21(DcmRxPduId,info);
                }
            }

        }
        else
        {
            if(Dcm_Prv_GetCurrentProtocol()!=DCM_NO_ACTIVE_PROTOCOL)
            {
                if(Dcm_Prv_GetActiveProtocolType() != Dcm_Prv_GetProtocolRow(DcmRxPduId)->protocolType)
                {
                    Dcm_Prv_SetProtocolStatus(FALSE);
                }
            }
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b=TRUE;
            Dcm_Prv_SetActiveRxPduId(DcmRxPduId,TpSduLength);
            Dcm_PduInfo_ast[DcmRxPduId].SduLength=TpSduLength;
            Dcm_Prv_Set_CurrentRequestLength(TpSduLength);
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8 = Dcm_Prv_ProvideFreeBuffer(DcmRxPduId,FALSE);
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr = Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_DslBufferPtr_pu8;
#else
            Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr=Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBuffer_u8;
#endif
            Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId=DcmRxPduId;
            Dcm_Dsl_Prv_SetDslState((DSL_STATE_WAITFOR_RXINDICATION_E));
            Dcm_Prv_ResetCopyRxDataStatus(DcmRxPduId);
            /*Store SA and TA for transmission of the final response*/
            Dcm_Prv_SetSourceAndTargetAddress(DcmRxPduId,info);
            bufRequestStatus_en=BUFREQ_OK;
        }
    }
    else
    {
        bufRequestStatus_en=BUFREQ_OK;
    }
    return bufRequestStatus_en;
}

#if(DCM_CFG_RXPDU_SHARING_ENABLED == DCM_CFG_ON)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessSharedRxPduid
 Syntax           : Dcm_Prv_ProcessSharedRxPduid(&RxPduId,&info)
 Description      : This API is used to Check if RxPduid passed in API Dcm_StartOfReception is shared Pduid
                    between protocol UDS and OBD.
 Parameter        : PduIdType*, const PduInfoType*
 Return value     : boolean
***********************************************************************************************************************/
static boolean Dcm_Prv_ProcessSharedRxPduid(PduIdType* DcmRxPduId, const PduInfoType * infoPtr)
{
    boolean processStatus_b  = TRUE;
    const Dcm_DslProtocolRowConfigType_tst* ActiveProtocolRow = Dcm_Prv_GetProtocolRow(DCM_CFG_TOTAL_RX_PDUID-1u);
    Dcm_ProtocolType ProtocolType = ActiveProtocolRow->protocolType;

    if(TRUE == Dcm_Prv_isRxPduShared(*DcmRxPduId,infoPtr->SduDataPtr[0]))
    {
        if((DCM_OBD_ON_CAN == ProtocolType) || (DCM_OBD_ON_FLEXRAY == ProtocolType))
        {
            *DcmRxPduId = (DCM_CFG_TOTAL_RX_PDUID-1u);
        }
        else
        {
            processStatus_b = FALSE;
        }
    }
    return processStatus_b;
}
#endif

/***********************************************************************************************************************
 Function name    : Dcm_CheckDependancies
 Syntax           : BufReq_ReturnType Dcm_CheckDependancies (
                    PduIdType DcmRxPduId,
                    const PduInfoType* infoPtr,
                    PduLengthType* RxBufferSizePtr)
 Description      :
 Parameter        : PduIdType,const PduInfoType*, PduLengthType*
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/

static BufReq_ReturnType Dcm_CheckDependancies (
        /* MR12 RULE 8.13 VIOLATION: cast may discard const qualifier. So used as non constant pointer*/
        PduIdType * DcmRxPduIdPtr,
        const PduInfoType* infoPtr,
        PduLengthType TpSduLength
)
{
    BufReq_ReturnType CheckDepencyStatus=BUFREQ_E_NOT_OK;
    const Dcm_DslProtocolRowConfigType_tst *protocolRowPtr;
    const Dcm_DslMainConnConfigType_tst *mainConnectionPtr;

#if(DCM_CFG_RXPDU_SHARING_ENABLED != DCM_CFG_OFF)
    if(TRUE == Dcm_Prv_ProcessSharedRxPduid(DcmRxPduIdPtr,infoPtr))
#endif
    {
        mainConnectionPtr = Dcm_Prv_GetMainConnection(*DcmRxPduIdPtr);
        if(DCM_CHKNOCOMM_MODE(mainConnectionPtr->channel_idx_u8))
        {
            protocolRowPtr  = Dcm_Prv_GetProtocolRow(*DcmRxPduIdPtr);
            if(E_OK == DcmAppl_DcmGetRxPermission(protocolRowPtr->protocolType,*DcmRxPduIdPtr,infoPtr,TpSduLength))
            {
                CheckDepencyStatus = BUFREQ_OK;
            }
        }
    }

    return CheckDepencyStatus;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_isDcmInitalisedAcceptRequest
 Syntax           : Dcm_Prv_isDcmInitalisedAcceptRequest(void)
 Description      : This INLINE API is used to check whether DCM is initilaise or not and ready to accept new request.
 Parameter        : None
 Return value     : boolean
 ***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isDcmInitalisedAcceptRequest(void)
{
    return ((Dcm_Prv_IsDcmInitialized() != FALSE) && (Dcm_acceptRequests_b != FALSE));
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_CheckEnvironment
 Syntax           : BufReq_ReturnType Dcm_Prv_CheckEnvironment (
                    PduIdType DcmRxPduId,
                    const PduInfoType* infoPtr,
                    PduLengthType* RxBufferSizePtr)
 Description      : This Function is used to validate all parameter passed to API Dcm_StartOfReception from Lower layer
 Parameter        : PduIdType,const PduInfoType*, PduLengthType*
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/
static BufReq_ReturnType Dcm_Prv_CheckEnvironment (
        PduIdType DcmRxPduId,const PduInfoType* info,
        const PduLengthType* RxBufferSizePtr
)
{
    BufReq_ReturnType bufRequestStatus = BUFREQ_E_NOT_OK;
    if(FALSE == Dcm_Prv_isDcmInitalisedAcceptRequest())
    {
        if(FALSE == Dcm_Prv_IsDcmInitialized())
        {
            Dcm_Prv_Det(DCM_STARTOFRECEPTION_ID,DCM_E_UNINIT);
        }
    }
    else if(DCM_CFG_TOTAL_RX_PDUID <= DcmRxPduId)
    {
        Dcm_Prv_Det(DCM_STARTOFRECEPTION_ID,DCM_E_PARAM);
    }
#if((DCM_CFG_RXPDU_SHARING_ENABLED != DCM_CFG_OFF) || (DCM_CALLAPPLICATIONONREQRX_ENABLED != DCM_CFG_OFF))
    else if (NULL_PTR==info)
    {
        Dcm_Prv_Det(DCM_STARTOFRECEPTION_ID,DCM_E_PARAM_POINTER);
    }
#endif
    else if(NULL_PTR==RxBufferSizePtr)
    {
        Dcm_Prv_Det(DCM_STARTOFRECEPTION_ID,DCM_E_PARAM_POINTER);
    }
    else if(BUFREQ_OK!= Dcm_Prv_ValidMetaDataReceived(DcmRxPduId,info))
    {
        Dcm_Prv_Det(DCM_STARTOFRECEPTION_ID,DCM_E_PARAM_POINTER);
    }
    else
    {
        bufRequestStatus = BUFREQ_OK;
    }
#if((DCM_CFG_RXPDU_SHARING_ENABLED == DCM_CFG_OFF) && (DCM_CALLAPPLICATIONONREQRX_ENABLED == DCM_CFG_OFF))
    (void)info;
#endif
    return bufRequestStatus;
}

/***********************************************************************************************************************
 Function name    : Dcm_StartOfReception
 Syntax           : BufReq_ReturnType Dcm_StartOfReception (
                    PduIdType id,
                    const PduInfoType* info,
                    PduLengthType TpSduLength,
                    PduLengthType* bufferSizePtr)
 Description      : This call-back function is invoked by medium specific TP (CanTp/FrTp)
                    via PduR to inform the start of reception (i.e. receiving a Single Frame or First Frame indication)
 Parameter        : PduIdType,const PduInfoType*,RetryInfoType*,PduLengthType*
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/

BufReq_ReturnType Dcm_StartOfReception (
        PduIdType id,
        const PduInfoType* info,
        PduLengthType TpSduLength,
        PduLengthType* bufferSizePtr
)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
    uint32 bufferSize_u32;
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    PduIdType connectionId;
#endif

    /* check all prameters are valid */
    if (BUFREQ_OK== Dcm_Prv_CheckEnvironment(id,info,bufferSizePtr))
    {
        if (BUFREQ_OK== Dcm_CheckDependancies(&id,info,TpSduLength))
        {
            bufferSize_u32 = Dcm_Prv_GetRxBufferMaxLen(id);
            if(TpSduLength==0x00u)
            {
                *(bufferSizePtr) = (PduLengthType) (bufferSize_u32);
                bufRequestStatus_en=BUFREQ_OK;
            }
            else if(TpSduLength>bufferSize_u32)
            {
                bufRequestStatus_en=BUFREQ_E_OVFL;
            }
            else
            {
                /* BSWEXT-533 */
                SchM_Enter_Dcm_Global();
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
                // For a request on OBD protocol, handle it separately in parallel to other protocol requests.
                if(Dcm_Prv_IsRxPduIdOBD(id))
                {
                    bufRequestStatus_en = Dcm_Prv_ProcessNewObdRequest(id,info,TpSduLength,bufferSizePtr);
                }
                else
#endif
                {
                    if(Dcm_ProcessStartOfReception(id,info,TpSduLength)==BUFREQ_OK)
                    {
                        *(bufferSizePtr) = TpSduLength;
                        bufRequestStatus_en=BUFREQ_OK;
#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
                        if(Dcm_ReceptionInfo_ast[id].Dcm_RequestProcessingFlag_b)
                        {
                            (void)DcmAppl_StartOfReception(info->SduDataPtr[0],id,TpSduLength,Dcm_PduInfo_ast[id].SduDataPtr);
                        }
#endif
#if(DCM_CFG_RXPDU_SHARING_ENABLED != DCM_CFG_OFF)
                       if(id == (DCM_CFG_TOTAL_RX_PDUID-1u))
                       {
                           Dcm_isObdRequestReceived_b = TRUE;
                       }
#endif
                    }
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
                    else
                    {
                        connectionId =(uint16)(Dcm_Prv_GetMainConnection(id)->rxConnId_u16);
                        if(FALSE != Dcm_Prv_isRxQueueFree(connectionId,bufRequestStatus_en))
                        {


                            /* copy the buffer address into the queue buffer pointer */
                            Dcm_QueueStructure_st.adrBufferPtr_pu8 = Dcm_Prv_ProvideFreeBuffer(id,TRUE);
                            Dcm_PduInfo_ast[id].SduDataPtr = Dcm_QueueStructure_st.adrBufferPtr_pu8;
                            Dcm_PduInfo_ast[id].SduLength  = TpSduLength;
                            Dcm_ReceptionInfo_ast[id].Dcm_RequestProcessingFlag_b = TRUE;

                            /* Application should not be called for copying the data while being queuing the request */
                            Dcm_QueueStructure_st.dataQueueReqLength_u16 = TpSduLength;
                            Dcm_QueueStructure_st.dataQueueRxPduId_u8    = id;

                            *(bufferSizePtr) = TpSduLength;

                            /* set the flag to indicate that the first buffer is busy */
                            /* To indicate that the Queueing of the next request on the same connection has started on buffer 0*/
                            Dcm_QueueStructure_st.Dcm_QueHandling_en = DCM_QUEUE_RUNNING;
                            bufRequestStatus_en = BUFREQ_OK;


                        }
                    }
#endif

                }
                /* BSWEXT-533 */
                SchM_Exit_Dcm_Global();
            }
        }
    }
    return (bufRequestStatus_en);
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
