/*
 * File: BehavourModule.h
 *
 * Code generated for Simulink model 'BehavourModule'.
 *
 * Model version                  : 1.1146
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Sep 13 17:15:14 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BehavourModule_h_
#define RTW_HEADER_BehavourModule_h_
#ifndef BehavourModule_COMMON_INCLUDES_
# define BehavourModule_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BehavourModule_COMMON_INCLUDES_ */

#include "BehavourModule_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "SimDiagMacroCAN.h"
#include "GlobalVar.h"
#include "CalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S1>/BehavourModule_BYDPowerMode' */
#ifndef BehavourModule_MDLREF_HIDE_CHILD_
#if MACRO_BEHAVEMODULE_SELECT == 1

typedef struct {
  struct {
    UInt32 is_c7_BehavourModule:3;     /* '<S4>/BYDPowerMode_StateTransition' */
    UInt32 is_c8_BehavourModule:2;    /* '<S5>/BehavourModule_PowerModeLogic' */
    UInt32 is_active_c8_BehavourModule:1;
                                      /* '<S5>/BehavourModule_PowerModeLogic' */
    UInt32 is_active_c7_BehavourModule:1;/* '<S4>/BYDPowerMode_StateTransition' */
  } bitsForTID0;

  Int16 BM_Rate;                       /* '<S4>/BYDPowerMode_StateTransition' */
  Int16 BM_Coef;                       /* '<S4>/BYDPowerMode_StateTransition' */
  Int16 Delay_DSTATE;                  /* '<S4>/Delay' */
  UInt16 PM_Timer;                    /* '<S5>/BehavourModule_PowerModeLogic' */
  UInt16 vsinvalidcnt;                 /* '<S4>/BYDPowerMode_TriggerLogic' */
  UInt16 Crank_timer;                  /* '<S4>/BYDPowerMode_StateTransition' */
  Bool TR00;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR01;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR02;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR03;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR04;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR05;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR06;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR07;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
  Bool TR08;                           /* '<S4>/BYDPowerMode_TriggerLogic' */
} DW_BehavourModule_BYDPowerMode;

#endif
#endif                                 /*BehavourModule_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S1>/BehavourModule_Default' */
#ifndef BehavourModule_MDLREF_HIDE_CHILD_
#if MACRO_BEHAVEMODULE_SELECT == 0

typedef struct {
  struct {
    UInt32 is_c5_BehavourModule:3;   /* '<S12>/StartStopState_BehavourModule' */
    UInt32 is_c2_BehavourModule:2;   /* '<S12>/StartStopState_PowerModeLogic' */
    UInt32 is_active_c2_BehavourModule:1;
                                     /* '<S12>/StartStopState_PowerModeLogic' */
    UInt32 is_active_c5_BehavourModule:1;
                                     /* '<S12>/StartStopState_BehavourModule' */
    UInt32 lastig:1;                   /* '<S10>/ONOFFSTATE' */
    UInt32 lastvslost:1;               /* '<S10>/ONOFFSTATE' */
    UInt32 advst:1;                    /* '<S10>/ONOFFSTATE' */
  } bitsForTID0;

  Int16 BM_Rate;                     /* '<S12>/StartStopState_BehavourModule' */
  Int16 BM_Coef;                     /* '<S12>/StartStopState_BehavourModule' */
  Int16 Delay_DSTATE;                  /* '<S12>/Delay' */
  UInt16 PM_Timer;                   /* '<S12>/StartStopState_PowerModeLogic' */
  UInt16 Off_timer;                  /* '<S12>/StartStopState_BehavourModule' */
  UInt16 Crank_timer;                /* '<S12>/StartStopState_BehavourModule' */
  UInt16 Active_timer;               /* '<S12>/StartStopState_BehavourModule' */
  UInt16 ASreadyTimer;               /* '<S12>/StartStopState_BehavourModule' */
  UInt8 readystate;                  /* '<S12>/StartStopState_BehavourModule' */
  Bool Compare;                        /* '<S15>/Compare' */
  Bool Compare_h2nq;                   /* '<S16>/Compare' */
  Bool Compare_cc0n;                   /* '<S17>/Compare' */
  Bool Compare_h23c;                   /* '<S18>/Compare' */
  Bool UnitDelay_DSTATE;               /* '<S11>/Unit Delay' */
  Bool UnitDelay1_DSTATE;              /* '<S11>/Unit Delay1' */
} Behav_DW_BehavourModule_Default;

#endif
#endif                                 /*BehavourModule_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'BehavourModule' */
#ifndef BehavourModule_MDLREF_HIDE_CHILD_

typedef struct {

#if MACRO_BEHAVEMODULE_SELECT == 0

  Behav_DW_BehavourModule_Default BehavourModule_Default;/* '<S1>/BehavourModule_Default' */

#define BEHAVOURMODULE_DW_FWU4_VARIANT_EXISTS
#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

  DW_BehavourModule_BYDPowerMode BehavourModule_BYDPowerMode;/* '<S1>/BehavourModule_BYDPowerMode' */

#define BEHAVOURMODULE_DW_FWU4_VARIANT_EXISTS
#endif

#ifndef BEHAVOURMODULE_DW_FWU4_VARIANT_EXISTS

  char _rt_unused;

#endif

} BehavourModule_DW_fwu4;

#endif                                 /*BehavourModule_MDLREF_HIDE_CHILD_*/

extern void BehavourModule_Init(void);
extern void BehavourModule(void);

#ifndef BehavourModule_MDLREF_HIDE_CHILD_
#if MACRO_BEHAVEMODULE_SELECT == 1

extern void B_BYDPowerMode_BMRateLimit_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void Behavo_BYDPowerMode_BMRateLimit(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void BYDPowerMode_StateTransiti_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void Be_BYDPowerMode_StateTransition(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void Behav_BYDPowerMode_TriggerLogic(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void BehavourModule_BYDPowerMod_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void Beh_BehavourModule_BYDPowerMode(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void BehavourModule_PowerModeLo_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void B_BehavourModule_PowerModeLogic(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void BehavourModule_DTCPowerMod_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 1

extern void Beh_BehavourModule_DTCPowerMode(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void Behav_BehavourModule_OnOffState(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void B_BehavourModule_RunInvalidLost(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void StartStopState_BMRateLimit_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void Beha_StartStopState_BMRateLimit(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void StartStopState_BehavourMod_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void B_StartStopState_BehavourModule(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void StartStopState_PowerModeLo_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void B_StartStopState_PowerModeLogic(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void BehavourModule_StartStopSt_Init(void);

#endif

#if MACRO_BEHAVEMODULE_SELECT == 0

extern void B_BehavourModule_StartStopState(void);

#endif
#endif                                 /*BehavourModule_MDLREF_HIDE_CHILD_*/

#ifndef BehavourModule_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern BehavourModule_DW_fwu4 BehavourModulertDW;

#endif                                 /*BehavourModule_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'BehavourModule'
 * '<S1>'   : 'BehavourModule/BehavourModule'
 * '<S2>'   : 'BehavourModule/BehavourModule/BehavourModule_BYDPowerMode'
 * '<S3>'   : 'BehavourModule/BehavourModule/BehavourModule_Default'
 * '<S4>'   : 'BehavourModule/BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode'
 * '<S5>'   : 'BehavourModule/BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_DTCPowerMode'
 * '<S6>'   : 'BehavourModule/BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_BMRateLimit'
 * '<S7>'   : 'BehavourModule/BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_StateTransition'
 * '<S8>'   : 'BehavourModule/BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_TriggerLogic'
 * '<S9>'   : 'BehavourModule/BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_DTCPowerMode/BehavourModule_PowerModeLogic'
 * '<S10>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_OnOffState'
 * '<S11>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_RunInvalidLost'
 * '<S12>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_StartStopState'
 * '<S13>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_OnOffState/ONOFFSTATE'
 * '<S14>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_RunInvalidLost/Compare To Constant'
 * '<S15>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_RunInvalidLost/Compare To Constant1'
 * '<S16>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_RunInvalidLost/Compare To Constant2'
 * '<S17>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_RunInvalidLost/Compare To Constant3'
 * '<S18>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_RunInvalidLost/Compare To Constant4'
 * '<S19>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BMRateLimit'
 * '<S20>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BehavourModule'
 * '<S21>'  : 'BehavourModule/BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_PowerModeLogic'
 */

/*-
 * Requirements for '<Root>': BehavourModule
 */
#endif                                 /* RTW_HEADER_BehavourModule_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
