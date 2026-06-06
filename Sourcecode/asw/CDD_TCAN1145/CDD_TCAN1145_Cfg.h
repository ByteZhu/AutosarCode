/*
 * CDD_TCAN1145_Cfg.h
 *
 *  Created on: 20230728
 *      Author: TXY
 */

#ifndef SOURCECODE_ASW_CDD_TCAN1145_CDD_TCAN1145_CFG_H_
#define SOURCECODE_ASW_CDD_TCAN1145_CDD_TCAN1145_CFG_H_

#include <Std_Types.h>
#include "Spi.h"
#include "Ifx_reg.h"

typedef union
{
	struct
	{
		uint16 DATA_WRTIE:8;
		uint16 RW:1;
		uint16 ADDRESS:7;
	}bits;
	uint16 data;
}TCAN1145_TxDataType;

typedef union
{
	struct
	{
		uint16 DATA_READ:8;
		uint16 INT_DATA:8;
	}bits;
	uint16 data;
}TCAN1145_RxDataType;



typedef union
{
	struct
	{
		uint16 bit0:1;
		uint16 bit1:1;
		uint16 bit2:1;
		uint16 bit3:1;
		uint16 bit4:1;
		uint16 bit5:1;
		uint16 bit6:1;
		uint16 bit7:1;
		uint16 bit8:1;
		uint16 bit9:1;
		uint16 bit10:1;
		uint16 bit11:1;
		uint16 bit12:1;
		uint16 bit13:1;
		uint16 bit14:1;
		uint16 bit15:1;
	}bits;
	uint16 data;
}TCAN1145_Uint16BitType;
#if 1
#define TCAN1145_DEVICE_ID_0             0x00u
#define TCAN1145_DEVICE_ID_1             0x01u
#define TCAN1145_DEVICE_ID_2             0x02u
#define TCAN1145_DEVICE_ID_3             0x03u
#define TCAN1145_DEVICE_ID_4             0x04u
#define TCAN1145_DEVICE_ID_5             0x05u
#define TCAN1145_DEVICE_ID_6             0x06u
#define TCAN1145_DEVICE_ID_7             0x07u
#define TCAN1145_REV_ID_MAJOR            0x08u
#define TCAN1145_REV_ID_MINOR            0x09u
#define TCAN1145_SPI_RSVD_0              0x0Au
#define TCAN1145_SPI_RSVD_1              0x0Bu
#define TCAN1145_SPI_RSVD_2              0x0Cu
#define TCAN1145_SPI_RSVD_3              0x0Du
#define TCAN1145_SPI_RSVD_4              0x0Eu
#define TCAN1145_Scratch_Pad_SPI         0x0Fu
#define TCAN1145_MODE_CNTRL              0x10u
#define TCAN1145_WAKE_PIN_CONFIG         0x11u
#define TCAN1145_PIN_CONFIG              0x12u
#define TCAN1145_WD_CONFIG_1             0x13u
#define TCAN1145_WD_CONFIG_2             0x14u
#define TCAN1145_WD_INPUT_TRIG           0x15u
#define TCAN1145_WD_RST_PULSE            0x16u
#define TCAN1145_FSM_CONFIG              0x17u
#define TCAN1145_FSM_CNTR                0x18u
#define TCAN1145_DEVICE_RST              0x19u
#define TCAN1145_DEVICE_CONFIG1          0x1Au
#define TCAN1145_DEVICE_CONFIG2          0x1Bu
#define TCAN1145_SWE_DIS                 0x1Cu
#define TCAN1145_SDO_CONFIG              0x29u
#define TCAN1145_WD_QA_CONFIG            0x2Du
#define TCAN1145_WD_QA_ANSWER            0x2Eu
#define TCAN1145_WD_QA_QUESTION          0x2Fu
#define TCAN1145_SW_ID1                  0x30u
#define TCAN1145_SW_ID2                  0x31u
#define TCAN1145_SW_ID3                  0x32u
#define TCAN1145_SW_ID4                  0x33u
#define TCAN1145_SW_ID_MASK1             0x34u
#define TCAN1145_SW_ID_MASK2             0x35u
#define TCAN1145_SW_ID_MASK3             0x36u
#define TCAN1145_SW_ID_MASK4             0x37u
#define TCAN1145_SW_ID_MASK_DLC          0x38u
#define TCAN1145_DATA_0                  0x39u
#define TCAN1145_DATA_1                  0x3Au
#define TCAN1145_DATA_2                  0x3Bu
#define TCAN1145_DATA_3                  0x3Cu
#define TCAN1145_DATA_4                  0x3Du
#define TCAN1145_DATA_5                  0x3Eu
#define TCAN1145_DATA_6                  0x3Fu
#define TCAN1145_DATA_7                  0x40u
#define TCAN1145_SW_RSVD_0               0x41u
#define TCAN1145_SW_RSVD_1               0x42u
#define TCAN1145_SW_RSVD_2               0x43u
#define TCAN1145_SW_CONFIG_1             0x44u
#define TCAN1145_SW_CONFIG_2             0x45u
#define TCAN1145_SW_CONFIG_3             0x46u
#define TCAN1145_SW_CONFIG_4             0x47u
#define TCAN1145_SW_CONFIG_RSVD_0        0x48u
#define TCAN1145_SW_CONFIG_RSVD_1        0x49u
#define TCAN1145_SW_CONFIG_RSVD_2        0x4Au
#define TCAN1145_SW_CONFIG_RSVD_3        0x4Bu
#define TCAN1145_SW_CONFIG_RSVD_4        0x4Cu
#define TCAN1145_SW_CONFIG_RSVD_5        0x4Du
#define TCAN1145_SW_CONFIG_RSVD_6        0x4Eu
#define TCAN1145_SW_CONFIG_RSVD_7        0x4Fu
#define TCAN1145_INT_GLOBAL              0x50u
#define TCAN1145_INT_1                   0x51u
#define TCAN1145_INT_2                   0x52u
#define TCAN1145_INT_3                   0x53u
#define TCAN1145_INT_CANBUS              0x54u
#define TCAN1145_INT_GLOBAL_ENABLE       0x55u
#define TCAN1145_INT_ENABLE_1            0x56u
#define TCAN1145_INT_ENABLE_2            0x57u
#define TCAN1145_INT_ENABLE_3            0x58u
#define TCAN1145_INT_ENABLE_CANBUS       0x59u

#define TCAN1145_W_CMD                   0x01u
#define TCAN1145_R_CMD                   0x00u
/* should use channel num in spi_cfg.h  */
#define TCAN1145_SPI_CHANNEL1		SpiConf_SpiSequence_SpiSequence_CAN1

#define TCAN1145_SPI_CHANNEL2		SpiConf_SpiSequence_SpiSequence_CAN2

#define TCAN1145_SPI_TIMEOUT_VALUE		2000

extern const uint8 TCan1145_Cfg_SW_ID1;
extern const uint8 TCan1145_Cfg_SW_ID2;
extern const uint8 TCan1145_Cfg_SW_ID3;
extern const uint8 TCan1145_Cfg_SW_ID4;
extern const uint8 TCan1145_Cfg_SW_ID_MASK1;
extern const uint8 TCan1145_Cfg_SW_ID_MASK2;
extern const uint8 TCan1145_Cfg_SW_ID_MASK3;
extern const uint8 TCan1145_Cfg_SW_ID_MASK4;
extern const uint8 TCan1145_Cfg_SW_ID_MASK_DLC;
extern const uint8 TCan1145_Cfg_DATA_0;
extern const uint8 TCan1145_Cfg_DATA_1;
extern const uint8 TCan1145_Cfg_DATA_2;
extern const uint8 TCan1145_Cfg_DATA_3;
extern const uint8 TCan1145_Cfg_DATA_4;
extern const uint8 TCan1145_Cfg_DATA_5;
extern const uint8 TCan1145_Cfg_DATA_6;
extern const uint8 TCan1145_Cfg_DATA_7;
extern const uint8 TCan1145_Cfg_DEVICE_CONFIG1;
extern const uint8 TCan1145_Cfg_SWE_DIS;
extern const uint8 TCan1145_Cfg_SW_CONFIG_1;
extern const uint8 TCan1145_Cfg_SW_CONFIG_4;

#else
#define TCAN1145_SPI_CMD_WRITE				1u
#define TCAN1145_SPI_CMD_READ				0u

#define TCAN1145_SPI_ADDR_MAJOR		0x08u
#define TCAN1145_SPI_ADDR_MINOR		0x09u
#define TCAN1145_SPI_ADDR_Scratch_Pad_SPI		0x0Fu
#define TCAN1145_SPI_ADDR_MODE_CNTRL		0x10u
#define TCAN1145_SPI_ADDR_SW_ID1    0x30u 
#define TCAN1145_SPI_ADDR_SW_ID2    0x31u 
#define TCAN1145_SPI_ADDR_SW_ID3    0x32u 
#define TCAN1145_SPI_ADDR_SW_ID4    0x33u 
#define TCAN1145_SPI_ADDR_SW_ID_MASK1    0x34u 
#define TCAN1145_SPI_ADDR_SW_ID_MASK2    0x35u 
#define TCAN1145_SPI_ADDR_SW_ID_MASK3    0x36u 
#define TCAN1145_SPI_ADDR_SW_ID_MASK4    0x37u 
#define TCAN1145_SPI_ADDR_SW_ID_MASK_DLC  0x38u 

#define TCAN1145_SPI_ADDR_SW_CONFIG_1   0x44u 
#define TCAN1145_SPI_ADDR_SW_CONFIG_2   0x45u 
#define TCAN1145_SPI_ADDR_SW_CONFIG_3   0x46u 
#define TCAN1145_SPI_ADDR_SW_CONFIG_4   0x47u 

#define TCAN1145_SPI_ADDR_MODE_INT1		0x51u
#define TCAN1145_SPI_ADDR_MODE_INT2		0x52u
/* should use channel num in spi_cfg.h  */
#define TCAN1145_SPI_CHANNEL		SpiConf_SpiSequence_SpiSequence_TCAN1145

#define TCAN1145_SPI_TIMEOUT_VALUE		2000
#endif
#endif /* SOURCECODE_ASW_CDD_TCAN1145_CDD_TCAN1145_CFG_H_ */
