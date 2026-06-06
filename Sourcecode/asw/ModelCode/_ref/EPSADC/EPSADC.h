/*
 * File: EPSADC.h
 *
 * Code generated for Simulink model 'EPSADC'.
 *
 * Model version                  : 1.1182
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Sep 16 11:42:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EPSADC_h_
#define RTW_HEADER_EPSADC_h_
#ifndef EPSADC_COMMON_INCLUDES_
# define EPSADC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* EPSADC_COMMON_INCLUDES_ */

#include "EPSADC_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "SimDiagMacroCAN.h"
#include "GlobalVar.h"
#include "CalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S24>/calc_anglecheck' */
#ifndef EPSADC_MDLREF_HIDE_CHILD_
#if MACRO_STEERANGLE_SELECT == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

typedef struct {
  Int32 calc_rtr;                      /* '<S26>/anglecheck' */
  Int32 calc_sum;                      /* '<S26>/anglecheck' */
  Int32 calc_rtr_init;                 /* '<S26>/anglecheck' */
  struct {
    UInt32 is_c15_EPSADC:2;            /* '<S26>/anglecheck' */
    UInt32 is_active_c15_EPSADC:1;     /* '<S26>/anglecheck' */
    UInt32 calc_valid_flag:1;          /* '<S26>/anglecheck' */
  } bitsForTID0;

  UInt16 calc_delay_cnt;               /* '<S26>/anglecheck' */
  UInt16 calc_sum_cnt;                 /* '<S26>/anglecheck' */
} EPSADC_DW_calc_anglecheck;

#endif
#endif                                 /*EPSADC_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S5>/EpsAngleConv_Sensor' */
#ifndef EPSADC_MDLREF_HIDE_CHILD_
#if MACRO_STEERANGLE_SELECT == 0

typedef struct {

#if STRANG_RTRANG_DIFF_TYPEMODE == 1

  EPSADC_DW_calc_anglecheck calc_anglecheck_k0uh;/* '<S24>/calc_anglecheck' */

#define EPSADC_DW_EPSANGLECONV_SENSOR_VARIANT_EXISTS
#endif

  Int32 mergec;                        /* '<S12>/Merge' */
  Int32 anginit;                       /* '<S21>/Subtract1' */
  Int32 Delay1_DSTATE;                 /* '<S31>/Delay1' */
  Int32 Delay_DSTATE;                  /* '<S31>/Delay' */
  Int32 sumoutlast;                    /* '<S30>/anglepsum' */
  Int32 modout;                        /* '<S30>/anglepsum' */
  struct {
    UInt32 is_c9_EPSADC:2;             /* '<S14>/angle_shedule' */
    UInt32 is_Decode:2;                /* '<S14>/angle_shedule' */
    UInt32 is_active_c9_EPSADC:1;      /* '<S14>/angle_shedule' */
    UInt32 jump:1;                     /* '<S14>/angle_shedule' */
  } bitsForTID0;

  Int16 out;                           /* '<S44>/esratelimit' */
  Int16 pang;                          /* '<S11>/Min' */
  Int16 sang;                          /* '<S11>/Min1' */
  Int16 panglast;                      /* '<S30>/anglepsum' */
  UInt16 decode_cnt;                   /* '<S14>/angle_shedule' */
  UInt16 mix_err_cnt;                  /* '<S14>/angle_shedule' */
  UInt16 follow_err_cnt;               /* '<S14>/angle_shedule' */
  UInt16 default_delaycnt;             /* '<S14>/angle_shedule' */
  UInt8 step;                          /* '<S14>/angle_shedule' */
  Bool stap;                           /* '<S11>/apst' */
  Bool stas;                           /* '<S11>/asst' */
  Bool stsup;                          /* '<S11>/apst1' */
  Bool Delay_DSTATE_krih;              /* '<S30>/Delay' */
} EPSADC_DW_EpsAngleConv_Sensor;

#endif
#endif                                 /*EPSADC_MDLREF_HIDE_CHILD_*/
typedef struct {
  /* Computed Parameter: tsc_looktable_cmd1_maxIndex
   * Referenced by: '<S194>/tsc_looktable_cmd1'
   */
  UInt32 tsc_looktable_cmd1_maxIndex[2];
} ConstP_EPSADC_dfsm;
/* Block signals and states (default storage) for model 'EPSADC' */
#ifndef EPSADC_MDLREF_HIDE_CHILD_

typedef struct {

#if MACRO_STEERANGLE_SELECT == 0

  EPSADC_DW_EpsAngleConv_Sensor EpsAngleConv_Sensor;/* '<S5>/EpsAngleConv_Sensor' */

#define EPSADC_DW_FWU4_VARIANT_EXISTS
#endif

  Float64 y[6];                        /* '<S72>/filter_pfilter' */
  Float64 notchfilter_states[2];       /* '<S71>/notchfilter' */
  Float64 notchfilter_denStates[2];    /* '<S71>/notchfilter' */
  Float64 notchfilter_tmp;             /* '<S71>/notchfilter' */
  Int32 out;                           /* '<S52>/VsErrorFix' */
  Int32 last_ang;                      /* '<S4>/DiffCalc' */
  Int32 out_last_y;                    /* '<S4>/DiffCalc' */
  Int32 out_last_x;                    /* '<S4>/DiffCalc' */
  UInt32 m_bpIndex;                    /* '<S67>/vsded' */
  UInt32 m_bpIndex_eyvb;               /* '<S72>/revfirfrez' */
  UInt32 m_bpIndex_nvh0;               /* '<S72>/vsfircoef' */
  UInt32 m_bpIndex_bsym[2];  
  struct {
    UInt32 trg_valid_flag:1;           /* '<S4>/DiffCalc' */
    UInt32 first_flag:1;               /* '<S4>/DiffCalc' */
  } bitsForTID0;

  Int16 out_fl2w;                      /* '<S56>/vsratelimit' */
  Int16 Vsfir;                         /* '<S55>/Switch' */
  Int16 Diff;                          /* '<S60>/Diff' */
  Int16 UnitDelay_DSTATE;              /* '<S55>/Unit Delay' */
  Int16 UnitDelay2_DSTATE;             /* '<S55>/Unit Delay2' */
  UInt16 out_jbcr;                     /* '<S53>/esratelimit' */
  UInt16 counter;                      /* '<S2>/EpsCANConv_SheduleCounter' */
  UInt16 trg_valid_cnt;                /* '<S4>/DiffCalc' */
  UInt8 level;                         /* '<S67>/FilterVsLevel' */
} EPSADC_DW_fwu4;

#endif                                 /*EPSADC_MDLREF_HIDE_CHILD_*/

extern void EPSADC_Init(void);
extern void EPSADC(void);

#ifndef EPSADC_MDLREF_HIDE_CHILD_

extern void EPSADC_filter_pfilter(Float64 rtu_f, Float64 rtu_c, Float64 rty_y[6]);

#if MACRO_STEERANGLE_SELECT == 1

extern void EPSADC_EpsAngleConv_CAN(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 1

extern void EPSADC_calc_anglecheck(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0 && STRANG_RTRANG_DIFF_TYPEMODE == 0

extern void EPSADC_calc_anglecheck_zero(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0

extern void EPSADC_EpsAngleConv_AngState(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0

extern void EPSADC_anglemix(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0

extern void EPSADC_calc_strangle(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0

extern void EPSADC_EpsAngleConv_AngleDecode(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0

extern void EPSAD_EpsAngleConv_HellaRevCalc(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0

extern void EPS_EpsAngleConv_MixFollowState(void);

#endif

#if MACRO_STEERANGLE_SELECT == 0

extern void EPSA_EpsAngleConv_SteeringAngle(void);

#endif

extern void EPS_EpsAngleConv_LowRevSyn_Init(void);
extern void EPSADC_EpsAngleConv_LowRevSyn(void);
extern void EPSADC_EpsAngleConv_SteerRevAcc(void);
extern void EPSADC_EpsAngleConv_Init(void);
extern void EPSADC_EpsAngleConv(void);
extern void EPSADC_EpsCANConv_EsCalc(void);
extern void EPSADC_EpsCANConv_VsCalc(void);
extern void EPSADC_EpsCANConv_VsJumpFir(void);
extern void EPSADC_EpsCANConv_VsRateLimit(void);
extern void EPSADC_EpsCANConv_VsErrProcess(void);
extern void EPSADC_EpsCANConv(void);
extern void EPSAD_EpsTorqueConv_AdvanceCalc(void);
extern void EPSADC_TorqueCalc_BasicHandT(void);
extern void EPSADC_TorqueCalc_NotchFir_Init(void);
extern void EPSADC_TorqueCalc_NotchFir(void);
extern void EPSADC_TorqueCalc_VsCf(void);
extern void EPSADC_EpsTorqueConv_Calc_Init(void);
extern void EPSADC_EpsTorqueConv_Calc(void);
extern void EPSA_EpsTorqueConv_DeadOut_Init(void);
extern void EPSADC_EpsTorqueConv_DeadOut(void);
extern void EPSADC_EpsTorqueConv_SoftAdv(void);
extern void EPSA_EpsTorqueConv_StableFilter(void);
extern void EPSADC_EpsTorqueConv_Init(void);
extern void EPSADC_EpsTorqueConv(void);

#endif                                 /*EPSADC_MDLREF_HIDE_CHILD_*/

#ifndef EPSADC_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern EPSADC_DW_fwu4 EPSADCrtDW;
extern const ConstP_EPSADC_dfsm rtConstP_EPSADC_dfsm;
#endif                                 /*EPSADC_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'EPSADC'
 * '<S1>'   : 'EPSADC/EpsAngleConv'
 * '<S2>'   : 'EPSADC/EpsCANConv'
 * '<S3>'   : 'EPSADC/EpsTorqueConv'
 * '<S4>'   : 'EPSADC/EpsAngleConv/EpsAngleConv_LowRevSyn'
 * '<S5>'   : 'EPSADC/EpsAngleConv/EpsAngleConv_Select'
 * '<S6>'   : 'EPSADC/EpsAngleConv/EpsAngleConv_SteerRevAcc'
 * '<S7>'   : 'EPSADC/EpsAngleConv/EpsAngleConv_LowRevSyn/DiffCalc'
 * '<S8>'   : 'EPSADC/EpsAngleConv/EpsAngleConv_LowRevSyn/Saturation Dynamic'
 * '<S9>'   : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_CAN'
 * '<S10>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor'
 * '<S11>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngState'
 * '<S12>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode'
 * '<S13>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc'
 * '<S14>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_MixFollowState'
 * '<S15>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle'
 * '<S16>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngState/Compare To Constant'
 * '<S17>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglefollow'
 * '<S18>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/angleinit'
 * '<S19>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix'
 * '<S20>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit'
 * '<S21>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test'
 * '<S22>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/anglecof'
 * '<S23>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/anglemix/anglemix_test/angoffset'
 * '<S24>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck'
 * '<S25>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_strangle'
 * '<S26>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck/calc_anglecheck'
 * '<S27>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck/calc_anglecheck_zero'
 * '<S28>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_anglecheck/calc_anglecheck/anglecheck'
 * '<S29>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_AngleDecode/stranglimit/calc_strangle/Saturation Dynamic'
 * '<S30>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_diff'
 * '<S31>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_rev'
 * '<S32>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_diff/Compare To Constant'
 * '<S33>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_diff/Compare To Constant1'
 * '<S34>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_diff/anglepsum'
 * '<S35>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_rev/Dead Zone Dynamic'
 * '<S36>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_HellaRevCalc/HellaRevCalc_rev/Saturation Dynamic'
 * '<S37>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_MixFollowState/angle_shedule'
 * '<S38>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/ReadMidSt'
 * '<S39>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/ReadVsSt'
 * '<S40>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/else1'
 * '<S41>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/else2'
 * '<S42>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/finalanglimit'
 * '<S43>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/if1'
 * '<S44>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/if2'
 * '<S45>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/ReadMidSt/Compare To Constant'
 * '<S46>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/ReadMidSt/Compare To Constant1'
 * '<S47>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/ReadVsSt/Compare To Constant'
 * '<S48>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/ReadVsSt/Compare To Constant1'
 * '<S49>'  : 'EPSADC/EpsAngleConv/EpsAngleConv_Select/EpsAngleConv_Sensor/EpsAngleConv_SteeringAngle/if2/esratelimit'
 * '<S50>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule'
 * '<S51>'  : 'EPSADC/EpsCANConv/EpsCANConv_SheduleCounter'
 * '<S52>'  : 'EPSADC/EpsCANConv/EpsCANConv_VsErrProcess'
 * '<S53>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_EsCalc'
 * '<S54>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsCalc'
 * '<S55>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsJumpFir'
 * '<S56>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsRateLimit'
 * '<S57>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_EsCalc/Compare To Constant'
 * '<S58>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_EsCalc/esratelimit'
 * '<S59>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsCalc/Compare To Zero'
 * '<S60>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsCalc/Dead Zone Dynamic'
 * '<S61>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsJumpFir/Compare To Constant'
 * '<S62>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsJumpFir/Compare To Constant1'
 * '<S63>'  : 'EPSADC/EpsCANConv/EpsCANConv_CAN_DataShedule/EpsCANConv_VsRateLimit/vsratelimit'
 * '<S64>'  : 'EPSADC/EpsCANConv/EpsCANConv_VsErrProcess/VsErrorFix'
 * '<S65>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_AdvanceCalc'
 * '<S66>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_Calc'
 * '<S67>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_DeadOut'
 * '<S68>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_SoftAdv'
 * '<S69>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_StableFilter'
 * '<S70>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_Calc/TorqueCalc_BasicHandT'
 * '<S71>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_Calc/TorqueCalc_NotchFir'
 * '<S72>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_Calc/TorqueCalc_VsCf'
 * '<S73>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_Calc/TorqueCalc_NotchFir/strip'
 * '<S74>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_Calc/TorqueCalc_VsCf/Saturation Dynamic'
 * '<S75>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_Calc/TorqueCalc_VsCf/filter_pfilter'
 * '<S76>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_DeadOut/DeadZone'
 * '<S77>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_DeadOut/FilterVsLevel'
 * '<S78>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_SoftAdv/Call_TorqueSoftAdv'
 * '<S79>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_SoftAdv/Call_TorqueSoftAdv/fixdt1q10'
 * '<S80>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_StableFilter/Call_ToruqeStableFilter'
 * '<S81>'  : 'EPSADC/EpsTorqueConv/EpsTorqueConv_StableFilter/Call_ToruqeStableFilter/fixdt1q10'
 */

/*-
 * Requirements for '<Root>': EPSADC
 */
#endif                                 /* RTW_HEADER_EPSADC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
