
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
#include "DcmAppl.h"


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
/* Maximum of (Maximum length of a child element for Role and Whitelists) */
#define DCM_CERT_ELEMENT_CHILD_MAX_LENGTH 4u


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
static Std_ReturnType Dcm_ProofOfOwnershipInitial (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_ProofOfOwnershipProcess (Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static void Dcm_ProofOfOwnershipCancel (const Dcm_MsgContextType* pMsgContext);
static Std_ReturnType Dcm_ProofOfOwnershipLengthCheck (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_VerifyProofOfOwnershipClientStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_VerifyProofOfOwnershipClientCompleted (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_VerifyProofOfOwnershipClientResult (uint32 jobId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_ReadRoleAndAvailableWhitelists (uint16 authConnectionIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_SetupCertElement(uint16 authConnectionIndex_u16, uint8 certElementType_u8, Dcm_CertElementType_tst* certElement_pst);
static Std_ReturnType Dcm_ReadCertElement(KeyM_CertificateIdType certId, Dcm_CertElementType_tst* certElement_pst);
static Dcm_AuthReadChildReturnType_ten Dcm_ReadCertElementChild(KeyM_CertificateIdType certId, Dcm_CertElementType_tst* certElement_pst, Dcm_CertElementInstanceType_ten certElementInstance_en, KeyM_CertElementIteratorType *certElementIterator);
static Std_ReturnType Dcm_CopyChildDataToElementData(Dcm_CertElementType_tst* certElement_pst, const uint8* childData_pcau8, uint8 childDataLength_u8);
static Std_ReturnType Dcm_CheckChildDataLength(const Dcm_CertElementType_tst* certElement_pcst, uint8 childDataLength_u8);
static Std_ReturnType Dcm_CheckRoleLength(const Dcm_CertElementType_tst* certElement_pcst);
static void Dcm_SetRoleAndAvailableWhitelists(uint16 authConnectionIndex_u16);
static void Dcm_PersistAccessRights(uint16 authConnectionIndex_u16);


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* Temproray storage location of  Role and Whitelist certificate elements in Dsp.
 * These will be passed to Dsl to be stored in the permanent Role and Whitelist storage location */
static uint8 Dcm_RoleTempData_au8[DCM_CFG_AUTH_ROLE_SIZE] = {0u};
static uint8 Dcm_RoleTempDataNumEntry_u8 = 0u;

static uint8 Dcm_WhitelistServiceTempData_au8[DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE] = {0u};
static uint8 Dcm_WhitelistServiceTempDataNumEntry_u8 = 0u;
/* Offset is needed for service whitelist to calculate the start and end positon of each service whitelist entry, as each of them can have a different length (1-Dcm_WhitelistServiceChildMaxLength_cu8 bytes) */
static uint8 Dcm_WhitelistServiceTempOffset_au8[DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE] = {0u};

static uint8 Dcm_WhitelistDIDTempData_au8[DCM_CFG_AUTH_WHITELIST_DID_MAX_SIZE] = {0u};
static uint8 Dcm_WhitelistDIDTempDataNumEntry_u8= 0u;

static uint8 Dcm_WhitelistRIDTempData_au8[DCM_CFG_AUTH_WHITELIST_RID_MAX_SIZE] = {0u};
static uint8 Dcm_WhitelistRIDTempDataNumEntry_u8 = 0u;

static uint8 Dcm_WhitelistMemSelnTempData_au8[DCM_CFG_AUTH_WHITELIST_MEMSELN_MAX_SIZE] = {0u};
static uint8 Dcm_WhitelistMemSelnTempDataNumEntry_u8 = 0u;
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Crypto_VerifyResultType Dcm_AuthVerifyProofOfOwnershipClientResult;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
static boolean Dcm_ProofOfOwnershipExpected_b = FALSE;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static const uint8 Dcm_AuthLengthProofOfOwnershipClientSize_cu8 = 2u;
static const uint8 Dcm_AuthLengthEphemeralPublicKeyClientSize_cu8 = 2u;
static const uint8 Dcm_AuthLengthSessionKeyInfoSize_cu8 = 2u;
static const uint8 Dcm_AuthIdxLengthProofOfOwnershipClient_cu8 = 1u;
static const uint8 Dcm_AuthIdxProofOfOwnershipClient_cu8 = 3u;
static const uint8 Dcm_AuthIdxLengthSessionKeyInfo_cu8 = 2u;
static const uint8 Dcm_AuthIdxSessionKeyInfo_cu8 = 4u;
static const uint8 Dcm_WhitelistServiceChildMaxLength_cu8 = 4u;
static const uint8 Dcm_WhitelistDIDChildMaxLength_cu8 = 3u;
static const uint8 Dcm_WhitelistRIDChildMaxLength_cu8 = 3u;
static const uint8 Dcm_WhitelistMemSelnChildMaxLength_cu8 = 1u;
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************
*/
LOCAL_INLINE uint16 Dcm_GetLengthProofOfOwnershipClient(const Dcm_MsgContextType* pMsgContext);
LOCAL_INLINE uint16 Dcm_GetLengthProofOfOwnershipClient(const Dcm_MsgContextType* pMsgContext)
{
    return ( (((uint16) pMsgContext->reqData[Dcm_AuthIdxLengthProofOfOwnershipClient_cu8]) << 8u) | ((uint16) pMsgContext->reqData[Dcm_AuthIdxLengthProofOfOwnershipClient_cu8 + 1u])) ;
}


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Sub-Service handler for proofOfOwnership */
Std_ReturnType Dcm_Prv_ProofOfOwnership (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType subServiceResult = E_NOT_OK;

    switch(OpStatus)
    {
        case DCM_CANCEL:
        Dcm_ProofOfOwnershipCancel(pMsgContext);
        subServiceResult = E_OK;
        break;

        case DCM_INITIAL:
        /* Synchronous Operations */
        subServiceResult = Dcm_ProofOfOwnershipInitial(pMsgContext, dataNegRespCode_u8);
        if (E_OK == subServiceResult)
        {
            Dcm_SrvOpstatus_u8= DCM_PROCESSSERVICE;
            /* No Break statement here as the PROCESSSERVICE shall continue immediately after the DCM_INITIAL is completed sucessfully */
            /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
        }
        else
        {
            break;
        }
        /* MR12 RULE 16.3 VIOLATION:The preceding 'switch' clause is not empty and does not end with a 'jump' statement. Execution will fall through. MISRA C:2012 Rule-16.3 */
        case DCM_PROCESSSERVICE:
        /* Asynchronous Operations */
        subServiceResult = Dcm_ProofOfOwnershipProcess(pMsgContext, dataNegRespCode_u8);
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

/* Synchronous Operations of the Sub-Service proofOfOwnership which needs to be executed before the first asynchronous operation */
static Std_ReturnType Dcm_ProofOfOwnershipInitial (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType initialResult = E_NOT_OK;

    if(DCM_ASYNCH_OPERATION_INACTIVE == Dcm_Prv_GetAuthAsynchOpStatus())
    {
        if(E_OK == Dcm_ProofOfOwnershipLengthCheck(pMsgContext, dataNegRespCode_u8))
        {
            if(Dcm_ProofOfOwnershipExpected_b)
            {
                initialResult = E_OK;
            }
            else
            {
                *dataNegRespCode_u8 = DCM_E_REQUESTSEQUENCEERROR;
            }
        }
    }
    Dcm_ProofOfOwnershipExpected_b = FALSE;

    return initialResult;
}

/* Asynchronous Operations of the Sub-Service proofOfOwnership. Also includes the synchronous operations which needs to be done after any asynchronous operation */
static Std_ReturnType Dcm_ProofOfOwnershipProcess (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType processResult = E_NOT_OK;
    Dcm_AuthAsynchOpStatusType_ten asynchOpStatus_en = Dcm_Prv_GetAuthAsynchOpStatus();

    switch(asynchOpStatus_en)
    {
        /* asynchOpStatus_en is set to DCM_ASYNCH_OPERATION_INACTIVE in Dcm_ProofOfOwnershipInitial().
         * So this will always be the case for the first call of Dcm_ProofOfOwnershipProcess() after the successful completion of Dcm_ProofOfOwnershipInitial() */
        case DCM_ASYNCH_OPERATION_INACTIVE:
        processResult = Dcm_VerifyProofOfOwnershipClientStart(pMsgContext, dataNegRespCode_u8);
        break;

        /* asynchOpStatus_en is set to DCM_ASYNCH_OPERATION_ACTIVE if the Csm asynchronous operation is started successfully.
         * Wait in this state until the callback from Csm is received indicating the successful completion of the asnychronous operation */
        case DCM_ASYNCH_OPERATION_ACTIVE:
        processResult = DCM_E_PENDING;
        break;

        /* asynchOpStatus_en is set to DCM_ASYNCH_OPERATION_COMPLETED if the Csm asyncronous operation is completed successfully */
        case DCM_ASYNCH_OPERATION_COMPLETED:
        processResult = Dcm_VerifyProofOfOwnershipClientCompleted(pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;
    }
    return processResult;
}

static void Dcm_ProofOfOwnershipCancel (const Dcm_MsgContextType* pMsgContext)
{
    uint16 authConnectionIndex_u16;
    uint32 jobId;

    if(DCM_ASYNCH_OPERATION_ACTIVE == Dcm_Prv_GetAuthAsynchOpStatus())
    {
        if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
        {
            jobId = Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].proofOfOwnershipClientVerifyJobId_u32;
            /* Ignore the return value from Csm as this information is not useful to Dcm
             * If the Csm_CancelJob returns E_NOT_OK (Request failed), Dcm will still proceed to cancel the service 0x29.
             * As ths AuthAsynchOpStatus is set to DCM_ASYNCH_OPERATION_INACTIVE, the callback from the Csm will be ignored by Dcm anyways. */
            (void)Csm_CancelJob(jobId,CRYPTO_OPERATIONMODE_SINGLECALL);
        }
    }
    Dcm_Prv_SetAuthAsynchOpStatus(DCM_ASYNCH_OPERATION_INACTIVE);
}

static Std_ReturnType Dcm_ProofOfOwnershipLengthCheck (const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType checkResult = E_NOT_OK;
    uint16 lengthProofOfOwnershipClient_u16 = Dcm_GetLengthProofOfOwnershipClient(pMsgContext);
    uint32 idxLengthEphemeralPublicKeyClient_u32 = (uint32)Dcm_AuthIdxProofOfOwnershipClient_cu8 + (uint32)lengthProofOfOwnershipClient_u16;
    uint16 lengthEphemeralPublicKeyClient_u16 = ( (((uint16) pMsgContext->reqData[idxLengthEphemeralPublicKeyClient_u32]) << 8u) | ((uint16) pMsgContext->reqData[idxLengthEphemeralPublicKeyClient_u32 + 1u]));
    uint32 expectedLength_u32 = (uint32)((uint16)Dcm_AuthSubFunctionSize_cu8 + (uint16)Dcm_AuthLengthProofOfOwnershipClientSize_cu8 + lengthProofOfOwnershipClient_u16 + (uint16)Dcm_AuthLengthEphemeralPublicKeyClientSize_cu8 + lengthEphemeralPublicKeyClient_u16);

    if(expectedLength_u32 == pMsgContext->reqDataLen)
    {
        if(lengthProofOfOwnershipClient_u16 == 0u)
        {
            *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
        else
        {
            checkResult = E_OK;
        }
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }

    return checkResult;
}


static Std_ReturnType Dcm_VerifyProofOfOwnershipClientStart (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchStartResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    uint32 jobId;
    uint16 lengthProofOfOwnershipClient_u16;
    uint8* challengeServer_pu8 = NULL_PTR;
    uint8** challengeServer_ppu8 = &challengeServer_pu8;
    uint32 lengthChallengeServer_u32 = 0;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        jobId = Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].proofOfOwnershipClientVerifyJobId_u32;
        lengthProofOfOwnershipClient_u16 = Dcm_GetLengthProofOfOwnershipClient(pMsgContext);

        /* Get the challenge server generated in the sub-service VerifyCertificate */
        Dcm_Prv_GetChallengeServer(challengeServer_ppu8, &lengthChallengeServer_u32);
        asynchStartResult = Csm_SignatureVerify(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, challengeServer_pu8, lengthChallengeServer_u32, &pMsgContext->reqData[Dcm_AuthIdxProofOfOwnershipClient_cu8], (uint32)lengthProofOfOwnershipClient_u16, &Dcm_AuthVerifyProofOfOwnershipClientResult);
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

static Std_ReturnType Dcm_VerifyProofOfOwnershipClientCompleted (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType asynchCompletedResult = E_NOT_OK;
    uint16 authConnectionIndex_u16;
    uint32 jobId;
    Dcm_NegativeResponseCodeType modeRuleNRC = 0;

    if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId, &authConnectionIndex_u16))
    {
        jobId = Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].proofOfOwnershipClientVerifyJobId_u32;
        if(E_OK == Dcm_VerifyProofOfOwnershipClientResult(jobId, dataNegRespCode_u8))
        {
            if (E_OK == Dcm_ReadRoleAndAvailableWhitelists(authConnectionIndex_u16, dataNegRespCode_u8))
            {
                Dcm_SetRoleAndAvailableWhitelists(authConnectionIndex_u16);
                Dcm_Prv_SetAuthState(authConnectionIndex_u16, DCM_AUTHENTICATED);

                pMsgContext->resData[Dcm_AuthIdxSubFunction_cu8] = (uint8)DCM_PROOF_OF_OWNERSHIP;
                pMsgContext->resData[Dcm_AuthIdxReturnParameter_cu8] = (uint8)DCM_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE;
                /* RTA-BSW Dcm does not support Session Key Info, so the length is set to 0 */
                pMsgContext->resData[Dcm_AuthIdxLengthSessionKeyInfo_cu8] = 0x00u;
                pMsgContext->resData[Dcm_AuthIdxLengthSessionKeyInfo_cu8 + 1u] = 0x00u;
                pMsgContext->resDataLen = Dcm_AuthIdxLengthSessionKeyInfo_cu8 + Dcm_AuthLengthSessionKeyInfoSize_cu8;

                if(Dcm_Cfg_AuthPersistentStateModeRule_pfct != NULL_PTR)
                {
                    if(TRUE == Dcm_Cfg_AuthPersistentStateModeRule_pfct(&modeRuleNRC))
                    {
                        Dcm_PersistAccessRights(authConnectionIndex_u16);
                    }
                }

                asynchCompletedResult = E_OK;
            }
        }
    }

    return asynchCompletedResult;
}


static Std_ReturnType Dcm_VerifyProofOfOwnershipClientResult (uint32 jobId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType signatureVerifyResult = E_NOT_OK;

    if(Dcm_Prv_GetCsmJobResult(jobId, dataNegRespCode_u8) == E_OK)
    {
        if (Dcm_AuthVerifyProofOfOwnershipClientResult == CRYPTO_E_VER_OK)
        {
            signatureVerifyResult = E_OK;
        }
        else
        {
            *dataNegRespCode_u8 = DCM_E_OWNERSHIPVERIFICATIONFAILED;
        }
    }

    return signatureVerifyResult;
}

static Std_ReturnType Dcm_ReadRoleAndAvailableWhitelists (uint16 authConnectionIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType readResult = E_OK;
    uint8 type_u8;
    KeyM_CertificateIdType certId = (KeyM_CertificateIdType)Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].certificateClientId_u16;
    Dcm_CertElementType_tst certElement_st = {  DCM_INVALID_CERT_ELEMENT,
                                                0u,
                                                NULL_PTR,
                                                NULL_PTR,
                                                0u,
                                                0u,
                                                0u,
                                                NULL_PTR,
                                                0u };

    /* Reset the temporary NumEntry to 0. Not neccessary to reset the TempData arrays and TempOffset array as they
     * will be overwritten and the access will be limited by the respective NumEntry(which will be updated accordingly) */
    Dcm_RoleTempDataNumEntry_u8 = 0u;
    Dcm_WhitelistServiceTempDataNumEntry_u8 = 0u;
    Dcm_WhitelistDIDTempDataNumEntry_u8= 0u;
    Dcm_WhitelistRIDTempDataNumEntry_u8 = 0u;
    Dcm_WhitelistMemSelnTempDataNumEntry_u8 = 0u;

    /* Loop over all the valid certificate element types in Dcm_CertElementType_ten */
    for (type_u8 = (uint8)DCM_ROLE; type_u8 < (uint8)DCM_NUM_CERT_ELEMENT_TYPE; type_u8++)
    {
        certElement_st.type_en = DCM_INVALID_CERT_ELEMENT;
        certElement_st.id_u16 = 0u;
        certElement_st.data_pau8 = NULL_PTR;
        certElement_st.dataLength_u8 = 0u;
        certElement_st.dataMaxLength_u8 = 0u;
        certElement_st.dataNumEntry_pu8 = NULL_PTR;
        certElement_st.childDataMaxLength_u8 = 0u;
        certElement_st.offset_pau8 = NULL_PTR;
        certElement_st.offsetLength_u8 = 0u;

        if(E_OK == Dcm_SetupCertElement(authConnectionIndex_u16, type_u8, &certElement_st))
        {
            if(E_NOT_OK == Dcm_ReadCertElement(certId, &certElement_st))
            {
                *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCONTENT;
                readResult = E_NOT_OK;
                break;
            }
        }
    }

    return readResult;
}

static Std_ReturnType Dcm_SetupCertElement(uint16 authConnectionIndex_u16, uint8 certElementType_u8, Dcm_CertElementType_tst* certElement_pst)
{
    Std_ReturnType setupCertElementResult = E_NOT_OK;

    switch (certElementType_u8)
    {
        case (uint8)DCM_ROLE:
        /* Role certificate element will always be available for every authConnectionIndex_u16 when Service 0x29 is configured */
        certElement_pst->type_en = DCM_ROLE;
        certElement_pst->id_u16 = Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].roleCertElementId_u16;
        certElement_pst->data_pau8 = &Dcm_RoleTempData_au8[0];
        certElement_pst->dataLength_u8 = 0u;
        certElement_pst->dataMaxLength_u8 = (uint8)DCM_CFG_AUTH_ROLE_SIZE;
        certElement_pst->dataNumEntry_pu8 = &Dcm_RoleTempDataNumEntry_u8;
        certElement_pst->childDataMaxLength_u8 = (uint8)DCM_CFG_AUTH_ROLE_SIZE;
        /* offset not needed for DCM_ROLE as there is only one child element expected */
        certElement_pst->offset_pau8 = NULL_PTR;
        certElement_pst->offsetLength_u8 = 0u;
        setupCertElementResult = E_OK;
        break;

        case (uint8)DCM_WHITELIST_SERVICE:
        if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistServiceCertElementId_pu16)
        {
            certElement_pst->type_en = DCM_WHITELIST_SERVICE;
            certElement_pst->id_u16 = *Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistServiceCertElementId_pu16;
            certElement_pst->data_pau8 = &Dcm_WhitelistServiceTempData_au8[0];
            certElement_pst->dataLength_u8 = 0u;
            certElement_pst->dataMaxLength_u8 = (uint8)DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE;
            certElement_pst->dataNumEntry_pu8 = &Dcm_WhitelistServiceTempDataNumEntry_u8;
            certElement_pst->childDataMaxLength_u8 = Dcm_WhitelistServiceChildMaxLength_cu8;
            /* offset is needed for DCM_WHITELIST_SERVICE as the size of each child element is not fixed (varies betwwen 1-Dcm_WhitelistServiceChildMaxLength_cu8 bytes) */
            certElement_pst->offset_pau8 = &Dcm_WhitelistServiceTempOffset_au8[0];
            certElement_pst->offsetLength_u8 = 0u;
            setupCertElementResult = E_OK;
        }
        break;

        case (uint8)DCM_WHITELIST_DID:
        if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistDIDCertElementId_pu16)
        {
            certElement_pst->type_en = DCM_WHITELIST_DID;
            certElement_pst->id_u16 = *Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistDIDCertElementId_pu16;
            certElement_pst->data_pau8 = &Dcm_WhitelistDIDTempData_au8[0];
            certElement_pst->dataLength_u8 = 0u;
            certElement_pst->dataMaxLength_u8 = (uint8)DCM_CFG_AUTH_WHITELIST_DID_MAX_SIZE;
            certElement_pst->dataNumEntry_pu8 = &Dcm_WhitelistDIDTempDataNumEntry_u8;
            certElement_pst->childDataMaxLength_u8 = Dcm_WhitelistDIDChildMaxLength_cu8;
            /* offset not needed for DCM_WHITELIST_DID as the size of each child element is fixed */
            certElement_pst->offset_pau8 = NULL_PTR;
            certElement_pst->offsetLength_u8 = 0u;
            setupCertElementResult = E_OK;
        }
        break;

        case (uint8)DCM_WHITELIST_RID:
        if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistRIDCertElementId_pu16)
        {
            certElement_pst->type_en = DCM_WHITELIST_RID;
            certElement_pst->id_u16 = *Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistRIDCertElementId_pu16;
            certElement_pst->data_pau8 = &Dcm_WhitelistRIDTempData_au8[0];
            certElement_pst->dataLength_u8 = 0u;
            certElement_pst->dataMaxLength_u8 = (uint8)DCM_CFG_AUTH_WHITELIST_RID_MAX_SIZE;
            certElement_pst->dataNumEntry_pu8 = &Dcm_WhitelistRIDTempDataNumEntry_u8;
            certElement_pst->childDataMaxLength_u8 = Dcm_WhitelistRIDChildMaxLength_cu8;
            /* offset not needed for DCM_WHITELIST_RID as the size of each child element is fixed */
            certElement_pst->offset_pau8 = NULL_PTR;
            certElement_pst->offsetLength_u8 = 0u;
            setupCertElementResult = E_OK;
        }
        break;

        case (uint8)DCM_WHITELIST_MEMSELN:
        if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistMemSelnCertElementId_pu16)
        {
            certElement_pst->type_en = DCM_WHITELIST_MEMSELN;
            certElement_pst->id_u16 = *Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistMemSelnCertElementId_pu16;
            certElement_pst->data_pau8 = &Dcm_WhitelistMemSelnTempData_au8[0];
            certElement_pst->dataLength_u8 = 0u;
            certElement_pst->dataMaxLength_u8 = (uint8)DCM_CFG_AUTH_WHITELIST_MEMSELN_MAX_SIZE;
            certElement_pst->dataNumEntry_pu8 = &Dcm_WhitelistMemSelnTempDataNumEntry_u8;
            certElement_pst->childDataMaxLength_u8 = Dcm_WhitelistMemSelnChildMaxLength_cu8;
            /* offset not needed for DCM_WHITELIST_MEMSELN as the size of each child element is fixed */
            certElement_pst->offset_pau8 = NULL_PTR;
            certElement_pst->offsetLength_u8 = 0u;
            setupCertElementResult = E_OK;
        }
        break;

        default:
        /*default should not happen*/
        break;
    }

    return setupCertElementResult;
}

static Std_ReturnType Dcm_ReadCertElement(KeyM_CertificateIdType certId, Dcm_CertElementType_tst* certElement_pst)
{
    Std_ReturnType readCertElementResult = E_NOT_OK;
    Dcm_AuthReadChildReturnType_ten readCertElementChildResult_en = READ_CERT_ELEMENT_CHILD_NOT_OK;
    KeyM_CertElementIteratorType certElementIterator;

    readCertElementChildResult_en = Dcm_ReadCertElementChild(certId, certElement_pst, DCM_READ_CERT_ELEMENT_FIRST, &certElementIterator);

    while(READ_CERT_ELEMENT_CHILD_OK_CONTINUE == readCertElementChildResult_en)
    /* The first/next Child element is read successfully. Further child elements available  */
    {
        readCertElementChildResult_en = Dcm_ReadCertElementChild(certId, certElement_pst, DCM_READ_CERT_ELEMENT_NEXT, &certElementIterator);
    }

    if(READ_CERT_ELEMENT_CHILD_NOT_AVAILABLE_STOP == readCertElementChildResult_en)
    /* All the available child elements read successfully. No further child available */
    {
        readCertElementResult = E_OK;
        if(DCM_ROLE == certElement_pst->type_en)
        {
            readCertElementResult = Dcm_CheckRoleLength(certElement_pst);
        }
    }

    return readCertElementResult;
}

static Dcm_AuthReadChildReturnType_ten Dcm_ReadCertElementChild(KeyM_CertificateIdType certId, Dcm_CertElementType_tst* certElement_pst, Dcm_CertElementInstanceType_ten certElementInstance_en, KeyM_CertElementIteratorType* certElementIterator)
{
    Dcm_AuthReadChildReturnType_ten readCertElementChildResult = READ_CERT_ELEMENT_CHILD_NOT_OK;
    Std_ReturnType keyMReadResult = E_NOT_OK;
    uint8 childData_au8[DCM_CERT_ELEMENT_CHILD_MAX_LENGTH] = {0u};
    uint32 childDataLength_u32 = (uint32)DCM_CERT_ELEMENT_CHILD_MAX_LENGTH;

    if(DCM_READ_CERT_ELEMENT_FIRST == certElementInstance_en)
    {
        keyMReadResult = KeyM_CertElementGetFirst(certId, (KeyM_CertElementIdType)certElement_pst->id_u16, certElementIterator, &childData_au8[0], &childDataLength_u32);
    }
    else
    {
        keyMReadResult = KeyM_CertElementGetNext(certElementIterator, &childData_au8[0], &childDataLength_u32);
    }

    if(E_OK == keyMReadResult)
    /* Child element read successfully */
    {
        if(E_OK == Dcm_CopyChildDataToElementData(certElement_pst, &childData_au8[0], (uint8)childDataLength_u32))
        /* The child element is valid. Continue reading the further child elements */
        {
            readCertElementChildResult = READ_CERT_ELEMENT_CHILD_OK_CONTINUE;
        }
        else
        /* The child element is Invalid. Stop the service and Send Negative response */
        {
            readCertElementChildResult = READ_CERT_ELEMENT_CHILD_NOT_OK;
        }
    }
    else if(E_NOT_OK == keyMReadResult)
    /* All the child elements read successfully. No more child elements available. Stop reading the further child elements */
    {
        readCertElementChildResult = READ_CERT_ELEMENT_CHILD_NOT_AVAILABLE_STOP;
    }
    else
    /* Error while reading the child element. Stop the service and Send Negative response */
    {
        readCertElementChildResult = READ_CERT_ELEMENT_CHILD_NOT_OK;
    }

    return readCertElementChildResult;
}

static Std_ReturnType Dcm_CopyChildDataToElementData(Dcm_CertElementType_tst* certElement_pst, const uint8* childData_pcau8, uint8 childDataLength_u8)
{
    Std_ReturnType copyChildDataResult = E_NOT_OK;
    uint8 idx_u8;

    if(E_OK == Dcm_CheckChildDataLength(certElement_pst, childDataLength_u8))
    {
        for(idx_u8 = 0u; idx_u8<childDataLength_u8; idx_u8++)
        {
            certElement_pst->data_pau8[certElement_pst->dataLength_u8] = childData_pcau8[idx_u8];
            certElement_pst->dataLength_u8++;
        }

        if(DCM_WHITELIST_SERVICE == certElement_pst->type_en)
        {
            certElement_pst->offset_pau8[certElement_pst->offsetLength_u8] = childDataLength_u8;
            certElement_pst->offsetLength_u8++;
        }

        (*certElement_pst->dataNumEntry_pu8)++;

        copyChildDataResult = E_OK;
    }

    return copyChildDataResult;
}

static Std_ReturnType Dcm_CheckChildDataLength(const Dcm_CertElementType_tst* certElement_pcst, uint8 childDataLength_u8)
{
    Std_ReturnType checkChildDataLengthResult = E_NOT_OK;
    boolean childDataLengthValid_b = FALSE;

    if(childDataLength_u8 <= (uint32)certElement_pcst->childDataMaxLength_u8)
    {
        if((DCM_WHITELIST_DID == certElement_pcst->type_en) || (DCM_WHITELIST_RID == certElement_pcst->type_en) || (DCM_WHITELIST_MEMSELN == certElement_pcst->type_en))
        {
            if(childDataLength_u8 == (uint32)certElement_pcst->childDataMaxLength_u8)
            {
                childDataLengthValid_b = TRUE;
            }
        }
        else
        {
            childDataLengthValid_b = TRUE;
        }
    }

    if(childDataLengthValid_b)
    {
        if((certElement_pcst->dataLength_u8 + childDataLength_u8) <= certElement_pcst->dataMaxLength_u8)
        {
            checkChildDataLengthResult = E_OK;
        }
    }

    return checkChildDataLengthResult;
}

static Std_ReturnType Dcm_CheckRoleLength(const Dcm_CertElementType_tst* certElement_pcst)
{
    Std_ReturnType checkRoleLengthResult = E_NOT_OK;

    if(certElement_pcst->dataLength_u8 == certElement_pcst->dataMaxLength_u8)
    {
        checkRoleLengthResult = E_OK;
    }

    return checkRoleLengthResult;
}

static void Dcm_SetRoleAndAvailableWhitelists(uint16 authConnectionIndex_u16)
{
    Dcm_Prv_SetRole(authConnectionIndex_u16, &Dcm_RoleTempData_au8[0]);

    if(Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistServiceCertElementId_pu16 != NULL_PTR)
    {
        Dcm_Prv_SetWhitelist(authConnectionIndex_u16, DCM_WHITELIST_SERVICE, &Dcm_WhitelistServiceTempData_au8[0], Dcm_WhitelistServiceTempDataNumEntry_u8, &Dcm_WhitelistServiceTempOffset_au8[0]);
    }

    if(Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistDIDCertElementId_pu16 != NULL_PTR)
    {
        Dcm_Prv_SetWhitelist(authConnectionIndex_u16, DCM_WHITELIST_DID, &Dcm_WhitelistDIDTempData_au8[0], Dcm_WhitelistDIDTempDataNumEntry_u8, NULL_PTR);
    }

    if(Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistRIDCertElementId_pu16  != NULL_PTR)
    {
        Dcm_Prv_SetWhitelist(authConnectionIndex_u16, DCM_WHITELIST_RID, &Dcm_WhitelistRIDTempData_au8[0], Dcm_WhitelistRIDTempDataNumEntry_u8, NULL_PTR);

    }

    if(Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistMemSelnCertElementId_pu16  != NULL_PTR)
    {
        Dcm_Prv_SetWhitelist(authConnectionIndex_u16, DCM_WHITELIST_MEMSELN, &Dcm_WhitelistMemSelnTempData_au8[0], Dcm_WhitelistMemSelnTempDataNumEntry_u8, NULL_PTR);
    }
}

void Dcm_Prv_SetProofOfOwnershipExpected(boolean proofOfOwnershipExpected_b)
{
    Dcm_ProofOfOwnershipExpected_b = proofOfOwnershipExpected_b;
}

static void Dcm_PersistAccessRights(uint16 authConnectionIndex_u16)
{
    (void)Dcm_WriteAccessRights(authConnectionIndex_u16, (uint8)DCM_ROLE, &Dcm_RoleTempData_au8[0], &Dcm_RoleTempDataNumEntry_u8, NULL_PTR);

    if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistServiceCertElementId_pu16)
    {
        (void)Dcm_WriteAccessRights(authConnectionIndex_u16, (uint8)DCM_WHITELIST_SERVICE, &Dcm_WhitelistServiceTempData_au8[0], &Dcm_WhitelistServiceTempDataNumEntry_u8, &Dcm_WhitelistServiceTempOffset_au8[0]);
    }

    if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistDIDCertElementId_pu16)
    {
        (void)Dcm_WriteAccessRights(authConnectionIndex_u16, (uint8)DCM_WHITELIST_DID, &Dcm_WhitelistDIDTempData_au8[0], &Dcm_WhitelistDIDTempDataNumEntry_u8, NULL_PTR);
    }

    if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistRIDCertElementId_pu16)
    {
        (void)Dcm_WriteAccessRights(authConnectionIndex_u16, (uint8)DCM_WHITELIST_RID, &Dcm_WhitelistRIDTempData_au8[0], &Dcm_WhitelistRIDTempDataNumEntry_u8, NULL_PTR);
    }

    if(NULL_PTR != Dcm_Cfg_AuthConnection_acst[authConnectionIndex_u16].whitelistMemSelnCertElementId_pu16)
    {
        (void)Dcm_WriteAccessRights(authConnectionIndex_u16, (uint8)DCM_WHITELIST_MEMSELN, &Dcm_WhitelistMemSelnTempData_au8[0], &Dcm_WhitelistMemSelnTempDataNumEntry_u8, NULL_PTR);
    }
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif /* (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)  */
