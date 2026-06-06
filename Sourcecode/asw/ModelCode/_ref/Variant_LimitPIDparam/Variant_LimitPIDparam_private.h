/*
 * File: Variant_LimitPIDparam_private.h
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

#ifndef RTW_HEADER_Variant_LimitPIDparam_private_h_
#define RTW_HEADER_Variant_LimitPIDparam_private_h_
#include "rtwtypes.h"
#include "Variant_LimitPIDparam_types.h"
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

/* Constant parameters (default storage) */
typedef struct {

#if (MACRO_VARIANT_PID_SELECT == 1) || (MACRO_VARIANT_PID_SELECT == 0)

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S3>/PidKiTab'
   *   '<S3>/PidKpTab'
   *   '<S5>/BackwardCurentTab'
   *   '<S5>/BackwardCurentTab1'
   *   '<S5>/NormalRevKITab'
   *   '<S5>/NormalRevKPTab'
   */
  UInt32 pooled2[2];

#define VARIANT_LIMITPIDPARAM_CONSTP_VARIANT_EXISTS
#endif

#ifndef VARIANT_LIMITPIDPARAM_CONSTP_VARIANT_EXISTS

  char _rt_unused;

#endif

} Variant_LimitPIDparam_ConstP;

/* Constant parameters (default storage) */
extern const Variant_LimitPIDparam_ConstP Variant_LimitPIDparamrtConstP;

#endif                         /* RTW_HEADER_Variant_LimitPIDparam_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
