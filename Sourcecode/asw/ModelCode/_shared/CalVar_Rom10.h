/*
 * File: CalVar.h
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Sep 14 09:18:28 2022
 */

#ifndef RTW_HEADER_CalVar_h_
#define RTW_HEADER_CalVar_h_
#include "rtwtypes.h"
#include "Std_Types.h"
/* ConstVolatile memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Global */
extern _C_A_L UInt16 A_Cal_FirCof_NCH_Frez_SSW_Vs[3];//初值0，640，1600
extern _C_A_L Float64 A_Cal_FirCof_NCH_FrezSSWA[4];
extern _C_A_L Float64 A_Cal_FirCof_NCH_FrezSSWB[4];
extern _C_A_L Float64 A_Cal_FirCof_NCH_FrezSSWC[4];

extern _C_A_L Int16 A_Cal_TMP_HrmAmpCoefTab_W[17];
extern _C_A_L Int16 A_Cal_TMP_HrmAmpCoefTab_T[17];
extern _C_A_L Int16 A_Cal_TMP_HrmAmpTab_W[9];
extern _C_A_L Int16 A_Cal_TMP_HrmAmpTab_T[9];
extern _C_A_L Int16 A_Cal_TMP_HrmOftTab_W[17];
extern _C_A_L Int16 A_Cal_TMP_HrmOftTab_T[17];

extern _C_A_L Int16 A_Cal_FirCof_TSA2_Frez2_Six_A[64];
                                  /* conv:2^7 , val:2 , min-max:0~50 */

extern _C_A_L Int16 A_Cal_FirCof_TSA2_Frez2_Six_B[64];
                                  /* conv:2^7 , val:2 , min-max:0~50 */

extern _C_A_L UInt16 A_Cal_FirCof_TSA2_Frez2_Trq0[8];
                                  /* conv:2^4deg/s , val:0.5...14 , min-max:0~50 */

extern _C_A_L UInt16 A_Cal_FirCof_TSA2_Frez2_dAng[8];
                                  /* conv:2^4deg/s , val:0.5...14 , min-max:0~50 */

extern _C_A_L Float64 A_Cal_FirCof_NCH_FrezA[4];
extern _C_A_L Float64 A_Cal_FirCof_NCH_FrezB[4];
extern _C_A_L Float64 A_Cal_FirCof_NCH_FrezC[4];
extern _C_A_L Int16 A_Cal_AR_PAimSpdCoef;//2^-7
extern _C_A_L Int16 A_Cal_AR_NAimSpdCoef;//2^-7

extern _C_A_L UInt16 A_Cal_FirCof_FWR_FirSel;

extern _C_A_L UInt16 A_Cal_BT_Generator_Sel;

extern _C_A_L Float64 A_Cal_FirCof_NCH_Frez_SSW[12];


extern _C_A_L Int16 A_Cal_SE_MaxTorq;
extern _C_A_L Int16 A_Cal_FirCof_FWRX_Tab_X[6] ; /* conv:2^-3rpm , val:0...120 , min-max:0~3000 */
extern _C_A_L UInt16 A_Cal_FirCof_FWRX_Tab_Y[9]; /* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_FirCof_FWRX_Tab_Z[54];

extern _C_A_L Float64 A_Cal_FirCof_TorqueSoftAdv2_Vs[3];// = {0,640,1600};

extern _C_A_L Float64 A_Cal_FirCof_RST_Frez2_Vs[5];//={0,640,1600,2560,3200};

extern _C_A_L Float64 A_Cal_FirCof_TSA_Frezx[8];// = {20,200,16,100,16,100,16,100};
extern _C_A_L UInt16 A_Cal_FirCof_TorqueSoftAdv_Vs[4];// = {0,160,320,640};

extern _C_A_L Float64 A_Cal_FirCof_TSA_Frez_1[2];

extern _C_A_L Int16 A_Cal_ADV_StrTrqAdv_Z[9][6];

extern _C_A_L Int16 A_Cal_ADV_StrTrqAdv_X[6];

extern _C_A_L UInt16 A_Cal_ADV_StrTrqAdv_Y[9];


extern _C_A_L Int16 A_Cal_AN_MaxAngle;

/* conv:2^-4deg , val:1000 , min-max:600~1200 */
extern _C_A_L Int16 A_Cal_AN_MaxdAngle;

/* conv:2^-4deg/s , val:2000 , min-max:1500~2000 */
extern _C_A_L Int16 A_Cal_AN_MaxddAngle;

/* conv:2^0deg/s^2 , val:20000 , min-max:15000~30000 */
extern _C_A_L Int16 A_Cal_APC_MONITOR_ANG;

/* conv:0.1deg , val:150 , min-max:0~300 */
extern _C_A_L Int16 A_Cal_APC_MONITOR_CEF;

/* conv:2^0 , val:1024 , min-max:512~2048 */
extern _C_A_L Int16 A_Cal_APC_MONITOR_REV;

/* conv:2^-4deg/s , val:8 , min-max:0~30 */
extern  _C_A_L Int16 A_Cal_APC_MONITOR_YawAcc;

/* conv:2^-4deg/s , val:8 , min-max:0~30 */
extern _C_A_L UInt16 A_Cal_APC_MONITOR_TMR;/* conv:2^0 , val:10 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_APC_MONITOR_TRQ;

/* conv:2^-10Nm , val:1.5 , min-max:0~2 */
extern _C_A_L UInt16 A_Cal_APC_MONITOR_VHS;

/* conv:2^-5km/h , val:60 , min-max:40~80 */
extern  _C_A_L UInt16 A_Cal_APC_MONITOR_VHS_UpLimit;

/* conv:2^-5km/h , val:60 , min-max:40~80 */
extern _C_A_L UInt16 A_Cal_APC_MONITOR_VsTab_X[5];

/* conv:2^-5km/h , val:0..160 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_APC_MONITOR_VsTab_Y[5];/* conv:2^0 , val:1..5 , min-max:0~10 */
extern  _C_A_L UInt16 A_Cal_APC_MONITOR_WHS_Detla;

/* conv:2^-5km/h , val:60 , min-max:40~80 */
extern _C_A_L Int16 A_Cal_AR_ActiveReturnTrqPlus;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_AimGainCoef;

/* conv:2^-7 , val:1.2031 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_AimGain_HRCoef;

/* conv:2^-7 , val:1.0547 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_AimStrSpdTab_A[10];

/* conv:2^-4deg , val:0...550 , min-max:0~800 */
extern _C_A_L Int16 A_Cal_AR_AimStrSpdTab_T1[90];

/* conv:2^-4deg/s , val:0...0 , min-max:0~400 */
extern _C_A_L Int16 A_Cal_AR_AimStrSpdTab_T2[90];

/* conv:2^-4deg/s , val:0...0 , min-max:0~400 */
extern _C_A_L Int16 A_Cal_AR_AimStrSpdTab_T3[90];

/* conv:2^-4deg/s , val:0...0 , min-max:0~400 */
extern _C_A_L Int16 A_Cal_AR_AimStrSpdTab_T_LKA[90];

/* conv:2^-4deg/s , val:0...0 , min-max:0~400 */
extern _C_A_L UInt16 A_Cal_AR_AimStrSpdTab_V[9];

/* conv:2^-5km/h , val:0...100 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_AR_DamperCoefTab_X[7];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_AR_DamperCoefTab_XS[7];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_AR_DamperCoefTab_Y[7];

/* conv:2^-7 , val:0.85...1.47 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_DamperCoefTab_YS[7];

/* conv:2^-7 , val:0.85...1.33 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_FilterCoef;/* conv:2^-7 , val:1 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_AR_MaxTorq;/* conv:2^-7Nm , val:30 , min-max:0~30 */
extern _C_A_L Int16 A_Cal_AR_NAngCoef;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_OutputRate;

/* conv:2^-7Nm/ms , val:0.5 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_AR_PAngCoef;

/* conv:2^-7 , val:1.0938 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef1Tab_X[6];

/* conv:2^-10Nm , val:0...2.7998 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef1Tab_Y1[6];

/* conv:2^-7 , val:1...0.33 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef1Tab_Y2[6];

/* conv:2^-7 , val:0.93...0.28 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef1Tab_Y3[6];

/* conv:2^-7 , val:1...0.34 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef2Tab_T[18];

/* conv:2^-7 , val:1...0.63 , min-max:0~2 */
extern _C_A_L UInt16 A_Cal_AR_TorqueCoef2Tab_V[3];

/* conv:2^-5 , val:15...80 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef2Tab_X[6];

/* conv:2^-10Nm , val:0.4502...3 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef3Tab_X[6];

/* conv:2^-10Nm , val:0...2.7998 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef3Tab_Y1[6];

/* conv:2^-7 , val:1...0.3125 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef3Tab_Y2[6];

/* conv:2^-7 , val:1...0.3 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_TorqueCoef3Tab_Y3[6];

/* conv:2^-7 , val:1.02...0.34 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_AR_TorqueRate;

/* conv:2^-10Nm/ms , val:0.099609 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_AR_dANGtoTORcoef_A[6];

/* conv:2^-4deg/s , val:0...900 , min-max:0~1000 */
extern _C_A_L Int16 A_Cal_AR_dANGtoTORcoef_T[18];

/* conv:2^-13 , val:0.04...0.065 , min-max:0~0.08 */
extern _C_A_L UInt16 A_Cal_AR_dANGtoTORcoef_V[3];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_AV_TempScale_X[36];

/* conv:2^-7V , val:0.15625...4.7188 , min-max:0~5 */
extern _C_A_L Int16 A_Cal_AV_TempScale_Y[36];

/* conv:2^-3��C , val:130...-45 , min-max:-50~150 */
extern _C_A_L Int16 A_Cal_Ang_GridMax;/* conv:2^-4deg , val:1 , min-max:0~5 */
extern _C_A_L UInt8 A_Cal_AntiTug_StopEnable;/* conv:2^0 , val:1 , min-max:0~1 */
extern _C_A_L Int32 A_Cal_AntiTug_WeakRecover;

/* conv:2^-7A , val:-1 , min-max:-10~10 */
extern _C_A_L Int32 A_Cal_AntiTug_WeakShutoff;

/* conv:2^-7A , val:-5 , min-max:-10~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_Dp[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_P0[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_P1[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_P2[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_P3[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_P4[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_P5[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_Pd[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve1_Ymax[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_Dp[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_P0[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_P1[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_P2[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_P3[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_P4[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_P5[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_Pd[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve2_Ymax[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_Dp[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_P0[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_P1[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_P2[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_P3[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_P4[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_P5[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_Pd[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Float64 A_Cal_AsssitCurve3_Ymax[10];/* conv:2^-7 , val:  , min-max:0~10 */
extern _C_A_L Int16 A_Cal_BMCoef_EMSSsmStatus;/* conv:2^-14 , val:0 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_BM_ActiveRate;

/* conv:2^-14 , val:0.00097656 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_BM_ActiveTimer;

/* conv:2^0 , val:1025 , min-max:0~60000 */
extern _C_A_L Int16 A_Cal_BM_CrankRate;

/* conv:2^-14 , val:0.00061035 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_BM_CrankTimer;

/* conv:2^0 , val:1639 , min-max:0~60000 */
extern _C_A_L UInt16 A_Cal_BM_CrankTimerPre;

/* conv:2^0 , val:30000 , min-max:0~60000 */
extern _C_A_L Int16 A_Cal_BM_EngineStopRate;

/* conv:2^-14 , val:0.00097656 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_BM_OffRate;

/* conv:2^-14 , val:0.00061035 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_BM_OffTimer;

/* conv:2^0 , val:1639 , min-max:0~60000 */
extern _C_A_L UInt16 A_Cal_BM_OffTimerPre;/* conv:2^0 , val:0 , min-max:0~60000 */
extern _C_A_L UInt16 A_Cal_BM_PMTimer;

/* conv:2^0 , val:100 , min-max:0~60000 */
extern _C_A_L UInt16 A_Cal_BM_ReadyTimer;

/* conv:2^0 , val:400 , min-max:0~60000 */
extern _C_A_L Int16 A_Cal_BT_BasicAsisTab_X[57];

/* conv:2^-10Nm , val:0...6.75 , min-max:0~10 */
extern _C_A_L UInt16 A_Cal_BT_BasicAsisTab_Y[10];

/* conv:2^-5km/h , val:0...140 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_BT_BasicAsisTab_Z1[570];

/* conv:2^-7Nm , val:0...33 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_BT_BasicAsisTab_Z2[570];

/* conv:2^-7Nm , val:0...33 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_BT_BasicAsisTab_Z3[570];

/* conv:2^-7Nm , val:0...33 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_BT_BasicAsisTab_Z_LKA[570];

/* conv:2^-7Nm , val:0...33 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_BT_BassicTrqPlus;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_DC_CompTrqFltVal;

/* conv:2^-7 , val:0.46875 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_DC_CompTrqMaxX[13];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_DC_CompTrqMaxY[13];

/* conv:2^-7 , val:0...30 , min-max:0~50 */
extern _C_A_L Int16 A_Cal_DC_MaxTorq;/* conv:2^-7Nm , val:30 , min-max:0~40 */
extern _C_A_L UInt16 A_Cal_DC_QuadVehSpdGainX[13];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_DC_QuadVehSpdGainY1[13];/* conv:2^-7 , val:0...1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_DC_QuadVehSpdGainY2[13];/* conv:2^-7 , val:0...1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_DC_QuadVehSpdGainY3[13];/* conv:2^-7 , val:0...1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_DC_QuadVehSpdGainY_LKA[13];/* conv:2^-7 , val:0...1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_DC_RpmGainPlus;/* conv:2^-7 , val:1 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_DC_RpmSquareGainPlus;

/* conv:2^-7 , val:0.0625 , min-max:0~0.1 */
extern _C_A_L UInt16 A_Cal_DC_RpmSquareVehSpdGainX[13];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_DC_RpmSquareVehSpdGainY1[13];

/* conv:2^-19 , val:0...0.000885 , min-max:0~0.001 */
extern _C_A_L Int16 A_Cal_DC_RpmSquareVehSpdGainY2[13];

/* conv:2^-19 , val:0...0.000978 , min-max:0~0.001 */
extern _C_A_L Int16 A_Cal_DC_RpmSquareVehSpdGainY3[13];

/* conv:2^-19 , val:0...0.000614 , min-max:0~0.001 */
extern _C_A_L Int16 A_Cal_DC_RpmSquareVehSpdGainY_LKA[13];

/* conv:2^-19 , val:0...0.000885 , min-max:0~0.001 */
extern _C_A_L UInt16 A_Cal_DC_RpmVehSpdGainX[13];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_DC_RpmVehSpdGainY1[13];

/* conv:2^-15 , val:0...0.003 , min-max:0~0.01 */
extern _C_A_L Int16 A_Cal_DC_RpmVehSpdGainY2[13];

/* conv:2^-15 , val:0...0.006 , min-max:0~0.01 */
extern _C_A_L Int16 A_Cal_DC_RpmVehSpdGainY3[13];

/* conv:2^-15 , val:0...0.003 , min-max:0~0.01 */
extern _C_A_L Int16 A_Cal_DC_RpmVehSpdGainY_LKA[13];

/* conv:2^-15 , val:0...0.003 , min-max:0~0.01 */
extern _C_A_L Int16 A_Cal_DC_StrTrqCoefFltVal;

/* conv:2^-7 , val:0.46875 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_DC_StrTrqCoefX[6];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_DC_StrTrqCoefY[6];

/* conv:2^-10Nm , val:0...1 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_DC_dStrTrqCoefX[6];

/* conv:2^-10Nm , val:0...2.5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_DC_dStrTrqCoefY[6];

/* conv:2^-10Nm , val:0...1 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_DC_dStrTrqFltVal;

/* conv:2^-7 , val:0.46875 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_DF_BasicAsisTabGen_X[6];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L UInt16 A_Cal_DF_BasicAsisTabGen_Y[6];

/* conv:2^-5km/h , val:0...50 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_DF_BasicAsisTabGen_Z[36];

/* conv:2^-7Nm , val:0...20 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_DF_BassicTrqPlus;/* conv:2^-7 , val:1 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_EngSpd_Grid;

/* conv:2^-1rpm , val:200 , min-max:0~1000 */
extern _C_A_L UInt16 A_Cal_EngSpd_Offset;

/* conv:2^-1rpm , val:0 , min-max:0~1000 */
extern _C_A_L UInt16 A_Cal_EngSpd_Run;

/* conv:2^-1rpm , val:500 , min-max:0~1000 */
extern _C_A_L UInt16 A_Cal_EngSpd_Scale;

/* conv:2^-10rpm , val:0.25 , min-max:0~1 */
extern  _C_A_L Int16 A_Cal_FC_FrictionAdativeMin;/* conv:2^-7Nm , val:4 , min-max:0~5 */
extern _C_A_L Int16 A_Cal_FC_FrictionCompRevTab_X[6];

/* conv:2^-3rpm , val:0...50 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_FC_FrictionCompRevTab_Y[6];

/* conv:2^-7Nm , val:0...0.78125 , min-max:0~3 */
extern _C_A_L Int16 A_Cal_FC_FrictionCompTorTab_X[7];

/* conv:2^-10Nm , val:0.099609...6 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_FC_FrictionCompTorTab_Y[7];/* conv:2^-7 , val:0...1 , min-max:0~3 */
extern _C_A_L UInt16 A_Cal_FC_FrictionCompVehTab_X[6];

/* conv:2^-5km/h , val:0...160 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_FC_FrictionCompVehTab_Y[6];

/* conv:2^-7 , val:1...0.71875 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_FC_FrictionMax;/* conv:2^-7Nm , val:4 , min-max:0~5 */
extern _C_A_L UInt16 A_Cal_FC_FrictionRevlVehTab_X[6];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_FC_FrictionRevlVehTab_Y[6];

/* conv:2^-7 , val:0.71875...0.39844 , min-max:0~2 */
extern _C_A_L UInt16 A_Cal_FC_FrictionStaticVehTab_X[6];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_FC_FrictionStaticVehTab_Y[6];/* conv:2^-7 , val:0...1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_FC_MaxTorq;/* conv:2^-7Nm , val:8 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_FC_ReturnCof;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L UInt16 A_Cal_FC_ReturnVsDn;

/* conv:2^-5km/h , val:30 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_FC_ReturnVsUp;

/* conv:2^-5km/h , val:35 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_FC_RevMaxTorq;/* conv:2^-7Nm , val:4 , min-max:0~5 */
extern _C_A_L Int16 A_Cal_FC_RevPlus;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_FC_StaticCompTorTab_X[5];

/* conv:2^-10Nm , val:0...3.998 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_FC_StaticCompTorTab_Y[5];/* conv:2^-7 , val:1...0 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_FC_StaticMaxTorq;/* conv:2^-7Nm , val:30 , min-max:0~50 */
extern  _C_A_L Int16 A_Cal_FC_StudyAccelMax;/* conv:2^-4 , val:50 , min-max:10~100 */
extern  _C_A_L Int16 A_Cal_FC_StudyAngleMax;

/* conv:2^-4 , val:250 , min-max:100~1000 */
extern  _C_A_L Int16 A_Cal_FC_StudyResultMax;/* conv:2^-7Nm , val:4 , min-max:0~5 */
extern  _C_A_L Int16 A_Cal_FC_StudyRevMax;/* conv:2^-4 , val:50 , min-max:10~100 */
extern  _C_A_L Int16 A_Cal_FC_StudyRevMin;/* conv:2^-4 , val:50 , min-max:10~100 */
extern  _C_A_L Int16 A_Cal_FC_StudyTempMax;

/* conv:2^-3degC , val:-40 , min-max:-50~150 */
extern  _C_A_L Int16 A_Cal_FC_StudyTempMin;

/* conv:2^-3degC , val:-40 , min-max:-50~150 */
extern  _C_A_L Int16 A_Cal_FC_StudyTorqueQact_X[7];

/* conv:2^-7A , val:0.099609...6 , min-max:0~100 */
extern  _C_A_L Int16 A_Cal_FC_StudyTorqueQact_Y[7];/* conv:2^-7 , val:0...1 , min-max:0~3 */
extern  _C_A_L Int16 A_Cal_FC_StudyTorqueTrq_X[7];

/* conv:2^-10Nm , val:0.099609...6 , min-max:0~10 */
extern  _C_A_L Int16 A_Cal_FC_StudyTorqueTrq_Y[7];/* conv:2^-7 , val:0...1 , min-max:0~3 */
extern  _C_A_L Int16 A_Cal_FC_StudyTrqMax;/* conv:2^10 , val:5 , min-max:0~10 */
extern  _C_A_L UInt16 A_Cal_FC_StudyVehMax;/* conv:2^-5 , km/h , min-max:0~200 */
extern  _C_A_L UInt16 A_Cal_FC_StudyVehMin;/* conv:2^-5 , km/h , min-max:0~200 */
extern  _C_A_L Int16 A_Cal_FC_TempCoefX[8];

/* conv:2^-3degC , val:-40 , min-max:-50~150 */
extern  _C_A_L Int16 A_Cal_FC_TempCoefY[8];/* conv:2^-7 , val:0...1 , min-max:0~3 */
extern _C_A_L Int16 A_Cal_FC_TrqPlus;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L Int32 A_Cal_FOC_IDFW_Current_Cmp_Max_C;

/* conv:2^-7A , val:-30 , min-max:-100~0 */
extern _C_A_L Int32 A_Cal_FOC_IDFW_Current_Max_C;

/* conv:2^-7A , val:-50 , min-max:-100~0 */
extern _C_A_L Int32 A_Cal_FOC_IDFW_Id_rev_Coef_C;/* conv:2^0 , val:5 , min-max:2~8 */
extern _C_A_L Int16 A_Cal_FOC_ID_WeakPwrTab_C[41];

/* conv:2^-10 , val:0.25...1 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_FOC_ID_WeakRtTab_X[18];

/* conv:2^-3rpm , val:0...4000 , min-max:0~5000 */
extern _C_A_L Int16 A_Cal_FOC_ID_WeakRtTab_Y[18];

/* conv:2^-10 , val:0...11.2002 , min-max:0~20 */
extern _C_A_L Float64 A_Cal_FirCof_FWR_Frez[5];

/* conv:2^0Hz , val:20...20 , min-max:0~50 */
extern _C_A_L UInt16 A_Cal_FirCof_FWR_Tab_X[9];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_FirCof_FWR_Tab_Y[9];

/* conv:0.1Hz , val:0...170 , min-max:0~500 */
extern _C_A_L Float64 A_Cal_FirCof_NCH_Frez[12];

/* conv:2^0Hz , val:35...0.7 , min-max:0~100 */
extern _C_A_L Float64 A_Cal_FirCof_OFC_Frez[2];

/* conv:2^0Hz , val:20...10 , min-max:0~100 */
extern _C_A_L Float64 A_Cal_FirCof_ONC_Frez[2];

/* conv:2^0Hz , val:30...45 , min-max:0~100 */
extern _C_A_L Float64 A_Cal_FirCof_RST_Frez2[20];

/* conv:2^0Hz , val:20...2.6 , min-max:0~100 */
extern _C_A_L Float64 A_Cal_FirCof_TSA2_Frez2[8];

/* conv:2^0Hz , val:0.5...14 , min-max:0~50 */
extern _C_A_L Float64 A_Cal_FirCof_TSA2_Frez2_SSW[8];

/* conv:2^0Hz , val:0.5...14 , min-max:0~200 */
extern _C_A_L Float64 A_Cal_FirCof_TSA_Frez[2];

/* conv:2^0Hz , val:26.5...159 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_FirRst_VsTemp1;/* conv:2^-5 , val:70 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_FirRst_VsTemp2;/* conv:2^-5 , val:100 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_HM_HarmonicSelect;
extern _C_A_L Int16 A_Cal_HM_HarmonicTabGen_X[6];

/* conv:2^-7A , val:0...100 , min-max:0~100 */
extern _C_A_L UInt16 A_Cal_HM_HarmonicTabGen_Y[5];

/* conv:2^-5km/h , val:0...130 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_HM_HarmonicTabGen_Z[30];

/* conv:2^-17A , val:0...100 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRateTab_S1[33];

/* conv:2^-10Nm , val:0...0.12 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRateTab_S2[33];

/* conv:2^-10Nm , val:0...0.12 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRateTab_S3[33];

/* conv:2^-10Nm , val:0...0.12 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRateTab_S_LKA[33];

/* conv:2^-10Nm , val:0...0.12 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRateTab_T[11];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L UInt16 A_Cal_HS_HysteresisRateTab_V[3];

/* conv:2^-5km/h , val:0...20 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRevDeadZone;

/* conv:2^-3rpm , val:0 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRevTab_X[10];

/* conv:2^-3rpm , val:0...480 , min-max:0~1000 */
extern _C_A_L Int16 A_Cal_HS_HysteresisRevTab_Y[10];

/* conv:2^-3rpm , val:0.5...1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_HS_HysteresisTrqDeadZone;

/* conv:2^-10Nm , val:0 , min-max:0~0.5 */
extern _C_A_L UInt16 A_Cal_HS_HysteresisTrqTab_X[9];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_HS_HysteresisTrqTab_Y[11];

/* conv:2^-10Nm , val:0...4.5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_HS_HysteresisTrqTab_Z1[99];

/* conv:2^-10Nm , val:0...23.8 , min-max:0~30 */
extern _C_A_L Int16 A_Cal_HS_HysteresisTrqTab_Z2[99];

/* conv:2^-10Nm , val:0...23.8 , min-max:0~30 */
extern _C_A_L Int16 A_Cal_HS_HysteresisTrqTab_Z3[99];

/* conv:2^-10Nm , val:0...23.8 , min-max:0~30 */
extern _C_A_L Int16 A_Cal_HS_HysteresisTrqTab_Z_LKA[99];

/* conv:2^-10Nm , val:0...23.8 , min-max:0~30 */
extern _C_A_L Int16 A_Cal_IC_InePlus;

/* conv:2^-7 , val:1.6016 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_IC_InertiaComp;

/* conv:2^-15Nm*s^2/m , val:0.0030823 , min-max:0~0.1 */
extern _C_A_L Int16 A_Cal_IC_InertiaCompTab_C[66];

/* conv:2^-7 , val:0.39063...0.656 , min-max:0~2 */
extern _C_A_L UInt16 A_Cal_IC_InertiaCompTab_S[6];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_IC_InertiaCompTab_T[11];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_IC_MaxTorq;/* conv:2^-7Nm , val:5 , min-max:0~20 */
extern _C_A_L Int16 A_Cal_IGExceedVol;/* conv:2^-7V , val:24 , min-max:20~30 */
extern _C_A_L Int16 A_Cal_IGHighVol;/* conv:2^-7V , val:6 , min-max:4~9 */
extern _C_A_L Int16 A_Cal_IGLowVol;/* conv:2^-7V , val:2 , min-max:1~4 */
extern _C_A_L Int32 A_Cal_InitAngle_HrmComp;/* conv:2^0 , val:0 , min-max:-30~30 */
extern _C_A_L Int16 A_Cal_LM_PidKiTabGen_X[6];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L UInt16 A_Cal_LM_PidKiTabGen_Y[5];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_LM_PidKiTabGen_Z[30];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L Int16 A_Cal_LM_PidKpTabGen_X[6];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L UInt16 A_Cal_LM_PidKpTabGen_Y[5];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_LM_PidKpTabGen_Z[30];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L Int16 A_Cal_ModeSwitch_Trq;/* conv:2^-10Nm , val:3 , min-max:0~5 */
extern _C_A_L UInt16 A_Cal_ModeSwitch_VehSpd;

/* conv:2^-5km/h , val:15 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_ModeSwitch_WheelSpd;

/* conv:2^-4deg/s , val:90 , min-max:0~2000 */
extern _C_A_L Int16 A_Cal_Motor_TrqCoef;

extern _C_A_L Int16 A_Cal_OC_AccCompTab_X[5];

extern _C_A_L Int16 A_Cal_OC_AccCompTab_Y[5];

/* conv:2^-7A/Nm , val:-1.1016 , min-max:-2~2 */
extern _C_A_L Int16 A_Cal_OC_HysCompPlus;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L UInt16 A_Cal_OC_HysCompVehTab_X[5];

/* conv:2^-5km/h , val:0...120 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_OC_HysCompVehTab_Y[5];

/* conv:2^-7 , val:0...0.078125 , min-max:0~0.2 */
extern _C_A_L Int16 A_Cal_OC_HysComp_SatMaxTorq;/* conv:2^-7Nm , val:10 , min-max:0~20 */
extern _C_A_L Int16 A_Cal_PID_CurActTable[6];

/* conv:2^-7A , val:0...50 , min-max:0~100 */
extern _C_A_L Int32 A_Cal_PID_CurrentAct;/* conv:2^-7A , val:4 , min-max:0~100 */
extern _C_A_L UInt16 A_Cal_PID_KI;/* conv:2^0 , val:18 , min-max:0~100 */
extern _C_A_L UInt16 A_Cal_PID_KP;

/* conv:2^0 , val:1000 , min-max:0~5000 */
extern _C_A_L UInt16 A_Cal_PID_MotorCurrentTab_I[30];

/* conv:2^0 , val:0...20 , min-max:0~25 */
extern _C_A_L UInt16 A_Cal_PID_MotorCurrentTab_P[30];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L Int16 A_Cal_PID_MotorCurrentTab_X[6];

/* conv:2^-7A , val:0...50 , min-max:0~100 */
extern _C_A_L UInt16 A_Cal_PID_MotorCurrentTab_Y[5];

/* conv:2^-5km/h , val:0...20 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_PID_MotorRevBackwardTab_X[6];

/* conv:2^-3rpm , val:0...4000 , min-max:0~4000 */
extern _C_A_L Int16 A_Cal_PID_MotorRevBackwardTab_Y[6];/* conv:2^-7 , val:0...1 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_PID_MotorRevTab_I[30];

/* conv:2^0 , val:0...36 , min-max:0~45 */
extern _C_A_L UInt16 A_Cal_PID_MotorRevTab_P[30];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L Int16 A_Cal_PID_MotorRevTab_X[6];

/* conv:2^-3rpm , val:0...4000 , min-max:0~4000 */
extern _C_A_L UInt16 A_Cal_PID_MotorRevTab_Y[5];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_PID_QpTable[6];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L Int32 A_Cal_PID_RotorRpm;

/* conv:2^-3rpm , val:125 , min-max:0~4000 */
extern _C_A_L UInt16 A_Cal_PID_VehSpdLimit;

/* conv:2^-5km/h , val:20 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_PID_VsQpTable[6];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L UInt16 A_Cal_PID_VsTab[6];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_PowerLimit_X[3];

/* conv:2^-7V , val:9...12 , min-max:0~20 */
extern _C_A_L UInt16 A_Cal_PowerLimit_Y[3];


extern _C_A_L UInt16 A_Cal_AR_TorqueRate_X[6];

extern _C_A_L UInt16 A_Cal_AR_TorqueRate_Y[6];


/* conv:2^-8 , val:0.39844...0 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_PowerWindow;/* conv:2^-7V , val:0.7 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_Power_High;/* conv:2^-7V , val:16 , min-max:15~20 */
extern _C_A_L Int16 A_Cal_Power_Low;/* conv:2^-7V , val:9 , min-max:6~11 */
extern _C_A_L Int16 A_Cal_Power_LowReset;/* conv:2^-7V , val:6 , min-max:5~9 */
extern _C_A_L Int16 A_Cal_Power_Over;/* conv:2^-7V , val:24 , min-max:20~30 */

/* conv:2^-4deg/s , val:90 , min-max:0~2000 */
extern _C_A_L Int16 A_Cal_RotorComCoef;

/* conv:2^-14 , val:-0.00067139 , min-max:-0.001~0 */
extern _C_A_L Int16 A_Cal_SE_EndAngLength;

/* conv:2^-4deg , val:25 , min-max:0~60 */
extern _C_A_L Int16 A_Cal_SE_EndLearnMaxAng;

/* conv:2^-4deg , val:502.625 , min-max:0~800 */
extern _C_A_L Int16 A_Cal_SE_EndLearnREV;

/* conv:2^-4deg/s , val:15 , min-max:0~180 */
extern _C_A_L Int16 A_Cal_SE_EndLearnSaveREV;

/* conv:2^-4deg/s , val:90 , min-max:0~180 */
extern _C_A_L Int16 A_Cal_SE_EndLearnSaveTBT;/* conv:2^-10Nm , val:5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_SE_EndLearnTBT;/* conv:2^-10Nm , val:8 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_SE_EndLearnMaxAng;/* conv:2^-4deg , val:502.625 , min-max:0~800 */
extern _C_A_L Int16 A_Cal_SE_EndOverrideLength;/* conv:2^-4deg , val:90 , min-max:0~180 */
extern _C_A_L Int16 A_Cal_SE_BYDOverrideOpsiLength;/* conv:2^-4deg , val:20 , min-max:0~180 */
extern _C_A_L Int16 A_Cal_SE_BYDRackMaxLength;/* conv:2^-4deg , val:960 , min-max:0~180 */   
extern _C_A_L Int16 A_Cal_SE_EndAngLength;/* conv:2^-4deg , val:25 , min-max:0~60 */
extern _C_A_L Int16 A_Cal_SE_EndLearnREV; /* conv:2^-4deg/s , val:15 , min-max:0~180 */
extern _C_A_L Int16 A_Cal_SE_EndStopPlus;/* conv:2^-7 , val:1 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_SE_EndStopBackMax;/* conv:2^-7Nm , val:50 , min-max:0~60 */
extern _C_A_L Int16 A_Cal_SE_ReturnTrqCoef;
extern _C_A_L Int16 A_Cal_SE_EndStopPlus;/* conv:2^-7 , val:1 , min-max:0~2 */


extern _C_A_L UInt16 A_Cal_SE_ExcessDampMaxTime;/* conv:2^0 , val:300 , min-max:0~500 */
extern _C_A_L Int16 A_Cal_SE_MaxDampComp;/* conv:2^-7Nm , val:50 , min-max:0~60 */


extern _C_A_L Int16 A_Cal_SE_ReturnTrqCoef;
extern _C_A_L Int16 A_Cal_SE_StrTrqAngCoefTab_X[6];
extern _C_A_L Int16 A_Cal_SE_StrTrqAngCoefTab_Y[6];
extern _C_A_L Int16 A_Cal_SE_StrTrqRevCoefTab_X[6];
extern _C_A_L Int16 A_Cal_SE_StrTrqRevCoefTab_Y[6];

extern _C_A_L Int16 A_Cal_SE_StrAngEndCompTab_A[7];

/* conv:2^-4deg , val:0...25 , min-max:0~60 */
extern _C_A_L Int16 A_Cal_SE_StrAngEndCompTab_C[4];

/* conv:2^-4deg , val:0...0 , min-max:-30~30 */
extern _C_A_L Int16 A_Cal_SE_StrAngEndCompTab_T[4][7];

/* conv:2^-7Nm , val:0...-50 , min-max:-80~0 */
extern _C_A_L UInt16 A_Cal_SE_StrAngEndCompTab_V[4];

/* conv:2^-5km/h , val:0...10 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_SE_StrdAngEndCompTab_A[7];

/* conv:2^-4deg , val:0...30 , min-max:0~60 */
extern _C_A_L Int16 A_Cal_SE_StrdAngEndCompTab_T[4][7];

/* conv:2^-7Nm , val:0...-0.0625 , min-max:-40~0 */
extern _C_A_L UInt16 A_Cal_SE_StrdAngEndCompTab_V[4];
extern _C_A_L Int16 A_Cal_SE_StrAngEndCompTab_C_Revser[3];
                                 /* conv:2^-4deg , val:0...0 , min-max:-30~30 */

extern _C_A_L Int16 A_Cal_SE_StrAngEndCompTab_T_Revser[3][7];
                                 /* conv:2^-7Nm , val:0...-50 , min-max:-80~0 */

extern _C_A_L UInt16 A_Cal_SE_StrAngEndCompTab_V_Revser[3];
                                /* conv:2^-5km/h , val:0...10 , min-max:0~200 */

extern _C_A_L Int16 A_Cal_SE_StrdAngEndCompTab_A_Revser[7];
                                  /* conv:2^-4deg , val:0...25 , min-max:0~60 */

extern _C_A_L Int16 A_Cal_SE_StrdAngEndCompTab_T_Revser[3][7];
extern _C_A_L UInt16 A_Cal_SE_StrdAngEndCompTab_V_Revser[3];
                                 /* conv:2^-5km/h , val:0...10 , min-max:0~60 */

/* conv:2^-5km/h , val:0...10 , min-max:0~60 */
extern _C_A_L Int32 A_Cal_SL_ColdCoef;/* conv:2^-7 , val:0.5 , min-max:0~1 */
extern _C_A_L Int32 A_Cal_SL_ColdCurrent;/* conv:2^-7A , val:30 , min-max:30~80 */
extern _C_A_L Int32 A_Cal_SL_ItegLimit;

/* conv:2^6A^2 , val:480000000 , min-max:0~600000000 */
extern _C_A_L Int32 A_Cal_SL_MaxIaxIa;

/* conv:2^6A^2 , val:384000000 , min-max:0~600000000 */
extern _C_A_L UInt32 A_Cal_SL_OverDelay;

/* conv:2^0 , val:30000 , min-max:0~100000 */
extern _C_A_L Int32 A_Cal_SL_SqureDown;

/* conv:2^6A^2 , val:320000000 , min-max:0~600000000 */
extern _C_A_L Int16 A_Cal_SL_StallCoTab_X[4];

/* conv:2^-7A , val:0...100 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_SL_StallCoTab_Y[4];

/* conv:2^-12A/ms , val:0.0048828...-0.050049 , min-max:-0.5~0.5 */
extern _C_A_L Int16 A_Cal_SL_StallPlus;/* conv:2^-7 , val:1 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_ShutDownTime;/* conv:2^0 , val:100 , min-max:0~1000 */
extern _C_A_L UInt16 A_Cal_SleepTime;/* conv:2^0 , val:2 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_Stall_HoldAmp;/* conv:2^-4 , val:-4 , min-max:-10~0 */
extern _C_A_L Int32 A_Cal_Stall_HoldDnRate1;

/* conv:2^-15 , val:16/32768 , min-max:0~1 */
extern _C_A_L Int32 A_Cal_Stall_HoldDnRate2;

/* conv:2^-15 , val:1/32768 , min-max:0~1 */
extern _C_A_L Int32 A_Cal_Stall_HoldFall1;/* conv:2^-15 , val:0.5 , min-max:0~1 */
extern _C_A_L Int32 A_Cal_Stall_HoldFall2;/* conv:2^-15 , val:0.6 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_Stall_HoldIblockPer;/* conv:2^-10 , val:0.7 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_Stall_HoldIreleasePer;/* conv:2^-10 , val:0.4 , min-max:0~1 */
extern _C_A_L Int32 A_Cal_Stall_HoldMax;/* conv:2^-7A , val:5 , min-max:0~10 */
extern _C_A_L UInt16 A_Cal_Stall_HoldRcr;/* conv:2^0 , val:10 , min-max:0~1000 */
extern _C_A_L Int16 A_Cal_Stall_HoldRevblock;

/* conv:2^-4deg/s , val:5 , min-max:0~90 */
extern _C_A_L Int16 A_Cal_Stall_HoldRevrelease;

/* conv:2^-4deg/s , val:10 , min-max:0~90 */
extern _C_A_L UInt16 A_Cal_Stall_HoldTmr;

/* conv:2^0 , val:1000 , min-max:0~1000 */
extern _C_A_L Int32 A_Cal_Stall_HoldUpRate;

/* conv:2^-15 , val:0.005556 , min-max:0~1 */
extern _C_A_L Int32 A_Cal_Stall_HoldWaveRate;

/* conv:2^-7 , val:0.015625 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_StrAng_Offset;

/* conv:2^-4deg , val:0 , min-max:0~2000 */
extern _C_A_L UInt16 A_Cal_StrAng_Scale;

/* conv:2^-4 , val:0.0625 , min-max:0~0.1 */
extern _C_A_L UInt16 A_Cal_TCL_CloseloopVsLimit_X[10];

/* conv:2^-5km/h , val:0...140 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_TCL_CloseloopVsLimit_Y[10];


extern _C_A_L Int16 A_Cal_TCL_CloseloopLimitCoef_X[11];

extern _C_A_L UInt16 A_Cal_TCL_CloseloopLimitCoef_V[5];

extern _C_A_L Int16 A_Cal_TCL_CloseloopLimitCoef_Y[55];

extern _C_A_L Int16 A_Cal_TCL_CloseloopLimitCoefReverse_X[11];

extern _C_A_L UInt16 A_Cal_TCL_CloseloopLimitCoefReverse_V[5];

extern _C_A_L Int16 A_Cal_TCL_CloseloopLimitCoefReverse_Y[55];


/* conv:2^-7 , val:0...30 , min-max:0~50 */
extern _C_A_L Int16 A_Cal_TCL_DampConvPlus;

/* conv:2^-7 , val:-0.0625 , min-max:-0.25~0.25 */
extern _C_A_L Float64 A_Cal_TCL_ESTLOAD_COEF;/* conv:2^0 , val:0.7 , min-max:0~1 */
extern _C_A_L Float64 A_Cal_TCL_ESTLOAD_RATIO;

/* conv:2^0 , val:-4.5/108*20.5 , min-max:-2~2 */
extern _C_A_L Float64 A_Cal_TCL_ESTLOAD_TRWFR[20];

/* conv:2^0 , val:0.5...500 , min-max:0~1000 */
extern _C_A_L Int16 A_Cal_TCL_EndConvPlus;

extern _C_A_L Int16 A_Cal_TCL_OpenloopTargetPlus;

extern _C_A_L Int16 A_Cal_TCL_CloseloopTargetPlus;

/* conv:2^-7 , val:-0.0625 , min-max:-0.25~0.25 */
extern _C_A_L Int16 A_Cal_TCL_HysConvPlus;

/* conv:2^-7 , val:0.-0625 , min-max:-0.25~0.25 */
extern _C_A_L Int16 A_Cal_TCL_PIDKI_Tab_X[6];

/* conv:2^-3rpm , val:0...125 , min-max:0~1000 */
extern _C_A_L Int16 A_Cal_TCL_PIDKI_Tab_Y[6];

/* conv:2^0 , val:0...18 , min-max:0~50 */
extern _C_A_L Int16 A_Cal_TCL_PIDKP;

/* conv:2^0 , val:0...1000 , min-max:0~3000 */
extern _C_A_L Float64 A_Cal_TCL_PIDOUT_TRWFR[5];

/* conv:2^0 , val:2...100 , min-max:0~1000 */
extern _C_A_L Int16 A_Cal_TCL_PidKiTabGen_X[6];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L UInt16 A_Cal_TCL_PidKiTabGen_Y[5];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_TCL_PidKiTabGen_Z[30];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L Int16 A_Cal_TCL_PidKpTabGen_X[6];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L UInt16 A_Cal_TCL_PidKpTabGen_Y[5];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_TCL_PidKpTabGen_Z[30];

/* conv:2^0 , val:0...3000 , min-max:0~3000 */
extern _C_A_L Int32 A_Cal_TCL_RedundantDnRate;/* conv:2^-7 , val:100 , min-max:0~100 */
extern _C_A_L Int32 A_Cal_TCL_RedundantUpRate;/* conv:2^-7 , val:0.2 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_TCL_ReturnConvPlus;

/* conv:2^-7 , val:-0.0625 , min-max:-0.25~0.25 */
extern _C_A_L Int16 A_Cal_TCL_ReturnOutLimit;/* conv:2^-7 , val:20 , min-max:0~30 */
extern _C_A_L Float64 A_Cal_TCL_SOF_COEF[2];

/* conv:2^0 , val:40...1 , min-max:0~100 */
extern _C_A_L Int16 A_Cal_TCL_StrTrqLoadTab_X[16];

/* conv:2^-10Nm , val:0...200 , min-max:0~250 */
extern _C_A_L UInt16 A_Cal_TCL_StrTrqLoadTab_Y[9];

/* conv:2^-5km/h , val:0...160 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_TCL_StrTrqLoadTab_Z1[144];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_TCL_StrTrqLoadTab_Z2[144];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_TCL_StrTrqLoadTab_Z3[144];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_TCL_StrTrqLoadTab_Z_LKA[144];

/* conv:2^-10Nm , val:0...5 , min-max:0~10 */
extern _C_A_L Int16 A_Cal_TCL_TARGETMAX;/* conv:2^-10 , val:10 , min-max:0~10 */
extern _C_A_L UInt16 A_Cal_TDK_TempScale_X[39];

/* conv:2^-7V , val:0.15625...4.7188 , min-max:0~5 */
extern _C_A_L Int16 A_Cal_TDK_TempScale_Y[39];

/* conv:2^-3��C , val:130...-45 , min-max:-50~150 */
extern _C_A_L Int16 A_Cal_TL_AssTorDownTab_X[6];

/* conv:2^-10Nm , val:-5...5 , min-max:-10~10 */
extern _C_A_L Int16 A_Cal_TL_AssTorDownTab_Y[6];

/* conv:2^-7Nm , val:-100...-5 , min-max:-100~100 */
extern _C_A_L Int16 A_Cal_TL_AssTorUpTab_X[6];

/* conv:2^-10Nm , val:-5...5 , min-max:-10~10 */
extern _C_A_L Int16 A_Cal_TL_AssTorUpTab_Y[6];

/* conv:2^-7Nm , val:5...100 , min-max:-100~100 */
extern _C_A_L UInt16 A_Cal_TL_TorFallTab_X[16];

/* conv:2^-3rpm , val:800...4500 , min-max:0~5000 */
extern _C_A_L Int16 A_Cal_TL_TorFallTab_Y[16];

/* conv:2^-7Nm , val:100...6.25 , min-max:-100~100 */


/* conv:2^-10Nm/ms , val:0.099609 , min-max:0~1 */
extern _C_A_L UInt16 A_Cal_TOC_StraightCoef;
extern _C_A_L UInt16 A_Cal_TOC_VehSpdLongComp;/* conv:2^-5 , km/h , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_TQ_RevTrqFirTab_X[9];

/* conv:2^-3rpm , val:0...64 , min-max:0~1000 */
extern _C_A_L Int16 A_Cal_TQ_RevTrqFirTab_Y[9];

extern _C_A_L UInt16 A_Cal_TQ_VsTrqFirTab_Y[6];

/* conv:2^-5km/h , val:0...80 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_TQ_VsTrqFirTab_X[7];/* conv:2^-7 , val:0...4 , min-max:0~5 */
extern _C_A_L UInt16 A_Cal_TQ_VsTrqFirTab_X_Reserve[6];                     /* conv:2^-5km/h , val:0...80 , min-max:0~200 */

extern _C_A_L Int16 A_Cal_TQ_VsTrqFirTab_Y_Reserve[6];/* conv:2^-7 , val:0...4 , min-max:0~5 */

extern _C_A_L Int16 A_Cal_TQ_VsTrqFirTab_Z[42];

/* conv:2^0Hz , val:0...2000 , min-max:0~2000 */
extern _C_A_L Int16 A_Cal_TQ_VehSpdPCTabNew_A[100];

/* conv:2^-7 , val:0...1.37 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_TQ_VehSpdPCTabNew_C[40];/* conv:2^-7 , val:1...0 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_TQ_VehSpdPCTabNew_T[10];

/* conv:2^-10Nm , val:0...4.5 , min-max:0~10 */
extern _C_A_L UInt16 A_Cal_TQ_VehSpdPCTabNew_V[10];

/* conv:2^-5km/h , val:0...160 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_TQ_VehSpdPCTabNew_W[4];

/* conv:2^-4 deg/s , val:0...800 , min-max:0~2000 */
extern _C_A_L UInt16 A_Cal_TQ_VsTrqDzTab_X[6];

/* conv:2^-5km/h , val:0...140 , min-max:0~200 */
extern _C_A_L Int16 A_Cal_TQ_VsTrqDzTab_Y[6];

/* conv:2^-7 , val:0...4 , min-max:0~5 */
extern _C_A_L Int16 A_Cal_TempLimit_X[6];

/* conv:2^-3degC , val:-40...125 , min-max:-50~150 */
extern _C_A_L UInt16 A_Cal_TempLimit_Y[6];

/* conv:2^-12 , val:0...1 , min-max:0~1 */
extern _C_A_L Int16 A_Cal_TempLow;

/* conv:2^-3degC , val:-40 , min-max:-50~150 */
extern _C_A_L Int16 A_Cal_TempOver;

/* conv:2^-3degC , val:100 , min-max:-50~150 */
extern _C_A_L UInt32 A_Cal_UdsInhabitProtectKey;

/* conv:2^0A^2 , val:0x9C1ABF38 , min-max: */
extern _C_A_L Int16 A_Cal_VehSpd_Ded;

/* conv:2^-5km/h , val:0.5 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_VehSpd_DedRvr;

/* conv:2^-5km/h , val:1.5 , min-max:0~2 */
extern _C_A_L Int16 A_Cal_VehSpd_GridMax;

/* conv:2^-5km/h , val:10 , min-max:0~20 */
extern _C_A_L Int16 A_Cal_VehSpd_Max;

/* conv:2^-5km/h , val:250 , min-max:0~300 */
extern _C_A_L UInt16 A_Cal_VehSpd_Mid;

/* conv:2^-5km/h , val:100 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_VehSpd_Offset;

/* conv:2^-5km/h , val:0 , min-max:0~200 */
extern _C_A_L UInt16 A_Cal_VehSpd_Scale;

/* conv:2^-15km/h , val:0.05625 , min-max:0~0.1 */
extern _C_A_L UInt16 A_Cal_WakeupTime;/* conv:2^0 , val:2 , min-max:0~100 */



extern _C_A_L Int16 A_Cal_SE_StrTrqAngCoefTab_X[6];
extern _C_A_L Int16 A_Cal_SE_StrTrqAngCoefTab_Y[6];
                                 /* vehspd conv:2^-5 km/h*/

extern _C_A_L Int16 A_Cal_SE_CurrentShrinkCoef_A[4];
                                  /* conv:2^-4deg , val:0...25 , min-max:0~60 */

extern _C_A_L Int16 A_Cal_SE_CurrentShrinkCoef_V[3];


extern _C_A_L Int16 A_Cal_SE_CurrentShrinkCoef_T[3][4];
                                /* 0 - 1 -> 0 - 128*/

extern _C_A_L Int16 A_Cal_SE_CurrentShrinkCoefPreci;

extern _C_A_L Int16 A_Cal_SE_SteerEndCompMindStrAng;
extern _C_A_L Int16 A_Cal_SE_SteerEndCompMindStrAngGap;
extern _C_A_L Int16 A_Cal_SE_SteerEndCompMindStrAngDeadZone;

extern _C_A_L Int16 A_Cal_SE_StrTrqRevCoefTab_X[6];
extern _C_A_L Int16 A_Cal_SE_StrTrqRevCoefTab_Y[6];
extern _C_A_L Int16 A_Cal_BT_VsTrqCoef_X[6];
extern _C_A_L UInt16 A_Cal_BT_VsTrqCoef_Y[6];
extern _C_A_L Int16 A_Cal_BT_VsTrqCoef_Z[6][6];


extern _C_A_L Int16 A_Cal_SE_EndKiCoef_X[7];
                               /* conv:2^-4deg , val:0...25 , min-max:0~60 */
extern _C_A_L Int16 A_Cal_SE_EndKiCoef_Y[7];
                               /* 0 - 128 */

extern _C_A_L Int16 A_Cal_SE_EndKpCoef_X[7];
                               /* conv:2^-4deg , val:0...25 , min-max:0~60 */			
extern _C_A_L Int16 A_Cal_SE_EndKpCoef_Y[7];
                               /* 0 - 128 */	

extern _C_A_L Int16 A_Cal_AR_PAngTrqCoef;
extern _C_A_L Int16 A_Cal_AR_NAngTrqCoef;	



#endif                                 /* RTW_HEADER_CalVar_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
