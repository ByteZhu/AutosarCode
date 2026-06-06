/*
 * File: Variant_LimitPIDparam.h
 *
 * Code generated for Simulink model 'Variant_LimitPIDparam'.
 *
 * Model version                  : 1.1141
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Sep 14 10:01:03 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Variant_LimitPIDparam_h_
#define RTW_HEADER_Variant_LimitPIDparam_h_
#ifndef Variant_LimitPIDparam_COMMON_INCLUDES_
# define Variant_LimitPIDparam_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                              /* Variant_LimitPIDparam_COMMON_INCLUDES_ */

#include "Variant_LimitPIDparam_types.h"

/* Includes for objects with custom storage classes. */
#include "CalVar.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S1>/Variant_LimitPIDparamFunc' */
#ifndef Variant_LimitPIDparam_MDLREF_HIDE_CHILD_
#if MACRO_VARIANT_PID_SELECT == 0

typedef struct {
  UInt32 m_bpIndex[2];                 /* '<S5>/BackwardCurentTab' */
  UInt32 m_bpIndex_bj45[2];            /* '<S5>/NormalRevKPTab' */
  UInt32 m_bpIndex_ixsg[2];            /* '<S5>/BackwardCurentTab1' */
  UInt32 m_bpIndex_dnc4[2];            /* '<S5>/NormalRevKITab' */
  UInt32 m_bpIndex_az0r;               /* '<S5>/BackwardRevTab' */
} Va_DW_Variant_LimitPIDparamFunc;

#endif
#endif                              /*Variant_LimitPIDparam_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S1>/Variant_LimitPIDparamFunc_BYDEK' */
#ifndef Variant_LimitPIDparam_MDLREF_HIDE_CHILD_
#if MACRO_VARIANT_PID_SELECT == 1

typedef struct {
  UInt32 m_bpIndex[2];                 /* '<S3>/PidKiTab' */
  UInt32 m_bpIndex_lyet[2];            /* '<S3>/PidKpTab' */
  UInt32 m_bpIndex_ddvf;               /* '<S9>/VsQpTab' */
  UInt32 m_bpIndex_azld;               /* '<S9>/QactQpTab' */
  UInt16 PidKpTab;                     /* '<S3>/PidKpTab' */
} DW_Variant_LimitPIDparamFunc_BY;

#endif
#endif                              /*Variant_LimitPIDparam_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'Variant_LimitPIDparam' */
#ifndef Variant_LimitPIDparam_MDLREF_HIDE_CHILD_

typedef struct {

#if MACRO_VARIANT_PID_SELECT == 1

  DW_Variant_LimitPIDparamFunc_BY Variant_LimitPIDparamFunc__juo0;

#define VARIANT_LIMITPIDPARAM_DW_FWU4_VARIANT_EXISTS
#endif

#if MACRO_VARIANT_PID_SELECT == 0

  Va_DW_Variant_LimitPIDparamFunc Variant_LimitPIDparamFunc_dtqy;

#define VARIANT_LIMITPIDPARAM_DW_FWU4_VARIANT_EXISTS
#endif

#ifndef VARIANT_LIMITPIDPARAM_DW_FWU4_VARIANT_EXISTS

  char _rt_unused;

#endif

} Variant_LimitPIDparam_DW_fwu4;

#endif                              /*Variant_LimitPIDparam_MDLREF_HIDE_CHILD_*/

extern void Variant_LimitPIDparam(void);

#ifndef Variant_LimitPIDparam_MDLREF_HIDE_CHILD_
#if MACRO_VARIANT_PID_SELECT == 0

extern void Varia_Variant_LimitPIDparamFunc(void);

#endif

#if MACRO_VARIANT_PID_SELECT == 1

extern void Variant_LimitPIDpar_LimitPID_QP(void);

#endif

#if MACRO_VARIANT_PID_SELECT == 1

extern void Variant_LimitPIDparamFunc_BYDEK(void);

#endif
#endif                              /*Variant_LimitPIDparam_MDLREF_HIDE_CHILD_*/

#ifndef Variant_LimitPIDparam_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern Variant_LimitPIDparam_DW_fwu4 Variant_LimitPIDparamrtDW;

#endif                              /*Variant_LimitPIDparam_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Variant_LimitPIDparam'
 * '<S1>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc'
 * '<S2>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc'
 * '<S3>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK'
 * '<S4>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc/LimitPID_flag'
 * '<S5>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc/LimitPID_tab'
 * '<S6>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc/LimitPID_flag/Compare To Constant'
 * '<S7>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc/LimitPID_flag/Compare To Constant1'
 * '<S8>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc/LimitPID_flag/Compare To Constant2'
 * '<S9>'   : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK/LimitPID_QP'
 * '<S10>'  : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK/LimitPID_QP/Compare To Constant'
 * '<S11>'  : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK/LimitPID_QP/Compare To Constant1'
 * '<S12>'  : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK/LimitPID_QP/Compare To Constant2'
 * '<S13>'  : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK/LimitPID_QP/Compare To Constant3'
 * '<S14>'  : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK/LimitPID_QP/Compare To Constant4'
 * '<S15>'  : 'Variant_LimitPIDparam/Variant_LimitPIDparamFunc/Variant_LimitPIDparamFunc_BYDEK/LimitPID_QP/Compare To Constant5'
 */

/*-
 * Requirements for '<Root>': Variant_LimitPIDparam
 */
#endif                                 /* RTW_HEADER_Variant_LimitPIDparam_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
