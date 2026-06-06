/*
 * File: DTC_CANCheck.h
 *
 * Code generated for Simulink model 'DTC_CANCheck'.
 *
 * Model version                  : 1.1204
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 21 17:56:45 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DTC_CANCheck_h_
#define RTW_HEADER_DTC_CANCheck_h_
#ifndef DTC_CANCheck_COMMON_INCLUDES_
# define DTC_CANCheck_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DTC_CANCheck_COMMON_INCLUDES_ */

#include "DTC_CANCheck_types.h"

/* Child system includes */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#include "CANDiagnose.h"
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#include "Failsafe.h"
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"
#include "SimDiagMacroCAN.h"
#include "GlobalVarCAN.h"
#include "CalVar.h"
#include "GlobalVar.h"

/* user code (top of header file) */
#include "Common.h"

/* Block signals and states (default storage) for model 'DTC_CANCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_

typedef struct {

#if DIAGDIS_CANSCU == 0

  DTC_CANCheck_DW_CANBUSSCUCheck sf_CANBUSSCUCheck;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CANMPC == 0

  DTC_CANCheck_DW_CANBUSMPCCheck sf_CANBUSMPCCheck;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CANIPB == 0

  DTC_CANCheck_DW_CANBUSIPBCheck sf_CANBUSIPBCheck;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CANEMS == 0

  DTC_CANCheck_DW_CANBUSEMSCheck sf_CANBUSEMSCheck;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

DTC_CANCheck_DW_CANBUSEMSCheck sf_CANBUSCCU1Check;

#if DIAGDIS_CANBCM2 == 0

  DTC_CANCheck_DW_CANBUSBCM2Check sf_CANBUSBCM2Check;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CANAPA == 0

  DTC_CANCheck_DW_CANBUSAPACheck sf_CANBUSAPACheck;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CANABS == 0

  DTC_CANCheck_DW_CANBUSABSCheck sf_CANBUSABSCheck;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

#if DIAGDIS_CANBUSOFF == 0

  DTC_CANCheck_DW_CANBUSOFFCheck sf_CANBUSOFFCheck;

#define DTC_CANCHECK_DW_FWU4_VARIANT_EXISTS
#endif

  POWER_MODE localmode;                /* '<S2>/DTC_Testfailed_Logic' */
  DTC u;                               /* '<S19>/CANCheck_Counter ' */
  FailureDiag Switch;                  /* '<S34>/Switch' */
  struct {
    UInt32 is_CANNodePowerSupplyNm:2;  /* '<S5>/CANNetManagement' */
    UInt32 is_IGON:2;                  /* '<S5>/CANNetManagement' */
    UInt32 is_Psmanag:2;               /* '<S5>/CANNetManagement' */
    UInt32 is_active_c74_DTC_CANCheck:1;/* '<S2>/DTC_Allow_Occur_Logic' */
    UInt32 is_active_c95_DTC_CANCheck:1;/* '<S5>/CANNetManagement' */
    UInt32 lastcanpending:1;           /* '<S5>/CANNetManagement' */
  } bitsForTID0;

  UInt16 CANBusoffRecoverDelay;        /* '<S2>/DTC_Allow_Occur_Logic' */
  UInt16 ps_lostcnt;                   /* '<S5>/CANNetManagement' */
  UInt16 ps_rcvcnt;                    /* '<S5>/CANNetManagement' */
  UInt16 VSI_Invalid_time;
  UInt16 VSI_CRC_time;
  UInt16 WSI_Invalid_time;
  UInt16 WSI_CRC_time;
  UInt8 temp;                          /* '<S2>/DTC_Allow_Occur_Logic' */
} DTC_CANCheck_DW_fwu4;

#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Zero-crossing (trigger) state for model 'DTC_CANCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState CANCheck_Signals_Reset_ZCE;/* '<S1>/CANCheck_Signals' */
} DTC_CANCheck_ZCE;

#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

extern void DTC_CANCheck_Init(void);
extern void DTC_CANCheck(void);

/* Model reference registration function */
extern void DTC_CANCheck_initialize(void);

#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DTC_CANCheck_DW_fwu4 DTC_CANCheckrtDW;

/* Previous zero-crossings (trigger) states */
extern DTC_CANCheck_ZCE DTC_CANCheckrtPrevZCX;

#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Localizable */
extern volatile UInt16 CAN_LostRecCounter[CANBUS_NUM];

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
 * '<Root>' : 'DTC_CANCheck'
 * '<S1>'   : 'DTC_CANCheck/CANCheck'
 * '<S2>'   : 'DTC_CANCheck/DTCLogic'
 * '<S3>'   : 'DTC_CANCheck/CANCheck/CANCheck_BUSOFF'
 * '<S4>'   : 'DTC_CANCheck/CANCheck/CANCheck_Signals'
 * '<S5>'   : 'DTC_CANCheck/CANCheck/CANNetworkManagement'
 * '<S6>'   : 'DTC_CANCheck/CANCheck/CANCheck_BUSOFF/CANBUSOFFCheck'
 * '<S7>'   : 'DTC_CANCheck/CANCheck/CANCheck_BUSOFF/CANBUSOFFCheck/DTC_Ctrl_Enabled'
 * '<S8>'   : 'DTC_CANCheck/CANCheck/CANCheck_BUSOFF/CANBUSOFFCheck/getDTCEnabled'
 * '<S9>'   : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_ABS'
 * '<S10>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_APA'
 * '<S11>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_BCM2'
 * '<S12>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_EMS'
 * '<S13>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_IPB'
 * '<S14>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_MPC'
 * '<S15>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_SCU'
 * '<S16>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function'
 * '<S17>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function1'
 * '<S18>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function2'
 * '<S19>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function3'
 * '<S20>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_ABS/CANBUSABSCheck'
 * '<S21>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_APA/CANBUSAPACheck'
 * '<S22>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_BCM2/CANBUSBCM2Check'
 * '<S23>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_EMS/CANBUSEMSCheck'
 * '<S24>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_IPB/CANBUSIPBCheck'
 * '<S25>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_MPC/CANBUSMPCCheck'
 * '<S26>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/CANCheck_SCU/CANBUSSCUCheck'
 * '<S27>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function/CANCheck_Lost '
 * '<S28>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function/CANCheck_Lost /SetInerDTCErr'
 * '<S29>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function1/CANCheck_Invalid '
 * '<S30>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function1/CANCheck_Invalid /SetInerDTCErr'
 * '<S31>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc '
 * '<S32>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function2/CANCheck_Crc /SetInerDTCErr'
 * '<S33>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function3/CANCheck_Counter '
 * '<S34>'  : 'DTC_CANCheck/CANCheck/CANCheck_Signals/Simulink Function3/CANCheck_Counter /SetInerDTCErr'
 * '<S35>'  : 'DTC_CANCheck/CANCheck/CANNetworkManagement/CANNetManagement'
 * '<S36>'  : 'DTC_CANCheck/DTCLogic/DTC_Allow_Occur_Logic'
 * '<S37>'  : 'DTC_CANCheck/DTCLogic/DTC_Testfailed_Logic'
 */

/*-
 * Requirements for '<Root>': DTC_CANCheck
 */
#endif                                 /* RTW_HEADER_DTC_CANCheck_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
