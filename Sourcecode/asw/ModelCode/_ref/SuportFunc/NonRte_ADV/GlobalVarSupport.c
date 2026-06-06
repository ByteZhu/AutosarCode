/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GlobalVarSupport.c
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

#include "GlobalVarSupport.h"
#include "rtwtypes.h"
#include "ADV_ExtFunction_types.h"

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Global */
volatile boolean Fv_APA_PosClearFlag;
volatile boolean Fv_APA_RevClearFlag;
volatile sint32 Fv_APA_Torque;
volatile boolean Fv_LKA_PosClearFlag;
volatile boolean Fv_LKA_RevClearFlag;
volatile sint16 Fv_LKA_Torque;
/*鏂板缁忎汉鏈哄叡椹緈ap杞崲杩囩殑lka杈撳嚭锛�240313 by zyg*/
volatile sint16 Fv_LKA_LimitTorque;
volatile sint16 Fv_DSR_Torque;
volatile sint16 Fv_LDW_Torque;
volatile sint16 Fv_SteerStsToParkAssi;
volatile sint16 Fv_ADV_CtrlMode;
volatile sint16 Fv_CAN_AdsTqInvalid_flag;



/*add LKA Globalvar,23.11.10 by zyg*/
volatile boolean Fv_AdsAgInvalid_flag;
volatile boolean Fv_AdsAgUBInvalid_flag;
volatile uint8 Fv_AdsMod;
volatile uint8 Fv_NOPMod;
volatile uint8 Fv_LKA_ADL3ADMod;
volatile uint8 Fv_LKA_ADL3CtrlStsSts;
volatile sint16 Fv_AdsAgReq;
volatile sint16 Fv_AdsAgTup;
volatile sint16 Fv_AdsAgTdn;
volatile uint8 Fv_LKA_AngleUpdataEn = 1;
volatile uint8 Fv_LKA_ControlSts;

volatile boolean Fv_LKA_AgReqNotInRange;
volatile boolean Fv_LKA_ExtFctUpperLimActive;
volatile boolean Fv_LKA_ExtFctLowerLimActive;
volatile boolean Fv_LKA_DrvrSteerOvrd;
volatile boolean Fv_LKA_AngleSpdLimit;
volatile Bool Fv_LKA_Configuration;
volatile sint16 Fv_LKA_LimitTorqueOut;
/*add DSR Globalvar,23.11.10 by zyg*/
volatile sint16 Fv_AdsTrqReq;
volatile boolean Fv_AdsTqInvalid;
volatile boolean Fv_AdsTqInvalid_flag;

/*add LDW Globalvar,23.11.10 by zyg*/
volatile uint8 Fv_Warnreq;


/*add APA Globalvar,23.11.10 by zyg*/
volatile sint16 Fv_AdsParkReq;
volatile boolean Fv_AdsPkInvalid_flag;
volatile uint8 Fv_APA_AngleUpdataEn = 1;
volatile uint8 Fv_APA_AbortFeedBack;
volatile uint8 Fv_APA_ControlSts;
volatile Bool Fv_APA_Configuration;
volatile Bool Fv_APA_CcpEn;
volatile Bool Fv_LKA_Ccp316En;
volatile Bool Fv_LKA_Ccp150En;
volatile uint8 Fv_DSR_ControlSts;


volatile uint8 Fv_DrvrSteerWhlHld = 1;
volatile uint8 Fv_DrvrSteerWhlHldQly;


/*add configuration 23.11.22 by zyg*/
volatile UInt8 Fv_Configuration_CCP100_TJPNOP;
volatile UInt8 Fv_Configuration_CCP142_APA;
volatile UInt8 Fv_Configuration_CCP150_LKALDW = 1;
volatile UInt8 Fv_Configuration_CCP316_LKALDW = 128;/*默锟斤拷未锟斤拷锟斤拷*/
volatile UInt8 Fv_Configuration_CCP317_EMA;
volatile UInt8 Fv_Configuration_CCP494_HWA;
volatile UInt8 Fv_Configuration_CCP565_APA;
volatile UInt8 Fv_Configuration_CCP639_HPA;
volatile UInt8 Fv_Configuration_CCP640_RPA;

volatile Int16 Fv_MotorAngle_Raw = 0;
volatile Int16 Fv_MotorAngle_Offset = 0;

volatile double Fv_FAA_LQR_ActSpd;
volatile double Fv_FAA_LQR_AimAng;
volatile double Fv_FAA_LQR_ActAng;
volatile double Fv_FAA_LQR_QcurOut;
volatile UInt8  Fv_FAA_Reset;

volatile double Fv_FAA_VehSpd;
volatile double Fv_FAA_TrqLim;

volatile double Fv_FAA_SpdKF;
volatile Int16 Fv_LKA_TorqueCmdDownLimit = -3072;
volatile Int16 Fv_LKA_TorqueCmdUpLimit = 3072;

volatile UInt8 Fv_LKAAC_ControlSts;
volatile UInt8 Fv_DST_ControlSts;
volatile UInt8 Fv_VOT_ControlSts;
volatile UInt8 Fv_APA_ControlSts;
volatile UInt8 Fv_LDW_ControlSts;
volatile UInt8 Fv_LKA_ControlSts;
volatile uint8 Tv_Asy_ActiveReturnDampingFactor = 128;/*uint8 2^-7*/
volatile uint8 Tv_Asy_ActiveReturnDampingFactorTemp = 128;/*uint8 2^-7*/
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
