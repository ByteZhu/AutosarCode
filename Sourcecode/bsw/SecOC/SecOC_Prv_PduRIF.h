/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef SECOC_PRV_PDURIF_H
#define SECOC_PRV_PDURIF_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "PduR.h"        /* interface to Pdu router, common part */
#include "PduR_SecOC.h"  /* interface to Pdu router, SecOC part */

/*
 **********************************************************************************************************************
 * Extern declarations for SecOC_PduRIf.c
 **********************************************************************************************************************
*/
extern PduIdType SecOC_Prv_getAuthenticPduId(PduIdType secPduId_uo);
extern void SecOC_Prv_TxConfirmation(PduIdType TxPduId, Std_ReturnType result, uint8 serviceId_u8);
extern Std_ReturnType SecOC_Prv_CancelTransmit(PduIdType id, uint8 serviceId_u8);
extern Std_ReturnType SecOC_Prv_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr, uint8 serviceId_u8);
extern Std_ReturnType SecOC_Prv_HandleAuthenticPdu(SecOC_Prv_TxAuthenticPduContext_tst *txAuthenticPduCtx_pst,
                                                   const PduInfoType* pduAuthInfo_pst);
extern void SecOC_Prv_HandlePdu(SecOC_Prv_RxSecuredPduContext_tst *rxPduCtx_pst, PduIdType RxPduId,
                         const PduInfoType* pduSecInfo_pcst, uint8 pduType_u8);
extern void SecOC_Prv_HandleAuthenticCollectionPdu(SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst, PduIdType RxPduId,
                                                   const PduInfoType* pduSecInfo_pcst, PduLengthType pduLength_uo);
extern void SecOC_Prv_HandleCryptographicCollectionPdu(SecOC_Prv_RxSecuredPduContext_tst *rxSecuredPduCtx_pst, PduIdType RxPduId,
                                                   const PduInfoType* pduSecInfo_pcst, PduLengthType pduLength_uo);

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
/**
 **********************************************************************************************************************
 * SecOC_Prv_AuthenticationFinished
 *
 * \brief  The function encloses the call of the function PduR_SecOCTransmit of the PduRouter to keep the SecOC main
 *         part independent from the PduR interface. The function PduR_SecOCTransmit is called to trigger the
 *         transmission of the secured I-PDU to the destination lower layer module.
 *
 * \param[in]    PduIdType           pduId_uo     identifier of the secured I-PDU
 *
 * \param[in]    const PduInfoType*  pduInfo_pcst  pointer to the payload of secured Pdu
 *
 * \return  Result of the function call:
 *                              - E_OK    : request successful
 *                              - E_NOT_OK: an error occurred, request failed
 **********************************************************************************************************************
*/
LOCAL_INLINE Std_ReturnType SecOC_Prv_AuthenticationFinished(PduIdType pduId_uo, const PduInfoType* pduInfo_pcst)
{
    Std_ReturnType result_en = E_NOT_OK;


    /* TRACE[SWS_SecOC_00061], TRACE[SWS_SecOC_00062], TRACE[SWS_SecOC_00067], TRACE[SWS_SecOC_00072]: */
    /* forward secured PDU to Pdu Router for further routing */
    result_en = PduR_SecOCTransmit(pduId_uo, pduInfo_pcst);


    return(result_en);
}


/**
 **********************************************************************************************************************
 * SecOC_Prv_VerificationFinished
 *
 * \brief  The function encloses the call of the function PduR_SecOCIf|TpRxIndication of the PduRouter to keep the SecOC
*          main part independent from the PduR interface.
*          In case of TpPduType Pdu the upper TP layer is triggered to copy the provided payload.
*          The function PduR_SecOCIf|TpRxIndication are called to indicates the reception of the authentic I-PDU.
 *
 * \param[in]  rxPduCtx_pst     Pointer to the RxPdu Context whose verification was finished successfully.
 *
 **********************************************************************************************************************
*/
LOCAL_INLINE void SecOC_Prv_VerificationFinished(const SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst)
{
    PduInfoType pduInfo_cst;
    uint16_least authenticPduLenInBytes_qu16 = 0u;
    PduLengthType remainAuthBytes_uo = 0u;
    PduLengthType upTpBufSize_uo = 0;
    PduLengthType cntChunk_uo = 0;
    boolean isLastChunk_b = FALSE;
    BufReq_ReturnType retVal_uo = BUFREQ_E_NOT_OK;
    Std_ReturnType result_uo = E_NOT_OK;


    authenticPduLenInBytes_qu16 = ((rxPduCtx_pst->actualAuthenticPduLengthInBits_uo + 7u) >> 3u);

    pduInfo_cst.SduDataPtr = rxPduCtx_pst->pduConfig_pst->authenticPduBufferOut_pu8;
    pduInfo_cst.SduLength = (PduLengthType)authenticPduLenInBytes_qu16;
    /* TRACE[SWS_SecOC_00212] */
    pduInfo_cst.MetaDataPtr = rxPduCtx_pst->metaData_pu8;

    /* TRACE[SWS_SecOC_00080], TRACE[SWS_SecOC_00086]: */
    /* forward authentic PDU to Pdu Router for further routing */
    if(FALSE == rxPduCtx_pst->pduConfig_pst->packedBits_stb.pduTpType_b)
    {
        PduR_SecOCIfRxIndication(rxPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo, &pduInfo_cst);
    }
    else
    {
        upTpBufSize_uo = rxPduCtx_pst->upTpBufSize_uo;
        if ((0 < upTpBufSize_uo) && (upTpBufSize_uo < authenticPduLenInBytes_qu16))
        {   /* provide chunks in loops*/
            pduInfo_cst.SduLength = upTpBufSize_uo;
            do
            {
                /* Start address of new chunk*/
                pduInfo_cst.SduDataPtr = &(rxPduCtx_pst->pduConfig_pst->authenticPduBufferOut_pu8[cntChunk_uo]);
                if(authenticPduLenInBytes_qu16  <= (cntChunk_uo + upTpBufSize_uo ))
                {   /* prepare length of last chunk */
                    pduInfo_cst.SduLength = (uint16)(authenticPduLenInBytes_qu16 - cntChunk_uo);
                    isLastChunk_b = TRUE;
                }
                retVal_uo = PduR_SecOCTpCopyRxData( rxPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo,
                                                   &pduInfo_cst,
                                                   &remainAuthBytes_uo);
                cntChunk_uo += upTpBufSize_uo;
            }while( (BUFREQ_OK == retVal_uo) && (!isLastChunk_b));
        }
        else
        {
            /* provide in one chunk, requested upper layer chunk size is bigger or equal to calc len */
            retVal_uo = PduR_SecOCTpCopyRxData( rxPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo,
                                                &pduInfo_cst,
                                                &remainAuthBytes_uo);
        }
        if(BUFREQ_OK == retVal_uo)
        {
            result_uo = E_OK;
        }
        PduR_SecOCTpRxIndication(rxPduCtx_pst->pduConfig_pst->pduRAuthenticPduId_uo, result_uo);
    }
}

#endif /* SECOC_PRV_PDURIF_H */
