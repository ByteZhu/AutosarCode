/***          
		Dcm Callout Function    
****/
#include "Dem_UserSnapCallback.h"
//#include "Common.h"


Std_ReturnType DemdataElementReadFnc_D0D2(uint8* Buffer)
{

	/* for(uint8 i = 0;i<4;i++)
	{
		*(Buffer + i) = DID_GlobalRealTime[i];
	}*/

    return E_OK;
}

Std_ReturnType DemdataElementReadFnc_DD01(uint8* Buffer)
{
	/* 
	for(uint8 i=0;i<3;i++)
	{
		*(Buffer+i) = DID_TotalDistance[i];
	} 
	*/
    return E_OK;
}
Std_ReturnType DemdataElementReadFnc_DD02(uint8* Buffer)
{
	//*Buffer = DID_ECUVoltageSupply[0];
	
    return E_OK;
}
Std_ReturnType DemdataElementReadFnc_DD07(uint8* Buffer)
{
	//*Buffer = DID_UsageMode[0];
    return E_OK;
}
Std_ReturnType DemdataElementReadFnc_DD0C(uint8* Buffer)
{
	//*Buffer = DID_ElectricPowerLevel[0];
    return E_OK;
}
Std_ReturnType DemdataElementReadFnc_E554(uint8* Buffer)
{
	//*Buffer = DID_SteeringShaftTorqueSensor[0];
    return E_OK;
}



/**********************Extended Frame******************************/

Std_ReturnType Extended_Data_ReadFnc_Consecutive(uint8* Buffer)
{
	
    return E_OK;
}
Std_ReturnType Extended_Data_ReadFnc_stamp22(uint8* Buffer)
{
    return E_OK;
}
Std_ReturnType Extended_Data_ReadFnc_stamp23(uint8* Buffer)
{
    return E_OK;
}
Std_ReturnType Snapshot_DataFuc_Read217D(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_Read217E(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_Read21AD(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_Read330C(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadD11C(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadD905(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadD906(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadD909(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadD90A(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadDD00(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadDD01(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadDD06(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadDD07(uint8* Buffer)
{
	return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadDD0A(uint8* Buffer)
{
    return E_OK;
}
Std_ReturnType Snapshot_DataFuc_ReadDD0C(uint8* Buffer)
{
	return E_OK;
}
