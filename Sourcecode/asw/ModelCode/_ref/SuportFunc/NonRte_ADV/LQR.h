/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LQR.h
 *
 * Code generated for Simulink model 'LQR'.
 *
 * Model version                  : 251
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Sep 17 10:58:07 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LQR_h_
#define RTW_HEADER_LQR_h_
#include <math.h>
#ifndef LQR_COMMON_INCLUDES_
#define LQR_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LQR_COMMON_INCLUDES_ */


/* Includes for objects with custom storage classes. */
#include "CalVar.h"
#include "CalVarSupport.h"
#include "GlobalVar.h"
#include "GlobalVarSupport.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  Float64 P_gvra[4];                   /* '<S5>/Spd_KF' */
  Float64 x[2];                        /* '<S5>/Spd_KF' */
  Float64 AngLeadDelay1_DSTATE;        /* '<S9>/AngLeadDelay1' */
  Float64 AngLeadDelay_DSTATE;         /* '<S9>/AngLeadDelay' */
  Float64 SpdPdelay_DSTATE;            /* '<S18>/SpdPdelay' */
  Float64 PIDelay_DSTATE;              /* '<S8>/PIDelay' */
  Float64 FCdelay_DSTATE;              /* '<S21>/FCdelay' */
  Float64 SpdLeadDelay_DSTATE;         /* '<S12>/SpdLeadDelay' */
  Float64 SpdLeadDelay1_DSTATE;        /* '<S12>/SpdLeadDelay1' */
  Float64 AngIn;                       /* '<S6>/RateLim' */
  Float64 Counter;                     /* '<S6>/RateLim' */
  Float64 cnt;                         /* '<S5>/Spd_KF' */
  UInt32 m_bpIndex[2];                 /* '<S19>/TorqueLim1' */
  UInt32 m_bpIndex_np4x[2];            /* '<S20>/TorqueLim1' */
  UInt32 m_bpIndex_kc2k;               /* '<S18>/SpdLoop_P' */
  UInt32 m_bpIndex_buu0;               /* '<S14>/FAA_FC' */
  UInt32 m_bpIndex_hutn;               /* '<S18>/SpdLoop_I' */
  UInt32 m_bpIndex_bx11;               /* '<S16>/FAA_FC' */
  UInt32 m_bpIndex_aj1t;               /* '<S16>/FAA_FC1' */
  UInt32 m_bpIndex_bx12;               /* '<S16>/FAA_al_p' */
  UInt32 m_bpIndex_bx13;               /* '<S16>/FAA_leadgain' */
  Bool icLoad;                         /* '<S9>/AngLeadDelay1' */
  Bool icLoad_gq03;                    /* '<S9>/AngLeadDelay' */
  Bool icLoad_fd53;                    /* '<S18>/SpdPdelay' */
  Bool icLoad_dxex;                    /* '<S12>/SpdLeadDelay' */
  Bool icLoad_kxck;                    /* '<S12>/SpdLeadDelay1' */
  Bool Improved_PI_MODE;               /* '<S1>/Improved_PI' */
} DW_l5cf_Lqr;

/* Invariant block signals (default storage) */
typedef struct {
  const Float64 Bias;                  /* '<S12>/Bias' */
  const Float64 Bias1;                 /* '<S12>/Bias1' */
  const Float64 Bias2;                 /* '<S12>/Bias2' */
  const Float64 Bias4;                 /* '<S12>/Bias4' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S19>/TorqueLim1'
   *   '<S20>/TorqueLim1'
   */
  UInt32 pooled14[2];
} ConstP_dfsm_Lqr;

/* Block signals and states (default storage) */
extern DW_l5cf_Lqr rtDW_l5cf_Lqr;
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_dfsm_Lqr rtConstP_dfsm_Lqr;

/* Model entry point functions */
extern void LQR_initialize(void);
extern void LQR_step(void);

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
 * '<Root>' : 'LQR'
 * '<S1>'   : 'LQR/LQR'
 * '<S2>'   : 'LQR/LQR/Compare To Constant'
 * '<S3>'   : 'LQR/LQR/Improved_PI'
 * '<S4>'   : 'LQR/LQR/Improved_PI/ActAngLead'
 * '<S5>'   : 'LQR/LQR/Improved_PI/AimSpd'
 * '<S6>'   : 'LQR/LQR/Improved_PI/Aim_Ang_RateLimit'
 * '<S7>'   : 'LQR/LQR/Improved_PI/AngErr2Spd'
 * '<S8>'   : 'LQR/LQR/Improved_PI/Spd_Loop_PI'
 * '<S9>'   : 'LQR/LQR/Improved_PI/ActAngLead/Sensor_Adjust'
 * '<S10>'  : 'LQR/LQR/Improved_PI/AimSpd/Signal_Lead2'
 * '<S11>'  : 'LQR/LQR/Improved_PI/AimSpd/Spd_KF'
 * '<S12>'  : 'LQR/LQR/Improved_PI/AimSpd/Signal_Lead2/Sensor_Adjust'
 * '<S13>'  : 'LQR/LQR/Improved_PI/Aim_Ang_RateLimit/RateLim'
 * '<S14>'  : 'LQR/LQR/Improved_PI/AngErr2Spd/SpdLim'
 * '<S15>'  : 'LQR/LQR/Improved_PI/AngErr2Spd/SpdLim/Saturation Dynamic'
 * '<S16>'  : 'LQR/LQR/Improved_PI/Spd_Loop_PI/FrictionModel'
 * '<S17>'  : 'LQR/LQR/Improved_PI/Spd_Loop_PI/Saturation Dynamic'
 * '<S18>'  : 'LQR/LQR/Improved_PI/Spd_Loop_PI/SpdLoopPI'
 * '<S19>'  : 'LQR/LQR/Improved_PI/Spd_Loop_PI/UPLim'
 * '<S20>'  : 'LQR/LQR/Improved_PI/Spd_Loop_PI/downLim'
 * '<S21>'  : 'LQR/LQR/Improved_PI/Spd_Loop_PI/FrictionModel/LuGre'
 */

/*-
 * Requirements for '<Root>': LQR
 */
#endif                                 /* RTW_HEADER_LQR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
