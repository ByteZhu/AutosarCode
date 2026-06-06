/*
 * File: DesignCurveCalcFun.h
 *
 * Code generated for Simulink model 'DesignCurveCalcFun'.
 *
 * Model version                  : 1.1130
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:55:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DesignCurveCalcFun_h_
#define RTW_HEADER_DesignCurveCalcFun_h_
#ifndef DesignCurveCalcFun_COMMON_INCLUDES_
# define DesignCurveCalcFun_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DesignCurveCalcFun_COMMON_INCLUDES_ */

#include "DesignCurveCalcFun_types.h"

/* Child system includes */
#ifndef DesignCurveCalcFun_MDLREF_HIDE_CHILD_
#include "DesignCurveBasic_private.h"
#include "DesignCurveBasic.h"
#endif                                 /*DesignCurveCalcFun_MDLREF_HIDE_CHILD_*/

/* Includes for objects with custom storage classes. */
#include "CalVar.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

extern void DesignCurveCalcFun(void);

#ifndef DesignCurveCalcFun_MDLREF_HIDE_CHILD_
#if ASSIST_EXTERN_LINESEG == 1

extern void DesignCurveCa_SelectDesignCurve(void);

#endif
#endif                                 /*DesignCurveCalcFun_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'DesignCurveCalcFun'
 * '<S1>'   : 'DesignCurveCalcFun/DesignCurveCalc'
 * '<S2>'   : 'DesignCurveCalcFun/Simulink Function'
 * '<S3>'   : 'DesignCurveCalcFun/DesignCurveCalc/ReactorAss'
 * '<S4>'   : 'DesignCurveCalcFun/DesignCurveCalc/ReactorAss/SelectDesignCurve'
 * '<S5>'   : 'DesignCurveCalcFun/DesignCurveCalc/ReactorAss/SelectDesignCurve/comfort'
 * '<S6>'   : 'DesignCurveCalcFun/DesignCurveCalc/ReactorAss/SelectDesignCurve/default'
 * '<S7>'   : 'DesignCurveCalcFun/DesignCurveCalc/ReactorAss/SelectDesignCurve/sport'
 * '<S8>'   : 'DesignCurveCalcFun/Simulink Function/DesignCurve'
 */

/*-
 * Requirements for '<Root>': DesignCurveCalcFun
 */
#endif                                 /* RTW_HEADER_DesignCurveCalcFun_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
