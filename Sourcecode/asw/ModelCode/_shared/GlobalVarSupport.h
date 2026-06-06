/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GlobalVarSupport.h
 *
 * Code generated for Simulink model 'ADV_ExtFunction'.
 *
 * Model version                  : 9.98
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 25 08:42:28 2023
 */

#ifndef RTW_HEADER_GlobalVarSupport_h_
#define RTW_HEADER_GlobalVarSupport_h_
#include "rtwtypes.h"
#include "Std_Types.h"
/* Volatile memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Global */
extern volatile boolean Fv_APA_PosClearFlag;
extern volatile boolean Fv_APA_RevClearFlag;
extern volatile sint32 Fv_APA_Torque;
extern volatile boolean Fv_LKA_PosClearFlag;
extern volatile boolean Fv_LKA_RevClearFlag;
extern volatile sint16 Fv_LKA_Torque;
extern volatile sint16 Fv_LKA_LimitTorque;
extern volatile sint16 Fv_DSR_Torque;
extern volatile sint16 Fv_LDW_Torque;
extern volatile sint16 Fv_SteerStsToParkAssi;
extern volatile sint16 Fv_ADV_CtrlMode;
extern volatile sint16 Fv_CAN_AdsTqInvalid_flag;

/*add lka Globalvar,23.11.10 by zyg*/
extern volatile boolean Fv_AdsAgInvalid_flag;
extern volatile boolean Fv_AdsAgUBInvalid_flag;
extern volatile uint8 Fv_AdsMod;
extern volatile uint8 Fv_NOPMod;
extern volatile uint8 Fv_LKA_ADL3ADMod;
extern volatile uint8 Fv_LKA_ADL3CtrlStsSts;
extern volatile sint16 Fv_AdsAgReq;
extern volatile sint16 Fv_AdsAgTup;
extern volatile sint16 Fv_AdsAgTdn;
extern volatile uint8 Fv_LKA_AngleUpdataEn;
extern volatile uint8 Fv_LKA_ControlSts;
extern volatile boolean Fv_LKA_AgReqNotInRange;
extern volatile boolean Fv_LKA_ExtFctUpperLimActive;
extern volatile boolean Fv_LKA_ExtFctLowerLimActive;
extern volatile boolean Fv_LKA_AngleSpdLimit;
extern volatile Bool Fv_LKA_Configuration;
extern volatile boolean Fv_LKA_DrvrSteerOvrd;
extern volatile sint16 Fv_LKA_LimitTorqueOut;

/*add DSR Globalvar,23.11.10 by zyg*/
extern volatile sint16 Fv_AdsTrqReq;
extern volatile boolean Fv_AdsTqInvalid_flag;
extern volatile uint8 Fv_Warnreq;
/*add LDW Globalvar,23.11.10 by zyg*/

/*add APA Globalvar,23.11.10 by zyg*/
extern volatile sint16 Fv_AdsParkReq;
extern volatile boolean Fv_AdsPkInvalid_flag;
extern volatile uint8 Fv_APA_AngleUpdataEn;
extern volatile uint8 Fv_APA_AbortFeedBack;
extern volatile uint8 Fv_APA_ControlSts;
extern volatile Bool Fv_APA_Configuration;
extern volatile Bool Fv_APA_CcpEn;
extern volatile Bool Fv_LKA_Ccp316En;
extern volatile Bool Fv_LKA_Ccp150En;
extern volatile uint8 Fv_DSR_ControlSts;

extern volatile uint8 Fv_DrvrSteerWhlHld;
extern volatile uint8 Fv_DrvrSteerWhlHldQly;

extern volatile UInt8 Fv_Configuration_CCP100_TJPNOP;
extern volatile UInt8 Fv_Configuration_CCP142_APA;
extern volatile UInt8 Fv_Configuration_CCP150_LKALDW;
extern volatile UInt8 Fv_Configuration_CCP316_LKALDW;
extern volatile UInt8 Fv_Configuration_CCP317_EMA;
extern volatile UInt8 Fv_Configuration_CCP494_HWA;
extern volatile UInt8 Fv_Configuration_CCP565_APA;
extern volatile UInt8 Fv_Configuration_CCP639_HPA;
extern volatile UInt8 Fv_Configuration_CCP640_RPA;

extern volatile Int16 Fv_MotorAngle_Raw;
extern volatile Int16 Fv_MotorAngle_Offset;
extern volatile double Fv_FAA_LQR_ActSpd;
extern volatile double Fv_FAA_LQR_AimAng;
extern volatile double Fv_FAA_LQR_ActAng;
extern volatile double Fv_FAA_LQR_QcurOut;
extern volatile UInt8  Fv_FAA_Reset;
extern volatile double Fv_FAA_VehSpd;
extern volatile double Fv_FAA_TrqLim;
extern volatile double Fv_FAA_SpdKF;
extern volatile Int16 Fv_LKA_TorqueCmdDownLimit;
extern volatile Int16 Fv_LKA_TorqueCmdUpLimit;

extern volatile UInt8 Fv_LKAAC_ControlSts;
extern volatile UInt8 Fv_DST_ControlSts;
extern volatile UInt8 Fv_VOT_ControlSts;
extern volatile UInt8 Fv_APA_ControlSts;
extern volatile UInt8 Fv_LDW_ControlSts;
extern volatile UInt8 Fv_LKA_ControlSts;

extern volatile uint8 Tv_Asy_ActiveReturnDampingFactorTemp;/*uint8 2^-7*/
extern volatile uint8 Tv_Asy_ActiveReturnDampingFactor;/*uint8 2^-7*/
#endif                                 /* RTW_HEADER_GlobalVarSupport_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
