/*
 * File: GlobalVar.c
 *
 * Code generated for Simulink model 'EPSADC'.
 *
 * Model version                  : 1.1180
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:56:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "EPSADC_types.h"

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Global */
#if MACRO_STEERANGLE_SELECT == 0

volatile Int16 Fv_AngleDecodeP;

#endif

#if MACRO_STEERANGLE_SELECT == 0

volatile Int32 Fv_StrAng_Psum;

#endif

volatile Int16 Fv_StrTrq_Primed;

#if MACRO_STEERANGLE_SELECT == 0

volatile Int16 Tv_HellaFirlterRev;

#endif

#if MACRO_STEERANGLE_SELECT == 0

volatile Int16 Tv_StrAng;

#endif

volatile Int16 Tv_StrTrq0Orig;
volatile Int16 Tv_StrTrqP2dot5;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
