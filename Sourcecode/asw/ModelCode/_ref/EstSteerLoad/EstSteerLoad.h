/*
 * File: EstSteerLoad.h
 *
 * Code generated for Simulink model 'EstSteerLoad'.
 *
 * Model version                  : 1.1145
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:57:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EstSteerLoad_h_
#define RTW_HEADER_EstSteerLoad_h_
#ifndef EstSteerLoad_COMMON_INCLUDES_
# define EstSteerLoad_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* EstSteerLoad_COMMON_INCLUDES_ */

#include "EstSteerLoad_types.h"

/* Includes for objects with custom storage classes. */
#include "CalVar.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for model 'EstSteerLoad' */
#ifndef EstSteerLoad_MDLREF_HIDE_CHILD_

typedef struct {
  Float64 y1[4];                       /* '<S3>/filter1_trw' */
  Float64 y2[6];                       /* '<S3>/filter1_trw' */
  Float64 y[6];                        /* '<S1>/filter_pfilter' */
  Float64 notchfilter_states[2];       /* '<S4>/notchfilter' */
  Float64 notchfilter_denStates[2];    /* '<S4>/notchfilter' */
  Float64 notchfilter_states_iusy[2];  /* '<S2>/notchfilter' */
  Float64 notchfilter_denStates_cvjq[2];/* '<S2>/notchfilter' */
  Float64 steerload;                   /* '<S2>/Add' */
  Float64 Saturation1;                 /* '<S4>/Saturation1' */
  Float64 notchfilter1_states;         /* '<S4>/notchfilter1' */
  Float64 notchfilter1_denStates;      /* '<S4>/notchfilter1' */
  Float64 notchfilter1_tmp;            /* '<S4>/notchfilter1' */
  Float64 notchfilter_tmp;             /* '<S4>/notchfilter' */
  Float64 notchfilter_tmp_kyyu;        /* '<S2>/notchfilter' */
} EstSteerLoad_DW_fwu4;

#endif                                 /*EstSteerLoad_MDLREF_HIDE_CHILD_*/

extern void EstSteerLoad_Init(void);
extern void EstSteerLoad(void);

extern void EstSteerLoad_1ms(void);
extern void EstSteerLoad_100us(void);
#ifndef EstSteerLoad_MDLREF_HIDE_CHILD_

extern void EstSteerLoad_filter_pfilter(Float64 rtu_f, Float64 rtu_c, Float64
  rty_y[6]);
extern void EstSteerLo_EstSteerLoad_FirCoef(void);
extern void EstStee_EstSteerLoad_P2Fir_Init(void);
extern void EstSteerLoad_EstSteerLoad_P2Fir(void);
extern void EstSteer_EstSteerLoad_SetTrwPar(void);
extern void EstSte_EstSteerLoad_TrwFir_Init(void);
extern void EstSteerLoa_EstSteerLoad_TrwFir(void);

#endif                                 /*EstSteerLoad_MDLREF_HIDE_CHILD_*/

#ifndef EstSteerLoad_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern EstSteerLoad_DW_fwu4 EstSteerLoadrtDW;

#endif                                 /*EstSteerLoad_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'EstSteerLoad'
 * '<S1>'   : 'EstSteerLoad/EstSteerLoad_FirCoef'
 * '<S2>'   : 'EstSteerLoad/EstSteerLoad_P2Fir'
 * '<S3>'   : 'EstSteerLoad/EstSteerLoad_SetTrwPar'
 * '<S4>'   : 'EstSteerLoad/EstSteerLoad_TrwFir'
 * '<S5>'   : 'EstSteerLoad/EstSteerLoad_FirCoef/filter_pfilter'
 * '<S6>'   : 'EstSteerLoad/EstSteerLoad_SetTrwPar/filter1_trw'
 */

/*-
 * Requirements for '<Root>': EstSteerLoad
 */
#endif                                 /* RTW_HEADER_EstSteerLoad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
