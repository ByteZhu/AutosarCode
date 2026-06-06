/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_HANDSOFF_DETECT.c
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
#include "ADV_HANDSOFF_DETECT.h"
#include "Rte_Type.h"
#include "ADV_ExtFunction_private.h"
#include "look2_is16u16ls32n10tu_gntPemx1.h"
#include "look2_is16s16ls32n10ts_mOyVHgzB.h"
#include "CalVar.h"
#include "CalVarSupport.h"

ARID_DEF_ADV_HANDSOFF_DETECT_AD rtADV_HANDSOFF_DETECT_ARID_DEF_;
#if 1
/* Output and update for Simulink Function: '<S4>/Simulink Function' */
void btfilterllslp_ADV(float64 u, float64 y[4])
{
  float64 tmp;
  float64 tmp_0;

  /* MATLAB Function: '<S116>/btfirllslp' incorporates:
   *  SignalConversion generated from: '<S116>/u'
   */
  tmp_0 = 1.0 / (6.2831853071795862 * u) * 2.0 / 0.001;
  tmp = 1.0 / (tmp_0 + 1.0);

  /* SignalConversion generated from: '<S116>/y' incorporates:
   *  MATLAB Function: '<S116>/btfirllslp'
   */
  y[0] = tmp;
  y[1] = tmp;
  y[2] = 1.0;
  y[3] = -(tmp_0 - 1.0) / (tmp_0 + 1.0);
}
#else
extern void btfilterllslp(float64 u, float64 y[4]);
#endif
/* System initialize for atomic system: '<Root>/ADV_HANDSOFF_DETECT' */
void ADV_HANDSOFF_DETECT_Init(void)
{
  /* InitializeConditions for DiscreteFilter: '<S4>/filterlph' */
  rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_states = 0.0;
  rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_denStates = 0.0;

  /* SystemInitialize for Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  Chart: '<S4>/lkauser_handoff'
   */
  //(void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DrvrSteerWhlHldQly(0U);
  Fv_DrvrSteerWhlHldQly = 0;
}

/* Output and update for atomic system: '<Root>/ADV_HANDSOFF_DETECT' */
UInt32 m_bpIndex_HandOff[2];      
UInt32 pooled9_HandOff[2] = { 7U, 2U };
void ADV_HANDSOFF_DETECT(void)
{
  sint32 conv1;
  uint32 rtb_torque_st;
  sint16 rtb_Abs1;
  uint16 rtb_handsoff_step;
  sint16 rtb_handsoff_step_sig;

  /* DataTypeConversion: '<S4>/conv1' incorporates:
   *  DataTypeConversion: '<S118>/FixPt Gateway Out'
   *  SignalConversion generated from: '<Root>/In Bus Element22'
   */
  conv1 = rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_TAS_TRQ;

  /* FunctionCaller: '<S4>/Function Caller1' */
  btfilterllslp_ADV(Cal_HANDOFF_TrqFir_Frez,
                rtADV_HANDSOFF_DETECT_ARID_DEF_.FunctionCaller1);
  /* DiscreteFilter: '<S4>/filterlph' */
  rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_tmp =
    (rtADV_HANDSOFF_DETECT_ARID_DEF_.FunctionCaller1[0] * (float64)conv1 +
     rtADV_HANDSOFF_DETECT_ARID_DEF_.FunctionCaller1[1] *
     rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_states) -
    rtADV_HANDSOFF_DETECT_ARID_DEF_.FunctionCaller1[3] *
    rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_denStates;

  /* Saturate: '<S4>/Saturation' incorporates:
   *  DataTypeConversion: '<S4>/conv2'
   *  DiscreteFilter: '<S4>/filterlph'
   */
  if ((sint32)rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_tmp >= 10240) {
    /* Abs: '<S4>/Abs1' */
    rtb_Abs1 = 10240;
  } else if ((sint32)rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_tmp <= (-10240))
  {
    /* Abs: '<S4>/Abs1' */
    rtb_Abs1 = (-10240);
  } else {
    /* Abs: '<S4>/Abs1' */
    rtb_Abs1 = (sint16)(sint32)rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_tmp;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Abs: '<S4>/Abs1' */
  if (rtb_Abs1 < 0) {
    rtb_Abs1 = (sint16)-rtb_Abs1;
  }

  /* End of Abs: '<S4>/Abs1' */

  /* FunctionCaller: '<S4>/Function Caller' */
  //Rte_Call_RS_FEE_GetDTCType_client_RS_FEE_GetDTCType(FAULTTYPE_TORQUE,
  //  &rtb_torque_st);
  rtb_torque_st = Fv_FaultClass_Torque;
  /* RelationalOperator: '<S115>/Compare' incorporates:
   *  Constant: '<S115>/Constant'
   */
  rtADV_HANDSOFF_DETECT_ARID_DEF_.Compare = (rtb_torque_st > 0U);

  /* Lookup_n-D: '<S4>/handsoff_step' incorporates:
   *  Abs: '<S4>/Abs1'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */

#if 0
  rtb_handsoff_step = look2_is16u16ls32n10tu_gntPemx1(rtb_Abs1,
    rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const sint16 *)
    &Cal_LKA_HandsOffStepTab_T[0], (const uint16 *)&Cal_LKA_HandsOffStepTab_V[0],
    (const uint16 *)&Cal_LKA_HandsOffStepTab_S[0],
    rtADV_HANDSOFF_DETECT_ARID_DEF_.m_bpIndex, rtCP_handsoff_step_maxIndex, 4U);

  /* Chart: '<S4>/lkauser_handoff' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S114>/Constant'
   *  RelationalOperator: '<S114>/Compare'
   */
  if (rtb_Abs1 < Cal_LKA_HANDOFF_TRQ) 
  {
    if (rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt < Cal_LKA_HANDOFF_TMR)
    {
      rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt += rtb_handsoff_step;
    }
  } else if (rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt > rtb_handsoff_step) {
    rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt -= rtb_handsoff_step;
  } else {
    rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt = 0U;
  }
#else
  rtb_handsoff_step_sig = look2_is16s16ls32n10ts_mOyVHgzB(rtb_Abs1, 
  rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_,
    ((const Int16 *)&(Cal_LKA_HandsOffStep_Trq[0])), //X
    ((const Int16 *)&(Cal_LKA_HandsOffStep_Spd[0])), //Y
    ((const Int16 *)&(Cal_LKA_HandsOffStep_Out[0])), //Z
    m_bpIndex_HandOff, pooled9_HandOff, 8U);

  if(rtb_handsoff_step_sig > 0)
  {
    if ((rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt + rtb_handsoff_step_sig)< Cal_LKA_HANDOFF_TMR)
    {
      rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt += rtb_handsoff_step_sig;
    }
    else
    {
      rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt = Cal_LKA_HANDOFF_TMR;
    }
  }
  else
  {
    if (rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt  > -rtb_handsoff_step_sig)
    {
      rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt += rtb_handsoff_step_sig;
    }
    else
    {
      rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt = 0;
    }
  }
#endif


  rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly = (uint8)((uint32)((sint32)
    rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_cnt * 15) / Cal_LKA_HANDOFF_TMR);
  if (rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly > 15) {
    rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly = 15U;
  }

  Fv_DrvrSteerWhlHldQly = rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly;

#if 1
  if (rtb_torque_st > 0U) {
      /* Outport generated from: '<Root>/Out Bus Element8' */
      //(void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DrvrSteerWhlHldQly(0U);
    } else {
     if(rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly<=15 && 
     rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly>=11) {

    	   Fv_DrvrSteerWhlHld = 1;//handoff
      }else if(rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly>4)
      {
        Fv_DrvrSteerWhlHld = 2;
      }else{
        Fv_DrvrSteerWhlHld = 3;
      }

    }
#else
  if (rtb_torque_st > 0U) {
    /* Outport generated from: '<Root>/Out Bus Element8' */
    (void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DrvrSteerWhlHldQly(0U);
  } else {
    switch (rtADV_HANDSOFF_DETECT_ARID_DEF_.handoff_qly) {
     case 15:
      /* Outport generated from: '<Root>/Out Bus Element8' */
      (void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DrvrSteerWhlHldQly(1U);
      break;

     case 0:
      /* Outport generated from: '<Root>/Out Bus Element8' */
      (void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DrvrSteerWhlHldQly(3U);
      break;

     default:
      /* Outport generated from: '<Root>/Out Bus Element8' */
      (void)Rte_Write_FV_ADV_CTRL_FVu8_ADV_DrvrSteerWhlHldQly(2U);
      break;
    }
  }
#endif
  /* End of Chart: '<S4>/lkauser_handoff' */

  /* Update for DiscreteFilter: '<S4>/filterlph' */
  rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_states = conv1;
  rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_denStates =
    rtADV_HANDSOFF_DETECT_ARID_DEF_.filterlph_tmp;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
