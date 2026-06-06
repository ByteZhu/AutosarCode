/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Project :    ETAS Entry Platform
 * Component:  ASW_NVM
 * Description: Testcode for ASW_NVM
 * Version         Author        Date               Update information
 * 1.0             AGT1HC        14-Jun-2019        Create software
 * 1.1             AGT1HC        19-Nov-2021        Update the Banner
 * 1.2             HAD1HC        13-Apr-2021        Update Memmap
 * 1.3             HAD1HC        15-June-2021       Update test code of block 
 * 													corruption
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************/




/*
	使用Write_AngCorrectStored
	使用Write_AngValidEnd
	使用Write_CCPVal
	暂时用来存储CCP和助力手感
	使用Write_CCPVal：
		0	Fv_CANCCP1
		1	Fv_CANCCP3
		2	Fv_CANCCP13
		3	Fv_CANCCP16
		4	Fv_CANCCP17
		5	Fv_CANCCP50
		6	Fv_CANCCP57
	使用Write_AngValidEnd：
		0	Fv_CANCCP58
		1	Fv_CANCCP62
		2	Fv_CANCCP142
		3	Fv_CANCCP150
		4	Fv_CANCCP316
		5	Fv_CANCCP494
		6	Fv_CANCCP565
	使用Write_AngCorrectStored：
		0	Fv_CANCCP639
		1	Fv_CANCCP640
		2	Fv_ActivePersonalMode
		3	Fv_CANCCP317
		4	Fv_CANCCPbulk_state
		5	Fv_SWP2_TS
		6
	NvM_StoreRequest.bit.AngValidEnd
	NvM_StoreRequest.bit.AngCorrectStoredReq
	NvM_StoreRequest.bit.CCPVal

	使用Write_CommonCRCStored：
		0  Fv_TOCLongStyTrq(H8)
		1  Fv_TOCLongStyTrq(L8)
		2  Fv_AngleCorrectOpr(H8)
		3  Fv_AngleCorrectOpr(L8)
		4  Fv_FriCompAdptiveTorque(H8)
		5  Fv_FriCompAdptiveTorque(L8)
		6
	NvM_StoreRequest.bit.CommonCRCStored
*/








#include "Rte_ASW_NVM.h"
#include "NvM.h"
#include "ASW_NVM.h"
#include "NVM_types.h"
#include "Fee.h"
#include "Fls.h"
#include "TimingCalculation.h"
#include "rba_FeeFs1x_Prv.h"
#include "rba_FeeFs1x_Prv_Cfg.h"
#include "rba_FeeFs1x_Prv_SectorReorgTypes.h"
#include "GlobalVar.h"
#include "common.h"
#include "Motor_Private.h"
#include "EepromData.h"
#include "IfxStm_reg.h"
#include "Crypto.h"
//#include "WS_FEE_SetDTCState.h"
//#include "Rte_DTCLogic_Type.h"
//#include "Rte_Eps_IptSwc_Type.h"
//#include "GlobalVar_EXT.h"
extern rba_FeeFs1x_Reorg_stm_tst rba_FeeFs1x_Reorg_stm_st;

#define ASW_NVM_START_SEC_VAR_INIT_8
#include "ASW_NVM_MemMap.h"
uint8 TEST_DATA_NVM_NATIVE_1024_1[SIZE_BLOCK1]={0};
uint8 TEST_DATA_NVM_NATIVE_1024_2[SIZE_BLOCK2]={0};
uint8 NVM_Read_Buffer[64]={0};
uint8 CorruptData = 0xCA;
static NvM_RequestResultType NvM_ErrorStatus[2] = {0,0};
static uint8 NvM_WriteFlag = 1;
uint8 CounterWriteBlock=0;
uint8 NVM_StoreStatus = 0;

const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_1[SIZE_BLOCK1] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_2[SIZE_BLOCK2] ={0};

const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngCorrectStored[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngEndCalData[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngValidEnd[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CCPVal[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CommonCRCStored[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_PenProf[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_StrAngZero[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_RotorOffset[34] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_InitAngle[18] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CurrentOffset[44] ={0};

const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BN_F190[17] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BN_D09A[2] ={0};

const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleName[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_FunConfig[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleConfig[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_SoftwareConfig[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_ResetFlag[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_Mileage[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_TestMode[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_TOCStudyTrq[8] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VIN[17] ={0};
const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_BackupConfig[64] ={0};



#define NVM_CDD_ADDR_BASE (/*FLS_17_DMU_BASE_ADDRESS + */RBA_FEEFS1X_PRV_CFG_PHYS_SEC_END1 + 1)

#define NVM_CDD_BLOCK0_OFFSET	0
#define NVM_CDD_BLOCK0_Len		40
#define NVM_CDD_BLOCK0_ID		0

#define NVM_CDD_BLOCK1_OFFSET	40
#define NVM_CDD_BLOCK1_Len		16
#define NVM_CDD_BLOCK1_ID		1

#define NVM_CDD_BLOCK2_OFFSET	56
#define NVM_CDD_BLOCK2_Len		16
#define NVM_CDD_BLOCK2_ID		2


uint8 NVM_CDD_RotorOffset_Stored[32]={0};
uint8 NVM_CDD_InitAngle_Stored[8]={0};
uint8 NVM_CDD_CurrentOffset_Stored[12]={0};

uint8 NVM_CDD_RotorOffset_Read[32]={0};
uint8 NVM_CDD_InitAngle_Read[8]={0};
uint8 NVM_CDD_CurrentOffset_Read[12]={0};


#define ASW_NVM_STOP_SEC_VAR_INIT_8
#include "ASW_NVM_MemMap.h"

#define ASW_NVM_START_SEC_VAR_INIT_32
#include "ASW_NVM_MemMap.h"
static uint32 modify_addr1 = 0x200;
static uint32 modify_addr2 = 0x300;
static uint32 NvM_Count_PENDING = 0;
#if (OS_COUNTER_IS_USED == TRUE)
static uint32 NvM_ElapsedTime = 0;
#else
static float32 NvM_ElapsedTime = 0;
#endif

#define ASW_NVM_STOP_SEC_VAR_INIT_32
#include "ASW_NVM_MemMap.h"

#define ASW_NVM_START_SEC_VAR_INIT_UNSPECIFIED
#include "ASW_NVM_MemMap.h"
NvM_Rb_StatusType status_NvM_test=0;
NvM_Test_t NvM_Test = SWC_ZERO;
NvM_Test_t NvM_State = SWC_ZERO;
NvM_Status_t NvM_Status = NVM_STATE_IDLE;
NvM_StoreReQuest_t NvM_StoreRequest = {0};
NvM_ReadReQuest_t NvM_ReadRequest = {0};
#define ASW_NVM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ASW_NVM_MemMap.h"

#define ASW_NVM_START_SEC_VAR_INIT_16
#include "ASW_NVM_MemMap.h"
static uint8 InvalidData[1400]      = {0};
static uint8 MngData[MngData_Size]  = {0};
#define ASW_NVM_STOP_SEC_VAR_INIT_16
#include "ASW_NVM_MemMap.h"

#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h"
uint8 writeValue = 0x7E;
MemIf_JobResultType tempState = 0;
uint8 NvM_SwcICopyDataToRam(uint8 * dest_addr, uint8 * src_addr, uint32 size);

FUNC (void, ASW_NVM_CODE) RE_ASW_NVM_func/* return value & FctID */
(
		void
)
{
	boolean retVal 		= E_NOT_OK;

	sint16 tempS16 = 0;
	uint8 crc = 0;
	uint16 i = 0;
	static cntnvm=0;
	if(cntnvm==10)
	{
	Rte_CPim_ASW_NVM_ASW_NVM_IDS_1024[0]=0xaa;
	Rte_CPim_ASW_NVM_ASW_NVM_IDS_1024[1]=0xbb;
    //Ids_WriteNVMData(Rte_CPim_ASW_NVM_ASW_NVM_IDS_1024);
    cntnvm++;
	}
	else if(cntnvm==11)
	{
		cntnvm++;
		//Cdd_SafeNVM_MainFunction();
	}
	else if(cntnvm>12)
	{
	}
	else
	{
		cntnvm++;
	}






	if((NvM_StoreRequest.data > 0) && (NvM_Status == NVM_STATE_IDLE))
	{
		if(NvM_StoreRequest.bit.AngCorrectStoredReq)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_AngCorrectStored;
			}
		}
		else if(NvM_StoreRequest.bit.AngEndCalDataReq)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_AngEndCalData;
			}
		}
		else if(NvM_StoreRequest.bit.AngValidEnd)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_AngValidEnd;
			}
		}
		else if(NvM_StoreRequest.bit.CCPVal)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_CCPVal;
			}
		}
		else if(NvM_StoreRequest.bit.CommonCRCStored)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_CommonCRCStored;
			}
		}
		else if(NvM_StoreRequest.bit.PenProf)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_PenProf;
			}
		}
		else if(NvM_StoreRequest.bit.StrAngZero)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_StrAngZero;
			}
		}
		else if(NvM_StoreRequest.bit.InitAngle)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_InitAngle;
			}
		}
		else if(NvM_StoreRequest.bit.CurrentOffset)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_CurrentOffset;
			}
		}
		else if(NvM_StoreRequest.bit.RotorOffset)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_RotorOffset;
			}
		}
		else if(NvM_StoreRequest.bit.DemExtra)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_DemExtra;
			}
		}
		else if(NvM_StoreRequest.bit.Did_D09A)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_DIDD09A;
			}
		}
		else if(NvM_StoreRequest.bit.Did_F190)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Write_DIDF190;
			}
		}
		else
		{

		}
	}
	
	if((NvM_ReadRequest.data > 0) && (NvM_Status == NVM_STATE_IDLE))
	{
		if(NvM_ReadRequest.bit.AngCorrectStoredReq)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_AngCorrectStored;
			}
		}
		else if(NvM_ReadRequest.bit.AngEndCalDataReq)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_AngEndCalData;
			}
		}
		else if(NvM_ReadRequest.bit.AngValidEnd)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_AngValidEnd;
			}
		}
		else if(NvM_ReadRequest.bit.CCPVal)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_CCPVal;
			}
		}
		else if(NvM_ReadRequest.bit.CommonCRCStored)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_CommonCRCStored;
			}
		}
		else if(NvM_ReadRequest.bit.PenProf)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_PenProf;
			}
		}
		else if(NvM_ReadRequest.bit.StrAngZero)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_StrAngZero;
			}
		}
		else if(NvM_ReadRequest.bit.InitAngle)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_InitAngle;
			}
		}
		else if(NvM_ReadRequest.bit.CurrentOffset)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_CurrentOffset;
			}
		}
		else if(NvM_ReadRequest.bit.RotorOffset)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_RotorOffset;
			}
		}
		else if(NvM_ReadRequest.bit.DemExtra)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_DemExtra;
			}
		}
		else if(NvM_ReadRequest.bit.Did_D09A)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_DIDD09A;
			}
		}
		else if(NvM_ReadRequest.bit.Did_F190)
		{
			if(NvM_State == SWC_ZERO)
			{
				NvM_State = Read_DIDF190;
			}
		}
		else
		{

		}
	}

	switch (NvM_State)
	{
		case Write_AngCorrectStored:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[0] = Fv_CANCCP639;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[1] = Fv_CANCCP640;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[2] = Fv_STOREAssistSelectMode;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[3] = Fv_CANCCP317;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[4] = Fv_CANCCPbulk_state;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[5] = Fv_SWP2_TS;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[6] = 0xAA;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[7] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored),7);
			Rte_Call_RPort_ASW_NVM_BR_AngCorrectStored_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored);
			NvM_StoreRequest.bit.AngCorrectStoredReq = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_AngCorrectStored:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);			
			Rte_Call_RPort_ASW_NVM_BR_AngCorrectStored_ReadBlock(NVM_Read_Buffer);
			
			NvM_ReadRequest.bit.AngCorrectStoredReq = 0;
			NvM_State = SWC_ZERO;
			break;
		case Write_AngValidEnd:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[0] = Fv_CANCCP58;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[1] = Fv_CANCCP62;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[2] = Fv_CANCCP142;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[3] = Fv_CANCCP150;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[4] = Fv_CANCCP316;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[5] = Fv_CANCCP494;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[6] = Fv_CANCCP565;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[7] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd),7);
			Rte_Call_RPort_ASW_NVM_BR_AngValidEnd_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd);
			NvM_StoreRequest.bit.AngValidEnd = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_AngValidEnd:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);
			Rte_Call_RPort_ASW_NVM_BR_AngValidEnd_ReadBlock(NVM_Read_Buffer);

			NvM_ReadRequest.bit.AngValidEnd = 0;
			NvM_State = SWC_ZERO;
			break;
		case Write_AngEndCalData:
			if(NvM_Status != NVM_STATE_PROCESS)
			{
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[0] = (UInt8)(((UInt16)fsCalibrationData.data.anglezero.al) >> 8);
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[1] = (UInt8)(((UInt16)fsCalibrationData.data.anglezero.al) >> 0);
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[2] = (UInt8)(((UInt16)fsCalibrationData.data.anglezero.ar) >> 8);
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[3] = (UInt8)(((UInt16)fsCalibrationData.data.anglezero.ar) >> 0);
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[4] = 0;
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[5] = (uint8)(Tv_SE_EndStoredFlag == TRUE);//stored flag
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[6] = 0xAA;
				Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[7] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData),7);
				Rte_Call_RPort_ASW_NVM_BR_AngEndCalData_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData);
			}
			NvM_Status = NVM_STATE_PROCESS;
			Rte_Call_RPort_ASW_NVM_BR_AngEndCalData_GetErrorStatus(&NVM_StoreStatus);
			if(NVM_StoreStatus == NVM_REQ_OK)
			{				
				if(Tv_SE_EndStoredFlag == TRUE)
				{
					Tv_SE_EndStoredFlag = FALSE;
					Fv_AngleEndValidFlag = ANGLE_STS_Valid;
					Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] = FailureDiag_RegOK;
					//WS_FEE_SetDTCState(DTC_ANGLEcheck_NoEndLearn, FailureDiag_RegOK, 0xFF, 0);
				}				
				else
				{
					Tv_SE_EndStoredFlag = FALSE;
					Fv_AngleEndValidFlag = ANGLE_STS_Invalid;
					Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] = FailureDiag_RegErr;
					//WS_FEE_SetDTCState(DTC_ANGLEcheck_NoEndLearn, FailureDiag_RegErr, 0xFF, 0);
				}
				NvM_StoreRequest.bit.AngEndCalDataReq = 0;
				NvM_State = SWC_ZERO;
			}
			else if(NVM_StoreStatus != NVM_REQ_PENDING)
			{
				Tv_SE_EndStoredFlag = FALSE;
				Fv_AngleEndValidFlag = ANGLE_STS_Invalid;
				NvM_StoreRequest.bit.AngEndCalDataReq = 0;
				Fv_ErrDiagStatus[DTC_ANGLEcheck_NoEndLearn] = FailureDiag_RegErr;
				//WS_FEE_SetDTCState(DTC_ANGLEcheck_NoEndLearn, FailureDiag_RegErr, 0xFF, 0);
				NvM_State = SWC_ZERO;
			}
			else{}
			break;
		case Read_AngEndCalData:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);
			Rte_Call_RPort_ASW_NVM_BR_AngEndCalData_ReadBlock(NVM_Read_Buffer);

			NvM_ReadRequest.bit.AngEndCalDataReq = 0;
			NvM_State = SWC_ZERO;
			break;
		case Write_CCPVal:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[0] = Fv_CANCCP1;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[1] = Fv_CANCCP3;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[2] = Fv_CANCCP13;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[3] = Fv_CANCCP16;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[4] = Fv_CANCCP17;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[5] = Fv_CANCCP50;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[6] = Fv_CANCCP57;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[7] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal),7);
			Rte_Call_RPort_ASW_NVM_BR_CCPVal_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal);
			NvM_StoreRequest.bit.CCPVal = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_CCPVal:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);
			Rte_Call_RPort_ASW_NVM_BR_CCPVal_ReadBlock(NVM_Read_Buffer);

			NvM_ReadRequest.bit.CCPVal = 0;
			NvM_State = SWC_ZERO;
			break;
		case Write_CommonCRCStored:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[0] = (((uint16)Fv_TOCLongStyTrq & 0xFF00) >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[1] = (((uint16)Fv_TOCLongStyTrq & 0x00FF) >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[2] = (((uint16)Fv_AngleCorrectOpr & 0xFF00) >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[3] = (((uint16)Fv_AngleCorrectOpr & 0x00FF) >> 0);
			if(Fv_FriCompAdptiveTorque ==0){
				Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[4] = (((uint16)Fv_FriCompAdptiveTorqueTemp & 0xFF00) >> 8); //mod by liuyang 241023
				Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[5] = (((uint16)Fv_FriCompAdptiveTorqueTemp & 0x00FF) >> 0);
			} else{
				Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[4] = (((uint16)((Fv_FriCompAdptiveTorqueTemp*1+Fv_FriCompAdptiveTorque*3)/4) & 0xFF00) >> 8);
				Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[5] = (((uint16)((Fv_FriCompAdptiveTorqueTemp*1+Fv_FriCompAdptiveTorque*3)/4) & 0x00FF) >> 0);
			}
			// Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[4] = (((uint16)Fv_FriCompAdptiveTorque & 0xFF00) >> 8); //mod by liuyang 241023
			// Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[5] = (((uint16)Fv_FriCompAdptiveTorque & 0x00FF) >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[6] = 0xAA;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[7] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored),7);
			Rte_Call_RPort_ASW_NVM_BR_CommonCRCStored_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored);
			NvM_StoreRequest.bit.CommonCRCStored = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_CommonCRCStored:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);
			Rte_Call_RPort_ASW_NVM_BR_CommonCRCStored_ReadBlock(NVM_Read_Buffer);


			NvM_ReadRequest.bit.CommonCRCStored = 0;
			NvM_State = SWC_ZERO;
			break;
		case Write_PenProf:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[0] = 0;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[1] = 0;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[2] = 0;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[3] = 0;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[4] = 0;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[5] = 0;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[6] = 0xAA;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[7] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf),7);
			Rte_Call_RPort_ASW_NVM_BR_PenProf_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf);
			NvM_StoreRequest.bit.PenProf = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_PenProf:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);
			Rte_Call_RPort_ASW_NVM_BR_PenProf_ReadBlock(NVM_Read_Buffer);

			NvM_ReadRequest.bit.PenProf = 0;
			NvM_State = SWC_ZERO;
			break;
		case Write_StrAngZero:
			if(NvM_Status != NVM_STATE_PROCESS)
			{
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[0] = (uint8)(fsCalibrationData.data.anglezero.a0 >> 8);
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[1] = (uint8)(fsCalibrationData.data.anglezero.a0 >> 0);
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[2] = 0;
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[3] = 0;
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[4] = 0;
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[5] = (uint8)(Fv_AngleMidValidFlag == ANGLE_STS_Calibrating);//stored Flag
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[6] = 0xAA;
				Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[7] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero),7);
				Rte_Call_RPort_ASW_NVM_BR_StrAngZero_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero);
			}
			NvM_Status = NVM_STATE_PROCESS;
			Rte_Call_RPort_ASW_NVM_BR_StrAngZero_GetErrorStatus(&NVM_StoreStatus);
			if(NVM_StoreStatus == NVM_REQ_OK)
			{				
				if(Fv_AngleMidValidFlag == ANGLE_STS_Calibrating)
				{
					Fv_AngleMidValidFlag = ANGLE_STS_Valid;
					Fv_ErrDiagStatus[DTC_ANGLEcheck_NoZeroCalib] = FailureDiag_RegOK;
					//WS_FEE_SetDTCState(DTC_ANGLEcheck_NoZeroCalib, FailureDiag_RegOK, 0xFF, 0);
				}				
				else
				{
					Fv_AngleMidValidFlag = ANGLE_STS_Invalid;
					Fv_ErrDiagStatus[DTC_ANGLEcheck_NoZeroCalib] = FailureDiag_RegErr;
					//WS_FEE_SetDTCState(DTC_ANGLEcheck_NoZeroCalib, FailureDiag_RegErr, 0xFF, 0);
				}
				NvM_StoreRequest.bit.StrAngZero = 0;
				NvM_State = SWC_ZERO;
			}
			else if(NVM_StoreStatus != NVM_REQ_PENDING)
			{
				Fv_AngleMidValidFlag = ANGLE_STS_Invalid;
				NvM_StoreRequest.bit.StrAngZero = 0;
				Fv_ErrDiagStatus[DTC_ANGLEcheck_NoZeroCalib] = FailureDiag_RegOK;
				//WS_FEE_SetDTCState(DTC_ANGLEcheck_NoZeroCalib, FailureDiag_RegErr, 0xFF, 0);
				NvM_State = SWC_ZERO;
			}
			else{}
			break;
		case Read_StrAngZero:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);
			Rte_Call_RPort_ASW_NVM_BR_StrAngZero_ReadBlock(NVM_Read_Buffer);


			NvM_ReadRequest.bit.StrAngZero = 0;
			NvM_State = SWC_ZERO;
			break;	
		case Write_RotorOffset:
			NvM_Status = NVM_STATE_PROCESS;
			/*32*/

			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[0] = (uint8)(AD_RotorSinOffsetMax[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[1] = (uint8)(AD_RotorSinOffsetMax[PreDriver_01] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[2] = (uint8)(AD_RotorSinOffsetMin[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[3] = (uint8)(AD_RotorSinOffsetMin[PreDriver_01] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[4] = (uint8)(AD_RotorCosOffsetMax[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[5] = (uint8)(AD_RotorCosOffsetMax[PreDriver_01] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[6] = (uint8)(AD_RotorCosOffsetMin[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[7] = (uint8)(AD_RotorCosOffsetMin[PreDriver_01] >> 0);

			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[8] = (uint8)(AD_RotorPhasePlusMax[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[9] = (uint8)(AD_RotorPhasePlusMax[PreDriver_01] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[10] = (uint8)(AD_RotorPhasePlusMin[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[11] = (uint8)(AD_RotorPhasePlusMin[PreDriver_01] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[12] = (uint8)(AD_RotorPhaseMinusMax[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[13] = (uint8)(AD_RotorPhaseMinusMax[PreDriver_01] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[14] = (uint8)(AD_RotorPhaseMinusMin[PreDriver_01] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[15] = (uint8)(AD_RotorPhaseMinusMin[PreDriver_01] >> 0);



			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[16] = (uint8)(AD_RotorSinOffsetMax[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[17] = (uint8)(AD_RotorSinOffsetMax[PreDriver_02] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[18] = (uint8)(AD_RotorSinOffsetMin[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[19] = (uint8)(AD_RotorSinOffsetMin[PreDriver_02] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[20] = (uint8)(AD_RotorCosOffsetMax[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[21] = (uint8)(AD_RotorCosOffsetMax[PreDriver_02] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[22] = (uint8)(AD_RotorCosOffsetMin[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[23] = (uint8)(AD_RotorCosOffsetMin[PreDriver_02] >> 0);

			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[24] = (uint8)(AD_RotorPhasePlusMax[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[25] = (uint8)(AD_RotorPhasePlusMax[PreDriver_02] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[26] = (uint8)(AD_RotorPhasePlusMin[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[27] = (uint8)(AD_RotorPhasePlusMin[PreDriver_02] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[28] = (uint8)(AD_RotorPhaseMinusMax[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[29] = (uint8)(AD_RotorPhaseMinusMax[PreDriver_02] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[30] = (uint8)(AD_RotorPhaseMinusMin[PreDriver_02] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[31] = (uint8)(AD_RotorPhaseMinusMin[PreDriver_02] >> 0);

			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[32] = 0xAA;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[33] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset),33);
			Rte_Call_RPort_ASW_NVM_BR_RotorOffset_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset);
			NvM_StoreRequest.bit.RotorOffset = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_RotorOffset:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,32,0x00);
			Rte_Call_RPort_ASW_NVM_BR_RotorOffset_ReadBlock(NVM_Read_Buffer);


			NvM_ReadRequest.bit.RotorOffset = 0;
			NvM_State = SWC_ZERO;
			break;	
		case Write_InitAngle:
			NvM_Status = NVM_STATE_PROCESS;

			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[0] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initangle >> 24);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[1] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initangle >> 16);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[2] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initangle >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[3] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initangle >> 0);

			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[4] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initanglecrr >> 24);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[5] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initanglecrr >> 16);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[6] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initanglecrr >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[7] = (uint8)(MotorCtrl_FocPar[PreDriver_01].initanglecrr >> 0);

			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[8] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initangle >> 24);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[9] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initangle >> 16);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[10] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initangle >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[11] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initangle >> 0);

			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[12] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initanglecrr >> 24);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[13] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initanglecrr >> 16);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[14] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initanglecrr >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[15] = (uint8)(MotorCtrl_FocPar[PreDriver_02].initanglecrr >> 0);

			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[16] = 0xAA;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[17] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle),17);
			Rte_Call_RPort_ASW_NVM_BR_InitAngle_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle);
			NvM_StoreRequest.bit.InitAngle = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_InitAngle:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,8,0x00);
			Rte_Call_RPort_ASW_NVM_BR_InitAngle_ReadBlock(NVM_Read_Buffer);


			NvM_ReadRequest.bit.InitAngle = 0;
			NvM_State = SWC_ZERO;
			break;	
		case Write_CurrentOffset:
			NvM_Status = NVM_STATE_PROCESS;

			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[0] = (uint8)(fsCalibrationData.data.gainoffset.i[0] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[1] = (uint8)(fsCalibrationData.data.gainoffset.i[0] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[2] = (uint8)(fsCalibrationData.data.gainoffset.i[1] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[3] = (uint8)(fsCalibrationData.data.gainoffset.i[1] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[4] = (uint8)(fsCalibrationData.data.gainoffset.i[2] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[5] = (uint8)(fsCalibrationData.data.gainoffset.i[2] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[6] = (uint8)(fsCalibrationData.data.gainoffset.i[3] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[7] = (uint8)(fsCalibrationData.data.gainoffset.i[3] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[8] = (uint8)(fsCalibrationData.data.gainoffset.i[4] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[9] = (uint8)(fsCalibrationData.data.gainoffset.i[4] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[10] = (uint8)(fsCalibrationData.data.gainoffset.i[5] >> 8);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[11] = (uint8)(fsCalibrationData.data.gainoffset.i[5] >> 0);
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[42] = 0xAA;
			Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[43] = CRC8forSAEJ1850((uint8*)(Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset),43);
			Rte_Call_RPort_ASW_NVM_BR_CurrentOffset_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset);
			NvM_StoreRequest.bit.CurrentOffset = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_CurrentOffset:
			NvM_Status = NVM_STATE_PROCESS;
			UpdatePIMWithValue(NVM_Read_Buffer,12,0x00);
			Rte_Call_RPort_ASW_NVM_BR_CurrentOffset_ReadBlock(NVM_Read_Buffer);


			NvM_ReadRequest.bit.CurrentOffset = 0;
			NvM_State = SWC_ZERO;
			break;		
		case Write_DemExtra:
			NvM_Status = NVM_STATE_PROCESS;
			for(i = 0; i < 16; i ++)
			{
				Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[i] = Eeprom_DTCStatus[i];
			}
			for(i = 0; i < 32; i ++)
			{
				Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[i + 16] = Eeprom_CanCCp.byte[i];
			}
			for(i = 0; i < 24; i ++)
			{
				Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[i + 16 + 32] = Eeprom_PINCODE[i];
			}
			Rte_Call_RPort_ASW_NVM_BlockNative_1024_2_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2);//mod by liuyang
			NvM_StoreRequest.bit.DemExtra = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_DemExtra:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_Call_RPort_ASW_NVM_BlockNative_1024_2_ReadBlock(Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_2);
			NvM_ReadRequest.bit.DemExtra = 0;
			NvM_State = SWC_ZERO;
			break;	

		case Write_DIDF190:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_Call_RPort_ASW_NVM_BN_DID_F190_WriteBlock(Rte_CPim_ASW_NVM_ASW_NVM_BN_DID_F190);
			NvM_StoreRequest.bit.Did_F190 = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_DIDF190:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_Call_RPort_ASW_NVM_BN_DID_F190_ReadBlock(Rte_ROM_ASW_NVM_ASW_NVM_BN_F190);
			NvM_ReadRequest.bit.Did_F190 = 0;
			NvM_State = SWC_ZERO;
			break;	

		case Write_DIDD09A:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_Call_RPort_ASW_NVM_BN_DID_D09A_WriteBlock(&Rte_CPim_ASW_NVM_ASW_NVM_BN_DID_D09A[0]);
			NvM_StoreRequest.bit.Did_D09A = 0;
			NvM_State = SWC_ZERO;
			break;
		case Read_DIDD09A:
			NvM_Status = NVM_STATE_PROCESS;
			Rte_Call_RPort_ASW_NVM_BN_DID_D09A_ReadBlock(&Rte_ROM_ASW_NVM_ASW_NVM_BN_D09A[0]);
			NvM_ReadRequest.bit.Did_D09A = 0;
			NvM_State = SWC_ZERO;
			break;	
			
		default:
			/*SWC_ZERO*/
			NvM_Status = NVM_STATE_IDLE;
			break;

	}


}
#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h"
#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h"
/***************************************************************************************************
 Function name    : UpdatePIMWithValue
 Syntax           : void  UpdatePIMWithValue(uint8 *src, uint32 length, uint8 Value)
 Description      : Update PIM's value
 Parameter        : uint8 *src, uint32 length, uint8 Value
 Return value     : none
 ***************************************************************************************************/

void UpdatePIMWithValue(uint8 *dst, uint32 length, uint8 Value)
{
	uint32 Cnt = 0;
	for(Cnt = 0; Cnt < length ; Cnt++)
	{
		*dst = Value;
		dst++;
	}

}

#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h"
#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h"
/***************************************************************************************************
 Function name    : NvM_SwcIModifyNvBlock
 Syntax           : void  NvM_SwcIModifyNvBlock(uint32 addr)
 Description      : Modify data on NV Block
 Parameter        : uint32 addr
 Return value     : none
 ***************************************************************************************************/
uint8 NvM_SwcIWriteDataToRom(uint32 addr, uint8 *Ptr, uint16 Length)
{
	static MDF_State_t MDF_State = MDF_NONE;
	uint8 ret_val = E_NOT_OK;
	switch(MDF_State)
	{
		case MDF_NONE:
			MDF_State = MDF_ERASE_BANK;
			break;
		case MDF_ERASE_BANK: /*erase bank 0 before write data*/
			if( Fls_GetHardWareStatus() == 0)
			{
				Fls_Erase(addr,addr + Length);
				MDF_State = MDF_MODIFY_DATA;
			}
			break;
		case MDF_MODIFY_DATA:
			InvalidData[addr]= CorruptData;
			MDF_State = MDF_UPDATE_DATA;
			break;
		case MDF_UPDATE_DATA: /*write data back to bank 0*/
			if( Fls_GetHardWareStatus() == 0){
				Fls_Write(addr, Ptr, Length);
				MDF_State = MDF_UPDATE_COMPLETE;
			}
			break;
		case MDF_UPDATE_COMPLETE:
			if( Fls_GetHardWareStatus() == 0){
				MDF_State = MDF_NONE;
				ret_val = E_OK;
			}
			break;
		default :
		break;
	}

	return ret_val ;
}

#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h"
#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h"
/***************************************************************************************************
 Function name    : NvM_SwcIModifyNvBlock
 Syntax           : void  NvM_SwcIModifyNvBlock(uint32 addr)
 Description      : Modify data on NV Block
 Parameter        : uint32 addr
 Return value     : none
 ***************************************************************************************************/
uint8 NvM_SwcIModifyNvBlock(uint32 addr)
{
	static MDF_State_t MDF_State = MDF_NONE;
	uint8 ret_val = E_NOT_OK;
	switch(MDF_State)
	{
	case MDF_NONE:
		MDF_State = MDF_INIT_STATE;
		break;
	case MDF_INIT_STATE: /*copy data flash to buffer ram*/;
		NvM_SwcICopyDataToRam(InvalidData, (uint8*)(FLS_17_DMU_BASE_ADDRESS + MngData_Size), sizeof(InvalidData));
		NvM_SwcICopyDataToRam(MngData, (uint8*)FLS_17_DMU_BASE_ADDRESS, sizeof(MngData));
		MDF_State = MDF_ERASE_BANK;
		break;
	case MDF_ERASE_BANK: /*erase bank 0 before write data*/
		if( Fls_GetJobResult() == MEMIF_JOB_OK)
		{
		Fls_Erase(RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0,RBA_FEEFS1X_PRV_CFG_PHYS_SEC_END1 - RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0 + 1);
		MDF_State = MDF_MODIFY_DATA;
		}
		break;
	case MDF_MODIFY_DATA:
		InvalidData[addr]= CorruptData;
		MDF_State = MDF_UPDATE_MANANGMENT_INFO;
		break;
	case MDF_UPDATE_MANANGMENT_INFO: /*write back  management data*/
		if( Fls_GetJobResult() == MEMIF_JOB_OK){
			Fls_Write((uint32)RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0, &MngData[0], sizeof(MngData));
			MDF_State = MDF_UPDATE_DATA;
		}
		break;
	case MDF_UPDATE_DATA: /*write data back to bank 0*/
		if( Fls_GetJobResult() == MEMIF_JOB_OK){
			Fls_Write((uint32)RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0 + sizeof(MngData), &InvalidData[0], sizeof(InvalidData));
			MDF_State = MDF_UPDATE_COMPLETE;
		}
		break;
	case MDF_UPDATE_COMPLETE:
		if( Fls_GetJobResult() == MEMIF_JOB_OK){
			MDF_State = MDF_NONE;
			ret_val = E_OK;
		}
		break;
	default :
		break;
	}

	return ret_val ;
}

#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h"
#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h"
/***************************************************************************************************
 Function name    : NvM_SwcICopyDataToRam
 Syntax           : static uint8 NvM_SwcICopyDataToRam(uint8 * dest_addr, uint8 * src_addr, size)
 Description      : Copy data from ROM to RAM for testing purpose
 Parameter        : uint8 * dest_addr, uint8 * src_addr, size
 Return value     : none
 ***************************************************************************************************/
uint8 NvM_SwcICopyDataToRam(uint8 * dest_addr, uint8 * src_addr, uint32 size)
{
	uint8 retVal = E_NOT_OK;
	if((dest_addr == NULL_PTR) || (NULL_PTR == src_addr) || (0u == size))
	{
		return retVal;
	}
	while(size > 0u)
	{
		*dest_addr = *src_addr;
		dest_addr++;
		src_addr++;
		size--;
	}
	retVal = E_OK;

	return retVal;
}
#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h"

#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h"
/***************************************************************************************************
 Function name    : NvM_BootLoaderDateRead
 Syntax           : none
 Description      : none
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
void NvM_BootLoaderDateRead(uint8 * dest_addr)
{
	Fls_Read(BOOTLOADER_DATA_ADDR,dest_addr,BOOTLOADER_DATA_LENGTH);
}
#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h"

#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h"
/***************************************************************************************************
 Function name    : NvM_BootLoaderDateRead
 Syntax           : none
 Description      : none
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
void NvM_CommonCRCStored_GetErrorStatus(uint8 * Sta)
{
	Rte_Call_RPort_ASW_NVM_BR_CommonCRCStored_GetErrorStatus(&Sta);
}
#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h"

