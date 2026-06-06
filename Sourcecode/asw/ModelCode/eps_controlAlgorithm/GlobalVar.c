/*
 * File: GlobalVar.c
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Sep 16 11:53:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "eps_controlAlgorithm_types.h"
#include "SimDiagMacro.h"
/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Global */
volatile UInt16 AD_I2D5Ref1;
volatile UInt16 AD_I2D5Ref2;
volatile UInt16 AD_IgnitionSys;
volatile UInt16 AD_InterMCUTemp;
volatile UInt16 AD_InterVolt1d2;
volatile UInt16 AD_MainTorque;
volatile UInt16 AD_PMSMCurrentU;
volatile UInt16 AD_PMSMCurrentV;
volatile UInt16 AD_PMSMCurrentW;
volatile UInt16 AD_PowerRelaySys;
volatile UInt16 AD_PowerSys;
volatile UInt16 AD_RotorMainCos1;
volatile UInt16 AD_RotorMainCos2;
volatile UInt16 AD_RotorMainMid1;
volatile UInt16 AD_RotorMainMid2;
volatile UInt16 AD_RotorMainSin1;
volatile UInt16 AD_RotorMainSin2;
volatile UInt16 AD_RotorSenPower;
volatile UInt16 AD_RotorSubCos1;
volatile UInt16 AD_RotorSubCos2;
volatile UInt16 AD_RotorSubSin1;
volatile UInt16 AD_RotorSubSin2;
volatile UInt16 AD_SampFunCheck;
volatile UInt16 AD_ShadowCurrentU;
volatile UInt16 AD_ShadowCurrentV;
volatile UInt16 AD_ShadowCurrentW;
volatile UInt16 AD_SubTorque;
volatile UInt16 AD_TempSys;
volatile UInt16 AD_TorqueSenPower;
volatile Int16 ANGLE_ZERO_CALIB;
volatile Bool Arg82800V5cOkFlag;
volatile UInt16 CAN_EngSpd;
volatile UInt8 CAN_Es_Err;
volatile UInt8 CAN_Et_Err;
volatile UInt8 CAN_Et_Status;
volatile UInt16 CAN_FLWS;
volatile UInt16 CAN_FRWS;
volatile UInt8 CAN_IG_Status;
volatile UInt32 CAN_OdoMeter;
volatile UInt16 CAN_RLWS;
volatile UInt16 CAN_RRWS;
volatile UInt8 CAN_Reverse;
volatile UInt16 CAN_StrAng;
volatile UInt16 CAN_VehSpd;
volatile UInt16 CAN_VehSpd0;
volatile UInt8 CAN_Vs_Err;
volatile tagDTC_Ctrl_Info DTC_Ctrl_Info_Tab[EPS_DTC_NUM_MAX];
volatile tagDTC_State_Info DTC_State_Info_Tab[EPS_DTC_NUM_MAX];
volatile UInt16 Fv_ABSVSReciveTimer;
volatile Bool Fv_APC_Configuration;
volatile ASS_TYPE Fv_AWSAssistSelectMode;
volatile Bool Fv_AbsInvalidFlag;
volatile Int16 Fv_ActiveReturnCompTrq;
volatile Int16 Fv_AngleCorrectAim;
volatile Int16 Fv_AngleCorrectLast;
volatile Int16 Fv_AngleCorrectOpr;
volatile Bool Fv_AngleCorrectStoredValid;
volatile Bool Fv_AngleEndPreStudyL;
volatile Bool Fv_AngleEndPreStudyR;
volatile ANGLE_STS Fv_AngleEndValidFlag;
volatile ANGLE_STS Fv_AngleMidValidFlag;
volatile HELLA_STS Fv_AngleReadyFlag;
volatile UInt16 Fv_AssGainLimitCoef;
volatile Int16 Fv_AssMaxLimitVal;
volatile Int16 Fv_AssistRangeLimit;
volatile Int16 Fv_BasicSteerAngle;
volatile Int16 Fv_BassicAssisFedforward;
volatile Int16 Fv_BassicAssisFedforward_SSW;
volatile BAT_VOLT Fv_BatVoltLevel;
volatile ASS_TYPE Fv_CMDAssistSelectMode;
volatile Int32 Fv_ConvStrAng;
volatile Int32 Fv_ConvStrAngOffset;
volatile Int16 Fv_DampCompTrq;
volatile UInt16 Fv_EMSVSReciveTimer;
volatile Bool Fv_EPSFailureStatus;
volatile Bool Fv_EmsInvalidFlag;
volatile Bool Fv_EngRun;               /* 2^0,0 */
volatile UInt16 Fv_EngSpd;
volatile Bool Fv_EngStartStop;
volatile UInt8 Fv_EMSVSReciveFlag;
volatile UInt8 Fv_ABSVSReciveFlag;
volatile FailureDiag Fv_ErrDiagStatus[EPS_DTC_NUM_MAX];
volatile UInt32 Fv_ErrorFromGn32;
volatile Bool Fv_EsSlopeVsflag;
volatile Bool Fv_EspSubFunctionValidFlag;
volatile Int32 Fv_FOC_RotorSpd;
volatile UInt16 Fv_FaultClass_Angle;
volatile UInt16 Fv_FaultClass_Current;
volatile UInt16 Fv_FaultClass_Eeprom;
volatile UInt16 Fv_FaultClass_MCU;
volatile UInt32 Fv_FaultClass_MCUcheck_Soft;
volatile UInt16 Fv_FaultClass_Motor;
volatile UInt16 Fv_FaultClass_Power;
volatile UInt16 Fv_FaultClass_Resolver;
volatile UInt16 Fv_FaultClass_Shutdown;
volatile UInt16 Fv_FaultClass_Torque;
volatile UInt16 Fv_FaultClass_BydNewFault;
volatile Float64 Fv_FirCof_FeedForward[20];/* filter coefficient */
volatile Float64 Fv_FirCof_OffCenter[4];/* filter coefficient */
volatile Float64 Fv_FirCof_OnCenter[8];/* filter coefficient */
volatile Float64 Fv_FirCof_TorqueNotchFilter[18];/* filter coefficient */
volatile Float64 Fv_FirCof_TorqueNotchFilter_SSW[18];/* filter coefficient */
volatile Float64 Fv_FirCof_TorqueRobust[18];/* filter coefficient */
volatile Float64 Fv_FirCof_TorqueRobust2[12];/* filter coefficient */
volatile Float64 Fv_FirCof_TorqueSoftAdv[4];/* filter coefficient */
volatile Float64 Fv_FirCof_TorqueSoftAdv2[16];/* filter coefficient */
volatile Float64 Fv_FirCof_TorqueSoftAdv2_SSW[16];/* filter coefficient */
volatile Int16 Fv_FrcRevCompTrq;
volatile Int16 Fv_FriCompAdptiveTorque;
volatile Int16 Fv_FriCompAdptiveTorqueTemp; // add by liuyang
volatile Int16 Fv_FriCompTrq;
volatile Int16 Fv_FriTorqueCompTrq;
volatile Int16 Fv_HellaFirlterRev;
volatile Int16 Fv_HighFailFlag;
volatile Int16 Fv_HighFailFlag1;
volatile Int16 Fv_HighFailFlag2;
volatile Int32 Fv_HighFailRate;
volatile Int32 Fv_HighFailRate1;
volatile Int32 Fv_HighFailRate2;
volatile UInt16 Fv_I2D5RefADVol1;
volatile UInt16 Fv_I2D5RefADVol2;
volatile Bool Fv_IGkeyEffect;
volatile Bool Fv_IGkeyEffect1;
volatile Int16 Fv_IGkeyVol;
volatile Int16 Fv_IGkeyVol1;
volatile Int16 Fv_InertiaCompTrq;
volatile Int16 Fv_InessentialFailFlag;
volatile Bool Fv_InitializeFaultDiagnosis;
volatile Int16 Fv_InrCompTrq0;
volatile Int16 Fv_LightLampFailFlag;
volatile Int16 Fv_LimitFailFlag;
volatile Int32 Fv_LimitFailRate;
volatile Int16 Fv_LimitedSysPower;
volatile Int32 Fv_LowFailCoef;
volatile Int16 Fv_LowFailFlag;
volatile Int32 Fv_LowFailRate;
volatile Int32 Fv_LowRev;
volatile Int16 Fv_LowRev_rpm;
volatile UInt16 Fv_MainTorqueADVol;
volatile Int16 Fv_ModeCoef;
volatile Int32 Fv_MotorCurrent_Alpha1;
volatile Int32 Fv_MotorCurrent_Alpha2;
volatile Int32 Fv_MotorCurrent_Beta1;
volatile Int32 Fv_MotorCurrent_Beta2;
volatile Int32 Fv_MotorCurrent_Dact;
volatile Int32 Fv_MotorCurrent_Dact1;
volatile Int32 Fv_MotorCurrent_Dact2;
volatile Int32 Fv_MotorCurrent_Daim1;
volatile Int32 Fv_MotorCurrent_Daim2;
volatile Int32 Fv_MotorCurrent_Qact;
volatile Int32 Fv_MotorCurrent_Qact1;
volatile Int32 Fv_MotorCurrent_Qact2;
volatile Int32 Fv_MotorCurrent_Qaim1;
volatile Int32 Fv_MotorCurrent_Qaim2;
volatile Int32 Fv_MotorCurrent_U1;
volatile Int32 Fv_MotorCurrent_U2;
volatile Int32 Fv_MotorCurrent_V1;
volatile Int32 Fv_MotorCurrent_V2;
volatile Int32 Fv_MotorCurrent_W1;
volatile Int32 Fv_MotorCurrent_W2;
volatile Int16 Fv_MotorRev_rpm;
volatile Int32 Fv_MotorVoltage_Alpha1;
volatile Int32 Fv_MotorVoltage_Alpha2;
volatile Int32 Fv_MotorVoltage_Beta1;
volatile Int32 Fv_MotorVoltage_Beta2;
volatile Int32 Fv_MotorVoltage_D1;
volatile Int32 Fv_MotorVoltage_D2;
volatile Int32 Fv_MotorVoltage_Q1;
volatile Int32 Fv_MotorVoltage_Q2;
volatile Int16 Fv_Motor_PWM_U1;
volatile Int16 Fv_Motor_PWM_U2;
volatile Int16 Fv_Motor_PWM_V1;
volatile Int16 Fv_Motor_PWM_V2;
volatile Int16 Fv_Motor_PWM_W1;
volatile Int16 Fv_Motor_PWM_W2;
volatile Int16 Fv_Motor_PWM_limit_U1;
volatile Int16 Fv_Motor_PWM_limit_U2;
volatile Int16 Fv_Motor_PWM_limit_V1;
volatile Int16 Fv_Motor_PWM_limit_V2;
volatile Int16 Fv_Motor_PWM_limit_W1;
volatile Int16 Fv_Motor_PWM_limit_W2;
volatile Int16 Fv_NewTrqTargetLimit;
volatile Int32 Fv_PMSMCurrent_ORGQAIM1;
volatile Int32 Fv_PMSMCurrent_ORGQAIM2;
volatile UInt16 Fv_PowerOnTimesFriction;
volatile Int32 Fv_PowerSqrt3INV;
volatile ASS_TYPE Fv_RUNAssistSelectMode;
volatile ASS_TYPE Fv_SteerAssistMode;
volatile ASS_TYPE Fv_SelectAssistMode;
volatile Int16 Fv_RotorAng;
volatile Int32 Fv_RotorAng_AddSum;
volatile Int32 Fv_RotorAng_AddSumFilter;
volatile UInt16 Fv_RotorMidADVol1;
volatile UInt16 Fv_RotorMidADVol2;
volatile Int16 Fv_Rotor_pos_elcdomin;
volatile Bool Fv_SEEEstoreFlag;
volatile Bool Fv_SEInitClearFlag;
volatile UInt8 Fv_SPITimeoutReq;
volatile UInt16 Fv_SensorPowerResolver;
volatile UInt16 Fv_SensorPowerTorque;
volatile Int32 Fv_ShuntCurrent;
volatile Int16 Fv_StallBlockCmp;
volatile UInt16 Fv_StallCompCoef;
volatile UInt16 Fv_StallProCoef;
volatile Int16 Fv_StrAng;
volatile Int16 Fv_StrAngFailFlag;
volatile Int16 Fv_StrAngOffset;
volatile Int32 Fv_StrAngRtr_Diff;
volatile Int16 Fv_StrAng_Raw;
volatile Int16 Fv_StrTrq;
volatile Int16 Fv_StrTrq0;
volatile Int16 Fv_StrTrqP;
volatile Int16 Fv_StrTrqP2dot5;
volatile Int16 Fv_StrTrq_FeedForward;
volatile UInt16 Fv_StudyTorqueSum;
volatile Bool Fv_StudyTorqueValid;
volatile UInt16 Fv_SubTorqueADVol;
volatile Bool Fv_SysDownCloseFlag;
volatile Bool Fv_SysFailCloseFlag;
volatile Bool Fv_SysFailCloseFlag1;
volatile Bool Fv_SysFailCloseFlag2;
volatile Int16 Fv_SysPower;
volatile Int16 Fv_SysPowerRelay;
volatile Int16 Fv_SysPowerVbat;
volatile Bool Fv_SystemTransferState;
volatile Float64 Fv_TCL_LoadEst;
volatile Int16 Fv_TCL_OpenLoopCompTrq;
volatile Bool Fv_TESTmodeFun_GlbFlag;
volatile UInt16 Fv_TESTmode_CrlReqFlag;
volatile Int16 Fv_TOCInitStyTrq;
volatile Bool Fv_TOCLongFuncFbd;
volatile Bool Fv_TOCSTCFbd;
volatile Bool Fv_TOCShortFuncFbd;
volatile Bool Fv_TOCYawRateCond;
volatile Bool Fv_TOCYawCondFbd = 1;//1;
volatile Bool Fv_TOC_MsgInvalidFlag = 0;
volatile UInt16 Fv_TempCompCoef;
volatile TEMP_CEL Fv_TempLevel;
volatile Int16 Fv_TempSysCel;
volatile UInt16 Fv_TempVol;
volatile TmrSft Fv_TimerShaftState;
volatile Int16 Fv_TorqueTarget;
volatile Int16 Fv_ColumnSumTorque;
volatile Int16 Fv_ExtSumTorque;
volatile Int16 Fv_TCL_CloseloopTargetPlus;//bxl
volatile UInt32 Fv_UdsInhibitProtectState;
volatile Int16 Fv_VehEngFailFlag;
volatile Int32 Fv_VehEngFailRate;
volatile UInt16 Fv_VehSpd;
volatile UInt16 Fv_VehSpd0;
volatile UInt16 Fv_VehSpdNew;
volatile Bool Fv_ViceMCUCommContTimeout;
volatile Bool Fv_ViceMCUCommLongTimeout;
volatile UInt8 Fv_VsPhaseflag;
volatile Bool Fv_VsSlopeflag;
volatile UInt8 Fv_VsSwitchflag;        /* 2^-3,0 */
volatile UInt16 Fv_WheelSpeed_FL;
volatile UInt16 Fv_WheelSpeed_FR;
volatile UInt16 Fv_WheelSpeed_RL;
volatile UInt16 Fv_WheelSpeed_RR;
volatile HOLD Fv_WhichMode;
volatile Bool Fv_WhsInvalidFlag;
volatile Int16 Fv_YawRateDegreeAcc;
volatile Int16 Fv_WheelSpeedRate[4];
volatile Int32 Fv_comp_current_id;
volatile Int32 Fv_comp_current_iq;
volatile Int32 Fv_comp_voltage_ed;
volatile Int32 Fv_comp_voltage_eq;
volatile Int32 Fv_comp_voltage_id;
volatile Int32 Fv_comp_voltage_iq;
volatile Int32 Fv_comp_voltage_rd;
volatile Int32 Fv_comp_voltage_rq;
volatile Int16 Fv_cos_eang;
volatile Int32 Fv_dRotorAng;
volatile Int32 Fv_dRotorAng_rpm;
volatile Int16 Fv_dStrAng;
volatile Int16 Fv_dStrTrq;
volatile Int32 Fv_ddRotorAng;
volatile Int16 Fv_ddStrAng;
volatile Int16 Fv_sin_eang;
volatile UInt16 IOC_AngpDuty;
volatile UInt16 IOC_AngpFrez;
volatile UInt16 IOC_AngsDuty;
volatile UInt16 IOC_AngsFrez;
volatile UInt16 IOC_Tor1Duty;
volatile UInt16 IOC_Tor1Frez;
volatile UInt16 IOC_Tor2Duty;
volatile UInt16 IOC_Tor2Frez;
volatile Bool IO_PredriverState1;
volatile Bool IO_PredriverState2;
volatile UInt16 IO_UphaseDuty1;
volatile UInt16 IO_UphaseDuty2;
volatile Bool IO_UphaseLevel;
volatile UInt16 IO_VphaseDuty1;
volatile UInt16 IO_VphaseDuty2;
volatile Bool IO_VphaseLevel;
volatile UInt16 IO_WphaseDuty1;
volatile UInt16 IO_WphaseDuty2;
volatile Bool IO_WphaseLevel;
volatile UInt8 PWM_Section;
volatile Int16 PWM_t0;
volatile Int16 PWM_t1;
volatile Int16 PWM_t2;
volatile POWER_MODE PowerMode;
volatile Bool SysTaskAngDutyCaclPending;
volatile Bool SysTaskCurrentSmpPending1;
volatile Bool SysTaskCurrentSmpPending2;
volatile Bool SysTaskDevCtrlReqPending;
volatile Bool SysTaskDisableDTCPending;
volatile Bool SysTaskEnableDTCdurDevPending;
volatile Bool SysTaskFocResetPending1;
volatile Bool SysTaskFocResetPending2;
volatile Bool SysTaskFocResetTrgPending1;
volatile Bool SysTaskFocResetTrgPending2;
volatile Bool SysTaskMainRelayPending;
volatile InitDiagStep SysTaskPhaseDiagStepIndex;
volatile InitDiag SysTaskPhaseOpenWarning1;
volatile InitDiag SysTaskPhaseOpenWarning2;
volatile Bool SysTaskPhaseRelayPending;
volatile Bool SysTaskPreDriverCalPending;
volatile Bool SysTaskPreDriverCommPending;
volatile Bool SysTaskPreDriverPending1;
volatile Bool SysTaskPreDriverPending2;
volatile Bool SysTaskPwrBrownoutPending;
volatile Bool SysTaskResolverFailPending1;
volatile Bool SysTaskResolverFailPending2;
volatile Bool SysTaskResolverSmpPending;
volatile Bool SysTaskRsvBrownoutPending;
volatile Bool SysTaskRsvResetTrgPending;
volatile Bool SysTaskRsvSnsPending;
volatile Bool SysTaskRunPending;
volatile Bool SysTaskShutDownPending;
volatile Bool SysTaskTrqSigPending;
volatile Bool SysTaskTrqSplPending;
volatile Bool SysTaskVbatAbnormalPending;
volatile Bool SysTaskViceShutDriverPending;
volatile UInt16 Timer100ms;
volatile UInt16 Timer10_0ms;
volatile UInt16 Timer10_5ms;
volatile UInt16 Timer20_0ms;
volatile UInt16 Timer20_10ms;
volatile UInt16 Timer5_0ms;
volatile Int16 Tv_BasicAsisTrq_Primed;
volatile Int32 Tv_HighFailCoef1;
volatile Int32 Tv_HighFailCoef2;
volatile UInt16 Tv_PID_DI;
volatile UInt16 Tv_PID_DP;
volatile UInt16 Tv_PID_QI;
volatile UInt16 Tv_PID_QP;
volatile Int16 Tv_SE_LeftMaxAng;
volatile Int16 Tv_SE_LeftMaxAngCopy;
volatile Int16 Tv_SE_RightMaxAng;
volatile Int16 Tv_SE_RightMaxAngCopy;
volatile Int16 Tv_StrAng_Raw;
volatile Int16 Fv_StrAng_Org;
volatile Int16 Tv_StrTrq0;
volatile Int16 Tv_dStrAng;
volatile Int16 Tv_ddStrAng;
volatile HOLD WhichMode;
volatile UInt16 glbMainIsrMilliSecondFlag;
volatile UInt16 Fv_DateInfo_Year;
volatile UInt16 Fv_DateInfo_Mounth;
volatile UInt16 Fv_DateInfo_Day;
volatile UInt16 Fv_DateInfo_Hour;
volatile UInt16 Fv_DateInfo_Minus;
volatile UInt16 Fv_DateInfo_Second;
volatile UInt16 Fv_EndCurrentShrinkCoef;
volatile UInt16 Fv_EndCurrentShrinkZoneAbs;
volatile UInt16 Fv_EndCurrentShrinkZoneDir;
volatile UInt16 fsBehaveVsInvalidFlag;
volatile UInt16 fsBehaveVsInvalidCond;
volatile UInt16 Fv_EndKiCoef;
volatile UInt16 Fv_EndKpCoef;
volatile UInt16 Fv_AngleConvRecoverCnt;
volatile UInt8 Fv_IG5MinRule_Flag; // add by liuyang at 241121 for 5min rule
volatile UInt8  Fv_EBL_Cmd = 0;
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
