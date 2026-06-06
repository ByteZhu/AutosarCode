/*
 * portability.c
 *
 *  Created on: 2020-8-27
 *      Author: TIAN
 */
#include "Common.h"
#include "portability.h"
#include "CalVar.h"
#include "IoHwAb.h"
#include "EPS_TL_lut.h"
#include "GlobalVarCAN.h"
#include "GlobalVarSupport.h"
#include "MotorAdvanced.h"
#include "look1_is16ls32n10ts16D_PDzFBkZ7.h"
#include "AssistControl.h"
#include "CalVarSupport.h"
#include "Sent.h"
#include "Ifx_reg.h"
#include "EepromData.h"
#include "CCP_Table.h"
#if defined(ENABLE_CHECKSUM_AND_COUNTER)
GLOBAL UInt8 fsSystemCANRevChecksumOrCrc[kCanNumberOfRxObjects] = {0,};
GLOBAL UInt8 fsSystemCANRevMsgCounter[kCanNumberOfRxObjects] = {0,};
GLOBAL UInt8 fsSystemCANRevDLC[kCanNumberOfRxObjects] = {0,};
#endif

extern void OffCenterSAT(void);
extern void ToruqeNotchFilter(void);
extern void TorqueSoftAdv2(void);
extern void RobustfilterFun(void);
extern void OnCenterKick(void);
extern void ToruqeStableFilter(void);
extern void TorqueSoftAdv(void);

/****************************************************************
* FUNCTION : 
* DESCRIPTION : M(x)=x8*D(x)+xn+x(n+1)+...+x(n+7),
				P(x)=x8+x4+x3+x2+1,R(x)=M(x)/P(x),inv(R(x))
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
UInt8 CRC8forSAEJ1850(UInt8 *u8_data,UInt8 u8_len)
{
    UInt8 i, j;
    UInt8 u8_crc8;
    UInt8 u8_poly;
    //CRC initialization to D (x) the highest 8 bit will be taken against
    u8_crc8 = 0xFF;
    //Ignore the highest bit D (x) = x8+x4+x3+x2+1,b00011101, conform to the J1850
    u8_poly = 0x1D;

    for (i = 0; i < u8_len; i++)
    {
        //Performed for the first time, take the top eight,
        //by xn+x(n+1)+...+x(n+7) implementation;Continuous execution time,
        //every time the CRC is calculated for the current byte as high eight,
        //low 8 bit is 0 the result, the equivalent of A(x)/P(x)=A1(x)/P(x)/A2(x)
        //The A1 is A low 8 bit is set to 0, A2 as A high 8 bit is set to 0
        u8_crc8 ^= u8_data[i];

        for (j = 0; j < 8; j++)
        {
            //Determine whether the need for Modulo 2 division
            if (u8_crc8 & 0x80)
            {
                //Highest bit abandon, x8 of P (x) also dropped, judge condition if meet the conditions,
                //the highest bit is 1. The left after the bitwise XOR(modulo 2 division), assigned to CRC
                u8_crc8 = (UInt8)(((UInt8)(u8_crc8 << 1)) ^ u8_poly);
            }
            else
            {
                //Don't need to carry on the division, judge the next bit
                u8_crc8 <<= 1;
            }
        }
    }
    //Take the NOT of CRC
    u8_crc8 ^= (UInt8)0xFF;
    return u8_crc8;
}
UInt8 CRC8forBYD(UInt8 *u8_data,UInt8 u8_len)
{
    UInt8 i, j;
    UInt8 u8_crc8;
    UInt8 u8_poly;
    //CRC initialization to D (x) the highest 8 bit will be taken against
    u8_crc8 = 0x00;
    //Ignore the highest bit D (x) = x8+x4+x3+x2+1,b00011101, conform to the J1850
    u8_poly = 0x1D;

    for (i = 0; i < u8_len; i++)
    {
        //Performed for the first time, take the top eight,
        //by xn+x(n+1)+...+x(n+7) implementation;Continuous execution time,
        //every time the CRC is calculated for the current byte as high eight,
        //low 8 bit is 0 the result, the equivalent of A(x)/P(x)=A1(x)/P(x)/A2(x)
        //The A1 is A low 8 bit is set to 0, A2 as A high 8 bit is set to 0
        u8_crc8 ^= u8_data[i];

        for (j = 0; j < 8; j++)
        {
            //Determine whether the need for Modulo 2 division
            if (u8_crc8 & 0x80)
            {
                //Highest bit abandon, x8 of P (x) also dropped, judge condition if meet the conditions,
                //the highest bit is 1. The left after the bitwise XOR(modulo 2 division), assigned to CRC
                u8_crc8 = (UInt8)(((UInt8)(u8_crc8 << 1)) ^ u8_poly);
            }
            else
            {
                //Don't need to carry on the division, judge the next bit
                u8_crc8 <<= 1;
            }
        }
    }
    //Take the NOT of CRC
    u8_crc8 ^= (UInt8)0x00;
    return u8_crc8;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
UInt8 CheckSumGeely(UInt8 *u8_data,UInt8 u8_len)
{
	UInt8 i = 0;
	UInt8 u8_crc8 = 0;

	for(i = 0; i < u8_len; i++)
	{
		u8_crc8 ^= u8_data[i];
	}
	return u8_crc8;
}
#if 1
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void UpdateReceiveMessageCounter(void)
{
    UInt8 i = 1;

    for(i = 1;i < CAN_SIGNAL_NUM;i++)
    {
    	if(fsSystemCANReciveCounter[i] < 10000)
    	{
    		fsSystemCANReciveCounter[i]++;
    	}
    	else
    	{
    		fsSystemCANReciveCounter[i] = 0;
    	}

	    if(Fv_SystemCANReciveStatus[i])
    	{
	    	Fv_SystemCANReciveStatus[i] = 0;

    		Fv_SystemCANReciveTimer[i] = 0;

	    	fsSystemCANReciveCounter[i] = 0;
    	}
    	else
    	{
    		if(fsSystemCANReciveCounter[i] >= fsSystemCANDiagTimes[i])
    		{
    			Fv_SystemCANReciveTimer[i] = fsSystemCANDiagTimes[i];
    		}
    	}
    }
#if 0
	if(Fv_ABSVSReciveFlag)
	{
		Fv_ABSVSReciveFlag = 0;
		Fv_ABSVSReciveTimer = 0;
	}
	else
	{
		if(Fv_ABSVSReciveTimer < fsSystemCANDiagTimes[CANBUS_ABSVs] + 1)
		{
			Fv_ABSVSReciveTimer++;
		}
	}

	if(Fv_EMSVSReciveFlag)
	{
		Fv_EMSVSReciveFlag = 0;
		Fv_EMSVSReciveTimer = 0;
	}
	else
	{	
		if(Fv_EMSVSReciveTimer < fsSystemCANDiagTimes[CANBUS_EMSEt] + 1)
		{
			Fv_EMSVSReciveTimer++;
		}
	}
#endif
}
#endif
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void SetPhaseIndp1(uint8 v)
{
	if(v == 0)
	{
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 = 2;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT4 = 2;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 1;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 1;
        GTM_CDTM0_DTM1_CH_CTRL2.U = 0x00222288;
	}
	else if(v == 1)
	{
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT4 = 1;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 2;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 2;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 1;
        GTM_CDTM0_DTM1_CH_CTRL2.U = 0x00228822;
	}
	else if(v == 2)
	{
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT4 = 1;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 1;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 1;
        GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 2;
        GTM_TOM0_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 2;
        GTM_CDTM0_DTM1_CH_CTRL2.U = 0x00882222;
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
	}
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void SetPhaseIndp2(uint8 v)
{
	if(v == 0)
	{
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 2;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 2;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 1;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT7 = 1;
        GTM_CDTM1_DTM1_CH_CTRL2.U = 0x22228800;
	}
	else if(v == 1)
	{
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 1;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 2;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 2;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT7 = 1;
        GTM_CDTM1_DTM1_CH_CTRL2.U = 0x22882200;
	}
	else if(v == 2)
	{
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT5 = 1;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = 1;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT6 = 1;
        GTM_TOM1_TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = 2;
        GTM_TOM1_TGC0_OUTEN_STAT.B.OUTEN_STAT7 = 2;
        GTM_CDTM1_DTM1_CH_CTRL2.U = 0x88222200;
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
	}
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void GetPrediverPwmDuty(void)
{
	IO_UphaseDuty1 = Gtm_TimGetPwmDuty(GTM_TIM_CH_7);
	IO_VphaseDuty1 = Gtm_TimGetPwmDuty(GTM_TIM_CH_2);
	IO_WphaseDuty1 = Gtm_TimGetPwmDuty(GTM_TIM_CH_3);
	IO_UphaseDuty2 = Gtm_TimGetPwmDuty(GTM_TIM_CH_5);
	IO_VphaseDuty2 = Gtm_TimGetPwmDuty(GTM_TIM_CH_6);
	IO_WphaseDuty2 = Gtm_TimGetPwmDuty(GTM_TIM_CH_0);
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void EpsTrqFilter(void)
{
   /* SFStaticLocalInit: Default storage class for static local variables with initvalue | Width: 16
    */
   static UInt16 Ca61_data1[10] =
   {
      /*[0..9]*/ 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000
      /* 10000., 10000., 10000., 10000., 10000., 10000., 10000., 10000., 10000., 10000. */
   } /*  MIN/MAX:  0 .. 10000 */;
   static UInt16 Ca61_data2[10] =
   {
      /*[0..9]*/ 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000
      /* 10000., 10000., 10000., 10000., 10000., 10000., 10000., 10000., 10000., 10000. */
   } /*  MIN/MAX:  0 .. 10000 */;

   /* Begin execution of chart EPS_TL/EPS_torquefilter/EpsTrqFilter_fun */
   Ca61_data1[9] = Ca61_data1[8];
   Ca61_data1[8] = Ca61_data1[7];
   Ca61_data1[7] = Ca61_data1[6];
   Ca61_data1[6] = Ca61_data1[5];
   Ca61_data1[5] = Ca61_data1[4];
   Ca61_data1[4] = Ca61_data1[3];
   Ca61_data1[3] = Ca61_data1[2];
   Ca61_data1[2] = Ca61_data1[1];
   Ca61_data1[1] = Ca61_data1[0];
   Ca61_data1[0] = IOC_Tor1Duty;
   Ca61_data2[9] = Ca61_data2[8];
   Ca61_data2[8] = Ca61_data2[7];
   Ca61_data2[7] = Ca61_data2[6];
   Ca61_data2[6] = Ca61_data2[5];
   Ca61_data2[5] = Ca61_data2[4];
   Ca61_data2[4] = Ca61_data2[3];
   Ca61_data2[3] = Ca61_data2[2];
   Ca61_data2[2] = Ca61_data2[1];
   Ca61_data2[1] = Ca61_data2[0];
   Ca61_data2[0] = IOC_Tor2Duty;

   /* End execution of chart EPS_TL/EPS_torquefilter/EpsTrqFilter_fun */

   /* TargetLink outport: EPS_TL/EPS_torquefilter/Tfr2 */
   AD_SubTorque = (UInt16)((((UInt32) Ca61_data2[0]) + ((UInt32) Ca61_data2[1]) + ((UInt32) Ca61_data2[2]) +
    ((UInt32) Ca61_data2[3]) + ((UInt32) Ca61_data2[4]) + ((UInt32) Ca61_data2[5]) + ((UInt32)
    Ca61_data2[6]) + ((UInt32) Ca61_data2[7]) + ((UInt32) Ca61_data2[8]) + ((UInt32) Ca61_data2[9]))
     / 10);

   /* TargetLink outport: EPS_TL/EPS_torquefilter/Tfr1 */
   AD_MainTorque = (UInt16)((((UInt32) Ca61_data1[0]) + ((UInt32) Ca61_data1[1]) + ((UInt32) Ca61_data1[2]) +
     ((UInt32) Ca61_data1[3]) + ((UInt32) Ca61_data1[4]) + ((UInt32) Ca61_data1[5]) + ((UInt32)
    Ca61_data1[6]) + ((UInt32) Ca61_data1[7]) + ((UInt32) Ca61_data1[8]) + ((UInt32) Ca61_data1[9]))
     / 10);
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void SetVsPhaseFlag(void)
{
	if(Fv_VehSpdNew >1600)
	{
		Fv_VsPhaseflag = 4;
	}
	else if(Fv_VehSpdNew >1120&&Fv_VehSpdNew <=1600)//>35&&<50
	{
		Fv_VsPhaseflag = 3;
	}
	else if(Fv_VehSpdNew >640&&Fv_VehSpdNew <=1120)//>20&&<35
	{
		Fv_VsPhaseflag = 2;
	}
	else if(Fv_VehSpdNew >160&&Fv_VehSpdNew <=640)//< 5km/h
	{
		Fv_VsPhaseflag = 1;
	}
	else
	{
		Fv_VsPhaseflag = 0;
	}
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void WheelSpeedFilter(void)
{
	static UInt16 y1[2] = {0,};
	static UInt16 y2[2] = {0,};
	static UInt16 y3[2] = {0,};
	static UInt16 y4[2] = {0,};

	y1[0] = (UInt16)((CAN_FLWS * 2 + y1[1] * 2) >> 2);
	y1[1] = y1[0];
	
	y2[0] = (UInt16)((CAN_FRWS * 2 + y2[1] * 2) >> 2);
	y2[1] = y2[0];
	
	y3[0] = (UInt16)((CAN_RLWS * 2 + y3[1] * 2) >> 2);
	y3[1] = y3[0];
	
	y4[0] = (UInt16)((CAN_RRWS * 2 + y4[1] * 2) >> 2);
	y4[1] = y4[0];
	
	Fv_WheelSpeed_FL = y1[0];
	Fv_WheelSpeed_FR = y2[0];
	Fv_WheelSpeed_RL = y3[0];
	Fv_WheelSpeed_RR = y4[0];
}
#if defined(ENABLE_CHECKSUM_AND_COUNTER)
/****************************************************************
* FUNCTION : 
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
UInt8 CheckSum_CanBus(UInt8 *u8_data,UInt8 u8_len)
{
	UInt8 i = 0;
	UInt8 u8_crc8 = 0;
	UInt8 CheckSum = 0;

	for(i = 0;i < u8_len;i++)
	{
		CheckSum += u8_data[i];
	}

	u8_crc8 = (CheckSum ^ 0xFF);

	return u8_crc8;
}
#endif
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void OpenPredriveIndp1(void)
{
	SysTaskPreDriverPending1 = TRUE;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void OpenPredriveIndp2(void)
{
	SysTaskPreDriverPending2 = TRUE;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : 
* INPUTS :  None
* OUTPUTS : 
* Limitations:
****************************************************************/
void CalcLowRtrSpd(void)
{
 #define ANGDIFF_FRZ      (Int32)1000  //1ms,1000Hz
 #define ANGDIFF_LMT_L 	  (Int32)320000 //93rpm
 #define ANGDIFF_LMT_H 	  (Int32)12800000 //930rpm
 #define ANGDIFF_DOR      (Int32)3200   //0.93rpm
 #define ANGDIFF_TRG_TMR  (UInt8)2

	static Int32 last_ang = 0;
	static Int32 out_last_x = 0;
	static Int32 out_last_y = 0;
	static UInt16 trg_valid_cnt = 0;
	static UInt8 trg_valid_flag = 0;

	Int32 out_now_y = 0;
	Int32 out_now_x = 0;
	Int32 local_ang = 0 ;
	Int32 out_final = 0;
	Int32 in_angle = 0;
	Int32 max_rev = ANGDIFF_LMT_L;

	if(Fv_SystemTransferState == FALSE)
	{
		in_angle = (Fv_RotorAng_AddSum);
		max_rev = ANGDIFF_LMT_H;
	}
	else
	{
		in_angle = (Fv_RotorAng_AddSum);
		max_rev = ANGDIFF_LMT_H;//L
	}

	if(SysTaskRsvResetTrgPending == TRUE)
	{
		trg_valid_flag = TRUE;
		trg_valid_cnt = 0;
	}
	else
	{
		if(trg_valid_cnt < ANGDIFF_TRG_TMR)
		{
			trg_valid_cnt++;
		}
		else
		{
			trg_valid_flag = FALSE;
		}
	}

	if(trg_valid_flag == TRUE)
	{
		last_ang = in_angle;
		out_last_y = 0;
		out_last_x = 0;
	}
	else
	{
	}

	local_ang = (in_angle - last_ang)*ANGDIFF_FRZ;
	last_ang = in_angle;

	if(local_ang > max_rev)
	{
		out_now_x = max_rev;
	}
	else if(local_ang < -max_rev)
	{
		out_now_x = -max_rev;
	}
	else
	{
		out_now_x = local_ang;
	}

	/**********************************************************
	*tustin ,1/(1+T0*s),s=2/Ts*((z-1)/(z+1))
	*y(k)=(2T0-Ts)/(2T0+Ts)*y(k-1)+1/(2T0+Ts)*(x(k)+x(k-1))
	*Ts=1ms,T0=10ms
	**********************************************************/
	out_now_y = (6*out_last_y + out_now_x + out_last_x)/8;
	out_last_y = out_now_y;
	out_last_x = out_now_x;

	if(out_now_y > ANGDIFF_DOR)
	{
		out_final = out_now_y - ANGDIFF_DOR;
	}
	else if(out_now_y < -ANGDIFF_DOR)
	{
		out_final = out_now_y + ANGDIFF_DOR;
	}
	else
	{
		out_final = 0;
	}

	if(SysTaskResolverSmpPending)
	{
		Fv_LowRev_spd = (out_final >> 5);
	}
	else
	{
		Fv_LowRev_spd = 0;
	}

#undef ANGDIFF_FRZ
#undef ANGDIFF_LMT_L
#undef ANGDIFF_LMT_H
#undef ANGDIFF_DOR
#undef ANGDIFF_TRG_TMR
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
Int16 OffCenterSATFun(Int16 input)
{
	Int16 output = 0;

	OffCenterSAT();

	output = Tv_OffCenterComp;

	return output;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
Int16 ToruqeNotchFilterFun(Int16 input)
{
	Int16 output = 0;

	ToruqeNotchFilter();

	output = Tv_BasicAsisTrq_NCH;

	return output;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
Int16 TorqueSoftAdv2Fun(Int16 input)
{
	Int16 output = 0;

	TorqueSoftAdv2();

	output = Tv_BasicAsisTrq_ADV;

	return output;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
Int16 ToruqeRobustfilterFun(Int16 input)
{
	Int16 output = 0;

	RobustfilterFun();

	output = Tv_BasicAsisTrq_RBS;

	return output;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
Int16 OnCenterKickFun(Int16 input)
{
	Int16 output = 0;
	Int16 diff_acc = 0;
	Int16 rtb_acccoef = 0;
	Int16 oc_comp = 0;
	static Int16 last_vs = 0;
	static UInt16 cnt = 10;
	static UInt32 m_bpIndex_oc = 0;

	OnCenterKick();

	oc_comp = Tv_OnCenterKickComp;
	//姣�10ms閿熸枻鎷烽敓鏂ゆ嫹涓�閿熻娇锝忔嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷蜂浚閿熺唇v_VehSpd閿熸枻鎷烽敓鍔鎷烽敓鎹疯鎷�,
	if(cnt == 0)
	{
		diff_acc = Fv_VehSpd - last_vs;
		last_vs = Fv_VehSpd;
		cnt = 10;
	}
	cnt--;
	//浣块敓鏂ゆ嫹diff_acc閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷风帿閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熻緝纰夋嫹閿燂拷
	if(diff_acc < 0)
	{
	  diff_acc = -diff_acc;
	}
	
	rtb_acccoef = look1_is16ls32n10ts16D_PDzFBkZ7(diff_acc, ((const Int16 *)
		&(Cal_OC_AccCompTab_X[0])), ((const Int16 *)
		&(Cal_OC_AccCompTab_Y[0])), &m_bpIndex_oc, 4U);
		
	Tv_OnCenterKickComp = (Int16)((((Int32)rtb_acccoef)*((Int32)oc_comp))>>7);
	
	output = Tv_OnCenterKickComp;

	return output;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
Int16 ToruqeStableFilterFun(Int16 input)
{
	Int16 output = 0;

	ToruqeStableFilter();

	output = Fv_StrTrq_FeedForward;

	return output;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
Int16 TorqueSoftAdvFun(Int16 input)
{
	Int16 output = 0;

	TorqueSoftAdv();

	output = Fv_StrTrqP2dot5;

	return output;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void OpenPredrive(void)
{
	IoHwAb_PwmOut01Enable();
	IoHwAb_PwmOut02Enable();
	SysTaskPreDriverPending1 = TRUE;
	SysTaskPreDriverPending2 = TRUE;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void OpenPredrive1(void)
{
	IoHwAb_PwmOut01Enable();
	SysTaskPreDriverPending1 = TRUE;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void OpenPredrive2(void)
{
	IoHwAb_PwmOut02Enable();
	SysTaskPreDriverPending2 = TRUE;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void ClosePredrive(void)
{
	IoHwAb_PwmOut01Disable();
    IoHwAb_PwmOut02Disable();
	SysTaskPreDriverPending1 = FALSE;
	SysTaskPreDriverPending2 = FALSE;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void ClosePredrive1(void)
{
	IoHwAb_PwmOut01Disable();
	SysTaskPreDriverPending1 = FALSE;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void ClosePredrive2(void)
{
    IoHwAb_PwmOut02Disable();
	SysTaskPreDriverPending2 = FALSE;
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
uint8 Compare_Msg_Length(uint8 DLC,uint8 Legallth)
{
	uint8 tmp = 0;

	if(DLC != Legallth)
	{
		tmp = 0 ;
	}else
	{
		tmp = 1;
	}

	return tmp;
}
#if 0
/******************************************
**Function name: CompareCheckSum
**Describe: 濡拷閺屻儲甯撮弨鑸靛Г閺傚構hecksum閸婏拷
**input: ReCheckSum:閹恒儲鏁归幎銉︽瀮閻ㄥ嚋hecksum閸婏拷
         CalCheckSum閿涙碍婀伴崷鎷岊吀缁犳鍤惃鍑渉ecksum閸婏拷
		 MsgEnum閿涙岸娓剁憰浣诡梾閺岊檳hecksum閸婅偐娈戦幒銉︽暪閹躲儲鏋冪槐銏犵穿
**return: 0:閹存劕濮涢敍锟�1閿涙艾銇戠拹锟�
**Modification record: 鐏忓棙鏆熺紒鍕綁闁插繐鍨垫慨瀣拷鐓庡弿闁劍鏁兼稉锟�0閿涘矂浼╅崗宥嗘殶缂佸嫭婀�瑰苯鍙忛崚婵嗩潗閸栨牕顕遍懛鏉戝毉閻滅増妫ら弫鍫濆坊閸欏弶鏅犻梾锟�--TXY--20220909
*******************************************/
UInt8 CompareCheckSum(UInt16 ReCheckSum,UInt16 CalCheckSum,UInt8 MsgEnum)
{
	/* 閸掓繂顫愰崠鏍Ц閹礁褰夐柌蹇ョ礉闁灝鍘ら崙铏瑰箛閺冪姵鏅ラ崢鍡楀蕉閺佸懘娈� --20210716-TIAN  */
	static UInt8 revalue[kCanNumberOfRxObjects] = {0};/*Yu-210719-閹恒儲鏁归幎銉︽瀮婢х偛濮炴禍鍡曠娑擄拷*/
	static UInt8 CrcCnt[kCanNumberOfRxObjects] = {0};/*Yu-210719-閹恒儲鏁归幎銉︽瀮婢х偛濮炴禍鍡曠娑擄拷*/
	static UInt8 RevCnt[kCanNumberOfRxObjects] = {0};/*Yu-210719-閹恒儲鏁归幎銉︽瀮婢х偛濮炴禍鍡曠娑擄拷*/

	if(ReCheckSum == CalCheckSum)
	{		
		if(RevCnt[MsgEnum] < 36)  // BYD EK 閻炲棜顔戦崐锟�40鐢勪划婢跺秵鍨氶崢鍡楀蕉閺佸懘娈伴敍灞惧閸斻劏藟閸嬭儻鍤�36 -WSY20230515
		{
			RevCnt[MsgEnum]++;	
		}
		else
		{
			revalue[MsgEnum] = 0;
			RevCnt[MsgEnum] = 0;
			CrcCnt[MsgEnum] = 0;
		}
		MessageCRCErrorFlag[MsgEnum] = 0;//CRC閸婂吋顒滅敮锟�
	}
	else
	{
		if(CrcCnt[MsgEnum] < 2/*10*/)  //BYD EK 3鐢勫Г閺佸懘娈� -WSY20230515
		{
			CrcCnt[MsgEnum]++;
		}
		else
		{
			revalue[MsgEnum] = 1;
			CrcCnt[MsgEnum] = 0;
			RevCnt[MsgEnum] = 0;
		}
		MessageCRCErrorFlag[MsgEnum] = 1;//CRC閸婂ジ鏁婄拠锟�
	}
	return revalue[MsgEnum];
}
/******************************************
**Function name: CheckRolling
**Describe: 濡拷閺屻儲甯撮弨鑸靛Г閺傚洦绮撮崝銊吀閺佹澘锟斤拷
**input: u8_cnt:閹恒儲鏁归幎銉︽瀮閻ㄥ嫯顓搁弫鏉匡拷锟�
         MsgEnum閿涙岸娓剁憰浣诡梾閺屻儴顓搁弫鏉匡拷鑲╂畱閹恒儲鏁归幎銉︽瀮缁便垹绱�
**return: 0:閹存劕濮�;1:婢惰精瑙�
**Modification record: 鐏忓棙鏆熺紒鍕綁闁插繐鍨垫慨瀣拷鐓庡弿闁劍鏁兼稉锟�0閿涘矂浼╅崗宥嗘殶缂佸嫭婀�瑰苯鍙忛崚婵嗩潗閸栨牕顕遍懛鏉戝毉閻滅増妫ら弫鍫濆坊閸欏弶鏅犻梾锟�--TXY--20220909
*******************************************/
UInt8 CheckRolling(UInt16 u8_cnt,UInt8 MsgEnum,UInt8 len)
{
#if 1
    #define ERROR_COUNTER 3//10  BYD EK 3鐢囨晩鐠囷拷 -WSY 2023015
    #define RECOVERY_COUNTER 36  //閻炲棜顔戦崐锟�40鐢勪划婢跺秳璐熼崢鍡楀蕉閺佸懘娈伴敍灞惧閸斻劏藟閸嬭儻鍤�36
	/* 閸掓繂顫愰崠鏍Ц閹礁褰夐柌蹇ョ礉闁灝鍘ら崙铏瑰箛閺冪姵鏅ラ崢鍡楀蕉閺佸懘娈� --20210716-TIAN  */
	static UInt8 first_flag[kCanNumberOfRxObjects] = {0};
	static UInt16 last_cnt[kCanNumberOfRxObjects] = {0};
	static UInt16 err_cnt[kCanNumberOfRxObjects] = {0};
	static UInt16 rcv_cnt[kCanNumberOfRxObjects] = {0};
	static UInt8 check_state[kCanNumberOfRxObjects] = {0};
	UInt16 UpperLimit = 0xF;   //BYD SUEA妞ゅ湱娲版晶鐐插闂�绶緊unter閸婄》绱濋柅姘崇箖婢х偛濮為崣鍌涙殶len(娣団�冲娇鐎涙濡梹鍨)閺夈儱鍨介弬锟�-wsy20230909
	switch(len)
	{
		case 1:UpperLimit = 0xF;break;
		case 2:UpperLimit = 0xFFFF;break;
	}
	if(u8_cnt > UpperLimit)
	{
		check_state[MsgEnum] = 1;
		MessageCounterErrorFlag[MsgEnum] = 1;
	}
	else
	{
		if((/*(u8_cnt == 0) && */(first_flag[MsgEnum] == 0x00u)) //閹懎鍠�1閿涙岸顩荤敮褌绗夐崚銈嗘焽
		|| (u8_cnt == (last_cnt[MsgEnum] + 1)) //閹懎鍠�2閿涙瓭ounter闁帒顤�
		|| ((u8_cnt == 0) && (last_cnt[MsgEnum] == UpperLimit)))//閹懎鍠�3閿涙艾顤冮崝鐘插煂F(閹存湉FFF)闁插秵鏌婃禒锟�0瀵拷婵拷
		{
			first_flag[MsgEnum] = 0xAA;
			if(rcv_cnt[MsgEnum] < RECOVERY_COUNTER)
			{
				rcv_cnt[MsgEnum] ++;
			}
			else
			{
				check_state[MsgEnum] = 0;
				err_cnt[MsgEnum] = 0;
				rcv_cnt[MsgEnum] = 0;
			}
			MessageCounterErrorFlag[MsgEnum] = 0;//Counter閸婂吋顒滅敮锟�
		}
		else
		{
			if(err_cnt[MsgEnum] < ERROR_COUNTER)
			{
				err_cnt[MsgEnum]++;
			}
			else
			{
				check_state[MsgEnum] = 1;
				err_cnt[MsgEnum] = 0;
				rcv_cnt[MsgEnum] = 0;
			}
			MessageCounterErrorFlag[MsgEnum] = 1;//Counter閸婂ジ鏁婄拠锟�
		}
	}
	last_cnt[MsgEnum] = u8_cnt;

	return check_state[MsgEnum];

#endif
}
#endif
#if 0
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void AssistModeSwitch(void)
{
#define	MACRO_ModeSwitch_Vehspd 5120//160km/h

	static AstModeCmd last_sfs_cmd = AstModeCmd_NoReq;
	static SMSModeCmd last_sms_cmd = SMSModeCmd_NoReq;
	static SMSModeCmd last_ats_cmd = RoadMode_Invalid;
	static UInt8 last_reset_req = 0;
	static ASS_TYPE sfs_ast_mod_req = ASS_TYPE_DEFAULT;
	static ASS_TYPE sms_ast_mod_req = ASS_TYPE_DEFAULT;
	static ASS_TYPE ats_ast_mod_req = ASS_TYPE_DEFAULT;
	UInt8 safety_cond = 0;

	if((Fv_StrTrq0 <= Cal_ModeSwitch_Trq)\
     &&(Fv_StrTrq0 >= -Cal_ModeSwitch_Trq)\
	 &&(Fv_VehSpd <= MACRO_ModeSwitch_Vehspd)\
	 &&(Fv_dStrAng <= Cal_ModeSwitch_WheelSpd)\
     &&(Fv_dStrAng >= -Cal_ModeSwitch_WheelSpd))
	{
		safety_cond = 1;
	}
	else
	{
		safety_cond = 0;
	}

	fsSFSSetSafetyCond = safety_cond;

	if((fsSMS_Target_Steering_Gear_S == SMSModeCmd_Comfort)\
	 ||(fsSMS_Target_Steering_Gear_S == SMSModeCmd_Sport)\
	 ||(fsSMS_STR_Adjust_Allow_S == SMSAdjustAlw_Forbid)\
	 ||(fsATSRoadMode == RoadMode_GlassSnow)\
	 ||(fsATSRoadMode == RoadMode_Muddy)\
	 ||(fsATSRoadMode == RoadMode_Sand)\
     ||(Fv_LKA_ControlSts == 2)
	 ||(Fv_LKAAC_ControlSts == 2))
	{
		fsSFSSetForbidCond = 1;
	}
	else
	{
		fsSFSSetForbidCond = 0;
	}

	if((Fv_LKA_ControlSts == 2)||(Fv_LKAAC_ControlSts == 2))
	{
		fsSMSSetForbidCond = 1;
		fsATSSetForbidCond = 1;
	}
	else
	{
		fsSMSSetForbidCond = 0;
		fsATSSetForbidCond = 0;
	}

	if(fsSFSFuncCfg > 0)
	{
		if(fsSFSSetForbidCond == 0)
		{
			if(((fsStrModeSelecCmd == AstModeCmd_Comfort)
				||(fsStrModeSelecCmd == AstModeCmd_Sport))
				&&(fsStrModeSelecCmd != last_sfs_cmd))
			{
				switch(fsStrModeSelecCmd)
				{
					case AstModeCmd_Comfort:
						sfs_ast_mod_req = ASS_TYPE_COMFORT;
						break;
					case AstModeCmd_Sport:
						sfs_ast_mod_req = ASS_TYPE_SPORT;
						break;
					default:
						break;
				}
			}

			if((fsSFSModeResetReq > 0)&&(last_reset_req == 0))
			{
				sfs_ast_mod_req = ASS_TYPE_COMFORT;
			}
			else
			{
			}
			
			if(safety_cond > 0)
			{
				if((Fv_CMDAssistSelectMode != sfs_ast_mod_req)
				 &&(sfs_ast_mod_req != AstModeCmd_NoReq))
				{
					Fv_CMDAssistSelectMode = sfs_ast_mod_req;
					sfs_ast_mod_req = AstModeCmd_NoReq;
					if(Fv_CMDAssistSelectMode != Fv_RUNAssistSelectMode)
					{
						Fv_RUNAssistSelectMode = Fv_CMDAssistSelectMode;
						AssistModeStoreRequest();
					}
				}
				else
				{
				}
			}
		}
	}
	else
	{
	}

	if(fsSMSFuncCfg > 0)
	{
		if(fsSMSSetForbidCond == 0)
		{
			if(((fsSMS_Target_Steering_Gear_S == SMSModeCmd_Comfort)\
				||(fsSMS_Target_Steering_Gear_S == SMSModeCmd_Sport)
				||(fsSMS_Target_Steering_Gear_S == SMSModeCmd_Spec2))\
				&&(last_sms_cmd != fsSMS_Target_Steering_Gear_S))
			{
				switch(fsSMS_Target_Steering_Gear_S)
				{
					case SMSModeCmd_Comfort:
						sms_ast_mod_req = ASS_TYPE_COMFORT;
						break;
					case SMSModeCmd_Sport:
						sms_ast_mod_req = ASS_TYPE_SPORT;
						break;
					case SMSModeCmd_Spec2:
						sms_ast_mod_req = ASS_TYPE_SPEC2;
						break;
					default:
						break;
				}
			}

			if(safety_cond > 0)
			{
				if((Fv_CMDAssistSelectMode != sms_ast_mod_req)
				  &&(sms_ast_mod_req != AstModeCmd_NoReq))
				{
					Fv_CMDAssistSelectMode = sms_ast_mod_req;
					sms_ast_mod_req = AstModeCmd_NoReq;
					if(Fv_CMDAssistSelectMode != Fv_RUNAssistSelectMode)
					{
						Fv_RUNAssistSelectMode = Fv_CMDAssistSelectMode;
					}
				}
				else
				{
				}
			}
		}
	}

	if(fsATSFuncCfg > 0)
	{
		if(fsATSSetForbidCond == 0)
		{
			if((fsATSRoadMode <= RoadMode_Resvered2)\
				&&(last_ats_cmd != fsATSRoadMode))
			{
				switch(fsATSRoadMode)
				{
					case RoadMode_GlassSnow:
						ats_ast_mod_req = ASS_TYPE_SPORT;
						break;
					case RoadMode_Muddy:
						ats_ast_mod_req = ASS_TYPE_SPORT;
						break;
					case RoadMode_Sand:
						ats_ast_mod_req = ASS_TYPE_COMFORT;
						break;
					default:
						ats_ast_mod_req = sfs_ast_mod_req;
						break;
				}
			}

			if(safety_cond > 0)
			{
				if((Fv_CMDAssistSelectMode != ats_ast_mod_req)
				  &&(ats_ast_mod_req != AstModeCmd_NoReq))
				{
					Fv_CMDAssistSelectMode = ats_ast_mod_req;
					ats_ast_mod_req = AstModeCmd_NoReq;
					if(Fv_CMDAssistSelectMode != Fv_RUNAssistSelectMode)
					{
						Fv_RUNAssistSelectMode = Fv_CMDAssistSelectMode;
					}
				}
				else
				{
				}
			}
		}
	}

    last_sfs_cmd = fsStrModeSelecCmd;
	last_ats_cmd = fsATSRoadMode;
    last_reset_req = fsSFSModeResetReq;
	last_sms_cmd = fsSMS_Target_Steering_Gear_S;

#undef	MACRO_ModeSwitch_Vehspd 
}
#endif
#if 0
/****************************************************************
* FUNCTION :
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void LKATurnCurveSel(void)
{
#if ((MACRO_LKA_FUNCTION_ENABLE == 1)||(MACRO_LKAAC_FUNCTION_ENABLE ==1))
#define MACRO_LKA_ExitDelay_TMR 30
	static UInt16 lka_exit_cnt = 0;

    UInt8 LKA_active = 0;
	#if (MACRO_LKA_FUNCTION_ENABLE == 1)
	LKA_active = (Fv_LKA_ControlSts == 2);
	#else
    LKA_active = (Fv_LKAAC_ControlSts == 2);
	#endif

	switch(fsLKATurnCurveSel)
	{
		case 0:
			if((LKA_active > 0)&&(fsSFSSetSafetyCond > 0))
			{
				fsLKATurnCurveSel = 1;
				lka_exit_cnt = 0;
			}
			else 
			{
			}
		break;

		default:
			if(LKA_active == 0)
			{
				if(lka_exit_cnt < MACRO_LKA_ExitDelay_TMR)
				{
					lka_exit_cnt++;
				}
				else
				{
					if(fsSFSSetSafetyCond > 0)
					{
					    fsLKATurnCurveSel = 0;
					}
				}
			}
			else
			{
				lka_exit_cnt = 0;
			}	
		break;
	}
#undef MACRO_LKA_ExitDelay_TMR
#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void SteerAssistModeSet(void)
{
	if(Fv_EBL_Cmd == 0)
	{
		if(fsLKATurnCurveSel != 1)
		{
			Fv_SelectAssistMode = Fv_RUNAssistSelectMode;
		}
		else
		{
			Fv_SelectAssistMode = ASS_TYPE_LKA;
		}
	}
	else
	{
        Fv_SelectAssistMode = ASS_TYPE_COMFORT;
	}

	if(Fv_SelectAssistMode != ASS_TYPE_SPEC2)
	{
		Fv_SteerAssistMode = Fv_SelectAssistMode;
	}
	else
	{
		Fv_SteerAssistMode = ASS_TYPE_COMFORT;
	}
}
#endif
/****************************************************************
* FUNCTION :
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void SuportFunc_LKAFeedBack(void)
{
#if(MACRO_LKA_FUNCTION_ENABLE == 1)

    static UInt8 LKA_ControlSts = 0;
	static UInt8 LKA_ActiveFail = 0;
	static UInt8 LKA_SlopeValueFail = 0;
	
	if (Fv_LKA_Configuration) 
	{
		if((Fv_LKA_ControlSts >= 3)&&(Fv_LKA_ControlSts != LKA_ControlSts))
		{
			if(LKA_Interrupt_Info.eps_permanent > 0)
			{
				Fv_LKA_BYDFeedback = 0x0A;
			}
			else if(LKA_Interrupt_Info.tempoverflag > 0)
			{
				Fv_LKA_BYDFeedback = 0x09;
			}
			else if(LKA_Interrupt_Info.range_invalid > 0)
			{
				Fv_LKA_BYDFeedback = 0x08;
			}
			else if(LKA_Interrupt_Info.grid_invalid > 0)
			{
				Fv_LKA_BYDFeedback = 0x07;
			}
			else if(LKA_Interrupt_Info.eps_temporary_err > 0)
			{
				Fv_LKA_BYDFeedback = 0x06;
			}
			else if(LKA_Interrupt_Info.lkainvalid > 0)
			{
				Fv_LKA_BYDFeedback = 0x05;
			}
			else if(LKA_Interrupt_Info.hanshake_err > 0)
			{
				Fv_LKA_BYDFeedback = 0x04;
			}
			else if(LKA_Interrupt_Info.vsinvalid > 0)
			{
				Fv_LKA_BYDFeedback = 0x03;
			}
			else if(LKA_Interrupt_Info.override_flag > 0)
			{
				Fv_LKA_BYDFeedback = 0x02;
			}
			else if(LKA_Interrupt_Info.handoff_flag > 0)
			{
				Fv_LKA_BYDFeedback = 0x01;
			}
			else
			{
				Fv_LKA_BYDFeedback = 0x00;
			}
		}
		else
		{
			if(Fv_LKA_ControlSts == 0)
			{
				Fv_LKA_BYDFeedback = 0x00;
			}
		}

		if((Fv_LKA_ControlSts >= 3)&&(Fv_LKA_ControlSts != LKA_ControlSts))
		{ 
			/***********************************************/
			if(LKA_Interrupt_Info.vsinvalid > 0)
			{
				LKA_ActiveFail = 0x01;
			}

			if(LKA_Interrupt_Info.override_flag > 0)
			{
				LKA_ActiveFail = 0x01;
			}
			
			/*******************************/
			if(LKA_Interrupt_Info.range_invalid > 0)
			{
				LKA_SlopeValueFail = 0x01;
			}
			if(LKA_Interrupt_Info.grid_invalid > 0)
			{
				LKA_SlopeValueFail = 0x01;
			}
		}
		else
		{
			if(Fv_LKA_ControlSts == 0)
			{
				LKA_ActiveFail = 0;
				LKA_SlopeValueFail = 0;
			}
		}

		LKA_ControlSts = Fv_LKA_ControlSts;

		/*******************************/
		if(LKA_SlopeValueFail > 0)
		{
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_ReqValueOverLimt] = FailureDiag_Err;
		}
		else
		{		
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_ReqValueOverLimt] = FailureDiag_OK;
		}

		if(LKA_ActiveFail > 0)
		{
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_AbnormalExit] = FailureDiag_Err;
		}
		else
		{		
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_AbnormalExit] = FailureDiag_OK;
		}
	}

#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void SuportFunc_LKAACFeedBack(void)
{
#if(MACRO_LKAAC_FUNCTION_ENABLE == 1)

    static UInt8 LKAAC_ControlSts = 0;
	static UInt8 LKAAC_ActiveExitFail = 0;
	static UInt8 LKAAC_AngleValueFail = 0;
	static UInt8 LKAAC_AngleSlopeFail = 0;
    static UInt16 LKAAC_dtccnt = 0;

	if (Fv_LKAAC_Configuration) 
	{
		if((Fv_LKAAC_ControlSts >= 3)&&(Fv_LKAAC_ControlSts != LKAAC_ControlSts))
		{
			/*0x0閿涳拷 No interruption
			0x1閿涳拷 Driver hands off reserved
			0x2閿涳拷 Driver override
			0x3閿涳拷 Vehicle Speed Invalid
			0x4閿涳拷 ADAS ECU Activation Request Error
			0x5閿涙DAS ECU Signal error
			0x6閿涙PS Temporary error
			0x7閿涙瓓equest Angle Slope over range
			0x8:  Request Angle Value over range
			0x9:  EPS Permanently error
			0xA~0xF:  Reserved

			Init:0x0*/
			if(LKAAC_ControlSts == 0)
			{
				if(LKA_Interrupt_Info2.eps_permanent > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x07;
				}
				else if(LKA_Interrupt_Info2.eps_temporary_err > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x06;
				}
				else if(LKA_Interrupt_Info2.lkainvalid > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x05;
				}
				else if(LKA_Interrupt_Info2.vsinvalid > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x03;
				}
				else if(LKA_Interrupt_Info2.hanshake_err > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x04;
				}
				else
				{
					Fv_LKAAC_BYDFeedback = 0x00;
				}
			}
			else if(LKAAC_ControlSts == 1)
			{
				if(LKA_Interrupt_Info2.eps_permanent > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x07;
				}
				else if(LKA_Interrupt_Info2.eps_temporary_err > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x06;
				}
				else if(LKA_Interrupt_Info2.lkainvalid > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x05;
				}
				else if(LKA_Interrupt_Info2.vsinvalid > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x03;
				}
				else if(LKA_Interrupt_Info2.vsrange > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x0A;
				}
				else
				{
					Fv_LKAAC_BYDFeedback = 0x00;
				}
			}
			else 
			{
				if(LKA_Interrupt_Info2.eps_permanent > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x07;
				}
				else if(LKA_Interrupt_Info2.eps_temporary_err > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x06;
				}
				else if(LKA_Interrupt_Info2.lkainvalid > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x05;
				}
				else if(LKA_Interrupt_Info2.vsinvalid > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x03;
				}
				else if(LKA_Interrupt_Info2.vsrange > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x0A;
				}
				else if(LKA_Interrupt_Info2.grid_invalid > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x09;
				}
				else if((LKA_Interrupt_Info2.range_invalid > 0)
				      ||(LKA_Interrupt_Info2.angle_diff_over > 0))
				{
					Fv_LKAAC_BYDFeedback = 0x08;
				}
				else if(LKA_Interrupt_Info2.override_flag > 0)
				{
					Fv_LKAAC_BYDFeedback = 0x02;
				}
				else
				{
					Fv_LKAAC_BYDFeedback = 0x00;
				}
			}
		}
		else
		{
			if(Fv_LKAAC_ControlSts <= 2)
			{
				Fv_LKAAC_BYDFeedback = 0x00;
			}
		}

		if((Fv_LKAAC_ControlSts >= 3)&&(LKAAC_ControlSts == 2))
		{ 
			LKAAC_dtccnt = 0;
			/***********************************************/
			if(LKA_Interrupt_Info2.vsrange > 0)
			{
				LKAAC_ActiveExitFail = 0x01;
			}

			if(LKA_Interrupt_Info2.override_flag > 0)
			{
				LKAAC_ActiveExitFail = 0x01;
			}
			
			/*******************************/
			if(LKA_Interrupt_Info2.range_invalid > 0)
			{
				LKAAC_AngleValueFail = 0x01;
			}
			if(LKA_Interrupt_Info2.grid_invalid > 0)
			{
				LKAAC_AngleSlopeFail = 0x01;
			}
		}
		else
		{
			if(LKAAC_dtccnt < 200)
			{
				LKAAC_dtccnt++;
			}
			else
			{
				// if(Fv_LKAAC_ControlSts <= 2)
				{
					LKAAC_ActiveExitFail = 0;
					LKAAC_AngleSlopeFail = 0;
					LKAAC_AngleValueFail = 0;
				}
			}
		}

		LKAAC_ControlSts = Fv_LKAAC_ControlSts;
		/*******************************/
		if((LKAAC_AngleValueFail > 0)||(LKAAC_AngleSlopeFail > 0))
		{
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_ReqValueOverLimt] = FailureDiag_Err;
		}
		else
		{		
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_ReqValueOverLimt] = FailureDiag_OK;
		}

		if(LKAAC_ActiveExitFail > 0)
		{
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_AbnormalExit] = FailureDiag_Err;
		}
		else
		{		
			Fv_ErrDiagStatus[DTC_LKAFUNCcheck_AbnormalExit] = FailureDiag_OK;
		}
	}

#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void SuportFunc_APAFeedBack(void)
{
#if(MACRO_APA_FUNCTION_ENABLE == 1)

    static UInt8 APA_ControlSts = 0;
	static UInt8 APA_ActiveExitFail = 0;
	static UInt16 APA_timecnt = 0;
    static UInt16 APA_dtccnt = 0;

	if (Fv_APA_Configuration) 
	{
		if(((Fv_APA_ControlSts >= 3)||(Fv_APA_ControlSts == 0))&&(Fv_APA_ControlSts != APA_ControlSts))
		{
			APA_timecnt = 0;
			if(APA_ControlSts == 1)
			{
				/*0x0閿涙瓊o Interruption
				0x1閿涙river Interruption
				0x2閿涙PS Temporary Error
				0x3閿涙PS Permanent Error
				0x4閿涙PA Single Absent Reserved
				0x5閿涙PA Target Angle Over Limit
				0x6閿涙PA Target Angle Velocity Over Limit
				0x7閿涙PA Signal Error
				0x8閿涙瓘ehicle Speed Over Limit
				0x9閿涙瓘ehicle Speed Signal Error
				0xA閿涙瓘ehicle Speed Signal Absent Reserved
				0xB閿涙瓖AS Angle Error
				0xC閿涙ncorrect Handshaking
				0xD閿涙瓌ver Angle Max Value
				0xE閿涙瓌ver Angle Velocity
				0xF閿涙瓌ther Faults */
				if(APA_Interrupt_Info.eps_permanent > 0)
				{
					Fv_APA_BYDFeedback = 0x03;
				}
				else if(APA_Interrupt_Info.eps_temporary_err > 0)
				{
					Fv_APA_BYDFeedback = 0x02;
				}
				else if(APA_Interrupt_Info.override_flag > 0)
				{
					Fv_APA_BYDFeedback = 0x01;
				}
				else if(APA_Interrupt_Info.tas_err > 0)
				{
					Fv_APA_BYDFeedback = 0x0B;
				}
				else if(APA_Interrupt_Info.apainvalid > 0)
				{
					Fv_APA_BYDFeedback = 0x07;
				}
				else if(APA_Interrupt_Info.vsinvalid > 0)
				{
					Fv_APA_BYDFeedback = 0x09;
				}
				else if(APA_Interrupt_Info.vsrange > 0)
				{
					Fv_APA_BYDFeedback = 0x08;
				}
				else if(APA_Interrupt_Info.over_anglespeed > 0)
				{
					Fv_APA_BYDFeedback = 0x0E;
				}
				else if(APA_Interrupt_Info.hanshake_err > 0)
				{
					Fv_APA_BYDFeedback = 0x0C;
				}
				else
				{
					Fv_APA_BYDFeedback = 0x00;
				}
			}
			else
			{
				if(APA_Interrupt_Info.eps_permanent > 0)
				{
					Fv_APA_BYDFeedback = 0x03;
				}
				else if(APA_Interrupt_Info.eps_temporary_err > 0)
				{
					Fv_APA_BYDFeedback = 0x02;
				}
				else if(APA_Interrupt_Info.override_flag2 > 0)
				{
					Fv_APA_BYDFeedback = 0x01;
					Fv_APA_OvrideExit = true;
				}
				else if(APA_Interrupt_Info.tas_err > 0)
				{
					Fv_APA_BYDFeedback = 0x0B;
				}
				else if(APA_Interrupt_Info.apainvalid > 0)
				{
					Fv_APA_BYDFeedback = 0x07;
				}
				else if(APA_Interrupt_Info.angle_diff_over > 0)
				{
					Fv_APA_BYDFeedback = 0x05;
				}
				else if(APA_Interrupt_Info.cmd_slope_over > 0)
				{
					Fv_APA_BYDFeedback = 0x06;
				}
				else if(APA_Interrupt_Info.vsinvalid > 0)
				{
					Fv_APA_BYDFeedback = 0x09;
				}
				else if(APA_Interrupt_Info.vsrange > 0)
				{
					Fv_APA_BYDFeedback = 0x08;
				}
				else if(APA_Interrupt_Info.angle_cmd_over > 0)
				{
					Fv_APA_BYDFeedback = 0x0D;
				}
				else if(APA_Interrupt_Info.over_anglespeed2 > 0)
				{
					Fv_APA_BYDFeedback = 0x0E;
				}
				else if(APA_Interrupt_Info.hanshake_err2 > 0)
				{
					Fv_APA_BYDFeedback = 0x0C;
				}
				else
				{
					Fv_APA_BYDFeedback = 0x00;
				}
			}
		}
		else
		{
			if(APA_timecnt < 1000)
			{
				APA_timecnt++;
			}
			else 
			{
				if((Fv_APA_ControlSts == 1)||(Fv_APA_ControlSts == 2))
				{
					Fv_APA_BYDFeedback = 0x00;
				}
			}
		}

		if(((Fv_APA_ControlSts >= 3)||(Fv_APA_ControlSts == 0))&&(APA_ControlSts == 2))
		{ 
			APA_dtccnt = 0;
			/***********************************************/
			if((APA_Interrupt_Info.vsrange > 0)\
			 ||(APA_Interrupt_Info.override_flag2 > 0)\
			 ||(APA_Interrupt_Info.hanshake_err2 > 0)\
			 ||(APA_Interrupt_Info.angle_diff_over > 0)\
			 ||(APA_Interrupt_Info.over_anglespeed2 > 0)\
			 ||(APA_Interrupt_Info.cmd_slope_over > 0)\
			 ||(APA_Interrupt_Info.angle_cmd_over > 0))
			{
				APA_ActiveExitFail = 0x01;
			}
		}
		else
		{
			if(APA_dtccnt <= 200)
			{
				APA_dtccnt++;
			}
			else
			{
				//if((Fv_APA_ControlSts == 1)||(Fv_APA_ControlSts == 2))
				{
					APA_ActiveExitFail = 0;
				}
			}
		}

		APA_ControlSts = Fv_APA_ControlSts;

		/*******************************/
		if(APA_ActiveExitFail > 0)
		{
			Fv_ErrDiagStatus[DTC_APAFUNCcheck_AbnormalExit] = FailureDiag_Err;
		}
		else
		{		
			Fv_ErrDiagStatus[DTC_APAFUNCcheck_AbnormalExit] = FailureDiag_OK;
		}
	}

#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void SuportFunc_VOTFeedBack(void)
{
#if(MACRO_VOT_FUNCTION_ENABLE == 1)

    static UInt8 VOT_ControlSts = 0;
	static UInt16 VOT_timecnt = 0;

	if (Fv_VOT_Configuration) 
	{
		if(((Fv_VOT_ControlSts >= 3)||(Fv_VOT_ControlSts == 0))&&(Fv_VOT_ControlSts != VOT_ControlSts))
		{
			VOT_timecnt = 0;
			/*"EPS_VOT_CtrlAbortFeed_S
			  閿涘湕PS VOT Control Abort Feedback閿涳拷"	"0x0閿涙瓊oInterruption
				0x1閿涙riverInterruption
				0x2閿涙PSTemporaryError
				0x3閿涙PSPermanentError
				0x4閿涙瓓eserved
				0x5閿涙PATargetAngleOverLimit
				0x6閿涙PATargetAngleVelocityOverLimit
				0x7閿涙瓘OT Signal Error
				0x8閿涙瓓eserved
				0x9閿涙瓘ehicleSpeedSignalError
				0xA閿涙瓘ehicleSpeedSignalAbsentReserved
				0xB閿涙瓖ASAngleError
				0xC閿涙ncorrectHandshaking
				0xD閿涙瓌verAngleMaxValue
				0xE閿涙瓌verAngleVelocity
				0xF閿涙瓌therFaults"
			*/
		    if(VOT_ControlSts == 1)
			{
				if(VOT_Interrupt_Info.eps_permanent_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x03;
				}
				else if(VOT_Interrupt_Info.eps_temporary_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x02;
				}
				else if(VOT_Interrupt_Info.driver_interrupt > 0)
				{
					Fv_VOT_BYDFeedback = 0x01;
					Fv_VOT_OvrideExit = true;
				}
				else if(VOT_Interrupt_Info.tas_angle_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x0B;
				}
				else if(VOT_Interrupt_Info.vot_signal_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x07;
				}
				else if(VOT_Interrupt_Info.vs_signal_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x09;
				}
				else if(VOT_Interrupt_Info.eps_wheelspd_over > 0)
				{
					Fv_VOT_BYDFeedback = 0x0E;
				}
				else if(VOT_Interrupt_Info.hanshake_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x0C;
				}
				else
				{
					Fv_VOT_BYDFeedback = 0x00;
				}
			}
			else
			{
				if(VOT_Interrupt_Info.eps_permanent_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x03;
				}
				else if(VOT_Interrupt_Info.eps_temporary_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x02;
				}
				else if(VOT_Interrupt_Info.driver_interrupt2 > 0)
				{
					Fv_VOT_BYDFeedback = 0x01;
					Fv_VOT_OvrideExit = true;
				}
				else if(VOT_Interrupt_Info.tas_angle_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x0B;
				}
				else if(VOT_Interrupt_Info.vot_signal_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x07;
				}
				else if(VOT_Interrupt_Info.vot_anglediff_over > 0)
				{
					Fv_VOT_BYDFeedback = 0x05;
				}
				else if(VOT_Interrupt_Info.vot_angleslope_over > 0)
				{
					Fv_VOT_BYDFeedback = 0x06;
				}
				else if(VOT_Interrupt_Info.vs_signal_err > 0)
				{
					Fv_VOT_BYDFeedback = 0x09;
				}
				else if(VOT_Interrupt_Info.vot_anglecmd_over > 0)
				{
					Fv_VOT_BYDFeedback = 0x0D;
				}
				else if(VOT_Interrupt_Info.eps_wheelspd_over2 > 0)
				{
					Fv_VOT_BYDFeedback = 0x0E;
				}
				else if(VOT_Interrupt_Info.hanshake_err2 > 0)
				{
					Fv_VOT_BYDFeedback = 0x0C;
				}
				else
				{
					Fv_VOT_BYDFeedback = 0x00;
				}
			}
		}
		else
		{
			if(VOT_timecnt < 1000)
			{
				VOT_timecnt++;
			}
			else 
			{
				if((Fv_VOT_ControlSts == 1)||(Fv_VOT_ControlSts == 2))
				{
					Fv_VOT_BYDFeedback = 0x00;
				}
			}
		}
		VOT_ControlSts = Fv_VOT_ControlSts;
	}
#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void SuportFunc_DSTFeedBack(void)
{
#if(MACRO_DST_FUNCTION_ENABLE == 1)

	static UInt8 DST_ControlSts = 0;
	static UInt16 DST_timecnt = 0;

	if (Fv_DST_Configuration) 
	{
		if(((Fv_DST_ControlSts == 0)||(Fv_DST_ControlSts == 3))&&(DST_ControlSts == 2))
		{
			DST_timecnt = 0;
			if((Fv_DST_TrqValueOver > 0)||(Fv_DST_TrqSlopeOver > 0))
			{
				Fv_ErrDiagStatus[DTC_DSTFUNCcheck_ReqValueOverLimt] = FailureDiag_Err;
			}
		}
		else
		{
			if(DST_timecnt < 200)
			{
				DST_timecnt++;
			}
			else 
			{
				//if((Fv_DST_TrqValueOver == 0)&&(Fv_DST_TrqSlopeOver == 0))
				{
					Fv_ErrDiagStatus[DTC_DSTFUNCcheck_ReqValueOverLimt] = FailureDiag_OK;
				}
			}
		}
		DST_ControlSts = Fv_DST_ControlSts;
	}
#endif
}
/****************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :  None
* OUTPUTS :
* Limitations:
****************************************************************/
void FailDiag_BYDNewFaultCollection(void)
{
	SuportFunc_LKAFeedBack();
	SuportFunc_LKAACFeedBack();
	SuportFunc_APAFeedBack();
	SuportFunc_VOTFeedBack();
	SuportFunc_DSTFeedBack();
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void ExternalCtrlPrioritySet(void)
{

}
#if 0
/****************************************************************
* FUNCTION : 
* DESCRIPTION : .
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void SupportVarSet(void)
{
#define MACRO_LOW_REV_LIMIT_L 800
#define MACRO_LOW_REV_LIMIT_H 1600



   Fv_AbsUnkownFlag = (Fv_SystemCANDiagStatus[CANBUS_ABSVs] >= FailureDiag_Err);
   Fv_SupportTempErr = ((Fv_ErrDiagStatus[DTC_CANCOMMcheck_Busoff] >= FailureDiag_Err)
						||(Fv_SystemCANDiagStatus[CANBUS_EMSEt] >= FailureDiag_Err)
						||(Fv_StallProCoef > 0)
						||(Fv_StallCompCoef > 0)
						||(fsLRAngleSumOverFlag > 0));
	Fv_SupportAngleErr = ((Fv_ErrDiagStatus[DTC_ANGLEcheck_Unreal] >= FailureDiag_Err)
	                     /*||(Fv_ErrDiagStatus[DTC_ANGLEcheck_CheckRotor] >= FailureDiag_Err)*/
						 ||(Fv_ErrDiagStatus[DTC_ANGLEcheck_Invalid] >= FailureDiag_Err));
#if((MACRO_LKAAC_FUNCTION_ENABLE == 1)|(MACRO_APA_FUNCTION_ENABLE == 1)\
   |(MACRO_VOT_FUNCTION_ENABLE == 1))
   if(Fv_LKAAC_Configuration|Fv_APA_Configuration|Fv_VOT_Configuration)
   {
	    Int16 temp_ang = 0;
		Int16 temp_rev = 0;
		Int16 temp_rev_low = 0;
		Int16 use_rev = 0;
		static UInt8 low_rev_sel = 0;
	#if(MACRO_STEER_DIR == 1)
		temp_ang = (Int16)(Fv_ConvStrAng - Fv_ConvStrAngOffset - Fv_AngleCorrectOpr);//2^-4,deg
		//temp_ang = (Int16)Fv_MotorAngle_Raw;
		temp_rev = -(((((Int32)Fv_FOC_RotorSpd) * ((Int32)MACRO_RAD2RPM)) >> 14)*1200/fsMotorToSteerRatio);//2^-4,deg/s
		temp_rev_low = (((((Int32)Fv_LowRev_spd) * ((Int32)MACRO_RAD2RPM)) >> 14)*1200/fsMotorToSteerRatio);//2^-4,deg/s
	#else
		temp_ang = -(Int16)(Fv_ConvStrAng - Fv_ConvStrAngOffset - Fv_AngleCorrectOpr);//2^-4,deg
		temp_rev = (((((Int32)Fv_FOC_RotorSpd) * ((Int32)MACRO_RAD2RPM)) >> 14)*1200/fsMotorToSteerRatio);//2^-4,deg/s
		temp_rev_low = -(((((Int32)Fv_LowRev_spd) * ((Int32)MACRO_RAD2RPM)) >> 14)*1200/fsMotorToSteerRatio);//2^-4,deg/s
	#endif

		if((temp_rev < MACRO_LOW_REV_LIMIT_L)&&(temp_rev > -MACRO_LOW_REV_LIMIT_L))
		{
			low_rev_sel = 1;
		}
		else if((temp_rev > MACRO_LOW_REV_LIMIT_H)||(temp_rev < -MACRO_LOW_REV_LIMIT_H))
		{
			low_rev_sel = 0;
		}

		if(low_rev_sel == 1)
		{
			use_rev = temp_rev_low;
		}
		else
		{
			use_rev = temp_rev;
		}
	#if(MACRO_LKAAC_FUNCTION_ENABLE == 1)
		Fv_LKAAC_SteerAngleAct = temp_ang;
		Fv_LKAAC_SteerRevAct   = use_rev;
	#endif

	#if(MACRO_APA_FUNCTION_ENABLE == 1)
		Fv_APA_SteerAngleAct = temp_ang;
		Fv_APA_SteerRevAct   = use_rev;
	#endif

	#if(MACRO_VOT_FUNCTION_ENABLE == 1)
		Fv_VOT_SteerAngleAct = temp_ang;
		Fv_VOT_SteerRevAct   = use_rev;
	#endif
   }

#endif

#undef MACRO_LOW_REV_LIMIT_L
#undef MACRO_LOW_REV_LIMIT_H
}
#endif
/****************************************************************
* FUNCTION : MainMilliSecondHandler
* DESCRIPTION : Main processing function per 5ms.
* INPUTS : None
* OUTPUTS : None
****************************************************************/
void AssignAimCurrent(void)
{
#if 0
#define MACRO_MaxCloopCtrlCurrent fsMotorMaxFocCurrentQ
#define MACRO_CoefSlopeExitFromClpCtrl 64//2^-14,閫�鍑篟CS鐨勫姪鍔涚郴鏁版枩鐜囷紝0%-100%

	static UInt16 limit_coef = 16384;
	static Int32 lock_current = 0;
	static Int16 exit_coefslope = 10;

	Int32 step_current = 0;
	Int32 org_current = 0;

    fsEPSCloseLoopCtrlFlag = (Fv_APA_ControlSts == 2) + (Fv_VOT_ControlSts == 2) + (Fv_RCS_State == RCS_STATE_ACT);
   
    if(fsEPSCloseLoopCtrlFlag <= 0)
    {
    	if(limit_coef < 16384)
    	{
    		limit_coef = limit_coef + exit_coefslope;
    	}

        if(limit_coef > 16384)
    	{
    		limit_coef = 16384;
    	}

        step_current = ((Int32)lock_current*(16384-limit_coef)>>14);

        if(step_current == 0)
        {
        	lock_current = 0;
        }

    	org_current = step_current + ((Int32)Fv_PMSMCurrent_OpenLoop*limit_coef>>14);

    	if(org_current > fsMotorMaxFocCurrentQ)
    	{
    		org_current = fsMotorMaxFocCurrentQ;
    	}
    	else if(org_current < -fsMotorMaxFocCurrentQ)
    	{
    		org_current = -fsMotorMaxFocCurrentQ;
    	}

		Fv_PMSMCurrent_ORGQAIM = org_current;
		Tv_TCL_LoopPIDReset = 0;
    }
    else
    {
    	Int32 loop_current = 0;
    	Int32 limit_current = 0;

    	limit_coef = 0;

		loop_current = Fv_APA_Current + Fv_VOT_Current + Fv_RCS_Current;
		exit_coefslope = MACRO_CoefSlopeExitFromClpCtrl;
        
    	limit_current = ((((((Int32)MACRO_MaxCloopCtrlCurrent*(4096U - Tv_StallCompCoef)>>12)\
    			*(4096U - Tv_StallProCoef)>>12)*(32768U - Tv_HighFailCoef)>>15)\
    			*(32768U - Tv_LowFailCoef)>>15)*(32768U - Tv_LimitFailCoef)>>15);

    	if(loop_current > limit_current)
    	{
    		loop_current = limit_current;
    	}
    	else
    	{
    	}

		Fv_PMSMCurrent_ORGQAIM = loop_current;

		lock_current = Fv_PMSMCurrent_ORGQAIM;
		Tv_TCL_LoopPIDReset = 1;
    }

#undef  MACRO_MaxCloopCtrlCurrent
#undef  MACRO_CoefSlopeExitFromClpCtrl
#else
#define MACRO_MaxCloopCtrlCurrent fsMotorMaxFocCurrentQ
#define MACRO_CoefSlopeExitFromClpCtrl 33//2^-14,閫�鍑篟CS鐨勫姪鍔涚郴鏁版枩鐜囷紝0%-100%
#define MACRO_RampDown_CurRate 128

	static UInt16 limit_coef = 16384;
	static Int32 lock_current = 0;
	static Int16 exit_coefslope = MACRO_CoefSlopeExitFromClpCtrl;
	static Int16 exit_coefslope2 = MACRO_CoefSlopeExitFromClpCtrl;
	Int32 step_current = 0;
	Int32 org_current = 0;

    fsEPSCloseLoopCtrlFlag = (Fv_APA_ControlSts == 2);//(Fv_APA_ControlSts == 2) + (Fv_VOT_ControlSts == 2);
   
    if(fsEPSCloseLoopCtrlFlag <= 0)
    {
		if(lock_current != 0)
		{
			if((Fv_PMSMCurrent_ORGQAIM > 3200)||(Fv_PMSMCurrent_ORGQAIM < -3200))
			{
				exit_coefslope2 = 80;
			}
			else
			{
				exit_coefslope2 = exit_coefslope;
			}
		}

    	if(limit_coef < 16384)
    	{
    		limit_coef = limit_coef + exit_coefslope2;
    	}

        if(limit_coef > 16384)
    	{
    		limit_coef = 16384;
    	}

        step_current = ((Int32)lock_current*(16384-limit_coef)>>14);

        if(step_current == 0)
        {
        	lock_current = 0;
        }

    	org_current = step_current + ((Int32)Fv_PMSMCurrent_OpenLoop*limit_coef>>14);

    	if(org_current > fsMotorMaxFocCurrentQ)
    	{
    		org_current = fsMotorMaxFocCurrentQ;
    	}
    	else if(org_current < -fsMotorMaxFocCurrentQ)
    	{
    		org_current = -fsMotorMaxFocCurrentQ;
    	}

		Fv_PMSMCurrent_ORGQAIM = org_current;
		Tv_TCL_LoopPIDReset = 0;
    }
    else
    {
    	Int32 loop_current = 0;
    	Int32 limit_current = 0;

    	limit_coef = 0;

		loop_current = asr_s32(((Int32)Fv_APA_Torque) * ((Int32)Cal_Motor_TrqCoef), 7U);;//Fv_APA_Current + Fv_VOT_Current+ Fv_RCS_Current;
		exit_coefslope = MACRO_CoefSlopeExitFromClpCtrl;
        
    	limit_current = ((((((Int32)MACRO_MaxCloopCtrlCurrent*(4096U - Tv_StallCompCoef)>>12)\
    			*(4096U - Tv_StallProCoef)>>12)*(32768U - Tv_HighFailCoef)>>15)\
    			*(32768U - Tv_LowFailCoef)>>15)*(32768U - Tv_LimitFailCoef)>>15);

    	if(loop_current > limit_current)
    	{
    		loop_current = limit_current;
    	}
    	if(loop_current < -limit_current)
    	{
    		loop_current = -limit_current;
    	}		
    	else
    	{
    	}

		Fv_PMSMCurrent_ORGQAIM = loop_current;

		lock_current = Fv_PMSMCurrent_ORGQAIM;
		Tv_TCL_LoopPIDReset = 1;
    }

#undef  MACRO_MaxCloopCtrlCurrent
#undef  MACRO_CoefSlopeExitFromClpCtrl
#endif
}
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
void BattVolLimitAstMonitor(void)
{
#define MACRO_VOLLIMITAST_DIAG_TMR 100
    static UInt16 low_time_cnt = 0;
	static UInt8 low_limit_flag = 0;

    if((Fv_BatVoltLevel == BAT_VOLT_NORMAL)&&(Fv_SysPower > Cal_Power_Low))
    {
        if(Tv_BatCoef > 0)
        {
            if(low_time_cnt < MACRO_VOLLIMITAST_DIAG_TMR)
            {
                low_time_cnt++;
            }
            else
            {
                low_limit_flag = true;
            }
        }
        else
        {
            low_time_cnt = 0;
            low_limit_flag = false;
        }
    }
    else
    {
        low_time_cnt = 0;
        low_limit_flag = false;
    }

	if(low_limit_flag > 0)
	{
		Fv_ErrDiagStatus[DTC_POWERcheck_VolLimitAst] = FailureDiag_Err;
	}
	else
	{
		Fv_ErrDiagStatus[DTC_POWERcheck_VolLimitAst] = FailureDiag_OK;
	}
	

#undef MACRO_VOLLIMITAST_DIAG_TMR
}
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
void TemperatureLimitAstMonitor(void)
{
#define MACRO_TMPLIMITAST_DIAG_TMR 100
    static UInt16 time_cnt = 0;

    if(Fv_TempLevel == TEMP_CEL_NORMAL)
    {
        if(Tv_TempCompCoef > 0)
        {
            if(time_cnt < MACRO_TMPLIMITAST_DIAG_TMR)
            {
                time_cnt++;
            }
            else
            {
                Fv_ErrDiagStatus[DTC_TEMPcheck_TempLimitAst] = FailureDiag_Err;
            }
        }
        else
        {
            time_cnt = 0;
            Fv_ErrDiagStatus[DTC_TEMPcheck_TempLimitAst] = FailureDiag_OK;
        }
    }
    else
    {
        time_cnt = 0;
        Fv_ErrDiagStatus[DTC_TEMPcheck_TempLimitAst] = FailureDiag_OK;
    }

#undef MACRO_TMPLIMITAST_DIAG_TMR
}
extern volatile Int16 Cal_MTR_DaxisPidKiTabGen_X[8];
extern volatile Int16 Cal_MTR_DaxisPidKiTabGen_Y[6];
extern volatile Int16 Cal_MTR_DaxisPidKiTabGen_Z[48];
extern volatile Int16 Cal_MTR_DaxisPidKpTabGen_X[8];
extern volatile Int16 Cal_MTR_DaxisPidKpTabGen_Y[6];
extern volatile Int16 Cal_MTR_DaxisPidKpTabGen_Z[48];

static UInt32 lmpid_kp_index[2] = {0, 0};
const UInt32 lmpid_kp_indexmax[2] = { 7U, 5U };
static UInt32 lmpid_ki_index[2] = {0, 0};
const UInt32 lmpid_ki_indexmax[2] = { 7U, 5U };
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
void MTR_Daxis_PID(void)
{
	Int16 lmpid_wabs = 0;
	Int16 lmpid_daimabs = 0;

	lmpid_daimabs = Fv_MotorCurrent_Daim1 + Fv_MotorCurrent_Daim2;

	if(lmpid_daimabs < 0)
	{
		lmpid_daimabs = -lmpid_daimabs;
	}

	if((Fv_dRotorAng_rpm > 32000) || (Fv_dRotorAng_rpm < -32000))
	{
		lmpid_wabs = 32000;
	}
	else
	{
		if(Fv_dRotorAng_rpm < 0)
		{
			lmpid_wabs = (Int16)(-Fv_dRotorAng_rpm);
		}
		else
		{
			lmpid_wabs = (Int16)(Fv_dRotorAng_rpm);
		}
	}

	Tv_PID_DI = look2_is16u16ls32n10ts_TlwpcxFz(lmpid_daimabs, lmpid_wabs, ((const
	  		    Int16 *)&(Cal_MTR_DaxisPidKiTabGen_X[0])), ((const Int16 *)
	  		    &(Cal_MTR_DaxisPidKiTabGen_Y[0])), ((const Int16 *)&(Cal_MTR_DaxisPidKiTabGen_Z[0])),
	  		  lmpid_ki_index, lmpid_ki_indexmax, 8U);

	Tv_PID_DP = look2_is16u16ls32n10ts_TlwpcxFz(lmpid_daimabs, lmpid_wabs, ((const
	  		    Int16 *)&(Cal_MTR_DaxisPidKpTabGen_X[0])), ((const UInt16 *)
	  		    &(Cal_MTR_DaxisPidKpTabGen_Y[0])), ((const Int16 *)&(Cal_MTR_DaxisPidKpTabGen_Z[0])),
	  		  lmpid_kp_index, lmpid_kp_indexmax, 8U);
}
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
void DTC_DetailFaultProcess(void)
{
	uint8 temp = 0;
	uint8 storerequest = 0;
	uint16 i = 0;

	for(i = 0; i < EPS_DTC_NUM_MAX; i ++)
	{
		if(DTC_State_Info_Tab[i].testFailed > 0)
		{
			fsDtcTestfailed[i / 8] |= (1 << (i - (i / 8) * 8));
		}
		else
		{
			fsDtcTestfailed[i / 8] &= (~(1 << (i - (i / 8) * 8)));
		}
	}

	for(i = 0; i < 16; i ++)
	{
		temp = fsDtcTestfailed[i] | Eeprom_DTCStatus[i];
		if(temp != Eeprom_DTCStatus[i])
		{
			Eeprom_DTCStatus[i] = temp;
			storerequest = 1;
		}
	}

	if(storerequest > 0)
	{
		NvM_StoreRequest.bit.DemExtra = 1;
	}
}
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
uint8 CCP_ValueCheck(const uint8 * table, uint16 len, uint32 value)
{
	uint8 ret = 0;
	uint16 i = 0;

	for(i = 0; i < len; i ++)
	{
		if(table[i] == value)
		{
			ret = 1;
			break;
		}
	}

	return ret;
}
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
void CCP_NvMStoreProcess(void)
{
	uint8 i = 0;
	Eeprom_CanCCp.data.crc =  CRC8forSAEJ1850(Eeprom_CanCCp.byte, 31);
	NvM_StoreRequest.bit.DemExtra = 1;
}
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
void CCP_DataProcess(uint32 key, uint32 value)
{
	switch(key)
	{
		case 1:
			if(CCP_ValueCheck(CCP1_Table, 12, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp1)
				{
					Eeprom_CanCCp.data.ccp1 = value;
					Fv_CANCCP1 = Eeprom_CanCCp.data.ccp1;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 3:
			if(CCP_ValueCheck(CCP3_Table, 4, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp3)
				{
					Eeprom_CanCCp.data.ccp3 = value;
					Fv_CANCCP3 = Eeprom_CanCCp.data.ccp3;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 13:
			if(CCP_ValueCheck(CCP13_Table, 6, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp13)
				{
					Eeprom_CanCCp.data.ccp13 = value;
					Fv_CANCCP13 = Eeprom_CanCCp.data.ccp13;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 17:
			if(CCP_ValueCheck(CCP17_Table, 83, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp17)
				{
					Eeprom_CanCCp.data.ccp17 = value;
					Fv_CANCCP17 = Eeprom_CanCCp.data.ccp17;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 50:
			if(CCP_ValueCheck(CCP50_Table, 5, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp50)
				{
					Eeprom_CanCCp.data.ccp50 = value;
					Fv_CANCCP50 = Eeprom_CanCCp.data.ccp50;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 58:
			if(CCP_ValueCheck(CCP58_Table, 5, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp58)
				{
					Eeprom_CanCCp.data.ccp58 = value;
					Fv_CANCCP58 = Eeprom_CanCCp.data.ccp58;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 59:
			if(CCP_ValueCheck(CCP59_Table, 4, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp59)
				{
					Eeprom_CanCCp.data.ccp59 = value;
					Fv_CANCCP59 = Eeprom_CanCCp.data.ccp59;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 62:
			if(CCP_ValueCheck(CCP62_Table, 79, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp62)
				{
					Eeprom_CanCCp.data.ccp62 = value;
					Fv_CANCCP62 = Eeprom_CanCCp.data.ccp62;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 100:
			if(CCP_ValueCheck(CCP100_Table, 3, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp100)
				{
					Eeprom_CanCCp.data.ccp100 = value;
					Fv_CANCCP100 = Eeprom_CanCCp.data.ccp100;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 142:
			if(CCP_ValueCheck(CCP142_Table, 11, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp142)
				{
					Eeprom_CanCCp.data.ccp142 = value;
					Fv_CANCCP142 = Eeprom_CanCCp.data.ccp142;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 150:
			if(CCP_ValueCheck(CCP150_Table, 3, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp150)
				{
					Eeprom_CanCCp.data.ccp150 = value;
					Fv_CANCCP150 = Eeprom_CanCCp.data.ccp150;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 317:
			if(CCP_ValueCheck(CCP317_Table, 3, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp317)
				{
					Eeprom_CanCCp.data.ccp317 = value;
					Fv_CANCCP317 = Eeprom_CanCCp.data.ccp317;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 494:
			if(CCP_ValueCheck(CCP494_Table, 11, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp494)
				{
					Eeprom_CanCCp.data.ccp494 = value;
					Fv_CANCCP494 = Eeprom_CanCCp.data.ccp494;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 540:
			if(CCP_ValueCheck(CCP540_Table, 2, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp540)
				{
					Eeprom_CanCCp.data.ccp540 = value;
					Fv_CANCCP540 = Eeprom_CanCCp.data.ccp540;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 547:
			if(CCP_ValueCheck(CCP547_Table, 2, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp547)
				{
					Eeprom_CanCCp.data.ccp547 = value;
					Fv_CANCCP547 = Eeprom_CanCCp.data.ccp547;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 565:
			if((value >= 1) && (value <= 0xFE))
			{
				if(value != Eeprom_CanCCp.data.ccp565)
				{
					Eeprom_CanCCp.data.ccp565 = value;
					Fv_CANCCP565 = Eeprom_CanCCp.data.ccp565;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 609:
			if(CCP_ValueCheck(CCP609_Table, 2, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp609)
				{
					Eeprom_CanCCp.data.ccp609 = value;
					Fv_CANCCP609 = Eeprom_CanCCp.data.ccp609;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 639:
			if((value >= 1) && (value <= 0xFE))
			{
				if(value != Eeprom_CanCCp.data.ccp639)
				{
					Eeprom_CanCCp.data.ccp639 = value;
					Fv_CANCCP639 = Eeprom_CanCCp.data.ccp639;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 640:
			if((value >= 1) && (value <= 0xFE))
			{
				if(value != Eeprom_CanCCp.data.ccp640)
				{
					Eeprom_CanCCp.data.ccp640 = value;
					Fv_CANCCP640 = Eeprom_CanCCp.data.ccp640;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 655:
			if(CCP_ValueCheck(CCP655_Table, 2, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp655)
				{
					Eeprom_CanCCp.data.ccp655 = value;
					Fv_CANCCP655 = Eeprom_CanCCp.data.ccp655;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 695:
			if(CCP_ValueCheck(CCP695_Table, 2, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp695)
				{
					Eeprom_CanCCp.data.ccp695 = value;
					Fv_CANCCP695 = Eeprom_CanCCp.data.ccp695;
					CCP_NvMStoreProcess();
				}
			}
			break;
		case 741:
			if(CCP_ValueCheck(CCP741_Table, 3, value) > 0)
			{
				if(value != Eeprom_CanCCp.data.ccp741)
				{
					Eeprom_CanCCp.data.ccp741 = value;
					Fv_CANCCP741 = Eeprom_CanCCp.data.ccp741;
					CCP_NvMStoreProcess();
				}
			}
			break;
		default:
			break;
	}
}
#if 0
/**************************************************************
* FUNCTION :
* DESCRIPTION :
* INPUTS :
* OUTPUTS :
****************************************************************/
void SysAstDegradeMonitor(void)
{
#define MACRO_SYSLIMITAST_DIAG_TMR  5
#define MACRO_SYSLIMITAST_DIAG_TMR2 20
#define MACRO_SYSLIMITAST_DIAG_TMR3 100

    static UInt16 time_cnt = 0;
    static UInt16 time_cnt2 = 0;
	static UInt16 time_cnt3 = 0;
	static UInt8 not_ready = 0;
    static UInt8 heat_prt = 0;
	static UInt8 bat_prt = 0;
	static UInt8 high_limit_flag = 0;
	static UInt16 high_time_cnt = 0;
	static UInt8 sum_ang_over = 0;
	static UInt16 sum_time_cnt1 = 0;
	static UInt16 sum_time_cnt2 = 0;
	if((Fv_WhichMode == HOLD_CRANK) || (Fv_WhichMode == HOLD_LIMIT))
	{
		if(time_cnt < MACRO_SYSLIMITAST_DIAG_TMR)
		{
			time_cnt++;
		}
		else
		{
			not_ready = 1;
		}	
	}
	else
	{
		time_cnt = 0;
        not_ready = 0;
	}
	if((Tv_StallProCoef > 0) || (Tv_StallCompCoef > 0))
	{
		if(time_cnt2 < MACRO_SYSLIMITAST_DIAG_TMR2)
		{
			time_cnt2++;
		}
		else
		{
			heat_prt = 1;
		}		
	}
	else
	{
		time_cnt2 = 0;
		heat_prt = 0;
	}

	if(Fv_SysPower > Cal_Power_High)
	{
		if(high_time_cnt < MACRO_SYSLIMITAST_DIAG_TMR3)
		{
			high_time_cnt++;
		}
		else
		{
			high_limit_flag = true;
		}
	}
	else
	{
		high_time_cnt = 0;
		high_limit_flag = false;
	}

	if(Tv_BatCoef > 0)
	{
		if(time_cnt3 < MACRO_SYSLIMITAST_DIAG_TMR3)
		{
			time_cnt3++;
		}
		else
		{
			bat_prt = 1;
			
		}		
	}
	else
	{
		time_cnt3 = 0;
		bat_prt = 0;

	}

	if((not_ready > 0)||(heat_prt > 0)||(bat_prt > 0)||(high_limit_flag > 0))
	{
		Fv_ErrDiagStatus[DTC_ASTcheck_AstDegrade] = FailureDiag_Err;
	}
	else
	{
		Fv_ErrDiagStatus[DTC_ASTcheck_AstDegrade] = FailureDiag_RegOK;
	}
#define MACRO_LRSum_AngLimit 960
#define MACRO_LRSum_OverTime 50
	if(/*(Fv_AngleEndPreStudyL > 0)&&(Fv_AngleEndPreStudyR > 0)&&*/
	   (Fv_AngleMidValidFlag == ANGLE_STS_Valid)
	 &&(Fv_AngleReadyFlag == HELLA_STS_Decode))
	{
		Int16 sum_ang = 0;

		if(Tv_StrAng_Raw < 0)
		{
		    sum_time_cnt2 = 0;
           sum_ang = Tv_StrAng_Raw + Tv_SE_RightMaxAng;
		   if(sum_ang < -MACRO_LRSum_AngLimit)
		   {
				if(sum_time_cnt1 < MACRO_LRSum_OverTime)
			  {
				    sum_time_cnt1++;
			  }
			  else
			  {
				sum_ang_over = 1;
			  }
		   }
		   else
		   {
			   sum_ang_over = 0;
			   sum_time_cnt1 = 0;
		   }
		}
		else
		{
			sum_time_cnt1 = 0;
			sum_ang = Tv_StrAng_Raw + Tv_SE_LeftMaxAng;
		   if(sum_ang > MACRO_LRSum_AngLimit)
		   {
				if(sum_time_cnt2 < MACRO_LRSum_OverTime)
			  {
					sum_time_cnt2++;
			  }
			  else
			  {
				sum_ang_over = 1;
			  }
		   }
		   else
		   {
			   sum_ang_over = 0;
				sum_time_cnt2 = 0;
		   }
		}
	}
	else
	{
		sum_ang_over = 0;
		sum_time_cnt1 = 0;
		sum_time_cnt2 = 0;
	}
#undef MACRO_LRSum_AngLimit
#undef MACRO_LRSum_OverTime
   fsLRAngleSumOverFlag = sum_ang_over;
    if((Fv_ErrDiagStatus[DTC_ANGLEcheck_Invalid] >= FailureDiag_Err)||(sum_ang_over > 0))
	{
		Fv_ErrDiagStatus[DTC_ANGLEcheck_ExtAngleErr] = FailureDiag_Err;
	}
	else
	{
		Fv_ErrDiagStatus[DTC_ANGLEcheck_ExtAngleErr] = FailureDiag_RegOK;
	}

#undef MACRO_SYSLIMITAST_DIAG_TMR  
#undef MACRO_SYSLIMITAST_DIAG_TMR2 
#undef MACRO_SYSLIMITAST_DIAG_TMR2 
}
#endif
