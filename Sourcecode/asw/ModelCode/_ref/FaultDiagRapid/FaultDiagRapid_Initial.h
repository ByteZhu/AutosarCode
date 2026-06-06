/*
 * File: FaultDiagRapid_Initial.h
 *
 * Code generated for Simulink model 'FaultDiagRapid'.
 *
 * Model version                  : 1.1273
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 14:58:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FaultDiagRapid_Initial_h_
#define RTW_HEADER_FaultDiagRapid_Initial_h_
#ifndef FaultDiagRapid_COMMON_INCLUDES_
# define FaultDiagRapid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultDiagRapid_COMMON_INCLUDES_ */

#include "FaultDiagRapid_types.h"

/* Block signals and states (default storage) for system '<S19>/ShortOpenInitCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MOTORSHORTOPENINIT == 0

typedef struct {
  struct {
    UInt32 is_c15_FaultDiagRapid:2;    /* '<S20>/MotorShortOpenInitDiag2' */
    UInt32 is_c4_FaultDiagRapid:2;     /* '<S20>/MotorShortOpenInitDiag1' */
    UInt32 is_active_c15_FaultDiagRapid:1;/* '<S20>/MotorShortOpenInitDiag2' */
    UInt32 is_active_c4_FaultDiagRapid:1;/* '<S20>/MotorShortOpenInitDiag1' */
    UInt32 stopflag:1;                 /* '<S20>/MotorShortOpenInitDiag2' */
    UInt32 stopflag_e53e:1;            /* '<S20>/MotorShortOpenInitDiag1' */
  } bitsForTID0;

  UInt16 read_fault;                   /* '<S20>/MotorShortOpenInitDiag2' */
  UInt16 read_timeout;                 /* '<S20>/MotorShortOpenInitDiag2' */
  UInt16 read_fault_krxe;              /* '<S20>/MotorShortOpenInitDiag1' */
  UInt16 read_timeout_owd2;            /* '<S20>/MotorShortOpenInitDiag1' */
  UInt8 diag_times;                    /* '<S20>/MotorShortOpenInitDiag2' */
  UInt8 diag_times_ofml;               /* '<S20>/MotorShortOpenInitDiag1' */
} FaultDiag_DW_ShortOpenInitCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#if DIAGDIS_MOTORSHORTOPENINIT == 0

extern void F_MotorShortOpenInitDiag1_Reset(void);

#endif

#if DIAGDIS_MOTORSHORTOPENINIT == 0

extern void FaultDi_MotorShortOpenInitDiag1(void);

#endif

#if DIAGDIS_MOTORSHORTOPENINIT == 0

extern void F_MotorShortOpenInitDiag2_Reset(void);

#endif

#if DIAGDIS_MOTORSHORTOPENINIT == 0

extern void FaultDi_MotorShortOpenInitDiag2(void);

#endif

extern void MotorInitialCheck_ShortOp_Reset(void);
extern void Fau_MotorInitialCheck_ShortOpen(void);
extern void FaultDiagR_DiagInit_Step0_Reset(void);
extern void FaultDiagRapid_DiagInit_Step0(void);

#endif                                /* RTW_HEADER_FaultDiagRapid_Initial_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
