#include "PduR_Prv.h"
#if defined(PDUR_IFGATEWAY_SUPPORT) && (PDUR_IFGATEWAY_SUPPORT != STD_OFF)
#include "PduR_Gw.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_GF_TTIf_Buf_TxConfirmation  - Handle TxConfirmation for gatewaying between If layers
 *                  where a single entry buffer is in use
 *
 * \param           PduIdType gwayId:Not used
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void PduR_GF_TTIf_Buf_TxConfirmation_Func( PduIdType gwayId,Std_ReturnType result)
{
    (void)gwayId; /*Gateway Id */
    (void)result;
}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif /* PDUR_IFGATEWAY_SUPPORT */

