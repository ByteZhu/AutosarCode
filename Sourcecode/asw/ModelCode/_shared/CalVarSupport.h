/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CalVarSupport.h
 *
 * Code generated for Simulink model 'ADV_ExtFunction'.
 *
 * Model version                  : 9.98
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 25 08:42:28 2023
 */

#ifndef RTW_HEADER_CalVarSupport_h_
#define RTW_HEADER_CalVarSupport_h_
#include "rtwtypes.h"
#include "Std_Types.h"
/* ConstVolatile memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Global */
extern volatile sint16 Cal_LKA_TqOut_X[25] ;/* conv:2^-7A , val:0...16.5 , min-max:0~100 */
extern volatile sint16 Cal_LKA_TqOut_Y[25] ;/* conv:Nm , val:0...3 , min-max:0~5 */

extern volatile uint16 Cal_FAA_AL_P_X[8];
extern volatile uint16 Cal_FAA_AL_P_Y[8];
extern volatile uint16 Cal_FAA_LeadGain_X[8];
extern volatile uint16 Cal_FAA_LeadGain_Y[8];

extern volatile sint16 Cal_LKA_TqLimit_A[25];                       /* conv:Nm , val:0...3 , min-max:0~5 */

extern volatile sint16 Cal_LKA_TqLimit_T[175];
                                 /* conv:2^-7A , val:0...16.5 , min-max:0~100 */

extern volatile uint16 Cal_LKA_TqLimit_V[7];


extern volatile double Cal_FAA_AL_P;
extern volatile double Cal_FAA_FcStif;
extern volatile double Cal_FAA_LeadFreq;
extern volatile double Cal_FAA_LeadGain;
extern volatile uint16 Cal_FAA_SpdLim_X[8];
extern volatile uint16 Cal_FAA_SpdLim_Y[8];
extern volatile uint16 Cal_FAA_FC_Lim_X[6];
extern volatile uint16 Cal_FAA_FC_Lim_Y[6];
extern volatile uint16 Cal_FAA_FC_X[8];
extern volatile uint16 Cal_FAA_FC_Y[8];
extern volatile uint16 Cal_FAA_SpdLoop_X[8];
extern volatile uint16 Cal_FAA_SpdLoop_Y_I[8];
extern volatile uint16 Cal_FAA_SpdLoop_Y_P[8];
extern volatile Int16 Cal_LKA_PosLoopKp_A[7];/* conv:2^-4 deg, val:90 , min-max:0~800    anglediff*/
extern volatile Int16 Cal_LKA_PosLoopKp_V[8];/* conv:2^-5 kph, val: , min-max:0~185 */
extern volatile Int16 Cal_LKA_PosLoopKp_T[56];


extern volatile uint16 Cal_APA_VSINIT_RPA;

extern volatile sint16 Cal_APA_DANGINIT;

/* conv:2^-4 , val:90 , min-max:0~800 */
extern volatile sint16 Cal_APA_DIFFINIT;

/* conv:2^-4 , val:250 , min-max:100~1000 */
extern volatile sint16 Cal_APA_DIFFLIMIT;

/* conv:2^-4 , val:250 , min-max:100~1000 */
extern volatile sint16 Cal_APA_ErrAdapt_Tab_A[8];

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile uint16 Cal_APA_ErrAdapt_Tab_I[24];

/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile uint16 Cal_APA_ErrAdapt_Tab_P[24];

/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile uint16 Cal_APA_ErrAdapt_Tab_V[3];

/* conv:2^-5 , val:0...10 , min-max:0~20 */
extern volatile sint16 Cal_APA_HandOverTimeTab_X[9];

/* conv:2^-10Nm , val:2...12 , min-max:0~12 */
extern volatile uint16 Cal_APA_HandOverTimeTab_Y[9];

/* conv:2^-10Nm , val:800...0 , min-max:0~1000 */
extern volatile sint16 Cal_APA_LOOP_INCREVLIMIT;

/* conv:2^0 , val:200 , min-max:0~1000 */
extern volatile sint16 Cal_APA_LOOP_MAX_ANGLE;

/* conv:2^-4 , val:540 , min-max:0~800 */
extern volatile sint32 Cal_APA_LOOP_MAX_CURRENT;

/* conv:2^-7 , val:90 , min-max:0~100 */
extern volatile sint32 Cal_APA_LOOP_MAX_REV;

/* conv:2^0 , val:213120 , min-max:0~320000,rpm:2^-3*16 */
extern volatile uint16 Cal_APA_LOOP_REVPI_PLUS;

/* conv:2^0 , val:4 , min-max:0~10 */
extern volatile sint16 Cal_APA_LOOP_STEP_ANGLE;

/* conv:2^-4 , val:0.5 , min-max:0~5 */
extern volatile sint32 Cal_APA_LOOP_STOPREVDN;

/* conv:2^-3 , val:100 , min-max:0~1000 */
extern volatile sint32 Cal_APA_LOOP_STOPREVUP;

/* conv:2^-3 , val:200 , min-max:0~1000 */
extern volatile uint16 Cal_APA_LOOP_STOPTMR;

/* conv:2^0 , val:100 , min-max:0~2000 */
extern volatile sint16 Cal_APA_POSPID_KD;

/* conv:2^0 , val:3 , min-max:0~5 */
extern volatile sint16 Cal_APA_POSPID_KP;

/* conv:2^0 , val:280 , min-max:0~500 */
extern volatile sint16 Cal_APA_TRQINIT;

/* conv:2^10 , val:1 , min-max:0~10 */
extern volatile sint16 Cal_APA_TRQLOOP;

/* conv:2^10 , val:5 , min-max:0~10 */
extern volatile uint16 Cal_APA_VSINIT;

/* conv:2^-5 , val:1 , min-max:0~100 */
extern volatile uint16 Cal_APA_VSLOOP;

/* conv:2^-5 , val:10 , min-max:0~100 */
extern volatile uint16 Cal_LDW_AmpVsTab_X[6];

/* conv:2^-5km/h , val:60...180 , min-max:0~200 */
extern volatile sint16 Cal_LDW_AmpVsTab_Y[6];

/* conv:2^-7Nm , val:23...18.5 , min-max:0~80 */
extern volatile uint16 Cal_LDW_FrzVsTab_X[6];

/* conv:2^-5km/h , val:60...180 , min-max:0~200 */
extern volatile uint16 Cal_LDW_FrzVsTab_Y[6];

/* conv:2^0Hz , val:20...20 , min-max:10~30 */
extern volatile uint16 Cal_LDW_TEMPRECOVER_TMR;

/* conv:2^0 , val:300 , min-max:0~1000 */
extern volatile sint16 Cal_LDW_VIBAMP_LIMIT;

/* conv:2^-7 , val:3 , min-max:1~5 */
extern volatile sint16 Cal_LDW_VIBAMP_RATE;

/* conv:2^-7Nm , val:0.39 , min-max:0~0.5 */
extern volatile uint16 Cal_LDW_VIBFREZ_DN;

/* conv:2^0 , val:10 , min-max:10~20 */
extern volatile uint16 Cal_LDW_VIBFREZ_UP;

/* conv:2^0 , val:20 , min-max:10~30 */
extern volatile uint16 Cal_LDW_VSEND;

/* conv:2^-5 , val:185 , min-max:0~200 */
extern volatile uint16 Cal_LDW_VSSTART;

/* conv:2^-5 , val:50 , min-max:0~200 */
extern volatile sint16 Cal_LDW_VibAmp_Gain;

/* conv:2^-10, val:8 , min-max:0~30 */
extern volatile sint16 Cal_LKA_ADVCMD_RATE;

/* conv:2^-10Nm , val:0.002 , min-max:0~0.5 */
extern volatile sint16 Cal_LKA_AgCtrlDnOfNoTrqLimit;

/* conv:2^-7 , val:15.625 , min-max:0~50 */
extern volatile sint16 Cal_LKA_AgCtrlTqDnLimit_X[10];

/* conv:2^-7 , val:15.625 , min-max:0~50 */
extern volatile sint16 Cal_LKA_AgCtrlTqDnLimit_Y[10];

extern volatile sint16 Cal_LKA_ARFactor_X[3];   
                                      /* conv:2^-5KM/ , val:15.625 , min-max:0~50 */

extern volatile sint16 Cal_LKA_ARFactor_Y[3];
                                     /* conv:2^-7 , val:1 , min-max:0~1 */
/* conv:2^-7 , val:15.625 , min-max:0~50 */
extern volatile sint16 Cal_LKA_AgCtrlTqUpLimit_X[10];

/* conv:2^-7 , val:15.625 , min-max:0~50 */
extern volatile sint16 Cal_LKA_AgCtrlTqUpLimit_Y[10];

/* conv:2^-7 , val:15.625 , min-max:0~50 */
extern volatile sint16 Cal_LKA_AgCtrlUpOfNoTrqLimit;

/* conv:2^-7 , val:15.625 , min-max:0~50 */
extern volatile sint16 Cal_LKA_AimCurrentTab_A[7];

/* conv:Nm , val:0...3 , min-max:0~5 */
extern volatile sint16 Cal_LKA_AimCurrentTab_T[49];

/* conv:2^-7A , val:0...16.5 , min-max:0~100 */
extern volatile uint16 Cal_LKA_AimCurrentTab_V[7];

/* conv:2^-5km/h , val:0...130 , min-max:0~200 */
extern volatile uint16 Cal_LKA_CMDSMP_TMR;

/* conv:2^0 , val:20 , min-max:0~1000 */
extern volatile sint16 Cal_LKA_CmdCoefTab_A[7];

/* conv:Nm , val:0...3 , min-max:0~5 */
extern volatile sint16 Cal_LKA_CmdCoefTab_T[49];

/* conv:2^-4, val:0...12 , min-max:0~20 */
extern volatile uint16 Cal_LKA_CmdCoefTab_V[7];

/* conv:km/h 2^-5 , val:30...120 , min-max:0~200 */
extern volatile sint16 Cal_LKA_DIFFLIMIT;

/* conv:2^-4 , val:250 , min-max:100~1000 */
extern volatile sint16 Cal_LKA_DampAngTab_A[7];

/* conv:2^-4, val:0...200 , min-max:0~800 */
extern volatile sint16 Cal_LKA_DampAngTab_T[49];

/* conv:2^-7, val:1...1 , min-max:0~1 */
extern volatile uint16 Cal_LKA_DampAngTab_V[7];

/* conv:2^-5 km/h , val:30...120 , min-max:0~200 */
extern volatile sint16 Cal_LKA_DampCoefTab_X[7];

/* conv:Nm , val:0...3 , min-max:0~5 */
extern volatile sint16 Cal_LKA_DampCoefTab_Y[7];

/* conv:2^-10, val:0.58...0 , min-max:0~2 */
extern volatile sint16 Cal_LKA_DampCompTab_A[7];

/* conv:2^-4, val:0...200 , min-max:0~800 */
extern volatile sint16 Cal_LKA_DampCompTab_T[49];

/* conv:2^-7, val:0...45 , min-max:0~20 */
extern volatile uint16 Cal_LKA_DampCompTab_V[7];

/* conv:2^-5 km/h , val:30...120 , min-max:0~200 */
extern volatile sint16 Cal_LKA_ErrAdapt_Tab_A[8];

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
extern volatile uint16 Cal_LKA_ErrAdapt_Tab_I[24];

/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile uint16 Cal_LKA_ErrAdapt_Tab_P[24];

/* conv:2^0 , val:0...100 , min-max:0~199 */
extern volatile uint16 Cal_LKA_ErrAdapt_Tab_V[3];

/* conv:2^-5 , val:0...100 , min-max:0~200 */
extern volatile sint16 Cal_LKA_FilterCoef;

/* conv:2^-10 , val:0.99 , min-max:0~1 */
extern volatile sint16 Cal_LKA_GRADCMD_RANGE;

/* conv:2^-10Nm , val:5 , min-max:0~10 */
extern volatile sint16 Cal_LKA_GRIDLIMIT;

/* conv:2^-4 , val:50 , min-max:10~100 */
extern volatile sint16 Cal_LKA_GradCoefTab_A[4];

/* conv:Nm/s , val:3...5 , min-max:0~5 */
extern volatile sint16 Cal_LKA_GradCoefTab_T[28];

/* conv:2^-7, val:1...1.2 , min-max:0~2 */
extern volatile uint16 Cal_LKA_GradCoefTab_V[7];

/* conv:2^-5km/h , val:0...130 , min-max:0~200 */
extern volatile uint16 Cal_LKA_HANDOFF_TMR;

/* conv:2^0 , val:3000 , min-max:0~1000 */
extern volatile sint16 Cal_LKA_HANDOFF_TRQ;

/* conv:2^-10 , val:0.25 , min-max:0~0.5 */
extern volatile sint16 Cal_LKA_HandOverMaxTrqTab_T[9];

/* conv:Nm , val:0...3 , min-max:0~5 */
extern volatile uint16 Cal_LKA_HandOverMaxTrqTab_V[9];

/* conv:2^-5km/h , val:0...130 , min-max:0~200 */
extern volatile sint16 Cal_LKA_HandOverTimeTab_A[9];

/* conv:2^-10Nm , val:2...12 , min-max:0~12 */
extern volatile uint16 Cal_LKA_HandOverTimeTab_T[63];

/* conv:2^-10Nm , val:800...0 , min-max:0~1000 */
extern volatile uint16 Cal_LKA_HandOverTimeTab_V[7];

/* conv:2^-5km/h , val:0...130 , min-max:0~200 */
extern volatile uint16 Cal_LKA_HandsOffStepTab_S[28];

/* conv:2^0ms , val:0...3 , min-max:0~5 */
extern volatile sint16 Cal_LKA_HandsOffStepTab_T[4];

/* conv:2^-10Nm, val:0...3 , min-max:0~10 */
extern volatile uint16 Cal_LKA_HandsOffStepTab_V[7];

/* conv:2^-5km/h , val:0...130 , min-max:0~200 */
extern volatile sint16 Cal_LKA_LOOP_INCREVLIMIT;

/* conv:2^0 , val:200 , min-max:0~1000 */
extern volatile sint16 Cal_LKA_LOOP_MAX_ANGLE;

/* conv:2^-4 , val:540 , min-max:0~800 */
extern volatile sint32 Cal_LKA_LOOP_MAX_CURRENT;

/* conv:2^-7 , val:90 , min-max:0~100 */
extern volatile sint32 Cal_LKA_LOOP_MAX_REV;

/* conv:2^0 , val:213120 , min-max:0~320000 */
extern volatile uint16 Cal_LKA_LOOP_REVPI_PLUS;

/* conv:2^0 , val:4 , min-max:0~10 */
extern volatile sint16 Cal_LKA_LOOP_STEP_ANGLE;

/* conv:2^-4 , val:0.5 , min-max:0~5 */
extern volatile sint32 Cal_LKA_LOOP_STOPREVDN;

/* conv:2^-3 , val:100 , min-max:0~1000 */
extern volatile sint32 Cal_LKA_LOOP_STOPREVUP;

/* conv:2^-3 , val:200 , min-max:0~1000 */
extern volatile uint16 Cal_LKA_LOOP_STOPTMR;

/* conv:2^0 , val:100 , min-max:0~2000 */
extern volatile sint16 Cal_LKA_POSPID_KD;

/* conv:2^0 , val:3 , min-max:0~5 */
extern volatile sint16 Cal_LKA_POSPID_KP;

/* conv:2^0 , val:280 , min-max:0~500 */
extern volatile sint16 Cal_LKA_REQLIMIT;

/* conv:2^-4 , val:600 , min-max:10~1000 */
extern volatile uint32 Cal_LKA_TEMPO_OVERTIME_TMR;

/* conv:2^0 , val:10 , min-max:0~2000 */
extern volatile uint16 Cal_LKA_TEMPRECOVER_TMR;

/* conv:2^0 , val:300 , min-max:0~1000 */
extern volatile sint16 Cal_LKA_TRQADVCOMP_MAX;

/* conv:2^-7 , val:15.625 , min-max:0~50 */
extern volatile sint16 Cal_LKA_TRQCMD_RANGE;

/* conv:2^-10Nm , val:3 , min-max:0~5 */
extern volatile sint16 Cal_LKA_TRQCMD_RATE;

/* conv:2^-10Nm/ms , val:0.05 , min-max:0~0.5 */
extern volatile sint16 Cal_LKA_TRQCMD_RATE_FRAME;

/* conv:2^-10Nm , val:0.5 , min-max:0~0.5 */
extern volatile sint16 Cal_LKA_TRQDMPCOMP_MAX;

/* conv:2^7 , val:30 , min-max:0~50 */
extern volatile sint16 Cal_LKA_TRQOUT_RANGE;

/* conv:2^-7Nm , val:60 , min-max:0~100 */
extern volatile sint16 Cal_LKA_TRQOUT_RATE;

/* conv:2^-7Nm , val:0.5 , min-max:0~5 */
extern volatile uint16 Cal_LKA_VSEND;
/* conv:2^-5 , val:185 , min-max:0~200 */
extern volatile uint16 Cal_LKA_VSSTART;

/* conv:2^-5 , val:50 , min-max:0~200 */
extern volatile uint16 Cal_LKA_VsCoefTab_X[6];

/* conv:2^-5km/h , val:0...180 , min-max:0~200 */
extern volatile uint16 Cal_LKA_VsCoefTab_Y[6];

/* conv:2^-10 , val:0...1 , min-max:0~2 */

extern volatile Int16 Cal_LDW_VibAmp_Gain;

/* conv:2^-10, val:8 , min-max:0~30 */
extern volatile Float64 Cal_SF_FREZLMT;

/* conv:2^0 , val:20 , min-max:0~100 */
extern volatile Float64 Cal_SF_FREZSTEP;

/* conv:2^0 , val:20 , min-max:0~100 */
extern volatile Int16 Cal_SF_LEVEL_1;

/* conv:2^-7 , val:10 , min-max:0~50 */
extern volatile Int16 Cal_SF_LEVEL_2;

/* conv:2^-7 , val:10 , min-max:0~50 */
extern volatile Int16 Cal_SF_LEVEL_3;

extern volatile uint8 Cal_TSC_Enable;
/* conv:2^-7 , val:10 , min-max:0~50 */
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

/* conv:2^0 , val:220 , min-max:0~5000 */

extern volatile Int16 Cal_LKA_HandsOffStep_Spd[];
extern volatile Int16 Cal_LKA_HandsOffStep_Trq[];
extern volatile Int16 Cal_LKA_HandsOffStep_Out[];
extern volatile float64 Cal_HANDOFF_TrqFir_Frez;

extern volatile Int16 Cal_Support_EndVar;
extern volatile Int16 Cal_Support_EndBoundary;

#endif                                 /* RTW_HEADER_CalVarSupport_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
