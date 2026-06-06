/*
 * File: CalVar.h
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.599
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 30 10:22:14 2020
 */

#ifndef RTW_HEADER_CalVarExt_h_
#define RTW_HEADER_CalVarExt_h_

#include "rtwtypes.h"
#include "Std_Types.h"

#if 1
#define Macro_SteerWheelMaxAng    8870 //2^-4 deg  1086.5/2
#define Macro_SteerWheelMaxAngP99 ((Int32)Macro_SteerWheelMaxAng*99/100)
#define Macro_SteerWheelMaxAngP96 ((Int32)Macro_SteerWheelMaxAng*96/100)
#define Macro_SteerWheelMaxAngP90 ((Int32)Macro_SteerWheelMaxAng*90/100)
#define Macro_SteerWheelMaxAngP91 ((Int32)Macro_SteerWheelMaxAng*91/100)
#else
#define Macro_SteerWheelMaxAng    7200 //2^-4 deg  521.5
#define Macro_SteerWheelMaxAngP99 ((Int32)Macro_SteerWheelMaxAng*99/100)
#define Macro_SteerWheelMaxAngP96 ((Int32)Macro_SteerWheelMaxAng*96/100)
#define Macro_SteerWheelMaxAngP90 ((Int32)Macro_SteerWheelMaxAng*90/100)
#define Macro_SteerWheelMaxAngP91 ((Int32)Macro_SteerWheelMaxAng*91/100)
#endif

extern _C_A_L Int16 Cal_SE_DefaultEndAng;
extern _C_A_L Int16 Cal_SE_EndMaxSumAng;
extern _C_A_L Int16 Cal_SE_EndLRDiffAng;
extern _C_A_L UInt16 Cal_SE_EndStyTime;//ms
extern _C_A_L Int16 Cal_SE_EndLearnTrq;//2^-10Nm,
extern _C_A_L Int16 Cal_SE_EndSaveTrq;//2^-10Nm,
extern _C_A_L Int16 Cal_SE_EndLearnRev;//2^-4deg
extern _C_A_L UInt16 Cal_SE_EndSaveVehSpd;//2^-5Km/h,
extern _C_A_L UInt16 Cal_SE_EndSaveTime;//ms

extern _C_A_L  UInt32 Cal_RCS_HeatExtendTime;//ms
extern _C_A_L Int16  Cal_RCS_MaxCurrent;//2^-7,A
extern _C_A_L Int16  Cal_RCS_BrakeExitSpd;
extern _C_A_L UInt16 Cal_RCS_BrakeLowSpdExitEnb;//
extern _C_A_L UInt16 Cal_RCS_BrakeLowSpdExitTmr;
extern _C_A_L UInt16 Cal_RCS_BrakeHoldTmr;//2^0,ms
extern _C_A_L Int16 Cal_RCS_ExitCoefSlope;//2^-14,闁拷閸戠療CS閻ㄥ嫬濮崝娑氶兇閺佺増鏋╅悳鍥风礉0%-100%
extern _C_A_L Int16  Cal_RCS_Enter_StrTrq;
extern _C_A_L Int16  Cal_RCS_Exit_StrTrq0;
extern _C_A_L UInt16 Cal_RCS_Exit_HoldTmr0;
extern _C_A_L UInt16 Cal_RCS_Exit_HoldTmrTick_X[5];
extern _C_A_L UInt16 Cal_RCS_Exit_HoldTmrTick_Y[5];
extern _C_A_L Int16  Cal_RCS_Max_StrAng;
extern _C_A_L Int16 Cal_RCS_Max_MechAng;
extern _C_A_L Int16 Cal_RCS_EndAngMargin;//2^-4,deg
extern _C_A_L Int16  Cal_RCS_AngleRampRate;
extern _C_A_L Int16  Cal_RCS_MaxStrWheelSpd;
extern _C_A_L Int16 Cal_RCS_SpdLoopMaxDiff;
extern _C_A_L UInt16 Cal_RCS_SpdLoopKi;
extern _C_A_L UInt16 Cal_RCS_SpdLoopKp;
extern _C_A_L UInt16 Cal_RCS_SpdLoopPI_X[4];//2^-4,deg
extern _C_A_L UInt16 Cal_RCS_SpdLoopKp_Y[4];//2^0,
extern _C_A_L UInt16 Cal_RCS_SpdLoopKi_Y[4];//2^-7
extern _C_A_L UInt16 Cal_RCS_AngLoopKp_X[4];//2^-4
extern _C_A_L UInt16 Cal_RCS_AngLoopKp_Y[4];//2^-2

extern _C_A_L uint8 Cal_TOC_Enable;
extern _C_A_L Int16 Cal_TOC_ActStrAng;/* conv:2^-4 , deg , min-max:600~1200 */
extern _C_A_L Int16 Cal_TOC_ActStrSpd;/* conv:2^-10 , deg/s , min-max:0~360 */
extern _C_A_L Int16 Cal_TOC_ActStrTrq;/* conv:2^-10 , Nm , min-max:0~8 */
extern _C_A_L UInt16 Cal_TOC_ActVehSpd;/* conv:2^-5 , km/h , min-max:0~200 */
extern _C_A_L Int16 Cal_TOC_DeadZoneTrq;/* conv:2^-10 , Nm  , min-max:0~8 */
extern _C_A_L Int16 Cal_TOC_ExtStrAng;/* conv:2^-4 , deg , min-max:0~100 */
extern _C_A_L Int16 Cal_TOC_ExtStrSpd;/* conv:2^-4 , deg/s , min-max:0~360 */
extern _C_A_L Int16 Cal_TOC_ExtStrTrq;/* conv:2^-10 , Nm , min-max:0~8 */
extern _C_A_L UInt16 Cal_TOC_ExtVehSpd;/* conv:2^-5 , km/h , min-max:0~200 */
extern _C_A_L UInt16 Cal_TOC_FuncActTime;/* conv:2^-20 , Nm/mS 閿熸枻鎷穖in-max:0~8 */
extern _C_A_L UInt16 Cal_TOC_FuncExtTime;/* conv:2^-20 , Nm/mS 閿熸枻鎷穖in-max:0~8 */
extern _C_A_L Int16 Cal_TOC_HoldStrAng;/* conv:2^-4 , deg , min-max:600~1200 */
extern _C_A_L Int16 Cal_TOC_HoldStrSpd;/* conv:2^-10 , deg/s , min-max:0~360 */
extern _C_A_L Int16 Cal_TOC_HoldStrTrq;/* conv:2^-10 , Nm , min-max:0~8 */
extern _C_A_L UInt16 Cal_TOC_HoldVehSpd;/* conv:2^-5 , km/h , min-max:0~200 */
extern _C_A_L UInt32 Cal_TOC_LongFiltCoef;/* conv:2^-18 , min-max:0~1 */
extern _C_A_L UInt16 Cal_TOC_LongFilterTick;
extern _C_A_L Int32 Cal_TOC_LongTrqOutRate;/* conv:2^-20 , Nm/mS 閿熸枻鎷穖in-max:0~8 */
extern _C_A_L Int16 Cal_TOC_MaxCompTrq;/* conv:2^-7 , Nm , min-max: 0~100 */
extern _C_A_L Int16 Cal_TOC_MaxDiffTrq;/* conv:2^-10 ,Nm 閿熸枻鎷� min-max:0~8 */
extern _C_A_L Int16 Cal_TOC_MaxLongTrq;/* conv:2^-7 , Nm , min-max: 0~100 */
extern _C_A_L Int16 Cal_TOC_MaxShortTrq;/* conv:2^-7 , Nm , min-max: 0~100 */
extern _C_A_L UInt16 Cal_TOC_MaxVehSpd;/* conv:2^-5 , km/h , min-max:0~200 */
extern _C_A_L UInt32 Cal_TOC_ShortCalcKi;/* conv:2^-14 , min-max:0~1 */
extern _C_A_L Int16 Cal_TOC_ShortTrqRate;
extern _C_A_L Int16 Cal_TOC_VsYawRate_X[8];//2^-5,km/h
extern _C_A_L Int16 Cal_TOC_VsYawRate_Y[8];//rad/s

/*shimmy comp*/
extern volatile Int16 Cal_SHI_AllowedVSpd;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Float64 Cal_SHI_Depth_Tab_Out[24];/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile UInt16 Cal_SHI_Depth_Tab_Vs[3];/* conv:2^-5 , val:0...10 , min-max:0~20 */
extern volatile UInt16 Cal_SHI_Depth_Tab_dAng[8];/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile Int16 Cal_SHI_FreqDetGrid;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Int32 Cal_SHI_FreqDetGridDecreaseStep;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Int32 Cal_SHI_FreqDetGridIncreaseStep;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile UInt8 Cal_SHI_FreqDetGridWaveTimeHigh;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile UInt8 Cal_SHI_FreqDetGridWaveTimeLow;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile UInt8 Cal_SHI_FreqDetGridWindowPoint;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Int16 Cal_SHI_FreqDetShutAng;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Int16 Cal_SHI_FreqDetShutGrid;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Int16 Cal_SHI_FreqDetShutTrq;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Int16 Cal_SHI_FreqDetShutdAng;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Int16 Cal_SHI_FreqGain_X[6];/* conv:2^-5 , val:0...10 , min-max:0~20 */
extern volatile Int16 Cal_SHI_FreqGain_Y[6];/* conv:2^-5 , val:0...10 , min-max:0~20 */
extern volatile Float64 Cal_SHI_Freq_Tab_Out[24];/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile UInt16 Cal_SHI_Freq_Tab_Vs[3];/* conv:2^-5 , val:0...10 , min-max:0~20 */
extern volatile UInt16 Cal_SHI_Freq_Tab_dAng[8];/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile Int16 Cal_SHI_Gain2_Tab_Ang[8];/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile Int16 Cal_SHI_Gain2_Tab_Out[24];/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile Int16 Cal_SHI_Gain2_Tab_Trq[3];/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile Int16 Cal_SHI_Gain_Tab_Out_Trq[24];/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile Int16 Cal_SHI_Gain_Tab_Out_dAng[24];/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile Int16 Cal_SHI_Gain_Tab_Trq[8];/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile UInt16 Cal_SHI_Gain_Tab_Vs[3];/* conv:2^-5 , val:0...10 , min-max:0~20 */
extern volatile Int16 Cal_SHI_Gain_Tab_dAng[8] ;/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile Int16 Cal_SHI_ShimmyDeadTrq;/* conv:2^-4 , val:15 , min-max:0~90 */
extern volatile Float64 Cal_SHI_Width_Tab_Out[24];/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile UInt16 Cal_SHI_Width_Tab_Vs[3];/* conv:2^-5 , val:0...10 , min-max:0~20 */
extern volatile UInt16 Cal_SHI_Width_Tab_dAng[8];/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile Int16 Cal_SHI_MaxCompTrq;/* conv:2^-7Nm , val:30 , min-max:0~50 */
extern volatile Int16 Cal_SHI_TrqPlus;/* conv:2^-7Nm , val:30 , min-max:0~50 */

extern volatile uint8 Cal_SHI_Enable;/* conv:2^-7Nm , val:30 , min-max:0~50 */
extern volatile Int16 Cal_SHI_FreqGainNew_X[15];
/* conv:2^-5 Hz, val:0...10 , min-max:0~20 */
extern volatile Int16 Cal_SHI_FreqGainNew_Y[15];

extern volatile Int16 Cal_TSC_ANGLMT;

/* conv:2^0 , val:220 , min-max:0~100 */
extern volatile Int16 Cal_TSC_ANGSPDLMT;

/* conv:2^0 , val:220 , min-max:0~300 */
extern volatile UInt16 Cal_TSC_CMD_Tab_X[5];

/* conv:2^0 , val:220 , min-max:0~5000 */
extern volatile Int16 Cal_TSC_CMD_Tab_Y[5];

/* conv:2^0 , val:220 , min-max:0~5000 */
extern volatile UInt16 Cal_TSC_CNT;

/* conv:2^0 , val:220 , min-max:0~5000 */
extern volatile UInt16 Cal_TSC_VEHSPDCNT;

/* conv:2^0 , val:220 , min-max:0~5000 */
extern volatile UInt16 Cal_TSC_VEHSPD_DIFF;

/* conv:2^0 , val:220 , min-max:0~5000 */
extern volatile Int16 Cal_TSC_VIBAMP_RATE;

/* conv:2^-7Nm , val:0.39 , min-max:0~0.5 */
extern volatile UInt16 Cal_TSC_WHEELSPD_DIFF;

extern volatile sint16 Cal_WS_FilterCoef;

extern volatile sint16 Cal_MapSwitchSpeedLimit;/* conv:2^5 , val:20 km/h , min-max:0~250 */

extern volatile sint16 Cal_MapSwitchTorqueLimit;/* conv:2^10 , val:2 NM , min-max:-10~10 */

extern volatile sint16 Cal_MapSwitchTime;/* conv:2^0 , val:50 ms , min-max:0~100 */

extern volatile sint32 Cal_MaxIntglSplyVal;
extern volatile sint16 Cal_SupplyVMonThd;
extern volatile uint16 Cal_SplyVMonVehSpdThd;

extern volatile uint16 Cal_TEvasiveManeuverStop;
extern volatile uint16 Cal_VEvasiveManeuverVehSpd;
extern volatile sint16 Cal_AEvasiveManeuverAng;
extern volatile sint16 Cal_DEvasiveManeuverSpd;
extern volatile uint16 Cal_TParkManeuverStop;
extern volatile uint16 Cal_TParkManeuverStart;
extern volatile sint16 Cal_DParkManeuverSpd;

extern volatile sint16 Cal_EMA_DrvrSteerActvSteerWhlTq;/* 1024 Referenced by: '<S10>/Constant' */

extern volatile sint16 Cal_EMA_DrvrSteerActvPinionSteerAgSpd;/* 16 Referenced by: '<S10>/Constant' */

extern volatile uint16 Cal_YawRateCompVehSpd;
extern volatile uint16 Cal_YawRateCompFactor;
extern volatile sint16 Cal_YawRateCompThreshold;

extern volatile Int16 Cal_FC_StudyAccelMax;/* conv:2^-4 , val:50 , min-max:10~100 */
extern volatile Int16 Cal_FC_StudyAngleBreakPoints[22];                                  /* conv:2^-4 , val:-5~5 , min-max:-20~20 */

extern volatile UInt16 Cal_FC_StudyAngleIndexMax;/* conv:2^0 , val:20 , min-max:0~500 */
extern volatile Int16 Cal_FC_StudyAngleMax;/* conv:2^-4 , val:8 , min-max:4~100 */
extern volatile UInt16 Cal_FC_StudyDtTimer;/* conv:2^0 , val:99 , min-max:0~500 */
extern volatile UInt16 Cal_FC_StudyFilterCnt;/* conv:2^0 , val:30 , min-max:0~100 */
extern volatile UInt16 Cal_FC_StudyRepeatTimes;/* conv:2^0 , val:16 , min-max:16~1024 */
extern volatile Int16 Cal_FC_StudyResultMax;/* conv:2^-7Nm , val:4 , min-max:0~5 */
extern volatile Int16 Cal_FC_StudyResultMin;/* conv:2^-7 , val:0.5 , min-max:0~2 */
extern volatile Int16 Cal_FC_StudyRevMax;/* conv:2^-4 , val:50 , min-max:10~100 */
extern volatile Int16 Cal_FC_StudyRevMin;/* conv:2^-4 , val:50 , min-max:10~100 */
extern volatile UInt16 Cal_FC_StudyStrghtTmr;
                                   /* conv:2^0ms , val:1000 , min-max:0~10000 */
extern volatile Int16 Cal_FC_StudyTempMax;
                                 /* conv:2^-3degC , val:-40 , min-max:-50~150 */
extern volatile Int16 Cal_FC_StudyTempMin;
                                 /* conv:2^-3degC , val:-40 , min-max:-50~150 */
extern volatile Int16 Cal_FC_StudyTrqGridMax;
                                      /* conv:2^-10Nm , val:0.6 , min-max:0~1 */
extern volatile Int16 Cal_FC_StudyTrqMax;/* conv:2^10 , val:5 , min-max:0~10 */
extern volatile UInt16 Cal_FC_StudyVehMax;/* conv:2^-5 , km/h , min-max:0~200 */
extern volatile UInt16 Cal_FC_StudyVehMin;/* conv:2^-5 , km/h , min-max:0~200 */
extern volatile UInt16 Cal_FC_VehSpdCoef_X[5];                   /* conv:2^-5km/h , val:60...100 , min-max:0~200 */

extern volatile Int16 Cal_FC_VehSpdCoef_Y[5];
                           /* conv:2^-7 , val:0.71875...0.39844 , min-max:0~2 */
/* Definition for custom storage class: Global */
extern volatile UInt16 Cal_FC_CURRENT2STEERTORQUE;
/* conv:2^-16 , val:MACRO_MOTOR_CURRENT2TORQUE*(MACRO_RAD2DEG/MACRO_ROTOR2STEER) , min-max:0~0.1 */
extern volatile Int16 Cal_FC_StudyStrghtRec;/* conv:2^-4 , val:90 , min-max:0~180 */

extern volatile uint16 Cal_DPFW_PulseValidTime;

extern volatile uint16 Cal_DPFW_PulseInValidTime;

extern volatile uint16 Cal_DPFW_PulseCnt;
#endif                                 /* RTW_HEADER_CalVar_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
