
#ifndef DCM_DSL_H
#define DCM_DSL_H
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
#include "KeyM.h"
#include "Csm.h"
#endif
/*
 * ********************************************************************************************************************
 * Included header files
 **********************************************************************************************************************
 */


BufReq_ReturnType Dcm_StartOfReception(PduIdType id, const PduInfoType* info, PduLengthType TpSduLength,
        PduLengthType* bufferSizePtr);

BufReq_ReturnType Dcm_CopyRxData(PduIdType id, const PduInfoType* info, PduLengthType* bufferSizePtr);

void Dcm_TpRxIndication(PduIdType id, Std_ReturnType result);

BufReq_ReturnType Dcm_CopyTxData(PduIdType id, const PduInfoType* info, const RetryInfoType* retry,
        PduLengthType* availableDataPtr);

void Dcm_TpTxConfirmation(PduIdType id, Std_ReturnType result);
void Dcm_TxConfirmation (PduIdType TxPduId, Std_ReturnType result);

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
extern Std_ReturnType Dcm_KeyMAsyncCertificateVerifyFinished(KeyM_CertificateIdType certId, KeyM_CertificateStatusType result);
extern void Dcm_CsmAsyncJobFinished(uint32 jobId, Crypto_ResultType result);
#endif

Std_ReturnType Dcm_SesCtrlChangeIndication(Dcm_SesCtrlType dataSesCtrlTypeOld_u8,Dcm_SesCtrlType dataSesCtrlTypeNew_u8);

#if(DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
void Dcm_Prv_SetOBDNegResponse(const Dcm_MsgContextType* pMsgContext,Dcm_NegativeResponseCodeType ErrorCode);
boolean Dcm_Prv_CanComMBeInactivated(boolean Context);
void Dcm_Prv_ConfirmationToOBDApl(void);
void Dcm_Prv_OBDTimerProcessing(void);
void Dcm_Prv_OBDStateMachine(void);
void Dcm_Prv_OBDSendResponse(const PduInfoType* adrPduStrucutre_pcst);
#endif

#endif
