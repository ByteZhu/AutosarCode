/*
 * File: SimDiagMacroCAN.h
 *
 * Code generated for Simulink model 'DTC_CANCheck'.
 *
 * Model version                  : 1.1204
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 21 17:56:45 2022
 */

#ifndef RTW_HEADER_SimDiagMacroCAN_h_
#define RTW_HEADER_SimDiagMacroCAN_h_
#include "rtwtypes.h"

/* Exported data define */
/* Definition for custom storage class: Define */
#define DIAGDIS_CANABS                 0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CANAPA                 0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CANBCM2                 0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CANBUSOFF              0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CANEMS                 0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CANIPB                 0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CANMPC                 0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CANSCU                 0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define MACRO_CAN_BUSOFFTIME           9U                        /* conv:2^0 , val:9 , min-max:0~1000 */
#define MACRO_CAN_CHECKTIME            0U//50U                  /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_CAN_INITDIAGLOST_TIME    150U                      /* conv:2^0 , val:150 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_ABSVs        99U                      /* conv:2^0 , val:249 , min-max:0~5000 */
#define MACRO_CAN_LOSTTIME_ABSWs       199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_APA         199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_BCM2        4949U                      /* conv:2^0 , val:499 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_IPB2        199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_IPB5        99U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_IPB6        199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_ADS2        199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_ADS1        199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_SCU         499U                      /* conv:2^0 , val:999 , min-max:0~2000 */
#define MACRO_CAN_LOSTTIME_CCU3        499U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_CCU1         99U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_CCU2        199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_VCU3        999U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_BCM3        999U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_IPB3         99U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_IPB4         99U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_LOSTTIME_IPB7        199U                      /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_CAN_POWERNMWIN           128                       /* conv:2^-7V , val:1 , min-max:0~3 */
#define MACRO_CAN_POWEROVERWIN         320                       /* conv:2^-7V , val:2.5 , min-max:0~3 */
#define MACRO_CAN_RECORNMTIMEOUT       25U                       /* conv:2^0 , val:25 , min-max:0~1000 */
#define MACRO_CAN_RECORTIMEOUT         9U                        /* conv:2^0 , val:9 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_ABSVs       39U                       /* conv:2^0 , val:39 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_IPB4        39U                       /* conv:2^0 , val:39 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_IPB7        19U                       /* conv:2^0 , val:39 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_ABSWs       39U                       /* conv:2^0 , val:39 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_APA         19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_BCM2         199U                      /* conv:2^0 , val:199 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_IPB2        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_IPB5        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_IPB6        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_ADS2        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_ADS1        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_SCU         399U                      /* conv:2^0 , val:399 , min-max:0~2000 */
#define MACRO_CAN_RECVTIME_CCU3        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_CCU1        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_CCU2        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */
#define MACRO_CAN_RECVTIME_VCU3        19U                       /* conv:2^0 , val:19 , min-max:0~1000 */

#define DIAG_VOL_LOW 832 //6.5V  
#define DIAG_VOL_HIGH 2304 //18V  

#endif                                 /* RTW_HEADER_SimDiagMacroCAN_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
