/*
 * File: FaultDiagRapid_Torque.h
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

#ifndef RTW_HEADER_FaultDiagRapid_Torque_h_
#define RTW_HEADER_FaultDiagRapid_Torque_h_
#ifndef FaultDiagRapid_COMMON_INCLUDES_
# define FaultDiagRapid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultDiagRapid_COMMON_INCLUDES_ */

#include "FaultDiagRapid_types.h"

/* Block signals and states (default storage) for system '<S66>/PowerCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_TORQUEPOWERREG == 0

typedef struct {
  Float64 SFunction_o2;                /* '<S67>/TorquePowerDiag' */
  Float64 SFunction_o3;                /* '<S67>/TorquePowerDiag' */
  Float64 SFunction_o4;                /* '<S67>/TorquePowerDiag' */
  Float64 SFunction_o5;                /* '<S67>/TorquePowerDiag' */
  struct {
    UInt32 is_c34_FaultDiagRapid:2;    /* '<S67>/TorquePowerDiag' */
    UInt32 is_Diag:2;                  /* '<S67>/TorquePowerDiag' */
    UInt32 is_active_c34_FaultDiagRapid:1;/* '<S67>/TorquePowerDiag' */
  } bitsForTID0;

  UInt16 SV_TimeWin;                   /* '<S67>/TorquePowerDiag' */
  UInt16 SVj_TimeWin;                  /* '<S67>/TorquePowerDiag' */
} FaultDiagRapid_DW_PowerCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S73>/SignalCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_TORQUESIGNALREG == 0

typedef struct {
  struct {
    UInt32 is_c37_FaultDiagRapid:2;    /* '<S74>/TorqueSignalDiag' */
    UInt32 is_MainTorque:2;            /* '<S74>/TorqueSignalDiag' */
    UInt32 is_SumTorque:2;             /* '<S74>/TorqueSignalDiag' */
    UInt32 is_SubTorque:2;             /* '<S74>/TorqueSignalDiag' */
    UInt32 is_OffsetTorque:2;          /* '<S74>/TorqueSignalDiag' */
    UInt32 is_Diag:2;                  /* '<S74>/TorqueSignalDiag' */
    UInt32 is_active_c37_FaultDiagRapid:1;/* '<S74>/TorqueSignalDiag' */
  } bitsForTID0;

  UInt16 SUM_RECORD[8];                /* '<S74>/TorqueSignalDiag' */
  UInt16 SM_TimeWin;                   /* '<S74>/TorqueSignalDiag' */
  UInt16 SS_TimeWin;                   /* '<S74>/TorqueSignalDiag' */
  UInt16 SUM_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SMC_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SMR_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SSR_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SSC_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SOF_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SMj_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SSj_TimeWin;                  /* '<S74>/TorqueSignalDiag' */
  UInt16 SUMj_TimeWin;                 /* '<S74>/TorqueSignalDiag' */
  UInt16 SOFj_TimeWin;                 /* '<S74>/TorqueSignalDiag' */
} FaultDiagRapid_DW_SignalCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

extern void FaultDi_TorqueCheck_Power_Reset(void);
extern void FaultDiagRapi_TorqueCheck_Power(void);
extern void FaultD_TorqueCheck_Signal_Reset(void);
extern void FaultDiagRap_TorqueCheck_Signal(void);
extern void Fau_DiagRapid_TorqueCheck_Reset(void);
extern void FaultDiag_DiagRapid_TorqueCheck(void);

#endif                                 /* RTW_HEADER_FaultDiagRapid_Torque_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
