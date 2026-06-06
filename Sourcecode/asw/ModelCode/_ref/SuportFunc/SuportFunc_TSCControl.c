/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SuportFunc_TSCControl.c
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 9.58
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Jan  5 15:52:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SuportFunc.h"
#include "SuportFunc_TSCControl.h"
#include "rtwtypes.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "GlobalVar.h"
#include "CalVar.h"
#include "CalVarExt.h"
#include "CalVarSupport.h"
#include "GlobalVar_EXT.h"


	extern volatile UInt16 Fv_VehSpdNew;

/* Output and update for atomic system: '<S106>/TSCControl_Logic' */
uint16 TSC_vehspd_last = 0;
uint16 TSC_tsc_spd_cnt = 0;
uint16 TSC_tsc_cnt = 0;
uint8 Fv_TSC_SpdFlag_apfc = 0;
uint8 Fv_TSC_Flag_b2yu = 0;
sint16 TSC_Add = 0;
uint32 TSC_m_bpIndex = 0;
sint32 TSC_cmdout = 0;
void TSCControl_Logic(void)
{
  Int32 tmp_0;
  Int16 rtb_DataTypeConversion1_jvng;
  Int16 rtb_cmdinput_kk1h;
  Int16 tmp;
  UInt16 rtb_Abs3;
  static UInt8 vehspd_overtmr;
  static UInt8 vehspd_overflag;

  /* Chart: '<S107>/TSC_VehSpdJudge' incorporates:
   *  DataStoreRead: '<S108>/Data Store Read5'
   */
  /* Gateway: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/TSC_VehSpdJudge */
  /* During: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/TSC_VehSpdJudge */
  /* Entry Internal: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/TSC_VehSpdJudge */
  /* Transition: '<S114>:710' */
//  if ((Fv_VehSpdNew - (TSC_vehspd_last << 5ULL)) > (Cal_TSC_VEHSPD_DIFF <<
//       5ULL)) {


  
  if(vehspd_overtmr < 10)
  {
    vehspd_overtmr++;    
  }
  else
  {
    if ((Fv_VehSpdNew - (TSC_vehspd_last)) > (Cal_TSC_VEHSPD_DIFF)) 
    {
      vehspd_overflag = 1;
    } 
    else 
    {
      /* Transition: '<S114>:901' */
      Fv_TSC_SpdFlag_apfc = 0U;
      TSC_tsc_spd_cnt = 0U;
      vehspd_overflag = 0;
    }    
    vehspd_overtmr = 0;
    TSC_vehspd_last = (UInt16)(Fv_VehSpdNew);
  }

  if(vehspd_overflag > 0)
  {    
    if (TSC_tsc_spd_cnt < Cal_TSC_VEHSPDCNT) 
    {
      /* Transition: '<S114>:897' */
      /* Transition: '<S114>:899' */
      TSC_tsc_spd_cnt = (UInt16)((Int32)(((Int32)TSC_tsc_spd_cnt) + 1));
    

      /* Transition: '<S114>:908' */
    } 
    else 
    {
      Fv_TSC_SpdFlag_apfc = 1U;
      /* Transition: '<S114>:907' */
    }
  }

  

  /* Transition: '<S114>:911' */
  //TSC_vehspd_last = (UInt16)(((UInt32)Fv_VehSpdNew) >> 5ULL);


  /* End of Chart: '<S107>/TSC_VehSpdJudge' */

  /* Sum: '<S107>/TSC_Add' incorporates:
   *  DataStoreRead: '<S108>/Data Store Read'
   *  DataStoreRead: '<S108>/Data Store Read1'
   */
  rtb_DataTypeConversion1_jvng = (Int16)(((Int16)Fv_WheelSpeed_FL) - ((Int16)
    Fv_WheelSpeed_FR));

  /* Abs: '<S107>/Abs3' */
  if (rtb_DataTypeConversion1_jvng < 0) {
    rtb_Abs3 = (UInt16)((Int32)(-((Int32)rtb_DataTypeConversion1_jvng)));
  } else {
    rtb_Abs3 = (UInt16)rtb_DataTypeConversion1_jvng;
  }

  /* End of Abs: '<S107>/Abs3' */

  /* Abs: '<S107>/Abs2' */
  /* Gateway: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/TSC_Logic */
  /* During: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/TSC_Logic */
  /* Entry Internal: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/TSC_Logic */
  /* Transition: '<S113>:710' */
  if (TSC_Add < 0) {
    rtb_cmdinput_kk1h = (Int16)(-TSC_Add);
  } else {
    rtb_cmdinput_kk1h = TSC_Add;
  }

  /* Abs: '<S107>/Abs1' incorporates:
   *  DataStoreRead: '<S108>/Data Store Read2'
   */
  if (Tv_dStrAng < 0) {
    tmp = (Int16)(-Tv_dStrAng);
  } else {
    tmp = Tv_dStrAng;
  }
  
  /* Chart: '<S107>/TSC_Logic' incorporates:
   *  Abs: '<S107>/Abs1'
   *  Abs: '<S107>/Abs2'
   *  Constant: '<S109>/Constant'
   *  Constant: '<S110>/Constant'
   *  Constant: '<S111>/Constant'
   *  Logic: '<S107>/Logical Operator'
   *  Logic: '<S107>/Logical Operator1'
   *  RelationalOperator: '<S109>/Compare'
   *  RelationalOperator: '<S110>/Compare'
   *  RelationalOperator: '<S111>/Compare'
   */
  if ((((rtb_cmdinput_kk1h <= Cal_TSC_ANGLMT) && (tmp <= Cal_TSC_ANGSPDLMT)) &&
       (Fv_TSC_SpdFlag_apfc != 0ULL)) && (rtb_Abs3 >=
       Cal_TSC_WHEELSPD_DIFF)) {
    /* Transition: '<S113>:851' */
    if (TSC_tsc_cnt < Cal_TSC_CNT) {
      /* Transition: '<S113>:854' */
      /* Transition: '<S113>:856' */
      TSC_tsc_cnt = (UInt16)((Int32)(((Int32)TSC_tsc_cnt) + 1));

      /* Transition: '<S113>:859' */
    } else {
      /* Transition: '<S113>:858' */
      Fv_TSC_Flag_b2yu = 1U;
    }

    /* Transition: '<S113>:862' */
  } else {
    /* Transition: '<S113>:861' */
    Fv_TSC_Flag_b2yu = 0U;
    TSC_tsc_cnt = 0U;
  }

  /* End of Chart: '<S107>/TSC_Logic' */

  /* DataStoreWrite: '<S107>/Data Store Write1' */
  Fv_TSC_Flag = Fv_TSC_Flag_b2yu;

  /* Lookup_n-D: '<S107>/tsclooktable_cmd' incorporates:
   *  Abs: '<S107>/Abs3'
   */
  rtb_cmdinput_kk1h = look1_iu16ls32n10ts16D_QWHCuzIb(rtb_Abs3, (const UInt16 *)
    &Cal_TSC_CMD_Tab_X[0], (const Int16 *)&Cal_TSC_CMD_Tab_Y[0],
    &TSC_m_bpIndex, 4U);

  /* Chart: '<S107>/cmdrate' incorporates:
   *  Constant: '<S107>/Constant3'
   *  Lookup_n-D: '<S107>/tsclooktable_cmd'
   */
  /* Gateway: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/cmdrate */
  /* During: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/cmdrate */
  /* Entry Internal: SuportFunc_TSCControl/TSCControl_Atomic/TSCControl_Logic/cmdrate */
  /* Transition: '<S115>:745' */
  tmp_0 = ((Int32)rtb_cmdinput_kk1h) - ((Int32)TSC_cmdout);
  if (tmp_0 > ((Int32)Cal_TSC_VIBAMP_RATE)) {
    /* Transition: '<S115>:747' */
    /* Transition: '<S115>:751' */
    TSC_cmdout += Cal_TSC_VIBAMP_RATE;

    /* Transition: '<S115>:760' */
    /* Transition: '<S115>:761' */

    /* Transition: '<S115>:753' */
  } else if (tmp_0 < (-((Int32)Cal_TSC_VIBAMP_RATE))) {
    /* Transition: '<S115>:755' */
    /* Transition: '<S115>:757' */
    TSC_cmdout -= Cal_TSC_VIBAMP_RATE;

    /* Transition: '<S115>:761' */
  } else {
    /* Transition: '<S115>:759' */
    TSC_cmdout = rtb_cmdinput_kk1h;
  }

  /* End of Chart: '<S107>/cmdrate' */

  /* Signum: '<S107>/Sign' */
  if (rtb_DataTypeConversion1_jvng < 0) {
    rtb_cmdinput_kk1h = -1;
  } else {
    rtb_cmdinput_kk1h = (Int16)((rtb_DataTypeConversion1_jvng > 0) ? ((Int32)1) :
      ((Int32)0));
  }

  /* Gain: '<S107>/Gain1' incorporates:
   *  DataStoreWrite: '<S107>/Data Store Write2'
   *  DataTypeConversion: '<S107>/Data Type Conversion1'
   *  Product: '<S107>/Product'
   *  Product: '<S107>/Product2'
   *  Signum: '<S107>/Sign'
   */
  Fv_TSC_CurOut = (Int16)((((Int32)Fv_TSC_Flag_b2yu) * ((Int32)
    TSC_cmdout)) * ((Int32)rtb_cmdinput_kk1h));

  /* DataStoreWrite: '<S107>/Data Store Write3' */
  Fv_TSC_SpdFlag = Fv_TSC_SpdFlag_apfc;
}

/* Output and update for atomic system: '<S106>/TSCControl_Paras' */
void TSCControl_Paras(void)
{
  /* Sum: '<S108>/TSC_Add' incorporates:
   *  DataStoreRead: '<S108>/Data Store Read3'
   *  DataStoreRead: '<S108>/Data Store Read4'
   */
  TSC_Add = (Int16)(Fv_StrAng - Fv_StrAngOffset);
}

/* Output and update for atomic system: '<Root>/SuportFunc_TSCControl' */
void SuportFunc_TSCControl(void)
{
  /* Outputs for Enabled SubSystem: '<S4>/TSCControl_Atomic' incorporates:
   *  EnablePort: '<S106>/Enable'
   */
  Fv_TSC_Configuration = Cal_TSC_Enable;
  /* DataStoreRead: '<S4>/Data Store Read2' */
  if (Fv_TSC_Configuration) {
    /* Outputs for Atomic SubSystem: '<S106>/TSCControl_Paras' */
    TSCControl_Paras();

    /* End of Outputs for SubSystem: '<S106>/TSCControl_Paras' */

    /* Outputs for Atomic SubSystem: '<S106>/TSCControl_Logic' */
    TSCControl_Logic();

    /* End of Outputs for SubSystem: '<S106>/TSCControl_Logic' */
  }

  /* End of DataStoreRead: '<S4>/Data Store Read2' */
  /* End of Outputs for SubSystem: '<S4>/TSCControl_Atomic' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
