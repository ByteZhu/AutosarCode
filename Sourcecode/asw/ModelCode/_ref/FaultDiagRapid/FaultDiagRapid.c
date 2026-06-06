/*
 * File: FaultDiagRapid.c
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

#include "FaultDiagRapid.h"
#include "FaultDiagRapid_private.h"

/* Block states (default storage) */
volatile FaultDiagRapid_DW_fwu4 FaultDiagRapidrtDW;

/* Previous zero-crossings (trigger) states */
FaultDiagRapid_ZCE FaultDiagRapidrtPrevZCX;

/* System reset for atomic system: '<S3>/DiagRapid_Step1' */
void FaultDiag_DiagRapid_Step1_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S29>/DiagRapid_CurrentCheck' */
  Fa_DiagRapid_CurrentCheck_Reset();

  /* End of SystemReset for SubSystem: '<S29>/DiagRapid_CurrentCheck' */

  /* SystemReset for Atomic SubSystem: '<S29>/DiagRapid_TorqueCheck' */
  Fau_DiagRapid_TorqueCheck_Reset();

  /* End of SystemReset for SubSystem: '<S29>/DiagRapid_TorqueCheck' */
}

/* Output and update for atomic system: '<S3>/DiagRapid_Step1' */
void FaultDiagRapid_DiagRapid_Step1(void)
{
  /* Outputs for Resettable SubSystem: '<S3>/DiagRapid_Step1' incorporates:
   *  ResetPort: '<S29>/Reset'
   */
  if ((FaultDiagRapidrtDW.reset_flag) && (((UInt32)
        FaultDiagRapidrtPrevZCX.DiagRapid_Step1_Reset_ZCE) != POS_ZCSIG)) {
    FaultDiag_DiagRapid_Step1_Reset();
  }

  FaultDiagRapidrtPrevZCX.DiagRapid_Step1_Reset_ZCE =
    FaultDiagRapidrtDW.reset_flag ? ((ZCSigState)1) : ((ZCSigState)0);

  /* Outputs for Atomic SubSystem: '<S29>/DiagRapid_CurrentCheck' */
  FaultDia_DiagRapid_CurrentCheck();

  /* End of Outputs for SubSystem: '<S29>/DiagRapid_CurrentCheck' */

  /* Outputs for Atomic SubSystem: '<S29>/DiagRapid_TorqueCheck' */
  FaultDiag_DiagRapid_TorqueCheck();

  /* End of Outputs for SubSystem: '<S29>/DiagRapid_TorqueCheck' */
  /* End of Outputs for SubSystem: '<S3>/DiagRapid_Step1' */
}

/* System reset for atomic system: '<S4>/DiagInit_Step2' */
void FaultDiagR_DiagInit_Step2_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S83>/DiagRapid_MotoCheck' */
  Fault_DiagRapid_MotoCheck_Reset();

  /* End of SystemReset for SubSystem: '<S83>/DiagRapid_MotoCheck' */

  /* SystemReset for Atomic SubSystem: '<S83>/DiagRapid_RotorCheck' */
  Faul_DiagRapid_RotorCheck_Reset();

  /* End of SystemReset for SubSystem: '<S83>/DiagRapid_RotorCheck' */

  /* SystemReset for Atomic SubSystem: '<S83>/DiagRapid_MCUCheck' */
  FaultD_DiagRapid_MCUCheck_Reset();

  /* End of SystemReset for SubSystem: '<S83>/DiagRapid_MCUCheck' */
}

/* Output and update for atomic system: '<S4>/DiagInit_Step2' */
void FaultDiagRapid_DiagInit_Step2(void)
{
  /* Outputs for Resettable SubSystem: '<S4>/DiagInit_Step2' incorporates:
   *  ResetPort: '<S83>/Reset'
   */
  if ((FaultDiagRapidrtDW.reset_flag) && (((UInt32)
        FaultDiagRapidrtPrevZCX.DiagInit_Step2_Reset_ZCE) != POS_ZCSIG)) {
    FaultDiagR_DiagInit_Step2_Reset();
  }

  FaultDiagRapidrtPrevZCX.DiagInit_Step2_Reset_ZCE =
    FaultDiagRapidrtDW.reset_flag ? ((ZCSigState)1) : ((ZCSigState)0);

  /* Outputs for Atomic SubSystem: '<S83>/DiagRapid_MotoCheck' */
  FaultDiagRa_DiagRapid_MotoCheck();

  /* End of Outputs for SubSystem: '<S83>/DiagRapid_MotoCheck' */

  /* Outputs for Atomic SubSystem: '<S83>/DiagRapid_RotorCheck' */
  FaultDiagR_DiagRapid_RotorCheck();

  /* End of Outputs for SubSystem: '<S83>/DiagRapid_RotorCheck' */

  /* Outputs for Atomic SubSystem: '<S83>/DiagRapid_MCUCheck' */
  FaultDiagRap_DiagRapid_MCUCheck();

  /* End of Outputs for SubSystem: '<S83>/DiagRapid_MCUCheck' */
  /* End of Outputs for SubSystem: '<S4>/DiagInit_Step2' */
}

/* Output and update for atomic system: '<Root>/FailStateReview' */
void FaultDiagRapid_FailStateReview(void)
{
  Int32 tmp;
  Int32 tmp_0;
  FailureDiag tmp_1;

  /* Chart: '<S5>/FailStateReview' incorporates:
   *  Inport: '<Root>/WhichMode'
   */
  /* Gateway: FailStateReview/FailStateReview */
  /* During: FailStateReview/FailStateReview */
  /* Entry Internal: FailStateReview/FailStateReview */
  /* Transition: '<S201>:154' */
  tmp = CANBUS_ABSWs;
  tmp_0 = CANBUS_EMSEt;
  if ((((((((((Fv_ErrDiagStatus[DTC_MCUcheck_CommTimeout] > FailureDiag_RegOK) ||
              (Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] > FailureDiag_RegOK))
             || (Fv_ErrDiagStatus[DTC_POWERcheck_IGkey] > FailureDiag_RegOK)) ||
            (Fv_ErrDiagStatus[DTC_TEMPcheck_TempLimitAst] > FailureDiag_RegOK)) ||
           ((((Int32)Fv_FaultClass_Eeprom) & ((Int32)((UInt16)DiagEepromMask)))
            != 0)) || ((((Int32)Fv_FaultClass_CAN) & ((Int32)((UInt16)
              DiagCANMask))) != 0)) || (Fv_SystemCANDiagStatus[(tmp)] >
          FailureDiag_RegOK)) || (Fv_SystemCANDiagStatus[(tmp_0)] >
         FailureDiag_RegOK)) || (Fv_SystemCANErrrStatus[(tmp)] >
        FailureDiag_RegOK)) || (Fv_SystemCANErrrStatus[(tmp_0)] >
       FailureDiag_RegOK)) {
    /* DataStoreWrite: '<S5>/Data Store Write' */
    /* Transition: '<S201>:104' */
    /* Transition: '<S201>:114' */
    Fv_InessentialFailFlag = 1;

    /* Transition: '<S201>:107' */
  } else {
    /* DataStoreWrite: '<S5>/Data Store Write' */
    /* Transition: '<S201>:153' */
    Fv_InessentialFailFlag = 0;
  }

  /* Transition: '<S201>:162' */
  tmp_1 = Fv_ErrDiagStatus[DTC_EEPROMcheck_CommTimeout];
  if ((((Fv_ErrDiagStatus[DTC_POWERcheck_Hold] > FailureDiag_RegOK) || (tmp_1 ==
         FailureDiag_RegErr)) || (Fv_ErrDiagStatus[DTC_TEMPcheck_HeatShut] >
        FailureDiag_RegOK)) || (Fv_ErrDiagStatus[DTC_ANGLEcheck_Unreal] >
       FailureDiag_RegOK)) {
    /* Transition: '<S201>:164' */
    /* Transition: '<S201>:146' */
    Fv_LightLampFailFlag = 1;

    /* Transition: '<S201>:108' */
  } else {
    /* Transition: '<S201>:139' */
    Fv_LightLampFailFlag = 0;
  }

  /* Transition: '<S201>:178' */
  /*    */
#if 0
  tmp = CANBUS_ABSVs;
  if ((((Fv_ErrDiagStatus[DTC_CANCOMMcheck_Busoff] > FailureDiag_RegOK) ||
        (Fv_SystemCANDiagStatus[(tmp)] > FailureDiag_RegOK)) ||
       (fsVehSpdSignalInValid > 0)) || (Fv_EsSlopeVsflag))
#else
  if(Fv_AbsInvalidFlag > 0)
#endif
  {
    /* DataStoreWrite: '<S5>/Data Store Write2' */
    /* Transition: '<S201>:180' */
    /* Transition: '<S201>:182' */
    Fv_VehEngFailFlag = 1;
    if (WhichMode < HOLD_ACTIVE) {
      /* Transition: '<S201>:186' */
      /* Transition: '<S201>:188' */
      Fv_VehEngFailRate = MACRO_FAIL_VERATEMAX;
    } else {
      /* Transition: '<S201>:190' */
      Fv_VehEngFailRate = MACRO_FAIL_VERATE;

      /* Transition: '<S201>:191' */
    }
  } else {
    /* DataStoreWrite: '<S5>/Data Store Write2' */
    /* Transition: '<S201>:184' */
    Fv_VehEngFailFlag = 0;

    /* Transition: '<S201>:192' */
    /* Transition: '<S201>:191' */
  }

  /* Transition: '<S201>:194' */
  /* Transition: '<S201>:196' */
  /* Transition: '<S201>:198' */
  if (((Fv_ErrDiagStatus[DTC_ANGLEcheck_NoZeroCalib] > FailureDiag_RegOK) ||
       (Fv_ErrDiagStatus[DTC_ANGLEcheck_Invalid] > FailureDiag_RegOK)) ||
      (Fv_ErrDiagStatus[DTC_EEPROMcheck_AngleCheck] > FailureDiag_RegOK)) {
    /* Transition: '<S201>:200' */
    /* Transition: '<S201>:202' */
    Fv_StrAngFailFlag = 1;

    /* Transition: '<S201>:205' */
  } else {
    /* Transition: '<S201>:204' */
    Fv_StrAngFailFlag = 0;
  }

  /* Transition: '<S201>:207' */
  if ((Fv_ErrDiagStatus[DTC_TEMPcheck_Range] > FailureDiag_RegOK) ||
      (Fv_ErrDiagStatus[DTC_TEMPcheck_ADport] > FailureDiag_RegOK)) {
    /* Transition: '<S201>:209' */
    /* Transition: '<S201>:211' */
    Fv_LimitFailFlag = 1;
    Fv_LimitFailRate = MACRO_FAIL_LIMITRATE;

    /* Transition: '<S201>:214' */
  } else {
    /* Transition: '<S201>:213' */
    Fv_LimitFailFlag = 0;
  }

  /* Transition: '<S201>:216' */
  if ((Fv_BatVoltLevel > BAT_VOLT_NORMAL) || (Fv_TempLevel == TEMP_CEL_OVER)) {
    /* Transition: '<S201>:218' */
    /* Transition: '<S201>:220' */
    Fv_LowFailFlag = 1;
    Fv_LowFailRate = MACRO_FAIL_LOWRATE;
  } else {
    /* Transition: '<S201>:222' */
    Fv_LowFailFlag = 0;

    /* Transition: '<S201>:224' */
  }

  /* Transition: '<S201>:226' */
  /* Transition: '<S201>:228' */
  /* Transition: '<S201>:230' */
  if ((((Fv_ErrDiagStatus[DTC_POWERcheck_VBATdt] > FailureDiag_RegOK)) ||
       (tmp_1 == FailureDiag_InitErr)) ||
      (Fv_ErrDiagStatus[DTC_EEPROMcheck_CalibCheck] > FailureDiag_RegOK)) {
    /* Transition: '<S201>:232' */
    /* Transition: '<S201>:234' */
    FaultDiagRapidrtDW.Fv_HighFailFlag1_g4ct = 1;
    Fv_HighFailRate1 = MACRO_FAIL_HIGH1RATE;
    FaultDiagRapidrtDW.Fv_HighFailFlag2_n4cj = 1;
    Fv_HighFailRate2 = MACRO_FAIL_HIGH1RATE;
    /* Transition: '<S201>:237' */
  } else {
    /* Transition: '<S201>:236' */
  }

  /* Transition: '<S201>:239' */
  if ((((((Fv_ErrDiagStatus[DTC_MCUcheck_UnexpReset] == FailureDiag_InitErr)/* ||
         (Fv_ErrDiagStatus[DTC_EEPROMcheck_ConfigCheck] > FailureDiag_RegOK)*/) ||
        ((((Int32)Fv_FaultClass_MCU) & ((Int32)((UInt16)DiagMCUMask))) != 0)) ||
        (((Int32)Fv_FaultClass_Torque) > 0))/* || (((Int32)Fv_FaultClass_Shutdown)
        > 0)*/) || (((((Int32)Fv_FaultClass_Resolver) & ((Int32)DIAGMASK_MODULE1))
                   > 0) || ((((Int32)Fv_FaultClass_Resolver) & ((Int32)
          DIAGMASK_MODULE2)) > 0))) {
    /* Transition: '<S201>:241' */
    /* Transition: '<S201>:243' */
    FaultDiagRapidrtDW.Fv_HighFailFlag1_g4ct = 1;
    Fv_HighFailRate1 = MACRO_FAIL_HIGH3RATE;
    FaultDiagRapidrtDW.Fv_HighFailFlag2_n4cj = 1;
    Fv_HighFailRate2 = MACRO_FAIL_HIGH3RATE;

    /* Transition: '<S201>:287' */
  } else {
    /* Transition: '<S201>:245' */

  }

  /* Transition: '<S201>:289' */
  if (((((Int32)Fv_FaultClass_Current) & ((Int32)DIAGMASK_MODULE1)) > 0) ||
      ((((Int32)Fv_FaultClass_Motor) & ((Int32)DIAGMASK_MODULE1)) > 0)) {
    /* Transition: '<S201>:292' */
    /* Transition: '<S201>:294' */
    /*Start,鍐椾綑绛栫暐寮�鍚�--TXY--240506*/
    // FaultDiagRapidrtDW.Fv_HighFailFlag2_n4cj = 1;
    // Fv_HighFailRate2 = MACRO_FAIL_HIGH3RATE;
    /*End,鍐椾綑绛栫暐寮�鍚�--TXY--240506*/
    FaultDiagRapidrtDW.Fv_HighFailFlag1_g4ct = 1;
    Fv_HighFailRate1 = MACRO_FAIL_HIGH3RATE;

    /* Transition: '<S201>:303' */
  } else {
    /* Transition: '<S201>:296' */
  }

  /* Transition: '<S201>:305' */
  if (((((Int32)Fv_FaultClass_Current) & ((Int32)DIAGMASK_MODULE2)) > 0) ||
      ((((Int32)Fv_FaultClass_Motor) & ((Int32)DIAGMASK_MODULE2)) > 0)) {
    /* Transition: '<S201>:300' */
    /* Transition: '<S201>:302' */
    FaultDiagRapidrtDW.Fv_HighFailFlag2_n4cj = 1;
    Fv_HighFailRate2 = MACRO_FAIL_HIGH3RATE;
    /*Start,鍐椾綑绛栫暐寮�鍚�--TXY--240506*/    
    // FaultDiagRapidrtDW.Fv_HighFailFlag1_g4ct = 1;
    // Fv_HighFailRate1 = MACRO_FAIL_HIGH3RATE;
    /*End,鍐椾綑绛栫暐寮�鍚�--TXY--240506*/

    /* Transition: '<S201>:309' */
  } else {
    /* Transition: '<S201>:308' */
  }

  /* Transition: '<S201>:311' */
  if ((FaultDiagRapidrtDW.Fv_HighFailFlag1_g4ct > 0) &&
      (FaultDiagRapidrtDW.Fv_HighFailFlag2_n4cj > 0)) {
    /* Transition: '<S201>:313' */
    /* Transition: '<S201>:315' */
    FaultDiagRapidrtDW.Fv_HighFailFlag_j3sw = 1;
    Fv_HighFailRate = MACRO_FAIL_HIGH3RATE;

    /* Transition: '<S201>:317' */
  } else {
    /* Transition: '<S201>:316' */
  }

  /* Transition: '<S201>:248' */
  Fv_EPSFailureStatus = (((((((((Int32)((Fv_LightLampFailFlag > 0) ? 1 : 0)) |
    ((Int32)((Fv_StrAngFailFlag > 0) ? 1 : 0))) | ((Int32)((Fv_LimitFailFlag > 0)
    ? 1 : 0))) | ((Int32)((Fv_LowFailFlag > 0) ? 1 : 0))) | ((Int32)
    ((FaultDiagRapidrtDW.Fv_HighFailFlag_j3sw > 0) ? 1 : 0))) | ((Int32)
    ((FaultDiagRapidrtDW.Fv_HighFailFlag1_g4ct > 0) ? 1 : 0))) | ((Int32)
    ((FaultDiagRapidrtDW.Fv_HighFailFlag2_n4cj > 0) ? 1 : 0))) != 0);
    
  SysTaskResolverFailPending1 = ((((Int32)Fv_FaultClass_Resolver) & ((Int32)
    DIAGMASK_MODULE1)) > 0);
  SysTaskResolverFailPending2 = ((((Int32)Fv_FaultClass_Resolver) & ((Int32)
    DIAGMASK_MODULE2)) > 0);

  /* End of Chart: '<S5>/FailStateReview' */

  /* DataStoreWrite: '<S5>/Data Store Write6' */
  Fv_HighFailFlag = FaultDiagRapidrtDW.Fv_HighFailFlag_j3sw;

  Fv_HighFailFlag1 = FaultDiagRapidrtDW.Fv_HighFailFlag1_g4ct;
  /* DataStoreWrite: '<S5>/Data Store Write8' */
  Fv_HighFailFlag2 = FaultDiagRapidrtDW.Fv_HighFailFlag2_n4cj;
}

/* Output and update for referenced model: 'FaultDiagRapid' */
void FaultDiagRapid(void)
{
  /* Chart: '<Root>/DiagRapid_SheduleCounter' */
  /* Gateway: DiagRapid_SheduleCounter */
  /* During: DiagRapid_SheduleCounter */
  /* Entry Internal: DiagRapid_SheduleCounter */
  /* Transition: '<S1>:124' */
  if ((Fv_InitializeFaultDiagnosis) &&
      (!FaultDiagRapidrtDW.bitsForTID0.last_Initdiag)) {
    /* Transition: '<S1>:126' */
    /* Transition: '<S1>:128' */
    FaultDiagRapidrtDW.reset_flag = true;

    /* Transition: '<S1>:131' */
  } else {
    /* Transition: '<S1>:130' */
    FaultDiagRapidrtDW.reset_flag = false;
  }

  /* Transition: '<S1>:133' */
  FaultDiagRapidrtDW.bitsForTID0.last_Initdiag = Fv_InitializeFaultDiagnosis;
  if (Fv_InitializeFaultDiagnosis) {
    /* Outputs for Function Call SubSystem: '<Root>/DiagRapid_Step0Func' */
    /* Outputs for Resettable SubSystem: '<S2>/DiagInit_Step0' */
    /* Transition: '<S1>:102' */
    /* Transition: '<S1>:108' */
    /* Event: '<S1>:109' */
    FaultDiagRapid_DiagInit_Step0();

    /* End of Outputs for SubSystem: '<S2>/DiagInit_Step0' */
    /* End of Outputs for SubSystem: '<Root>/DiagRapid_Step0Func' */
    /* Transition: '<S1>:139' */
  } else {
    /* Transition: '<S1>:104' */
  }

  /* Transition: '<S1>:137' */
  if (!FaultDiagRapidrtDW.bitsForTID0.diaginitflag) {
    /* Transition: '<S1>:10' */
    /* Transition: '<S1>:19' */
    FaultDiagRapidrtDW.bitsForTID0.diaginitflag = true;

    /* Outputs for Function Call SubSystem: '<Root>/DiagRapid_Step1Func' */
    /* Outputs for Resettable SubSystem: '<S3>/DiagRapid_Step1' */
    /* Event: '<S1>:99' */
    FaultDiagRapid_DiagRapid_Step1();

    /* End of Outputs for SubSystem: '<S3>/DiagRapid_Step1' */
    /* End of Outputs for SubSystem: '<Root>/DiagRapid_Step1Func' */
    /* Transition: '<S1>:121' */
  } else {
    /* Transition: '<S1>:96' */
    FaultDiagRapidrtDW.bitsForTID0.diaginitflag = false;

    /* Outputs for Function Call SubSystem: '<Root>/DiagRapid_Step2Func' */
    /* Outputs for Resettable SubSystem: '<S4>/DiagInit_Step2' */
    /* Event: '<S1>:100' */
    FaultDiagRapid_DiagInit_Step2();

    /* End of Outputs for SubSystem: '<S4>/DiagInit_Step2' */
    /* End of Outputs for SubSystem: '<Root>/DiagRapid_Step2Func' */
  }

  /* End of Chart: '<Root>/DiagRapid_SheduleCounter' */

  /* Outputs for Atomic SubSystem: '<Root>/FailStateReview' */
  FaultDiagRapid_FailStateReview();

  /* End of Outputs for SubSystem: '<Root>/FailStateReview' */
}

/* Model initialize function */
void FaultDiagRapid_initialize(void)
{
  FaultDiagRapidrtPrevZCX.MotorInitialCheck_ShortOpen_Res = POS_ZCSIG;
  FaultDiagRapidrtPrevZCX.DiagInit_Step0_Reset_ZCE = POS_ZCSIG;
  FaultDiagRapidrtPrevZCX.DiagRapid_Step1_Reset_ZCE = POS_ZCSIG;
  FaultDiagRapidrtPrevZCX.DiagInit_Step2_Reset_ZCE = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
