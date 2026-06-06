/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of MDL Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   MDL Technologies.
************************************************************************************************
*   File Name       : TESTMODE.c
************************************************************************************************
*   Project/Product : EPS Project
*   Title           : Standard Define 
*   Author          : QUN
************************************************************************************************
*   Description     : Define TESTMODE module.
*
************************************************************************************************
*   Limitations     : NONE
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version       Date         Initials     CR#           Descriptions
*   ---------   -----------  ------------  ----------  ---------------
*    0.1          31/01/12     QUN        N/A           Original
*
************************************************************************************************
*   END_FILE_HDR*/
#ifndef TESTMODE_C
#define TESTMODE_C
#include "TestMode.h"
//#include "flexcan.h"
#include "Motor.h"
#include "Motor_Private.h"
#include "EPS_TL_lut.h"
#include "CalVar.h"
#include "Ifx_reg.h"
#include "EepromData.h"
#include "GlobalVarCan.h"
#include "ASW_NVM.h"
//#include  "ssd_c90fl.h"
//#include  "init.h"
//#include  "IO.h"
//#include  "monitor.h"
#if TESTMODE_SEGMENt_DEF
#pragma push
#pragma force_active on
#pragma section const_type ".product_info" 
#endif


//#define ENABLE_PWM_SELECT
#define ENABLE_SENT_PWM_SELECT

#define PutMsg_ECUTESTMODE ASW_COM_TestModeResponseSend
#define IlGetRxTestModeRequest0() TestMode_RequestData[0]
#define IlGetRxTestModeRequest1() TestMode_RequestData[1]
#define IlGetRxTestModeRequest2() TestMode_RequestData[2]
#define IlGetRxTestModeRequest3() TestMode_RequestData[3]
#define IlGetRxTestModeRequest4() TestMode_RequestData[4]
#define IlGetRxTestModeRequest5() TestMode_RequestData[5]
#define IlGetRxTestModeRequest6() TestMode_RequestData[6]
#define IlGetRxTestModeRequest7() TestMode_RequestData[7]

#define  T212L_SinMax AD_RotorSinOffsetMax
#define  T212L_SinMin AD_RotorSinOffsetMin
#define  T212L_CosMax AD_RotorCosOffsetMax
#define  T212L_CosMin AD_RotorCosOffsetMin
#define  T212L_PhaseSinMax AD_RotorPhasePlusMax
#define  T212L_PhaseSinMin AD_RotorPhasePlusMin
#define  T212L_PhaseCosMax AD_RotorPhaseMinusMax
#define  T212L_PhaseCosMin AD_RotorPhaseMinusMin

#define Eeprom_WriteTestMode(data)
#define Eeprom_WriteCalibGainOffset(data) (NvM_StoreRequest.bit.CurrentOffset = 1)
#define Eeprom_WriteMotorResolver(data)
#define Eeprom_WriteMotorPhase(data)	(NvM_StoreRequest.bit.RotorOffset = 1)
#define Eeprom_WriteMotorAngle(data)	(NvM_StoreRequest.bit.InitAngle = 1)

#define DspiA4911Send(data) 0
/*DFLASH addr = 0x00800000*/
#define TESTMODE_PRODUCTINFO    0x8007FF00
const MDLINT32U  glbProductInfo[16] = 
{
	0x60000100,0x11572301,0x00010202,0x00000000,
};

const MDLINT8U LIST_GeelyProductExtNum[12] =
{
	0x60,0x70,0x66,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x71
};//mod to 0071 by liuyang at 24 11 15

#if TESTMODE_SEGMENt_DEF
#pragma force_active off
#pragma pop
#endif
/*
#pragma push
#pragma force_active on
#pragma section sconst_type ".rom_checksum" 

const MDLINT32U initROM_CheckSum = 0x2B63DD00;
#pragma force_active off


#pragma pop
*/

#if defined(PRODUCT_ENABLE_BTCOM) 
#if TESTMODE_SEGMENt_DEF
	#pragma push
	#pragma force_active on
	#pragma section sconst_type ".rom_appvalid" 
#endif
	const MDLINT32U app_DownLoadFinish = 0x01010101;
#if TESTMODE_SEGMENt_DEF
	//If need, can be increased,const flashchecksum
	#pragma force_active off
	#pragma pop
#endif
#endif


#if defined(PRODUCT_ENABLE_ENCRYPTION)
#if TESTMODE_SEGMENt_DEF
	extern const unsigned int FlashInit_C[];
	extern const unsigned int FlashErase_C[];
	extern const unsigned int BlankCheck_C[];
	extern const unsigned int FlashProgram_C[];
	extern const unsigned int ProgramVerify_C[];
	extern const unsigned int CheckSum_C[];
	extern const unsigned int GetLock_C[];
	extern const unsigned int SetLock_C[];

	/* Assign function pointers */
	pFLASHINIT     pFlashInit     = (pFLASHINIT)     FlashInit_C;
	pFLASHERASE    pFlashErase    = (pFLASHERASE)    FlashErase_C;
	pBLANKCHECK    pBlankCheck    = (pBLANKCHECK)    BlankCheck_C;
	pFLASHPROGRAM  pFlashProgram  = (pFLASHPROGRAM)  FlashProgram_C;
	pPROGRAMVERIFY pProgramVerify = (pPROGRAMVERIFY) ProgramVerify_C;
	pCHECKSUM      pCheckSum      = (pCHECKSUM)      CheckSum_C;
	pGETLOCK       pGetLock       = (pGETLOCK)       GetLock_C;
	pSETLOCK       pSetLock       = (pSETLOCK)       SetLock_C;


	/* CFlash */
	SSD_CONFIG ssdConfig = {
	    C90FL_REG_BASE,         /* Flash control register base */
	    MAIN_ARRAY_BASE,        /* base of main array */
	    0,                      /* size of main array */
	    SHADOW_ROW_BASE,        /* base of shadow row */
	    SHADOW_ROW_SIZE,        /* size of shadow row */
	    0,                      /* block number in low address space */
	    0,                      /* block number in middle address space */
	    0,                      /* block number in high address space */
	    FLASH_PAGE_SIZE,        /* flash page size selection */
	    FALSE                    /* debug mode selection */
	};



	MDLINT32U scrt_appvalid;
	MDLINT32U scrt_writedata[2];
	MDLINT32U scrt_buffer[2];
	MDLINT32U scrt_source;
#endif
#endif

extern void ASW_COM_TestModeResponseSend(uint8 *data);

static void TM_CommunicationCheckProcess(void);
static void TM_SelfCheckProcess(void);
static void TM_PSL_EE_9VCheckProcess(void);
static void TM_PSL_EE_18VCheckProcess(void);
static void TM_MainRelayCloseProcess(void);
static void TM_PreDriverRelayOpenProcess(void);
static void TM_NormalVolTorqueProcess(void);
static void TM_LowVolTorqueProcess(void);
static void TM_HighVolTorqueProcess(void);

static void TM_OpenLoopCalMidProcess(void);
static void TM_OpenLoopCalAmp1Process(void);
static void TM_OpenLoopCalAmp2Process(void);
static void TM_OpenLoopWriteCalProcess(void);
static void TM_OpenLoopRUNProcess(void);
static void TM_ResolverTemperatureProcess(void);
static void TM_ResolverInitAngleProcess(void);

static void TM_CloseLoopNormalPosProcess(void);
static void TM_CloseLoopNormalNegProcess(void);
static void TM_CloseLoopLowPosProcess(void);
static void TM_CloseLoopHighNegProcess(void);
static void TM_CloseLoopRevUDProcess(void);

static void TM_PowerLatchProcess(void);
static void TM_ProductInfoProcess(void);

static void TM_PowerOnTimesRecordProcess(void);

static void TM_FCTInputOutputAvailctrl(void);
static void TM_FCTInputOutputNavailctrl(void);

static void TM_AGING_TEST_CHECK_Func(void);

static Int32 TM_FCT_CurrentMid[6] = {0};
static void TM_CALIB_DATA_CHECK_Func(void);
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
uint8 TestMode_DebugInfoEnable;
static void TM_TestMode_AngProcess(void)
{
	uint8 databuf[8] = {0,};
	uint8 i = 0;

	if(1||testmode_req == 0xAA)
	{
		//testmode_req = 0;
#if 0
		TestMode_RequestData[0] = IlGetRxTestModeRequest0();
		TestMode_RequestData[1] = IlGetRxTestModeRequest1();
		TestMode_RequestData[2] = IlGetRxTestModeRequest2();
		TestMode_RequestData[3] = IlGetRxTestModeRequest3();
		TestMode_RequestData[4] = IlGetRxTestModeRequest4();
		TestMode_RequestData[5] = IlGetRxTestModeRequest5();
		TestMode_RequestData[6] = IlGetRxTestModeRequest6();
		TestMode_RequestData[7] = IlGetRxTestModeRequest7();
#endif

		if((TestMode_RequestData[2] == 0x9C)&& (TestMode_RequestData[3] == 0x1A) && (TestMode_RequestData[4] == 0xBF)
				&& (TestMode_RequestData[5] == 0x38) && (TestMode_RequestData[6] == 0x45) && (TestMode_RequestData[7] == 0x2D))
		{
			//TestMode_HandShakeRequest = 0xAA;
		}
		else if((TestMode_RequestData[0] == 3) && (TestMode_RequestData[1] == 0) && (TestMode_RequestData[2] == 0)
				&& (TestMode_RequestData[3] == 0) && (TestMode_RequestData[4] == 0) && (TestMode_RequestData[5] == 0)
					&& (TestMode_RequestData[6] == 0) && (TestMode_RequestData[7] == 0) && (TestMode_DebugInfoEnable == 0))
		{
			if(Fv_AngleReadyFlag == HELLA_STS_Decode)
			{
				databuf[0] = 0x80;
				databuf[1] = 0x00;
				databuf[2] = 0x00;
				databuf[3] = 0x00;
				databuf[4] = 0x00;
				databuf[5] = 0x00;
				databuf[6] = 0x00;
				databuf[7] = 0x03;

				StrAngZeroStored();

				//ASW_COM_TestModeResponseSend(databuf);
				PutMsg_ECUTESTMODE(databuf);
			}
			TestMode_DebugInfoEnable = 1;
		}
		else if((TestMode_RequestData[0] == 5) && (TestMode_RequestData[1] == 0) && (TestMode_RequestData[2] == 0)
				&& (TestMode_RequestData[3] == 0) && (TestMode_RequestData[4] == 0) && (TestMode_RequestData[5] == 0)
					&& (TestMode_RequestData[6] == 0) && (TestMode_RequestData[7] == 0) && (TestMode_DebugInfoEnable == 1))
		{
			databuf[0] = 0x80;
			databuf[1] = 0x00;
			databuf[2] = 0x00;
			databuf[3] = 0x00;
			databuf[4] = 0x00;
			databuf[5] = 0x00;
			databuf[6] = 0x00;
			databuf[7] = 0x05;

			StrAngZeroRemoved();

			//ASW_COM_TestModeResponseSend(databuf);
			PutMsg_ECUTESTMODE(databuf);
			TestMode_DebugInfoEnable = 0;
		}
		else if((TestMode_RequestData[0] == 0x03) && (TestMode_RequestData[1] == 0x19) && (TestMode_RequestData[2] == 0x02)
				&& (TestMode_RequestData[3] == 0x01) && (TestMode_RequestData[4] == 0) && (TestMode_RequestData[5] == 0)
					&& (TestMode_RequestData[6] == 0) && (TestMode_RequestData[7] == 0))
		{
			databuf[0] = fsDtcTestfailed[0];
			databuf[1] = fsDtcTestfailed[1];
			databuf[2] = fsDtcTestfailed[2];
			databuf[3] = fsDtcTestfailed[3];
			databuf[4] = fsDtcTestfailed[4];
			databuf[5] = fsDtcTestfailed[5];
			databuf[6] = fsDtcTestfailed[6];
			databuf[7] = fsDtcTestfailed[7];
			PutMsg_ECUTESTMODE(databuf);
		}
		else if((TestMode_RequestData[0] == 0x03) && (TestMode_RequestData[1] == 0x19) && (TestMode_RequestData[2] == 0x02)
				&& (TestMode_RequestData[3] == 0x80) && (TestMode_RequestData[4] == 0) && (TestMode_RequestData[5] == 0)
					&& (TestMode_RequestData[6] == 0) && (TestMode_RequestData[7] == 0))
		{
			databuf[0] = Eeprom_DTCStatus[0];
			databuf[1] = Eeprom_DTCStatus[1];
			databuf[2] = Eeprom_DTCStatus[2];
			databuf[3] = Eeprom_DTCStatus[3];
			databuf[4] = Eeprom_DTCStatus[4];
			databuf[5] = Eeprom_DTCStatus[5];
			databuf[6] = Eeprom_DTCStatus[6];
			databuf[7] = Eeprom_DTCStatus[7];
			PutMsg_ECUTESTMODE(databuf);
		}
		else if((TestMode_RequestData[0] == 0x04) && (TestMode_RequestData[1] == 0x14) && (TestMode_RequestData[2] == 0xff)
				&& (TestMode_RequestData[3] == 0xff) && (TestMode_RequestData[4] == 0xff) && (TestMode_RequestData[5] == 0)
					&& (TestMode_RequestData[6] == 0) && (TestMode_RequestData[7] == 0))
		{
			for(i = 0; i < 16; i ++)
			{
				Eeprom_DTCStatus[i] = 0;
			}
			databuf[0] = Eeprom_DTCStatus[0];
			databuf[1] = Eeprom_DTCStatus[1];
			databuf[2] = Eeprom_DTCStatus[2];
			databuf[3] = Eeprom_DTCStatus[3];
			databuf[4] = Eeprom_DTCStatus[4];
			databuf[5] = Eeprom_DTCStatus[5];
			databuf[6] = Eeprom_DTCStatus[6];
			databuf[7] = Eeprom_DTCStatus[7];
			PutMsg_ECUTESTMODE(databuf);
		}
		else
		{

		}
	}
	else
	{
	}
}
/****************************************************************
* FUNCTION : TESTmodeFun
* DESCRIPTION : Test mode schedule function
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void TESTmodeFun(void)
{
	uint8 databuf[8] = {0,};
	static UInt8 reset_delay = 0;
	static uint16 loopcount = 0;
	static uint8 reverseflag = 0;

	TM_PowerOnTimesRecordProcess();
	TM_TestMode_AngProcess();
	if(Fv_TESTmodeFun_GlbFlag)
	{
		 //fs_testmode_rc = (0x0701); //mod by liuyang for HW test
		 fs_testmode_rc = ((MDLINT16U) IlGetRxTestModeRequest1());
		 fs_testmode_rc |= ((MDLINT16U) IlGetRxTestModeRequest0()) << 8;
		
/* 閿熺潾闈╂嫹SENT --220819--YBL */

		fsETimerCapInfo[Hella_AP].duty = IOC_AngpDuty;
		fsETimerCapInfo[Hella_AS].duty = IOC_AngsDuty;
		fsETimerCapInfo[Hella_AP].frez = IOC_AngpFrez;
		fsETimerCapInfo[Hella_AS].frez = IOC_AngsFrez;
		fsETimerCapInfo[Hella_T1].duty = IOC_Tor1Duty;
		fsETimerCapInfo[Hella_T2].duty = IOC_Tor2Duty;
		fsETimerCapInfo[Hella_T1].frez = IOC_Tor1Frez;
		fsETimerCapInfo[Hella_T2].frez = IOC_Tor2Frez;

		switch(fs_testmode_rc)
		{
			case 	TM_COMMUCATION_CHECK_CMD:
					TM_CommunicationCheckProcess();
					break;
			
			case 	TM_SELF_CHENK_CMD:
					TM_SelfCheckProcess();
					break;
			
			case 	TM_PSL_EE_9V:
					TM_PSL_EE_9VCheckProcess();
					break;
			
			case 	TM_PSL_EE_18V:
					TM_PSL_EE_18VCheckProcess();
					break;
			
			case 	TM_MAIN_RELAY_CMD:
					TM_MainRelayCloseProcess();
					break;
			
			case 	TM_PREDRIVER_CMD:
					TM_PreDriverRelayOpenProcess();
					break;
			
			case 	TM_NORMAL_VOLTAGE_TORQUE_CMD:
					TM_NormalVolTorqueProcess();
					break;
			
			case 	TM_LOW_VOLTAGE_TORQUE_CMD:
					TM_LowVolTorqueProcess();
					break;
			
			case 	TM_HIGH_VOLTAGE_TORQUE_CMD:
					TM_HighVolTorqueProcess();
					break;
			
			case    TM_MTR_CALMID_CMD:
					TM_OpenLoopCalMidProcess();
					break;
			case    TM_MTR_CALAMP1_CMD:
					TM_OpenLoopCalAmp1Process();
					break;
			case    TM_MTR_CALAMP2_CMD:
					TM_OpenLoopCalAmp2Process();
					break;
			case    TM_MTR_WRITEVAL_CMD:
					TM_OpenLoopWriteCalProcess();
					break;
			case 	TM_MTR_OPENLOOP_RUN_CMD:
					TM_OpenLoopRUNProcess();
					break;
			case 	TM_RESOLVER_TEMPERATURE_CMD:
					TM_ResolverTemperatureProcess();
					break;
			case 	TM_RESOLVER_INITANGLE_CMD:
					TM_ResolverInitAngleProcess();
					break;
			case 	TM_MTR_CLOSELOOP_NrmPos_CMD:
					TM_CloseLoopNormalPosProcess();
					break;
			
			case 	TM_MTR_CLOSELOOP_NrmNeg_CMD:
					TM_CloseLoopNormalNegProcess();
					break;
			
			case 	TM_MTR_CLOSELOOP_LowPos_CMD:
					TM_CloseLoopLowPosProcess();
					break;
			
			case 	TM_MTR_CLOSELOOP_HghNeg_CMD:
					TM_CloseLoopHighNegProcess();
					break;
			case 	TM_MTR_CLOSELOOP_SPEED_CMD:
					TM_CloseLoopRevUDProcess();
					break;		
			
			case 	TM_POWER_LATCH_CMD:
					TM_PowerLatchProcess();
					break;
			
			case    TM_PRODUCT_INFORMATION_WAIT_CMD:
					TM_ProductInfoProcess();
					break;
			
			case    TM_FCT_INPUTOUTPUT_A_CMD:
					TM_FCTInputOutputAvailctrl();
					break;
			case    TM_FCT_INPUTOUTPUT_N_CMD:
					TM_FCTInputOutputNavailctrl();
					break;
			/* 閿熻緝浼欐嫹閿熷�熷閿熸枻鎷烽敓绛嬧�旈敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹2022.03.02 By YBL */
			case    TM_AGING_TEST_CHECK_CMD:
					TM_AGING_TEST_CHECK_Func();
					break;
			case    TM_CALIB_DATA_CHECK_CMD:
					TM_CALIB_DATA_CHECK_Func();
					break;
					
			default:
			
					if(fs_testmode_rc == TM_TEST_VOLTAGE_TORQUE_CMD)
					{
						fsTESTmodeFun_TrqTransEnabled = TRUE;
					}
					else if((IlGetRxTestModeRequest0() == 1) && (IlGetRxTestModeRequest1() == 2)
							&& (IlGetRxTestModeRequest2() == 3) && (IlGetRxTestModeRequest3() == 4)
							&& (IlGetRxTestModeRequest4() == 5) && (IlGetRxTestModeRequest5() == 6)
							&& (IlGetRxTestModeRequest6() == 7) && (IlGetRxTestModeRequest7() == 8))
					{

						if(reset_delay == 0)
						{
							reset_delay = 1;
							fsTestSpeedAim = 0;
							reverseflag = 0;
							loopcount = 0;
							SysTaskFocResetPending = TRUE;
							SysTaskFocResetPending1 = TRUE;
							SysTaskFocResetPending2 = TRUE;
							SysTaskFocResetTrgPending1 = TRUE;
							SysTaskFocResetTrgPending2 = TRUE;
						}
						else
						{
							SysTaskFocResetPending = FALSE;
							SysTaskFocResetPending1 = FALSE;
							SysTaskFocResetPending2 = FALSE;
							SysTaskFocResetTrgPending1 = FALSE;
							SysTaskFocResetTrgPending2 = FALSE;
						}

						Fv_TESTmode_CrlReqFlag = TESTMODE_SpeedLoopFlag;
						if(loopcount < 25)
						{
							fsTestSpeedAim = 120;
						}
						else if(loopcount < 35)
						{
							fsTestSpeedAim = 0;
						}
						else
						{
							fsTestSpeedAim = -120;
						}
						if(reverseflag > 0)
						{
							if(loopcount > 0)
							{
								loopcount --;
							}
							else
							{
								loopcount = 0;
								reverseflag = 0;
							}
						}
						else
						{
							if(loopcount < 60)
							{
								loopcount ++;
							}
							else
							{
								loopcount = 60;
								reverseflag = 1;
							}
						}

						databuf[0] = 1;
						databuf[1] = 2;
						databuf[2] = 3;
						databuf[3] = 4;
						databuf[4] = 5;
						databuf[5] = 6;
						databuf[6] = 7;
						databuf[7] = 8;
						PutMsg_ECUTESTMODE(databuf);
					}
					else if((IlGetRxTestModeRequest0() == 8) && (IlGetRxTestModeRequest1() == 7)
							&& (IlGetRxTestModeRequest2() == 6) && (IlGetRxTestModeRequest3() == 5)
							&& (IlGetRxTestModeRequest4() == 4) && (IlGetRxTestModeRequest5() == 3)
							&& (IlGetRxTestModeRequest6() == 2) && (IlGetRxTestModeRequest7() == 1))
					{
						reset_delay = 0;
						Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
						fsOpenloopUQ=0;
						fsOpenloopUD=0;
						fsOpenloopS1=0;//20
						fsOpenloopS2=0;//1,spd=s1/s2
						fsOpenloopSa=0;
						databuf[0] = 8;
						databuf[1] = 7;
						databuf[2] = 6;
						databuf[3] = 5;
						databuf[4] = 4;
						databuf[5] = 3;
						databuf[6] = 2;
						databuf[7] = 1;
						PutMsg_ECUTESTMODE(databuf);
					}
					else if((IlGetRxTestModeRequest0() == 0x5A) && (IlGetRxTestModeRequest1() == 0xA5)
							&& (IlGetRxTestModeRequest2() == 0x3C) && (IlGetRxTestModeRequest3() == 0xC3)
							&& (IlGetRxTestModeRequest4() == 0) && (IlGetRxTestModeRequest5() == 0)
							&& (IlGetRxTestModeRequest6() == 0))
					{
						if(reset_delay == 0)
						{
							reset_delay = 1;
							fsTestSpeedAim = 0;
							SysTaskFocResetPending = TRUE;
							SysTaskFocResetPending1 = TRUE;
							SysTaskFocResetPending2 = TRUE;
							SysTaskFocResetTrgPending1 = TRUE;
							SysTaskFocResetTrgPending2 = TRUE;
						}
						else
						{
							SysTaskFocResetPending = FALSE;
							SysTaskFocResetPending1 = FALSE;
							SysTaskFocResetPending2 = FALSE;
							SysTaskFocResetTrgPending1 = FALSE;
							SysTaskFocResetTrgPending2 = FALSE;
						}

						Fv_TESTmode_CrlReqFlag = TESTMODE_SpeedLoopFlag;
						/*閿熸枻鎷烽敓鏂ゆ嫹閿熺粸纭锋嫹璋村ú顫嫹閿熸枻鎷锋枑锝忔嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熺粸褝鎷烽敓锟�--TXY--20231123*/
						if(Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] > FailureDiag_RegOK)
						{
							fsTestSpeedAim = 0;
						}
						else
						{
							if(IlGetRxTestModeRequest7() == 0x80)
							{
								fsTestSpeedAim = -8000;
							}
							else if(IlGetRxTestModeRequest7() == 0x81)
							{
								fsTestSpeedAim = -12000;
							}
							else if(IlGetRxTestModeRequest7() == 0x82)
							{
								fsTestSpeedAim = -16000;
							}
							else if(IlGetRxTestModeRequest7() == 0x2)
							{
								fsTestSpeedAim = 16000;
							}
							else if(IlGetRxTestModeRequest7() == 0x1)
							{
								fsTestSpeedAim = 12000;
							}
							else if(IlGetRxTestModeRequest7() == 0x0)
							{
								fsTestSpeedAim = 8000;
							}
							else
							{
								fsTestSpeedAim = 0;
							}
						}

						databuf[0] = 0x5A;
						databuf[1] = 0xA5;
						databuf[2] = 0x3C;
						databuf[3] = 0xC3;
						databuf[4] = 0;
						databuf[5] = 0;
						databuf[6] = 0;
						databuf[7] = 0;
						PutMsg_ECUTESTMODE(databuf);
					}
					else
					{
						fsTESTmodeFun_TrqTransEnabled = FALSE;
					}
			break; 
		}
	}
	else
	{
	}
}
/****************************************************************
* FUNCTION : TM_CommunicationCheckProcess
* DESCRIPTION : CAN communication detection
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_CommunicationCheckProcess(void)
{
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		MDLINT8U datamid[12] = {0,};
		static MDLINT8U i = 0;
		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
//		BridgePrechargeFun(FALSE);
//		PredriverViceCtrlFun(FALSE);
		SysTaskPhaseDiagStepIndex = InitDiagStep_Default;

#if 0
		if(glbProductInfo[0] == 0xFFFFFFFFul && glbProductInfo[1] == 0xFFFFFFFFul && glbProductInfo[2] == 0xFFFFFFFFul)
		{
			datamid[0] = 0x60;
			datamid[1] = 0x00;
			datamid[2] = 0x01;
			datamid[3] = 0x00;
			datamid[4] = 0x11;
			datamid[5] = 0x34;
			datamid[6] = 0x25;
			datamid[7] = 0x01;
			datamid[8] = 0x00;
			datamid[9] = 0x21;
			datamid[10] = 0xAA;
			datamid[11] = 0xBB;					
		}
		else
		{
			datamid[0] = (MDLINT8U)(glbProductInfo[0] >> 24);
			datamid[1] = (MDLINT8U)(glbProductInfo[0] >> 16);
			datamid[2] = (MDLINT8U)(glbProductInfo[0] >> 8);
			datamid[3] = (MDLINT8U)(glbProductInfo[0]);
			datamid[4] = (MDLINT8U)(glbProductInfo[1] >> 24);
			datamid[5] = (MDLINT8U)(glbProductInfo[1] >> 16);
			datamid[6] = (MDLINT8U)(glbProductInfo[1] >> 8);
			datamid[7] = (MDLINT8U)(glbProductInfo[1]);
			datamid[8] = (MDLINT8U)(glbProductInfo[2] >> 24);
			datamid[9] = (MDLINT8U)(glbProductInfo[2] >> 16);
			datamid[10] = (MDLINT8U)(glbProductInfo[2] >> 8);
			datamid[11] = (MDLINT8U)(glbProductInfo[2]);	
		}
#else
		if(((*((uint32 *)TESTMODE_PRODUCTINFO)) == 0x000000000ul)
				&& (((*(((uint32 *)TESTMODE_PRODUCTINFO) + 1)) == 0x000000000ul))
					&& (((*(((uint32 *)TESTMODE_PRODUCTINFO) + 2)) == 0x000000000ul)))
//		if(glbProductInfo[0] == 0xFFFFFFFFul && glbProductInfo[1] == 0xFFFFFFFFul && glbProductInfo[2] == 0xFFFFFFFFul)
		{
			datamid[0] = 0x60;
			datamid[1] = 0x00;
			datamid[2] = 0x00;
			datamid[3] = 0x00;
			datamid[4] = 0x00;
			datamid[5] = 0x34;
			datamid[6] = 0x25;
			datamid[7] = 0x01;
			datamid[8] = 0x00;
			datamid[9] = 0x21;
			datamid[10] = 0xAA;
			datamid[11] = 0xBB;
		}
		else
		{
			datamid[0] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 3));
			datamid[1] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 2));
			datamid[2] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 1));
			datamid[3] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 0));
			datamid[4] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 7));
			datamid[5] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 6));
			datamid[6] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 5));
			datamid[7] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 4));
			datamid[8] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 11));
			datamid[9] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 10));
			datamid[10] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 9));
			datamid[11] = (MDLINT8U)(*(((uint8 *)TESTMODE_PRODUCTINFO) + 8));
		}
#endif
		
		if(i == 0)
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
			databuf[2] = LIST_GeelyProductExtNum[0];
			databuf[3] = LIST_GeelyProductExtNum[1];
			databuf[4] = LIST_GeelyProductExtNum[2];
			databuf[5] = LIST_GeelyProductExtNum[3];
			databuf[6] = (MDLINT8U)((datamid[4]&0x0F)|LIST_GeelyProductExtNum[4]);
			databuf[7] = datamid[5];
			PutMsg_ECUTESTMODE(databuf);
			i =1;
		}
		else 
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
			databuf[2] = datamid[6];
			databuf[3] = datamid[7];
			databuf[4] = datamid[8];
			databuf[5] = datamid[9];
			databuf[6] = LIST_GeelyProductExtNum[10];
			databuf[7] = LIST_GeelyProductExtNum[11];

			PutMsg_ECUTESTMODE(databuf);
			i = 0;
		}
		

}
/****************************************************************
* FUNCTION : TM_SelfCheckProcess
* DESCRIPTION : System self-check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_SelfCheckProcess(void)
{
		MDLINT32U vicemcuerr = 0;
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		MDLINT8U mcufault_state = 0;
		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
		EnableTorqueSensorPowerSupply();
//		SetTrqPwrSpl(1);
//		SetTrqPwrRef(1);
//		SetRtrTrmSpl(1);

		mcufault_state |= (MDLINT8U)((Fv_FaultClass_MCU & 0x0001u) << 1);
		mcufault_state |= (MDLINT8U)((Fv_FaultClass_MCU & 0x0002u) << 1);
		mcufault_state |= (MDLINT8U)((Fv_FaultClass_MCU & 0x0004u) << 1);
		mcufault_state |= (MDLINT8U)((Fv_FaultClass_MCU & 0x0008u) << 1);
		mcufault_state |= (MDLINT8U)((Fv_FaultClass_MCU & 0x0010u) << 1);
		mcufault_state |= (MDLINT8U)((!fsTESTmode_ResetFlag) << 6);

		vicemcuerr = Fv_ErrorFromGn32;

		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = mcufault_state;
		databuf[3] = (MDLINT8U)(vicemcuerr >> 24);
		databuf[4] = (MDLINT8U)(vicemcuerr >> 16);
		databuf[5] = (MDLINT8U)(vicemcuerr >> 8);
		databuf[6] = (MDLINT8U)(vicemcuerr);
		databuf[7] = (MDLINT8U)(((MDLINT8U)((fsSPI_Communication_Status == SPI_StateNormal) << 4))|(fsPowerOnTimesRecord & 0x0F));
		PutMsg_ECUTESTMODE(databuf);			
}
/****************************************************************
* FUNCTION : TM_PSL_EE_9VCheckProcess
* DESCRIPTION : power supply & eeprom check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_PSL_EE_9VCheckProcess(void)
{
		MDLINT16S tm_igkeyvol = 0;
		MDLINT16S tm_syspower = 0;
		MDLINT16U tm_inervcc = 0;
		MDLINT16U tm_vicepower = 0;
		MDLINT16U tm_viceigkey = 0;
		MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		MDLINT8U returnCode = 0;
		MDLINT8U ee_check_write[8] = {0x55,0x55,0x55,0x55,0x55,0x55};
		MDLINT8U ee_check_read[8] = {0xAA,0xAA,0xAA,0xAA,0xAA,0xAA};
		uint8 j = 0;
		static MDLINT8U i = 0;
		static MDLINT8U eeflag = 0;
		fsTESTmode_ResetFlag = FALSE;
		
		if(eeflag == 0)
		{
//			fsEEPROM_StoreState[TestMode].enabled = TRUE;
//			fsEEPROM_StoreState[TestMode].queued = FALSE;
			
			ee_check_write[4] = (MDLINT8U)(Fv_PowerOnTimesFriction >> 8);
			
			ee_check_write[5] = (MDLINT8U)(Fv_PowerOnTimesFriction);
						
			Eeprom_WriteTestMode(ee_check_write);

			for(j = 0; j < 8; j++)
			{
				ee_check_read[j] = Eeprom_TestMode[j];
			}
			
			if((ee_check_write[0] != ee_check_read[0]) || (ee_check_write[1] != ee_check_read[1]) ||
			   (ee_check_write[2] != ee_check_read[2]) || (ee_check_write[3] != ee_check_read[3]))
			{
//				fsEEPROM_StoreState[TestMode].failure = TRUE;

				
			}
//			fsEEPROM_StoreState[TestMode].enabled = FALSE;
			eeflag = 1;	
		}
		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
		tm_igkeyvol = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) AD_IgnitionSys) * ((MDLINT32U) MACRO_AV_IGNITION_SCALE))
    				 	 >> 9)) + MACRO_AV_IGNITION_OFFSET);

    	tm_syspower = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) AD_PowerSys) * ((MDLINT32U) MACRO_AV_POWER_SCALE))
    					 >> 9)) + MACRO_AV_POWER_OFFSET);
 
    	tm_inervcc = (MDLINT16U) ((AD_InterVolt1d2 * MACRO_AV_AD2VOL) >> 6);
	
//    	tm_vicepower = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) fsDataFromGn32[TRSM_BAT]) * ((MDLINT32U) MACRO_AV_POWER_SCALE))
 //   					 >> 9)) + MACRO_AV_POWER_OFFSET);
    	
 //   	tm_viceigkey = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) fsDataFromGn32[TRSM_IGKEY]) * ((MDLINT32U) MACRO_AV_IGNITION_SCALE))
 //   				 	 >> 9)) + MACRO_AV_IGNITION_OFFSET);

		
		datamid[0] = tm_igkeyvol;
		datamid[1] = tm_syspower;
		datamid[2] = tm_inervcc;
		datamid[3] = tm_vicepower;
		datamid[4] = tm_viceigkey;		

		
		if(i == 0)
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
			databuf[2] = (MDLINT8U)(datamid[0] >> 8);
			databuf[3] = (MDLINT8U)(datamid[0]);
			databuf[4] = (MDLINT8U)(datamid[1] >> 8);
			databuf[5] = (MDLINT8U)(datamid[1]);
//			databuf[6] = (MDLINT8U)fsEEPROM_StoreState[TestMode].failure;
	
			PutMsg_ECUTESTMODE(databuf);
			i = 1;
		}
		
		else
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
			databuf[2] = (MDLINT8U)(datamid[2] >> 8);
			databuf[3] = (MDLINT8U)(datamid[2]);
			databuf[4] = (MDLINT8U)(datamid[3] >> 8);
			databuf[5] = (MDLINT8U)(datamid[3]);
			databuf[6] = (MDLINT8U)(datamid[4] >> 8);
			databuf[7] = (MDLINT8U)(datamid[4] );
			
			PutMsg_ECUTESTMODE(databuf);
			i =0;
		}
				
}
/****************************************************************
* FUNCTION : TM_PSL_EE_18VCheckProcess
* DESCRIPTION : power supply & eeprom check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_PSL_EE_18VCheckProcess(void)
{
		MDLINT16S tm_igkeyvol = 0;
		MDLINT16S tm_syspower = 0;
		MDLINT16U tm_inervcc = 0;
		MDLINT16U tm_vicepower = 0;
		MDLINT16U tm_viceigkey = 0;
		MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		MDLINT8U returnCode = 0;
		MDLINT8U ee_check_write[8] = {0x55,0x55,0x55,0x55,0x55,0x55};
		MDLINT8U ee_check_read[8] = {0xAA,0xAA,0xAA,0xAA,0xAA,0xAA};
		uint8 j = 0;
		static MDLINT8U i = 0;
		static MDLINT8U eeflag = 0;
		
		fsTESTmode_ResetFlag = FALSE;
		if(eeflag == 0)
		{
//			fsEEPROM_StoreState[TestMode].enabled = TRUE;
//			fsEEPROM_StoreState[TestMode].queued = FALSE;
			
			ee_check_write[4] = (MDLINT8U)(Fv_PowerOnTimesFriction >> 8);
			
			ee_check_write[5] = (MDLINT8U)(Fv_PowerOnTimesFriction);
						
			Eeprom_WriteTestMode(ee_check_write);

			for(j = 0; j < 8; j++)
			{
				ee_check_read[j] = Eeprom_TestMode[j];
			}
			
			if((ee_check_write[0] != ee_check_read[0]) || (ee_check_write[1] != ee_check_read[1]) ||
			   (ee_check_write[2] != ee_check_read[2]) || (ee_check_write[3] != ee_check_read[3]))
			{
//				fsEEPROM_StoreState[TestMode].failure = TRUE;

				
			}
//			fsEEPROM_StoreState[TestMode].enabled = FALSE;
			eeflag = 1;	
		}
		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
		tm_igkeyvol = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) AD_IgnitionSys) * ((MDLINT32U) MACRO_AV_IGNITION_SCALE))
    				 	 >> 9)) + MACRO_AV_IGNITION_OFFSET);

    	tm_syspower = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) AD_PowerSys) * ((MDLINT32U) MACRO_AV_POWER_SCALE))
    					 >> 9)) + MACRO_AV_POWER_OFFSET);
 
    	tm_inervcc = (MDLINT16U) ((AD_InterVolt1d2 * MACRO_AV_AD2VOL) >> 6);
	
//    	tm_vicepower = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) fsDataFromGn32[TRSM_BAT]) * ((MDLINT32U) MACRO_AV_POWER_SCALE))
//    					 >> 9)) + MACRO_AV_POWER_OFFSET);
    	
//    	tm_viceigkey = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) fsDataFromGn32[TRSM_IGKEY]) * ((MDLINT32U) MACRO_AV_IGNITION_SCALE))
//    				 	 >> 9)) + MACRO_AV_IGNITION_OFFSET);

		
		datamid[0] = tm_igkeyvol;
		datamid[1] = tm_syspower;
		datamid[2] = tm_inervcc;
		datamid[3] = tm_vicepower;
		datamid[4] = tm_viceigkey;		

		
		if(i == 0)
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1() + 1);
			databuf[2] = (MDLINT8U)(datamid[0] >> 8);
			databuf[3] = (MDLINT8U)(datamid[0]);
			databuf[4] = (MDLINT8U)(datamid[1] >> 8);
			databuf[5] = (MDLINT8U)(datamid[1]);
//			databuf[6] = (MDLINT8U)fsEEPROM_StoreState[TestMode].failure;
	
			PutMsg_ECUTESTMODE(databuf);
			i = 1;
		}
		
		else
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1() + 2);
			databuf[2] = (MDLINT8U)(datamid[2] >> 8);
			databuf[3] = (MDLINT8U)(datamid[2]);
			databuf[4] = (MDLINT8U)(datamid[3] >> 8);
			databuf[5] = (MDLINT8U)(datamid[3]);
			databuf[6] = (MDLINT8U)(datamid[4] >> 8);
			databuf[7] = (MDLINT8U)(datamid[4] );
			
			PutMsg_ECUTESTMODE(databuf);
			i =0;
		}
				
}
/****************************************************************
* FUNCTION : TM_MainRelayCloseProcess
* DESCRIPTION : Main relay check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_MainRelayCloseProcess(void)
{
		MDLINT16S tm_syspower = 0;
		MDLINT16S tm_rlypower = 0;
		MDLINT16U tm_predrive = 0;
		MDLINT16U datamid[2] = {0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		
		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		fsTESTmode_ResetFlag = FALSE;
		tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
		tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));

        tm_syspower = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) AD_PowerSys) * ((MDLINT32U) MACRO_AV_POWER_SCALE))
    					 >> 9)) + MACRO_AV_POWER_OFFSET);
     	tm_rlypower = (MDLINT16S) ((((MDLINT32U) AD_PowerRelaySys) * ((MDLINT32U)MACRO_AV_POWERRELAY_SCALE)) >> 9);

  
		datamid[0] = tm_syspower;
		datamid[1] = tm_rlypower;
		
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)(datamid[1] >> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);
		PutMsg_ECUTESTMODE(databuf);
 }
/****************************************************************
* FUNCTION : TM_PreDriverRelayOpenProcess
* DESCRIPTION : Predriver check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_PreDriverRelayOpenProcess(void)
{
		MDLINT16S tm_syspower = 0;
		MDLINT16S tm_rlypower = 0;
		MDLINT16U tm_predrive = 0;
		MDLINT16U datamid[2] = {0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		static MDLINT8U i = 0;

		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
		fsTESTmode_ResetFlag = FALSE;
    	if(i < 1)
		{
			OpenRelay();
    		i++;
		}
    	else
		{

	    	if(i <= 2)
	    	{
	    		i++;
				SysTaskFocResetPending = TRUE;
				SysTaskFocResetPending1 = TRUE;
				SysTaskFocResetPending2 = TRUE;
				SysTaskFocResetTrgPending1 = TRUE;
				SysTaskFocResetTrgPending2 = TRUE;
		}
	    	else
		{
	    		SysTaskFocResetPending = FALSE;
				SysTaskFocResetPending1 = FALSE;
				SysTaskFocResetPending2 = FALSE;
				SysTaskFocResetTrgPending1 = FALSE;
				SysTaskFocResetTrgPending2 = FALSE;
	    		OpenPhase();
	    		OpenPredrive();
	    	}

		}

    	SysTaskCurrentSmpPending1 = TRUE;
		SysTaskCurrentSmpPending2 = TRUE;
        SysTaskResolverSmpPending = TRUE;
#if T212L_TESTMODE
#else
		SIU.GPDO[PIN_RTRLY_V_ENH_MPB1].R 	= HIGH; 
		SIU.GPDO[PIN_TS_POWER_ENH_MPD6].R 	= HIGH;
#endif
		
		tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
		tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));

		
  		tm_syspower = (MDLINT16S) (((MDLINT16S) ((((MDLINT32U) AD_PowerSys) * ((MDLINT32U) MACRO_AV_POWER_SCALE))
    					 >> 9)) + MACRO_AV_POWER_OFFSET);
    	tm_rlypower = (MDLINT16S) ((((MDLINT32U) AD_PowerRelaySys) * ((MDLINT32U)MACRO_AV_POWERRELAY_SCALE)) >> 9);

  
		datamid[0] = tm_syspower;
		datamid[1] = tm_syspower;
	  
		
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
 		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
 		databuf[3] = (MDLINT8U)(datamid[0]);
 		databuf[4] = (MDLINT8U)(datamid[1] >> 8);
 		databuf[5] = (MDLINT8U)(datamid[1]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);
	
		PutMsg_ECUTESTMODE(databuf);	
}
/****************************************************************
* FUNCTION : TM_NormalVolTorqueProcess
* DESCRIPTION : Normal Voltage Torque check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_NormalVolTorqueProcess(void)
{
		MDLINT16U tm_trqpower = 0;
		MDLINT16U rc = 0;
		MDLINT16U datamid[6] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		static MDLINT8U i = 0;


		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;

	    tm_trqpower = (MDLINT16U) ((((MDLINT32U) AD_TorqueSenPower) * ((MDLINT32U)MACRO_AV_TRQPOWER_SCALE)) >> 9);
		
		datamid[0] = tm_trqpower;

		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AP].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AP].frez/10))) << 8;//0~1000	
		datamid[1] = rc;;		
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T1].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T1].frez/10))) << 8;//0~2000			
		datamid[2] = rc;;
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T2].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T2].frez/10))) << 8;//0~2000		
		datamid[3] = rc;;
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AS].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AS].frez/10))) << 8;//0~200	

		datamid[4] = rc;
		datamid[5] = (MDLINT16S) ((((MDLINT32U) AD_PowerRelaySys) * ((MDLINT32U)MACRO_AV_POWERRELAY_SCALE)) >> 9);

		if(i == 0)
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
			databuf[2] = (MDLINT8U)(datamid[0] >> 8);
			databuf[3] = (MDLINT8U)(datamid[0]);
			databuf[4] = (MDLINT8U)(datamid[1] >> 8);
			databuf[5] = (MDLINT8U)(datamid[1]);
			databuf[6] = (MDLINT8U)(datamid[2] >> 8);
			databuf[7] = (MDLINT8U)(datamid[2]);
			PutMsg_ECUTESTMODE(databuf);
			i = 1;
		}
		else 
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
			databuf[2] = (MDLINT8U)(datamid[3] >> 8);
			databuf[3] = (MDLINT8U)(datamid[3]);
			databuf[4] = (MDLINT8U)(datamid[4] >> 8);
			databuf[5] = (MDLINT8U)(datamid[4]);
			databuf[6] = (MDLINT8U)(datamid[5] >> 8);
			databuf[7] = (MDLINT8U)(datamid[5]);
			PutMsg_ECUTESTMODE(databuf);
			i = 0;
		}
}
/****************************************************************
* FUNCTION : TM_LowVolTorqueProcess
* DESCRIPTION : Low Voltage Torque check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_LowVolTorqueProcess(void)
{
		MDLINT16U tm_trqpower = 0;
		MDLINT16U rc = 0;
		MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		static MDLINT8U i = 0;

		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
	    tm_trqpower = (MDLINT16U) ((((MDLINT32U) AD_TorqueSenPower) * ((MDLINT32U)MACRO_AV_TRQPOWER_SCALE)) >> 9);
		
		datamid[0] = tm_trqpower;

		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AP].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AP].frez/10))) << 8;//0~1000	
		datamid[1] = rc;		
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T1].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T1].frez/10))) << 8;//0~2000			
		datamid[2] = rc;
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T2].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T2].frez/10))) << 8;//0~2000		
		datamid[3] = rc;
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AS].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AS].frez/10))) << 8;//0~200	
		datamid[4] = rc;
		
		if(i == 0)
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
			databuf[2] = (MDLINT8U)(datamid[0] >> 8);
			databuf[3] = (MDLINT8U)(datamid[0]);
			databuf[4] = (MDLINT8U)(datamid[1] >> 8);
			databuf[5] = (MDLINT8U)(datamid[1]);
			databuf[6] = (MDLINT8U)(datamid[2] >> 8);
			databuf[7] = (MDLINT8U)(datamid[2]);
			PutMsg_ECUTESTMODE(databuf);
			i = 1;
		}
		else 
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);
			databuf[2] = (MDLINT8U)(datamid[3] >> 8);
			databuf[3] = (MDLINT8U)(datamid[3]);
			databuf[4] = (MDLINT8U)(datamid[4] >> 8);
			databuf[5] = (MDLINT8U)(datamid[4]);
			databuf[6] = 0xFF;
			databuf[7] = 0xFF;
			PutMsg_ECUTESTMODE(databuf);
			i = 0;
		}		
}
/****************************************************************
* FUNCTION : TM_HighVolTorqueProcess
* DESCRIPTION : High Voltage Torque check
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_HighVolTorqueProcess(void)
{
		MDLINT16U tm_trqpower = 0;
		MDLINT16U rc = 0;
		MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		static MDLINT8U i = 0;

		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
	    tm_trqpower = (MDLINT16U) ((((MDLINT32U) AD_TorqueSenPower) * ((MDLINT32U)MACRO_AV_TRQPOWER_SCALE)) >> 9);
		
		datamid[0] = tm_trqpower;
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AP].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AP].frez/10))) << 8;//0~1000	
		datamid[1] = rc;		
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T1].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T1].frez/10))) << 8;//0~2000			
		datamid[2] = rc;//Fv_MainTorqueADVol;
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T2].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_T2].frez/10))) << 8;//0~2000		
		datamid[3] = rc;//Fv_SubTorqueADVol;
		
		rc = ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AS].duty/100)));//0~10000
		rc |= ((MDLINT16U) ((MDLINT8U)(fsETimerCapInfo[Hella_AS].frez/10))) << 8;//0~200	
		datamid[4] = rc;//Fv_MainAdTorqueADVol;
		
		if(i == 0)
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);
			databuf[2] = (MDLINT8U)(datamid[0] >> 8);
			databuf[3] = (MDLINT8U)(datamid[0]);
			databuf[4] = (MDLINT8U)(datamid[1] >> 8);
			databuf[5] = (MDLINT8U)(datamid[1]);
			databuf[6] = (MDLINT8U)(datamid[2] >> 8);
			databuf[7] = (MDLINT8U)(datamid[2]);
			PutMsg_ECUTESTMODE(databuf);
			i = 1;
		}
		else 
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
			databuf[2] = (MDLINT8U)(datamid[3] >> 8);
			databuf[3] = (MDLINT8U)(datamid[3]);
			databuf[4] = (MDLINT8U)(datamid[4] >> 8);
			databuf[5] = (MDLINT8U)(datamid[4]);
			databuf[6] = 0xFF;
			databuf[7] = 0xFF;
			PutMsg_ECUTESTMODE(databuf);
			i = 0;
		}		
}
/****************************************************************
* FUNCTION : TM_OpenLoopCalMidProcess
* DESCRIPTION : Calebration middle point of current
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_OpenLoopCalMidProcess(void)
{
	MDLINT16U datamid[6] = {0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	MDLINT8U ee_crc = 0;
	MDLINT16U ee_calarray[CALI_PARA_NUM] 	 = {0xFFFFu,0xFFFFu,0xFFFFu,0xFFFFu,0xFFFFu,0xFFFFu,0xFFFFu,0xFFFFu,};
	uint16 ee_temp[CALI_PARA_NUM] = {0};
	uint8 j = 0;
	static MDLINT8U i = 0;
	static uint8 cnt = 0;
	static uint8 fail = 0;
	static uint32 usum[PreDriver_Num] = {0,0};
	static uint32 vsum[PreDriver_Num] = {0,0};
	static uint32 wsum[PreDriver_Num] = {0,0};
	
	Fv_TESTmode_CrlReqFlag = TESTMODE_OpenLoopFlag;
	//Cal Middle point
	fsOpenloopUQ=0;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2
	fsOpenloopSa=0;//2048->3pi/6,6144->9pi/6
	
	if(cnt < 24)
	{
		datamid[0] = AD_MotorCurrentU[PreDriver_01];
		datamid[1] = AD_MotorCurrentV[PreDriver_01];
		datamid[2] = AD_MotorCurrentW[PreDriver_01];
		datamid[3] = AD_MotorCurrentU[PreDriver_02];
		datamid[4] = AD_MotorCurrentV[PreDriver_02];
		datamid[5] = AD_MotorCurrentW[PreDriver_02];
		usum[PreDriver_01] = 0;
		vsum[PreDriver_01] = 0;
		wsum[PreDriver_01] = 0;
		usum[PreDriver_02] = 0;
		vsum[PreDriver_02] = 0;
		wsum[PreDriver_02] = 0;
		fail = 0;
		cnt ++;
	}
	else if(cnt < 88)
	{
		datamid[0] = AD_MotorCurrentU[PreDriver_01];
		datamid[1] = AD_MotorCurrentV[PreDriver_01];
		datamid[2] = AD_MotorCurrentW[PreDriver_01];
		datamid[3] = AD_MotorCurrentU[PreDriver_02];
		datamid[4] = AD_MotorCurrentV[PreDriver_02];
		datamid[5] = AD_MotorCurrentW[PreDriver_02];
		usum[PreDriver_01] += AD_MotorCurrentU[PreDriver_01];
		vsum[PreDriver_01] += AD_MotorCurrentV[PreDriver_01];
		wsum[PreDriver_01] += AD_MotorCurrentW[PreDriver_01];
		usum[PreDriver_02] += AD_MotorCurrentU[PreDriver_02];
		vsum[PreDriver_02] += AD_MotorCurrentV[PreDriver_02];
		wsum[PreDriver_02] += AD_MotorCurrentW[PreDriver_02];
		fail = 0;
		cnt ++;
	}
	else if(cnt == 88)
	{
		datamid[0] = (uint16)(usum[PreDriver_01] >> 6);
		datamid[1] = (uint16)(vsum[PreDriver_01] >> 6);
		datamid[2] = (uint16)(wsum[PreDriver_01] >> 6);
		datamid[3] = (uint16)(usum[PreDriver_02] >> 6);
		datamid[4] = (uint16)(vsum[PreDriver_02] >> 6);
		datamid[5] = (uint16)(wsum[PreDriver_02] >> 6);
		fail = 0;
		fsCalibrationData.data.gainoffset.i[0] = (UInt16)(usum[PreDriver_01] >> 6);
		fsCalibrationData.data.gainoffset.i[1] = (UInt16)(vsum[PreDriver_01] >> 6);
		fsCalibrationData.data.gainoffset.i[2] = (UInt16)(wsum[PreDriver_01] >> 6);
		fsCalibrationData.data.gainoffset.i[3] = (UInt16)(usum[PreDriver_02] >> 6);
		fsCalibrationData.data.gainoffset.i[4] = (UInt16)(vsum[PreDriver_02] >> 6);
		fsCalibrationData.data.gainoffset.i[5] = (UInt16)(wsum[PreDriver_02] >> 6);
		ee_calarray[0] = fsCalibrationData.data.gainoffset.i[0];
		ee_calarray[1] = fsCalibrationData.data.gainoffset.i[1];
		ee_calarray[2] = fsCalibrationData.data.gainoffset.i[2];
		ee_calarray[3] = fsCalibrationData.data.gainoffset.i[3];
		ee_calarray[4] = fsCalibrationData.data.gainoffset.i[4];
		ee_calarray[5] = fsCalibrationData.data.gainoffset.i[5];
//		ee_calarray[6] = EEPROM_INIT_RSVGAIN;
//		ee_calarray[7] = EEPROM_INIT_RSVGAIN;
//		ee_calarray[8] = EEPROM_INIT_GOINDX4;
//		ee_calarray[9] = EEPROM_INIT_GOINDX5;
//		ee_calarray[10] = EEPROM_INIT_GOINDX6;
//		ee_calarray[11] = EEPROM_INIT_GOINDX7;

		ee_crc = CRC8forSAEJ1850((MDLINT8U*)ee_calarray,(MDLINT8U)(CALI_PARA_NUM*2 - 1));
		ee_calarray[11] = (((uint16)ee_crc << 8) | (ee_calarray[11] & 0xFF));

		Eeprom_WriteCalibGainOffset((MDLINT8U*)ee_calarray);
//		Eeprom_WriteCalibGainOffsetMrr((MDLINT8U*)ee_calarray);

		for(j = 0; j < CALI_PARA_NUM; j ++)
		{
			if(Eeprom_CalibGainOffset.halfword[j] != ee_calarray[j])
			{
				fail = 1;
				break;
			}
		}
		if(fail == 0)
		{
			for(j = 0; j < CALI_PARA_NUM; j ++)
			{
				if(Eeprom_CalibGainOffsetMrr.halfword[j] != ee_calarray[j])
				{
					fail = 1;
					break;
				}
			}
		}
		cnt ++;
	}
	else
	{
		datamid[0] = (uint16)(usum[PreDriver_01] >> 6);
		datamid[1] = (uint16)(vsum[PreDriver_01] >> 6);
		datamid[2] = (uint16)(wsum[PreDriver_01] >> 6);
		datamid[3] = (uint16)(usum[PreDriver_02] >> 6);
		datamid[4] = (uint16)(vsum[PreDriver_02] >> 6);
		datamid[5] = (uint16)(wsum[PreDriver_02] >> 6);
	}
	
	if(i == 0)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)( datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
		databuf[6] = (MDLINT8U)( datamid[2]>> 8);
		databuf[7] = (MDLINT8U)(datamid[2]);
		PutMsg_ECUTESTMODE(databuf);
		i = 1;
	}
	else if(i == 1)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1() + 1);
		databuf[2] = (MDLINT8U)(datamid[3] >> 8);
		databuf[3] = (MDLINT8U)(datamid[3]);
		databuf[4] = (MDLINT8U)( datamid[4]>> 8);
		databuf[5] = (MDLINT8U)(datamid[4]);
		databuf[6] = (MDLINT8U)( datamid[5]>> 8);
		databuf[7] = (MDLINT8U)(datamid[5]);
		PutMsg_ECUTESTMODE(databuf);
		i = 2;
	}
	else
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1() + 2);
		databuf[2] = fail;
		databuf[3] = fail;
		databuf[4] = 0;
		databuf[5] = 0;
		databuf[6] = 0;
		databuf[7] = 0;
		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}
}
/****************************************************************
* FUNCTION : TM_OpenLoopCalAmp1Process
* DESCRIPTION : Calebration Amp1 of current
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_OpenLoopCalAmp1Process(void)
{
	MDLINT16U datamid[3] = {0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
//	static MDLINT8U i = 0;
	Fv_TESTmode_CrlReqFlag = TESTMODE_OpenLoopFlag;
	//Cal Middle point
	fsOpenloopUQ=1280;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2
	fsOpenloopSa=2048;//2048->3pi/6,6144->9pi/6
	
	datamid[0] = AD_MotorCurrentU[PreDriver_01];
	datamid[1] = AD_MotorCurrentV[PreDriver_01];
	datamid[2] = AD_MotorCurrentW[PreDriver_01];
	
	databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
	databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
	databuf[2] = (MDLINT8U)(datamid[0] >> 8);
	databuf[3] = (MDLINT8U)(datamid[0]);
	databuf[4] = (MDLINT8U)( datamid[1]>> 8);
	databuf[5] = (MDLINT8U)(datamid[1]);
	databuf[6] = (MDLINT8U)( datamid[2]>> 8);
	databuf[7] = (MDLINT8U)(datamid[2]);
	PutMsg_ECUTESTMODE(databuf);
}
/****************************************************************
* FUNCTION : TM_OpenLoopCalAmp2Process
* DESCRIPTION : Calebration Amp1 of current
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_OpenLoopCalAmp2Process(void)
{
	MDLINT16U datamid[3] = {0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
//	static MDLINT8U i = 0;
	Fv_TESTmode_CrlReqFlag = TESTMODE_OpenLoopFlag;
	//Cal Middle point
	fsOpenloopUQ=1280;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2
	fsOpenloopSa=6144;//2048->3pi/6,6144->9pi/6
	
	datamid[0] = AD_MotorCurrentU[PreDriver_01];
	datamid[1] = AD_MotorCurrentV[PreDriver_01];
	datamid[2] = AD_MotorCurrentW[PreDriver_01];
	
	databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
	databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
	databuf[2] = (MDLINT8U)(datamid[0] >> 8);
	databuf[3] = (MDLINT8U)(datamid[0]);
	databuf[4] = (MDLINT8U)( datamid[1]>> 8);
	databuf[5] = (MDLINT8U)(datamid[1]);
	databuf[6] = (MDLINT8U)( datamid[2]>> 8);
	databuf[7] = (MDLINT8U)(datamid[2]);
	PutMsg_ECUTESTMODE(databuf);
}
/****************************************************************
* FUNCTION : TM_OpenLoopWriteCalProcess
* DESCRIPTION : Write to eeprom
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_OpenLoopWriteCalProcess(void)
{
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
	//Cal Middle point
	fsOpenloopUQ=0;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2
	fsOpenloopSa=0;//2048->3pi/6,6144->9pi/6
	
	if(fsGblCALWriteFlag == 1)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = 0xAA;
		databuf[3] = 0xAA;
		databuf[4] = 0xBB;
		databuf[5] = 0xBB;
		databuf[6] = 0xCC;
		databuf[7] = 0xCC;
		PutMsg_ECUTESTMODE(databuf);
	}
	else
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = 0x11;
		databuf[3] = 0x11;
		databuf[4] = 0x22;
		databuf[5] = 0x22;
		databuf[6] = 0x33;
		databuf[7] = 0x33;
		PutMsg_ECUTESTMODE(databuf);	
	}
}
/****************************************************************
* FUNCTION : TM_OpenLoopRUNProcess
* DESCRIPTION : Open Loop process
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_OpenLoopRUNProcess(void)
{
	MDLINT16U tm_predrive = 0;
	MDLINT16S tm_phasevol_u = 0;
	MDLINT16S tm_phasevol_v = 0;
	MDLINT16S tm_phasevol_w = 0;
	MDLINT16U tm_i2d5vol = 0;
	MDLINT16U datamid[4] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	static MDLINT8U i = 0;
	static uint16 cnt = 0;
	
	Fv_TESTmode_CrlReqFlag = TESTMODE_OpenLoopFlag;
	//Cal Middle point
	fsOpenloopUQ= 896;
	fsOpenloopUD=0;
	fsOpenloopS1=6;//20
	fsOpenloopS2=2;//1,spd=s1/s2
	fsOpenloopSa=0;//2048->3pi/6,6144->9pi/6
	
	SysTaskFocResetPending = FALSE;
	SysTaskFocResetPending1 = FALSE;
	SysTaskFocResetPending2 = FALSE;
	SysTaskFocResetTrgPending1 = FALSE;
	SysTaskFocResetTrgPending2 = FALSE;
	OpenPhase();
	OpenPredrive();
//	GET_PREDRIVER_PWMDUTY();
	
	
	tm_phasevol_u = (Int16)(((Int32)(MotorCtrl_FocPar[PreDriver_01].PwmU) * (Int32)Fv_SysPowerRelay)/4000);
	tm_phasevol_v = (Int16)(((Int32)(MotorCtrl_FocPar[PreDriver_01].PwmV) * (Int32)Fv_SysPowerRelay)/4000);
	tm_phasevol_w = (Int16)(((Int32)(MotorCtrl_FocPar[PreDriver_01].PwmW) * (Int32)Fv_SysPowerRelay)/4000);            		
	
//    tm_i2d5vol = (MDLINT16U) ((AD_RotorMainMid * MACRO_AV_AD2VOL) >> 6);
	tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
	tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));
	datamid[0] = tm_phasevol_u;
	datamid[1] = tm_phasevol_v;
	datamid[2] = tm_phasevol_w;
	datamid[3] = tm_i2d5vol;
	
	if(cnt <  10)
	{
		AD_RotorSinOffsetMax[PreDriver_01] = 0;
		AD_RotorSinOffsetMin[PreDriver_01] = 0;
		AD_RotorCosOffsetMax[PreDriver_01] = 0;
		AD_RotorCosOffsetMin[PreDriver_01] = 0;
		AD_RotorSinOffsetMax[PreDriver_02] = 0;
		AD_RotorSinOffsetMin[PreDriver_02] = 0;
		AD_RotorCosOffsetMax[PreDriver_02] = 0;
		AD_RotorCosOffsetMin[PreDriver_02] = 0;
		cnt ++;
	}
	else if(cnt < 360)
	{
		AD_RotorPhasePlusMax[PreDriver_01] = 0;
		AD_RotorPhasePlusMin[PreDriver_01] = 0;
		AD_RotorPhaseMinusMax[PreDriver_01] = 0;
		AD_RotorPhaseMinusMin[PreDriver_01] = 0;
		AD_RotorPhasePlusMax[PreDriver_02] = 0;
		AD_RotorPhasePlusMin[PreDriver_02] = 0;
		AD_RotorPhaseMinusMax[PreDriver_02] = 0;
		AD_RotorPhaseMinusMin[PreDriver_02] = 0;
		cnt ++;
	}
	else
	{

	}

	if(i == 0)
	{
	
		MDLINT16S local_IU = 0;
		MDLINT16S local_IV = 0;
		MDLINT16S local_IW = 0;
		
#if T212L_TESTMODE
		local_IU = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentU[PreDriver_01] - fsCalibrationData.data.gainoffset.i[0])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;//3
	    local_IV = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentV[PreDriver_01] - fsCalibrationData.data.gainoffset.i[1])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;
	    local_IW = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentW[PreDriver_01] - fsCalibrationData.data.gainoffset.i[2])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;
#else
		local_IU = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentU[PreDriver_01]<<1) - fsCalibrationData.data.gainoffset.i[0])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;//3
	    local_IV = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentV[PreDriver_01]<<1) - fsCalibrationData.data.gainoffset.i[1])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;
	    local_IW = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentW[PreDriver_01]<<1) - fsCalibrationData.data.gainoffset.i[2])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;
#endif
	    databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = (MDLINT8U)(((MDLINT16U)local_IU) >> 8);
		databuf[3] = (MDLINT8U)(((MDLINT16U)local_IU));
		databuf[4] = (MDLINT8U)(((MDLINT16U)local_IV) >> 8);
		databuf[5] = (MDLINT8U)(((MDLINT16U)local_IV));
		databuf[6] = (MDLINT8U)(((MDLINT16U)local_IW) >> 8);
		databuf[7] = (MDLINT8U)(((MDLINT16U)local_IW));
		PutMsg_ECUTESTMODE(databuf);
		i =1;
	}
	else if(i == 1)
	{
		MDLINT16S local_shadowIU = 0;
		MDLINT16S local_shadowIV = 0;
		MDLINT16S local_shadowIW = 0;

		local_shadowIU = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentU[PreDriver_02]<<1) - fsCalibrationData.data.gainoffset.i[3])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;//3
		local_shadowIV = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentV[PreDriver_02]<<1) - fsCalibrationData.data.gainoffset.i[4])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;//TODO
		local_shadowIW = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentW[PreDriver_02]<<1) - fsCalibrationData.data.gainoffset.i[5])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;
	
	
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
		databuf[2] = (MDLINT8U)(((MDLINT16U)local_shadowIU) >> 8);
		databuf[3] = (MDLINT8U)(((MDLINT16U)local_shadowIU));
		databuf[4] = (MDLINT8U)(((MDLINT16U)local_shadowIV) >> 8);
		databuf[5] = (MDLINT8U)(((MDLINT16U)local_shadowIV));
		databuf[6] = (MDLINT8U)(((MDLINT16U)local_shadowIW) >> 8);
		databuf[7] = (MDLINT8U)(((MDLINT16U)local_shadowIW));
		PutMsg_ECUTESTMODE(databuf);
		i = 2;
	}
	else if(i == 2)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)( datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
		databuf[6] = (MDLINT8U)( datamid[2]>> 8);
		databuf[7] = (MDLINT8U)(datamid[2]);
		PutMsg_ECUTESTMODE(databuf);
		i = 3;
	}
	else if(i == 3)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
//		databuf[2] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[3] = (MDLINT8U)(tm_predrive);
		databuf[4] = (MDLINT8U)(datamid[3] >> 8);
		databuf[5] = (MDLINT8U)(datamid[3]);

		PutMsg_ECUTESTMODE(databuf);
		i = 4;
	}
	else if(i == 4)
	{

		MDLINT16S local_IU = 0;
		MDLINT16S local_IV = 0;
		MDLINT16S local_IW = 0;
		
#if T212L_TESTMODE
		local_IU = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentU[PreDriver_02] - fsCalibrationData.data.gainoffset.i[3])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;//3
	    local_IV = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentV[PreDriver_02] - fsCalibrationData.data.gainoffset.i[4])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;
	    local_IW = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentW[PreDriver_02] - fsCalibrationData.data.gainoffset.i[5])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;
#else
		local_IU = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentU[PreDriver_01]<<1) - fsCalibrationData.data.gainoffset.i[0])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;//3
	    local_IV = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentV[PreDriver_01]<<1) - fsCalibrationData.data.gainoffset.i[1])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;
	    local_IW = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentW[PreDriver_01]<<1) - fsCalibrationData.data.gainoffset.i[2])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;
#endif


		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+4);//8
		databuf[2] = (MDLINT8U)(((MDLINT16U)local_IU) >> 8);
		databuf[3] = (MDLINT8U)(((MDLINT16U)local_IU));
		databuf[4] = (MDLINT8U)(((MDLINT16U)local_IV) >> 8);
		databuf[5] = (MDLINT8U)(((MDLINT16U)local_IV));
		databuf[6] = (MDLINT8U)(((MDLINT16U)local_IW) >> 8);
		databuf[7] = (MDLINT8U)(((MDLINT16U)local_IW));

		PutMsg_ECUTESTMODE(databuf);
		i = 5;
	}
	else if(i == 5)
	{

		MDLINT16S local_shadowIU = 0;
		MDLINT16S local_shadowIV = 0;
		MDLINT16S local_shadowIW = 0;
			
		local_shadowIU = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentU[PreDriver_02]<<1) - fsCalibrationData.data.gainoffset.i[3])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;//3
		local_shadowIV = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentV[PreDriver_02]<<1) - fsCalibrationData.data.gainoffset.i[4])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;
		local_shadowIW = (MDLINT16S)((((MDLINT32S) ((AD_MotorCurrentW[PreDriver_02]<<1) - fsCalibrationData.data.gainoffset.i[5])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 4) ;

		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+5);//9
		databuf[2] = (MDLINT8U)(((MDLINT16U)local_shadowIU) >> 8);
		databuf[3] = (MDLINT8U)(((MDLINT16U)local_shadowIU));
		databuf[4] = (MDLINT8U)(((MDLINT16U)local_shadowIV) >> 8);
		databuf[5] = (MDLINT8U)(((MDLINT16U)local_shadowIV));
		databuf[6] = (MDLINT8U)(((MDLINT16U)local_shadowIW) >> 8);
		databuf[7] = (MDLINT8U)(((MDLINT16U)local_shadowIW));
		PutMsg_ECUTESTMODE(databuf);
		i = 6;
	}
	else if(i == 6)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+6);//A
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)( datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
		databuf[6] = (MDLINT8U)( datamid[2]>> 8);
		databuf[7] = (MDLINT8U)(datamid[2]);
		PutMsg_ECUTESTMODE(databuf);
		i = 7;
	}
	else if(i == 7)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+7);//B
//		databuf[2] = (MDLINT8U)(((MDLINT8U)((TB9083_ErrorFlag*2) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[3] = (MDLINT8U)(tm_predrive);
		databuf[4] = (MDLINT8U)(datamid[3] >> 8);
		databuf[5] = (MDLINT8U)(datamid[3]);

		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}
		
}

/****************************************************************
* FUNCTION : TM_ResolverTemperatureProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_ResolverTemperatureProcess(void)
{
	MDLINT16U tm_predrive = 0;
	MDLINT16U tm_rsv_sin = 0;
	MDLINT16U tm_rsv_cos = 0;
	MDLINT16U tm_rsv_sinv = 0;
	MDLINT16U tm_rsv_cosv = 0;
	MDLINT16U tm_rsv_mid = 0;
	MDLINT16U datamid[11] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT16U datafrequency = 0;
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	MDLINT16U tm_tempvol = 0;
	MDLINT16S tm_tempcel = 0;

	static MDLINT8U i = 0;
    static const MAP_Tab1DS0I2T2081_a lookup_temp_map = {
      36 /* Nx:  */, 
      (const MDLINT16U *) &(Cal_AV_TempScale_X[0]) /* x_table: vector with axis values */, 
      (const MDLINT16S *) &(Cal_AV_TempScale_Y[0]) /* z_table: vector with table values */
   };
   tm_tempvol = (UInt16) ((((UInt32) AD_TempSys) * ((UInt32) MACRO_AV_AD2VOL)) >> 6);
   tm_tempcel = Tab1DS0I2T2081_a(&lookup_temp_map, tm_tempvol);	
	
	Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
	fsOpenloopUQ=0;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2
	fsOpenloopSa=0;
	

	
   tm_rsv_sin = (MDLINT16U) ((AD_RotorMainSin1 * 66/10) >> 6);
   tm_rsv_cos = (MDLINT16U) ((AD_RotorMainCos1 * 66/10) >> 6);
   tm_rsv_mid = (MDLINT16U) ((AD_RotorMainMid1 * 66/10) >> 6);
   tm_rsv_sinv = (MDLINT16U) ((AD_RotorSubSin1 * 66/10) >> 6);
   tm_rsv_cosv = (MDLINT16U) ((AD_RotorSubCos1 * 66/10) >> 6);

	tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
	tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));   

	datamid[0] = tm_rsv_sin;
	datamid[1] = tm_rsv_cos;
	datamid[2] = tm_rsv_mid;
	datamid[3] = tm_rsv_sinv;
	datamid[4] = tm_rsv_cosv;
	datamid[5] = (Int16) (((UInt16) ((((UInt32) AD_PowerSys) * ((UInt32) MACRO_AV_POWER_SCALE))
		    >> 9)) + MACRO_AV_POWER_OFFSET);
	/*(UInt16) ((((UInt32) AD_RotorSenPower) * ((UInt32)MACRO_AV_RSVPOWER_SCALE)) >> 9);*/
	
	datamid[6] = (Int16)((((Int32) Fv_dRotorAng) * ((Int32) MACRO_RAD2RPM) ) >> 14);
	datamid[7] = (UInt16)tm_tempcel;
	datamid[8] = (UInt16)(tm_rsv_sin + tm_rsv_sinv);
	datamid[9] = (UInt16)(tm_rsv_cos + tm_rsv_cosv);
	datamid[10] = (UInt16)(((((Int32)(tm_rsv_sin - tm_rsv_sinv)) * ((Int32)(tm_rsv_sin - tm_rsv_sinv))) +
	             (((Int32)(tm_rsv_cos - tm_rsv_cosv)) * ((Int32)(tm_rsv_cos - tm_rsv_cosv)))) >> 7);
	
	if(i == 0)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)( datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
		databuf[6] = (MDLINT8U)( datamid[2]>> 8);
		databuf[7] = (MDLINT8U)(datamid[2]);
		PutMsg_ECUTESTMODE(databuf);
		i =1;
	}
	else if(i == 1)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
		databuf[2] = (MDLINT8U)(datamid[3] >> 8);
		databuf[3] = (MDLINT8U)(datamid[3]);
		databuf[4] = (MDLINT8U)(datamid[4] >> 8);
		databuf[5] = (MDLINT8U)(datamid[4]);
		databuf[6] = (MDLINT8U)(datamid[5] >> 8);//// inspring frz
		databuf[7] = (MDLINT8U)(datamid[5]);////
		PutMsg_ECUTESTMODE(databuf);
		i = 2;
	}
	else// if(i == 2)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);
		databuf[2] = (MDLINT8U)(datamid[6] >> 8);
		databuf[3] = (MDLINT8U)(datamid[6]);
		databuf[4] = (MDLINT8U)( datamid[7]>> 8);
		databuf[5] = (MDLINT8U)(datamid[7]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);

		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}
#if 0
	else
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
		databuf[2] = (MDLINT8U)(datamid[8] >> 8);
		databuf[3] = (MDLINT8U)(datamid[8]);
		databuf[4] = (MDLINT8U)(datamid[9] >> 8);
		databuf[5] = (MDLINT8U)(datamid[9]);
		databuf[6] = (MDLINT8U)(datamid[10] >> 8);//// inspring frz
		databuf[7] = (MDLINT8U)(datamid[10]);////
		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}
#endif
}
/****************************************************************
* FUNCTION : TM_ResolverTemperatureProcess
* DESCRIPTION :
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_ResolverInitAngleProcess(void)
{
	MDLINT16U datamid[18] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	uint8 ee_Initangle[48] = {0};
	static MDLINT8U i = 0;
	static uint16 initanglecnt = 0;
	static sint32 initangle[PreDriver_Num] = {0};
	static Int16 lstrotorangle[PreDriver_Num] = {0};



	Fv_TESTmode_CrlReqFlag = TESTMODE_OpenLoopFlag;
	fsOpenloopUQ = 896;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2


	if(initanglecnt < 100)
	{
		initanglecnt ++;
		fsOpenloopSa=4096;//2048->3pi/6,6144->9pi/6
		initangle[PreDriver_01] = 0;
		initangle[PreDriver_02] = 0;
		MotorCtrl_FocPar[PreDriver_01].initangle = 0;
		MotorCtrl_FocPar[PreDriver_02].initangle = 0;
	}
	else if(initanglecnt < 240)
	{
		initanglecnt ++;
		fsOpenloopSa=6144;//2048->3pi/6,6144->9pi/6
		initangle[PreDriver_01] = 0;
		initangle[PreDriver_02] = 0;
		MotorCtrl_FocPar[PreDriver_01].initangle = 0;
		MotorCtrl_FocPar[PreDriver_02].initangle = 0;
		lstrotorangle[PreDriver_01] = MotorCtrl_FocPar[PreDriver_01].angle;
		lstrotorangle[PreDriver_02] = MotorCtrl_FocPar[PreDriver_02].angle;
	}
	else if(initanglecnt < 304)
	{
		initanglecnt ++;
		fsOpenloopSa=6144;//2048->3pi/6,6144->9pi/6
		if((MotorCtrl_FocPar[PreDriver_01].angle<0)&&(lstrotorangle[PreDriver_01] > MACRO_MBC_PI_2))
		{
			initangle[PreDriver_01] += (((Int32)MotorCtrl_FocPar[PreDriver_01].angle) + MACRO_MBC_2PI);
		}
		else if((MotorCtrl_FocPar[PreDriver_01].angle>0)&&(lstrotorangle[PreDriver_01] < -((Int16)MACRO_MBC_PI_2)))
		{
			initangle[PreDriver_01] += (((Int32)MotorCtrl_FocPar[PreDriver_01].angle) - MACRO_MBC_2PI);
		}
		else
		{
			initangle[PreDriver_01] += MotorCtrl_FocPar[PreDriver_01].angle;
		}

		if((MotorCtrl_FocPar[PreDriver_02].angle<0)&&(lstrotorangle[PreDriver_02] > MACRO_MBC_PI_2))
		{
			initangle[PreDriver_02] += (((Int32)MotorCtrl_FocPar[PreDriver_02].angle) + MACRO_MBC_2PI);
		}
		else if((MotorCtrl_FocPar[PreDriver_02].angle>0)&&(lstrotorangle[PreDriver_02] < -((Int16)MACRO_MBC_PI_2)))
		{
			initangle[PreDriver_02] += (((Int32)MotorCtrl_FocPar[PreDriver_02].angle) - MACRO_MBC_2PI);
		}
		else
		{
			initangle[PreDriver_02] += MotorCtrl_FocPar[PreDriver_02].angle;
		}
		MotorCtrl_FocPar[PreDriver_01].initangle = MACRO_MBC_PI - MotorCtrl_FocPar[PreDriver_01].angle;
		MotorCtrl_FocPar[PreDriver_02].initangle = MACRO_MBC_PI - MotorCtrl_FocPar[PreDriver_02].angle;
	}
	else if(initanglecnt == 304)
	{
		MotorCtrl_FocPar[PreDriver_01].initangle = MACRO_MBC_PI - (initangle[PreDriver_01] >> 6);
		MotorCtrl_FocPar[PreDriver_02].initangle = MACRO_MBC_PI - (initangle[PreDriver_02] >> 6);
		MotorCtrl_FocPar[PreDriver_01].initanglecrr = 0;
		MotorCtrl_FocPar[PreDriver_02].initanglecrr = 0;
		ee_Initangle[1] = (uint8)((AD_RotorSinOffsetMax[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[0] = (uint8)(AD_RotorSinOffsetMax[PreDriver_01] & 0x00FF);
		ee_Initangle[3] = (uint8)((AD_RotorSinOffsetMin[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[2] = (uint8)(AD_RotorSinOffsetMin[PreDriver_01] & 0x00FF);
		ee_Initangle[5] = (uint8)((AD_RotorCosOffsetMax[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[4] = (uint8)(AD_RotorCosOffsetMax[PreDriver_01] & 0x00FF);
		ee_Initangle[7] = (uint8)((AD_RotorCosOffsetMin[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[6] = (uint8)(AD_RotorCosOffsetMin[PreDriver_01] & 0x00FF);
		
		ee_Initangle[9] = (uint8)((AD_RotorSinOffsetMax[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[8] = (uint8)(AD_RotorSinOffsetMax[PreDriver_02] & 0x00FF);
		ee_Initangle[11] = (uint8)((AD_RotorSinOffsetMin[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[10] = (uint8)(AD_RotorSinOffsetMin[PreDriver_02] & 0x00FF);
		ee_Initangle[13] = (uint8)((AD_RotorCosOffsetMax[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[12] = (uint8)(AD_RotorCosOffsetMax[PreDriver_02] & 0x00FF);
		ee_Initangle[15] = (uint8)((AD_RotorCosOffsetMin[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[14] = (uint8)(AD_RotorCosOffsetMin[PreDriver_02] & 0x00FF);
		
		ee_Initangle[17] = (uint8)((AD_RotorPhasePlusMax[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[16] = (uint8)(AD_RotorPhasePlusMax[PreDriver_01] & 0x00FF);
		ee_Initangle[19] = (uint8)((AD_RotorPhasePlusMin[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[18] = (uint8)(AD_RotorPhasePlusMin[PreDriver_01] & 0x00FF);
		ee_Initangle[21] = (uint8)((AD_RotorPhaseMinusMax[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[20] = (uint8)(AD_RotorPhaseMinusMax[PreDriver_01] & 0x00FF);
		ee_Initangle[23] = (uint8)((AD_RotorPhaseMinusMin[PreDriver_01] & 0xFF00) >> 8);
		ee_Initangle[22] = (uint8)(AD_RotorPhaseMinusMin[PreDriver_01] & 0x00FF);

		ee_Initangle[25] = (uint8)((AD_RotorPhasePlusMax[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[24] = (uint8)(AD_RotorPhasePlusMax[PreDriver_02] & 0x00FF);
		ee_Initangle[27] = (uint8)((AD_RotorPhasePlusMin[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[26] = (uint8)(AD_RotorPhasePlusMin[PreDriver_02] & 0x00FF);
		ee_Initangle[29] = (uint8)((AD_RotorPhaseMinusMax[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[28] = (uint8)(AD_RotorPhaseMinusMax[PreDriver_02] & 0x00FF);
		ee_Initangle[31] = (uint8)((AD_RotorPhaseMinusMin[PreDriver_02] & 0xFF00) >> 8);
		ee_Initangle[30] = (uint8)(AD_RotorPhaseMinusMin[PreDriver_02] & 0x00FF);
		
		ee_Initangle[35] = (uint8)((MotorCtrl_FocPar[PreDriver_01].initangle & 0xFF000000) >> 24);
		ee_Initangle[34] = (uint8)((MotorCtrl_FocPar[PreDriver_01].initangle & 0x00FF0000) >> 16);
		ee_Initangle[33] = (uint8)((MotorCtrl_FocPar[PreDriver_01].initangle & 0x0000FF00) >> 8);
		ee_Initangle[32] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initangle & 0x000000FF);

		ee_Initangle[39] = (uint8)((MotorCtrl_FocPar[PreDriver_02].initangle & 0xFF000000) >> 24);
		ee_Initangle[38] = (uint8)((MotorCtrl_FocPar[PreDriver_02].initangle & 0x00FF0000) >> 16);
		ee_Initangle[37] = (uint8)((MotorCtrl_FocPar[PreDriver_02].initangle & 0x0000FF00) >> 8);
		ee_Initangle[36] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initangle & 0x000000FF);
		Eeprom_WriteMotorResolver(ee_Initangle);
		Eeprom_WriteMotorPhase(&ee_Initangle[16]);
		Eeprom_WriteMotorAngle(&ee_Initangle[32]);
		fsOpenloopUQ = 0;
		initanglecnt ++;
		fsOpenloopSa=6144;//2048->3pi/6,6144->9pi/6
	}
	else
	{
		fsOpenloopUQ = 0;
		SysTaskFocResetTrgPending1 = TRUE;
		SysTaskFocResetTrgPending2 = TRUE;
		SysTaskFocResetPending = TRUE;
		SysTaskFocResetPending1 = TRUE;
		SysTaskFocResetPending2 = TRUE;
		fsOpenloopSa=6144;//2048->3pi/6,6144->9pi/6
	}

	datamid[0] = AD_RotorSinOffsetMax[PreDriver_01];
	datamid[1] = AD_RotorSinOffsetMin[PreDriver_01];
	datamid[2] = AD_RotorCosOffsetMax[PreDriver_01];
	datamid[3] = AD_RotorCosOffsetMin[PreDriver_01];
	datamid[4] = AD_RotorPhasePlusMax[PreDriver_01];
	datamid[5] = AD_RotorPhasePlusMin[PreDriver_01];

	datamid[6] = AD_RotorPhaseMinusMax[PreDriver_01];
	datamid[7] = AD_RotorPhaseMinusMin[PreDriver_01];
	datamid[8] = (sint16)MotorCtrl_FocPar[PreDriver_01].initangle;

	datamid[9] = AD_RotorSinOffsetMax[PreDriver_02];
	datamid[10] = AD_RotorSinOffsetMin[PreDriver_02];
	datamid[11] = AD_RotorCosOffsetMax[PreDriver_02];
	datamid[12] = AD_RotorCosOffsetMin[PreDriver_02];
	datamid[13] = AD_RotorPhasePlusMax[PreDriver_02];
	datamid[14] = AD_RotorPhasePlusMin[PreDriver_02];

	datamid[15] = AD_RotorPhaseMinusMax[PreDriver_02];
	datamid[16] = AD_RotorPhaseMinusMin[PreDriver_02];
	datamid[17] = (sint16)MotorCtrl_FocPar[PreDriver_02].initangle;

	if(i == 0)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1() + 2);
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)( datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
		databuf[6] = (MDLINT8U)( datamid[2]>> 8);
		databuf[7] = (MDLINT8U)(datamid[2]);
		PutMsg_ECUTESTMODE(databuf);
		i =1;
	}
	else if(i == 1)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
		databuf[2] = (MDLINT8U)(datamid[3] >> 8);
		databuf[3] = (MDLINT8U)(datamid[3]);
		databuf[4] = (MDLINT8U)(datamid[4] >> 8);
		databuf[5] = (MDLINT8U)(datamid[4]);
		databuf[6] = (MDLINT8U)(datamid[5] >> 8);//// inspring frz
		databuf[7] = (MDLINT8U)(datamid[5]);////
		PutMsg_ECUTESTMODE(databuf);
		i = 2;
	}
	else if(i == 2)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+4);
		databuf[2] = (MDLINT8U)(datamid[6] >> 8);
		databuf[3] = (MDLINT8U)(datamid[6]);
		databuf[4] = (MDLINT8U)( datamid[7]>> 8);
		databuf[5] = (MDLINT8U)(datamid[7]);
		databuf[6] = (MDLINT8U)(datamid[8] >> 8);
		databuf[7] = (MDLINT8U)(datamid[8]);

		PutMsg_ECUTESTMODE(databuf);
		i = 3;
	}
	else if(i == 3)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1() + 5);
		databuf[2] = (MDLINT8U)(datamid[9] >> 8);
		databuf[3] = (MDLINT8U)(datamid[9]);
		databuf[4] = (MDLINT8U)( datamid[10]>> 8);
		databuf[5] = (MDLINT8U)(datamid[10]);
		databuf[6] = (MDLINT8U)( datamid[11]>> 8);
		databuf[7] = (MDLINT8U)(datamid[11]);
		PutMsg_ECUTESTMODE(databuf);
		i =4;
	}
	else if(i == 4)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+6);
		databuf[2] = (MDLINT8U)(datamid[12] >> 8);
		databuf[3] = (MDLINT8U)(datamid[12]);
		databuf[4] = (MDLINT8U)(datamid[13] >> 8);
		databuf[5] = (MDLINT8U)(datamid[13]);
		databuf[6] = (MDLINT8U)(datamid[14] >> 8);//// inspring frz
		databuf[7] = (MDLINT8U)(datamid[14]);////
		PutMsg_ECUTESTMODE(databuf);
		i = 5;
	}
	else
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+7);
		databuf[2] = (MDLINT8U)(datamid[15] >> 8);
		databuf[3] = (MDLINT8U)(datamid[15]);
		databuf[4] = (MDLINT8U)( datamid[16]>> 8);
		databuf[5] = (MDLINT8U)(datamid[16]);
		databuf[6] = (MDLINT8U)(datamid[17] >> 8);
		databuf[7] = (MDLINT8U)(datamid[17]);

		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}
}
/****************************************************************
* FUNCTION : TM_CloseLoopNormalPosProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_CloseLoopNormalPosProcess(void)
{

    MDLINT16U tm_predrive = 0;
	MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	static MDLINT8U i = 0;
	static UInt8 reset_delay = 0;
	if(reset_delay == 0)
	{
		reset_delay = 1;
		SysTaskFocResetPending = TRUE;
		SysTaskFocResetPending1 = TRUE;
		SysTaskFocResetPending2 = TRUE;
		SysTaskFocResetTrgPending1 = TRUE;
		SysTaskFocResetTrgPending2 = TRUE;
	}
	else
	{
		SysTaskFocResetPending = FALSE;
		SysTaskFocResetPending1 = FALSE;
		SysTaskFocResetPending2 = FALSE;
		SysTaskFocResetTrgPending1 = FALSE;
		SysTaskFocResetTrgPending2 = FALSE;
	}
	SysTaskCurrentSmpPending1 = TRUE;
	SysTaskCurrentSmpPending2 = TRUE;
    SysTaskResolverSmpPending = TRUE;

	Fv_TESTmode_CrlReqFlag = TESTMODE_CurrentLoopFlag;
#if 0
	fsTestCurrentAim = 896;//640;
#else
	if((Fv_dRotorAng_rpm > 10000) || (Fv_dRotorAng_rpm < -10000))
	{
		fsTestCurrentAim = 0;
	}
	else if((Fv_dRotorAng_rpm < 8000) && (Fv_dRotorAng_rpm > -8000))
	{
		fsTestCurrentAim = 896;//640;
	}
	else
	{

	}
#endif

	tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
	tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));
	
	datamid[0] = ((MDLINT16U)Fv_MotorCurrent_Dact);
	datamid[1] = ((MDLINT16U)Fv_MotorCurrent_Qact);
	datamid[2] = ((MDLINT16U)Fv_MotorCurrent_U1);
	datamid[3] = ((MDLINT16U)Fv_MotorCurrent_V1);
	datamid[4] = ((MDLINT16U)Fv_MotorCurrent_W1);
	
	if(i == 0)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)(datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);
	
		PutMsg_ECUTESTMODE(databuf);
		i =1;
	}
	else if(i == 1)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
		databuf[2] = (MDLINT8U)(datamid[2] >> 8);
		databuf[3] = (MDLINT8U)(datamid[2]);
		databuf[4] = (MDLINT8U)(datamid[3] >> 8);
		databuf[5] = (MDLINT8U)(datamid[3]);
		databuf[6] = (MDLINT8U)(datamid[4] >> 8);
		databuf[7] = (MDLINT8U)(datamid[4]);
		PutMsg_ECUTESTMODE(databuf);
		i = 2;
	}	
	else if(i == 2)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)(datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((TB9083_ErrorFlag*2) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);
		PutMsg_ECUTESTMODE(databuf);
		i = 3;
	}	
	else if(i == 3)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
		databuf[2] = (MDLINT8U)(datamid[2] >> 8);
		databuf[3] = (MDLINT8U)(datamid[2]);
		databuf[4] = (MDLINT8U)(datamid[3] >> 8);
		databuf[5] = (MDLINT8U)(datamid[3]);
		databuf[6] = (MDLINT8U)(datamid[4] >> 8);
		databuf[7] = (MDLINT8U)(datamid[4]);
		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}		
}

/****************************************************************
* FUNCTION : TM_CloseLoopNormalNegProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_CloseLoopNormalNegProcess(void)
{
	MDLINT16U tm_predrive = 0;
	MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	static MDLINT8U i = 0;
	static UInt8 reset_delay = 0;
	if(reset_delay == 0)
	{
		reset_delay = 1;
		SysTaskFocResetPending = TRUE;
		SysTaskFocResetPending1 = TRUE;
		SysTaskFocResetPending2 = TRUE;
		SysTaskFocResetTrgPending1 = TRUE;
		SysTaskFocResetTrgPending2 = TRUE;
	}
	else
	{
		SysTaskFocResetPending = FALSE;
		SysTaskFocResetPending1 = FALSE;
		SysTaskFocResetPending2 = FALSE;
		SysTaskFocResetTrgPending1 = FALSE;
		SysTaskFocResetTrgPending2 = FALSE;
	}
	SysTaskCurrentSmpPending1 = TRUE;
	SysTaskCurrentSmpPending2 = TRUE;
    SysTaskResolverSmpPending = TRUE;

	Fv_TESTmode_CrlReqFlag = TESTMODE_CurrentLoopFlag;
#if 0
	fsTestCurrentAim = -896;//-640;
#else
	if((Fv_dRotorAng_rpm > 20000) || (Fv_dRotorAng_rpm < -20000)) //mod by liuyang from 10000 to 20000 241122
	{
		fsTestCurrentAim = 0;
	}
	else if((Fv_dRotorAng_rpm < 8000) && (Fv_dRotorAng_rpm > -8000))
	{
		fsTestCurrentAim = -3840;//-896;//mod from -896 to 3840 by liuyang for HW test 241122
	}
	else
	{

	}
#endif
	
	tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
	tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));
	
	datamid[0] = ((MDLINT16U)Fv_MotorCurrent_Dact);
	datamid[1] = ((MDLINT16U)Fv_MotorCurrent_Qact);
	datamid[2] = ((MDLINT16U)Fv_MotorCurrent_U1);
	datamid[3] = ((MDLINT16U)Fv_MotorCurrent_V1);
	datamid[4] = ((MDLINT16U)Fv_MotorCurrent_W1);
	
	if(i == 0)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)(datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);
	
		PutMsg_ECUTESTMODE(databuf);
		i =1;
	}
	else 
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);
		databuf[2] = (MDLINT8U)(datamid[2] >> 8);
		databuf[3] = (MDLINT8U)(datamid[2]);
		databuf[4] = (MDLINT8U)(datamid[3] >> 8);
		databuf[5] = (MDLINT8U)(datamid[3]);
		databuf[6] = (MDLINT8U)(datamid[4] >> 8);
		databuf[7] = (MDLINT8U)(datamid[4]);
		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}		
}
/****************************************************************
* FUNCTION : TM_CloseLoopLowPosProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_CloseLoopLowPosProcess(void)
{

	MDLINT16U tm_predrive = 0;
	MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	static MDLINT8U i = 0;
	static UInt8 reset_delay = 0;
	if(reset_delay == 0)
	{
		reset_delay = 1;
		SysTaskFocResetPending = TRUE;
		SysTaskFocResetPending1 = TRUE;
		SysTaskFocResetPending2 = TRUE;
		SysTaskFocResetTrgPending1 = TRUE;
		SysTaskFocResetTrgPending2 = TRUE;
	}
	else
	{
		SysTaskFocResetPending = FALSE;
		SysTaskFocResetPending1 = FALSE;
		SysTaskFocResetPending2 = FALSE;
		SysTaskFocResetTrgPending1 = FALSE;
		SysTaskFocResetTrgPending2 = FALSE;
	}
	SysTaskCurrentSmpPending1 = TRUE;
	SysTaskCurrentSmpPending2 = TRUE;
    SysTaskResolverSmpPending = TRUE;

	Fv_TESTmode_CrlReqFlag = TESTMODE_CurrentLoopFlag;
#if 0
	fsTestCurrentAim = 896;//640;
#else
	if((Fv_dRotorAng_rpm > 10000) || (Fv_dRotorAng_rpm < -10000))
	{
		fsTestCurrentAim = 0;
	}
	else if((Fv_dRotorAng_rpm < 8000) && (Fv_dRotorAng_rpm > -8000))
	{
		fsTestCurrentAim = 896;//640;
	}
	else
	{

	}
#endif

	tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
	tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));
	
	datamid[0] = ((MDLINT16U)Fv_MotorCurrent_Dact);
	datamid[1] = ((MDLINT16U)Fv_MotorCurrent_Qact);
//	datamid[2] = ((MDLINT16U)Fv_MotorCurrent_U);
//	datamid[3] = ((MDLINT16U)Fv_MotorCurrent_V);
//	datamid[4] = ((MDLINT16U)Fv_MotorCurrent_W);
	
	if(i == 0)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)(datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);
	
		PutMsg_ECUTESTMODE(databuf);
		i =1;
	}
	else 
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
		databuf[2] = (MDLINT8U)(datamid[2] >> 8);
		databuf[3] = (MDLINT8U)(datamid[2]);
		databuf[4] = (MDLINT8U)(datamid[3] >> 8);
		databuf[5] = (MDLINT8U)(datamid[3]);
		databuf[6] = (MDLINT8U)(datamid[4] >> 8);
		databuf[7] = (MDLINT8U)(datamid[4]);
		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}		
}
/****************************************************************
* FUNCTION : TM_CloseLoopHighNegProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_CloseLoopHighNegProcess(void)
{

    MDLINT16U tm_predrive = 0;
	MDLINT16U datamid[5] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	static MDLINT8U i = 0;
	static UInt8 reset_delay = 0;
	if(reset_delay == 0)
	{
		reset_delay = 1;
		SysTaskFocResetPending = TRUE;
		SysTaskFocResetPending1 = TRUE;
		SysTaskFocResetPending2 = TRUE;
		SysTaskFocResetTrgPending1 = TRUE;
		SysTaskFocResetTrgPending2 = TRUE;
	}
	else
	{
		SysTaskFocResetPending = FALSE;
		SysTaskFocResetPending1 = FALSE;
		SysTaskFocResetPending2 = FALSE;
		SysTaskFocResetTrgPending1 = FALSE;
		SysTaskFocResetTrgPending2 = FALSE;
	}
	SysTaskCurrentSmpPending1 = TRUE;
	SysTaskCurrentSmpPending2 = TRUE;
    SysTaskResolverSmpPending = TRUE;

	Fv_TESTmode_CrlReqFlag = TESTMODE_CurrentLoopFlag;
#if 0
	fsTestCurrentAim = -896;//-640;
#else
	if((Fv_dRotorAng_rpm > 10000) || (Fv_dRotorAng_rpm < -10000))
	{
		fsTestCurrentAim = 0;
	}
	else if((Fv_dRotorAng_rpm < 8000) && (Fv_dRotorAng_rpm > -8000))
	{
		fsTestCurrentAim = -896;//-640;
	}
	else
	{

	}
#endif

	tm_predrive = (MDLINT16U)(DspiA4911Send(0xFC80u));
	tm_predrive = (MDLINT16U)(((tm_predrive & 0x3FC0u) >> 2) | ((tm_predrive & 0x001Eu) >> 1));
	
	datamid[0] = ((MDLINT16U)Fv_MotorCurrent_Dact);
	datamid[1] = ((MDLINT16U)Fv_MotorCurrent_Qact);
//	datamid[2] = ((MDLINT16U)Fv_MotorCurrent_U);
//	datamid[3] = ((MDLINT16U)Fv_MotorCurrent_V);
//	datamid[4] = ((MDLINT16U)Fv_MotorCurrent_W);
	
	if(i == 0)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
		databuf[2] = (MDLINT8U)(datamid[0] >> 8);
		databuf[3] = (MDLINT8U)(datamid[0]);
		databuf[4] = (MDLINT8U)(datamid[1]>> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
//		databuf[6] = (MDLINT8U)(((MDLINT8U)((IO_PredriverState*2 + (IO_PshdriverState ^ 0x01)) << 4)) | ((MDLINT8U)((tm_predrive >> 8) & 0x0Fu)));
		databuf[7] = (MDLINT8U)(tm_predrive);
	
		PutMsg_ECUTESTMODE(databuf);
		i =1;
	}
	else 
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+4);
		databuf[2] = (MDLINT8U)(datamid[2] >> 8);
		databuf[3] = (MDLINT8U)(datamid[2]);
		databuf[4] = (MDLINT8U)(datamid[3] >> 8);
		databuf[5] = (MDLINT8U)(datamid[3]);
		databuf[6] = (MDLINT8U)(datamid[4] >> 8);
		databuf[7] = (MDLINT8U)(datamid[4]);
		PutMsg_ECUTESTMODE(databuf);
		i = 0;
	}		
}

/****************************************************************
* FUNCTION : TM_CloseLoopRevUDProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_CloseLoopRevUDProcess(void)
{
	#define MACRO_INIT_CORRECT  (MDLINT16S)400
	static Int16 correcttemp=0;
	
	MDLINT16U datamid[2] = {0xFFFF,0xFFFF};
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	MDLINT16S datadiff = 0;
	MDLINT16U local_data[8] = {0,};
	MDLINT16U  local_tmp = 0;
	MDLINT16U  local_crc = 0;
	Int32 _RotorSpeed = 0;
	/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹哺绾攱瀚瑰婊呮晛椤帗瀚归柨鐔告灮閹风柉骞栭柨鐔告灮閹峰嘲顩奸搴㈠闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐕傛嫹2021.12.08 By TDJ */
	uint8 ee_Initangle[48] = {0};
	uint8 i = 0;
	static MDLINT32S dataout = 0;
	static MDLINT16S datapos = 0;
	static MDLINT16S dataneg = 0;
	static MDLINT16U datacnt = 0;
	static MDLINT8U  datastp = 0;
	static MDLINT8U  datavalid = 0;
	static MDLINT8U  datawait = 0;
	static UInt8 reset_delay = 0;
	if(reset_delay == 0)
	{
		reset_delay = 1;
		fsTestSpeedAim = 0;
		SysTaskFocResetPending = TRUE;
		SysTaskFocResetPending1 = TRUE;
		SysTaskFocResetPending2 = TRUE;
		SysTaskFocResetTrgPending1 = TRUE;
		SysTaskFocResetTrgPending2 = TRUE;
	}
	else
	{
		SysTaskFocResetPending = FALSE;
		SysTaskFocResetPending1 = FALSE;
		SysTaskFocResetPending2 = FALSE;
		SysTaskFocResetTrgPending1 = FALSE;
		SysTaskFocResetTrgPending2 = FALSE;
	}


	Fv_TESTmode_CrlReqFlag = TESTMODE_SpeedLoopFlag;

	
	if((!datawait) && (reset_delay > 0))
	{
		if(datacnt < 100)
		{
			datacnt ++;
			if(fsTestSpeedAim < 8000)
			{
				fsTestSpeedAim += 8;
			}
			else
			{
				fsTestSpeedAim = 8000;
			}
		}
		else if(datacnt < 500)
		{
			if((datacnt == 100) && (!datastp))
			{
				fsInitRotorAngleCorrect = 0;
				MotorCtrl_FocPar[PreDriver_01].initanglecrr = 0;
				MotorCtrl_FocPar[PreDriver_02].initanglecrr = 0;
			}
			
			datacnt ++;
			if(datacnt < 200)
			{
				dataout = 0;
			}
			else 
			{
				dataout += Fv_MotorVoltage_D;
				if(datacnt == 500)
				{
					datapos = (MDLINT16S)(dataout/300);
				}
			}
			fsTestSpeedAim = 8000;
		}
		else if(datacnt <550)
		{
			datacnt ++;
			fsTestSpeedAim = 0;
		}
		else if(datacnt <650)
		{
			datacnt ++;
			if(fsTestSpeedAim > -8000)
			{
				fsTestSpeedAim -= 8;
			}
			else
			{
				fsTestSpeedAim = -8000;
			}
		}
		else if(datacnt <1050)
		{
			datacnt ++;
			if(datacnt < 750)
			{
				dataout = 0;
			}
			else 
			{
				dataout += Fv_MotorVoltage_D;
				if(datacnt == 1050)
				{
					dataneg = (MDLINT16S)(dataout/300);
				}
			}
			fsTestSpeedAim = -8000;	
			
		}
		else
		{
				datacnt = 0;
			{
				datadiff = (MDLINT16S)(dataneg - datapos);
				correcttemp+= datadiff;
				if(correcttemp > EEPROM_INIT_MAXCCRA)
				{
					fsInitRotorAngleCorrect = EEPROM_INIT_MAXCCRA;
				}
				else if(correcttemp < -EEPROM_INIT_MAXCCRA)
				{
					fsInitRotorAngleCorrect = -EEPROM_INIT_MAXCCRA;
				}
				else
				{
					fsInitRotorAngleCorrect = correcttemp;
				}
				MotorCtrl_FocPar[PreDriver_01].initanglecrr = fsInitRotorAngleCorrect;
				MotorCtrl_FocPar[PreDriver_02].initanglecrr = fsInitRotorAngleCorrect;
				/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚圭拠娆撴晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閸楁悂鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸鐞涙顣幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨噦鎷�2021.12.08 By TDJ */
				if(datastp > 0)
				{
					/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崐濂告晸閺傘倖瀚归崶缈犲▏闁跨喓鐓悮瀛樺闁跨喐鏋婚幏宄拔涢濠冨闁跨喐鏋婚幏宄邦潗闁跨喐鏋婚幏鐑芥晸鏉堝啰顣幏鐑芥晸閺傘倖瀚规稉鈧柨鐔兼應閳藉懏瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚敓?021.12.08 By TDJ */
					if((correcttemp > EEPROM_INIT_MAXCCRA + MACRO_INIT_CORRECT)
							|| (correcttemp < -(EEPROM_INIT_MAXCCRA + MACRO_INIT_CORRECT)))
					{
						fsInitRotorAngleCorrect = 0;
						MotorCtrl_FocPar[PreDriver_01].initanglecrr = 0;
						MotorCtrl_FocPar[PreDriver_02].initanglecrr = 0;
						datavalid = 2;
					}
					else
					{
						MotorCtrl_FocPar[PreDriver_01].initanglecrr = fsInitRotorAngleCorrect;
						MotorCtrl_FocPar[PreDriver_02].initanglecrr = fsInitRotorAngleCorrect;
						datavalid = TRUE;
					}
					/* 閿熻妭璁规嫹閿熻娇鎾呮嫹閿熸枻鎷烽敓鍓跨鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷�2021.12.08 By TDJ */
					datawait = TRUE;
				}
				fsTestSpeedAim = 0;
				datastp = TRUE;
			}
		}		

		if(datavalid == 1)
		{
	   	   	for(i = 0; i < 8; i++)
	   	   	{
	   	   		local_data[i] = Eeprom_MotorAngle.halfword[i];
	   	   	}
	   	   	local_data[4] = MotorCtrl_FocPar[PreDriver_01].initanglecrr;
			local_data[5] = MotorCtrl_FocPar[PreDriver_02].initanglecrr;

	   	   	for(i = 0; i < 16; i ++)
	   	 	{
	   	   		/* 闁跨喕顫楃拋瑙勫闁跨喕鍓奸崣宄板殩閹风兘鏁撻弬銈嗗閸嬪繘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崐濂告晸閺傘倖瀚归柨鐔诲Г閳ユ棃鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2021.12.08 By TDJ */
	   	   		ee_Initangle[i] = Eeprom_MotorResolver.byte[i];
	   	 	}

	   	 	for(i = 16; i < 32; i ++)
	   	 	{
	   	 		/* 闁跨喕顫楃拋瑙勫闁跨喕鍓奸悮瀛樺闁跨喐鏋婚幏铚傜秴閸嬪繘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崐濂告晸閺傘倖瀚归柨鐔诲Г閳ユ棃鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2021.12.08 By TDJ */
	   	 		ee_Initangle[i] = Eeprom_MotorPhase.byte[i - 16];
	   	 	}

	   	 	for(i = 32; i < 40; i ++)
	   	 	{
	   	 		/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹哺绾攱瀚归懙鏃堟晸閺傘倖瀚规俊妤婁悍閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閿�?021.12.08 By TDJ */
	   	 		ee_Initangle[i] = Eeprom_MotorAngle.byte[i - 32];
	   	 	}
	   	 	/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹哺绾攱瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喕顢滅喊澶嬪闁跨喐鏋婚幏宄邦浖椤忓孩瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨噦鎷�2021.12.08 By TDJ */
	   	 	ee_Initangle[40] = (uint8)(local_data[4] & 0x00FF);
	   	 	ee_Initangle[41] = (uint8)((local_data[4] & 0xFF00) >> 8);
			ee_Initangle[42] = (uint8)(local_data[5] & 0x00FF);
	   	 	ee_Initangle[43] = (uint8)((local_data[5] & 0xFF00) >> 8);

	   	 	/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹哺绾攱瀚瑰婊呮晛椤帗瀚归柨鐔峰建閿濆繑瀚归柨鐔煎徍绾攱瀚归柨鐔奉潟閳ユ棃鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2021.12.08 By TDJ */
	   	 	local_tmp = CRC8forSAEJ1850(ee_Initangle, 47);
	   	 	local_data[7] = (((uint16)local_tmp << 8) & 0xFF00);
	   	   	Eeprom_WriteMotorAngle((UInt8*)local_data);
#if 0
		  	local_tmp = (MDLINT8U)((local_data[ANGC_PARA_NUM - 1] & 0xFF00) >> 8);
			   	
		   	local_crc = CRC8forSAEJ1850((MDLINT8U*)local_data,(MDLINT8U)(ANGC_PARA_NUM*2 - 1));
#else
		   	local_tmp = local_data[7];
		   	local_crc = Eeprom_MotorAngle.halfword[7];
#endif
		   	if(local_tmp != local_crc)
		   	{
//		   		fsEEPROM_StoreState[AngleAutoCorrectData].failure = TRUE;
		   	}
		   	else
		   	{
//		   		fsEEPROM_StoreState[AngleAutoCorrectData].failure = FALSE;
		   	}		
		}		
	}


	datamid[0] = ((MDLINT16U)correcttemp);//fsInitRotorAngleCorrect);
	_RotorSpeed = (Fv_FOC_RotorSpd < 0) ? -Fv_FOC_RotorSpd : Fv_FOC_RotorSpd;
	datamid[1] = (MDLINT16U)((MDLINT16S)((((Int32) _RotorSpeed) * ((Int32) MACRO_RAD2RPM) ) >> 17));

	
	databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
	databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+4);
	databuf[2] = (MDLINT8U)(datamid[0] >> 8);
	databuf[3] = (MDLINT8U)(datamid[0]);
	databuf[4] = (MDLINT8U)(datamid[1]>> 8);
	databuf[5] = (MDLINT8U)(datamid[1]);
	databuf[6] = (MDLINT8U)(datavalid);
//	databuf[7] = (MDLINT8U)(!fsEEPROM_StoreState[AngleAutoCorrectData].failure);

	PutMsg_ECUTESTMODE(databuf);
}
/****************************************************************
* FUNCTION : TM_PowerLatchProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_PowerLatchProcess(void)
{

	MDLINT16U dataadc = 0xFF;
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	
	uint8 i = 0;
	MDLINT8U ee_tmp = 0;
	MDLINT8U ee_crc = 0;
	uint8 dflashtemp[48] = {0,};
	uint8 angle_err=0;
	uint8 waitflag=0;
	uint8 errflag=0;
	
	Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
	fsOpenloopUQ=0;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2
	fsOpenloopSa=0;
	/*閿熸枻鎷烽敓鎺ュ洖璁规嫹纭敓杈冪鎷峰閿熸枻鎷烽敓绐栧瓨鍌ㄩ敓缂寸櫢鎷�       20220223    by  wtw*/
if(StoreManager_GetStatus()==0)
{
//	Eeprom_ReadMotorResolver();
//	Eeprom_ReadMotorPhase();
//	Eeprom_ReadMotorAngle();
/*閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹濮嬮敓鏂ゆ嫹閿熻鍚︿繚杈炬嫹鏅掗敓锟�    20220222    by  wtw*/
		for(i = 0; i < 16; i ++)
		{
			/* 闁跨喕顫楃拋瑙勫闁跨喕鍓奸崣宄板殩閹风兘鏁撻弬銈嗗閸嬪繘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崐濂告晸閺傘倖瀚归柨鐔诲Г閳ユ棃鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2021.12.08 By TDJ */
			dflashtemp[i] = Eeprom_MotorResolver.byte[i];
		}

		for(i = 16; i < 32; i ++)
		{
			/* 闁跨喕顫楃拋瑙勫闁跨喕鍓奸悮瀛樺闁跨喐鏋婚幏铚傜秴閸嬪繘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崐濂告晸閺傘倖瀚归柨鐔诲Г閳ユ棃鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2021.12.08 By TDJ */
			dflashtemp[i] = Eeprom_MotorPhase.byte[i - 16];
		}

		for(i = 32; i < 48; i ++)
		{
			/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹哺绾攱瀚圭紘宀勬晸閺傘倖瀚归柨鐔虹哺绾攱瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喕顢滅喊澶嬪闁跨喐鏋婚幏宄邦浖椤忓孩瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨噦鎷�2021.12.08 By TDJ */
			dflashtemp[i] = Eeprom_MotorAngle.byte[i - 32];
		}
		/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹哺绾攱瀚瑰婊呮晛椤帗瀚归柨鐔峰建閿濆繑瀚归柨鐔煎徍娴兼瑦瀚归柨鐔诲Г閳ユ棃鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2021.12.08 By TDJ */
		ee_tmp = dflashtemp[47];

		/* 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔虹哺绾攱瀚瑰婊呮晛椤帗瀚归柨鐔峰建閿濆繑瀚归柨鐔煎徍绾攱瀚归柨鐔奉潟閳ユ棃鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2021.12.08 By TDJ */
		ee_crc = CRC8forSAEJ1850(dflashtemp, 47);

	if(ee_tmp != ee_crc)
	{
		angle_err=1;
	}
	else
	{
		angle_err=0;
	}
	waitflag=2;
}
else
{
	waitflag=1;
}

	errflag=(uint8)(/*(fsPublickeyflag<<6)|*/((Fv_ErrDiagStatus[DTC_EEPROMcheck_ConfigCheck]>FailureDiag_RegOK)<<5)|((Fv_ErrDiagStatus[DTC_EEPROMcheck_CalibCheck]>FailureDiag_RegOK)<<4)|((Fv_ErrDiagStatus[DTC_EEPROMcheck_AngleCrrCheck]>FailureDiag_RegOK)<<3)|
	   ((Fv_ErrDiagStatus[DTC_EEPROMcheck_AngleCheck]>FailureDiag_RegOK)<<2)|(Fv_ErrDiagStatus[DTC_EEPROMcheck_OtherCheck]>FailureDiag_RegOK));

		dataadc = AD_SampFunCheck;
		
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = (MDLINT8U)(fsSPI_Communication_Status);
		databuf[3] = (MDLINT8U)(dataadc >> 8);
		databuf[4] = (MDLINT8U)(dataadc);
		databuf[5] = angle_err;
		databuf[6] = waitflag;
		databuf[7] = errflag;
		PutMsg_ECUTESTMODE(databuf);



	
}
/****************************************************************
* FUNCTION : TM_ProductInfoProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_ProductInfoProcess(void)
{
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	
#if defined(PRODUCT_ENABLE_ENCRYPTION)
	
	MDLINT32U returnCode;           /* Return code from each SSD function. */
    MDLBOOL   shadowFlag;           /* H7FA shadow select flag */
    MDLINT32U lowEnabledBlocks;     /* selected blocks in low space */
    MDLINT32U midEnabledBlocks;     /* selected blocks in middle space */
    MDLINT32U highEnabledBlocks;    /* selected blocks in high space */
//    MDLINT32U blkLockState;
//    MDLINT8U  blkLockEnabled;       /* block lock enabled state */
#endif  
    static MDLINT8U flash_security_flag = 0;
    static MDLINT8U flash_errflag = FALSE;
    MDLINT32U enc_data[2] = {0,0};
   
	
	Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
	fsOpenloopUQ=0;
	fsOpenloopUD=0;
	fsOpenloopS1=0;//20
	fsOpenloopS2=0;//1,spd=s1/s2
	fsOpenloopSa=0;
	
	
	if(/*fsGblINFOWriteFlag == 1*/flash_security_flag == FALSE)
	{
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = 0xAA;
		databuf[3] = 0xAA;
		databuf[4] = 0xBB;
		databuf[5] = 0xBB;
		databuf[6] = 0xCC;
		databuf[7] = 0xCC;
		PutMsg_ECUTESTMODE(databuf);
		
#if defined(PRODUCT_ENABLE_ENCRYPTION)
#if TESTMODE_SEGMENt_DEF
		flash_security_flag = TRUE;
	
		DisableInterrupts;
		DISABLE_WATCHDOG();
		ContinueFeedExtWD(TRUE);
		memcpy(&enc_data,(MDLINT32U *)SECURITY_FLASH_ADDR,8);
		if((enc_data[0] != FLASH_SECURITY_KEY) || (enc_data[1] != FLASH_SECURITY_KEY))
		{
		/* Assign function pointers */
		pFlashInit     = (pFLASHINIT)     FlashInit_C;
		pFlashErase    = (pFLASHERASE)    FlashErase_C;
		pBlankCheck    = (pBLANKCHECK)    BlankCheck_C;
		pFlashProgram  = (pFLASHPROGRAM)  FlashProgram_C;
		pProgramVerify = (pPROGRAMVERIFY) ProgramVerify_C;
		pCheckSum      = (pCHECKSUM)      CheckSum_C;
		pGetLock       = (pGETLOCK)       GetLock_C;
		pSetLock       = (pSETLOCK)       SetLock_C;

		/* C Flash */
		ssdConfig.c90flRegBase  = C90FL_REG_BASE;            
		ssdConfig.mainArrayBase = MAIN_ARRAY_BASE;        
		ssdConfig.mainArraySize = 0;                     
		ssdConfig.shadowRowBase = SHADOW_ROW_BASE;        
		ssdConfig.shadowRowSize = SHADOW_ROW_SIZE;        
		ssdConfig.lowBlockNum 	= 0;                       
		ssdConfig.midBlockNum 	= 0;                       
		ssdConfig.highBlockNum	= 0;                        
		ssdConfig.pageSize  	= FLASH_PAGE_SIZE;           
		ssdConfig.BDMEnable 	= FALSE;                     


			
		returnCode = pFlashInit( &ssdConfig );

        
			returnCode = pSetLock( &ssdConfig, LOCK_SHADOW_PRIMARY, 0, FLASH_LMLR_PASSWORD );
			if ( C90FL_OK != returnCode )
			{
				flash_errflag = TRUE;
			}
			returnCode = pSetLock( &ssdConfig, LOCK_SHADOW_SECONDARY, 0, FLASH_SLMLR_PASSWORD );
	        if ( C90FL_OK != returnCode )
			{
				flash_errflag = TRUE;
			}  
	         	    					           
			shadowFlag = TRUE;
			lowEnabledBlocks = 0x00000000;
			midEnabledBlocks = 0x00000000;
			highEnabledBlocks = 0x00000000;
			returnCode = pFlashErase( &ssdConfig, shadowFlag, lowEnabledBlocks, midEnabledBlocks, highEnabledBlocks, NULL_CALLBACK );
			if( C90FL_OK != returnCode)
			{
				flash_errflag = TRUE;
			}
			scrt_buffer[0] = FLASH_SECURITY_KEY;
			scrt_buffer[1] = FLASH_SECURITY_KEY;
			scrt_source = (MDLINT32U)scrt_buffer;
			returnCode = pFlashProgram( &ssdConfig, SECURITY_FLASH_ADDR, 8, scrt_source, NULL_CALLBACK );
			if( C90FL_OK != returnCode)
			{
				flash_errflag = TRUE;
			}            
		}
             
		   EnableInterrupts;
		   ENABLE_WATCHDOG();
		   ContinueFeedExtWD(FALSE);	
#endif
#endif

	}
	else
	{
		if(flash_errflag == FALSE)
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
			databuf[2] = 0x11;
			databuf[3] = 0x11;
			databuf[4] = 0x22;
			databuf[5] = 0x22;
			databuf[6] = 0x33;
			databuf[7] = 0x33;			
		}
		else
		{
			databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
			databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
			databuf[2] = 0x44;
			databuf[3] = 0x44;
			databuf[4] = 0x55;
			databuf[5] = 0x55;
			databuf[6] = 0x66;
			databuf[7] = 0x66;	
		}

		PutMsg_ECUTESTMODE(databuf);	
	}
	
		fsTESTmode_ResetFlag = FALSE;
		DisablePowerSupply();	
		
	
}

/****************************************************************
* FUNCTION : TM_FCTInputOutputAvailctrl
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_FCTInputOutputAvailctrl(void)
{
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	MDLINT16U datatmp[4] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U test_frez = 0;
	MDLINT16U test_tmp1 = 0;
	MDLINT16U test_tmp2 = 0;
	MDLINT16U test_tmp3 = 0;
	MDLINT16U test_dut1 = 0;
	MDLINT16U test_dut2 = 0;
	MDLINT16U test_dut3 = 0;
	MDLINT8U test_daccnt = 0xFF;
	
	static MDLINT8U test_daccnt_last = 0;
	static MDLINT16U test_dac = 0;	
	
	static MDLINT16S test_mid[3] = {0,};
	static MDLINT8U  test_cnt_delay = 0;
	static MDLINT8U  i = 0;
	static MDLINT16U temdata_tp2[10] = {0,};
	static MDLINT8U  tp2_cnt = 0;
	static MDLINT16U test_cnt = 0;
	static MDLINT8U  test_valid = 0;


	/*IO control*/
//	SetPowerLatch(1);
	
//	SetTrqPwrSpl(1);
//	SetTrqPwrRef(1);
//	SetRtrTrmSpl(1);
//	SetEEPROMHOLD(1);
	
#if defined(ENABLE_SENT_PWM_SELECT)
	SENT_RCR3.U = 0x00602;
	SENT_RCR2.U = 0x00602;
	SENT_RCR0.U = 0x00602;
	GTM_TIM0INSEL.U = 0x1110444B;
	GTM_TIM0_CH0_CTRL.B.TIM_EN = 1;
	GTM_TIM0_CH5_CTRL.B.TIM_EN = 1;
	GTM_TIM0_CH6_CTRL.B.TIM_EN = 1;
	GTM_TIM0_CH7_CTRL.B.TIM_EN = 1;
#endif

	/*Vice MCU:PowerLatch 1,Relay 0,PreDriver 0*/
//	BridgePrechargeFun(FALSE);
//	PredriverViceCtrlFun(FALSE);
	SysTaskPhaseDiagStepIndex = InitDiagStep_Default;
#if T212L_TESTMODE
	GTM_TOM1_TGC0_OUTEN_CTRL.U = 0x0000AAAA;
	GTM_TOM1_TGC0_OUTEN_STAT.U = 0x0000AAAA;
//	GTM_DTM5_CH_CTRL2.U = 0x00888888;

//	GTM_DTM5_CH0_DTV.U = 0x00000000;
//	GTM_DTM5_CH1_DTV.U = 0x00000000;
//	GTM_DTM5_CH2_DTV.U = 0x00000000;

//	Gtm_GetChannelDuty(&test_dut1, &test_dut2, &test_dut3);
	test_dut1 /= 10;
	test_dut2 /= 10;
	test_dut3 /= 10;
#else
	SetFlexPWMA_OUTEN(PWM123_OUTEN);
	SetFlexPWMB_OUTEN(PWM123_OUTEN);

	FlexPwmSetDeadZone(3,0,0);
	FlexPwmSetDeadZone(2,0,0);
	FlexPwmSetDeadZone(1,0,0);

	test_dut1 = (MDLINT16U)(eTimer1ChxIsr(1)/10);
	test_dut2 = (MDLINT16U)(eTimer1ChxIsr(2)/10);
	test_dut3 = (MDLINT16U)(eTimer1ChxIsr(3)/10);
#endif
//	test_daccnt = (MDLINT8U)fsDataFromGn32[TRSM_DAC];
	if(test_daccnt != test_daccnt_last)
	{
		test_valid = 1;
	}
	if(test_valid == 1)
	{
		if(test_cnt < 5)
		{
			if(test_cnt > 1)
			{
//				test_dac = AD_SampFunCheck;
			}
			test_cnt++;
		}
		else
		{
			test_valid = 0;
			test_cnt = 0;
		}
	}

	test_daccnt_last = test_daccnt;
	

	if(test_cnt_delay < 45)
	{
//		SetPhaseRelay(0);
		ClosePhase();
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
//		SetMainRelay(0);
		CloseRelay();
		

		test_cnt_delay++;
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+15);
		databuf[2] = 0;
		databuf[3] = 0;
		databuf[4] = 0;
		databuf[5] = 0;
		databuf[6] = 0;
		databuf[7] = 0;
		PutMsg_ECUTESTMODE(databuf);
		
		temdata_tp2[tp2_cnt] = 0;
		tp2_cnt++;
		if(tp2_cnt > 9)
		{
			tp2_cnt = 0;
		}
		else
		{
			
		}
			
	}
	else if((test_cnt_delay == 45))
	{
//		SetPhaseRelay(1);
		OpenPhase();
//		SetMainRelay(1);
		OpenRelay();
		
		test_cnt_delay++;
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+15);
		databuf[2] = 0x22;
		databuf[3] = 0x22;
		databuf[4] = 0x22;
		databuf[5] = 0x22;
		databuf[6] = 0x22;
		databuf[7] = 0x22;
		PutMsg_ECUTESTMODE(databuf);
	}
	else if((test_cnt_delay > 45) && (test_cnt_delay < 55))
	{
	//	SetPreDrvENH(1);
//		SetPreDrvINH(1);
#if 0
#if T212L_TESTMODE
		test_mid[0] = (MDLINT16S)(512 - (AD_PMSMCurrentU >> 2));
		test_mid[1] = (MDLINT16S)(512 - (AD_PMSMCurrentV >> 2));
		test_mid[2] = (MDLINT16S)(512 - (AD_PMSMCurrentW >> 2));
#else
		test_mid[0] = (MDLINT16S)(512 - AD_PMSMCurrentU);
		test_mid[1] = (MDLINT16S)(512 - AD_PMSMCurrentV);
		test_mid[2] = (MDLINT16S)(512 - AD_PMSMCurrentW);
#endif
		TM_FCT_CurrentMid[0] = test_mid[0];
		TM_FCT_CurrentMid[1] = test_mid[1];
		TM_FCT_CurrentMid[2] = test_mid[2];
#endif
		TM_FCT_CurrentMid[0] = 0;
		TM_FCT_CurrentMid[1] = 0;
		TM_FCT_CurrentMid[2] = 0;
		datatmp[0] = (MDLINT16U)AD_PMSMCurrentU >> 2;
		datatmp[1] = (MDLINT16U)AD_PMSMCurrentV >> 2;
		datatmp[2] = (MDLINT16U)AD_PMSMCurrentW >> 2;

		test_cnt_delay++;

		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+15);
		databuf[2] = (MDLINT8U)(datatmp[0] >> 8);
		databuf[3] = (MDLINT8U)(datatmp[0]);
		databuf[4] = (MDLINT8U)(datatmp[1] >> 8);
		databuf[5] = (MDLINT8U)(datatmp[1]);
		databuf[6] = (MDLINT8U)(datatmp[2] >> 8);
		databuf[7] = (MDLINT8U)(datatmp[2]);
		PutMsg_ECUTESTMODE(databuf);
	}
	else if((test_cnt_delay >= 55) && (test_cnt_delay < 85))
	{
#if T212L_TESTMODE
		test_mid[0] = (MDLINT16S)(512 - (AD_PMSMCurrentU >> 2));
		test_mid[1] = (MDLINT16S)(512 - (AD_PMSMCurrentV >> 2));
		test_mid[2] = (MDLINT16S)(512 - (AD_PMSMCurrentW >> 2));
#else
		test_mid[0] = (MDLINT16S)(512 - AD_PMSMCurrentU);
		test_mid[1] = (MDLINT16S)(512 - AD_PMSMCurrentV);
		test_mid[2] = (MDLINT16S)(512 - AD_PMSMCurrentW);
#endif
		TM_FCT_CurrentMid[0] += test_mid[0];
		TM_FCT_CurrentMid[1] += test_mid[1];
		TM_FCT_CurrentMid[2] += test_mid[2];
		
		datatmp[0] = (MDLINT16U)AD_PMSMCurrentU >> 2;
		datatmp[1] = (MDLINT16U)AD_PMSMCurrentV >> 2;
		datatmp[2] = (MDLINT16U)AD_PMSMCurrentW >> 2;
		
		test_cnt_delay++;
		
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+15);
		databuf[2] = (MDLINT8U)(datatmp[0] >> 8);
		databuf[3] = (MDLINT8U)(datatmp[0]);
		databuf[4] = (MDLINT8U)(datatmp[1] >> 8);
		databuf[5] = (MDLINT8U)(datatmp[1]);
		databuf[6] = (MDLINT8U)(datatmp[2] >> 8);
		databuf[7] = (MDLINT8U)(datatmp[2]);
		PutMsg_ECUTESTMODE(databuf);
	}
	else if((test_cnt_delay >= 85) && (test_cnt_delay < 90))
	{
		Fv_TESTmode_CrlReqFlag = TESTMODE_FCTsLoopFlag;
		(void)DspiA4911Send(0xE000u);//read diag 0
		(void)DspiA4911Send(0xE801u);//read diag 1
		(void)DspiA4911Send(0xF001u);//read diag 2
		test_cnt_delay++;
		
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+15);
		databuf[2] = (MDLINT8U)(0x33);
		databuf[3] = (MDLINT8U)(0x33);
		databuf[4] = (MDLINT8U)(0x33);
		databuf[5] = (MDLINT8U)(0x33);
		databuf[6] = (MDLINT8U)(0x33);
		databuf[7] = (MDLINT8U)(0x33);
		PutMsg_ECUTESTMODE(databuf);
	}	
	else
	{
	    	Fv_TESTmode_CrlReqFlag = TESTMODE_FCTsLoopFlag;
			
			if(i == 0)
			{
	//			datatmp[0] = (MDLINT16U)(((fsDataFromGn32[0] & 0x6000) >> 5) | ((fsDataFromGn32[0] & 0x0FF0) >> 4));
	//			datatmp[1] = (MDLINT16U)(((fsDataFromGn32[1] & 0x40) << 3) | ((fsDataFromGn32[1] & 8) << 5)
	//					 | (fsDataFromGn32[3] & 0xF0) | (fsDataFromGn32[4] & 0x0F)) ;
				datatmp[2] = (MDLINT16U)(AD_PowerSys >> 1);
				datatmp[3] = (MDLINT16U)(AD_IgnitionSys >> 1);
				
				
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_T1].frez/10);	
				/*V1,V2,V3,F1*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;

				
				PutMsg_ECUTESTMODE(databuf);
				i =1;
			}
			else if(i == 1)
			{

				datatmp[0] = (MDLINT16U)(AD_TempSys >> 2);
				datatmp[1] = (MDLINT16U)test_dut1;
				datatmp[2] = (MDLINT16U)test_dut2;
				datatmp[3] = (MDLINT16U)test_dut3;
								
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_T2].frez/10);
				/*V5,V6,V7,V8,F2*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;					
				
				
				PutMsg_ECUTESTMODE(databuf);
				i = 2;
			}
			else if(i == 2)
			{
				datatmp[0] = (MDLINT16U)(test_dac >> 2);
				datatmp[1] = (MDLINT16U)(AD_RotorSenPower >> 2);
				datatmp[2] = (MDLINT16U)(fsETimerCapInfo[Hella_T1].duty/10);
				datatmp[3] = (MDLINT16U)(fsETimerCapInfo[Hella_T2].duty/10);				
		
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_AP].frez/10);
				/*V9,V10,V11,V12,F3*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);

				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;					
				
				
				PutMsg_ECUTESTMODE(databuf);
				i = 3;
			}
			else if(i == 3)
			{
		
				datatmp[0] = (MDLINT16U)(fsETimerCapInfo[Hella_AP].duty/10);
				datatmp[1] = (MDLINT16U)(fsETimerCapInfo[Hella_AS].duty/10);
//				datatmp[2] = (MDLINT16U)(AD_RotorMainMid >> 2);
//				datatmp[3] = (MDLINT16U)(AD_RotorMainCos >> 2);
				
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_AS].frez/10);		
					
				/*V13,V14,V15,V16,F4*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				
				databuf[7] = test_frez;				

				
				PutMsg_ECUTESTMODE(databuf);
				i = 4;
			}
			else if(i == 4)
			{
//				datatmp[0] = (MDLINT16U)(AD_RotorMainSin >> 2);
				datatmp[1] = (MDLINT16U)(AD_TorqueSenPower >> 2);
				datatmp[2] = (MDLINT16U)(AD_PowerRelaySys >> 2);
//				datatmp[3] = (MDLINT16U)(AD_I2D5Ref >> 2);
				
				/*V17,V18,V19,V20*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+4);

				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;

				
				PutMsg_ECUTESTMODE(databuf);
				i = 5;
			}
			else if(i == 5)
			{
				/*V21,V22,V23,V24,S1,S2,D1,D2*/
				/* 閿熸枻鎷烽敓鏂ゆ嫹RAM閿熸枻鎷烽敓鏂ゆ嫹鏍￠敓鏂ゆ嫹 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹2021.11.23 By TDJ */
#if 0
				uint8 i_cnt;
				uint8 *BT_JUMP_ADDR;

			 	test_tmp1 = EEPROM_MAP_VERSION;

				BT_JUMP_ADDR = ((uint8 *)0xD0014000);
				for(i_cnt = 0; i_cnt < 8; i_cnt++)
				{
					*BT_JUMP_ADDR = i_cnt;
					if(*BT_JUMP_ADDR != i_cnt)
					{
						test_tmp1 = 0;
						break;
					}
					BT_JUMP_ADDR++;
				}
#endif
			 	test_tmp2 = (MDLINT16U)(DspiA4911Send(0xFC80u));
				test_tmp2 = (MDLINT16U)(((test_tmp2 & 0x3FC0u) >> 2) | ((test_tmp2 & 0x001Eu) >> 1)); 

				test_frez = (((MDLINT8U)(Fv_SPITimeoutReq > 0)) << 7) |
//							(((MDLINT8U)(test_tmp1 == EEPROM_MAP_VERSION)) << 6) |
//				            (((MDLINT8U)(IO_PredriverState*2 + (IO_PshdriverState ^ 0x01))) << 4) |
				            ((MDLINT8U)((test_tmp2 >> 8) & 0x0Fu));
				Fv_SPITimeoutReq = 0;
				datatmp[0] = (MDLINT16U)(AD_InterVolt1d2 >> 2);
				datatmp[3] = (MDLINT16S)((AD_PMSMCurrentU >> 2) + TM_FCT_CurrentMid[0] / 30);//(MDLINT16S)((AD_PMSMCurrentU >> 2) + test_mid[0]);
				datatmp[2] = (MDLINT16S)((AD_PMSMCurrentV >> 2) + TM_FCT_CurrentMid[1] / 30);//(MDLINT16S)((AD_PMSMCurrentV >> 2) + test_mid[1]);
				datatmp[1] = (MDLINT16S)((AD_PMSMCurrentW >> 2) + TM_FCT_CurrentMid[2] / 30);//(MDLINT16S)((AD_PMSMCurrentW >> 2) + test_mid[2]);
				
				
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+5);
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;	
				
				PutMsg_ECUTESTMODE(databuf);
				i = 6;
			}
			else
			{

				test_tmp2 = (MDLINT16U)(DspiA4911Send(0xFC80u));
				test_tmp2 = (MDLINT16U)(((test_tmp2 & 0x3FC0u) >> 2) | ((test_tmp2 & 0x001Eu) >> 1));
				test_frez = (MDLINT8U)test_tmp2;
				
				datatmp[0] = (MDLINT16U)(AD_InterMCUTemp >> 2);
				datatmp[1] = (MDLINT16U)(temdata_tp2[tp2_cnt] >> 2);

				/*V25,V26,D3*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+6);

				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4)));//L4H4

				databuf[7] = test_frez;
				
				
				tp2_cnt++;
				if(tp2_cnt > 5)
				{
					tp2_cnt = 0;
				}
				else
				{
					
				}
				
				PutMsg_ECUTESTMODE(databuf);
				i = 0;
		}
	}
}

/****************************************************************
* FUNCTION : TM_FCTInputOutputNavailctrl
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_FCTInputOutputNavailctrl(void)
{
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	MDLINT16U datatmp[4] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	MDLINT8U test_frez = 0;
	MDLINT16U test_tmp1 = 0;
	MDLINT16U test_tmp2 = 0;
	MDLINT16U test_tmp3 = 0;
	MDLINT16U test_dut1 = 0;
	MDLINT16U test_dut2 = 0;
	MDLINT16U test_dut3 = 0;

	
	static MDLINT8U  test_cnt_delay = 0;
	static MDLINT8U  i = 0;

	/*IO control*/
//	SetPowerLatch(0);
	
//	SetTrqPwrSpl(1);
//	DisableTorqueSensorPowerSupply();
//	SetTrqPwrRef(1);
//	SetRtrTrmSpl(0);
//	SetEEPROMHOLD(0);
//	SetMainRelay(0);
//	CloseRelay();
	
#if defined(ENABLE_SENT_PWM_SELECT)
	SENT_RCR3.U = 0x00602;
	SENT_RCR2.U = 0x00602;
	SENT_RCR0.U = 0x00602;
	GTM_TIM0INSEL.U = 0x1110444B;
	GTM_TIM0_CH0_CTRL.B.TIM_EN = 1;
	GTM_TIM0_CH5_CTRL.B.TIM_EN = 1;
	GTM_TIM0_CH6_CTRL.B.TIM_EN = 1;
	GTM_TIM0_CH7_CTRL.B.TIM_EN = 1;
#endif
	 
	/*PWM-->50%*/	
	Fv_TESTmode_CrlReqFlag = TESTMODE_FCTsLoopFlag;

	/*Vice MCU:PowerLatch 0,Relay 1,PreDriver 1*/
#if T212L_TESTMODE
//	GTM_DTM5_CH0_DTV.U = 0x00000000;
//	GTM_DTM5_CH1_DTV.U = 0x00000000;
//	GTM_DTM5_CH2_DTV.U = 0x00000000;

//	Gtm_GetChannelDuty(&test_dut1, &test_dut2, &test_dut3);
	if(test_dut1 == 6600)
	{
		test_dut1 = 0;
	}
	if(test_dut2 == 6600)
	{
		test_dut2 = 0;
	}
	if(test_dut3 == 6600)
	{
		test_dut3 = 0;
	}
	test_dut1 /= 10;
	test_dut2 /= 10;
	test_dut3 /= 10;

#else
	FlexPwmSetDeadZone(3,0,0);
	FlexPwmSetDeadZone(2,0,0);
	FlexPwmSetDeadZone(1,0,0);

	test_dut1 = (MDLINT16U)(eTimer1ChxIsr(1)/10);
	test_dut2 = (MDLINT16U)(eTimer1ChxIsr(2)/10);
	test_dut3 = (MDLINT16U)(eTimer1ChxIsr(3)/10);	
#endif
	if(test_cnt_delay < 200)
	{
			
		fsETimerCapInfo[Hella_T1].frez = 0;
		fsETimerCapInfo[Hella_T2].frez = 0;
		fsETimerCapInfo[Hella_AP].frez = 0;
		fsETimerCapInfo[Hella_AS].frez = 0;
		
		test_cnt_delay++;
		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+15);
		databuf[2] = 0;
		databuf[3] = 0;
		databuf[4] = 0;
		databuf[5] = 0;
		databuf[6] = 0;
		databuf[7] = 0;
		PutMsg_ECUTESTMODE(databuf);
		
		if(test_cnt_delay == 1)
		{
#if T212L_TESTMODE
#else
			DSPI_1.RSER.B.RFDFRE = 0;
#endif
			fsSPI_Communication_Status = 0;
			Fv_SPITimeoutReq = 0;
//			fsDataFromGn32[TRSM_BAT] = 0;
//			fsDataFromGn32[TRSM_IGKEY] = 0;
//			SetPreDrvENH(1);
//			SetPreDrvINH(1);
//			SetPhaseRelay(1);
			OpenPhase();
		}
        else 
        {
			if(test_cnt_delay <= 150)
			{
//				SetPreDrvENH(1);
////				SetPreDrvINH(1);
//				SetPhaseRelay(1);
				OpenPhase();
			}
			else
			{

//				SetPreDrvENH(0);
//				SetPreDrvINH(0);
//				SetPhaseRelay(0);
				ClosePhase();
				if(test_cnt_delay >= 200)
				{
					(void)DspiA4911Send(0x2C81u);
					(void)DspiA4911Send(0xE000u);//read diag 0
					(void)DspiA4911Send(0xE801u);//read diag 1
					(void)DspiA4911Send(0xF001u);//read diag 2
				}				
			}
        	
        }
			
	}
	else
	{

			Fv_TESTmode_CrlReqFlag = TESTMODE_FCTsLoopFlag;
//			SetPreDrvENH(0);
//			SetPreDrvINH(0);
//			SetPhaseRelay(0);
			ClosePhase();
			
			if(i == 0)
			{
//				datatmp[0] = (MDLINT16U)(((fsDataFromGn32[0] & 0x6000) >> 5) | ((fsDataFromGn32[0] & 0x0FF0) >> 4));
//				datatmp[1] = (MDLINT16U)(((fsDataFromGn32[1] & 0x40) << 3) | ((fsDataFromGn32[1] & 8) << 5)
//					| (fsDataFromGn32[3] & 0xF0) | (fsDataFromGn32[4] & 0x0F)) ;
				datatmp[2] = (MDLINT16U)(AD_PowerSys >> 1);
				datatmp[3] = (MDLINT16U)(AD_IgnitionSys >> 1);
				
				
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_T1].frez/10);	
				/*V1,V2,V3,F1*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;

				
				PutMsg_ECUTESTMODE(databuf);
				i =1;
			}
			else if(i == 1)
			{

				datatmp[0] = (MDLINT16U)(AD_TempSys >> 2);
				datatmp[1] = (MDLINT16U)test_dut1;
				datatmp[2] = (MDLINT16U)test_dut2;
				datatmp[3] = (MDLINT16U)test_dut3;
								
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_T2].frez/10);
				/*V5,V6,V7,V8,F2*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+1);
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;					
				
				
				PutMsg_ECUTESTMODE(databuf);
				i = 2;
			}
			else if(i == 2)
			{
				datatmp[0] = (MDLINT16U)(AD_SampFunCheck >> 2);
				datatmp[1] = 97;//(MDLINT16U)(AD_RotorSenPower >> 2);
				datatmp[2] = (MDLINT16U)(fsETimerCapInfo[Hella_T1].duty/10);
				datatmp[3] = (MDLINT16U)(fsETimerCapInfo[Hella_T2].duty/10);				
		
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_AP].frez/10);
				/*V9,V10,V11,V12,F3*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+2);

				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;					
				
				
				PutMsg_ECUTESTMODE(databuf);
				i = 3;
			}
			else if(i == 3)
			{
		
				datatmp[0] = (MDLINT16U)(fsETimerCapInfo[Hella_AP].duty/10);
				datatmp[1] = (MDLINT16U)(fsETimerCapInfo[Hella_AS].duty/10);
//				datatmp[2] = (MDLINT16U)(AD_RotorMainMid >> 2);
//				datatmp[3] = (MDLINT16U)((AD_RotorMainCos + 2048) >> 2);
					
				test_frez = (MDLINT8U)(fsETimerCapInfo[Hella_AS].frez/10);
				/*V13,V14,V15,V16,F4*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+3);
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;				

				
				PutMsg_ECUTESTMODE(databuf);
				i = 4;
			}
			else if(i == 4)
			{
//				datatmp[0] = (MDLINT16U)((AD_RotorMainSin + 2048) >> 2);
				datatmp[1] = (MDLINT16U)(AD_TorqueSenPower >> 2);
				datatmp[2] = 97;//(MDLINT16U)(AD_PowerRelaySys >> 2);
//				datatmp[3] = (MDLINT16U)(AD_I2D5Ref >> 2);
				
				/*V17,V18,V19,V20*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+4);

				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;

				
				PutMsg_ECUTESTMODE(databuf);
				i = 5;
			}
			else if(i == 5)
			{
				/*V21,V22,V23,V24,S1,S2,D1,D2*/
				

			 	test_tmp1 = 0;
			 	test_tmp2 = (MDLINT16U)(DspiA4911Send(0xFC80u));
				test_tmp2 = (MDLINT16U)(((test_tmp2 & 0x3FC0u) >> 2) | ((test_tmp2 & 0x001Eu) >> 1)); 

				test_frez = (((MDLINT8U)(Fv_SPITimeoutReq > 0)) << 7) |
//							(((MDLINT8U)(test_tmp1 == EEPROM_MAP_VERSION)) << 6) |
//				            (((MDLINT8U)(IO_PredriverState*2 + (IO_PshdriverState ^ 0x01))) << 4) |
				            ((MDLINT8U)((test_tmp2 >> 8) & 0x0Fu));
				
				Fv_SPITimeoutReq = 0;
				
				datatmp[0] = (MDLINT16U)(AD_InterVolt1d2 >> 2);
				datatmp[1] = (MDLINT16U)(TM_FCT_CurrentMid[0] / 30 + (MDLINT16S)((AD_PMSMCurrentU - 2000) >> 2));
				datatmp[2] = (MDLINT16U)(TM_FCT_CurrentMid[1] / 30 + (MDLINT16S)((AD_PMSMCurrentV - 2000) >> 2));
				datatmp[3] = (MDLINT16U)(TM_FCT_CurrentMid[2] / 30 + (MDLINT16S)((AD_PMSMCurrentW - 2000) >> 2));
				
				
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+5);
				
				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)((0xF0u&(datatmp[1] << 4))|(0x0Fu&(datatmp[2] >> 6)));//L4H4
				databuf[5] = (MDLINT8U)((0xFCu&(datatmp[2] << 2))|(0x03u&(datatmp[3] >> 8)));//L6H2
				databuf[6] = (MDLINT8U)(datatmp[3]);//L8;
				databuf[7] = test_frez;	
				
				PutMsg_ECUTESTMODE(databuf);
				i = 6;
			}
			else
			{

				test_tmp2 = (MDLINT16U)(DspiA4911Send(0xFC80u));
				test_tmp2 = (MDLINT16U)(((test_tmp2 & 0x3FC0u) >> 2) | ((test_tmp2 & 0x001Eu) >> 1));
				test_frez = (MDLINT8U)test_tmp2;
				
				datatmp[0] = (MDLINT16U)(AD_InterMCUTemp >> 2);
				datatmp[1] = 0;//(MDLINT16U)(AD_PowerRelaySys >> 2);

				/*V25,V26,D3*/
				databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
				databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1()+6);

				databuf[2] = (MDLINT8U)(datatmp[0] >> 2);//H8
				databuf[3] = (MDLINT8U)((0xC0u&(datatmp[0] << 6))|(0x3Fu&(datatmp[1] >> 4)));//L2H6
				databuf[4] = (MDLINT8U)(0xF0u&(datatmp[1] << 4));//L4H4
				databuf[7] = test_frez;
				
				
				PutMsg_ECUTESTMODE(databuf);
				i = 0;
		}
		
	
	}
}

/****************************************************************
* FUNCTION : TM_PowerOnTimesRecordProcess
* DESCRIPTION :  
* INPUTS : None
* OUTPUTS : None
****************************************************************/
static void TM_PowerOnTimesRecordProcess(void)
{
	static MDLINT8U PowerOn_First = 0;
	static MDLINT8U local_ct = 0;
	static MDLINT8U local_en = 0;
	static MDLINT8U local_ex = 0;
	
		local_ex++;
		if((local_ex <= 200)&&(testmode_req != 0xAA))
		{
			static UInt16 i = 0;
			i++;
			if(i == 200)
			{
				i = 200;
				fsTestModeInhibit = TRUE;
			}
		  	
		}
		else
		{
			local_ex = 200;
		}
		
		if(testmode_req == 0xaa)
		{
			//testmode_req = 0;
			local_ct++;
			if(local_ct >= 4)
			{
				local_ct = 4;
				local_en = 1;
			}
		}
		else
		{
		
		}
		
		
		if((local_en)&&(!fsTestModeInhibit)&&(Fv_SystemCANReciveStatus[CANBUS_ABSVs]== 0)/*&&(Fv_SystemCANReciveStatus[CANBUS_EMSEs] == 0)&&(fsPowerOnTimesRecord <= 6)*/)
		{
			Fv_TESTmodeFun_GlbFlag = TRUE;
			
//			BridgePrechargeFun(FALSE);
//			PredriverViceCtrlFun(FALSE);

			SysTaskPhaseDiagStepIndex = InitDiagStep_Default;
#if T212L_TESTMODE
			GTM_TOM1_TGC0_OUTEN_CTRL.U = 0x0000AAAA;
			GTM_TOM1_TGC0_OUTEN_STAT.U = 0x0000AAAA;
#else
			SetFlexPWMA_OUTEN(PWM123_OUTEN);
			SetFlexPWMB_OUTEN(PWM123_OUTEN);
#endif
		}

}

void TM_AssemblyTorqueFeedback(MDLINT8U enabled)
{
   if(enabled)
   {
   	
		MDLINT16U datamid[3] = {0xFFFF,0xFFFF,0xFFFF};
		MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		MDLINT16U datatmp = 0;
		static MDLINT8U i = 0;

		
		Fv_TESTmode_CrlReqFlag = TESTMODE_ZeroLoopFlag;
		fsOpenloopUQ=0;
		fsOpenloopUD=0;
		fsOpenloopS1=0;//20
		fsOpenloopS2=0;//1,spd=s1/s2
		fsOpenloopSa=0;
		
		datatmp    = (MDLINT16U)(((MDLINT16S)(IOC_Tor1Duty - IOC_Tor2Duty)) / 2 + 5000);
		datamid[0] = datatmp;
		datamid[1] = datatmp;
		datamid[2] = datatmp;

		databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
		databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
		databuf[2] = (MDLINT8U)(datamid[2] >> 8);
		databuf[3] = (MDLINT8U)(datamid[2]);
		databuf[4] = (MDLINT8U)(datamid[1] >> 8);
		databuf[5] = (MDLINT8U)(datamid[1]);
		databuf[6] = (MDLINT8U)(datamid[0] >> 8);
		databuf[7] = (MDLINT8U)(datamid[0]);
		PutMsg_ECUTESTMODE(databuf);   	
   	
   }	
}
/*閿熻緝浼欐嫹閿熷�熷閿熸枻鎷烽敓鏂ゆ嫹杞ā寮�    20210927  by  wangtingwei*/
static void TM_AGING_TEST_CHECK_Func(void)
{
	static uint8 i =0;

	Fv_TESTmodeFun_GlbFlag = TRUE;

	Fv_TESTmode_CrlReqFlag = TESTMODE_OpenLoopFlag;

	fsOpenloopUQ= 850;
	fsOpenloopUD=0;
	fsOpenloopS1= 8;
	fsOpenloopS2=2;//1,spd=s1/s2

	fsOpenloopSa=0;//2048->3pi/6,6144->9pi/6
	if(i < 1)
	{
		OpenRelay();
		i++;
	}
	else
	{

		if(i <= 2)
		{
			i++;
			SysTaskFocResetPending = TRUE;
			SysTaskFocResetTrgPending1 = TRUE;
			SysTaskFocResetTrgPending2 = TRUE;
		}
		else
		{
			SysTaskFocResetPending = FALSE;
			SysTaskFocResetTrgPending1 = FALSE;
			SysTaskFocResetTrgPending2 = FALSE;
			OpenPhase();
			OpenPredrive();
		}

	}
	SysTaskCurrentSmpPending1 = TRUE;
	SysTaskCurrentSmpPending2 = TRUE;
	SysTaskResolverSmpPending = TRUE;
}
		
static void TM_CALIB_DATA_CHECK_Func(void)
{
	MDLINT8U databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

	databuf[0] = (MDLINT8U)(IlGetRxTestModeRequest0());
	databuf[1] = (MDLINT8U)(IlGetRxTestModeRequest1());
	databuf[2] = ((Fv_ErrDiagStatus[DTC_CURRENTcheck_IcalibInvalid] > FailureDiag_RegOK)
	            |((Fv_ErrDiagStatus[DTC_EEPROMcheck_CommTimeout] == FailureDiag_InitErr)<<1));
	databuf[3] = fsCalibFaultClass;
	databuf[4] = (Fv_ErrDiagStatus[DTC_MOTORcheck_PhaseOpen] > FailureDiag_RegOK);
	databuf[5] = 0;
	databuf[6] = 0;
	databuf[7] = 0;

	PutMsg_ECUTESTMODE(databuf);
}

		
      
#endif
