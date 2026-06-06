
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Iocbi_Inf.h"
#include "Dcm_Prv.h"
#include "DcmDspUds_Iocbi_Priv.h"



/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"




Std_ReturnType Dcm_GetActiveIOCBIDid(uint16 * dataDid_u16)
{
    uint16 idxIocbiIndex_u16 = 0u;
    Std_ReturnType Result = E_NOT_OK;

#if(DCM_CFG_NUM_IOCBI_DIDS != 0x0)
    for(idxIocbiIndex_u16 = 0u;idxIocbiIndex_u16<DCM_CFG_NUM_IOCBI_DIDS;idxIocbiIndex_u16++)
    {
        if(DCM_IOCBI_IDLESTATE != DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].IocbiStatus_en)
        {
           ptrDidConfig = &Dcm_DIDConfig[DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].idxindex_u16];
           *dataDid_u16 = ptrDidConfig->dataDid_u16;
           Result = E_OK;
           break;
        }
    }
#endif

    return Result;
}



static void Dcm_CheckFunctionConfigured(const void* IoControl_cpv,Dcm_NegativeResponseCodeType *ErrorCode)
{
    if((USE_DATA_ELEMENT_SPECIFIC_INTERFACES == ptrDidConfig->didUsePort_u8) && (IoControl_cpv == NULL_PTR))
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
        if(((USE_ATOMIC_SENDER_RECEIVER_INTERFACE == ptrDidConfig->didUsePort_u8) || \
                (USE_ATOMIC_SENDER_RECEIVER_INTERFACE_AS_SERVICE == ptrDidConfig->didUsePort_u8)) && \
                (NULL_PTR == ptrDidConfig->ioControlRequest_cpv))
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
}




boolean Dcm_Prv_CheckIoControl(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType *ErrorCode)
{
    const Dcm_DataInfoConfig_tst * ptrSigConfig;
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig;
    const Dcm_SignalDIDIocbiConfig_tst * ptrIOCBIsigConfig;
    boolean Result_b = FALSE;

    while((Dcm_DidSignalIdx_u16<ptrDidConfig->nrSig_u16) && (*ErrorCode==0u))
    {
        ptrSigConfig      = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
        ptrIOSigConfig    = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];
        ptrIOCBIsigConfig = &Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16];

        /*Check if the DID is supported for IOCTRL or not by comparing against the structure index*/
        if((ptrSigConfig->idxDcmDspControlInfo_u16 >0u) && (ptrIOSigConfig->idxDcmDspIocbiInfo_u16>0u))
        {
            /*TRACE[SWS_Dcm_00563]*/
            if((pMsgContext->reqData[2] == DCM_IOCBI_SHORTTERMADJUSTMENT) && ((ptrDidConfig->adrExtendedConfig_pcst->statusmaskIOControl_u8 & 0x08u)==0x08u ))
            {
                Dcm_CheckFunctionConfigured(ptrIOCBIsigConfig->adrShortTermAdjustment_cpv,ErrorCode);
            }
            else if((pMsgContext->reqData[2] == DCM_IOCBI_FREEZECURRENTSTATE) && ((ptrDidConfig->adrExtendedConfig_pcst->statusmaskIOControl_u8 & 0x04u)==0x04u ) )
            {
                Dcm_CheckFunctionConfigured(ptrIOCBIsigConfig->adrFreezeCurrentState_cpv,ErrorCode);
            }
            else if((pMsgContext->reqData[2] == DCM_IOCBI_RESETTODEFAULT) && ((ptrDidConfig->adrExtendedConfig_pcst->statusmaskIOControl_u8 & 0x02u)==0x02u ))
            {
                Dcm_CheckFunctionConfigured(ptrIOCBIsigConfig->adrResetToDefault_cpv,ErrorCode);
            }
            else if((pMsgContext->reqData[2] == DCM_IOCBI_RETURNCONTROLTOECU) && ((ptrDidConfig->adrExtendedConfig_pcst->statusmaskIOControl_u8 & 0x01u)==0x01u ))
            {
                Dcm_CheckFunctionConfigured(ptrIOCBIsigConfig->adrReturnControlEcu_cpv,ErrorCode);
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }

        if(*ErrorCode == 0u)
        {
            Dcm_DidSignalIdx_u16++;
        }
        else
        {
            break;
        }
    }

    if(*ErrorCode == 0x00u)
    {
        Dcm_DidSignalIdx_u16 = 0;
        Result_b = TRUE;
    }

    return Result_b;
}





Std_ReturnType Dcm_Prv_CheckTotalLength(const Dcm_MsgContextType * pMsgContext, Dcm_NegativeResponseCodeType * ErrorCode)
{
    uint16 controlMaskLen_u16 = 0u;
    uint32 dataLength_u32 = 0u;
    Std_ReturnType Result = E_OK;

    uint16 nrDID_u16 = (uint16)(DSP_CONV_2U8_TO_U16 (pMsgContext->reqData[0], pMsgContext->reqData[1]));


#if(DCM_CFG_DSP_SHORTTERMADJUSTMENT_ENABLED  == DCM_CFG_ON)
    if(DCM_IOCBI_SHORTTERMADJUSTMENT == pMsgContext->reqData[2])
    {
        Result = Dcm_GetLengthOfDIDIndex(&Dcm_idxIocbiDidIndexType_st,&dataLength_u32,nrDID_u16);
    }
#endif

    if(E_OK == Result)
    {
        if(ptrDidExtendedConfig->dataCtrlMask_en != DCM_CONTROLMASK_NO)
        {
            controlMaskLen_u16 = ptrDidExtendedConfig->dataCtrlMaskSize_u8;
        }

        if ((pMsgContext->reqDataLen-3u) != (dataLength_u32 + controlMaskLen_u16))
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /* If control state or control mask is present*/
            if((dataLength_u32 != 0u) || ((controlMaskLen_u16 != 0u) && (controlMaskLen_u16 <= 4u)))
            {
                /* Call the appl function to validate the control mask and control state*/
                Result = DcmAppl_DcmCheckControlMaskAndState(nrDID_u16,pMsgContext->reqData[2],&(pMsgContext->reqData[3]),(uint16)(pMsgContext->reqDataLen-3u));
                if(E_OK != Result)
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
            }
        }
    }
    else if (DCM_E_PENDING == Result)
    {
        /* Do nothing, just call again*/
    }
    else
    {
        *ErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
    }

    return Result;
}



#if(DCM_CFG_DSP_NUMISDIDAVAIL>0)
boolean Dcm_Prv_CheckVariant(const Dcm_MsgContextType* pMsgContext,Dcm_DIDIndexType_tst Dcm_IocbiDidIndexType_st)
{
    boolean Result_b = TRUE;

    uint16 DID_u16 = (uint16)(DSP_CONV_2U8_TO_U16 (pMsgContext->reqData[0], pMsgContext->reqData[1]));

    if((Dcm_IocbiDidIndexType_st.dataRange_b==FALSE) && (*Dcm_DIDIsAvail[Dcm_DIDConfig[Dcm_IocbiDidIndexType_st.idxIndex_u16].idxDIDSupportedFnc_u16] != NULL_PTR))
    {
        if(E_OK != (*(IsDIDAvailFnc_pf)(Dcm_DIDIsAvail[Dcm_DIDConfig[Dcm_IocbiDidIndexType_st.idxIndex_u16].idxDIDSupportedFnc_u16]))(DID_u16))
        {
            Result_b = FALSE;
        }
    }
    return Result_b;
}
#endif





Std_ReturnType Dcm_Prv_CheckCondition(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    boolean Result_b = FALSE;
    Std_ReturnType dataFuncRetVal = E_NOT_OK;

    if(NULL_PTR != ptrDidConfig->adrExtendedConfig_pcst->adrUserControlModeRule_pfct)
    {
        dataFuncRetVal = (*ptrDidConfig->adrExtendedConfig_pcst->adrUserControlModeRule_pfct)\
                (ErrorCode,ptrDidConfig->dataDid_u16,DCM_SUPPORT_IOCONTROL);
    }
    else
    {
        dataFuncRetVal = DcmAppl_UserDIDModeRuleService(ErrorCode,ptrDidConfig->dataDid_u16,DCM_SUPPORT_IOCONTROL);
    }

    if(E_OK == dataFuncRetVal)
    {
        Result_b = TRUE;

        #if(DCM_CFG_DSP_MODERULEFORDIDCONTROL != DCM_CFG_OFF)
        if(NULL_PTR != ptrDidConfig->adrExtendedConfig_pcst->adrIocbiModeRuleChkFnc_pfct)
        {
            Result_b = (*(ptrDidConfig->adrExtendedConfig_pcst->adrIocbiModeRuleChkFnc_pfct))(ErrorCode);
        }
        #endif
        if(FALSE != Result_b)
        {
            /* Check if the response length fits into the buffer */
            if (pMsgContext->resMaxDataLen >= (uint16)(ptrDidConfig->dataMaxDidLen_u16+3u))
            {
                dataFuncRetVal = E_OK;
            }
            else
            {
                dataFuncRetVal = E_NOT_OK;
                *ErrorCode = DCM_E_RESPONSETOOLONG;
            }
        }
        else
        {
            dataFuncRetVal = E_NOT_OK;
        }
    }


    if(E_OK != dataFuncRetVal)
    {
        if(0x00u == *ErrorCode)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }

    return dataFuncRetVal;
}





void Dcm_Prv_UpdateStatusArray(Std_ReturnType retValGetDid)
{
    uint16 idxIocbiIndex_u16 = 0u;

    for(idxIocbiIndex_u16=0;idxIocbiIndex_u16<DCM_CFG_NUM_IOCBI_DIDS;idxIocbiIndex_u16++)
    {
        if(Dcm_idxIocbiDidIndexType_st.idxIndex_u16 == DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].idxindex_u16)
        {
            if(Dcm_ControlParameter_u8 == DCM_IOCBI_RETURNCONTROLTOECU)
            {
                DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].IocbiStatus_en = (E_OK == retValGetDid) ? DCM_IOCBI_IDLESTATE : DCM_IOCBI_RCE_PENDING;
            }
            else if(Dcm_ControlParameter_u8 == DCM_IOCBI_RESETTODEFAULT)
            {
                DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].IocbiStatus_en = (E_OK == retValGetDid) ? DCM_IOCBI_RTD_ACTIVE : DCM_IOCBI_RTD_PENDING;
            }
            else if(Dcm_ControlParameter_u8 == DCM_IOCBI_FREEZECURRENTSTATE)
            {
                DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].IocbiStatus_en = (E_OK == retValGetDid) ? DCM_IOCBI_FCS_ACTIVE : DCM_IOCBI_FCS_PENDING;
            }
            else
            {
                if(Dcm_ControlParameter_u8 == DCM_IOCBI_SHORTTERMADJUSTMENT)
                {
                    DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].IocbiStatus_en = (E_OK == retValGetDid) ? DCM_IOCBI_STA_ACTIVE : DCM_IOCBI_STA_PENDING;
                }
            }
        }
    }
}



static boolean Dcm_isDidActive(uint16 idxIocbiIndex_u16,uint32 dataSessionMask_u32,uint32 dataSecurityMask_u32,boolean flgSessChkReqd_b)
{
    boolean Result_b = FALSE;

    if((DCM_IOCBI_IDLESTATE != DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].IocbiStatus_en)                                                                           &&     \
                    (Dcm_DIDConfig[DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].idxindex_u16].adrExtendedConfig_pcst->dataIocbirst_b  != FALSE)                                    &&     \
                    (((0x0u == ((Dcm_DIDConfig[DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].idxindex_u16].adrExtendedConfig_pcst->dataSecBitMask_u32)  & dataSecurityMask_u32)))   ||     \
                            (((flgSessChkReqd_b) && (0x0u  == ((Dcm_DIDConfig[DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].idxindex_u16].adrExtendedConfig_pcst->dataSessBitMask_u32) & dataSessionMask_u32))))))
    {
        Result_b = TRUE;
    }

    return Result_b;
}



static Std_ReturnType Dcm_ProcessResetActiveIOCtrl(const Dcm_DIDConfig_tst * DidConfig,uint16 idxSig_u16)
{
    void * ptrIOCBIFnc;
    const Dcm_DataInfoConfig_tst * ptrSigConfig;
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig;
    const Dcm_ExtendedDIDConfig_tst * ptrDidExtended;
    Std_ReturnType dataRetIocbiFunc_u8 = E_NOT_OK;
    Dcm_NegativeResponseCodeType dataNegResCode_u8 = 0u; /* Negative response code indicator */

#if(DCM_CFG_DSP_CONTROLMASK_EXTERNAL_ENABLED != DCM_CFG_OFF)
    uint8 ControlMask_u8 = 0xFFu;
    uint16 ControlMask_u16 = 0xFFFFu;
    uint32 ControlMask_u32 = 0xFFFFFFFFu;
    uint8 ControlMaskArr[1] = {0xFFu};
#endif

    ptrSigConfig   = &Dcm_DspDataInfo_st[DidConfig->adrDidSignalConfig_pcst[idxSig_u16].idxDcmDspDatainfo_u16];
    ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

#if( DCM_CFG_DSP_IOCBI_SR_ENABLED != DCM_CFG_OFF)
    if((USE_ATOMIC_SENDER_RECEIVER_INTERFACE == DidConfig->didUsePort_u8)||\
            (USE_ATOMIC_SENDER_RECEIVER_INTERFACE_AS_SERVICE == DidConfig->didUsePort_u8))
    {
        ptrIOCBIFnc = DidConfig->ioControlRequest_cpv;
        if(ptrIOCBIFnc != NULL_PTR)
        {
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            dataRetIocbiFunc_u8 =(*(IOControlrequest_pfct)(ptrIOCBIFnc))\
                    (DCM_RETURN_CONTROL_TO_ECU,NULL_PTR,0,0,DCM_INITIAL,&dataNegResCode_u8);
        }
        ptrIOCBIFnc = NULL_PTR;
        (void)dataRetIocbiFunc_u8;
        (void)dataNegResCode_u8;
    }
    else
#endif
    {
        ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrReturnControlEcu_cpv;
        ptrDidExtended = DidConfig->adrExtendedConfig_pcst;

        /*As ReturnControlToEcu is a synchronous API , the same API is invoked for both Synch and ASynch Fnc and ClientServer Configuration */
        if (ptrDidExtended->dataCtrlMask_en != DCM_CONTROLMASK_EXTERNAL)
        {
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            dataRetIocbiFunc_u8 = (*(ReturnControlEcu1_pfct) (ptrIOCBIFnc))(&dataNegResCode_u8);
        }
        else
        {
#if(DCM_CFG_DSP_CONTROLMASK_EXTERNAL_ENABLED != DCM_CFG_OFF)
            if(ptrDidExtended->dataCtrlMaskSize_u8 == 1u)
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                dataRetIocbiFunc_u8 = (*(ReturnControlEcu3_pfct)(ptrIOCBIFnc)) (ControlMask_u8,&dataNegResCode_u8);
            }
            else if(ptrDidExtended->dataCtrlMaskSize_u8 == 2u)
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                dataRetIocbiFunc_u8 = (*(ReturnControlEcu4_pfct)(ptrIOCBIFnc)) (ControlMask_u16,&dataNegResCode_u8);
            }
            else if(ptrDidExtended->dataCtrlMaskSize_u8 <= 4u)
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                dataRetIocbiFunc_u8 = (*(ReturnControlEcu5_pfct)(ptrIOCBIFnc)) (ControlMask_u32,&dataNegResCode_u8);
            }
            else
            {
                if((USE_DATA_SYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8) || (USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8))
                {
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                    dataRetIocbiFunc_u8 = (*(ReturnControlEcu9_pfct)(ptrIOCBIFnc)) (ControlMaskArr,&dataNegResCode_u8);
                }
            }
#endif
        }

        (void) dataNegResCode_u8;
    }

    return dataRetIocbiFunc_u8;
}


/*TRACE[Ext-4289][Ext-4291][Ext-4292][Ext-4293]*/
void Dcm_ResetActiveIoCtrl(uint32 dataSessionMask_u32,uint32 dataSecurityMask_u32,boolean flgSessChkReqd_b)
{
    /**The code which would loop through all the IOCBI DIDs and call all the returncontrol to ECU functions to reset all the  active IOctrls
     supported in the current session level*/

    uint16 idxIocbiIndex_u16; /*Index to loop through all the IOCTRL DID*/
    uint16 idxSig_u16; /*Index to loop through all the signals of the DID*/
    Std_ReturnType dataRetIocbiFunc_u8 = E_NOT_OK;
    const Dcm_DIDConfig_tst * DidConfig;

    for (idxIocbiIndex_u16 = 0; idxIocbiIndex_u16 < DCM_CFG_NUM_IOCBI_DIDS; idxIocbiIndex_u16++)
    {
        if(FALSE != Dcm_isDidActive(idxIocbiIndex_u16,dataSessionMask_u32,dataSecurityMask_u32,flgSessChkReqd_b))
        {
            DidConfig = &Dcm_DIDConfig[DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].idxindex_u16];

            /*Loop through all the signals of the IOCBI DID and invoke return control to ECU*/
            for (idxSig_u16 = 0; idxSig_u16 < DidConfig->nrSig_u16; idxSig_u16++)
            {
                dataRetIocbiFunc_u8 = Dcm_ProcessResetActiveIOCtrl(DidConfig,idxSig_u16);

                if(E_OK != dataRetIocbiFunc_u8)
                {
                    break;
                }
            }

            /*if the resetting the IOcontrol was successful, reset the status array to DCM_IOCBI_IDLESTATE*/
            if (E_OK == dataRetIocbiFunc_u8)
            {
                /*Update the Iocbistatus arrays status with DCM_IOCBI_IDLESTATE  when E_OK is returned from return control to ecu function pointer*/
                DcmDsp_IocbiStatus_array[idxIocbiIndex_u16].IocbiStatus_en = DCM_IOCBI_IDLESTATE;
            }
        }
    }

    (void) dataSessionMask_u32;
    (void) dataSecurityMask_u32;
    (void) flgSessChkReqd_b;
}


/**
 ****************************************************************************************************************************
 * Dcm_GetLengthOfSignal:
 *
 * Get the read data length of the current active signal for IOCBI request
 *
 * \param     dataSigLength_u16 :   Pointer to hold the length of the signal
 * \retval     E_OK: calculation finished successfully
 *             E_NOT_OK: error in configuration or in the called length calculating function
 *             DCM_INFRASTRUCTURE_ERROR : Infrastructure error occured
 * \seealso
 *
 ****************************************************************************************************************************
 */

Std_ReturnType Dcm_GetLengthOfSignal(uint16 * dataSigLength_u16)
{
    uint32 dataSigLength_u32;
    Std_ReturnType dataRetVal_u8 = E_NOT_OK;
    void * ptrReadDataLenFnc;
    const Dcm_DataInfoConfig_tst * ptrSigConfig;
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig;

    *dataSigLength_u16 = 0x0;

    if((ptrDidConfig->didUsePort_u8 == USE_ATOMIC_SENDER_RECEIVER_INTERFACE) || (ptrDidConfig->didUsePort_u8 == USE_ATOMIC_SENDER_RECEIVER_INTERFACE_AS_SERVICE))
    {
        while(Dcm_DidSignalIdx_u16 < ptrDidConfig->nrSig_u16)
        {
            ptrSigConfig= &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];

#if(DCM_CFG_DSP_CONTROL_FIXED_LEN_ENABLED != DCM_CFG_OFF)
            /*If the interface is RTE AR4.x retain the signal size in bits, else convert it to bytes*/
            *dataSigLength_u16 += ptrSigConfig->dataSize_u16;
#endif
            Dcm_DidSignalIdx_u16++;
        }
        Dcm_DidSignalIdx_u16=0x0;
        dataRetVal_u8 = E_OK;
    }
    else
    {
        ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
        ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

        ptrReadDataLenFnc = ptrIOSigConfig->adrReadDataLengthFnc_pfct;

        /* Check for USE FUNC and valid Read Data length function configuration */
        if((ptrSigConfig->idxDcmDspControlInfo_u16 >0u)&& (ptrReadDataLenFnc != NULL_PTR))
        {
#if(DCM_CFG_DSP_CONTROL_VAR_LEN_ENABLED != DCM_CFG_OFF)
            if((ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_FNC) || (ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_CLIENT_SERVER))
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                dataRetVal_u8 = (*(ReadDataLengthFnc1_pf)(ptrReadDataLenFnc))(dataSigLength_u16);
            }
            else
            {
                if ((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_FNC) || (ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER))
                {
#if (DCM_CFG_DSP_READ_ASP_ENABLED != DCM_CFG_OFF)
                    if ((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER) && (ptrSigConfig->UseAsynchronousServerCallPoint_b))
                    {
                        if(!Dcm_IocbiReadLengthRteCallPlaced_b)
                        {
                            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                            dataRetVal_u8 = (*(ReadDataLengthFnc6_pf)(ptrReadDataLenFnc))(Dcm_idxIocbiDidIndexType_st.dataopstatus_b);
                            if(dataRetVal_u8 == E_OK)
                            {
                                /* Set the Rte_Call Flag to TRUE and return Pending so that Rte_Result will be invoked in the next cycle */
                                Dcm_IocbiReadLengthRteCallPlaced_b = TRUE;
                                dataRetVal_u8 = DCM_E_PENDING;
                            }
                        }
                        else
                        {
                            ptrReadDataLenFnc = ptrIOSigConfig->adrReadDataLengthFncResults_pfct;
                            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                            dataRetVal_u8 = (*(ReadDataLengthFnc1_pf)(ptrReadDataLenFnc))(dataSigLength_u16);

                            if(dataRetVal_u8 == E_OK)
                            {
                                Dcm_IocbiReadLengthRteCallPlaced_b = FALSE;
                            }
                            else if(dataRetVal_u8 == RTE_E_NO_DATA)
                            {
                                dataRetVal_u8 = DCM_E_PENDING;
                            }
                            else
                            {
                                /* For any return value other than E_OK , RTE_E_NO_DATA ,  reset the Flag */
                                Dcm_IocbiReadLengthRteCallPlaced_b = FALSE;
                            }
                        }
                    }
                    else
#endif
                    {
                        /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                        dataRetVal_u8 = (*(ReadDataLengthFnc4_pf)(ptrReadDataLenFnc))(Dcm_idxIocbiDidIndexType_st.dataopstatus_b,dataSigLength_u16);
                    }
                }
            }

            if(dataRetVal_u8 == E_OK)
            {
                /* If the length received in more than the configured maximum length for a lengththen return error */
                if((*dataSigLength_u16 > ptrSigConfig->dataSize_u16) ||(*dataSigLength_u16==0))
                {
                    dataRetVal_u8 = E_NOT_OK;
                }
            }
            else if((dataRetVal_u8 == DCM_E_PENDING) && \
                    ((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_FNC) || (ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER)))
            {
                //do nothing
            }
            else
            {
                /* Check for infrastructural errors in case of RTE*/
                if((Dcm_IsInfrastructureErrorPresent_b(dataRetVal_u8) != FALSE) && \
                        ((ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_CLIENT_SERVER) || (ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER)))
                {
                    dataRetVal_u8=DCM_INFRASTRUCTURE_ERROR;
                }
            }
#endif
        }
        else
        {
#if(DCM_CFG_DSP_CONTROL_FIXED_LEN_ENABLED != DCM_CFG_OFF)
            /*If the interface is RTE AR4.x retain the signal size in bits, else convert it to bytes*/
            *dataSigLength_u16 = ptrSigConfig->dataSize_u16;
            dataRetVal_u8 = E_OK;
#endif
        }
    }

    if(dataRetVal_u8 == E_OK)
    {
        dataSigLength_u32=*dataSigLength_u16;
        *dataSigLength_u16=(uint16)dataSigLength_u32;
    }
    return dataRetVal_u8;
}






#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif      /* #if (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF) */

