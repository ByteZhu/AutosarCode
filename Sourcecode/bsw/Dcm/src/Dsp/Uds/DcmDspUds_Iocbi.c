
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
 * Variables
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
uint8 Dcm_ControlParameter_u8;
static Std_ReturnType  Dcm_ServiceRetVal;
Std_ReturnType Dcm_ProcessIOResult;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_ProcessStates_ten Dcm_ProcessState_en;
static Dcm_ValidationStates_ten Dcm_ValidationStates_en;
const Dcm_ExtendedDIDConfig_tst * ptrDidExtendedConfig;
const Dcm_DIDConfig_tst * ptrDidConfig;
Dcm_DIDIndexType_tst Dcm_idxIocbiDidIndexType_st;
Dcm_OpStatusType Dcm_DspIocbiOpStatus;
#if(DCM_CFG_NUM_IOCBI_DIDS != 0x0)
Dcm_Dsp_IocbiStatusType_tst DcmDsp_IocbiStatus_array[DCM_CFG_NUM_IOCBI_DIDS];
#endif
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"
uint16 Dcm_ReadSignalLength_u16;
uint16 Dcm_dataSignalLength_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
boolean Dcm_IocbiRteCallPlaced_b;
#endif
#if (DCM_CFG_DSP_READ_ASP_ENABLED != DCM_CFG_OFF)
boolean Dcm_IocbiReadLengthRteCallPlaced_b;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"


void Dcm_Prv_DspIOCBIConfirmation(uint8 sid_u8,
                                    uint8 reqType_u8,
                                    uint16 connectionId_u16,
                                    Dcm_ConfirmationStatusType confirmationStatus,
                                    Dcm_ProtocolType protocolType,
                                    uint16 testerSrcAddress_u16)
{
    DcmAppl_DcmConfirmation(sid_u8,reqType_u8,connectionId_u16,confirmationStatus,protocolType,testerSrcAddress_u16);
}



void Dcm_Prv_DspIOCBI_Init(void)
{
    const Dcm_DataInfoConfig_tst * ptrSigConfig  = NULL_PTR;
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig = NULL_PTR;

    /* To call cancellation of SWCD operation in case API was called with Opstatus as DCM_PENDING */
#if(DCM_CFG_DSP_CONTROL_ASYNCH_FNC_ENABLED == DCM_CFG_ON)
    if (Dcm_DspIocbiOpStatus == DCM_PENDING)
    {
        ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
        ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];
        ptrDidExtendedConfig = ptrDidConfig->adrExtendedConfig_pcst;

        if ((ptrSigConfig->idxDcmDspControlInfo_u16 > 0) && (ptrIOSigConfig->idxDcmDspIocbiInfo_u16 > 0))
        {
#if(DCM_CFG_DSP_CONTROLMASK_EXTERNAL_ENABLED != DCM_CFG_OFF)
            if(DCM_CONTROLMASK_EXTERNAL == ptrDidConfig->adrExtendedConfig_pcst->dataCtrlMask_en)
            {
                (void)Dcm_Prv_IocbiInitExternalMask();
            }
            else
#endif
            {
                (void)Dcm_Prv_IocbiInitInternalMask();
            }
        }
    }
#endif


    if (Dcm_idxIocbiDidIndexType_st.dataopstatus_b == DCM_PENDING)
    {
        ptrSigConfig = &Dcm_DspDataInfo_st[Dcm_DIDConfig[Dcm_idxIocbiDidIndexType_st.idxIndex_u16].adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];

        if((ptrSigConfig->adrReadFnc_cpv!=NULL_PTR) && ((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER)|| (ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_FNC)))
        {
#if (DCM_CFG_DSP_READ_ASP_ENABLED != DCM_CFG_OFF)
            if ((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER) && (ptrSigConfig->UseAsynchronousServerCallPoint_b))
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                (void)(*(ReadFunc11_ptr) (ptrSigConfig->adrReadFnc_cpv))(DCM_CANCEL);
            }
            else
#endif
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                (void)(*(ReadFunc2_ptr) (ptrSigConfig->adrReadFnc_cpv))(DCM_CANCEL, NULL_PTR);
            }
        }
    }


    Dcm_ProcessIOResult = E_OK;
    Dcm_dataSignalLength_u16 = 0u;
    Dcm_ReadSignalLength_u16 = 0u;

    Dcm_DidSignalIdx_u16 = 0x0;
    Dcm_SrvOpstatus_u8   = DCM_INITIAL;
    Dcm_DspIocbiOpStatus = DCM_INITIAL;

#if (DCM_CFG_DSP_READ_ASP_ENABLED != DCM_CFG_OFF)
    Dcm_IocbiReadLengthRteCallPlaced_b = FALSE;
#endif
#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
    Dcm_IocbiRteCallPlaced_b = FALSE;
#endif

    Dcm_ResetDIDIndexstruct(&Dcm_idxIocbiDidIndexType_st); /*This function is invoked to reset all the elements of DID index structure to its default value*/
    (void)ptrIOSigConfig;
}




/*TRACE[Ext-4294]*/
static void Dcm_ResponseService(Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    Std_ReturnType Result   = E_NOT_OK;

    Result = Dcm_GetDIDData(&Dcm_idxIocbiDidIndexType_st,&pMsgContext->resData[3]);

    if((Result == E_OK) || (Result == DCM_E_PENDING))
    {
        Dcm_Prv_UpdateStatusArray(Result);

        if(Result == E_OK)
        {
            Dcm_SrvOpstatus_u8 = DCM_INITIAL;

            Dcm_idxIocbiDidIndexType_st.dataopstatus_b = DCM_INITIAL;
            Dcm_idxIocbiDidIndexType_st.nrNumofSignalsRead_u16 = 0x0; /*All the signals read correctly, therefore reset it to zero*/
            Dcm_idxIocbiDidIndexType_st.dataSignalLengthInfo_u32 = 0x0; /*All the signals read correctly, therefore reset the signal data length to zero*/

            /* Prepare the DID bytes and the Input Output Control parameter in the response buffer */
            pMsgContext->resData[0] = pMsgContext->reqData[0];
            pMsgContext->resData[1] = pMsgContext->reqData[1];
            pMsgContext->resData[2] = Dcm_ControlParameter_u8;  //IOCBI Control Parameter
            pMsgContext->resDataLen = Dcm_ReadSignalLength_u16+DSP_IOCBI_MINREQLEN;
            Dcm_ReadSignalLength_u16 = 0;
        }
        else
        {
            Dcm_idxIocbiDidIndexType_st.dataopstatus_b = DCM_PENDING;
            Dcm_DidSignalIdx_u16 = Dcm_idxIocbiDidIndexType_st.nrNumofSignalsRead_u16;
        }
    }
    else
    {
        if(Result == E_NOT_OK)
        {
            /* Invoke the DcmAPPl API to obtain the NRC from the Application*/
            if(E_OK != DcmAppl_DcmReadDataNRC(Dcm_DIDConfig[Dcm_idxIocbiDidIndexType_st.idxIndex_u16].dataDid_u16,\
                    Dcm_DIDConfig[Dcm_idxIocbiDidIndexType_st.idxIndex_u16].adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].posnSigBit_u16,\
                    ErrorCode))
            {
                *ErrorCode = DCM_E_GENERALREJECT;
            }
        }
        else
        {
            *ErrorCode = DCM_E_GENERALREJECT;
        }

        Dcm_idxIocbiDidIndexType_st.nrNumofSignalsRead_u16   = 0x0; /*E_NOT_OK set stop reading the signals, therefore reset the number of singals read to zero*/
        Dcm_idxIocbiDidIndexType_st.dataSignalLengthInfo_u32 = 0x0; /*All the signals not read correctly, therefore reset the signal data length to zero*/
        Dcm_idxIocbiDidIndexType_st.dataopstatus_b = DCM_INITIAL;
    }

    Dcm_ServiceRetVal = Result;
}


/*TRACE[Ext-4230][Ext-5018][Ext-4231][Ext-5019]*/
/*TRACE[Ext-4232][Ext-5020][Ext-4233][Ext-5021][Ext-4299][Ext-4300]*/
static void Dcm_ProcessService(const Dcm_MsgContextType *pMsgContext,Dcm_NegativeResponseCodeType *ErrorCode)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DCM_CFG_DSP_CONTROLMASK_EXTERNAL_ENABLED != DCM_CFG_OFF)
    if(DCM_CONTROLMASK_EXTERNAL == ptrDidConfig->adrExtendedConfig_pcst->dataCtrlMask_en)
    {
        Result = Dcm_Prv_ProcessWithExternalMask(pMsgContext,ErrorCode);
    }
    else
#endif
    {
        Result = Dcm_Prv_ProcessWithInternalMask(pMsgContext,ErrorCode);
    }

    if ((E_OK == Result) && (*ErrorCode == 0u))
    {
        Dcm_DidSignalIdx_u16 = 0x0;
        Dcm_DspIocbiOpStatus = DCM_INITIAL;
        Dcm_ProcessState_en  = DCM_IOCBI_RESPONSE;
    }
    else if(E_NOT_OK == Result)
    {
        Dcm_ReadSignalLength_u16 = 0;
        Dcm_DspIocbiOpStatus = DCM_INITIAL;

        if(*ErrorCode == 0u)
        {
            *ErrorCode = DCM_E_GENERALREJECT;
        }
    }
    else
    {
        Dcm_DspIocbiOpStatus = DCM_INITIAL;
        if(DCM_E_PENDING == Result)
        {
            *ErrorCode = 0x00;
            Dcm_DspIocbiOpStatus = DCM_PENDING;
            Dcm_ServiceRetVal   = DCM_E_PENDING;
        }
    }
}



static void Dcm_ProcessIoControl(Dcm_MsgContextType *pMsgContext,Dcm_NegativeResponseCodeType *ErrorCode)
{
    if(DCM_IOCBI_PROCESS == Dcm_ProcessState_en)
    {
        Dcm_ProcessService(pMsgContext,ErrorCode);
    }

    if(DCM_IOCBI_RESPONSE == Dcm_ProcessState_en)
    {
        Dcm_ResponseService(pMsgContext,ErrorCode);
    }
}



/*TRACE[Ext-3597][Ext-3052][Ext-4197][Ext-4198][Ext-4199][Ext-4202][Ext-4203]*/
static void Dcm_ValidateService(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DCM_IOCBI_CHECKSESSION == Dcm_ValidationStates_en)
    {
        if(0x0u != (Dcm_DsldGetActiveSessionMask_u32() & (ptrDidConfig->adrExtendedConfig_pcst->dataSessBitMask_u32)))
        {
            Dcm_ValidationStates_en = DCM_IOCBI_CHECKLENGTH;
        }
        else
        {
            Dcm_ServiceRetVal = E_NOT_OK;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }

    if(DCM_IOCBI_CHECKLENGTH == Dcm_ValidationStates_en)
    {
        Result = Dcm_Prv_CheckTotalLength(pMsgContext,ErrorCode);

        if((E_OK == Result) && (*ErrorCode == 0u))
        {
            Dcm_ValidationStates_en = DCM_IOCBI_CHECKSECURITY;
        }
        else if(DCM_E_PENDING == Result)
        {
            Dcm_ServiceRetVal = DCM_E_PENDING;
            *ErrorCode = 0u;
        }
        else
        {
            Dcm_ServiceRetVal = E_NOT_OK;
        }
    }

    if(DCM_IOCBI_CHECKSECURITY == Dcm_ValidationStates_en)
    {
        Result = Dcm_Prv_CheckAccessRights(DCM_CHECK_DID,\
                ptrDidConfig->adrExtendedConfig_pcst->dataAuthenticationRoles_u32,pMsgContext,ErrorCode);

        if(E_OK != Result)
        {
            Dcm_ServiceRetVal = E_NOT_OK;
        }
        else if(0x0u == (Dcm_DsldGetActiveSecurityMask_u32() & (ptrDidConfig->adrExtendedConfig_pcst->dataSecBitMask_u32)))
        {
            Dcm_ServiceRetVal = E_NOT_OK;
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
        else
        {
            Dcm_ValidationStates_en = DCM_IOCBI_CHECKMODERULE;
        }
    }

    if(DCM_IOCBI_CHECKMODERULE == Dcm_ValidationStates_en)
    {
        Result = Dcm_Prv_CheckCondition(pMsgContext,ErrorCode);

        if((E_OK == Result) && (*ErrorCode == 0u))
        {
            Dcm_ControlParameter_u8 = pMsgContext->reqData[2];
            Dcm_SrvOpstatus_u8 = DCM_PROCESSSERVICE;
            Dcm_ProcessState_en = DCM_IOCBI_PROCESS;
            Dcm_ValidationStates_en = DCM_IOCBI_CHECKSESSION;
        }
        else
        {
            Dcm_ServiceRetVal = E_NOT_OK;
        }
    }

    if((E_NOT_OK == Dcm_ServiceRetVal) && (*ErrorCode == 0u))
    {
        //Need to check
        *ErrorCode = DCM_E_GENERALREJECT;
    }
}



/*TRACE[Ext-4194][Ext-4196][Ext-4320]*/
static void Dcm_CheckDidSupport(const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* ErrorCode)
{
    if(!(pMsgContext->reqDataLen >= DSP_IOCBI_MINREQLEN))
    {
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else if(!(pMsgContext->reqData[2] <= 3u))
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else if (E_OK != Dcm_Prv_GetIndexOfDID((uint16)(DSP_CONV_2U8_TO_U16 (pMsgContext->reqData[0], \
            pMsgContext->reqData[1])),&Dcm_idxIocbiDidIndexType_st))
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    #if(DCM_CFG_DSP_NUMISDIDAVAIL>0)
    else if(FALSE == Dcm_Prv_CheckVariant(pMsgContext,Dcm_idxIocbiDidIndexType_st))
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    #endif
    else
    {
        ptrDidConfig = &Dcm_DIDConfig[Dcm_idxIocbiDidIndexType_st.idxIndex_u16];
        ptrDidExtendedConfig = ptrDidConfig->adrExtendedConfig_pcst;

        if(FALSE != Dcm_Prv_CheckIoControl(pMsgContext,ErrorCode))
        {
            Dcm_SrvOpstatus_u8 = DCM_CHECKDATA;
            Dcm_ValidationStates_en = DCM_IOCBI_CHECKSESSION;
        }
    }
}




/*TRACE[Ext-4195][Ext-4229]*/
Std_ReturnType Dcm_Prv_DspInputOutputControlByIdentifier(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,\
        Dcm_NegativeResponseCodeType * dataNegRespCode_u8)
{
    Dcm_ServiceRetVal = DCM_E_PENDING;
    *dataNegRespCode_u8 = 0u;

    if (OpStatus == DCM_CANCEL)
    {
        Dcm_Prv_DspIOCBI_Init();
        Dcm_ServiceRetVal = E_OK;
    }
    else
    {
        if (Dcm_SrvOpstatus_u8 == DCM_INITIAL)
        {
            Dcm_CheckDidSupport(pMsgContext,dataNegRespCode_u8);
        }

        if (Dcm_SrvOpstatus_u8 == DCM_CHECKDATA)
        {
            Dcm_ValidateService(pMsgContext,dataNegRespCode_u8);
        }

        if (Dcm_SrvOpstatus_u8 == DCM_PROCESSSERVICE)
        {
            Dcm_ProcessIoControl(pMsgContext,dataNegRespCode_u8);
        }
    }

    /* If negative response code is set */
    if(*dataNegRespCode_u8 != 0x00u)
    {
        Dcm_DidSignalIdx_u16 = 0x00u;
        Dcm_ServiceRetVal = E_NOT_OK;
        Dcm_SrvOpstatus_u8 = DCM_INITIAL;
    }

    return Dcm_ServiceRetVal;
}



#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif      /* #if (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF) */
