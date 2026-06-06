/*
 * CDD_TPS653852A.c
 *
 *  Created on: 2023��7��17��
 *      Author: tiand
 */
#include "CDD_TPS653852A.h"
#include "CDD_TPS653852A_Cfg.h"
#include "CDD_TCAN1145.h"
#include "CDD_TCAN1145_Cfg.h"
#include "MemIf.h"
#include "NvM.h"
#include "Spi.h"
#include "common.h"
#include "Dio.h"
#include "Dem.h"
//#include "IdsM.h"
#include "EcuM.h"
#include "SleepLogic.h"
typedef union
{
	uint32 dword;
	uint8 byte[4];
	struct
	{
		uint8 crc;
		uint8 data;
		uint8 cmd;
		uint8 rsv;
	}bits;
}TPS653852A_TxDataType;

typedef union
{
	uint32 dword;
	uint8 byte[4];
	struct
	{
		uint8 crc;
		uint8 r;
		uint8 stat;
		uint8 rsv;
	}bits;
}TPS653852A_RxDataType;

#define PMIC_STATE_BITS     0xE0u
#define PMIC_SAFE_STATE     0x80u
#define PMIC_ACTIVE_STATE   0xA0u
#define PMIC_DIAGNOSTIC_STATE   0xE0u
#define NRES_ERR_BIT        0x10u

#define SAFE            4u
#define ACTIVE          5u
#define DIAGNOSTIC      7u

#define RD_DEV_ID       0x06

#define RD_DEV_REV      0x0c

#define RD_DEV_STAT     0x11

#define RD_DEV_CFG_1        0xAF
#define WR_DEV_CFG_1        0xB7

#define RD_DEV_CFG_2        0x48
#define WR_DEV_CFG_2        0x95

#define RD_DEV_CFG_3        0x3F
#define WR_DEV_CFG_3        0x83

#define RD_SAFETY_FUNC_CFG  0x3A
#define WR_SAFETY_FUNC_CFG  0x35

#define RD_DIAG_CFG_CTRL    0xDD
#define WR_DIAG_CFG_CTRL    0xCC

#define RD_DIAG_MUX_SEL     0xAC
#define WR_DIAG_MUX_SEL     0xC9

#define RD_SAFETY_BIST_CTRL 0x3C
#define WR_SAFETY_BIST_CTRL 0x9F

#define RD_SAFETY_CFG_CRC   0x5A
#define WR_SAFETY_CFG_CRC   0x63

#define RD_SAFETY_CHECK_CTRL    0x44
#define WR_SAFETY_CHECK_CTRL    0x93

#define RD_SAFETY_STAT_1    0x24
#define RD_SAFETY_STAT_2    0xC5
#define RD_SAFETY_STAT_3    0xA3
#define RD_SAFETY_STAT_4    0xA5
#define RD_SAFETY_STAT_5    0xC0

#define RD_SAFETY_ERR_STAT_1    0xAA
#define WR_SAFETY_ERR_STAT_1    0xA9

#define RD_SAFETY_ERR_STAT_2    0x4A

#define RD_VMON_STAT_1      0x12
#define RD_VMON_STAT_2      0xA6
#define RD_VMON_STAT_3      0xDA

#define RD_WD_WIN1_CFG      0x2E
#define WR_WD_WIN1_CFG      0xED

#define RD_WD_WIN2_CFG      0x5
#define WR_WD_WIN2_CFG      0x9

#define RD_WD_QUESTION      0x36

#define RD_WD_STATUS        0x4E

#define RD_SENS_CTRL        0x56
#define WR_SENS_CTRL        0x7B

#define RD_WD_QUESTION_FDBK 0x78
#define WR_WD_QUESTION_FDBK 0x77

#define WR_SAFETY_ERR_PWM_HMAX  0xD8
#define RD_SAFETY_ERR_PWM_HMAX  0xD7

#define WR_SAFETY_ERR_PWM_HMIN  0xB0
#define RD_SAFETY_ERR_PWM_HMIN  0x52

#define WR_SAFETY_ERR_PWM_LMAX  0x7E
#define RD_SAFETY_ERR_PWM_LMAX  0x59

#define WR_SAFETY_ERR_PWM_LMIN  0x5F
#define RD_SAFETY_ERR_PWM_LMIN  0x80

#define RD_SAFETY_ERR_CFG_2 0xE9

#define RD_POWER_ON_RST     0x31

#define RD_SAFETY_PWD_THR_CFG   0x39

#define RD_SAFETY_ERR_CFG_1 0x30

#define RD_SPI_INV_TRAN_STAT    0xB3

#define WR_SAFETY_ERR_CFG_1 0xDB

#define WR_SAFETY_ERR_CFG_2 0xCF

#define WR_SAFETY_PWD_THR_CFG   0x99

#define WR_WD_ANSWER        0xE1

#define TPS653832A_MCU_RST_RQ()     TPS653832A_SendAndReceive(0x04, 0x5A)

#define TPS653832A_SAFE_EXIT()	TPS653832A_SendAndReceive(0x9A, 0xA5)

#define TPS653832A_SW_UNLOCK()	TPS653832A_SendAndReceive(0xBB, 0x55)

#define TPS653832A_SW_LOCK()	TPS653832A_SendAndReceive(0xBD, 0xAA)

#define TPS653832A_CLR_PWRL()		TPS653832A_SendAndReceive(0x4B, 0xAA)

#define TPS653832A_CAN_PWD()    TPS653832A_SendAndReceive(0x7D, 0x55)

#define TPS653832A_STATE_INIT			0x00u

#define TPS653832A_STATE_DIAG			0x01u

#define TPS653832A_STATE_DIAG_TRANSIT	0x02u

#define TPS653832A_STATE_ACTIVE			0x03u

#define TPS653832A_STATE_SAFE			0x04u

#define TPS653832A_STATE_SAFE_TRANSIT	0x05u

boolean TPS653852A_SAFETY_ERR_SATA_1_ClearFlag = 0;
uint32 TPS653832A_SpiTxData = 0;
uint32 TPS653832A_SpiRxData = 0;
uint8 TPS653832A_State = 0;
uint16  TPS653832A_CrcErrCnt = 0;
uint8 TPS653832A_CrcErrFlag = 0;
TPS653852A_RxDataType TPS653832A_DebugStat[13] = {{0},};
TPS653852A_VoltFaultType TPS653832A_VoltFault = {0};
boolean TPS653832A_ShutDownReqFlag = FALSE;

const uint32 TPS653832A_WDAnswer[16] = {
		0xFF0FF000,	0xB040BF4F, 0xE919E616, 0xA656A959,
		0x75857A8A, 0x3ACA35C5, 0x63936C9C, 0x2CDC23D3,
		0xD222DD2D, 0x9D6D9262, 0xC434CB3B, 0x8B7B8474,
		0x58A857A7, 0x17E718E8, 0x4EBE41B1, 0x01F10EFE
};


static uint8 TPS653832A_CalcCRC8(uint8 *buf, uint8 len);
static TPS653852A_RxDataType TPS653832A_SendAndReceive(uint8 cmd, uint8 data);
static void TPS653832A_ConfigCrcCheck(void);
static void TPS653832A_QAWatchdogFeed(void);
static uint8 TPS653832A_CrcCheck(TPS653852A_RxDataType Rxdata);
static void TPS653832A_DiagStateConfig(void);
static void TPS653832A_DiagTransitProcess(void);
static void TPS653832A_SafeTransitProcess(void);
static void TPS653832A_SafeStateProcess(void);
static void TPS653832A_ActiveStateProcess(void);
static void TPS653832A_InitStateProcess(void);
static void TPS653832A_VoltageMonitor(void);
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void CDD_TPS653852A_Init(void)
{
	TPS653852A_RxDataType rxdata = {0,};
	uint8 ret = 0;

	TPS653832A_VoltFault.word = 0;

	rxdata = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);

	ret = TPS653832A_CrcCheck(rxdata);

	if(ret > 0)
	{
		rxdata = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);
		ret = TPS653832A_CrcCheck(rxdata);
	}

	if(ret > 0)
	{
		/* spi error, retry init */
		TPS653832A_State = TPS653832A_STATE_INIT;
	}
	else
	{
		if((rxdata.bits.r & PMIC_STATE_BITS) == PMIC_DIAGNOSTIC_STATE)
		{
			/* diagnostic state, do configuration */
			TPS653832A_DiagStateConfig();
		}
		else
		{
			/* other state, retry init */
			TPS653832A_State = TPS653832A_STATE_INIT;
		}
	}
	/* ESM TPS mode */
	Dio_WriteChannel(DioConf_DioChannel_P33_3, STD_HIGH);
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void CDD_TPS653852A_MainFunction(void)
{
	TPS653852A_RxDataType rxdata = {0,};
	uint8 crcerror = 0;
	boolean shutdownpending = 0;

	NvM_Rb_StatusType status_NvM;
	MemIf_StatusType stMemIf_en;
	static uint8 rescnt = 0;
	static uint8 saveall = 0;

#if 0
	/* to do */
	shutdownpending = Rte_IRead_MainFunction_FS26_DataIn_SysTaskShutDownPending();
#endif
	Fv_SPITimeoutReq = 0xAA;
	switch(TPS653832A_State)
	{
		case TPS653832A_STATE_INIT:
			TPS653832A_InitStateProcess();
			break;
		case TPS653832A_STATE_DIAG:
			rxdata = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);
			crcerror = TPS653832A_CrcCheck(rxdata);
			if((crcerror == 0) && ((rxdata.bits.r & PMIC_STATE_BITS) == PMIC_DIAGNOSTIC_STATE))
			{
				TPS653832A_DiagStateConfig();
			}
			else
			{
				/* error, go to safe state */
				TPS653832A_State = TPS653832A_STATE_SAFE;
			}
			break;
		case TPS653832A_STATE_DIAG_TRANSIT:
			TPS653832A_DiagTransitProcess();
			break;
		case TPS653832A_STATE_ACTIVE:
			TPS653832A_ActiveStateProcess();
			break;
		case TPS653832A_STATE_SAFE:
			TPS653832A_SafeStateProcess();
			break;
		case TPS653832A_STATE_SAFE_TRANSIT:
			TPS653832A_SafeTransitProcess();
			break;
		default:
			break;
	}

	/* feed Q&A watchdog */
	TPS653832A_QAWatchdogFeed();

	/* sleep request, go to sleep */
	if (TRUE == TPS653832A_ShutDownReqFlag)
	{
		if ((TRUE == TCAN1145_GetCANWakeupInterruptStatusTransceiver1()) ||
			(TRUE == SleepLogic_GetIGkeyState()))
		{
			Mcu_PerformReset();
		}

		rxdata = TPS653832A_SendAndReceive(RD_DEV_STAT, 0xFF);
		if(TPS653832A_CrcCheck(rxdata) == 0)
		{
			if((rxdata.bits.r & 0x02) > 0)
			{
				(void)TPS653832A_CAN_PWD();
			}
			else
			{
				/* sleep request, go to sleep */
				(void)TPS653832A_CLR_PWRL();
			}
		}
	}
#if 0
	if((Fv_TPS653852GoToSleep > 0)/* && (shutdownpending > 0)*/ && (Fv_IGkeyEffect < 1)
			&& (Fv_TCAN1145Sleep > 0) && (SysTaskShutDownPending > 0))
	{

		/* sleep request, go to sleep */
		if(saveall == 0)
		{
			Dem_Shutdown();
			NvM_WriteAll();
			saveall = 1;
		}
		else
		{
			if(rescnt < 50)
			{
				rescnt++;
			}
			NvM_MainFunction();
			MemIf_Rb_MainFunction();
			NvM_Rb_GetStatus(&status_NvM);
			stMemIf_en = MemIf_Rb_GetStatus();
			if(((status_NvM != NVM_RB_STATUS_BUSY) && (stMemIf_en != MEMIF_BUSY) && (rescnt > 10)))
			{
				(void)TCAN1145_SendAndReceive1(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x81);

				(void)TCAN1145_SendAndReceive2(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x81);
				rxdata = TPS653832A_SendAndReceive(RD_DEV_STAT, 0xFF);
				if(TPS653832A_CrcCheck(rxdata) == 0)
				{
					if((rxdata.bits.r & 0x02) > 0)
					{
						(void)TPS653832A_CAN_PWD();
					}
					else
					{
						/* sleep request, go to sleep */
						(void)TPS653832A_CLR_PWRL();
					}
				}	
			}
		}		
	}
	else
	{
		saveall = 0;
	}
#endif
	Dio_WriteChannel(DioConf_DioChannel_P33_3, STD_HIGH);
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_VoltageMonitor(void)
{
	TPS653852A_RxDataType rxdata = {0,};
	uint8 crcerror = 0;
	static uint8 queStep = 0;
	static uint16 timeoutcnt = 0;
	static uint16 voltfaultcnt = 0;

	rxdata = TPS653832A_SendAndReceive(RD_VMON_STAT_1, 0xFF);
	crcerror |= (TPS653832A_CrcCheck(rxdata) << 0U);
	if((crcerror & (1U << 0U)) == 0)
	{
		if(rxdata.bits.r > 0)
		{
			//TPS653832A_VoltFault.bits.VBAT_OV = ((rxdata.bits.r >> 7U) & 1);
			//TPS653832A_VoltFault.bits.VBAT_UV = ((rxdata.bits.r >> 6U) & 1);
			TPS653832A_VoltFault.bits.VCP_UV = ((rxdata.bits.r >> 5U) & 1);
		}
	}else{rxdata.dword = 0;}
	rxdata = TPS653832A_SendAndReceive(RD_VMON_STAT_2, 0xFF);
	crcerror |= (TPS653832A_CrcCheck(rxdata) << 1U);
	if((crcerror & (1U << 1U)) == 0)
	{
		if(rxdata.bits.r > 0)
		{
			TPS653832A_VoltFault.bits.VDD6_OV = ((rxdata.bits.r >> 7U) & 1);
			TPS653832A_VoltFault.bits.VDD6_UV = ((rxdata.bits.r >> 6U) & 1);
			TPS653832A_VoltFault.bits.VDD5_OV = ((rxdata.bits.r >> 5U) & 1);
			TPS653832A_VoltFault.bits.VDD5_UV = ((rxdata.bits.r >> 4U) & 1);
			TPS653832A_VoltFault.bits.VDD35_OV = ((rxdata.bits.r >> 3U) & 1);
			TPS653832A_VoltFault.bits.VDD35_UV = ((rxdata.bits.r >> 2U) & 1);
		}
	}else{rxdata.dword = 0;}
	rxdata = TPS653832A_SendAndReceive(RD_VMON_STAT_3, 0xFF);
	crcerror |= (TPS653832A_CrcCheck(rxdata) << 2U);
	if((crcerror & (1U << 2U)) == 0)
	{
		if(rxdata.bits.r > 0)
		{
			TPS653832A_VoltFault.bits.VREG_UV = ((rxdata.bits.r >> 5U) & 1);
			TPS653832A_VoltFault.bits.VDD6_LP_UV = ((rxdata.bits.r >> 4U) & 1);
			TPS653832A_VoltFault.bits.VSOUT1_OV = ((rxdata.bits.r >> 3U) & 1);
			TPS653832A_VoltFault.bits.VSOUT1_UV = ((rxdata.bits.r >> 2U) & 1);
			TPS653832A_VoltFault.bits.VSOUT2_OV = ((rxdata.bits.r >> 1U) & 1);
			TPS653832A_VoltFault.bits.VSOUT2_UV = ((rxdata.bits.r >> 0U) & 1);
		}
	}else{rxdata.dword = 0;}



	if(crcerror > 0)
	{
		timeoutcnt ++;

		if(timeoutcnt > 40)
		{
			timeoutcnt = 40;
			/* spi erorr, retry 5 times = 25ms */
			TPS653832A_State = TPS653832A_STATE_SAFE;
		}
	}
	else{
		if(TPS653832A_VoltFault.word > 0)
		{
			voltfaultcnt ++;
			if(voltfaultcnt > 2)
			{
				voltfaultcnt = 3;
				TPS653832A_State = TPS653832A_STATE_SAFE;
			}
			else
			{
				TPS653832A_VoltFault.word = 0;
			}
		}		
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_InitStateProcess(void)
{
	TPS653852A_RxDataType rxdata = {0,};
	uint8 crcerror = 0;
	static uint16 timeoutcnt = 0;
	static uint16 retrycnt = 0;

	rxdata = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);

	crcerror = TPS653832A_CrcCheck(rxdata);

	if(crcerror > 0)
	{
		timeoutcnt ++;

		if(timeoutcnt > 40)
		{
			timeoutcnt = 40;
			/* spi erorr, retry 5 times = 25ms */
			TPS653832A_State = TPS653832A_STATE_SAFE;
		}
	}
	else
	{
		timeoutcnt = 0;
		if((rxdata.bits.r & PMIC_STATE_BITS) == PMIC_DIAGNOSTIC_STATE)
		{
			/* diagnostic state, go to diag */
			TPS653832A_State = TPS653832A_STATE_DIAG;
		}
		else if((rxdata.bits.r & PMIC_STATE_BITS) == PMIC_ACTIVE_STATE)
		{
			if((rxdata.bits.r & 0x07) < 5)
			{
				/* active state, go to active */
				TPS653832A_State = TPS653832A_STATE_ACTIVE;
			}
			else
			{
				(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, 0x80);
			}
		}
		else
		{
			(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, 0x04);
			/* safe state, read status */
			(void)TPS653832A_SendAndReceive(RD_POWER_ON_RST, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_SAFETY_STAT_1, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_SAFETY_STAT_2, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_SAFETY_STAT_3, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_SAFETY_STAT_4, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_SAFETY_ERR_STAT_1, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_SAFETY_ERR_STAT_2, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_VMON_STAT_1, 0xFF);
			(void)TPS653832A_SendAndReceive(RD_VMON_STAT_2, 0xFF);
			rxdata = TPS653832A_SendAndReceive(RD_SAFETY_ERR_STAT_1, 0xFF);
			crcerror = TPS653832A_CrcCheck(rxdata);

			if((crcerror == 0) && ((rxdata.bits.r & 0x20) == 0))
			{
				retrycnt = 0;
				/* PMIC has only esm and watchdog error, try to transit to diag state */
				TPS653832A_State = TPS653832A_STATE_SAFE_TRANSIT;
				if((rxdata.bits.r & 0x0F) >= 14)
				{
					TPS653852A_SAFETY_ERR_SATA_1_ClearFlag = TRUE;
				}
			}
			else
			{
				if((crcerror > 0) && (retrycnt < 5))
				{
					retrycnt ++;
				}
				else
				{
					retrycnt = 0;
					/* other error, go to safe state */
					TPS653832A_State = TPS653832A_STATE_SAFE;
				}
			}
		}
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_DiagStateConfig(void)
{
	uint8 data = 0;
	TPS653852A_RxDataType SENS_CTRL = {0,};

	/* config pmic */
	(void)TPS653832A_SW_UNLOCK();
	(void)TPS653832A_SendAndReceive(WR_DEV_CFG_1, PMIC_DEV_CFG_1);
	(void)TPS653832A_SendAndReceive(WR_DEV_CFG_2, PMIC_DEV_CFG_2);
	(void)TPS653832A_SendAndReceive(WR_DEV_CFG_3, PMIC_DEV_CFG_3);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_ERR_CFG_1, PMIC_SAFETY_ERR_CFG_1);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_ERR_CFG_2, PMIC_SAFETY_ERR_CFG_2);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_BIST_CTRL, 0x00);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_FUNC_CFG, PMIC_SAFETY_FUNC_CFG);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, PMIC_SAFETY_CHECK_CTRL);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_ERR_PWM_HMAX, PMIC_SAFETY_ERR_PWM_HMAX);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_ERR_PWM_HMIN, PMIC_SAFETY_ERR_PWM_HMIN);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_ERR_PWM_LMAX, PMIC_SAFETY_ERR_PWM_LMAX);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_ERR_PWM_LMIN, PMIC_SAFETY_ERR_PWM_LMIN);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_PWD_THR_CFG, PMIC_SAFETY_PWD_THR_CFG);
	(void)TPS653832A_SendAndReceive(WR_WD_QUESTION_FDBK, PMIC_WD_QUESTION_FDBK);
	(void)TPS653832A_SendAndReceive(WR_WD_WIN1_CFG, PMIC_WD_WIN1_CFG);
	(void)TPS653832A_SendAndReceive(WR_WD_WIN2_CFG, PMIC_WD_WIN2_CFG);
	if(TPS653852A_SAFETY_ERR_SATA_1_ClearFlag == TRUE)
	{
		TPS653832A_SendAndReceive(WR_SAFETY_ERR_STAT_1,0x00);
	}

	SENS_CTRL = TPS653832A_SendAndReceive(RD_SENS_CTRL, 0xFF);

	data = SENS_CTRL.bits.r | PMIC_SENS_CTRL;
	(void)TPS653832A_SendAndReceive(WR_SENS_CTRL, data);

	/* configuration check */
	TPS653832A_ConfigCrcCheck();

	TPS653832A_State = TPS653832A_STATE_DIAG_TRANSIT;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_DiagTransitProcess(void)
{
	TPS653852A_RxDataType rxdata = {0,};
	uint8 crcerror = 0;
	static uint16 retrycnt = 0;


	rxdata = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);

	crcerror = TPS653832A_CrcCheck(rxdata);

	if((crcerror == 0) && ((rxdata.bits.r & PMIC_STATE_BITS) == PMIC_DIAGNOSTIC_STATE))
	{
		(void)TPS653832A_SendAndReceive(RD_POWER_ON_RST, 0xFF);
		/* exit diag state */
		(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, (0x01 | PMIC_SAFETY_CHECK_CTRL));
		TPS653832A_State = TPS653832A_STATE_ACTIVE;

		retrycnt = 0;
	}
	else
	{
		if((crcerror > 0) && (retrycnt < 5))
		{
			retrycnt ++;
		}
		else
		{
			retrycnt = 0;
			/* eorr occured, go to safe */
			TPS653832A_State = TPS653832A_STATE_SAFE;
		}
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_ActiveStateProcess(void)
{
	TPS653852A_RxDataType rxdata = {0,};
	uint8 crcerror = 0;
	static uint16 timeoutcnt = 0;
	static uint8 endrvflag = 0;

	static uint8 safeEnterCnt = 0;

	rxdata = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);
	TPS653832A_VoltageMonitor();

	TPS653832A_DebugStat[12] = rxdata;

	crcerror = TPS653832A_CrcCheck(rxdata);

	if(crcerror > 0)
	{
		timeoutcnt ++;
		/* 200ms crc error, go to safe state */
		if(timeoutcnt > 40)
		{
			timeoutcnt = 40;
			TPS653832A_State = TPS653832A_STATE_SAFE;
			endrvflag = 0;
		}
	}
	else
	{
		timeoutcnt = 0;
		if((rxdata.bits.r & PMIC_STATE_BITS) == PMIC_DIAGNOSTIC_STATE)
		{
			TPS653832A_State = TPS653832A_STATE_DIAG_TRANSIT;
			endrvflag = 0;
		}
		else if((rxdata.bits.r & PMIC_STATE_BITS) == PMIC_SAFE_STATE)
		{
			TPS653832A_State = TPS653832A_STATE_SAFE;
			endrvflag = 0;
		}
		else
		{
			if((rxdata.bits.r & 0x07) < 5)
			{
				/* open predriver */
				(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, (0x20 | PMIC_SAFETY_CHECK_CTRL));
				endrvflag = 1;
				safeEnterCnt = 0;
			}
			else
			{
				if(((rxdata.bits.r & 0x10) == 0) && (endrvflag > 0))
				{
					endrvflag = 0;
					if(safeEnterCnt < 20){
						safeEnterCnt++;
					}
					else{
						TPS653832A_State = TPS653832A_STATE_SAFE;
					}

				}
			}
			fsPredriver_EnableStatus = endrvflag;
		}
	}
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_SafeStateProcess(void)
{
	uint8 crcerror = 0;
	TPS653852A_RxDataType rxdata = {0,};

	rxdata = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);

	crcerror = TPS653832A_CrcCheck(rxdata);

	if(crcerror > 0)
	{
		Fv_ErrorFromGn32 = 1;
	}
	else
	{
		Fv_ErrorFromGn32 = 2;
		TPS653832A_DebugStat[0] = TPS653832A_SendAndReceive(RD_DEV_STAT, 0xFF);
		TPS653832A_DebugStat[1] = TPS653832A_SendAndReceive(RD_SAFETY_STAT_1, 0xFF);
		TPS653832A_DebugStat[2] = TPS653832A_SendAndReceive(RD_SAFETY_STAT_2, 0xFF);
		TPS653832A_DebugStat[3] = TPS653832A_SendAndReceive(RD_SAFETY_STAT_3, 0xFF);
		TPS653832A_DebugStat[4] = TPS653832A_SendAndReceive(RD_SAFETY_STAT_4, 0xFF);
		TPS653832A_DebugStat[5] = TPS653832A_SendAndReceive(RD_SAFETY_STAT_5, 0xFF);
		TPS653832A_DebugStat[6] = TPS653832A_SendAndReceive(RD_SAFETY_ERR_STAT_1, 0xFF);
		TPS653832A_DebugStat[7] = TPS653832A_SendAndReceive(RD_SAFETY_ERR_STAT_2, 0xFF);
		TPS653832A_DebugStat[8] = TPS653832A_SendAndReceive(RD_VMON_STAT_1, 0xFF);
		TPS653832A_DebugStat[9] = TPS653832A_SendAndReceive(RD_VMON_STAT_2, 0xFF);
		TPS653832A_DebugStat[10] = TPS653832A_SendAndReceive(RD_VMON_STAT_3, 0xFF);
		TPS653832A_DebugStat[11] = TPS653832A_SendAndReceive(RD_SPI_INV_TRAN_STAT, 0xFF);
		(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, (0x00 | PMIC_SAFETY_CHECK_CTRL));
	}
#if 0
	/* to do */
	Rte_IWrite_MainFunction_FS26_DataOut_FS26_ErrorInfo((uint8)Fv_ErrorFromGn32);
#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_SafeTransitProcess(void)
{
	(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, (0x00 | PMIC_SAFETY_CHECK_CTRL));
	(void)TPS653832A_SAFE_EXIT();

	TPS653832A_State = TPS653832A_STATE_DIAG;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_QAWatchdogFeed(void)
{
	uint8 state = 0;
	TPS653852A_RxDataType rxdata = {0,};
	static uint8 question = 0;
	uint8 answer = 0;

	rxdata = TPS653832A_SendAndReceive(RD_WD_STATUS, 0xFF);

	state = rxdata.bits.r & 0xC0;

	switch(state)
	{
        case 0:
            answer = (uint8)(TPS653832A_WDAnswer[question]);
            (void)TPS653832A_SendAndReceive(WR_WD_ANSWER, answer);
            break;
        case 0x40:
            answer = (uint8)(TPS653832A_WDAnswer[question] >> 8);
            (void)TPS653832A_SendAndReceive(WR_WD_ANSWER, answer);
            break;
        case 0x80:
            answer = (uint8)(TPS653832A_WDAnswer[question] >> 16);
            (void)TPS653832A_SendAndReceive(WR_WD_ANSWER, answer);
            break;
		case 0xC0:
			rxdata = TPS653832A_SendAndReceive(RD_WD_QUESTION, 0xFF);
			question = rxdata.bits.r & 0x0F;
			answer = (uint8)(TPS653832A_WDAnswer[question] >> 24);
			(void)TPS653832A_SendAndReceive(WR_WD_ANSWER, answer);
			break;
		default:
			break;
	}

}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TPS653832A_ConfigCrcCheck(void)
{
	uint8 crc = 0;
	uint8 databuf[16] = {0,};

    databuf[15] = PMIC_SAFETY_FUNC_CFG;
    databuf[14] = PMIC_DEV_REV;
    databuf[13] = PMIC_DEV_ID;
    databuf[12] = ((PMIC_SAFETY_PWD_THR_CFG & 0xF) << 4) | ((PMIC_SAFETY_ERR_CFG_1 & 0xF0) >> 4);
    databuf[11] = ((PMIC_SAFETY_ERR_CFG_1 & 0xF) << 4) | ((PMIC_WD_QUESTION_FDBK & 0xF0) >> 4);
    databuf[10] = ((PMIC_WD_QUESTION_FDBK & 0xF) << 4) | ((PMIC_WD_WIN2_CFG & 0x1E) >> 1);
    databuf[9] = ((PMIC_WD_WIN2_CFG & 0x1) << 7) | (PMIC_WD_WIN1_CFG & 0x7F);
    databuf[8] = PMIC_SAFETY_ERR_PWM_LMAX;
    databuf[7] = PMIC_SAFETY_ERR_PWM_LMIN;
    databuf[6] = PMIC_SAFETY_ERR_PWM_HMAX;
    databuf[5] = PMIC_SAFETY_ERR_PWM_HMIN;
    databuf[4] = (PMIC_DEV_CFG_2 & 0xF0) | ((PMIC_DEV_CFG_2 & 0x02) << 1) | ((PMIC_DEV_CFG_1 & 0xC0) >> 6);
    databuf[3] = ((PMIC_DEV_CFG_1 & 0x3E) << 2) | (PMIC_SAFETY_ERR_CFG_2 & 0x07);
    databuf[2] = ((PMIC_DEV_CFG_3 & 0x0F) << 4) | ((PMIC_SAFETY_CHECK_CTRL & 0x04) << 1) |
        ((PMIC_SENS_CTRL & 0x40) >> 4) | ((PMIC_SENS_CTRL & 0x18) >> 3);
    databuf[1] = ((PMIC_SENS_CTRL & 0x04) << 5) | ((PMIC_DEV_CFG_2 & 0x01) << 6);
    databuf[0] = 0;

	crc = TPS653832A_CalcCRC8(databuf, 16);

	(void)TPS653832A_SendAndReceive(WR_SAFETY_CFG_CRC, crc);
	(void)TPS653832A_SendAndReceive(WR_SAFETY_CHECK_CTRL, (0x80 | PMIC_SAFETY_CHECK_CTRL));

}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static uint8 TPS653832A_CrcCheck(TPS653852A_RxDataType Rxdata)
{
	uint8 ret = 0;
	uint8 databuf[2] = {0,};
	uint8 crc = 0;

	databuf[0] = Rxdata.bits.stat;
	databuf[1] = Rxdata.bits.r;

	crc = (TPS653832A_CalcCRC8(databuf, 2) & 0x0F);

	if(crc == Rxdata.bits.crc)
	{
		ret = 0;
	}
	else
	{
		ret = 1;
	}

	return ret;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static TPS653852A_RxDataType TPS653832A_SendAndReceive(uint8 cmd, uint8 data)
{
	TPS653852A_TxDataType txdata = {0,};
	TPS653852A_RxDataType rxdata = {0,};
	uint8 databuf[2] = {0,};
	uint8 crc = 0;
	uint8 errorflag = 0;
	uint16 timeoutcnt = 0;

	txdata.bits.cmd = cmd;
	txdata.bits.data = data;
	databuf[0] = cmd;
	databuf[1] = data;

	crc = TPS653832A_CalcCRC8(databuf, 2) & 0x0F;

	txdata.bits.crc = crc;

	TPS653832A_SpiTxData = txdata.dword;

	(void)Spi_WriteIB(TPS653852A_SPI_CHANNEL, (uint8 *) &TPS653832A_SpiTxData);
	(void)Spi_SyncTransmit(TPS653852A_SPI_CHANNEL);
    while(Spi_GetSequenceResult(TPS653852A_SPI_CHANNEL) != SPI_SEQ_OK)
    {
      /* Wait till write is finished
       * add timeout count */
    	timeoutcnt ++;
    	if(timeoutcnt > TPS653852A_SPI_TIMEOUT_VALUE)
    	{
    		errorflag = 1;
    		break;
    	}
    }

    (void)Spi_ReadIB(TPS653852A_SPI_CHANNEL, (uint8 *)&TPS653832A_SpiRxData);

    if(errorflag > 0)
    {
    	TPS653832A_SpiRxData = 0xFFFFFFFF;
    }

	rxdata.dword = TPS653832A_SpiRxData;

	return rxdata;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static uint8 TPS653832A_CalcCRC8(uint8 *buf, uint8 len)
{
    uint8 i = 0;
    uint8 index = 0;
    uint8 crc = 0;

    crc = 0xFF;
    /* Standard CRC-8 polynomial ,X8 + X2 + X1 + 1.,is used to calculate the
     * checksum value based on the command and data which the MCU transmits
     * to the TPS653850-Q1 device.
     */
    for(index = 0; index < len; index ++)
    {
    	crc ^= buf[index];
		for (i = 0 ; i< 8 ; i++)
		{
            if (crc & 0x80)
            {
            	crc = (uint8)(((uint8)(crc << 1)) ^ 7);
            }
            else
            {
            	crc <<= 1;
            }
		}
    }
    /* Return the spi MCRC value */
    return crc;
}

/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void CDD_TPS653832A_PowerDown(void)
{
	TPS653832A_ShutDownReqFlag = TRUE;
}

/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS : CAN Wakeup 0, IGN Wakeup 1, Error 0xFF
* Limitations:
****************************************************************/
uint8 GetWakeUpSource(void)
{
    TPS653852A_RxDataType rxdata = {0,};
	rxdata = TPS653832A_SendAndReceive(RD_DEV_STAT, 0xFF);
	if(TPS653832A_CrcCheck(rxdata) != 0)
	{
		return 0xFF;
	}
    return (rxdata.bits.r & 0x01);  //if IGN Wakeup, else CAN Wakeup
}