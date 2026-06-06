#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

void Dcm_Dsl_Init(const Dcm_ConfigType* ConfigPtr)
{
    PduIdType rxPduId;
    (void)ConfigPtr;

    /* Initialize DSL and Preemption state */
    Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
    Dcm_Dsl_Prv_SetPreemptionState(DSL_PREEMPTION_STATE_IDLE_E);
    Dcm_Dsl_Prv_SetRespPendingCounterValue(DCM_DEFAULT_VALUE);
    Dcm_Prv_SetProtocolStatus(FALSE);
    Dcm_Prv_NoActiveProtocol();
    Dcm_Prv_SetHighPrioPduid(DCM_CFG_INVALID_RX_PDUID);
    Dcm_Prv_SetLowPrioNrc21RxPduId(DCM_CFG_INVALID_RX_PDUID);
    Dcm_Prv_SetInfinitePendingFlag(FALSE);
    Dcm_Dsl_SetForcePendingFlag(FALSE);
    Dcm_Dsl_Prv_isRetryTransmission(NULL_PTR,FALSE);
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
    Dcm_Prv_ResetObdActiveRxPduId();
    Dcm_OBDGlobal_st.flgCommActive_b = FALSE;
    Dcm_OBDGlobal_st.idxCurrentProtocol_u8 = 0x00;
    Dcm_OBDGlobal_st.nrActiveConn_u8 = 0x00u;
    Dcm_OBDSrvOpstatus_u8 = DCM_INITIAL;
    Dcm_OBDExtSrvOpStatus_u8 = DCM_INITIAL;
    Dcm_ObdSendTxConfirmation_b = FALSE;
#endif

    Dcm_Prv_SetActiveSessionIdx(DCM_DEFAULT_SESSION_IDX );
    Dcm_Prv_SetActiveSecurityLevelIdx(DCM_SEC_LEV_LOCKED);

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    Dcm_CurOBDProtocol_u8 = DCM_NO_ACTIVE_PROTOCOL;
#endif

    for(rxPduId=0 ; rxPduId < DCM_CFG_TOTAL_RX_PDUID; rxPduId++)
    {
        Dcm_ReceptionInfo_ast[rxPduId].Dcm_FuncTesterPresent_b = FALSE;
        Dcm_ReceptionInfo_ast[rxPduId].Dcm_RequestProcessingFlag_b = FALSE;
        Dcm_ReceptionInfo_ast[rxPduId].Dcm_RxPduId = DCM_CFG_INVALID_RX_PDUID;
        Dcm_ReceptionInfo_ast[rxPduId].Dcm_ServiceId_u8 = DCM_DSP_SID_INVALID;
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
        Dcm_DslOBDRxPduArray_ast[rxPduId].Dcm_DslCopyRxData_b = FALSE;
        Dcm_DslOBDRxPduArray_ast[rxPduId].Dcm_RxPduId = DCM_CFG_INVALID_RX_PDUID;
        Dcm_DslOBDRxPduArray_ast[rxPduId].Dcm_DslServiceId_u8 = DCM_DSP_SID_INVALID;
#endif
    }
}

void Dcm_Dsl_Main(void)
{
    if(Dcm_Dsd_Prv_GetDsdState() == DSD_SENDTXCONF_APPL_E)
    {
        Dcm_Dsd_Prv_SendTx_Confirmation();
        Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest();
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
        Dcm_Prv_ProcessRequestInQueue();
#endif
    }
    /* Check if the application has requested for switching to the default session */
    Dcm_Prv_ProcessResetToDefaultSession();

#if(DCM_CFG_RDPI_ENABLED == DCM_CFG_ON)
    Dcm_RdpiMainFunction();
#endif

    Dcm_Dsl_Prv_CheckFor_ProtocolPreemption();
    Dcm_Dsl_Prv_StateMachine();

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_AuthTimerHandling(DCM_TIMER_PROCESS,(PduIdType)0x00);
#endif
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
