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
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************/

#define SIZE_BLOCK1      1024
#define SIZE_BLOCK2      1024
#define NUMBER_BLOCK_TO_WRITE_DATA_IN_PAGE1      20
#define NUMBER_BLOCK_TO_WRITE_DATA_IN_PAGE2      40
#define MngData_Size     0x500
#define Header_Size      14


#ifndef NvM_SWC_H_
#define NvM_SWC_H_

#define EEPROM_INIT_CURRENTUP (uint16)2304
#define EEPROM_INIT_CURRENTDN (uint16)1792
#define EEPROM_INIT_MAXCCRA   (sint16)800
#define EEPROM_INIT_VALIDA    (uint16)11520//720deg

typedef enum NvM_Test_t{
	SWC_ZERO = 0,
	Write_AngCorrectStored,
	Read_AngCorrectStored,
	Write_AngEndCalData,
	Read_AngEndCalData,
	Write_AngValidEnd,
	Read_AngValidEnd,
	Write_CCPVal,
	Read_CCPVal,
	Write_CommonCRCStored,
	Read_CommonCRCStored,
	Write_PenProf,
	Read_PenProf,
	Write_StrAngZero,
	Read_StrAngZero,
	Write_RotorOffset,
	Read_RotorOffset,
	Write_InitAngle,
	Read_InitAngle,
	Write_CurrentOffset,
	Read_CurrentOffset,
	Write_DemExtra,
	Read_DemExtra,
	Write_DIDF190,
	Read_DIDF190,
	Write_DIDD09A,
	Read_DIDD09A,



	Write_CDD_RotorOffset,
	Read_CDD_RotorOffset,
	Write_CDD_InitAngle,
	Read_CDD_InitAngle,
	Write_CDD_CurrentOffset,
	Read_CDD_CurrentOffset

}NvM_Test_t;
typedef enum NvM_Status_t{
	NVM_STATE_IDLE = 0,
	NVM_STATE_PROCESS = 1,
	NVM_STATE_ERROR = 2,
}NvM_Status_t;

typedef enum NvM_SwcIModifyNvBlock_State_t{
	MDF_NONE,
	MDF_INIT_STATE,
	MDF_ERASE_BANK,
	MDF_MODIFY_DATA,
	MDF_UPDATE_DATA,
	MDF_UPDATE_MANANGMENT_INFO,
	MDF_UPDATE_COMPLETE
}MDF_State_t;

typedef union NvM_StoreReQuest_t{
	struct{
		uint32 AngCorrectStoredReq : 1;
		uint32 AngEndCalDataReq : 1;
		uint32 AngValidEnd : 1;
		uint32 CCPVal : 1;
		uint32 CommonCRCStored : 1;
		uint32 PenProf : 1;
		uint32 StrAngZero : 1;
		uint32 RotorOffset : 1;
		uint32 InitAngle : 1;
		uint32 CurrentOffset : 1;

		uint32 VehicleName : 1;
		uint32 FunConfig : 1;
		uint32 VehicleConfig : 1;
		uint32 SoftwareConfig : 1;
		uint32 ResetFlag : 1;
		uint32 Mileage : 1;
		uint32 TestMode : 1;
		uint32 TOCStudyTrq : 1;
		uint32 VIN : 1;
		uint32 BackUpConfig : 1;
		uint32 DemExtra : 1;

		uint16 Did_D09A : 1;
		uint16 Did_F190 : 1;
	}bit;
	uint32  data;
}NvM_StoreReQuest_t;

typedef union NvM_ReadReQuest_t{
	struct{
		uint32 AngCorrectStoredReq : 1;
		uint32 AngEndCalDataReq : 1;
		uint32 AngValidEnd : 1;
		uint32 CCPVal : 1;
		uint32 CommonCRCStored : 1;
		uint32 PenProf : 1;
		uint32 StrAngZero : 1;
		uint32 RotorOffset : 1;
		uint32 InitAngle : 1;
		uint32 CurrentOffset : 1;

		uint32 VehicleName : 1;
		uint32 FunConfig : 1;
		uint32 VehicleConfig : 1;
		uint32 SoftwareConfig : 1;
		uint32 ResetFlag : 1;
		uint32 Mileage : 1;
		uint32 TestMode : 1;
		uint32 TOCStudyTrq : 1;
		uint32 VIN : 1;
		uint32 BackUpConfig : 1;
		uint32 DemExtra : 1;

		uint16 Did_D09A : 1;
		uint16 Did_F190 : 1;
	}bit;
	uint32  data;
}NvM_ReadReQuest_t;
typedef struct
{
	uint8 UpdataStatus[5];  //C00C
//        bl_u8_t BootProcessFail[8];//C00D
	uint8 StartupFail[4];//C00F
//        bl_u8_t WatchdogTimeout[2];//C014
	uint8 SecurityAccessFailure[4];//BFFF
	uint8 SecurityAccessOK[4];//C000
	uint8 SecurityAcLevelMis;//C000
//        bl_u8_t DetectUnauthDiagAccess[10];
} Auditlog;
extern Auditlog Record_AuditLogFile;
extern void UpdatePIMWithValue(uint8 *dst, uint32 length, uint8 Value) ;
extern uint8 NvM_SwcIModifyNvBlock(uint32 addr);
extern uint8 NvM_SwcIWriteDataToRom(uint32 addr, uint8 *Ptr, uint16 Length);
extern void NvM_CommonCRCStored_GetErrorStatus(uint8 * Sta);
extern void NvM_BootLoaderDateRead(uint8 * dest_addr);
#define ASW_NVM_START_SEC_CONST_8
#include "ASW_NVM_MemMap.h"
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_1[SIZE_BLOCK1];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_2[SIZE_BLOCK2];

extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngCorrectStored[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngEndCalData[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngValidEnd[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CCPVal[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CommonCRCStored[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_PenProf[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_StrAngZero[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_RotorOffset[34];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_InitAngle[18];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CurrentOffset[44];

extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BN_F190[17];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BN_D09A[2];

extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleName[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_FunConfig[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleConfig[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_SoftwareConfig[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_ResetFlag[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_Mileage[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_TestMode[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_TOCStudyTrq[8];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VIN[17];
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_BackupConfig[64];


extern NvM_StoreReQuest_t NvM_StoreRequest;
extern NvM_ReadReQuest_t NvM_ReadRequest;

#define ASW_NVM_STOP_SEC_CONST_8
#include "ASW_NVM_MemMap.h"

extern uint8 shutdown_b;
#endif /* NvM_SWC_H_ */
