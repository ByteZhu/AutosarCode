

#ifndef DCMDSPUDS_PRV_AUTHENTICATION_H
#define DCMDSPUDS_PRV_AUTHENTICATION_H

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/
extern const uint8 Dcm_AuthSubFunctionSize_cu8;
extern const uint8 Dcm_AuthIdxSubFunction_cu8;
extern const uint8 Dcm_AuthIdxReturnParameter_cu8;

extern Std_ReturnType Dcm_Prv_VerifyCertificate (Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
extern Std_ReturnType Dcm_Prv_ProofOfOwnership (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
extern void Dcm_Prv_AuthenticationNRCHandling (Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
extern void Dcm_Prv_GetChallengeServer(uint8** challengeServer_ppu8, uint32* lengthChallengeServer_pu32);
extern Std_ReturnType Dcm_Prv_GetCsmJobResult(uint32 jobId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
extern Std_ReturnType Dcm_Prv_GetKeyMVerifyCertificateResult(KeyM_CertificateIdType certId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
extern void Dcm_Prv_CertificateInvalidNRCHandling(KeyM_CertificateStatusType certStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
extern Dcm_AuthAsynchOpStatusType_ten Dcm_Prv_GetAuthAsynchOpStatus(void);
extern void Dcm_Prv_SetAuthAsynchOpStatus(Dcm_AuthAsynchOpStatusType_ten asynchOpStatus_en);
extern void Dcm_Prv_SetProofOfOwnershipExpected(boolean proofOfOwnershipExpected_b);
extern void Dcm_Prv_VerifyCertificateStateIni(void);

#endif   /* (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON) */

/* DCMDSPUDS_PRV_AUTHENTICATION_H */
#endif
