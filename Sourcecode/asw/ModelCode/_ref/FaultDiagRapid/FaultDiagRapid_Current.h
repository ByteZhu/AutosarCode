/*
 * File: FaultDiagRapid_Current.h
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

#ifndef RTW_HEADER_FaultDiagRapid_Current_h_
#define RTW_HEADER_FaultDiagRapid_Current_h_
#ifndef FaultDiagRapid_COMMON_INCLUDES_
# define FaultDiagRapid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultDiagRapid_COMMON_INCLUDES_ */

#include "FaultDiagRapid_types.h"

/* Block signals and states (default storage) for system '<S34>/MidCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_CURRENTMIDREG == 0

typedef struct {
  struct {
    UInt32 is_c7_FaultDiagRapid:2;     /* '<S35>/CurrentMidDiag2' */
    UInt32 is_Run:2;                   /* '<S35>/CurrentMidDiag2' */
    UInt32 is_c6_FaultDiagRapid:2;     /* '<S35>/CurrentMidDiag1' */
    UInt32 is_Run_ipns:2;              /* '<S35>/CurrentMidDiag1' */
    UInt32 is_active_c7_FaultDiagRapid:1;/* '<S35>/CurrentMidDiag2' */
    UInt32 is_active_c6_FaultDiagRapid:1;/* '<S35>/CurrentMidDiag1' */
  } bitsForTID0;

  UInt16 Fv_I2D5RefADVol2_j1h3;        /* '<S38>/Product' */
  UInt16 CM_TimeWin;                   /* '<S35>/CurrentMidDiag2' */
  UInt16 CM_TimeWin_aoak;              /* '<S35>/CurrentMidDiag1' */
  Bool precond2;                       /* '<S38>/Logical Operator' */
} FaultDiagRapid_DW_MidCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S49>/SampleCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_CURRENTSAMPLEREG == 0

typedef struct {
  Int32 isum2;                         /* '<S53>/Abs' */
  struct {
    UInt32 is_c10_FaultDiagRapid:2;    /* '<S50>/CurrentSampleDiag2' */
    UInt32 is_Run:2;                   /* '<S50>/CurrentSampleDiag2' */
    UInt32 is_c9_FaultDiagRapid:2;     /* '<S50>/CurrentSampleDiag1' */
    UInt32 is_Run_phx2:2;              /* '<S50>/CurrentSampleDiag1' */
    UInt32 is_active_c10_FaultDiagRapid:1;/* '<S50>/CurrentSampleDiag2' */
    UInt32 is_active_c9_FaultDiagRapid:1;/* '<S50>/CurrentSampleDiag1' */
  } bitsForTID0;

  UInt16 CS_TimeWin;                   /* '<S50>/CurrentSampleDiag2' */
  UInt16 CS_TimeWin_gn52;              /* '<S50>/CurrentSampleDiag1' */
  Bool precondsum2;                    /* '<S53>/Logical Operator1' */
} FaultDiagRapid_DW_SampleCheck;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#if DIAGDIS_CURRENTMIDREG == 0

extern void FaultDiag_CurrentMidDiag1_Reset(void);

#endif

#if DIAGDIS_CURRENTMIDREG == 0

extern void FaultDiagRapid_CurrentMidDiag1(void);

#endif

#if DIAGDIS_CURRENTMIDREG == 0

extern void FaultDiag_CurrentMidDiag2_Reset(void);

#endif

#if DIAGDIS_CURRENTMIDREG == 0

extern void FaultDiagRapid_CurrentMidDiag2(void);

#endif

#if DIAGDIS_CURRENTSAMPLEREG == 0

extern void FaultD_CurrentSampleDiag1_Reset(void);

#endif

#if DIAGDIS_CURRENTSAMPLEREG == 0

extern void FaultDiagRap_CurrentSampleDiag1(void);

#endif

#if DIAGDIS_CURRENTSAMPLEREG == 0

extern void FaultD_CurrentSampleDiag2_Reset(void);

#endif

#if DIAGDIS_CURRENTSAMPLEREG == 0

extern void FaultDiagRap_CurrentSampleDiag2(void);

#endif

extern void FaultDia_CurrentCheck_Mid_Reset(void);
extern void FaultDiagRapid_CurrentCheck_Mid(void);
extern void Fault_CurrentCheck_Sample_Reset(void);
extern void FaultDiagRa_CurrentCheck_Sample(void);
extern void Fa_DiagRapid_CurrentCheck_Reset(void);
extern void FaultDia_DiagRapid_CurrentCheck(void);

#endif                                /* RTW_HEADER_FaultDiagRapid_Current_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
