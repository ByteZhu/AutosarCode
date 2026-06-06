/*
 * File: GlobalVar.h
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Sep 16 11:53:04 2022
 */

#ifndef RTW_HEADER_SHI_GlobalVar_h_
#define RTW_HEADER_SHI_GlobalVar_h_
#include "rtwtypes.h"
#include "Std_Types.h"
#include "Rte_Type.h"
#include "common.h"


extern volatile Int16 Fv_SHI_FreqDetDiff;
extern volatile Int16 Fv_SHI_FreqDetGrid;
extern volatile Int16 Fv_SHI_FreqDetValue;
extern volatile Int16 Fv_SHI_FreqGain;
extern volatile Int16 Fv_SHI_Torque;
extern volatile Int16 Fv_ShimmyNotchTrq;
extern volatile Int16 Fv_ShimmyTrq;
extern volatile UInt8 Fv_SHI_Configuration;
extern volatile UInt8 Fv_SHI_ControlSts;
extern volatile Int16 Fv_SHI_FreqValue;

extern volatile Int16 FC_TrqOutput_Last;
extern volatile UInt8 Fv_FriCompAdptiveLearnCnt;
extern volatile Int16 Fv_FriCompAdptiveTorque;
extern volatile Int16 Fv_FriCompAdptiveTorqueLast;
extern volatile Int16 Tv_FriCompTrq_Adp_Gain;


extern volatile UInt16 Fv_SF_Frez;
extern volatile Int16 Fv_SF_Torque;
extern volatile Bool Fv_TSC_Configuration;
extern volatile Int16 Fv_TSC_CurOut;
extern volatile UInt8 Fv_TSC_Flag;
extern volatile UInt8 Fv_TSC_SpdFlag;

extern volatile uint8 Fv_EXT_PMIndication;
extern volatile uint8 Fv_EXT_SpdIndication;

extern volatile uint8 Fv_EXT_SpdValidFlag;
extern volatile uint8 Fv_EXT_SpdLostFlag;
extern volatile uint8 Fv_EXT_PMValidFlag;
extern volatile uint8 Fv_EXT_PMLostFlag;
extern volatile uint8 Fv_EXT_ASSReqValidFlag;

extern volatile uint16 Fv_EXT_CanSpd;
extern volatile uint8 Fv_EXT_CanPowerMode;
extern volatile uint8 Fv_EXT_CanAssReq;
extern volatile uint8 Fv_EXT_CanVehMtnS;
extern volatile uint16 Fv_EXT_CanElPwrLvl;

extern volatile uint8 Fv_EXT_NMState;
extern volatile uint8 Fv_EXT_FiveMinRule;

extern volatile uint16 Fv_EXT_InternalSpd;
extern volatile uint8 Fv_EXT_InternalPowerMode;
extern volatile uint8 Fv_EXT_InternalAssReq;
extern volatile uint8 Fv_EXT_InternalDriverMode;

extern volatile sint16 Tv_StrSASAng;//0.1
extern volatile sint16 Tv_StrSASAngValid;//1 or 0

extern volatile uint8 Fv_EXT_RE_SysStaus;
extern volatile uint8 Fv_EXT_RE_DrvState_M;
extern volatile uint8 Fv_EXT_RE_DrvState_S;
extern volatile uint8 Fv_EXT_RE_AlgState_M;
extern volatile uint8 Fv_EXT_RE_AlgState_S;
extern volatile uint8 Fv_EXT_RE_McuState_M;
extern volatile uint8 Fv_EXT_RE_McuState_S;
extern volatile uint8 Fv_EXT_RE_InnerCanState;


extern volatile uint8 Fv_EXT_RE_OutFlag_M;
extern volatile uint8 Fv_EXT_RE_OutFlag_S;
extern volatile uint8 Fv_EXT_RE_CtrlFlag;//0 for no control 1 for main 2 for sub


extern volatile uint16 Fv_EXT_InnerCanLostCnt;


extern volatile UInt8 Fv_AbsLostFlag;//0xE0
extern volatile UInt8 Fv_AdsModLostFlag;//0x190
extern volatile UInt8 Fv_LkaLostFlag;//0x33
extern volatile UInt8 Fv_APALostFlag;//0xEB
extern volatile UInt8 Fv_UsageLostFlag;//0x2E0
extern volatile UInt8 Fv_VehModMngtGlbSafe1UBFlag;//0x2E0
#endif                                 /* RTW_HEADER_GlobalVar_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
