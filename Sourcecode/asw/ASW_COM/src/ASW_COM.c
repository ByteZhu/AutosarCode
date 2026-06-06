/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Project :    ETAS Entry Platform
 * Component:  ASW_COM
 * Description: Testcode for ASW_COM
 * Version         Author:       Date               Update information
 * 1.0             AGT1HC        12-Mar-2019        Standardized the Banner
 * 1.1             AGT1HC        19-Jan-2021        Update software for new requirement OS_2_1
 * 1.2			   HAD1HC	     13-Apr-2021        Update Memmap
 * 1.3			   AGT1HC	     18-Aug-2021        Update testcase for 60 signals
 * 1.4             LEA8HC        06-Oct-2021        Update timeout value replace
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : ETAS Entry Platform
 * Component: /COM_SWC/ASW_COM
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 9.1
 * Author: AGT1HC
 * Date : Wed Aug 18 16:20:43 2021
 ****************************************************************************/

#include "Rte_ASW_COM.h"
#include "CDD_FVM.h"
#include "common.h"
#include "Com_User.h"
#include "E2E_User.h"
#include "CalVarExt.h"
#include "IdsM.h"
#include "CanIf_Prv.h"
#include "Com.h"
#include "E2EXf.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_COM_SWC_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_COM_SWC_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_COM_SWC_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define ASW_COM_START_SEC_VAR_INIT_8                   
#include "ASW_COM_MemMap.h"
//add your code
#define ASW_COM_STOP_SEC_VAR_INIT_8                   
#include "ASW_COM_MemMap.h"

#define ASW_COM_START_SEC_VAR_INIT_16                   
#include "ASW_COM_MemMap.h"
//add your code
#define ASW_COM_STOP_SEC_VAR_INIT_16                   
#include "ASW_COM_MemMap.h"

#define ASW_COM_START_SEC_VAR_INIT_16                   
#include "ASW_COM_MemMap.h"
//add your code
#define ASW_COM_STOP_SEC_VAR_INIT_16                   
#include "ASW_COM_MemMap.h"

#define ASW_COM_START_SEC_VAR_INIT_32                   
#include "ASW_COM_MemMap.h"
//add your code 
#define ASW_COM_STOP_SEC_VAR_INIT_32                   
#include "ASW_COM_MemMap.h"

// #define ASW_COM_START_SEC_CODE                   
// #include "ASW_COM_MemMap.h"
// #define RAD_TO_DEG 5729578
// /*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_COM_SWC_func) ENABLED START */
// /* Start of user variable defintions - Do not remove this comment  */
// extern _c__PSCM_IDS_buf PSCM_IDS_GEELYFrame01;
// extern void MCan_TransmitTEST(uint8 *data);
// uint8 secframe01_AsyADL3FuncCtrlStsChks8 = 0;
// uint8 secframe02_VehSpdLgtChks8 = 0;
// uint8 secframe03_VehMtnStChks8 = 0;
// uint8 secframe04_VehModMngtGlbSafeChks8 = 0;
// uint8 secframe01_tx_PinionSteerAgChks8 = 0;

// static void ASW_COM_PSCMFram01(void);
// static void ASW_COM_PSCMSACM_SecCanFrame01(void);
// static void ASW_COM_PSCMSACMFram01(void);
// static void ASW_COM_PSCMSACMFram02(void);
// static void ASW_COM_PSCMSACMFram03(void);
// static void ASW_COM_PSCMSACMFram04(void);
// static void ASW_COM_PSCMSFCMFram01(void);
// static void ASW_COM_PSCMSFCMFram03(void);
// void ASW_COM_PSCMIDPSSFram01(uint8* idsData);
// void ASW_COM_PSCMBCCanFDFram01(void);
// void ASW_COM_Secoc_pro(void);
// static void ASW_COM_RX_CSCBCMCore_SecCanFrame01(void);

// static void ASW_COM_RX_CSCBCMCore_SecCanFrame02(void);

// static void ASW_COM_RX_CSCBCMCore_SecCanFrame03(void);

// //static void ASW_COM_RX_CSCBCMCore_SecCanFrame04(void);

// static void ASW_COM_RX_CSCBCMCore_SpecialSecFrame01(void);

// static void ASW_COM_RX_MCoreBCCanFDFrame02(void);
// static void ASW_COM_RX_MCoreBCCanFDFrame03(void);
// static void ASW_COM_RX_MCoreBCCanFDFrame04(void);
// static void ASW_COM_RX_MCoreBCCanFDFramefe(void);
// static void ASW_COM_RX_MCoreBCCanFDFrame01(void);
// static void ASW_COM_RX_MCoreBCCanFDFrame07(void);
// static void ASW_COM_RX_MCoreBCCanFDFrame09(void);
// static void ASW_COM_RX_ISWMBCCanFDFrame06(void);
// static void ASW_COM_TestModeRequest_Process(void);
// //CAN2
// static void ASW_COM_PSCBHIPBCanFD7Frame01(void);
// static void ASW_COM_RX_CSCHIPBHIPBCANFD7Frame03(void);
// static void ASW_COM_RX_CSCHIPBHIPBCanFD7Frame10(void);

// /* CAN Frame PDU Info for Trigger transmit check */
// #include "Can_GeneralTypes.h"
// uint8 tx_data_1[][10] = {
//   {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 },
//   {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18 },
//   {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28 },
//   {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38 },
//   {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48 },
//   {0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58 },
//   {0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68 },
//   {0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78 },
//   {0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88 },
//   {0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98 },
//   {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
//   {0x11, 0x22, 0x33, 0x44, 0x44, 0x33, 0x22, 0x11 },
//   {0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98 },
// } ;

// Can_PduType PduInfo_TriggerTransmit[] =
// {
//   {tx_data_1[0], 0x2A, 37, 8 },
//   {tx_data_1[1], 0x2A, 38, 8 },
//   {tx_data_1[0], 0x2A, 39, 8 },
//   {tx_data_1[1], 0x2A, 40, 8 }
// };
// uint8 innerTrans[64];
// extern void MCan_Transmit_Inner(uint8 *data);//02
void ASW_COM_TX_PscmChas1Fr01(void)
{
  Rte_Write_ASW_COM_PPort_DrvrSteerActv_UB_DrvrSteerActv_UB(1);
  Rte_Write_ASW_COM_PPort_DrvrSteerActvDrvrSteerActv_DrvrSteerActvDrvrSteerActv(1);
}

void ASW_COM_TX_PscmChas1Fr02(void)
{
  Rte_Write_ASW_COM_PPort_LatCtrlModCfmd_UB_LatCtrlModCfmd_UB(1);
  Rte_Write_ASW_COM_PPort_LatCtrlModCfmdLatCtrlMod_LatCtrlModCfmdLatCtrlMod(12);
}

void ASW_COM_TX_PscmChas1Fr07(void)
{
  Rte_Write_ASW_COM_PPort_PinionSteerAgGroup_UB_PinionSteerAgGroup_UB(1);
  Rte_Write_ASW_COM_PPort_PinionSteerAgGroupPinionSteerAg1_PinionSteerAgGroupPinionSteerAg1(129);
  Rte_Write_ASW_COM_PPort_PinionSteerAgGroupPinionSteerAgS_PinionSteerAgGroupPinionSteerAgS(88);
}

void ASW_COM_RX_AsdmChas1Fr03(void)
{
	uint8 data1 = 0;
	uint8 data2 = 0;
	uint16 data3 = 0;
	Rte_Read_ASW_COM_RPort_AsyPinionAgReqSafeAsyPinion_0000_AsyPinionAgReqSafeAsyPinion_0000(&data1);
	Rte_Read_ASW_COM_RPort_AsyPinionAgReqSafeAsyPinion_0001_AsyPinionAgReqSafeAsyPinion_0001(&data2);
	Rte_Read_ASW_COM_RPort_AsyPinionAgReqSafeAsyPinionAgReq_AsyPinionAgReqSafeAsyPinionAgReq(&data3);
}

FUNC (void, ASW_COM_CODE) RE_COM_SWC_func/* return value & FctID */
(
		void
)
{

	/* Tx Data */
  ASW_COM_TX_PscmChas1Fr01();
	ASW_COM_TX_PscmChas1Fr02();
  ASW_COM_TX_PscmChas1Fr07();
	ASW_COM_RX_AsdmChas1Fr03();
// 	uint8 InternalData[2] = {0};

// 	/* Local Data Declaration */
// 	static uint8 E2E_Function_Init_Flag = 0x0;

// 	/*PROTECTED REGION ID(UserVariables :RE_COM_SWC_func) ENABLED START */
// 	/* Start of user variable defintions - Do not remove this comment  */
// 	/* End of user variable defintions - Do not remove this comment  */
// 	/*PROTECTED REGION END */
// 	Std_ReturnType retValue = RTE_E_OK;
// 	uint16 sync_rstcnt = 0;
// 	uint32 sync_tripcnt = 0;

// 	if(E2E_Function_Init_Flag == 0x0)
// 	{
// 		E2E_Function_Init_Flag = 0xAA;
// 		//TX
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SACM_SecCanFrame01_ADL);
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SACM_SecCanFrame01_LAT);	
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SACM_SecCanFrame01_PIN);		
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SACMFram01_DRV);
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SACMFram01_STE);	
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SACMFram02_SSS);
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SACMFram02_SST);
// 		E2E_P11ProtectInit(&E2E_P11ProtectStateType_SFCMBCCanFDFrame01);
	
// 		//RX
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame01_ADF);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame01_APA);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame01_AAM);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame01_ALO);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame02_VSL);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame02_BPP);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame03_WFS);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame03_WRT);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_SecCanFrame03_VMS);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame06);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame01_ES);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame01_VMM);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame04_ALC);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame04_ADR);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame04_AgD);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame04_WSCF);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame04_WSCR);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame04_LCR);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame07_GLI);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame07_ACA);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame07_PTA);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame09_ADW);
// 		E2E_P11CheckInit(&E2E_P11CheckStateType_CanFDFrame09_PPA);		
// 	}	
// 	/*  -------------------------------------- Data Read -----------------------------------------  */
// 	Rte_Read_RPort_AsyADL3FuncCtrlStsChks8_AsyADL3FuncCtrlStsChks8(&secframe01_AsyADL3FuncCtrlStsChks8);
// 	Rte_Read_RPort_VehSpdLgtChks8_VehSpdLgtChks8(&secframe02_VehSpdLgtChks8);
// 	Rte_Read_RPort_VehMtnStChks8_VehMtnStChks8(&secframe03_VehMtnStChks8);
// 	Rte_Read_RPort_VehModMngtGlbSafeChks8_VehModMngtGlbSafeChks8(&secframe04_VehModMngtGlbSafeChks8);
// 	Rte_Read_RPort_TripResetSyncMsgRestCnt_TripResetSyncMsgRestCnt(&sync_rstcnt);
// 	if(Rte_IsUpdated_ASW_COM_RPort_TripResetSyncMsgTripCnt_TripResetSyncMsgTripCnt())
// 	{
// 		Rte_Read_RPort_TripResetSyncMsgTripCnt_TripResetSyncMsgTripCnt(&sync_tripcnt);
// 		Get_Trip_Reset_Counter_Clear_Acceptance_Store_Trip(sync_rstcnt, sync_tripcnt);
// 	}
// 	/*  -------------------------------------- Data Read -----------------------------------------  */
// 	ASW_COM_RX_MCoreBCCanFDFrame01();
// 	ASW_COM_RX_CSCBCMCore_SecCanFrame01();
// 	ASW_COM_RX_CSCBCMCore_SecCanFrame02();
// 	ASW_COM_RX_CSCBCMCore_SecCanFrame03();
// 	//ASW_COM_RX_CSCBCMCore_SecCanFrame04();
// 	ASW_COM_RX_CSCBCMCore_SpecialSecFrame01();
// 	ASW_COM_RX_MCoreBCCanFDFrame02();
// 	ASW_COM_RX_MCoreBCCanFDFrame03();
// 	ASW_COM_RX_MCoreBCCanFDFrame04();
// 	ASW_COM_RX_MCoreBCCanFDFramefe();
// 	ASW_COM_TestModeRequest_Process();
// 	ASW_COM_RX_MCoreBCCanFDFrame07();
// 	ASW_COM_RX_MCoreBCCanFDFrame09();
// 	ASW_COM_RX_ISWMBCCanFDFrame06();


//      ASW_COM_RX_CSCHIPBHIPBCANFD7Frame03();
// 	 ASW_COM_RX_CSCHIPBHIPBCanFD7Frame10();
//   #  define ComConf_ComSignal_S_test_0x1A_current_Can_Network_1_Channel_CAN_Tx 19
//   #  define ComConf_ComSignal_S_test_0x2A_current_Can_Network_2_Channel_CAN_Tx 23

// 	//debug_jing1++;
// 	//InternalData[0] = (debug_jing1 >> 8);
// 	//InternalData[1] = (debug_jing1 >> 0);
// 	//Com_SendSignal((23), InternalData);
// 	//Com_SendSignal((19), InternalData);

// 	//Can_Write(37,&PduInfo_TriggerTransmit[0]);
// 	//Can_Write(38,&PduInfo_TriggerTransmit[1]);
// 	//Can_Write(39,&PduInfo_TriggerTransmit[2]);
// 	//Can_Write(40,&PduInfo_TriggerTransmit[3]);
// 	/*  -------------------------------------- Server Call Point  --------------------------------  */

//     /*  -------------------------------------- RX Timeout value replace  -------------------------  */
    
// 	/*  -------------------------------------- CDATA ---------------------------------------------  */

// 	/*  -------------------------------------- Data Write ----------------------------------------  */
// 	secframe01_tx_PinionSteerAgChks8++;
// 	//Rte_Write_PPort_PinionSteerAgChks8_PinionSteerAgChks8(secframe01_tx_PinionSteerAgChks8);
// 	ASW_COM_PSCMFram01();

// 	ASW_COM_PSCMSACM_SecCanFrame01();
// 	ASW_COM_PSCMSACMFram01();
// 	ASW_COM_PSCMSACMFram02();
// 	ASW_COM_PSCMSACMFram03();
// 	ASW_COM_PSCMSACMFram04();
// 	ASW_COM_PSCMSFCMFram01();
// 	ASW_COM_PSCMSFCMFram03();
	
// 	ASW_COM_PSCBHIPBCanFD7Frame01();
// 	ASW_COM_Secoc_pro();

// 	/*  -------------------------------------- Trigger Interface ---------------------------------  */

// 	/*  -------------------------------------- Mode Management -----------------------------------  */

// 	/*  -------------------------------------- Port Handling -------------------------------------  */

// 	/*  -------------------------------------- Exclusive Area ------------------------------------  */

// 	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

// 	/*PROTECTED REGION ID(User Logic :RE_COM_SWC_func) ENABLED START */
// 	/* Start of user code - Do not remove this comment */
// 	/* End of user code - Do not remove this comment */

// 	/*PROTECTED REGION END */

// }
// #define ASW_COM_STOP_SEC_CODE  
// #include "ASW_COM_MemMap.h" 

// /*PROTECTED REGION ID(FileHeaderUserDefinedFunctions :ASW_COM) ENABLED START */
// /* Start of user defined functions  - Do not remove this comment */
// /* End of user defined functions - Do not remove this comment */
// /*PROTECTED REGION END */

// void ASW_COM_Secoc_pro(void)
// {
// 	static uint8 send_falg = 0;
// 	static uint8 timer_cnt = 0x0;
// 	static uint8 timer_50ms = 0x0;
// 	static uint8 timer = 3;
// 	static uint8 busoff_last_flag = 0;

// 	if((CanIf_Prv_ControllerState_ast[0].Ctrl_Pdu_mode&0X0F==CANIF_TX_OFFLINE))
// 	{
// 		//busoffÇå³ý×´Ì¬
// 		Can_NM_tx_flag = 0;
// 		Can_busoffrecover = 0;
// 		Can_secoc_pr = 0;
// 		send_falg =0;
// 	}
// 	if((CanIf_Prv_ControllerState_ast[0].Ctrl_Pdu_mode&0X0F==CANIF_ONLINE)&&(busoff_last_flag==CANIF_TX_OFFLINE))
// 	{
// 		//buoffÖÃÎª×´Ì¬
// 		Can_busoffrecover = 0xAA;//busoff»Ö¸´

// 	}

// 	if((Can_NM_tx_flag == 0xAA)||(Can_busoffrecover == 0xAA))
// 	{
// 		timer_cnt++;
// 		timer_50ms++;
// 		if(timer_cnt>29)//150ms
// 		{
// 			timer_cnt=30;
// 		}
// 		else
// 		{//150msÄÚ
// 			if(Can_secoc_pr == 0xAA)
// 			{
// 				send_falg = 0xAA;
// 			}

// 		}

// 		if((timer_50ms>9)&&(send_falg!=0XAA)&&(timer!=0))
// 		{
// 			timer--;
// 			timer_50ms = 0;

// 			ASW_COM_PSCMBCCanFDFram01();
// 		}


// 	}
// 	else
// 	{
// 		Can_secoc_pr=0;
// 		timer_cnt=0;
// 		timer=3;
// 		send_falg =0;
// 	}
// 	busoff_last_flag = (CanIf_Prv_ControllerState_ast[0].Ctrl_Pdu_mode&0X0F);
// }
// static void ASW_COM_PSCBHIPBCanFD7Frame01(void)
// {
// 	uint8 write358;
// 		Std_ReturnType retWrite358;
// 		uint8 write359;
// 		Std_ReturnType retWrite359;
// 		uint8 write360;
// 		Std_ReturnType retWrite360;
// 		uint8 write361;
// 		Std_ReturnType retWrite361;
// 		uint8 write362;
// 		Std_ReturnType retWrite362;
// 		uint8 write363;
// 		Std_ReturnType retWrite363;
// 		uint8 write364;
// 		Std_ReturnType retWrite364;
// 		uint8 write365;
// 		Std_ReturnType retWrite365;
// 		uint8 write366;
// 		Std_ReturnType retWrite366;
// 		uint8 write367;
// 		Std_ReturnType retWrite367;
// 		uint8 write368;
// 		Std_ReturnType retWrite368;
// 		uint8 write369;
// 		Std_ReturnType retWrite369;
// 		uint8 write370;
// 		Std_ReturnType retWrite370;
// 		uint8 write371;
// 		Std_ReturnType retWrite371;
// 		uint8 write372;
// 		Std_ReturnType retWrite372;
// 		uint16 write373;
// 		Std_ReturnType retWrite373;
// 		uint8 write374;
// 		Std_ReturnType retWrite374;
// 		uint16 write375;
// 		Std_ReturnType retWrite375;
// 		uint8 write376;
// 		Std_ReturnType retWrite376;
// 		uint16 write377;
// 		Std_ReturnType retWrite377;

// 	    retWrite358 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkp_UB_ADL3LatCtrlStsForCoDrvForBkp_UB(write358);
// 		retWrite359 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpADMo_ADL3LatCtrlStsForCoDrvForBkpADMo(write359);
// 		retWrite360 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpChks_ADL3LatCtrlStsForCoDrvForBkpChks(write360);
// 		retWrite361 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpCntr_ADL3LatCtrlStsForCoDrvForBkpCntr(write361);
// 		retWrite362 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpCtrl_ADL3LatCtrlStsForCoDrvForBkpCtrl(write362);
// 		retWrite363 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpData_ADL3LatCtrlStsForCoDrvForBkpData(write363);
// 		retWrite364 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpDegr_ADL3LatCtrlStsForCoDrvForBkpDegr(write364);
// 		retWrite365 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpLatC_ADL3LatCtrlStsForCoDrvForBkpLatC(write365);
// 		retWrite366 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpQf_ADL3LatCtrlStsForCoDrvForBkpQf(write366);
// 		retWrite367 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvForBkpSts_ADL3LatCtrlStsForCoDrvForBkpSts(write367);
// 		retWrite368 = Rte_Write_PPort_PinionSteerAgGroupForBkp_UB_PinionSteerAgGroupForBkp_UB(write368);
// 		retWrite369 = Rte_Write_PPort_PinionSteerAgGroupForBkpChks8_PinionSteerAgGroupForBkpChks8(write369);
// 		retWrite370 = Rte_Write_PPort_PinionSteerAgGroupForBkpCntr4_PinionSteerAgGroupForBkpCntr4(write370);
// 		retWrite371 = Rte_Write_PPort_PinionSteerAgGroupForBkpDataID4_PinionSteerAgGroupForBkpDataID4(write371);
// 		retWrite372 = Rte_Write_PPort_PinionSteerAgGroupForBkpPin_0000_PinionSteerAgGroupForBkpPin_0000(write372);
// 		retWrite373 = Rte_Write_PPort_PinionSteerAgGroupForBkpPin_0001_PinionSteerAgGroupForBkpPin_0001(write373);
// 		retWrite374 = Rte_Write_PPort_PinionSteerAgGroupForBkpPin_0002_PinionSteerAgGroupForBkpPin_0002(write374);
// 		retWrite375 = Rte_Write_PPort_PinionSteerAgGroupForBkpPinionSt_PinionSteerAgGroupForBkpPinionSt(write375);
// 		retWrite376 = Rte_Write_PPort_PinionSteerAgGroupForBkpSte_0000_PinionSteerAgGroupForBkpSte_0000(write376);
// 		retWrite377 = Rte_Write_PPort_PinionSteerAgGroupForBkpSteerWhl_PinionSteerAgGroupForBkpSteerWhl(write377);
// }
// static void ASW_COM_RX_CSCHIPBHIPBCANFD7Frame03(void)
// {

// 	uint8 read220;
// 		Std_ReturnType retRead220;
// 		uint8 read221;
// 		Std_ReturnType retRead221;
// 		uint8 read222;
// 		Std_ReturnType retRead222;
// 		uint8 read223;
// 		Std_ReturnType retRead223;
// 		uint8 read224;
// 		Std_ReturnType retRead224;
// 		uint8 read225;
// 		Std_ReturnType retRead225;
// 		uint8 read226;
// 		Std_ReturnType retRead226;
// 		uint8 read227;
// 		Std_ReturnType retRead227;
// 		uint8 read228;
// 		Std_ReturnType retRead228;
// 		uint8 read229;
// 		Std_ReturnType retRead229;
// 		uint8 read230;
// 		Std_ReturnType retRead230;
// 		uint8 read231;
// 		Std_ReturnType retRead231;
// 		uint8 read232;
// 		Std_ReturnType retRead232;
// 		uint8 read233;
// 		Std_ReturnType retRead233;
// 		uint8 read234;
// 		Std_ReturnType retRead234;
// 		uint8 read245;
// 			Std_ReturnType retRead245;
// 			uint16 read246;
// 			Std_ReturnType retRead246;
// 			uint8 read247;
// 			Std_ReturnType retRead247;
// 			uint8 read248;
// 			Std_ReturnType retRead248;
// 			uint8 read249;
// 			Std_ReturnType retRead249;
// 	retRead220 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkp_UB_AsyADL3FuncCtrlStsForBkp_UB(&read220);
// 		retRead221 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpADMod_AsyADL3FuncCtrlStsForBkpADMod(&read221);
// 		retRead222 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpChks8_AsyADL3FuncCtrlStsForBkpChks8(&read222);
// 		retRead223 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpCntr4_AsyADL3FuncCtrlStsForBkpCntr4(&read223);
// 		retRead224 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpCtrlSts_AsyADL3FuncCtrlStsForBkpCtrlSts(&read224);
// 		retRead225 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpDataID4_AsyADL3FuncCtrlStsForBkpDataID4(&read225);
// 		retRead226 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpDegraded_AsyADL3FuncCtrlStsForBkpDegraded(&read226);
// 		retRead227 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpQf_AsyADL3FuncCtrlStsForBkpQf(&read227);
// 		retRead228 = Rte_Read_RPort_AsyADL3FuncCtrlStsForBkpSts_AsyADL3FuncCtrlStsForBkpSts(&read228);
// 		retRead229 = Rte_Read_RPort_AsyADModeReqForBkp_UB_AsyADModeReqForBkp_UB(&read229);
// 		retRead230 = Rte_Read_RPort_AsyADModeReqForBkpADActiveReq_AsyADModeReqForBkpADActiveReq(&read230);
// 		retRead231 = Rte_Read_RPort_AsyADModeReqForBkpADDeactiveReq_AsyADModeReqForBkpADDeactiveReq(&read231);
// 		retRead232 = Rte_Read_RPort_AsyADModeReqForBkpChks8_AsyADModeReqForBkpChks8(&read232);
// 		retRead233 = Rte_Read_RPort_AsyADModeReqForBkpCntr4_AsyADModeReqForBkpCntr4(&read233);
// 		retRead234 = Rte_Read_RPort_AsyADModeReqForBkpDataID4_AsyADModeReqForBkpDataID4(&read234);

// 		retRead245 = Rte_Read_RPort_AsyPinionAgReqForBkp_UB_AsyPinionAgReqForBkp_UB(&read245);
// 		retRead246 = Rte_Read_RPort_AsyPinionAgReqForBkpAsyPinionAgR_AsyPinionAgReqForBkpAsyPinionAgR(&read246);
// 		retRead247 = Rte_Read_RPort_AsyPinionAgReqForBkpChks8_AsyPinionAgReqForBkpChks8(&read247);
// 		retRead248 = Rte_Read_RPort_AsyPinionAgReqForBkpCntr4_AsyPinionAgReqForBkpCntr4(&read248);
// 		retRead249 = Rte_Read_RPort_AsyPinionAgReqForBkpDataID4_AsyPinionAgReqForBkpDataID4(&read249);
// }
// static void ASW_COM_RX_CSCHIPBHIPBCanFD7Frame10(void)
// {
// 	Std_ReturnType retRead234;
// 		uint8 read235;
// 		Std_ReturnType retRead235;
// 		uint8 read236;
// 		Std_ReturnType retRead236;
// 		uint8 read237;
// 		Std_ReturnType retRead237;
// 		uint8 read238;
// 		Std_ReturnType retRead238;
// 		uint8 read239;
// 		Std_ReturnType retRead239;
// 		uint8 read240;
// 		Std_ReturnType retRead240;
// 		uint8 read241;
// 		Std_ReturnType retRead241;
// 		uint8 read242;
// 		Std_ReturnType retRead242;
// 		uint8 read243;
// 		Std_ReturnType retRead243;
// 		uint8 read244;
// 		Std_ReturnType retRead244;
// 	retRead235 = Rte_Read_RPort_AsyLatCoDrvReqForBkp_UB_AsyLatCoDrvReqForBkp_UB(&read235);
// 	retRead236 = Rte_Read_RPort_AsyLatCoDrvReqForBkpAsyLatCoDrvR_AsyLatCoDrvReqForBkpAsyLatCoDrvR(&read236);
// 	retRead237 = Rte_Read_RPort_AsyLatCoDrvReqForBkpChks8_AsyLatCoDrvReqForBkpChks8(&read237);
// 	retRead238 = Rte_Read_RPort_AsyLatCoDrvReqForBkpCntr4_AsyLatCoDrvReqForBkpCntr4(&read238);
// 	retRead239 = Rte_Read_RPort_AsyLatCoDrvReqForBkpDataID4_AsyLatCoDrvReqForBkpDataID4(&read239);
// 	retRead240 = Rte_Read_RPort_AsyLatOvrdReqForBkp_UB_AsyLatOvrdReqForBkp_UB(&read240);
// 	retRead241 = Rte_Read_RPort_AsyLatOvrdReqForBkpAsyLatOvrdReq_AsyLatOvrdReqForBkpAsyLatOvrdReq(&read241);
// 	retRead242 = Rte_Read_RPort_AsyLatOvrdReqForBkpChks8_AsyLatOvrdReqForBkpChks8(&read242);
// 	retRead243 = Rte_Read_RPort_AsyLatOvrdReqForBkpCntr4_AsyLatOvrdReqForBkpCntr4(&read243);
// 	retRead244 = Rte_Read_RPort_AsyLatOvrdReqForBkpDataID4_AsyLatOvrdReqForBkpDataID4(&read244);
// }
// static void ASW_COM_PSCMFram01(void)
//  {
// 	uint8 write221 = 0;
// 	Std_ReturnType retWrite221;
// 	uint8 write222 = 0;
// 	Std_ReturnType retWrite222;
// 	retWrite221 = Rte_Write_PPort_TankTurnSteerWhlCfmd_TankTurnSteerWhlCfmd(write221);
// 	retWrite222 = Rte_Write_PPort_TankTurnSteerWhlCfmd_UB_TankTurnSteerWhlCfmd_UB(write222);
 }
void ASW_COM_PSCMIDPSSFram01(uint8* idsData)
{

// 	uint64 IDPSSEvFromPSCMContextData1 = 0;
// 	uint64 IDPSSEvFromPSCMContextData2 = 0;
// 	uint16 IDPSSEvFromPSCMCount = 0;
// 	uint64 IDPSSEvFromPSCMTimestamp = 0;
// 	uint32 IDPSSEvFromPSCMIDSID = 0;
// 	uint8 IDPSSEvFromPSCMContextDataLength = 0;
// 	uint8 IDPSSEvFromPSCMReserve = 0;
// 	uint8 IDPSSEvFromPSCMProtocol = 0;

// 	IDPSSEvFromPSCMProtocol = idsData[0];
// 	IDPSSEvFromPSCMIDSID = (uint32)((uint32)idsData[1]<<24|(uint32)idsData[2]<<16|(uint32)idsData[3]<<8|(uint32)idsData[4]<<0);
// 	IDPSSEvFromPSCMCount = (uint16)((uint16)idsData[5]<<8|(uint16)idsData[6]<<0);
// 	IDPSSEvFromPSCMReserve = idsData[7];
// 	IDPSSEvFromPSCMTimestamp = (uint64)((uint64)idsData[8]<<56|(uint64)idsData[9]<<48|(uint64)idsData[10]<<40|(uint64)idsData[11]<<32|(uint64)idsData[12]<<24|(uint64)idsData[13]<<16|(uint64)idsData[14]<<8|(uint64)idsData[15]<<0);
// 	IDPSSEvFromPSCMContextDataLength = idsData[16];
// 	IDPSSEvFromPSCMContextData1 =  (uint64)((uint64)idsData[17]<<56|(uint64)idsData[18]<<48|(uint64)idsData[19]<<40|(uint64)idsData[20]<<32|(uint64)idsData[21]<<24|(uint64)idsData[22]<<16|(uint64)idsData[23]<<8|(uint64)idsData[24]<<0);
// 	IDPSSEvFromPSCMContextData2 =  (uint64)((uint64)idsData[25]<<56|(uint64)idsData[26]<<48|(uint64)idsData[27]<<40|(uint64)idsData[28]<<32|(uint64)idsData[29]<<24|(uint64)idsData[30]<<16|(uint64)idsData[31]<<8|(uint64)idsData[32]<<0);
// 	Rte_Write_PPort_IDPSSEvFromPSCMContextData1_IDPSSEvFromPSCMContextData1(IDPSSEvFromPSCMContextData1);
// 	Rte_Write_PPort_IDPSSEvFromPSCMContextData2_IDPSSEvFromPSCMContextData2(IDPSSEvFromPSCMContextData2);
// 	Rte_Write_PPort_IDPSSEvFromPSCMContextDataLength_IDPSSEvFromPSCMContextDataLength(IDPSSEvFromPSCMContextDataLength);
// 	Rte_Write_PPort_IDPSSEvFromPSCMCount_IDPSSEvFromPSCMCount(IDPSSEvFromPSCMCount);
// 	Rte_Write_PPort_IDPSSEvFromPSCMIDSID_IDPSSEvFromPSCMIDSID(IDPSSEvFromPSCMIDSID) ;
// 	Rte_Write_PPort_IDPSSEvFromPSCMProtocol_IDPSSEvFromPSCMProtocol(IDPSSEvFromPSCMProtocol);
// 	Rte_Write_PPort_IDPSSEvFromPSCMReserve_IDPSSEvFromPSCMReserve(IDPSSEvFromPSCMReserve) ;
// 	Rte_Write_PPort_IDPSSEvFromPSCMTimestamp_IDPSSEvFromPSCMTimestamp(IDPSSEvFromPSCMTimestamp) ;


 }

// static void ASW_COM_PSCMSACM_SecCanFrame01(void)
//  {
// 	static E2E_ImpleDataType_SACM_SecCanFrame01_PIN SecCanFrame01_PIN_DATA;
// 	static E2E_ImpleDataType_SACM_SecCanFrame01_ADL SecCanFrame01_ADL_DATA;
// 	static E2E_ImpleDataType_SACM_SecCanFrame01_LAT SecCanFrame01_LAT_DATA;
// 	uint8 write275;
// 	Std_ReturnType retWrite275;
// 	uint8 write276;
// 	Std_ReturnType retWrite276;
// 	uint8 write277;
// 	Std_ReturnType retWrite277;
// 	uint8 write278;
// 	Std_ReturnType retWrite278;
// 	uint8 write279;
// 	Std_ReturnType retWrite279;
// 	uint8 write280;
// 	Std_ReturnType retWrite280;
// 	uint8 write281;
// 	Std_ReturnType retWrite281;
// 	uint8 write282;
// 	Std_ReturnType retWrite282;
// 	uint8 write283;
// 	Std_ReturnType retWrite283;
// 	uint8 write284;
// 	Std_ReturnType retWrite284;
// 	uint8 write285;
// 	Std_ReturnType retWrite285;
// 	uint8 write286;
// 	Std_ReturnType retWrite286;
// 	uint8 write287;
// 	Std_ReturnType retWrite287;
// 	uint8 write288;
// 	Std_ReturnType retWrite288;
// 	uint8 write289;
// 	Std_ReturnType retWrite289;
// 	uint8 write290;
// 	Std_ReturnType retWrite290;
// 	uint8 write291;
// 	Std_ReturnType retWrite291;
// 	uint8 write292;
// 	Std_ReturnType retWrite292;
// 	uint8 write293;
// 	Std_ReturnType retWrite293;
// 	uint16 write294;
// 	Std_ReturnType retWrite294;
// 	uint8 write295;
// 	Std_ReturnType retWrite295;
// 	uint16 write296;
// 	Std_ReturnType retWrite296;
// 	uint8 write297;
// 	Std_ReturnType retWrite297;
// 	uint16 write298;
// 	Std_ReturnType retWrite298;
// 	uint8 write299;
// 	Std_ReturnType retWrite299;

// 	sint16 tmp = 0;
// 	if(Tx_SACM_SecCanFrame01_Flag == 0)
// 	{
// 		Tx_SACM_SecCanFrame01_Flag = 1;
// 		//ADL3


// 		write275 = 1;
// 		retWrite275 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrv_UB_ADL3LatCtrlStsForCoDrv_UB(write275);
// 		if(Fv_LKA_ADL3ADMod != 0 && Fv_LKA_ControlSts ==2){
// 			write276 = Fv_LKA_ADL3ADMod; 
// 		}else{
// 			write276 = 0;
// 		}
// 		retWrite276 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvADMod_ADL3LatCtrlStsForCoDrvADMod(write276);
// 		write280 = 0;
// 		write281 = 0;
// 		write282 = 0;
// 		write283 = 3;
// 		write284 = 0; //todo liuyang
// 		write279 = Fv_LKA_ADL3CtrlStsSts;
// 		retWrite279 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvCtrlSts_ADL3LatCtrlStsForCoDrvCtrlSts(write279);
// 		retWrite280 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvDataID4_ADL3LatCtrlStsForCoDrvDataID4(write280);
// 		retWrite281 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvDegraded_ADL3LatCtrlStsForCoDrvDegraded(write281);
// 		retWrite282 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvLatCoDrvSt_ADL3LatCtrlStsForCoDrvLatCoDrvSt(write282);
// 		retWrite283 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvQf_ADL3LatCtrlStsForCoDrvQf(write283);
// 		retWrite284 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvSts_ADL3LatCtrlStsForCoDrvSts(write284);

// 		SecCanFrame01_ADL_DATA.Impl_Sig1 = (write283 << 6) | (write284 << 4) | write281;
// 		SecCanFrame01_ADL_DATA.Impl_Sig2 = (write282 << 3) | (write279 << 2) | write276;
// 		E2E_P11Protect(&E2E_P11ConfigType_SACM_SecCanFrame01_ADL,&E2E_P11ProtectStateType_SACM_SecCanFrame01_ADL,(uint8 *)&SecCanFrame01_ADL_DATA,4);
// 		write277 = SecCanFrame01_ADL_DATA.Impl_Cks;
// 		retWrite277 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvChks8_ADL3LatCtrlStsForCoDrvChks8(write277);
// 		write278 = SecCanFrame01_ADL_DATA.Impl_Cnt;
// 		retWrite278 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvCntr4_ADL3LatCtrlStsForCoDrvCntr4(write278);
// 		write280 = E2E_P11ConfigType_SACM_SecCanFrame01_ADL.DataID >> 8;
// 		retWrite280 = Rte_Write_PPort_ADL3LatCtrlStsForCoDrvDataID4_ADL3LatCtrlStsForCoDrvDataID4(write280);
// 		//LAT
// 		write285 = 1;
// 		retWrite285 = Rte_Write_PPort_LatCtrlModCfmd_UB_LatCtrlModCfmd_UB(write285);
// 		if(((Fv_APA_ControlSts == 2U) || (Fv_DSR_ControlSts == 2U) || (Fv_LKA_ControlSts == 2U)) && Fv_LKA_ADL3ADMod == 0) 
// 		{
// 			write289 = Fv_AdsMod;
// 		}
// 		else
// 		{
// 			write289 = 0;
// 		}
// 		retWrite289 = Rte_Write_PPort_LatCtrlModCfmdLatCtrlMod_LatCtrlModCfmdLatCtrlMod(write289);

// 		SecCanFrame01_LAT_DATA.Impl_Sig1 = write289;
// 		E2E_P11Protect(&E2E_P11ConfigType_SACM_SecCanFrame01_LAT,&E2E_P11ProtectStateType_SACM_SecCanFrame01_LAT,(uint8 *)&SecCanFrame01_LAT_DATA,3);
// 		write286 = SecCanFrame01_LAT_DATA.Impl_Cks;
// 		retWrite286 = Rte_Write_PPort_LatCtrlModCfmdChks8_LatCtrlModCfmdChks8(write286);
// 		write287 = SecCanFrame01_LAT_DATA.Impl_Cnt;
// 		retWrite287 = Rte_Write_PPort_LatCtrlModCfmdCntr4_LatCtrlModCfmdCntr4(write287);
// 		write288 = E2E_P11ConfigType_SACM_SecCanFrame01_LAT.DataID >> 8;
// 		retWrite288 = Rte_Write_PPort_LatCtrlModCfmdDataID4_LatCtrlModCfmdDataID4(write288);
// 		//PIN
// 		write290 = 1;
// 		if(Fv_AngleMidValidFlag == ANGLE_STS_Valid)
// 		{
// 			tmp = ((sint32)Fv_StrAng_Raw*1024 * 3.14 / 180/16 );
// 			//write50 = (uint16)((sint32)(Fv_StrAng - Fv_StrAngOffset)* 1024 * 3.14 / 180 / 10);
// 			if(tmp > 14848)
// 			{
// 				tmp = 14848;
// 				write295 = 0x2;
// 			}
// 			else if(tmp < -14848)
// 			{
// 				tmp = -14848;
// 				write295 = 0x2;
// 			}
// 			else
// 			{
// 				write295 = 0x3;
// 			}

// 			write294 = (uint16)tmp;

// 			tmp = ((sint32)Fv_dStrAng * 128 * 3.14 / 180 / 16);
// 			if(tmp > 6400)
// 			{
// 				tmp = 6400;
// 				write297 = 0x2;
// 			}
// 			else if(tmp < -6400)
// 			{
// 				tmp = -6400;
// 				write297 = 0x2;
// 			}
// 			else
// 			{
// 				write297 = 0x3;
// 			}

// 			write296 = (uint16)tmp;
// 		}
// 		else
// 		{
// 			write294 = 0;//todozmq
// 			write295 = 0x0;
// 			write296 = 0;
// 			write297 = 0x0;
// 		}
// 		retWrite290 = Rte_Write_PPort_PinionSteerAgGroup_UB_PinionSteerAgGroup_UB(write290);
// 		retWrite294 = Rte_Write_PPort_PinionSteerAgGroupPinionSteerAg1_PinionSteerAgGroupPinionSteerAg1(write294);
// 		retWrite295 = Rte_Write_PPort_PinionSteerAgGroupPinionSte_0000_PinionSteerAgGroupPinionSte_0000(write295);//PinionSteerAgGroupPinionSteerAg1Qf    46
// 		retWrite296 = Rte_Write_PPort_PinionSteerAgGroupPinionSteerAgS_PinionSteerAgGroupPinionSteerAgS(write296);
// 		retWrite297 = Rte_Write_PPort_PinionSteerAgGroupPinionSte_0001_PinionSteerAgGroupPinionSte_0001(write297);//PinionSteerAgGroupPinionSteerAgSpd1Qf  62

// 		if(Fv_FaultClass_Torque == 0)
// 		{
// 			tmp = (((sint32)Fv_StrTrq0 *256) / 1024);
// 			if(tmp > 7680)
// 			{
// 				tmp = 7680;
// 				write299 = 0x2;
// 			}
// 			else if(tmp < -7680)
// 			{
// 				tmp = -7680;
// 				write299 = 0x2;
// 			}
// 			else
// 			{
// 				write299 = 0x3;
// 			}

// 			write298 = (uint16)tmp;
// 		}
// 		else
// 		{
// 			write298 = 0;
// 			write299 = 0x0;
// 		}

// 		retWrite298 = Rte_Write_PPort_PinionSteerAgGroupSteerWhlTq_PinionSteerAgGroupSteerWhlTq(write298);
// 		retWrite299 = Rte_Write_PPort_PinionSteerAgGroupSteerWhlTqQf_PinionSteerAgGroupSteerWhlTqQf(write299);
// 		//TODO,ä¿¡å·åä¸Žé€šä¿¡çŸ©é˜µå¯¹ä¸ä¸Šï¼Œæ— æ³•èµ‹å??
// 		SecCanFrame01_PIN_DATA.Impl_Sig1 = write294;
// 		SecCanFrame01_PIN_DATA.Impl_Sig2 = (write294 >> 8);
// 		SecCanFrame01_PIN_DATA.Impl_Sig3 = write296;
// 		SecCanFrame01_PIN_DATA.Impl_Sig4 = (write296 >> 8)|(write295<<6);
// 		SecCanFrame01_PIN_DATA.Impl_Sig5 = write298;
// 		SecCanFrame01_PIN_DATA.Impl_Sig6 = (write298 >> 8)|(write297<<6);
// 		SecCanFrame01_PIN_DATA.Impl_Sig7 = write299;

// 		E2E_P11Protect(&E2E_P11ConfigType_SACM_SecCanFrame01_PIN,&E2E_P11ProtectStateType_SACM_SecCanFrame01_PIN,(uint8 *)&SecCanFrame01_PIN_DATA,9);
// 		write291 = SecCanFrame01_PIN_DATA.Impl_Cks;
// 		retWrite291 = Rte_Write_PPort_PinionSteerAgGroupChks8_PinionSteerAgGroupChks8(write291);
// 		write292 = SecCanFrame01_PIN_DATA.Impl_Cnt;
// 		retWrite292 = Rte_Write_PPort_PinionSteerAgGroupCntr4_PinionSteerAgGroupCntr4(write292);
// 		write293 = E2E_P11ConfigType_SACM_SecCanFrame01_PIN.DataID >> 8;
// 		retWrite293 = Rte_Write_PPort_PinionSteerAgGroupDataID4_PinionSteerAgGroupDataID4(write293);		
// 	}
//  }
// static void ASW_COM_PSCMSACMFram01(void)
//  {
// 	    static E2E_ImpleDataType_SACMFram01_STE SACMFram01_STE_DATA;
// 		static E2E_ImpleDataType_SACMFram01_DRV SACMFram01_DRV_DATA;
// 	    uint8 write259;
// 		Std_ReturnType retWrite259;
// 		uint8 write260;
// 		Std_ReturnType retWrite260;
// 		uint8 write261;
// 		Std_ReturnType retWrite261;
// 		uint8 write262;
// 		Std_ReturnType retWrite262;
// 		uint8 write263;
// 		Std_ReturnType retWrite263;
// 		uint8 write264;
// 		Std_ReturnType retWrite264;
// 		uint8 write265;
// 		Std_ReturnType retWrite265;
// 		uint8 write266;
// 		Std_ReturnType retWrite266;
// 		uint8 write267;
// 		Std_ReturnType retWrite267;
// 		uint8 write268;
// 		Std_ReturnType retWrite268;
// 		uint8 write269;
// 		Std_ReturnType retWrite269;
// 		uint8 write270;
// 		Std_ReturnType retWrite270;
// 		uint8 write271;
// 		Std_ReturnType retWrite271;
// 		uint8 write272;
// 		Std_ReturnType retWrite272;
// 		uint8 write273;
// 		Std_ReturnType retWrite273;
// 		uint8 write274;
// 		Std_ReturnType retWrite274;

// 		static uint16 FFT1 = 0;

// 		if(Tx_SACMFram01_Flag == 0)
// 		{
// 			Tx_SACMFram01_Flag = 1;
// 			write259 = 1;
// 			/*
// 			 * Rte_IRead_RE_COM_SWC_RPort_FV_TAS_TRQ_FVs16q10_TAS_StrTrq_0();
// 			 * Rte_IRead_RE_COM_SWC_RPort_FV_TAS_ANG_FVs16q4_TAS_dStrAng_tas();
// 			 *reqID: 134227
// 			 * */
// 			if(((Fv_StrTrq0 > Cal_EMA_DrvrSteerActvSteerWhlTq) || (Fv_StrTrq0 < -Cal_EMA_DrvrSteerActvSteerWhlTq)) ||
// 			   ((Tv_dStrAng > Cal_EMA_DrvrSteerActvPinionSteerAgSpd) || (Tv_dStrAng < -Cal_EMA_DrvrSteerActvPinionSteerAgSpd)))
// 			{
// 				if(FFT1 < 200)//5ms/cycle
// 				{
// 					FFT1++;
// 				}
// 				else
// 				{
// 					write263 = 1;
// 				}
// 			}
// 			else
// 			{
// 				if(FFT1 > 0)
// 				{
// 					FFT1--;
// 				}
// 				else
// 				{
// 					write263 = 0;
// 				}
// 			}
// 			retWrite259 = Rte_Write_PPort_DrvrSteerActv_UB_DrvrSteerActv_UB(write259);
// 			retWrite263 = Rte_Write_PPort_DrvrSteerActvDrvrSteerActv_DrvrSteerActvDrvrSteerActv(write263);
			
// 			SACMFram01_DRV_DATA.Impl_Sig1 = write263;
// 			E2E_P11Protect(&E2E_P11ConfigType_SACMFram01_DRV,&E2E_P11ProtectStateType_SACMFram01_DRV,(uint8 *)&SACMFram01_DRV_DATA,3);
// 			write260 = SACMFram01_DRV_DATA.Impl_Cks;
// 			retWrite260 = Rte_Write_PPort_DrvrSteerActvChks8_DrvrSteerActvChks8(write260);
// 			write261 = SACMFram01_DRV_DATA.Impl_Cnt;
// 			retWrite261 = Rte_Write_PPort_DrvrSteerActvCntr4_DrvrSteerActvCntr4(write261);
// 			write262 = E2E_P11ConfigType_SACMFram01_DRV.DataID >> 8;
// 			retWrite262 = Rte_Write_PPort_DrvrSteerActvDataID4_DrvrSteerActvDataID4(write262);
// 			//STE
// 			write264 = 1;
// 			retWrite264 = Rte_Write_PPort_SteerExtFctSts_UB_SteerExtFctSts_UB(write264);
// 			write268 =( (Fv_LKA_ControlSts == 2) || (Fv_APA_ControlSts == 2)||(Fv_DSR_ControlSts == 2));
// 			retWrite268 = Rte_Write_PPort_SteerExtFctStsDrvrSteerOvrd_SteerExtFctStsDrvrSteerOvrd(write268);
// 			write269 = Fv_LKA_ExtFctLowerLimActive;
// 			retWrite269 = Rte_Write_PPort_SteerExtFctStsExtFctLowerLimActi_SteerExtFctStsExtFctLowerLimActi(write269);
// 			write270 = Fv_LKA_AngleSpdLimit;
// 			retWrite270 = Rte_Write_PPort_SteerExtFctStsExtFctRateLimActiv_SteerExtFctStsExtFctRateLimActiv(write270);
// 			write271 = Fv_LKA_ExtFctUpperLimActive;
// 			retWrite271 = Rte_Write_PPort_SteerExtFctStsExtFctUpperLimActi_SteerExtFctStsExtFctUpperLimActi(write271);
// 			write272 = (Fv_LKA_ExtFctLowerLimActive|Fv_LKA_AngleSpdLimit|Fv_LKA_ExtFctUpperLimActive);
// 			retWrite272 = Rte_Write_PPort_SteerExtFctStsExtSafeLimActive_SteerExtFctStsExtSafeLimActive(write272);
// 			write273 = 0;
// 			retWrite273 = Rte_Write_PPort_SteerExtFctStsLatAgReqNotInRange_SteerExtFctStsLatAgReqNotInRange(write273);
// 			write274 = 0;
// 			retWrite274 = Rte_Write_PPort_SteerExtFctStsLatCtrlReqNotInRan_SteerExtFctStsLatCtrlReqNotInRan(write274);
// 			SACMFram01_STE_DATA.Impl_Sig1 = write274 << 6 | write273 << 5 | write272 << 4 | write271 << 3 | write270 << 2 | write269 << 1 | write268; 
// 			E2E_P11Protect(&E2E_P11ConfigType_SACMFram01_STE,&E2E_P11ProtectStateType_SACMFram01_STE,(uint8 *)&SACMFram01_STE_DATA,3);
// 			write265 = SACMFram01_STE_DATA.Impl_Cks;
// 			retWrite265 = Rte_Write_PPort_SteerExtFctStsChks8_SteerExtFctStsChks8(write265);
// 			write266 = SACMFram01_STE_DATA.Impl_Cnt;
// 			retWrite266 = Rte_Write_PPort_SteerExtFctStsCntr4_SteerExtFctStsCntr4(write266);
// 			write267 = E2E_P11ConfigType_SACMFram01_STE.DataID >> 8;
// 			retWrite267 = Rte_Write_PPort_SteerExtFctStsDataID4_SteerExtFctStsDataID4(write267);					
// 		}
//  }
// static void ASW_COM_PSCMSACMFram02(void)
//  {
// 	 static E2E_ImpleDataType_SACMFram02_SST SACMFram02_SST_DATA;
// 	 static E2E_ImpleDataType_SACMFram02_SSS SACMFram02_SSS_DATA;
// 	uint8 write245;
// 		Std_ReturnType retWrite245;
// 		uint8 write246;
// 		Std_ReturnType retWrite246;
// 		uint8 write247;
// 		Std_ReturnType retWrite247;
// 		uint8 write248;
// 		Std_ReturnType retWrite248;
// 		uint8 write249;
// 		Std_ReturnType retWrite249;
// 		uint8 write250;
// 		Std_ReturnType retWrite250;
// 		uint8 write251;
// 		Std_ReturnType retWrite251;
// 		uint8 write252;
// 		Std_ReturnType retWrite252;
// 		uint8 write253;
// 		Std_ReturnType retWrite253;
// 		uint8 write254;
// 		Std_ReturnType retWrite254;
// 		uint16 write255;
// 		Std_ReturnType retWrite255;
// 		uint8 write256;
// 		Std_ReturnType retWrite256;
// 		uint8 write257;
// 		Std_ReturnType retWrite257;
// 		uint8 write258;
// 		Std_ReturnType retWrite258;

// 		static uint16 startcnt = 0;
// 		static uint16 stopcnt1 = 0;
// 		static uint16 stopcnt2 = 0;
// 		sint16 motortrq = 0;

// 		if(Tx_SACMFram02_Flag == 0)
// 		{
// 			Tx_SACMFram02_Flag = 1;
// 			write245 = 1;
// 			retWrite245 = Rte_Write_PPort_SteerServoSts_UB_SteerServoSts_UB(write245);
// 			if((Fv_APA_ControlSts > 2) || (Fv_LKA_ControlSts > 2))
// 			{
// 				write246 = 1;
// 			}
// 			else
// 			{
// 				write246 = 0;
// 			}
// 			retWrite246 = Rte_Write_PPort_SteerServoSts1_SteerServoSts1(write246);

// 			SACMFram02_SSS_DATA.Impl_Sig1 = write246;
// 			E2E_P11Protect(&E2E_P11ConfigType_SACMFram02_SSS,&E2E_P11ProtectStateType_SACMFram02_SSS,(uint8 *)&SACMFram02_SSS_DATA,3);
// 			write247 = SACMFram02_SSS_DATA.Impl_Cks;
// 			retWrite247 = Rte_Write_PPort_SteerServoStsChks8_SteerServoStsChks8(write247);
// 			write248 = SACMFram02_SSS_DATA.Impl_Cnt;
// 			retWrite248 = Rte_Write_PPort_SteerServoStsCntr4_SteerServoStsCntr4(write248);
// 			write249 = E2E_P11ConfigType_SACMFram02_SSS.DataID >> 8;
// 			retWrite249 = Rte_Write_PPort_SteerServoStsDataID4_SteerServoStsDataID4(write249);			
// 			//
// 			write250 = 1;
// 			retWrite250 = Rte_Write_PPort_SteerStsToParkAssi_UB_SteerStsToParkAssi_UB(write250);
// 			write254 = Fv_SteerStsToParkAssi;//Fv_APA_AbortFeedBack;
// 			retWrite254 = Rte_Write_PPort_SteerStsToParkAssiSteerStsToPark_SteerStsToParkAssiSteerStsToPark(write254);
// 			SACMFram02_SST_DATA.Impl_Sig1 = write254;
// 			E2E_P11Protect(&E2E_P11ConfigType_SACMFram02_SST,&E2E_P11ProtectStateType_SACMFram02_SST,(uint8 *)&SACMFram02_SST_DATA,3);
// 			write251 = SACMFram02_SST_DATA.Impl_Cks;
// 			retWrite251 = Rte_Write_PPort_SteerStsToParkAssiChks8_SteerStsToParkAssiChks8(write251);
// 			write252 = SACMFram02_SST_DATA.Impl_Cnt;
// 			retWrite252 = Rte_Write_PPort_SteerStsToParkAssiCntr4_SteerStsToParkAssiCntr4(write252);
// 			write253 = E2E_P11ConfigType_SACMFram02_SST.DataID >> 8;
// 			retWrite253 = Rte_Write_PPort_SteerStsToParkAssiDataID4_SteerStsToParkAssiDataID4(write253);


// 			motortrq = ((Fv_MotorCurrent_Qact1 + Fv_MotorCurrent_Qact2) * 6 * 256)/19200;
// 			write255 = (uint16)motortrq;
// 			write256 = 1;
// 			retWrite255 = Rte_Write_PPort_TqAssAddl_TqAssAddl(write255);
// 			retWrite256 = Rte_Write_PPort_TqAssAddl_UB_TqAssAddl_UB(write256);

// 			/*
// 			 * reqID: 88140
// 			 * */
// 			write257 = 0;
// 			write258 = 1;
// 			if(((Tv_dStrAng > Cal_DParkManeuverSpd)
// 				|| (Tv_dStrAng < -Cal_DParkManeuverSpd))
// 					&& (Fv_VehSpd < 480))
// 			{
// 				if(startcnt < Cal_TParkManeuverStart)
// 				{
// 					startcnt ++;
// 				}
// 				else
// 				{
// 					write257 = 1;
// 					stopcnt1 = Cal_TParkManeuverStop;
// 				}
// 			}
// 			else
// 			{
// 				startcnt = 0;
// 			}


// 			if((Tv_dStrAng < Cal_DParkManeuverSpd) &&
// 				(Tv_dStrAng > -Cal_DParkManeuverSpd))
// 			{
// 				if(stopcnt1 > 0)
// 				{
// 					stopcnt1 --;
// 					write257 = 1;
// 				}
// 			}
// 			else
// 			{
// 				if(stopcnt1 > 0)
// 				{
// 					stopcnt1 = Cal_TParkManeuverStop;
// 					write257 = 1;
// 				}
// 			}

// 			if((Fv_AdsMod <= 15)
// 				&& (Fv_AdsMod >= 13))
// 			{
// 				write257 = 1;
// 			}

// 			if(((Tv_dStrAng > Cal_DEvasiveManeuverSpd)
// 				|| (Tv_dStrAng < -Cal_DEvasiveManeuverSpd))
// 					&& ((Tv_StrAng_Raw > Cal_AEvasiveManeuverAng)
// 					|| (Tv_StrAng_Raw < -Cal_AEvasiveManeuverAng))
// 					&& (Fv_VehSpd > Cal_VEvasiveManeuverVehSpd))
// 			{
// 				write257 = 2;
// 				stopcnt2 = Cal_TEvasiveManeuverStop;
// 			}

// 			if((Tv_dStrAng < Cal_DEvasiveManeuverSpd) &&
// 				(Tv_dStrAng > -Cal_DEvasiveManeuverSpd))
// 			{
// 				if(stopcnt2 > 0)
// 				{
// 					stopcnt2 --;
// 					write257 = 2;
// 				}
// 			}
// 			else
// 			{
// 				if(stopcnt2 > 0)
// 				{
// 					stopcnt2 = Cal_TEvasiveManeuverStop;
// 					write257 = 2;
// 				}
// 			}//todozmq
// 			retWrite257 = Rte_Write_PPort_UBoostReqBySteerFrnt_UBoostReqBySteerFrnt(write257);
// 			retWrite258 = Rte_Write_PPort_UBoostReqBySteerFrnt_UB_UBoostReqBySteerFrnt_UB(write258);
// 		}
//  }
// static void ASW_COM_PSCMSACMFram03(void)
//  {
// 	uint16 write241;
// 	Std_ReturnType retWrite241;
// 	uint8 write242;
// 	Std_ReturnType retWrite242;
// 	uint16 write243 = 0;
// 	Std_ReturnType retWrite243;
// 	uint8 write244 = 0;
// 	Std_ReturnType retWrite244;
// 	uint8 steerfestvb = 0;
// 	sint32 steerfest = 0;
// 	if(Fv_HighFailFlag > 0)
// 	{
// 		steerfestvb = 0;
// 		steerfest = 0;
// 	}
// 	else
// 	{
// 		steerfestvb = 1;
// 		steerfest = (sint16)((Fv_TCL_LoadEst * 2 / 180) * 18000);
// 	}

// 	write241 = (uint16)steerfest;
// 	retWrite241 = Rte_Write_PPort_FrntSteerFEstimd1_FrntSteerFEstimd1(write241);
// 	write242 = steerfestvb;
// 	retWrite242 = Rte_Write_PPort_FrntSteerFEstimd1_UB_FrntSteerFEstimd1_UB(write242);

// 	if((Fv_LKA_ControlSts == 2)||(Fv_LKA_LimitTorque!=0))
// 	{
// 		write243 = Fv_LKA_LimitTorque/4;
// 	}
// 	else if((Fv_DSR_ControlSts == 2) ||(Fv_AdsTrqReq!=0))
// 	{
// 		write243  = -Fv_AdsTrqReq/4;
// 	}
// 	else
// 	{
// 		write243 = 0;
// 	}

// 	write244 = 1;
// 	retWrite243 = Rte_Write_PPort_SteerWhlTqAddl_SteerWhlTqAddl(write243);
// 	retWrite244 = Rte_Write_PPort_SteerWhlTqAddl_UB_SteerWhlTqAddl_UB(write244);

//  }

// static void ASW_COM_PSCMSACMFram04(void)
//  {
// 	uint16 write239 = 0;
// 	Std_ReturnType retWrite239;
// 	uint8 write240 = 0;
// 	Std_ReturnType retWrite240;
// 	sint16 park_ang_limit = 0;

// 	park_ang_limit = (sint16)(((sint32)Tv_SE_RightMaxAng)*1117/1000);

// 	write239 = park_ang_limit;

// 	write240 = 1;
//  	retWrite239 = Rte_Write_PPort_PinionSteerAgMax1_PinionSteerAgMax1(write239);
// 	retWrite240 = Rte_Write_PPort_PinionSteerAgMax1_UB_PinionSteerAgMax1_UB(write240);
//  }
// static void ASW_COM_PSCMSFCMFram01(void)
//  {
// 	static E2E_ImpleDataType_SFCMBCCanFDFrame01 SFCMBCCanFDFrame01_DATA;
// 	    uint8 write223;
// 		Std_ReturnType retWrite223;
// 		uint8 write224;
// 		Std_ReturnType retWrite224;
// 		uint8 write225;
// 		Std_ReturnType retWrite225;
// 		uint8 write226;
// 		Std_ReturnType retWrite226;
// 		uint8 write227;
// 		Std_ReturnType retWrite227;
// 		uint8 write228;
// 		Std_ReturnType retWrite228;
// 		uint8 write229;
// 		Std_ReturnType retWrite229;
// 		uint8 write230;
// 		Std_ReturnType retWrite230;

// 		static sint32 integvalue = 0;
// 		static sint32 supplycnt = 0;

// 		if (Tx_SFCMBCCanFDFrame01_Flag == 0)
// 		{
// 			Tx_SFCMBCCanFDFrame01_Flag = 1;

// 			write223 = 1;
// 			retWrite223 = Rte_Write_PPort_DrvrSteerWhlHldGroup_UB_DrvrSteerWhlHldGroup_UB(write223);

// 			write227 = Fv_DrvrSteerWhlHld;

// 			write228 = Fv_DrvrSteerWhlHldQly;

// 			retWrite227 = Rte_Write_PPort_DrvrSteerWhlHldGroupDrvrSteerWhl_DrvrSteerWhlHldGroupDrvrSteerWhl(write227);//DrvrSteerWhlHldGroupDrvrSteerWhlHld  24
// 			retWrite228 = Rte_Write_PPort_DrvrSteerWhlHldGroupDrvrSte_0000_DrvrSteerWhlHldGroupDrvrSte_0000(write228);//DrvrSteerWhlHldGroupDrvrSteerWhlHldQly  26
// 			//TODO,ä¿¡å·åä¸ä¸?è‡?
// 			SFCMBCCanFDFrame01_DATA.Impl_Sig1 = write227|(write228<<2);

// 			E2E_P11Protect(&E2E_P11ConfigType_SFCMBCCanFDFrame01,&E2E_P11ProtectStateType_SFCMBCCanFDFrame01,(uint8 *)&SFCMBCCanFDFrame01_DATA,3);
// 			write224 = SFCMBCCanFDFrame01_DATA.Impl_Cks;
// 			retWrite224 = Rte_Write_PPort_DrvrSteerWhlHldGroupChks8_DrvrSteerWhlHldGroupChks8(write224);
// 			write225 = SFCMBCCanFDFrame01_DATA.Impl_Cnt;
// 			retWrite225 = Rte_Write_PPort_DrvrSteerWhlHldGroupCntr4_DrvrSteerWhlHldGroupCntr4(write225);
// 			//write226 = SFCMBCCanFDFrame01_DATA.DataID >> 8;
// 			write226 = E2E_P11ConfigType_SFCMBCCanFDFrame01.DataID>> 8;
// 			retWrite226 = Rte_Write_PPort_DrvrSteerWhlHldGroupDataID4_DrvrSteerWhlHldGroupDataID4(write226);
// 			/*
// 				 * req: 80053
// 				 * */
// 			//SteerErrReq=4 æ¥‚æ¨»ä¿¯éŽ´æ ¬ï¿½å‘¬ç¶†é˜å¬¶ç´™ç»‰îˆšåžŽé”›å¤ˆï¿½ï¿½(çå¿Žç°?9.5)
// 			//SteerErrReq=3 éŽµî… ç…©æ·‡â€³å½¿æ¶“ãˆ ã‘éŠ†ä½¸å¾æµ æ ¦ç¬‰æ¶“ãˆ ã‘é”â•å§é¨å‹¬æ™ é—…æº¿ï¿½ï¿½
// 			//SteerErrReq=2 é”â•å§æ¶“ãˆ ã‘é’ï¿½20%æµ ãƒ¤ç¬…é¨å‹¬æ™ é—…ï¿½(é¢é›å¸‡æµ£åºç°¬8.3V?)
// 			//SteerErrReq=1 é†å‚›æ¤‚æ¶“å¶‡æ•¤
// 			if(((Fv_HighFailFlag > 0)&&(Fv_FaultClass_Torque == 0 ))
// 					||(Fv_SysPowerRelay <= 1062)
// 					|| ((Fv_LowFailFlag > 0)&&(Fv_TempLevel != 2)))/*é¢é›å¸‡æµ£åºç°¬8.3*/
// 			{
// 				write229 = 2;
// 			}
// 			else if(Fv_FaultClass_Torque > 0 )/*éŽµî… ç…©æ·‡â€³å½¿éå‘´æ®?*/
// 			{
// 				write229 = 3;
// 			}
// 			else{
// 				write229 = 0;
// 			}
// 			//æµ£åº¡å¸‡ç»‰îˆšåžŽ
// 			if(Fv_VehSpd > Cal_SplyVMonVehSpdThd)/*æžï¹‚ï¿½ç†»ç§?20kph*/
// 			{
// 				if(integvalue > Cal_MaxIntglSplyVal)
// 				{
// 					integvalue = Cal_MaxIntglSplyVal;
// 				}
// 				else if(integvalue < -Cal_MaxIntglSplyVal)
// 				{
// 					integvalue = -Cal_MaxIntglSplyVal;
// 				}
// 				else
// 				{
// 					integvalue = integvalue + Cal_SupplyVMonThd - Fv_SysPowerRelay;
// 				}
// 			}
// 			else
// 			{
// 				integvalue = 0;
// 			}

// 			if(((write229 == 0) && (integvalue >= Cal_MaxIntglSplyVal))||
// 				(Fv_TempLevel == 2)||((Fv_SysPowerRelay > 1062)&&(Fv_SysPowerRelay < 1216) ))/*æµ£åºç°?9.5V éŽ´æ ¬ï¿½å‘´ç®å¨“â•‚æ™ é—…ï¿½*/
// 			{
// 				write229 = 4;
// 					supplycnt = 5000; /*éŽ­ãˆ î˜²å¯¤æƒ°ç¹œ5s   88139*/
// 			}
// 			if((write229 == 0) && (supplycnt > 0))
// 			{
// 				write229 = 4;
// 				supplycnt --;
// 			}
// 			retWrite229 = Rte_Write_PPort_SteerErrReq_SteerErrReq(write229);

// 			write230 = 1;
// 			retWrite230 = Rte_Write_PPort_SteerErrReq_UB_SteerErrReq_UB(write230);

// 		}
		

//  }
// void ASW_COM_PSCMBCCanFDFram01(void)
// {
// 	uint8 ReqMsg = 1;
// 	uint8 ReqMsgPSCM_UB = 1;
// Rte_Write_PPort_TripResetSyncReqMsgPSCM_TripResetSyncReqMsgPSCM(ReqMsg);
// Rte_Write_PPort_TripResetSyncReqMsgPSCM_UB_TripResetSyncReqMsgPSCM_UB(ReqMsgPSCM_UB);
// }
// static void ASW_COM_PSCMSFCMFram03(void)
//  {
// 	uint8 write221 = 0;
// 	Std_ReturnType retWrite221;
// 	uint8 write222 = 0;
// 	Std_ReturnType retWrite222;
// 	retWrite221 = Rte_Write_PPort_TankTurnSteerWhlCfmd_TankTurnSteerWhlCfmd(write221);
// 	retWrite222 = Rte_Write_PPort_TankTurnSteerWhlCfmd_UB_TankTurnSteerWhlCfmd_UB(write222);
//  }

// static void ASW_COM_RX_CSCBCMCore_SecCanFrame01(void)
// {
// 	static E2E_ImpleDataType_SecCanFrame01_ADF SecCanFrame01_ADF_DATA;
// 	static E2E_ImpleDataType_SecCanFrame01_APA SecCanFrame01_APA_DATA;
// 	static E2E_ImpleDataType_SecCanFrame01_AAM SecCanFrame01_AAM_DATA;
// 	static E2E_ImpleDataType_SecCanFrame01_ALO SecCanFrame01_ALO_DATA;	
// 	uint8 read185;
// 	Std_ReturnType retRead185;
// 	uint8 read186;
// 	Std_ReturnType retRead186;
// 	uint8 read187;
// 	Std_ReturnType retRead187;
// 	uint8 read188;
// 	Std_ReturnType retRead188;
// 	uint8 read189;
// 	Std_ReturnType retRead189;
// 	uint8 read190;
// 	Std_ReturnType retRead190;
// 	uint8 read191;
// 	Std_ReturnType retRead191;
// 	uint8 read192;
// 	Std_ReturnType retRead192;
// 	uint8 read193;
// 	Std_ReturnType retRead193;
// 	uint8 read194;
// 	Std_ReturnType retRead194;
// 	uint8 read195;
// 	Std_ReturnType retRead195;
// 	uint8 read196;
// 	Std_ReturnType retRead196;
// 	uint8 read197;
// 	Std_ReturnType retRead197;
// 	uint8 read198;
// 	Std_ReturnType retRead198;
// 	uint8 read199;
// 	Std_ReturnType retRead199;
// 	uint8 read200;
// 	Std_ReturnType retRead200;
// 	uint8 read201;
// 	Std_ReturnType retRead201;
// 	uint8 read202;
// 	Std_ReturnType retRead202;
// 	uint8 read203;
// 	Std_ReturnType retRead203;
// 	uint8 read204;
// 	Std_ReturnType retRead204;
// 	uint8 read205;
// 	Std_ReturnType retRead205;
// 	uint16 read206;
// 	Std_ReturnType retRead206;
// 	uint8 read207;
// 	Std_ReturnType retRead207;
// 	uint8 read208;
// 	Std_ReturnType retRead208;
// 	uint8 read209;
// 	Std_ReturnType retRead209;
// 	static uint16 cnt = 0;
// 	sint16 agreq = 0;
// 	uint8 ret = 0;

// 	if(COMRxFlag[CANBUS_ID_0x50] == 0xAA)
// 	{
// 	 COMRxFlag[CANBUS_ID_0x50] = 0;//ï¿½ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ä°´ï¿½Õ½ï¿½ï¿½Õ±ï¿½ï¿½Äµï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿?

// 	  cnt=0;//ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½0
// 	  COMRxLostFlag[CANBUS_ID_0x50] = 0;
// 	    retRead185 = Rte_Read_RPort_AsyADL3FuncCtrlSts_UB_AsyADL3FuncCtrlSts_UB(&read185);
// 	  	retRead186 = Rte_Read_RPort_AsyADL3FuncCtrlStsADMod_AsyADL3FuncCtrlStsADMod(&read186);
// 	  	retRead187 = Rte_Read_RPort_AsyADL3FuncCtrlStsChks8_AsyADL3FuncCtrlStsChks8(&read187);
// 	  	retRead188 = Rte_Read_RPort_AsyADL3FuncCtrlStsCntr4_AsyADL3FuncCtrlStsCntr4(&read188);
// 	  	retRead189 = Rte_Read_RPort_AsyADL3FuncCtrlStsCtrlSts_AsyADL3FuncCtrlStsCtrlSts(&read189);
// 	  	retRead190 = Rte_Read_RPort_AsyADL3FuncCtrlStsDataID4_AsyADL3FuncCtrlStsDataID4(&read190);
// 	  	retRead191 = Rte_Read_RPort_AsyADL3FuncCtrlStsDegraded_AsyADL3FuncCtrlStsDegraded(&read191);
// 	  	retRead192 = Rte_Read_RPort_AsyADL3FuncCtrlStsQf_AsyADL3FuncCtrlStsQf(&read192);
// 	  	retRead193 = Rte_Read_RPort_AsyADL3FuncCtrlStsSts_AsyADL3FuncCtrlStsSts(&read193);

// 		SecCanFrame01_ADF_DATA.Impl_Cks = read187;
// 		SecCanFrame01_ADF_DATA.Impl_Cnt = read190 << 4 | read188;
// 		SecCanFrame01_ADF_DATA.Impl_Sig1 = read193 << 6 | read192 << 4 | read191;
// 		SecCanFrame01_ADF_DATA.Impl_Sig2 = read189 << 1 | read186;
		
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame01_ADF,&E2E_P11CheckStateType_SecCanFrame01_ADF,(uint8 *)&SecCanFrame01_ADF_DATA,4);

// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame01_ADF.Status == 0)) || (read187 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x50] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x50] = 2;
		
// 		}

// 	  	retRead194 = Rte_Read_RPort_AsyADModeReq_UB_AsyADModeReq_UB(&read194);
// 	  	retRead195 = Rte_Read_RPort_AsyADModeReqADActiveReq_AsyADModeReqADActiveReq(&read195);

// 	  	retRead196 = Rte_Read_RPort_AsyADModeReqADDeactiveReq_AsyADModeReqADDeactiveReq(&read196);
// 	  	retRead197 = Rte_Read_RPort_AsyADModeReqChks8_AsyADModeReqChks8(&read197);
// 	  	retRead198 = Rte_Read_RPort_AsyADModeReqCntr4_AsyADModeReqCntr4(&read198);
// 	  	retRead199 = Rte_Read_RPort_AsyADModeReqDataID4_AsyADModeReqDataID4(&read199);

// 		SecCanFrame01_AAM_DATA.Impl_Cks = read197;
// 		SecCanFrame01_AAM_DATA.Impl_Cnt = read199 << 4 | read198;
// 		SecCanFrame01_AAM_DATA.Impl_Sig1 = read196 << 2 | read195;
		
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame01_AAM,&E2E_P11CheckStateType_SecCanFrame01_AAM,(uint8 *)&SecCanFrame01_AAM_DATA,3);

// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame01_AAM.Status == 0)) || (read197 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x50] = 0;
// 			Fv_NOPMod = read195;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x50] = 2;
			
// 		}

// 	  	retRead200 = Rte_Read_RPort_AsyLatOvrdReq_UB_AsyLatOvrdReq_UB(&read200);
// 	  	retRead201 = Rte_Read_RPort_AsyLatOvrdReqAsyLatOvrdReq_AsyLatOvrdReqAsyLatOvrdReq(&read201);
// 	  	retRead202 = Rte_Read_RPort_AsyLatOvrdReqChks8_AsyLatOvrdReqChks8(&read202);
// 	  	retRead203 = Rte_Read_RPort_AsyLatOvrdReqCntr4_AsyLatOvrdReqCntr4(&read203);
// 	  	retRead204 = Rte_Read_RPort_AsyLatOvrdReqDataID4_AsyLatOvrdReqDataID4(&read204);

// 		SecCanFrame01_ALO_DATA.Impl_Cks = read202;
// 		SecCanFrame01_ALO_DATA.Impl_Cnt = read204 << 4 | read203;
// 		SecCanFrame01_ALO_DATA.Impl_Sig1 = read201;
		
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame01_ALO,&E2E_P11CheckStateType_SecCanFrame01_ALO,(uint8 *)&SecCanFrame01_ALO_DATA,3);

// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame01_ALO.Status == 0)) || (read202 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x50] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x50] = 2;
		
// 		}		
// 	  	retRead205 = Rte_Read_RPort_AsyPinionAgReqSafe_UB_AsyPinionAgReqSafe_UB(&read205);
// 	  	retRead206 = Rte_Read_RPort_AsyPinionAgReqSafeAsyPinionAgReq_AsyPinionAgReqSafeAsyPinionAgReq(&read206);
// 	  	retRead207 = Rte_Read_RPort_AsyPinionAgReqSafeChks8_AsyPinionAgReqSafeChks8(&read207);
// 	  	retRead208 = Rte_Read_RPort_AsyPinionAgReqSafeCntr4_AsyPinionAgReqSafeCntr4(&read208);
// 	  	retRead209 = Rte_Read_RPort_AsyPinionAgReqSafeDataID4_AsyPinionAgReqSafeDataID4(&read209);
// 		SecCanFrame01_APA_DATA.Impl_Cks = read207;
// 		SecCanFrame01_APA_DATA.Impl_Cnt = read209 << 4 | read208;
// 		SecCanFrame01_APA_DATA.Impl_Sig1 = read206;
// 		SecCanFrame01_APA_DATA.Impl_Sig2 = read206 >> 8;
		
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame01_APA,&E2E_P11CheckStateType_SecCanFrame01_APA,(uint8 *)&SecCanFrame01_APA_DATA,4);
// 		/*if(read205 == 1){
// 			Fv_AdsAgUBInvalid_flag = 0;
// 		}else{
// 			Fv_AdsAgUBInvalid_flag = 1;
// 		}*/ //todo liuyang
// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame01_APA.Status == 0)) || (read207 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x50] = 0;
// 			agreq = (sint16)(((sint64)((sint32)read206 - 14848)*16*RAD_TO_DEG/102400000));
	
// 			if(agreq > 14848)
// 			{
// 				Fv_AdsAgReq = 14848;
// 			}
// 			else if(agreq < -14848)
// 			{
// 				Fv_AdsAgReq = -14848;
// 			}
// 			else
// 			{
// 				Fv_AdsAgReq =  agreq ;
// 			}
// 			Fv_AdsAgInvalid_flag = 0;
// 			if(Fv_EXT_SpdValidFlag != 1){
// 				Fv_AdsAgReq = 0;
// 			}
// 		}
// 		else
// 		{
// 			Fv_AdsAgInvalid_flag = 1;
// 			COMRxVailFlag[CANBUS_ID_0x50] = 2;
			
// 		}		
// 	}
// 	else
// 	{//ï¿½ï¿½Ê§

// 		cnt ++;
// 		if(cnt >= 4)//ï¿½ï¿½ï¿½Õµï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Äµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// 		{
// 			COMRxLostFlag[CANBUS_ID_0x50] = 0xAA;
// 			cnt = 4;
// 		}
// 	}
// }
// static void ASW_COM_RX_CSCBCMCore_SecCanFrame02(void)
// {
// 	static E2E_ImpleDataType_SecCanFrame02_VSL SecCanFrame02_VSL_DATA;
// 	static E2E_ImpleDataType_SecCanFrame02_BPP SecCanFrame02_BPP_DATA;	
// 	uint8 read172;
// 		Std_ReturnType retRead172;
// 		uint8 read173;
// 		Std_ReturnType retRead173;
// 		uint8 read174;
// 		Std_ReturnType retRead174;
// 		uint8 read175;
// 		Std_ReturnType retRead175;
// 		uint8 read176;
// 		Std_ReturnType retRead176;
// 		uint8 read177;
// 		Std_ReturnType retRead177;
// 		uint8 read178;
// 		Std_ReturnType retRead178;
// 		uint8 read179;
// 		Std_ReturnType retRead179;
// 		uint16 read180;
// 		Std_ReturnType retRead180;
// 		uint8 read181;
// 		Std_ReturnType retRead181;
// 		uint8 read182;
// 		Std_ReturnType retRead182;
// 		uint8 read183;
// 		Std_ReturnType retRead183;
// 		uint8 read184;
// 		Std_ReturnType retRead184;
// 	uint8 vehspdvb = 0;
// 	uint8 vehspdqf = 0;
// 	static uint16 cnt = 0;
// 	uint8 ret = 0;
// 	static uint8  MsgValid_time_0 = 0;
// 	static uint8  MsgValid_time_1 = 0;
// 	static uint8  MsgValid_time_2 = 0;
// 	if(COMRxFlag[CANBUS_ID_0x51] == 0xAA)
// 	{
// 		COMRxFlag[CANBUS_ID_0x51] = 0;//��־����ʱ�䰴�ս��ձ��ĵ�ʱ�����?

// 		cnt=0;//��ʧ������0
// 		COMRxLostFlag[CANBUS_ID_0x51] = 0;

// 		retRead172 = Rte_Read_RPort_BrkPedlPsd_UB_BrkPedlPsd_UB(&read172);
// 		retRead173 = Rte_Read_RPort_BrkPedlPsdBrkPedlNotPsdSafe_BrkPedlPsdBrkPedlNotPsdSafe(&read173);
// 		retRead174 = Rte_Read_RPort_BrkPedlPsdBrkPedlPsd_BrkPedlPsdBrkPedlPsd(&read174);
// 		retRead175 = Rte_Read_RPort_BrkPedlPsdChks8_BrkPedlPsdChks8(&read175);
// 		retRead176 = Rte_Read_RPort_BrkPedlPsdCntr4_BrkPedlPsdCntr4(&read176);
// 		retRead177 = Rte_Read_RPort_BrkPedlPsdDataID4_BrkPedlPsdDataID4(&read177);
// 		retRead178 = Rte_Read_RPort_BrkPedlPsdQf_BrkPedlPsdQf(&read178);

// 		SecCanFrame02_BPP_DATA.Impl_Cks = read175;
// 		SecCanFrame02_BPP_DATA.Impl_Cnt = read177 << 4 | read176;
// 		SecCanFrame02_BPP_DATA.Impl_Sig1 = read178 << 2 | read174 << 1 | read173;
		
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame02_BPP,&E2E_P11CheckStateType_SecCanFrame02_BPP,(uint8 *)&SecCanFrame02_BPP_DATA,3);

// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame02_BPP.Status == 0)) || (read175 == 0xAA))
// 		{
// 			COMRxVailFlag1[CANBUS_ID_0x51] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag1[CANBUS_ID_0x51] = 2;
// 		}


// 		retRead179 = Rte_Read_RPort_VehSpdLgt_UB_VehSpdLgt_UB(&read179);
// 		vehspdvb = read179;
// 		retRead180 = Rte_Read_RPort_VehSpdLgtA_VehSpdLgtA(&read180);
// 		retRead181 = Rte_Read_RPort_VehSpdLgtChks8_VehSpdLgtChks8(&read181);
// 		retRead182 = Rte_Read_RPort_VehSpdLgtCntr4_VehSpdLgtCntr4(&read182);
// 		retRead183 = Rte_Read_RPort_VehSpdLgtDataID4_VehSpdLgtDataID4(&read183);
// 		retRead184 = Rte_Read_RPort_VehSpdLgtQf_VehSpdLgtQf(&read184);
// 		vehspdqf = read184;

// 		SecCanFrame02_VSL_DATA.Impl_Cks = read181;
// 		SecCanFrame02_VSL_DATA.Impl_Cnt = read183 << 4 | read182;
// 		SecCanFrame02_VSL_DATA.Impl_Sig1 = read180;
// 		SecCanFrame02_VSL_DATA.Impl_Sig2 = read180 >> 8;
// 		SecCanFrame02_VSL_DATA.Impl_Sig3 = read184;
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame02_VSL,&E2E_P11CheckStateType_SecCanFrame02_VSL,(uint8 *)&SecCanFrame02_VSL_DATA,5);
// 		//debug_jing1 = ret;
// 		//debug_jing3 = (E2E_P11CheckStateType_SecCanFrame02_VSL.Status << 8) | SecCanFrame02_VSL_DATA.Impl_Cnt;
// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame02_VSL.Status == 0)) || (read181 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x51] = 0;
// 			 MsgValid_time_2 = 0;
// 			if(vehspdvb > 0 && vehspdqf > 2)
// 			{
// 				//Rte_Read_ASW_COM_RPort_VehSpdLgtA_VehSpdLgtA(&Fv_EXT_CanSpd);//1 for 0.00391m/s -> 0.014076km/h
// 				Fv_EXT_CanSpd = read180;

// 				Fv_EXT_SpdValidFlag = 1;
// 				MsgValid_time_0 = 0;
// 				MsgValid_time_1 = 0;
// 			}
// 			else
// 			{
// 				if(MsgValid_time_0 > 10)
// 				{
// 					Fv_EXT_SpdValidFlag = 0;
// 				}
// 				else
// 				{
// 					MsgValid_time_0++;
// 				}
// 				//Fv_EXT_SpdValidFlag = 0; //add for doudong by liuyang
// 			}
// 		}
// 		else
// 		{
// 			if(MsgValid_time_2 > 1){
// 			COMRxVailFlag[CANBUS_ID_0x51] = 2;
// 			}else{
// 				MsgValid_time_2++;
// 			}
// 			if(MsgValid_time_1 > 10)
// 			{
// 			Fv_EXT_SpdValidFlag = 0;
// 			}
// 			else
// 			{
// 				MsgValid_time_1++;
// 			}

// 		}

// 		Fv_EXT_SpdIndication = 0xAA;

// 		COMRxFlag[CANBUS_ID_0x51] = 0;//ï¿½ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ä°´ï¿½Õ½ï¿½ï¿½Õ±ï¿½ï¿½Äµï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿?

// 		cnt=0;//ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½0
// 		COMRxLostFlag[CANBUS_ID_0x51] = 0;
// 	}
// 	else
// 	{//ï¿½ï¿½Ê§

// 		cnt ++;
// 		if(cnt >=4)//ï¿½ï¿½ï¿½Õµï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Äµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// 		{
// 			COMRxLostFlag[CANBUS_ID_0x51] = 0xAA;
// 			cnt = 4;
// 		} 
// 	}
// }
// static void ASW_COM_RX_CSCBCMCore_SecCanFrame03(void)
// {
// 	static E2E_ImpleDataType_SecCanFrame03_WFS SecCanFrame03_WFS_DATA;
// 	static E2E_ImpleDataType_SecCanFrame03_WRT SecCanFrame03_WRT_DATA;
// 	static E2E_ImpleDataType_SecCanFrame03_VMS SecCanFrame03_VMS_DATA;
// 	uint8 read153;
// 		Std_ReturnType retRead153;
// 		uint8 read154;
// 		Std_ReturnType retRead154;
// 		uint8 read155;
// 		Std_ReturnType retRead155;
// 		uint8 read156;
// 		Std_ReturnType retRead156;
// 		uint8 read157;
// 		Std_ReturnType retRead157;
// 		uint8 read158;
// 		Std_ReturnType retRead158;
// 		uint16 read159;
// 		Std_ReturnType retRead159;
// 		uint8 read160;
// 		Std_ReturnType retRead160;
// 		uint8 read161;
// 		Std_ReturnType retRead161;
// 		uint8 read162;
// 		Std_ReturnType retRead162;
// 		uint8 read163;
// 		Std_ReturnType retRead163;
// 		uint8 read164;
// 		Std_ReturnType retRead164;
// 		uint8 read165;
// 		Std_ReturnType retRead165;
// 		uint8 read166;
// 		Std_ReturnType retRead166;
// 		uint8 read167;
// 		Std_ReturnType retRead167;
// 		uint8 read168;
// 		Std_ReturnType retRead168;
// 		uint8 read169;
// 		Std_ReturnType retRead169;
// 		uint8 read170;
// 		Std_ReturnType retRead170;
// 		uint8 read171;
// 		Std_ReturnType retRead171;
// 	uint8 vehmtnstvb = 0;
// 	static uint16 cnt = 0;
// 	uint8 ret;
// 	if(COMRxFlag[CANBUS_ID_0x52] == 0xAA)
// 	{
// 		COMRxFlag[CANBUS_ID_0x52] = 0;//��־����ʱ�䰴�ս��ձ��ĵ�ʱ�����?

// 		cnt=0;//��ʧ������0
// 		COMRxLostFlag[CANBUS_ID_0x52] = 0;

// 		retRead153 = Rte_Read_RPort_VehMtnSt_UB_VehMtnSt_UB(&read153);
// 		vehmtnstvb = read153 ;
// 			retRead154 = Rte_Read_RPort_VehMtnStChks8_VehMtnStChks8(&read154);
// 			retRead155 = Rte_Read_RPort_VehMtnStCntr4_VehMtnStCntr4(&read155);
// 			retRead156 = Rte_Read_RPort_VehMtnStDataID4_VehMtnStDataID4(&read156);
// 			retRead157 = Rte_Read_RPort_VehMtnStVehMtnSt_VehMtnStVehMtnSt(&read157);
// 		SecCanFrame03_VMS_DATA.Impl_Cks = read154;
// 		SecCanFrame03_VMS_DATA.Impl_Cnt = read156 << 4 | read155;
// 		SecCanFrame03_VMS_DATA.Impl_Sig1 = read157;
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame03_VMS,&E2E_P11CheckStateType_SecCanFrame03_VMS,(uint8 *)&SecCanFrame03_VMS_DATA,3);

// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame03_VMS.Status == 0)) || (read154 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x52] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x52] = 2;
			
// 		}
// 			retRead158 = Rte_Read_RPort_WhlFastSpdSafe_UB_WhlFastSpdSafe_UB(&read158);
// 			retRead159 = Rte_Read_RPort_WhlFastSpdSafeA_WhlFastSpdSafeA(&read159);
// 			retRead160 = Rte_Read_RPort_WhlFastSpdSafeChks8_WhlFastSpdSafeChks8(&read160);
// 			retRead161 = Rte_Read_RPort_WhlFastSpdSafeCntr4_WhlFastSpdSafeCntr4(&read161);
// 			retRead162 = Rte_Read_RPort_WhlFastSpdSafeDataID4_WhlFastSpdSafeDataID4(&read162);
// 			retRead163 = Rte_Read_RPort_WhlFastSpdSafeQF_WhlFastSpdSafeQF(&read163);
// 		SecCanFrame03_WFS_DATA.Impl_Cks = read160;
// 		SecCanFrame03_WFS_DATA.Impl_Cnt = read162 << 4| read161;
// 		SecCanFrame03_WFS_DATA.Impl_Sig1 = read159;
// 		SecCanFrame03_WFS_DATA.Impl_Sig2 = read159 >> 8;
// 		SecCanFrame03_WFS_DATA.Impl_Sig3 = read163;
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame03_WFS,&E2E_P11CheckStateType_SecCanFrame03_WFS,(uint8 *)&SecCanFrame03_WFS_DATA,5);

// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame03_WFS.Status == 0)) || (read160 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x52] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x52] = 2;
					
// 		}

// 			retRead164 = Rte_Read_RPort_WhlRotToothCntr_UB_WhlRotToothCntr_UB(&read164);
// 			retRead165 = Rte_Read_RPort_WhlRotToothCntrChks8_WhlRotToothCntrChks8(&read165);
// 			retRead166 = Rte_Read_RPort_WhlRotToothCntrCntr4_WhlRotToothCntrCntr4(&read166);
// 			retRead167 = Rte_Read_RPort_WhlRotToothCntrDataID4_WhlRotToothCntrDataID4(&read167);
// 			retRead168 = Rte_Read_RPort_WhlRotToothCntrFrntLe_WhlRotToothCntrFrntLe(&read168);
// 			retRead169 = Rte_Read_RPort_WhlRotToothCntrFrntRi_WhlRotToothCntrFrntRi(&read169);
// 			retRead170 = Rte_Read_RPort_WhlRotToothCntrReLe_WhlRotToothCntrReLe(&read170);
// 			retRead171 = Rte_Read_RPort_WhlRotToothCntrReRi_WhlRotToothCntrReRi(&read171);
// 		SecCanFrame03_WRT_DATA.Impl_Cks = read165;
// 		SecCanFrame03_WRT_DATA.Impl_Cnt = read167 << 4| read166;
// 		SecCanFrame03_WRT_DATA.Impl_Sig1 = read168;
// 		SecCanFrame03_WRT_DATA.Impl_Sig2 = read169;
// 		SecCanFrame03_WRT_DATA.Impl_Sig3 = read170;
// 		SecCanFrame03_WRT_DATA.Impl_Sig4 = read171;
// 		ret = E2E_P11Check(&E2E_P11ConfigType_SecCanFrame03_WRT,&E2E_P11CheckStateType_SecCanFrame03_WRT,(uint8 *)&SecCanFrame03_WRT_DATA,6);

// 		if(((ret == 0) && (E2E_P11CheckStateType_SecCanFrame03_WRT.Status == 0)) || (read165 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x52] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x52] = 2;
				
// 		}

// 	if((vehmtnstvb > 0) && (cnt < 100))
// 	{

// 		Fv_EXT_CanVehMtnS = read157;

// 	}
// 	else
// 	{
// 		Fv_EXT_CanVehMtnS = 0;
// 	}
	

// 	 COMRxFlag[CANBUS_ID_0x52] = 0;//ï¿½ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ä°´ï¿½Õ½ï¿½ï¿½Õ±ï¿½ï¿½Äµï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿?

// 	  cnt=0;//ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½0
// 	  COMRxLostFlag[CANBUS_ID_0x52] = 0;
// 	}
// 	else
// 	{//ï¿½ï¿½Ê§

// 		cnt ++;
// 		if(cnt >= 4)//ï¿½ï¿½ï¿½Õµï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Äµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// 		{
// 			COMRxLostFlag[CANBUS_ID_0x52] = 0xAA;
// 			cnt = 4;
// 		}
// 	}
// //Rte_Read_ASW_COM_RPort_VehMtnStDataID4_VehMtnStDataID4
// //Rte_Read_ASW_COM_RPort_VehMtnStCntr4_VehMtnStCntr4
// //Rte_Read_ASW_COM_RPort_VehMtnStChks8_VehMtnStChks8

// }
// static void ASW_COM_RX_CSCBCMCore_SecCanFrame04(void)//0x202 deleted at 24N3 dbc
// {
// //todo--ï¿½Þ´Ë±ï¿½ï¿½ï¿½
// 	/*Rte_Read_RPort_VehModMngtGlbSafe_UB_VehModMngtGlbSafe_UB(&modevb);
// 	if(modevb > 0)
// 	{
// 		Fv_EXT_PMValidFlag = 1;
// 		Rte_Read_RPort_VehModMngtGlbSafePwrModSts_VehModMngtGlbSafePwrModSts(&Fv_PowerMode);
// 		Fv_EXT_CanPowerMode = Fv_PowerMode;
// 	}
// 	else
// 	{
// 		Fv_EXT_PMValidFlag = 0;
// 	}
	
// 	if(COMRxFlag[CANBUS_ID_0x202] == 0xAA)
// 	{
// 		COMRxFlag[CANBUS_ID_0x202] = 0;
// 		Fv_EXT_PMIndication = 0xAA;
// 	}

// 	Rte_Read_RPort_VehModMngtGlbSafePwrElecMai_VehModMngtGlbSafePwrElecMai(&Fv_EXT_CanElPwrLvl);

// 	//Rte_Read_RPort_VehModMngtGlbSafePwrElecSubtyp_VehModMngtGlbSafePwrElecSubtyp

// 	Rte_Read_RPort_VehModMngtGlbSafeCarModSts_VehModMngtGlbSafeCarModSts(&Fv_CarMode);*/
// }
// static void ASW_COM_RX_CSCBCMCore_SpecialSecFrame01(void)
// {
// 	uint16 read151;
// 		Std_ReturnType retRead151;
// 		uint32 read152;
// 		Std_ReturnType retRead152;
// 		if(COMRxFlag[CANBUS_ID_0x201] == 0xAA)
// 		{
// 			COMRxFlag[CANBUS_ID_0x201] = 0;
// 		Ids_SetSecurityEvent(IDS_SECOC_FRESHVAL_RESYNC);//IDS-Event
// 		retRead151 = Rte_Read_RPort_TripResetSyncMsgRestCnt_TripResetSyncMsgRestCnt(&read151);
// 		retRead152 = Rte_Read_RPort_TripResetSyncMsgTripCnt_TripResetSyncMsgTripCnt(&read152);
// 		}
// }

// /****************************************************************
// * FUNCTION :
// * DESCRIPTION :
// * INPUTS :  None
// * OUTPUTS :
// * Limitations:
// ****************************************************************/
void ASW_COM_TestModeResponseSend(uint8 *data)
{
// 	//uint64 senddata;
// 	uint8 senddata[8]={0,};
// 	uint8 i=0;
// 	for(i=0;i<8;i++)
// 	{
// 		senddata[i] = data[i];
// 	}
// 	MCan_TransmitTEST(&senddata);
// 	/*senddata = data[7] | ((uint64)data[6] << 8) | ((uint64)data[5] << 16) | ((uint64)data[4] << 24)
// 		 | ((uint64)data[3] << 32) | ((uint64)data[2] << 40) | ((uint64)data[1] << 48) | ((uint64)data[0] << 56);
// 	(void)Rte_Write_PPort_Testmode_Response_Testmode_Response(senddata);*/
}
// /****************************************************************
// * FUNCTION :
// * DESCRIPTION :
// * INPUTS :  None
// * OUTPUTS :
// * Limitations:
// ****************************************************************/
// static void ASW_COM_TestModeRequest_Process(void)
// {
// #if 0
// 	uint64 readdata;
	
// 	(void)Rte_Read_RPort_Testmode_Request_Testmode_Request(&readdata);

// 	TestMode_RequestData[7] = (uint8)(readdata & 0xFF);
// 	TestMode_RequestData[6] = (uint8)((readdata >> 8) & 0xFF);
// 	TestMode_RequestData[5] = (uint8)((readdata >> 16) & 0xFF);
// 	TestMode_RequestData[4] = (uint8)((readdata >> 24) & 0xFF);
// 	TestMode_RequestData[3] = (uint8)((readdata >> 32) & 0xFF);
// 	TestMode_RequestData[2] = (uint8)((readdata >> 40) & 0xFF);
// 	TestMode_RequestData[1] = (uint8)((readdata >> 48) & 0xFF);
// 	TestMode_RequestData[0] = (uint8)((readdata >> 56) & 0xFF);
// #else
// 	uint32 addr = 0;
// 	addr = 0xf0200400;     //anglemid

// 	TestMode_RequestData[0] = ((uint8 *)addr)[0];
// 	TestMode_RequestData[1] = ((uint8 *)addr)[1];
// 	TestMode_RequestData[2] = ((uint8 *)addr)[2];
// 	TestMode_RequestData[3] = ((uint8 *)addr)[3];
// 	TestMode_RequestData[4] = ((uint8 *)addr)[4];
// 	TestMode_RequestData[5] = ((uint8 *)addr)[5];
// 	TestMode_RequestData[6] = ((uint8 *)addr)[6];
// 	TestMode_RequestData[7] = ((uint8 *)addr)[7];
// #endif
// 	if((TestMode_RequestData[2] == 0x9C)&& (TestMode_RequestData[3] == 0x1A) && (TestMode_RequestData[4] == 0xBF)
// 			&& (TestMode_RequestData[5] == 0x38) && (TestMode_RequestData[6] == 0x45) && (TestMode_RequestData[7] == 0x2D))
// 	{
// 		testmode_req = 0xAA;
// 	}
// }
// static void ASW_COM_RX_MCoreBCCanFDFrame01(void)
// { 
// 	static E2E_ImpleDataType_CanFDFrame01_ES CanFDFrame01_ES_DATA;
// 	static E2E_ImpleDataType_CanFDFrame01_VMM CanFDFrame01_VMM_DATA;
// 		uint8 read110;
// 		Std_ReturnType retRead110;
// 		uint8 read111;
// 		Std_ReturnType retRead111;
// 	    uint8 read112;
// 	    Std_ReturnType retRead112;
// 		uint16 read113;
// 		Std_ReturnType retRead113;
// 		uint8 read114;
// 		Std_ReturnType retRead114;
// 		uint8 read115;
// 		Std_ReturnType retRead115;
// 		uint8 read116;
// 		Std_ReturnType retRead116;
// 		uint8 read117;
// 		Std_ReturnType retRead117;
// 		uint8 read118;
// 		Std_ReturnType retRead118;
// 		uint8 read119;
// 		Std_ReturnType retRead119;
// 		uint8 read120;
// 		Std_ReturnType retRead120;
// 		uint8 read121;
// 		Std_ReturnType retRead121;
// 		uint8 read122;
// 		Std_ReturnType retRead122;
// 		uint8 read123;
// 		Std_ReturnType retRead123;
// 		uint8 read124;
// 		Std_ReturnType retRead124;
// 		uint8 read125;
// 		Std_ReturnType retRead125;
// 		uint8 read126;
// 		Std_ReturnType retRead126;
// 		uint8 read127;
// 		Std_ReturnType retRead127;
// 		uint8 read128;
// 		Std_ReturnType retRead128;
// 		uint8 read129;
// 		Std_ReturnType retRead129;
// 		uint8 read130;
// 		Std_ReturnType retRead130;
// 		uint8 read131;
// 		Std_ReturnType retRead131;
// 		uint8 read132;
// 		Std_ReturnType retRead132;
// 		uint8 read133;
// 		Std_ReturnType retRead133;
// 		uint8 read134;
// 		Std_ReturnType retRead134;
// 		uint8 read135;
// 		Std_ReturnType retRead135;
// 	uint8 assreqvb = 0;
// 	static uint16 cnt = 0;
// 	uint8 ret = 0;
// 	uint8 modevb = 0;
// 	if(COMRxFlag[CANBUS_ID_0x200] == 0xAA)
// 	{
// 		COMRxFlag[CANBUS_ID_0x200] = 0;//��־����ʱ�䰴�ս��ձ��ĵ�ʱ�����?
// 		Fv_EXT_PMIndication = 0xAA;
// 		cnt=0;//��ʧ������0
// 		COMRxLostFlag[CANBUS_ID_0x200] = 0;
// 		retRead110 = Rte_Read_RPort_ActvSubtypMod_ActvSubtypMod(&read110);
// 		retRead111 = Rte_Read_RPort_ActvSubtypMod_UB_ActvSubtypMod_UB(&read111);
// 		assreqvb = read111;
// 		retRead112 = Rte_Read_RPort_AmbTRaw_UB_AmbTRaw_UB(&read112);
// 		retRead113 = Rte_Read_RPort_AmbTRawAmbTEstimd_AmbTRawAmbTEstimd(&read113);
// 		retRead114 = Rte_Read_RPort_AmbTRawAmbTEstimdQf_AmbTRawAmbTEstimdQf(&read114);
// 		retRead115 = Rte_Read_RPort_BrkTracCtrlActv_BrkTracCtrlActv(&read115);
// 		retRead116 = Rte_Read_RPort_BrkTracCtrlActv_UB_BrkTracCtrlActv_UB(&read116);
// 		retRead117 = Rte_Read_RPort_EscSt_UB_EscSt_UB(&read117);
// 		retRead118 = Rte_Read_RPort_EscStChks8_EscStChks8(&read118);
// 		retRead119 = Rte_Read_RPort_EscStCntr4_EscStCntr4(&read119);
// 		retRead120 = Rte_Read_RPort_EscStDataID4_EscStDataID4(&read120);
// 		retRead121 = Rte_Read_RPort_EscStEscSt_EscStEscSt(&read121);
// 		CanFDFrame01_ES_DATA.Impl_Cks = read118;
// 		CanFDFrame01_ES_DATA.Impl_Cnt = read120 << 4 | read119;
// 		CanFDFrame01_ES_DATA.Impl_Sig1 = read121;

// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame01_ES,&E2E_P11CheckStateType_CanFDFrame01_ES,(uint8 *)&CanFDFrame01_ES_DATA,3);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame01_ES.Status == 0)) || (read118 == 0xAA))
// 		{
// 			COMRxVailFlag1[CANBUS_ID_0x200] = 0;
// 			if((assreqvb > 0) && (cnt < 100))
// 			{
// 				Fv_EXT_CanAssReq = read110;
// 				Fv_EXT_ASSReqValidFlag = 1;
// 			}
// 			else
// 			{
// 				Fv_EXT_ASSReqValidFlag = 0;
// 			}
// 		}
// 		else
// 		{
// 			COMRxVailFlag1[CANBUS_ID_0x200] = 2;

// 		}			
// 			retRead122 = Rte_Read_RPort_SftRkLimrFwrReq_SftRkLimrFwrReq(&read122);
// 			retRead123 = Rte_Read_RPort_SftRkLimrFwrReq_UB_SftRkLimrFwrReq_UB(&read123);
// 			retRead124 = Rte_Read_RPort_VehModMngtGlbSafe_UB_VehModMngtGlbSafe_UB(&read124);
// 			modevb = read124;
// 			retRead125 = Rte_Read_RPort_VehModMngtGlbSafeCarModSts_VehModMngtGlbSafeCarModSts(&read125);
// 			Fv_CarMode = read125;
// 			retRead126 = Rte_Read_RPort_VehModMngtGlbSafeCarModSubtypWdC_VehModMngtGlbSafeCarModSubtypWdC(&read126);
// 			retRead127 = Rte_Read_RPort_VehModMngtGlbSafeChks8_VehModMngtGlbSafeChks8(&read127);
// 			retRead128 = Rte_Read_RPort_VehModMngtGlbSafeCntr4_VehModMngtGlbSafeCntr4(&read128);
// 			retRead129 = Rte_Read_RPort_VehModMngtGlbSafeDataID4_VehModMngtGlbSafeDataID4(&read129);
// 			retRead130 = Rte_Read_RPort_VehModMngtGlbSafeEgyLvlElecMai_VehModMngtGlbSafeEgyLvlElecMai(&read130);
// 			retRead131 = Rte_Read_RPort_VehModMngtGlbSafeEgyLvlElecSubty_VehModMngtGlbSafeEgyLvlElecSubty(&read131);
// 			retRead132 = Rte_Read_RPort_VehModMngtGlbSafeFltEgyCnsWdSts_VehModMngtGlbSafeFltEgyCnsWdSts(&read132);
// 			retRead133 = Rte_Read_RPort_VehModMngtGlbSafePwrLvlElecMai_VehModMngtGlbSafePwrLvlElecMai(&read133);
// 			retRead134 = Rte_Read_RPort_VehModMngtGlbSafePwrLvlElecSubty_VehModMngtGlbSafePwrLvlElecSubty(&read134);
// 			retRead135 = Rte_Read_RPort_VehModMngtGlbSafePwrModSts_VehModMngtGlbSafePwrModSts(&read135);
// 			retRead110 = Rte_Read_RPort_ActvSubtypMod_ActvSubtypMod(&read110);
// 			retRead111 = Rte_Read_RPort_ActvSubtypMod_UB_ActvSubtypMod_UB(&read111);
// 		CanFDFrame01_VMM_DATA.Impl_Cks = read127;
// 		CanFDFrame01_VMM_DATA.Impl_Cnt = read129 << 4 | read128;
// 		CanFDFrame01_VMM_DATA.Impl_Sig1 = read131 << 4 | read130;
// 		CanFDFrame01_VMM_DATA.Impl_Sig2 = read134 << 4 | read133;
// 		CanFDFrame01_VMM_DATA.Impl_Sig3 = read132 << 7 | read125 << 4 | read135;
// 		CanFDFrame01_VMM_DATA.Impl_Sig4 = read126;
// 		//ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame01_VMM_DATA,&E2E_P11CheckStateType_CanFDFrame01_VMM_DATA,(uint8 *)&CanFDFrame01_VMM_DATA_DATA);
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame01_VMM,&E2E_P11CheckStateType_CanFDFrame01_VMM,(uint8 *)&CanFDFrame01_VMM_DATA,6);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame01_VMM.Status == 0)) || (read127 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x200] = 0;
// 			Fv_PowerMode = read135;
// 			if((modevb > 0) &&(Fv_PowerMode >= 0)&&(Fv_PowerMode <= 8))
// 			{
// 				Fv_EXT_PMValidFlag = 1;
// 				Fv_EXT_CanPowerMode = Fv_PowerMode;
// 			}
// 			else
// 			{
// 				Fv_EXT_PMValidFlag = 0;
// 			}
// 			if((modevb > 0) &&(Fv_CarMode >= 0)&&(Fv_CarMode <= 8))
// 			{
// 				Fv_EXT_UsageModeReq = Fv_CarMode;
// 			}
// 			else
// 			{
// 				Fv_EXT_UsageModeReq = 0;
// 			}

// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x200] = 2;
// 			Fv_EXT_CanPowerMode = 0;
// 		}
	

// 	//Rte_Read_ASW_COM_RPort_ActvSubtypMod_ActvSubtypMod(&read25);

// 	  cnt=0;//¶ªÊ§¼ÆÊýÇå0
// 	  COMRxLostFlag[CANBUS_ID_0x200] = 0;
// 	}
// 	else
// 	{//¶ªÊ§

// 		if(cnt >= 40)//°´ÕÕµ÷²éÎÊ¾íµÄµ÷ÓÃÖÜÆÚÉèÖÃ
// 		{
// 			COMRxLostFlag[CANBUS_ID_0x200] = 0xAA;
// 			cnt = 40;
// 			Fv_CarMode = 0;
// 			Fv_PowerMode = 2;
// 		}
// 		else
// 		{
// 			cnt ++;
// 		}
// 	}

// }

// static void ASW_COM_RX_MCoreBCCanFDFrame02(void)
// {

// }

// static void ASW_COM_RX_MCoreBCCanFDFrame03(void)
// {
// 	uint32 read101;
// 		Std_ReturnType retRead101;
// 		uint8 read102;
// 		Std_ReturnType retRead102;
// 		uint8 read103;
// 		Std_ReturnType retRead103;
// 		uint8 read104;
// 		Std_ReturnType retRead104;
// 		uint8 read105;
// 		Std_ReturnType retRead105;
// 		uint8 read106;
// 		Std_ReturnType retRead106;
// 		uint8 read107;
// 		Std_ReturnType retRead107;
// 		uint8 read108;
// 		Std_ReturnType retRead108;
// 		uint8 read109;
// 		Std_ReturnType retRead109;
// 	uint8 ASScLvl = 0;
// 	static uint16 cnt = 0;
// 	//500msï¿½ï¿½ï¿½ï¿½
// 	if(COMRxFlag[CANBUS_ID_0x400] == 0xAA)
// 	{
// 	 COMRxFlag[CANBUS_ID_0x400] = 0;//ï¿½ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ä°´ï¿½Õ½ï¿½ï¿½Õ±ï¿½ï¿½Äµï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿?
// 			cnt=0;//��ʧ������0
// 		COMRxLostFlag[CANBUS_ID_0x400] = 0;
// 		retRead101 = Rte_Read_RPort_OdoMeter_OdoMeter(&read101);
// 		retRead102 = Rte_Read_RPort_OdoMeter_UB_OdoMeter_UB(&read102);
// 		retRead103 = Rte_Read_RPort_SteerSetg_UB_SteerSetg_UB(&read103);
// 		retRead104 = Rte_Read_RPort_SteerSetgPen_SteerSetgPen(&read104);

// 		retRead106 = Rte_Read_RPort_SteerSetgSteerMod_SteerSetgSteerMod(&read106);
// 		retRead107 = Rte_Read_RPort_VehLVSysUZCL_UB_VehLVSysUZCL_UB(&read107);
// 		retRead108 = Rte_Read_RPort_VehLVSysUZCLVehLVSysUBkp_VehLVSysUZCLVehLVSysUBkp(&read108);
// 		retRead109 = Rte_Read_RPort_VehLVSysUZCLVehLVSysUMai_VehLVSysUZCLVehLVSysUMai(&read109);

// 	retRead105 = Rte_Read_RPort_SteerSetgSteerAsscLvl_SteerSetgSteerAsscLvl(&ASScLvl);
// 	if(ASScLvl != 0)
// 	{
// 		switch(ASScLvl)
// 		{
// 			case 1:
// 				Fv_CMDAssistSelectMode = ASS_TYPE_COMFORT;
// 				break;
// 			case 2:
// 				Fv_CMDAssistSelectMode = ASS_TYPE_STANDARD;
// 				break;
// 			case 3:
// 				Fv_CMDAssistSelectMode = ASS_TYPE_SPORT;
// 				break;
// 			case 4:
// 				Fv_CMDAssistSelectMode = ASS_TYPE_LKA;
// 				break;
// 			default:
// 				break;
// 		}
// 	}
// 	else
// 	{

// 	}
// 	cnt=0;//¶ªÊ§¼ÆÊýÇå0

// 	}
// 	else
// 	{//¶ªÊ§

// 		cnt ++;
// 		if(cnt >= 100)//°´ÕÕµ÷²éÎÊ¾íµÄµ÷ÓÃÖÜÆÚÉèÖÃ
// 		{
// 			COMRxLostFlag[CANBUS_ID_0x400] = 0xAA;
// 			cnt = 100;
// 		}
// 	}
// }

// static void ASW_COM_RX_MCoreBCCanFDFrame04(void)//0x40
// {
// 	static E2E_ImpleDataType_CanFDFrame04_AgD CanFDFrame04_AgD_DATA;
// 	static E2E_ImpleDataType_CanFDFrame04_ALC CanFDFrame04_ALC_DATA;
// 	static E2E_ImpleDataType_CanFDFrame04_ADR CanFDFrame04_ADR_DATA;
// 	static E2E_ImpleDataType_CanFDFrame04_WSCF CanFDFrame04_WSCF_DATA;
// 	static E2E_ImpleDataType_CanFDFrame04_WSCR CanFDFrame04_WSCR_DATA;
// 	static E2E_ImpleDataType_CanFDFrame04_LCR CanFDFrame04_LCR_DATA;		
// 	uint8 read51;
// 		Std_ReturnType retRead51;
// 		uint16 read52;
// 		Std_ReturnType retRead52;
// 		uint8 read53;
// 		Std_ReturnType retRead53;
// 		uint16 read54;
// 		Std_ReturnType retRead54;
// 		uint8 read55;
// 		Std_ReturnType retRead55;
// 		uint16 read56;
// 		Std_ReturnType retRead56;
// 		uint8 read57;
// 		Std_ReturnType retRead57;
// 		uint8 read58;
// 		Std_ReturnType retRead58;
// 		uint8 read59;
// 		Std_ReturnType retRead59;
// 		uint8 read60;
// 		Std_ReturnType retRead60;
// 		uint8 read61;
// 		Std_ReturnType retRead61;
// 		uint8 read62;
// 		Std_ReturnType retRead62;
// 		uint8 read63;
// 		Std_ReturnType retRead63;
// 		uint8 read64;
// 		Std_ReturnType retRead64;
// 		uint16 read65;
// 		Std_ReturnType retRead65;
// 		uint8 read66;
// 		Std_ReturnType retRead66;
// 		uint16 read67;
// 		Std_ReturnType retRead67;
// 		uint8 read68;
// 		Std_ReturnType retRead68;
// 		uint8 read69;
// 		Std_ReturnType retRead69;
// 		uint8 read70;
// 		Std_ReturnType retRead70;
// 		uint8 read71;
// 		Std_ReturnType retRead71;
// 		uint8 read72;
// 		Std_ReturnType retRead72;
// 		uint8 read73;
// 		Std_ReturnType retRead73;
// 		uint8 read74;
// 		Std_ReturnType retRead74;
// 		uint8 read75;
// 		Std_ReturnType retRead75;
// 		uint8 read76;
// 		Std_ReturnType retRead76;
// 		uint8 read77;
// 		Std_ReturnType retRead77;
// 		uint8 read78;
// 		Std_ReturnType retRead78;
// 		uint16 read79;
// 		Std_ReturnType retRead79;
// 		uint16 read80;
// 		Std_ReturnType retRead80;
// 		uint16 read81;
// 		Std_ReturnType retRead81;
// 		uint8 read82;
// 		Std_ReturnType retRead82;
// 		uint8 read83;
// 		Std_ReturnType retRead83;
// 		uint8 read84;
// 		Std_ReturnType retRead84;
// 		uint8 read85;
// 		Std_ReturnType retRead85;
// 		uint8 read86;
// 		Std_ReturnType retRead86;
// 		uint8 read87;
// 		Std_ReturnType retRead87;
// 		uint8 read88;
// 		Std_ReturnType retRead88;
// 		uint16 read89;
// 		Std_ReturnType retRead89;
// 		uint8 read90;
// 		Std_ReturnType retRead90;
// 		uint16 read91;
// 		Std_ReturnType retRead91;
// 		uint8 read92;
// 		Std_ReturnType retRead92;
// 		uint8 read93;
// 		Std_ReturnType retRead93;
// 		uint8 read94;
// 		Std_ReturnType retRead94;
// 		uint8 read95;
// 		Std_ReturnType retRead95;
// 		uint8 read96;
// 		Std_ReturnType retRead96;
// 		uint16 read97;
// 		Std_ReturnType retRead97;
// 		uint8 read98;
// 		Std_ReturnType retRead98;
// 		uint16 read99;
// 		Std_ReturnType retRead99;
// 		uint8 read100;
// 		Std_ReturnType retRead100;
// 	uint8 whsFntUB = 0;
// 	uint8 whsReUB = 0;
// 	uint8 ret;
// 	sint16 tqreq = 0;
// 	sint16 agreq = 0;
// 	sint16 tqreqlimit = 0;
// 	sint16 tqreqTemp = 0;
// 	static uint16 cnt = 0;

// 	if(COMRxFlag[CANBUS_ID_0x40] == 0xAA)
// 	{	
// 		COMRxFlag[CANBUS_ID_0x40] = 0;
// 		cnt = 0;
// 		COMRxLostFlag[CANBUS_ID_0x40] = 0x0;
// 	/*Rte_Read_RPort_WhlSpdCircumlFrnt_UB_WhlSpdCircumlFrnt_UB(&whsFntUB);
// 	Rte_Read_RPort_WhlSpdCircumlRe_UB_WhlSpdCircumlRe_UB(&whsReUB);
// 	Fv_WhsInvalidFlag = (whsFntUB && whsReUB);
// 	Rte_Read_RPort_WhlSpdCircumlFrntRi_WhlSpdCircumlFrntRi(&Fv_Ws_Frws_raw);
// 	Rte_Read_RPort_WhlSpdCircumlFrntLe_WhlSpdCircumlFrntLe(&Fv_Ws_Flws_raw);
// 	Rte_Read_RPort_WhlSpdCircumlReRi_WhlSpdCircumlReRi(&Fv_Ws_Rrws_raw);
// 	Rte_Read_RPort_WhlSpdCircumlReLe_WhlSpdCircumlReLe(&Fv_Ws_Rlws_raw);
// 	Rte_Read_RPort_AgDataRawSafeYawRate_AgDataRawSafeYawRate(&Fv_YawRate_Raw);*/
// 	retRead51 = Rte_Read_RPort_ADataRawSafe_UB_ADataRawSafe_UB(&read51);
// 		retRead52 = Rte_Read_RPort_ADataRawSafeALat_ADataRawSafeALat(&read52);
// 		retRead53 = Rte_Read_RPort_ADataRawSafeALat1Qf_ADataRawSafeALat1Qf(&read53);
// 		retRead54 = Rte_Read_RPort_ADataRawSafeALgt_ADataRawSafeALgt(&read54);
// 		retRead55 = Rte_Read_RPort_ADataRawSafeALgt1Qf_ADataRawSafeALgt1Qf(&read55);
// 		retRead56 = Rte_Read_RPort_ADataRawSafeAVert_ADataRawSafeAVert(&read56);
// 		retRead57 = Rte_Read_RPort_ADataRawSafeAVertQf_ADataRawSafeAVertQf(&read57);
// 		retRead58 = Rte_Read_RPort_ADataRawSafeChks8_ADataRawSafeChks8(&read58);
// 		retRead59 = Rte_Read_RPort_ADataRawSafeCntr4_ADataRawSafeCntr4(&read59);
// 		retRead60 = Rte_Read_RPort_ADataRawSafeDataID4_ADataRawSafeDataID4(&read60);
// 		CanFDFrame04_ADR_DATA.Impl_Cks = read58;
// 		CanFDFrame04_ADR_DATA.Impl_Cnt = read60 << 4 | read59;
// 		CanFDFrame04_ADR_DATA.Impl_Sig1 = read52;
// 		CanFDFrame04_ADR_DATA.Impl_Sig2 = read52 >> 8;
// 		CanFDFrame04_ADR_DATA.Impl_Sig3 = read56;
// 		CanFDFrame04_ADR_DATA.Impl_Sig4 = read56 >> 8;
// 		CanFDFrame04_ADR_DATA.Impl_Sig5 = read54;
// 		CanFDFrame04_ADR_DATA.Impl_Sig6 = read54 >> 8;	
// 		CanFDFrame04_ADR_DATA.Impl_Sig7 = read57 << 4 | read55 << 2 | read53;
// 		//ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame01_VMM_DATA,&E2E_P11CheckStateType_CanFDFrame01_VMM_DATA,(uint8 *)&CanFDFrame01_VMM_DATA_DATA);
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame04_ADR,&E2E_P11CheckStateType_CanFDFrame04_ADR,(uint8 *)&CanFDFrame04_ADR_DATA,9);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame04_ADR.Status == 0)) || (read58 == 0xAA))
// 		{
// 			COMRxVailFlag4[CANBUS_ID_0x40] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag4[CANBUS_ID_0x40] = 2;
// 		}
// 		//AgD
// 		retRead61 = Rte_Read_RPort_AgDataRawSafe_UB_AgDataRawSafe_UB(&read61);
// 		retRead62 = Rte_Read_RPort_AgDataRawSafeChks8_AgDataRawSafeChks8(&read62);
// 		retRead63 = Rte_Read_RPort_AgDataRawSafeCntr4_AgDataRawSafeCntr4(&read63);
// 		retRead64 = Rte_Read_RPort_AgDataRawSafeDataID4_AgDataRawSafeDataID4(&read64);
// 		retRead65 = Rte_Read_RPort_AgDataRawSafeRollRate_AgDataRawSafeRollRate(&read65);
// 		retRead66 = Rte_Read_RPort_AgDataRawSafeRollRateQf_AgDataRawSafeRollRateQf(&read66);
// 		retRead67 = Rte_Read_RPort_AgDataRawSafeYawRate_AgDataRawSafeYawRate(&read67);
// 		retRead68 = Rte_Read_RPort_AgDataRawSafeYawRateQf_AgDataRawSafeYawRateQf(&read68);
// 		CanFDFrame04_AgD_DATA.Impl_Cks = read62;
// 		CanFDFrame04_AgD_DATA.Impl_Cnt = read64 << 4| read63;
// 		CanFDFrame04_AgD_DATA.Impl_Sig1 = read65;
// 		CanFDFrame04_AgD_DATA.Impl_Sig2 = read65 >> 8;
// 		CanFDFrame04_AgD_DATA.Impl_Sig3 = read67;
// 		CanFDFrame04_AgD_DATA.Impl_Sig4 = read67 >> 8;
// 		CanFDFrame04_AgD_DATA.Impl_Sig5 = read68 << 2 | read66;
	
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame04_AgD,&E2E_P11CheckStateType_CanFDFrame04_AgD,(uint8 *)&CanFDFrame04_AgD_DATA,7);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame04_AgD.Status == 0)) || (read62 == 0xAA))
// 		{		
// 			if(read68 == 3)
// 			{
// 				fsYawRateCompensated = read67 + fsRawYawRateComp;
// 				if((Fv_VehSpd < Cal_YawRateCompVehSpd) &&
// 						(fsYawRateCompensated < Cal_YawRateCompThreshold)
// 							&& (fsYawRateCompensated > -Cal_YawRateCompThreshold))
// 				{
// 					fsRawYawRateComp = fsRawYawRateComp - (read67 / Cal_YawRateCompFactor);
// 				}
		
// 			}
// 				COMRxVailFlag1[CANBUS_ID_0x40] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag1[CANBUS_ID_0x40] = 2;
// 		}

        
// 		retRead69 = Rte_Read_RPort_AsyLatCoDrvReq_UB_AsyLatCoDrvReq_UB(&read69);
// 		retRead70 = Rte_Read_RPort_AsyLatCoDrvReq1_AsyLatCoDrvReq1(&read70);
// 		retRead71 = Rte_Read_RPort_AsyLatCoDrvReqChks8_AsyLatCoDrvReqChks8(&read71);
// 		retRead72 = Rte_Read_RPort_AsyLatCoDrvReqCntr4_AsyLatCoDrvReqCntr4(&read72);
// 		retRead73 = Rte_Read_RPort_AsyLatCoDrvReqDataID4_AsyLatCoDrvReqDataID4(&read73);
// 		CanFDFrame04_ALC_DATA.Impl_Cks = read71;
// 		CanFDFrame04_ALC_DATA.Impl_Cnt = read73 << 4 | read72;
// 		CanFDFrame04_ALC_DATA.Impl_Sig1 = read70;

// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame04_ALC,&E2E_P11CheckStateType_CanFDFrame04_ALC,(uint8 *)&CanFDFrame04_ALC_DATA,3);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame04_ALC.Status == 0)) || (read71 == 0xAA))
// 		{
// 			COMRxVailFlag2[CANBUS_ID_0x40] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag2[CANBUS_ID_0x40] = 2;
// 		}

// 		retRead74 = Rte_Read_RPort_LatCtrlReqSafe_UB_LatCtrlReqSafe_UB(&read74);
// 		retRead75 = Rte_Read_RPort_LatCtrlReqSafeChks8_LatCtrlReqSafeChks8(&read75);
// 		retRead76 = Rte_Read_RPort_LatCtrlReqSafeCntr4_LatCtrlReqSafeCntr4(&read76);
// 		retRead77 = Rte_Read_RPort_LatCtrlReqSafeDataID4_LatCtrlReqSafeDataID4(&read77);
// 		retRead78 = Rte_Read_RPort_LatCtrlReqSafeLatCtrlMod1_LatCtrlReqSafeLatCtrlMod1(&read78);
// 		retRead79 = Rte_Read_RPort_LatCtrlReqSafeSteerAgOffReq_LatCtrlReqSafeSteerAgOffReq(&read79);
// 		retRead80 = Rte_Read_RPort_LatCtrlReqSafeSteerAgReq_LatCtrlReqSafeSteerAgReq(&read80);
// 		retRead81 = Rte_Read_RPort_LatCtrlReqSafeSteerTqReq_LatCtrlReqSafeSteerTqReq(&read81);
// 		retRead82 = Rte_Read_RPort_LatCtrlReqSafeSteerWhlHptcWarnRe_LatCtrlReqSafeSteerWhlHptcWarnRe(&read82);
// 		CanFDFrame04_LCR_DATA.Impl_Cks = read75;
// 		CanFDFrame04_LCR_DATA.Impl_Cnt = read77 << 4 | read76;
// 		CanFDFrame04_LCR_DATA.Impl_Sig1 = read80;
// 		CanFDFrame04_LCR_DATA.Impl_Sig2 = read82 << 7 | read80 >> 8;
// 		CanFDFrame04_LCR_DATA.Impl_Sig3 = read81;	
// 		CanFDFrame04_LCR_DATA.Impl_Sig4 = read81 >> 8;
// 		CanFDFrame04_LCR_DATA.Impl_Sig5 = read78;	
// 		CanFDFrame04_LCR_DATA.Impl_Sig6 = read79;	
// 		CanFDFrame04_LCR_DATA.Impl_Sig7 = read80 >> 8;															
// 		if (read74==1){
// 			Fv_AbsLostFlag = 0;
// 		}						
// 		else{
// 			Fv_AbsLostFlag = 1;
// 		}								
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame04_LCR,&E2E_P11CheckStateType_CanFDFrame04_LCR,(uint8 *)&CanFDFrame04_LCR_DATA,9);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame04_LCR.Status == 0)) || (read75 == 0xAA))
// 		{
// 			Fv_AdsMod = read78;
// 			Fv_Warnreq = read82;
// 			tqreq = read81;
// 			tqreqlimit = tqreq*4;
// 			if(tqreqlimit > 3072)
// 			{
// 				Fv_AdsTrqReq = 3072;
// 			}
// 			else if(tqreqlimit < -3072)
// 			{
// 				Fv_AdsTrqReq = -3072;
// 			}
// 			else
// 			{
// 				Fv_AdsTrqReq = tqreqlimit;
// 			}
// 			Fv_AdsTqInvalid_flag = 0;
// 			COMRxVailFlag3[CANBUS_ID_0x40] = 0;
// 		}
// 		else
// 		{
// 			Fv_AdsTqInvalid_flag = 1;
// 			COMRxVailFlag3[CANBUS_ID_0x40] = 2;
// 		}

// 		retRead83 = Rte_Read_RPort_TankTurnSteerWhlReq_TankTurnSteerWhlReq(&read83);
// 		retRead84 = Rte_Read_RPort_TankTurnSteerWhlReq_UB_TankTurnSteerWhlReq_UB(&read84);

// 		retRead85 = Rte_Read_RPort_WhlSpdCircumlFrnt_UB_WhlSpdCircumlFrnt_UB(&whsFntUB);
// 		retRead86 = Rte_Read_RPort_WhlSpdCircumlFrntChks8_WhlSpdCircumlFrntChks8(&read86);
// 		retRead87 = Rte_Read_RPort_WhlSpdCircumlFrntCntr4_WhlSpdCircumlFrntCntr4(&read87);
// 		retRead88 = Rte_Read_RPort_WhlSpdCircumlFrntDataID4_WhlSpdCircumlFrntDataID4(&read88);
// 		retRead89 = Rte_Read_RPort_WhlSpdCircumlFrntWhlSpdCircumlLe_WhlSpdCircumlFrntWhlSpdCircumlLe(&read89);
// 		retRead90 = Rte_Read_RPort_WhlSpdCircumlFrntWhlSpdCirc_0000_WhlSpdCircumlFrntWhlSpdCirc_0000(&read90);
// 		retRead91 = Rte_Read_RPort_WhlSpdCircumlFrntWhlSpdCircumlRi_WhlSpdCircumlFrntWhlSpdCircumlRi(&read91);
// 		retRead92 = Rte_Read_RPort_WhlSpdCircumlFrntWhlSpdCirc_0001_WhlSpdCircumlFrntWhlSpdCirc_0001(&read92);
// 		CanFDFrame04_WSCF_DATA.Impl_Cks = read86;
// 		CanFDFrame04_WSCF_DATA.Impl_Cnt = read88 << 4 | read87;
// 		CanFDFrame04_WSCF_DATA.Impl_Sig1 = read89;
// 		CanFDFrame04_WSCF_DATA.Impl_Sig2 = read89 >> 8;
// 		CanFDFrame04_WSCF_DATA.Impl_Sig3 = read91;	
// 		CanFDFrame04_WSCF_DATA.Impl_Sig4 = read91 >> 8;
// 		CanFDFrame04_WSCF_DATA.Impl_Sig5 = read92 << 2 | read90;	
														
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame04_WSCF,&E2E_P11CheckStateType_CanFDFrame04_WSCF,(uint8 *)&CanFDFrame04_WSCF_DATA,7);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame04_WSCF.Status == 0)) || (read86 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x40] = 0;
// 			if(read90 == 3)
// 			{
// 				Fv_Ws_Flws_raw = read89;
// 				CAN_FLWS = read89;
// 			}

// 			if(read92 == 3)
// 			{
// 				Fv_Ws_Frws_raw = read91;
// 				CAN_FRWS = read91;
// 			}
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x40] = 2;
// 		}

// 		retRead93 = Rte_Read_RPort_WhlSpdCircumlRe_UB_WhlSpdCircumlRe_UB(&whsReUB);
// 		retRead94 = Rte_Read_RPort_WhlSpdCircumlReChks8_WhlSpdCircumlReChks8(&read94);
// 		retRead95 = Rte_Read_RPort_WhlSpdCircumlReCntr4_WhlSpdCircumlReCntr4(&read95);
// 		retRead96 = Rte_Read_RPort_WhlSpdCircumlReDataID4_WhlSpdCircumlReDataID4(&read96);
// 		retRead97 = Rte_Read_RPort_WhlSpdCircumlReWhlSpdCircumlLe_WhlSpdCircumlReWhlSpdCircumlLe(&read97);
// 		retRead98 = Rte_Read_RPort_WhlSpdCircumlReWhlSpdCircumlLeQf_WhlSpdCircumlReWhlSpdCircumlLeQf(&read98);
// 		retRead99 = Rte_Read_RPort_WhlSpdCircumlReWhlSpdCircumlRi_WhlSpdCircumlReWhlSpdCircumlRi(&read99);
// 		retRead100 = Rte_Read_RPort_WhlSpdCircumlReWhlSpdCircumlRiQf_WhlSpdCircumlReWhlSpdCircumlRiQf(&read100);
// 		CanFDFrame04_WSCR_DATA.Impl_Cks = read94;
// 		CanFDFrame04_WSCR_DATA.Impl_Cnt = read96 << 4 | read95;
// 		CanFDFrame04_WSCR_DATA.Impl_Sig1 = read97;
// 		CanFDFrame04_WSCR_DATA.Impl_Sig2 = read97 >> 8;
// 		CanFDFrame04_WSCR_DATA.Impl_Sig3 = read99;	
// 		CanFDFrame04_WSCR_DATA.Impl_Sig4 = read99 >> 8;
// 		CanFDFrame04_WSCR_DATA.Impl_Sig5 = read100 << 2 | read98;	
														
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame04_WSCR,&E2E_P11CheckStateType_CanFDFrame04_WSCR,(uint8 *)&CanFDFrame04_WSCR_DATA,7);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame04_WSCR.Status == 0)) || (read94 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x40] = 0;
// 			if(read98 == 3)
// 			{
// 				Fv_Ws_Rlws_raw = read97;
// 				CAN_RLWS = read97 ;
// 			}
// 			if(read100 == 3)
// 			{
// 				Fv_Ws_Rrws_raw = read99;
// 				CAN_RRWS = read99;
// 			}
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x40] = 2;
// 		}

// 		cnt = 0;
// 	}
// 	else
// 	{
// 		if(cnt > 80)
// 		{
// 			Fv_AdsTqInvalid_flag = 1;
// 			COMRxLostFlag[CANBUS_ID_0x40] = 0xAA;
// 			cnt = 80;
// 		}
// 		else
// 		{
// 			cnt ++;
// 		}
// 	}
	
// }

// static void ASW_COM_RX_MCoreBCCanFDFramefe(void)
// {
// 	uint8 read1;
// 		Std_ReturnType retRead1;
// 		uint8 read2;
// 		Std_ReturnType retRead2;
// 		uint32 read3;
// 		Std_ReturnType retRead3;
// 		static uint16 cnt = 0;
// 		if(COMRxFlag[CANBUS_ID_0xfe] == 0xAA)
// 			{
// 				COMRxFlag[CANBUS_ID_0xfe] = 0;//ï¿½ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ä°´ï¿½Õ½ï¿½ï¿½Õ±ï¿½ï¿½Äµï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿?
// 				retRead1 = Rte_Read_RPort_UTCTimeLite_UB_UTCTimeLite_UB(&read1);
// 				retRead2 = Rte_Read_RPort_UTCTimeLiteDataValid_UTCTimeLiteDataValid(&read2);
// 				retRead3 = Rte_Read_RPort_UTCTimeLiteUtcTiVal_UTCTimeLiteUtcTiVal(&read3);
// 				cnt = 0;
// 				if(read2 == 0x00)
// 				{
// 				     G_timestamp = read3 ;
// 				}
// 				else
// 				{
// 					 G_timestamp = 0 ;
// 				}
// 			}
// 		else
// 		{
// 			cnt ++;
// 			if(cnt >= 1000)//ï¿½ï¿½ï¿½Õµï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Äµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// 			{
// 				cnt = 1000;
// 				G_timestamp = 0 ;
// 			}

// 		}
// }

// static void ASW_COM_RX_MCoreBCCanFDFrame07(void)
// {
// 	static	E2E_ImpleDataType_CanFDFrame07_GLI CanFDFrame07_GLI_DATA;
// 	static	E2E_ImpleDataType_CanFDFrame07_ACA CanFDFrame07_ACA_DATA;
// 	static	E2E_ImpleDataType_CanFDFrame07_PTA CanFDFrame07_PTA_DATA;
// 	uint8 read30;
// 		Std_ReturnType retRead30;
// 		uint8 read31;
// 		Std_ReturnType retRead31;
// 		uint8 read32;
// 		Std_ReturnType retRead32;
// 		uint8 read33;
// 		Std_ReturnType retRead33;
// 		uint8 read34;
// 		Std_ReturnType retRead34;
// 		uint8 read35;
// 		Std_ReturnType retRead35;
// 		uint8 read36;
// 		Std_ReturnType retRead36;
// 		uint8 read37;
// 		Std_ReturnType retRead37;
// 		uint8 read38;
// 		Std_ReturnType retRead38;
// 		uint8 read39;
// 		Std_ReturnType retRead39;
// 		uint8 read40;
// 		Std_ReturnType retRead40;
// 		uint8 read41;
// 		Std_ReturnType retRead41;
// 		uint8 read42;
// 		Std_ReturnType retRead42;
// 		uint8 read43;
// 		Std_ReturnType retRead43;
// 		uint16 read44;
// 		Std_ReturnType retRead44;
// 		uint16 read45;
// 		Std_ReturnType retRead45;
// 		uint16 read46;
// 		Std_ReturnType retRead46;
// 		uint8 read47;
// 		Std_ReturnType retRead47;
// 		uint8 read48;
// 		Std_ReturnType retRead48;
// 		uint32 read49;
// 		Std_ReturnType retRead49;
// 		uint32 read50;
// 		Std_ReturnType retRead50;
// 	static uint16 cnt = 0;
// 	uint8 ret;
// 	if(COMRxFlag[CANBUS_ID_0x234] == 0xAA)
// 	{
// 	 COMRxFlag[CANBUS_ID_0x234] = 0;//ï¿½ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ä°´ï¿½Õ½ï¿½ï¿½Õ±ï¿½ï¿½Äµï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿?
// 		cnt=0;//��ʧ������0
// 		COMRxLostFlag[CANBUS_ID_0x234] = 0;
// 		retRead30 = Rte_Read_RPort_AbsCtrlActv_UB_AbsCtrlActv_UB(&read30);
// 		retRead31 = Rte_Read_RPort_AbsCtrlActvChks8_AbsCtrlActvChks8(&read31);
// 		retRead32 = Rte_Read_RPort_AbsCtrlActvCntr4_AbsCtrlActvCntr4(&read32);
// 		retRead33 = Rte_Read_RPort_AbsCtrlActvCtrlSts1_AbsCtrlActvCtrlSts1(&read33);
// 		retRead34 = Rte_Read_RPort_AbsCtrlActvDataID4_AbsCtrlActvDataID4(&read34);
// 		CanFDFrame07_ACA_DATA.Impl_Cks = read31;
// 		CanFDFrame07_ACA_DATA.Impl_Cnt = read34 << 4 | read32;
// 		CanFDFrame07_ACA_DATA.Impl_Sig1 = read33;	
														
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame07_ACA,&E2E_P11CheckStateType_CanFDFrame07_ACA,(uint8 *)&CanFDFrame07_ACA_DATA,3);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame07_ACA.Status == 0)) || (read31 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x234] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x234] = 2;
// 		}

// 		retRead35 = Rte_Read_RPort_GearLvrIndcn_UB_GearLvrIndcn_UB(&read35);
// 		retRead36 = Rte_Read_RPort_GearLvrIndcn2_GearLvrIndcn2(&read36);
// 		retRead37 = Rte_Read_RPort_GearLvrIndcnChks8_GearLvrIndcnChks8(&read37);
// 		retRead38 = Rte_Read_RPort_GearLvrIndcnCntr4_GearLvrIndcnCntr4(&read38);
// 		retRead39 = Rte_Read_RPort_GearLvrIndcnDataID4_GearLvrIndcnDataID4(&read39);
// 		CanFDFrame07_GLI_DATA.Impl_Cks = read37;
// 		CanFDFrame07_GLI_DATA.Impl_Cnt = read39 << 4 | read38;
// 		CanFDFrame07_GLI_DATA.Impl_Sig1 = read36;	
														
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame07_GLI,&E2E_P11CheckStateType_CanFDFrame07_GLI,(uint8 *)&CanFDFrame07_GLI_DATA,3);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame07_GLI.Status == 0)) || (read37 == 0xAA))
// 		{
// 			COMRxVailFlag1[CANBUS_ID_0x234] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag1[CANBUS_ID_0x234] = 2;
// 		}

// 		retRead40 = Rte_Read_RPort_PtTqAtWhlFrntAct_UB_PtTqAtWhlFrntAct_UB(&read40);
// 		retRead41 = Rte_Read_RPort_PtTqAtWhlFrntActChks8_PtTqAtWhlFrntActChks8(&read41);
// 		retRead42 = Rte_Read_RPort_PtTqAtWhlFrntActCntr4_PtTqAtWhlFrntActCntr4(&read42);
// 		retRead43 = Rte_Read_RPort_PtTqAtWhlFrntActDataID4_PtTqAtWhlFrntActDataID4(&read43);
// 		retRead44 = Rte_Read_RPort_PtTqAtWhlFrntActPtTqAtAxleFrntAc_PtTqAtWhlFrntActPtTqAtAxleFrntAc(&read44);
// 		retRead45 = Rte_Read_RPort_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_PtTqAtWhlFrntActPtTqAtWhlFrntLeA(&read45);
// 		retRead46 = Rte_Read_RPort_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_PtTqAtWhlFrntActPtTqAtWhlFrntRiA(&read46);
// 		retRead47 = Rte_Read_RPort_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_PtTqAtWhlFrntActPtTqAtWhlsFrntQl(&read47);
// 		CanFDFrame07_PTA_DATA.Impl_Cks = read41;
// 		CanFDFrame07_PTA_DATA.Impl_Cnt = read43 << 4 | read42;
// 		CanFDFrame07_PTA_DATA.Impl_Sig1 = read44;	
// 		CanFDFrame07_PTA_DATA.Impl_Sig2 = read44 >> 8;	
// 		CanFDFrame07_PTA_DATA.Impl_Sig3 = read45;
// 		CanFDFrame07_PTA_DATA.Impl_Sig4 = read45 >> 8;
// 		CanFDFrame07_PTA_DATA.Impl_Sig5 = read46;
// 		CanFDFrame07_PTA_DATA.Impl_Sig6 = read46 >> 8;	
// 		CanFDFrame07_PTA_DATA.Impl_Sig7 = read47;	

// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame07_PTA,&E2E_P11CheckStateType_CanFDFrame07_PTA,(uint8 *)&CanFDFrame07_PTA_DATA,9);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame07_PTA.Status == 0)) || (read41 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x234] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x234] = 2;
// 		}

// 		retRead48 = Rte_Read_RPort_SteerCtrlCCPtoFAS_UB_SteerCtrlCCPtoFAS_UB(&read48);
// 		retRead49 = Rte_Read_RPort_SteerCtrlCCPtoFASKey_SteerCtrlCCPtoFASKey(&read49);
// 		retRead50 = Rte_Read_RPort_SteerCtrlCCPtoFASValue_SteerCtrlCCPtoFASValue(&read50);

// 		if(read48 == 1)
// 		{
// 			CCP_DataProcess(read49, read50);
// 		}

// 	}
// 	else
// 	{//ï¿½ï¿½Ê§

// 		cnt ++;
// 		if(cnt >= 10)//ï¿½ï¿½ï¿½Õµï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Äµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// 		{
// 			COMRxLostFlag[CANBUS_ID_0x234] = 0xAA;
// 			cnt = 10;
// 		}
// 	}
// }

// static void ASW_COM_RX_ISWMBCCanFDFrame06(void)
// {
// 	static E2E_ImpleDataType_CanFDFrame06 CanFDFrame06_DATA;
// 	uint8 read136;
// 	Std_ReturnType retRead136;
// 	uint16 read137;
// 	Std_ReturnType retRead137;
// 	uint16 read138;
// 	Std_ReturnType retRead138;
// 	uint8 read139;
// 	Std_ReturnType retRead139;
// 	uint8 read140;
// 	Std_ReturnType retRead140;
// 	uint8 read141;
// 	Std_ReturnType retRead141;
// 	uint8 read142;
// 	Std_ReturnType retRead142;
// 	uint8 read143;
// 	uint8 ret;
// 	sint16 ang = 0;
// 	sint16 angspd = 0;

// 	static uint16 cnt = 0;
// 	if(COMRxFlag[CANBUS_ID_0x62] == 0xAA)
// 	{
// 		COMRxFlag[CANBUS_ID_0x62] = 0;
// 		retRead136 = Rte_Read_RPort_SteerWhlSnsr_UB_SteerWhlSnsr_UB(&read136);
// 		retRead137 = Rte_Read_RPort_SteerWhlSnsrAg_SteerWhlSnsrAg(&read137);
// 		retRead138 = Rte_Read_RPort_SteerWhlSnsrAgSpd_SteerWhlSnsrAgSpd(&read138);
// 		retRead139 = Rte_Read_RPort_SteerWhlSnsrChks8_SteerWhlSnsrChks8(&read139);
// 		retRead140 = Rte_Read_RPort_SteerWhlSnsrCntr4_SteerWhlSnsrCntr4(&read140);
// 		retRead141 = Rte_Read_RPort_SteerWhlSnsrDataID4_SteerWhlSnsrDataID4(&read141);
// 		retRead142 = Rte_Read_RPort_SteerWhlSnsrQf_SteerWhlSnsrQf(&read142);
// 		cnt=0;//ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½0
// 		COMRxLostFlag[CANBUS_ID_0x62] = 0;
// 		CanFDFrame06_DATA.Impl_Cks = read139;
// 		CanFDFrame06_DATA.Impl_Cnt = read141 << 4 | read140;
// 		CanFDFrame06_DATA.Impl_Sig1 = read137;
// 		CanFDFrame06_DATA.Impl_Sig2 = read137 >> 8;
// 		CanFDFrame06_DATA.Impl_Sig3 = read138;
// 		CanFDFrame06_DATA.Impl_Sig4 = read142 << 6 | read138 >> 8;

// 		if((read137 & 0x4000) > 0)
// 		{
// 			ang = (sint16)(read137 + 0x8000);
// 		}
// 		else
// 		{
// 			ang = read137;
// 		}

// 		if((read138 & 0x2000) > 0)
// 		{
// 			angspd = (sint16)(read138 + 0xC000);
// 		}
// 		else
// 		{
// 			angspd = read138;
// 		}

// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame06,&E2E_P11CheckStateType_CanFDFrame06,(uint8 *)&CanFDFrame06_DATA,6);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame06.Status == 0)) || (read139 == 0xAA))
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x62] = 0;
// 			if((read142 == 0)||((ang>14848)||(ang<(-14848)))||((angspd>6400)||(angspd<-6400)))
// 			{
// 				Tv_StrSASAngValid = 0;
// 			}
// 			else
// 			{
// 				Tv_StrSASAng = (sint16)((sint32)ang * 180000 / 314 / 1024);
// 				Tv_StrSASAngValid = 1;
// 			}
// 		}
// 		else
// 		{
// 			Tv_StrSASAngValid = 0;
// 			COMRxVailFlag[CANBUS_ID_0x62] = 2;
// 		}
// 	}
// 	else
// 	{//ï¿½ï¿½Ê§
// 		cnt ++;
// 		if(cnt >= 40)//ï¿½ï¿½ï¿½Õµï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Äµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// 		{
// 				COMRxLostFlag[CANBUS_ID_0x62] = 0xAA;
// 				cnt = 40;
// 				Tv_StrSASAngValid = 0;
// 		}
// 	}
// }


// /*1rad = 57.325deg*/
// #define RAD_TO_DEG 5732484
// static void ASW_COM_RX_MCoreBCCanFDFrame09(void)
// {
// 	static E2E_ImpleDataType_CanFDFrame09_ADW CanFDFrame09_ADW_DATA;
// 	static E2E_ImpleDataType_CanFDFrame09_PPA CanFDFrame09_PPA_DATA;
// 	uint16 read4;
// 		Std_ReturnType retRead4;
// 		uint8 read5;
// 		Std_ReturnType retRead5;
// 		uint16 read6;
// 		Std_ReturnType retRead6;
// 		uint8 read7;
// 		Std_ReturnType retRead7;
// 		uint8 read8;
// 		Std_ReturnType retRead8;
// 		uint8 read9;
// 		Std_ReturnType retRead9;
// 		uint8 read10;
// 		Std_ReturnType retRead10;
// 		uint8 read11;
// 		Std_ReturnType retRead11;
// 		uint8 read12;
// 		Std_ReturnType retRead12;
// 		uint8 read13;
// 		Std_ReturnType retRead13;
// 		uint16 read14;
// 		Std_ReturnType retRead14;
// 		uint8 read15;
// 		Std_ReturnType retRead15;
// 		uint8 read16;
// 		Std_ReturnType retRead16;
// 		uint8 read17;
// 		Std_ReturnType retRead17;
// 		uint8 read18;
// 		Std_ReturnType retRead18;
// 		uint16 read19;
// 		Std_ReturnType retRead19;
// 		uint8 read20;
// 		Std_ReturnType retRead20;
// 		uint16 read21;
// 		Std_ReturnType retRead21;
// 		uint8 read22;
// 		Std_ReturnType retRead22;
// 		uint8 read23;
// 		Std_ReturnType retRead23;
// 		uint8 read24;
// 		Std_ReturnType retRead24;
// 		uint8 read25;
// 		Std_ReturnType retRead25;
// 		uint16 read26;
// 		Std_ReturnType retRead26;
// 		uint8 read27;
// 		Std_ReturnType retRead27;
// 		uint8 read28;
// 		Std_ReturnType retRead28;
// 		uint8 read29;
// 		Std_ReturnType retRead29;
// 	static uint16 cnt = 0;
// 	static uint16 ubcnt = 0;
// 	uint8 ret;
// 	sint16 temp = 0;
// 		if(COMRxFlag[CANBUS_ID_0x99] == 0xAA)
// 		{
// 		 COMRxFlag[CANBUS_ID_0x99] = 0;//ï¿½ï¿½Ö¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ä°´ï¿½Õ½ï¿½ï¿½Õ±ï¿½ï¿½Äµï¿½Ê±ï¿½ï¿½ï¿½ï¿½ï¿?
// 		 retRead4 = Rte_Read_RPort_AgCtrlTqLowrLim_AgCtrlTqLowrLim(&read4);
// 		 	retRead5 = Rte_Read_RPort_AgCtrlTqLowrLim_UB_AgCtrlTqLowrLim_UB(&read5);
// 		 	retRead6 = Rte_Read_RPort_AgCtrlTqUpprLim_AgCtrlTqUpprLim(&read6);
// 		 	retRead7 = Rte_Read_RPort_AgCtrlTqUpprLim_UB_AgCtrlTqUpprLim_UB(&read7);
// 		 	retRead8 = Rte_Read_RPort_AgDataCmpQuality_UB_AgDataCmpQuality_UB(&read8);
// 		 	retRead9 = Rte_Read_RPort_AgDataCmpQualityPitchRateCmpQual_AgDataCmpQualityPitchRateCmpQual(&read9);
// 		 	retRead10 = Rte_Read_RPort_AgDataCmpQualityRollRateCmpQuali_AgDataCmpQualityRollRateCmpQuali(&read10);
// 		 	retRead11 = Rte_Read_RPort_AgDataCmpQualityYawRateCmpQualit_AgDataCmpQualityYawRateCmpQualit(&read11);
// 		 	retRead12 = Rte_Read_RPort_AsyDataWithCmpSafe_UB_AsyDataWithCmpSafe_UB(&read12);
// 		 	retRead13 = Rte_Read_RPort_AsyDataWithCmpSafeALat1Qf_AsyDataWithCmpSafeALat1Qf(&read13);
// 		 	retRead14 = Rte_Read_RPort_AsyDataWithCmpSafeALatWithCmp_AsyDataWithCmpSafeALatWithCmp(&read14);
// 		 	retRead15 = Rte_Read_RPort_AsyDataWithCmpSafeALgt1Qf_AsyDataWithCmpSafeALgt1Qf(&read15);
// 		 	retRead16 = Rte_Read_RPort_AsyDataWithCmpSafeChks8_AsyDataWithCmpSafeChks8(&read16);
// 		 	retRead17 = Rte_Read_RPort_AsyDataWithCmpSafeCntr4_AsyDataWithCmpSafeCntr4(&read17);
// 		 	retRead18 = Rte_Read_RPort_AsyDataWithCmpSafeDataID4_AsyDataWithCmpSafeDataID4(&read18);
// 		 	retRead19 = Rte_Read_RPort_AsyDataWithCmpSafeGrdtOfALgt_AsyDataWithCmpSafeGrdtOfALgt(&read19);
// 		 	retRead20 = Rte_Read_RPort_AsyDataWithCmpSafeYawRateQf_AsyDataWithCmpSafeYawRateQf(&read20);
// 		 	retRead21 = Rte_Read_RPort_AsyDataWithCmpSafeYawRateWithCmp_AsyDataWithCmpSafeYawRateWithCmp(&read21);
// 		CanFDFrame09_ADW_DATA.Impl_Cks = read16;
// 		CanFDFrame09_ADW_DATA.Impl_Cnt = read18 << 4 |read17;
// 		CanFDFrame09_ADW_DATA.Impl_Sig1 = read14;	
// 		CanFDFrame09_ADW_DATA.Impl_Sig2 = read14 >> 8;	
// 		CanFDFrame09_ADW_DATA.Impl_Sig3 = read19;
// 		CanFDFrame09_ADW_DATA.Impl_Sig4 = read13 << 6 | read19 >> 8;
// 		CanFDFrame09_ADW_DATA.Impl_Sig5 = read20 << 2 | read15;
// 		CanFDFrame09_ADW_DATA.Impl_Sig6 = read21;	
// 		CanFDFrame09_ADW_DATA.Impl_Sig7 = read21 >> 8;	
// 		if (read5==1){
// 			Fv_AdsAgTdn = -(read4 * 128-30720);
// 				Fv_LKA_TorqueCmdUpLimit = (Int16)Fv_AdsAgTdn;

// 		}else{
// 			Fv_AdsAgTdn = 0;
// 		}
// 		if(read7==1){
// 			Fv_AdsAgTup = read6 * 128-30720;
// 			Fv_LKA_TorqueCmdDownLimit = (Int16)-Fv_AdsAgTup;
// 		}else{
// 			Fv_AdsAgTup = 0;
// 		}
// 		if(read12 > 0)
// 		{
// 			ubcnt = 0;
// 			fsAsyDataWithCmpSafeValid = 1;
// 		}
// 		else
// 		{
// 			if(ubcnt > 400)
// 			{
// 				fsAsyDataWithCmpSafeValid = 0;
// 			}
// 			else
// 			{
// 				ubcnt ++;
// 			}
// 		}
// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame09_ADW,&E2E_P11CheckStateType_CanFDFrame09_ADW,(uint8 *)&CanFDFrame09_ADW_DATA,9);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame09_ADW.Status == 0)) || (read16 == 0xAA))
// 		{
// 			if(read20 == 3)
// 			{
// 				fsYawRateWithComp = read21;
// 			}
// 			COMRxVailFlag[CANBUS_ID_0x99] = 0;
// 		}
// 		else
// 		{
// 			COMRxVailFlag[CANBUS_ID_0x99] = 2;

// 		}

// 		 	retRead22 = Rte_Read_RPort_PrkgPinionAgReqGroup_UB_PrkgPinionAgReqGroup_UB(&read22);
// 		 	retRead23 = Rte_Read_RPort_PrkgPinionAgReqGroupChks8_PrkgPinionAgReqGroupChks8(&read23);
// 		 	retRead24 = Rte_Read_RPort_PrkgPinionAgReqGroupCntr4_PrkgPinionAgReqGroupCntr4(&read24);
// 		 	retRead25 = Rte_Read_RPort_PrkgPinionAgReqGroupDataID4_PrkgPinionAgReqGroupDataID4(&read25);
// 		 	retRead26 = Rte_Read_RPort_PrkgPinionAgReqGroupParkAssiPini_PrkgPinionAgReqGroupParkAssiPini(&read26);
// 		 	retRead27 = Rte_Read_RPort_PrkgPinionAgReqGroupQF_PrkgPinionAgReqGroupQF(&read27);
// 		CanFDFrame09_PPA_DATA.Impl_Cks = read23;
// 		CanFDFrame09_PPA_DATA.Impl_Cnt = read25 << 4| read24;
// 		CanFDFrame09_PPA_DATA.Impl_Sig1 = read26;	
// 		CanFDFrame09_PPA_DATA.Impl_Sig2 = read26 >> 8;	
// 		CanFDFrame09_PPA_DATA.Impl_Sig3 = read27;

// 		ret = E2E_P11Check(&E2E_P11ConfigType_CanFDFrame09_PPA,&E2E_P11CheckStateType_CanFDFrame09_PPA,(uint8 *)&CanFDFrame09_PPA_DATA,5);
// 		if(((ret == 0) && (E2E_P11CheckStateType_CanFDFrame09_PPA.Status == 0)) || (read23 == 0xAA))
// 		{
// 			if(read27 == 3)
// 			{
// 				temp = (sint16)(((sint64)((sint32)read26 - 14848)*16*RAD_TO_DEG/102400000));
// 				if(temp > 14848)
// 				{
// 					Fv_AdsParkReq  = 14848;
// 				}
// 				else if(temp < -14848)
// 				{
// 					Fv_AdsParkReq  = -14848;
// 				}
// 				else
// 				{
// 					Fv_AdsParkReq = temp;
// 				}
// 				Fv_AdsPkInvalid_flag = 0;
// 			}
// 			else
// 			{
// 				Fv_AdsPkInvalid_flag = 1;
// 			}
// 			if(Fv_EXT_SpdValidFlag != 1){
// 				Fv_AdsParkReq = 0;
// 			}

// 			COMRxVailFlag[CANBUS_ID_0x99] = 0;
// 		}
// 		else
// 		{
// 			Fv_AdsPkInvalid_flag = 1;
// 			COMRxVailFlag[CANBUS_ID_0x99] = 2;
		
// 		}
// 		Fv_APALostFlag = 0;

// 		 	retRead28 = Rte_Read_RPort_VehHomePrkgSysSts_VehHomePrkgSysSts(&read28);
// 		 	retRead29 = Rte_Read_RPort_VehHomePrkgSysSts_UB_VehHomePrkgSysSts_UB(&read29);
// 		  cnt=0;//ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½0
// 		  COMRxLostFlag[CANBUS_ID_0x99] = 0;
// 		}
// 		else
// 		{//ï¿½ï¿½Ê§

// 			cnt ++;
// 			if(cnt >= 40)//ï¿½ï¿½ï¿½Õµï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Äµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
// 			{
// 				COMRxLostFlag[CANBUS_ID_0x99] = 0xAA;
// 				cnt = 40;
// 				Fv_APALostFlag = 1;
// 			}
// 		}
// }
/*=========================================================================================*/


#include "ASW_DEM_ComDiag.h"
/****************************************** Rx ********************************************/

/**
 * @brief VddmChas1Fr47: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr47(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr47_Type{
    uint8 AgDataCmpQualityPitchRateCmpQuality : 8u;
    uint8 AgDataCmpQualityRollRateCmpQuality  : 8u;
    uint8 AgDataCmpQualityYawRateCmpQuality   : 8u;
    uint8                                     : 8u;
    uint8                                     : 8u;
    uint8 BattURaw_H                          : 1u;
    uint8                                     : 2u;
    uint8 AgDataCmpQuality_UB                 : 1u;
    uint8 EgyRgnLvlSet_UB                     : 1u;
    uint8 EgyRgnLvlSet                        : 2u;
    uint8 BattURaw_UB                         : 1u;
    uint8 BattURaw_L                          : 8u;
    uint8                                     : 8u;
  } *p_VddmChas1Fr47_Data = (struct VddmChas1Fr47_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr47: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr47(void)
{
}

/**
 * @brief AsdmChas1Fr03: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_AsdmChas1Fr03(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct AsdmChas1Fr03_Type{
    uint8 AgCtrlTqLowrLim_H                    : 7u;
    uint8 AsyPinionAgReqSafe_UB                : 1u;
    uint8                                      : 5u;
    uint8 AgCtrlTqLowrLim_UB                   : 1u;
    uint8 AgCtrlTqLowrLim_L                    : 2u;
    uint8 AsyPinionAgReqSafeAsyPinionAgReq_H   : 8u;
    uint8                                      : 1u;
    uint8 AsyPinionAgReqSafeAsyPinionAgReq_L   : 7u;
    uint8 AsyPinionAgReqSafeAsyPinionAgReqChks : 8u;
    uint8 AgCtrlTqUpprLim_H                    : 4u;
    uint8 AsyPinionAgReqSafeAsyPinionAgReqCntr : 4u;
    uint8                                      : 2u;
    uint8 AgCtrlTqUpprLim_UB                   : 1u;
    uint8 AgCtrlTqUpprLim_L                    : 5u;
    uint8                                      : 8u;
  } *p_AsdmChas1Fr03_Data = (struct AsdmChas1Fr03_Type *)ptr->SduDataPtr;

  uint8 Data_AsyPinionAgReqSafe[4] = {0};

  ComDiag_DealFault_C16882(DTC_C16882_FAULT_Msg_33_Missing, FAULT_CLEAR);

  if (p_AsdmChas1Fr03_Data->AgCtrlTqLowrLim_UB)
  {
    ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqLowrLim_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqLowrLim_UB, FAULT_SET);
  }

  if (p_AsdmChas1Fr03_Data->AgCtrlTqUpprLim_UB)
  {
    ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqUpprLim_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C16882(DTC_C16882_FAULT_AgCtrlTqUpprLim_UB, FAULT_SET);
  }

  if (p_AsdmChas1Fr03_Data->AsyPinionAgReqSafe_UB)
  {
    uint16 AsyPinionAgReqSafeAsyPinionAgReq = ((uint16)p_AsdmChas1Fr03_Data->AsyPinionAgReqSafeAsyPinionAgReq_H << 7u) + ((uint16)p_AsdmChas1Fr03_Data->AsyPinionAgReqSafeAsyPinionAgReq_L);

    Data_AsyPinionAgReqSafe[0] = (uint8)p_AsdmChas1Fr03_Data->AsyPinionAgReqSafeAsyPinionAgReqChks;
    Data_AsyPinionAgReqSafe[1] = (uint8)p_AsdmChas1Fr03_Data->AsyPinionAgReqSafeAsyPinionAgReqCntr;
    Data_AsyPinionAgReqSafe[2] = (uint8)(AsyPinionAgReqSafeAsyPinionAgReq >> (8u * 0));
    Data_AsyPinionAgReqSafe[3] = (uint8)(AsyPinionAgReqSafeAsyPinionAgReq >> (8u * 1));
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyPinionAgReqSafe.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyPinionAgReqSafe,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyPinionAgReqSafe,
                       Data_AsyPinionAgReqSafe);
    ComDiag_DealFault_C16882(DTC_C16882_FAULT_AsyPinionAgReqSafe_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C16882(DTC_C16882_FAULT_AsyPinionAgReqSafe_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyPinionAgReqSafe.Status)
  {
    ComDiag_DealFault_E72783(DTC_E72783_FAULT_AsyPinionAgReqSafeAsyPinionAgReq_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_E72783(DTC_E72783_FAULT_AsyPinionAgReqSafeAsyPinionAgReq_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyPinionAgReqSafe.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief AsdmChas1Fr03: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_AsdmChas1Fr03(void)
{
  ComDiag_DealFault_C16882(DTC_C16882_FAULT_Msg_33_Missing, FAULT_SET);
}

/**
 * @brief SasChas1Fr01: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_SasChas1Fr01(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct SasChas1Fr01_Type{
    uint8 SteerWhlSnsrAg_H    : 7u;
    uint8 SteerWhlSnsr_UB     : 1u;
    uint8 SteerWhlSnsrAg_L    : 8u;
    uint8 SteerWhlSnsrAgSpd_H : 6u;
    uint8 SteerWhlSnsrQf      : 2u;
    uint8 SteerWhlSnsrAgSpd_L : 8u;
    uint8 SteerWhlSnsrChks    : 8u;
    uint8                     : 4u;
    uint8 SteerWhlSnsrCntr    : 4u;
    uint8                     : 8u;
    uint8                     : 8u;
  } *p_SasChas1Fr01_Data = (struct SasChas1Fr01_Type *)ptr->SduDataPtr;

  uint8 Data_SteerWhlSnsr[7] = {0};

  if (p_SasChas1Fr01_Data->SteerWhlSnsr_UB)
  {
    uint16 SteerWhlSnsrAg = ((uint16)p_SasChas1Fr01_Data->SteerWhlSnsrAg_H << 8u) + ((uint16)p_SasChas1Fr01_Data->SteerWhlSnsrAg_L);
    uint16 SteerWhlSnsrAgSpd = ((uint16)p_SasChas1Fr01_Data->SteerWhlSnsrAgSpd_H << 8u) + ((uint16)p_SasChas1Fr01_Data->SteerWhlSnsrAgSpd_L);

    Data_SteerWhlSnsr[0] = (uint8)p_SasChas1Fr01_Data->SteerWhlSnsrChks;
    Data_SteerWhlSnsr[1] = (uint8)p_SasChas1Fr01_Data->SteerWhlSnsrCntr;
    Data_SteerWhlSnsr[2] = (uint8)(SteerWhlSnsrAg >> (8u * 0));
    Data_SteerWhlSnsr[3] = (uint8)(SteerWhlSnsrAg >> (8u * 1));
    Data_SteerWhlSnsr[4] = (uint8)(SteerWhlSnsrAgSpd >> (8u * 0));
    Data_SteerWhlSnsr[5] = (uint8)(SteerWhlSnsrAgSpd >> (8u * 1));
    Data_SteerWhlSnsr[6] = (uint8)p_SasChas1Fr01_Data->SteerWhlSnsrQf;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_SteerWhlSnsr.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_SteerWhlSnsr,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_SteerWhlSnsr,
                       Data_SteerWhlSnsr);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_SteerWhlSnsr.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief SasChas1Fr01: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_SasChas1Fr01(void)
{
}

/**
 * @brief VddmChas1Fr01: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr01(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr01_Type{
    uint8 AsyDataWithCmpSafeYawRateWithCmp_H : 8u;
    uint8 AsyDataWithCmpSafeYawRateWithCmp_L : 8u;
    uint8 AsyDataWithCmpSafeChks             : 8u;
    uint8 AsyDataWithCmpSafeGrdtOfALgt_H     : 8u;
    uint8 AsyDataWithCmpSafeYawRateQf        : 2u;
    uint8 AsyDataWithCmpSafeGrdtOfALgt_L     : 6u;
    uint8 AsyDataWithCmpSafeALat1Qf          : 2u;
    uint8 AsyDataWithCmpSafeALgt1Qf          : 2u;
    uint8 AsyDataWithCmpSafeCntr             : 4u;
    uint8 AsyDataWithCmpSafeALatWithCmp_H    : 8u;
    uint8 AsyDataWithCmpSafe_UB              : 1u;
    uint8 AsyDataWithCmpSafeALatWithCmp_L    : 7u;
  } *p_VddmChas1Fr01_Data = (struct VddmChas1Fr01_Type *)ptr->SduDataPtr;

  uint8 Data_AsyDataWithCmpSafe[11] = {0};

  if (p_VddmChas1Fr01_Data->AsyDataWithCmpSafe_UB)
  {
    uint16 AsyDataWithCmpSafeALatWithCmp = ((uint16)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeALatWithCmp_H << 7u) + ((uint16)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeALatWithCmp_L);
    uint16 AsyDataWithCmpSafeGrdtOfALgt = ((uint16)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeGrdtOfALgt_H << 6u) + ((uint16)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeGrdtOfALgt_L);
    uint16 AsyDataWithCmpSafeYawRateWithCmp = ((uint16)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeYawRateWithCmp_H << 8u) + ((uint16)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeYawRateWithCmp_L);

    Data_AsyDataWithCmpSafe[0] = (uint8)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeChks;
    Data_AsyDataWithCmpSafe[1] = (uint8)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeCntr;
    Data_AsyDataWithCmpSafe[2] = (uint8)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeALat1Qf;
    Data_AsyDataWithCmpSafe[3] = (uint8)(AsyDataWithCmpSafeALatWithCmp >> (8u * 0));
    Data_AsyDataWithCmpSafe[4] = (uint8)(AsyDataWithCmpSafeALatWithCmp >> (8u * 1));
    Data_AsyDataWithCmpSafe[5] = (uint8)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeALgt1Qf;
    Data_AsyDataWithCmpSafe[6] = (uint8)(AsyDataWithCmpSafeGrdtOfALgt >> (8u * 0));
    Data_AsyDataWithCmpSafe[7] = (uint8)(AsyDataWithCmpSafeGrdtOfALgt >> (8u * 1));
    Data_AsyDataWithCmpSafe[8] = (uint8)p_VddmChas1Fr01_Data->AsyDataWithCmpSafeYawRateQf;
    Data_AsyDataWithCmpSafe[9] = (uint8)(AsyDataWithCmpSafeYawRateWithCmp >> (8u * 0));
    Data_AsyDataWithCmpSafe[10] = (uint8)(AsyDataWithCmpSafeYawRateWithCmp >> (8u * 1));
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyDataWithCmpSafe.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyDataWithCmpSafe,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyDataWithCmpSafe,
                       Data_AsyDataWithCmpSafe);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyDataWithCmpSafe.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr01: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr01(void)
{
}

/**
 * @brief VdcuIemChas1Fr01: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VdcuIemChas1Fr01(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VdcuIemChas1Fr01_Type{
    uint8 GVMCSteerWhlAgReqFrntAgReqFrnt_H : 7u;
    uint8 GVMCSteerWhlAgReqFrnt_UB         : 1u;
    uint8 GVMCSteerWhlAgReqFrntAgReqFrnt_L : 8u;
    uint8 GVMCSteerWhlAgReqFrntChks        : 8u;
    uint8 GVMCSteerWhlAgReqFrntTqReqFrnt   : 8u;
    uint8                                  : 1u;
    uint8 GVMCSteerWhlAgReqFrntCtrlModFrnt : 3u;
    uint8 GVMCSteerWhlAgReqFrntCntr        : 4u;
    uint8                                  : 8u;
    uint8 CrabMovModStsCntr                : 4u;
    uint8 CrabMovModStsTankTurnModSts      : 3u;
    uint8 CrabMovModSts_UB                 : 1u;
    uint8 CrabMovModStsChks                : 8u;
  } *p_VdcuIemChas1Fr01_Data = (struct VdcuIemChas1Fr01_Type *)ptr->SduDataPtr;

  uint8 Data_GVMCSteerWhlAgReqFrnt[6] = {0};

  ComDiag_DealFault_C29682(DTC_C29682_FAULT_Msg_5B_Missing, FAULT_CLEAR);

  if (p_VdcuIemChas1Fr01_Data->CrabMovModSts_UB)
  {
    ComDiag_DealFault_C29682(DTC_C29682_FAULT_CrabMovModSts_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C29682(DTC_C29682_FAULT_CrabMovModSts_UB, FAULT_SET);
  }

  if (p_VdcuIemChas1Fr01_Data->GVMCSteerWhlAgReqFrnt_UB)
  {
    uint16 GVMCSteerWhlAgReqFrntAgReqFrnt = ((uint16)p_VdcuIemChas1Fr01_Data->GVMCSteerWhlAgReqFrntAgReqFrnt_H << 8u) + ((uint16)p_VdcuIemChas1Fr01_Data->GVMCSteerWhlAgReqFrntAgReqFrnt_L);

    Data_GVMCSteerWhlAgReqFrnt[0] = (uint8)p_VdcuIemChas1Fr01_Data->GVMCSteerWhlAgReqFrntChks;
    Data_GVMCSteerWhlAgReqFrnt[1] = (uint8)p_VdcuIemChas1Fr01_Data->GVMCSteerWhlAgReqFrntCntr;
    Data_GVMCSteerWhlAgReqFrnt[2] = (uint8)(GVMCSteerWhlAgReqFrntAgReqFrnt >> (8u * 0));
    Data_GVMCSteerWhlAgReqFrnt[3] = (uint8)(GVMCSteerWhlAgReqFrntAgReqFrnt >> (8u * 1));
    Data_GVMCSteerWhlAgReqFrnt[4] = (uint8)p_VdcuIemChas1Fr01_Data->GVMCSteerWhlAgReqFrntCtrlModFrnt;
    Data_GVMCSteerWhlAgReqFrnt[5] = (uint8)p_VdcuIemChas1Fr01_Data->GVMCSteerWhlAgReqFrntTqReqFrnt;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt,
                       Data_GVMCSteerWhlAgReqFrnt);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VdcuIemChas1Fr01: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VdcuIemChas1Fr01(void)
{
  ComDiag_DealFault_C29682(DTC_C29682_FAULT_Msg_5B_Missing, FAULT_SET);
}

/**
 * @brief VddmChas1Fr24: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr24(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr24_Type{
    uint8 WhlFastSpdSafeCntr : 4u;
    uint8 WhlFastSpdSafeQF   : 2u;
    uint8 WhlFastSpdSafe_UB  : 1u;
    uint8                    : 1u;
    uint8 WhlFastSpdSafeA_H  : 7u;
    uint8                    : 1u;
    uint8 WhlFastSpdSafeA_L  : 8u;
    uint8 WhlFastSpdSafeChks : 8u;
    uint8                    : 8u;
    uint8                    : 8u;
    uint8                    : 8u;
    uint8                    : 8u;
  } *p_VddmChas1Fr24_Data = (struct VddmChas1Fr24_Type *)ptr->SduDataPtr;

  uint8 Data_WhlFastSpdSafe[5] = {0};

  if (p_VddmChas1Fr24_Data->WhlFastSpdSafe_UB)
  {
    uint16 WhlFastSpdSafeA = ((uint16)p_VddmChas1Fr24_Data->WhlFastSpdSafeA_H << 8u) + ((uint16)p_VddmChas1Fr24_Data->WhlFastSpdSafeA_L);

    Data_WhlFastSpdSafe[0] = (uint8)p_VddmChas1Fr24_Data->WhlFastSpdSafeChks;
    Data_WhlFastSpdSafe[1] = (uint8)p_VddmChas1Fr24_Data->WhlFastSpdSafeCntr;
    Data_WhlFastSpdSafe[2] = (uint8)(WhlFastSpdSafeA >> (8u * 0));
    Data_WhlFastSpdSafe[3] = (uint8)(WhlFastSpdSafeA >> (8u * 1));
    Data_WhlFastSpdSafe[4] = (uint8)p_VddmChas1Fr24_Data->WhlFastSpdSafeQF;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlFastSpdSafe.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlFastSpdSafe,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlFastSpdSafe,
                       Data_WhlFastSpdSafe);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlFastSpdSafe.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr24: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr24(void)
{
}

/**
 * @brief AsdmChas1Fr01: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_AsdmChas1Fr01(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct AsdmChas1Fr01_Type{
    uint8                            : 2u;
    uint8 AsySftyStandStillReq_UB    : 1u;
    uint8                            : 2u;
    uint8 AsySftyStandStillReq       : 1u;
    uint8                            : 4u;
    uint8 RcwmBrkReqQM_UB            : 1u;
    uint8 RcwmBrkReqQM               : 1u;
    uint8 RctaBrkReqQM_UB            : 1u;
    uint8 RctaBrkReqQM               : 1u;
    uint8 PASFuncActive_UB           : 1u;
    uint8 PASFuncActive              : 1u;
    uint8 AsyADL3FuncCtrlStsChks     : 8u;
    uint8 AsyADL3FuncCtrlStsQf       : 2u;
    uint8 AsyADL3FuncCtrlStsADMod    : 2u;
    uint8 AsyADL3FuncCtrlStsCntr     : 4u;
    uint8 AsyADL3FuncCtrlSts_UB      : 1u;
    uint8 AsyADL3FuncCtrlStsCtrlSts  : 1u;
    uint8 AsyADL3FuncCtrlStsSts      : 2u;
    uint8 AsyADL3FuncCtrlStsDegraded : 4u;
    uint8 AsyADModeReqChks           : 8u;
    uint8 AsyADModeReq_UB            : 1u;
    uint8 AsyADModeReqADDeactiveReq  : 1u;
    uint8 AsyADModeReqADActiveReq    : 2u;
    uint8 AsyADModeReqCntr           : 4u;
    uint8                            : 8u;
  } *p_AsdmChas1Fr01_Data = (struct AsdmChas1Fr01_Type *)ptr->SduDataPtr;

  uint8 Data_AsyADL3FuncCtrlSts[7] = {0};
  uint8 Data_AsyADModeReq[4] = {0};

  if (p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlSts_UB)
  {

    Data_AsyADL3FuncCtrlSts[0] = (uint8)p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlStsChks;
    Data_AsyADL3FuncCtrlSts[1] = (uint8)p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlStsCntr;
    Data_AsyADL3FuncCtrlSts[2] = (uint8)p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlStsADMod;
    Data_AsyADL3FuncCtrlSts[3] = (uint8)p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlStsCtrlSts;
    Data_AsyADL3FuncCtrlSts[4] = (uint8)p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlStsDegraded;
    Data_AsyADL3FuncCtrlSts[5] = (uint8)p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlStsQf;
    Data_AsyADL3FuncCtrlSts[6] = (uint8)p_AsdmChas1Fr01_Data->AsyADL3FuncCtrlStsSts;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyADL3FuncCtrlSts,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts,
                       Data_AsyADL3FuncCtrlSts);
  }
  if (p_AsdmChas1Fr01_Data->AsyADModeReq_UB)
  {

    Data_AsyADModeReq[0] = (uint8)p_AsdmChas1Fr01_Data->AsyADModeReqChks;
    Data_AsyADModeReq[1] = (uint8)p_AsdmChas1Fr01_Data->AsyADModeReqCntr;
    Data_AsyADModeReq[2] = (uint8)p_AsdmChas1Fr01_Data->AsyADModeReqADActiveReq;
    Data_AsyADModeReq[3] = (uint8)p_AsdmChas1Fr01_Data->AsyADModeReqADDeactiveReq;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADModeReq.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyADModeReq,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADModeReq,
                       Data_AsyADModeReq);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts.Status;
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADModeReq.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief AsdmChas1Fr01: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_AsdmChas1Fr01(void)
{
}

/**
 * @brief VddmChas1Fr03: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr03(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr03_Type{
    uint8 ADataRawSafeChks      : 8u;
    uint8 ADataRawSafeALgt1Qf   : 2u;
    uint8 ADataRawSafeALat1Qf   : 2u;
    uint8 ADataRawSafeCntr      : 4u;
    uint8 ADataRawSafeALat_H    : 8u;
    uint8 ADataRawSafeAVertQf_H : 1u;
    uint8 ADataRawSafeALat_L    : 7u;
    uint8 ADataRawSafeALgt_H    : 7u;
    uint8 ADataRawSafeAVertQf_L : 1u;
    uint8 ADataRawSafeALgt_L    : 8u;
    uint8 ADataRawSafeAVert_H   : 8u;
    uint8 ADataRawSafe_UB       : 1u;
    uint8 ADataRawSafeAVert_L   : 7u;
  } *p_VddmChas1Fr03_Data = (struct VddmChas1Fr03_Type *)ptr->SduDataPtr;

  uint8 Data_ADataRawSafe[11] = {0};

  if (p_VddmChas1Fr03_Data->ADataRawSafe_UB)
  {
    uint16 ADataRawSafeALat = ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeALat_H << 7u) + ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeALat_L);
    uint16 ADataRawSafeALgt = ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeALgt_H << 8u) + ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeALgt_L);
    uint16 ADataRawSafeAVert = ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeAVert_H << 7u) + ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeAVert_L);
    uint16 ADataRawSafeAVertQf = ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeAVertQf_H << 1u) + ((uint16)p_VddmChas1Fr03_Data->ADataRawSafeAVertQf_L);

    Data_ADataRawSafe[0] = (uint8)p_VddmChas1Fr03_Data->ADataRawSafeChks;
    Data_ADataRawSafe[1] = (uint8)p_VddmChas1Fr03_Data->ADataRawSafeCntr;
    Data_ADataRawSafe[2] = (uint8)(ADataRawSafeALat >> (8u * 0));
    Data_ADataRawSafe[3] = (uint8)(ADataRawSafeALat >> (8u * 1));
    Data_ADataRawSafe[4] = (uint8)p_VddmChas1Fr03_Data->ADataRawSafeALat1Qf;
    Data_ADataRawSafe[5] = (uint8)(ADataRawSafeALgt >> (8u * 0));
    Data_ADataRawSafe[6] = (uint8)(ADataRawSafeALgt >> (8u * 1));
    Data_ADataRawSafe[7] = (uint8)p_VddmChas1Fr03_Data->ADataRawSafeALgt1Qf;
    Data_ADataRawSafe[8] = (uint8)(ADataRawSafeAVert >> (8u * 0));
    Data_ADataRawSafe[9] = (uint8)(ADataRawSafeAVert >> (8u * 1));
    Data_ADataRawSafe[10] = (uint8)(ADataRawSafeAVertQf >> (8u * 0));
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_ADataRawSafe.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_ADataRawSafe,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_ADataRawSafe,
                       Data_ADataRawSafe);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_ADataRawSafe.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr03: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr03(void)
{
}

/**
 * @brief VddmChas1Fr05: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr05(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr05_Type{
    uint8 EngRunngReqByParkAssiCntr : 4u;
    uint8 EngRunngReqByParkAssi1    : 2u;
    uint8 EngRunngReqByParkAssi_UB  : 1u;
    uint8                           : 1u;
    uint8 EngRunngReqByParkAssiChks : 8u;
    uint8 CnvnReq_UB                : 1u;
    uint8                           : 4u;
    uint8 CnvnReq                   : 3u;
    uint8                           : 8u;
    uint8 VehSpdLgtA_H              : 7u;
    uint8 VehSpdLgt_UB              : 1u;
    uint8 VehSpdLgtA_L              : 8u;
    uint8 VehSpdLgtChks             : 8u;
    uint8                           : 2u;
    uint8 VehSpdLgtQf               : 2u;
    uint8 VehSpdLgtCntr             : 4u;
  } *p_VddmChas1Fr05_Data = (struct VddmChas1Fr05_Type *)ptr->SduDataPtr;

  uint8 Data_EngRunngReqByParkAssi[3] = {0};
  uint8 Data_VehSpdLgt[5] = {0};

  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_E0_Missing, FAULT_CLEAR);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_E0_Missing, FAULT_CLEAR);

  if (p_VddmChas1Fr05_Data->EngRunngReqByParkAssi_UB)
  {

    Data_EngRunngReqByParkAssi[0] = (uint8)p_VddmChas1Fr05_Data->EngRunngReqByParkAssiChks;
    Data_EngRunngReqByParkAssi[1] = (uint8)p_VddmChas1Fr05_Data->EngRunngReqByParkAssiCntr;
    Data_EngRunngReqByParkAssi[2] = (uint8)p_VddmChas1Fr05_Data->EngRunngReqByParkAssi1;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_EngRunngReqByParkAssi.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_EngRunngReqByParkAssi,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_EngRunngReqByParkAssi,
                       Data_EngRunngReqByParkAssi);
  }
  if (p_VddmChas1Fr05_Data->VehSpdLgt_UB)
  {
    uint16 VehSpdLgtA = ((uint16)p_VddmChas1Fr05_Data->VehSpdLgtA_H << 8u) + ((uint16)p_VddmChas1Fr05_Data->VehSpdLgtA_L);

    Data_VehSpdLgt[0] = (uint8)p_VddmChas1Fr05_Data->VehSpdLgtChks;
    Data_VehSpdLgt[1] = (uint8)p_VddmChas1Fr05_Data->VehSpdLgtCntr;
    Data_VehSpdLgt[2] = (uint8)(VehSpdLgtA >> (8u * 0));
    Data_VehSpdLgt[3] = (uint8)(VehSpdLgtA >> (8u * 1));
    Data_VehSpdLgt[4] = (uint8)p_VddmChas1Fr05_Data->VehSpdLgtQf;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehSpdLgt.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehSpdLgt,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehSpdLgt,
                       Data_VehSpdLgt);
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_VehSpdLgt_UB, FAULT_CLEAR);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_VehSpdLgt_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_VehSpdLgt_UB, FAULT_SET);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_VehSpdLgt_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehSpdLgt.Status)
  {
    ComDiag_DealFault_ED3683(DTC_ED3683_FAULT_VehSpdLgt_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED3683(DTC_ED3683_FAULT_VehSpdLgt_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_EngRunngReqByParkAssi.Status;
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehSpdLgt.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr05: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr05(void)
{
  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_E0_Missing, FAULT_SET);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_E0_Missing, FAULT_SET);
}

/**
 * @brief PasChas1Fr02: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_PasChas1Fr02(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct PasChas1Fr02_Type{
    uint8 PrkgPinionAgReqGroupParkAssiPinionAgReqChks : 8u;
    uint8                                             : 2u;
    uint8 PrkgPinionAgReqGroupQF                      : 2u;
    uint8 PrkgPinionAgReqGroupParkAssiPinionAgReqCntr : 4u;
    uint8 PrkgPinionAgReqGroupParkAssiPinionAgReq_H   : 8u;
    uint8 PrkgPinionAgReqGroup_UB                     : 1u;
    uint8 PrkgPinionAgReqGroupParkAssiPinionAgReq_L   : 7u;
    uint8                                             : 8u;
    uint8                                             : 8u;
    uint8 UturnTrqRelsChks                            : 8u;
    uint8                                             : 2u;
    uint8 UturnTrqRels_UB                             : 1u;
    uint8 UturnTrqRelsUturnTrqRels                    : 1u;
    uint8 UturnTrqRelsCntr                            : 4u;
  } *p_PasChas1Fr02_Data = (struct PasChas1Fr02_Type *)ptr->SduDataPtr;

  uint8 Data_PrkgPinionAgReqGroup[5] = {0};

  ComDiag_DealFault_C15982(DTC_C15982_FAULT_Msg_EB_Missing, FAULT_CLEAR);
  ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_Msg_EB_Missing, FAULT_CLEAR);

  if (p_PasChas1Fr02_Data->UturnTrqRels_UB)
  {
    ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_UturnTrqRels_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_UturnTrqRels_UB, FAULT_SET);
  }

  if (p_PasChas1Fr02_Data->PrkgPinionAgReqGroup_UB)
  {
    uint16 PrkgPinionAgReqGroupParkAssiPinionAgReq = ((uint16)p_PasChas1Fr02_Data->PrkgPinionAgReqGroupParkAssiPinionAgReq_H << 7u) + ((uint16)p_PasChas1Fr02_Data->PrkgPinionAgReqGroupParkAssiPinionAgReq_L);

    Data_PrkgPinionAgReqGroup[0] = (uint8)p_PasChas1Fr02_Data->PrkgPinionAgReqGroupParkAssiPinionAgReqChks;
    Data_PrkgPinionAgReqGroup[1] = (uint8)p_PasChas1Fr02_Data->PrkgPinionAgReqGroupParkAssiPinionAgReqCntr;
    Data_PrkgPinionAgReqGroup[2] = (uint8)(PrkgPinionAgReqGroupParkAssiPinionAgReq >> (8u * 0));
    Data_PrkgPinionAgReqGroup[3] = (uint8)(PrkgPinionAgReqGroupParkAssiPinionAgReq >> (8u * 1));
    Data_PrkgPinionAgReqGroup[4] = (uint8)p_PasChas1Fr02_Data->PrkgPinionAgReqGroupQF;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PrkgPinionAgReqGroup,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup,
                       Data_PrkgPinionAgReqGroup);
    ComDiag_DealFault_C15982(DTC_C15982_FAULT_PrkgPinionAgReqGroup_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C15982(DTC_C15982_FAULT_PrkgPinionAgReqGroup_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup.Status)
  {
    ComDiag_DealFault_E7B283(DTC_E7B283_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_SET);
    ComDiag_DealFault_ED4183(DTC_ED4183_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_E7B283(DTC_E7B283_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_CLEAR);
    ComDiag_DealFault_ED4183(DTC_ED4183_FAULT_PrkgPinionAgReqGroup_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief PasChas1Fr02: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_PasChas1Fr02(void)
{
  ComDiag_DealFault_C15982(DTC_C15982_FAULT_Msg_EB_Missing, FAULT_SET);
  ComDiag_DealFault_E7B182(DTC_E7B182_FAULT_Msg_EB_Missing, FAULT_SET);
}

/**
 * @brief ZcudChas1Fr02: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_ZcudChas1Fr02(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct ZcudChas1Fr02_Type{
    uint8 VehCfgPrmExt2BlkIDBytePosn1 : 8u;
    uint8 VehCfgPrmExt2CCPBytePosn2   : 8u;
    uint8 VehCfgPrmExt2CCPBytePosn3   : 8u;
    uint8 VehCfgPrmExt2CCPBytePosn4   : 8u;
    uint8 VehCfgPrmExt2CCPBytePosn5   : 8u;
    uint8 VehCfgPrmExt2CCPBytePosn6   : 8u;
    uint8 VehCfgPrmExt2CCPBytePosn7   : 8u;
    uint8 VehCfgPrmExt2CCPBytePosn8   : 8u;
  } *p_ZcudChas1Fr02_Data = (struct ZcudChas1Fr02_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief ZcudChas1Fr02: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_ZcudChas1Fr02(void)
{
}

/**
 * @brief VcuChas1Fr06: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VcuChas1Fr06(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VcuChas1Fr06_Type{
    uint8 TiAndDateIndcnSec1      : 6u;
    uint8 TiAndDateIndcnDataValid : 1u;
    uint8 TiAndDateIndcn_UB       : 1u;
    uint8 TiAndDateIndcnMins1     : 6u;
    uint8                         : 2u;
    uint8 TiAndDateIndcnHr1       : 5u;
    uint8                         : 3u;
    uint8 TiAndDateIndcnDay       : 5u;
    uint8                         : 3u;
    uint8 TiAndDateIndcnMth1      : 4u;
    uint8                         : 4u;
    uint8 TiAndDateIndcnYr1       : 7u;
    uint8                         : 8u;
    uint8                         : 8u;
    uint8                         : 1u;
  } *p_VcuChas1Fr06_Data = (struct VcuChas1Fr06_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VcuChas1Fr06: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VcuChas1Fr06(void)
{
}

/**
 * @brief VddmChas1Fr04: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr04(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr04_Type{
    uint8 AbsCtrlActvChks                   : 8u;
    uint8                                   : 2u;
    uint8 AbsCtrlActv_UB                    : 1u;
    uint8 AbsCtrlActvCtrlSts1               : 1u;
    uint8 AbsCtrlActvCntr                   : 4u;
    uint8 LatCtrlReqSafeChks                : 8u;
    uint8 LatCtrlReqSafeLatCtrlModReq       : 4u;
    uint8 LatCtrlReqSafeCntr                : 4u;
    uint8 LatCtrlReqSafeSteerTqReq_H        : 8u;
    uint8 LatCtrlReqSafe_UB                 : 1u;
    uint8 LatCtrlReqSafeSteerWhlHptcWarnReq : 1u;
    uint8 LatCtrlReqSafeSteerTqReq_L        : 6u;
    uint8                                   : 8u;
    uint8                                   : 8u;
  } *p_VddmChas1Fr04_Data = (struct VddmChas1Fr04_Type *)ptr->SduDataPtr;

  uint8 Data_LatCtrlReqSafe[6] = {0};
  uint8 Data_AbsCtrlActv[3] = {0};

  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_190_Missing, FAULT_CLEAR);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_190_Missing, FAULT_CLEAR);

  if (p_VddmChas1Fr04_Data->LatCtrlReqSafe_UB)
  {
    uint16 LatCtrlReqSafeSteerTqReq = ((uint16)p_VddmChas1Fr04_Data->LatCtrlReqSafeSteerTqReq_H << 6u) + ((uint16)p_VddmChas1Fr04_Data->LatCtrlReqSafeSteerTqReq_L);

    Data_LatCtrlReqSafe[0] = (uint8)p_VddmChas1Fr04_Data->LatCtrlReqSafeChks;
    Data_LatCtrlReqSafe[1] = (uint8)p_VddmChas1Fr04_Data->LatCtrlReqSafeCntr;
    Data_LatCtrlReqSafe[2] = (uint8)p_VddmChas1Fr04_Data->LatCtrlReqSafeLatCtrlModReq;
    Data_LatCtrlReqSafe[3] = (uint8)(LatCtrlReqSafeSteerTqReq >> (8u * 0));
    Data_LatCtrlReqSafe[4] = (uint8)(LatCtrlReqSafeSteerTqReq >> (8u * 1));
    Data_LatCtrlReqSafe[5] = (uint8)p_VddmChas1Fr04_Data->LatCtrlReqSafeSteerWhlHptcWarnReq;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_LatCtrlReqSafe.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlReqSafe,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_LatCtrlReqSafe,
                       Data_LatCtrlReqSafe);
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_LatCtrlReqSafe_UB, FAULT_CLEAR);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_LatCtrlReqSafe_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_LatCtrlReqSafe_UB, FAULT_SET);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_LatCtrlReqSafe_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_LatCtrlReqSafe.Status)
  {
    ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_LatCtrlReqSafe_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_LatCtrlReqSafe_E2E, FAULT_CLEAR);
  }

  if (p_VddmChas1Fr04_Data->AbsCtrlActv_UB)
  {

    Data_AbsCtrlActv[0] = (uint8)p_VddmChas1Fr04_Data->AbsCtrlActvChks;
    Data_AbsCtrlActv[1] = (uint8)p_VddmChas1Fr04_Data->AbsCtrlActvCntr;
    Data_AbsCtrlActv[2] = (uint8)p_VddmChas1Fr04_Data->AbsCtrlActvCtrlSts1;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_AbsCtrlActv.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AbsCtrlActv,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_AbsCtrlActv,
                       Data_AbsCtrlActv);
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_AbsCtrlActv_UB, FAULT_CLEAR);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_AbsCtrlActv_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_AbsCtrlActv_UB, FAULT_SET);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_AbsCtrlActv_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_AbsCtrlActv.Status)
  {
    ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_AbsCtrlActv_E2E, FAULT_SET);
    ComDiag_DealFault_ED9683(DTC_ED9683_FAULT_AbsCtrActv_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED3383(DTC_ED3383_FAULT_AbsCtrlActv_E2E, FAULT_CLEAR);
    ComDiag_DealFault_ED9683(DTC_ED9683_FAULT_AbsCtrActv_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_LatCtrlReqSafe.Status;
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_AbsCtrlActv.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr04: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr04(void)
{
  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_190_Missing, FAULT_SET);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_190_Missing, FAULT_SET);
}

/**
 * @brief VddmChas1Fr14: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr14(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr14_Type{
    uint8 AgDataRawSafeRollRate_H : 8u;
    uint8 AgDataRawSafeRollRate_L : 8u;
    uint8 AgDataRawSafeYawRate_H  : 8u;
    uint8 AgDataRawSafeYawRate_L  : 8u;
    uint8 AgDataRawSafeChks       : 8u;
    uint8 AgDataRawSafeYawRateQf  : 2u;
    uint8 AgDataRawSafeRollRateQf : 2u;
    uint8 AgDataRawSafeCntr       : 4u;
    uint8 ChrgnUReq_UB            : 1u;
    uint8 AgDataRawSafe_UB        : 1u;
    uint8 RemHvStrtActvReq_UB     : 1u;
    uint8 RemHvStrtActvReq        : 2u;
    uint8                         : 3u;
    uint8 ChrgnUReq               : 8u;
  } *p_VddmChas1Fr14_Data = (struct VddmChas1Fr14_Type *)ptr->SduDataPtr;

  uint8 Data_AgDataRawSafe[8] = {0};

  ComDiag_DealFault_C15182(DTC_C15182_FAULT_Msg_1B0_Missing, FAULT_CLEAR);

  if (p_VddmChas1Fr14_Data->AgDataRawSafe_UB)
  {
    uint16 AgDataRawSafeRollRate = ((uint16)p_VddmChas1Fr14_Data->AgDataRawSafeRollRate_H << 8u) + ((uint16)p_VddmChas1Fr14_Data->AgDataRawSafeRollRate_L);
    uint16 AgDataRawSafeYawRate = ((uint16)p_VddmChas1Fr14_Data->AgDataRawSafeYawRate_H << 8u) + ((uint16)p_VddmChas1Fr14_Data->AgDataRawSafeYawRate_L);

    Data_AgDataRawSafe[0] = (uint8)p_VddmChas1Fr14_Data->AgDataRawSafeChks;
    Data_AgDataRawSafe[1] = (uint8)p_VddmChas1Fr14_Data->AgDataRawSafeCntr;
    Data_AgDataRawSafe[2] = (uint8)(AgDataRawSafeRollRate >> (8u * 0));
    Data_AgDataRawSafe[3] = (uint8)(AgDataRawSafeRollRate >> (8u * 1));
    Data_AgDataRawSafe[4] = (uint8)p_VddmChas1Fr14_Data->AgDataRawSafeRollRateQf;
    Data_AgDataRawSafe[5] = (uint8)(AgDataRawSafeYawRate >> (8u * 0));
    Data_AgDataRawSafe[6] = (uint8)(AgDataRawSafeYawRate >> (8u * 1));
    Data_AgDataRawSafe[7] = (uint8)p_VddmChas1Fr14_Data->AgDataRawSafeYawRateQf;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_AgDataRawSafe.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AgDataRawSafe,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_AgDataRawSafe,
                       Data_AgDataRawSafe);
    ComDiag_DealFault_C15182(DTC_C15182_FAULT_AgDataRawSafe_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C15182(DTC_C15182_FAULT_AgDataRawSafe_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_AgDataRawSafe.Status)
  {
    ComDiag_DealFault_ED3983(DTC_ED3983_FAULT_AgDataRawSafe_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED3983(DTC_ED3983_FAULT_AgDataRawSafe_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_AgDataRawSafe.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr14: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr14(void)
{
  ComDiag_DealFault_C15182(DTC_C15182_FAULT_Msg_1B0_Missing, FAULT_SET);
}

/**
 * @brief VddmChas1Fr10: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr10(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr10_Type{
    uint8 WhlSpdCircumlFrntLe_H                  : 7u;
    uint8 WhlSpdCircumlFrnt_UB                   : 1u;
    uint8 WhlSpdCircumlFrntLe_L                  : 8u;
    uint8 WhlSpdCircumlFrntChks                  : 8u;
    uint8 WhlSpdCircumlFrntRiQf                  : 2u;
    uint8 WhlSpdCircumlFrntLeQf                  : 2u;
    uint8 WhlSpdCircumlFrntCntr                  : 4u;
    uint8 WhlSpdCircumlFrntWhlSpdCircumlFrntRi_H : 8u;
    uint8 BrkPedlPsd_UB                          : 1u;
    uint8 WhlSpdCircumlFrntWhlSpdCircumlFrntRi_L : 7u;
    uint8 BrkPedlPsdCntr                         : 4u;
    uint8 BrkPedlPsdQf                           : 2u;
    uint8 BrkPedlPsdBrkPedlPsd                   : 1u;
    uint8 BrkPedlPsdBrkPedlNotPsdSafe            : 1u;
    uint8 BrkPedlPsdChks                         : 8u;
  } *p_VddmChas1Fr10_Data = (struct VddmChas1Fr10_Type *)ptr->SduDataPtr;

  uint8 Data_BrkPedlPsd[5] = {0};
  uint8 Data_WhlSpdCircumlFrnt[8] = {0};

  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B1_Missing, FAULT_CLEAR);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B1_Missing, FAULT_CLEAR);

  if (p_VddmChas1Fr10_Data->BrkPedlPsd_UB)
  {

    Data_BrkPedlPsd[0] = (uint8)p_VddmChas1Fr10_Data->BrkPedlPsdChks;
    Data_BrkPedlPsd[1] = (uint8)p_VddmChas1Fr10_Data->BrkPedlPsdCntr;
    Data_BrkPedlPsd[2] = (uint8)p_VddmChas1Fr10_Data->BrkPedlPsdBrkPedlNotPsdSafe;
    Data_BrkPedlPsd[3] = (uint8)p_VddmChas1Fr10_Data->BrkPedlPsdBrkPedlPsd;
    Data_BrkPedlPsd[4] = (uint8)p_VddmChas1Fr10_Data->BrkPedlPsdQf;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_BrkPedlPsd.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_BrkPedlPsd,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_BrkPedlPsd,
                       Data_BrkPedlPsd);
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_BrkPedlPsd_UB, FAULT_CLEAR);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_BrkPedlPsd_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_BrkPedlPsd_UB, FAULT_SET);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_BrkPedlPsd_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_BrkPedlPsd.Status)
  {
    ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_BrkPedlPsd_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_BrkPedlPsd_E2E, FAULT_CLEAR);
  }

  if (p_VddmChas1Fr10_Data->WhlSpdCircumlFrnt_UB)
  {
    uint16 WhlSpdCircumlFrntLe = ((uint16)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntLe_H << 8u) + ((uint16)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntLe_L);
    uint16 WhlSpdCircumlFrntWhlSpdCircumlFrntRi = ((uint16)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntWhlSpdCircumlFrntRi_H << 7u) + ((uint16)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntWhlSpdCircumlFrntRi_L);

    Data_WhlSpdCircumlFrnt[0] = (uint8)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntChks;
    Data_WhlSpdCircumlFrnt[1] = (uint8)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntCntr;
    Data_WhlSpdCircumlFrnt[2] = (uint8)(WhlSpdCircumlFrntLe >> (8u * 0));
    Data_WhlSpdCircumlFrnt[3] = (uint8)(WhlSpdCircumlFrntLe >> (8u * 1));
    Data_WhlSpdCircumlFrnt[4] = (uint8)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntLeQf;
    Data_WhlSpdCircumlFrnt[5] = (uint8)p_VddmChas1Fr10_Data->WhlSpdCircumlFrntRiQf;
    Data_WhlSpdCircumlFrnt[6] = (uint8)(WhlSpdCircumlFrntWhlSpdCircumlFrntRi >> (8u * 0));
    Data_WhlSpdCircumlFrnt[7] = (uint8)(WhlSpdCircumlFrntWhlSpdCircumlFrntRi >> (8u * 1));
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlSpdCircumlFrnt,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt,
                       Data_WhlSpdCircumlFrnt);
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlFrnt_UB, FAULT_CLEAR);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlFrnt_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlFrnt_UB, FAULT_SET);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlFrnt_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt.Status)
  {
    ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlFrnt_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlFrnt_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_BrkPedlPsd.Status;
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr10: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr10(void)
{
  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B1_Missing, FAULT_SET);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B1_Missing, FAULT_SET);
}

/**
 * @brief VddmChas1Fr55: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr55(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr55_Type{
    uint8 WhlSpdCircumlReLe_H : 7u;
    uint8 WhlSpdCircumlRe_UB  : 1u;
    uint8 WhlSpdCircumlReLe_L : 8u;
    uint8 WhlSpdCircumlReChks : 8u;
    uint8 WhlSpdCircumlReRiQf : 2u;
    uint8 WhlSpdCircumlReLeQf : 2u;
    uint8 WhlSpdCircumlReCntr : 4u;
    uint8 WhlSpdCircumlReRi_H : 8u;
    uint8                     : 1u;
    uint8 WhlSpdCircumlReRi_L : 7u;
    uint8                     : 8u;
    uint8                     : 8u;
  } *p_VddmChas1Fr55_Data = (struct VddmChas1Fr55_Type *)ptr->SduDataPtr;

  uint8 Data_WhlSpdCircumlRe[8] = {0};

  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B7_Missing, FAULT_CLEAR);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B7_Missing, FAULT_CLEAR);

  if (p_VddmChas1Fr55_Data->WhlSpdCircumlRe_UB)
  {
    uint16 WhlSpdCircumlReLe = ((uint16)p_VddmChas1Fr55_Data->WhlSpdCircumlReLe_H << 8u) + ((uint16)p_VddmChas1Fr55_Data->WhlSpdCircumlReLe_L);
    uint16 WhlSpdCircumlReRi = ((uint16)p_VddmChas1Fr55_Data->WhlSpdCircumlReRi_H << 7u) + ((uint16)p_VddmChas1Fr55_Data->WhlSpdCircumlReRi_L);

    Data_WhlSpdCircumlRe[0] = (uint8)p_VddmChas1Fr55_Data->WhlSpdCircumlReChks;
    Data_WhlSpdCircumlRe[1] = (uint8)p_VddmChas1Fr55_Data->WhlSpdCircumlReCntr;
    Data_WhlSpdCircumlRe[2] = (uint8)(WhlSpdCircumlReLe >> (8u * 0));
    Data_WhlSpdCircumlRe[3] = (uint8)(WhlSpdCircumlReLe >> (8u * 1));
    Data_WhlSpdCircumlRe[4] = (uint8)p_VddmChas1Fr55_Data->WhlSpdCircumlReLeQf;
    Data_WhlSpdCircumlRe[5] = (uint8)(WhlSpdCircumlReRi >> (8u * 0));
    Data_WhlSpdCircumlRe[6] = (uint8)(WhlSpdCircumlReRi >> (8u * 1));
    Data_WhlSpdCircumlRe[7] = (uint8)p_VddmChas1Fr55_Data->WhlSpdCircumlReRiQf;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlRe.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlSpdCircumlRe,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlRe,
                       Data_WhlSpdCircumlRe);
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlRe_UB, FAULT_CLEAR);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlRe_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_C12182(DTC_C12182_FAULT_WhlSpdCircumlRe_UB, FAULT_SET);
    ComDiag_DealFault_D10382(DTC_D10382_FAULT_WhlSpdCircumlRe_UB, FAULT_SET);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlRe.Status)
  {
    ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlRe_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED3283(DTC_ED3283_FAULT_WhlSpdCircumlRe_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlRe.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr55: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr55(void)
{
  ComDiag_DealFault_C12182(DTC_C12182_FAULT_Msg_1B7_Missing, FAULT_SET);
  ComDiag_DealFault_D10382(DTC_D10382_FAULT_Msg_1B7_Missing, FAULT_SET);
}

/**
 * @brief VddmChas1Fr53: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr53(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr53_Type{
    uint8 BkpOfDstTrvld_H                : 8u;
    uint8 BkpOfDstTrvld_M                : 8u;
    uint8 DrvModReqForChampnMod          : 3u;
    uint8 BkpOfDstTrvld_L                : 5u;
    uint8 StandStillMgrStsForHldCntr     : 4u;
    uint8 StandStillMgrStsForHld1        : 3u;
    uint8 StandStillMgrStsForHld_UB      : 1u;
    uint8 StandStillMgrStsForHldChks     : 8u;
    uint8                                : 7u;
    uint8 RlyPwrDistbnCmd1WdIgnRlyCmd_UB : 1u;
    uint8                                : 5u;
    uint8 BkpOfDstTrvld_UB               : 1u;
    uint8 DrvModReqForChampnMod_UB       : 1u;
    uint8 RlyPwrDistbnCmd1WdIgnRlyCmd    : 1u;
    uint8                                : 8u;
  } *p_VddmChas1Fr53_Data = (struct VddmChas1Fr53_Type *)ptr->SduDataPtr;

  uint8 Data_StandStillMgrStsForHld[3] = {0};

  if (p_VddmChas1Fr53_Data->StandStillMgrStsForHld_UB)
  {

    Data_StandStillMgrStsForHld[0] = (uint8)p_VddmChas1Fr53_Data->StandStillMgrStsForHldChks;
    Data_StandStillMgrStsForHld[1] = (uint8)p_VddmChas1Fr53_Data->StandStillMgrStsForHldCntr;
    Data_StandStillMgrStsForHld[2] = (uint8)p_VddmChas1Fr53_Data->StandStillMgrStsForHld1;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_StandStillMgrStsForHld.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_StandStillMgrStsForHld,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_StandStillMgrStsForHld,
                       Data_StandStillMgrStsForHld);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_StandStillMgrStsForHld.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr53: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr53(void)
{
}

/**
 * @brief VddmChas1Fr54: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr54(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr54_Type{
    uint8 IDcDcActLoSideCntr             : 4u;
    uint8 IDcDcActLoSide_UB              : 1u;
    uint8                                : 3u;
    uint8 IDcDcActLoSideChks             : 8u;
    uint8 IDcDcActLoSideIDcDcActLoSide_H : 8u;
    uint8                                : 4u;
    uint8 IDcDcActLoSideIDcDcActLoSide_L : 4u;
    uint8                                : 8u;
    uint8                                : 8u;
    uint8                                : 8u;
    uint8                                : 8u;
  } *p_VddmChas1Fr54_Data = (struct VddmChas1Fr54_Type *)ptr->SduDataPtr;

  uint8 Data_IDcDcActLoSide[4] = {0};

  if (p_VddmChas1Fr54_Data->IDcDcActLoSide_UB)
  {
    uint16 IDcDcActLoSideIDcDcActLoSide = ((uint16)p_VddmChas1Fr54_Data->IDcDcActLoSideIDcDcActLoSide_H << 4u) + ((uint16)p_VddmChas1Fr54_Data->IDcDcActLoSideIDcDcActLoSide_L);

    Data_IDcDcActLoSide[0] = (uint8)p_VddmChas1Fr54_Data->IDcDcActLoSideChks;
    Data_IDcDcActLoSide[1] = (uint8)p_VddmChas1Fr54_Data->IDcDcActLoSideCntr;
    Data_IDcDcActLoSide[2] = (uint8)(IDcDcActLoSideIDcDcActLoSide >> (8u * 0));
    Data_IDcDcActLoSide[3] = (uint8)(IDcDcActLoSideIDcDcActLoSide >> (8u * 1));
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_IDcDcActLoSide.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_IDcDcActLoSide,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_IDcDcActLoSide,
                       Data_IDcDcActLoSide);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_IDcDcActLoSide.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr54: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr54(void)
{
}

/**
 * @brief VddmChas1Fr30: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr30(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr30_Type{
    uint8 VehCfgPrmBlkIDBytePosn1 : 8u;
    uint8 VehCfgPrmCCPBytePosn2   : 8u;
    uint8 VehCfgPrmCCPBytePosn3   : 8u;
    uint8 VehCfgPrmCCPBytePosn4   : 8u;
    uint8 VehCfgPrmCCPBytePosn5   : 8u;
    uint8 VehCfgPrmCCPBytePosn6   : 8u;
    uint8 VehCfgPrmCCPBytePosn7   : 8u;
    uint8 VehCfgPrmCCPBytePosn8   : 8u;
  } *p_VddmChas1Fr30_Data = (struct VddmChas1Fr30_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr30: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr30(void)
{
}

/**
 * @brief VddmChas1Fr41: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr41(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr41_Type{
    uint8 ULoWarnCntr                       : 4u;
    uint8 ULoWarnULoWarn                    : 2u;
    uint8 ULoWarn_UB                        : 1u;
    uint8                                   : 1u;
    uint8 ULoWarnChks                       : 8u;
    uint8                                   : 8u;
    uint8                                   : 8u;
    uint8 HvacHexAirTHvacAirTForHeatrFrnt_H : 5u;
    uint8 HvacHexAirTHvacAirTForHeatrFrntQf : 1u;
    uint8 HvacHexAirT_UB                    : 1u;
    uint8                                   : 1u;
    uint8 HvacHexAirTHvacAirTForHeatrFrnt_L : 8u;
    uint8                                   : 8u;
    uint8                                   : 2u;
    uint8 DrvModReq                         : 4u;
    uint8 DrvModReq_UB                      : 1u;
    uint8                                   : 1u;
  } *p_VddmChas1Fr41_Data = (struct VddmChas1Fr41_Type *)ptr->SduDataPtr;

  uint8 Data_ULoWarn[3] = {0};

  ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_2AE_Missing, FAULT_CLEAR);

  if (p_VddmChas1Fr41_Data->DrvModReq_UB)
  {
    ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_DrvModReq_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_DrvModReq_UB, FAULT_SET);
  }

  if (p_VddmChas1Fr41_Data->ULoWarn_UB)
  {

    Data_ULoWarn[0] = (uint8)p_VddmChas1Fr41_Data->ULoWarnChks;
    Data_ULoWarn[1] = (uint8)p_VddmChas1Fr41_Data->ULoWarnCntr;
    Data_ULoWarn[2] = (uint8)p_VddmChas1Fr41_Data->ULoWarnULoWarn;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_ULoWarn.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_ULoWarn,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_ULoWarn,
                       Data_ULoWarn);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_ULoWarn.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr41: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr41(void)
{
  ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_2AE_Missing, FAULT_SET);
}

/**
 * @brief VddmChas1Fr19: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr19(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr19_Type{
    uint8 VehModMngtGlbSafe1Chks                       : 8u;
    uint8 VehModMngtGlbSafe1UsgModSts                  : 4u;
    uint8 VehModMngtGlbSafe1Cntr                       : 4u;
    uint8 VehModMngtGlbSafe1PwrLvlElecMai              : 4u;
    uint8 VehModMngtGlbSafe1PwrLvlElecSubtyp           : 4u;
    uint8 VehModMngtGlbSafe1EgyLvlElecMai              : 4u;
    uint8 VehModMngtGlbSafe1EgyLvlElecSubtyp           : 4u;
    uint8 VehModMngtGlbSafe1_UB                        : 1u;
    uint8 VehModMngtGlbSafe1FltEgyCnsWdSts             : 1u;
    uint8 VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp : 3u;
    uint8 VehModMngtGlbSafe1CarModSts1                 : 3u;
    uint8                                              : 3u;
    uint8 AutEgyRgnLvlSet                              : 3u;
    uint8                                              : 1u;
    uint8 AutEgyRgnLvlSet_UB                           : 1u;
    uint8                                              : 8u;
    uint8                                              : 8u;
  } *p_VddmChas1Fr19_Data = (struct VddmChas1Fr19_Type *)ptr->SduDataPtr;

  uint8 Data_VehModMngtGlbSafe1[10] = {0};

  if (p_VddmChas1Fr19_Data->VehModMngtGlbSafe1_UB)
  {

    Data_VehModMngtGlbSafe1[0] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1Chks;
    Data_VehModMngtGlbSafe1[1] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1Cntr;
    Data_VehModMngtGlbSafe1[2] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1CarModSts1;
    Data_VehModMngtGlbSafe1[3] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp;
    Data_VehModMngtGlbSafe1[4] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1EgyLvlElecMai;
    Data_VehModMngtGlbSafe1[5] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1EgyLvlElecSubtyp;
    Data_VehModMngtGlbSafe1[6] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1FltEgyCnsWdSts;
    Data_VehModMngtGlbSafe1[7] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1PwrLvlElecMai;
    Data_VehModMngtGlbSafe1[8] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1PwrLvlElecSubtyp;
    Data_VehModMngtGlbSafe1[9] = (uint8)p_VddmChas1Fr19_Data->VehModMngtGlbSafe1UsgModSts;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehModMngtGlbSafe1.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehModMngtGlbSafe1,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehModMngtGlbSafe1,
                       Data_VehModMngtGlbSafe1);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehModMngtGlbSafe1.Status)
  {
    ComDiag_DealFault_ED5A83(DTC_ED5A83_FAULT_VehModMngtGlbSafe1_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED5A83(DTC_ED5A83_FAULT_VehModMngtGlbSafe1_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehModMngtGlbSafe1.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr19: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr19(void)
{
}

/**
 * @brief VddmChas1Fr49: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr49(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr49_Type{
    uint8 CarTiGlb_H                        : 8u;
    uint8 CarTiGlb_M0                       : 8u;
    uint8 CarTiGlb_M1                       : 8u;
    uint8 CarTiGlb_L                        : 8u;
    uint8 HvacHeatrInletTempReqEvaprTFrnt_H : 6u;
    uint8 HvacHeatrInletTempReqEvaprTQf     : 1u;
    uint8 HvacHeatrInletTempReq_UB          : 1u;
    uint8                                   : 1u;
    uint8 HvacHeatrInletTempReqEvaprTFrnt_L : 7u;
    uint8 SaveSetgToMemPrmnt_UB             : 1u;
    uint8 SaveSetgToMemPrmnt                : 2u;
    uint8 ProfPenSts1_UB                    : 1u;
    uint8 ProfPenSts1                       : 4u;
    uint8                                   : 1u;
    uint8 CarTiGlb_UB                       : 1u;
    uint8                                   : 6u;
  } *p_VddmChas1Fr49_Data = (struct VddmChas1Fr49_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr49: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr49(void)
{
}

/**
 * @brief VddmChas1Fr50: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr50(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr50_Type{
    uint8 TotDstToEmptyDstToEmpty_H : 8u;
    uint8 DstProtnReq_H             : 1u;
    uint8 DstProtnReq_UB            : 1u;
    uint8                           : 1u;
    uint8 TotDstToEmpty_UB          : 1u;
    uint8 TotDstToEmptyDstUnit      : 1u;
    uint8 TotDstToEmptyDstToEmpty_L : 3u;
    uint8 DstProtnReq_L             : 8u;
    uint8                           : 8u;
    uint8                           : 8u;
    uint8                           : 8u;
    uint8 VehBattUSysUQf            : 2u;
    uint8 HMIAutoShowModSet_UB      : 1u;
    uint8 HMIAutoShowModSet         : 1u;
    uint8                           : 2u;
    uint8 VehBattU_UB               : 1u;
    uint8                           : 1u;
    uint8 VehBattUSysU              : 8u;
  } *p_VddmChas1Fr50_Data = (struct VddmChas1Fr50_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr50: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr50(void)
{
}

/**
 * @brief VddmChas1Fr33: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr33(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr33_Type{
    uint8 VehCfgPrmExtBlkIDBytePosn1 : 8u;
    uint8 VehCfgPrmExtCCPBytePosn2   : 8u;
    uint8 VehCfgPrmExtCCPBytePosn3   : 8u;
    uint8 VehCfgPrmExtCCPBytePosn4   : 8u;
    uint8 VehCfgPrmExtCCPBytePosn5   : 8u;
    uint8 VehCfgPrmExtCCPBytePosn6   : 8u;
    uint8 VehCfgPrmExtCCPBytePosn7   : 8u;
    uint8 VehCfgPrmExtCCPBytePosn8   : 8u;
  } *p_VddmChas1Fr33_Data = (struct VddmChas1Fr33_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr33: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr33(void)
{
}

/**
 * @brief VddmChas1Fr46: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr46(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr46_Type{
    uint8                       : 5u;
    uint8 WhlRotToothCntr_UB    : 1u;
    uint8                       : 8u;
    uint8                       : 2u;
    uint8 WhlRotToothCntrCntr   : 4u;
    uint8 BrkTracCtrlActv       : 1u;
    uint8 BrkTracCtrlActv_UB    : 1u;
    uint8                       : 2u;
    uint8 WhlRotToothCntrChks   : 8u;
    uint8 WhlRotToothCntrFrntLe : 8u;
    uint8 WhlRotToothCntrFrntRi : 8u;
    uint8 WhlRotToothCntrReLe   : 8u;
    uint8 WhlRotToothCntrReRi   : 8u;
  } *p_VddmChas1Fr46_Data = (struct VddmChas1Fr46_Type *)ptr->SduDataPtr;

  uint8 Data_WhlRotToothCntr[6] = {0};

  if (p_VddmChas1Fr46_Data->WhlRotToothCntr_UB)
  {

    Data_WhlRotToothCntr[0] = (uint8)p_VddmChas1Fr46_Data->WhlRotToothCntrChks;
    Data_WhlRotToothCntr[1] = (uint8)p_VddmChas1Fr46_Data->WhlRotToothCntrCntr;
    Data_WhlRotToothCntr[2] = (uint8)p_VddmChas1Fr46_Data->WhlRotToothCntrFrntLe;
    Data_WhlRotToothCntr[3] = (uint8)p_VddmChas1Fr46_Data->WhlRotToothCntrFrntRi;
    Data_WhlRotToothCntr[4] = (uint8)p_VddmChas1Fr46_Data->WhlRotToothCntrReLe;
    Data_WhlRotToothCntr[5] = (uint8)p_VddmChas1Fr46_Data->WhlRotToothCntrReRi;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlRotToothCntr.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlRotToothCntr,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlRotToothCntr,
                       Data_WhlRotToothCntr);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlRotToothCntr.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr46: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr46(void)
{
}

/**
 * @brief EcmChas1Fr08: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_EcmChas1Fr08(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct EcmChas1Fr08_Type{
    uint8 PtTqAtWhlFrntActCntr                 : 4u;
    uint8 PtTqAtWhlFrntActPtTqAtWhlsFrntQly    : 3u;
    uint8 PtTqAtWhlFrntAct_UB                  : 1u;
    uint8 PtTqAtWhlFrntActChks                 : 8u;
    uint8 PtTqAtWhlFrntActPtTqAtWhlFrntRiAct_H : 8u;
    uint8 PtTqAtWhlFrntActPtTqAtWhlFrntRiAct_L : 8u;
    uint8 PtTqAtWhlFrntActPtTqAtWhlFrntLeAct_H : 8u;
    uint8 PtTqAtWhlFrntActPtTqAtWhlFrntLeAct_L : 8u;
    uint8 PtTqAtWhlFrntActPtTqAtAxleFrntAct_H  : 8u;
    uint8 PtTqAtWhlFrntActPtTqAtAxleFrntAct_L  : 8u;
  } *p_EcmChas1Fr08_Data = (struct EcmChas1Fr08_Type *)ptr->SduDataPtr;

  uint8 Data_PtTqAtWhlFrntAct[9] = {0};

  if (p_EcmChas1Fr08_Data->PtTqAtWhlFrntAct_UB)
  {
    uint16 PtTqAtWhlFrntActPtTqAtAxleFrntAct = ((uint16)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActPtTqAtAxleFrntAct_H << 8u) + ((uint16)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActPtTqAtAxleFrntAct_L);
    uint16 PtTqAtWhlFrntActPtTqAtWhlFrntLeAct = ((uint16)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActPtTqAtWhlFrntLeAct_H << 8u) + ((uint16)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActPtTqAtWhlFrntLeAct_L);
    uint16 PtTqAtWhlFrntActPtTqAtWhlFrntRiAct = ((uint16)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActPtTqAtWhlFrntRiAct_H << 8u) + ((uint16)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActPtTqAtWhlFrntRiAct_L);

    Data_PtTqAtWhlFrntAct[0] = (uint8)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActChks;
    Data_PtTqAtWhlFrntAct[1] = (uint8)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActCntr;
    Data_PtTqAtWhlFrntAct[2] = (uint8)(PtTqAtWhlFrntActPtTqAtAxleFrntAct >> (8u * 0));
    Data_PtTqAtWhlFrntAct[3] = (uint8)(PtTqAtWhlFrntActPtTqAtAxleFrntAct >> (8u * 1));
    Data_PtTqAtWhlFrntAct[4] = (uint8)(PtTqAtWhlFrntActPtTqAtWhlFrntLeAct >> (8u * 0));
    Data_PtTqAtWhlFrntAct[5] = (uint8)(PtTqAtWhlFrntActPtTqAtWhlFrntLeAct >> (8u * 1));
    Data_PtTqAtWhlFrntAct[6] = (uint8)(PtTqAtWhlFrntActPtTqAtWhlFrntRiAct >> (8u * 0));
    Data_PtTqAtWhlFrntAct[7] = (uint8)(PtTqAtWhlFrntActPtTqAtWhlFrntRiAct >> (8u * 1));
    Data_PtTqAtWhlFrntAct[8] = (uint8)p_EcmChas1Fr08_Data->PtTqAtWhlFrntActPtTqAtWhlsFrntQly;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PtTqAtWhlFrntAct,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct,
                       Data_PtTqAtWhlFrntAct);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct.Status)
  {
    ComDiag_DealFault_ED7983(DTC_ED7983_FAULT_PtTqAtWhlFrntAct_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_ED7983(DTC_ED7983_FAULT_PtTqAtWhlFrntAct_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief EcmChas1Fr08: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_EcmChas1Fr08(void)
{
}

/**
 * @brief VddmChas1Fr22: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr22(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr22_Type{
    uint8                       : 8u;
    uint8                       : 8u;
    uint8                       : 8u;
    uint8                       : 8u;
    uint8                       : 8u;
    uint8                       : 8u;
    uint8 SteerSetgSteerMod     : 3u;
    uint8 SteerSetg_UB          : 1u;
    uint8                       : 4u;
    uint8 SteerSetgPen          : 4u;
    uint8 SteerSetgSteerAsscLvl : 3u;
    uint8                       : 1u;
  } *p_VddmChas1Fr22_Data = (struct VddmChas1Fr22_Type *)ptr->SduDataPtr;

  ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_463_Missing, FAULT_CLEAR);

  if (p_VddmChas1Fr22_Data->SteerSetg_UB)
  {
    ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_SteerSetg_UB, FAULT_CLEAR);
  }
  else
  {
    ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_SteerSetg_UB, FAULT_SET);
  }

  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr22: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr22(void)
{
  ComDiag_DealFault_D44D82(DTC_D44D82_FAULT_Msg_463_Missing, FAULT_SET);
}

/**
 * @brief VddmChas1Fr48: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr48(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr48_Type{
    uint8 VehMtnStVehMtnSt : 3u;
    uint8 VehMtnStCntr     : 4u;
    uint8 VehMtnSt_UB      : 1u;
    uint8 VehMtnStChks     : 8u;
    uint8                  : 8u;
    uint8                  : 8u;
    uint8                  : 8u;
    uint8                  : 8u;
    uint8                  : 8u;
    uint8                  : 8u;
  } *p_VddmChas1Fr48_Data = (struct VddmChas1Fr48_Type *)ptr->SduDataPtr;

  uint8 Data_VehMtnSt[3] = {0};

  if (p_VddmChas1Fr48_Data->VehMtnSt_UB)
  {

    Data_VehMtnSt[0] = (uint8)p_VddmChas1Fr48_Data->VehMtnStChks;
    Data_VehMtnSt[1] = (uint8)p_VddmChas1Fr48_Data->VehMtnStCntr;
    Data_VehMtnSt[2] = (uint8)p_VddmChas1Fr48_Data->VehMtnStVehMtnSt;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehMtnSt.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehMtnSt,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehMtnSt,
                       Data_VehMtnSt);
  }

  if (E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehMtnSt.Status)
  {
    ComDiag_DealFault_E71883(DTC_E71883_FAULT_VehMtnSt_E2E, FAULT_SET);
  }
  else
  {
    ComDiag_DealFault_E71883(DTC_E71883_FAULT_VehMtnSt_E2E, FAULT_CLEAR);
  }

  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehMtnSt.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr48: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr48(void)
{
}

/**
 * @brief VddmChas1Fr44: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_VddmChas1Fr44(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct VddmChas1Fr44_Type{
    uint8            : 8u;
    uint8            : 8u;
    uint8            : 8u;
    uint8            : 8u;
    uint8 EscStCntr  : 4u;
    uint8 EscStEscSt : 3u;
    uint8 EscSt_UB   : 1u;
    uint8 EscStChks  : 8u;
    uint8            : 8u;
    uint8            : 8u;
  } *p_VddmChas1Fr44_Data = (struct VddmChas1Fr44_Type *)ptr->SduDataPtr;

  uint8 Data_EscSt[3] = {0};

  if (p_VddmChas1Fr44_Data->EscSt_UB)
  {

    Data_EscSt[0] = (uint8)p_VddmChas1Fr44_Data->EscStChks;
    Data_EscSt[1] = (uint8)p_VddmChas1Fr44_Data->EscStCntr;
    Data_EscSt[2] = (uint8)p_VddmChas1Fr44_Data->EscStEscSt;
    E2EXf_Prv_Check_State_E2EXfRb_Transformer_EscSt.NewDataAvailable = TRUE;
    (void)E2E_P01Check(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_EscSt,
                       &E2EXf_Prv_Check_State_E2EXfRb_Transformer_EscSt,
                       Data_EscSt);
  }
  CheckRes |= E2EXf_Prv_Check_State_E2EXfRb_Transformer_EscSt.Status;
  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief VddmChas1Fr44: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_VddmChas1Fr44(void)
{
}

/**
 * @brief EtcToPscmDevelFr: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_RxPdu_EtcToPscmDevelFr(PduIdType id, const PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType CheckRes = 0;
  struct EtcToPscmDevelFr_Type{
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup1 : 8u;
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup2 : 8u;
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup3 : 8u;
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup4 : 8u;
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup5 : 8u;
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup6 : 8u;
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup7 : 8u;
    uint8 PSCMdevelpsignalgroupreq1Functiondevpsignalgroup8 : 8u;
  } *p_EtcToPscmDevelFr_Data = (struct EtcToPscmDevelFr_Type *)ptr->SduDataPtr;


  if (CheckRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief EtcToPscmDevelFr: 8 bytes
 * @return void
 */
void Rte_COMTout_RxPdu_EtcToPscmDevelFr(void)
{
}



/****************************************** Tx ********************************************/

/**
 * @brief PscmChas1Fr02: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_TxPdu_PscmChas1Fr02(PduIdType id, PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType ProtRes = 0;
  struct PscmChas1Fr02_Type{
    uint8 LatCtrlModCfmdChks       : 8u;
    uint8 LatCtrlModCfmdLatCtrlMod : 4u;
    uint8 LatCtrlModCfmdCntr       : 4u;
    uint8                          : 7u;
    uint8 LatCtrlModCfmd_UB        : 1u;
    uint8                          : 8u;
    uint8 SteerWhlTqAddl_H         : 8u;
    uint8 SteerServoSts            : 1u;
    uint8 SteerWhlTqAddl_UB        : 1u;
    uint8 SteerWhlTqAddl_L         : 6u;
    uint8 TqAssAddl_H              : 6u;
    uint8 TqAssAddl_UB             : 1u;
    uint8 SteerServoSts_UB         : 1u;
    uint8 TqAssAddl_L              : 8u;
  } *p_PscmChas1Fr02_Data = (struct PscmChas1Fr02_Type *)ptr->SduDataPtr;

  uint8 Data_LatCtrlModCfmd[3] = {0};

  if (p_PscmChas1Fr02_Data->LatCtrlModCfmd_UB)
  {

    Data_LatCtrlModCfmd[0] = (uint8)p_PscmChas1Fr02_Data->LatCtrlModCfmdChks;
    Data_LatCtrlModCfmd[1] = (uint8)p_PscmChas1Fr02_Data->LatCtrlModCfmdCntr;
    Data_LatCtrlModCfmd[2] = (uint8)p_PscmChas1Fr02_Data->LatCtrlModCfmdLatCtrlMod;
    ProtRes |= E2E_P01Protect(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlModCfmd,
                              &E2EXf_Prv_Protect_State_E2EXfRb_Transformer_LatCtrlModCfmd,
                              Data_LatCtrlModCfmd);
    p_PscmChas1Fr02_Data->LatCtrlModCfmdChks = Data_LatCtrlModCfmd[0];
    p_PscmChas1Fr02_Data->LatCtrlModCfmdCntr = Data_LatCtrlModCfmd[1];
  }
  if (ProtRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief PscmChas1Fr07: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_TxPdu_PscmChas1Fr07(PduIdType id, PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType ProtRes = 0;
  struct PscmChas1Fr07_Type{
    uint8 PinionSteerAgGroupChks                : 8u;
    uint8 PinionSteerAgGroupPinionSteerAgSpd1_H : 6u;
    uint8 PinionSteerAgGroupPinionSteerAg1Qf    : 2u;
    uint8 PinionSteerAgGroupPinionSteerAgSpd1_L : 8u;
    uint8 PinionSteerAgGroupSteerWhlTq_H        : 6u;
    uint8 PinionSteerAgGroupPinionSteerAgSpd1Qf : 2u;
    uint8 PinionSteerAgGroupSteerWhlTq_L        : 8u;
    uint8 PinionSteerAgGroupPinionSteerAg1_H    : 7u;
    uint8                                       : 1u;
    uint8 PinionSteerAgGroupPinionSteerAg1_L    : 8u;
    uint8                                       : 1u;
    uint8 PinionSteerAgGroup_UB                 : 1u;
    uint8 PinionSteerAgGroupSteerWhlTqQf        : 2u;
    uint8 PinionSteerAgGroupCntr                : 4u;
  } *p_PscmChas1Fr07_Data = (struct PscmChas1Fr07_Type *)ptr->SduDataPtr;

  uint8 Data_PinionSteerAgGroup[11] = {0};

  if (p_PscmChas1Fr07_Data->PinionSteerAgGroup_UB)
  {
    uint16 PinionSteerAgGroupPinionSteerAg1 = ((uint16)p_PscmChas1Fr07_Data->PinionSteerAgGroupPinionSteerAg1_H << 8u) + ((uint16)p_PscmChas1Fr07_Data->PinionSteerAgGroupPinionSteerAg1_L);
    uint16 PinionSteerAgGroupPinionSteerAgSpd1 = ((uint16)p_PscmChas1Fr07_Data->PinionSteerAgGroupPinionSteerAgSpd1_H << 8u) + ((uint16)p_PscmChas1Fr07_Data->PinionSteerAgGroupPinionSteerAgSpd1_L);
    uint16 PinionSteerAgGroupSteerWhlTq = ((uint16)p_PscmChas1Fr07_Data->PinionSteerAgGroupSteerWhlTq_H << 8u) + ((uint16)p_PscmChas1Fr07_Data->PinionSteerAgGroupSteerWhlTq_L);

    Data_PinionSteerAgGroup[0] = (uint8)p_PscmChas1Fr07_Data->PinionSteerAgGroupChks;
    Data_PinionSteerAgGroup[1] = (uint8)p_PscmChas1Fr07_Data->PinionSteerAgGroupCntr;
    Data_PinionSteerAgGroup[2] = (uint8)(PinionSteerAgGroupPinionSteerAg1 >> (8u * 0));
    Data_PinionSteerAgGroup[3] = (uint8)(PinionSteerAgGroupPinionSteerAg1 >> (8u * 1));
    Data_PinionSteerAgGroup[4] = (uint8)p_PscmChas1Fr07_Data->PinionSteerAgGroupPinionSteerAg1Qf;
    Data_PinionSteerAgGroup[5] = (uint8)(PinionSteerAgGroupPinionSteerAgSpd1 >> (8u * 0));
    Data_PinionSteerAgGroup[6] = (uint8)(PinionSteerAgGroupPinionSteerAgSpd1 >> (8u * 1));
    Data_PinionSteerAgGroup[7] = (uint8)p_PscmChas1Fr07_Data->PinionSteerAgGroupPinionSteerAgSpd1Qf;
    Data_PinionSteerAgGroup[8] = (uint8)(PinionSteerAgGroupSteerWhlTq >> (8u * 0));
    Data_PinionSteerAgGroup[9] = (uint8)(PinionSteerAgGroupSteerWhlTq >> (8u * 1));
    Data_PinionSteerAgGroup[10] = (uint8)p_PscmChas1Fr07_Data->PinionSteerAgGroupSteerWhlTqQf;
    ProtRes |= E2E_P01Protect(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PinionSteerAgGroup,
                              &E2EXf_Prv_Protect_State_E2EXfRb_Transformer_PinionSteerAgGroup,
                              Data_PinionSteerAgGroup);
    p_PscmChas1Fr07_Data->PinionSteerAgGroupChks = Data_PinionSteerAgGroup[0];
    p_PscmChas1Fr07_Data->PinionSteerAgGroupCntr = Data_PinionSteerAgGroup[1];
  }
  if (ProtRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief PscmChas1Fr01: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_TxPdu_PscmChas1Fr01(PduIdType id, PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType ProtRes = 0;
  struct PscmChas1Fr01_Type{
    uint8 DrvrSteerActvChks          : 8u;
    uint8 SteerStsToCrabMov          : 2u;
    uint8 DrvrSteerActv_UB           : 1u;
    uint8 DrvrSteerActvDrvrSteerActv : 1u;
    uint8 DrvrSteerActvCntr          : 4u;
    uint8 ADL3LatCtrlStsADMod        : 2u;
    uint8 ADL3LatCtrlStsQf           : 2u;
    uint8 ADL3LatCtrlStsSts          : 2u;
    uint8 ADL3LatCtrlStsCtrlSts      : 1u;
    uint8 ADL3LatCtrlSts_UB          : 1u;
    uint8 ADL3LatCtrlStsCntr         : 4u;
    uint8 ADL3LatCtrlStsDegraded     : 4u;
    uint8 ADL3LatCtrlStsChks         : 8u;
    uint8 FrntSteerFEstimd1_H        : 8u;
    uint8 FrntSteerFEstimd1_L        : 8u;
    uint8 FrntSteerFEstimd1_UB       : 1u;
    uint8 UBoostReqBySteerFrnt_UB    : 1u;
    uint8 UBoostReqBySteerFrnt       : 2u;
    uint8 SteerStsToCrabMov_UB       : 1u;
    uint8                            : 3u;
  } *p_PscmChas1Fr01_Data = (struct PscmChas1Fr01_Type *)ptr->SduDataPtr;

  uint8 Data_DrvrSteerActv[3] = {0};

  if (p_PscmChas1Fr01_Data->DrvrSteerActv_UB)
  {

    Data_DrvrSteerActv[0] = (uint8)p_PscmChas1Fr01_Data->DrvrSteerActvChks;
    Data_DrvrSteerActv[1] = (uint8)p_PscmChas1Fr01_Data->DrvrSteerActvCntr;
    Data_DrvrSteerActv[2] = (uint8)p_PscmChas1Fr01_Data->DrvrSteerActvDrvrSteerActv;
    ProtRes |= E2E_P01Protect(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_DrvrSteerActv,
                              &E2EXf_Prv_Protect_State_E2EXfRb_Transformer_DrvrSteerActv,
                              Data_DrvrSteerActv);
    p_PscmChas1Fr01_Data->DrvrSteerActvChks = Data_DrvrSteerActv[0];
    p_PscmChas1Fr01_Data->DrvrSteerActvCntr = Data_DrvrSteerActv[1];
  }
  if (ProtRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief PscmChas1Fr03: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_TxPdu_PscmChas1Fr03(PduIdType id, PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType ProtRes = 0;
  struct PscmChas1Fr03_Type{
    uint8 SteerStsToParkAssi_UB                  : 1u;
    uint8 DrvrSteerWhlHldGroup_UB                : 1u;
    uint8 DrvrSteerWhlHldGroupDrvrSteerWhlHldQly : 4u;
    uint8 DrvrSteerWhlHldGroupDrvrSteerWhlHld    : 2u;
    uint8                                        : 3u;
    uint8 SteerSftyLimrSts_UB                    : 1u;
    uint8 SteerSftyLimrSts                       : 1u;
    uint8 SteerStsToParkAssi                     : 3u;
    uint8                                        : 8u;
    uint8                                        : 8u;
    uint8                                        : 8u;
    uint8 SteerExtFctStsExtSafeLimActive         : 1u;
    uint8 SteerExtFctStsLatAgReqNotInRange       : 1u;
    uint8 SteerExtFctStsLatCtrlReqNotInRange     : 1u;
    uint8 SteerExtFctSts_UB                      : 1u;
    uint8 SteerErrReq                            : 3u;
    uint8 SteerErrReq_UB                         : 1u;
    uint8 SteerExtFctStsCntr                     : 4u;
    uint8 SteerExtFctStsDrvrSteerOvrd            : 1u;
    uint8 SteerExtFctStsExtFctLowerLimActive     : 1u;
    uint8 SteerExtFctStsExtFctRateLimActive      : 1u;
    uint8 SteerExtFctStsExtFctUpperLimActive     : 1u;
    uint8 SteerExtFctStsChks                     : 8u;
  } *p_PscmChas1Fr03_Data = (struct PscmChas1Fr03_Type *)ptr->SduDataPtr;


  if (ProtRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief PscmChas1Fr06: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_TxPdu_PscmChas1Fr06(PduIdType id, PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType ProtRes = 0;
  struct PscmChas1Fr06_Type{
    uint8                      : 8u;
    uint8                      : 8u;
    uint8                      : 8u;
    uint8                      : 8u;
    uint8                      : 8u;
    uint8                      : 8u;
    uint8 PinionSteerAgMax1_H  : 7u;
    uint8 PinionSteerAgMax1_UB : 1u;
    uint8 PinionSteerAgMax1_L  : 8u;
  } *p_PscmChas1Fr06_Data = (struct PscmChas1Fr06_Type *)ptr->SduDataPtr;


  if (ProtRes)
  {
    ret = FALSE;
  }
  return ret;
}

/**
 * @brief PscmDevelpFr: 8 bytes
 * @param id: PduIdType
 * @param ptr: PduInfoType*
 * @return boolean
 */
boolean Rte_COMCbk_TxPdu_PscmDevelpFr(PduIdType id, PduInfoType *ptr)
{
  boolean ret = TRUE;
  Std_ReturnType ProtRes = 0;
  struct PscmDevelpFr_Type{
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup1 : 8u;
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup2 : 8u;
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup3 : 8u;
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup4 : 8u;
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup5 : 8u;
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup6 : 8u;
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup7 : 8u;
    uint8 PSCMdevelpsignalgroupresp1Functiondevpsignalgroup8 : 8u;
  } *p_PscmDevelpFr_Data = (struct PscmDevelpFr_Type *)ptr->SduDataPtr;


  if (ProtRes)
  {
    ret = FALSE;
  }
  return ret;
}

