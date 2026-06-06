/*
 * File: AssistControl_private.h
 *
 * Code generated for Simulink model 'AssistControl'.
 *
 * Model version                  : 1.1328
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Nov 24 15:02:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AssistControl_private_h_
#define RTW_HEADER_AssistControl_private_h_
#include "rtwtypes.h"
#include "AssistControl_types.h"

/* Includes for objects with custom storage classes. */
#include "GlobalVar.h"
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
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S19>/AimSpeedCM'
   *   '<S19>/AimSpeedLKA'
   *   '<S19>/AimSpeedSP'
   *   '<S19>/AimSpeedST'
   */
  UInt32 pooled10[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S21>/AimSpeedt'
   *   '<S22>/TrqCfReturn2'
   */
  UInt32 pooled11[2];

  /* Computed Parameter: DFFLimit_maxIndex
   * Referenced by: '<S31>/DFFLimit'
   */
  UInt32 DFFLimit_maxIndex[2];

  /* Computed Parameter: vst0_tab_maxIndex
   * Referenced by: '<S32>/vst0_tab'
   */
  UInt32 vst0_tab_maxIndex[2];

  /* Computed Parameter: vsw_tab_maxIndex
   * Referenced by: '<S32>/vsw_tab'
   */
  UInt32 vsw_tab_maxIndex[2];

#if (ASSIST_EXTERN_LINESEG == 0) || (ASSIST_EXTERN_LINESEG == 1)

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S43>/TorFrLimit1'
   *   '<S43>/TorFrLimit2'
   *   '<S43>/TorFrLimit3'
   *   '<S43>/TorFrLimit4'
   *   '<S44>/TorFrLimit'
   */
  UInt32 pooled12[2];

#define ASSISTCONTROL_CONSTP_VARIANT_EXISTS
#endif

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S113>/hs_trqtab1'
   *   '<S113>/hs_trqtab2'
   *   '<S113>/hs_trqtab3'
   *   '<S113>/hs_trqtab4'
   */
  UInt32 pooled13[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S116>/hs_trqtab1'
   *   '<S116>/hs_trqtab2'
   *   '<S116>/hs_trqtab3'
   *   '<S116>/hs_trqtab4'
   */
  UInt32 pooled14[2];

  /* Computed Parameter: TrqInetiaComp_maxIndex
   * Referenced by: '<S9>/TrqInetiaComp'
   */
  UInt32 TrqInetiaComp_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S158>/SteerAngEnd'
   *   '<S158>/SteerdAngEnd'
   */
  UInt32 pooled16[2];
} AssistControl_ConstP;

/* Imported (extern) block parameters */
#if ASSIST_EXTERN_LINESEG == 1

extern Int16 Cal_BT_BasicAsisTabGen_X[57];/* Variable: Cal_BT_BasicAsisTabGen_X
                                           * Referenced by: '<S44>/TorFrLimit'
                                           */

#endif

#if ASSIST_EXTERN_LINESEG == 1

extern Int16 Cal_BT_BasicAsisTabGen_Z[570];/* Variable: Cal_BT_BasicAsisTabGen_Z
                                            * Referenced by: '<S44>/TorFrLimit'
                                            */

#endif

#if ASSIST_EXTERN_LINESEG == 1

extern UInt16 Cal_BT_BasicAsisTabGen_Y[10];/* Variable: Cal_BT_BasicAsisTabGen_Y
                                            * Referenced by: '<S44>/TorFrLimit'
                                            */

#endif

/* Constant parameters (default storage) */
extern const AssistControl_ConstP AssistControlrtConstP;

#endif                                 /* RTW_HEADER_AssistControl_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
