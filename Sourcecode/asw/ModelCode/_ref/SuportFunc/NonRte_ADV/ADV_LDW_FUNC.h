/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_LDW_FUNC.h
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

#ifndef RTW_HEADER_ADV_LDW_FUNC_h_
#define RTW_HEADER_ADV_LDW_FUNC_h_
#ifndef ADV_ExtFunction_COMMON_INCLUDES_
#define ADV_ExtFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AngleOffsetComp.h"
#endif                                 /* ADV_ExtFunction_COMMON_INCLUDES_ */

/* PublicStructure Variables for Internal Data, for system '<Root>/ADV_LDW_FUNC' */
typedef struct {
  uint32 m_bpIndex;                    /* '<S135>/ldw_vibfrz' */
  uint32 m_bpIndex_jppo;               /* '<S135>/ldw_vibamp' */
  sint16 Gain1;                        /* '<S134>/Gain1' */
  sint16 cmdout;                       /* '<S134>/cmdrate' */
  uint16 ldw_temp_cnt;                 /* '<S122>/LDWControlLogic' */
  uint16 i;                            /* '<S134>/ldw_sin_input' */
  uint8 Fv_LDW_ControlSts;             /* '<S122>/LDWControlLogic' */
  uint8 is_active_c7_ADV_ExtFunction;  /* '<S122>/LDWControlLogic' */
  uint8 is_c7_ADV_ExtFunction;         /* '<S122>/LDWControlLogic' */
  boolean suppression;                 /* '<S120>/Logical Operator9' */
  boolean ldw_temporary;               /* '<S120>/Logical Operator6' */
  boolean ldw_permanent;               /* '<S120>/Logical Operator5' */
  boolean Compare;                     /* '<S129>/Compare' */
  boolean ldw_noactive;                /* '<S120>/Logical Operator1' */
  boolean Delay_DSTATE;                /* '<S120>/Delay' */
  boolean ldw_temp_flag;               /* '<S122>/LDWControlLogic' */
  boolean ldw_active_last;             /* '<S122>/LDWControlLogic' */
  boolean ldw_activetriger;            /* '<S122>/LDWControlLogic' */
  boolean icLoad;                      /* '<S120>/Delay' */
} ARID_DEF_ADV_LDW_FUNC_ADV_ExtFu;

extern ARID_DEF_ADV_LDW_FUNC_ADV_ExtFu rtADV_LDW_FUNC_ARID_DEF_ADV_Ext;
extern void LDWControl_Cond_Init(void);
extern void LDWControl_Cond(void);
extern void LDWControl_Exec(void);
extern void LDWControl_Logic(void);
extern void ADV_LDW_FUNC_Init(void);
extern void ADV_LDW_FUNC(void);

#endif                                 /* RTW_HEADER_ADV_LDW_FUNC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
