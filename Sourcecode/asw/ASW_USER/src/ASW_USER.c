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
 * Component: /SwComponentTypes/ASW_USER
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 12.0.1
 * Author: HZN4SGH
 * Date : Thu Apr 20 14:52:08 2023
 ****************************************************************************/

#include "Rte_ASW_USER.h"
#include "IfxGtm_reg.h"
#include "common.h"

#include "NvM.h"
#include "ASW_NVM.h"
#include "NVM_types.h"
#include "EepromData.h"
#include "IdsM.h"
#include "ASW_USER.h"
#include "Fls.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_USER_SWC_10ms_fun) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_USER_SWC_10ms_fun) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_USER_SWC_10ms_fun) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define ASW_USER_START_SEC_CODE                   
#include "ASW_USER_MemMap.h"
uint16 user_test_ReadData =0;
uint16 user_test_WriteData =0;
extern void ASW_COM_PSCMIDPSSFram01(uint8* idsData);
//extern Std_ReturnType  NvmSIDSDataWrite(uint8* BlockAddr, uint16 BlockSize);
extern void IC_BswM_NvM_ReadAll ( void );
void Ids_TxData (const uint8* idsData,
uint16 idsDataSize
);
uint8 data_dd[1024]={0,};
uint8 data_dd512[512]={0,};
uint8 data_dd511[512]={0,};
uint8 data_dd513[512]={0,};
uint8 data_dd514[512]={0,};
Std_ReturnType Readsem_BootFnc (uint8* Data);
void Ids_ReadNVMData(uint8* sem);
void Ids_WriteNVMData(uint8* data);
uint16 datalen[10] = {0};

FUNC (void, ASW_USER_CODE) RE_USER_SWC_10ms_fun/* return value & FctID */
(
		void
)
{

	uint16 dRead1;
	uint16 write2;
	Std_ReturnType retdRead1;
	Std_ReturnType retWrite2;

	static uint8 CNT=0;
	static uint8 i=0;
	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :RE_USER_SWC_10ms_fun) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	if(CNT>8)
	{
		 CNT= 0 ;

      Ids_MainFunction();

/*
       if (i == 1)
		 {
			 Ids_Evt_AuthFreshValVerifFail data;
			 data.sensitiveData = IDS_SENSITIVE_DATE_SYMMETRIC;
			 data.sensitiveOp = IDS_SENSITIVE_OP_READ;
			 data.did = 0x01;
			 data.sensitiveOpRes = IDS_SENSITIVE_OP_RES_UNKNOWN;

			 Ids_SetSecurityEventWithContextData(IDS_COMPROMISE_SENSITIVE_DATA, (uint8_t *)&data, sizeof(Ids_Evt_AuthFreshValVerifFail));

		 }
 	 else if(i == 2)
		 {
		 Ids_Evt_AuthFreshValVerifFail data;
		 data.sensitiveData = IDS_SENSITIVE_DATE_SYMMETRIC;
		 data.sensitiveOp = IDS_SENSITIVE_OP_READ;
		 data.did = 0x01;
		 data.sensitiveOpRes = IDS_SENSITIVE_OP_RES_UNKNOWN;

		 Ids_SetSecurityEventWithContextData(IDS_COMPROMISE_SENSITIVE_DATA, (uint8_t *)&data, sizeof(Ids_Evt_AuthFreshValVerifFail));
			// Ids_SetSecurityEvent(IDS_SECOC_FRESHVAL_VERIFY_FAIL);

		 }*/
       /*	 else if(i == 3)
		 {
			 Ids_MainFunction();
			 //Ids_SetSecurityEvent(IDS_SECOC_PDUMAC_VERIFY_FAIL_SMALL);

		 }
		 else if(i == 4)
		 {
			 Ids_MainFunction();
			// Ids_SetSecurityEvent(IDS_SECOC_PDUMAC_VERIFY_FAIL_MEDIUM);

		 }
		 else if(i == 5)
		 {
			 Ids_MainFunction();
			// Ids_SetSecurityEvent(IDS_SECOC_FRESHVAL_RESYNC);

		 }
		 else if(i == 6)
		 {
			 Ids_MainFunction();
			//Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_SUCCESS);

		 }
		 else if(i == 7)
		 {
			 Ids_SetSecurityEvent(IDS_SECOC_KEY_DISTRIBUTION_UPD_FAIL);

		 }
		 else if(i == 8)
		 {
			 Ids_SetSecurityEvent(IDS_SECOC_KEY_RESET_SUCCESS);

		 }
		 else if(i == 9)
		 {
			// Ids_SetSecurityEvent(IDS_SECOC_KEY_RESET_FAIL);

		 }
		 else if(i == 10)
		 {
			 Ids_Evt_SecurityAccessValiFail data;
			 data.level = 1;
			 data.nrc = 35;

			 Ids_SetSecurityEventWithContextData(IDS_SECURITY_ACCESS_VALIDATION_FAIL, (uint8_t *)&data, sizeof(Ids_Evt_SecurityAccessValiFail));

		 }
		 else if(i == 11)
		 {
		     Ids_SecurityAccLvType data;
			 data = 1;

			 Ids_SetSecurityEventWithContextData(IDS_SECURITY_ACCESS_VALIDATION_SUCCESS, (uint8_t *)&data, sizeof(Ids_SecurityAccLvType));

		 }
		 else if(i == 12)
		 {
			 Ids_Evt_SecurityAccessMismatchCmdExc data;
			 data.serviceId = 5;
			 data.subFunctionId = 6;

			 Ids_SetSecurityEventWithContextData(IDS_SECURITY_ACCESS_LEVEL_MISMATCH, (uint8_t *)&data, sizeof(Ids_Evt_SecurityAccessMismatchCmdExc));
		 }*/
/*			else
	        {

	        }
	        if(i<20)
	        {
	        i++;
	        }*/


	}
	else
	{
		CNT++;
	}


	 // Ids_SetSecurityEvent (0x8024);
	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :RE_USER_SWC_10ms_fun) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}
#define ASW_USER_STOP_SEC_CODE  
#include "ASW_USER_MemMap.h" 

#define ASW_USER_START_SEC_CODE                   
#include "ASW_USER_MemMap.h"
void GTMEn_PeriodicInterrupt(void)
{
#if 0
	GTM_TOM0_CH0_IRQ_EN.B.CCU0TC_IRQ_EN = 1U;
	Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0 , 10000UL);
#endif
}
#define ASW_USER_STOP_SEC_CODE  
#include "ASW_USER_MemMap.h" 
/*PROTECTED REGION ID(FileHeaderUserDefinedFunctions :ASW_USER) ENABLED START */
/* Start of user defined functions  - Do not remove this comment */
/* End of user defined functions - Do not remove this comment */
/*PROTECTED REGION END */
extern void MCan_Transmit02(uint8 *data);
Std_ReturnType Readsem_BootFnc (uint8* Data)
{
     uint8 i = 0;
     uint8_t bootFailReason = 0;//1;
     uint8_t bootSwPn[6] = {0xFF,0xFF,0xFF,0xFF ,0xFF, 0xFF};
     uint8_t updateState = 0;//0x0F;
     uint8_t updateSwPn[5] = {0xFF, 0xFF, 0xFF, 0xFF , 0xFF};
     uint8_t Restsr[2] = {0xFF,0xFF};

	 uint8 *SemADDR;
	 SemADDR = ((uint8 *)0xAF012000);//锟斤拷址锟斤拷boot锟斤拷锟�

		for(i = 0;i < 14;i++)
		{
			Data[i] = *SemADDR;
			SemADDR++;
		}
		for(i = 0;i < 8;i++)
		{

		}

	 if (WatchDogtimeoutFlag())
	 {
		 Restsr[0]=0;
		 Restsr[1]=1;
	 }
	 updateState = Data[9];
	 if(Data[2]==0x02)
	 {
		 bootFailReason = 0x02 ;
	 }
	 else
	 {
		 bootFailReason = 0xFF ;
	 }
     memcpy(Data, &bootFailReason, 1);
     memcpy(Data + 1, bootSwPn, 6);
     memcpy(Data + 1 + 6, &updateState, 1);
     memcpy(Data + 1 + 6 + 1, updateSwPn, 5);
     memcpy(Data + 1 + 6 + 1 + 5, Restsr, 2);
	return RTE_E_OK;
}
Std_ReturnType Readsem_BootFnc_clear()
{
	uint8 SemADDR[32]={0};
	uint8 i =0;
	 uint8 *SemADDR1;
			 SemADDR1 = ((uint8 *)0xAF012000);//锟斤拷址锟斤拷boot锟斤拷锟�

		Fls_Erase(0x12000, 8);

		Fls_Erase(0x12008, 8);
		 //test111[4]= SemADDR1[2];
		// test111[5]= SemADDR1[9];
	return RTE_E_OK;
}

void Ids_TxData ( const uint8* idsData,
uint16 idsDataSize
)
{
	ASW_COM_PSCMIDPSSFram01(idsData);
}
void Ids_WriteNVMData (uint8* data)
{
	uint16 i=0;
	//NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_NATIVE_IDS_1024, data);
	for(i=0;i<512;i++)
	{
	data_dd513[i]=data[i];
	}
	 memcpy(&Nvm_BswIDS_Data[0], &data[0], 512);
	 //NvmSIDSDataWrite(Nvm_BswIDS_Data, NVM_CFG_NV_BLOCK_LENGTH_NvM_NATIVE_IDS_1024);
}
void Ids_GetCarConfigInfo(uint8* carMode, uint8* carConfig)
{
	*carMode = 0x0U;//&Fv_CarMode;
	*carConfig = 0x02U;//&Eeprom_CanCCp.data.ccp741;
}
void Ids_GetTimestamp(uint64* timestamp)
{
		*timestamp = G_timestamp;
}
void Ids_ReadNVMData(uint8* sem)
{
	   uint16 i = 0;
	//NvM_ReadBlock(NvMConf_NvMBlockDescriptor_NvM_NATIVE_IDS_1024,&Nvm_BswIDS_Data[0]);
	 memcpy(&sem[0], &Nvm_BswIDS_Data[0], 512);
}
