
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: PduR  / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

#include "PduR_Prv.h"
/* Appropriate header files are included to declare the prototypes
 */
#include "PduR_UpIf.h"

#if defined(PDUR_MULTICAST_TO_IF_SUPPORT) && (PDUR_MULTICAST_TO_IF_SUPPORT == 1)
#include "PduR_Mc.h"
#endif

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_ComTransmit
 *      This function is called by the COM to request a transmission.
 *
 * \param           PduIdType id: ID of COM I-PDU to be transmitted.
 *                  const PduInfoType * ptr: Pointer to a structure with I-PDU related data that shall be transmitted:
 *                                         data length and pointer to I-SDU buffer
 *
 * \retval          E_OK Transmit request has been accepted
 *                  E_NOT_OK Transmit request has not been accepted
 *
 * \seealso         PDUR202, PDUR206
 * \usedresources
 **************************************************************************************************
 */

Std_ReturnType PduR_ComTransmit(PduIdType id, const PduInfoType *ptr) {
	return ((Std_ReturnType) PduR_rComTransmit((id), (ptr)));
}

/* ------------------------------------------------------------------------ */
/* End section for code */
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_SecOCTransmit
 *      This function is called by the SECOC to request a transmission.
 *
 * \param           PduIdType id: ID of SECOC I-PDU to be transmitted.
 *                  const PduInfoType * ptr: Pointer to a structure with I-PDU related data that shall be transmitted:
 *                                         data length and pointer to I-SDU buffer
 *
 * \retval          E_OK Transmit request has been accepted
 *                  E_NOT_OK Transmit request has not been accepted
 *
 * \seealso         PDUR202, PDUR206
 * \usedresources
 **************************************************************************************************
 */

Std_ReturnType PduR_SecOCTransmit(PduIdType id, const PduInfoType *ptr) {
	return ((Std_ReturnType) PduR_rSecOCTransmit((id), (ptr)));
}

/* ------------------------------------------------------------------------ */
/* End section for code */
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_SecOCIfRxIndication
 *    This function is called by the SecOC (acting as a lower layer module) after the PDU has been received.
 *
 *
 * \param           PduIdType Id    : ID of SecOCIf I-PDU that has been received.
 *                  const uint8 *ptr: Pointer to SecOCIf SDU (buffer of received payload)
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void PduR_SecOCIfRxIndication(PduIdType id, const PduInfoType *ptr) {
	PduR_rSecOCRxIndication((id), (ptr));
}

/**
 **************************************************************************************************
 * PduR_SecOCTpStartOfReception - This service is called by the SecOC for requesting a new buffer (pointer to a
 *                             PduInfoStructure containing a pointer to a SDU buffer and the buffer length) for the SecOC
 *                             TP to fill in the received data..
 */

BufReq_ReturnType PduR_SecOCTpStartOfReception(PduIdType id,
		const PduInfoType *info, PduLengthType TpSduLength,
		PduLengthType *bufferSizePtr) {
	return (PduR_rSecOCTpStartOfReception((id), (info), (TpSduLength),
			(bufferSizePtr)));
}

/**
 **************************************************************************************************
 * PduR_SecOCTpCopyRxData - This service is called by the SecOC for requesting a new buffer (pointer to a
 *                             PduInfoStructure containing a pointer to a SDU buffer and the buffer length) for the SecOC
 *                             TP to fill in the received data..
 */

BufReq_ReturnType PduR_SecOCTpCopyRxData(PduIdType id, const PduInfoType *info,
		PduLengthType *bufferSizePtr) {
	return (PduR_rSecOCTpCopyRxData((id), (info), (bufferSizePtr)));
}

/**
 **************************************************************************************************
 * PduR_SecOCTpRxIndication - PDU Router SecOCRxIndication.
 */

void PduR_SecOCTpRxIndication(PduIdType id, Std_ReturnType std) {
	PduR_rSecOCTpRxIndication((id), (std));
}

/**
 **************************************************************************************************
 * PduR_SecOCTpCopyTxData - This function is called by the SecOC TP for requesting a transmit buffer.
 */

BufReq_ReturnType PduR_SecOCTpCopyTxData(PduIdType id, const PduInfoType *info,
		const RetryInfoType *retry, PduLengthType *availableDataPtr) {
	return (PduR_rSecOCTpCopyTxData((id), (info), (retry), (availableDataPtr)));

}

/**
 **************************************************************************************************
 * PduR_SecOCTpTxConfirmation
 *                  This function is called by the SecOC Transport Protocol:
 */

void PduR_SecOCTpTxConfirmation(PduIdType id, Std_ReturnType std) {
	PduR_rSecOCTpTxConfirmation((id), (std));
}

/**
 **************************************************************************************************
 * PduR_SecOCIfTxConfirmation - This function is called by the FlexRay Interface after the PDU has been transmitted on the
 *                           FlexRay network.
 *
 *
 * \param           PduIdType id -  ID of SecOCIf I-PDU to be transmitted.
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void PduR_SecOCIfTxConfirmation(PduIdType id, Std_ReturnType result) {
	PduR_rSecOCTxConfirmation(id, result);

}

/**
 **************************************************************************************************
 * PduR_SecOCTriggerTransmit - This function is called by the SecOC for sending out a  frame.
 * The trigger transmit is initiated by the  schedule. Whether this function is called or not is statically
 * configured for each PDU.
 *
 *
 * \param           PduIdType id -  ID of FlexRay L-PDU that is requested to be transmitted.
 *                                  Range: 0..(maximum number of L-PDU IDs which may be transmitted by FlexRay
 *                                             Interface) - 1
 *
 *                  uint8 *  ptr - Pointer to place inside the transmit buffer of the L-PDU where data shall be copied
 *                                 to.
 *
 * \retval          None
 * \seealso         PDUR199
 * \usedresources
 **************************************************************************************************
 */

Std_ReturnType PduR_SecOCTriggerTransmit(PduIdType id, PduInfoType *ptr) {
	return ((Std_ReturnType) PduR_rSecOCTriggerTransmit((id), (ptr)));
}

/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

