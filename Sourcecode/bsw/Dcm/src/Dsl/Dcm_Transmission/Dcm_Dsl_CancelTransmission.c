#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"
#include "Rte_Dcm.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3312] */
Std_ReturnType Dcm_Dsl_Prv_CancelOnGoingTransmission(PduIdType activeTxPduId, uint8 activeProtocol_u8)
{
    /* Local variables */
    Dcm_DslStatesType_ten dslState;                         /* To copy the DSL state */
    Dcm_DsdStatesType_ten dsdState;                         /* To copy the DSD state */
    Std_ReturnType CancelTransmitResult = E_OK;         /* To store the CancelTransmit return value */
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    uint8 Sid_u8;                                           /* To store the service ID */
    boolean IsPagedBufferTransmissionInProgress_b = FALSE;  /* Flag used to validate the pagedbuffer transmission */
    const Dcm_MsgItemType * RequestBuffer = Dcm_Prv_GetActiveRxBuffer();
    IsPagedBufferTransmissionInProgress_b = Dcm_Prv_Get_PagedBufferTxOn();
#endif

    /*Multicore: Lock added here to ensure that the DSL, DSD states are updated together here.
      The active request should not modify the state machine variables separately only during
      this protocol pre-emption scenario*/
    /* BSWEXT-533 */
    SchM_Enter_Dcm_Global();
    dslState = Dcm_Dsl_Prv_GetDslState();
    dsdState = Dcm_Dsd_Prv_GetDsdState();
    /* BSWEXT-533 */
    SchM_Exit_Dcm_Global();

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    if((DSL_STATE_WAITFOR_TXCONFIRMATION_E == dslState)||(IsPagedBufferTransmissionInProgress_b!= FALSE))
#else

    if((DSL_STATE_WAITFOR_TXCONFIRMATION_E == dslState)|| \
            ((DSD_WAITFORTXCONF_E == dsdState) && (dslState == DSL_STATE_ROETYPE1_RECEIVED_E)))
#endif
    {
        /* Set the status to Cancel the transmission */
        Dcm_IsCancelTransmitInvoked_b = TRUE;
    }

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    if(TRUE == IsPagedBufferTransmissionInProgress_b)
    {
        /* Set the status to Cancel the transmission */
        Dcm_IsCancelTransmitInvoked_b = TRUE;
        Sid_u8 = RequestBuffer[0];
        DcmAppl_DcmCancelPagedBufferProcessing(Sid_u8);
    }
#endif
    /* If Cancellation of transmission is needed */
    if(TRUE == Dcm_IsCancelTransmitInvoked_b)
    {
        /* Call the PduR API to cancel the initiated Transmission */
        CancelTransmitResult = PduR_DcmCancelTransmit(activeTxPduId);
        if(E_NOT_OK == CancelTransmitResult)
        {
            Dcm_StopProtocol(activeProtocol_u8,Dcm_Prv_GetCurrentTesterSourceAddress(),Dcm_Prv_GetCurrentConnectionID());
            Dcm_IsCancelTransmitInvoked_b = FALSE;
        }
    }
    return CancelTransmitResult;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
