/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Private source file providing helper functionality for PduR inteerface.
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
 * Variables
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"
/* Translate secOC secured PDU ID / PDU collection ID (cryptographic or authentic PDU ID) to secOC authentic PDU ID */
static const PduIdType SecOC_Prv_Tx_Lookup_PduId_auo[SECOC_NUMBER_TX_PDU_ID] =
{
    0U
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
#include "SecOC_MemMap.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"

/**
 ***********************************************************************************************************************
 * SecOC_Prv_getAuthenticPduId
 *
 * \brief  returns authentic PduId for given secured PduId from lookup table
 *
 * \param[in] PduIdType secPduId_uo   Id of secured PDU
 *
 * \return  Id of authentic PDU
 ***********************************************************************************************************************
*/
PduIdType SecOC_Prv_getAuthenticPduId(PduIdType secPduId_uo)
{
    return SecOC_Prv_Tx_Lookup_PduId_auo[secPduId_uo];
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_TpCopyTxData
 *
 * \brief  The function copies the authentic pdu identified by the context buffer txPduCtx_pst from the upper PduR.
 *
 *         The function is called during the start of a TpTansmit or by the MainFunctionTx as a copy retry.
 *         It calls the PdurIF PduR_SecOCTpCopyTxData to copy the authentic pdu into the PduBufferIn.
 *         It sets depending on the retVal the state machine variable.
 *
 * \param[inout] SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst   context buffer of the authentic PDU
 *
 * \param[in]    const PduInfoType*  pduAuthInfo_pst   holds the pointer to the payload of the authentic pdu
 *
 * \return  Result of the function call:
 *                              - E_OK    : copy successful or retry next MainFunctionTx
 *                              - E_NOT_OK: copy error occurred
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_Prv_TpCopyTxData(SecOC_Prv_TxAuthenticPduContext_tst* txAuthenticPduCtx_pst)
{
    PduInfoType pduTpTarget_st;

    PduLengthType availableData_uo = 0u;
    RetryInfoType retry_st = { TP_DATACONF, 0u};
    BufReq_ReturnType retval_en = BUFREQ_E_NOT_OK;
    Std_ReturnType result_en = E_OK;

    /* TRACE[SWS_SecOC_00254]:  */
    pduTpTarget_st.SduDataPtr  = txAuthenticPduCtx_pst->pduConfig_pst->authenticPduBufferIn_pu8;
    pduTpTarget_st.MetaDataPtr = txAuthenticPduCtx_pst->MetaDataPtr_pu8;  /* return MetaData ptr to itself */
    pduTpTarget_st.SduLength   = (PduLengthType)((txAuthenticPduCtx_pst->payloadLength_uo + 7u) >> 3u);

    retry_st.TpDataState = TP_CONFPENDING;     /* hold data on upper layer for fast meta data addresse copy */
    retry_st.TxTpDataCnt = 0;                  /* fetch all tx data from upper layer */

    retval_en = PduR_SecOCTpCopyTxData(
        txAuthenticPduCtx_pst->pduConfig_pst->pduRId_uo,
        &pduTpTarget_st,
        &retry_st,
        &availableData_uo);                    /* remaining number of bytes in upper layer == 0 expected */
    if(BUFREQ_OK == retval_en)
    {
        txAuthenticPduCtx_pst->status_u8 = SECOC_TX_STATE_SENDING_E;
    }
    else if(BUFREQ_E_BUSY == retval_en)
    {
        /*TRACE[SWS_SecOC_00260]: upper layer busy, retry copy in next MainFunctionTx */
        txAuthenticPduCtx_pst->status_u8 = SECOC_TX_STATE_FETCH_TP_DATA_E;
    }
    else
    {
        /* TRACE[SWS_SecOC_00266]: unexpected BUFREQ_E_NOT_OK or BUFREQ_E_OVFL */
        /* Inform upper layer*/
        PduR_SecOCTpTxConfirmation( txAuthenticPduCtx_pst->pduConfig_pst->pduRId_uo, E_NOT_OK);
        /* Internal cleaning of authenticPduBufferIn_pu8 not needed, just release state */
        txAuthenticPduCtx_pst->status_u8 = SECOC_TX_STATE_AUTHENTIC_IDLE_E;
        result_en = E_NOT_OK;
    }

    return result_en;
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_CancelTransmit
 *
 * \brief  Private function called by public API requests cancellation of an ongoing transmission of a PDU
 *         in a lower layer communication module.
 *
 * \param[in]   PduIdType            id     identifier of the Pdu
 *
 * \param[in]   uint8       serviceId_u8    If/Tp API switch
 *
 * \return      Std_ReturnType     - E_OK    : request successfull
 *                                 - E_NOT_OK: an error occurred, request failed
 ***********************************************************************************************************************
 */
Std_ReturnType SecOC_Prv_CancelTransmit(PduIdType id, uint8 serviceId_u8 )
{
    Std_ReturnType result_en = E_NOT_OK;
    SecOC_Prv_TxSecuredPduContext_tst *txSecuredPduCtx_pst;
    SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst;
    SecOC_Prv_TxSecuredPduState_tu8 ctxBufferState_u8;
    SECOC_PARAM_UNUSED(serviceId_u8);


    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else if (id > SECOC_MAX_AUTHENTIC_PDU_ID)
    {
        /* TRACE[]|Det disabled */
    }
    else
    {
        txSecuredPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(id);
        if (NULL_PTR != txSecuredPduCtx_pst)
        {
            ctxBufferState_u8 = SecOC_Prv_TxSecuredContextBufferGetState(id);

            switch(ctxBufferState_u8)
            {
                case SECOC_TX_STATE_WAIT_FOR_CSM_CALLBACK_E:
                {
                    /* set internal state for the Pdu to canceled to handle it in main function */
                    txSecuredPduCtx_pst->status_u8 = SECOC_TX_STATE_CANCEL_PENDING_E;
                    result_en = E_OK;
                    break;
                }

                case SECOC_TX_STATE_GENERATE_E:
                {
                    SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
                    result_en = E_OK;
                    break;
                }

                case SECOC_TX_STATE_SENT_E:
                {
                    SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
                    result_en = E_OK;
                    break;
                }
                case SECOC_TX_STATE_SECURED_IDLE_E:
                {
                    /* nothing to do but valid state */
                    result_en = E_OK;
                    break;
                }

                /* MR12 RULE 16.4 VIOLATION: no action is necessary */
                default:
                {
                    /* Switch statement covers all relevant enum values, empty default clause required by coding rules. */
                    SecOC_Prv_clearTxSecuredPduContext(txSecuredPduCtx_pst);
                    break;
                }
            }
            SecOC_Prv_TxSecuredContextBufferRelease(&txSecuredPduCtx_pst);
        }

        txAuthenticPduCtx_pst = SecOC_Prv_TxAuthenticContextBufferAllocate(id);
        if (NULL_PTR != txAuthenticPduCtx_pst)
        {
            txAuthenticPduCtx_pst->status_u8 = SECOC_TX_STATE_AUTHENTIC_IDLE_E;
            SecOC_Prv_resetSameBufferTxRefInUse((uint32)id);
            result_en = E_OK;
            SecOC_Prv_TxAuthenticContextBufferRelease(&txAuthenticPduCtx_pst);
        }
        else
        {
            result_en = E_NOT_OK;
        }
    }

    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_Transmit
 *
 * \brief  The function is called by the public APIs to trigger the transmission of a authentic Pdu.
 *         After checking the state of SecOC and the input parameters the function SecOC_Prv_HandleAuthenticPdu
 *         to handle the authentic PDU is called. This function returns a secured Pdu which the payload of the
 *         authentic Pdu plus the authenticator plus frehsness information. This Pdu is forwarded to the PduR for
 *         further routing.
 *         If SecOC is not initialized E_NOT_OK is returned and the error is reported to Det.
 *
 * \param[in]    PduIdType           TxPduId      Identifier of the PDU to be transmitted
 *
 * \param[in]    const PduInfoType*  PduInfoPtr   Length of and pointer to the PDU data and pointer to MetaData.
 *
 * \param[in]    uint8               serviceId_u8 ServiceId of the calling public API used in DetReportError call.
 *
 * \return       Result of the function call:
 *                              - E_NOT_OK: an error occurred, request failed
 *                              - E_OK    : request successful
 ***********************************************************************************************************************
*/
/* HIS METRIC LEVEL VIOLATION in SecOC_Prv_Transmit: levels required because of checks according to Autosar */
Std_ReturnType SecOC_Prv_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr, uint8 serviceId_u8)
{
    Std_ReturnType result_en = E_NOT_OK;  /* TRACE[SWS_SecOC_00108] */
    SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst = NULL_PTR;
    SECOC_PARAM_UNUSED(serviceId_u8);


    /* check state of SecOC */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else if (TxPduId > SECOC_MAX_AUTHENTIC_PDU_ID)
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    /* check input parameters */
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr) || (PduInfoPtr->SduLength == 0u))
    {
        /* TRACE[]|Det disabled */
    }
    else
    {
        txAuthenticPduCtx_pst = SecOC_Prv_TxAuthenticContextBufferAllocate(TxPduId);
        if (NULL_PTR != txAuthenticPduCtx_pst)
        {
            /* TRACE[SWS_SecOC_00313]: check if secured area is valid */
            if (    (txAuthenticPduCtx_pst->pduConfig_pst->securedTxPduLength_u32 > 0u)
                 && ((  txAuthenticPduCtx_pst->pduConfig_pst->securedTxPduOffset_u32
                       + txAuthenticPduCtx_pst->pduConfig_pst->securedTxPduLength_u32) > PduInfoPtr->SduLength)
               )
            {
                /* TRACE[SWS_SecOC_Rb_00314]: Call DET to notify that the received authentic PDU
                   is discarded because the PDU length is smaller than secured area length. */
                /* TRACE[SWS_SecOC_Rb_00314]|Det disabled */
            }
            else if (FALSE == SecOC_Prv_lockSameBuffer(
                                                    txAuthenticPduCtx_pst->pduConfig_pst->isSameBufferRefInUse_pb,
                                                    txAuthenticPduCtx_pst->pduConfig_pst->sameBufferRefInUsePduId_puo,
                                                    TxPduId))
            {
                /* TRACE[]|Det disabled */
            }
            else
            {
                result_en = SecOC_Prv_HandleAuthenticPdu(txAuthenticPduCtx_pst, PduInfoPtr);
                if (E_OK != result_en)
                {
                    /* PDU is discarded because it is invalid => release same buffer */
                    SecOC_Prv_resetSameBufferTxRefInUse((uint32)TxPduId);
                }
            }
            SecOC_Prv_TxAuthenticContextBufferRelease(&txAuthenticPduCtx_pst);
        }
    }


    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_TxConfirmation
 *
 * \brief Private function is called by public APIs
 *
 * \param[in] PduIdType             id    Identification of the transmitted I-PDU.
 *
 * \param[in] Std_ReturnType    result    Result of the transmission of the I-PDU.
 *
 * \param[in] uint8       serviceId_u8    If/Tp API switch
 *
 * \return void
 ***********************************************************************************************************************
 */
void SecOC_Prv_TxConfirmation(PduIdType TxPduId, Std_ReturnType result, uint8 serviceId_u8 )
{
    /* TRACE[SWS_SecOC_00152]: Implementation of SecOC_TpTxConfirmation */
    /* (SRS_BSW_00323, SRS_BSW_00359, SRS_BSW_00449, SRS_SecOC_00012) */
    SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst = NULL_PTR;
    PduIdType secOCAuthenticPduId_uo;
    uint8 pduType_u8 = 0;


    /* Verify if current SecOC state is valid. */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else if ( TxPduId > SECOC_MAX_TX_PDU_ID )
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        /* Translate secOC secured / collection authentic / cryptographic PDU TxPduId to secOC authentic PDU TxPduId */
        secOCAuthenticPduId_uo = SecOC_Prv_Tx_Lookup_PduId_auo[TxPduId];
        txPduCtx_pst = &SecOC_Prv_TxSecuredPduContext_ast[secOCAuthenticPduId_uo];

        if (SECOC_SERVICE_ID_TX_CONFIRMATION == serviceId_u8)
        {
            /* TRACE[SWS_SecOC_00074]: Confirm transmission of authentic I-PDU to upper layer module */
            PduR_SecOCIfTxConfirmation(txPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo, result);
        }
        /* TRACE[SWS_SecOC_00077]: silent reject during Transmission protocol */
        if ((SECOC_SERVICE_ID_TP_TX_CONFIRMATION == serviceId_u8) && (E_OK == result))
        {
            /* TRACE[SWS_SecOC_00074]: Confirm transmission of authentic I-PDU to upper layer module */
            if(FALSE != txPduCtx_pst->pduConfig_pst->packedBits_stb.pduTpType_b)
            {
                PduR_SecOCTpTxConfirmation(txPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo, result);
            }
            else
            {
                PduR_SecOCIfTxConfirmation(txPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo, result);
            }
        }

        if (SECOC_TX_STATE_SENT_E == SecOC_Prv_TxSecuredContextBufferGetState(secOCAuthenticPduId_uo))
        {
            txPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(secOCAuthenticPduId_uo);
            if (NULL_PTR != txPduCtx_pst)
            {
                pduType_u8 = SecOC_Prv_TxGetPduType(TxPduId);
                if (SECOC_COLLECTION_CRYPTOGRAPHIC_PDU == pduType_u8)
                {
                    txPduCtx_pst->received_CryptographicPdu_b = TRUE;
                }
                if (SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8)
                {
                    txPduCtx_pst->received_AuthenticPdu_b = TRUE;
                }
                if ((SECOC_TX_STATE_SENT_E == SecOC_Prv_TxSecuredContextBufferGetState(secOCAuthenticPduId_uo)) &&
                    ((SECOC_SECURED_PDU == pduType_u8) ||
                    ((FALSE != txPduCtx_pst->received_AuthenticPdu_b) && (FALSE != txPduCtx_pst->received_CryptographicPdu_b))))
                {
                    /* TRACE[SWS_SecOC_00075] Clear buffer of secured I-PDU  */
                    /* The processing of the authentic I-PDU is now finished. */
                    /* So clear all internal buffers of the authentic Pdu */
                    SecOC_Prv_clearTxSecuredPduContext(txPduCtx_pst);
                }
                SecOC_Prv_TxSecuredContextBufferRelease(&txPduCtx_pst);
            }
        }
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_HandleAuthenticPdu
 *
 * \brief  The function handles the authentic pdu identified by the context buffer txPduCtx_pst.
 *
 *         In asynchronous mode the function copies the payload of the authentic pdu to the internal data buffer
 *         for the authentication and sets the state of the pdu to SECOC_TX_STATE_SENDING_E. The further processing
 *         is done in the cyclic function SecOC_MainFunctionTx.
 *         In synchronous mode the authenticator (CMAC or signature) is generated with the key given by the private key
 *         interface of SecOC. The key identifier is hold in the pdu configuration structure. The generated authenticator
 *         is truncated to the configured length and combined with the payload of the authentic pdu to the secured pdu.
 *         The secured pdu is hold in an internal buffer.
 *
 * \param[inout] SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst   context buffer of the authentic PDU
 *
 * \param[in]    const PduInfoType*  pduAuthInfo_pst   holds the pointer to the payload of the authentic pdu
 *
 * \return  Result of the function call:
 *                              - E_OK    : request successful
 *                              - E_NOT_OK: an error occurred, authentication failed
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_Prv_HandleAuthenticPdu(SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst,
                                            const PduInfoType* pduAuthInfo_pst)
{
    uint32 authPduLength_u32 = 0u;
    Std_ReturnType result_en = E_NOT_OK;


    /* Only start processing if the length of received pdu is within the allowed range. */
    if (    (pduAuthInfo_pst->SduLength <= txAuthenticPduCtx_pst->pduConfig_pst->authenticPduLength_uo)
         && (    (0u == txAuthenticPduCtx_pst->pduConfig_pst->messageLinkLength_u16)
              || ((   txAuthenticPduCtx_pst->pduConfig_pst->messageLinkLength_u16
                    + txAuthenticPduCtx_pst->pduConfig_pst->messageLinkPos_u16) <= (pduAuthInfo_pst->SduLength * 8u))))
    {
        /* Check if the received length fit into secured pdu (not possible for pdu collection) */
        if (FALSE == txAuthenticPduCtx_pst->pduConfig_pst->packedBits_stb.pduColl_b)
        {
            /* Calculate the length of the authentic PDU in bits by subtracting the length of the secured header,
             * the authenticator and the length of the truncated freshness value from the configured length of the
             * secured PDU to get the maximum of the payload which fit into secured PDU.
             * Note: For PDUs with payload length modulo 8 > 0 (byte border violation) the calculated length
             *       is less than the received length and the calculated length is used for further handling.
             * */
            authPduLength_u32 = (8u * txAuthenticPduCtx_pst->pduConfig_pst->pduLength_uo)
                                 - txAuthenticPduCtx_pst->pduConfig_pst->securedHeaderLength_u8
                                 - txAuthenticPduCtx_pst->pduConfig_pst->authInfoTxLength_u16
                                 - txAuthenticPduCtx_pst->pduConfig_pst->freshnessValueTxLength_u8;

            /* Limit the length of the authentic PDU to the actual amount of data available */
            if (authPduLength_u32 > (8u * pduAuthInfo_pst->SduLength))
            {
                authPduLength_u32 = (8u * pduAuthInfo_pst->SduLength);
            }
        }
        else
        {
            authPduLength_u32 = (8u * pduAuthInfo_pst->SduLength);
        }

        /* Store the calculated length of the PDU. */
        txAuthenticPduCtx_pst->payloadLength_uo = (PduLengthType)(authPduLength_u32);
        txAuthenticPduCtx_pst->MetaDataPtr_pu8 = pduAuthInfo_pst->MetaDataPtr;

        if(FALSE == txAuthenticPduCtx_pst->pduConfig_pst->packedBits_stb.pduTpType_b)
        {
            /* copy payload of the received PDU to the internal buffer */
            SecOC_Prv_CopyBits(
                txAuthenticPduCtx_pst->pduConfig_pst->authenticPduBufferIn_pu8, /* out: destination */
                0u,                                              /*  in: destination bit position */
                pduAuthInfo_pst->SduDataPtr,                     /*  in: source */
                0u,                                              /*  in: source bit position */
                txAuthenticPduCtx_pst->payloadLength_uo          /*  in: number of bits to copy */
            );
            /* set status to SECOC_TX_STATE_SENDING_E to indicate that the authentic I-PDU is successfully received */
            /* and authentication can start. */
            txAuthenticPduCtx_pst->status_u8 = SECOC_TX_STATE_SENDING_E;
            result_en = E_OK;
        }
        else
        {
            /* TRACE[SWS_SecOC_00254]:  */
            result_en = SecOC_Prv_TpCopyTxData(txAuthenticPduCtx_pst);
        }
    }
    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_TpRxIndication
 *
 * \brief Called after an I-PDU has been received via the TP API, the result indicates whether the transmission was
 *        successful or not.
 *
 * \param[in] PduIdType      id     Identification of the I-PDU.
 *
 * \param[in] Std_ReturnType result Result of the reception.
 *
 ***********************************************************************************************************************
 */
/* HIS METRIC LEVEL VIOLATION in SecOC_Prv_TpRxIndication: levels required because of checks according to Autosar */
void SecOC_Prv_TpRxIndication( PduIdType id, Std_ReturnType result )
{
    /* TRACE[SWS_SecOC_00125]: Implementation of SecOC_TpRxIndication */
    /* (SRS_BSW_00323, SRS_BSW_00359, SRS_BSW_00449, SRS_SecOC_00012) */
    PduIdType idx_cuo;
    SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst = NULL_PTR;
    uint8 pduType_u8 = 0;
    uint16 valueID_u16;
    SecOC_OverrideStatusType overrideStatus_u8;

    /* check state of SecOC */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else if (id > SECOC_MAX_RX_PDU_ID)
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        pduType_u8 = SecOC_Prv_RxGetPduType(id);
        /* if id is collection authentic pduId then calculate the related cryptographic pduId */
        if (SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8)
        {
            id = id - SECOC_NUMBER_RX_COLLECTION_PDU;
        }

        /* TRACE[SWS_SecOC_00084] */
        if ((SECOC_RX_STATE_RECEIVING_E == SecOC_Prv_RxPduContextBufferGetState(id, pduType_u8)))
        {
            /* Get a pointer to the context buffer */
            rxSecuredPduCtx_pst = SecOC_Prv_RxSecuredContextBufferAllocate(id);

            if(NULL_PTR != rxSecuredPduCtx_pst)
            {
                /* If the reception result was E_OK and the current buffer state is valid, we indicate successfull
                * reception to the scheduled main task by setting the state to SECOC_RX_STATE_RECEIVED_E, else the
                * state is set to idle and the secured buffer is cleared.
                */
                if (E_OK == result)
                {
                    /* TRACE[SWS_SecOC_00203], TRACE[SWS_SecOC_00210], TRACE[SWS_SecOC_00211]: */
                    /* set status to SECOC_RX_STATE_RECEIVED_E to indicate that the collection I-PDU (cryptographic pdu
                     * and authentic pdu) is successfully received and Message Linker is matching. The verification can
                     * start
                     */
                    if(FALSE == rxSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.pduColl_b)
                    {
                        /* check if any data was received. */
                        /* Note: StartOfReception and CopyRxData check if the received data is not too big for current
                        buffer. */
                        if (rxSecuredPduCtx_pst->bufferPosition_uo > 0u)
                        {
                            rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVED_E;
                        }
                        else
                        {
                            /* empty secured pdu - no data was received - set status to IDLE */
                            rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
                            /* reset same buffer because it is already reserved in StartOfReception */
                            SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                        }
                    }
                    else /* Collection Pdu */
                    {
                        if (SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8)
                        {
                            /* In case of Collection Authentic Pdu, the Pdu length can be 0 only when it is a
                               static Collection Pdu and the payload length is 0. */
                            if (    (rxSecuredPduCtx_pst->bufferPosition_uo > 0u)
                                 || (0u == rxSecuredPduCtx_pst->actualAuthenticPduLengthInBits_uo))
                            {
                                /* Set the received flag on TRUE and set the state on RECEIVED because
                                the auth/crypto is successfully received. */
                                rxSecuredPduCtx_pst->received_AuthenticPdu_b = TRUE;
                                rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVED_E;

                                /* In case of both authentic and cryptographic were received but the current authentic
                                   pdu was overwritten by overflow strategy, a new message linker check needs to be
                                   performed. */
                                if ((FALSE == rxSecuredPduCtx_pst->received_CryptographicPdu_b) &&
                                    (SECOC_RX_STATE_RECEIVED_E == rxSecuredPduCtx_pst->cryptographicPduStatus_u8))
                                {
                                    /* Set the received cryptographic flag to trigger the message linker check. */
                                    rxSecuredPduCtx_pst->received_CryptographicPdu_b = TRUE;
                                }
                            }
                            else
                            {
                                /* empty collection authentic pdu - no data was received - set status to IDLE */
                                rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
                                /* reset same buffer because it is already reserved in StartOfReception */
                                SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                            }

                        }
                        else /* (SECOC_COLLECTION_CRYPTOGRAPHIC_PDU == pduType_u8) */
                        {
                            /* check if any data was received */
                            if (rxSecuredPduCtx_pst->cryptographicPduBufferPosition_uo > 0u)
                            {
                                rxSecuredPduCtx_pst->received_CryptographicPdu_b = TRUE;
                                rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_RECEIVED_E;

                                /* In case of both authentic and cryptographic were received but the current
                                   cryptographic pdu was overwritten by overflow strategy, a new message linker check
                                   needs to be performed. */
                                if ((FALSE == rxSecuredPduCtx_pst->received_AuthenticPdu_b) &&
                                    (SECOC_RX_STATE_RECEIVED_E == rxSecuredPduCtx_pst->status_u8))
                                {
                                    /* Set the received authentic flag to trigger the message linker check. */
                                    rxSecuredPduCtx_pst->received_AuthenticPdu_b = TRUE;
                                }
                            }
                            else
                            {
                                /* empty collection crypto pdu - no data was received - set status to IDLE  */
                                rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
                                /* reset same buffer because it is already reserved in StartOfReception */
                                SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                            }
                        }
                        idx_cuo = rxSecuredPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
                        valueID_u16   = (*rxSecuredPduCtx_pst->pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo];
                        overrideStatus_u8 = SecOC_Prv_fetchOverrideStatus(valueID_u16);
                        if(    (FALSE != rxSecuredPduCtx_pst->received_AuthenticPdu_b)
                            && (SECOC_OVERRIDE_TO_PASS == overrideStatus_u8))
                        {
                            /* PduCollection case:
                             * Check whether authentic Pdu was received and Bypass is ON then
                             * set status to SECOC_RX_STATE_RECEIVED_E to indicate that the secured I-PDU is
                             * successfully received and verification can start. The "cryptographicPduStatus_u8" is
                             * artificially set to RECEIVED in order to notify MainFunctionRx that the collection pair
                             * can be processed.
                             */
                            rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVED_E;
                            rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_RECEIVED_E;
                            /* Question to Reviewer: Can/Should we add 2 lines and release received_flags?
                                    rxSecuredPduCtx_pst->received_AuthenticPdu_b = FALSE;
                                    rxSecuredPduCtx_pst->received_CryptographicPdu_b = FALSE;*/
                        }
                        else if((FALSE != rxSecuredPduCtx_pst->received_AuthenticPdu_b)
                            && (FALSE != rxSecuredPduCtx_pst->received_CryptographicPdu_b))
                             {
                                if (FALSE != SecOC_Prv_RxCheckMessageLinks(rxSecuredPduCtx_pst))
                                {
                                    /* The status_u8 is set to RECEIVED in order to be processed by
                                      MainFunctionRx because the cryptographic Pdu is already in buffer. */
                                    rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVED_E;
                                    rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_RECEIVED_E;
                                    /* Enable receiving new collection pair. */
                                    rxSecuredPduCtx_pst->received_AuthenticPdu_b = FALSE;
                                    rxSecuredPduCtx_pst->received_CryptographicPdu_b = FALSE;
                                }
                                else
                                {
                                    /* Both pdus remain buffered and the verification will be reattempted when new data
                                     *  arrives. In this case, the status_u8 and cryptographicPduStatus_u8 are set to
                                     * IDLE in order to accept new pdus, but the received flags remain set to TRUE to
                                     * reattempt the message linker check when any new Pdu from the pair arrives.*/
                                    rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
                                    rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
                                    /* reset same buffer because it is already reserved in StartOfReception */
                                    SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                                }
                             }
                        else
                        {
                            /* MR12 RULE 16.4 VIOLATION: no action is necessary */
                        }
                    }
                }
                else
                {   /* TRACE[SWS_SecOC_00089]: request failed, clear internal buffer */
                    SecOC_Prv_clearRxSecuredPduContext(rxSecuredPduCtx_pst);
                }
                SecOC_Prv_resetRxTpRxIndPending(id, pduType_u8);
                SecOC_Prv_RxSecuredContextBufferRelease(&rxSecuredPduCtx_pst);
            }
            else
            {
                /* TpRxIndication while context buffer is locked => will be handled in next main function */
                SecOC_Prv_setRxTpRxIndPending(id, pduType_u8, result);
             }
        }

    }
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_HandlePdu
 *
 * \brief  The function handles the secured pdu identified by the context buffer rxPduCtx_pst.
 *         The secured pdu consists of the header (if is dynamic Pdu),
 *         payload, the truncated freshness value and the truncated authenticator (CMAC or signature).
 *         In asynchronous mode the complete secured pdu is copied into an internal buffer and its state is set to
 *         SECOC_RX_STATE_RECEIVED_E. The further proccesing of the pdu is done in the cyclic function
 *         SecOC_MainFunctionRx. In synchronous mode the verification of the authenticator is done with the key given
 *         by the private key interface of SecOC. The key identifier is hold in the pdu configuration structure. If the
 *         verification was successful the authentic pdu, payload without the authenticator and freshness value, is
 *         forwared to the pdu router.
 *
 * \param[in]    SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst  pointer to the private context buffer
 *
 * \param[in]    const PduInfoType*  pduSecInfo_pcst   holds the pointer to the payload of the secured pdu
 *
 * \param[in]    uint8 pduType_u8   holds the pdu type: secured pdu, collection authentic pdu or cryptographic pdu
 *
 ***********************************************************************************************************************
*/
/* HIS METRIC LEVEL VIOLATION in SecOC_Prv_HandlePdu: levels required because of checks according to Autosar */
void  SecOC_Prv_HandlePdu(SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst, PduIdType RxPduId, const PduInfoType* pduSecInfo_pcst, uint8 pduType_u8)
{
    uint32 idx_u32;
    PduIdType idx_cuo;
    uint32 securedRxPduOffset_u32 = 0;
    uint32 securedRxPduLength_u32 = 0;
    PduLengthType pduLength_uo = 0;
    Std_ReturnType pduValid_en = E_NOT_OK;

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

    switch(pduType_u8)
    {
        case SECOC_SECURED_PDU:
        {
            pduLength_uo = pduSecInfo_pcst->SduLength;
            if (   (FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.dynPdu_b)
                || (rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 > 0u))
            {
                /* TRACE[SWS_SecOC_00078][SWS_SecOC_Rb_00078]: Get the minimum of received and configured length in case of dynamic secured PDU */
                if (pduLength_uo > rxPduCtx_pst->pduConfig_pst->pduLength_uo)
                {
                    pduLength_uo = rxPduCtx_pst->pduConfig_pst->pduLength_uo;
                }
            }

            if (rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 > 0u)
            {
                /* dynamic secured Pdu with secured header */
                /* In case of dynamic pdu with header included we need to check the length of Authentic PDU from header. */
                /* TRACE[SWS_SecOC_00263] */
                /* Check if the received Secured Pdu length is bigger than header length  */
                if(pduLength_uo <= rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8)
                {
                    pduValid_en = E_NOT_OK;
                }
                else
                {
                    /* TRACE[SWS_SecOC_00259]: Extract length of Authentic pdu from secured header */
                    /* In this case checks if the configured length of Authentic pdu is smaller or equal with Authentic length from Secured Header */
                    /* Also, it sets the actualAuthenticPduLengthInBits_uo from SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst. */
                    pduValid_en = SecOC_Prv_RxCheckAndSetAuthPduLengthFromSecuredHeader(rxPduCtx_pst, pduSecInfo_pcst->SduDataPtr);
                }
            }
            else if (    (FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.dynPdu_b)
                      || (pduLength_uo == rxPduCtx_pst->pduConfig_pst->pduLength_uo))
            {
                /* dynamic secured Pdu without secured header or static secured Pdu */

                /* Calculate and check the length of authentic pdu
                * TRACE[SWS_SecOC_00257]: static pdu: use configured pdu length for calculation of the payload length
                * TRACE[SWS_SecOC_00258]: dynamic pdu: use received pdu length for calculation of the payload length
                * The correct length is already stored in pduLength_uo.
                * */
                pduValid_en = SecOC_Prv_RxCalculateAuthenticPduLength(rxPduCtx_pst, pduLength_uo);
            }
            else
            {
                /* TRACE[SWS_SecOC_00268]: */
                /* Drop secured Pdu with static length and received length is not equal configured length */
            }

            if (E_OK == pduValid_en)
            {
                /* If the length of Authentic PDU is ok, it will copy the Secured Pdu to the internal buffer. */
                /* TRACE[SWS_SecOC_00314]: check if secured area is valid */
                if (   (securedRxPduLength_u32 == 0u)
                    || (    ((securedRxPduOffset_u32 + securedRxPduLength_u32) * 8u)
                         <= rxPduCtx_pst->actualAuthenticPduLengthInBits_uo)
                    )
                {
                    /* TRACE[SWS_SecOC_00042], TRACE[SWS_SecOC_00078][SWS_SecOC_Rb_00078]: */
                    /* copy payload of the received PDU to the internal buffer */
                    /* MR12 DIR 1.1 VIOLATION: Cast is safe, converting from uint8* to void* to uint8* (inside MemCopy) */
                    SecOC_Prv_MemCopy(
                                rxPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,   /* out: destination */
                                pduSecInfo_pcst->SduDataPtr,                     /* in: source */
                                pduLength_uo);                                  /* in: number of bytes */

                    /* set status to SECOC_RX_STATE_RECEIVED_E to indicate that the secured I-PDU is successfully received */
                    /* and verification can start                                                                          */
                    rxPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVED_E;

                    /* TRACE[SWS_SecOC_00212] */
                    for(idx_u32 = 0; idx_u32 < rxPduCtx_pst->pduConfig_pst->metaDataLen_u8; idx_u32++)
                    {
                        if (NULL_PTR != pduSecInfo_pcst->MetaDataPtr)
                        {
                            rxPduCtx_pst->metaData_pu8[idx_u32] = pduSecInfo_pcst->MetaDataPtr[idx_u32];
                        }
                    }
                }
                else
                {
                    /* reset same buffer because it is already reserved before check of pdu */
                    SecOC_Prv_resetSameBufferRxRefInUse(rxPduCtx_pst);
                }
            }
            else
            {
                /* reset same buffer because it is already reserved before check of pdu */
                SecOC_Prv_resetSameBufferRxRefInUse(rxPduCtx_pst);
            }

            break;
        }
        case SECOC_COLLECTION_CRYPTOGRAPHIC_PDU:
        {
            pduLength_uo = pduSecInfo_pcst->SduLength;
            if (FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.dynCryptoPdu_b)
            {
                /* TRACE[SWS_SecOC_00078][SWS_SecOC_Rb_00078]: Get the minimum of received and configured length in case of dynamic secured PDU */
                if (pduLength_uo > rxPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo)
                {
                    pduLength_uo = rxPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo;
                }
            }

            if (    (FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.dynCryptoPdu_b)
                 || (pduLength_uo == rxPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo))
            {
                SecOC_Prv_HandleCryptographicCollectionPdu(rxPduCtx_pst, RxPduId, pduSecInfo_pcst, pduLength_uo);
            }
            else
            {
                /* TRACE[SWS_SecOC_00268]: cryptographic pdu has invalid size. Can be overwritten */
                rxPduCtx_pst->received_CryptographicPdu_b = FALSE;

                if (FALSE == rxPduCtx_pst->received_AuthenticPdu_b)
                {
                    /* reset same buffer if authentic pdu is not already received because it is already reserved before check of pdu */
                    SecOC_Prv_resetSameBufferRxRefInUse(rxPduCtx_pst);
                }
            }
            break;
        }
        case SECOC_COLLECTION_AUTHENTIC_PDU:
        {
            pduLength_uo = pduSecInfo_pcst->SduLength;
            if (   (FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.dynPdu_b)
                || (rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 > 0u))
            {
                /* TRACE[SWS_SecOC_00078][SWS_SecOC_Rb_00078]: Get the minimum of received and configured length in case of dynamic secured PDU */
                if (pduLength_uo > rxPduCtx_pst->pduConfig_pst->pduLength_uo)
                {
                    pduLength_uo = rxPduCtx_pst->pduConfig_pst->pduLength_uo;
                }
            }

            if (    (rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 > 0u)
                 && ((rxPduCtx_pst->pduConfig_pst->messageLinkLength_u16 + rxPduCtx_pst->pduConfig_pst->messageLinkPos_u16)
                         <= (pduLength_uo * 8u)))
            {
                /* In case of dynamic authentic Pdu with secured header and correct message link */
                /* In case of dynamic pdu with header included we need to check the length of Authentic PDU from header. */
                /* TRACE[SWS_SecOC_00263] */
                /* Check if the received Secured Pdu length is bigger than header length  */
                if(pduLength_uo < rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8)
                {
                    pduValid_en = E_NOT_OK;
                }
                else
                {
                    /* In this case checks if the configured length of Authentic pdu is smaller or equal with Authentic length from Secured Header */
                    /* Also, it sets the actualAuthenticPduLengthInBits_uo from SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst. */
                    pduValid_en = SecOC_Prv_RxCheckAndSetAuthPduLengthFromSecuredHeader(rxPduCtx_pst, pduSecInfo_pcst->SduDataPtr);
                }
            }
            else if (   (0u == rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8)
                     && (FALSE != rxPduCtx_pst->pduConfig_pst->packedBits_stb.dynPdu_b)
                     && ((rxPduCtx_pst->pduConfig_pst->messageLinkLength_u16 + rxPduCtx_pst->pduConfig_pst->messageLinkPos_u16)
                         <= (pduLength_uo * 8u))
                    )
            {
                /* dynamic Authentic Pdu without secured header and with correct message link */
                pduValid_en = E_OK;
                rxPduCtx_pst->actualAuthenticPduLengthInBits_uo = pduLength_uo * 8u;
            }
            else if (   (0u == rxPduCtx_pst->pduConfig_pst->securedHeaderLength_u8)
                     && (FALSE == rxPduCtx_pst->pduConfig_pst->packedBits_stb.dynPdu_b)
                     && (pduLength_uo == rxPduCtx_pst->pduConfig_pst->pduLength_uo))
            {
                 /* static Authentic Pdu */
                 pduValid_en = E_OK;
            }
            else
            {
                 /* TRACE[SWS_SecOC_00268]: */
                 /* Drop invalid authentic Pdu: static length and received length is not equal configured length */
                 /* or dynamic length with incorrect message link                                                */
            }

            if (E_OK == pduValid_en)
            {
                 /* TRACE[SWS_SecOC_00314]: check if secured area is valid */
                 if (   (securedRxPduLength_u32 == 0u)
                     || (    ((securedRxPduOffset_u32 + securedRxPduLength_u32) * 8u)
                          <= rxPduCtx_pst->actualAuthenticPduLengthInBits_uo)
                    )
                {
                    SecOC_Prv_HandleAuthenticCollectionPdu(rxPduCtx_pst, RxPduId, pduSecInfo_pcst, pduLength_uo);
                }
                else
                {
                    if (FALSE == rxPduCtx_pst->received_CryptographicPdu_b)
                    {
                        /* reset same buffer if cryptographic pdu is not already received because it is already reserved before check of pdu */
                        SecOC_Prv_resetSameBufferRxRefInUse(rxPduCtx_pst);
                    }
                }
            }
            else
            {
                if (FALSE == rxPduCtx_pst->received_CryptographicPdu_b)
                {
                    /* reset same buffer if cryptographic pdu is not already received because it is already reserved before check of pdu */
                    SecOC_Prv_resetSameBufferRxRefInUse(rxPduCtx_pst);
                }
            }
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

/**
 ***********************************************************************************************************************
 * SecOC_Prv_HandleAuthenticCollectionPdu
 *
 * \brief  This function handles the received Authentic Collection Pdu. It copies the Authentic Collection Pdu in
 *         Secured buffers. It checks if the Message linker length is > 0. If so, it checks the Cryptographic Collection
 *         Pdu is already received, then it checks, if the message linker matches. If the message
 *         linker matches, then a valid Collection is received, otherwise the Pdu is kept in buffers and it waits
 *         for a new Authentic or Cryptographic Pdu to be received. If the Collection
 *         Pdu is received and Authentic buffers from Authentic Context are free then it copies the Collection
 *         Pdu to Authentic buffers, set the status of Authentic Context to VERIFY, clears the Secured context
 *         buffers and set the Secured context status to IDLE. Otherwise, the Collection Pdu remains in Secured
 *         Buffers and set the Secured context status to RECEIVED.
 *
 *
 * \param[in]   SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst      pointer to private secured context buffer of
 *                                                                          the rx pdu
 * \param[in]   PduIdType                          RxPduId                  identifier of the secured Pdu
 * \param[in]   const PduInfoType*                 pduSecInfo_pcst          pointer to the payload of Authentic
 *                                                                          Collection Pdu
 * \param[in]   PduLengthType                      pduLength_uo             Pdu length
 *
 * \return  void
 ***********************************************************************************************************************
*/
void SecOC_Prv_HandleAuthenticCollectionPdu(SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst, PduIdType RxPduId,
                                                   const PduInfoType* pduSecInfo_pcst, PduLengthType pduLength_uo)
{
    SecOC_Prv_RxAuthenticPduContext_tst *rxAuthenticPduCtx_pst = NULL_PTR;
    SecOC_Prv_RxAuthenticPduState_tu8 ctxAuthenticBufferState_u8;
    uint32 idx_u32;

    PduIdType idx_cuo = rxSecuredPduCtx_pst->pduConfig_pst->freshnessValueId_cst.idx_cuo;
    uint16 valueID_u16   = (*rxSecuredPduCtx_pst->pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo];
    SecOC_OverrideStatusType overrideStatus_u8 = SecOC_Prv_fetchOverrideStatus(valueID_u16);

    rxSecuredPduCtx_pst->received_AuthenticPdu_b = TRUE;
    rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVED_E;

    /* In case of both authentic and cryptographic were received but the current authentic
       pdu was overwritten by overflow strategy, a new message linker check needs to be performed. */
    if ((FALSE == rxSecuredPduCtx_pst->received_CryptographicPdu_b) &&
        (SECOC_RX_STATE_RECEIVED_E == rxSecuredPduCtx_pst->cryptographicPduStatus_u8))
    {
        /* Set the received cryptographic flag to trigger the message linker check. */
        rxSecuredPduCtx_pst->received_CryptographicPdu_b = TRUE;
    }

        /* TRACE[SWS_SecOC_00042], TRACE[SWS_SecOC_00078][SWS_SecOC_Rb_00078]: */
        /* copy payload of the received PDU to the internal buffer */
        if (pduLength_uo > 0U)
        {
          /* MR12 DIR 1.1 VIOLATION: Cast is safe, converting from uint8* to void* to uint8* (inside MemCopy) */
            SecOC_Prv_MemCopy(
                rxSecuredPduCtx_pst->pduConfig_pst->pduBufferIn_pu8, /* out: destination */
                pduSecInfo_pcst->SduDataPtr,                   /* in: source */
                pduLength_uo);                                /* in: number of bytes */
        }

        /* TRACE[SWS_SecOC_00212] */
        for(idx_u32 = 0; idx_u32 < rxSecuredPduCtx_pst->pduConfig_pst->metaDataLen_u8; idx_u32++)
        {
            if (NULL_PTR != pduSecInfo_pcst->MetaDataPtr)
            {
                rxSecuredPduCtx_pst->metaData_pu8[idx_u32] = pduSecInfo_pcst->MetaDataPtr[idx_u32];
            }
        }

    /* TRACE[SWS_SecOC_00203], TRACE[SWS_SecOC_00210], TRACE[SWS_SecOC_00211]: */
    if(    (FALSE != rxSecuredPduCtx_pst->received_CryptographicPdu_b)
        || (SECOC_OVERRIDE_TO_PASS  == overrideStatus_u8)
      )
    {
        /* MR12 RULE 13.5 VIOLATION: SecOC_Prv_RxCheckMessageLinks checks the message linker, it is safe to not be
           called when overrideStatus_u8 is set to PASS or SKIP.*/
        if(    (FALSE != SecOC_Prv_RxCheckMessageLinks(rxSecuredPduCtx_pst))
            || (SECOC_OVERRIDE_TO_PASS  == overrideStatus_u8)
          )
        {
            /* Set cryptographicPduStatus_u8 to RECEIVED to indicate that a valid Collection PDU is ready for verification */
            rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_RECEIVED_E;
            if(    (0u != rxSecuredPduCtx_pst->pduConfig_pst->messageLinkLength_u16)

                || (SECOC_OVERRIDE_TO_PASS == overrideStatus_u8)
              )
            {
                rxAuthenticPduCtx_pst = SecOC_Prv_RxAuthenticContextBufferAllocate(RxPduId);
                if (NULL_PTR != rxAuthenticPduCtx_pst)
                {
                    /* Check the status is IDLE after lock was got  */
                    ctxAuthenticBufferState_u8 = SecOC_Prv_RxAuthenticContextBufferGetState(RxPduId);

                    if (SECOC_RX_STATE_AUTHENTIC_IDLE_E == ctxAuthenticBufferState_u8)
                    {
                        /* The Collection Pdu data is copied in Authentic Context Buffers */
                        SecOC_Prv_CopyPduFromSecuredCtxToAuthenticCtx(rxSecuredPduCtx_pst, rxAuthenticPduCtx_pst);

                        /* Free secured buffers */
                        SecOC_Prv_clearRxSecuredPduContext(rxSecuredPduCtx_pst);
                    }
                    else
                    {
                        /* Nothing to do. The Authentic Buffers are busy. Wait for MainFunction to get the PDU */
                    }

                    SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                }
                else
                {
                    /* Nothing to do. The Authentic Buffers are busy. Wait for MainFunction to get the PDU */
                }
            }
            else
            {
                /* PDU w/o Message Linker -> rely on time related authentic and cryptographic PDUs.
                   Both must be received in same cycle before MainFunctionRx.
                   MainFunctionRx pairs the latest received Pdus w/o linker check */
            }
        }
        else
        {
            /* Both pdus remain buffered and the verification will be reattempted when new data arrives.
             * In this case, the status_u8 and cryptographicPduStatus_u8 are set to IDLE in order to accept
             * new pdus, but the received flags remain set to TRUE to reattempt the message linker check when
             * any new Pdu from the pair arrives.*/
            rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
            rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
        }
    }
    else
    {
       /* wait for cryptographic pdu for verification. */
    }
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_HandleCryptographicCollectionPdu
 *
 * \brief  This function handles the received Cryptographic Collection Pdu. It copies the Cryptographic Collection Pdu
 *         in Secured buffers. It checks if the Message linker length is > 0. If so, it checks ifthe Authentic
 *         Collection Pdu is already received, then it checks if the message
 *         linker matches, then a valid Collection is received, otherwise the Pdu
 *         is kept in buffers and it waits for a new Authentic or Cryptographic Pdu to be received. If the Collection
 *         Pdu is received and Authentic buffers from Authentic Context are free then it copies the Collection
 *         Pdu to Authentic buffers, set the status of Authentic Context to VERIFY, clears the Secured context
 *         buffers and set the Secured context status to IDLE. Otherwise, the Collection Pdu remains in Secured
 *         Buffers and set the Secured context status to RECEIVED.
 *
 *
 * \param[in]   SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst      pointer to private secured context buffer of
 *                                                                          the rx pdu
 * \param[in]   PduIdType                          RxPduId                  identifier of the secured Pdu
 * \param[in]   const PduInfoType*                 pduSecInfo_pcst          pointer to the payload of Cryptographic
 *                                                                          Collection Pdu
 * \param[in]   PduLengthType                      pduLength_uo             Pdu length
 *
 * \return  void
 ***********************************************************************************************************************
*/
void SecOC_Prv_HandleCryptographicCollectionPdu(SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst, PduIdType RxPduId,
                                                   const PduInfoType* pduSecInfo_pcst, PduLengthType pduLength_uo)
{
    SecOC_Prv_RxAuthenticPduContext_tst *rxAuthenticPduCtx_pst = NULL_PTR;
    SecOC_Prv_RxAuthenticPduState_tu8 ctxAuthenticBufferState_u8;


    rxSecuredPduCtx_pst->received_CryptographicPdu_b = TRUE;
    rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_RECEIVED_E;

    /* In case of both authentic and cryptographic were received but the current cryptographic
       pdu was overwritten by overflow strategy, a new message linker check needs to be performed. */
    if ((FALSE == rxSecuredPduCtx_pst->received_AuthenticPdu_b) &&
        (SECOC_RX_STATE_RECEIVED_E == rxSecuredPduCtx_pst->status_u8))
    {
        /* Set the received authentic flag to trigger the message linker check. */
        rxSecuredPduCtx_pst->received_AuthenticPdu_b = TRUE;
    }
    /* TRACE[SWS_SecOC_00042], TRACE[SWS_SecOC_00078][SWS_SecOC_Rb_00078]: */
    /* copy payload of the received PDU to the internal buffer */

    /* MR12 DIR 1.1 VIOLATION: Cast is safe, converting from uint8* to void* to uint8* (inside MemCopy) */
    SecOC_Prv_MemCopy(
          rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferIn_pu8,    /* out: destination */
          pduSecInfo_pcst->SduDataPtr,                                   /* in: source */
          pduLength_uo);                                                /* in: number of bytes */

    /* TRACE[SWS_SecOC_00203], TRACE[SWS_SecOC_00210], TRACE[SWS_SecOC_00211]: */
    /* set status to SECOC_RX_STATE_RECEIVED_E to indicate that the collection I-PDU (cryptographic pdu and
     * authentic pdu) is successfully received and Message Linker is matching. The verification can start
     */
    if(FALSE != rxSecuredPduCtx_pst->received_AuthenticPdu_b)
    {
        if (FALSE != SecOC_Prv_RxCheckMessageLinks(rxSecuredPduCtx_pst))
        {
           /* The status_u8 is set to RECEIVED in order to be processed by
              MainFunctionRx because the authentic Pdu is already in buffer. */
            rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVED_E;

            if(0u != rxSecuredPduCtx_pst->pduConfig_pst->messageLinkLength_u16)
            {
                rxAuthenticPduCtx_pst = SecOC_Prv_RxAuthenticContextBufferAllocate(RxPduId);
                if (NULL_PTR != rxAuthenticPduCtx_pst)
                {
                    /* Check again status to be sure that the status is IDLE after lock was got  */
                    ctxAuthenticBufferState_u8 = SecOC_Prv_RxAuthenticContextBufferGetState(RxPduId);

                    if (SECOC_RX_STATE_AUTHENTIC_IDLE_E == ctxAuthenticBufferState_u8)
                    {
                        /* The Collection Pdu data is copied in Authentic Context Buffers */
                        SecOC_Prv_CopyPduFromSecuredCtxToAuthenticCtx(rxSecuredPduCtx_pst, rxAuthenticPduCtx_pst);

                        /* Free secured buffers */
                        SecOC_Prv_clearRxSecuredPduContext(rxSecuredPduCtx_pst);
                    }
                    else
                    {
                        /* Nothing to do. The Authentic Buffers are busy. Wait for MainFunction to get the PDU */
                    }

                    SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                }
                else
                {
                    /* Nothing to do. The Authentic Buffers are busy. Wait for MainFunction to get the PDU */
                }
            }
            else
            {
                /* PDU w/o Message Linker -> rely on time related authentic and cryptographic PDUs.
                   Both must be received in same cycle before MainFunctionRx.
                   MainFunctionRx pairs the latest received Pdus w/o linker check */
            }
        }
        else
        {
            /* Both pdus remain buffered and the verification will be reattempted when new data arrives.
             * In this case, the status_u8 and cryptographicPduStatus_u8 were set to IDLE in order to accept
             * new pdus, but the received flags remain set to TRUE to reattempt the message linker check when
             * any new Pdu from the pair arrives.*/
            rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
            rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
        }
    }
    else
    {
        /* wait for authentic pdu for verification. */
    }
}

#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"
