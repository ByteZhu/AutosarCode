/*
 * File: DTC_CANCheck_private.h
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

#ifndef RTW_HEADER_DTC_CANCheck_private_h_
#define RTW_HEADER_DTC_CANCheck_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "DTC_CANCheck_types.h"
#include "DTC_CANCheck.h"

/* Includes for objects with custom storage classes. */
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
extern void DTC_CANCheck_CANCheckLost(CANBUS rtu_bussignal, DTC rtu_dtcindex,
  UInt16 rtu_losttime, UInt16 rtu_rectime, Bool *rtuy_can_lost_flag);
extern void DTC_CANCheck_CANCheckInvalid(CANBUS rtu_bussignal, DTC rtu_dtcindex,
  UInt16 rtu_checktime, UInt16 *rtuy_vsl_cnt);
extern void DTC_CANCheck_CANCheckCrc(CANBUS rtu_bussignal, DTC rtu_dtcindex,
  UInt16 rtu_checktime, UInt16 *rtuy_vsl_crc_cnt);
extern void DTC_CANCheck_CANCheckCounter(CANBUS rtu_bussignal, DTC rtu_dtcindex,
  UInt16 rtu_checktime, UInt16 *rtuy_vsl_counter_cnt);
  
#endif                                 /* RTW_HEADER_DTC_CANCheck_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
