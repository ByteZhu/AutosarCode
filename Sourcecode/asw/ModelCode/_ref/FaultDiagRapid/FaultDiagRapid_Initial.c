/*
 * File: FaultDiagRapid_Initial.c
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

#include "FaultDiagRapid_Initial.h"

/* Include model header file for global data */
#include "FaultDiagRapid.h"
#include "FaultDiagRapid_private.h"

/* Named constants for Chart: '<S20>/MotorShortOpenInitDiag1' */
#define FaultDiagRap_IN_NO_ACTIVE_CHILD ((UInt8)0U)
#define FaultDiagRapid_IN_Diag         ((UInt8)1U)
#define FaultDiagRapid_IN_Wait         ((UInt8)2U)

/* Named constants for Chart: '<S20>/MotorShortOpenInitDiag2' */
#define FaultDi_IN_NO_ACTIVE_CHILD_g3wj ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_emyl    ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_gxud    ((UInt8)2U)

/* Named constants for Chart: '<S6>/DiagInit_InitialTimerShaft' */
#define FaultDi_IN_NO_ACTIVE_CHILD_hstz ((UInt8)0U)
#define FaultDiagR_IN_OFF_predrive_Test ((UInt8)2U)
#define FaultDiagRapid_IN_Complete     ((UInt8)1U)
#define FaultDiagRapid_IN_ON_predrive  ((UInt8)3U)
#define FaultDiagRapid_IN_Process      ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_ivwd    ((UInt8)2U)

/* Exported data definition */

/* Definition for custom storage class: Localizable */
static Bool diaginvalid;
static Bool diagvalid;
static Bool failflag;
static Bool powerflag;
static Bool v5cflag;

/* Forward declaration for local functions */
static void FaultDiag_enter_atomic_Complete(void);
static void FaultDiagRapid_ON_predrive(void);
static void FaultDiagRapid_Complete(void);
static void exit_internal_OFF_predrive_Test(void);
static void F_exit_atomic_OFF_predrive_Test(void);
static void FaultD_enter_atomic_ON_predrive(void);
static void FaultDiagRapi_OFF_predrive_Test(void);
static void enter_atomic_OFF_predrive_Test(void);
static void enter_internal_OFF_predrive_Tes(void);

/* System reset for atomic system: '<S20>/MotorShortOpenInitDiag1' */
#if DIAGDIS_MOTORSHORTOPENINIT == 0

void F_MotorShortOpenInitDiag1_Reset(void)
{
  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_active_c4_FaultDiagRapid =
    0;
  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c4_FaultDiagRapid =
    FaultDiagRap_IN_NO_ACTIVE_CHILD;
  FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe = 0U;
  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag_e53e = false;
  FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times_ofml = 0U;
  FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout_owd2 = 0U;
}

#endif

/* Output and update for atomic system: '<S20>/MotorShortOpenInitDiag1' */
#if DIAGDIS_MOTORSHORTOPENINIT == 0

void FaultDi_MotorShortOpenInitDiag1(void)
{
  /* Chart: '<S20>/MotorShortOpenInitDiag1' incorporates:
   *  DataStoreRead: '<S23>/Data Store Read'
   *  DataStoreRead: '<S24>/Data Store Read'
   *  DataStoreRead: '<S25>/Data Store Read'
   *  DataTypeConversion: '<S23>/Data Type Conversion2'
   *  DataTypeConversion: '<S24>/Data Type Conversion2'
   *  Product: '<S23>/Product'
   *  Product: '<S24>/Product'
   *  Selector: '<S23>/Selector'
   *  Selector: '<S24>/Selector'
   *  Selector: '<S25>/Selector'
   */
  /* Gateway: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1 */
  /* During: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1 */
  if (((UInt32)
       FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_active_c4_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1 */
    FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_active_c4_FaultDiagRapid
      = 1;

    /* Entry Internal: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag1 */
    /* Transition: '<S21>:1393' */
    FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c4_FaultDiagRapid =
      FaultDiagRapid_IN_Wait;

    /* Entry 'Wait': '<S21>:1396' */
    FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times_ofml = 0U;
  } else if (((UInt32)
              FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c4_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag) {
    /* During 'Diag': '<S21>:1399' */
    if ((!(SysTaskPhaseDiagStepIndex == InitDiagStep_OpenPhase)) ||
        (!SysTaskPhaseRelayPending)) {
      /* Transition: '<S21>:1394' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c4_FaultDiagRapid =
        FaultDiagRapid_IN_Wait;

      /* Entry 'Wait': '<S21>:1396' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times_ofml = 0U;
    } else {
      /* Transition: '<S21>:1672' */
      if (!FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag_e53e) {
        /* Transition: '<S21>:1688' */
        /* Transition: '<S21>:1489' */
        FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout_owd2 = (UInt16)
          ((Int32)(((Int32)
                    FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout_owd2) + 1));
        GET_PREDRIVER_PWMDUTY1();
        if ((((((IO_UphaseDuty1 > ((UInt16)MACRO_PHASEDUTY_MIN)) &&
                (IO_UphaseDuty1 < ((UInt16)MACRO_PHASEDUTY_MAX))) &&
               (IO_VphaseDuty1 > ((UInt16)MACRO_PHASEDUTY_MIN))) &&
              (IO_VphaseDuty1 < ((UInt16)MACRO_PHASEDUTY_MAX))) &&
             (IO_WphaseDuty1 > ((UInt16)MACRO_PHASEDUTY_MIN))) &&
            (IO_WphaseDuty1 < ((UInt16)MACRO_PHASEDUTY_MAX))) {
          /* Transition: '<S21>:1491' */
          /* Transition: '<S21>:1497' */
          FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe = (UInt16)
            ((Int32)(((Int32)
                      FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe) + 1));
          if ((((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe) ==
               1) || (((Int32)
                       FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe) ==
                      7)) {
            /* Transition: '<S21>:1499' */
            /* Transition: '<S21>:1501' */
            SetPhaseIndp1(1);

            /* Transition: '<S21>:1507' */
            /* Transition: '<S21>:1532' */
            /* Transition: '<S21>:1533' */
            /* Transition: '<S21>:1534' */
            /* Transition: '<S21>:1538' */
            /* Transition: '<S21>:1537' */
          } else {
            /* Transition: '<S21>:1503' */
            if ((((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe) ==
                 2) || (((Int32)
                         FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe) ==
                        8)) {
              /* Transition: '<S21>:1505' */
              /* Transition: '<S21>:1509' */
              SetPhaseIndp1(2);

              /* Transition: '<S21>:1511' */
              /* Transition: '<S21>:1533' */
              /* Transition: '<S21>:1534' */
              /* Transition: '<S21>:1538' */
              /* Transition: '<S21>:1537' */
            } else {
              /* Transition: '<S21>:1513' */
              if (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe)
                  == 3) {
                /* Transition: '<S21>:1515' */
                /* Transition: '<S21>:1517' */
                SetThresholdVPT1((Int32)(((UInt32)((UInt8)
                  MACRO_MOTOR_DEFAULTDUTY)) >> 1));

                /* Transition: '<S21>:1519' */
                /* Transition: '<S21>:1534' */
                /* Transition: '<S21>:1538' */
                /* Transition: '<S21>:1537' */
              } else {
                /* Transition: '<S21>:1521' */
                if (((Int32)
                     FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe) > 8)
                {
                  /* Transition: '<S21>:1527' */
                  /* Transition: '<S21>:1529' */
                  SetThresholdVPT1(((UInt8)MACRO_MOTOR_DEFAULTDUTY));
                  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag_e53e
                    = true;
                  SysTaskPhaseOpenWarning1 = InitDiag_Pass;
                  ClosePredrive1();
                  IO_UphaseDuty1 = 0;
                  IO_VphaseDuty1 = 0;
                  IO_WphaseDuty1 = 0;

                  /* Transition: '<S21>:1537' */
                } else {
                  /* Transition: '<S21>:1536' */
                }
              }
            }
          }

          /* Transition: '<S21>:1555' */
          /* Transition: '<S21>:1557' */
        } else {
          /* Transition: '<S21>:1540' */
          if (FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout_owd2 > ((UInt16)
               MACRO_MOTOR_STOPTIME)) {
            /* Transition: '<S21>:1694' */
            /* Transition: '<S21>:1696' */
            switch (FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times_ofml) {
             case 0:
              /* Transition: '<S21>:1698' */
              /* Transition: '<S21>:1700' */
              ClosePredrive1();
              FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times_ofml = 1U;

              /* Outputs for Function Call SubSystem: '<S21>/DTCInit_Ctrl_Enabled' */
              /* Simulink Function 'DTCInit_Ctrl_Enabled': '<S21>:1681' */
              SysTaskPhaseOpenWarning1 = (InitDiag)(((UInt32)(((tagDTC_Ctrl_Info
                *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MOTORcheck_PhaseOpen].Enabled) *
                ((UInt32)InitDiag_Abnormal));

              /* End of Outputs for SubSystem: '<S21>/DTCInit_Ctrl_Enabled' */
              /* Transition: '<S21>:1708' */
              /* Transition: '<S21>:1710' */
              /* Transition: '<S21>:1711' */
              /* Transition: '<S21>:1714' */
              break;

             case 1:
              /* Transition: '<S21>:1702' */
              /* Transition: '<S21>:1704' */
              /* Transition: '<S21>:1706' */
              FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe = 0U;
              OpenPredriveIndp1();
              SetPhaseIndp1(0);
              FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times_ofml = 2U;

              /* Transition: '<S21>:1714' */
              break;

             default:
              /* Transition: '<S21>:1713' */
              break;
            }

            /* Transition: '<S21>:1716' */
          } else {
            /* Transition: '<S21>:1717' */
          }

          /* Transition: '<S21>:1718' */
          if (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout_owd2) >
              (((Int32)((UInt16)MACRO_MOTOR_STOPTIME)) * 3)) {
            /* Transition: '<S21>:1542' */
            /* Transition: '<S21>:1544' */
            SetThresholdVPT1(((UInt8)MACRO_MOTOR_DEFAULTDUTY));
            FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag_e53e =
              true;
            ClosePredrive1();

            /* Outputs for Function Call SubSystem: '<S21>/DTC_Ctrl_Enabled' */
            /* Transition: '<S21>:1552' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S21>:1667' */
            Fv_ErrDiagStatus[DTC_MOTORcheck_PhaseOpen] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MOTORcheck_PhaseOpen].Enabled) * ((UInt32)FailureDiag_InitErr));

            /* End of Outputs for SubSystem: '<S21>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S21>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S21>:1663' */
            Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 2,
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MOTORcheck_PhaseOpen].Enabled);

            /* End of Outputs for SubSystem: '<S21>/getDTCEnabled' */

            /* Outputs for Function Call SubSystem: '<S21>/DTCInit_Ctrl_Enabled' */
            /* Simulink Function 'DTCInit_Ctrl_Enabled': '<S21>:1681' */
            SysTaskPhaseOpenWarning1 = (InitDiag)(((UInt32)(((tagDTC_Ctrl_Info *)
              &(DTC_Ctrl_Info_Tab[0])))[DTC_MOTORcheck_PhaseOpen].Enabled) *
              ((UInt32)InitDiag_Error));

            /* End of Outputs for SubSystem: '<S21>/DTCInit_Ctrl_Enabled' */
            /* Transition: '<S21>:1557' */
          } else {
            /* Transition: '<S21>:1546' */
          }
        }

        /* Transition: '<S21>:1691' */
      } else {
        /* Transition: '<S21>:1690' */
      }
    }
  } else {
    /* During 'Wait': '<S21>:1396' */
    if ((SysTaskPhaseDiagStepIndex == InitDiagStep_OpenPhase) &&
        (SysTaskPhaseRelayPending)) {
      /* Transition: '<S21>:1395' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c4_FaultDiagRapid =
        FaultDiagRapid_IN_Diag;

      /* Entry 'Diag': '<S21>:1399' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault_krxe = 0U;
      FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout_owd2 = 0U;
      OpenPredriveIndp1();
      SetPhaseIndp1(0);
      FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag_e53e = false;
    }
  }

  /* End of Chart: '<S20>/MotorShortOpenInitDiag1' */
}

#endif

/* System reset for atomic system: '<S20>/MotorShortOpenInitDiag2' */
#if DIAGDIS_MOTORSHORTOPENINIT == 0

void F_MotorShortOpenInitDiag2_Reset(void)
{
  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_active_c15_FaultDiagRapid
    = 0;
  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c15_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_g3wj;
  FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault = 0U;
  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag = false;
  FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times = 0U;
  FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout = 0U;
}

#endif

/* Output and update for atomic system: '<S20>/MotorShortOpenInitDiag2' */
#if DIAGDIS_MOTORSHORTOPENINIT == 0

void FaultDi_MotorShortOpenInitDiag2(void)
{
  /* Chart: '<S20>/MotorShortOpenInitDiag2' incorporates:
   *  DataStoreRead: '<S26>/Data Store Read'
   *  DataStoreRead: '<S27>/Data Store Read'
   *  DataStoreRead: '<S28>/Data Store Read'
   *  DataTypeConversion: '<S26>/Data Type Conversion2'
   *  DataTypeConversion: '<S27>/Data Type Conversion2'
   *  Product: '<S26>/Product'
   *  Product: '<S27>/Product'
   *  Selector: '<S26>/Selector'
   *  Selector: '<S27>/Selector'
   *  Selector: '<S28>/Selector'
   */
  /* Gateway: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2 */
  /* During: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2 */
  if (((UInt32)
       FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_active_c15_FaultDiagRapid)
      == 0U) {
    /* Entry: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2 */
    FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_active_c15_FaultDiagRapid
      = 1;

    /* Entry Internal: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft/DIagMotorOpen/MotorInitialCheck_ShortOpen/DiagInit_ShortOpen_Check/ShortOpenInitCheck/MotorShortOpenInitDiag2 */
    /* Transition: '<S22>:1393' */
    FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c15_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_gxud;

    /* Entry 'Wait': '<S22>:1396' */
    FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times = 0U;
  } else if (((UInt32)
              FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c15_FaultDiagRapid)
             == FaultDiagRapid_IN_Diag_emyl) {
    /* During 'Diag': '<S22>:1399' */
    if ((!(SysTaskPhaseDiagStepIndex == InitDiagStep_OpenPhase)) ||
        (!SysTaskPhaseRelayPending)) {
      /* Transition: '<S22>:1394' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c15_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_gxud;

      /* Entry 'Wait': '<S22>:1396' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times = 0U;
    } else {
      /* Transition: '<S22>:1672' */
      if (!FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag) {
        /* Transition: '<S22>:1688' */
        /* Transition: '<S22>:1489' */
        FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout = (UInt16)((Int32)
          (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout) + 1));
        GET_PREDRIVER_PWMDUTY2();
        if ((((((IO_UphaseDuty2 > ((UInt16)MACRO_PHASEDUTY_MIN)) &&
                (IO_UphaseDuty2 < ((UInt16)MACRO_PHASEDUTY_MAX))) &&
               (IO_VphaseDuty2 > ((UInt16)MACRO_PHASEDUTY_MIN))) &&
              (IO_VphaseDuty2 < ((UInt16)MACRO_PHASEDUTY_MAX))) &&
             (IO_WphaseDuty2 > ((UInt16)MACRO_PHASEDUTY_MIN))) &&
            (IO_WphaseDuty2 < ((UInt16)MACRO_PHASEDUTY_MAX))) {
          /* Transition: '<S22>:1491' */
          /* Transition: '<S22>:1497' */
          FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault) + 1));
          if ((((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault) == 1) ||
              (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault) == 7))
          {
            /* Transition: '<S22>:1499' */
            /* Transition: '<S22>:1501' */
            SetPhaseIndp2(1);

            /* Transition: '<S22>:1507' */
            /* Transition: '<S22>:1532' */
            /* Transition: '<S22>:1533' */
            /* Transition: '<S22>:1534' */
            /* Transition: '<S22>:1538' */
            /* Transition: '<S22>:1537' */
          } else {
            /* Transition: '<S22>:1503' */
            if ((((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault) == 2)
                || (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault) ==
                    8)) {
              /* Transition: '<S22>:1505' */
              /* Transition: '<S22>:1509' */
              SetPhaseIndp2(2);

              /* Transition: '<S22>:1511' */
              /* Transition: '<S22>:1533' */
              /* Transition: '<S22>:1534' */
              /* Transition: '<S22>:1538' */
              /* Transition: '<S22>:1537' */
            } else {
              /* Transition: '<S22>:1513' */
              if (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault) == 3)
              {
                /* Transition: '<S22>:1515' */
                /* Transition: '<S22>:1517' */
                SetThresholdVPT2((Int32)(((UInt32)((UInt8)
                  MACRO_MOTOR_DEFAULTDUTY)) >> 1));

                /* Transition: '<S22>:1519' */
                /* Transition: '<S22>:1534' */
                /* Transition: '<S22>:1538' */
                /* Transition: '<S22>:1537' */
              } else {
                /* Transition: '<S22>:1521' */
                if (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault) >
                    8) {
                  /* Transition: '<S22>:1527' */
                  /* Transition: '<S22>:1529' */
                  SetThresholdVPT2(((UInt8)MACRO_MOTOR_DEFAULTDUTY));
                  FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag =
                    true;
                  SysTaskPhaseOpenWarning2 = InitDiag_Pass;
                  ClosePredrive2();
                  IO_UphaseDuty2 = 0;
                  IO_VphaseDuty2 = 0;
                  IO_WphaseDuty2 = 0;

                  /* Transition: '<S22>:1537' */
                } else {
                  /* Transition: '<S22>:1536' */
                }
              }
            }
          }

          /* Transition: '<S22>:1555' */
          /* Transition: '<S22>:1557' */
        } else {
          /* Transition: '<S22>:1540' */
          if (FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout > ((UInt16)
               MACRO_MOTOR_STOPTIME)) {
            /* Transition: '<S22>:1694' */
            /* Transition: '<S22>:1696' */
            switch (FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times) {
             case 0:
              /* Transition: '<S22>:1698' */
              /* Transition: '<S22>:1700' */
              ClosePredrive2();
              FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times = 1U;

              /* Outputs for Function Call SubSystem: '<S22>/DTCInit_Ctrl_Enabled' */
              /* Simulink Function 'DTCInit_Ctrl_Enabled': '<S22>:1681' */
              SysTaskPhaseOpenWarning2 = (InitDiag)(((UInt32)(((tagDTC_Ctrl_Info
                *)&(DTC_Ctrl_Info_Tab[0])))[DTC_MOTORcheck_PhaseOpen].Enabled) *
                ((UInt32)InitDiag_Abnormal));

              /* End of Outputs for SubSystem: '<S22>/DTCInit_Ctrl_Enabled' */
              /* Transition: '<S22>:1708' */
              /* Transition: '<S22>:1710' */
              /* Transition: '<S22>:1711' */
              /* Transition: '<S22>:1714' */
              break;

             case 1:
              /* Transition: '<S22>:1702' */
              /* Transition: '<S22>:1704' */
              /* Transition: '<S22>:1706' */
              FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault = 0U;
              OpenPredriveIndp2();
              SetPhaseIndp2(0);
              FaultDiagRapidrtDW.ShortOpenInitCheck.diag_times = 2U;

              /* Transition: '<S22>:1714' */
              break;

             default:
              /* Transition: '<S22>:1713' */
              break;
            }

            /* Transition: '<S22>:1716' */
          } else {
            /* Transition: '<S22>:1717' */
          }

          /* Transition: '<S22>:1718' */
          if (((Int32)FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout) >
              (((Int32)((UInt16)MACRO_MOTOR_STOPTIME)) * 3)) {
            /* Transition: '<S22>:1542' */
            /* Transition: '<S22>:1544' */
            SetThresholdVPT2(((UInt8)MACRO_MOTOR_DEFAULTDUTY));
            FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag = true;
            ClosePredrive2();

            /* Outputs for Function Call SubSystem: '<S22>/DTC_Ctrl_Enabled' */
            /* Transition: '<S22>:1552' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S22>:1667' */
            Fv_ErrDiagStatus[DTC_MOTORcheck_PhaseOpen] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MOTORcheck_PhaseOpen].Enabled) * ((UInt32)FailureDiag_InitErr));

            /* End of Outputs for SubSystem: '<S22>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S22>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S22>:1663' */
            Fv_FaultClass_Motor = (UInt16)SetU16Fault(Fv_FaultClass_Motor, 3,
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_MOTORcheck_PhaseOpen].Enabled);

            /* End of Outputs for SubSystem: '<S22>/getDTCEnabled' */

            /* Outputs for Function Call SubSystem: '<S22>/DTCInit_Ctrl_Enabled' */
            /* Simulink Function 'DTCInit_Ctrl_Enabled': '<S22>:1681' */
            SysTaskPhaseOpenWarning2 = (InitDiag)(((UInt32)(((tagDTC_Ctrl_Info *)
              &(DTC_Ctrl_Info_Tab[0])))[DTC_MOTORcheck_PhaseOpen].Enabled) *
              ((UInt32)InitDiag_Error));

            /* End of Outputs for SubSystem: '<S22>/DTCInit_Ctrl_Enabled' */
            /* Transition: '<S22>:1557' */
          } else {
            /* Transition: '<S22>:1546' */
          }
        }

        /* Transition: '<S22>:1691' */
      } else {
        /* Transition: '<S22>:1690' */
      }
    }
  } else {
    /* During 'Wait': '<S22>:1396' */
    if ((SysTaskPhaseDiagStepIndex == InitDiagStep_OpenPhase) &&
        (SysTaskPhaseRelayPending)) {
      /* Transition: '<S22>:1395' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.is_c15_FaultDiagRapid =
        FaultDiagRapid_IN_Diag_emyl;

      /* Entry 'Diag': '<S22>:1399' */
      FaultDiagRapidrtDW.ShortOpenInitCheck.read_fault = 0U;
      FaultDiagRapidrtDW.ShortOpenInitCheck.read_timeout = 0U;
      OpenPredriveIndp2();
      SetPhaseIndp2(0);
      FaultDiagRapidrtDW.ShortOpenInitCheck.bitsForTID0.stopflag = false;
    }
  }

  /* End of Chart: '<S20>/MotorShortOpenInitDiag2' */
}

#endif

/* System reset for atomic system: '<S17>/MotorInitialCheck_ShortOpen' */
void MotorInitialCheck_ShortOp_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S18>/DiagInit_ShortOpen_Check' */
#if DIAGDIS_MOTORSHORTOPENINIT == 0

  /* Reset conditions for atomic system: '<S19>/ShortOpenInitCheck' */

  /* SystemReset for Chart: '<S20>/MotorShortOpenInitDiag1' */
  F_MotorShortOpenInitDiag1_Reset();

  /* SystemReset for Chart: '<S20>/MotorShortOpenInitDiag2' */
  F_MotorShortOpenInitDiag2_Reset();

#endif

  /* End of SystemReset for SubSystem: '<S18>/DiagInit_ShortOpen_Check' */
}

/* Output and update for atomic system: '<S17>/MotorInitialCheck_ShortOpen' */
void Fau_MotorInitialCheck_ShortOpen(void)
{
  /* Outputs for Resettable SubSystem: '<S17>/MotorInitialCheck_ShortOpen' incorporates:
   *  ResetPort: '<S18>/Reset'
   */
  if ((FaultDiagRapidrtDW.resetflag) && (((UInt32)
        FaultDiagRapidrtPrevZCX.MotorInitialCheck_ShortOpen_Res) != POS_ZCSIG))
  {
    MotorInitialCheck_ShortOp_Reset();
  }

  FaultDiagRapidrtPrevZCX.MotorInitialCheck_ShortOpen_Res =
    FaultDiagRapidrtDW.resetflag ? ((ZCSigState)1) : ((ZCSigState)0);

  /* Outputs for Atomic SubSystem: '<S18>/DiagInit_ShortOpen_Check' */
#if DIAGDIS_MOTORSHORTOPENINIT == 0

  /* Output and update for atomic system: '<S19>/ShortOpenInitCheck' */

  /* Chart: '<S20>/MotorShortOpenInitDiag1' */
  FaultDi_MotorShortOpenInitDiag1();

  /* Chart: '<S20>/MotorShortOpenInitDiag2' */
  FaultDi_MotorShortOpenInitDiag2();

#endif

  /* End of Outputs for SubSystem: '<S18>/DiagInit_ShortOpen_Check' */
  /* End of Outputs for SubSystem: '<S17>/MotorInitialCheck_ShortOpen' */
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void FaultDiag_enter_atomic_Complete(void)
{
  /* Entry 'Complete': '<S8>:1134' */
  Fv_TimerShaftState = TmrSft_Complete;
  SysTaskPhaseDiagStepIndex = InitDiagStep_Default;
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void FaultDiagRapid_ON_predrive(void)
{
  /* During 'ON_predrive': '<S8>:1040' */
  if ((failflag) || (FaultDiagRapidrtDW.bitsForTID0.onp_jump_flag)) {
    /* Transition: '<S8>:1093' */
    /* Transition: '<S8>:1088' */
    FaultDiagRapidrtDW.bitsForTID0.is_TimeShaft = FaultDiagRapid_IN_Complete;
    FaultDiag_enter_atomic_Complete();
  } else {
    /* Transition: '<S8>:1057' */
    if (powerflag) {
      /* Transition: '<S8>:1059' */
      /* Transition: '<S8>:1061' */

      if (((Int32)FaultDiagRapidrtDW.onp_ts_cnt) > 0) {
        /* Transition: '<S8>:1063' */
        /* Transition: '<S8>:1065' */
        FaultDiagRapidrtDW.onp_ts_cnt = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.onp_ts_cnt) - 1));
      } else {
        /* Transition: '<S8>:1067' */
        FaultDiagRapidrtDW.bitsForTID0.onp_jump_flag = true;
        OpenPredrive();//�����鵥(C017)--TXY--20240115
        /* Transition: '<S8>:1068' */
      }
    } else {
      /* Transition: '<S8>:1070' */
      /* Transition: '<S8>:1078' */
      /* Transition: '<S8>:1068' */
    }
  }
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void FaultDiagRapid_Complete(void)
{
  /* During 'Complete': '<S8>:1134' */
  /* Transition: '<S8>:1141' */
  if ((!failflag) || (((Int32)FaultDiagRapidrtDW.failtimeout_cnt) == 0)) {
    /* Transition: '<S8>:1142' */
    /* Transition: '<S8>:1144' */
    Fv_SystemTransferState = true;

    /* Transition: '<S8>:1145' */
  } else {
    /* Transition: '<S8>:1143' */
  }
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void exit_internal_OFF_predrive_Test(void)
{
  /* Exit Internal 'OFF_predrive_Test': '<S8>:889' */
  FaultDiagRapidrtDW.bitsForTID0.is_OFF_predrive_Test =
    FaultDi_IN_NO_ACTIVE_CHILD_hstz;
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void F_exit_atomic_OFF_predrive_Test(void)
{
  /* Exit 'OFF_predrive_Test': '<S8>:889' */
  SysTaskPhaseDiagStepIndex = InitDiagStep_Default;
  ClosePredrive();
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void FaultD_enter_atomic_ON_predrive(void)
{
  /* Entry 'ON_predrive': '<S8>:1040' */
  Fv_TimerShaftState = TmrSft_PredriverON;
  FaultDiagRapidrtDW.onp_ts_cnt = ((UInt16)MACRO_TP_INITCHECK_DRIVETIME);
  FaultDiagRapidrtDW.bitsForTID0.onp_jump_flag = !MACRO_TP_TASKEN_ONPREDRIVE;
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void FaultDiagRapi_OFF_predrive_Test(void)
{
  /* During 'OFF_predrive_Test': '<S8>:889' */
  if (failflag) {
    /* Transition: '<S8>:1091' */
    exit_internal_OFF_predrive_Test();
    F_exit_atomic_OFF_predrive_Test();
    FaultDiagRapidrtDW.bitsForTID0.is_TimeShaft = FaultDiagRapid_IN_Complete;
    FaultDiag_enter_atomic_Complete();
  } else if (FaultDiagRapidrtDW.bitsForTID0.ofp_jump_flag) {
    /* Transition: '<S8>:1330' */
    exit_internal_OFF_predrive_Test();
    F_exit_atomic_OFF_predrive_Test();
    FaultDiagRapidrtDW.bitsForTID0.is_TimeShaft = FaultDiagRapid_IN_ON_predrive;
    FaultD_enter_atomic_ON_predrive();
  } else if (((UInt32)FaultDiagRapidrtDW.bitsForTID0.is_OFF_predrive_Test) ==
             FaultDiagRapid_IN_Process) {
#if 1
    /* During 'Process': '<S8>:893' */
    if ((diaginvalid) || (v5cflag)) {
      /* Transition: '<S8>:892' */
      FaultDiagRapidrtDW.bitsForTID0.is_OFF_predrive_Test =
        FaultDiagRapid_IN_Wait_ivwd;

      /* Entry 'Wait': '<S8>:902' */
      SysTaskPhaseDiagStepIndex = InitDiagStep_Default;
    } else {
      /* Transition: '<S8>:907' */
      if (((Int32)FaultDiagRapidrtDW.ofp_ts_cnt) > 0) {
        /* Transition: '<S8>:909' */
        /* Transition: '<S8>:911' */
        FaultDiagRapidrtDW.ofp_ts_cnt = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.ofp_ts_cnt) - 1));
      } else {
        /* Transition: '<S8>:913' */
        if ((SysTaskPhaseOpenWarning1 <= InitDiag_Pass) ||
            (SysTaskPhaseOpenWarning2 <= InitDiag_Pass)) {
          /* Transition: '<S8>:915' */
          /* Transition: '<S8>:917' */
          FaultDiagRapidrtDW.bitsForTID0.ofp_jump_flag = true;
        } else {
          /* Transition: '<S8>:919' */
          /* Transition: '<S8>:1251' */
        }

        /* Transition: '<S8>:1252' */
      }

      if (FaultDiagRapidrtDW.bitsForTID0.diag_step) {
        /* Transition: '<S8>:1250' */
        /* Transition: '<S8>:1254' */
        FaultDiagRapidrtDW.bitsForTID0.diag_step = false;

        /* Simulink Function 'DIagMotorOpen': '<S8>:1167' */
        FaultDiagRapidrtDW.resetflag = FaultDiagRapidrtDW.bitsForTID0.diagreset;

        /* Outputs for Function Call SubSystem: '<S8>/DIagMotorOpen' */
        /* Outputs for Resettable SubSystem: '<S17>/MotorInitialCheck_ShortOpen' */
        Fau_MotorInitialCheck_ShortOpen();

        /* End of Outputs for SubSystem: '<S17>/MotorInitialCheck_ShortOpen' */
        /* End of Outputs for SubSystem: '<S8>/DIagMotorOpen' */
        FaultDiagRapidrtDW.bitsForTID0.diagreset = false;
      } else {
        /* Transition: '<S8>:1256' */
        FaultDiagRapidrtDW.bitsForTID0.diag_step = true;

        /* Transition: '<S8>:1257' */
      }
    }
#else
    FaultDiagRapidrtDW.bitsForTID0.ofp_jump_flag = true;
#endif
  } else {
#if 1
    /* During 'Wait': '<S8>:902' */
    if ((diagvalid) && (!v5cflag)) {
      /* Transition: '<S8>:890' */
      FaultDiagRapidrtDW.bitsForTID0.is_OFF_predrive_Test =
        FaultDiagRapid_IN_Process;

      /* Entry 'Process': '<S8>:893' */
      SysTaskPhaseDiagStepIndex = InitDiagStep_OpenPhase;
      FaultDiagRapidrtDW.ofp_ts_cnt = ((UInt16)MACRO_TP_INITCHECK_STEPTIME_PM);
      FaultDiagRapidrtDW.bitsForTID0.diag_step = true;
      FaultDiagRapidrtDW.bitsForTID0.diagreset = true;
    }
#else
    /*TB9083 FET测试正常(临时方案)--TXY--20240506*/
    if(diagvalid)
    {
      FaultDiagRapidrtDW.bitsForTID0.ofp_jump_flag = true;
    }
    //FaultDiagRapidrtDW.bitsForTID0.ofp_jump_flag = true;
#endif

  }
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void enter_atomic_OFF_predrive_Test(void)
{
  UInt8 ofp_ts_tldvpt;

  /* Entry 'OFF_predrive_Test': '<S8>:889' */
  /* 150ms */
  Fv_TimerShaftState = TmrSft_OpenTest;
  SysTaskPhaseDiagStepIndex = InitDiagStep_Default;
  ofp_ts_tldvpt = ((UInt8)MACRO_MOTOR_DEFAULTDUTY);
  OpenPhase();
  Gtm_SetPwmValue_50per1();
  SetThresholdVPT1(ofp_ts_tldvpt);
  Gtm_SetPwmValue_50per2();
  SetThresholdVPT2(ofp_ts_tldvpt);
  FaultDiagRapidrtDW.bitsForTID0.ofp_jump_flag =
    !MACRO_TP_TASKEN_OFFPREDRIVETEST;
}

/* Function for Chart: '<S6>/DiagInit_InitialTimerShaft' */
static void enter_internal_OFF_predrive_Tes(void)
{
  /* Entry Internal 'OFF_predrive_Test': '<S8>:889' */
  /* Transition: '<S8>:891' */
  FaultDiagRapidrtDW.bitsForTID0.is_OFF_predrive_Test =
    FaultDiagRapid_IN_Wait_ivwd;

  /* Entry 'Wait': '<S8>:902' */
  SysTaskPhaseDiagStepIndex = InitDiagStep_Default;
}

/* System reset for atomic system: '<S2>/DiagInit_Step0' */
void FaultDiagR_DiagInit_Step0_Reset(void)
{
  /* SystemReset for Chart: '<S6>/DiagInit_InitialTimerShaft' */
  FaultDiagRapidrtDW.bitsForTID0.is_TimeShaft = FaultDi_IN_NO_ACTIVE_CHILD_hstz;
  FaultDiagRapidrtDW.bitsForTID0.is_OFF_predrive_Test =
    FaultDi_IN_NO_ACTIVE_CHILD_hstz;
  FaultDiagRapidrtDW.bitsForTID0.is_active_c1_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.failtimeout_cnt = 0U;
  FaultDiagRapidrtDW.bitsForTID0.onp_jump_flag = false;
  FaultDiagRapidrtDW.bitsForTID0.ofp_jump_flag = false;
  FaultDiagRapidrtDW.ofp_ts_cnt = 0U;
  FaultDiagRapidrtDW.onp_ts_cnt = 0U;
  FaultDiagRapidrtDW.bitsForTID0.diagreset = false;
  FaultDiagRapidrtDW.bitsForTID0.diag_step = false;
}

/* Output and update for atomic system: '<S2>/DiagInit_Step0' */
void FaultDiagRapid_DiagInit_Step0(void)
{
  /* local block i/o variables */
  Bool powerwork;
  Int32 rtb_rotor_rpm;

  /* Outputs for Resettable SubSystem: '<S2>/DiagInit_Step0' incorporates:
   *  ResetPort: '<S6>/Reset'
   */
  if ((FaultDiagRapidrtDW.reset_flag) && (((UInt32)
        FaultDiagRapidrtPrevZCX.DiagInit_Step0_Reset_ZCE) != POS_ZCSIG)) {
    FaultDiagR_DiagInit_Step0_Reset();
  }

  FaultDiagRapidrtPrevZCX.DiagInit_Step0_Reset_ZCE =
    FaultDiagRapidrtDW.reset_flag ? ((ZCSigState)1) : ((ZCSigState)0);

  /* Outputs for Atomic SubSystem: '<S6>/DiagInit_InitialTImerCond' */
  /* Abs: '<S7>/Abs' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read2'
   */
  if (Fv_dRotorAng_rpm < 0) {
    rtb_rotor_rpm = -Fv_dRotorAng_rpm;
  } else {
    rtb_rotor_rpm = Fv_dRotorAng_rpm;
  }

  /* End of Abs: '<S7>/Abs' */

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataStoreRead: '<S7>/Data Store Read1'
   */
  powerwork = (Fv_SysPowerRelay > ((Int16)MACRO_TP_BRIDGEWORK));

  /* Logic: '<S7>/AND' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataStoreRead: '<S7>/Data Store Read4'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  diagvalid = (((rtb_rotor_rpm < MACRO_TP_MOTORCHECK_REVDN) && (powerwork)) &&
               (SysTaskPreDriverCalPending == true));

  /* Logic: '<S7>/AND2' incorporates:
   *  Constant: '<S14>/Constant'
   *  DataStoreRead: '<S7>/Data Store Read6'
   *  RelationalOperator: '<S14>/Compare'
   */
  powerflag = ((powerwork) && (SysTaskVbatAbnormalPending == false));

  /* Logic: '<S7>/AND1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  DataStoreRead: '<S7>/Data Store Read1'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   */
  diaginvalid = ((Fv_SysPowerRelay < ((Int16)MACRO_TP_BRIDGESHUT)) ||
                 (rtb_rotor_rpm > MACRO_TP_MOTORCHECK_REVUP));

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   *  DataStoreRead: '<S7>/Data Store Read3'
   */
  failflag = (Fv_HighFailFlag > 0);

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   *  DataStoreRead: '<S7>/Data Store Read5'
   */
  v5cflag = (((Int32)(Arg82800V5cOkFlag ? 1 : 0)) > ((Int32)(false ? 1 : 0)));

  /* End of Outputs for SubSystem: '<S6>/DiagInit_InitialTImerCond' */

  /* Chart: '<S6>/DiagInit_InitialTimerShaft' */
  /* Gateway: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft */
  /* During: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft */
  if (((UInt32)FaultDiagRapidrtDW.bitsForTID0.is_active_c1_FaultDiagRapid) == 0U)
  {
    /* Entry: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft */
    FaultDiagRapidrtDW.bitsForTID0.is_active_c1_FaultDiagRapid = 1;

    /* Entry Internal: DiagRapid_Step0Func/DiagInit_Step0/DiagInit_InitialTimerShaft */
    /* Entry 'TimeShaft': '<S8>:670' */
    FaultDiagRapidrtDW.failtimeout_cnt = ((UInt16)MACRO_TP_INITCHECK_OUTTIME);
    OpenRelay();

    /* Entry Internal 'TimeShaft': '<S8>:670' */
    /* Transition: '<S8>:903' */
    FaultDiagRapidrtDW.bitsForTID0.is_TimeShaft =
      FaultDiagR_IN_OFF_predrive_Test;
    enter_atomic_OFF_predrive_Test();
    enter_internal_OFF_predrive_Tes();
  } else {
    /* During 'TimeShaft': '<S8>:670' */
    /* Transition: '<S8>:677' */
    if (((Int32)FaultDiagRapidrtDW.failtimeout_cnt) > 0) {
      /* Transition: '<S8>:680' */
      /* Transition: '<S8>:685' */
      FaultDiagRapidrtDW.failtimeout_cnt = (UInt16)((Int32)(((Int32)
        FaultDiagRapidrtDW.failtimeout_cnt) - 1));

      /* Transition: '<S8>:687' */
    } else {
      /* Transition: '<S8>:688' */
    }
    switch (FaultDiagRapidrtDW.bitsForTID0.is_TimeShaft) {
     case FaultDiagRapid_IN_Complete:
      FaultDiagRapid_Complete();
      break;

     case FaultDiagR_IN_OFF_predrive_Test:
      FaultDiagRapi_OFF_predrive_Test();
      break;

     default:
      FaultDiagRapid_ON_predrive();
      break;
    }
  }

  /* End of Chart: '<S6>/DiagInit_InitialTimerShaft' */
  /* End of Outputs for SubSystem: '<S2>/DiagInit_Step0' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
