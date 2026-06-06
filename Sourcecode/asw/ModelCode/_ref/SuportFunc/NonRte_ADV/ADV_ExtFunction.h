/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ADV_ExtFunction.h
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

#ifndef RTW_HEADER_ADV_ExtFunction_h_
#define RTW_HEADER_ADV_ExtFunction_h_
#ifndef ADV_ExtFunction_COMMON_INCLUDES_
#define ADV_ExtFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ADV_ExtFunction_COMMON_INCLUDES_ */

#include "ADV_APA_FUNC.h"
#include "ADV_CCP_PROC.h"
#include "ADV_DSR_FUNC.h"
#include "ADV_HANDSOFF_DETECT.h"
#include "ADV_LDW_FUNC.h"
#include "ADV_LKA_FUNC.h"
#include "ADV_ExtFunction_types.h"

/* Includes for objects with custom storage classes */
#include "SimDiagMacro.h"
#include "CalVarSupport.h"
#include "CalVar.h"
#include "GlobalVarSupport.h"

/* user code (top of header file) */
#include "Common.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  sint32 TmpSignalConversionAtFV_MTR_RTR;
  HOLD TmpSignalConversionAtFV_BHM_MOD;
  sint16 TmpSignalConversionAtFV_TAS_ANG;
  sint16 TmpSignalConversionAtFV_TA_bp5n;
  sint16 TmpSignalConversionAtFV_TA_e3ct;
  sint16 TmpSignalConversionAtFV_TAS_TRQ;
  sint16 TmpSignalConversionAtFV_FRP_FAI;
  sint16 TmpSignalConversionAtFV_FR_bf30;
  sint16 TmpSignalConversionAtFV_FR_g51s;
  sint16 TmpSignalConversionAtFV_FR_jyet;
  uint16 TmpSignalConversionAtFV_CAN_VS_;
  boolean TmpSignalConversionAtFV_CA_l0v1;
} ARID_DEF_ADV_ExtFunction;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ADV_ExtFunction rtARID_DEF_ADV_ExtFunction;

#endif                                 /* RTW_HEADER_ADV_ExtFunction_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
