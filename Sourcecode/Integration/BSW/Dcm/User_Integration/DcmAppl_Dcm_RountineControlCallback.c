#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "CDD_FVM.h"
#include "Crypto.h"

#include "Rte_Dcm.h"
#include "common.h"
//#include "GlobalVar_EXT.h"
//#include "ASW_NVM.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/*** Extern declaration for DcmDspRoutine_0206_Start ***/
Std_ReturnType DcmDspRoutine_0206_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode)
{
	
	/*  add your handler function*/

	return RTE_E_OK;
}


/*** Extern declaration for DcmDspRoutine_307B_Start ***/
Std_ReturnType DcmDspRoutine_307B_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode)
{
	
	/*  add your handler function*/
	if(Fv_AngleReadyFlag == HELLA_STS_Decode)
	{
		StrAngZeroStored();
		Fv_AngleCorrectOpr = 0;
		Fv_AngleCorrectOprLast = 0;
		NvM_StoreRequest.bit.CommonCRCStored = 1;
		*dataOut1 = 0x20;
	}
	else
	{
		*dataOut1 = 0x21;
	}
	return RTE_E_OK;
}
/*** Extern declaration for DcmDspRoutine_3080_Start ***/
Std_ReturnType DcmDspRoutine_3080_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode)
{
	
	/*  add your handler function*/
	StrAngZeroRemoved();
	/*??¦Ë??????????*/
	Fv_AngleCorrectOpr = 0;
	Fv_AngleCorrectOprLast = 0;
	NvM_StoreRequest.bit.CommonCRCStored = 1;
	*dataOut1 = 0x20;
	return RTE_E_OK;
}
/*** Extern declaration for DcmDspRoutine_3082_Start ***/
 Std_ReturnType DcmDspRoutine_3082_Start(
						  const uint8 *  dataIn1,
                          Dcm_OpStatusType OpStatus,
                          uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode)
 {

 	/*  add your handler function*/

 	return RTE_E_OK;
 }
 /*** Extern declaration for DcmDspRoutine_3083_Start ***/
Std_ReturnType DcmDspRoutine_3083_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
						  Dcm_NegativeResponseCodeType * ErrorCode)
{
	
	/*  add your handler function*/

	return RTE_E_OK;
}
/*** Extern declaration for DcmDspRoutine_3088_Start ***/
Std_ReturnType DcmDspRoutine_3088_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
						 Dcm_NegativeResponseCodeType * ErrorCode)
{
						 
	 /*  add your handler function*/

	 return RTE_E_OK;
 }
/*** Extern declaration for DcmDspRoutine_3089_Start ***/
Std_ReturnType DcmDspRoutine_3089_Start(
						 Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
						 Dcm_NegativeResponseCodeType * ErrorCode)
{
	
	/*  add your handler function*/

	return RTE_E_OK;
}
/*** Extern declaration for DcmDspRoutine_308A_Start ***/
Std_ReturnType DcmDspRoutine_308A_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode)
{
	
	/*  add your handler function*/

	return RTE_E_OK;
}
/*** Extern declaration for DcmDspRoutine_308B_Start ***/
Std_ReturnType DcmDspRoutine_308B_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode)

{
	/*  add your handler function*/

	return RTE_E_OK;
}
/*** Extern declaration for DcmDspRoutine_30A8_Start ***/
 Std_ReturnType DcmDspRoutine_30A8_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode)
 {
 	/*  add your handler function*/

 	return RTE_E_OK;
 }
/***Routine control Appl functions for Range Routine***/



#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
