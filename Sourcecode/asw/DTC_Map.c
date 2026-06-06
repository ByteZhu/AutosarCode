/*
 * DTC_Map.c
 *
 *  Created on: 2024Äê9ÔÂ5ÈÕ
 *      Author: Administrator
 */
#include "common.h"
#include "Dem_Cfg_EventId.h"

#define DEM_AGING_COUNT  40u


const DTC_Code_Str DTC_CodeStrInfo[EPS_DTC_NUM_MAX] =
{
	0
	#if 0
	/* 0 DTC_MCUcheck_RAM */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x060696_Event		/* DEM EVENT ID */
	},

	/* 1 DTC_MCUcheck_ROM */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x060696_Event		/* DEM EVENT ID */
	},

	/* 2 DTC_MCUcheck_PerOthers */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x060696_Event		/* DEM EVENT ID */
	},

	/* 3 DTC_MCUcheck_UnexpReset */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 4 DTC_MCUcheck_ExtWatchDog */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 5 DTC_MCUcheck_MotorCtrl */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd45148_Event		/* DEM EVENT ID */
	},

	/* 6 DTC_MCUcheck_AssistCtrl */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd45148_Event		/* DEM EVENT ID */
	},

	/* 7 DTC_MCUcheck_CommTimeout */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 8 DTC_MCUcheck_ViceMonitor */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 9 DTC_MOTORcheck_Predriver */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 10 DTC_ANGLEcheck_ExtAngleErr */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 11 DTC_MOTORcheck_PhaseOpen */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 12 DTC_MOTORcheck_OverCurrent */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x962649_Event		/* DEM EVENT ID */
	},

	/* 13 DTC_MOTORcheck_Output */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x962649_Event		/* DEM EVENT ID */
	},

	/* 14 DTC_CURRENTcheck_MiddSig */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x962649_Event		/* DEM EVENT ID */
	},

	/* 15 DTC_CURRENTcheck_3PhaseSum */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x962649_Event		/* DEM EVENT ID */
	},

	/* 16 DTC_DSTFUNCcheck_ReqValueOverLimt */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 17 DTC_CURRENTcheck_IcalibInvalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x060141_Event		/* DEM EVENT ID */
	},

	/* 18 DTC_TORQUEcheck_PowerSupply */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600b49_Event		/* DEM EVENT ID */
	},

	/* 19 DTC_TORQUEcheck_PowerSupply */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600b49_Event		/* DEM EVENT ID */
	},

	/* 20 DTC_TORQUEcheck_MainWave */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600b49_Event		/* DEM EVENT ID */
	},

	/* 21 DTC_TORQUEcheck_SubRange */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600b49_Event		/* DEM EVENT ID */
	},

	/* 22 DTC_TORQUEcheck_SubWave */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600b49_Event		/* DEM EVENT ID */
	},

	/* 23 DTC_TORQUEcheck_SumOfMS */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600b49_Event		/* DEM EVENT ID */
	},

	/* 24 DTC_TORQUEcheck_Offset */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600b49_Event		/* DEM EVENT ID */
	},

	/* 25 DTC_ANGLEcheck_NoZeroCalib */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x5b0049_Event		/* DEM EVENT ID */
	},

	/* 26 DTC_ANGLEcheck_Invalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x5b0049_Event		/* DEM EVENT ID */
	},

	/* 27 DTC_ANGLEcheck_Unreal */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x5b0049_Event		/* DEM EVENT ID */
	},

	/* 28 DTC_ANGLEcheck_NoEndLearn */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 29 DTC_ANGLEcheck_CheckRotor */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x5b0049_Event		/* DEM EVENT ID */
	},

	/* 30 DTC_RESOLVERcheck_PowerSupply */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600d49_Event		/* DEM EVENT ID */
	},

	/* 31 DTC_RESOLVERcheck_MiddSig */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600d49_Event		/* DEM EVENT ID */
	},

	/* 32 DTC_RESOLVERcheck_SinRange */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600d49_Event		/* DEM EVENT ID */
	},

	/* 33 DTC_RESOLVERcheck_SinOffset */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600d49_Event		/* DEM EVENT ID */
	},

	/* 34 DTC_RESOLVERcheck_CosRange */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600d49_Event		/* DEM EVENT ID */
	},

	/* 35 DTC_RESOLVERcheck_CosOffset */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600d49_Event		/* DEM EVENT ID */
	},

	/* 36 DTC_RESOLVERcheck_LotusWave */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x600d49_Event		/* DEM EVENT ID */
	},

	/* 37 DTC_LKAFUNCcheck_ReqValueOverLimt */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 38 DTC_LKAFUNCcheck_AbnormalExit */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 39 DTC_APAFUNCcheck_AbnormalExit */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 40 DTC_POWERcheck_Burned */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xee0368_Event		/* DEM EVENT ID */
	},

	/* 41 DTC_POWERcheck_LowReset */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xee0468_Event		/* DEM EVENT ID */
	},

	/* 42 DTC_POWERcheck_OverShut */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xee0368_Event		/* DEM EVENT ID */
	},

	/* 43 DTC_POWERcheck_LowShut */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xee0468_Event		/* DEM EVENT ID */
	},

	/* 44 DTC_POWERcheck_VolLimitAst */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xF003A2_Event		/* DEM EVENT ID */
	},

	/* 45 DTC_POWERcheck_VBATdt */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 46 DTC_POWERcheck_IGkey */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 47 DTC_POWERcheck_Hold */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 48 DTC_EEPROMcheck_CommTimeout */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0x060141_Event		/* DEM EVENT ID */
	},

	/* 49 DTC_EEPROMcheck_BootCheck */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 50 DTC_EEPROMcheck_ConfigCheck */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 51 DTC_EEPROMcheck_CalibCheck */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 52 DTC_EEPROMcheck_AngleCheck */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 53 DTC_EEPROMcheck_AngleCrrCheck */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 54 DTC_ASTcheck_AstDegrade */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 55 DTC_EEPROMcheck_OtherCheck */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 56 DTC_TEMPcheck_ADport */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 57 DTC_TEMPcheck_Range */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd09a96_Event		/* DEM EVENT ID */
	},

	/* 58 DTC_TEMPcheck_Over */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xee0068_Event		/* DEM EVENT ID */
	},

	/* 59 DTC_TEMPcheck_TempLimitAst */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 60 DTC_TEMPcheck_HeatShut */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x01,            /* DTC priority */
		DemConf_DemEventParameter_DTC_0xd45198_Event		/* DEM EVENT ID */
	},

	/* 61 DTC_CANCOMMcheck_Busoff */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 62 DTC_CANCOMMcheck_ABSVsLostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 63 DTC_CANCOMMcheck_ABSVsDataInvalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 64 DTC_CANCOMMcheck_ABSVsCRCError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 65 DTC_CANCOMMcheck_ABSVsCounterError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 66 DTC_CANCOMMcheck_ABSWsLostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 67 DTC_CANCOMMcheck_ABSWsDataInvalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 68 DTC_CANCOMMcheck_ABSWsCRCError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 69 DTC_CANCOMMcheck_ABSWsCounterError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 70 DTC_CANCOMMcheck_IPB2LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 71 DTC_CANCOMMcheck_IPB2DataInvalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 72 DTC_CANCOMMcheck_IPB2CRCError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 73 DTC_CANCOMMcheck_IPB2CounterError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 74 DTC_CANCOMMcheck_IPB5LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 75 DTC_CANCOMMcheck_IPB5DataInvalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 76 DTC_CANCOMMcheck_IPB6LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 77 DTC_CANCOMMcheck_IPB6DataInvalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 78 DTC_CANCOMMcheck_IPB6CRCError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 79 DTC_CANCOMMcheck_IPB6CounterError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 80 DTC_CANCOMMcheck_CCU3LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 81 DTC_CANCOMMcheck_CCU2LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 82 DTC_CANCOMMcheck_VCU3LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 83 DTC_CANCOMMcheck_ADS2LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 84 DTC_CANCOMMcheck_ADS2CRCError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 85 DTC_CANCOMMcheck_ADS2CounterError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 86 DTC_CANCOMMcheck_ADS1LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 87 DTC_CANCOMMcheck_ADS1CRCError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 88 DTC_CANCOMMcheck_ADS1CounterError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 89 DTC_CANCOMMcheck_APALostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 90 DTC_CANCOMMcheck_APADataInvalid */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 91 DTC_CANCOMMcheck_APACRCError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 92 DTC_CANCOMMcheck_APACounterError */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 93 DTC_CANCOMMcheck_SCULostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 94 DTC_CANCOMMcheck_BCM2LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 95 DTC_CANCOMMcheck_CCU1LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 96 DTC_CANCOMMcheck_SCUInvalidDLC */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 97 DTC_CANCOMMcheck_RemoteInvalidDLC */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 98 DTC_CANCOMMcheck_BrakeInvalidDLC */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 99 DTC_CANCOMMcheck_BrakeLostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 100 DTC_CANCOMMcheck_IPB7LostComm */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 101 DTC_CANCOMMcheck_VCU1InvalidDLC */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 102 DTC_CANCOMMcheck_BCMInvalidData */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	},

	/* 103 DTC_CANCOMMcheck_IPB7InvalidData */
	{
		DEM_AGING_COUNT,	/* maximum ignition cycle to clear DTC */
		0x03,            /* DTC priority */
		DEM_EVENTID_INVALID		/* DEM EVENT ID */
	}
	#endif
};

