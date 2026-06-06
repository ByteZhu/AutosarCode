/*
 * File: TorqueOffsetComp.h
 *
 * Code generated for Simulink model 'TorqueOffsetComp'.
 *
 * Model version                  : 1.1678
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Oct 25 16:35:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TorqueOffsetComp_h_
#define RTW_HEADER_TorqueOffsetComp_h_
#ifndef TorqueOffsetComp_COMMON_INCLUDES_
# define TorqueOffsetComp_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TorqueOffsetComp_COMMON_INCLUDES_ */

#include "TorqueOffsetComp_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "CalVar.h"
#include "CalVarExt.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for model 'TorqueOffsetComp' */
#ifndef TorqueOffsetComp_MDLREF_HIDE_CHILD_

typedef struct {
  Int32 delay_DSTATE;                  /* '<S40>/delay' */
  Int32 UnitDelay_DSTATE;              /* '<S37>/Unit Delay' */
  Int32 delay_DSTATE_hmnw;             /* '<S22>/delay' */
  struct {
    UInt32 is_c3_TorqueOffsetComp:2;  /* '<S3>/TorqueOffsetComp_StateMachine' */
    UInt32 is_Active:2;               /* '<S3>/TorqueOffsetComp_StateMachine' */
    UInt32 is_active_c3_TorqueOffsetComp:1;
                                      /* '<S3>/TorqueOffsetComp_StateMachine' */
  } bitsForTID0;

  Int16 str_ang_abs;                   /* '<S6>/ang_abs' */
  Int16 str_spd_abs;                   /* '<S6>/spd_abs' */
  Int16 str_trq_abs;                   /* '<S6>/trq_abs' */
  Int16 time_cnt;                     /* '<S3>/TorqueOffsetComp_StateMachine' */
  Int16 exit_cnt;                     /* '<S3>/TorqueOffsetComp_StateMachine' */
  UInt8 toc_cnt;                       /* '<S24>/toc_sch' */
  Bool short_reset;                    /* '<S21>/Logical Operator1' */
  Bool study_calc;                     /* '<S21>/Relational Operator7' */
  Bool long_enb;                       /* '<S21>/Logical Operator2' */
} TorqueOffsetComp_DW_fwu4;

#endif                                 /*TorqueOffsetComp_MDLREF_HIDE_CHILD_*/

extern void TorqueOffsetComp_Init(void);
extern void TorqueOffsetComp(void);
extern void ClearTOCTrqueVaue(void);
#ifndef TorqueOffsetComp_MDLREF_HIDE_CHILD_

extern void T_TorqueOffsetComp_StraightCond(void);
extern void Tor_TorqueOffsetComp_ValidScale(void);
extern void Tor_TorqueOffsetComp_PreProcess(void);
extern void TorqueOffsetComp_StateMng_Init(void);
extern void Torqu_TorqueOffsetComp_StateMng(void);
extern void TorqueOffsetComp_toc_cond_judge(void);
extern void TorqueOffsetComp_toc_trq_calc(void);
extern void TorqueOffsetComp_toc_trq_out(void);
extern void TorqueOffsetComp_toc_trq_sty(void);
extern void Torque_TorqueOffsetComp_TrqCalc(void);

#endif                                 /*TorqueOffsetComp_MDLREF_HIDE_CHILD_*/

#ifndef TorqueOffsetComp_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern TorqueOffsetComp_DW_fwu4 TorqueOffsetComprtDW;

#endif                                 /*TorqueOffsetComp_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'TorqueOffsetComp'
 * '<S1>'   : 'TorqueOffsetComp/TestSub'
 * '<S2>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess'
 * '<S3>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_StateMng'
 * '<S4>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc'
 * '<S5>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_StraightCond'
 * '<S6>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale'
 * '<S7>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_StraightCond/Compare To Constant1'
 * '<S8>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_StraightCond/Compare To Constant5'
 * '<S9>'   : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_StraightCond/Compare To Constant6'
 * '<S10>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_StraightCond/Compare To Constant9'
 * '<S11>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant'
 * '<S12>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant1'
 * '<S13>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant10'
 * '<S14>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant12'
 * '<S15>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant2'
 * '<S16>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant3'
 * '<S17>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant4'
 * '<S18>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant7'
 * '<S19>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_PreProcess/TorqueOffsetComp_ValidScale/Compare To Constant8'
 * '<S20>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_StateMng/TorqueOffsetComp_StateMachine'
 * '<S21>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_cond_judge'
 * '<S22>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc'
 * '<S23>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_out'
 * '<S24>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_sty'
 * '<S25>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_cond_judge/Compare To Constant'
 * '<S26>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_cond_judge/Compare To Constant1'
 * '<S27>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_cond_judge/Compare To Zero'
 * '<S28>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_cond_judge/Compare To Zero1'
 * '<S29>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/Dead Zone Dynamic'
 * '<S30>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/LimitCoef'
 * '<S31>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/Saturation Dynamic'
 * '<S32>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/Saturation Dynamic1'
 * '<S33>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/LimitCoef/Data Type Scaling Strip'
 * '<S34>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/LimitCoef/Data Type Scaling Strip1'
 * '<S35>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_calc/LimitCoef/rate_limit'
 * '<S36>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_out/Compare To Zero'
 * '<S37>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_out/LongRateLimit'
 * '<S38>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_out/Saturation Dynamic'
 * '<S39>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_sty/toc_sch'
 * '<S40>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_sty/toc_sty'
 * '<S41>'  : 'TorqueOffsetComp/TestSub/TorqueOffsetComp_TrqCalc/toc_trq_sty/toc_sty/Saturation Dynamic'
 */

/*-
 * Requirements for '<Root>': TorqueOffsetComp
 */
#endif                                 /* RTW_HEADER_TorqueOffsetComp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
