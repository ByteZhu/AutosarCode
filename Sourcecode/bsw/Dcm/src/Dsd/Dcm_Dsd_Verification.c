
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"
#include "Dcm_Dsd_Verification.h"
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
 */
static Std_ReturnType Dcm_searchService(Dcm_IdContextType idContext,uint8 srvTabId_u8);
static Std_ReturnType Dcm_SearchSubService(uint8 subFuncId_u8);
static Std_ReturnType Dcm_VerifyService(const Dcm_MsgContextType *dcm_MsgContext_pst,\
        Dcm_NegativeResponseCodeType *negativeResponseCode);
static Std_ReturnType Dcm_VerifySubService(const Dcm_MsgContextType *dcm_MsgContext_pst,\
        Dcm_NegativeResponseCodeType *negativeResponseCode);
static Std_ReturnType Dcm_VerifyModeRule(Dcm_NegativeResponseCodeType *negativeResponseCode);

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static const Dcm_DsdServicePBConfigType_tst    **Dcm_DsdSidTablePbCfg_pacst;
static const Dcm_DsdServiceTableConfigType_tst *Dcm_DsdActiveSrvCfg_pst;
static const Dcm_DsdSubServiceConfigType_tst   *Dcm_DsdActiveSubSrvCfg_pcst;
static const Dcm_DsdServicePBConfigType_tst    *Dcm_DsdActiveSrvPbCfg_pcst;
static const Dcm_DsdSubSrvPBConfigType_tst     *Dcm_DsdActiveSubSrvPbCfg_pcst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-2736] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4048] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4054] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4070] */
Std_ReturnType Dcm_Dsd_Prv_Verification(const Dcm_MsgContextType *dcm_MsgContext_pst,
        Dcm_NegativeResponseCodeType *negativeResponseCode)
{
    Std_ReturnType verificationResult=E_NOT_OK;
    *negativeResponseCode = DCM_DEFAULT_VALUE;

    verificationResult = DCM_MANUFACTURER_NOTIFICATION(dcm_MsgContext_pst,negativeResponseCode,DCM_UDSCONTEXT);

    if(E_OK == verificationResult)
    {
        verificationResult = Dcm_VerifyService(dcm_MsgContext_pst,
                negativeResponseCode);

    }

    if(E_OK == verificationResult)
    {
        verificationResult = DCM_SUPPLIER_NOTIFICATION(dcm_MsgContext_pst,negativeResponseCode,DCM_UDSCONTEXT);
    }


    if((E_OK == verificationResult))
    {
        verificationResult = Dcm_VerifySubService(dcm_MsgContext_pst,
                negativeResponseCode);
    }

    if(E_OK == verificationResult)
    {
        verificationResult = Dcm_VerifyModeRule(negativeResponseCode);
    }

    if(E_NOT_OK==verificationResult)
    {
#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF ) && (DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF ))
        /*Check if Error Code is supported for the requested service shall have sid 0x27 and servicelocator is set to True*/
        if((*negativeResponseCode!=0x00u) && (dcm_MsgContext_pst->idContext==DCM_DSP_SID_SECURITYACCESS))
        {
            /* To Reset the stored AccessType when the NRC is returned for Seca Service(0x27) from DsdStateMachine*/
            Dcm_ResetAccessType();

        }
#endif
    }

    return verificationResult;
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3097] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3146] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3719] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4049] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4052] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3147] */
static Std_ReturnType Dcm_VerifyService(const Dcm_MsgContextType *dcm_MsgContext_pst,
        Dcm_NegativeResponseCodeType *negativeResponseCode)
{
    Std_ReturnType VerificationResult = E_NOT_OK;
    uint8 srvTabId_u8 = Dcm_Prv_GetActiveSrvTabId();

    if(E_OK == Dcm_searchService(dcm_MsgContext_pst->idContext,srvTabId_u8))
    {
        if(E_OK == Dcm_Prv_CheckAccessRights(DCM_CHECK_SERVICE,\
                Dcm_DsdActiveSrvPbCfg_pcst->allowedRole_u32,\
                dcm_MsgContext_pst,
                negativeResponseCode))
        {
            if(E_OK == Dcm_Dsl_Prv_VerifySessionAccess(Dcm_DsdActiveSrvCfg_pst->allowedSession_u32))
            {
                if(E_OK == Dcm_Dsl_Prv_VerifySecurityAccess(Dcm_DsdActiveSrvCfg_pst->allowedSecurity_u32,
                        negativeResponseCode))
                {
                    VerificationResult = E_OK;
                }
            }
            else
            {
                /* Requested service not supported in active session. Send NRC configured to DcmRbNRCForService. */
                *negativeResponseCode = Dcm_DsdActiveSrvCfg_pst->NRC_ServiceNotSupported_ActSession_u8;
            }
        }
    }
    else
    {
        *negativeResponseCode = DCM_E_SERVICENOTSUPPORTED;

        VerificationResult = Dcm_CheckRspAllRqst(dcm_MsgContext_pst->idContext);

    }

    return VerificationResult;
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3118] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3718] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4051] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4070] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3149] */
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3150] */
static Std_ReturnType Dcm_VerifySubService(const Dcm_MsgContextType *dcm_MsgContext_pst,
        Dcm_NegativeResponseCodeType *negativeResponseCode)
{
    Std_ReturnType VerificationResult = E_NOT_OK;
    Dcm_ProtocolType ProtocolId = Dcm_Prv_GetActiveProtocolType();
    uint8 subFuncId_u8;

    if((dcm_MsgContext_pst->idContext == DCM_ROUTINE_CONTROL_SID) || (Dcm_DsdActiveSrvCfg_pst->subFncAvail_b != TRUE))
    {
        VerificationResult = E_OK;
    }
    else
    {
        if(dcm_MsgContext_pst->reqDataLen >= DCM_SUBFUNC_INDEX)
        {
            subFuncId_u8 = (dcm_MsgContext_pst->reqData[DCM_REQUESTWITHOUT_SID]& DCM_REMOVESUPPRESSRESPONSEBIT_MASK);

            /* Get the sub-service byte from the request. In case of ROE mask the event storage information */
            subFuncId_u8 = (dcm_MsgContext_pst->idContext != DCM_ROE_SID)? (subFuncId_u8) : (subFuncId_u8 & DCM_REMOVEEVENTSTORAGEBIT_MASK);

            if(E_OK == Dcm_SearchSubService(subFuncId_u8))
            {
                if(E_OK == Dcm_Prv_CheckAccessRights(DCM_CHECK_SUBSERVICE,\
                        Dcm_DsdActiveSubSrvPbCfg_pcst->allowedSubSrvRoles_u32,\
                        dcm_MsgContext_pst,\
                        negativeResponseCode))
                {
                    if(E_OK == Dcm_Dsl_Prv_VerifySessionAccess(Dcm_DsdActiveSubSrvCfg_pcst->allowedSession_u32))
                    {
                        if(E_OK == Dcm_Dsl_Prv_VerifySecurityAccess(Dcm_DsdActiveSubSrvCfg_pcst->allowedSecurity_u32,
                                negativeResponseCode))
                        {
                            VerificationResult = E_OK;
                        }
                    }
                    else
                    {
                        *negativeResponseCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
                    }
                }
            }
            else
            {
                *negativeResponseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            }
        }
        else
        {
            if(FALSE == Dcm_DsdActiveSrvCfg_pst->internalDspService_b)
            {
                /* For services outside DSP call DcmAppl API to fetch the NRC in case minimum length check fails */
                DcmAppl_DcmGetNRCForMinLengthCheck(ProtocolId,dcm_MsgContext_pst->idContext,negativeResponseCode);
            }

            if(DCM_DEFAULT_VALUE == *negativeResponseCode)
            {
                /* If no NRC is set then update NRC to 0x13 */
                *negativeResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            }
        }
    }

    return VerificationResult;
}


/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3154]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3156] */
static Std_ReturnType Dcm_Dsd_VerifySubServiceModeRule(uint8 sid_u8, Dcm_NegativeResponseCodeType *negativeResponseCode)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 SubServiceId_u8 = Dcm_DsdActiveSubSrvCfg_pcst->subServiceId_u8;

    /* Check for User SubService mode rule */
    Result = Dcm_DsdActiveSubSrvCfg_pcst->subServiceUserModeRule_pfct(negativeResponseCode,sid_u8,SubServiceId_u8);

    if((E_OK == Result) && (NULL_PTR != Dcm_DsdActiveSubSrvCfg_pcst->subServiceModeRule_pfct))
    {
        /* Check for SubService mode rule */
        Result = (TRUE == Dcm_DsdActiveSubSrvCfg_pcst->subServiceModeRule_pfct(negativeResponseCode))?E_OK:E_NOT_OK;
    }

    return Result;
}

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3152]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3155] */
static Std_ReturnType Dcm_Dsd_VerifyServiceModeRule(uint8 sid_u8, Dcm_NegativeResponseCodeType *negativeResponseCode)
{
    Std_ReturnType Result = E_NOT_OK;

    /* Check for User service mode rule */
    Result = Dcm_DsdActiveSrvCfg_pst->serviceUserModeRule_pfct(negativeResponseCode,sid_u8);

    if((E_OK == Result) && (NULL_PTR != Dcm_DsdActiveSrvCfg_pst->serviceModeRule_pfct))
    {
        /* Check for service mode rule */
        Result = (TRUE == Dcm_DsdActiveSrvCfg_pst->serviceModeRule_pfct(negativeResponseCode))?E_OK:E_NOT_OK;
    }

    return Result;
}


/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3720]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4050]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3151]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3153] */
static Std_ReturnType Dcm_VerifyModeRule(Dcm_NegativeResponseCodeType *negativeResponseCode)
{
    Std_ReturnType ModeRuleResult = E_NOT_OK;
    uint8 sid_u8 = Dcm_DsdActiveSrvCfg_pst->sid_u8;

    ModeRuleResult = Dcm_Dsd_VerifyServiceModeRule(sid_u8,negativeResponseCode);

    if((E_OK == ModeRuleResult) && (Dcm_DsdActiveSrvCfg_pst->subFncAvail_b) && (sid_u8 != DCM_ROUTINE_CONTROL_SID))
    {
        ModeRuleResult = Dcm_Dsd_VerifySubServiceModeRule(sid_u8,negativeResponseCode);
    }

    return ModeRuleResult;
}


static Std_ReturnType Dcm_searchService(Dcm_IdContextType idContext,uint8 srvTabId_u8)
{
    Std_ReturnType serviceResult = E_NOT_OK;
    uint8 srvIdx_u8=0;
    uint8 numOfServices_u8 = 0;
    const Dcm_DsdServiceTableConfigType_tst *dsdSrvTableCfg_pst;
    const Dcm_DsdServicePBConfigType_tst    *dsdServicePbCfg_pcst;

    dsdSrvTableCfg_pst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[srvTabId_u8].srvTable_pcast;
    numOfServices_u8 = Dcm_Cfg_Dsd_pcst->sidTables_pcast[srvTabId_u8].numOfServices_u8;

    Dcm_DsdSidTablePbCfg_pacst = Dcm_Dsd_Prv_GetPBServiceTable();

    dsdServicePbCfg_pcst = Dcm_DsdSidTablePbCfg_pacst[srvTabId_u8];

    for(srvIdx_u8=0;srvIdx_u8< numOfServices_u8;srvIdx_u8++)
    {
        if(dsdSrvTableCfg_pst[srvIdx_u8].sid_u8 == idContext)
        {
            Dcm_DsdActiveSrvCfg_pst = &dsdSrvTableCfg_pst[srvIdx_u8];
            Dcm_DsdActiveSrvPbCfg_pcst = &dsdServicePbCfg_pcst[srvIdx_u8];
            serviceResult = E_OK;
            break;
        }
    }

    return serviceResult;
}

static Std_ReturnType Dcm_SearchSubService(uint8 subFuncId_u8)
{
    Std_ReturnType serviceResult = E_NOT_OK;
    uint8 subSrvIdx_u8=0;
    const Dcm_DsdSubServiceConfigType_tst   *subSrvCfg_pcst;
    subSrvCfg_pcst = Dcm_DsdActiveSrvCfg_pst->subSrvCfg_pcast;

    for(subSrvIdx_u8=0;subSrvIdx_u8< Dcm_DsdActiveSrvCfg_pst->numOfSubFnc_u8;subSrvIdx_u8++)
    {
        if(subSrvCfg_pcst[subSrvIdx_u8].subServiceId_u8 == subFuncId_u8)
        {
            Dcm_DsdActiveSubSrvCfg_pcst = &subSrvCfg_pcst[subSrvIdx_u8];
            Dcm_DsdActiveSubSrvPbCfg_pcst = &Dcm_DsdActiveSrvPbCfg_pcst->subSrvPbCfg_past[subSrvIdx_u8];
            serviceResult = E_OK;
            break;
        }
    }

    return serviceResult;
}


const Dcm_DsdServiceTableConfigType_tst* Dcm_Prv_GetServiceTable(void)
{
    return Dcm_DsdActiveSrvCfg_pst;
}

void Dcm_Prv_SetServiceTable(uint8 srvTabId)
{
    Dcm_DsdActiveSrvCfg_pst = Dcm_Cfg_Dsd_pcst->sidTables_pcast[srvTabId].srvTable_pcast;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
