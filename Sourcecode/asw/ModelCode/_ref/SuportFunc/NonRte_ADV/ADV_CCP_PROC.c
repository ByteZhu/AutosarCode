/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_CCP_PROC.c
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
#include "ADV_CCP_PROC.h"
#include "rtwtypes.h"
#include "ADV_ExtFunction_private.h"

#define CONFIG_Enable 1

ARID_DEF_ADV_CCP_PROC_ADV_ExtFu rtADV_CCP_PROC_ARID_DEF_ADV_Ext;

/* Output and update for atomic system: '<Root>/ADV_CCP_PROC' */
void ADV_CCP_PROC(void)
{
  /* local block i/o variables */
  uint8 rtb_CCP639_HPA;
  boolean rtb_AND_k3ny;
  boolean rtb_Compare_awmm;
  boolean rtb_Compare_nv3z;
  boolean rtb_Compare_pq3a;

  /* Logic: '<S2>/AND' incorporates:
   *  Constant: '<S60>/Constant'
   *  Inport generated from: '<Root>/In Bus Element12'
   *  RelationalOperator: '<S60>/Compare'
   */

  
#if CONFIG_Enable
  Fv_Configuration_CCP142_APA     = Fv_CANCCP142;
  Fv_Configuration_CCP150_LKALDW  = Fv_CANCCP150;
  Fv_Configuration_CCP316_LKALDW  = Fv_CANCCP316;
  Fv_Configuration_CCP317_EMA     = Fv_CANCCP317;
  Fv_Configuration_CCP494_HWA     = Fv_CANCCP494;
  Fv_Configuration_CCP565_APA     = Fv_CANCCP565;
  Fv_Configuration_CCP639_HPA     = Fv_CANCCP639;
  Fv_Configuration_CCP640_RPA     = Fv_CANCCP640;
  Fv_Configuration_CCP100_TJPNOP  = Fv_CANCCP100;
  rtb_AND_k3ny = (Fv_Configuration_CCP150_LKALDW
                     == ((uint8)1U));
  /* RelationalOperator: '<S66>/Compare' incorporates:
     *  Constant: '<S61>/Constant'
     *  Inport generated from: '<Root>/In Bus Element12'
     *  RelationalOperator: '<S61>/Compare'
     */
    rtb_Compare_awmm = (Fv_Configuration_CCP316_LKALDW == ((uint8)128U));

    /* Logic: '<S2>/AND' */
    //rtb_AND_k3ny = (rtb_AND_k3ny && rtb_Compare_awmm);

    /* RelationalOperator: '<S64>/Compare' incorporates:
     *  Constant: '<S64>/Constant'
     *  Inport generated from: '<Root>/In Bus Element12'
     */
    if((Fv_Configuration_CCP494_HWA >
       ((uint8)1U))&&(Fv_Configuration_CCP494_HWA <=(0x4))){
          rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Compare = 1;
       }
       if((Fv_Configuration_CCP494_HWA >=(0x83)) &&(Fv_Configuration_CCP494_HWA <= (0x85)))
       { rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Compare = 0;}

    /* RelationalOperator: '<S65>/Compare' incorporates:
     *  Constant: '<S65>/Constant'
     *  Inport generated from: '<Root>/In Bus Element12'
     */
    rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Compare_bd4g =
      (Fv_Configuration_CCP317_EMA >
       ((uint8)1U));

    /* RelationalOperator: '<S66>/Compare' incorporates:
     *  Constant: '<S66>/Constant'
     *  Inport generated from: '<Root>/In Bus Element12'
     */
    rtb_Compare_awmm = (Fv_Configuration_CCP142_APA > ((uint8)1U));

    /* RelationalOperator: '<S67>/Compare' incorporates:
     *  Constant: '<S67>/Constant'
     *  Inport generated from: '<Root>/In Bus Element12'
     */
    rtb_Compare_pq3a = (Fv_Configuration_CCP565_APA > ((uint8)1U));

    /* RelationalOperator: '<S68>/Compare' incorporates:
     *  Constant: '<S68>/Constant'
     *  Inport generated from: '<Root>/In Bus Element12'
     */
    rtb_Compare_nv3z = (Fv_Configuration_CCP640_RPA > ((uint8)1U));

    /* Logic: '<S2>/OR' */
    rtADV_CCP_PROC_ARID_DEF_ADV_Ext.OR = (rtb_Compare_awmm || rtb_Compare_pq3a ||
      rtb_Compare_nv3z);

    Fv_APA_Configuration = rtADV_CCP_PROC_ARID_DEF_ADV_Ext.OR;

#else
  rtb_AND_k3ny = ((Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP())
                  ->CCP150_LKALDW
                   == ((uint8)1U));


  /* RelationalOperator: '<S66>/Compare' incorporates:
   *  Constant: '<S61>/Constant'
   *  Inport generated from: '<Root>/In Bus Element12'
   *  RelationalOperator: '<S61>/Compare'
   */
  rtb_Compare_awmm = ((Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP()
                      )->CCP316_LKALDW == ((uint8)128U));

  /* Logic: '<S2>/AND' */
  rtb_AND_k3ny = (rtb_AND_k3ny && rtb_Compare_awmm);

  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Constant: '<S64>/Constant'
   *  Inport generated from: '<Root>/In Bus Element12'
   */

  rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Compare =
    ((Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP())->CCP494_HWA >
     ((uint8)1U));

  /* RelationalOperator: '<S65>/Compare' incorporates:
   *  Constant: '<S65>/Constant'
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Compare_bd4g =
    ((Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP())->CCP317_EMA >
     ((uint8)1U));

  /* RelationalOperator: '<S66>/Compare' incorporates:
   *  Constant: '<S66>/Constant'
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  rtb_Compare_awmm = ((Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP()
                      )->CCP142_APA > ((uint8)1U));

  /* RelationalOperator: '<S67>/Compare' incorporates:
   *  Constant: '<S67>/Constant'
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  rtb_Compare_pq3a = ((Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP()
                      )->CCP565_APA > ((uint8)1U));

  /* RelationalOperator: '<S68>/Compare' incorporates:
   *  Constant: '<S68>/Constant'
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  rtb_Compare_nv3z = ((Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP()
                      )->CCP640_RPA > ((uint8)1U));

  /* Logic: '<S2>/OR' */
  rtADV_CCP_PROC_ARID_DEF_ADV_Ext.OR = (rtb_Compare_awmm || rtb_Compare_pq3a ||
    rtb_Compare_nv3z);

#endif
//  debug_jing2 = Fv_Configuration_CCP150_LKALDW;
  /* Switch: '<S2>/Switch' */
  //150 = 1        316 = 128
  if (rtb_AND_k3ny) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     */
    rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[0] = false;
    rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[1] = false;
  } else {
    	rtb_AND_k3ny = (Fv_Configuration_CCP150_LKALDW
    	                       == ((uint8)5U));
      /* Switch: '<S2>/Switch2' */
      if (rtb_AND_k3ny) {
        /* Switch: '<S2>/Switch' incorporates:
         *  Constant: '<S2>/Constant4'
         *  Constant: '<S2>/Constant5'
         *  Switch: '<S2>/Switch1'
         */
        rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[0] = false;// mod by liuyang for eeprom problem
        rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[1] = true;
      } else {
        /* Switch: '<S2>/Switch' incorporates:
         *  Constant: '<S2>/Constant6'
         *  Constant: '<S2>/Constant7'
         *  Switch: '<S2>/Switch1'
         */
        rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[0] = true;
        rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[1] = true; // mod by liuyang for eeprom problem
      }

      /* End of Switch: '<S2>/Switch2' */
    }



  /* End of Switch: '<S2>/Switch' */

  /* SignalConversion generated from: '<S2>/Bus Selector' incorporates:
   *  Inport generated from: '<Root>/In Bus Element12'
   */
 // rtb_CCP639_HPA = (Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_CCP_FVstr_CAN_CCP())
 //   ->CCP639_HPA;

  rtb_CCP639_HPA = Fv_Configuration_CCP639_HPA;
  Fv_LKA_Configuration = rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[0];
//  debug_jing3 = Fv_LKA_Configuration;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
