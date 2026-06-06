#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"


#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/**
 **************************************************************************************************
 * Dcm_RestartP3timer : Function called by Kline TP to restart P3 timer after getting the first
 *                          byte of request
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void Dcm_RestartP3timer(void)
{
    /* Restart P3 timer */
    Dcm_Prv_ReloadS3Timer();
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

