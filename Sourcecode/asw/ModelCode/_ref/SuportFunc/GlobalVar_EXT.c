/*
 * File: GlobalVar.c
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Sep 16 11:53:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <GlobalVar.h>
#include "GlobalVar_EXT.h"
#include "rtwtypes.h"
/* Exported data definition */


volatile Int16 Fv_SHI_FreqDetDiff;
volatile Int16 Fv_SHI_FreqDetGrid;
volatile Int16 Fv_SHI_FreqDetValue;
volatile Int16 Fv_SHI_FreqGain;
volatile Int16 Fv_SHI_Torque;
volatile Int16 Fv_ShimmyNotchTrq;
volatile Int16 Fv_ShimmyTrq;
volatile UInt8 Fv_SHI_Configuration;
volatile UInt8 Fv_SHI_ControlSts;
volatile Int16 Fv_SHI_FreqValue;

volatile Int16 FC_TrqOutput_Last;
volatile UInt8 Fv_FriCompAdptiveLearnCnt;
volatile Int16 Tv_FriCompTrq_Adp_Gain;

volatile UInt16 Fv_SF_Frez;
volatile Int16 Fv_SF_Torque;
volatile Bool Fv_TSC_Configuration;
volatile Int16 Fv_TSC_CurOut;
volatile UInt8 Fv_TSC_Flag;
volatile UInt8 Fv_TSC_SpdFlag;

volatile uint8 Fv_EXT_PMIndication;
volatile uint8 Fv_EXT_SpdIndication;

volatile uint8 Fv_EXT_SpdValidFlag;
volatile uint8 Fv_EXT_SpdLostFlag;
volatile uint8 Fv_EXT_PMValidFlag;
volatile uint8 Fv_EXT_PMLostFlag;
volatile uint8 Fv_EXT_ASSReqValidFlag;

volatile uint16 Fv_EXT_CanSpd;
volatile uint8 Fv_EXT_CanPowerMode;
volatile uint8 Fv_EXT_CanAssReq;
volatile uint8 Fv_EXT_CanVehMtnS;
volatile uint16 Fv_EXT_CanElPwrLvl;

volatile uint8 Fv_EXT_NMState = 1;
volatile uint8 Fv_EXT_FiveMinRule;

volatile uint16 Fv_EXT_InternalSpd;
volatile uint8 Fv_EXT_InternalPowerMode;
volatile uint8 Fv_EXT_InternalAssReq;
volatile uint8 Fv_EXT_InternalDriverMode;

volatile sint16 Tv_StrSASAng;//0.1
volatile sint16 Tv_StrSASAngValid;//1 or 0



volatile uint8 Fv_EXT_RE_SysStaus;
volatile uint8 Fv_EXT_RE_DrvState_M = 1;
volatile uint8 Fv_EXT_RE_DrvState_S = 1;
volatile uint8 Fv_EXT_RE_AlgState_M = 1;
volatile uint8 Fv_EXT_RE_AlgState_S = 1;
volatile uint8 Fv_EXT_RE_McuState_M = 1;
volatile uint8 Fv_EXT_RE_McuState_S = 1;
volatile uint8 Fv_EXT_RE_InnerCanState = 1;

volatile uint8 Fv_EXT_RE_OutFlag_M;
volatile uint8 Fv_EXT_RE_OutFlag_S;
volatile uint8 Fv_EXT_RE_CtrlFlag;//0 for no control 1 for main 2 for sub

volatile uint16 Fv_EXT_InnerCanLostCnt;



volatile UInt8 Fv_AbsLostFlag;//0xE0
volatile UInt8 Fv_AdsModLostFlag;//0x190
volatile UInt8 Fv_LkaLostFlag;//0x33
volatile UInt8 Fv_APALostFlag;//0xEB
volatile UInt8 Fv_UsageLostFlag;//0x2E0
volatile UInt8 Fv_VehModMngtGlbSafe1UBFlag;//0x2E0
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
