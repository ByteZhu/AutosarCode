/*
 * integration.c
 *
 *  Created on: Dec 24, 2020
 *      Author: AGT1HC
 */

#include "Gtm.h"
#include "EVAdc.h"
#include "Sent.h"
#include "Ifx_reg.h"
#include "Motor_Private.h"
#include "common.h"
#include "Rte_ASW_NVM.h"
#include "NewCode.h"
#include "ASW_NVM.h"
#include "GlobalVar.h"
#include "Rte.h"
#include "EepromData.h"
#include "Dem_Cfg_EventId.h"
#include "Rte_Dem_Type.h"

static void IC_Parameter_Init(void);
static void DTC_Initialize(void);
static void CCP_Init(void);
/**************************************************************/
/* OS Tick timer start 		                                  */
/**************************************************************/
#define CPU0_START_SEC_CODE
#include "MemMap.h" /*lint !e537 permit multiple inclusion */
void IC_RteTimerStart ( void )
{
	DTC_Initialize();
	eps_controlAlgorithm_initialize();
    FrictionComp_Study_1_initialize(); //mod by liuyang for  wen ti jian cha dan B031

	IC_Parameter_Init();
	CCP_Init();
   	(void)Rte_Start();

	Sent_SetChannel(0,SENT_ENABLE);
	Sent_SetChannel(1,SENT_ENABLE);
	Sent_SetChannel(2,SENT_ENABLE);
	Sent_SetChannel(3,SENT_ENABLE);
	IoHwAb_Init();

	Gtm_StartTOM();
	EVAdc_Start();
}
#define CPU0_STOP_SEC_CODE
#include "MemMap.h" /*lint !e537 permit multiple inclusion */
#define MACRO_MBC_PI      (Int32)25736 /* 3.1416 */
static void IC_Parameter_Init(void)
{

	uint8 i = 0;
	uint8 cnt = 0;
	uint8 cnt1 = 0;
	uint8 ee_tmp = 0;
	uint8 ee_crc = 0;
	uint8 ee_calinvalid[4] = {0,};


	Fv_TOCShortFuncFbd = TRUE;
	Fv_TOCLongFuncFbd = TRUE;
	Fv_TOCSTCFbd = TRUE;
//	Fv_TSC_Configuration = FALSE;
	Fv_AOC_Configuration = FALSE;

/********************************************************************************************
Current calibration data (Primary)   check start
********************************************************************************************/

	cnt = 0;
	cnt1 = 0;
	for(i = 0; i < 12; i++)
	{
		if(Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[i] == 0)
		{
			cnt++;
		}
		else if(Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[i] == 0xFF)
		{
			cnt1++;
		}
		else{}
	}
	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[43];
	if((cnt > 8) || (cnt1 > 8))
	{
		for(i = 0; i < 44; i++)
		{
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[i] = 0xFF;
			NvM_StoreRequest.bit.CurrentOffset = 1;
		}
		ee_calinvalid[CUR_CALIB] = TRUE;
	}
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset),43);

   	if(ee_tmp != ee_crc)
   	{
   		fsSystemEEPROMDiagStatus[CUR_CALIB] = FailureDiag_InitErr;
   	}
   	else
   	{
   		fsSystemEEPROMDiagStatus[CUR_CALIB] = FailureDiag_InitOK;
   	}

/********************************************************************************************
Current calibration data (Primary)   check end
********************************************************************************************/

/********************************************************************************************
InitAngle calibration data (Primary)   check start
********************************************************************************************/

	cnt = 0;
	cnt1 = 0;
	for(i = 0; i < 18; i++)
	{
		if(Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[i] == 0)
		{
			cnt++;
		}
		else if(Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[i] == 0xFF)
		{
			cnt1++;
		}
		else{}
	}
	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[17];
	if((cnt > 18) || (cnt1 > 18))
	{
		for(i = 0; i < 18; i++)
		{
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[i] = 0xFF;
			NvM_StoreRequest.bit.CurrentOffset = 1;
		}
		ee_calinvalid[ANGI_CALIB] = TRUE;
	}
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle),17);

   	if(ee_tmp != ee_crc)
   	{
   		fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitErr;
   	}
   	else
   	{
   		fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitOK;
   	}

/********************************************************************************************
InitAngle calibration data (Primary)   check end
********************************************************************************************/

/********************************************************************************************
StrAngZero calibration data (Primary)   check start
********************************************************************************************/

	cnt = 0;
	cnt1 = 0;
	for(i = 0; i < 8; i++)
	{
		if(Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[i] == 0)
		{
			cnt++;
		}
		else if(Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[i] == 0xFF)
		{
			cnt1++;
		}
		else{}
	}
	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[7];
	if((cnt > 6) || (cnt1 > 6))
	{
		for(i = 0; i < 8; i++)
		{
			Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[i] = 0xFF;
			NvM_StoreRequest.bit.CurrentOffset = 1;
		}
		ee_calinvalid[ANGZ_CALIB] = TRUE;
	}
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero),7);

   	if(ee_tmp != ee_crc)
   	{
   		fsSystemEEPROMDiagStatus[ANGZ_CALIB] = FailureDiag_InitErr;
   	}
   	else
   	{
   		fsSystemEEPROMDiagStatus[ANGZ_CALIB] = FailureDiag_InitOK;
   	}

/********************************************************************************************
StrAngZero calibration data (Primary)   check end
********************************************************************************************/

/********************************************************************************************
AngEnd calibration data (Primary)   check start
********************************************************************************************/

	cnt = 0;
	cnt1 = 0;
	for(i = 0; i < 8; i++)
	{
		if(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[i] == 0)
		{
			cnt++;
		}
		else if(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[i] == 0xFF)
		{
			cnt1++;
		}
		else{}
	}
	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[7];
	if((cnt > 6) || (cnt1 > 6))
	{
		for(i = 0; i < 8; i++)
		{
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[i] = 0xFF;
			NvM_StoreRequest.bit.CurrentOffset = 1;
		}
		ee_calinvalid[ANGE_CALIB] = TRUE;
	}
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData),7);

   	if(ee_tmp != ee_crc)
   	{
   		fsSystemEEPROMDiagStatus[ANGE_CALIB] = FailureDiag_InitErr;
   	}
   	else
   	{
   		fsSystemEEPROMDiagStatus[ANGE_CALIB] = FailureDiag_InitOK;
   	}

/********************************************************************************************
AngEnd calibration data (Primary)   check end
********************************************************************************************/

/********************************************************************************************
Current calibration data (Primary)   read start
********************************************************************************************/
	if(fsSystemEEPROMDiagStatus[CUR_CALIB] == FailureDiag_InitOK)
	{
//		WS_FEE_SetDTCState(DTC_EEPROMcheck_CalibCheck, FailureDiag_InitOK, FAULTTYPE_EEPROM, 3);
		Fv_ErrDiagStatus[DTC_EEPROMcheck_CalibCheck] = FailureDiag_InitOK;
		fsCalibrationData.data.gainoffset.i[0] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[0] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[1];
		fsCalibrationData.data.gainoffset.i[1] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[2] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[3];
		fsCalibrationData.data.gainoffset.i[2] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[4] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[5];
		fsCalibrationData.data.gainoffset.i[3] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[6] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[7];
		fsCalibrationData.data.gainoffset.i[4] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[8] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[9];
		fsCalibrationData.data.gainoffset.i[5] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[10] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[11];
	}
	else
	{
//		WS_FEE_SetDTCState(DTC_EEPROMcheck_CalibCheck, FailureDiag_InitErr, FAULTTYPE_EEPROM, 3);
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 3);
		fsCalibrationData.data.gainoffset.i[0] = 0xFFFF;
		fsCalibrationData.data.gainoffset.i[1] = 0xFFFF;
		fsCalibrationData.data.gainoffset.i[2] = 0xFFFF;
		fsCalibrationData.data.gainoffset.i[3] = 0xFFFF;
		fsCalibrationData.data.gainoffset.i[4] = 0xFFFF;
		fsCalibrationData.data.gainoffset.i[5] = 0xFFFF;

		Fv_ErrDiagStatus[DTC_EEPROMcheck_CalibCheck] = FailureDiag_InitErr;
		Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] = FailureDiag_InitErr;
		_SetU16Varit(Fv_FaultClass_Current,3);
		_SetU16Varit(fsCalibFaultClass,0);
		_SetU16Varit(Fv_FaultClass_Current,4);
	}

	if((fsCalibrationData.data.gainoffset.i[0] > EEPROM_INIT_CURRENTUP || fsCalibrationData.data.gainoffset.i[0] < EEPROM_INIT_CURRENTDN ||
	  fsCalibrationData.data.gainoffset.i[1] > EEPROM_INIT_CURRENTUP || fsCalibrationData.data.gainoffset.i[1] < EEPROM_INIT_CURRENTDN ||
	  fsCalibrationData.data.gainoffset.i[2] > EEPROM_INIT_CURRENTUP || fsCalibrationData.data.gainoffset.i[2] < EEPROM_INIT_CURRENTDN) ||
	  (fsCalibrationData.data.gainoffset.i[3] > EEPROM_INIT_CURRENTUP || fsCalibrationData.data.gainoffset.i[3] < EEPROM_INIT_CURRENTDN ||
	  fsCalibrationData.data.gainoffset.i[4] > EEPROM_INIT_CURRENTUP || fsCalibrationData.data.gainoffset.i[4] < EEPROM_INIT_CURRENTDN ||
	  fsCalibrationData.data.gainoffset.i[5] > EEPROM_INIT_CURRENTUP || fsCalibrationData.data.gainoffset.i[5] < EEPROM_INIT_CURRENTDN) ||
	  (ee_calinvalid[CUR_CALIB] > 0))
	{
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 3);

		Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] = FailureDiag_InitErr;
		_SetU16Varit(Fv_FaultClass_Current,3);
		_SetU16Varit(fsCalibFaultClass,1);
		_SetU16Varit(Fv_FaultClass_Current,4);
	}

/********************************************************************************************
Current calibration data (Primary)   read stop
********************************************************************************************/


/********************************************************************************************
InitAngle calibration data (Primary)   read start
********************************************************************************************/

	if(fsSystemEEPROMDiagStatus[ANGI_CALIB] == FailureDiag_InitOK)
	{
//		WS_FEE_SetDTCState(DTC_EEPROMcheck_CalibCheck, FailureDiag_InitOK, FAULTTYPE_EEPROM, 3);
		Fv_ErrDiagStatus[DTC_EEPROMcheck_CalibCheck] = FailureDiag_InitOK;

		MotorCtrl_FocPar[PreDriver_01].initangle = (sint32)(((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[0] << 24)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[1] << 16)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[2] <<  8)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[3] <<  0));

		MotorCtrl_FocPar[PreDriver_01].initanglecrr = (sint32)(((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[4] << 24)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[5] << 16)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[6] <<  8)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[7] <<  0));

		MotorCtrl_FocPar[PreDriver_02].initangle = (sint32)(((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[8] << 24)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[9] << 16)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[10] <<  8)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[11] <<  0));

		MotorCtrl_FocPar[PreDriver_02].initanglecrr = (sint32)(((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[12] << 24)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[13] << 16)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[14] <<  8)|
															((uint32)Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[15] <<  0));
	}
	else
	{
//		WS_FEE_SetDTCState(DTC_EEPROMcheck_CalibCheck, FailureDiag_InitErr, FAULTTYPE_EEPROM, 3);
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 4);
		MotorCtrl_FocPar[PreDriver_01].initangle = 0xFFFF;
		MotorCtrl_FocPar[PreDriver_01].initanglecrr = 0xFFFF;
		MotorCtrl_FocPar[PreDriver_02].initangle = 0xFFFF;
		MotorCtrl_FocPar[PreDriver_02].initanglecrr = 0xFFFF;
		Fv_ErrDiagStatus[DTC_EEPROMcheck_CalibCheck] = FailureDiag_InitErr;
		Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] = FailureDiag_InitErr;
		_SetU16Varit(Fv_FaultClass_Current,3);
		_SetU16Varit(fsCalibFaultClass,2);
		_SetU16Varit(Fv_FaultClass_Current,4);

	}

	if((MotorCtrl_FocPar[PreDriver_01].initanglecrr > EEPROM_INIT_MAXCCRA) || (MotorCtrl_FocPar[PreDriver_01].initanglecrr < -EEPROM_INIT_MAXCCRA))
	{
		MotorCtrl_FocPar[PreDriver_01].initanglecrr = 0xFFFF;
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 4);
		Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] = FailureDiag_InitErr;
		_SetU16Varit(Fv_FaultClass_Current,3);
		_SetU16Varit(fsCalibFaultClass,3);
		_SetU16Varit(Fv_FaultClass_Current,4);
	}
	else{}


/********************************************************************************************
InitAngle calibration data (Primary)   read end
********************************************************************************************/

/********************************************************************************************
Rotor offset calibration data (Primary)   read start
********************************************************************************************/

	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[33];
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset),33);

	if(ee_tmp == ee_crc)
	{
		/* Rotor Offset */
		AD_RotorSinOffsetMax[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[0] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[1];
		AD_RotorSinOffsetMin[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[2] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[3];
		AD_RotorCosOffsetMax[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[4] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[5];
		AD_RotorCosOffsetMin[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[6] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[7];

		AD_RotorPhasePlusMax[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[8] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[9];
		AD_RotorPhasePlusMin[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[10] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[11];
		AD_RotorPhaseMinusMax[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[12] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[13];
		AD_RotorPhaseMinusMin[PreDriver_01] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[14] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[15];


		AD_RotorSinOffsetMax[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[16] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[17];
		AD_RotorSinOffsetMin[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[18] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[19];
		AD_RotorCosOffsetMax[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[20] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[21];
		AD_RotorCosOffsetMin[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[22] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[23];

		AD_RotorPhasePlusMax[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[24] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[25];
		AD_RotorPhasePlusMin[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[26] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[27];
		AD_RotorPhaseMinusMax[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[28] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[29];
		AD_RotorPhaseMinusMin[PreDriver_02] = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[30] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[31];

		if(	(AD_RotorSinOffsetMax[PreDriver_01] > 1600) ||  (AD_RotorSinOffsetMax[PreDriver_01] < 1000)||
			(AD_RotorSinOffsetMin[PreDriver_01] > -1000)  ||  (AD_RotorSinOffsetMin[PreDriver_01] < -1600)||
			(AD_RotorCosOffsetMax[PreDriver_01] > 1600) ||  (AD_RotorCosOffsetMax[PreDriver_01] < 1000)||
			(AD_RotorCosOffsetMin[PreDriver_01] > -1000)  ||  (AD_RotorCosOffsetMin[PreDriver_01] < -1600)||
			(AD_RotorPhasePlusMax[PreDriver_01] > 3300) ||  (AD_RotorPhasePlusMax[PreDriver_01] < 2500)||
			(AD_RotorPhasePlusMin[PreDriver_01] > -2500)  ||  (AD_RotorPhasePlusMin[PreDriver_01] < -3300)||
			(AD_RotorPhaseMinusMax[PreDriver_01] > 3300) ||  (AD_RotorPhaseMinusMax[PreDriver_01] < 2500)||
			(AD_RotorPhaseMinusMin[PreDriver_01] > -2500)  ||  (AD_RotorPhaseMinusMin[PreDriver_01] < -3300)||
			(AD_RotorSinOffsetMax[PreDriver_02] > 1600) ||  (AD_RotorSinOffsetMax[PreDriver_02] < 1000)||
			(AD_RotorSinOffsetMin[PreDriver_02] > -1000)  ||  (AD_RotorSinOffsetMin[PreDriver_02] < -1600)||
			(AD_RotorCosOffsetMax[PreDriver_02] > 1600) ||  (AD_RotorCosOffsetMax[PreDriver_02] < 1000)||
			(AD_RotorCosOffsetMin[PreDriver_02] > -1000)  ||  (AD_RotorCosOffsetMin[PreDriver_02] < -1600)||
			(AD_RotorPhasePlusMax[PreDriver_02] > 3300) ||  (AD_RotorPhasePlusMax[PreDriver_02] < 2500)||
			(AD_RotorPhasePlusMin[PreDriver_02] > -2500)  ||  (AD_RotorPhasePlusMin[PreDriver_02] < -3300)||
			(AD_RotorPhaseMinusMax[PreDriver_02] > 3300) ||  (AD_RotorPhaseMinusMax[PreDriver_02] < 2500)||
			(AD_RotorPhaseMinusMin[PreDriver_02] > -2500)  ||  (AD_RotorPhaseMinusMin[PreDriver_02] < -3300))
		{
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 3);
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 4);
			Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] = FailureDiag_InitErr;
			_SetU16Varit(Fv_FaultClass_Current,3);
			_SetU16Varit(Fv_FaultClass_Current,4);
		}

	}
	else
	{
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 3);
//		WS_FEE_SetDTCState(DTC_CURRENTcheck_IcalibInvalid, FailureDiag_InitErr, FAULTTYPE_CURRENT, 4);
		Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] = FailureDiag_InitErr;
		_SetU16Varit(Fv_FaultClass_Current,3);
		_SetU16Varit(fsCalibFaultClass,4);
		_SetU16Varit(Fv_FaultClass_Current,4);
	}
/********************************************************************************************
Rotor offset calibration data (Primary)   read end
********************************************************************************************/

/********************************************************************************************
StrAngZero and SteerEnd calibration data (Primary)   read start
********************************************************************************************/


	if(fsSystemEEPROMDiagStatus[ANGZ_CALIB] == FailureDiag_InitOK)
	{
//		WS_FEE_SetDTCState(DTC_EEPROMcheck_AngleCheck, FailureDiag_InitOK, 0xFF, 0);
		Fv_ErrDiagStatus[DTC_EEPROMcheck_AngleCheck] = FailureDiag_InitOK;
 		fsCalibrationData.data.anglezero.a0 = ((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[0] << 8) | Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[1];
		fsCalibrationData.data.anglezero.st |= ((Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[5] > 0) << 1);

		if(fsSystemEEPROMDiagStatus[ANGE_CALIB] == FailureDiag_InitOK)
		{
			fsCalibrationData.data.anglezero.al = ((SInt16)(((UInt16)Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[0] << 8) | ((UInt16)Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[1] << 0)));
			fsCalibrationData.data.anglezero.ar = ((SInt16)(((UInt16)Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[2] << 8) | ((UInt16)Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[3] << 0)));
			fsCalibrationData.data.anglezero.st |= ((Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[5] > 0) << 0);
		}
		else
		{
			fsCalibrationData.data.anglezero.al = 0xFFFF;
			fsCalibrationData.data.anglezero.ar = 0xFFFF;
			fsCalibrationData.data.anglezero.st &= ~1;
		}

	}
	else
	{
//		WS_FEE_SetDTCState(DTC_EEPROMcheck_AngleCheck, FailureDiag_InitErr, 0xFF, 0);
		Fv_ErrDiagStatus[DTC_EEPROMcheck_AngleCheck] = FailureDiag_InitErr;
		fsCalibrationData.data.anglezero.a0 = 0;
		fsCalibrationData.data.anglezero.al = 0xFFFF;
		fsCalibrationData.data.anglezero.ar = 0xFFFF;
		fsCalibrationData.data.anglezero.st = 0;
	}

	if((fsCalibrationData.data.anglezero.st & 2) == 2)
	{
//		WS_FEE_SetDTCState(DTC_ANGLEcheck_NoZeroCalib, FailureDiag_InitOK, FAULTTYPE_ANGLE, 0);
		Fv_ErrDiagStatus[DTC_ANGLEcheck_NoZeroCalib] = FailureDiag_InitOK;
		_ClrU16Varit(Fv_FaultClass_Angle,0);
		Fv_AngleMidValidFlag = ANGLE_STS_Valid;

		if((fsCalibrationData.data.anglezero.st & 3) == 3)
		{
			if((fsCalibrationData.data.anglezero.al < EEPROM_INIT_VALIDA) && (fsCalibrationData.data.anglezero.ar < EEPROM_INIT_VALIDA))
			{
//				WS_FEE_SetDTCState(DTC_ANGLEcheck_NoEndLearn, FailureDiag_InitOK, FAULTTYPE_ANGLE, 3);
				Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] = FailureDiag_InitOK;
				Fv_AngleEndValidFlag = ANGLE_STS_Valid;
#if 0
				rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_LeftMaxAng  = (sint16)(-((sint16)(fsCalibrationData.data.anglezero.al)));
				rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_RightMaxAng = (sint16)(fsCalibrationData.data.anglezero.ar);
				Tv_SE_LeftMaxAng = rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_LeftMaxAng;
				Tv_SE_RightMaxAng = rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_RightMaxAng;
#else
				Tv_SE_LeftMaxAng  = (sint16)(-((sint16)(fsCalibrationData.data.anglezero.al)));
				Tv_SE_RightMaxAng = (sint16)(fsCalibrationData.data.anglezero.ar);
#endif
			}
			else
			{
//				WS_FEE_SetDTCState(DTC_ANGLEcheck_NoEndLearn, FailureDiag_InitErr, FAULTTYPE_ANGLE, 3);
				Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] = FailureDiag_InitErr;
				_SetU16Varit(Fv_FaultClass_Angle,3);
				Fv_AngleEndValidFlag = ANGLE_STS_Invalid;
			}
		}
		else
		{
//			WS_FEE_SetDTCState(DTC_ANGLEcheck_NoEndLearn, FailureDiag_InitErr, FAULTTYPE_ANGLE, 3);
			Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] = FailureDiag_InitErr;
			_SetU16Varit(Fv_FaultClass_Angle,3);
			Fv_AngleEndValidFlag = ANGLE_STS_Invalid;
		}
	}
	else
	{
//		WS_FEE_SetDTCState(DTC_ANGLEcheck_NoZeroCalib, FailureDiag_InitErr, FAULTTYPE_ANGLE, 0);
//		WS_FEE_SetDTCState(DTC_ANGLEcheck_NoEndLearn, FailureDiag_InitErr, FAULTTYPE_ANGLE, 3);
		Fv_AngleMidValidFlag = ANGLE_STS_Invalid;
		Fv_AngleEndValidFlag = ANGLE_STS_Invalid;
		Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] = FailureDiag_InitErr;
		_SetU16Varit(Fv_FaultClass_Angle,3);
		Fv_ErrDiagStatus[DTC_ANGLEcheck_NoZeroCalib] = FailureDiag_InitErr;
		_SetU16Varit(Fv_FaultClass_Angle,0);
	}
/********************************************************************************************
StrAngZero and SteerEnd calibration data (Primary)   read end
********************************************************************************************/

/********************************************************************************************
CCP and AssistMode   read start
********************************************************************************************/
#if 0
	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[7];
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal),7);
   	if(ee_tmp != ee_crc)
   	{

   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitErr;
   	}
   	else
   	{
		Fv_CANCCP1 = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[0];
		Fv_CANCCP3 = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[1];
		Fv_CANCCP13 = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[2];
		Fv_CANCCP16 = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[3];
		Fv_CANCCP17 = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[4];
		Fv_CANCCP50 = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[5];
		Fv_CANCCP57 = Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[6];
   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitOK;
   	}

	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[7];
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd),7);
   	if(ee_tmp != ee_crc)
   	{

   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitErr;
   	}
   	else
   	{
		Fv_CANCCP58 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[0];
		Fv_CANCCP62 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[1];
		Fv_CANCCP142 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[2];
		Fv_CANCCP150 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[3];
		Fv_CANCCP316 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[4];
		Fv_CANCCP494 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[5];
		Fv_CANCCP565 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[6];
   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitOK;
   	}

	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[7];
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored),7);
   	if(ee_tmp != ee_crc)
   	{

   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitErr;
   		Fv_RUNAssistSelectMode = ASS_TYPE_STANDARD;
   	}
   	else
   	{
		Fv_CANCCP639 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[0];
		Fv_CANCCP640 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[1];
		Fv_RUNAssistSelectMode = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[2];
		Fv_CANCCP317 = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[3];
		Fv_CANCCPbulk_state= Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[4];
		Fv_SWP2_TS = Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[5];
   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitOK;
   	}
   	Fv_CMDAssistSelectMode = Fv_RUNAssistSelectMode;
   	Fv_SteerAssistMode = Fv_RUNAssistSelectMode;
/********************************************************************************************
CCP and AssistMode   read end
********************************************************************************************/

#endif
/********************************************************************************************
PDC and FC read start
********************************************************************************************/

	ee_tmp = Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[7];
	ee_crc = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored),7);
   	if(ee_tmp != ee_crc)
   	{
   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitErr;
		Fv_AngleCorrectStoredValid = FALSE;

   	}
   	else
   	{
		Fv_AngleCorrectStoredValid = TRUE;
		Fv_TOCInitStyTrq = (sint16)((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[0] << 8 | (uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[1]);
		Fv_AngleCorrectOpr = (sint16)((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[2] << 8 | (uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[3]);
		Fv_FriCompAdptiveTorque = (sint16)((uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[4] << 8 | (uint16)Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[5]);
		Fv_FriCompAdptiveTorqueLast = Fv_FriCompAdptiveTorque;
		if(Fv_AngleCorrectOpr > 56)
		{
			Fv_AngleCorrectOpr = 56;
		}
		else if(Fv_AngleCorrectOpr < -56)
		{
			Fv_AngleCorrectOpr = -56;
		}
		Fv_AngleCorrectOprLast = Fv_AngleCorrectOpr;
		Fv_TOCLongStyTrqLast = Fv_TOCInitStyTrq;

   		//fsSystemEEPROMDiagStatus[ANGI_CALIB] = FailureDiag_InitOK;
   	}

/********************************************************************************************
PDC and AssistMode   read end
********************************************************************************************/


#if 0 //HARD
	fsCalibrationData.data.gainoffset.i[0] = 1988;
	fsCalibrationData.data.gainoffset.i[1] = 2036;
	fsCalibrationData.data.gainoffset.i[2] = 2024;

	fsCalibrationData.data.gainoffset.i[3] = 2000;//Eeprom_CalibGainOffset.halfword[3];
	fsCalibrationData.data.gainoffset.i[4] = 2015;//Eeprom_CalibGainOffset.halfword[4];
	fsCalibrationData.data.gainoffset.i[5] = 1993;//Eeprom_CalibGainOffset.halfword[5];


	AD_RotorSinOffsetMax[PreDriver_01] = 1311;
	AD_RotorSinOffsetMin[PreDriver_01] = -1300;
	AD_RotorCosOffsetMax[PreDriver_01] = 1322;
	AD_RotorCosOffsetMin[PreDriver_01] = -1319;

	AD_RotorSinOffsetMax[PreDriver_02] = 1319;
	AD_RotorSinOffsetMin[PreDriver_02] = -1296;
	AD_RotorCosOffsetMax[PreDriver_02] = 1308;
	AD_RotorCosOffsetMin[PreDriver_02] = -1298;

	AD_RotorPhasePlusMax[PreDriver_01] = 2961;
	AD_RotorPhasePlusMin[PreDriver_01] = -2961;
	AD_RotorPhaseMinusMax[PreDriver_01] = 2785;
	AD_RotorPhaseMinusMin[PreDriver_01] = -2834;

	AD_RotorPhasePlusMax[PreDriver_02] = 2960;
	AD_RotorPhasePlusMin[PreDriver_02] = -2963;
	AD_RotorPhaseMinusMax[PreDriver_02] = 2792;
	AD_RotorPhaseMinusMin[PreDriver_02] = -2789;


	MotorCtrl_FocPar[PreDriver_01].initangle = -20333;
	MotorCtrl_FocPar[PreDriver_02].initangle = -20333;
#if 0

	MotorCtrl_FocPar[PreDriver_01].initanglecrr = Eeprom_MotorAngle.data.anglecorrect1;
	MotorCtrl_FocPar[PreDriver_02].initanglecrr = Eeprom_MotorAngle.data.anglecorrect1;

#endif

#endif

#if 0	//SOFT1
	AD_RotorSinOffsetMax[PreDriver_01] = 1308;
	AD_RotorSinOffsetMin[PreDriver_01] = -1318;
	AD_RotorCosOffsetMax[PreDriver_01] = 1307;
	AD_RotorCosOffsetMin[PreDriver_01] = -1318;

	AD_RotorSinOffsetMax[PreDriver_02] = 1323;
	AD_RotorSinOffsetMin[PreDriver_02] = -1320;
	AD_RotorCosOffsetMax[PreDriver_02] = 1292;
	AD_RotorCosOffsetMin[PreDriver_02] = -1301;

	AD_RotorPhasePlusMax[PreDriver_01] = 3029;
	AD_RotorPhasePlusMin[PreDriver_01] = -3025;
	AD_RotorPhaseMinusMax[PreDriver_01] = 2691;
	AD_RotorPhaseMinusMin[PreDriver_01] = -2692;

	AD_RotorPhasePlusMax[PreDriver_02] = 2883;
	AD_RotorPhasePlusMin[PreDriver_02] = -2889;
	AD_RotorPhaseMinusMax[PreDriver_02] = 2840;
	AD_RotorPhaseMinusMin[PreDriver_02] = -2844;

	fsCalibrationData.data.gainoffset.i[0] = 2025;
	fsCalibrationData.data.gainoffset.i[1] = 2048;
	fsCalibrationData.data.gainoffset.i[2] = 2009;

	fsCalibrationData.data.gainoffset.i[3] = 2012;
	fsCalibrationData.data.gainoffset.i[4] = 2030;
	fsCalibrationData.data.gainoffset.i[5] = 2063;



	//MotorCtrl_FocPar[PreDriver_01].initangle = MACRO_MBC_PI - (25736);
	//MotorCtrl_FocPar[PreDriver_02].initangle = MACRO_MBC_PI - (25736);
	MotorCtrl_FocPar[PreDriver_01].initangle = -25736;
	MotorCtrl_FocPar[PreDriver_02].initangle = -25736;
#if 0

	MotorCtrl_FocPar[PreDriver_01].initanglecrr = Eeprom_MotorAngle.data.anglecorrect1;
	MotorCtrl_FocPar[PreDriver_02].initanglecrr = Eeprom_MotorAngle.data.anglecorrect1;

#endif
#endif


#if 0	//soft 2
	AD_RotorSinOffsetMax[PreDriver_01] = 1304;
	AD_RotorSinOffsetMin[PreDriver_01] = -1307;
	AD_RotorCosOffsetMax[PreDriver_01] = 1333;
	AD_RotorCosOffsetMin[PreDriver_01] = -1331;

	AD_RotorSinOffsetMax[PreDriver_02] = 1324;
	AD_RotorSinOffsetMin[PreDriver_02] = -1312;
	AD_RotorCosOffsetMax[PreDriver_02] = 1297;
	AD_RotorCosOffsetMin[PreDriver_02] = -1295;

	AD_RotorPhasePlusMax[PreDriver_01] = 2841;
	AD_RotorPhasePlusMin[PreDriver_01] = -2834;
	AD_RotorPhaseMinusMax[PreDriver_01] = 2924;
	AD_RotorPhaseMinusMin[PreDriver_01] = -2922;

	AD_RotorPhasePlusMax[PreDriver_02] = 2949;
	AD_RotorPhasePlusMin[PreDriver_02] = -2950;
	AD_RotorPhaseMinusMax[PreDriver_02] = 2802;
	AD_RotorPhaseMinusMin[PreDriver_02] = -2803;


	fsCalibrationData.data.gainoffset.i[0] = 2017;
	fsCalibrationData.data.gainoffset.i[1] = 2044;
	fsCalibrationData.data.gainoffset.i[2] = 2061;

	fsCalibrationData.data.gainoffset.i[3] = 2030;
	fsCalibrationData.data.gainoffset.i[4] = 2037;
	fsCalibrationData.data.gainoffset.i[5] = 2020;


	MotorCtrl_FocPar[PreDriver_01].initangle =  - (6520);
	MotorCtrl_FocPar[PreDriver_02].initangle =  - (6520);

	NvM_StoreRequest.bit.RotorOffset = 1;
	NvM_StoreRequest.bit.InitAngle = 1;
	NvM_StoreRequest.bit.CurrentOffset = 1;

#endif


}
static void DTC_Initialize(void)
{
	uint8 i = 0;

	MDLINT8U rdst[16] = {0,};

	for(i = 0; i < 16; i++)
	{
		Eeprom_DTCStatus[i] = Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[i];
		rdst[i] = Eeprom_DTCStatus[i];
	}

	for(i=0;i<EPS_DTC_NUM_MAX;i++)
	{
		DTC_Ctrl_Info_Tab[i].Enabled = TRUE;
		DTC_Ctrl_Info_Tab[i].SnapShotAllowed = TRUE;
        DTC_State_Info_Tab[i].testFailed 					      = FALSE;
        DTC_State_Info_Tab[i].testFailedThisMonitoringCycle 	  = FALSE;
        DTC_State_Info_Tab[i].confirmedDTC                        = (rdst[i / 8] >> (i - (i / 8) * 8)) & 0x01;
        DTC_State_Info_Tab[i].testNotCompletedThisMonitoringCycle = FALSE;
        DTC_State_Info_Tab[i].warningIndicatorRequest 			  = FALSE;

        DTC_Ctrl_Info_Tab[i].OnStarTrigEnabled 					  = FALSE;
        DTC_Ctrl_Info_Tab[i].Enabled 						      = TRUE;
        DTC_Ctrl_Info_Tab[i].LightLampReq                         = FALSE;
        DTC_Ctrl_Info_Tab[i].LightLampUnrecover 				  = TRUE;
	}
	/*PIN CODE INIT*/
     for(i = 0; i < 24; i++)
    {
            Eeprom_PINCODE[i] = Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[i + 16 + 32];
            if(Eeprom_PINCODE[23] ==  CRC8forSAEJ1850(Eeprom_PINCODE, 23))
            {
                    //Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd63451_Event), DEM_EVENT_STATUS_PASSED);
            }
            else
            {
                    //Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd63451_Event), DEM_EVENT_STATUS_FAILED);
            }                
     } 
}
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
static void CCP_Init(void)
{
#define COPYFLASHTORAMLGTH 0x43FF
#define CAL_DARA_FLASH_ADDR 0x80100000ul
#define CAL_DARA_FLASH_ADDR_1 0x80108000ul
#define CAL_DARA_RAM_ADDR   0x70018000ul

	uint32 i = 0;
	uint8 crc = 0;
	uint8* targetPtr = NULL_PTR;
	uint8* ramPtr = NULL_PTR;
	uint32 mp_targetAddr = 0;
	uint32 mp_RamAddr = 0;

	for(i = 0; i < 32; i ++)
	{
		Eeprom_CanCCp.byte[i] = Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[i + 16];
	}

	crc = CRC8forSAEJ1850(Eeprom_CanCCp.byte, 31);

	if(crc == Eeprom_CanCCp.data.crc)
	{
		Fv_CANCCP1 = Eeprom_CanCCp.data.ccp1;
		Fv_CANCCP3 = Eeprom_CanCCp.data.ccp3;
		Fv_CANCCP13 = Eeprom_CanCCp.data.ccp13;
		Fv_CANCCP17 = Eeprom_CanCCp.data.ccp17;
		Fv_CANCCP50 = Eeprom_CanCCp.data.ccp50;
		Fv_CANCCP58 = Eeprom_CanCCp.data.ccp58;
		Fv_CANCCP59 = Eeprom_CanCCp.data.ccp59;
		Fv_CANCCP62 = Eeprom_CanCCp.data.ccp62;
		Fv_CANCCP100 = Eeprom_CanCCp.data.ccp100;
		Fv_CANCCP142 = Eeprom_CanCCp.data.ccp142;
		Fv_CANCCP150 = Eeprom_CanCCp.data.ccp150;
		Fv_CANCCP317 = Eeprom_CanCCp.data.ccp317;
		Fv_CANCCP494 = Eeprom_CanCCp.data.ccp494;
		Fv_CANCCP540 = Eeprom_CanCCp.data.ccp540;
		Fv_CANCCP547 = Eeprom_CanCCp.data.ccp547;
		Fv_CANCCP565 = Eeprom_CanCCp.data.ccp565;
		Fv_CANCCP609 = Eeprom_CanCCp.data.ccp609;
		Fv_CANCCP639 = Eeprom_CanCCp.data.ccp639;
		Fv_CANCCP640 = Eeprom_CanCCp.data.ccp640;
		Fv_CANCCP655 = Eeprom_CanCCp.data.ccp655;
		Fv_CANCCP695 = Eeprom_CanCCp.data.ccp695;
		Fv_CANCCP741 = Eeprom_CanCCp.data.ccp741;
	}
	else
	{
		Fv_CANCCP1 = 0x94;
		Fv_CANCCP3 = 0;
		Fv_CANCCP13 = 0;
		Fv_CANCCP17 = 0;
		Fv_CANCCP50 = 0;
		Fv_CANCCP58 = 1;
		Fv_CANCCP59 = 0;
		Fv_CANCCP62 = 0;
		Fv_CANCCP100 = 0;
		Fv_CANCCP142 = 0;
		Fv_CANCCP150 = 0;
		Fv_CANCCP317 = 0;
		Fv_CANCCP494 = 0;
		Fv_CANCCP540 = 0;
		Fv_CANCCP547 = 1;
		Fv_CANCCP565 = 1;
		Fv_CANCCP609 = 1;
		Fv_CANCCP639 = 1;
		Fv_CANCCP640 = 1;
		Fv_CANCCP655 = 1;
		Fv_CANCCP695 = 0;
		Fv_CANCCP741 = 1;
	}

	if(Fv_CANCCP1 == 0x94)
	{
		mp_RamAddr = CAL_DARA_RAM_ADDR;
		mp_targetAddr = CAL_DARA_FLASH_ADDR;
	}
	else
	{
		mp_RamAddr = CAL_DARA_RAM_ADDR;
		mp_targetAddr = CAL_DARA_FLASH_ADDR;
	}

	ramPtr = (uint8 *)mp_RamAddr;
	targetPtr = (uint8 *)mp_targetAddr;

	for(i = 0; i < COPYFLASHTORAMLGTH; i++)
	{
		ramPtr[i] = targetPtr[i];
	}
}
