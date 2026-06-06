/*
 * Gtm.c
 *
 *  Created on: 2021年7月21日
 *      Author: TIAN
 */

#include "Ifx_reg.h"
#include "Gtm.h"

#define GTM_DEADTIME_500NS		100

static void Gtm_TomInit(void);
static void Gtm_TimInit(void);
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void Gtm_Init(void)
{
    uint16 password = 0;

	password = SCU_WDTCPU0CON0.B.PW;

	password ^= 0x003F;
    if(SCU_WDTCPU0CON0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
    	SCU_WDTCPU0CON0.U = (1 << 0u) |
                          (0 << 1u) |
                          (password << 2u) |
                          (SCU_WDTCPU0CON0.B.REL << 16u);
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    SCU_WDTCPU0CON0.U = (0 << 0u) |
                      (1 << 1u) |
                      (password << 2u) |
                      (SCU_WDTCPU0CON0.B.REL << 16u);

    /* read back ENDINIT and wait until it has been cleared */
    while (SCU_WDTCPU0CON0.B.ENDINIT == 1)
    {}
    GTM_CLC.B.DISR = 0;
    CCU60_CLC.B.DISR = 0;
    if(SCU_WDTCPU0CON0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
    	SCU_WDTCPU0CON0.U = (1 << 0u) |
                          (0 << 1u) |
                          (password << 2u) |
                          (SCU_WDTCPU0CON0.B.REL << 16u);
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    SCU_WDTCPU0CON0.U = (1 << 0u) |
                      (1 << 1u) |
                      (password << 2u) |
                      (SCU_WDTCPU0CON0.B.REL << 16u);

    /* read back ENDINIT and wait until it has been cleared */
    while (SCU_WDTCPU0CON0.B.ENDINIT == 0)
    {}

    GTM_CTRL.B.RF_PROT = 0;
    GTM_CLS_CLK_CFG.B.CLS0_CLK_DIV = 1;
    GTM_CLS_CLK_CFG.B.CLS1_CLK_DIV = 1;
    GTM_CTRL.B.RF_PROT = 1;

    GTM_CMU_CLK_EN.U = 0x00555555;
    /* fgtm = 200Mhz */
    /* CMU = fgtm * z / n */
    /* z = 1 */
    GTM_CMU_GCLK_NUM.B.GCLK_NUM = 1;
    /* n = 1 */
    GTM_CMU_GCLK_DEN.B.GCLK_DEN = 1;

    Gtm_TomInit();

    Gtm_TimInit();
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void Gtm_StartTOM(void)
{
    GTM_CMU_CLK_EN.U = 0x008000AA;
#if 1
    /* TOM0 init */
    /* ch0 - ch7 */
    GTM_TOM0_TGC0_GLB_CTRL.U = 0x2AA00000;
    GTM_TOM0_TGC0_OUTEN_CTRL.U = 0x00005555;
    GTM_TOM0_TGC0_OUTEN_STAT.U = 0x00005555;
    GTM_TOM0_TGC0_ENDIS_CTRL.U = 0x00002AA0;
    GTM_TOM0_TGC0_ENDIS_STAT.U = 0x00002AA0;
    /* TOM1 init */
    /* ch0 - ch7 */
    GTM_TOM1_TGC0_GLB_CTRL.U = 0xA8000000;
    GTM_TOM1_TGC0_OUTEN_CTRL.U = 0x00005555;
    GTM_TOM1_TGC0_OUTEN_STAT.U = 0x00005555;
    GTM_TOM1_TGC0_ENDIS_CTRL.U = 0x0000A800;
    GTM_TOM1_TGC0_ENDIS_STAT.U = 0x0000A800;
    /* ch8 - ch15 */
    GTM_TOM1_TGC1_GLB_CTRL.U = 0x28000000;
    GTM_TOM1_TGC1_OUTEN_CTRL.U = 0x00002800;
    GTM_TOM1_TGC1_OUTEN_STAT.U = 0x00002800;
    GTM_TOM1_TGC1_ENDIS_CTRL.U = 0x00002800;
    GTM_TOM1_TGC1_ENDIS_STAT.U = 0x00002800;
#endif

    GTM_TIM2_CH0_CTRL.B.TIM_EN = 1;
    GTM_TIM2_CH2_CTRL.B.TIM_EN = 1;
    GTM_TIM2_CH3_CTRL.B.TIM_EN = 1;
    GTM_TIM2_CH5_CTRL.B.TIM_EN = 1;
    GTM_TIM2_CH6_CTRL.B.TIM_EN = 1;
    GTM_TIM2_CH7_CTRL.B.TIM_EN = 1;
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void Gtm_EnablePwm01(uint8 status)
{
    if(status > 0)
    {
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 = 2;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT4 = 2;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 2;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 2;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 2;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 2;
        GTM_CDTM0_DTM1_CH_CTRL2.U = 0x00888888;
        GTM_CDTM0_DTM1_CH0_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH0_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH1_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH1_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH2_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH2_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    }
    else
    {
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT4 = 1;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 1;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 1;
        GTM_CDTM0_DTM1_CH_CTRL2.U = 0x00222222;
        GTM_CDTM0_DTM1_CH0_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH0_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH1_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH1_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH2_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM0_DTM1_CH2_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    }
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void Gtm_EnablePwm02(uint8 status)
{
    if(status > 0)
    {
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 2;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 2;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 2;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 2;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = 2;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT7 = 2;
        GTM_CDTM1_DTM1_CH_CTRL2.U = 0x88888800;
        GTM_CDTM1_DTM1_CH1_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH1_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH2_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH2_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH3_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH3_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    }
    else
    {
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 1;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 1;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT7 = 1;
        GTM_CDTM1_DTM1_CH_CTRL2.U = 0x22222200;
        GTM_CDTM1_DTM1_CH1_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH1_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH2_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH2_DTV.B.RELRISE = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH3_DTV.B.RELFALL = GTM_DEADTIME_500NS;
        GTM_CDTM1_DTM1_CH3_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    }
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void Gtm_SetPwm01(uint16 u, uint16 v, uint16 w)
{
    if(u > 0)
    {
        GTM_TOM0_CH4_SR0.B.SR0 = 10000 - u;
        GTM_TOM0_CH4_SR1.B.SR1 = u;
    }
    else
    {
        GTM_TOM0_CH4_SR0.B.SR0 = 10001;
        GTM_TOM0_CH4_SR1.B.SR1 = 0;
    }

    if(v > 0)
    {
        GTM_TOM0_CH6_SR0.B.SR0 = 10000 - v;
        GTM_TOM0_CH6_SR1.B.SR1 = v;
    }
    else
    {
        GTM_TOM0_CH6_SR0.B.SR0 = 10001;
        GTM_TOM0_CH6_SR1.B.SR1 = 0;
    }

    if(w > 0)
    {
        GTM_TOM0_CH5_SR0.B.SR0 = 10000 - w;
        GTM_TOM0_CH5_SR1.B.SR1 = w;
    }
    else
    {
        GTM_TOM0_CH5_SR0.B.SR0 = 10001;
        GTM_TOM0_CH5_SR1.B.SR1 = 0;
    }
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void Gtm_SetPwm02(uint16 u, uint16 v, uint16 w)
{
    if(u > 0)
    {
        GTM_TOM1_CH7_SR0.B.SR0 = 10000 - u;
        GTM_TOM1_CH7_SR1.B.SR1 = u;
    }
    else
    {
        GTM_TOM1_CH7_SR0.B.SR0 = 10001;
        GTM_TOM1_CH7_SR1.B.SR1 = 0;
    }

    if(v > 0)
    {
        GTM_TOM1_CH6_SR0.B.SR0 = 10000 - v;
        GTM_TOM1_CH6_SR1.B.SR1 = v;
    }
    else
    {
        GTM_TOM1_CH6_SR0.B.SR0 = 10001;
        GTM_TOM1_CH6_SR1.B.SR1 = 0;
    }

    if(w > 0)
    {
        GTM_TOM1_CH5_SR0.B.SR0 = 10000 - w;
        GTM_TOM1_CH5_SR1.B.SR1 = w;
    }
    else
    {
        GTM_TOM1_CH5_SR0.B.SR0 = 10001;
        GTM_TOM1_CH5_SR1.B.SR1 = 0;
    }
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
static void Gtm_TomInit(void)
{
#if 0
    /* TOM1 init */
    /* ch0 - ch7 */
    GTM_TOM1_TGC0_GLB_CTRL.U = 0xAAAA0000;
    GTM_TOM1_TGC0_OUTEN_CTRL.U = 0x00005556;
    GTM_TOM1_TGC0_OUTEN_STAT.U = 0x00005556;
    GTM_TOM1_TGC0_ENDIS_CTRL.U = 0x0000AAAA;
    GTM_TOM1_TGC0_ENDIS_STAT.U = 0x0000AAAA;
    /* ch8 - ch15 */
    GTM_TOM1_TGC1_GLB_CTRL.U = 0x28000000;
    GTM_TOM1_TGC1_OUTEN_CTRL.U = 0x000028000;
    GTM_TOM1_TGC1_OUTEN_STAT.U = 0x000002800;
    GTM_TOM1_TGC1_ENDIS_CTRL.U = 0x00002800;
    GTM_TOM1_TGC1_ENDIS_STAT.U = 0x00002800;
#endif
    /* pwm channel init */
    /* channel 0 用于同步 200Mhz  10000代表50us */
    GTM_TOM0_CH2_CTRL.U = 0x01000000;
    GTM_TOM0_CH2_CN0.B.CN0 = 0;
    GTM_TOM0_CH2_CM0.B.CM0 = 10000;
    GTM_TOM0_CH2_CM1.B.CM1 = 5000;
    GTM_TOM0_CH2_SR0.B.SR0 = 10000;
    GTM_TOM0_CH2_SR1.B.SR1 = 5000;


    /* channel 1 */
    GTM_TOM0_CH3_CTRL.U = 0x00100800;

    /* channel 4,5,6 用于控制A路  */
    GTM_TOM0_CH4_CTRL.U = 0x00100800;
    GTM_TOM0_CH4_CN0.B.CN0 = 0;
    GTM_TOM0_CH4_CM0.B.CM0 = 7500;
    GTM_TOM0_CH4_CM1.B.CM1 = 2500;
    GTM_TOM0_CH4_SR0.B.SR0 = 7500;
    GTM_TOM0_CH4_SR1.B.SR1 = 2500;

    /* channel 5 */
    GTM_TOM0_CH5_CTRL.U = 0x00100800;
    GTM_TOM0_CH5_CN0.B.CN0 = 0;
    GTM_TOM0_CH5_CM0.B.CM0 = 7500;
    GTM_TOM0_CH5_CM1.B.CM1 = 2500;
    GTM_TOM0_CH5_SR0.B.SR0 = 7500;
    GTM_TOM0_CH5_SR1.B.SR1 = 2500;

    /* channel 6 */
    GTM_TOM0_CH6_CTRL.U = 0x00100800;
    GTM_TOM0_CH6_CN0.B.CN0 = 0;
    GTM_TOM0_CH6_CM0.B.CM0 = 7500;
    GTM_TOM0_CH6_CM1.B.CM1 = 2500;
    GTM_TOM0_CH6_SR0.B.SR0 = 7500;
    GTM_TOM0_CH6_SR1.B.SR1 = 2500;

    GTM_TOM0_CH7_CTRL.U = 0x00100800;
    GTM_TOM0_CH8_CTRL.U = 0x00100800;
    GTM_TOM0_CH9_CTRL.U = 0x00100800;
    GTM_TOM0_CH10_CTRL.U = 0x00100800;
    GTM_TOM0_CH11_CTRL.U = 0x00100800;
    GTM_TOM0_CH12_CTRL.U = 0x00100800;

    GTM_TOM0_CH13_CTRL.U = 0x00100800;
    GTM_TOM0_CH14_CTRL.U = 0x00100800;
    GTM_TOM1_CH0_CTRL.U = 0x00100800;
    GTM_TOM1_CH1_CTRL.U = 0x00100800;
    GTM_TOM1_CH2_CTRL.U = 0x00100800;
    GTM_TOM1_CH3_CTRL.U = 0x00100800;
    GTM_TOM1_CH4_CTRL.U = 0x00100800;

    /* channel 5,6,7 用于控制B路  */
    /* channel 5 */
    GTM_TOM1_CH5_CTRL.U = 0x00100800;
    GTM_TOM1_CH5_CN0.B.CN0 = 0;
    GTM_TOM1_CH5_CM0.B.CM0 = 7500;
    GTM_TOM1_CH5_CM1.B.CM1 = 2500;
    GTM_TOM1_CH5_SR0.B.SR0 = 4950;
    GTM_TOM1_CH5_SR1.B.SR1 = 1650;

    /* channel 6 */
    GTM_TOM1_CH6_CTRL.U = 0x00100800;
    GTM_TOM1_CH6_CN0.B.CN0 = 0;
    GTM_TOM1_CH6_CM0.B.CM0 = 7500;
    GTM_TOM1_CH6_CM1.B.CM1 = 2500;
    GTM_TOM1_CH6_SR0.B.SR0 = 7500;
    GTM_TOM1_CH6_SR1.B.SR1 = 2500;

    /* channel 7 */
    GTM_TOM1_CH7_CTRL.U = 0x00100800;
    GTM_TOM1_CH7_CN0.B.CN0 = 0;
    GTM_TOM1_CH7_CM0.B.CM0 = 7500;
    GTM_TOM1_CH7_CM1.B.CM1 = 2500;
    GTM_TOM1_CH7_SR0.B.SR0 = 7500;
    GTM_TOM1_CH7_SR1.B.SR1 = 2500;

    /* channel 8 */
    GTM_TOM1_CH8_CTRL.U = 0x00100800;
    GTM_TOM1_CH9_CTRL.U = 0x00100800;
    GTM_TOM1_CH10_CTRL.U = 0x00100800;
    GTM_TOM1_CH11_CTRL.U = 0x00100800;
    GTM_TOM1_CH12_CTRL.U = 0x00100800;

    /* channel 13 Adc trigger */
    GTM_TOM1_CH13_CTRL.U = 0x00100800;
    GTM_TOM1_CH13_CN0.B.CN0 = 0;
    GTM_TOM1_CH13_CM0.B.CM0 = 7500;
    GTM_TOM1_CH13_CM1.B.CM1 = 5300;
    GTM_TOM1_CH13_SR0.B.SR0 = 7500;
    GTM_TOM1_CH13_SR1.B.SR1 = 5300;

    /* 100 us isr task*/
    GTM_TOM1_CH14_CTRL.U = 0x01000000;
    GTM_TOM1_CH14_CN0.B.CN0 = 0;
    GTM_TOM1_CH14_CM0.B.CM0 = 20000;
    GTM_TOM1_CH14_CM1.B.CM1 = 10000;
    GTM_TOM1_CH14_SR0.B.SR0 = 20000;
    GTM_TOM1_CH14_SR1.B.SR1 = 10000;
    GTM_TOM1_CH14_IRQ_MODE.B.IRQ_MODE = 2;
    GTM_TOM1_CH14_IRQ_EN.B.CCU0TC_IRQ_EN = 1;


    GTM_CDTM0_DTM1_CTRL.B.CLK_SEL = 2;
    GTM_CDTM0_DTM1_CH_CTRL1.U = 0;
    GTM_CDTM0_DTM1_CH_CTRL2.U = 0x00222222;
    GTM_CDTM0_DTM1_CH0_DTV.B.RELFALL = GTM_DEADTIME_500NS;
    GTM_CDTM0_DTM1_CH0_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    GTM_CDTM0_DTM1_CH1_DTV.B.RELFALL = GTM_DEADTIME_500NS;
    GTM_CDTM0_DTM1_CH1_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    GTM_CDTM0_DTM1_CH2_DTV.B.RELFALL = GTM_DEADTIME_500NS;
    GTM_CDTM0_DTM1_CH2_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    GTM_CDTM1_DTM1_CTRL.B.CLK_SEL = 2;
    GTM_CDTM1_DTM1_CH_CTRL1.U = 0;
    GTM_CDTM1_DTM1_CH_CTRL2.U = 0x22222200;
    GTM_CDTM1_DTM1_CH1_DTV.B.RELFALL = GTM_DEADTIME_500NS;
    GTM_CDTM1_DTM1_CH1_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    GTM_CDTM1_DTM1_CH2_DTV.B.RELFALL = GTM_DEADTIME_500NS;
    GTM_CDTM1_DTM1_CH2_DTV.B.RELRISE = GTM_DEADTIME_500NS;
    GTM_CDTM1_DTM1_CH3_DTV.B.RELFALL = GTM_DEADTIME_500NS;
    GTM_CDTM1_DTM1_CH3_DTV.B.RELRISE = GTM_DEADTIME_500NS;

    /* P02.0 TOM0_4 */
    GTM_TOUTSEL0.B.SEL0 = 6;
    /* P02.1 TOM0_4N */
    GTM_TOUTSEL0.B.SEL1 = 6;
    /* P02.2 TOM0_5 */
    GTM_TOUTSEL0.B.SEL2 = 6;
    /* P02.3 TOM0_5N */
    GTM_TOUTSEL0.B.SEL3 = 6;
    /* P2.4 TOM0_6 */
    GTM_TOUTSEL0.B.SEL4 = 6;
    /* P2.5 TOM0_6N */
    GTM_TOUTSEL0.B.SEL5 = 6;
    /* P11.3 TOM1_5 */
    GTM_TOUTSEL12.B.SEL0 = 7;
    /* P11.6 TOM1_5N */
    GTM_TOUTSEL12.B.SEL1 = 7;
    /* P11.9 TOM1_6 */
    GTM_TOUTSEL12.B.SEL2 = 7;
    /* P11.10 TOM1_6N */
    GTM_TOUTSEL12.B.SEL3 = 7;
    /* P11.12 TOM1_7 */
    GTM_TOUTSEL12.B.SEL5 = 7;
    /* P11.11 TOM1_7N */
    GTM_TOUTSEL12.B.SEL4 = 7;


    GTM_ADCTRIG1OUT0.B.SEL0 = 3;
    GTM_ADCTRIG1OUT0.B.SEL1 = 3;
    GTM_ADCTRIG1OUT0.B.SEL3 = 3;
    GTM_ADCTRIG1OUT1.B.SEL0 = 3;
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
static void Gtm_TimInit(void)
{
    /* 25Mhz */
    GTM_CMU_CLK_3_CTRL.B.CLK_CNT = 1;

    /* ch0 PreDriver A SAL */
    /* clk3,  filter mode, level high measurement, cnt as input */
    GTM_TIM2_CH0_CTRL.U = 0x03532F00;
    GTM_TIM2_CH0_FLT_FE.U = 0xA0;
    GTM_TIM2_CH0_FLT_RE.U = 0xA0;

    /* ch2 PreDriver A SBL */
    /* clk3,  filter mode, level high measurement, cnt as input */
    GTM_TIM2_CH2_CTRL.U = 0x03532F00;
    GTM_TIM2_CH2_FLT_FE.U = 0xA0;
    GTM_TIM2_CH2_FLT_RE.U = 0xA0;

    /* ch3 PreDriver A SCL */
    /* clk3,  filter mode, level high measurement, cnt as input */
    GTM_TIM2_CH3_CTRL.U = 0x03532F00;
    GTM_TIM2_CH3_FLT_FE.U = 0xA0;
    GTM_TIM2_CH3_FLT_RE.U = 0xA0;

    /* ch5 PreDriver B SAL */
    /* clk3,  filter mode, level high measurement, cnt as input */
    GTM_TIM2_CH5_CTRL.U = 0x03532F00;
    GTM_TIM2_CH5_FLT_FE.U = 0xA0;
    GTM_TIM2_CH5_FLT_RE.U = 0xA0;

    /* ch6 PreDriver B SBL */
    /* clk3,  filter mode, level high measurement, cnt as input */
    GTM_TIM2_CH6_CTRL.U = 0x03532F00;
    GTM_TIM2_CH6_FLT_FE.U = 0xA0;
    GTM_TIM2_CH6_FLT_RE.U = 0xA0;

    /* ch7 PreDriver B SCL */
    /* clk3,  filter mode, level high measurement, cnt as input */
    GTM_TIM2_CH7_CTRL.U = 0x03532F00;
    GTM_TIM2_CH7_FLT_FE.U = 0xA0;
    GTM_TIM2_CH7_FLT_RE.U = 0xA0;

    /* P13.3 P20.14 P15.0 P13.0 P13.1 P20.11 */
    GTM_TIM2INSEL.B.CH0SEL = 3;
    GTM_TIM2INSEL.B.CH2SEL = 4;
    GTM_TIM2INSEL.B.CH3SEL = 4;
    GTM_TIM2INSEL.B.CH5SEL = 3;
    GTM_TIM2INSEL.B.CH6SEL = 3;
    GTM_TIM2INSEL.B.CH7SEL = 6;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
uint16 Gtm_TimGetPwmDuty(GTM_TIMChannelType channel)
{
	Ifx_GTM_TIM_CH_IRQ_NOTIFY *irq_notify;
    Ifx_GTM_TIM_CH_GPR1 * gpr1;
    Ifx_GTM_TIM_CH_GPR0 * gpr0;
    uint16 duty = 0;

    irq_notify = (Ifx_GTM_TIM_CH_IRQ_NOTIFY *)((uint32)0xF0101000u + 0x102Cu +
            + (uint32)channel * 0x80u);

    gpr1 = (Ifx_GTM_TIM_CH_GPR1 *)((uint32)0xF0101000u + 0x1004u +
            + (uint32)channel * 0x80u);

    gpr0 = (Ifx_GTM_TIM_CH_GPR0 *)((uint32)0xF0101000u + 0x1000u +
            + (uint32)channel * 0x80u);

    if(irq_notify->B.NEWVAL > 0)
    {
        if(gpr1->B.GPR1 > 0)
        {
            duty = (uint16)(10000 * (uint32)gpr0->B.GPR0 /gpr1->B.GPR1);
        }
        else
        {
            duty = 0;
        }
        irq_notify->B.NEWVAL = 1;
    }
    else
    {
        if(irq_notify->B.CNTOFL > 0)
        {
            duty = 10000;
            irq_notify->B.CNTOFL = 1;
        }
        else
        {
            duty = 0;
        }
    }

    return duty;
}
