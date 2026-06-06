/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LQR.c
 *
 * Code generated for Simulink model 'LQR'.
 *
 * Model version                  : 251
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Sep 17 10:58:07 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "LQR.h"
#include "look1_iu16ls32n10tu16_pbinlcase.h"
//#include "look2_is16u16ls32n10ts_TlwpcxFz.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "GlobalVarSupport.h"

/*新增查表函数,240629 by zyg*/
Int32 asr_s32_1(Int32 u, UInt32 n)
{
  Int32 y;
  if (u >= 0) {
    y = (Int32)((UInt32)(((UInt32)u) >> n));
  } else {
    y = (-((Int32)((UInt32)(((UInt32)((Int32)(-1 - u))) >> n)))) - 1;
  }

  return y;
}

Int16 look2_is16u16ls32n10ts_TlwpcxFz_lqr(Int16 u0, UInt16 u1, const Int16
  bp0[], const UInt16 bp1[], const Int16 table[], UInt32 prevIndex[],
  const UInt32 maxIndex[], UInt32 stride)
{
  Int16 y;
  Int32 frac;
  UInt32 bpIndices[2];
  Int32 fractions[2];
  Int16 yR_1d;
  UInt32 offset_1d;
  UInt32 bpIdx;

  /* Column-major Lookup 2-D
     Canonical function name: look2_is16u16ls32n10ts16Ds32ds32_plinlcas
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (Int32)((UInt32)((((UInt32)((UInt16)((Int32)(((Int32)u0)
      - ((Int32)bp0[bpIdx]))))) << 10) / ((UInt32)((UInt16)((Int32)
      (((Int32)bp0[bpIdx + 1U]) - ((Int32)bp0[bpIdx])))))));
  } else {
    bpIdx = maxIndex[0U];
    frac = 0;
  }

  prevIndex[0U] = bpIdx;
  fractions[0U] = frac;
  bpIndices[0U] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Linear Search */
    for (bpIdx = prevIndex[1U]; u1 < bp1[bpIdx]; bpIdx--) {
    }

    while (u1 >= bp1[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (Int32)((UInt32)((((UInt32)((UInt16)(((UInt32)u1) -
      ((UInt32)bp1[bpIdx])))) << 10) / ((UInt32)((UInt16)(((UInt32)
      bp1[bpIdx + 1U]) - ((UInt32)bp1[bpIdx]))))));
  } else {
    bpIdx = maxIndex[1U];
    frac = 0;
  }

  prevIndex[1U] = bpIdx;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  offset_1d = (bpIdx * stride) + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    y = (Int16)(((Int16)asr_s32_1((((Int32)table[offset_1d + 1U]) -
      ((Int32)table[offset_1d])) * fractions[0U], 10U)) + table[offset_1d]);
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_1d = table[bpIdx];
    } else {
      yR_1d = (Int16)(((Int16)asr_s32_1((((Int32)table[bpIdx + 1U]) -
        ((Int32)table[bpIdx])) * fractions[0U], 10U)) + table[bpIdx]);
    }

    y += (Int16)asr_s32_1((((Int32)yR_1d) - ((Int32)y)) * frac, 10U);
  }

  return y;
}
/* Block signals and states (default storage) */
DW_l5cf_Lqr rtDW_l5cf_Lqr;
uint32 m_bpIndex_tqout = 0;
/* Model step function */
void LQR_step(void)
{

  static Int16 lka_rate = 0;
  Float64 a_0[4];
  Float64 a[2];
  Float64 K_idx_1;
  Float64 b;
  Float64 rtb_Add_grmp;
  Float64 rtb_Gain;
  Float64 rtb_Sign;
  Int32 b_I_tmp;
  Int32 i;
  Int16 rtb_Abs2;
  Int16 rtb_Abs2_agwj;
  UInt16 rtb_FAA_FC1;
  UInt16 rtb_FAA_FC1_mj5h;
  /*增加变量，用与随速查表赋值,24.03.01 by zyg*/
  static Float64 rtb_angleloop_kp = 20;
  static Float64 rtb_leadgain = 0;

  volatile sint16 rtb_lkatq = 0;
  volatile sint16 rtb_lkatqout = 0;
  volatile sint16 rtb_lkatqdir = 0;
  static const Float64 a_1[4] = { 1.0, 0.02, 0.0, 1.0 };

  static const Int32 Qk[4] = { 1000000, 0, 0, 10 };

  /* Outputs for Enabled SubSystem: '<S1>/Improved_PI' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/Reset'
   */
  if (Fv_FAA_Reset == ((UInt8)2U)) {
    if (!rtDW_l5cf_Lqr.Improved_PI_MODE) {
      /* InitializeConditions for Delay: '<S9>/AngLeadDelay1' */
      rtDW_l5cf_Lqr.icLoad = true;

      /* InitializeConditions for Delay: '<S9>/AngLeadDelay' */
      rtDW_l5cf_Lqr.icLoad_gq03 = true;

      /* InitializeConditions for Delay: '<S18>/SpdPdelay' */
      rtDW_l5cf_Lqr.icLoad_fd53 = true;

      /* InitializeConditions for Sum: '<S18>/Add9' incorporates:
       *  Delay: '<S8>/PIDelay'
       */
      rtDW_l5cf_Lqr.PIDelay_DSTATE = 0.0;

      /* InitializeConditions for Delay: '<S21>/FCdelay' */
      rtDW_l5cf_Lqr.FCdelay_DSTATE = 0.0;

      /* SystemReset for Atomic SubSystem: '<S3>/Aim_Ang_RateLimit' */
      /* SystemReset for MATLAB Function: '<S6>/RateLim' */
      /* '<S13>:1:5' Counter = 0; */
      rtDW_l5cf_Lqr.Counter = 0.0;

      /* '<S13>:1:6' AngIn = 0; */
      rtDW_l5cf_Lqr.AngIn = 0.0;

      /* End of SystemReset for SubSystem: '<S3>/Aim_Ang_RateLimit' */

      /* SystemReset for MATLAB Function: '<S5>/Spd_KF' */
      rtDW_l5cf_Lqr.P_gvra[0] = 1.0E+6;
      rtDW_l5cf_Lqr.P_gvra[1] = 0.0;
      rtDW_l5cf_Lqr.P_gvra[2] = 0.0;
      rtDW_l5cf_Lqr.P_gvra[3] = 1.0E+6;

      /* '<S11>:1:10' P=[Para1,0;0,Para2]; */
      /* '<S11>:1:11' x=[0,0]'; */
      rtDW_l5cf_Lqr.x[0] = 0.0;
      rtDW_l5cf_Lqr.x[1] = 0.0;

      /* '<S11>:1:12' cnt = 0; */
      rtDW_l5cf_Lqr.cnt = 0.0;

      /* SystemReset for Atomic SubSystem: '<S10>/Sensor_Adjust' */
      /* InitializeConditions for Delay: '<S12>/SpdLeadDelay' */
      rtDW_l5cf_Lqr.icLoad_dxex = true;

      /* InitializeConditions for Delay: '<S12>/SpdLeadDelay1' */
      rtDW_l5cf_Lqr.icLoad_kxck = true;

      /* End of SystemReset for SubSystem: '<S10>/Sensor_Adjust' */
      rtDW_l5cf_Lqr.Improved_PI_MODE = true;
    }

    /* Saturate: '<S19>/Saturation' incorporates:
     *  Abs: '<S16>/Abs2'
     *  DataStoreRead: '<S19>/Data Store Read2'
     */
    if (Fv_LKA_TorqueCmdDownLimit > 0) {
      rtb_Abs2 = 0;
    } else if (Fv_LKA_TorqueCmdDownLimit < (-8192)) {
      rtb_Abs2 = (-8192);
    } else {
      rtb_Abs2 = Fv_LKA_TorqueCmdDownLimit;
    }

    /* End of Saturate: '<S19>/Saturation' */

    /* Abs: '<S19>/Abs' incorporates:
     *  Abs: '<S16>/Abs2'
     */
    if (rtb_Abs2 < 0) {
      rtb_Abs2 = (Int16)(-rtb_Abs2);
    }

    /* End of Abs: '<S19>/Abs' */

    /* Lookup_n-D: '<S19>/TorqueLim1' incorporates:
     *  Abs: '<S16>/Abs2'
     *  DataStoreRead: '<S19>/Data Store Read3'
     */
    #if 0
    rtb_Abs2_agwj = look2_is16u16ls32n10ts_TlwpcxFz(rtb_Abs2, Fv_VehSpdNew, ((
      const Int16 *)&(Cal_LKA_TqLimit_A[0])), ((const UInt16 *)
      &(Cal_LKA_TqLimit_V[0])), ((const Int16 *)&(Cal_LKA_TqLimit_T
      [0])), rtDW_l5cf_Lqr.m_bpIndex, rtConstP_dfsm_Lqr.pooled14, 7U);
    #else
    rtb_Abs2_agwj = look2_is16u16ls32n10ts_TlwpcxFz_lqr(rtb_Abs2, Fv_VehSpdNew, ((
      const Int16 *)&(Cal_LKA_TqLimit_A[0])), ((const UInt16 *)
      &(Cal_LKA_TqLimit_V[0])), ((const Int16 *)&(Cal_LKA_TqLimit_T
      [0])), rtDW_l5cf_Lqr.m_bpIndex, rtConstP_dfsm_Lqr.pooled14, 25U);
    #endif

    /* Lookup_n-D: '<S18>/SpdLoop_P' incorporates:
     *  Abs: '<S18>/Abs'
     *  DataStoreRead: '<S18>/Data Store Read5'
     *  Lookup_n-D: '<S16>/FAA_FC1'
     */
    rtb_FAA_FC1 = look1_iu16ls32n10tu16_pbinlcase(Fv_VehSpdNew, ((const UInt16 *)
      &(Cal_FAA_SpdLoop_X[0])), ((const UInt16 *)&(Cal_FAA_SpdLoop_Y_P[0])),
      &rtDW_l5cf_Lqr.m_bpIndex_kc2k, 7U);

    /* Lookup_n-D: '<S14>/FAA_FC' incorporates:
     *  Abs: '<S14>/Abs'
     *  DataStoreRead: '<S14>/Data Store Read5'
     *  Lookup_n-D: '<S16>/FAA_FC1'
     */
    rtb_FAA_FC1_mj5h = look1_iu16ls32n10tu16_pbinlcase(Fv_VehSpdNew, ((const
      UInt16 *)&(Cal_FAA_SpdLim_X[0])), ((const UInt16 *)&(Cal_FAA_SpdLim_Y[0])),
      &rtDW_l5cf_Lqr.m_bpIndex_buu0, 7U);

    /* Outputs for Atomic SubSystem: '<S3>/Aim_Ang_RateLimit' */
    /* MATLAB Function: '<S6>/RateLim' incorporates:
     *  Constant: '<S6>/AimAng_LimRate'
     *  Inport: '<Root>/AngLoopLQR_AimAng'
     */
    /*  AngLim dealy */
    /* MATLAB Function 'LQR/Improved_PI/Aim_Ang_RateLimit/RateLim': '<S13>:1' */
    /* '<S13>:1:4' if isempty(Counter) */
    /* '<S13>:1:8' if Counter <= 2 */
    if (rtDW_l5cf_Lqr.Counter <= 2.0) {
      /* '<S13>:1:9' AngIn = Ang; */
      rtDW_l5cf_Lqr.AngIn = Fv_FAA_LQR_AimAng;
    } else {
      /* '<S13>:1:10' else */
      /* '<S13>:1:11' if (Ang-AngIn)> LimRate *0.001 */
      rtb_Gain = Fv_FAA_LQR_AimAng - rtDW_l5cf_Lqr.AngIn;
      if (rtb_Gain > (300.0 * 0.001)) {
        /* '<S13>:1:12' AngIn = AngIn +LimRate *0.001; */
        rtDW_l5cf_Lqr.AngIn += 300.0 * 0.001;
      } else if (rtb_Gain < ((-300.0) * 0.001)) {
        /* '<S13>:1:13' elseif (Ang-AngIn)< -LimRate *0.001 */
        /* '<S13>:1:14' AngIn = AngIn - LimRate *0.001; */
        rtDW_l5cf_Lqr.AngIn -= 300.0 * 0.001;
      } else {
        /* '<S13>:1:15' else */
        /* '<S13>:1:16' AngIn = Ang; */
        rtDW_l5cf_Lqr.AngIn = Fv_FAA_LQR_AimAng;
      }

      /* '<S13>:1:18' Counter = 2; */
      rtDW_l5cf_Lqr.Counter = 2.0;
    }

    /* '<S13>:1:20' Counter = Counter +1; */
    rtDW_l5cf_Lqr.Counter++;

    /* End of Outputs for SubSystem: '<S3>/Aim_Ang_RateLimit' */

    /* Delay: '<S9>/AngLeadDelay1' */
    /* '<S13>:1:21' AimLim = AngIn; */
    if (rtDW_l5cf_Lqr.icLoad) {
      /* Product: '<S9>/Multiply' incorporates:
       *  Inport: '<Root>/AngLoopLQR_ActAng'
       */
      rtDW_l5cf_Lqr.AngLeadDelay1_DSTATE = Fv_FAA_LQR_ActAng;
    }

    /* Gain: '<S4>/Gain2' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    K_idx_1 = 0.1 * Cal_FAA_LeadFreq;

    /* Saturate: '<S4>/Saturation' */
    if (K_idx_1 > 20.0) {
      K_idx_1 = 20.0;
    } else if (K_idx_1 < 0.5) {
      K_idx_1 = 0.5;
    } else {
      /* no actions */
    }

    /* End of Saturate: '<S4>/Saturation' */

    /* Gain: '<S4>/Gain' */
    rtb_Gain = 6.2831853071795862 * K_idx_1;

    /* Bias: '<S4>/Bias' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Gain: '<S4>/Gain1'
     */
    /*增加随速查表,24.03.01 by zyg*/

#if 1

    rtb_leadgain = look1_iu16ls32n10tu16_pbinlcase(Fv_VehSpdNew, ((const UInt16 *)
      &(Cal_FAA_LeadGain_X[0])), ((const UInt16 *)&(Cal_FAA_LeadGain_Y[0])),
      &rtDW_l5cf_Lqr.m_bpIndex_bx13, 7U);

    rtb_Add_grmp = (0.1 * rtb_leadgain) + 1.0;
#else

    rtb_Add_grmp = (0.1 * Cal_FAA_LeadGain) + 1.0;
#endif
    /* Saturate: '<S4>/Saturation1' */
    if (rtb_Add_grmp > 5.0) {
      rtb_Add_grmp = 5.0;
    } else if (rtb_Add_grmp < 1.0) {
      rtb_Add_grmp = 1.0;
    } else {
      /* no actions */
    }

    /* End of Saturate: '<S4>/Saturation1' */

    /* Product: '<S9>/Product4' */
    rtb_Sign = rtb_Gain * rtb_Add_grmp;

    /* Delay: '<S9>/AngLeadDelay' incorporates:
     *  Inport: '<Root>/AngLoopLQR_ActAng'
     */
    if (rtDW_l5cf_Lqr.icLoad_gq03) {
      rtDW_l5cf_Lqr.AngLeadDelay_DSTATE = Fv_FAA_LQR_ActAng;
    }

    /* Product: '<S9>/Multiply' incorporates:
     *  Bias: '<S9>/Bias'
     *  Bias: '<S9>/Bias1'
     *  Bias: '<S9>/Bias2'
     *  Bias: '<S9>/Bias4'
     *  Delay: '<S9>/AngLeadDelay'
     *  Delay: '<S9>/AngLeadDelay1'
     *  Inport: '<Root>/AngLoopLQR_ActAng'
     *  Product: '<S9>/Product'
     *  Product: '<S9>/Product1'
     *  Product: '<S9>/Product2'
     *  Product: '<S9>/Product3'
     *  Sum: '<S9>/Add'
     *  Sum: '<S9>/Add1'
     */
    rtDW_l5cf_Lqr.AngLeadDelay1_DSTATE = ((((Fv_FAA_LQR_ActAng * (rtb_Gain + 2000.0))
      + (rtDW_l5cf_Lqr.AngLeadDelay_DSTATE * (rtb_Gain + (-2000.0)))) * rtb_Add_grmp)
      - (rtDW_l5cf_Lqr.AngLeadDelay1_DSTATE * (rtb_Sign + (-2000.0)))) / (rtb_Sign +
      2000.0);

    /* Outputs for Atomic SubSystem: '<S3>/Aim_Ang_RateLimit' */
    /* Sum: '<S3>/Add6' incorporates:
     *  MATLAB Function: '<S6>/RateLim'
     */
    rtb_Sign = rtDW_l5cf_Lqr.AngIn - rtDW_l5cf_Lqr.AngLeadDelay1_DSTATE;

    /* End of Outputs for SubSystem: '<S3>/Aim_Ang_RateLimit' */

    /* Saturate: '<S7>/Sat1' incorporates:
     *  Constant: '<S7>/AngLoop_P'
     */
    /*增加速速查表,24.03.01 by zyg*/
#if 1
    rtb_angleloop_kp = look1_iu16ls32n10tu16_pbinlcase(Fv_VehSpdNew, ((const UInt16 *)
      &(Cal_FAA_AL_P_X[0])), ((const UInt16 *)&(Cal_FAA_AL_P_Y[0])),
      &rtDW_l5cf_Lqr.m_bpIndex_bx12, 7U);


    if (rtb_angleloop_kp > 50.0) {
      rtb_Gain = 50.0;
    } else if (rtb_angleloop_kp < 10.0) {
      rtb_Gain = 10.0;
    } else {
      rtb_Gain = (Float64)rtb_angleloop_kp;
    }
#else
    if (Cal_FAA_AL_P > 50.0) {
      rtb_Gain = 50.0;
    } else if (Cal_FAA_AL_P < 10.0) {
      rtb_Gain = 10.0;
    } else {
      rtb_Gain = Cal_FAA_AL_P;
    }
#endif
    /* End of Saturate: '<S7>/Sat1' */

    /* DeadZone: '<S7>/Dead Zone1' */
    if (rtb_Sign > 0.02) {
      rtb_Sign -= 0.02;
    } else if (rtb_Sign >= (-0.02)) {
      rtb_Sign = 0.0;
    } else {
      rtb_Sign -= (-0.02);
    }

    /* End of DeadZone: '<S7>/Dead Zone1' */

    /* Product: '<S7>/Product1' */
    rtb_Gain *= rtb_Sign;

    /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
     *  Lookup_n-D: '<S16>/FAA_FC1'
     */
    rtb_Add_grmp = ((Float64)rtb_FAA_FC1_mj5h) * 0.0625;

    /* Gain: '<S14>/Gain' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion1'
     */
    rtb_Sign = (-1.0) * rtb_Add_grmp;

    /* Switch: '<S15>/Switch2' incorporates:
     *  RelationalOperator: '<S15>/LowerRelop1'
     *  RelationalOperator: '<S15>/UpperRelop'
     *  Switch: '<S15>/Switch'
     */
    if (rtb_Gain > rtb_Add_grmp) {
      rtb_Gain = rtb_Add_grmp;
    } else if (rtb_Gain < rtb_Sign) {
      /* Switch: '<S15>/Switch' */
      rtb_Gain = rtb_Sign;
    } else {
      /* no actions */
    }

    /* End of Switch: '<S15>/Switch2' */

    /* Sum: '<S7>/Add7' incorporates:
     *  Inport: '<Root>/AngLoopLQR_ActSpd'
     */
    rtb_Sign = rtb_Gain - Fv_FAA_LQR_ActSpd;

    /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
     *  Lookup_n-D: '<S16>/FAA_FC1'
     */
    K_idx_1 = ((Float64)rtb_FAA_FC1) * 0.0009765625;

    /* Saturate: '<S18>/Saturation' */
    if (K_idx_1 > 2.0) {
      K_idx_1 = 2.0;
    } else if (K_idx_1 < 0.05) {
      K_idx_1 = 0.05;
    } else {
      /* no actions */
    }

    /* End of Saturate: '<S18>/Saturation' */

    /* Product: '<S18>/Product3' */
    rtb_Gain = K_idx_1 * rtb_Sign;

    /* Delay: '<S18>/SpdPdelay' */
    if (rtDW_l5cf_Lqr.icLoad_fd53) {
      rtDW_l5cf_Lqr.SpdPdelay_DSTATE = rtb_Gain;
    }

    /* Lookup_n-D: '<S18>/SpdLoop_I' incorporates:
     *  Abs: '<S18>/Abs1'
     *  DataStoreRead: '<S18>/Data Store Read1'
     *  Lookup_n-D: '<S16>/FAA_FC1'
     */
    rtb_FAA_FC1 = look1_iu16ls32n10tu16_pbinlcase(Fv_VehSpdNew, ((const UInt16 *)
      &(Cal_FAA_SpdLoop_X[0])), ((const UInt16 *)&(Cal_FAA_SpdLoop_Y_I[0])),
      &rtDW_l5cf_Lqr.m_bpIndex_hutn, 7U);

    /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
     *  Lookup_n-D: '<S16>/FAA_FC1'
     */
    K_idx_1 = ((Float64)rtb_FAA_FC1) * 0.0009765625;

    /* Saturate: '<S18>/Saturation1' */
    if (K_idx_1 > 5.0) {
      K_idx_1 = 5.0;
    } else if (K_idx_1 < 0.5) {
      K_idx_1 = 0.5;
    } else {
      /* no actions */
    }

    /* End of Saturate: '<S18>/Saturation1' */

    /* Sum: '<S18>/Add9' incorporates:
     *  Delay: '<S18>/SpdPdelay'
     *  Delay: '<S8>/PIDelay'
     *  Gain: '<S18>/Gain8'
     *  Product: '<S18>/Product4'
     *  Sum: '<S18>/Add10'
     *  Sum: '<S18>/Add8'
     */
    rtDW_l5cf_Lqr.PIDelay_DSTATE = (rtb_Gain - rtDW_l5cf_Lqr.SpdPdelay_DSTATE) + ((0.001
      * (rtb_Sign * K_idx_1)) + rtDW_l5cf_Lqr.PIDelay_DSTATE);

    /* Saturate: '<S20>/Saturation' incorporates:
     *  Abs: '<S16>/Abs2'
     *  DataStoreRead: '<S20>/Data Store Read4'
     */
    if (Fv_LKA_TorqueCmdUpLimit > 8192) {
      rtb_Abs2 = 8192;
    } else if (Fv_LKA_TorqueCmdUpLimit < 0) {
      rtb_Abs2 = 0;
    } else {
      rtb_Abs2 = Fv_LKA_TorqueCmdUpLimit;
    }
    /* End of Saturate: '<S20>/Saturation' */

    /* Abs: '<S20>/Abs1' incorporates:
     *  Abs: '<S16>/Abs2'
     */
    if (rtb_Abs2 < 0) {
      rtb_Abs2 = (Int16)(-rtb_Abs2);
    }

    /* End of Abs: '<S20>/Abs1' */

    /* Lookup_n-D: '<S20>/TorqueLim1' incorporates:
     *  Abs: '<S16>/Abs2'
     *  DataStoreRead: '<S20>/Data Store Read1'
     */
    #if 0 
    rtb_Abs2 = look2_is16u16ls32n10ts_TlwpcxFz(rtb_Abs2, Fv_VehSpdNew, ((const
      Int16 *)&(Cal_LKA_TqLimit_A[0])), ((const UInt16 *)
      &(Cal_LKA_TqLimit_V[0])), ((const Int16 *)&(Cal_LKA_TqLimit_T
      [0])), rtDW_l5cf_Lqr.m_bpIndex_np4x, rtConstP_dfsm_Lqr.pooled14, 7U);
    #else
    rtb_Abs2 = look2_is16u16ls32n10ts_TlwpcxFz_lqr(rtb_Abs2, Fv_VehSpdNew, ((const
      Int16 *)&(Cal_LKA_TqLimit_A[0])), ((const UInt16 *)
      &(Cal_LKA_TqLimit_V[0])), ((const Int16 *)&(Cal_LKA_TqLimit_T
      [0])), rtDW_l5cf_Lqr.m_bpIndex_np4x, rtConstP_dfsm_Lqr.pooled14, 25U);
    #endif
    /* Gain: '<S20>/Gain' incorporates:
     *  Abs: '<S16>/Abs2'
     *  DataTypeConversion: '<S20>/Data Type Conversion'
     */
    rtb_Sign = (-1.0) * (((Float64)rtb_Abs2) * 0.0078125);

    /* Switch: '<S17>/Switch2' incorporates:
     *  Abs: '<S16>/Abs2'
     *  DataTypeConversion: '<S19>/Data Type Conversion'
     *  RelationalOperator: '<S17>/LowerRelop1'
     *  RelationalOperator: '<S17>/UpperRelop'
     *  Switch: '<S17>/Switch'
     */
    /*传入的下限当内部的上限，外部左正右负  内部左负右正*/
    /*下限*/
    /*定标2^-7*/
    if (rtDW_l5cf_Lqr.PIDelay_DSTATE > (((Float64)rtb_Abs2_agwj) * 0.0078125)) {
      /* Sum: '<S18>/Add9' */
      rtDW_l5cf_Lqr.PIDelay_DSTATE = ((Float64)rtb_Abs2_agwj) * 0.0078125;

      Fv_LKA_ExtFctLowerLimActive = true;
    } else if (rtDW_l5cf_Lqr.PIDelay_DSTATE < rtb_Sign) {/*上限*/
      /* Sum: '<S18>/Add9' incorporates:
       *  Switch: '<S17>/Switch'
       */
      rtDW_l5cf_Lqr.PIDelay_DSTATE = rtb_Sign;

      Fv_LKA_ExtFctUpperLimActive = true;
    } else {
      /* no actions */
      Fv_LKA_ExtFctUpperLimActive = false;
      Fv_LKA_ExtFctLowerLimActive = false;
    }
    Fv_LKA_LimitTorqueOut = (Int16)(rtDW_l5cf_Lqr.PIDelay_DSTATE*128.0);

    /* End of Switch: '<S17>/Switch2' */

    /* Gain: '<S21>/Gain' incorporates:
     *  Constant: '<S21>/Constant1'
     */
    rtb_Sign = 0.01 * Cal_FAA_FcStif;

    /* Saturate: '<S21>/Saturation' */
    if (rtb_Sign > 10.0) {
      rtb_Sign = 10.0;
    } else if (rtb_Sign < 0.05) {
      rtb_Sign = 0.05;
    } else {
      /* no actions */
    }

    /* End of Saturate: '<S21>/Saturation' */

    /* MATLAB Function: '<S5>/Spd_KF' incorporates:
     *  Inport: '<Root>/AngLoopLQR_AimAng'
     */
    /* MATLAB Function 'LQR/Improved_PI/AimSpd/Spd_KF': '<S11>:1' */
    /* '<S11>:1:4' Para1 = 10^6; */
    /* '<S11>:1:5' Para2 = 10^6; */
    /* '<S11>:1:6' Q1 = 10^6; */
    /* '<S11>:1:7' Q2 = 10; */
    /* '<S11>:1:8' R1 =10^4; */
    /* '<S11>:1:9' if isempty(P) */
    /* '<S11>:1:15' Ts = 0.02; */
    /* '<S11>:1:16' A=[0,0;1,0]; */
    /* '<S11>:1:17' B=[0,0]'; */
    /* ת�� */
    /* '<S11>:1:18' Ak=eye(2)+Ts*A; */
    /* '<S11>:1:19' Bk=Ts*B; */
    /* '<S11>:1:20' Hk=[0,1]; */
    /* '<S11>:1:21' Qk = [Q1,0; 0 Q2]; */
    /* '<S11>:1:22' Rk = R1; */
    /* '<S11>:1:24' cnt = cnt + 1; */
    rtDW_l5cf_Lqr.cnt++;

    /* '<S11>:1:25' if cnt == 20 */
    if (rtDW_l5cf_Lqr.cnt == 20.0) {
      /* '<S11>:1:26' cnt = 0; */
      rtDW_l5cf_Lqr.cnt = 0.0;

      /* '<S11>:1:27' zk = FAA_Ang; */
      /* '<S11>:1:28' x=Ak*x+Bk*0; */
      a[0] = rtDW_l5cf_Lqr.x[0];
      a[1] = (rtDW_l5cf_Lqr.x[0] * 0.02) + rtDW_l5cf_Lqr.x[1];

      /* '<S11>:1:29' P=Ak*P*Ak'+Qk; */
      for (i = 0; i < 2; i++) {
        rtDW_l5cf_Lqr.x[i] = a[i];
        a_0[i] = 0.0;
        a_0[i] += a_1[i] * rtDW_l5cf_Lqr.P_gvra[0];
        rtb_Add_grmp = a_1[i + 2];
        a_0[i] += rtb_Add_grmp * rtDW_l5cf_Lqr.P_gvra[1];
        a_0[i + 2] = 0.0;
        a_0[i + 2] += a_1[i] * rtDW_l5cf_Lqr.P_gvra[2];
        a_0[i + 2] += rtb_Add_grmp * rtDW_l5cf_Lqr.P_gvra[3];
      }

      for (i = 0; i < 2; i++) {
        rtDW_l5cf_Lqr.P_gvra[i] = a_0[i] + ((Float64)Qk[i]);
        rtDW_l5cf_Lqr.P_gvra[i + 2] = ((a_0[i] * 0.02) + a_0[i + 2]) + ((Float64)
          Qk[i + 2]);
      }

      /* '<S11>:1:30' K=P*Hk'/(Hk*P*Hk'+Rk); */
      /* '<S11>:1:31' x=x+K*(zk-Hk*x); */
      rtb_Add_grmp = rtDW_l5cf_Lqr.P_gvra[2] / (rtDW_l5cf_Lqr.P_gvra[3] + 10000.0);
      K_idx_1 = rtDW_l5cf_Lqr.P_gvra[3] / (rtDW_l5cf_Lqr.P_gvra[3] + 10000.0);
      b = Fv_FAA_LQR_AimAng - rtDW_l5cf_Lqr.x[1];
      rtDW_l5cf_Lqr.x[0] += rtb_Add_grmp * b;
      rtDW_l5cf_Lqr.x[1] += K_idx_1 * b;

      /* '<S11>:1:32' P=(eye(2)-K*Hk)*P; */
      for (i = 0; i < 2; i++) {
        b_I_tmp = i * 2;
        a_0[b_I_tmp] = 0.0;
        a_0[b_I_tmp] += rtDW_l5cf_Lqr.P_gvra[b_I_tmp];
        a_0[b_I_tmp] += (0.0 - rtb_Add_grmp) * rtDW_l5cf_Lqr.P_gvra[b_I_tmp + 1];
        a_0[b_I_tmp + 1] = 0.0;
        a_0[b_I_tmp + 1] += (1.0 - K_idx_1) * rtDW_l5cf_Lqr.P_gvra[b_I_tmp + 1];
      }

      rtDW_l5cf_Lqr.P_gvra[0] = a_0[0];
      rtDW_l5cf_Lqr.P_gvra[1] = a_0[1];
      rtDW_l5cf_Lqr.P_gvra[2] = a_0[2];
      rtDW_l5cf_Lqr.P_gvra[3] = a_0[3];
    }

    /* Outputs for Atomic SubSystem: '<S10>/Sensor_Adjust' */
    /* Delay: '<S12>/SpdLeadDelay' incorporates:
     *  MATLAB Function: '<S5>/Spd_KF'
     */
    /* '<S11>:1:34' Spd_KF=x(1); */
    if (rtDW_l5cf_Lqr.icLoad_dxex) {
      rtDW_l5cf_Lqr.SpdLeadDelay_DSTATE = rtDW_l5cf_Lqr.x[0];
    }

    /* Delay: '<S12>/SpdLeadDelay1' incorporates:
     *  MATLAB Function: '<S5>/Spd_KF'
     */
    if (rtDW_l5cf_Lqr.icLoad_kxck) {
      rtDW_l5cf_Lqr.SpdLeadDelay1_DSTATE = rtDW_l5cf_Lqr.x[0];
    }

    /* Product: '<S12>/Multiply' incorporates:
     *  Constant: '<S10>/Constant'
     *  Delay: '<S12>/SpdLeadDelay'
     *  Delay: '<S12>/SpdLeadDelay1'
     *  MATLAB Function: '<S5>/Spd_KF'
     *  Product: '<S12>/Product'
     *  Product: '<S12>/Product1'
     *  Product: '<S12>/Product2'
     *  Product: '<S12>/Product3'
     *  Sum: '<S12>/Add'
     *  Sum: '<S12>/Add1'
     */
    Fv_FAA_SpdKF = ((((rtDW_l5cf_Lqr.x[0] * rtConstB.Bias) +
                      (rtDW_l5cf_Lqr.SpdLeadDelay_DSTATE * rtConstB.Bias2)) * 3.0) -
                    (rtDW_l5cf_Lqr.SpdLeadDelay1_DSTATE * rtConstB.Bias1)) /
      rtConstB.Bias4;

    /* Update for Delay: '<S12>/SpdLeadDelay' incorporates:
     *  MATLAB Function: '<S5>/Spd_KF'
     */
    rtDW_l5cf_Lqr.icLoad_dxex = false;
    rtDW_l5cf_Lqr.SpdLeadDelay_DSTATE = rtDW_l5cf_Lqr.x[0];

    /* Update for Delay: '<S12>/SpdLeadDelay1' */
    rtDW_l5cf_Lqr.icLoad_kxck = false;
    rtDW_l5cf_Lqr.SpdLeadDelay1_DSTATE = Fv_FAA_SpdKF;

    /* End of Outputs for SubSystem: '<S10>/Sensor_Adjust' */

    /* DeadZone: '<S5>/Dead Zone' */
    if (Fv_FAA_SpdKF > 0.1) {
      rtb_Add_grmp = Fv_FAA_SpdKF - 0.1;
    } else if (Fv_FAA_SpdKF >= (-0.1)) {
      rtb_Add_grmp = 0.0;
    } else {
      rtb_Add_grmp = Fv_FAA_SpdKF - (-0.1);
    }

    /* End of DeadZone: '<S5>/Dead Zone' */

    /* Saturate: '<S5>/Saturation4' */
    if (rtb_Add_grmp > 30.0) {
      rtb_Add_grmp = 30.0;
    } else if (rtb_Add_grmp < (-30.0)) {
      rtb_Add_grmp = (-30.0);
    } else {
      /* no actions */
    }

    /* End of Saturate: '<S5>/Saturation4' */

    /* Sum: '<S21>/Add' incorporates:
     *  Abs: '<S21>/Abs'
     *  Delay: '<S21>/FCdelay'
     *  Product: '<S21>/Product'
     *  Product: '<S21>/Product2'
     */
    rtb_Add_grmp -= fabs(rtb_Sign * rtb_Add_grmp) * rtDW_l5cf_Lqr.FCdelay_DSTATE;

    /* Lookup_n-D: '<S16>/FAA_FC' incorporates:
     *  Abs: '<S16>/Abs'
     *  DataStoreRead: '<S16>/Data Store Read5'
     *  Lookup_n-D: '<S16>/FAA_FC1'
     */
    rtb_FAA_FC1 = look1_iu16ls32n10tu16_pbinlcase(Fv_VehSpdNew, ((const UInt16 *)
      &(Cal_FAA_FC_X[0])), ((const UInt16 *)&(Cal_FAA_FC_Y[0])),
      &rtDW_l5cf_Lqr.m_bpIndex_bx11, 7U);

    /* Abs: '<S16>/Abs2' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read2'
     */
    if (Fv_LKA_TorqueCmdDownLimit < 0) {
      rtb_Abs2 = (Int16)(-Fv_LKA_TorqueCmdDownLimit);
    } else {
      rtb_Abs2 = Fv_LKA_TorqueCmdDownLimit;
    }

    /* End of Abs: '<S16>/Abs2' */

    /* Abs: '<S16>/Abs3' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read3'
     */
    if (Fv_LKA_TorqueCmdUpLimit < 0) {
      rtb_Abs2_agwj = (Int16)(-Fv_LKA_TorqueCmdUpLimit);
    } else {
      rtb_Abs2_agwj = Fv_LKA_TorqueCmdUpLimit;
    }

    /* End of Abs: '<S16>/Abs3' */

    /* MinMax: '<S16>/Max' incorporates:
     *  Abs: '<S16>/Abs2'
     *  Abs: '<S16>/Abs3'
     */
    if (rtb_Abs2 > rtb_Abs2_agwj) {
      rtb_Abs2_agwj = rtb_Abs2;
    }

    /* End of MinMax: '<S16>/Max' */

    /* Abs: '<S16>/Abs1' incorporates:
     *  MinMax: '<S16>/Max'
     */
    if (rtb_Abs2_agwj < 0) {
      rtb_FAA_FC1_mj5h = (UInt16)((Int32)(-((Int32)rtb_Abs2_agwj)));
    } else {
      rtb_FAA_FC1_mj5h = (UInt16)rtb_Abs2_agwj;
    }

    /* End of Abs: '<S16>/Abs1' */

    /* Lookup_n-D: '<S16>/FAA_FC1' */
    rtb_FAA_FC1_mj5h = look1_iu16ls32n10tu16_pbinlcase(rtb_FAA_FC1_mj5h, ((const
      UInt16 *)&(Cal_FAA_FC_Lim_X[0])), ((const UInt16 *)&(Cal_FAA_FC_Lim_Y[0])),
      &rtDW_l5cf_Lqr.m_bpIndex_aj1t, 5U);

    /* Product: '<S16>/Product' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion1'
     *  DataTypeConversion: '<S16>/Data Type Conversion2'
     *  Delay: '<S21>/FCdelay'
     *  Gain: '<S21>/Gain1'
     *  Lookup_n-D: '<S16>/FAA_FC1'
     *  Product: '<S16>/Product1'
     *  Product: '<S21>/Product3'
     *  Product: '<S21>/Product4'
     *  Sum: '<S21>/Add2'
     */
    K_idx_1 = (((rtb_Sign * rtDW_l5cf_Lqr.FCdelay_DSTATE) + ((0.002 * rtb_Sign) *
      rtb_Add_grmp)) * (((Float64)rtb_FAA_FC1) * 0.0078125)) * (((Float64)
      rtb_FAA_FC1_mj5h) * 0.0078125);

    /* Saturate: '<S16>/Saturation7' */
    if (K_idx_1 > 20.0) {
      K_idx_1 = 20.0;
    } else if (K_idx_1 < (-20.0)) {
      K_idx_1 = (-20.0);
    } else {
      /* no actions */
    }

    /* End of Saturate: '<S16>/Saturation7' */

    /* Gain: '<S3>/Sign' incorporates:
     *  Delay: '<S8>/PIDelay'
     *  Sum: '<S8>/Add'
     */
    rtb_Sign = (-1.0) * (rtDW_l5cf_Lqr.PIDelay_DSTATE + K_idx_1);

    /* Saturate: '<S3>/Sat' incorporates:
     *  DataStoreWrite: '<S3>/Data Store Write'
     */
    if (rtb_Sign >= (((Float64)15360) * 0.0078125)) {
      Fv_FAA_LQR_QcurOut = 15360;
    } else if (rtb_Sign <= (((Float64)(-15360)) * 0.0078125)) {
      Fv_FAA_LQR_QcurOut = -15360;
    } else {
      Fv_FAA_LQR_QcurOut = (Int16)((Float64)(rtb_Sign * 128.0));
    }

    

    /* End of Saturate: '<S3>/Sat' */

    /* Product: '<S3>/Divide' incorporates:
     *  Constant: '<S3>/Constant1'
     *  DataStoreRead: '<S3>/Data Store Read'
     *  DataStoreWrite: '<S3>/Data Store Write1'
     */
    Fv_LKA_Torque = (Int16)((Fv_FAA_LQR_QcurOut * 128) / Cal_Motor_TrqCoef);

    /* Sum: '<S21>/Add1' incorporates:
     *  Delay: '<S21>/FCdelay'
     *  Gain: '<S21>/gain3'
     */
    rtDW_l5cf_Lqr.FCdelay_DSTATE += 0.001 * rtb_Add_grmp;

    /* Update for Delay: '<S9>/AngLeadDelay1' */
    rtDW_l5cf_Lqr.icLoad = false;

    /* Update for Delay: '<S9>/AngLeadDelay' incorporates:
     *  Inport: '<Root>/AngLoopLQR_ActAng'
     */
    rtDW_l5cf_Lqr.icLoad_gq03 = false;
    rtDW_l5cf_Lqr.AngLeadDelay_DSTATE = Fv_FAA_LQR_ActAng;

    /* Update for Delay: '<S18>/SpdPdelay' */
    rtDW_l5cf_Lqr.icLoad_fd53 = false;
    rtDW_l5cf_Lqr.SpdPdelay_DSTATE = rtb_Gain;
  } else {
    rtDW_l5cf_Lqr.Improved_PI_MODE = false;

    /*退出后按梯度衰减到0*/
    if(Fv_LKA_LimitTorqueOut < 0)
    {
      if(Fv_LKA_LimitTorqueOut + 5 < 0)
      {
        Fv_LKA_LimitTorqueOut += 5;
      }
      else
      {
        Fv_LKA_LimitTorqueOut = 0;
      }
    }
    else
    {
      if(Fv_LKA_LimitTorqueOut - 5 > 0)
      {
        Fv_LKA_LimitTorqueOut -= 5;
      }
      else
      {
        Fv_LKA_LimitTorqueOut = 0;
      }
    }

  }

  /*根据人机共驾map，反馈lka输出力矩,2024.03.12 by zyg*/
  {
    if(Fv_LKA_LimitTorqueOut < 0)
    {
      rtb_lkatq = -Fv_LKA_LimitTorqueOut;
      rtb_lkatqdir = -1;
    }
    else
    {
      rtb_lkatq = Fv_LKA_LimitTorqueOut;
      rtb_lkatqdir = 1;
    }
    /*左正右负*/

    rtb_lkatqout = look1_iu16ls32n10ts16D_QWHCuzIb
        (rtb_lkatq, (const uint16 *)
         &Cal_LKA_TqOut_X[0], (const sint16 *)
         &Cal_LKA_TqOut_Y[0],
         &m_bpIndex_tqout, 24U);
    Fv_LKA_LimitTorque = rtb_lkatqdir * rtb_lkatqout;

  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<S1>/Improved_PI' */
}

/* Model initialize function */
void LQR_initialize(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S1>/Improved_PI' */
  /* InitializeConditions for Delay: '<S9>/AngLeadDelay1' */
  rtDW_l5cf_Lqr.icLoad = true;

  /* InitializeConditions for Delay: '<S9>/AngLeadDelay' */
  rtDW_l5cf_Lqr.icLoad_gq03 = true;

  /* InitializeConditions for Delay: '<S18>/SpdPdelay' */
  rtDW_l5cf_Lqr.icLoad_fd53 = true;

  /* InitializeConditions for Sum: '<S18>/Add9' incorporates:
   *  Delay: '<S8>/PIDelay'
   */
  rtDW_l5cf_Lqr.PIDelay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S21>/FCdelay' */
  rtDW_l5cf_Lqr.FCdelay_DSTATE = 0.0;

  /* SystemInitialize for MATLAB Function: '<S5>/Spd_KF' */
  /* '<S13>:1:5' Counter = 0; */
  /* '<S13>:1:6' AngIn = 0; */
  rtDW_l5cf_Lqr.P_gvra[0] = 1.0E+6;
  rtDW_l5cf_Lqr.P_gvra[1] = 0.0;
  rtDW_l5cf_Lqr.P_gvra[2] = 0.0;
  rtDW_l5cf_Lqr.P_gvra[3] = 1.0E+6;

  /* SystemInitialize for Atomic SubSystem: '<S10>/Sensor_Adjust' */
  /* InitializeConditions for Delay: '<S12>/SpdLeadDelay' */
  /* '<S11>:1:10' P=[Para1,0;0,Para2]; */
  /* '<S11>:1:11' x=[0,0]'; */
  /* '<S11>:1:12' cnt = 0; */
  rtDW_l5cf_Lqr.icLoad_dxex = true;

  /* InitializeConditions for Delay: '<S12>/SpdLeadDelay1' */
  rtDW_l5cf_Lqr.icLoad_kxck = true;

  /* End of SystemInitialize for SubSystem: '<S10>/Sensor_Adjust' */
  /* End of SystemInitialize for SubSystem: '<S1>/Improved_PI' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
