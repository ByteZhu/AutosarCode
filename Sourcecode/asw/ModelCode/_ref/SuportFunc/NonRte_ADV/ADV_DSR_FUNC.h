/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_DSR_FUNC.h
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

#ifndef RTW_HEADER_ADV_DSR_FUNC_h_
#define RTW_HEADER_ADV_DSR_FUNC_h_
#ifndef ADV_ExtFunction_COMMON_INCLUDES_
#define ADV_ExtFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AngleOffsetComp.h"
#endif                                 /* ADV_ExtFunction_COMMON_INCLUDES_ */

/* PublicStructure Variables for Internal Data, for system '<Root>/ADV_DSR_FUNC' */
typedef struct {
  uint32 m_bpIndex_esah[2];            /* '<S103>/dsr_dampcomp' */
  uint32 m_bpIndex_o203[2];            /* '<S103>/dsr_dampang_coef' */
  uint32 m_bpIndex_l0uy[2];            /* '<S102>/AimSpeedt' */
  uint32 m_bpIndex_atui[2];            /* '<S102>/gradcoef' */
  uint32 m_bpIndex_kdie[2];            /* '<S101>/lka_cmdcoef2' */
  uint32 m_bpIndex_bxat[2];            /* '<S69>/dsr_override' */
  uint32 m_bpIndex;                    /* '<S104>/dsr_vscoef' */
  uint32 m_bpIndex_fdyw;               /* '<S103>/dsr_dampcmd_coef' */
  uint32 m_bpIndex_fa2a;               /* '<S69>/dsr_vs_handOvertrq' */
  uint32 apa_trqover_cnt;              /* '<S69>/dsruseroprtmr' */
  uint32 temporary_cnt;                /* '<S69>/dsr_temporarytmr' */
  sint16 cmdinput;                     /* '<S95>/Merge' */
  sint16 Switch2;                      /* '<S110>/Switch2' */
  sint16 dsrbasecurrent;               /* '<S102>/Product1' */
  sint16 Switch2_dfgf;                 /* '<S106>/Switch2' */
  sint16 Switch2_d4s5;                 /* '<S111>/Switch2' */
  sint16 cmdout;                       /* '<S99>/cmdrate' */
  sint16 cmd_grid;                     /* '<S69>/cmdgridcalc1' */
  sint16 Abs;                          /* '<S102>/Abs' */
  sint16 cmdout_nbym;                  /* '<S101>/cmdoutrate' */
  sint16 cmd_grid_g5yz;                /* '<S101>/cmdgridcalc' */
  sint16 Switch2_ibjd;                 /* '<S96>/Switch2' */
  sint16 cmdout_cng5;                  /* '<S94>/cmdrate' */
  sint16 Delay_DSTATE;                 /* '<S98>/Delay' */
  sint16 lastsigout;                   /* '<S101>/ARDelayFilter1' */
  sint16 Delay_DSTATE_c3kl;            /* '<S3>/Delay' */
  sint16 cmd_inlast;                   /* '<S101>/cmdgridcalc' */
  sint16 cmd_inlast_hfms;              /* '<S69>/cmdgridcalc1' */
  uint16 dsr_temp_cnt;                 /* '<S71>/DSRControlLogic' */
  uint16 cmd_cnt;                      /* '<S101>/cmdgridcalc' */
  uint16 cmd_cnt_ii3u;                 /* '<S69>/cmdgridcalc1' */
  uint8 Fv_DSR_ControlSts;             /* '<S71>/DSRControlLogic' */
  uint8 is_active_c19_ADV_ExtFunction; /* '<S71>/DSRControlLogic' */
  uint8 is_c19_ADV_ExtFunction;        /* '<S71>/DSRControlLogic' */
  boolean dst_enable;                  /* '<S69>/AND' */
  boolean lka_temporary;               /* '<S69>/Logical Operator2' */
  boolean dsr_permanent;               /* '<S69>/Logical Operator9' */
  boolean suppression;                 /* '<S69>/OR' */
  boolean dsr_active;                  /* '<S69>/OR1' */
  boolean trqover_flag;                /* '<S69>/dsruseroprtmr' */
  boolean overtime_flag;               /* '<S69>/dsr_temporarytmr' */
  boolean dsr_temp_flag;               /* '<S71>/DSRControlLogic' */
  boolean dsr_active_last;             /* '<S71>/DSRControlLogic' */
  boolean dsr_activetriger;            /* '<S71>/DSRControlLogic' */
} ARID_DEF_ADV_DSR_FUNC_ADV_ExtFu;

extern ARID_DEF_ADV_DSR_FUNC_ADV_ExtFu rtADV_DSR_FUNC_ARID_DEF_ADV_Ext;
extern void DSRControl_Cond(void);
extern void DSRControl_Logic_Limit(void);
extern void DSRControl_Logic_RateMax(void);
extern void DSR_ActiveState_Adv(void);
extern void DSR_ActiveState_Base(void);
extern void DSR_ActiveState_Damp(void);
extern void DSR_ActiveState_Limit(void);
extern void DSRControl_Logic_Trq(void);
extern void DSRControl_Exec(void);
extern void DSRControl_Logic(void);
extern void ADV_DSR_FUNC(void);

#endif                                 /* RTW_HEADER_ADV_DSR_FUNC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
