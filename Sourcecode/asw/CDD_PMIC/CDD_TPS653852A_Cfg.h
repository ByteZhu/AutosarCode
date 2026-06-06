/*
 * CDD_TPS653852A_Cfg.h
 *
 *  Created on: 2023Äê7ÔÂ18ÈÕ
 *      Author: tiand
 */

#ifndef SOURCECODE_ASW_CDD_TPS653852A_CDD_TPS653852A_CFG_H_
#define SOURCECODE_ASW_CDD_TPS653852A_CDD_TPS653852A_CFG_H_

#include "Std_Types.h"

#define TPS653852A_SPI_CHANNEL		SpiConf_SpiSequence_SpiSequence_PMIC

#define TPS653852A_SPI_TIMEOUT_VALUE		2000

extern const uint8 PMIC_SAFETY_FUNC_CFG;
extern const uint8 PMIC_DEV_REV;
extern const uint8 PMIC_DEV_ID;
extern const uint8 PMIC_SAFETY_PWD_THR_CFG;
extern const uint8 PMIC_SAFETY_ERR_CFG_1;
extern const uint8 PMIC_WD_QUESTION_FDBK;
extern const uint8 PMIC_WD_WIN2_CFG;
extern const uint8 PMIC_WD_WIN1_CFG;
extern const uint8 PMIC_SAFETY_ERR_PWM_LMAX;
extern const uint8 PMIC_SAFETY_ERR_PWM_LMIN;
extern const uint8 PMIC_SAFETY_ERR_PWM_HMAX;
extern const uint8 PMIC_SAFETY_ERR_PWM_HMIN;
extern const uint8 PMIC_DEV_CFG_2;
extern const uint8 PMIC_DEV_CFG_1;
extern const uint8 PMIC_SAFETY_ERR_CFG_2;
extern const uint8 PMIC_DEV_CFG_3;
extern const uint8 PMIC_SAFETY_CHECK_CTRL;
extern const uint8 PMIC_SENS_CTRL;

#endif /* SOURCECODE_ASW_CDD_TPS653852A_CDD_TPS653852A_CFG_H_ */
