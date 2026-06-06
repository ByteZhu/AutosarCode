/*
 * MotorControl.h
 *
 *  Created on: 2021��8��19��
 *      Author: TIAN
 */

#ifndef _MOTOR_PRIVATE_H_
#define _MOTOR_PRIVATE_H_

#include "common.h"

typedef struct
{
        sint32 err;
        sint32 errlast;
        sint32 u;
        sint32 du;
        sint32 err_e;
        sint32 i;
        sint32 p;
}MotorCtrl_PidParType;
typedef struct
{
		uint8 cursmppending;
		uint8 ResetTrgPending;
        uint8 section;
        sint16 t0;
        sint16 t1;
        sint16 t2;
        sint16 PwmU;
        sint16 PwmV;
        sint16 PwmW;
        sint16 PwmUdz;
        sint16 PwmVdz;
        sint16 PwmWdz;
        sint16 PwmUlimit;
        sint16 PwmVlimit;
        sint16 PwmWlimit;
        sint16 angle;
		sint16 eangsin;
		sint16 eangcos;
		sint16 elcdomin;
        sint16 CtrlVoltage;
        sint16 initanglecrr;
        sint32 initangle;
        sint32 shuntcurrent;
		sint32 currentU;
		sint32 currentV;
		sint32 currentW;
		sint32 voltageD;
		sint32 voltageQ;
		sint32 currentQ;
		sint32 currentD;
		sint32 curaimQ;
		sint32 curaimD;
		sint32 currentAlpha;
		sint32 currentBeta;
		sint32 voltageAlpha;
		sint32 voltageBeta;
        MotorCtrl_PidParType dxispidpar;
        MotorCtrl_PidParType qxispidpar;
}MotorCtrl_FocParType;

#define MACRO_MBC_12PI      (Int32)308831 /*2^-13, 37.6991*/
#define MACRO_MBC_10PI      (Int32)257359 /* 31.4159 */
#define MACRO_MBC_2PI       (Int32)51472 /* 6.2832 */
#define MACRO_MBC_4PI       (Int32)102944 /* 12.5664 */
#define MACRO_MBC_6PI       (Int32)154416 /* 18.8496 */
#define MACRO_MBC_8PI       (Int32)205887 /* 25.1327 */
#define MACRO_MBC_PI      (Int32)25736 /* 3.1416 */
#define MACRO_MBC_PI_2        (Int32)12868 /* 1.5708 */
#define MACRO_MBC_PI_6      (Int32)4289 /* 0.5236 */
#define MACRO_MBC_PI_3      (Int32)8579 /* 1.0472 */
#define MACRO_MBC_PI_3N     (Int32)(-MACRO_MBC_PI_3)
#define MACRO_MBC_2PI_3     (Int32)(2*MACRO_MBC_PI_3)
#define MACRO_MBC_2PI_3N    (Int32)(-MACRO_MBC_2PI_3)
#define MACRO_MBC_PIN       (Int32)(-MACRO_MBC_PI)

#define MACRO_MBC_DXRES_LEVEL_HUGE  (UInt8)4
#define MACRO_MBC_DXRES_LEVEL_WAKE  (UInt8)3
#define MACRO_MBC_DXRES_LEVEL_WAVE  (UInt8)2
#define MACRO_MBC_DXRES_LEVEL_CUT0  (UInt8)0
#define MACRO_MBC_DXRES_LEVEL_CUT1  (UInt8)1
#define MACRO_MBC_DXRES_LEVEL_CUT2  (UInt8)2
#define MACRO_MBC_DXRES_BREAK_ACCL  (Int32)457560


#define MACRO_MBC_PID_MAXDKI        (UInt16)20
#define MACRO_MBC_PID_OUTMODULATION  fsMotorPidOutModulation
#define MACRO_MBC_PID_RTREATAB      (Int32)20861 /* 1303.7973 */
#define MACRO_MBC_PID_MAXDE         (Int32)6400 /*50.*/
#define MACRO_MBC_PID_MAXDEE        (Int32)2560 /*20.*/
#define MACRO_MBC_PID_MAXQE         (Int32)12800 /*100.*/
#define MACRO_MBC_PID_MAXQEE        (Int32)5120//1280 /*10.*/
#define MACRO_MBC_PID_ID_SWITCH     (Int32)-640/*-5*/
#define MACRO_MBC_PID_ID_DISCAHRGE  (Int32)-512/*-4*/
#define MACRO_MBC_PID_SWITCH_T0     (Int16)1000 /*5us,duty 10%*/


#define MACRO_MBC_PWM_T           (Int16)10000

#define MACRO_MBC_PWM_T2            (Int16)(MACRO_MBC_PWM_T*2)
#define MACRO_MBC_PWM_T_2           (Int16)(MACRO_MBC_PWM_T/2)
#define MACRO_MBC_PWM_T_4           (Int16)(MACRO_MBC_PWM_T/4)
#define MACRO_MBC_PWM_T_8           (Int16)(MACRO_MBC_PWM_T/8)
#define MACRO_MBC_PWM_T_2_PCR     (Int16)(((Int32)MACRO_MBC_PWM_T_2)*((Int32)(64+MACRO_MBC_PID_LIMIT_PCR/2))/128)
#define MACRO_MBC_PWM_T_2_IDY     (Int16)(MACRO_MBC_PWM_T_2 - MACRO_MBC_PWM_T_2_PCR)
#define MACRO_MBC_PWM_T_DIAG        (Int16)((MACRO_MBC_PWM_T - MACRO_MBC_PID_SWITCH_T0)/2)
#define MACRO_MBC_PWM_T_FCT         (Int16)100


#define MACRO_MBC_JS_INITANG        (Int32)MACRO_MBC_PI_6//4018//6005//
#define MACRO_MBC_HARMONIC_OFST     (Int16)0//30

#define MACRO_MBC_MOTOR_INITANG     MACRO_MBC_PI
#define MACRO_MBC_KNOCK_PROTECT_I   (Int32)1280 /*10,2^-7*/
#define MACRO_MBC_MAXLIMIT_CURRENTQ (Int32)(MACRO_MAX_FOC_CURRENTQ + MACRO_MBC_KNOCK_PROTECT_I)/*85,2^-7*/
#define MACRO_MBC_MAXLIMIT_IPHASE   (Int32)(MACRO_MBC_MAXLIMIT_CURRENTQ )/*90*/
#define MACRO_MBC_MAXLIMIT_ISHUT    (Int32)((MACRO_MBC_MAXLIMIT_IPHASE * MACRO_MBC_MAXLIMIT_IPHASE) >> 14)


extern MotorCtrl_FocParType MotorCtrl_FocPar[];

extern uint16 MotorControl_CurrentOffset[];

extern void Motor_Private_PhaseCurrentCal(uint8 type);
extern Int16 Motor_Private_AtanCalcu(Int16 sin_a,Int16 cos_a);
extern void Motor_Private_AngleCal(uint8 type);
extern sint16 Motor_Private_RotorPosElcdomainCal(Int32 rotor_pos_elc);
extern void Motor_Private_ClarkParkTrans(uint8 type);
extern void Motor_Private_PidCal(uint8 type, sint32 pid_power_limit);
extern void Motor_Private_SvpwmCal(uint8 type);
extern void Motor_Private_Openloop(Int32 UQ,Int32 UD,Int16 sp1,Int16 sp2,Int16 sta);
extern void Motor_Private_Sin6Cal(void);
extern void Motor_Private_DaxisDecouping(uint8 type);
extern void Motor_Private_QaxisDecouping(uint8 type);

#endif /* APP_MOTORCTRL_MOTORCONTROL_H_ */
