/*
 * File: SimDiagEnum.h
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1172
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Nov 25 17:10:05 2022
 */

#ifndef RTW_HEADER_SimDiagEnum_h_
#define RTW_HEADER_SimDiagEnum_h_
#include "rtwtypes.h"

typedef enum {
  HELLA_STS_Default = 0,               /* Default value */
  HELLA_STS_Mix,
  HELLA_STS_Decode,
  HELLA_STS_Error
} HELLA_STS;

typedef enum {
  ANGLE_STS_Invalid = 0,               /* Default value */
  ANGLE_STS_Valid,
  ANGLE_STS_Calibrating,
  ANGLE_STS_Error
} ANGLE_STS;

typedef enum {
  ASS_TYPE_DEFAULT = 0,                /* Default value */
  ASS_TYPE_COMFORT,
  ASS_TYPE_STANDARD,
  ASS_TYPE_SPORT,
  ASS_TYPE_LKA,
  ASS_TYPE_SPEC2,
} ASS_TYPE;

typedef enum {
  HOLD_OFF = 0,                        /* Default value */
  HOLD_INIT,
  HOLD_OFFDELAY,
  HOLD_ATTEMPTINIT,
  HOLD_ACTIVE,
  HOLD_CRANK,
  HOLD_LIMIT
} HOLD;

typedef enum {
  TOC_STATE_HoldLong = 0,              /* Default value */
  TOC_STATE_HoldTcnt,
  TOC_STATE_ActLong,
  TOC_STATE_ActShort,
  TOC_STATE_HoldWait
} TOC_STATE;

typedef enum {
  POWER_MODE_PMOFF = 0,                /* Default value */
  POWER_MODE_PMON,
  POWER_MODE_PMCRANK
} POWER_MODE;

typedef enum {
  BM_SPDSTATE_NORUN = 0,               /* Default value */
  BM_SPDSTATE_RUN,
  BM_SPDSTATE_INVALID,
  BM_SPDSTATE_LOST
} BM_SPDSTATE;

typedef enum {
  ASSIST_MODE_NOSTART = 0,             /* Default value */
  ASSIST_MODE_START,
  ASSIST_MODE_DELAYSTART,
  ASSIST_MODE_DEFAULTSTART,
  ASSIST_MODE_NORMALRUN,
  ASSIST_MODE_STOPRUN,
  ASSIST_MODE_DEFAULTRUN,
  ASSIST_MODE_DELAYSTOPRUN
} ASSIST_MODE;

typedef struct {
  UInt8 testFailed;
  UInt8 testFailedThisMonitoringCycle;
  UInt8 pendingDTC;
  UInt8 confirmedDTC;
  UInt8 testNotCompletedSinceLastClear;
  UInt8 testFailedSinceLastClear;
  UInt8 testNotCompletedThisMonitoringCycle;
  UInt8 warningIndicatorRequest;
} tagDTC_State_Info;

typedef enum {
  FailureDiag_Default = 0,             /* Default value */
  FailureDiag_OK,
  FailureDiag_InitOK,
  FailureDiag_RegOK,
  FailureDiag_Err,
  FailureDiag_InitErr,
  FailureDiag_RegErr
} FailureDiag;

typedef struct {
  UInt8 Enabled;
  UInt8 OnStarTrigEnabled;
  UInt8 OnStarTrigQueued;
  UInt8 OnStarTrigReported;
  UInt8 MonitorAllowed;
  UInt8 ErrOccurring;
  UInt8 StoreReq;
  UInt8 IgnitCycleReq;
  UInt8 LightLampUnrecover;
  UInt8 LightLampReq;
  UInt8 SnapShotAllowed;
  UInt8 SnapShotStoreReq;
  UInt8 SnapShotRecordDisabled;
  UInt8 SnapShotIgClearStore;
  UInt8 SnapShotRecordWatting;
  UInt8 unused;
} tagDTC_Ctrl_Info;

typedef enum {
  CANBUS_BUSOff = 0,                   /* Default value */
  CANBUS_ABSVs,
  CANBUS_ABSWs,
  CANBUS_IPB2,
  CANBUS_IPB5,
  CANBUS_IPB6,
  CANBUS_EMSEt,
  CANBUS_CCU2,
  CANBUS_VCU3,
  CANBUS_ADS2,
  CANBUS_ADS1,
  CANBUS_APA,
  CANBUS_SCU,
  CANBUS_BCM2, 
  CANBUS_CCU1,
  CANBUS_BCM3,
  CANBUS_IPB3,
  CANBUS_IPB4,
  CANBUS_IPB7,
  CANBUS_NUM,
} CANBUS;

typedef enum {
  DTC_MCUcheck_RAM = 0,                /* Default value */
  DTC_MCUcheck_ROM,
  DTC_MCUcheck_PerOthers,
  DTC_MCUcheck_UnexpReset,
  DTC_MCUcheck_ExtWatchDog,
  DTC_MCUcheck_MotorCtrl,
  DTC_MCUcheck_AssistCtrl,
  DTC_MCUcheck_CommTimeout,
  DTC_MCUcheck_ViceMonitor,
  DTC_MOTORcheck_Predriver,/* 9 */
  DTC_ANGLEcheck_ExtAngleErr,
  DTC_MOTORcheck_PhaseOpen,
  DTC_MOTORcheck_OverCurrent,
  DTC_MOTORcheck_Output,
  DTC_CURRENTcheck_MiddSig, /* 14 */
  DTC_CURRENTcheck_3PhaseSum,
  DTC_DSTFUNCcheck_ReqValueOverLimt,
  DTC_CURRENTcheck_IcalibInvalid,
  DTC_TORQUEcheck_PowerSupply, /* 18 */
  DTC_TORQUEcheck_MainRange,
  DTC_TORQUEcheck_MainWave,
  DTC_TORQUEcheck_SubRange,
  DTC_TORQUEcheck_SubWave,
  DTC_TORQUEcheck_SumOfMS,
  DTC_TORQUEcheck_Offset,
  DTC_ANGLEcheck_NoZeroCalib, /* 25 */
  DTC_ANGLEcheck_Invalid,
  DTC_ANGLEcheck_Unreal,
  DTC_ANGLEcheck_NoEndLearn,
  DTC_ANGLEcheck_CheckRotor,
  DTC_RESOLVERcheck_PowerSupply,/* 30 */
  DTC_RESOLVERcheck_MiddSig,
  DTC_RESOLVERcheck_SinRange,
  DTC_RESOLVERcheck_SinOffset,
  DTC_RESOLVERcheck_CosRange,
  DTC_RESOLVERcheck_CosOffset,
  DTC_RESOLVERcheck_LotusWave,
  DTC_LKAFUNCcheck_ReqValueOverLimt, /* 37 */
  DTC_LKAFUNCcheck_AbnormalExit,
  DTC_APAFUNCcheck_AbnormalExit,
  DTC_POWERcheck_Burned, /* 40 */
  DTC_POWERcheck_LowReset,
  DTC_POWERcheck_OverShut,
  DTC_POWERcheck_LowShut,
  DTC_POWERcheck_VolLimitAst,
  DTC_POWERcheck_VBATdt,
  DTC_POWERcheck_IGkey,
  DTC_POWERcheck_Hold,
  DTC_EEPROMcheck_CommTimeout, /* 48 */
  DTC_EEPROMcheck_BootCheck,
  DTC_EEPROMcheck_ConfigCheck,
  DTC_EEPROMcheck_CalibCheck,
  DTC_EEPROMcheck_AngleCheck,
  DTC_EEPROMcheck_AngleCrrCheck,
  DTC_ASTcheck_AstDegrade,
  DTC_EEPROMcheck_OtherCheck,
  DTC_TEMPcheck_ADport, /* 56 */
  DTC_TEMPcheck_Range,
  DTC_TEMPcheck_Over,
  DTC_TEMPcheck_TempLimitAst,
  DTC_TEMPcheck_HeatShut,
  DTC_CANCOMMcheck_Busoff,  /* 61 */
  DTC_CANCOMMcheck_ABSVsLostComm,
  DTC_CANCOMMcheck_ABSVsDataInvalid,
  DTC_CANCOMMcheck_ABSVsCRCError,
  DTC_CANCOMMcheck_ABSVsCounterError,
  DTC_CANCOMMcheck_ABSWsLostComm,
  DTC_CANCOMMcheck_ABSWsDataInvalid,
  DTC_CANCOMMcheck_ABSWsCRCError,
  DTC_CANCOMMcheck_ABSWsCounterError,
  DTC_CANCOMMcheck_IPB2LostComm,
  DTC_CANCOMMcheck_IPB2DataInvalid,/* 71 */
  DTC_CANCOMMcheck_IPB2CRCError,
  DTC_CANCOMMcheck_IPB2CounterError,
  DTC_CANCOMMcheck_IPB5LostComm,
  DTC_CANCOMMcheck_IPB5DataInvalid,
  DTC_CANCOMMcheck_IPB6LostComm,
  DTC_CANCOMMcheck_IPB6DataInvalid,
  DTC_CANCOMMcheck_IPB6CRCError,
  DTC_CANCOMMcheck_IPB6CounterError,
  DTC_CANCOMMcheck_CCU3LostComm,
  DTC_CANCOMMcheck_CCU2LostComm,/* 81 */
  DTC_CANCOMMcheck_VCU3LostComm,
  DTC_CANCOMMcheck_ADS2LostComm,
  DTC_CANCOMMcheck_ADS2CRCError,
  DTC_CANCOMMcheck_ADS2CounterError,
  DTC_CANCOMMcheck_ADS1LostComm,
  DTC_CANCOMMcheck_ADS1CRCError,
  DTC_CANCOMMcheck_ADS1CounterError,
  DTC_CANCOMMcheck_APALostComm,
  DTC_CANCOMMcheck_APADataInvalid,
  DTC_CANCOMMcheck_APACRCError, /* 91 */
  DTC_CANCOMMcheck_APACounterError,
  DTC_CANCOMMcheck_SCULostComm,
  DTC_CANCOMMcheck_BCM2LostComm,
  DTC_CANCOMMcheck_CCU1LostComm,
  DTC_CANCOMMcheck_SCUInvalidDLC,
  DTC_CANCOMMcheck_RemoteInvalidDLC,
  DTC_CANCOMMcheck_BrakeInvalidDLC,
  DTC_CANCOMMcheck_BrakeLostComm,
  DTC_CANCOMMcheck_IPB7LostComm,
  DTC_CANCOMMcheck_VCU1InvalidDLC,/* 101 */
  DTC_CANCOMMcheck_BCMInvalidData,
  DTC_CANCOMMcheck_IPB7InvalidData,/* 103 */
  DTC_Reserved0			/* 104 */
} DTC;

typedef enum {
  EPS_IGNIT_REQ_NONE = 0,              /* Default value */
  EPS_IGNIT_REQ_INC,
  EPS_IGNIT_REQ_CLR
} EPS_IGNIT;

typedef struct {
  UInt16 Code;
  UInt8 FailType;
  UInt8 MaxIgnitCycle;
  UInt8 Priority;
  UInt32 Num;
} tagDTC_Code_Str;

typedef enum {
  BAT_VOLT_UNKNOWN = 0,                /* Default value */
  BAT_VOLT_NORMAL,
  BAT_VOLT_LOWRESET,
  BAT_VOLT_LOW,
  BAT_VOLT_OVER,
  BAT_VOLT_BURNED,
  BAT_VOLT_REVERSE
} BAT_VOLT;

typedef enum {
  TmrSft_Default = 0,                  /* Default value */
  TmrSft_AllOFF,
  TmrSft_OpenTest,
  TmrSft_Discharge,
  TmrSft_PreCharge,
  TmrSft_RelayON,
  TmrSft_PredriverON,
  TmrSft_Complete
} TmrSft;

typedef enum {
  InitDiag_Default = 0,                /* Default value */
  InitDiag_Normal,
  InitDiag_Pass,
  InitDiag_Abnormal,
  InitDiag_Error
} InitDiag;

typedef enum {
  InitDiagStep_Default = 0,            /* Default value */
  InitDiagStep_Phase2Power,
  InitDiagStep_Phase2Ground,
  InitDiagStep_OpenPhase,
  InitDiagStep_MosMeltCommon,
  InitDiagStep_MosMeltDischarge,
  InitDiagStep_WaitCharge
} InitDiagStep;

typedef enum {
  TEMP_CEL_NORMAL = 0,                 /* Default value */
  TEMP_CEL_LOW,
  TEMP_CEL_OVER
} TEMP_CEL;



typedef struct {
  UInt16 mainT;
  UInt16 subT;
  UInt16 dutyT1;
  UInt16 frezT1;
  UInt16 dutyT2;
  UInt16 frezT2;
  UInt16 dutyAP;
  UInt16 frezAP;
  UInt16 dutyAS;
  UInt16 frezAS;
  UInt16 sinP;
  UInt16 sinN;
  UInt16 cosP;
  UInt16 cosN;
  UInt16 psinP;
  UInt16 psinN;
  UInt16 pcosP;
  UInt16 pcosN;
  UInt16 Iu;
  UInt16 Iv;
  UInt16 Iw;
  UInt16 pIu;
  UInt16 pIv;
  UInt16 pIw;
  UInt16 temp1;
  UInt16 temp2;
  UInt16 tempc;
} INFO_EXTSENSOR;

typedef struct {
  UInt16 vIG;
  UInt16 vBS;
  UInt16 vBR;
  UInt16 vMR;
  UInt16 vTA;
  UInt16 cRM1;
  UInt16 cRM2;
  UInt16 vCO1;
  UInt16 vCO2;
  UInt16 v1d2;
  UInt8 levelU;
  UInt8 levelV;
  UInt8 levelW;
  UInt8 plevelU;
  UInt8 plevelv;
  UInt8 plevelW;
  Bool drvst1;
  Bool drvst2;
  UInt8 ign;
  UInt32 odo;
  UInt8 rvr;
  UInt16 vhs;
  UInt8 vhs_err;
  UInt16 ens;
  UInt8 ens_err;
  UInt8 et;
  UInt8 et_err;
  UInt16 fls;
  UInt16 frs;
  UInt16 rls;
  UInt16 rrs;
} INFO_INNERSAMPLE;

#endif                                 /* RTW_HEADER_SimDiagEnum_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
