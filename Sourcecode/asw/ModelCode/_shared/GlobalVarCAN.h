/*
 * File: GlobalVarCAN.h
 *
 * Code generated for Simulink model 'DTC_CANCheck'.
 *
 * Model version                  : 1.1204
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Oct 21 17:56:45 2022
 */

#ifndef RTW_HEADER_GlobalVarCAN_h_
#define RTW_HEADER_GlobalVarCAN_h_
#include "rtwtypes.h"
#include "SimDiagEnum.h"

/* Volatile memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Global */
extern volatile Bool CAN_BCM2Message_Diag_Pending;
extern volatile Bool CAN_Es_Lost;
extern volatile Bool CAN_Vs_Lost;
extern volatile Bool FLEXCAN_LostImpedance;
extern volatile UInt16 Fv_FaultClass_CAN;
extern volatile FailureDiag Fv_SystemCANChecksumErrorStatus[];
extern volatile FailureDiag Fv_SystemCANCounterErrorStatus[];
extern volatile Bool Fv_SystemCANCounterStatus[];
extern volatile Bool Fv_SystemCANCrcStatus[];
extern volatile FailureDiag Fv_SystemCANDataInvalidStatus[];
extern volatile FailureDiag Fv_SystemCANDiagStatus[];
extern volatile FailureDiag Fv_SystemCANErrrStatus[];
extern volatile UInt8 Fv_SystemCANReciveStatus[];
extern volatile UInt16 Fv_SystemCANReciveTimer[];
extern volatile Bool Fv_SystemCANValidStatus[];
extern volatile Bool SysTaskCANBusoffPending;
extern volatile Bool SysTaskCANLostDiagPending;
extern volatile Bool SysTaskCANPending;
extern volatile Bool SysTaskCANResetPending;
extern volatile unsigned short InitNormalCANFlag;
#endif                                 /* RTW_HEADER_GlobalVarCAN_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
