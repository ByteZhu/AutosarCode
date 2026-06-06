
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"


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
static Std_ReturnType Dcm_Deauthenticate (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_AuthenticationConfiguration (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
const uint8 Dcm_AuthSubFunctionSize_cu8 = 1u;
const uint8 Dcm_AuthIdxSubFunction_cu8 =  0u;
const uint8 Dcm_AuthIdxReturnParameter_cu8 = 1u;
static const uint8 Dcm_AuthReturnParameterSize_cu8 = 1u;
static const uint8 Dcm_DeauthenticateExpLen_cu8 = 1u;
static const uint8 Dcm_AuthenticationConfigurationExpLen_cu8 = 1u;
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"
/* Initialize to an invalid sub-service 0xFF which is not supported by RTA-BSW Dcm */
static uint8 Dcm_AuthActiveSubService_u8 = 0xFF;
#define DCM_STOP_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
void Dcm_Prv_DspAuthentication_Init(void)
{
    Dcm_Prv_VerifyCertificateStateIni();
    Dcm_Prv_SetProofOfOwnershipExpected(FALSE);
    Dcm_Prv_SetAuthAsynchOpStatus(DCM_ASYNCH_OPERATION_INACTIVE);
}

Std_ReturnType Dcm_Prv_DspAuthentication (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType serviceResult = E_NOT_OK;

    if(DCM_CANCEL != OpStatus)
    {
        Dcm_AuthActiveSubService_u8 = pMsgContext->reqData[0];
    }

    /* The reqData will be invalid in case of DCM_CANCEL. So the Dcm_AuthActiveSubService_u8 is used to find
     * the previously active sub-service that needs to be cancelled */
    switch(Dcm_AuthActiveSubService_u8)
    {
        case (uint8)DCM_DEAUTHENTICATE:
        serviceResult = Dcm_Deauthenticate(OpStatus, pMsgContext, dataNegRespCode_u8);
        break;

        case (uint8)DCM_VERIFY_CERTIFICATE_UNIDIRECTIONAL:
        serviceResult = Dcm_Prv_VerifyCertificate(OpStatus, pMsgContext, dataNegRespCode_u8);
        break;

        case (uint8)DCM_VERIFY_CERTIFICATE_BIDIRECTIONAL:
        serviceResult = Dcm_Prv_VerifyCertificate(OpStatus, pMsgContext, dataNegRespCode_u8);
        break;

        case (uint8)DCM_PROOF_OF_OWNERSHIP:
        serviceResult = Dcm_Prv_ProofOfOwnership(OpStatus, pMsgContext, dataNegRespCode_u8);
        break;

        case (uint8)DCM_AUTHENTICATION_CONFIGURATION:
        serviceResult = Dcm_AuthenticationConfiguration(OpStatus, pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;

    }

    return serviceResult;
}

static Std_ReturnType Dcm_Deauthenticate (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType subServiceResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;

    if(DCM_INITIAL == OpStatus)
    {
        if(Dcm_DeauthenticateExpLen_cu8 == pMsgContext->reqDataLen)
        {
            if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
            {
                Dcm_Prv_ResetAccessRights(authConnectionIndex_u16);
                pMsgContext->resData[Dcm_AuthIdxSubFunction_cu8] = pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8] ;
                pMsgContext->resData[Dcm_AuthIdxReturnParameter_cu8] = (uint8)DCM_DEAUTHENTICATION_SUCCESSFUL;
                pMsgContext->resDataLen = (uint32)(Dcm_AuthSubFunctionSize_cu8 + Dcm_AuthReturnParameterSize_cu8);
                subServiceResult = E_OK;
            }
        }
        else
        {
            *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
    }

    return subServiceResult;
}

static Std_ReturnType Dcm_AuthenticationConfiguration (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType subServiceResult = E_NOT_OK;

    if(DCM_INITIAL == OpStatus)
    {
        if(Dcm_AuthenticationConfigurationExpLen_cu8 == pMsgContext->reqDataLen)
        {
            pMsgContext->resData[Dcm_AuthIdxSubFunction_cu8] = pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8] ;
            pMsgContext->resData[Dcm_AuthIdxReturnParameter_cu8] = (uint8)DCM_AUTHENTICATION_CONFIG_APCE;
            pMsgContext->resDataLen = (uint32)(Dcm_AuthSubFunctionSize_cu8 + Dcm_AuthReturnParameterSize_cu8);
            subServiceResult = E_OK;
        }
        else
        {
            *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
    }

    return subServiceResult;
}

void Dcm_Prv_AuthenticationNRCHandling (Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Dcm_NegativeResponseCodeType modeRuleNRC = 0;

    if(DCM_POSITIVE_RESPONSE != *dataNegRespCode_u8)
    {
        boolean isCertificateVerificationNRC_b = (DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCERTIFICATE >= *dataNegRespCode_u8) && (DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTIMEPERIOD <= *dataNegRespCode_u8);

        if((NULL_PTR != Dcm_Cfg_AuthGeneralNRCModeRule_pfct)&&(isCertificateVerificationNRC_b))
        {
            if((*(Dcm_Cfg_AuthGeneralNRCModeRule_pfct))(&modeRuleNRC))
            {
                *dataNegRespCode_u8 = DCM_CFG_AUTH_GENERAL_NRC;
            }
        }
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
    }
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif /* (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)  */
