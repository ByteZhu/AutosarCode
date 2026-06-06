
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: PduR  / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

#include "PduR_Prv.h"

#include "PduR_Cfg.h"
/* Appropriate header files are included to declare the prototypes
 */
#include "PduR_UpIf.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
/**
 **************************************************************************************************
 * PduR_dComTransmit - Function to be invoked if DET is enable for PduR_ComTransmit
 *      This function is called by the Com to request a transmission.
 *
 * \param           PduIdType id: ID of Com I-PDU to be transmitted.
 *                  const PduInfoType * ptr: Pointer to a structure with I-PDU related data that shall be transmitted:
 *                                         data length and pointer to I-SDU buffer
 *
 * \retval          E_OK Transmit request has been accepted
 *                  E_NOT_OK Transmit request has not been accepted
 *
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
Std_ReturnType PduR_dComTransmit(PduIdType id, const PduInfoType *ptr) {

	/* Returns the state */
	PDUR_CHECK_STATE_RET(PDUR_MODULE_ID_COM, PDUR_SID_TX, E_NOT_OK)

	/* Checks for invalid pointer */
	PDUR_CHECK_PTR_RET(PDUR_MODULE_ID_COM, PDUR_SID_TX, ptr, E_NOT_OK)

	/* If the PDU identifier is not within the specified range then PDUR_E_PDU_ID_INVALID is reported via DET.*/
	if ((id >= PDUR_NR_VALID_COM_IDS)
			|| (PduR_iComTransmitFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_COM, PDUR_SID_TX,
				PDUR_E_PDU_ID_INVALID);
		return E_NOT_OK;
	}

	/*Calls the Lower layer TransmitFunction */

	return PduR_iComTransmitFunc(id)(PduR_iComTransmitID(id), ptr);

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
 * PduR_dSecOCTransmit - Function to be invoked if DET is enable for PduR_SecOCTransmit
 *      This function is called by the SecOC to request a transmission.
 *
 * \param           PduIdType id: ID of SecOC I-PDU to be transmitted.
 *                  const PduInfoType * ptr: Pointer to a structure with I-PDU related data that shall be transmitted:
 *                                         data length and pointer to I-SDU buffer
 *
 * \retval          E_OK Transmit request has been accepted
 *                  E_NOT_OK Transmit request has not been accepted
 *
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
Std_ReturnType PduR_dSecOCTransmit(PduIdType id, const PduInfoType *ptr) {

	/* Returns the state */
	PDUR_CHECK_STATE_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TX, E_NOT_OK)

	/* Checks for invalid pointer */
	PDUR_CHECK_PTR_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TX, ptr, E_NOT_OK)

	/* If the PDU identifier is not within the specified range then PDUR_E_PDU_ID_INVALID is reported via DET.*/
	if ((id >= PDUR_NR_VALID_SECOC_IDS)
			|| (PduR_iSecOCTransmitFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TX,
				PDUR_E_PDU_ID_INVALID);
		return E_NOT_OK;
	}

	/*Calls the Lower layer TransmitFunction */

	return PduR_iSecOCTransmitFunc(id)(PduR_iSecOCTransmitID(id), ptr);

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
 * PduR_dSecOCRxIndication - Function to be invoked if DET is enable for PduR_SecOCRxIndication
 *    This function is called by the SECOC (acting as a lower layer module) after the PDU has been received.
 *
 *
 * \param           PduIdType Id    : ID of SECOC I-PDU that has been received.
 *                  const uint8 *ptr: Pointer to SECOC SDU (buffer of received payload)
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void PduR_dSecOCRxIndication(PduIdType id, const PduInfoType *ptr) {

	PDUR_CHECK_STATE_VOID(PDUR_MODULE_ID_SECOC, PDUR_SID_RXIND)

	PDUR_CHECK_PTR_VOID(PDUR_MODULE_ID_SECOC, PDUR_SID_RXIND, ptr)

	if ((id >= PDUR_NR_VALID_SECOCIFRXTOUP_IDS)
			|| (PduR_iSecOCRxIndicationFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_RXIND,
				PDUR_E_PDU_ID_INVALID);
		return;
	}

	PduR_iSecOCRxIndicationFunc(id)(PduR_iSecOCRxIndicationID(id), ptr);
}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_dSecOCTriggerTransmit - Function to be invoked DET enable for PduR_SecOCTriggerTransmit
 * This function is called by the SecOC for sending out a  frame.
 * The trigger transmit is initiated by the schedule. Whether this function is called or not is statically
 * configured for each PDU.
 *
 *
 * \param           PduIdType id -  ID of LoIf module (supporting TT) L-PDU that is requested to be transmitted.
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
Std_ReturnType PduR_dSecOCTriggerTransmit(PduIdType id, PduInfoType *ptr) {

	PDUR_CHECK_STATE_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TRIGTX, E_OK)

	PDUR_CHECK_PTR_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TRIGTX, ptr, E_OK)

	/*Check for Invalid Id and null pointer */
	if ((id >= PDUR_NR_VALID_SECOCIFTXTOUP_IDS)
			|| (PduR_iSecOCTriggerTransmitFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TRIGTX,
				PDUR_E_PDU_ID_INVALID);
		return E_OK;
	}

	/*Call the upper layer trigger Transmit function */
	return ((Std_ReturnType) PduR_iSecOCTriggerTransmitFunc(id)(
			PduR_iSecOCTriggerTransmitID(id), ptr));
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
 * PduR_dSecOCTxConfirmation - Function to be invoked DET enable for PduR_SecOCTxConfirmation
 * This function is called by the FlexRay Interface after the PDU has been transmitted on
 *                             the FlexRay network.
 *
 *
 * \param           PduIdType id -  ID of SECOC I-PDU to be transmitted.
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void PduR_dSecOCTxConfirmation(PduIdType id, Std_ReturnType result) {

	PDUR_CHECK_STATE_VOID(PDUR_MODULE_ID_SECOC, PDUR_SID_TXCONF)

	if ((id >= PDUR_NR_VALID_SECOCIFTXTOUP_IDS)
			|| (PduR_iSecOCTxConfirmationFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TXCONF,
				PDUR_E_PDU_ID_INVALID);
		return;
	}

	PduR_iSecOCTxConfirmationFunc(id)(PduR_iSecOCTxConfirmationID(id),
			(result));

}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

/* Begin section for code */
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_dSecOCTpStartOfReception - This service is called by the SecOC TP for requesting a new buffer (pointer to a
 *                             PduInfoStructure containing a pointer to a SDU buffer and the buffer length) for the SecOC
 *                             TP to fill in the received data..
 */

BufReq_ReturnType PduR_dSecOCTpStartOfReception(PduIdType id,
		const PduInfoType *info, PduLengthType TpSduLength,
		PduLengthType *bufferSizePtr) {
	PDUR_CHECK_STATE_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TPSTARTOFRECEP,
			BUFREQ_E_NOT_OK)

	/*Check for Invalid Id and null pointer */
	if ((id >= PDUR_NR_VALID_SECOCTPRXTOUP_IDS)
			|| (PduR_iSecOCTpStartOfReceptionFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TPSTARTOFRECEP,
				PDUR_E_PDU_ID_INVALID);
		return BUFREQ_E_NOT_OK;
	} else {
		/*Call The upper layer StartOfReception function */
		return PduR_iSecOCTpStartOfReceptionFunc(id)(
				PduR_iSecOCTpStartOfReceptionID(id), info, TpSduLength,
				bufferSizePtr);
	}
}

/**
 **************************************************************************************************
 * PduR_dSecOCTpCopyRxData - This service is called by the SecOC TP for requesting a new buffer (pointer to a
 *                             PduInfoStructure containing a pointer to a SDU buffer and the buffer length) for the SecOC
 *                             TP to fill in the received data..
 *                  Function to be invoked DET enable for PduR_SecOCProvideRxBuffer
 */

BufReq_ReturnType PduR_dSecOCTpCopyRxData(PduIdType id, const PduInfoType *info,
		PduLengthType *bufferSizePtr) {
	PDUR_CHECK_STATE_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TPRXBUF,
			BUFREQ_E_NOT_OK)

	PDUR_CHECK_PTR_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TPRXBUF, info,
			BUFREQ_E_NOT_OK)

	/*Check for Invalid Id and null pointer */
	if ((id >= PDUR_NR_VALID_SECOCTPRXTOUP_IDS)
			|| (PduR_iSecOCTpCopyRxDataFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TPRXBUF,
				PDUR_E_PDU_ID_INVALID);
		return BUFREQ_E_NOT_OK;
	} else {
		/*Call the upper layer CopyRxData Function */
		return PduR_iSecOCTpCopyRxDataFunc(id)(PduR_iSecOCTpCopyRxDataID(id),
				info, bufferSizePtr);
	}
}

/**
 **************************************************************************************************
 * PduR_dSecOCTpRxIndication - PDU Router SecOCRxIndication.
 *        Function to be invoked DET enable for PduR_SecOCRxIndication
 */

void PduR_dSecOCTpRxIndication(PduIdType id, Std_ReturnType std) {
	PDUR_CHECK_STATE_VOID(PDUR_MODULE_ID_SECOC, PDUR_SID_TPRXIND)

	/*Check for Invalid Id and null pointer */
	if ((id >= PDUR_NR_VALID_SECOCTPRXTOUP_IDS)
			|| (PduR_iSecOCTpRxIndicationFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TPRXIND,
				PDUR_E_PDU_ID_INVALID);
		return;
	}

	/*Call the upperlayer RxIndication Function */
	PduR_iSecOCTpRxIndicationFunc(id)(PduR_iSecOCTpRxIndicationID(id), std);
}

/**
 **************************************************************************************************
 * PduR_dSecOCTpCopyTxData - This function is called by the SecOC TP for requesting a transmit buffer.
 *                 Function to be invoked DET enable for PduR_SecOCCopyTxData
 */

BufReq_ReturnType PduR_dSecOCTpCopyTxData(PduIdType id, const PduInfoType *info,
		const RetryInfoType *retry, PduLengthType *availableDataPtr) {
	/* If the PDU Router has not been initialized (PDUR_UNINIT state) all
	 services except PduR_Init() shall report the error PDUR_E_INVALID_REQUEST via the Development Error Tracer (DET)
	 when called.*/
	PDUR_CHECK_STATE_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TPTXBUF,
			BUFREQ_E_NOT_OK)

	PDUR_CHECK_PTR_RET(PDUR_MODULE_ID_SECOC, PDUR_SID_TPTXBUF, info,
			BUFREQ_E_NOT_OK)

	/* The PDU identifier shall be within the specified range and shall be
	 configured to be used by the PDU Router for
	 routing according to the post-build routing tables (PDUR_ONLINE state). Otherwise PDUR_E_PDU_ID_INVALID shall be
	 reported to DET.*/

	if ((id >= PDUR_NR_VALID_SECOCTPTXTOUP_IDS)
			|| (PduR_iSecOCTpCopyTxDataFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TPTXBUF,
				PDUR_E_PDU_ID_INVALID);
		return BUFREQ_E_NOT_OK;
	}

	/*Call the upperlayer CopyTxData Function */
	return PduR_iSecOCTpCopyTxDataFunc(id)(PduR_iSecOCTpCopyTxDataID(id), info,
			retry, availableDataPtr);
}

/**
 **************************************************************************************************
 * PduR_dSecOCTpTxConfirmation - Function to be invoked DET enable for PduR_SecOCTxConfirmation
 *
 *                  This function is called by the SecOC Transport Protocol:
 */

void PduR_dSecOCTpTxConfirmation(PduIdType id, Std_ReturnType std) {

	PDUR_CHECK_STATE_VOID(PDUR_MODULE_ID_SECOC, PDUR_SID_TPTXCONF)

	/*Check for Invalid Id and null pointer */
	if ((id >= PDUR_NR_VALID_SECOCTPTXTOUP_IDS)
			|| (PduR_iSecOCTpTxConfirmationFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_SECOC, PDUR_SID_TPTXCONF,
				PDUR_E_PDU_ID_INVALID);
		return;
	}

	/*Call upper layer TxConfirmation function */
	PduR_iSecOCTpTxConfirmationFunc(id)(PduR_iSecOCTpTxConfirmationID(id), std);
}

/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

