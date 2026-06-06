/*
 * File: SimDiagEnumSupport.h
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Sep 11 14:57:30 2023
 */

#ifndef RTW_HEADER_SimDiagEnumSupport_h_
#define RTW_HEADER_SimDiagEnumSupport_h_
#include "rtwtypes.h"

typedef enum {
  APA_REQ_STS_NoRequest = 0,           /* Default value */
  APA_REQ_STS_Request
} APA_REQ_STS;

typedef enum {
  APA_MAIN_STS_Invalid = 0,            /* Default value */
  APA_MAIN_STS_Serching,
  APA_MAIN_STS_GuidanceActive,
  APA_MAIN_STS_GuidanceSuspend,
  APA_MAIN_STS_GuidanceTerminated,
  APA_MAIN_STS_GuidanceCompleted,
  APA_MAIN_STS_Failure,
  APA_MAIN_STS_ParkAssistStandby
} APA_MAIN_STS;

typedef struct {
  Bool vsinvalid;
  Bool over_anglespeed2;
  Bool angle_diff_over;
  Bool override_flag2;
  Bool hanshake_err2;
  Bool override_flag;
  Bool vsrange;
  Bool angle_diff_err;
  Bool over_anglespeed;
  Bool tempoverflag;
  Bool eps_temporary_err;
  Bool other_err;
  Bool hanshake_err;
  Bool apa_failure;
  Bool angle_cmd_over;
  Bool eps_permanent;
  Bool apainvalid;
  Bool tas_err;
  Bool cmd_slope_over;
} tagAPA_Interrupt_Info;

typedef enum {
  DST_REQ_STS_Inhibited = 0,           /* Default value */
  DST_REQ_STS_Active
} DST_REQ_STS;

typedef enum {
  LDW_WARN_STS_no_display = 0,         /* Default value */
  LDW_WARN_STS_line_tracking,
  LDW_WARN_STS_intervention,
  LDW_WARN_STS_warning
} LDW_WARN_STS;

typedef enum {
  LDW_WARN_STYLE_only_vibration = 0,   /* Default value */
  LDW_WARN_STYLE_only_voice,
  LDW_WARN_STYLE_vibration_voice
} LDW_WARN_STYLE;

typedef enum {
  LKA_REQ_STS_Inhibited = 0,           /* Default value */
  LKA_REQ_STS_Ready,
  LKA_REQ_STS_Active
} LKA_REQ_STS;

typedef struct {
  Bool angle_diff_over;
  Bool handoff_flag;
  Bool override_flag;
  Bool vsinvalid;
  Bool hanshake_err;
  Bool lkainvalid;
  Bool eps_temporary_err;
  Bool grid_invalid;
  Bool range_invalid;
  Bool tempoverflag;
  Bool eps_permanent;
  Bool apa_itrp;
  Bool vsrange;
} tagLKA_Interrupt_Info;

typedef enum {
  VOT_REQ_STS_Request = 0,             /* Default value */
  VOT_REQ_STS_NoRequest
} VOT_REQ_STS;

typedef enum {
  VOT_ACTV_STS_NoActivate = 0,         /* Default value */
  VOT_ACTV_STS_Activate
} VOT_ACTV_STS;

typedef struct {
  Bool vot_anglediff_over;
  Bool eps_wheelspd_over2;
  Bool driver_interrupt2;
  Bool hanshake_err2;
  Bool driver_interrupt;
  Bool vs_range_over;
  Bool eps_wheelspd_over;
  Bool eps_wheelang_over;
  Bool tempoverflag;
  Bool eps_temporary_err;
  Bool vot_anglecmd_over;
  Bool hanshake_err;
  Bool tas_angle_err;
  Bool vot_angleslope_over;
  Bool eps_permanent_err;
  Bool vot_signal_err;
  Bool vs_signal_err;
  Bool others_err;
} tagVOT_Interrupt_Info;

#endif                                 /* RTW_HEADER_SimDiagEnumSupport_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
