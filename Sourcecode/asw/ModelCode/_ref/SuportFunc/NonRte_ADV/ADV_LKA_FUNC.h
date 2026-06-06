/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_LKA_FUNC.h
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

#ifndef RTW_HEADER_ADV_LKA_FUNC_h_
#define RTW_HEADER_ADV_LKA_FUNC_h_
#ifndef ADV_ExtFunction_COMMON_INCLUDES_
#define ADV_ExtFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AngleOffsetComp.h"
#endif                                 /* ADV_ExtFunction_COMMON_INCLUDES_ */

/* PublicStructure Variables for Internal Data, for system '<Root>/ADV_LKA_FUNC' */
typedef struct {
  sint32 mclk_actrev;                  /* '<S175>/Switch' */
  sint32 mclk_kp;                      /* '<S175>/Switch1' */
  sint32 FixPtGatewayOut;              /* '<S182>/FixPt Gateway Out' */
  sint32 mclk_err;                     /* '<S174>/LKA_PosControl' */
  sint32 mclk_ki;                      /* '<S175>/Switch2' */
  sint32 mclk_err_mbvz;                /* '<S176>/LKA_RevControl' */
  sint32 mclk_aimout;                  /* '<S176>/LKA_RevControl' */
  uint32 m_bpIndex_hvsy[2];            /* '<S175>/lkalooktab_kp' */
  uint32 m_bpIndex_cprh[2];            /* '<S175>/lkalooktab_ki' */
  uint32 m_bpIndex_l1cm[2];            /* '<S142>/lka_override' */
  uint32 m_bpIndex;                    /* '<S186>/UpLimit' */
  uint32 m_bpIndex_oaez;               /* '<S186>/DnLimit1' */
  uint32 m_bpIndex_jieb;               /* '<S142>/lka_vs_handOvertrq' */
  uint32 apa_trqover_cnt;              /* '<S142>/lkauseroprtmr' */
  uint32 temporary_cnt;                /* '<S142>/lka_temporarytmr' */
  sint16 Switch2;                      /* '<S185>/Switch2' */
  sint16 cmd_grid;                     /* '<S142>/cmdgridcalc' */
  sint16 FixPtGatewayOut_mjka;         /* '<S193>/FixPt Gateway Out' */
  sint16 FixPtGatewayOut_odfm;         /* '<S194>/FixPt Gateway Out' */
  sint16 FixPtGatewayOut_kze5;         /* '<S195>/FixPt Gateway Out' */
  sint16 FixPtGatewayOut_iiqs;         /* '<S183>/FixPt Gateway Out' */
  sint16 mclk_aimrevin;                /* '<S174>/Signal Copy2' */
  sint16 Delay1_DSTATE;                /* '<S190>/Delay1' */
  sint16 Delay_DSTATE;                 /* '<S6>/Delay' */
  sint16 pc_strang_last;               /* '<S174>/LKA_PosControl' */
  sint16 cmd_inlast;                   /* '<S142>/cmdgridcalc' */
  uint16 lka_temp_cnt;                 /* '<S144>/LKAControlLogic' */
  uint16 lka_stop_cnt;                 /* '<S174>/LKA_PosControl' */
  uint16 cmd_cnt;                      /* '<S142>/cmdgridcalc' */
  uint8 Fv_LKA_ControlSts;             /* '<S144>/LKAControlLogic' */
  uint8 is_active_c2_ADV_ExtFunction;  /* '<S144>/LKAControlLogic' */
  uint8 is_c2_ADV_ExtFunction;         /* '<S144>/LKAControlLogic' */
  boolean Compare;                     /* '<S192>/Compare' */
  boolean lka_stop_flag;               /* '<S174>/LKA_PosControl' */
  boolean lka_temporary;               /* '<S142>/Logical Operator2' */
  boolean lka_permanent;               /* '<S142>/Logical Operator9' */
  boolean suppression;                 /* '<S142>/OR' */
  boolean OR1;                         /* '<S142>/OR1' */
  boolean trqover_flag;                /* '<S142>/lkauseroprtmr' */
  boolean overtime_flag;               /* '<S142>/lka_temporarytmr' */
  boolean lka_stop_flag_bmc2;          /* '<S174>/Signal Copy' */
  boolean lka_temp_flag;               /* '<S144>/LKAControlLogic' */
  boolean lka_active_last;             /* '<S144>/LKAControlLogic' */
  boolean lka_activetriger;            /* '<S144>/LKAControlLogic' */
  boolean Relay_Mode;                  /* '<S175>/Relay' */
} ARID_DEF_ADV_LKA_FUNC_ADV_ExtFu;

extern ARID_DEF_ADV_LKA_FUNC_ADV_ExtFu rtADV_LKA_FUNC_ARID_DEF_ADV_Ext;
extern void LKAControl_Cond(void);
extern void LKA_PosLoopControl(void);
extern void LKA_RevCalcParamSet(void);
extern void LKA_RevLoopControl(void);
extern void LKAControl_Exec_AngleLoop(void);
extern void LKAControl_Exec_Precond(void);
extern void LKAControl_Exec(void);
extern void LKAControl_Logic(void);
extern void ADV_LKA_FUNC(void);

#endif                                 /* RTW_HEADER_ADV_LKA_FUNC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
