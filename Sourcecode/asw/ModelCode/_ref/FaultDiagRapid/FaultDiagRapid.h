/*
 * File: FaultDiagRapid.h
 *
 * Code generated for Simulink model 'FaultDiagRapid'.
 *
 * Model version                  : 1.1273
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:58:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FaultDiagRapid_h_
#define RTW_HEADER_FaultDiagRapid_h_
#ifndef FaultDiagRapid_COMMON_INCLUDES_
# define FaultDiagRapid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultDiagRapid_COMMON_INCLUDES_ */

#include "FaultDiagRapid_types.h"

/* Child system includes */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#include "FaultDiagRapid_Current.h"
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#include "FaultDiagRapid_Initial.h"
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#include "FaultDiagRapid_MCU.h"
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#include "FaultDiagRapid_Motor.h"
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#include "FaultDiagRapid_Rotor.h"
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#include "FaultDiagRapid_Torque.h"
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "GlobalVar.h"
#include "CalVar.h"
#include "GlobalVarCAN.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for model 'FaultDiagRapid' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_

typedef struct {

#if DIAGDIS_ROTORSIGNALREG == 0

  FaultDiagRa_DW_SignalCheck_g2uu SignalCheck_pci3;/* '<S182>/SignalCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_ROTORPOWERREG == 0

  FaultDiagRap_DW_PowerCheck_l5tg PowerCheck_kyga;/* '<S175>/PowerCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MOTORPREDRIVERREG == 0

  FaultDiagRapi_DW_PredriverCheck PredriverCheck;/* '<S158>/PredriverCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MOTOROVERCURRENTREG == 0

  FaultDiagRa_DW_OverCurrentCheck OverCurrentCheck;/* '<S129>/OverCurrentCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

  FaultDiag_DW_OutputCurrentCheck OutputCurrentCheck;/* '<S118>/OutputCurrentCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MCUVICECOMM == 0

  FaultDiagRapid_DW_ViceCommCheck ViceCommCheck;/* '<S108>/ViceCommCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

  FaultDiagR_DW_MotorControlCheck MotorControlCheck;/* '<S103>/MotorControlCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MCUEPSCONTROL == 0

  FaultDiagRap_DW_EPSControlCheck EPSControlCheck;/* '<S98>/EPSControlCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MCUCORE == 0

  FaultDiagRapid_DW_CoreCheck CoreCheck;/* '<S91>/CoreCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_TORQUESIGNALREG == 0

  FaultDiagRapid_DW_SignalCheck SignalCheck;/* '<S73>/SignalCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_TORQUEPOWERREG == 0

  FaultDiagRapid_DW_PowerCheck PowerCheck;/* '<S66>/PowerCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CURRENTSAMPLEREG == 0

  FaultDiagRapid_DW_SampleCheck SampleCheck;/* '<S49>/SampleCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CURRENTMIDREG == 0

  FaultDiagRapid_DW_MidCheck MidCheck; /* '<S34>/MidCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_MOTORSHORTOPENINIT == 0

  FaultDiag_DW_ShortOpenInitCheck ShortOpenInitCheck;/* '<S19>/ShortOpenInitCheck' */

#define FAULTDIAGRAPID_DW_FWU4_VARIANT_EXISTS
#endif

  struct {
    UInt32 is_TimeShaft:2;             /* '<S6>/DiagInit_InitialTimerShaft' */
    UInt32 is_OFF_predrive_Test:2;     /* '<S6>/DiagInit_InitialTimerShaft' */
    UInt32 is_active_c1_FaultDiagRapid:1;/* '<S6>/DiagInit_InitialTimerShaft' */
    UInt32 diaginitflag:1;             /* '<Root>/DiagRapid_SheduleCounter' */
    UInt32 last_Initdiag:1;            /* '<Root>/DiagRapid_SheduleCounter' */
    UInt32 onp_jump_flag:1;            /* '<S6>/DiagInit_InitialTimerShaft' */
    UInt32 ofp_jump_flag:1;            /* '<S6>/DiagInit_InitialTimerShaft' */
    UInt32 diagreset:1;                /* '<S6>/DiagInit_InitialTimerShaft' */
    UInt32 diag_step:1;                /* '<S6>/DiagInit_InitialTimerShaft' */
  } bitsForTID0;

  Int16 Fv_HighFailFlag_j3sw;          /* '<S5>/FailStateReview' */
  Int16 Fv_HighFailFlag1_g4ct;         /* '<S5>/FailStateReview' */
  Int16 Fv_HighFailFlag2_n4cj;         /* '<S5>/FailStateReview' */
  UInt16 failtimeout_cnt;              /* '<S6>/DiagInit_InitialTimerShaft' */
  UInt16 ofp_ts_cnt;                   /* '<S6>/DiagInit_InitialTimerShaft' */
  UInt16 onp_ts_cnt;                   /* '<S6>/DiagInit_InitialTimerShaft' */
  Bool reset_flag;                     /* '<Root>/DiagRapid_SheduleCounter' */
  Bool precondover1;
  Bool precondover2;
  Bool resetflag;                      /* '<S6>/DiagInit_InitialTimerShaft' */
} FaultDiagRapid_DW_fwu4;

#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Zero-crossing (trigger) state for model 'FaultDiagRapid' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState DiagInit_Step2_Reset_ZCE; /* '<S4>/DiagInit_Step2' */
  ZCSigState DiagRapid_Step1_Reset_ZCE;/* '<S3>/DiagRapid_Step1' */
  ZCSigState DiagInit_Step0_Reset_ZCE; /* '<S2>/DiagInit_Step0' */
  ZCSigState MotorInitialCheck_ShortOpen_Res;/* '<S17>/MotorInitialCheck_ShortOpen' */
} FaultDiagRapid_ZCE;

#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

extern void FaultDiagRapid(void);

/* Model reference registration function */
extern void FaultDiagRapid_initialize(void);

#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_

extern void FaultDiag_DiagRapid_Step1_Reset(void);
extern void FaultDiagRapid_DiagRapid_Step1(void);
extern void FaultDiagR_DiagInit_Step2_Reset(void);
extern void FaultDiagRapid_DiagInit_Step2(void);
extern void FaultDiagRapid_FailStateReview(void);

#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern volatile FaultDiagRapid_DW_fwu4 FaultDiagRapidrtDW;

/* Previous zero-crossings (trigger) states */
extern FaultDiagRapid_ZCE FaultDiagRapidrtPrevZCX;

#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FaultDiagRapid'
 * '<S1>'   : 'FaultDiagRapid/DiagRapid_SheduleCounter'
 * '<S2>'   : 'FaultDiagRapid/DiagRapid_Step0Func'
 * '<S3>'   : 'FaultDiagRapid/DiagRapid_Step1Func'
 * '<S4>'   : 'FaultDiagRapid/DiagRapid_Step2Func'
 * '<S5>'   : 'FaultDiagRapid/FailStateReview'
 * '<S6>'   : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0'
 * '<S7>'   : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond'
 * '<S8>'   : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft'
 * '<S9>'   : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Constant'
 * '<S10>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Constant1'
 * '<S11>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Constant2'
 * '<S12>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Constant3'
 * '<S13>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Constant4'
 * '<S14>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Constant7'
 * '<S15>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Zero'
 * '<S16>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTImerCond/Compare To Zero1'
 * '<S17>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen'
 * '<S18>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen'
 * '<S19>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check'
 * '<S20>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck'
 * '<S21>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1'
 * '<S22>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2'
 * '<S23>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1/DTCInit_Ctrl_Enabled'
 * '<S24>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1/DTC_Ctrl_Enabled'
 * '<S25>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1/getDTCEnabled'
 * '<S26>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2/DTCInit_Ctrl_Enabled'
 * '<S27>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2/DTC_Ctrl_Enabled'
 * '<S28>'  : 'FaultDiagRapid/DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2/getDTCEnabled'
 * '<S29>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1'
 * '<S30>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck'
 * '<S31>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck'
 * '<S32>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid'
 * '<S33>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample'
 * '<S34>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check'
 * '<S35>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck'
 * '<S36>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheckDis'
 * '<S37>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidCond1'
 * '<S38>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidCond2'
 * '<S39>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag1'
 * '<S40>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag2'
 * '<S41>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidCond1/Compare To Constant'
 * '<S42>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidCond1/Compare To Constant1'
 * '<S43>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidCond2/Compare To Constant'
 * '<S44>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidCond2/Compare To Constant1'
 * '<S45>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag1/DTC_Ctrl_Enabled'
 * '<S46>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag1/getDTCEnabled'
 * '<S47>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag2/DTC_Ctrl_Enabled'
 * '<S48>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag2/getDTCEnabled'
 * '<S49>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check'
 * '<S50>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck'
 * '<S51>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheckDis'
 * '<S52>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleCond1'
 * '<S53>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleCond2'
 * '<S54>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag1'
 * '<S55>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag2'
 * '<S56>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleCond1/Compare To Constant2'
 * '<S57>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleCond1/Compare To Constant3'
 * '<S58>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleCond2/Compare To Constant2'
 * '<S59>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleCond2/Compare To Constant3'
 * '<S60>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag1/DTC_Ctrl_Enabled'
 * '<S61>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag1/getDTCEnabled'
 * '<S62>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag2/DTC_Ctrl_Enabled'
 * '<S63>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag2/getDTCEnabled'
 * '<S64>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power'
 * '<S65>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal'
 * '<S66>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check'
 * '<S67>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck'
 * '<S68>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheckDis'
 * '<S69>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerCond'
 * '<S70>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerDiag'
 * '<S71>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerDiag/DTC_Ctrl_Enabled'
 * '<S72>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerDiag/getDTCEnabled'
 * '<S73>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check'
 * '<S74>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck'
 * '<S75>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheckDis'
 * '<S76>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalCond'
 * '<S77>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalDiag'
 * '<S78>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalCond/Compare To Constant1'
 * '<S79>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalCond/Compare To Constant2'
 * '<S80>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalCond/Compare To Constant3'
 * '<S81>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalDiag/DTC_Ctrl_Enabled'
 * '<S82>'  : 'FaultDiagRapid/DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalDiag/getDTCEnabled'
 * '<S83>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2'
 * '<S84>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck'
 * '<S85>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck'
 * '<S86>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck'
 * '<S87>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core'
 * '<S88>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl'
 * '<S89>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl'
 * '<S90>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm'
 * '<S91>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check'
 * '<S92>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck'
 * '<S93>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheckDis'
 * '<S94>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreCond'
 * '<S95>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreDiag'
 * '<S96>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreDiag/DTC_Ctrl_Enabled'
 * '<S97>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreDiag/getDTCEnabled'
 * '<S98>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check'
 * '<S99>'  : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck'
 * '<S100>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck/EPSCtrlCheck'
 * '<S101>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck/EPSCtrlCheck/DTC_Ctrl_Enabled'
 * '<S102>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck/EPSCtrlCheck/getDTCEnabled'
 * '<S103>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check'
 * '<S104>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck'
 * '<S105>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck/MotorCtrlCheck'
 * '<S106>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck/MotorCtrlCheck/DTC_Ctrl_Enabled'
 * '<S107>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck/MotorCtrlCheck/getDTCEnabled'
 * '<S108>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check'
 * '<S109>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck'
 * '<S110>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommCond'
 * '<S111>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommDiag'
 * '<S112>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommCond/Compare To Constant3'
 * '<S113>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommDiag/DTC_Ctrl_Enabled'
 * '<S114>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommDiag/getDTCEnabled'
 * '<S115>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent'
 * '<S116>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent'
 * '<S117>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver'
 * '<S118>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check'
 * '<S119>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck'
 * '<S120>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheckDis'
 * '<S121>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentCond1'
 * '<S122>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentCond2'
 * '<S123>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag1'
 * '<S124>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag2'
 * '<S125>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag1/DTC_Ctrl_Enabled'
 * '<S126>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag1/getDTCEnabled'
 * '<S127>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag2/DTC_Ctrl_Enabled'
 * '<S128>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OutputCurrent/DiagRapid_MotorOutputCurrent_Check/OutputCurrentCheck/OutputCurrentDiag2/getDTCEnabled'
 * '<S129>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check'
 * '<S130>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck'
 * '<S131>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheckDis'
 * '<S132>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond1'
 * '<S133>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond2'
 * '<S134>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag1'
 * '<S135>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag2'
 * '<S136>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond1/Compare To Constant3'
 * '<S137>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond1/Compare To Constant4'
 * '<S138>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond1/Compare To Constant5'
 * '<S139>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond1/Compare To Constant6'
 * '<S140>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond1/Compare To Constant7'
 * '<S141>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond1/Compare To Constant8'
 * '<S142>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond2/Compare To Constant3'
 * '<S143>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond2/Compare To Constant4'
 * '<S144>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond2/Compare To Constant5'
 * '<S145>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond2/Compare To Constant6'
 * '<S146>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond2/Compare To Constant7'
 * '<S147>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentCond2/Compare To Constant8'
 * '<S148>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag1/DTC_Ctrl_Enabled'
 * '<S149>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag1/getDTCEnabled'
 * '<S150>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag2/DTC_Ctrl_Enabled'
 * '<S151>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheck/OverCurrentDiag2/getDTCEnabled'
 * '<S152>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheckDis/Compare To Constant1'
 * '<S153>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheckDis/Compare To Constant2'
 * '<S154>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheckDis/Compare To Constant3'
 * '<S155>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheckDis/Compare To Constant4'
 * '<S156>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheckDis/Compare To Constant5'
 * '<S157>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_OverCurrent/DiagRapid_MotorOverCurrent_Check/OverCurrentCheckDis/Compare To Constant6'
 * '<S158>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check'
 * '<S159>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck'
 * '<S160>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheckDis'
 * '<S161>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverCond1'
 * '<S162>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverCond2'
 * '<S163>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag1'
 * '<S164>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag2'
 * '<S165>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverCond1/Compare To Constant1'
 * '<S166>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverCond1/Compare To Constant2'
 * '<S167>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverCond2/Compare To Constant1'
 * '<S168>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverCond2/Compare To Constant2'
 * '<S169>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag1/DTC_Ctrl_Enabled'
 * '<S170>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag1/getDTCEnabled'
 * '<S171>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag2/DTC_Ctrl_Enabled'
 * '<S172>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MotoCheck/MotorCheck_Predriver/DiagRapid_MotorPredriver_Check/PredriverCheck/PredriverDiag2/getDTCEnabled'
 * '<S173>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power'
 * '<S174>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal'
 * '<S175>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check'
 * '<S176>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck'
 * '<S177>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheckDis'
 * '<S178>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerCond'
 * '<S179>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerDiag'
 * '<S180>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerDiag/DTC_Ctrl_Enabled'
 * '<S181>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerDiag/getDTCEnabled'
 * '<S182>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check'
 * '<S183>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck'
 * '<S184>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheckDis'
 * '<S185>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond1'
 * '<S186>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond2'
 * '<S187>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag1'
 * '<S188>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag2'
 * '<S189>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond1/Compare To Constant1'
 * '<S190>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond1/Compare To Constant2'
 * '<S191>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond1/Compare To Constant3'
 * '<S192>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond1/Compare To Constant4'
 * '<S193>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond2/Compare To Constant1'
 * '<S194>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond2/Compare To Constant2'
 * '<S195>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond2/Compare To Constant3'
 * '<S196>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalCond2/Compare To Constant4'
 * '<S197>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag1/DTC_Ctrl_Enabled'
 * '<S198>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag1/getDTCEnabled'
 * '<S199>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag2/DTC_Ctrl_Enabled'
 * '<S200>' : 'FaultDiagRapid/DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag2/getDTCEnabled'
 * '<S201>' : 'FaultDiagRapid/FailStateReview/FailStateReview'
 */

/*-
 * Requirements for '<Root>': FaultDiagRapid
 */
#endif                                 /* RTW_HEADER_FaultDiagRapid_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
