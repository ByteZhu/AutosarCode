#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/***********************************************************************************************************************
 Function name    : Dcm_Prv_isLowPriorityRequestReceived
 Syntax           : Dcm_Prv_isLowPriorityRequestReceived(DcmRxPduId)
 Description      : This Inline Function is used to check whether Low priority request has arrived
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isLowPriorityRequestReceived(PduIdType DcmRxPduId)
{
    boolean lowpriostatus_b=FALSE;
    uint8 activeprotocolpriority;
    boolean ChkFullComMode_b;
    uint8 priority_u8;

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(Dcm_Prv_IsRxPduIdOBD(Dcm_Prv_GetObdActiveRxPduId()))
    {
        activeprotocolpriority = Dcm_Prv_GetObdActiveProtocolPriority();
    }
    else
#endif
    {
        activeprotocolpriority = Dcm_Prv_GetActiveProtocolPriority();
    }
    ChkFullComMode_b = DCM_CHKFULLCOMM_MODE(Dcm_Prv_GetMainConnection(DcmRxPduId)->channel_idx_u8);
    priority_u8 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->priority_u8;
    if((priority_u8 >= activeprotocolpriority) && (ChkFullComMode_b))
    {
        lowpriostatus_b=TRUE;
    }

    return lowpriostatus_b;
}


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProvideOBDRxBufferSize
 Description      : This API is used to provide available buffer size for an OBD protocol
 Parameter        : PduIdType,PduLengthType*
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_ProvideOBDRxBufferSize(PduIdType DcmRxPduId,PduLengthType* RxBufferSizePtr)
{
    if (FALSE !=  Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b)
    {
        /* Dcm needs to update to the underlying TP on the no. of remaining bytes left */
        *(RxBufferSizePtr) = Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength;
    }
    else
    {
        /* Simulating reception without copying, thus update to TP that Buffer is available for any length.
          The available Rx buffer is updated in this case. */
        *(RxBufferSizePtr) = Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBufferSize_u32;
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_CopyOBDDataToRxBuffer
 Description      : This API is used to copy the received data into OBD buffer
 Parameter        : PduIdType,const PduInfoType*, PduLengthType*
 Return value     : void
 ***********************************************************************************************************************/
static void Dcm_Prv_CopyOBDDataToRxBuffer(PduIdType DcmRxPduId, const PduInfoType* PduInfoPtr,
        PduLengthType* RxBufferSizePtr)
{
    /* MR12 DIR 1.1 VIOLATION: This is required for implementation as DCM_MEMCOPY takes void pointer as input
     * and object type pointer is converted to void pointer */
    DCM_MEMCOPY(Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduDataPtr,PduInfoPtr->SduDataPtr,
            PduInfoPtr->SduLength);
    Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduDataPtr += PduInfoPtr->SduLength;
    Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength  -= PduInfoPtr->SduLength;

#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
    (void)DcmAppl_CopyRxData(DcmRxPduId,PduInfoPtr->SduLength);
#endif
    *(RxBufferSizePtr) = Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength;
}

/***********************************************************************************************************************
 Function name  : Dcm_Prv_CheckOBDRxData
 Description    : Based on RxPduId, the request is segregated to:
                     - Normal CopyRxData - here, store the the Rx data into Dcm buffer
                     - NRC 21 request, simulate pseudo reception
                     - else reject the request
 Parameter      : PduIdType, const PduInfoType*, const PduLengthType*
 Return value   : BufReq_ReturnType
 ***********************************************************************************************************************/
static BufReq_ReturnType Dcm_Prv_CheckOBDRxData(PduIdType DcmRxPduId, const PduInfoType* PduInfoPtr,
        PduLengthType* RxBufferSizePtr)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;

    if (FALSE != Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b)
    {
        Dcm_Prv_CopyOBDDataToRxBuffer(DcmRxPduId,PduInfoPtr,RxBufferSizePtr);
        bufRequestStatus_en = BUFREQ_OK;
    }
    else
    {
        if(FALSE != Dcm_Prv_isLowPriorityRequestReceived(DcmRxPduId))
        {
            /* Save ServiceId For NRC21 Handling In TpTxConfirmation */
            if (Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslServiceId_u8 == DCM_SERVICEID_DEFAULT_VALUE)
            {
                Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslServiceId_u8 = (uint8)PduInfoPtr->SduDataPtr[0];
            }
            bufRequestStatus_en = BUFREQ_OK;
        }
    }
    return bufRequestStatus_en;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDCopyRxData
 Description      : This API is used to process CopyRx Data for an OBD request reception
 Parameter        : PduIdType,const PduInfoType*,PduLengthType*
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/
static BufReq_ReturnType Dcm_Prv_OBDCopyRxData(PduIdType DcmRxPduId,
        const PduInfoType* PduInfoPtr, PduLengthType* RxBufferSizePtr)
{
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
    if(PduInfoPtr->SduLength == 0u)
    {
        Dcm_Prv_ProvideOBDRxBufferSize(DcmRxPduId,RxBufferSizePtr);
        Result = BUFREQ_OK;
    }
    else
    {
        boolean ChkLowPrioRequest_b = Dcm_Prv_isLowPriorityRequestReceived(DcmRxPduId);
        if((PduInfoPtr->SduLength <= Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength) ||
                (ChkLowPrioRequest_b))
        {
            Result = Dcm_Prv_CheckOBDRxData(DcmRxPduId,PduInfoPtr,RxBufferSizePtr);
        }
        else
        {
            Dcm_Prv_Det(DCM_COPYRXDATA_ID , DCM_E_INTERFACE_BUFFER_OVERFLOW);
        }
    }
    return Result;
}

#endif /*  (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF) */


/***********************************************************************************************************************
 Function name    : Dcm_Prv_CopyRxData_CheckEnvironment
 Syntax           : Dcm_Prv_CopyRxData_CheckEnvironment(DcmRxPduId,&PduInfoPtr,&RxBufferSizePtr)
 Description      : This API is used to validate all parameters passed to Dcm_CopyRxData
 Parameter        : PduIdType,const PduInfoType*, const PduLengthType*
 Return value     : boolean
 ***********************************************************************************************************************/
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3636] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3638] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3639] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3736] */

static BufReq_ReturnType Dcm_CheckEnvironment(PduIdType DcmRxPduId,
        const PduInfoType * PduInfoPtr,
        const PduLengthType * RxBufferSizePtr)
{
    PduIdType RxPduid;
    PduLengthType sdulength_temp;
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    boolean context = DCM_UDSCONTEXT;
#endif
    BufReq_ReturnType copyRxEnvStatus = BUFREQ_E_NOT_OK;
    boolean requestProcessingFlag_b;

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    context = (Dcm_Prv_IsRxPduIdOBD(DcmRxPduId)?DCM_OBDCONTEXT:DCM_UDSCONTEXT);

    if(context==DCM_OBDCONTEXT)
    {
        if(DCM_CFG_TOTAL_RX_PDUID > DcmRxPduId)
        {
            sdulength_temp=Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength;
            RxPduid = Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_RxPduId;
            requestProcessingFlag_b= Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b;
        }
    }
    else
#endif
    {
        if(DCM_CFG_TOTAL_RX_PDUID > DcmRxPduId)
        {
            sdulength_temp=Dcm_PduInfo_ast[DcmRxPduId].SduLength;
            RxPduid = Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RxPduId;
            requestProcessingFlag_b=Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b;
        }
    }
    if((DCM_CFG_TOTAL_RX_PDUID <= DcmRxPduId)|| (DcmRxPduId!=RxPduid))
    {
        Dcm_Prv_Det(DCM_COPYRXDATA_ID,DCM_E_PARAM);
    }
    else if  (((PduInfoPtr == NULL_PTR) || (RxBufferSizePtr == NULL_PTR))||
            ((PduInfoPtr->SduLength != 0u) && (PduInfoPtr->SduDataPtr == NULL_PTR)))
    {
        Dcm_Prv_Det(DCM_COPYRXDATA_ID , DCM_E_PARAM_POINTER);
    }
    else if((PduInfoPtr->SduLength >sdulength_temp ) &&(requestProcessingFlag_b==TRUE))
    {
        Dcm_Prv_Det(DCM_COPYRXDATA_ID , DCM_E_INTERFACE_BUFFER_OVERFLOW);
    }
    else
    {
        copyRxEnvStatus=BUFREQ_OK;
    }
    return copyRxEnvStatus;
}
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProvideRxBufferSize
 Syntax           : Dcm_Prv_ProvideRxBufferSize(DcmRxPduId,PduLengthType * RxBufferSizePtr)
 Description      : This API is used to validate all parameters passed to Dcm_CopyRxData
 Parameter        : PduIdType,const PduInfoType*, const PduLengthType*
 Return value     : boolean
 ***********************************************************************************************************************/
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3187] */

static void Dcm_ProvideRxBufferSize(PduIdType DcmRxPduId,
        PduLengthType * RxBufferSizePtr)
{
    if(TRUE==Dcm_Prv_GetRequestProcessingFlag(DcmRxPduId))
    {
        *(RxBufferSizePtr) = Dcm_PduInfo_ast[DcmRxPduId].SduLength;
    }
    else
    {
        *(RxBufferSizePtr) = (PduLengthType) (Dcm_Prv_GetProtocolRow(DcmRxPduId)->rxBufferSize_u32);
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessCopyRxData
 Syntax           : Dcm_Prv_ProvideRxBufferSize(DcmRxPduId,const PduInfoType * PduInfoPtr,
                    PduLengthType * RxBufferSizePtr)
 Description      : This API is used to validate all parameters passed to Dcm_CopyRxData
 Parameter        : PduIdType,const PduInfoType*, const PduLengthType*
 Return value     : boolean
 ***********************************************************************************************************************/
static BufReq_ReturnType Dcm_Prv_ProcessCopyRxData(PduIdType DcmRxPduId,
        const PduInfoType * PduInfoPtr,
        PduLengthType * RxBufferSizePtr)
{
    BufReq_ReturnType bufRequestStatus = BUFREQ_E_NOT_OK;

    if(TRUE==Dcm_Prv_GetRequestProcessingFlag(DcmRxPduId))
    {
        /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as input and object
         * type pointer is converted to void pointer*/
        DCM_MEMCOPY(Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr,PduInfoPtr->SduDataPtr,
                PduInfoPtr->SduLength);
        Dcm_PduInfo_ast[DcmRxPduId].SduDataPtr += PduInfoPtr->SduLength;
        Dcm_PduInfo_ast[DcmRxPduId].SduLength  -= PduInfoPtr->SduLength;

#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
#if(DCM_BUFQUEUE_ENABLED !=DCM_CFG_OFF)
        if(Dcm_QueueStructure_st.Dcm_QueHandling_en == DCM_QUEUE_IDLE)
#endif
        {
            (void)DcmAppl_CopyRxData(DcmRxPduId,PduInfoPtr->SduLength);
        }
#endif

        *(RxBufferSizePtr) = Dcm_PduInfo_ast[DcmRxPduId].SduLength ;
        bufRequestStatus = BUFREQ_OK;
    }
    else
    {
        if((TRUE==Dcm_Prv_isLowPriorityRequestReceived(DcmRxPduId)) && (FALSE == Dcm_LowPrioReject_b))
        {
            Dcm_Prv_SetServiceId(PduInfoPtr->SduDataPtr[0],DcmRxPduId);
            bufRequestStatus = BUFREQ_OK;
        }
        /* Low prio request reception is in progress and a new high prio request arrived*/
        if(TRUE == Dcm_LowPrioReject_b)
        {
            /* To reject the on going low prio request silently */
            bufRequestStatus = BUFREQ_E_NOT_OK;
            /* Reset the flag */
            Dcm_LowPrioReject_b = FALSE;
        }
    }

    return bufRequestStatus;
}

/***********************************************************************************************************************
 Function name    : Dcm_CopyRxData
 Syntax           : BufReq_ReturnType Dcm_CopyRxData(PduIdType id,const PduInfoType* info, PduLengthType* bufferSizePtr)
 Description      : This Call back API is invoked by the lower layer to copy the request in DCM
 Parameter        : PduIdType,const PduInfoType*, PduLengthType*
 Return value     : BufReq_ReturnType
 ***********************************************************************************************************************/

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3186] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3187] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3381] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3636] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3641] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3640] */

BufReq_ReturnType Dcm_CopyRxData(PduIdType id, const PduInfoType* info, PduLengthType* bufferSizePtr)
{
    BufReq_ReturnType bufRequestStatus = BUFREQ_E_NOT_OK;
    /*check all parameters are valid */
#if(DCM_CFG_RXPDU_SHARING_ENABLED == DCM_CFG_ON)
    if ((NULL_PTR != info) &&(NULL_PTR != info->SduDataPtr)&& (TRUE == Dcm_isObdRequestReceived_b))
    {
        if(TRUE == Dcm_Prv_isRxPduShared(id,info->SduDataPtr[0]))
        {
            id = (DCM_CFG_TOTAL_RX_PDUID-1u);
        }
    }
#endif
if (BUFREQ_OK==Dcm_CheckEnvironment(id,info,bufferSizePtr))
{
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(Dcm_Prv_IsRxPduIdOBD(id))
    {
        /* BSWEXT-533 */
        SchM_Enter_Dcm_Global();
        bufRequestStatus = Dcm_Prv_OBDCopyRxData(id,info,bufferSizePtr);
        /* BSWEXT-533 */
        SchM_Exit_Dcm_Global();
    }
    else
#endif
{
        if (0x00u==info->SduLength)
        {
            Dcm_ProvideRxBufferSize(id,bufferSizePtr);
            bufRequestStatus=BUFREQ_OK;
        }
        else if(TRUE == Dcm_Prv_GetFunctionalTPStatusFlag(id))
        {
            bufRequestStatus=BUFREQ_OK;
        }
        else
        {
            /* BSWEXT-533 */
            SchM_Enter_Dcm_Global();
            bufRequestStatus = Dcm_Prv_ProcessCopyRxData(id,info,bufferSizePtr);
            /* BSWEXT-533 */
            SchM_Exit_Dcm_Global();

        }
}
}
return bufRequestStatus;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
