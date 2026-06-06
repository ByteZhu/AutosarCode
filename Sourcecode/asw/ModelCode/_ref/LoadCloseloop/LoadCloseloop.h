/*
 * File: LoadCloseloop.h
 *
 * Code generated for Simulink model 'LoadCloseloop'.
 *
 * Model version                  : 1.1160
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Oct 20 16:17:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LoadCloseloop_h_
#define RTW_HEADER_LoadCloseloop_h_
#ifndef LoadCloseloop_COMMON_INCLUDES_
# define LoadCloseloop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LoadCloseloop_COMMON_INCLUDES_ */

#include "LoadCloseloop_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "CalVar.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S1>/LoadCloseloop_BYDEK' */
#ifndef LoadCloseloop_MDLREF_HIDE_CHILD_
#if MACRO_LOADCLOSELOOP_SELECT == 1

typedef struct {
  Int32 trqcloseloop;                  /* '<S7>/Gain' */
  UInt32 m_bpIndex[2];                 /* '<S8>/StrTrqLoad4' */
  UInt32 m_bpIndex_ozut[2];            /* '<S8>/StrTrqLoad1' */
  UInt32 m_bpIndex_deai[2];            /* '<S8>/StrTrqLoad2' */
  UInt32 m_bpIndex_ggab[2];            /* '<S8>/StrTrqLoad3' */
  UInt32 m_bpIndex_cz2v[2];            /* '<S7>/TCL_revKI' */
  UInt32 m_bpIndex_fydq[2];            /* '<S7>/TCL_revKP' */
  UInt32 m_bpIndex_d0dr;               /* '<S7>/TCL_VsLimit' */
  UInt32 m_bpIndex_hfwf;               /* '<S6>/AssUp' */
  UInt32 m_bpIndex_jtxx;               /* '<S6>/AssDn' */
  UInt32 m_bpIndex_dhwd;               /* '<S6>/TorFrLimit' */
  Int16 Add1;                          /* '<S8>/Add1' */
} LoadClos_DW_LoadCloseloop_BYDEK;

#endif
#endif                                 /*LoadCloseloop_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S1>/LoadCloseloop_Orignal' */
#ifndef LoadCloseloop_MDLREF_HIDE_CHILD_
#if MACRO_LOADCLOSELOOP_SELECT == 0

typedef struct {
  Float64 y1[4];                       /* '<S22>/filter1_trw' */
  Float64 y2[6];                       /* '<S22>/filter1_trw' */
  Float64 notchfilter_states[2];       /* '<S22>/notchfilter' */
  Float64 notchfilter_denStates[2];    /* '<S22>/notchfilter' */
  Float64 notchfilter1_states;         /* '<S22>/notchfilter1' */
  Float64 notchfilter1_denStates;      /* '<S22>/notchfilter1' */
  Float64 notchfilter1_tmp;            /* '<S22>/notchfilter1' */
  Float64 notchfilter_tmp;             /* '<S22>/notchfilter' */
  Int32 trqcloseloop;                  /* '<S25>/Gain' */
  UInt32 m_bpIndex[2];                 /* '<S26>/StrTrqLoad4' */
  UInt32 m_bpIndex_ixbb[2];            /* '<S26>/StrTrqLoad1' */
  UInt32 m_bpIndex_oesk[2];            /* '<S26>/StrTrqLoad2' */
  UInt32 m_bpIndex_i2g0[2];            /* '<S26>/StrTrqLoad3' */
  UInt32 m_bpIndex_ko1f;               /* '<S25>/TCL_revKI' */
  UInt32 m_bpIndex_jd4l;               /* '<S24>/AssUp' */
  UInt32 m_bpIndex_ljuh;               /* '<S24>/AssDn' */
  UInt32 m_bpIndex_imng;               /* '<S24>/TorFrLimit' */
} LoadCl_DW_LoadCloseloop_Orignal;

#endif
#endif                                 /*LoadCloseloop_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'LoadCloseloop' */
#ifndef LoadCloseloop_MDLREF_HIDE_CHILD_

typedef struct {

#if MACRO_LOADCLOSELOOP_SELECT == 0

  LoadCl_DW_LoadCloseloop_Orignal LoadCloseloop_Orignal;

#define LOADCLOSELOOP_DW_FWU4_VARIANT_EXISTS
#endif

#if MACRO_LOADCLOSELOOP_SELECT == 1

  LoadClos_DW_LoadCloseloop_BYDEK LoadCloseloop_BYDEK;

#define LOADCLOSELOOP_DW_FWU4_VARIANT_EXISTS
#endif

#ifndef LOADCLOSELOOP_DW_FWU4_VARIANT_EXISTS

  char _rt_unused;

#endif

} LoadCloseloop_DW_fwu4;

#endif                                 /*LoadCloseloop_MDLREF_HIDE_CHILD_*/

extern void LoadCloseloop_Init1(void);
extern void LoadCloseloop1(void);

#ifndef LoadCloseloop_MDLREF_HIDE_CHILD_
#if MACRO_LOADCLOSELOOP_SELECT == 1

extern void LoadCloseloop_LoadCloseloop_FIR(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 1

extern void LoadCloselo_LoadCloseloop_Limit(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 1

extern void LoadClose_LoadCloseloop_OpenFed(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 1

extern void LoadCloseloop_LoadCloseloop_PID(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 1

extern void LoadClosel_LoadCloseloop_Target(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 1

extern void LoadCloselo_LoadCloseloop_BYDEK(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void LoadClos_LoadCloseloop_FIR_Init(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void LoadClos_LoadCloseloop_FIR_f2eq(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void LoadCl_LoadCloseloop_Limit_ilaf(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void Load_LoadCloseloop_OpenFed_bqgi(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void LoadClos_LoadCloseloop_PID_ceaz(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void LoadC_LoadCloseloop_Target_cpsp(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void Load_LoadCloseloop_Orignal_Init(void);

#endif

#if MACRO_LOADCLOSELOOP_SELECT == 0

extern void LoadClose_LoadCloseloop_Orignal(void);

#endif
#endif                                 /*LoadCloseloop_MDLREF_HIDE_CHILD_*/

#ifndef LoadCloseloop_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern LoadCloseloop_DW_fwu4 LoadCloselooprtDW;

#endif                                 /*LoadCloseloop_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'LoadCloseloop'
 * '<S1>'   : 'LoadCloseloop/LoadCloseloop'
 * '<S2>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK'
 * '<S3>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal'
 * '<S4>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_FIR'
 * '<S5>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_Limit'
 * '<S6>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_OpenFed'
 * '<S7>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_PID'
 * '<S8>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_Target'
 * '<S9>'   : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_Limit/Saturation Dynamic'
 * '<S10>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_OpenFed/Compare To Zero'
 * '<S11>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_OpenFed/Compare To Zero1'
 * '<S12>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_OpenFed/Compare To Zero2'
 * '<S13>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_OpenFed/Compare To Zero3'
 * '<S14>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_OpenFed/SaturationDynamic'
 * '<S15>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_PID/Compare To Zero'
 * '<S16>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_PID/Compare To Zero1'
 * '<S17>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_PID/Data Type Scaling Strip'
 * '<S18>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_PID/Data Type Scaling Strip2'
 * '<S19>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_PID/Data Type Scaling Strip3'
 * '<S20>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_PID/Saturation Dynamic'
 * '<S21>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_BYDEK/LoadCloseloop_Target/Saturation Dynamic'
 * '<S22>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_FIR'
 * '<S23>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_Limit'
 * '<S24>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_OpenFed'
 * '<S25>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_PID'
 * '<S26>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_Target'
 * '<S27>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_FIR/filter1_trw'
 * '<S28>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_Limit/Saturation Dynamic'
 * '<S29>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_OpenFed/Compare To Zero'
 * '<S30>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_OpenFed/Compare To Zero1'
 * '<S31>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_OpenFed/Compare To Zero2'
 * '<S32>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_OpenFed/Compare To Zero3'
 * '<S33>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_OpenFed/SaturationDynamic'
 * '<S34>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_PID/Data Type Scaling Strip'
 * '<S35>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_PID/Data Type Scaling Strip1'
 * '<S36>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_PID/Saturation Dynamic'
 * '<S37>'  : 'LoadCloseloop/LoadCloseloop/LoadCloseloop_Orignal/LoadCloseloop_Target/Saturation Dynamic'
 */

/*-
 * Requirements for '<Root>': LoadCloseloop
 */
#endif                                 /* RTW_HEADER_LoadCloseloop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
