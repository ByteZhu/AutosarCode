/*
 * File: EPSADC_types.h
 *
 * Code generated for Simulink model 'EPSADC'.
 *
 * Model version                  : 1.1180
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:56:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EPSADC_types_h_
#define RTW_HEADER_EPSADC_types_h_
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"

/* Model Code Variants */

/* Exactly one variant for '<S1>/EpsAngleConv_Select' should be active */
#if ((MACRO_STEERANGLE_SELECT == 1) ? 1 : 0) + ((MACRO_STEERANGLE_SELECT == 0) ? 1 : 0) != 1
#error Exactly one variant for '<S1>/EpsAngleConv_Select' should be active
#endif

/* Exactly one variant for '<S20>/calc_anglecheck' should be active */
#if ((STRANG_RTRANG_DIFF_TYPEMODE == 1) ? 1 : 0) + ((STRANG_RTRANG_DIFF_TYPEMODE == 0) ? 1 : 0) != 1
#error Exactly one variant for '<S20>/calc_anglecheck' should be active
#endif
#endif                                 /* RTW_HEADER_EPSADC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
