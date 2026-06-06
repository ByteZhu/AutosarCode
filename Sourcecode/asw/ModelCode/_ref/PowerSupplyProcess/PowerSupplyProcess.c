/*
 * File: PowerSupplyProcess.c
 *
 * Code generated for Simulink model 'PowerSupplyProcess'.
 *
 * Model version                  : 1.1126
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:34:13 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PowerSupplyProcess.h"
#include "PowerSupplyProcess_private.h"

/* Named constants for Chart: '<S3>/HoldPowerLatchCheck' */
#define PowerSupplyProcess_IN_Fault    ((UInt8)1U)
#define PowerSupplyProcess_IN_Normal   ((UInt8)2U)

/* Named constants for Chart: '<S4>/IGkeyCANCheck' */
#define PowerSupplyProce_IN_Normal_cp0j ((UInt8)2U)
#define PowerSupplyProces_IN_Fault_eihz ((UInt8)1U)

/* Named constants for Chart: '<S24>/PowerManagement' */
#define PowerSupplyP_IN_TransferStation ((UInt8)6U)
#define PowerSupplyProce_IN_Normal_mvmr ((UInt8)4U)
#define PowerSupplyProcess_IN_Burned   ((UInt8)1U)
#define PowerSupplyProcess_IN_Low      ((UInt8)2U)
#define PowerSupplyProcess_IN_LowReset ((UInt8)3U)
#define PowerSupplyProcess_IN_Over     ((UInt8)5U)

/* Named constants for Chart: '<S31>/ResolverPowerBrownout' */
#define PowerSupplyPro_IN_StateBrownout ((UInt8)1U)
#define PowerSupplyProce_IN_StateNormal ((UInt8)2U)

/* Named constants for Chart: '<S34>/SysPowerBrownout' */
#define PowerSupp_IN_StateBrownout_k2xx ((UInt8)1U)
#define PowerSupply_IN_StateNormal_myn5 ((UInt8)2U)

/* Named constants for Chart: '<S37>/VbatCheck' */
#define PowerSupplyProce_IN_Normal_os02 ((UInt8)2U)
#define PowerSupplyProces_IN_Fault_jc5h ((UInt8)1U)

/* Block states (default storage) */
PowerSupplyProcess_DW_fwu4 PowerSupplyProcessrtDW;

/* Output and update for atomic system: '<S3>/HoldPowerLatchCheck' */
#if DIAGDIS_POWERHOLD == 0

void PowerSupplyProc_OverShuntBYD(void);

void PowerSupply_HoldPowerLatchCheck(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S3>/HoldPowerLatchCheck' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read'
   *  DataStoreRead: '<S8>/Data Store Read'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Inport: '<Root>/WhichMode'
   *  Product: '<S7>/Product'
   *  Selector: '<S7>/Selector'
   *  Selector: '<S8>/Selector'
   */
  /* Gateway: DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheck */
  /* During: DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheck */
  if (((UInt32)
       PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.bitsForTID0.is_active_c55_PowerSupplyProces)
      == 0U) {
    /* Entry: DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheck */
    PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.bitsForTID0.is_active_c55_PowerSupplyProces
      = 1;

    /* Entry Internal: DiagSlow_PowerOthersCheck/PowerOthersCheck_HoldPowerLatch/HoldPowerLatchCheck */
    /* Transition: '<S5>:1559' */
    PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.bitsForTID0.is_c55_PowerSupplyProcess
      = PowerSupplyProcess_IN_Normal;
  } else if (((UInt32)
              PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.bitsForTID0.is_c55_PowerSupplyProcess)
             == PowerSupplyProcess_IN_Fault) {
    /* During 'Fault': '<S5>:1546' */
    if ((Fv_IGkeyEffect) || (Fv_IGkeyVol > ((Int16)MACRO_POWER_HOLDIGVOL))) {
      /* Transition: '<S5>:1557' */
      PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.bitsForTID0.is_c55_PowerSupplyProcess
        = PowerSupplyProcess_IN_Normal;
    } else {
      /* Transition: '<S5>:1551' */
      if (((Int32)PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.hold_cnt) > 0) {
        /* Transition: '<S5>:1552' */
        /* Transition: '<S5>:1553' */
        PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.hold_cnt = (UInt16)((Int32)
          (((Int32)PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.hold_cnt) - 1));

        /* Transition: '<S5>:1555' */
      } else {
        /* Outputs for Function Call SubSystem: '<S5>/DTC_Ctrl_Enabled' */
        /* Selector: '<S7>/Selector' */
        /* Transition: '<S5>:1554' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S5>:1566' */
        Fv_ErrDiagStatus_tmp = DTC_POWERcheck_Hold;
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp].
          Enabled) * ((UInt32)FailureDiag_Err));

        /* End of Outputs for SubSystem: '<S5>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S5>/getDTCEnabled' */
        /* Simulink Function 'getDTCEnabled': '<S5>:1562' */
        Fv_FaultClass_Power = (UInt16)SetU16Fault(Fv_FaultClass_Power, 6,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_POWERcheck_Hold].
          Enabled);

        /* End of Outputs for SubSystem: '<S5>/getDTCEnabled' */
      }
    }
  } else {
    /* During 'Normal': '<S5>:1558' */
    if ((!Fv_IGkeyEffect) && (WhichMode == HOLD_OFF)) {
      /* Transition: '<S5>:1556' */
      PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.bitsForTID0.is_c55_PowerSupplyProcess
        = PowerSupplyProcess_IN_Fault;

      /* Entry 'Fault': '<S5>:1546' */
      PowerSupplyProcessrtDW.sf_HoldPowerLatchCheck.hold_cnt = ((UInt16)
        MACRO_POWER_HOLDTIME);
    }
  }

  /* End of Chart: '<S3>/HoldPowerLatchCheck' */
}

#endif

/* Output and update for atomic system: '<S4>/IGkeyCANCheck' */
#if DIAGDIS_POWERIGCAN == 0

void PowerSupplyProces_IGkeyCANCheck(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S4>/IGkeyCANCheck' incorporates:
   *  DataStoreRead: '<S11>/Data Store Read'
   *  DataStoreRead: '<S12>/Data Store Read'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   *  Inport: '<Root>/CAN_IG_Status'
   *  Product: '<S11>/Product'
   *  Selector: '<S11>/Selector'
   *  Selector: '<S12>/Selector'
   */
  /* Gateway: DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheck */
  /* During: DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheck */
  if (((UInt32)
       PowerSupplyProcessrtDW.sf_IGkeyCANCheck.bitsForTID0.is_active_c92_PowerSupplyProces)
      == 0U) {
    /* Entry: DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheck */
    PowerSupplyProcessrtDW.sf_IGkeyCANCheck.bitsForTID0.is_active_c92_PowerSupplyProces
      = 1;

    /* Entry Internal: DiagSlow_PowerOthersCheck/PowerOthersCheck_IGkeyCAN/IGkeyCANCheck */
    /* Transition: '<S9>:1547' */
    PowerSupplyProcessrtDW.sf_IGkeyCANCheck.bitsForTID0.is_c92_PowerSupplyProcess
      = PowerSupplyProce_IN_Normal_cp0j;

    /* Entry 'Normal': '<S9>:1560' */
    PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15j_cnt = ((UInt16)
      MACRO_POWER_IGTIME);
  } else if (((UInt32)
              PowerSupplyProcessrtDW.sf_IGkeyCANCheck.bitsForTID0.is_c92_PowerSupplyProcess)
             == PowerSupplyProces_IN_Fault_eihz) {
    /* During 'Fault': '<S9>:1549' */
    if ((Fv_IGkeyEffect) || (((Int32)CAN_IG_Status) <= 0)) {
      /* Transition: '<S9>:1548' */
      PowerSupplyProcessrtDW.sf_IGkeyCANCheck.bitsForTID0.is_c92_PowerSupplyProcess
        = PowerSupplyProce_IN_Normal_cp0j;

      /* Entry 'Normal': '<S9>:1560' */
      PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15j_cnt = ((UInt16)
        MACRO_POWER_IGTIME);
    } else {
      /* Transition: '<S9>:1554' */
      if (((Int32)PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15_cnt) > 0) {
        /* Transition: '<S9>:1555' */
        /* Transition: '<S9>:1556' */
        PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15_cnt = (UInt16)((Int32)
          (((Int32)PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15_cnt) - 1));

        /* Transition: '<S9>:1558' */
      } else {
        /* Outputs for Function Call SubSystem: '<S9>/DTC_Ctrl_Enabled' */
        /* Transition: '<S9>:1557' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S9>:1576' */
        Fv_ErrDiagStatus[DTC_POWERcheck_IGkey] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_POWERcheck_IGkey].
          Enabled) * ((UInt32)FailureDiag_Err));

        /* End of Outputs for SubSystem: '<S9>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S9>/getDTCEnabled' */
        /* Simulink Function 'getDTCEnabled': '<S9>:1572' */
        Fv_FaultClass_Power = (UInt16)SetU16Fault(Fv_FaultClass_Power, 7,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_POWERcheck_IGkey].
          Enabled);

        /* End of Outputs for SubSystem: '<S9>/getDTCEnabled' */
      }
    }
  } else {
    /* During 'Normal': '<S9>:1560' */
    if ((!Fv_IGkeyEffect) && (((Int32)CAN_IG_Status) > 0)) {
      /* Transition: '<S9>:1559' */
      PowerSupplyProcessrtDW.sf_IGkeyCANCheck.bitsForTID0.is_c92_PowerSupplyProcess
        = PowerSupplyProces_IN_Fault_eihz;

      /* Entry 'Fault': '<S9>:1549' */
      PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15_cnt = ((UInt16)
        MACRO_POWER_IGTIME);
    } else {
      /* Transition: '<S9>:1565' */
      if (((Int32)PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15j_cnt) > 0) {
        /* Transition: '<S9>:1566' */
        /* Transition: '<S9>:1568' */
        PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15j_cnt = (UInt16)((Int32)
          (((Int32)PowerSupplyProcessrtDW.sf_IGkeyCANCheck.t15j_cnt) - 1));

        /* Transition: '<S9>:1569' */
      } else {
        /* Outputs for Function Call SubSystem: '<S9>/DTC_Ctrl_Enabled' */
        /* Selector: '<S11>/Selector' */
        /* Transition: '<S9>:1567' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S9>:1576' */
        Fv_ErrDiagStatus_tmp = DTC_POWERcheck_IGkey;
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp].
          Enabled) * ((UInt32)FailureDiag_OK));

        /* End of Outputs for SubSystem: '<S9>/DTC_Ctrl_Enabled' */
        Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 7);
      }
    }
  }

  /* End of Chart: '<S4>/IGkeyCANCheck' */
}

#endif

/* Output and update for atomic system: '<Root>/DiagSlow_PowerOthersCheck' */
void Power_DiagSlow_PowerOthersCheck(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/PowerOthersCheck_IGkeyCAN' */
#if DIAGDIS_POWERIGCAN == 0

  PowerSupplyProces_IGkeyCANCheck();

#endif

  /* End of Outputs for SubSystem: '<S1>/PowerOthersCheck_IGkeyCAN' */

  /* Outputs for Atomic SubSystem: '<S1>/PowerOthersCheck_HoldPowerLatch' */
#if DIAGDIS_POWERHOLD == 0

  PowerSupply_HoldPowerLatchCheck();

#endif

  /* End of Outputs for SubSystem: '<S1>/PowerOthersCheck_HoldPowerLatch' */
}

/* Output and update for atomic system: '<S2>/PowerSupplyCheck_EquSysPower' */
void Po_PowerSupplyCheck_EquSysPower(void)
{
  /* Sum: '<S13>/Add1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   *  DataStoreWrite: '<S13>/Data Store Write5'
   *  Inport: '<Root>/AD_PowerSys'
   *  Product: '<S13>/Product'
   */
  Fv_SysPowerVbat = (Int16)(((Int32)((UInt32)((((UInt32)AD_PowerSys) * ((UInt32)
    ((UInt16)MACRO_AV_POWER_SCALE))) >> 9))) + ((Int32)((Int16)
    MACRO_AV_POWER_OFFSET)));

  /* Outputs for Atomic SubSystem: '<S13>/JudgeVbat' */
#if DIAGDIS_POWERVBAT == 0

  /* Output and update for atomic system: '<S16>/JudgeVbat_VBRIG' */
  {
    Bool rtb_Compare;
    Int16 rtb_Abs1;
    Bool precond_h;

    /* Sum: '<S17>/Add2' incorporates:
     *  DataStoreRead: '<S17>/Data Store Read2'
     *  DataStoreWrite: '<S13>/Data Store Write5'
     */
    rtb_Abs1 = (Int16)(Fv_SysPowerVbat - Fv_IGkeyVol);

    /* Abs: '<S17>/Abs' */
    if (rtb_Abs1 < 0) {
      rtb_Abs1 = (Int16)(-rtb_Abs1);
    }

    /* End of Abs: '<S17>/Abs' */

    /* RelationalOperator: '<S19>/Compare' incorporates:
     *  Constant: '<S19>/Constant'
     */
    rtb_Compare = (rtb_Abs1 > ((Int16)MACRO_POWER_IGNBREAK));

    /* Sum: '<S17>/Add3' incorporates:
     *  DataStoreRead: '<S17>/Data Store Read3'
     *  DataStoreWrite: '<S13>/Data Store Write5'
     */
    rtb_Abs1 = (Int16)(Fv_SysPowerVbat - Fv_SysPowerRelay);

    /* Abs: '<S17>/Abs1' */
    if (rtb_Abs1 < 0) {
      rtb_Abs1 = (Int16)(-rtb_Abs1);
    }

    /* End of Abs: '<S17>/Abs1' */

    /* Logic: '<S17>/Logical Operator' incorporates:
     *  DataStoreRead: '<S17>/Data Store Read'
     *  DataStoreRead: '<S17>/Data Store Read1'
     */
    precond_h = ((Fv_IGkeyEffect) && (SysTaskMainRelayPending));

    /* Chart: '<S17>/CondCounter' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S22>/Constant'
     *  DataStoreRead: '<S17>/Data Store Read4'
     *  Logic: '<S17>/Logical Operator1'
     *  RelationalOperator: '<S20>/Compare'
     *  RelationalOperator: '<S22>/Compare'
     */
    /* Gateway: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/CondCounter */
    /* During: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/CondCounter */
    /* Entry Internal: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_EquSysPower/JudgeVbat/JudgeVbat_VBRIG/CondCounter */
    /* Transition: '<S23>:1226' */
    if (precond_h) {
      /* Transition: '<S23>:1228' */
      if ((rtb_Compare && (rtb_Abs1 > ((Int16)MACRO_SHUTDOWN_MOSBREAK))) &&
          (Arg82800V5cOkFlag == false)) {
        /* Transition: '<S23>:1230' */
        /* Transition: '<S23>:1232' */
        PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt2 = 0U;
        if (PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt1 < ((UInt16)
             MACRO_POWER_ALTERTIME)) {
          /* Transition: '<S23>:1234' */
          /* Transition: '<S23>:1236' */
          PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt1 = (UInt16)((Int32)
            (((Int32)PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt1) + 1));
        } else {
          /* Transition: '<S23>:1238' */
          PowerSupplyProcessrtDW.JudgeVbat_VBRIG.SysTaskVbatAbnormalPending_pqfw
            = true;

          /* Transition: '<S23>:1240' */
        }

        /* Transition: '<S23>:1250' */
        /* Transition: '<S23>:1251' */
        /* Transition: '<S23>:1252' */
      } else {
        /* Transition: '<S23>:1242' */
        PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt1 = 0U;
        if (PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt2 < ((UInt16)
             MACRO_POWER_ALRECOVERTIME)) {
          /* Transition: '<S23>:1244' */
          /* Transition: '<S23>:1246' */
          PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt2 = (UInt16)((Int32)
            (((Int32)PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt2) + 1));

          /* Transition: '<S23>:1252' */
        } else {
          /* Transition: '<S23>:1248' */
          PowerSupplyProcessrtDW.JudgeVbat_VBRIG.SysTaskVbatAbnormalPending_pqfw
            = false;
        }
      }

      /* Transition: '<S23>:1255' */
    } else {
      /* Transition: '<S23>:1254' */
      PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt1 = 0U;
      PowerSupplyProcessrtDW.JudgeVbat_VBRIG.alter_batcnt2 = 0U;
    }

    /* End of Chart: '<S17>/CondCounter' */

    /* DataStoreWrite: '<S17>/Data Store Write' */
    SysTaskVbatAbnormalPending =
      PowerSupplyProcessrtDW.JudgeVbat_VBRIG.SysTaskVbatAbnormalPending_pqfw;

    /* Switch: '<S17>/Switch' incorporates:
     *  DataStoreWrite: '<S13>/Data Store Write5'
     *  DataStoreWrite: '<S17>/Data Store Write1'
     *  Logic: '<S17>/Logical Operator2'
     */
    if ((PowerSupplyProcessrtDW.JudgeVbat_VBRIG.SysTaskVbatAbnormalPending_pqfw)
        && precond_h) {
      /* Switch: '<S17>/Switch1' incorporates:
       *  DataStoreRead: '<S17>/Data Store Read2'
       *  DataStoreRead: '<S17>/Data Store Read3'
       *  RelationalOperator: '<S17>/Relational Operator'
       */
      if (Fv_IGkeyVol > Fv_SysPowerRelay) {
        rtb_Abs1 = Fv_IGkeyVol;
      } else {
        rtb_Abs1 = Fv_SysPowerRelay;
      }

      /* End of Switch: '<S17>/Switch1' */

      /* Switch: '<S17>/Switch2' incorporates:
       *  Constant: '<S17>/Constant2'
       *  Constant: '<S17>/Constant3'
       *  Constant: '<S21>/Constant'
       *  RelationalOperator: '<S21>/Compare'
       *  Sum: '<S17>/Add4'
       *  Sum: '<S17>/Add5'
       */
      if (rtb_Abs1 >= ((Int16)MACRO_POWER_STANDARDVOL)) {
        Fv_SysPower = (Int16)(((Int16)MACRO_SHUTDOWN_MOSBREAK) + rtb_Abs1);
      } else {
        Fv_SysPower = (Int16)(rtb_Abs1 - ((Int16)MACRO_SHUTDOWN_MOSBREAK));
      }

      /* End of Switch: '<S17>/Switch2' */

      /* Saturate: '<S17>/Saturation' incorporates:
       *  DataStoreWrite: '<S17>/Data Store Write1'
       */
      if (Fv_SysPower > 3840) {
        Fv_SysPower = 3840;
      } else {
        if (Fv_SysPower < 0) {
          Fv_SysPower = 0;
        }
      }

      /* End of Saturate: '<S17>/Saturation' */
    } else {
      Fv_SysPower = Fv_SysPowerVbat;
    }

    /* End of Switch: '<S17>/Switch' */
  }

#elif DIAGDIS_POWERVBAT == 1

  /* Output and update for atomic system: '<S16>/JudgeVbat_VBRIGDIS' */

  /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
   *  Constant: '<S18>/Constant'
   */
  SysTaskVbatAbnormalPending = false;

  /* DataStoreWrite: '<S18>/Data Store Write1' incorporates:
   *  DataStoreWrite: '<S13>/Data Store Write5'
   */
  Fv_SysPower = Fv_SysPowerVbat;

#endif

  /* End of Outputs for SubSystem: '<S13>/JudgeVbat' */
}

/* Output and update for atomic system: '<S14>/PowerLevelCheck' */
#if DIAGDIS_POWERLEVEL == 0

void PowerSupplyProc_PowerLevelCheck(void)
{
  Int32 tmp;

  PowerSupplyProc_OverShuntBYD();


  /* Chart: '<S24>/PowerManagement' incorporates:
   *  DataStoreRead: '<S24>/Data Store Read'
   *  DataStoreRead: '<S27>/Data Store Read'
   *  Selector: '<S27>/Selector'
   */
  /* Gateway: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheck/PowerManagement */
  /* During: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheck/PowerManagement */
  if (((UInt32)
       PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_active_c64_PowerSupplyProces)
      == 0U) {
    /* Entry: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheck/PowerManagement */
    PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_active_c64_PowerSupplyProces
      = 1;

    /* Entry Internal: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_PowerLevel/PowerLevelCheck/PowerManagement */
    /* Transition: '<S26>:1275' */
    PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
      = PowerSupplyProce_IN_Normal_mvmr;
  } else {
    switch
      (PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess)
    {
     case PowerSupplyProcess_IN_Burned:
      /* During 'Burned': '<S26>:1268' */
      if (Fv_SysPower <= Cal_Power_Over) {
        /* Transition: '<S26>:1293' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyP_IN_TransferStation;
      } else {
        /* Transition: '<S26>:1271' */
        if (((Int32)PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime) >
            0) {
          /* Transition: '<S26>:1272' */
          /* Transition: '<S26>:1376' */
          PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = (UInt16)
            ((Int32)(((Int32)
                      PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime)
                     - 1));

          /* Transition: '<S26>:1378' */
          /* Transition: '<S26>:1462' */
        } else {
          /* Outputs for Function Call SubSystem: '<S26>/getDTCEnabled' */
          /* Selector: '<S27>/Selector' */
          /* Transition: '<S26>:1457' */
          /* Simulink Function 'getDTCEnabled': '<S26>:1437' */
          tmp = DTC_POWERcheck_Burned;
          if (((Int32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[tmp].
               Enabled) != 0) {
            /* Transition: '<S26>:1459' */
            /* Transition: '<S26>:1273' */
            Fv_BatVoltLevel = BAT_VOLT_BURNED;
            Fv_ErrDiagStatus[(tmp)] = FailureDiag_Err;
            Fv_ErrDiagStatus[DTC_POWERcheck_LowReset] = FailureDiag_OK;
            //Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_OK;
            Fv_ErrDiagStatus[DTC_POWERcheck_LowShut] = FailureDiag_OK;
            Fv_FaultClass_Power = (UInt16)SetU16Varit(Fv_FaultClass_Power, 0);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 1);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 2);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 3);

            /* Transition: '<S26>:1462' */
          } else {
            /* Transition: '<S26>:1461' */
          }

          /* End of Outputs for SubSystem: '<S26>/getDTCEnabled' */
        }
      }
      break;

     case PowerSupplyProcess_IN_Low:
      /* During 'Low': '<S26>:1282' */
      if ((Fv_SysPower < Cal_Power_LowReset) || (Fv_SysPower >= Cal_Power_Low))
      {
        /* Transition: '<S26>:1317' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyP_IN_TransferStation;
      } else {
        /* Transition: '<S26>:1346' */
        if (((Int32)PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime) >
            0) {
          /* Transition: '<S26>:1348' */
          /* Transition: '<S26>:1350' */
          PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = (UInt16)
            ((Int32)(((Int32)
                      PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime)
                     - 1));

          /* Transition: '<S26>:1360' */
          /* Transition: '<S26>:1359' */
          /* Transition: '<S26>:1434' */
        } else {
          /* Outputs for Function Call SubSystem: '<S26>/getDTCEnabled' */
          /* Selector: '<S27>/Selector' */
          /* Transition: '<S26>:1429' */
          /* Simulink Function 'getDTCEnabled': '<S26>:1437' */
          tmp = DTC_POWERcheck_LowShut;
          if (((Int32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[tmp].
               Enabled) != 0) {
            /* Transition: '<S26>:1430' */
            /* Transition: '<S26>:1352' */
            Fv_BatVoltLevel = BAT_VOLT_LOW;
            Fv_ErrDiagStatus[DTC_POWERcheck_Burned] = FailureDiag_OK;
            Fv_ErrDiagStatus[DTC_POWERcheck_LowReset] = FailureDiag_OK;
            //Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_OK;
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 0);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 1);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 2);
            if (((Int32)PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime) >
                0) {
              /* Transition: '<S26>:1354' */
              /* Transition: '<S26>:1356' */
              PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime = (UInt16)
                ((Int32)(((Int32)
                          PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime)
                         - 1));

              /* Transition: '<S26>:1359' */
              /* Transition: '<S26>:1434' */
            } else {
              /* Transition: '<S26>:1358' */
              Fv_ErrDiagStatus[(tmp)] = FailureDiag_Err;
              Fv_FaultClass_Power = (UInt16)SetU16Varit(Fv_FaultClass_Power, 3);

              /* Transition: '<S26>:1434' */
            }
          } else {
            /* Transition: '<S26>:1432' */
          }

          /* End of Outputs for SubSystem: '<S26>/getDTCEnabled' */
        }
      }
      break;

     case PowerSupplyProcess_IN_LowReset:
      /* During 'LowReset': '<S26>:1276' */
      if (Fv_SysPower >= Cal_Power_LowReset) {
        /* Transition: '<S26>:1264' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyP_IN_TransferStation;
      } else {
        /* Transition: '<S26>:1366' */
        if (((Int32)PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime) >
            0) {
          /* Transition: '<S26>:1368' */
          /* Transition: '<S26>:1370' */
          PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = (UInt16)
            ((Int32)(((Int32)
                      PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime)
                     - 1));

          /* Transition: '<S26>:1373' */
          /* Transition: '<S26>:1454' */
        } else {
          /* Outputs for Function Call SubSystem: '<S26>/getDTCEnabled' */
          /* Selector: '<S27>/Selector' */
          /* Transition: '<S26>:1440' */
          /* Simulink Function 'getDTCEnabled': '<S26>:1437' */
          tmp = DTC_POWERcheck_LowReset;
          if (((Int32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[tmp].
               Enabled) != 0) {
            /* Transition: '<S26>:1442' */
            /* Transition: '<S26>:1372' */
            Fv_BatVoltLevel = BAT_VOLT_LOWRESET;
            Fv_ErrDiagStatus[DTC_POWERcheck_Burned] = FailureDiag_OK;
            Fv_ErrDiagStatus[(tmp)] = FailureDiag_Err;
            //Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_OK;
            Fv_ErrDiagStatus[DTC_POWERcheck_LowShut] = FailureDiag_OK;
            Fv_FaultClass_Power = (UInt16)SetU16Varit(Fv_FaultClass_Power, 1);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 0);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 2);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 3);

            /* Transition: '<S26>:1454' */
          } else {
            /* Transition: '<S26>:1444' */
          }

          /* End of Outputs for SubSystem: '<S26>/getDTCEnabled' */
        }
      }
      break;

     case PowerSupplyProce_IN_Normal_mvmr:
      /* During 'Normal': '<S26>:1306' */
      if ((Fv_SysPower < Cal_Power_Low) || (Fv_SysPower > Cal_Power_High)) {
        /* Transition: '<S26>:1262' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyP_IN_TransferStation;
      } else {
        /* Transition: '<S26>:1320' */
        if (((Int32)PowerSupplyProcessrtDW.PowerLevelCheck.PowerNormalTime) > 0)
        {
          /* Transition: '<S26>:1322' */
          /* Transition: '<S26>:1324' */
          PowerSupplyProcessrtDW.PowerLevelCheck.PowerNormalTime = (UInt16)
            ((Int32)(((Int32)
                      PowerSupplyProcessrtDW.PowerLevelCheck.PowerNormalTime) -
                     1));

          /* Transition: '<S26>:1334' */
        } else {
          /* Transition: '<S26>:1326' */
          /* Transition: '<S26>:1328' */
          /* Transition: '<S26>:1330' */
          Fv_BatVoltLevel = BAT_VOLT_NORMAL;
          Fv_ErrDiagStatus[DTC_POWERcheck_Burned] = FailureDiag_OK;
          Fv_ErrDiagStatus[DTC_POWERcheck_LowReset] = FailureDiag_OK;
          //Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_OK;
          Fv_ErrDiagStatus[DTC_POWERcheck_LowShut] = FailureDiag_OK;
          Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 0);
          Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 1);
          Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 2);
          Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 3);
        }
      }
      break;

     case PowerSupplyProcess_IN_Over:
      /* During 'Over': '<S26>:1295' */
      if ((Fv_SysPower <= Cal_Power_High) || (Fv_SysPower > Cal_Power_Over)) {
        /* Transition: '<S26>:1265' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyP_IN_TransferStation;
      } else {
        /* Transition: '<S26>:1384' */
        if (((Int32)PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime) >
            0) {
          /* Transition: '<S26>:1392' */
          /* Transition: '<S26>:1393' */
          PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = (UInt16)
            ((Int32)(((Int32)
                      PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime)
                     - 1));

          /* Transition: '<S26>:1379' */
          /* Transition: '<S26>:1382' */
          /* Transition: '<S26>:1453' */
        } else {
          /* Outputs for Function Call SubSystem: '<S26>/getDTCEnabled' */
          /* Selector: '<S27>/Selector' */
          /* Transition: '<S26>:1448' */
          /* Simulink Function 'getDTCEnabled': '<S26>:1437' */
          tmp = DTC_POWERcheck_OverShut;
          if (((Int32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[tmp].
               Enabled) != 0) {
            /* Transition: '<S26>:1450' */
            /* Transition: '<S26>:1385' */
            Fv_BatVoltLevel = BAT_VOLT_OVER;
            Fv_ErrDiagStatus[DTC_POWERcheck_Burned] = FailureDiag_OK;
            Fv_ErrDiagStatus[DTC_POWERcheck_LowReset] = FailureDiag_OK;
            Fv_ErrDiagStatus[DTC_POWERcheck_LowShut] = FailureDiag_OK;
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 0);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 1);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 3);
            if (((Int32)PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime) >
                0) {
              /* Transition: '<S26>:1388' */
              /* Transition: '<S26>:1380' */
              PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime = (UInt16)
                ((Int32)(((Int32)
                          PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime)
                         - 1));

              /* Transition: '<S26>:1382' */
              /* Transition: '<S26>:1453' */
            } else {
              /* Transition: '<S26>:1390' */
              //Fv_ErrDiagStatus[(tmp)] = FailureDiag_Err;
              Fv_FaultClass_Power = (UInt16)SetU16Varit(Fv_FaultClass_Power, 2);

              /* Transition: '<S26>:1453' */
            }
          } else {
            /* Transition: '<S26>:1451' */
          }

          /* End of Outputs for SubSystem: '<S26>/getDTCEnabled' */
        }
      }
      break;

     default:
      /* During 'TransferStation': '<S26>:1318' */
      if ((Fv_SysPower >= (Cal_Power_Low + Cal_PowerWindow)) && (Fv_SysPower <=
           (Cal_Power_High - Cal_PowerWindow))) {
        /* Transition: '<S26>:1267' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyProce_IN_Normal_mvmr;
      } else if ((Fv_SysPower >= Cal_Power_LowReset) && (Fv_SysPower <
                  Cal_Power_Low)) {
        /* Transition: '<S26>:1274' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyProcess_IN_Low;

        /* Entry 'Low': '<S26>:1282' */
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = ((UInt16)
          MACRO_POWER_ABNORMALTIME);
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerNormalTime = ((UInt16)
          MACRO_POWER_LOWTIME);
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime = ((UInt16)
          MACRO_POWER_SHUTIME);
      } else if ((Fv_SysPower > Cal_Power_High) && (Fv_SysPower <=
                  Cal_Power_Over)) {
        /* Transition: '<S26>:1263' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyProcess_IN_Over;

        /* Entry 'Over': '<S26>:1295' */
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = ((UInt16)
          MACRO_POWER_ABNORMALTIME);
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerNormalTime = ((UInt16)
          MACRO_POWER_OVERTIME);
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerShutTime = ((UInt16)
          MACRO_POWER_SHUTIME);
      } else if (Fv_SysPower < Cal_Power_LowReset) {
        /* Transition: '<S26>:1294' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyProcess_IN_LowReset;

        /* Entry 'LowReset': '<S26>:1276' */
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = ((UInt16)
          MACRO_POWER_ABNORMALTIME);
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerNormalTime = ((UInt16)
          MACRO_POWER_LOWRESETTIME);
      } else if (Fv_SysPower > Cal_Power_Over) {
        /* Transition: '<S26>:1266' */
        PowerSupplyProcessrtDW.PowerLevelCheck.bitsForTID0.is_c64_PowerSupplyProcess
          = PowerSupplyProcess_IN_Burned;

        /* Entry 'Burned': '<S26>:1268' */
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerAbnormalTime = ((UInt16)
          MACRO_POWER_ABNORMALTIME);
        PowerSupplyProcessrtDW.PowerLevelCheck.PowerNormalTime = ((UInt16)
          MACRO_POWER_BURNEDTIME);
      } else {
        /* Transition: '<S26>:1397' */
        if (Fv_LowFailCoef == 32768) {
          /* Transition: '<S26>:1399' */
          if ((Fv_BatVoltLevel == BAT_VOLT_LOW) &&
              (Fv_ErrDiagStatus[DTC_POWERcheck_LowShut] < FailureDiag_Err)) {
            /* Transition: '<S26>:1401' */
            /* Transition: '<S26>:1403' */
            Fv_ErrDiagStatus[DTC_POWERcheck_Burned] = FailureDiag_OK;
            Fv_ErrDiagStatus[DTC_POWERcheck_LowReset] = FailureDiag_OK;
            //Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_OK;
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 0);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 1);
            Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 2);
            Fv_ErrDiagStatus[DTC_POWERcheck_LowShut] = FailureDiag_Err;
            Fv_FaultClass_Power = (UInt16)SetU16Varit(Fv_FaultClass_Power, 3);

            /* Transition: '<S26>:1414' */
            /* Transition: '<S26>:1415' */
          } else {
            /* Transition: '<S26>:1405' */
            if ((Fv_BatVoltLevel == BAT_VOLT_OVER) &&
                (Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] < FailureDiag_Err)) {
              /* Transition: '<S26>:1409' */
              /* Transition: '<S26>:1411' */
              Fv_ErrDiagStatus[DTC_POWERcheck_Burned] = FailureDiag_OK;
              Fv_ErrDiagStatus[DTC_POWERcheck_LowReset] = FailureDiag_OK;
              Fv_ErrDiagStatus[DTC_POWERcheck_LowShut] = FailureDiag_OK;
              Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 0);
              Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 1);
              Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 3);
              //Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_Err;
              Fv_FaultClass_Power = (UInt16)SetU16Varit(Fv_FaultClass_Power, 2);

              /* Transition: '<S26>:1415' */
            } else {
              /* Transition: '<S26>:1413' */
            }
          }

          /* Transition: '<S26>:1416' */
        } else {
          /* Transition: '<S26>:1407' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S24>/PowerManagement' */
}

enum{
  BYD_Over,
  BYD_Burned,
  BYD_notOver,
  BYD_Trans
};
#define BYD_Volt_High Cal_Power_High /*16V*/
#define BYD_Volt_Burn Cal_Power_Over /*24V*/
#define BYD_Volt_Step 64 /*0.5V*/
void PowerSupplyProc_OverShuntBYD(void)
{
  static UInt8 initFlag = 0;
  static UInt8 powerStateBYD = 0;
  static UInt16 toBurnCnt = 0;
  static UInt16 toOverCnt = 0;
  if(initFlag == 0)
  {
    initFlag = 1;
    powerStateBYD = BYD_notOver;
    toBurnCnt = 0;
    toOverCnt = 0;
  }
  else
  {
    switch(powerStateBYD)
    {
      case BYD_notOver:
        if(Fv_SysPower > BYD_Volt_High)
        {
          powerStateBYD = BYD_Trans;
          toBurnCnt = 0;
          toOverCnt = 0;
        }
        else
        {
          Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_OK;
        }
      break;
      case BYD_Burned:
        if((Fv_SysPower < BYD_Volt_Burn))
        {
          powerStateBYD = BYD_Trans;
          toBurnCnt = 0;
          toOverCnt = 0;
        }
        else
        {
          Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_OK;
        }
      break;
      case BYD_Over:
        if((Fv_SysPower > BYD_Volt_Burn) || (Fv_SysPower < BYD_Volt_High))
        {
          powerStateBYD = BYD_Trans;
          toBurnCnt = 0;
          toOverCnt = 0;
        }
        else
        {
          Fv_ErrDiagStatus[DTC_POWERcheck_OverShut] = FailureDiag_Err;
        }
      break;
      default:
      /*BYD_Trans*/

        if((Fv_SysPower > BYD_Volt_High) && (Fv_SysPower < BYD_Volt_Burn))
        {
          if(toOverCnt < 100)
          {
            toOverCnt++;
          }
          else
          {
            powerStateBYD = BYD_Over;
            toBurnCnt = 0;
          }
        }
        else if(Fv_SysPower > BYD_Volt_Burn)
        {
          if(toBurnCnt < 100)
          {
            toBurnCnt++;
          }
          else
          {
            powerStateBYD = BYD_Burned;
            toOverCnt = 0;
          }
        }
        else if(Fv_SysPower < (BYD_Volt_High - BYD_Volt_Step))
        {
          powerStateBYD = BYD_notOver;
          toOverCnt = 0;
          toBurnCnt = 0;
        }
        else if((Fv_SysPower < (BYD_Volt_Burn - BYD_Volt_Step)) && (Fv_SysPower > BYD_Volt_High))
        {
          if(toOverCnt < 100)
          {
            toOverCnt++;
          }
          else
          {
            powerStateBYD = BYD_Over;
            toBurnCnt = 0;
          }
        }
        else
        {}
      break;      
    }
  }
}
#endif

/* Output and update for atomic system: '<S14>/PowerLevelCheckDis' */
#if DIAGDIS_POWERLEVEL == 1

void PowerSupplyP_PowerLevelCheckDis(void)
{
  /* DataStoreWrite: '<S25>/Data Store Write' incorporates:
   *  Constant: '<S25>/Constant'
   */
  Fv_BatVoltLevel = BAT_VOLT_NORMAL;
}

#endif

/* Output and update for atomic system: '<S28>/ResolverPowerCheck' */
#if DIAGDIS_ROTORPOWERREG == 0

void PowerSupplyP_ResolverPowerCheck(void)
{
  /* Chart: '<S31>/ResolverPowerBrownout' */
  /* Gateway: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower/ResolverPowerCheck/ResolverPowerBrownout */
  /* During: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower/ResolverPowerCheck/ResolverPowerBrownout */
  if (((UInt32)
       PowerSupplyProcessrtDW.ResolverPowerCheck.bitsForTID0.is_active_c94_PowerSupplyProces)
      == 0U) {
    /* Entry: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower/ResolverPowerCheck/ResolverPowerBrownout */
    PowerSupplyProcessrtDW.ResolverPowerCheck.bitsForTID0.is_active_c94_PowerSupplyProces
      = 1;

    /* Entry Internal: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_ResolverPower/ResolverPowerCheck/ResolverPowerBrownout */
    /* Transition: '<S33>:1279' */
    PowerSupplyProcessrtDW.ResolverPowerCheck.bitsForTID0.is_c94_PowerSupplyProcess
      = PowerSupplyProce_IN_StateNormal;

    /* Entry 'StateNormal': '<S33>:1284' */
    PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimej = ((UInt16)
      MACRO_POWER_BROWNOUTTIME);
  } else if (((UInt32)
              PowerSupplyProcessrtDW.ResolverPowerCheck.bitsForTID0.is_c94_PowerSupplyProcess)
             == PowerSupplyPro_IN_StateBrownout) {
    /* During 'StateBrownout': '<S33>:1285' */
    if (Fv_SensorPowerResolver >= ((UInt16)MACRO_RESOLVER_POWERMIN)) {
      /* Transition: '<S33>:1280' */
      PowerSupplyProcessrtDW.ResolverPowerCheck.bitsForTID0.is_c94_PowerSupplyProcess
        = PowerSupplyProce_IN_StateNormal;

      /* Entry 'StateNormal': '<S33>:1284' */
      PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimej = ((UInt16)
        MACRO_POWER_BROWNOUTTIME);
    } else {
      /* Transition: '<S33>:1283' */
      if (((Int32)
           PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimei) > 0)
      {
        /* Transition: '<S33>:1299' */
        /* Transition: '<S33>:1298' */
        PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimei =
          (UInt16)((Int32)(((Int32)
                            PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimei)
                           - 1));

        /* Transition: '<S33>:1297' */
      } else {
        /* Transition: '<S33>:1300' */
        SysTaskRsvBrownoutPending = true;
      }
    }
  } else {
    /* During 'StateNormal': '<S33>:1284' */
    if (Fv_SensorPowerResolver < ((UInt16)MACRO_RESOLVER_POWERMIN)) {
      /* Transition: '<S33>:1278' */
      PowerSupplyProcessrtDW.ResolverPowerCheck.bitsForTID0.is_c94_PowerSupplyProcess
        = PowerSupplyPro_IN_StateBrownout;

      /* Entry 'StateBrownout': '<S33>:1285' */
      PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimei = ((UInt16)
        MACRO_POWER_BROWNOUTTIME);
    } else {
      /* Transition: '<S33>:1292' */
      if (((Int32)
           PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimej) > 0)
      {
        /* Transition: '<S33>:1291' */
        /* Transition: '<S33>:1294' */
        PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimej =
          (UInt16)((Int32)(((Int32)
                            PowerSupplyProcessrtDW.ResolverPowerCheck.ResolverBrownoutTimej)
                           - 1));

        /* Transition: '<S33>:1290' */
      } else {
        /* Transition: '<S33>:1293' */
        SysTaskRsvBrownoutPending = false;
      }
    }
  }

  /* End of Chart: '<S31>/ResolverPowerBrownout' */
}

#endif

/* Output and update for atomic system: '<S28>/ResolverPowerCheckDis' */
#if DIAGDIS_ROTORPOWERREG == 1

void PowerSupp_ResolverPowerCheckDis(void)
{
  /* DataStoreWrite: '<S32>/Data Store Write' incorporates:
   *  Constant: '<S32>/Constant'
   */
  SysTaskRsvBrownoutPending = false;
}

#endif

/* Output and update for atomic system: '<S29>/SysPowerCheck' */
#if DIAGDIS_POWERLEVEL == 0

void PowerSupplyProces_SysPowerCheck(void)
{
  /* Chart: '<S34>/SysPowerBrownout' incorporates:
   *  DataStoreRead: '<S34>/Data Store Read'
   */
  /* Gateway: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower/SysPowerCheck/SysPowerBrownout */
  /* During: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower/SysPowerCheck/SysPowerBrownout */
  if (((UInt32)
       PowerSupplyProcessrtDW.SysPowerCheck.bitsForTID0.is_active_c93_PowerSupplyProces)
      == 0U) {
    /* Entry: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower/SysPowerCheck/SysPowerBrownout */
    PowerSupplyProcessrtDW.SysPowerCheck.bitsForTID0.is_active_c93_PowerSupplyProces
      = 1;

    /* Entry Internal: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_SysPower/SysPowerCheck/SysPowerBrownout */
    /* Transition: '<S36>:1299' */
    PowerSupplyProcessrtDW.SysPowerCheck.bitsForTID0.is_c93_PowerSupplyProcess =
      PowerSupply_IN_StateNormal_myn5;

    /* Entry 'StateNormal': '<S36>:1288' */
    PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimej = ((UInt16)
      MACRO_POWER_BROWNOUTTIME);
  } else if (((UInt32)
              PowerSupplyProcessrtDW.SysPowerCheck.bitsForTID0.is_c93_PowerSupplyProcess)
             == PowerSupp_IN_StateBrownout_k2xx) {
    /* During 'StateBrownout': '<S36>:1278' */
    if (Fv_SysPower >= Cal_Power_Low) {
      /* Transition: '<S36>:1298' */
      PowerSupplyProcessrtDW.SysPowerCheck.bitsForTID0.is_c93_PowerSupplyProcess
        = PowerSupply_IN_StateNormal_myn5;

      /* Entry 'StateNormal': '<S36>:1288' */
      PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimej = ((UInt16)
        MACRO_POWER_BROWNOUTTIME);
    } else {
      /* Transition: '<S36>:1283' */
      if (((Int32)PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimei) > 0)
      {
        /* Transition: '<S36>:1284' */
        /* Transition: '<S36>:1286' */
        PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimei = (UInt16)
          ((Int32)(((Int32)
                    PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimei) - 1));

        /* Transition: '<S36>:1287' */
      } else {
        /* Transition: '<S36>:1285' */
        SysTaskPwrBrownoutPending = true;
      }
    }
  } else {
    /* During 'StateNormal': '<S36>:1288' */
    if (Fv_SysPower < Cal_Power_Low) {
      /* Transition: '<S36>:1300' */
      PowerSupplyProcessrtDW.SysPowerCheck.bitsForTID0.is_c93_PowerSupplyProcess
        = PowerSupp_IN_StateBrownout_k2xx;

      /* Entry 'StateBrownout': '<S36>:1278' */
      PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimei = ((UInt16)
        MACRO_POWER_BROWNOUTTIME);
    } else {
      /* Transition: '<S36>:1293' */
      if (((Int32)PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimej) > 0)
      {
        /* Transition: '<S36>:1294' */
        /* Transition: '<S36>:1296' */
        PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimej = (UInt16)
          ((Int32)(((Int32)
                    PowerSupplyProcessrtDW.SysPowerCheck.PowerBrownoutTimej) - 1));
      } else {
        /* Transition: '<S36>:1295' */
        SysTaskPwrBrownoutPending = false;

        /* Transition: '<S36>:1297' */
      }
    }
  }

  /* End of Chart: '<S34>/SysPowerBrownout' */
}

#endif

/* Output and update for atomic system: '<S29>/SysPowerCheckDis' */
#if DIAGDIS_POWERLEVEL == 1

void PowerSupplyPro_SysPowerCheckDis(void)
{
  /* DataStoreWrite: '<S35>/Data Store Write' incorporates:
   *  Constant: '<S35>/Constant'
   */
  SysTaskPwrBrownoutPending = false;
}

#endif

/* Output and update for atomic system: '<S30>/VbatCheck' */
#if DIAGDIS_POWERVBAT == 0

void PowerSupplyProcess_VbatCheck(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S37>/VbatCheck' incorporates:
   *  DataStoreRead: '<S37>/Data Store Read1'
   *  DataStoreRead: '<S39>/Data Store Read'
   *  DataStoreRead: '<S40>/Data Store Read'
   *  DataTypeConversion: '<S39>/Data Type Conversion2'
   *  Product: '<S39>/Product'
   *  Selector: '<S39>/Selector'
   *  Selector: '<S40>/Selector'
   */
  /* Gateway: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck/VbatCheck */
  /* During: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck/VbatCheck */
  if (((UInt32)
       PowerSupplyProcessrtDW.VbatCheck.bitsForTID0.is_active_c65_PowerSupplyProces)
      == 0U) {
    /* Entry: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck/VbatCheck */
    PowerSupplyProcessrtDW.VbatCheck.bitsForTID0.is_active_c65_PowerSupplyProces
      = 1;

    /* Entry Internal: DiagSlow_PowerSupplyCheck/PowerSupplyCheck_Vbat/PowerSupplyCheck_Vbat/VbatCheck/VbatCheck */
    /* Transition: '<S38>:1299' */
    PowerSupplyProcessrtDW.VbatCheck.bitsForTID0.is_c65_PowerSupplyProcess =
      PowerSupplyProce_IN_Normal_os02;

    /* Entry 'Normal': '<S38>:1288' */
    PowerSupplyProcessrtDW.VbatCheck.batj_jdcnt = ((UInt16)MACRO_POWER_BATTIME);
  } else if (((UInt32)
              PowerSupplyProcessrtDW.VbatCheck.bitsForTID0.is_c65_PowerSupplyProcess)
             == PowerSupplyProces_IN_Fault_jc5h) {
    /* During 'Fault': '<S38>:1278' */
    if (!SysTaskVbatAbnormalPending) {
      /* Transition: '<S38>:1298' */
      PowerSupplyProcessrtDW.VbatCheck.bitsForTID0.is_c65_PowerSupplyProcess =
        PowerSupplyProce_IN_Normal_os02;

      /* Entry 'Normal': '<S38>:1288' */
      PowerSupplyProcessrtDW.VbatCheck.batj_jdcnt = ((UInt16)MACRO_POWER_BATTIME);
    } else {
      /* Transition: '<S38>:1284' */
      if (((Int32)PowerSupplyProcessrtDW.VbatCheck.bat_jdcnt) > 0) {
        /* Transition: '<S38>:1283' */
        /* Transition: '<S38>:1286' */
        PowerSupplyProcessrtDW.VbatCheck.bat_jdcnt = (UInt16)((Int32)(((Int32)
          PowerSupplyProcessrtDW.VbatCheck.bat_jdcnt) - 1));

        /* Transition: '<S38>:1287' */
      } else {
        /* Outputs for Function Call SubSystem: '<S38>/DTC_Ctrl_Enabled' */
        /* Transition: '<S38>:1285' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S38>:1304' */
        Fv_ErrDiagStatus[DTC_POWERcheck_VBATdt] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_POWERcheck_VBATdt]
          .Enabled) * ((UInt32)FailureDiag_Err));

        /* End of Outputs for SubSystem: '<S38>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S38>/getDTCEnabled' */
        /* Simulink Function 'getDTCEnabled': '<S38>:1307' */
        Fv_FaultClass_Power = (UInt16)SetU16Fault(Fv_FaultClass_Power, 5,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_POWERcheck_VBATdt]
          .Enabled);

        /* End of Outputs for SubSystem: '<S38>/getDTCEnabled' */
      }
    }
  } else {
    /* During 'Normal': '<S38>:1288' */
    if (SysTaskVbatAbnormalPending) {
      /* Transition: '<S38>:1300' */
      PowerSupplyProcessrtDW.VbatCheck.bitsForTID0.is_c65_PowerSupplyProcess =
        PowerSupplyProces_IN_Fault_jc5h;

      /* Entry 'Fault': '<S38>:1278' */
      PowerSupplyProcessrtDW.VbatCheck.bat_jdcnt = ((UInt16)MACRO_POWER_BATTIME);
    } else {
      /* Transition: '<S38>:1293' */
      if (((Int32)PowerSupplyProcessrtDW.VbatCheck.batj_jdcnt) > 0) {
        /* Transition: '<S38>:1294' */
        /* Transition: '<S38>:1295' */
        PowerSupplyProcessrtDW.VbatCheck.batj_jdcnt = (UInt16)((Int32)(((Int32)
          PowerSupplyProcessrtDW.VbatCheck.batj_jdcnt) - 1));

        /* Transition: '<S38>:1297' */
      } else {
        /* Outputs for Function Call SubSystem: '<S38>/DTC_Ctrl_Enabled' */
        /* Selector: '<S39>/Selector' */
        /* Transition: '<S38>:1296' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S38>:1304' */
        Fv_ErrDiagStatus_tmp = DTC_POWERcheck_VBATdt;
        Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp].
          Enabled) * ((UInt32)FailureDiag_OK));

        /* End of Outputs for SubSystem: '<S38>/DTC_Ctrl_Enabled' */
        Fv_FaultClass_Power = (UInt16)ClrU16Varit(Fv_FaultClass_Power, 5);
      }
    }
  }

  /* End of Chart: '<S37>/VbatCheck' */
}

#endif

/* Output and update for atomic system: '<S2>/PowerSupplyCheck_Vbat' */
void PowerSupp_PowerSupplyCheck_Vbat(void)
{
  /* Outputs for Atomic SubSystem: '<S15>/PowerSupplyCheck_ResolverPower' */
#if DIAGDIS_ROTORPOWERREG == 0

  PowerSupplyP_ResolverPowerCheck();

#elif DIAGDIS_ROTORPOWERREG == 1

  PowerSupp_ResolverPowerCheckDis();

#endif

  /* End of Outputs for SubSystem: '<S15>/PowerSupplyCheck_ResolverPower' */

  /* Outputs for Atomic SubSystem: '<S15>/PowerSupplyCheck_SysPower' */
#if DIAGDIS_POWERLEVEL == 0

  PowerSupplyProces_SysPowerCheck();

#elif DIAGDIS_POWERLEVEL == 1

  PowerSupplyPro_SysPowerCheckDis();

#endif

  /* End of Outputs for SubSystem: '<S15>/PowerSupplyCheck_SysPower' */

  /* Outputs for Atomic SubSystem: '<S15>/PowerSupplyCheck_Vbat' */
#if DIAGDIS_POWERVBAT == 0

  PowerSupplyProcess_VbatCheck();

#endif

  /* End of Outputs for SubSystem: '<S15>/PowerSupplyCheck_Vbat' */
}

/* Output and update for atomic system: '<Root>/DiagSlow_PowerSupplyCheck' */
void Power_DiagSlow_PowerSupplyCheck(void)
{
  /* Outputs for Atomic SubSystem: '<S2>/PowerSupplyCheck_EquSysPower' */
  Po_PowerSupplyCheck_EquSysPower();

  /* End of Outputs for SubSystem: '<S2>/PowerSupplyCheck_EquSysPower' */

  /* Outputs for Atomic SubSystem: '<S2>/PowerSupplyCheck_PowerLevel' */
#if DIAGDIS_POWERLEVEL == 0

  PowerSupplyProc_PowerLevelCheck();

#elif DIAGDIS_POWERLEVEL == 1

  PowerSupplyP_PowerLevelCheckDis();

#endif

  /* End of Outputs for SubSystem: '<S2>/PowerSupplyCheck_PowerLevel' */

  /* Outputs for Atomic SubSystem: '<S2>/PowerSupplyCheck_Vbat' */
  PowerSupp_PowerSupplyCheck_Vbat();

  /* End of Outputs for SubSystem: '<S2>/PowerSupplyCheck_Vbat' */
}

/* Output and update for referenced model: 'PowerSupplyProcess' */
void PowerSupplyProcess(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/DiagSlow_PowerOthersCheck' */
  Power_DiagSlow_PowerOthersCheck();

  /* End of Outputs for SubSystem: '<Root>/DiagSlow_PowerOthersCheck' */

  /* Outputs for Atomic SubSystem: '<Root>/DiagSlow_PowerSupplyCheck' */
  Power_DiagSlow_PowerSupplyCheck();

  /* End of Outputs for SubSystem: '<Root>/DiagSlow_PowerSupplyCheck' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
