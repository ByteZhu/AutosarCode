/*
 * File: SteerAngleCheck.h
 *
 * Code generated for Simulink model 'SteerAngleCheck'.
 *
 * Model version                  : 1.1122
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:02:02 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SteerAngleCheck_h_
#define RTW_HEADER_SteerAngleCheck_h_
#ifndef SteerAngleCheck_COMMON_INCLUDES_
# define SteerAngleCheck_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SteerAngleCheck_COMMON_INCLUDES_ */

#include "SteerAngleCheck_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "CalVar.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S1>/AngleRotorCheck' */
#ifndef SteerAngleCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0

typedef struct {
  Int32 hr_diff_fix;                   /* '<S3>/RotorCompareCheck' */
  Int32 hr_diff_avr;                   /* '<S3>/RotorCompareCheck' */
  struct {
    UInt32 is_c68_SteerAngleCheck:2;   /* '<S3>/RotorCompareCheck' */
    UInt32 is_Run:2;                   /* '<S3>/RotorCompareCheck' */
    UInt32 is_active_c68_SteerAngleCheck:1;/* '<S3>/RotorCompareCheck' */
    UInt32 jumpdiag_flag:1;            /* '<S3>/RotorCompareCheck' */
  } bitsForTID0;

  UInt16 rotor_delay_cnt;              /* '<S3>/RotorCompareCheck' */
  UInt16 rotor_record_cnt;             /* '<S3>/RotorCompareCheck' */
  UInt16 hr_err_cnt;                   /* '<S3>/RotorCompareCheck' */
} SteerAngleCh_DW_AngleRotorCheck;

#endif
#endif                                 /*SteerAngleCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S1>/AngleRotorCheckExn' */
#ifndef SteerAngleCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

typedef struct {
  UInt16 hr_err_cnt;                   /* '<S5>/RotorCompareCheckExn' */
} SteerAngl_DW_AngleRotorCheckExn;

#endif
#endif                                 /*SteerAngleCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S2>/AngleValCheck' */
#ifndef SteerAngleCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_ANGLEVALCHECK == 0

typedef struct {
  struct {
    UInt32 is_ValidCheck:2;            /* '<S18>/AngleValCheck' */
    UInt32 is_RealCheck:2;             /* '<S18>/AngleValCheck' */
    UInt32 is_Diag:2;                  /* '<S18>/AngleValCheck' */
    UInt32 is_active_c67_SteerAngleCheck:1;/* '<S18>/AngleValCheck' */
  } bitsForTID0;

  UInt16 AV_TimeWin;                   /* '<S18>/AngleValCheck' */
  UInt16 AR_TimeWin;                   /* '<S18>/AngleValCheck' */
  UInt16 ARj_TimeWin;                  /* '<S18>/AngleValCheck' */
} SteerAngleChec_DW_AngleValCheck;

#endif
#endif                                 /*SteerAngleCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'SteerAngleCheck' */
#ifndef SteerAngleCheck_MDLREF_HIDE_CHILD_

typedef struct {

#if DIAGDIS_ANGLEVALCHECK == 0

  SteerAngleChec_DW_AngleValCheck AngleValCheck;

#define STEERANGLECHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

  SteerAngl_DW_AngleRotorCheckExn AngleRotorCheckExn;

#define STEERANGLECHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0

  SteerAngleCh_DW_AngleRotorCheck AngleRotorCheck;

#define STEERANGLECHECK_DW_FWU4_VARIANT_EXISTS
#endif

#ifndef STEERANGLECHECK_DW_FWU4_VARIANT_EXISTS

  char _rt_unused;

#endif

} SteerAngleCheck_DW_fwu4;

#endif                                 /*SteerAngleCheck_MDLREF_HIDE_CHILD_*/

extern void SteerAngleCheck(void);

#ifndef SteerAngleCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0

extern void SteerAngleCheck_AngleRotorCheck(void);

#endif

#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

extern void SteerAngleCh_AngleRotorCheckExn(void);

#endif

#if DIAGDIS_ANGLEVALCHECK == 0

extern void SteerAngleCheck_AngleValCheck(void);

#endif
#endif                                 /*SteerAngleCheck_MDLREF_HIDE_CHILD_*/

#ifndef SteerAngleCheck_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern SteerAngleCheck_DW_fwu4 SteerAngleCheckrtDW;

#endif                                 /*SteerAngleCheck_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SteerAngleCheck'
 * '<S1>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck'
 * '<S2>'   : 'SteerAngleCheck/DiagSlow_AngleValCheck'
 * '<S3>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck'
 * '<S4>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheckDis'
 * '<S5>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheckExn'
 * '<S6>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/PreConditon'
 * '<S7>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/RotorCompareCheck'
 * '<S8>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/PreConditon/Compare To Constant'
 * '<S9>'   : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/PreConditon/Compare To Constant2'
 * '<S10>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/PreConditon/Compare To Constant3'
 * '<S11>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/PreConditon/Compare To Constant4'
 * '<S12>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/PreConditon/Compare To Zero'
 * '<S13>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/RotorCompareCheck/DTC_Ctrl_Enabled'
 * '<S14>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheck/RotorCompareCheck/getDTCEnabled'
 * '<S15>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheckExn/RotorCompareCheckExn'
 * '<S16>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheckExn/RotorCompareCheckExn/DTC_Ctrl_Enabled'
 * '<S17>'  : 'SteerAngleCheck/DiagSLow_AngleRotorCheck/AngleRotorCheckExn/RotorCompareCheckExn/getDTCEnabled'
 * '<S18>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck'
 * '<S19>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheckDis'
 * '<S20>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCheck'
 * '<S21>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCond'
 * '<S22>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCheck/DTC_Ctrl_Enabled'
 * '<S23>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCheck/getDTCEnabled'
 * '<S24>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCond/Compare To Constant1'
 * '<S25>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCond/Compare To Constant2'
 * '<S26>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCond/Compare To Constant3'
 * '<S27>'  : 'SteerAngleCheck/DiagSlow_AngleValCheck/AngleValCheck/AngleValCond/Compare To Constant4'
 */

/*-
 * Requirements for '<Root>': SteerAngleCheck
 */
#endif                                 /* RTW_HEADER_SteerAngleCheck_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
