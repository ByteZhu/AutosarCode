/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_CCP_PROC.h
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

#ifndef RTW_HEADER_ADV_CCP_PROC_h_
#define RTW_HEADER_ADV_CCP_PROC_h_
#ifndef ADV_ExtFunction_COMMON_INCLUDES_
#define ADV_ExtFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AngleOffsetComp.h"
#endif                                 /* ADV_ExtFunction_COMMON_INCLUDES_ */

/* PublicStructure Variables for Internal Data, for system '<Root>/ADV_CCP_PROC' */
typedef struct {
  boolean Switch[2];                   /* '<S2>/Switch' */
  boolean Compare;                     /* '<S64>/Compare' */
  boolean Compare_bd4g;                /* '<S65>/Compare' */
  boolean OR;                          /* '<S2>/OR' */
} ARID_DEF_ADV_CCP_PROC_ADV_ExtFu;

extern ARID_DEF_ADV_CCP_PROC_ADV_ExtFu rtADV_CCP_PROC_ARID_DEF_ADV_Ext;
extern void ADV_CCP_PROC(void);

#endif                                 /* RTW_HEADER_ADV_CCP_PROC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
