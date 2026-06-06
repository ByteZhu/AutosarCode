/*
 * File: Failsafe.h
 *
 * Code generated for Simulink model 'DTC_CANCheck'.
 *
 * Model version                  : 1.1204
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 21 17:56:45 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Failsafe_h_
#define RTW_HEADER_Failsafe_h_
#ifndef DTC_CANCheck_COMMON_INCLUDES_
# define DTC_CANCheck_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DTC_CANCheck_COMMON_INCLUDES_ */

#include "DTC_CANCheck_types.h"

extern void DTC_CANCh_DTC_Allow_Occur_Logic(void);
extern void DTC_C_DTC_Testfailed_Logic_Init(void);
extern void DTC_CANChe_DTC_Testfailed_Logic(void);
extern void DTC_CANCheck_DTCLogic_Init(void);
extern void DTC_CANCheck_DTCLogic(void);

#endif                                 /* RTW_HEADER_Failsafe_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
