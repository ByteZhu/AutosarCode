/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_STATE_SET.c
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
#include "ADV_STATE_SET.h"
#include "ADV_LKA_FUNC.h"
#include "ADV_DSR_FUNC.h"
#include "ADV_APA_FUNC.h"
#include "ADV_LDW_FUNC.h"
#include "Rte_Type.h"
#include "rtwtypes.h"
#include "ADV_ExtFunction_private.h"

/* Output and update for atomic system: '<Root>/ADV_STATE_SET' */
void ADV_STATE_SET(void)
{
  sint16 rtb_trq_ba3r;
  boolean rtb_Compare_kfvv;
  boolean rtb_Compare_n2p3;
  boolean rtb_Compare_osrx;
  ADVMOD rtb_DataTypeConversion_oif3;

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Constant: '<S207>/Constant'
   *  Inport generated from: '<Root>/In Bus Element16'
   *  Inport generated from: '<Root>/In Bus Element3'
   *  Product: '<S7>/Product4'
   *  RelationalOperator: '<S207>/Compare'
   */
  /*����mode��23.11.12 by zyg*/
#if 0
  rtb_DataTypeConversion_oif3 = (ADVMOD)
    (Fv_CAN_AdsTqInvalid_flag ==
     false ? (sint32)Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVu8_CAN_AdsMod() :
     0);
#else
     rtb_DataTypeConversion_oif3 = (ADVMOD)
         (Fv_CAN_AdsTqInvalid_flag ==
          false ? (sint32)Fv_AdsMod :
          0);
#endif
  /* RelationalOperator: '<S200>/Compare' incorporates:
   *  Constant: '<S200>/Constant'
   */
  rtb_Compare_kfvv = (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts ==
                      ((uint8)2U));

  /* RelationalOperator: '<S202>/Compare' incorporates:
   *  Constant: '<S202>/Constant'
   */
  rtb_Compare_osrx = (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts ==
                      ((uint8)2U));

  /* RelationalOperator: '<S201>/Compare' incorporates:
   *  Constant: '<S201>/Constant'
   *  Delay: '<S1>/Delay'
   *  Product: '<S41>/Divide'
   */
  rtb_Compare_n2p3 = (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE == 256);

  /* MultiPortSwitch generated from: '<S7>/Multiport Switch' */
  switch (rtb_DataTypeConversion_oif3) {
   case ADVMOD_HWA:
   case ADVMOD_ELKAO:
   case ADVMOD_ELKAS:
   case ADVMOD_SLKA:
   case ADVMOD_SAC:
   case ADVMOD_SHWA:
    /* Switch generated from: '<S7>/Switch' */
    if (rtb_Compare_kfvv) {
      /* MultiPortSwitch generated from: '<S7>/Multiport Switch' incorporates:
       *  Switch: '<S185>/Switch2'
       */
      rtb_trq_ba3r = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2;
    } else {
      /* MultiPortSwitch generated from: '<S7>/Multiport Switch' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      rtb_trq_ba3r = 0;
    }
    break;

   case ADVMOD_DSROS:
   case ADVMOD_DSRMS:
   case ADVMOD_DSRTS:
   case ADVMOD_EMA:
    /* Switch generated from: '<S7>/Switch1' */
    if (rtb_Compare_osrx) {
      /* MultiPortSwitch generated from: '<S7>/Multiport Switch' incorporates:
       *  Switch: '<S111>/Switch2'
       */
      rtb_trq_ba3r = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_d4s5;
    } else {
      /* MultiPortSwitch generated from: '<S7>/Multiport Switch' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      rtb_trq_ba3r = 0;
    }
    break;

   case ADVMOD_APA:
   case ADVMOD_RPA:
    /* Switch generated from: '<S7>/Switch2' */
    if (rtb_Compare_n2p3) {
      /* MultiPortSwitch generated from: '<S7>/Multiport Switch' */
      rtb_trq_ba3r = (sint16)(rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts <<
        7);
    } else {
      /* MultiPortSwitch generated from: '<S7>/Multiport Switch' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      rtb_trq_ba3r = 0;
    }
    break;

   case ADVMOD_HPA:
    /* MultiPortSwitch generated from: '<S7>/Multiport Switch' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    rtb_trq_ba3r = 0;
    break;

   default:
    /* MultiPortSwitch generated from: '<S7>/Multiport Switch' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    rtb_trq_ba3r = 0;
    break;
  }

  /* MultiPortSwitch generated from: '<S7>/Multiport Switch' */
  switch (rtb_DataTypeConversion_oif3) {
   case ADVMOD_HWA:
   case ADVMOD_ELKAO:
   case ADVMOD_ELKAS:
   case ADVMOD_SLKA:
   case ADVMOD_SAC:
   case ADVMOD_SHWA:
    /* Switch generated from: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    if (!rtb_Compare_kfvv) {
      rtb_DataTypeConversion_oif3 = ADVMOD_NOREQ;
    }

    /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
     *  Switch generated from: '<S7>/Switch'
     */
    Fv_ADV_CtrlMode = (rtb_DataTypeConversion_oif3);
    break;

   case ADVMOD_DSROS:
   case ADVMOD_DSRMS:
   case ADVMOD_DSRTS:
   case ADVMOD_EMA:
    /* Switch generated from: '<S7>/Switch1' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    if (!rtb_Compare_osrx) {
      rtb_DataTypeConversion_oif3 = ADVMOD_NOREQ;
    }

    /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
     *  Switch generated from: '<S7>/Switch1'
     */
    Fv_ADV_CtrlMode = (rtb_DataTypeConversion_oif3);
    break;

   case ADVMOD_APA:
   case ADVMOD_RPA:
    /* Switch generated from: '<S7>/Switch2' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    if (!rtb_Compare_n2p3) {
      rtb_DataTypeConversion_oif3 = ADVMOD_NOREQ;
    }

    /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
     *  Switch generated from: '<S7>/Switch2'
     */
    Fv_ADV_CtrlMode = (rtb_DataTypeConversion_oif3);
    break;

   case ADVMOD_HPA:
    /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    Fv_ADV_CtrlMode = (ADVMOD_NOREQ);
    break;

   default:
    /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    Fv_ADV_CtrlMode = (ADVMOD_NOREQ);
    break;
  }
#if 0
  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  Logic: '<S7>/OR'
   */
  (void)Rte_Write_FV_ADV_CTRL_FVbl_ADV_CloseLoop_Dis(rtb_Compare_kfvv ||
    rtb_Compare_n2p3);
#endif
#if 0
  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  Constant: '<S203>/Constant'
   *  Constant: '<S204>/Constant'
   *  Constant: '<S205>/Constant'
   *  Delay: '<S1>/Delay'
   *  Logic: '<S7>/OR1'
   *  Product: '<S41>/Divide'
   *  RelationalOperator: '<S203>/Compare'
   *  RelationalOperator: '<S204>/Compare'
   *  RelationalOperator: '<S205>/Compare'
   */
  (void)Rte_Write_FV_ADV_CTRL_FVbl_ADV_SteerServoSts
    ((rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts > ((uint8)2U)) ||
     (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE > 256) ||
     (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts > ((uint8)2U)));
#endif
#if 0
  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  Constant: '<S206>/Constant'
   *  Gain: '<S134>/Gain1'
   *  Gain: '<S7>/aim2motor'
   *  MultiPortSwitch generated from: '<S7>/Multiport Switch'
   *  Product: '<S7>/Product'
   *  RelationalOperator: '<S206>/Compare'
   *  Sum: '<S7>/Add'
   */
  (void)Rte_Write_FV_ADV_CTRL_FVs16q8_ADV_SteerWhlTqAddl((sint16)((((uint16)51U)
    * (sint16)(rtb_trq_ba3r + ((rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Gain1 == 256 ?
    (sint32)rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts : 0) << 7))) >> 9));
#endif
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
