/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2017. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Component 	: Task_Background.c
 * Created on	: Jan 7, 2020
 * Version   	: 1.0
 * Description  : This module implement Tasks bodies that are not implemented in RTE context.
 * Author		: HAD1HC
 **********************************************************************************************************************
    This file contains sample code only. It is not part of the production code deliverables.

*/

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Os.h"
/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/

#define SHARED_START_SEC_CODE
#include "MemMap.h"
/**
 *********************************************************************
 * TASK(OsTask_Background_1ms): Task to call Mainfunction that run in the background.
 *
 * This task to call MemIf_Rb_MainFunction.
 *
 *********************************************************************
 */
extern void TemperatureCheck(void);
extern void AngleOffsetComp(void);
extern volatile unsigned char Fv_TESTmodeFun_GlbFlag;
TASK(Core0_OsTask_BSW_100ms)
{
	if(!Fv_TESTmodeFun_GlbFlag)
	{
		TemperatureCheck();
		AngleOffsetComp();
	}
	TerminateTask();
}
TASK(Core0_OsTask_BSW_5ms)
{
	__nop();
	__nop();
	TerminateTask();
}
TASK(Core0_OsTask_ASW_2ms)
{
	__nop();
	__nop();
	TerminateTask();
}
extern void CDD_TPS653852A_MainFunction(void);
extern void TCAN1145_MainFunction(void);
extern void DRV3245_MainFunction(void);
extern void SetVsPhaseFlag(void);
//extern void Ext_DataConv_Ws(void);
extern void CDD_WakeupSrc_Monitor(void);
TASK(Core0_OsTask_ASW_5ms)
{
	Ext_DataConv_Ws();

	CDD_TPS653852A_MainFunction();

	TCAN1145_MainFunction();

	DRV3245_MainFunction();

	SetVsPhaseFlag();

	CDD_WakeupSrc_Monitor();

	TerminateTask();
}
TASK(Core1_OsTask_BSW_1ms)
{
	__nop();
	__nop();
	TerminateTask();
}
TASK(Core1_OsTask_BSW_5ms)
{
	__nop();
	__nop();
	TerminateTask();
}
TASK(Core1_OsTask_ASW_10ms)
{
	__nop();
	__nop();
	TerminateTask();
}
TASK(Core1_OsTask_ASW_5ms)
{
	__nop();
	__nop();
	TerminateTask();
}
#define SHARED_STOP_SEC_CODE
#include "MemMap.h"
/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */
