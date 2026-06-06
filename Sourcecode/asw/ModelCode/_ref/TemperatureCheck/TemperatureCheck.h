/*
 * File: TemperatureCheck.h
 *
 * Code generated for Simulink model 'TemperatureCheck'.
 *
 * Model version                  : 1.1125
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Aug 18 15:35:32 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TemperatureCheck_h_
#define RTW_HEADER_TemperatureCheck_h_
#ifndef TemperatureCheck_COMMON_INCLUDES_
# define TemperatureCheck_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TemperatureCheck_COMMON_INCLUDES_ */

#include "TemperatureCheck_types.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "GlobalVar.h"
#include "CalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for system '<S1>/TemperatureCheck_Calc_CP' */
#ifndef TemperatureCheck_MDLREF_HIDE_CHILD_
#if MACRO_TEMP_DP_ENABLE == 0

typedef struct {
  UInt32 m_bpIndex;                    /* '<S6>/temptable' */
} Tem_DW_TemperatureCheck_Calc_CP;

#endif
#endif                                 /*TemperatureCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S1>/TemperatureCheck_Calc_DP' */
#ifndef TemperatureCheck_MDLREF_HIDE_CHILD_
#if MACRO_TEMP_DP_ENABLE == 1

typedef struct {
  UInt32 m_bpIndex;                    /* '<S8>/temptable' */
} Tem_DW_TemperatureCheck_Calc_DP;

#endif
#endif                                 /*TemperatureCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S10>/TempLevelCheck' */
#ifndef TemperatureCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_TEMPLEVEL == 0

typedef struct {
  struct {
    UInt32 is_c77_TemperatureCheck:3;  /* '<S11>/TempManagement' */
    UInt32 is_active_c77_TemperatureCheck:1;/* '<S11>/TempManagement' */
  } bitsForTID0;

  UInt16 TempCheckTimel;               /* '<S11>/TempManagement' */
  UInt16 TempCheckTimeo;               /* '<S11>/TempManagement' */
  UInt16 TempCheckTimen;               /* '<S11>/TempManagement' */
} TemperatureCh_DW_TempLevelCheck;

#endif
#endif                                 /*TemperatureCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S15>/TempVolCheck' */
#ifndef TemperatureCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_TEMPVOL == 0

typedef struct {
  struct {
    UInt32 is_TempSensorRangeCheck:2;  /* '<S16>/TempSignalCheck' */
    UInt32 is_TempEstHeat:2;           /* '<S16>/TempSignalCheck' */
    UInt32 is_active_c78_TemperatureCheck:1;/* '<S16>/TempSignalCheck' */
  } bitsForTID0;

  UInt16 TS_TimeWink;                  /* '<S16>/TempSignalCheck' */
  UInt16 TS_TimeWinj;                  /* '<S16>/TempSignalCheck' */
  UInt16 TSE_TimeWink;                 /* '<S16>/TempSignalCheck' */
  UInt16 TSE_TimeWinj;                 /* '<S16>/TempSignalCheck' */
} TemperatureChec_DW_TempVolCheck;

#endif
#endif                                 /*TemperatureCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'TemperatureCheck' */
#ifndef TemperatureCheck_MDLREF_HIDE_CHILD_

typedef struct {

#if DIAGDIS_TEMPVOL == 0

  TemperatureChec_DW_TempVolCheck TempVolCheck_bkta;/* '<S15>/TempVolCheck' */

#define TEMPERATURECHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_TEMPLEVEL == 0

  TemperatureCh_DW_TempLevelCheck TempLevelCheck_po3n;/* '<S10>/TempLevelCheck' */

#define TEMPERATURECHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if MACRO_TEMP_DP_ENABLE == 1

  Tem_DW_TemperatureCheck_Calc_DP TemperatureCheck_Calc_DP;/* '<S1>/TemperatureCheck_Calc_DP' */

#define TEMPERATURECHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if MACRO_TEMP_DP_ENABLE == 0

  Tem_DW_TemperatureCheck_Calc_CP TemperatureCheck_Calc_CP;/* '<S1>/TemperatureCheck_Calc_CP' */

#define TEMPERATURECHECK_DW_FWU4_VARIANT_EXISTS
#endif

  Int16 Fv_TempSysCel_ibrv;
  UInt16 Fv_TempVol_morp;
} TemperatureCheck_DW_fwu4;

#endif                                 /*TemperatureCheck_MDLREF_HIDE_CHILD_*/

extern void TemperatureCheck(void);

#ifndef TemperatureCheck_MDLREF_HIDE_CHILD_
#if MACRO_TEMP_DP_ENABLE == 0

extern void Te_TemperatureCheck_Calc_Atomic(void);

#endif

#if MACRO_TEMP_DP_ENABLE == 1

extern void TemperatureCheck_Calc_Atom_ahhn(void);

#endif

extern void Temperat_TemperatureCheck_Level(void);
extern void Temperatur_TemperatureCheck_Vol(void);

#endif                                 /*TemperatureCheck_MDLREF_HIDE_CHILD_*/

#ifndef TemperatureCheck_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern TemperatureCheck_DW_fwu4 TemperatureCheckrtDW;

#endif                                 /*TemperatureCheck_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'TemperatureCheck'
 * '<S1>'   : 'TemperatureCheck/TemperatureCheck_Calc'
 * '<S2>'   : 'TemperatureCheck/TemperatureCheck_Level'
 * '<S3>'   : 'TemperatureCheck/TemperatureCheck_Vol'
 * '<S4>'   : 'TemperatureCheck/TemperatureCheck_Calc/TemperatureCheck_Calc_CP'
 * '<S5>'   : 'TemperatureCheck/TemperatureCheck_Calc/TemperatureCheck_Calc_DP'
 * '<S6>'   : 'TemperatureCheck/TemperatureCheck_Calc/TemperatureCheck_Calc_CP/TemperatureCheck_Calc_Atomic'
 * '<S7>'   : 'TemperatureCheck/TemperatureCheck_Calc/TemperatureCheck_Calc_CP/TemperatureCheck_Calc_Atomic/Compare To Zero'
 * '<S8>'   : 'TemperatureCheck/TemperatureCheck_Calc/TemperatureCheck_Calc_DP/TemperatureCheck_Calc_Atomic'
 * '<S9>'   : 'TemperatureCheck/TemperatureCheck_Calc/TemperatureCheck_Calc_DP/TemperatureCheck_Calc_Atomic/Compare To Zero'
 * '<S10>'  : 'TemperatureCheck/TemperatureCheck_Level/TempLevelCheck'
 * '<S11>'  : 'TemperatureCheck/TemperatureCheck_Level/TempLevelCheck/TempLevelCheck'
 * '<S12>'  : 'TemperatureCheck/TemperatureCheck_Level/TempLevelCheck/TempLevelCheckDis'
 * '<S13>'  : 'TemperatureCheck/TemperatureCheck_Level/TempLevelCheck/TempLevelCheck/TempManagement'
 * '<S14>'  : 'TemperatureCheck/TemperatureCheck_Level/TempLevelCheck/TempLevelCheck/TempManagement/getDTCEnabled'
 * '<S15>'  : 'TemperatureCheck/TemperatureCheck_Vol/TempVolCheck'
 * '<S16>'  : 'TemperatureCheck/TemperatureCheck_Vol/TempVolCheck/TempVolCheck'
 * '<S17>'  : 'TemperatureCheck/TemperatureCheck_Vol/TempVolCheck/TempVolCheckDis'
 * '<S18>'  : 'TemperatureCheck/TemperatureCheck_Vol/TempVolCheck/TempVolCheck/TempSignalCheck'
 * '<S19>'  : 'TemperatureCheck/TemperatureCheck_Vol/TempVolCheck/TempVolCheck/TempSignalCheck/DTC_Ctrl_Enabled'
 */

/*-
 * Requirements for '<Root>': TemperatureCheck
 */
#endif                                 /* RTW_HEADER_TemperatureCheck_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
