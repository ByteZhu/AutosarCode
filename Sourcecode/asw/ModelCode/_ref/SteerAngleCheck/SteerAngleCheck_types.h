/*
 * File: SteerAngleCheck_types.h
 *
 * Code generated for Simulink model 'SteerAngleCheck'.
 *
 * Model version                  : 1.1125
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:35:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SteerAngleCheck_types_h_
#define RTW_HEADER_SteerAngleCheck_types_h_
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"

/*
 * Registered constraints for dimension variants
 */
/* Constraint 'EPS_DTC_NUM_MAX == 96' registered by:
 * '<S13>/Data Store Read'
 * '<S14>/Data Store Read'
 * '<S16>/Data Store Read'
 * '<S17>/Data Store Read'
 * '<S22>/Data Store Read'
 * '<S23>/Data Store Read'
 */
#if EPS_DTC_NUM_MAX != 104
# error "The preprocessor definition 'EPS_DTC_NUM_MAX' must be equal to '104'"
#endif

/* Model Code Variants */

/* Exactly one variant for '<Root>/DiagSLow_AngleRotorCheck' should be active */
#if ((DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0) ? 1 : 0) + ((DIAGDIS_ANGLEROTORCHECK == 1 && STRANG_RTRANG_DIFF_TYPEMODE == 1) ? 1 : 0) + ((DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1) ? 1 : 0) != 1
#error Exactly one variant for '<Root>/DiagSLow_AngleRotorCheck' should be active
#endif

/* Exactly one variant for '<Root>/DiagSlow_AngleValCheck' should be active */
#if ((DIAGDIS_ANGLEVALCHECK == 0) ? 1 : 0) + ((DIAGDIS_ANGLEVALCHECK == 1) ? 1 : 0) != 1
#error Exactly one variant for '<Root>/DiagSlow_AngleValCheck' should be active
#endif
#endif                                 /* RTW_HEADER_SteerAngleCheck_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
