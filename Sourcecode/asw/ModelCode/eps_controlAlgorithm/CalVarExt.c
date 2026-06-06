
#include "rtwtypes.h"
#include "CalVarExt.h"

#define _ADDR_R0(x)

#if 1
_C_A_L Int16 Cal_SE_DefaultEndAng = (Macro_SteerWheelMaxAng-320);//2^-4deg,MaxAng-10
_C_A_L  Int16 Cal_SE_EndMaxSumAng = (Macro_SteerWheelMaxAng*2+640);//2^-4deg,MaxAng+20
_C_A_L  Int16 Cal_SE_EndLRDiffAng = 640;//2^-4deg,20deg
_C_A_L  UInt16 Cal_SE_EndStyTime = 300;//ms
_C_A_L  Int16 Cal_SE_EndLearnTrq = 5120;//2^-10Nm,
_C_A_L  Int16 Cal_SE_EndSaveTrq = 4096;//2^-10Nm,
_C_A_L  Int16 Cal_SE_EndLearnRev = 240;//2^-4deg/s
_C_A_L  UInt16 Cal_SE_EndSaveVehSpd = 640;//2^-5Km/h,
_C_A_L  UInt16 Cal_SE_EndSaveTime = 100;//ms
#else
_C_A_L  Int16 Cal_SE_DefaultEndAng = 6400;//2^-4deg,516-10
_C_A_L  Int16 Cal_SE_EndMaxSumAng = 14400;//2^-4deg,516*2+20
_C_A_L  Int16 Cal_SE_EndLRDiffAng = 900;//2^-4deg,20deg
_C_A_L  UInt16 Cal_SE_EndStyTime = 300;//ms
_C_A_L  Int16 Cal_SE_EndLearnTrq = 3072;//2^-10Nm,
_C_A_L  Int16 Cal_SE_EndSaveTrq = 2048;//2^-10Nm,
_C_A_L  Int16 Cal_SE_EndLearnRev = 240;//2^-4deg/s
_C_A_L  UInt16 Cal_SE_EndSaveVehSpd = 640;//2^-5Km/h,
_C_A_L  UInt16 Cal_SE_EndSaveTime = 100;//ms
#endif
/*******************RCS******************************/
_C_A_L UInt32 Cal_RCS_HeatExtendTime = 0;//ms
_C_A_L Int16  Cal_RCS_MaxCurrent = 12800;//2^-7,A
_C_A_L Int16  Cal_RCS_BrakeExitSpd = 10;//2^-4,deg/s,
_C_A_L UInt16 Cal_RCS_BrakeLowSpdExitEnb = 1;//
_C_A_L UInt16 Cal_RCS_BrakeLowSpdExitTmr = 100;//2^0,ms
_C_A_L UInt16 Cal_RCS_BrakeHoldTmr = 150;//2^0,ms
_C_A_L Int16 Cal_RCS_ExitCoefSlope = 10;//2^-14,閫�鍑篟CS鐨勫姪鍔涚郴鏁版枩鐜囷紝0%-100%
_C_A_L Int16 Cal_RCS_Enter_StrTrq = 3072;//2^-10,Nm
_C_A_L Int16 Cal_RCS_Exit_StrTrq0 =  2048;//2^-10,Nm,鍚屽悜
_C_A_L UInt16 Cal_RCS_Exit_HoldTmr0 = 150;//2^0,ms 200
_C_A_L UInt16 Cal_RCS_Exit_HoldTmrTick_X[5] = //2^-10,Nm
{ 2048,  3072,  4096,  5120, 6144};
_C_A_L UInt16 Cal_RCS_Exit_HoldTmrTick_Y[5] = //2^0,ms
{1,  1,  1,  1,  1};
_C_A_L Int16 Cal_RCS_Max_StrAng = Macro_SteerWheelMaxAngP91;//2^-4,deg,MAX掳-10%
_C_A_L Int16 Cal_RCS_Max_MechAng = Macro_SteerWheelMaxAngP99;//2^-4,deg,1032.12/2-1%
_C_A_L Int16 Cal_RCS_EndAngMargin = 240;//2^-4,deg,15掳
_C_A_L Int16 Cal_RCS_AngleRampRate = 4;//2^-4,deg/ms
_C_A_L Int16 Cal_RCS_MaxStrWheelSpd = 3863;//2^-3,rpm,120deg/s,v=(120*fsMotorToSteerRatio/600)*8
_C_A_L Int16 Cal_RCS_SpdLoopMaxDiff = 3863;//2^-3,rpm,
_C_A_L UInt16 Cal_RCS_SpdLoopKi = 8;//2^-7
_C_A_L UInt16 Cal_RCS_SpdLoopKp = 120;//2^0
_C_A_L UInt16 Cal_RCS_SpdLoopPI_X[4] = {64,96,144,192};//2^-4,deg
_C_A_L UInt16 Cal_RCS_SpdLoopKp_Y[4] = {80,280,540,980};//2^0,
_C_A_L UInt16 Cal_RCS_SpdLoopKi_Y[4] = {200,730,1394,1968};
_C_A_L UInt16 Cal_RCS_AngLoopKp_X[4] = {48,96,144,192};//2^-4,deg
_C_A_L UInt16 Cal_RCS_AngLoopKp_Y[4] = {25,64,141,274};
/*****************************************/
_C_A_L uint8 Cal_TOC_Enable = 0;
_C_A_L Int16 Cal_TOC_ActStrAng = 64;/* conv:2^-4 , deg , min-max:600~1200 */
_C_A_L Int16 Cal_TOC_ActStrSpd = 160;/* conv:2^-4 , deg/s , min-max:0~360 */
_C_A_L Int16 Cal_TOC_ActStrTrq = 1536;/* conv:2^-10 , Nm , min-max:0~8 */
_C_A_L UInt16 Cal_TOC_ActVehSpd = 1600U;/* conv:2^-5 , km/h , min-max:0~200 */
_C_A_L Int16 Cal_TOC_DeadZoneTrq = 307;/* conv:2^-10 , Nm  , min-max:0~8 */
_C_A_L Int16 Cal_TOC_ExtStrAng = 800;/* conv:2^-4 , deg , min-max:0~100 */
_C_A_L Int16 Cal_TOC_ExtStrSpd = 1120;/* conv:2^-4 , deg/s , min-max:0~360 */
_C_A_L Int16 Cal_TOC_ExtStrTrq = 3072;/* conv:2^-10 , Nm , min-max:0~8 */
_C_A_L UInt16 Cal_TOC_ExtVehSpd = 640U;/* conv:2^-5 , km/h , min-max:0~200 */
_C_A_L UInt16 Cal_TOC_FuncActTime = 5000U;/* conv:2^0 , mS 锛宮in-max:0~8 */
_C_A_L UInt16 Cal_TOC_FuncExtTime = 100U;/* conv:2^0 , mS 锛宮in-max:0~8 */
_C_A_L Int16 Cal_TOC_HoldStrAng = 80;/* conv:2^-4 , deg , min-max:600~1200 */
_C_A_L Int16 Cal_TOC_HoldStrSpd = 240;/* conv:2^-4 , deg/s , min-max:0~360 */
_C_A_L Int16 Cal_TOC_HoldStrTrq = 3072;/* conv:2^-10 , Nm , min-max:0~8 */
_C_A_L UInt16 Cal_TOC_HoldVehSpd = 1280U;/* conv:2^-5 , km/h , min-max:0~200 */
_C_A_L UInt32 Cal_TOC_LongFiltCoef = 4U;/* conv:2^-18 , min-max:0~1 */
_C_A_L Int32 Cal_TOC_LongTrqOutRate = 1049;/* conv:2^-20 , Nm/mS 锛宮in-max:0~8 */
_C_A_L Int16 Cal_TOC_MaxCompTrq = 242;/* conv:2^-7 , Nm , min-max: 0~100 */
_C_A_L Int16 Cal_TOC_MaxDiffTrq = 1024;/* conv:2^-10 ,Nm 锛� min-max:0~8 */
_C_A_L Int16 Cal_TOC_MaxLongTrq = 121;/* conv:2^-7 , Nm , min-max: 0~100 */
_C_A_L Int16 Cal_TOC_MaxShortTrq = 242;/* conv:2^-7 , Nm , min-max: 0~100 */
_C_A_L UInt16 Cal_TOC_MaxVehSpd = 4800U;/* conv:2^-5 , km/h , min-max:0~200 */
_C_A_L UInt32 Cal_TOC_ShortCalcKi = 10U;/* conv:2^-14 , min-max:0~1 */
_C_A_L Int16 Cal_TOC_ShortTrqRate = 1049;/* conv:2^-20 , Nm/mS 锛宮in-max:0~8 */
_C_A_L UInt16 Cal_TOC_StraightCoef = 410U;/*conv:2^0 ,*/
_C_A_L UInt16 Cal_TOC_VehSpdLongComp = 960U;/* conv:2^-5 , km/h , min-max:0~200 */
_C_A_L UInt16 Cal_TOC_LongFilterTick = 50U;/* conv:2^0 , ms , min-max:0~200 */
_C_A_L Int16 Cal_TOC_VsYawRate_X[8] = {640,1280,1920,2560,3200,3840,4480,5120};//2^-5,km/h
_C_A_L Int16 Cal_TOC_VsYawRate_Y[8] = {8,8,8,8,8,8,8,8};//{4,4,4,4,4,4,4,4};//rad/s

volatile Int16 Cal_SHI_AllowedVSpd _ADDR_R0(0x0116) = 2560;/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Float64 Cal_SHI_Depth_Tab_Out[24] _ADDR_R0(0x172a) = { 1.0, 1.0, 1.0, 1.0, 1.0,
  1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
  1.0, 1.0, 1.0 } ;

/* conv:2^0 , val:0...100 , min-max:0~199 */
volatile UInt16 Cal_SHI_Depth_Tab_Vs[3] _ADDR_R0(0x0246) = { 0U, 160U, 320U } ;

/* conv:2^-5 , val:0...10 , min-max:0~20 */
volatile UInt16 Cal_SHI_Depth_Tab_dAng[8] _ADDR_R0(0x06d6) = { 0U, 800U, 1600U, 4800U,
  8000U, 12800U, 19200U, 25600U } ;

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
volatile Int16 Cal_SHI_FreqDetGrid _ADDR_R0(0x0118) = 4;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Int32 Cal_SHI_FreqDetGridDecreaseStep _ADDR_R0(0x01f8) = 51;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Int32 Cal_SHI_FreqDetGridIncreaseStep _ADDR_R0(0x01fc) = 2048;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile UInt8 Cal_SHI_FreqDetGridWaveTimeHigh _ADDR_R0(0x3382) = 200U;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile UInt8 Cal_SHI_FreqDetGridWaveTimeLow _ADDR_R0(0x3383) = 1U;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile UInt8 Cal_SHI_FreqDetGridWindowPoint _ADDR_R0(0x3384) = 10U;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Int16 Cal_SHI_FreqDetShutAng _ADDR_R0(0x011a) = 80;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Int16 Cal_SHI_FreqDetShutGrid _ADDR_R0(0x011c) = 307;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Int16 Cal_SHI_FreqDetShutTrq _ADDR_R0(0x011e) = 819;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Int16 Cal_SHI_FreqDetShutdAng _ADDR_R0(0x0120) = 200;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Int16 Cal_SHI_FreqGainNew_X[15] _ADDR_R0(0x0a4a) = { 32, 288, 320, 352, 384, 416,
  448, 480, 512, 544, 576, 608, 640, 672, 960 } ;

/* conv:2^-5 , val:0...10 , min-max:0~20 */
volatile Int16 Cal_SHI_FreqGainNew_Y[15] _ADDR_R0(0x0a68) = { 0, 0, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 0, 0 } ;//zmq

/* conv:2^-5 , val:0...10 , min-max:0~20 */
volatile Float64 Cal_SHI_Freq_Tab_Out[24] _ADDR_R0(0x178a) = { 100.0, 100.0, 100.0, 100.0,
  100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
  100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0 } ;

/* conv:2^0 , val:0...100 , min-max:0~199 */
volatile UInt16 Cal_SHI_Freq_Tab_Vs[3] _ADDR_R0(0x024c) = { 0U, 160U, 320U } ;

/* conv:2^-5 , val:0...10 , min-max:0~20 */
volatile UInt16 Cal_SHI_Freq_Tab_dAng[8] _ADDR_R0(0x06e6) = { 0U, 800U, 1600U, 4800U, 8000U,
  12800U, 19200U, 25600U } ;

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
volatile Int16 Cal_SHI_Gain2_Tab_Ang[8] _ADDR_R0(0x06f6) = { 0, 50, 100, 300, 500, 800,
  1200, 1600 } ;

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
volatile Int16 Cal_SHI_Gain2_Tab_Out[24] _ADDR_R0(0x12a2) = { 1152, 1152, 1152, 1152, 1152,
  1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152,
  1152, 1152, 1152, 1152, 1152, 1152 } ;

/* conv:2^0 , val:0...100 , min-max:0~199 */
volatile Int16 Cal_SHI_Gain2_Tab_Trq[3] _ADDR_R0(0x0252) = { 100, 400, 800 } ;

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
volatile Int16 Cal_SHI_Gain_Tab_Out_Trq[24] _ADDR_R0(0x12d2) = { 1152, 1152, 1152, 1152,
  1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152,
  1152, 1152, 1152, 1152, 1152, 1152, 1152 } ;

/* conv:2^0 , val:0...100 , min-max:0~199 */
volatile Int16 Cal_SHI_Gain_Tab_Out_dAng[24] _ADDR_R0(0x1302) = { 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 192, 192, 192, 192, 192,
  192, 192, 192 } ;

/* conv:2^0 , val:0...100 , min-max:0~199 */
volatile Int16 Cal_SHI_Gain_Tab_Trq[8] _ADDR_R0(0x0706) = { 0, 410, 819, 1229, 1536, 2048,
  2560, 3072 } ;

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
volatile UInt16 Cal_SHI_Gain_Tab_Vs[3] _ADDR_R0(0x0258) = { 0U, 2880U, 3840U } ;

/* conv:2^-5 , val:0...10 , min-max:0~20 */
volatile Int16 Cal_SHI_Gain_Tab_dAng[8] _ADDR_R0(0x0716) = { 0, 50, 100, 300, 500, 800,
  1200, 1600 } ;

/* conv:2^0 , val:0...1600 , min-max:0~2000 */
volatile Int16 Cal_SHI_ShimmyDeadTrq _ADDR_R0(0x0122) = 1;

/* conv:2^-4 , val:15 , min-max:0~90 */
volatile Float64 Cal_SHI_Width_Tab_Out[24] _ADDR_R0(0x17ea) = { 0.2, 0.2, 0.2, 0.2, 0.2,
  0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
  0.2, 0.2, 0.2 } ;

/* conv:2^0 , val:0...100 , min-max:0~199 */
volatile UInt16 Cal_SHI_Width_Tab_Vs[3] _ADDR_R0(0x025e) = { 0U, 160U, 320U } ;

/* conv:2^-5 , val:0...10 , min-max:0~20 */
volatile UInt16 Cal_SHI_Width_Tab_dAng[8] _ADDR_R0(0x0726) = { 0U, 800U, 1600U, 4800U,
  8000U, 12800U, 19200U, 25600U } ;

/* conv:2^0 , val:0...1600 , min-max:0~2000 */

volatile uint8 Cal_SHI_Enable _ADDR_R0(0x3385) = 0;

volatile Int16 Cal_SHI_MaxCompTrq _ADDR_R0(0x0124) = 1000;/* conv:2^-7Nm , val:30 , min-max:0~50 */

volatile Int16 Cal_SHI_TrqPlus _ADDR_R0(0x0126) = 64;/* conv:2^-7Nm , val:30 , min-max:0~50 */

volatile sint16 Cal_WS_FilterCoef _ADDR_R0(0x00c2) = 16;/* conv:2^-7 , val:0.125 , min-max:0~1 */

volatile sint16 Cal_MapSwitchSpeedLimit = 640;/* conv:2^5 , val:20 km/h , min-max:0~250 */

volatile sint16 Cal_MapSwitchTorqueLimit = 2048;/* conv:2^10 , val:2 NM , min-max:-10~10 */

volatile sint16 Cal_MapSwitchTime = 50;/* conv:2^0 , val:50 ms , min-max:0~100 */

volatile sint32 Cal_MaxIntglSplyVal _ADDR_R0(0x017c) = 128000;
volatile sint16 Cal_SupplyVMonThd _ADDR_R0(0x000e) = 1216;
volatile uint16 Cal_SplyVMonVehSpdThd _ADDR_R0(0x0010) = 640;

volatile uint16 Cal_TEvasiveManeuverStop _ADDR_R0(0x0000) = 100;
volatile uint16 Cal_VEvasiveManeuverVehSpd _ADDR_R0(0x0002) = 1600;
volatile sint16 Cal_AEvasiveManeuverAng _ADDR_R0(0x0004) = 1600;
volatile sint16 Cal_DEvasiveManeuverSpd _ADDR_R0(0x0006) = 1600;
volatile uint16 Cal_TParkManeuverStop _ADDR_R0(0x0008) = 100;
volatile uint16 Cal_TParkManeuverStart _ADDR_R0(0x000a) = 200;
volatile sint16 Cal_DParkManeuverSpd _ADDR_R0(0x000c) = 1600;

volatile sint16 Cal_EMA_DrvrSteerActvSteerWhlTq _ADDR_R0(0x00d8) = 2048;/* 1024 Referenced by: '<S10>/Constant' */

volatile sint16 Cal_EMA_DrvrSteerActvPinionSteerAgSpd _ADDR_R0(0x00da) = 160;/* 16 Referenced by: '<S10>/Constant' */

volatile uint16 Cal_YawRateCompVehSpd _ADDR_R0(0x0012) = 160;
volatile uint16 Cal_YawRateCompFactor _ADDR_R0(0x0014) = 10;
volatile sint16 Cal_YawRateCompThreshold _ADDR_R0(0x0016) = 200;

volatile Int16 Cal_FC_StudyAngleBreakPoints[22] = { -80, -75, -70, -66,
  -61, -56, -51, -46, -42, -37, -32, 32, 37, 42, 46, 51, 56, 61, 66, 70, 75, 80
} ;                                  /* conv:2^-4 , val:-5~5 , min-max:-20~20 */

volatile UInt16 Cal_FC_StudyAngleIndexMax = 20U;/* conv:2^0 , val:20 , min-max:0~500 */
volatile UInt16 Cal_FC_StudyDtTimer = 99U;/* conv:2^0 , val:99 , min-max:0~500 */
volatile UInt16 Cal_FC_StudyFilterCnt = 30U;/* conv:2^0 , val:30 , min-max:0~100 */
volatile UInt16 Cal_FC_StudyRepeatTimes = 16U;/* conv:2^0 , val:16 , min-max:16~1024 */
volatile Int16 Cal_FC_StudyResultMin = 192;/* conv:2^-7 , val:0.5 , min-max:0~2 */
volatile UInt16 Cal_FC_StudyStrghtTmr = 1000U;
                                   /* conv:2^0ms , val:1000 , min-max:0~10000 */
volatile Int16 Cal_FC_StudyTrqGridMax = 614;
                                      /* conv:2^-10Nm , val:0.6 , min-max:0~1 */
volatile UInt16 Cal_FC_VehSpdCoef_X[5] = { 1920U, 2240U, 2560U, 2880U,
  3200U } ;                   /* conv:2^-5km/h , val:60...100 , min-max:0~200 */

volatile Int16 Cal_FC_VehSpdCoef_Y[5] = { 128, 128, 128, 128, 128 } ;
                           /* conv:2^-7 , val:0.71875...0.39844 , min-max:0~2 */
/* Definition for custom storage class: Global */
volatile UInt16 Cal_FC_CURRENT2STEERTORQUE = 758U;
/* conv:2^-16 , val:MACRO_MOTOR_CURRENT2TORQUE*(MACRO_RAD2DEG/MACRO_ROTOR2STEER) , min-max:0~0.1 */
volatile Int16 Cal_FC_StudyStrghtRec = 1440;/* conv:2^-4 , val:90 , min-max:0~180 */

volatile uint16 Cal_DPFW_PulseValidTime = 100;

volatile uint16 Cal_DPFW_PulseInValidTime = 100;

volatile uint16 Cal_DPFW_PulseCnt = 10;
