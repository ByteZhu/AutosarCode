/*
 * IoHwAb.c
 *
 *  Created on: 2024��5��24��
 *      Author: Administrator
 */
#include "IoHwAb.h"
#include "common.h"
#include "Ifx_reg.h"
#include "eps_controlAlgorithm.h"
#include "ASW_NVM.h"
#include "Rte_ASW_NVM.h"
#include "can.h"
#include "Motor.h"
#include "FrictionComp_Study_1.h"

extern uint16 Sent_T1SentToPwm;
extern uint16 Sent_T2SentToPwm;
extern uint16 Sent_ASSentToPwm;
extern uint16 Sent_APSentToPwm;
extern uint16 Sent_T1Count;
extern uint16 Sent_T2Count;
extern uint16 Sent_ASCount;



static void MCan13_Init(void)
{
    uint8 i = 0;
    Ifx_CAN_MCR mcr = {{0,}};
    Ifx_CAN_N_CCCR cccr = {{0,}};
    Ifx_CAN_STDMSG *standardFilterElement;

    mcr.B.CCCE = 1;
    mcr.B.CI = 1;
    CAN1_MCR.U = mcr.U;
    mcr.B.CLKSEL1 = 3;
    mcr.B.CLKSEL2 = 3;
    mcr.B.CLKSEL3 = 3;
    CAN1_MCR.U = mcr.U;
    mcr.B.CCCE = 0;
    mcr.B.CI = 0;
    CAN1_MCR.U = mcr.U;

    if(CAN1_CCCR3.B.INIT == 1)
    {
        CAN1_CCCR3.B.CCE = 0;
        while(CAN1_CCCR3.B.CCE != 0)
        {}
        CAN1_CCCR3.B.INIT = 0;
        while(CAN1_CCCR3.B.INIT != 0)
        {}
    }
    CAN1_CCCR3.B.INIT = 1;
    while(CAN1_CCCR3.B.INIT != 1)
    {}
    cccr.U = CAN1_CCCR3.U;

    cccr.B.INIT = 1;
    cccr.B.CCE = 1;
    CAN1_CCCR3.U = cccr.U;

    CAN1_DBTP3.U = 0x00010200;

    CAN1_NBTP3.U = 0x06001E07;

    CAN1_TXESC3.U = 0x0007;
    CAN1_TDCR3.U = 0x00000A0B;

    CAN1_TXBC3.B.TBSA = 0x1400 >> 2;
    CAN1_TXBC3.B.NDTB = 1;/* tx num */

    CAN1_RXESC3.U = 0x0700;

    CAN1_RXBC3.B.RBSA = 0x1200 >> 2;

    CAN1_SIDFC3.B.FLSSA = 0x1100 >> 2;
    CAN1_SIDFC3.B.LSS = 1;/* rx num */

//    CAN0_GRINT22.B.REINT = 2;

    //SRC_CAN0INT2.B.SRPN = INTERRUPT_CAN02_PRIORITY;
    //SRC_CAN0INT2.B.CLRR = 1;
    //SRC_CAN0INT2.B.SRE = 1;

    CAN1_GFC3.U = 0x0000;

//    CAN0_IE2.B.DRXE = 1;

    for(i = 0; i < 1; i ++)
    {
        standardFilterElement = (Ifx_CAN_STDMSG *)(0xF0210000 + 0x1100 + i * 4);
        standardFilterElement->S0.U = i + (1 << 16) + (7 << 27);
    }

    CAN1_CCCR3.B.FDOE = 1;
    CAN1_CCCR3.B.BRSE = 1;
    CAN1_CCCR3.B.CCE = 0;

    while(CAN1_CCCR3.B.CCE != 0)
    {}

    CAN1_CCCR3.B.INIT = 0;

    while(CAN1_CCCR3.B.INIT != 0)
    {}

    CAN1_NPCR3.B.RXSEL = 1;
    //can0_node2_init_pins();
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void IoHwAb_Init(void)
{
	uint8 i = 0;
	uint8 ee_tmp = 0;
	uint8 ee_crc = 0;
    Init_CalcFirCoef();
	IoHwAb_UBrigdeSampleEnable();

    // eps_controlAlgorithm_initialize();

    // FrictionComp_Study_1_initialize();

    Fv_SensorPowerTorque = 640;

    Fv_SensorPowerResolver = 1536;

    //Can_SetControllerMode(CanConf_CanController_Can_Network_CANNODE_2,CAN_T_STOP);
    //Can_EnableControllerInterrupts(CanConf_CanController_Can_Network_CANNODE_2);

//    Init_CalcFirCoef();

    Fv_TOCShortFuncFbd = false;
	Fv_TOCLongFuncFbd = false;
	Fv_TOCSTCFbd = false;
//	Fv_TSC_Configuration = true;
	Fv_AOC_Configuration = true;
    Fv_APC_Configuration = true;

//	MCan13_Init();
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void IoHwAb_RapidDataProcess(void)
{
	static uint16 initcnt = 0;

	if(initcnt > 1000)
	{
		 EnableResolverPowerSupply();
		 SysTaskTrqSplPending = TRUE;
	}
	else
	{
		initcnt ++;
	}
	AD_MotorCurrentU[PreDriver_01] = EVADC_G8RES5.B.RESULT;
    AD_MotorCurrentV[PreDriver_01] = EVADC_G1RES5.B.RESULT;
    AD_MotorCurrentW[PreDriver_01] = EVADC_G0RES1.B.RESULT;

    AD_MotorCurrentW[PreDriver_02] = EVADC_G3RES0.B.RESULT;
    AD_MotorCurrentV[PreDriver_02] = EVADC_G1RES3.B.RESULT;
    AD_MotorCurrentU[PreDriver_02] = EVADC_G8RES4.B.RESULT;

    AD_RotorMainSin1 = EVADC_G0RES2.B.RESULT;
    AD_RotorMainCos1 = EVADC_G1RES1.B.RESULT;
    if(EVADC_G0RES0.B.RESULT > 4095)
    {
    	AD_RotorSubSin1 = 0;
    }
    else
    {
    	AD_RotorSubSin1 = 4096 - EVADC_G0RES0.B.RESULT;
    }
    if(EVADC_G1RES4.B.RESULT > 4095)
    {
    	AD_RotorSubCos1 = 0;
    }
    else
    {
    	AD_RotorSubCos1 = 4096 - EVADC_G1RES4.B.RESULT;
    }

	AD_RotorMainSin2 = EVADC_G2RES0.B.RESULT;
	AD_RotorMainCos2 = EVADC_G1RES7.B.RESULT;
	if(EVADC_G2RES1.B.RESULT > 4095)
	{
		AD_RotorSubSin2 = 0;
	}
	else
	{
		AD_RotorSubSin2 = 4096 - EVADC_G2RES1.B.RESULT;
	}
	if(EVADC_G1RES6.B.RESULT > 4095)
	{
		AD_RotorSubCos2 = 0;
	}
	else
	{
		AD_RotorSubCos2 = 4096 - EVADC_G1RES6.B.RESULT;
	}


    AD_RotorMainMid1 = 2048;
    AD_RotorMainMid2 = 2048;

    AD_PowerRelaySys = EVADC_G0RES7.B.RESULT;

    AD_PowerSys = AD_PowerRelaySys;
    AD_IgnitionSys = EVADC_G0RES4.B.RESULT;

    AD_PMICAmux = EVADC_G8RES0.B.RESULT;

    AD_I2D5Ref1 = 2048;
    AD_I2D5Ref2 = 2048;

    AD_TempSys = EVADC_G0RES6.B.RESULT;

    AD_TempSys2 = EVADC_G1RES2.B.RESULT;

	AD_InterVolt1d2     	= 1065;

	AD_InterMCUTemp = 640;

	AD_TorqueSenPower = 780;

	AD_RotorSenPower = 2148;
#if 0
	IOC_Tor1Duty        = Sent_T2SentToPwm;
	if(Sent_T1Count < 25)
	{
		IOC_Tor1Frez        = 2000;
	}
	else
	{
		IOC_Tor1Frez = 0;
	}
	IOC_Tor2Duty        = Sent_T1SentToPwm;
	if(Sent_T2Count < 25)
	{
		IOC_Tor2Frez        = 2000;
	}
	else
	{
		IOC_Tor2Frez = 0;
	}
#else
	IOC_Tor1Duty        = Sent_T2SentToPwm;
	if(Sent_T1Count < 25)
	{
		IOC_Tor1Frez        = 2000;
	}
	else
	{
		IOC_Tor1Frez = 0;
	}
	IOC_Tor2Duty        =  Sent_T1SentToPwm;
	if(Sent_T2Count < 25)
	{
		IOC_Tor2Frez        = 2000;
	}
	else
	{
		IOC_Tor2Frez = 0;
	}
#endif
	Sent_T1Count ++;
	Sent_T2Count ++;
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void IoHwAb_SlowDataProcess(void)
{
	 IO_PredriverState1 = Dio_ReadChannel(DioConf_DioChannel_P21_0);
	 IO_PredriverState2 = Dio_ReadChannel(DioConf_DioChannel_P21_2);
#if 1
	IOC_AngpDuty        =  Sent_APSentToPwm; //mod by liuyang at 240909
	if((Sent_T1Count < 25) && (Sent_T2Count < 25))
	{
		IOC_AngpFrez        = 1000;
	}
	else
	{
		IOC_AngpFrez = 0;
	}
	IOC_AngsDuty        = 10000 - Sent_ASSentToPwm;
	if(Sent_ASCount < 50)
	{
		IOC_AngsFrez        = 200;
	}
	else
	{
		IOC_AngsFrez = 0;
	}
#else
	IOC_AngpDuty        = Sent_APSentToPwm;
	if((Sent_T1Count < 25) && (Sent_T2Count < 25))
	{
		IOC_AngpFrez        = 1000;
	}
	else
	{
		IOC_AngpFrez = 0;
	}
	IOC_AngsDuty        = Sent_ASSentToPwm;
	if(Sent_ASCount < 50)
	{
		IOC_AngsFrez        = 200;
	}
	else
	{
		IOC_AngsFrez = 0;
	}
#endif

	ANGLE_ZERO_CALIB = fsCalibrationData.data.anglezero.a0;
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void IoHwAb_TMRCorrection(void)
{
    sint16 diffsin[PreDriver_Num] = {0,};
    sint16 diffcos[PreDriver_Num] = {0,};

    sint16 diffsinPhase[PreDriver_Num] = {0,};
    sint16 diffcosPhase[PreDriver_Num] = {0,};

    diffsin[PreDriver_01] = AD_RotorMainSin1 - AD_RotorSubSin1;
    diffcos[PreDriver_01] = AD_RotorMainCos1 - AD_RotorSubCos1;

	diffsin[PreDriver_02] = AD_RotorMainSin2 - AD_RotorSubSin2;
    diffcos[PreDriver_02] = AD_RotorMainCos2 - AD_RotorSubCos2;

    if(Fv_TESTmode_CrlReqFlag == TESTMODE_OpenLoopFlag)
    {
        if(diffsin[PreDriver_01] > AD_RotorSinOffsetMax[PreDriver_01])
        {
            AD_RotorSinOffsetMax[PreDriver_01] = diffsin[PreDriver_01];
        }
        else if(diffsin[PreDriver_01] < AD_RotorSinOffsetMin[PreDriver_01])
        {
            AD_RotorSinOffsetMin[PreDriver_01] = diffsin[PreDriver_01];
        }
        else
        {

        }

		if(diffsin[PreDriver_02] > AD_RotorSinOffsetMax[PreDriver_02])
        {
            AD_RotorSinOffsetMax[PreDriver_02] = diffsin[PreDriver_02];
        }
        else if(diffsin[PreDriver_02] < AD_RotorSinOffsetMin[PreDriver_02])
        {
            AD_RotorSinOffsetMin[PreDriver_02] = diffsin[PreDriver_02];
        }
        else
        {

        }

        if(diffcos[PreDriver_01] > AD_RotorCosOffsetMax[PreDriver_01])
        {
            AD_RotorCosOffsetMax[PreDriver_01] = diffcos[PreDriver_01];
        }
        else if(diffcos[PreDriver_01] < AD_RotorCosOffsetMin[PreDriver_01])
        {
            AD_RotorCosOffsetMin[PreDriver_01] = diffcos[PreDriver_01];
        }
        else
        {

        }

		if(diffcos[PreDriver_02] > AD_RotorCosOffsetMax[PreDriver_02])
        {
            AD_RotorCosOffsetMax[PreDriver_02] = diffcos[PreDriver_02];
        }
        else if(diffcos[PreDriver_02] < AD_RotorCosOffsetMin[PreDriver_02])
        {
            AD_RotorCosOffsetMin[PreDriver_02] = diffcos[PreDriver_02];
        }
        else
        {

        }

    }
    diffsinPhase[PreDriver_01] = (sint16)(((sint32)(diffsin[PreDriver_01] - (AD_RotorSinOffsetMax[PreDriver_01] + AD_RotorSinOffsetMin[PreDriver_01]) / 2) * 32768)
            /(AD_RotorSinOffsetMax[PreDriver_01] - AD_RotorSinOffsetMin[PreDriver_01]) / 8);

    diffcosPhase[PreDriver_01] = (sint16)(((sint32)(diffcos[PreDriver_01] - (AD_RotorCosOffsetMax[PreDriver_01] + AD_RotorCosOffsetMin[PreDriver_01]) / 2) * 32768)
            /(AD_RotorCosOffsetMax[PreDriver_01] - AD_RotorCosOffsetMin[PreDriver_01]) / 8);

	diffsinPhase[PreDriver_02] = (sint16)(((sint32)(diffsin[PreDriver_02] - (AD_RotorSinOffsetMax[PreDriver_02] + AD_RotorSinOffsetMin[PreDriver_02]) / 2) * 32768)
            /(AD_RotorSinOffsetMax[PreDriver_02] - AD_RotorSinOffsetMin[PreDriver_02]) / 8);

    diffcosPhase[PreDriver_02] = (sint16)(((sint32)(diffcos[PreDriver_02] - (AD_RotorCosOffsetMax[PreDriver_02] + AD_RotorCosOffsetMin[PreDriver_02]) / 2) * 32768)
            /(AD_RotorCosOffsetMax[PreDriver_02] - AD_RotorCosOffsetMin[PreDriver_02]) / 8);

	if(Fv_TESTmode_CrlReqFlag == TESTMODE_OpenLoopFlag)
    {
        if((diffsinPhase[PreDriver_01] + diffcosPhase[PreDriver_01]) > AD_RotorPhasePlusMax[PreDriver_01])
        {
            AD_RotorPhasePlusMax[PreDriver_01] = (diffsinPhase[PreDriver_01] + diffcosPhase[PreDriver_01]);
        }
        else if((diffsinPhase[PreDriver_01] + diffcosPhase[PreDriver_01]) < AD_RotorPhasePlusMin[PreDriver_01])
        {
            AD_RotorPhasePlusMin[PreDriver_01] = (diffsinPhase[PreDriver_01] + diffcosPhase[PreDriver_01]);
        }
        else
        {

        }

		if((diffsinPhase[PreDriver_02] + diffcosPhase[PreDriver_02]) > AD_RotorPhasePlusMax[PreDriver_02])
        {
            AD_RotorPhasePlusMax[PreDriver_02] = (diffsinPhase[PreDriver_02] + diffcosPhase[PreDriver_02]);
        }
        else if((diffsinPhase[PreDriver_02] + diffcosPhase[PreDriver_02]) < AD_RotorPhasePlusMin[PreDriver_02])
        {
            AD_RotorPhasePlusMin[PreDriver_02] = (diffsinPhase[PreDriver_02] + diffcosPhase[PreDriver_02]);
        }
        else
        {

        }

        if((diffcosPhase[PreDriver_01] - diffsinPhase[PreDriver_01]) > AD_RotorPhaseMinusMax[PreDriver_01])
        {
            AD_RotorPhaseMinusMax[PreDriver_01] = (diffcosPhase[PreDriver_01] - diffsinPhase[PreDriver_01]);
        }
        else if((diffcosPhase[PreDriver_01] - diffsinPhase[PreDriver_01]) < AD_RotorPhaseMinusMin[PreDriver_01])
        {
            AD_RotorPhaseMinusMin[PreDriver_01] = (diffcosPhase[PreDriver_01] - diffsinPhase[PreDriver_01]);
        }
        else
        {

        }

		if((diffcosPhase[PreDriver_02] - diffsinPhase[PreDriver_02]) > AD_RotorPhaseMinusMax[PreDriver_02])
        {
            AD_RotorPhaseMinusMax[PreDriver_02] = (diffcosPhase[PreDriver_02] - diffsinPhase[PreDriver_02]);
        }
        else if((diffcosPhase[PreDriver_02] - diffsinPhase[PreDriver_02]) < AD_RotorPhaseMinusMin[PreDriver_02])
        {
            AD_RotorPhaseMinusMin[PreDriver_02] = (diffcosPhase[PreDriver_02] - diffsinPhase[PreDriver_02]);
        }
        else
        {

        }
    }

	AD_RotorCosCorrect[PreDriver_01] = (sint16)(((sint32)(diffsinPhase[PreDriver_01] + diffcosPhase[PreDriver_01]) * 32768)
            / (AD_RotorPhasePlusMax[PreDriver_01] - AD_RotorPhasePlusMin[PreDriver_01]) / 4);
    AD_RotorSinCorrect[PreDriver_01] = (sint16)(((sint32)(diffcosPhase[PreDriver_01] - diffsinPhase[PreDriver_01]) * 32768)
            / (AD_RotorPhaseMinusMax[PreDriver_01] - AD_RotorPhaseMinusMin[PreDriver_01]) / 4);

    AD_RotorCosCorrect[PreDriver_02] = (sint16)(((sint32)(diffsinPhase[PreDriver_02] + diffcosPhase[PreDriver_02]) * 32768)
            / (AD_RotorPhasePlusMax[PreDriver_02] - AD_RotorPhasePlusMin[PreDriver_02]) / 4);
    AD_RotorSinCorrect[PreDriver_02] = (sint16)(((sint32)(diffcosPhase[PreDriver_02] - diffsinPhase[PreDriver_02]) * 32768)
            / (AD_RotorPhaseMinusMax[PreDriver_02] - AD_RotorPhaseMinusMin[PreDriver_02]) / 4);

}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void IoHwAb_GetPredriver01PwmDuty(void)
{
	IO_UphaseDuty1 = Gtm_TimGetPwmDuty(GTM_TIM_CH_7);
	IO_VphaseDuty1 = Gtm_TimGetPwmDuty(GTM_TIM_CH_2);
	IO_WphaseDuty1 = Gtm_TimGetPwmDuty(GTM_TIM_CH_3);
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void IoHwAb_GetPredriver02PwmDuty(void)
{
	IO_UphaseDuty2 = Gtm_TimGetPwmDuty(GTM_TIM_CH_5);
	IO_VphaseDuty2 = Gtm_TimGetPwmDuty(GTM_TIM_CH_6);
	IO_WphaseDuty2 = Gtm_TimGetPwmDuty(GTM_TIM_CH_0);
}

/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
boolean IoHwAb_GetKL15_Status(void)
{
	uint16 KL15_volt;
	KL15_volt = AD_IgnitionSys >> 7 ;
	if (KL15_volt >= 6 )
    {
        return TRUE;
    }
	if (KL15_volt<6)
    {
        return FALSE;
    }
}