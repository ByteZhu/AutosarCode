/* BEGIN_FILE_HDR
**************************************************************************
* NOTICE
* This software is the property of XiangBin Electric. Any information contained in this
* doc should not be reproduced, or used, or disclosed without the written authorization from
* XiangBin Electric.
**************************************************************************
* File Name: DRV32345_Cfg.h
********************************************************************
* Project/Product: EPS
* Title: DRV3245妫板嫰鈹嶉懞顖滃妞瑰崬濮�
* Author: LHC
*********************************************************************
* Description:
*	濮濄倖鏋冩禒鍓佹暏娴滃骸锛愰弰宥V3245閸掓繂顫愰崠鏍波閺嬪嫪缍�
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
#ifndef _DRV3245_CFG_H_
#define _DRV3245_CFG_H_

#include "DRV3245_Types.h"

#define DRV3245_WRONG_CONTENT_CNT 2u
#define DRV3245_ERR_ALLOWED_CNT 20u

#define CDD_PREDRIVER_SPI_CHANNEL1		SpiConf_SpiSequence_SpiSequence_PreDriver1

#define CDD_PREDRIVER_SPI_CHANNEL2		SpiConf_SpiSequence_SpiSequence_PreDriver2

#define CDD_PREDRIVER_SPI_TIMEOUT_VALUE		2000

extern const DRV3245_HS_GATE_DRIVE_CTRLType DRV3245_HS_GATE_DRIVE_CTRLInit;

extern const DRV3245_LS_GATE_DRIVE_CTRLType DRV3245_LS_GATE_DRIVE_CTRLInit;

extern const DRV3245_GATE_DRIVE_CTRLType DRV3245_GATE_DRIVE_CTRLInit;

extern const DRV3245_IC_OPERATIONType DRV3245_IC_OPERATIONInit;

extern const DRV3245_SHUNT_AMPLIDIER_CRTLType DRV3245_SHUNT_AMPLIDIER_CRTLInit;

extern const DRV3245_IC_CRTL0Type DRV3245_IC_CRTL0Init;

extern const DRV3245_IC_CRTL1Type DRV3245_IC_CRTL1Init;

extern const DRV3245_PHC_CRTLType DRV3245_PHC_CRTLInit;

extern const DRV3245_VOLTAGE_REGULATOR_CTRLType DRV3245_VOLTAGE_REGULATOR_CTRLInit;

extern const DRV3245_VDS_SENSE_CTRL0Type DRV3245_VDS_SENSE_CTRL0Init;

extern const DRV3245_VDS_SENSE_CTRL1Type DRV3245_VDS_SENSE_CTRL1Init;

extern const DRV3245_VDS_SENSE_CTRL2Type DRV3245_VDS_SENSE_CTRL2Init;

extern const DRV3245_VGS_CTRL1Type DRV3245_VGS_CTRL1Init;

#endif
