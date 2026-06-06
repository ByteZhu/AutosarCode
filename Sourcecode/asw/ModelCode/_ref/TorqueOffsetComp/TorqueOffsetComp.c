/*
 * File: TorqueOffsetComp.c
 *
 * Code generated for Simulink model 'TorqueOffsetComp'.
 *
 * Model version                  : 1.1678
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Oct 25 17:07:17 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TorqueOffsetComp.h"
#include "TorqueOffsetComp_private.h"
#include "asr_s32.h"
#include "asr_s64.h"
#include "GlobalVarSupport.h"

/* Named constants for Chart: '<S3>/TorqueOffsetComp_StateMachine' */
#define TorqueOffsetComp_IN_Active     ((UInt8)1U)
#define TorqueOffsetComp_IN_HDLTimer   ((UInt8)2U)
#define TorqueOffsetComp_IN_Hold       ((UInt8)1U)
#define TorqueOffsetComp_IN_Study      ((UInt8)2U)
#define TorqueOffsetComp_IN_Wait       ((UInt8)3U)
#define TorqueOffset_IN_NO_ACTIVE_CHILD ((UInt8)0U)

/* Block states (default storage) */
TorqueOffsetComp_DW_fwu4 TorqueOffsetComprtDW;

/* Output and update for atomic system: '<S2>/TorqueOffsetComp_StraightCond' */
void T_TorqueOffsetComp_StraightCond(void)
{
  Int32 rtb_Abs3;
  Int32 rtb_Add;

  /* Sum: '<S5>/Add1' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read'
   *  DataStoreRead: '<S2>/Data Store Read1'
   */
  rtb_Abs3 = ((Int32)Fv_WheelSpeed_FL) - ((Int32)Fv_WheelSpeed_FR);

  /* Abs: '<S5>/Abs3' */
  if (rtb_Abs3 < 0) {
    rtb_Abs3 = -rtb_Abs3;
  }

  /* End of Abs: '<S5>/Abs3' */

  /* Sum: '<S5>/Add' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read'
   *  DataStoreRead: '<S2>/Data Store Read1'
   */
  rtb_Add = (Int32)((UInt32)(((UInt32)Fv_WheelSpeed_FL) + ((UInt32)
    Fv_WheelSpeed_FR)));

  /* Logic: '<S5>/Logical Operator4' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read5'
   *  DataStoreRead: '<S5>/Data Store Read4'
   *  Logic: '<S5>/Logical Operator1'
   *  Logic: '<S5>/Logical Operator2'
   *  Logic: '<S5>/Logical Operator3'
   *  Product: '<S5>/Product'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  Fv_TOCStcValid = (((Fv_WhsInvalidFlag == false) && (((rtb_Add > 0) ||
    (rtb_Abs3 > 0)) && (rtb_Add >= (rtb_Abs3 * ((Int32)Cal_TOC_StraightCoef)))))
                    || (((Int32)(Fv_TOCSTCFbd ? 1 : 0)) > ((Int32)(false ? 1 : 0))));
}

/* Output and update for atomic system: '<S2>/TorqueOffsetComp_ValidScale' */
void Tor_TorqueOffsetComp_ValidScale(void)
{
  /* Logic: '<S6>/Logical Operator5' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read10'
   *  DataStoreRead: '<S2>/Data Store Read11'
   *  DataStoreRead: '<S2>/Data Store Read12'
   *  DataStoreRead: '<S2>/Data Store Read2'
   *  DataStoreRead: '<S2>/Data Store Read3'
   *  DataStoreRead: '<S2>/Data Store Read6'
   *  DataStoreRead: '<S2>/Data Store Read7'
   *  DataStoreRead: '<S2>/Data Store Read9'
   *  Inport: '<Root>/WhichMode'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S19>/Compare'
   */
  Fv_TOCStyValid = (((((((((Fv_AngleMidValidFlag == ANGLE_STS_Valid) &&
    (Fv_FaultClass_Torque == ((UInt16)0U))) && (Fv_AbsInvalidFlag == false)) &&
    (Fv_AngleReadyFlag == HELLA_STS_Decode)) && (Fv_HighFailFlag == 0)) &&
                       (Fv_LowFailFlag == 0)) && (Fv_LimitFailFlag == 0)) &&
                     (Fv_TOCShortFuncFbd == false)) && (WhichMode >= HOLD_ACTIVE) &&
                     (Fv_LKA_ControlSts != 2) && (Fv_APA_ControlSts != 2));

  /* Abs: '<S6>/ang_abs' incorporates:
   *  Inport: '<Root>/Tv_StrAng_Raw'
   */
  if (Tv_StrAng_Raw < 0) {
    TorqueOffsetComprtDW.str_ang_abs = (Int16)(-Tv_StrAng_Raw);
  } else {
    TorqueOffsetComprtDW.str_ang_abs = Tv_StrAng_Raw;
  }

  /* End of Abs: '<S6>/ang_abs' */

  /* Abs: '<S6>/spd_abs' incorporates:
   *  Inport: '<Root>/Tv_dStrAng'
   */
  if (Tv_dStrAng < 0) {
    TorqueOffsetComprtDW.str_spd_abs = (Int16)(-Tv_dStrAng);
  } else {
    TorqueOffsetComprtDW.str_spd_abs = Tv_dStrAng;
  }

  /* End of Abs: '<S6>/spd_abs' */

  /* Abs: '<S6>/trq_abs' incorporates:
   *  Inport: '<Root>/Fv_StrTrq'
   */
  if (Fv_StrTrq0 < 0) {
    TorqueOffsetComprtDW.str_trq_abs = (Int16)(-Fv_StrTrq0);
  } else {
    TorqueOffsetComprtDW.str_trq_abs = Fv_StrTrq0;
  }

  /* End of Abs: '<S6>/trq_abs' */
}

/* Output and update for atomic system: '<S1>/TorqueOffsetComp_PreProcess' */
void Tor_TorqueOffsetComp_PreProcess(void)
{
  /* Outputs for Atomic SubSystem: '<S2>/TorqueOffsetComp_ValidScale' */
  Tor_TorqueOffsetComp_ValidScale();

  /* End of Outputs for SubSystem: '<S2>/TorqueOffsetComp_ValidScale' */

  /* Outputs for Atomic SubSystem: '<S2>/TorqueOffsetComp_StraightCond' */
  T_TorqueOffsetComp_StraightCond();

  /* End of Outputs for SubSystem: '<S2>/TorqueOffsetComp_StraightCond' */
}

/* System initialize for atomic system: '<S1>/TorqueOffsetComp_StateMng' */
void TorqueOffsetComp_StateMng_Init(void)
{
  /* SystemInitialize for Chart: '<S3>/TorqueOffsetComp_StateMachine' */
  Fv_TOCState = TOC_STATE_HoldLong;
}

/* Output and update for atomic system: '<S1>/TorqueOffsetComp_StateMng' */
void Torqu_TorqueOffsetComp_StateMng(void)
{
  /* Chart: '<S3>/TorqueOffsetComp_StateMachine' incorporates:
   *  Inport: '<Root>/Fv_VehSpd'
   */
  /* Gateway: TestSub/TorqueOffsetComp_StateMng/TorqueOffsetComp_StateMachine */
  /* During: TestSub/TorqueOffsetComp_StateMng/TorqueOffsetComp_StateMachine */
  if (((UInt32)TorqueOffsetComprtDW.bitsForTID0.is_active_c3_TorqueOffsetComp) ==
      0U) {
    /* Entry: TestSub/TorqueOffsetComp_StateMng/TorqueOffsetComp_StateMachine */
    TorqueOffsetComprtDW.bitsForTID0.is_active_c3_TorqueOffsetComp = 1;

    /* Entry Internal: TestSub/TorqueOffsetComp_StateMng/TorqueOffsetComp_StateMachine */
    /* Transition: '<S20>:341' */
    TorqueOffsetComprtDW.bitsForTID0.is_c3_TorqueOffsetComp =
      TorqueOffsetComp_IN_Wait;

    /* Entry 'Wait': '<S20>:340' */
    Fv_TOCState = TOC_STATE_HoldLong;
  } else {
    switch (TorqueOffsetComprtDW.bitsForTID0.is_c3_TorqueOffsetComp) {
     case TorqueOffsetComp_IN_Active:
      /* During 'Active': '<S20>:451' */
      if ((TorqueOffsetComprtDW.exit_cnt == 0) || (!Fv_TOCStyValid)) {
        /* Transition: '<S20>:349' */
        /* Exit Internal 'Active': '<S20>:451' */
        TorqueOffsetComprtDW.bitsForTID0.is_Active =
          TorqueOffset_IN_NO_ACTIVE_CHILD;
        TorqueOffsetComprtDW.bitsForTID0.is_c3_TorqueOffsetComp =
          TorqueOffsetComp_IN_Wait;

        /* Entry 'Wait': '<S20>:340' */
        Fv_TOCState = TOC_STATE_HoldLong;
      } else {
        /* Transition: '<S20>:459' */
        if ((((((Fv_VehSpd <= Cal_TOC_ExtVehSpd) || (Fv_VehSpd >
                 Cal_TOC_MaxVehSpd)) || (TorqueOffsetComprtDW.str_ang_abs >
                Cal_TOC_ExtStrAng)) || (TorqueOffsetComprtDW.str_spd_abs >
               Cal_TOC_ExtStrSpd)) || (TorqueOffsetComprtDW.str_trq_abs >
              Cal_TOC_ExtStrTrq)) && (TorqueOffsetComprtDW.exit_cnt > 0)) {
          /* Transition: '<S20>:452' */
          /* Transition: '<S20>:457' */
          TorqueOffsetComprtDW.exit_cnt--;
        } else {
          /* Transition: '<S20>:458' */
          /* Transition: '<S20>:453' */
        }

        if (((UInt32)TorqueOffsetComprtDW.bitsForTID0.is_Active) ==
            TorqueOffsetComp_IN_Hold) {
          /* During 'Hold': '<S20>:344' */
          if (((((TorqueOffsetComprtDW.str_ang_abs < Cal_TOC_ActStrAng) &&
                 (Fv_VehSpd > Cal_TOC_ActVehSpd)) &&
                (TorqueOffsetComprtDW.str_spd_abs < Cal_TOC_ActStrSpd)) &&
               (TorqueOffsetComprtDW.str_trq_abs < Cal_TOC_HoldStrTrq)) &&
              (Fv_TOCStcValid) && (Fv_TOCYawRateCond)) {
            /* Transition: '<S20>:347' */
            TorqueOffsetComprtDW.bitsForTID0.is_Active =
              TorqueOffsetComp_IN_Study;

            /* Entry 'Study': '<S20>:343' */
            TorqueOffsetComprtDW.exit_cnt = (Int16)Cal_TOC_FuncExtTime;
          }
        } else {
          /* During 'Study': '<S20>:343' */
          if (((((TorqueOffsetComprtDW.str_ang_abs > Cal_TOC_HoldStrAng) ||
                 (Fv_VehSpd < Cal_TOC_ActVehSpd)) ||
                (TorqueOffsetComprtDW.str_spd_abs > Cal_TOC_HoldStrSpd)) ||
               (TorqueOffsetComprtDW.str_trq_abs > Cal_TOC_HoldStrTrq)) ||
              (!Fv_TOCStcValid) ||(!Fv_TOCYawRateCond)) {
            /* Transition: '<S20>:348' */
            TorqueOffsetComprtDW.bitsForTID0.is_Active =
              TorqueOffsetComp_IN_Hold;

            /* Entry 'Hold': '<S20>:344' */
            Fv_TOCState = TOC_STATE_HoldWait;
            TorqueOffsetComprtDW.time_cnt = (Int16)((UInt16)MACRO_TOC_SHORT_TMR);
            TorqueOffsetComprtDW.exit_cnt = (Int16)Cal_TOC_FuncExtTime;
          } else {
            /* Transition: '<S20>:469' */
            if (TorqueOffsetComprtDW.time_cnt > 0) {
              /* Transition: '<S20>:466' */
              /* Transition: '<S20>:468' */
              TorqueOffsetComprtDW.time_cnt--;
            } else {
              /* Transition: '<S20>:467' */
              Fv_TOCState = TOC_STATE_ActShort;

              /* Transition: '<S20>:470' */
            }
          }
        }
      }
      break;

     case TorqueOffsetComp_IN_HDLTimer:
      /* During 'HDLTimer': '<S20>:371' */
      if (TorqueOffsetComprtDW.time_cnt == 0) {
        /* Transition: '<S20>:388' */
        TorqueOffsetComprtDW.bitsForTID0.is_c3_TorqueOffsetComp =
          TorqueOffsetComp_IN_Active;

        /* Entry 'Active': '<S20>:451' */
        TorqueOffsetComprtDW.time_cnt = 0;

        /* Entry Internal 'Active': '<S20>:451' */
        /* Transition: '<S20>:460' */
        TorqueOffsetComprtDW.bitsForTID0.is_Active = TorqueOffsetComp_IN_Study;

        /* Entry 'Study': '<S20>:343' */
        TorqueOffsetComprtDW.exit_cnt = (Int16)Cal_TOC_FuncExtTime;
      } else if ((((((TorqueOffsetComprtDW.str_ang_abs > Cal_TOC_ActStrAng) ||
                     (Fv_VehSpd < Cal_TOC_ActVehSpd)) || (Fv_VehSpd >
          Cal_TOC_MaxVehSpd)) || (TorqueOffsetComprtDW.str_spd_abs >
                    Cal_TOC_ActStrSpd)) || (TorqueOffsetComprtDW.str_trq_abs >
                   Cal_TOC_ActStrTrq)) || (!Fv_TOCStyValid)) {
        /* Transition: '<S20>:390' */
        TorqueOffsetComprtDW.bitsForTID0.is_c3_TorqueOffsetComp =
          TorqueOffsetComp_IN_Wait;

        /* Entry 'Wait': '<S20>:340' */
        Fv_TOCState = TOC_STATE_HoldLong;
      } else {
        /* Transition: '<S20>:379' */
        if (TorqueOffsetComprtDW.time_cnt > 0) {
          /* Transition: '<S20>:381' */
          /* Transition: '<S20>:384' */
          TorqueOffsetComprtDW.time_cnt--;
        } else {
          /* Transition: '<S20>:383' */
          /* Transition: '<S20>:385' */
        }
      }
      break;

     default:
      /* During 'Wait': '<S20>:340' */
      if ((((((TorqueOffsetComprtDW.str_ang_abs < Cal_TOC_ActStrAng) &&
              (Fv_VehSpd > Cal_TOC_ActVehSpd)) && (Fv_VehSpd < Cal_TOC_MaxVehSpd))
            && (TorqueOffsetComprtDW.str_spd_abs < Cal_TOC_ActStrSpd)) &&
           (TorqueOffsetComprtDW.str_trq_abs < Cal_TOC_ActStrTrq)) &&
          (Fv_TOCStyValid)) {
        /* Transition: '<S20>:345' */
        TorqueOffsetComprtDW.bitsForTID0.is_c3_TorqueOffsetComp =
          TorqueOffsetComp_IN_HDLTimer;

        /* Entry 'HDLTimer': '<S20>:371' */
        Fv_TOCState = TOC_STATE_HoldTcnt;
        TorqueOffsetComprtDW.time_cnt = (Int16)Cal_TOC_FuncActTime;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/TorqueOffsetComp_StateMachine' */
}

/* Output and update for atomic system: '<S4>/toc_cond_judge' */
void TorqueOffsetComp_toc_cond_judge(void)
{
  /* Logic: '<S21>/Logical Operator1' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S21>/Constant5'
   *  RelationalOperator: '<S21>/Relational Operator1'
   *  RelationalOperator: '<S21>/Relational Operator2'
   */
  TorqueOffsetComprtDW.short_reset = ((TOC_STATE_HoldTcnt == Fv_TOCState) ||
    (TOC_STATE_HoldLong == Fv_TOCState));

  /* RelationalOperator: '<S21>/Relational Operator7' incorporates:
   *  Constant: '<S21>/Constant8'
   */
  TorqueOffsetComprtDW.study_calc = (Fv_TOCState == TOC_STATE_ActShort);

  /* Logic: '<S21>/Logical Operator2' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  Constant: '<S28>/Constant'
   *  DataStoreRead: '<S21>/Data Store Read3'
   *  DataStoreRead: '<S4>/Data Store Read12'
   *  Inport: '<Root>/Fv_VehSpd'
   *  Inport: '<Root>/WhichMode'
   *  RelationalOperator: '<S25>/Compare'
   *  RelationalOperator: '<S26>/Compare'
   *  RelationalOperator: '<S27>/Compare'
   *  RelationalOperator: '<S28>/Compare'
   */
  TorqueOffsetComprtDW.long_enb = ((((Fv_TOCLongFuncFbd == false) && (WhichMode >=
    HOLD_ACTIVE)) && (Fv_AbsInvalidFlag == false)) && (Fv_VehSpd >=
    Cal_TOC_VehSpdLongComp));
}

/* Output and update for atomic system: '<S4>/toc_trq_calc' */
void TorqueOffsetComp_toc_trq_calc(void)
{
  Int16 rtb_UnaryMinus1;
  Int16 rtb_Diff;
  Int32 rtb_UnaryMinus;
  Int32 rtb_Constant3_tmp;

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S22>/Constant4'
   *  Inport: '<Root>/Fv_StrTrq'
   *  RelationalOperator: '<S29>/u_GTE_up'
   */
  if (Fv_StrTrq0 >= Cal_TOC_DeadZoneTrq) {
    rtb_UnaryMinus1 = Cal_TOC_DeadZoneTrq;
  } else {
    /* UnaryMinus: '<S22>/Unary Minus1' incorporates:
     *  Constant: '<S22>/Constant6'
     */
    rtb_UnaryMinus1 = (Int16)(-Cal_TOC_DeadZoneTrq);

    /* Switch: '<S29>/Switch1' incorporates:
     *  RelationalOperator: '<S29>/u_GT_lo'
     */
    if (Fv_StrTrq0 > rtb_UnaryMinus1) {
      rtb_UnaryMinus1 = Fv_StrTrq0;
    }

    /* End of Switch: '<S29>/Switch1' */
  }

  /* End of Switch: '<S29>/Switch' */

  /* Sum: '<S29>/Diff' incorporates:
   *  Inport: '<Root>/Fv_StrTrq'
   */
  rtb_Diff = (Int16)(Fv_StrTrq0 - rtb_UnaryMinus1);

  /* UnaryMinus: '<S22>/Unary Minus2' incorporates:
   *  Constant: '<S22>/Constant8'
   */
  rtb_UnaryMinus1 = (Int16)(-Cal_TOC_MaxDiffTrq);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Product1'
   */
  if (TorqueOffsetComprtDW.study_calc) {
    /* Switch: '<S32>/Switch2' incorporates:
     *  Constant: '<S22>/Constant7'
     *  RelationalOperator: '<S32>/LowerRelop1'
     *  RelationalOperator: '<S32>/UpperRelop'
     *  Switch: '<S32>/Switch'
     */
    if (rtb_Diff > Cal_TOC_MaxDiffTrq) {
      rtb_Diff = Cal_TOC_MaxDiffTrq;
    } else {
      if (rtb_Diff < rtb_UnaryMinus1) {
        /* Switch: '<S32>/Switch' */
        rtb_Diff = rtb_UnaryMinus1;
      }
    }

    /* End of Switch: '<S32>/Switch2' */
    rtb_UnaryMinus = asr_s32(((Int32)Cal_TOC_ShortCalcKi) * ((Int32)rtb_Diff),
      4U);
  } else {
    rtb_UnaryMinus = 0;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Sum: '<S22>/Sum' incorporates:
   *  Delay: '<S22>/delay'
   */
  TorqueOffsetComprtDW.delay_DSTATE_hmnw += rtb_UnaryMinus;

  /* Constant: '<S22>/Constant3' incorporates:
   *  Constant: '<S22>/Constant5'
   */
  rtb_Constant3_tmp = ((Int32)Cal_TOC_MaxShortTrq) * 8192;

  /* UnaryMinus: '<S22>/Unary Minus' */
  rtb_UnaryMinus = -rtb_Constant3_tmp;

  /* Switch: '<S31>/Switch2' incorporates:
   *  Constant: '<S22>/Constant3'
   *  RelationalOperator: '<S31>/LowerRelop1'
   *  RelationalOperator: '<S31>/UpperRelop'
   *  Switch: '<S31>/Switch'
   */
  if (TorqueOffsetComprtDW.delay_DSTATE_hmnw > rtb_Constant3_tmp) {
    TorqueOffsetComprtDW.delay_DSTATE_hmnw = rtb_Constant3_tmp;
  } else {
    if (TorqueOffsetComprtDW.delay_DSTATE_hmnw < rtb_UnaryMinus) {
      /* Switch: '<S31>/Switch' */
      TorqueOffsetComprtDW.delay_DSTATE_hmnw = rtb_UnaryMinus;
    }
  }

  /* End of Switch: '<S31>/Switch2' */

  /* Chart: '<S30>/rate_limit' incorporates:
   *  Constant: '<S30>/Constant'
   *  DataTypeConversion: '<S33>/FixPt Gateway Out'
   *  DataTypeConversion: '<S34>/FixPt Gateway Out'
   */
  /* Gateway: TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/LimitCoef/rate_limit */
  /* During: TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/LimitCoef/rate_limit */
  /* Entry Internal: TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/LimitCoef/rate_limit */
  /* Transition: '<S35>:5' */
  /* '<S35>:7:1' sf_internal_predicateOutput = reset>0; */
  if (TorqueOffsetComprtDW.short_reset) {
    /* Transition: '<S35>:7' */
    /* '<S35>:9:1' sf_internal_predicateOutput = input>limit; */
    if (TorqueOffsetComprtDW.delay_DSTATE_hmnw > Cal_TOC_ShortTrqRate) {
      /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
       *  Delay: '<S22>/delay'
       */
      /* Transition: '<S35>:9' */
      /* '<S35>:9:1' output=input-limit; */
      TorqueOffsetComprtDW.delay_DSTATE_hmnw -= Cal_TOC_ShortTrqRate;

      /* Transition: '<S35>:14' */
      /* Transition: '<S35>:19' */
    } else {
      /* Transition: '<S35>:11' */
      /* '<S35>:13:1' sf_internal_predicateOutput = input<-limit; */
      if (TorqueOffsetComprtDW.delay_DSTATE_hmnw < (-Cal_TOC_ShortTrqRate)) {
        /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
         *  Delay: '<S22>/delay'
         */
        /* Transition: '<S35>:13' */
        /* '<S35>:13:1' output=input+limit; */
        TorqueOffsetComprtDW.delay_DSTATE_hmnw += Cal_TOC_ShortTrqRate;

        /* Transition: '<S35>:19' */
      } else {
        /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
         *  Delay: '<S22>/delay'
         */
        /* Transition: '<S35>:16' */
        /* Transition: '<S35>:18' */
        /* '<S35>:18:1' output = 0; */
        TorqueOffsetComprtDW.delay_DSTATE_hmnw = 0;
      }
    }

    /* Transition: '<S35>:24' */
  } else {
    /* Transition: '<S35>:21' */
    /* Transition: '<S35>:23' */
    /* '<S35>:23:1' output=input; */
  }

  /* End of Chart: '<S30>/rate_limit' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' incorporates:
   *  Delay: '<S22>/delay'
   */
  Fv_TOCShortTrq = (Int16)asr_s32(TorqueOffsetComprtDW.delay_DSTATE_hmnw, 13U);
}

/* Output and update for atomic system: '<S4>/toc_trq_out' */
void TorqueOffsetComp_toc_trq_out(void)
{
  Int16 rtb_UnaryMinus;
  Int32 rtb_DataTypeConversion_opjm;
  Int32 rtb_differ;
  Int32 rtb_UnaryMinus_f52o;
  Int16 rtb_sum_trq;

  /* DataTypeConversion: '<S37>/Data Type Conversion' incorporates:
   *  Constant: '<S36>/Constant'
   *  DataStoreRead: '<S23>/Data Store Read9'
   *  Product: '<S23>/Product'
   *  RelationalOperator: '<S36>/Compare'
   */
  rtb_DataTypeConversion_opjm = ((((Int32)(TorqueOffsetComprtDW.long_enb ? 1 : 0))
    > ((Int32)(false ? 1 : 0))) ? ((Int32)Fv_TOCInitStyTrq) : 0) * 8192;

  /* Sum: '<S37>/Subtract' incorporates:
   *  UnitDelay: '<S37>/Unit Delay'
   */
  rtb_differ = rtb_DataTypeConversion_opjm -
    TorqueOffsetComprtDW.UnitDelay_DSTATE;

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Constant1'
   *  RelationalOperator: '<S37>/Relational Operator'
   *  Sum: '<S37>/Add'
   *  UnitDelay: '<S37>/Unit Delay'
   */
  if (rtb_differ >= Cal_TOC_LongTrqOutRate) {
    TorqueOffsetComprtDW.UnitDelay_DSTATE += Cal_TOC_LongTrqOutRate;
  } else {
    /* UnaryMinus: '<S37>/Unary Minus' incorporates:
     *  Constant: '<S37>/Constant2'
     */
    rtb_UnaryMinus_f52o = -Cal_TOC_LongTrqOutRate;

    /* Switch: '<S37>/Switch1' incorporates:
     *  RelationalOperator: '<S37>/Relational Operator1'
     */
    if (rtb_differ <= rtb_UnaryMinus_f52o) {
      /* UnitDelay: '<S37>/Unit Delay' incorporates:
       *  Sum: '<S37>/Add1'
       */
      TorqueOffsetComprtDW.UnitDelay_DSTATE += rtb_UnaryMinus_f52o;
    } else {
      /* UnitDelay: '<S37>/Unit Delay' */
      TorqueOffsetComprtDW.UnitDelay_DSTATE = rtb_DataTypeConversion_opjm;
    }

    /* End of Switch: '<S37>/Switch1' */
  }

  /* End of Switch: '<S37>/Switch' */

  /* Sum: '<S23>/Add' incorporates:
   *  DataTypeConversion: '<S37>/Data Type Conversion1'
   *  UnitDelay: '<S37>/Unit Delay'
   */
  rtb_sum_trq = (Int16)(Fv_TOCShortTrq + ((Int16)asr_s32
    (TorqueOffsetComprtDW.UnitDelay_DSTATE, 13U)));

  /* UnaryMinus: '<S23>/Unary Minus' incorporates:
   *  Constant: '<S23>/Constant1'
   */
  rtb_UnaryMinus = (Int16)(-Cal_TOC_MaxCompTrq);

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S23>/Constant3'
   *  RelationalOperator: '<S38>/LowerRelop1'
   *  RelationalOperator: '<S38>/UpperRelop'
   *  Switch: '<S38>/Switch'
   */
  if (rtb_sum_trq > Cal_TOC_MaxCompTrq) {
    Fv_TOCCompTrq = Cal_TOC_MaxCompTrq;
  } else if (rtb_sum_trq < rtb_UnaryMinus) {
    /* Switch: '<S38>/Switch' */
    Fv_TOCCompTrq = rtb_UnaryMinus;
  } else {
    Fv_TOCCompTrq = rtb_sum_trq;
  }

  /* End of Switch: '<S38>/Switch2' */
}

/* Output and update for enable system: '<S4>/toc_trq_sty' */
void TorqueOffsetComp_toc_trq_sty(void)
{
  Int32 rtb_UnaryMinus;
  Int32 rtb_Constant3_cirr_tmp;

  /* Outputs for Enabled SubSystem: '<S4>/toc_trq_sty' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  if (TorqueOffsetComprtDW.study_calc) {
    /* Chart: '<S24>/toc_sch' incorporates:
     *  Constant: '<S40>/Constant1'
     *  Constant: '<S40>/Constant3'
     */
    /* Gateway: TestSub/TorqueOffsetComp_TrqCalc/toc_trq_sty/toc_sch */
    /* During: TestSub/TorqueOffsetComp_TrqCalc/toc_trq_sty/toc_sch */
    /* Entry Internal: TestSub/TorqueOffsetComp_TrqCalc/toc_trq_sty/toc_sch */
    /* Transition: '<S39>:103' */
    if (((UInt16)TorqueOffsetComprtDW.toc_cnt) < Cal_TOC_LongFilterTick) {
      /* Transition: '<S39>:102' */
      /* Transition: '<S39>:96' */
      TorqueOffsetComprtDW.toc_cnt = (UInt8)((Int32)(((Int32)
        TorqueOffsetComprtDW.toc_cnt) + 1));
    } else {
      /* Transition: '<S39>:105' */
      TorqueOffsetComprtDW.toc_cnt = 0U;

      /* Outputs for Function Call SubSystem: '<S24>/toc_sty' */
      /* Sum: '<S40>/Add1' incorporates:
       *  Constant: '<S40>/Constant'
       *  DataTypeConversion: '<S40>/Data Type Conversion1'
       *  Product: '<S40>/Product'
       *  Sum: '<S40>/Add'
       *  UnitDelay: '<S40>/delay'
       */
      /* Event: '<S39>:100' */
      TorqueOffsetComprtDW.delay_DSTATE += (Int32)asr_s64(((int64_T)
        Cal_TOC_LongFiltCoef) * ((int64_T)((Int16)(Fv_TOCCompTrq - ((Int16)
        asr_s32(TorqueOffsetComprtDW.delay_DSTATE, 13U))))), 5U);
      rtb_Constant3_cirr_tmp = ((Int32)Cal_TOC_MaxLongTrq) * 8192;

      /* UnaryMinus: '<S40>/Unary Minus' incorporates:
       *  Constant: '<S40>/Constant1'
       *  Constant: '<S40>/Constant3'
       */
      rtb_UnaryMinus = -rtb_Constant3_cirr_tmp;

      /* Switch: '<S41>/Switch2' incorporates:
       *  Constant: '<S40>/Constant3'
       *  RelationalOperator: '<S41>/LowerRelop1'
       *  RelationalOperator: '<S41>/UpperRelop'
       *  Switch: '<S41>/Switch'
       *  UnitDelay: '<S40>/delay'
       */
      if (TorqueOffsetComprtDW.delay_DSTATE > rtb_Constant3_cirr_tmp) {
        TorqueOffsetComprtDW.delay_DSTATE = rtb_Constant3_cirr_tmp;
      } else {
        if (TorqueOffsetComprtDW.delay_DSTATE < rtb_UnaryMinus) {
          /* Switch: '<S41>/Switch' incorporates:
           *  UnitDelay: '<S40>/delay'
           */
          TorqueOffsetComprtDW.delay_DSTATE = rtb_UnaryMinus;
        }
      }

      /* End of Switch: '<S41>/Switch2' */

      /* DataTypeConversion: '<S40>/Data Type Conversion3' incorporates:
       *  UnitDelay: '<S40>/delay'
       */
      Fv_TOCLongStyTrq = (Int16)asr_s32(TorqueOffsetComprtDW.delay_DSTATE, 13U);

      /* End of Outputs for SubSystem: '<S24>/toc_sty' */
      /* Transition: '<S39>:110' */
    }

    /* End of Chart: '<S24>/toc_sch' */
  }

  /* End of Outputs for SubSystem: '<S4>/toc_trq_sty' */
}

/* Output and update for atomic system: '<S1>/TorqueOffsetComp_TrqCalc' */
void Torque_TorqueOffsetComp_TrqCalc(void)
{
  /* Outputs for Atomic SubSystem: '<S4>/toc_cond_judge' */
  TorqueOffsetComp_toc_cond_judge();

  /* End of Outputs for SubSystem: '<S4>/toc_cond_judge' */

  /* Outputs for Atomic SubSystem: '<S4>/toc_trq_calc' */
  TorqueOffsetComp_toc_trq_calc();

  /* End of Outputs for SubSystem: '<S4>/toc_trq_calc' */

  /* Outputs for Atomic SubSystem: '<S4>/toc_trq_out' */
  TorqueOffsetComp_toc_trq_out();

  /* End of Outputs for SubSystem: '<S4>/toc_trq_out' */

  /* Outputs for Enabled SubSystem: '<S4>/toc_trq_sty' */
  TorqueOffsetComp_toc_trq_sty();

  /* End of Outputs for SubSystem: '<S4>/toc_trq_sty' */
}

/* System initialize for referenced model: 'TorqueOffsetComp' */
void TorqueOffsetComp_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/TorqueOffsetComp_StateMng' */
  TorqueOffsetComp_StateMng_Init();
  TorqueOffsetComprtDW.delay_DSTATE = (Int32)Fv_TOCInitStyTrq*8192;
  /* End of SystemInitialize for SubSystem: '<S1>/TorqueOffsetComp_StateMng' */
}

/* Output and update for referenced model: 'TorqueOffsetComp' */
void TorqueOffsetComp(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/TorqueOffsetComp_PreProcess' */
  Fv_TOCShortFuncFbd = /*(fsSCUGearPosion != GearStatus_D)
                       ||*/(fsEPSCloseLoopCtrlFlag > 0)||(Fv_LKA_ControlSts == 2)
                       ||(Fv_LKAAC_ControlSts == 2)||(Fv_DST_ControlSts == 2)
                       ||(Fv_LDW_ControlSts > 0) || (Fv_DSR_ControlSts == 2) || (Cal_TOC_Enable == 0);
  Fv_TOCLongFuncFbd = 1;
  // Fv_TOCLongFuncFbd = (fsSCUGearPosion != GearStatus_D)
  //                     ||(fsEPSCloseLoopCtrlFlag > 0)||(Fv_LKA_ControlSts == 2)
  //                     ||(Fv_LKAAC_ControlSts == 2)||(Fv_DST_ControlSts == 2)
  //                     ||(Fv_LDW_ControlSts > 0);

  {
    Int16 yaw_rate_limit = 0;
  	yaw_rate_limit = look1_is16ls32n10ts16D_fwsiRw8g(Fv_VehSpd, ((const
	    Int16 *)&(Cal_TOC_VsYawRate_X[0])), ((const Int16 *)&(Cal_TOC_VsYawRate_Y[0])), 7U);

    Fv_TOCYawRateCond = (((Fv_TOC_MsgInvalidFlag == FALSE)\
    		&&((fsVechYawRate <= yaw_rate_limit)&&(fsVechYawRate >= -yaw_rate_limit)))\
    		||(Fv_TOCYawCondFbd));
  }

  Tor_TorqueOffsetComp_PreProcess();

  /* End of Outputs for SubSystem: '<S1>/TorqueOffsetComp_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S1>/TorqueOffsetComp_StateMng' */
  Torqu_TorqueOffsetComp_StateMng();

  /* End of Outputs for SubSystem: '<S1>/TorqueOffsetComp_StateMng' */

  /* Outputs for Atomic SubSystem: '<S1>/TorqueOffsetComp_TrqCalc' */
  Torque_TorqueOffsetComp_TrqCalc();

  /* End of Outputs for SubSystem: '<S1>/TorqueOffsetComp_TrqCalc' */
}

void ClearTOCTrqueVaue(void)
{
  TorqueOffsetComprtDW.delay_DSTATE = 0;
}
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
