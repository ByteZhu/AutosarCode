/*
 * File: BehavourModule.c
 *
 * Code generated for Simulink model 'BehavourModule'.
 *
 * Model version                  : 1.1164
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed Nov 23 12:03:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BehavourModule.h"
#include "BehavourModule_private.h"

/* Named constants for Chart: '<S4>/BYDPowerMode_StateTransition' */
#define BehavourModul_IN_EngineStopMode ((UInt8)1U)
#define BehavourModule_IN_LimitMode    ((UInt8)2U)
#define BehavourModule_IN_NotReadyMode ((UInt8)3U)
#define BehavourModule_IN_OffMode      ((UInt8)4U)
#define BehavourModule_IN_PowerOn      ((UInt8)5U)
#define BehavourModule_IN_ReadyMode    ((UInt8)6U)
#define Behavour_IN_UnknownVehicleState ((UInt8)7U)

/* Named constants for Chart: '<S5>/BehavourModule_PowerModeLogic' */
#define BehavourModule_IN_CRANK        ((UInt8)1U)
#define BehavourModule_IN_OFF          ((UInt8)2U)
#define BehavourModule_IN_ON           ((UInt8)3U)

/* Named constants for Chart: '<S12>/StartStopState_BehavourModule' */
#define BehavourModule_IN_Active       ((UInt8)1U)
#define BehavourModule_IN_CrankDelay   ((UInt8)2U)
#define BehavourModule_IN_InitDelay    ((UInt8)3U)
#define BehavourModule_IN_OFFDelay     ((UInt8)5U)
#define BehavourModule_IN_OFF_atmn     ((UInt8)4U)
#define BehavourModule_IN_ReadyRun     ((UInt8)6U)

/* Named constants for Chart: '<S12>/StartStopState_PowerModeLogic' */
#define BehavourModule_IN_CRANK_debq   ((UInt8)1U)
#define BehavourModule_IN_OFF_ehjn     ((UInt8)2U)
#define BehavourModule_IN_ON_cjtv      ((UInt8)3U)

/* Block states (default storage) */
BehavourModule_DW_fwu4 BehavourModulertDW;

static uint16 BM_limitiedDelay = 200;

#if MACRO_BEHAVEMODULE_SELECT == 0

/* Forward declaration for local functions */
#if MACRO_BEHAVEMODULE_SELECT == 0

static BM_SPDSTATE BehavourModule_bm_spdstatesel(Bool sl, Bool si, Bool run);

#endif
#endif

/* System initialize for atomic system: '<S4>/BYDPowerMode_BMRateLimit' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void B_BYDPowerMode_BMRateLimit_Init(void)
{
  Fv_ModeCoef = 16384;
}

#endif

/* Output and update for atomic system: '<S4>/BYDPowerMode_BMRateLimit' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void Behavo_BYDPowerMode_BMRateLimit(void)
{
  Int32 tmp;

  /* Chart: '<S4>/BYDPowerMode_BMRateLimit' */
  /* Gateway: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_BMRateLimit */
  /* During: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_BMRateLimit */
  /* Entry Internal: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_BMRateLimit */
  /* Transition: '<S6>:2' */
  tmp = ((Int32)BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef) -
    ((Int32)Fv_ModeCoef);
  if (tmp > ((Int32)BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate)) {
    /* Transition: '<S6>:8' */
    /* Transition: '<S6>:14' */
    Fv_ModeCoef = (Int16)(Fv_ModeCoef +
                          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate);

    /* Transition: '<S6>:68' */
    /* Transition: '<S6>:71' */
    /* Transition: '<S6>:72' */
  } else {
    /* Transition: '<S6>:58' */
    if (tmp < (-((Int32)BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate)))
    {
      /* Transition: '<S6>:60' */
      /* Transition: '<S6>:62' */
      Fv_ModeCoef = (Int16)(Fv_ModeCoef -
                            BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate);

      /* Transition: '<S6>:70' */
      /* Transition: '<S6>:72' */
    } else {
      /* Transition: '<S6>:64' */
      Fv_ModeCoef = BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef;

      /* Transition: '<S6>:66' */
    }
  }

  /* End of Chart: '<S4>/BYDPowerMode_BMRateLimit' */
}

#endif

/* System initialize for atomic system: '<S4>/BYDPowerMode_StateTransition' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void BYDPowerMode_StateTransiti_Init(void)
{
  WhichMode = HOLD_OFF;
}

#endif

/* Output and update for atomic system: '<S4>/BYDPowerMode_StateTransition' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void Be_BYDPowerMode_StateTransition(void)
{
  /* Chart: '<S4>/BYDPowerMode_StateTransition' incorporates:
   *  Delay: '<S4>/Delay'
   */
  /* Gateway: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_StateTransition */
  /* During: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_StateTransition */
  if (((UInt32)
       BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_active_c7_BehavourModule)
      == 0U) {
    /* Entry: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_StateTransition */
    BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_active_c7_BehavourModule
      = 1;

    /* Entry Internal: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_StateTransition */
    /* Transition: '<S7>:19' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
      = BehavourModule_IN_PowerOn;

    /* Entry 'PowerOn': '<S7>:50' */
    fsBehaveVsInvalidFlag = 1;
    WhichMode = HOLD_OFF;
    BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
    BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = 0;
    Fv_SystemTransferState = false;
    Fv_SysDownCloseFlag = true;
  } else {
    switch
      (BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule)
    {
     case BehavourModul_IN_EngineStopMode:
      BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
      Fv_SysDownCloseFlag = false;
      /* During 'EngineStopMode': '<S7>:22' */
      if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR02) &&
          (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:29' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_ReadyMode;

        /* Entry 'ReadyMode': '<S7>:20' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 0;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_ActiveRate;
        WhichMode = HOLD_ACTIVE;
      } else if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR04) &&
                 (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:40' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_LimitMode;
        BM_limitiedDelay = 200;
        /* Entry 'LimitMode': '<S7>:23' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 11468;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_ActiveRate;
        WhichMode = HOLD_LIMIT;
      } else if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR05) &&
                 (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:45' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = Behavour_IN_UnknownVehicleState;

        /* Entry 'UnknownVehicleState': '<S7>:24' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.Crank_timer = 0U;
        WhichMode = HOLD_CRANK;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = 0;
      } else {
        if (BehavourModulertDW.BehavourModule_BYDPowerMode.TR03) {
          /* Transition: '<S7>:46' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
            = BehavourModule_IN_OffMode;

          /* Entry 'OffMode': '<S7>:25' */
          WhichMode = HOLD_OFF;
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
            Cal_BM_OffRate;
        }
      }
      break;

     case BehavourModule_IN_LimitMode:
      BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 11468;

      if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR00) &&
          (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:39' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_ReadyMode;

        /* Entry 'ReadyMode': '<S7>:20' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 0;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_ActiveRate;
        WhichMode = HOLD_ACTIVE;
      } else if (BehavourModulertDW.BehavourModule_BYDPowerMode.TR05) {
        /* Transition: '<S7>:44' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = Behavour_IN_UnknownVehicleState;

        /* Entry 'UnknownVehicleState': '<S7>:24' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.Crank_timer = 0U;
        WhichMode = HOLD_CRANK;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = 0;
      } else {
        if (BehavourModulertDW.BehavourModule_BYDPowerMode.TR03) {
          /* Transition: '<S7>:47' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
            = BehavourModule_IN_OffMode;

          /* Entry 'OffMode': '<S7>:25' */
          WhichMode = HOLD_OFF;
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
            Cal_BM_OffRate;
        }
      }
      /* During 'LimitMode': '<S7>:23' */
      break;

     case BehavourModule_IN_NotReadyMode:
      BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;

      /* During 'NotReadyMode': '<S7>:18' */
      if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR08) &&
          (Fv_SystemTransferState)) {
        /* Transition: '<S7>:21' */
        /* Exit 'NotReadyMode': '<S7>:18' */
        Fv_InitializeFaultDiagnosis = false;
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_ReadyMode;

        /* Entry 'ReadyMode': '<S7>:20' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 0;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_ActiveRate;
        WhichMode = HOLD_ACTIVE;
      } else if (!Fv_IGkeyEffect) {
        /* Transition: '<S7>:52' */
        /* Exit 'NotReadyMode': '<S7>:18' */
        Fv_InitializeFaultDiagnosis = false;
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_PowerOn;

        /* Entry 'PowerOn': '<S7>:50' */
        WhichMode = HOLD_OFF;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = 0;
        Fv_SystemTransferState = false;
        Fv_SysDownCloseFlag = true;
      } else {
        Fv_InitializeFaultDiagnosis = true;

        /* Transition: '<S7>:88' */
        if (Fv_SystemTransferState) {
          /* Transition: '<S7>:90' */
          /* Transition: '<S7>:92' */
          WhichMode = HOLD_ATTEMPTINIT;
        } else {
          /* Transition: '<S7>:94' */
          WhichMode = HOLD_INIT;

          /* Transition: '<S7>:95' */
        }
      }
      break;

     case BehavourModule_IN_OffMode:
      BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;

      /* During 'OffMode': '<S7>:25' */
      if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR00) &&
          (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:49' */
        /* Exit 'OffMode': '<S7>:25' */
        Fv_SysDownCloseFlag = false;
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_ReadyMode;

        /* Entry 'ReadyMode': '<S7>:20' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 0;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_ActiveRate;
        WhichMode = HOLD_ACTIVE;
      } else {
        if (BehavourModulertDW.BehavourModule_BYDPowerMode.Delay_DSTATE == 16384)
        {
          /* Transition: '<S7>:83' */
          /* Transition: '<S7>:85' */
          Fv_SysDownCloseFlag = true;
        }
      }
      break;

     case BehavourModule_IN_PowerOn:
      BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;

      /* During 'PowerOn': '<S7>:50' */
      if (Fv_IGkeyEffect) {
        /* Transition: '<S7>:51' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_NotReadyMode;

        /* Entry 'NotReadyMode': '<S7>:18' */
        WhichMode = HOLD_INIT;
        Fv_SysDownCloseFlag = false;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = 0;
        Fv_InitializeFaultDiagnosis = false;
      }
      break;

     case BehavourModule_IN_ReadyMode:
      BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 0;

      /* During 'ReadyMode': '<S7>:20' */
      if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR01) &&
          (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:28' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModul_IN_EngineStopMode;

        /* Entry 'EngineStopMode': '<S7>:22' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_EngineStopRate;
        WhichMode = HOLD_ATTEMPTINIT;
      } else if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR04) &&
                 (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:38' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_LimitMode;
        BM_limitiedDelay = 200;
        /* Entry 'LimitMode': '<S7>:23' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 11468;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_ActiveRate;
        WhichMode = HOLD_LIMIT;
      } else if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR05) &&
                 (Fv_HighFailFlag == 0)) {
        /* Transition: '<S7>:43' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = Behavour_IN_UnknownVehicleState;

        /* Entry 'UnknownVehicleState': '<S7>:24' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.Crank_timer = 0U;
        WhichMode = HOLD_CRANK;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = 0;
      } else {
        if (BehavourModulertDW.BehavourModule_BYDPowerMode.TR03) {
          /* Transition: '<S7>:48' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
            = BehavourModule_IN_OffMode;

          /* Entry 'OffMode': '<S7>:25' */
          WhichMode = HOLD_OFF;
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
            Cal_BM_OffRate;
        }
      }
      break;

     default:
      BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;

      /* During 'UnknownVehicleState': '<S7>:24' */
      if ((BehavourModulertDW.BehavourModule_BYDPowerMode.TR06) ||
          (Fv_HighFailFlag > 0)) {
        /* Transition: '<S7>:53' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_OffMode;

        /* Entry 'OffMode': '<S7>:25' */
        WhichMode = HOLD_OFF;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = Cal_BM_OffRate;
      } else if (BehavourModulertDW.BehavourModule_BYDPowerMode.TR07) {
        /* Transition: '<S7>:42' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c7_BehavourModule
          = BehavourModule_IN_ReadyMode;

        /* Entry 'ReadyMode': '<S7>:20' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Coef = 0;
        BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
          Cal_BM_ActiveRate;
        WhichMode = HOLD_ACTIVE;
      } else {
        /* Transition: '<S7>:61' */
        if (BehavourModulertDW.BehavourModule_BYDPowerMode.Crank_timer >=
            Cal_BM_CrankTimer) {
          /* Transition: '<S7>:63' */
          /* Transition: '<S7>:65' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate =
            Cal_BM_CrankRate;
          BehavourModulertDW.BehavourModule_BYDPowerMode.Crank_timer = 0U;
        } else {
          /* Transition: '<S7>:67' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.Crank_timer = (UInt16)
            ((Int32)(((Int32)
                      BehavourModulertDW.BehavourModule_BYDPowerMode.Crank_timer)
                     + 1));
          BehavourModulertDW.BehavourModule_BYDPowerMode.BM_Rate = 0;

          /* Transition: '<S7>:68' */
        }
      }
      break;
    }
  }
  {
    static UInt16 invalid_cnt = 0;
    UInt8 invalid_flag = 0;
    invalid_flag  = ((fsBehaveVsInvalidFlag == 1)\
                    &&(Fv_SystemCANDiagStatus[CANBUS_ABSVs] >= FailureDiag_Err));
    if(invalid_flag > 0)
    {
      if(invalid_cnt < 1000)
      {
        invalid_cnt++;
      }
      else
      {
        fsBehaveVsInvalidCond = 1;
      }
    }
    else
    {
       invalid_cnt = 0;
       fsBehaveVsInvalidCond = 0;
    }
  }
  /* End of Chart: '<S4>/BYDPowerMode_StateTransition' */
}

#endif

/* Output and update for atomic system: '<S4>/BYDPowerMode_TriggerLogic' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void Behav_BYDPowerMode_TriggerLogic(void)
{
  UInt8 engsts;
  UInt8 vehsts;
  Bool tmp;

  /* Chart: '<S4>/BYDPowerMode_TriggerLogic' incorporates:
   *  Delay: '<S4>/Delay'
   *  Inport: '<Root>/CAN_Es_Err'
   *  Inport: '<Root>/CAN_Vs_Err'
   *  Inport: '<Root>/Fv_EngRun'
   *  Inport: '<Root>/Fv_VehSpd'
   */
  /* Gateway: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_TriggerLogic */
  /* During: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_TriggerLogic */
  /* Entry Internal: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_BYDPowerMode/BYDPowerMode_TriggerLogic */
  /* Transition: '<S8>:35' */
  if ((((Int32)CAN_Es_Err) == 0) && (Fv_EMSVSReciveTimer < ((UInt16)
        MACRO_CAN_LOSTTIME_EMSEs))) {
    /* Transition: '<S8>:41' */
    if (Fv_EngRun) {
      /* Transition: '<S8>:46' */
      /* Transition: '<S8>:48' */
      engsts = 1U;

      /* Transition: '<S8>:49' */
    } else {
      /* Transition: '<S8>:43' */
      engsts = 0U;
    }

    /* Transition: '<S8>:44' */
  } else {
    /* Transition: '<S8>:36' */
    engsts = 2U;
  }

  /* Transition: '<S8>:194' */
  if (Fv_ABSVSReciveTimer < ((UInt16)MACRO_CAN_LOSTTIME_ABSVs)) {
    /* Transition: '<S8>:182' */
    if (((Int32)CAN_Vs_Err) == 0) {
      /* Transition: '<S8>:186' */
      /* Transition: '<S8>:188' */
      vehsts = 0U;

      /* Transition: '<S8>:190' */
    } else {
      /* Transition: '<S8>:189' */
      vehsts = 1U;
    }

    /* Transition: '<S8>:192' */
  } else {
    /* Transition: '<S8>:191' */
    vehsts = 2U;
  }
  //??????????��??????????
  /* Transition: '<S8>:195' */
  if (((Int32)vehsts) != 0) {
    /* Transition: '<S8>:61' */
    if (((Int32)BehavourModulertDW.BehavourModule_BYDPowerMode.vsinvalidcnt) >
        2000) {
      /* Transition: '<S8>:63' */
      /* Transition: '<S8>:68' */
      BehavourModulertDW.BehavourModule_BYDPowerMode.vsinvalidcnt = 2000U;

      /* Transition: '<S8>:69' */
    } else {
      /* Transition: '<S8>:70' */
      BehavourModulertDW.BehavourModule_BYDPowerMode.vsinvalidcnt = (UInt16)
        ((Int32)(((Int32)
                  BehavourModulertDW.BehavourModule_BYDPowerMode.vsinvalidcnt) +
                 1));
    }

    /* Transition: '<S8>:71' */
  } else {
    /* Transition: '<S8>:65' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.vsinvalidcnt = 0U;
  }

  /* Transition: '<S8>:196' */
  if ((Fv_IGkeyEffect) || ((((Int32)vehsts) == 0) && (Fv_VehSpd > ((UInt16)
         MACRO_ASC_VSCONST_3)))) {
    /* Transition: '<S8>:25' */
    /* Transition: '<S8>:27' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR00 = true;

    /* Transition: '<S8>:28' */
  } else {
    /* Transition: '<S8>:20' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR00 = false;
  }

  /* Transition: '<S8>:30' */
  if ((((Fv_IGkeyEffect) && (((Int32)engsts) == 0)) && (((Int32)vehsts) == 0)) &&
      (Fv_VehSpd <= ((UInt16)MACRO_ASC_VSCONST_1))) {
    /* Transition: '<S8>:51' */
    /* Transition: '<S8>:55' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR01 = true;

    /* Transition: '<S8>:56' */
  } else {
    /* Transition: '<S8>:54' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR01 = false;
  }

  /* Transition: '<S8>:74' */
  if ((Fv_IGkeyEffect) && (
    ((((Int32)engsts) != 0) || ((((Int32)vehsts) == 0) && (Fv_VehSpd > ((UInt16)MACRO_ASC_VSCONST_1)))) || 
    (((Int32)BehavourModulertDW.BehavourModule_BYDPowerMode.vsinvalidcnt) >= 2000)
    ))
  {
    /* Transition: '<S8>:75' */
    /* Transition: '<S8>:78' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR02 = true;

    /* Transition: '<S8>:80' */
  } else {
    /* Transition: '<S8>:79' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR02 = false;
  }
  /* Transition: '<S8>:90' */
  tmp = !Fv_IGkeyEffect;
  if ((tmp && (((Int32)engsts) != 1)) && ((((Int32)vehsts) == 0) && (Fv_VehSpd <
        ((UInt16)MACRO_ASC_VSCONST_3)))) {
    /* Transition: '<S8>:88' */
    /* Transition: '<S8>:82' */
      if(BM_limitiedDelay > 0)
      {
        BM_limitiedDelay--;
      }
      else
      {
        BehavourModulertDW.BehavourModule_BYDPowerMode.TR03 = true;
      }
    /* Transition: '<S8>:81' */
  } else {
    /* Transition: '<S8>:83' */
    BM_limitiedDelay = 1000;
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR03 = false;
  }

  /* Transition: '<S8>:100' */
  if ((tmp && (((Int32)engsts) == 1)) && ((((Int32)vehsts) == 0) && (Fv_VehSpd <
        ((UInt16)MACRO_ASC_VSCONST_3)))) {
    /* Transition: '<S8>:95' */
    /* Transition: '<S8>:96' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR04 = true;

    /* Transition: '<S8>:93' */
  } else {
    /* Transition: '<S8>:97' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR04 = false;
  }

  /* Transition: '<S8>:110' */
  if ((tmp && (((Int32)engsts) != 1)) && (((Int32)vehsts) > 0)) {
    /* Transition: '<S8>:103' */
    /* Transition: '<S8>:102' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR05 = true;

    /* Transition: '<S8>:109' */
  } else {
    /* Transition: '<S8>:108' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR05 = false;
  }

  /* Transition: '<S8>:119' */
  if (((tmp && (((Int32)engsts) != 1)) && ((((Int32)vehsts) == 0) && (Fv_VehSpd <
         ((UInt16)MACRO_ASC_VSCONST_3)))) ||
      (BehavourModulertDW.BehavourModule_BYDPowerMode.Delay_DSTATE == 16384)) {
    /* Transition: '<S8>:116' */
    /* Transition: '<S8>:111' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR06 = true;

    /* Transition: '<S8>:114' */
  } else {
    /* Transition: '<S8>:113' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR06 = false;
  }

  /* Transition: '<S8>:128' */
  if ((((Fv_IGkeyEffect) || (((Int32)engsts) == 1)) || ((((Int32)vehsts) == 0) &&
        (Fv_VehSpd > ((UInt16)MACRO_ASC_VSCONST_3)))) &&
      (BehavourModulertDW.BehavourModule_BYDPowerMode.Delay_DSTATE < 16384)) {
    /* Transition: '<S8>:121' */
    /* Transition: '<S8>:127' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR07 = true;

    /* Transition: '<S8>:120' */
  } else {
    /* Transition: '<S8>:126' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR07 = false;
  }

  /* Transition: '<S8>:168' */
  if ((Fv_IGkeyEffect) && (((((Int32)engsts) == 1) || (((((Int32)engsts) == 2) &&
          (((Int32)vehsts) == 0)) && (Fv_VehSpd > ((UInt16)MACRO_ASC_VSCONST_1))))
       || (((Int32)vehsts) == 1)||(fsBehaveVsInvalidCond > 0))) {
    /* Transition: '<S8>:161' */
    /* Transition: '<S8>:165' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR08 = true;

    /* Transition: '<S8>:166' */
  } else {
    /* Transition: '<S8>:164' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.TR08 = false;
  }

  /* End of Chart: '<S4>/BYDPowerMode_TriggerLogic' */
}

#endif

/* System initialize for atomic system: '<S2>/BehavourModule_BYDPowerMode' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void BehavourModule_BYDPowerMod_Init(void)
{
  /* SystemInitialize for Chart: '<S4>/BYDPowerMode_StateTransition' */
  BYDPowerMode_StateTransiti_Init();

  /* SystemInitialize for Chart: '<S4>/BYDPowerMode_BMRateLimit' */
  B_BYDPowerMode_BMRateLimit_Init();
}

#endif

/* Output and update for atomic system: '<S2>/BehavourModule_BYDPowerMode' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void Beh_BehavourModule_BYDPowerMode(void)
{
  /* Chart: '<S4>/BYDPowerMode_TriggerLogic' */
  Behav_BYDPowerMode_TriggerLogic();

  /* Chart: '<S4>/BYDPowerMode_StateTransition' */
  Be_BYDPowerMode_StateTransition();

  /* Chart: '<S4>/BYDPowerMode_BMRateLimit' */
  Behavo_BYDPowerMode_BMRateLimit();

  /* DataStoreWrite: '<S4>/Data Store Write' */
  Fv_WhichMode = WhichMode;

  /* Update for Delay: '<S4>/Delay' */
  BehavourModulertDW.BehavourModule_BYDPowerMode.Delay_DSTATE = Fv_ModeCoef;
}

#endif

/* System initialize for atomic system: '<S5>/BehavourModule_PowerModeLogic' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void BehavourModule_PowerModeLo_Init(void)
{
  PowerMode = POWER_MODE_PMOFF;
}

#endif

/* Output and update for atomic system: '<S5>/BehavourModule_PowerModeLogic' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void B_BehavourModule_PowerModeLogic(void)
{
  /* Chart: '<S5>/BehavourModule_PowerModeLogic' incorporates:
   *  Inport: '<Root>/Fv_EngRun'
   */
  /* Gateway: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_DTCPowerMode/BehavourModule_PowerModeLogic */
  /* During: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_DTCPowerMode/BehavourModule_PowerModeLogic */
  if (((UInt32)
       BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_active_c8_BehavourModule)
      == 0U) {
    /* Entry: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_DTCPowerMode/BehavourModule_PowerModeLogic */
    BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_active_c8_BehavourModule
      = 1;

    /* Entry Internal: BehavourModule/BehavourModule_BYDPowerMode/BehavourModule_DTCPowerMode/BehavourModule_PowerModeLogic */
    /* Transition: '<S9>:84' */
    BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule
      = BehavourModule_IN_OFF;

    /* Entry 'OFF': '<S9>:73' */
    PowerMode = POWER_MODE_PMOFF;
    BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer = Cal_BM_PMTimer;
  } else {
    switch
      (BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule)
    {
     case BehavourModule_IN_CRANK:
      PowerMode = POWER_MODE_PMCRANK;

      /* During 'CRANK': '<S9>:79' */
      if ((Fv_IGkeyEffect) && (Fv_EngRun)) {
        /* Transition: '<S9>:87' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule
          = BehavourModule_IN_ON;

        /* Entry 'ON': '<S9>:80' */
        PowerMode = POWER_MODE_PMON;
      } else {
        if (!Fv_IGkeyEffect) {
          /* Transition: '<S9>:85' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule
            = BehavourModule_IN_OFF;

          /* Entry 'OFF': '<S9>:73' */
          PowerMode = POWER_MODE_PMOFF;
          BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer =
            Cal_BM_PMTimer;
        }
      }
      break;

     case BehavourModule_IN_OFF:
      PowerMode = POWER_MODE_PMOFF;

      /* During 'OFF': '<S9>:73' */
      if (((Fv_IGkeyEffect) && ((((Int32)Fv_EngSpd) > 0) && (!Fv_EngRun))) &&
          (((Int32)BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer) == 0))
      {
        /* Transition: '<S9>:83' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule
          = BehavourModule_IN_CRANK;

        /* Entry 'CRANK': '<S9>:79' */
        PowerMode = POWER_MODE_PMCRANK;
      } else if (((Fv_IGkeyEffect) && ((((Int32)Fv_EngSpd) == 0) || (Fv_EngRun)))
                 && (((Int32)
                      BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer) ==
                     0)) {
        /* Transition: '<S9>:86' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule
          = BehavourModule_IN_ON;

        /* Entry 'ON': '<S9>:80' */
        PowerMode = POWER_MODE_PMON;
      } else {
        /* Transition: '<S9>:76' */
        if (((Int32)BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer) > 0)
        {
          /* Transition: '<S9>:78' */
          /* Transition: '<S9>:91' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer = (UInt16)
            ((Int32)(((Int32)
                      BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer) -
                     1));
        } else {
          /* Transition: '<S9>:93' */
          /* Transition: '<S9>:94' */
        }
      }
      break;

     default:
      PowerMode = POWER_MODE_PMON;

      /* During 'ON': '<S9>:80' */
      if ((Fv_IGkeyEffect) && ((((Int32)Fv_EngSpd) > 0) && (!Fv_EngRun))) {
        /* Transition: '<S9>:82' */
        BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule
          = BehavourModule_IN_CRANK;

        /* Entry 'CRANK': '<S9>:79' */
        PowerMode = POWER_MODE_PMCRANK;
      } else {
        if (!Fv_IGkeyEffect) {
          /* Transition: '<S9>:81' */
          BehavourModulertDW.BehavourModule_BYDPowerMode.bitsForTID0.is_c8_BehavourModule
            = BehavourModule_IN_OFF;

          /* Entry 'OFF': '<S9>:73' */
          PowerMode = POWER_MODE_PMOFF;
          BehavourModulertDW.BehavourModule_BYDPowerMode.PM_Timer =
            Cal_BM_PMTimer;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S5>/BehavourModule_PowerModeLogic' */
}

#endif

/* System initialize for atomic system: '<S2>/BehavourModule_DTCPowerMode' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void BehavourModule_DTCPowerMod_Init(void)
{
  /* SystemInitialize for Chart: '<S5>/BehavourModule_PowerModeLogic' */
  BehavourModule_PowerModeLo_Init();
}

#endif

/* Output and update for atomic system: '<S2>/BehavourModule_DTCPowerMode' */
#if MACRO_BEHAVEMODULE_SELECT == 1

void Beh_BehavourModule_DTCPowerMode(void)
{
  /* Chart: '<S5>/BehavourModule_PowerModeLogic' */
  B_BehavourModule_PowerModeLogic();
}

#endif

/* Function for Chart: '<S10>/ONOFFSTATE' */
#if MACRO_BEHAVEMODULE_SELECT == 0
#if MACRO_BEHAVEMODULE_SELECT == 0

static BM_SPDSTATE BehavourModule_bm_spdstatesel(Bool sl, Bool si, Bool run)
{
  BM_SPDSTATE st;

  /* Truth Table Function 'bm_spdstatesel': '<S13>:169' */
  /* Transition: '<S13>:317' */
  /* Condition '#1': '<S13>:319' */
  /*  Speed Lost  */
  /* Condition '#2': '<S13>:321' */
  /*  Speed Invalid  */
  /* Condition '#3': '<S13>:323' */
  /*  Spped Run  */
  if (((!sl) && (!si)) && run) {
    /* Decision 'D1': '<S13>:325' */
    /* Action '3': '<S13>:327' */
    /*  'srun':Speed run  */
    st = BM_SPDSTATE_RUN;
  } else {
    /* Transition: '<S13>:329' */
    if (sl) {
      /* Decision 'D2': '<S13>:331' */
      /* Action '1': '<S13>:333' */
      /*  'lost':Speed lost  */
      st = BM_SPDSTATE_LOST;
    } else {
      /* Transition: '<S13>:335' */
      if (si) {
        /* Decision 'D3': '<S13>:337' */
        /* Action '2': '<S13>:339' */
        /*  'invalid':Speed invalid  */
        st = BM_SPDSTATE_INVALID;
      } else {
        /* Transition: '<S13>:341' */
        /* Decision 'D4': '<S13>:343' */
        /*  Default  */
        /* Action '4': '<S13>:345' */
        /*  'snorun':Speed norun  */
        st = BM_SPDSTATE_NORUN;
      }
    }
  }

  return st;
}

#endif
#endif

/* Output and update for atomic system: '<S3>/BehavourModule_OnOffState' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void Behav_BehavourModule_OnOffState(void)
{
  BM_SPDSTATE vsst;
  BM_SPDSTATE esst;

  /* Chart: '<S10>/ONOFFSTATE' incorporates:
   *  DataStoreRead: '<S10>/Data Store Read4'
   *  SignalConversion: '<S10>/Signal Copy'
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  /* Gateway: BehavourModule/BehavourModule_Default/BehavourModule_OnOffState/ONOFFSTATE */
  /* During: BehavourModule/BehavourModule_Default/BehavourModule_OnOffState/ONOFFSTATE */
  /* Entry Internal: BehavourModule/BehavourModule_Default/BehavourModule_OnOffState/ONOFFSTATE */
  /* Transition: '<S13>:85' */
  vsst = BehavourModule_bm_spdstatesel
    (BehavourModulertDW.BehavourModule_Default.Compare_h2nq,
     BehavourModulertDW.BehavourModule_Default.Compare,
     BehavourModulertDW.BehavourModule_Default.UnitDelay_DSTATE);
  esst = BehavourModule_bm_spdstatesel
    (BehavourModulertDW.BehavourModule_Default.Compare_h23c,
     BehavourModulertDW.BehavourModule_Default.Compare_cc0n,
     BehavourModulertDW.BehavourModule_Default.UnitDelay1_DSTATE);
  if ((((Fv_IGkeyEffect) &&
        (BehavourModulertDW.BehavourModule_Default.bitsForTID0.lastig)) &&
       (BehavourModulertDW.BehavourModule_Default.Compare_h2nq)) &&
      (!BehavourModulertDW.BehavourModule_Default.bitsForTID0.lastvslost)) {
    /* Transition: '<S13>:223' */
    /* Transition: '<S13>:234' */
    BehavourModulertDW.BehavourModule_Default.bitsForTID0.advst = true;

    /* Transition: '<S13>:239' */
    /* Transition: '<S13>:238' */
  } else {
    /* Transition: '<S13>:225' */
    if ((((!Fv_IGkeyEffect) &&
          (BehavourModulertDW.BehavourModule_Default.bitsForTID0.lastig)) &&
         (!BehavourModulertDW.BehavourModule_Default.Compare_h2nq)) &&
        (!BehavourModulertDW.BehavourModule_Default.bitsForTID0.lastvslost)) {
      /* Transition: '<S13>:227' */
      /* Transition: '<S13>:229' */
      BehavourModulertDW.BehavourModule_Default.bitsForTID0.advst = false;

      /* Transition: '<S13>:238' */
    } else {
      /* Transition: '<S13>:231' */
    }
  }

  /* Transition: '<S13>:240' */
  BehavourModulertDW.BehavourModule_Default.bitsForTID0.lastig = Fv_IGkeyEffect;
  BehavourModulertDW.BehavourModule_Default.bitsForTID0.lastvslost =
    BehavourModulertDW.BehavourModule_Default.Compare_h2nq;
  if (Fv_IGkeyEffect) {
    /* Transition: '<S13>:111' */
    switch (vsst) {
     case BM_SPDSTATE_RUN:
      /* SignalConversion: '<S10>/Signal Copy2' */
      /* Transition: '<S13>:208' */
      /* Transition: '<S13>:209' */
      Fv_BM_OffStatus = ASSIST_MODE_NORMALRUN;
      break;

     case BM_SPDSTATE_NORUN:
      /* Transition: '<S13>:113' */
      /* Transition: '<S13>:115' */
      switch (esst) {
       case BM_SPDSTATE_RUN:
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:119' */
        /* Transition: '<S13>:117' */
        Fv_BM_OffStatus = ASSIST_MODE_NORMALRUN;
        break;

       case BM_SPDSTATE_NORUN:
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:121' */
        /* Transition: '<S13>:122' */
        /* Transition: '<S13>:348' */
        Fv_BM_OffStatus = ASSIST_MODE_DELAYSTOPRUN;

        /* Transition: '<S13>:352' */
        break;

       default:
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:350' */
        Fv_BM_OffStatus = ASSIST_MODE_DEFAULTRUN;

        /* Transition: '<S13>:351' */
        /* Transition: '<S13>:352' */
        break;
      }

      /* Transition: '<S13>:159' */
      break;

     default:
      /* SignalConversion: '<S10>/Signal Copy2' */
      /* Transition: '<S13>:124' */
      Fv_BM_OffStatus = ASSIST_MODE_DEFAULTRUN;

      /* Transition: '<S13>:126' */
      /* Transition: '<S13>:351' */
      /* Transition: '<S13>:352' */
      break;
    }

    /* Transition: '<S13>:254' */
  } else {
    /* Transition: '<S13>:128' */
    switch (vsst) {
     case BM_SPDSTATE_RUN:
      /* SignalConversion: '<S10>/Signal Copy2' */
      /* Transition: '<S13>:215' */
      /* Transition: '<S13>:217' */
      Fv_BM_OffStatus = ASSIST_MODE_NORMALRUN;

      /* Transition: '<S13>:219' */
      break;

     case BM_SPDSTATE_NORUN:
      /* Transition: '<S13>:211' */
      /* Transition: '<S13>:130' */
      if (esst == BM_SPDSTATE_RUN) {
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:132' */
        /* Transition: '<S13>:134' */
        Fv_BM_OffStatus = ASSIST_MODE_NORMALRUN;
      } else {
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:136' */
        Fv_BM_OffStatus = ASSIST_MODE_STOPRUN;

        /* Transition: '<S13>:137' */
      }

      /* Transition: '<S13>:161' */
      /* Transition: '<S13>:256' */
      break;

     case BM_SPDSTATE_INVALID:
      /* Transition: '<S13>:139' */
      /* Transition: '<S13>:141' */
      if (esst == BM_SPDSTATE_RUN) {
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:143' */
        /* Transition: '<S13>:145' */
        Fv_BM_OffStatus = ASSIST_MODE_DEFAULTRUN;
      } else {
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:147' */
        Fv_BM_OffStatus = ASSIST_MODE_DELAYSTOPRUN;

        /* Transition: '<S13>:148' */
      }

      /* Transition: '<S13>:163' */
      /* Transition: '<S13>:257' */
      break;

     default:
      /* Transition: '<S13>:150' */
      if ((esst == BM_SPDSTATE_RUN) || (esst == BM_SPDSTATE_INVALID)) {
        /* SignalConversion: '<S10>/Signal Copy2' */
        /* Transition: '<S13>:152' */
        /* Transition: '<S13>:154' */
        Fv_BM_OffStatus = ASSIST_MODE_DEFAULTRUN;

        /* Transition: '<S13>:165' */
      } else {
        /* Transition: '<S13>:156' */
        if (BehavourModulertDW.BehavourModule_Default.bitsForTID0.advst) {
          /* SignalConversion: '<S10>/Signal Copy2' */
          /* Transition: '<S13>:157' */
          /* Transition: '<S13>:246' */
          Fv_BM_OffStatus = ASSIST_MODE_DELAYSTOPRUN;
        } else {
          /* SignalConversion: '<S10>/Signal Copy2' */
          /* Transition: '<S13>:248' */
          Fv_BM_OffStatus = ASSIST_MODE_STOPRUN;

          /* Transition: '<S13>:249' */
        }

        /* Transition: '<S13>:251' */
        /* Transition: '<S13>:259' */
      }

      /* Transition: '<S13>:258' */
      break;
    }

    /* Transition: '<S13>:255' */
  }

  /* Transition: '<S13>:261' */
  /* Transition: '<S13>:263' */
  if (Fv_IGkeyEffect) {
    /* Transition: '<S13>:265' */
    switch (vsst) {
     case BM_SPDSTATE_RUN:
      /* SignalConversion: '<S10>/Signal Copy1' */
      /* Transition: '<S13>:267' */
      /* Transition: '<S13>:269' */
      Fv_BM_OnStatus = ASSIST_MODE_START;

      /* Transition: '<S13>:294' */
      /* Transition: '<S13>:303' */
      break;

     case BM_SPDSTATE_NORUN:
      /* Transition: '<S13>:271' */
      /* Transition: '<S13>:273' */
      if (esst == BM_SPDSTATE_RUN) {
        /* SignalConversion: '<S10>/Signal Copy1' */
        /* Transition: '<S13>:275' */
        /* Transition: '<S13>:277' */
        Fv_BM_OnStatus = ASSIST_MODE_START;
      } else {
        /* SignalConversion: '<S10>/Signal Copy1' */
        /* Transition: '<S13>:279' */
        Fv_BM_OnStatus = ASSIST_MODE_NOSTART;

        /* Transition: '<S13>:280' */
      }

      /* Transition: '<S13>:281' */
      /* Transition: '<S13>:294' */
      /* Transition: '<S13>:303' */
      break;

     default:
      /* Transition: '<S13>:283' */
      /* Transition: '<S13>:307' */
      switch (esst) {
       case BM_SPDSTATE_RUN:
        /* SignalConversion: '<S10>/Signal Copy1' */
        /* Transition: '<S13>:287' */
        /* Transition: '<S13>:289' */
        Fv_BM_OnStatus = ASSIST_MODE_DEFAULTSTART;

        /* Transition: '<S13>:293' */
        /* Transition: '<S13>:303' */
        break;

       case BM_SPDSTATE_NORUN:
        /* SignalConversion: '<S10>/Signal Copy1' */
        /* Transition: '<S13>:291' */
        /* Transition: '<S13>:296' */
        /* Transition: '<S13>:298' */
        Fv_BM_OnStatus = ASSIST_MODE_DEFAULTSTART;//ASSIST_MODE_NOSTART;

        /* Transition: '<S13>:304' */
        break;

       default:
        /* SignalConversion: '<S10>/Signal Copy1' */
        /* Transition: '<S13>:300' */
        Fv_BM_OnStatus = ASSIST_MODE_DELAYSTART;

        /* Transition: '<S13>:301' */
        break;
      }
      break;
    }

    /* Transition: '<S13>:312' */
  } else {
    /* SignalConversion: '<S10>/Signal Copy1' */
    /* Transition: '<S13>:309' */
    Fv_BM_OnStatus = ASSIST_MODE_NOSTART;

    /* Transition: '<S13>:311' */
  }

  /* End of Chart: '<S10>/ONOFFSTATE' */
}

#endif

/* Output and update for atomic system: '<S3>/BehavourModule_RunInvalidLost' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void B_BehavourModule_RunInvalidLost(void)
{
  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   *  Inport: '<Root>/CAN_Vs_Err'
   */
  BehavourModulertDW.BehavourModule_Default.Compare = (CAN_Vs_Err > ((UInt8)0U));

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   *  DataStoreRead: '<S11>/Data Store Read2'
   */
  BehavourModulertDW.BehavourModule_Default.Compare_h2nq = (Fv_ABSVSReciveTimer >
    ((UInt16)MACRO_CAN_LOSTTIME_ABSVs));

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Inport: '<Root>/Fv_VehSpd'
   *  Logic: '<S11>/Logical Operator1'
   *  RelationalOperator: '<S14>/Compare'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  if ((!BehavourModulertDW.BehavourModule_Default.Compare_h2nq) &&
      (!BehavourModulertDW.BehavourModule_Default.Compare)) {
    BehavourModulertDW.BehavourModule_Default.UnitDelay_DSTATE = (Fv_VehSpd >
      ((UInt16)MACRO_ASC_VSCONST_7));
  }

  /* End of Switch: '<S11>/Switch' */

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  Inport: '<Root>/CAN_Es_Err'
   */
  BehavourModulertDW.BehavourModule_Default.Compare_cc0n = (CAN_Es_Err > ((UInt8)
    0U));

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataStoreRead: '<S11>/Data Store Read3'
   */
  BehavourModulertDW.BehavourModule_Default.Compare_h23c = (Fv_EMSVSReciveTimer >
    ((UInt16)MACRO_CAN_LOSTTIME_EMSEs));

  /* Switch: '<S11>/Switch1' incorporates:
   *  DataStoreRead: '<S11>/Data Store Read1'
   *  Inport: '<Root>/Fv_EngRun'
   *  Logic: '<S11>/Logical Operator2'
   *  Logic: '<S11>/Logical Operator3'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  if ((!BehavourModulertDW.BehavourModule_Default.Compare_h23c) &&
      (!BehavourModulertDW.BehavourModule_Default.Compare_cc0n)) {
    BehavourModulertDW.BehavourModule_Default.UnitDelay1_DSTATE = ((Fv_EngRun) ||
      (Fv_EngStartStop));
  }

  /* End of Switch: '<S11>/Switch1' */
}

#endif

/* System initialize for atomic system: '<S12>/StartStopState_BMRateLimit' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void StartStopState_BMRateLimit_Init(void)
{
  Fv_ModeCoef = 16384;
}

#endif

/* Output and update for atomic system: '<S12>/StartStopState_BMRateLimit' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void Beha_StartStopState_BMRateLimit(void)
{
  Int32 tmp;

  /* Chart: '<S12>/StartStopState_BMRateLimit' */
  /* Gateway: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BMRateLimit */
  /* During: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BMRateLimit */
  /* Entry Internal: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BMRateLimit */
  /* Transition: '<S19>:2' */
  tmp = ((Int32)BehavourModulertDW.BehavourModule_Default.BM_Coef) - ((Int32)
    Fv_ModeCoef);
  if (tmp > ((Int32)BehavourModulertDW.BehavourModule_Default.BM_Rate)) {
    /* Transition: '<S19>:8' */
    /* Transition: '<S19>:14' */
    Fv_ModeCoef = (Int16)(Fv_ModeCoef +
                          BehavourModulertDW.BehavourModule_Default.BM_Rate);

    /* Transition: '<S19>:68' */
    /* Transition: '<S19>:71' */
    /* Transition: '<S19>:72' */
  } else {
    /* Transition: '<S19>:58' */
    if (tmp < (-((Int32)BehavourModulertDW.BehavourModule_Default.BM_Rate))) {
      /* Transition: '<S19>:60' */
      /* Transition: '<S19>:62' */
      Fv_ModeCoef = (Int16)(Fv_ModeCoef -
                            BehavourModulertDW.BehavourModule_Default.BM_Rate);

      /* Transition: '<S19>:70' */
      /* Transition: '<S19>:72' */
    } else {
      /* Transition: '<S19>:64' */
      Fv_ModeCoef = BehavourModulertDW.BehavourModule_Default.BM_Coef;

      /* Transition: '<S19>:66' */
    }
  }

  /* End of Chart: '<S12>/StartStopState_BMRateLimit' */
}
#if 0
void BHM_Behavour_Mod_IG5MinRule(void)
{
  static boolean busoff_flag = 0;
  static boolean trq5min_flag = 0;
  static uint16 ig5min_cnt = 0;
  static boolean ig5min_flag = 0;

  (void)Dem_GetEventFailed(5,&busoff_flag);
  //(void)Rte_Read_FV_TAS_TRQ_FVbl_TAS_Rule5Min(&trq5min_flag);
  trq5min_flag = Rte_Rx_000508;

  if((Fv_IGkeyOffFlag == true) && (busoff_flag == true) && (Fv_dStrTrq < Cal_Rule5Min_Trq))
  {
    if(ig5min_cnt < Cal_Rule5Min_Timer)
    {
      ig5min_cnt++;
    }
    else
    {
      Fv_IG5MinRule_Flag = true;
    }
  }
  else
  {
    Fv_IG5MinRule_Flag = false;
    ig5min_cnt = 0;
  }
}//add by liuyang at 241121 for 5min rule
#endif
//todo by liuyang at 241121 for 5min rule
#endif

/* System initialize for atomic system: '<S12>/StartStopState_BehavourModule' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void StartStopState_BehavourMod_Init(void)
{
  WhichMode = HOLD_OFF;
}

#endif

/* Output and update for atomic system: '<S12>/StartStopState_BehavourModule' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void B_StartStopState_BehavourModule(void)
{
  /* Chart: '<S12>/StartStopState_BehavourModule' incorporates:
   *  Delay: '<S12>/Delay'
   */
  /* Gateway: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BehavourModule */
  /* During: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BehavourModule */
  if (((UInt32)
       BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_active_c5_BehavourModule)
      == 0U) {
    /* Entry: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BehavourModule */
    BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_active_c5_BehavourModule
      = 1;

    /* Entry Internal: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_BehavourModule */
    /* Transition: '<S20>:13' */
    BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule =
      BehavourModule_IN_OFF_atmn;

    /* Entry 'OFF': '<S20>:1' */
    WhichMode = HOLD_OFF;
    BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
    BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;
    Fv_SystemTransferState = false;
  } else {
    switch
      (BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule)
    {
     case BehavourModule_IN_Active:
      WhichMode = HOLD_ACTIVE;

      /* During 'Active': '<S20>:6' */
      if ((!Fv_IGkeyEffect) && (Fv_BM_OffStatus == ASSIST_MODE_STOPRUN)) {
        /* Transition: '<S20>:261' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_OFFDelay;

        /* Entry 'OFFDelay': '<S20>:4' */
        WhichMode = HOLD_OFFDELAY;
        BehavourModulertDW.BehavourModule_Default.Off_timer = 0U;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
      } else if ((Fv_HighFailFlag == 0) && (Fv_BM_OffStatus ==
                  ASSIST_MODE_DELAYSTOPRUN)) {
        /* Transition: '<S20>:25' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_CrankDelay;

        /* Entry 'CrankDelay': '<S20>:2' */
        BehavourModulertDW.BehavourModule_Default.Crank_timer = 0U;
        WhichMode = HOLD_CRANK;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
      } else {
        /* Transition: '<S20>:672' */
        if ((!Fv_EmsInvalidFlag) && (Fv_EngStartStop)) {
          /* Transition: '<S20>:674' */
          /* Transition: '<S20>:676' */
          BehavourModulertDW.BehavourModule_Default.BM_Coef =
            Cal_BMCoef_EMSSsmStatus;

          /* Transition: '<S20>:695' */
        } else {
          /* Transition: '<S20>:678' */
          BehavourModulertDW.BehavourModule_Default.BM_Coef = 0;
        }

        /* Transition: '<S20>:696' */
        if (BehavourModulertDW.BehavourModule_Default.Active_timer <
            Cal_BM_ActiveTimer) {
          /* Transition: '<S20>:298' */
          /* Transition: '<S20>:299' */
          BehavourModulertDW.BehavourModule_Default.BM_Rate = Cal_BM_ActiveRate;
          BehavourModulertDW.BehavourModule_Default.Active_timer = (UInt16)
            ((Int32)(((Int32)
                      BehavourModulertDW.BehavourModule_Default.Active_timer) +
                     1));

          /* Transition: '<S20>:698' */
        } else {
          /* Transition: '<S20>:297' */
          BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;
        }

        /* Transition: '<S20>:699' */
        if (BehavourModulertDW.BehavourModule_Default.Delay_DSTATE !=
            BehavourModulertDW.BehavourModule_Default.BM_Coef) {
          /* Transition: '<S20>:681' */
          /* Transition: '<S20>:684' */
          BehavourModulertDW.BehavourModule_Default.Active_timer = 0U;

          /* Transition: '<S20>:700' */
        } else {
          /* Transition: '<S20>:686' */
          BehavourModulertDW.BehavourModule_Default.Active_timer =
            Cal_BM_ActiveTimer;
        }
      }
      break;

     case BehavourModule_IN_CrankDelay:
      WhichMode = HOLD_CRANK;

      /* During 'CrankDelay': '<S20>:2' */
      if ((!Fv_IGkeyEffect) && (Fv_BM_OffStatus == ASSIST_MODE_STOPRUN)) {
        /* Transition: '<S20>:21' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_OFFDelay;

        /* Entry 'OFFDelay': '<S20>:4' */
        WhichMode = HOLD_OFFDELAY;
        BehavourModulertDW.BehavourModule_Default.Off_timer = 0U;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
      } else if ((Fv_HighFailFlag == 0) && ((Fv_BM_OffStatus ==
                   ASSIST_MODE_NORMALRUN) || (Fv_BM_OffStatus ==
                   ASSIST_MODE_DEFAULTRUN))) {
        /* Transition: '<S20>:29' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_Active;

        /* Entry 'Active': '<S20>:6' */
        BehavourModulertDW.BehavourModule_Default.Active_timer = 0U;
        WhichMode = HOLD_ACTIVE;
      } else if (BehavourModulertDW.BehavourModule_Default.Crank_timer >=
                 (Cal_BM_CrankTimer + Cal_BM_CrankTimerPre)) {
        /* Transition: '<S20>:20' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_InitDelay;

        /* Entry 'InitDelay': '<S20>:12' */
        WhichMode = HOLD_INIT;
        Fv_SysDownCloseFlag = false;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;
        Fv_InitializeFaultDiagnosis = false;
      } else {
        /* Transition: '<S20>:41' */
        BehavourModulertDW.BehavourModule_Default.Crank_timer = (UInt16)((Int32)
          (((Int32)BehavourModulertDW.BehavourModule_Default.Crank_timer) + 1));
        if (BehavourModulertDW.BehavourModule_Default.Crank_timer <=
            Cal_BM_CrankTimerPre) {
          /* Transition: '<S20>:49' */
          /* Transition: '<S20>:51' */
          BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;

          /* Transition: '<S20>:47' */
        } else {
          /* Transition: '<S20>:53' */
          BehavourModulertDW.BehavourModule_Default.BM_Rate = Cal_BM_CrankRate;
        }
      }
      break;

     case BehavourModule_IN_InitDelay:
      WhichMode = HOLD_INIT;

      /* During 'InitDelay': '<S20>:12' */
      if ((Fv_IGkeyEffect) && (Fv_SystemTransferState)) {
        /* Transition: '<S20>:17' */
        /* Exit 'InitDelay': '<S20>:12' */
        /* InitializeFaultDiagnosis(); */
        Fv_InitializeFaultDiagnosis = false;
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_ReadyRun;

        /* Entry 'ReadyRun': '<S20>:5' */
        WhichMode = HOLD_ATTEMPTINIT;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_Default.BM_Rate = Cal_BM_OffRate;
        BehavourModulertDW.BehavourModule_Default.ASreadyTimer = 0U;
        BehavourModulertDW.BehavourModule_Default.readystate = 0U;
      } else if (!Fv_IGkeyEffect) {
        /* Transition: '<S20>:15' */
        Fv_SysDownCloseFlag = true;

        /* Exit 'InitDelay': '<S20>:12' */
        /* InitializeFaultDiagnosis(); */
        Fv_InitializeFaultDiagnosis = false;
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_OFF_atmn;

        /* Entry 'OFF': '<S20>:1' */
        WhichMode = HOLD_OFF;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;
        Fv_SystemTransferState = false;
      } else {
        Fv_InitializeFaultDiagnosis = true;
      }
      break;

     case BehavourModule_IN_OFF_atmn:
      WhichMode = HOLD_OFF;

      /* During 'OFF': '<S20>:1' */
      if (Fv_IGkeyEffect) {
        /* Transition: '<S20>:14' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_InitDelay;

        /* Entry 'InitDelay': '<S20>:12' */
        WhichMode = HOLD_INIT;
        Fv_SysDownCloseFlag = false;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;
        Fv_InitializeFaultDiagnosis = false;
      }
      break;

     case BehavourModule_IN_OFFDelay:
      WhichMode = HOLD_OFFDELAY;

      /* During 'OFFDelay': '<S20>:4' */
      if (Fv_IGkeyEffect) {
        /* Transition: '<S20>:58' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_InitDelay;

        /* Entry 'InitDelay': '<S20>:12' */
        WhichMode = HOLD_INIT;
        Fv_SysDownCloseFlag = false;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;
        Fv_InitializeFaultDiagnosis = false;
      } else if (BehavourModulertDW.BehavourModule_Default.Off_timer >=
                 (Cal_BM_OffTimer + Cal_BM_OffTimerPre)) {
        /* Transition: '<S20>:19' */
        Fv_SysDownCloseFlag = true;
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_OFF_atmn;

        /* Entry 'OFF': '<S20>:1' */
        WhichMode = HOLD_OFF;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
        BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;
        Fv_SystemTransferState = false;
      } else {
        /* Transition: '<S20>:39' */
        BehavourModulertDW.BehavourModule_Default.Off_timer = (UInt16)((Int32)
          (((Int32)BehavourModulertDW.BehavourModule_Default.Off_timer) + 1));
        if (((Int32)BehavourModulertDW.BehavourModule_Default.Off_timer) <=
            (((Int32)Cal_BM_OffTimerPre) + 1)) {
          /* Transition: '<S20>:37' */
          /* Transition: '<S20>:35' */
          BehavourModulertDW.BehavourModule_Default.BM_Rate = 0;

          /* Transition: '<S20>:33' */
        } else {
          /* Transition: '<S20>:34' */
          BehavourModulertDW.BehavourModule_Default.BM_Rate = Cal_BM_OffRate;
        }
      }
      break;

     default:
      WhichMode = HOLD_ATTEMPTINIT;

      /* During 'ReadyRun': '<S20>:5' */
      if (((Fv_HighFailFlag == 0) && (Fv_IGkeyEffect)) && (((Int32)
            BehavourModulertDW.BehavourModule_Default.readystate) > 0)) {
        /* Transition: '<S20>:28' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_Active;

        /* Entry 'Active': '<S20>:6' */
        BehavourModulertDW.BehavourModule_Default.Active_timer = 0U;
        WhichMode = HOLD_ACTIVE;
      } else if (!Fv_IGkeyEffect) {
        /* Transition: '<S20>:22' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c5_BehavourModule
          = BehavourModule_IN_OFFDelay;

        /* Entry 'OFFDelay': '<S20>:4' */
        WhichMode = HOLD_OFFDELAY;
        BehavourModulertDW.BehavourModule_Default.Off_timer = 0U;
        BehavourModulertDW.BehavourModule_Default.BM_Coef = 16384;
      } else {
        /* Transition: '<S20>:199' */
        if ((Fv_BM_OnStatus == ASSIST_MODE_START) || (Fv_BM_OnStatus ==
             ASSIST_MODE_DEFAULTSTART)) {
          /* Transition: '<S20>:212' */
          /* Transition: '<S20>:214' */
          BehavourModulertDW.BehavourModule_Default.readystate = 1U;
        } else {
          /* Transition: '<S20>:222' */
          if (Fv_BM_OnStatus == ASSIST_MODE_DELAYSTART) {
            /* Transition: '<S20>:201' */
            if (BehavourModulertDW.BehavourModule_Default.ASreadyTimer <
                Cal_BM_ReadyTimer) {
              /* Transition: '<S20>:203' */
              /* Transition: '<S20>:205' */
              BehavourModulertDW.BehavourModule_Default.ASreadyTimer = (UInt16)
                ((Int32)(((Int32)
                          BehavourModulertDW.BehavourModule_Default.ASreadyTimer)
                         + 1));
            } else {
              /* Transition: '<S20>:207' */
              BehavourModulertDW.BehavourModule_Default.readystate = 2U;

              /* Transition: '<S20>:208' */
            }
          } else {
            /* Transition: '<S20>:224' */
            /* Transition: '<S20>:226' */
            /* Transition: '<S20>:208' */
          }

          /* Transition: '<S20>:229' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S12>/StartStopState_BehavourModule' */
}

#endif

/* System initialize for atomic system: '<S12>/StartStopState_PowerModeLogic' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void StartStopState_PowerModeLo_Init(void)
{
  PowerMode = POWER_MODE_PMOFF;
}

#endif

/* Output and update for atomic system: '<S12>/StartStopState_PowerModeLogic' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void B_StartStopState_PowerModeLogic(void)
{
  /* Chart: '<S12>/StartStopState_PowerModeLogic' incorporates:
   *  Inport: '<Root>/Fv_EngRun'
   */
  /* Gateway: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_PowerModeLogic */
  /* During: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_PowerModeLogic */
  if (((UInt32)
       BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_active_c2_BehavourModule)
      == 0U) {
    /* Entry: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_PowerModeLogic */
    BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_active_c2_BehavourModule
      = 1;

    /* Entry Internal: BehavourModule/BehavourModule_Default/BehavourModule_StartStopState/StartStopState_PowerModeLogic */
    /* Transition: '<S21>:84' */
    BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule =
      BehavourModule_IN_OFF_ehjn;

    /* Entry 'OFF': '<S21>:73' */
    PowerMode = POWER_MODE_PMOFF;
    BehavourModulertDW.BehavourModule_Default.PM_Timer = Cal_BM_PMTimer;
  } else {
    switch
      (BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule)
    {
     case BehavourModule_IN_CRANK_debq:
      PowerMode = POWER_MODE_PMCRANK;

      /* During 'CRANK': '<S21>:79' */
      if ((Fv_IGkeyEffect) && (Fv_EngRun)) {
        /* Transition: '<S21>:87' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule
          = BehavourModule_IN_ON_cjtv;

        /* Entry 'ON': '<S21>:80' */
        PowerMode = POWER_MODE_PMON;
      } else {
        if (!Fv_IGkeyEffect) {
          /* Transition: '<S21>:85' */
          BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule
            = BehavourModule_IN_OFF_ehjn;

          /* Entry 'OFF': '<S21>:73' */
          PowerMode = POWER_MODE_PMOFF;
          BehavourModulertDW.BehavourModule_Default.PM_Timer = Cal_BM_PMTimer;
        }
      }
      break;

     case BehavourModule_IN_OFF_ehjn:
      PowerMode = POWER_MODE_PMOFF;

      /* During 'OFF': '<S21>:73' */
      if (((Fv_IGkeyEffect) && ((((Int32)Fv_EngSpd) > 0) && (!Fv_EngRun))) &&
          (((Int32)BehavourModulertDW.BehavourModule_Default.PM_Timer) == 0)) {
        /* Transition: '<S21>:83' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule
          = BehavourModule_IN_CRANK_debq;

        /* Entry 'CRANK': '<S21>:79' */
        PowerMode = POWER_MODE_PMCRANK;
      } else if (((Fv_IGkeyEffect) && ((((Int32)Fv_EngSpd) == 0) || (Fv_EngRun)))
                 && (((Int32)BehavourModulertDW.BehavourModule_Default.PM_Timer)
                     == 0)) {
        /* Transition: '<S21>:86' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule
          = BehavourModule_IN_ON_cjtv;

        /* Entry 'ON': '<S21>:80' */
        PowerMode = POWER_MODE_PMON;
      } else {
        /* Transition: '<S21>:76' */
        if (((Int32)BehavourModulertDW.BehavourModule_Default.PM_Timer) > 0) {
          /* Transition: '<S21>:78' */
          /* Transition: '<S21>:91' */
          BehavourModulertDW.BehavourModule_Default.PM_Timer = (UInt16)((Int32)
            (((Int32)BehavourModulertDW.BehavourModule_Default.PM_Timer) - 1));
        } else {
          /* Transition: '<S21>:93' */
          /* Transition: '<S21>:94' */
        }
      }
      break;

     default:
      PowerMode = POWER_MODE_PMON;

      /* During 'ON': '<S21>:80' */
      if ((Fv_IGkeyEffect) && ((((Int32)Fv_EngSpd) > 0) && (!Fv_EngRun))) {
        /* Transition: '<S21>:82' */
        BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule
          = BehavourModule_IN_CRANK_debq;

        /* Entry 'CRANK': '<S21>:79' */
        PowerMode = POWER_MODE_PMCRANK;
      } else {
        if (!Fv_IGkeyEffect) {
          /* Transition: '<S21>:81' */
          BehavourModulertDW.BehavourModule_Default.bitsForTID0.is_c2_BehavourModule
            = BehavourModule_IN_OFF_ehjn;

          /* Entry 'OFF': '<S21>:73' */
          PowerMode = POWER_MODE_PMOFF;
          BehavourModulertDW.BehavourModule_Default.PM_Timer = Cal_BM_PMTimer;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S12>/StartStopState_PowerModeLogic' */
}

#endif

/* System initialize for atomic system: '<S3>/BehavourModule_StartStopState' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void BehavourModule_StartStopSt_Init(void)
{
  /* SystemInitialize for Chart: '<S12>/StartStopState_BehavourModule' */
  StartStopState_BehavourMod_Init();

  /* SystemInitialize for Chart: '<S12>/StartStopState_BMRateLimit' */
  StartStopState_BMRateLimit_Init();

  /* SystemInitialize for Chart: '<S12>/StartStopState_PowerModeLogic' */
  StartStopState_PowerModeLo_Init();
}

#endif

/* Output and update for atomic system: '<S3>/BehavourModule_StartStopState' */
#if MACRO_BEHAVEMODULE_SELECT == 0

void B_BehavourModule_StartStopState(void)
{
  /* Chart: '<S12>/StartStopState_BehavourModule' */
  B_StartStopState_BehavourModule();

  /* Chart: '<S12>/StartStopState_BMRateLimit' */
  Beha_StartStopState_BMRateLimit();

  /* Chart: '<S12>/StartStopState_PowerModeLogic' */
  B_StartStopState_PowerModeLogic();

  /* DataStoreWrite: '<S12>/Data Store Write' */
  Fv_WhichMode = WhichMode;

  /* Update for Delay: '<S12>/Delay' */
  BehavourModulertDW.BehavourModule_Default.Delay_DSTATE = Fv_ModeCoef;
}

#endif

/* System initialize for referenced model: 'BehavourModule' */
void BehavourModule_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/BehavourModule' */
#if MACRO_BEHAVEMODULE_SELECT == 1

  /* System initialize for atomic system: '<S1>/BehavourModule_BYDPowerMode' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/BehavourModule_BYDPowerMode' */
  BehavourModule_BYDPowerMod_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/BehavourModule_BYDPowerMode' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/BehavourModule_DTCPowerMode' */
  BehavourModule_DTCPowerMod_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/BehavourModule_DTCPowerMode' */
#elif MACRO_BEHAVEMODULE_SELECT == 0

  /* System initialize for atomic system: '<S1>/BehavourModule_Default' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/BehavourModule_StartStopState' */
  BehavourModule_StartStopSt_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/BehavourModule_StartStopState' */
#endif

  /* End of SystemInitialize for SubSystem: '<Root>/BehavourModule' */
}

/* Output and update for referenced model: 'BehavourModule' */
void BehavourModule(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/BehavourModule' */
#if MACRO_BEHAVEMODULE_SELECT == 1

  /* Output and update for atomic system: '<S1>/BehavourModule_BYDPowerMode' */

  /* Outputs for Atomic SubSystem: '<S2>/BehavourModule_BYDPowerMode' */
  Beh_BehavourModule_BYDPowerMode();

  /* End of Outputs for SubSystem: '<S2>/BehavourModule_BYDPowerMode' */

  /* Outputs for Atomic SubSystem: '<S2>/BehavourModule_DTCPowerMode' */
  Beh_BehavourModule_DTCPowerMode();

  /* End of Outputs for SubSystem: '<S2>/BehavourModule_DTCPowerMode' */
#elif MACRO_BEHAVEMODULE_SELECT == 0

  /* Output and update for atomic system: '<S1>/BehavourModule_Default' */

  /* Outputs for Atomic SubSystem: '<S3>/BehavourModule_RunInvalidLost' */
  B_BehavourModule_RunInvalidLost();

  /* End of Outputs for SubSystem: '<S3>/BehavourModule_RunInvalidLost' */

  /* Outputs for Atomic SubSystem: '<S3>/BehavourModule_OnOffState' */
  Behav_BehavourModule_OnOffState();

  /* End of Outputs for SubSystem: '<S3>/BehavourModule_OnOffState' */

  /* Outputs for Atomic SubSystem: '<S3>/BehavourModule_StartStopState' */
  B_BehavourModule_StartStopState();

  /* End of Outputs for SubSystem: '<S3>/BehavourModule_StartStopState' */
#endif

  /* End of Outputs for SubSystem: '<Root>/BehavourModule' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
