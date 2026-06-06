/*
 * File: FaultDiagRapid_Rotor.h
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

#ifndef RTW_HEADER_FaultDiagRapid_Rotor_h_
#define RTW_HEADER_FaultDiagRapid_Rotor_h_
#ifndef FaultDiagRapid_COMMON_INCLUDES_
# define FaultDiagRapid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FaultDiagRapid_COMMON_INCLUDES_ */

#include "FaultDiagRapid_types.h"

/* Block signals and states (default storage) for system '<S175>/PowerCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_ROTORPOWERREG == 0

typedef struct {
  struct {
    UInt32 is_MiddDiag1:2;             /* '<S176>/RotorPowerDiag' */
    UInt32 is_MiddDiag2:2;             /* '<S176>/RotorPowerDiag' */
    UInt32 is_active_c42_FaultDiagRapid:1;/* '<S176>/RotorPowerDiag' */
  } bitsForTID0;

  UInt16 RM_TimeWin1;                  /* '<S176>/RotorPowerDiag' */
  UInt16 RM_TimeWin2;                  /* '<S176>/RotorPowerDiag' */
} FaultDiagRap_DW_PowerCheck_l5tg;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S182>/SignalCheck' */
#ifndef FaultDiagRapid_MDLREF_HIDE_CHILD_
#if DIAGDIS_ROTORSIGNALREG == 0

typedef struct {
  struct {
    UInt32 is_c5_FaultDiagRapid:2;     /* '<S183>/RotorSignalDiag2' */
    UInt32 is_c60_FaultDiagRapid:2;    /* '<S183>/RotorSignalDiag1' */
    UInt32 is_active_c5_FaultDiagRapid:1;/* '<S183>/RotorSignalDiag2' */
    UInt32 is_active_c60_FaultDiagRapid:1;/* '<S183>/RotorSignalDiag1' */
    UInt32 sinrflag:1;                 /* '<S183>/RotorSignalDiag2' */
    UInt32 cosrflag:1;                 /* '<S183>/RotorSignalDiag2' */
    UInt32 sinoflag:1;                 /* '<S183>/RotorSignalDiag2' */
    UInt32 cosoflag:1;                 /* '<S183>/RotorSignalDiag2' */
    UInt32 sinrflag_l5n0:1;            /* '<S183>/RotorSignalDiag1' */
    UInt32 cosrflag_anpc:1;            /* '<S183>/RotorSignalDiag1' */
    UInt32 sinoflag_oken:1;            /* '<S183>/RotorSignalDiag1' */
    UInt32 cosoflag_p2dn:1;            /* '<S183>/RotorSignalDiag1' */
  } bitsForTID0;

  UInt16 RSI_TimeWin;                  /* '<S183>/RotorSignalDiag2' */
  UInt16 RSF_TimeWin;                  /* '<S183>/RotorSignalDiag2' */
  UInt16 RCO_TimeWin;                  /* '<S183>/RotorSignalDiag2' */
  UInt16 RCF_TimeWin;                  /* '<S183>/RotorSignalDiag2' */
  UInt16 RL_TimeWin;                   /* '<S183>/RotorSignalDiag2' */
  UInt16 RSI_TimeWin_mmp1;             /* '<S183>/RotorSignalDiag1' */
  UInt16 RSF_TimeWin_pdg0;             /* '<S183>/RotorSignalDiag1' */
  UInt16 RCO_TimeWin_eikr;             /* '<S183>/RotorSignalDiag1' */
  UInt16 RCF_TimeWin_mksu;             /* '<S183>/RotorSignalDiag1' */
  UInt16 RL_TimeWin_jiuo;              /* '<S183>/RotorSignalDiag1' */
} FaultDiagRa_DW_SignalCheck_g2uu;

#endif
#endif                                 /*FaultDiagRapid_MDLREF_HIDE_CHILD_*/

#if (DIAGDIS_ROTORPOWERREG == 0) || (DIAGDIS_ROTORPOWERREG == 1)

extern void FaultDiagRapid_RotorPowerCond(const UInt16 *rtu_AD_RotorSenPower,
  const UInt16 *rtu_AD_RotorMainMid1, const UInt16 *rtu_AD_RotorMainMid2, UInt16
  *rty_Fv_RotorMidADVol1, UInt16 *rty_Fv_RotorMidADVol2);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

extern void FaultDiagRapid_RotorSignalCond1(UInt16 rtu_Fv_RotorMidADVol, const
  UInt16 *rtu_AD_RotorMainSin, const UInt16 *rtu_AD_RotorMainCos, const UInt16
  *rtu_AD_RotorSubSin, const UInt16 *rtu_AD_RotorSubCos, Bool *rty_precondrtr,
  UInt16 *rty_Fv_RotorMainSinADVol, UInt16 *rty_mainsquare, UInt16
  *rty_Fv_RotorMainCosADVol, UInt16 *rty_vsinsum, UInt16 *rty_vsinoft, UInt16
  *rty_Fv_RotorSubSinADVol, UInt16 *rty_subsquare, UInt16
  *rty_Fv_RotorSubCosADVol, UInt16 *rty_vcossum, UInt16 *rty_vcosoft);

#endif

extern void Faul_DiagRapid_RotorCheck_Reset(void);
extern void FaultDiagR_DiagRapid_RotorCheck(void);

#endif                                 /* RTW_HEADER_FaultDiagRapid_Rotor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
