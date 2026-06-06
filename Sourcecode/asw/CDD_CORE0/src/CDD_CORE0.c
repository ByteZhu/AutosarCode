/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Project :    ETAS Entry Platform
 * Component:  CDD_CORE0
 * Description: Testcode for CDD_CORE0
 * Version         Author        Date               Update information
 * 1.0             AGT1HC        19-Nov-2021        Create software
 * 1.1             HAD1HC        15-Mar-2021        Update function of calculating
 * 													stack utilization and CPU Load
 * 1.2             HAD1HC        13-Apr-2021        Update Memmap
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************/

#include "Rte_CDD_CORE0.h"
#include "CDD_CORE0.h"
#include "Os.h"
#include "csm.h"
#include "Csm_Prv.h"
#include "Dcm.h"
#include "Gtm.h"
#include "EVAdc.h"
#include "CanIf_Types.h"      
#include "Can_17_McmCan.h"
#include "Crypto.h"

#define CDD_CORE0_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_CORE0_MemMap.h"
static enum StateCaculation_type StateCaculationCore0 = PREPARE;
#define CDD_CORE0_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_CORE0_MemMap.h"

#define CDD_CORE0_START_SEC_VAR_INIT_8
#include "CDD_CORE0_MemMap.h"
static uint8 Status_global = 0;
static uint8 DiagResponse_data[64] = {0};
#define CDD_CORE0_STOP_SEC_VAR_INIT_8
#include "CDD_CORE0_MemMap.h"

#define CDD_CORE0_START_SEC_VAR_INIT_16
#include "CDD_CORE0_MemMap.h"
static uint16 DataReceiverCore0_ClientServer = 0;
#define CDD_CORE0_STOP_SEC_VAR_INIT_16
#include "CDD_CORE0_MemMap.h"

#define CDD_CORE0_START_SEC_VAR_INIT_32
#include "CDD_CORE0_MemMap.h"
static uint32 Duration_global = 0;  
#define CDD_CORE0_STOP_SEC_VAR_INIT_32
#include "CDD_CORE0_MemMap.h"

#define CDD_CORE0_START_SEC_VAR_INIT_64
#include "CDD_CORE0_MemMap.h"
static float64 CPU_PercentUtilization_global = 0.0;
static float64 MaxUserStackUtilization_f64 = 0.0;
#define CDD_CORE0_STOP_SEC_VAR_INIT_64
#include "CDD_CORE0_MemMap.h"
#define OS_CORE_ID_0 (0U)
static uint8 testvar = 0;

static uint8  HDR[100] = {0x01, 0x02, 0x03};
static uint8 PlainText[512] = {0xC0, 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x01, 0x00, 0x00, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x00};
static uint8 Cliper[512] = {0};
static uint8 Tag[50] = {0};
static uint32 PlainTextLen = 50;
static uint32 ChiperLen = 50;
static uint32 Taglen = 50;
static uint8 verify = 0;

static uint8 MacKey_keyS[16] = {0X01, 0X02, 0X03, 0X01, 0X02, 0X03, 0X01, 0X02, 0X03, 0X01, 0X02, 0X03, 0X01, 0X02, 0X03, 0X04};
static uint8 MacKey_key[16] = {0};
static uint32 MacKey_keylen = 128;
static uint8 MacKey_IV[12] = {0};
static uint32 MacKey_IVlen = 12;
static uint8 ENCKey_key[16] = {0};
static uint32 ENCKey_keylen = 16;
static uint8 ENCKey_IV[12] = {0};
static uint32 ENCKey_IVlen = 12 * 8;
static unsigned char Deal_2E_D0E9_Data[48] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x94,0x99,0xa4,0x9d,0x0b,0x03,0xdb,0x55,0xe4,0x90,0x85,0xc5,0xea,0xf5,0x64,0x5c,0x9e,0x4b,0x6b,0x92,0xc6,0x05,0x8c,0x55,0xab,0x36,0x21,0x8a,0x38,0xac,0x09,0x91};
unsigned char Deal_2E_C05D_Data[53] = {0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x83,0xC3,0x0C,0x6F,0x26,0xC3,0x94,0x8F,0xC5,0x2E,0x66,0x41,0xCD,0xDD,0x5D,0xA9,0x26,0xb5,0xca,0xf4,0x2a,0x96,0x11,0xb8,0x53,0xde,0x63,0xf7,0x1a,0x42,0x64,0x87};
#define CDD_CORE0_START_SEC_CODE
#include "CDD_CORE0_MemMap.h"
void CddIf_Transmit(Can_PduType* PduInfo)
{
	Can_17_McmCan_Write(0, PduInfo);/*0:Can_Network_CANNODE_0_Rx_Std_MailBox_1 -- Hth*/
}
/**********************************************************************************
  Function name		:	CDD_CORE0_func
  Description		:	Main function to process the calculation of Cpu load and stack
						utilization 
  Parameter	(in)	:	None
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks: 
***********************************************************************************/
FUNC (void, CDD_CORE0_CODE) CDD_CORE0_func_1ms/* return value & FctID */
(
		void
)
{	
	Can_PduType lPduInfo_st          = {NULL_PTR, 0, 0, 0};

	if(TRUE == Rte_IsUpdated_CDD_CORE0_R_CoreCrossMsg_Data_Data)
	{
		Rte_Read_CDD_CORE0_R_CoreCrossMsg_Data_Data(&DiagResponse_data);
		lPduInfo_st.id = 0x6dd;
		lPduInfo_st.swPduHandle = 0;
		lPduInfo_st.sdu         = &DiagResponse_data;
		lPduInfo_st.length      = 64;
		
		//CddIf_Transmit(&lPduInfo_st);
	}
	
	
}
FUNC (void, CDD_CORE0_CODE) Cdd_Safe_NVM_func
( 
		void
)
{
	//Cdd_SafeNVM_MainFunction();
}
/**********************************************************************************
  Function name		:	CDD_CORE0_func
  Description		:	Main function to process the calculation of Cpu load and stack
						utilization 
  Parameter	(in)	:	None
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks: 
***********************************************************************************/
FUNC (void, CDD_CORE0_CODE) CDD_CORE0_func/* return value & FctID */
(
		void
)
{	
  // if(testvar == 1)
  // {
  //   Csm_MacGenerate(CsmConf_CsmJob_CsmJob_Gen_SecOC, CRYPTO_OPERATIONMODE_SINGLECALL, PlainText, 16, Tag, &Taglen );
  //   testvar = 0;
  // }
  // else if(testvar == 2)
  // {
  //   Csm_MacVerify(CsmConf_CsmJob_CsmJob_Ver_SecOC, CRYPTO_OPERATIONMODE_SINGLECALL, PlainText, 16, Tag, 128, &verify );
  //   testvar = 0;
  // }
  // else if(testvar == 3)
  // {
  //   Csm_AEADEncrypt(CsmConf_CsmJob_CsmJob_GCM_ENC, CRYPTO_OPERATIONMODE_SINGLECALL, PlainText, 16, HDR, 3, Cliper, &ChiperLen, Tag, &Taglen);
  //   testvar = 0;
  // }
  // else if(testvar == 4)
  // {
  //   Csm_AEADDecrypt(CsmConf_CsmJob_CsmJob_GCM_DEC, CRYPTO_OPERATIONMODE_SINGLECALL, Cliper, 16, HDR, 3, Tag, 128, PlainText, &PlainTextLen, &verify);
  //   testvar = 0;
  // }
  // else if(testvar == 5)
  // {
  //   Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_DevKey, 1, MacKey_keyS, MacKey_keylen);
  //   Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_DevKey, 5, ENCKey_IV, ENCKey_IVlen);
  //   testvar = 0;
  // }
  // else if(testvar == 6)
  // {
  //   Csm_KeyElementGet(CsmConf_CsmKey_CsmKey_DevKey, 1, MacKey_key, &MacKey_keylen);
  //   Csm_KeyElementGet(CsmConf_CsmKey_CsmKey_DevKey, 5, ENCKey_IV, &ENCKey_IVlen);
  //   testvar = 0;
  // }
  //  else if(testvar == 7)
  // {
  //   Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_SecOC_CMAC_Ele, 1, MacKey_keyS, MacKey_keylen);
  //   testvar = 0;
  // }
  // else if(testvar == 8)
  // {
  //   Csm_KeyElementGet(CsmConf_CsmKey_CsmKey_SecOC_CMAC_Ele, 1, MacKey_key, &MacKey_keylen);
  //   testvar = 0;
  // }
  // else if(testvar == 9)
  // {
  //   static uint8 ErrorCode = E_OK;
  //   static Std_ReturnType retVar = E_OK;
  //   retVar = DeviceKey_Deal_2E_D0E9(Deal_2E_D0E9_Data, &ErrorCode);
  //   if(retVar != DCM_E_PENDING)
  //   {
  //     testvar = 0;
  //   }
  // }
  // else if(testvar == 10)
  // {
  //   static uint8 ErrorCode = E_OK;
  //   static Std_ReturnType retVar = E_OK;
  //   retVar = SecOCKey_Deal_2E_C05D(Deal_2E_C05D_Data, &ErrorCode);
  //   if(retVar != DCM_E_PENDING)
  //   {
  //     testvar = 0;
  //   }
  // }
  // else if(testvar == 11)
  // {
  //   static uint8 ErrorCode = E_OK;
  //   static Std_ReturnType retVar = E_OK;
  //   uint8  dataIn1 = 1;
  //   uint8 OpStatus = 0;
  //   uint8 dataOut1[16] = {0};
  //   retVar = SysKeyTest_Deal_31_B050(dataIn1, OpStatus, dataOut1, &ErrorCode);
  //   testvar = 0;
  // }
  // SecOC_DefaultKey_CheckRoutine();
	
}
void CddIf_RxIndication(Can_HwType *Mailbox, PduInfoType *PduInfoPtr)
{
	uint8 *data;
	data = PduInfoPtr->SduDataPtr;
	Rte_Write_CDD_CORE0_P_CoreCrossMsg_Data_Data(data);
}
FUNC (void, CDD_CORE0_CODE) CDD_CORE0_Init
(
	void
)
{	
	//Add your cdd's init function
	Gtm_Init();
	EVAdc_Init();
}
#define CDD_CORE0_STOP_SEC_CODE
#include "CDD_CORE0_MemMap.h"
#define CDD_CORE0_START_SEC_CODE
#include "CDD_CORE0_MemMap.h"
/**********************************************************************************
  Function name		:	RE_OsShell_TriggerBg_func
  Description		:	This function is used to activate the background task. 
  Parameter	(in)	:	None
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks: 
***********************************************************************************/
FUNC (void, CDD_CORE0_CODE) RE_OsShell_TriggerBg_func/* return value & FctID */
(
		void
)
{
	TaskStateType stTaskState = SUSPENDED;

	/* Get Task State of background task.*/
	(void)GetTaskState(Core0_OsTask_Background_1ms, &stTaskState);

	if(stTaskState == SUSPENDED)
	{
		/* If back ground task terminate, just activate the background task. */
		(void)ActivateTask(Core0_OsTask_Background_1ms);
	}
}
#define CDD_CORE0_STOP_SEC_CODE
#include "CDD_CORE0_MemMap.h"
