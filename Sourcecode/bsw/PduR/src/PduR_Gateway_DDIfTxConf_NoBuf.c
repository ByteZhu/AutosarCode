/** Handle TxConfirmation from a lower interface layer which uses
  * data direct transmission and which is not configured with a DD-FIFO.
  */

#include "PduR_Prv.h"
#include "PduR_Gw.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

void PduR_GF_DDIf_NoBuf_TxConfirmation_Func(PduIdType gwayId,Std_ReturnType result)
{
    /* We do not need this confirmation: simply ignore it */
    (void)gwayId;
    (void)result;

}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

