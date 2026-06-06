/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Name: 
 * Description:
 * Version: 1.0
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : Isolar_Project
 * Component: /SwComponentTypes/CDD_TCAN1145
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 12.0.1
 * Author: tiand
 * Date : ��һ 4�� 17 14:35:41 2023
 ****************************************************************************/


/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :TCAN1145_MainFunction) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
#include "CDD_TCAN1145.h"
//#include "CDD_TCAN1145_Cfg.h"
#include "Spi.h"
#include "common.h"
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :TCAN1145_MainFunction) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :TCAN1145_MainFunction) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
#if 0
static uint16 TCAN1145_State = 0;
#endif

static uint16 TCAN1145_SpiRxdata1 = 0;

static uint16 TCAN1145_SpiTxdata1 = 0;

static uint16 TCAN1145_SpiRxdata2 = 0;

static uint16 TCAN1145_SpiTxdata2 = 0;

TCAN1145_RxDataType Tian_CANDebug[6] = {0,};


//static TCAN1145_RxDataType TCAN1145_SendAndReceive1(uint8 addr, uint8 cmd, uint8 data);
//
//static TCAN1145_RxDataType TCAN1145_SendAndReceive2(uint8 addr, uint8 cmd, uint8 data);
static void TCAN1145_ConfigConfirm1(void);
static void TCAN1145_ConfigConfirm2(void);
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
//static TCAN1145_RxDataType TCAN1145_SendAndReceive1(uint8 addr, uint8 cmd, uint8 data)
TCAN1145_RxDataType TCAN1145_SendAndReceive1(uint8 addr, uint8 cmd, uint8 data)
{
	TCAN1145_TxDataType txdata = {0,};
	TCAN1145_RxDataType rxdata = {0,};
    uint8 errorflag = 0;
	uint16 timeoutcnt = 0;

	txdata.bits.DATA_WRTIE = data;
	txdata.bits.RW = cmd;
	txdata.bits.ADDRESS = addr & 0x7Fu;

	TCAN1145_SpiTxdata1 = txdata.data;

	(void)Spi_WriteIB(TCAN1145_SPI_CHANNEL1, (uint8 *) &TCAN1145_SpiTxdata1);
	(void)Spi_SyncTransmit(TCAN1145_SPI_CHANNEL1);
    while(Spi_GetSequenceResult(TCAN1145_SPI_CHANNEL1) != SPI_SEQ_OK)
    {
      /* Wait till write is finished
       * add timeout count */
    	timeoutcnt ++;
    	if(timeoutcnt > TCAN1145_SPI_TIMEOUT_VALUE)
    	{
    		errorflag = 1;
    		break;
    	}
    }

    (void)Spi_ReadIB(TCAN1145_SPI_CHANNEL1, (uint8 *)&TCAN1145_SpiRxdata1);

    if(errorflag > 0)
    {
    	TCAN1145_SpiRxdata1 = 0xFFFF;
    }

    rxdata.data = TCAN1145_SpiRxdata1;

	return rxdata;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
//static TCAN1145_RxDataType TCAN1145_SendAndReceive2(uint8 addr, uint8 cmd, uint8 data)
TCAN1145_RxDataType TCAN1145_SendAndReceive2(uint8 addr, uint8 cmd, uint8 data)
{
	TCAN1145_TxDataType txdata = {0,};
	TCAN1145_RxDataType rxdata = {0,};
    uint8 errorflag = 0;
	uint16 timeoutcnt = 0;

	txdata.bits.DATA_WRTIE = data;
	txdata.bits.RW = cmd;
	txdata.bits.ADDRESS = addr & 0x7Fu;

	TCAN1145_SpiTxdata2 = txdata.data;

	(void)Spi_WriteIB(TCAN1145_SPI_CHANNEL2, (uint8 *) &TCAN1145_SpiTxdata2);
	(void)Spi_SyncTransmit(TCAN1145_SPI_CHANNEL2);
    while(Spi_GetSequenceResult(TCAN1145_SPI_CHANNEL2) != SPI_SEQ_OK)
    {
      /* Wait till write is finished
       * add timeout count */
    	timeoutcnt ++;
    	if(timeoutcnt > TCAN1145_SPI_TIMEOUT_VALUE)
    	{
    		errorflag = 1;
    		break;
    	}
    }

    (void)Spi_ReadIB(TCAN1145_SPI_CHANNEL2, (uint8 *)&TCAN1145_SpiRxdata2);

    if(errorflag > 0)
    {
    	TCAN1145_SpiRxdata2 = 0xFFFF;
    }

    rxdata.data = TCAN1145_SpiRxdata2;

	return rxdata;
}
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define CDD_TCAN1145_START_SEC_CODE
#if 0
extern volatile uint8 Fv_RWS_TempSleepFlag;
#endif
FUNC (void, CDD_TCAN1145_CODE) TCAN1145_MainFunction/* return value & FctID */
(
		void
)
{

	boolean shutdownpending = 0;
	uint8 faultinfo = 0;

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :TCAN1145_MainFunction) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	TCAN1145_RxDataType rxdata1 = {0,};
	TCAN1145_RxDataType rxdata2 = {0,};

	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
#if 0
	/* to do */
	Std_ReturnType retValue = RTE_E_OK;
#endif

	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :TCAN1145_MainFunction) ENABLED START */
	/* Start of user code - Do not remove this comment */
 #if 1   
	TCAN1145_ConfigConfirm1();
	TCAN1145_ConfigConfirm2();

	Tian_CANDebug[0] = TCAN1145_SendAndReceive1(TCAN1145_INT_1, TCAN1145_R_CMD, 0);
	Tian_CANDebug[1] = TCAN1145_SendAndReceive1(TCAN1145_INT_2, TCAN1145_R_CMD, 0);
	Tian_CANDebug[2] = TCAN1145_SendAndReceive1(TCAN1145_INT_3, TCAN1145_R_CMD, 0);

	Tian_CANDebug[3] = TCAN1145_SendAndReceive2(TCAN1145_INT_1, TCAN1145_R_CMD, 0);
	Tian_CANDebug[4] = TCAN1145_SendAndReceive2(TCAN1145_INT_2, TCAN1145_R_CMD, 0);
	Tian_CANDebug[5] = TCAN1145_SendAndReceive2(TCAN1145_INT_3, TCAN1145_R_CMD, 0);

//	(void)TCAN1145_SendAndReceive(TCAN1145_INT_1, TCAN1145_W_CMD, 0xFF);

	rxdata1 = TCAN1145_SendAndReceive1(TCAN1145_MODE_CNTRL, TCAN1145_R_CMD, 0x00);

	if((rxdata1.bits.DATA_READ & 0x0F) == 4)
	{
		(void)TCAN1145_SendAndReceive1(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x87);
		Fv_TCAN1145Sleep = 0;
	}

	rxdata2 = TCAN1145_SendAndReceive2(TCAN1145_MODE_CNTRL, TCAN1145_R_CMD, 0x00);

	if((rxdata2.bits.DATA_READ & 0x0F) == 4)
	{
		(void)TCAN1145_SendAndReceive2(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x87);
		Fv_TCAN1145Sleep = 0;
	}

	if((Fv_EXT_NMState == 0) && (Fv_SysDownCloseFlag > 0))
	{
//		(void)TCAN1145_SendAndReceive1(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x81);
//
//		(void)TCAN1145_SendAndReceive2(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x81);
        Fv_TCAN1145Sleep = 1;
	}
    else
    {
        Fv_TCAN1145Sleep = 0;
    }
#else

	TCAN1145_ConfigConfirm();

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_READ, 0x00);

	if((rxdata.bits.DATA_READ & 0x0F) == 4)
	{
		(void)TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_WRITE, 0x07);
		Fv_TCAN1145Sleep = 0;
	}
	else if((rxdata.bits.DATA_READ & 0x0F) == 1)
	{
		Fv_TCAN1145Sleep = 1;
	}
	else
	{
		Fv_TCAN1145Sleep = 0;
	}
	if(Fv_TPS653852GoToSleep > 0)
	{
		(void)TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_WRITE, 0x01);
	}
#endif   
}
#define CDD_TCAN1145_STOP_SEC_CODE  

/*PROTECTED REGION ID(FileHeaderUserDefinedFunctions :CDD_TCAN1145) ENABLED START */
/* Start of user defined functions  - Do not remove this comment */
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void TCAN1145_Init1(void)
{
#if 1
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID1);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID2);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID3);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID4);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK1);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK2);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK3);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK4);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK_DLC, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK_DLC);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_0, TCAN1145_W_CMD, TCan1145_Cfg_DATA_0);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_1, TCAN1145_W_CMD, TCan1145_Cfg_DATA_1);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_2, TCAN1145_W_CMD, TCan1145_Cfg_DATA_2);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_3, TCAN1145_W_CMD, TCan1145_Cfg_DATA_3);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_4, TCAN1145_W_CMD, TCan1145_Cfg_DATA_4);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_5, TCAN1145_W_CMD, TCan1145_Cfg_DATA_5);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_6, TCAN1145_W_CMD, TCan1145_Cfg_DATA_6);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_7, TCAN1145_W_CMD, TCan1145_Cfg_DATA_7);
    (void)TCAN1145_SendAndReceive1(TCAN1145_DEVICE_CONFIG1, TCAN1145_W_CMD, TCan1145_Cfg_DEVICE_CONFIG1);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SWE_DIS, TCAN1145_W_CMD, TCan1145_Cfg_SWE_DIS);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_1, TCAN1145_W_CMD, TCan1145_Cfg_SW_CONFIG_1);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_4, TCAN1145_W_CMD, 0x80);
    (void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_RSVD_7, TCAN1145_W_CMD, 0x80);
    (void)TCAN1145_SendAndReceive1(TCAN1145_INT_ENABLE_3, TCAN1145_W_CMD, 0xA0);

    (void)TCAN1145_SendAndReceive1(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x87);
    (void)TCAN1145_SendAndReceive1(TCAN1145_INT_1, TCAN1145_W_CMD, 0xFF);
    (void)TCAN1145_SendAndReceive1(TCAN1145_INT_2, TCAN1145_W_CMD, 0xFF);
    (void)TCAN1145_SendAndReceive1(TCAN1145_INT_3, TCAN1145_W_CMD, 0xFF);
    (void)TCAN1145_SendAndReceive1(TCAN1145_INT_GLOBAL, TCAN1145_R_CMD, 0);
#else
	TCAN1145_RxDataType rxdata = {0,};
	uint8 spi_err = 0;
	uint8 ret = 0;
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_Scratch_Pad_SPI, TCAN1145_SPI_CMD_READ, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MAJOR, TCAN1145_SPI_CMD_READ, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MINOR, TCAN1145_SPI_CMD_READ, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT1, TCAN1145_SPI_CMD_WRITE, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT2, TCAN1145_SPI_CMD_WRITE, 0x00);
    /*ID*/
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID1, TCAN1145_SPI_CMD_WRITE, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID2, TCAN1145_SPI_CMD_WRITE, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID3, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID3, TCAN1145_SPI_CMD_WRITE, 0x15);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID4, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID4, TCAN1145_SPI_CMD_WRITE, 0x15);	
	/*ID Mask*/
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK1, TCAN1145_SPI_CMD_WRITE, 0x03);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK2, TCAN1145_SPI_CMD_WRITE, 0xFF);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK3, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK3, TCAN1145_SPI_CMD_WRITE, 0xFF);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK4, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK4, TCAN1145_SPI_CMD_WRITE, 0xFF);	
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK_DLC, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK_DLC, TCAN1145_SPI_CMD_WRITE, 0xF1);	
	/*SW Configure*/
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_1, TCAN1145_SPI_CMD_WRITE, 0x50);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_2, TCAN1145_SPI_CMD_WRITE, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_3, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_3, TCAN1145_SPI_CMD_WRITE, 0xFF);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_4, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_4, TCAN1145_SPI_CMD_WRITE, 0x80);	

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_READ, 0x00);
	//rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_WRITE, 0x01);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_WRITE, 0x07);

#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void TCAN1145_Init2(void)
{
#if 1
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID1);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID2);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID3);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID4);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK1);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK2);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK3);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK4);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK_DLC, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK_DLC);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_0, TCAN1145_W_CMD, TCan1145_Cfg_DATA_0);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_1, TCAN1145_W_CMD, TCan1145_Cfg_DATA_1);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_2, TCAN1145_W_CMD, TCan1145_Cfg_DATA_2);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_3, TCAN1145_W_CMD, TCan1145_Cfg_DATA_3);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_4, TCAN1145_W_CMD, TCan1145_Cfg_DATA_4);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_5, TCAN1145_W_CMD, TCan1145_Cfg_DATA_5);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_6, TCAN1145_W_CMD, TCan1145_Cfg_DATA_6);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_7, TCAN1145_W_CMD, TCan1145_Cfg_DATA_7);
    (void)TCAN1145_SendAndReceive2(TCAN1145_DEVICE_CONFIG1, TCAN1145_W_CMD, TCan1145_Cfg_DEVICE_CONFIG1);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SWE_DIS, TCAN1145_W_CMD, TCan1145_Cfg_SWE_DIS);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_1, TCAN1145_W_CMD, TCan1145_Cfg_SW_CONFIG_1);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_4, TCAN1145_W_CMD, 0x80);
    (void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_RSVD_7, TCAN1145_W_CMD, 0x80);
    (void)TCAN1145_SendAndReceive2(TCAN1145_INT_ENABLE_3, TCAN1145_W_CMD, 0xA0);

    (void)TCAN1145_SendAndReceive2(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x87);
    (void)TCAN1145_SendAndReceive2(TCAN1145_INT_1, TCAN1145_W_CMD, 0xFF);
    (void)TCAN1145_SendAndReceive2(TCAN1145_INT_2, TCAN1145_W_CMD, 0xFF);
    (void)TCAN1145_SendAndReceive2(TCAN1145_INT_3, TCAN1145_W_CMD, 0xFF);
    (void)TCAN1145_SendAndReceive2(TCAN1145_INT_GLOBAL, TCAN1145_R_CMD, 0);
#else
	TCAN1145_RxDataType rxdata = {0,};
	uint8 spi_err = 0;
	uint8 ret = 0;
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_Scratch_Pad_SPI, TCAN1145_SPI_CMD_READ, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MAJOR, TCAN1145_SPI_CMD_READ, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MINOR, TCAN1145_SPI_CMD_READ, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT1, TCAN1145_SPI_CMD_WRITE, 0x00);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_INT2, TCAN1145_SPI_CMD_WRITE, 0x00);
    /*ID*/
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID1, TCAN1145_SPI_CMD_WRITE, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID2, TCAN1145_SPI_CMD_WRITE, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID3, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID3, TCAN1145_SPI_CMD_WRITE, 0x15);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID4, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID4, TCAN1145_SPI_CMD_WRITE, 0x15);
	/*ID Mask*/
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK1, TCAN1145_SPI_CMD_WRITE, 0x03);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK2, TCAN1145_SPI_CMD_WRITE, 0xFF);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK3, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK3, TCAN1145_SPI_CMD_WRITE, 0xFF);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK4, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK4, TCAN1145_SPI_CMD_WRITE, 0xFF);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK_DLC, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_ID_MASK_DLC, TCAN1145_SPI_CMD_WRITE, 0xF1);
	/*SW Configure*/
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_1, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_1, TCAN1145_SPI_CMD_WRITE, 0x50);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_2, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_2, TCAN1145_SPI_CMD_WRITE, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_3, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_3, TCAN1145_SPI_CMD_WRITE, 0xFF);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_4, TCAN1145_SPI_CMD_READ, 0x00);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_SW_CONFIG_4, TCAN1145_SPI_CMD_WRITE, 0x80);

	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_READ, 0x00);
	//rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_WRITE, 0x01);
	rxdata = TCAN1145_SendAndReceive(TCAN1145_SPI_ADDR_MODE_CNTRL, TCAN1145_SPI_CMD_WRITE, 0x07);

#endif
}

/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TCAN1145_ConfigConfirm1(void)
{
    #if 1
    static uint8 state = 0;
    TCAN1145_RxDataType rxdata = {0,};
    uint8 recofig = 0;

    switch(state)
    {
        case 0:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID1)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID1);
                recofig = 1;
            }
            state ++;
            break;
        case 1:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID2, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID2)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID2);
                recofig = 1;
            }
            state ++;
            break;
        case 2:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID3, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID3)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID3);
                recofig = 1;
            }
            state ++;
            break;
        case 3:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID4, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID4)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID4);
                recofig = 1;
            }
            state ++;
            break;
        case 4:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK1)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK1);
                recofig = 1;
            }
            state ++;
            break;
        case 5:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK2, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK2)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK2);
                recofig = 1;
            }
            state ++;
            break;
        case 6:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK3, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK3)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK3);
                recofig = 1;
            }
            state ++;
            break;
        case 7:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK4, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK4)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK4);
                recofig = 1;
            }
            state ++;
            break;
        case 8:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK_DLC, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK_DLC)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_ID_MASK_DLC, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK_DLC);
                recofig = 1;
            }
            state ++;
            break;
        case 9:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_0, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_0)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_0, TCAN1145_W_CMD, TCan1145_Cfg_DATA_0);
                recofig = 1;
            }
            state ++;
            break;
        case 10:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_1)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_1, TCAN1145_W_CMD, TCan1145_Cfg_DATA_1);
                recofig = 1;
            }
            state ++;
            break;
        case 11:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_2, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_2)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_2, TCAN1145_W_CMD, TCan1145_Cfg_DATA_2);
                recofig = 1;
            }
            state ++;
            break;
        case 12:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_3, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_3)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_3, TCAN1145_W_CMD, TCan1145_Cfg_DATA_3);
                recofig = 1;
            }
            state ++;
            break;
        case 13:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_4, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_4)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_4, TCAN1145_W_CMD, TCan1145_Cfg_DATA_4);
                recofig = 1;
            }
            state ++;
            break;
        case 14:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_5, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_5)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_5, TCAN1145_W_CMD, TCan1145_Cfg_DATA_5);
                recofig = 1;
            }
            state ++;
            break;
        case 15:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_6, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_6)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_6, TCAN1145_W_CMD, TCan1145_Cfg_DATA_6);
                recofig = 1;
            }
            state ++;
            break;
        case 16:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DATA_7, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_7)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DATA_7, TCAN1145_W_CMD, TCan1145_Cfg_DATA_7);
                recofig = 1;
            }
            state ++;
            break;
        case 17:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_DEVICE_CONFIG1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DEVICE_CONFIG1)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_DEVICE_CONFIG1, TCAN1145_W_CMD, TCan1145_Cfg_DEVICE_CONFIG1);
                recofig = 1;
            }
            state ++;
            break;
        case 18:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SWE_DIS, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SWE_DIS)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SWE_DIS, TCAN1145_W_CMD, TCan1145_Cfg_SWE_DIS);
                recofig = 1;
            }
            state ++;
            break;
        case 19:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_CONFIG_1)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_1, TCAN1145_W_CMD, TCan1145_Cfg_SW_CONFIG_1);
                recofig = 1;
            }
            state ++;
            break;
        case 20:
            rxdata = TCAN1145_SendAndReceive1(TCAN1145_INT_1, TCAN1145_R_CMD, 0);
            if ((rxdata.bits.DATA_READ & 0xBF) != 0)
            {
                (void)TCAN1145_SendAndReceive1(TCAN1145_INT_1, TCAN1145_W_CMD, 0xBF);
            }
        default:
            state = 0;
            break;
    }

    if(recofig > 0)
    {
        (void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_4, TCAN1145_W_CMD, 0x80);
        (void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_RSVD_7, TCAN1145_W_CMD, 0x80);
    }
    else
    {
    	rxdata = TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_4, TCAN1145_R_CMD, 0);
		if(rxdata.bits.DATA_READ & 0x80 != 0x80)
		{
			(void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_4, TCAN1145_W_CMD, TCan1145_Cfg_SW_CONFIG_4);
			(void)TCAN1145_SendAndReceive1(TCAN1145_SW_CONFIG_RSVD_7, TCAN1145_W_CMD, 0x80);
		}
    }
    #endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static void TCAN1145_ConfigConfirm2(void)
{
    #if 1
    static uint8 state = 0;
    TCAN1145_RxDataType rxdata = {0,};
    uint8 recofig = 0;

    switch(state)
    {
        case 0:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID1)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID1);
                recofig = 1;
            }
            state ++;
            break;
        case 1:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID2, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID2)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID2);
                recofig = 1;
            }
            state ++;
            break;
        case 2:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID3, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID3)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID3);
                recofig = 1;
            }
            state ++;
            break;
        case 3:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID4, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID4)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID4);
                recofig = 1;
            }
            state ++;
            break;
        case 4:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK1)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK1, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK1);
                recofig = 1;
            }
            state ++;
            break;
        case 5:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK2, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK2)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK2, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK2);
                recofig = 1;
            }
            state ++;
            break;
        case 6:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK3, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK3)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK3, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK3);
                recofig = 1;
            }
            state ++;
            break;
        case 7:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK4, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK4)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK4, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK4);
                recofig = 1;
            }
            state ++;
            break;
        case 8:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK_DLC, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_ID_MASK_DLC)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_ID_MASK_DLC, TCAN1145_W_CMD, TCan1145_Cfg_SW_ID_MASK_DLC);
                recofig = 1;
            }
            state ++;
            break;
        case 9:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_0, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_0)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_0, TCAN1145_W_CMD, TCan1145_Cfg_DATA_0);
                recofig = 1;
            }
            state ++;
            break;
        case 10:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_1)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_1, TCAN1145_W_CMD, TCan1145_Cfg_DATA_1);
                recofig = 1;
            }
            state ++;
            break;
        case 11:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_2, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_2)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_2, TCAN1145_W_CMD, TCan1145_Cfg_DATA_2);
                recofig = 1;
            }
            state ++;
            break;
        case 12:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_3, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_3)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_3, TCAN1145_W_CMD, TCan1145_Cfg_DATA_3);
                recofig = 1;
            }
            state ++;
            break;
        case 13:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_4, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_4)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_4, TCAN1145_W_CMD, TCan1145_Cfg_DATA_4);
                recofig = 1;
            }
            state ++;
            break;
        case 14:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_5, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_5)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_5, TCAN1145_W_CMD, TCan1145_Cfg_DATA_5);
                recofig = 1;
            }
            state ++;
            break;
        case 15:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_6, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_6)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_6, TCAN1145_W_CMD, TCan1145_Cfg_DATA_6);
                recofig = 1;
            }
            state ++;
            break;
        case 16:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DATA_7, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DATA_7)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DATA_7, TCAN1145_W_CMD, TCan1145_Cfg_DATA_7);
                recofig = 1;
            }
            state ++;
            break;
        case 17:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_DEVICE_CONFIG1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_DEVICE_CONFIG1)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_DEVICE_CONFIG1, TCAN1145_W_CMD, TCan1145_Cfg_DEVICE_CONFIG1);
                recofig = 1;
            }
            state ++;
            break;
        case 18:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SWE_DIS, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SWE_DIS)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SWE_DIS, TCAN1145_W_CMD, TCan1145_Cfg_SWE_DIS);
                recofig = 1;
            }
            state ++;
            break;
        case 19:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_1, TCAN1145_R_CMD, 0);
            if(rxdata.bits.DATA_READ != TCan1145_Cfg_SW_CONFIG_1)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_1, TCAN1145_W_CMD, TCan1145_Cfg_SW_CONFIG_1);
                recofig = 1;
            }
            state ++;
            break;
        case 20:
            rxdata = TCAN1145_SendAndReceive2(TCAN1145_INT_1, TCAN1145_R_CMD, 0);
            if ((rxdata.bits.DATA_READ & 0xBF) != 0)
            {
                (void)TCAN1145_SendAndReceive2(TCAN1145_INT_1, TCAN1145_W_CMD, 0xBF);
            }
        default:
            state = 0;
            break;
    }

    if(recofig > 0)
    {
        (void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_4, TCAN1145_W_CMD, 0x80);
        (void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_RSVD_7, TCAN1145_W_CMD, 0x80);
    }
    else
    {
    	rxdata = TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_4, TCAN1145_R_CMD, 0);
		if(rxdata.bits.DATA_READ & 0x80 != 0x80)
		{
			(void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_4, TCAN1145_W_CMD, TCan1145_Cfg_SW_CONFIG_4);
			(void)TCAN1145_SendAndReceive2(TCAN1145_SW_CONFIG_RSVD_7, TCAN1145_W_CMD, 0x80);
		}
    }
    #endif
}

/****************************************************************
* FUNCTION :    TCAN1145_GetCANWakeupInterruptStatusTransceiver1
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
boolean TCAN1145_GetCANWakeupInterruptStatusTransceiver1(void)
{
    boolean retValue = FALSE;
    TCAN1145_RxDataType rxdata = {0,};

    rxdata = TCAN1145_SendAndReceive1(TCAN1145_INT_1, TCAN1145_R_CMD, 0);
    if((rxdata.bits.DATA_READ & 0x40) == 0x40)
    {
        retValue = TRUE;
        (void)TCAN1145_SendAndReceive1(TCAN1145_INT_1, TCAN1145_W_CMD, 0x40);
    }

    return retValue;
}

/****************************************************************
* FUNCTION :    TCAN1145_GetCANWakeupInterruptStatusTransceiver1
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
boolean TCAN1145_GetCANWakeupInterruptStatusTransceiver2(void)
{
    boolean retValue = FALSE;
    TCAN1145_RxDataType rxdata = {0,};

    rxdata = TCAN1145_SendAndReceive2(TCAN1145_INT_1, TCAN1145_R_CMD, 0);
    if((rxdata.bits.DATA_READ & 0x40) == 0x40)
    {
        retValue = TRUE;
        (void)TCAN1145_SendAndReceive2(TCAN1145_INT_1, TCAN1145_W_CMD, 0x40);
    }

    return retValue;
}
/* End of user defined functions - Do not remove this comment */
/*PROTECTED REGION END */

