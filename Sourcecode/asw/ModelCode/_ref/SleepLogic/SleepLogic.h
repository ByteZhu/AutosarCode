/*
 * File: SleepLogic.h
 *
 * Code generated for Simulink model 'SleepLogic'.
 *
 * Model version                  : 1.1132
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Aug  9 15:01:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SleepLogic_h_
#define RTW_HEADER_SleepLogic_h_
#ifndef SleepLogic_COMMON_INCLUDES_
# define SleepLogic_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SleepLogic_COMMON_INCLUDES_ */

#include "SleepLogic_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "GlobalVar.h"
#include "CalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for model 'SleepLogic' */
#ifndef SleepLogic_MDLREF_HIDE_CHILD_

typedef struct {
  struct {
    UInt32 is_Logic:3;                 /* '<S1>/SleepLogicStatus' */
    UInt32 is_Timer:2;                 /* '<S1>/SleepLogicStatus' */
    UInt32 is_IGHigh:2;                /* '<S1>/SleepLogicStatus' */
    UInt32 is_IGLow:2;                 /* '<S1>/SleepLogicStatus' */
    UInt32 is_active_c2_SleepLogic:1;  /* '<S1>/SleepLogicStatus' */
    UInt32 IGkey:1;                    /* '<S1>/SleepLogicStatus' */
    UInt32 IGkeyDown:1;                /* '<S1>/SleepLogicStatus' */
  } bitsForTID0;

  UInt16 ShutDownDelayTmrCnt;          /* '<S1>/SleepLogicStatus' */
  UInt16 SleepLogicTmrCntk;            /* '<S1>/SleepLogicStatus' */
  UInt16 SleepLogicTmrCntj;            /* '<S1>/SleepLogicStatus' */
  UInt16 store_timout;                 /* '<S1>/SleepLogicStatus' */
} SleepLogic_DW_fwu4;

#endif                                 /*SleepLogic_MDLREF_HIDE_CHILD_*/

extern void SleepLogic(void);

#ifndef SleepLogic_MDLREF_HIDE_CHILD_

extern void SleepLogic_SleepLogicFunc(void);

extern boolean SleepLogic_GetIGkeyState(void);

#endif                                 /*SleepLogic_MDLREF_HIDE_CHILD_*/

#ifndef SleepLogic_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern SleepLogic_DW_fwu4 SleepLogicrtDW;

#endif                                 /*SleepLogic_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'SleepLogic'
 * '<S1>'   : 'SleepLogic/SleepLogicFunc'
 * '<S2>'   : 'SleepLogic/SleepLogicFunc/SleepLogicCond'
 * '<S3>'   : 'SleepLogic/SleepLogicFunc/SleepLogicStatus'
 */

/*-
 * Requirements for '<Root>': SleepLogic
 */
#endif                                 /* RTW_HEADER_SleepLogic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
