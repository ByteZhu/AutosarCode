/*
 * File: EPSADC.c
 *
 * Code generated for Simulink model 'EPSADC'.
 *
 * Model version                  : 1.1184
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov  7 10:07:14 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EPSADC.h"
#include "EPSADC_private.h"
#include "asr_s32.h"
#include "look1_iu16ls32n10ts16D_QWHCuzIb.h"
#include "look2_is16u16ls32n10tu_gntPemx1.h"
/* Named constants for Chart: '<S26>/anglecheck' */
#define EPSADC_IN_calculation          ((UInt8)1U)
#define EPSADC_IN_wait                 ((UInt8)2U)

/* Named constants for Chart: '<S14>/angle_shedule' */
#define EPSADC_IN_Decode               ((UInt8)1U)
#define EPSADC_IN_Default              ((UInt8)2U)
#define EPSADC_IN_Follow               ((UInt8)1U)
#define EPSADC_IN_Mix                  ((UInt8)2U)
#define EPSADC_IN_NO_ACTIVE_CHILD_fqrs ((UInt8)0U)
#define EPSADC_CONST_DIFFMAX           (2097152)

/* Block states (default storage) */
EPSADC_DW_fwu4 EPSADCrtDW;

/* System initialize for atomic system: '<S1>/EpsAngleConv_LowRevSyn' */
void EPS_EpsAngleConv_LowRevSyn_Init(void)
{
  /* SystemInitialize for Chart: '<S4>/DiffCalc' */
  EPSADCrtDW.bitsForTID0.trg_valid_flag = true;
}

/* Output and update for atomic system: '<S1>/EpsAngleConv_LowRevSyn' */
void EPSADC_EpsAngleConv_LowRevSyn(void)
{
  Int32 diff_ang;
  Int32 Switch_idx_0;
  Int32 Switch_idx_1;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/Constant5'
   *  DataStoreRead: '<S4>/Data Store Read'
   *  DataStoreRead: '<S4>/Data Store Read1'
   *  DataStoreRead: '<S4>/Data Store Read2'
   *  DataTypeConversion: '<S4>/Data Type Conversion1'
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   */
  if (Fv_SystemTransferState) {
    Switch_idx_0 = Fv_RotorAng_AddSumFilter;
    Switch_idx_1 = MACRO_REVEXT_LIMITR * 32;
  } else {
    Switch_idx_0 = Fv_RotorAng_AddSum;
    Switch_idx_1 = MACRO_REVEXT_LIMITI * 32;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Chart: '<S4>/DiffCalc' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   */
  /* Gateway: EpsAngleConv/EpsAngleConv_LowRevSyn/DiffCalc */
  /* During: EpsAngleConv/EpsAngleConv_LowRevSyn/DiffCalc */
  /* Entry Internal: EpsAngleConv/EpsAngleConv_LowRevSyn/DiffCalc */
  /* Transition: '<S7>:128' */
  if (!EPSADCrtDW.bitsForTID0.first_flag) {
    /* Transition: '<S7>:203' */
    /* Transition: '<S7>:205' */
    EPSADCrtDW.last_ang = Switch_idx_0;
    EPSADCrtDW.bitsForTID0.first_flag = true;

    /* Transition: '<S7>:208' */
  } else {
    /* Transition: '<S7>:207' */
  }

  /* Transition: '<S7>:209' */
  if (SysTaskRsvResetTrgPending) {
    /* Transition: '<S7>:130' */
    /* Transition: '<S7>:132' */
    EPSADCrtDW.bitsForTID0.trg_valid_flag = true;
    EPSADCrtDW.trg_valid_cnt = 0U;
  } else {
    /* Transition: '<S7>:134' */
    if (EPSADCrtDW.trg_valid_cnt < ((UInt16)MACRO_REVEXT_TRGCNT)) {
      /* Transition: '<S7>:136' */
      /* Transition: '<S7>:138' */
      EPSADCrtDW.trg_valid_cnt = (UInt16)((Int32)(((Int32)
        EPSADCrtDW.trg_valid_cnt) + 1));
    } else {
      /* Transition: '<S7>:140' */
      EPSADCrtDW.bitsForTID0.trg_valid_flag = false;

      /* Transition: '<S7>:141' */
    }

    /* Transition: '<S7>:142' */
  }

  if (EPSADCrtDW.bitsForTID0.trg_valid_flag) {
    /* Transition: '<S7>:152' */
    /* Transition: '<S7>:154' */
    EPSADCrtDW.last_ang = Switch_idx_0;
    EPSADCrtDW.out_last_y = 0;
    EPSADCrtDW.out_last_x = 0;

    /* Transition: '<S7>:160' */
  } else {
    /* Transition: '<S7>:156' */
  }

  /* Transition: '<S7>:212' */
  diff_ang = Switch_idx_0 - EPSADCrtDW.last_ang;
  if (diff_ang > 2097152) {
    /* Transition: '<S7>:214' */
    /* Transition: '<S7>:216' */
    diff_ang = EPSADC_CONST_DIFFMAX;

    /* Transition: '<S7>:223' */
    /* Transition: '<S7>:226' */
  } else {
    /* Transition: '<S7>:218' */
    if (diff_ang < -2097152) {
      /* Transition: '<S7>:220' */
      /* Transition: '<S7>:222' */
      diff_ang = -2097152;

      /* Transition: '<S7>:226' */
    } else {
      /* Transition: '<S7>:225' */
    }
  }

  /* Transition: '<S7>:162' */
  diff_ang *= 1000;
  EPSADCrtDW.last_ang = Switch_idx_0;
  if (diff_ang > Switch_idx_1) {
    /* Transition: '<S7>:164' */
    /* Transition: '<S7>:166' */
    diff_ang = Switch_idx_1;

    /* Transition: '<S7>:175' */
    /* Transition: '<S7>:176' */
  } else {
    /* Transition: '<S7>:168' */
    if (diff_ang < (-Switch_idx_1)) {
      /* Transition: '<S7>:170' */
      /* Transition: '<S7>:172' */
      diff_ang = -Switch_idx_1;

      /* Transition: '<S7>:176' */
    } else {
      /* Transition: '<S7>:174' */
    }
  }

  /* Transition: '<S7>:178' */
  EPSADCrtDW.out_last_y = (((EPSADCrtDW.out_last_y * 14) + diff_ang) +
    EPSADCrtDW.out_last_x) / 16;
  EPSADCrtDW.out_last_x = diff_ang;
  if (EPSADCrtDW.out_last_y > MACRO_REVEXT_DEADDOOR) {
    /* Transition: '<S7>:180' */
    /* Transition: '<S7>:182' */
    Fv_LowRev = (asr_s32(EPSADCrtDW.out_last_y - MACRO_REVEXT_DEADDOOR, 5U));

    /* Transition: '<S7>:192' */
    /* Transition: '<S7>:191' */
  } else {
    /* Transition: '<S7>:184' */
    if (EPSADCrtDW.out_last_y < (-MACRO_REVEXT_DEADDOOR)) {
      /* Transition: '<S7>:186' */
      /* Transition: '<S7>:188' */
      Fv_LowRev = (asr_s32(EPSADCrtDW.out_last_y + MACRO_REVEXT_DEADDOOR, 5U));

      /* Transition: '<S7>:191' */
    } else {
      /* Transition: '<S7>:190' */
      Fv_LowRev = 0;
    }
  }

  /* End of Chart: '<S4>/DiffCalc' */

  /* Saturate: '<S4>/Saturation' incorporates:
   *  DataStoreWrite: '<S4>/Data Store Write'
   */
  /* Transition: '<S7>:230' */
  if (Fv_LowRev > 409600) {
    Fv_LowRev = 409600;
  } else {
    if (Fv_LowRev < (-409600)) {
      Fv_LowRev = -409600;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Product: '<S4>/Product5' incorporates:
   *  Constant: '<S4>/Constant7'
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  DataStoreWrite: '<S4>/Data Store Write1'
   */
  Fv_LowRev_rpm = (Int16)asr_s32(Fv_LowRev * ((Int32)((UInt16)MACRO_RAD2RPM)),
    14U);

  /* UnaryMinus: '<S4>/Unary Minus' incorporates:
   *  Constant: '<S4>/Constant2'
   *  DataTypeConversion: '<S4>/conv3'
   */
  Switch_idx_0 = -((Int32)((Int16)MACRO_REVEXT_LOWMAX));

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S4>/Constant'
   *  DataStoreRead: '<S4>/Data Store Read3'
   *  DataTypeConversion: '<S4>/conv2'
   *  RelationalOperator: '<S8>/LowerRelop1'
   *  RelationalOperator: '<S8>/UpperRelop'
   *  Switch: '<S8>/Switch'
   */
  if (Fv_dRotorAng_rpm > ((Int32)((Int16)MACRO_REVEXT_LOWMAX))) {
    /* DataTypeConversion: '<S4>/conv1' */
    Fv_MotorRev_rpm = ((Int16)MACRO_REVEXT_LOWMAX);
  } else if (Fv_dRotorAng_rpm < Switch_idx_0) {
    /* Switch: '<S8>/Switch' incorporates:
     *  DataTypeConversion: '<S4>/conv1'
     */
    Fv_MotorRev_rpm = (Int16)Switch_idx_0;
  } else {
    /* DataTypeConversion: '<S4>/conv1' incorporates:
     *  Switch: '<S8>/Switch'
     */
    Fv_MotorRev_rpm = (Int16)Fv_dRotorAng_rpm;
  }

  /* End of Switch: '<S8>/Switch2' */
}

/* Output and update for atomic system: '<S5>/EpsAngleConv_CAN' */
#if MACRO_STEERANGLE_SELECT == 1

void EPSADC_EpsAngleConv_CAN(void)
{
  Int32 rtb_Sign_ovfi;
  Int32 rtb_Abs_hzj1;

  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S9>/Constant10'
   *  Constant: '<S9>/Constant2'
   *  DataStoreRead: '<S9>/Data Store Read'
   *  Product: '<S9>/Product'
   */
  rtb_Abs_hzj1 = ((Int32)((UInt32)(((UInt32)CAN_StrAng) * ((UInt32)
    Cal_StrAng_Scale)))) - ((Int32)Cal_StrAng_Offset);

  /* Signum: '<S9>/Sign' */
  if (rtb_Abs_hzj1 < 0) {
    rtb_Sign_ovfi = -1;
  } else {
    rtb_Sign_ovfi = (rtb_Abs_hzj1 > 0);
  }

  /* End of Signum: '<S9>/Sign' */

  /* Abs: '<S9>/Abs' */
  if (rtb_Abs_hzj1 < 0) {
    rtb_Abs_hzj1 = -rtb_Abs_hzj1;
  }

  /* End of Abs: '<S9>/Abs' */

  /* MinMax: '<S9>/MinMax' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (rtb_Abs_hzj1 < ((Int32)Cal_AN_MaxAngle)) {
  } else {
    rtb_Abs_hzj1 = (Int32)Cal_AN_MaxAngle;
  }

  /* End of MinMax: '<S9>/MinMax' */

  /* Product: '<S9>/Product1' */
  Tv_StrAng_Raw = (Int16)(rtb_Abs_hzj1 * rtb_Sign_ovfi);

  /* DataStoreWrite: '<S9>/Data Store Write' */
  Fv_StrAng_Raw = Tv_StrAng_Raw;
}

#endif

/* Output and update for atomic system: '<S10>/EpsAngleConv_AngState' */
#if MACRO_STEERANGLE_SELECT == 0

void EPSADC_EpsAngleConv_AngState(void)
{
  Int16 u0;
  Bool stsUpTemp = 0;
  /* Product: '<S11>/Divide1' incorporates:
   *  Constant: '<S11>/Constant10'
   *  Constant: '<S11>/Constant11'
   *  Gain: '<S11>/Gain3'
   *  Inport: '<Root>/IOC_AngpDuty'
   *  Sum: '<S11>/Subtract2'
   */
  u0 = (Int16)((((Int32)((Int16)MACRO_ANGLEDECODE_EXTENTP)) * (((Int32)
    IOC_AngpDuty) - ((Int32)((UInt16)MACRO_ANGLEDECODE_ZERORIFT)))) / ((Int32)
    ((UInt16)MACRO_ANGLEDECODE_DUTYRANGE)));

  /* MinMax: '<S11>/Min' incorporates:
   *  Constant: '<S11>/Constant14'
   */
  if (u0 > 0) {
    EPSADCrtDW.EpsAngleConv_Sensor.pang = u0;
  } else {
    EPSADCrtDW.EpsAngleConv_Sensor.pang = 0;
  }

  /* End of MinMax: '<S11>/Min' */

  /* Product: '<S11>/Divide2' incorporates:
   *  Constant: '<S11>/Constant10'
   *  Constant: '<S11>/Constant11'
   *  Gain: '<S11>/Gain4'
   *  Inport: '<Root>/IOC_AngsDuty'
   *  Sum: '<S11>/Subtract1'
   */
  u0 = (Int16)((((Int32)((Int16)MACRO_ANGLEDECODE_EXTENTS)) * (((Int32)
    IOC_AngsDuty) - ((Int32)((UInt16)MACRO_ANGLEDECODE_ZERORIFT)))) / ((Int32)
    ((UInt16)MACRO_ANGLEDECODE_DUTYRANGE)));

  /* MinMax: '<S11>/Min1' incorporates:
   *  Constant: '<S11>/Constant14'
   */
  if (0 > u0) {
    EPSADCrtDW.EpsAngleConv_Sensor.sang = 0;
  } else {
    EPSADCrtDW.EpsAngleConv_Sensor.sang = u0;
  }

  /* End of MinMax: '<S11>/Min1' */

  /* Logic: '<S11>/apst' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/Constant5'
   *  Inport: '<Root>/IOC_AngpDuty'
   *  Inport: '<Root>/IOC_AngpFrez'
   *  RelationalOperator: '<S11>/GE0'
   *  RelationalOperator: '<S11>/GE1'
   *  RelationalOperator: '<S11>/GE2'
   *  RelationalOperator: '<S11>/GE3'
   */
  EPSADCrtDW.EpsAngleConv_Sensor.stap = ((((IOC_AngpDuty <= ((UInt16)
    MACRO_ANGLE_DUTYMAX)) && (IOC_AngpDuty >= ((UInt16)MACRO_ANGLE_DUTYMIN))) &&
    (IOC_AngpFrez <= ((UInt16)MACRO_ANGLE_FRZPMAX))) && (IOC_AngpFrez >=
    ((UInt16)MACRO_ANGLE_FRZPMIN)));

  /* Logic: '<S11>/asst' incorporates:
   *  Constant: '<S11>/Constant6'
   *  Constant: '<S11>/Constant7'
   *  Constant: '<S11>/Constant8'
   *  Constant: '<S11>/Constant9'
   *  Inport: '<Root>/IOC_AngsDuty'
   *  Inport: '<Root>/IOC_AngsFrez'
   *  RelationalOperator: '<S11>/GE4'
   *  RelationalOperator: '<S11>/GE5'
   *  RelationalOperator: '<S11>/GE6'
   *  RelationalOperator: '<S11>/GE7'
   */
  EPSADCrtDW.EpsAngleConv_Sensor.stas = ((((IOC_AngsDuty <= ((UInt16)
    MACRO_ANGLE_DUTYMAX)) && (IOC_AngsDuty >= ((UInt16)MACRO_ANGLE_DUTYMIN))) &&
    (IOC_AngsFrez <= ((UInt16)MACRO_ANGLE_FRZSMAX))) && (IOC_AngsFrez >=
    ((UInt16)MACRO_ANGLE_FRZSMIN)));

  /* Logic: '<S11>/apst1' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S11>/Constant13'
   *  Constant: '<S16>/Constant'
   *  DataStoreRead: '<S11>/Data Store Read'
   *  DataStoreRead: '<S11>/Data Store Read1'
   *  DataStoreRead: '<S11>/Data Store Read2'
   *  RelationalOperator: '<S11>/GE10'
   *  RelationalOperator: '<S11>/GE8'
   *  RelationalOperator: '<S11>/GE9'
   *  RelationalOperator: '<S16>/Compare'
   */
  stsUpTemp = ((((Fv_SensorPowerTorque <= ((UInt16)
    MACRO_STRTRQ_POWERMAX)) && (Fv_SensorPowerTorque >= ((UInt16)
    MACRO_STRTRQ_POWERMIN))) && (Fv_SysPower >= ((Int16)MACRO_ANGLE_INIT_VOL))) &&
    (SysTaskTrqSplPending == true));

  if(stsUpTemp == 0)
  {
    if(Fv_AngleConvRecoverCnt < MACRO_ANGLEDECODE_PWRCNT)
    {
      Fv_AngleConvRecoverCnt++;
    }
    else
    {
      EPSADCrtDW.EpsAngleConv_Sensor.stsup = 0;//todo
    }
  }
  else
  {
    EPSADCrtDW.EpsAngleConv_Sensor.stsup = 1;
    Fv_AngleConvRecoverCnt = 1;
  }
}

#endif

/* Output and update for action system: '<S12>/anglemix' */
#if MACRO_STEERANGLE_SELECT == 0

void EPSADC_anglemix(void)
{
  Int16 hella_mode;
  Int32 rtb_hella_eigen;
  Int32 tmp;

  /* Outputs for Atomic SubSystem: '<S19>/anglemix_test' */
  /* Product: '<S21>/Product1' incorporates:
   *  Constant: '<S21>/Constant13'
   *  Sum: '<S21>/Subtract4'
   */
  rtb_hella_eigen = ((Int32)((UInt16)10U)) * (((Int32)
    EPSADCrtDW.EpsAngleConv_Sensor.pang) - ((Int32)
    EPSADCrtDW.EpsAngleConv_Sensor.sang));

  /* Chart: '<S21>/anglecof' */
  /* Gateway: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/anglecof */
  /* During: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/anglecof */
  /* Entry Internal: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/anglecof */
  /* Transition: '<S22>:101' */
  if (rtb_hella_eigen >= 0) {
    /* Transition: '<S22>:103' */
    /* Transition: '<S22>:105' */
    hella_mode = (Int16)(rtb_hella_eigen - ((rtb_hella_eigen /
      MACRO_ANGLEDECODE_BASICM10) * MACRO_ANGLEDECODE_BASICM10));
  } else {
    /* Transition: '<S22>:108' */
    hella_mode = (Int16)((MACRO_ANGLEDECODE_BASICM10 + rtb_hella_eigen) +
                         (((-rtb_hella_eigen) / MACRO_ANGLEDECODE_BASICM10) *
                          MACRO_ANGLEDECODE_BASICM10));

    /* Transition: '<S22>:109' */
  }

  /* Transition: '<S22>:12' */
  if ((((Int32)hella_mode) > MACRO_ANGLEDECODE_BASICM1) && (((Int32)hella_mode) <=
       MACRO_ANGLEDECODE_BASICM3)) {
    /* Transition: '<S22>:35' */
    /* Transition: '<S22>:38' */
    hella_mode = 3;

    /* Transition: '<S22>:80' */
    /* Transition: '<S22>:88' */
    /* Transition: '<S22>:89' */
    /* Transition: '<S22>:90' */
    /* Transition: '<S22>:93' */
  } else {
    /* Transition: '<S22>:58' */
    if ((((Int32)hella_mode) > MACRO_ANGLEDECODE_BASICM3) && (((Int32)hella_mode)
         <= MACRO_ANGLEDECODE_BASICM5)) {
      /* Transition: '<S22>:60' */
      /* Transition: '<S22>:62' */
      hella_mode = 1;

      /* Transition: '<S22>:82' */
      /* Transition: '<S22>:89' */
      /* Transition: '<S22>:90' */
      /* Transition: '<S22>:93' */
    } else {
      /* Transition: '<S22>:64' */
      if ((((Int32)hella_mode) > MACRO_ANGLEDECODE_BASICM5) && (((Int32)
            hella_mode) <= MACRO_ANGLEDECODE_BASICM7)) {
        /* Transition: '<S22>:66' */
        /* Transition: '<S22>:68' */
        hella_mode = 4;

        /* Transition: '<S22>:84' */
        /* Transition: '<S22>:90' */
        /* Transition: '<S22>:93' */
      } else {
        /* Transition: '<S22>:70' */
        if ((((Int32)hella_mode) > MACRO_ANGLEDECODE_BASICM7) && (((Int32)
              hella_mode) <= MACRO_ANGLEDECODE_BASICM9)) {
          /* Transition: '<S22>:72' */
          /* Transition: '<S22>:111' */
          hella_mode = 2;

          /* Transition: '<S22>:86' */
          /* Transition: '<S22>:93' */
        } else {
          /* Transition: '<S22>:76' */
          hella_mode = 0;

          /* Transition: '<S22>:92' */
        }
      }
    }
  }

  /* End of Chart: '<S21>/anglecof' */

  /* Sum: '<S21>/Add' incorporates:
   *  Constant: '<S21>/Constant12'
   *  Product: '<S21>/Product'
   */
  rtb_hella_eigen = (((Int32)((Int16)MACRO_ANGLEDECODE_EXTENTS)) * ((Int32)
    hella_mode)) + ((Int32)EPSADCrtDW.EpsAngleConv_Sensor.sang);

  /* Chart: '<S21>/angoffset' */
  /* Gateway: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/angoffset */
  /* During: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/angoffset */
  /* Entry Internal: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/angoffset */
  /* Transition: '<S23>:2' */
  tmp = ((Int32)ANGLE_ZERO_CALIB) - rtb_hella_eigen;
  if (tmp > ((Int32)((Int16)MACRO_ANGLEDECODE_HALF))) {
    /* Transition: '<S23>:8' */
    /* Transition: '<S23>:14' */
    Fv_StrAngOffset = (Int16)(ANGLE_ZERO_CALIB - ((Int16)MACRO_ANGLEDECODE_MAX));

    /* Transition: '<S23>:78' */
    /* Transition: '<S23>:87' */
    /* Transition: '<S23>:101' */
  } else {
    /* Transition: '<S23>:12' */
    if (tmp < (-((Int32)((Int16)MACRO_ANGLEDECODE_HALF)))) {
      /* Transition: '<S23>:35' */
      /* Transition: '<S23>:38' */
      Fv_StrAngOffset = (Int16)(ANGLE_ZERO_CALIB + ((Int16)MACRO_ANGLEDECODE_MAX));

      /* Transition: '<S23>:80' */
      /* Transition: '<S23>:101' */
    } else {
      /* Transition: '<S23>:98' */
      Fv_StrAngOffset = ANGLE_ZERO_CALIB;

      /* Transition: '<S23>:100' */
    }
  }

  /* End of Chart: '<S21>/angoffset' */

  /* Product: '<S21>/Divide2' incorporates:
   *  DataStoreWrite: '<S21>/Data Store Write3'
   *  DataTypeConversion: '<S21>/conv1'
   */
  Fv_ConvStrAngOffset = (Fv_StrAngOffset * 16) / 10;

  /* Sum: '<S21>/Subtract1' */
  EPSADCrtDW.EpsAngleConv_Sensor.anginit = Fv_StrAng_Psum - rtb_hella_eigen;

  /* End of Outputs for SubSystem: '<S19>/anglemix_test' */

  /* SignalConversion: '<S19>/OutportBufferForangd' */
  EPSADCrtDW.EpsAngleConv_Sensor.mergec = rtb_hella_eigen;
}

#endif

/* Output and update for atomic system: '<S24>/calc_anglecheck' */
#if MACRO_STEERANGLE_SELECT == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

void EPSADC_calc_anglecheck(void)
{
  Int32 rtb_Subtract2_kohz;
  Int16 angcheck_diff;

  /* Sum: '<S26>/Subtract2' incorporates:
   *  DataStoreRead: '<S26>/Data Store Read'
   *  DataStoreRead: '<S26>/Data Store Read1'
   */
  rtb_Subtract2_kohz = ((Int32)Fv_BasicSteerAngle) - Fv_ConvStrAng;

  /* Saturate: '<S26>/Saturation' */
  if (rtb_Subtract2_kohz >= ((Int32)32000)) {
    angcheck_diff = 32000;
  } else if (rtb_Subtract2_kohz <= ((Int32)(-32000))) {
    angcheck_diff = (-32000);
  } else {
    angcheck_diff = (Int16)rtb_Subtract2_kohz;
  }

  /* End of Saturate: '<S26>/Saturation' */

  /* Chart: '<S26>/anglecheck' */
  /* Gateway: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck/calc_anglecheck/anglecheck */
  /* During: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck/calc_anglecheck/anglecheck */
  if (((UInt32)
       EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.is_active_c15_EPSADC)
      == 0U) {
    /* Entry: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck/calc_anglecheck/anglecheck */
    EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.is_active_c15_EPSADC
      = 1;

    /* Entry Internal: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck/calc_anglecheck/anglecheck */
    /* Transition: '<S28>:4' */
    EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.is_c15_EPSADC
      = EPSADC_IN_wait;
  } else if (((UInt32)
              EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.is_c15_EPSADC)
             == EPSADC_IN_calculation) {
    /* During 'calculation': '<S28>:5' */
    if (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.step) != 2) {
      /* Transition: '<S28>:7' */
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.is_c15_EPSADC
        = EPSADC_IN_wait;
    } else {
      /* Transition: '<S28>:9' */
      if (((Int32)
           EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_delay_cnt) <
          2000) {
        /* Transition: '<S28>:11' */
        /* Transition: '<S28>:13' */
        EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_delay_cnt =
          (UInt16)((Int32)(((Int32)
                            EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_delay_cnt)
                           + 1));
        EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum_cnt = 0U;
        EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.calc_valid_flag
          = false;
        EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum = 0;
        EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr_init = 0;
        EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr = 0;
      } else {
        /* Transition: '<S28>:15' */
        if (!EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.calc_valid_flag)
        {
          /* Transition: '<S28>:18' */
          /* Transition: '<S28>:20' */
          EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr_init = 0;
          EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr = 0;
          if (((Int32)
               EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum_cnt)
              < 8) {
            /* Transition: '<S28>:22' */
            /* Transition: '<S28>:24' */
            EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum_cnt =
              (UInt16)((Int32)(((Int32)
                                EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum_cnt)
                               + 1));
            EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum +=
              (Int32)angcheck_diff;
          } else {
            /* Transition: '<S28>:26' */
            EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr_init =
              EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum / 8;
            EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.calc_valid_flag
              = true;

            /* Transition: '<S28>:27' */
          }
        } else {
          /* Transition: '<S28>:29' */
          EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr = ((Int32)
            angcheck_diff) -
            EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr_init;

          /* Transition: '<S28>:30' */
          /* Transition: '<S28>:27' */
        }

        /* Transition: '<S28>:31' */
      }
    }
  } else {
    /* During 'wait': '<S28>:3' */
    if (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.step) == 2) {
      /* Transition: '<S28>:6' */
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.is_c15_EPSADC
        = EPSADC_IN_calculation;

      /* Entry 'calculation': '<S28>:5' */
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_delay_cnt = 0U;
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum_cnt = 0U;
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.bitsForTID0.calc_valid_flag
        = false;
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_sum = 0;
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr_init = 0;
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr = 0;
    } else {
      EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr = 0;
    }
  }

  /* End of Chart: '<S26>/anglecheck' */

  /* DataStoreWrite: '<S26>/Data Store Write1' */
  Fv_StrAngRtr_Diff =
    EPSADCrtDW.EpsAngleConv_Sensor.calc_anglecheck_k0uh.calc_rtr;
}

#endif

/* Output and update for atomic system: '<S24>/calc_anglecheck_zero' */
#if MACRO_STEERANGLE_SELECT == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0

void EPSADC_calc_anglecheck_zero(void)
{
  /* DataStoreWrite: '<S27>/Data Store Write1' incorporates:
   *  Constant: '<S27>/Constant'
   */
  Fv_StrAngRtr_Diff = 0;
}

#endif

/* Output and update for atomic system: '<S20>/calc_strangle' */
#if MACRO_STEERANGLE_SELECT == 0

void EPSADC_calc_strangle(void)
{
  Int32 rtb_conv2_chws;

  /* UnaryMinus: '<S25>/Unary Minus' incorporates:
   *  Constant: '<S25>/Constant'
   *  DataTypeConversion: '<S25>/conv3'
   */
  rtb_conv2_chws = -((Int32)((Int16)MACRO_ANGLEDECODE_LIMIT));

  /* Switch: '<S29>/Switch2' incorporates:
   *  Constant: '<S25>/Constant'
   *  DataTypeConversion: '<S25>/conv3'
   *  RelationalOperator: '<S29>/LowerRelop1'
   *  RelationalOperator: '<S29>/UpperRelop'
   *  Switch: '<S29>/Switch'
   */
  if (EPSADCrtDW.EpsAngleConv_Sensor.mergec > ((Int32)((Int16)
        MACRO_ANGLEDECODE_LIMIT))) {
    /* DataTypeConversion: '<S25>/conv1' */
    Tv_StrAng = ((Int16)MACRO_ANGLEDECODE_LIMIT);
  } else if (EPSADCrtDW.EpsAngleConv_Sensor.mergec < rtb_conv2_chws) {
    /* Switch: '<S29>/Switch' incorporates:
     *  DataTypeConversion: '<S25>/conv1'
     */
    Tv_StrAng = (Int16)rtb_conv2_chws;
  } else {
    /* DataTypeConversion: '<S25>/conv1' incorporates:
     *  Switch: '<S29>/Switch'
     */
    Tv_StrAng = (Int16)EPSADCrtDW.EpsAngleConv_Sensor.mergec;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* DataStoreWrite: '<S25>/Data Store Write1' */
  Fv_StrAng = Tv_StrAng;

  /* Product: '<S25>/Divide1' incorporates:
   *  DataStoreWrite: '<S25>/Data Store Write2'
   *  DataTypeConversion: '<S25>/conv2'
   */
  Fv_ConvStrAng = (Tv_StrAng * 16) / 10;
}

#endif

/* Output and update for atomic system: '<S10>/EpsAngleConv_AngleDecode' */
#if MACRO_STEERANGLE_SELECT == 0

void EPSADC_EpsAngleConv_AngleDecode(void)
{
  /* SwitchCase: '<S12>/SwitchCase' */
  switch (EPSADCrtDW.EpsAngleConv_Sensor.step) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S12>/anglemix' incorporates:
     *  ActionPort: '<S19>/ActionPort'
     */
    EPSADC_anglemix();

    /* End of Outputs for SubSystem: '<S12>/anglemix' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S12>/anglefollow' incorporates:
     *  ActionPort: '<S17>/ActionPort'
     */
    /* Sum: '<S17>/Subtract1' */
    EPSADCrtDW.EpsAngleConv_Sensor.mergec = Fv_StrAng_Psum -
      EPSADCrtDW.EpsAngleConv_Sensor.anginit;

    /* End of Outputs for SubSystem: '<S12>/anglefollow' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S12>/angleinit' incorporates:
     *  ActionPort: '<S18>/ActionPort'
     */
    /* SignalConversion: '<S18>/OutportBufferForangz' incorporates:
     *  Constant: '<S18>/Constant'
     */
    EPSADCrtDW.EpsAngleConv_Sensor.mergec = 0;

    /* End of Outputs for SubSystem: '<S12>/angleinit' */
    break;
  }

  /* End of SwitchCase: '<S12>/SwitchCase' */

  /* Outputs for Atomic SubSystem: '<S20>/calc_strangle' */
  EPSADC_calc_strangle();

  /* End of Outputs for SubSystem: '<S20>/calc_strangle' */

  /* Outputs for Atomic SubSystem: '<S20>/calc_anglecheck' */
#if STRANG_RTRANG_DIFF_TYPEMODE == 1

  EPSADC_calc_anglecheck();

#elif STRANG_RTRANG_DIFF_TYPEMODE == 0

  EPSADC_calc_anglecheck_zero();

#endif

  /* End of Outputs for SubSystem: '<S20>/calc_anglecheck' */
}

#endif

/* Output and update for atomic system: '<S10>/EpsAngleConv_HellaRevCalc' */
#if MACRO_STEERANGLE_SELECT == 0

void EPSAD_EpsAngleConv_HellaRevCalc(void)
{
  Int32 sumout;
  Int32 rtb_Diff;
  Int32 diffout;

  /* Outputs for Atomic SubSystem: '<S13>/HellaRevCalc_diff' */
  /* Product: '<S30>/Divide1' incorporates:
   *  DataTypeConversion: '<S30>/conv3'
   */
  Fv_AngleDecodeP = (Int16)((EPSADCrtDW.EpsAngleConv_Sensor.pang * 16) / 10);

  /* Chart: '<S30>/anglepsum' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  Delay: '<S30>/Delay'
   *  Logic: '<S30>/AND'
   *  RelationalOperator: '<S32>/Compare'
   *  RelationalOperator: '<S33>/Compare'
   */
  /* Gateway: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_diff/anglepsum */
  /* During: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_diff/anglepsum */
  /* Entry Internal: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_diff/anglepsum */
  /* Transition: '<S34>:116' */
  if ((EPSADCrtDW.EpsAngleConv_Sensor.stsup == true) &&
      (EPSADCrtDW.EpsAngleConv_Sensor.Delay_DSTATE_krih == false)) {
    /* Transition: '<S34>:115' */
    /* Transition: '<S34>:2' */
    EPSADCrtDW.EpsAngleConv_Sensor.panglast = Fv_AngleDecodeP;
    EPSADCrtDW.EpsAngleConv_Sensor.sumoutlast = (Int32)Fv_AngleDecodeP;
    EPSADCrtDW.EpsAngleConv_Sensor.modout = 0;
  } else {
    /* Transition: '<S34>:118' */
    /* Transition: '<S34>:119' */
  }

  diffout = ((Int32)Fv_AngleDecodeP) - ((Int32)
    EPSADCrtDW.EpsAngleConv_Sensor.panglast);
  if (diffout > ((Int32)((Int16)MACRO_ANGLE_MAXP_2))) {
    /* Transition: '<S34>:8' */
    /* Transition: '<S34>:14' */
    EPSADCrtDW.EpsAngleConv_Sensor.modout -= (Int32)((Int16)MACRO_ANGLE_MAXP);

    /* Transition: '<S34>:78' */
    /* Transition: '<S34>:103' */
  } else {
    /* Transition: '<S34>:12' */
    if (diffout < (-((Int32)((Int16)MACRO_ANGLE_MAXP_2)))) {
      /* Transition: '<S34>:35' */
      /* Transition: '<S34>:98' */
      EPSADCrtDW.EpsAngleConv_Sensor.modout += (Int32)((Int16)MACRO_ANGLE_MAXP);
    } else {
      /* Transition: '<S34>:100' */
      /* Transition: '<S34>:102' */
    }

    /* Transition: '<S34>:105' */
  }

  /* Transition: '<S34>:108' */
  sumout = EPSADCrtDW.EpsAngleConv_Sensor.modout + ((Int32)Fv_AngleDecodeP);
  diffout = sumout - EPSADCrtDW.EpsAngleConv_Sensor.sumoutlast;
  EPSADCrtDW.EpsAngleConv_Sensor.panglast = Fv_AngleDecodeP;
  EPSADCrtDW.EpsAngleConv_Sensor.sumoutlast = sumout;

  /* SignalConversion: '<S30>/Signal Conversion' incorporates:
   *  Chart: '<S30>/anglepsum'
   */
  Fv_StrAng_Psum = (asr_s32(sumout * 10, 4U));

  /* Update for Delay: '<S30>/Delay' */
  EPSADCrtDW.EpsAngleConv_Sensor.Delay_DSTATE_krih =
    EPSADCrtDW.EpsAngleConv_Sensor.stsup;

  /* End of Outputs for SubSystem: '<S13>/HellaRevCalc_diff' */

  /* Outputs for Atomic SubSystem: '<S13>/HellaRevCalc_rev' */
  /* Saturate: '<S31>/Saturation1' */
  if (diffout > 160) {
    diffout = 160;
  } else {
    if (diffout < (-160)) {
      diffout = (-160);
    }
  }

  /* End of Saturate: '<S31>/Saturation1' */

  /* Product: '<S31>/Product1' */
  diffout *= 1000;

  /* Gain: '<S31>/Gain2' incorporates:
   *  Delay: '<S31>/Delay'
   *  Delay: '<S31>/Delay1'
   *  Gain: '<S31>/Gain'
   *  Sum: '<S31>/Subtract1'
   */
  EPSADCrtDW.EpsAngleConv_Sensor.Delay_DSTATE = asr_s32((diffout +
    EPSADCrtDW.EpsAngleConv_Sensor.Delay1_DSTATE) + (30 *
    EPSADCrtDW.EpsAngleConv_Sensor.Delay_DSTATE), 5U);

  /* Saturate: '<S31>/Saturation2' incorporates:
   *  Delay: '<S31>/Delay'
   */
  if (EPSADCrtDW.EpsAngleConv_Sensor.Delay_DSTATE > 32000) {
    rtb_Diff = 32000;
  } else if (EPSADCrtDW.EpsAngleConv_Sensor.Delay_DSTATE < (-32000)) {
    rtb_Diff = (-32000);
  } else {
    rtb_Diff = EPSADCrtDW.EpsAngleConv_Sensor.Delay_DSTATE;
  }

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S31>/Constant1'
   *  RelationalOperator: '<S35>/u_GTE_up'
   *  Saturate: '<S31>/Saturation2'
   */
  if (rtb_Diff >= MACRO_ANGLE_DEADREV) {
    sumout = MACRO_ANGLE_DEADREV;
  } else {
    /* UnaryMinus: '<S31>/Unary Minus' incorporates:
     *  Constant: '<S31>/Constant3'
     */
    sumout = -MACRO_ANGLE_DEADREV;

    /* Switch: '<S35>/Switch1' incorporates:
     *  RelationalOperator: '<S35>/u_GT_lo'
     */
    if (rtb_Diff > sumout) {
      sumout = rtb_Diff;
    }

    /* End of Switch: '<S35>/Switch1' */
  }

  /* End of Switch: '<S35>/Switch' */

  /* Sum: '<S35>/Diff' incorporates:
   *  Saturate: '<S31>/Saturation2'
   */
  rtb_Diff -= sumout;

  /* UnaryMinus: '<S31>/Unary Minus1' incorporates:
   *  Constant: '<S31>/Constant5'
   *  DataTypeConversion: '<S31>/Data Type Conversion1'
   */
  sumout = -((Int32)Cal_AN_MaxdAngle);

  /* Switch: '<S36>/Switch2' incorporates:
   *  Constant: '<S31>/Constant4'
   *  DataTypeConversion: '<S31>/Data Type Conversion'
   *  RelationalOperator: '<S36>/LowerRelop1'
   *  RelationalOperator: '<S36>/UpperRelop'
   *  Switch: '<S36>/Switch'
   */
  if (rtb_Diff > ((Int32)Cal_AN_MaxdAngle)) {
    /* DataTypeConversion: '<S31>/Data Type Conversion2' */
    Tv_HellaFirlterRev = Cal_AN_MaxdAngle;
  } else if (rtb_Diff < sumout) {
    /* Switch: '<S36>/Switch' incorporates:
     *  DataTypeConversion: '<S31>/Data Type Conversion2'
     */
    Tv_HellaFirlterRev = (Int16)sumout;
  } else {
    /* DataTypeConversion: '<S31>/Data Type Conversion2' incorporates:
     *  Switch: '<S36>/Switch'
     */
    Tv_HellaFirlterRev = (Int16)rtb_Diff;
  }

  /* End of Switch: '<S36>/Switch2' */

  /* DataStoreWrite: '<S31>/Data Store Write' */
  Fv_HellaFirlterRev = Tv_HellaFirlterRev;

  /* Update for Delay: '<S31>/Delay1' */
  EPSADCrtDW.EpsAngleConv_Sensor.Delay1_DSTATE = diffout;

  /* End of Outputs for SubSystem: '<S13>/HellaRevCalc_rev' */
}

#endif

/* Output and update for atomic system: '<S10>/EpsAngleConv_MixFollowState' */
#if MACRO_STEERANGLE_SELECT == 0

void EPS_EpsAngleConv_MixFollowState(void)
{
  /* Chart: '<S14>/angle_shedule' */
  /* Gateway: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_MixFollowState/angle_shedule */
  /* During: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_MixFollowState/angle_shedule */
  if (((UInt32)EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_active_c9_EPSADC) ==
      0U) {
    /* Entry: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_MixFollowState/angle_shedule */
    EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_active_c9_EPSADC = 1;

    /* Entry Internal: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_MixFollowState/angle_shedule */
    /* Transition: '<S37>:116' */
    EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_c9_EPSADC = EPSADC_IN_Default;

    /* Entry 'Default': '<S37>:257' */
    EPSADCrtDW.EpsAngleConv_Sensor.step = 0U;
    SysTaskTrqSigPending = false;
    Fv_AngleReadyFlag = HELLA_STS_Default;
    EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt = ((UInt16)
      MACRO_ANGLE_DEFAULT_DELAYTIME);
  } else if (((UInt32)EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_c9_EPSADC) ==
             EPSADC_IN_Decode) {
    /* During 'Decode': '<S37>:118' */
    if (!EPSADCrtDW.EpsAngleConv_Sensor.stsup) {
      /* Transition: '<S37>:161' */
      /* Exit Internal 'Decode': '<S37>:118' */
      EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_Decode =
        EPSADC_IN_NO_ACTIVE_CHILD_fqrs;
      EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_c9_EPSADC =
        EPSADC_IN_Default;

      /* Entry 'Default': '<S37>:257' */
      EPSADCrtDW.EpsAngleConv_Sensor.step = 0U;
      SysTaskTrqSigPending = false;
      Fv_AngleReadyFlag = HELLA_STS_Default;
      EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt = ((UInt16)
        MACRO_ANGLE_DEFAULT_DELAYTIME);
    } else {
      SysTaskAngDutyCaclPending = true;
      if (((UInt32)EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_Decode) ==
          EPSADC_IN_Follow) {
        /* During 'Follow': '<S37>:135' */
        EPSADCrtDW.EpsAngleConv_Sensor.step = 2U;
        Fv_AngleReadyFlag = HELLA_STS_Decode;

        /* Transition: '<S37>:211' */
        if (!EPSADCrtDW.EpsAngleConv_Sensor.stap) {
          /* Transition: '<S37>:227' */
          if (EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt < ((UInt16)
               MACRO_ANGLE_CHECKTIME)) {
            /* Transition: '<S37>:216' */
            /* Transition: '<S37>:213' */
            EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt = (UInt16)((Int32)
              (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt) + 1));

            /* Transition: '<S37>:254' */
          } else {
            /* Transition: '<S37>:245' */
            Fv_AngleMidValidFlag = ANGLE_STS_Error;
            Fv_AngleReadyFlag = HELLA_STS_Error;
          }

          /* Transition: '<S37>:207' */
          SysTaskTrqSigPending = false;
        } else {
          /* Transition: '<S37>:247' */
          if (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt) > 1) {
            /* Transition: '<S37>:223' */
            /* Transition: '<S37>:219' */
            EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt = (UInt16)((Int32)
              (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt) - 2));

            /* Transition: '<S37>:239' */
          } else {
            /* Transition: '<S37>:243' */
            SysTaskTrqSigPending = true;
            EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt = 0U;
          }

          /* Transition: '<S37>:240' */
        }
      } else {
        /* During 'Mix': '<S37>:133' */
        if (EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.jump) {
          /* Transition: '<S37>:255' */
          EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_Decode =
            EPSADC_IN_Follow;

          /* Entry 'Follow': '<S37>:135' */
          EPSADCrtDW.EpsAngleConv_Sensor.follow_err_cnt = 0U;
        } else {
          EPSADCrtDW.EpsAngleConv_Sensor.step = 1U;
          Fv_AngleReadyFlag = HELLA_STS_Mix;

          /* Transition: '<S37>:252' */
          if ((Tv_HellaFirlterRev < ((Int16)MACRO_ANGLE_LIMITPREV)) &&
              (Tv_HellaFirlterRev > (-((Int16)MACRO_ANGLE_LIMITPREV)))) {
            /* Transition: '<S37>:249' */
            if (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.decode_cnt) < ((Int32)
                 ((Int16)MACRO_ANGLEDECODE_MIXTIMER))) {
              /* Transition: '<S37>:149' */
              /* Transition: '<S37>:244' */
              EPSADCrtDW.EpsAngleConv_Sensor.decode_cnt = (UInt16)((Int32)
                (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.decode_cnt) + 1));
            } else {
              /* Transition: '<S37>:152' */
              EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.jump = true;

              /* Transition: '<S37>:246' */
            }
          } else {
            /* Transition: '<S37>:177' */
            EPSADCrtDW.EpsAngleConv_Sensor.decode_cnt = 0U;

            /* Transition: '<S37>:242' */
            /* Transition: '<S37>:246' */
          }

          if ((!EPSADCrtDW.EpsAngleConv_Sensor.stap) ||
              (!EPSADCrtDW.EpsAngleConv_Sensor.stas)) {
            /* Transition: '<S37>:186' */
            if (EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt < ((UInt16)
                 MACRO_ANGLE_CHECKTIME)) {
              /* Transition: '<S37>:188' */
              /* Transition: '<S37>:190' */
              EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt = (UInt16)((Int32)
                (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt) + 1));
            } else {
              /* Transition: '<S37>:192' */
              Fv_AngleMidValidFlag = ANGLE_STS_Error;
              Fv_AngleReadyFlag = HELLA_STS_Error;

              /* Transition: '<S37>:193' */
            }

            /* Transition: '<S37>:195' */
            SysTaskTrqSigPending = false;
          } else {
            /* Transition: '<S37>:197' */
            if (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt) > 1) {
              /* Transition: '<S37>:199' */
              /* Transition: '<S37>:200' */
              EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt = (UInt16)((Int32)
                (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt) - 2));
            } else {
              /* Transition: '<S37>:203' */
              SysTaskTrqSigPending = true;
              EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt = 0U;

              /* Transition: '<S37>:204' */
            }

            /* Transition: '<S37>:205' */
          }
        }
      }
    }
  } else {
    /* During 'Default': '<S37>:257' */
    if ((EPSADCrtDW.EpsAngleConv_Sensor.stsup) && (((Int32)
          EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt) == 0)) {
      /* Transition: '<S37>:253' */
      EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_c9_EPSADC = EPSADC_IN_Decode;

      /* Entry 'Decode': '<S37>:118' */
      EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.jump = false;

      /* Entry Internal 'Decode': '<S37>:118' */
      /* Transition: '<S37>:134' */
      EPSADCrtDW.EpsAngleConv_Sensor.bitsForTID0.is_Decode = EPSADC_IN_Mix;

      /* Entry 'Mix': '<S37>:133' */
      EPSADCrtDW.EpsAngleConv_Sensor.mix_err_cnt = 0U;
    } else {
      /* Transition: '<S37>:262' */
      if (EPSADCrtDW.EpsAngleConv_Sensor.stsup) {
        /* Transition: '<S37>:264' */
        if (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt) > 0) {
          /* Transition: '<S37>:271' */
          /* Transition: '<S37>:273' */
          EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt = (UInt16)((Int32)
            (((Int32)EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt) - 1));
        } else {
          /* Transition: '<S37>:268' */
          EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt = 0U;

          /* Transition: '<S37>:275' */
        }
      } else {
        /* Transition: '<S37>:267' */
        EPSADCrtDW.EpsAngleConv_Sensor.default_delaycnt = ((UInt16)
          MACRO_ANGLE_DEFAULT_DELAYTIME);

        /* Transition: '<S37>:274' */
        /* Transition: '<S37>:275' */
      }
    }
  }

  /* End of Chart: '<S14>/angle_shedule' */
}

#endif

/* Output and update for atomic system: '<S10>/EpsAngleConv_SteeringAngle' */
#if MACRO_STEERANGLE_SELECT == 0

void EPSA_EpsAngleConv_SteeringAngle(void)
{
  Int16 rtb_in_c2ly;
  Int16 rtb_Abs_k5hb;
  Int32 u0;

  /* If: '<S15>/If' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  DataStoreRead: '<S38>/Data Store Read'
   *  DataStoreRead: '<S38>/Data Store Read1'
   *  Logic: '<S38>/Logical Operator'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S46>/Compare'
   */
  if ((Fv_AngleMidValidFlag == ANGLE_STS_Valid) && (Fv_AngleReadyFlag == HELLA_STS_Decode)) {
    /* Outputs for IfAction SubSystem: '<S15>/if1' incorporates:
     *  ActionPort: '<S43>/ap'
     */
    /* Sum: '<S43>/Subtract1' incorporates:
     *  DataStoreRead: '<S43>/Data Store Read'
     */
    u0 = ((Int32)Tv_StrAng) - ((Int32)Fv_StrAngOffset);

    /* Saturate: '<S43>/Saturation' */
    if (u0 > 20000) {
      u0 = 20000;
    } else {
      if (u0 < (-20000)) {
        u0 = (-20000);
      }
    }

    /* End of Saturate: '<S43>/Saturation' */

    /* Product: '<S43>/Divide1' */
    rtb_in_c2ly = (Int16)((u0 * 16) / 10);

    /* End of Outputs for SubSystem: '<S15>/if1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S15>/else1' incorporates:
     *  ActionPort: '<S40>/ap'
     */
    /* SignalConversion: '<S40>/OutportBufferForangx' incorporates:
     *  Constant: '<S40>/Constant'
     */
    rtb_in_c2ly = 0;

    /* End of Outputs for SubSystem: '<S15>/else1' */
  }

  /* End of If: '<S15>/If' */

  /* If: '<S15>/If1' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  DataStoreRead: '<S39>/Data Store Read'
   *  DataStoreRead: '<S39>/Data Store Read2'
   *  Logic: '<S39>/Logical Operator'
   *  RelationalOperator: '<S47>/Compare'
   *  RelationalOperator: '<S48>/Compare'
   */
  if ((Fv_VehEngFailFlag == 0) && (Fv_VsSlopeflag == false)) {
    /* Outputs for IfAction SubSystem: '<S15>/if2' incorporates:
     *  ActionPort: '<S44>/ap'
     */
    /* Chart: '<S44>/esratelimit' incorporates:
     *  Constant: '<S44>/Constant'
     */
    /* Gateway: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/if2/esratelimit */
    /* During: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/if2/esratelimit */
    /* Entry Internal: EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/if2/esratelimit */
    /* Transition: '<S49>:8' */
    if (EPSADCrtDW.EpsAngleConv_Sensor.out > (rtb_in_c2ly + Cal_Ang_GridMax)) {
      /* Transition: '<S49>:10' */
      /* Transition: '<S49>:19' */
      EPSADCrtDW.EpsAngleConv_Sensor.out -= Cal_Ang_GridMax;

      /* Transition: '<S49>:58' */
      /* Transition: '<S49>:63' */
      /* Transition: '<S49>:64' */
    } else {
      /* Transition: '<S49>:14' */
      if (rtb_in_c2ly > (EPSADCrtDW.EpsAngleConv_Sensor.out + Cal_Ang_GridMax))
      {
        /* Transition: '<S49>:16' */
        /* Transition: '<S49>:22' */
        EPSADCrtDW.EpsAngleConv_Sensor.out += Cal_Ang_GridMax;

        /* Transition: '<S49>:33' */
        /* Transition: '<S49>:64' */
      } else {
        /* Transition: '<S49>:60' */
        EPSADCrtDW.EpsAngleConv_Sensor.out = rtb_in_c2ly;

        /* Transition: '<S49>:62' */
      }
    }

    /* End of Chart: '<S44>/esratelimit' */

    /* SignalConversion: '<S44>/OutportBufferForangout' */
    rtb_in_c2ly = EPSADCrtDW.EpsAngleConv_Sensor.out;

    /* End of Outputs for SubSystem: '<S15>/if2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S15>/else2' incorporates:
     *  ActionPort: '<S41>/ap'
     */
    /* SignalConversion: '<S41>/OutportBufferForangout0' incorporates:
     *  Constant: '<S41>/Constant1'
     */
    rtb_in_c2ly = 0;

    /* End of Outputs for SubSystem: '<S15>/else2' */
  }

  /* End of If: '<S15>/If1' */

  /* Abs: '<S42>/Abs' */
  if (rtb_in_c2ly < 0) {
    rtb_Abs_k5hb = (Int16)(-rtb_in_c2ly);
  } else {
    rtb_Abs_k5hb = rtb_in_c2ly;
  }

  /* End of Abs: '<S42>/Abs' */

  /* MinMax: '<S42>/MinMax' incorporates:
   *  Constant: '<S42>/Constant2'
   */
  if (rtb_Abs_k5hb < Cal_AN_MaxAngle) {
  } else {
    rtb_Abs_k5hb = Cal_AN_MaxAngle;
  }

  /* End of MinMax: '<S42>/MinMax' */

  /* Signum: '<S42>/Sign' */
  if (rtb_in_c2ly < 0) {
    rtb_in_c2ly = -1;
  } else {
    rtb_in_c2ly = (Int16)((rtb_in_c2ly > 0) ? 1 : 0);
  }

  /* End of Signum: '<S42>/Sign' */

  /* Sum: '<S42>/Subtract' incorporates:
   *  DataStoreRead: '<S42>/Data Store Read'
   *  Product: '<S42>/Product'
   */
  Fv_StrAng_Org = (Int16)(((Int16)(rtb_Abs_k5hb * rtb_in_c2ly)));

  if (((Fv_AngleMidValidFlag == ANGLE_STS_Valid) 
    && (Fv_AngleReadyFlag == HELLA_STS_Decode))
    &&((Fv_VehEngFailFlag == 0) && (Fv_VsSlopeflag == false))) 
  {
    Tv_StrAng_Raw = (Int16)(((Int16)(rtb_Abs_k5hb * rtb_in_c2ly)) -
      Fv_AngleCorrectOpr);
  }
  else
  {
    Tv_StrAng_Raw = (Int16)(((Int16)(rtb_Abs_k5hb * rtb_in_c2ly)));
  }
  /* DataStoreWrite: '<S42>/Data Store Write' */
  Fv_StrAng_Raw = Tv_StrAng_Raw;
}

#endif

/* Output and update for atomic system: '<S1>/EpsAngleConv_SteerRevAcc' */
void EPSADC_EpsAngleConv_SteerRevAcc(void)
{
  Int32 rtb_Sign;
  Int32 rtb_DataTypeConversion1;

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S6>/Constant'
   *  DataStoreRead: '<S6>/Data Store Read1'
   *  DataTypeConversion: '<S6>/Data Type Conversion3'
   */
  rtb_DataTypeConversion1 = asr_s32(Fv_dRotorAng * ((Int32)((UInt16)
    MACRO_ROTOR2STEER)), 15U);

  /* Signum: '<S6>/Sign' */
  if (rtb_DataTypeConversion1 < 0) {
    rtb_Sign = -1;
  } else {
    rtb_Sign = (rtb_DataTypeConversion1 > 0);
  }

  /* End of Signum: '<S6>/Sign' */

  /* Abs: '<S6>/Abs' */
  if (rtb_DataTypeConversion1 < 0) {
    rtb_DataTypeConversion1 = -rtb_DataTypeConversion1;
  }

  /* End of Abs: '<S6>/Abs' */

  /* MinMax: '<S6>/MinMax' incorporates:
   *  Constant: '<S6>/Constant2'
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   */
  if (rtb_DataTypeConversion1 < ((Int32)Cal_AN_MaxdAngle)) {
  } else {
    rtb_DataTypeConversion1 = (Int32)Cal_AN_MaxdAngle;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* Product: '<S6>/Product1' */
  Tv_dStrAng = (Int16)(rtb_DataTypeConversion1 * rtb_Sign);

  /* DataStoreWrite: '<S6>/Data Store Write' */
  Fv_dStrAng = Tv_dStrAng;

  /* Product: '<S6>/Product2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  DataStoreRead: '<S6>/Data Store Read4'
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  DataTypeConversion: '<S6>/Data Type Conversion4'
   */
  rtb_DataTypeConversion1 = asr_s32(Fv_ddRotorAng * ((Int32)((Int16)((UInt32)
    (((UInt32)((UInt16)MACRO_ROTOR2STEER)) >> 6)))), 13U);

  /* Signum: '<S6>/Sign1' */
  if (rtb_DataTypeConversion1 < 0) {
    rtb_Sign = -1;
  } else {
    rtb_Sign = (rtb_DataTypeConversion1 > 0);
  }

  /* End of Signum: '<S6>/Sign1' */

  /* Abs: '<S6>/Abs1' */
  if (rtb_DataTypeConversion1 < 0) {
    rtb_DataTypeConversion1 = -rtb_DataTypeConversion1;
  }

  /* End of Abs: '<S6>/Abs1' */

  /* MinMax: '<S6>/MinMax1' incorporates:
   *  Constant: '<S6>/Constant3'
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   */
  if (rtb_DataTypeConversion1 < ((Int32)Cal_AN_MaxddAngle)) {
  } else {
    rtb_DataTypeConversion1 = (Int32)Cal_AN_MaxddAngle;
  }

  /* End of MinMax: '<S6>/MinMax1' */

  /* Product: '<S6>/Product3' */
  Tv_ddStrAng = (Int16)(rtb_DataTypeConversion1 * rtb_Sign);
}

/* System initialize for atomic system: '<Root>/EpsAngleConv' */
void EPSADC_EpsAngleConv_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/EpsAngleConv_LowRevSyn' */
  EPS_EpsAngleConv_LowRevSyn_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/EpsAngleConv_LowRevSyn' */
}

/* Output and update for atomic system: '<Root>/EpsAngleConv' */
void EPSADC_EpsAngleConv(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/EpsAngleConv_Select' */
#if MACRO_STEERANGLE_SELECT == 1

  EPSADC_EpsAngleConv_CAN();

#elif MACRO_STEERANGLE_SELECT == 0

  /* Output and update for atomic system: '<S5>/EpsAngleConv_Sensor' */

  /* Outputs for Atomic SubSystem: '<S10>/EpsAngleConv_AngState' */
  EPSADC_EpsAngleConv_AngState();

  /* End of Outputs for SubSystem: '<S10>/EpsAngleConv_AngState' */

  /* Outputs for Atomic SubSystem: '<S10>/EpsAngleConv_HellaRevCalc' */
  EPSAD_EpsAngleConv_HellaRevCalc();

  /* End of Outputs for SubSystem: '<S10>/EpsAngleConv_HellaRevCalc' */

  /* Outputs for Atomic SubSystem: '<S10>/EpsAngleConv_MixFollowState' */
  EPS_EpsAngleConv_MixFollowState();

  /* End of Outputs for SubSystem: '<S10>/EpsAngleConv_MixFollowState' */

  /* Outputs for Atomic SubSystem: '<S10>/EpsAngleConv_AngleDecode' */
  EPSADC_EpsAngleConv_AngleDecode();

  /* End of Outputs for SubSystem: '<S10>/EpsAngleConv_AngleDecode' */

  /* Outputs for Atomic SubSystem: '<S10>/EpsAngleConv_SteeringAngle' */
  EPSA_EpsAngleConv_SteeringAngle();

  /* End of Outputs for SubSystem: '<S10>/EpsAngleConv_SteeringAngle' */
#endif

  /* End of Outputs for SubSystem: '<S1>/EpsAngleConv_Select' */

  /* Outputs for Atomic SubSystem: '<S1>/EpsAngleConv_LowRevSyn' */
  EPSADC_EpsAngleConv_LowRevSyn();

  /* End of Outputs for SubSystem: '<S1>/EpsAngleConv_LowRevSyn' */

  /* Outputs for Atomic SubSystem: '<S1>/EpsAngleConv_SteerRevAcc' */
  EPSADC_EpsAngleConv_SteerRevAcc();

  /* End of Outputs for SubSystem: '<S1>/EpsAngleConv_SteerRevAcc' */
}

/* Output and update for atomic system: '<S50>/EpsCANConv_EsCalc' */
void EPSADC_EpsCANConv_EsCalc(void)
{
  UInt16 rtb_in;

  /* Sum: '<S53>/Add1' incorporates:
   *  Constant: '<S53>/Constant4'
   *  Constant: '<S53>/Constant5'
   *  Inport: '<Root>/CAN_EngSpd'
   *  Product: '<S53>/Product1'
   */
  rtb_in = (UInt16)((Int32)(((Int32)((UInt32)((((UInt32)CAN_EngSpd) * ((UInt32)
    Cal_EngSpd_Scale)) >> 9))) - ((Int32)Cal_EngSpd_Offset)));

  /* Chart: '<S53>/esratelimit' incorporates:
   *  Constant: '<S53>/Constant3'
   *  Inport: '<Root>/CAN_Es_Err'
   */
  /* Gateway: EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_EsCalc/esratelimit */
  /* During: EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_EsCalc/esratelimit */
  /* Entry Internal: EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_EsCalc/esratelimit */
  /* Transition: '<S58>:8' */
  if (EPSADCrtDW.out_jbcr > (rtb_in + Cal_EngSpd_Grid)) {
    /* Transition: '<S58>:10' */
    /* Transition: '<S58>:19' */
    EPSADCrtDW.out_jbcr -= Cal_EngSpd_Grid;

    /* Transition: '<S58>:58' */
    /* Transition: '<S58>:63' */
    /* Transition: '<S58>:64' */
    /* Transition: '<S58>:75' */
  } else {
    /* Transition: '<S58>:14' */
    if (rtb_in > (EPSADCrtDW.out_jbcr + Cal_EngSpd_Grid)) {
      /* Transition: '<S58>:16' */
      /* Transition: '<S58>:22' */
      EPSADCrtDW.out_jbcr += Cal_EngSpd_Grid;

      /* Transition: '<S58>:33' */
      /* Transition: '<S58>:64' */
      /* Transition: '<S58>:75' */
    } else {
      /* Transition: '<S58>:60' */
      EPSADCrtDW.out_jbcr = rtb_in;
    }
  }

  /* Transition: '<S58>:70' */
  if ((Fv_EMSVSReciveTimer >= ((UInt16)MACRO_CAN_LOSTTIME_EMSEs)) || (((Int32)
        CAN_Es_Err) == 1)) {
    /* Transition: '<S58>:66' */
    /* Transition: '<S58>:74' */
    Fv_EmsInvalidFlag = true;

    /* Transition: '<S58>:72' */
  } else {
    /* Transition: '<S58>:69' */
    Fv_EmsInvalidFlag = false;
  }

  /* End of Chart: '<S53>/esratelimit' */

  /* SignalConversion: '<S53>/cpy1' incorporates:
   *  DataStoreWrite: '<S53>/Data Store Write'
   */
  Fv_EngSpd = EPSADCrtDW.out_jbcr;

  /* RelationalOperator: '<S57>/Compare' incorporates:
   *  Constant: '<S57>/Constant'
   *  DataStoreWrite: '<S53>/Data Store Write'
   */
  Fv_EngRun = (Fv_EngSpd > Cal_EngSpd_Run);
}

/* Output and update for atomic system: '<S50>/EpsCANConv_VsCalc' */
void EPSADC_EpsCANConv_VsCalc(void)
{
  Int16 rtb_Add;
  Int16 rtb_Switch_kb53;

  /* Sum: '<S54>/Add' incorporates:
   *  Constant: '<S54>/Constant10'
   *  Constant: '<S54>/Constant2'
   *  Inport: '<Root>/CAN_VehSpd'
   *  Product: '<S54>/Product'
   */
  rtb_Add = (Int16)(((Int32)((UInt32)((((UInt32)CAN_VehSpd) * ((UInt32)
    Cal_VehSpd_Scale)) >> 10))) - ((Int32)Cal_VehSpd_Offset));

  /* DataTypeConversion: '<S54>/vs0' incorporates:
   *  DataStoreWrite: '<S54>/Data Store Write'
   */
  Fv_VehSpd0 = (UInt16)rtb_Add;

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S54>/Constant1'
   *  Constant: '<S54>/Constant3'
   *  Constant: '<S59>/Constant'
   *  Inport: '<Root>/CAN_Reverse'
   *  RelationalOperator: '<S59>/Compare'
   */
  if (CAN_Reverse > ((UInt8)0U)) {
    rtb_Switch_kb53 = Cal_VehSpd_DedRvr;
  } else {
    rtb_Switch_kb53 = Cal_VehSpd_Ded;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S54>/Constant6'
   *  RelationalOperator: '<S60>/u_GTE_up'
   *  RelationalOperator: '<S60>/u_GT_lo'
   *  Switch: '<S60>/Switch1'
   */
  if (rtb_Add >= rtb_Switch_kb53) {
  } else if (rtb_Add > 0) {
    /* Switch: '<S60>/Switch1' */
    rtb_Switch_kb53 = rtb_Add;
  } else {
    rtb_Switch_kb53 = 0;
  }

  /* End of Switch: '<S60>/Switch' */

  /* Sum: '<S60>/Diff' */
  EPSADCrtDW.Diff = (Int16)(rtb_Add - rtb_Switch_kb53);

  /* DataStoreWrite: '<S54>/Data Store Write1' incorporates:
   *  Inport: '<Root>/CAN_VehSpd'
   */
  CAN_VehSpd0 = CAN_VehSpd;
}

/* Output and update for atomic system: '<S50>/EpsCANConv_VsJumpFir' */
void EPSADC_EpsCANConv_VsJumpFir(void)
{
  Int16 rtb_vslast;
  Int16 rtb_UnitDelay2;
  Int16 rtb_Abs1_j13j;

  /* UnitDelay: '<S55>/Unit Delay' */
  rtb_vslast = EPSADCrtDW.UnitDelay_DSTATE;

  /* Sum: '<S55>/Add2' */
  rtb_UnitDelay2 = (Int16)(EPSADCrtDW.Diff - rtb_vslast);

  /* Abs: '<S55>/Abs' */
  if (rtb_UnitDelay2 < 0) {
    rtb_UnitDelay2 = (Int16)(-rtb_UnitDelay2);
  }

  /* End of Abs: '<S55>/Abs' */

  /* Sum: '<S55>/Add3' incorporates:
   *  UnitDelay: '<S55>/Unit Delay2'
   */
  rtb_Abs1_j13j = (Int16)(rtb_vslast - EPSADCrtDW.UnitDelay2_DSTATE);

  /* Abs: '<S55>/Abs1' */
  if (rtb_Abs1_j13j < 0) {
    rtb_Abs1_j13j = (Int16)(-rtb_Abs1_j13j);
  }

  /* End of Abs: '<S55>/Abs1' */

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S61>/Constant'
   *  Constant: '<S62>/Constant'
   *  Logic: '<S55>/Logical Operator'
   *  RelationalOperator: '<S61>/Compare'
   *  RelationalOperator: '<S62>/Compare'
   */
  if ((rtb_UnitDelay2 > Cal_VehSpd_GridMax) && (rtb_Abs1_j13j <
       Cal_VehSpd_GridMax)) {
    EPSADCrtDW.Vsfir = rtb_vslast;
  } else {
    EPSADCrtDW.Vsfir = EPSADCrtDW.Diff;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Update for UnitDelay: '<S55>/Unit Delay' */
  EPSADCrtDW.UnitDelay_DSTATE = EPSADCrtDW.Diff;

  /* Update for UnitDelay: '<S55>/Unit Delay2' */
  EPSADCrtDW.UnitDelay2_DSTATE = rtb_vslast;
}

/* Output and update for atomic system: '<S50>/EpsCANConv_VsRateLimit' */
void EPSADC_EpsCANConv_VsRateLimit(void)
{
  /* Chart: '<S56>/vsratelimit' incorporates:
   *  Constant: '<S56>/Constant3'
   *  Inport: '<Root>/CAN_Vs_Err'
   */
  /* Gateway: EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsRateLimit/vsratelimit */
  /* During: EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsRateLimit/vsratelimit */
  /* Entry Internal: EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsRateLimit/vsratelimit */
  /* Transition: '<S63>:8' */
  if (EPSADCrtDW.out_fl2w > (EPSADCrtDW.Vsfir + Cal_VehSpd_GridMax)) {
    /* Transition: '<S63>:10' */
    /* Transition: '<S63>:19' */
    EPSADCrtDW.out_fl2w -= Cal_VehSpd_GridMax;

    /* Transition: '<S63>:58' */
    /* Transition: '<S63>:63' */
    /* Transition: '<S63>:64' */
    /* Transition: '<S63>:65' */
  } else {
    /* Transition: '<S63>:14' */
    if (EPSADCrtDW.Vsfir > (EPSADCrtDW.out_fl2w + Cal_VehSpd_GridMax)) {
      /* Transition: '<S63>:16' */
      /* Transition: '<S63>:22' */
      EPSADCrtDW.out_fl2w += Cal_VehSpd_GridMax;

      /* Transition: '<S63>:33' */
      /* Transition: '<S63>:64' */
      /* Transition: '<S63>:65' */
    } else {
      /* Transition: '<S63>:60' */
      EPSADCrtDW.out_fl2w = EPSADCrtDW.Vsfir;
    }
  }

  /* Transition: '<S63>:67' */
  if ((Fv_ABSVSReciveTimer >= ((UInt16)MACRO_CAN_LOSTTIME_ABSVs)) || (((Int32)
        CAN_Vs_Err) == 1)) {
    /* Transition: '<S63>:74' */
    /* Transition: '<S63>:76' */
    Fv_AbsInvalidFlag = true;

    /* Transition: '<S63>:79' */
  } else {
    /* Transition: '<S63>:78' */
    Fv_AbsInvalidFlag = false;
  }

  /* End of Chart: '<S56>/vsratelimit' */

  /* MinMax: '<S56>/Min' incorporates:
   *  Constant: '<S56>/Constant1'
   */
  if (Cal_VehSpd_Max < EPSADCrtDW.out_fl2w) {
    Fv_VehSpd = (UInt16)Cal_VehSpd_Max;
  } else {
    Fv_VehSpd = (UInt16)EPSADCrtDW.out_fl2w;
  }

  /* End of MinMax: '<S56>/Min' */
}

/* Output and update for atomic system: '<S2>/EpsCANConv_VsErrProcess' */
void EPSADC_EpsCANConv_VsErrProcess(void)
{
  Int32 rtb_in;

  /* DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
   *  DataStoreRead: '<S52>/Data Store Read'
   */
  rtb_in = ((Int32)Fv_VehEngFailFlag) * 32768;

  /* Chart: '<S52>/VsErrorFix' incorporates:
   *  DataStoreRead: '<S52>/Data Store Read1'
   */
  /* Gateway: EpsCANConv/EpsCANConv_VsErrProcess/VsErrorFix */
  /* During: EpsCANConv/EpsCANConv_VsErrProcess/VsErrorFix */
  /* Entry Internal: EpsCANConv/EpsCANConv_VsErrProcess/VsErrorFix */
  /* Transition: '<S64>:8' */
  if (EPSADCrtDW.out > (rtb_in + Fv_VehEngFailRate)) {
    /* Transition: '<S64>:10' */
    /* Transition: '<S64>:19' */
    EPSADCrtDW.out -= Fv_VehEngFailRate;

    /* SignalConversion: '<S52>/cpy1' incorporates:
     *  DataStoreWrite: '<S52>/Data Store Write'
     */
    Fv_VsSlopeflag = true;

    /* Transition: '<S64>:58' */
    /* Transition: '<S64>:63' */
    /* Transition: '<S64>:64' */
  } else {
    /* Transition: '<S64>:14' */
    if (rtb_in > (EPSADCrtDW.out + Fv_VehEngFailRate)) {
      /* Transition: '<S64>:16' */
      /* Transition: '<S64>:22' */
      EPSADCrtDW.out += Fv_VehEngFailRate;

      /* SignalConversion: '<S52>/cpy1' incorporates:
       *  DataStoreWrite: '<S52>/Data Store Write'
       */
      Fv_VsSlopeflag = true;

      /* Transition: '<S64>:33' */
      /* Transition: '<S64>:64' */
    } else {
      /* Transition: '<S64>:60' */
      EPSADCrtDW.out = rtb_in;

      /* SignalConversion: '<S52>/cpy1' incorporates:
       *  DataStoreWrite: '<S52>/Data Store Write'
       */
      Fv_VsSlopeflag = false;

      /* Transition: '<S64>:62' */
    }
  }

  /* End of Chart: '<S52>/VsErrorFix' */

  /* Sum: '<S52>/Add3' incorporates:
   *  Constant: '<S52>/Constant1'
   *  Product: '<S52>/Product'
   *  Sum: '<S52>/Add2'
   */
  Fv_VehSpdNew = (UInt16)((Int32)(((Int32)Fv_VehSpd) + ((Int32)((Int16)asr_s32
    (((Int32)((Int16)((Int32)(((Int32)Cal_VehSpd_Mid) - ((Int32)Fv_VehSpd))))) *
     EPSADCrtDW.out, 15U)))));
}

/* Output and update for atomic system: '<Root>/EpsCANConv' */
void EPSADC_EpsCANConv(void)
{
  /* Chart: '<S2>/EpsCANConv_SheduleCounter' */
  /* Gateway: EpsCANConv/EpsCANConv_SheduleCounter */
  /* During: EpsCANConv/EpsCANConv_SheduleCounter */
  /* Entry Internal: EpsCANConv/EpsCANConv_SheduleCounter */
  /* Transition: '<S51>:8' */
  if (((Int32)EPSADCrtDW.counter) < 10) {
    /* Transition: '<S51>:10' */
    /* Transition: '<S51>:19' */
    EPSADCrtDW.counter = (UInt16)((Int32)(((Int32)EPSADCrtDW.counter) + 1));
  } else {
    /* Transition: '<S51>:96' */
    EPSADCrtDW.counter = 0U;

    /* Outputs for Function Call SubSystem: '<S2>/EpsCANConv_CAN_DataShedule' */
    /* Outputs for Atomic SubSystem: '<S50>/EpsCANConv_VsCalc' */
    /* Event: '<S51>:99' */
    EPSADC_EpsCANConv_VsCalc();

    /* End of Outputs for SubSystem: '<S50>/EpsCANConv_VsCalc' */

    /* Outputs for Atomic SubSystem: '<S50>/EpsCANConv_VsJumpFir' */
    EPSADC_EpsCANConv_VsJumpFir();

    /* End of Outputs for SubSystem: '<S50>/EpsCANConv_VsJumpFir' */

    /* Outputs for Atomic SubSystem: '<S50>/EpsCANConv_VsRateLimit' */
    EPSADC_EpsCANConv_VsRateLimit();

    /* End of Outputs for SubSystem: '<S50>/EpsCANConv_VsRateLimit' */

    /* Outputs for Atomic SubSystem: '<S50>/EpsCANConv_EsCalc' */
    EPSADC_EpsCANConv_EsCalc();

    /* End of Outputs for SubSystem: '<S50>/EpsCANConv_EsCalc' */
    /* End of Outputs for SubSystem: '<S2>/EpsCANConv_CAN_DataShedule' */
    /* Transition: '<S51>:97' */
  }

  /* End of Chart: '<S2>/EpsCANConv_SheduleCounter' */

  /* Outputs for Atomic SubSystem: '<S2>/EpsCANConv_VsErrProcess' */
  EPSADC_EpsCANConv_VsErrProcess();

  /* End of Outputs for SubSystem: '<S2>/EpsCANConv_VsErrProcess' */
}

/* Output and update for atomic system: '<S3>/EpsTorqueConv_AdvanceCalc' */
void EPSAD_EpsTorqueConv_AdvanceCalc(void)
{
  Int32 rtb_Sign1_onvv;
  Int16 rtb_Abs;
  Int32 rtb_Abs2;
  Int16 tmp;

  /* Abs: '<S65>/Abs1' */
  if (Tv_StrTrq0 < 0) {
    rtb_Abs = (Int16)(-Tv_StrTrq0);
  } else {
    rtb_Abs = Tv_StrTrq0;
  }

  /* MinMax: '<S65>/MinMax' incorporates:
   *  Abs: '<S65>/Abs1'
   *  Constant: '<S65>/Constant'
   */
  if (rtb_Abs < ((Int16)MACRO_TQ_MAX_TORQM)) {
  } else {
    rtb_Abs = ((Int16)MACRO_TQ_MAX_TORQM);
  }

  /* End of MinMax: '<S65>/MinMax' */

  /* Signum: '<S65>/Sign' */
  if (Tv_StrTrq0 < 0) {
    tmp = -1;
  } else {
    tmp = (Int16)((Tv_StrTrq0 > 0) ? 1 : 0);
  }

  /* End of Signum: '<S65>/Sign' */

  /* Sum: '<S65>/Add' incorporates:
   *  Product: '<S65>/Product'
   *  Product: '<S65>/Product1'
   */
  rtb_Abs2 = ((Int32)Tv_StrTrqP2dot5) - ((((Int32)rtb_Abs) * ((Int32)tmp)) * 2);

  /* Signum: '<S65>/Sign1' */
  if (rtb_Abs2 < 0) {
    rtb_Sign1_onvv = -1;
  } else {
    rtb_Sign1_onvv = (rtb_Abs2 > 0);
  }

  /* End of Signum: '<S65>/Sign1' */

  /* Abs: '<S65>/Abs2' */
  if (rtb_Abs2 < 0) {
    rtb_Abs2 = -rtb_Abs2;
  }

  /* End of Abs: '<S65>/Abs2' */

  /* MinMax: '<S65>/MinMax1' incorporates:
   *  Constant: '<S65>/Constant1'
   */
  if (rtb_Abs2 < ((Int32)((Int16)MACRO_TQ_MAX_TORQAV))) {
  } else {
    rtb_Abs2 = (Int32)((Int16)MACRO_TQ_MAX_TORQAV);
  }

  /* End of MinMax: '<S65>/MinMax1' */

  /* Product: '<S65>/Product2' */
  rtb_Abs = (Int16)(rtb_Abs2 * rtb_Sign1_onvv);

  /* Abs: '<S65>/Abs' */
  if (rtb_Abs < 0) {
    rtb_Abs = (Int16)(-rtb_Abs);
  }

  /* End of Abs: '<S65>/Abs' */

  /* Product: '<S65>/Divide1' incorporates:
   *  DataStoreWrite: '<S65>/Data Store Write'
   */
  Fv_dStrTrq = (Int16)(rtb_Abs / 2);

  /* Product: '<S65>/Divide' */
  Fv_StrTrq_Primed = (Int16)(Tv_StrTrqP2dot5 / 2);
}

/* Output and update for atomic system: '<S66>/TorqueCalc_BasicHandT' */
void EPSADC_TorqueCalc_BasicHandT(void)
{
  /* SignalConversion: '<S70>/cpy1' incorporates:
   *  DataStoreWrite: '<S70>/Data Store Write'
   *  Inport: '<Root>/IOC_Tor1Duty'
   */
  Fv_MainTorqueADVol = IOC_Tor1Duty;

  /* SignalConversion: '<S70>/cpy2' incorporates:
   *  DataStoreWrite: '<S70>/Data Store Write1'
   *  Inport: '<Root>/IOC_Tor2Duty'
   */
  Fv_SubTorqueADVol = IOC_Tor2Duty;

  /* Product: '<S70>/Product1' incorporates:
   *  Constant: '<S70>/Constant10'
   *  Constant: '<S70>/Constant2'
   *  Constant: '<S70>/Constant3'
   *  Constant: '<S70>/Constant4'
   *  Constant: '<S70>/Constant5'
   *  Constant: '<S70>/Constant6'
   *  Constant: '<S70>/Constant7'
   *  Constant: '<S70>/Constant8'
   *  Constant: '<S70>/Constant9'
   *  Inport: '<Root>/AD_MainTorque'
   *  Inport: '<Root>/AD_SubTorque'
   *  Inport: '<Root>/IOC_Tor1Duty'
   *  Inport: '<Root>/IOC_Tor1Frez'
   *  Inport: '<Root>/IOC_Tor2Duty'
   *  Inport: '<Root>/IOC_Tor2Frez'
   *  Logic: '<S70>/trqena'
   *  Product: '<S70>/Product'
   *  RelationalOperator: '<S70>/ge1'
   *  RelationalOperator: '<S70>/ge2'
   *  RelationalOperator: '<S70>/ge3'
   *  RelationalOperator: '<S70>/ge42'
   *  RelationalOperator: '<S70>/ge5'
   *  RelationalOperator: '<S70>/ge6'
   *  RelationalOperator: '<S70>/ge7'
   *  RelationalOperator: '<S70>/ge8'
   *  Sum: '<S70>/Add'
   */
  Tv_StrTrq0Orig = (Int16)(((Int32)((Int16)asr_s32((((Int32)AD_MainTorque) -
    ((Int32)AD_SubTorque)) * ((Int32)((Int16)MACRO_TQ_STRTRQ_SNR_COEF)), 7U))) *
    ((Int32)(((((((((IOC_Tor1Duty <= ((UInt16)MACRO_STRTRQ_MAX)) &&
                    (IOC_Tor1Duty >= ((UInt16)MACRO_STRTRQ_MIN))) &&
                   (IOC_Tor2Duty <= ((UInt16)MACRO_STRTRQ_MAX))) &&
                  (IOC_Tor2Duty >= ((UInt16)MACRO_STRTRQ_MIN))) && (IOC_Tor1Frez
    <= ((UInt16)MACRO_STRTRQ_FRZMAX))) && (IOC_Tor1Frez >= ((UInt16)
    MACRO_STRTRQ_FRZMIN))) && (IOC_Tor2Frez <= ((UInt16)MACRO_STRTRQ_FRZMAX))) &&
              (IOC_Tor2Frez >= ((UInt16)MACRO_STRTRQ_FRZMIN))) ? 1 : 0)));
}

/* System initialize for atomic system: '<S66>/TorqueCalc_NotchFir' */
void EPSADC_TorqueCalc_NotchFir_Init(void)
{
  /* InitializeConditions for DiscreteFilter: '<S71>/notchfilter' */
  EPSADCrtDW.notchfilter_states[0] = 0.0;
  EPSADCrtDW.notchfilter_denStates[0] = 0.0;
  EPSADCrtDW.notchfilter_states[1] = 0.0;
  EPSADCrtDW.notchfilter_denStates[1] = 0.0;
}

/* Output and update for atomic system: '<S66>/TorqueCalc_NotchFir' */
void EPSADC_TorqueCalc_NotchFir(void)
{
  Int32 rtb_Gain1;

  /* DiscreteFilter: '<S71>/notchfilter' incorporates:
   *  DataTypeConversion: '<S71>/conv1'
   *  DataTypeConversion: '<S73>/FixPt Gateway Out'
   */
  EPSADCrtDW.notchfilter_tmp = ((((EPSADCrtDW.y[0] * ((Float64)Tv_StrTrq0Orig))
    + (EPSADCrtDW.y[1] * EPSADCrtDW.notchfilter_states[0])) + (EPSADCrtDW.y[2] *
    EPSADCrtDW.notchfilter_states[1])) - (EPSADCrtDW.y[4] *
    EPSADCrtDW.notchfilter_denStates[0])) - (EPSADCrtDW.y[5] *
    EPSADCrtDW.notchfilter_denStates[1]);

  /* Gain: '<S71>/Gain1' incorporates:
   *  DataTypeConversion: '<S71>/conv2'
   *  DiscreteFilter: '<S71>/notchfilter'
   */
  rtb_Gain1 = (Int32)EPSADCrtDW.notchfilter_tmp;

  /* Saturate: '<S71>/Saturation' */
  if (rtb_Gain1 >= ((Int32)16384)) {
    Tv_StrTrq0 = 16384;
  } else if (rtb_Gain1 <= ((Int32)(-16384))) {
    Tv_StrTrq0 = -16384;
  } else {
    Tv_StrTrq0 = (Int16)rtb_Gain1;
  }

  /* End of Saturate: '<S71>/Saturation' */

  /* DataStoreWrite: '<S71>/Data Store Write2' */
  Fv_StrTrq0 = Tv_StrTrq0;

  /* Update for DiscreteFilter: '<S71>/notchfilter' incorporates:
   *  DataTypeConversion: '<S71>/conv1'
   *  DataTypeConversion: '<S73>/FixPt Gateway Out'
   */
  EPSADCrtDW.notchfilter_states[1] = EPSADCrtDW.notchfilter_states[0];
  EPSADCrtDW.notchfilter_states[0] = (Float64)Tv_StrTrq0Orig;
  EPSADCrtDW.notchfilter_denStates[1] = EPSADCrtDW.notchfilter_denStates[0];
  EPSADCrtDW.notchfilter_denStates[0] = EPSADCrtDW.notchfilter_tmp;
}

/* Output and update for atomic system: '<S72>/filter_pfilter' */
void EPSADC_filter_pfilter(Float64 rtu_f, Float64 rtu_c, Float64 rty_y[6])
{
  Float64 Px;
  Float64 P1;
  Float64 P2;
  Float64 A1;

  /* MATLAB Function 'EpsTorqueConv/EpsTorqueConv_Calc/TorqueCalc_VsCf/filter_pfilter': '<S75>:1' */
  /* '<S75>:1:2' T0 = 1e-3; */
  /* '<S75>:1:3' w = 2*pi*f; */
  /* '<S75>:1:4' Px=w*T0; */
  Px = (6.2831853071795862 * rtu_f) * 0.001;

  /* '<S75>:1:5' P1=(2/(Px))^2; */
  P1 = 2.0 / Px;
  P1 *= P1;

  /* '<S75>:1:6' P2=4*c/(Px); */
  P2 = (4.0 * rtu_c) / Px;

  /* '<S75>:1:7' Px=P1+P2+1; */
  Px = (P1 + P2) + 1.0;

  /* '<S75>:1:8' A1=1/Px; */
  A1 = 1.0 / Px;

  /* '<S75>:1:9' A2=2/Px; */
  /* '<S75>:1:10' A3=A1; */
  /* '<S75>:1:11' B1=1; */
  /* '<S75>:1:12' B2=(-2*P1+2)/Px; */
  /* '<S75>:1:13' B3=((P1-P2)+1)/Px; */
  /* '<S75>:1:14' y=[A1,A2,A3,B1,B2,B3]; */
  rty_y[0] = A1;
  rty_y[1] = 2.0 / Px;
  rty_y[2] = A1;
  rty_y[3] = 1.0;
  rty_y[4] = ((-2.0 * P1) + 2.0) / Px;
  rty_y[5] = ((P1 - P2) + 1.0) / Px;
}

/* Output and update for atomic system: '<S66>/TorqueCalc_VsCf' */
void EPSADC_TorqueCalc_VsCf(void)
{
  /* local block i/o variables */
  Float64 rtb_DataTypeConversion;
  Int16 rtb_revfirfrez;
  Int32 rtb_Abs;
  Int16 rtb_vsfircoef;
  Int32 tmp_0;
  const ConstP_EPSADC_dfsm rtConstP_EPSADC_dfsm = {

    /* Computed Parameter: tsc_looktable_cmd1_maxIndex
    * Referenced by: '<S194>/tsc_looktable_cmd1'
    */
    { 6U, 5U }
  };
  /* Abs: '<S72>/Abs' incorporates:
   *  DataStoreRead: '<S72>/Data Store Read'
   */
#if 0//���������������--TXY--20240619  
  if (Fv_dRotorAng_rpm < 0) {
    rtb_Abs = -Fv_dRotorAng_rpm;
  } else {
    rtb_Abs = Fv_dRotorAng_rpm;
  }
#else
  if (Tv_ddStrAng < 0) {
    rtb_Abs = -Tv_ddStrAng;
  } else {
    rtb_Abs = Tv_ddStrAng;
  }
#endif  
  /* End of Abs: '<S72>/Abs' */

  /* MinMax: '<S72>/Max' incorporates:
   *  Constant: '<S72>/Constant'
   */
  if (rtb_Abs < ((Int32)((UInt16)Cal_AN_MaxddAngle))) {
  } else {
    rtb_Abs = (Int32)((UInt16)Cal_AN_MaxddAngle);
  }

  /* Lookup_n-D: '<S72>/revfirfrez' incorporates:
   *  MinMax: '<S72>/Max'
   */

	  rtb_revfirfrez = look1_iu16ls32n10ts16D_QWHCuzIb((UInt16)rtb_Abs, ((const
	    UInt16 *)&(Cal_TQ_RevTrqFirTab_X[0])), ((const Int16 *)
	    &(Cal_TQ_RevTrqFirTab_Y[0])), &EPSADCrtDW.m_bpIndex_eyvb, 8U);

    if (Fv_dRotorAng_rpm < 0) {
      tmp_0 = -Fv_dRotorAng_rpm;
    } else {
      tmp_0 = Fv_dRotorAng_rpm;
    }
  /* Lookup_n-D: '<S72>/vsfircoef' */
   
  rtb_vsfircoef = look2_is16u16ls32n10tu_gntPemx1(tmp_0, Fv_VehSpdNew, (const
    Int16 *)&Cal_TQ_VsTrqFirTab_X2[0], (const UInt16 *)&Cal_TQ_VsTrqFirTab_Y2[0],
    (const UInt16 *)&Cal_TQ_VsTrqFirTab_Z2[0], EPSADCrtDW.m_bpIndex_bsym,
    rtConstP_EPSADC_dfsm.tsc_looktable_cmd1_maxIndex, 7U);

  /* Product: '<S72>/Product2' */
  rtb_revfirfrez = (Int16)asr_s32(((Int32)rtb_revfirfrez) * ((Int32)
    rtb_vsfircoef), 7U);

  /* Switch: '<S74>/Switch2' incorporates:
   *  Constant: '<S72>/Constant1'
   *  Constant: '<S72>/Constant11'
   *  RelationalOperator: '<S74>/LowerRelop1'
   *  RelationalOperator: '<S74>/UpperRelop'
   *  Switch: '<S74>/Switch'
   */
  if (rtb_revfirfrez > ((Int16)MACRO_STRTRQ_FIRFRZMAX)) {
    /* DataTypeConversion: '<S72>/Data Type Conversion' */
    rtb_DataTypeConversion = (Float64)((Int16)MACRO_STRTRQ_FIRFRZMAX);
  } else if (rtb_revfirfrez < ((Int16)MACRO_STRTRQ_FIRFRZMIN)) {
    /* Switch: '<S74>/Switch' incorporates:
     *  Constant: '<S72>/Constant11'
     *  DataTypeConversion: '<S72>/Data Type Conversion'
     */
    rtb_DataTypeConversion = (Float64)((Int16)MACRO_STRTRQ_FIRFRZMIN);
  } else {
    /* DataTypeConversion: '<S72>/Data Type Conversion' incorporates:
     *  Switch: '<S74>/Switch'
     */
    rtb_DataTypeConversion = (Float64)rtb_revfirfrez;
  }

  /* End of Switch: '<S74>/Switch2' */

  /* MATLAB Function: '<S72>/filter_pfilter' incorporates:
   *  Constant: '<S72>/Constant12'
   */
  EPSADC_filter_pfilter(rtb_DataTypeConversion, MACRO_STRTRQ_FIRCOEF_C,
                        EPSADCrtDW.y);
}

/* System initialize for atomic system: '<S3>/EpsTorqueConv_Calc' */
void EPSADC_EpsTorqueConv_Calc_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S66>/TorqueCalc_NotchFir' */
  EPSADC_TorqueCalc_NotchFir_Init();

  /* End of SystemInitialize for SubSystem: '<S66>/TorqueCalc_NotchFir' */
}

/* Output and update for atomic system: '<S3>/EpsTorqueConv_Calc' */
void EPSADC_EpsTorqueConv_Calc(void)
{
  /* Outputs for Atomic SubSystem: '<S66>/TorqueCalc_VsCf' */
  EPSADC_TorqueCalc_VsCf();

  /* End of Outputs for SubSystem: '<S66>/TorqueCalc_VsCf' */

  /* Outputs for Atomic SubSystem: '<S66>/TorqueCalc_BasicHandT' */
  EPSADC_TorqueCalc_BasicHandT();

  /* End of Outputs for SubSystem: '<S66>/TorqueCalc_BasicHandT' */

  /* Outputs for Atomic SubSystem: '<S66>/TorqueCalc_NotchFir' */
  EPSADC_TorqueCalc_NotchFir();

  /* End of Outputs for SubSystem: '<S66>/TorqueCalc_NotchFir' */
}

/* System initialize for atomic system: '<S3>/EpsTorqueConv_DeadOut' */
void EPSA_EpsTorqueConv_DeadOut_Init(void)
{
  /* SystemInitialize for SignalConversion: '<S67>/cpy3' */
  Fv_VsSwitchflag = EPSADCrtDW.level;
}

/* Output and update for atomic system: '<S3>/EpsTorqueConv_DeadOut' */
void EPSADC_EpsTorqueConv_DeadOut(void)
{
  Int16 rtb_Sign;
  Int16 rtb_vsdz;

  /* SignalConversion: '<S67>/cpy1' incorporates:
   *  DataStoreWrite: '<S67>/Data Store Write'
   */
  Fv_StrTrqP = Fv_StrTrq_Primed;

  /* Lookup_n-D: '<S67>/vsded' */
  rtb_vsdz = look1_iu16ls32n10ts16D_QWHCuzIb(Fv_VehSpdNew, ((const UInt16 *)
    &(Cal_TQ_VsTrqDzTab_X[0])), ((const Int16 *)&(Cal_TQ_VsTrqDzTab_Y[0])),
    &EPSADCrtDW.m_bpIndex, 5U);

  /* Switch: '<S76>/Switch' incorporates:
   *  DataStoreWrite: '<S67>/Data Store Write'
   *  RelationalOperator: '<S76>/u_GTE_up'
   */
  if (Fv_StrTrqP >= rtb_vsdz) {
  } else {
    /* UnaryMinus: '<S67>/Unary Minus' */
    rtb_vsdz = (Int16)(-rtb_vsdz);

    /* Switch: '<S76>/Switch1' incorporates:
     *  RelationalOperator: '<S76>/u_GT_lo'
     */
    if (Fv_StrTrqP > rtb_vsdz) {
      rtb_vsdz = Fv_StrTrqP;
    }

    /* End of Switch: '<S76>/Switch1' */
  }

  /* End of Switch: '<S76>/Switch' */

  /* Sum: '<S76>/Diff' incorporates:
   *  DataStoreWrite: '<S67>/Data Store Write'
   */
  rtb_vsdz = (Int16)(Fv_StrTrqP - rtb_vsdz);

  /* Signum: '<S67>/Sign' */
  if (rtb_vsdz < 0) {
    rtb_Sign = -1;
  } else {
    rtb_Sign = (Int16)((rtb_vsdz > 0) ? 1 : 0);
  }

  /* End of Signum: '<S67>/Sign' */

  /* Abs: '<S67>/Abs' */
  if (rtb_vsdz < 0) {
    rtb_vsdz = (Int16)(-rtb_vsdz);
  }

  /* End of Abs: '<S67>/Abs' */

  /* MinMax: '<S67>/MinMax' incorporates:
   *  Constant: '<S67>/Constant'
   */
  if (rtb_vsdz < ((Int16)MACRO_TQ_MAX_TORQM)) {
  } else {
    rtb_vsdz = ((Int16)MACRO_TQ_MAX_TORQM);
  }

  /* End of MinMax: '<S67>/MinMax' */

  /* Product: '<S67>/Product' */
  Fv_StrTrq = (Int16)(rtb_vsdz * rtb_Sign);

  /* Chart: '<S67>/FilterVsLevel' incorporates:
   *  SignalConversion: '<S67>/cpy2'
   */
  /* Gateway: EpsTorqueConv/EpsTorqueConv_DeadOut/FilterVsLevel */
  /* During: EpsTorqueConv/EpsTorqueConv_DeadOut/FilterVsLevel */
  /* Entry Internal: EpsTorqueConv/EpsTorqueConv_DeadOut/FilterVsLevel */
  /* Transition: '<S77>:8' */
  if (Fv_VehSpdNew > ((UInt16)MACRO_MAC_VSLEVEL3UP)) {
    /* Transition: '<S77>:10' */
    /* Transition: '<S77>:19' */
    EPSADCrtDW.level = 3U;
  } else {
    /* Transition: '<S77>:14' */
    if (Fv_VehSpdNew < ((UInt16)MACRO_MAC_VSLEVEL3DN)) {
      /* Transition: '<S77>:21' */
      if (Fv_VehSpdNew > ((UInt16)MACRO_MAC_VSLEVEL2UP)) {
        /* Transition: '<S77>:65' */
        /* Transition: '<S77>:67' */
        EPSADCrtDW.level = 2U;
      } else {
        /* Transition: '<S77>:29' */
        if (Fv_VehSpdNew < ((UInt16)MACRO_MAC_VSLEVEL2DN)) {
          /* Transition: '<S77>:68' */
          if (Fv_VehSpdNew > ((UInt16)MACRO_MAC_VSLEVEL1UP)) {
            /* Transition: '<S77>:98' */
            /* Transition: '<S77>:100' */
            EPSADCrtDW.level = 1U;

            /* Transition: '<S77>:101' */
          } else {
            /* Transition: '<S77>:103' */
            if (Fv_VehSpdNew < ((UInt16)MACRO_MAC_VSLEVEL1DN)) {
              /* Transition: '<S77>:105' */
              /* Transition: '<S77>:109' */
              EPSADCrtDW.level = 0U;

              /* Transition: '<S77>:108' */
              /* Transition: '<S77>:101' */
            } else {
              /* Transition: '<S77>:106' */
              /* Transition: '<S77>:87' */
              /* Transition: '<S77>:108' */
              /* Transition: '<S77>:101' */
            }
          }
        } else {
          /* Transition: '<S77>:94' */
          /* Transition: '<S77>:93' */
          /* Transition: '<S77>:87' */
          /* Transition: '<S77>:108' */
          /* Transition: '<S77>:101' */
        }
      }
    } else {
      /* Transition: '<S77>:90' */
      /* Transition: '<S77>:91' */
      /* Transition: '<S77>:93' */
      /* Transition: '<S77>:87' */
      /* Transition: '<S77>:108' */
      /* Transition: '<S77>:101' */
    }

    /* Transition: '<S77>:88' */
  }

  /* End of Chart: '<S67>/FilterVsLevel' */

  /* SignalConversion: '<S67>/cpy3' */
  Fv_VsSwitchflag = EPSADCrtDW.level;
}

/* Output and update for atomic system: '<S3>/EpsTorqueConv_SoftAdv' */
void EPSADC_EpsTorqueConv_SoftAdv(void)
{
  /* Chart: '<S68>/Call_TorqueSoftAdv' */
  /* Gateway: EpsTorqueConv/EpsTorqueConv_SoftAdv/Call_TorqueSoftAdv */
  /* During: EpsTorqueConv/EpsTorqueConv_SoftAdv/Call_TorqueSoftAdv */
  /* Entry Internal: EpsTorqueConv/EpsTorqueConv_SoftAdv/Call_TorqueSoftAdv */
  /* Transition: '<S78>:4' */
  /* Transition: '<S78>:6' */
  Tv_StrTrqP2dot5 = (Int16)TorqueSoftAdvFun(Tv_StrTrq0);

  /* DataStoreWrite: '<S68>/Data Store Write' */
  /* Simulink Function 'fixdt1q10': '<S78>:7' */
  Fv_StrTrqP2dot5 = Tv_StrTrqP2dot5;
}

/* Output and update for atomic system: '<S3>/EpsTorqueConv_StableFilter' */
void EPSA_EpsTorqueConv_StableFilter(void)
{
  /* Chart: '<S69>/Call_ToruqeStableFilter' */
  /* Gateway: EpsTorqueConv/EpsTorqueConv_StableFilter/Call_ToruqeStableFilter */
  /* During: EpsTorqueConv/EpsTorqueConv_StableFilter/Call_ToruqeStableFilter */
  /* Entry Internal: EpsTorqueConv/EpsTorqueConv_StableFilter/Call_ToruqeStableFilter */
  /* Transition: '<S80>:4' */
  /* Transition: '<S80>:6' */
  Fv_StrTrq_FeedForward = (Int16)ToruqeStableFilterFun(Fv_StrTrq_Primed);

  /* Simulink Function 'fixdt1q10': '<S80>:7' */
}

/* System initialize for atomic system: '<Root>/EpsTorqueConv' */
void EPSADC_EpsTorqueConv_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S3>/EpsTorqueConv_Calc' */
  EPSADC_EpsTorqueConv_Calc_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/EpsTorqueConv_Calc' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/EpsTorqueConv_DeadOut' */
  EPSA_EpsTorqueConv_DeadOut_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/EpsTorqueConv_DeadOut' */
}

/* Output and update for atomic system: '<Root>/EpsTorqueConv' */
void EPSADC_EpsTorqueConv(void)
{
  /* Outputs for Atomic SubSystem: '<S3>/EpsTorqueConv_Calc' */
  EPSADC_EpsTorqueConv_Calc();

  /* End of Outputs for SubSystem: '<S3>/EpsTorqueConv_Calc' */

  /* Outputs for Atomic SubSystem: '<S3>/EpsTorqueConv_SoftAdv' */
  EPSADC_EpsTorqueConv_SoftAdv();

  /* End of Outputs for SubSystem: '<S3>/EpsTorqueConv_SoftAdv' */

  /* Outputs for Atomic SubSystem: '<S3>/EpsTorqueConv_AdvanceCalc' */
  EPSAD_EpsTorqueConv_AdvanceCalc();

  /* End of Outputs for SubSystem: '<S3>/EpsTorqueConv_AdvanceCalc' */

  /* Outputs for Atomic SubSystem: '<S3>/EpsTorqueConv_DeadOut' */
  EPSADC_EpsTorqueConv_DeadOut();

  /* End of Outputs for SubSystem: '<S3>/EpsTorqueConv_DeadOut' */

  /* Outputs for Atomic SubSystem: '<S3>/EpsTorqueConv_StableFilter' */
  EPSA_EpsTorqueConv_StableFilter();

  /* End of Outputs for SubSystem: '<S3>/EpsTorqueConv_StableFilter' */
}

/* System initialize for referenced model: 'EPSADC' */
void EPSADC_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/EpsTorqueConv' */
  EPSADC_EpsTorqueConv_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/EpsTorqueConv' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/EpsAngleConv' */
  EPSADC_EpsAngleConv_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/EpsAngleConv' */
}

/* Output and update for referenced model: 'EPSADC' */
void EPSADC(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/EpsCANConv' */
  EPSADC_EpsCANConv();

  /* End of Outputs for SubSystem: '<Root>/EpsCANConv' */

  /* Outputs for Atomic SubSystem: '<Root>/EpsTorqueConv' */
  EPSADC_EpsTorqueConv();

  /* End of Outputs for SubSystem: '<Root>/EpsTorqueConv' */

  /* Outputs for Atomic SubSystem: '<Root>/EpsAngleConv' */
  EPSADC_EpsAngleConv();

  /* End of Outputs for SubSystem: '<Root>/EpsAngleConv' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
