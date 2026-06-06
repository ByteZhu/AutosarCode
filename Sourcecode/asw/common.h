/*
 * common.h
 *
 *  Created on: 2024閿熸枻鎷�5閿熸枻鎷�22閿熸枻鎷�
 *      Author: Administrator
 */

#ifndef SOURCECODE_ASW_COMMON_H_
#define SOURCECODE_ASW_COMMON_H_

#include "Std_Types.h"
#include "rtwtypes.h"
#include "globaltables.h"
#include "CalVar.h"
#include "CalVar.h"
#include "GlobalVar.h"
#include "GlobalVarSupport.h"
#include "IoHwAb.h"
#include "portability.h"
#include "Motor.h"
#include "SimDiagMacro.h"
#include "ASW_NVM.h"
#include "GlobalVarCAN.h"
#include "GlobalVar_EXT.h"

typedef unsigned char         MDLBOOL;                 /* UnSigned  8 bit quantity  */
typedef unsigned char         MDLINT8U;                /* UnSigned  8 bit quantity  */
typedef signed   char         MDLINT8S;                /* Signed    8 bit quantity  */
typedef unsigned short  int	  MDLINT16U;               /* Unsigned  16 bit quantity */
typedef signed   short  int   MDLINT16S;               /* Signed    16 bit quantity */
typedef unsigned long   int   MDLINT32U;               /* Unsigned  32 bit quantity */
typedef signed   long   int   MDLINT32S;               /* Signed    32 bit quantity */

#define GLOBAL  volatile

enum
{
	CUR_CALIB = 0,
  ANGI_CALIB,
  ANGZ_CALIB,
  ANGE_CALIB,
};

enum
{
    PreDriver_01,
    PreDriver_02,
    PreDriver_Num
};

enum
{
	Hella_AP = 0,
	Hella_AS = 1,
	Hella_T1 = 2,
	Hella_T2 = 3
};

typedef enum
{
	RCSAllowSts_Fbd = 0,
	RCSAllowSts_Alw,
}RCSAllowSts;

typedef enum
{
	GearStatus_NoAct = 0,
	GearStatus_P,
	GearStatus_R,
	GearStatus_N,
	GearStatus_D,
	GearStatus_LOST,

}GearStatus;

typedef enum
{
	RemoteDriveCmd_Invalid = 0x0,
	RemoteDriveCmd_StartOff = 0x1,
	RemoteDriveCmd_Err = 0x3,
	RemoteDriveCmd_Forward = 0x4,
	RemoteDriveCmd_Backward = 0x5,
	RemoteDriveCmd_TurnLeft = 0x6,
	RemoteDriveCmd_TurnRight = 0x7,
	RemoteDriveCmd_ForwardLeft = 0x8,
	RemoteDriveCmd_ForwardRght = 0x9,
	RemoteDriveCmd_BackwardLeft = 0xA,
	RemoteDriveCmd_BackwardRght = 0xB,
	RemoteDriveCmd_Warning = 0xC,
	RemoteDriveCmd_Error2 = 0xF,

}RemoteDriveCmd;

typedef struct
{
	UInt16 i[3];
	UInt16 rsv;//resolver sin&cos gain
	UInt8  bat;//battery voltage difference
	UInt8  nmt;//normal temperature
	UInt8  ic[3];
	UInt8  hgt;//high temperature
	UInt8  rfu;
	UInt8  crc;
}tag_CalibGainOffs_Data;

typedef struct
{
	UInt16 a0;
	UInt16 al;
	UInt16 ar;
	UInt8  st;
	UInt8  crc;
}tag_CalibAngle_Data;

typedef struct
{
	UInt16 a0crr;
	UInt16 rtrofs;
	UInt8  rfu[3];
	UInt8  crc;
}tag_CalibAngleCorrect_Data;

typedef union
{
  	UInt8  byte[32];
  	UInt16 word[16];
	struct
	{
		tag_CalibGainOffs_Data 		gainoffset;
		tag_CalibAngle_Data    		anglezero;
		tag_CalibAngleCorrect_Data  anglecorrect;
	}data;
} tag_Calibration_Datas;

typedef struct
{
	UInt32 duty;
	UInt32 frez;
	UInt32 cap1;
	UInt32 cap2;
	UInt32 overcnt;
}tag_eTIMER_CapInfo;

typedef struct _c_PSCM_IDS_msgTypeTag
{
	uint8 IDPSSEvFromPSCMProtocol : 8;
	uint8 IDPSSEvFromPSCMIDSID_00 : 8;
	uint8 IDPSSEvFromPSCMIDSID_01 : 8;
	uint8 IDPSSEvFromPSCMIDSID_02 : 8;
	uint8 IDPSSEvFromPSCMIDSID_03 : 8;
	uint8 IDPSSEvFromPSCMCount_00 : 8;
	uint8 IDPSSEvFromPSCMCount_01: 8;
	uint8 IDPSSEvFromPSCMReserve : 8;
	uint8 IDPSSEvFromPSCMTimestamp_00 : 8;
	uint8 IDPSSEvFromPSCMTimestamp_01 : 8;
	uint8 IDPSSEvFromPSCMTimestamp_02 : 8;
	uint8 IDPSSEvFromPSCMTimestamp_03 : 8;
	uint8 IDPSSEvFromPSCMTimestamp_04 : 8;
	uint8 IDPSSEvFromPSCMTimestamp_05 : 8;
	uint8 IDPSSEvFromPSCMTimestamp_06 : 8;
	uint8 IDPSSEvFromPSCMTimestamp_07 : 8;
	uint8 IDPSSEvFromPSCMContextDataLength : 8;
	uint8 IDPSSEvFromPSCMContextData1_00 : 8;
	uint8 IDPSSEvFromPSCMContextData1_01 : 8;
	uint8 IDPSSEvFromPSCMContextData1_02 : 8;
	uint8 IDPSSEvFromPSCMContextData1_03 : 8;
	uint8 IDPSSEvFromPSCMContextData1_04 : 8;
	uint8 IDPSSEvFromPSCMContextData1_05 : 8;
	uint8 IDPSSEvFromPSCMContextData1_06 : 8;
	uint8 IDPSSEvFromPSCMContextData1_07 : 8;
	uint8 IDPSSEvFromPSCMContextData2_00 : 8;
	uint8 IDPSSEvFromPSCMContextData2_01 : 8;
	uint8 IDPSSEvFromPSCMContextData2_02 : 8;
	uint8 IDPSSEvFromPSCMContextData2_03 : 8;
	uint8 IDPSSEvFromPSCMContextData2_04 : 8;
	uint8 IDPSSEvFromPSCMContextData2_05 : 8;
	uint8 IDPSSEvFromPSCMContextData2_06 : 8;
	uint8 IDPSSEvFromPSCMContextData2_07 : 8;
	uint8 Reserve1 : 8;
	uint8 Reserve2 : 8;
	uint8 Reserve3 : 8;
	uint8 Reserve4 : 8;
	uint8 Reserve5 : 8;
	uint8 Reserve6 : 8;
	uint8 Reserve7 : 8;
	uint8 Reserve8 : 8;
	uint8 Reserve9 : 8;
	uint8 Reserve10 : 8;
	uint8 Reserve11 : 8;
	uint8 Reserve12 : 8;
	uint8 Reserve13 : 8;
	uint8 Reserve14 : 8;
	uint8 Reserve15 : 8;

} _c_EPS_PSCM_IDS_msgType;
typedef union _c_PSCM_IDS_bufTag
{
	uint8 _c[48];
	_c_EPS_PSCM_IDS_msgType PSCM_IDS_Response;
} _c__PSCM_IDS_buf;
typedef struct
{
	const MDLINT8U		MaxIgnitCycle;		/* maximum ignition cycle to clear DTC */
	const MDLINT8U      Priority;           /* DTC priority */
	const MDLINT8U		Num;
} DTC_Code_Str;

#define MACRO_RAD2RPM                  1222U                     /* conv:2^-7rpm/(rad/s) , val:9.5493 , min-max:8~10 */
#define TESTMODE_CurrentLoopFlag 					0x7F3Du
#define TESTMODE_SpeedLoopFlag 		    	        0x9B2Cu
#define TESTMODE_OpenLoopFlag    					0x6B5Au
#define TESTMODE_ZeroLoopFlag    					0x0001u
#define TESTMODE_FCTsLoopFlag    			        0x3180u
#define MACRO_MAC_IDFW_CURRENT_BK_MAX  0
#define MACRO_POWER_STANDARDVOL        1600                      /* conv:2^-7V , val:12.5 , min-max:0~20 */
#define MACRO_POWER_STANDARDCEF                     (Int16)(40)
#define MACRO_ROTOR2STEER              fsMotorRotorToSteer
#define MACRO_TP_BRIDGEWORK			1024

#define MACRO_AV_POWERRELAY_SCALE fsAvPowerRelayScale

#define DTCErrDebounceTmrCntCnstr	DTCErrDebounceTmrCntCnStart

#define MACRO_CURRENT_AMP        					(Int16)-250//2^-10
#define MACRO_MBC_ONESQRTTHIRD      (UInt16)18919 /* 0.57735 2^-15*/
#define MACRO_MBC_ONETHIRD          (UInt16)10923//2^-15
#define MACRO_MBC_PID_LIMIT_PCR     (Int16)128/*128//2^-7,110,86%,116,90%,max duty 95%*/
#define DIAGMASK_MODULE1                    0x5555U
#define DIAGMASK_MODULE2                    0xAAAAU

#define _On8int(v)                          (UInt8)((v>>3)<<3)
#define _On8mod(v)                          (UInt8)(v - _On8int(v))

#define PMSM_FOC_Sqrt_U     TAB_PMSM_FOC_Sqrt_U

#define _SetU16Varit(v, w)	(v |= (UInt16)(1 << w))

#define _ClrU16Varit(v, w)	(v &= (~(UInt16)(1 << w)))

#define _SetU32Varit(v, w)	(v |= (UInt32)(1 << w))

#define SetU16Fault(v, w, e) (v |= (UInt16)((1*e) << w))
#define SetU16Varit(v, w)    _SetU16Varit(v, w)
#define ClrU16Varit(v, w)   _ClrU16Varit(v, w)
#define SetU32Fault(v, w, e) (v |= (UInt32)((1*e) << w))

#define SetEEstoreChn(v)

#define SetEEstoreChn_AngleEndCalData()

#define SetThresholdVPT1(v)

#define SetThresholdVPT2(v)

#define PredriverViceCtrlFun(v)	(SysTaskViceShutDriverPending = v)

#define Gtm_SetPwmValue_50per1()

#define Gtm_SetPwmValue_50per2()

#define ANGLE_LEFT_CALIB    				(Int16)(fsCalibrationData.data.anglezero.al)
#define ANGLE_RIGHT_CALIB   				(Int16)(fsCalibrationData.data.anglezero.ar)
#define ANGLE_CORRT_CALIB   				(Int16)(fsCalibrationData.data.anglecorrect.a0crr)
#define ANGLE_VALID_ZERO()				    (UInt8)((fsCalibrationData.data.anglezero.st&0x01) == 0)
#define ANGLE_VALID_LEFT()  				(UInt8)((fsCalibrationData.data.anglezero.st&0x04) == 0)
#define ANGLE_VALID_RIGHT() 				(UInt8)((fsCalibrationData.data.anglezero.st&0x02) == 0)
#define ANGLR_VALID_END()                   (UInt8)((fsCalibrationData.data.anglezero.st&0x06) == 0)
#define ANGLE_ZERO_CALSTATUS  				(UInt8)((ANGLE_VALID_ZERO())&(Fv_AngleMidValidFlag != ANGLE_STS_Invalid))
#define AssistModeStoreRequest()			AssistModeStored();
#define get_GET_ANGLR_VALID_END 		ANGLR_VALID_END
#define TOCDataStoredRequest()

#define BOOTLOADER_DATA_LENGTH 5U
#define BOOTLOADER_DATA_ADDR   0x10000U

#define MACRO_CAN_LOSTTIME_EMSEs		MACRO_CAN_LOSTTIME_CCU3

#define MACRO_FC_STRAIGHTCOND		1

#define CAN_SIGNAL_NUM CANBUS_NUM

extern volatile uint8 Fv_TCAN1145Sleep;
extern volatile uint8 Fv_TPS653852GoToSleep;
extern volatile boolean Tx_Stop_flag;
extern volatile uint8 CANTP_Last_frame;
extern GLOBAL Int16 fsMotorCtrlVoltage;

extern GLOBAL Int16 fsMotor_PWMdz_U;
extern GLOBAL Int16 fsMotor_PWMdz_V;
extern GLOBAL Int16 fsMotor_PWMdz_W;

extern tag_Calibration_Datas fsCalibrationData;

extern GLOBAL Int16 fsMotorCurrentGain[6];

extern GLOBAL Int16 AD_MotorCurrentU[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_MotorCurrentV[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_MotorCurrentW[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

extern GLOBAL Int16 AD_RotorCosCorrect[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_RotorSinCorrect[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

extern GLOBAL Int16 AD_RotorCosOffsetMax[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_RotorSinOffsetMax[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_RotorCosOffsetMin[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_RotorSinOffsetMin[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

extern GLOBAL Int16 AD_RotorPhasePlusMax[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_RotorPhaseMinusMax[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_RotorPhasePlusMin[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;
extern GLOBAL Int16 AD_RotorPhaseMinusMin[]  /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1024 */;

extern GLOBAL Int32 T212L_MotorInialAngle;
extern GLOBAL Int16 fsInitRotorAngleCorrect;
extern uint8 testData[30];
extern GLOBAL Int32 debug_jing[4];
extern GLOBAL Int32 debug_jing1;
extern GLOBAL Int32 debug_jing2;
extern GLOBAL Int32 debug_jing3;
extern GLOBAL Int32 debug_jing4;

extern GLOBAL Int16 fsSIN6;
extern GLOBAL Int16 fsCOS6;

extern GLOBAL Int32 fsTestCurrentAim;
extern GLOBAL Int32 fsTestSpeedAim;

extern GLOBAL Int32 fscomp_current_iq;
extern GLOBAL Int32 fscomp_current_id;

extern GLOBAL Int32 fscomp_voltage_rd;
extern GLOBAL Int32 fscomp_voltage_rq;
extern GLOBAL Int32 fscomp_voltage_id;
extern GLOBAL Int32 fscomp_voltage_iq;
extern GLOBAL Int32 fscomp_voltage_ed;
extern GLOBAL Int32 fscomp_voltage_eq;

extern GLOBAL Int32 fsOpenloopUQ;
extern GLOBAL Int32 fsOpenloopUD;
extern GLOBAL Int16 fsOpenloopS1;
extern GLOBAL Int16 fsOpenloopS2;
extern GLOBAL Int16 fsOpenloopSa;

extern GLOBAL Int32 fsShuntCurrentAct;

extern const Int32 fsMotorMaxFocCurrentQ;//2^-7,75A
extern const Int32 fsMotorMaxFocCurrentQHalf;
extern const Int32 fsMotorIdfwCurrentLimit;/*2^0,75A^2/2*/
extern const Int32 fsMotorIdfwCurrentLimitHalf;
extern const Int32 fsMotorKnockProtectI;//2^-7,25A
extern const Int16 fsMotorCurrentMax;/* conv:2^-7A ,= fsMotorMaxFocCurrentQ + 25A*/
extern const Int16 fsMotorCurrentMax2;/* conv:2^-7A ,= fsMotorMaxFocCurrentQ + 25A*/
extern const Int32 fsMotorUqLimitBaseVol;
extern const Int32 fsMotorIdfwCurrentMaxHalf;
/***************閿熸枻鎷烽敓鏂ゆ嫹閿熼ズ璇ф嫹閿熸枻鎷�**********************/
extern const UInt16 fsMotorSteerToRpm;/*2^-10,20*60/360*/
extern const UInt16 fsMotorRotorToSteer;//2^-9,180/pi/20
/***************鎵敓鍓垮垰搴﹁鎷烽敓鏂ゆ嫹**********************/
extern const UInt16 fsStrTrqSNRCoef;/* conv:2^-17Nm , val: 2.35Nm/閿熸枻鎷� */
extern const UInt16 fsMotorPidOutModulation;
extern const UInt16 fsAvPowerRelayScale;
extern GLOBAL uint8 fsPredriver_EnableStatus;
extern GLOBAL uint16 fsFaultClass_Predriver;
extern GLOBAL uint16 fsFaultClass_Predriver_extral;

extern GLOBAL UInt16 AD_PMICAmux;
extern GLOBAL UInt16 AD_CutOffVCP;
extern GLOBAL UInt16 AD_TempSys2;

extern GLOBAL Int32 Fv_LowRev_spd;

#define ENABLE_DOUBLE_P_SIGNAL_CALCUL_ANGLE
#if defined(ENABLE_DOUBLE_P_SIGNAL_CALCUL_ANGLE)
extern volatile UInt16 IOC_AngpDuty1;
extern volatile UInt16 IOC_AngpDuty2;
extern volatile uint16 Sent_APSentToPwm2;
#endif


extern const UInt8 DTCErrDebounceTmrCntCnStart[];
extern UInt8 DTCErrDebounceTmrCnt [];


extern volatile uint8 Fv_TCAN1145Sleep;
extern volatile uint8 Fv_TPS653852GoToSleep;
extern volatile uint32 Fv_ErrorFromGn32;
extern volatile uint8 TEST_00[8];

extern volatile uint8 TestMode_RequestData[8];

extern GLOBAL UInt16 fs_testmode_rc;
extern GLOBAL UInt8 fsTESTmodeFun_TrqTransEnabled;
extern GLOBAL UInt8 fsSPI_Communication_Status;
extern GLOBAL UInt8 fsTestModeInhibit;
extern GLOBAL UInt16 fsCalibFaultClass;
extern GLOBAL UInt8 fsTESTmode_ResetFlag;
extern GLOBAL UInt8 fsPowerOnTimesRecord;
extern tag_eTIMER_CapInfo fsETimerCapInfo[6];

extern volatile uint8 ModeDeclaration_true;
extern volatile uint8 NRC_22_timecounter;
extern volatile uint8 Can_NM_tx_flag;
extern volatile uint8 Can_busoffrecover;
extern volatile uint8 Can_secoc_pr;
extern GLOBAL UInt8 fsGblCALWriteFlag;
extern GLOBAL UInt8 fsGblINFOWriteFlag;

extern uint8 testmode_req;

extern  volatile Float64 Fv_FirCof_TorqueNotchFilter_SSW[18];
extern  volatile Int16 Fv_BassicAssisFedforward_SSW;

extern volatile Int32 Fv_MotorCurrent_Dact1;
extern volatile Int32 Fv_MotorCurrent_Daim;
extern volatile Int32 Fv_MotorCurrent_Qact1;
extern volatile Int32 Fv_MotorCurrent_Qaim;

extern volatile UInt8 Fv_PowerMode;
extern volatile UInt8 Fv_CarMode;
extern volatile UInt16 Fv_Ws_Flws_raw;
extern volatile UInt16 Fv_Ws_Frws_raw;
extern volatile UInt16 Fv_Ws_Rlws_raw;
extern volatile UInt16 Fv_Ws_Rrws_raw;
extern volatile Int16 Fv_YawRate_Raw;
extern volatile Int16 Fv_VechYawRate;
extern volatile UInt8 Tv_SE_EndStoredFlag;
extern volatile Bool SysTaskFocResetPending;
extern volatile ASS_TYPE Fv_STOREAssistSelectMode;
extern volatile Int16 Fv_FriCompAdptiveTorqueLast;
extern volatile Int16 Fv_AngleCorrectOprLast;
extern volatile Bool Fv_AOC_Configuration;
extern volatile Int16 Fv_TOCLongStyTrqLast;
extern volatile Int32 Fv_MotorVoltage_D;
extern volatile Int32 Fv_MotorVoltage_Q;
extern volatile Int32 Fv_MotorVoltage_Alpha;
extern volatile Int32 Fv_MotorVoltage_Beta;

extern GLOBAL UInt8 fsRCS_BCMAllowed;
extern GLOBAL Int16 fsVechYawRate;
extern GLOBAL UInt8 fsSFSModeResetReq;
extern GLOBAL UInt8 fsSFSFuncCfg;
extern GLOBAL UInt8 fsSFSSetForbidCond;
extern GLOBAL UInt8 fsOffOnResetFlag;
extern GLOBAL UInt8 fsLKATurnCurveSel;
extern GLOBAL UInt8 fsEPSCloseLoopCtrlFlag;
extern GLOBAL UInt16 fsDataFromGn32[12];
extern GLOBAL UInt8 fsLKATCFuncCfg;
extern GLOBAL UInt8 fsSMSFuncCfg;
extern GLOBAL UInt8 fsLKAACFuncCfg;
extern GLOBAL UInt8 fsADASTCFuncCfg;
extern GLOBAL UInt8 fsRCSFuncCfg;
extern GLOBAL UInt8 fsATSFuncCfg;
extern GLOBAL UInt8 fsDSTFuncCfg;
extern GLOBAL UInt8 fsLDWFuncCfg;
extern GLOBAL UInt8 fsAPAFuncCfg;
extern GLOBAL UInt8 fsVOTFuncCfg;
extern GLOBAL UInt8 fsSACFuncCfg;
extern GLOBAL UInt8 fsVeh_TuneFuncCfg;
extern GLOBAL UInt8 fsVehSpdSignalInValid;
extern const DTC_Code_Str DTC_CodeStrInfo[EPS_DTC_NUM_MAX];
extern uint8 Read_DTC_IgnitCycle_Tab[EPS_DTC_NUM_MAX];

extern GLOBAL RCSAllowSts fsIKEYControlAllow;
extern GLOBAL GearStatus fsSCUGearPosion;
extern GLOBAL RemoteDriveCmd fsIKeyDriveCmd;

extern volatile FailureDiag fsSystemEEPROMDiagStatus[4];

extern GLOBAL UInt16 fsSystemCANReciveCounter[CAN_SIGNAL_NUM];
extern const UInt16 fsSystemCANDiagTimes[CAN_SIGNAL_NUM];

extern volatile UInt8 Fv_CANCCP1;
extern volatile UInt8 Fv_CANCCP3;
extern volatile UInt8 Fv_CANCCP13;
extern volatile UInt8 Fv_CANCCP16;
extern volatile UInt8 Fv_CANCCP17;
extern volatile UInt8 Fv_CANCCP50;
extern volatile UInt8 Fv_CANCCP57;
extern volatile UInt8 Fv_CANCCP58;
extern volatile UInt8 Fv_CANCCP59;/*new*/
extern volatile UInt8 Fv_CANCCP62;
extern volatile UInt8 Fv_CANCCP100;/*new*/
extern volatile UInt16 Fv_CANCCP142;/*new*/
extern volatile UInt8 Fv_CANCCP150;
extern volatile UInt8 Fv_CANCCP316;
extern volatile UInt8 Fv_CANCCP317;
extern volatile UInt8 Fv_CANCCP494;
extern volatile UInt8 Fv_CANCCP540;/*new*/
extern volatile UInt8 Fv_CANCCP547;/*new*/
extern volatile UInt8 Fv_CANCCP565;
extern volatile UInt8 Fv_CANCCP609;/*new*/
extern volatile UInt8 Fv_CANCCP639;
extern volatile UInt8 Fv_CANCCP640;
extern volatile UInt8 Fv_CANCCP655;/*new*/
extern volatile UInt8 Fv_CANCCP695;/*new*/
extern volatile UInt8 Fv_CANCCP741;/*new*/
extern volatile UInt8 Fv_CANCCPbulk_state;
extern volatile UInt16 Fv_SWP2_TS;
extern volatile UInt16 Fv_SWP2_TS1;
extern volatile uint8 fsDtcTestfailed[];
extern volatile sint16 fsYawRateCompensated;
extern volatile sint16 fsRawYawRateComp;
extern volatile sint16 fsYawRateWithComp;
extern volatile uint8 fsAsyDataWithCmpSafeValid;
extern volatile Int16 Tv_FriCompAdptiveTorque;
extern volatile Bool Fv_AOC_StraightFlag;
extern volatile uint8 Fv_DualPSCMFallBackWarningReq;
extern volatile uint64 G_timestamp;

extern volatile UInt8 Fv_EXT_CarMode;
extern volatile UInt8 Fv_EXT_CarModeReq;
extern volatile UInt8 Fv_EXT_UsageMode;
extern volatile UInt8 Fv_EXT_UsageModeReq;

extern void StrAngZeroStored(void);
extern void StrAngZeroRemoved(void);
extern void StrAngEndCalDataReq(void);
extern void AssistModeStored(void);
extern int16_T GetSinTableValue(uint16_T v);
extern void EXT_ServiceCpuDog(void);
extern unsigned short WatchDogtimeoutFlag(void);
#endif /* SOURCECODE_ASW_COMMON_H_ */
