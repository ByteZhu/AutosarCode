/* BEGIN_FILE_HDR
**************************************************************************
* NOTICE
* This software is the property of XiangBin Electric. Any information contained in this
* doc should not be reproduced, or used, or disclosed without the written authorization from
* XiangBin Electric.
**************************************************************************
* File Name: DRV32345.c
********************************************************************
* Project/Product: EPS
* Title: DRV3245妫板嫰鈹嶉懞顖滃妞瑰崬濮�
* Author: LHC
*********************************************************************
* Description:
*	濮濄倖鏋冩禒鍓佹暏娴滃骸鐣炬稊澶婃嫲鐎圭偟骞囩�电RV3245鏉╂稖顢戦幙宥勭稊閻ㄥ嫭甯撮崣锝忕礉娑撴槒顩︾�瑰本鍨欴RV3245閻ㄥ嫬鍨垫慨瀣閿涘矁鐦栭弬顓炲挤闁板秶鐤�
*
* (Requirements, pseudo code and etc.)
*********************************************************************
* Limitations:
* 	閺堫剚鏋冩禒鏈电矌闁倻鏁ゆ禍搴㈡儗鏉炵椿RV3245閼侯垳澧栭惃鍕付閸掕泛娅�
* (limitations)
*********************************************************************
*********************************************************************
* Revision History閿涳拷
*
* Version      Date         Author             Descriptions
* ----------    --------------    ------------   ----------------------------------------
* 1.0       		2024-05-22      	LHC            Original
*
********************************************************************
*END_FILE_HDR */
/******************************************************************/
/* file include */
/******************************************************************/
#include "DRV3245_Types.h"
#include "DRV3245_Cfg.h"
#include "DRV3245.h"
#include "common.h"
#include "Dio.h"
#include "Spi.h"

#define DRV3245_GetFaultState1         Dio_ReadChannel(DioConf_DioChannel_P21_0)
#define DRV3245_SetDRVOFF1(v)          Dio_WriteChannel(DioConf_DioChannel_P15_3, v)
#define DRV3245_EN(v)                 (fsPredriver_EnableStatus = v)

#define DRV3245_GetFaultState2         Dio_ReadChannel(DioConf_DioChannel_P21_2)
#define DRV3245_SetDRVOFF2(v)          Dio_WriteChannel(DioConf_DioChannel_P15_4, v)

/******************************************************************/
/* TYPE DEFINE */
/******************************************************************/
typedef union {
  uint32 data;
  struct
  {
    uint32 OTW : 1;//OverTemperatureWarning
    uint32 SPIERR : 1;
    uint32 BIST : 1;
    uint32 PVDD_OVFL : 1;//PVDD overvoltage flag warning

    uint32 PVDD_UVFL : 1;//PVDD undervoltage flag warning
    uint32 VDS_HA : 1;
    uint32 VDS_LA : 1;
    uint32 VDS_HB : 1;

    uint32 VDS_LB : 1;
    uint32 VDS_HC : 1;
    uint32 VDS_LC : 1;
    uint32 VGS : 1;

    uint32 PVDD_UVLO : 1;
    uint32 DVDD_OVLO : 1;
    uint32 AVDD_OVLO : 1;
    uint32 AVDD_UVLO : 1;

    uint32 SNS_OCP : 1;
    uint32 VCP_LSD_UVLO : 1;
    uint32 VCP_LSD_OVLO : 1;
    uint32 VCPH_UVLO : 1;

    uint32 VCPH_OVLO : 1;
    uint32 VCPH_OVLO_ABS : 1;
    uint32 STP_FAULT : 1;
    uint32 DEADT_FAULT : 1;

    uint32 INT_REG_FAULT : 1;
    uint32 CFG_CRC_FAULT : 1;
    uint32 CLK_MON_FAULT : 1;
    uint32 EE_CRC_FAULT : 1;

    uint32 DEV_MODE_FAULT : 1;
    uint32 rsv : 1;
  } bits;
} DRV3245_FaultInfoType;

#define DRV3245_CRC8_TABLESIZE 256U

/* DRV3245妞瑰崬濮╅梼鑸殿唽 */
#define DRV3245_STATE_INIT			      0x00u
#define DRV3245_STATE_Normal					0x01u
#define DRV3245_STATE_RESET						0x02u
#define DRV3245_STATE_FAULT						0xFFu

/******************************************************************/
/* macro function  */
/******************************************************************/
#define DRV3245_BooleanToByte(x) ((x) ? 1 : 0) 
/******************************************************************/
/* static variables */
/******************************************************************/
/* DRV3245妞瑰崬濮╅悩鑸碉拷锟� */
static uint8 DRV3245_State1 = 0;
static uint8 DRV3245_State2 = 0;
/* DRV3245闁矮淇婇柨娆掝嚖鐠佲剝鏆� */
static uint8 DRV3245_CommErrCnt1 = 0;
static uint8 DRV3245_CommErrCnt2 = 0;
/* DRV3245 EN娴ｈ儻鍏樺鑸垫鐠佲剝鏆� */
static uint8 DRV3245_EN_DelayCnt1 = 0;
static uint8 DRV3245_EN_DelayCnt2 = 0;
/* DRV3245 鐠囪鍟揅RC閺嶏繝鐛� */
static uint8 tx_crc8_1 = 0xFF;
static uint8 rx_crc8_1 = 0XFF;
static uint8 tx_crc8_2 = 0xFF;
static uint8 rx_crc8_2 = 0XFF;

static uint8 DRV3245_CrcDataArr1[2] = {0};
static uint8 DRV3245_CrcRxErr1 = 0;

static uint8 DRV3245_CrcDataArr2[2] = {0};
static uint8 DRV3245_CrcRxErr2 = 0;

static uint16 PreDriver_SpiTxdata1;
static uint16 PreDriver_SpiRxdata1;
static uint16 PreDriver_SpiTxdata2;
static uint16 PreDriver_SpiRxdata2;

static DRV3245_IC_STAT0Type DRV3245_Fault1_IC_STAT0 = {0};
static DRV3245_OV_VDS_FAULTType DRV3245_Fault1_OV_VDS = {0};
static DRV3245_IC_FAULTType DRV3245_Fault1_IC = {0};
static DRV3245_VGS_FAULTType DRV3245_Fault1_VGS = {0};
static DRV3245_IC_STAT1Type DRV3245_Fault1_IC_STAT1 = {0};
static DRV3245_IC_STAT2Type DRV3245_Fault1_IC_STAT2 = {0};

static DRV3245_IC_STAT0Type DRV3245_Fault2_IC_STAT0 = {0};
static DRV3245_OV_VDS_FAULTType DRV3245_Fault2_OV_VDS = {0};
static DRV3245_IC_FAULTType DRV3245_Fault2_IC = {0};
static DRV3245_VGS_FAULTType DRV3245_Fault2_VGS = {0};
static DRV3245_IC_STAT1Type DRV3245_Fault2_IC_STAT1 = {0};
static DRV3245_IC_STAT2Type DRV3245_Fault2_IC_STAT2 = {0};

volatile Bool SysTaskPreDriverCalPending1;
volatile Bool SysTaskPreDriverCalPending2;

static const uint8 DRV3245_CRC8_Tbl[((uint16)DRV3245_CRC8_TABLESIZE)] = {
/* 0-15 */    0x0, 0x2f, 0x5e, 0x71, 0xbc, 0x93, 0xe2, 0xcd, 0x57, 0x78, 0x9, 0x26, 0xeb, 0xc4, 0xb5, 0x9a,
/* 16-31 */   0xae, 0x81, 0xf0, 0xdf, 0x12, 0x3d, 0x4c, 0x63, 0xf9, 0xd6, 0xa7, 0x88, 0x45, 0x6a, 0x1b, 0x34,
/* 32-47 */   0x73, 0x5c, 0x2d, 0x2, 0xcf, 0xe0, 0x91, 0xbe, 0x24, 0xb, 0x7a, 0x55, 0x98, 0xb7, 0xc6, 0xe9,
/* 48-63 */   0xdd, 0xf2, 0x83, 0xac, 0x61, 0x4e, 0x3f, 0x10, 0x8a, 0xa5, 0xd4, 0xfb, 0x36, 0x19, 0x68, 0x47,
/* 64-79 */   0xe6, 0xc9, 0xb8, 0x97, 0x5a, 0x75, 0x4, 0x2b, 0xb1, 0x9e, 0xef, 0xc0, 0xd, 0x22, 0x53, 0x7c,
/* 80-95 */   0x48, 0x67, 0x16, 0x39, 0xf4, 0xdb, 0xaa, 0x85, 0x1f, 0x30, 0x41, 0x6e, 0xa3, 0x8c, 0xfd, 0xd2,
/* 96-111 */  0x95, 0xba, 0xcb, 0xe4, 0x29, 0x6, 0x77, 0x58, 0xc2, 0xed, 0x9c, 0xb3, 0x7e, 0x51, 0x20, 0xf,
/* 112-127 */ 0x3b, 0x14, 0x65, 0x4a, 0x87, 0xa8, 0xd9, 0xf6, 0x6c, 0x43, 0x32, 0x1d, 0xd0, 0xff, 0x8e, 0xa1,
/* 128-143 */ 0xe3, 0xcc, 0xbd, 0x92, 0x5f, 0x70, 0x1, 0x2e, 0xb4, 0x9b, 0xea, 0xc5, 0x8, 0x27, 0x56, 0x79,
/* 144-159 */ 0x4d, 0x62, 0x13, 0x3c, 0xf1, 0xde, 0xaf, 0x80, 0x1a, 0x35, 0x44, 0x6b, 0xa6, 0x89, 0xf8, 0xd7,
/* 160-175 */ 0x90, 0xbf, 0xce, 0xe1, 0x2c, 0x3, 0x72, 0x5d, 0xc7, 0xe8, 0x99, 0xb6, 0x7b, 0x54, 0x25, 0xa,
/* 176-191 */ 0x3e, 0x11, 0x60, 0x4f, 0x82, 0xad, 0xdc, 0xf3, 0x69, 0x46, 0x37, 0x18, 0xd5, 0xfa, 0x8b, 0xa4,
/* 192-207 */ 0x5, 0x2a, 0x5b, 0x74, 0xb9, 0x96, 0xe7, 0xc8, 0x52, 0x7d, 0xc, 0x23, 0xee, 0xc1, 0xb0, 0x9f,
/* 208-223 */ 0xab, 0x84, 0xf5, 0xda, 0x17, 0x38, 0x49, 0x66, 0xfc, 0xd3, 0xa2, 0x8d, 0x40, 0x6f, 0x1e, 0x31,
/* 224-239 */ 0x76, 0x59, 0x28, 0x7, 0xca, 0xe5, 0x94, 0xbb, 0x21, 0xe, 0x7f, 0x50, 0x9d, 0xb2, 0xc3, 0xec,
/* 240-256 */ 0xd8, 0xf7, 0x86, 0xa9, 0x64, 0x4b, 0x3a, 0x15, 0x8f, 0xa0, 0xd1, 0xfe, 0x33, 0x1c, 0x6d, 0x42,
};
/******************************************************************/
/* static funciton */
/******************************************************************/
/* DRV3245 Init 濡�崇础閹垮秳缍旈崙鑺ユ殶 */
static void DRV3245_Init1(void);

static void DRV3245_Init2(void);
/* DRV3245 reset 濡�崇础閹垮秳缍旈崙鑺ユ殶 */
static void DRV3245_ResetModeOperation1(void);

static void DRV3245_ResetModeOperation2(void);
/* DRV3245 normal 濡�崇础閹垮秳缍旈崙鑺ユ殶 */
static void DRV3245_NormalModeOperation1(void);

static void DRV3245_NormalModeOperation2(void);
/* DRV3245 Fault 濡�崇础閹垮秳缍旈崙鑺ユ殶 */
static void DRV3245_FaultInfoCollection1(void);

static void DRV3245_FaultInfoCollection2(void);
/* DRV3245 閸欐垿锟戒礁鎷伴幒銉︽暪閺佺増宓� */
static void DRV3245_SendAndReceive1(DRV3245_TxDataType *txdata, DRV3245_RxDataType *rxdata);

static void DRV3245_SendAndReceive2(DRV3245_TxDataType *txdata, DRV3245_RxDataType *rxdata);

void DRV3245_RegWrite1(uint8 addr, uint16 data);

void DRV3245_RegWrite2(uint8 addr, uint16 data);

static DRV3245_RxDataType DRV3245_RegRead1(uint8 addr, uint8 addr_extral);

static DRV3245_RxDataType DRV3245_RegRead2(uint8 addr, uint8 addr_extral);
/* DRV3245鐠佸墽鐤嗛柨娆掝嚖鐠佲剝鏆� */
static void DRV3245_ErrCountSet1(void);

static void DRV3245_ErrCountSet2(void);

static uint16 DRV3245_SpiComm1(uint16 txdata);

static uint16 DRV3245_SpiComm2(uint16 txdata);
/****************************************************************
 * FUNCTION :  DRV3245_MainFunction
 * DESCRIPTION : DRV3245娑撹鍤遍弫甯礉閻€劋绨径鍕倞DRV3245妞瑰崬濮╅崥鍕Ц閹線妫块惃鍕儲鏉烇拷
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	鐠囥儱鍤遍弫鏉跨安閸︺劌鐖剁憴锟�5ms娴犺濮熸稉顓＄殶閻拷
 ****************************************************************/
void DRV3245_MainFunction(void)
{
#if 1
  switch (DRV3245_State1)
  {
    case DRV3245_STATE_INIT:
      DRV3245_Init1();
      break;

    case DRV3245_STATE_Normal:
      DRV3245_NormalModeOperation1();
      break;

    case DRV3245_STATE_RESET:
      DRV3245_ResetModeOperation1();
      break;

  default:
    DRV3245_FaultInfoCollection1();
    break;
  }
#endif
#if 1
  switch (DRV3245_State2)
  {
    case DRV3245_STATE_INIT:
      DRV3245_Init2();
      break;

    case DRV3245_STATE_Normal:
      DRV3245_NormalModeOperation2();
      break;

    case DRV3245_STATE_RESET:
      DRV3245_ResetModeOperation2();
      break;
  
  default:
    DRV3245_FaultInfoCollection2();
    break;
  }
#endif
  SysTaskPreDriverCalPending = SysTaskPreDriverCalPending1 | SysTaskPreDriverCalPending2;
}

/****************************************************************
 * FUNCTION :  DRV3245_Init
 * DESCRIPTION : DRV3245閸掓繂顫愰崠鏍у毐閺侊拷
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	閸︺劏钂嬫禒璺哄灥婵瀵查梼鑸殿唽鏉╂稖顢戠拫鍐暏
 ****************************************************************/
void DRV3245_Init1(void)
{
  uint8 faultCluster = 0;
  DRV3245_RxDataType rxdata = {0};
  uint8 nFault = 0;
  if(DRV3245_EN_DelayCnt1 == 0)
  {
    DRV3245_EN(0);
    DRV3245_EN_DelayCnt1++;
    return ;
  }
  else if(DRV3245_EN_DelayCnt1 < 3)
  {
    if(fsPredriver_EnableStatus > 0)
    {
    	DRV3245_EN(1);
    	DRV3245_EN_DelayCnt1++;
    }
    return ;
  }
  else
  {
    nFault = DRV3245_GetFaultState1;

    if(nFault == 1)
    {
    DRV3245_RegWrite1(DRV3245_SPIWR_CRC,0x6900);
    DRV3245_RegRead1(DRV3245_SPIRD_CRC,DRV3245_SPIRD_CRC_EXTRAL);
    DRV3245_ClearAllFault1();
      rxdata = DRV3245_RegRead1(DRV3245_IC_STAT0,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x04E5U) > 0));
      DRV3245_Fault1_IC_STAT0.data = rxdata.data;

      rxdata = DRV3245_RegRead1(DRV3245_OV_VDS_FAULT,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E7U) > 0));
      DRV3245_Fault1_OV_VDS.data = rxdata.data;

      rxdata = DRV3245_RegRead1(DRV3245_IC_FAULT,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x05FFU) > 0));
      DRV3245_Fault1_IC.data = rxdata.data;

      rxdata = DRV3245_RegRead1(DRV3245_VGS_FAULT,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E0U) > 0));
      DRV3245_Fault1_VGS.data = rxdata.data;

      rxdata = DRV3245_RegRead1(DRV3245_IC_STAT1,DRV3245_IC_STAT1_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x001FU) > 0));
      DRV3245_Fault1_IC_STAT1.data = rxdata.data;

      DRV3245_RegWrite1(DRV3245_SPIWR_CRC,0x6900);

      rxdata = DRV3245_RegRead1(DRV3245_IC_STAT2,DRV3245_IC_STAT2_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x007FU) > 0));
      DRV3245_Fault1_IC_STAT2.data = rxdata.data;

      rxdata = DRV3245_RegRead1(DRV3245_IC_STAT0,DRV3245_NO_EXTRAL);

      DRV3245_RegRead1(DRV3245_SPIRD_CRC,DRV3245_SPIRD_CRC_EXTRAL);
      faultCluster |= DRV3245_CrcRxErr1;

      if (rxdata.bits.DATA_READ & 0x04)//BIST_STAT
      {
        DRV3245_State1 = DRV3245_STATE_RESET;
        DRV3245_ErrCountSet1();
      }
      else if(faultCluster == 0)
      {
        DRV3245_RegWrite1(DRV3245_HS_GATE_DRIVE_CTRL,DRV3245_HS_GATE_DRIVE_CTRLInit.data);
        DRV3245_RegWrite1(DRV3245_LS_GATE_DRIVE_CTRL,DRV3245_LS_GATE_DRIVE_CTRLInit.data);
        DRV3245_RegWrite1(DRV3245_GATE_DRIVE_CTRL,DRV3245_GATE_DRIVE_CTRLInit.data);
        DRV3245_RegWrite1(DRV3245_IC_OPERATION,DRV3245_IC_OPERATIONInit.data);
        DRV3245_RegWrite1(DRV3245_SHUNT_AMPLIDIER_CTRL,DRV3245_SHUNT_AMPLIDIER_CRTLInit.data);
        DRV3245_RegWrite1(DRV3245_IC_CTRL0,DRV3245_IC_CRTL0Init.data);
        DRV3245_RegWrite1(DRV3245_IC_CTRL1,DRV3245_IC_CRTL1Init.data);
        DRV3245_RegWrite1(DRV3245_PHC_CTRL,DRV3245_PHC_CRTLInit.data);
        DRV3245_RegWrite1(DRV3245_VOLTAGE_REGULATOR_CTRL,DRV3245_VOLTAGE_REGULATOR_CTRLInit.data);
        DRV3245_RegWrite1(DRV3245_VDS_SENSE_CTRL0,DRV3245_VDS_SENSE_CTRL0Init.data);
        DRV3245_RegWrite1(DRV3245_VDS_SENSE_CTRL1,DRV3245_VDS_SENSE_CTRL1Init.data);
        DRV3245_RegWrite1(DRV3245_VGS_CTRL1,DRV3245_VGS_CTRL1Init.data);

        DRV3245_RegWrite1(DRV3245_SPIWR_CRC,0x6900);

        if(DRV3245_GetFaultState1 > 0)
        {
          DRV3245_State1 = DRV3245_STATE_Normal;
        }
      }
      else
      {
        DRV3245_ErrCountSet1();
        DRV3245_ClearAllFault1();
      }
    }
    else
    {
      DRV3245_ErrCountSet1();
      DRV3245_ClearAllFault1();
      DRV3245_EN(0);
      DRV3245_EN_DelayCnt1 = 0;
      tx_crc8_1 = 0xFF;
      rx_crc8_1 = 0XFF;
    }
  }

}

void DRV3245_Init2(void)
{
  uint8 faultCluster = 0;
  DRV3245_RxDataType rxdata = {0};
  uint8 nFault = 0;
  if(DRV3245_EN_DelayCnt2 == 0)
  {
    DRV3245_EN(0);
    DRV3245_EN_DelayCnt2++;
    return ;
  }
  else if(DRV3245_EN_DelayCnt2 < 3)
  {
    if(fsPredriver_EnableStatus > 0)
    {
    	DRV3245_EN(1);
    	DRV3245_EN_DelayCnt2++;
    }
    return ;
  }
  else
  {
    nFault = DRV3245_GetFaultState2;

    if(nFault == 1)
    {
    DRV3245_RegWrite2(DRV3245_SPIWR_CRC,0x6900);
    DRV3245_RegRead2(DRV3245_SPIRD_CRC,DRV3245_SPIRD_CRC_EXTRAL);
    DRV3245_ClearAllFault2();
      rxdata = DRV3245_RegRead2(DRV3245_IC_STAT0,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x04E5U) > 0));
      DRV3245_Fault2_IC_STAT0.data = rxdata.data;

      rxdata = DRV3245_RegRead2(DRV3245_OV_VDS_FAULT,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E7U) > 0));
      DRV3245_Fault2_OV_VDS.data = rxdata.data;

      rxdata = DRV3245_RegRead2(DRV3245_IC_FAULT,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x05FFU) > 0));
      DRV3245_Fault2_IC.data = rxdata.data;

      rxdata = DRV3245_RegRead2(DRV3245_VGS_FAULT,DRV3245_NO_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E0U) > 0));
      DRV3245_Fault2_VGS.data = rxdata.data;

      rxdata = DRV3245_RegRead2(DRV3245_IC_STAT1,DRV3245_IC_STAT1_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x001FU) > 0));
      DRV3245_Fault2_IC_STAT1.data = rxdata.data;

      DRV3245_RegWrite2(DRV3245_SPIWR_CRC,0x6900);

      rxdata = DRV3245_RegRead2(DRV3245_IC_STAT2,DRV3245_IC_STAT2_EXTRAL);
      faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x007FU) > 0));
      DRV3245_Fault2_IC_STAT2.data = rxdata.data;

      rxdata = DRV3245_RegRead2(DRV3245_IC_STAT0,DRV3245_NO_EXTRAL);

      DRV3245_RegRead2(DRV3245_SPIRD_CRC,DRV3245_SPIRD_CRC_EXTRAL);
      faultCluster |= DRV3245_CrcRxErr2;

      if (rxdata.bits.DATA_READ & 0x04)//BIST_STAT
      {
        DRV3245_State2 = DRV3245_STATE_RESET;
        DRV3245_ErrCountSet2();
      }
      else if(faultCluster == 0)
      {
        DRV3245_RegWrite2(DRV3245_HS_GATE_DRIVE_CTRL,DRV3245_HS_GATE_DRIVE_CTRLInit.data);
        DRV3245_RegWrite2(DRV3245_LS_GATE_DRIVE_CTRL,DRV3245_LS_GATE_DRIVE_CTRLInit.data);
        DRV3245_RegWrite2(DRV3245_GATE_DRIVE_CTRL,DRV3245_GATE_DRIVE_CTRLInit.data);
        DRV3245_RegWrite2(DRV3245_IC_OPERATION,DRV3245_IC_OPERATIONInit.data);
        DRV3245_RegWrite2(DRV3245_SHUNT_AMPLIDIER_CTRL,DRV3245_SHUNT_AMPLIDIER_CRTLInit.data);
        DRV3245_RegWrite2(DRV3245_IC_CTRL0,DRV3245_IC_CRTL0Init.data);
        DRV3245_RegWrite2(DRV3245_IC_CTRL1,DRV3245_IC_CRTL1Init.data);
        DRV3245_RegWrite2(DRV3245_PHC_CTRL,DRV3245_PHC_CRTLInit.data);
        DRV3245_RegWrite2(DRV3245_VOLTAGE_REGULATOR_CTRL,DRV3245_VOLTAGE_REGULATOR_CTRLInit.data);
        DRV3245_RegWrite2(DRV3245_VDS_SENSE_CTRL0,DRV3245_VDS_SENSE_CTRL0Init.data);
        DRV3245_RegWrite2(DRV3245_VDS_SENSE_CTRL1,DRV3245_VDS_SENSE_CTRL1Init.data);
        DRV3245_RegWrite2(DRV3245_VGS_CTRL1,DRV3245_VGS_CTRL1Init.data);

        DRV3245_RegWrite2(DRV3245_SPIWR_CRC,0x6900);

        if(DRV3245_GetFaultState2 > 0)
        {
          DRV3245_State2 = DRV3245_STATE_Normal;
        }
      }
      else
      {
        DRV3245_ErrCountSet2();
        DRV3245_ClearAllFault2();
      }
    }
    else
    {
      DRV3245_ErrCountSet2();
      DRV3245_ClearAllFault2();
      DRV3245_EN(0);
      DRV3245_EN_DelayCnt2 = 0;
      tx_crc8_2 = 0xFF;
      rx_crc8_2 = 0XFF;
    }
  }

}
/****************************************************************
 * FUNCTION :  DRV3245_ResetModeOperation
 * DESCRIPTION : DRV3245 reset 濡�崇础婢跺嫮鎮婇崙鑺ユ殶
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	娴犲懘妾烘禍宥V3245_MainFunction鐠嬪啰鏁�
 ****************************************************************/
static void DRV3245_ResetModeOperation1(void)
{
  DRV3245_EN(0);//娴ｈ儻鍏橀懘姘娴ｏ拷
  DRV3245_EN_DelayCnt1 = 0;
  tx_crc8_1 = 0xFF;
  rx_crc8_1 = 0XFF;
  if(Fv_SysPower > MACRO_TP_BRIDGEWORK)
  {
    DRV3245_State1 = DRV3245_STATE_INIT;
  }
  else
  {

  }
}
static void DRV3245_ResetModeOperation2(void)
{
  DRV3245_EN(0);//娴ｈ儻鍏橀懘姘娴ｏ拷
  DRV3245_EN_DelayCnt2 = 0;
  tx_crc8_2 = 0xFF;
  rx_crc8_2 = 0XFF;
  if(Fv_SysPower > MACRO_TP_BRIDGEWORK)
  {
    DRV3245_State2 = DRV3245_STATE_INIT;
  }
  else
  {

  }
}
/****************************************************************
 * FUNCTION :  DRV3245_NormalModeOperation
 * DESCRIPTION : DRV3245 normal 濡�崇础閹垮秳缍旈崙鑺ユ殶
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	娴犲懘妾烘禍宥V3245_MainFunction鐠嬪啰鏁�
 ****************************************************************/
static void DRV3245_NormalModeOperation1(void)//todo 婢х偛濮炴担搴″竾婢跺嫮鎮婇敍灞剧壌閹诡喗藟閻㈤潧鍨介弬锟�
{
  static uint8 state = 0;
  static uint8 regLossCnt = 0;
  uint8 faultCluster = 0;
  DRV3245_IC_STAT0Type stat1 = {0};
  DRV3245_OV_VDS_FAULTType stat2 = {0};
  DRV3245_IC_FAULTType stat3 = {0};
  DRV3245_VGS_FAULTType stat4 = {0};
  DRV3245_IC_STAT1Type stat5 = {0};
  DRV3245_IC_STAT2Type stat6 = {0};
  DRV3245_RxDataType rxdata = {0};

    /* 妫板嫰鈹嶉幍鎾崇磻閺嶅洤绻旀稉铏规埂閺冭绱濇担鑳厴3245 */
  if((SysTaskPreDriverPending1 > 0))
  {
    DRV3245_BridgeOper1(1);
  }
  else
  {
    DRV3245_BridgeOper1(0);
  }

  faultCluster = !(DRV3245_GetFaultState1);

  rxdata = DRV3245_RegRead1(DRV3245_IC_STAT0,DRV3245_NO_EXTRAL);
  stat1.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x04E5U) > 0));

  rxdata = DRV3245_RegRead1(DRV3245_OV_VDS_FAULT,DRV3245_NO_EXTRAL);
  stat2.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E7U) > 0));

  rxdata = DRV3245_RegRead1(DRV3245_IC_FAULT,DRV3245_NO_EXTRAL);
  stat3.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x05FFU) > 0));

  rxdata = DRV3245_RegRead1(DRV3245_VGS_FAULT,DRV3245_NO_EXTRAL);
  stat4.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E0U) > 0));

  rxdata = DRV3245_RegRead1(DRV3245_IC_STAT1,DRV3245_IC_STAT1_EXTRAL);
  stat5.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x001FU) > 0));

  DRV3245_RegWrite1(DRV3245_SPIWR_CRC,0x6900);

  rxdata = DRV3245_RegRead1(DRV3245_IC_STAT2,DRV3245_IC_STAT2_EXTRAL);
  stat6.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x007FU) > 0));

  DRV3245_RegRead1(DRV3245_SPIRD_CRC,DRV3245_SPIRD_CRC_EXTRAL);
  faultCluster |= DRV3245_CrcRxErr1;

  if(faultCluster > 0)
  {
    DRV3245_ErrCountSet1();
    DRV3245_Fault1_IC_STAT0.data = stat1.data;
    DRV3245_Fault1_OV_VDS.data = stat2.data;
    DRV3245_Fault1_IC.data = stat3.data;
    DRV3245_Fault1_VGS.data = stat4.data;
    DRV3245_Fault1_IC_STAT1.data = stat5.data;
    DRV3245_Fault1_IC_STAT2.data = stat6.data;
    DRV3245_ClearAllFault1();

    SysTaskPreDriverCalPending1 = FALSE;
  }
  else
  {
    SysTaskPreDriverCalPending1 = TRUE;

    switch (state)
    {
    case 0:
      rxdata = DRV3245_RegRead1(DRV3245_HS_GATE_DRIVE_CTRL,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != DRV3245_HS_GATE_DRIVE_CTRLInit.data)
      {
        DRV3245_RegWrite1(DRV3245_HS_GATE_DRIVE_CTRL,DRV3245_HS_GATE_DRIVE_CTRLInit.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;
      
    case 1:
      rxdata = DRV3245_RegRead1(DRV3245_LS_GATE_DRIVE_CTRL,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != DRV3245_LS_GATE_DRIVE_CTRLInit.data)
      {
        DRV3245_RegWrite1(DRV3245_LS_GATE_DRIVE_CTRL,DRV3245_LS_GATE_DRIVE_CTRLInit.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 2:
      rxdata = DRV3245_RegRead1(DRV3245_GATE_DRIVE_CTRL,DRV3245_NO_EXTRAL);
      if((rxdata.bits.DATA_READ & 0x3FF) != (DRV3245_GATE_DRIVE_CTRLInit.data & 0x3FF))
      {
        DRV3245_RegWrite1(DRV3245_GATE_DRIVE_CTRL,DRV3245_GATE_DRIVE_CTRLInit.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 3:
      rxdata = DRV3245_RegRead1(DRV3245_IC_OPERATION,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_IC_OPERATIONInit.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_IC_OPERATION,DRV3245_IC_OPERATIONInit.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 4:
      rxdata = DRV3245_RegRead1(DRV3245_SHUNT_AMPLIDIER_CTRL,DRV3245_SHUNT_AMPLIDIER_CTRL_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_SHUNT_AMPLIDIER_CRTLInit.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_SHUNT_AMPLIDIER_CTRL,DRV3245_SHUNT_AMPLIDIER_CRTLInit.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 5:
      rxdata = DRV3245_RegRead1(DRV3245_IC_CTRL0,DRV3245_IC_CTRL0_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_IC_CRTL0Init.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_IC_CTRL0,DRV3245_IC_CRTL0Init.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 6:
      rxdata = DRV3245_RegRead1(DRV3245_IC_CTRL1,DRV3245_IC_CTRL1_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_IC_CRTL1Init.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_IC_CTRL1,DRV3245_IC_CRTL1Init.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 7:
      rxdata = DRV3245_RegRead1(DRV3245_PHC_CTRL,DRV3245_PHC_CTRL_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_PHC_CRTLInit.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_PHC_CTRL,DRV3245_PHC_CRTLInit.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 8:
      rxdata = DRV3245_RegRead1(DRV3245_VOLTAGE_REGULATOR_CTRL,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != DRV3245_VOLTAGE_REGULATOR_CTRLInit.data)
      {
        DRV3245_RegWrite1(DRV3245_VOLTAGE_REGULATOR_CTRL,DRV3245_VOLTAGE_REGULATOR_CTRLInit.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 9:
      rxdata = DRV3245_RegRead1(DRV3245_VDS_SENSE_CTRL0,DRV3245_VDS_SENSE_CTRL0_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_VDS_SENSE_CTRL0Init.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_VDS_SENSE_CTRL0,DRV3245_VDS_SENSE_CTRL0Init.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 10:
      rxdata = DRV3245_RegRead1(DRV3245_VDS_SENSE_CTRL1,DRV3245_VDS_SENSE_CTRL1_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_VDS_SENSE_CTRL1Init.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_VDS_SENSE_CTRL1,DRV3245_VDS_SENSE_CTRL1Init.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 11:
      rxdata = DRV3245_RegRead1(DRV3245_VGS_CTRL1,DRV3245_VGS_CTRL1_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_VGS_CTRL1Init.data & 0xFF))
      {
        DRV3245_RegWrite1(DRV3245_VGS_CTRL1,DRV3245_VGS_CTRL1Init.data);
        if(SysTaskPreDriverPending1 > 0)
        {
          regLossCnt++;
        }
      }
      state = 0;
      break;
    
    default:
      state = 0;
      break;
    }

    if(regLossCnt > DRV3245_WRONG_CONTENT_CNT)
    {
      regLossCnt = 0;
      DRV3245_ErrCountSet1();
    }
  }
}
static void DRV3245_NormalModeOperation2(void)//todo 婢х偛濮炴担搴″竾婢跺嫮鎮婇敍灞剧壌閹诡喗藟閻㈤潧鍨介弬锟�
{
  static uint8 state = 0;
  static uint8 regLossCnt = 0;
  uint8 faultCluster = 0;
  DRV3245_IC_STAT0Type stat1 = {0};
  DRV3245_OV_VDS_FAULTType stat2 = {0};
  DRV3245_IC_FAULTType stat3 = {0};
  DRV3245_VGS_FAULTType stat4 = {0};
  DRV3245_IC_STAT1Type stat5 = {0};
  DRV3245_IC_STAT2Type stat6 = {0};
  DRV3245_RxDataType rxdata = {0};

    /* 妫板嫰鈹嶉幍鎾崇磻閺嶅洤绻旀稉铏规埂閺冭绱濇担鑳厴3245 */
  if((SysTaskPreDriverPending2 > 0))
  {
    DRV3245_BridgeOper2(1);
  }
  else
  {
    DRV3245_BridgeOper2(0);
  }

  faultCluster = !(DRV3245_GetFaultState2);

  rxdata = DRV3245_RegRead2(DRV3245_IC_STAT0,DRV3245_NO_EXTRAL);
  stat1.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x04E5U) > 0));

  rxdata = DRV3245_RegRead2(DRV3245_OV_VDS_FAULT,DRV3245_NO_EXTRAL);
  stat2.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E7U) > 0));

  rxdata = DRV3245_RegRead2(DRV3245_IC_FAULT,DRV3245_NO_EXTRAL);
  stat3.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x05FFU) > 0));

  rxdata = DRV3245_RegRead2(DRV3245_VGS_FAULT,DRV3245_NO_EXTRAL);
  stat4.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x07E0U) > 0));

  rxdata = DRV3245_RegRead2(DRV3245_IC_STAT1,DRV3245_IC_STAT1_EXTRAL);
  stat5.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x001FU) > 0));

  DRV3245_RegWrite2(DRV3245_SPIWR_CRC,0x6900);

  rxdata = DRV3245_RegRead2(DRV3245_IC_STAT2,DRV3245_IC_STAT2_EXTRAL);
  stat6.data = rxdata.bits.DATA_READ;
  faultCluster |= DRV3245_BooleanToByte(((rxdata.bits.DATA_READ & 0x007FU) > 0));

  DRV3245_RegRead2(DRV3245_SPIRD_CRC,DRV3245_SPIRD_CRC_EXTRAL);
  faultCluster |= DRV3245_CrcRxErr2;

  if(faultCluster > 0)
  {
    DRV3245_ErrCountSet2();
    DRV3245_Fault2_IC_STAT0.data = stat1.data;
    DRV3245_Fault2_OV_VDS.data = stat2.data;
    DRV3245_Fault2_IC.data = stat3.data;
    DRV3245_Fault2_VGS.data = stat4.data;
    DRV3245_Fault2_IC_STAT1.data = stat5.data;
    DRV3245_Fault2_IC_STAT2.data = stat6.data;
    DRV3245_ClearAllFault2();

    SysTaskPreDriverCalPending2 = FALSE;
  }
  else
  {
    SysTaskPreDriverCalPending2 = TRUE;

    switch (state)
    {
    case 0:
      rxdata = DRV3245_RegRead2(DRV3245_HS_GATE_DRIVE_CTRL,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != DRV3245_HS_GATE_DRIVE_CTRLInit.data)
      {
        DRV3245_RegWrite2(DRV3245_HS_GATE_DRIVE_CTRL,DRV3245_HS_GATE_DRIVE_CTRLInit.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 1:
      rxdata = DRV3245_RegRead2(DRV3245_LS_GATE_DRIVE_CTRL,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != DRV3245_LS_GATE_DRIVE_CTRLInit.data)
      {
        DRV3245_RegWrite2(DRV3245_LS_GATE_DRIVE_CTRL,DRV3245_LS_GATE_DRIVE_CTRLInit.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 2:
      rxdata = DRV3245_RegRead2(DRV3245_GATE_DRIVE_CTRL,DRV3245_NO_EXTRAL);
      if((rxdata.bits.DATA_READ & 0x3FF) != (DRV3245_GATE_DRIVE_CTRLInit.data & 0x3FF))
      {
        DRV3245_RegWrite2(DRV3245_GATE_DRIVE_CTRL,DRV3245_GATE_DRIVE_CTRLInit.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 3:
      rxdata = DRV3245_RegRead2(DRV3245_IC_OPERATION,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_IC_OPERATIONInit.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_IC_OPERATION,DRV3245_IC_OPERATIONInit.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 4:
      rxdata = DRV3245_RegRead2(DRV3245_SHUNT_AMPLIDIER_CTRL,DRV3245_SHUNT_AMPLIDIER_CTRL_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_SHUNT_AMPLIDIER_CRTLInit.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_SHUNT_AMPLIDIER_CTRL,DRV3245_SHUNT_AMPLIDIER_CRTLInit.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 5:
      rxdata = DRV3245_RegRead2(DRV3245_IC_CTRL0,DRV3245_IC_CTRL0_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_IC_CRTL0Init.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_IC_CTRL0,DRV3245_IC_CRTL0Init.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 6:
      rxdata = DRV3245_RegRead2(DRV3245_IC_CTRL1,DRV3245_IC_CTRL1_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_IC_CRTL1Init.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_IC_CTRL1,DRV3245_IC_CRTL1Init.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 7:
      rxdata = DRV3245_RegRead2(DRV3245_PHC_CTRL,DRV3245_PHC_CTRL_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_PHC_CRTLInit.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_PHC_CTRL,DRV3245_PHC_CRTLInit.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 8:
      rxdata = DRV3245_RegRead2(DRV3245_VOLTAGE_REGULATOR_CTRL,DRV3245_NO_EXTRAL);
      if(rxdata.bits.DATA_READ != DRV3245_VOLTAGE_REGULATOR_CTRLInit.data)
      {
        DRV3245_RegWrite2(DRV3245_VOLTAGE_REGULATOR_CTRL,DRV3245_VOLTAGE_REGULATOR_CTRLInit.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 9:
      rxdata = DRV3245_RegRead2(DRV3245_VDS_SENSE_CTRL0,DRV3245_VDS_SENSE_CTRL0_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_VDS_SENSE_CTRL0Init.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_VDS_SENSE_CTRL0,DRV3245_VDS_SENSE_CTRL0Init.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 10:
      rxdata = DRV3245_RegRead2(DRV3245_VDS_SENSE_CTRL1,DRV3245_VDS_SENSE_CTRL1_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_VDS_SENSE_CTRL1Init.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_VDS_SENSE_CTRL1,DRV3245_VDS_SENSE_CTRL1Init.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state++;
      break;

    case 11:
      rxdata = DRV3245_RegRead2(DRV3245_VGS_CTRL1,DRV3245_VGS_CTRL1_EXTRAL);
      if(rxdata.bits.DATA_READ != (DRV3245_VGS_CTRL1Init.data & 0xFF))
      {
        DRV3245_RegWrite2(DRV3245_VGS_CTRL1,DRV3245_VGS_CTRL1Init.data);
        if(SysTaskPreDriverPending2 > 0)
        {
          regLossCnt++;
        }
      }
      state = 0;
      break;

    default:
      state = 0;
      break;
    }

    if(regLossCnt > DRV3245_WRONG_CONTENT_CNT)
    {
      regLossCnt = 0;
      DRV3245_ErrCountSet2();
    }
  }
}
/****************************************************************
 * FUNCTION :  DRV3245_FaultInfoCollection
 * DESCRIPTION : DRV3245 闁挎瑨顕ゆ穱鈩冧紖閺�鍫曟肠閸戣姤鏆�
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	娴犲懘妾烘禍宥V3245_MainFunction鐠嬪啰鏁�
 ****************************************************************/
DRV3245_FaultInfoType faultinfo = {0};
static void DRV3245_FaultInfoCollection1(void)
{
  static uint8 readflag = 0;
  DRV3245_IC_STAT0Type stat1 = {0};
  DRV3245_OV_VDS_FAULTType stat2 = {0};
  DRV3245_IC_FAULTType stat3 = {0};
  DRV3245_VGS_FAULTType stat4 = {0};
  DRV3245_IC_STAT1Type stat5 = {0};
  DRV3245_IC_STAT2Type stat6 = {0};
  DRV3245_RxDataType rxdata = {0};


  DRV3245_State1 = DRV3245_STATE_FAULT;

  if(0 == readflag)
  {
    /* 闁挎瑨顕ら悩鑸碉拷浣稿彠闂傤參顣╂す鍙樺▏閼筹拷 *///todo 閸忚櫕藟妞癸拷
    DRV3245_EN(0);//娴ｈ儻鍏橀懘姘娴ｏ拷
    DRV3245_EN_DelayCnt1 = 0;
    tx_crc8_1 = 0xFF;
    rx_crc8_1 = 0XFF;

    if(0 == DRV3245_CrcRxErr1)
    {
      stat1.data = DRV3245_Fault1_IC_STAT0.data;
      stat2.data = DRV3245_Fault1_OV_VDS.data;
      stat3.data = DRV3245_Fault1_IC.data;
      stat4.data = DRV3245_Fault1_VGS.data;
      stat5.data = DRV3245_Fault1_IC_STAT1.data;
      stat6.data = DRV3245_Fault1_IC_STAT2.data;

      if(1 == stat1.bits.OTW)
      {
        faultinfo.bits.OTW = 1;
      }

      if((1 == stat1.bits.BIST_STAT)
          ||(1 == stat6.bits.ABIST_FAULT)
          ||(1 == stat6.bits.CLKMON_BIST_FAULT))
      {
        faultinfo.bits.BIST = 1;
      }

      if(1 == stat1.bits.PVDD_OVFL)
      {
        faultinfo.bits.PVDD_OVFL = 1;
      }

      if(1 == stat1.bits.PVDD_UVFL)
      {
        faultinfo.bits.PVDD_UVFL = 1;
      }

      if(1 == stat2.bits.VDS_HA)
      {
        faultinfo.bits.VDS_HA = 1;
      }

      if(1 == stat2.bits.VDS_HB)
      {
        faultinfo.bits.VDS_HB = 1;
      }

      if(1 == stat2.bits.VDS_HC)
      {
        faultinfo.bits.VDS_HC = 1;
      }

      if(1 == stat2.bits.VDS_LA)
      {
        faultinfo.bits.VDS_LA = 1;
      }

      if(1 == stat2.bits.VDS_LB)
      {
        faultinfo.bits.VDS_LB = 1;
      }

      if(1 == stat2.bits.VDS_LC)
      {
        faultinfo.bits.VDS_LC = 1;
      }

      if((1 == stat2.bits.SNS_A_OCP)
          ||(1 == stat2.bits.SNS_B_OCP)
          ||(1 == stat2.bits.SNS_C_OCP))
      {
        faultinfo.bits.SNS_OCP = 1;
      }

      if(1 == stat3.bits.PVDD_UVLO)
      {
        faultinfo.bits.PVDD_UVLO = 1;
      }

      if(1 == stat3.bits.DVDD_OVLO)
      {
        faultinfo.bits.DVDD_OVLO = 1;
      }

      if(1 == stat3.bits.AVDD_OVLO)
      {
        faultinfo.bits.AVDD_OVLO = 1;
      }

      if(1 == stat3.bits.AVDD_UVLO)
      {
        faultinfo.bits.AVDD_UVLO = 1;
      }

      if(1 == stat3.bits.VCP_LSD_UVLO)
      {
        faultinfo.bits.VCP_LSD_UVLO = 1;
      }

      if(1 == stat3.bits.VCP_LSD_OVLO)
      {
        faultinfo.bits.VCP_LSD_OVLO = 1;
      }

      if(1 == stat3.bits.VCPH_UVLO)
      {
        faultinfo.bits.VCPH_UVLO = 1;
      }

      if(1 == stat3.bits.VCPH_OVLO)
      {
        faultinfo.bits.VCPH_OVLO = 1;
      }

      if(1 == stat3.bits.VCPH_OVLO_ABS)
      {
        faultinfo.bits.VCPH_OVLO_ABS = 1;
      }

      if((1 == stat4.bits.VGS_HA)
          ||(1 == stat4.bits.VGS_HB)
          ||(1 == stat4.bits.VGS_HC)
          ||(1 == stat4.bits.VGS_LA)
          ||(1 == stat4.bits.VGS_LB)
          ||(1 == stat4.bits.VGS_LC))
      {
        faultinfo.bits.VGS = 1;
      }

      if(1 == stat5.bits.STP_FAULT)
      {
        faultinfo.bits.STP_FAULT = 1;
      }

      if(1 == stat5.bits.DEADT_FAULT)
      {
        faultinfo.bits.DEADT_FAULT = 1;
      }

      if(1 == stat5.bits.INT_REG_FAULT)
      {
        faultinfo.bits.INT_REG_FAULT = 1;
      }

      if(1 == stat5.bits.CFG_CRC_FAULT)
      {
        faultinfo.bits.CFG_CRC_FAULT = 1;
      }

      if(1 == stat5.bits.CLK_MON_FAULT)
      {
        faultinfo.bits.CLK_MON_FAULT = 1;
      }

      if(1 == stat6.bits.EE_CRC_FAULT)
      {
        faultinfo.bits.EE_CRC_FAULT = 1;
      }

      if(1 == stat6.bits.DEV_MODE_FAULT)
      {
        faultinfo.bits.DEV_MODE_FAULT = 1;
      }

      if((1 == stat6.bits.SPIWR_CRC_FAULT)
          ||(1 == stat6.bits.SPI_CLK_FAULT)
          ||(1 == stat6.bits.SPI_ADDR_FAULT))
      {
        faultinfo.bits.SPIERR = 1;
      }

      /* 閻€劋绨�涙ê鍙嗛幍鈺佺潔DTC */
      if(faultinfo.data == 0)
      {
        faultinfo.bits.rsv = 1;
      }

    }
    else
    {
      /* 鐠佹澘缍峉PI闁挎瑨顕� */
      faultinfo.bits.SPIERR = 1;
    }

    readflag = 1;
    fsFaultClass_Predriver = (uint16)(faultinfo.data & 0xFFFF);
    fsFaultClass_Predriver_extral = (uint16)((faultinfo.data >> 16) & 0xFFFF);
  }
  else
  {
    if(((fsFaultClass_Predriver & 0x1018) != 0)
        &&((fsFaultClass_Predriver & 0xEFE7) == 0)
        &&(fsFaultClass_Predriver_extral == 0))//婵″倹鐏夐崣顏勵槱閸︺劏绻冮崢瀣灗濞嗙姴甯囬弫鍛存娑擄拷
    {
      if((Fv_SysPower > 1024)
        &&(Fv_SysPower < 1958))//閻㈤潧甯囬崶鐐插煂濮濓絽鐖堕懠鍐ㄦ纯閸愶拷 8.7V-16V
      {
        readflag = 0;
        fsFaultClass_Predriver = 0;//濞撳懏顨熼弫鍛存閺嶅洤绻旀担宥呯毦鐠囨洟鍣搁崥锟�
        DRV3245_State1 = DRV3245_STATE_RESET;
      }
    }
  }
}
static void DRV3245_FaultInfoCollection2(void)
{
  static uint8 readflag = 0;
  DRV3245_IC_STAT0Type stat1 = {0};
  DRV3245_OV_VDS_FAULTType stat2 = {0};
  DRV3245_IC_FAULTType stat3 = {0};
  DRV3245_VGS_FAULTType stat4 = {0};
  DRV3245_IC_STAT1Type stat5 = {0};
  DRV3245_IC_STAT2Type stat6 = {0};
  DRV3245_RxDataType rxdata = {0};
  

  DRV3245_State2 = DRV3245_STATE_FAULT;

  if(0 == readflag)
  {
    /* 闁挎瑨顕ら悩鑸碉拷浣稿彠闂傤參顣╂す鍙樺▏閼筹拷 *///todo 閸忚櫕藟妞癸拷
    DRV3245_EN(0);//娴ｈ儻鍏橀懘姘娴ｏ拷
    DRV3245_EN_DelayCnt2 = 0;
    tx_crc8_2 = 0xFF;
    rx_crc8_2 = 0XFF;

    if(0 == DRV3245_CrcRxErr2)
    {
      stat1.data = DRV3245_Fault2_IC_STAT0.data;
      stat2.data = DRV3245_Fault2_OV_VDS.data;
      stat3.data = DRV3245_Fault2_IC.data;
      stat4.data = DRV3245_Fault2_VGS.data;
      stat5.data = DRV3245_Fault2_IC_STAT1.data;
      stat6.data = DRV3245_Fault2_IC_STAT2.data;

      if(1 == stat1.bits.OTW)
      {
        faultinfo.bits.OTW = 1;
      }

      if((1 == stat1.bits.BIST_STAT)
          ||(1 == stat6.bits.ABIST_FAULT)
          ||(1 == stat6.bits.CLKMON_BIST_FAULT))
      {
        faultinfo.bits.BIST = 1;
      }

      if(1 == stat1.bits.PVDD_OVFL)
      {
        faultinfo.bits.PVDD_OVFL = 1;
      }

      if(1 == stat1.bits.PVDD_UVFL)
      {
        faultinfo.bits.PVDD_UVFL = 1;
      }

      if(1 == stat2.bits.VDS_HA)
      {
        faultinfo.bits.VDS_HA = 1;
      }

      if(1 == stat2.bits.VDS_HB)
      {
        faultinfo.bits.VDS_HB = 1;
      }

      if(1 == stat2.bits.VDS_HC)
      {
        faultinfo.bits.VDS_HC = 1;
      }

      if(1 == stat2.bits.VDS_LA)
      {
        faultinfo.bits.VDS_LA = 1;
      }

      if(1 == stat2.bits.VDS_LB)
      {
        faultinfo.bits.VDS_LB = 1;
      }

      if(1 == stat2.bits.VDS_LC)
      {
        faultinfo.bits.VDS_LC = 1;
      }

      if((1 == stat2.bits.SNS_A_OCP)
          ||(1 == stat2.bits.SNS_B_OCP)
          ||(1 == stat2.bits.SNS_C_OCP))
      {
        faultinfo.bits.SNS_OCP = 1;
      }

      if(1 == stat3.bits.PVDD_UVLO)
      {
        faultinfo.bits.PVDD_UVLO = 1;
      }

      if(1 == stat3.bits.DVDD_OVLO)
      {
        faultinfo.bits.DVDD_OVLO = 1;
      }

      if(1 == stat3.bits.AVDD_OVLO)
      {
        faultinfo.bits.AVDD_OVLO = 1;
      }

      if(1 == stat3.bits.AVDD_UVLO)
      {
        faultinfo.bits.AVDD_UVLO = 1;
      }

      if(1 == stat3.bits.VCP_LSD_UVLO)
      {
        faultinfo.bits.VCP_LSD_UVLO = 1;
      }

      if(1 == stat3.bits.VCP_LSD_OVLO)
      {
        faultinfo.bits.VCP_LSD_OVLO = 1;
      }

      if(1 == stat3.bits.VCPH_UVLO)
      {
        faultinfo.bits.VCPH_UVLO = 1;
      }

      if(1 == stat3.bits.VCPH_OVLO)
      {
        faultinfo.bits.VCPH_OVLO = 1;
      }

      if(1 == stat3.bits.VCPH_OVLO_ABS)
      {
        faultinfo.bits.VCPH_OVLO_ABS = 1;
      }

      if((1 == stat4.bits.VGS_HA)
          ||(1 == stat4.bits.VGS_HB)
          ||(1 == stat4.bits.VGS_HC)
          ||(1 == stat4.bits.VGS_LA)
          ||(1 == stat4.bits.VGS_LB)
          ||(1 == stat4.bits.VGS_LC))
      {
        faultinfo.bits.VGS = 1;
      }

      if(1 == stat5.bits.STP_FAULT)
      {
        faultinfo.bits.STP_FAULT = 1;
      }

      if(1 == stat5.bits.DEADT_FAULT)
      {
        faultinfo.bits.DEADT_FAULT = 1;
      }

      if(1 == stat5.bits.INT_REG_FAULT)
      {
        faultinfo.bits.INT_REG_FAULT = 1;
      }

      if(1 == stat5.bits.CFG_CRC_FAULT)
      {
        faultinfo.bits.CFG_CRC_FAULT = 1;
      }

      if(1 == stat5.bits.CLK_MON_FAULT)
      {
        faultinfo.bits.CLK_MON_FAULT = 1;
      }

      if(1 == stat6.bits.EE_CRC_FAULT)
      {
        faultinfo.bits.EE_CRC_FAULT = 1;
      }

      if(1 == stat6.bits.DEV_MODE_FAULT)
      {
        faultinfo.bits.DEV_MODE_FAULT = 1;
      }

      if((1 == stat6.bits.SPIWR_CRC_FAULT)
          ||(1 == stat6.bits.SPI_CLK_FAULT)
          ||(1 == stat6.bits.SPI_ADDR_FAULT))
      {
        faultinfo.bits.SPIERR = 1;
      }

      /* 閻€劋绨�涙ê鍙嗛幍鈺佺潔DTC */
      if(faultinfo.data == 0)
      {
        faultinfo.bits.rsv = 1;
      }

    }
    else
    {
      /* 鐠佹澘缍峉PI闁挎瑨顕� */
      faultinfo.bits.SPIERR = 1;
    }

    readflag = 1;
    fsFaultClass_Predriver = (uint16)(faultinfo.data & 0xFFFF);
    fsFaultClass_Predriver_extral = (uint16)((faultinfo.data >> 16) & 0xFFFF);
  }
  else
  {
    if(((fsFaultClass_Predriver & 0x1018) != 0)
        &&((fsFaultClass_Predriver & 0xEFE7) == 0)
        &&(fsFaultClass_Predriver_extral == 0))//婵″倹鐏夐崣顏勵槱閸︺劏绻冮崢瀣灗濞嗙姴甯囬弫鍛存娑擄拷
    {
      if((Fv_SysPower > 1024)
        &&(Fv_SysPower < 1958))//閻㈤潧甯囬崶鐐插煂濮濓絽鐖堕懠鍐ㄦ纯閸愶拷 8.7V-16V
      {
        readflag = 0;
        fsFaultClass_Predriver = 0;//濞撳懏顨熼弫鍛存閺嶅洤绻旀担宥呯毦鐠囨洟鍣搁崥锟�
        DRV3245_State2 = DRV3245_STATE_RESET;
      }
    }
  }
}
/****************************************************************
 * FUNCTION :  DRV3245_BridgeOper(uint8 set)
 * DESCRIPTION : 
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	
 ****************************************************************/
void DRV3245_BridgeOper1(uint8 set)
{
  DRV3245_GATE_DRIVE_CTRLType gate_drive_ctrl = {0};
  gate_drive_ctrl.data = DRV3245_GATE_DRIVE_CTRLInit.data;
  gate_drive_ctrl.bits.ENABLE_DRV = set;
  DRV3245_RegWrite1(DRV3245_GATE_DRIVE_CTRL,gate_drive_ctrl.data);

  DRV3245_SetDRVOFF1((!set));
}
void DRV3245_BridgeOper2(uint8 set)
{
  DRV3245_GATE_DRIVE_CTRLType gate_drive_ctrl = {0};
  gate_drive_ctrl.data = DRV3245_GATE_DRIVE_CTRLInit.data;
  gate_drive_ctrl.bits.ENABLE_DRV = set;
  DRV3245_RegWrite2(DRV3245_GATE_DRIVE_CTRL,gate_drive_ctrl.data);

  DRV3245_SetDRVOFF2((!set));
}
/****************************************************************
 * FUNCTION :  DRV3245_ClearAllFault(void)
 * DESCRIPTION : clear all fault bits
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	
 ****************************************************************/
void DRV3245_ClearAllFault1(void)
{
    DRV3245_RegWrite1(DRV3245_IC_OPERATION,(DRV3245_IC_OPERATIONInit.data | 0x02));
}
void DRV3245_ClearAllFault2(void)
{
    DRV3245_RegWrite2(DRV3245_IC_OPERATION,(DRV3245_IC_OPERATIONInit.data | 0x02));
}
  /****************************************************************
 * FUNCTION :  DRV3245_RegRead(uint8 addr)
 * DESCRIPTION : Read reg value
 * INPUTS :  Reg addr 
 * OUTPUTS : Reg value
 * Limitations:	
 ****************************************************************/
static DRV3245_RxDataType DRV3245_RegRead1(uint8 addr, uint8 addr_extral)
{
  DRV3245_RxDataType rxdata = {0};
  DRV3245_TxDataType txdata = {0};

  txdata.read_bits.RW = DRV3245_SPI_READ;
  txdata.read_bits.ADDRESS = addr;
  txdata.read_bits.ADDRESS_EXTRAL = addr_extral;

  DRV3245_SendAndReceive1(&txdata,&rxdata);

  return rxdata;
}
static DRV3245_RxDataType DRV3245_RegRead2(uint8 addr, uint8 addr_extral)
{
  DRV3245_RxDataType rxdata = {0};
  DRV3245_TxDataType txdata = {0};

  txdata.read_bits.RW = DRV3245_SPI_READ;
  txdata.read_bits.ADDRESS = addr;
  txdata.read_bits.ADDRESS_EXTRAL = addr_extral;

  DRV3245_SendAndReceive2(&txdata,&rxdata);

  return rxdata;
}
/****************************************************************
 * FUNCTION :  DRV3245_RegWrite(uint8 addr, uint16 data)
 * DESCRIPTION : write value to desinated reg
 * INPUTS :  addr/data
 * OUTPUTS : None
 * Limitations:	
 ****************************************************************/
void DRV3245_RegWrite1(uint8 addr, uint16 data)
{
    DRV3245_RxDataType rxdata = {0};
    DRV3245_TxDataType txdata = {0};

    txdata.write_bits.RW = DRV3245_SPI_WRITE;
    txdata.write_bits.ADDRESS = addr;
    txdata.write_bits.DATA_WRTIE = (data & 0x7FF);
    DRV3245_SendAndReceive1(&txdata,&rxdata);
}
void DRV3245_RegWrite2(uint8 addr, uint16 data)
{
    DRV3245_RxDataType rxdata = {0};
    DRV3245_TxDataType txdata = {0};

    txdata.write_bits.RW = DRV3245_SPI_WRITE;
    txdata.write_bits.ADDRESS = addr;
    txdata.write_bits.DATA_WRTIE = (data & 0x7FF);
    DRV3245_SendAndReceive2(&txdata,&rxdata);
}
/****************************************************************
* FUNCTION :  DRV3245_SendAndReceive
* DESCRIPTION : DRV3245閸欐垿锟戒礁鎷伴幒銉︽暪閺佺増宓侀崙鑺ユ殶
* INPUTS :
      txdata					鐟曚礁褰傞柅浣规殶閹诡喚娈戠紒鎾寸�担鎾村瘹闁斤拷
      rxdata				  閻€劋绨幒銉︽暪閺佺増宓侀惃鍕波閺嬪嫪缍嬮幐鍥嫛
* OUTPUTS :
      None
* Limitations:	娴犲懘妾洪崘鍛村劥鐠嬪啰鏁�
****************************************************************/
DRV3245_RxDataType RxDataDebug;
static void DRV3245_SendAndReceive1(DRV3245_TxDataType *txdata, DRV3245_RxDataType *rxdata)
{
  volatile static uint16 cnt = 0;
  DRV3245_CrcDataArr1[0] = ((txdata->data >> 8) & 0xFF);
  DRV3245_CrcDataArr1[1] = ((txdata->data) & 0xFF);

  if((txdata->data & 0xFF00) == 0X6900)
  {
    tx_crc8_1 = DRV3245_CRC8_Tbl[tx_crc8_1 ^ DRV3245_CrcDataArr1[0]];
    txdata->data |= tx_crc8_1;
    tx_crc8_1 = 0xFF;
  }
  else
  {
    tx_crc8_1 = DRV3245_CRC8_Tbl[tx_crc8_1 ^ DRV3245_CrcDataArr1[0]];
    tx_crc8_1 = DRV3245_CRC8_Tbl[tx_crc8_1 ^ DRV3245_CrcDataArr1[1]];
  }

  /* 閸欐垿锟戒讣PI閺佺増宓� */
  rxdata->data = DRV3245_SpiComm1(txdata->data);
  RxDataDebug.data = rxdata->data;
  DRV3245_CrcDataArr1[0] = ((rxdata->data >> 8) & 0xFF);
  DRV3245_CrcDataArr1[1] = ((rxdata->data) & 0xFF);

  if((txdata->data & 0xFF00) == 0XEA00)
  {
    rx_crc8_1 = DRV3245_CRC8_Tbl[rx_crc8_1 ^ DRV3245_CrcDataArr1[0]];
    if(rx_crc8_1 == DRV3245_CrcDataArr1[1])
    {
      DRV3245_CrcRxErr1 = 0;
    }
    else
    {
      DRV3245_CrcRxErr1 = 1;
    }
    rx_crc8_1 = 0xFF;
  }
  else
  {
    rx_crc8_1 = DRV3245_CRC8_Tbl[rx_crc8_1 ^ DRV3245_CrcDataArr1[0]];
    rx_crc8_1 = DRV3245_CRC8_Tbl[rx_crc8_1 ^ DRV3245_CrcDataArr1[1]];
  }

  while(cnt < 1000)
  {
	  cnt ++;
  }
  cnt = 0;
}
static void DRV3245_SendAndReceive2(DRV3245_TxDataType *txdata, DRV3245_RxDataType *rxdata)
{
  volatile static uint16 cnt = 0;
  DRV3245_CrcDataArr2[0] = ((txdata->data >> 8) & 0xFF);
  DRV3245_CrcDataArr2[1] = ((txdata->data) & 0xFF);

  if((txdata->data & 0xFF00) == 0X6900)
  {
    tx_crc8_2 = DRV3245_CRC8_Tbl[tx_crc8_2 ^ DRV3245_CrcDataArr2[0]];
    txdata->data |= tx_crc8_2;
    tx_crc8_2 = 0xFF;
  }
  else
  {
    tx_crc8_2 = DRV3245_CRC8_Tbl[tx_crc8_2 ^ DRV3245_CrcDataArr2[0]];
    tx_crc8_2 = DRV3245_CRC8_Tbl[tx_crc8_2 ^ DRV3245_CrcDataArr2[1]];
  }

  /* 閸欐垿锟戒讣PI閺佺増宓� */
  rxdata->data = DRV3245_SpiComm2(txdata->data);
  RxDataDebug.data = rxdata->data;
  DRV3245_CrcDataArr2[0] = ((rxdata->data >> 8) & 0xFF);
  DRV3245_CrcDataArr2[1] = ((rxdata->data) & 0xFF);

  if((txdata->data & 0xFF00) == 0XEA00)
  {
    rx_crc8_2 = DRV3245_CRC8_Tbl[rx_crc8_2 ^ DRV3245_CrcDataArr2[0]];
    if(rx_crc8_2 == DRV3245_CrcDataArr2[1])
    {
      DRV3245_CrcRxErr2 = 0;
    }
    else
    {
      DRV3245_CrcRxErr2 = 1;
    }
    rx_crc8_2 = 0xFF;
  }
  else
  {
    rx_crc8_2 = DRV3245_CRC8_Tbl[rx_crc8_2 ^ DRV3245_CrcDataArr2[0]];
    rx_crc8_2 = DRV3245_CRC8_Tbl[rx_crc8_2 ^ DRV3245_CrcDataArr2[1]];
  }

  while(cnt < 1000)
  {
	  cnt ++;
  }
  cnt = 0;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
static uint16 DRV3245_SpiComm1(uint16 txdata)
{
	uint16 rxdata = 0;
    uint8 errorflag = 0;
	uint16 timeoutcnt = 0;

	PreDriver_SpiTxdata1 = txdata;

	(void)Spi_WriteIB(CDD_PREDRIVER_SPI_CHANNEL1, (uint8 *) &PreDriver_SpiTxdata1);
	(void)Spi_SyncTransmit(CDD_PREDRIVER_SPI_CHANNEL1);
    while(Spi_GetSequenceResult(CDD_PREDRIVER_SPI_CHANNEL1) != SPI_SEQ_OK)
    {
      /* Wait till write is finished
       * add timeout count */
    	timeoutcnt ++;
    	if(timeoutcnt > CDD_PREDRIVER_SPI_TIMEOUT_VALUE)
    	{
    		errorflag = 1;
    		break;
    	}
    }

    (void)Spi_ReadIB(CDD_PREDRIVER_SPI_CHANNEL1, (uint8 *)&PreDriver_SpiRxdata1);

    if(errorflag > 0)
    {
    	PreDriver_SpiRxdata1 = 0xFFFF;
    }

    rxdata = PreDriver_SpiRxdata1;

	return rxdata;
}
static uint16 DRV3245_SpiComm2(uint16 txdata)
{
	uint16 rxdata = 0;
    uint8 errorflag = 0;
	uint16 timeoutcnt = 0;

	PreDriver_SpiTxdata2 = txdata;

	(void)Spi_WriteIB(CDD_PREDRIVER_SPI_CHANNEL2, (uint8 *) &PreDriver_SpiTxdata2);
	(void)Spi_SyncTransmit(CDD_PREDRIVER_SPI_CHANNEL2);
    while(Spi_GetSequenceResult(CDD_PREDRIVER_SPI_CHANNEL2) != SPI_SEQ_OK)
    {
      /* Wait till write is finished
       * add timeout count */
    	timeoutcnt ++;
    	if(timeoutcnt > CDD_PREDRIVER_SPI_TIMEOUT_VALUE)
    	{
    		errorflag = 1;
    		break;
    	}
    }

    (void)Spi_ReadIB(CDD_PREDRIVER_SPI_CHANNEL2, (uint8 *)&PreDriver_SpiRxdata2);

    if(errorflag > 0)
    {
    	PreDriver_SpiRxdata2 = 0xFFFF;
    }

    rxdata = PreDriver_SpiRxdata2;

	return rxdata;
}
/****************************************************************
 * FUNCTION :  DRV3245_ErrCountSet
 * DESCRIPTION : DRV3245闁挎瑨顕ょ拋鈩冩殶鐠佸墽鐤�
 * INPUTS :  None
 * OUTPUTS : None
 * Limitations:	娴犲懘妾烘禍搴″敶闁劏鐨熼悽锟�
 ****************************************************************/
static void DRV3245_ErrCountSet1(void)
{
	/* 闁挎瑨顕ょ拋鈩冩殶鐡掑懓绻冩稉锟界�规艾锟界厧鎮楅敍灞炬纯閺傞璐熼柨娆掝嚖閻樿埖锟斤拷 */
	if(DRV3245_CommErrCnt1 < DRV3245_ERR_ALLOWED_CNT)
	{
		DRV3245_CommErrCnt1 ++;
	}
	else
	{
		DRV3245_State1 = DRV3245_STATE_FAULT;
	}
}
static void DRV3245_ErrCountSet2(void)
{
	/* 闁挎瑨顕ょ拋鈩冩殶鐡掑懓绻冩稉锟界�规艾锟界厧鎮楅敍灞炬纯閺傞璐熼柨娆掝嚖閻樿埖锟斤拷 */
	if(DRV3245_CommErrCnt2 < DRV3245_ERR_ALLOWED_CNT)
	{
		DRV3245_CommErrCnt2 ++;
	}
	else
	{
		DRV3245_State2 = DRV3245_STATE_FAULT;
	}
}
/****************************************************************
* FUNCTION :  DRV3245_GetStatus
* DESCRIPTION : DRV3245 閼惧嘲褰囬悩鑸碉拷浣稿毐閺侊拷
* INPUTS :  None
* OUTPUTS :
        0			DRV3245瀹搞儰缍斿锝呯埗
        1			DRV3245瀹搞儰缍斿鍌氱埗
* Limitations:	閻€劋绨径鏍劥閺屻儴顕桪RV3245鏉╂劘顢戦悩鑸碉拷锟�
****************************************************************/
uint8 DRV3245_GetStatus1(void)
{

  uint8 ret = 0;

	if(DRV3245_State1 == DRV3245_STATE_FAULT)
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}

  return ret;
}
uint8 DRV3245_GetStatus2(void)
{

  uint8 ret = 0;

	if(DRV3245_State2 == DRV3245_STATE_FAULT)
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}

  return ret;
}
