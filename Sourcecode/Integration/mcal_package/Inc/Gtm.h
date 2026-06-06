/*
 * Gtm.h
 *
 *  Created on: 2021年7月21日
 *      Author: TIAN
 */

#ifndef MCAL_IO_GTM_H_
#define MCAL_IO_GTM_H_

#include "Std_Types.h"

enum Gtm_TimChType
{
    Gtm_Tim1Ch1 = 0,
    Gtm_Tim1Ch2,
    Gtm_Tim1Ch5,
    Gtm_Tim1Ch7,
    Gtm_TimChnum = 4
};

typedef enum
{
	GTM_TIM_CH_0,
	GTM_TIM_CH_1,
	GTM_TIM_CH_2,
	GTM_TIM_CH_3,
	GTM_TIM_CH_4,
	GTM_TIM_CH_5,
	GTM_TIM_CH_6,
	GTM_TIM_CH_7
}GTM_TIMChannelType;

typedef struct
{
        uint32 Gpr0;
        uint32 Gpr1;
        uint8 status;
}Gtm_TimxChxCapValueType;

#define GTM_TIMX_CHX_STATUS_NEW_VAL    1u
#define GTM_TIMX_CHX_STATUS_ERROR      2u

extern Gtm_TimxChxCapValueType Gtm_TimxChxCapValue[Gtm_TimChnum];

extern void Gtm_Init(void);

extern void Gtm_StartTOM(void);

extern void Gtm_EnablePwm01(uint8 status);

extern void Gtm_EnablePwm02(uint8 status);

extern void Gtm_SetPwm01(uint16 u, uint16 v, uint16 w);

extern void Gtm_SetPwm02(uint16 u, uint16 v, uint16 w);

extern uint16 Gtm_TimGetPwmDuty(GTM_TIMChannelType channel);

#endif /* MCAL_IO_GTM_H_ */
