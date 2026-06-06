/*
 * File: FaultDiagRapid_types.h
 *
 * Code generated for Simulink model 'FaultDiagRapid'.
 *
 * Model version                  : 1.1294
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:32:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FaultDiagRapid_types_h_
#define RTW_HEADER_FaultDiagRapid_types_h_
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"

/*
 * Registered constraints for dimension variants
 */
/* Constraint 'EPS_DTC_NUM_MAX == 96' registered by:
 * '<S45>/Data Store Read'
 * '<S46>/Data Store Read'
 * '<S47>/Data Store Read'
 * '<S48>/Data Store Read'
 * '<S60>/Data Store Read'
 * '<S61>/Data Store Read'
 * '<S62>/Data Store Read'
 * '<S63>/Data Store Read'
 * '<S71>/Data Store Read'
 * '<S72>/Data Store Read'
 * '<S81>/Data Store Read'
 * '<S82>/Data Store Read'
 * '<S96>/Data Store Read'
 * '<S97>/Data Store Read'
 * '<S101>/Data Store Read'
 * '<S102>/Data Store Read'
 * '<S106>/Data Store Read'
 * '<S107>/Data Store Read'
 * '<S113>/Data Store Read'
 * '<S114>/Data Store Read'
 * '<S125>/Data Store Read'
 * '<S126>/Data Store Read'
 * '<S127>/Data Store Read'
 * '<S128>/Data Store Read'
 * '<S148>/Data Store Read'
 * '<S149>/Data Store Read'
 * '<S150>/Data Store Read'
 * '<S151>/Data Store Read'
 * '<S169>/Data Store Read'
 * '<S170>/Data Store Read'
 * '<S171>/Data Store Read'
 * '<S172>/Data Store Read'
 * '<S180>/Data Store Read'
 * '<S181>/Data Store Read'
 * '<S197>/Data Store Read'
 * '<S198>/Data Store Read'
 * '<S199>/Data Store Read'
 * '<S200>/Data Store Read'
 * '<S23>/Data Store Read'
 * '<S24>/Data Store Read'
 * '<S25>/Data Store Read'
 * '<S26>/Data Store Read'
 * '<S27>/Data Store Read'
 * '<S28>/Data Store Read'
 */
#if EPS_DTC_NUM_MAX != 104
# error "The preprocessor definition 'EPS_DTC_NUM_MAX' must be equal to '104'"
#endif

/* Model Code Variants */

/* Exactly one variant for '<S18>/DiagInit_ShortOpen_Check' should be active */
#if ((DIAGDIS_MOTORSHORTOPENINIT == 0) ? 1 : 0) + ((DIAGDIS_MOTORSHORTOPENINIT == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S18>/DiagInit_ShortOpen_Check' should be active
#endif

/* Exactly one variant for '<S32>/DiagReg_CurrentMid_Check' should be active */
#if ((DIAGDIS_CURRENTMIDREG == 0) ? 1 : 0) + ((DIAGDIS_CURRENTMIDREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S32>/DiagReg_CurrentMid_Check' should be active
#endif

/* Exactly one variant for '<S33>/DiagReg_CurrentSample_Check' should be active */
#if ((DIAGDIS_CURRENTSAMPLEREG == 0) ? 1 : 0) + ((DIAGDIS_CURRENTSAMPLEREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S33>/DiagReg_CurrentSample_Check' should be active
#endif

/* Exactly one variant for '<S64>/DiagRapid_TorquePower_Check' should be active */
#if ((DIAGDIS_TORQUEPOWERREG == 0) ? 1 : 0) + ((DIAGDIS_TORQUEPOWERREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S64>/DiagRapid_TorquePower_Check' should be active
#endif

/* Exactly one variant for '<S65>/DiagRapid_TorqueSignal_Check' should be active */
#if ((DIAGDIS_TORQUESIGNALREG == 0) ? 1 : 0) + ((DIAGDIS_TORQUESIGNALREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S65>/DiagRapid_TorqueSignal_Check' should be active
#endif

/* Exactly one variant for '<S87>/Diag_MCUCore_Check' should be active */
#if ((DIAGDIS_MCUCORE == 0) ? 1 : 0) + ((DIAGDIS_MCUCORE == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S87>/Diag_MCUCore_Check' should be active
#endif

/* Exactly one variant for '<S88>/Diag_MCUEPSControl_Check' should be active */
#if ((DIAGDIS_MCUEPSCONTROL == 0) ? 1 : 0) + ((DIAGDIS_MCUEPSCONTROL == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S88>/Diag_MCUEPSControl_Check' should be active
#endif

/* Exactly one variant for '<S89>/Diag_MCUMotorControl_Check' should be active */
#if ((DIAGDIS_MCUMOTORCONTROL == 0) ? 1 : 0) + ((DIAGDIS_MCUMOTORCONTROL == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S89>/Diag_MCUMotorControl_Check' should be active
#endif

/* Exactly one variant for '<S90>/Diag_MCUViceComm_Check' should be active */
#if ((DIAGDIS_MCUVICECOMM == 0) ? 1 : 0) + ((DIAGDIS_MCUVICECOMM == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S90>/Diag_MCUViceComm_Check' should be active
#endif

/* Exactly one variant for '<S115>/DiagRapid_MotorOutputCurrent_Check' should be active */
#if ((DIAGDIS_MOTOROUTPUTCURRENTREG == 0) ? 1 : 0) + ((DIAGDIS_MOTOROUTPUTCURRENTREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S115>/DiagRapid_MotorOutputCurrent_Check' should be active
#endif

/* Exactly one variant for '<S116>/DiagRapid_MotorOverCurrent_Check' should be active */
#if ((DIAGDIS_MOTOROVERCURRENTREG == 0) ? 1 : 0) + ((DIAGDIS_MOTOROVERCURRENTREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S116>/DiagRapid_MotorOverCurrent_Check' should be active
#endif

/* Exactly one variant for '<S117>/DiagRapid_MotorPredriver_Check' should be active */
#if ((DIAGDIS_MOTORPREDRIVERREG == 0) ? 1 : 0) + ((DIAGDIS_MOTORPREDRIVERREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S117>/DiagRapid_MotorPredriver_Check' should be active
#endif

/* Exactly one variant for '<S173>/DiagRapid_RotorPower_Check' should be active */
#if ((DIAGDIS_ROTORPOWERREG == 0) ? 1 : 0) + ((DIAGDIS_ROTORPOWERREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S173>/DiagRapid_RotorPower_Check' should be active
#endif

/* Exactly one variant for '<S174>/DiagRapid_RotorSignal_Check' should be active */
#if ((DIAGDIS_ROTORSIGNALREG == 0) ? 1 : 0) + ((DIAGDIS_ROTORSIGNALREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S174>/DiagRapid_RotorSignal_Check' should be active
#endif
#endif                                 /* RTW_HEADER_FaultDiagRapid_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
