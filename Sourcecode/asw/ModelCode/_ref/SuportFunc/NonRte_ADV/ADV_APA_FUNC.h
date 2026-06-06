/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_APA_FUNC.h
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

#ifndef RTW_HEADER_ADV_APA_FUNC_h_
#define RTW_HEADER_ADV_APA_FUNC_h_
#ifndef ADV_ExtFunction_COMMON_INCLUDES_
#define ADV_ExtFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AngleOffsetComp.h"
#endif                                 /* ADV_ExtFunction_COMMON_INCLUDES_ */

#include "Rte_Type.h"


/* Box: /DataTypes/PARKERR begin */
/* Box: "PARKERR_NormOper" begin */
#ifndef PARKERR_NormOper
#define PARKERR_NormOper (0)
#endif /* !PARKERR_NormOper */
/* Box: "PARKERR_NormOper" end */
/* Box: "PARKERR_SteerAbortBySpdHi" begin */
#ifndef PARKERR_SteerAbortBySpdHi
#define PARKERR_SteerAbortBySpdHi (1)
#endif /* !PARKERR_SteerAbortBySpdHi */
/* Box: "PARKERR_SteerAbortBySpdHi" end */
/* Box: "PARKERR_CtrlDifHi" begin */
#ifndef PARKERR_CtrlDifHi
#define PARKERR_CtrlDifHi (2)
#endif /* !PARKERR_CtrlDifHi */
/* Box: "PARKERR_CtrlDifHi" end */
/* Box: "PARKERR_SteerCtrlIntErr" begin */
#ifndef PARKERR_SteerCtrlIntErr
#define PARKERR_SteerCtrlIntErr (3)
#endif /* !PARKERR_SteerCtrlIntErr */
/* Box: "PARKERR_SteerCtrlIntErr" end */
/* Box: "PARKERR_SteerAbortByDrvIntv" begin */
#ifndef PARKERR_SteerAbortByDrvIntv
#define PARKERR_SteerAbortByDrvIntv (4)
#endif /* !PARKERR_SteerAbortByDrvIntv */
/* Box: "PARKERR_SteerAbortByDrvIntv" end */
/* Box: "PARKERR_SteerTqHi" begin */
#ifndef PARKERR_SteerTqHi
#define PARKERR_SteerTqHi (5)
#endif /* !PARKERR_SteerTqHi */
/* Box: "PARKERR_SteerTqHi" end */
/* Box: "PARKERR_Spare1" begin */
#ifndef PARKERR_Spare1
#define PARKERR_Spare1 (6)
#endif /* !PARKERR_Spare1 */
/* Box: "PARKERR_Spare1" end */
/* Box: "PARKERR_Spare2" begin */
#ifndef PARKERR_Spare2
#define PARKERR_Spare2 (7)
#endif /* !PARKERR_Spare2 */
/* Box: "PARKERR_Spare2" end */
/* Box: /DataTypes/PARKERR end */

/* PublicStructure Variables for Internal Data, for system '<Root>/ADV_APA_FUNC' */
typedef struct {
  sint32 Delay;                        /* '<S1>/Delay' */
  sint32 mcsl_actrev;                  /* '<S40>/Switch' */
  sint32 mcsl_kp;                      /* '<S40>/Switch1' */
  sint32 FixPtGatewayOut;              /* '<S47>/FixPt Gateway Out' */
  sint32 mcsl_err;                     /* '<S39>/APA_PosControl' */
  sint32 mcsl_ki;                      /* '<S40>/Switch2' */
  sint32 Delay_DSTATE;                 /* '<S1>/Delay' */
  sint32 mcsl_err_mbvz;                /* '<S41>/APA_RevControl' */
  sint32 mcsl_aimout;                  /* '<S41>/APA_RevControl' */
  uint32 m_bpIndex[2];                 /* '<S40>/apalooktab_kp' */
  uint32 m_bpIndex_lxba[2];            /* '<S40>/apalooktab_ki' */
  uint32 m_bpIndex_e4kx;               /* '<S8>/apa_handoverride' */
  uint32 apa_trqover_cnt;              /* '<S8>/apauseroprtmr' */
  PARKERR SteerStsToParkAssi;          /* '<S9>/APAControlLogic' */
  PARKERR opn2flt_st;                  /* '<S8>/Open2FaultRecord' */
  PARKERR actv2flt_st;                 /* '<S8>/Active2FaultRecord' */
  sint16 FixPtGatewayOut_eprv;         /* '<S54>/FixPt Gateway Out' */
  sint16 FixPtGatewayOut_plsa;         /* '<S55>/FixPt Gateway Out' */
  sint16 FixPtGatewayOut_chuv;         /* '<S56>/FixPt Gateway Out' */
  sint16 FixPtGatewayOut_palk;         /* '<S48>/FixPt Gateway Out' */
  sint16 mcsl_aimrevin;                /* '<S39>/Signal Copy2' */
  sint16 Delay1_DSTATE;                /* '<S51>/Delay1' */
  sint16 pc_strang_last;               /* '<S39>/APA_PosControl' */
  uint16 apa_stop_cnt;                 /* '<S39>/APA_PosControl' */
  uint8 Fv_APA_ControlSts;             /* '<S9>/APAControlLogic' */
  uint8 lastst;                        /* '<S9>/APAControlLogic' */
  uint8 is_active_c24_ADV_ExtFunction; /* '<S9>/APAControlLogic' */
  uint8 is_c24_ADV_ExtFunction;        /* '<S9>/APAControlLogic' */
  boolean Compare;                     /* '<S53>/Compare' */
  boolean apa_stop_flag;               /* '<S39>/APA_PosControl' */
  boolean active2fault_flag;           /* '<S8>/AND11' */
  boolean fault2close_flag;            /* '<S8>/AND12' */
  boolean open2fault_flag;             /* '<S8>/AND14' */
  boolean close2open_flag;             /* '<S8>/AND7' */
  boolean open2active_flag;            /* '<S8>/AND9' */
  boolean open2close_flag;             /* '<S8>/NOT' */
  boolean close2fault_flag;            /* '<S8>/NOT8' */
  boolean park_temporary;              /* '<S8>/apauseroprtmr' */
  boolean apa_stop_flag_ca22;          /* '<S39>/Signal Copy' */
  boolean Relay_Mode;                  /* '<S40>/Relay' */
} ARID_DEF_ADV_APA_FUNC_ADV_ExtFu;

extern ARID_DEF_ADV_APA_FUNC_ADV_ExtFu rtADV_APA_FUNC_ARID_DEF_ADV_Ext;
extern void APAControl_Cond(void);
extern void APAControl_Logic(void);
extern void APA_PosLoopControl(void);
extern void APA_RevCalcParamSet(void);
extern void APA_RevLoopControl(void);
extern void Position_AngleLoop(void);
extern void Position_Precond(void);
extern void APAControl_Position(void);
extern void ADV_APA_FUNC(void);

#endif                                 /* RTW_HEADER_ADV_APA_FUNC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
