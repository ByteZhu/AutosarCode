/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CalVarSupport.c
 *
 * Code generated for Simulink model 'ADV_ExtFunction'.
 *
 * Model version                  : 9.98
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 25 08:42:28 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "CalVarSupport.h"
#include "rtwtypes.h"
#include "ADV_ExtFunction_types.h"

/* Exported data definition */

#define _Support_Offset 0x4000
#define _ADDR_R0(addr) /*__at(RAM_TuningSet_ADDR_Start + _Support_Offset + addr)*/

/* ConstVolatile memory section */
/* Definition for custom storage class: Global */
volatile double Cal_FAA_FcStif _ADDR_R0(0x0680) = 500;
volatile double Cal_FAA_LeadFreq _ADDR_R0(0x0684) = 50;
volatile uint16 Cal_FAA_FC_Lim_X[6] _ADDR_R0(0x0688) = { 0U, 512U, 1024U, 1536U, 2048U, 2560U } ;

volatile uint16 Cal_FAA_FC_Lim_Y[6] _ADDR_R0(0x0694) = {  0U, 8U, 22U, 38U, 66U, 128U } ;
volatile uint16 Cal_FAA_FC_X[8] _ADDR_R0(0x06A0) = { 0U, 320U, 640U, 1280U, 1600U, 2240U, 3200U, 3840U } ;
volatile uint16 Cal_FAA_FC_Y[8] _ADDR_R0(0x06B0) = {  256,  256,  256,  128,  0,  0,  0,  0 } ;
volatile uint16 Cal_FAA_SpdLim_X[8] _ADDR_R0(0x06C0) = { 0U, 320U, 640U, 1280U, 1920U, 2560U, 3200U, 3840U } ;
volatile uint16 Cal_FAA_SpdLim_Y[8] _ADDR_R0(0x06D0) = {  9920,  9920,  9920,  9920,  9920,  9920,  9920,  9920 } ;
volatile uint16 Cal_FAA_SpdLoop_X[8] _ADDR_R0(0x06E0) = { 0U, 320U, 640U, 1280U, 1920U, 2560U, 3200U, 3840U } ;
volatile uint16 Cal_FAA_SpdLoop_Y_I[8] _ADDR_R0(0x06F0)= { 3072,  3072,  3064,  3144,  2928,  3072,  3072,  3072 } ;
volatile uint16 Cal_FAA_SpdLoop_Y_P[8] _ADDR_R0(0x0700) = { 307,  307,  311,  307,  316,  316,  332,  364 } ;
volatile sint16 Cal_LKA_TqOut_X[25] _ADDR_R0(0x0710) = { 0,  300,  420,  480,  520,  546,  645,  743,  843,  900,  996,  1091,  1187,  1283,  1379,  1475,  1581
,  1687,  1794,  2007,  2833,  3866,  4900,  5933,  8000 } ;/* conv:2^-7A , val:0...16.5 , min-max:0~100 */
volatile sint16 Cal_LKA_TqOut_Y[25] _ADDR_R0(0x0742) = { 0,  102,  204,  307,  409,  512,  614,  716,  819,  921,  1024,  1126,  1228,  1331,  1433,  1536,  1638
,  1740,  1843,  2048,  3072,  4096,  5120,  6144,  8192 } ;/* conv:Nm , val:0...3 , min-max:0~5 */
volatile uint16 Cal_FAA_AL_P_X[8] _ADDR_R0(0x0774) = { 0U,  320U,  1280U,  1600U,  2240U,  2880U,  3200U,  3520U} ;
volatile uint16 Cal_FAA_AL_P_Y[8] _ADDR_R0(0x0784) = { 10,  16,  21,  21,  21,  22,  23,  23} ;
volatile uint16 Cal_FAA_LeadGain_X[8] _ADDR_R0(0x0794)= { 0U, 960U, 1280U, 1600U, 1920U, 2240U, 2880U, 3200U } ;
volatile uint16 Cal_FAA_LeadGain_Y[8] _ADDR_R0(0x07A4) = { 5,  5,  4,  2,  4,  0,  5,  4} ;
#if 0
volatile sint16 Cal_LKA_TqLimit_A[7] = { 0, 512, 819, 1024, 1536,
  2048, 3072 } ;                       /* conv:Nm , val:0...3 , min-max:0~5 */

volatile sint16 Cal_LKA_TqLimit_T[49] = { 
  535, 546, 843, 996, 1475, 2007, 2833,
  535, 546, 843, 996, 1475, 2007, 2833,
  535, 546, 843, 1016, 1535, 2088, 2833,
  535, 546, 843, 1036, 1566, 2130, 2833,
  535, 546, 843, 1036, 1592, 2439, 3581,
  525, 535, 843, 1036, 1592, 2439, 3581,
  525, 535, 843, 1036, 1592, 2439, 3581,  } ;/* conv:2^-7A , val:0...16.5 , min-max:0~100 */

volatile uint16 Cal_LKA_TqLimit_V[7] = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;
#else
volatile sint16 Cal_LKA_TqLimit_A[25] _ADDR_R0(0x07B4)= { 
  0,  102,  204,  307,  409,  512,  614,  716,  819,  921,  
  1024,  1126,  1228,  1331,  1433,  1536,  1638,  1740,  1843,  2048,  
  3072,	4096,	5120,	6144,	8192} ;                       /* conv:Nm , val:0...3 , min-max:0~5 */
volatile sint16 Cal_LKA_TqLimit_T[175] _ADDR_R0(0x07E6) = { 
  0,  300,  420,  480,  520,  546,  645,  743,  843,  900,  996,  1091,  1187,  1283,  1379,  1475,  1581
,  1687,  1794,  2007,  2833,  3866,  4900,  5933,  8000,  
0,  300,  420,  480,  520,  546,  645,  743,  843
,  900,  996,  1091,  1187,  1283,  1379,  1475,  1581,  1687,  1794,  2007,  2833,  3866,  4900,  5933,  8000,  
0,  300,  420,  480,  520,  546,  645,  743,  843,  900,  996,  1091,  1187,  1283,  1379,  1475,  1581,  1687
,  1794,  2007,  2833,  3866,  4900,  5933,  8000,  
0,  300,  420,  480,  520,  546,  645,  743,  843,  900
,  996,  1091,  1187,  1283,  1379,  1475,  1581,  1687,  1794,  2007,  2833,  3866,  4900,  5933,  8000,  
0,  300,  420,  480,  520,  546,  645,  743,  843,  900,  996,  1091,  1187,  1283,  1379,  1475,  1581,  1687,  1794
,  2007,  2833,  3866,  4900,  5933,  8000,  
0,  300,  420,  480,  520,  546,  645,  743,  843,  900,  996
,  1091,  1187,  1283,  1379,  1475,  1581,  1687,  1794,  2007,  2833,  3866,  4900,  5933,  8000,  
0,  300,  420,  480,  520,  645,  743,  843,  900,  996,  1091,  1187,  1283,  1379,  1475,  1581,  1687,  1794,  2007
,  2833,  3866,  4900,  5933,  8000
 } ;/* conv:2^-7A , val:0...16.5 , min-max:0~100 */
volatile uint16 Cal_LKA_TqLimit_V[7] _ADDR_R0(0x0944) = { 960,  1280,  1600,  1920,  2560,  3200,  3840 } ;
#endif
/*Add new calvar*/
volatile Int16 Cal_LKA_PosLoopKp_A[7] _ADDR_R0(0x05F0) = { 16, 32, 48 , 64 ,80 , 96, 112 } ;/* conv:2^-4 deg, val:90 , min-max:0~800    anglediff*/
volatile Int16 Cal_LKA_PosLoopKp_V[8] _ADDR_R0(0x0600) = {320U, 960U, 1280U, 1600U, 1920U, 2560U, 3200U, 3840U } ;/* conv:2^-5 kph, val: , min-max:0~185 */
volatile Int16 Cal_LKA_PosLoopKp_T[56] _ADDR_R0(0x0610) = { 280, 279, 278, 277, 276, 275, 274, 
                                           290, 290, 290, 290, 290, 290, 290,
                                           291, 291, 291, 291, 291, 291, 291,
                                           292, 292, 292, 292, 292, 292, 292,
                                           293, 293, 293, 293, 293, 293, 293,
                                           294, 294, 294, 294, 294, 294, 294, 
                                           295, 295, 295, 295, 295, 295, 295,
                                           296, 296, 296, 296, 296, 296, 296} ;


volatile uint16 Cal_APA_VSINIT_RPA _ADDR_R0(0x05E0) = 96U;/* conv:2^-5 , val:3 , min-max:0~100 */

volatile sint16 Cal_APA_DANGINIT _ADDR_R0(0x0000) = 1440;/* conv:2^-4 , val:90 , min-max:0~800 */
volatile sint16 Cal_APA_DIFFINIT _ADDR_R0(0x0002) = 4000;
                                    /* conv:2^-4 , val:250 , min-max:100~1000 */
volatile sint16 Cal_APA_DIFFLIMIT _ADDR_R0(0x0004) = 4000;
                                    /* conv:2^-4 , val:250 , min-max:100~1000 */
volatile sint16 Cal_APA_ErrAdapt_Tab_A[8] _ADDR_R0(0x01a2) = { 0, 50, 100, 300, 500, 800,
  1200, 1600 } ;                  /* conv:2^0 , val:0...1600 , min-max:0~2000 */

volatile uint16 Cal_APA_ErrAdapt_Tab_I[24] _ADDR_R0(0x026c) = { 67U, 64U, 61U, 54U, 50U,
  46U, 44U, 43U, 67U, 64U, 61U, 54U, 50U, 46U, 44U, 43U, 67U, 64U, 61U, 54U, 50U,
  46U, 44U, 43U } ;                 /* conv:2^0 , val:0...100 , min-max:0~199 */

volatile uint16 Cal_APA_ErrAdapt_Tab_P[24] _ADDR_R0(0x029c) = { 2080U, 2080U, 2080U, 2080U,
		2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U,
		2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U } ;
                                    /* conv:2^0 , val:0...100 , min-max:0~199 */

volatile uint16 Cal_APA_ErrAdapt_Tab_V[3] _ADDR_R0(0x0088) = { 0U, 160U, 320U } ;
                                     /* conv:2^-5 , val:0...10 , min-max:0~20 */

volatile sint16 Cal_APA_HandOverTimeTab_X[9] _ADDR_R0(0x01c2) = { 2048, 3072, 4096, 5120,
  6144, 7168, 8192, 10240, 12288 } ;
                                  /* conv:2^-10Nm , val:2...12 , min-max:0~12 */

volatile uint16 Cal_APA_HandOverTimeTab_Y[9] _ADDR_R0(0x01d4) = { 800U, 600U, 400U, 300U,
  230U, 180U, 100U, 50U, 0U } ;/* conv:2^-10Nm , val:800...0 , min-max:0~1000 */

volatile sint16 Cal_APA_LOOP_INCREVLIMIT _ADDR_R0(0x0006) = 200;/* conv:2^0 , val:200 , min-max:0~1000 */
volatile sint16 Cal_APA_LOOP_MAX_ANGLE _ADDR_R0(0x0008) = 13056;/* conv:2^-4 , val:540 , min-max:0~800 */
volatile sint32 Cal_APA_LOOP_MAX_CURRENT _ADDR_R0(0x0064) = 11520;/* conv:2^-7 , val:90 , min-max:0~100 */
volatile sint32 Cal_APA_LOOP_MAX_REV _ADDR_R0(0x0068) = 213120;
                      /* conv:2^0 , val:213120 , min-max:0~320000,rpm:2^-3*16 */
volatile uint16 Cal_APA_LOOP_REVPI_PLUS _ADDR_R0(0x000a) = 4U;/* conv:2^0 , val:4 , min-max:0~10 */
volatile sint16 Cal_APA_LOOP_STEP_ANGLE _ADDR_R0(0x000c) = 8;/* conv:2^-4 , val:0.5 , min-max:0~5 */
volatile sint32 Cal_APA_LOOP_STOPREVDN _ADDR_R0(0x006c) = 800;
                                      /* conv:2^-3 , val:100 , min-max:0~1000 */
volatile sint32 Cal_APA_LOOP_STOPREVUP _ADDR_R0(0x0070) = 1600;
                                      /* conv:2^-3 , val:200 , min-max:0~1000 */
volatile uint16 Cal_APA_LOOP_STOPTMR _ADDR_R0(0x000e) = 100U;/* conv:2^0 , val:100 , min-max:0~2000 */
volatile sint16 Cal_APA_POSPID_KD _ADDR_R0(0x0010) = 0;/* conv:2^0 , val:3 , min-max:0~5 */
volatile sint16 Cal_APA_POSPID_KP _ADDR_R0(0x0012) = 280;/* conv:2^0 , val:280 , min-max:0~500 */
volatile sint16 Cal_APA_TRQINIT _ADDR_R0(0x0014) = 1024;/* conv:2^10 , val:1 , min-max:0~10 */
volatile sint16 Cal_APA_TRQLOOP _ADDR_R0(0x0016) = 5120;/* conv:2^10 , val:5 , min-max:0~10 */
volatile uint16 Cal_APA_VSINIT _ADDR_R0(0x0018) = 160U;/* conv:2^-5 , val:1 , min-max:0~100 */
volatile uint16 Cal_APA_VSLOOP _ADDR_R0(0x001a) = 160U;/* conv:2^-5 , val:10 , min-max:0~100 */
volatile uint16 Cal_LDW_AmpVsTab_X[6] _ADDR_R0(0x00a4) = { 1920U, 2560U, 2880U, 3200U,
  4800U, 5760U } ;            /* conv:2^-5km/h , val:60...180 , min-max:0~200 */

volatile sint16 Cal_LDW_AmpVsTab_Y[6] _ADDR_R0(0x00b0) = { 2000, 2000, 2000, 2200, 2200,
  2200 } ;                      /* conv:2^-7Nm , val:23...18.5 , min-max:0~80 */

volatile uint16 Cal_LDW_FrzVsTab_X[6] _ADDR_R0(0x00bc) = { 1920U, 2560U, 3200U, 3840U,
  4800U, 5760U } ;            /* conv:2^-5km/h , val:60...180 , min-max:0~200 */

volatile uint16 Cal_LDW_FrzVsTab_Y[6] _ADDR_R0(0x00c8) = { 16U, 16U, 16U, 16U, 16U, 16U } ;
                                  /* conv:2^0Hz , val:20...20 , min-max:10~30 */

volatile uint16 Cal_LDW_TEMPRECOVER_TMR _ADDR_R0(0x001c) = 300U;/* conv:2^0 , val:300 , min-max:0~1000 */
volatile sint16 Cal_LDW_VIBAMP_LIMIT _ADDR_R0(0x001e) = 384;/* conv:2^-7 , val:3 , min-max:1~5 */
volatile sint16 Cal_LDW_VIBAMP_RATE _ADDR_R0(0x0020) = 64;
                                    /* conv:2^-7Nm , val:0.39 , min-max:0~0.5 */
volatile uint16 Cal_LDW_VIBFREZ_DN _ADDR_R0(0x0022) = 10U;/* conv:2^0 , val:10 , min-max:10~20 */
volatile uint16 Cal_LDW_VIBFREZ_UP _ADDR_R0(0x0024) = 20U;/* conv:2^0 , val:20 , min-max:10~30 */
volatile uint16 Cal_LDW_VSEND _ADDR_R0(0x0026) = 5920U;/* conv:2^-5 , val:185 , min-max:0~200 */
volatile uint16 Cal_LDW_VSSTART _ADDR_R0(0x0028) = 0U;/* conv:2^-5 , val:50 , min-max:0~200 */
volatile sint16 Cal_LDW_VibAmp_Gain _ADDR_R0(0x002a) = 3840;/* conv:2^-10, val:8 , min-max:0~30 */
volatile sint16 Cal_LKA_ADVCMD_RATE _ADDR_R0(0x002c) = 2;
                                  /* conv:2^-10Nm , val:0.002 , min-max:0~0.5 */
volatile sint16 Cal_LKA_AgCtrlDnOfNoTrqLimit _ADDR_R0(0x002e) = 3776;
                                     /* conv:2^-7 , val:15.625 , min-max:0~50 */
volatile sint16 Cal_LKA_AgCtrlTqDnLimit_X[10] _ADDR_R0(0x021c) = { 0, 256, 512, 768, 1024,
  1280, 1536, 1792, 2048, 2304 } ;   /* conv:2^-7 , val:15.625 , min-max:0~50 */

volatile sint16 Cal_LKA_AgCtrlTqDnLimit_Y[10] _ADDR_R0(0x0230) = { 0, 2000, 4000, 6000,
  8000, 10000, 12000, 12800, 12800, 12800 } ;
                                     /* conv:2^-7 , val:15.625 , min-max:0~50 */

volatile sint16 Cal_LKA_ARFactor_X[3] _ADDR_R0(0x05E2) = {0,320,640} ;   
                                      /* conv:2^-5KM/ , val:15.625 , min-max:0~50 */

volatile sint16 Cal_LKA_ARFactor_Y[3] _ADDR_R0(0x05E8) = {64,0,0} ;
                                     /* conv:2^-7 , val:1 , min-max:0~1 */

volatile sint16 Cal_LKA_AgCtrlTqUpLimit_X[10] _ADDR_R0(0x0244) = { 0, 256, 512, 768, 1024,
  1280, 1536, 1792, 2048, 2304 } ;   /* conv:2^-7 , val:15.625 , min-max:0~50 */

volatile sint16 Cal_LKA_AgCtrlTqUpLimit_Y[10] _ADDR_R0(0x0258) = { 0, 2000, 4000, 6000,
  8000, 10000, 12000, 12800, 12800, 12800 } ;
                                     /* conv:2^-7 , val:15.625 , min-max:0~50 */

volatile sint16 Cal_LKA_AgCtrlUpOfNoTrqLimit _ADDR_R0(0x0030) = 3776;
                                     /* conv:2^-7 , val:15.625 , min-max:0~50 */
volatile sint16 Cal_LKA_AimCurrentTab_A[7] _ADDR_R0(0x00ec) = { 0,  512,  1024,  1536,  2048,  2560,  3072 } ;
                       /* conv:Nm , val:0...3 , min-max:0~5 */

// volatile sint16 Cal_LKA_AimCurrentTab_T[49] _ADDR_R0(0x039c) = { 0,  631,  50,  60,  100,  600,  3600, 
//                                                 0,  631,  1011,  1263,  1634,  2057,  2530, 
//                                                 0,  681,  1080,  1200,  2200,  3175,  4150, 
//                                                 0,  574,  900,  1100,  1600,  2260,  3600, 
//                                                 0,  517,  827,  900,  1300,  2000,  2700, 
//                                                 0,  400,  600,  800,  1200,  1500,  2200, 
//                                                 0,  350,  550,  780,  1050,  1300,  1800 } ;
                                 /* conv:2^-7A , val:0...16.5 , min-max:0~100 */
                                 //mod by liuyang for EMA debug
volatile sint16 Cal_LKA_AimCurrentTab_T[49] _ADDR_R0(0x039c) = { 0,  631,  1011,  1263,  1634,  2057,  2530, 
                    0,  631,  1011,  1263,  1634,  2057,  2530, 
                    0,  681,  1080,  1200,  2200,  3175,  4150, 
                    0,  574,  900,  1100,  1600,  2260,  3600, 
                    0,  517,  827,  900,  1300,  2000,  2700, 
                    0,  400,  600,  800,  1200,  1500,  2200, 
                    0,  350,  550,  780,  1050,  1300,  1800 } ;

volatile uint16 Cal_LKA_AimCurrentTab_V[7] _ADDR_R0(0x00fa) = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;      /* conv:2^-5km/h , val:0...130 , min-max:0~200 */

volatile uint16 Cal_LKA_CMDSMP_TMR _ADDR_R0(0x0032) = 20U;/* conv:2^0 , val:20 , min-max:0~1000 */
volatile sint16 Cal_LKA_CmdCoefTab_A[7] _ADDR_R0(0x0108) = { 0, 512, 819, 1024, 1536, 2048,
  3072 } ;                             /* conv:Nm , val:0...3 , min-max:0~5 */

volatile sint16 Cal_LKA_CmdCoefTab_T[49] _ADDR_R0(0x03fe) = { 0, 20, 45, 70, 110, 130, 140,
  0, 20, 45, 70, 110, 130, 140, 0, 20, 45, 70, 110, 130, 140, 0, 40, 80, 110,
  160, 180, 192, 0, 40, 80, 110, 160, 180, 192, 0, 40, 80, 110, 160, 180, 192, 0,
  42, 83, 114, 166, 187, 200 } ;      /* conv:2^-4, val:0...12 , min-max:0~20 */

volatile uint16 Cal_LKA_CmdCoefTab_V[7] _ADDR_R0(0x0116) = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;    /* conv:km/h 2^-5 , val:30...120 , min-max:0~200 */

volatile sint16 Cal_LKA_DIFFLIMIT _ADDR_R0(0x0034) = 4000;
                                    /* conv:2^-4 , val:250 , min-max:100~1000 */
volatile sint16 Cal_LKA_DampAngTab_A[7] _ADDR_R0(0x0124) = { 0, 160, 320, 480, 800, 1280,
  3200 } ;                          /* conv:2^-4, val:0...200 , min-max:0~800 */

volatile sint16 Cal_LKA_DampAngTab_T[49] _ADDR_R0(0x0460) = { 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128 } ;/* conv:2^-7, val:1...1 , min-max:0~1 */

volatile uint16 Cal_LKA_DampAngTab_V[7] _ADDR_R0(0x0132) = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;    /* conv:2^-5 km/h , val:30...120 , min-max:0~200 */

volatile sint16 Cal_LKA_DampCoefTab_X[7] _ADDR_R0(0x0140) = { 0, 512, 1024, 1536, 2048,
  2560, 3072 } ;                       /* conv:Nm , val:0...3 , min-max:0~5 */

volatile sint16 Cal_LKA_DampCoefTab_Y[7] _ADDR_R0(0x014e) = { 0, 350, 575, 715, 800, 900,
  1000 } ;                          /* conv:2^-10, val:0.58...0 , min-max:0~2 */

volatile sint16 Cal_LKA_DampCompTab_A[7] _ADDR_R0(0x015c) = { 0, 160, 320, 480, 800, 1280,
  3200 } ;                          /* conv:2^-4, val:0...200 , min-max:0~800 */

volatile sint16 Cal_LKA_DampCompTab_T[49] _ADDR_R0(0x04c2) = { 0, 500, 1000, 1500, 1800,
  2100, 2400, 0, 500, 1000, 1500, 1800, 2100, 2400, 0, 500, 1000, 1500, 1800,
  2100, 2400, 0, 500, 1000, 1500, 1800, 2100, 2400, 0, 500, 1000, 1500, 1800,
  2100, 2400, 0, 500, 1000, 1500, 1800, 2100, 2400, 0, 500, 1000, 1500, 1800,
  2100, 2400 } ;                      /* conv:2^-7, val:0...45 , min-max:0~20 */

volatile uint16 Cal_LKA_DampCompTab_V[7] _ADDR_R0(0x016a) = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;    /* conv:2^-5 km/h , val:30...120 , min-max:0~200 */

volatile sint16 Cal_LKA_ErrAdapt_Tab_A[8] _ADDR_R0(0x01b2) = { 0, 50, 100, 300, 500, 800,
  1200, 1600 } ;                  /* conv:2^0 , val:0...1600 , min-max:0~2000 */

volatile uint16 Cal_LKA_ErrAdapt_Tab_I[24] _ADDR_R0(0x02cc) = { 67U, 64U, 61U, 54U, 50U,
  46U, 44U, 43U, 67U, 64U, 61U, 54U, 50U, 46U, 44U, 43U, 67U, 64U, 61U, 54U, 50U,
  46U, 44U, 43U } ;                 /* conv:2^0 , val:0...100 , min-max:0~199 */

volatile uint16 Cal_LKA_ErrAdapt_Tab_P[24] _ADDR_R0(0x02fc) = { 2080U, 2080U, 2080U, 2080U,
		2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U,
		2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U, 2080U } ;
                                    /* conv:2^0 , val:0...100 , min-max:0~199 */

volatile uint16 Cal_LKA_ErrAdapt_Tab_V[3] _ADDR_R0(0x008e) = { 0U, 1600U, 3200U } ;
                                   /* conv:2^-5 , val:0...100 , min-max:0~200 */

volatile sint16 Cal_LKA_FilterCoef _ADDR_R0(0x0036) = 1014;/* conv:2^-10 , val:0.99 , min-max:0~1 */
volatile sint16 Cal_LKA_GRADCMD_RANGE _ADDR_R0(0x0038) = 5120;/* conv:2^-10Nm , val:5 , min-max:0~10 */
volatile sint16 Cal_LKA_GRIDLIMIT _ADDR_R0(0x003a) = 800;/* conv:2^-4 , val:50 , min-max:10~100 */
volatile sint16 Cal_LKA_GradCoefTab_A[4] _ADDR_R0(0x0094) = { 3072, 4096, 4608, 5120 } ;/* conv:Nm/s , val:3...5 , min-max:0~5 */

volatile sint16 Cal_LKA_GradCoefTab_T[28] _ADDR_R0(0x032c) = { 128, 128, 128, 154, 128, 128,
  128, 154, 128, 128, 128, 154, 128, 128, 128, 154, 128, 128, 128, 154, 128, 128,
  128, 154, 128, 128, 128, 154 } ;    /* conv:2^-7, val:1...1.2 , min-max:0~2 */

volatile uint16 Cal_LKA_GradCoefTab_V[7] _ADDR_R0(0x0178) = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;      /* conv:2^-5km/h , val:0...130 , min-max:0~200 */

volatile uint16 Cal_LKA_HANDOFF_TMR _ADDR_R0(0x003c) = 3000U;
                                      /* conv:2^0 , val:3000 , min-max:0~1000 */
volatile sint16 Cal_LKA_HANDOFF_TRQ _ADDR_R0(0x003e) = 256;
                                     /* conv:2^-10 , val:0.25 , min-max:0~0.5 */
volatile sint16 Cal_LKA_HandOverMaxTrqTab_T[9] _ADDR_R0(0x01e6) = { 3072, 3072, 3072, 3072,
  3072, 3072, 3072, 3072, 3072 } ;     /* conv:Nm , val:0...3 , min-max:0~5 */

volatile uint16 Cal_LKA_HandOverMaxTrqTab_V[9] _ADDR_R0(0x01f8) = { 0U, 1600U, 1760U, 1920U,
  2176U, 2240U, 2400U, 3200U, 3840U } ;
                               /* conv:2^-5km/h , val:0...130 , min-max:0~200 */

volatile sint16 Cal_LKA_HandOverTimeTab_A[9] _ADDR_R0(0x020a) = { 2560, 3072, 4096, 5120,
  6144, 7168, 8192, 10240, 12288 } ;
                                  /* conv:2^-10Nm , val:2...12 , min-max:0~12 */

volatile uint16 Cal_LKA_HandOverTimeTab_T[63] _ADDR_R0(0x0524) = {
  5000U, 3000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 
  5000U, 3000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 
  5000U, 3000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U,  
  5000U, 3000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 
  5000U, 3000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U,  
  5000U, 3000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 
  5000U, 3000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U, 2000U} ;
                               /* conv:2^-10Nm , val:800...0 , min-max:0~1000 */

volatile uint16 Cal_LKA_HandOverTimeTab_V[7] _ADDR_R0(0x0186) = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;      /* conv:2^-5km/h , val:0...130 , min-max:0~200 */

volatile uint16 Cal_LKA_HandsOffStepTab_S[28] _ADDR_R0(0x0364) = { 1U, 7U, 10U, 15U, 
                                                        1U, 7U, 10U, 15U, 
                                                        1U, 7U, 10U, 15U, 
                                                        1U, 7U, 10U, 15U,  
                                                        1U, 7U, 10U, 15U, 
                                                        1U, 7U, 10U, 15U, 
                                                        1U, 7U, 10U, 15U} ;                       /* conv:2^0ms , val:0...3 , min-max:0~5 */

volatile sint16 Cal_LKA_HandsOffStepTab_T[4] _ADDR_R0(0x009c) = { 0, 512, 1024, 3072 } ;
                                    /* conv:2^-10Nm, val:0...3 , min-max:0~10 */

volatile uint16 Cal_LKA_HandsOffStepTab_V[7] _ADDR_R0(0x0194) = { 960U, 1280U, 1600U, 1920U,
  2560U, 3200U, 3840U } ;      /* conv:2^-5km/h , val:0...130 , min-max:0~200 */

volatile sint16 Cal_LKA_LOOP_INCREVLIMIT _ADDR_R0(0x0040) = 200;/* conv:2^0 , val:200 , min-max:0~1000 */
volatile sint16 Cal_LKA_LOOP_MAX_ANGLE _ADDR_R0(0x0042) = 8640;/* conv:2^-4 , val:540 , min-max:0~800 */
volatile sint32 Cal_LKA_LOOP_MAX_CURRENT _ADDR_R0(0x0074) = 12800;/* conv:2^-7 , val:90 , min-max:0~100 */
volatile sint32 Cal_LKA_LOOP_MAX_REV _ADDR_R0(0x0078) = 100000;
                                  /* conv:2^0 , val:213120 , min-max:0~320000 */
volatile uint16 Cal_LKA_LOOP_REVPI_PLUS _ADDR_R0(0x0044) = 4U;/* conv:2^0 , val:4 , min-max:0~10 */
volatile sint16 Cal_LKA_LOOP_STEP_ANGLE _ADDR_R0(0x0046) = 8;/* conv:2^-4 , val:0.5 , min-max:0~5 */
volatile sint32 Cal_LKA_LOOP_STOPREVDN _ADDR_R0(0x007c) = 800;
                                      /* conv:2^-3 , val:100 , min-max:0~1000 */
volatile sint32 Cal_LKA_LOOP_STOPREVUP _ADDR_R0(0x0080) = 1600;
                                      /* conv:2^-3 , val:200 , min-max:0~1000 */
volatile uint16 Cal_LKA_LOOP_STOPTMR _ADDR_R0(0x0048) = 100U;/* conv:2^0 , val:100 , min-max:0~2000 */
volatile sint16 Cal_LKA_POSPID_KD _ADDR_R0(0x004a) = 0;/* conv:2^0 , val:3 , min-max:0~5 */
volatile sint16 Cal_LKA_POSPID_KP _ADDR_R0(0x004c) = 280;/* conv:2^0 , val:280 , min-max:0~500 */
volatile sint16 Cal_LKA_REQLIMIT _ADDR_R0(0x004e) = 13056;
                                     /* conv:2^-4 , val:600 , min-max:10~1000 */
volatile uint32 Cal_LKA_TEMPO_OVERTIME_TMR _ADDR_R0(0x0084) = 600000U;/* conv:2^0 , val:10 , min-max:0~2000 */
volatile uint16 Cal_LKA_TEMPRECOVER_TMR _ADDR_R0(0x0050) = 300U;/* conv:2^0 , val:300 , min-max:0~1000 */
volatile sint16 Cal_LKA_TRQADVCOMP_MAX _ADDR_R0(0x0052) = 0;
                                     /* conv:2^-7 , val:15.625 , min-max:0~50 */
volatile sint16 Cal_LKA_TRQCMD_RANGE _ADDR_R0(0x0054) = 3072;/* conv:2^-10Nm , val:3 , min-max:0~5 */
volatile sint16 Cal_LKA_TRQCMD_RATE _ADDR_R0(0x0056) = 2048;
                                /* conv:2^-10Nm/ms , val:0.05 , min-max:0~0.5 */
volatile sint16 Cal_LKA_TRQCMD_RATE_FRAME _ADDR_R0(0x0058) = 5120;
                                    /* conv:2^-10Nm , val:0.5 , min-max:0~0.5 */
volatile sint16 Cal_LKA_TRQDMPCOMP_MAX _ADDR_R0(0x005a) = 0;/* conv:2^7 , val:30 , min-max:0~50 */
volatile sint16 Cal_LKA_TRQOUT_RANGE _ADDR_R0(0x005c) = 7680;
                                      /* conv:2^-7Nm , val:60 , min-max:0~100 */
volatile sint16 Cal_LKA_TRQOUT_RATE _ADDR_R0(0x005e) = 1280;/* conv:2^-7Nm , val:0.5 , min-max:0~5 */
volatile uint16 Cal_LKA_VSEND _ADDR_R0(0x0060) = 5920U;/* conv:2^-5 , val:185 , min-max:0~200 */
volatile uint16 Cal_LKA_VSSTART _ADDR_R0(0x0062) = 0U;/* conv:2^-5 , val:50 , min-max:0~200 */
volatile uint16 Cal_LKA_VsCoefTab_X[6] _ADDR_R0(0x00d4) = { 0U, 1760U, 1920U, 5600U, 5760U,
  6400U } ;                    /* conv:2^-5km/h , val:0...180 , min-max:0~200 */

volatile uint16 Cal_LKA_VsCoefTab_Y[6] _ADDR_R0(0x00e0) = { 1024U, 1024U, 1024U, 1024U, 0U, 0U } ;
                                      /* conv:2^-10 , val:0...1 , min-max:0~2 */
volatile Float64 Cal_SF_FREZLMT _ADDR_R0(0x05A4) = 200.0;/* conv:2^0 , val:20 , min-max:0~100 */
volatile Float64 Cal_SF_FREZSTEP _ADDR_R0(0x05A8) = 0.5;/* conv:2^0 , val:20 , min-max:0~100 */
volatile Int16 Cal_SF_LEVEL_1 _ADDR_R0(0x05AC) = 1280;/* conv:2^-7 , val:10 , min-max:0~50 */
volatile Int16 Cal_SF_LEVEL_2 _ADDR_R0(0x05AE) = 2560;/* conv:2^-7 , val:10 , min-max:0~50 */
volatile Int16 Cal_SF_LEVEL_3 _ADDR_R0(0x05B0) = 3840;/* conv:2^-7 , val:10 , min-max:0~50 */
volatile uint8 Cal_TSC_Enable = 0;
volatile Int16 Cal_TSC_ANGLMT _ADDR_R0(0x05B2) = 50;/* conv:2^0 , val:220 , min-max:0~100 */
volatile Int16 Cal_TSC_ANGSPDLMT _ADDR_R0(0x05B4) = 320;/* conv:2^0 , val:220 , min-max:0~300 */
volatile UInt16 Cal_TSC_CMD_Tab_X[5] _ADDR_R0(0x05B6) = { 0U, 5U, 10U, 15U, 20U } ;/* conv:2^0 , val:220 , min-max:0~5000 */

volatile Int16 Cal_TSC_CMD_Tab_Y[5] _ADDR_R0(0x05C0) = { 0, 32, 64, 96, 128 } ;/* conv:2^0 , val:220 , min-max:0~5000 */

volatile UInt16 Cal_TSC_CNT _ADDR_R0(0x05CA) = 5U;/* conv:2^0 , val:220 , min-max:0~5000 */
volatile UInt16 Cal_TSC_VEHSPDCNT _ADDR_R0(0x05CC) = 5U;/* conv:2^0 , val:220 , min-max:0~5000 */
volatile UInt16 Cal_TSC_VEHSPD_DIFF _ADDR_R0(0x05CE) = 20U;/* conv:2^0 , val:220 , min-max:0~5000 */
volatile Int16 Cal_TSC_VIBAMP_RATE _ADDR_R0(0x05D0) = 32;
                                    /* conv:2^-7Nm , val:0.39 , min-max:0~0.5 */
volatile UInt16 Cal_TSC_WHEELSPD_DIFF _ADDR_R0(0x05D2) = 20U;/* conv:2^0 , val:220 , min-max:0~5000 */

volatile Int16 Cal_LKA_HandsOffStep_Spd[3] = { 100, 400, 800 } ;//2^-5KM/H
volatile Int16 Cal_LKA_HandsOffStep_Trq[8] = { 0,  31,  49,  246,  430,  717,  1029,  1228 } ;
/* conv:2^-10 , val:0...1600 , min-max:0~2000 */
volatile Int16 Cal_LKA_HandsOffStep_Out[24] = { 2,  2,  2,  2,  -1,  -14,  -15,  -18,  2,  2,  2,  2,  -1,  -14,  -15,  -18,  2
,  2,  2,  2,  -1,  -14,  -15,  -18  } ;
/* conv:2^0 , val:0...100 , min-max:0~199 */

volatile float64 Cal_HANDOFF_TrqFir_Frez = 5.0;/* conv:2^0Hz , val:5 , min-max:0~100 */

volatile Int16 Cal_Support_EndVar _ADDR_R0(0x0952) = 0x00AA;/*记录当前新变量可用的地址，添加变量后务必更新此地址*/
volatile Int16 Cal_Support_EndBoundary _ADDR_R0(0x1FFE) = 0x00BB;/*鍩烘湰鍔╁姏鍒嗛厤鍦板潃鐨勬渶澶ч暱搴� 8k - 2*/




#undef _ADDR_R0(addr)
#undef _Support_Offset

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
