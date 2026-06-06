/*
 * File: SimDiagMacro.h
 *
 * Code generated for Simulink model 'AssistControl'.
 *
 * Model version                  : 1.1306
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:05:55 2022
 */

#ifndef RTW_HEADER_SimDiagMacro_h_
#define RTW_HEADER_SimDiagMacro_h_
#include "rtwtypes.h"

/* Exported data define */
/* Definition for custom storage class: Define */
#define CACLAIM_MOTORANG_POWERST       0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_ANGLEROTORCHECK        0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_ANGLEVALCHECK          0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CURRENTMIDREG          0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_CURRENTSAMPLEREG       0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MCUCORE                0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MCUEPSCONTROL          0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MCUMOTORCONTROL        0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MCUVICECOMM            0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MOTOROUTPUTCURRENTREG  0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MOTOROVERCURRENTREG    0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MOTORPREDRIVERREG      0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_MOTORSHORTOPENINIT     0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_POWERHOLD              0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_POWERIGCAN             0U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define DIAGDIS_POWERLEVEL             0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_POWERVBAT              1U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define DIAGDIS_ROTORPOWERREG          1U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_ROTORSIGNALREG         0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_TEMPLEVEL              0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_TEMPVOL                0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_TORQUEPOWERREG         0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DIAGDIS_TORQUESIGNALREG        0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define DiagCANMask                    7680U                     /* conv:2^0 , val:7680 , min-max:~ */
#define DiagEepromMask                 230U                      /* conv:2^0 , val:230 , min-max:~ */
#define DiagMCUMask                    375U                      /* conv:2^0 , val:375 , min-max:~ */
#define DiagSoftMask                   1023U                     /* conv:2^0 , val:1023 , min-max:~ */
#define EPS_DTC_NUM_MAX                104                        /* conv:2^0 , val:80 , min-max:0~128 */
#ifndef FALSE
#define FALSE                          0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#endif
#define MACRO_ADVCIRPLUS               2                         /* conv:2^0 , val:2 , min-max:1~2 */
#define MACRO_ANGEL_OFFSET_COMP_SELECT 1U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define MACRO_ANGLEDECODE_BASICM1      400                       /* conv:2^0 , val:400 , min-max:0~4000 */
#define MACRO_ANGLEDECODE_BASICM10     4000                      /* conv:2^0 , val:4000 , min-max:3000~4000 */
#define MACRO_ANGLEDECODE_BASICM3      1200                      /* conv:2^0 , val:1200 , min-max:0~4000 */
#define MACRO_ANGLEDECODE_BASICM5      2000                      /* conv:2^0 , val:2000 , min-max:0~4000 */
#define MACRO_ANGLEDECODE_BASICM7      2800                      /* conv:2^0 , val:2800 , min-max:0~4000 */
#define MACRO_ANGLEDECODE_BASICM9      3600                      /* conv:2^0 , val:3600 , min-max:0~4000 */
#define MACRO_ANGLEDECODE_DUTYRANGE    7500U                     /* conv:2^0 , val:7500 , min-max:0~10000 */
#define MACRO_ANGLEDECODE_EXTENTP      400                       /* conv:2^0 , val:400 , min-max:0~400 */
#define MACRO_ANGLEDECODE_EXTENTS      2960                      /* conv:2^0 , val:2960 , min-max:0~2960 */
#define MACRO_ANGLEDECODE_HALF         7400                      /* conv:2^0 , val:7400 , min-max:0~14800 */
#define MACRO_ANGLEDECODE_LIMIT        29600                     /* conv:2^0 , val:29600 , min-max:14800~32000 */
#define MACRO_ANGLEDECODE_MAX          14800                     /* conv:2^0 , val:14800 , min-max:0~14800 */
#define MACRO_ANGLEDECODE_MIXTIMER     200                       /* conv:2^0 , val:200 , min-max:0~500 */
#define MACRO_ANGLEDECODE_ZERORIFT     1250U                     /* conv:2^0 , val:1250 , min-max:0~10000 */
#define MACRO_ANGLEDECODE_PWRCNT       10                        /* conv:2^0 , val:10 , min-max:0~400 */
#define MACRO_ANGLE_CHECKDIFF          400                       /* conv:2^-4deg , val:15 , min-max:0~30 */
#define MACRO_ANGLE_CHECKRECNUM        8U                        /* conv:2^0 , val:8 , min-max:0~100 */
#define MACRO_ANGLE_CHECKTIME          10U                       /* conv:2^0 , val:10 , min-max:0~100 */
#define MACRO_ANGLE_DEADREV            32                        /* conv:2^-4deg/s , val:2 , min-max:0~5 */
#define MACRO_ANGLE_DEFAULT_DELAYTIME  200U                      /* conv:2^0 , val:400 , min-max:0~1000 */
#define MACRO_ANGLE_DELAYTIME          200U                      /* conv:2^0 , val:200 , min-max:0~1000 */
#define MACRO_ANGLE_DIFFTIME           50U                       /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_ANGLE_DUTYMAX            9375U                     /* conv:2^0 , val:9375 , min-max:9000~10000 */
#define MACRO_ANGLE_DUTYMIN            625U                      /* conv:2^0 , val:625 , min-max:0~1000 */
#define MACRO_ANGLE_FRZPMAX            1250U                     /* conv:2^0Hz , val:1250 , min-max:1000~1500 */
#define MACRO_ANGLE_FRZPMIN            750U                      /* conv:2^0Hz , val:750 , min-max:500~1000 */
#define MACRO_ANGLE_FRZSMAX            250U                      /* conv:2^0Hz , val:250 , min-max:200~300 */
#define MACRO_ANGLE_FRZSMIN            150U                      /* conv:2^0Hz , val:150 , min-max:100~200 */
#define MACRO_ANGLE_INIT_VOL           896                       /* conv:2^-7V , val:7 , min-max:6~9 */
#define MACRO_ANGLE_LIMITPREV          1440                      /* conv:2^-4deg/s , val:90 , min-max:30~180 */
#define MACRO_ANGLE_MAXP               640                       /* conv:2^-4deg , val:40 , min-max:0~50 */
#define MACRO_ANGLE_MAXP_2             320                       /* conv:2^-4deg , val:20 , min-max:0~25 */
#define MACRO_ANGLE_UNREALMAX          11520                     /* conv:2^-4deg , val:500 , min-max:0~800 */
#define MACRO_ASC_VSCONST_1            32U                       /* conv:2^-5km/h , val:7 , min-max:0~10 */
#define MACRO_ASC_VSCONST_3            96U                       /* conv:2^-5km/h , val:7 , min-max:0~10 */
#define MACRO_ASC_VSCONST_7            224U                      /* conv:2^-5km/h , val:7 , min-max:0~10 */
#define MACRO_AV_AD2VOL                10U                       /* conv:2^-13V , val:0.0012207 , min-max:0~0.01 */
#define MACRO_AV_AD2VOL_1              10U                       /* conv:2^-13V , val:0.0012207 , min-max:0~0.01 */
#define MACRO_AV_AD2VOL_2              10U                       /* conv:2^-13V , val:0.0012207 , min-max:0~0.01 */
#define MACRO_AV_IGNITION_OFFSET       64                        /* conv:2^-7V , val:0.5 , min-max:0~1 */
#define MACRO_AV_IGNITION_SCALE        420U                      /* conv:2^-16 , val:0.0099334716796875 , min-max:0~0.02 */
#define MACRO_AV_POWER_OFFSET          0                        /* conv:2^-7V , val:0.7 , min-max:0~1 */
#define MACRO_AV_POWER_SCALE           420U                      /* conv:2^-16V , val:0.012207 , min-max:0~0.02 */
#define MACRO_AV_RSVPOWER_SCALE        420U                      /* conv:2^-16V , val:0.0064087 , min-max:0~0.01 */
#define MACRO_AV_TRQPOWER_SCALE        420U                      /* conv:2^-16V , val:0.0064087 , min-max:0~0.01 */
#define MACRO_BEHAVEMODULE_SELECT      0U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define MACRO_CURRENT_CHECKTIME        50U                       /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_CURRENT_MIDMAX           333U                      /* conv:2^-7V , val:2.6 , min-max:0~5 */
#define MACRO_CURRENT_MIDMIN           307U                      /* conv:2^-7V , val:2.4 , min-max:0~5 */
#define MACRO_CURRENT_SUMMAX           3840                      /* conv:2^-7A , val:30 , min-max:0~100 */
#define MACRO_FAIL_HIGH1RATE           33                        /* conv:2^-15 , val:0.001 , min-max:0~1 */
#define MACRO_FAIL_HIGH3RATE           32768                     /* conv:2^-15 , val:1 , min-max:0~1 */
#define MACRO_FAIL_LIMITPER            19661                     /* conv:2^-15 , val:0.6 , min-max:0~1 */
#define MACRO_FAIL_LIMITRATE           33                        /* conv:2^-15 , val:0.001 , min-max:0~1 */
#define MACRO_FAIL_LOWRATE             33                        /* conv:2^-15 , val:0.001 , min-max:0~1 */
#define MACRO_FAIL_VERATE              33                        /* conv:2^-15 , val:0.001 , min-max:0~1 */
#define MACRO_FAIL_VERATEMAX           819                       /* conv:2^-15 , val:0.025 , min-max:0~1 */
#define MACRO_FRICTION_COMP_SELECT     0U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define MACRO_LOADCLOSELOOP_SELECT    1// 0U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define MACRO_LOW_REV_LIMIT_H          1600                      /* conv:2^-3rpm , val:3000 , min-max:0~4000 */
#define MACRO_LOW_REV_LIMIT_L          800                       /* conv:2^-3rpm , val:3000 , min-max:0~4000 */
#define MACRO_MAC_IDFW_CURRENT_BK_MAX  0                         /* conv:2^-7A , val:0 , min-max:0~20 */
#define MACRO_MAC_IDFW_CURRENT_LIMIT   fsMotorIdfwCurrentMaxHalf                    /* conv:2^-7A , val:-80 , min-max:-120~0 */
#define MACRO_MAC_VSLEVEL1DN           96U                       /* conv:2^-5km/h , val:20 , min-max:0~100 */
#define MACRO_MAC_VSLEVEL1UP           160U                      /* conv:2^-5km/h , val:22 , min-max:0~100 */
#define MACRO_MAC_VSLEVEL2DN           640U                      /* conv:2^-5km/h , val:50 , min-max:0~100 */
#define MACRO_MAC_VSLEVEL2UP           704U                      /* conv:2^-5km/h , val:52 , min-max:0~100 */
#define MACRO_MAC_VSLEVEL3DN           1600U                     /* conv:2^-5km/h , val:22 , min-max:0~100 */
#define MACRO_MAC_VSLEVEL3UP           1664U                     /* conv:2^-5km/h , val:22 , min-max:0~100 */
#define MACRO_MAX_FOC_CURRENTQ         fsMotorMaxFocCurrentQ                     /* conv:2^-7A , val:80 , min-max:80~120 */
#define MACRO_MAX_FOC_CURRENTQ_HALF    fsMotorMaxFocCurrentQHalf                     /* conv:2^-7A , val:80 , min-max:80~120 */
#define MACRO_MAX_SEATING_RATIO        109U                      /* conv:2^-7 , val:0.85 , min-max:0~1 */
#define MACRO_MAX_SEATING_TIMES        600U                      /* conv:2^0 , val:600 , min-max:0~1000 */
#define MACRO_MBC_PI                   25736                     /* conv:2^-13 , val:3.1416 , min-max:2~4 */
#define MACRO_MBC_PI_2                 12868                     /* conv:2^-13 , val:1.5708 , min-max:1~2 */
#define MACRO_MBC_PWM_T_2_IDY          0                         /* conv:2^0 , val:0 , min-max:0~10000 */
#define MACRO_MBC_PWM_T_2_PCR          10000                      /* conv:2^0 , val:6600 , min-max:0~10000 */
#define MACRO_MOTOR_CHECKTIME          25U                       /* conv:2^0 , val:25 , min-max:0~1000 */
#define MACRO_MOTOR_OVERCURRENT_CHECKTIME 50U                      /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_MOTOR_CURRENTMAX         fsMotorCurrentMax                     /* conv:2^-7A , val:110 , min-max:80~120 */
#define MACRO_MOTOR_DEFAULTDUTY        48U                       /* conv:2^0 , val:32 , min-max:~ */
#define MACRO_MOTOR_DIFFTIME           250U                      /* conv:2^0 , val:250 , min-max:0~1000 */
#define MACRO_MOTOR_OUTPUTMAX          6400                      /* conv:2^-7A , val:50 , min-max:0~80 */
#define MACRO_MOTOR_OUTPUTPER          64U                       /* conv:2^-7 , val:0.5 , min-max:0~1 */
#define MACRO_MOTOR_PASSTIME           5U                        /* conv:2^0 , val:5 , min-max:0~1000 */
#define MACRO_MOTOR_STOPTIME           50U                      /* conv:2^0 , val:100 , min-max:0~1000 */
#define MACRO_MR_INERANG_D             715                       /* conv:2^-13rad , val:0.087266 , min-max:0~1 */
#define MACRO_MR_INERANG_TIMER         500U                      /* conv:2^0 , val:500 , min-max:0~1000 */
#define MACRO_MR_INERBRG_MAX           (Int16)((((((((Int32)Cal_Power_High) * MACRO_MBC_ONESQRTTHIRD)>>12)*MACRO_MBC_PID_LIMIT_PCR)>>7)*fsMotorPidOutModulation)>>10)                     /* conv:2^-10V , val:10.7296 , min-max:0~15 */
#define MACRO_MR_INERBRG_MIN           (Int16)((((((((Int32)Cal_Power_Low) * MACRO_MBC_ONESQRTTHIRD)>>12)*MACRO_MBC_PID_LIMIT_PCR)>>7)*fsMotorPidOutModulation)>>10)                      /* conv:2^-10V , val:5.9313 , min-max:0~15 */
#define MACRO_MR_INERMAX_ACC           39045157                  /* conv:2^-10rad/s^2 , val:38130.0361 , min-max:0~50000 */
#define MACRO_MR_INERMAX_HMNEMF        18432                     /* conv:2^-10V , val:18 , min-max:0~20 */
#define MACRO_MR_INERMAX_HMNI          1024                      /* conv:2^-7A , val:8 , min-max:0~20 */
#define MACRO_MR_INERMAX_HMNV          201                       /* conv:2^-10V , val:0.19629 , min-max:0~1 */
#define MACRO_MR_INERMAX_HMNVCF        18432                     /* conv:2^-10V , val:18 , min-max:0~20 */
#define MACRO_MR_INERMAX_IDIF          2048                      /* conv:2^-7A , val:16 , min-max:0~20 */
#define MACRO_MR_INERMAX_OUTDIF        2                         /* conv:2^-3V^2 , val:0.25 , min-max:0~1 */
#define MACRO_MR_INERMAX_REV           643398                    /* conv:2^-10rad/s , val:628.3185 , min-max:0~1000 */
#define MACRO_MR_INERMAX_REVDIF        428932                    /* conv:2^-10rad/s , val:418.8789 , min-max:0~1000 */
#define MACRO_MR_INERMAX_REVTIME       250U                      /* conv:2^0 , val:250 , min-max:0~1000 */
#define MACRO_MR_INERMAX_VDIF          256                       /* conv:2^-10V , val:0.25 , min-max:0~1 */
#define MACRO_MR_INERTMP_MAX           627U                      /* conv:2^-7V , val:4.9 , min-max:0~5 */
#define MACRO_MR_INERTMP_MIN           13U                       /* conv:2^-7V , val:0.1 , min-max:0~5 */
#define MACRO_MR_INERVCC_MAX           192U                      /* conv:2^-7V , val:1.5 , min-max:0~5 */
#define MACRO_MR_INERVCC_MIN           128U                      /* conv:2^-7V , val:1 , min-max:0~5 */
#define MACRO_MR_MONITOR_OUTTIME       500U                      /* conv:2^0 , val:500 , min-max:0~1000 */
#define MACRO_MR_OUTERMAX_LIMITGAIN    16                        /* conv:2^0 , val:32 , min-max:0~100 */
#define MACRO_MR_OUTERMAX_LIMITTRQ     3060                      /* conv:2^-10Nm , val:3 , min-max:0~5 */
#define MACRO_MR_OUTERMAX_SWHASST      7680                      /* conv:2^-7Nm , val:20 , min-max:0~100 */
#define MACRO_MR_OUTERMAX_SWHTRQ       500                       /* conv:2^-10Nm , val:0.5 , min-max:0~1 */
#define MACRO_MR_OUTERMAX_TRQTIMER     250U                      /* conv:2^0 , val:250 , min-max:0~1000 */
#define MACRO_MSWITCH_CHANGETIME       20U                       /* conv:2^0 , val:2000 , min-max:0~5000 */
#define MACRO_MSWITCH_WAITTIME         2000U                     /* conv:2^0 , val:2000 , min-max:0~5000 */
#define MACRO_PHASEDUTY_MAX            7500U                     /* conv:2^0 , val:4600 , min-max:0~10000 */
#define MACRO_PHASEDUTY_MIN            2500U                     /* conv:2^0 , val:2000 , min-max:0~10000 */
#define MACRO_POWER_ABNORMALTIME       20U                       /* conv:2^0 , val:20 , min-max:0~1000 */
#define MACRO_POWER_ALRECOVERTIME      20U                       /* conv:2^0 , val:20 , min-max:0~1000 */
#define MACRO_POWER_ALTERTIME          10U                       /* conv:2^0 , val:10 , min-max:0~1000 */
#define MACRO_POWER_BATTIME            500U                      /* conv:2^0 , val:500 , min-max:0~1000 */
#define MACRO_POWER_BROWNOUTTIME       25U                       /* conv:2^0 , val:25 , min-max:0~1000 */
#define MACRO_POWER_BURNEDTIME         50U                       /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_POWER_HOLDIGVOL          602                       /* conv:2^-7V , val:4.7 , min-max:0~15 */
#define MACRO_POWER_HOLDTIME           1000U                     /* conv:2^0 , val:1000 , min-max:0~1000 */
#define MACRO_POWER_IGNBREAK           384                       /* conv:2^-7V , val:3 , min-max:0~15 */
#define MACRO_POWER_IGTIME             300U                      /* conv:2^0 , val:100 , min-max:0~1000 */
#define MACRO_POWER_LOWRESETTIME       50U                       /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_POWER_LOWTIME            20U                       /* conv:2^0 , val:20 , min-max:0~1000 */
#define MACRO_POWER_OVERTIME           20U                       /* conv:2^0 , val:20 , min-max:0~1000 */
#define MACRO_POWER_SHUTIME            80U                       /* conv:2^0 , val:80 , min-max:0~1000 */
#define MACRO_POWER_STANDARDVOL        1600                      /* conv:2^-7V , val:12.5 , min-max:0~20 */
#define MACRO_POWER_VICEMONITOR        1024                      /* conv:2^-7V , val:8 , min-max:0~15 */
#define MACRO_RAD2RPM                  1222U                     /* conv:2^-7rpm/(rad/s) , val:9.5493 , min-max:8~10 */
#define MACRO_RESOLVERPOWER_MIN        1024                      /* conv:2^-7V , val:8 , min-max:6~9 */
#define MACRO_RESOLVER_CHAOSMIN        960U                      /* conv:2^-7V , val:7.5 , min-max:6~9 */
#define MACRO_RESOLVER_CHECKTIME       25U                       /* conv:2^0 , val:25 , min-max:0~1000 */
#define MACRO_RESOLVER_FAULTCNT        50U                       /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_RESOLVER_LOTUSMAX        512U                      /* conv:2^-7V^2 , val:4 , min-max:0~5 */
#define MACRO_RESOLVER_LOTUSMIN        20U                       /* conv:2^-7V^2 , val:0.15625 , min-max:0~5 */
#define MACRO_RESOLVER_MIDMAX          333U                      /* conv:2^-7V , val:2.6 , min-max:0~5 */
#define MACRO_RESOLVER_MIDMIN          307U                      /* conv:2^-7V , val:2.4 , min-max:0~5 */
#define MACRO_RESOLVER_POWERMIN        1024U                     /* conv:2^-7V , val:8 , min-max:6~9 */
#define MACRO_RESOLVER_SIGAMP          512U                      /* conv:2^-7V , val:4 , min-max:0~5 */
#define MACRO_RESOLVER_SIGMAX          602U                      /* conv:2^-7V , val:4.7 , min-max:0~5 */
#define MACRO_RESOLVER_SIGMIN          38U                       /* conv:2^-7V , val:0.3 , min-max:0~5 */
#define MACRO_RESOLVER_SUMMAX          800U                      /* conv:2^-7V , val:6.25 , min-max:0~10 */
#define MACRO_RESOLVER_SUMMIN          480U                      /* conv:2^-7V , val:3.75 , min-max:0~10 */
#define MACRO_REVEXT_DEADDOOR          3200                      /* conv:2^-15rad/s , val:0.097656 , min-max:0~0.1 */
#define MACRO_REVEXT_LIMITI            100000                    /* conv:2^-10rad/s , val:97.6563 , min-max:50~200 */
#define MACRO_REVEXT_LIMITR            150000                    /* conv:2^-10rad/s , val:146.4844 , min-max:100~500 */
#define MACRO_REVEXT_LOWMAX            24000                     /* conv:2^-3rpm , val:3000 , min-max:0~4000 */
#define MACRO_REVEXT_TRGCNT            2U                        /* conv:2^0 , val:2 , min-max:0~1000 */
#define MACRO_ROTOR2STEER              fsMotorRotorToSteer                     /* conv:2^-9 , val:3.0971 , min-max:3~3.8 */
#define MACRO_SE_ANGRATE               1                         /* conv:2^-4deg , val:0.0625 , min-max:0~1 */
#define MACRO_SE_LIMITVS               160U                      /* conv:2^-5 , val:5 , min-max:0~200 */
#define MACRO_SHUNTCURRENT             3840                      /* conv:2^-7A , val:30 , min-max:0~100 */
#define MACRO_SHUTDOWN_MOSBREAK        384                       /* conv:2^-7V , val:3 , min-max:0~5 */
#define MACRO_SHUTDOWN_TIMEOUT         700U                      /* conv:2^0 , val:700 , min-max:0~1000 */
#define MACRO_SL_ISHUT_MAX             19200                     /* conv:2^-7 , val:100 , min-max:0~150 */
#define MACRO_SL_ISQRSUM_MAX           2880000U                  /* conv:2^-7 , val:22500 , min-max:0~30000 */
#define MACRO_STEERANGLE_SELECT        0U                        /* conv:2^0 , val:0, min-max:0~1 */
#define MACRO_STRTRQ_CHECKTIME         10U                       /* conv:2^0 , val:10 , min-max:0~1000 */
#define MACRO_STRTRQ_CONTTIME          50U                       /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_STRTRQ_FIRCOEF_C         1.0                       /* conv:2^0 , val:1 , min-max:0~2 */
#define MACRO_STRTRQ_FIRFRZMAX         2000                      /* conv:2^0 , val:2000 , min-max:0~2000 */
#define MACRO_STRTRQ_FIRFRZMIN         200                       /* conv:2^0 , val:200 , min-max:0~2000 */
#define MACRO_STRTRQ_FIRREVMAX         10000U                    /* conv:2^-3rpm , val:1250 , min-max:0~4000 */
#define MACRO_STRTRQ_FRZMAX            2500U                     /* conv:2^0Hz , val:2500 , min-max:2100~2500 */
#define MACRO_STRTRQ_FRZMIN            1500U                     /* conv:2^0Hz , val:1500 , min-max:1500~1900 */
#define MACRO_STRTRQ_MAX               9375U                     /* conv:2^0 , val:9375 , min-max:8000~10000 */
#define MACRO_STRTRQ_MIN               625U                      /* conv:2^0 , val:625 , min-max:0~2000 */
#define MACRO_STRTRQ_OFFSET            500                       /* conv:2^0 , val:500 , min-max:0~1000 */
#define MACRO_STRTRQ_POWERMAX          704U                      /* conv:2^-7V , val:5.5 , min-max:4~6 */
#define MACRO_STRTRQ_POWERMIN          576U                      /* conv:2^-7V , val:4.5 , min-max:4~6 */
#define MACRO_STRTRQ_RECOVERTIME       25U                       /* conv:2^0 , val:25 , min-max:0~1000 */
#define MACRO_STRTRQ_RSTCONTTIME       5000U                     /* conv:2^0 , val:5000 , min-max:0~10000 */
#define MACRO_STRTRQ_SUMMAX            10500U                    /* conv:2^0 , val:10500 , min-max:9000~11000 */
#define MACRO_STRTRQ_SUMMIN            9500U                     /* conv:2^0 , val:9500 , min-max:9000~11000 */
#define MACRO_STRTRQ_SUPPLYCHECK       896                       /* conv:2^-7V , val:7 , min-max:0~10 */
#define MACRO_TEMPR_CHECKTIME          100U                      /* conv:2^0 , val:100 , min-max:0~1000 */
#define MACRO_TEMPR_CHECKTIME_2        50U                       /* conv:2^0 , val:50 , min-max:0~1000 */
#define MACRO_TEMPR_RCVMAX             512U                      /* conv:2^-7V , val:4 , min-max:0~5 */
#define MACRO_TEMPR_RCVMIN             128U                      /* conv:2^-7V , val:1 , min-max:0~5 */
#define MACRO_TEMPR_SIGMAX             627U                      /* conv:2^-7V , val:4.9 , min-max:0~5 */
#define MACRO_TEMPR_SIGMIN             13U                       /* conv:2^-7V , val:0.1 , min-max:0~5 */
#define MACRO_TEMP_DP_ENABLE           1U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define MACRO_TESTMODE_ZEROLOOPFLAG    1U                        /* conv:2^0 , val:1 , min-max:~ */
#define MACRO_TL_MAXAPARATE            64                        /* conv:2^-7Nm/ms , val:0.5 , min-max:0~10 */
#define MACRO_TL_MAXLKARATE            256                       /* conv:2^-7Nm/ms , val:2 , min-max:0~10 */
#define MACRO_TL_MAXTRQLIMIT           12800                     /* conv:2^-7Nm , val:100 , min-max:80~120 */
#define MACRO_TOC_HDL_TMR              15000U                    /* conv:2^0 , val:15000 , min-max:0~60000 */
#define MACRO_TOC_SHORT_TMR            2000U                     /* conv:2^0 , val:249 , min-max:0~1000 */
#define MACRO_TP_BRIDGESHUT            960                       /* conv:2^-7V , val:7.5 , min-max:0~30 */
#define MACRO_TP_BRIDGEWORK            1024                      /* conv:2^-7V , val:8 , min-max:0~30 */
#define MACRO_TP_FAULTSHUT_TIME        10U                       /* conv:2^0 , val:10 , min-max:0~1000 */
#define MACRO_TP_INITCHECK_DRIVETIME   80U                       /* conv:2^0 , val:80 , min-max:0~1000 */
#define MACRO_TP_INITCHECK_OUTTIME     800U                      /* conv:2^0 , val:800 , min-max:0~1000 */
#define MACRO_TP_INITCHECK_PASSTIME    10U                       /* conv:2^0 , val:10 , min-max:0~1000 */
#define MACRO_TP_INITCHECK_STEPTIME    100U                      /* conv:2^0 , val:100 , min-max:0~1000 */
#define MACRO_TP_INITCHECK_STEPTIME_PM 400U                      /* conv:2^0 , val:400 , min-max:0~1000 */
#define MACRO_TP_MOTORCHECK_REVDN      800                       /* conv:2^-3rpm , val:100 , min-max:0~500 */
#define MACRO_TP_MOTORCHECK_REVUP      2400                      /* conv:2^-3rpm , val:300 , min-max:0~500 */
#define MACRO_TP_REGULAR_VCCTIME       10U                       /* conv:2^0 , val:10 , min-max:0~1000 */
#define MACRO_TP_TASKEN_OFFPREDRIVETEST 1                        /* conv:2^0 , val:1 , min-max:0~1 */
#define MACRO_TP_TASKEN_ONPREDRIVE     1                         /* conv:2^0 , val:1 , min-max:0~1 */
#define MACRO_TQ_MAX_TORQAV            4096                      /* conv:2^-10Nm , val:4 , min-max:3~5 */
#define MACRO_TQ_MAX_TORQM             8806                      /* conv:2^-10Nm , val:8.6 , min-max:8~10 */
#define MACRO_TQ_STRTRQ_SNR_COEF       fsStrTrqSNRCoef                       /* conv:2^-17Nm , val:0.0019531 , min-max:0.0015~0.0025 */
#define MACRO_VARIANT_PID_SELECT       1U                        /* conv:2^0 , val:1 , min-max:0~1 */
#define STEEREND_ZONE_VARIABLE         0U                        /* conv:2^0 , val:0 , min-max:0~1 */
#define STRANG_RTRANG_DIFF_TYPEMODE    0U                        /* conv:2^0 , val:1 , min-max:0~1 */
#ifndef TRUE
#define TRUE                           1U                        /* conv:2^0 , val:1 , min-max:0~1 */
#endif
#endif                                 /* RTW_HEADER_SimDiagMacro_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
