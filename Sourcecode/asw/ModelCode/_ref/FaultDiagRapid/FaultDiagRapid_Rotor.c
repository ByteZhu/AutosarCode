/*
 * File: FaultDiagRapid_Rotor.c
 *
 * Code generated for Simulink model 'FaultDiagRapid'.
 *
 * Model version                  : 1.1294
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:32:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FaultDiagRapid_Rotor.h"

/* Include model header file for global data */
#include "FaultDiagRapid.h"
#include "FaultDiagRapid_private.h"
#include "asr_s32.h"

/* Named constants for Chart: '<S176>/RotorPowerDiag' */
#define FaultDi_IN_NO_ACTIVE_CHILD_i1cc ((UInt8)0U)
#define FaultDiagRapid_IN_Fault_jwdo   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_fswg  ((UInt8)2U)

/* Named constants for Chart: '<S183>/RotorSignalDiag1' */
#define FaultDi_IN_NO_ACTIVE_CHILD_p1yb ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_ml4k    ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_cyuj    ((UInt8)2U)
#if DIAGDIS_ROTORSIGNALREG == 0

/* Forward declaration for local functions */
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinRange(const UInt16 *Fv_RotorMainSinADVol_i53a_m,
  const UInt16 *Fv_RotorSubSinADVol_hkyp_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinOffset(const UInt16 *vsinsum_erde_m, const UInt16 *
  vsinoft_mt2z_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosRange(const UInt16 *Fv_RotorMainCosADVol_gu5x_m,
  const UInt16 *Fv_RotorSubCosADVol_gja2_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiag_enter_atomic_SinRange(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosOffset(const UInt16 *vcossum_cp20_m, const UInt16 *
  vcosoft_lcdl_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDia_enter_atomic_SinOffset(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_Lotus(const UInt16 *mainsquare_ov4l_m, const UInt16
  *subsquare_bs40_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiag_enter_atomic_CosRange(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDia_enter_atomic_CosOffset(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRap_enter_atomic_Lotus(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinRange_afap(const UInt16 *Fv_RotorMainSinADVol_m,
  const UInt16 *Fv_RotorSubSinADVol_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinOffset_k3lv(const UInt16 *vsinsum_m, const UInt16 *
  vsinoft_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosRange_lxvo(const UInt16 *Fv_RotorMainCosADVol_m,
  const UInt16 *Fv_RotorSubCosADVol_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void Faul_enter_atomic_SinRange_czdq(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosOffset_czxq(const UInt16 *vcossum_m, const UInt16 *
  vcosoft_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void Fau_enter_atomic_SinOffset_ndfd(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_Lotus_dln4(const UInt16 *mainsquare_m, const UInt16
  *subsquare_m);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void Faul_enter_atomic_CosRange_jwzx(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void Fau_enter_atomic_CosOffset_lz5f(void);

#endif

#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDi_enter_atomic_Lotus_awzk(void);

#endif
#endif

/*
 * Output and update for atomic system:
 *    '<S176>/RotorPowerCond'
 *    '<S175>/PowerCheckDis'
 */
#if (DIAGDIS_ROTORPOWERREG == 0) || (DIAGDIS_ROTORPOWERREG == 1)

void FaultDiagRapid_RotorPowerCond(const UInt16 *rtu_AD_RotorSenPower, const
  UInt16 *rtu_AD_RotorMainMid1, const UInt16 *rtu_AD_RotorMainMid2, UInt16
  *rty_Fv_RotorMidADVol1, UInt16 *rty_Fv_RotorMidADVol2)
{
  /* Product: '<S178>/Product1' incorporates:
   *  Constant: '<S178>/Constant1'
   */
  *rty_Fv_RotorMidADVol1 = (UInt16)((((UInt32)(*rtu_AD_RotorMainMid1)) *
    ((UInt32)((UInt16)MACRO_AV_AD2VOL))) >> 6);

  /* Product: '<S178>/Product2' incorporates:
   *  Constant: '<S178>/Constant1'
   */
  *rty_Fv_RotorMidADVol2 = (UInt16)((((UInt32)((UInt16)MACRO_AV_AD2VOL)) *
    ((UInt32)(*rtu_AD_RotorMainMid2))) >> 6);

  /* DataStoreWrite: '<S178>/Data Store Write2' */
  Fv_RotorMidADVol2 = *rty_Fv_RotorMidADVol2;

  /* DataStoreWrite: '<S178>/Data Store Write' */
  Fv_RotorMidADVol1 = *rty_Fv_RotorMidADVol1;

  /* Product: '<S178>/Product' incorporates:
   *  Constant: '<S178>/Constant'
   *  DataStoreWrite: '<S178>/Data Store Write1'
   */
  Fv_SensorPowerResolver = (UInt16)((((UInt32)(*rtu_AD_RotorSenPower)) *
    ((UInt32)((UInt16)MACRO_AV_RSVPOWER_SCALE))) >> 9);
}

#endif

/*
 * Output and update for atomic system:
 *    '<S183>/RotorSignalCond1'
 *    '<S183>/RotorSignalCond2'
 */
#if DIAGDIS_ROTORSIGNALREG == 0

void FaultDiagRapid_RotorSignalCond1(UInt16 rtu_Fv_RotorMidADVol, const UInt16
  *rtu_AD_RotorMainSin, const UInt16 *rtu_AD_RotorMainCos, const UInt16
  *rtu_AD_RotorSubSin, const UInt16 *rtu_AD_RotorSubCos, Bool *rty_precondrtr,
  UInt16 *rty_Fv_RotorMainSinADVol, UInt16 *rty_mainsquare, UInt16
  *rty_Fv_RotorMainCosADVol, UInt16 *rty_vsinsum, UInt16 *rty_vsinoft, UInt16
  *rty_Fv_RotorSubSinADVol, UInt16 *rty_subsquare, UInt16
  *rty_Fv_RotorSubCosADVol, UInt16 *rty_vcossum, UInt16 *rty_vcosoft)
{
  Int16 rtb_Subtract4;
  UInt16 rtb_MagnitudeSquared4;

  /* Product: '<S185>/Product4' incorporates:
   *  Constant: '<S185>/Constant3'
   */
  *rty_Fv_RotorSubSinADVol = (UInt16)((((UInt32)(*rtu_AD_RotorSubSin)) *
    ((UInt32)((UInt16)MACRO_AV_AD2VOL))) >> 6);

  /* Product: '<S185>/Product2' incorporates:
   *  Constant: '<S185>/Constant2'
   */
  *rty_Fv_RotorMainSinADVol = (UInt16)((((UInt32)(*rtu_AD_RotorMainSin)) *
    ((UInt32)((UInt16)MACRO_AV_AD2VOL))) >> 6);

  /* Sum: '<S185>/Add3' */
  rtb_Subtract4 = (Int16)((Int32)(((Int32)(*rty_Fv_RotorSubSinADVol)) - ((Int32)
    (*rty_Fv_RotorMainSinADVol))));

  /* Abs: '<S185>/Abs' */
  if (rtb_Subtract4 < 0) {
    *rty_vsinoft = (UInt16)((Int32)(-((Int32)rtb_Subtract4)));
  } else {
    *rty_vsinoft = (UInt16)rtb_Subtract4;
  }

  /* End of Abs: '<S185>/Abs' */

  /* Sum: '<S185>/Subtract' */
  rtb_Subtract4 = (Int16)((Int32)(((Int32)(*rty_Fv_RotorMainSinADVol)) - ((Int32)
    rtu_Fv_RotorMidADVol)));

  /* Math: '<S185>/Magnitude Squared'
   *
   * About '<S185>/Magnitude Squared':
   *  Operator: magnitude^2
   */
  rtb_MagnitudeSquared4 = (UInt16)asr_s32(((Int32)rtb_Subtract4) * ((Int32)
    rtb_Subtract4), 7U);

  /* Product: '<S185>/Product3' incorporates:
   *  Constant: '<S185>/Constant2'
   */
  *rty_Fv_RotorMainCosADVol = (UInt16)((((UInt32)((UInt16)MACRO_AV_AD2VOL)) *
    ((UInt32)(*rtu_AD_RotorMainCos))) >> 6);

  /* Sum: '<S185>/Subtract1' */
  rtb_Subtract4 = (Int16)((Int32)(((Int32)(*rty_Fv_RotorMainCosADVol)) - ((Int32)
    rtu_Fv_RotorMidADVol)));

  /* Sum: '<S185>/Add' incorporates:
   *  Math: '<S185>/Magnitude Squared1'
   *
   * About '<S185>/Magnitude Squared1':
   *  Operator: magnitude^2
   */
  *rty_mainsquare = (UInt16)(((UInt32)rtb_MagnitudeSquared4) + ((UInt32)((UInt16)
    asr_s32(((Int32)rtb_Subtract4) * ((Int32)rtb_Subtract4), 7U))));

  /* Product: '<S185>/Product5' incorporates:
   *  Constant: '<S185>/Constant3'
   */
  *rty_Fv_RotorSubCosADVol = (UInt16)((((UInt32)((UInt16)MACRO_AV_AD2VOL)) *
    ((UInt32)(*rtu_AD_RotorSubCos))) >> 6);

  /* Sum: '<S185>/Add5' */
  rtb_Subtract4 = (Int16)((Int32)(((Int32)(*rty_Fv_RotorSubCosADVol)) - ((Int32)
    (*rty_Fv_RotorMainCosADVol))));

  /* Abs: '<S185>/Abs1' */
  if (rtb_Subtract4 < 0) {
    *rty_vcosoft = (UInt16)((Int32)(-((Int32)rtb_Subtract4)));
  } else {
    *rty_vcosoft = (UInt16)rtb_Subtract4;
  }

  /* End of Abs: '<S185>/Abs1' */

  /* Sum: '<S185>/Subtract5' */
  rtb_Subtract4 = (Int16)((Int32)(((Int32)(*rty_Fv_RotorSubCosADVol)) - ((Int32)
    rtu_Fv_RotorMidADVol)));

  /* Math: '<S185>/Magnitude Squared5'
   *
   * About '<S185>/Magnitude Squared5':
   *  Operator: magnitude^2
   */
  rtb_MagnitudeSquared4 = (UInt16)asr_s32(((Int32)rtb_Subtract4) * ((Int32)
    rtb_Subtract4), 7U);

  /* Sum: '<S185>/Subtract4' */
  rtb_Subtract4 = (Int16)((Int32)(((Int32)(*rty_Fv_RotorSubSinADVol)) - ((Int32)
    rtu_Fv_RotorMidADVol)));

  /* Sum: '<S185>/Add1' incorporates:
   *  Math: '<S185>/Magnitude Squared4'
   *
   * About '<S185>/Magnitude Squared4':
   *  Operator: magnitude^2
   */
  *rty_subsquare = (UInt16)(((UInt32)((UInt16)asr_s32(((Int32)rtb_Subtract4) *
    ((Int32)rtb_Subtract4), 7U))) + ((UInt32)rtb_MagnitudeSquared4));

  /* Sum: '<S185>/Add4' */
  *rty_vcossum = (UInt16)(((UInt32)(*rty_Fv_RotorSubCosADVol)) + ((UInt32)
    (*rty_Fv_RotorMainCosADVol)));

  /* Sum: '<S185>/Add2' */
  *rty_vsinsum = (UInt16)(((UInt32)(*rty_Fv_RotorSubSinADVol)) + ((UInt32)
    (*rty_Fv_RotorMainSinADVol)));

  /* Logic: '<S185>/Logical Operator2' incorporates:
   *  Constant: '<S189>/Constant'
   *  Constant: '<S190>/Constant'
   *  Constant: '<S191>/Constant'
   *  Constant: '<S192>/Constant'
   *  DataStoreRead: '<S185>/Data Store Read'
   *  DataStoreRead: '<S185>/Data Store Read2'
   *  DataStoreRead: '<S185>/Data Store Read3'
   *  RelationalOperator: '<S189>/Compare'
   *  RelationalOperator: '<S190>/Compare'
   *  RelationalOperator: '<S191>/Compare'
   *  RelationalOperator: '<S192>/Compare'
   */
  *rty_precondrtr = (((((Fv_SensorPowerResolver >= ((UInt16)
    MACRO_RESOLVER_POWERMIN)) && (SysTaskRsvBrownoutPending == false)) &&
                       (SysTaskRsvSnsPending)) && (rtu_Fv_RotorMidADVol >=
    ((UInt16)MACRO_RESOLVER_MIDMIN))) && (rtu_Fv_RotorMidADVol <= ((UInt16)
    MACRO_RESOLVER_MIDMAX)));
}

#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinRange(const UInt16 *Fv_RotorMainSinADVol_i53a_m,
  const UInt16 *Fv_RotorSubSinADVol_hkyp_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'SinRange': '<S187>:1476' */
  /* Transition: '<S187>:1527' */
  if (((((*Fv_RotorMainSinADVol_i53a_m) > ((UInt16)MACRO_RESOLVER_SIGMAX)) || ((*
          Fv_RotorMainSinADVol_i53a_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) || ((*
         Fv_RotorSubSinADVol_hkyp_m) > ((UInt16)MACRO_RESOLVER_SIGMAX))) ||
      ((*Fv_RotorSubSinADVol_hkyp_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) {
    /* Transition: '<S187>:1529' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1 < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S187>:1531' */
      /* Transition: '<S187>:1533' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1 = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1) + 2));
    } else {
      /* Outputs for Function Call SubSystem: '<S187>/DTC_Ctrl_Enabled' */
      /* Selector: '<S197>/Selector' */
      /* Transition: '<S187>:1535' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S187>:1787' */
      Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_SinRange;

      /* DataTypeConversion: '<S197>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S197>/Data Store Read'
       *  Product: '<S197>/Product'
       *  Selector: '<S197>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m].
        Enabled) * ((UInt32)FailureDiag_RegErr));

      /* End of Outputs for SubSystem: '<S187>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S187>/getDTCEnabled' */
      /* Selector: '<S198>/Selector' incorporates:
       *  DataStoreRead: '<S198>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S187>:1783' */
      Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 2,
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
        [DTC_RESOLVERcheck_SinRange].Enabled);

      /* End of Outputs for SubSystem: '<S187>/getDTCEnabled' */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag_l5n0 = true;

      /* Transition: '<S187>:1538' */
    }

    /* Transition: '<S187>:1547' */
  } else {
    /* Transition: '<S187>:1537' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1) > 0) {
      /* Transition: '<S187>:1540' */
      /* Transition: '<S187>:1542' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1 = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1) - 1));
    } else {
      /* Transition: '<S187>:1544' */
      /* Transition: '<S187>:1545' */
    }

    /* Transition: '<S187>:1548' */
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinOffset(const UInt16 *vsinsum_erde_m, const UInt16 *
  vsinoft_mt2z_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'SinOffset': '<S187>:1464' */
  /* Transition: '<S187>:1584' */
  if ((((*vsinsum_erde_m) > ((UInt16)MACRO_RESOLVER_SUMMAX)) ||
       ((*vsinsum_erde_m) < ((UInt16)MACRO_RESOLVER_SUMMIN))) ||
      ((*vsinoft_mt2z_m) > ((UInt16)MACRO_RESOLVER_SIGAMP))) {
    /* Transition: '<S187>:1594' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0 < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S187>:1592' */
      /* Transition: '<S187>:1588' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0 = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0) + 2));

      /* Transition: '<S187>:1665' */
      /* Transition: '<S187>:1666' */
    } else {
      /* Transition: '<S187>:1597' */
      if (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag_l5n0) {
        /* Outputs for Function Call SubSystem: '<S187>/DTC_Ctrl_Enabled' */
        /* Selector: '<S197>/Selector' */
        /* Transition: '<S187>:1603' */
        /* Transition: '<S187>:1660' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S187>:1787' */
        Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_SinOffset;

        /* DataTypeConversion: '<S197>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S197>/Data Store Read'
         *  Product: '<S197>/Product'
         *  Selector: '<S197>/Selector'
         */
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m]
          .Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S187>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S187>/getDTCEnabled' */
        /* Selector: '<S198>/Selector' incorporates:
         *  DataStoreRead: '<S198>/Data Store Read'
         */
        /* Simulink Function 'getDTCEnabled': '<S187>:1783' */
        Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 4,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_RESOLVERcheck_SinOffset].Enabled);

        /* End of Outputs for SubSystem: '<S187>/getDTCEnabled' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinoflag_oken = true;

        /* Transition: '<S187>:1666' */
      } else {
        /* Transition: '<S187>:1664' */
      }
    }

    /* Transition: '<S187>:1667' */
    /* Transition: '<S187>:1668' */
  } else {
    /* Transition: '<S187>:1601' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0) > 0) {
      /* Transition: '<S187>:1600' */
      /* Transition: '<S187>:1586' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0 = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0) - 1));

      /* Transition: '<S187>:1668' */
    } else {
      /* Transition: '<S187>:1590' */
    }
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosRange(const UInt16 *Fv_RotorMainCosADVol_gu5x_m,
  const UInt16 *Fv_RotorSubCosADVol_gja2_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'CosRange': '<S187>:1488' */
  /* Transition: '<S187>:1549' */
  if (((((*Fv_RotorMainCosADVol_gu5x_m) > ((UInt16)MACRO_RESOLVER_SIGMAX)) || ((*
          Fv_RotorMainCosADVol_gu5x_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) || ((*
         Fv_RotorSubCosADVol_gja2_m) > ((UInt16)MACRO_RESOLVER_SIGMAX))) ||
      ((*Fv_RotorSubCosADVol_gja2_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) {
    /* Transition: '<S187>:1559' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S187>:1557' */
      /* Transition: '<S187>:1553' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr) + 2));
    } else {
      /* Outputs for Function Call SubSystem: '<S187>/DTC_Ctrl_Enabled' */
      /* Selector: '<S197>/Selector' */
      /* Transition: '<S187>:1562' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S187>:1787' */
      Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_CosRange;

      /* DataTypeConversion: '<S197>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S197>/Data Store Read'
       *  Product: '<S197>/Product'
       *  Selector: '<S197>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m].
        Enabled) * ((UInt32)FailureDiag_RegErr));

      /* End of Outputs for SubSystem: '<S187>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S187>/getDTCEnabled' */
      /* Selector: '<S198>/Selector' incorporates:
       *  DataStoreRead: '<S198>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S187>:1783' */
      Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 6,
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
        [DTC_RESOLVERcheck_CosRange].Enabled);

      /* End of Outputs for SubSystem: '<S187>/getDTCEnabled' */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag_anpc = true;

      /* Transition: '<S187>:1568' */
    }

    /* Transition: '<S187>:1571' */
  } else {
    /* Transition: '<S187>:1566' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr) > 0) {
      /* Transition: '<S187>:1565' */
      /* Transition: '<S187>:1551' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr) - 1));
    } else {
      /* Transition: '<S187>:1555' */
      /* Transition: '<S187>:1560' */
    }

    /* Transition: '<S187>:1563' */
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiag_enter_atomic_SinRange(void)
{
  /* Entry 'SinRange': '<S187>:1476' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1 = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosOffset(const UInt16 *vcossum_cp20_m, const UInt16 *
  vcosoft_lcdl_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'CosOffset': '<S187>:1500' */
  /* Transition: '<S187>:1694' */
  if ((((*vcossum_cp20_m) > ((UInt16)MACRO_RESOLVER_SUMMAX)) ||
       ((*vcossum_cp20_m) < ((UInt16)MACRO_RESOLVER_SUMMIN))) ||
      ((*vcosoft_lcdl_m) > ((UInt16)MACRO_RESOLVER_SIGAMP))) {
    /* Transition: '<S187>:1688' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S187>:1678' */
      /* Transition: '<S187>:1681' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu) + 2));

      /* Transition: '<S187>:1671' */
      /* Transition: '<S187>:1696' */
    } else {
      /* Transition: '<S187>:1684' */
      if (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag_anpc) {
        /* Outputs for Function Call SubSystem: '<S187>/DTC_Ctrl_Enabled' */
        /* Selector: '<S197>/Selector' */
        /* Transition: '<S187>:1693' */
        /* Transition: '<S187>:1675' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S187>:1787' */
        Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_CosOffset;

        /* DataTypeConversion: '<S197>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S197>/Data Store Read'
         *  Product: '<S197>/Product'
         *  Selector: '<S197>/Selector'
         */
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m]
          .Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S187>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S187>/getDTCEnabled' */
        /* Selector: '<S198>/Selector' incorporates:
         *  DataStoreRead: '<S198>/Data Store Read'
         */
        /* Simulink Function 'getDTCEnabled': '<S187>:1783' */
        Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 8,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_RESOLVERcheck_CosOffset].Enabled);

        /* End of Outputs for SubSystem: '<S187>/getDTCEnabled' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosoflag_p2dn = true;

        /* Transition: '<S187>:1696' */
      } else {
        /* Transition: '<S187>:1674' */
      }
    }

    /* Transition: '<S187>:1695' */
    /* Transition: '<S187>:1673' */
  } else {
    /* Transition: '<S187>:1691' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu) > 0) {
      /* Transition: '<S187>:1680' */
      /* Transition: '<S187>:1690' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu) - 1));

      /* Transition: '<S187>:1673' */
    } else {
      /* Transition: '<S187>:1679' */
    }
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDia_enter_atomic_SinOffset(void)
{
  /* Entry 'SinOffset': '<S187>:1464' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0 = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_Lotus(const UInt16 *mainsquare_ov4l_m, const UInt16
  *subsquare_bs40_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'Lotus': '<S187>:1512' */
  /* Transition: '<S187>:1705' */
  if (((((*mainsquare_ov4l_m) > ((UInt16)MACRO_RESOLVER_LOTUSMAX)) ||
        ((*mainsquare_ov4l_m) < ((UInt16)MACRO_RESOLVER_LOTUSMIN))) ||
       ((*subsquare_bs40_m) > ((UInt16)MACRO_RESOLVER_LOTUSMAX))) ||
      ((*subsquare_bs40_m) < ((UInt16)MACRO_RESOLVER_LOTUSMIN))) {
    /* Transition: '<S187>:1710' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S187>:1709' */
      /* Transition: '<S187>:1719' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo) + 2));

      /* Transition: '<S187>:1703' */
      /* Transition: '<S187>:1712' */
    } else {
      /* Transition: '<S187>:1724' */
      if ((((!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag_l5n0) &&
            (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinoflag_oken)) &&
           (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag_anpc)) &&
          (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosoflag_p2dn)) {
        /* Outputs for Function Call SubSystem: '<S187>/DTC_Ctrl_Enabled' */
        /* Selector: '<S197>/Selector' */
        /* Transition: '<S187>:1708' */
        /* Transition: '<S187>:1697' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S187>:1787' */
        Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_LotusWave;

        /* DataTypeConversion: '<S197>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S197>/Data Store Read'
         *  Product: '<S197>/Product'
         *  Selector: '<S197>/Selector'
         */
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m]
          .Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S187>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S187>/getDTCEnabled' */
        /* Selector: '<S198>/Selector' incorporates:
         *  DataStoreRead: '<S198>/Data Store Read'
         */
        /* Simulink Function 'getDTCEnabled': '<S187>:1783' */
        Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 10,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_RESOLVERcheck_LotusWave].Enabled);

        /* End of Outputs for SubSystem: '<S187>/getDTCEnabled' */
        /* Transition: '<S187>:1712' */
      } else {
        /* Transition: '<S187>:1700' */
      }
    }

    /* Transition: '<S187>:1706' */
    /* Transition: '<S187>:1701' */
  } else {
    /* Transition: '<S187>:1715' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo) > 0) {
      /* Transition: '<S187>:1716' */
      /* Transition: '<S187>:1718' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo) - 1));

      /* Transition: '<S187>:1701' */
    } else {
      /* Transition: '<S187>:1721' */
    }
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiag_enter_atomic_CosRange(void)
{
  /* Entry 'CosRange': '<S187>:1488' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDia_enter_atomic_CosOffset(void)
{
  /* Entry 'CosOffset': '<S187>:1500' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag1' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRap_enter_atomic_Lotus(void)
{
  /* Entry 'Lotus': '<S187>:1512' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinRange_afap(const UInt16 *Fv_RotorMainSinADVol_m,
  const UInt16 *Fv_RotorSubSinADVol_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'SinRange': '<S188>:1476' */
  /* Transition: '<S188>:1527' */
  if (((((*Fv_RotorMainSinADVol_m) > ((UInt16)MACRO_RESOLVER_SIGMAX)) ||
        ((*Fv_RotorMainSinADVol_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) ||
       ((*Fv_RotorSubSinADVol_m) > ((UInt16)MACRO_RESOLVER_SIGMAX))) ||
      ((*Fv_RotorSubSinADVol_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) {
    /* Transition: '<S188>:1529' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S188>:1531' */
      /* Transition: '<S188>:1533' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin) + 2));
    } else {
      /* Outputs for Function Call SubSystem: '<S188>/DTC_Ctrl_Enabled' */
      /* Selector: '<S199>/Selector' */
      /* Transition: '<S188>:1535' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S188>:1787' */
      Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_SinRange;

      /* DataTypeConversion: '<S199>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S199>/Data Store Read'
       *  Product: '<S199>/Product'
       *  Selector: '<S199>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m].
        Enabled) * ((UInt32)FailureDiag_RegErr));

      /* End of Outputs for SubSystem: '<S188>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S188>/getDTCEnabled' */
      /* Selector: '<S200>/Selector' incorporates:
       *  DataStoreRead: '<S200>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S188>:1783' */
      Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 3,
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
        [DTC_RESOLVERcheck_SinRange].Enabled);

      /* End of Outputs for SubSystem: '<S188>/getDTCEnabled' */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag = true;

      /* Transition: '<S188>:1538' */
    }

    /* Transition: '<S188>:1547' */
  } else {
    /* Transition: '<S188>:1537' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin) > 0) {
      /* Transition: '<S188>:1540' */
      /* Transition: '<S188>:1542' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin) - 1));
    } else {
      /* Transition: '<S188>:1544' */
      /* Transition: '<S188>:1545' */
    }

    /* Transition: '<S188>:1548' */
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_SinOffset_k3lv(const UInt16 *vsinsum_m, const UInt16 *
  vsinoft_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'SinOffset': '<S188>:1464' */
  /* Transition: '<S188>:1584' */
  if ((((*vsinsum_m) > ((UInt16)MACRO_RESOLVER_SUMMAX)) || ((*vsinsum_m) <
        ((UInt16)MACRO_RESOLVER_SUMMIN))) || ((*vsinoft_m) > ((UInt16)
        MACRO_RESOLVER_SIGAMP))) {
    /* Transition: '<S188>:1594' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S188>:1592' */
      /* Transition: '<S188>:1588' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin) + 2));

      /* Transition: '<S188>:1665' */
      /* Transition: '<S188>:1666' */
    } else {
      /* Transition: '<S188>:1597' */
      if (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag) {
        /* Outputs for Function Call SubSystem: '<S188>/DTC_Ctrl_Enabled' */
        /* Selector: '<S199>/Selector' */
        /* Transition: '<S188>:1603' */
        /* Transition: '<S188>:1660' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S188>:1787' */
        Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_SinOffset;

        /* DataTypeConversion: '<S199>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S199>/Data Store Read'
         *  Product: '<S199>/Product'
         *  Selector: '<S199>/Selector'
         */
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m]
          .Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S188>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S188>/getDTCEnabled' */
        /* Selector: '<S200>/Selector' incorporates:
         *  DataStoreRead: '<S200>/Data Store Read'
         */
        /* Simulink Function 'getDTCEnabled': '<S188>:1783' */
        Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 5,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_RESOLVERcheck_SinOffset].Enabled);

        /* End of Outputs for SubSystem: '<S188>/getDTCEnabled' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinoflag = true;

        /* Transition: '<S188>:1666' */
      } else {
        /* Transition: '<S188>:1664' */
      }
    }

    /* Transition: '<S188>:1667' */
    /* Transition: '<S188>:1668' */
  } else {
    /* Transition: '<S188>:1601' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin) > 0) {
      /* Transition: '<S188>:1600' */
      /* Transition: '<S188>:1586' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin) - 1));

      /* Transition: '<S188>:1668' */
    } else {
      /* Transition: '<S188>:1590' */
    }
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosRange_lxvo(const UInt16 *Fv_RotorMainCosADVol_m,
  const UInt16 *Fv_RotorSubCosADVol_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'CosRange': '<S188>:1488' */
  /* Transition: '<S188>:1549' */
  if (((((*Fv_RotorMainCosADVol_m) > ((UInt16)MACRO_RESOLVER_SIGMAX)) ||
        ((*Fv_RotorMainCosADVol_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) ||
       ((*Fv_RotorSubCosADVol_m) > ((UInt16)MACRO_RESOLVER_SIGMAX))) ||
      ((*Fv_RotorSubCosADVol_m) < ((UInt16)MACRO_RESOLVER_SIGMIN))) {
    /* Transition: '<S188>:1559' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S188>:1557' */
      /* Transition: '<S188>:1553' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin) + 2));
    } else {
      /* Outputs for Function Call SubSystem: '<S188>/DTC_Ctrl_Enabled' */
      /* Selector: '<S199>/Selector' */
      /* Transition: '<S188>:1562' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S188>:1787' */
      Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_CosRange;

      /* DataTypeConversion: '<S199>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S199>/Data Store Read'
       *  Product: '<S199>/Product'
       *  Selector: '<S199>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m].
        Enabled) * ((UInt32)FailureDiag_RegErr));

      /* End of Outputs for SubSystem: '<S188>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S188>/getDTCEnabled' */
      /* Selector: '<S200>/Selector' incorporates:
       *  DataStoreRead: '<S200>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S188>:1783' */
      Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 7,
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
        [DTC_RESOLVERcheck_CosRange].Enabled);

      /* End of Outputs for SubSystem: '<S188>/getDTCEnabled' */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag = true;

      /* Transition: '<S188>:1568' */
    }

    /* Transition: '<S188>:1571' */
  } else {
    /* Transition: '<S188>:1566' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin) > 0) {
      /* Transition: '<S188>:1565' */
      /* Transition: '<S188>:1551' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin) - 1));
    } else {
      /* Transition: '<S188>:1555' */
      /* Transition: '<S188>:1560' */
    }

    /* Transition: '<S188>:1563' */
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void Faul_enter_atomic_SinRange_czdq(void)
{
  /* Entry 'SinRange': '<S188>:1476' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_CosOffset_czxq(const UInt16 *vcossum_m, const UInt16 *
  vcosoft_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'CosOffset': '<S188>:1500' */
  /* Transition: '<S188>:1694' */
  if ((((*vcossum_m) > ((UInt16)MACRO_RESOLVER_SUMMAX)) || ((*vcossum_m) <
        ((UInt16)MACRO_RESOLVER_SUMMIN))) || ((*vcosoft_m) > ((UInt16)
        MACRO_RESOLVER_SIGAMP))) {
    /* Transition: '<S188>:1688' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S188>:1678' */
      /* Transition: '<S188>:1681' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin) + 2));

      /* Transition: '<S188>:1671' */
      /* Transition: '<S188>:1696' */
    } else {
      /* Transition: '<S188>:1684' */
      if (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag) {
        /* Outputs for Function Call SubSystem: '<S188>/DTC_Ctrl_Enabled' */
        /* Selector: '<S199>/Selector' */
        /* Transition: '<S188>:1693' */
        /* Transition: '<S188>:1675' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S188>:1787' */
        Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_CosOffset;

        /* DataTypeConversion: '<S199>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S199>/Data Store Read'
         *  Product: '<S199>/Product'
         *  Selector: '<S199>/Selector'
         */
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m]
          .Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S188>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S188>/getDTCEnabled' */
        /* Selector: '<S200>/Selector' incorporates:
         *  DataStoreRead: '<S200>/Data Store Read'
         */
        /* Simulink Function 'getDTCEnabled': '<S188>:1783' */
        Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 9,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_RESOLVERcheck_CosOffset].Enabled);

        /* End of Outputs for SubSystem: '<S188>/getDTCEnabled' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosoflag = true;

        /* Transition: '<S188>:1696' */
      } else {
        /* Transition: '<S188>:1674' */
      }
    }

    /* Transition: '<S188>:1695' */
    /* Transition: '<S188>:1673' */
  } else {
    /* Transition: '<S188>:1691' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin) > 0) {
      /* Transition: '<S188>:1680' */
      /* Transition: '<S188>:1690' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin) - 1));

      /* Transition: '<S188>:1673' */
    } else {
      /* Transition: '<S188>:1679' */
    }
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void Fau_enter_atomic_SinOffset_ndfd(void)
{
  /* Entry 'SinOffset': '<S188>:1464' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDiagRapid_Lotus_dln4(const UInt16 *mainsquare_m, const UInt16
  *subsquare_m)
{
  Int32 Fv_ErrDiagStatus_tmp_m;

  /* During 'Lotus': '<S188>:1512' */
  /* Transition: '<S188>:1705' */
  if (((((*mainsquare_m) > ((UInt16)MACRO_RESOLVER_LOTUSMAX)) || ((*mainsquare_m)
         < ((UInt16)MACRO_RESOLVER_LOTUSMIN))) || ((*subsquare_m) > ((UInt16)
         MACRO_RESOLVER_LOTUSMAX))) || ((*subsquare_m) < ((UInt16)
        MACRO_RESOLVER_LOTUSMIN))) {
    /* Transition: '<S188>:1710' */
    if (FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin < ((UInt16)
         MACRO_RESOLVER_FAULTCNT)) {
      /* Transition: '<S188>:1709' */
      /* Transition: '<S188>:1719' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin) + 2));

      /* Transition: '<S188>:1703' */
      /* Transition: '<S188>:1712' */
    } else {
      /* Transition: '<S188>:1724' */
      if ((((!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag) &&
            (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinoflag)) &&
           (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag)) &&
          (!FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosoflag)) {
        /* Outputs for Function Call SubSystem: '<S188>/DTC_Ctrl_Enabled' */
        /* Selector: '<S199>/Selector' */
        /* Transition: '<S188>:1708' */
        /* Transition: '<S188>:1697' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S188>:1787' */
        Fv_ErrDiagStatus_tmp_m = DTC_RESOLVERcheck_LotusWave;

        /* DataTypeConversion: '<S199>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S199>/Data Store Read'
         *  Product: '<S199>/Product'
         *  Selector: '<S199>/Selector'
         */
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m]
          .Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S188>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S188>/getDTCEnabled' */
        /* Selector: '<S200>/Selector' incorporates:
         *  DataStoreRead: '<S200>/Data Store Read'
         */
        /* Simulink Function 'getDTCEnabled': '<S188>:1783' */
        Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver, 11,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_RESOLVERcheck_LotusWave].Enabled);

        /* End of Outputs for SubSystem: '<S188>/getDTCEnabled' */
        /* Transition: '<S188>:1712' */
      } else {
        /* Transition: '<S188>:1700' */
      }
    }

    /* Transition: '<S188>:1706' */
    /* Transition: '<S188>:1701' */
  } else {
    /* Transition: '<S188>:1715' */
    if (((Int32)FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin) > 0) {
      /* Transition: '<S188>:1716' */
      /* Transition: '<S188>:1718' */
      FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin) - 1));

      /* Transition: '<S188>:1701' */
    } else {
      /* Transition: '<S188>:1721' */
    }
  }
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void Faul_enter_atomic_CosRange_jwzx(void)
{
  /* Entry 'CosRange': '<S188>:1488' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void Fau_enter_atomic_CosOffset_lz5f(void)
{
  /* Entry 'CosOffset': '<S188>:1500' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin = 0U;
}

#endif
#endif

/* Function for Chart: '<S183>/RotorSignalDiag2' */
#if DIAGDIS_ROTORSIGNALREG == 0
#if DIAGDIS_ROTORSIGNALREG == 0

static void FaultDi_enter_atomic_Lotus_awzk(void)
{
  /* Entry 'Lotus': '<S188>:1512' */
  FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin = 0U;
}

#endif
#endif

/* System reset for atomic system: '<S83>/DiagRapid_RotorCheck' */
void Faul_DiagRapid_RotorCheck_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S86>/RotorCheck_Power' */
  /* SystemReset for Atomic SubSystem: '<S173>/DiagRapid_RotorPower_Check' */
#if DIAGDIS_ROTORPOWERREG == 0

  /* Reset conditions for atomic system: '<S175>/PowerCheck' */

  /* SystemReset for Chart: '<S176>/RotorPowerDiag' */
  FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag1 =
    FaultDi_IN_NO_ACTIVE_CHILD_i1cc;
  FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag2 =
    FaultDi_IN_NO_ACTIVE_CHILD_i1cc;
  FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_active_c42_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin1 = 0U;
  FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin2 = 0U;

#endif

  /* End of SystemReset for SubSystem: '<S173>/DiagRapid_RotorPower_Check' */
  /* End of SystemReset for SubSystem: '<S86>/RotorCheck_Power' */

  /* SystemReset for Atomic SubSystem: '<S86>/RotorCheck_Signal' */
  /* SystemReset for Atomic SubSystem: '<S174>/DiagRapid_RotorSignal_Check' */
#if DIAGDIS_ROTORSIGNALREG == 0

  /* Reset conditions for atomic system: '<S182>/SignalCheck' */

  /* SystemReset for Chart: '<S183>/RotorSignalDiag1' */
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_active_c60_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c60_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_p1yb;
  FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin_mmp1 = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin_pdg0 = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin_eikr = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin_mksu = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin_jiuo = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag_l5n0 = false;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag_anpc = false;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinoflag_oken = false;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosoflag_p2dn = false;

  /* SystemReset for Chart: '<S183>/RotorSignalDiag2' */
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_active_c5_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c5_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_p1yb;
  FaultDiagRapidrtDW.SignalCheck_pci3.RSI_TimeWin = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RSF_TimeWin = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RCO_TimeWin = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RCF_TimeWin = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.RL_TimeWin = 0U;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinrflag = false;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosrflag = false;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.sinoflag = false;
  FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.cosoflag = false;

#endif

  /* End of SystemReset for SubSystem: '<S174>/DiagRapid_RotorSignal_Check' */
  /* End of SystemReset for SubSystem: '<S86>/RotorCheck_Signal' */
}

/* Output and update for atomic system: '<S83>/DiagRapid_RotorCheck' */
void FaultDiagR_DiagRapid_RotorCheck(void)
{
  /* local block i/o variables */
  UInt16 rtb_Fv_RotorMidADVol1;
  UInt16 rtb_Fv_RotorMidADVol2;

  /* Outputs for Atomic SubSystem: '<S86>/RotorCheck_Power' */
  /* Outputs for Atomic SubSystem: '<S173>/DiagRapid_RotorPower_Check' */
#if DIAGDIS_ROTORPOWERREG == 0

  /* Output and update for atomic system: '<S175>/PowerCheck' */
  {
    Int32 Fv_ErrDiagStatus_tmp_a;

    /* Outputs for Atomic SubSystem: '<S176>/RotorPowerCond' */
    /* Inport: '<Root>/AD_RotorSenPower' incorporates:
     *  Inport: '<Root>/AD_RotorMainMid1'
     *  Inport: '<Root>/AD_RotorMainMid2'
     */
    FaultDiagRapid_RotorPowerCond(((UInt16 *)&(AD_RotorSenPower)), ((UInt16 *)
      &(AD_RotorMainMid1)), ((UInt16 *)&(AD_RotorMainMid2)),
      &rtb_Fv_RotorMidADVol1, &rtb_Fv_RotorMidADVol2);

    /* End of Outputs for SubSystem: '<S176>/RotorPowerCond' */

    /* Chart: '<S176>/RotorPowerDiag' incorporates:
     *  DataStoreRead: '<S180>/Data Store Read'
     *  DataStoreRead: '<S181>/Data Store Read'
     *  DataTypeConversion: '<S180>/Data Type Conversion2'
     *  Product: '<S180>/Product'
     *  Selector: '<S180>/Selector'
     *  Selector: '<S181>/Selector'
     */
    /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerDiag */
    /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerDiag */
    if (((UInt32)
         FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_active_c42_FaultDiagRapid)
        == 0U) {
      /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerDiag */
      FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_active_c42_FaultDiagRapid
        = 1;

      /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Power/DiagRapid_RotorPower_Check/PowerCheck/RotorPowerDiag */
      /* Entry Internal 'MiddDiag1': '<S179>:1416' */
      /* Transition: '<S179>:1418' */
      FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag1 =
        FaultDiagRapid_IN_Normal_fswg;

      /* Entry Internal 'MiddDiag2': '<S179>:1483' */
      /* Transition: '<S179>:1484' */
      FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag2 =
        FaultDiagRapid_IN_Normal_fswg;
    } else {
      /* During 'MiddDiag1': '<S179>:1416' */
      if (((UInt32)FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag1) ==
          FaultDiagRapid_IN_Fault_jwdo) {
        /* During 'Fault': '<S179>:1420' */
        if ((rtb_Fv_RotorMidADVol1 <= ((UInt16)MACRO_RESOLVER_MIDMAX)) &&
            (rtb_Fv_RotorMidADVol1 >= ((UInt16)MACRO_RESOLVER_MIDMIN))) {
          /* Transition: '<S179>:1419' */
          FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag1 =
            FaultDiagRapid_IN_Normal_fswg;
        } else {
          /* Transition: '<S179>:1457' */
          if (((Int32)FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin1) > 0) {
            /* Transition: '<S179>:1456' */
            /* Transition: '<S179>:1459' */
            FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin1 = (UInt16)((Int32)
              (((Int32)FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin1) - 1));

            /* Transition: '<S179>:1454' */
          } else {
            /* Outputs for Function Call SubSystem: '<S179>/DTC_Ctrl_Enabled' */
            /* Selector: '<S180>/Selector' */
            /* Transition: '<S179>:1455' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S179>:1480' */
            Fv_ErrDiagStatus_tmp_a = DTC_RESOLVERcheck_MiddSig;
            Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_a)] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [Fv_ErrDiagStatus_tmp_a].Enabled) * ((UInt32)FailureDiag_RegErr));

            /* End of Outputs for SubSystem: '<S179>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S179>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S179>:1476' */
            Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver,
              0, (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_RESOLVERcheck_MiddSig].Enabled);

            /* End of Outputs for SubSystem: '<S179>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S179>:1426' */
        if ((rtb_Fv_RotorMidADVol1 > ((UInt16)MACRO_RESOLVER_MIDMAX)) ||
            (rtb_Fv_RotorMidADVol1 < ((UInt16)MACRO_RESOLVER_MIDMIN))) {
          /* Transition: '<S179>:1417' */
          FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag1 =
            FaultDiagRapid_IN_Fault_jwdo;

          /* Entry 'Fault': '<S179>:1420' */
          FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin1 = ((UInt16)
            MACRO_RESOLVER_CHECKTIME);
        }
      }

      /* During 'MiddDiag2': '<S179>:1483' */
      if (((UInt32)FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag2) ==
          FaultDiagRapid_IN_Fault_jwdo) {
        /* During 'Fault': '<S179>:1488' */
        if ((rtb_Fv_RotorMidADVol2 <= ((UInt16)MACRO_RESOLVER_MIDMAX)) &&
            (rtb_Fv_RotorMidADVol2 >= ((UInt16)MACRO_RESOLVER_MIDMIN))) {
          /* Transition: '<S179>:1486' */
          FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag2 =
            FaultDiagRapid_IN_Normal_fswg;
        } else {
          /* Transition: '<S179>:1493' */
          if (((Int32)FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin2) > 0) {
            /* Transition: '<S179>:1494' */
            /* Transition: '<S179>:1496' */
            FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin2 = (UInt16)((Int32)
              (((Int32)FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin2) - 1));

            /* Transition: '<S179>:1497' */
          } else {
            /* Outputs for Function Call SubSystem: '<S179>/DTC_Ctrl_Enabled' */
            /* Transition: '<S179>:1495' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S179>:1480' */
            Fv_ErrDiagStatus[DTC_RESOLVERcheck_MiddSig] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_RESOLVERcheck_MiddSig].Enabled) * ((UInt32)FailureDiag_RegErr));

            /* End of Outputs for SubSystem: '<S179>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S179>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S179>:1476' */
            Fv_FaultClass_Resolver = (UInt16)SetU16Fault(Fv_FaultClass_Resolver,
              1, (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_RESOLVERcheck_MiddSig].Enabled);

            /* End of Outputs for SubSystem: '<S179>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S179>:1487' */
        if ((rtb_Fv_RotorMidADVol2 > ((UInt16)MACRO_RESOLVER_MIDMAX)) ||
            (rtb_Fv_RotorMidADVol2 < ((UInt16)MACRO_RESOLVER_MIDMIN))) {
          /* Transition: '<S179>:1485' */
          FaultDiagRapidrtDW.PowerCheck_kyga.bitsForTID0.is_MiddDiag2 =
            FaultDiagRapid_IN_Fault_jwdo;

          /* Entry 'Fault': '<S179>:1488' */
          FaultDiagRapidrtDW.PowerCheck_kyga.RM_TimeWin2 = ((UInt16)
            MACRO_RESOLVER_CHECKTIME);
        }
      }
    }

    /* End of Chart: '<S176>/RotorPowerDiag' */
  }

#elif DIAGDIS_ROTORPOWERREG == 1

  /* Inport: '<Root>/AD_RotorSenPower' incorporates:
   *  Inport: '<Root>/AD_RotorMainMid1'
   *  Inport: '<Root>/AD_RotorMainMid2'
   */
  FaultDiagRapid_RotorPowerCond(((UInt16 *)&(AD_RotorSenPower)), ((UInt16 *)
    &(AD_RotorMainMid1)), ((UInt16 *)&(AD_RotorMainMid2)),
    &rtb_Fv_RotorMidADVol1, &rtb_Fv_RotorMidADVol2);

#endif

  /* End of Outputs for SubSystem: '<S173>/DiagRapid_RotorPower_Check' */
  /* End of Outputs for SubSystem: '<S86>/RotorCheck_Power' */

  /* Outputs for Atomic SubSystem: '<S86>/RotorCheck_Signal' */
  /* Outputs for Atomic SubSystem: '<S174>/DiagRapid_RotorSignal_Check' */
#if DIAGDIS_ROTORSIGNALREG == 0

  /* Output and update for atomic system: '<S182>/SignalCheck' */
  {
    Bool precondrtr_dkhf_m;
    Bool precondrtr_m;
    UInt16 Fv_RotorMainSinADVol_i53a_m;
    UInt16 mainsquare_ov4l_m;
    UInt16 Fv_RotorMainCosADVol_gu5x_m;
    UInt16 vsinsum_erde_m;
    UInt16 vsinoft_mt2z_m;
    UInt16 Fv_RotorSubSinADVol_hkyp_m;
    UInt16 subsquare_bs40_m;
    UInt16 Fv_RotorSubCosADVol_gja2_m;
    UInt16 vcossum_cp20_m;
    UInt16 vcosoft_lcdl_m;
    UInt16 Fv_RotorMainSinADVol_m;
    UInt16 mainsquare_m;
    UInt16 Fv_RotorMainCosADVol_m;
    UInt16 vsinsum_m;
    UInt16 vsinoft_m;
    UInt16 Fv_RotorSubSinADVol_m;
    UInt16 subsquare_m;
    UInt16 Fv_RotorSubCosADVol_m;
    UInt16 vcossum_m;
    UInt16 vcosoft_m;

    /* Outputs for Atomic SubSystem: '<S183>/RotorSignalCond1' */
    /* Inport: '<Root>/AD_RotorMainSin' incorporates:
     *  Inport: '<Root>/AD_RotorMainCos'
     *  Inport: '<Root>/AD_RotorSubCos'
     *  Inport: '<Root>/AD_RotorSubSin'
     */
    FaultDiagRapid_RotorSignalCond1(rtb_Fv_RotorMidADVol1, ((UInt16 *)
      &(AD_RotorMainSin1)), ((UInt16 *)&(AD_RotorMainCos1)), ((UInt16 *)
      &(AD_RotorSubSin1)), ((UInt16 *)&(AD_RotorSubCos1)), &precondrtr_dkhf_m,
      &Fv_RotorMainSinADVol_i53a_m, &mainsquare_ov4l_m,
      &Fv_RotorMainCosADVol_gu5x_m, &vsinsum_erde_m, &vsinoft_mt2z_m,
      &Fv_RotorSubSinADVol_hkyp_m, &subsquare_bs40_m,
      &Fv_RotorSubCosADVol_gja2_m, &vcossum_cp20_m, &vcosoft_lcdl_m);

    /* End of Outputs for SubSystem: '<S183>/RotorSignalCond1' */

    /* Chart: '<S183>/RotorSignalDiag1' */
    /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag1 */
    /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag1 */
    if (((UInt32)
         FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_active_c60_FaultDiagRapid)
        == 0U) {
      /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag1 */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_active_c60_FaultDiagRapid
        = 1;

      /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag1 */
      /* Transition: '<S187>:1525' */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c60_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_cyuj;
    } else if (((UInt32)
                FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c60_FaultDiagRapid)
               == FaultDiagRapid_IN_Diag_ml4k) {
      /* During 'Diag': '<S187>:1463' */
      if (!precondrtr_dkhf_m) {
        /* Transition: '<S187>:1462' */
        /* Exit Internal 'Diag': '<S187>:1463' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c60_FaultDiagRapid =
          FaultDiagRapid_IN_Wait_cyuj;
      } else {
        FaultDiagRapid_SinRange(&Fv_RotorMainSinADVol_i53a_m,
          &Fv_RotorSubSinADVol_hkyp_m);
        FaultDiagRapid_SinOffset(&vsinsum_erde_m, &vsinoft_mt2z_m);
        FaultDiagRapid_CosRange(&Fv_RotorMainCosADVol_gu5x_m,
          &Fv_RotorSubCosADVol_gja2_m);
        FaultDiagRapid_CosOffset(&vcossum_cp20_m, &vcosoft_lcdl_m);
        FaultDiagRapid_Lotus(&mainsquare_ov4l_m, &subsquare_bs40_m);
      }
    } else {
      /* During 'Wait': '<S187>:1524' */
      if (precondrtr_dkhf_m) {
        /* Transition: '<S187>:1461' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c60_FaultDiagRapid =
          FaultDiagRapid_IN_Diag_ml4k;

        /* Entry Internal 'Diag': '<S187>:1463' */
        FaultDiag_enter_atomic_SinRange();
        FaultDia_enter_atomic_SinOffset();
        FaultDiag_enter_atomic_CosRange();
        FaultDia_enter_atomic_CosOffset();
        FaultDiagRap_enter_atomic_Lotus();
      }
    }

    /* End of Chart: '<S183>/RotorSignalDiag1' */

    /* Outputs for Atomic SubSystem: '<S183>/RotorSignalCond2' */
    /* Inport: '<Root>/AD_RotorMainSin2' incorporates:
     *  Inport: '<Root>/AD_RotorMainCos2'
     *  Inport: '<Root>/AD_RotorSubCos2'
     *  Inport: '<Root>/AD_RotorSubSin2'
     */
    FaultDiagRapid_RotorSignalCond1(rtb_Fv_RotorMidADVol2, ((UInt16 *)
      &(AD_RotorMainSin2)), ((UInt16 *)&(AD_RotorMainCos2)), ((UInt16 *)
      &(AD_RotorSubSin2)), ((UInt16 *)&(AD_RotorSubCos2)), &precondrtr_m,
      &Fv_RotorMainSinADVol_m, &mainsquare_m, &Fv_RotorMainCosADVol_m,
      &vsinsum_m, &vsinoft_m, &Fv_RotorSubSinADVol_m, &subsquare_m,
      &Fv_RotorSubCosADVol_m, &vcossum_m, &vcosoft_m);

    /* End of Outputs for SubSystem: '<S183>/RotorSignalCond2' */

    /* Chart: '<S183>/RotorSignalDiag2' */
    /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag2 */
    /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag2 */
    if (((UInt32)
         FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_active_c5_FaultDiagRapid)
        == 0U) {
      /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag2 */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_active_c5_FaultDiagRapid
        = 1;

      /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_RotorCheck/RotorCheck_Signal/DiagRapid_RotorSignal_Check/SignalCheck/RotorSignalDiag2 */
      /* Transition: '<S188>:1525' */
      FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c5_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_cyuj;
    } else if (((UInt32)
                FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c5_FaultDiagRapid)
               == FaultDiagRapid_IN_Diag_ml4k) {
      /* During 'Diag': '<S188>:1463' */
      if (!precondrtr_m) {
        /* Transition: '<S188>:1462' */
        /* Exit Internal 'Diag': '<S188>:1463' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c5_FaultDiagRapid =
          FaultDiagRapid_IN_Wait_cyuj;
      } else {
        FaultDiagRapid_SinRange_afap(&Fv_RotorMainSinADVol_m,
          &Fv_RotorSubSinADVol_m);
        FaultDiagRapid_SinOffset_k3lv(&vsinsum_m, &vsinoft_m);
        FaultDiagRapid_CosRange_lxvo(&Fv_RotorMainCosADVol_m,
          &Fv_RotorSubCosADVol_m);
        FaultDiagRapid_CosOffset_czxq(&vcossum_m, &vcosoft_m);
        FaultDiagRapid_Lotus_dln4(&mainsquare_m, &subsquare_m);
      }
    } else {
      /* During 'Wait': '<S188>:1524' */
      if (precondrtr_m) {
        /* Transition: '<S188>:1461' */
        FaultDiagRapidrtDW.SignalCheck_pci3.bitsForTID0.is_c5_FaultDiagRapid =
          FaultDiagRapid_IN_Diag_ml4k;

        /* Entry Internal 'Diag': '<S188>:1463' */
        Faul_enter_atomic_SinRange_czdq();
        Fau_enter_atomic_SinOffset_ndfd();
        Faul_enter_atomic_CosRange_jwzx();
        Fau_enter_atomic_CosOffset_lz5f();
        FaultDi_enter_atomic_Lotus_awzk();
      }
    }

    /* End of Chart: '<S183>/RotorSignalDiag2' */
  }

#endif

  /* End of Outputs for SubSystem: '<S174>/DiagRapid_RotorSignal_Check' */
  /* End of Outputs for SubSystem: '<S86>/RotorCheck_Signal' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
