/*
 * File: FaultDiagRapid_MCU.c
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

#include "FaultDiagRapid_MCU.h"

/* Include model header file for global data */
#include "FaultDiagRapid.h"
#include "FaultDiagRapid_private.h"
#include "asr_s32.h"

/* Named constants for Chart: '<S92>/MCUCoreDiag' */
#define FaultDi_IN_NO_ACTIVE_CHILD_cjjq ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_es1v    ((UInt8)1U)
#define FaultDiagRapid_IN_Fault_j1z0   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_fnwy  ((UInt8)2U)
#define FaultDiagRapid_IN_Stop_p1y3    ((UInt8)2U)
#if DIAGDIS_MCUEPSCONTROL == 0

/* Forward declaration for local functions */
#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRa_softTorqueCalcCheck(void);

#endif

#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRapi_softOutLimitCheck(void);

#endif

#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRa_softCompAssistCheck(void);

#endif

#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRapid_EPSDiagMask(void);

#endif

#if DIAGDIS_MCUEPSCONTROL == 0

static void enter_atomic_softTorqueCalcChec(void);

#endif

#if DIAGDIS_MCUEPSCONTROL == 0

static void enter_atomic_softOutLimitCheck(void);

#endif

#if DIAGDIS_MCUEPSCONTROL == 0

static void enter_atomic_softCompAssistChec(void);

#endif
#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

/* Forward declaration for local functions */
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRa_softRotorAngleCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_softKalmanCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRap_softClarkParkCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRa_softClarkParkCheck1(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softRotorAngleChec(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRap_softInnerCompCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void Fa_enter_atomic_softKalmanCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_softPIoutCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softClarkParkCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_softPIoutCheck1(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softClarkPark_psmj(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRap_softVoltLimitCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softInnerCompCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_MotorDiagMask(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void Fau_enter_atomic_softPIoutCheck(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void Fa_enter_atomic_softPIoutCheck1(void);

#endif

#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softVoltLimitCheck(void);

#endif
#endif

#if DIAGDIS_MCUVICECOMM == 0

/* Forward declaration for local functions */
#if DIAGDIS_MCUVICECOMM == 0

static void FaultDiagRapid_ViceCommTimeOut(const Bool *enbcond_g, const Bool
  *commout_g);

#endif

#if DIAGDIS_MCUVICECOMM == 0

static void FaultDiagRapi_ViceMonitorReport(void);

#endif

#if DIAGDIS_MCUVICECOMM == 0

static void Fa_enter_atomic_ViceCommTimeOut(void);

#endif
#endif

/* System reset for atomic system: '<S84>/MCUCheck_Core' */
void FaultDiagRa_MCUCheck_Core_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S87>/Diag_MCUCore_Check' */
#if DIAGDIS_MCUCORE == 0

  /* Reset conditions for atomic system: '<S91>/CoreCheck' */

  /* SystemReset for Chart: '<S92>/MCUCoreDiag' */
  FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_Diag =
    FaultDi_IN_NO_ACTIVE_CHILD_cjjq;
  FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_active_c30_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_c30_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_cjjq;
  FaultDiagRapidrtDW.CoreCheck.IV_TimeWin = 0U;

#endif

  /* End of SystemReset for SubSystem: '<S87>/Diag_MCUCore_Check' */
}

/* Output and update for atomic system: '<S84>/MCUCheck_Core' */
void FaultDiagRapid_MCUCheck_Core(void)
{
  /* Outputs for Atomic SubSystem: '<S87>/Diag_MCUCore_Check' */
#if DIAGDIS_MCUCORE == 0

  /* Output and update for atomic system: '<S91>/CoreCheck' */
  {
    UInt16 rtb_Fv_InerVccADVol;
    UInt16 rtb_Fv_InerTmpADVol;

    /* Outputs for Atomic SubSystem: '<S92>/MCUCoreCond' */
    /* Product: '<S94>/Product' incorporates:
     *  Constant: '<S94>/Constant'
     *  Inport: '<Root>/AD_InterVolt1d2'
     */
    rtb_Fv_InerVccADVol = (UInt16)((((UInt32)AD_InterVolt1d2) * ((UInt32)
      ((UInt16)MACRO_AV_AD2VOL))) >> 6);

    /* Product: '<S94>/Product1' incorporates:
     *  Constant: '<S94>/Constant'
     *  Inport: '<Root>/AD_InterMCUTemp'
     */
    rtb_Fv_InerTmpADVol = (UInt16)((((UInt32)((UInt16)MACRO_AV_AD2VOL)) *
      ((UInt32)AD_InterMCUTemp)) >> 6);

    /* End of Outputs for SubSystem: '<S92>/MCUCoreCond' */

    /* Chart: '<S92>/MCUCoreDiag' incorporates:
     *  DataStoreRead: '<S96>/Data Store Read'
     *  DataStoreRead: '<S97>/Data Store Read'
     *  DataTypeConversion: '<S96>/Data Type Conversion2'
     *  Product: '<S96>/Product'
     *  Selector: '<S96>/Selector'
     *  Selector: '<S97>/Selector'
     */
    /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreDiag */
    /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreDiag */
    if (((UInt32)
         FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_active_c30_FaultDiagRapid) ==
        0U) {
      /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreDiag */
      FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_active_c30_FaultDiagRapid = 1;

      /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_Core/Diag_MCUCore_Check/CoreCheck/MCUCoreDiag */
      /* Transition: '<S95>:1150' */
      FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_c30_FaultDiagRapid =
        FaultDiagRapid_IN_Stop_p1y3;
    } else if (((UInt32)
                FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_c30_FaultDiagRapid) ==
               FaultDiagRapid_IN_Diag_es1v) {
      /* During 'Diag': '<S95>:1138' */
      if ((Fv_ErrDiagStatus[DTC_MCUcheck_PerOthers] >= FailureDiag_Err) ||
          (Fv_SysPower < Cal_Power_LowReset)) {
        /* Transition: '<S95>:1145' */
        /* Exit Internal 'Diag': '<S95>:1138' */
        FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_Diag =
          FaultDi_IN_NO_ACTIVE_CHILD_cjjq;
        FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_c30_FaultDiagRapid =
          FaultDiagRapid_IN_Stop_p1y3;
      } else if (((UInt32)FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_Diag) ==
                 FaultDiagRapid_IN_Fault_j1z0) {
        /* During 'Fault': '<S95>:1142' */
        if ((((rtb_Fv_InerVccADVol >= ((UInt16)MACRO_MR_INERVCC_MIN)) &&
              (rtb_Fv_InerVccADVol <= ((UInt16)MACRO_MR_INERVCC_MAX))) &&
             (rtb_Fv_InerTmpADVol >= ((UInt16)MACRO_MR_INERTMP_MIN))) &&
            (rtb_Fv_InerTmpADVol <= ((UInt16)MACRO_MR_INERTMP_MAX))) {
          /* Transition: '<S95>:1151' */
          FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Normal_fnwy;
        } else {
          /* Transition: '<S95>:1144' */
          if (((Int32)FaultDiagRapidrtDW.CoreCheck.IV_TimeWin) > 0) {
            /* Transition: '<S95>:1146' */
            /* Transition: '<S95>:1157' */
            FaultDiagRapidrtDW.CoreCheck.IV_TimeWin = (UInt16)((Int32)(((Int32)
              FaultDiagRapidrtDW.CoreCheck.IV_TimeWin) - 1));

            /* Transition: '<S95>:1159' */
          } else {
            /* Outputs for Function Call SubSystem: '<S95>/DTC_Ctrl_Enabled' */
            /* Transition: '<S95>:1139' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S95>:1167' */
            Fv_ErrDiagStatus[DTC_MCUcheck_PerOthers] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MCUcheck_PerOthers].Enabled) * ((UInt32)FailureDiag_Err));

            /* End of Outputs for SubSystem: '<S95>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S95>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S95>:1163' */
            Fv_FaultClass_MCU = (UInt16)SetU16Fault(Fv_FaultClass_MCU, 2,
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MCUcheck_PerOthers].Enabled);

            /* End of Outputs for SubSystem: '<S95>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S95>:1140' */
        if ((((rtb_Fv_InerVccADVol < ((UInt16)MACRO_MR_INERVCC_MIN)) ||
              (rtb_Fv_InerVccADVol > ((UInt16)MACRO_MR_INERVCC_MAX))) ||
             (rtb_Fv_InerTmpADVol < ((UInt16)MACRO_MR_INERTMP_MIN))) ||
            (rtb_Fv_InerTmpADVol > ((UInt16)MACRO_MR_INERTMP_MAX))) {
          /* Transition: '<S95>:1137' */
          FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Fault_j1z0;

          /* Entry 'Fault': '<S95>:1142' */
          FaultDiagRapidrtDW.CoreCheck.IV_TimeWin = ((UInt16)
            MACRO_TP_REGULAR_VCCTIME);
        }
      }
    } else {
      /* During 'Stop': '<S95>:1147' */
      if ((Fv_ErrDiagStatus[DTC_MCUcheck_PerOthers] < FailureDiag_Err) &&
          (Fv_SysPower >= Cal_Power_LowReset)) {
        /* Transition: '<S95>:1141' */
        FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_c30_FaultDiagRapid =
          FaultDiagRapid_IN_Diag_es1v;

        /* Entry Internal 'Diag': '<S95>:1138' */
        /* Transition: '<S95>:1149' */
        FaultDiagRapidrtDW.CoreCheck.bitsForTID0.is_Diag =
          FaultDiagRapid_IN_Normal_fnwy;
      }
    }

    /* End of Chart: '<S92>/MCUCoreDiag' */
  }

#endif

  /* End of Outputs for SubSystem: '<S87>/Diag_MCUCore_Check' */
}

/* Function for Chart: '<S99>/EPSCtrlCheck' */
#if DIAGDIS_MCUEPSCONTROL == 0
#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRa_softTorqueCalcCheck(void)
{
  Int16 outter_assup_e;
  Int16 outter_assdown_e;
  Int32 Fv_ErrDiagStatus_tmp_e;

  /* During 'softTorqueCalcCheck': '<S100>:1594' */
  /* Transition: '<S100>:1616' */
  if (Fv_StrTrqP > ((Int16)MACRO_MR_OUTERMAX_SWHTRQ)) {
    /* Transition: '<S100>:1618' */
    /* Transition: '<S100>:1620' */
    outter_assup_e = ((Int16)MACRO_TL_MAXTRQLIMIT);
    outter_assdown_e = (Int16)(-((Int16)MACRO_MR_OUTERMAX_SWHASST));

    /* Transition: '<S100>:1629' */
    /* Transition: '<S100>:1630' */
  } else {
    /* Transition: '<S100>:1622' */
    if (Fv_StrTrqP < (-((Int16)MACRO_MR_OUTERMAX_SWHTRQ))) {
      /* Transition: '<S100>:1624' */
      /* Transition: '<S100>:1626' */
      outter_assup_e = ((Int16)MACRO_MR_OUTERMAX_SWHASST);
      outter_assdown_e = (Int16)(-((Int16)MACRO_TL_MAXTRQLIMIT));

      /* Transition: '<S100>:1630' */
    } else {
      /* Transition: '<S100>:1628' */
      outter_assup_e = ((Int16)MACRO_MR_OUTERMAX_SWHASST);
      outter_assdown_e = (Int16)(-((Int16)MACRO_MR_OUTERMAX_SWHASST));
    }
  }

  /* Transition: '<S100>:1632' */
  if ((Tv_BasicAsisTrq_Primed > outter_assup_e) || (Tv_BasicAsisTrq_Primed <
       outter_assdown_e)) {
    /* Transition: '<S100>:1635' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_asscnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S100>:1637' */
      /* Transition: '<S100>:1639' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_asscnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_asscnt) + 1));

      /* Transition: '<S100>:1644' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* Selector: '<S101>/Selector' */
      /* Transition: '<S100>:1641' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus_tmp_e = DTC_MCUcheck_AssistCtrl;

      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_e)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_e].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 10, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1645' */
  } else {
    /* Transition: '<S100>:1643' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_asscnt = 0U;
  }

  /* Transition: '<S100>:1647' */
  if ((Fv_StrTrqP > ((Int16)MACRO_TQ_MAX_TORQM)) || (Fv_StrTrqP < (-((Int16)
         MACRO_TQ_MAX_TORQM)))) {
    /* Transition: '<S100>:1649' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_trqcnt < ((UInt16)
         MACRO_MR_OUTERMAX_TRQTIMER)) {
      /* Transition: '<S100>:1651' */
      /* Transition: '<S100>:1653' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_trqcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_trqcnt) + 1));

      /* Transition: '<S100>:1658' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      /* Transition: '<S100>:1655' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus[DTC_MCUcheck_AssistCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl]
        .Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 11, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1659' */
  } else {
    /* Transition: '<S100>:1657' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_trqcnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S99>/EPSCtrlCheck' */
#if DIAGDIS_MCUEPSCONTROL == 0
#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRapi_softOutLimitCheck(void)
{
  Int16 outter_limitup_e;
  Int16 outter_limitdown_e;
  Int32 Fv_ErrDiagStatus_tmp_e;

  /* During 'softOutLimitCheck': '<S100>:1673' */
  /* Transition: '<S100>:1697' */
  if ((Fv_NewTrqTargetLimit > ((Int16)MACRO_TL_MAXTRQLIMIT)) ||
      (Fv_NewTrqTargetLimit < (-((Int16)MACRO_TL_MAXTRQLIMIT)))) {
    /* Transition: '<S100>:1699' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_tgtcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S100>:1703' */
      /* Transition: '<S100>:1705' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_tgtcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_tgtcnt) + 1));

      /* Transition: '<S100>:1710' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* Selector: '<S101>/Selector' */
      /* Transition: '<S100>:1709' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus_tmp_e = DTC_MCUcheck_AssistCtrl;

      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_e)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_e].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 12, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1711' */
  } else {
    /* Transition: '<S100>:1707' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_tgtcnt = 0U;
  }

  /* Transition: '<S100>:1713' */
  if (Fv_StrTrq0 <= (-((Int16)MACRO_MR_OUTERMAX_LIMITTRQ))) {
    /* Transition: '<S100>:1715' */
    /* Transition: '<S100>:1717' */
    outter_limitup_e = ((Int16)MACRO_MR_OUTERMAX_SWHASST);
    outter_limitdown_e = (Int16)(-((Int16)MACRO_TL_MAXTRQLIMIT));

    /* Transition: '<S100>:1719' */
    /* Transition: '<S100>:1728' */
    /* Transition: '<S100>:1737' */
    /* Transition: '<S100>:1748' */
    /* Transition: '<S100>:1751' */
    /* Transition: '<S100>:1752' */
  } else {
    /* Transition: '<S100>:1721' */
    if (Fv_StrTrq0 < (-((Int16)MACRO_MR_OUTERMAX_SWHTRQ))) {
      /* Transition: '<S100>:1723' */
      /* Transition: '<S100>:1725' */
      outter_limitup_e = ((Int16)MACRO_MR_OUTERMAX_SWHASST);
      outter_limitdown_e = (Int16)asr_s32((((Int32)((Int16)
        MACRO_MR_OUTERMAX_LIMITGAIN)) * (((Int32)Fv_StrTrq0) + ((Int32)((Int16)
        MACRO_MR_OUTERMAX_SWHTRQ)))) - (((Int32)((Int16)
        MACRO_MR_OUTERMAX_SWHASST)) * 8), 3U);

      /* Transition: '<S100>:1727' */
      /* Transition: '<S100>:1737' */
      /* Transition: '<S100>:1748' */
      /* Transition: '<S100>:1751' */
      /* Transition: '<S100>:1752' */
    } else {
      /* Transition: '<S100>:1730' */
      if (Fv_StrTrq0 <= ((Int16)MACRO_MR_OUTERMAX_SWHTRQ)) {
        /* Transition: '<S100>:1732' */
        /* Transition: '<S100>:1734' */
        outter_limitup_e = ((Int16)MACRO_MR_OUTERMAX_SWHASST);
        outter_limitdown_e = (Int16)(-((Int16)MACRO_MR_OUTERMAX_SWHASST));

        /* Transition: '<S100>:1736' */
        /* Transition: '<S100>:1748' */
        /* Transition: '<S100>:1751' */
        /* Transition: '<S100>:1752' */
      } else {
        /* Transition: '<S100>:1739' */
        if (Fv_StrTrq0 < ((Int16)MACRO_MR_OUTERMAX_LIMITTRQ)) {
          /* Transition: '<S100>:1741' */
          /* Transition: '<S100>:1743' */
          outter_limitup_e = (Int16)asr_s32((((Int32)((Int16)
            MACRO_MR_OUTERMAX_LIMITGAIN)) * (((Int32)Fv_StrTrq0) - ((Int32)
            ((Int16)MACRO_MR_OUTERMAX_SWHTRQ)))) + (((Int32)((Int16)
            MACRO_MR_OUTERMAX_SWHASST)) * 8), 3U);
          outter_limitdown_e = (Int16)(-((Int16)MACRO_MR_OUTERMAX_SWHASST));

          /* Transition: '<S100>:1752' */
        } else {
          /* Transition: '<S100>:1750' */
          outter_limitup_e = ((Int16)MACRO_TL_MAXTRQLIMIT);
          outter_limitdown_e = (Int16)(-((Int16)MACRO_MR_OUTERMAX_SWHASST));
        }
      }
    }
  }
#if 0
  /* Transition: '<S100>:1754' */
  if ((Fv_TCL_OpenLoopCompTrq > outter_limitup_e) || (Fv_TCL_OpenLoopCompTrq <
       outter_limitdown_e)) {
    /* Transition: '<S100>:1756' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_lmtcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S100>:1759' */
      /* Transition: '<S100>:1761' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_lmtcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_lmtcnt) + 1));

      /* Transition: '<S100>:1766' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      /* Transition: '<S100>:1765' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus[DTC_MCUcheck_AssistCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl]
        .Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 13, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1767' */
  } else {
    /* Transition: '<S100>:1763' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_lmtcnt = 0U;
  }
#endif
}

#endif
#endif

/* Function for Chart: '<S99>/EPSCtrlCheck' */
#if DIAGDIS_MCUEPSCONTROL == 0
#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRa_softCompAssistCheck(void)
{
  Int32 Fv_ErrDiagStatus_tmp_e;

  /* During 'softCompAssistCheck': '<S100>:1779' */
  /* Transition: '<S100>:1797' */
  if ((Fv_FriCompTrq > Cal_FC_MaxTorq) || (Fv_FriCompTrq < (-Cal_FC_MaxTorq))) {
    /* Transition: '<S100>:1789' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_frccnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S100>:1791' */
      /* Transition: '<S100>:1793' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_frccnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_frccnt) + 1));

      /* Transition: '<S100>:1798' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* Selector: '<S101>/Selector' */
      /* Transition: '<S100>:1795' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus_tmp_e = DTC_MCUcheck_AssistCtrl;

      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_e)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_e].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 14, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1801' */
  } else {
    /* Transition: '<S100>:1800' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_frccnt = 0U;
  }

  /* Transition: '<S100>:1815' */
  if ((Fv_DampCompTrq > Cal_DC_MaxTorq) || (Fv_DampCompTrq < (-Cal_DC_MaxTorq)))
  {
    /* Transition: '<S100>:1809' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_dmpcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S100>:1808' */
      /* Transition: '<S100>:1812' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_dmpcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_dmpcnt) + 1));

      /* Transition: '<S100>:1813' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      /* Transition: '<S100>:1806' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus[DTC_MCUcheck_AssistCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl]
        .Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 15, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1804' */
  } else {
    /* Transition: '<S100>:1803' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_dmpcnt = 0U;
  }

  /* Transition: '<S100>:1816' */
  if ((Fv_InertiaCompTrq > Cal_IC_MaxTorq) || (Fv_InertiaCompTrq <
       (-Cal_IC_MaxTorq))) {
    /* Transition: '<S100>:1828' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_inacnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S100>:1829' */
      /* Transition: '<S100>:1824' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_inacnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_inacnt) + 1));

      /* Transition: '<S100>:1818' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      /* Transition: '<S100>:1827' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus[DTC_MCUcheck_AssistCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl]
        .Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 16, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1825' */
  } else {
    /* Transition: '<S100>:1821' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_inacnt = 0U;
  }

  /* Transition: '<S100>:1841' */
  if ((Fv_ActiveReturnCompTrq > Cal_AR_MaxTorq) || (Fv_ActiveReturnCompTrq <
       (-Cal_AR_MaxTorq))) {
    /* Transition: '<S100>:1835' */
    if (FaultDiagRapidrtDW.EPSControlCheck.outter_rtncnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S100>:1838' */
      /* Transition: '<S100>:1839' */
      FaultDiagRapidrtDW.EPSControlCheck.outter_rtncnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.EPSControlCheck.outter_rtncnt) + 1));

      /* Transition: '<S100>:1843' */
    } else {
      /* Outputs for Function Call SubSystem: '<S100>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S101>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S101>/Data Store Read'
       *  Product: '<S101>/Product'
       *  Selector: '<S101>/Selector'
       */
      /* Transition: '<S100>:1830' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S100>:1869' */
      Fv_ErrDiagStatus[DTC_MCUcheck_AssistCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl]
        .Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S100>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S100>/getDTCEnabled' */
      /* Selector: '<S102>/Selector' incorporates:
       *  DataStoreRead: '<S102>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S100>:1872' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 17, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_AssistCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S100>/getDTCEnabled' */
    }

    /* Transition: '<S100>:1833' */
  } else {
    /* Transition: '<S100>:1836' */
    FaultDiagRapidrtDW.EPSControlCheck.outter_rtncnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S99>/EPSCtrlCheck' */
#if DIAGDIS_MCUEPSCONTROL == 0
#if DIAGDIS_MCUEPSCONTROL == 0

static void FaultDiagRapid_EPSDiagMask(void)
{
  /* During 'EPSDiagMask': '<S100>:1299' */
  /* Transition: '<S100>:1171' */
  if ((Fv_FaultClass_MCUcheck_Soft & (~DiagSoftMask)) > 0U) {
    /* Transition: '<S100>:1172' */
    /* Transition: '<S100>:1487' */
    Fv_FaultClass_MCU = (UInt16)SetU16Varit(Fv_FaultClass_MCU, 6);

    /* Transition: '<S100>:1489' */
  } else {
    /* Transition: '<S100>:1173' */
  }
}

#endif
#endif

/* Function for Chart: '<S99>/EPSCtrlCheck' */
#if DIAGDIS_MCUEPSCONTROL == 0
#if DIAGDIS_MCUEPSCONTROL == 0

static void enter_atomic_softTorqueCalcChec(void)
{
  /* Entry 'softTorqueCalcCheck': '<S100>:1594' */
  FaultDiagRapidrtDW.EPSControlCheck.outter_asscnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_trqcnt = 0U;
}

#endif
#endif

/* Function for Chart: '<S99>/EPSCtrlCheck' */
#if DIAGDIS_MCUEPSCONTROL == 0
#if DIAGDIS_MCUEPSCONTROL == 0

static void enter_atomic_softOutLimitCheck(void)
{
  /* Entry 'softOutLimitCheck': '<S100>:1673' */
  FaultDiagRapidrtDW.EPSControlCheck.outter_tgtcnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_lmtcnt = 0U;
}

#endif
#endif

/* Function for Chart: '<S99>/EPSCtrlCheck' */
#if DIAGDIS_MCUEPSCONTROL == 0
#if DIAGDIS_MCUEPSCONTROL == 0

static void enter_atomic_softCompAssistChec(void)
{
  /* Entry 'softCompAssistCheck': '<S100>:1779' */
  FaultDiagRapidrtDW.EPSControlCheck.outter_frccnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_dmpcnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_inacnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_rtncnt = 0U;
}

#endif
#endif

/* System reset for atomic system: '<S84>/MCUCheck_EPSControl' */
void Fault_MCUCheck_EPSControl_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S88>/Diag_MCUEPSControl_Check' */
#if DIAGDIS_MCUEPSCONTROL == 0

  /* Reset conditions for atomic system: '<S98>/EPSControlCheck' */

  /* SystemReset for Chart: '<S99>/EPSCtrlCheck' */
  FaultDiagRapidrtDW.EPSControlCheck.bitsForTID0.is_active_c43_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.EPSControlCheck.outter_asscnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_trqcnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_tgtcnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_lmtcnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_frccnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_dmpcnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_inacnt = 0U;
  FaultDiagRapidrtDW.EPSControlCheck.outter_rtncnt = 0U;

#endif

  /* End of SystemReset for SubSystem: '<S88>/Diag_MCUEPSControl_Check' */
}

/* Output and update for atomic system: '<S84>/MCUCheck_EPSControl' */
void FaultDiagRa_MCUCheck_EPSControl(void)
{
  /* Outputs for Atomic SubSystem: '<S88>/Diag_MCUEPSControl_Check' */
#if DIAGDIS_MCUEPSCONTROL == 0

  /* Output and update for atomic system: '<S98>/EPSControlCheck' */

  /* Chart: '<S99>/EPSCtrlCheck' */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck/EPSCtrlCheck */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck/EPSCtrlCheck */
  if (((UInt32)
       FaultDiagRapidrtDW.EPSControlCheck.bitsForTID0.is_active_c43_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck/EPSCtrlCheck */
    FaultDiagRapidrtDW.EPSControlCheck.bitsForTID0.is_active_c43_FaultDiagRapid =
      1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_EPSControl/Diag_MCUEPSControl_Check/EPSControlCheck/EPSCtrlCheck */
    enter_atomic_softTorqueCalcChec();
    enter_atomic_softOutLimitCheck();
    enter_atomic_softCompAssistChec();
  } else {
    FaultDiagRa_softTorqueCalcCheck();
    FaultDiagRapi_softOutLimitCheck();
    FaultDiagRa_softCompAssistCheck();
    FaultDiagRapid_EPSDiagMask();
  }

  /* End of Chart: '<S99>/EPSCtrlCheck' */
#endif

  /* End of Outputs for SubSystem: '<S88>/Diag_MCUEPSControl_Check' */
}

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRa_softRotorAngleCheck(void)
{
  Int16 inner_cos_g;
  Int16 inner_sin_g;
  Int32 inner_pos_g;

  /* During 'softRotorAngleCheck': '<S105>:1178' */
  /* Transition: '<S105>:1303' */
  if (Fv_SysPower >= ((Int16)MACRO_RESOLVERPOWER_MIN)) {
    /* Transition: '<S105>:1305' */
    /* Transition: '<S105>:1307' */
    inner_cos_g = Fv_cos_eang;
    inner_sin_g = Fv_sin_eang;
    inner_pos_g = (Int32)Fv_Rotor_pos_elcdomin;

    /* Transition: '<S105>:1310' */
  } else {
    /* Transition: '<S105>:1309' */
    inner_cos_g = 0;
    inner_sin_g = 0;
    inner_pos_g = 0;
  }

  /* Transition: '<S105>:1312' */
  if (((inner_sin_g >= 0) && ((((inner_cos_g >= 0) && (inner_pos_g >=
           (-MACRO_MR_INERANG_D))) && (inner_pos_g <= (MACRO_MBC_PI_2 +
           MACRO_MR_INERANG_D))) || ((inner_cos_g <= 0) && (((inner_pos_g >=
            (MACRO_MBC_PI_2 - MACRO_MR_INERANG_D)) && (inner_pos_g <=
            MACRO_MBC_PI)) || ((inner_pos_g > (-MACRO_MBC_PI)) && (inner_pos_g <=
            (MACRO_MR_INERANG_D - MACRO_MBC_PI))))))) || ((inner_sin_g <= 0) &&
       (((inner_cos_g <= 0) && (((inner_pos_g >= (-MACRO_MBC_PI)) &&
           (inner_pos_g <= (MACRO_MR_INERANG_D - MACRO_MBC_PI_2))) ||
          ((inner_pos_g <= MACRO_MBC_PI) && (inner_pos_g >= (MACRO_MBC_PI -
             MACRO_MR_INERANG_D))))) || (((inner_cos_g >= 0) && (inner_pos_g >=
           ((-MACRO_MBC_PI_2) - MACRO_MR_INERANG_D))) && (inner_pos_g <=
          MACRO_MR_INERANG_D))))) {
    /* Transition: '<S105>:1314' */
    if (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt) > 0) {
      /* Transition: '<S105>:1316' */
      /* Transition: '<S105>:1318' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt) - 1));
    } else {
      /* Transition: '<S105>:1320' */
      /* Transition: '<S105>:1328' */
    }

    /* Transition: '<S105>:1332' */
    /* Transition: '<S105>:1333' */
    /* Transition: '<S105>:1334' */
  } else {
    /* Transition: '<S105>:1323' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt < ((UInt16)
         MACRO_MR_INERANG_TIMER)) {
      /* Transition: '<S105>:1325' */
      /* Transition: '<S105>:1327' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt) + 2));

      /* Transition: '<S105>:1334' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1330' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      inner_pos_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(inner_pos_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[inner_pos_g].Enabled) *
        ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 0, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_softKalmanCheck(void)
{
  Int32 inner_foc_spd_g;
  Int32 inner_out_spd_g;
  Int32 inner_revdiff_g;
  Int32 inner_out_acc_g;

  /* During 'softKalmanCheck': '<S105>:1276' */
  /* Transition: '<S105>:1336' */
  /* Transition: '<S105>:1338' */
  inner_foc_spd_g = -Fv_FOC_RotorSpd;
  inner_out_spd_g = Fv_dRotorAng;
  inner_out_acc_g = Fv_ddRotorAng;
  if ((Fv_SysPower >= ((Int16)MACRO_RESOLVERPOWER_MIN)) &&
      (SysTaskResolverSmpPending)) {
    /* Transition: '<S105>:1340' */
    if (inner_foc_spd_g > Fv_dRotorAng) {
      /* Transition: '<S105>:1342' */
      /* Transition: '<S105>:1344' */
      inner_revdiff_g = inner_foc_spd_g - Fv_dRotorAng;

      /* Transition: '<S105>:1347' */
    } else {
      /* Transition: '<S105>:1346' */
      inner_revdiff_g = Fv_dRotorAng - inner_foc_spd_g;
    }

    /* Transition: '<S105>:1350' */
  } else {
    /* Transition: '<S105>:1349' */
    inner_revdiff_g = 0;
  }

  /* Transition: '<S105>:1352' */
  if (inner_revdiff_g > MACRO_MR_INERMAX_REVDIF) {
    /* Transition: '<S105>:1354' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_revcnt < ((UInt16)
         MACRO_MR_INERMAX_REVTIME)) {
      /* Transition: '<S105>:1358' */
      /* Transition: '<S105>:1360' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_revcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_revcnt) + 1));

      /* Transition: '<S105>:1363' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1362' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      inner_revdiff_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(inner_revdiff_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[inner_revdiff_g].Enabled)
        * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 1, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1364' */
  } else {
    /* Transition: '<S105>:1356' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_revcnt = 0U;
  }

  /* Transition: '<S105>:1367' */
  if ((((((inner_out_acc_g > MACRO_MR_INERMAX_ACC) || (inner_out_acc_g <
           (-MACRO_MR_INERMAX_ACC))) || (inner_out_spd_g > MACRO_MR_INERMAX_REV))
        || (inner_out_spd_g < (-MACRO_MR_INERMAX_REV))) || (inner_foc_spd_g >
        MACRO_MR_INERMAX_REV)) || (inner_foc_spd_g < (-MACRO_MR_INERMAX_REV))) {
    /* Transition: '<S105>:1369' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_acccnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1371' */
      /* Transition: '<S105>:1373' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_acccnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_acccnt) + 1));

      /* Transition: '<S105>:1376' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      /* Transition: '<S105>:1375' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus[DTC_MCUcheck_MotorCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 2, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1379' */
  } else {
    /* Transition: '<S105>:1378' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_acccnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRap_softClarkParkCheck(void)
{
  Int32 Fv_ErrDiagStatus_tmp_g;

  /* During 'softClarkParkCheck': '<S105>:1206' */
  /* Transition: '<S105>:1382' */
  /* Transition: '<S105>:1384' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud = Fv_MotorVoltage_D1;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq = Fv_MotorVoltage_Q1;
  if (!SysTaskFocResetPending1) {
    /* Transition: '<S105>:1386' */
    /* Transition: '<S105>:1388' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff = asr_s32
      ((((Fv_MotorCurrent_Dact1 * Fv_MotorCurrent_Dact1) +
         (Fv_MotorCurrent_Qact1 * Fv_MotorCurrent_Qact1)) -
        (Fv_MotorCurrent_Alpha1 * Fv_MotorCurrent_Alpha1)) -
       (Fv_MotorCurrent_Beta1 * Fv_MotorCurrent_Beta1), 7U);
    FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff = asr_s32
      ((((FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud *
          FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud) +
         (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq *
          FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq)) -
        (Fv_MotorVoltage_Alpha1 * Fv_MotorVoltage_Alpha1)) -
       (Fv_MotorVoltage_Beta1 * Fv_MotorVoltage_Beta1), 10U);

    /* Transition: '<S105>:1391' */
  } else {
    /* Transition: '<S105>:1390' */
  }

  /* Transition: '<S105>:1393' */
  if (FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff < 0) {
    /* Transition: '<S105>:1395' */
    /* Transition: '<S105>:1397' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff =
      -FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff;

    /* Transition: '<S105>:1399' */
  } else {
    /* Transition: '<S105>:1400' */
  }

  /* Transition: '<S105>:1402' */
  if (FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff < 0) {
    /* Transition: '<S105>:1404' */
    /* Transition: '<S105>:1406' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff =
      -FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff;

    /* Transition: '<S105>:1409' */
  } else {
    /* Transition: '<S105>:1408' */
  }

  /* Transition: '<S105>:1411' */
  if ((FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff >
       MACRO_MR_INERMAX_IDIF) ||
      (FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff >
       MACRO_MR_INERMAX_VDIF)) {
    /* Transition: '<S105>:1413' */
    /* Transition: '<S105>:1415' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt < ((UInt16)
         MACRO_MR_INERMAX_REVTIME)) {
      /* Transition: '<S105>:1417' */
      /* Transition: '<S105>:1419' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt) + 1));

      /* Transition: '<S105>:1426' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1423' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus_tmp_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_g].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 3, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1427' */
  } else {
    /* Transition: '<S105>:1425' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRa_softClarkParkCheck1(void)
{
  Int32 Fv_ErrDiagStatus_tmp_g;

  /* During 'softClarkParkCheck1': '<S105>:1662' */
  /* Transition: '<S105>:1683' */
  /* Transition: '<S105>:1684' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2 = Fv_MotorVoltage_D2;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2 = Fv_MotorVoltage_Q2;
  if (!SysTaskFocResetPending2) {
    /* Transition: '<S105>:1685' */
    /* Transition: '<S105>:1687' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff2 = asr_s32
      ((((Fv_MotorCurrent_Dact2 * Fv_MotorCurrent_Dact2) +
         (Fv_MotorCurrent_Qact2 * Fv_MotorCurrent_Qact2)) -
        (Fv_MotorCurrent_Alpha2 * Fv_MotorCurrent_Alpha2)) -
       (Fv_MotorCurrent_Beta2 * Fv_MotorCurrent_Beta2), 7U);
    FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff2 = asr_s32
      ((((FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2 *
          FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2) +
         (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2 *
          FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2)) -
        (Fv_MotorVoltage_Alpha2 * Fv_MotorVoltage_Alpha2)) -
       (Fv_MotorVoltage_Beta2 * Fv_MotorVoltage_Beta2), 10U);

    /* Transition: '<S105>:1688' */
  } else {
    /* Transition: '<S105>:1686' */
  }

  /* Transition: '<S105>:1689' */
  if (FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff2 < 0) {
    /* Transition: '<S105>:1690' */
    /* Transition: '<S105>:1692' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff2 =
      -FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff2;

    /* Transition: '<S105>:1693' */
  } else {
    /* Transition: '<S105>:1691' */
  }

  /* Transition: '<S105>:1694' */
  if (FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff2 < 0) {
    /* Transition: '<S105>:1695' */
    /* Transition: '<S105>:1697' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff2 =
      -FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff2;

    /* Transition: '<S105>:1698' */
  } else {
    /* Transition: '<S105>:1696' */
  }

  /* Transition: '<S105>:1699' */
  if ((FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff2 >
       MACRO_MR_INERMAX_IDIF) ||
      (FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff2 >
       MACRO_MR_INERMAX_VDIF)) {
    /* Transition: '<S105>:1700' */
    /* Transition: '<S105>:1702' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt2 < ((UInt16)
         MACRO_MR_INERMAX_REVTIME)) {
      /* Transition: '<S105>:1703' */
      /* Transition: '<S105>:1705' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt2 = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt2) + 1));

      /* Transition: '<S105>:1707' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1704' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus_tmp_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_g].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 3, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1706' */
  } else {
    /* Transition: '<S105>:1701' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt2 = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softRotorAngleChec(void)
{
  /* Entry 'softRotorAngleCheck': '<S105>:1178' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt = 0U;
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRap_softInnerCompCheck(void)
{
  Int32 tmp_g;
  Int32 tmp_ccuf;
  Int32 tmp_msyc;
  Int32 tmp_e1f4;
  Int32 tmp_f0u4;
  Int32 tmp_f20t;
  Int32 tmp_ds2y;
  Int32 tmp_joo2;
  Int32 Fv_ErrDiagStatus_tmp_g;

  /* During 'softInnerCompCheck': '<S105>:1239' */
  /* Transition: '<S105>:1443' */
  /* Transition: '<S105>:1429' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit = Fv_PowerSqrt3INV;
  tmp_g = Fv_comp_current_iq;
  tmp_ccuf = Fv_comp_current_id;
  tmp_msyc = Fv_comp_voltage_rq;
  tmp_e1f4 = Fv_comp_voltage_rd;
  tmp_f0u4 = Fv_comp_voltage_iq;
  tmp_f20t = Fv_comp_voltage_id;
  tmp_ds2y = Fv_comp_voltage_eq;
  tmp_joo2 = Fv_comp_voltage_ed;
  if ((((Fv_MotorCurrent_Daim1 > MACRO_MAC_IDFW_CURRENT_BK_MAX) ||
        (Fv_MotorCurrent_Daim1 < MACRO_MAC_IDFW_CURRENT_LIMIT)) ||
       (Fv_MotorCurrent_Daim2 > MACRO_MAC_IDFW_CURRENT_BK_MAX)) ||
      (Fv_MotorCurrent_Daim2 < MACRO_MAC_IDFW_CURRENT_LIMIT)) {
    /* Transition: '<S105>:1431' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_wkfcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1435' */
      /* Transition: '<S105>:1437' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_wkfcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_wkfcnt) + 1));

      /* Transition: '<S105>:1440' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1439' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus_tmp_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_g].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 4, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1441' */
  } else {
    /* Transition: '<S105>:1433' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_wkfcnt = 0U;
  }

  /* Transition: '<S105>:1445' */
  if ((FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit <
       MACRO_MR_INERBRG_MIN) ||
      (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit >
       MACRO_MR_INERBRG_MAX)) {
    /* Transition: '<S105>:1447' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_brgcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1449' */
      /* Transition: '<S105>:1451' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_brgcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_brgcnt) + 1));

      /* Transition: '<S105>:1454' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      /* Transition: '<S105>:1453' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus[DTC_MCUcheck_MotorCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 5, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1457' */
  } else {
    /* Transition: '<S105>:1456' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_brgcnt = 0U;
  }

  /* Transition: '<S105>:1459' */
  if (tmp_g < 0) {
    tmp_g = -tmp_g;
  }

  if (tmp_ccuf < 0) {
    tmp_ccuf = -tmp_ccuf;
  }

  if (tmp_msyc < 0) {
    tmp_msyc = -tmp_msyc;
  }

  if (tmp_e1f4 < 0) {
    tmp_e1f4 = -tmp_e1f4;
  }

  if (tmp_f0u4 < 0) {
    tmp_f0u4 = -tmp_f0u4;
  }

  if (tmp_f20t < 0) {
    tmp_f20t = -tmp_f20t;
  }

  if (tmp_ds2y < 0) {
    tmp_ds2y = -tmp_ds2y;
  }

  if (tmp_joo2 < 0) {
    tmp_joo2 = -tmp_joo2;
  }

  if ((((((((tmp_g > MACRO_MR_INERMAX_HMNI) || (tmp_ccuf > MACRO_MR_INERMAX_HMNI))
           || (tmp_msyc > MACRO_MR_INERMAX_HMNV)) || (tmp_e1f4 >
           MACRO_MR_INERMAX_HMNV)) || (tmp_f0u4 > MACRO_MR_INERMAX_HMNVCF)) ||
        (tmp_f20t > MACRO_MR_INERMAX_HMNVCF)) || (tmp_ds2y >
        MACRO_MR_INERMAX_HMNEMF)) || (tmp_joo2 > MACRO_MR_INERMAX_HMNEMF)) {
    /* Transition: '<S105>:1461' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_hmncnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1463' */
      /* Transition: '<S105>:1465' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_hmncnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_hmncnt) + 1));

      /* Transition: '<S105>:1468' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      /* Transition: '<S105>:1467' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus[DTC_MCUcheck_MotorCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 6, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1471' */
  } else {
    /* Transition: '<S105>:1470' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_hmncnt = 0U;
  }

  /* Transition: '<S105>:1473' */
  /*          */
  if ((((((((((((Fv_Motor_PWM_U1 > (((Int16)MACRO_MBC_PWM_T_2_PCR) -
      Fv_Motor_PWM_limit_U1)) || (Fv_Motor_PWM_U1 < (((Int16)
      MACRO_MBC_PWM_T_2_IDY) + Fv_Motor_PWM_limit_U1))) || (Fv_Motor_PWM_V1 >
                (((Int16)MACRO_MBC_PWM_T_2_PCR) - Fv_Motor_PWM_limit_V1))) ||
              (Fv_Motor_PWM_V1 < (((Int16)MACRO_MBC_PWM_T_2_IDY) +
                Fv_Motor_PWM_limit_V1))) || (Fv_Motor_PWM_W1 > (((Int16)
                MACRO_MBC_PWM_T_2_PCR) - Fv_Motor_PWM_limit_W1))) ||
            (Fv_Motor_PWM_W1 < (((Int16)MACRO_MBC_PWM_T_2_IDY) +
              Fv_Motor_PWM_limit_W1))) || (Fv_Motor_PWM_U2 > (((Int16)
              MACRO_MBC_PWM_T_2_PCR) - Fv_Motor_PWM_limit_U2))) ||
          (Fv_Motor_PWM_U2 < (((Int16)MACRO_MBC_PWM_T_2_IDY) +
            Fv_Motor_PWM_limit_U2))) || (Fv_Motor_PWM_V2 > (((Int16)
            MACRO_MBC_PWM_T_2_PCR) - Fv_Motor_PWM_limit_V2))) ||
        (Fv_Motor_PWM_V2 < (((Int16)MACRO_MBC_PWM_T_2_IDY) +
          Fv_Motor_PWM_limit_V2))) || (Fv_Motor_PWM_W2 > (((Int16)
          MACRO_MBC_PWM_T_2_PCR) - Fv_Motor_PWM_limit_W2))) || (Fv_Motor_PWM_W2 <
       (((Int16)MACRO_MBC_PWM_T_2_IDY) + Fv_Motor_PWM_limit_W2))) {
    /* Transition: '<S105>:1475' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_pwmcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1477' */
      /* Transition: '<S105>:1479' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_pwmcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_pwmcnt) + 1));

      /* Transition: '<S105>:1484' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      /* Transition: '<S105>:1481' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus[DTC_MCUcheck_MotorCtrl] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 7, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1485' */
  } else {
    /* Transition: '<S105>:1483' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_pwmcnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void Fa_enter_atomic_softKalmanCheck(void)
{
  /* Entry 'softKalmanCheck': '<S105>:1276' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_acccnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_revcnt = 0U;
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_softPIoutCheck(void)
{
  Int32 inner_for_umax_g;

  /* During 'softPIoutCheck': '<S105>:1224' */
  /* Transition: '<S105>:1491' */
  /* Transition: '<S105>:1493' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud = Fv_MotorVoltage_D1;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq = Fv_MotorVoltage_Q1;
  inner_for_umax_g = FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit +
    MACRO_MR_INERMAX_VDIF;
  if ((((FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq > inner_for_umax_g) ||
        (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq < (-inner_for_umax_g)))
       || (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud > inner_for_umax_g))
      || (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud < (-inner_for_umax_g)))
  {
    /* Transition: '<S105>:1495' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1497' */
      /* Transition: '<S105>:1499' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt) + 1));

      /* Transition: '<S105>:1504' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1501' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      inner_for_umax_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(inner_for_umax_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[inner_for_umax_g].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 8, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1505' */
  } else {
    /* Transition: '<S105>:1503' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softClarkParkCheck(void)
{
  /* Entry 'softClarkParkCheck': '<S105>:1206' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt = 0U;
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_softPIoutCheck1(void)
{
  Int32 inner_for_umax2_g;

  /* During 'softPIoutCheck1': '<S105>:1710' */
  /* Transition: '<S105>:1718' */
  /* Transition: '<S105>:1719' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2 = Fv_MotorVoltage_D2;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2 = Fv_MotorVoltage_Q2;
  inner_for_umax2_g = FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit +
    MACRO_MR_INERMAX_VDIF;
  if ((((FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2 > inner_for_umax2_g)
        || (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2 <
            (-inner_for_umax2_g))) ||
       (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2 > inner_for_umax2_g))
      || (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2 <
          (-inner_for_umax2_g))) {
    /* Transition: '<S105>:1720' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt2 < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1721' */
      /* Transition: '<S105>:1724' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt2 = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt2) + 1));

      /* Transition: '<S105>:1726' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1723' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      inner_for_umax2_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(inner_for_umax2_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[inner_for_umax2_g].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 8, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1725' */
  } else {
    /* Transition: '<S105>:1722' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt2 = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softClarkPark_psmj(void)
{
  /* Entry 'softClarkParkCheck1': '<S105>:1662' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff2 = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff2 = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt2 = 0U;
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRap_softVoltLimitCheck(void)
{
  Int32 Fv_ErrDiagStatus_tmp_g;

  /* During 'softVoltLimitCheck': '<S105>:1162' */
  /* Transition: '<S105>:1507' */
  /* Transition: '<S105>:1509' */
  Fv_ErrDiagStatus_tmp_g = FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit
    * FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit;
  if ((asr_s32(((FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq *
                 FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq) +
                (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud *
                 FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud)) -
               Fv_ErrDiagStatus_tmp_g, 17U) > MACRO_MR_INERMAX_OUTDIF) ||
      (asr_s32(((FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2 *
                 FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2) +
                (FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2 *
                 FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2)) -
               Fv_ErrDiagStatus_tmp_g, 17U) > MACRO_MR_INERMAX_OUTDIF)) {
    /* Transition: '<S105>:1511' */
    if (FaultDiagRapidrtDW.MotorControlCheck.inner_outcnt < ((UInt16)
         MACRO_TP_REGULAR_VCCTIME)) {
      /* Transition: '<S105>:1513' */
      /* Transition: '<S105>:1515' */
      FaultDiagRapidrtDW.MotorControlCheck.inner_outcnt = (UInt16)((Int32)
        (((Int32)FaultDiagRapidrtDW.MotorControlCheck.inner_outcnt) + 1));

      /* Transition: '<S105>:1520' */
    } else {
      /* Outputs for Function Call SubSystem: '<S105>/DTC_Ctrl_Enabled' */
      /* Selector: '<S106>/Selector' */
      /* Transition: '<S105>:1517' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S105>:1651' */
      Fv_ErrDiagStatus_tmp_g = DTC_MCUcheck_MotorCtrl;

      /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S106>/Data Store Read'
       *  Product: '<S106>/Product'
       *  Selector: '<S106>/Selector'
       */
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_g)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_g].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S105>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S105>/getDTCEnabled' */
      /* Selector: '<S107>/Selector' incorporates:
       *  DataStoreRead: '<S107>/Data Store Read'
       */
      /* Simulink Function 'getDTCEnabled': '<S105>:1647' */
      Fv_FaultClass_MCUcheck_Soft = (UInt32)SetU32Fault
        (Fv_FaultClass_MCUcheck_Soft, 9, (((tagDTC_Ctrl_Info *)
           &(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_MotorCtrl].Enabled);

      /* End of Outputs for SubSystem: '<S105>/getDTCEnabled' */
    }

    /* Transition: '<S105>:1521' */
  } else {
    /* Transition: '<S105>:1519' */
    FaultDiagRapidrtDW.MotorControlCheck.inner_outcnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softInnerCompCheck(void)
{
  /* Entry 'softInnerCompCheck': '<S105>:1239' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_wkfcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_brgcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_hmncnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_pwmcnt = 0U;
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void FaultDiagRapid_MotorDiagMask(void)
{
  /* During 'MotorDiagMask': '<S105>:1299' */
  /* Transition: '<S105>:1171' */
  if ((Fv_FaultClass_MCUcheck_Soft & DiagSoftMask) > 0U) {
    /* Transition: '<S105>:1172' */
    /* Transition: '<S105>:1487' */
    Fv_FaultClass_MCU = (UInt16)SetU16Varit(Fv_FaultClass_MCU, 5);

    /* Transition: '<S105>:1489' */
  } else {
    /* Transition: '<S105>:1173' */
  }
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void Fau_enter_atomic_softPIoutCheck(void)
{
  /* Entry 'softPIoutCheck': '<S105>:1224' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt = 0U;
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void Fa_enter_atomic_softPIoutCheck1(void)
{
  /* Entry 'softPIoutCheck1': '<S105>:1710' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt2 = 0U;
}

#endif
#endif

/* Function for Chart: '<S104>/MotorCtrlCheck' */
#if DIAGDIS_MCUMOTORCONTROL == 0
#if DIAGDIS_MCUMOTORCONTROL == 0

static void enter_atomic_softVoltLimitCheck(void)
{
  /* Entry 'softVoltLimitCheck': '<S105>:1162' */
  FaultDiagRapidrtDW.MotorControlCheck.inner_outcnt = 0U;
}

#endif
#endif

/* System reset for atomic system: '<S84>/MCUCheck_MotorControl' */
void Fau_MCUCheck_MotorControl_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S89>/Diag_MCUMotorControl_Check' */
#if DIAGDIS_MCUMOTORCONTROL == 0

  /* Reset conditions for atomic system: '<S103>/MotorControlCheck' */

  /* SystemReset for Chart: '<S104>/MotorCtrlCheck' */
  FaultDiagRapidrtDW.MotorControlCheck.bitsForTID0.is_active_c2_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ulimit = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_ud2 = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_foc_uq2 = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_angcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_acccnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_revcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_currentdiff2 = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_voltagediff2 = 0;
  FaultDiagRapidrtDW.MotorControlCheck.inner_capcnt2 = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_wkfcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_brgcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_hmncnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_pwmcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_pidcnt2 = 0U;
  FaultDiagRapidrtDW.MotorControlCheck.inner_outcnt = 0U;

#endif

  /* End of SystemReset for SubSystem: '<S89>/Diag_MCUMotorControl_Check' */
}

/* Output and update for atomic system: '<S84>/MCUCheck_MotorControl' */
void FaultDiag_MCUCheck_MotorControl(void)
{
  /* Outputs for Atomic SubSystem: '<S89>/Diag_MCUMotorControl_Check' */
#if DIAGDIS_MCUMOTORCONTROL == 0

  /* Output and update for atomic system: '<S103>/MotorControlCheck' */

  /* Chart: '<S104>/MotorCtrlCheck' */
  /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck/MotorCtrlCheck */
  /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck/MotorCtrlCheck */
  if (((UInt32)
       FaultDiagRapidrtDW.MotorControlCheck.bitsForTID0.is_active_c2_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck/MotorCtrlCheck */
    FaultDiagRapidrtDW.MotorControlCheck.bitsForTID0.is_active_c2_FaultDiagRapid
      = 1;

    /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_MotorControl/Diag_MCUMotorControl_Check/MotorControlCheck/MotorCtrlCheck */
    enter_atomic_softRotorAngleChec();
    Fa_enter_atomic_softKalmanCheck();
    enter_atomic_softClarkParkCheck();
    enter_atomic_softClarkPark_psmj();
    enter_atomic_softInnerCompCheck();
    Fau_enter_atomic_softPIoutCheck();
    Fa_enter_atomic_softPIoutCheck1();
    enter_atomic_softVoltLimitCheck();
  } else {
    FaultDiagRa_softRotorAngleCheck();
    FaultDiagRapid_softKalmanCheck();
    FaultDiagRap_softClarkParkCheck();
    FaultDiagRa_softClarkParkCheck1();
    FaultDiagRap_softInnerCompCheck();
    FaultDiagRapid_softPIoutCheck();
    FaultDiagRapid_softPIoutCheck1();
    FaultDiagRap_softVoltLimitCheck();
    FaultDiagRapid_MotorDiagMask();
  }

  /* End of Chart: '<S104>/MotorCtrlCheck' */
#endif

  /* End of Outputs for SubSystem: '<S89>/Diag_MCUMotorControl_Check' */
}

/* Function for Chart: '<S109>/MCUViceCommDiag' */
#if DIAGDIS_MCUVICECOMM == 0
#if DIAGDIS_MCUVICECOMM == 0

static void FaultDiagRapid_ViceCommTimeOut(const Bool *enbcond_g, const Bool
  *commout_g)
{
  Bool mcu_vct_flag_g;
  Int32 Fv_ErrDiagStatus_tmp_g;

  /* During 'ViceCommTimeOut': '<S111>:1163' */
  /* Transition: '<S111>:1200' */
  if (*enbcond_g) {
    /* Transition: '<S111>:1202' */
    if (((Int32)Fv_SPITimeoutReq) == 0) {
      /* Transition: '<S111>:1204' */
      /* Transition: '<S111>:1206' */
      mcu_vct_flag_g = true;

      /* Transition: '<S111>:1209' */
    } else {
      /* Transition: '<S111>:1208' */
      Fv_SPITimeoutReq = 0;
      mcu_vct_flag_g = false;
    }

    /* Transition: '<S111>:1211' */
    if (mcu_vct_flag_g || (*commout_g)) {
      /* Transition: '<S111>:1213' */
      /* Transition: '<S111>:1215' */
      FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_rcvcnt = 0U;
      if (FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_errcnt < ((UInt16)
           MACRO_MR_MONITOR_OUTTIME)) {
        /* Transition: '<S111>:1217' */
        /* Transition: '<S111>:1219' */
        FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_errcnt = (UInt16)((Int32)
          (((Int32)FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_errcnt) + 1));
      } else {
        /* Outputs for Function Call SubSystem: '<S111>/DTC_Ctrl_Enabled' */
        /* DataTypeConversion: '<S113>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S113>/Data Store Read'
         *  Product: '<S113>/Product'
         *  Selector: '<S113>/Selector'
         */
        /* Transition: '<S111>:1222' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S111>:1259' */
        Fv_ErrDiagStatus[DTC_MCUcheck_CommTimeout] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_MCUcheck_CommTimeout].Enabled) * ((UInt32)FailureDiag_Err));

        /* End of Outputs for SubSystem: '<S111>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S111>/getDTCEnabled' */
        /* Selector: '<S114>/Selector' incorporates:
         *  DataStoreRead: '<S114>/Data Store Read'
         */
        /* Simulink Function 'getDTCEnabled': '<S111>:1255' */
        Fv_FaultClass_MCU = (UInt16)SetU16Fault(Fv_FaultClass_MCU, 7,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_MCUcheck_CommTimeout].Enabled);

        /* End of Outputs for SubSystem: '<S111>/getDTCEnabled' */
        /* Transition: '<S111>:1227' */
      }

      /* Transition: '<S111>:1235' */
      /* Transition: '<S111>:1236' */
      /* Transition: '<S111>:1233' */
    } else {
      /* Transition: '<S111>:1224' */
      FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_errcnt = 0U;
      if (FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_rcvcnt < ((UInt16)
           MACRO_MR_MONITOR_OUTTIME)) {
        /* Transition: '<S111>:1226' */
        /* Transition: '<S111>:1229' */
        FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_rcvcnt = (UInt16)((Int32)
          (((Int32)FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_rcvcnt) + 1));

        /* Transition: '<S111>:1233' */
      } else {
        /* Outputs for Function Call SubSystem: '<S111>/DTC_Ctrl_Enabled' */
        /* Selector: '<S113>/Selector' */
        /* Transition: '<S111>:1231' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S111>:1259' */
        Fv_ErrDiagStatus_tmp_g = DTC_MCUcheck_CommTimeout;

        /* DataTypeConversion: '<S113>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S113>/Data Store Read'
         *  Product: '<S113>/Product'
         *  Selector: '<S113>/Selector'
         */
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_g)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_g]
          .Enabled) * ((UInt32)FailureDiag_OK));

        /* End of Outputs for SubSystem: '<S111>/DTC_Ctrl_Enabled' */
        Fv_FaultClass_MCU = (UInt16)ClrU16Varit(Fv_FaultClass_MCU, 7);
      }
    }

    /* Transition: '<S111>:1239' */
  } else {
    /* Transition: '<S111>:1238' */
    FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_errcnt = 0U;
    FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_rcvcnt = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S109>/MCUViceCommDiag' */
#if DIAGDIS_MCUVICECOMM == 0
#if DIAGDIS_MCUVICECOMM == 0

static void FaultDiagRapi_ViceMonitorReport(void)
{
  Int32 Fv_ErrDiagStatus_tmp_g;

  /* DataStoreRead: '<S110>/Data Store Read6' incorporates:
   *  DataStoreRead: '<S113>/Data Store Read'
   *  DataStoreRead: '<S114>/Data Store Read'
   *  DataTypeConversion: '<S113>/Data Type Conversion2'
   *  Product: '<S113>/Product'
   *  Selector: '<S113>/Selector'
   *  Selector: '<S114>/Selector'
   */
  /* During 'ViceMonitorReport': '<S111>:1186' */
  /* Transition: '<S111>:1190' */
  if (Fv_ErrorFromGn32 > 0U) {
    /* Outputs for Function Call SubSystem: '<S111>/DTC_Ctrl_Enabled' */
    /* Selector: '<S113>/Selector' */
    /* Transition: '<S111>:1189' */
    /* Transition: '<S111>:1241' */
    /* Simulink Function 'DTC_Ctrl_Enabled': '<S111>:1259' */
    Fv_ErrDiagStatus_tmp_g = DTC_MCUcheck_ViceMonitor;
    Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_g)] = (FailureDiag)(((UInt32)
      (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_g].
      Enabled) * ((UInt32)FailureDiag_InitErr));

    /* End of Outputs for SubSystem: '<S111>/DTC_Ctrl_Enabled' */

    /* Outputs for Function Call SubSystem: '<S111>/getDTCEnabled' */
    /* Simulink Function 'getDTCEnabled': '<S111>:1255' */
    Fv_FaultClass_MCU = (UInt16)SetU16Fault(Fv_FaultClass_MCU, 8,
      (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MCUcheck_ViceMonitor].
      Enabled);

    /* End of Outputs for SubSystem: '<S111>/getDTCEnabled' */
    /* Transition: '<S111>:1243' */
  } else {
    /* Transition: '<S111>:1191' */
  }

  /* End of DataStoreRead: '<S110>/Data Store Read6' */
}

#endif
#endif

/* Function for Chart: '<S109>/MCUViceCommDiag' */
#if DIAGDIS_MCUVICECOMM == 0
#if DIAGDIS_MCUVICECOMM == 0

static void Fa_enter_atomic_ViceCommTimeOut(void)
{
  /* Entry 'ViceCommTimeOut': '<S111>:1163' */
  FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_errcnt = ((UInt16)
    MACRO_MR_MONITOR_OUTTIME);
  FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_rcvcnt = ((UInt16)
    MACRO_MR_MONITOR_OUTTIME);
}

#endif
#endif

/* System reset for atomic system: '<S84>/MCUCheck_ViceComm' */
void FaultDi_MCUCheck_ViceComm_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S90>/Diag_MCUViceComm_Check' */
#if DIAGDIS_MCUVICECOMM == 0

  /* Reset conditions for atomic system: '<S108>/ViceCommCheck' */

  /* SystemReset for Chart: '<S109>/MCUViceCommDiag' */
  FaultDiagRapidrtDW.ViceCommCheck.bitsForTID0.is_active_c45_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_rcvcnt = 0U;
  FaultDiagRapidrtDW.ViceCommCheck.mcu_vct_errcnt = 0U;

#endif

  /* End of SystemReset for SubSystem: '<S90>/Diag_MCUViceComm_Check' */
}

/* Output and update for atomic system: '<S84>/MCUCheck_ViceComm' */
void FaultDiagRapi_MCUCheck_ViceComm(void)
{
  /* Outputs for Atomic SubSystem: '<S90>/Diag_MCUViceComm_Check' */
#if DIAGDIS_MCUVICECOMM == 0

  /* Output and update for atomic system: '<S108>/ViceCommCheck' */
  {
    Bool enbcond_g;
    Bool commout_g;

    /* Outputs for Atomic SubSystem: '<S109>/MCUViceCommCond' */
    /* Logic: '<S110>/Logical Operator2' incorporates:
     *  Constant: '<S112>/Constant'
     *  DataStoreRead: '<S110>/Data Store Read'
     *  DataStoreRead: '<S110>/Data Store Read1'
     *  DataStoreRead: '<S110>/Data Store Read2'
     *  RelationalOperator: '<S112>/Compare'
     */
    enbcond_g = (((Fv_SysPower >= ((Int16)MACRO_POWER_VICEMONITOR)) &&
                  (Fv_IGkeyEffect)) && (Fv_SystemTransferState));

    /* Logic: '<S110>/Logical Operator1' incorporates:
     *  DataStoreRead: '<S110>/Data Store Read3'
     *  DataStoreRead: '<S110>/Data Store Read4'
     */
    commout_g = ((Fv_ViceMCUCommContTimeout) || (Fv_ViceMCUCommLongTimeout));

    /* End of Outputs for SubSystem: '<S109>/MCUViceCommCond' */

    /* Chart: '<S109>/MCUViceCommDiag' */
    /* Gateway: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommDiag */
    /* During: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommDiag */
    if (((UInt32)
         FaultDiagRapidrtDW.ViceCommCheck.bitsForTID0.is_active_c45_FaultDiagRapid)
        == 0U) {
      /* Entry: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommDiag */
      FaultDiagRapidrtDW.ViceCommCheck.bitsForTID0.is_active_c45_FaultDiagRapid =
        1;

      /* Entry Internal: DiagRapid_Step2Func/DiagInit_Step2/DiagRapid_MCUCheck/MCUCheck_ViceComm/Diag_MCUViceComm_Check/ViceCommCheck/MCUViceCommDiag */
      Fa_enter_atomic_ViceCommTimeOut();
    } else {
      FaultDiagRapid_ViceCommTimeOut(&enbcond_g, &commout_g);
      FaultDiagRapi_ViceMonitorReport();
    }

    /* End of Chart: '<S109>/MCUViceCommDiag' */
  }

#endif

  /* End of Outputs for SubSystem: '<S90>/Diag_MCUViceComm_Check' */
}

/* System reset for atomic system: '<S83>/DiagRapid_MCUCheck' */
void FaultD_DiagRapid_MCUCheck_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S84>/MCUCheck_Core' */
  FaultDiagRa_MCUCheck_Core_Reset();

  /* End of SystemReset for SubSystem: '<S84>/MCUCheck_Core' */

  /* SystemReset for Atomic SubSystem: '<S84>/MCUCheck_EPSControl' */
  Fault_MCUCheck_EPSControl_Reset();

  /* End of SystemReset for SubSystem: '<S84>/MCUCheck_EPSControl' */

  /* SystemReset for Atomic SubSystem: '<S84>/MCUCheck_MotorControl' */
  Fau_MCUCheck_MotorControl_Reset();

  /* End of SystemReset for SubSystem: '<S84>/MCUCheck_MotorControl' */

  /* SystemReset for Atomic SubSystem: '<S84>/MCUCheck_ViceComm' */
  FaultDi_MCUCheck_ViceComm_Reset();

  /* End of SystemReset for SubSystem: '<S84>/MCUCheck_ViceComm' */
}

/* Output and update for atomic system: '<S83>/DiagRapid_MCUCheck' */
void FaultDiagRap_DiagRapid_MCUCheck(void)
{
  /* Outputs for Atomic SubSystem: '<S84>/MCUCheck_Core' */
  FaultDiagRapid_MCUCheck_Core();

  /* End of Outputs for SubSystem: '<S84>/MCUCheck_Core' */

  /* Outputs for Atomic SubSystem: '<S84>/MCUCheck_EPSControl' */
  FaultDiagRa_MCUCheck_EPSControl();

  /* End of Outputs for SubSystem: '<S84>/MCUCheck_EPSControl' */

  /* Outputs for Atomic SubSystem: '<S84>/MCUCheck_MotorControl' */
  FaultDiag_MCUCheck_MotorControl();

  /* End of Outputs for SubSystem: '<S84>/MCUCheck_MotorControl' */

  /* Outputs for Atomic SubSystem: '<S84>/MCUCheck_ViceComm' */
  FaultDiagRapi_MCUCheck_ViceComm();

  /* End of Outputs for SubSystem: '<S84>/MCUCheck_ViceComm' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
