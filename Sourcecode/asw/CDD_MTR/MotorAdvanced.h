/*
 * MotorAdvanced.h
 *
 *  Created on: 2021Äê8ÔÂ19ÈÕ
 *      Author: TIAN
 */

#ifndef APP_MOTORCTRL_MOTORADVANCED_H_
#define APP_MOTORCTRL_MOTORADVANCED_H_

#include "common.h"
#include "GlobalVar.h"

#define MAC_ENABLE_CHINA_S093       //MAC_DISABLE_CHINA_S093//
#define MAC_ENABLE_VARIABLE_DEAD    //MAC_DISABLE_VARIABLE_DEAD
#define MAC_DISABLE_DAXIS_DYNAMIC   MAC_ENABLE_DAXIS_DYNAMIC//
#define MAC_DISABLE_ANGLE_PSCHECK   //MAC_EABLE_ANGLE_PSCHECK     //


#define MACRO_MAC_MOTOR_POLEPAIRS       (UInt8)4

#define MACRO_MAC_STEER2RPM             fsMotorSteerToRpm
#if 0
#define MACRO_MAC_VSPIDDN0               (UInt16)640              /*2^-5,20km/h*/
#define MACRO_MAC_VSPIDUP0               (UInt16)(MACRO_MAC_VSPIDDN0 + 64 )              /*2^-5,5km/h*/
#define MACRO_MAC_VSPIDDN1               (UInt16)1600              /*2^-5,20km/h*/
#define MACRO_MAC_VSPIDUP1               (UInt16)(MACRO_MAC_VSPIDDN1 + 64 )              /*2^-5,5km/h*/
#endif

#define MACRO_MAC_VSCONST_120           (UInt16)3840             /* 120. */

#define MACRO_MAC_TAB_MAXNUM            (UInt16)8192

#define MACRO_MAC_COMP_L                (Int32)85                /*2^-20,80.5uH*/
#define MACRO_MAC_COMP_R                (Int32)1605              /*2^-16,24.5mom*/
#define MACRO_MAC_COMP_KE               (Int32)428               /*2^-16,Max REV 5066rpm,12V*/
#define MACRO_MAC_COMP_ONE              (Int32)1048576           /*2^-20*/
#define MACRO_MAC_COMP_ACC              (Int16)30
#define MACRO_MAC_COMP_KE_3P4           (Int32)321               /*2^-16,Max REV 5066rpm,12V*/
#define MACRO_MAC_COMP_KE_1P2           (Int32)214               /*2^-16,Max REV 5066rpm,12V*/
#define MACRO_MAC_COMP_KE_1P4           (Int32)107               /*2^-16,Max REV 5066rpm,12V*/
#define MACRO_MAC_COMP_VS_DN            (UInt16)480              /*2^-5*/
#define MACRO_MAC_COMP_VS_UP            (UInt16)800              /*2^-5*/
#define MACRO_MAC_COMP_VS_DF            (Int16)(MACRO_MAC_COMP_VS_UP - MACRO_MAC_COMP_VS_DN)                 /*2^-5*/


#define MACRO_MAC_DCP_C1                (Int32)994               /*2^-10*/
#define MACRO_MAC_DCP_C2                (Int32)1024              /*2^-10*/
#define MACRO_MAC_DCP_C3                (Int32)54                /*2^-20*/
#define MACRO_MAC_MAX_REV               (Int32)643398            /*2^-10,6000rpm*/
#define MACRO_MAC_MAX_REV_FOC           (Int32)(MACRO_MAC_MAX_REV*4) /*2^-10,12000rpm*/
#define MACRO_MAC_MAX_ACC               (Int32)39045157          /*2^-10, 38130rad/s^2 */
#define MACRO_MAC_RTRSPD_MAX            (Int32)40000             /*2^-3 5000*/
#define MACRO_MAC_T_TorqCal             (Int32)105               /*2^-20,1e-4*/

#define MACRO_MAC_IDFW_CURRENT_LIMIT_MAX    fsMotorIdfwCurrentLimit

extern const Int16 FOC_ID_WeakVsTab_C[121]
#ifdef MOTOR_ADVANCED_C
=
/*2^-10*/
{
  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,
  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,
  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1024,  1007,   990,   973,   956,   939,   922,
   905,   887,   870,   853,   836,   819,   802,   785,   768,   751,   734,   717,   700,   683,   666,   649,   631,   614,   597,
   580,   563,   546,   529,   512,   506,   499,   493,   486,   480,   474,   467,   461,   454,   448,   442,   435,   429,   422,
   416,   410,   403,   397,   390,   384,   378,   371,   365,   358,   352,   346,   339,   333,   326,   320,   314,   307,   301,
   294,   288,   282,   275,   269,   262,   256
}
#endif
;

extern Int16 HarmonicPhaseComptab_C[4]
#ifdef MOTOR_ADVANCED_C
=
{
     0/*w<0,I>0 */, 0/*w<0,I<0*/,0/*w>0,I>0*/, 0/*w>0,I<0 */
}
#endif
;

extern void EPS_KalmanFilter(void);

extern void FOC_KalmanFilter(void);

extern void UQ_FOCdAngLimit(uint8 type);

extern void PWM_VariableDead(uint8 type);

extern Int32 MotorCtrl_SpdLoop(Int16 AimSpeed,Int32 MaxIaim,UInt8 stop);

extern void ID_FieldWeakening_1(Int32 RTRW,UInt16 VS);

extern void HarmonicCompensation(Int32 W);

extern void HarmonicCompensation2(Int32 W);


#endif /* APP_MOTORCTRL_MOTORADVANCED_H_ */
