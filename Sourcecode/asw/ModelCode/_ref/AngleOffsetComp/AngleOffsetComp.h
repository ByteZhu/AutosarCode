/*
 * File: AngleOffsetComp.h
 *
 * Code generated for Simulink model 'AngleOffsetComp'.
 *
 * Model version                  : 1.1171
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov  7 10:03:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AngleOffsetComp_h_
#define RTW_HEADER_AngleOffsetComp_h_
#ifndef AngleOffsetComp_COMMON_INCLUDES_
# define AngleOffsetComp_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AngleOffsetComp_COMMON_INCLUDES_ */

#include "AngleOffsetComp_types.h"

/* Includes for objects with custom storage classes. */
#include "GlobalVar.h"
#include "CalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S1>/AngleOffsetComp' */
#ifndef AngleOffsetComp_MDLREF_HIDE_CHILD_
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

typedef struct {
  Int32 apc_gain;                      /* '<S4>/Apull_integ' */
  UInt32 m_bpIndex;                    /* '<S5>/vs_aoftgain' */
  struct {
    UInt32 is_c1_AngleOffsetComp:2;    /* '<S4>/Apull_integ' */
    UInt32 is_active_c1_AngleOffsetComp:1;/* '<S4>/Apull_integ' */
  } bitsForTID0;

  Int32 apc_offset_last;               /* '<S4>/Apull_integ' */
  UInt16 apc_straight_cnt;             /* '<S4>/Apull_integ' */
} AngleOffsetC_DW_AngleOffsetComp;

#endif
#endif                                 /*AngleOffsetComp_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S1>/AngleOffsetComp_BYD' */
#ifndef AngleOffsetComp_MDLREF_HIDE_CHILD_
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

typedef struct {
  Int32 apc_gain;                      /* '<S18>/Apull_integ' */
  UInt32 m_bpIndex;                    /* '<S19>/vs_aoftgain' */
  struct {
    UInt32 is_c2_AngleOffsetComp:2;    /* '<S18>/Apull_integ' */
    UInt32 is_active_c2_AngleOffsetComp:1;/* '<S18>/Apull_integ' */
  } bitsForTID0;

  Int16 angcrr_angopt;                 /* '<S18>/Apull_integ' */
  Int16 Delay_DSTATE_pbnu;             /* '<S19>/Delay' */
  Int16 Delay1_DSTATE;                 /* '<S19>/Delay1' */
  Int32 apc_offset_last;               /* '<S18>/Apull_integ' */
  UInt16 Delay_DSTATE;                 /* '<S36>/Delay' */
  UInt16 Delay_DSTATE_brsy;            /* '<S37>/Delay' */
  UInt16 Delay_DSTATE_em54;            /* '<S34>/Delay' */
  UInt16 Delay_DSTATE_cxiz;            /* '<S35>/Delay' */
  UInt16 apc_straight_cnt;             /* '<S18>/Apull_integ' */
} AngleOff_DW_AngleOffsetComp_BYD;

#endif
#endif                                 /*AngleOffsetComp_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'AngleOffsetComp' */
#ifndef AngleOffsetComp_MDLREF_HIDE_CHILD_

typedef struct {

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

  AngleOff_DW_AngleOffsetComp_BYD AngleOffsetComp_BYD;/* '<S1>/AngleOffsetComp_BYD' */

#define ANGLEOFFSETCOMP_DW_FWU4_VARIANT_EXISTS
#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

  AngleOffsetC_DW_AngleOffsetComp AngleOffsetComp_ctk5;/* '<S1>/AngleOffsetComp' */

#define ANGLEOFFSETCOMP_DW_FWU4_VARIANT_EXISTS
#endif

#ifndef ANGLEOFFSETCOMP_DW_FWU4_VARIANT_EXISTS

  char _rt_unused;

#endif

} AngleOffsetComp_DW_fwu4;

#endif                                 /*AngleOffsetComp_MDLREF_HIDE_CHILD_*/

extern void AngleOffsetComp(void);

#ifndef AngleOffsetComp_MDLREF_HIDE_CHILD_
#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

extern void AngleOffs_AngleOffsetComp_Apull(void);

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 0

extern void AngleO_AngleOffsetComp_Straight(void);

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

extern void Angl_AngleOffsetComp_Apull_hldl(void);

#endif

#if MACRO_ANGEL_OFFSET_COMP_SELECT == 1

extern void A_AngleOffsetComp_Straight_d1qu(void);

#endif
#endif                                 /*AngleOffsetComp_MDLREF_HIDE_CHILD_*/

#ifndef AngleOffsetComp_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern AngleOffsetComp_DW_fwu4 AngleOffsetComprtDW;

#endif                                 /*AngleOffsetComp_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'AngleOffsetComp'
 * '<S1>'   : 'AngleOffsetComp/AngleOffsetComp'
 * '<S2>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp'
 * '<S3>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD'
 * '<S4>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Apull'
 * '<S5>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight'
 * '<S6>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Apull/Apull_integ'
 * '<S7>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant'
 * '<S8>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant1'
 * '<S9>'   : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant10'
 * '<S10>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant2'
 * '<S11>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant3'
 * '<S12>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant4'
 * '<S13>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant7'
 * '<S14>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant8'
 * '<S15>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Constant9'
 * '<S16>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Zero'
 * '<S17>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_Straight/Compare To Zero1'
 * '<S18>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Apull'
 * '<S19>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight'
 * '<S20>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Apull/Apull_integ'
 * '<S21>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant'
 * '<S22>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant1'
 * '<S23>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant10'
 * '<S24>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant11'
 * '<S25>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant12'
 * '<S26>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant2'
 * '<S27>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant3'
 * '<S28>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant4'
 * '<S29>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant5'
 * '<S30>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant6'
 * '<S31>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant7'
 * '<S32>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant8'
 * '<S33>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/Compare To Constant9'
 * '<S34>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/front_left'
 * '<S35>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/front_right'
 * '<S36>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/rear_left'
 * '<S37>'  : 'AngleOffsetComp/AngleOffsetComp/AngleOffsetComp_BYD/AngleOffsetComp_Straight/rear_right'
 */

/*-
 * Requirements for '<Root>': AngleOffsetComp
 */
#endif                                 /* RTW_HEADER_AngleOffsetComp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
