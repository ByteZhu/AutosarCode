

#ifndef DCM_PRV_DSD_INLINE_H
#define DCM_PRV_DSD_INLINE_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Defines/Macros/inline function
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_DslTxType_tst Dcm_DslTransmit_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


LOCAL_INLINE boolean Dcm_Dsd_isNegativeResponseSupressed(Dcm_NegativeResponseCodeType Nrc_u8)
{
    uint8 reqType_u8=Dcm_Dsd_Prv_GetReqType();
    uint8 cntrWaitpendCounter_u8 = Dcm_Dsl_Prv_GetRespPendingCounterValue();
    boolean isKwpActive_b =  DCM_IS_KWPPROT_ACTIVE();

    return ((reqType_u8==DCM_FUNCTIONAL_REQUEST) && (cntrWaitpendCounter_u8 == 0x00u)&& (isKwpActive_b == FALSE) &&
           ((Nrc_u8==0x11u)||(Nrc_u8==0x12u)||(Nrc_u8==0x31u)||(Nrc_u8==0x7Eu)||(Nrc_u8==0x7Fu)));
}


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)

LOCAL_INLINE boolean Dcm_Dsd_isObdNegativeResponseSupressed(Dcm_NegativeResponseCodeType Nrc_u8)
{
    return ((Nrc_u8==0x11u)||(Nrc_u8==0x12u)||(Nrc_u8==0x31u)||(Nrc_u8==0x7Eu)||(Nrc_u8==0x7Fu));
}



/***********************************************************************************************************************
 Function name    : Dcm_Prv_ObtainSidIndexOfOBD
 Syntax           : Dcm_Prv_ObtainSidIndexOfOBD(idxIndex_qu8,dataSid_cu8,context)
 Description      : Linear search to find out the element(Key, SID) for OBD in case of parallel processing
 Parameter        : uint8*,const uint8
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_ObtainSidIndexOfOBD(uint8* idxIndex_qu8, const uint8 dataSid_cu8)
{
    boolean IsSidAvailable_b = FALSE;
    uint8 srvTabId_u8   = Dcm_Prv_GetObdActiveProtocolRow()->srvTableId_u8;
    uint8 nrServices_u8 = Dcm_Cfg_Dsd_pcst->sidTables_pcast[srvTabId_u8].numOfServices_u8;
    *idxIndex_qu8 = DCM_DEFAULT_VALUE;

    while(*idxIndex_qu8 < nrServices_u8)
    {
        if(Dcm_Cfg_Dsd_pcst->sidTables_pcast[srvTabId_u8].srvTable_pcast[*idxIndex_qu8].sid_u8 == dataSid_cu8)
        {
            IsSidAvailable_b = TRUE;
            break;
        }
        (*idxIndex_qu8)++;
    }
    return(IsSidAvailable_b);
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDDsdSendNegativeResponse
 Syntax           : Dcm_Prv_OBDDsdSendNegativeResponse(ErrorCode)
 Description      : Trigger Negative Response by DSD for OBD
 Parameter        : Dcm_NegativeResponseCodeType
 Return value     : void
***********************************************************************************************************************/
LOCAL_INLINE void Dcm_Prv_OBDDsdSendNegativeResponse(Dcm_NegativeResponseCodeType ErrorCode)
{
    /* If no NRC is set , then set NRC to conditions not correct */
    ErrorCode = (ErrorCode == DCM_DEFAULT_VALUE)?DCM_E_CONDITIONSNOTCORRECT:ErrorCode;
    /* Response given by DSD itself , Set the data response given by DSD to True*/
    Dcm_OBDGlobal_st.dataResponseByDsd_b = TRUE;
    Dcm_Prv_SetOBDNegResponse(&Dcm_OBDMsgContext_st,ErrorCode);
    Dcm_OBDProcessingDone(&Dcm_OBDMsgContext_st);
}



/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessOBDServiceNotSupported
 Syntax           : Dcm_Prv_ProcessOBDServiceNotSupported(void)
 Description      : Helper Function to send NRC for OBD when requested service is not supported
 Parameter        : void
 Return value     : void
***********************************************************************************************************************/
LOCAL_INLINE void Dcm_Prv_ProcessOBDServiceNotSupported(void)
{
    Dcm_NegativeResponseCodeType ErrorCode_u8 = DCM_E_SERVICENOTSUPPORTED;

#if(DCM_CFG_RESPOND_ALLREQUEST == FALSE)
    uint8 SID_u8 = Dcm_OBDGlobal_st.dataSid_u8;
    /* Check whether the configured service is in proper range as specified in ISO */
    if((SID_u8 < DCM_SERVICE_ISO_LOWERLIMIT) ||
       ((SID_u8 > DCM_SERVICE_ISO_MIDLIMIT)  && (SID_u8 < DCM_SERVICE_ISO_UPPERLIMIT)))
    {
        Dcm_Prv_OBDDsdSendNegativeResponse(ErrorCode_u8);
    }
    else
    {
        /* SID is out of range, ignore the request *
        *  Set the suppressPosResponse flag is set to True */
        Dcm_OBDMsgContext_st.msgAddInfo.suppressPosResponse = TRUE;
        Dcm_OBDGlobal_st.dataResponseByDsd_b = TRUE;
        Dcm_OBDProcessingDone(&Dcm_OBDMsgContext_st);
    }
#else
    /* Send negative response for all range of SID with NRC service not supported because non configured service */
    Dcm_Prv_OBDDsdSendNegativeResponse(ErrorCode_u8);
#endif
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDVerifyData
 Syntax           : Dcm_Prv_OBDVerifyData()
 Description      : Perform verification of the requested data for OBD in case of parallel processing
 Parameter        : void
 Return value     : Std_ReturnType
***********************************************************************************************************************/
LOCAL_INLINE Std_ReturnType Dcm_Prv_OBDVerifyData(void)
{
    /* local pointer to service configuration structure */
    const Dcm_DsdServiceTableConfigType_tst* adrService_pcst;
    uint8 idxIndex_qu8;      /* To store the Index of the requested Service */
    Dcm_NegativeResponseCodeType ErrorCode_u8 = DCM_DEFAULT_VALUE;  /* Variable to store NRC from application */
    Std_ReturnType  VerificationResult_u8 = E_NOT_OK;  /* To update the return Value */

    /* 1: Verification of the requested SID */
    if (Dcm_Prv_ObtainSidIndexOfOBD(&idxIndex_qu8,Dcm_OBDGlobal_st.dataSid_u8))
    {
        /* SID found here, store the index of requested service */
        Dcm_OBDGlobal_st.idxService_u8 = idxIndex_qu8;
        /* Id context is used as SID */
        Dcm_OBDMsgContext_st.idContext = Dcm_OBDGlobal_st.dataSid_u8;
        /* get the active service configuration structure */
        adrService_pcst=Dcm_OBDSrvTable_pcst;
        /* generate bit mask for active security level */
        if(E_OK == Dcm_Dsl_Prv_VerifySecurityAccess(adrService_pcst->allowedSecurity_u32,&ErrorCode_u8))
        {
            /* 3: Check requested service is allowed in configured Mode rule */
            VerificationResult_u8 = (*adrService_pcst->serviceUserModeRule_pfct)
                                    (&ErrorCode_u8, Dcm_OBDGlobal_st.dataSid_u8);
#if(DCM_CFG_DSD_MODERULESERVICE_ENABLED != DCM_CFG_OFF)
            /* Check if the mode rule is configured for the sub function */
            if((adrService_pcst->serviceModeRule_pfct != ((Dcm_ModeRuleType)NULL_PTR)) && (VerificationResult_u8 == E_OK))
            {
                /* Call the mode rule API configured */
                VerificationResult_u8 = (adrService_pcst->serviceModeRule_pfct(&ErrorCode_u8) == TRUE)?E_OK:E_NOT_OK;
            }
#endif
        }

        if (VerificationResult_u8 != E_OK)
        {
            Dcm_Prv_OBDDsdSendNegativeResponse(ErrorCode_u8);
        }
    }
    else
    {
        Dcm_Prv_ProcessOBDServiceNotSupported();
    }
    return VerificationResult_u8;
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDServiceTableInit
 Syntax           : Dcm_Prv_OBDServiceTableInit()
 Description      : Function to Initialize the OBD service table
 Parameter        : void
 Return value     : void
***********************************************************************************************************************/
LOCAL_INLINE void Dcm_Prv_OBDServiceTableInit(void)
{
    Dcm_MsgItemType* adrRxBuffer_pu8;

    /* Pointer to the Tx buffer */
    Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8 = Dcm_Prv_GetObdActiveProtocolRow()->txBuffer_u8;
    /* Fill the maximum possible response length */
    Dcm_OBDMsgContext_st.resMaxDataLen = Dcm_Prv_GetObdActiveProtocolRow()->txBufferSize_u32 - DCM_SID_LENGTH;
    adrRxBuffer_pu8 = Dcm_Prv_GetObdActiveProtocolRow()->rxBuffer_u8;
    /* Data response given by DSD is set to False */
    Dcm_OBDGlobal_st.dataResponseByDsd_b = FALSE;
    /* Store SID in a global variable */
    Dcm_OBDGlobal_st.dataSid_u8 = adrRxBuffer_pu8[DCM_REQUESTBUFFER_INDEX];
    /* Index of requested service is initialised to zero */
    Dcm_OBDGlobal_st.idxService_u8 = DCM_DEFAULT_VALUE;
    /* Make the Positive response as the default response */
    Dcm_OBDGlobal_st.stResponseType_en = DCM_POS_RESPONSE;
    /* Response length (filled by the service) */
    Dcm_OBDMsgContext_st.resDataLen = DCM_DEFAULT_VALUE;
    Dcm_OBDTransmit_st.TxResponseLength_u32 = DCM_DEFAULT_VALUE;
    Dcm_OBDMsgContext_st.dcmRxPduId = Dcm_OBDGlobal_st.dataActiveRxPduId_u8;
    /* Fill the addressing mode info (physical or functional) */
    Dcm_OBDMsgContext_st.msgAddInfo.reqType = (Dcm_OBDGlobal_st.dataActiveRxPduId_u8 >= DCM_CFG_INDEX_FUNC_RX_PDUID)?
                                                DCM_PRV_FUNCTIONAL_REQUEST : DCM_PRV_PHYSICAL_REQUEST;
    /* Fill the request length excluding SID */
    Dcm_OBDMsgContext_st.reqDataLen = (Dcm_MsgLenType) Dcm_OBDGlobal_st.dataRequestLength_u16 - DCM_SID_LENGTH;
    /* Assign the Rx buffer address excluding SID */
    Dcm_OBDMsgContext_st.reqData = &(adrRxBuffer_pu8[DCM_REQUESTBUFFER_INDEX+DCM_SID_LENGTH]);
    /* Assign the Tx buffer address */
    Dcm_OBDMsgContext_st.resData = &(Dcm_OBDGlobal_st.adrActiveTxBuffer_tpu8[DCM_RESPONSEBUFFER_INDEX]);
}

#endif

/* DCM_PRV_DSD_INLINE_H */
#endif
