
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
#include "Rte_Dcm.h"
#include "KeyM.h"
#include "Csm.h"
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
static Std_ReturnType Dcm_VerifyCertificateInitial (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_VerifyCertificateProcess (Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static void Dcm_VerifyCertificateCancel (const Dcm_MsgContextType* pMsgContext);
static Std_ReturnType Dcm_VerifyCertificateLengthCheck (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_VerifyCertificateClient (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GenerateChallengeServer (Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_VerifyCertificateClientStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_VerifyCertificateClientCompleted (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_SetCertificateClient (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GetCertificateStatus (KeyM_CertificateIdType certId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GenerateChallengeServerStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GenerateChallengeServerCompleted (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GenerateProofOfOwnershipServer (Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GenerateProofOfOwnershipServerStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GenerateProofOfOwnershipServerCompleted (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_GetCertificateServer (KeyM_CertificateIdType certId);
static Std_ReturnType Dcm_AuthAssembleResponse (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static uint8 Dcm_AuthChallengeServer_au8[DCM_CFG_AUTH_CHALLENGE_SERVER_MAX_SIZE];
static uint8 Dcm_AuthProofOfOwnershipServer_au8[DCM_CFG_AUTH_PROOF_OF_OWNERSHIP_SERVER_MAX_SIZE];
static uint8 Dcm_AuthCertificateServer_au8[DCM_CFG_AUTH_CERTIFICATE_SERVER_MAX_SIZE];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
static uint32 Dcm_AuthChallengeServerSize_u32;
static uint32 Dcm_AuthProofOfOwnershipServerSize_u32;
static uint32 Dcm_AuthCertificateServerSize_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_stVerfiyCertificate_ten Dcm_stVerfiyCertificate_en;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static const uint8 Dcm_AuthCommunicationConfigurationSize_cu8 = 1u;
static const uint8 Dcm_AuthLengthCertificateClientSize_cu8 = 2u;
static const uint8 Dcm_AuthLengthChallengeClientSize_cu8 = 2u;
static const uint8 Dcm_AuthLengthChallengeServerSize_cu8 = 2u;
static const uint8 Dcm_AuthLengthCertificateServerSize_cu8 = 2u;
static const uint8 Dcm_AuthLengthProofOfOwnershipServerSize_cu8 = 2u;
static const uint8 Dcm_AuthLengthEphemeralPublicKeyServerSize_cu8 = 2u;
static const uint8 Dcm_AuthEphemeralPublicKeyServerSize_cu8 = 0u;
static const uint8 Dcm_AuthIdxCommunicationConfiguration_cu8 = 1u;
static const uint8 Dcm_AuthIdxLengthCertificateClient_cu8 = 2u;
static const uint8 Dcm_AuthIdxCertificateClient_cu8 = 4u;
static const uint8 Dcm_AuthIdxLengthChallengeServer_cu8 = 2u;
static const uint8 Dcm_AuthIdxChallengeServer_cu8 = 4u;
static const uint8 Dcm_AuthCommunicationConfigurationExpected_cu8 = 0u;
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************
*/
LOCAL_INLINE uint16 Dcm_GetLengthCertificateClient(const Dcm_MsgContextType* pMsgContext);
LOCAL_INLINE uint16 Dcm_GetLengthCertificateClient(const Dcm_MsgContextType* pMsgContext)
{
    return ( (((uint16) pMsgContext->reqData[Dcm_AuthIdxLengthCertificateClient_cu8]) << 8u) | ((uint16) pMsgContext->reqData[Dcm_AuthIdxLengthCertificateClient_cu8 + 1u])) ;
}

LOCAL_INLINE uint32 Dcm_GetIndexLengthChallengeClient(const Dcm_MsgContextType* pMsgContext);
LOCAL_INLINE uint32 Dcm_GetIndexLengthChallengeClient(const Dcm_MsgContextType* pMsgContext)
{
    return (uint32)((uint16)Dcm_AuthIdxCertificateClient_cu8 + Dcm_GetLengthCertificateClient(pMsgContext));
}

LOCAL_INLINE uint16 Dcm_GetLengthChallengeClient(const Dcm_MsgContextType* pMsgContext);
LOCAL_INLINE uint16 Dcm_GetLengthChallengeClient(const Dcm_MsgContextType* pMsgContext)
{
    uint32 idxLengthchallengeClient_u32 = Dcm_GetIndexLengthChallengeClient(pMsgContext);
    return ( (((uint16) pMsgContext->reqData[idxLengthchallengeClient_u32]) << 8u) | ((uint16) pMsgContext->reqData[idxLengthchallengeClient_u32 + 1u])) ;
}



/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Sub-Service handler for verifyCertificate */
Std_ReturnType Dcm_Prv_VerifyCertificate (Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType subServiceResult = E_NOT_OK;

    switch(OpStatus)
    {
        case DCM_CANCEL:
        Dcm_VerifyCertificateCancel(pMsgContext);
        subServiceResult = E_OK;
        break;

        case DCM_INITIAL:
        subServiceResult = Dcm_VerifyCertificateInitial(pMsgContext, dataNegRespCode_u8);
        if (subServiceResult == E_OK)
        {
            Dcm_SrvOpstatus_u8= DCM_PROCESSSERVICE;
            /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
            /* No Break statement here as the PROCESSSERVICE shall continue immediately after the DCM_INITIAL is completed sucessfully */
        }
        else
        {
            break;
        }
        /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
        case DCM_PROCESSSERVICE:
        subServiceResult = Dcm_VerifyCertificateProcess(pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;
    }

    if (E_NOT_OK == subServiceResult)
    {
        Dcm_Prv_AuthenticationNRCHandling(dataNegRespCode_u8);
    }

    return subServiceResult;
}

void Dcm_Prv_VerifyCertificateStateIni(void)
{
    Dcm_stVerfiyCertificate_en = DCM_VERIFY_CERTIFICATE_IDLE;
}

/* Synchronous Operations of the Sub-Service verifyCertificate which needs to be executed before the first asynchronous operation */
static Std_ReturnType Dcm_VerifyCertificateInitial (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType initialResult = E_NOT_OK;

    if((DCM_ASYNCH_OPERATION_INACTIVE == Dcm_Prv_GetAuthAsynchOpStatus()) && (DCM_VERIFY_CERTIFICATE_IDLE == Dcm_stVerfiyCertificate_en))
    {
        if(E_OK == Dcm_VerifyCertificateLengthCheck(pMsgContext, dataNegRespCode_u8))
        {
            if(Dcm_AuthCommunicationConfigurationExpected_cu8 == pMsgContext->reqData[Dcm_AuthIdxCommunicationConfiguration_cu8])
            {
                if(E_OK == Dcm_SetCertificateClient(pMsgContext, dataNegRespCode_u8))
                {
                    initialResult = E_OK;
                    Dcm_stVerfiyCertificate_en = DCM_VERIFY_CERTIFICATE_CLIENT;
                }
            }
            else
            {
                *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }

    return initialResult;
}

/* Asynchronous Operations of the Sub-Service verifyCertificate. Also includes the synchronous operations which needs to be done after any asynchronous operation */
static Std_ReturnType Dcm_VerifyCertificateProcess (Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType processResult = E_NOT_OK;

    switch(Dcm_stVerfiyCertificate_en)
    {
        case DCM_VERIFY_CERTIFICATE_CLIENT:
        processResult = Dcm_VerifyCertificateClient(pMsgContext, dataNegRespCode_u8);
        if (processResult == E_OK)
        {
            Dcm_stVerfiyCertificate_en = DCM_GENERATE_CHALLENGE_SERVER;
            /* No Break statement here as the DCM_GENERATE_CHALLENGE_SERVER shall continue immediately after the DCM_CERTIFICATE_VERIFICATION is completed sucessfully */
            /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
        }
        else
        {
            break;
        }
        /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
        case DCM_GENERATE_CHALLENGE_SERVER:
        processResult = Dcm_GenerateChallengeServer(pMsgContext, dataNegRespCode_u8);
        if ((E_OK == processResult) && ((uint8)DCM_VERIFY_CERTIFICATE_UNIDIRECTIONAL != pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8]))
        {
            Dcm_stVerfiyCertificate_en = DCM_GENERATE_PROOF_OF_OWNERSHIP_SERVER;
            /* No Break statement here as the DCM_GENERATE_PROOF_OF_OWNERSHIP_SERVER shall continue immediately after the DCM_GENERATE_CHALLENGE_SERVER is completed sucessfully */
            /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
        }
        else
        {
            break;
        }
        /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
        case DCM_GENERATE_PROOF_OF_OWNERSHIP_SERVER:
        processResult = Dcm_GenerateProofOfOwnershipServer(pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;
    }

    if (DCM_E_PENDING != processResult)
    {
        Dcm_stVerfiyCertificate_en = DCM_VERIFY_CERTIFICATE_IDLE;
    }

    return processResult;
}

static void Dcm_VerifyCertificateCancel (const Dcm_MsgContextType* pMsgContext)
{
    uint16 authConnectionIndex_u16;
    uint32 jobId;
    boolean cancelCsmJob_b = FALSE;

    if(DCM_ASYNCH_OPERATION_ACTIVE == Dcm_Prv_GetAuthAsynchOpStatus())
    {
        if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
        {
            if(DCM_GENERATE_CHALLENGE_SERVER == Dcm_stVerfiyCertificate_en)
            {
                jobId = Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].challengeServerGenerateJobId_u32;
                cancelCsmJob_b = TRUE;
            }
            else if(DCM_GENERATE_PROOF_OF_OWNERSHIP_SERVER == Dcm_stVerfiyCertificate_en)
            {
                jobId = Dcm_Cfg_AuthConnectionBiDirectional_acst[authConnectionIndex_u16].proofOfOwnershipServerGenerateJobId_u32;
                cancelCsmJob_b = TRUE;
            }
            else
            {
                /* For MISRA */
            }

            if(cancelCsmJob_b)
            {
                /* Ignore the return value from Csm as this information is not useful to Dcm
                 * If the Csm_CancelJob returns E_NOT_OK (Request failed), Dcm will still proceed to cancel the service 0x29.
                 * As ths AuthAsynchOpStatus is set to DCM_ASYNCH_OPERATION_INACTIVE, the callback from the Csm will be ignored by Dcm anyways. */
                (void)Csm_CancelJob(jobId,CRYPTO_OPERATIONMODE_SINGLECALL);
            }
        }
    }
    Dcm_Prv_SetAuthAsynchOpStatus(DCM_ASYNCH_OPERATION_INACTIVE);
    Dcm_stVerfiyCertificate_en = DCM_VERIFY_CERTIFICATE_IDLE;
}

static Std_ReturnType Dcm_VerifyCertificateLengthCheck (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType checkResult = E_NOT_OK;
    uint32 expectedLength_u32;
    uint16 lengthCertificateClient_u16 = Dcm_GetLengthCertificateClient(pMsgContext);
    uint16 lengthChallengeClient_u16 = Dcm_GetLengthChallengeClient(pMsgContext);

    expectedLength_u32 = (uint32)(Dcm_AuthSubFunctionSize_cu8 + Dcm_AuthCommunicationConfigurationSize_cu8 + Dcm_AuthLengthCertificateClientSize_cu8 + lengthCertificateClient_u16 + Dcm_AuthLengthChallengeClientSize_cu8 + lengthChallengeClient_u16);

    if (expectedLength_u32 == pMsgContext->reqDataLen)
    {
        if(0u != lengthCertificateClient_u16)
        {
            if((pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8] == (uint8)DCM_VERIFY_CERTIFICATE_UNIDIRECTIONAL) || (0u != lengthChallengeClient_u16))
            {
                checkResult = E_OK;
            }
            else
            {
                *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            }
        }
        else
        {
            *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }

    return checkResult;
}

/* State machine handler for the asynchronous operation KeyM_VerifyCertificate() */
static Std_ReturnType Dcm_VerifyCertificateClient (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType subStateResult = E_NOT_OK;
    Dcm_AuthAsynchOpStatusType_ten asynchOpStatus_en = Dcm_Prv_GetAuthAsynchOpStatus();

    switch(asynchOpStatus_en)
    {
        case DCM_ASYNCH_OPERATION_INACTIVE:
        subStateResult = Dcm_VerifyCertificateClientStart(pMsgContext, dataNegRespCode_u8);
        break;

        case DCM_ASYNCH_OPERATION_ACTIVE:
        subStateResult = DCM_E_PENDING;
        break;

        case DCM_ASYNCH_OPERATION_COMPLETED:
        subStateResult = Dcm_VerifyCertificateClientCompleted(pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;
    }
    return subStateResult;
}

/* State machine handler for the asynchronous operation Csm_RandomGenerate() */
static Std_ReturnType Dcm_GenerateChallengeServer (Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType subStateResult = E_NOT_OK;
    Dcm_AuthAsynchOpStatusType_ten asynchOpStatus_en = Dcm_Prv_GetAuthAsynchOpStatus();

    switch(asynchOpStatus_en)
    {
        case DCM_ASYNCH_OPERATION_INACTIVE:
        subStateResult = Dcm_GenerateChallengeServerStart(pMsgContext, dataNegRespCode_u8);
        break;

        case DCM_ASYNCH_OPERATION_ACTIVE:
        subStateResult = DCM_E_PENDING;
        break;

        case DCM_ASYNCH_OPERATION_COMPLETED:
        subStateResult = Dcm_GenerateChallengeServerCompleted(pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;
    }
    return subStateResult;
}

/* State machine handler for the asynchronous operation Csm_SignatureGenerate() */
static Std_ReturnType Dcm_GenerateProofOfOwnershipServer (Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType subStateResult = E_NOT_OK;
    Dcm_AuthAsynchOpStatusType_ten asynchOpStatus_en = Dcm_Prv_GetAuthAsynchOpStatus();

    switch(asynchOpStatus_en)
    {
        case DCM_ASYNCH_OPERATION_INACTIVE:
        subStateResult = Dcm_GenerateProofOfOwnershipServerStart(pMsgContext, dataNegRespCode_u8);
        break;

        case DCM_ASYNCH_OPERATION_ACTIVE:
        subStateResult = DCM_E_PENDING;
        break;

        case DCM_ASYNCH_OPERATION_COMPLETED:
        subStateResult = Dcm_GenerateProofOfOwnershipServerCompleted(pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;
    }
    return subStateResult;
}

/* Start asynchronous operation KeyM_VerifyCertificate() */
static Std_ReturnType Dcm_VerifyCertificateClientStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchStartResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    KeyM_CertificateIdType certId;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        certId = (KeyM_CertificateIdType)Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].certificateClientId_u16;
        asynchStartResult = Dcm_GetCertificateStatus(certId, dataNegRespCode_u8);

        if(E_OK == asynchStartResult)
        {
            asynchStartResult = KeyM_VerifyCertificate(certId);

            if(E_OK == asynchStartResult)
            {
                Dcm_Prv_SetAuthAsynchOpStatus(DCM_ASYNCH_OPERATION_ACTIVE);
                asynchStartResult = DCM_E_PENDING;
            }
            else if(KEYM_E_BUSY == asynchStartResult)
            {
                *dataNegRespCode_u8 = DCM_E_BUSYREPEATREQUEST;
                asynchStartResult = E_NOT_OK;
            }
            else
            {
                asynchStartResult = E_NOT_OK;
            }
        }
    }

    return asynchStartResult;
}

/* Asynchronous operation KeyM_VerifyCertificate() completed successfully */
static Std_ReturnType Dcm_VerifyCertificateClientCompleted (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchCompletedResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    KeyM_CertificateIdType certId;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        certId = (KeyM_CertificateIdType)Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].certificateClientId_u16;
        asynchCompletedResult  = Dcm_Prv_GetKeyMVerifyCertificateResult(certId, dataNegRespCode_u8);
    }
    return asynchCompletedResult;
}

/* Start asynchronous operation Csm_RandomGenerate() */
static Std_ReturnType Dcm_GenerateChallengeServerStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchStartResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    uint32 jobId;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        jobId = Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].challengeServerGenerateJobId_u32;
        Dcm_AuthChallengeServerSize_u32 = (uint16)Dcm_Cfg_AuthChallengeServerSize_acu16[authConnectionIndex_u16];

        /* The size of the buffer provided to Csm in Dcm_AuthChallengeServer_au8[] is generated based largest possible random generate result DCM_CFG_AUTH_CHALLENGE_SERVER_MAX_SIZE(<=65535)  that can generated by the Csm Jobs configured in Dcm_Authentication.
         * This makes sure that Csm will always get a sufficient enough buffer to generate the challenge server */
        asynchStartResult = Csm_RandomGenerate(jobId, &Dcm_AuthChallengeServer_au8[0], &Dcm_AuthChallengeServerSize_u32 );
        if(E_OK == asynchStartResult)
        {
            Dcm_Prv_SetAuthAsynchOpStatus(DCM_ASYNCH_OPERATION_ACTIVE);
            asynchStartResult = DCM_E_PENDING;
        }
        else if((uint8)CRYPTO_E_BUSY == asynchStartResult)
        {
            *dataNegRespCode_u8 = DCM_E_BUSYREPEATREQUEST;
            asynchStartResult = E_NOT_OK;
        }
        else
        {
            asynchStartResult = E_NOT_OK;
        }
    }
    return asynchStartResult;
}

/* Asynchronous operation Csm_RandomGenerate() completed successfully */
static Std_ReturnType Dcm_GenerateChallengeServerCompleted (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchCompletedResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    uint32 jobId;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        jobId = Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].challengeServerGenerateJobId_u32;
        if(E_OK == Dcm_Prv_GetCsmJobResult(jobId, dataNegRespCode_u8))
        {
            if((uint8)DCM_VERIFY_CERTIFICATE_UNIDIRECTIONAL == pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8])
            {
                if(E_OK == Dcm_AuthAssembleResponse(pMsgContext, dataNegRespCode_u8))
                {
                    Dcm_Prv_SetProofOfOwnershipExpected(TRUE);
                    asynchCompletedResult = E_OK;
                }
            }
            else
            {
                asynchCompletedResult = E_OK;
            }
        }
    }

    return asynchCompletedResult;
}

/* Start asynchronous operation Csm_SignatureGenerate() */
static Std_ReturnType Dcm_GenerateProofOfOwnershipServerStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchStartResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    uint32 jobId;
    uint32 idxLengthChallengeClient_u32;
    uint32 idxChallengeClient_u32;
    uint16 lengthChallengeClient_u16;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        jobId = Dcm_Cfg_AuthConnectionBiDirectional_acst[authConnectionIndex_u16].proofOfOwnershipServerGenerateJobId_u32;
        idxLengthChallengeClient_u32 = Dcm_GetIndexLengthChallengeClient(pMsgContext);
        idxChallengeClient_u32 = idxLengthChallengeClient_u32 + Dcm_AuthLengthChallengeClientSize_cu8;
        lengthChallengeClient_u16 = Dcm_GetLengthChallengeClient(pMsgContext);
        Dcm_AuthProofOfOwnershipServerSize_u32 = DCM_CFG_AUTH_PROOF_OF_OWNERSHIP_SERVER_MAX_SIZE;

        /* The size of the buffer provided to Csm Dcm_AuthProofOfOwnershipServer_au8[] is generated based largest possible signature generate result DCM_CFG_AUTH_PROOF_OF_OWNERSHIP_SERVER_MAX_SIZE(<=65535)  that can generated by the Csm Jobs configured in Dcm_Authentication.
         * This makes sure that Csm will always get a sufficient enough buffer to generate the proof of ownership server */
        asynchStartResult = Csm_SignatureGenerate(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, &pMsgContext->reqData[idxChallengeClient_u32], (uint32)lengthChallengeClient_u16, &Dcm_AuthProofOfOwnershipServer_au8[0], &Dcm_AuthProofOfOwnershipServerSize_u32 );
        if(E_OK == asynchStartResult)
        {
            Dcm_Prv_SetAuthAsynchOpStatus(DCM_ASYNCH_OPERATION_ACTIVE);
            asynchStartResult = DCM_E_PENDING;
        }
        else if((uint8)CRYPTO_E_BUSY == asynchStartResult)
        {
            *dataNegRespCode_u8 = DCM_E_BUSYREPEATREQUEST;
            asynchStartResult = E_NOT_OK;
        }
        else
        {
            asynchStartResult = E_NOT_OK;
        }
    }
    return asynchStartResult;
}

/* Asynchronous operation Csm_SignatureGenerate() completed successfully */
static Std_ReturnType Dcm_GenerateProofOfOwnershipServerCompleted (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchCompletedResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    KeyM_CertificateIdType certId;
    uint32 jobId;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        jobId = Dcm_Cfg_AuthConnectionBiDirectional_acst[authConnectionIndex_u16].proofOfOwnershipServerGenerateJobId_u32;
        if(E_OK == Dcm_Prv_GetCsmJobResult(jobId, dataNegRespCode_u8))
        {
            certId = (KeyM_CertificateIdType)Dcm_Cfg_AuthConnectionBiDirectional_acst[authConnectionIndex_u16].certificateServerId;
            if (E_OK == Dcm_GetCertificateServer(certId))
            {
                if(E_OK == Dcm_AuthAssembleResponse(pMsgContext, dataNegRespCode_u8))
                {
                    Dcm_Prv_SetProofOfOwnershipExpected(TRUE);
                    asynchCompletedResult = E_OK;
                }
            }
        }
    }

    return asynchCompletedResult;
}

static Std_ReturnType Dcm_GetCertificateServer (KeyM_CertificateIdType certId)
{
    Std_ReturnType getCertificateResult = E_NOT_OK;
    KeyM_CertDataType certificateDataPtr;

    /* The size of the buffer provided to KeyM in Dcm_AuthCertificateServer_au8[] is generated based largest possible certificate server DCM_CFG_AUTH_CERTIFICATE_SERVER_MAX_SIZE(<=65535) that is configured in Dcm_Authentication.
     * This makes sure that KeyM will always get a sufficient enough buffer for the certificate server */
    certificateDataPtr.certDataLength = (uint32)DCM_CFG_AUTH_CERTIFICATE_SERVER_MAX_SIZE;
    certificateDataPtr.certData = &Dcm_AuthCertificateServer_au8[0];

    if(KeyM_GetCertificate(certId, &certificateDataPtr) == E_OK)
    {
        Dcm_AuthCertificateServerSize_u32 = certificateDataPtr.certDataLength;
        getCertificateResult = E_OK;
    }

    return getCertificateResult;
}

static Std_ReturnType Dcm_SetCertificateClient (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType setCertificateResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    KeyM_CertificateIdType certId;
    KeyM_CertDataType certificateDataPtr;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        certId = (KeyM_CertificateIdType)Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].certificateClientId_u16;
        certificateDataPtr.certDataLength = (uint32) Dcm_GetLengthCertificateClient(pMsgContext);
        certificateDataPtr.certData = &pMsgContext->reqData[Dcm_AuthIdxCertificateClient_cu8];

        setCertificateResult = KeyM_SetCertificate(certId, &certificateDataPtr);
        if(setCertificateResult == KEYM_E_KEY_CERT_SIZE_MISMATCH)
        {
            *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            setCertificateResult = E_NOT_OK;
        }
        else if(setCertificateResult != E_OK)
        {
            setCertificateResult = E_NOT_OK;
        }
        else
        {
            /* for MISRA */
        }
    }

    return setCertificateResult;
}

static Std_ReturnType Dcm_GetCertificateStatus (KeyM_CertificateIdType certId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType getCertificateStatusResult = E_NOT_OK;
    KeyM_CertificateStatusType certificateStatus = KEYM_CERTIFICATE_INVALID;

    if(E_OK == KeyM_CertGetStatus(certId, &certificateStatus))
    {
        if(KEYM_CERTIFICATE_NOT_PARSED == certificateStatus)
        {
            getCertificateStatusResult = DCM_E_PENDING;
        }
        else if(KEYM_CERTIFICATE_PARSED_NOT_VALIDATED == certificateStatus)
        {
            getCertificateStatusResult = E_OK;
        }
        /* KEYM_CERTIFICATE_NOT_AVAILABLE is not possible, as the Ceritificate set successfully
         * KEYM_CERTIFICATE_VALID is not possible, as the Ceritificate is not yet verified
         * All the other possible KeyM_CertificateStatusType is handled in the else part */
        else
        {
            Dcm_Prv_CertificateInvalidNRCHandling(certificateStatus, dataNegRespCode_u8);
        }
    }
    /* KEYM_E_PARAMETER_MISMATCH is also a possible return value from KeyM_CertGetStatus()
     * But Dcm considers KEYM_E_PARAMETER_MISMATCH similar to E_NOT_OK internally, as there are
     * no specific NRCs specified for KEYM_E_PARAMETER_MISMATCH */

    return getCertificateStatusResult;
}


void Dcm_Prv_GetChallengeServer(uint8** challengeServer_ppu8, uint32* lengthChallengeServer_pu32)
{
    *challengeServer_ppu8 = &Dcm_AuthChallengeServer_au8[0];
    *lengthChallengeServer_pu32 = Dcm_AuthChallengeServerSize_u32;
}

static Std_ReturnType Dcm_AuthAssembleResponse (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType assembleResponseResult = E_NOT_OK;
    uint32 actualResLen = 0;
    uint32 idxLengthCertificateServer_u32 = 0;
    uint32 idxCertificateServer_u32 = 0;
    uint32 idxLengthProofOfOwnershipServer_u32 = 0;
    uint32 idxProofOfOwnershipServer_u32 = 0;
    uint32 idxlengthEphemeralPublicKeyServer_u32 = 0;
    uint32 idx_u32 = 0;

    if((uint8)DCM_VERIFY_CERTIFICATE_UNIDIRECTIONAL == pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8])
    {
        idxlengthEphemeralPublicKeyServer_u32 = (uint32)Dcm_AuthIdxChallengeServer_cu8 + Dcm_AuthChallengeServerSize_u32;
    }
    else
    {
        idxLengthCertificateServer_u32 = (uint32)Dcm_AuthIdxChallengeServer_cu8 + Dcm_AuthChallengeServerSize_u32;
        idxCertificateServer_u32 = idxLengthCertificateServer_u32 + (uint32)Dcm_AuthLengthCertificateServerSize_cu8;
        idxLengthProofOfOwnershipServer_u32 = idxCertificateServer_u32 + Dcm_AuthCertificateServerSize_u32;
        idxProofOfOwnershipServer_u32 = idxLengthProofOfOwnershipServer_u32 + (uint32)Dcm_AuthLengthProofOfOwnershipServerSize_cu8 ;
        idxlengthEphemeralPublicKeyServer_u32 = idxProofOfOwnershipServer_u32 + Dcm_AuthProofOfOwnershipServerSize_u32;
    }

    actualResLen = idxlengthEphemeralPublicKeyServer_u32 + Dcm_AuthLengthEphemeralPublicKeyServerSize_cu8;

    if(pMsgContext->resMaxDataLen >= actualResLen)
    {
        pMsgContext->resData[Dcm_AuthIdxSubFunction_cu8] = pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8] ;
        pMsgContext->resData[Dcm_AuthIdxReturnParameter_cu8] = (uint8)DCM_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY;

        /* Assemble the generated challenge server in the response buffer.
         * Dcm_AuthChallengeServerSize_u32 will always be <= 0xFFFFu as the maximum buffer size provided to Csm is uint16 */
        pMsgContext->resData[Dcm_AuthIdxLengthChallengeServer_cu8] = (uint8)((Dcm_AuthChallengeServerSize_u32 & 0xFF00u) >> 8u);
        pMsgContext->resData[Dcm_AuthIdxLengthChallengeServer_cu8 + 1u] = (uint8)(Dcm_AuthChallengeServerSize_u32 & 0x00FFu);
        for(idx_u32 = 0; idx_u32 <= Dcm_AuthChallengeServerSize_u32; idx_u32++)
        {
            pMsgContext->resData[(uint32)Dcm_AuthIdxChallengeServer_cu8 + idx_u32] = Dcm_AuthChallengeServer_au8[idx_u32];
        }

        if((uint8)DCM_VERIFY_CERTIFICATE_BIDIRECTIONAL == pMsgContext->reqData[Dcm_AuthIdxSubFunction_cu8])
        {
            /* Assemble the generated certificate server in the response buffer.
             * Dcm_AuthCertificateServerSize_u32 will always be <= 0xFFFFu as the maximum buffer size provided to KeyM is uint16 */
            pMsgContext->resData[idxLengthCertificateServer_u32] = (uint8)((Dcm_AuthCertificateServerSize_u32 & 0xFF00u) >> 8);
            pMsgContext->resData[idxLengthCertificateServer_u32 + 1u] = (uint8)(Dcm_AuthCertificateServerSize_u32 & 0x00FFu);
            for(idx_u32 = 0; idx_u32 <= Dcm_AuthCertificateServerSize_u32; idx_u32++)
            {
                pMsgContext->resData[idxCertificateServer_u32 + idx_u32] = Dcm_AuthCertificateServer_au8[idx_u32];
            }

            /* Assemble the generated proof of ownership server in the response buffer.
             * Dcm_AuthProofOfOwnershipServerSize_u32 will always be <= 0xFFFFu as the maximum buffer size provided to Csm is uint16 */
            pMsgContext->resData[idxLengthProofOfOwnershipServer_u32] = (uint8)((Dcm_AuthProofOfOwnershipServerSize_u32 & 0xFF00u) >> 8);
            pMsgContext->resData[idxLengthProofOfOwnershipServer_u32 + 1u] = (uint8)(Dcm_AuthProofOfOwnershipServerSize_u32 & 0x00FFFu);
            for(idx_u32 = 0; idx_u32 <= Dcm_AuthProofOfOwnershipServerSize_u32; idx_u32++)
            {
                pMsgContext->resData[idxProofOfOwnershipServer_u32 + idx_u32] = Dcm_AuthProofOfOwnershipServer_au8[idx_u32];
            }
        }

        pMsgContext->resData[idxlengthEphemeralPublicKeyServer_u32] = Dcm_AuthEphemeralPublicKeyServerSize_cu8;
        pMsgContext->resData[idxlengthEphemeralPublicKeyServer_u32 + 1u] = Dcm_AuthEphemeralPublicKeyServerSize_cu8;
        pMsgContext->resDataLen = actualResLen;
        assembleResponseResult = E_OK;
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_RESPONSETOOLONG;
    }

    return assembleResponseResult;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif /* (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON) */
