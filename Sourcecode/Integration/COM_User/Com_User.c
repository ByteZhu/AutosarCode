#include "Com_Cbk.h"
#include "Com_User.h"

uint8 COMTimeoutFlag[CANBUS_Num]={0,};
uint8 COMRxFlag[CANBUS_Num]={0,};
uint8 COMRxLostFlag[CANBUS_Num]={0,};
uint8 COMRxVailFlag[CANBUS_Num]={0,};
uint8 COMRxVailFlag1[CANBUS_Num]={0,};
uint8 COMRxVailFlag2[CANBUS_Num]={0,};
uint8 COMRxVailFlag3[CANBUS_Num]={0,};
uint8 COMRxVailFlag4[CANBUS_Num]={0,};
uint8 Tx_SACM_SecCanFrame01_Flag = 0;
uint8 Tx_SACMFram01_Flag = 0;
uint8 Tx_SACMFram02_Flag = 0;
uint8 Tx_SFCMBCCanFDFrame01_Flag = 0;

uint8 EtcToPscmDevelFr_UpdateFlag;
uint8 ComXcp_Data[8] = {0,};
//TX
void ComNoti_Calback_TX_77A(void)
{

}
void ComNoti_Calback_TX_7FE(void)
{

}
void ComNoti_Calback_TX_380(void)
{

}
void ComNoti_Calback_TX_55(void)
{
	Tx_SACMFram01_Flag = 0;
}
void ComNoti_Calback_TX_179(void)
{
	Tx_SACMFram02_Flag = 0;
}
void ComNoti_Calback_TX_47(void)
{

}
void ComNoti_Calback_TX_251(void)
{

}
void ComNoti_Calback_TX_102(void)
{
	Tx_SACM_SecCanFrame01_Flag = 0;
}
void ComNoti_Calback_TX_186(void)
{
	Tx_SFCMBCCanFDFrame01_Flag = 0;
}
void ComNoti_Calback_TX_232(void)
{
	}
void ComNoti_Calback_TX_382(void)
{
	}
void ComNoti_Calback_TX_760(void)
{
	}
void ComNoti_Calback_TX_2(void)
{
	}

//CAN1
void ComNoti_Calback_TX_11(void)
{

}
/*Rx timeout*/
void Comtimeout_Calback_0x50(void)//0
{
    COMTimeoutFlag[CANBUS_ID_0x50] = 0xAA;
}
void Comtimeout_Calback_0x51(void)//1
{
	COMTimeoutFlag[CANBUS_ID_0x51] = 0xAA;
}
void Comtimeout_Calback_0x52(void)//2
{
	COMTimeoutFlag[CANBUS_ID_0x52] = 0xAA;
}
void Comtimeout_Calback_0x201(void)//3
{
	COMTimeoutFlag[CANBUS_ID_0x201] = 0xAA;
}

void Comtimeout_Calback_0x200(void)//4
{
	COMTimeoutFlag[CANBUS_ID_0x200] = 0xAA;
}
void Comtimeout_Calback_0x400(void)//7
{
	COMTimeoutFlag[CANBUS_ID_0x400] = 0xAA;
}
void Comtimeout_Calback_0x40(void)//8
{
	COMTimeoutFlag[CANBUS_ID_0x40] = 0xAA;
}
void Comtimeout_Calback_0x243(void)//9
{
	COMTimeoutFlag[CANBUS_ID_0x234] = 0xAA;
}
void Comtimeout_Calback_0x99(void)//10
{
	COMTimeoutFlag[CANBUS_ID_0x99] = 0xAA;
}
void Comtimeout_Calback_0xFE(void)//11
{
	COMTimeoutFlag[CANBUS_ID_0xfe] = 0xAA;
}
void Comtimeout_Calback_0x62(void)
{
	COMTimeoutFlag[CANBUS_ID_0x62] = 0xAA;
}
/*Rx Notifi*/
void ComNoti_Calback_0x50(void)//0
{
	COMRxFlag[CANBUS_ID_0x50] = 0xAA;
}
void ComNoti_Calback_0x51(void)//1
{
	COMRxFlag[CANBUS_ID_0x51] = 0xAA;
}
void ComNoti_Calback_0x52(void)//2
{
	COMRxFlag[CANBUS_ID_0x52] = 0xAA;
}

void ComNoti_Calback_0x201(void)//4
{
	COMRxFlag[CANBUS_ID_0x201] = 0xAA;
}
void ComNoti_Calback_0x200(void)//6
{
	COMRxFlag[CANBUS_ID_0x200] = 0xAA;
}
void ComNoti_Calback_0x400(void)//7
{
	COMRxFlag[CANBUS_ID_0x400] = 0xAA;
}
void ComNoti_Calback_0x40(void)//8
{
	COMRxFlag[CANBUS_ID_0x40] = 0xAA;
}
void ComNoti_Calback_0x243(void)//9
{
	COMRxFlag[CANBUS_ID_0x234] = 0xAA;
}
void ComNoti_Calback_0x99(void)//10
{
	COMRxFlag[CANBUS_ID_0x99] = 0xAA;
}
void ComNoti_Calback_0xfe(void)//11
{
	COMRxFlag[CANBUS_ID_0xfe] = 0xAA;
}
void ComNoti_Calback_0x62(void)//11
{
	COMRxFlag[CANBUS_ID_0x62] = 0xAA;
}

void ComNoti_Calback_0x1A0(void)
{

}


void ComNoti_Calback_0x20(void)
{

}

void COM_XCP1_Callback(void)
{
	uint8 i = 0;
	uint32 addr = 0;

	addr = 0xf02005F8UL;//0xF0200178;

	for(i = 0; i < 8; i ++)
	{
		ComXcp_Data[i] = ((uint8 *)addr)[i];
	}
	EtcToPscmDevelFr_UpdateFlag = 0xAA;
}

void COM_XCP_Callback(void)
{


}
void COM_Angle_Callback(void)
{

}
