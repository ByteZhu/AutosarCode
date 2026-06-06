/*
 * File: AssistControl.h
 *
 * Code generated for Simulink model 'AssistControl'.
 *
 * Model version                  : 1.1328
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Nov 24 15:02:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AssistControl_h_
#define RTW_HEADER_AssistControl_h_
#ifndef AssistControl_COMMON_INCLUDES_
# define AssistControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AssistControl_COMMON_INCLUDES_ */

#include "AssistControl_types.h"

/* Child system includes */
#ifndef AssistControl_MDLREF_HIDE_CHILD_
#include "NewCodeAPI.h"
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

#ifndef AssistControl_MDLREF_HIDE_CHILD_
#define TorqueOffsetComp_MDLREF_HIDE_CHILD_
#include "TorqueOffsetComp.h"
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

#ifndef AssistControl_MDLREF_HIDE_CHILD_
#define LoadCloseloop_MDLREF_HIDE_CHILD_
#include "LoadCloseloop.h"
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Includes for objects with custom storage classes. */
#include "SimGlobal.h"
#include "SimDiagMacro.h"
#include "SimDiagMacroSupport.h"
#include "CalVar.h"
#include "GlobalVarSupport.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S42>/CalibAss' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_
#if ASSIST_EXTERN_LINESEG == 0

typedef struct {
  UInt32 m_bpIndex[2];                 /* '<S43>/TorFrLimit4' */
  UInt32 m_bpIndex_fuv2[2];            /* '<S43>/TorFrLimit1' */
  UInt32 m_bpIndex_l1t3[2];            /* '<S43>/TorFrLimit3' */
  UInt32 m_bpIndex_imja[2];            /* '<S43>/TorFrLimit2' */
} AssistControl_DW_CalibAss;


/* Named constants for Chart: '<S160>/StudyProcess_Auto' */
#define AssistControl_IN_Learned       ((UInt8)2U)
#define AssistControl_IN_Learning      ((UInt8)1U)
#define AssistControl_IN_NotLearn      ((UInt8)0U)

#endif
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S42>/ReactorAss' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_
#if ASSIST_EXTERN_LINESEG == 1

typedef struct {
  UInt32 m_bpIndex[2];                 /* '<S44>/TorFrLimit' */
} AssistControl_DW_ReactorAss;

#endif
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S56>/CaclAim_MotorAngState_En' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_
#if CACLAIM_MOTORANG_POWERST == 1

typedef struct {
  struct {
    UInt32 resvInitFlag:1;             /* '<S68>/MotorPositionWork' */
  } bitsForTID0;

  UInt16 resv_lowcnt;                  /* '<S68>/MotorPositionWork' */
  Bool resolversmp;                    /* '<S68>/MotorPositionWork' */
  Bool lastrsvreset_DSTATE;            /* '<S68>/lastrsvreset' */
} Ass_DW_CaclAim_MotorAngState_En;

#endif
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S81>/FrictionComp' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_
#if MACRO_FRICTION_COMP_SELECT == 0

typedef struct {
  UInt32 m_bpIndex;                    /* '<S86>/FrcCompRev2' */
  UInt32 m_bpIndex_do0v;               /* '<S86>/FrcCompTrqVs' */
  UInt32 m_bpIndex_gcpy;               /* '<S84>/FrcCompRev' */
  UInt32 m_bpIndex_lbhr;               /* '<S84>/FrcCompRevVs' */
} AssistControl_DW_FrictionComp;

#endif
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S81>/FrictionCompAdptive' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_
#if MACRO_FRICTION_COMP_SELECT == 1

typedef struct {
  UInt32 m_bpIndex;                    /* '<S96>/FrcStudyQact' */
  UInt32 m_bpIndex_ourf;               /* '<S96>/FrcStudyTrq' */
  UInt32 m_bpIndex_oeyg;               /* '<S92>/FrcCompRev2' */
  UInt32 m_bpIndex_apdg;               /* '<S92>/FrcCompTrqVs' */
  UInt32 m_bpIndex_i3fx;               /* '<S91>/LowTempComp' */
  UInt32 m_bpIndex_nykm;               /* '<S90>/FrcCompRev' */
  UInt32 m_bpIndex_ig0p;               /* '<S90>/FrcCompRevVs' */
  struct {
    UInt32 is_c22_AssistControl:3;     /* '<S94>/StudyProcess' */
    UInt32 is_active_c22_AssistControl:1;/* '<S94>/StudyProcess' */
    UInt32 learnvalid:1;               /* '<S94>/StudyProcess' */
    UInt32 restartflag:1;              /* '<S94>/StudyProcess' */
  } bitsForTID0;

  Int16 friction_up[16];               /* '<S94>/StudyProcess' */
  Int16 friction_down[16];             /* '<S94>/StudyProcess' */
  Int16 Add;                           /* '<S96>/Add' */
  Int16 FriCompAdptiveTorque;          /* '<S94>/StudyProcess' */
  UInt16 cnt_up[16];                   /* '<S94>/StudyProcess' */
  UInt16 cnt_down[16];                 /* '<S94>/StudyProcess' */
  Bool LogicalOperator5;               /* '<S95>/Logical Operator5' */
} AssistCo_DW_FrictionCompAdptive;

#endif
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S125>/LowFailLimit_fun' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_

typedef struct {
  struct {
    UInt32 is_active_c13_AssistControl:1;/* '<S125>/LowFailLimit_fun' */
  } bitsForTID0;
} AssistContr_DW_LowFailLimit_fun;

#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S156>/SteeringEnd_DecZone' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_
#if STEEREND_ZONE_VARIABLE == 1

typedef struct {
  Int16 lastangle_cmp_limit;           /* '<S164>/calc_variantend' */
  UInt16 counter;                      /* '<S161>/SheduleCounter' */
  UInt16 count;                        /* '<S164>/calc_variantend' */
} AssistCo_DW_SteeringEnd_DecZone;

#endif
#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'AssistControl' */
#ifndef AssistControl_MDLREF_HIDE_CHILD_

typedef struct {
  AssistContr_DW_LowFailLimit_fun sf_TempSampFailLimit_fun;/* '<S16>/TempSampFailLimit_fun' */

#if STEEREND_ZONE_VARIABLE == 1

  AssistCo_DW_SteeringEnd_DecZone SteeringEnd_DecZone_cm20;

#define ASSISTCONTROL_DW_FWU4_VARIANT_EXISTS
#endif

  AssistContr_DW_LowFailLimit_fun sf_LowFailLimit_fun;/* '<S125>/LowFailLimit_fun' */

#if MACRO_FRICTION_COMP_SELECT == 1

  AssistCo_DW_FrictionCompAdptive FrictionCompAdptive;

#define ASSISTCONTROL_DW_FWU4_VARIANT_EXISTS
#endif

#if MACRO_FRICTION_COMP_SELECT == 0

  AssistControl_DW_FrictionComp FrictionComp_dpvt;

#define ASSISTCONTROL_DW_FWU4_VARIANT_EXISTS
#endif

#if CACLAIM_MOTORANG_POWERST == 1

  Ass_DW_CaclAim_MotorAngState_En CaclAim_MotorAngState_En;

#define ASSISTCONTROL_DW_FWU4_VARIANT_EXISTS
#endif

#if ASSIST_EXTERN_LINESEG == 1

  AssistControl_DW_ReactorAss ReactorAss;/* '<S42>/ReactorAss' */

#define ASSISTCONTROL_DW_FWU4_VARIANT_EXISTS
#endif

#if ASSIST_EXTERN_LINESEG == 0

  AssistControl_DW_CalibAss CalibAss;  /* '<S42>/CalibAss' */

#define ASSISTCONTROL_DW_FWU4_VARIANT_EXISTS
#endif

  Int32 BlockComp;                     /* '<S143>/StallProcess_comp' */
  Int32 Isemiout1;                     /* '<S13>/GenSemiCurrent' */
  Int32 Isemiout2;                     /* '<S13>/GenSemiCurrent' */
  Int32 Tv_ShuntCurrent;               /* '<S131>/Max2' */
  Int32 TLBF;                          /* '<S16>/TempSampFailLimit_fun' */
  Int32 stall_fallcoef;                /* '<S147>/StallProcess_stall' */
  Int32 TLBF_llf5;                     /* '<S125>/LowFailLimit_fun' */
  Int32 TLBF2;                         /* '<S104>/HighFailLimit_fun2' */
  Int32 TLBF1;                         /* '<S104>/HighFailLimit_fun1' */
  Int32 Delay_DSTATE;                  /* '<S132>/Delay' */
  Int32 Delay_DSTATE_gww0;             /* '<S133>/Delay' */
  Int32 stall_falldown;                /* '<S147>/StallProcess_stall' */
  Int32 stall_fallrate;                /* '<S147>/StallProcess_stall' */
  UInt32 m_bpIndex_l2om[2];            /* '<S158>/SteerAngEnd' */
  UInt32 m_bpIndex_f5fp[2];            /* '<S158>/SteerdAngEnd' */
  UInt32 m_bpIndex_aowz[2];            /* '<S9>/TrqInetiaComp' */
  UInt32 m_bpIndex_nj3y[2];            /* '<S116>/hs_trqtab4' */
  UInt32 m_bpIndex_cmrx[2];            /* '<S116>/hs_trqtab1' */
  UInt32 m_bpIndex_i3qt[2];            /* '<S116>/hs_trqtab3' */
  UInt32 m_bpIndex_ja0g[2];            /* '<S116>/hs_trqtab2' */
  UInt32 m_bpIndex_dzbu[2];            /* '<S113>/hs_trqtab4' */
  UInt32 m_bpIndex_b4j1[2];            /* '<S113>/hs_trqtab1' */
  UInt32 m_bpIndex_ppf0[2];            /* '<S113>/hs_trqtab3' */
  UInt32 m_bpIndex_pe3i[2];            /* '<S113>/hs_trqtab2' */
  UInt32 m_bpIndex_puux[2];            /* '<S32>/vst0_tab' */
  UInt32 m_bpIndex_miig[2];            /* '<S32>/vsw_tab' */
  UInt32 m_bpIndex_hr4m[2];            /* '<S31>/DFFLimit' */
  UInt32 m_bpIndex_ega4[2];            /* '<S22>/TrqCfReturn2' */
  UInt32 m_bpIndex_krxr[2];            /* '<S21>/AimSpeedt' */
  UInt32 m_bpIndex_ceen[2];            /* '<S19>/AimSpeedLKA' */
  UInt32 m_bpIndex_phf4[2];            /* '<S19>/AimSpeedCM' */
  UInt32 m_bpIndex_exw0[2];            /* '<S19>/AimSpeedSP' */
  UInt32 m_bpIndex_pdbh[2];            /* '<S19>/AimSpeedST' */
  UInt32 SquraII;                      /* '<S131>/Max' */
  UInt32 m_bpIndex;                    /* '<S173>/SteerAngJudge' */
  UInt32 m_bpIndex_bsaj;               /* '<S148>/AssUp' */
  UInt32 m_bpIndex_cxrh;               /* '<S148>/AssDn' */
  UInt32 m_bpIndex_p3rd;               /* '<S148>/TorFrLimit' */
  UInt32 m_bpIndex_kedx;               /* '<S133>/StallCoef' */
  UInt32 slsumcnt;                     /* '<S132>/DelayOverHeat' */
  UInt32 m_bpIndex_coiv;               /* '<S116>/hs_revtab' */
  UInt32 m_bpIndex_j4ts;               /* '<S79>/DmpCompMax' */
  UInt32 m_bpIndex_grfe;               /* '<S79>/DmpCompRevVs4' */
  UInt32 m_bpIndex_opy4;               /* '<S79>/DmpCompRevVs1' */
  UInt32 m_bpIndex_gjtc;               /* '<S79>/DmpCompRevVs3' */
  UInt32 m_bpIndex_g5vh;               /* '<S79>/DmpCompRevVs2' */
  UInt32 m_bpIndex_hech;               /* '<S79>/DmpCompSquareRevVs4' */
  UInt32 m_bpIndex_dk32;               /* '<S79>/DmpCompSquareRevVs1' */
  UInt32 m_bpIndex_ihei;               /* '<S79>/DmpCompSquareRevVs3' */
  UInt32 m_bpIndex_isy5;               /* '<S79>/DmpCompSquareRevVs2' */
  UInt32 m_bpIndex_gmao;               /* '<S79>/DmpQuadVehReturn4' */
  UInt32 m_bpIndex_cr4p;               /* '<S79>/DmpQuadVehReturn1' */
  UInt32 m_bpIndex_dbcy;               /* '<S79>/DmpQuadVehReturn3' */
  UInt32 m_bpIndex_fofr;               /* '<S79>/DmpQuadVehReturn2' */
  UInt32 m_bpIndex_jquz;               /* '<S78>/DampCompDTrq' */
  UInt32 m_bpIndex_mlpg;               /* '<S78>/DampCompTrq' */
  UInt32 m_bpIndex_pjgy;               /* '<S3>/TempLimit' */
  UInt32 m_bpIndex_ffhg;               /* '<S3>/PowerLimit' */
  UInt32 m_bpIndex_hpm0;               /* '<S22>/TorqueCoef1CM' */
  UInt32 m_bpIndex_c24y;               /* '<S22>/TorqueCoef1SP' */
  UInt32 m_bpIndex_dam5;               /* '<S22>/TorqueCoef1ST' */
  UInt32 m_bpIndex_bmac;               /* '<S22>/TorqueCoef3CM' */
  UInt32 m_bpIndex_ld0g;               /* '<S22>/TorqueCoef3SP' */
  UInt32 m_bpIndex_dz3t;               /* '<S22>/TorqueCoef3ST' */
  UInt32 m_bpIndex_neew;               /* '<S21>/DamperCoef' */
  UInt32 m_bpIndex_ndwh;               /* '<S21>/DamperCoefNew' */
  ANGLE_STS LearnValidOut;             /* '<S160>/StudyProcess_Store' */
  ANGLE_STS LearnValid;                /* '<S160>/StudyProcess_Auto' */
  ANGLE_STS last_learnflag;            /* '<S160>/StudyProcess_Store' */
  struct {
    UInt32 is_c3_AssistControl:2;      /* '<S160>/StudyProcess_Auto' */
    UInt32 is_c17_AssistControl:2;     /* '<S126>/PredrveControl' */
    UInt32 is_active_c3_AssistControl:1;/* '<S160>/StudyProcess_Auto' */
    UInt32 is_active_c17_AssistControl:1;/* '<S126>/PredrveControl' */
    UInt32 is_active_c4_AssistControl:1;/* '<S104>/HighFailLimit_fun2' */
    UInt32 is_active_c16_AssistControl:1;/* '<S104>/HighFailLimit_fun1' */
    UInt32 is_active_c19_AssistControl:1;/* '<S103>/FailCloseFlagCtrl' */
    UInt32 is_active_c20_AssistControl:1;/* '<S59>/assitreclimit' */
    UInt32 rightok:1;                  /* '<S160>/StudyProcess_Auto' */
    UInt32 leftok:1;                   /* '<S160>/StudyProcess_Auto' */
    UInt32 startsave:1;                /* '<S160>/StudyProcess_Auto' */
  } bitsForTID0;

  Int16 hs_compaim;                    /* '<S110>/Merge' */
  Int16 MultiportSwitch2;              /* '<S79>/Multiport Switch2' */
  Int16 bsslimit;                      /* '<S59>/assitreclimit' */
  Int16 trqsign;                       /* '<S111>/Sign' */
  Int16 EndZone;                       /* '<S159>/Merge' */
  Int16 hs_comprate;                   /* '<S113>/Multiport Switch' */
  Int16 trqabs;                        /* '<S111>/Abs' */
  Int16 delayst;                       /* '<S78>/ARDelayFilter1' */
  Int16 Delay_DSTATE_owvw;             /* '<S22>/Delay' */
  Int16 DelayInput1_DSTATE;            /* '<S112>/Delay Input1' */
  Int16 delayst_leyx;                  /* '<S78>/ARDelayFilter2' */
  Int16 delayst_miku;                  /* '<S76>/ARDelayFilter1' */
  Int16 ARDelayFilter1_DSTATE;         /* '<S22>/ARDelayFilter1' */
  Int16 ARDelayFilter2_DSTATE;         /* '<S22>/ARDelayFilter2' */
  Int16 Delay_DSTATE_ecug;             /* '<S20>/Delay' */
  Int16 leftmin;                       /* '<S160>/StudyProcess_Auto' */
  Int16 rightmax;                      /* '<S160>/StudyProcess_Auto' */
  Int16 bssrate;                       /* '<S59>/assitreclimit' */
  UInt16 learncnt0;                    /* '<S160>/StudyProcess_Auto' */
  UInt16 learncnt1;                    /* '<S160>/StudyProcess_Auto' */
  UInt16 learncnt2;                    /* '<S160>/StudyProcess_Auto' */
  UInt16 learncnt3;                    /* '<S160>/StudyProcess_Auto' */
  UInt16 cnt;                          /* '<S158>/RevEndLiimit' */
  UInt16 stall_fallcnt;                /* '<S147>/StallProcess_stall' */
  UInt16 prectrl_count1;               /* '<S126>/PredrveControl' */
  UInt16 prectrl_count2;               /* '<S126>/PredrveControl' */
  UInt16 down_delay1;                  /* '<S103>/FailCloseFlagCtrl' */
  UInt16 down_delay2;                  /* '<S103>/FailCloseFlagCtrl' */
  Bool outheatflag;                    /* '<S132>/DelayOverHeat' */
  Bool failclose1;                     /* '<S103>/FailCloseFlagCtrl' */
  Bool failclose2;                     /* '<S103>/FailCloseFlagCtrl' */
  Bool lastfocreset1_DSTATE;           /* '<S58>/lastfocreset1' */
  Bool lastfocreset_DSTATE;            /* '<S58>/lastfocreset' */
  Bool Relay_Mode;                     /* '<S132>/Relay' */
  Bool Relay_Mode_lptv;                /* '<S10>/Relay' */
} AssistControl_DW_fwu4;

#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

extern void AssistControl_Init(void);
extern void AssistControl(void);

#ifndef AssistControl_MDLREF_HIDE_CHILD_

extern void AssistCon_LowFailLimit_fun_Init(Int32 *rty_TLBF);
extern void AssistControl_LowFailLimit_fun(Int32 rtu_Input, Int32 rtu_dLimit,
  Int32 *rty_TLBF, AssistContr_DW_LowFailLimit_fun *localDW);

#if CACLAIM_MOTORANG_POWERST == 0

extern void Assist_CaclAim_MotorAngState_Ds(void);

#endif

#if CACLAIM_MOTORANG_POWERST == 1

extern void Assist_CaclAim_MotorAngState_En(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 0

extern void Assist_FrictionComp_FrictionRev(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 0

extern void Assist_FrictionComp_FrictionSum(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 0

extern void Ass_FrictionComp_FrictionTorque(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 0

extern void AssistControl_FrictionComp(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void A_FrictionComp_FrictionRev_k5w4(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void A_FrictionComp_FrictionSum_ng1w(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void FrictionComp_FrictionTorqu_gwno(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void AssistControl_FrictionComp_Cal(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void AssistControl_FCA_StudyProcess(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void AssistContro_FCA_StudyStartCond(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void AssistControl_FCA_StudyTorque(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void AssistContro_FrictionComp_Study(void);

#endif

#if MACRO_FRICTION_COMP_SELECT == 1

extern void AssistContr_FrictionCompAdptive(void);

#endif

#if STEEREND_ZONE_VARIABLE == 1

extern void AssistContr_SteeringEnd_DecZone(void);

#endif

extern void AssistContr_ActiveReturn_AimRev(void);
extern void AssistCon_ActiveReturn_Pcontrol(void);
extern void Assist_ActiveReturn_TorqueLimit(void);
extern void AssistControl_ActiveReturn(void);
extern void Assis_BasicAsist_DirectFeedComp(void);
extern void AssistCont_BasicAsist_LimitedBT(void);
extern void Assi_BasicAsist_LookAssistCurve(void);
extern void AssistC_BasicAsist_OffCenterSAT(void);
extern void AssistContr_BasicAsistantTorque(void);
extern void AssistControl_BatteryTempLimit(void);
extern void AssistCo_CurrentORG_APA_LKA_LDW(void);
extern void AssistContro_CaclAim_CurrentORG(void);
extern void AssistCont_CalcAim_CurrentState(void);
extern void AssistControl_CalcAim_FOCState(void);
extern void AssistControl_CaclAimCurrent(void);
extern void AssistContro_Dampercomp_BasicDC(void);
extern void AssistContro_Dampercomp_DCLimit(void);
extern void AssistControl_Dampercomp_TdTcf(void);
extern void AssistControl_Dampercomp_Vscf(void);
extern void AssistControl_Dampercomp(void);
extern void AssistControl_FrictionComp_pk25(void);
extern void AssistC_HighFailLimit_FailClose(void);
extern void AssistContr_HighFailLimit_Logic(void);
extern void AssistControl_HighFailLimit(void);
extern void AssistControl_Hysteresis_aim(void);
extern void AssistControl_Hysteresis_dir(void);
extern void AssistControl_Hysteresis_rate(void);
extern void AssistControl_Hysteresis(void);
extern void AssistControl_InertiaComp(void);
extern void AssistControl_LeaveReturnStatus(void);
extern void AssistC_LowFailLimit_Logic_Init(void);
extern void AssistContro_LowFailLimit_Logic(void);
extern void AssistCo_LowFailLimit_Predriver(void);
extern void AssistControl_LowFailLimit_Init(void);
extern void AssistControl_LowFailLimit(void);
extern void Assi_OverHeating_CalcActCurrent(void);
extern void Assis_OverHeating_CalcHeatValue(void);
extern void OverHeating_CurrentPercent_Init(void);
extern void Assi_OverHeating_CurrentPercent(void);
extern void Assist_OverHeatingIdentity_Init(void);
extern void AssistContr_OverHeatingIdentity(void);
extern void AssistControl_SemiRedundant(void);
extern void AssistC_StallProcess_compAtomic(void);
extern void Assist_StallProcess_stallAtomic(void);
extern void StallProcess_stallAtomic_TaimMa(void);
extern void As_StallProcess_stall_AtomicNew(void);
extern void AssistControl_StallProcess(void);
extern void AssistCont_SteeringEnd_EndLimit(void);
extern void Assis_SteeringEnd_EndSpringDamp(void);
extern void AssistContr_SteeringEnd_EndZone(void);
extern void A_SteeringEnd_StudyProcess_Init(void);
extern void Assist_SteeringEnd_StudyProcess(void);
extern void AssistControl_SteeringEnd_Init(void);
extern void AssistControl_SteeringEnd(void);
extern void AssistCo_TempSampFailLimit_Init(void);
extern void AssistControl_TempSampFailLimit(void);
extern void AssistControl_TorqueAimGether(void);
extern void AssistControl_TorqueAimLimit(void);

#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

#ifndef AssistControl_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern AssistControl_DW_fwu4 AssistControlrtDW;

#endif                                 /*AssistControl_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'AssistControl'
 * '<S1>'   : 'AssistControl/ActiveReturn'
 * '<S2>'   : 'AssistControl/BasicAsistantTorque'
 * '<S3>'   : 'AssistControl/BatteryTempLimit'
 * '<S4>'   : 'AssistControl/CaclAimCurrent'
 * '<S5>'   : 'AssistControl/Dampercomp'
 * '<S6>'   : 'AssistControl/FrictionComp'
 * '<S7>'   : 'AssistControl/HighFailLimit'
 * '<S8>'   : 'AssistControl/Hysteresis'
 * '<S9>'   : 'AssistControl/InertiaComp'
 * '<S10>'  : 'AssistControl/LeaveReturnStatus'
 * '<S11>'  : 'AssistControl/LowFailLimit'
 * '<S12>'  : 'AssistControl/OverHeatingIdentity'
 * '<S13>'  : 'AssistControl/SemiRedundant'
 * '<S14>'  : 'AssistControl/StallProcess'
 * '<S15>'  : 'AssistControl/SteeringEnd'
 * '<S16>'  : 'AssistControl/TempSampFailLimit'
 * '<S17>'  : 'AssistControl/TorqueAimGether'
 * '<S18>'  : 'AssistControl/TorqueAimLimit'
 * '<S19>'  : 'AssistControl/ActiveReturn/ActiveReturn_AimRev'
 * '<S20>'  : 'AssistControl/ActiveReturn/ActiveReturn_LeftRight'
 * '<S21>'  : 'AssistControl/ActiveReturn/ActiveReturn_Pcontrol'
 * '<S22>'  : 'AssistControl/ActiveReturn/ActiveReturn_TorqueLimit'
 * '<S23>'  : 'AssistControl/ActiveReturn/ActiveReturn_AimRev/Compare To Zero'
 * '<S24>'  : 'AssistControl/ActiveReturn/ActiveReturn_LeftRight/Saturation Dynamic'
 * '<S25>'  : 'AssistControl/ActiveReturn/ActiveReturn_LeftRight/SaturationDynamic'
 * '<S26>'  : 'AssistControl/ActiveReturn/ActiveReturn_LeftRight/comp'
 * '<S27>'  : 'AssistControl/ActiveReturn/ActiveReturn_LeftRight/comp1'
 * '<S28>'  : 'AssistControl/ActiveReturn/ActiveReturn_LeftRight/comp2'
 * '<S29>'  : 'AssistControl/ActiveReturn/ActiveReturn_LeftRight/comp3'
 * '<S30>'  : 'AssistControl/ActiveReturn/ActiveReturn_TorqueLimit/SaturationDynamic'
 * '<S31>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_DirectFeedComp'
 * '<S32>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LimitedBT'
 * '<S33>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LookAssistCurve'
 * '<S34>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_OffCenterSAT'
 * '<S35>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_OnCenterKick'
 * '<S36>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_RobustfilterFun'
 * '<S37>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_TorqueSoftAdv2'
 * '<S38>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_ToruqeNotchFilter'
 * '<S39>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LimitedBT/Data Type Scaling Strip'
 * '<S40>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LimitedBT/Saturation Dynamic'
 * '<S41>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LimitedBT/Saturation Dynamic1'
 * '<S42>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LookAssistCurve/Assist_Select'
 * '<S43>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LookAssistCurve/Assist_Select/CalibAss'
 * '<S44>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_LookAssistCurve/Assist_Select/ReactorAss'
 * '<S45>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_OffCenterSAT/Call_OffCenterSAT'
 * '<S46>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_OffCenterSAT/Call_OffCenterSAT/fixdt1q7'
 * '<S47>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_OnCenterKick/Call_OnCenterKick'
 * '<S48>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_OnCenterKick/Call_OnCenterKick/fixdt1q7'
 * '<S49>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_RobustfilterFun/Call_RobustfilterFun'
 * '<S50>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_RobustfilterFun/Call_RobustfilterFun/fixdt1q7'
 * '<S51>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_TorqueSoftAdv2/Call_TorqueSoftAdv2'
 * '<S52>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_TorqueSoftAdv2/Call_TorqueSoftAdv2/fixdt1q7'
 * '<S53>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_ToruqeNotchFilter/Call_ToruqeNotchFilter'
 * '<S54>'  : 'AssistControl/BasicAsistantTorque/BasicAsist_ToruqeNotchFilter/Call_ToruqeNotchFilter/fixdt1q7'
 * '<S55>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG'
 * '<S56>'  : 'AssistControl/CaclAimCurrent/CaclAim_MotorAngState'
 * '<S57>'  : 'AssistControl/CaclAimCurrent/CalcAim_CurrentState'
 * '<S58>'  : 'AssistControl/CaclAimCurrent/CalcAim_FOCState'
 * '<S59>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_APA_LKA_LDW'
 * '<S60>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_Torque2Current'
 * '<S61>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_APA_LKA_LDW/Compare To Constant'
 * '<S62>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_APA_LKA_LDW/Compare To Constant1'
 * '<S63>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_APA_LKA_LDW/Compare To Constant2'
 * '<S64>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_APA_LKA_LDW/Compare To Zero1'
 * '<S65>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_APA_LKA_LDW/Saturation Dynamic'
 * '<S66>'  : 'AssistControl/CaclAimCurrent/CaclAim_CurrentORG/CurrentORG_APA_LKA_LDW/assitreclimit'
 * '<S67>'  : 'AssistControl/CaclAimCurrent/CaclAim_MotorAngState/CaclAim_MotorAngState_Ds'
 * '<S68>'  : 'AssistControl/CaclAimCurrent/CaclAim_MotorAngState/CaclAim_MotorAngState_En'
 * '<S69>'  : 'AssistControl/CaclAimCurrent/CaclAim_MotorAngState/CaclAim_MotorAngState_En/Compare To Constant2'
 * '<S70>'  : 'AssistControl/CaclAimCurrent/CaclAim_MotorAngState/CaclAim_MotorAngState_En/MotorPositionWork'
 * '<S71>'  : 'AssistControl/CaclAimCurrent/CalcAim_CurrentState/Compare To Constant'
 * '<S72>'  : 'AssistControl/CaclAimCurrent/CalcAim_CurrentState/Compare To Constant1'
 * '<S73>'  : 'AssistControl/CaclAimCurrent/CalcAim_FOCState/Compare To Constant3'
 * '<S74>'  : 'AssistControl/CaclAimCurrent/CalcAim_FOCState/Compare To Constant4'
 * '<S75>'  : 'AssistControl/CaclAimCurrent/CalcAim_FOCState/Compare To Constant5'
 * '<S76>'  : 'AssistControl/Dampercomp/Dampercomp_BasicDC'
 * '<S77>'  : 'AssistControl/Dampercomp/Dampercomp_DCLimit'
 * '<S78>'  : 'AssistControl/Dampercomp/Dampercomp_TdTcf'
 * '<S79>'  : 'AssistControl/Dampercomp/Dampercomp_Vscf'
 * '<S80>'  : 'AssistControl/Dampercomp/Dampercomp_DCLimit/Saturation Dynamic'
 * '<S81>'  : 'AssistControl/FrictionComp/FrictionComp'
 * '<S82>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionComp'
 * '<S83>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive'
 * '<S84>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionComp/FrictionComp_FrictionRev'
 * '<S85>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionComp/FrictionComp_FrictionSum'
 * '<S86>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionComp/FrictionComp_FrictionTorque'
 * '<S87>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionComp/FrictionComp_FrictionSum/Compare To Constant'
 * '<S88>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Cal'
 * '<S89>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study'
 * '<S90>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Cal/FrictionComp_FrictionRev'
 * '<S91>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Cal/FrictionComp_FrictionSum'
 * '<S92>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Cal/FrictionComp_FrictionTorque'
 * '<S93>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Cal/FrictionComp_FrictionSum/Compare To Constant'
 * '<S94>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyProcess'
 * '<S95>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyStartCond'
 * '<S96>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyTorque'
 * '<S97>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyProcess/StudyProcess'
 * '<S98>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyStartCond/Compare To Constant'
 * '<S99>'  : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyStartCond/Compare To Constant1'
 * '<S100>' : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyStartCond/Compare To Constant2'
 * '<S101>' : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyStartCond/Compare To Constant3'
 * '<S102>' : 'AssistControl/FrictionComp/FrictionComp/FrictionCompAdptive/FrictionComp_Study/FCA_StudyStartCond/Compare To Constant4'
 * '<S103>' : 'AssistControl/HighFailLimit/HighFailLimit_FailClose'
 * '<S104>' : 'AssistControl/HighFailLimit/HighFailLimit_Logic'
 * '<S105>' : 'AssistControl/HighFailLimit/HighFailLimit_FailClose/Compare To Constant'
 * '<S106>' : 'AssistControl/HighFailLimit/HighFailLimit_FailClose/Compare To Constant1'
 * '<S107>' : 'AssistControl/HighFailLimit/HighFailLimit_FailClose/FailCloseFlagCtrl'
 * '<S108>' : 'AssistControl/HighFailLimit/HighFailLimit_Logic/HighFailLimit_fun1'
 * '<S109>' : 'AssistControl/HighFailLimit/HighFailLimit_Logic/HighFailLimit_fun2'
 * '<S110>' : 'AssistControl/Hysteresis/Hysteresis_aim'
 * '<S111>' : 'AssistControl/Hysteresis/Hysteresis_dir'
 * '<S112>' : 'AssistControl/Hysteresis/Hysteresis_rate'
 * '<S113>' : 'AssistControl/Hysteresis/Hysteresis_aim/calc_rate'
 * '<S114>' : 'AssistControl/Hysteresis/Hysteresis_aim/hscond'
 * '<S115>' : 'AssistControl/Hysteresis/Hysteresis_aim/hselse'
 * '<S116>' : 'AssistControl/Hysteresis/Hysteresis_aim/hsif'
 * '<S117>' : 'AssistControl/Hysteresis/Hysteresis_aim/hscond/Compare To Constant'
 * '<S118>' : 'AssistControl/Hysteresis/Hysteresis_dir/Dead Zone Dynamic'
 * '<S119>' : 'AssistControl/Hysteresis/Hysteresis_dir/Dead Zone Dynamic1'
 * '<S120>' : 'AssistControl/Hysteresis/Hysteresis_rate/Saturation Dynamic1'
 * '<S121>' : 'AssistControl/LeaveReturnStatus/Compare To Zero'
 * '<S122>' : 'AssistControl/LeaveReturnStatus/Compare To Zero1'
 * '<S123>' : 'AssistControl/LeaveReturnStatus/Compare To Zero2'
 * '<S124>' : 'AssistControl/LeaveReturnStatus/Compare To Zero3'
 * '<S125>' : 'AssistControl/LowFailLimit/LowFailLimit_Logic'
 * '<S126>' : 'AssistControl/LowFailLimit/LowFailLimit_Predriver'
 * '<S127>' : 'AssistControl/LowFailLimit/LowFailLimit_Logic/LowFailLimit_fun'
 * '<S128>' : 'AssistControl/LowFailLimit/LowFailLimit_Predriver/Compare To Zero'
 * '<S129>' : 'AssistControl/LowFailLimit/LowFailLimit_Predriver/Compare To Zero1'
 * '<S130>' : 'AssistControl/LowFailLimit/LowFailLimit_Predriver/PredrveControl'
 * '<S131>' : 'AssistControl/OverHeatingIdentity/OverHeating_CalcActCurrent'
 * '<S132>' : 'AssistControl/OverHeatingIdentity/OverHeating_CalcHeatValue'
 * '<S133>' : 'AssistControl/OverHeatingIdentity/OverHeating_CurrentPercent'
 * '<S134>' : 'AssistControl/OverHeatingIdentity/OverHeating_CalcActCurrent/strip'
 * '<S135>' : 'AssistControl/OverHeatingIdentity/OverHeating_CalcHeatValue/Comp'
 * '<S136>' : 'AssistControl/OverHeatingIdentity/OverHeating_CalcHeatValue/DelayOverHeat'
 * '<S137>' : 'AssistControl/OverHeatingIdentity/OverHeating_CurrentPercent/Compare'
 * '<S138>' : 'AssistControl/OverHeatingIdentity/OverHeating_CurrentPercent/Compare To Constant'
 * '<S139>' : 'AssistControl/SemiRedundant/GenSemiCurrent'
 * '<S140>' : 'AssistControl/SemiRedundant/n1n2y1y2'
 * '<S141>' : 'AssistControl/SemiRedundant/n1y2'
 * '<S142>' : 'AssistControl/SemiRedundant/y1n2'
 * '<S143>' : 'AssistControl/StallProcess/StallProcess_compAtomic'
 * '<S144>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew'
 * '<S145>' : 'AssistControl/StallProcess/StallProcess_compAtomic/Compare To Constant'
 * '<S146>' : 'AssistControl/StallProcess/StallProcess_compAtomic/StallProcess_comp'
 * '<S147>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic'
 * '<S148>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic_TaimMax'
 * '<S149>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic/StallProcess_stall'
 * '<S150>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic_TaimMax/Compare To Zero'
 * '<S151>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic_TaimMax/Compare To Zero1'
 * '<S152>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic_TaimMax/Compare To Zero2'
 * '<S153>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic_TaimMax/Compare To Zero3'
 * '<S154>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic_TaimMax/Saturation Dynamic'
 * '<S155>' : 'AssistControl/StallProcess/StallProcess_stall_AtomicNew/StallProcess_stallAtomic_TaimMax/SaturationDynamic'
 * '<S156>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone'
 * '<S157>' : 'AssistControl/SteeringEnd/SteeringEnd_EndLimit'
 * '<S158>' : 'AssistControl/SteeringEnd/SteeringEnd_EndSpringDamp'
 * '<S159>' : 'AssistControl/SteeringEnd/SteeringEnd_EndZone'
 * '<S160>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess'
 * '<S161>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_DecZone'
 * '<S162>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_None'
 * '<S163>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_DecZone/SheduleCounter'
 * '<S164>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_DecZone/VariantEndAngle'
 * '<S165>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_DecZone/VariantEndAngle/calc_variantend'
 * '<S166>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_DecZone/VariantEndAngle/getanglest'
 * '<S167>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_DecZone/VariantEndAngle/calc_variantend/fixdtvstoang'
 * '<S168>' : 'AssistControl/SteeringEnd/SteeringEnd_DecZone/SteeringEnd_DecZone/VariantEndAngle/calc_variantend/fixdtvstoang/Data Type Scaling Strip'
 * '<S169>' : 'AssistControl/SteeringEnd/SteeringEnd_EndLimit/BassicTrqLimit'
 * '<S170>' : 'AssistControl/SteeringEnd/SteeringEnd_EndLimit/Compare To Constant'
 * '<S171>' : 'AssistControl/SteeringEnd/SteeringEnd_EndLimit/Compare To Constant2'
 * '<S172>' : 'AssistControl/SteeringEnd/SteeringEnd_EndSpringDamp/RevEndLiimit'
 * '<S173>' : 'AssistControl/SteeringEnd/SteeringEnd_EndZone/DriveVsComp'
 * '<S174>' : 'AssistControl/SteeringEnd/SteeringEnd_EndZone/angle_cond'
 * '<S175>' : 'AssistControl/SteeringEnd/SteeringEnd_EndZone/elsecd'
 * '<S176>' : 'AssistControl/SteeringEnd/SteeringEnd_EndZone/elseifcd'
 * '<S177>' : 'AssistControl/SteeringEnd/SteeringEnd_EndZone/ifcd'
 * '<S178>' : 'AssistControl/SteeringEnd/SteeringEnd_EndZone/angle_cond/Data Type Scaling Strip'
 * '<S179>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Auto'
 * '<S180>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond'
 * '<S181>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Store'
 * '<S182>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond/Compare To Constant'
 * '<S183>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond/Compare To Constant1'
 * '<S184>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond/Compare To Constant2'
 * '<S185>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond/Compare To Constant3'
 * '<S186>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond/Compare To Constant4'
 * '<S187>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond/Compare To Constant5'
 * '<S188>' : 'AssistControl/SteeringEnd/SteeringEnd_StudyProcess/StudyProcess_Cond/Compare To Constant6'
 * '<S189>' : 'AssistControl/TempSampFailLimit/Compare To Zero'
 * '<S190>' : 'AssistControl/TempSampFailLimit/TempSampFailLimit_fun'
 */

/*-
 * Requirements for '<Root>': AssistControl
 */
#endif                                 /* RTW_HEADER_AssistControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
