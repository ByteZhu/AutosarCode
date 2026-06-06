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
#include "Dcm_Prv.h"

#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)

 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 * @ingroup DCM_TPL
 * DcmAppl_DcmGetStoreType :-\n
 * This API is used to retrieve the Type of Storage required by User.
 * This API should return the Storage Type required by the user for Jump to Boot.\n
 *
 * @param[in]       dataBootType_u8 : Posible values are DCM_JUMPTOOEMBOOTLOADER ,DCM_JUMPTOSYSSUPPLIERBOOTLOADER or DCM_JUMPDRIVETODRIVE
 * @param[in]       SID :Service identifier.Possible values are DCM_DSP_SID_DIAGNOSTICSESSIONCONTROL and DCM_DSP_SID_ECURESET.
 * @param[out]      None
 * @retval           0u     :  Jump to Boot Not allowed\n
 * @retval           1u     :  Warm Request Type\n
 * @retval           2u     :  Warm Init Type\n
 * @retval           3u     :  Warm Response Type\n
 */
uint8 DcmAppl_DcmGetStoreType(uint8 dataBootType_u8,uint8 SID)

{
    /* add your implementation here*/

    /* BSWEXT-470 */
	//uint8 retVal = DCM_NOTVALID_TYPE;
	uint8 retVal = DCM_WARMRESPONSE_TYPE;

	/*TESTCODE-START
	retVal = DcmTest_DcmAppl_DcmGetStoreType(dataBootType_u8,SID);
	TESTCODE-END*/

	return(retVal);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#endif

