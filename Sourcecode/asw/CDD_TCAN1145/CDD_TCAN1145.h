/*
 * CDD_TCAN1145.h
 *
 *  Created on: 20230728
 *      Author: TXY
 */

#ifndef SOURCECODE_ASW_CDD_TCAN1145_CDD_TCAN1145_H_
#define SOURCECODE_ASW_CDD_TCAN1145_CDD_TCAN1145_H_

#include <Std_Types.h>
#include "CDD_TCAN1145_Cfg.h"
extern void TCAN1145_Init1(void);
extern void TCAN1145_Init2(void);
extern void TCAN1145_EnterSleep(void);
extern void TCAN1145_MainFunction(void);
extern TCAN1145_RxDataType TCAN1145_SendAndReceive1(uint8 addr, uint8 cmd, uint8 data);
extern TCAN1145_RxDataType TCAN1145_SendAndReceive2(uint8 addr, uint8 cmd, uint8 data);
extern boolean TCAN1145_GetCANWakeupInterruptStatusTransceiver1(void);
extern boolean TCAN1145_GetCANWakeupInterruptStatusTransceiver2(void);
#endif /* SOURCECODE_ASW_CDD_TCAN1145_CDD_TCAN1145_H_ */
