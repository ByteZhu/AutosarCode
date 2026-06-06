
#ifndef FEE_H
#define FEE_H

#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fee_Rb_Types.h"   // All static macros + type defs included via this header file
#include "Fee_Cfg.h"        // To get the definitions of Fls hook function

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
#define FEE_VENDOR_ID                                        (6u)   /*  */
#define FEE_MODULE_ID                                        (21u)  /* Module ID of Fee */
#define FEE_INSTANCE_ID                                      (0u)   /* Instance ID */

/* Fee Software Version */
#define FEE_SW_MAJOR_VERSION                                 (19u)
#define FEE_SW_MINOR_VERSION                                 (0u)
#define FEE_SW_PATCH_VERSION                                 (0u)

/* Fee compatible Autosar Version */
#define FEE_AR_RELEASE_MAJOR_VERSION                         (4u)
#define FEE_AR_RELEASE_MINOR_VERSION                         (5u)
#define FEE_AR_RELEASE_REVISION_VERSION                      (0u)

/* Pre-processor switch to enable or disable development error detection */
#define FEE_DEV_ERROR_DETECT                                 (STD_ON)

/* Compiler switch to enable/disable the 'SetMode' functionality of the FEE module */
#define FEE_SET_MODE_SUPPORTED                               (STD_OFF)

/* Pre-processor switch to enable or disable the API to read out the modules version information */
#define FEE_VERSION_INFO_API                                 (STD_OFF)

/* Pre-processor switch to enable or disable redunant block maintenance API */
#define FEE_RB_MAINTAIN                                      (TRUE)

/* Pre-processor switch to enable or disable of variable length APIs */
#define FEE_RB_VAR_LEN_READ_WRITE_API                        (FALSE)

/* Pre-processor switch to enable or disable of migration result APIs */
#define FEE_RB_FIRST_READ_DATA_MIGRATION_API                 (FALSE)

/* Pre-processor switch to enable or disable forced sector reorganisation (for one sector) */
#define FEE_RB_TRIGGER_REORG                                 (FALSE)

/* Pre-processor switch to enable or disable stop mode */
#define FEE_RB_ENTER_STOP_MODE                               (FALSE)

/* Pre-processor switch to enable or disable free space API */
#define FEE_RB_GET_NR_FREE_BYTES                             (FALSE)

/* Pre-processor switch to enable or disable sector erase counter APIs */
#define FEE_RB_GET_NR_SECTOR_ERASES                          (FALSE)

/* Pre-processor switch to enable or disable number free bytes and FAT entries API */
#define FEE_RB_GET_NR_FREE_BYTES_AND_FAT_ENTRIES             (FALSE)

/* Pre-processor switch to  indicate if the block properties table is in ROM or RAM */
#define FEE_RB_USE_ROM_BLOCKTABLE                            (FALSE)

/* Pre-processor switch to enable or disable Set and Get Job Mode APIs */
#define FEE_RB_SET_AND_GET_JOB_MODE                          (FALSE)

/* Pre-processor switch to enable or disable Detailed Block Info API */
#define FEE_RB_DETAILED_BLK_INFO_API                         (FALSE)

/* Hook into synchronous Fls_MainFunction loop */
#define FEE_RB_SYNC_LOOP_FLS_MAIN_HOOK()                     ((void)0)

/* ******************************************************************************************************************
   ******************************************** FeePublishedInformation *********************************************
   ****************************************************************************************************************** */

/* FEE116_Conf: FeeVirtualPageSize {FEE_BLOCK_OVERHEAD}. Management overhead per logical block in bytes. */
#define FEE_VIRTUAL_PAGE_SIZE                                (8u)

/* FEE117_Conf: FeeBlockOverhead {FEE_BLOCK_OVERHEAD}. Management overhead per logical block in bytes. */
#define FEE_BLOCK_OVERHEAD                                   (14u)

/* FEE118_Conf: FeePageOverhead {FEE_PAGE_OVERHEAD}. Management overhead per page in bytes. */
#define FEE_PAGE_OVERHEAD                                    (0u)

/* ******************************************************************************************************************
   ******************************************* Generate FLASH configuration *****************************************
   ****************************************************************************************************************** */

#define FEE_CFG_EMULATION_START                              (0x00000000uL)
#define FEE_CFG_EMULATION_END                                (0x00007FFFuL)
#define FEE_CFG_EMULATION_SIZE                               (0x00008000uL)

#define FEE_NUM_FLASH_BANKS_AVAILABLE                        (2u)

/* ******************************************************************************************************************
   ******************************************* Defines for accessing blocks *****************************************
   ****************************************************************************************************************** */
#ifndef FEE_CFG_BLOCKDEFINES_H
#define FeeConf_FeeBlockConfiguration_NvM_BR_AngCorrectStored                                        (0u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_4                                             (1u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_5                                             (2u)
#define FeeConf_FeeBlockConfiguration_NV_ValidityFlagsBlock                                          (3u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_ResetFlag                                               (4u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_7                                             (5u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_6                                             (6u)
#define FeeConf_FeeBlockConfiguration_NV_PartNumberBlock                                             (7u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_VehicleConfig                                           (8u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_CommonCRCStored                                         (9u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_TOCStudyTrq                                             (10u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_CCPVal                                                  (11u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_1                                             (12u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_0                                             (13u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_18                                            (14u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_29                                            (15u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_39                                            (16u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_2                                             (17u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_3                                             (18u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_19                                            (19u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_38                                            (20u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_28                                            (21u)
#define FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_SystemFaultRank                         (22u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_DEM_GENERIC_NV_DATA                                     (23u)
#define FeeConf_FeeBlockConfiguration_NV_ProgrammingCounterBlock                                     (24u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_TestMode                                                (25u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVT_STATUSBYTE                                          (26u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_VehicleName                                             (27u)
#define FeeConf_FeeBlockConfiguration_NV_CrcBlock                                                    (28u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_StrAngZero                                              (29u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_9                                             (30u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_8                                             (31u)
#define FeeConf_FeeBlockConfiguration_NvM_ConfigId                                                   (32u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_FunConfig                                               (33u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_CurrentOffset                                           (34u)
#define FeeConf_FeeBlockConfiguration_NV_ExternalReprogrammingRequestFlagBlock                       (35u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_31                                            (36u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_21                                            (37u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_10                                            (38u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_AngValidEnd                                             (39u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_20                                            (40u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_30                                            (41u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_11                                            (42u)
#define FeeConf_FeeBlockConfiguration_NvM_BN_DID_D09A                                                (43u)
#define FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_ReadWritebyAddress                          (44u)
#define FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_IOControl                               (45u)
#define FeeConf_FeeBlockConfiguration_NvM_NativeBlock_2                                              (46u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_12                                            (47u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_33                                            (48u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_23                                            (49u)
#define FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_VehicleSpeed                            (50u)
#define FeeConf_FeeBlockConfiguration_NvM_NativeBlock_3                                              (51u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_13                                            (52u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_22                                            (53u)
#define FeeConf_FeeBlockConfiguration_NV_ProgrammingAttemptCounterBlock                              (54u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_32                                            (55u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_34                                            (56u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_24                                            (57u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_15                                            (58u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_InitAngle                                               (59u)
#define FeeConf_FeeBlockConfiguration_NvM_NATIVE_IDS_1024                                            (60u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_25                                            (61u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_35                                            (62u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_RotorOffset                                             (63u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_14                                            (64u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_Mileage                                                 (65u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_BackupConfig                                            (66u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_PenProf                                                 (67u)
#define FeeConf_FeeBlockConfiguration_NvM_BN_DID_F190                                                (68u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_SoftwareConfig                                          (69u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_17                                            (70u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_36                                            (71u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_AngEndCalData                                           (72u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_26                                            (73u)
#define FeeConf_FeeBlockConfiguration_NV_ResetResponseFlagBlock                                      (74u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_16                                            (75u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_27                                            (76u)
#define FeeConf_FeeBlockConfiguration_ECUM_CFG_NVM_BLOCK                                             (77u)
#define FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_37                                            (78u)
#define FeeConf_FeeBlockConfiguration_NvM_BR_VIN                                                     (79u)
#endif /* FEE_CFG_BLOCKDEFINES_H */

/* ******************************************************************************************************************
   ********************************************** Fs specific defines ***********************************************
   ****************************************************************************************************************** */

#define FEE_CFG_FEE_COMMON_ENABLED                           (TRUE)
#define FEE_CFG_MULTIINSTANCE_ENABLED                        (FALSE)
#define FEE_CFG_FEE1X_ENABLED                                (TRUE)
#define FEE_REQUIRED_FREE_SPACE_BEFORE_SOFT_SR               (16288uL)
 // Threshold when reached soft reorganisation will start 
#define FEE_REQUIRED_FREE_SPACE_BEFORE_HARD_SR               (16288uL)
 // Threshold when reached hard reorganisation will start

/* ******************************************************************************************************************
   ******************* External declarations of functions that are supported (enabled) for this instance ************
   ****************************************************************************************************************** */

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

// mandatory AUTOSAR APIs that are always supported
extern void                 Fee_Init(Fee_ConfigType const * CfgPtr_pst);
extern Std_ReturnType       Fee_Read(uint16 nrBlks_u16, uint16 nrBlkOffs_u16, uint8 * DataBuf_pu8, uint16 nrLen_u16);
extern Std_ReturnType       Fee_Write(uint16 nrBlks_u16, uint8 * DataBuf_pu8);
extern Std_ReturnType       Fee_InvalidateBlock(uint16 nrBlks_u16);
extern Std_ReturnType       Fee_EraseImmediateBlock(uint16 nrBlks_u16);
#ifndef FEE_RB_HIDE_MAINFUNC_RTEAPI
/* This declaration is used only if RTE generator is NOT used */
extern void                 Fee_MainFunction(void);
#endif /* FEE_RB_HIDE_MAINFUNC_RTEAPI */
extern MemIf_StatusType     Fee_GetStatus(void);
extern MemIf_JobResultType  Fee_GetJobResult(void);
extern void                 Fee_Cancel(void);

// optional AUTOSAR APIs that are supported when the feature is enabled
/* ### FeeSetModeSupported disabled - Fee_SetMode API not available ### */
/* ### FeeVersionInfoApi disabled - Fee_GetVersionInfo API not available ### */

// non autosar APIs that are always supported
#ifndef FEE_RB_HIDE_ENDINIT_RTEAPI
/* This declaration is used only if RTE generator is NOT used */
extern void                         Fee_Rb_EndInit(void);
#endif /* FEE_RB_HIDE_ENDINIT_RTEAPI */
extern MemIf_JobResultType          Fee_Rb_GetAdapterJobResult(void);
extern uint32                       Fee_Rb_GetSectChngCnt(void);
extern void                         Fee_Rb_DisableBackgroundOperation(void);
extern void                         Fee_Rb_EnableBackgroundOperation(void);
extern boolean                      Fee_Rb_IsBlockDoubleStorageActiveByBlockNr(uint16 blkNr_u16);
extern Fee_Rb_WorkingStateType_ten  Fee_Rb_GetWorkingState(void);
extern void                         Fee_Rb_MainFunctionAndDependency(void);

// non autosar APIs that are supported when the feature is enabled
extern Std_ReturnType               Fee_Rb_BlockMaintenance(uint16 nrBlks_u16);
/* ### FeeRbVarBlockLength and FeeRbFirstReadDataMigration disabled for all blocks - Fee_Rb_VarLenRead API not available ### */
/* ### FeeRbVarBlockLength disabled for all blocks - Fee_Rb_VarLenWrite API not available ### */
/* ### FeeRbFirstReadDataMigration disabled for all blocks - Fee_Rb_GetMigrationResult API not available ### */
/* ### FeeRbDetailedBlkInfoApi disabled - Fee_Rb_GetDetailedBlkInfo API not available ### */
/* ### FeeRbTriggerReorgApi disabled - Fee_Rb_TriggerReorg API not available ### */
/* ### FeeSetModeSupported disabled - Fee_SetMode, Fee_Rb_GetMode API not available ### */
/* ### FeeRbGetNrSectorErases disabled - APIs for writing persistent data are not available ### */
/* ### FeeRbGetNrSectorErases disabled - APIs for accessing number of performed erase cycles not available ### */

/* ### FeeRbEnterStopModeApi disabled - Fee_Rb_EnterStopMode API not available ### */
/* ### FeeRbGetFreeSpaceApi disabled - Fee_Rb_GetNrFreeBytes API not available ### */
/* ### FeeRbGetNrFreeBytesAndFatEntriesApi disabled - Fee_Rb_GetNrFreeBytesAndFatEntries API not available ### */
/* ### FeeRbSetAndGetJobModeApi disabled - Fee_Rb_SetJobMode() and Fee_Rb_GetJobMode() APIs are not available ### */

/* End of Fee section */
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


/* ******************************************************************************************************************
   *********************** Macro for external declarations of hook functions provided to Fee ************************
   ****************************************************************************************************************** */


#endif /* FEE_H */
