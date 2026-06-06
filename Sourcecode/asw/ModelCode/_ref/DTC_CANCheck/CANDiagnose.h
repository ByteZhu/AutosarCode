/*
 * File: CANDiagnose.h
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

#ifndef RTW_HEADER_CANDiagnose_h_
#define RTW_HEADER_CANDiagnose_h_
#ifndef DTC_CANCheck_COMMON_INCLUDES_
# define DTC_CANCheck_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DTC_CANCheck_COMMON_INCLUDES_ */

#include "DTC_CANCheck_types.h"

/* Block signals and states (default storage) for system '<S3>/CANBUSOFFCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANBUSOFF == 0

typedef struct {
  UInt16 can_busoff_rcvcnt;            /* '<S3>/CANBUSOFFCheck' */
  UInt16 can_busoff_rcvcnt1; //BYDҪ��busoff�ָ�1s���¼�������--TXY--20221125 
  UInt16 can_busoff_errcnt;            /* '<S3>/CANBUSOFFCheck' */
} DTC_CANCheck_DW_CANBUSOFFCheck;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S9>/CANBUSABSCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANABS == 0

typedef struct {
  struct {
    UInt32 is_c7_DTC_CANCheck:2;       /* '<S9>/CANBUSABSCheck' */
    UInt32 is_LostRun:2;               /* '<S9>/CANBUSABSCheck' */
    UInt32 is_active_c7_DTC_CANCheck:1;/* '<S9>/CANBUSABSCheck' */
    UInt32 can_lostws_flag:1;          /* '<S9>/CANBUSABSCheck' */
  } bitsForTID0;

  UInt16 WSI_Counter_time;             /* '<S9>/CANBUSABSCheck' */
  UInt16 VSI_Counter_time;             /* '<S9>/CANBUSABSCheck' */
} DTC_CANCheck_DW_CANBUSABSCheck;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S10>/CANBUSAPACheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANAPA == 0

typedef struct {
  UInt16 APA_CRC_time;                /* '<S10>/CANBUSAPACheck' */
  UInt16 APA_Counter_time;            /* '<S10>/CANBUSAPACheck' */
  UInt16 APA_Invalid_time;            /* '<S10>/CANBUSAPACheck' */
  UInt16 CAN_APA_Lost;                /* '<S10>/CANBUSAPACheck' */
  struct {
    UInt32 is_c72_DTC_CANCheck:2;      /* '<S10>/CANBUSAPACheck' */
    UInt32 is_LostRun:2;               /* '<S10>/CANBUSAPACheck' */
    UInt32 is_active_c72_DTC_CANCheck:1;/* '<S10>/CANBUSAPACheck' */
  } bitsForTID0;
} DTC_CANCheck_DW_CANBUSAPACheck;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S11>/CANBUSBCM2Check' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANBCM2 == 0

typedef struct {
  UInt16 can_BCM2_flag;                /* '<S11>/CANBUSBCM2Check' */
  struct {
    UInt32 is_c70_DTC_CANCheck:2;      /* '<S11>/CANBUSBCM2Check' */
    UInt32 is_LostRun:2;               /* '<S11>/CANBUSBCM2Check' */
    UInt32 is_active_c70_DTC_CANCheck:1;/* '<S11>/CANBUSBCM2Check' */
  } bitsForTID0;
} DTC_CANCheck_DW_CANBUSBCM2Check;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S12>/CANBUSEMSCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANEMS == 0

typedef struct {
  UInt16 CAN_CCU2_Lost;               /* '<S12>/CANBUSEMSCheck' */
  UInt16 CAN_VCU3_Lost;               /* '<S12>/CANBUSEMSCheck' */
  struct {
    UInt32 is_c71_DTC_CANCheck:2;      /* '<S12>/CANBUSEMSCheck' */
    UInt32 is_LostRun:2;               /* '<S12>/CANBUSEMSCheck' */
    UInt32 is_active_c71_DTC_CANCheck:1;/* '<S12>/CANBUSEMSCheck' */
  } bitsForTID0;
} DTC_CANCheck_DW_CANBUSEMSCheck;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S13>/CANBUSIPBCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANIPB == 0

typedef struct {
  UInt16 CAN_IPB2_Lost;               /* '<S13>/CANBUSIPBCheck' */
  UInt16 IPB2_CRC_time;               /* '<S13>/CANBUSIPBCheck' */
  UInt16 IPB2_Counter_time;           /* '<S13>/CANBUSIPBCheck' */
  UInt16 IPB2_Invalid_time;           /* '<S13>/CANBUSIPBCheck' */
  UInt16 IPB5_Invalid_time;           /* '<S13>/CANBUSIPBCheck' */
  UInt16 IPB6_CRC_time;               /* '<S13>/CANBUSIPBCheck' */
  UInt16 IPB6_Counter_time;           /* '<S13>/CANBUSIPBCheck' */
  UInt16 IPB6_Invalid_time;           /* '<S13>/CANBUSIPBCheck' */
  UInt16 can_IPB5_flag;               /* '<S13>/CANBUSIPBCheck' */
  UInt16 can_IPB6_flag;               /* '<S13>/CANBUSIPBCheck' */
  struct {
    UInt32 is_c69_DTC_CANCheck:2;      /* '<S13>/CANBUSIPBCheck' */
    UInt32 is_LostRun:2;               /* '<S13>/CANBUSIPBCheck' */
    UInt32 is_active_c69_DTC_CANCheck:1;/* '<S13>/CANBUSIPBCheck' */
  } bitsForTID0;
} DTC_CANCheck_DW_CANBUSIPBCheck;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S14>/CANBUSMPCCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANMPC == 0

typedef struct {
  UInt16 ADS2_CRC_time;               /* '<S14>/CANBUSMPCCheck' */
  UInt16 ADS2_Counter_time;           /* '<S14>/CANBUSMPCCheck' */
  UInt16 ADS1_CRC_time;               /* '<S14>/CANBUSMPCCheck' */
  UInt16 ADS1_Counter_time;           /* '<S14>/CANBUSMPCCheck' */
  UInt16 can_ADS2_flag;               /* '<S14>/CANBUSMPCCheck' */
  UInt16 can_ADS1_flag;               /* '<S14>/CANBUSMPCCheck' */
  struct {
    UInt32 is_c2_DTC_CANCheck:2;       /* '<S14>/CANBUSMPCCheck' */
    UInt32 is_LostRun:2;               /* '<S14>/CANBUSMPCCheck' */
    UInt32 is_active_c2_DTC_CANCheck:1;/* '<S14>/CANBUSMPCCheck' */
  } bitsForTID0;
} DTC_CANCheck_DW_CANBUSMPCCheck;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S15>/CANBUSSCUCheck' */
#ifndef DTC_CANCheck_MDLREF_HIDE_CHILD_
#if DIAGDIS_CANSCU == 0

typedef struct {
  UInt16 can_SCU_flag;                /* '<S15>/CANBUSSCUCheck' */
  struct {
    UInt32 is_c1_DTC_CANCheck:2;       /* '<S15>/CANBUSSCUCheck' */
    UInt32 is_LostRun:2;               /* '<S15>/CANBUSSCUCheck' */
    UInt32 is_active_c1_DTC_CANCheck:1;/* '<S15>/CANBUSSCUCheck' */
  } bitsForTID0;
} DTC_CANCheck_DW_CANBUSSCUCheck;

#endif
#endif                                 /*DTC_CANCheck_MDLREF_HIDE_CHILD_*/

#if DIAGDIS_CANBUSOFF == 0

extern void DTC_CANCheck_CANBUSOFFCheck(void);

#endif

#if DIAGDIS_CANABS == 0

extern void DTC_CANChe_CANBUSABSCheck_Reset(void);

#endif

#if DIAGDIS_CANABS == 0

extern void DTC_CANCheck_CANBUSABSCheck(void);

#endif

#if DIAGDIS_CANAPA == 0

extern void DTC_CANChe_CANBUSAPACheck_Reset(void);

#endif

#if DIAGDIS_CANAPA == 0

extern void DTC_CANCheck_CANBUSAPACheck(void);

#endif

#if DIAGDIS_CANBCM2 == 0

extern void DTC_CANChe_CANBUSBCM2Check_Reset(void);

#endif

#if DIAGDIS_CANBCM2 == 0

extern void DTC_CANCheck_CANBUSBCM2Check(void);

#endif

#if DIAGDIS_CANEMS == 0

extern void DTC_CANChe_CANBUSEMSCheck_Reset(void);

#endif

#if DIAGDIS_CANEMS == 0

extern void DTC_CANCheck_CANBUSEMSCheck(void);

#endif

#if DIAGDIS_CANIPB == 0

extern void DTC_CANChe_CANBUSIPBCheck_Reset(void);

#endif

#if DIAGDIS_CANIPB == 0

extern void DTC_CANCheck_CANBUSIPBCheck(void);

#endif

#if DIAGDIS_CANMPC == 0

extern void DTC_CANChe_CANBUSMPCCheck_Reset(void);

#endif

#if DIAGDIS_CANMPC == 0

extern void DTC_CANCheck_CANBUSMPCCheck(void);

#endif

#if DIAGDIS_CANSCU == 0

extern void DTC_CANChe_CANBUSSCUCheck_Reset(void);

#endif

#if DIAGDIS_CANSCU == 0

extern void DTC_CANCheck_CANBUSSCUCheck(void);

#endif

extern void DTC_CANChe_CANNetworkManagement(void);
extern void DTC_CANCheck_CANCheck(void);

#endif                                 /* RTW_HEADER_CANDiagnose_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
