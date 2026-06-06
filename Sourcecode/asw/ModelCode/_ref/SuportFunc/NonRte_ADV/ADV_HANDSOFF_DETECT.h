/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_HANDSOFF_DETECT.h
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

#ifndef RTW_HEADER_ADV_HANDSOFF_DETECT_h_
#define RTW_HEADER_ADV_HANDSOFF_DETECT_h_
#ifndef ADV_ExtFunction_COMMON_INCLUDES_
#define ADV_ExtFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AngleOffsetComp.h"
#endif                                 /* ADV_ExtFunction_COMMON_INCLUDES_ */

/* PublicStructure Variables for Internal Data, for system '<Root>/ADV_HANDSOFF_DETECT' */
typedef struct {
  float64 FunctionCaller1[4];          /* '<S4>/Function Caller1' */
  float64 filterlph_states;            /* '<S4>/filterlph' */
  float64 filterlph_denStates;         /* '<S4>/filterlph' */
  float64 filterlph_tmp;               /* '<S4>/filterlph' */
  uint32 m_bpIndex[2];                 /* '<S4>/handsoff_step' */
  uint32 handoff_cnt;                  /* '<S4>/lkauser_handoff' */
  uint8 handoff_qly;                   /* '<S4>/lkauser_handoff' */
  boolean Compare;                     /* '<S115>/Compare' */
} ARID_DEF_ADV_HANDSOFF_DETECT_AD;

extern ARID_DEF_ADV_HANDSOFF_DETECT_AD rtADV_HANDSOFF_DETECT_ARID_DEF_;
extern void ADV_HANDSOFF_DETECT_Init(void);
extern void ADV_HANDSOFF_DETECT(void);

#endif                                 /* RTW_HEADER_ADV_HANDSOFF_DETECT_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
