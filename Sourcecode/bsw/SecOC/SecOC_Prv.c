/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Private source file providing helper functionality.
 * \addtogroup SecOC
 */


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"
#include "SecOC_Prv.h"
#include "SecOC_Prv_PduRIF.h"
#include "Rte_SecOC.h"
#include "Csm.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"

/**
 ***********************************************************************************************************************
 * SecOC_Prv_resetSameBufferTxRefInUse
 *
 * \brief  The function resets the flag isSameBufferRefInUse_pb and the variable sameBufferRefInUsePduId_puo
 *         hold in the private authentic context buffer if state is IDLE
 * \warning  configIndex_u32 is assumed to be valid, no range check is done!
 *
 * \param[in]    configIndex_u32   index of the context buffer for the Tx authentic pdu
 *
 ***********************************************************************************************************************
*/
void SecOC_Prv_resetSameBufferTxRefInUse(uint32 configIndex_u32)
{
    SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst;


    txAuthenticPduCtx_pst = &SecOC_Prv_TxAuthenticPduContext_ast[configIndex_u32];
    if (SECOC_TX_STATE_AUTHENTIC_IDLE_E == txAuthenticPduCtx_pst->status_u8)
    {
       SchM_Enter_SecOC_SameBuffer();
       if (NULL_PTR != txAuthenticPduCtx_pst->pduConfig_pst->isSameBufferRefInUse_pb)
        {
            *(txAuthenticPduCtx_pst->pduConfig_pst->isSameBufferRefInUse_pb) = FALSE;
        }
        if (NULL_PTR != txAuthenticPduCtx_pst->pduConfig_pst->sameBufferRefInUsePduId_puo)
        {
            *(txAuthenticPduCtx_pst->pduConfig_pst->sameBufferRefInUsePduId_puo) = 0u;
        }
        SchM_Exit_SecOC_SameBuffer();
     }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_handlePenTxCbk
 *
 * \brief  This private function handles a pending Tx callback.
 *
 * \return  void
 ***********************************************************************************************************************
 */
void SecOC_Prv_handlePenTxCbk(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst)
{
    if (E_OK == SecOC_Prv_TxCbkPending_au8[txSecuredPduCtx_pst->pduIndex_u32])
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
        if (SecOC_Prv_CheckAuthenticationResult(txSecuredPduCtx_pst,
                                                SecOC_Prv_TxCbkPending_au8[txSecuredPduCtx_pst->pduIndex_u32]))
        {
            /* TRACE[SWS_SecOC_00166]|Det disabled */
        }
    }
    SecOC_Prv_TxCbkPending_au8[txSecuredPduCtx_pst->pduIndex_u32] = SECOC_PRV_NO_PENDING_CALLBACK;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_AuthenticationRetry
 *
 * \brief The function increments the authentication build counter until the maximum value is reached.
 *        Until the maximum is not reached the state of the given private context buffer is set to
 *        SECOC_TX_STATE_GENERATE_E to retry the authentication.
      
 *        When the maximum is reached (the Default Authentication Information Pattern is disabled) the function
 *        SecOC_Prv_clearTxSecuredPduContext is called to clear the internal buffers.
 *
 *
 * \param[in]    SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst   pointer to private context buffer of the
 *                                                                        Tx secured pdu
 *
 ***********************************************************************************************************************
*/
void SecOC_Prv_AuthenticationRetry(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst)
{
    /* TRACE[SWS_SecOC_00225]: maintain authentication build counter */
    /* increment retry counter and check if the authentication can be retried */
    txSecuredPduCtx_pst->authAttempts_u16++;
    if (txSecuredPduCtx_pst->authAttempts_u16 < txSecuredPduCtx_pst->pduConfig_pst->authenticationBuildAttempts_u16)
    {
        /* Retry authentication */
        txSecuredPduCtx_pst->status_u8 = SECOC_TX_STATE_GENERATE_E;
    }
    else
    {
      
        /* TRACE[SWS_SecOC_00229]: discard PDU, clear internal buffers */
        SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_CheckAuthenticationResult
 *
 * \brief The function handles negative results of an authentication via csm. It checks and increments the
 *        authentication counter and sets the state of the pdu job. It returns true if an det error shall
 *        be called by the calling function. This is done because the function can be called by two different
 *        functions and the det error requires an function identifier.
      
 *        When the maximum is reached (the Default Authentication Information Pattern is disabled) the function
 *        SecOC_Prv_clearTxSecuredPduContext is called to clear the internal buffers and returns TRUE.
 *
 * \param[in]    SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst   pointer to private context buffer of the
 *                                                                        secured pdu
 * \param[in]    Std_ReturnType    authResult   result of the cryptographic interface
 *
 * \return       TRUE    det error shall be called
 *               FALSE   no det error required
 ***********************************************************************************************************************
*/
boolean SecOC_Prv_CheckAuthenticationResult(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst,
                                            Std_ReturnType authResult)
{
    boolean   detErrorCall_b = FALSE;

    switch (authResult)
    {
        case CRYPTO_E_KEY_NOT_VALID:
        case E_NOT_OK:
        {
      
            /* TRACE[SWS_SecOC_00229]: non recoverable error from MacGenerate => authentication failed */
            SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);

            detErrorCall_b = TRUE;
            break;
        }

        case CRYPTO_E_BUSY:
        {
            /* TRACE[SWS_SecOC_00227]: recoverable error from MacGenerate => retry authentication */
            SecOC_Prv_AuthenticationRetry(txSecuredPduCtx_pst);

      
            if (SECOC_TX_STATE_SECURED_IDLE_E == txSecuredPduCtx_pst->status_u8)
            {
                /* TRACE[SWS_SecOC_RB_00155]: authentication retry counter reaches the maximum value => invoke det error */
                detErrorCall_b = TRUE;
            }
            break;
        }

        default:
        {
            /* clear internal buffers */
      
            /* TRACE[SWS_SecOC_00229]: non recoverable error from MacGenerate => authentication failed */
            SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
            detErrorCall_b = TRUE;
            break;
       }
    }


    return (detErrorCall_b);
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_VerificationRetry
 *
 * \brief The function calls function SecOC_Prv_HandleVerifyStatusOverride to check if the verification status is
 *        overwritten by external. With function SecOC_Prv_WriteVerificationStatus the status is propageted.
 *        The function SecOC_Prv_IncrVerifyRetryCounters is called to increment the retry counter until the
 *        maximum.
 *
 * \param[in]    SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the secured pdu
 *
 * \param[in]    SecOC_VerificationResultType verificationStatus  new verification status of the pdu
 *
 * \param[in]    uint16 *counter   pointer to the counter to maintained
 *
 * \param[in]    uint16 maxValue   maximum of the pointer
 *
 ***********************************************************************************************************************
*/
void SecOC_Prv_VerificationRetry(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst,
                                 SecOC_VerificationResultType verificationStatus, uint16* counter, uint16 maxValue)
{
    PduIdType idx_cuo = rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
    rxPduCtx_pst->verificationStatus_u8 = SecOC_Prv_HandleVerifyStatusOverride(
                                             (*rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo],
                                               verificationStatus);

    /* TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142] */
    if (SECOC_VERIFICATIONFAILURE_OVERWRITTEN == rxPduCtx_pst->verificationStatus_u8)
    {
        /* status is overwritten to success => pass the PDU */
        SecOC_Prv_VerificationSuccessful(rxPduCtx_pst);
    }
    else
    {
        /* TRACE[SWS_SecOC_00141], TRACE[SWS_SecOC_00148]: */
        /* propagate the verification status of each authentication attempt to the application layer */
        /* Note: Authentication build failure is not propagated */
        SecOC_Prv_WriteVerificationStatus(rxPduCtx_pst);

        /* TRACE[SWS_SecOC_00234]: maintain authentication build and authentication verify attempt counters */
        if ((*counter) < maxValue)
        {
            /* TRACE[SWS_SecOC_00238]: increment retry counter and retry verification */
            (*counter)++;
            rxPduCtx_pst->status_u8 = SECOC_RX_STATE_VERIFY_E;
        }
        if ((*counter) == maxValue)
        {
            /* TRACE[SWS_SecOC_00240],TRACE[SWS_SecOC_RB_00241]: If counter expires, discard the PDU */
            SecOC_Prv_clearRxAuthenticPduContext(rxPduCtx_pst);
        }
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_VerificationSuccessful
 *
 * \brief The function handles the succesful verification: The authentic pdu is created and forwarded to PduR.
 *        The verification status is propageted via function call SecOC_Prv_WriteVerificationStatus.
 *        After this all internal buffer are cleared and the state is set to IDLE by calling the function
 *        SecOC_Prv_clearRxAuthenticPduContext.
 *
 * \param[in]    SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the secured pdu
 ***********************************************************************************************************************
*/
void SecOC_Prv_VerificationSuccessful(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst)
{
    /* TRACE[SWS_SecOC_00050], TRACE[SWS_SecOC_00180]: forward the authentic pdu to the PduR */
    SecOC_Prv_VerificationFinished(rxPduCtx_pst);

    /* TRACE[SWS_SecOC_00141], TRACE[SWS_SecOC_00148] */
    SecOC_Prv_WriteVerificationStatus(rxPduCtx_pst);

    /* TRACE[SWS_SecOC_00087]: clear internal buffer */
    SecOC_Prv_clearRxAuthenticPduContext(rxPduCtx_pst);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_VerificationFailed
 *
 * \brief The function handles the unsuccesful verification: It is checked if the verification status is overwritten
 *        by external. The verification status is propageted via function call SecOC_Prv_WriteVerificationStatus.
 *        After this all internal buffer are cleared and the state is set to IDLE by calling the function
 *        SecOC_Prv_clearRxAuthenticPduContext.
 *
 * \param[in]    SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the secured pdu
 *
 * \param[in]    SecOC_VerificationResultType verificationStatus  new verification status of the pdu
 ***********************************************************************************************************************
*/
void SecOC_Prv_VerificationFailed(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst,
                                  SecOC_VerificationResultType verificationStatus)
{
    PduIdType idx_cuo = rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
    rxPduCtx_pst->verificationStatus_u8 = SecOC_Prv_HandleVerifyStatusOverride(
                                             (*rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo],
                                               verificationStatus);


    /* TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142] */
    if (SECOC_VERIFICATIONFAILURE_OVERWRITTEN == rxPduCtx_pst->verificationStatus_u8)
    {
        /* status is overwritten to success => pass the PDU */
        SecOC_Prv_VerificationSuccessful(rxPduCtx_pst);
    }
    else
    {
        /* TRACE[SWS_SecOC_00213]:*/
        /* For PduTpType cancel reception on upper layer */
        if(FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.pduTpType_b)
        {
            PduR_SecOCTpRxIndication(rxPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo, E_NOT_OK);
        }
        /* TRACE[SWS_SecOC_00141], TRACE[SWS_SecOC_00148] */
        SecOC_Prv_WriteVerificationStatus(rxPduCtx_pst);

        /* TRACE[SWS_SecOC_00087]: verification fails */
        SecOC_Prv_clearRxAuthenticPduContext(rxPduCtx_pst);
    }
}

/**
 ***************************************************************************************************
 * SecOC_Prv_HandleVerificationResult
 *
 * \brief The function checks result of the verification of an authenticator. If it was successful it
 *        checks if the verification state shall be override. The state is overridden if the given freshness
 *        identifier of the I-PDU is equal the freshness identifier of the override state.
 *        The override state is set via function SecOC_VerifyStatusOverride.
 *
 *        SECOC_OVERRIDE_DROP_UNTIL_NOTICE, SECOC_OVERRIDE_DROP_UNTIL_LIMIT, SECOC_OVERRIDE_SKIP_UNTIL_LIMIT:
 *           the state is set to SECOC_NO_VERIFICATION
 *        SECOC_OVERRIDE_PASS_UNTIL_NOTICE, SECOC_OVERRIDE_PASS_UNTIL_LIMIT:
 *            the state is set to SECOC_VERIFICATIONFAILURE_OVERWRITTEN
 *        SECOC_OVERRIDE_TO_PASS: the state is set to SECOC_VERIFICATIONSUCCESS
 *        If the verification state is still successful the PduR is triggered for forwarding the pdu.
 *        In addition the functions handles negative verification results. It returns true if an det error shall
 *        be called by the calling function. This is done because the function can be called by two different
 *        functions and the det error requires an function identifier.
 *        If SecOC is configured without cryptographic interface or to ignore the verification result the pdu is
 *        forwarded to PduR in any cases.
 *
 * \param[inout] SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the pdu
 *
 * \param[in]    Std_ReturnType               authResult   result of the cryptographic interface
 *
 * \return       TRUE    det error shall be called
 *               FALSE   no det error required
 ***************************************************************************************************
 */
boolean SecOC_Prv_HandleVerificationResult(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst,
                                           Std_ReturnType authResult)
{
    boolean detErrorCall_b = FALSE;
    PduIdType idx_cuo = rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
    uint16 valueID_u16 = (*rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo];
    SecOC_OverrideStatusType overrideStatus_u8 = SecOC_Prv_fetchOverrideStatus(valueID_u16);
    SecOC_Prv_CryptIf_en cryptIf_e = SECOC_CRYPTIF_NONE;

    switch (authResult)
    {
        case E_OK:
        {
            idx_cuo = rxPduCtx_pst->pduConfig_pst->cryptIf_cst.idx_cuo;
            cryptIf_e = (*rxPduCtx_pst->pduConfig_pst->cryptIf_cst.value_pace)[idx_cuo];

            if ((FALSE == rxPduCtx_pst->pduConfig_pst->packedBits_stb.syncMod_b)
                && (SECOC_CRYPTIF_NONE != cryptIf_e)
                && (SECOC_OVERRIDE_TO_PASS  != overrideStatus_u8)
                && (SECOC_RX_STATE_MAC_VERIFY_FINISHED_E != rxPduCtx_pst->status_u8))
            {
                /* crypt interface is called asynchronously (only possible for Csm) */
                /* => wait for result via callbacks                                 */
                rxPduCtx_pst->status_u8 = SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E;
            }

            if ((SECOC_RX_STATE_VERIFY_E == rxPduCtx_pst->status_u8)
                || (SECOC_RX_STATE_MAC_VERIFY_FINISHED_E == rxPduCtx_pst->status_u8))
            {
                /* authentic I-PDU is ready for verification (SECOC_RX_STATE_VERIFY_E) */
                /* or callback with mac verification result is received (SECOC_RX_STATE_MAC_VERIFY_FINISHED_E) */
                if (FALSE != SecOC_Prv_CurrentGenConfig_st.ignoreVerificationResult_b)
                {
                    if (SecOC_Prv_VerificationResultSuccess (rxPduCtx_pst,
                                                             valueID_u16))
                    {
                        /* Set verificationStatus to success to propagate status in function SecOC_Prv_VerificationSuccessful */
                        rxPduCtx_pst->verificationStatus_u8 = SECOC_VERIFICATIONSUCCESS;
                    }
                    else
                    {
                        /* TRACE[SWS_SecOC_00239]: reset authentication build counter */
                        rxPduCtx_pst->authAttempts_u16 = 0;

                        /* Set verificationStatus to fail to propagate status in function SecOC_Prv_VerificationSuccessful */
                        rxPduCtx_pst->verificationStatus_u8 = SECOC_VERIFICATIONFAILURE;
                    }

                    /* verification result is ignored => handle PDU successfully */
                    /* TRACE[SWS_SecOC_00242], TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142] */
                    rxPduCtx_pst->verificationStatus_u8 = SecOC_Prv_HandleVerifyStatusOverride(
                                                               valueID_u16,
                                                               rxPduCtx_pst->verificationStatus_u8);

                    SecOC_Prv_VerificationSuccessful(rxPduCtx_pst);
                }
                else
                {
                    if (SecOC_Prv_VerificationResultSuccess (rxPduCtx_pst,
                                                             valueID_u16))
                    {
                        /* TRACE[SWS_SecOC_00242], TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142] */
                        rxPduCtx_pst->verificationStatus_u8 = SecOC_Prv_HandleVerifyStatusOverride(
                            valueID_u16, SECOC_VERIFICATIONSUCCESS);

                        /* status is still success => handle PDU */
                        SecOC_Prv_VerificationSuccessful(rxPduCtx_pst);
                    }
                    else
                    {
                        SecOC_Prv_VerificationRetry(rxPduCtx_pst, SECOC_VERIFICATIONFAILURE,
                                                     &rxPduCtx_pst->verifyAttempts_u16,
                                                     rxPduCtx_pst->pduConfig_pst->authenticationVerifyAttempts_u16);
                        /* TRACE[SWS_SecOC_00239]: reset authentication build counter */
                        rxPduCtx_pst->authAttempts_u16 = 0;
                    }
                }
            }
            break;
        }
        
        case CRYPTO_E_KEY_NOT_VALID:
        case E_NOT_OK:
        {
            /* TRACE[SWS_SecOC_RB_00241]: non recoverable error from MacVerify => verification failed */
            SecOC_Prv_VerificationFailed(rxPduCtx_pst, SECOC_AUTHENTICATIONBUILDFAILURE);
            detErrorCall_b = TRUE;
            break;
        }

        case CRYPTO_E_BUSY:
        {
            /* recoverable error from MacVerify : */
            /* TRACE[SWS_SecOC_00237]: increment authentication build counter */
            /* TRACE[SWS_SecOC_00238]: retry verification */
            /* TRACE[SWS_SecOC_00240]: If authentication build counter expires, set SECOC_AUTHENTICATIONBUILDFAILURE */
            SecOC_Prv_VerificationRetry(rxPduCtx_pst, SECOC_AUTHENTICATIONBUILDFAILURE,
                                        &rxPduCtx_pst->authAttempts_u16,
                                        rxPduCtx_pst->pduConfig_pst->authenticationBuildAttempts_u16);

            if (SECOC_RX_STATE_AUTHENTIC_IDLE_E == rxPduCtx_pst->status_u8)
            {
                /* invoke det error call */
                detErrorCall_b = TRUE;
            }
            break;
        }

        case CRYPTO_E_JOB_CANCELED:
        {
            /* csm job was canceled, release authentic context */
            SecOC_Prv_clearRxAuthenticPduContext(rxPduCtx_pst);
            break;
        }

        default:
        {
            /* MR12 RULE 16.4 VIOLATION: Switch covers all relevant cases, empty default clause required
             * by coding guidelines */
            break;
        }
    }


    return (detErrorCall_b);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_createSecPdu
 *
 * \brief  The function creates the secured I-PDU by coping the payload of the received authentic I-PDU,
 *         the truncated freshness value and the generated and truncated authenticator to the internal buffer in big
 *         endian byte order (TRACE[SWS_SecOC_00011]).
 *
 * \param[inout] SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst   context buffer of the secured PDU
 *
 * \param[in]    const uint8   authenticator_pu8  generated authenticator
 *
 ***********************************************************************************************************************
*/
void SecOC_Prv_createSecPdu(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst,
                            const uint8 *authenticator_pu8)
{
    PduInfoType securedPdu_st = { 0 };
    Std_ReturnType result_en = E_NOT_OK;
    uint8 securedHeaderLengthInBits_u8 = 0u;
    PduLengthType lengthUnusedAreaBytesLeft_uo = 0u;
    PduLengthType lengthUnusedAreaBitsLeft_uo = 0u;
    PduLengthType actualPduLengthBits_uo = 0u;
    PduLengthType configPduLengthBits_uo = 0u;
    uint8 index_u8 = 0u;


    /* Get the secured header length */
    securedHeaderLengthInBits_u8 = SecOC_Prv_TxGetSecuredHeaderLength(txSecuredPduCtx_pst);

    /* It copies the length of Authentic pdu in Secured Header if header exists. */
    if(securedHeaderLengthInBits_u8 > 0)
    {
        SecOC_Prv_CopyLengthInSecuredHeader(txSecuredPduCtx_pst);
    }

    /* TRACE[SWS_SecOC_000941], TRACE[SWS_SecOC_00037]: copy freshness value to buffer of secured PDU */
    if (txSecuredPduCtx_pst->freshnessValueTxLength_u8 > 0U)
    {
        uint32 offset = ((txSecuredPduCtx_pst->freshnessValueTxLength_u8 + 7u) & 0xFFFFFFF8uL)
                    - txSecuredPduCtx_pst->freshnessValueTxLength_u8;

        SecOC_Prv_CopyBits(
             txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8,                  /* out: destination */
             txSecuredPduCtx_pst->payloadLength_uo + securedHeaderLengthInBits_u8,  /*  in: destination bit position */
             txSecuredPduCtx_pst->freshnessTruncValue_au8,                          /*  in: source */
             offset,                                                                /*  in: source bit position */
             (uint32)(txSecuredPduCtx_pst->freshnessValueTxLength_u8)               /*  in: number of bits */
             );
    }

    /* TRACE[SWS_SecOC_00037], TRACE[SWS_SecOC_00036]: */
    /* copy most significant bits of authenticator to buffer of secured PDU */
    SecOC_Prv_CopyBits(
        txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8,             /* out: destination */
        txSecuredPduCtx_pst->payloadLength_uo + securedHeaderLengthInBits_u8
        + txSecuredPduCtx_pst->freshnessValueTxLength_u8,                 /*  in: destination bit position */
        authenticator_pu8,                                                /*  in: source */
        0,                                                                /*  in: source bit position */
        txSecuredPduCtx_pst->pduConfig_pst->authInfoTxLength_u16          /*  in: number of bits */
    );

    /**
     * clear internal buffer
     */
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)txSecuredPduCtx_pst->pduConfig_pst->authenticator_pu8, (uint32)(SECOC_CMAC_AES128v21_BLOCK_LEN));

    /* calculate actual length of secured PDU in bytes */
    actualPduLengthBits_uo = (PduLengthType)(securedHeaderLengthInBits_u8
            + txSecuredPduCtx_pst->payloadLength_uo
            + txSecuredPduCtx_pst->freshnessValueTxLength_u8
            + txSecuredPduCtx_pst->pduConfig_pst->authInfoTxLength_u16);
    txSecuredPduCtx_pst->actualPduLength_uo    = ((actualPduLengthBits_uo + 7u) >> 3u);

    /* TRACE[SWS_SecOC_00269]: add default pattern for unused areas */
    /* calculate config length in bits */
    configPduLengthBits_uo = (txSecuredPduCtx_pst->pduConfig_pst->pduLength_uo << 3u);
    if (actualPduLengthBits_uo < configPduLengthBits_uo)
    {
        /* length of used area is less than the configured length => fill unused area with default pattern */
        /* calculate first if single bits after used area are available */
         lengthUnusedAreaBitsLeft_uo = (configPduLengthBits_uo - actualPduLengthBits_uo) % 8u;

        if (lengthUnusedAreaBitsLeft_uo != 0u)
        {
            SecOC_Prv_CopyBits(
                txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8,  /* out: destination */
                actualPduLengthBits_uo,                                /*  in: destination bit position */
                &txSecuredPduCtx_pst->pduConfig_pst->unusedAreaDef_u8, /*  in: source */
                0,                                                     /*  in: source bit position */
                lengthUnusedAreaBitsLeft_uo                            /*  in: number of bits */
           );
        }
        /* copy default pattern into complete bytes */
        lengthUnusedAreaBytesLeft_uo = txSecuredPduCtx_pst->pduConfig_pst->pduLength_uo - txSecuredPduCtx_pst->actualPduLength_uo;
        for(index_u8 = 0u; index_u8 < lengthUnusedAreaBytesLeft_uo; index_u8++)
        {
           txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8[txSecuredPduCtx_pst->actualPduLength_uo + index_u8]
                                                 = txSecuredPduCtx_pst->pduConfig_pst->unusedAreaDef_u8;
        }
    }

    /* supply parameter with secured PDU data */
    securedPdu_st.SduDataPtr = (uint8*)(txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8);
    securedPdu_st.SduLength = txSecuredPduCtx_pst->pduConfig_pst->pduLength_uo;
    securedPdu_st.MetaDataPtr = txSecuredPduCtx_pst->MetaDataPtr_pu8;

    /* TRACE[SWS_SecOC_00062], TRACE[SWS_SecOC_00067], TRACE[SWS_SecOC_00072], TRACE[SWS_SecOC_00180]: */
    /* forward the secured pdu to the PduR */
    result_en = SecOC_Prv_AuthenticationFinished(
            txSecuredPduCtx_pst->pduConfig_pst->pduRId_uo,
            (const PduInfoType*)&securedPdu_st);

    /* TRACE[SWS_SecOC_00226]: */
    /* Reset the buffer position for transport protocol PDUs and authentication attempt counter of the PDU. */
    txSecuredPduCtx_pst->authAttempts_u16 = 0u;
    txSecuredPduCtx_pst->bufferPosition_uo = 0u;

    if (E_OK == result_en)
    {
        txSecuredPduCtx_pst->status_u8 = SECOC_TX_STATE_SENT_E;
        /* Secured I-PDU has been initiated for transmission */
        if (FALSE != txSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.txConfirm_b)
        {
            SecOC_Prv_SPduTxConfirmation(txSecuredPduCtx_pst->pduConfig_pst->freshnessValueId_u16);
        }
    }
    else
    {
        /* Clear buffer if the PduR doesn't accept the PDU. */
        SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_createPduCollection
 *
 * \brief  The function creates the secured I-PDU by coping the payload of the received authentic I-PDU,
 *         the truncated freshness value and the generated and truncated authenticator to the internal buffer in big
 *         endian byte order (TRACE[SWS_SecOC_00011]).
 *
 * \param[inout] SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst   context buffer of the secured PDU
 *
 * \param[in]    const uint8   authenticator_pu8  generated authenticator
 *
 ***********************************************************************************************************************
*/
void SecOC_Prv_createPduCollection(SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst,
                                      const uint8 *authenticator_pu8)
{
    PduInfoType authenticPdu_st = { 0 };
    PduInfoType cryptographicPdu_st = { 0 };
    uint8 securedHeaderLengthInBits_u8 = 0u;
    Std_ReturnType result_en = E_NOT_OK;
    PduLengthType lengthUnusedArea_uo = 0u;
    PduLengthType lengthUnusedAreaBytesLeft_uo = 0u;
    PduLengthType lengthUnusedAreaBitsLeft_uo = 0u;
    PduLengthType lengthUnusedAreaOffset_uo = 0u;
    PduLengthType lengthCryptoBits_uo = 0u;
    PduLengthType configCryptoPduLengthBits_uo = 0u;
    uint8 index_u8 = 0u;


    /* Get the secured header length */
    securedHeaderLengthInBits_u8 = SecOC_Prv_TxGetSecuredHeaderLength(txSecuredPduCtx_pst);
    /* It copies the length of Authentic pdu in Secured Header if header exists. */
    if(securedHeaderLengthInBits_u8 > 0)
    {
        SecOC_Prv_CopyLengthInSecuredHeader(txSecuredPduCtx_pst);
    }

    /* create cryptographic pdu: TruncatedFreshnessValue | Authenticator | MessageLength */
    if (txSecuredPduCtx_pst->freshnessValueTxLength_u8 > 0U)
    {
        uint32 offset = ((txSecuredPduCtx_pst->freshnessValueTxLength_u8 + 7u) & 0xFFFFFFF8uL)
                        - txSecuredPduCtx_pst->freshnessValueTxLength_u8;

        /* TRACE[SWS_SecOC_00201], TRACE[SWS_SecOC_00209]: copy freshness value to buffer of cryptographic PDU */
        SecOC_Prv_CopyBits(
            txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8,  /* out: destination */
            0u,                                                                 /*  in: destination bit position */
            txSecuredPduCtx_pst->freshnessTruncValue_au8,                       /*  in: source */
            offset,                                                             /*  in: source bit position */
            txSecuredPduCtx_pst->freshnessValueTxLength_u8                      /*  in: number of bits */
        );
    }

    /* TRACE[SWS_SecOC_00036], TRACE[SWS_SecOC_00201], TRACE[SWS_SecOC_00209]: */
    /* copy most significant bits of authenticator to buffer of cryptographic PDU */
    SecOC_Prv_CopyBits(
        txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8,  /* out: destination */
        txSecuredPduCtx_pst->freshnessValueTxLength_u8,                     /*  in: destination bit position */
        authenticator_pu8,                                                  /*  in: source */
        0,                                                                  /*  in: source bit position */
        txSecuredPduCtx_pst->pduConfig_pst->authInfoTxLength_u16            /*  in: number of bits */
    );

    if(0 != txSecuredPduCtx_pst->pduConfig_pst->messageLinkLength_u16)
    {
        /* TRACE[SWS_SecOC_00201], TRACE[SWS_SecOC_00209], TRACE[SWS_SecOC_00210]: */
        /* copy message linker (part of the payload) to buffer of cryptographic PDU */
        SecOC_Prv_CopyBits(
            txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8,  /* out: destination */
            txSecuredPduCtx_pst->freshnessValueTxLength_u8
            +txSecuredPduCtx_pst->pduConfig_pst->authInfoTxLength_u16,          /*  in: destination bit position */
            txSecuredPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,             /*  in: source */
            SECOC_PRV_PAYLOAD_OFFSET
            +txSecuredPduCtx_pst->pduConfig_pst->messageLinkPos_u16 ,           /*  in: source bit position */
            txSecuredPduCtx_pst->pduConfig_pst->messageLinkLength_u16           /*  in: number of bits */
        );
    }

    /**
      * clear internal buffer
      */
    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)txSecuredPduCtx_pst->pduConfig_pst->authenticator_pu8, (uint32)(SECOC_CMAC_AES128v21_BLOCK_LEN));

    txSecuredPduCtx_pst->actualPduLength_uo = (PduLengthType)((securedHeaderLengthInBits_u8
            + txSecuredPduCtx_pst->payloadLength_uo + 7u) >> 3u);
    /* supply parameter with authentic PDU data */
    authenticPdu_st.SduDataPtr = (uint8*)(txSecuredPduCtx_pst->pduConfig_pst->pduBufferOut_pu8);
    authenticPdu_st.SduLength = txSecuredPduCtx_pst->actualPduLength_uo;
    authenticPdu_st.MetaDataPtr = txSecuredPduCtx_pst->MetaDataPtr_pu8;

    /* TRACE[SWS_SecOC_00062], TRACE[SWS_SecOC_00067], TRACE[SWS_SecOC_00072], TRACE[SWS_SecOC_00180]: */
    /* forward the authentic pdu to the PduR */
    result_en = SecOC_Prv_AuthenticationFinished(
        txSecuredPduCtx_pst->pduConfig_pst->pduRId_uo,
        (const PduInfoType*)&authenticPdu_st);

    /* TRACE[SWS_SecOC_00269]: add default pattern for unused areas */
    /* calculate config length of cryptographic PDU in bits */
    configCryptoPduLengthBits_uo = (txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo << 3u);
    /* calculate the length of used area in bits */
    lengthCryptoBits_uo = (PduLengthType)(txSecuredPduCtx_pst->freshnessValueTxLength_u8
                                        + txSecuredPduCtx_pst->pduConfig_pst->authInfoTxLength_u16
                                        + txSecuredPduCtx_pst->pduConfig_pst->messageLinkLength_u16);

    if (lengthCryptoBits_uo < configCryptoPduLengthBits_uo)
    {
        /* length of used area is less than the configured length => fill unused area with default pattern */
        lengthUnusedArea_uo = configCryptoPduLengthBits_uo - lengthCryptoBits_uo;
        lengthUnusedAreaBitsLeft_uo = lengthUnusedArea_uo % 8u;

        if (lengthUnusedAreaBitsLeft_uo != 0u)
        {
            SecOC_Prv_CopyBits(
                txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8,  /* out: destination */
                lengthCryptoBits_uo,                                                /*  in: destination bit position */
                &txSecuredPduCtx_pst->pduConfig_pst->unusedAreaDef_u8,              /*  in: source */
                0,                                                                  /*  in: source bit position */
                lengthUnusedAreaBitsLeft_uo                                         /*  in: number of bits */
            );
        }
        lengthUnusedAreaBytesLeft_uo = (((lengthUnusedArea_uo - lengthUnusedAreaBitsLeft_uo) + 7u) >> 3u);
        lengthUnusedAreaOffset_uo = ((lengthCryptoBits_uo + 7u) >> 3u);
        for(index_u8 = 0u; index_u8 < lengthUnusedAreaBytesLeft_uo; index_u8++)
        {
           txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8[lengthUnusedAreaOffset_uo + index_u8]
                                                 = txSecuredPduCtx_pst->pduConfig_pst->unusedAreaDef_u8;
        }
    }

    /* supply parameter with cryptographic PDU data */
    cryptographicPdu_st.SduDataPtr = (uint8*)(txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8);
    cryptographicPdu_st.SduLength = txSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo;
    cryptographicPdu_st.MetaDataPtr = txSecuredPduCtx_pst->MetaDataPtr_pu8;

    /* TRACE[SWS_SecOC_00062], TRACE[SWS_SecOC_00067], TRACE[SWS_SecOC_00072], TRACE[SWS_SecOC_00180]: */
    /* forward the cryptographic pdu to the PduR */
    result_en |= SecOC_Prv_AuthenticationFinished(
        txSecuredPduCtx_pst->pduConfig_pst->pduRCryptographicPduId_uo,
        (const PduInfoType*)&cryptographicPdu_st);

    /* TRACE[SWS_SecOC_00226]: */
    /* Reset the buffer position for transport protocol PDUs and authentication attempt counter of the PDU. */
    txSecuredPduCtx_pst->authAttempts_u16 = 0u;
    txSecuredPduCtx_pst->bufferPosition_uo = 0u;
    txSecuredPduCtx_pst->cryptographicPduBufferPosition_uo = 0u;

    if (E_OK == result_en)
    {
        txSecuredPduCtx_pst->status_u8 = SECOC_TX_STATE_SENT_E;
        /* Secured I-PDU has been initiated for transmission */
        if (FALSE != txSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.txConfirm_b)
        {
            SecOC_Prv_SPduTxConfirmation(txSecuredPduCtx_pst->pduConfig_pst->freshnessValueId_u16);
        }
    }
    else
    {
        /* Clear buffer if the PduR doesn't accept the PDU. */
        SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
    }
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_createDataforAuthenticationRx
 *
 * \brief   The function creates the data stream requested for authentication and verification.
 *          The data stream is consisting of data identifier, payload of I-PDU and complete freshness value.
 *          If no swap of endian format is configured the data stream is created in big endian format.
 *
 * \param[in]   SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the pdu
 *
 ***********************************************************************************************************************
*/
/*TRACE[SWS_SecOC_00034], TRACE[SWS_SecOC_00046], TRACE[SWS_SecOC_00085]: */
void SecOC_Prv_createDataforAuthenticationRx(SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst)
{
    PduIdType idx_cuo;
    uint16 dataId_u16;
    uint8 freshnessValueLength_u8;
    uint8 freshValTruncLen_u8;
    uint32 securedRxPduOffset_u32 = 0;
    uint32 securedRxPduLength_u32 = 0;

    uint32 freshnessOffset_u32 = 0u; /* Updated in case of SecuredPdus */
    uint8 freshnessValueTxLengthBytesRounded_u8 = 0u;
    uint8 authDataFreshnessLengthBytesRounded_u8 = 0u;
    uint8 authenticPduOffsetInBits_u8 = SecOC_Prv_RxGetAuthenticPduOffset(rxPduCtx_pst->pduConfig_pst);

    idx_cuo = rxPduCtx_pst->pduConfig_pst->dataId_cst.idx_cuo;
    dataId_u16 = (*rxPduCtx_pst->pduConfig_pst->dataId_cst.value_pacu16)[idx_cuo];
    idx_cuo = rxPduCtx_pst->freshnessValueLength_st.idx_cuo;
    freshnessValueLength_u8 = (*rxPduCtx_pst->freshnessValueLength_st.value_pau8)[idx_cuo];
    idx_cuo = rxPduCtx_pst->pduConfig_pst->freshValTruncLen_cst.idx_cuo;
    freshValTruncLen_u8 = (*rxPduCtx_pst->pduConfig_pst->freshValTruncLen_cst.value_pacu8)[idx_cuo];
    /* NULL_PTR check for optional secured area values needed */
    if(NULL_PTR != rxPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.value_pacu32)
    {
        idx_cuo = rxPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.idx_cuo;
        securedRxPduOffset_u32 = (*rxPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.value_pacu32)[idx_cuo];
    }
    if(NULL_PTR != rxPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)
    {
        idx_cuo = rxPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.idx_cuo;
        securedRxPduLength_u32 = (*rxPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)[idx_cuo];
    }

    if(FALSE == rxPduCtx_pst->pduConfig_pst->packedBits_stb.pduColl_b)
    {
        /* Update the offset of freshness for seucred PDU */
        freshnessOffset_u32 = SecOC_Prv_RxGetAuthenticPduOffset(rxPduCtx_pst->pduConfig_pst) + rxPduCtx_pst->actualAuthenticPduLengthInBits_uo;
    }

    /* Update the length of AuthDataBuffer */
    rxPduCtx_pst->authDataBufferLength_u32 = (SECOC_PRV_PAYLOAD_OFFSET + rxPduCtx_pst->actualAuthenticPduLengthInBits_uo + freshnessValueLength_u8 + 7u) >> 3u;

    /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
    SecOC_Prv_MemZero((void*)rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8, rxPduCtx_pst->authDataBufferLength_u32);

    /* copy DataId to the data for authentication */
    rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8[0] = (uint8)(dataId_u16 >> 8U);
    rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8[1] = (uint8)(dataId_u16);

     /* copy payload */
     
    if (TRUE == rxPduCtx_pst->pduConfig_pst->useRxPduSecuredArea_b)
    {
        /* TRACE[SWS_SecOC_00311], TRACE[SWS_SecOC_00312]: */
        /* If secured area is available consider only bytes of this area */
        SecOC_Prv_CopyBits(
            rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,               /* out: destination */
            SECOC_PRV_PAYLOAD_OFFSET,                                      /*  in: destination bit position */
            rxPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,                  /*  in: source */
            (uint32)((8u * securedRxPduOffset_u32) + authenticPduOffsetInBits_u8), /*  in: source bit position */
            (uint32)(8u * securedRxPduLength_u32)                          /*  in: number of bits */
        );
        /* Update the length of AuthDataBuffer in bytes */
        rxPduCtx_pst->authDataBufferLength_u32 = (SECOC_PRV_PAYLOAD_OFFSET
                                                   + (8u * securedRxPduLength_u32)
                                                   +  freshnessValueLength_u8 + 7u) >> 3u;
    }
    else
    {
        /* copy payload */
        SecOC_Prv_CopyBits(
            rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8, /* out: destination */
            SECOC_PRV_PAYLOAD_OFFSET,                        /*  in: destination bit position */
            rxPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,    /*  in: source */
            authenticPduOffsetInBits_u8,                     /*  in: source bit position */
            rxPduCtx_pst->actualAuthenticPduLengthInBits_uo  /*  in: number of bits */
        );
    }

    /* Only extract FV from secured PDU if truncated freshness value length > 0 */
    if (freshValTruncLen_u8 > 0U)
    {
        freshnessValueTxLengthBytesRounded_u8 = (uint8)((freshValTruncLen_u8 + 7u) & 0xFFFFFFF8uL);
        /* TRACE[SWS_SecOC_00042]: get truncated freshness value from the received secured PDU */
        if(FALSE == rxPduCtx_pst->pduConfig_pst->packedBits_stb.pduColl_b)
        {
            SecOC_Prv_CopyBits(
                rxPduCtx_pst->freshnessTruncValue_au8,                     /* out: destination */
                freshnessValueTxLengthBytesRounded_u8
                - freshValTruncLen_u8,                                     /*  in: destination bit position */
                rxPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,              /*  in: source */
                freshnessOffset_u32,                                       /*  in: source bit position */
                freshValTruncLen_u8                                        /*  in: number of bits */
            );
        }
        else
        {
            SecOC_Prv_CopyBits(
                rxPduCtx_pst->freshnessTruncValue_au8,                      /* out: destination */
                freshnessValueTxLengthBytesRounded_u8
                - freshValTruncLen_u8,                                      /*  in: destination bit position */
                rxPduCtx_pst->pduConfig_pst->cryptographicPduBufferIn_pu8,  /*  in: source */
                freshnessOffset_u32,                                        /*  in: source bit position */
                freshValTruncLen_u8                                         /*  in: number of bits */
            );
        }
    }

    /* extract authentic data freshness value if authentic data freshness length > 0 */
    /* and packedBits_stb.authDataFresh_b flag is set to TRUE */
    if ((rxPduCtx_pst->pduConfig_pst->authDataFreshnessLength_u16 > 0U) &&
       (FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.authDataFresh_b))
    {
        authDataFreshnessLengthBytesRounded_u8 = (uint8)((rxPduCtx_pst->pduConfig_pst->authDataFreshnessLength_u16 + 7u) & 0xFFFFFFF8uL);

        SecOC_Prv_CopyBits(
            rxPduCtx_pst->authDataFreshnessValue_au8,                                                     /* out: destination */
            authDataFreshnessLengthBytesRounded_u8
            - rxPduCtx_pst->pduConfig_pst->authDataFreshnessLength_u16,                                    /*  in: destination bit position */
            rxPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,                                                  /*  in: source */
            rxPduCtx_pst->pduConfig_pst->authDataFreshnessStartPosition_u16 + authenticPduOffsetInBits_u8, /*  in: source bit position */
            rxPduCtx_pst->pduConfig_pst->authDataFreshnessLength_u16                                       /*  in: number of bits */
        );
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_getFreshnessValueRx
 *
 * \brief   The function gets the complete freshness value for the mac verification
 *
 * \param[in]   SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the pdu
 *
 * \return      Result of the function call:
 *                              - E_NOT_OK: an error occurred, request failed
 *                              - E_OK    : request successful
 ***********************************************************************************************************************
*/
/*TRACE[SWS_SecOC_00034], TRACE[SWS_SecOC_00046], TRACE[SWS_SecOC_00085]: */
Std_ReturnType SecOC_Prv_getFreshnessValueRx(const SecOC_Prv_RxAuthenticPduContext_tst * const rxPduCtx_pst)
{
    PduIdType idx_cuo;
    uint16 valueID_u16;
    uint8 freshnessValueLength_u8;
    uint8 freshValTruncLen_u8;
    uint32 securedRxPduLength_u32 = 0;

    Std_ReturnType result_en = E_NOT_OK;
    uint8 freshnessValue_au8[SECOC_MAX_FRESHNESS_SIZE] = {0u};
    boolean useAuthDataFreshness_b = rxPduCtx_pst->pduConfig_pst->packedBits_stb.authDataFresh_b;

    idx_cuo = rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
    valueID_u16 = (*rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo];
    idx_cuo = rxPduCtx_pst->pduConfig_pst->freshValTruncLen_cst.idx_cuo;
    freshValTruncLen_u8 = (*rxPduCtx_pst->pduConfig_pst->freshValTruncLen_cst.value_pacu8)[idx_cuo];
    /* NULL_PTR check for optional secured area values needed */
    if(NULL_PTR != rxPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)
    {
        idx_cuo = rxPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.idx_cuo;
        securedRxPduLength_u32 = (*rxPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)[idx_cuo];
    }

    idx_cuo = rxPduCtx_pst->freshnessValueLength_st.idx_cuo;
    /* Try to get the complete freshness value from freshenss manager or callout function */
    result_en = SecOC_Prv_GetRxFreshness(
                    valueID_u16,
                    rxPduCtx_pst->freshnessTruncValue_au8,
                    freshValTruncLen_u8,
                    rxPduCtx_pst->authDataFreshnessValue_au8,
                    rxPduCtx_pst->pduConfig_pst->authDataFreshnessLength_u16,
                    rxPduCtx_pst->verifyAttempts_u16,
                    freshnessValue_au8,  /* out: complete freshness value */
                    &((*rxPduCtx_pst->freshnessValueLength_st.value_pau8)[idx_cuo]),
                    useAuthDataFreshness_b);
    freshnessValueLength_u8 = (*rxPduCtx_pst->freshnessValueLength_st.value_pau8)[idx_cuo];

    if (E_OK == result_en)
    {
        /* pack complete freshness value into data for authentication */
         
        if (TRUE == rxPduCtx_pst->pduConfig_pst->useRxPduSecuredArea_b)
        {
            SecOC_Prv_CopyBits(
                    rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,                  /* out: destination */
                    SECOC_PRV_PAYLOAD_OFFSET + (8u * securedRxPduLength_u32),         /* in: destination bit position */
                    freshnessValue_au8,                                               /* in: source */
                    0,                                                                /* in: source bit position */
                    freshnessValueLength_u8                                           /* in: number of bits */
            );
        }
        else
        {
            SecOC_Prv_CopyBits(
                    rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,                 /* out: destination */
                    SECOC_PRV_PAYLOAD_OFFSET +
                                    rxPduCtx_pst->actualAuthenticPduLengthInBits_uo, /* in: destination bit position */
                    freshnessValue_au8,                                              /* in: source */
                    0,                                                               /* in: source bit position */
                    freshnessValueLength_u8                                          /* in: number of bits */
            );
        }
    }


    return (result_en);
}

/**
 ***************************************************************************************************
 * Internal function used for getting a pointer to the Rx context buffer in a thread-safe way
 *
 * \param[in]  pduIndex   index of the PDU to which the context buffer is allocated
 *
 * \return     pointer to context buffer if available, NULL otherwise
 ***************************************************************************************************
 */
SecOC_Prv_RxSecuredPduContext_tst* SecOC_Prv_RxSecuredContextBufferAllocate(PduIdType pduIndex)
{
    SecOC_Prv_RxSecuredPduContext_tst *rxPduContext_pst = NULL_PTR;


    SchM_Enter_SecOC_RxContext(pduIndex);

    if (!SecOC_Prv_RxSecuredPduContext_ast[pduIndex].isLocked_b)
    {
        SecOC_Prv_RxSecuredPduContext_ast[pduIndex].isLocked_b = TRUE;
        rxPduContext_pst = &SecOC_Prv_RxSecuredPduContext_ast[pduIndex];
    }

    SchM_Exit_SecOC_RxContext(pduIndex);


    return (rxPduContext_pst);
}

/**
 ***************************************************************************************************
 * Internal function used for getting a pointer to the Rx context buffer in a thread-safe way
 *
 * \param[in]  pduIndex  index of the PDU to which the context buffer is allocated
 *
 * \return     pointer to context buffer if available, NULL otherwise
 ***************************************************************************************************
 */
SecOC_Prv_RxAuthenticPduContext_tst* SecOC_Prv_RxAuthenticContextBufferAllocate(PduIdType pduIndex)
{
    SecOC_Prv_RxAuthenticPduContext_tst *rxPduContext_pst = NULL_PTR;


    SchM_Enter_SecOC_RxContext(pduIndex);

    if (!SecOC_Prv_RxAuthenticPduContext_ast[pduIndex].isLocked_b)
    {
        SecOC_Prv_RxAuthenticPduContext_ast[pduIndex].isLocked_b = TRUE;
        rxPduContext_pst = &SecOC_Prv_RxAuthenticPduContext_ast[pduIndex];
        rxPduContext_pst->pduIndex_u32 = pduIndex;
    }

    SchM_Exit_SecOC_RxContext(pduIndex);


    return (rxPduContext_pst);
}

/**
 ***************************************************************************************************
 * Internal function used for releasing a pointer to the Rx context buffer in a thread-safe way
 *
 * \param[in,out]  rxPduContext_ppst   address of pointer to context buffer, set to NULL after release
 *
 ***************************************************************************************************
 */
void SecOC_Prv_RxAuthenticContextBufferRelease(SecOC_Prv_RxAuthenticPduContext_tst** rxPduContext_ppst)
{
    if (NULL_PTR != *rxPduContext_ppst)
    {
        (*rxPduContext_ppst)->isLocked_b = FALSE;
        *rxPduContext_ppst = NULL_PTR;
    }
}

/**
 ***************************************************************************************************
 * Internal function used for releasing a pointer to the Rx context buffer in a thread-safe way
 *
 * \param[in,out]  rxPduContext_ppst   address of pointer to context buffer, set to NULL after release
 *
 ***************************************************************************************************
 */
void SecOC_Prv_RxSecuredContextBufferRelease(SecOC_Prv_RxSecuredPduContext_tst** rxPduContext_ppst)
{
    if (NULL_PTR != *rxPduContext_ppst)
    {
        (*rxPduContext_ppst)->isLocked_b = FALSE;
        *rxPduContext_ppst = NULL_PTR;
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_createDataforAuthenticationTx
 *
 * \brief   The function creates the data stream requested for authentication and verification.
 *          The data stream is consisting of data identifier, payload of I-PDU and complete freshness value (optional).
 *
 * \param[in]   SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst   pointer to private context buffer of the pdu
 *
 * \return      Result of the function call:
 *                              - E_NOT_OK: an error occurred, request failed
 *                              - E_OK    : request successful
 ***********************************************************************************************************************
*/
/*TRACE[SWS_SecOC_00034], TRACE[SWS_SecOC_00046], TRACE[SWS_SecOC_00085]: */
Std_ReturnType SecOC_Prv_createDataforAuthenticationTx(SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint8 freshnessValue_au8[SECOC_MAX_FRESHNESS_SIZE] = {0u};
    boolean truncFresh_b = txPduCtx_pst->pduConfig_pst->packedBits_stb.truncFresh_b;

     
    if (TRUE == txPduCtx_pst->pduConfig_pst->useTxPduSecuredArea_b)
    {
        /* TRACE[SWS_SecOC_00311], TRACE[SWS_SecOC_00312]: */
        /* If secured area is available consider only bytes of this area */
        txPduCtx_pst->authDataBufferLength_u32 = (SECOC_PRV_PAYLOAD_OFFSET
                                                   + (8u * txPduCtx_pst->pduConfig_pst->securedTxPduLength_u32)
                                                   + txPduCtx_pst->freshnessValueLength_u8 + 7u) >> 3u;
    }
    else
    {
        txPduCtx_pst->authDataBufferLength_u32 = (SECOC_PRV_PAYLOAD_OFFSET + txPduCtx_pst->payloadLength_uo
                                                   + txPduCtx_pst->freshnessValueLength_u8 + 7u) >> 3u;
    }

    txPduCtx_pst->pduConfig_pst->authDataBuffer_pu8[0u] = (uint8)(txPduCtx_pst->pduConfig_pst->dataId_u16 >> 8u);
    txPduCtx_pst->pduConfig_pst->authDataBuffer_pu8[1u] = (uint8)(txPduCtx_pst->pduConfig_pst->dataId_u16);

    if (txPduCtx_pst->freshnessValueLength_u8 > 0u)
    {
        result_en = SecOC_Prv_GetTxFreshness(
                       txPduCtx_pst->pduConfig_pst->freshnessValueId_u16,
                       freshnessValue_au8,
                       &txPduCtx_pst->freshnessValueLength_u8,
                       txPduCtx_pst->freshnessTruncValue_au8,
                       &txPduCtx_pst->freshnessValueTxLength_u8,
                       truncFresh_b);

        if (E_OK == result_en)
        {
            /* pack complete freshness value into data for authentication */
            
            if (TRUE == txPduCtx_pst->pduConfig_pst->useTxPduSecuredArea_b)
            {
                SecOC_Prv_CopyBits(
                        txPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,             /* out: destination */
                        (SECOC_PRV_PAYLOAD_OFFSET +
                        (8u * txPduCtx_pst->pduConfig_pst->securedTxPduLength_u32)), /*  in: destination bit position */
                        freshnessValue_au8,                                          /*  in: source */
                        0,                                                           /*  in: source bit position */
                        (uint32)txPduCtx_pst->freshnessValueLength_u8                /*  in: number of bits */
                );
            }
            else
            {
                SecOC_Prv_CopyBits(
                        txPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,             /* out: destination */
                        SECOC_PRV_PAYLOAD_OFFSET + txPduCtx_pst->payloadLength_uo,   /*  in: destination bit position */
                        freshnessValue_au8,                                          /*  in: source */
                        0,                                                           /*  in: source bit position */
                        (uint32)txPduCtx_pst->freshnessValueLength_u8                /*  in: number of bits */
                );
            }
        }
        else
        {
            /* Empty else clause required by MISRA2012 Rule 17.7 */
        }
    }
    else
    {
         result_en = E_OK;
    }


    return (result_en);
}

/**
 ***************************************************************************************************
 * Internal function used for getting a pointer to the Tx context buffer in a thread-safe way
 *
 * \param[in]  pduIndex  index of the PDU to which the context buffer is allocated
 *
 * \return     pointer to context buffer if available, NULL otherwise
 ***************************************************************************************************
 */
SecOC_Prv_TxSecuredPduContext_tst* SecOC_Prv_TxSecuredContextBufferAllocate(PduIdType pduIndex)
{
    SecOC_Prv_TxSecuredPduContext_tst *txPduContext_pst = NULL_PTR;


    SchM_Enter_SecOC_TxContext(pduIndex);

    if (!SecOC_Prv_TxSecuredPduContext_ast[pduIndex].isLocked_b)
    {
        SecOC_Prv_TxSecuredPduContext_ast[pduIndex].isLocked_b = TRUE;
        txPduContext_pst = &SecOC_Prv_TxSecuredPduContext_ast[pduIndex];
        txPduContext_pst->pduIndex_u32 = pduIndex;
    }

    SchM_Exit_SecOC_TxContext(pduIndex);


    return txPduContext_pst;
}

/**
 ***************************************************************************************************
 * Internal function used for releasing a pointer to the Tx context buffer in a thread-safe way
 *
 * \param[in,out]  txPduContext_ppst   address of pointer to context buffer, set to NULL after release
 *
 ***************************************************************************************************
 */
void SecOC_Prv_TxSecuredContextBufferRelease(SecOC_Prv_TxSecuredPduContext_tst** txPduContext_ppst)
{
    if (NULL_PTR != *txPduContext_ppst)
    {
        (*txPduContext_ppst)->isLocked_b = FALSE;
        *txPduContext_ppst = NULL_PTR;
    }
}

/**
 ***************************************************************************************************
 * Internal function used for getting a pointer to the Tx context buffer in a thread-safe way
 *
 * \param[in]  pduId    index of the PDU to which the context buffer is allocated
 *
 * \return     pointer to context buffer if available, NULL otherwise
 ***************************************************************************************************
 */
SecOC_Prv_TxAuthenticPduContext_tst* SecOC_Prv_TxAuthenticContextBufferAllocate(PduIdType pduIndex)
{
    SecOC_Prv_TxAuthenticPduContext_tst *txPduContext_pst = NULL_PTR;


    SchM_Enter_SecOC_TxContext(pduIndex);

    if (!SecOC_Prv_TxAuthenticPduContext_ast[pduIndex].isLocked_b)
    {
        SecOC_Prv_TxAuthenticPduContext_ast[pduIndex].isLocked_b = TRUE;
        txPduContext_pst = &SecOC_Prv_TxAuthenticPduContext_ast[pduIndex];
    }

    SchM_Exit_SecOC_TxContext(pduIndex);


    return txPduContext_pst;
}

/**
 ***************************************************************************************************
 * Internal function used for releasing a pointer to the Tx context buffer in a thread-safe way
 *
 * \param[in,out]  txPduContext_ppst   address of pointer to context buffer, set to NULL after release
 *
 ***************************************************************************************************
 */
void SecOC_Prv_TxAuthenticContextBufferRelease(SecOC_Prv_TxAuthenticPduContext_tst** txPduContext_ppst)
{
    if (NULL_PTR != *txPduContext_ppst)
    {
        (*txPduContext_ppst)->isLocked_b = FALSE;
        *txPduContext_ppst = NULL_PTR;
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_TxGetSecuredHeaderLength
 *
 * \brief  This function returns the length of secured header in bits in case the PDU was configured to include the Secure Header.
 *
 * \param[in]    SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pcst   pointer to private context buffer of the secured pdu
 *
 * \return  Result of the function call:
 *                      uint8     - secured header length from configuration
 *
 ***********************************************************************************************************************
 */
uint8 SecOC_Prv_TxGetSecuredHeaderLength(const SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pcst)
{
    uint8 securedHeaderLengthInBits = 0u;

    if(0u != txPduCtx_pcst->pduConfig_pst->securedHeaderLength_u8)
    {
        securedHeaderLengthInBits = txPduCtx_pcst->pduConfig_pst->securedHeaderLength_u8 * 8u;
    }

    return securedHeaderLengthInBits;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_TxGetPduType
 *
 * \brief  This function checks boundary to get the pdu type
 *
 * \param[in]   PduIdType id    pdu id of secured PDU / cryptographic PDU / secured PDU
 *
 * \return  Result of the function call:
 *                      - SECOC_SECURED_PDU
 *                      - SECOC_COLLECTION_AUTHENTIC_PDU
 *                      - SECOC_COLLECTION_CRYPTOGRAPHIC_PDU
 *
 * \return  uint8
 ***********************************************************************************************************************
 */
uint8 SecOC_Prv_TxGetPduType(PduIdType id)
{
    (void)id;

    return SECOC_SECURED_PDU;
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_SaveVerifyStatusOverride
 *
 * \brief  This function verifies if the freshnessValueId is not yet registered, saves the parameters in the
 *         VerifyStatusOverride buffer and activates the new entry. If the freshnessValueId is already registered or
 *         there is no available entry in the VerifyStatusOverride buffer this functions returns E_NOT_OK.
 *
 * \param[in]    uint32 index_u32        index of the override status for which the request is set
 *
 * \param[in]    uint8 overrideStatus    override status
 * \param[in]    uint8 numberOfMessagesToOverride  number of messages(secured I-PDUs) which are override if
 *                                                 overrideStatus is equal OVERRIDE_TO_FAIL_NUMBER
 *
 ***********************************************************************************************************************
*/
void SecOC_Prv_SaveVerifyStatusOverride(uint32 index_u32,
                                        SecOC_OverrideStatusType overrideStatus,
                                        uint8  numberOfMessagesToOverride)
{
    /* TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142] */

    SchM_Enter_SecOC_SaveVerifyStatusOverride();
    SecOC_Prv_VerifyStatusOverride_ast[index_u32].overrideStatus_u8 = overrideStatus;
    SecOC_Prv_VerifyStatusOverride_ast[index_u32].numberOfMessagesToOverride_u8 = numberOfMessagesToOverride;
    SecOC_Prv_VerifyStatusOverride_ast[index_u32].numberOfOverriddenMessages_u8 = 0;
    SchM_Exit_SecOC_SaveVerifyStatusOverride();
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_CounterNumberOfMessagesAndSetState
 *
 * \brief  this function counts the number of messages to override. If maximum is reached the override state is
 *         reset to SECOC_OVERRIDE_CANCEL.
 *
 * \param[in]    uint32 index_u32        index of the override status for which the request is set
 ***********************************************************************************************************************
*/
void SecOC_Prv_CounterNumberOfMessagesAndSetState(uint32 index_u32)
{
     /* TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142] */
     SchM_Enter_SecOC_SaveVerifyStatusOverride();
     SecOC_Prv_VerifyStatusOverride_ast[index_u32].numberOfOverriddenMessages_u8++;

     if (SecOC_Prv_VerifyStatusOverride_ast[index_u32].numberOfMessagesToOverride_u8 ==
         SecOC_Prv_VerifyStatusOverride_ast[index_u32].numberOfOverriddenMessages_u8)
     {
        SchM_Exit_SecOC_SaveVerifyStatusOverride();
        SecOC_Prv_SaveVerifyStatusOverride(index_u32, SECOC_OVERRIDE_CANCEL, 0);
     }
     else
     {
        SchM_Exit_SecOC_SaveVerifyStatusOverride();
     }

 }

/**
 ***********************************************************************************************************************
 * SecOC_Prv_HandleVerifyStatusOverride
 *
 * \brief  This function searches the VerifyStatusOverride buffer for this ValueId and returns the according
 *         verificationStatus when found and numberOfMessagesToOverride_u8 is not reached.
 *
 * \param[in]    uint16  ValueId   value identifier for which the request is set
 *
 * \param[in]    SecOC_VerificationResultType verificationStatus verification status before handling of overrideStatus
 *
 * \return  Result of the function call: SecOC_VerificationResultType
 *               - SECOC_VERIFICATIONFAILURE: verification status after handling of overrideStatus
 *               - SECOC_VERIFICATIONSUCCESS: verification status after handling of overrideStatus
 *               - SECOC_NO_VERIFICATION:      No verification attempt was performed on this IPDU and the I-PDU was passed on to the upper layer "as is"
 *               - SECOC_VERIFICATIONFAILURE_OVERWRITTEN:Verification failed, but the IPDU was passed on to the upper layer due to the override status for this PDU.
 ***********************************************************************************************************************
*/
SecOC_VerificationResultType SecOC_Prv_HandleVerifyStatusOverride(uint16 valueId,
                                                                  SecOC_VerificationResultType verificationStatus)
{
    /* TRACE[SWS_SecOC_00122], TRACE[SWS_SecOC_00142] */
    uint32 index_u32;
    SecOC_VerificationResultType result_en = verificationStatus;

    for(index_u32 = 0; index_u32 < SECOC_MAX_VERIFY_STATUS_OVERRIDE; index_u32++)
    {
        if(valueId == SecOC_Prv_Rx_Lookup_ValueId_pcu16[index_u32])
        {
            switch(SecOC_Prv_VerifyStatusOverride_ast[index_u32].overrideStatus_u8)
            {
                case SECOC_OVERRIDE_DROP_UNTIL_NOTICE:
                {
                    result_en = SECOC_NO_VERIFICATION;
                    break;
                }
                case SECOC_OVERRIDE_DROP_UNTIL_LIMIT:
                {
                    result_en = SECOC_NO_VERIFICATION;
                    SecOC_Prv_CounterNumberOfMessagesAndSetState(index_u32);
                    break;
                }
                case SECOC_OVERRIDE_TO_PASS:
                {
                    result_en = SECOC_VERIFICATIONSUCCESS;
                    break;
                }

                default:
                {
                    /* MR12 RULE 16.4 VIOLATION: Switch covers all enum values, empty default clause required
                     * by coding guidelines. */
                    break;
                }
            }
        }
    }
    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_WriteVerificationStatus
 *
 * \brief  This function propagates the verification status according to SecOCVerificationStatusPropagationMode and
 *         VerificationStatus.
 *
 * \param[in]    SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the pdu
 ***********************************************************************************************************************
*/
void SecOC_Prv_WriteVerificationStatus(const SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst)
{
    /* TRACE[SWS_SecOC_00141], TRACE[SWS_SecOC_00148], TRACE[SWS_SecOC_00048] */
    PduIdType idx_cuo;
    SecOC_Prv_VerifyPropType_en VerificationStatusPropagationMode;
    SecOC_VerificationStatusType verificationStatus_st = {0u};
    idx_cuo = rxPduCtx_pst->pduConfig_pst->verifyPropMode_cst.idx_cuo;
    VerificationStatusPropagationMode = (*rxPduCtx_pst->pduConfig_pst->verifyPropMode_cst.value_pace)[idx_cuo];

    /* Copy verificationStatus to local variable so that rxPduCtx_pst can be const */
    idx_cuo = rxPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
    verificationStatus_st.freshnessValueID = (*rxPduCtx_pst
                                                 ->pduConfig_pst
                                                 ->freshnessValueId_cst.value_pacu16)[idx_cuo];
    verificationStatus_st.verificationStatus = rxPduCtx_pst->verificationStatus_u8;
    idx_cuo = rxPduCtx_pst->pduConfig_pst->dataId_cst.idx_cuo;
    verificationStatus_st.secOCDataId = (*rxPduCtx_pst->pduConfig_pst->dataId_cst.value_pacu16)[idx_cuo];

    if (SECOC_BOTH_E == VerificationStatusPropagationMode)
    {
        /* propagate the verification status */
        /* MR12 RULE 2.2 VIOLATION: called function is generated by RTE generator */
        (void)Rte_Call_RP_SecOC_VerificationStatusService_verificationStatus(&verificationStatus_st);
    }
    else if (SECOC_FAILURE_ONLY_E == VerificationStatusPropagationMode)
    {
        if(     (SECOC_VERIFICATIONFAILURE == verificationStatus_st.verificationStatus)
             || (SECOC_FRESHNESSFAILURE == verificationStatus_st.verificationStatus)
             || (SECOC_AUTHENTICATIONBUILDFAILURE == verificationStatus_st.verificationStatus)
             || (SECOC_VERIFICATIONFAILURE_OVERWRITTEN == verificationStatus_st.verificationStatus)
             || (SECOC_NO_VERIFICATION == verificationStatus_st.verificationStatus) )
        {
            /* propagate the verification status */
            /* MR12 RULE 2.2 VIOLATION: called function is generated by RTE generator */
            (void)Rte_Call_RP_SecOC_VerificationStatusService_verificationStatus(&verificationStatus_st);
        }
    }
    else
    {
        /* MR12 RULE 15.7 VILOLATION: Nothing to do, empty else clause required by MISRA */
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_RxCalculateAuthenticPduLength
 *
 * \brief  This function calculates the length of the payload by subtraction of the length of authenticator and
 *         freshness from the length of the secured pdu. This is required to handle pdus with payload length
 *         modulo 8 > 0.
 *
 * \param[in out]    SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst pointer to private context buffer of the pdu
 * \param[in]        uint32 securedLength_u32                        length of the secured pdu
 ***********************************************************************************************************************
 */
Std_ReturnType SecOC_Prv_RxCalculateAuthenticPduLength(SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst,
                                                       uint32 securedLength_u32)
{
    PduIdType idx_cuo;
    uint8 freshValTruncLen_u8;
    uint16 authInfoTruncLen_u16;
    uint32 cryptographicBitLength_u32;

    Std_ReturnType result_en = E_OK;
    uint32 authenticDataBitLength_u32 = 0u;

    idx_cuo = rxPduCtx_pst->pduConfig_pst->freshValTruncLen_cst.idx_cuo;
    freshValTruncLen_u8 = (*rxPduCtx_pst->pduConfig_pst->freshValTruncLen_cst.value_pacu8)[idx_cuo];
    idx_cuo = rxPduCtx_pst->pduConfig_pst->authInfoTruncLen_cst.idx_cuo;
    authInfoTruncLen_u16 = (*rxPduCtx_pst->pduConfig_pst->authInfoTruncLen_cst.value_pacu16)[idx_cuo];

    cryptographicBitLength_u32 = freshValTruncLen_u8 + authInfoTruncLen_u16;

    /* Calculate the length of the authentic PDU in bits by subtracting the length of the authenticator
     * and the length of the truncated freshness value from the configured length of the secured
     * PDU to handle PDUs with payload length modulo 8 > 0 (byte border violation)
    * */
    if (cryptographicBitLength_u32 <= (8u * securedLength_u32))
    {
        authenticDataBitLength_u32 = (8u * securedLength_u32) - cryptographicBitLength_u32;

        /* Limit the length of the authentic PDU to the actual amount of data available */
        if (authenticDataBitLength_u32 > (8u * rxPduCtx_pst->pduConfig_pst->authenticPduLength_uo))
        {
            authenticDataBitLength_u32 = 8u * rxPduCtx_pst->pduConfig_pst->authenticPduLength_uo;
        }
        rxPduCtx_pst->actualAuthenticPduLengthInBits_uo = (PduLengthType)authenticDataBitLength_u32;
    }
    else
    {
        /* The length of secured pdu is smaller than configured length of authenticator and freshness. Return E_NOT_OK */
        result_en = E_NOT_OK;
    }


    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_RxCheckAndSetAuthPduLengthFromSecuredHeader
 *
 * \brief  This function checks the value from Secured Header if it is a Dynamic length PDU and saves the length of
 *         Authentic PDU (extracted from Secured Header) in actualAuthenticPduLengthInBits_uo.
 *
 *
 *
 * \param[in out]    const SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst pointer to private context buffer of the pdu
 * \param[in]        const uint8 *securedPduData_pcu8                      pointer to secured pdu data used to extract value from header
 *
 * \return  Result of the function call:
 *                      - E_OK       - length of Authentic PDU from Secured PDU Header is smaller or equal with
 *                                     configured value for Authentic PDU
 *                      - E_NOT_OK   - length of Authentic PDU from Secured PDU Header is greater than
 *                                     configured value for Authentic PDU
 *
 * \return  Std_ReturnType
 ***********************************************************************************************************************
 */
 Std_ReturnType SecOC_Prv_RxCheckAndSetAuthPduLengthFromSecuredHeader(SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst,
                                                                      const uint8* securedPduData_pcu8)
 {
    Std_ReturnType result_en = E_OK; /* We assume that the value from header is correct. */
    uint8 index_u8 = 0u;
    uint32 actualAuthenticPduLengthInBits_u32 = 0u; /* The length of Authentic PDU extracted from Secured header in Bits. */

    /* Extract the value from header */
    for(index_u8 = 0u; index_u8 < rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8; index_u8++)
    {
        actualAuthenticPduLengthInBits_u32 |= securedPduData_pcu8[index_u8] << ((rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 - index_u8 - 1u) * 8u);
    }

    /* Check the length of Authentic Pdu from Secured Header if the representation is in Bytes*/
    if(FALSE == rxPduCtx_pst->pduConfig_pst->packedBits_stb.bitHeader_b)
    {
        if(actualAuthenticPduLengthInBits_u32 > (uint32)rxPduCtx_pst->pduConfig_pst->authenticPduLength_uo)
        {
            /* The length is greater than configured value. Return E_NOT_OK */
            result_en = E_NOT_OK;
        }
        else
        {
            /* TRACE[SWS_SecOC_00259]: In case of Header representation is in Bytes, convert to bits and save the length. */
            rxPduCtx_pst->actualAuthenticPduLengthInBits_uo = (PduLengthType)(actualAuthenticPduLengthInBits_u32 * 8u);
        }
    }
    /* Check the length of Authentic Pdu from Secured Header if the representation is in Bits. */
    else
    {
        if (((PduLengthType)(((actualAuthenticPduLengthInBits_u32 + 7u) >> 3u))) > rxPduCtx_pst->pduConfig_pst->authenticPduLength_uo)
        {
            /* The length is greater than configured value. Return E_NOT_OK */
            result_en = E_NOT_OK;
        }
        else
        {
            /* TRACE[SWS_SecOC_00259]: Save the length of Authentic Pdu. */
            rxPduCtx_pst->actualAuthenticPduLengthInBits_uo = (PduLengthType) actualAuthenticPduLengthInBits_u32;
        }
    }

    return result_en;
 }

/**
 ***********************************************************************************************************************
 * SecOC_Prv_RxGetAuthenticPduOffset
 *
 * \brief  This function calculates the offset of the Authentic I-PDU in bits inside a received Secured I-PDU
 *
 * \param[in]    SecOC_Prv_RxPduConfig_tst *rxPduCfg_pst   pointer to private config buffer of the pdu
 *
 * \return  Offset of Authentic I-PDU in bits
 *
 * \return  uint8
 ***********************************************************************************************************************
 */
uint8 SecOC_Prv_RxGetAuthenticPduOffset(const SecOC_Prv_RxPduConfig_tst *rxPduCfg_pst)
{
    uint8 authenticPduOffsetInBits_u8 = 0u;


    if (0u != rxPduCfg_pst->securedHeaderLength_u8)
    {
        authenticPduOffsetInBits_u8 = rxPduCfg_pst->securedHeaderLength_u8 * 8u;
    }
    else
    {
        /* nothing to do */
    }

    return authenticPduOffsetInBits_u8;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_RxGetPduType
 *
 * \brief  This function checks boundary to get the pdu type
 *
 * \param[in]   PduIdType id    pdu id of secured PDU / cryptographic PDU / secured PDU
 *
 * \return  Result of the function call:
 *                      - SECOC_SECURED_PDU
 *                      - SECOC_COLLECTION_AUTHENTIC_PDU
 *                      - SECOC_COLLECTION_CRYPTOGRAPHIC_PDU
 *
 * \return  uint8
 ***********************************************************************************************************************
 */
uint8 SecOC_Prv_RxGetPduType(PduIdType id)
{
    (void)id;

    return SECOC_SECURED_PDU;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_RxCheckMessageLinks
 *
 * \brief  This function checks message links
 *
 * \param[in]    SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst   pointer to private context buffer of the rx pdu
 *
 * \return  Result of the function call:
 *                      - TRUE      - message links match or messageLinkLength_u16 == 0
 *                      - FALSE     - message links do not match
 *
 * \return  boolean
 ***********************************************************************************************************************
 */
boolean SecOC_Prv_RxCheckMessageLinks(const SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst)
{
    boolean messageLinkMatch_b = TRUE;

    (void) rxPduCtx_pst;

    return messageLinkMatch_b;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_handlePenRxCbk
 *
 * \brief  This private function handles a pending Rx callback.
 *
 * \return  void
 ***********************************************************************************************************************
 */
void SecOC_Prv_handlePenRxCbk(SecOC_Prv_RxAuthenticPduContext_tst *rxAuthPduCtx_pst)
{
    if(SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E == rxAuthPduCtx_pst->status_u8)
    {
        rxAuthPduCtx_pst->status_u8 = SECOC_RX_STATE_MAC_VERIFY_FINISHED_E;

        if (FALSE != SecOC_Prv_HandleVerificationResult(rxAuthPduCtx_pst, SecOC_Prv_RxCbkPending_au8[rxAuthPduCtx_pst->pduIndex_u32]))
        {
            /* TRACE[SWS_SecOC_00166]|Det disabled */
        }
    }
    else if(SECOC_RX_STATE_WAIT_ABORT_VERIFY_E == rxAuthPduCtx_pst->status_u8)
    {
        SecOC_Prv_clearRxAuthenticPduContext(rxAuthPduCtx_pst);
    }
    else
    {
        /* do nothing*/
    }
    SecOC_Prv_RxCbkPending_au8[rxAuthPduCtx_pst->pduIndex_u32] = SECOC_PRV_NO_PENDING_CALLBACK;
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_CopyPduFromSecuredCtxToAuthenticCtx
 *
 * \brief  This function copies the Secured Pdu from Secured buffers to Authentic buffers and it sets the status of
 *         authentic Context to VERIFY. The secured pdu consists of the header (if is dynamic Pdu),
 *         payload, the truncated freshness value and the truncated authenticator (CMAC or signature).
 *         It is used by SecOC_MainFunctionRx and SecOC_RxIndication.
 *
 * \param[in]   SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_cpcst      pointer to private secured context buffer of
 *                                                                            the rx pdu
 * \param[in]   SecOC_Prv_RxAuthenticPduContext_tst *rxAuthenticPduCtx_cpst   pointer to private authentic context buffer
 *                                                                            of the rx pdu
 *
 * \return  void
 ***********************************************************************************************************************
*/
void SecOC_Prv_CopyPduFromSecuredCtxToAuthenticCtx(const SecOC_Prv_RxSecuredPduContext_tst * const rxSecuredPduCtx_cpcst,
                                                   SecOC_Prv_RxAuthenticPduContext_tst * const rxAuthenticPduCtx_cpst)
{
    PduIdType idx_cuo;
    uint8 freshValTruncLen_u8;
    uint16 authInfoTruncLen_u16;
    uint8_least idx_qu8;

    uint32 authenticatorOffsetInBits_u32 = 0u;
    uint8 authenticPduOffsetInBits_u8 = 0u;


    idx_cuo = rxSecuredPduCtx_cpcst->pduConfig_pst->freshValTruncLen_cst.idx_cuo;
    freshValTruncLen_u8 = (*rxSecuredPduCtx_cpcst->pduConfig_pst->freshValTruncLen_cst.value_pacu8)[idx_cuo];
    idx_cuo = rxSecuredPduCtx_cpcst->pduConfig_pst->authInfoTruncLen_cst.idx_cuo;
    authInfoTruncLen_u16 = (*rxSecuredPduCtx_cpcst->pduConfig_pst->authInfoTruncLen_cst.value_pacu16)[idx_cuo];

    rxAuthenticPduCtx_cpst->status_u8 = SECOC_RX_STATE_VERIFY_E;
    rxAuthenticPduCtx_cpst->actualAuthenticPduLengthInBits_uo = rxSecuredPduCtx_cpcst->actualAuthenticPduLengthInBits_uo;
    /* TRACE[SWS_SecOC_00235]: reset retry counters */
    rxAuthenticPduCtx_cpst->verifyAttempts_u16 = 0u;
    rxAuthenticPduCtx_cpst->authAttempts_u16 = 0u;

    /* copy all data of input buffers into internal buffers */
    SecOC_Prv_createDataforAuthenticationRx(rxAuthenticPduCtx_cpst);

    /* copy payload of authentic PDU to output buffer */
    SecOC_Prv_CopyBits(
        rxSecuredPduCtx_cpcst->pduConfig_pst->authenticPduBufferOut_pu8, /* out: destination */
        0u,                                                            /*  in: destination bit position */
        rxSecuredPduCtx_cpcst->pduConfig_pst->pduBufferIn_pu8,           /*  in: source */
        SecOC_Prv_RxGetAuthenticPduOffset(rxAuthenticPduCtx_cpst->pduConfig_pst), /*  in: source bit position */
        rxSecuredPduCtx_cpcst->actualAuthenticPduLengthInBits_uo         /*  in: number of bits */
    );

    if(FALSE == rxAuthenticPduCtx_cpst->pduConfig_pst->packedBits_stb.pduColl_b)
    {
        /* Get the offset of authentic in case of dynamic pdu, otherwise (in case of static pdu) returns 0. */
        authenticPduOffsetInBits_u8 = SecOC_Prv_RxGetAuthenticPduOffset(rxAuthenticPduCtx_cpst->pduConfig_pst);

        authenticatorOffsetInBits_u32 = authenticPduOffsetInBits_u8
                       + rxAuthenticPduCtx_cpst->actualAuthenticPduLengthInBits_uo
                       + freshValTruncLen_u8;

        /* TRACE[SWS_SecOC_00042]: unpack the authenticator from the received secured PDU */
        SecOC_Prv_CopyBits(
            rxAuthenticPduCtx_cpst->pduConfig_pst->authenticator_pu8,     /* out: destination */
            0u,                                                           /*  in: destination bit position */
            rxAuthenticPduCtx_cpst->pduConfig_pst->pduBufferIn_pu8,       /*  in: source */
            authenticatorOffsetInBits_u32,                                /*  in: source bit position */
            authInfoTruncLen_u16);                                        /*  in: number of bits */
    }
    else
    {
        /* TRACE[SWS_SecOC_00042]: unpack the authenticator from the received secured PDU */
        SecOC_Prv_CopyBits(
            rxAuthenticPduCtx_cpst->pduConfig_pst->authenticator_pu8,             /* out: destination */
            0u,                                                                   /*  in: destination bit position */
            rxAuthenticPduCtx_cpst->pduConfig_pst->cryptographicPduBufferIn_pu8,  /*  in: source */
            freshValTruncLen_u8,                                                  /*  in: source bit position */
            authInfoTruncLen_u16);                                                /*  in: number of bits */
    }

    /* TRACE[SWS_SecOC_00212] */
    for(idx_qu8 = 0; idx_qu8 < rxSecuredPduCtx_cpcst->pduConfig_pst->metaDataLen_u8; idx_qu8++)
    {
        rxAuthenticPduCtx_cpst->metaData_pu8[idx_qu8] = rxSecuredPduCtx_cpcst->metaData_pu8[idx_qu8];
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_fetchOverrideStatus
 *
 * \brief  The function returns the override status of the given ValueID.
 *         It loops over the whole StatusOverride structure and returns the state of the matching entry
 *
 * \param[in]    valueID_u16
 *
 * \return       override state of requested ValueID
 ***********************************************************************************************************************
*/
SecOC_OverrideStatusType SecOC_Prv_fetchOverrideStatus(uint16  valueID_u16)
{
    uint32 index_u32;


    SecOC_OverrideStatusType status_u8 = SECOC_OVERRIDE_CANCEL;
    for(index_u32 = 0; index_u32 < SECOC_MAX_VERIFY_STATUS_OVERRIDE; index_u32++)
    {
        if(valueID_u16 == SecOC_Prv_Rx_Lookup_ValueId_pcu16[index_u32])
        {
            status_u8 = SecOC_Prv_VerifyStatusOverride_ast[index_u32].overrideStatus_u8;
            break;
        }
    }
    return (status_u8);
}




#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"
