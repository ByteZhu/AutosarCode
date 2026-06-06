/*
 * File: SuportFunc_ShimmyComp.h
 *
 * Code generated for Simulink model 'SuportFunc'.
 *
 * Model version                  : 1.1560
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Oct 26 12:24:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SuportFunc_ShimmyComp_h_
#define RTW_HEADER_SuportFunc_ShimmyComp_h_
#ifndef SuportFunc_COMMON_INCLUDES_
# define SuportFunc_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SuportFunc_COMMON_INCLUDES_ */


typedef struct {
  Float64 Delay1_DSTATE[2];            /* '<S247>/Delay1' */
  Float64 Delay2_DSTATE[2];            /* '<S247>/Delay2' */
  Float64 Delay_DSTATE;                /* '<S247>/Delay' */
  Float64 Delay3_DSTATE;               /* '<S247>/Delay3' */
  Int32 Delay1_DSTATE_gcyu;            /* '<S235>/Delay1' */
  UInt32 m_bpIndex[2];                 /* '<S236>/shiFreqLookup' */
  UInt32 m_bpIndex_jvcx[2];            /* '<S236>/shiWidthLookup1' */
  UInt32 m_bpIndex_nzfg[2];            /* '<S236>/shiWidthLookup' */
  UInt32 m_bpIndex_gr3m[2];            /* '<S236>/shiGainLookup2' */
  UInt32 m_bpIndex_dqkw[2];            /* '<S236>/shiGainLookup1' */
  UInt32 m_bpIndex_pjqd[2];            /* '<S236>/shiGainLookup' */
  UInt32 m_bpIndex_df1p;               /* '<S235>/shiGainLookup' */
  UInt32 m_bpIndex_df1p_New;               /* '<S235>/shiGainLookupnew' */
  struct {
    UInt32 is_WaveCalc:2;              /* '<S235>/WaveControl_Frez' */
    UInt32 is_Process:2;               /* '<S235>/WaveControl_Frez' */
    UInt32 is_active_c43_SuportFunc:1; /* '<S235>/WaveControl_Frez' */
  } bitsForTID0;

  Int16 D[20];                         /* '<S235>/WaveControl_Frez' */
  Int16 enable;                        /* '<S235>/FreqQuitLogic1' */
  Int16 SpdGrid;                       /* '<S235>/WaveControl_Frez' */
  Int16 trqValueDiff;                  /* '<S235>/WaveControl_Frez' */
  Int16 trqValueDwn;                   /* '<S235>/WaveControl_Frez' */
  Int16 trqValueUp;                    /* '<S235>/WaveControl_Frez' */
  UInt16 WaveTime;                     /* '<S235>/WaveControl_Frez' */
  UInt16 detectCnt;                    /* '<S235>/WaveControl_Frez' */
  UInt16 WaveTmrCnt;                   /* '<S235>/WaveControl_Frez' */
  UInt16 InterTmr;                     /* '<S235>/WaveControl_Frez' */
  UInt16 entrycnt;                     /* '<S235>/FreqQuitLogic1' */
  UInt8 WaveState;                     /* '<S235>/WaveControl_Frez' */
  Bool LogicalOperator15;              /* '<S230>/Logical Operator15' */
} DW_EXT;

typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S236>/shiFreqLookup'
   *   '<S236>/shiGainLookup'
   *   '<S236>/shiGainLookup1'
   *   '<S236>/shiGainLookup2'
   *   '<S236>/shiWidthLookup'
   *   '<S236>/shiWidthLookup1'
   *   '<S38>/apalooktab_ki'
   *   '<S38>/apalooktab_kp'
   *   '<S66>/apalooktab_ki'
   *   '<S66>/apalooktab_kp'
   *   '<S141>/lkalooktab_ki'
   *   '<S141>/lkalooktab_kp'
   */
  UInt32 pooled9[2];
} ConstP_dfsm;

extern void SHIControl_Cond(void);
extern void SHIControl_Trq(void);
extern void SHIControl(void);
extern void SuportFunc_ShimmyComp(void);

#endif                                 /* RTW_HEADER_SuportFunc_ShimmyComp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
