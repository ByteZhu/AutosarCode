/*
 * File: FaultDiagRapid_Motor.h
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

#ifndef RTW_HEADER_FaultDiagRapid_Motor_h_
#define RTW_HEADER_FaultDiagRapid_Motor_h_
#include <string.h>
#ifndef FaultDiagRapid_COMMON_INCLUDES_
# define FaultDiagRapid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultDiagRapid_COMMON_INCLUDES_ */

#include "FaultDiagRapid_types.h"

/* Block signals and states (default storage) for system '<S118>/OutputCurrentCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

typedef struct {
  Int32 record_diff1[25];              /* '<S119>/OutputCurrentDiag2' */
  Int32 record_diff2[25];              /* '<S119>/OutputCurrentDiag2' */
  Int32 record_diff1_bnq3[25];         /* '<S119>/OutputCurrentDiag1' */
  Int32 record_diff2_muqi[25];         /* '<S119>/OutputCurrentDiag1' */
  Int32 max_qaxis2;                    /* '<S122>/MinMax' */
  Int32 qdiff2;                        /* '<S122>/Saturation1' */
  Int32 max_daxis2;                    /* '<S122>/MinMax1' */
  Int32 ddiff2;                        /* '<S122>/Saturation' */
  Int32 max_qaxis1;                    /* '<S121>/MinMax' */
  Int32 qdiff1;                        /* '<S121>/Saturation1' */
  Int32 max_daxis1;                    /* '<S121>/MinMax1' */
  Int32 ddiff1;                        /* '<S121>/Saturation' */
  struct {
    UInt32 is_c14_FaultDiagRapid:2;    /* '<S119>/OutputCurrentDiag2' */
    UInt32 is_Diag:2;                  /* '<S119>/OutputCurrentDiag2' */
    UInt32 is_c13_FaultDiagRapid:2;    /* '<S119>/OutputCurrentDiag1' */
    UInt32 is_Diag_cepr:2;             /* '<S119>/OutputCurrentDiag1' */
    UInt32 is_active_c14_FaultDiagRapid:1;/* '<S119>/OutputCurrentDiag2' */
    UInt32 is_active_c13_FaultDiagRapid:1;/* '<S119>/OutputCurrentDiag1' */
  } bitsForTID0;

  UInt16 MOO_TimeWin;                  /* '<S119>/OutputCurrentDiag2' */
  UInt16 MOO_TimeWin_iksw;             /* '<S119>/OutputCurrentDiag1' */
} FaultDiag_DW_OutputCurrentCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S129>/OverCurrentCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MOTOROVERCURRENTREG == 0

typedef struct {
  struct {
    UInt32 is_c12_FaultDiagRapid:2;    /* '<S130>/OverCurrentDiag2' */
    UInt32 is_Diag:2;                  /* '<S130>/OverCurrentDiag2' */
    UInt32 is_c11_FaultDiagRapid:2;    /* '<S130>/OverCurrentDiag1' */
    UInt32 is_Diag_g0ku:2;             /* '<S130>/OverCurrentDiag1' */
    UInt32 is_active_c12_FaultDiagRapid:1;/* '<S130>/OverCurrentDiag2' */
    UInt32 is_active_c11_FaultDiagRapid:1;/* '<S130>/OverCurrentDiag1' */
  } bitsForTID0;

  UInt16 MIA_TimeWin;                  /* '<S130>/OverCurrentDiag2' */
  UInt16 MIA_TimeWin_dhmt;             /* '<S130>/OverCurrentDiag1' */
  Bool overcurrent2;                   /* '<S133>/Logical Operator3' */
} FaultDiagRa_DW_OverCurrentCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S158>/PredriverCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_MOTORPREDRIVERREG == 0

typedef struct {
  struct {
    UInt32 is_c8_FaultDiagRapid:2;     /* '<S159>/PredriverDiag2' */
    UInt32 is_c3_FaultDiagRapid:2;     /* '<S159>/PredriverDiag1' */
    UInt32 is_active_c8_FaultDiagRapid:1;/* '<S159>/PredriverDiag2' */
    UInt32 is_active_c3_FaultDiagRapid:1;/* '<S159>/PredriverDiag1' */
  } bitsForTID0;

  UInt16 MP_TimeWin;                   /* '<S159>/PredriverDiag2' */
  UInt16 MP_TimeWin_c1ll;              /* '<S159>/PredriverDiag1' */
  Bool precondwait2;                   /* '<S162>/Logical Operator8' */
  Bool preconddiag2;                   /* '<S162>/Logical Operator7' */
} FaultDiagRapi_DW_PredriverCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

extern void FaultD_OutputCurrentDiag1_Reset(void);

#endif

#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

extern void FaultDiagRap_OutputCurrentDiag1(void);

#endif

#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

extern void FaultD_OutputCurrentDiag2_Reset(void);

#endif

#if DIAGDIS_MOTOROUTPUTCURRENTREG == 0

extern void FaultDiagRap_OutputCurrentDiag2(void);

#endif

#if DIAGDIS_MOTOROVERCURRENTREG == 0

extern void FaultDia_OverCurrentDiag1_Reset(void);

#endif

#if DIAGDIS_MOTOROVERCURRENTREG == 0

extern void FaultDiagRapid_OverCurrentDiag1(void);

#endif

#if DIAGDIS_MOTOROVERCURRENTREG == 0

extern void FaultDia_OverCurrentDiag2_Reset(void);

#endif

#if DIAGDIS_MOTOROVERCURRENTREG == 0

extern void FaultDiagRapid_OverCurrentDiag2(void);

#endif

#if DIAGDIS_MOTORPREDRIVERREG == 0

extern void FaultDiagR_PredriverDiag1_Reset(void);

#endif

#if DIAGDIS_MOTORPREDRIVERREG == 0

extern void FaultDiagRapid_PredriverDiag1(void);

#endif

#if DIAGDIS_MOTORPREDRIVERREG == 0

extern void FaultDiagR_PredriverDiag2_Reset(void);

#endif

#if DIAGDIS_MOTORPREDRIVERREG == 0

extern void FaultDiagRapid_PredriverDiag2(void);

#endif

extern void MotorCheck_OutputCurrent_Reset(void);
extern void FaultD_MotorCheck_OutputCurrent(void);
extern void Fa_MotorCheck_OverCurrent_Reset(void);
extern void FaultDia_MotorCheck_OverCurrent(void);
extern void Faul_MotorCheck_Predriver_Reset(void);
extern void FaultDiagR_MotorCheck_Predriver(void);
extern void Fault_DiagRapid_MotoCheck_Reset(void);
extern void FaultDiagRa_DiagRapid_MotoCheck(void);

#endif                                 /* RTW_HEADER_FaultDiagRapid_Motor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
