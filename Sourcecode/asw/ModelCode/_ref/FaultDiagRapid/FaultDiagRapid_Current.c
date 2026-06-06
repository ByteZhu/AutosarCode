/*
 * File: FaultDiagRapid_Current.c
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

#include "FaultDiagRapid_Current.h"

/* Include model header file for global data */
#include "FaultDiagRapid.h"
#include "FaultDiagRapid_private.h"

/* Named constants for Chart: '<S35>/CurrentMidDiag1' */
#define FaultDi_IN_NO_ACTIVE_CHILD_ov0w ((UInt8)0U)
#define FaultDiagRapid_IN_Fault        ((UInt8)1U)
#define FaultDiagRapid_IN_Normal       ((UInt8)2U)
#define FaultDiagRapid_IN_Run          ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_g5e1    ((UInt8)2U)

/* Named constants for Chart: '<S35>/CurrentMidDiag2' */
#define FaultDi_IN_NO_ACTIVE_CHILD_mhc1 ((UInt8)0U)
#define FaultDiagRapid_IN_Fault_da1b   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_aa0m  ((UInt8)2U)
#define FaultDiagRapid_IN_Run_o2ij     ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_mz33    ((UInt8)2U)

/* Named constants for Chart: '<S50>/CurrentSampleDiag1' */
#define FaultDi_IN_NO_ACTIVE_CHILD_b1v3 ((UInt8)0U)
#define FaultDiagRapid_IN_Fault_clhn   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_mjba  ((UInt8)2U)
#define FaultDiagRapid_IN_Run_csrf     ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_fcch    ((UInt8)2U)

/* Named constants for Chart: '<S50>/CurrentSampleDiag2' */
#define FaultDi_IN_NO_ACTIVE_CHILD_dogl ((UInt8)0U)
#define FaultDiagRapid_IN_Fault_fs5j   ((UInt8)1U)
#define FaultDiagRapid_IN_Normal_pisf  ((UInt8)2U)
#define FaultDiagRapid_IN_Run_hb31     ((UInt8)1U)
#define FaultDiagRapid_IN_Wait_pxkq    ((UInt8)2U)

/* System reset for atomic system: '<S35>/CurrentMidDiag1' */
#if DIAGDIS_CURRENTMIDREG == 0

void FaultDiag_CurrentMidDiag1_Reset(void)
{
  FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run_ipns =
    FaultDi_IN_NO_ACTIVE_CHILD_ov0w;
  FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_active_c6_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c6_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_ov0w;
  FaultDiagRapidrtDW.MidCheck.CM_TimeWin_aoak = 0U;
}

#endif

/* Output and update for atomic system: '<S35>/CurrentMidDiag1' */
#if DIAGDIS_CURRENTMIDREG == 0

void FaultDiagRapid_CurrentMidDiag1(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S35>/CurrentMidDiag1' incorporates:
   *  DataStoreRead: '<S45>/Data Store Read'
   *  DataStoreRead: '<S46>/Data Store Read'
   *  DataTypeConversion: '<S45>/Data Type Conversion2'
   *  Product: '<S45>/Product'
   *  Selector: '<S45>/Selector'
   *  Selector: '<S46>/Selector'
   */
  /* Gateway: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag1 */
  /* During: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag1 */
  if (((UInt32)
       FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_active_c6_FaultDiagRapid) ==
      0U) {
    /* Entry: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag1 */
    FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_active_c6_FaultDiagRapid = 1;

    /* Entry Internal: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag1 */
    /* Transition: '<S39>:1104' */
    FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c6_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_g5e1;
  } else if (((UInt32)
              FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c6_FaultDiagRapid) ==
             FaultDiagRapid_IN_Run) {
    /* During 'Run': '<S39>:1103' */
    if (!FaultDiagRapidrtDW.MidCheck.precond2) {
      /* Transition: '<S39>:1120' */
      /* Exit Internal 'Run': '<S39>:1103' */
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run_ipns =
        FaultDi_IN_NO_ACTIVE_CHILD_ov0w;
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c6_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_g5e1;
    } else if (((UInt32)FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run_ipns) ==
               FaultDiagRapid_IN_Fault) {
      /* During 'Fault': '<S39>:1105' */
      if ((FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 <= ((UInt16)
            MACRO_CURRENT_MIDMAX)) &&
          (FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 >= ((UInt16)
            MACRO_CURRENT_MIDMIN))) {
        /* Transition: '<S39>:1119' */
        FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run_ipns =
          FaultDiagRapid_IN_Normal;
      } else {
        /* Transition: '<S39>:1108' */
        if (((Int32)FaultDiagRapidrtDW.MidCheck.CM_TimeWin_aoak) > 0) {
          /* Transition: '<S39>:1110' */
          /* Transition: '<S39>:1133' */
          FaultDiagRapidrtDW.MidCheck.CM_TimeWin_aoak = (UInt16)((Int32)(((Int32)
            FaultDiagRapidrtDW.MidCheck.CM_TimeWin_aoak) - 1));

          /* Transition: '<S39>:1135' */
        } else {
          /* Outputs for Function Call SubSystem: '<S39>/DTC_Ctrl_Enabled' */
          /* Selector: '<S45>/Selector' */
          /* Transition: '<S39>:1111' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S39>:1152' */
          Fv_ErrDiagStatus_tmp = DTC_CURRENTcheck_MiddSig;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S39>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S39>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S39>:1148' */
          Fv_FaultClass_Current = (UInt16)SetU16Fault(Fv_FaultClass_Current, 0,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_CURRENTcheck_MiddSig].Enabled);

          /* End of Outputs for SubSystem: '<S39>/getDTCEnabled' */
        }
      }
    } else {
      /* During 'Normal': '<S39>:1106' */
      if ((FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 > ((UInt16)
            MACRO_CURRENT_MIDMAX)) ||
          (FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 < ((UInt16)
            MACRO_CURRENT_MIDMIN))) {
        /* Transition: '<S39>:1118' */
        FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run_ipns =
          FaultDiagRapid_IN_Fault;

        /* Entry 'Fault': '<S39>:1105' */
        FaultDiagRapidrtDW.MidCheck.CM_TimeWin_aoak = ((UInt16)
          MACRO_CURRENT_CHECKTIME);
      }
    }
  } else {
    /* During 'Wait': '<S39>:1102' */
    if (FaultDiagRapidrtDW.MidCheck.precond2) {
      /* Transition: '<S39>:1121' */
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c6_FaultDiagRapid =
        FaultDiagRapid_IN_Run;

      /* Entry Internal 'Run': '<S39>:1103' */
      /* Transition: '<S39>:1112' */
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run_ipns =
        FaultDiagRapid_IN_Normal;
    }
  }

  /* End of Chart: '<S35>/CurrentMidDiag1' */
}

#endif

/* System reset for atomic system: '<S35>/CurrentMidDiag2' */
#if DIAGDIS_CURRENTMIDREG == 0

void FaultDiag_CurrentMidDiag2_Reset(void)
{
  FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run =
    FaultDi_IN_NO_ACTIVE_CHILD_mhc1;
  FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_active_c7_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c7_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_mhc1;
  FaultDiagRapidrtDW.MidCheck.CM_TimeWin = 0U;
}

#endif

/* Output and update for atomic system: '<S35>/CurrentMidDiag2' */
#if DIAGDIS_CURRENTMIDREG == 0

void FaultDiagRapid_CurrentMidDiag2(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S35>/CurrentMidDiag2' incorporates:
   *  DataStoreRead: '<S47>/Data Store Read'
   *  DataStoreRead: '<S48>/Data Store Read'
   *  DataTypeConversion: '<S47>/Data Type Conversion2'
   *  Product: '<S47>/Product'
   *  Selector: '<S47>/Selector'
   *  Selector: '<S48>/Selector'
   */
  /* Gateway: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag2 */
  /* During: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag2 */
  if (((UInt32)
       FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_active_c7_FaultDiagRapid) ==
      0U) {
    /* Entry: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag2 */
    FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_active_c7_FaultDiagRapid = 1;

    /* Entry Internal: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Mid/DiagReg_CurrentMid_Check/MidCheck/CurrentMidDiag2 */
    /* Transition: '<S40>:1104' */
    FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c7_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_mz33;
  } else if (((UInt32)
              FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c7_FaultDiagRapid) ==
             FaultDiagRapid_IN_Run_o2ij) {
    /* During 'Run': '<S40>:1103' */
    if (!FaultDiagRapidrtDW.MidCheck.precond2) {
      /* Transition: '<S40>:1120' */
      /* Exit Internal 'Run': '<S40>:1103' */
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run =
        FaultDi_IN_NO_ACTIVE_CHILD_mhc1;
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c7_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_mz33;
    } else if (((UInt32)FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run) ==
               FaultDiagRapid_IN_Fault_da1b) {
      /* During 'Fault': '<S40>:1105' */
      if ((FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 <= ((UInt16)
            MACRO_CURRENT_MIDMAX)) &&
          (FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 >= ((UInt16)
            MACRO_CURRENT_MIDMIN))) {
        /* Transition: '<S40>:1119' */
        FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run =
          FaultDiagRapid_IN_Normal_aa0m;
      } else {
        /* Transition: '<S40>:1108' */
        if (((Int32)FaultDiagRapidrtDW.MidCheck.CM_TimeWin) > 0) {
          /* Transition: '<S40>:1110' */
          /* Transition: '<S40>:1133' */
          FaultDiagRapidrtDW.MidCheck.CM_TimeWin = (UInt16)((Int32)(((Int32)
            FaultDiagRapidrtDW.MidCheck.CM_TimeWin) - 1));

          /* Transition: '<S40>:1135' */
        } else {
          /* Outputs for Function Call SubSystem: '<S40>/DTC_Ctrl_Enabled' */
          /* Selector: '<S47>/Selector' */
          /* Transition: '<S40>:1111' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S40>:1152' */
          Fv_ErrDiagStatus_tmp = DTC_CURRENTcheck_MiddSig;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S40>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S40>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S40>:1148' */
          Fv_FaultClass_Current = (UInt16)SetU16Fault(Fv_FaultClass_Current, 1,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_CURRENTcheck_MiddSig].Enabled);

          /* End of Outputs for SubSystem: '<S40>/getDTCEnabled' */
        }
      }
    } else {
      /* During 'Normal': '<S40>:1106' */
      if ((FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 > ((UInt16)
            MACRO_CURRENT_MIDMAX)) ||
          (FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 < ((UInt16)
            MACRO_CURRENT_MIDMIN))) {
        /* Transition: '<S40>:1118' */
        FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run =
          FaultDiagRapid_IN_Fault_da1b;

        /* Entry 'Fault': '<S40>:1105' */
        FaultDiagRapidrtDW.MidCheck.CM_TimeWin = ((UInt16)
          MACRO_CURRENT_CHECKTIME);
      }
    }
  } else {
    /* During 'Wait': '<S40>:1102' */
    if (FaultDiagRapidrtDW.MidCheck.precond2) {
      /* Transition: '<S40>:1121' */
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_c7_FaultDiagRapid =
        FaultDiagRapid_IN_Run_o2ij;

      /* Entry Internal 'Run': '<S40>:1103' */
      /* Transition: '<S40>:1112' */
      FaultDiagRapidrtDW.MidCheck.bitsForTID0.is_Run =
        FaultDiagRapid_IN_Normal_aa0m;
    }
  }

  /* End of Chart: '<S35>/CurrentMidDiag2' */
}

#endif

/* System reset for atomic system: '<S30>/CurrentCheck_Mid' */
void FaultDia_CurrentCheck_Mid_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S32>/DiagReg_CurrentMid_Check' */
#if DIAGDIS_CURRENTMIDREG == 0

  /* Reset conditions for atomic system: '<S34>/MidCheck' */

  /* SystemReset for Chart: '<S35>/CurrentMidDiag1' */
  FaultDiag_CurrentMidDiag1_Reset();

  /* SystemReset for Chart: '<S35>/CurrentMidDiag2' */
  FaultDiag_CurrentMidDiag2_Reset();

#endif

  /* End of SystemReset for SubSystem: '<S32>/DiagReg_CurrentMid_Check' */
}

/* Output and update for atomic system: '<S30>/CurrentCheck_Mid' */
void FaultDiagRapid_CurrentCheck_Mid(void)
{
  /* Outputs for Atomic SubSystem: '<S32>/DiagReg_CurrentMid_Check' */
#if DIAGDIS_CURRENTMIDREG == 0

  /* Output and update for atomic system: '<S34>/MidCheck' */

  /* Outputs for Atomic SubSystem: '<S35>/CurrentMidCond1' */
  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant'
   *  Inport: '<Root>/AD_I2D5Ref1'
   */
  FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 = (UInt16)((((UInt32)
    AD_I2D5Ref1) * ((UInt32)((UInt16)MACRO_AV_AD2VOL_1))) >> 6);

  /* DataStoreWrite: '<S37>/Data Store Write' */
  Fv_I2D5RefADVol1 = FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3;

  /* Logic: '<S37>/Logical Operator' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S42>/Constant'
   *  DataStoreRead: '<S37>/Data Store Read1'
   *  DataStoreRead: '<S37>/Data Store Read2'
   *  DataStoreRead: '<S37>/Data Store Read3'
   *  Inport: '<Root>/IO_PredriverState1'
   *  RelationalOperator: '<S41>/Compare'
   *  RelationalOperator: '<S42>/Compare'
   */
  FaultDiagRapidrtDW.MidCheck.precond2 = ((((IO_PredriverState1) &&
    (SysTaskPreDriverPending1)) && (Fv_SysPower >= Cal_Power_LowReset)) &&
    (Fv_SysPowerRelay >= ((Int16)MACRO_TP_BRIDGEWORK)));

  /* End of Outputs for SubSystem: '<S35>/CurrentMidCond1' */

  /* Chart: '<S35>/CurrentMidDiag1' */
  FaultDiagRapid_CurrentMidDiag1();

  /* Outputs for Atomic SubSystem: '<S35>/CurrentMidCond2' */
  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S38>/Constant'
   *  Inport: '<Root>/AD_I2D5Ref2'
   */
  FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3 = (UInt16)((((UInt32)
    AD_I2D5Ref2) * ((UInt32)((UInt16)MACRO_AV_AD2VOL_2))) >> 6);

  /* DataStoreWrite: '<S38>/Data Store Write' */
  Fv_I2D5RefADVol2 = FaultDiagRapidrtDW.MidCheck.Fv_I2D5RefADVol2_j1h3;

  /* Logic: '<S38>/Logical Operator' incorporates:
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  DataStoreRead: '<S38>/Data Store Read1'
   *  DataStoreRead: '<S38>/Data Store Read2'
   *  DataStoreRead: '<S38>/Data Store Read3'
   *  Inport: '<Root>/IO_PredriverState2'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S44>/Compare'
   */
  FaultDiagRapidrtDW.MidCheck.precond2 = ((((IO_PredriverState2) &&
    (SysTaskPreDriverPending2)) && (Fv_SysPower >= Cal_Power_LowReset)) &&
    (Fv_SysPowerRelay >= ((Int16)MACRO_TP_BRIDGEWORK)));

  /* End of Outputs for SubSystem: '<S35>/CurrentMidCond2' */

  /* Chart: '<S35>/CurrentMidDiag2' */
  FaultDiagRapid_CurrentMidDiag2();

#elif DIAGDIS_CURRENTMIDREG == 1

  /* Output and update for atomic system: '<S34>/MidCheckDis' */

  /* Product: '<S36>/Product' incorporates:
   *  Constant: '<S36>/Constant'
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  Inport: '<Root>/AD_I2D5Ref1'
   */
  Fv_I2D5RefADVol1 = (UInt16)((((UInt32)AD_I2D5Ref1) * ((UInt32)((UInt16)
    MACRO_AV_AD2VOL))) >> 6);

  /* Product: '<S36>/Product1' incorporates:
   *  Constant: '<S36>/Constant'
   *  DataStoreWrite: '<S36>/Data Store Write1'
   *  Inport: '<Root>/AD_I2D5Ref2'
   */
  Fv_I2D5RefADVol2 = (UInt16)((((UInt32)((UInt16)MACRO_AV_AD2VOL)) * ((UInt32)
    AD_I2D5Ref2)) >> 6);

#endif

  /* End of Outputs for SubSystem: '<S32>/DiagReg_CurrentMid_Check' */
}

/* System reset for atomic system: '<S50>/CurrentSampleDiag1' */
#if DIAGDIS_CURRENTSAMPLEREG == 0

void FaultD_CurrentSampleDiag1_Reset(void)
{
  FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run_phx2 =
    FaultDi_IN_NO_ACTIVE_CHILD_b1v3;
  FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_active_c9_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c9_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_b1v3;
  FaultDiagRapidrtDW.SampleCheck.CS_TimeWin_gn52 = 0U;
}

#endif

/* Output and update for atomic system: '<S50>/CurrentSampleDiag1' */
#if DIAGDIS_CURRENTSAMPLEREG == 0

void FaultDiagRap_CurrentSampleDiag1(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S50>/CurrentSampleDiag1' incorporates:
   *  DataStoreRead: '<S60>/Data Store Read'
   *  DataStoreRead: '<S61>/Data Store Read'
   *  DataTypeConversion: '<S60>/Data Type Conversion2'
   *  Product: '<S60>/Product'
   *  Selector: '<S60>/Selector'
   *  Selector: '<S61>/Selector'
   */
  /* Gateway: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag1 */
  /* During: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag1 */
  if (((UInt32)
       FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_active_c9_FaultDiagRapid) ==
      0U) {
    /* Entry: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag1 */
    FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_active_c9_FaultDiagRapid = 1;

    /* Entry Internal: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag1 */
    /* Transition: '<S54>:1104' */
    FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c9_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_fcch;
  } else if (((UInt32)
              FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c9_FaultDiagRapid) ==
             FaultDiagRapid_IN_Run_csrf) {
    /* During 'Run': '<S54>:1103' */
    if (!FaultDiagRapidrtDW.SampleCheck.precondsum2) {
      /* Transition: '<S54>:1120' */
      /* Exit Internal 'Run': '<S54>:1103' */
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run_phx2 =
        FaultDi_IN_NO_ACTIVE_CHILD_b1v3;
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c9_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_fcch;
    } else if (((UInt32)FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run_phx2) ==
               FaultDiagRapid_IN_Fault_clhn) {
      /* During 'Fault': '<S54>:1105' */
      if (FaultDiagRapidrtDW.SampleCheck.isum2 <= MACRO_CURRENT_SUMMAX) {
        /* Transition: '<S54>:1119' */
        FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run_phx2 =
          FaultDiagRapid_IN_Normal_mjba;
      } else {
        /* Transition: '<S54>:1108' */
        if (((Int32)FaultDiagRapidrtDW.SampleCheck.CS_TimeWin_gn52) > 0) {
          /* Transition: '<S54>:1110' */
          /* Transition: '<S54>:1133' */
          FaultDiagRapidrtDW.SampleCheck.CS_TimeWin_gn52 = (UInt16)((Int32)
            (((Int32)FaultDiagRapidrtDW.SampleCheck.CS_TimeWin_gn52) - 1));

          /* Transition: '<S54>:1135' */
        } else {
          /* Outputs for Function Call SubSystem: '<S54>/DTC_Ctrl_Enabled' */
          /* Selector: '<S60>/Selector' */
          /* Transition: '<S54>:1111' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S54>:1152' */
          Fv_ErrDiagStatus_tmp = DTC_CURRENTcheck_3PhaseSum;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S54>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S54>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S54>:1148' */
          Fv_FaultClass_Current = (UInt16)SetU16Fault(Fv_FaultClass_Current, 2,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_CURRENTcheck_3PhaseSum].Enabled);

          /* End of Outputs for SubSystem: '<S54>/getDTCEnabled' */
        }
      }
    } else {
      /* During 'Normal': '<S54>:1106' */
      if (FaultDiagRapidrtDW.SampleCheck.isum2 > MACRO_CURRENT_SUMMAX) {
        /* Transition: '<S54>:1118' */
        FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run_phx2 =
          FaultDiagRapid_IN_Fault_clhn;

        /* Entry 'Fault': '<S54>:1105' */
        FaultDiagRapidrtDW.SampleCheck.CS_TimeWin_gn52 = ((UInt16)
          MACRO_CURRENT_CHECKTIME);
      }
    }
  } else {
    /* During 'Wait': '<S54>:1102' */
    if (FaultDiagRapidrtDW.SampleCheck.precondsum2) {
      /* Transition: '<S54>:1121' */
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c9_FaultDiagRapid =
        FaultDiagRapid_IN_Run_csrf;

      /* Entry Internal 'Run': '<S54>:1103' */
      /* Transition: '<S54>:1112' */
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run_phx2 =
        FaultDiagRapid_IN_Normal_mjba;
    }
  }

  /* End of Chart: '<S50>/CurrentSampleDiag1' */
}

#endif

/* System reset for atomic system: '<S50>/CurrentSampleDiag2' */
#if DIAGDIS_CURRENTSAMPLEREG == 0

void FaultD_CurrentSampleDiag2_Reset(void)
{
  FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run =
    FaultDi_IN_NO_ACTIVE_CHILD_dogl;
  FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_active_c10_FaultDiagRapid = 0;
  FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c10_FaultDiagRapid =
    FaultDi_IN_NO_ACTIVE_CHILD_dogl;
  FaultDiagRapidrtDW.SampleCheck.CS_TimeWin = 0U;
}

#endif

/* Output and update for atomic system: '<S50>/CurrentSampleDiag2' */
#if DIAGDIS_CURRENTSAMPLEREG == 0

void FaultDiagRap_CurrentSampleDiag2(void)
{
  Int32 Fv_ErrDiagStatus_tmp;

  /* Chart: '<S50>/CurrentSampleDiag2' incorporates:
   *  DataStoreRead: '<S62>/Data Store Read'
   *  DataStoreRead: '<S63>/Data Store Read'
   *  DataTypeConversion: '<S62>/Data Type Conversion2'
   *  Product: '<S62>/Product'
   *  Selector: '<S62>/Selector'
   *  Selector: '<S63>/Selector'
   */
  /* Gateway: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag2 */
  /* During: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag2 */
  if (((UInt32)
       FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_active_c10_FaultDiagRapid) ==
      0U) {
    /* Entry: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag2 */
    FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_active_c10_FaultDiagRapid = 1;

    /* Entry Internal: DiagRapid_Step1Func/DiagRapid_Step1/DiagRapid_CurrentCheck/CurrentCheck_Sample/DiagReg_CurrentSample_Check/SampleCheck/CurrentSampleDiag2 */
    /* Transition: '<S55>:1104' */
    FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c10_FaultDiagRapid =
      FaultDiagRapid_IN_Wait_pxkq;
  } else if (((UInt32)
              FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c10_FaultDiagRapid) ==
             FaultDiagRapid_IN_Run_hb31) {
    /* During 'Run': '<S55>:1103' */
    if (!FaultDiagRapidrtDW.SampleCheck.precondsum2) {
      /* Transition: '<S55>:1120' */
      /* Exit Internal 'Run': '<S55>:1103' */
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run =
        FaultDi_IN_NO_ACTIVE_CHILD_dogl;
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c10_FaultDiagRapid =
        FaultDiagRapid_IN_Wait_pxkq;
    } else if (((UInt32)FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run) ==
               FaultDiagRapid_IN_Fault_fs5j) {
      /* During 'Fault': '<S55>:1105' */
      if (FaultDiagRapidrtDW.SampleCheck.isum2 <= MACRO_CURRENT_SUMMAX) {
        /* Transition: '<S55>:1119' */
        FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run =
          FaultDiagRapid_IN_Normal_pisf;
      } else {
        /* Transition: '<S55>:1108' */
        if (((Int32)FaultDiagRapidrtDW.SampleCheck.CS_TimeWin) > 0) {
          /* Transition: '<S55>:1110' */
          /* Transition: '<S55>:1133' */
          FaultDiagRapidrtDW.SampleCheck.CS_TimeWin = (UInt16)((Int32)(((Int32)
            FaultDiagRapidrtDW.SampleCheck.CS_TimeWin) - 1));

          /* Transition: '<S55>:1135' */
        } else {
          /* Outputs for Function Call SubSystem: '<S55>/DTC_Ctrl_Enabled' */
          /* Selector: '<S62>/Selector' */
          /* Transition: '<S55>:1111' */
          /* Simulink Function 'DTC_Ctrl_Enabled': '<S55>:1152' */
          Fv_ErrDiagStatus_tmp = DTC_CURRENTcheck_3PhaseSum;
          Fv_ErrDiagStatus[(Fv_ErrDiagStatus_tmp)] = (FailureDiag)(((UInt32)
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))[Fv_ErrDiagStatus_tmp]
            .Enabled) * ((UInt32)FailureDiag_RegErr));

          /* End of Outputs for SubSystem: '<S55>/DTC_Ctrl_Enabled' */

          /* Outputs for Function Call SubSystem: '<S55>/getDTCEnabled' */
          /* Simulink Function 'getDTCEnabled': '<S55>:1148' */
          Fv_FaultClass_Current = (UInt16)SetU16Fault(Fv_FaultClass_Current, 3,
            (((tagDTC_Ctrl_Info *)&(DTC_Ctrl_Info_Tab[0])))
            [DTC_CURRENTcheck_3PhaseSum].Enabled);

          /* End of Outputs for SubSystem: '<S55>/getDTCEnabled' */
        }
      }
    } else {
      /* During 'Normal': '<S55>:1106' */
      if (FaultDiagRapidrtDW.SampleCheck.isum2 > MACRO_CURRENT_SUMMAX) {
        /* Transition: '<S55>:1118' */
        FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run =
          FaultDiagRapid_IN_Fault_fs5j;

        /* Entry 'Fault': '<S55>:1105' */
        FaultDiagRapidrtDW.SampleCheck.CS_TimeWin = ((UInt16)
          MACRO_CURRENT_CHECKTIME);
      }
    }
  } else {
    /* During 'Wait': '<S55>:1102' */
    if (FaultDiagRapidrtDW.SampleCheck.precondsum2) {
      /* Transition: '<S55>:1121' */
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_c10_FaultDiagRapid =
        FaultDiagRapid_IN_Run_hb31;

      /* Entry Internal 'Run': '<S55>:1103' */
      /* Transition: '<S55>:1112' */
      FaultDiagRapidrtDW.SampleCheck.bitsForTID0.is_Run =
        FaultDiagRapid_IN_Normal_pisf;
    }
  }

  /* End of Chart: '<S50>/CurrentSampleDiag2' */
}

#endif

/* System reset for atomic system: '<S30>/CurrentCheck_Sample' */
void Fault_CurrentCheck_Sample_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S33>/DiagReg_CurrentSample_Check' */
#if DIAGDIS_CURRENTSAMPLEREG == 0

  /* Reset conditions for atomic system: '<S49>/SampleCheck' */

  /* SystemReset for Chart: '<S50>/CurrentSampleDiag1' */
  FaultD_CurrentSampleDiag1_Reset();

  /* SystemReset for Chart: '<S50>/CurrentSampleDiag2' */
  FaultD_CurrentSampleDiag2_Reset();

#endif

  /* End of SystemReset for SubSystem: '<S33>/DiagReg_CurrentSample_Check' */
}

/* Output and update for atomic system: '<S30>/CurrentCheck_Sample' */
void FaultDiagRa_CurrentCheck_Sample(void)
{
  /* Outputs for Atomic SubSystem: '<S33>/DiagReg_CurrentSample_Check' */
#if DIAGDIS_CURRENTSAMPLEREG == 0

  /* Output and update for atomic system: '<S49>/SampleCheck' */
  {
    Int32 rtb_Add;

    /* Outputs for Atomic SubSystem: '<S50>/CurrentSampleCond1' */
    /* Sum: '<S52>/Add' incorporates:
     *  DataStoreRead: '<S52>/Data Store Read4'
     *  DataStoreRead: '<S52>/Data Store Read5'
     *  DataStoreRead: '<S52>/Data Store Read6'
     */
    rtb_Add = (Fv_MotorCurrent_U1 + Fv_MotorCurrent_V1) + Fv_MotorCurrent_W1;

    /* Abs: '<S52>/Abs' */
    if (rtb_Add < 0) {
      FaultDiagRapidrtDW.SampleCheck.isum2 = -rtb_Add;
    } else {
      FaultDiagRapidrtDW.SampleCheck.isum2 = rtb_Add;
    }

    /* End of Abs: '<S52>/Abs' */

    /* Logic: '<S52>/Logical Operator1' incorporates:
     *  Constant: '<S56>/Constant'
     *  Constant: '<S57>/Constant'
     *  DataStoreRead: '<S52>/Data Store Read'
     *  DataStoreRead: '<S52>/Data Store Read1'
     *  Inport: '<Root>/IO_PredriverState1'
     *  RelationalOperator: '<S56>/Compare'
     *  RelationalOperator: '<S57>/Compare'
     */
    FaultDiagRapidrtDW.SampleCheck.precondsum2 = ((((IO_PredriverState1) &&
      (SysTaskPreDriverPending1)) && (Fv_I2D5RefADVol1 <= ((UInt16)
      MACRO_CURRENT_MIDMAX))) && (Fv_I2D5RefADVol1 >= ((UInt16)
      MACRO_CURRENT_MIDMIN)));

    /* End of Outputs for SubSystem: '<S50>/CurrentSampleCond1' */

    /* Chart: '<S50>/CurrentSampleDiag1' */
    FaultDiagRap_CurrentSampleDiag1();

    /* Outputs for Atomic SubSystem: '<S50>/CurrentSampleCond2' */
    /* Sum: '<S53>/Add' incorporates:
     *  DataStoreRead: '<S53>/Data Store Read4'
     *  DataStoreRead: '<S53>/Data Store Read5'
     *  DataStoreRead: '<S53>/Data Store Read6'
     */
    rtb_Add = (Fv_MotorCurrent_U2 + Fv_MotorCurrent_V2) + Fv_MotorCurrent_W2;

    /* Abs: '<S53>/Abs' */
    if (rtb_Add < 0) {
      FaultDiagRapidrtDW.SampleCheck.isum2 = -rtb_Add;
    } else {
      FaultDiagRapidrtDW.SampleCheck.isum2 = rtb_Add;
    }

    /* End of Abs: '<S53>/Abs' */

    /* Logic: '<S53>/Logical Operator1' incorporates:
     *  Constant: '<S58>/Constant'
     *  Constant: '<S59>/Constant'
     *  DataStoreRead: '<S53>/Data Store Read'
     *  DataStoreRead: '<S53>/Data Store Read1'
     *  Inport: '<Root>/IO_PredriverState2'
     *  RelationalOperator: '<S58>/Compare'
     *  RelationalOperator: '<S59>/Compare'
     */
    FaultDiagRapidrtDW.SampleCheck.precondsum2 = ((((IO_PredriverState2) &&
      (SysTaskPreDriverPending2)) && (Fv_I2D5RefADVol2 <= ((UInt16)
      MACRO_CURRENT_MIDMAX))) && (Fv_I2D5RefADVol2 >= ((UInt16)
      MACRO_CURRENT_MIDMIN)));

    /* End of Outputs for SubSystem: '<S50>/CurrentSampleCond2' */

    /* Chart: '<S50>/CurrentSampleDiag2' */
    FaultDiagRap_CurrentSampleDiag2();
  }

#endif

  /* End of Outputs for SubSystem: '<S33>/DiagReg_CurrentSample_Check' */
}

/* System reset for atomic system: '<S29>/DiagRapid_CurrentCheck' */
void Fa_DiagRapid_CurrentCheck_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S30>/CurrentCheck_Mid' */
  FaultDia_CurrentCheck_Mid_Reset();

  /* End of SystemReset for SubSystem: '<S30>/CurrentCheck_Mid' */

  /* SystemReset for Atomic SubSystem: '<S30>/CurrentCheck_Sample' */
  Fault_CurrentCheck_Sample_Reset();

  /* End of SystemReset for SubSystem: '<S30>/CurrentCheck_Sample' */
}

/* Output and update for atomic system: '<S29>/DiagRapid_CurrentCheck' */
void FaultDia_DiagRapid_CurrentCheck(void)
{
  /* Outputs for Atomic SubSystem: '<S30>/CurrentCheck_Mid' */
  FaultDiagRapid_CurrentCheck_Mid();

  /* End of Outputs for SubSystem: '<S30>/CurrentCheck_Mid' */

  /* Outputs for Atomic SubSystem: '<S30>/CurrentCheck_Sample' */
  FaultDiagRa_CurrentCheck_Sample();

  /* End of Outputs for SubSystem: '<S30>/CurrentCheck_Sample' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
