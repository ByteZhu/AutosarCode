/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Project :    ETAS Entry Platform
 * Component:  ASW_DEM
 * Description: Testcode for ASW_DEM
 * Version         Author:       Date               Update information
 * 1.0             HAD1HC        04-Mar-2021        Initial version
 * 1.1             HAD1HC        13-Apr-2021        Update Memmap
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************/

#include "Rte_ASW_DEM.h"
#include "ASW_DEM.h"
#include "Com_User.h"
#include "Dem_Cfg_EventId.h"
#include "Rte_Dem_Type.h"
#include "common.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :ASW_DEM_PeriodicRunnable_10ms_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */
uint8 DEM_EventTestFailed[DEM_EVENTID_ARRAYLENGTH] = {0,};
/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :ASW_DEM_PeriodicRunnable_10ms_func) ENABLED START */
/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :DemSwc_RE_Dem_SWC_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */

#define ASW_DEM_START_SEC_VAR_INIT_8
#include "ASW_DEM_MemMap.h"
uint8 Dem_Testcase = 0x0A, DemOperationCycleControl = 0;
uint8 isQualified = FALSE;
uint8 PfcQualified_Trigger = FALSE;
#define ASW_DEM_STOP_SEC_VAR_INIT_8
#include "ASW_DEM_MemMap.h"
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define ASW_DEM_START_SEC_CODE                   
#include "ASW_DEM_MemMap.h"
/* Block signals and states (default storage) */
DW_l5cf_1 rtDW_l5cf_1;
const volatile UInt16 Cal_EXT_ModeSwitchTMR = 500U;

void CAN_Check_DTC(void);
void Public_constantCheck(void);
void Safety_constantCheck(void);
uint8 CAN_Check_PR(uint16 index);
FUNC (void, ASW_DEM_CODE) ASW_DEM_PeriodicRunnable_10ms_func/* return value & FctID */
(
		void
)
{

	uint8 i = 0;

	for(i = 0; i < EPS_DTC_NUM_MAX; i++)
	{
		// if(DTC_CodeStrInfo[i].Num < DEM_EVENTID_ARRAYLENGTH)
		// {
		// 	DEM_EventTestFailed[DTC_CodeStrInfo[i].Num] |= DTC_State_Info_Tab[i].testFailed ;
		// }
	}

	for(i = 1; i < DEM_EVENTID_COUNT; i ++)
	{
		if(CAN_Check_PR(i) !=CAN_TYPE_OK )
		{
			if(DEM_EventTestFailed[i] > 0)
			{
				Dem_SetEventStatus(i, DEM_EVENT_STATUS_PREFAILED);
			}
			else
			{
				Dem_SetEventStatus(i, DEM_EVENT_STATUS_PREPASSED);
			}
		}
	}
  /*DemConf_DemEventParameter_DTC_0xd0c451_Event
	DemConf_DemEventParameter_DTC_0xdc4088_Event
	DemConf_DemEventParameter_DTC_0xDC5088_Event
	DemConf_DemEventParameter_DTC_0xd0c568_Event其他处处理*/

//	Dem_OperationCycleStateType CycleState5;
//	Dem_OperationCycleStateType CycleState6;
//	Dem_OperationCycleStateType CycleState7;
//	Dem_OperationCycleStateType CycleState8;

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :ASW_DEM_PeriodicRunnable_10ms_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	ModeChangeDelay_step();
	CAN_Check_DTC();
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	// if( DemOperationCycleControl == 0 )
    // {
    // 	Rte_Call_RPort_OpCycle_DemOperationCycle_Power_SetOperationCycleState(DEM_CYCLE_STATE_START);
	// 	DemOperationCycleControl = 255;
    // }

    // if( DemOperationCycleControl == 1 )
    // {
    // 	Rte_Call_RPort_OpCycle_DemOperationCycle_Power_SetOperationCycleState(DEM_CYCLE_STATE_END);
	// 	DemOperationCycleControl = 255;
    // }


	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :ASW_DEM_PeriodicRunnable_10ms_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}
void CAN_Check_DTC(void)
{
	uint8 i=0;

	/*CANBUS_ID_0x50=0,
	CANBUS_ID_0x51,
	CANBUS_ID_0x52,
	CANBUS_ID_0x201,
	CANBUS_ID_0x62,
	CANBUS_ID_0x200,
	CANBUS_ID_0x400,
	CANBUS_ID_0x40,
	CANBUS_ID_0x243,
	CANBUS_ID_0x99,
	CANBUS_ID_0xfe,,*/

	//以下故障码无此报文故上设置OK

	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE66D86_Event), DEM_EVENT_STATUS_PASSED);
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE66D87_Event), DEM_EVENT_STATUS_PASSED);
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71B86_Event), DEM_EVENT_STATUS_PASSED);
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71B87_Event), DEM_EVENT_STATUS_PASSED);
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE72F86_Event), DEM_EVENT_STATUS_PASSED);


	//todo Central Configuration System Programming Failures Missing calibration 0x234
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE30054_Event), DEM_EVENT_STATUS_PASSED);
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xed4a87_Event), DEM_EVENT_STATUS_PASSED);
//add by liuyang at 241031 to coomment DTC d18053 dc5088
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd18053_Event), DEM_EVENT_STATUS_PASSED);
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xDC5088_Event), DEM_EVENT_STATUS_PASSED); //mod by liuyang 241115
//	Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xdc4088_Event), DEM_EVENT_STATUS_PASSED); 
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE72F87_Event), DEM_EVENT_STATUS_PASSED);
	// Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd0c568_Event), DEM_EVENT_STATUS_PASSED);
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd63451_Event), DEM_EVENT_STATUS_PASSED);
//CAN lost
if(COMRxLostFlag[CANBUS_ID_0x400]==0xAA)
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd65987_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd65987_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxLostFlag[CANBUS_ID_0x234]==0xAA)
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71687_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71687_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxLostFlag[CANBUS_ID_0x52]==0xAA)
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71887_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71887_Event), DEM_EVENT_STATUS_PREPASSED);

}
if((COMRxLostFlag[CANBUS_ID_0x50]==0xAA)||(COMRxLostFlag[CANBUS_ID_0x99]==0xAA))
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE75087_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE75087_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxLostFlag[CANBUS_ID_0x51]==0xAA)
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC3687_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC3687_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxLostFlag[CANBUS_ID_0x200]==0xAA)
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC5387_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC5387_Event), DEM_EVENT_STATUS_PREPASSED);

}



//无效故障
/*暂时屏蔽无效故障码*/
/*for(i=0;i<CANBUS_Num;i++)
{
	COMRxVailFlag[i]=0;
	COMRxVailFlag1[i]=0;
	COMRxVailFlag2[i]=0;
	COMRxVailFlag3[i]=0;
	COMRxVailFlag4[i]=0;
	}*/
if((COMRxVailFlag[CANBUS_ID_0x400]==0x2)||(COMRxVailFlag[CANBUS_ID_0x200]==0x2))//400  200//E2E
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd65986_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xd65986_Event), DEM_EVENT_STATUS_PREPASSED);

}

if(COMRxVailFlag[CANBUS_ID_0x234]==0x2)//E2E  GearLvrIndcn
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71686_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71686_Event), DEM_EVENT_STATUS_PREPASSED);

}
/////////////////////////////////////
if(COMRxVailFlag[CANBUS_ID_0x52]==0x2)//E2E  VehMtnSt
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71886_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE71886_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxVailFlag[CANBUS_ID_0x40]==0x2)//E2E  WhlSpdCircumlFrnt
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE73286_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE73286_Event), DEM_EVENT_STATUS_PREPASSED);

}
if((COMRxVailFlag[CANBUS_ID_0x50]==0x2)||(COMRxVailFlag[CANBUS_ID_0x99]==0x2))
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE75086_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xE75086_Event), DEM_EVENT_STATUS_PREPASSED);

}

if(COMRxVailFlag[CANBUS_ID_0x51]==0x2)//e2e VehSpdLgt
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC3686_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC3686_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxVailFlag1[CANBUS_ID_0x40]==0x2)//AgDataRawSafe  e2e
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xec4e86_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xec4e86_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxVailFlag1[CANBUS_ID_0x200]==0x2)//TODO  AmbTRaw
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC5386_event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC5386_event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxVailFlag1[CANBUS_ID_0x51]==0x2)//TODO BrkPedlPsd/BrkPedlPsd
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC5686_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC5686_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxVailFlag1[CANBUS_ID_0x234]==0x2)//TODO  PtTqAtWhlFrntActGroup
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC9686_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xEC9686_Event), DEM_EVENT_STATUS_PREPASSED);

}

if(COMRxVailFlag2[CANBUS_ID_0x40]==0x2)//TODO  LatCtrlReqSafe
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xED3386_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xED3386_Event), DEM_EVENT_STATUS_PREPASSED);

}
if(COMRxVailFlag3[CANBUS_ID_0x40]==0x2)//TODO  ADataRawSafe
{

	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xED4A86_Event), DEM_EVENT_STATUS_PREFAILED);
}
else
{
	//Dem_SetEventStatus((DemConf_DemEventParameter_DTC_0xED4A86_Event), DEM_EVENT_STATUS_PREPASSED);

}
 Public_constantCheck();
 Safety_constantCheck();
}
uint8 CAN_Check_PR(uint16 index)
{
	  /*DemConf_DemEventParameter_DTC_0xd0c451_Event
		DemConf_DemEventParameter_DTC_0xdc4088_Event
		DemConf_DemEventParameter_DTC_0xDC5088_Event
		DemConf_DemEventParameter_DTC_0xd0c568_Event其他处处理*/
	if(1)//((index==(DemConf_DemEventParameter_DTC_0xd0c451_Event)) // 241112 liuyang
	// 	||(index==(DemConf_DemEventParameter_DTC_0xd0c568_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xd14b51_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xd14c51_Event)) //241112 liuyang
	// 	||(index==(DemConf_DemEventParameter_DTC_0xd18053_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xd63451_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xd65986_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xd65987_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xdc4088_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xDC5088_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE66D86_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE66D87_Event)) 
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE71686_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE71687_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE71886_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE71887_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE71B86_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE71B87_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE72F86_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE72F87_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE73286_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE75086_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xE75087_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xEC3686_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xEC3687_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xec4e86_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xEC5386_event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xEC5387_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xEC5686_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xEC9686_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xED3386_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xED4A86_Event))
	// 	||(index==(DemConf_DemEventParameter_DTC_0xed4a87_Event)))
	{
		return CAN_TYPE_OK;
	}
	else
	{
		return CAN_TYPE_NOK;
	}



}

void Public_constantCheck(void)
{
	 uint16 i = 0;
	 uint8 Data[256]={0};
	 static uint16 flagcounter0 = 0, flagcounterf = 0;
	static uint8 First_flag = 0;
	uint8 *PublicKeyADDR;
	if(First_flag==0)
		{
			First_flag = 0xAA;
			PublicKeyADDR = ((uint8 *)0xAF011000);

			for(i = 0;i < 256;i++)
			{
			Data[i] = *PublicKeyADDR;
			PublicKeyADDR++;
			}

			for(i = 0; i < 256; i ++)
			{
			if(Data[i]==0)
			{
			flagcounter0++;
			}
			}
			for(i = 0; i < 256; i ++)
			{
			if(Data[i]==0xFF)
			{
			flagcounterf++;
			}
			}
		}
		else
		{

			//no
		}
	if(flagcounter0==256)
			{
			//Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14b51_Event,DEM_EVENT_STATUS_PREFAILED);
			}
			else if(flagcounterf==256)
			{

				//Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14b51_Event,DEM_EVENT_STATUS_PREFAILED);
			}
			else
			{

				 //Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14b51_Event,DEM_EVENT_STATUS_PASSED);
			}
#if 0
	if(First_flag==0)
	{
		First_flag = 0xAA;
		PublicKeyADDR = ((uint8 *)0xAF011000);

		for(i = 0;i < 256;i++)
		{
		Data[i] = *PublicKeyADDR;
		PublicKeyADDR++;
		}

		for(i = 0; i < 256; i ++)
		{
		if(Data[i]==0)
		{
		flagcounter0++;
		}
		}
		for(i = 0; i < 256; i ++)
		{
		if(Data[i]==0xFF)
		{
		flagcounterf++;
		}
		}
	}
	else
	{

		//no
	}
	if((rtARID_DEF_NTM_NmCAN.cm_flag == true)
	&&((rtARID_DEF_NTM_NmCAN.um1_flag == true)||(rtARID_DEF_NTM_NmCAN.um2_flag == true))
	&&(rtARID_DEF_NTM_NmCAN.pl_flag == true))
	{
		if(flagcounter0==256)
		{
		flagcounter0=0;
		Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14b51_Event,DEM_EVENT_STATUS_PREFAILED);
		}
		else if(flagcounterf==256)
		{

			Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14b51_Event,DEM_EVENT_STATUS_PREFAILED);
		}
		else
		{

			 Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14b51_Event,DEM_EVENT_STATUS_PASSED);
		}
	}else
	{

		Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14b51_Event,DEM_EVENT_STATUS_PASSED);
	}
#endif
	 //0xAF011000

}
void Safety_constantCheck(void)
{
	 //0xAF010000
	 uint8 i = 0,Data[10]={0};
	 static uint8 flagcounter0=0, flagcounterf=0;
	static uint8 First_flag_00 = 0;
	uint8 *SafetyKeyADDR;

	if(First_flag_00==0)
	{
		First_flag_00 = 0xaa;
		SafetyKeyADDR = ((uint8 *)0xAF010000);
		for(i = 0;i < 10;i++)
		{
		Data[i] = *SafetyKeyADDR;
		SafetyKeyADDR++;
		}

		for(i = 0; i < 10; i ++)
		{
		if(Data[i]==0)
		{
		flagcounter0++;
		}
		}
		for(i = 0; i <10; i ++)
		{
		if(Data[i]==0xFF)
		{
		flagcounterf++;
		}
		}
	}
	else
	{

	}
	if(flagcounter0==10)
	{
	//Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14c51_Event,DEM_EVENT_STATUS_PREFAILED);
	}
	else if(flagcounterf==10)
	{

		//Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14c51_Event,DEM_EVENT_STATUS_PREFAILED);
	}
	else
	{

		 //Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14c51_Event,DEM_EVENT_STATUS_PASSED);
	}
#if 0
	if(First_flag_00==0)
	{
		First_flag_00 = 0xaa;
		SafetyKeyADDR = ((uint8 *)0xAF010000);
		for(i = 0;i < 10;i++)
		{
		Data[i] = *SafetyKeyADDR;
		SafetyKeyADDR++;
		}

		for(i = 0; i < 10; i ++)
		{
		if(Data[i]==0)
		{
		flagcounter0++;
		}
		}
		for(i = 0; i <10; i ++)
		{
		if(Data[i]==0xFF)
		{
		flagcounterf++;
		}
		}
	}
	else
	{

	}
/*��ѹ��- UsageMode = Driving or Active for 5s
  AND
- Car Mode = Normal for 5s
  AND
- ElPowerLevel !=1*/
	if((rtARID_DEF_NTM_NmCAN.cm_flag == true)
	&&((rtARID_DEF_NTM_NmCAN.um1_flag == true)||(rtARID_DEF_NTM_NmCAN.um2_flag == true))
	&&(rtARID_DEF_NTM_NmCAN.pl_flag == true))
	{
		if(flagcounter0==10)
		{
		  flagcounter0=0;

		Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14c51_Event,DEM_EVENT_STATUS_PREFAILED);
		}
		else if(flagcounterf==10)
		{

			Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14c51_Event,DEM_EVENT_STATUS_PREFAILED);
		}
		else
		{

			 Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14c51_Event,DEM_EVENT_STATUS_PASSED);
		}
	}
	else
	{
		Dem_SetEventStatus(DemConf_DemEventParameter_DTC_0xd14c51_Event,DEM_EVENT_STATUS_PASSED);
	}

#endif
}

/*
 * System initialize for atomic system:
 *    '<S1>/CarModeReqTMR'
 *    '<S1>/UsageModeReqTMR'
 */
void CarModeReqTMR_Init(UInt8 *rty_Mode)
{
  *rty_Mode = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S1>/CarModeReqTMR'
 *    '<S1>/UsageModeReqTMR'
 */
void CarModeReqTMR(UInt8 rtu_ModeSwitchReq, UInt8 *rty_Mode, DW_CarModeReqTMR
                   *localDW)
{
  /* Chart: '<S1>/CarModeReqTMR' */
  /* Gateway: ModeSwitchLogic/CarModeReqTMR */
  /* During: ModeSwitchLogic/CarModeReqTMR */
  /* Entry Internal: ModeSwitchLogic/CarModeReqTMR */
  /* Transition: '<S2>:20' */
  if (rtu_ModeSwitchReq == localDW->ModeSwitchReq_last) {
    /* Transition: '<S2>:5' */
    if (localDW->timecnt < Cal_EXT_ModeSwitchTMR) {
      /* Transition: '<S2>:10' */
      /* Transition: '<S2>:13' */
      localDW->timecnt = (UInt16)((Int32)(((Int32)localDW->timecnt) + 1));

      /* Transition: '<S2>:16' */
    } else {
      /* Transition: '<S2>:15' */
      *rty_Mode = rtu_ModeSwitchReq;
    }

    /* Transition: '<S2>:19' */
  } else {
    /* Transition: '<S2>:18' */
    localDW->timecnt = 0U;
  }

  /* Transition: '<S2>:22' */
  localDW->ModeSwitchReq_last = rtu_ModeSwitchReq;

  /* End of Chart: '<S1>/CarModeReqTMR' */
}

/* System initialize for atomic system: '<Root>/ModeSwitchLogic' */
void ModeSwitchLogic_Init(void)
{
  /* SystemInitialize for Chart: '<S1>/UsageModeReqTMR' */
  CarModeReqTMR_Init(&rtDW_l5cf_1.Mode);

  /* SystemInitialize for Chart: '<S1>/CarModeReqTMR' */
  CarModeReqTMR_Init(&rtDW_l5cf_1.Mode_eipi);
}

/* Output and update for atomic system: '<Root>/ModeSwitchLogic' */
void ModeSwitchLogic(void)
{
  /* Chart: '<S1>/UsageModeReqTMR' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  CarModeReqTMR(Fv_EXT_UsageModeReq, &rtDW_l5cf_1.Mode,
                &rtDW_l5cf_1.sf_UsageModeReqTMR);

  /* Chart: '<S1>/CarModeReqTMR' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   */
  CarModeReqTMR(Fv_EXT_CarModeReq, &rtDW_l5cf_1.Mode_eipi,
                &rtDW_l5cf_1.sf_CarModeReqTMR);
}

/* Model step function */
void ModeChangeDelay_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/ModeSwitchLogic' */
  ModeSwitchLogic();

  /* End of Outputs for SubSystem: '<Root>/ModeSwitchLogic' */

  /* DataStoreWrite: '<Root>/Data Store Write' */
  Fv_EXT_UsageMode = rtDW_l5cf_1.Mode;

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  Fv_EXT_CarMode = rtDW_l5cf_1.Mode_eipi;
}

/* Model initialize function */
void ModeChangeDelay_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/ModeSwitchLogic' */
  ModeSwitchLogic_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/ModeSwitchLogic' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
#define ASW_DEM_STOP_SEC_CODE                       
#include "ASW_DEM_MemMap.h"
