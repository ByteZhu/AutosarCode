/*
 * File: NewCode.h
 *
 * Code generated for Simulink model 'AssistControl'.
 *
 * Model version                  : 1.1306
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:05:55 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NewCode_h_
#define RTW_HEADER_NewCode_h_
#ifndef AssistControl_COMMON_INCLUDES_
# define AssistControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AssistControl_COMMON_INCLUDES_ */

#include "AssistControl_types.h"

extern void AssistC_BasicAsist_OnCenterKick(void);
extern void Assi_BasicAsist_RobustfilterFun(void);
extern void Assis_BasicAsist_TorqueSoftAdv2(void);
extern void As_BasicAsist_ToruqeNotchFilter(void);

#endif                                 /* RTW_HEADER_NewCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
