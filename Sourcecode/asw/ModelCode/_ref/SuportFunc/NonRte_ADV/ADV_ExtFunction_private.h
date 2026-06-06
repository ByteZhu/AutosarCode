/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_ExtFunction_private.h
 *
 * Code generated for Simulink model 'ADV_ExtFunction'.
 *
 * Model version                  : 9.98
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 25 08:42:28 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADV_ExtFunction_private_h_
#define RTW_HEADER_ADV_ExtFunction_private_h_
#include "rtwtypes.h"
#include "ADV_ExtFunction_types.h"
#include "ADV_ExtFunction.h"
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
extern const uint32 rtCP_pooled_ctK6ygfIzFli[2];
extern const uint32 rtCP_pooled_Wnrvi205ZYcK[2];
extern const uint32 rtCP_pooled_hle4hBMqSjBY[2];
extern const uint32 rtCP_pooled_RQOB40sEfD7C[2];

#define rtCP_apalooktab_kp_maxIndex    rtCP_pooled_ctK6ygfIzFli  /* Computed Parameter: rtCP_apalooktab_kp_maxIndex
                                                                  * Referenced by: '<S40>/apalooktab_kp'
                                                                  */
#define rtCP_apalooktab_ki_maxIndex    rtCP_pooled_ctK6ygfIzFli  /* Computed Parameter: rtCP_apalooktab_ki_maxIndex
                                                                  * Referenced by: '<S40>/apalooktab_ki'
                                                                  */
#define rtCP_dsr_override_maxIndex     rtCP_pooled_Wnrvi205ZYcK  /* Computed Parameter: rtCP_dsr_override_maxIndex
                                                                  * Referenced by: '<S69>/dsr_override'
                                                                  */
#define rtCP_lka_cmdcoef2_maxIndex     rtCP_pooled_hle4hBMqSjBY  /* Computed Parameter: rtCP_lka_cmdcoef2_maxIndex
                                                                  * Referenced by: '<S101>/lka_cmdcoef2'
                                                                  */
#define rtCP_AimSpeedt_maxIndex        rtCP_pooled_hle4hBMqSjBY  /* Computed Parameter: rtCP_AimSpeedt_maxIndex
                                                                  * Referenced by: '<S102>/AimSpeedt'
                                                                  */
#define rtCP_gradcoef_maxIndex         rtCP_pooled_RQOB40sEfD7C  /* Computed Parameter: rtCP_gradcoef_maxIndex
                                                                  * Referenced by: '<S102>/gradcoef'
                                                                  */
#define rtCP_dsr_dampcomp_maxIndex     rtCP_pooled_hle4hBMqSjBY  /* Computed Parameter: rtCP_dsr_dampcomp_maxIndex
                                                                  * Referenced by: '<S103>/dsr_dampcomp'
                                                                  */
#define rtCP_dsr_dampang_coef_maxIndex rtCP_pooled_hle4hBMqSjBY  /* Computed Parameter: rtCP_dsr_dampang_coef_maxIndex
                                                                  * Referenced by: '<S103>/dsr_dampang_coef'
                                                                  */
#define rtCP_handsoff_step_maxIndex    rtCP_pooled_RQOB40sEfD7C  /* Computed Parameter: rtCP_handsoff_step_maxIndex
                                                                  * Referenced by: '<S4>/handsoff_step'
                                                                  */
#define rtCP_lka_override_maxIndex     rtCP_pooled_Wnrvi205ZYcK  /* Computed Parameter: rtCP_lka_override_maxIndex
                                                                  * Referenced by: '<S142>/lka_override'
                                                                  */
#define rtCP_lkalooktab_kp_maxIndex    rtCP_pooled_ctK6ygfIzFli  /* Computed Parameter: rtCP_lkalooktab_kp_maxIndex
                                                                  * Referenced by: '<S175>/lkalooktab_kp'
                                                                  */
#define rtCP_lkalooktab_ki_maxIndex    rtCP_pooled_ctK6ygfIzFli  /* Computed Parameter: rtCP_lkalooktab_ki_maxIndex
                                                                  * Referenced by: '<S175>/lkalooktab_ki'
                                                                  */

extern void btfilterllslp(float64 u, float64 y[4]);

#endif                               /* RTW_HEADER_ADV_ExtFunction_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
