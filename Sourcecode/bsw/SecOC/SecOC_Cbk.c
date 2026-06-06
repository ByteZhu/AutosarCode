/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"
#include "SecOC_Prv.h"

/*
 **********************************************************************************************************************
 * Local functions
 **********************************************************************************************************************
*/
    
static void SecOC_Prv_TxCallback(PduIdType configIndex_uo, Std_ReturnType csmResult_en);
    
static void SecOC_Prv_RxCallback(PduIdType configIndex_uo, Std_ReturnType csmResult_en);

void SecOCTxPduProcessing_TxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en);

void IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en);
void IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en);
void IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en);
void IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en);

    

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"

/**
 ***************************************************************************************************
 * SecOC_Prv_TxCallback
 *
 * The function is called by Csm to notifiy that the authentication is finished.
 * To identify the corresponding csm job the identifier of the csm job is given.
 * If the authentication was sucessful csmResult_en is E_OK otherwise it is E_NOT_OK.
 *
 * \param[in]   configIndex_uo    index of the context buffer for the authentic pdu
 * \param[in]   csmResult_en      result of the authentication
 *
 ***************************************************************************************************
 */
static void SecOC_Prv_TxCallback(PduIdType configIndex_uo, Std_ReturnType csmResult_en)
{
    /* TRACE[SWS_SecOC_00012]: provide callback functions for asynchonous call of CSM interface */
    SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst;
    SecOC_Prv_TxSecuredPduState_tu8 state_u8 = SecOC_Prv_TxSecuredContextBufferGetState(configIndex_uo);

    if (SECOC_TX_STATE_WAIT_FOR_CSM_CALLBACK_E == state_u8)
    {
        txSecuredPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(configIndex_uo);
        if (NULL_PTR != txSecuredPduCtx_pst)
        {
            if (E_OK == csmResult_en)
            {
                /**
                  * TRACE[SWS_SecOC_00061], TRACE[SWS_SecOC_00066], TRACE[SWS_SecOC_00071]:
                  * create and forward secured PDU or PDU collection
                  */
                if(FALSE == txSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.pduColl_b)
                {
                    SecOC_Prv_createSecPdu(txSecuredPduCtx_pst,
                                           txSecuredPduCtx_pst->pduConfig_pst->authenticator_pu8);
                }
                else
                {
                    SecOC_Prv_createPduCollection(txSecuredPduCtx_pst,
                                                  txSecuredPduCtx_pst->pduConfig_pst->authenticator_pu8);
                }
            }
            else
            {
                if (SecOC_Prv_CheckAuthenticationResult(txSecuredPduCtx_pst, csmResult_en))
                {
                    /* TRACE[SWS_SecOC_00166]|Det disabled */
                }
            }
            /* no pending callback so clear it */
            SecOC_Prv_TxCbkPending_au8[configIndex_uo] = SECOC_PRV_NO_PENDING_CALLBACK;
            /* unlock context buffer if it is locked in this callback */
            SecOC_Prv_TxSecuredContextBufferRelease(&txSecuredPduCtx_pst);
        }
        else
        {
            /* callback while context buffer is locked */
            SecOC_Prv_TxCbkPending_au8[configIndex_uo] = csmResult_en;
        }
    }
    else
    {
        /* callback while state not proper */
        SecOC_Prv_TxCbkPending_au8[configIndex_uo] = csmResult_en;
    }
}


/**
 ***************************************************************************************************
 * SecOCTxPduProcessing_TxCallback
 *
 * The function is called by Csm to notifiy that the authentication is finished.
 * To identify the corresponding csm job the identifier of the csm job is given.
 * If the authentication was sucessful csmResult_en is E_OK otherwise it is E_NOT_OK.
 *
 * \param[in]   jobId_u32      the job id of the job that completed
 * \param[in]   csmResult_en   result of the authentication
 *
 ***************************************************************************************************
 */
void SecOCTxPduProcessing_TxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en)
{
    (void)jobId_u32;
    /* TRACE[SWS_SecOC_00012]: provide callback functions for asynchonous call of CSM interface */
    SecOC_Prv_TxCallback(SECOC_PRV_SECOCTXPDUPROCESSING_TX_CONFIG_INDEX, csmResult_en);
}

/**
 ***************************************************************************************************
 * The function is called by Csm to notifiy that the verification is finished.
 * To identify the corresponding csm job the identifier of the csm job is given.
 * If the verification was sucessful csmResult_en is E_OK otherwise it is E_NOT_OK.
 *
 * \param[in]   configIndex_uo  Configuration index of the pdu that completed a callback.
 *                              For Rx PDUs this is the secured PDU Id generated by the SecOC
 *                              Forwarder.
 * \param[in]   csmResult_en    result of the verification
 *
 ***************************************************************************************************
 */
static void SecOC_Prv_RxCallback(PduIdType configIndex_uo, Std_ReturnType csmResult_en)
{
    /* TRACE[SWS_SecOC_00012]: provide callback functions for asynchonous call of CSM interface */
    SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst;
    boolean detErrorCall_b = FALSE;
    SecOC_Prv_RxAuthenticPduState_tu8 state_u8 = SecOC_Prv_RxAuthenticContextBufferGetState(configIndex_uo);

    if (SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E == state_u8)
    {
        rxPduCtx_pst  = SecOC_Prv_RxAuthenticContextBufferAllocate(configIndex_uo);
        if (NULL_PTR != rxPduCtx_pst)
        {
            rxPduCtx_pst->status_u8 = SECOC_RX_STATE_MAC_VERIFY_FINISHED_E;
            detErrorCall_b = SecOC_Prv_HandleVerificationResult(rxPduCtx_pst, csmResult_en);
            if (FALSE != detErrorCall_b)
            {
                /* TRACE[SWS_SecOC_00166]|Det disabled */
            }
            /* no pending callback so clear it */
            SecOC_Prv_RxCbkPending_au8[configIndex_uo] = SECOC_PRV_NO_PENDING_CALLBACK;
            /* unlock context buffer if it is locked in this callback */
            SecOC_Prv_RxAuthenticContextBufferRelease(&rxPduCtx_pst);
        }
        else
        {
            /* callback while context buffer is locked */
            SecOC_Prv_RxCbkPending_au8[configIndex_uo] = csmResult_en;
        }
    }
    else if(SECOC_RX_STATE_WAIT_ABORT_VERIFY_E == state_u8)
    {
        rxPduCtx_pst  = SecOC_Prv_RxAuthenticContextBufferAllocate(configIndex_uo);
        if (NULL_PTR != rxPduCtx_pst)
        {
            SecOC_Prv_clearRxAuthenticPduContext(rxPduCtx_pst);
            SecOC_Prv_RxCbkPending_au8[configIndex_uo] = SECOC_PRV_NO_PENDING_CALLBACK;
            SecOC_Prv_RxAuthenticContextBufferRelease(&rxPduCtx_pst);
        }
        else
        {
            /* callback while context buffer is locked */
            SecOC_Prv_RxCbkPending_au8[configIndex_uo] = csmResult_en;
        }
    }
    else if( SECOC_RX_STATE_VERIFY_E == state_u8 )
    {
        /* callback while state not proper */
        SecOC_Prv_RxCbkPending_au8[configIndex_uo] = csmResult_en;
    }
    else
    {
        /* do nothing */
    }
}

/**
 ***************************************************************************************************
 * The function is called by Csm to notifiy that the verification is finished.
 * If the mac verification completed sucessfully, csmResult_en is E_OK and the result of the
 * verification can be read back from the provided result buffer.
 *
 * \param[in]   jobId_u32      the job id of the job that has finished
 * \param[in]   csmResult_en   result of the verification
 *
 ***************************************************************************************************
 */
void IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en)
{
    (void)jobId_u32;
    /* TRACE[SWS_SecOC_00012]: provide callback functions for asynchonous call of CSM interface */
    SecOC_Prv_RxCallback(SECOC_PRV_IP_CSCBCMCORE_SECCANFRAME01_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX, csmResult_en);
}

/**
 ***************************************************************************************************
 * The function is called by Csm to notifiy that the verification is finished.
 * If the mac verification completed sucessfully, csmResult_en is E_OK and the result of the
 * verification can be read back from the provided result buffer.
 *
 * \param[in]   jobId_u32      the job id of the job that has finished
 * \param[in]   csmResult_en   result of the verification
 *
 ***************************************************************************************************
 */
void IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en)
{
    (void)jobId_u32;
    /* TRACE[SWS_SecOC_00012]: provide callback functions for asynchonous call of CSM interface */
    SecOC_Prv_RxCallback(SECOC_PRV_IP_CSCBCMCORE_SECCANFRAME02_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX, csmResult_en);
}

/**
 ***************************************************************************************************
 * The function is called by Csm to notifiy that the verification is finished.
 * If the mac verification completed sucessfully, csmResult_en is E_OK and the result of the
 * verification can be read back from the provided result buffer.
 *
 * \param[in]   jobId_u32      the job id of the job that has finished
 * \param[in]   csmResult_en   result of the verification
 *
 ***************************************************************************************************
 */
void IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en)
{
    (void)jobId_u32;
    /* TRACE[SWS_SecOC_00012]: provide callback functions for asynchonous call of CSM interface */
    SecOC_Prv_RxCallback(SECOC_PRV_IP_CSCBCMCORE_SECCANFRAME03_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX, csmResult_en);
}

/**
 ***************************************************************************************************
 * The function is called by Csm to notifiy that the verification is finished.
 * If the mac verification completed sucessfully, csmResult_en is E_OK and the result of the
 * verification can be read back from the provided result buffer.
 *
 * \param[in]   jobId_u32      the job id of the job that has finished
 * \param[in]   csmResult_en   result of the verification
 *
 ***************************************************************************************************
 */
void IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId_u32, Std_ReturnType csmResult_en)
{
    (void)jobId_u32;
    /* TRACE[SWS_SecOC_00012]: provide callback functions for asynchonous call of CSM interface */
    SecOC_Prv_RxCallback(SECOC_PRV_IP_CSCBCMCORE_SPECIALSECFRAME01_CAN_NETWORK_0_CHANNEL_CAN_RX_RX_CONFIG_INDEX, csmResult_en);
}


#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"

