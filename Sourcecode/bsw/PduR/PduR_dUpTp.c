
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
#include "PduR_UpTp.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
/**
 **************************************************************************************************
 * PduR_dDcmTransmit - Function to be invoked DET enable for PduR_DcmTransmit
 *      This function is called by the Dcm to request a transmission.
 *
 * \param           PduIdType id: ID of Dcm I-PDU to be transmitted.
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
Std_ReturnType PduR_dDcmTransmit(PduIdType id, const PduInfoType *ptr) {
	Std_ReturnType r;

	PDUR_CHECK_STATE_RET(PDUR_MODULE_ID_DCM, PDUR_SID_TX, E_NOT_OK)

	PDUR_CHECK_PTR_RET(PDUR_MODULE_ID_DCM, PDUR_SID_TX, ptr, E_NOT_OK)

	if ((id >= PDUR_NR_VALID_DCM_IDS)
			|| (PduR_iDcmTransmitFunc(id) == NULL_PTR)) {
		PDUR_REPORT_ERROR(PDUR_MODULE_ID_DCM, PDUR_SID_TX,
				PDUR_E_PDU_ID_INVALID);
		return E_NOT_OK;
	}

	r = PduR_iDcmTransmitFunc(id)(PduR_iDcmTransmitID(id), ptr);

	if (E_OK != r) {
		PDUR_REPORT_RUNTIME_ERROR(PDUR_MODULE_ID_DCM, PDUR_SID_TX,
				PDUR_E_TP_TX_REQ_REJECTED);
	}

	return r;
}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

