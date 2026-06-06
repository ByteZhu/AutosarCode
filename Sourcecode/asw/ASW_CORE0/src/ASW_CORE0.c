/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Project :    ETAS Entry Platform
 * Component:  ASW_CORE0
 * Description: Testcode for ASW_CORE0
 * Version         Author:       Date               Update information
 * 1.0             AGT1HC        12-Mar-2019        Create software
 * 1.1             AGT1HC        19-Jan-2021        Update software for new requirement OS_2_1
 * 1.2             HAD1HC        02-Feb-2021        Test code for transmission and reception 
 * 													data from other core
 * 1.3			   HAD1HC	     01-Mar-2021		Add function for fault reaction
 * 1.4			   HAD1HC	     15-Mar-2021		Update API call for stack utilization
 * 													Add function for handling IRV variable
 * 													Update function of getting CPU Load	
 * 1.5             HAD1HC	     13-Apr-2021	    Update Memmap
 * 1.6             HAD1HC	     20-Sep-2021	    Update RE_Core0FaultReaction, RE_CORE0_SWC_10ms_func					
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************/
#define CPULOAD_MEASURE_TIME 1000u /* 1000u = 1 second */
#define ISR_ID 255
#define CORE0_ID 0
#define CORE1_ID 1
#define CORE2_ID 2
#define CORE3_ID 3

#include "Rte_ASW_CORE0.h"
#include "ASW_CORE0.h"

#define ASW_CORE0_START_SEC_VAR_INIT_8
#include "ASW_CORE0_MemMap.h"
uint8 CPU0_StatusUtiliazation=0;
char Test_ErrorHook=0;
boolean ShutdownRequested = FALSE;
#define ASW_CORE0_STOP_SEC_VAR_INIT_8
#include "ASW_CORE0_MemMap.h"

#define ASW_CORE0_START_SEC_VAR_INIT_64
#include "ASW_CORE0_MemMap.h"
float64  CPU0_PercentUtilization=0.0;
float64 CPU0_MaximumUtilization = 0.0;
float64 Core0_MaxUserStackUtilization = 0.0;
#define ASW_CORE0_STOP_SEC_VAR_INIT_64
#include "ASW_CORE0_MemMap.h"

#define ASW_CORE0_START_SEC_CODE
#include "ASW_CORE0_MemMap.h"

FUNC (void, ASW_CORE0_CODE) RE_CORE0_SWC_10ms_func/* return value & FctID */
(
		void
)
{


	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :RE_CORE0_SWC_10ms_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */



	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :RE_CORE0_SWC_10ms_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}
FUNC(void, ASW_CORE0_CODE) RE_Core0FaultReaction(VAR(StatusType, AUTOMATIC) Error)
{
	
	switch (Error)
	{
	case E_OS_LIMIT:
		ShutdownRequested = TRUE;
		break;
	case E_OS_STACKFAULT:
		ShutdownRequested = TRUE;
		break;
	default:
		break;
	}
	
}

#define ASW_CORE0_STOP_SEC_CODE
#include "ASW_CORE0_MemMap.h"
