/*
 * File: FaultDiagRapid_Torque.c
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

#include "FaultDiagRapid_Torque.h"

/* Include model header file for global data */
#include "FaultDiagRapid.h"
#include "FaultDiagRapid_private.h"

/* Named constants for Chart: '<S67>/TorquePowerDiag' */
#define FaultDi_IN_NO_ACTIVE_CHILD_ipy3 ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_fxxj    ((UInt8)1U)
#define FaultDiagRapid_IN_Fault_dhjm   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_il3j  ((UInt8)2U)
#define FaultDiagRapid_IN_Stop         ((UInt8)2U)
#define FaultDiagRapid_IN_wait         ((UInt8)3U)

/* Named constants for Chart: '<S74>/TorqueSignalDiag' */
#define FaultDi_IN_NO_ACTIVE_CHILD_a3ba ((UInt8)0U)
#define FaultDiagRapid_IN_Diag_l0ld    ((UInt8)1U)
#define FaultDiagRapid_IN_Fault_gotf   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_czaz  ((UInt8)2U)
#define FaultDiagRapid_IN_Wait_fuou    ((UInt8)2U)
#if DIAGDIS_TORQUESIGNALREG == 0

/* Forward declaration for local functions */
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_MainTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_SubTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_SumTorque(const UInt16 *sumtrq_m);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void Faul_exit_internal_OffsetTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDi_enter_atomic_MainTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_OffsetTorque(const UInt16 *sumtrq_m);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDi_exit_internal_SumTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void Fault_enter_internal_MainTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDi_exit_internal_SubTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDia_enter_atomic_SubTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultD_exit_internal_MainTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultD_enter_internal_SubTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDia_enter_atomic_SumTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultD_enter_internal_SumTorque(void);

#endif

#if DIAGDIS_TORQUESIGNALREG == 0

static void Fau_enter_internal_OffsetTorque(void);

#endif
#endif

/* System reset for atomic system: '<S31>/TorqueCheck_Power' */
void FaultDi_TorqueCheck_Power_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S64>/DiagRapid_TorquePower_Check' */
#if DIAGDIS_TORQUEPOWERREG == 0

  /* Reset conditions for atomic system: '<S66>/PowerCheck' */

  /* SystemReset for Chart: '<S67>/TorquePowerDiag' */
  FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_Diag =
    FaultDi_IN_NO_ACTIVE_CHILD_ipy3;
  FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_active_c34_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_c34_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_ipy3;
  FaultDiagRapidrtDW.PowerCheck.SV_TimeWin = 0U;
  FaultDiagRapidrtDW.PowerCheck.SVj_TimeWin = 0U;

#endif

  /* End of SystemReset for SubSystem: '<S64>/DiagRapid_TorquePower_Check' */
}

/* Output and update for atomic system: '<S31>/TorqueCheck_Power' */
void FaultDiagRapi_TorqueCheck_Power(void)
{
  /* Outputs for Atomic SubSystem: '<S64>/DiagRapid_TorquePower_Check' */
#if DIAGDIS_TORQUEPOWERREG == 0

  /* Output and update for atomic system: '<S66>/PowerCheck' */

  /* Outputs for Atomic SubSystem: '<S67>/TorquePowerCond' */
  /* Product: '<S69>/Product' incorporates:
   *  Constant: '<S69>/Constant'
   *  Inport: '<Root>/AD_TorqueSenPower'
   */
  Fv_SensorPowerTorque = (UInt16)((((UInt32)AD_TorqueSenPower) * ((UInt32)
    ((UInt16)MACRO_AV_TRQPOWER_SCALE))) >> 9);

  /* End of Outputs for SubSystem: '<S67>/TorquePowerCond' */

  /* Chart: '<S67>/TorquePowerDiag' incorporates:
   *  DataStoreRead: '<S71>/Data Store Read'
   *  DataStoreRead: '<S72>/Data Store Read'
   *  DataTypeConversion: '<S71>/Data Type Conversion2'
   *  Product: '<S71>/Product'
   *  Selector: '<S71>/Selector'
   *  Selector: '<S72>/Selector'
   */
  /* Gateway: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerDiag */
  /* During: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerDiag */
  if (((UInt32)
       FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_active_c34_FaultDiagRapid) ==
      0U) {
    /* Entry: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerDiag */
    FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_active_c34_FaultDiagRapid = 1;

    /* Entry Internal: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Power/DiagRapid_TorquePower_Check/PowerCheck/TorquePowerDiag */
    /* Transition: '<S70>:1150' */
    FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_c34_FaultDiagRapid =
      FaultDiagRapid_IN_wait;
  } else {
    switch (FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_c34_FaultDiagRapid) {
     case FaultDiagRapid_IN_Diag_fxxj:
      /* During 'Diag': '<S70>:1147' */
      if (Fv_ErrDiagStatus[DTC_TORQUEcheck_PowerSupply] >= FailureDiag_Err) {
        /* Transition: '<S70>:1145' */
        /* Exit Internal 'Diag': '<S70>:1147' */
        FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_Diag =
          FaultDi_IN_NO_ACTIVE_CHILD_ipy3;
        FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_c34_FaultDiagRapid =
          FaultDiagRapid_IN_Stop;
      } else if ((Fv_SysPower <= ((Int16)MACRO_STRTRQ_SUPPLYCHECK)) ||
                 (!SysTaskTrqSplPending)) {
        /* Transition: '<S70>:1138' */
        /* Exit Internal 'Diag': '<S70>:1147' */
        FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_Diag =
          FaultDi_IN_NO_ACTIVE_CHILD_ipy3;
        FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_c34_FaultDiagRapid =
          FaultDiagRapid_IN_wait;
      } else if (((UInt32)FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_Diag) ==
                 FaultDiagRapid_IN_Fault_dhjm) {
        /* During 'Fault': '<S70>:1155' */
        if ((Fv_SensorPowerTorque >= ((UInt16)MACRO_STRTRQ_POWERMIN)) &&
            (Fv_SensorPowerTorque <= ((UInt16)MACRO_STRTRQ_POWERMAX))) {
          /* Transition: '<S70>:1140' */
          FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Normal_il3j;

          /* Entry 'Normal': '<S70>:1148' */
          FaultDiagRapidrtDW.PowerCheck.SVj_TimeWin = ((UInt16)
            MACRO_STRTRQ_CHECKTIME);
        } else {
          /* Transition: '<S70>:1156' */
          if (((Int32)FaultDiagRapidrtDW.PowerCheck.SV_TimeWin) > 0) {
            /* Transition: '<S70>:1149' */
            /* Transition: '<S70>:1167' */
            FaultDiagRapidrtDW.PowerCheck.SV_TimeWin = (UInt16)((Int32)(((Int32)
              FaultDiagRapidrtDW.PowerCheck.SV_TimeWin) - 1));

            /* Transition: '<S70>:1168' */
          } else {
            /* Outputs for Function Call SubSystem: '<S70>/DTC_Ctrl_Enabled' */
            /* Transition: '<S70>:1157' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S70>:1201' */
            Fv_ErrDiagStatus[DTC_TORQUEcheck_PowerSupply] = (FailureDiag)
              (((UInt32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
                [DTC_TORQUEcheck_PowerSupply].Enabled) * ((UInt32)
                FailureDiag_RegErr));

            /* End of Outputs for SubSystem: '<S70>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S70>/getDTCEnabled' */
            /* Simulink Function 'getDTCEnabled': '<S70>:1197' */
            Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 0,
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_TORQUEcheck_PowerSupply].Enabled);

            /* End of Outputs for SubSystem: '<S70>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S70>:1148' */
        if ((Fv_SensorPowerTorque < ((UInt16)MACRO_STRTRQ_POWERMIN)) ||
            (Fv_SensorPowerTorque > ((UInt16)MACRO_STRTRQ_POWERMAX))) {
          /* Transition: '<S70>:1141' */
          FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Fault_dhjm;

          /* Entry 'Fault': '<S70>:1155' */
          FaultDiagRapidrtDW.PowerCheck.SV_TimeWin = ((UInt16)
            MACRO_STRTRQ_CHECKTIME);
        } else {
          /* Transition: '<S70>:1144' */
          if (((Int32)FaultDiagRapidrtDW.PowerCheck.SVj_TimeWin) > 0) {
            /* Transition: '<S70>:1142' */
            /* Transition: '<S70>:1162' */
            FaultDiagRapidrtDW.PowerCheck.SVj_TimeWin = (UInt16)((Int32)(((Int32)
              FaultDiagRapidrtDW.PowerCheck.SVj_TimeWin) - 1));

            /* Transition: '<S70>:1164' */
          } else {
            /* Outputs for Function Call SubSystem: '<S70>/DTC_Ctrl_Enabled' */
            /* Transition: '<S70>:1137' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S70>:1201' */
            Fv_ErrDiagStatus[DTC_TORQUEcheck_PowerSupply] = (FailureDiag)
              (((UInt32)(((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
                [DTC_TORQUEcheck_PowerSupply].Enabled) * ((UInt32)
                FailureDiag_RegOK));

            /* End of Outputs for SubSystem: '<S70>/DTC_Ctrl_Enabled' */
            Fv_FaultClass_Torque = (UInt16)ClrU16Varit(Fv_FaultClass_Torque, 0);
          }
        }
      }
      break;

     case FaultDiagRapid_IN_Stop:
      /* During 'Stop': '<S70>:1154' */
      break;

     default:
      /* During 'wait': '<S70>:1151' */
      if (Fv_ErrDiagStatus[DTC_TORQUEcheck_PowerSupply] >= FailureDiag_Err) {
        /* Transition: '<S70>:1139' */
        FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_c34_FaultDiagRapid =
          FaultDiagRapid_IN_Stop;
      } else {
        if ((Fv_SysPower > ((Int16)MACRO_STRTRQ_SUPPLYCHECK)) &&
            (SysTaskTrqSplPending)) {
          /* Transition: '<S70>:1143' */
          FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_c34_FaultDiagRapid =
            FaultDiagRapid_IN_Diag_fxxj;

          /* Entry Internal 'Diag': '<S70>:1147' */
          /* Transition: '<S70>:1146' */
          FaultDiagRapidrtDW.PowerCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Normal_il3j;

          /* Entry 'Normal': '<S70>:1148' */
          FaultDiagRapidrtDW.PowerCheck.SVj_TimeWin = ((UInt16)
            MACRO_STRTRQ_CHECKTIME);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S67>/TorquePowerDiag' */
#elif DIAGDIS_TORQUEPOWERREG == 1

  /* Output and update for atomic system: '<S66>/PowerCheckDis' */

  /* Product: '<S68>/Product' incorporates:
   *  Constant: '<S68>/Constant'
   *  DataStoreWrite: '<S68>/Data Store Write'
   *  Inport: '<Root>/AD_TorqueSenPower'
   */
  Fv_SensorPowerTorque = (UInt16)((((UInt32)AD_TorqueSenPower) * ((UInt32)
    ((UInt16)MACRO_AV_TRQPOWER_SCALE))) >> 9);

#endif

  /* End of Outputs for SubSystem: '<S64>/DiagRapid_TorquePower_Check' */
}

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_MainTorque(void)
{
  Int32 Fv_ErrDiagStatus_tmp_m;
  Int32 tmp_m;

  /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
  /* Selector: '<S81>/Selector' */
  /* During 'MainTorque': '<S77>:1182' */
  /* Transition: '<S77>:1337' */
  tmp_m = DTC_TORQUEcheck_MainRange;
#if 0
  /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */
  if ((((Int32)FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin) == 0) &&
      (Fv_ErrDiagStatus[(tmp_m)] < FailureDiag_Err)) {
    /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
    /* Selector: '<S81>/Selector' */
    /* Transition: '<S77>:1339' */
    /* Transition: '<S77>:1341' */
    /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
    Fv_ErrDiagStatus_tmp_m = DTC_TORQUEcheck_MainWave;

    /* DataTypeConversion: '<S81>/Data Type Conversion2' incorporates:
     *  DataStoreRead: '<S81>/Data Store Read'
     *  Product: '<S81>/Product'
     *  Selector: '<S81>/Selector'
     */
    Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
      (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m].
      Enabled) * ((UInt32)FailureDiag_RegErr));

    /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

    /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
    /* Selector: '<S82>/Selector' incorporates:
     *  DataStoreRead: '<S82>/Data Store Read'
     */
    /* Simulink Function 'getDTCEnabled': '<S77>:1449' */
    Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 2,
      (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_MainWave].
      Enabled);

    /* End of Outputs for SubSystem: '<S77>/getDTCEnabled' */
    /* Transition: '<S77>:1344' */
  } else {
    /* Transition: '<S77>:1343' */
  }
#endif
  if (((UInt32)FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_MainTorque) ==
      FaultDiagRapid_IN_Fault_gotf) {
    /* DataStoreRead: '<S76>/Data Store Read3' incorporates:
     *  DataStoreRead: '<S81>/Data Store Read'
     *  DataStoreRead: '<S82>/Data Store Read'
     *  DataTypeConversion: '<S81>/Data Type Conversion2'
     *  Inport: '<Root>/IOC_Tor1Frez'
     *  Product: '<S81>/Product'
     *  Selector: '<S81>/Selector'
     *  Selector: '<S82>/Selector'
     */
    /* During 'Fault': '<S77>:1186' */
   if (((((Fv_MainTorqueADVol >= ((UInt16)MACRO_STRTRQ_MIN)) &&         
           (Fv_MainTorqueADVol <= ((UInt16)MACRO_STRTRQ_MAX))) && (IOC_Tor1Frez >=
           ((UInt16)MACRO_STRTRQ_FRZMIN))) && (IOC_Tor1Frez <= ((UInt16)
           MACRO_STRTRQ_FRZMAX))) && (Fv_ErrDiagStatus[(tmp_m)] <
         FailureDiag_Err)) {
      /* Transition: '<S77>:1185' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_MainTorque =
        FaultDiagRapid_IN_Normal_czaz;

      /* Entry 'Normal': '<S77>:1192' */
      FaultDiagRapidrtDW.SignalCheck.SMj_TimeWin = ((UInt16)
        MACRO_STRTRQ_RECOVERTIME);
      FaultDiagRapidrtDW.SignalCheck.SMR_TimeWin = ((UInt16)
        MACRO_STRTRQ_RSTCONTTIME);
    } else {
      /* Transition: '<S77>:1190' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SM_TimeWin) > 0) {
        /* Transition: '<S77>:1189' */
        /* Transition: '<S77>:1247' */
        FaultDiagRapidrtDW.SignalCheck.SM_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SM_TimeWin) - 1));

        /* Transition: '<S77>:1249' */
      } else {
        /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
        /* Transition: '<S77>:1191' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
        Fv_ErrDiagStatus[(tmp_m)] = (FailureDiag)(((UInt32)(((tagDTC_Ctrl_Info *)
          &(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_MainRange].Enabled) *
          ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
        /* Simulink Function 'getDTCEnabled': '<S77>:1449' */
        Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 1,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_TORQUEcheck_MainRange].Enabled);

        /* End of Outputs for SubSystem: '<S77>/getDTCEnabled' */
        FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin = ((UInt16)
          MACRO_STRTRQ_CONTTIME);

        Fv_ErrDiagStatus[(DTC_TORQUEcheck_MainWave)] = (FailureDiag)(((UInt32)   
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_MainWave].
        Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
        /* Selector: '<S82>/Selector' incorporates:
        *  DataStoreRead: '<S82>/Data Store Read'
        */
        /* Simulink Function 'getDTCEnabled': '<S77>:1449' */    
        Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 2,
        (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_MainWave].
        Enabled);

      }

      /* Transition: '<S77>:1328' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin) > 0) {
        /* Transition: '<S77>:1330' */
        /* Transition: '<S77>:1332' */
        FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin) - 1));

        /* Transition: '<S77>:1335' */
      } else {  
      }
    }
  } else {
    /* DataStoreRead: '<S76>/Data Store Read3' incorporates:
     *  DataStoreRead: '<S81>/Data Store Read'
     *  DataTypeConversion: '<S81>/Data Type Conversion2'
     *  Inport: '<Root>/IOC_Tor1Frez'
     *  Product: '<S81>/Product'
     *  Selector: '<S81>/Selector'
     */
    /* During 'Normal': '<S77>:1192' */
    if ((((Fv_MainTorqueADVol < ((UInt16)MACRO_STRTRQ_MIN)) ||
          (Fv_MainTorqueADVol > ((UInt16)MACRO_STRTRQ_MAX))) || (IOC_Tor1Frez <
          ((UInt16)MACRO_STRTRQ_FRZMIN))) || (IOC_Tor1Frez > ((UInt16)
          MACRO_STRTRQ_FRZMAX))) {
      /* Transition: '<S77>:1184' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_MainTorque =
        FaultDiagRapid_IN_Fault_gotf;

      /* Entry 'Fault': '<S77>:1186' */
      FaultDiagRapidrtDW.SignalCheck.SM_TimeWin = ((UInt16)
        MACRO_STRTRQ_CHECKTIME);
    } else {
      /* Transition: '<S77>:1196' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SMj_TimeWin) > 0) {
        /* Transition: '<S77>:1195' */
        /* Transition: '<S77>:1242' */
        FaultDiagRapidrtDW.SignalCheck.SMj_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SMj_TimeWin) - 1));

        /* Transition: '<S77>:1244' */
      } else {
        /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
        /* Transition: '<S77>:1197' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
        Fv_ErrDiagStatus[(tmp_m)] = (FailureDiag)(((UInt32)(((tagDTC_Ctrl_Info *)
          &(DTC_Ctrl_Info_Tab[0])))[tmp_m].Enabled) * ((UInt32)FailureDiag_RegOK));

        /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */
        Fv_FaultClass_Torque = (UInt16)ClrU16Varit(Fv_FaultClass_Torque, 1);
      }

      /* Transition: '<S77>:1309' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SMR_TimeWin) > 0) {
        /* Transition: '<S77>:1311' */
        /* Transition: '<S77>:1313' */
        FaultDiagRapidrtDW.SignalCheck.SMR_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SMR_TimeWin) - 1));

        /* Transition: '<S77>:1316' */
      } else {
        /* Transition: '<S77>:1315' */
        FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin = ((UInt16)
          MACRO_STRTRQ_CONTTIME);
      }
    }
  }
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_SubTorque(void)
{
  Int32 Fv_ErrDiagStatus_tmp_m;
  Int32 tmp_m;

  /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
  /* Selector: '<S81>/Selector' */
  /* During 'SubTorque': '<S77>:1198' */
  /* Transition: '<S77>:1371' */
  tmp_m = DTC_TORQUEcheck_SubRange;
#if 0
  /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */
  if ((((Int32)FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin) == 0) &&
      (Fv_ErrDiagStatus[(tmp_m)] < FailureDiag_Err)) {
    /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
    /* Selector: '<S81>/Selector' */
    /* Transition: '<S77>:1372' */
    /* Transition: '<S77>:1367' */
    /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
    Fv_ErrDiagStatus_tmp_m = DTC_TORQUEcheck_SubWave;

    /* DataTypeConversion: '<S81>/Data Type Conversion2' incorporates:
     *  DataStoreRead: '<S81>/Data Store Read'
     *  Product: '<S81>/Product'
     *  Selector: '<S81>/Selector'
     */
    Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp_m)] = (FailureDiag)(((UInt32)
      (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp_m].
      Enabled) * ((UInt32)FailureDiag_RegErr));

    /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

    /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
    /* Selector: '<S82>/Selector' incorporates:
     *  DataStoreRead: '<S82>/Data Store Read'
     */
    /* Simulink Function 'getDTCEnabled': '<S77>:1449' */
    Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 4,
      (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_SubWave].
      Enabled);

    /* End of Outputs for SubSystem: '<S77>/getDTCEnabled' */
    /* Transition: '<S77>:1370' */
  } else {
    /* Transition: '<S77>:1369' */
  }
#endif
  if (((UInt32)FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SubTorque) ==
      FaultDiagRapid_IN_Fault_gotf) {
    /* DataStoreRead: '<S76>/Data Store Read4' incorporates:
     *  DataStoreRead: '<S81>/Data Store Read'
     *  DataStoreRead: '<S82>/Data Store Read'
     *  DataTypeConversion: '<S81>/Data Type Conversion2'
     *  Inport: '<Root>/IOC_Tor2Frez'
     *  Product: '<S81>/Product'
     *  Selector: '<S81>/Selector'
     *  Selector: '<S82>/Selector'
     */
    /* During 'Fault': '<S77>:1202' */

    if (((((Fv_SubTorqueADVol >= ((UInt16)MACRO_STRTRQ_MIN)) &&
           (Fv_SubTorqueADVol <= ((UInt16)MACRO_STRTRQ_MAX))) && (IOC_Tor2Frez >=
           ((UInt16)MACRO_STRTRQ_FRZMIN))) && (IOC_Tor2Frez <= ((UInt16)
           MACRO_STRTRQ_FRZMAX))) && (Fv_ErrDiagStatus[(tmp_m)] <
         FailureDiag_Err)) {
      /* Transition: '<S77>:1201' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SubTorque =
        FaultDiagRapid_IN_Normal_czaz;

      /* Entry 'Normal': '<S77>:1208' */
      FaultDiagRapidrtDW.SignalCheck.SSj_TimeWin = ((UInt16)
        MACRO_STRTRQ_RECOVERTIME);
      FaultDiagRapidrtDW.SignalCheck.SSR_TimeWin = ((UInt16)
        MACRO_STRTRQ_RSTCONTTIME);
    } else {
      /* Transition: '<S77>:1206' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SS_TimeWin) > 0) {
        /* Transition: '<S77>:1205' */
        /* Transition: '<S77>:1255' */
        FaultDiagRapidrtDW.SignalCheck.SS_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SS_TimeWin) - 1));

        /* Transition: '<S77>:1257' */
      } else {
        /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
        /* Transition: '<S77>:1207' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
        Fv_ErrDiagStatus[(tmp_m)] = (FailureDiag)(((UInt32)(((tagDTC_Ctrl_Info *)
          &(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_SubRange].Enabled) *
          ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
        /* Simulink Function 'getDTCEnabled': '<S77>:1449' */
        Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 3,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
          [DTC_TORQUEcheck_SubRange].Enabled);

        /* End of Outputs for SubSystem: '<S77>/getDTCEnabled' */
        FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin = ((UInt16)
          MACRO_STRTRQ_CONTTIME);


        Fv_ErrDiagStatus[(DTC_TORQUEcheck_SubWave)] = (FailureDiag)(((UInt32)
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_SubWave].
          Enabled) * ((UInt32)FailureDiag_RegErr));

        /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

        /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
        /* Selector: '<S82>/Selector' incorporates:
        *  DataStoreRead: '<S82>/Data Store Read'
        */
        /* Simulink Function 'getDTCEnabled': '<S77>:1449' */   
        Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 4,
          (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[DTC_TORQUEcheck_SubWave].
          Enabled);


      }

      /* Transition: '<S77>:1363' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin) > 0) {
        /* Transition: '<S77>:1356' */
        /* Transition: '<S77>:1362' */
        FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin) - 1));

        /* Transition: '<S77>:1358' */
      } else {

      }
    }
  } else {
    /* DataStoreRead: '<S76>/Data Store Read4' incorporates:
     *  DataStoreRead: '<S81>/Data Store Read'
     *  DataTypeConversion: '<S81>/Data Type Conversion2'
     *  Inport: '<Root>/IOC_Tor2Frez'
     *  Product: '<S81>/Product'
     *  Selector: '<S81>/Selector'
     */
    /* During 'Normal': '<S77>:1208' */
    if ((((Fv_SubTorqueADVol < ((UInt16)MACRO_STRTRQ_MIN)) || (Fv_SubTorqueADVol
           > ((UInt16)MACRO_STRTRQ_MAX))) || (IOC_Tor2Frez < ((UInt16)
           MACRO_STRTRQ_FRZMIN))) || (IOC_Tor2Frez > ((UInt16)
          MACRO_STRTRQ_FRZMAX))) {
      /* Transition: '<S77>:1200' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SubTorque =
        FaultDiagRapid_IN_Fault_gotf;

      /* Entry 'Fault': '<S77>:1202' */
      FaultDiagRapidrtDW.SignalCheck.SS_TimeWin = ((UInt16)
        MACRO_STRTRQ_CHECKTIME);
    } else {
      /* Transition: '<S77>:1212' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SSj_TimeWin) > 0) {
        /* Transition: '<S77>:1211' */
        /* Transition: '<S77>:1251' */
        FaultDiagRapidrtDW.SignalCheck.SSj_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SSj_TimeWin) - 1));

        /* Transition: '<S77>:1253' */
      } else {
        /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
        /* Transition: '<S77>:1213' */
        /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
        Fv_ErrDiagStatus[(tmp_m)] = (FailureDiag)(((UInt32)(((tagDTC_Ctrl_Info *)
          &(DTC_Ctrl_Info_Tab[0])))[tmp_m].Enabled) * ((UInt32)FailureDiag_RegOK));

        /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */
        Fv_FaultClass_Torque = (UInt16)ClrU16Varit(Fv_FaultClass_Torque, 3);
      }

      /* Transition: '<S77>:1350' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SSR_TimeWin) > 0) {
        /* Transition: '<S77>:1353' */
        /* Transition: '<S77>:1349' */
        FaultDiagRapidrtDW.SignalCheck.SSR_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SSR_TimeWin) - 1));

        /* Transition: '<S77>:1347' */
      } else {
        /* Transition: '<S77>:1355' */
        FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin = ((UInt16)
          MACRO_STRTRQ_CONTTIME);
      }
    }
  }
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_SumTorque(const UInt16 *sumtrq_m)
{
  Int32 tmp_m;

  /* During 'SumTorque': '<S77>:1215' */
  if (((UInt32)FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SumTorque) ==
      FaultDiagRapid_IN_Fault_gotf) {
    /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
    /* Selector: '<S81>/Selector' */
    /* During 'Fault': '<S77>:1274' */
    tmp_m = DTC_TORQUEcheck_SumOfMS;

    /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */
    if ((((*sumtrq_m) <= ((UInt16)MACRO_STRTRQ_SUMMAX)) && ((*sumtrq_m) >=
          ((UInt16)MACRO_STRTRQ_SUMMIN))) && (Fv_ErrDiagStatus[(tmp_m)] <
         FailureDiag_Err)) {
      /* Transition: '<S77>:1218' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SumTorque =
        FaultDiagRapid_IN_Normal_czaz;

      /* Entry 'Normal': '<S77>:1225' */
      FaultDiagRapidrtDW.SignalCheck.SUMj_TimeWin = ((UInt16)
        MACRO_STRTRQ_RECOVERTIME);
    } else {
      /* Transition: '<S77>:1281' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SUM_TimeWin) > 0) {
        /* Transition: '<S77>:1282' */
        /* Transition: '<S77>:1284' */
        FaultDiagRapidrtDW.SignalCheck.SUM_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SUM_TimeWin) - 1));

        /* Transition: '<S77>:1290' */
        /* Transition: '<S77>:1293' */
      } else {
        /* Transition: '<S77>:1283' */
        if ((Fv_ErrDiagStatus[DTC_TORQUEcheck_MainRange] <= FailureDiag_RegOK) &&
            (Fv_ErrDiagStatus[DTC_TORQUEcheck_SubRange] <= FailureDiag_RegOK)) {
          /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
          /* DataTypeConversion: '<S81>/Data Type Conversion2' incorporates:
           *  DataStoreRead: '<S81>/Data Store Read'
           *  Product: '<S81>/Product'
           *  Selector: '<S81>/Selector'
           */
          /* Transition: '<S77>:1287' */
          /* Transition: '<S77>:1289' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
          Fv_ErrDiagStatus[(tmp_m)] = (FailureDiag)(((UInt32)(((tagDTC_Ctrl_Info
            *)&(DTC_Ctrl_Info_Tab[0])))[tmp_m].Enabled) * ((UInt32)
            FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
          /* Selector: '<S82>/Selector' incorporates:
           *  DataStoreRead: '<S82>/Data Store Read'
           */
          /* Simulink Function 'getDTCEnabled': '<S77>:1449' */
          Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 5,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_TORQUEcheck_SumOfMS].Enabled);

          /* End of Outputs for SubSystem: '<S77>/getDTCEnabled' */
          /* Transition: '<S77>:1293' */
        } else {
          /* Transition: '<S77>:1292' */
        }
      }
    }
  } else {
    /* During 'Normal': '<S77>:1225' */
    if (((*sumtrq_m) > ((UInt16)MACRO_STRTRQ_SUMMAX)) || ((*sumtrq_m) < ((UInt16)
          MACRO_STRTRQ_SUMMIN))) {
      /* Transition: '<S77>:1217' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SumTorque =
        FaultDiagRapid_IN_Fault_gotf;

      /* Entry 'Fault': '<S77>:1274' */
      FaultDiagRapidrtDW.SignalCheck.SUM_TimeWin = ((UInt16)
        MACRO_STRTRQ_CHECKTIME);
    } else {
      /* Transition: '<S77>:1378' */
      if (((Int32)FaultDiagRapidrtDW.SignalCheck.SUMj_TimeWin) > 0) {
        /* Transition: '<S77>:1376' */
        /* Transition: '<S77>:1382' */
        FaultDiagRapidrtDW.SignalCheck.SUMj_TimeWin = (UInt16)((Int32)(((Int32)
          FaultDiagRapidrtDW.SignalCheck.SUMj_TimeWin) - 1));

        /* Transition: '<S77>:1384' */
      } else {
        /* Transition: '<S77>:1380' */
        Fv_ErrDiagStatus[DTC_TORQUEcheck_SumOfMS] = FailureDiag_RegOK;
        Fv_FaultClass_Torque = (UInt16)ClrU16Varit(Fv_FaultClass_Torque, 5);
        if (!Fv_SystemTransferState) {
          /* Transition: '<S77>:1464' */
          /* Transition: '<S77>:1466' */
          Fv_StudyTorqueSum = (UInt16)((Int32)((((((((((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[0]) + ((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[1])) + ((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[2])) + ((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[3])) + ((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[4])) + ((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[5])) + ((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[6])) + ((Int32)
            FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[7])) / 8));
          Fv_StudyTorqueValid = true;

          /* Transition: '<S77>:1469' */
        } else {
          /* Transition: '<S77>:1468' */
        }

        /* Transition: '<S77>:1470' */
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[7] =
          FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[6];
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[6] =
          FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[5];
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[5] =
          FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[4];
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[4] =
          FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[3];
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[3] =
          FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[2];
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[2] =
          FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[1];
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[1] =
          FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[0];
        FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[0] = *sumtrq_m;
      }
    }
  }
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void Faul_exit_internal_OffsetTorque(void)
{
  /* Exit Internal 'OffsetTorque': '<S77>:1390' */
  /* Exit Internal 'Diag': '<S77>:1408' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_Diag =
    FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_OffsetTorque =
    FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDi_enter_atomic_MainTorque(void)
{
  /* Entry 'MainTorque': '<S77>:1182' */
  FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin = ((UInt16)MACRO_STRTRQ_CONTTIME);
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDiagRapid_OffsetTorque(const UInt16 *sumtrq_m)
{
  Int32 u_m;
  Int32 tmp_m;

  /* During 'OffsetTorque': '<S77>:1390' */
  if (((UInt32)FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_OffsetTorque) ==
      FaultDiagRapid_IN_Diag_l0ld) {
    /* During 'Diag': '<S77>:1408' */
    if ((((((*sumtrq_m) > ((UInt16)MACRO_STRTRQ_SUMMAX)) || ((*sumtrq_m) <
            ((UInt16)MACRO_STRTRQ_SUMMIN))) ||
          (!(Fv_ErrDiagStatus[DTC_TORQUEcheck_SumOfMS] <= FailureDiag_RegOK))) ||
         (!Fv_StudyTorqueValid)) || (!Fv_SystemTransferState)) {
      /* Transition: '<S77>:1405' */
      /* Exit Internal 'Diag': '<S77>:1408' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_Diag =
        FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_OffsetTorque =
        FaultDiagRapid_IN_Wait_fuou;
    } else {
      u_m = ((Int32)Fv_StudyTorqueSum) - ((Int32)(*sumtrq_m));
      if (u_m < 0) {
        u_m = -u_m;
      }

      if (((UInt32)FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_Diag) ==
          FaultDiagRapid_IN_Fault_gotf) {
        /* During 'Fault': '<S77>:1407' */
        tmp_m = DTC_TORQUEcheck_Offset;
        if ((((Int32)((UInt16)u_m)) <= ((Int32)((Int16)MACRO_STRTRQ_OFFSET))) &&
            (Fv_ErrDiagStatus[(tmp_m)] < FailureDiag_Err)) {
          /* Transition: '<S77>:1393' */
          FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Normal_czaz;

          /* Entry 'Normal': '<S77>:1403' */
          FaultDiagRapidrtDW.SignalCheck.SOFj_TimeWin = ((UInt16)
            MACRO_STRTRQ_RECOVERTIME);
        } else {
          /* Transition: '<S77>:1397' */
          if (((Int32)FaultDiagRapidrtDW.SignalCheck.SOF_TimeWin) > 0) {
            /* Transition: '<S77>:1391' */
            /* Transition: '<S77>:1418' */
            FaultDiagRapidrtDW.SignalCheck.SOF_TimeWin = (UInt16)((Int32)
              (((Int32)FaultDiagRapidrtDW.SignalCheck.SOF_TimeWin) - 1));

            /* Transition: '<S77>:1420' */
          } else {
            /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
            /* DataTypeConversion: '<S81>/Data Type Conversion2' incorporates:
             *  DataStoreRead: '<S81>/Data Store Read'
             *  Product: '<S81>/Product'
             *  Selector: '<S81>/Selector'
             */
            /* Transition: '<S77>:1409' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
            // Fv_ErrDiagStatus[(tmp_m)] = (FailureDiag)(((UInt32)
            //   (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            //   [DTC_TORQUEcheck_Offset].Enabled) * ((UInt32)FailureDiag_RegErr));

            /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */

            /* Outputs for Function Call SubSystem: '<S77>/getDTCEnabled' */
            /* Selector: '<S82>/Selector' incorporates:
             *  DataStoreRead: '<S82>/Data Store Read'
             */
            /* Simulink Function 'getDTCEnabled': '<S77>:1449' */
            // Fv_FaultClass_Torque = (UInt16)SetU16Fault(Fv_FaultClass_Torque, 6,
            //   (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            //   [DTC_TORQUEcheck_Offset].Enabled);

            /* End of Outputs for SubSystem: '<S77>/getDTCEnabled' */
          }
        }
      } else {
        /* During 'Normal': '<S77>:1403' */
        if (((Int32)((UInt16)u_m)) > ((Int32)((Int16)MACRO_STRTRQ_OFFSET))) {
          /* Transition: '<S77>:1392' */
          FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_Diag =
            FaultDiagRapid_IN_Fault_gotf;

          /* Entry 'Fault': '<S77>:1407' */
          FaultDiagRapidrtDW.SignalCheck.SOF_TimeWin = ((UInt16)
            MACRO_STRTRQ_CHECKTIME);
        } else {
          /* Transition: '<S77>:1401' */
          if (((Int32)FaultDiagRapidrtDW.SignalCheck.SOFj_TimeWin) > 0) {
            /* Transition: '<S77>:1400' */
            /* Transition: '<S77>:1414' */
            FaultDiagRapidrtDW.SignalCheck.SOFj_TimeWin = (UInt16)((Int32)
              (((Int32)FaultDiagRapidrtDW.SignalCheck.SOFj_TimeWin) - 1));

            /* Transition: '<S77>:1416' */
          } else {
            /* Outputs for Function Call SubSystem: '<S77>/DTC_Ctrl_Enabled' */
            /* DataTypeConversion: '<S81>/Data Type Conversion2' incorporates:
             *  DataStoreRead: '<S81>/Data Store Read'
             *  Product: '<S81>/Product'
             *  Selector: '<S81>/Selector'
             */
            /* Transition: '<S77>:1404' */
            /* Simulink Function 'DTC_Ctrl_Enabled': '<S77>:1446' */
            Fv_ErrDiagStatus[DTC_TORQUEcheck_Offset] = (FailureDiag)(((UInt32)
              (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
              [DTC_TORQUEcheck_Offset].Enabled) * ((UInt32)FailureDiag_RegOK));

            /* End of Outputs for SubSystem: '<S77>/DTC_Ctrl_Enabled' */
            Fv_FaultClass_Torque = (UInt16)ClrU16Varit(Fv_FaultClass_Torque, 6);
          }
        }
      }
    }
  } else {
    /* During 'Wait': '<S77>:1406' */
    if ((((((*sumtrq_m) <= ((UInt16)MACRO_STRTRQ_SUMMAX)) && ((*sumtrq_m) >=
            ((UInt16)MACRO_STRTRQ_SUMMIN))) &&
          (Fv_ErrDiagStatus[DTC_TORQUEcheck_SumOfMS] <= FailureDiag_RegOK)) &&
         (Fv_StudyTorqueValid)) && (Fv_SystemTransferState)) {
      /* Transition: '<S77>:1394' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_OffsetTorque =
        FaultDiagRapid_IN_Diag_l0ld;

      /* Entry 'Diag': '<S77>:1408' */
      /* Entry Internal 'Diag': '<S77>:1408' */
      /* Transition: '<S77>:1410' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_Diag =
        FaultDiagRapid_IN_Normal_czaz;

      /* Entry 'Normal': '<S77>:1403' */
      FaultDiagRapidrtDW.SignalCheck.SOFj_TimeWin = ((UInt16)
        MACRO_STRTRQ_RECOVERTIME);
    }
  }
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDi_exit_internal_SumTorque(void)
{
  /* Exit Internal 'SumTorque': '<S77>:1215' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SumTorque =
    FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void Fault_enter_internal_MainTorque(void)
{
  /* Entry Internal 'MainTorque': '<S77>:1182' */
  /* Transition: '<S77>:1183' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_MainTorque =
    FaultDiagRapid_IN_Normal_czaz;

  /* Entry 'Normal': '<S77>:1192' */
  FaultDiagRapidrtDW.SignalCheck.SMj_TimeWin = ((UInt16)MACRO_STRTRQ_RECOVERTIME);
  FaultDiagRapidrtDW.SignalCheck.SMR_TimeWin = ((UInt16)MACRO_STRTRQ_RSTCONTTIME);
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDi_exit_internal_SubTorque(void)
{
  /* Exit Internal 'SubTorque': '<S77>:1198' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SubTorque =
    FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDia_enter_atomic_SubTorque(void)
{
  /* Entry 'SubTorque': '<S77>:1198' */
  FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin = ((UInt16)MACRO_STRTRQ_CONTTIME);
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultD_exit_internal_MainTorque(void)
{
  /* Exit Internal 'MainTorque': '<S77>:1182' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_MainTorque =
    FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultD_enter_internal_SubTorque(void)
{
  /* Entry Internal 'SubTorque': '<S77>:1198' */
  /* Transition: '<S77>:1199' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SubTorque =
    FaultDiagRapid_IN_Normal_czaz;

  /* Entry 'Normal': '<S77>:1208' */
  FaultDiagRapidrtDW.SignalCheck.SSj_TimeWin = ((UInt16)MACRO_STRTRQ_RECOVERTIME);
  FaultDiagRapidrtDW.SignalCheck.SSR_TimeWin = ((UInt16)MACRO_STRTRQ_RSTCONTTIME);
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultDia_enter_atomic_SumTorque(void)
{
  Int32 i_m;

  /* Entry 'SumTorque': '<S77>:1215' */
  for (i_m = 0; i_m < 8; i_m++) {
    FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[i_m] = 0U;
  }
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void FaultD_enter_internal_SumTorque(void)
{
  /* Entry Internal 'SumTorque': '<S77>:1215' */
  /* Transition: '<S77>:1216' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SumTorque =
    FaultDiagRapid_IN_Normal_czaz;

  /* Entry 'Normal': '<S77>:1225' */
  FaultDiagRapidrtDW.SignalCheck.SUMj_TimeWin = ((UInt16)
    MACRO_STRTRQ_RECOVERTIME);
}

#endif
#endif

/* Function for Chart: '<S74>/TorqueSignalDiag' */
#if DIAGDIS_TORQUESIGNALREG == 0
#if DIAGDIS_TORQUESIGNALREG == 0

static void Fau_enter_internal_OffsetTorque(void)
{
  /* Entry Internal 'OffsetTorque': '<S77>:1390' */
  /* Transition: '<S77>:1411' */
  FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_OffsetTorque =
    FaultDiagRapid_IN_Wait_fuou;
}

#endif
#endif

/* System reset for atomic system: '<S31>/TorqueCheck_Signal' */
void FaultD_TorqueCheck_Signal_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S65>/DiagRapid_TorqueSignal_Check' */
#if DIAGDIS_TORQUESIGNALREG == 0

  /* Reset conditions for atomic system: '<S73>/SignalCheck' */
  {
    Int32 i_m;

    /* SystemReset for Chart: '<S74>/TorqueSignalDiag' */
    FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_MainTorque =
      FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
    FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_OffsetTorque =
      FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
    FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_Diag =
      FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
    FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SubTorque =
      FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
    FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_SumTorque =
      FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
    FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_active_c37_FaultDiagRapid = 0;
    FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_c37_FaultDiagRapid =
      FaultDi_IN_NO_ACTIVE_CHILD_a3ba;
    FaultDiagRapidrtDW.SignalCheck.SM_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SS_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SUM_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SMC_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SMR_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SSR_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SSC_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SOF_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SMj_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SSj_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SUMj_TimeWin = 0U;
    FaultDiagRapidrtDW.SignalCheck.SOFj_TimeWin = 0U;
    for (i_m = 0; i_m < 8; i_m++) {
      FaultDiagRapidrtDW.SignalCheck.SUM_RECORD[i_m] = 0U;
    }

    /* End of SystemReset for Chart: '<S74>/TorqueSignalDiag' */
  }

#endif

  /* End of SystemReset for SubSystem: '<S65>/DiagRapid_TorqueSignal_Check' */
}

/* Output and update for atomic system: '<S31>/TorqueCheck_Signal' */
void FaultDiagRap_TorqueCheck_Signal(void)
{
  /* Outputs for Atomic SubSystem: '<S65>/DiagRapid_TorqueSignal_Check' */
#if DIAGDIS_TORQUESIGNALREG == 0

  /* Output and update for atomic system: '<S73>/SignalCheck' */
  {
    Bool precondtrq_m;
    UInt16 sumtrq_m;

    /* Outputs for Atomic SubSystem: '<S74>/TorqueSignalCond' */
    /* Logic: '<S76>/Logical Operator' incorporates:
     *  Constant: '<S78>/Constant'
     *  Constant: '<S79>/Constant'
     *  Constant: '<S80>/Constant'
     *  DataStoreRead: '<S76>/Data Store Read'
     *  DataStoreRead: '<S76>/Data Store Read1'
     *  DataStoreRead: '<S76>/Data Store Read2'
     *  RelationalOperator: '<S78>/Compare'
     *  RelationalOperator: '<S79>/Compare'
     *  RelationalOperator: '<S80>/Compare'
     */
    precondtrq_m = ((((Fv_SensorPowerTorque <= ((UInt16)MACRO_STRTRQ_POWERMAX)) &&
                      (Fv_SensorPowerTorque >= ((UInt16)MACRO_STRTRQ_POWERMIN)))
                     && (SysTaskTrqSplPending)) && (Fv_SysPower >=
      Cal_Power_LowReset));

    /* Sum: '<S76>/Add' incorporates:
     *  DataStoreRead: '<S76>/Data Store Read3'
     *  DataStoreRead: '<S76>/Data Store Read4'
     */
    sumtrq_m = (UInt16)(((UInt32)Fv_MainTorqueADVol) + ((UInt32)
      Fv_SubTorqueADVol));

    /* End of Outputs for SubSystem: '<S74>/TorqueSignalCond' */

    /* Chart: '<S74>/TorqueSignalDiag' */
    /* Gateway: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalDiag */
    /* During: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalDiag */
    if (((UInt32)
         FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_active_c37_FaultDiagRapid)
        == 0U) {
      /* Entry: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalDiag */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_active_c37_FaultDiagRapid =
        1;

      /* Entry Internal: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_TorqueCheck/TorqueCheck_Signal/DiagRapid_TorqueSignal_Check/SignalCheck/TorqueSignalDiag */
      /* Transition: '<S77>:1179' */
      FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_c37_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_fuou;
    } else if (((UInt32)
                FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_c37_FaultDiagRapid)
               == FaultDiagRapid_IN_Diag_l0ld) {
      /* During 'Diag': '<S77>:1181' */
      if (!precondtrq_m) {
        /* Transition: '<S77>:1180' */
        /* Exit Internal 'Diag': '<S77>:1181' */
        Faul_exit_internal_OffsetTorque();
        FaultDi_exit_internal_SumTorque();
        FaultDi_exit_internal_SubTorque();
        FaultD_exit_internal_MainTorque();
        FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_c37_FaultDiagRapid =
          FaultDiagRapid_IN_Wait_fuou;
      } else {
        FaultDiagRapid_MainTorque();
        FaultDiagRapid_SubTorque();
        FaultDiagRapid_SumTorque(&sumtrq_m);
        FaultDiagRapid_OffsetTorque(&sumtrq_m);
      }
    } else {
      /* During 'Wait': '<S77>:1178' */
      if (precondtrq_m) {
        /* Transition: '<S77>:1233' */
        FaultDiagRapidrtDW.SignalCheck.bitsForTID0.is_c37_FaultDiagRapid =
          FaultDiagRapid_IN_Diag_l0ld;

        /* Entry Internal 'Diag': '<S77>:1181' */
        FaultDi_enter_atomic_MainTorque();
        Fault_enter_internal_MainTorque();
        FaultDia_enter_atomic_SubTorque();
        FaultD_enter_internal_SubTorque();
        FaultDia_enter_atomic_SumTorque();
        FaultD_enter_internal_SumTorque();
        Fau_enter_internal_OffsetTorque();
      }
    }

    /* End of Chart: '<S74>/TorqueSignalDiag' */
  }

#endif

  /* End of Outputs for SubSystem: '<S65>/DiagRapid_TorqueSignal_Check' */
}

/* System reset for atomic system: '<S29>/DiagRapid_TorqueCheck' */
void Fau_DiagRapid_TorqueCheck_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S31>/TorqueCheck_Power' */
  FaultDi_TorqueCheck_Power_Reset();

  /* End of SystemReset for SubSystem: '<S31>/TorqueCheck_Power' */

  /* SystemReset for Atomic SubSystem: '<S31>/TorqueCheck_Signal' */
  FaultD_TorqueCheck_Signal_Reset();

  /* End of SystemReset for SubSystem: '<S31>/TorqueCheck_Signal' */
}

/* Output and update for atomic system: '<S29>/DiagRapid_TorqueCheck' */
void FaultDiag_DiagRapid_TorqueCheck(void)
{
  /* Outputs for Atomic SubSystem: '<S31>/TorqueCheck_Power' */
  FaultDiagRapi_TorqueCheck_Power();

  /* End of Outputs for SubSystem: '<S31>/TorqueCheck_Power' */

  /* Outputs for Atomic SubSystem: '<S31>/TorqueCheck_Signal' */
  FaultDiagRap_TorqueCheck_Signal();

  /* End of Outputs for SubSystem: '<S31>/TorqueCheck_Signal' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
