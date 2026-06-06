/*
 * File: GlobalVarCAN.c
 *
 * Code generated for Simulink model 'eps_controlAlgorithm'.
 *
 * Model version                  : 1.1176
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 14 11:06:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "eps_controlAlgorithm_types.h"

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Global */
volatile Bool CAN_BCM2Message_Diag_Pending;
volatile Bool CAN_Es_Lost;
volatile Bool CAN_Vs_Lost;
volatile Bool FLEXCAN_LostImpedance;
volatile UInt16 Fv_FaultClass_CAN;
volatile FailureDiag Fv_SystemCANChecksumErrorStatus[CANBUS_NUM];
volatile FailureDiag Fv_SystemCANCounterErrorStatus[CANBUS_NUM];
volatile Bool Fv_SystemCANCounterStatus[CANBUS_NUM];
volatile Bool Fv_SystemCANCrcStatus[CANBUS_NUM];
volatile FailureDiag Fv_SystemCANDataInvalidStatus[CANBUS_NUM];
volatile FailureDiag Fv_SystemCANDiagStatus[CANBUS_NUM];
volatile FailureDiag Fv_SystemCANErrrStatus[CANBUS_NUM];
volatile UInt8 Fv_SystemCANReciveStatus[CANBUS_NUM];
volatile UInt16 Fv_SystemCANReciveTimer[CANBUS_NUM];
volatile Bool Fv_SystemCANValidStatus[CANBUS_NUM];
volatile Bool SysTaskCANBusoffPending;
volatile Bool SysTaskCANLostDiagPending;
volatile Bool SysTaskCANPending;

volatile unsigned short InitNormalCANFlag;
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
