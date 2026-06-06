/*
 * File: eps_controlAlgorithm.c
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Sep 16 11:53:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "eps_controlAlgorithm.h"
#include "eps_controlAlgorithm_private.h"
#include "CalVarExt.h"
/* Named constants for Chart: '<S1>/Scheduler' */
#define event_Intrpt1                  (0)
#define event_Intrpt2                  (1)

/* Block signals and states (default storage) */
DW_l5cf rtDW_l5cf;

/* Previous zero-crossings (trigger) states */
PrevZCX_pwxn rtPrevZCX_pwxn;

/* External inputs (root inport signals with default storage) */
ExtU_csev rtU;

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Localizable */
volatile UInt16 CAN_LostRecCounter[CANBUS_NUM];

/* Forward declaration for local functions */
static void chartstep_c2_eps_controlAlgorit(const Int32 *sfEvent);

/* System initialize for function-call system: '<S1>/task_100us' */
void task_100us_Init(void)
{
  /* SystemInitialize for ModelReference: '<S4>/EstSteerLoad' */
  EstSteerLoad_Init();
}

/* Output and update for function-call system: '<S1>/task_100us' */
void task_100us(void)
{
  Float64 rtb_Constant21[20];
  Float64 rtb_Constant14[12];
  Int16 rtb_Constant1[9];
  Float64 rtb_Constant16[8];
  Float64 rtb_Constant32[8];
  Float64 rtb_Constant13[5];
  Float64 rtb_Constant17[2];
  Float64 rtb_Constant18[2];
  Float64 rtb_Constant19[2];
  Int32 rtb_Constant12;
  UInt16 rtb_Constant36;
  UInt8 rtb_Constant4;
  Int32 rtb_Constant6;
  UInt16 rtb_DataStoreRead;
  UInt16 rtb_DataStoreRead1;
  UInt16 rtb_DataStoreRead2;
  UInt16 rtb_DataStoreRead3;
  UInt16 rtb_DataStoreRead10;
  UInt16 rtb_DataStoreRead11;
  Bool rtb_DataStoreRead12;
  Int16 rtb_DataStoreRead15;
  Int16 rtb_DataStoreRead16;
  Int16 rtb_DataStoreRead17;
  UInt8 rtb_DataStoreRead18;
  Bool rtb_DataStoreRead19;
  Bool rtb_DataStoreRead20;
  Bool rtb_DataStoreRead21;
  UInt16 rtb_DataStoreRead22;
  UInt16 rtb_DataStoreRead23;
  UInt16 rtb_DataStoreRead24;
  UInt16 rtb_DataStoreRead25;
  UInt8 rtb_DataStoreRead26;
  UInt8 rtb_DataStoreRead27;
  UInt32 rtb_DataStoreRead28;
  UInt16 rtb_DataStoreRead29;
  UInt16 rtb_DataStoreRead30;
  UInt8 rtb_DataStoreRead31;
  UInt16 rtb_DataStoreRead34;
  UInt16 rtb_DataStoreRead4;
  UInt16 rtb_DataStoreRead41;
  UInt16 rtb_DataStoreRead5;
  UInt16 rtb_DataStoreRead6;
  UInt16 rtb_DataStoreRead7;
  UInt16 rtb_DataStoreRead8;
  UInt16 rtb_DataStoreRead9;
  Int16 rtb_Constant11[41];
  UInt16 rtb_Constant35[30];
  Float64 rtb_DataStoreRead32[20];
  Int16 rtb_Constant10[18];
  UInt16 rtb_Constant9[18];
  Float64 rtb_DataStoreRead38[18];
  Float64 rtb_DataStoreRead42[18];
  Float64 rtb_DataStoreRead37[16];
  Float64 rtb_DataStoreRead40[16];
  Float64 rtb_DataStoreRead39[12];
  UInt16 rtb_Constant20[9];
  Float64 rtb_DataStoreRead35[8];
  UInt16 rtb_Constant27[6];
  Int16 rtb_Constant28[6];
  Int16 rtb_Constant33[6];
  UInt16 rtb_Constant24[5];
  Int8 rtb_Constant25[5];
  Int16 rtb_Constant30[5];
  Int16 rtb_Constant31[5];
  UInt16 rtb_Constant34[5];
  Float64 rtb_DataStoreRead33[4];
  Float64 rtb_DataStoreRead36[4];
  Int16 rtb_Constant15;
  Int32 rtb_Constant2;
  UInt16 rtb_Constant22;
  UInt16 rtb_Constant23;
  Int16 rtb_Constant26;
  Int16 rtb_Constant29;
  Int32 rtb_Constant3;
  Int16 rtb_Constant5;
  Int32 rtb_Constant7;
  Int32 rtb_Constant8;
  Int16 rtb_DataStoreRead13;
  Int16 rtb_DataStoreRead14;
  Int32 i;

  /* Constant: '<S12>/Constant11' */
  memcpy(&rtb_Constant11[0], ((const Int16 *)&(Cal_FOC_ID_WeakPwrTab_C[0])), 41U
         * (sizeof(Int16)));

  /* Constant: '<S12>/Constant35' */
  for (i = 0; i < 30; i++) {
    rtb_Constant35[i] = Cal_HM_HarmonicTabGen_Z[(i)];
  }

  /* End of Constant: '<S12>/Constant35' */

  /* Constant: '<S12>/Constant21' */
  memcpy(&rtb_Constant21[0], ((const Float64 *)&(Cal_FirCof_RST_Frez2[0])), 20U *
         (sizeof(Float64)));

  /* DataStoreRead: '<S12>/Data Store Read32' */
  memcpy(&rtb_DataStoreRead32[0], ((Float64 *)&(Fv_FirCof_FeedForward[0])), 20U *
         (sizeof(Float64)));

  /* DataStoreRead: '<S12>/Data Store Read38' */
  memcpy(&rtb_DataStoreRead38[0], ((Float64 *)&(Fv_FirCof_TorqueNotchFilter[0])),
         18U * (sizeof(Float64)));

  /* DataStoreRead: '<S12>/Data Store Read42' */
  memcpy(&rtb_DataStoreRead42[0], ((Float64 *)&(Fv_FirCof_TorqueRobust[0])), 18U
         * (sizeof(Float64)));
  for (i = 0; i < 18; i++) {
    /* Constant: '<S12>/Constant10' */
    rtb_Constant10[i] = Cal_FOC_ID_WeakRtTab_Y[(i)];

    /* Constant: '<S12>/Constant9' */
    rtb_Constant9[i] = Cal_FOC_ID_WeakRtTab_X[(i)];
  }

  /* DataStoreRead: '<S12>/Data Store Read37' */
  memcpy(&rtb_DataStoreRead37[0], ((Float64 *)&(Fv_FirCof_TorqueSoftAdv2[0])),
         (sizeof(Float64)) << 4U);

  /* DataStoreRead: '<S12>/Data Store Read40' */
  memcpy(&rtb_DataStoreRead40[0], ((Float64 *)&(Fv_FirCof_TorqueSoftAdv2_SSW[0])),
         (sizeof(Float64)) << 4U);

  /* Constant: '<S12>/Constant14' */
  memcpy(&rtb_Constant14[0], ((const Float64 *)&(Cal_FirCof_NCH_Frez[0])), 12U *
         (sizeof(Float64)));

  /* DataStoreRead: '<S12>/Data Store Read39' */
  memcpy(&rtb_DataStoreRead39[0], ((Float64 *)&(Fv_FirCof_TorqueRobust2[0])),
         12U * (sizeof(Float64)));
  for (i = 0; i < 9; i++) {
    /* Constant: '<S12>/Constant1' */
    rtb_Constant1[i] = Cal_FirCof_FWR_Tab_Y[(i)];

    /* Constant: '<S12>/Constant20' */
    rtb_Constant20[i] = Cal_FirCof_FWR_Tab_X[(i)];
  }

  /* Constant: '<S12>/Constant16' */
  memcpy(&rtb_Constant16[0], ((const Float64 *)&(Cal_FirCof_TSA2_Frez2[0])),
         (sizeof(Float64)) << 3U);

  /* Constant: '<S12>/Constant32' */
  memcpy(&rtb_Constant32[0], ((const Float64 *)&(Cal_FirCof_TSA2_Frez2_SSW[0])),
         (sizeof(Float64)) << 3U);

  /* DataStoreRead: '<S12>/Data Store Read35' */
  memcpy(&rtb_DataStoreRead35[0], ((Float64 *)&(Fv_FirCof_OnCenter[0])), (sizeof
          (Float64)) << 3U);
  for (i = 0; i < 6; i++) {
    /* Constant: '<S12>/Constant27' */
    rtb_Constant27[i] = Cal_FC_FrictionStaticVehTab_X[(i)];

    /* Constant: '<S12>/Constant28' */
    rtb_Constant28[i] = Cal_FC_FrictionStaticVehTab_Y[(i)];

    /* Constant: '<S12>/Constant33' */
    rtb_Constant33[i] = Cal_HM_HarmonicTabGen_X[(i)];
  }

  for (i = 0; i < 5; i++) {
    /* Constant: '<S12>/Constant13' */
    rtb_Constant13[i] = Cal_FirCof_FWR_Frez[(i)];

    /* Constant: '<S12>/Constant24' */
    rtb_Constant24[i] = Cal_OC_HysCompVehTab_X[(i)];

    /* Constant: '<S12>/Constant25' */
    rtb_Constant25[i] = (Int8)Cal_OC_HysCompVehTab_Y[(i)];

    /* Constant: '<S12>/Constant30' */
    rtb_Constant30[i] = Cal_FC_StaticCompTorTab_X[(i)];

    /* Constant: '<S12>/Constant31' */
    rtb_Constant31[i] = Cal_FC_StaticCompTorTab_Y[(i)];

    /* Constant: '<S12>/Constant34' */
    rtb_Constant34[i] = Cal_HM_HarmonicTabGen_Y[(i)];
  }

  /* DataStoreRead: '<S12>/Data Store Read33' */
  rtb_DataStoreRead33[0] = Fv_FirCof_OffCenter[0];

  /* DataStoreRead: '<S12>/Data Store Read36' */
  rtb_DataStoreRead36[0] = Fv_FirCof_TorqueSoftAdv[0];

  /* DataStoreRead: '<S12>/Data Store Read33' */
  rtb_DataStoreRead33[1] = Fv_FirCof_OffCenter[1];

  /* DataStoreRead: '<S12>/Data Store Read36' */
  rtb_DataStoreRead36[1] = Fv_FirCof_TorqueSoftAdv[1];

  /* DataStoreRead: '<S12>/Data Store Read33' */
  rtb_DataStoreRead33[2] = Fv_FirCof_OffCenter[2];

  /* DataStoreRead: '<S12>/Data Store Read36' */
  rtb_DataStoreRead36[2] = Fv_FirCof_TorqueSoftAdv[2];

  /* DataStoreRead: '<S12>/Data Store Read33' */
  rtb_DataStoreRead33[3] = Fv_FirCof_OffCenter[3];

  /* DataStoreRead: '<S12>/Data Store Read36' */
  rtb_DataStoreRead36[3] = Fv_FirCof_TorqueSoftAdv[3];

  /* Constant: '<S12>/Constant17' */
  rtb_Constant17[0] = Cal_FirCof_TSA_Frez[0];

  /* Constant: '<S12>/Constant18' */
  rtb_Constant18[0] = Cal_FirCof_OFC_Frez[0];

  /* Constant: '<S12>/Constant19' */
  rtb_Constant19[0] = Cal_FirCof_ONC_Frez[0];

  /* Constant: '<S12>/Constant17' */
  rtb_Constant17[1] = Cal_FirCof_TSA_Frez[1];

  /* Constant: '<S12>/Constant18' */
  rtb_Constant18[1] = Cal_FirCof_OFC_Frez[1];

  /* Constant: '<S12>/Constant19' */
  rtb_Constant19[1] = Cal_FirCof_ONC_Frez[1];

  /* Constant: '<S12>/Constant12' */
  rtb_Constant12 = Cal_InitAngle_HrmComp;

  /* Constant: '<S12>/Constant15' */
  rtb_Constant15 = Cal_OC_HysComp_SatMaxTorq;

  /* Constant: '<S12>/Constant2' */
  rtb_Constant2 = Cal_AntiTug_WeakShutoff;

  /* Constant: '<S12>/Constant22' */
  rtb_Constant22 = Cal_FirRst_VsTemp2;

  /* Constant: '<S12>/Constant23' */
  rtb_Constant23 = Cal_FirRst_VsTemp1;

  /* Constant: '<S12>/Constant26' */
  rtb_Constant26 = Cal_OC_HysCompPlus;

  /* Constant: '<S12>/Constant29' */
  rtb_Constant29 = Cal_FC_StaticMaxTorq;

  /* Constant: '<S12>/Constant3' */
  rtb_Constant3 = Cal_AntiTug_WeakRecover;

  /* Constant: '<S12>/Constant36' */
  rtb_Constant36 = Cal_HM_HarmonicSelect;

  /* Constant: '<S12>/Constant4' */
  rtb_Constant4 = Cal_AntiTug_StopEnable;

  /* Constant: '<S12>/Constant5' */
  rtb_Constant5 = Cal_RotorComCoef;

  /* Constant: '<S12>/Constant6' */
  rtb_Constant6 = Cal_FOC_IDFW_Id_rev_Coef_C;

  /* Constant: '<S12>/Constant7' */
  rtb_Constant7 = Cal_FOC_IDFW_Current_Cmp_Max_C;

  /* Constant: '<S12>/Constant8' */
  rtb_Constant8 = Cal_FOC_IDFW_Current_Max_C;

  /* ModelReference: '<S4>/Variant_LimitPIDparam' */
  Variant_LimitPIDparam();

  /* DataStoreRead: '<S12>/Data Store Read' */
  rtb_DataStoreRead = Tv_PID_DI;

  /* DataStoreRead: '<S12>/Data Store Read1' */
  rtb_DataStoreRead1 = Tv_PID_DP;

  /* DataStoreRead: '<S12>/Data Store Read2' */
  rtb_DataStoreRead2 = Tv_PID_QI;

  /* DataStoreRead: '<S12>/Data Store Read3' */
  rtb_DataStoreRead3 = Tv_PID_QP;

  /* ModelReference: '<S4>/EstSteerLoad' */
  EstSteerLoad();

  /* DataStoreRead: '<S12>/Data Store Read10' */
  rtb_DataStoreRead10 = AD_PowerRelaySys;

  /* DataStoreRead: '<S12>/Data Store Read11' */
  rtb_DataStoreRead11 = AD_SampFunCheck;

  /* DataStoreRead: '<S12>/Data Store Read12' */
  rtb_DataStoreRead12 = SysTaskPreDriverCommPending;

  /* DataStoreRead: '<S12>/Data Store Read13' */
  rtb_DataStoreRead13 = Fv_RotorAng;

  /* DataStoreRead: '<S12>/Data Store Read14' */
  rtb_DataStoreRead14 = Fv_LimitedSysPower;

  /* DataStoreRead: '<S12>/Data Store Read15' */
  rtb_DataStoreRead15 = PWM_t0;

  /* DataStoreRead: '<S12>/Data Store Read16' */
  rtb_DataStoreRead16 = PWM_t1;

  /* DataStoreRead: '<S12>/Data Store Read17' */
  rtb_DataStoreRead17 = PWM_t2;

  /* DataStoreRead: '<S12>/Data Store Read18' */
  rtb_DataStoreRead18 = PWM_Section;

  /* DataStoreRead: '<S12>/Data Store Read19' */
  rtb_DataStoreRead19 = IO_UphaseLevel;

  /* DataStoreRead: '<S12>/Data Store Read20' */
  rtb_DataStoreRead20 = IO_VphaseLevel;

  /* DataStoreRead: '<S12>/Data Store Read21' */
  rtb_DataStoreRead21 = IO_WphaseLevel;

  /* DataStoreRead: '<S12>/Data Store Read22' */
  rtb_DataStoreRead22 = CAN_FLWS;

  /* DataStoreRead: '<S12>/Data Store Read23' */
  rtb_DataStoreRead23 = CAN_FRWS;

  /* DataStoreRead: '<S12>/Data Store Read24' */
  rtb_DataStoreRead24 = CAN_RLWS;

  /* DataStoreRead: '<S12>/Data Store Read25' */
  rtb_DataStoreRead25 = CAN_RRWS;

  /* DataStoreRead: '<S12>/Data Store Read26' */
  rtb_DataStoreRead26 = CAN_Et_Err;

  /* DataStoreRead: '<S12>/Data Store Read27' */
  rtb_DataStoreRead27 = CAN_Et_Status;

  /* DataStoreRead: '<S12>/Data Store Read28' */
  rtb_DataStoreRead28 = CAN_OdoMeter;

  /* DataStoreRead: '<S12>/Data Store Read29' */
  rtb_DataStoreRead29 = Fv_WheelSpeed_FL;

  /* DataStoreRead: '<S12>/Data Store Read30' */
  rtb_DataStoreRead30 = Fv_WheelSpeed_FR;

  /* DataStoreRead: '<S12>/Data Store Read31' */
  rtb_DataStoreRead31 = Fv_VsPhaseflag;

  /* DataStoreRead: '<S12>/Data Store Read34' */
  rtb_DataStoreRead34 = Fv_WheelSpeed_RL;

  /* DataStoreRead: '<S12>/Data Store Read4' */
  rtb_DataStoreRead4 = AD_PMSMCurrentU;

  /* DataStoreRead: '<S12>/Data Store Read41' */
  rtb_DataStoreRead41 = Fv_WheelSpeed_RR;

  /* DataStoreRead: '<S12>/Data Store Read5' */
  rtb_DataStoreRead5 = AD_PMSMCurrentV;

  /* DataStoreRead: '<S12>/Data Store Read6' */
  rtb_DataStoreRead6 = AD_PMSMCurrentW;

  /* DataStoreRead: '<S12>/Data Store Read7' */
  rtb_DataStoreRead7 = AD_ShadowCurrentU;

  /* DataStoreRead: '<S12>/Data Store Read8' */
  rtb_DataStoreRead8 = AD_ShadowCurrentV;

  /* DataStoreRead: '<S12>/Data Store Read9' */
  rtb_DataStoreRead9 = AD_ShadowCurrentW;
}

/* System initialize for function-call system: '<S1>/task_1ms' */
void task_1ms_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S14>/OuterLoopControlAlg' */

  /* SystemInitialize for ModelReference: '<S15>/FUN_EpsAd2Phy' */
  EPSADC_Init();

  /* SystemInitialize for ModelReference: '<S15>/FUN_BehavourModule' */
  BehavourModule_Init();

  /* SystemInitialize for ModelReference: '<S15>/FUN_AssistControl' */
  AssistControl_Init();

  /* End of SystemInitialize for SubSystem: '<S14>/OuterLoopControlAlg' */
  /* SystemInitialize for ModelReference: '<S14>/SuportFunc' */
  SuportFunc_Init();

  /* SystemInitialize for Outport: '<S7>/Tv_StrAng_Raw' */
  Tv_StrAng_Raw = 0;
}

/* Start for function-call system: '<S1>/task_1ms' */
void task_1ms_Start(void)
{
  /* Start for ModelReference: '<S14>/SuportFunc' */
  SuportFunc_Start();
}

/* Output and update for function-call system: '<S1>/task_1ms' */
void task_1ms(const INFO_EXTSENSOR *rtu_sensor, const INFO_INNERSAMPLE
              *rtu_sample)
{
  /* SignalConversion: '<S7>/cpy16' */
  AD_I2D5Ref1 = rtu_sample->vCO1;

  /* SignalConversion: '<S7>/cpy32' */
  AD_I2D5Ref2 = rtu_sample->vCO2;

  /* SignalConversion: '<S7>/cpy17' */
  AD_TorqueSenPower = rtu_sample->vTA;

  /* SignalConversion: '<S7>/cpy20' */
  AD_RotorSenPower = rtu_sample->vMR;

  /* SignalConversion: '<S7>/cpy21' */
  AD_RotorMainMid1 = rtu_sample->cRM1;

  /* SignalConversion: '<S7>/cpy33' */
  AD_RotorMainMid2 = rtu_sample->cRM2;

  /* SignalConversion: '<S7>/cpy22' */
  AD_RotorMainSin1 = rtu_sensor->sinP;

  /* SignalConversion: '<S7>/cpy23' */
  AD_RotorMainCos1 = rtu_sensor->cosP;

  /* SignalConversion: '<S7>/cpy24' */
  AD_RotorSubSin1 = rtu_sensor->sinN;

  /* SignalConversion: '<S7>/cpy25' */
  AD_RotorSubCos1 = rtu_sensor->cosN;

  /* SignalConversion: '<S7>/cpy31' */
  AD_RotorMainSin2 = rtu_sensor->psinP;

  /* SignalConversion: '<S7>/cpy28' */
  AD_RotorMainCos2 = rtu_sensor->pcosP;

  /* SignalConversion: '<S7>/cpy29' */
  AD_RotorSubSin2 = rtu_sensor->psinN;

  /* SignalConversion: '<S7>/cpy30' */
  AD_RotorSubCos2 = rtu_sensor->pcosN;

  /* SignalConversion: '<S7>/cpy18' */
  IO_PredriverState1 = rtu_sample->drvst1;

  /* SignalConversion: '<S7>/cpy19' */
  IO_PredriverState2 = rtu_sample->drvst2;

  /* SignalConversion: '<S7>/cpy4' */
  IOC_Tor1Frez = rtu_sensor->frezT1;

  /* SignalConversion: '<S7>/cpy6' */
  IOC_Tor2Frez = rtu_sensor->frezT2;

  /* ModelReference: '<S14>/SuportFunc' */
  SuportFunc();

  /* SignalConversion: '<S7>/cpy1' */
  AD_MainTorque = rtu_sensor->mainT;

  /* SignalConversion: '<S7>/cpy2' */
  AD_SubTorque = rtu_sensor->subT;

  /* SignalConversion: '<S7>/cpy3' */
  IOC_Tor1Duty = rtu_sensor->dutyT1;

  /* SignalConversion: '<S7>/cpy5' */
  IOC_Tor2Duty = rtu_sensor->dutyT2;

  /* SignalConversion: '<S7>/cpy7' */
  CAN_VehSpd = rtu_sample->vhs;

  /* SignalConversion: '<S7>/cpy14' */
  CAN_Vs_Err = rtu_sample->vhs_err;

  /* SignalConversion: '<S7>/cpy8' */
  CAN_Reverse = rtu_sample->rvr;

  /* SignalConversion: '<S7>/cpy9' */
  CAN_EngSpd = rtu_sample->ens;

  /* SignalConversion: '<S7>/cpy15' */
  CAN_Es_Err = rtu_sample->ens_err;

  /* SignalConversion: '<S7>/cpy10' */
  IOC_AngpDuty = rtu_sensor->dutyAP;

  /* SignalConversion: '<S7>/cpy11' */
  IOC_AngpFrez = rtu_sensor->frezAP;

  /* SignalConversion: '<S7>/cpy12' */
  IOC_AngsDuty = rtu_sensor->dutyAS;

  /* SignalConversion: '<S7>/cpy13' */
  IOC_AngsFrez = rtu_sensor->frezAS;

  /* Outputs for Atomic SubSystem: '<S14>/OuterLoopControlAlg' */

  /* ModelReference: '<S15>/FUN_EpsAd2Phy' */
  EPSADC();

  /* ModelReference: '<S15>/FUN_BehavourModule' */
  BehavourModule();

  /* ModelReference: '<S15>/FUN_AssistControl' */
  AssistControl();

  /* End of Outputs for SubSystem: '<S14>/OuterLoopControlAlg' */

  /* SignalConversion: '<S7>/cpy27' */
  AD_InterMCUTemp = rtu_sensor->tempc;

  /* SignalConversion: '<S7>/cpy26' */
  AD_InterVolt1d2 = rtu_sample->v1d2;

  /* ModelReference: '<S14>/FaultDiagRapid' */
  FaultDiagRapid();
}

/* Output and update for function-call system: '<S1>/task_10_0ms' */
void task_10_0ms(const INFO_INNERSAMPLE *rtu_sample)
{
  /* SignalConversion: '<S5>/cpy0' */
  AD_PowerSys = rtu_sample->vBS;

  /* SignalConversion: '<S5>/cpy1' */
  CAN_IG_Status = rtu_sample->ign;

  /* ModelReference: '<S5>/PowerSupplyProcess' */
  PowerSupplyProcess();
}

/* Output and update for function-call system: '<S1>/task_10_5ms' */
void task_10_5ms(const INFO_INNERSAMPLE *rtu_sample)
{
  /* SignalConversion: '<S6>/cpy0' */
  AD_IgnitionSys = rtu_sample->vIG;

  /* ModelReference: '<S13>/SteerAngleCheck' */
  SteerAngleCheck();

  /* ModelReference: '<S13>/SleepLogic' */
  SleepLogic();
}

/* System initialize for function-call system: '<S1>/task_20_0ms' */
void task_20_0ms_Init(void)
{
  /* SystemInitialize for ModelReference: '<S8>/DTC_CANCheck' */
  DTC_CANCheck_Init();
}

/* Output and update for function-call system: '<S1>/task_20_0ms' */
void task_20_0ms(void)
{
  /* ModelReference: '<S8>/DTC_CANCheck' */
  DTC_CANCheck();
}

/* Output and update for function-call system: '<S1>/task_100ms' */
void task_100ms(const INFO_EXTSENSOR *rtu_sensor)
{
  /* SignalConversion: '<S3>/cpy0' */
  AD_TempSys = rtu_sensor->temp1;

  /* ModelReference: '<S3>/TemperatureCheck' */
  TemperatureCheck();

  /* ModelReference: '<S3>/AngleOffsetComp' */
  AngleOffsetComp();

  /* ModelReference: '<S3>/DesignCurveCalcFun' */
  DesignCurveCalcFun();
}

/* Function for Chart: '<S1>/Scheduler' */
static void chartstep_c2_eps_controlAlgorit(const Int32 *sfEvent)
{
  /* Chart: '<S1>/Scheduler' incorporates:
   *  Inport: '<Root>/ExternSensor'
   *  Inport: '<Root>/InternalSample'
   */
  /* During: ControlAlgorithm_Atomic/Scheduler */
  if (((UInt32)rtDW_l5cf.bitsForTID0.is_active_c2_eps_controlAlgorit) == 0U) {
    /* Entry: ControlAlgorithm_Atomic/Scheduler */
    rtDW_l5cf.bitsForTID0.is_active_c2_eps_controlAlgorit = 1;

    /* Entry Internal: ControlAlgorithm_Atomic/Scheduler */
    /* Entry 'Shedule': '<S2>:65' */
    /* Event: '<S2>:64' */
    /* Entry Internal 'Shedule': '<S2>:65' */
  } else {
    /* During 'Shedule': '<S2>:65' */
    /* During 'AsynchronousScheduler1': '<S2>:3' */
    if ((*sfEvent) == ((Int32)event_Intrpt1)) {
      /* Outputs for Function Call SubSystem: '<S1>/task_100us' */
      /* Transition: '<S2>:5' */
      /* Event: '<S2>:7' */
      task_100us();

      /* End of Outputs for SubSystem: '<S1>/task_100us' */
      /* Transition: '<S2>:62' */
    }

    /* During 'AsynchronousScheduler2': '<S2>:15' */
    if ((*sfEvent) == ((Int32)event_Intrpt2)) {
      /* Outputs for Function Call SubSystem: '<S1>/task_1ms' */
      /* Transition: '<S2>:13' */
      /* Event: '<S2>:8' */
      task_1ms(&rtU.ExternSensor, &rtU.InternalSample);

      /* End of Outputs for SubSystem: '<S1>/task_1ms' */
      if (((Int32)glbMainIsrMilliSecondFlag) < 5) {
        /* Transition: '<S2>:20' */
        glbMainIsrMilliSecondFlag = (UInt16)((Int32)(((Int32)
          glbMainIsrMilliSecondFlag) + 1));

        /* Transition: '<S2>:40' */
      } else {
        /* Transition: '<S2>:22' */
        glbMainIsrMilliSecondFlag = 0;
        if (((Int32)Timer5_0ms) == 0) {
          /* Transition: '<S2>:24' */
          /* Event: '<S2>:10' */
          Timer5_0ms = 1;
        } else {
          /* Transition: '<S2>:25' */
        }

        if (((Int32)Timer10_0ms) == 0) {
          /* Outputs for Function Call SubSystem: '<S1>/task_10_0ms' */
          /* Transition: '<S2>:27' */
          /* Event: '<S2>:16' */
          task_10_0ms(&rtU.InternalSample);

          /* End of Outputs for SubSystem: '<S1>/task_10_0ms' */
          Timer10_0ms = 2;
        } else {
          /* Transition: '<S2>:28' */
        }

        if (((Int32)Timer10_5ms) == 0) {
          /* Outputs for Function Call SubSystem: '<S1>/task_10_5ms' */
          /* Transition: '<S2>:42' */
          /* Event: '<S2>:36' */
          task_10_5ms(&rtU.InternalSample);

          /* End of Outputs for SubSystem: '<S1>/task_10_5ms' */
          Timer10_5ms = 2;
        } else {
          /* Transition: '<S2>:43' */
        }

        if (((Int32)Timer20_0ms) == 0) {
          /* Outputs for Function Call SubSystem: '<S1>/task_20_0ms' */
          /* Transition: '<S2>:45' */
          /* Event: '<S2>:37' */
          task_20_0ms();

          /* End of Outputs for SubSystem: '<S1>/task_20_0ms' */
          Timer20_0ms = 4;
        } else {
          /* Transition: '<S2>:46' */
        }

        if (((Int32)Timer20_10ms) == 0) {
          /* Transition: '<S2>:48' */
          /* Event: '<S2>:38' */
          Timer20_10ms = 4;
        } else {
          /* Transition: '<S2>:49' */
        }

        if (((Int32)Timer100ms) == 0) {
          /* Outputs for Function Call SubSystem: '<S1>/task_100ms' */
          /* Transition: '<S2>:67' */
          /* Event: '<S2>:68' */
          task_100ms(&rtU.ExternSensor);

          /* End of Outputs for SubSystem: '<S1>/task_100ms' */
          Timer100ms = 20;
        } else {
          /* Transition: '<S2>:52' */
        }

        /* Transition: '<S2>:30' */
        Timer5_0ms = (UInt16)((Int32)(((Int32)Timer5_0ms) - 1));
        Timer10_0ms = (UInt16)((Int32)(((Int32)Timer10_0ms) - 1));
        Timer10_5ms = (UInt16)((Int32)(((Int32)Timer10_5ms) - 1));
        Timer20_0ms = (UInt16)((Int32)(((Int32)Timer20_0ms) - 1));
        Timer20_10ms = (UInt16)((Int32)(((Int32)Timer20_10ms) - 1));
        Timer100ms = (UInt16)((Int32)(((Int32)Timer100ms) - 1));
      }
    }
  }

  /* End of Chart: '<S1>/Scheduler' */
}

/* System initialize for trigger system: '<S1>/Scheduler' */
void Scheduler_Init(void)
{
  Timer10_5ms = 1;
  Timer20_10ms = 2;

  /* SystemInitialize for Function Call SubSystem: '<S1>/task_100us' */
  task_100us_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/task_100us' */

  /* SystemInitialize for Function Call SubSystem: '<S1>/task_1ms' */
  task_1ms_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/task_1ms' */

  /* SystemInitialize for Function Call SubSystem: '<S1>/task_20_0ms' */
  task_20_0ms_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/task_20_0ms' */
}

/* Start for trigger system: '<S1>/Scheduler' */
void Scheduler_Start(void)
{
  /* Start for Function Call SubSystem: '<S1>/task_1ms' */
  task_1ms_Start();

  /* End of Start for SubSystem: '<S1>/task_1ms' */
}

/* Output and update for trigger system: '<S1>/Scheduler' */
void Scheduler(void)
{
  Int32 sfEvent;
  Bool zcEvent_idx_0;
  Bool zcEvent_idx_1;

  /* Chart: '<S1>/Scheduler' incorporates:
   *  TriggerPort: '<S2>/input events'
   */
  zcEvent_idx_0 = ((((Int32)rtDW_l5cf.Intrpt1) > 0) && (((UInt32)
    rtPrevZCX_pwxn.Scheduler_Trig_ZCE[0]) != POS_ZCSIG));
  zcEvent_idx_1 = ((((Int32)rtDW_l5cf.Intrpt2) > 0) && (((UInt32)
    rtPrevZCX_pwxn.Scheduler_Trig_ZCE[1]) != POS_ZCSIG));
  if (zcEvent_idx_0 || zcEvent_idx_1) {
    /* Gateway: ControlAlgorithm_Atomic/Scheduler */
    if (zcEvent_idx_0) {
      /* Event: '<S2>:11' */
      sfEvent = (Int32)event_Intrpt1;
      chartstep_c2_eps_controlAlgorit(&sfEvent);
    }

    if (zcEvent_idx_1) {
      /* Event: '<S2>:12' */
      sfEvent = (Int32)event_Intrpt2;
      chartstep_c2_eps_controlAlgorit(&sfEvent);
    }
  }

  rtPrevZCX_pwxn.Scheduler_Trig_ZCE[0] = (ZCSigState)((((Int32)rtDW_l5cf.Intrpt1)
    > 0) ? 1 : 0);
  rtPrevZCX_pwxn.Scheduler_Trig_ZCE[1] = (ZCSigState)((((Int32)rtDW_l5cf.Intrpt2)
    > 0) ? 1 : 0);
}

/* Model step function */
void eps_controlAlgorithm_step(void)
{
  Float64 rtb_u000HzISR;

  /* DiscretePulseGenerator: '<S1>/10000 Hz ISR' */
  rtb_u000HzISR = ((((Float64)rtDW_l5cf.clockTickCounter) < 1.0) &&
                   (rtDW_l5cf.clockTickCounter >= 0)) ? 1.0 : 0.0;
  if (((Float64)rtDW_l5cf.clockTickCounter) >= (2.0 - 1.0)) {
    rtDW_l5cf.clockTickCounter = 0;
  } else {
    rtDW_l5cf.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/10000 Hz ISR' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtDW_l5cf.Intrpt1 = (UInt8)rtb_u000HzISR;

  /* DiscretePulseGenerator: '<S1>/1000 Hz ISR' */
  rtb_u000HzISR = ((((Float64)rtDW_l5cf.clockTickCounter_e42y) < 10.0) &&
                   (rtDW_l5cf.clockTickCounter_e42y >= 0)) ? 1.0 : 0.0;
  if (((Float64)rtDW_l5cf.clockTickCounter_e42y) >= (20.0 - 1.0)) {
    rtDW_l5cf.clockTickCounter_e42y = 0;
  } else {
    rtDW_l5cf.clockTickCounter_e42y++;
  }

  /* End of DiscretePulseGenerator: '<S1>/1000 Hz ISR' */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  rtDW_l5cf.Intrpt2 = (UInt8)rtb_u000HzISR;

  /* Chart: '<S1>/Scheduler' */
  Scheduler();
}

/* Model initialize function */
void eps_controlAlgorithm_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  AD_MainTorque = ((UInt16)5000U);
  AD_SubTorque = ((UInt16)5000U);
  Fv_ModeCoef = 16384;

  /* Model Initialize function for ModelReference Block: '<S14>/FaultDiagRapid' */
  FaultDiagRapid_initialize();

  /* Model Initialize function for ModelReference Block: '<S8>/DTC_CANCheck' */
  DTC_CANCheck_initialize();

  /* Start for Chart: '<S1>/Scheduler' */
  Scheduler_Start();

  /* Start for DataStoreMemory: '<Root>/Tv_PID_DI' */
  Tv_PID_DI = ((UInt16)18U);

  /* Start for DataStoreMemory: '<Root>/Tv_PID_DP' */
  Tv_PID_DP = ((UInt16)1000U);

  /* Start for DataStoreMemory: '<Root>/Tv_PID_QI' */
  Tv_PID_QI = ((UInt16)18U);

  /* Start for DataStoreMemory: '<Root>/Tv_PID_QP' */
  Tv_PID_QP = ((UInt16)1000U);

  /* Start for DataStoreMemory: '<Root>/Tv_SE_LeftMaxAng' */
  Tv_SE_LeftMaxAng = -Cal_SE_DefaultEndAng;;

  /* Start for DataStoreMemory: '<Root>/Tv_SE_RightMaxAng' */
  Tv_SE_RightMaxAng = Cal_SE_DefaultEndAng;
  rtPrevZCX_pwxn.Scheduler_Trig_ZCE[0] = POS_ZCSIG;
  rtPrevZCX_pwxn.Scheduler_Trig_ZCE[1] = POS_ZCSIG;

  /* SystemInitialize for Chart: '<S1>/Scheduler' */
  Scheduler_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
