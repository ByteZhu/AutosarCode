/*
 * portability.h
 *
 *  Created on: 2017-9-25
 *      Author: TIAN
 */

#ifndef PORTABILITY_H_
#define PORTABILITY_H_

#include "common.h"
#include "IoHwAb.h"
#include "FilterLibrary.h"


enum
{
	SPI_StateInit0 = 0,
	SPI_StateInit1,
	SPI_StateNormal,
	SPI_StateError,
	SPI_StateShutdown
};

enum
{
	TRSM_FAULT = 1,
    TRSM_COREVCC,
    TRSM_IGKEY,
    TRSM_BAT,
    TRSM_DAC,
    TRSM_RELAY,
    TRSM_PREDRIVER,
    TRSM_COMOUTCNT,
    TRSM_COMNUMCNT,
    TRSM_COMCRCCNT
};

enum
{
  EPS_AglCalReq_Msg /* ID: 0x0000077a, Handle: 0, EPS_AngleCalibrateRequest [FC] */, 
  CCP_Request_Msg /* ID: 0x00000699, Handle: 1, CCP_Request [FC] */, 
  ECU_Media_2_Msg /* ID: 0x000004e3, Handle: 2, ECU_Media_2 [FC] */, 
  ECU_CCU2_Msg /* ID: 0x00000410, Handle: 3, ECU_CCU2 [FC] */, 
  ECU_Media_1_Msg /* ID: 0x000003e3, Handle: 4, ECU_Media_1 [FC] */, 
  ECU_SCU_Msg /* ID: 0x0000035c, Handle: 5, ECU_SCU [FC] */, 
  ECU_CCU3_Msg /* ID: 0x00000341, Handle: 6, ECU_CCU3 [FC] */, 
  ECU_ADS2_Msg /* ID: 0x00000316, Handle: 7, ECU_ADS2 [FC] */, 
  ECU_Media_3_Msg /* ID: 0x000002b6, Handle: 8, ECU_Media_3 [FC] */, 
  ECU_BCM1_Msg /* ID: 0x00000299, Handle: 9, ECU_BCM1 [FC] */, 
  ECU_IPB6_Msg /* ID: 0x0000027e, Handle: 10, ECU_IPB6 [FC] */, 
  ECU_VTOG3_Msg /* ID: 0x00000240, Handle: 11, ECU_VTOG3 [FC] */, 
  ECU_IPB2_Msg /* ID: 0x00000222, Handle: 12, ECU_IPB2 [FC] */, 
  ECU_IPB3_Msg /* ID: 0x000001f0, Handle: 13, ECU_IPB3 [FC] */, 
  ECU_ADS1_Msg /* ID: 0x000001e2, Handle: 14, ECU_ADS1 [FC] */, 
  ECU_APA_Msg /* ID: 0x00000134, Handle: 15, ECU_APA [FC] */, 
  ECU_BCM2_Msg /* ID: 0x0000012d, Handle: 16, ECU_BCM2 [FC] */, 
  ECU_IPB5_Msg /* ID: 0x00000123, Handle: 17, ECU_IPB5 [FC] */, 
  ECU_IPB1_Msg /* ID: 0x00000121, Handle: 18, ECU_IPB1 [FC] */, 
  TestRequest_Msg /* ID: 0x00000001, Handle: 19, TestRequest [FC] */, 
  ECU_DiagFun_Msg /* ID: 0x000007df, Handle: 20, EPS_DiagRequestFcn [FC] */, 
  ECU_DiagPhy_Msg /* ID: 0x00000783, Handle: 21, EPS_DiagRequestPhy [FC] */,
  ECU_CCU1_Msg /* ID: 0x000000F4, Handle: 22, ECU_CCU1 [FC] */, 
  ECU_IPB7_Msg,
};
enum
{
  phyreq,
  funreq,
  EPS_AngleCalibrateRequest_DLC /* ID: 0x0000077a, Handle: 0, EPS_AngleCalibrateRequest [FC] */, 
  CCP_Request_DLC /* ID: 0x00000699, Handle: 1, CCP_Request [FC] */, 
  ECU_Media_2_DLC /* ID: 0x000004e3, Handle: 2, ECU_Media_2 [FC] */, 
  ECU_Left_BCM2_DLC /* ID: 0x000004bf, Handle: 3, ECU_Left_BCM2 [FC] */, 
  ECU_VTOG2_DLC /* ID: 0x00000410, Handle: 4, ECU_VTOG2 [FC] */, 
  ECU_Media_1_DLC /* ID: 0x000003e3, Handle: 5, ECU_Media_1 [FC] */, 
  ECU_SCU_DLC /* ID: 0x0000035c, Handle: 6, ECU_SCU [FC] */, 
  ECU_VTOG1_DLC /* ID: 0x00000341, Handle: 7, ECU_VTOG1 [FC] */, 
  ECU_Left_BCM1_DLC /* ID: 0x00000336, Handle: 8, ECU_Left_BCM1 [FC] */, 
  ECU_MPC1_DLC /* ID: 0x00000316, Handle: 9, ECU_MPC1 [FC] */, 
  ECU_Media_3_DLC /* ID: 0x000002b6, Handle: 10, ECU_Media_3 [FC] */, 
  ECU_IKey_DLC /* ID: 0x00000299, Handle: 11, ECU_IKey [FC] */, 
  ECU_IPB5_DLC /* ID: 0x0000027e, Handle: 12, ECU_IPB5 [FC] */, 
  ECU_VTOG3_DLC /* ID: 0x00000240, Handle: 13, ECU_VTOG3 [FC] */, 
  ECU_IPB7_DLC/* ID: 0x00000223, Handle: 14, ECU_IPB7 [FC] */, 
  ECU_IPB3_DLC /* ID: 0x00000222, Handle: 15, ECU_IPB3 [FC] */, 
  ECU_IPB2_DLC /* ID: 0x000001f0, Handle: 16, ECU_IPB2 [FC] */, 
  ECU_MPC2_DLC /* ID: 0x000001e2, Handle: 17, ECU_MPC2 [FC] */, 
  ECU_APA_DLC /* ID: 0x00000134, Handle: 18, ECU_APA [FC] */, 
  ECU_BCM_DLC/* ID: 0x0000012d, Handle: 19, ECU_BCM [FC] */,
  ECU_IPB4_DLC /* ID: 0x00000123, Handle: 20, ECU_IPB4 [FC] */, 
  ECU_IPB1_DLC /* ID: 0x00000121, Handle: 21, ECU_IPB1 [FC] */, 
  TestRequest_DLC /* ID: 0x00000001, Handle: 22, TestRequest [FC] */, 
};

typedef enum
{
	STOREMANAGER_IDLE,
	STOREMANAGER_BUSY,
	STOREMANAGER_ERROR
}StoreManager_StatusType;

#define  SetPowerLatch(v)			
#define  SetWatchDogFeed(v)			
#define	 SetTrqPwrSpl(v)			
#define	 SetRtrTrmSpl(v)			v
#define  SetEEPROMHOLD(v)			
#define  SetMainRelay(v)    		
#define  SetPhaseRelay(v)    		

#define	 SetPreCharge(v)
#define  SetPreDrvSCDL(v)
#define  SetPreDrvVCT(v)
#define  SetPreDrvENH(v)    		
#define  SetPreDrvINH(v)    		
#define  SetLINENABLE(v)
#define  SetCANENABLE(v)    		

#define	 SetTrqPwrRef(v)

#define  FeedExternWatchDogAgain()

#define EnableTorqueSensorPowerSupply()		((SysTaskTrqSplPending = TRUE))
#define DisableTorqueSensorPowerSupply()    ((SysTaskTrqSplPending = FALSE))
#define DisableResolverPowerSupply()  		((SysTaskRsvSnsPending = FALSE))
#define EnableResolverPowerSupply()			((SysTaskRsvSnsPending = TRUE))

#define GET_PREDRIVER_PWMDUTY1    IoHwAb_GetPredriver01PwmDuty
#define GET_PREDRIVER_PWMDUTY2    IoHwAb_GetPredriver02PwmDuty

#define OpenRelay()         (SysTaskMainRelayPending = TRUE)

#define OpenPhase()         (SysTaskPhaseRelayPending = TRUE)

#define CloseRelay()        (SysTaskMainRelayPending = FALSE)

#define ClosePhase()        (SysTaskPhaseRelayPending = FALSE)


extern Int16 PMSM_FOC_AtanCalcu(Int16 sin_a,Int16 cos_a);

extern UInt8 CRC8forSAEJ1850(UInt8 *u8_data,UInt8 u8_len);

extern UInt8 CRC8forBYD(UInt8 *u8_data,UInt8 u8_len);

extern UInt16 GetPredriverDiagInfoReal(void);

extern UInt8 CheckSumGeely(UInt8 *u8_data,UInt8 u8_len);

extern void CalcShuntCurrent(void);

extern void UpdateReceiveMessageCounter(void);

extern void SetPhaseIndp1(uint8 v);

extern void SetPhaseIndp2(uint8 v);

extern void EpsTrqFilter(void);

extern void SetVsPhaseFlag(void);


extern void Init_CalcFirCoef(void);
#if defined(ENABLE_CHECKSUM_AND_COUNTER)
extern UInt8 CheckSum_CanBus(UInt8 *u8_data,UInt8 u8_len);
#endif

extern void OpenPredriveIndp1(void);

extern void OpenPredriveIndp2(void);

extern void GetPrediverPwmDuty(void);

extern void AngleCalib(void);

extern void WheelSpeedFilter(void);

extern void CalcLowRtrSpd(void);

extern void filtertrw(Float64 rtu_f1, Float64 rtu_f2, Float64 rtu_f3, Float64 rtu_f0,
               Float64 rtu_c, Float64 rtu_T0, Float64 rty_y1[8], Float64 rty_y2[8]);

extern Int16 ToruqeRobustfilterFun(Int16 input);

extern Int16 OffCenterSATFun(Int16 input);

extern Int16 ToruqeNotchFilterFun(Int16 input);

extern Int16 TorqueSoftAdv2Fun(Int16 input);

extern Int16 ToruqeStableFilterFun(Int16 input);

extern Int16 TorqueSoftAdvFun(Int16 input);

extern Int16 OnCenterKickFun(Int16 input);

extern void OpenPredrive(void);

extern void OpenPredrive1(void);

extern void OpenPredrive2(void);

extern void ClosePredrive(void);

extern void ClosePredrive1(void);

extern void ClosePredrive2(void);

extern uint8 Compare_Msg_Length(uint8 DLC,uint8 Legallth);

extern void FailDiag_BYDNewFaultCollection(void);

extern void MTR_Daxis_PID(void);

extern void UpdateReceiveMessageCounter(void);

inline UInt8 CheckSumForxxx(UInt8 *u8_data,UInt8 u8_len)
{
	UInt8 i = 0;
	UInt8 u8_crc8 = 0;

	for(i = 0; i < u8_len; i++)
	{
		u8_crc8 = u8_crc8 + u8_data[i];
	}
	return u8_crc8;
}
/* BEGIN_FUNCTION_HDR
********************************************************************
* Function Name: CheckSumForReceiveMessage
* Description: 閿熸枻鎷烽敓鏂ゆ嫹Checksum Function閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓琛楁枻鎷烽敓妗斿姞鍜岋綇鎷烽敓鏂ゆ嫹鍙栭敓鏂ゆ嫹閿熻鏂ゆ嫹
*
*
* Inputs: 閿熸枻鎷烽敓鏂ゆ嫹鎸囬敓鏂ゆ嫹:u8_data, 閿熸枻鎷烽敓鏂ゆ嫹鎸囬敓璇暱閿熸枻鎷�:u8_len
*
*
* Outputs: checksum鏍￠敓鏂ゆ嫹閿熸枻鎷�
*
*
* Limitations:
********************************************************************
END_FUNCTION_HDR*/
inline UInt8 CheckSumForReceiveMessage(UInt8 *u8_data,UInt8 u8_len)
{
	UInt8 i = 0;
	UInt8 u8_crc8 = 0;

	for(i = 0; i < u8_len; i++)
	{
		u8_crc8 = u8_crc8 + u8_data[i];
	}
	return u8_crc8 ^ 0xFF;
}
inline unsigned short CRC16_CCITT_FALSE(unsigned char *data, unsigned int datalen)
{
	unsigned short wCRCin = 0xFFFF;
	unsigned short wCPoly = 0x1021;
	while (datalen--) 	
	{
		wCRCin ^= *(data++) << 8;
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x8000)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin);
}
/******************************************
**Function name: CompareCheckSum
**Describe: 閿熸枻鎷烽敓鏂ゆ嫹閿熺Ц鎲嬫嫹閿熸枻鎷稢hecksum鍊�
**input: ReCheckSum:閿熸枻鎷烽敓绉告唻鎷烽敓渚ョ鎷稢hecksum鍊�
         CalCheckSum閿熸枻鎷烽敓鏂ゆ嫹閿熸埅纭锋嫹閿熸枻鎷烽敓鏂ゆ嫹閿熺春hecksum鍊�
		 MsgEnum閿熸枻鎷烽敓鏂ゆ嫹瑕侀敓鏂ゆ嫹閿熺春hecksum鍊奸敓渚ユ枻鎷烽敓绉告唻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹
**return: 0:閿熺即鐧告嫹閿熸枻鎷�1閿熸枻鎷峰け閿熸枻鎷�
**Modification record: 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓缁炶淳绛夘偓鎷烽敓鏂ゆ嫹閿熻娇锟�0閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋湭閿熸枻鎷峰叏閿熸枻鎷峰閿熸枻鎷烽敓鏂ゆ嫹閿熼摪绛规嫹閿熸枻鎷烽敓鏂ゆ嫹鏁堥敓鏂ゆ嫹鍙查敓鏂ゆ嫹閿熸枻鎷�--TXY--20220909
*******************************************/
//extern UInt8 MessageCRCErrorFlag[kCanNumberOfRxObjects];//閿熸枻鎷烽敓鑺傚瓨鍌ㄩ敓鏂ゆ嫹閿熸枻鎷锋牎閿熸枻鎷烽敓鏂ゆ嫹--TXY--20221124
extern UInt8 CompareCheckSum(UInt16 ReCheckSum,UInt16 CalCheckSum,UInt8 MsgEnum);
/******************************************
**Function name: CheckRolling
**Describe: 閿熸枻鎷烽敓鏂ゆ嫹閿熺Ц鎲嬫嫹閿熶茎鐧告嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰��
**input: u8_cnt:閿熸枻鎷烽敓绉告唻鎷烽敓渚ョ殑纭锋嫹閿熸枻鎷峰��
         MsgEnum閿熸枻鎷烽敓鏂ゆ嫹瑕侀敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹鍊奸敓渚ユ枻鎷烽敓绉告唻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹
**return: 0:閿熺即鐧告嫹;1:澶遍敓鏂ゆ嫹
**Modification record: 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓缁炶淳绛夘偓鎷烽敓鏂ゆ嫹閿熻娇锟�0閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋湭閿熸枻鎷峰叏閿熸枻鎷峰閿熸枻鎷烽敓鏂ゆ嫹閿熼摪绛规嫹閿熸枻鎷烽敓鏂ゆ嫹鏁堥敓鏂ゆ嫹鍙查敓鏂ゆ嫹閿熸枻鎷�--TXY--20220909
*******************************************/
//extern UInt8 MessageCounterErrorFlag[kCanNumberOfRxObjects];//閿熸枻鎷烽敓鑺傚瓨鍌ㄩ敓鏂ゆ嫹閿熸枻鎷锋牎閿熸枻鎷烽敓鏂ゆ嫹--TXY--20221124
extern UInt8 CheckRolling(UInt16 u8_cnt,UInt8 MsgEnum,UInt8 len);

extern void AssistModeSwitch(void);
extern void LKATurnCurveSel(void);
extern void SteerAssistModeSet(void);

extern void ExternalCtrlPrioritySet(void);
extern void SupportVarSet(void);
extern void AssignAimCurrent(void);
extern void BattVolLimitAstMonitor(void);
extern void TemperatureLimitAstMonitor(void);
extern void SysAstDegradeMonitor(void);

extern void DTC_DetailFaultProcess(void);

extern void CCP_DataProcess(uint32 key, uint32 value);

#endif /* PORTABILITY_H_ */
