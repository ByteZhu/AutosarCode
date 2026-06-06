/*
 * File: SuportFunc_ShimmyComp.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.1560
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Oct 26 12:24:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SuportFunc_ShimmyComp.h"

/* Include model header file for global data */
#include "SuportFunc.h"
//#include "asr_s32.h"
#include "look1_is16ls16n7Ds32_plinlcas.h"
#include "look2_is16s16ls32n10ts_mOyVHgzB.h"
#include "look2_is16u16bu16u16ls_zZG6Z6JH.h"
#include "look2_is16u16ls32n10ts_TlwpcxFz.h"
#include "CalVarExt.h"
#include "GlobalVar_EXT.h"

#define asr_s32(X,Y)  ((X) >> (Y))

DW_EXT rtDW_EXT;

/* Constant parameters (default storage) */
const ConstP_dfsm rtConstP_dfsm = {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S236>/shiFreqLookup'
   *   '<S236>/shiGainLookup'
   *   '<S236>/shiGainLookup1'
   *   '<S236>/shiGainLookup2'
   *   '<S236>/shiWidthLookup'
   *   '<S236>/shiWidthLookup1'
   *   '<S38>/apalooktab_ki'
   *   '<S38>/apalooktab_kp'
   *   '<S66>/apalooktab_ki'
   *   '<S66>/apalooktab_kp'
   *   '<S141>/lkalooktab_ki'
   *   '<S141>/lkalooktab_kp'
   */
  { 7U, 2U },
};
/* Named constants for Chart: '<S235>/WaveControl_Frez' */
#define IN_NGrid                       ((UInt8)1U)
#define IN_Normal                      ((UInt8)1U)
#define IN_PGrid                       ((UInt8)2U)
#define IN_Wave                        ((UInt8)2U)
#define IN_default                     ((UInt8)3U)

/* Output and update for atomic system: '<S228>/SHIControl_Cond' */
void SHIControl_Cond(void)
{
  /* Logic: '<S230>/Logical Operator15' incorporates:
   *  Constant: '<S232>/Constant'
   *  Constant: '<S233>/Constant'
   *  Constant: '<S234>/Constant'
   *  DataStoreRead: '<S230>/Data Store Read1'
   *  DataStoreRead: '<S230>/Data Store Read21'
   *  DataStoreRead: '<S230>/Data Store Read22'
   *  DataTypeConversion: '<S230>/Data Type Conversion'
   *  RelationalOperator: '<S232>/Compare'
   *  RelationalOperator: '<S233>/Compare'
   *  RelationalOperator: '<S234>/Compare'
   */
  rtDW_EXT.LogicalOperator15 = (((((Int32)Fv_VehSpdNew) >= ((Int32)
    Cal_SHI_AllowedVSpd)) && (Fv_AbsInvalidFlag == false)) && (((Int32)
    Fv_AngleMidValidFlag) == ((Int32)1U)));
}

/* Output and update for atomic system: '<S228>/SHIControl_Trq' */
void SHIControl_Trq(void)
{
  UInt16 b_index;
  Float64 rtb_F;
  Float64 rtb_F2;
  Float64 rtb_Product5;
  Float64 rtb_u000F_ietx;
  Float64 rtb_Product;
  Float64 rtb_Product1;
  Float64 rtb_Product3;
  Int32 rtb_Constant_bjex;
  Int32 rtb_Divide1;
  Int16 rtb_Add_fkxx;
  Int16 rtb_UnaryMinus2;
  Int16 rtb_shiGainLookup1;

  /* Abs: '<S236>/Abs' incorporates:
   *  DataStoreRead: '<S236>/Data Store Read1'
   */
  if (Tv_dStrAng < 0) {
    rtb_UnaryMinus2 = (Int16)(-Tv_dStrAng);
  } else {
    rtb_UnaryMinus2 = Tv_dStrAng;
  }

  /* End of Abs: '<S236>/Abs' */

  /* Lookup_n-D: '<S236>/shiFreqLookup' incorporates:
   *  DataStoreRead: '<S236>/Data Store Read21'
   */
  rtb_F = look2_is16u16bu16u16ls_zZG6Z6JH(rtb_UnaryMinus2, Fv_VehSpdNew, ((const
    UInt16 *)&(Cal_SHI_Freq_Tab_dAng[0])), ((const UInt16 *)
    &(Cal_SHI_Freq_Tab_Vs[0])), ((const Float64 *)&(Cal_SHI_Freq_Tab_Out[0])),
    rtDW_EXT.m_bpIndex, rtConstP_dfsm.pooled9, 8U);

  /* Gain: '<S247>/Gain' */
  rtb_F *= 6.2831853071795862;

  /* Math: '<S247>/Square' */
  rtb_F2 = rtb_F * rtb_F;

  /* Lookup_n-D: '<S236>/shiWidthLookup1' incorporates:
   *  DataStoreRead: '<S236>/Data Store Read21'
   */
  rtb_Product5 = look2_is16u16bu16u16ls_zZG6Z6JH(rtb_UnaryMinus2, Fv_VehSpdNew, ((
    const UInt16 *)&(Cal_SHI_Depth_Tab_dAng[0])), ((const UInt16 *)
    &(Cal_SHI_Depth_Tab_Vs[0])), ((const Float64 *)&(Cal_SHI_Depth_Tab_Out[0])),
    rtDW_EXT.m_bpIndex_jvcx, rtConstP_dfsm.pooled9, 8U);

  /* Product: '<S247>/Product5' incorporates:
   *  Gain: '<S247>/Gain1'
   */
  rtb_Product5 = rtb_F * (4000.0 * rtb_Product5);

  /* Bias: '<S247>/Bias1' incorporates:
   *  Gain: '<S247>/Gain2'
   */
  rtb_u000F_ietx = (2.0 * rtb_F2) + (-8.0E+6);

  /* Product: '<S247>/Product' incorporates:
   *  Delay: '<S247>/Delay'
   */
  rtb_Product = rtDW_EXT.Delay_DSTATE * rtb_u000F_ietx;

  /* Delay: '<S247>/Delay1' incorporates:
   *  Delay: '<S247>/Delay'
   */
  rtDW_EXT.Delay_DSTATE = rtDW_EXT.Delay1_DSTATE[0];

  /* Product: '<S247>/Product1' incorporates:
   *  Bias: '<S247>/Bias2'
   *  Delay: '<S247>/Delay'
   *  Sum: '<S247>/Subtract1'
   */
  rtb_Product1 = rtDW_EXT.Delay_DSTATE * ((rtb_F2 - rtb_Product5) + 4.0E+6);

  /* Delay: '<S247>/Delay3' incorporates:
   *  Delay: '<S247>/Delay'
   */
  rtDW_EXT.Delay_DSTATE = rtDW_EXT.Delay3_DSTATE;

  /* Product: '<S247>/Product3' incorporates:
   *  Delay: '<S247>/Delay'
   */
  rtb_Product3 = rtb_u000F_ietx * rtDW_EXT.Delay_DSTATE;

  /* Lookup_n-D: '<S236>/shiWidthLookup' incorporates:
   *  DataStoreRead: '<S236>/Data Store Read21'
   */
  rtb_u000F_ietx = look2_is16u16bu16u16ls_zZG6Z6JH(rtb_UnaryMinus2, Fv_VehSpdNew,
    ((const UInt16 *)&(Cal_SHI_Width_Tab_dAng[0])), ((const UInt16 *)
    &(Cal_SHI_Width_Tab_Vs[0])), ((const Float64 *)&(Cal_SHI_Width_Tab_Out[0])),
    rtDW_EXT.m_bpIndex_nzfg, rtConstP_dfsm.pooled9, 8U);

  /* Product: '<S247>/Product6' incorporates:
   *  Gain: '<S247>/Gain3'
   *  Gain: '<S247>/Gain4'
   */
  rtb_u000F_ietx = (4000.0 * rtb_F) * (6.2831853071795862 * rtb_u000F_ietx);

  /* Delay: '<S247>/Delay2' incorporates:
   *  Delay: '<S247>/Delay'
   */
  rtDW_EXT.Delay_DSTATE = rtDW_EXT.Delay2_DSTATE[0];

  /* Product: '<S247>/Divide' incorporates:
   *  Bias: '<S247>/Bias'
   *  Bias: '<S247>/Bias3'
   *  Bias: '<S247>/Bias4'
   *  DataStoreRead: '<S236>/Data Store Read2'
   *  DataTypeConversion: '<S236>/conv1'
   *  DataTypeConversion: '<S248>/FixPt Gateway Out'
   *  Delay: '<S247>/Delay'
   *  Delay: '<S247>/Delay3'
   *  Product: '<S247>/Product2'
   *  Product: '<S247>/Product4'
   *  Sum: '<S247>/Add'
   *  Sum: '<S247>/Subtract'
   *  Sum: '<S247>/Subtract2'
   *  Sum: '<S247>/Subtract3'
   */
  rtDW_EXT.Delay3_DSTATE = (((((((Float64)Tv_StrTrq0Orig) * ((rtb_F2 +
    rtb_Product5) + 4.0E+6)) + rtb_Product) + rtb_Product1) - rtb_Product3) -
    (((rtb_F2 - rtb_u000F_ietx) + 4.0E+6) * rtDW_EXT.Delay_DSTATE)) / ((rtb_F2
    + rtb_u000F_ietx) + 4.0E+6);

  /* Gain: '<S236>/Gain1' incorporates:
   *  DataTypeConversion: '<S236>/conv2'
   *  Delay: '<S247>/Delay3'
   */
  rtb_Divide1 = (Int32)rtDW_EXT.Delay3_DSTATE;

  /* Saturate: '<S236>/Saturation1' */
  if (rtb_Divide1 > 16384) {
    rtb_Divide1 = 16384;
  } else {
    if (rtb_Divide1 < (-16384)) {
      rtb_Divide1 = (-16384);
    }
  }

  /* End of Saturate: '<S236>/Saturation1' */

  /* DataTypeConversion: '<S236>/conv8' incorporates:
   *  DataStoreWrite: '<S236>/Data Store Write1'
   */
  Fv_ShimmyNotchTrq = (Int16)rtb_Divide1;
#if 0
  /* Sum: '<S236>/Add' incorporates:
   *  DataStoreRead: '<S236>/Data Store Read2'
   *  DataStoreWrite: '<S236>/Data Store Write1'
   */
  rtb_Add_fkxx = (Int16)(((Int16)(asr_s32((Int32)Tv_StrTrq0Orig, 10U) - asr_s32
    ((Int32)Fv_ShimmyNotchTrq, 10U))) * 1024);
#else
  rtb_Add_fkxx = Tv_StrTrq0Orig - Fv_ShimmyNotchTrq;

#endif
  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S236>/Constant1'
   *  RelationalOperator: '<S245>/u_GTE_up'
   */
  if (rtb_Add_fkxx >= Cal_SHI_ShimmyDeadTrq) {
    rtb_UnaryMinus2 = Cal_SHI_ShimmyDeadTrq;
  } else {
    /* UnaryMinus: '<S236>/Unary Minus2' incorporates:
     *  Constant: '<S236>/Constant2'
     */
    rtb_UnaryMinus2 = (Int16)(-Cal_SHI_ShimmyDeadTrq);

    /* Switch: '<S245>/Switch1' incorporates:
     *  RelationalOperator: '<S245>/u_GT_lo'
     */
    if (rtb_Add_fkxx > rtb_UnaryMinus2) {
      rtb_UnaryMinus2 = rtb_Add_fkxx;
    }

    /* End of Switch: '<S245>/Switch1' */
  }

  /* End of Switch: '<S245>/Switch' */

  /* Sum: '<S245>/Diff' */
  Fv_ShimmyTrq = (Int16)(rtb_Add_fkxx - rtb_UnaryMinus2);
  //debug_jing[0] = Fv_ShimmyTrq;
  /* Chart: '<S235>/WaveControl_Frez' incorporates:
   *  Constant: '<S235>/Constant2'
   *  Constant: '<S235>/Constant4'
   *  DataStoreRead: '<S235>/Data Store Read2'
   */
  /* Gateway: SuportFunc_ShimmyComp/SHIControl/SHIControl_Atomic/SHIControl_Trq/SHI_FreqDetect/WaveControl_Frez */
  /* During: SuportFunc_ShimmyComp/SHIControl/SHIControl_Atomic/SHIControl_Trq/SHI_FreqDetect/WaveControl_Frez */
  if (((UInt32)rtDW_EXT.bitsForTID0.is_active_c43_SuportFunc) == 0U) {
    /* Entry: SuportFunc_ShimmyComp/SHIControl/SHIControl_Atomic/SHIControl_Trq/SHI_FreqDetect/WaveControl_Frez */
    rtDW_EXT.bitsForTID0.is_active_c43_SuportFunc = 1;

    /* Entry Internal: SuportFunc_ShimmyComp/SHIControl/SHIControl_Atomic/SHIControl_Trq/SHI_FreqDetect/WaveControl_Frez */
    /* Entry 'WaveCalc': '<S244>:2' */
    rtDW_EXT.WaveState = 0U;
    rtDW_EXT.WaveTmrCnt = 0U;

    /* Entry Internal 'WaveCalc': '<S244>:2' */
    /* Transition: '<S244>:43' */
    rtDW_EXT.bitsForTID0.is_WaveCalc = IN_Normal;

    /* Entry 'Normal': '<S244>:3' */
    rtDW_EXT.WaveTime = 200U;
    rtDW_EXT.InterTmr = 0U;
    rtDW_EXT.detectCnt = 0U;
    rtDW_EXT.trqValueDiff = 0;
    rtDW_EXT.trqValueDwn = 0;
    rtDW_EXT.trqValueUp = 0;
  } else {
    /* During 'GridCalc': '<S244>:1' */
    /* Transition: '<S244>:138' */
    rtb_Divide1 = ((Int32)Cal_SHI_FreqDetGridWindowPoint) - 1;
    b_index = (UInt16)rtb_Divide1;
    while (((Int32)b_index) > 0) {
      /* Transition: '<S244>:142' */
      rtb_Constant_bjex = ((Int32)b_index) - 1;
      rtDW_EXT.D[b_index] = rtDW_EXT.D[rtb_Constant_bjex];
      b_index = (UInt16)rtb_Constant_bjex;
    }
    /*?????1???????rtDW_EXT.D[0]
     * ????????????????????rtDW_EXT.D[1]
     * ???????(???1ms)??????????????rtDW_EXT.D[9]
     *  */
    /* Transition: '<S244>:147' */


    rtDW_EXT.D[0] = Tv_StrTrq0Orig;

    /* Transition: '<S244>:149' */
    /* During 'WaveCalc': '<S244>:2' */
    rtb_Divide1 = ((Int32)rtDW_EXT.D[rtb_Divide1]) - ((Int32)Tv_StrTrq0Orig);
    if (rtb_Divide1 < 0) {
      rtDW_EXT.SpdGrid = (Int16)(-rtb_Divide1);
    } else {
      rtDW_EXT.SpdGrid = (Int16)rtb_Divide1;
    }

    if (((UInt32)rtDW_EXT.bitsForTID0.is_WaveCalc) == IN_Normal) {
      /* During 'Normal': '<S244>:3' */
      if (rtDW_EXT.SpdGrid >= Cal_SHI_FreqDetGrid) {
        /* Transition: '<S244>:44' */
        rtDW_EXT.bitsForTID0.is_WaveCalc = IN_Wave;

        /* Entry Internal 'Wave': '<S244>:4' */
        /* Entry Internal 'Process': '<S244>:8' */
        /* Transition: '<S244>:46' */
        rtDW_EXT.bitsForTID0.is_Process = IN_default;

        /* Entry 'default': '<S244>:5' */
        rtDW_EXT.WaveTmrCnt = 0U;
        rtDW_EXT.WaveState = 0U;
      }
    } else {
      /* During 'Wave': '<S244>:4' */
      if ((rtDW_EXT.SpdGrid < Cal_SHI_FreqDetGrid) && (((Int32)
            rtDW_EXT.InterTmr) >= 200)) {
        /* Transition: '<S244>:45' */
        /* Exit Internal 'Wave': '<S244>:4' */
        /* Exit Internal 'Process': '<S244>:8' */
        rtDW_EXT.bitsForTID0.is_Process = 0;
        rtDW_EXT.bitsForTID0.is_WaveCalc = IN_Normal;

        /* Entry 'Normal': '<S244>:3' */
        rtDW_EXT.WaveTime = 200U;
        rtDW_EXT.InterTmr = 0U;
        rtDW_EXT.detectCnt = 0U;
        rtDW_EXT.trqValueDiff = 0;
        rtDW_EXT.trqValueDwn = 0;
        rtDW_EXT.trqValueUp = 0;
      } else {
        /* During 'Timer': '<S244>:9' */
        /* Transition: '<S244>:61' */
        if (rtDW_EXT.SpdGrid < Cal_SHI_FreqDetGrid) {
          /* Transition: '<S244>:62' */
          rtDW_EXT.InterTmr = (UInt16)((Int32)(((Int32)rtDW_EXT.InterTmr) + 1));
        } else {
          /* Transition: '<S244>:63' */
          rtDW_EXT.InterTmr = 0U;
        }

        if (((Int32)rtDW_EXT.InterTmr) >= 200) {
          /* Transition: '<S244>:64' */
          rtDW_EXT.InterTmr = 200U;
        } else {
          /* Transition: '<S244>:65' */
        }

        /* During 'Process': '<S244>:8' */
        switch (rtDW_EXT.bitsForTID0.is_Process) {
         case IN_NGrid:
          /* During 'NGrid': '<S244>:6' */
          if (rtb_Divide1 >= 0) {
            /* Transition: '<S244>:50' */
            rtDW_EXT.trqValueUp = Tv_StrTrq0Orig;
            rtDW_EXT.bitsForTID0.is_Process = IN_PGrid;
          } else {
            /* Transition: '<S244>:55' */
            rtDW_EXT.WaveTmrCnt = (UInt16)((Int32)(((Int32)rtDW_EXT.WaveTmrCnt)
              + 1));
            if (((Int32)rtDW_EXT.WaveTmrCnt) >= 200) {
              /* Transition: '<S244>:56' */
              /* Transition: '<S244>:57' */
              rtDW_EXT.WaveTmrCnt = 200U;

              /* Transition: '<S244>:58' */
            } else {
              /* Transition: '<S244>:59' */
            }

            /* Transition: '<S244>:60' */
          }
          break;

         case IN_PGrid:
          /* During 'PGrid': '<S244>:7' */
          if (rtb_Divide1 < 0) {
            /* Transition: '<S244>:49' */
            rtDW_EXT.trqValueDwn = Tv_StrTrq0Orig;
            rtDW_EXT.bitsForTID0.is_Process = IN_NGrid;

            /* Entry 'NGrid': '<S244>:6' */
            rtDW_EXT.WaveState = 1U;
          } else {
            /* Transition: '<S244>:51' */
            if (((Int32)rtDW_EXT.WaveState) == 1) {
              /* Transition: '<S244>:154' */
              if (((Int32)rtDW_EXT.detectCnt) < 3) {
                /* Transition: '<S244>:155' */
                rtDW_EXT.detectCnt = (UInt16)((Int32)(((Int32)
                  rtDW_EXT.detectCnt) + 1));
              } else {
                /* Transition: '<S244>:156' */
                rtDW_EXT.WaveTime = rtDW_EXT.WaveTmrCnt;
                rtb_Divide1 = ((Int32)rtDW_EXT.trqValueDwn) - ((Int32)
                  rtDW_EXT.trqValueUp);
                if (rtb_Divide1 < 0) {
                  rtDW_EXT.trqValueDiff = (Int16)(-rtb_Divide1);
                } else {
                  rtDW_EXT.trqValueDiff = (Int16)rtb_Divide1;
                }
              }
            } else {
              /* Transition: '<S244>:54' */
            }

            /* Transition: '<S244>:53' */
            rtDW_EXT.WaveState = 2U;
            rtDW_EXT.WaveTmrCnt = 0U;
          }
          break;

         default:
          /* During 'default': '<S244>:5' */
          if (rtb_Divide1 < 0) {
            /* Transition: '<S244>:47' */
            rtDW_EXT.bitsForTID0.is_Process = IN_NGrid;

            /* Entry 'NGrid': '<S244>:6' */
            rtDW_EXT.WaveState = 1U;
          } else {
            /* Transition: '<S244>:48' */
            rtDW_EXT.bitsForTID0.is_Process = IN_PGrid;
          }
          break;
        }
      }
    }
  }

  /* End of Chart: '<S235>/WaveControl_Frez' */

  /* Switch: '<S242>/Switch2' incorporates:
   *  Constant: '<S235>/Constant1'
   *  Constant: '<S235>/Constant5'
   *  RelationalOperator: '<S242>/LowerRelop1'
   *  RelationalOperator: '<S242>/UpperRelop'
   *  Switch: '<S242>/Switch'
   */
  if (rtDW_EXT.WaveTime > ((UInt16)Cal_SHI_FreqDetGridWaveTimeHigh)) {
    b_index = (UInt16)Cal_SHI_FreqDetGridWaveTimeHigh;
  } else if (rtDW_EXT.WaveTime < ((UInt16)Cal_SHI_FreqDetGridWaveTimeLow)) {
    /* Switch: '<S242>/Switch' incorporates:
     *  Constant: '<S235>/Constant5'
     */
    b_index = (UInt16)Cal_SHI_FreqDetGridWaveTimeLow;
  } else {
    b_index = rtDW_EXT.WaveTime;
  }

  /* End of Switch: '<S242>/Switch2' */

  /* Sum: '<S235>/Subtract' incorporates:
   *  DataTypeConversion: '<S235>/Data Type Conversion'
   *  Delay: '<S235>/Delay1'
   */
  rtb_Divide1 = ((Int32)((UInt32)(((UInt32)b_index) << 10))) -
    rtDW_EXT.Delay1_DSTATE_gcyu;

  /* UnaryMinus: '<S235>/Unary Minus2' incorporates:
   *  Constant: '<S235>/Constant8'
   */
  rtb_Constant_bjex = -Cal_SHI_FreqDetGridDecreaseStep;

  /* Switch: '<S243>/Switch2' incorporates:
   *  Constant: '<S235>/Constant7'
   *  RelationalOperator: '<S243>/LowerRelop1'
   *  RelationalOperator: '<S243>/UpperRelop'
   *  Switch: '<S243>/Switch'
   */
  if (rtb_Divide1 > Cal_SHI_FreqDetGridIncreaseStep) {
    rtb_Divide1 = Cal_SHI_FreqDetGridIncreaseStep;
  } else {
    if (rtb_Divide1 < rtb_Constant_bjex) {
      /* Switch: '<S243>/Switch' */
      rtb_Divide1 = rtb_Constant_bjex;
    }
  }

  /* End of Switch: '<S243>/Switch2' */

  /* Sum: '<S235>/Add2' incorporates:
   *  Delay: '<S235>/Delay1'
   */
  rtDW_EXT.Delay1_DSTATE_gcyu += rtb_Divide1;

  /* DataTypeConversion: '<S235>/Data Type Conversion2' incorporates:
   *  DataStoreWrite: '<S235>/Data Store Write2'
   *  Delay: '<S235>/Delay1'
   */
  Fv_SHI_FreqDetValue = (Int16)asr_s32(rtDW_EXT.Delay1_DSTATE_gcyu, 3U);

  /* Abs: '<S235>/Abs4' incorporates:
   *  DataStoreRead: '<S235>/Data Store Read5'
   */
  /* Gateway: SuportFunc_ShimmyComp/SHIControl/SHIControl_Atomic/SHIControl_Trq/SHI_FreqDetect/FreqQuitLogic1 */
  /* During: SuportFunc_ShimmyComp/SHIControl/SHIControl_Atomic/SHIControl_Trq/SHI_FreqDetect/FreqQuitLogic1 */
  /* Entry Internal: SuportFunc_ShimmyComp/SHIControl/SHIControl_Atomic/SHIControl_Trq/SHI_FreqDetect/FreqQuitLogic1 */
  /* Transition: '<S241>:164' */
  if (Tv_StrAng_Raw < 0) {
    rtb_UnaryMinus2 = (Int16)(-Tv_StrAng_Raw);
  } else {
    rtb_UnaryMinus2 = Tv_StrAng_Raw;
  }

  /* End of Abs: '<S235>/Abs4' */

  /* Abs: '<S235>/Abs3' incorporates:
   *  DataStoreRead: '<S235>/Data Store Read4'
   */
  if (Fv_dRotorAng < 0) {
    rtb_Divide1 = -Fv_dRotorAng;
  } else {
    rtb_Divide1 = Fv_dRotorAng;
  }
  rtb_Divide1 = 100;

  /* End of Abs: '<S235>/Abs3' */

  /* Abs: '<S235>/Abs2' incorporates:
   *  DataStoreRead: '<S235>/Data Store Read1'
   */
  if (Tv_StrTrq0Orig < 0) {
    rtb_Add_fkxx = (Int16)(-Tv_StrTrq0Orig);
  } else {
    rtb_Add_fkxx = Tv_StrTrq0Orig;
  }

  /* End of Abs: '<S235>/Abs2' */

  /* Chart: '<S235>/FreqQuitLogic1' incorporates:
   *  Constant: '<S237>/Constant'
   *  Constant: '<S238>/Constant'
   *  Constant: '<S239>/Constant'
   *  Constant: '<S240>/Constant'
   *  DataStoreRead: '<S235>/Data Store Read3'
   *  Logic: '<S235>/Logical Operator1'
   *  RelationalOperator: '<S237>/Compare'
   *  RelationalOperator: '<S238>/Compare'
   *  RelationalOperator: '<S239>/Compare'
   *  RelationalOperator: '<S240>/Compare'
   */
  if ((((rtb_UnaryMinus2 >= Cal_SHI_FreqDetShutAng) || (rtb_Divide1 >= (((Int32)
           Cal_SHI_FreqDetShutdAng) * 64))) || (rtb_Add_fkxx >=
        Cal_SHI_FreqDetShutTrq)) || (Fv_SHI_FreqDetGrid >=
       Cal_SHI_FreqDetShutGrid)) {
    /* Transition: '<S241>:166' */
    /* Transition: '<S241>:168' */
    rtDW_EXT.enable = 0;
    rtDW_EXT.entrycnt = 600U;
  } else {
    /* Transition: '<S241>:170' */
    if (((Int32)rtDW_EXT.entrycnt) > 0) {
      /* Transition: '<S241>:172' */
      /* Transition: '<S241>:174' */
      rtDW_EXT.entrycnt = (UInt16)((Int32)(((Int32)rtDW_EXT.entrycnt) - 1));
    } else {
      /* Transition: '<S241>:176' */
      rtDW_EXT.enable = 128;

      /* Transition: '<S241>:177' */
    }

    /* Transition: '<S241>:178' */
  }
  //debug_jing2 = rtDW_EXT.enable;
  
  //debug_jing[1] = (rtb_UnaryMinus2 >= Cal_SHI_FreqDetShutAng) |( (rtb_Divide1 >= (((Int32)Cal_SHI_FreqDetShutdAng) * 64)) << 1)|
	//	  ((rtb_Add_fkxx >=Cal_SHI_FreqDetShutTrq)<<2)|((Fv_SHI_FreqDetGrid >=Cal_SHI_FreqDetShutGrid)<<3);
  //debug_jing[2] = rtb_UnaryMinus2;
  //debug_jing[3] = Fv_SHI_FreqDetGrid;



  /* End of Chart: '<S235>/FreqQuitLogic1' */

  /* Lookup_n-D: '<S235>/shiGainLookup' incorporates:
   *  DataStoreWrite: '<S235>/Data Store Write2'
   *  DataStoreWrite: '<S235>/Data Store Write3'
   *  DataTypeConversion: '<S235>/Data Type Conversion4'
   *  Product: '<S235>/Divide2'
   */
/*???2???????,23.11.18 by zyg*/
#if 00
  Fv_SHI_FreqGain = look1_is16ls16n7Ds32_plinlcas((Int16)asr_s32(((Int32)
    Fv_SHI_FreqDetValue) * ((Int32)rtDW_EXT.enable), 7U), ((const Int16 *)
    &(Cal_SHI_FreqGain_X[0])), ((const Int16 *)&(Cal_SHI_FreqGain_Y[0])),
    &rtDW_EXT.m_bpIndex_df1p, 5U);
#else
  //Fv_SHI_FreqValue = 1000*2^5/(Fv_SHI_FreqDetValue*2/2^7)
  Fv_SHI_FreqValue = (Int16)(4096000/((Int32)Fv_SHI_FreqDetValue*2));//????????2^-5,????Hz

  /*Fv_SHI_FreqGain = (Int16)(((Int32)rtDW_EXT.enable)*(look1_is16ls16n7Ds32_plinlcas(Fv_SHI_FreqValue, ((const Int16 *)
      &(Cal_SHI_FreqGainNew_X[0])), ((const Int16 *)&(Cal_SHI_FreqGainNew_Y[0])),
      &rtDW_EXT.m_bpIndex_df1p_New, 14U))/128);*/
  Fv_SHI_FreqGain = (Int16)((look1_is16ls16n7Ds32_plinlcas(Fv_SHI_FreqValue, ((const Int16 *)
      &(Cal_SHI_FreqGainNew_X[0])), ((const Int16 *)&(Cal_SHI_FreqGainNew_Y[0])),
      &rtDW_EXT.m_bpIndex_df1p_New, 14U)));

#endif

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S236>/Constant'
   *  DataTypeConversion: '<S236>/conv6'
   */
  if (!rtDW_EXT.LogicalOperator15) {
    rtb_UnaryMinus2 = 0;
  } else {
    /* Lookup_n-D: '<S236>/shiGainLookup2' incorporates:
     *  DataStoreRead: '<S236>/Data Store Read4'
     *  DataStoreRead: '<S236>/Data Store Read5'
     */
    rtb_Add_fkxx = look2_is16s16ls32n10ts_mOyVHgzB(Tv_StrAng_Raw, Tv_StrTrq0Orig,
      ((const Int16 *)&(Cal_SHI_Gain2_Tab_Ang[0])), ((const Int16 *)
      &(Cal_SHI_Gain2_Tab_Trq[0])), ((const Int16 *)&(Cal_SHI_Gain2_Tab_Out[0])),
      rtDW_EXT.m_bpIndex_gr3m, rtConstP_dfsm.pooled9, 8U);

    /* Lookup_n-D: '<S236>/shiGainLookup1' incorporates:
     *  DataStoreRead: '<S236>/Data Store Read21'
     *  DataStoreRead: '<S236>/Data Store Read3'
     */
    rtb_shiGainLookup1 = look2_is16u16ls32n10ts_TlwpcxFz(Tv_dStrAng, Fv_VehSpdNew,
      ((const Int16 *)&(Cal_SHI_Gain_Tab_dAng[0])), ((const UInt16 *)
      &(Cal_SHI_Gain_Tab_Vs[0])), ((const Int16 *)&(Cal_SHI_Gain_Tab_Out_dAng[0])),
      rtDW_EXT.m_bpIndex_dqkw, rtConstP_dfsm.pooled9, 8U);

    /* Abs: '<S236>/Abs1' incorporates:
     *  DataStoreWrite: '<S236>/Data Store Write1'
     */
    if (Fv_ShimmyNotchTrq < 0) {
      rtb_UnaryMinus2 = (Int16)(-Fv_ShimmyNotchTrq);
    } else {
      rtb_UnaryMinus2 = Fv_ShimmyNotchTrq;
    }

    /* End of Abs: '<S236>/Abs1' */

    /* Lookup_n-D: '<S236>/shiGainLookup' incorporates:
     *  DataStoreRead: '<S236>/Data Store Read21'
     */
    rtb_UnaryMinus2 = look2_is16u16ls32n10ts_TlwpcxFz(rtb_UnaryMinus2,
      Fv_VehSpdNew, ((const Int16 *)&(Cal_SHI_Gain_Tab_Trq[0])), ((const UInt16 *)
      &(Cal_SHI_Gain_Tab_Vs[0])), ((const Int16 *)&(Cal_SHI_Gain_Tab_Out_Trq[0])),
      rtDW_EXT.m_bpIndex_pjqd, rtConstP_dfsm.pooled9, 8U);
#if 0
    /* DataTypeConversion: '<S236>/conv10' incorporates:
     *  DataTypeConversion: '<S236>/conv9'
     *  Product: '<S236>/Divide3'
     *  Product: '<S236>/Divide4'
     */
    rtb_Divide1 = ((Int32)((Int16)asr_s32(((Int32)rtb_UnaryMinus2) * ((Int32)
      rtb_shiGainLookup1), 7U))) * ((Int32)rtb_Add_fkxx);
    /* DataTypeConversion: '<S236>/conv11' incorporates:
     *  DataStoreWrite: '<S235>/Data Store Write3'
     *  DataTypeConversion: '<S236>/conv10'
     *  Product: '<S236>/Divide2'
     */
#endif
    rtb_Divide1 = (Int16)(((((((Int32)Fv_ShimmyTrq * (Int32)rtb_UnaryMinus2)/128)*(Int32)rtb_shiGainLookup1)/128)*(Int32)rtb_Add_fkxx)/128);
#if 0
    rtb_Divide1 = ((Int32)Fv_SHI_FreqGain) * ((Int32)((Int16)asr_s32(rtb_Divide1
      + ((rtb_Divide1 < 0) ? 127 : 0), 7U)));
#endif
    //rtb_Divide1 = (Int16)(((Int32)rtb_Divide1 * (Int32)Fv_SHI_FreqGain)/128);
    rtb_Divide1 = (Int16)((Int32)rtDW_EXT.enable *(((Int32)rtb_Divide1 * (Int32)Fv_SHI_FreqGain)/128)/128);
    /* DataTypeConversion: '<S236>/conv6' incorporates:
     *  DataTypeConversion: '<S236>/conv11'
     *  Product: '<S236>/Divide'
     */
#if 0
    rtb_Divide1 = ((Int32)Fv_ShimmyTrq) * ((Int32)((Int16)asr_s32(rtb_Divide1 +
      ((rtb_Divide1 < 0) ? 127 : 0), 7U)));
    rtb_UnaryMinus2 = (Int16)asr_s32(rtb_Divide1 + ((rtb_Divide1 < 0) ? 1023 : 0),
      10U);
#else
    rtb_UnaryMinus2 = rtb_Divide1;
#endif
    
  }

  /* End of Switch: '<S236>/Switch' */

  /* DataTypeConversion: '<S236>/conv7' incorporates:
   *  Constant: '<S236>/Constant3'
   *  Product: '<S236>/Divide1'
   */
  rtb_Divide1 = ((Int32)rtb_UnaryMinus2) * ((Int32)Cal_SHI_TrqPlus);
  Fv_SHI_Torque = (Int16)((rtb_Divide1 / 128));
  //Fv_SHI_Torque = (Int16)asr_s32(rtb_Divide1 + ((rtb_Divide1 < 0) ? 127 : 0), 7U);

  /* UnaryMinus: '<S236>/Unary Minus1' incorporates:
   *  Constant: '<S236>/Constant5'
   */
  rtb_UnaryMinus2 = (Int16)(-Cal_SHI_MaxCompTrq);

  /* Switch: '<S246>/Switch2' incorporates:
   *  Constant: '<S236>/Constant4'
   *  DataStoreWrite: '<S236>/Data Store Write'
   *  RelationalOperator: '<S246>/LowerRelop1'
   *  RelationalOperator: '<S246>/UpperRelop'
   *  Switch: '<S246>/Switch'
   */
 if (rtDW_EXT.LogicalOperator15) {
    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S11>/Constant4'
     *  DataTypeConversion: '<S11>/conv15'
     *  RelationalOperator: '<S21>/LowerRelop1'
     *  RelationalOperator: '<S21>/UpperRelop'
     *  Switch: '<S21>/Switch'
     *  UnaryMinus: '<S11>/Unary Minus3'
     */
    if (Fv_SHI_Torque > Cal_SHI_MaxCompTrq) {
      Fv_SHI_Torque = Cal_SHI_MaxCompTrq;
    } else if (Fv_SHI_Torque < ((Int16)(-Cal_SHI_MaxCompTrq))) {
      /* Switch: '<S21>/Switch' incorporates:
       *  UnaryMinus: '<S11>/Unary Minus3'
       */
      Fv_SHI_Torque = (Int16)(-Cal_SHI_MaxCompTrq);
    } else {
      /* no actions */
    }
    
    /* End of Switch: '<S21>/Switch2' */
  } else {
    /* DataTypeConversion: '<S11>/conv15' incorporates:
     *  Constant: '<S11>/Constant6'
     */
    Fv_SHI_Torque = 0;
  }
  /* End of Switch: '<S246>/Switch2' */

  /* DataTypeConversion: '<S235>/Data Type Conversion10' incorporates:
   *  DataStoreWrite: '<S235>/Data Store Write'
   */
  Fv_SHI_FreqDetGrid = rtDW_EXT.SpdGrid;

  /* DataTypeConversion: '<S235>/Data Type Conversion9' incorporates:
   *  DataStoreWrite: '<S235>/Data Store Write1'
   */
  Fv_SHI_FreqDetDiff = rtDW_EXT.trqValueDiff;

  /* Update for Delay: '<S247>/Delay' incorporates:
   *  DataStoreRead: '<S236>/Data Store Read2'
   *  DataTypeConversion: '<S248>/FixPt Gateway Out'
   */
  rtDW_EXT.Delay_DSTATE = (Float64)Tv_StrTrq0Orig;

  /* Update for Delay: '<S247>/Delay1' incorporates:
   *  DataStoreRead: '<S236>/Data Store Read2'
   *  DataTypeConversion: '<S248>/FixPt Gateway Out'
   */
  rtDW_EXT.Delay1_DSTATE[0] = rtDW_EXT.Delay1_DSTATE[1];
  rtDW_EXT.Delay1_DSTATE[1] = (Float64)Tv_StrTrq0Orig;

  /* Update for Delay: '<S247>/Delay2' incorporates:
   *  Delay: '<S247>/Delay3'
   */
  rtDW_EXT.Delay2_DSTATE[0] = rtDW_EXT.Delay2_DSTATE[1];
  rtDW_EXT.Delay2_DSTATE[1] = rtDW_EXT.Delay3_DSTATE;
}

/* Output and update for atomic system: '<S4>/SHIControl' */
void SHIControl(void)
{
  /* If: '<S227>/If' incorporates:
   *  DataStoreRead: '<S227>/Data Store Read7'
   */

  Fv_SHI_Configuration = Cal_SHI_Enable;

  if (((Int32)Fv_SHI_Configuration) != 0) {
    /* Outputs for IfAction SubSystem: '<S227>/SHIControl_Atomic' incorporates:
     *  ActionPort: '<S228>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S228>/SHIControl_Cond' */
    SHIControl_Cond();

    /* End of Outputs for SubSystem: '<S228>/SHIControl_Cond' */

    /* DataTypeConversion: '<S228>/conv1' incorporates:
     *  DataStoreWrite: '<S228>/Data Store Write1'
     */
    Fv_SHI_ControlSts = (UInt8)(rtDW_EXT.LogicalOperator15 ? ((UInt8)1) :
      ((UInt8)0));

    /* Outputs for Atomic SubSystem: '<S228>/SHIControl_Trq' */
    SHIControl_Trq();

    /* End of Outputs for SubSystem: '<S228>/SHIControl_Trq' */
    /* End of Outputs for SubSystem: '<S227>/SHIControl_Atomic' */
  } else {
    /* Outputs for IfAction SubSystem: '<S227>/SHIControl_DisAtomic' incorporates:
     *  ActionPort: '<S229>/Action Port'
     */
    /* DataStoreWrite: '<S229>/Data Store Write' incorporates:
     *  Constant: '<S229>/Constant'
     */
    Fv_SHI_Torque = 0;

    /* DataStoreWrite: '<S229>/Data Store Write1' incorporates:
     *  Constant: '<S229>/Constant1'
     */
    Fv_SHI_ControlSts = ((UInt8)0U);

    /* End of Outputs for SubSystem: '<S227>/SHIControl_DisAtomic' */
  }

  /* End of If: '<S227>/If' */
}

/* Output and update for atomic system: '<Root>/SuportFunc_ShimmyComp' */
void SuportFunc_ShimmyComp(void)
{
  /* Outputs for Atomic SubSystem: '<S4>/SHIControl' */
  SHIControl();

  /* End of Outputs for SubSystem: '<S4>/SHIControl' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
