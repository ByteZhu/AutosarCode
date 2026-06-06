/*
 * File: FaultDiagRapid_MCU.h
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

#ifndef RTW_HEADER_FaultDiagRapid_MCU_h_
#define RTW_HEADER_FaultDiagRapid_MCU_h_
#ifndef FaultDiagRapid_COMMON_INCLUDES_
# define FaultDiagRapid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultDiagRapid_COMMON_INCLUDES_ */

#include "FaultDiagRapid_types.h"

/* Block signals and states (default storage) for system '<S91>/CoreCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MCUCORE == 0

typedef struct {
  struct {
    UInt32 is_c30_FaultDiagRapid:2;    /* '<S92>/MCUCoreDiag' */
    UInt32 is_Diag:2;                  /* '<S92>/MCUCoreDiag' */
    UInt32 is_active_c30_FaultDiagRapid:1;/* '<S92>/MCUCoreDiag' */
  } bitsForTID0;

  UInt16 IV_TimeWin;                   /* '<S92>/MCUCoreDiag' */
} FaultDiagRapid_DW_CoreCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S98>/EPSControlCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MCUEPSCONTROL == 0

typedef struct {
  struct {
    UInt32 is_active_c43_FaultDiagRapid:1;/* '<S99>/EPSCtrlCheck' */
  } bitsForTID0;

  UInt16 outter_asscnt;                /* '<S99>/EPSCtrlCheck' */
  UInt16 outter_trqcnt;                /* '<S99>/EPSCtrlCheck' */
  UInt16 outter_tgtcnt;                /* '<S99>/EPSCtrlCheck' */
  UInt16 outter_lmtcnt;                /* '<S99>/EPSCtrlCheck' */
  UInt16 outter_frccnt;                /* '<S99>/EPSCtrlCheck' */
  UInt16 outter_dmpcnt;                /* '<S99>/EPSCtrlCheck' */
  UInt16 outter_inacnt;                /* '<S99>/EPSCtrlCheck' */
  UInt16 outter_rtncnt;                /* '<S99>/EPSCtrlCheck' */
} FaultDiagRap_DW_EPSControlCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S103>/MotorControlCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MCUMOTORCONTROL == 0

typedef struct {
  Int32 inner_currentdiff;             /* '<S104>/MotorCtrlCheck' */
  Int32 inner_currentdiff2;            /* '<S104>/MotorCtrlCheck' */
  Int32 inner_foc_ulimit;              /* '<S104>/MotorCtrlCheck' */
  Int32 inner_foc_ud;                  /* '<S104>/MotorCtrlCheck' */
  Int32 inner_foc_uq;                  /* '<S104>/MotorCtrlCheck' */
  Int32 inner_foc_ud2;                 /* '<S104>/MotorCtrlCheck' */
  Int32 inner_foc_uq2;                 /* '<S104>/MotorCtrlCheck' */
  Int32 inner_voltagediff;             /* '<S104>/MotorCtrlCheck' */
  Int32 inner_voltagediff2;            /* '<S104>/MotorCtrlCheck' */
  struct {
    UInt32 is_active_c2_FaultDiagRapid:1;/* '<S104>/MotorCtrlCheck' */
  } bitsForTID0;

  UInt16 inner_angcnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_acccnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_revcnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_capcnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_capcnt2;                /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_wkfcnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_brgcnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_hmncnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_pwmcnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_pidcnt;                 /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_pidcnt2;                /* '<S104>/MotorCtrlCheck' */
  UInt16 inner_outcnt;                 /* '<S104>/MotorCtrlCheck' */
} FaultDiagR_DW_MotorControlCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S108>/ViceCommCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MCUVICECOMM == 0

typedef struct {
  struct {
    UInt32 is_active_c45_FaultDiagRapid:1;/* '<S109>/MCUViceCommDiag' */
  } bitsForTID0;

  UInt16 mcu_vct_rcvcnt;               /* '<S109>/MCUViceCommDiag' */
  UInt16 mcu_vct_errcnt;               /* '<S109>/MCUViceCommDiag' */
} FaultDiagRapid_DW_ViceCommCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

extern void FaultDiagRa_MCUCheck_Core_Reset(void);
extern void FaultDiagRapid_MCUCheck_Core(void);
extern void Fault_MCUCheck_EPSControl_Reset(void);
extern void FaultDiagRa_MCUCheck_EPSControl(void);
extern void Fau_MCUCheck_MotorControl_Reset(void);
extern void FaultDiag_MCUCheck_MotorControl(void);
extern void FaultDi_MCUCheck_ViceComm_Reset(void);
extern void FaultDiagRapi_MCUCheck_ViceComm(void);
extern void FaultD_DiagRapid_MCUCheck_Reset(void);
extern void FaultDiagRap_DiagRapid_MCUCheck(void);

#endif                                 /* RTW_HEADER_FaultDiagRapid_MCU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
