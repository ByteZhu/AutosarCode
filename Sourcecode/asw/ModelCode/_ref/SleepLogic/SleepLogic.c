/*
 * File: SleepLogic.c
 *
 * Code generated for Simulink model 'SleepLogic'.
 *
 * Model version                  : 1.1133
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Sep 16 13:53:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SleepLogic.h"
#include "SleepLogic_private.h"
/* Named constants for Chart: '<S1>/SleepLogicStatus' */
#define SleepLogic_IN_Exceed           ((UInt8)1U)
#define SleepLogic_IN_IGHigh           ((UInt8)1U)
#define SleepLogic_IN_IGLow            ((UInt8)2U)
#define SleepLogic_IN_Init             ((UInt8)1U)
#define SleepLogic_IN_Low              ((UInt8)1U)
#define SleepLogic_IN_LowtoHigh        ((UInt8)2U)
#define SleepLogic_IN_NO_ACTIVE_CHILD  ((UInt8)0U)
#define SleepLogic_IN_Normal           ((UInt8)2U)
#define SleepLogic_IN_Run              ((UInt8)2U)
#define SleepLogic_IN_ShutDown         ((UInt8)3U)
#define SleepLogic_IN_SleepReq         ((UInt8)4U)

/* Block states (default storage) */
SleepLogic_DW_fwu4 SleepLogicrtDW;

/* Output and update for atomic system: '<Root>/SleepLogicFunc' */
void SleepLogic_SleepLogicFunc(void)
{
  Bool guard1 = false;
  Bool guard2 = false;
  static uint16 IGONCnt = 0;
  static uint16 IGOffCnt = 0;

  /* Outputs for Atomic SubSystem: '<S1>/SleepLogicCond' */
  /* Saturate: '<S2>/Saturation' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/AD_IgnitionSys'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Add1'
   */
#if 0
  Fv_IGkeyVol = (Int16)(((Int32)((UInt32)((((UInt32)AD_IgnitionSys) * ((UInt32)
    ((UInt16)MACRO_AV_IGNITION_SCALE))) >> 9))) + ((Int32)((Int16)
    MACRO_AV_IGNITION_OFFSET)));
#else
  if(!Fv_EXT_NMState)
  {
    Fv_IGkeyVol = 0;
  }
  else
  {
    Fv_IGkeyVol = 1200;
  }
#endif

  if (Fv_IGkeyVol > 3840) {
    Fv_IGkeyVol = 3840;
  } else {
    if (Fv_IGkeyVol < 0) {
      Fv_IGkeyVol = 0;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/SleepLogicCond' */
  Fv_IGkeyVol1 = (Int16)(((Int32)((UInt32)((((UInt32)AD_IgnitionSys) * ((UInt32)
  ((UInt16)MACRO_AV_IGNITION_SCALE))) >> 9))) + ((Int32)((Int16)
  MACRO_AV_IGNITION_OFFSET)));

  if(Fv_IGkeyVol1 < Cal_IGLowVol)
  {
    IGONCnt = 0;
    if(IGOffCnt < 3)
    {
      IGOffCnt++;
    }
    else
    {
      Fv_IGkeyEffect1 = false;
    }
    
  }
  else if((Fv_IGkeyVol1 > Cal_IGHighVol) && (Fv_IGkeyVol1 < Cal_IGExceedVol))
  {
    IGOffCnt = 0;
    if(IGONCnt < 3)
    {
      IGONCnt++;
    }
    else
    {
      Fv_IGkeyEffect1 = true;
    }
  }


  /* Chart: '<S1>/SleepLogicStatus' incorporates:
   *  Saturate: '<S2>/Saturation'
   */
  /* Gateway: SleepLogicFunc/SleepLogicStatus */
  /* During: SleepLogicFunc/SleepLogicStatus */
  if (((UInt32)SleepLogicrtDW.bitsForTID0.is_active_c2_SleepLogic) == 0U) {
    /* Entry: SleepLogicFunc/SleepLogicStatus */
    SleepLogicrtDW.bitsForTID0.is_active_c2_SleepLogic = 1;

    /* Entry Internal: SleepLogicFunc/SleepLogicStatus */
    /* Entry Internal 'Timer': '<S3>:1665' */
    /* Transition: '<S3>:1661' */
    SleepLogicrtDW.bitsForTID0.is_Timer = SleepLogic_IN_IGHigh;

    /* Entry 'IGHigh': '<S3>:1667' */
    SleepLogicrtDW.bitsForTID0.IGkey = true;

    /* Entry Internal 'IGHigh': '<S3>:1667' */
    /* Transition: '<S3>:1668' */
    SleepLogicrtDW.bitsForTID0.is_IGHigh = SleepLogic_IN_Normal;

    /* Entry 'Normal': '<S3>:1672' */
    SleepLogicrtDW.SleepLogicTmrCntj = Cal_WakeupTime;

    /* Entry Internal 'Logic': '<S3>:1664' */
    /* Transition: '<S3>:1658' */
    SleepLogicrtDW.bitsForTID0.is_Logic = SleepLogic_IN_Init;

    /* Entry 'Init': '<S3>:1694' */
    /* inhibit diagnose */
    SysTaskShutDownPending = false;
  } else {
    /* During 'Timer': '<S3>:1665' */
    if (((UInt32)SleepLogicrtDW.bitsForTID0.is_Timer) == SleepLogic_IN_IGHigh) {
      /* Outputs for Atomic SubSystem: '<S1>/SleepLogicCond' */
      /* During 'IGHigh': '<S3>:1667' */
      if (Fv_IGkeyVol <= Cal_IGLowVol) {
        /* Transition: '<S3>:1662' */
        /* Exit Internal 'IGHigh': '<S3>:1667' */
        SleepLogicrtDW.bitsForTID0.is_IGHigh = SleepLogic_IN_NO_ACTIVE_CHILD;
        SleepLogicrtDW.bitsForTID0.is_Timer = SleepLogic_IN_IGLow;

        /* Entry 'IGLow': '<S3>:1678' */
        SleepLogicrtDW.bitsForTID0.IGkey = false;

        /* Entry Internal 'IGLow': '<S3>:1678' */
        /* Transition: '<S3>:1679' */
        SleepLogicrtDW.bitsForTID0.is_IGLow = SleepLogic_IN_Low;

        /* Entry 'Low': '<S3>:1682' */
        SleepLogicrtDW.SleepLogicTmrCntk = Cal_SleepTime;
      } else if (((UInt32)SleepLogicrtDW.bitsForTID0.is_IGHigh) ==
                 SleepLogic_IN_Exceed) {
        /* During 'Exceed': '<S3>:1671' */
        if ((Fv_IGkeyVol >= Cal_IGHighVol) && (Fv_IGkeyVol <= Cal_IGExceedVol))
        {
          /* Transition: '<S3>:1670' */
          SleepLogicrtDW.bitsForTID0.is_IGHigh = SleepLogic_IN_Normal;

          /* Entry 'Normal': '<S3>:1672' */
          SleepLogicrtDW.SleepLogicTmrCntj = Cal_WakeupTime;
        }
      } else {
        /* During 'Normal': '<S3>:1672' */
        if ((Fv_IGkeyVol < Cal_IGHighVol) || (Fv_IGkeyVol > Cal_IGExceedVol)) {
          /* Transition: '<S3>:1669' */
          SleepLogicrtDW.bitsForTID0.is_IGHigh = SleepLogic_IN_Exceed;
        } else {
          /* Transition: '<S3>:1675' */
          if (((Int32)SleepLogicrtDW.SleepLogicTmrCntj) > 0) {
            /* Transition: '<S3>:1676' */
            /* Transition: '<S3>:1714' */
            SleepLogicrtDW.SleepLogicTmrCntj = (UInt16)((Int32)(((Int32)
              SleepLogicrtDW.SleepLogicTmrCntj) - 1));

            /* Transition: '<S3>:1716' */
          } else {
            /* Transition: '<S3>:1677' */
            Fv_IGkeyEffect = true;
          }
        }
      }

      /* End of Outputs for SubSystem: '<S1>/SleepLogicCond' */
    } else {
      /* Outputs for Atomic SubSystem: '<S1>/SleepLogicCond' */
      /* During 'IGLow': '<S3>:1678' */
      if (Fv_IGkeyVol >= Cal_IGHighVol) {
        /* Transition: '<S3>:1660' */
        /* Exit Internal 'IGLow': '<S3>:1678' */
        SleepLogicrtDW.bitsForTID0.is_IGLow = SleepLogic_IN_NO_ACTIVE_CHILD;
        SleepLogicrtDW.bitsForTID0.is_Timer = SleepLogic_IN_IGHigh;

        /* Entry 'IGHigh': '<S3>:1667' */
        SleepLogicrtDW.bitsForTID0.IGkey = true;

        /* Entry Internal 'IGHigh': '<S3>:1667' */
        /* Transition: '<S3>:1668' */
        SleepLogicrtDW.bitsForTID0.is_IGHigh = SleepLogic_IN_Normal;

        /* Entry 'Normal': '<S3>:1672' */
        SleepLogicrtDW.SleepLogicTmrCntj = Cal_WakeupTime;
      } else if (((UInt32)SleepLogicrtDW.bitsForTID0.is_IGLow) ==
                 SleepLogic_IN_Low) {
        /* During 'Low': '<S3>:1682' */
        if (Fv_IGkeyVol > Cal_IGLowVol) {
          /* Transition: '<S3>:1680' */
          SleepLogicrtDW.bitsForTID0.is_IGLow = SleepLogic_IN_LowtoHigh;
        } else {
          /* Transition: '<S3>:1780' */
          if (((Int32)SleepLogicrtDW.SleepLogicTmrCntk) > 0) {
            /* Transition: '<S3>:1784' */
            /* Transition: '<S3>:1787' */
            SleepLogicrtDW.SleepLogicTmrCntk = (UInt16)((Int32)(((Int32)
              SleepLogicrtDW.SleepLogicTmrCntk) - 1));

            /* Transition: '<S3>:1779' */
          } else {
            /* Transition: '<S3>:1781' */
            Fv_IGkeyEffect = false;
          }
        }
      } else {
        /* During 'LowtoHigh': '<S3>:1688' */
        if (Fv_IGkeyVol <= Cal_IGLowVol) {
          /* Transition: '<S3>:1681' */
          SleepLogicrtDW.bitsForTID0.is_IGLow = SleepLogic_IN_Low;

          /* Entry 'Low': '<S3>:1682' */
          SleepLogicrtDW.SleepLogicTmrCntk = Cal_SleepTime;
        }
      }

      /* End of Outputs for SubSystem: '<S1>/SleepLogicCond' */
    }

    /* During 'Logic': '<S3>:1664' */
    guard1 = false;
    guard2 = false;

    switch (SleepLogicrtDW.bitsForTID0.is_Logic) {
     case SleepLogic_IN_Init:
      /* During 'Init': '<S3>:1694' */
      if (Fv_SysFailCloseFlag) {
        /* Transition: '<S3>:1654' */
        ClosePredrive();
        CloseRelay();
        ClosePhase();
        guard1 = true;
      } else if (Fv_IGkeyEffect) {
        /* Transition: '<S3>:1659' */
        SleepLogicrtDW.bitsForTID0.is_Logic = SleepLogic_IN_Run;

        /* Entry 'Run': '<S3>:1707' */
        SysTaskShutDownPending = false;
        SysTaskRunPending = true;
      } else {
        /* Transition: '<S3>:1656' */
        guard1 = true;
      }
      break;

     case SleepLogic_IN_Run:
      /* During 'Run': '<S3>:1707' */
      if (Fv_SysFailCloseFlag) {
        /* Transition: '<S3>:1653' */
        ClosePredrive();
        CloseRelay();
        ClosePhase();
        guard2 = true;
      } else {
        if ((!Fv_IGkeyEffect) && (Fv_SysDownCloseFlag)) {
          /* Transition: '<S3>:1655' */
          ClosePredrive();
          guard2 = true;
        }
      }
      break;

     case SleepLogic_IN_ShutDown:
      /* During 'ShutDown': '<S3>:1689' */
      if ((SleepLogicrtDW.bitsForTID0.IGkey) && (!Fv_SysFailCloseFlag)) {
        /* Transition: '<S3>:1666' */
        SoftWareReset();
        SleepLogicrtDW.bitsForTID0.is_Logic = SleepLogic_IN_ShutDown;

        /* Entry 'ShutDown': '<S3>:1689' */
        SysTaskShutDownPending = true;

        /* IGkeyDown = false; */
        DisablePowerSupply();
      } else {
        /* Transition: '<S3>:1692' */
        /* Transition: '<S3>:1693' */
        SERVICE_WATCHDOG();
      }
      break;

     default:
      /* During 'SleepReq': '<S3>:1695' */
      if (SleepLogicrtDW.bitsForTID0.IGkeyDown) {
        /* Transition: '<S3>:1663' */
        SleepLogicrtDW.bitsForTID0.is_Logic = SleepLogic_IN_ShutDown;

        /* Entry 'ShutDown': '<S3>:1689' */
        SysTaskShutDownPending = true;

        /* IGkeyDown = false; */
        DisablePowerSupply();
      } else if ((SleepLogicrtDW.bitsForTID0.IGkey) && (!Fv_SysFailCloseFlag)) {
        /* Transition: '<S3>:1657' */
        SleepLogicrtDW.bitsForTID0.is_Logic = SleepLogic_IN_Init;

        /* Entry 'Init': '<S3>:1694' */
        /* inhibit diagnose */
        SysTaskShutDownPending = false;
      } else {
        /* Transition: '<S3>:1726' */
        if (Fv_SysFailCloseFlag) {
          /* Transition: '<S3>:1728' */
          /* Transition: '<S3>:1730' */
          ClosePredrive();
          CloseRelay();
          ClosePhase();

          /* Transition: '<S3>:1733' */
        } else {
          /* Transition: '<S3>:1732' */
        }

        /* Transition: '<S3>:1735' */
        if (!Fv_IGkeyEffect) {
          /* Transition: '<S3>:1737' */
          if (((Int32)SleepLogicrtDW.ShutDownDelayTmrCnt) > 0) {
            /* Transition: '<S3>:1741' */
            /* Transition: '<S3>:1743' */
            SleepLogicrtDW.ShutDownDelayTmrCnt = (UInt16)((Int32)(((Int32)
              SleepLogicrtDW.ShutDownDelayTmrCnt) - 1));
            if (((Int32)SleepLogicrtDW.ShutDownDelayTmrCnt) == ((Int32)((UInt32)
                  (((UInt32)Cal_ShutDownTime) >> 1)))) {
              /* Transition: '<S3>:1749' */
              /* Transition: '<S3>:1751' */
              CommonCheckSumStoredRequest();
            } else {
              /* Transition: '<S3>:1753' */
              /* Transition: '<S3>:1790' */
            }

            /* Transition: '<S3>:1800' */
          } else {
            /* Transition: '<S3>:1745' */
            if ((((Int32)SleepLogicrtDW.store_timout) == 0) ||
                (StoreManager_GetStatus() != STOREMANAGER_BUSY)) {
              /* Transition: '<S3>:1792' */
              /* Transition: '<S3>:1794' */
              ClosePredrive();
              CloseRelay();
              ClosePhase();
              SleepLogicrtDW.bitsForTID0.IGkeyDown = true;

              /* Transition: '<S3>:1801' */
            } else {
              /* Transition: '<S3>:1796' */
              SleepLogicrtDW.store_timout = (UInt16)((Int32)(((Int32)
                SleepLogicrtDW.store_timout) - 1));

              /* Transition: '<S3>:1797' */
              /* Transition: '<S3>:1801' */
            }
          }
        } else {
          /* Transition: '<S3>:1757' */
          /* Transition: '<S3>:1798' */
          /* Transition: '<S3>:1797' */
          /* Transition: '<S3>:1801' */
        }
      }
      break;
    }

    if (guard2) {
      /* Exit 'Run': '<S3>:1707' */
      SysTaskRunPending = false;
      SleepLogicrtDW.bitsForTID0.is_Logic = SleepLogic_IN_SleepReq;

      /* Entry 'SleepReq': '<S3>:1695' */
      SysTaskShutDownPending = true;
      SleepLogicrtDW.bitsForTID0.IGkeyDown = false;
      SleepLogicrtDW.ShutDownDelayTmrCnt = Cal_ShutDownTime;
      AngleCorrectStoredRequest();
      TOCDataStoredRequest();
      SleepLogicrtDW.store_timout = ((UInt16)MACRO_SHUTDOWN_TIMEOUT);
    }

    if (guard1) {
      SleepLogicrtDW.bitsForTID0.is_Logic = SleepLogic_IN_SleepReq;

      /* Entry 'SleepReq': '<S3>:1695' */
      SysTaskShutDownPending = true;
      SleepLogicrtDW.bitsForTID0.IGkeyDown = false;
      SleepLogicrtDW.ShutDownDelayTmrCnt = Cal_ShutDownTime;
      AngleCorrectStoredRequest();
      TOCDataStoredRequest();
      SleepLogicrtDW.store_timout = ((UInt16)MACRO_SHUTDOWN_TIMEOUT);
    }
  }

  /* End of Chart: '<S1>/SleepLogicStatus' */
}

/* Output and update for referenced model: 'SleepLogic' */
void SleepLogic(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/SleepLogicFunc' */
  SleepLogic_SleepLogicFunc();

  /* End of Outputs for SubSystem: '<Root>/SleepLogicFunc' */
}

/* Function for referencing symbol: 'SleepLogic_GetIGkeyState' */
boolean SleepLogic_GetIGkeyState(void)
{
  return Fv_IGkeyEffect1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
