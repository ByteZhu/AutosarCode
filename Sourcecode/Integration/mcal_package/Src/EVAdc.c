/*
 * EVAdc.c
 *
 *  Created on: 2021Äê7ÔÂ21ÈÕ
 *      Author: TIAN
 */

#include "Ifx_reg.h"
#include "EVadc.h"

#define TIAN_ADC_DEBUG      0
#include "Dio.h"
#if TIAN_ADC_DEBUG
#define INTERRUPT_ADC_ISR0_PRIORITY    245

#endif
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void EVAdc_Init(void)
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
    EVADC_CLC.B.DISR = 0;
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

    /* fADCI = 200MHz */
    EVADC_GLOBCFG.U = 0x80008001;

    EVADC_G0ARBCFG.U = 0x00000003;
    EVADC_G1ARBCFG.U = 0x00000003;
    EVADC_G2ARBCFG.U = 0x00000003;
    EVADC_G3ARBCFG.U = 0x00000003;
    EVADC_G8ARBCFG.U = 0x00000003;

    EVADC_G0ARBPR.U = 0x0700000B;
    EVADC_G1ARBPR.U = 0x0700000B;
    EVADC_G2ARBPR.U = 0x0700000B;
    EVADC_G3ARBPR.U = 0x0700000B;
    EVADC_G8ARBPR.U = 0x0700000B;

    EVADC_G0CHCTR0.U = 0x00000000;
    EVADC_G0CHCTR1.U = 0x00010000;
    EVADC_G0CHCTR2.U = 0x00020000;
    EVADC_G0CHCTR4.U = 0x00040000;
    EVADC_G0CHCTR6.U = 0x00060000;
    EVADC_G0CHCTR7.U = 0x00070000;

    EVADC_G1CHCTR1.U = 0x00010000;
    EVADC_G1CHCTR2.U = 0x00020000;
    EVADC_G1CHCTR3.U = 0x00030000;
    EVADC_G1CHCTR4.U = 0x00040000;
    EVADC_G1CHCTR5.U = 0x00050000;
    EVADC_G1CHCTR6.U = 0x00060000;
    EVADC_G1CHCTR7.U = 0x00070000;

    EVADC_G2CHCTR0.U = 0x00000000;
    EVADC_G2CHCTR1.U = 0x00010000;

    EVADC_G3CHCTR0.U = 0x00000000;

    EVADC_G8CHCTR0.U = 0x00000000;
    EVADC_G8CHCTR4.U = 0x00040000;
    EVADC_G8CHCTR5.U = 0x00050000;

    /* AD0 queue */
    /* trigger mode, tom1 ch7 */
    EVADC_G0QCTRL0.U = 0x0081AF00;
    EVADC_G0QMR0.U = 0x00000405;
    EVADC_G0QINR0.U = 0x000000A1;

    EVADC_G1QCTRL0.U = 0x0081AF00;
    EVADC_G1QMR0.U = 0x00000405;
    EVADC_G1QINR0.U = 0x000000A3;
    EVADC_G1QINR0.U = 0x000000A5;

    EVADC_G3QCTRL0.U = 0x0081AF00;
    EVADC_G3QMR0.U = 0x00000405;
    EVADC_G3QINR0.U = 0x000000A0;

    EVADC_G8QCTRL0.U = 0x0081AF00;
    EVADC_G8QMR0.U = 0x00000405;
    EVADC_G8QINR0.U = 0x000000A4;
    EVADC_G8QINR0.U = 0x000000A5;

    EVADC_G0QCTRL1.U = 0x00000000;
    EVADC_G0QMR1.U = 0x00000405;
    EVADC_G0QINR1.U = 0x00000020;
    EVADC_G0QINR1.U = 0x00000022;
    EVADC_G0QINR1.U = 0x00000024;
    EVADC_G0QINR1.U = 0x00000026;
    EVADC_G0QINR1.U = 0x00000027;

    EVADC_G1QCTRL1.U = 0x00000000;
    EVADC_G1QMR1.U = 0x00000405;
    EVADC_G1QINR1.U = 0x00000021;
    EVADC_G1QINR1.U = 0x00000022;
    EVADC_G1QINR1.U = 0x00000024;
    EVADC_G1QINR1.U = 0x00000026;
    EVADC_G1QINR1.U = 0x00000027;

    EVADC_G2QCTRL1.U = 0x00000000;
    EVADC_G2QMR1.U = 0x00000405;
    EVADC_G2QINR1.U = 0x00000020;
    EVADC_G2QINR1.U = 0x00000021;

    EVADC_G8QCTRL1.U = 0x00000000;
    EVADC_G8QMR1.U = 0x00000405;
    EVADC_G8QINR1.U = 0x00000020;

#if TIAN_ADC_DEBUG
    EVADC_G8RCR5.B.SRGEN = 1;
 //   EVADC_G0REVNP0.B.REV1NP = 1;
    SRC_VADCG8SR0.B.SRPN = INTERRUPT_ADC_ISR0_PRIORITY;
    SRC_VADCG8SR0.B.CLRR = 1;
    SRC_VADCG8SR0.B.SRE = 1;
#endif
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void EVAdc_Start(void)
{
    EVADC_G0QMR1.B.TREV = 1;
    EVADC_G1QMR1.B.TREV = 1;
    EVADC_G2QMR1.B.TREV = 1;
    EVADC_G3QMR1.B.TREV = 1;
    EVADC_G8QMR1.B.TREV = 1;
}
#if TIAN_ADC_DEBUG
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
****************************************************************/
void __interrupt(INTERRUPT_ADC_ISR0_PRIORITY) __vector_table(0) __bisr_(INTERRUPT_ADC_ISR0_PRIORITY) EVAdc_ResIsr0(void)
{
	static uint8 flag = 0;

	if(flag == 0)
	{
		flag = 1;
		Dio_WriteChannel(DioConf_DioChannel_P15_3, STD_LOW);
	}
	else
	{
		flag = 0;
		Dio_WriteChannel(DioConf_DioChannel_P15_3, STD_HIGH);
	}
}
#endif
