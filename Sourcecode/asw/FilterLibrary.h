/*
 * File: NewCode.h
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.599
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 30 10:22:14 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NewCode_h_
#define RTW_HEADER_NewCode_h_
#ifndef eps_controlAlgorithm_COMMON_INCLUDES_
# define eps_controlAlgorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                               /* eps_controlAlgorithm_COMMON_INCLUDES_ */

#include "eps_controlAlgorithm_types.h"

#define MACRO_SAT_HFBACK_DZ            640                       /* conv:2^-7Nm , val:5 , min-max:0~8 */
#define MACRO_TQ_MAX_TORQP             17613                     /* conv:2^-10Nm , val:17.2 , min-max:16~20 */


/* Block signals and states (default storage) for system '<S155>/OffCenterSAT' */
typedef struct {
  Float64 offcenterfilter_states;      /* '<S191>/offcenterfilter' */
  Float64 offcenterfilter_denStates;   /* '<S191>/offcenterfilter' */
  Float64 offcenterfilter_tmp;         /* '<S191>/offcenterfilter' */
  UInt32 m_bpIndex;                    /* '<S191>/vsocsat' */
} DW_OffCenterSAT;

/* Block signals and states (default storage) for system '<S155>/OnCenterKick' */
typedef struct {
  Float64 DataStoreRead3[4];           /* '<S192>/Data Store Read3' */
  Float64 DataStoreRead4[4];           /* '<S192>/Data Store Read4' */
  Float64 oncenterhf_states;           /* '<S192>/oncenterhf' */
  Float64 oncenterhf_denStates;        /* '<S192>/oncenterhf' */
  Float64 oncenterlf_states;           /* '<S192>/oncenterlf' */
  Float64 oncenterlf_denStates;        /* '<S192>/oncenterlf' */
  Float64 oncenterhf_tmp;              /* '<S192>/oncenterhf' */
  Float64 oncenterlf_tmp;              /* '<S192>/oncenterlf' */
  UInt32 m_bpIndex;                    /* '<S192>/vsockick' */
  UInt32 m_bpIndex_fn1k;               /* '<S192>/trqockick' */
} DW_OnCenterKick;

/* Block signals and states (default storage) for system '<S155>/RobustfilterFun' */
typedef struct {
  Float64 filtercof[6];                /* '<S193>/filtercof' */
  Float64 robustfilter_states[2];      /* '<S193>/robustfilter' */
  Float64 robustfilter_denStates[2];   /* '<S193>/robustfilter' */
  Float64 robustfilter_tmp;            /* '<S193>/robustfilter' */
} DW_RobustfilterFun;

/* Block signals and states (default storage) for system '<S155>/TorqueSoftAdv2' */
typedef struct {
  Float64 advancedfilter2_states;      /* '<S194>/advancedfilter2' */
  Float64 advancedfilter2_denStates;   /* '<S194>/advancedfilter2' */
  Float64 advancedfilter2_tmp;         /* '<S194>/advancedfilter2' */
} DW_TorqueSoftAdv2;

/* Block signals and states (default storage) for system '<S155>/ToruqeNotchFilter' */
typedef struct {
  Float64 filtercof[6];                /* '<S195>/filtercof' */
  Float64 notchfilter_states[2];       /* '<S195>/notchfilter' */
  Float64 notchfilter_denStates[2];    /* '<S195>/notchfilter' */
  Float64 notchfilter_tmp;             /* '<S195>/notchfilter' */
} DW_ToruqeNotchFilter;

/* Block signals and states (default storage) for system '<S309>/TorqueSoftAdv' */
typedef struct {
  Float64 advancedphase_states;        /* '<S364>/advancedphase' */
  Float64 advancedphase_denStates;     /* '<S364>/advancedphase' */
  Float64 lowfilter_denStates;         /* '<S364>/lowfilter' */
  Float64 advancedphase_tmp;           /* '<S364>/advancedphase' */
  Float64 lowfilter_tmp;               /* '<S364>/lowfilter' */
} DW_TorqueSoftAdv;

/* Block signals and states (default storage) for system '<S309>/ToruqeStableFilter' */
typedef struct {
  Float64 filtercof[4];                /* '<S365>/filtercof' */
  Float64 fedforward_states;           /* '<S365>/fedforward' */
  Float64 fedforward_denStates;        /* '<S365>/fedforward' */
  Float64 fedforward_tmp;              /* '<S365>/fedforward' */
} DW_ToruqeStableFilter;

/* Extern declarations of internal data for system '<S155>/OffCenterSAT' */
extern DW_OffCenterSAT rtOffCenterSAT_DW;

/* Extern declarations of internal data for system '<S155>/OnCenterKick' */
extern DW_OnCenterKick rtOnCenterKick_DW;
extern void OffCenterSAT(void);
extern void OnCenterKick(void);
extern void RobustfilterFun(void);
extern void TorqueSoftAdv2(void);
extern void ToruqeNotchFilter(void);
extern void TorqueSoftAdv(void);
extern void ToruqeStableFilter(void);
extern Int16 TorqueSoftAdv2_SSW(Int16 bassin);
extern DW_TorqueSoftAdv rtTorqueSoftAdv_DW;
#endif                                 /* RTW_HEADER_NewCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
