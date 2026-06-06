/* BEGIN_FILE_HDR
**************************************************************************
* NOTICE
* This software is the property of XiangBin Electric. Any information contained in this
* doc should not be reproduced, or used, or disclosed without the written authorization from
* XiangBin Electric.
**************************************************************************
* File Name: DRV32345_Cfg.c
********************************************************************
* Project/Product: EPS
* Title: DRV3245棰勯┍鑺墖椹卞姩
* Author: LHC
*********************************************************************
* Description:
*	姝ゆ枃浠剁敤浜庡畾涔塂RV3245鍒濆鍖栫粨鏋勪綋
*
* (Requirements, pseudo code and etc.)
*********************************************************************
* Limitations:
* 	鏈枃浠朵粎閫傜敤浜庢惌杞紻RV3245鑺墖鐨勬帶鍒跺櫒
* (limitations)
*********************************************************************
*********************************************************************
* Revision History锛�
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
#include "DRV3245_Cfg.h"
#include "DRV3245_Types.h"

const DRV3245_HS_GATE_DRIVE_CTRLType DRV3245_HS_GATE_DRIVE_CTRLInit = {
  0x3, /* IDRIVEP_HS-----High-side gate driver peak source current */
  0x0, /* rsv */
  0x3, /* IDRIVEN_HS-----High-side gate driver peak sink current */
  0x0, /* rsv */
  0x3, /* TDRIVEN-----High-side and low-side gate driver peak sink time */
  0x0, /* rsv */
};

const DRV3245_LS_GATE_DRIVE_CTRLType DRV3245_LS_GATE_DRIVE_CTRLInit = {
  0x3, /* IDRIVEP_LS-----Low-side gate driver peak source current */
  0x0, /* rsv */
  0x3, /* IDRIVEN_LS-----Low-side gate driver peak sink current */
  0x0, /* rsv */
  0x3, /* TDRIVEP-----High-side and low-side gate driver peak source time */
  0x0, /* IHOLD_MODE */
  0x0, /* rsv */
};

const DRV3245_GATE_DRIVE_CTRLType DRV3245_GATE_DRIVE_CTRLInit = {
  0x2, /* TVDS-----VDS sense deglitch time */ //todo 鍙傝��9083
  0x1, /* TBLANK-----VDS sense blanking time *///todo 鍙傝��4911
  0x3, /* DEAD_TIME-----Predriver input dead time */
  0x0, /* PWM_MODE-----PWM mode */
  0x0, /* PWM_COM-----1 PWM mode control */
  0x0, /* ENABLE_DRV-----Enable predriver bit */
  0x0, /* rsv */
};

const DRV3245_IC_OPERATIONType DRV3245_IC_OPERATIONInit = {
  0x0, /* rsv */
  0x0, /* CLR_FLTS-----Clear faults */
  0x1, /* PVDD_OV_MODE-----PVDD overvoltage fault reporting mode */
  0x0, /* rsv */
  0x0, /* DIS_SNS_OCP-----Disable SNS overcurrent protection fault and reporting */
  0x1, /* DEADT_MODE-----Dead-time protection mode in the 3-PWM and 1-PWM modes *///todo 闂瓼AE
  0x0, /* STP_MODE-----Shoot-through protection report mode */
  0x0, /* VGS_MODE-----VGS detection mode */
  0x0, /* rsv */
};

const DRV3245_SHUNT_AMPLIDIER_CRTLType DRV3245_SHUNT_AMPLIDIER_CRTLInit = {
  0x1, /* GAIN_CS1-----Gain of CS amplifier 1 *///鍛婅瘔纭欢
  0x1, /* GAIN_CS2-----Gain of CS amplifier 2 */
  0x1, /* GAIN_CS3-----Gain of CS amplifier 3 */
  0x0, /* CSA2_DIAG-----CSA2 (SO2) diagnostic mode */
  0x0, /* rsv */
  0x0, /* 000b */
  0x0, /* rsv */
};

const DRV3245_IC_CRTL0Type DRV3245_IC_CRTL0Init = {
  0x1, /* WARN_MODE-----Warning reporting mode (nFAULT) for the PVDD_OVFL and VDS_xx bits. */
  0x0, /* CFG_CRC_EN-----Configuration data CRC enable *///todo
  0x2, /* IDRIVESD-----Predriver shutdown current IDRIVESHD control */
  0x0, /* rsv */
  0x1, /* 001b */
  0x0, /* rsv */
};

const DRV3245_IC_CRTL1Type DRV3245_IC_CRTL1Init = {
  0x0, /* CFG_CRC_DIAG-----Configuration data CRC diagnostic mode *///TODO
  0x0, /* DRV_SH_DIAG-----Driver SHx pin diagnostic mode */
  0x1, /* DRVOFF_DIAG-----DRVOFF VGS diagnostic mode */
  0x0, /* rsv */
  0x2, /* 010b */
  0x0, /* rsv */
};

const DRV3245_PHC_CRTLType DRV3245_PHC_CRTLInit = {
  0x0, /* PHC_COMP_EN-----Phase comparator enable (A, B, C devices only) */
  0x0, /* PHC_OUTEN-----Phase-comparator output enable (B device only) */
  0x0, /* PHC_MODE-----Phase-comparator threshold mode (A, B, C devices only) */
  0x0, /* rsv */
  0x4, /* 100b */
  0x0, /* rsv */
};

const DRV3245_VOLTAGE_REGULATOR_CTRLType DRV3245_VOLTAGE_REGULATOR_CTRLInit = {
  0x1, /* CP_SD_MODE-----Charge pump shutdown mode */
  0x0, /* CP_DIS-----Charge pump disable *///TODO 闂‖浠�
  0x1, /* VCPHOVABS_MODE-----VCPH_OV_ABS fault mode */
  0x0, /* rsv */
  0x1, /* VREF_SCALE-----VREF scaling */
  0x0, /* rsv */
};

const DRV3245_VDS_SENSE_CTRL0Type DRV3245_VDS_SENSE_CTRL0Init = {
  0x0, /* VDS_MODE-----VDS mode */
  0x0, /* VDS_DIAG-----VDS diagnostic mode */
  0xF, /* VDS_LEVEL-----Predriver shutdown current IDRIVESHD control */
  0x0, /* 000b */
  0x0, /* rsv */
};

const DRV3245_VDS_SENSE_CTRL1Type DRV3245_VDS_SENSE_CTRL1Init = {
  0x0, /* VDS_CFG_MODE-----VDS diagnostic mode */
  0x0, /* rsv */
  0x0, /* VDS_LEVEL_HSA-----VDS comparator threshold for high-side channel A */
  0x1, /* 001b */
  0x0, /* rsv */
};

const DRV3245_VDS_SENSE_CTRL2Type DRV3245_VDS_SENSE_CTRL2Init = {
  0x0, /* VDS_LEVEL_HSC-----VDS comparator threshold for high-side channel C */
  0x0, /* VDS_LEVEL_HSB-----VDS comparator threshold for high-side channel B */
  0x2, /* 010b */
  0x0, /* rsv */
};

const DRV3245_VGS_CTRL1Type DRV3245_VGS_CTRL1Init = {
  0x2, /* VGS_BLANK-----VGS detection blanking time */
  0x2, /* VGS_DEG-----VGS detection deglitch time */
  0x0, /* VGS_TH_MODE-----VGS detection threshold mode */
  0x0, /* rsv */
  0x4, /* 100b */
  0x0, /* rsv */
};
