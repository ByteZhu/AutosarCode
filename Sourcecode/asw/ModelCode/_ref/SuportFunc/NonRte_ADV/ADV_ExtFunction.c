/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_ExtFunction.c
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
#include "ADV_HANDSOFF_DETECT.h"
#include "ADV_CCP_PROC.h"
#include "ADV_APA_FUNC.h"
#include "ADV_DSR_FUNC.h"
#include "ADV_LDW_FUNC.h"
#include "ADV_LKA_FUNC.h"
#include "ADV_STATE_SET.h"
#include "ADV_ExtFunction_private.h"
#include "LQR.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_ADV_ExtFunction rtARID_DEF_ADV_ExtFunction;

/* Model step function */
void EXT_ExtFunction_1ms(void)
{
  
  //(void)Rte_Read_FV_CAN_VS_FVu16q5_CAN_VehSpd_0
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ = ((UInt16)(Fv_EXT_CanSpd*0.45));  //Fv——EXT_Canspd 256 m/s-> 32 km/h (*32*3.6/256) ly 241122

  //(void)Rte_Read_FV_CAN_VS_FVbl_CAN_VsInvalid_flag
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1 = !Fv_EXT_SpdValidFlag;

  //(void)Rte_Read_FV_FRP_FAIL_FVs16_FRP_HighFail_flag
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FRP_FAI);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FRP_FAI = Fv_HighFailFlag;

  //(void)Rte_Read_FV_FRP_FAIL_FVs16_FRP_LimitFail_flag
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_bf30);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_bf30 = Fv_LimitFailFlag;

  //(void)Rte_Read_FV_FRP_FAIL_FVs16_FRP_LowFail_flag
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s = Fv_LowFailFlag;

  //(void)Rte_Read_FV_FRP_FAIL_FVs16_FRP_StrAngFail_flag
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_jyet);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_jyet = Fv_StrAngFailFlag;

  //(void)Rte_Read_FV_BHM_MOD_FVenm_BHM_WhichMode
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_BHM_MOD);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_BHM_MOD = Fv_WhichMode;

  //(void)Rte_Read_FV_TAS_ANG_FVs16q4_TAS_StrAng_raw
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_ANG = Fv_StrAng_Raw;
  


  //(void)Rte_Read_FV_TAS_ANG_FVs16q3_TAS_LowRev_rpm
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_e3ct);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_e3ct = Fv_LowRev_rpm;

  //(void)Rte_Read_FV_TAS_ANG_FVs16q4_TAS_dStrAng
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TA_bp5n = Fv_dStrAng;

  //(void)Rte_Read_FV_TAS_TRQ_FVs16q10_TAS_StrTrq_0
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ = Fv_StrTrq0;

  //(void)Rte_Read_FV_MTR_RTR_FVs32q10_MTR_FOC_RotorSpd
  //  (&rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_MTR_RTR);
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_MTR_RTR = Fv_FOC_RotorSpd;

  ADV_HANDSOFF_DETECT();

  /* End of Outputs for SubSystem: '<Root>/ADV_HANDSOFF_DETECT' */

  /* Outputs for Atomic SubSystem: '<Root>/ADV_CCP_PROC' */
  ADV_CCP_PROC();

  /* End of Outputs for SubSystem: '<Root>/ADV_CCP_PROC' */

  /* Outputs for Atomic SubSystem: '<Root>/ADV_APA_FUNC' */
  ADV_APA_FUNC();

  /* End of Outputs for SubSystem: '<Root>/ADV_APA_FUNC' */

  /* Outputs for Atomic SubSystem: '<Root>/ADV_DSR_FUNC' */
  ADV_DSR_FUNC();

  /* End of Outputs for SubSystem: '<Root>/ADV_DSR_FUNC' */

  /* Outputs for Atomic SubSystem: '<Root>/ADV_LDW_FUNC' */
  ADV_LDW_FUNC();

  /* End of Outputs for SubSystem: '<Root>/ADV_LDW_FUNC' */

  /* Outputs for Atomic SubSystem: '<Root>/ADV_LKA_FUNC' */
  ADV_LKA_FUNC();

  /* End of Outputs for SubSystem: '<Root>/ADV_LKA_FUNC' */

  /* Outputs for Atomic SubSystem: '<Root>/ADV_STATE_SET' */
  ADV_STATE_SET();

  /* End of Outputs for SubSystem: '<Root>/ADV_STATE_SET' */

  /* Outport generated from: '<Root>/Out Bus Element' */
  Fv_APA_ControlSts = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts;
  //Rte_IWrite_EXT_ExtFunction_1ms_FV_ADV_CTRL_FVu8_ADV_APAControlSts
  //  (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Fv_APA_ControlSts);

  Fv_LKA_ControlSts = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts;
  //(void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_LKAControlSts
  //  (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Fv_LKA_ControlSts);

  Fv_LDW_ControlSts = rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts;
  //(void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_LDWControlSts
  //  (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts);

  Fv_APA_Torque = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE;
  //(void)Rte_Write_FV_ADV_CTRL_FVs32q7_ADV_APATorque
  //  (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE);
  
  Fv_LKA_Torque = rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2;
  //(void)Rte_Write_FV_ADV_CTRL_FVs16q7_ADV_LKATorque
  //  (rtADV_LKA_FUNC_ARID_DEF_ADV_Ext.Switch2);

  Fv_LDW_Torque = rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Gain1;
  //(void)Rte_Write_FV_ADV_CTRL_FVs16q7_ADV_LDWTorque
  //  (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Gain1);

  Fv_DrvrSteerWhlHld = rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly;
  //(void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DrvrSteerWhlHld
  //  (rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly);

  Fv_DSR_ControlSts = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts;
  //(void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DSRControlSts
  //  (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Fv_DSR_ControlSts);

  Fv_DSR_Torque = rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_d4s5;
  //(void)Rte_Write_FV_ADV_CTRL_FVs16q7_ADV_DSRTorque
  //  (rtADV_DSR_FUNC_ARID_DEF_ADV_Ext.Switch2_d4s5);

  Fv_SteerStsToParkAssi = rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi;
  //(void)Rte_Write_FV_ADV_CTRL_FVenm_ADV_SteerStsToParkAssi
  //  (rtADV_APA_FUNC_ARID_DEF_ADV_Ext.SteerStsToParkAssi);
}

/* Model initialize function */
void EXT_ExtFunction_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/ADV_HANDSOFF_DETECT' */
  ADV_HANDSOFF_DETECT_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/ADV_HANDSOFF_DETECT' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/ADV_LDW_FUNC' */
  ADV_LDW_FUNC_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/ADV_LDW_FUNC' */
  LQR_initialize();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
