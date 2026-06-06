/*
 * File: LoadCloseloop_private.h
 *
 * Code generated for Simulink model 'LoadCloseloop'.
 *
 * Model version                  : 1.1161
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Oct 25 17:06:37 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LoadCloseloop_private_h_
#define RTW_HEADER_LoadCloseloop_private_h_
#include "rtwtypes.h"
#include "LoadCloseloop_types.h"
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

#if MACRO_LOADCLOSELOOP_SELECT == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S7>/TCL_revKI'
   *   '<S7>/TCL_revKP'
   */
  UInt32 pooled7[2];

#define LOADCLOSELOOP_CONSTP_VARIANT_EXISTS
#endif

#if (MACRO_LOADCLOSELOOP_SELECT == 1) || (MACRO_LOADCLOSELOOP_SELECT == 0)

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/StrTrqLoad1'
   *   '<S8>/StrTrqLoad2'
   *   '<S8>/StrTrqLoad3'
   *   '<S8>/StrTrqLoad4'
   *   '<S26>/StrTrqLoad1'
   *   '<S26>/StrTrqLoad2'
   *   '<S26>/StrTrqLoad3'
   *   '<S26>/StrTrqLoad4'
   */
  UInt32 pooled9[2];

#define LOADCLOSELOOP_CONSTP_VARIANT_EXISTS
#endif

#ifndef LOADCLOSELOOP_CONSTP_VARIANT_EXISTS

  char _rt_unused;

#endif

} LoadCloseloop_ConstP;

/* Constant parameters (default storage) */
extern const LoadCloseloop_ConstP LoadCloselooprtConstP;

#endif                                 /* RTW_HEADER_LoadCloseloop_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
