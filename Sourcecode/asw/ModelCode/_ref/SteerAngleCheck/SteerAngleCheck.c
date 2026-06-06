/*
 * File: SteerAngleCheck.c
 *
 * Code generated for Simulink model 'SteerAngleCheck'.
 *
 * Model version                  : 1.1125
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:35:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SteerAngleCheck.h"
#include "SteerAngleCheck_private.h"

/* Named constants for Chart: '<S3>/RotorCompareCheck' */
#define SteerAngleCh_IN_NO_ACTIVE_CHILD ((UInt8)0U)
#define SteerAngleCheck_IN_Delay       ((UInt8)1U)
#define SteerAngleCheck_IN_Diag        ((UInt8)2U)
#define SteerAngleCheck_IN_Run         ((UInt8)1U)
#define SteerAngleCheck_IN_Wait        ((UInt8)2U)

/* Named constants for Chart: '<S18>/AngleValCheck' */
#define SteerAn_IN_NO_ACTIVE_CHILD_plwn ((UInt8)0U)
#define SteerAngleCheck_IN_Diag_obax   ((UInt8)1U)
#define SteerAngleCheck_IN_Fault       ((UInt8)1U)
#define SteerAngleCheck_IN_Normal      ((UInt8)2U)
#define SteerAngleCheck_IN_Wait_klfp   ((UInt8)2U)

/* Block states (default storage) */
SteerAngleCheck_DW_fwu4 SteerAngleCheckrtDW;

/* Output and update for atomic system: '<S1>/AngleRotorCheck' */
#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0

void SteerAngleCheck_AngleRotorCheck(void)
{
  Bool rtb_precond;
  Int32 Fv_ErrDiagStatus_tmp;

  /* Logic: '<S6>/Logical Operator3' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataStoreRead: '<S6>/Data Store Read'
   *  DataStoreRead: '<S6>/Data Store Read2'
   *  DataStoreRead: '<S6>/Data Store Read3'
   *  DataStoreRead: '<S6>/Data Store Read4'
   *  DataStoreRead: '<S6>/Data Store Read5'
   *  DataStoreRead: '<S6>/Data Store Read6'
   *  DataStoreRead: '<S6>/Data Store Read7'
   *  Inport: '<Root>/WhichMode'
   *  Logic: '<S6>/Logical Operator'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator2'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Sum: '<S6>/Add'
   */
  rtb_precond = (((((WhichMode >= HOLD_ACTIVE) && (Fv_AngleReadyFlag >=
    HELLA_STS_Decode)) && (Fv_FaultClass_Resolver == ((UInt16)0U))) &&
                  (((Fv_SensorPowerTorque >= ((UInt16)MACRO_STRTRQ_POWERMIN)) &&
                    (Fv_SensorPowerTorque <= ((UInt16)MACRO_STRTRQ_POWERMAX))) &&
                   (Fv_SysPower >= (Cal_Power_Low + Cal_PowerWindow)))) &&
                 (((SysTaskResolverSmpPending) && (SysTaskMainRelayPending)) &&
                  (SysTaskTrqSigPending)));

  /* Chart: '<S3>/RotorCompareCheck' incorporates:
   *  DataStoreRead: '<S13>/Data Store Read'
   *  DataStoreRead: '<S14>/Data Store Read'
   *  DataTypeConversion: '<S13>/Data Type Conversion2'
   *  Product: '<S13>/Product'
   *  Selector: '<S13>/Selector'
   *  Selector: '<S14>/Selector'
   */
  /* Gateway: DiagSLow_AngleRotorCheck/AngleRotorCheck/RotorCompareCheck */
  /* During: DiagSLow_AngleRotorCheck/AngleRotorCheck/RotorCompareCheck */
  if (((UInt32)
       SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_active_c68_SteerAngleCheck)
      == 0U) {
    /* Entry: DiagSLow_AngleRotorCheck/AngleRotorCheck/RotorCompareCheck */
    SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_active_c68_SteerAngleCheck
      = 1;

    /* Entry Internal: DiagSLow_AngleRotorCheck/AngleRotorCheck/RotorCompareCheck */
    /* Transition: '<S7>:1653' */
    SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_c68_SteerAngleCheck =
      SteerAngleCheck_IN_Wait;
  } else if (((UInt32)
              SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_c68_SteerAngleCheck)
             == SteerAngleCheck_IN_Run) {
    /* During 'Run': '<S7>:1654' */
    if (!rtb_precond) {
      /* Transition: '<S7>:1656' */
      /* Exit Internal 'Run': '<S7>:1654' */
      SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_Run =
        SteerAngleCh_IN_NO_ACTIVE_CHILD;
      SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_c68_SteerAngleCheck =
        SteerAngleCheck_IN_Wait;
    } else if (((UInt32)SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_Run) ==
               SteerAngleCheck_IN_Delay) {
      /* During 'Delay': '<S7>:1657' */
      if (SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.jumpdiag_flag) {
        /* Transition: '<S7>:1678' */
        SteerAngleCheckrtDW.AngleRotorCheck.hr_diff_fix =
          SteerAngleCheckrtDW.AngleRotorCheck.hr_diff_avr;
        SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_Run =
          SteerAngleCheck_IN_Diag;

        /* Entry 'Diag': '<S7>:1668' */
        SteerAngleCheckrtDW.AngleRotorCheck.hr_err_cnt = ((UInt16)
          MACRO_ANGLE_DIFFTIME);
      } else {
        /* Transition: '<S7>:1684' */
        /* Transition: '<S7>:1660' */
        if (((Int32)SteerAngleCheckrtDW.AngleRotorCheck.rotor_delay_cnt) > 0) {
          /* Transition: '<S7>:1662' */
          /* Transition: '<S7>:1664' */
          SteerAngleCheckrtDW.AngleRotorCheck.rotor_delay_cnt = (UInt16)((Int32)
            (((Int32)SteerAngleCheckrtDW.AngleRotorCheck.rotor_delay_cnt) - 1));
          SteerAngleCheckrtDW.AngleRotorCheck.hr_diff_avr = Fv_ConvStrAng -
            ((Int32)Fv_BasicSteerAngle);

          /* Transition: '<S7>:1687' */
          /* Transition: '<S7>:1688' */
        } else {
          /* Transition: '<S7>:1666' */
          if (SteerAngleCheckrtDW.AngleRotorCheck.rotor_record_cnt < ((UInt16)
               MACRO_ANGLE_CHECKRECNUM)) {
            /* Transition: '<S7>:1680' */
            /* Transition: '<S7>:1682' */
            SteerAngleCheckrtDW.AngleRotorCheck.rotor_record_cnt = (UInt16)
              ((Int32)(((Int32)
                        SteerAngleCheckrtDW.AngleRotorCheck.rotor_record_cnt) +
                       1));
            SteerAngleCheckrtDW.AngleRotorCheck.hr_diff_avr = ((Fv_ConvStrAng -
              ((Int32)Fv_BasicSteerAngle)) +
              SteerAngleCheckrtDW.AngleRotorCheck.hr_diff_avr) / 2;

            /* Transition: '<S7>:1688' */
          } else {
            /* Transition: '<S7>:1686' */
            SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.jumpdiag_flag = true;
          }
        }
      }
    } else {
      /* During 'Diag': '<S7>:1668' */
      /* Transition: '<S7>:1690' */
      Fv_ErrDiagStatus_tmp = (Fv_ConvStrAng - ((Int32)Fv_BasicSteerAngle)) -
        SteerAngleCheckrtDW.AngleRotorCheck.hr_diff_fix;

      if (Fv_ErrDiagStatus_tmp < 0) {
        Fv_ErrDiagStatus_tmp = -Fv_ErrDiagStatus_tmp;
      }
      if (Fv_ErrDiagStatus_tmp > MACRO_ANGLE_CHECKDIFF) {
        /* Transition: '<S7>:1693' */
        /* Transition: '<S7>:1695' */
        if (((Int32)SteerAngleCheckrtDW.AngleRotorCheck.hr_err_cnt) > 0) {
          /* Transition: '<S7>:1697' */
          /* Transition: '<S7>:1699' */
          SteerAngleCheckrtDW.AngleRotorCheck.hr_err_cnt = (UInt16)((Int32)
            (((Int32)SteerAngleCheckrtDW.AngleRotorCheck.hr_err_cnt) - 1));

          /* Transition: '<S7>:1702' */
        } else {
          /* Outputs for Function Call SubSystem: '<S7>/DTC_Ctrl_Enabled' */
          /* Selector: '<S13>/Selector' */
          /* Transition: '<S7>:1701' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S7>:1723' */
          Fv_ErrDiagStatus_tmp = DTC_ANGLEcheck_CheckRotor;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_Err));

          /* End of Outputs for SubSystem: '<S7>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S7>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S7>:1726' */
          Fv_FaultClass_Angle = (UInt16)SetU16Fault(Fv_FaultClass_Angle, 4,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_ANGLEcheck_CheckRotor].Enabled);

          /* End of Outputs for SubSystem: '<S7>/getDTCEnabled' */
        }

        /* Transition: '<S7>:1705' */
      } else {
        /* Transition: '<S7>:1704' */
        SteerAngleCheckrtDW.AngleRotorCheck.hr_err_cnt = ((UInt16)
          MACRO_ANGLE_DIFFTIME);
      }
    }
  } else {
    /* During 'Wait': '<S7>:1652' */
    if (rtb_precond) {
      /* Transition: '<S7>:1655' */
      SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_c68_SteerAngleCheck =
        SteerAngleCheck_IN_Run;

      /* Entry Internal 'Run': '<S7>:1654' */
      /* Transition: '<S7>:1658' */
      SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.is_Run =
        SteerAngleCheck_IN_Delay;

      /* Entry 'Delay': '<S7>:1657' */
      SteerAngleCheckrtDW.AngleRotorCheck.rotor_delay_cnt = ((UInt16)
        MACRO_ANGLE_DELAYTIME);
      SteerAngleCheckrtDW.AngleRotorCheck.rotor_record_cnt = 0U;
      SteerAngleCheckrtDW.AngleRotorCheck.hr_diff_avr = Fv_ConvStrAng - ((Int32)
        Fv_BasicSteerAngle);
      SteerAngleCheckrtDW.AngleRotorCheck.bitsForTID0.jumpdiag_flag = false;
    }
  }

  /* End of Chart: '<S3>/RotorCompareCheck' */
}

#endif

/* Output and update for atomic system: '<S1>/AngleRotorCheckExn' */
#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

void SteerAngleCh_AngleRotorCheckExn(void)
{
  Float64 tmp;
  Float64 tmp_0;
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S5>/RotorCompareCheckExn' incorporates:
   *  DataStoreRead: '<S16>/Data Store Read'
   *  DataStoreRead: '<S17>/Data Store Read'
   *  DataStoreRead: '<S5>/Data Store Read'
   *  DataTypeConversion: '<S16>/Data Type Conversion2'
   *  Product: '<S16>/Product'
   *  Selector: '<S16>/Selector'
   *  Selector: '<S17>/Selector'
   */
  /* Gateway: DiagSLow_AngleRotorCheck/AngleRotorCheckExn/RotorCompareCheckExn */
  /* During: DiagSLow_AngleRotorCheck/AngleRotorCheckExn/RotorCompareCheckExn */
  /* Entry Internal: DiagSLow_AngleRotorCheck/AngleRotorCheckExn/RotorCompareCheckExn */
  /* Transition: '<S15>:1740' */
  tmp = ((Float64)MACRO_ANGLE_CHECKDIFF) * 0.0625;
  tmp_0 = ((Float64)Fv_StrAngRtr_Diff) * 0.0625;
  if ((tmp_0 > tmp) || (tmp_0 < (-tmp))) {
    /* Transition: '<S15>:1733' */
    /* Transition: '<S15>:1730' */
    if (SteerAngleCheckrtDW.AngleRotorCheckExn.hr_err_cnt < ((UInt16)
         MACRO_ANGLE_DIFFTIME)) {
      /* Transition: '<S15>:1737' */
      /* Transition: '<S15>:1741' */
      SteerAngleCheckrtDW.AngleRotorCheckExn.hr_err_cnt = (UInt16)((Int32)
        (((Int32)SteerAngleCheckrtDW.AngleRotorCheckExn.hr_err_cnt) + 1));

      /* Transition: '<S15>:1742' */
    } else {
      /* Outputs for Function Call SubSystem: '<S15>/DTC_Ctrl_Enabled' */
      /* Selector: '<S16>/Selector' */
      /* Transition: '<S15>:1736' */
      /* Simulink Function 'DTC_Ctrl_Enabled': '<S15>:1723' */
      Fv_ErrDiagStatus_tmp = DTC_ANGLEcheck_CheckRotor;
      Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp].
        Enabled) * ((UInt32)FailureDiag_Err));

      /* End of Outputs for SubSystem: '<S15>/DTC_Ctrl_Enabled' */

      /* Outputs for Function Call SubSystem: '<S15>/getDTCEnabled' */
      /* Simulink Function 'getDTCEnabled': '<S15>:1726' */
      Fv_FaultClass_Angle = (UInt16)SetU16Fault(Fv_FaultClass_Angle, 4,
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
        [DTC_ANGLEcheck_CheckRotor].Enabled);

      /* End of Outputs for SubSystem: '<S15>/getDTCEnabled' */
    }

    /* Transition: '<S15>:1738' */
  } else {
    /* Transition: '<S15>:1731' */
    SteerAngleCheckrtDW.AngleRotorCheckExn.hr_err_cnt = ((UInt16)
      MACRO_ANGLE_DIFFTIME);
  }

  /* End of Chart: '<S5>/RotorCompareCheckExn' */
}

#endif

/* Output and update for atomic system: '<S2>/AngleValCheck' */
#if DIAGDIS_ANGLEVALCHECK == 0

void SteerAngleCheck_AngleValCheck(void)
{
  Bool rtb_precond;
  Int32 Fv_ErrDiagStatus_tmp;

  /* Outputs for Atomic SubSystem: '<S18>/AngleValCond' */
  /* Logic: '<S21>/Logical Operator' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  DataStoreRead: '<S21>/Data Store Read1'
   *  DataStoreRead: '<S21>/Data Store Read2'
   *  DataStoreRead: '<S21>/Data Store Read3'
   *  DataStoreRead: '<S21>/Data Store Read4'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S25>/Compare'
   *  RelationalOperator: '<S26>/Compare'
   *  RelationalOperator: '<S27>/Compare'
   */
  rtb_precond = ((((Fv_AngleReadyFlag == HELLA_STS_Decode) &&
                   (Fv_AngleMidValidFlag == ANGLE_STS_Valid))) && (Fv_SysPower >=
    Cal_Power_LowReset) && (Fv_FaultClass_Torque == 0));

  /* End of Outputs for SubSystem: '<S18>/AngleValCond' */

  /* Chart: '<S18>/AngleValCheck' incorporates:
   *  DataStoreRead: '<S22>/Data Store Read'
   *  DataStoreRead: '<S23>/Data Store Read'
   *  DataTypeConversion: '<S22>/Data Type Conversion2'
   *  Inport: '<Root>/Tv_StrAng_Raw'
   *  Product: '<S22>/Product'
   *  Selector: '<S22>/Selector'
   *  Selector: '<S23>/Selector'
   */
  /* Gateway: DiagSlow_AngleValCheck/AngleValCheck/AngleValCheck */
  /* During: DiagSlow_AngleValCheck/AngleValCheck/AngleValCheck */
  if (((UInt32)
       SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_active_c67_SteerAngleCheck)
      == 0U) {
    /* Entry: DiagSlow_AngleValCheck/AngleValCheck/AngleValCheck */
    SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_active_c67_SteerAngleCheck =
      1;

    /* Entry Internal: DiagSlow_AngleValCheck/AngleValCheck/AngleValCheck */
    /* Entry 'ValidCheck': '<S20>:1546' */
    SteerAngleCheckrtDW.AngleValCheck.AV_TimeWin = 0U;

    /* Entry Internal 'ValidCheck': '<S20>:1546' */
    /* Transition: '<S20>:1547' */
    SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_ValidCheck =
      SteerAngleCheck_IN_Normal;

    /* Entry 'RealCheck': '<S20>:1564' */
    SteerAngleCheckrtDW.AngleValCheck.AR_TimeWin = 0U;
    SteerAngleCheckrtDW.AngleValCheck.ARj_TimeWin = 0U;

    /* Entry Internal 'RealCheck': '<S20>:1564' */
    /* Transition: '<S20>:1566' */
    SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_RealCheck =
      SteerAngleCheck_IN_Wait_klfp;
  } else {
    /* During 'ValidCheck': '<S20>:1546' */
    if (((UInt32)SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_ValidCheck) ==
        SteerAngleCheck_IN_Fault) {
      /* During 'Fault': '<S20>:1550' */
      if (Fv_AngleMidValidFlag != ANGLE_STS_Error) {
        /* Transition: '<S20>:1549' */
        SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_ValidCheck =
          SteerAngleCheck_IN_Normal;
      } else {
        /* Transition: '<S20>:1555' */
        if (((Int32)SteerAngleCheckrtDW.AngleValCheck.AV_TimeWin) > 0) {
          /* Transition: '<S20>:1553' */
          /* Transition: '<S20>:1626' */
          SteerAngleCheckrtDW.AngleValCheck.AV_TimeWin = (UInt16)((Int32)
            (((Int32)SteerAngleCheckrtDW.AngleValCheck.AV_TimeWin) - 1));

          /* Transition: '<S20>:1628' */
        } else {
          /* Outputs for Function Call SubSystem: '<S20>/DTC_Ctrl_Enabled' */
          /* Selector: '<S22>/Selector' */
          /* Transition: '<S20>:1554' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S20>:1658' */
          Fv_ErrDiagStatus_tmp = DTC_ANGLEcheck_Invalid;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_Err));

          /* End of Outputs for SubSystem: '<S20>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S20>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S20>:1654' */
          Fv_FaultClass_Angle = (UInt16)SetU16Fault(Fv_FaultClass_Angle, 1,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_ANGLEcheck_Invalid].Enabled);

          /* End of Outputs for SubSystem: '<S20>/getDTCEnabled' */
        }
      }
    } else {
      /* During 'Normal': '<S20>:1556' */
      if (Fv_AngleMidValidFlag == ANGLE_STS_Error) {
        /* Transition: '<S20>:1548' */
        SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_ValidCheck =
          SteerAngleCheck_IN_Fault;

        /* Entry 'Fault': '<S20>:1550' */
        SteerAngleCheckrtDW.AngleValCheck.AV_TimeWin = ((UInt16)
          MACRO_ANGLE_CHECKTIME);
      }
    }

    /* During 'RealCheck': '<S20>:1564' */
    if (((UInt32)SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_RealCheck) ==
        SteerAngleCheck_IN_Diag_obax) {
      /* During 'Diag': '<S20>:1568' */
      if (!rtb_precond) {
        /* Transition: '<S20>:1565' */
        /* Exit Internal 'Diag': '<S20>:1568' */
        SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_Diag =
          SteerAn_IN_NO_ACTIVE_CHILD_plwn;
        SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_RealCheck =
          SteerAngleCheck_IN_Wait_klfp;
      } else if (((UInt32)SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_Diag)
                 == SteerAngleCheck_IN_Fault) {
        /* During 'Fault': '<S20>:1578' */
        if ((Tv_StrAng_Raw <= ((Int16)MACRO_ANGLE_UNREALMAX)) && (Tv_StrAng_Raw >=
             (-((Int16)MACRO_ANGLE_UNREALMAX)))) {
          /* Transition: '<S20>:1570' */
          SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_Diag =
            SteerAngleCheck_IN_Normal;

          /* Entry 'Normal': '<S20>:1572' */
          SteerAngleCheckrtDW.AngleValCheck.ARj_TimeWin = ((UInt16)
            MACRO_ANGLE_CHECKTIME);
        } else {
          /* Transition: '<S20>:1582' */
          if (((Int32)SteerAngleCheckrtDW.AngleValCheck.AR_TimeWin) > 0) {
            /* Transition: '<S20>:1581' */
            /* Transition: '<S20>:1648' */
            SteerAngleCheckrtDW.AngleValCheck.AR_TimeWin = (UInt16)((Int32)
              (((Int32)SteerAngleCheckrtDW.AngleValCheck.AR_TimeWin) - 1));

            /* Transition: '<S20>:1650' */
          } else {
            /* Outputs for Function Call SubSystem: '<S20>/DTC_Ctrl_Enabled' */
            /* Transition: '<S20>:1583' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S20>:1658' */
            Fv_ErrDiagStatus[DTC_ANGLEcheck_Unreal] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_ANGLEcheck_Unreal].Enabled) * ((UInt32)FailureDiag_Err));

            /* End of Outputs for SubSystem: '<S20>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S20>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S20>:1654' */
            Fv_FaultClass_Angle = (UInt16)SetU16Fault(Fv_FaultClass_Angle, 2,
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_ANGLEcheck_Unreal].Enabled);

            /* End of Outputs for SubSystem: '<S20>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S20>:1572' */
        if ((Tv_StrAng_Raw > ((Int16)MACRO_ANGLE_UNREALMAX)) || (Tv_StrAng_Raw <
             (-((Int16)MACRO_ANGLE_UNREALMAX)))) {
          /* Transition: '<S20>:1569' */
          SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_Diag =
            SteerAngleCheck_IN_Fault;

          /* Entry 'Fault': '<S20>:1578' */
          SteerAngleCheckrtDW.AngleValCheck.AR_TimeWin = ((UInt16)
            MACRO_ANGLE_CHECKTIME);
        } else {
          /* Transition: '<S20>:1576' */
          if (((Int32)SteerAngleCheckrtDW.AngleValCheck.ARj_TimeWin) > 0) {
            /* Transition: '<S20>:1575' */
            /* Transition: '<S20>:1635' */
            SteerAngleCheckrtDW.AngleValCheck.ARj_TimeWin = (UInt16)((Int32)
              (((Int32)SteerAngleCheckrtDW.AngleValCheck.ARj_TimeWin) - 1));

            /* Transition: '<S20>:1637' */
          } else {
            /* Outputs for Function Call SubSystem: '<S20>/DTC_Ctrl_Enabled' */
            /* Selector: '<S22>/Selector' */
            /* Transition: '<S20>:1577' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S20>:1658' */
            Fv_ErrDiagStatus_tmp = DTC_ANGLEcheck_Unreal;
            Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [Fv_ErrDiagStatus_tmp].Enabled) * ((UInt32)FailureDiag_OK));

            /* End of Outputs for SubSystem: '<S20>/DTC_Ctrl_Enabled' */
            Fv_FaultClass_Angle = (UInt16)ClrU16Varit(Fv_FaultClass_Angle, 2);
          }
        }
      }
    } else {
      /* During 'Wait': '<S20>:1584' */
      if (rtb_precond) {
        /* Transition: '<S20>:1567' */
        SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_RealCheck =
          SteerAngleCheck_IN_Diag_obax;

        /* Entry Internal 'Diag': '<S20>:1568' */
        /* Transition: '<S20>:1571' */
        SteerAngleCheckrtDW.AngleValCheck.bitsForTID0.is_Diag =
          SteerAngleCheck_IN_Normal;

        /* Entry 'Normal': '<S20>:1572' */
        SteerAngleCheckrtDW.AngleValCheck.ARj_TimeWin = ((UInt16)
          MACRO_ANGLE_CHECKTIME);
      }
    }
  }

  /* End of Chart: '<S18>/AngleValCheck' */
}

#endif

/* Output and update for referenced model: 'SteerAngleCheck' */
void SteerAngleCheck(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/DiagSLow_AngleRotorCheck' */
#if DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0

  SteerAngleCheck_AngleRotorCheck(); 

#elif DIAGDIS_ANGLEROTORCHECK == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

  SteerAngleCh_AngleRotorCheckExn();

#endif

  /* End of Outputs for SubSystem: '<Root>/DiagSLow_AngleRotorCheck' */

  /* Outputs for Atomic SubSystem: '<Root>/DiagSlow_AngleValCheck' */
#if DIAGDIS_ANGLEVALCHECK == 0

  SteerAngleCheck_AngleValCheck();

#endif

  /* End of Outputs for SubSystem: '<Root>/DiagSlow_AngleValCheck' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
