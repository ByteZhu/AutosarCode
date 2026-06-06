#ifndef DCM_PRV_DSL_H
#define DCM_PRV_DSL_H
#include "Dcm_Prv_Dsl_Reception.h"
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
#define DCM_OBDCONTEXT                      TRUE /*used to indicate processing for OBD in case of parallel processing*/
#define DCM_UDSCONTEXT                      FALSE

/* Mask value which will be varied depending on active session/security */
#define DCM_DEFAULT_MASKVALUE               0x00000001uL
#define DCM_SID_DIAGNOSTICSESSIONCONTROL    (0x10u)
#define DCM_SERVICEID_ADDEND           (0x40u)

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const PduIdType Dcm_TxTable_cast[DCM_CFG_PDUIDTABLE_TX_LENGTH];
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

extern void Dcm_Prv_SetSecurityLevel (Dcm_SecLevelType dataSecurityLevel_u8);

#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF) )
void Dcm_Prv_SetNewSession(void);
#endif

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
extern PduInfoType Dcm_Dsl_Respone_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#if(DCM_CFG_RDPI_ENABLED!=DCM_CFG_OFF)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern void Dcm_DsldPeriodicScheduler(void);
extern void Dcm_RdpiMainFunction(void);
extern void Dcm_DsldPeriodicSchedulerIni(void);
extern void Dcm_GetRdpiType2Index(uint8 * idxRdpi2TxPduId_u8);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
extern Dcm_OBDStateMachine_tst Dcm_OBDState_en;
extern Dcm_OBDStateMachine_tst Dcm_OBD_PreviousState;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_DslOBDRxPduArray_tst Dcm_DslOBDRxPduArray_ast[DCM_CFG_TOTAL_RX_PDUID];
extern Dcm_OBDInternalStructureType_tst Dcm_OBDGlobal_st;
extern PduInfoType Dcm_OBDPduInfo_st;
extern Dcm_OBDTxType_tst Dcm_OBDTransmit_st;
extern const Dcm_DsdServiceTableConfigType_tst* Dcm_OBDSrvTable_pcst;
extern Dcm_MsgContextType Dcm_OBDMsgContext_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern boolean Dcm_ObdSendTxConfirmation_b;
extern boolean Dcm_OBDisGeneralRejectSent_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
extern uint8 Dcm_CurOBDProtocol_u8;
extern uint8 stObdSubState_en;
extern Dcm_SrvOpStatusType Dcm_OBDSrvOpstatus_u8;
extern Dcm_SrvOpStatusType Dcm_OBDExtSrvOpStatus_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

/* Sub State Machine definitions for OBD */
#define OBDSUBSTATE_SERVICETABLE_INI           (0x00u)
#define OBDSUBSTATE_MANUFACTURER_NOTIFICATION  (0x01u)
#define OBDSUBSTATE_VERIFYDATA                 (0x02u)
#define OBDSUBSTATE_SUPPLIER_NOTIFICATION      (0x03u)

#define Dcm_Prv_SetOBDState(ObdState) (Dcm_OBDState_en = ObdState)
#define Dcm_Prv_GetOBDState()         (Dcm_OBDState_en)
/* To Reset OBD SubState Machine */
#define Dcm_ResetOBDSubStateMachine() (stObdSubState_en = OBDSUBSTATE_SERVICETABLE_INI)
/* Store OBD state , needed for handling Pending Transmission use case */
#define Dcm_Prv_SetOBDPreviousState() (Dcm_OBD_PreviousState = Dcm_OBDState_en)
#define Dcm_Prv_GetOBDPreviousState() (Dcm_OBD_PreviousState)

#if (DCM_CFG_OSTIMER_USE != FALSE)
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_P2OrS3StartTick_u32;
extern uint32 Dcm_OBDP2OrS3StartTick_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#endif

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
extern Dcm_QueueStructure_tst Dcm_QueueStructure_st;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

/****************/

/*
 **********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************
 */
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern void Dcm_Dsl_Init(const Dcm_ConfigType* ConfigPtr);
extern void Dcm_Dsl_Main(void);
void Dcm_Dsl_Prv_CheckFor_ProtocolPreemption(void);
void Dcm_Dsl_Prv_StateMachine(void);
Std_ReturnType Dcm_Prv_SendForcePendingResponse(void);
Std_ReturnType Dcm_Dsl_Prv_VerifySecurityAccess(const uint32 allowedSecurity_u32,
                                                Dcm_NegativeResponseCodeType *negativeResponseCode);
Std_ReturnType Dcm_Dsl_Prv_VerifySessionAccess(const uint32 allowedSessions_u32);
uint32 Dcm_Dsl_Prv_GetActiveSecurityLevelBitwise(void);
void Dcm_Prv_TriggerTransmit(PduLengthType Sdulength);
void Dcm_Dsl_SetForcePendingFlag(boolean value);
#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF) && (DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
boolean Dcm_Prv_isKWPSplitResponseTimeout(void);
#endif
void Dcm_Prv_InactivateComMChannel(void);
uint8 Dcm_Dsl_Prv_GetRespPendingCounterValue(void);
void Dcm_Dsl_Prv_SetDslState(Dcm_DslStatesType_ten DslState_en);
void Dcm_Prv_NoActiveProtocol(void);
void Dcm_Prv_SetInfinitePendingFlag(boolean value);
boolean Dcm_Prv_GetInfinitePendingFlag(void);
uint8 Dcm_Prv_GetCurrentProtocol(void);
uint16 Dcm_Prv_GetCurrentTesterSourceAddress(void);
uint16 Dcm_Prv_GetCurrentConnectionID(void);
void Dcm_Prv_SetCurrentProtocol(uint8 Dcm_ActiveProtocol);
Dcm_DslStatesType_ten Dcm_Dsl_Prv_GetDslState(void);
Dcm_DslSubStatesType_ten Dcm_Dsl_Prv_GetDslSubState(void);
void Dcm_Dsl_Prv_SetDslSubState(Dcm_DslSubStatesType_ten DslSubState_en);
void Dcm_Dsl_Prv_SetPreemptionState(Dcm_DslProtocolPreemptionStatesType_ten dslPreemptionState_en);
Dcm_DslProtocolPreemptionStatesType_ten Dcm_Dsl_Prv_GetPreemptionState(void);
void Dcm_Dsl_Prv_SetRespPendingCounterValue(uint8 RespPendingCounter_u8);
Dcm_SesCtrlType Dcm_Prv_GetActiveSession(void);
void Dcm_Prv_SetSesCtrlType (Dcm_SesCtrlType SesCtrlType_u8);
void Dcm_Prv_SendResponse(const PduInfoType * PduInfoPcst);
void Dcm_Dsl_Prv_isRetryTransmission(const PduInfoType * retryRespTransission_pcst, boolean retryTransmission_b);
boolean Dcm_Dsl_Prv_isItPendingResponse(void);
void Dcm_Dsl_Prv_SetPendingResponse(boolean pendingResponseStatus);
Std_ReturnType Dcm_Dsl_Prv_CancelOnGoingTransmission(PduIdType activeTxPduId, uint8 activeProtocol_u8);
void Dcm_Dsl_Prv_SendPendingResponse(void);
void Dcm_Dsl_Prv_ConfirmationForCurrentResponse (Std_ReturnType Result);
extern uint32 Dcm_DsldGetActiveSessionMask_u32 (void);
extern uint32 Dcm_DsldGetActiveSecurityMask_u32 (void);
extern uint32 Dcm_GetSignal_u32(uint8 xDataType_u8,
                                   uint16 posnStart_u16,
                                   const uint8 * adrReqBuffer_u8,
                                    uint8 dataEndianness_u8);

extern void Dcm_StoreSignal(uint8 xDataType_u8,
                                    uint16 posnStart_u16,
                                    uint8 * adrRespBuffer_u8,
                                    uint32 dataSignalValue_u32,
                                    uint8 dataEndianness_u8);

#if (DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF)
extern void Dcm_RCSetDataInArray(const Dcm_RoutineSignalConfigType_tst * targetSignalConfig_pcst, const uint8 * sourceBuffer_pau8);
extern void Dcm_RCCopyDataOutArrayToResponse(const Dcm_RoutineSignalConfigType_tst * sourceSignalConfig_pcst,uint8 * targetBuffer_pau8);
#endif

extern void (*Dcm_adrUpdatePage_pfct) (
                                                 Dcm_MsgType PageBufPtr,
                                                 Dcm_MsgLenType PageLen
                                               );
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
extern boolean Dcm_Prv_CheckTotalResponseLength(Dcm_MsgLenType TotalResLen_u32 );
extern void Dcm_Prv_Set_RemainingPageLength(PduLengthType RemainingPageLen);
extern void Dcm_Prv_Get_RemainingPageLength(PduLengthType *RemainingPageLen);
extern boolean Dcm_Prv_Get_PagedBufferTxOn(void);
extern void Dcm_Prv_Set_PagedBufferTxOn(boolean pagedBufferTxOn_b);
extern void Dcm_Prv_Set_dataCurrentPageRespLength_u32(uint32 dataCurrentPageRespLength_u32);
uint32 Dcm_Prv_Get_dataCurrentPageRespLength_u32(void);
void Dcm_Prv_Reset_dataCurrentPageRespLength_u32(void);
uint32 Dcm_Prv_Get_DataPagedBufferTimeOut(void);
void Dcm_Prv_Set_DataPagedBufferTimeOut(uint32 dataPagedBufferTimeOutMonitor_u32);
void Dcm_Prv_PagedBufferInit(void);
#endif

extern void Dcm_CheckActiveDiagnosticStatus(uint8 dataNetworkId);
extern void Dcm_DslDsdWarmStart(void);
extern uint8 Dcm_GetActiveConnectionIdx_u8(void);
extern void Dcm_JumpToBootLoader(uint8 dataBootType_u8, Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
extern void Dcm_ResetBootLoader(void);
extern boolean Dcm_Prv_isProtocolStarted(void);
extern void Dcm_Prv_ConfirmationRespPendForBootloader(Dcm_ConfirmationStatusType Status_u8);

extern void Dcm_Prv_SetActiveSecurityLevelIdx(uint8 SecurityLevelIdx_u8);
extern uint8 Dcm_Prv_GetActiveSecurityLevelIdx(void);

extern void Dcm_DsldSetsessionTiming(uint32 nrP2StarMax_u32,uint32 nrP2Max_u32);
extern void Dcm_Prv_ResetDefaultSessionRequestFlag(void);
extern void Dcm_Prv_ProcessResetToDefaultSession(void);
extern void Dcm_Prv_SetSessionStoreFlag(boolean Value);
extern void Dcm_Prv_SetActiveSessionIdx(uint8 SessionIdx_u8);
extern uint8 Dcm_Prv_GetActiveSessionIdx(void);
extern void Dcm_Prv_SetPreviousSessionIdx(uint8 SessionIdx_u8);
extern uint8 Dcm_GetPreviousSessionIdx(void);
extern Dcm_SesCtrlType Dcm_Prv_GetSession(uint8 SessionIdx_u8);

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
extern void Dcm_Prv_ResetOBDCopyRxDataStatus(PduIdType id);
extern boolean Dcm_Prv_IsTxPduIdOBD(PduIdType DcmTxPduId);
extern boolean Dcm_Prv_IsRxPduIdOBD(PduIdType DcmRxPduId);
#endif

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
extern Dcm_MsgItemType* Dcm_Prv_ProvideFreeBuffer(PduIdType DcmRxPduId,boolean isQueuedReq_b);
extern void Dcm_Prv_ProcessRequestInQueue(void);
#endif

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
extern void Dcm_KWPConfirmationForSplitResp(Dcm_ConfirmationStatusType status);
#endif
/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif
