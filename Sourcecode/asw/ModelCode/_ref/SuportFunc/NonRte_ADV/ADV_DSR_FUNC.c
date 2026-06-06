/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_DSR_FUNC.c
 *
 * Code generated for Simulink model 'ADV_ExtFunction'.
 *
 * Model version                  : 9.98
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 25 08:42:28 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADV_ExtFunction.h"
#include "rtwtypes.h"
#include "ADV_DSR_FUNC.h"
#include "ADV_CCP_PROC.h"
#include "Rte_Type.h"
#include "ADV_ExtFunction_private.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "look2_is16u16ls32n10tu_gntPemx1.h"
#include "CalVarSupport.h"
#include "look2_is16u16ls32n10ts_TlwpcxFz.h"
#include "look1_is16ls32n10Ds32_plinlcas.h"
#include "look1_iu16ls32n10tu16_plinlcase.h"

/* Named constants for Chart: '<S69>/dsruseroprtmr' */
#define CONSTCNTMAX_lbb5               (1000000U)

/* Named constants for Chart: '<S71>/DSRControlLogic' */
#define IN_Active                      ((uint8)1U)
#define IN_Initialization              ((uint8)2U)
#define IN_Permanent                   ((uint8)3U)
#define IN_Ready                       ((uint8)4U)
#define IN_Temporary                   ((uint8)5U)

#define RECEIVE_MODE_DSR              0

ARID_DEF_ADV_DSR_FUNC_ADV_ExtFu rtADV_DSR_FUNC_ARID_DEF_ADV_Ext;

/* Output and update for atomic system: '<S3>/DSRControl_Cond' */
void DSRControl_Cond(void)
{
  sint32 cmd_grid_tmp;
  uint32 apa_trqstep;
  sint16 rtb_Abs4;
  sint16 rtb_handOver_trq;
  sint16 rtb_handOver_trq_tmp_tmp;
  sint16 tmp;
  uint16 rtb_overtime;
  uint8 dst_enable_tmp_0;
  boolean dst_enable_tmp;

  /* RelationalOperator: '<S85>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element16'
   *  RelationalOperator: '<S75>/Compare'
   *  RelationalOperator: '<S88>/Compare'
   */
#if RECEIVE_MODE_DSR
  dst_enable_tmp =
    Fv_CAN_AdsTqInvalid_flag;
#else
  dst_enable_tmp = Fv_AdsTqInvalid_flag;
#endif

  /* RelationalOperator: '<S73>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   *  RelationalOperator: '<S72>/Compare'
   *  RelationalOperator: '<S79>/Compare'
   *  RelationalOperator: '<S80>/Compare'
   *  RelationalOperator: '<S84>/Compare'
   */
#if RECEIVE_MODE_DSR
  dst_enable_tmp_0 = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVu8_CAN_AdsMod();
#else
  dst_enable_tmp_0 = Fv_AdsMod;
#endif

  /* Logic: '<S69>/AND' incorporates:
   *  Constant: '<S73>/Constant'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S85>/Constant'
   *  Delay: '<S3>/Delay'
   *  Inport generated from: '<Root>/In Bus Element16'
   *  Inport generated from: '<Root>/In Bus Element3'
   *  RelationalOperator: '<S73>/Compare'
   *  RelationalOperator: '<S83>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dst_enable = ((dst_enable_tmp_0 == ((uint8)0U))
    && (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE_c3kl == 0) &&
    (dst_enable_tmp == false));

  /* Chart: '<S69>/cmdgridcalc1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_cnt_ii3u < Cal_LKA_CMDSMP_TMR) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_cnt_ii3u++;
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_cnt_ii3u = 0U;
#if RECEIVE_MODE_DSR
    cmd_grid_tmp = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q7_CAN_AdsTqReq
      ();
#else
    cmd_grid_tmp = Fv_AdsTrqReq;
#endif
#if 0
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid = (sint16)((cmd_grid_tmp -
      (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_inlast_hfms << 3)) >> 3);
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_inlast_hfms = (sint16)(cmd_grid_tmp >> 3);
#else
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid = (sint16)(((Int32)cmd_grid_tmp -
      ((Int32)rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_inlast_hfms * 64)) >> 6);
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_inlast_hfms = (sint16)(cmd_grid_tmp >> 6);
#endif
  }

  /* End of Chart: '<S69>/cmdgridcalc1' */

  /* Abs: '<S69>/Abs4' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element22'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ < 0) {
    /* Abs: '<S69>/Abs4' */
    rtb_Abs4 = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  } else {
    /* Abs: '<S69>/Abs4' */
    rtb_Abs4 = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  }

  /* End of Abs: '<S69>/Abs4' */

  /* UnaryMinus: '<S69>/Unary Minus1' incorporates:
   *  Abs: '<S69>/Abs5'
   *  Inport generated from: '<Root>/In Bus Element2'
   */
#if RECEIVE_MODE_DSR
  rtb_handOver_trq_tmp_tmp =
    Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q7_CAN_AdsTqReq();
#else
  rtb_handOver_trq_tmp_tmp = Fv_AdsTrqReq;
#endif

  /* Signum: '<S69>/Sign3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   *  UnaryMinus: '<S69>/Unary Minus1'
   */
  if ((sint16)-rtb_handOver_trq_tmp_tmp < 0) {
    tmp = -1;
  } else {
    tmp = (sint16)((sint16)-rtb_handOver_trq_tmp_tmp > 0);
  }

  /* Lookup_n-D: '<S69>/dsr_vs_handOvertrq' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_handOver_trq = look1_iu16ls32n10ts16D_QWHCuzIb
    (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const uint16 *)
     &Cal_LKA_HandOverMaxTrqTab_V[0], (const sint16 *)
     &Cal_LKA_HandOverMaxTrqTab_T[0],
     &rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_fa2a, 8U);

  /* Lookup_n-D: '<S69>/dsr_override' incorporates:
   *  Abs: '<S69>/Abs4'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_overtime = look2_is16u16ls32n10tu_gntPemx1(rtb_Abs4,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_HandOverTimeTab_A[0], (const uint16 *)&Cal_LKA_HandOverTimeTab_V[0],
    (const uint16 *)&Cal_LKA_HandOverTimeTab_T[0],
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_bxat, rtCP_dsr_override_maxIndex,
    9U);

  /* Chart: '<S69>/dsruseroprtmr' incorporates:
   *  Abs: '<S69>/Abs4'
   *  Lookup_n-D: '<S69>/dsr_vs_handOvertrq'
   *  RelationalOperator: '<S69>/Relational Operator'
   */
  if (rtb_overtime == 0) {
    apa_trqstep = CONSTCNTMAX_lbb5;
  } else {
    apa_trqstep = CONSTCNTMAX_lbb5 / rtb_overtime;
  }

  if (rtb_Abs4 > rtb_handOver_trq) {
    if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt < CONSTCNTMAX_lbb5) {
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt += apa_trqstep;
    } else {
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.trqover_flag = true;
    }
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.trqover_flag = false;
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt = 0U;
  }

  /* End of Chart: '<S69>/dsruseroprtmr' */

  /* Signum: '<S69>/Sign2' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element22'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ < 0) {
    rtb_Abs4 = -1;
  } else {
    rtb_Abs4 = (sint16)
      (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ > 0);
  }

  /* Logic: '<S69>/Logical Operator2' incorporates:
   *  Constant: '<S69>/Constant1'
   *  Constant: '<S69>/Constant3'
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  Constant: '<S77>/Constant'
   *  Logic: '<S69>/Logical Operator3'
   *  RelationalOperator: '<S69>/Relational Operator1'
   *  RelationalOperator: '<S74>/Compare'
   *  RelationalOperator: '<S75>/Compare'
   *  RelationalOperator: '<S77>/Compare'
   *  Signum: '<S69>/Sign2'
   *  Signum: '<S69>/Sign3'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lka_temporary = (((tmp == rtb_Abs4) &&
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.trqover_flag) ||
    (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1 == true) ||
    false || (dst_enable_tmp == true) || false ||
    (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s == 1));
  
  /* Chart: '<S69>/dsr_temporarytmr' */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lka_temporary) {
    if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.temporary_cnt <
        Cal_LKA_TEMPO_OVERTIME_TMR) {
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.temporary_cnt++;
    } else {
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.overtime_flag = true;
    }
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.overtime_flag = false;
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.temporary_cnt = 0U;
  }

  /* End of Chart: '<S69>/dsr_temporarytmr' */

  /* Abs: '<S69>/Abs2' */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid < 0) {
    tmp = (sint16)-rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid;
  } else {
    tmp = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid;
  }

  /* Abs: '<S69>/Abs5' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   *  UnaryMinus: '<S69>/Unary Minus1'
   */
  if (rtb_handOver_trq_tmp_tmp < 0) {
    rtb_handOver_trq_tmp_tmp = (sint16)-rtb_handOver_trq_tmp_tmp;
  }

  /* Logic: '<S69>/Logical Operator9' incorporates:
   *  Abs: '<S69>/Abs2'
   *  Abs: '<S69>/Abs5'
   *  Constant: '<S76>/Constant'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Logic: '<S69>/Logical Operator5'
   *  RelationalOperator: '<S76>/Compare'
   *  RelationalOperator: '<S78>/Compare'
   *  RelationalOperator: '<S86>/Compare'
   *  RelationalOperator: '<S87>/Compare'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_permanent =
    (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.overtime_flag || (tmp >
      ((Cal_LKA_TRQCMD_RATE_FRAME + 32) >> 6)) || (rtb_handOver_trq_tmp_tmp >
      ((Cal_LKA_TRQCMD_RANGE ))) ||
     ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FRP_FAI == 1) ||
      (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_bf30 == 1)));
// debug_jing2 = (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.overtime_flag) |(tmp > ((Cal_LKA_TRQCMD_RATE_FRAME + 32) >> 6))<<1|
//     (rtb_handOver_trq_tmp_tmp >((Cal_LKA_TRQCMD_RANGE )))<<2 |
//     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FRP_FAI == 1)<<3|
//     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_bf30 == 1)<<4;
  /* Logic: '<S69>/OR' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  Logic: '<S69>/Logical Operator8'
   *  RelationalOperator: '<S81>/Compare'
   *  RelationalOperator: '<S82>/Compare'
   *  RelationalOperator: '<S88>/Compare'
   *  RelationalOperator: '<S89>/Compare'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.suppression =
    ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ <
      Cal_LKA_VSSTART) ||
     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ > Cal_LKA_VSEND)
     || (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_BHM_MOD !=
         HOLD_ACTIVE) || (dst_enable_tmp == true));

  /* Logic: '<S69>/OR1' incorporates:
   *  Constant: '<S72>/Constant'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  Constant: '<S84>/Constant'
   *  Constant: '<S90>/Constant'
   *  Logic: '<S69>/Logical Operator10'
   *  Logic: '<S69>/Logical Operator4'
   *  RelationalOperator: '<S72>/Compare'
   *  RelationalOperator: '<S79>/Compare'
   *  RelationalOperator: '<S80>/Compare'
   *  RelationalOperator: '<S84>/Compare'
   *  RelationalOperator: '<S90>/Compare'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_active = (((dst_enable_tmp_0 == ((uint8)9U))
    && (rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Compare_bd4g == true)) ||
    ((dst_enable_tmp_0 == ((uint8)6U)) || (dst_enable_tmp_0 == ((uint8)7U)) ||
     (dst_enable_tmp_0 == ((uint8)8U))));
}

/* Output and update for atomic system: '<S70>/DSRControl_Logic_Limit' */
void DSRControl_Logic_Limit(void)
{
  sint32 tmp;
  sint32 tmp_0;

  /* Chart: '<S94>/cmdrate' incorporates:
   *  Constant: '<S94>/Constant2'
   *  Inport generated from: '<Root>/In Bus Element2'
   */
#if RECEIVE_MODE_DSR
  tmp_0 = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q7_CAN_AdsTqReq();
#else
  tmp_0 = Fv_AdsTrqReq;
#endif
  tmp = (tmp_0) - rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_cng5;
  if (tmp > Cal_LKA_TRQCMD_RATE) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_cng5 += Cal_LKA_TRQCMD_RATE;
  } else if (tmp < -Cal_LKA_TRQCMD_RATE) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_cng5 -= Cal_LKA_TRQCMD_RATE;
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_cng5 = (sint16)(tmp_0);
  }

  /* End of Chart: '<S94>/cmdrate' */

  /* Switch: '<S96>/Switch2' incorporates:
   *  Constant: '<S94>/Constant'
   *  Constant: '<S94>/Constant1'
   *  RelationalOperator: '<S96>/LowerRelop1'
   *  RelationalOperator: '<S96>/UpperRelop'
   *  Switch: '<S96>/Switch'
   *  UnaryMinus: '<S94>/Unary Minus'
   */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_cng5 > Cal_LKA_TRQCMD_RANGE) {
    /* Switch: '<S96>/Switch2' */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd = Cal_LKA_TRQCMD_RANGE;
  } else if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_cng5 < (sint16)-
             Cal_LKA_TRQCMD_RANGE) {
    /* Switch: '<S96>/Switch' incorporates:
     *  Constant: '<S94>/Constant'
     *  Switch: '<S96>/Switch2'
     *  UnaryMinus: '<S94>/Unary Minus'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd = (sint16)-Cal_LKA_TRQCMD_RANGE;
  } else {
    /* Switch: '<S96>/Switch2' incorporates:
     *  Switch: '<S96>/Switch'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd =
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_cng5;
  }

  /* End of Switch: '<S96>/Switch2' */
}

/* Output and update for atomic system: '<S95>/DSRControl_Logic_RateMax' */
void DSRControl_Logic_RateMax(void)
{
  sint32 tmp;

  /* Chart: '<S99>/cmdrate' incorporates:
   *  Constant: '<S99>/Constant3'
   *  Merge: '<S95>/Merge'
   */
  tmp = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdinput -
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout;
  if (tmp > Cal_LKA_TRQOUT_RATE) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout += Cal_LKA_TRQOUT_RATE;
  } else if (tmp < -Cal_LKA_TRQOUT_RATE) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout -= Cal_LKA_TRQOUT_RATE;
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout =
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdinput;
  }
  //debug_jing2 = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdinput;//add by liuyang

  /* End of Chart: '<S99>/cmdrate' */

  /* Switch: '<S111>/Switch2' incorporates:
   *  Constant: '<S99>/Constant1'
   *  Constant: '<S99>/Constant2'
   *  RelationalOperator: '<S111>/LowerRelop1'
   *  RelationalOperator: '<S111>/UpperRelop'
   *  Switch: '<S111>/Switch'
   *  UnaryMinus: '<S99>/Unary Minus'
   */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout > Cal_LKA_TRQOUT_RANGE) {
    /* Switch: '<S111>/Switch2' */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_d4s5 = Cal_LKA_TRQOUT_RANGE;
  } else if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout < (sint16)-
             Cal_LKA_TRQOUT_RANGE) {
    /* Switch: '<S111>/Switch' incorporates:
     *  Constant: '<S99>/Constant2'
     *  Switch: '<S111>/Switch2'
     *  UnaryMinus: '<S99>/Unary Minus'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_d4s5 = (sint16)-Cal_LKA_TRQOUT_RANGE;
  } else {
    /* Switch: '<S111>/Switch2' incorporates:
     *  Switch: '<S111>/Switch'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_d4s5 =
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout;
  }

  /* End of Switch: '<S111>/Switch2' */
}

/* Output and update for atomic system: '<S98>/DSR_ActiveState_Adv' */
void DSR_ActiveState_Adv(void)
{
  sint32 rtb_Divide;
  sint16 rtb_Switch_m3ax;
  sint16 tmp;

  /* Chart: '<S101>/cmdgridcalc' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_cnt < Cal_LKA_CMDSMP_TMR) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_cnt++;
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_cnt = 0U;
#if RECEIVE_MODE_DSR
    rtb_Divide = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q7_CAN_AdsTqReq();
#else
    rtb_Divide = Fv_AdsTrqReq;
#endif
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid_g5yz = (sint16)((rtb_Divide ) -
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_inlast);
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_inlast = (sint16)(rtb_Divide);
  }

  /* End of Chart: '<S101>/cmdgridcalc' */

  /* Sum: '<S101>/ARSumFilter1' incorporates:
   *  Constant: '<S101>/filcf'
   *  Product: '<S101>/ARProductFilter1'
   *  Sum: '<S101>/ARSubFilter1'
   *  UnitDelay: '<S101>/ARDelayFilter1'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lastsigout = (sint16)((((sint16)
    (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid_g5yz -
     rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lastsigout) * Cal_LKA_FilterCoef) >> 10) +
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lastsigout);

  /* Product: '<S101>/Divide' incorporates:
   *  Constant: '<S101>/Constant4'
   *  Gain: '<S101>/Gain'
   */
  rtb_Divide = 1000 * rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid_g5yz /
    Cal_LKA_CMDSMP_TMR;

  /* Switch: '<S107>/Switch2' incorporates:
   *  Constant: '<S101>/Constant5'
   *  Constant: '<S101>/Constant6'
   *  Product: '<S101>/Divide'
   *  RelationalOperator: '<S107>/LowerRelop1'
   *  RelationalOperator: '<S107>/UpperRelop'
   *  Switch: '<S107>/Switch'
   *  UnaryMinus: '<S101>/Unary Minus'
   *  UnaryMinus: '<S101>/Unary Minus1'
   */
  if (rtb_Divide > Cal_LKA_GRADCMD_RANGE) {
    /* DataTypeConversion: '<S101>/Data Type Conversion' incorporates:
     *  Delay: '<S98>/Delay'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE = Cal_LKA_GRADCMD_RANGE;
  } else if (rtb_Divide < (sint16)-Cal_LKA_GRADCMD_RANGE) {
    /* Switch: '<S107>/Switch' incorporates:
     *  Constant: '<S101>/Constant6'
     *  DataTypeConversion: '<S101>/Data Type Conversion'
     *  Delay: '<S98>/Delay'
     *  UnaryMinus: '<S101>/Unary Minus'
     *  UnaryMinus: '<S101>/Unary Minus1'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE = (sint16)-
      Cal_LKA_GRADCMD_RANGE;
  } else {
    /* DataTypeConversion: '<S101>/Data Type Conversion' incorporates:
     *  Delay: '<S98>/Delay'
     *  Switch: '<S107>/Switch'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE = (sint16)rtb_Divide;
  }

  /* End of Switch: '<S107>/Switch2' */

  /* Signum: '<S101>/Sign1' */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid_g5yz < 0) {
    rtb_Switch_m3ax = -1;
  } else {
    rtb_Switch_m3ax = (sint16)(rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmd_grid_g5yz > 0);
  }

  /* Signum: '<S101>/Sign' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
#if RECEIVE_MODE_DSR
  rtb_Divide = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q7_CAN_AdsTqReq();
#else
  rtb_Divide = Fv_AdsTrqReq;
#endif
  if (rtb_Divide < 0) {
    tmp = -1;
  } else {
    tmp = (sint16)(rtb_Divide > 0);
  }

  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S105>/Constant'
   *  Product: '<S101>/Product'
   *  RelationalOperator: '<S105>/Compare'
   *  Signum: '<S101>/Sign'
   *  Signum: '<S101>/Sign1'
   */
  if (rtb_Switch_m3ax * tmp == (-1)) {
    /* Switch: '<S101>/Switch' incorporates:
     *  Sum: '<S101>/ARSumFilter1'
     */
    rtb_Switch_m3ax = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lastsigout;
  } else {
    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S101>/Constant'
     */
    rtb_Switch_m3ax = 0;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Chart: '<S101>/cmdoutrate' incorporates:
   *  Constant: '<S101>/Constant2'
   *  Switch: '<S101>/Switch'
   */
  rtb_Divide = rtb_Switch_m3ax - rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_nbym;
  if (rtb_Divide > Cal_LKA_ADVCMD_RATE) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_nbym += Cal_LKA_ADVCMD_RATE;
  } else if (rtb_Divide < -Cal_LKA_ADVCMD_RATE) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_nbym -= Cal_LKA_ADVCMD_RATE;
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_nbym = rtb_Switch_m3ax;
  }

  /* End of Chart: '<S101>/cmdoutrate' */

  /* UnaryMinus: '<S101>/Unary Minus' incorporates:
   *  Abs: '<S102>/Abs'
   *  Lookup_n-D: '<S101>/lka_cmdcoef2'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_Switch_m3ax = look2_is16u16ls32n10ts_TlwpcxFz
    (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Abs,
     rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
     &Cal_LKA_CmdCoefTab_A[0], (const uint16 *)&Cal_LKA_CmdCoefTab_V[0], (const
      sint16 *)&Cal_LKA_CmdCoefTab_T[0],
     rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_kdie, rtCP_lka_cmdcoef2_maxIndex,
     7U);

  /* Product: '<S101>/Product1' incorporates:
   *  UnaryMinus: '<S101>/Unary Minus'
   */
  rtb_Switch_m3ax = (sint16)((rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdout_nbym *
    rtb_Switch_m3ax) >> 7);

  /* Switch: '<S106>/Switch2' incorporates:
   *  Constant: '<S101>/Constant1'
   *  Constant: '<S101>/Constant3'
   *  Product: '<S101>/Product1'
   *  RelationalOperator: '<S106>/LowerRelop1'
   *  RelationalOperator: '<S106>/UpperRelop'
   *  Switch: '<S106>/Switch'
   *  UnaryMinus: '<S101>/Unary Minus'
   */
  if (rtb_Switch_m3ax > Cal_LKA_TRQADVCOMP_MAX) {
    /* Switch: '<S106>/Switch2' */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_dfgf = Cal_LKA_TRQADVCOMP_MAX;
  } else if (rtb_Switch_m3ax < (sint16)-Cal_LKA_TRQADVCOMP_MAX) {
    /* Switch: '<S106>/Switch' incorporates:
     *  Constant: '<S101>/Constant1'
     *  Switch: '<S106>/Switch2'
     *  UnaryMinus: '<S101>/Unary Minus'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_dfgf = (sint16)-
      Cal_LKA_TRQADVCOMP_MAX;
  } else {
    /* Switch: '<S106>/Switch2' incorporates:
     *  Switch: '<S106>/Switch'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_dfgf = rtb_Switch_m3ax;
  }

  /* End of Switch: '<S106>/Switch2' */
}

/* Output and update for atomic system: '<S98>/DSR_ActiveState_Base' */
void DSR_ActiveState_Base(void)
{
  sint16 rtb_AimSpeedt;
  sint16 rtb_gradcoef;
  sint16 tmp;

  /* Abs: '<S102>/Abs' incorporates:
   *  Switch: '<S96>/Switch2'
   */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd < 0) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Abs = (sint16)-
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd;
  } else {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Abs =
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd;
  }

  /* End of Abs: '<S102>/Abs' */

  /* Lookup_n-D: '<S102>/AimSpeedt' incorporates:
   *  Abs: '<S102>/Abs'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_AimSpeedt = look2_is16u16ls32n10ts_TlwpcxFz
    (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Abs,
     rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
     &Cal_LKA_AimCurrentTab_A[0], (const uint16 *)&Cal_LKA_AimCurrentTab_V[0], (
      const sint16 *)&Cal_LKA_AimCurrentTab_T[0],
     rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_l0uy, rtCP_AimSpeedt_maxIndex, 7U);

  /* Abs: '<S102>/Abs1' incorporates:
   *  Delay: '<S98>/Delay'
   */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE < 0) {
    tmp = (sint16)-rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE;
  } else {
    tmp = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE;
  }

  /* Lookup_n-D: '<S102>/gradcoef' incorporates:
   *  Abs: '<S102>/Abs1'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_gradcoef = look2_is16u16ls32n10ts_TlwpcxFz(tmp,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_GradCoefTab_A[0], (const uint16 *)&Cal_LKA_GradCoefTab_V[0], (const
    sint16 *)&Cal_LKA_GradCoefTab_T[0],
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_atui, rtCP_gradcoef_maxIndex, 4U);

  /* Signum: '<S102>/Sign' incorporates:
   *  Switch: '<S96>/Switch2'
   */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd < 0) {
    tmp = -1;
  } else {
    tmp = (sint16)(rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_ibjd > 0);
  }

  /* Product: '<S102>/Product1' incorporates:
   *  Lookup_n-D: '<S102>/AimSpeedt'
   *  Lookup_n-D: '<S102>/gradcoef'
   *  Product: '<S102>/Product'
   *  Signum: '<S102>/Sign'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsrbasecurrent = (sint16)(((sint16)(tmp *
    rtb_AimSpeedt) * rtb_gradcoef) >> 7);
}

/* Output and update for atomic system: '<S98>/DSR_ActiveState_Damp' */
void DSR_ActiveState_Damp(void)
{
  sint16 rtb_Product3;
  sint16 rtb_UnaryMinus_mzbe;
  sint16 rtb_UnaryMinus_oofu;
  sint16 rtb_dsr_dampcomp;

  /* Abs: '<S103>/Abs1' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element8'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n < 0) {
    rtb_Product3 = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n;
  } else {
    rtb_Product3 = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n;
  }

  /* Lookup_n-D: '<S103>/dsr_dampcomp' incorporates:
   *  Abs: '<S103>/Abs1'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_dsr_dampcomp = look2_is16u16ls32n10ts_TlwpcxFz(rtb_Product3,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_DampCompTab_A[0], (const uint16 *)&Cal_LKA_DampCompTab_V[0], (const
    sint16 *)&Cal_LKA_DampCompTab_T[0],
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_esah, rtCP_dsr_dampcomp_maxIndex,
    7U);

  /* Abs: '<S103>/Abs2' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element19'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG < 0) {
    rtb_Product3 = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG;
  } else {
    rtb_Product3 = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG;
  }

  /* UnaryMinus: '<S103>/Unary Minus' incorporates:
   *  Abs: '<S102>/Abs'
   *  Abs: '<S103>/Abs2'
   *  Lookup_n-D: '<S103>/dsr_dampang_coef'
   *  Lookup_n-D: '<S103>/dsr_dampcmd_coef'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_UnaryMinus_mzbe = look2_is16u16ls32n10ts_TlwpcxFz(rtb_Product3,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_DampAngTab_A[0], (const uint16 *)&Cal_LKA_DampAngTab_V[0], (const
    sint16 *)&Cal_LKA_DampAngTab_T[0],
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_o203,
    rtCP_dsr_dampang_coef_maxIndex, 7U);
  rtb_UnaryMinus_oofu = look1_is16ls32n10Ds32_plinlcas
    (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Abs, (const sint16 *)
     &Cal_LKA_DampCoefTab_X[0], (const sint16 *)&Cal_LKA_DampCoefTab_Y[0],
     &rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_fdyw, 6U);

  /* Signum: '<S103>/Sign1' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element8'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n < 0) {
    rtb_Product3 = -1;
  } else {
    rtb_Product3 = (sint16)
      (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n > 0);
  }

  /* Product: '<S103>/Product3' incorporates:
   *  Lookup_n-D: '<S103>/dsr_dampcomp'
   *  Product: '<S103>/Product1'
   *  Product: '<S103>/Product2'
   *  Signum: '<S103>/Sign1'
   *  UnaryMinus: '<S103>/Unary Minus'
   *  UnaryMinus: '<S103>/Unary Minus2'
   */
  rtb_Product3 = (sint16)(((sint16)(((sint16)(-rtb_Product3 * rtb_dsr_dampcomp) *
    rtb_UnaryMinus_mzbe) >> 7) * rtb_UnaryMinus_oofu) >> 10);

  /* Switch: '<S110>/Switch2' incorporates:
   *  Constant: '<S103>/Constant1'
   *  Constant: '<S103>/Constant3'
   *  Product: '<S103>/Product3'
   *  RelationalOperator: '<S110>/LowerRelop1'
   *  RelationalOperator: '<S110>/UpperRelop'
   *  Switch: '<S110>/Switch'
   *  UnaryMinus: '<S103>/Unary Minus'
   */
  if (rtb_Product3 > Cal_LKA_TRQDMPCOMP_MAX) {
    /* Switch: '<S110>/Switch2' */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2 = Cal_LKA_TRQDMPCOMP_MAX;
  } else if (rtb_Product3 < (sint16)-Cal_LKA_TRQDMPCOMP_MAX) {
    /* Switch: '<S110>/Switch' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Switch: '<S110>/Switch2'
     *  UnaryMinus: '<S103>/Unary Minus'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2 = (sint16)-Cal_LKA_TRQDMPCOMP_MAX;
  } else {
    /* Switch: '<S110>/Switch2' incorporates:
     *  Switch: '<S110>/Switch'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2 = rtb_Product3;
  }

  /* End of Switch: '<S110>/Switch2' */
}

/* Output and update for atomic system: '<S98>/DSR_ActiveState_Limit' */
void DSR_ActiveState_Limit(void)
{
  uint16 rtb_dsr_vscoef;

  /* Lookup_n-D: '<S104>/dsr_vscoef' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_dsr_vscoef = look1_iu16ls32n10tu16_plinlcase
    (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const uint16 *)
     &Cal_LKA_VsCoefTab_X[0], (const uint16 *)&Cal_LKA_VsCoefTab_Y[0],
     &rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.m_bpIndex, 5U);

  /* Product: '<S104>/Product4' incorporates:
   *  Lookup_n-D: '<S104>/dsr_vscoef'
   *  Merge: '<S95>/Merge'
   *  Product: '<S102>/Product1'
   *  Sum: '<S104>/Add2'
   *  Switch: '<S106>/Switch2'
   *  Switch: '<S110>/Switch2'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdinput = (sint16)
    ((((rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2 +
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsrbasecurrent) +
       rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_dfgf) * rtb_dsr_vscoef) >> 10);


}

/* Output and update for atomic system: '<S70>/DSRControl_Logic_Trq' */
void DSRControl_Logic_Trq(void)
{
  /* If: '<S95>/If' */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts == 2) {
    /* Outputs for IfAction SubSystem: '<S95>/DSRControl_Logic_ActiveState' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S98>/DSR_ActiveState_Base' */
    DSR_ActiveState_Base();

    /* End of Outputs for SubSystem: '<S98>/DSR_ActiveState_Base' */

    /* Outputs for Atomic SubSystem: '<S98>/DSR_ActiveState_Adv' */
    DSR_ActiveState_Adv();

    /* End of Outputs for SubSystem: '<S98>/DSR_ActiveState_Adv' */

    /* Outputs for Atomic SubSystem: '<S98>/DSR_ActiveState_Damp' */
    DSR_ActiveState_Damp();

    /* End of Outputs for SubSystem: '<S98>/DSR_ActiveState_Damp' */

    /* Outputs for Atomic SubSystem: '<S98>/DSR_ActiveState_Limit' */
    DSR_ActiveState_Limit();

    /* End of Outputs for SubSystem: '<S98>/DSR_ActiveState_Limit' */
    /* End of Outputs for SubSystem: '<S95>/DSRControl_Logic_ActiveState' */
  } else {
    /* Outputs for IfAction SubSystem: '<S95>/DSRControl_Logic_StopState' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    /* SignalConversion generated from: '<S100>/lkacurrent' incorporates:
     *  Constant: '<S100>/Constant'
     *  Merge: '<S95>/Merge'
     */
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.cmdinput = 0;

    /* End of Outputs for SubSystem: '<S95>/DSRControl_Logic_StopState' */
  }

  /* End of If: '<S95>/If' */

  /* Outputs for Atomic SubSystem: '<S95>/DSRControl_Logic_RateMax' */
  DSRControl_Logic_RateMax();

  /* End of Outputs for SubSystem: '<S95>/DSRControl_Logic_RateMax' */
}

/* Output and update for atomic system: '<S3>/DSRControl_Exec' */
void DSRControl_Exec(void)
{
  /* Outputs for Atomic SubSystem: '<S70>/DSRControl_Logic_Limit' */
  DSRControl_Logic_Limit();

  /* End of Outputs for SubSystem: '<S70>/DSRControl_Logic_Limit' */

  /* Outputs for Atomic SubSystem: '<S70>/DSRControl_Logic_Trq' */
  DSRControl_Logic_Trq();

  /* End of Outputs for SubSystem: '<S70>/DSRControl_Logic_Trq' */
}

/* Output and update for atomic system: '<S3>/DSRControl_Logic' */
void DSRControl_Logic(void)
{
  boolean tmp;

  /* Chart: '<S71>/DSRControlLogic' */
  if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_active_c19_ADV_ExtFunction == 0U) {
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_active_c19_ADV_ExtFunction = 1U;
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Initialization;
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 0U;
  } else {
    switch (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction) {
     case IN_Active:
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 2U;
      if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_permanent) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Permanent;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 4U;
      } else if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lka_temporary) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Temporary;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 3U;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_flag = false;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_cnt = Cal_LKA_TEMPRECOVER_TMR;
      } else if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.suppression) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction =
          IN_Initialization;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 0U;
      } else if (!rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_active) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Ready;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 1U;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_activetriger = false;
      }
      break;

     case IN_Initialization:
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 0U;
      if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_permanent) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Permanent;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 4U;
      } else if ((!rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.suppression) &&
                 (!rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lka_temporary)) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Ready;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 1U;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_activetriger = false;
      }
      break;

     case IN_Permanent:
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 4U;
      break;

     case IN_Ready:
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 1U;
      if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_permanent) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Permanent;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 4U;
      } else if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lka_temporary) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Temporary;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 3U;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_flag = false;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_cnt = Cal_LKA_TEMPRECOVER_TMR;
      } else if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.suppression) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction =
          IN_Initialization;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 0U;
      } else if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_active &&
                 rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_activetriger) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Active;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 2U;
      } else {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_activetriger =
          ((rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_active &&
            (!rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_active_last)) ||
           rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_activetriger);
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_active_last =
          rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_active;
      }
      break;

     default:
      /* case IN_Temporary: */
      rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 3U;
      if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_permanent) {
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Permanent;
        rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 4U;
      } else {
        tmp = !rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.lka_temporary;
        if (tmp && rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_flag &&
            rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dst_enable) {
          rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.is_c19_ADV_ExtFunction = IN_Ready;
          rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts = 1U;
          rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_activetriger = false;
        } else if (tmp) {
          if (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_cnt > 0) {
            rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_cnt--;
          } else {
            rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_flag = true;
          }
        } else {
          rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_flag = false;
          rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.dsr_temp_cnt = Cal_LKA_TEMPRECOVER_TMR;
        }
      }
      break;
    }
  }
  Fv_DSR_ControlSts = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts;
  /* End of Chart: '<S71>/DSRControlLogic' */
}

/* Output and update for atomic system: '<Root>/ADV_DSR_FUNC' */
void ADV_DSR_FUNC(void)
{
  /* Outputs for Atomic SubSystem: '<S3>/DSRControl_Cond' */
  DSRControl_Cond();

  /* End of Outputs for SubSystem: '<S3>/DSRControl_Cond' */

  /* Outputs for Atomic SubSystem: '<S3>/DSRControl_Logic' */
  DSRControl_Logic();

  /* End of Outputs for SubSystem: '<S3>/DSRControl_Logic' */

  /* Outputs for Atomic SubSystem: '<S3>/DSRControl_Exec' */
  DSRControl_Exec();

  /* End of Outputs for SubSystem: '<S3>/DSRControl_Exec' */

  /* Update for Delay: '<S3>/Delay' incorporates:
   *  Switch: '<S111>/Switch2'
   */
  rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE_c3kl =
    rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_d4s5;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
