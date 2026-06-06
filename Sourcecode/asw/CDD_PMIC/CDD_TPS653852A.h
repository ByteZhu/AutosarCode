/*
 * CDD_TPS653852A.h
 *
 *  Created on: 2023Äê7ÔÂ17ÈÕ
 *      Author: tiand
 */

#ifndef SOURCECODE_ASW_CDD_TPS653852A_CDD_TPS653852A_H_
#define SOURCECODE_ASW_CDD_TPS653852A_CDD_TPS653852A_H_
#include "common.h"

typedef union
{
	uint16 word;
	struct
	{
		uint16 VBAT_OV : 1; //0
		uint16 VBAT_UV : 1; //1
		uint16 VCP_UV : 1;  //2
		uint16 VDD6_OV : 1; //3
		uint16 VDD6_UV : 1; //4
		uint16 VDD5_OV : 1; //5
		uint16 VDD5_UV : 1; //6
		uint16 VDD35_OV : 1;//7

		uint16 VDD35_UV : 1;//8
		uint16 VREG_UV : 1; //9
		uint16 VDD6_LP_UV : 1;//10
		uint16 VSOUT1_OV : 1;//11
		uint16 VSOUT1_UV : 1;//12
		uint16 VSOUT2_OV : 1;//13
		uint16 VSOUT2_UV : 1;//14
		uint16 RSV : 1;
	}bits;
}TPS653852A_VoltFaultType;

extern TPS653852A_VoltFaultType TPS653832A_VoltFault;

extern void CDD_TPS653852A_Init(void);

extern void CDD_TPS653852A_MainFunction(void);

extern void CDD_TPS653832A_PowerDown(void);

#endif /* SOURCECODE_ASW_CDD_TPS653852A_CDD_TPS653852A_H_ */
