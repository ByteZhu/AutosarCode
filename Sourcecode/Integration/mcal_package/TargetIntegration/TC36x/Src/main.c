/*
 * Contains code for the "Hello World" example application
 *
 * Copyright ETAS GmbH 2016
 */

 /*includes*/
#include <Os.h>
#include "Std_Types.h"
#include "Rte_UserCfg.h"
#include "Port.h"
#include "IfxPort_reg.h"
#include "IfxStm_reg.h"
#include "IfxSrc_reg.h"
#include "EcuM.h"
#include "BswM.h"
#include "SchM_BswM.h"
#include "main.h"
#include "Wdg_17_Scu_Cbk.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "Ifx_Ssw_Infra.h"
#include "CDD_USER.h"
#include "IFX_Os.h"
#include "Traps.h"
#include "Dio.h"
#include "CDD_TPS653852A.h"
#include "CDD_TCAN1145.h"
#include "DRV3245.h"
#include "Gtm.h"
#include "IoHwAb.h"
#include "Motor.h"
#include "eps_controlAlgorithm.h"
#include "TestMode.h"
#include "SuportFunc.h"
#include "TorqueOffsetComp.h"
#include "Motor_Private.h"
#include "SuportFunc_ShimmyComp.h"
#include "SuportFunc_TSCControl.h"
#include "Ext_DataConv.h"
#include "CanIf_Prv.h"
#include "Com_Prv.h"
#include "portability.h"

#if defined(ENABLE_CCP_CALIBRATE_FUNC)
extern void XcpHandler(void);
#define EVENT_10MS            0
#define EVENT_100MS           1
#endif

/*Macro definitions*/
#define STM_CMP0 STM0_CMP0
#define STM_TIM0 STM0_TIM0
#define STM_SRC0 SRC_STM0SR0
#define CLEAR_PENDING_INTERRUPT() { STM_CMP0.U = STM_CMP0.U + TIMER_MILLISECOND; /* Increment from timer so that breakpoints won't cause an issue in samples */  STM_SRC0.B.CLRR = 1; }
#define TIMER_MILLISECOND (OSSWTICKSPERSECOND/1000UL)

/********************/
/* The main program */
/********************/
#define APP_START_SEC_SHARECODE
#include "MemMap.h"

/*MISRA Dir-1.1, Rule 1.2, 10.4, 2.2, 8.5, 10.1 VIOLATION: This is a OS macro, This is a OS function*/
OS_MAIN()
{

#if 0
    int coreID;
	unsigned short wdtPassword;
    coreID = GetCoreID();

	/*enable Pcache and Dcache for CPU0->CPU5*/
	wdtPassword   = Ifx_Ssw_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[coreID]);
	Ifx_Ssw_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[coreID], wdtPassword);
	{
		Ifx_CPU_PCON0 pcon0;
		pcon0.U       = 0;
		pcon0.B.PCBYP = 0; /*enable cache */
		Ifx_Ssw_MTCR(CPU_PCON0, pcon0.U);
		Ifx_Ssw_ISYNC();
	}
	{
		Ifx_CPU_DCON0 dcon0;
		dcon0.U       = 0;
		dcon0.B.DCBYP = 0; /*enable cache */
		Ifx_Ssw_MTCR(CPU_DCON0, dcon0.U);
		Ifx_Ssw_ISYNC();
	}
	Ifx_Ssw_setCpuEndinitInline(&MODULE_SCU.WDTCPU[coreID], wdtPassword);
#endif
	EcuM_Init();
	return;
}
#define APP_STOP_SEC_SHARECODE
#include "MemMap.h"


void MCan_Transmit_Inner(uint8 *data)//02
{
#define DEBUG_MAILBOX   0
	Ifx_CAN_TXMSG *txBufferElement;
	uint8 i = 0;
	txBufferElement = (Ifx_CAN_TXMSG *)(0xF0200000u + 0x1400 + 72 * DEBUG_MAILBOX);
	txBufferElement->T0.U = (0x2) << 18;
	txBufferElement->T1.U = 0x003F0000;
	for(i = 0; i < 64; i ++)
	{
		txBufferElement->DB[i].U = data[i];
	}
	CAN0_TXBAR2.U = ((1<< DEBUG_MAILBOX) | CAN0_TXBAR2.U);
#undef DEBUG_MAILBOX
}
/*Periodic interrupt definition*/
#define STARTUP_START_SEC_CODE
#include "MemMap.h"
void TargetEn_PeriodicInterrupt(void)
{
	/* Initialize and enable STM CMP0 as the periodic interrupt source. */

	/* Configure 32 bit compares on the lowest 32 bits of the STM */
	STM0_CMCON.B.MSIZE0 = 31U;
	STM0_CMCON.B.MSTART0 = 0U;

	/* Set compare register to period value */
//	STM0_CMP0.U = STM0_TIM0.U + 1000*TIMER_MILLISECOND;

	/* Reset the interrupt pending flag */
	STM0_ISCR.B.CMP0IRR = 1;

	/* Enable compare interrupt */
	STM0_ICR.B.CMP0EN = 1;

	/* Enable suspend for system timer */
	STM0_OCS.U = 0x12000000;


}

// #ifdef __GNUC__
#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"
/******************************************************************/

#define APP_START_SEC_CPU0_DATA
#include "MemMap.h"
/* Default Interrupt handler for unknown IR source */
char MyCounterIsRunning = FALSE;
uint32 Curr_TickCounter = 0;
uint32 OS_Counter_1ms = 0;
TickType Match_old = 0;
TickType Match_new = 0;
#define APP_STOP_SEC_CPU0_DATA
#include "MemMap.h"

#define CAT1_ISR_START_SEC_CODE
#include "MemMap.h"
CAT1_ISR(DefaultInterruptHandler)
{
	for (;;)
	{
	/* Loop forever */
	}
}

boolean test_dio = TRUE;

CAT1_ISR(USER_ISR)//100us
{
#if 0
	//User_40usIsr_fun();
#endif
	IoHwAb_RapidDataProcess();

	IoHwAb_TMRCorrection();

	MTR_Daxis_PID();

	Motor_MainFunction();

	EpsTrqFilter();

	EstSteerLoad_100us();

}
void MCan_Transmit02(uint8 *data)
{
#define DEBUG_MAILBOX   0
	Ifx_CAN_TXMSG *txBufferElement;
	uint8 i = 0;
	txBufferElement = (Ifx_CAN_TXMSG *)(0xF0210000u + 0x1400 + 72 * DEBUG_MAILBOX);
	txBufferElement->T0.U = (0x564) << 18;
	txBufferElement->T1.U = 0x00080000;
	for(i = 0; i < 8; i ++)
	{
		txBufferElement->DB[i].U = data[i];
	}
	CAN1_TXBAR3.U = ((1<< DEBUG_MAILBOX) | CAN1_TXBAR3.U);
#undef DEBUG_MAILBOX

	if(CAN1_CCCR3.B.INIT > 0)
	{
		CAN1_CCCR3.B.INIT = 0;
	}
}
void MCan_Transmitdebug(uint8 *data)
{
#define DEBUG_MAILBOX   16
	Ifx_CAN_TXMSG *txBufferElement;
	uint8 i = 0;
	//0xf02001b0UL

	txBufferElement = (Ifx_CAN_TXMSG *)(0xF0200000u + 0x7a8 + 72 * DEBUG_MAILBOX);

	txBufferElement->T0.U = (0x7fe) << 18;
	txBufferElement->T1.U = 0x00280000;


	for(i = 0; i < 8; i ++)
	{
		txBufferElement->DB[i].U = data[i];
	}

	CAN0_TXBAR1.U = ((1<< DEBUG_MAILBOX) | CAN0_TXBAR1.U);
#undef DEBUG_MAILBOX
}
void PutMsg_EPSDEBUGINFO(sint16 can_signal1,sint16 can_signal2,sint16 can_signal3,sint16 can_signal4)
{
	uint8 Debug_data[8] = {0,};
	Debug_data[0] = (uint8)((can_signal1&0xFF00)>>8);
	Debug_data[1] = (uint8)(can_signal1&0x00FF);
	Debug_data[2] = (uint8)((can_signal2&0xFF00)>>8);
	Debug_data[3] = (uint8)(can_signal2&0x00FF);
	Debug_data[4] = (uint8)((can_signal3&0xFF00)>>8);
	Debug_data[5] = (uint8)(can_signal3&0x00FF);
	Debug_data[6] = (uint8)((can_signal4&0xFF00)>>8);
	Debug_data[7] = (uint8)(can_signal4&0x00FF);
	MCan_Transmitdebug(Debug_data);
}
void MCan_Transmit03(uint8 *data)
{
#define XCP_MAILBOX   3
	Ifx_CAN_TXMSG *txBufferElement;
	uint8 i = 0;
	//0xf02001b0UL

	txBufferElement = (Ifx_CAN_TXMSG *)(0xF0200000u + 0x7a8 + 72 * XCP_MAILBOX);

	txBufferElement->T0.U = (0x596) << 18;
	txBufferElement->T1.U = 0x00280000;


	for(i = 0; i < 8; i ++)
	{
		txBufferElement->DB[i].U = data[i];
	}

	CAN0_TXBAR1.U = ((1<< XCP_MAILBOX) | CAN0_TXBAR1.U);
#undef XCP_MAILBOX
}
void MCan_TransmitTEST(uint8 *data)
{
#define TEST_MAILBOX   5
	Ifx_CAN_TXMSG *txBufferElement;
	uint8 i = 0;
	//0xf02001b0UL

	txBufferElement = (Ifx_CAN_TXMSG *)(0xF0200000u + 0x7a8 + 72 * TEST_MAILBOX);

	txBufferElement->T0.U = (0x2) << 18;
	txBufferElement->T1.U = 0x00280000;


	for(i = 0; i < 8; i ++)
	{
		txBufferElement->DB[i].U = data[i];
	}

	CAN0_TXBAR1.U = ((1<< TEST_MAILBOX) | CAN0_TXBAR1.U);
#undef XCP_MAILBOX
}
ISR(Millisecond)
{

	Os_AdvanceCounter_Rte_TickCounter();
	STM_SRC0.B.CLRR = 1;
	OS_Counter_1ms++;
#if defined(ENABLE_CCP_CALIBRATE_FUNC)
	XcpHandler();
#endif

}

FUNC(TickType, OS_CALLOUT_CODE) Os_Cbk_Now_Rte_TickCounter(void)
{
	return (*(Os_const_counters[1].dynamic)).type_dependent.hw.match;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Set_Rte_TickCounter(TickType Match)
{
	TickType Detal_Match;
	Match_old = Match_new;
	Match_new = Match;

	if(Match_new < Match_old)
	{
		Detal_Match = 0xffff - (Match_old -Match_new) + 	1;
	}
	else
	{
		Detal_Match=(Match_new-Match_old);
	}
	if (MyCounterIsRunning == TRUE)
	{
		STM_CMP0.U += (Ifx_UReg_32Bit)(Detal_Match*TIMER_MILLISECOND);
	}
	else
	{
		STM_CMP0.U = STM0_TIM0.U + (Ifx_UReg_32Bit)(Detal_Match*TIMER_MILLISECOND);
	}
	
	MyCounterIsRunning = TRUE;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_State_Rte_TickCounter(Os_CounterStatusRefType State)
{
	State->Delay = (STM_CMP0.U - STM0_TIM0.U)/TIMER_MILLISECOND;
	State->Running = MyCounterIsRunning;
	if ((*(Os_const_counters[0].dynamic)).type_dependent.hw.running) 
	{
		State->Pending = TRUE;
	} 
	else {
		State->Pending = FALSE;
	}
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Cancel_Rte_TickCounter(void)
{
	MyCounterIsRunning = FALSE;

}

void Fee_JobEndNotification(void)
{
	;
}

void Fee_JobErrorNotification(void)
{
	;
}

void Fee_17_JobEraseErrorNotification(void)
{
	;
}

void Fee_17_JobProgErrorNotification(void)
{
	;
}


#define CAT1_ISR_STOP_SEC_CODE
#include "MemMap.h"
#include "Rte_ASW_COM.h"
uint8 openloopStart;
uint8 SentFlag = 0;
uint8 initflag = 0;
//uint8 innerTrans[64];
extern void ASW_COM_TestModeResponseSend(uint8 *data);
extern uint8 data_dd512[512];
void Main_1msTask(void)
{
	sint16 rtb_rev_abs = 0;
	uint8 databuf[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	static uint8 toggle = 0;
	

	if (Tv_dStrAng < 0) {
		rtb_rev_abs = (Int16)(-Tv_dStrAng);
	} else {
		rtb_rev_abs = Tv_dStrAng;
	}
	/*MDLINT16S local_IU = 0;
	MDLINT16S local_IV = 0;
	MDLINT16S local_IW = 0;
	local_IU = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentU[PreDriver_02] - fsCalibrationData.data.gainoffset.i[0])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;//3
	local_IV = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentV[PreDriver_02] - fsCalibrationData.data.gainoffset.i[1])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;
	local_IW = (MDLINT16S)((((MDLINT32S) (AD_MotorCurrentW[PreDriver_02] - fsCalibrationData.data.gainoffset.i[2])) * ((MDLINT32S)MACRO_CURRENT_AMP)) >> 5) ;*/
  //MCan_Transmit02(databuf);
 //PutMsg_EPSDEBUGINFO(Tv_SE_LeftMaxAng,Fv_AngleEndValidFlag,Fv_EndCurrentShrinkZoneAbs,Tv_StrAng_Raw); 
//  PutMsg_EPSDEBUGINFO(Fv_TorqueTarget,Fv_StrTrq0,Tv_SteerEndCompTrq,Fv_ActiveReturnCompTrq); //AD_PowerRelaySys U bridge
  	//PutMsg_EPSDEBUGINFO(AD_PowerRelaySys,AD_IgnitionSys,AD_TempSys,AD_TempSys2); //AD_PowerRelaySys U bridge
	//PutMsg_EPSDEBUGINFO(Fv_LKA_ADL3ADMod|Fv_NOPMod<<1,debug_jing1,Fv_APA_ControlSts ,debug_jing3);

//	PutMsg_EPSDEBUGINFO(Tian_Debug[0],Fv_FaultClass_Torque,Tian_Debug[1],Fv_HighFailFlag);

//	PutMsg_EPSDEBUGINFO(Fv_VehSpdNew,WhichMode,Fv_PMSMCurrent_ORGQAIM,Fv_HighFailFlag);
//	PutMsg_EPSDEBUGINFO(Fv_AdsTrqReq,Tv_StrSASAng,Tv_StrSASAngValid,Fv_HighFailFlag);
#if 0
	Rte_Write_ASW_COM_PPort_DebugInfo_0_DebugInfo_0(Fv_FaultClass_Torque & (Fv_FaultClass_Angle << 8));
	Rte_Write_ASW_COM_PPort_DebugInfo_1_DebugInfo_1((Fv_WhichMode << 8) | (Fv_LowFailFlag << 4) | (Fv_HighFailFlag));
	Rte_Write_ASW_COM_PPort_DebugInfo_2_DebugInfo_2(Fv_FaultClass_Current | (Fv_FaultClass_Motor << 8));
	Rte_Write_ASW_COM_PPort_DebugInfo_3_DebugInfo_3(Fv_FaultClass_MCU);
#else
#if 0
#if 0
	Rte_Write_ASW_COM_PPort_DebugInfo_0_DebugInfo_0(WhichMode);//(AD_RotorSinCorrect[PreDriver_01]);//(AD_MotorCurrentU[PreDriver_01]);//(AD_MotorCurrentU[PreDriver_01]);//(AD_RotorMainCos1);
	Rte_Write_ASW_COM_PPort_DebugInfo_1_DebugInfo_1(Tv_StrTrq0Orig);//(AD_RotorCosCorrect[PreDriver_01]);//(AD_MotorCurrentU[PreDriver_02]);//(AD_MotorCurrentV[PreDriver_01]);//(AD_MotorCurrentV[PreDriver_01]);//(AD_RotorMainSin1);
	Rte_Write_ASW_COM_PPort_DebugInfo_2_DebugInfo_2(Fv_PMSMCurrent_ORGQAIM);//(AD_RotorSinCorrect[PreDriver_02]);//(MotorCtrl_FocPar[PreDriver_01].angle);//(AD_MotorCurrentW[PreDriver_01]);//(AD_RotorSubCos1);
	Rte_Write_ASW_COM_PPort_DebugInfo_3_DebugInfo_3(Fv_MotorCurrent_Qact);//(AD_RotorCosCorrect[PreDriver_02]);//(MotorCtrl_FocPar[PreDriver_02].angle);//(AD_MotorCurrentV[PreDriver_02]);//(MotorCtrl_FocPar[PreDriver_02].angle);//(AD_RotorSubSin1);
#endif
#else
	// Rte_Write_ASW_COM_PPort_DebugInfo_0_DebugInfo_0(Fv_RUNAssistSelectMode);//(Fv_VehSpdNew);
	// Rte_Write_ASW_COM_PPort_DebugInfo_1_DebugInfo_1(WhichMode);//(Tv_TCL_OpenLoopCompTrq);//(WhichMode);
	// Rte_Write_ASW_COM_PPort_DebugInfo_2_DebugInfo_2(Fv_PMSMCurrent_ORGQAIM);//(Tv_TCL_CloseLoopCompTrq);//
	// Rte_Write_ASW_COM_PPort_DebugInfo_3_DebugInfo_3(CAN_EngSpd);//(Fv_StrTrq0);//(CAN_EngSpd);
#endif
#endif
#if 0
	toggle ^= 1;
	if(toggle)//0x7FF
	{
		PutMsg_EPSDEBUGINFO(local_IU,local_IV,local_IW,Fv_MotorRev_rpm);
	}
	else//0x2
	{
		databuf[0] = (uint8)(Fv_MotorCurrent_Qaim2 >> 8);
		databuf[1] = (uint8)(Fv_MotorCurrent_Qaim2 );
		databuf[2] = (uint8)(Fv_MotorCurrent_Qact2  >> 8);
		databuf[3] = (uint8)(Fv_MotorCurrent_Qact2 );
		databuf[4] = (uint8)(Fv_MotorCurrent_Daim2 >> 8);
		databuf[5] = (uint8)(Fv_MotorCurrent_Daim2);
		databuf[6] = (uint8)(Fv_MotorCurrent_Dact2 >> 8);
		databuf[7] = (uint8)(Fv_MotorCurrent_Dact2);
		ASW_COM_TestModeResponseSend(databuf);	
	}
#endif
	if(openloopStart)
	{
		Fv_TESTmodeFun_GlbFlag = TRUE;
		Fv_TESTmode_CrlReqFlag = TESTMODE_OpenLoopFlag;
		//Cal Middle point
		fsOpenloopUQ= 0;//896;
		fsOpenloopUD=0;
		fsOpenloopS1=6;//20
		fsOpenloopS2=2;//1,spd=s1/s2
		fsOpenloopSa=0;//2048->3pi/6,6144->9pi/6

		SysTaskFocResetPending = FALSE;
		//SysTaskFocResetTrgPending = FALSE;
		SysTaskResolverSmpPending = TRUE;
		OpenPhase();
		OpenPredrive();	
	}
	
	IoHwAb_SlowDataProcess();

	EPSADC();

	Ext_DataConv_1ms_Task();

	Variant_LimitPIDparam();
	EstSteerLoad_1ms();
    if(!Fv_TESTmodeFun_GlbFlag)
    {
		if(initflag==0){
			EXT_ExtFunction_Init();
			initflag = 1;
		}
		BehavourModule();

		AssistControl();

		FaultDiagRapid();

		SuportFunc_ShimmyComp();

		SuportFunc_TSCControl();
		
		EXT_ExtFunction_1ms();


		CalcLowRtrSpd();
		
    }
    else
    {

    }

    UpdateReceiveMessageCounter();
}
