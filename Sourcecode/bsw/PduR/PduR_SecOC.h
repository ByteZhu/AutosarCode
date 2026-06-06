#ifndef PDUR_SECOC_H
#define PDUR_SECOC_H

#include "PduR.h"

#include "SecOC.h"
#if(PDUR_ENABLE_INTER_MODULE_CHECKS)
#if (!defined(SECOC_AR_RELEASE_MAJOR_VERSION) || (SECOC_AR_RELEASE_MAJOR_VERSION != PDUR_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(SECOC_AR_RELEASE_MINOR_VERSION) || (SECOC_AR_RELEASE_MINOR_VERSION != PDUR_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif /* #if(PDUR_ENABLE_INTER_MODULE_CHECKS) */

/* Interface translation layers ------------------------------------- */
/**
 * @ingroup PDUR_SECOC_H
 *
 *This Macro gets generated through code generation which will be mapped to actual API
 */

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOC Copy Tx Data
 */
#define PduR_RF_SecOC_CopyTxData_Func              SecOC_CopyTxData

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOCTp Tx Confirmation
 */
#define PduR_RF_SecOC_TpTxConfirmation_Func        SecOC_TpTxConfirmation

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOC Start Of Reception
 */
#define PduR_RF_SecOC_StartOfReception_Func        SecOC_StartOfReception

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOC Copy Rx Data
 */
#define PduR_RF_SecOC_CopyRxData_Func              SecOC_CopyRxData

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOCTp Rx Indication
 */
#define PduR_RF_SecOC_TpRxIndication_Func          SecOC_TpRxIndication

/* PduR_SecOCStartOfReception */
extern BufReq_ReturnType PduR_SecOCTpStartOfReception(PduIdType id,
		const PduInfoType *info, PduLengthType TpSduLength,
		PduLengthType *bufferSizePtr);

/* PduR_SecOCCopyRxData  */
extern BufReq_ReturnType PduR_SecOCTpCopyRxData(PduIdType id,
		const PduInfoType *info, PduLengthType *bufferSizePtr);

/* PduR_SecOCTpRxIndication  */
extern void PduR_SecOCTpRxIndication(PduIdType id, Std_ReturnType std);

/* PduR_SecOCCopyTxData  */
extern BufReq_ReturnType PduR_SecOCTpCopyTxData(PduIdType id,
		const PduInfoType *info, const RetryInfoType *retry,
		PduLengthType *availableDataPtr);

/* PduR_SecOCTxConfirmation  */
extern void PduR_SecOCTpTxConfirmation(PduIdType id, Std_ReturnType std);

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SecOC RF transmit
 */
#define PduR_RF_SecOCTp_Transmit_Func          SecOC_TpTransmit

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOC Trigger Transmit
 */
#define PduR_RF_SecOC_TriggerTransmit_Func       SecOC_TriggerTransmit

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOC Rx Indication
 */
#define PduR_RF_SecOC_RxIndication_Func          SecOC_RxIndication

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SECOC Tx Confirmation
 */
#define PduR_RF_SecOC_TxConfirmation_Func        SecOC_TxConfirmation

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
/**
 * @ingroup PDUR_SECOC_H
 *
 *  This function is called by the SECOC to request a transmission.
 *\n
 * @param in          id -  ID of SECOC I-PDU to be transmitted.\n
 * @param out         const PduInfoType * ptr -   Pointer to a structure with I-PDU related data that shall be transmitted:
 *                                         data length and pointer to I-SDU buffer\n
 *\n
 * @return            E_OK: Transmit request has been accepted.\n
 *                    E_NOT_OK: Transmit request has not been accepted.\n
 */
extern Std_ReturnType PduR_SecOCTransmit(PduIdType id, const PduInfoType *ptr);

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SecOC RF transmit
 */
/**
 * @ingroup PDUR_SECOC_H
 *
 *  This function is called by the SecOC after the PDU has been received. \n
 *
 *  @param  In:      id - ID of SecOC I-PDU that has been received. \n
 *  @param  Out:     ptr - Pointer to SECOC SDU (buffer of received payload) \n
 *
 *  @return None \n
 */

/* PduR_SecOCIfRxIndication*/

extern void PduR_SecOCIfRxIndication(PduIdType id, const PduInfoType *ptr);

/* ------------------------------------------------------------------- */
/* PduR_SecOCIfTxConfirmation*/
/**
 * @ingroup PDUR_SECOC_H
 *
 *  This function is called by the FlexRay Interface after the PDU has been transmitted on the FlexRay network. \n
 *
 *  @param  In:      id - ID of SECOCIF I-PDU to be transmitted. \n
 *
 *  @return None \n
 */
extern void PduR_SecOCIfTxConfirmation(PduIdType id, Std_ReturnType result);

/**
 * @ingroup SECOC_H
 *
 *  This function is used for PDUR_SECOC buffer initialization to get SecOC Init Values\n
 *
 *  @param  In:      PdumTxPduId - Pdu ID type \n
 *  @param  In:      Ptr -  Pdu Info type for Buffer Init values\n
 *
 *  @return          E_OK: if the request is accepted \n
 *                   E_NOT_OK: if the request is not accepted \n
 */
/* PduR_SecOCTriggerTransmit  */
extern Std_ReturnType PduR_SecOCTriggerTransmit(PduIdType id, PduInfoType *ptr);

/**
 * @ingroup PDUR_SECOC_H
 *
 * Interface translation layers for SecOC RF transmit
 */
#define PduR_RF_SecOCIf_Transmit_Func          SecOC_IfTransmit

/**
 * @ingroup PDUR_SECOC_H
 *
 * Anything after this point will not be placed in the code section.
 */
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif /* PDUR_SECOC_H    */
