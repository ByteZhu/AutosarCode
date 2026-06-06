#ifndef PDUR_SECOC_UP_H
#define PDUR_SECOC_UP_H

#include "PduR_Prv.h"

/**
 * @ingroup PDUR_SECOC_H
 *
 * To ensure that the function declarations in this header are located in the code section.
 */
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if defined(PDUR_CONFIG_SINGLE_IFTX_LO)
/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC Transmit ID
 */
#define PduR_iSecOCTransmitID(id)           (id)                                   

/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC Transmit function ID
 */
#define PduR_iSecOCTransmitFunc(id)           (PDUR_CONFIG_SINGLE_IFTX_LO(Transmit)) 

#else
/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC Transmit ID
 */
#define PduR_iSecOCTransmitID(id)           (PDUR_SECOC_TX_BASE[(id)].loId)          

/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC Transmit function ID
 */
#define PduR_iSecOCTransmitFunc(id)           (PduR_loTransmitTable[(PDUR_SECOC_TX_BASE[(id)].loTransmitID)].PduR_loTransmitFunc)

#endif /* PDUR_CONFIG_SINGLE_IFTX_LO */

/**
 * @ingroup PDUR_SECOC_H
 *      This function is called by the SECOC to request a transmission. \n
 * \n
 * @param in        id: ID of SECOC I-PDU to be transmitted. \n
 *                  const PduInfoType * ptr: Pointer to a structure with I-PDU related data that shall be transmitted:
 *                                         data length and pointer to I-SDU buffer. \n
 * \n
 * @return          E_OK: Transmit request has been accepted.\n
 *                  E_NOT_OK: Transmit request has not been accepted.\n
 */
extern Std_ReturnType PduR_dSecOCTransmit(PduIdType id, const PduInfoType *ptr);

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)   
/**
 * @ingroup PDUR_SECOC_H
 *
 * SECOC Transmit for PduR DEV Error Detect
 */
 #define PduR_rSecOCTransmit(id, ptr)        PduR_dSecOCTransmit((id), (ptr))
#else

/**
 * @ingroup PDUR_SECOC_H
 *
 * SECOC Transmit for PduR DEV Error Detect
 */
#define PduR_rSecOCTransmit(id, ptr)        PduR_iSecOCTransmitFunc(id)(PduR_iSecOCTransmitID(id), (ptr))
#endif /* PDUR_DEV_ERROR_DETECT */

/*------------------------------------------------------------------------------- Multicast mapping ------------------------------------------------ */

/**
 * @ingroup PDUR_SECOC_H
 *
 *  This function is called by AUTOSAR SECOC to request a transmission for multicast mapping. \n
 *
 *  @param  In:      id - multicast ID to be transmitted. \n
 *  @param  In:      info - Pointer to a structure with PDU related data that shall be transmitted
 *                           data length and pointer to buffer \n
 *
 *  @return          E_OK: if the request is accepted \n
 *                   E_NOT_OK: if the request is not accepted  just for testing \n
 */
extern Std_ReturnType PduR_MF_SecOC_Transmit_Func(PduIdType id,
		const PduInfoType *info);

/*-------------------------------------------------------------------------------End of Multicast mapping func------------------------------------------------ */

#define PDUR_IH_SecOC_Transmit_Func    PDUR_DET_API(PduR_invId_UpTransmit)
/**
 * @ingroup PDUR_SECOC_H
 *
 * Invalid PDU ID handlers for SECOC Rx Indication
 */
#define PDUR_IH_SecOCRx_RxIndication_Func   PDUR_DET_API(PduR_invId_IfRxIndication)

/**
 * @ingroup PDUR_SECOC_H
 *
 * Invalid PDU ID handlers for SECOC Tx Confirmation
 */
#define PDUR_IH_SecOCTx_TxConfirmation_Func PDUR_DET_API(PduR_invId_IfTxConfirmation)

/**
 * @ingroup PDUR_SECOC_H
 *
 * Invalid PDU ID handlers for SECOC Tx Confirmation
 */
#define PDUR_IH_SecOCTx_TriggerTransmit_Func  PDUR_DET_API(PduR_invId_IfTriggerTransmit)

/**
 * @ingroup PDUR_SECOC_H
 *
 *  Function to be invoked DET enable for PduR_dSecOCTxConfirmation. This function is called by the FlexRay Interface after the PDU has been transmitted on
 *  the FlexRay network. \n
 *
 *  @param  In:      id - ID of SECOC I-PDU to be transmitted. \n
 *
 *  @return None \n
 */
extern void PduR_dSecOCTxConfirmation(PduIdType id, Std_ReturnType result);

/**
 * @ingroup PDUR_SECOC_H
 *
 *  This function is called by the SECOC after the PDU has been received. \n
 *
 *  @param  In:      id - ID of SECOC I-PDU that has been received. \n
 *  @param  Out:     ptr - Pointer to SECOC SDU (buffer of received payload) \n
 *
 *  @return None \n
 */
extern void PduR_dSecOCRxIndication(PduIdType id, const PduInfoType *ptr);

/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC RxIndication Id
 */
#define PduR_iSecOCRxIndicationID(id)        (PDUR_SECOC_RXIND_BASE[(id)].upId)              

/**
 * @ingroup PDUR_SECOC_H
 *
 * SECOC RxIndication function Id
 */
#define PduR_iSecOCRxIndicationFunc(id)      (PduR_upIfRxIndicationTable[(PDUR_SECOC_RXIND_BASE[(id)].upRxIndicationID)].PduR_upIfRxIndicationFunc)

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)   
/**
 * @ingroup PDUR_SECOC_H
 *
 * SECOC RxConfirmation Indication
 */
 #define PduR_rSecOCRxIndication(id, ptr)     PduR_dSecOCRxIndication((id), (ptr))
#else
/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC RxConfirmation Indication
 */
#define PduR_rSecOCRxIndication(id, ptr)     PduR_iSecOCRxIndicationFunc(id)(PduR_iSecOCRxIndicationID(id), (ptr))
#endif /* PDUR_DEV_ERROR_DETECT */

/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC TxConfirmation Id
 */
#define PduR_iSecOCTxConfirmationID(id)      (PDUR_SECOC_TXCONF_BASE[(id)].upId)                
/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC TxConfirmation Function Id
 */
#define PduR_iSecOCTxConfirmationFunc(id)    (PduR_upIfTxConfirmationTable[(PDUR_SECOC_TXCONF_BASE[(id)].upTxConfirmationID)].PduR_upIfTxConfirmationFunc)

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)   
/**
 * @ingroup PDUR_SECOC_H
 *
 *  SecOC TxConfirmation Id
 */
#define PduR_rSecOCTxConfirmation(id,result)        PduR_dSecOCTxConfirmation(id,result)
 
#else
/**
 * @ingroup PDUR_SECOC_H
 *
 * SecOC TxConfirmation Function Id
 */
#define PduR_rSecOCTxConfirmation(id,result)        PduR_iSecOCTxConfirmationFunc(id)(PduR_iSecOCTxConfirmationID(id),(result))
#endif /* PDUR_DEV_ERROR_DETECT */

#if defined(PDUR_CONFIG_SINGLE_IFTX_UP)
#define PduR_iSecOCTriggerTransmitID(id)     (id)
#define PduR_iSecOCTriggerTransmitFunc(id)     (PDUR_CONFIG_SINGLE_IFTX_UP(TriggerTransmit))
#else
#define PduR_iSecOCTriggerTransmitID(id)     (PDUR_SECOC_TXCONF_BASE[(id)].upId)
#define PduR_iSecOCTriggerTransmitFunc(id)   (PduR_upIfTriggerTxTable[(PDUR_SECOC_TXCONF_BASE[(id)].upTriggerTxID)].PduR_upIfTriggerTxFunc)

#endif /* PDUR_CONFIG_SINGLE_IFTX_UP */

extern Std_ReturnType PduR_dSecOCTriggerTransmit(PduIdType id,
		PduInfoType *ptr);

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)
#define PduR_aSecOCTriggerTransmit(id, ptr)  PduR_dSecOCTriggerTransmit((id), (ptr))
#else
#define PduR_aSecOCTriggerTransmit(id, ptr)  PduR_iSecOCTriggerTransmitFunc(id)(PduR_iSecOCTriggerTransmitID(id), (ptr))
#endif /* PDUR_DEV_ERROR_DETECT */

#define PduR_rSecOCTriggerTransmit(id, ptr)   PduR_aSecOCTriggerTransmit((id), (ptr))

/* ------------------------------------------------------------------- */
#if defined(PDUR_CONFIG_SINGLE_TPRX)
#define PduR_iSecOCTpStartOfReception(id)        (id)
#define PduR_iSecOCTpStartOfReceptionFunc(id)        (PDUR_CONFIG_SINGLE_TPRX(StartOfReception))
#else
#define PduR_iSecOCTpStartOfReceptionID(id)        (PDUR_SECOCTP_RXIND_BASE[(id)].upId)
#define PduR_iSecOCTpStartOfReceptionFunc(id)      (PduR_upTpStartOfReceptionTable[(PDUR_SECOCTP_RXIND_BASE[(id)].upStartOfReceptionID)].PduR_upTpStartOfReceptionFunc)

#endif /* PDUR_CONFIG_SINGLE_TPRX */

extern BufReq_ReturnType PduR_dSecOCTpStartOfReception(PduIdType id,
		const PduInfoType *info, PduLengthType TpSduLength,
		PduLengthType *bufferSizePtr);

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)
#define PduR_aSecOCTpStartOfReception(id,info,TpSduLength,bufSizePtr)   PduR_dSecOCTpStartOfReception((id),(info),(TpSduLength),(bufSizePtr))
#else
#define PduR_aSecOCTpStartOfReception(id,info,TpSduLength,bufSizePtr)   PduR_iSecOCTpStartOfReceptionFunc(id)(PduR_iSecOCTpStartOfReceptionID(id),(info),(TpSduLength),(bufSizePtr))
#endif /* PDUR_DEV_ERROR_DETECT */

#define PduR_rSecOCTpStartOfReception(id,info,TpSduLength,bufSizePtr)   PduR_aSecOCTpStartOfReception((id),(info),(TpSduLength),(bufSizePtr))

/* ------------------------------------------------------------------- */
#if defined(PDUR_CONFIG_SINGLE_TPRX)
#define PduR_iSecOCTpCopyRxDataID(id)        (id)
#define PduR_iSecOCTpCopyRxDataFunc(id)        (PDUR_CONFIG_SINGLE_TPRX(CopyRxData))
#else
#define PduR_iSecOCTpCopyRxDataID(id)        (PDUR_SECOCTP_RXIND_BASE[(id)].upId)
#define PduR_iSecOCTpCopyRxDataFunc(id)      (PduR_upTpCopyRxDataTable[(PDUR_SECOCTP_RXIND_BASE[(id)].upProvideRxBufID)].PduR_upTpCopyRxDataFunc)

#endif /* PDUR_CONFIG_SINGLE_TPRX */

extern BufReq_ReturnType PduR_dSecOCTpCopyRxData(PduIdType id,
		const PduInfoType *info, PduLengthType *bufferSizePtr);

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)
#define PduR_aSecOCTpCopyRxData(id,info,bufSizePtr)   PduR_dSecOCTpCopyRxData((id),(info),(bufSizePtr))
#else
#define PduR_aSecOCTpCopyRxData(id,info,bufSizePtr)   PduR_iSecOCTpCopyRxDataFunc(id)(PduR_iSecOCTpCopyRxDataID(id),(info),(bufSizePtr))
#endif /* PDUR_DEV_ERROR_DETECT */

#define PduR_rSecOCTpCopyRxData(id,info,bufSizePtr)   PduR_aSecOCTpCopyRxData((id),(info),(bufSizePtr))

/* ------------------------------------------------------------------- */
#if defined(PDUR_CONFIG_SINGLE_TPRX)
#define PduR_iSecOCTpRxIndicationID(id)           (id)
#define PduR_iSecOCTpRxIndicationFunc(id)           (PDUR_CONFIG_SINGLE_TPRX(TpRxIndication))
#else
#define PduR_iSecOCTpRxIndicationID(id)           (PDUR_SECOCTP_RXIND_BASE[(id)].upId)

#define PduR_iSecOCTpRxIndicationFunc(id)         (PduR_upTpRxIndicationTable[(PDUR_SECOCTP_RXIND_BASE[(id)].upRxIndicationID)].PduR_upTpRxIndicationFunc)

#endif /* PDUR_CONFIG_SINGLE_TPRX */

extern void PduR_dSecOCTpRxIndication(PduIdType id, Std_ReturnType std);

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)
#define PduR_aSecOCTpRxIndication(id,result)      PduR_dSecOCTpRxIndication((id), (result))
#else
#define PduR_aSecOCTpRxIndication(id,result)      PduR_iSecOCTpRxIndicationFunc(id)(PduR_iSecOCTpRxIndicationID(id), (result))
#endif /* PDUR_DEV_ERROR_DETECT */

#define PduR_rSecOCTpRxIndication(id,result)       PduR_aSecOCTpRxIndication((id),(result))

/* ------------------------------------------------------------------- */
#if defined(PDUR_CONFIG_SINGLE_TPTX_UP)
#define PduR_iSecOCTpCopyTxDataID(id)        (id)
#define PduR_iSecOCTpCopyTxDataFunc(id)        (PDUR_CONFIG_SINGLE_TPTX_UP(CopyTxData))
#else
#define PduR_iSecOCTpCopyTxDataID(id)        (PDUR_SECOCTP_TXCONF_BASE[(id)].upId)
#define PduR_iSecOCTpCopyTxDataFunc(id)      (PduR_upTpCopyTxDataTable[(PDUR_SECOCTP_TXCONF_BASE[(id)].upProvideTxBufID)].PduR_upTpCopyTxDataFunc)

#endif /* PDUR_CONFIG_SINGLE_TPTX_UP */

extern BufReq_ReturnType PduR_dSecOCTpCopyTxData(PduIdType id,
		const PduInfoType *info, const RetryInfoType *retry,
		PduLengthType *availableDataPtr);

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)
#define PduR_aSecOCTpCopyTxData(id,info,retry,avdataptr)    PduR_dSecOCTpCopyTxData((id),(info),(retry),(avdataptr))
#else
#define PduR_aSecOCTpCopyTxData(id,info,retry,avdataptr)    PduR_iSecOCTpCopyTxDataFunc(id)(PduR_iSecOCTpCopyTxDataID(id), (info),(retry),(avdataptr))
#endif /* PDUR_DEV_ERROR_DETECT */

#define PduR_rSecOCTpCopyTxData(id,info,retry,avdataptr)     PduR_aSecOCTpCopyTxData((id),(info),(retry),(avdataptr))

/* ------------------------------------------------------------------- */
#if defined(PDUR_CONFIG_SINGLE_TPTX_UP)
#define PduR_iSecOCTpTxConfirmationID(id)         (id)
#define PduR_iSecOCTpTxConfirmationFunc(id)         (PDUR_CONFIG_SINGLE_TPTX_UP(TpTxConfirmation))
#else
#define PduR_iSecOCTpTxConfirmationID(id)         (PDUR_SECOCTP_TXCONF_BASE[(id)].upId)

#define PduR_iSecOCTpTxConfirmationFunc(id)       (PduR_upTpTxConfirmationTable[(PDUR_SECOCTP_TXCONF_BASE[(id)].upTxConfirmationID)].PduR_upTpTxConfirmationFunc)

#endif /* PDUR_CONFIG_SINGLE_TPTX_UP */

extern void PduR_dSecOCTpTxConfirmation(PduIdType id, Std_ReturnType std);

#if defined(PDUR_DEV_ERROR_DETECT) && (PDUR_DEV_ERROR_DETECT != STD_OFF)
#define PduR_aSecOCTpTxConfirmation(id,result)    PduR_dSecOCTpTxConfirmation((id), (result))
#else
#define PduR_aSecOCTpTxConfirmation(id,result)    PduR_iSecOCTpTxConfirmationFunc(id)(PduR_iSecOCTpTxConfirmationID(id), (result))
#endif /* PDUR_DEV_ERROR_DETECT */

#define PduR_rSecOCTpTxConfirmation(id, result)    PduR_aSecOCTpTxConfirmation((id),(result))

/**
 * @ingroup PDUR_SECOC_H
 *
 * Anything after this point will not be placed in the code section.
 */
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif /* PDUR_SECOC_UP_H */

