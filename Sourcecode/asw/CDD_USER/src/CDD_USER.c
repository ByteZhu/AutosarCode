/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Name: 
 * Description:
 * Version: 1.0
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : ENTRYP_AUTOSAR_BSW12_V5.0
 * Component: /SwComponentTypes/CDD_USER
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 12.0.1
 * Author: HZN4SGH
 * Date : Thu Apr 20 15:24:48 2023
 ****************************************************************************/

#include "Rte_CDD_USER.h"

/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :User_40usIsr_fun) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :User_40usIsr_fun) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :User_40usIsr_fun) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define CDD_USER_START_SEC_CODE                   
#include "CDD_USER_MemMap.h"

uint16 cdd_test_ReadData =0;
uint16 cdd_test_WriteData =0;
uint16 while_loop_counter = 0;
uint16 Reassembly_counter = 1250;//1250 ~40us
FUNC (void, CDD_USER_CODE) User_40usIsr_fun/* return value & FctID */
(
		void
)
{

	uint16 dRead1 ;
	uint16 write2;
	Std_ReturnType retdRead1;
	Std_ReturnType retWrite2;

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :User_40usIsr_fun) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;

	/*  -------------------------------------- Data Read -----------------------------------------  */
	
	//dRead1 = Rte_DRead_RPort_UserSend_Data();
	
	cdd_test_ReadData = dRead1;
	write2 = cdd_test_WriteData; 
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */
	
	//retWrite2 = Rte_Write_PPort_UserRec_Data(write2);
	
	cdd_test_WriteData++;
	while_loop_counter = Reassembly_counter;
	while(while_loop_counter)
	{
		while_loop_counter--;
	}
	
	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :User_40usIsr_fun) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}
#define CDD_USER_STOP_SEC_CODE  
#include "CDD_USER_MemMap.h" 

/*PROTECTED REGION ID(FileHeaderUserDefinedFunctions :CDD_USER) ENABLED START */
/* Start of user defined functions  - Do not remove this comment */
/* End of user defined functions - Do not remove this comment */
/*PROTECTED REGION END */

