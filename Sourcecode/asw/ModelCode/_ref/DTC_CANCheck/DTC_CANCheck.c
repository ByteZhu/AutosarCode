/*
 * File: DTC_CANCheck.c
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

#include "DTC_CANCheck.h"
#include "DTC_CANCheck_private.h"

/* Block states (default storage) */
DTC_CANCheck_DW_fwu4 DTC_CANCheckrtDW;

/* Previous zero-crossings (trigger) states */
DTC_CANCheck_ZCE DTC_CANCheckrtPrevZCX;

/* System initialize for referenced model: 'DTC_CANCheck' */
void DTC_CANCheck_Init(void)
{
  /* Machine initializer */
  DTC_CANCheckrtDW.VSI_Invalid_time = (0);
  DTC_CANCheckrtDW.VSI_CRC_time = (0);
  DTC_CANCheckrtDW.WSI_Invalid_time = (0);
  DTC_CANCheckrtDW.WSI_CRC_time = (0);

  /* SystemInitialize for Atomic SubSystem: '<Root>/DTCLogic' */
  DTC_CANCheck_DTCLogic_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/DTCLogic' */
}

/* Output and update for referenced model: 'DTC_CANCheck' */
void DTC_CANCheck(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/DTCLogic' */
  DTC_CANCheck_DTCLogic();

  /* End of Outputs for SubSystem: '<Root>/DTCLogic' */

  /* Outputs for Atomic SubSystem: '<Root>/CANCheck' */
  DTC_CANCheck_CANCheck();

  /* End of Outputs for SubSystem: '<Root>/CANCheck' */
}

/* Model initialize function */
void DTC_CANCheck_initialize(void)
{
  DTC_CANCheckrtPrevZCX.CANCheck_Signals_Reset_ZCE = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
