/*
 * Sent_Callback.c
 *
 *  Created on: 2023??5??23??
 *      Author: tiand
 */
#include "sent.h"

uint16 Sent_DataBuffer[8] = {0};
uint16 Sent_T1SentToPwm = 0;
uint16 Sent_T2SentToPwm = 0;
uint16 Sent_ASSentToPwm = 0;
uint16 Sent_ASSentToPwm1 = 0;
uint16 Sent_APSentToPwm = 0;
uint16 Sent_T1Count = 0;
uint16 Sent_T2Count = 0;
uint16 Sent_ASCount = 0;
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
* LIMIT: None
****************************************************************/
void SENT1_ISR_Process (Sent_ChannelIdxType ChannelId,Sent_NotifType Stat)
{
	uint32 data = 0;

	if((Stat & 0x33E0) > 0)
	{
		Sent_DataBuffer[0] = 0;
		Sent_DataBuffer[1] = 0;
		Sent_ASSentToPwm = 0;

	}
	else
	{
		data = Sent_ReadData(0);
		Sent_DataBuffer[0] = (uint16)(data & 0x00000FFF);
		Sent_DataBuffer[1] = (uint16)((data & 0x00FFF000)>>12);

		if((Sent_DataBuffer[0] < 1) || (Sent_DataBuffer[0] > 4088))
		{
			Sent_ASSentToPwm = 0;
		}
		else
		{
			Sent_ASSentToPwm = (uint16)(((uint32)(Sent_DataBuffer[0] - 1) * 7500) / 4087 + 1250);
		}
	}

	Sent_ASCount = 0;
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
* LIMIT: None
****************************************************************/
void SENT8_ISR_Process (Sent_ChannelIdxType ChannelId,Sent_NotifType Stat)
{
	uint32 data = 0;

	if((Stat & 0x33E0) > 0)
	{
		Sent_DataBuffer[6] = 0;
		Sent_DataBuffer[7] = 0;
		Sent_ASSentToPwm1 = 0;

	}
	else
	{
		data = Sent_ReadData(2);
		Sent_DataBuffer[6] = (uint16)(data & 0x00000FFF);
		Sent_DataBuffer[7] = (uint16)((data & 0x00FFF000)>>12);

		if((Sent_DataBuffer[0] < 1) || (Sent_DataBuffer[0] > 4088))
		{
			Sent_ASSentToPwm1 = 0;
		}
		else
		{
			Sent_ASSentToPwm1 = (uint16)(((uint32)(Sent_DataBuffer[0] - 1) * 7500) / 4087 + 1250);
		}
	}

	Sent_ASCount = 0;
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
* LIMIT: None
****************************************************************/
void SENT4_ISR_Process (Sent_ChannelIdxType ChannelId,Sent_NotifType Stat)
{
	uint32 data = 0;

	if((Stat & 0x33E0) > 0)
	{
		Sent_DataBuffer[2] = 0;
		Sent_DataBuffer[3] = 0;
		Sent_T1SentToPwm = 0;

	}
	else
	{
		data = Sent_ReadData(3);
		Sent_DataBuffer[2] = (uint16)(data & 0x00000FFF);
		Sent_DataBuffer[3] = (uint16)((data & 0x00FFF000)>>12);
		if((Sent_DataBuffer[3] < 8) || (Sent_DataBuffer[3] > 4087))
		{
			Sent_T1SentToPwm = 0;
		}
		else
		{
			Sent_T1SentToPwm = (uint16)(((uint32)(Sent_DataBuffer[3] - 8) * 7500) / 4080 + 1250);
		}
	}
	Sent_T1Count = 0;
}
/****************************************************************
* FUNCTION :  None
* DESCRIPTION : None
* INPUTS :  None
* OUTPUTS : None
* LIMIT: None
****************************************************************/
void SENT2_ISR_Process (Sent_ChannelIdxType ChannelId,Sent_NotifType Stat)
{
	uint32 data = 0;

	if((Stat & 0x33E0) > 0)
	{
		Sent_DataBuffer[4] = 0;
		Sent_DataBuffer[5] = 0;
		Sent_T2SentToPwm = 0;
		Sent_APSentToPwm = 0;
	}
	else
	{
		data = Sent_ReadData(1);

		Sent_DataBuffer[4] = (uint16)(data & 0x00000FFF);
		Sent_DataBuffer[5] = (uint16)((data & 0x00FFF000)>>12);

		if((Sent_DataBuffer[5] < 8) || (Sent_DataBuffer[5] > 4087))
		{
			Sent_T2SentToPwm = 0;
		}
		else
		{
			Sent_T2SentToPwm = (uint16)(((uint32)(Sent_DataBuffer[5] - 8) * 7500) / 4080 + 1250);
		}

		if((Sent_DataBuffer[4] < 2) || (Sent_DataBuffer[4] > 4094))
		{
			Sent_APSentToPwm = 0;
		}
		else
		{
			Sent_APSentToPwm = (uint16)(((uint32)(Sent_DataBuffer[4] - 2) * 7500) / 4092 + 1250);
		}
	}

	Sent_T2Count = 0;
}

