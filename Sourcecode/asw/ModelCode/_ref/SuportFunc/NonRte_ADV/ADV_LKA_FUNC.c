/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_LKA_FUNC.c
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
#include "ADV_LKA_FUNC.h"
#include "ADV_CCP_PROC.h"
#include "Rte_Type.h"
#include "ADV_ExtFunction_private.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "look2_is16u16ls32n10tu_gntPemx1.h"
#include "CalVarSupport.h"
#include "GlobalVarSupport.h"
#include "SimDiagMacro.h"
#include "CalVar.h"

#include "LQR.h"
/* Named constants for Chart: '<S142>/lkauseroprtmr' */
#define CONSTCNTMAX_mef0               (1000000U)

/* Named constants for Chart: '<S144>/LKAControlLogic' */
#define IN_Active_ke1u                 ((uint8)1U)
#define IN_Initialization_eyzg         ((uint8)2U)
#define IN_Permanent_g4tw              ((uint8)3U)
#define IN_Ready_iatp                  ((uint8)4U)
#define IN_Temporary_pl5k              ((uint8)5U)
/* 1:锟脚猴拷     0:全锟街憋拷锟斤拷,23.11.10 by zyg*/
#define RECEIVE_MODE_LKA               0




sint16 look1_is16bs16n7ls32n1_8I508xgm(sint16 u0, const sint16 bp0[], const
  sint16 table[], uint32 prevIndex[], uint32 maxIndex)
{
  sint32 frac;
  uint32 bpIdx;
  sint16 uCast;
  sint16 y;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16bs16n7ls32n10ts16Ds32_plinlcas
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
  if (u0 > 255) {
    uCast = MAX_int16_T;
  } else if (u0 <= -256) {
    uCast = MIN_int16_T;
  } else {
    uCast = (sint16)(u0 << 7);
  }

  if ((u0 << 7) < bp0[0U]) {
    bpIdx = 0U;
    frac = 0;
  } else if (uCast < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; uCast < bp0[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (sint32)(((uint64)(((uint32)u0 << 7) - (uint32)bp0[bpIdx]) <<
                      10) / (uint16)(bp0[bpIdx + 1U] - bp0[bpIdx]));
  } else {
    bpIdx = maxIndex;
    frac = 0;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    uCast = table[bpIdx];
    y = (sint16)((sint16)(((table[bpIdx + 1U] - uCast) * frac) >> 10) + uCast);
  }

  return y;
}



ARID_DEF_ADV_LKA_FUNC_ADV_ExtFu rtADV_LKA_FUNC_ARID_DEF_ADV_Ext;
Int32 asr_s32_lka(Int32 u, UInt32 n)
{
  Int32 y;
  if (u >= 0) {
    y = (Int32)((UInt32)(((UInt32)u) >> n));
  } else {
    y = (-((Int32)((UInt32)(((UInt32)((Int32)(-1 - u))) >> n)))) - 1;
  }
  return y;
}

/* Output and update for atomic system: '<S6>/LKAControl_Cond' */
void LKAControl_Cond(void)
{
  sint32 rtb_handOver_trq_gjut_tmp;
  uint32 apa_trqstep;
  sint16 cmd_grid_tmp;
  sint16 rtb_Abs4;
  sint16 rtb_handOver_trq;
  uint16 rtb_overtime;
  uint8 lka_stop_flag_bmc2_tmp_0;
  boolean lka_stop_flag_bmc2_tmp;
  boolean lka_nop_lka_cond;
  /* RelationalOperator: '<S160>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element18'
   *  RelationalOperator: '<S148>/Compare'
   */
#if RECEIVE_MODE_LKA
  lka_stop_flag_bmc2_tmp =
    Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVbl_CAN_AdsAgInvalid_flag();
#else
  lka_stop_flag_bmc2_tmp = Fv_AdsAgInvalid_flag;
#endif
  /* RelationalOperator: '<S162>/Compare' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   *  RelationalOperator: '<S145>/Compare'
   *  RelationalOperator: '<S152>/Compare'
   *  RelationalOperator: '<S153>/Compare'
   *  RelationalOperator: '<S157>/Compare'
   *  RelationalOperator: '<S158>/Compare'
   *  RelationalOperator: '<S166>/Compare'
   */
#if RECEIVE_MODE_LKA
  lka_stop_flag_bmc2_tmp_0 =
    Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVu8_CAN_AdsMod();
#else
  lka_stop_flag_bmc2_tmp_0 = Fv_AdsMod;
  
  //add by liuyang for NOP requset at 241106
  lka_nop_lka_cond = ((lka_stop_flag_bmc2_tmp_0 >=2 && lka_stop_flag_bmc2_tmp_0 <=4 ) ||
  (lka_stop_flag_bmc2_tmp_0 ==9));

  if( Fv_LKA_ADL3ADMod != 0){
    if (lka_nop_lka_cond && Fv_LKA_ControlSts != 2){
        Fv_LKA_ADL3ADMod = 0;
        Fv_LKA_ADL3CtrlStsSts = 1;     
    }else{
         Fv_LKA_ADL3ADMod = Fv_NOPMod;
         Fv_LKA_ADL3CtrlStsSts = 0;
      }
  } else 
  {
    if (lka_nop_lka_cond && Fv_LKA_ControlSts == 2 ){
       Fv_LKA_ADL3ADMod = 0;
       if(Fv_NOPMod != 0){
            Fv_LKA_ADL3CtrlStsSts = 1;
       }else{
            Fv_LKA_ADL3CtrlStsSts = 0;       
       }

    }else if(Fv_LKA_ControlSts == 2 && Fv_AdsMod ==1){
        Fv_LKA_ADL3ADMod = Fv_NOPMod;
       Fv_LKA_ADL3CtrlStsSts = 0;
      }else if(Fv_LKA_ControlSts == 2||Fv_DSR_Torque !=0 ||Fv_APA_ControlSts ==2){
       Fv_LKA_ADL3ADMod = 0;
       Fv_LKA_ADL3CtrlStsSts = 0;

    }else{
        Fv_LKA_ADL3ADMod = Fv_NOPMod;
        Fv_LKA_ADL3CtrlStsSts = 0;
    }
  }




#endif
  /* SignalConversion: '<S174>/Signal Copy' incorporates:
   *  Constant: '<S160>/Constant'
   *  Constant: '<S162>/Constant'
   *  Constant: '<S163>/Constant'
   *  Delay: '<S6>/Delay'
   *  Inport generated from: '<Root>/In Bus Element18'
   *  Inport generated from: '<Root>/In Bus Element3'
   *  Logic: '<S142>/AND'
   *  RelationalOperator: '<S160>/Compare'
   *  RelationalOperator: '<S162>/Compare'
   *  RelationalOperator: '<S163>/Compare'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag_bmc2 =
    ((lka_stop_flag_bmc2_tmp_0 == ((uint8)0U)) &&
     (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE == 0) &&
     (lka_stop_flag_bmc2_tmp == false));

  /* Chart: '<S142>/cmdgridcalc' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_cnt < Cal_LKA_CMDSMP_TMR) {
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_cnt++;
  } else {
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_cnt = 0U;
#if RECEIVE_MODE_LKA
    cmd_grid_tmp = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q4_CAN_AdsAgReq
      ();
#else

    cmd_grid_tmp = Fv_AdsAgReq;
    Fv_FAA_LQR_AimAng = ((double)Fv_AdsAgReq)/16;
#endif
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_grid = (sint16)(cmd_grid_tmp -
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_inlast);
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_inlast = cmd_grid_tmp;

  }

  /* End of Chart: '<S142>/cmdgridcalc' */

  /* Sum: '<S142>/Subtract' incorporates:
   *  Abs: '<S142>/Abs1'
   *  Inport generated from: '<Root>/In Bus Element4'
   */
#if RECEIVE_MODE_LKA
  rtb_handOver_trq_gjut_tmp =
    Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q4_CAN_AdsAgReq();
#else
  rtb_handOver_trq_gjut_tmp = Fv_AdsAgReq;
#endif
  /* Lookup_n-D: '<S142>/lka_vs_handOvertrq' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element19'
   *  Sum: '<S142>/Subtract'
   */
  rtb_handOver_trq = (sint16)(rtb_handOver_trq_gjut_tmp -
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG);

  /* Abs: '<S142>/Abs2' incorporates:
   *  Lookup_n-D: '<S142>/lka_vs_handOvertrq'
   */
  if (rtb_handOver_trq < 0) {
    cmd_grid_tmp = (sint16)-rtb_handOver_trq;
  } else {
    cmd_grid_tmp = rtb_handOver_trq;
  }

  /* Abs: '<S142>/Abs4' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element22'
   */
  if (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ < 0) {
    /* Abs: '<S142>/Abs4' */
    rtb_Abs4 = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  } else {
    /* Abs: '<S142>/Abs4' */
    rtb_Abs4 = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;
  }

  /* End of Abs: '<S142>/Abs4' */

  /* Lookup_n-D: '<S142>/lka_vs_handOvertrq' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_handOver_trq = look1_iu16ls32n10ts16D_QWHCuzIb
    (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const uint16 *)
     &Cal_LKA_HandOverMaxTrqTab_V[0], (const sint16 *)
     &Cal_LKA_HandOverMaxTrqTab_T[0],
     &rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_jieb, 8U);

  /* Lookup_n-D: '<S142>/lka_override' incorporates:
   *  Abs: '<S142>/Abs4'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_overtime = look2_is16u16ls32n10tu_gntPemx1(rtb_Abs4,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_HandOverTimeTab_A[0], (const uint16 *)&Cal_LKA_HandOverTimeTab_V[0],
    (const uint16 *)&Cal_LKA_HandOverTimeTab_T[0],
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_l1cm, rtCP_lka_override_maxIndex,
    9U);

  /* Chart: '<S142>/lkauseroprtmr' incorporates:
   *  Abs: '<S142>/Abs4'
   *  Lookup_n-D: '<S142>/lka_vs_handOvertrq'
   *  RelationalOperator: '<S142>/Relational Operator'
   */
  if (rtb_overtime == 0) {
    apa_trqstep = CONSTCNTMAX_mef0;
  } else {
    apa_trqstep = CONSTCNTMAX_mef0 / rtb_overtime;
  }

  if (rtb_Abs4 > rtb_handOver_trq) {
    if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt < CONSTCNTMAX_mef0) {
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt += apa_trqstep;
    } else {
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.trqover_flag = true;
      //Fv_LKA_DrvrSteerOvrd = (true && (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts == 3));
    }
  } else {
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.trqover_flag = false;
    //Fv_LKA_DrvrSteerOvrd = false;

    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.apa_trqover_cnt = 0U;
  }

  /* End of Chart: '<S142>/lkauseroprtmr' */

  /* Logic: '<S142>/Logical Operator2' incorporates:
   *  Constant: '<S142>/Constant1'
   *  Constant: '<S142>/Constant3'
   *  Constant: '<S147>/Constant'
   *  Constant: '<S148>/Constant'
   *  Constant: '<S150>/Constant'
   *  Constant: '<S164>/Constant'
   *  Logic: '<S142>/Logical Operator3'
   *  RelationalOperator: '<S147>/Compare'
   *  RelationalOperator: '<S148>/Compare'
   *  RelationalOperator: '<S150>/Compare'
   *  RelationalOperator: '<S164>/Compare'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temporary =
    (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.trqover_flag ||
    		 (rtb_handOver_trq >Cal_LKA_REQLIMIT) ||
    		((rtb_Abs4 > Cal_LKA_GRIDLIMIT) && (cmd_grid_tmp >Cal_LKA_DIFFLIMIT))||
     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1 == true) ||
     false || (lka_stop_flag_bmc2_tmp == true) || false ||
     ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s == 1) ||
      (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_jyet == 1)) || (Fv_AdsModLostFlag > 0));
  // debug_jing4 = (Fv_AdsModLostFlag > 0)| (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_jyet == 1)<<1|
  // (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s == 1) <<2|(lka_stop_flag_bmc2_tmp == true)<<3|
  // (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1 == true)<<4;
  /* Chart: '<S142>/lka_temporarytmr' */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temporary) {
    if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.temporary_cnt <
        Cal_LKA_TEMPO_OVERTIME_TMR) {
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.temporary_cnt++;
    } else {
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.overtime_flag = true;
    }
  } else {
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.overtime_flag = false;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.temporary_cnt = 0U;
  }

  /* End of Chart: '<S142>/lka_temporarytmr' */

  /* Abs: '<S142>/Abs1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  if (rtb_handOver_trq_gjut_tmp < 0) {
    rtb_handOver_trq = (sint16)-rtb_handOver_trq_gjut_tmp;
  } else {
#if RECEIVE_MODE_LKA
    rtb_handOver_trq =
      Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q4_CAN_AdsAgReq();
#else
    rtb_handOver_trq = Fv_AdsAgReq;
#endif
  }

  /* Abs: '<S142>/Abs3' */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_grid < 0) {
    rtb_Abs4 = (sint16)-rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_grid;
  } else {
    rtb_Abs4 = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.cmd_grid;
  }

  /* Logic: '<S142>/Logical Operator9' incorporates:
   *  Abs: '<S142>/Abs1'
   *  Abs: '<S142>/Abs2'
   *  Abs: '<S142>/Abs3'
   *  Constant: '<S146>/Constant'
   *  Constant: '<S149>/Constant'
   *  Constant: '<S151>/Constant'
   *  Constant: '<S156>/Constant'
   *  Constant: '<S165>/Constant'
   *  Logic: '<S142>/AND1'
   *  Logic: '<S142>/Logical Operator5'
   *  RelationalOperator: '<S146>/Compare'
   *  RelationalOperator: '<S149>/Compare'
   *  RelationalOperator: '<S151>/Compare'
   *  RelationalOperator: '<S156>/Compare'
   *  RelationalOperator: '<S165>/Compare'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_permanent =
      (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.overtime_flag  ||
     ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FRP_FAI == 1) ||
      (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_bf30 == 1)));

  Fv_LKA_AgReqNotInRange = (rtb_handOver_trq > Cal_LKA_REQLIMIT);
  /* Logic: '<S142>/OR' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S155>/Constant'
   *  Constant: '<S161>/Constant'
   *  Constant: '<S167>/Constant'
   *  Inport generated from: '<Root>/In Bus Element16'
   *  Logic: '<S142>/Logical Operator8'
   *  RelationalOperator: '<S154>/Compare'
   *  RelationalOperator: '<S155>/Compare'
   *  RelationalOperator: '<S161>/Compare'
   *  RelationalOperator: '<S167>/Compare'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
#if RECEIVE_MODE_LKA
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.suppression =
    ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ <
      Cal_LKA_VSSTART) ||
     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ > Cal_LKA_VSEND)
     || (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_BHM_MOD !=
         HOLD_ACTIVE) ||
     (Fv_CAN_AdsTqInvalid_flag ==
      true));
#else
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.suppression =
      ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ <
        Cal_LKA_VSSTART) ||
       (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ > Cal_LKA_VSEND)
       || (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_BHM_MOD !=
           HOLD_ACTIVE) ||
       (Fv_AdsTqInvalid_flag ==true))||(Fv_AdsAgUBInvalid_flag == true);

#endif
  /* Logic: '<S142>/OR1' incorporates:
   *  Constant: '<S145>/Constant'
   *  Constant: '<S152>/Constant'
   *  Constant: '<S153>/Constant'
   *  Constant: '<S157>/Constant'
   *  Constant: '<S158>/Constant'
   *  Constant: '<S159>/Constant'
   *  Constant: '<S166>/Constant'
   *  Constant: '<S168>/Constant'
   *  Logic: '<S142>/Logical Operator1'
   *  Logic: '<S142>/Logical Operator10'
   *  Logic: '<S142>/Logical Operator11'
   *  Logic: '<S142>/Logical Operator4'
   *  Logic: '<S142>/Logical Operator6'
   *  Logic: '<S142>/Logical Operator7'
   *  RelationalOperator: '<S145>/Compare'
   *  RelationalOperator: '<S152>/Compare'
   *  RelationalOperator: '<S153>/Compare'
   *  RelationalOperator: '<S157>/Compare'
   *  RelationalOperator: '<S158>/Compare'
   *  RelationalOperator: '<S159>/Compare'
   *  RelationalOperator: '<S166>/Compare'
   *  RelationalOperator: '<S168>/Compare'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.OR1 = (
    ((lka_stop_flag_bmc2_tmp_0 == ((uint8)1U))  && (rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Compare == true)) ||
    (((lka_stop_flag_bmc2_tmp_0 == ((uint8)2U)) || (lka_stop_flag_bmc2_tmp_0 == ((uint8)3U)) || ((lka_stop_flag_bmc2_tmp_0 == ((uint8)4U)) || (lka_stop_flag_bmc2_tmp_0 == ((uint8)5U)))) &&
     (rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[0] == true)) ||
    ((Fv_LKA_ADL3ADMod == 2)&& ((Fv_CANCCP494 > 0x4) &&Fv_CANCCP494 <= 0x82 )) || 
    (((Fv_LKA_ADL3ADMod == 1) || (lka_stop_flag_bmc2_tmp_0 == ((uint8)12U)))&&(Fv_CANCCP100>3)) ) ;
    //mod by liuyang for NOP
}
UInt32 m_bpIndex_PosLoopKp[2];      
UInt32 pooled9_PosLoop[2] = { 6U, 7U };
/* Output and update for atomic system: '<S172>/LKA_PosLoopControl' */
void LKA_PosLoopControl(void)
{
  sint32 mclk_err_last;
  sint16 mclk_kp = 0;
  sint16 mclk_anglediff = 0; 

  /* Chart: '<S174>/LKA_PosControl' */
  if (Fv_LKA_PosClearFlag) {
    Fv_LKA_PosClearFlag = false;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err = 0;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag = false;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_cnt = 0U;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.pc_strang_last = 0;
  } else {
    if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_kze5 ==
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.pc_strang_last) {
      if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_cnt < Cal_LKA_LOOP_STOPTMR) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_cnt++;
      } else {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag = true;
      }
    } else {
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag = false;
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_cnt = 0U;
    }

    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.pc_strang_last =
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_kze5;
  }
  mclk_err_last = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err;
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err =
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_mjka -
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_odfm;
#if 1
  if(rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err < 0)
  {
    mclk_anglediff = -((sint16)rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err);
  }
  else
  {
    mclk_anglediff = (sint16)rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err;
  }


     mclk_kp = look2_is16s16ls32n10ts_mOyVHgzB(mclk_anglediff, 
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_,
    ((const Int16 *)&(Cal_LKA_PosLoopKp_A[0])), //X
    ((const Int16 *)&(Cal_LKA_PosLoopKp_V[0])), //Y
    ((const Int16 *)&(Cal_LKA_PosLoopKp_T[0])), //Z
    m_bpIndex_PosLoopKp, pooled9_PosLoop, 7U);


    mclk_err_last = (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err - mclk_err_last) *
    Cal_LKA_POSPID_KD + rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err *
	mclk_kp;
#else
mclk_err_last = (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err - mclk_err_last) *
    Cal_LKA_POSPID_KD + rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err *
    Cal_LKA_POSPID_KP;

#endif


  if (mclk_err_last > Cal_LKA_LOOP_MAX_REV) {
    mclk_err_last = Cal_LKA_LOOP_MAX_REV;
  } else if (mclk_err_last < -Cal_LKA_LOOP_MAX_REV) {
    mclk_err_last = -Cal_LKA_LOOP_MAX_REV;
  }

  /* SignalConversion: '<S174>/Signal Copy' */
  /* aimcurrent = MotorCtrl_SpdLoop_LKA(mclk_aimrev,Cal_LKA_LOOP_MAX_CURRENT,lka_stop_flag); */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag_bmc2 =
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag;

  /* Switch: '<S175>/Switch2' incorporates:
   *  SignalConversion: '<S174>/Signal Copy1'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_ki =
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err;

  /* SignalConversion: '<S174>/Signal Copy2' incorporates:
   *  Chart: '<S174>/LKA_PosControl'
   */

  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimrevin = (sint16)(-mclk_err_last / 16);

}

/* Output and update for atomic system: '<S172>/LKA_RevCalcParamSet' */
void LKA_RevCalcParamSet(void)
{
  sint32 rtb_focrevabs;
  sint32 rtb_revfoc;
  sint16 rtb_errabs;
  uint16 rtb_lkalooktab_ki;
  uint16 rtb_lkalooktab_kp;
  boolean tmp;

  /* Product: '<S175>/revfoc' incorporates:
   *  Constant: '<S175>/Constant'
   *  DataTypeConversion: '<S175>/Data Type Conversion3'
   *  SignalConversion generated from: '<Root>/In Bus Element21'
   */
  //rtb_revfoc = (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_MTR_RTR *
   //             ((uint16)MACRO_RAD2RPM)) >> 14;

  rtb_revfoc = (Fv_FOC_RotorSpd *
                  ((uint16)MACRO_RAD2RPM)) >> 14;

  /* Abs: '<S175>/focrevabs' incorporates:
   *  DataTypeConversion: '<S180>/FixPt Gateway Out'
   *  Product: '<S175>/revfoc'
   */
  if (rtb_revfoc < 0) {
    /* Abs: '<S175>/focrevabs' */
    rtb_focrevabs = -rtb_revfoc;
  } else {
    /* Abs: '<S175>/focrevabs' */
    rtb_focrevabs = rtb_revfoc;
  }

  /* End of Abs: '<S175>/focrevabs' */

  /* Relay: '<S175>/Relay' */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Relay_Mode = ((rtb_focrevabs >=
    Cal_LKA_LOOP_STOPREVUP) || ((rtb_focrevabs > Cal_LKA_LOOP_STOPREVDN) &&
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Relay_Mode));
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Relay_Mode) {
    tmp = false;
  } else {
    tmp = true;
  }

  /* Switch: '<S175>/Switch' incorporates:
   *  Logic: '<S175>/AND'
   *  Relay: '<S175>/Relay'
   *  SignalConversion: '<S174>/Signal Copy'
   */
#if 1
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag_bmc2 && tmp) {
    /* Switch: '<S175>/Switch' incorporates:
     *  SignalConversion generated from: '<Root>/In Bus Element23'
     *  UnaryMinus: '<S175>/Unary Minus'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_actrev = (sint16)-
      rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_e3ct;
  } else {
    /* Switch: '<S175>/Switch' incorporates:
     *  DataTypeConversion: '<S180>/FixPt Gateway Out'
     *  Product: '<S175>/revfoc'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_actrev = rtb_revfoc;
  }
#else
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_actrev = (sint16)-
        rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_e3ct;

#endif
  /* End of Switch: '<S175>/Switch' */

  /* DataTypeConversion: '<S183>/FixPt Gateway Out' incorporates:
   *  SignalConversion: '<S174>/Signal Copy2'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_iiqs =
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimrevin;

  /* Abs: '<S175>/errabs' incorporates:
   *  Switch: '<S175>/Switch2'
   */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_ki < 0) {
    /* Abs: '<S175>/errabs' */
    rtb_errabs = (sint16)-rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_ki;
  } else {
    /* Abs: '<S175>/errabs' */
    rtb_errabs = (sint16)rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_ki;
  }

  /* End of Abs: '<S175>/errabs' */

  /* Lookup_n-D: '<S175>/lkalooktab_kp' incorporates:
   *  Abs: '<S175>/errabs'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_lkalooktab_kp = look2_is16u16ls32n10tu_gntPemx1(rtb_errabs,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_ErrAdapt_Tab_A[0], (const uint16 *)&Cal_LKA_ErrAdapt_Tab_V[0], (
    const uint16 *)&Cal_LKA_ErrAdapt_Tab_P[0],
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_hvsy, rtCP_lkalooktab_kp_maxIndex,
    8U);

  /* Lookup_n-D: '<S175>/lkalooktab_ki' incorporates:
   *  Abs: '<S175>/errabs'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_lkalooktab_ki = look2_is16u16ls32n10tu_gntPemx1(rtb_errabs,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_ErrAdapt_Tab_A[0], (const uint16 *)&Cal_LKA_ErrAdapt_Tab_V[0], (
    const uint16 *)&Cal_LKA_ErrAdapt_Tab_I[0],
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_cprh, rtCP_lkalooktab_ki_maxIndex,
    8U);

  /* Abs: '<S175>/aimrevabs' incorporates:
   *  SignalConversion: '<S174>/Signal Copy2'
   */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimrevin < 0) {
    rtb_errabs = (sint16)-rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimrevin;
  } else {
    rtb_errabs = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimrevin;
  }

  /* Switch: '<S175>/Switch1' incorporates:
   *  Abs: '<S175>/aimrevabs'
   *  Constant: '<S175>/Constant3'
   *  Constant: '<S178>/Constant'
   *  Constant: '<S179>/Constant'
   *  DataTypeConversion: '<S175>/Data Type Conversion2'
   *  Logic: '<S175>/AND1'
   *  Lookup_n-D: '<S175>/lkalooktab_ki'
   *  Product: '<S175>/incki'
   *  RelationalOperator: '<S178>/Compare'
   *  RelationalOperator: '<S179>/Compare'
   *  Switch: '<S175>/Switch'
   *  Switch: '<S175>/Switch2'
   */
  if ((rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_actrev == 0) && (rtb_errabs >
       Cal_LKA_LOOP_INCREVLIMIT)) {
    /* Switch: '<S175>/Switch1' incorporates:
     *  Constant: '<S175>/Constant1'
     *  Lookup_n-D: '<S175>/lkalooktab_kp'
     *  Product: '<S175>/inckp'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_kp = (sint32)((uint32)
      Cal_LKA_LOOP_REVPI_PLUS * rtb_lkalooktab_kp);
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_ki = (sint32)((uint32)
      Cal_LKA_LOOP_REVPI_PLUS * rtb_lkalooktab_ki);
  } else {
    /* Switch: '<S175>/Switch1' incorporates:
     *  DataTypeConversion: '<S175>/Data Type Conversion1'
     *  Lookup_n-D: '<S175>/lkalooktab_kp'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_kp = rtb_lkalooktab_kp;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_ki = rtb_lkalooktab_ki;
  }

  /* End of Switch: '<S175>/Switch1' */

  /* DataTypeConversion: '<S182>/FixPt Gateway Out' incorporates:
   *  Constant: '<S175>/Constant2'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut = Cal_LKA_LOOP_MAX_CURRENT;
}

/* Output and update for atomic system: '<S172>/LKA_RevLoopControl' */
void LKA_RevLoopControl(void)
{
  sint32 mclk_err_last;
  sint32 mclk_maxI_pi;
  sint16 rtb_Divide;
  sint16 rtb_abs;
  sint16 rtb_abs1;
  sint16 rtb_dn;

  sint16 rtb_transfer;

  /* Chart: '<S176>/LKA_RevControl' incorporates:
   *  DataTypeConversion: '<S182>/FixPt Gateway Out'
   *  DataTypeConversion: '<S183>/FixPt Gateway Out'
   *  Switch: '<S175>/Switch'
   *  Switch: '<S175>/Switch1'
   *  Switch: '<S175>/Switch2'
   */
  if (Fv_LKA_RevClearFlag) {
    Fv_LKA_RevClearFlag = false;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err_mbvz = 0;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout = 0;
  }

  mclk_maxI_pi = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut << 8;
  mclk_err_last = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err_mbvz;
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err_mbvz =
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_iiqs -
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_actrev;


  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout +=
    ((rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err_mbvz - mclk_err_last) *
     rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_kp +
     rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_ki *
     rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_err_mbvz) / 16;
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout > mclk_maxI_pi) {
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout = mclk_maxI_pi;
  } else if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout < -mclk_maxI_pi) {
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout = -mclk_maxI_pi;
  }

  /*mclk_maxI_pi = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout / 256 -
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_iiqs / 4;*/
/*240221 by zyg*/
  mclk_maxI_pi = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.mclk_aimout / 256;

  if (mclk_maxI_pi > rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut) {
    mclk_maxI_pi = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut;
  } else if (mclk_maxI_pi < -rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut) {
    mclk_maxI_pi = -rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut;
  }

  /* End of Chart: '<S176>/LKA_RevControl' */

  /* Product: '<S176>/Divide' incorporates:
   *  Constant: '<S176>/Constant1'
   *  Gain: '<S176>/Gain'
   */
  rtb_Divide = (sint16)((mclk_maxI_pi << 7) / Cal_Motor_TrqCoef);

  /* Abs: '<S186>/abs' incorporates:
   *  Inport generated from: '<Root>/In Bus Element5'
   */
#if RECEIVE_MODE_LKA
  rtb_dn = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q7_CANAdsAgTup();
#else
  /*��ȡŤ����ֵ  �ѷŴ�2^7*/
  rtb_dn = Fv_AdsAgTup;
#endif
  if (rtb_dn < 0) {
    /* Abs: '<S186>/abs' */
    //rtb_abs = (sint16)((uint32)(uint16)-rtb_dn >> 7);
	  rtb_abs =(sint16)-rtb_dn;
  } else {
    /* Abs: '<S186>/abs' */
    //rtb_abs = (sint16)((uint32)(uint16)rtb_dn >> 7);
    rtb_abs = (sint16)rtb_dn;
  }

  /* Switch: '<S186>/Switch' incorporates:
   *  Constant: '<S188>/Constant'
   *  RelationalOperator: '<S188>/Compare'
   */
//  if (rtb_abs > ((Cal_LKA_AgCtrlUpOfNoTrqLimit + 64) >> 7)) {
  if (rtb_abs > (Cal_LKA_AgCtrlUpOfNoTrqLimit + 64)) {
    /* Switch: '<S186>/Switch1' incorporates:
     *  Constant: '<S186>/Constant2'
     */
    mclk_maxI_pi = Cal_LKA_LOOP_MAX_CURRENT;
  } else {
    /* Lookup_n-D: '<S186>/UpLimit' incorporates:
     *  Abs: '<S186>/abs'
     */
    rtb_abs = look1_is16bs16n7ls32n1_8I508xgm(rtb_abs, (const sint16 *)
      &Cal_LKA_AgCtrlTqUpLimit_X[0], (const sint16 *)&Cal_LKA_AgCtrlTqUpLimit_Y
      [0], &rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex, 9U);

    /* Switch: '<S186>/Switch1' incorporates:
     *  Lookup_n-D: '<S186>/UpLimit'
     */
    mclk_maxI_pi = rtb_abs;
  }

  /* End of Switch: '<S186>/Switch' */

  /* Signum: '<S186>/Sign' incorporates:
   *  Abs: '<S186>/abs'
   *  Inport generated from: '<Root>/In Bus Element5'
   */
  if (rtb_dn < 0) {
    rtb_dn = -1;
  } else {
    rtb_dn = (sint16)(rtb_dn > 0);
  }

  /* Product: '<S186>/Product2' incorporates:
   *  Signum: '<S186>/Sign'
   *  Switch: '<S186>/Switch1'
   */
  rtb_abs = (sint16)(mclk_maxI_pi * rtb_dn);

  /* Abs: '<S186>/abs1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   */
#if RECEIVE_MODE_LKA
  rtb_dn = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q7_CANAdsAgTdn();
#else
  rtb_dn = Fv_AdsAgTdn;
#endif
  if (rtb_dn < 0) {
    /* Abs: '<S186>/abs1' */
    //rtb_abs1 = (sint16)((uint32)(uint16)-rtb_dn >> 7);
	  rtb_abs1 = (sint16)-rtb_dn;
  } else {
    /* Abs: '<S186>/abs1' */
    //rtb_abs1 = (sint16)((uint32)(uint16)rtb_dn >> 7);
    rtb_abs1 = (sint16)rtb_dn;
  }

  /* Switch: '<S186>/Switch1' incorporates:
   *  Constant: '<S187>/Constant'
   *  RelationalOperator: '<S187>/Compare'
   */
//  if (rtb_abs1 > ((Cal_LKA_AgCtrlDnOfNoTrqLimit + 64) >> 7)) {
  if (rtb_abs1 > (Cal_LKA_AgCtrlDnOfNoTrqLimit + 64)) {
    /* Switch: '<S186>/Switch1' incorporates:
     *  Constant: '<S186>/Constant3'
     */
    mclk_maxI_pi = Cal_LKA_LOOP_MAX_CURRENT;
  } else {
    /* Lookup_n-D: '<S186>/DnLimit1' incorporates:
     *  Abs: '<S186>/abs1'
     */
    rtb_abs1 = look1_is16bs16n7ls32n1_8I508xgm(rtb_abs1, (const sint16 *)
      &Cal_LKA_AgCtrlTqDnLimit_X[0], (const sint16 *)&Cal_LKA_AgCtrlTqDnLimit_Y
      [0], &rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_oaez, 9U);

    /* Switch: '<S186>/Switch1' incorporates:
     *  Lookup_n-D: '<S186>/DnLimit1'
     */
    mclk_maxI_pi = rtb_abs1;
  }

  /* End of Switch: '<S186>/Switch1' */

  /* Signum: '<S186>/Sign1' incorporates:
   *  Abs: '<S186>/abs1'
   *  Inport generated from: '<Root>/In Bus Element6'
   */
  if (rtb_dn < 0) {
    rtb_dn = -1;
  } else {
    rtb_dn = (sint16)(rtb_dn > 0);
  }

  /* Product: '<S186>/Product1' incorporates:
   *  Signum: '<S186>/Sign1'
   *  Switch: '<S186>/Switch1'
   */
  rtb_dn = (sint16)(mclk_maxI_pi * rtb_dn);

  /* Switch: '<S185>/Switch2' incorporates:
   *  Product: '<S176>/Divide'
   *  Product: '<S186>/Product1'
   *  Product: '<S186>/Product2'
   *  RelationalOperator: '<S185>/LowerRelop1'
   *  RelationalOperator: '<S185>/UpperRelop'
   *  Switch: '<S185>/Switch'
   */
  //��ʱ�����˻�����
#if 1
  /*����*/
  /*�����жϣ���ֹ����С�����޵��������,23.11.13 by zyg*/
  if(rtb_abs >= rtb_dn)/*������� ���ޡ�����*/
  {
	  /*��������*/
  }
  else/*�쳣���  ����<����*/
  {
	  /*����������*/
	  rtb_transfer = rtb_abs;
	  rtb_abs = rtb_dn;
	  rtb_dn = rtb_transfer;
  }


  if (rtb_Divide > rtb_abs) {
    /* Switch: '<S185>/Switch2' */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2 = rtb_abs;
    Fv_LKA_ExtFctUpperLimActive = true;
  } else if (rtb_Divide < rtb_dn) {/*����*/
    /* Switch: '<S185>/Switch' incorporates:
     *  Product: '<S186>/Product1'
     *  Switch: '<S185>/Switch2'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2 = rtb_dn;
    Fv_LKA_ExtFctLowerLimActive = true;
  } else {
    /* Switch: '<S185>/Switch2' incorporates:
     *  Switch: '<S185>/Switch'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2 = rtb_Divide;
    Fv_LKA_ExtFctUpperLimActive = false;
    Fv_LKA_ExtFctLowerLimActive = false;
  }
  /* End of Switch: '<S185>/Switch2' */
#else
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2 = rtb_Divide;
#endif
}

/* Output and update for enable system: '<S143>/LKAControl_Exec_AngleLoop' */
void LKAControl_Exec_AngleLoop(void)
{
  /* Outputs for Enabled SubSystem: '<S143>/LKAControl_Exec_AngleLoop' incorporates:
   *  EnablePort: '<S172>/Enable'
   */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Compare) {
    /* Outputs for Atomic SubSystem: '<S172>/LKA_PosLoopControl' */
    LKA_PosLoopControl();

    /* End of Outputs for SubSystem: '<S172>/LKA_PosLoopControl' */

    /* Outputs for Atomic SubSystem: '<S172>/LKA_RevCalcParamSet' */
    LKA_RevCalcParamSet();

    /* End of Outputs for SubSystem: '<S172>/LKA_RevCalcParamSet' */

    /* Outputs for Atomic SubSystem: '<S172>/LKA_RevLoopControl' */
    LKA_RevLoopControl();

    /* End of Outputs for SubSystem: '<S172>/LKA_RevLoopControl' */
  }

  /* End of Outputs for SubSystem: '<S143>/LKAControl_Exec_AngleLoop' */
}

/* Output and update for atomic system: '<S143>/LKAControl_Exec_Precond' */
uint32 m_bpIndex_ARDF;  
void LKAControl_Exec_Precond(void)
{
  #define MACRO_LKA_QUITERATE_MAX 128
#define MACRO_LKA_QUITERATE_CTRL 20

  static Int16 lka_rate = 0;
  sint16 rtb_Subtract;
  sint16 rtb_Switch2;

  /* Outputs for Atomic SubSystem: '<S173>/LKA_Precond_FlagSet' */
  /* If: '<S189>/If' */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts != 2) {
    /* Outputs for IfAction SubSystem: '<S189>/ActiveState' incorporates:
     *  ActionPort: '<S191>/Action Port'
     */
    /* DataStoreWrite: '<S191>/Data Store Write' incorporates:
     *  Constant: '<S191>/Constant'
     */
    Fv_LKA_PosClearFlag = true;

    /* DataStoreWrite: '<S191>/Data Store Write1' incorporates:
     *  Constant: '<S191>/Constant'
     */
    Fv_LKA_RevClearFlag = true;

    /* DataStoreWrite: '<S191>/Data Store Write2' */
    //Fv_LKA_Torque = 0;
    /*增加缓退机制*/
    if(Fv_LKA_Torque > 3200 || Fv_LKA_Torque < -3200)
    {
      lka_rate = MACRO_LKA_QUITERATE_MAX;
    }
    else
    {
      lka_rate = MACRO_LKA_QUITERATE_CTRL;
    }

    if(Fv_LKA_Torque > lka_rate)
    {
      Fv_LKA_Torque-= lka_rate;
    }
    else if(Fv_LKA_Torque < -lka_rate)
    {
      Fv_LKA_Torque += lka_rate;
    }
    else
    {
      Fv_LKA_Torque = 0;
    }

    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2 = 0;
    Fv_LKA_AngleUpdataEn = 1;

    Fv_LKA_ExtFctUpperLimActive = false;
    Fv_LKA_ExtFctLowerLimActive = false;
    Tv_Asy_ActiveReturnDampingFactorTemp = 128;
    /* End of Outputs for SubSystem: '<S189>/ActiveState' */
  }
  else
  {
    Tv_Asy_ActiveReturnDampingFactorTemp = look1_is16bs16n7ls32n1_8I508xgm(Fv_VehSpdNew, (const sint16 *)
      &Cal_LKA_ARFactor_X[0], (const sint16 *)&Cal_LKA_ARFactor_Y
      [0], &m_bpIndex_ARDF, 2U);
  }
  /* End of If: '<S189>/If' */
  /* End of Outputs for SubSystem: '<S173>/LKA_Precond_FlagSet' */

  /* Outputs for Atomic SubSystem: '<S173>/LKA_Precond_WorkState' */
  /* RelationalOperator: '<S196>/LowerRelop1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   *  Switch: '<S196>/Switch'
   */
#if RECEIVE_MODE_LKA
  rtb_Switch2 = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVs16q4_CAN_AdsAgReq();
#else
  rtb_Switch2 = Fv_AdsAgReq;
#endif

  /* Switch: '<S196>/Switch2' incorporates:
   *  Constant: '<S190>/Constant2'
   *  Delay: '<S190>/Delay1'
   *  Inport generated from: '<Root>/In Bus Element4'
   *  RelationalOperator: '<S196>/LowerRelop1'
   *  RelationalOperator: '<S196>/UpperRelop'
   *  Switch: '<S196>/Switch'
   *  UnaryMinus: '<S190>/Unary Minus'
   */
  if (rtb_Switch2 > Cal_LKA_LOOP_MAX_ANGLE) {
    /* Switch: '<S196>/Switch2' */
    rtb_Switch2 = Cal_LKA_LOOP_MAX_ANGLE;
  } else if (rtb_Switch2 < (sint16)-Cal_LKA_LOOP_MAX_ANGLE) {
    /* Switch: '<S196>/Switch' incorporates:
     *  Delay: '<S190>/Delay1'
     *  Switch: '<S196>/Switch2'
     *  UnaryMinus: '<S190>/Unary Minus'
     */
    rtb_Switch2 = (sint16)-Cal_LKA_LOOP_MAX_ANGLE;
  }

  /* End of Switch: '<S196>/Switch2' */

  /* Sum: '<S190>/Subtract' incorporates:
   *  Delay: '<S190>/Delay1'
   *  Switch: '<S196>/Switch2'
   */
  if((Fv_LKA_AngleUpdataEn == 1) && (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts == ((uint8)2U)))
  {
	  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE = rtb_Switch2;
	  Fv_LKA_AngleUpdataEn = 0;
  }
  else
  {

  }

  rtb_Subtract = (sint16)(rtb_Switch2 -
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE);

  /* Switch: '<S198>/Switch2' incorporates:
   *  Constant: '<S190>/Constant1'
   *  Constant: '<S190>/Constant5'
   *  RelationalOperator: '<S198>/LowerRelop1'
   *  RelationalOperator: '<S198>/UpperRelop'
   *  Sum: '<S190>/Subtract'
   *  Switch: '<S198>/Switch'
   *  UnaryMinus: '<S190>/Unary Minus1'
   *  UnaryMinus: '<S190>/Unary Minus2'
   */
  if (rtb_Subtract > Cal_LKA_LOOP_STEP_ANGLE) {
    rtb_Subtract = Cal_LKA_LOOP_STEP_ANGLE;
    Fv_LKA_AngleSpdLimit = true;
  } else if (rtb_Subtract < (sint16)-Cal_LKA_LOOP_STEP_ANGLE) {
    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S190>/Constant1'
     *  UnaryMinus: '<S190>/Unary Minus1'
     *  UnaryMinus: '<S190>/Unary Minus2'
     */
    rtb_Subtract = (sint16)-Cal_LKA_LOOP_STEP_ANGLE;
    Fv_LKA_AngleSpdLimit = true;
  }
  else
  {
	  Fv_LKA_AngleSpdLimit = false;
  }

  /* Sum: '<S190>/Add' incorporates:
   *  Delay: '<S190>/Delay1'
   *  Switch: '<S198>/Switch2'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE += rtb_Subtract;

  /* RelationalOperator: '<S192>/Compare' incorporates:
   *  Constant: '<S192>/Constant'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Compare =
    (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts == ((uint8)2U));

  /* Switch: '<S197>/Switch2' incorporates:
   *  Constant: '<S190>/Constant3'
   *  RelationalOperator: '<S197>/LowerRelop1'
   *  RelationalOperator: '<S197>/UpperRelop'
   *  SignalConversion generated from: '<Root>/In Bus Element19'
   *  Switch: '<S197>/Switch'
   *  UnaryMinus: '<S190>/Unary Minus1'
   */
  rtb_Subtract = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG;  
  if (rtb_Subtract > Cal_LKA_LOOP_MAX_ANGLE) {
    /* Switch: '<S197>/Switch2' */
    rtb_Subtract = Cal_LKA_LOOP_MAX_ANGLE;
  } else if (rtb_Subtract < (sint16)-Cal_LKA_LOOP_MAX_ANGLE) {
    /* Switch: '<S197>/Switch' incorporates:
     *  Switch: '<S197>/Switch2'
     *  UnaryMinus: '<S190>/Unary Minus1'
     */
    rtb_Subtract = (sint16)-Cal_LKA_LOOP_MAX_ANGLE;
  } else {
    /* Switch: '<S197>/Switch2' incorporates:
     *  Switch: '<S197>/Switch'
     */
    //rtb_Subtract = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG;
  }

  /* End of Switch: '<S197>/Switch2' */

  /* Switch: '<S190>/Switch' */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Compare) {
    /* DataTypeConversion: '<S193>/FixPt Gateway Out' incorporates:
     *  Sum: '<S190>/Add'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_mjka =
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Delay1_DSTATE;
  } else {
    /* DataTypeConversion: '<S193>/FixPt Gateway Out' incorporates:
     *  Switch: '<S197>/Switch2'
     */
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_mjka = rtb_Subtract;
  }

  /* End of Switch: '<S190>/Switch' */

  /* DataTypeConversion: '<S194>/FixPt Gateway Out' incorporates:
   *  Switch: '<S197>/Switch2'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_odfm = rtb_Subtract;

  /* DataTypeConversion: '<S195>/FixPt Gateway Out' incorporates:
   *  Switch: '<S196>/Switch2'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.FixPtGatewayOut_kze5 = rtb_Switch2;
#undef MACRO_LKA_QUITERATE_MAX
#undef MACRO_LKA_QUITERATE_CTRL
  /* End of Outputs for SubSystem: '<S173>/LKA_Precond_WorkState' */
}

/* Output and update for atomic system: '<S6>/LKAControl_Exec' */
//uint32 m_bpIndex_tqout = 0;
void LKAControl_Exec(void)
{
  

  //volatile sint16 rtb_lkatq = 0;
  //volatile sint16 rtb_lkatqout = 0;
  //volatile sint16 rtb_lkatqdir = 0;
  /* Outputs for Atomic SubSystem: '<S143>/LKAControl_Exec_Precond' */
  LKAControl_Exec_Precond();

  /* End of Outputs for SubSystem: '<S143>/LKAControl_Exec_Precond' */

  //if (Fv_LKA_ControlSts != 2) {
  //  Fv_LKA_PosClearFlag = true;
  //  Fv_LKA_RevClearFlag = true;
  //  Fv_LKA_Torque = 0;
  //}
 // Fv_FAA_LQR_ActAng = (double)Fv_MotorAngle_Raw * 0.0625; // TODO,motorangle
  Fv_FAA_LQR_ActAng = (double)Fv_StrAng_Raw*0.0625;
  Fv_FAA_LQR_ActSpd = ((double)asr_s32_lka(-Fv_FOC_RotorSpd * ((Int32)((UInt16)MACRO_RAD2RPM)), 14U)) * 0.0232;
  Fv_FAA_VehSpd = Fv_VehSpdNew / 32;
  Fv_FAA_Reset = Fv_LKA_ControlSts;
  LQR_step();/*内部激活时清零，退出后不再计算Fv_LKA_Torque*/
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2 = Fv_LKA_Torque;
  #if 0
  /*根据人机共驾map，反馈lka输出力矩,2024.03.12 by zyg*/
  {
    if(Fv_LKA_Torque < 0)
    {
      rtb_lkatq = -Fv_LKA_Torque;
      rtb_lkatqdir = 1;
    }
    else
    {
      rtb_lkatq = Fv_LKA_Torque;
      rtb_lkatqdir = -1;
    }
    /*左正右负*/

    rtb_lkatqout = look1_iu16ls32n10ts16D_QWHCuzIb
        (rtb_lkatq, (const uint16 *)
         &Cal_LKA_TqOut_X[0], (const sint16 *)
         &Cal_LKA_TqOut_Y[0],
         &m_bpIndex_tqout, 24U);
    Fv_LKA_LimitTorque = rtb_lkatqdir * rtb_lkatqout;
  }
  //#else 
 /*根据人机共驾map，反馈lka输出力矩,2024.03.12 by zyg*/
  {
    if(Fv_FAA_LQR_QcurOut < 0)
    {
      rtb_lkatq = -Fv_FAA_LQR_QcurOut;
      rtb_lkatqdir = 1;
    }
    else
    {
      rtb_lkatq = Fv_FAA_LQR_QcurOut;
      rtb_lkatqdir = -1;
    }
    rtb_lkatqout = look1_iu16ls32n10ts16D_QWHCuzIb
        (rtb_lkatq, (const uint16 *)
         &Cal_LKA_TqOut_X[0], (const sint16 *)
         &Cal_LKA_TqOut_Y[0],
         &m_bpIndex_tqout, 24U);
    Fv_LKA_LimitTorque = rtb_lkatqdir * rtb_lkatqout;
  }
  #endif
  /* Outputs for Enabled SubSystem: '<S143>/LKAControl_Exec_AngleLoop' */
 // LKAControl_Exec_AngleLoop();

  /* End of Outputs for SubSystem: '<S143>/LKAControl_Exec_AngleLoop' */
#undef MACRO_LKA_QUITERATE_MAX
#undef MACRO_LKA_QUITERATE_CTRL
}

/* Output and update for atomic system: '<S6>/LKAControl_Logic' */
void LKAControl_Logic(void)
{
  boolean tmp;

  /* Chart: '<S144>/LKAControlLogic' */
  if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_active_c2_ADV_ExtFunction == 0U) {
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_active_c2_ADV_ExtFunction = 1U;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
      IN_Initialization_eyzg;
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 0U;
  } else {
    switch (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction) {
     case IN_Active_ke1u:
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 2U;
      if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_permanent) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Permanent_g4tw;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 4U;
      } else if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temporary) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Temporary_pl5k;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 3U;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_flag = false;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_cnt = Cal_LKA_TEMPRECOVER_TMR;
      } else if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.suppression) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Initialization_eyzg;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 0U;
      } else if (!rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.OR1) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction = IN_Ready_iatp;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 1U;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_activetriger = false;
      }
      break;

     case IN_Initialization_eyzg:
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 0U;
      if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_permanent) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Permanent_g4tw;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 4U;
      } else if ((!rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.suppression) &&
                 (!rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temporary)) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction = IN_Ready_iatp;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 1U;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_activetriger = false;
      }
      break;

     case IN_Permanent_g4tw:
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 4U;
      break;

     case IN_Ready_iatp:
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 1U;
      if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_permanent) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Permanent_g4tw;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 4U;
      } else if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temporary) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Temporary_pl5k;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 3U;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_flag = false;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_cnt = Cal_LKA_TEMPRECOVER_TMR;
      } else if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.suppression) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Initialization_eyzg;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 0U;
      } else if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.OR1 &&
                 rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_activetriger) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction = IN_Active_ke1u;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 2U;
      } else {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_activetriger =
          ((rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.OR1 &&
            (!rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_active_last)) ||
           rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_activetriger);
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_active_last =
          rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.OR1;
      }
      break;

     default:
      /* case IN_Temporary: */
      rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 3U;
      if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_permanent) {
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction =
          IN_Permanent_g4tw;
        rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 4U;
      } else {
        tmp = !rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temporary;
        if (tmp && rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_flag &&
            rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_stop_flag_bmc2) {
          rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.is_c2_ADV_ExtFunction = IN_Ready_iatp;
          rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts = 1U;
          rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_activetriger = false;
        } else if (tmp) {
          if (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_cnt > 0) {
            rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_cnt--;
          } else {
            rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_flag = true;
          }
        } else {
          rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_flag = false;
          rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.lka_temp_cnt = Cal_LKA_TEMPRECOVER_TMR;
        }
      }
      break;
    }
  }
  Fv_LKA_ControlSts = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts;
  /* End of Chart: '<S144>/LKAControlLogic' */
}

/* Output and update for atomic system: '<Root>/ADV_LKA_FUNC' */
void ADV_LKA_FUNC(void)
{
  /* Outputs for Atomic SubSystem: '<S6>/LKAControl_Cond' */
  LKAControl_Cond();

  /* End of Outputs for SubSystem: '<S6>/LKAControl_Cond' */

  /* Outputs for Atomic SubSystem: '<S6>/LKAControl_Logic' */
  LKAControl_Logic();

  /* End of Outputs for SubSystem: '<S6>/LKAControl_Logic' */

  /* Outputs for Atomic SubSystem: '<S6>/LKAControl_Exec' */
  LKAControl_Exec();

  /* End of Outputs for SubSystem: '<S6>/LKAControl_Exec' */

  /* Update for Delay: '<S6>/Delay' incorporates:
   *  Switch: '<S185>/Switch2'
   */
  rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE =
    rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
