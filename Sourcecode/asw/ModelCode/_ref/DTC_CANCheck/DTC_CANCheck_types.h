/*
 * File: DTC_CANCheck_types.h
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

#ifndef RTW_HEADER_DTC_CANCheck_types_h_
#define RTW_HEADER_DTC_CANCheck_types_h_
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacroCAN.h"

/* Model Code Variants */

/* Exactly one variant for '<S1>/CANCheck_BUSOFF' should be active */
#if ((DIAGDIS_CANBUSOFF == 0) ? 1 : 0) + ((DIAGDIS_CANBUSOFF == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S1>/CANCheck_BUSOFF' should be active
#endif

/* Exactly one variant for '<S4>/CANCheck_ABS' should be active */
#if ((DIAGDIS_CANABS == 0) ? 1 : 0) + ((DIAGDIS_CANABS == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CANCheck_ABS' should be active
#endif

/* Exactly one variant for '<S4>/CANCheck_APA' should be active */
#if ((DIAGDIS_CANAPA == 0) ? 1 : 0) + ((DIAGDIS_CANAPA == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CANCheck_APA' should be active
#endif

/* Exactly one variant for '<S4>/CANCheck_BCM2' should be active */
#if ((DIAGDIS_CANBCM2 == 0) ? 1 : 0) + ((DIAGDIS_CANBCM2 == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CANCheck_BCM2' should be active
#endif

/* Exactly one variant for '<S4>/CANCheck_EMS' should be active */
#if ((DIAGDIS_CANEMS == 0) ? 1 : 0) + ((DIAGDIS_CANEMS == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CANCheck_EMS' should be active
#endif

/* Exactly one variant for '<S4>/CANCheck_IPB' should be active */
#if ((DIAGDIS_CANIPB == 0) ? 1 : 0) + ((DIAGDIS_CANIPB == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CANCheck_IPB' should be active
#endif

/* Exactly one variant for '<S4>/CANCheck_MPC' should be active */
#if ((DIAGDIS_CANMPC == 0) ? 1 : 0) + ((DIAGDIS_CANMPC == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CANCheck_MPC' should be active
#endif

/* Exactly one variant for '<S4>/CANCheck_SCU' should be active */
#if ((DIAGDIS_CANSCU == 0) ? 1 : 0) + ((DIAGDIS_CANSCU == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S4>/CANCheck_SCU' should be active
#endif
#endif                                 /* RTW_HEADER_DTC_CANCheck_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
