/*
 * File: TemperatureCheck_types.h
 *
 * Code generated for Simulink model 'TemperatureCheck'.
 *
 * Model version                  : 1.1126
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:37:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TemperatureCheck_types_h_
#define RTW_HEADER_TemperatureCheck_types_h_
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"

/*
 * Registered constraints for dimension variants
 */
/* Constraint 'EPS_DTC_NUM_MAX == 96' registered by:
 * '<S14>/Data Store Read'
 * '<S19>/Data Store Read'
 */
#if EPS_DTC_NUM_MAX != 104
# error "The preprocessor definition 'EPS_DTC_NUM_MAX' must be equal to '104'"
#endif

/* Model Code Variants */

/* Exactly one variant for '<Root>/TemperatureCheck_Calc' should be active */
#if ((MACRO_TEMP_DP_ENABLE == 0) ? 1 : 0) + ((MACRO_TEMP_DP_ENABLE == 1) ? 1 : 0) != 1
#error Exactly one variant for '<Root>/TemperatureCheck_Calc' should be active
#endif

/* Exactly one variant for '<S2>/TempLevelCheck' should be active */
#if ((DIAGDIS_TEMPLEVEL == 0) ? 1 : 0) + ((DIAGDIS_TEMPLEVEL == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S2>/TempLevelCheck' should be active
#endif

/* Exactly one variant for '<S3>/TempVolCheck' should be active */
#if ((DIAGDIS_TEMPVOL == 0) ? 1 : 0) + ((DIAGDIS_TEMPVOL == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S3>/TempVolCheck' should be active
#endif
#endif                                /* RTW_HEADER_TemperatureCheck_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
