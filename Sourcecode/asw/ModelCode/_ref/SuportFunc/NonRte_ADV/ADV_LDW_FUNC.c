/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_LDW_FUNC.c
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
#include "ADV_LDW_FUNC.h"
#include "ADV_CCP_PROC.h"
#include "Rte_Type.h"
#include <math.h>
#include "ADV_ExtFunction_private.h"
#include "CalVarSupport.h"
#include "look1_iu16ls32n10tu16_plinlcase.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "GlobalVarSupport.h"

/* Named constants for Chart: '<S122>/LDWControlLogic' */
#define IN_Active_gxqa                 ((uint8)1U)
#define IN_Initialization_jyku         ((uint8)2U)
#define IN_Permanent_lgcc              ((uint8)3U)
#define IN_Ready_ajzp                  ((uint8)4U)
#define IN_Temporary_ibha              ((uint8)5U)

#define RECEIVE_MODE_LDW              0

ARID_DEF_ADV_LDW_FUNC_ADV_ExtFu rtADV_LDW_FUNC_ARID_DEF_ADV_Ext;

/* System initialize for atomic system: '<S5>/LDWControl_Cond' */
void LDWControl_Cond_Init(void)
{
  /* InitializeConditions for Delay: '<S120>/Delay' */
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.icLoad = true;
}

/* Output and update for atomic system: '<S5>/LDWControl_Cond' */
void LDWControl_Cond(void)
{
  boolean Compare_tmp_tmp;

  /* Logic: '<S120>/Logical Operator9' incorporates:
   *  Constant: '<S131>/Constant'
   *  Constant: '<S132>/Constant'
   *  Constant: '<S133>/Constant'
   *  Logic: '<S120>/Logical Operator4'
   *  Logic: '<S120>/Logical Operator8'
   *  RelationalOperator: '<S131>/Compare'
   *  RelationalOperator: '<S132>/Compare'
   *  RelationalOperator: '<S133>/Compare'
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.suppression =
    ((rtADV_CCP_PROC_ARID_DEF_ADV_Ext.Switch[1] == false) ||
     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_BHM_MOD != HOLD_ACTIVE)
     || ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ <
          Cal_LDW_VSSTART) ||
         (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_ >
          Cal_LDW_VSEND)));
  /* Logic: '<S120>/Logical Operator6' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S125>/Constant'
   *  Constant: '<S127>/Constant'
   *  Inport generated from: '<Root>/In Bus Element16'
   *  RelationalOperator: '<S124>/Compare'
   *  RelationalOperator: '<S125>/Compare'
   *  RelationalOperator: '<S127>/Compare'
   */
#if RECEIVE_MODE_LDW
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temporary =
    ((Fv_CAN_AdsTqInvalid_flag ==
      true) || (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1 ==
                true) ||
     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s == 1));
#else
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temporary =
      ((Fv_AdsTqInvalid_flag ==
        true) || (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CA_l0v1 ==
                  true) ||
       (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_g51s == 1));
#endif
  /* Logic: '<S120>/Logical Operator5' incorporates:
   *  Constant: '<S126>/Constant'
   *  Constant: '<S128>/Constant'
   *  RelationalOperator: '<S126>/Compare'
   *  RelationalOperator: '<S128>/Compare'
   */
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_permanent =
    ((rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FRP_FAI == 1) ||
     (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_FR_bf30 == 1));

  /* Delay: '<S120>/Delay' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
#if RECEIVE_MODE_LDW
  if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.icLoad) {
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE =
      Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVbl_CAN_AdsTqWarn();
  }
#else
  if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.icLoad) {
      rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE =
    		  Fv_Warnreq;
    }
#endif

  /* RelationalOperator: '<S129>/Compare' incorporates:
   *  Delay: '<S120>/Delay'
   *  Inport generated from: '<Root>/In Bus Element1'
   * */
#if RECEIVE_MODE_LDW
  Compare_tmp_tmp = Rte_IRead_EXT_ExtFunction_1ms_FV_CAN_ADS_FVbl_CAN_AdsTqWarn();
#else
  Compare_tmp_tmp = Fv_Warnreq;
#endif
  /* RelationalOperator: '<S129>/Compare' incorporates:
   *  Constant: '<S129>/Constant'
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Compare = (Compare_tmp_tmp == true);

  /* Logic: '<S120>/Logical Operator1' incorporates:
   *  Constant: '<S123>/Constant'
   *  Constant: '<S130>/Constant'
   *  Delay: '<S120>/Delay'
   *  Inport generated from: '<Root>/In Bus Element1'
   *  RelationalOperator: '<S123>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   *  RelationalOperator: '<S130>/Compare'
   */
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_noactive = ((Compare_tmp_tmp == false) &&
    (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE == false));

  /* Update for Delay: '<S120>/Delay' */
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.icLoad = false;
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Delay_DSTATE = Compare_tmp_tmp;

}

/* Output and update for atomic system: '<S5>/LDWControl_Exec' */
void LDWControl_Exec(void)
{
  sint32 tmp;
  sint16 rtb_Switch_dmx3;
  uint16 rtb_ldw_vibfrz;

  /* Outputs for Atomic SubSystem: '<S121>/setampfrez' */
  /* Lookup_n-D: '<S135>/ldw_vibfrz' incorporates:
   *  SignalConversion generated from: '<Root>/In Bus Element7'
   */
  rtb_ldw_vibfrz = look1_iu16ls32n10tu16_plinlcase
    (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const uint16 *)
     &Cal_LDW_FrzVsTab_X[0], (const uint16 *)&Cal_LDW_FrzVsTab_Y[0],
     &rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.m_bpIndex, 5U);

  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S140>/Constant'
   *  RelationalOperator: '<S140>/Compare'
   */
  if (rtb_ldw_vibfrz > ((uint16)0U)) {
    /* Saturate: '<S135>/Saturation' incorporates:
     *  Lookup_n-D: '<S135>/ldw_vibamp'
     *  SignalConversion generated from: '<Root>/In Bus Element7'
     */
    rtb_Switch_dmx3 = look1_iu16ls32n10ts16D_QWHCuzIb
      (rtARID_DEF_ADV_ExtFunction.TmpSignalConversionAtFV_CAN_VS_, (const uint16
        *)&Cal_LDW_AmpVsTab_X[0], (const sint16 *)&Cal_LDW_AmpVsTab_Y[0],
       &rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.m_bpIndex_jppo, 5U);

    /* Saturate: '<S135>/Saturation' */
    if (rtb_Switch_dmx3 > Cal_LDW_VIBAMP_LIMIT) {
      rtb_Switch_dmx3 = Cal_LDW_VIBAMP_LIMIT;
    } else if (rtb_Switch_dmx3 < 0) {
      rtb_Switch_dmx3 = 0;
    }

    /* Switch: '<S135>/Switch' incorporates:
     *  Gain: '<S135>/Gain'
     *  Saturate: '<S135>/Saturation'
     */
    rtb_Switch_dmx3 = (sint16)((Cal_LDW_VibAmp_Gain * rtb_Switch_dmx3) >> 10);
  } else {
    /* Switch: '<S135>/Switch' incorporates:
     *  Constant: '<S135>/Constant'
     */
    rtb_Switch_dmx3 = 0;
  }

  /* End of Switch: '<S135>/Switch' */
  /* End of Outputs for SubSystem: '<S121>/setampfrez' */

  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S136>/Constant'
   *  RelationalOperator: '<S136>/Compare'
   */
  if ((rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts != ((uint8)2U)) && (Fv_DualPSCMFallBackWarningReq != 1)) {
    /* Switch: '<S134>/Switch' incorporates:
     *  Constant: '<S134>/Constant'
     */
    rtb_Switch_dmx3 = 0;
    
  }

  /* End of Switch: '<S134>/Switch' */

  /* Chart: '<S134>/cmdrate' incorporates:
   *  Constant: '<S134>/Constant3'
   *  Switch: '<S134>/Switch'
   */
  tmp = rtb_Switch_dmx3 - rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.cmdout;
  if (tmp > Cal_LDW_VIBAMP_RATE) {
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.cmdout += Cal_LDW_VIBAMP_RATE;
  } else if (tmp < -Cal_LDW_VIBAMP_RATE) {
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.cmdout -= Cal_LDW_VIBAMP_RATE;
  } else {
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.cmdout = rtb_Switch_dmx3;
  }

  /* End of Chart: '<S134>/cmdrate' */

  /* Outputs for Atomic SubSystem: '<S121>/setampfrez' */
  /* Saturate: '<S135>/Saturation1' */
  if (rtb_ldw_vibfrz > Cal_LDW_VIBFREZ_UP) {
    rtb_ldw_vibfrz = Cal_LDW_VIBFREZ_UP;
  } else if (rtb_ldw_vibfrz < Cal_LDW_VIBFREZ_DN) {
    rtb_ldw_vibfrz = Cal_LDW_VIBFREZ_DN;
  }

  /* Chart: '<S134>/ldw_sin_input' incorporates:
   *  Saturate: '<S135>/Saturation1'
   */
  rtb_ldw_vibfrz = (uint16)(1000U / rtb_ldw_vibfrz);

  /* End of Outputs for SubSystem: '<S121>/setampfrez' */
  if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.i < rtb_ldw_vibfrz) {
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.i++;
  } else {
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.i = 0U;
  }

  /* Gain: '<S134>/Gain1' incorporates:
   *  Chart: '<S134>/ldw_sin_input'
   *  DataTypeConversion: '<S134>/Data Type Conversion'
   *  DataTypeConversion: '<S137>/FixPt Gateway Out'
   *  Gain: '<S134>/Gain'
   *  Product: '<S134>/Product'
   *  Trigonometry: '<S134>/Trigonometric Function'
   */
  rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Gain1 = (sint16)(sin((float64)
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.i / (float64)rtb_ldw_vibfrz *
    6.2831853071795862) * (float64)rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.cmdout);

}

/* Output and update for atomic system: '<S5>/LDWControl_Logic' */
void LDWControl_Logic(void)
{
  boolean tmp;

  /* Chart: '<S122>/LDWControlLogic' */
  if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_active_c7_ADV_ExtFunction == 0U) {
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_active_c7_ADV_ExtFunction = 1U;
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
      IN_Initialization_jyku;
    rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 0U;
  } else {
    switch (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction) {
     case IN_Active_gxqa:
      rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 2U;
      if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_permanent) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Permanent_lgcc;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 4U;
      } else if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temporary) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Temporary_ibha;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 3U;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_flag = false;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_cnt = Cal_LDW_TEMPRECOVER_TMR;
      } else if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.suppression) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Initialization_jyku;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 0U;
      } else if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_noactive) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction = IN_Ready_ajzp;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 1U;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_activetriger = false;
      }
      break;

     case IN_Initialization_jyku:
      rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 0U;
      if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_permanent) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Permanent_lgcc;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 4U;
      } else if ((!rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.suppression) &&
                 (!rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temporary)) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction = IN_Ready_ajzp;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 1U;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_activetriger = false;
      }
      break;

     case IN_Permanent_lgcc:
      rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 4U;
      break;

     case IN_Ready_ajzp:
      rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 1U;
      if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_permanent) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Permanent_lgcc;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 4U;
      } else if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temporary) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Temporary_ibha;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 3U;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_flag = false;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_cnt = Cal_LDW_TEMPRECOVER_TMR;
      } else if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.suppression) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Initialization_jyku;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 0U;
      } else if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Compare &&
                 rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_activetriger) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction = IN_Active_gxqa;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 2U;
      } else {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_activetriger =
          ((rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Compare &&
            (!rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_active_last)) ||
           rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_activetriger);
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_active_last =
          rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Compare;
      }
      break;

     default:
      /* case IN_Temporary: */
      rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 3U;
      if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_permanent) {
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction =
          IN_Permanent_lgcc;
        rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 4U;
      } else {
        tmp = !rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temporary;
        if (tmp && rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_flag) {
          rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.is_c7_ADV_ExtFunction = IN_Ready_ajzp;
          rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.Fv_LDW_ControlSts = 1U;
          rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_activetriger = false;
        } else if (tmp) {
          if (rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_cnt > 0) {
            rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_cnt--;
          } else {
            rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_flag = true;
          }
        } else {
          rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_flag = false;
          rtADV_LDW_FUNC_ARID_DEF_ADV_Ext.ldw_temp_cnt = Cal_LDW_TEMPRECOVER_TMR;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S122>/LDWControlLogic' */
}

/* System initialize for atomic system: '<Root>/ADV_LDW_FUNC' */
void ADV_LDW_FUNC_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S5>/LDWControl_Cond' */
  LDWControl_Cond_Init();

  /* End of SystemInitialize for SubSystem: '<S5>/LDWControl_Cond' */
}

/* Output and update for atomic system: '<Root>/ADV_LDW_FUNC' */
void ADV_LDW_FUNC(void)
{
  /* Outputs for Atomic SubSystem: '<S5>/LDWControl_Cond' */
  LDWControl_Cond();

  /* End of Outputs for SubSystem: '<S5>/LDWControl_Cond' */

  /* Outputs for Atomic SubSystem: '<S5>/LDWControl_Logic' */
  LDWControl_Logic();

  /* End of Outputs for SubSystem: '<S5>/LDWControl_Logic' */

  /* Outputs for Atomic SubSystem: '<S5>/LDWControl_Exec' */
  LDWControl_Exec();

  /* End of Outputs for SubSystem: '<S5>/LDWControl_Exec' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
