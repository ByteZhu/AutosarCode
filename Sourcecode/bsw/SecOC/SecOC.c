/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


/**
 * \brief Source file providing initializing and get version functions of the SecOC module.
 * \addtogroup SecOC
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"
#include "SecOC_Prv.h"
#include "SecOC_Prv_PbCfg.h"
#include "Rte_SecOC.h"

/* Internal cyclic functions which process a given subset of Tx/Rx PDUs corresponding to a configured partition
   (1 partition <-> 1 main function container). */
static void SecOC_Prv_InternalMainFunctionTx(const PduIdType* pduPartitionArray_acuo, uint32 pduPartitionSize_u32);
static void SecOC_Prv_InternalMainFunctionRx(const PduIdType* pduPartitionArray_acuo, uint32 pduPartitionSize_u32);
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"
/**
 ***********************************************************************************************************************
 * SecOC_GetVersionInfo
 *
 * \brief  function to spend information about the version of the library
 *
 * \param[in]    Std_VersionInfoType*    versioninfo  pointer to the version structure
 *
 * \return       void
 ***********************************************************************************************************************
*/
void SecOC_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
    /* TRACE[SWS_SecOC_00107]: Implementation of SecOC_GetVersionInfo. */

    if (NULL_PTR != versioninfo)
    {
        versioninfo->vendorID = SECOC_VENDOR_ID;
        versioninfo->moduleID = SECOC_MODULE_ID;
        versioninfo->sw_major_version = SECOC_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = SECOC_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = SECOC_SW_PATCH_VERSION;
    }
    /* TRACE[SWS_SecOC_00101]|Det disabled */
}

/**
 ***********************************************************************************************************************
 * SecOC_Init
 *
 * \brief  The function initializes all global buffers of SecOC. After this the global state of SecOC is set to
 *         SECOC_INIT. If no Tx and Rx Pdus are configured for SecOC the global state keeps SECOC_UNINIT because
 *         no actions of SecOC are required. In the BCT run an empty function SecOC_Init is generated in this case.
 *         The post-build configuration variants are supported only for RxPdus w/o PduR references.
 *
 * \param[in]    SecOC_ConfigType*    config         pointer to the configuration
 *
 * \return       void
 ***********************************************************************************************************************
*/
void SecOC_Init(const SecOC_ConfigType *config)
{
    /* TRACE[SWS_SecOC_00054], TRACE[SWS_SecOC_00106]: Implementation of SecOC_Init. */

    PduLengthType pduLen_uo;
    PduLengthType payLen_uo;
    uint16 authInfoTruncLen_u16;
    uint8 freshValTruncLen_u8;
    uint8 freshnessValueLen_u8;
    /* BSWEXT-541 */ /* [$DD_BSWCODE 40632] */
    uint8 securedHeaderLength_u8;

    PduIdType idx_cuo;

    uint16 i = 0;

    if (config == NULL_PTR)
    {
        // This implementation only supports post-build configuration
        /* TRACE[]|Det disabled */
        // Initialise pointer to post-build configuration data with NULL.
    }
    else if (config->idxPBV_cu16 >= SECOC_NR_CONFIGSETS)
    {
        // Id of post build array bigger than the number of existing post build data sets -> illegal call
        /* TRACE[]|Det disabled */
    }
    else
    {
        // Initialise general config
        SecOC_Prv_CurrentGenConfig_st = SecOC_Prv_DefaultGenConfig;


        /* initialize all devired RxValues because they might be PBV */
        for( i = 0; i < SECOC_NUMBER_RX_PDU; i++)
        {
            idx_cuo = SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->authInfoTruncLen_cst.idx_cuo;
            authInfoTruncLen_u16 = (*SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->authInfoTruncLen_cst.value_pacu16)[idx_cuo];

            idx_cuo = SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->freshValTruncLen_cst.idx_cuo;
            freshValTruncLen_u8 = (*SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->freshValTruncLen_cst.value_pacu8)[idx_cuo];

            idx_cuo = SecOC_Prv_RxAuthenticPduContext_ast[i].freshnessValueLength_st.idx_cuo;
            freshnessValueLen_u8 = (*SecOC_Prv_RxAuthenticPduContext_ast[i].freshnessValueLength_st.value_pau8)[idx_cuo];

            pduLen_uo = (SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->pduLength_uo) * 8U;
            /* BSWEXT-541 */ /* [$DD_BSWCODE 40632] */
            securedHeaderLength_u8 = (SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->securedHeaderLength_u8) * 8u;
            if( FALSE == SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->packedBits_stb.pduColl_b)
            {   /* Secured Pdu*/
                payLen_uo = pduLen_uo - authInfoTruncLen_u16 - freshValTruncLen_u8 - securedHeaderLength_u8;
            }
            else
            {   /* Collection Pdu*/
                payLen_uo = pduLen_uo - securedHeaderLength_u8;
            }
            /* calculated for SecOC_Prv_clearAllRxPduContexts */
            SecOC_Prv_RxAuthenticPduContext_ast[i].authDataBufferLength_u32 = (payLen_uo + 16U
                                                                               + freshnessValueLen_u8 + 7U ) >> 3U;
            SecOC_Prv_RxAuthenticPduContext_ast[i].actualAuthenticPduLengthInBits_uo = payLen_uo;
            SecOC_Prv_RxSecuredPduContext_ast[i].actualAuthenticPduLengthInBits_uo = payLen_uo;
        }
        /* END BSWEXT-541 */ /* END [$DD_BSWCODE 40632] */

        SecOC_Prv_Rx_Lookup_ValueId_pcu16 =  SecOC_Prv_Rx_Lookup_ValueId_acpcu16[config->idxPBV_cu16];

        /* initialize all buffers of all secured PDUs */
        SecOC_Prv_clearAllRxPduContexts();
        /* initialize the SecOC_Prv_VerifyStatusOverride_ast buffer */
        SecOC_Prv_clearVerifyStatusOverrideBuffer();


        /* initialize all buffers of all authentic PDUs */
        SecOC_Prv_clearAllTxPduContexts();

        /* set global state to initialize */
        SecOC_State_en = SECOC_INIT;
    }


}

/**
 ***********************************************************************************************************************
 * SecOC_DeInit
 *
 * \brief  The function cleares all global PDU specific buffers and sets the state of SecOC to SECOC_UNINIT.
 *
 * \return  void
 ***********************************************************************************************************************
*/
void SecOC_DeInit(void)
{
    /* TRACE[SWS_SecOC_00161]: Implementation of SecOC_DeInit. */
    /* TRACE[SWS_SecOC_00157]: Clear all internal global variables and the buffers of SecOC I-PDUs. */

    /* initialize all buffers of all secured PDUs */
    SecOC_Prv_clearAllRxPduContexts();
    /* initialize the SecOC_Prv_VerifyStatusOverride_ast buffer */
    SecOC_Prv_clearVerifyStatusOverrideBuffer();

    /* initialize all buffers of all authentic PDUs */
    SecOC_Prv_clearAllTxPduContexts();

    /* set global state to UNINIT */
    SecOC_State_en = SECOC_UNINIT;

}

/**
 ***********************************************************************************************************************
 * SecOC_VerifyStatusOverride
 *
 * \brief  This function provides the ability to skip, pass or drop a secured I-PDU with the given value identifier
 *         until a cancel request (UNTIL_NOTICE) or until a given limit is reached (UNTIL_LIMIT).
 *         If a pdu is dropped or skipped no verification is executed and the verification result is written to
 *         SECOC_NO_VERIFICATION. The I-PDUs with a skipped verification are forwarded to PduR nevertheless.
 *         For passed pdu a verification is done but the result is ignored. The verification result is set to
 *         SECOC_VERIFICATIONFAILURE_OVERWRITTEN for unsuccessful verifications. The pdu is forwarded to PduR in all
 *         cases.
 *         SECOC_OVERRIDE_TO_PASS is a non-AUTOSAR parameter for pdu collections. A verification is not performed and
 *         the verification result is set to SECOC_VERIFICATIONSUCCESS and the authentic I-PDU is forwarded to PduR.
 *         This feature is only available if configuration parameter SecOCRbEnableCryptPduBypass is set to TRUE.
 *
 * \param[in]    uint16 ValueID   value identifier for which the request is set depending on parameter SecOCOverrideStatusWithDataId
 *                                If SecOCOverrideStatusWithDataId is set to true ValueID is interpreted as DataId.
 *                                If SecOCOverrideStatusWithDataId is set to false ValueID is interpreted as FreshnessId.
 *
 * \param[in]    SecOC_OverrideStatusType overrideStatus    override status
 *               - SECOC_OVERRIDE_DROP_UNTIL_NOTICE(0x00): no verification,  Override VerifiyStatus to No_Verification, drop PDU until notice
 *               - SECOC_OVERRIDE_DROP_UNTIL_LIMIT(0x01):  no verification,  Override VerifiyStatus to No_Verification, drop PDU until limit
 *               - SECOC_OVERRIDE_CANCEL(0x02):            cancel override of VerifyStatus
 *               - SECOC_OVERRIDE_PASS_UNTIL_NOTICE(0x40): perform verification, Override VerifiyStatus to Verification_Overwritten until cancel request
 *               - SECOC_OVERRIDE_SKIP_UNTIL_LIMIT (0x41): no verification, Override VerifiyStatus to No_Verification until limit
 *               - SECOC_OVERRIDE_PASS_UNTIL_LIMIT (0x42): perform verification, Override VerifiyStatus to Verification_Overwritten until limit
 *               - SECOC_OVERRIDE_SKIP_UNTIL_NOTICE(0x43): no verification, Override VerifiyStatus to  No_Verification, until notice
 *               - SECOC_OVERRIDE_TO_PASS (43U): no verification, Override VerifiyStatus to SECOC_VERIFICATIONSUCCESS
 *
 * \param[in]    uint8 numberOfMessagesToOverride  number of messages(secured I-PDUs) which are override if
 *                                                 overrideStatus is equal OVERRIDE_TO_FAIL_NUMBER
 * \return  Result of the function call:
 *                              - E_OK    : request successful
 *                              - E_NOT_OK: an error occurred, request failed
 *
 * \return  Std_ReturnType
 ***********************************************************************************************************************
*/
/* MR12 RULE 8.3 VIOLATION: Parameter overrideStatus differs from RTE definition because RTE cannot handle typedef */
/* TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142]: Implementation of SecOC_VerifyStatusOverride */
Std_ReturnType SecOC_VerifyStatusOverride(uint16 ValueID,
                                          SecOC_OverrideStatusType overrideStatus,
                                          uint8 numberOfMessagesToOverride)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 index_u32;

    switch (overrideStatus)
    {
        case SECOC_OVERRIDE_DROP_UNTIL_NOTICE:
        case SECOC_OVERRIDE_CANCEL:
        case SECOC_OVERRIDE_TO_PASS:
        {
            result_en = E_OK;
            numberOfMessagesToOverride = 0;
            break;
        }
        case SECOC_OVERRIDE_DROP_UNTIL_LIMIT:
        {
            if (0u == numberOfMessagesToOverride)
            {
                    /* TRACE[]|Det disabled */
            }
            else
            {
                result_en = E_OK;
            }
            break;
        }
        default:
        {
                /* TRACE[]|Det disabled */
            break;
        }
    }

    if(E_OK == result_en)
    {
        // reset the result
        result_en = E_NOT_OK;
        // check if ValueID exists
        for(index_u32 = 0; index_u32 < SECOC_MAX_VERIFY_STATUS_OVERRIDE; index_u32++)
        {
            if(ValueID == SecOC_Prv_Rx_Lookup_ValueId_pcu16[index_u32])
            {
                result_en = E_OK;
                SecOC_Prv_SaveVerifyStatusOverride(index_u32,
                                                   overrideStatus,
                                                   numberOfMessagesToOverride);
                break;
            }
        }
    }

    return (result_en);
}


/**
 ***********************************************************************************************************************
 * SecOC_MainFunctionTx
 *
 * \brief  This cyclic function performs the authentication of authentic I-PDUs.
 *
 * \return  void
 ***********************************************************************************************************************
*/
/*TRACE[SWS_SecOC_00060], TRACE[SWS_SecOC_00065], TRACE[SWS_SecOC_00070]: */
/**
 ***********************************************************************************************************************
 * SecOC_MainFunctionTx
 ***********************************************************************************************************************
*/
/*HIS METRIC STMT VIOLATION in SecOC_MainFunctionTx:
  HIS metric compliance would decrease readability and maintainability.*/
void SecOC_MainFunctionTx(void)
{
    SecOC_Prv_InternalMainFunctionTx(SecOC_Prv_TxPduPartition_apcuo[0], 1);
}

/*HIS METRIC PATH, v(G), CALLS, STMT, LEVEL VIOLATION in SecOC_Prv_InternalMainFunctionTx: central main function for authentication
  of Tx authentic I-PDUs which handles all features defined by AUTOSAR for authentic I-PDUs in a cyclic task*/
static void SecOC_Prv_InternalMainFunctionTx(const PduIdType* pduPartitionArray_acuo, uint32 pduPartitionSize_u32)
{
    uint32 loopIndex_u32;
    PduIdType configIndex_uo;
    SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst;
    SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst;
    SecOC_Prv_TxSecuredPduState_tu8 ctxSecBufState_u8;
    SecOC_Prv_TxAuthenticPduState_tu8 ctxAuthBufState_u8;
    Std_ReturnType result_en = E_NOT_OK;
    uint8 securedHeaderLengthInBits_u8 = 0u;


    /* TRACE[SWS_SecOC_00177]: check SecOC state */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        /* TRACE[SWS_SecOC_00179]: check state of all authentic pdus */
        for(loopIndex_u32 = 0u; loopIndex_u32 < pduPartitionSize_u32; loopIndex_u32++)
        {
            /* Get current states to reduce semaphore allocations, re-check after semaphore allocation success
             * New transmission requests inbetween state check and re-check will be handled next cycle
             */
            configIndex_uo = pduPartitionArray_acuo[loopIndex_u32];

            ctxSecBufState_u8 = SecOC_Prv_TxSecuredContextBufferGetState(configIndex_uo);
            ctxAuthBufState_u8 = SecOC_Prv_TxAuthenticContextBufferGetState(configIndex_uo);
            /* Only allocate semaphore if needed, re-check after allocation success*/
            if (    (SECOC_TX_STATE_FETCH_TP_DATA_E == ctxAuthBufState_u8)
                 || (    (SECOC_TX_STATE_SENDING_E == ctxAuthBufState_u8)
                      && (    (SECOC_TX_STATE_SECURED_IDLE_E == ctxSecBufState_u8)
                           || (SECOC_TX_STATE_SENT_E == ctxSecBufState_u8)) ))
            {
                txAuthenticPduCtx_pst = SecOC_Prv_TxAuthenticContextBufferAllocate(configIndex_uo);
                if (NULL_PTR != txAuthenticPduCtx_pst)
                {
                    ctxAuthBufState_u8 = SecOC_Prv_TxAuthenticContextBufferGetState(configIndex_uo);
                    /* No PduType check needed, only tp pdu can have this state */
                    if (SECOC_TX_STATE_FETCH_TP_DATA_E == ctxAuthBufState_u8)
                    {
                        /* TRACE[SWS_SecOC_00260]:  */
                        result_en = SecOC_Prv_TpCopyTxData(txAuthenticPduCtx_pst);
                        if (E_OK != result_en)
                        {
                             /* Reset same buffer if PDU is discarded because it is already locked in SecOC_Transmit */
                             SecOC_Prv_resetSameBufferTxRefInUse(configIndex_uo);
                        }
                        /* reload authentic context buffer state */
                        ctxAuthBufState_u8 = SecOC_Prv_TxAuthenticContextBufferGetState(configIndex_uo);
                    }
                    txSecuredPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(configIndex_uo);
                    if (NULL_PTR != txSecuredPduCtx_pst)
                    {
                        /* reload secured context state after successful allocation */
                        ctxSecBufState_u8 = SecOC_Prv_TxSecuredContextBufferGetState(configIndex_uo);
                        /* TRACE[SWS_SecOC_00110]: check if updated Authentic PDU is waiting for authentication */
                        /*                         if creation of Secured PDU is finished                       */
                        if (    (SECOC_TX_STATE_SENDING_E == ctxAuthBufState_u8)
                             && (    (SECOC_TX_STATE_SECURED_IDLE_E == ctxSecBufState_u8)
                                  || (SECOC_TX_STATE_SENT_E == ctxSecBufState_u8)) )
                        {
                            txSecuredPduCtx_pst->status_u8 = SECOC_TX_STATE_GENERATE_E;

                            /* Get the secured header length */
                            securedHeaderLengthInBits_u8 = SecOC_Prv_TxGetSecuredHeaderLength(txSecuredPduCtx_pst);

                            /* TRACE[SWS_SecOC_00037]: pack payload of the received authentic PDU into the out buffer */
                            SecOC_Prv_CopyBits(
                                txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8,/* out: destination */
                                securedHeaderLengthInBits_u8,                        /*  in: destination bit position */
                                txAuthenticPduCtx_pst->pduConfig_pst->authenticPduBufferIn_pu8, /*  in: source */
                                0u,                                                  /*  in: source bit position */
                                txAuthenticPduCtx_pst->payloadLength_uo              /*  in: number of bits to copy */
                            );
                            txSecuredPduCtx_pst->MetaDataPtr_pu8 = txAuthenticPduCtx_pst->MetaDataPtr_pu8;
                            ctxSecBufState_u8 = SecOC_Prv_TxSecuredContextBufferGetState(configIndex_uo);
                            SecOC_Prv_TxAuthenticContextBufferRelease(&txAuthenticPduCtx_pst);
                            SecOC_Prv_TxSecuredContextBufferRelease(&txSecuredPduCtx_pst);
                        }
                    }
                    SecOC_Prv_TxAuthenticContextBufferRelease(&txAuthenticPduCtx_pst);
                }
            }

            switch (ctxSecBufState_u8)
            {
                case SECOC_TX_STATE_GENERATE_E:
                {
                    /* try to lock context buffers */
                    txSecuredPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(configIndex_uo);
                    if (NULL_PTR != txSecuredPduCtx_pst)
                    {
                        /* lock authentic context buffer only if secured context buffer is locked because both */
                        /* context buffers are unlocked at during handling of state SECOC_TX_STATE_GENERATE_E  */
                        txAuthenticPduCtx_pst = SecOC_Prv_TxAuthenticContextBufferAllocate(configIndex_uo);
                        if (NULL_PTR == txAuthenticPduCtx_pst)
                        {
                            /* unlock secured context buffer if authentic context buffer can not locked */
                            SecOC_Prv_TxSecuredContextBufferRelease(&txSecuredPduCtx_pst);
                        }
                    }
                    if (NULL_PTR != txSecuredPduCtx_pst)
                    {
                         
                        if (TRUE == txAuthenticPduCtx_pst->pduConfig_pst->useTxPduSecuredArea_b)
                        {
                            /* TRACE[SWS_SecOC_00311], TRACE[SWS_SecOC_00312]: */
                            /* Copy secured area of Authentic PDU from input buffer (authenticPduBufferIn_pu8) to buffer
                             * for authentication (authDataBuffer_pu8)
                             * */
                            SecOC_Prv_CopyBits(
                                txSecuredPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,        /* out: destination */
                                SECOC_PRV_PAYLOAD_OFFSET,                                      /*  in: destination bit position */
                                txAuthenticPduCtx_pst->pduConfig_pst->authenticPduBufferIn_pu8,/*  in: source */
                                (uint32)(8u * txAuthenticPduCtx_pst->pduConfig_pst->securedTxPduOffset_u32),/*  in: source bit position */
                                (uint32)(8u * txAuthenticPduCtx_pst->pduConfig_pst->securedTxPduLength_u32) /*  in: number of bits to copy */
                            );
                        }
                        else
                        {
                            /* Copy Authentic PDU from input buffer (authenticPduBufferIn_pu8) to buffer for
                             * authentication (authDataBuffer_pu8)
                             * */
                            SecOC_Prv_CopyBits(
                                txSecuredPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,         /* out: destination */
                                SECOC_PRV_PAYLOAD_OFFSET,                        /*  in: destination bit position */
                                txAuthenticPduCtx_pst->pduConfig_pst->authenticPduBufferIn_pu8, /*  in: source */
                                0u,                                              /*  in: source bit position */
                                txAuthenticPduCtx_pst->payloadLength_uo          /*  in: number of bits to copy */
                            );
                        }
                        txSecuredPduCtx_pst->payloadLength_uo = txAuthenticPduCtx_pst->payloadLength_uo;

                        /* release authentic context buffer and same buffer because it is not longer handled here */
                        /* => a new authentic PDU can be received                                 */
                        txAuthenticPduCtx_pst->status_u8 = SECOC_TX_STATE_AUTHENTIC_IDLE_E;
                        SecOC_Prv_resetSameBufferTxRefInUse(configIndex_uo);
                        SecOC_Prv_TxAuthenticContextBufferRelease(&txAuthenticPduCtx_pst);

                        if (SECOC_CRYPTIF_NONE == txSecuredPduCtx_pst->pduConfig_pst->cryptInterface_e)
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
                            result_en = SecOC_Prv_createDataforAuthenticationTx(txSecuredPduCtx_pst);

                            switch (result_en)
                            {
                                case E_OK:
                                {
                                    /**
                                      * calculate authenticator, input data stream: dataId | payload | freshness value
                                      */
                                    result_en = SecOC_Prv_AuthGenerate(txSecuredPduCtx_pst);

                                    if (E_OK == result_en)
                                    {
                                        if(FALSE != txSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.syncMod_b)
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
                                             /* asynchronous handling: wait for callback */
                                             txSecuredPduCtx_pst->status_u8 = SECOC_TX_STATE_WAIT_FOR_CSM_CALLBACK_E;
                                        }
                                    }
                                    else
                                    {
                                        /* authentication fails, call function to check negative response */
                                        if (SecOC_Prv_CheckAuthenticationResult(txSecuredPduCtx_pst, result_en))
                                        {
                                            /* TRACE[SWS_SecOC_00166]|Det disabled */
                                        }
                                    }
                                    break;
                                }

                                case SECOC_E_BUSY: 
                                {
                                    /* TRACE[SWS_SecOC_00227], TRACE[SWS_SecOC_00251]: */
                                    /* currently no freshness value available => increment verify attempt counter and retry */
                                    SecOC_Prv_AuthenticationRetry(txSecuredPduCtx_pst);
                                    if (SECOC_TX_STATE_SECURED_IDLE_E == txSecuredPduCtx_pst->status_u8)
                                    {
                                        /* TRACE[SWS_SecOC_00114]|Runtime Error */
                                        (void)Det_ReportRuntimeError(SECOC_MODULE_ID, SECOC_INSTANCE_ID, SECOC_SERVICE_ID_MAIN_FUNCTION_TX, SECOC_E_FRESHNESS_FAILURE);
                                    }
                                    break;
                                }

                                case E_NOT_OK:  
                                {
      
                                    /* TRACE[SWS_SecOC_00227], TRACE[SWS_SecOC_00229], TRACE[SWS_SecOC_00251]: */
                                    /* No freshness value available => discard PDU and clear internal buffers */
                                    SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
                                        /* TRACE[SWS_SecOC_00114]|Runtime Error */
                                        (void)Det_ReportRuntimeError(SECOC_MODULE_ID, SECOC_INSTANCE_ID, SECOC_SERVICE_ID_MAIN_FUNCTION_TX, SECOC_E_FRESHNESS_FAILURE);
                                    break;
                                }

                                /* MR12 RULE 16.4 VIOLATION: Empty default case required by coding rules */
                                default:
                                {
                                    /* TRACE[SWS_SecOC_00251]: */
                                    /* Switch statement covers all possible enum values, empty default case
                                     * required by coding rules.
                                     * */
      
                                    SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
                                    /* TRACE[SWS_SecOC_00114]|Runtime Error */
                                    (void)Det_ReportRuntimeError(SECOC_MODULE_ID, SECOC_INSTANCE_ID, SECOC_SERVICE_ID_MAIN_FUNCTION_TX, SECOC_E_FRESHNESS_FAILURE);
                                    break;
                                }
                            }
                        }
                        /* handle pending early callback */
                        if(SECOC_PRV_NO_PENDING_CALLBACK != SecOC_Prv_TxCbkPending_au8[(PduIdType)configIndex_uo])
                        {
                            SecOC_Prv_handlePenTxCbk(txSecuredPduCtx_pst);
                        }
                        SecOC_Prv_TxSecuredContextBufferRelease(&txSecuredPduCtx_pst);
                    }
                    break;
                }

                case SECOC_TX_STATE_CANCEL_PENDING_E:
                {
                    /* inform Csm to cancel the transmission and clear internal buffers */
                    txSecuredPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(configIndex_uo);
                    if (NULL_PTR != txSecuredPduCtx_pst)
                    {
                        SecOC_Prv_CancelCryptJob((PduIdType)configIndex_uo);
                        SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
                        SecOC_Prv_TxSecuredContextBufferRelease(&txSecuredPduCtx_pst);
                    }
                    break;
                }

                case SECOC_TX_STATE_SECURED_IDLE_E:
                case SECOC_TX_STATE_SENT_E:
                {
                    /* valid states, but nothing to do in the main function */
                    break;
                }

                case SECOC_TX_STATE_WAIT_FOR_CSM_CALLBACK_E:
                {
                    if (SECOC_PRV_NO_PENDING_CALLBACK != SecOC_Prv_TxCbkPending_au8[(PduIdType)configIndex_uo])
                    {
                        txSecuredPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(configIndex_uo);
                        if (NULL_PTR != txSecuredPduCtx_pst)
                        {
                            SecOC_Prv_handlePenTxCbk(txSecuredPduCtx_pst);
                            SecOC_Prv_TxSecuredContextBufferRelease(&txSecuredPduCtx_pst);
                        }
                    }
                    break;
                }

                /* MR12 RULE 16.4 VIOLATION: no action is necessary */
                default:
                {
                    /* Switch statement covers all relevant enum values, empty default clause
                     * required by coding rules.
                     * */
                    break;
                }
            }
        }
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_MainFunctionRx
 *
 * \brief  This cyclic function performs the verification of secured I-PDUs.
 *
 * \return  void
 ***********************************************************************************************************************
*/
/**
 ***********************************************************************************************************************
 * SecOC_MainFunctionRx
 ***********************************************************************************************************************
*/
/*HIS METRIC STMT VIOLATION in SecOC_MainFunctionRx:
  HIS metric compliance would decrease readability and maintainability.*/
void SecOC_MainFunctionRx(void)
{
    SecOC_Prv_InternalMainFunctionRx(SecOC_Prv_RxPduPartition_apcuo[0], 4);
}

/*HIS METRIC PATH, v(G), CALLS, LEVEL VIOLATION in SecOC_Prv_InternalMainFunctionRx: central main function for verifing
  Rx secured I-PDUs which handles all features defined by AUTOSAR for secured I-PDUs in a cyclic task*/
static void SecOC_Prv_InternalMainFunctionRx(const PduIdType* pduPartitionArray_acuo, uint32 pduPartitionSize_u32)
{
    uint32 loopIndex_u32;
    PduIdType configIndex_uo;
    PduIdType idx_cuo;
    SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst;
    SecOC_Prv_RxOvrflwStrat_en rxOverflowStrategy;
    uint16 valueID_u16;
    SecOC_OverrideStatusType overrideStatus_u8;
    SecOC_Prv_RxSecuredPduState_tu8 crxSecuredBufferState_u8;
    SecOC_Prv_RxAuthenticPduState_tu8 crxAuthenticBufferState_u8;
    SecOC_Prv_RxAuthenticPduContext_tst *rxAuthenticPduCtx_pst = NULL_PTR;
    Std_ReturnType result_en = E_NOT_OK;
    boolean retryVerificationImmediately_b = FALSE;
    SecOC_Prv_CryptIf_en cryptIf_e = SECOC_CRYPTIF_NONE;


    /* TRACE[SWS_SecOC_00172]: check SecOC state */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        /* TRACE[SWS_SecOC_00174]: check state of all secured pdus */
        for(loopIndex_u32 = 0u; loopIndex_u32 < pduPartitionSize_u32; loopIndex_u32++)
        {
            /* Get the actual Rx Pdu ID from partition array */
            configIndex_uo = pduPartitionArray_acuo[loopIndex_u32];

            /* save access to static configuration via secured Pdu context*/
            rxOverflowStrategy = SecOC_Prv_RxSecuredPduContext_ast[configIndex_uo].pduConfig_pst->rxOvrflwStrat_e;
            retryVerificationImmediately_b = TRUE;

            /* while loop for retry verification immediately if configured and required */
            while (retryVerificationImmediately_b)
            {
                retryVerificationImmediately_b = FALSE;

                crxSecuredBufferState_u8 = SecOC_Prv_RxSecuredContextBufferGetState((PduIdType)configIndex_uo);
                crxAuthenticBufferState_u8 = SecOC_Prv_RxAuthenticContextBufferGetState((PduIdType)configIndex_uo);

                /* Check if hanging SecOC_TpRxIndication is available */
                if (   (SECOC_RX_STATE_RECEIVING_E == crxSecuredBufferState_u8)
                     && (SECOC_PRV_NO_PENDING_INDICATION != SecOC_Prv_RxTpRxIndPending[configIndex_uo]))
                {
                    /* hanging SecOC_Prv_TpRxIndication for single PDU, handle it now */
                    SecOC_Prv_TpRxIndication(configIndex_uo, SecOC_Prv_RxTpRxIndPending[configIndex_uo]);
                }

                /* TRACE[SWS_SecOC_00214], TRACE[SWS_SecOC_00215], TRACE[SWS_SecOC_00216]: Overflow strategy */
                /* (SRS_SecOC_00021, SRS_SecOC_00022) */
                /* New receive only in case of QUEUE or REPLACE possible,
                 * REJECT was handled in earlier parts of the call chain RxIndication or StartofReception
                 *
                 * authentic context buffer needed only if VERIFY retried
                 *       OR New Pdu available
                 *          AND creation of Authentic PDU is finished
                 *              OR creation of Authentic PDU ongoing
                 *                 AND forced to be Replace */
                if (    (SECOC_RX_STATE_VERIFY_E == crxAuthenticBufferState_u8)
                     || (    (SECOC_RX_STATE_RECEIVED_E == crxSecuredBufferState_u8)
                          && (    (SECOC_RX_STATE_AUTHENTIC_IDLE_E == crxAuthenticBufferState_u8)
                               || (    (SECOC_RX_REPLACE_E == rxOverflowStrategy)
                                    && (SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E == crxAuthenticBufferState_u8)))))
                {
                    rxAuthenticPduCtx_pst = SecOC_Prv_RxAuthenticContextBufferAllocate(configIndex_uo);
                    /* Get again the Auth buffer state to be sure that the state did not change. */
                    crxAuthenticBufferState_u8 = SecOC_Prv_RxAuthenticContextBufferGetState((PduIdType)configIndex_uo);
                }
                /* Checks for further handling force abort VERIFY  or COPY                              */
                /* TRACE[SWS_SecOC_00111]: check if updated Secured PDU is waiting for verification AND */
                /*                            if creation of Authentic PDU is finished                  */
                /*                         OR if Secured PDU retry VERIFY                               */
                /*                            AND forced to be REPLACED                                 */
                if(SECOC_RX_STATE_RECEIVED_E == crxSecuredBufferState_u8)
                {
                    /* Check for forced REPLACE -> force abort -> skip result in callback
                     * since the verification was started on the lower level CSM and also the CSM can't abort
                     * instantly, we have to wait for the CSM callback and to discard verifcation result
                     * next MainFuctionRx latest content of (cryptographic)PduBufferIn will be processed */
                    if(    (SECOC_RX_REPLACE_E == rxOverflowStrategy)
                        && (SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E == crxAuthenticBufferState_u8))
                    {
                        if(NULL_PTR != rxAuthenticPduCtx_pst)
                        {
                             rxAuthenticPduCtx_pst->status_u8 = SECOC_RX_STATE_WAIT_ABORT_VERIFY_E;
                             /* update local variable also */
                             crxAuthenticBufferState_u8 = SECOC_RX_STATE_WAIT_ABORT_VERIFY_E;
                             SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                        }
                    }
                    /*Check for COPY if creation of Authentic PDU is finished                           */
                    /*               OR if Secured PDU retry VERIFY                                     */
                    /*                  AND forced to be REPLACED                                       */
                    else  if(    (SECOC_RX_STATE_AUTHENTIC_IDLE_E == crxAuthenticBufferState_u8)
                              || (    (SECOC_RX_STATE_VERIFY_E == crxAuthenticBufferState_u8)
                                   && (SECOC_RX_REPLACE_E == rxOverflowStrategy)))
                    {
                        if (NULL_PTR != rxAuthenticPduCtx_pst)
                        {
                            rxSecuredPduCtx_pst = SecOC_Prv_RxSecuredContextBufferAllocate(configIndex_uo);
                            if (NULL_PTR != rxSecuredPduCtx_pst)
                            {
                                /* Get the status again */
                                crxSecuredBufferState_u8 = SecOC_Prv_RxSecuredContextBufferGetState((PduIdType)configIndex_uo);
                                /* Check the status second time to be sure that the status is RECEIVED after lock was acquired */
                                if (SECOC_RX_STATE_RECEIVED_E == crxSecuredBufferState_u8)
                                {
                                    /* A valid PDU was received and the buffers are free.
                                       Copies the PDU from Secured buffer to Authentic buffer */
                                    SecOC_Prv_CopyPduFromSecuredCtxToAuthenticCtx(rxSecuredPduCtx_pst, rxAuthenticPduCtx_pst);
                                    rxAuthenticPduCtx_pst->upTpBufSize_uo = rxSecuredPduCtx_pst->upTpBufSize_uo;
                                    /* all input data are copied into internal buffers => clear and unlock secured context buffer */
                                    SecOC_Prv_clearRxSecuredPduContext(rxSecuredPduCtx_pst);
                                    crxAuthenticBufferState_u8 = SecOC_Prv_RxAuthenticContextBufferGetState((PduIdType)configIndex_uo);
                                }
                                else
                                {
                                    /* Secured state changed. The Pdu can't be copied to Authentic buffer. */
                                }
                                SecOC_Prv_RxSecuredContextBufferRelease(&rxSecuredPduCtx_pst);
                            }
                            else
                            {
                                /* Secured context buffer can not be locked, Authentic state is still IDLE */
                                /* Release authentic context buffer                                        */
                                SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                            }
                        }
                        else
                        {
                            /* Authentic context is busy. */
                        }
                    }
                    else
                    {
                        /* No copy or further handling due to overflow strategy and state */
                    }
                }

                switch (crxAuthenticBufferState_u8)
                {
                    case SECOC_RX_STATE_VERIFY_E:
                    /* a secured I-PDU is ready for verification */
                    {
                        if (NULL_PTR != rxAuthenticPduCtx_pst)
                        {
                            idx_cuo = rxAuthenticPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
                            valueID_u16 = (*rxAuthenticPduCtx_pst->pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo];
                            idx_cuo = rxAuthenticPduCtx_pst->pduConfig_pst->cryptIf_cst.idx_cuo;
                            cryptIf_e = (*rxAuthenticPduCtx_pst->pduConfig_pst->cryptIf_cst.value_pace)[idx_cuo];

                            overrideStatus_u8 = SecOC_Prv_fetchOverrideStatus(valueID_u16);
                            if (    (SECOC_OVERRIDE_DROP_UNTIL_NOTICE == overrideStatus_u8)
                                 || (SECOC_OVERRIDE_DROP_UNTIL_LIMIT == overrideStatus_u8))
                            {
                                /* TRACE[SWS_SecOC_00991]: Drop Pdu because status os overwritten */
                                 SecOC_Prv_VerificationFailed(rxAuthenticPduCtx_pst, SECOC_NO_VERIFICATION);
                            }
                            else if (    (SECOC_CRYPTIF_NONE == cryptIf_e)
                                      || (SECOC_OVERRIDE_TO_PASS  == overrideStatus_u8)
                                    )
                            {
                               /* TRACE[SWS_SecOC_00991]:verification is disabled for this pdu, assume successful verification */
                               (void)SecOC_Prv_HandleVerificationResult(rxAuthenticPduCtx_pst, E_OK);
                            }
                            else
                            {
                                result_en = SecOC_Prv_getFreshnessValueRx(rxAuthenticPduCtx_pst);

                                switch (result_en)
                                {
                                    case E_OK:
                                    {
                                         /* TRACE[SWS_SecOC_00079]: verification of received PDU */
                                         result_en = SecOC_Prv_AuthVerify(rxAuthenticPduCtx_pst);

                                         /* check verification result and forward authentic I-Pdu to PduR if possible */
                                         if (SecOC_Prv_HandleVerificationResult(rxAuthenticPduCtx_pst, result_en))
                                         {
                                            /* TRACE[SWS_SecOC_00166]|Det disabled */
                                         }

                                         /* retry mac verification in the same main function cycle if */
                                         /* SecOCRbRetryVerifyImmediately is configured to true       */
                                         if ((FALSE != SecOC_Prv_CurrentGenConfig_st.rbRetryVerifyImmediately_b) &&
                                             (SECOC_RX_STATE_VERIFY_E == rxAuthenticPduCtx_pst->status_u8))
                                         {
                                             retryVerificationImmediately_b = TRUE;
                                         }
                                         break;
                                     }

                                    case SECOC_E_BUSY: 
                                    {
                                         /* TRACE[SWS_SecOC_00236]: currently no freshness value available */
                                         /* => increment verify attempt counter and retry */
                                         SecOC_Prv_VerificationRetry(rxAuthenticPduCtx_pst, SECOC_AUTHENTICATIONBUILDFAILURE,
                                             &rxAuthenticPduCtx_pst->authAttempts_u16,
                                             rxAuthenticPduCtx_pst->pduConfig_pst->authenticationBuildAttempts_u16);

                                         /* TRACE[SWS_SecOC_RB_00155], TRACE[SWS_SecOC_00251]: */
                                         /* no freshness value available, report SECOC_E_FRESHNESS_FAILURE to DET */
                                         if (SECOC_RX_STATE_AUTHENTIC_IDLE_E == rxAuthenticPduCtx_pst->status_u8)
                                         {
                                            /* TRACE[SWS_SecOC_00114]|Runtime Error */
                                            (void)Det_ReportRuntimeError(SECOC_MODULE_ID, SECOC_INSTANCE_ID, SECOC_SERVICE_ID_MAIN_FUNCTION_RX, SECOC_E_FRESHNESS_FAILURE);
                                          }
                                          /* retry mac verification in the same main function cycle if */
                                          /* SecOCRbRetryVerifyImmediately is configured to true       */
                                          if ((FALSE != SecOC_Prv_CurrentGenConfig_st.rbRetryVerifyImmediately_b) &&
                                              (SECOC_RX_STATE_VERIFY_E == rxAuthenticPduCtx_pst->status_u8))
                                          {
                                             retryVerificationImmediately_b = TRUE;
                                          }
                                          break;
                                    }

                                    case E_NOT_OK:  
                                    {
                                        /* TRACE[SWS_SecOC_00256]: No freshness value available => discard PDU */
                                        /* TRACE[SWS_SecOC_RB_00155], TRACE[SWS_SecOC_00251]: */
                                        /* no freshness value available, report SECOC_E_FRESHNESS_FAILURE to DET */
                                        SecOC_Prv_VerificationFailed(rxAuthenticPduCtx_pst, SECOC_FRESHNESSFAILURE);
                                        /* TRACE[SWS_SecOC_00114]|Runtime Error */
                                        (void)Det_ReportRuntimeError(SECOC_MODULE_ID, SECOC_INSTANCE_ID, SECOC_SERVICE_ID_MAIN_FUNCTION_RX, SECOC_E_FRESHNESS_FAILURE);
                                        break;
                                     }

                                     default:
                                     {
                                        /* MR12 RULE 16.4 VIOLATION: Switch covers all relevant cases, empty default clause required
                                         * by coding guidelines */
                                        /* TRACE[SWS_SecOC_RB_00155], TRACE[SWS_SecOC_00251]: */
                                        /* no freshness value available, report SECOC_E_FRESHNESS_FAILURE to DET */
                                        SecOC_Prv_VerificationFailed(rxAuthenticPduCtx_pst, SECOC_FRESHNESSFAILURE);
                                        /* TRACE[SWS_SecOC_00114]|Runtime Error */
                                        (void)Det_ReportRuntimeError(SECOC_MODULE_ID, SECOC_INSTANCE_ID, SECOC_SERVICE_ID_MAIN_FUNCTION_RX, SECOC_E_FRESHNESS_FAILURE);
                                        break;
                                     }
                                }
                            }
                            /* handle pending early callback */
                            if(SECOC_PRV_NO_PENDING_CALLBACK != SecOC_Prv_RxCbkPending_au8[(PduIdType)configIndex_uo])
                            {
                                 SecOC_Prv_handlePenRxCbk(rxAuthenticPduCtx_pst);
                            }
                            SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                        }
                        break;
                    }
                    case SECOC_RX_STATE_AUTHENTIC_IDLE_E:
                    case SECOC_RX_STATE_MAC_VERIFY_FINISHED_E:
                    {
                        /* valid states, but nothing to do in the main function */
                        break;
                    }
                    case SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E:
                    case SECOC_RX_STATE_WAIT_ABORT_VERIFY_E:
                    {
                        if(SECOC_PRV_NO_PENDING_CALLBACK != SecOC_Prv_RxCbkPending_au8[(PduIdType)configIndex_uo])
                        {
                            rxAuthenticPduCtx_pst  = SecOC_Prv_RxAuthenticContextBufferAllocate(configIndex_uo);
                            if (NULL_PTR != rxAuthenticPduCtx_pst)
                            {
                                 SecOC_Prv_handlePenRxCbk(rxAuthenticPduCtx_pst);
                                 SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                            }
                        }
                        break;
                    }
                     /* MR12 RULE 16.4 VIOLATION: no action is necessary */
                    default:
                    {
                        /* Switch statement covers all relevant enum values, empty default clause
                         * required by coding rules.
                         * */
                        break;
                    }
                }
            }
        }
    }
}
#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"

