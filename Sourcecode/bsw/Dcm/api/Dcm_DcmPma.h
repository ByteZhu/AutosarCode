#ifndef DCM_DCMPMA_H
#define DCM_DCMPMA_H

/***********************************************************************************************************************
*                                 Defines
***********************************************************************************************************************/

/* Location of default session ID in session array table */
#define DCM_DEFAULT_SESSION_IDX                        0x00u

/***********************************************************************************************************************
*                                 Function Declaration
***********************************************************************************************************************/
Dcm_DsdStatesType_ten Dcm_Dsd_Prv_GetDsdState(void);
Dcm_SesCtrlType Dcm_Prv_GetActiveSession(void);
Dcm_SesCtrlType Dcm_Prv_GetSession(uint8 SessionIdx_u8);
void Dcm_Prv_SetSesCtrlType (Dcm_SesCtrlType SesCtrlType_u8);
const Dcm_DsdServiceTableConfigType_tst* Dcm_Prv_GetServiceTable(void);
PduIdType Dcm_Prv_GetActiveTxPduId(void);
Dcm_ProtocolType Dcm_Prv_GetActiveProtocolType(void);
Dcm_MsgContextType Dcm_Dsd_Prv_GetUdsMsgContext(void);
Std_ReturnType Dcm_Dsl_Prv_CancelOnGoingTransmission(PduIdType activeTxPduId, uint8 activeProtocol_u8);
void Dcm_Dsd_Prv_ServiceInit(uint8 ServiceTableIndex_u8);
void Dcm_Prv_SetServiceTable(uint8 srvTabId);
void Dcm_Prv_Det(uint8 DCM_ApiId,uint8 DCM_ErrorId);
void Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest(void);

#endif//DCM_EXTERNALS_H
