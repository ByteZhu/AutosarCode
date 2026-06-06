/*
 * File: PowerSupplyProcess_types.h
 *
 * Code generated for Simulink model 'PowerSupplyProcess'.
 *
 * Model version                  : 1.1126
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Nov 14 17:34:13 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PowerSupplyProcess_types_h_
#define RTW_HEADER_PowerSupplyProcess_types_h_
#include "SimDiagEnum.h"

/* Includes for objects with custom storage classes. */
#include "SimDiagMacro.h"

/*
 * Registered constraints for dimension variants
 */
/* Constraint 'EPS_DTC_NUM_MAX == 96' registered by:
 * '<S7>/Data Store Read'
 * '<S8>/Data Store Read'
 * '<S11>/Data Store Read'
 * '<S12>/Data Store Read'
 * '<S27>/Data Store Read'
 * '<S39>/Data Store Read'
 * '<S40>/Data Store Read'
 */
#if EPS_DTC_NUM_MAX != 104
# error "The preprocessor definition 'EPS_DTC_NUM_MAX' must be equal to '104'"
#endif

/* Model Code Variants */

/* Exactly one variant for '<S1>/PowerOthersCheck_HoldPowerLatch' should be active */
#if ((DIAGDIS_POWERHOLD == 0) ? 1 : 0) + ((DIAGDIS_POWERHOLD == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S1>/PowerOthersCheck_HoldPowerLatch' should be active
#endif

/* Exactly one variant for '<S1>/PowerOthersCheck_IGkeyCAN' should be active */
#if ((DIAGDIS_POWERIGCAN == 0) ? 1 : 0) + ((DIAGDIS_POWERIGCAN == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S1>/PowerOthersCheck_IGkeyCAN' should be active
#endif

/* Exactly one variant for '<S13>/JudgeVbat' should be active */
#if ((DIAGDIS_POWERVBAT == 0) ? 1 : 0) + ((DIAGDIS_POWERVBAT == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S13>/JudgeVbat' should be active
#endif

/* Exactly one variant for '<S2>/PowerSupplyCheck_PowerLevel' should be active */
#if ((DIAGDIS_POWERLEVEL == 0) ? 1 : 0) + ((DIAGDIS_POWERLEVEL == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S2>/PowerSupplyCheck_PowerLevel' should be active
#endif

/* Exactly one variant for '<S15>/PowerSupplyCheck_ResolverPower' should be active */
#if ((DIAGDIS_ROTORPOWERREG == 0) ? 1 : 0) + ((DIAGDIS_ROTORPOWERREG == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S15>/PowerSupplyCheck_ResolverPower' should be active
#endif

/* Exactly one variant for '<S15>/PowerSupplyCheck_SysPower' should be active */
#if ((DIAGDIS_POWERLEVEL == 0) ? 1 : 0) + ((DIAGDIS_POWERLEVEL == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S15>/PowerSupplyCheck_SysPower' should be active
#endif

/* Exactly one variant for '<S15>/PowerSupplyCheck_Vbat' should be active */
#if ((DIAGDIS_POWERVBAT == 0) ? 1 : 0) + ((DIAGDIS_POWERVBAT == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S15>/PowerSupplyCheck_Vbat' should be active
#endif
#endif                              /* RTW_HEADER_PowerSupplyProcess_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
