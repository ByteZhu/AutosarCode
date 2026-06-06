/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FrictionComp_Study_1.h
 *
 * Code generated for Simulink model 'FrictionComp_Study_1'.
 *
 * Model version                  : 9.59
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jun  4 11:25:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FrictionComp_Study_1_h_
#define RTW_HEADER_FrictionComp_Study_1_h_
#ifndef FrictionComp_Study_1_COMMON_INCLUDES_
#define FrictionComp_Study_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* FrictionComp_Study_1_COMMON_INCLUDES_ */

#include "FrictionComp_Study_1_types.h"
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes */
#include "SimDiagMacroCAN.h"
#include "CalVarSupport.h"
#include "CalVar.h"
#include "CalVarExt.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  UInt32 anglebreakpoints_DWORK1;      /* '<S3>/anglebreakpoints' */
  UInt32 m_bpIndex;                    /* '<S3>/vehspd_coef_tab' */
  struct {
    UInt32 is_c15_FrictionComp_Study_1:3;/* '<S2>/StudyProcess_Logic' */
    UInt32 is_active_c15_FrictionComp_Stud:1;/* '<S2>/StudyProcess_Logic' */
    UInt32 lastflag:1;                 /* '<S3>/phyflag_strght' */
    UInt32 strght_trg:1;               /* '<S3>/phyflag_strght' */
    UInt32 learnvalid:1;               /* '<S2>/StudyProcess_Logic' */
    UInt32 restartflag:1;              /* '<S2>/StudyProcess_Logic' */
  } bitsForTID0;

  Int16 friction_up[21];               /* '<S2>/StudyProcess_Logic' */
  Int16 friction_down[21];             /* '<S2>/StudyProcess_Logic' */
  Int16 vehspd_coef_tab;               /* '<S3>/vehspd_coef_tab' */
  Int16 Fv_FriCompAdptiveTorque_pch4;  /* '<S2>/StudyProcess_Logic' */
  Int16 Delay_DSTATE;                  /* '<S5>/Delay' */
  Int16 Delay_DSTATE_oagu;             /* '<S4>/Delay' */
  UInt16 cnt_up[21];                   /* '<S2>/StudyProcess_Logic' */
  UInt16 cnt_down[21];                 /* '<S2>/StudyProcess_Logic' */
  UInt16 strght_cnt;                   /* '<S3>/phyflag_strght' */
  UInt16 shedulecnt;                   /* '<S1>/StudyDiffTrq_SheduleCounter' */
  Bool strght_flag;                    /* '<S3>/phyflag_strght' */
  Bool icLoad;                         /* '<S5>/Delay' */
} DW_l5cf_fcs;

/* Block signals and states (default storage) */
extern DW_l5cf_fcs rtDW_l5cf_fcs;

/* Model entry point functions */
extern void FrictionComp_Study_1_initialize(void);
extern void FrictionComp_Study_1_step(void);

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
 * '<Root>' : 'FrictionComp_Study_1'
 * '<S1>'   : 'FrictionComp_Study_1/FCA_StudyDiffTrq'
 * '<S2>'   : 'FrictionComp_Study_1/FCA_StudyProcess'
 * '<S3>'   : 'FrictionComp_Study_1/FCA_StudyStartCond'
 * '<S4>'   : 'FrictionComp_Study_1/FCA_StudyTorque'
 * '<S5>'   : 'FrictionComp_Study_1/FCA_StudyDiffTrq/StudyDiffTrq_Calc'
 * '<S6>'   : 'FrictionComp_Study_1/FCA_StudyDiffTrq/StudyDiffTrq_SheduleCounter'
 * '<S7>'   : 'FrictionComp_Study_1/FCA_StudyProcess/StudyProcess_Logic'
 * '<S8>'   : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant'
 * '<S9>'   : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant1'
 * '<S10>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant10'
 * '<S11>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant11'
 * '<S12>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant12'
 * '<S13>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant13'
 * '<S14>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant14'
 * '<S15>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant15'
 * '<S16>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant2'
 * '<S17>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant3'
 * '<S18>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant4'
 * '<S19>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant5'
 * '<S20>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant6'
 * '<S21>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant7'
 * '<S22>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant8'
 * '<S23>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/Compare To Constant9'
 * '<S24>'  : 'FrictionComp_Study_1/FCA_StudyStartCond/phyflag_strght'
 * '<S25>'  : 'FrictionComp_Study_1/FCA_StudyTorque/Data Type Scaling Strip2'
 * '<S26>'  : 'FrictionComp_Study_1/FCA_StudyTorque/Data Type Scaling Strip3'
 */

/*-
 * Requirements for '<Root>': FrictionComp_Study_1

 */
#endif                                 /* RTW_HEADER_FrictionComp_Study_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
