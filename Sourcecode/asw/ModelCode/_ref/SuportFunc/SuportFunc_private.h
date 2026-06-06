/*
 * File: SuportFunc_private.h
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Sep 27 15:37:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SuportFunc_private_h_
#define RTW_HEADER_SuportFunc_private_h_
#include "rtwtypes.h"
#include "SuportFunc_types.h"
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
#if MACRO_APA_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled28[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif    
#if MACRO_APA_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled27[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif  
#if MACRO_APA_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled26[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif
#if MACRO_APA_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled25[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif


#if MACRO_LKAAC_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled24[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif   
#if MACRO_LKAAC_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled23[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif    
#if MACRO_LKAAC_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled22[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif  
#if MACRO_LKAAC_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled21[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif
#if MACRO_LKAAC_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled20[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif

#if MACRO_LKAAC_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S163>/LowerLimit'
   *   '<S163>/UpperLimit'
   */
  UInt32 pooled19[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif

#if MACRO_LKA_FUNCTION_ENABLE == 1

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S290>/lka_cmdcoef2'
   *   '<S291>/AimCurrent'
   *   '<S292>/lka_dampang_coef'
   *   '<S292>/lka_dampcomp'
   */
  UInt32 pooled17[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif

#if MACRO_LKA_FUNCTION_ENABLE == 1

  /* Computed Parameter: gradcoef_maxIndex
   * Referenced by: '<S291>/gradcoef'
   */
  UInt32 gradcoef_maxIndex[2];

#define SUPORTFUNC_CONSTP_VARIANT_EXISTS
#endif

#ifndef SUPORTFUNC_CONSTP_VARIANT_EXISTS

  char _rt_unused;

#endif

} SuportFunc_ConstP;

/* Constant parameters (default storage) */
extern const SuportFunc_ConstP SuportFuncrtConstP;

#endif                                 /* RTW_HEADER_SuportFunc_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
