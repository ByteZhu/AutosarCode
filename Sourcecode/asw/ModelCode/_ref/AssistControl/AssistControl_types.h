/*
 * File: AssistControl_types.h
 *
 * Code generated for Simulink model 'AssistControl'.
 *
 * Model version                  : 1.1327
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Nov 23 17:17:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AssistControl_types_h_
#define RTW_HEADER_AssistControl_types_h_
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacroSupport.h"
#include "SimDiagMacro.h"

/* Model Code Variants */

/* Exactly one variant for '<S33>/Assist_Select' should be active */
#if ((ASSIST_EXTERN_LINESEG == 0) ? 1 : 0) + ((ASSIST_EXTERN_LINESEG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S33>/Assist_Select' should be active
#endif

/* Exactly one variant for '<S4>/CaclAim_MotorAngState' should be active */
#if ((CACLAIM_MOTORANG_POWERST == 0) ? 1 : 0) + ((CACLAIM_MOTORANG_POWERST == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CaclAim_MotorAngState' should be active
#endif

/* Exactly one variant for '<S6>/FrictionComp' should be active */
#if ((MACRO_FRICTION_COMP_SELECT == 0) ? 1 : 0) + ((MACRO_FRICTION_COMP_SELECT == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S6>/FrictionComp' should be active
#endif

/* Exactly one variant for '<S15>/SteeringEnd_DecZone' should be active */
#if ((STEEREND_ZONE_VARIABLE == 1) ? 1 : 0) + ((STEEREND_ZONE_VARIABLE == 0) ? 1 : 0) != 1
#error Exactly one variant for '<S15>/SteeringEnd_DecZone' should be active
#endif
#endif                                 /* RTW_HEADER_AssistControl_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
