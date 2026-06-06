/*
 * File: eps_controlAlgorithm.h
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:08:34 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_eps_controlAlgorithm_h_
#define RTW_HEADER_eps_controlAlgorithm_h_
#include <string.h>
#ifndef eps_controlAlgorithm_COMMON_INCLUDES_
# define eps_controlAlgorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                               /* eps_controlAlgorithm_COMMON_INCLUDES_ */

#include "eps_controlAlgorithm_types.h"

/* Child system includes */
#define TemperatureCheck_MDLREF_HIDE_CHILD_
#include "TemperatureCheck.h"
#define AngleOffsetComp_MDLREF_HIDE_CHILD_
#include "AngleOffsetComp.h"
#define DesignCurveCalcFun_MDLREF_HIDE_CHILD_
#include "DesignCurveCalcFun.h"
#define DTC_CANCheck_MDLREF_HIDE_CHILD_
#include "DTC_CANCheck.h"
#define SteerAngleCheck_MDLREF_HIDE_CHILD_
#include "SteerAngleCheck.h"
#define SleepLogic_MDLREF_HIDE_CHILD_
#include "SleepLogic.h"
#define PowerSupplyProcess_MDLREF_HIDE_CHILD_
#include "PowerSupplyProcess.h"
#define SuportFunc_MDLREF_HIDE_CHILD_
#include "SuportFunc.h"
#define FaultDiagRapid_MDLREF_HIDE_CHILD_
#include "FaultDiagRapid.h"
#define EPSADC_MDLREF_HIDE_CHILD_
#include "EPSADC.h"
#define BehavourModule_MDLREF_HIDE_CHILD_
#include "BehavourModule.h"
#define AssistControl_MDLREF_HIDE_CHILD_
#include "AssistControl.h"
#define Variant_LimitPIDparam_MDLREF_HIDE_CHILD_
#include "Variant_LimitPIDparam.h"
#define EstSteerLoad_MDLREF_HIDE_CHILD_
#include "EstSteerLoad.h"

/* Includes for objects with custom storage classes. */
#include "SimGlobal.h"
#include "SimDiagMacro.h"
#include "SimDiagMacroCAN.h"
#include "SimDiagMacroSupport.h"
#include "GlobalVar.h"
#include "GlobalVarCAN.h"
#include "CalVar.h"
#include "CalVarSupport.h"
#include "GlobalVarSupport.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  Int32 clockTickCounter;              /* '<S1>/10000 Hz ISR' */
  Int32 clockTickCounter_e42y;         /* '<S1>/1000 Hz ISR' */
  struct {
    UInt32 is_active_c2_eps_controlAlgorit:1;/* '<S1>/Scheduler' */
  } bitsForTID0;

  UInt8 Intrpt1;                       /* '<S1>/Data Type Conversion' */
  UInt8 Intrpt2;                       /* '<S1>/Data Type Conversion1' */
} DW_l5cf;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Scheduler_Trig_ZCE[2];    /* '<S1>/Scheduler' */
} PrevZCX_pwxn;

/* External inputs (root inport signals with default storage) */
typedef struct {
  INFO_EXTSENSOR ExternSensor;         /* '<Root>/ExternSensor' */
  INFO_INNERSAMPLE InternalSample;     /* '<Root>/InternalSample' */
} ExtU_csev;

/* Block signals and states (default storage) */
extern DW_l5cf rtDW_l5cf;

/* External inputs (root inport signals with default storage) */
extern ExtU_csev rtU;

/* Model entry point functions */
extern void eps_controlAlgorithm_initialize(void);
extern void eps_controlAlgorithm_step(void);

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Localizable */
extern volatile UInt16 CAN_LostRecCounter[CANBUS_NUM];

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
 * '<Root>' : 'eps_controlAlgorithm'
 * '<S1>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic'
 * '<S2>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/Scheduler'
 * '<S3>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_100ms'
 * '<S4>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_100us'
 * '<S5>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_10_0ms'
 * '<S6>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_10_5ms'
 * '<S7>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_1ms'
 * '<S8>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_20_0ms'
 * '<S9>'   : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_20_10ms'
 * '<S10>'  : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_5ms'
 * '<S11>'  : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_init'
 * '<S12>'  : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_100us/Subsystem'
 * '<S13>'  : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_10_5ms/Anglecheck_SleepLogic'
 * '<S14>'  : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_1ms/OuterLoopControl'
 * '<S15>'  : 'eps_controlAlgorithm/ControlAlgorithm_Atomic/task_1ms/OuterLoopControl/OuterLoopControlAlg'
 */

/*-
 * Requirements for '<Root>': eps_controlAlgorithm
 */
#endif                                 /* RTW_HEADER_eps_controlAlgorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
