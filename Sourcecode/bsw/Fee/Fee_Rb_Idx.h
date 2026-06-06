

#ifndef FEE_RB_IDX_H
#define FEE_RB_IDX_H

#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fee_Cfg.h"
#include "Fee_Rb_Types.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
/* Compiler switch to enable/disable the 'SetMode' functionality for Fee_Rb_Idx based API */
#define FEE_RB_IDX_SET_MODE_SUPPORTED                        (FALSE)

/* Pre-processor switch to enable or disable the API to read out the modules version information for Fee_Rb_Idx based API */
#define FEE_RB_IDX_VERSION_INFO_API                          (FALSE)

/* Pre-processor switch to enable or disable redundant block maintenance for Fee_Rb_Idx based API */
#define FEE_RB_IDX_MAINTAIN                                  (TRUE)

/* Pre-processor switch to enable or disable of variable length for Fee_Rb_Idx based API */
#define FEE_RB_IDX_VAR_LEN_READ_WRITE_API                    (FALSE)

/* Pre-processor switch to enable or disable of migration result for Fee_Rb_Idx based API */
#define FEE_RB_IDX_FIRST_READ_DATA_MIGRATION_API             (FALSE)

/* Pre-processor switch to enable or disable forced sector reorganisation (for one sector) for Fee_Rb_Idx based API */
#define FEE_RB_IDX_TRIGGER_REORG                             (FALSE)

/* Pre-processor switch to enable or disable stop mode for Fee_Rb_Idx based API */
#define FEE_RB_IDX_ENTER_STOP_MODE                           (FALSE)

/* Pre-processor switch to enable or disable free space for Fee_Rb_Idx based API */
#define FEE_RB_IDX_GET_NR_FREE_BYTES                         (FALSE)

/* Pre-processor switch to enable or disable number free bytes and FAT entries for Fee_Rb_Idx based API */
#define FEE_RB_IDX_GET_NR_FREE_BYTES_AND_FAT_ENTRIES         (FALSE)

/* Pre-processor switch to enable or disable chunk-wise job processing Fee_Rb_Idx based APIs */
#define FEE_RB_IDX_CHUNK_JOBS                                (FALSE)

/* Pre-processor switch to enable or disable set and get job mode for Fee_Rb_Idx based APIs */
#define FEE_RB_IDX_SET_AND_GET_JOB_MODE                      (FALSE)

/* Pre-processor switch to enable or disable Detailed Block Info for Fee_Rb_Idx based API */
#define FEE_RB_IDX_DETAILED_BLK_INFO_API                     (FALSE)

/*
 ***************************************************************************************************
 * Extern declarations
 ***************************************************************************************************
 */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern boolean Fee_Rb_IsThisDeviceIndexFee(uint8 DeviceIndex_u8);

extern Fee_Rb_DeviceName_ten Fee_Rb_GetDeviceNameFromDeviceIndex(uint8 feeDeviceIdx_u8);

extern void Fee_Rb_Idx_Init(Fee_Rb_DeviceName_ten deviceName_en, Fee_ConfigType const * ConfigPtr);
extern void Fee_Rb_Idx_EndInit(Fee_Rb_DeviceName_ten deviceName_en);

extern uint32 Fee_Rb_Idx_GetSectChngCnt(Fee_Rb_DeviceName_ten deviceName_en);

extern uint32 Fee_Rb_Idx_GetSectEraseCntr(Fee_Rb_DeviceName_ten deviceName_en, uint8 physSectIdx_u8);

extern void Fee_Rb_Idx_Cancel(Fee_Rb_DeviceName_ten deviceName_en);

extern void Fee_Rb_Idx_MainFunction(Fee_Rb_DeviceName_ten deviceName_en);
extern void Fee_Rb_Idx_MainFunctionAndDependency(Fee_Rb_DeviceName_ten deviceName_en);

extern Std_ReturnType Fee_Rb_Idx_Write(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint8* DataBufferPtr);
extern Std_ReturnType Fee_Rb_Idx_VarLenWrite(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint8* DataBufferPtr, uint16 Length);

extern Std_ReturnType Fee_Rb_Idx_Read(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);
extern Std_ReturnType Fee_Rb_Idx_VarLenRead(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);

extern Std_ReturnType Fee_Rb_Idx_InvalidateBlock(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber);

extern Std_ReturnType Fee_Rb_Idx_EraseImmediateBlock(Fee_Rb_DeviceName_ten deviceName_en, uint16 BlockNumber);

extern Std_ReturnType Fee_Rb_Idx_BlockMaintenance(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber);

extern MemIf_StatusType Fee_Rb_Idx_GetStatus(Fee_Rb_DeviceName_ten deviceName_en);

extern MemIf_JobResultType Fee_Rb_Idx_GetJobResult(Fee_Rb_DeviceName_ten deviceName_en);

extern MemIf_JobResultType Fee_Rb_Idx_GetAdapterJobResult(Fee_Rb_DeviceName_ten deviceName_en);

extern MemIf_JobResultType Fee_Rb_Idx_GetInternalJobResult(Fee_Rb_DeviceName_ten deviceName_en);

/* ### FeeRbFirstReadDataMigration disabled for all users - Fee_Rb_Idx_SetMode API not available ### */

/* ### FeeRbDetailedBlkInfoApi disabled for all users - Fee_Rb_Idx_GetDetailedBlkInfo API not available ### */

extern void Fee_Rb_Idx_DisableBackgroundOperation(Fee_Rb_DeviceName_ten deviceName_en);

extern void Fee_Rb_Idx_EnableBackgroundOperation(Fee_Rb_DeviceName_ten deviceName_en);

/* ### FeeSetModeSupported disabled for all users - Fee_Rb_Idx_SetMode, Fee_Rb_Idx_GetMode API not available ### */

/* ### FeeVersionInfoApi disabled for all users - Fee_Rb_Idx_GetVersionInfo API not available ### */

/* ### FeeRbTriggerReorgApi disabled for all users - Fee_Rb_Idx_TriggerReorg API not available ### */

/* ### FeeRbEnterStopModeApi disabled for all users - Fee_Rb_Idx_EnterStopMode API not available ### */

/* ### FeeRbGetFreeSpaceApi disabled for all users - Fee_Rb_Idx_GetNrFreeBytes API not available ### */

/* ### FeeRbGetNrFreeBytesAndFatEntriesApi disabled for all users - Fee_Rb_Idx_GetNrFreeBytesAndFatEntries API not available ### */

/* ### FeeRbChunkJobApis disabled for all users - Fee_Rb_Idx_Chunk~ APIs not available ### */

extern boolean Fee_Rb_Idx_IsBlockDoubleStorageActiveByBlockNr(Fee_Rb_DeviceName_ten deviceName_en, uint16 blkNr_u16);

extern Fee_Rb_WorkingStateType_ten Fee_Rb_Idx_GetWorkingState(Fee_Rb_DeviceName_ten deviceName_en);

extern Std_ReturnType Fee_Rb_Idx_WritePersistentData(Fee_Rb_DeviceName_ten deviceName_en);
extern uint32         Fee_Rb_Idx_GetNrOfSuprtdErases(Fee_Rb_DeviceName_ten deviceName_en);

/* ### FeeRbSetAndGetJobModeApi disabled - Fee_Rb_Idx_SetJobMode() and Fee_Rb_Idx_GetJobMode() APIs are not available ### */

/* End of Fee section */
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/* FEE_RB_IDX_H */
#endif

