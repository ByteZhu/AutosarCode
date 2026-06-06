/*
 * File: eps_controlAlgorithm_private.h
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:08:34 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_eps_controlAlgorithm_private_h_
#define RTW_HEADER_eps_controlAlgorithm_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "eps_controlAlgorithm.h"

/* Includes for objects with custom storage classes. */
#include "GlobalVar.h"
#include "Common.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef DTCErrDebounceTmrCntCnstr
#error The variable for the parameter "DTCErrDebounceTmrCntCnstr" is not defined
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Imported (extern) block parameters */
extern Int16 Cal_BT_BasicAsisTabGen_X[57];/* Variable: Cal_BT_BasicAsisTabGen_X
                                           * Referenced by: '<S15>/FUN_AssistControl'
                                           */
extern Int16 Cal_BT_BasicAsisTabGen_Z[570];/* Variable: Cal_BT_BasicAsisTabGen_Z
                                            * Referenced by: '<S15>/FUN_AssistControl'
                                            */
extern UInt16 Cal_BT_BasicAsisTabGen_Y[10];/* Variable: Cal_BT_BasicAsisTabGen_Y
                                            * Referenced by: '<S15>/FUN_AssistControl'
                                            */
extern void task_100us_Init(void);
extern void task_100us(void);
extern void task_1ms_Init(void);
extern void task_1ms_Start(void);
extern void task_1ms(const INFO_EXTSENSOR *rtu_sensor, const INFO_INNERSAMPLE
                     *rtu_sample);
extern void task_10_0ms(const INFO_INNERSAMPLE *rtu_sample);
extern void task_10_5ms(const INFO_INNERSAMPLE *rtu_sample);
extern void task_20_0ms_Init(void);
extern void task_20_0ms(void);
extern void task_100ms(const INFO_EXTSENSOR *rtu_sensor);
extern void Scheduler_Init(void);
extern void Scheduler_Start(void);
extern void Scheduler(void);

#endif                          /* RTW_HEADER_eps_controlAlgorithm_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
