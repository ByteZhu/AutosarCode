/*
 * common.c
 *
 *  Created on: 2024��5��22��
 *      Author: Administrator
 */
#include "common.h"
#include "SimDiagMacroCAN.h"


volatile uint8 Fv_TCAN1145Sleep = 0;
volatile uint8 Fv_TPS653852GoToSleep = 0;
volatile boolean Tx_Stop_flag = FALSE;
volatile uint8 CANTP_Last_frame = 0;
GLOBAL Int16 fsMotorCtrlVoltage = 0;

GLOBAL Int16 fsMotor_PWMdz_U = 0;
GLOBAL Int16 fsMotor_PWMdz_V = 0;
GLOBAL Int16 fsMotor_PWMdz_W = 0;

tag_Calibration_Datas fsCalibrationData;

GLOBAL Int16 fsMotorCurrentGain[6] = { 250, 250, 250, 250, 250, 250 };

GLOBAL Int16 AD_MotorCurrentU[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_MotorCurrentV[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_MotorCurrentW[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

GLOBAL Int16 AD_RotorCosCorrect[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_RotorSinCorrect[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

GLOBAL Int16 AD_RotorCosOffsetMax[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_RotorSinOffsetMax[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_RotorCosOffsetMin[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_RotorSinOffsetMin[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

GLOBAL Int16 AD_RotorPhasePlusMax[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_RotorPhaseMinusMax[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_RotorPhasePlusMin[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
GLOBAL Int16 AD_RotorPhaseMinusMin[PreDriver_Num] = {0,}  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

GLOBAL Int32 debug_jing[4];
GLOBAL Int32 debug_jing1;
GLOBAL Int32 debug_jing2;
GLOBAL Int32 debug_jing3;
GLOBAL Int32 debug_jing4;

GLOBAL Int16 fsSIN6 = 0;
GLOBAL Int16 fsCOS6 = 0;

GLOBAL Int32 fsTestCurrentAim = 0;
GLOBAL Int32 fsTestSpeedAim = 0;

GLOBAL Int32 fscomp_current_iq = 0;
GLOBAL Int32 fscomp_current_id = 0;

GLOBAL Int32 fscomp_voltage_rd = 0;
GLOBAL Int32 fscomp_voltage_rq = 0;
GLOBAL Int32 fscomp_voltage_id = 0;
GLOBAL Int32 fscomp_voltage_iq = 0;
GLOBAL Int32 fscomp_voltage_ed = 0;
GLOBAL Int32 fscomp_voltage_eq = 0;

GLOBAL Int32 fsOpenloopUQ = 0;
GLOBAL Int32 fsOpenloopUD = 0;
GLOBAL Int16 fsOpenloopS1 = 0;
GLOBAL Int16 fsOpenloopS2 = 0;
GLOBAL Int16 fsOpenloopSa = 0;

GLOBAL Int32 fsShuntCurrentAct = 0;

const Int32 fsMotorMaxFocCurrentQ = 19200;//2^-7,150A
const Int32 fsMotorMaxFocCurrentQHalf = 9600;//2^-7,75A
const Int32 fsMotorIdfwCurrentLimit = 11250;/*2^0,150A^2/2*/
const Int32 fsMotorIdfwCurrentLimitHalf = 5625; /*2^0,150A^2/4*/
const Int32 fsMotorKnockProtectI = 3200;//2^-7,25A
const Int16 fsMotorCurrentMax = 22400;/* conv:2^-7A ,= fsMotorMaxFocCurrentQ + 25A*/
const Int16 fsMotorCurrentMax2 = 22400;/* conv:2^-7A ,= fsMotorMaxFocCurrentQ + 25A*/
const Int32 fsMotorUqLimitBaseVol = 2822;
const Int32 fsMotorIdfwCurrentMaxHalf = -19200;
/***************�����Ȳ���**********************/
// const UInt16 fsMotorSteerToRpm = 3584;/*2^-10,21*60/360*/
// const UInt16 fsMotorRotorToSteer = 1397;//2^-9,180/pi/21
const UInt16 fsMotorSteerToRpm = 4795;/*2^-10,28*60/360*/
const UInt16 fsMotorRotorToSteer = 1044;//2^-9,180/pi/28  //mod by liuyang

/***************Ť�˸նȲ���**********************/
const UInt16 fsStrTrqSNRCoef = 262;/* conv:2^-17Nm , val: 2.5Nm/�� */
const UInt16 fsMotorPidOutModulation = 1182;
const UInt16 fsAvPowerRelayScale = 420;

GLOBAL uint8 fsPredriver_EnableStatus = 0;
GLOBAL uint16 fsFaultClass_Predriver = 0;
GLOBAL uint16 fsFaultClass_Predriver_extral = 0;

GLOBAL UInt16 AD_PMICAmux = 0;
GLOBAL UInt16 AD_CutOffVCP = 0;
GLOBAL UInt16 AD_TempSys2 = 0;
uint8 testData[30]={0};
GLOBAL Int32 Fv_LowRev_spd = 0 /* LSB: 2^-10 OFF:  0 MIN/MAX:  -300 .. 300 */;

#if defined(ENABLE_DOUBLE_P_SIGNAL_CALCUL_ANGLE)
volatile UInt16 IOC_AngpDuty1;
volatile UInt16 IOC_AngpDuty2;
volatile uint16 Sent_APSentToPwm2 = 0;
#endif

const uint8_T DTCErrDebounceTmrCntCnStart[EPS_DTC_NUM_MAX]= {0,};
uint8_T DTCErrDebounceTmrCnt [EPS_DTC_NUM_MAX] = {0,};

/* Replace New lab file */
volatile Float64 Fv_FirCof_TorqueRobus_Param[4];








volatile uint8 ModeDeclaration_true;
volatile uint8 NRC_22_timecounter=0;
volatile uint8 Can_NM_tx_flag=0;
volatile uint8 Can_busoffrecover=0;
volatile uint8 Can_secoc_pr=0;
//volatile uint8 Fv_TCAN1145Sleep = 0;
//volatile uint8 Fv_TPS653852GoToSleep = 0;
//volatile uint32 Fv_ErrorFromGn32 = 0;
volatile uint8 TEST_00[8]={0,};

volatile uint8 TestMode_RequestData[8] = {0,};

GLOBAL UInt16 fs_testmode_rc = 0;
GLOBAL UInt8 fsTESTmodeFun_TrqTransEnabled = 0;
GLOBAL UInt8 fsSPI_Communication_Status = 0;
GLOBAL UInt8 fsTestModeInhibit = 0;
GLOBAL UInt16 fsCalibFaultClass = 0;
GLOBAL UInt8 fsTESTmode_ResetFlag = 0;
GLOBAL UInt8 fsPowerOnTimesRecord = 0;

tag_eTIMER_CapInfo fsETimerCapInfo[6] = {{0},};

GLOBAL UInt8 fsGblCALWriteFlag = 0;
GLOBAL UInt8 fsGblINFOWriteFlag = 0;
uint8 testmode_req = 0;



volatile Float64 Fv_FirCof_TorqueSoftAdv2_Param[2] = {0, 0};
volatile Float64 Fv_FirCof_TorqueSoftAdv_Param[2] = {0, 0};

volatile UInt8 Fv_PowerMode;
volatile UInt8 Fv_CarMode;

volatile UInt16 Fv_Ws_Flws_raw;
volatile UInt16 Fv_Ws_Frws_raw;
volatile UInt16 Fv_Ws_Rlws_raw;
volatile UInt16 Fv_Ws_Rrws_raw;
volatile Int16 Fv_YawRate_Raw;
volatile Int16 Fv_VechYawRate = 0;
volatile UInt8 Tv_SE_EndStoredFlag;
volatile Bool SysTaskFocResetPending;
volatile ASS_TYPE Fv_STOREAssistSelectMode;
volatile Int16 Fv_FriCompAdptiveTorqueLast;
volatile Int16 Fv_AngleCorrectOprLast;
volatile Bool Fv_AOC_Configuration;
volatile Int16 Fv_TOCLongStyTrqLast;
volatile Int32 Fv_MotorVoltage_D;
volatile Int32 Fv_MotorVoltage_Q;
volatile Int32 Fv_MotorVoltage_Alpha;
volatile Int32 Fv_MotorVoltage_Beta;

GLOBAL UInt8 fsRCS_BCMAllowed = 0;
GLOBAL Int16 fsVechYawRate = 0;
GLOBAL UInt8 fsSFSModeResetReq = 0;
GLOBAL UInt8 fsSFSSetForbidCond = 0;
GLOBAL UInt8 fsSMSSetForbidCond = 0;
GLOBAL UInt8 fsATSSetForbidCond = 0;
GLOBAL UInt8 fsSFSSetSafetyCond = 0;
GLOBAL UInt8 fsOffOnResetFlag = 0;
GLOBAL UInt16 fsDataFromGn32[12] = {0,};
GLOBAL UInt8 fsLKATurnCurveSel = 0;
GLOBAL UInt8 fsEPSCloseLoopCtrlFlag = 0;
GLOBAL UInt8 fsSFSFuncCfg = 0;
GLOBAL UInt8 fsSMSFuncCfg = 0;
GLOBAL UInt8 fsLKATCFuncCfg = 0;
GLOBAL UInt8 fsLKAACFuncCfg = 0;
GLOBAL UInt8 fsADASTCFuncCfg = 0;
GLOBAL UInt8 fsRCSFuncCfg = 0;
GLOBAL UInt8 fsATSFuncCfg = 0;
GLOBAL UInt8 fsDSTFuncCfg = 0;
GLOBAL UInt8 fsLDWFuncCfg = 0;
GLOBAL UInt8 fsAPAFuncCfg = 0;
GLOBAL UInt8 fsVOTFuncCfg = 0;
GLOBAL UInt8 fsSACFuncCfg = 0;
GLOBAL UInt8 fsVeh_TuneFuncCfg = 0;
GLOBAL UInt8 fsVehSpdSignalInValid = 0;
uint8 Read_DTC_IgnitCycle_Tab[EPS_DTC_NUM_MAX];

GLOBAL RCSAllowSts fsIKEYControlAllow = RCSAllowSts_Fbd;
GLOBAL GearStatus fsSCUGearPosion = 0;
GLOBAL RemoteDriveCmd fsIKeyDriveCmd = 0;
volatile UInt8 Fv_EXT_CarMode;
volatile UInt8 Fv_EXT_CarModeReq;
volatile UInt8 Fv_EXT_UsageMode;
volatile UInt8 Fv_EXT_UsageModeReq;

volatile FailureDiag fsSystemEEPROMDiagStatus[4] = {0,};

GLOBAL Int16 fsInitRotorAngleCorrect;

GLOBAL UInt16 fsSystemCANReciveCounter[CAN_SIGNAL_NUM] = {0,};

const UInt16 fsSystemCANDiagTimes[CAN_SIGNAL_NUM] = {0,
                                        MACRO_CAN_LOSTTIME_ABSVs,MACRO_CAN_LOSTTIME_ABSWs,
                                        MACRO_CAN_LOSTTIME_IPB2,MACRO_CAN_LOSTTIME_IPB5,
                                        MACRO_CAN_LOSTTIME_IPB6,MACRO_CAN_LOSTTIME_CCU3,
                                        MACRO_CAN_LOSTTIME_CCU2,MACRO_CAN_LOSTTIME_VCU3,
                                        MACRO_CAN_LOSTTIME_ADS2,MACRO_CAN_LOSTTIME_ADS1,
                                        MACRO_CAN_LOSTTIME_APA,MACRO_CAN_LOSTTIME_SCU,
                                        MACRO_CAN_LOSTTIME_BCM2,MACRO_CAN_LOSTTIME_CCU1,
                                        MACRO_CAN_LOSTTIME_BCM3,MACRO_CAN_LOSTTIME_IPB3,
                                        MACRO_CAN_LOSTTIME_IPB4,MACRO_CAN_LOSTTIME_IPB7};

volatile UInt8 Fv_CANCCP1;
volatile UInt8 Fv_CANCCP3;
volatile UInt8 Fv_CANCCP13;
volatile UInt8 Fv_CANCCP16;
volatile UInt8 Fv_CANCCP17;
volatile UInt8 Fv_CANCCP50;
volatile UInt8 Fv_CANCCP57;
volatile UInt8 Fv_CANCCP58;
volatile UInt8 Fv_CANCCP59;/*new*/
volatile UInt8 Fv_CANCCP62;
volatile UInt8 Fv_CANCCP100;/*new*/
volatile UInt16 Fv_CANCCP142;/*new*/
volatile UInt8 Fv_CANCCP150;
volatile UInt8 Fv_CANCCP316;
volatile UInt8 Fv_CANCCP317;
volatile UInt8 Fv_CANCCP494;
volatile UInt8 Fv_CANCCP540;/*new*/
volatile UInt8 Fv_CANCCP547;/*new*/
volatile UInt8 Fv_CANCCP565;
volatile UInt8 Fv_CANCCP609;/*new*/
volatile UInt8 Fv_CANCCP639;
volatile UInt8 Fv_CANCCP640;
volatile UInt8 Fv_CANCCP655;/*new*/
volatile UInt8 Fv_CANCCP695;/*new*/
volatile UInt8 Fv_CANCCP741;/*new*/
volatile UInt8 Fv_CANCCPbulk_state;
volatile UInt16 Fv_SWP2_TS;
volatile UInt16 Fv_SWP2_TS1;
volatile uint8 fsDtcTestfailed[16] = {0,};
volatile sint16 fsYawRateCompensated;
volatile sint16 fsRawYawRateComp;
volatile sint16 fsYawRateWithComp;
volatile uint8 fsAsyDataWithCmpSafeValid;
volatile Int16 Tv_FriCompAdptiveTorque;
volatile Bool Fv_AOC_StraightFlag;
volatile uint8 Fv_DualPSCMFallBackWarningReq;
volatile uint64 G_timestamp = 0;

/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void AssistModeStored(void)
{
	if(0 != ((sint8)Fv_STOREAssistSelectMode - (sint8)Fv_RUNAssistSelectMode))
	{
		Fv_STOREAssistSelectMode = Fv_RUNAssistSelectMode;
		NvM_StoreRequest.bit.AngCorrectStoredReq = 1;
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void StrAngZeroStored(void)
{

	Fv_StrAngOffset = Tv_StrAng;
	//rtTAS_DataConv_Ang_ARID_DEF_TAS.strangoffset = Fv_StrAngOffset;
	Fv_AngleMidValidFlag = ANGLE_STS_Calibrating;

	fsCalibrationData.data.anglezero.a0 = Tv_StrAng;
	NvM_StoreRequest.bit.StrAngZero = 1;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void StrAngZeroRemoved(void)
{
	Fv_AngleMidValidFlag = ANGLE_STS_Invalid;
	Fv_StrAngOffset = 0;
	fsCalibrationData.data.anglezero.a0 = 0;
	NvM_StoreRequest.bit.StrAngZero = 1;

#if 1
	Fv_AngleEndValidFlag = ANGLE_STS_Invalid;
	fsCalibrationData.data.anglezero.ar = 0;
	fsCalibrationData.data.anglezero.al = 0;
	Tv_SE_LeftMaxAng = 0;
	Tv_SE_RightMaxAng = 0;
#if 0
	rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_LeftMaxAng = 0;
	rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_RightMaxAng = 0;
#endif
	Tv_SE_EndStoredFlag = FALSE;
	NvM_StoreRequest.bit.AngEndCalDataReq = 1;
#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void StrAngEndCalDataReq(void)
{
	if((Tv_SE_EndStoredFlag == FALSE) && (Fv_AngleEndValidFlag == ANGLE_STS_Invalid))
	{
#if 0
		fsCalibrationData.data.anglezero.al = -rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_LeftMaxAng;
		fsCalibrationData.data.anglezero.ar = rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_RightMaxAng;
		Tv_SE_LeftMaxAng = rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_LeftMaxAng;
		Tv_SE_RightMaxAng = rtBSS_SteeringEnd_ARID_DEF_BSS_.Tv_SE_RightMaxAng;
#else
		fsCalibrationData.data.anglezero.al = -Tv_SE_LeftMaxAng;
		fsCalibrationData.data.anglezero.ar = Tv_SE_RightMaxAng;
#endif
		Tv_SE_EndStoredFlag = TRUE;

		NvM_StoreRequest.bit.AngEndCalDataReq = 1;	
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void AngleCorrectStoredReq(void)
{
    if((Fv_TOCLongStyTrqLast != Fv_TOCLongStyTrq)&&(Fv_TOCLongFuncFbd == 0)&&(Fv_TOCSTCFbd == 0))
    {
        Fv_TOCLongStyTrqLast = Fv_TOCLongStyTrq;
        NvM_StoreRequest.bit.CommonCRCStored = 1;
    }

    if((Fv_AngleCorrectOprLast != Fv_AngleCorrectOpr) && (Fv_AOC_Configuration > 0))
    {
        Fv_AngleCorrectOprLast = Fv_AngleCorrectOpr;
        NvM_StoreRequest.bit.CommonCRCStored = 1;
    }

    if((Fv_FriCompAdptiveTorqueLast != Fv_FriCompAdptiveTorqueTemp))
    {
        Fv_FriCompAdptiveTorqueLast = Fv_FriCompAdptiveTorqueTemp; //mod by liuyang
        NvM_StoreRequest.bit.CommonCRCStored = 1;

    }

}

int16_T GetSinTableValue(uint16_T v)
{
    if(v > 8192)
    {
       v = 8192;
    }

    return PMSM_Angle_Sin_Table[v];
};

/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
#include "IfxScu_reg.h"
void EXT_ServiceCpuDog(void)
{
  unsigned short cpuWdtPassword;
  cpuWdtPassword = Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[0]);
  Ifx_Ssw_serviceCpuWatchdog(&MODULE_SCU.WDTCPU[0], cpuWdtPassword);
}

unsigned short WatchDogtimeoutFlag(void)
{
  unsigned short timeoutfalg=0;
  timeoutfalg = MODULE_SCU.WDTCPU[0].SR.B.TO;//Watchdog Time-Out Mode Flag
  return timeoutfalg;
}







