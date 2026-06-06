/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */


#include "Dcm_Cfg_Prot.h"
//#include "DcmCore_DslDsd_Inf.h"
#include "Dcm.h"
#include "Rte_Dcm.h"



#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 * @ingroup DCM_TPL
 *  DcmAppl_DcmCancelPagedBufferProcessing :-\n
 *  This API indicates the service to stop paged buffer transmission.This API has to call ini function of the service.
 *  @param[in]       idContext : SID of the service which is running.\n
 *  @param[out]      None
 *  @retval          None
 */
void DcmAppl_DcmCancelPagedBufferProcessing(Dcm_IdContextType idContext)
{
    /* BSWEXT-470 */
    /*TESTCODE-START
    DcmTest_DcmAppl_DcmCancelPagedBufferProcessing(idContext);
    TESTCODE-END*/
    (void) idContext;
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

