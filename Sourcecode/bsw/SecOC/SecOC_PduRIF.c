/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Source file providing interface from the SecOC module to PDU Router.
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"            /* SecOC module header */
#include "SecOC_Prv.h"        /* SecOC private header */
#include "SecOC_Prv_PduRIf.h" /* SecOC PduRIf header for function declaration */
#include "Rte_SecOC.h"        /* RTE functions */

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"
/**
 ***********************************************************************************************************************
 * SecOC_TpCancelReceive
 *
 * \brief  Requests cancellation of an ongoing reception of a PDU in a lower layer transport protocol module.
 *
 * \param[in]    PduIdType            RxPduId        identifier of the authentic Pdu to be cancelled
 *
 * \return       Std_ReturnType     - E_OK    : cancellation was executed successfully
 *                                  - E_NOT_OK: cancellation was rejected
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_TpCancelReceive(PduIdType RxPduId)
{
    /* TRACE[SWS_SecOC_91010]: Implementation of SecOC_TpCancelReceive */
    /* SRS_SecOC_00012, SRS_BSW_00357, SRS_BSW_00449: BSW Service APIs called by RTE shall return Std_ReturnType */

    SecOC_Prv_RxAuthenticPduContext_tst *rxAuthenticPduCtx_pst = NULL_PTR;
    SecOC_Prv_RxAuthenticPduState_tu8 authenticCtxState_u8;
    SecOC_Prv_RxSecuredPduContext_tst* rxSecuredPduCtx_pst = NULL_PTR;
    SecOC_Prv_RxSecuredPduState_tu8 securedCtxState_u8;
    Std_ReturnType result1 = E_NOT_OK;
    Std_ReturnType result2 = E_NOT_OK;
    Std_ReturnType result_en = E_NOT_OK;


    /* check state of SecOC */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    /* SRS_BSW_00323: check input parameters */
    else if (RxPduId > SECOC_MAX_RX_PDU_ID)
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        // Check state of authentic PDU
        authenticCtxState_u8 = SecOC_Prv_RxAuthenticContextBufferGetState(RxPduId);

        if (SECOC_RX_STATE_VERIFY_E == authenticCtxState_u8)
        {
            /* TRACE[SWS_SecOC_Rb_00217]:                                                                 */
            /* PDU data are already copied into authentic context buffer but PDU is not yet handled in */
            /* MainFunction => release authentic context buffer                                        */
            /* Secured context buffer is already released if state VERIFY is set.                      */
            rxAuthenticPduCtx_pst = SecOC_Prv_RxAuthenticContextBufferAllocate(RxPduId);
            if (NULL_PTR != rxAuthenticPduCtx_pst)
            {
                SecOC_Prv_clearRxAuthenticPduContext(rxAuthenticPduCtx_pst);
                SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                result1 = E_OK;
            }
        }
        else if (SECOC_RX_STATE_WAIT_FOR_CSM_CALLBACK_E == authenticCtxState_u8)
        {
            /* TRACE[SWS_SecOC_Rb_00217]: PDU is waiting for callback, set state to discard callback */
            rxAuthenticPduCtx_pst = SecOC_Prv_RxAuthenticContextBufferAllocate(RxPduId);
            if (NULL_PTR != rxAuthenticPduCtx_pst)
            {
                /* Try to abort csm job, cancel result will be received in callback */
                /* Authentic context buffer is released in callback */
                SecOC_Prv_CancelCryptJob(rxAuthenticPduCtx_pst->pduConfig_pst->jobId_u32);

                SecOC_Prv_RxAuthenticContextBufferRelease(&rxAuthenticPduCtx_pst);
                result1 = E_OK;
            }
        }
        else
        {
            /* No action needed for all other states */
            result1 = E_OK;
        }

        // Check state of secured PDU
        /* It is ensured that authentic PDU has the same identifier as secured or cryptographic PDU */
        /* because the identifiers are set by SecOC forwarder.                                      */
        /* Therefore RxPduId can also be used for access of secured context.                        */
        securedCtxState_u8 = SecOC_Prv_RxSecuredContextBufferGetState(RxPduId);

        if (  (SECOC_RX_STATE_RECEIVING_E == securedCtxState_u8)
            ||(SECOC_RX_STATE_RECEIVED_E  == securedCtxState_u8))
        {
             /* TRACE[SWS_SecOC_Rb_00217]: */
             /* Secured PDU is receiving or already completely received */
             /* Reception cannot be canceled because PduR supports not this interface */
             /* Clear secured context, set state to IDLE */
             /*  => SecOC_CopyRxData and SecOC_TpRxIndication will do nothing */
             rxSecuredPduCtx_pst = SecOC_Prv_RxSecuredContextBufferAllocate(RxPduId);
             if (NULL_PTR != rxSecuredPduCtx_pst)
             {
                 SecOC_Prv_clearRxSecuredPduContext(rxSecuredPduCtx_pst);
                 SecOC_Prv_RxSecuredContextBufferRelease(&rxSecuredPduCtx_pst);
                 result2 = E_OK;
             }
        }
        else
        {
            /* No action needed for all other states */
            result2 = E_OK;
        }

        /* If authentic and secured part are handled correctly return E_OK */
        if ((E_OK == result1) && (E_OK == result2))
        {
            result_en = E_OK;
        }
    }

    return(result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_RxIndication
 *
 * \brief  The function is called from PduR to trigger the receipt of a secured Pdu.
 *         After checking the state of SecOC and the input parameters the function SecOC_Prv_HandlePdu
 *         to handle the secured Pdu is called. This function verifies the authenticator of the secured Pdu.
 *         If the authenticator is valid the function SecOC_Prv_HandlePdu returns the authentic Pdu (means the
 *         payload of the secured Pdu without authenticator and freshness information).This Pdu is forwarded to the
 *         PduR for further routing via the function PduR_SecOCIf|TpRxIndication.
 *         If SecOC is not initialized no error is returned but it is reported to Det.
 *
 * \param[in]    PduIdType           RxPduId        identifier of the secured Pdu
 *
 * \param[in]    const PduInfoType*  PduInfoPtr     pointer to the payload of secured Pdu
 *
 * \return       void
 ***********************************************************************************************************************
*/
/* HIS METRIC LEVEL VIOLATION in SecOC_RxIndication: levels required because of checks according to Autosar */
void SecOC_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr)
{
    /* TRACE[SWS_SecOC_00124]: Implementation of SecOC_RxIndication. */
    /* (SRS_BSW_00323, SRS_BSW_00359, SRS_SecOC_00012) */
    SecOC_Prv_RxSecuredPduContext_tst* rxSecuredPduCtx_pst;
    SecOC_Prv_RxSecuredPduState_tu8 securedCtxState_u8;
    SecOC_Prv_RxOvrflwStrat_en rxOverflowStrategy;
    uint8 pduType_u8 = 0;


    /* check state of SecOC */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    /* check input parameters */
    else if (NULL_PTR == PduInfoPtr)
    {
        /* TRACE[]|Det disabled */
    }
    else if (RxPduId > SECOC_MAX_RX_PDU_ID)
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        pduType_u8 = SecOC_Prv_RxGetPduType(RxPduId);

        /* if RxPduId is collection authentic pduId then calculate the related cryptographic pduId */
        if (SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8)
        {
            RxPduId = RxPduId - SECOC_NUMBER_RX_COLLECTION_PDU;
        }

        /* save access to static configuration via secured Pdu context*/
        rxOverflowStrategy = SecOC_Prv_RxSecuredPduContext_ast[RxPduId].pduConfig_pst->rxOvrflwStrat_e;
        securedCtxState_u8 = SecOC_Prv_RxPduContextBufferGetState(RxPduId, pduType_u8);
        /* According to AR4.5 */
        /* TRACE[SWS_SecOC_00214], TRACE[SWS_SecOC_00215], TRACE[SWS_SecOC_00216]: Overflow strategy */
        /* (SRS_SecOC_00021, SRS_SecOC_00022) */
        if (    (SECOC_RX_STATE_SECURED_IDLE_E == securedCtxState_u8)
             || (SECOC_RX_REPLACE_E == rxOverflowStrategy)
             || (    (SECOC_RX_QUEUE_E   == rxOverflowStrategy)
                  && (SECOC_RX_STATE_RECEIVED_E == securedCtxState_u8)))
        {
            rxSecuredPduCtx_pst = SecOC_Prv_RxSecuredContextBufferAllocate(RxPduId);

            if (NULL_PTR != rxSecuredPduCtx_pst)
            {
                if (FALSE == SecOC_Prv_lockSameBuffer(rxSecuredPduCtx_pst->pduConfig_pst->isSameBufferRefInUse_pb,
                                                      rxSecuredPduCtx_pst->pduConfig_pst->sameBufferRefInUsePduId_puo,
                                                      RxPduId))
                {
                    /* TRACE[]|Det disabled */
                }
                else
                {
                    /* Check PduInfoPtr data. */
                    if ((NULL_PTR == PduInfoPtr->SduDataPtr) || (PduInfoPtr->SduLength == 0u))
                    {
                        /* Only Authentic Collection Pdu can be received with length 0 when it is a static
                           collection pdu (secured header = 0) and when the configured value auth pdu length is 0. */
                        if (SECOC_COLLECTION_AUTHENTIC_PDU != pduType_u8)
                        {
                            /* reset same buffer because it is already reserved before check of pdu */
                            SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                            /* TRACE[]|Det disabled */
                        }
                        else if ((rxSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 == 0u) &&
                                 (rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo > 0u))
                        {
                           /* reset same buffer because it is already reserved before check of pdu */
                            SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                            /* TRACE[]|Det disabled */
                        }
                        else if (rxSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 > 0u)
                        {
                            /* reset same buffer because it is already reserved before check of pdu */
                            SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                            /* TRACE[]|Det disabled */
                        }
                        else
                        {
                            SecOC_Prv_HandlePdu(rxSecuredPduCtx_pst, RxPduId, PduInfoPtr, pduType_u8);
                        }
                    }
                    else
                    {
                        SecOC_Prv_HandlePdu(rxSecuredPduCtx_pst, RxPduId, PduInfoPtr, pduType_u8);
                    }
                }
                SecOC_Prv_RxSecuredContextBufferRelease(&rxSecuredPduCtx_pst);
            }
        }
        else
        {
            /* PDU with same identifier is already handled, do nothing */
            /* TRACE[SWS_RB_SecOC_00101]|Det disabled */
        }
    }
}

/**
 ***********************************************************************************************************************
 * SecOC_StartOfReception
 *
 * \brief This function is called at the start of receiving an N-SDU. The N-SDU might be fragmented into multiple N-PDUs
 *        (FF with one or more following CFs) or might consist of a single N-PDU (SF).
 *
 * \param[in]  PduIdType          id            Identification of the I-PDU.
 *
 * \param[in]  const PduInfoType* info          Pointer to a PduInfoType structure containing the payload data (without
 *                                              protocol information) and payload length of the first frame or single
 *                                              frame of a transport protocol I-PDU reception. Depending on the global
 *                                              parameter MetaDataLength, additional bytes containing MetaData (e.g. the
 *                                              CAN ID) are appended after the payload data, increasing the length
 *                                              accordingly. If neither first/single frame data nor MetaData are
 *                                              available, this parameter is set to NULL_PTR.
 *
 * \param[in]  PduLengthType     TpSduLength    Total length of the N-SDU to be received in byte.
 *
 * \param[out] PduLengthType*    bufferSizePtr  Available receive buffer in the receiving module. This parameter will be
 *                                              used to compute the Block Size (BS) in the transport protocol module.
 *
 * \return BufReq_ReturnType:
 *         - BUFREQ_OK: Connection has been accepted. bufferSizePtr indicates the available receive buffer; reception is
 *                      continued. If no buffer of the requested size is available, a receive buffer size of 0 shall be
 *                      indicated by bufferSizePtr.
 *         - BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr remains unchanged.
 *         - BUFREQ_E_OVFL: No buffer of the required length can be provided; reception is aborted. bufferSizePtr
 *                          remains unchanged.
 ***********************************************************************************************************************
 **/
/* HIS METRIC LEVEL VIOLATION in SecOC_StartOfReception: levels required because of checks according to Autosar */
BufReq_ReturnType SecOC_StartOfReception( PduIdType id, const PduInfoType* info, PduLengthType TpSduLength,
                                          PduLengthType* bufferSizePtr )
{
    uint8_least idx_qu8;
    /* TRACE[SWS_SecOC_00130]: Implementation of SecOC_StartOfReception */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_SecOC_00012) */
    SecOC_Prv_RxOvrflwStrat_en rxOverflowStrategy;
    SecOC_Prv_RxSecuredPduState_tu8 ctxState_u8;
    PduIdType idx_cuo;
    uint32 securedRxPduOffset_u32 = 0;
    uint32 securedRxPduLength_u32 = 0;
    SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst = NULL_PTR;
    Std_ReturnType checkSecuredHeaderResult_en = E_OK;
    uint8 pduType_u8 = 0;
    boolean  invalidSecuredArea_b = FALSE;
    Std_ReturnType  invalidSecuredLength_b = E_OK;
    PduLengthType authPduLen_uo = 0;
    BufReq_ReturnType result_en = BUFREQ_E_NOT_OK; /* TRACE[SWS_SecOC_00109] */
    /* We assume positive initialization because in case of static PDU, this variable will always
       be E_OK. In case of dynamic PDU the check for length from header will be performed
       and this variable will be updated. */


    /* check state of SecOC */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else if (NULL_PTR == bufferSizePtr)
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

        /* save access to static configuration via secured Pdu context*/
        rxOverflowStrategy = SecOC_Prv_RxSecuredPduContext_ast[id].pduConfig_pst->rxOvrflwStrat_e;
        ctxState_u8 = SecOC_Prv_RxPduContextBufferGetState(id, pduType_u8);

        /* TRACE[SWS_SecOC_00214], TRACE[SWS_SecOC_00215], TRACE[SWS_SecOC_00216]: Overflow strategy */
        /* (SRS_SecOC_00021, SRS_SecOC_00022) */
        if (    (SECOC_RX_STATE_SECURED_IDLE_E == ctxState_u8)
             || (SECOC_RX_REPLACE_E == rxOverflowStrategy)
             || (    (SECOC_RX_QUEUE_E   == rxOverflowStrategy)
                  && (SECOC_RX_STATE_RECEIVED_E == ctxState_u8)))
        {
            rxSecuredPduCtx_pst = SecOC_Prv_RxSecuredContextBufferAllocate(id);

            if (NULL_PTR != rxSecuredPduCtx_pst)
            {
                if (FALSE == SecOC_Prv_lockSameBuffer(rxSecuredPduCtx_pst->pduConfig_pst->isSameBufferRefInUse_pb,
                                                      rxSecuredPduCtx_pst->pduConfig_pst->sameBufferRefInUsePduId_puo,
                                                      id))
                {
                    /* TRACE[]|Det disabled */
                }
                else
                {
                    if((SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8) || (SECOC_SECURED_PDU == pduType_u8))
                    {
                        /* If we don't have enough memory to hold the total Sdu, we return with BUFREQ_E_OVFL indicating that
                        * we can't provide a large enough buffer.
                        */
                        if ((TpSduLength > rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo)
                            || ((NULL_PTR != info) && (info->SduLength > rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo)))
                        {
                            // If the complete Sdu length or the first segment Sdu length
                            // is longer than our maxmimum buffer length, report an overflow error.
                            result_en = BUFREQ_E_OVFL;
                        }
                        /* The TpSduLength can be unequal to the configured pdu length in case of Dynamic Pdu, but not in case of Static Pdu. */
                        else if (    (TpSduLength != rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo)
                                  && (rxSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 == 0)
                                  && (!rxSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.dynPdu_b) )
                        {
                            result_en = BUFREQ_E_NOT_OK;
                        }
                        /* In case of Collection Authentic Pdu with Message Linker enabled checks if the length of Message Linker plus position is smaller than Authentic Pdu. */
                        else if ((0u != rxSecuredPduCtx_pst->pduConfig_pst->messageLinkLength_u16) &&
                                ((rxSecuredPduCtx_pst->pduConfig_pst->messageLinkLength_u16 + rxSecuredPduCtx_pst->pduConfig_pst->messageLinkPos_u16) > (TpSduLength * 8u)))
                        {
                            result_en = BUFREQ_E_NOT_OK;
                        }
                        else
                        {
                            /* NULL_PTR check for optional secured area values needed */
                            if(NULL_PTR != rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.value_pacu32)
                            {
                                idx_cuo = rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.idx_cuo;
                                securedRxPduOffset_u32 = (*rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.value_pacu32)[idx_cuo];
                            }
                            if(NULL_PTR != rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)
                            {
                                idx_cuo = rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.idx_cuo;
                                securedRxPduLength_u32 = (*rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)[idx_cuo];
                            }

                            /*In case of dynamic Pdu with secured header */
                            if(0u != rxSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8)
                            {
                                /* In case of Dynamic Pdu with header we need to check the length of Authentic PDU from header */
                                /* Check the length and payload of info Pdu and check if the length of first chunk is sufficient to extract header. */
                                /* If the first chunk is not sufficient to extract the header it will be retry in CopyRxData. */
                                /* TRACE[SWS_SecOC_00263] */
                                if (( NULL_PTR != info ) && (NULL_PTR != info->SduDataPtr) && (rxSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8 <= info->SduLength))
                                {
                                    checkSecuredHeaderResult_en = SecOC_Prv_RxCheckAndSetAuthPduLengthFromSecuredHeader(rxSecuredPduCtx_pst, info->SduDataPtr);
                                    /* TRACE[SWS_SecOC_00314]: check if secured area is valid for secured PDU or authentic PDU of collection */
                                     if (    (securedRxPduLength_u32 > 0u)
                                          && ((   (securedRxPduOffset_u32 + securedRxPduLength_u32) * 8u)
                                                > rxSecuredPduCtx_pst->actualAuthenticPduLengthInBits_uo)
                                        )
                                     {
                                         invalidSecuredArea_b = TRUE;
                                     }
                                }
                            }
                            else // In case of dynamic Pdu without secured header or static Pdu length
                            {
                                if (rxSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.dynPdu_b)
                                {
                                    if (SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8)
                                    {
                                        /* calculate actual length of authentic pdu for collection pdu */
                                        if (0 == TpSduLength)
                                        {
                                            /* update actual length of dynamic collection authentic pdu based on received configured length */
                                            rxSecuredPduCtx_pst->actualAuthenticPduLengthInBits_uo = rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo * 8u;
                                        }
                                        else
                                        {
                                            /* update actual length of dynamic collection authentic pdu based on received TpSduLength */
                                            rxSecuredPduCtx_pst->actualAuthenticPduLengthInBits_uo = TpSduLength * 8u;
                                        }
                                    }
                                    else
                                    {
                                        /* calculate actual length of authentic pdu for secured pdu */
                                        if (0 == TpSduLength)
                                        {
                                            /* TRACE[SWS_SecOC_00258]: if no complete length is available the configured length is used for calculation of actual length of authentic pdu */
                                            invalidSecuredLength_b = SecOC_Prv_RxCalculateAuthenticPduLength(rxSecuredPduCtx_pst, rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo);
                                        }
                                        else
                                        {
                                            /* TRACE[SWS_SecOC_00258]: update length of authentic pdu if configured length do not fit into the secured pdu based on received TpSduLength */
                                            invalidSecuredLength_b = SecOC_Prv_RxCalculateAuthenticPduLength(rxSecuredPduCtx_pst, TpSduLength);
                                        }
                                    }
                                }

                                /* Check secured area */
                                /* TRACE[SWS_SecOC_00314]: check if secured area is valid for secured PDU or authentic PDU of collection */
                                if(    (securedRxPduLength_u32 > 0u)
                                    && (   ((securedRxPduOffset_u32 + securedRxPduLength_u32) * 8u)
                                         > rxSecuredPduCtx_pst->actualAuthenticPduLengthInBits_uo))
                                {
                                    invalidSecuredArea_b = TRUE;
                                }
                            }

                            /* Check the secured area flag for dynamic pdus */
                            if (FALSE != invalidSecuredArea_b)
                            {
                                result_en = BUFREQ_E_NOT_OK;
                                /* TRACE[SWS_SecOC_Rb_00314]: Call DET to notify that the received secured/authentic collection PDU
                                is discarded because the PDU length is smaller than secured area length. */
                                /* TRACE[SWS_SecOC_Rb_00314]|Det disabled */
                            }
                            /* The length of the Authentic Pdu from Secured Header is not OK. Return BUFREQ_E_NOT_OK accordind to [SWS_SecOC_00263] */
                            else if (   (E_OK != checkSecuredHeaderResult_en)
                                     || (E_OK != invalidSecuredLength_b))
                            {
                                result_en = BUFREQ_E_NOT_OK;
                            }
                            else
                            {
                                /* TRACE[SWS_SecOC_00082]: calling PduR_SecOCTpStartOfReception in case SecOCPduType
                                After successful verification only authentic part is forwarded to upper layer.
                                Therefore announche only pdus containing authentic payload */
                                if (FALSE != rxSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.pduTpType_b)
                                {
                                    authPduLen_uo = ((rxSecuredPduCtx_pst->actualAuthenticPduLengthInBits_uo + 7u) >> 3u);
                                    result_en = PduR_SecOCTpStartOfReception(
                                                    rxSecuredPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo,
                                                    NULL_PTR,
                                                    authPduLen_uo,
                                                    &rxSecuredPduCtx_pst->upTpBufSize_uo);
                                }
                                else
                                {
                                    result_en = BUFREQ_OK;
                                }
                                /* TRACE[SWS_SecOC_00082]: In case of PduTpType reject Rx, if upper layer does not
                                 * accept Rx */
                                if(BUFREQ_OK == result_en)
                                {
                                    /* Reset the buffer position */
                                    rxSecuredPduCtx_pst->bufferPosition_uo = 0;
                                    *bufferSizePtr = rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo;
                                    rxSecuredPduCtx_pst->received_AuthenticPdu_b = FALSE;

                                    /* First frame or single frame data available? */
                                    if (( NULL_PTR != info ) && (NULL_PTR != info->SduDataPtr))
                                    {
                                        /* Copy the first / single frame data into our internal buffer */
                                        SecOC_Prv_MemCopy(
                                            /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                            rxSecuredPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,
                                            /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                            info->SduDataPtr,
                                            info->SduLength);

                                        rxSecuredPduCtx_pst->bufferPosition_uo += info->SduLength;
                                        *bufferSizePtr = rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo - rxSecuredPduCtx_pst->bufferPosition_uo;
                                    }
                                    rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_RECEIVING_E;
                                    if (( NULL_PTR != info ) && ( NULL_PTR != info->MetaDataPtr ))
                                    {   /* TRACE[SWS_SecOC_00212] */
                                        /* Copy MetaData as with RxIndication data will be invalid in transproter layer and
                                        can't be reused later in transport protocol
                                        Done only for secured and authentic Pdu, cryptographic metadata are redundant copy of
                                        authentic Pdu*/
                                        for(idx_qu8 = 0; idx_qu8 < rxSecuredPduCtx_pst->pduConfig_pst->metaDataLen_u8; idx_qu8++)
                                        {
                                            rxSecuredPduCtx_pst->metaData_pu8[idx_qu8] = info->MetaDataPtr[idx_qu8];
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {   /* SECOC_COLLECTION_CRYPTOGRAPHIC_PDU
                         * If we don't have enough memory to hold the total Sdu, we return with BUFREQ_E_OVFL indicating
                         * that we can't provide a large enough buffer.
                         */
                        if ((TpSduLength > rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo)
                            || ((NULL_PTR != info) && (info->SduLength > rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo)))
                        {
                            // If the complete Sdu length or the first segment Sdu length
                            // is longer than our maxmimum buffer length, report an overflow error.
                            result_en = BUFREQ_E_OVFL;
                        }
                        else if (   (TpSduLength != rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo)
                                 && (FALSE == rxSecuredPduCtx_pst->pduConfig_pst->packedBits_stb.dynCryptoPdu_b))
                        {
                            result_en = BUFREQ_E_NOT_OK;
                        }
                        else
                        {
                            /* Reset the buffer position */
                            rxSecuredPduCtx_pst->cryptographicPduBufferPosition_uo = 0;
                            rxSecuredPduCtx_pst->received_CryptographicPdu_b = FALSE;
                            *bufferSizePtr = rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo;

                            /* First frame or single frame data available? */
                            if (( NULL_PTR != info ) && (NULL_PTR != info->SduDataPtr))
                            {
                                /* Copy the first / single frame data into our internal buffer */
                                SecOC_Prv_MemCopy(
                                    /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                    rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferIn_pu8,
                                    /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                    info->SduDataPtr,
                                    info->SduLength);

                                rxSecuredPduCtx_pst->cryptographicPduBufferPosition_uo += info->SduLength;
                                *bufferSizePtr = rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo -
                                                 rxSecuredPduCtx_pst->cryptographicPduBufferPosition_uo;
                            }
                            rxSecuredPduCtx_pst->cryptographicPduStatus_u8 = SECOC_RX_STATE_RECEIVING_E;
                            result_en = BUFREQ_OK;
                        }
                    }
                    if (BUFREQ_OK != result_en)
                    {
                        /* reset same buffer because it is already reserved before check of PDU */
                        SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                    }
                }

                SecOC_Prv_RxSecuredContextBufferRelease(&rxSecuredPduCtx_pst);
            }
        }
    }


    return(result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_CopyRxData
 *
 * \brief This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer.
 *        Each call to this function provides the next part of the I-PDU data.
 *        The size of the remaining data is written to the position indicated by bufferSizePtr.
 *
 * \param[in] PduIdType          id            Identification of the received I-PDU.
 *
 * \param[in] const PduInfoType* info          Provides the source buffer (SduDataPtr) and the number of bytes to be
 *                                             copied (SduLength). An SduLength of 0 can be used to query the current
 *                                             amount of available buffer in the upper layer module. In this case, the
 *                                             SduDataPtr may be a NULL_PTR.
 *
 * \param[out] PduLengthType*    bufferSizePtr Available receive buffer after data has been copied.
 *
 * \return BufReq_ReturnType:
 *         - BUFREQ_OK: Data copied successfully.
 *         - BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
 ***********************************************************************************************************************
 */
/* HIS METRIC LEVEL VIOLATION in SecOC_CopyRxData: levels required because of checks according to Autosar */
BufReq_ReturnType SecOC_CopyRxData( PduIdType id, const PduInfoType* info, PduLengthType* bufferSizePtr )
{
    /* TRACE[SWS_SecOC_00128]: Implementation of SecOC_CopyRxData */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_SecOC_00012) */
    SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst;
    PduLengthType remainingBufferBytes_uo;
    PduIdType idx_cuo;
    uint32 securedRxPduOffset_u32 = 0;
    uint32 securedRxPduLength_u32 = 0;
    BufReq_ReturnType result_en = BUFREQ_E_NOT_OK;
    /* We assume positive initialization because in case of static PDU, this variable will always
       be E_OK. In case of dynamic PDU the check for length from header will be performed
       and this variable will be updated. */
    Std_ReturnType checkSecuredHeaderResult_en = E_OK;
    uint8 pduType_u8 = 0;


    /* check state of SecOC */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else if ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr))
    {
        /* TRACE[]|Det disabled */
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

        /* Only start processing if the buffer is in RECEIVING state */
        if ((SECOC_RX_STATE_RECEIVING_E == SecOC_Prv_RxPduContextBufferGetState(id, pduType_u8)))
        {
            rxSecuredPduCtx_pst = SecOC_Prv_RxSecuredContextBufferAllocate(id);
            if (NULL_PTR != rxSecuredPduCtx_pst)
            {
                if((SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8) || (SECOC_SECURED_PDU == pduType_u8))
                {
                    remainingBufferBytes_uo = rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo - rxSecuredPduCtx_pst->bufferPosition_uo;
                }
                else
                {
                    remainingBufferBytes_uo = rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo -
                                              rxSecuredPduCtx_pst->cryptographicPduBufferPosition_uo;
                }

                if (0u == info->SduLength)
                {
                    /* Return current amount of buffer size available to */
                    *bufferSizePtr = remainingBufferBytes_uo;
                    result_en = BUFREQ_OK;
                }

                /* Check if the data pointer is valid and the data fits into our buffer. */
                if ((NULL_PTR != info->SduDataPtr)
                    && (info->SduLength > 0u)
                    && (info->SduLength <= remainingBufferBytes_uo))
                {
                    if((SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8) || (SECOC_SECURED_PDU == pduType_u8))
                    {
                        /* TRACE[SWS_SecOC_00083]: Copy the frame data into our internal buffer */
                        SecOC_Prv_MemCopy(
                              /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                              &rxSecuredPduCtx_pst->pduConfig_pst->pduBufferIn_pu8[rxSecuredPduCtx_pst->bufferPosition_uo],
                              /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                              info->SduDataPtr,
                              info->SduLength );

                        if((rxSecuredPduCtx_pst->bufferPosition_uo < rxSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8)
                            && ((rxSecuredPduCtx_pst->bufferPosition_uo + info->SduLength) >= rxSecuredPduCtx_pst->pduConfig_pst->securedHeaderLength_u8))
                        {
                            /* The authentic pdu length from Secured header was not checked in SecOC_StartOfReception. */
                            checkSecuredHeaderResult_en = SecOC_Prv_RxCheckAndSetAuthPduLengthFromSecuredHeader(rxSecuredPduCtx_pst, rxSecuredPduCtx_pst->pduConfig_pst->pduBufferIn_pu8);
                        }

                        /* TRACE[SWS_SecOC_00314]: check if secured area is valid for secured PDU or authentic PDU of collection */
                        /* NULL_PTR check for optional secured area values needed */
                        if(NULL_PTR != rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.value_pacu32)
                        {
                            idx_cuo = rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.idx_cuo;
                            securedRxPduOffset_u32 = (*rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduOffset_cst.value_pacu32)[idx_cuo];
                        }
                        if(NULL_PTR != rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)
                        {
                            idx_cuo = rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.idx_cuo;
                            securedRxPduLength_u32 = (*rxSecuredPduCtx_pst->pduConfig_pst->securedRxPduLength_cst.value_pacu32)[idx_cuo];
                        }
                        if (    (securedRxPduLength_u32 > 0u)
                             && (   ((  securedRxPduOffset_u32 + securedRxPduLength_u32) * 8u)
                                  > rxSecuredPduCtx_pst->actualAuthenticPduLengthInBits_uo)
                           )
                        {
                            /* discard PDU with invalid secured area */
                            result_en = BUFREQ_E_NOT_OK;
                            checkSecuredHeaderResult_en = E_NOT_OK;
                            /* Reset the state of pdu and clear buffers*/
                            rxSecuredPduCtx_pst->status_u8 = SECOC_RX_STATE_SECURED_IDLE_E;
                            /* reset same buffer because it is already reserved before check of PDU */
                            SecOC_Prv_resetSameBufferRxRefInUse(rxSecuredPduCtx_pst);
                            /* MR12 DIR 1.1 VIOLATION: input parameters are declared as (void*) for generic implementation */
                            SecOC_Prv_MemZero((void*)rxSecuredPduCtx_pst->pduConfig_pst->pduBufferIn_pu8,(uint32)rxSecuredPduCtx_pst->pduConfig_pst->pduLength_uo);
                            /* TRACE[SWS_SecOC_Rb_00314]: Call DET to notify that the received secured/authentic collection PDU
                               is discarded because the PDU length is smaller than secured area length. */
                            /* TRACE[SWS_SecOC_Rb_00314]|Det disabled */
                        }
                    }
                    else
                    {
                        /* TRACE[SWS_SecOC_00083]: Copy the frame data into our internal buffer */
                        SecOC_Prv_MemCopy(
                              /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                              &rxSecuredPduCtx_pst->pduConfig_pst->cryptographicPduBufferIn_pu8[rxSecuredPduCtx_pst->cryptographicPduBufferPosition_uo],
                              /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                              info->SduDataPtr,
                              info->SduLength );
                    }
                    /* If length check is E_OK then we will update the output data.
                       Obs: checkSecuredHeaderResult_en is updated only in case of a dynamic pdu, otherwise is E_OK. */
                    if(E_OK == checkSecuredHeaderResult_en)
                    {
                        /* Remaining buffer bytes reduced by amount of bytes copied into buffer. */
                        remainingBufferBytes_uo = remainingBufferBytes_uo - info->SduLength;

                        /* Increment buffer position by current sdu length. */
                        if((SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8) || (SECOC_SECURED_PDU == pduType_u8))
                        {
                            rxSecuredPduCtx_pst->bufferPosition_uo += info->SduLength;
                        }
                        else
                        {
                            rxSecuredPduCtx_pst->cryptographicPduBufferPosition_uo += info->SduLength;
                        }

                        /* Report remaining buffer size back to caller. */
                        *bufferSizePtr = remainingBufferBytes_uo;
                        result_en = BUFREQ_OK;
                    }
                }
                SecOC_Prv_RxSecuredContextBufferRelease(&rxSecuredPduCtx_pst);
            }
        }
    }


    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_TpRxIndication
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
/* HIS METRIC LEVEL VIOLATION in SecOC_TpRxIndication: levels required because of checks according to Autosar */
void SecOC_TpRxIndication( PduIdType id, Std_ReturnType result )
{
    /* TRACE[SWS_SecOC_00125]: Implementation of SecOC_TpRxIndication */
    /* (SRS_BSW_00323, SRS_BSW_00359, SRS_BSW_00449, SRS_SecOC_00012) */
    SecOC_Prv_TpRxIndication(id, result);
}

/**
 ***********************************************************************************************************************
 * SecOC_TriggerTransmit
 *
 * \brief Within this API, the upper layer module (called module) shall check whether the available data fits into the
 *        buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the buffer provided by
 *        PduInfoPtr->SduDataPtr and update the length of the actual copied data in PduInfoPtr->SduLength. If not, it
 *        returns E_NOT_OK without changing PduInfoPtr.
 *
 * \param[in]    PduIdType    TxPduId     ID of the SDU that is requested to be transmitted.
 *
 * \param[inout] PduInfoType* PduInfoPtr  Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be
 *                                        copied, and the available buffer size in SduLength. On return, the service
 *                                        will indicate the length of the copied SDU data in SduLength.
 *
 * \return Std_Return_Type:
 *         - E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
 *         - E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may contain
 *                     a NULL pointer or point to invalid data.
 **********************************************************************************************************************
 */
/* HIS METRIC LEVEL VIOLATION in SecOC_TriggerTransmit: levels required because of checks according to Autosar */
Std_ReturnType SecOC_TriggerTransmit( PduIdType TxPduId, PduInfoType* PduInfoPtr )
{

    /* TRACE[SWS_SecOC_00127]: Implementation of SecOC_TriggerTransmit */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_BSW_00449, SRS_SecOC_00012) */
    SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst;
    PduLengthType dataLength_uo = 0u;
    Std_ReturnType result_en = E_NOT_OK;
    uint8 pduType_u8 = 0;

    /* check state of SecOC */
    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    /* check input parameters */
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr) || (PduInfoPtr->SduLength == 0u))
    {
        /* TRACE[]|Det disabled */
    }
    /* check that the pduId is inside our mapping table */
    else if (TxPduId > SECOC_MAX_TX_PDU_ID)
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        if (SECOC_TX_STATE_SENT_E == SecOC_Prv_TxSecuredContextBufferGetState(SecOC_Prv_getAuthenticPduId(TxPduId)))
        {
            txPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(SecOC_Prv_getAuthenticPduId(TxPduId));

            if(NULL_PTR != txPduCtx_pst)
            {
                pduType_u8 = SecOC_Prv_TxGetPduType(TxPduId);

                /* Check if the TxPduId is a cryptographic pduId */
                if (   (SECOC_COLLECTION_CRYPTOGRAPHIC_PDU == pduType_u8)
                    && (PduInfoPtr->SduLength >= txPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo))
                {
                    SecOC_Prv_MemCopy(
                        /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                        PduInfoPtr->SduDataPtr,
                        /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                        txPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8,
                        txPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo);

                    PduInfoPtr->SduLength = txPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo;
                    /* MR12 RULE 18.6 VIOLATION: QAC throwing false positive warning */
                    PduInfoPtr->MetaDataPtr = txPduCtx_pst->MetaDataPtr_pu8;
                    result_en = E_OK;
                }
                /* Check if the TxPduId is a collection authentic or secured pduId */
                else if ((SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8) || (SECOC_SECURED_PDU == pduType_u8))
                {
                   if (SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8)
                   {
                       /* actualPduLength_uo for collection authentic PDU is calculated in SecOC_Prv_createPduCollection */
                       dataLength_uo = txPduCtx_pst->actualPduLength_uo;
                   }
                   else
                   {
                       /* TRACE[SWS_SecOC_00269]:
                          For secured PDU always the configured length is used because unused area is filled with
                          default pattern */
                       dataLength_uo = txPduCtx_pst->pduConfig_pst->pduLength_uo;
                   }
                   if (PduInfoPtr->SduLength >= dataLength_uo)
                   {
                      SecOC_Prv_MemCopy(
                          /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                          PduInfoPtr->SduDataPtr,
                          /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                          txPduCtx_pst->pduConfig_pst->pduBufferOut_pu8,
                          dataLength_uo);

                      PduInfoPtr->SduLength = dataLength_uo;
                      /* MR12 RULE 18.6 VIOLATION: QAC throwing false positive warning */
                      PduInfoPtr->MetaDataPtr = txPduCtx_pst->MetaDataPtr_pu8;
                      result_en = E_OK;
                   }
                }
                else
                {
                    /* MR12 RULE 16.4 VIOLATION: no action is necessary */
                }
                SecOC_Prv_TxSecuredContextBufferRelease(&txPduCtx_pst);
            }
        }
        else
        {
            /* wrong state - do nothing */
        }
    }

    return(result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_CopyTxData
 * \brief This function is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this function
 *        provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this case the function
 *        restarts to copy the data beginning at the offset from the current position indicated by retry->TxTpDataCnt.
 *        The size of the remaining data is written to the position indicated by availableDataPtr.
 *
 * \param[in]  PduIdType      id                Identification of the transmitted I-PDU.
 *
 * \param[in]  PduInfoType*   info              Provides the destination buffer (SduDataPtr) and the number of bytes to
 *                                              be copied (SduLength). If not enough transmit data is available, no data
 *                                              is copied by the upper layer module and BUFREQ_E_BUSY is returned. The
 *                                              lower layer module may retry the call. An SduLength of 0 can be used to
 *                                              indicate state changes in the retry parameter or to query the current
 *                                              amount of available data in the upper layer module. In this case, the
 *                                              SduDataPtr may be a NULL_PTR.
 *
 * \param[in]  RetryInfoType* retry             This parameter is used to acknowledge transmitted data or to retransmit
 *                                              data after transmission problems.
 *                                              If the retry parameter is a NULL_PTR, it indicates that the transmit
 *                                              data can be removed from the buffer immediately after it has been
 *                                              copied. Otherwise, the retry parameter must point to a valid
 *                                              RetryInfoType element.
 *
 *                                              If TpDataState indicates TP_CONFPENDING, the previously copied data must
 *                                              remain in the TP buffer to be available for error recovery.
 *                                              TP_DATACONF indicates that all data that has been copied before this
 *                                              call is confirmed and can be removed from the TP buffer. Data copied by
 *                                              this API call is excluded and will be confirmed later.
 *                                              TP_DATARETRY indicates that this API call shall copy previously copied
 *                                              data in order to recover from an error. In this case TxTpDataCnt
 *                                              specifies the offset in bytes from the current data copy position.
 *
 * \param[out] PduLengthType* availableDataPtr  Indicates the remaining number of bytes that are available in the upper
 *                                              layer module's Tx buffer. availableDataPtr can be used by TP modules
 *                                              that support dynamic payload lengths (e.g. FrIsoTp) to determine the
 *                                              size of the following CFs.
 *
 * \return BufReq_ReturnType:
 *         - BUFREQ_OK: Data has been copied to the transmit buffer completely as requested.
 *         - BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount of Tx data is not available. The
 *                          lower layer module may retry this call later on. No data has been copied.
 *         - BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
 **********************************************************************************************************************/
/* MR12 RULE 8.13 VIOLATION: retry and availableDataPtr can not be const because this interface is defined by AUTOSAR */
/* HIS METRIC LEVEL VIOLATION in SecOC_CopyTxData: levels required because of checks according to Autosar */
BufReq_ReturnType SecOC_CopyTxData(PduIdType id, const PduInfoType* info, RetryInfoType* retry,
                                    PduLengthType* availableDataPtr )
{
    /* TRACE[SWS_SecOC_00072], TRACE[SWS_SecOC_00073], TRACE[SWS_SecOC_00129]: Implementation of SecOC_CopyTxData */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_SecOC_00012) */
    SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst;
    PduLengthType position_uo;
    PduLengthType dataLength_uo = 0u;
    PduIdType secOCAuthenticPduId_uo;
    BufReq_ReturnType result_en = BUFREQ_E_NOT_OK;
    SecOC_Prv_TxSecuredPduState_tu8 ctxBufferState_u8;
    /* BSWEXT-489 */
    boolean retryCntValid_b = TRUE;
    uint8 pduType_u8 = 0;

    if (SECOC_INIT != SecOC_Prv_getState())
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else if ((NULL_PTR == info) || (NULL_PTR == availableDataPtr))
    {
        /* TRACE[]|Det disabled */
    }
    else if (id > SECOC_MAX_TX_PDU_ID)
    {
        /* TRACE[SWS_SecOC_00101]|Det disabled */
    }
    else
    {
        /* Translate secOC secured / collection authentic / cryptographic PDU ID to secOC authentic PDU ID */
        secOCAuthenticPduId_uo = SecOC_Prv_getAuthenticPduId(id);
        ctxBufferState_u8 = SecOC_Prv_TxSecuredContextBufferGetState(secOCAuthenticPduId_uo);

        /* Only start processing if the buffer is in send or copx_tx state */
        if (SECOC_TX_STATE_SENT_E == ctxBufferState_u8)
        {
            pduType_u8 = SecOC_Prv_TxGetPduType(id);

            /* Get the context buffer for the Tx PDU with the authentic PDU Id as the index */
            txPduCtx_pst = SecOC_Prv_TxSecuredContextBufferAllocate(secOCAuthenticPduId_uo);
            if (NULL_PTR != txPduCtx_pst)
            {
                /* Check if we have a retry condition and need to adjust the buffer position */
                if ((NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState))
                {
                    /* Check if the id is a cryptographic pduId */
                    if (SECOC_COLLECTION_CRYPTOGRAPHIC_PDU == pduType_u8)
                    {
                        /* BSWEXT-489 */ /* [$DD_BSWCODE 40555] */
                        if (retry->TxTpDataCnt <= txPduCtx_pst->cryptographicPduBufferPosition_uo)
                        {
                            txPduCtx_pst->cryptographicPduBufferPosition_uo =
                                txPduCtx_pst->cryptographicPduBufferPosition_uo - retry->TxTpDataCnt;
                        }
                        else
                        {
                            retryCntValid_b = FALSE;
                        }
                        /* END BSWEXT-489 */
                    }
                    else
                    {
                        /* BSWEXT-489 */ /* [$DD_BSWCODE 40555] */
                        if (retry->TxTpDataCnt <= txPduCtx_pst->bufferPosition_uo)
                        {
                            txPduCtx_pst->bufferPosition_uo = txPduCtx_pst->bufferPosition_uo - retry->TxTpDataCnt;
                        }
                        else
                        {
                            retryCntValid_b = FALSE;
                        }
                        /* END BSWEXT-489 */
                    }
                }

                /* Check if the data pointer is valid and the data fits into our buffer. */
                /* BSWEXT-489 */ /* [$DD_BSWCODE 40555] */
                if ((NULL_PTR != info->SduDataPtr) && (FALSE != retryCntValid_b))
                {
                    /* Check if the id is a cryptographic pduId */
                    if (SECOC_COLLECTION_CRYPTOGRAPHIC_PDU == pduType_u8)
                    {
                        position_uo = txPduCtx_pst->cryptographicPduBufferPosition_uo;
                        /* BSWEXT-489 */ /* [$DD_BSWCODE 40555] */
                        if (   (position_uo <= txPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo)
                            && (info->SduLength <= (txPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo - position_uo)))
                        /* END BSWEXT-489 */
                        {
                            SecOC_Prv_MemCopy(
                                    /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                    info->SduDataPtr,
                                    /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                    &txPduCtx_pst->pduConfig_pst->cryptographicPduBufferOut_pu8[position_uo],
                                    info->SduLength );

                            position_uo = position_uo + info->SduLength;
                            txPduCtx_pst->cryptographicPduBufferPosition_uo = position_uo;
                            *availableDataPtr = txPduCtx_pst->pduConfig_pst->cryptographicPduLength_uo - position_uo;
                            result_en = BUFREQ_OK;
                        }
                    }
                    /*Check if the id is a collection authentic or secured pduId. The branch covers the case of dynamic
                      and static length of Pdu (collection authentic or secured) as the variable dataLength_uo holds
                      the length to be copied. */
                    else
                    {
                        position_uo = txPduCtx_pst->bufferPosition_uo;
                        if (SECOC_COLLECTION_AUTHENTIC_PDU == pduType_u8)
                        {
                            /* actualPduLength_uo for collection authentic PDU is calculated in SecOC_Prv_createPduCollection */
                            dataLength_uo = txPduCtx_pst->actualPduLength_uo;
                        }
                        else
                        {
                            /* TRACE[SWS_SecOC_00269]:
                               For secured PDU always the configured length is used because unused area is filled with
                               default pattern */
                            dataLength_uo = txPduCtx_pst->pduConfig_pst->pduLength_uo;
                        }

                        /* BSWEXT-489 */ /* [$DD_BSWCODE 40555] */
                        if (    (position_uo <= dataLength_uo)
                             && (info->SduLength <= (dataLength_uo - position_uo)))
                        /* END BSWEXT-489 */
                        {
                            SecOC_Prv_MemCopy(
                                    /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                    info->SduDataPtr,
                                    /* MR12 DIR 1.1 VIOLATION: this pointer is modified in SecOC_Prv_MemCopy */
                                    &txPduCtx_pst->pduConfig_pst->pduBufferOut_pu8[position_uo],
                                    info->SduLength );

                            position_uo = position_uo + info->SduLength;
                            txPduCtx_pst->bufferPosition_uo = position_uo;
                            *availableDataPtr = dataLength_uo - position_uo;
                            result_en = BUFREQ_OK;
                        }
                    }
                }

                /* NULL_PTR indicates that the transmit data can be removed from the
                 * buffer immediately after it has been copied.
                 */
                if (NULL_PTR == retry)
                {
                    SecOC_Prv_clearTxSecuredPduContext(txPduCtx_pst);
                }
                else
                {
                    txPduCtx_pst->status_u8 = SECOC_TX_STATE_SENT_E;
                }
                SecOC_Prv_TxSecuredContextBufferRelease(&txPduCtx_pst);
            }
        }
    }

    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_IfTransmit
 *
 * \brief  The function is called from PduR to trigger the transmission of a authentic Pdu.
 *
 * \param[in]    PduIdType           TxPduId      Identifier of the PDU to be transmitted
 *
 * \param[in]    const PduInfoType*  PduInfoPtr   Length of and pointer to the PDU data and pointer to MetaData.
 *
 * \return       Result of the function call:
 *                              - E_NOT_OK: an error occurred, request failed
 *                              - E_OK    : request successful
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_IfTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
    /* TRACE[SWS_SecOC_00112]: Implementation of SecOC_IfTransmit */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_BSW_00369, SRS_BSW_00449) */
    return SecOC_Prv_Transmit(TxPduId, PduInfoPtr, SECOC_SERVICE_ID_IFTRANSMIT);
}

/**
 ***********************************************************************************************************************
 * SecOC_TpTransmit
 *
 * \brief  The function is called from PduR to trigger the transmission of a authentic Pdu.
 *
 * \param[in]    PduIdType           TxPduId      Identifier of the PDU to be transmitted
 *
 * \param[in]    const PduInfoType*  PduInfoPtr   Length of and pointer to the PDU data and pointer to MetaData.
 *
 * \return       Result of the function call:
 *                              - E_NOT_OK: an error occurred, request failed
 *                              - E_OK    : request successful
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_TpTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
    /* TRACE[SWS_SecOC_91008]: Implementation of SecOC_TpTransmit */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_BSW_00369, SRS_BSW_00449) */
    return SecOC_Prv_Transmit(TxPduId, PduInfoPtr, SECOC_SERVICE_ID_TPTRANSMIT);
}

/**
 ***********************************************************************************************************************
 * SecOC_TxConfirmation
 *
 * \brief  The lower layer communication interface module confirms the transmission of a PDU, or the failure to transmit
 *         a PDU.
 *
 * \param[in]    TxPduId       ID of the PDU that has been transmitted.
 * \param[in]    result        Result of the transmission of the PDU.
 ***********************************************************************************************************************
*/
void SecOC_TxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    /* TRACE[SWS_SecOC_00126]: Implementation of SecOC_TxConfirmation */
    /* (SRS_BSW_00323, SRS_BSW_00359, SRS_SecOC_00012) */
    SecOC_Prv_TxConfirmation(TxPduId, result, SECOC_SERVICE_ID_TX_CONFIRMATION);
}

/**
 ***********************************************************************************************************************
 * SecOC_TpTxConfirmation
 *
 * \brief This function is called after the I-PDU has been transmitted on its network, the result indicates whether the
 *        transmission was successful or not.
 *
 * \param[in] PduIdType             id    Identification of the transmitted I-PDU.
 *
 * \param[in] Std_ReturnType    result    Result of the transmission of the I-PDU.
 *
 * \return void
 ***********************************************************************************************************************
 */
 void SecOC_TpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    /* TRACE[SWS_SecOC_00152]: Implementation of SecOC_TxConfirmation */
    /* (SRS_BSW_00323, SRS_BSW_00359, SRS_SecOC_00012) */
    SecOC_Prv_TxConfirmation(id, result, SECOC_SERVICE_ID_TP_TX_CONFIRMATION);
}

/**
 ***********************************************************************************************************************
 * SecOC_IfCancelTransmit
 *
 * \brief  Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module.
 *
 * \param[in]   PduIdType            TxPduId    identifier of the authentic Pdu
 *
 * \return      Std_ReturnType     - E_OK    : request successfull
 *                                 - E_NOT_OK: an error occurred, request failed
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_IfCancelTransmit(PduIdType TxPduId)
{
    /* TRACE[SWS_SecOC_00113]: Implementation of SecOC_IfCancelTransmit */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_BSW_00449, SRS_SecOC_00012) */
    return SecOC_Prv_CancelTransmit(TxPduId, SECOC_SERVICE_ID_IF_CANCEL_TRANSMIT);
}
/**
 ***********************************************************************************************************************
 * SecOC_TpCancelTransmit
 *
 * \brief  Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module.
 *
 * \param[in]    PduIdType            TxPduId        identifier of the Pdu
 *
 * \return       Std_ReturnType     - E_OK    : request successfull
 *                                  - E_NOT_OK: an error occurred, request failed
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_TpCancelTransmit(PduIdType TxPduId)
{
    /* TRACE[SWS_SecOC_91009]: Implementation of SecOC_TpCancelTransmit */
    /* (SRS_BSW_00323, SRS_BSW_00357, SRS_BSW_00449, SRS_SecOC_00012) */
    return SecOC_Prv_CancelTransmit(TxPduId, SECOC_SERVICE_ID_TP_CANCEL_TRANSMIT);
}
#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"
