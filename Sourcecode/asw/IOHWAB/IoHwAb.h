/*
 * IoHwAb.h
 *
 *  Created on: 2024��5��24��
 *      Author: Administrator
 */

#ifndef SOURCECODE_ASW_IOHWAB_IOHWAB_H_
#define SOURCECODE_ASW_IOHWAB_IOHWAB_H_

#include "Dio.h"
#include "Gtm.h"
#include "Mcu.h"

#define IoHwAb_UBrigdeSampleEnable()  Dio_WriteChannel(DioConf_DioChannel_P00_0, STD_HIGH)
#define IoHwAb_UBrigdeSampleDisable()  Dio_WriteChannel(DioConf_DioChannel_P00_0, STD_LOW)

#define IoHwAb_DRVOFF1_Enable()	Dio_WriteChannel(DioConf_DioChannel_P15_3, STD_LOW)
#define IoHwAb_DRVOFF1_Disable()	Dio_WriteChannel(DioConf_DioChannel_P15_3, STD_HIGH)

#define IoHwAb_DRVOFF2_Enable()	Dio_WriteChannel(DioConf_DioChannel_P15_4, STD_LOW)
#define IoHwAb_DRVOFF2_Disable()	Dio_WriteChannel(DioConf_DioChannel_P15_4, STD_HIGH)

#define IoHwAb_PreDriverDiagIoGet()	Dio_ReadChannel(DioConf_DioChannel_P21_0)

#define IoHwAb_PwmOut01Enable()           Gtm_EnablePwm01(1)
#define IoHwAb_PwmOut01Disable()           Gtm_EnablePwm01(0)

#define IoHwAb_PwmOut02Enable()           Gtm_EnablePwm02(1)
#define IoHwAb_PwmOut02Disable()           Gtm_EnablePwm02(0)

#define IoHwAb_PwmOut01Set(u, v, w)          Gtm_SetPwm01(u, v, w)
#define IoHwAb_PwmOut02Set(u, v, w)          Gtm_SetPwm02(u, v, w)

#if 0
#define OpenRelay()         (SysTaskMainRelayPending = TRUE)

#define OpenPhase()         (IoHwAb_CUTOFF_Enable(), (SysTaskPhaseRelayPending = TRUE))

#define CloseRelay()        (SysTaskMainRelayPending = FALSE)

#define ClosePhase()        (IoHwAb_CUTOFF_Disable(), (SysTaskPhaseRelayPending = FALSE))
#endif

#define SoftWareReset()		Mcu_PerformReset()

#define DisablePowerSupply() (Fv_TPS653852GoToSleep = TRUE)

#define SERVICE_WATCHDOG()

#define CommonCheckSumStoredRequest()

#define AngleCorrectStoredRequest()         AngleCorrectStoredReq()

#define StoreManager_GetStatus()    0

#define TAB_PMSM_FOC_Sqrt_U PMSM_FOC_Sqrt_U

#define GET_ANGLR_VALID_END     (0)

extern void IoHwAb_Init(void);

extern void IoHwAb_RapidDataProcess(void);

extern void IoHwAb_SlowDataProcess(void);

extern void IoHwAb_TMRCorrection(void);

extern boolean IoHwAb_GetKL15_Status(void);

#endif /* SOURCECODE_ASW_IOHWAB_IOHWAB_H_ */
