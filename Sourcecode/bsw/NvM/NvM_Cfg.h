

// TRACE[NVM552]
// Header file specifying NvM pre-compile time configuration parameters

#ifndef NVM_CFG_H
#define NVM_CFG_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

// ensure that all necessary type definitions are available
#include "Std_Types.h"

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2993]
// Function-like macro NVM_CFG_NV_BLOCK_LENGTH shall
// support runtime calculated block lengths
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2997]
// Include declarations of runtime calculated block
// lengths to make it usable in function-like macro NVM_CFG_NV_BLOCK_LENGTH

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/* AUTOSAR version information  */
#define NVM_AR_RELEASE_MAJOR_VERSION                                             (4u)
#define NVM_AR_RELEASE_MINOR_VERSION                                             (5u)
#define NVM_AR_RELEASE_REVISION_VERSION                                          (0u)

/* SW version information   */
#define NVM_SW_MAJOR_VERSION                                                     (19u)
#define NVM_SW_MINOR_VERSION                                                     (0u)
#define NVM_SW_PATCH_VERSION                                                     (0u)

/* Additional defines */
#define NVM_VENDOR_ID                                                            (6u)
#define NVM_MODULE_ID                                                            (20u)
#define NVM_INSTANCE_ID                                                          (0u)


// ---------------------------------------------------------------------------------------------------------------------
// TRACE[NVM028_Conf]
// Defines for common options (in the same order as in the ParamDef)
// ---------------------------------------------------------------------------------------------------------------------

// TRACE[NVM491_Conf]
// Enables/disables some APIs which are related to NvM API configuration classes
#define NVM_API_CONFIG_CLASS                                                     (NVM_API_CONFIG_CLASS_3)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2803]
// Enables/disables the notification of BswM about the current status of the multiblock job
#define NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION                              (STD_ON)

// TRACE[NVM492_Conf]
// ID representing the currently configured block layout
#define NVM_COMPILED_CONFIG_ID                                                   (1u)

// TRACE[ECUC_NvM_00119]
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3186]
// Enables/disables the CRC (re)calculation for the permanent RAM block
#define NVM_CALC_RAM_BLOCK_CRC                                                   (STD_OFF)
// Number of blocks definitions using RAM block CRC for different CRC types
#define NVM_CFG_CRC_8_NR_RAM_BLOCKS                                              (0u)
#define NVM_CFG_CRC_16_NR_RAM_BLOCKS                                             (0u)
#define NVM_CFG_CRC_32_NR_RAM_BLOCKS                                             (0u)
#define NVM_CFG_CRC_NR_RAM_BLOCKS                                                (0u)
// TRACE[NVM119_Conf]
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3249]
// Enables/disables the usage of CRC for user data encryption
#define NVM_CALC_CRYPTO_CRC                                                      (STD_OFF)
// TRACE[NVM036_Conf]
// TRACE[NVM476_Conf]
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3187]
// Enables/disables the additional storage of CRC in the non-volatile memory
#define NVM_CALC_NV_CRC                                                          (STD_OFF)

// Enables/disables the usage of CRC services by the NvM
// Usage of CRC services is enabled if at least one of following features is enabled:
// - CRC (re)calculation for the permanent RAM block
// - usage of CRC for user data encryption
// - storage of CRC in the non-volatile memory
#define NVM_CALC_CRC                    (   (NVM_CALC_RAM_BLOCK_CRC == STD_ON)  \
                                         || (NVM_CALC_CRYPTO_CRC == STD_ON)     \
                                         || (NVM_CALC_NV_CRC == STD_ON))

/* BSWEXT-293 */
#define NVM_PRV_CFG_SIZE_ADDING_LENGTH_STRING                                    (0u)
#define NVM_PRV_CFG_SIZE_CRYPTO_BUFFER_CFG                                       (0u)
/* END BSWEXT-293 */

// TRACE[NVM493_Conf]
// Maximum number of bytes which shall be processed within one cycle of job processing
#define NVM_CRC_NUM_OF_BYTES                                                     (1u)

// The parameter NvMDatasetSelectionBits is not supported in this implementation of NvM

// Enables/disables usage of cryptographic services
#define NVM_CRYPTO_USED                                                          (STD_OFF)
#define NVM_CRYPTO_RANDOM_USED                                                   (STD_OFF)
#define NVM_CRYPTO_KEY_SETTING_USED                                              (STD_OFF)
#define NVM_CRYPTO_ENCRYPTION_USED                                               (STD_OFF)
#define NVM_CRYPTO_AEAD_ENCRYPTION_USED                                          (STD_OFF)
#define NVM_CRYPTO_SIGNATURE_USED                                                (STD_OFF)

// TRACE[ECUC_NvM_00572]
// Number of retries for Csm jobs for cryptographic services
#define NVM_CSM_RETRY_COUNTER                                                    (0u)

// TRACE[NVM495_Conf]
// Enables/disables development error detection
#define NVM_DEV_ERROR_DETECT                                                     (STD_ON)

// TRACE[NVM496_Conf]
// Enables/disables switching memory drivers to fast mode
// during performing NvM_ReadAll/NvM_WriteAll
#define NVM_DRV_MODE_SWITCH                                                      (STD_OFF)

// TRACE[NVM497_Conf]
// Enables/disables the dynamic configuration management handling
// by the NvM_ReadAll request
#define NVM_DYNAMIC_CONFIGURATION                                                (STD_ON)

// TRACE[NVM498_Conf]
// Enables/disables job prioritization handling
#define NVM_JOB_PRIORITIZATION                                                   (STD_OFF)

// TRACE[ECUC_NvM_00555]
// Defines the cycle time in seconds of the periodic calling of NvM main function
#define NVM_MAIN_FUNCTION_PERIOD                                                 (0.0099999997764826f)

// TRACE[NVM500_Conf]
// Callback routine indicating termination of each asynchronous multi block requests
#define NVM_MULTI_BLOCK_CALLBACK                                                 (NULL_PTR)

// TRACE[NVM501_Conf]
// Enables/disables polling mode in NvM
// (disables/enables callback functions for lower layers)
#define NVM_POLLING_MODE                                                         (STD_ON)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2945]
// Enables/disables the auxiliary service interface
#define NVM_RB_AUX_INTERFACE                                                     (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-xxx]
// Enables/disables the block header
#define NVM_RB_BLOCK_HEADER                                                      (0u)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-xxx]
// Defines the block header length if enabled
#define NVM_RB_BLOCK_HEADER_LENGTH                                               (0u)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3307]
// Defines whether NvM loads default values (STD_ON) or skips reading for non-resistant blocks (STD_OFF)
// in case of layout change for dynamic configuration defined by Autosar
#define NVM_RB_DYN_CONFIG_LOAD_DEFAULTS                                          (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3405]
// Enables/disables the error info detail interface
#define NVM_RB_ERROR_INFO_DETAIL                                                 (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2746]
// Version of the generated ARXML file(s)
#define NVM_RB_GEN_ARXML_VERSION                                                 (NVM_GEN_ARXML_VERSION_402)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2893]
// Enables/disables the initialization of blocks
#define NVM_RB_INIT_AT_LAYOUT_CHANGE                                             (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2762]
// Callback routine indicating the start of each asynchronous multi block operation
#define NVM_RB_MULTI_BLOCK_START_CALLBACK                                        (NULL_PTR)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2843]
// Callback routine indicating termination of any NvM job
#define NVM_RB_OBSERVER_CALLBACK                                                 (NULL_PTR)

// RAM (re-)intialization definitions
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2786]
// Defines the behavior of NvM module when saved RAM zone is lost
#define NVM_RB_RAM_INIT_CHECK                                                    (NVM_RB_RAM_INIT_CHECK_NONE)
// NvM blocks RAM status bits are initialized with default values.
// Saved RAM zone is considered lost.
#define NVM_RB_RAM_INIT_CHECK_NONE  (0u)
// NvM blocks RAM status bits are not initialized. Only blocks with INVLAID RAM bit have
// their RAM blocks filled in with Nv data during NvM_ReadAll.
#define NVM_RB_RAM_INIT_CHECK_QUICK (1u)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2787]
// Enables/disables enhanced configuration
#define NVM_RB_REMOVE_NON_RESISTANT_BLOCKS                                       (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2977]
// Enables/disables the NvM_Rb_SetWriteAllTrigger API
#define NVM_RB_SET_WRITEALL_TRIGGER_API                                          (STD_ON)

// TRACE[NVM518_Conf]
// Number of retries for mirror operations before postponing the current job
#define NVM_REPEAT_MIRROR_OPERATIONS                                             (0u)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3296]
// Enables/disables block write counter
#define NVM_RB_BLOCK_WRITE_COUNTER                                               (STD_OFF)

// NvM usage flag, set to STD_ON if at least one NvM block has a configured block version.
#define NVM_RB_BLOCK_VERSION                                                     (STD_OFF)

// TRACE[NVM502_Conf]
// Enables/disables the NvM_SetRamBlockStatus API
#define NVM_SET_RAM_BLOCK_STATUS_API                                             (STD_ON)

// TRACE[NVM503_Conf]
// Number of queue entries for the immediate priority job queue
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE                                             (1u)

// TRACE[NVM504_Conf]
// Number of queue entries for the standard job queue
#define NVM_SIZE_STANDARD_JOB_QUEUE                                              (11u)

// TRACE[NVM505_Conf]
// Enables/disables the NvM_GetVersionInfo API
#define NVM_VERSION_INFO_API                                                     (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3298]
// Enables/disables the initialization of the NvM buffer before invoking the sync write callback
#define NVM_RB_INIT_BUFFER_BEFORE_SYNC_WRITE                                     (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3330]
// Enables/disables no single block request before ReadAll feature
#define NVM_RB_NO_SINGLE_BLOCK_BEFORE_READALL                                    (STD_OFF)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3124]
// Defines the request monitoring function for the NvM
#define NVM_RB_REQ_MONITOR                                                       (NVM_RB_REQ_MON_DISABLED)
// Request monitoring disabled
#define NVM_RB_REQ_MON_DISABLED (0u)
// Monitoring of write requests enabled
#define NVM_RB_REQ_MON_WRITE (1u)

// RTE usage flag, set to STD_ON if at least one NvM block is using the RTE ports.
#define NVM_RB_RTE_USED                                                          (STD_ON)
// RTE scheduling is configured
#define NVM_RB_RTE_MAINFUNC_USED                                                 (STD_ON)


// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3333]
// Enables/disables the usage of const qualifier in NvMBuffer parameter of read callback
#define NVM_RB_EXPLICIT_SYNC_READ_WITH_CONST                                     (STD_OFF)


// ---------------------------------------------------------------------------------------------------------------------
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2914]
// Names of overloaded API functions
// ---------------------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------------------------------------------
// TRACE[NVM481_Conf]
// IDs for all configured blocks
// ---------------------------------------------------------------------------------------------------------------------

#define NvMConf_NvMBlockDescriptor_NvM_MultiBlock                                (0u)
#define NvMConf_NvMBlockDescriptor_NvM_ConfigId                                  (1u)
#define NvMConf_NvMBlockDescriptor_ECUM_CFG_NVM_BLOCK                            (2u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_DEM_GENERIC_NV_DATA                    (3u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_0                            (4u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_1                            (5u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_10                           (6u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_11                           (7u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_12                           (8u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_13                           (9u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_14                           (10u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_15                           (11u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_16                           (12u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_17                           (13u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_18                           (14u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_19                           (15u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_2                            (16u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_20                           (17u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_21                           (18u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_22                           (19u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_23                           (20u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_24                           (21u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_25                           (22u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_26                           (23u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_27                           (24u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_28                           (25u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_29                           (26u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_3                            (27u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_30                           (28u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_31                           (29u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_32                           (30u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_33                           (31u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_34                           (32u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_35                           (33u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_36                           (34u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_37                           (35u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_38                           (36u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_39                           (37u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_4                            (38u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_5                            (39u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_6                            (40u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_7                            (41u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_8                            (42u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_9                            (43u)
#define NvMConf_NvMBlockDescriptor_NVM_ID_EVT_STATUSBYTE                         (44u)
#define NvMConf_NvMBlockDescriptor_NV_CrcBlock                                   (45u)
#define NvMConf_NvMBlockDescriptor_NV_ExternalReprogrammingRequestFlagBlock      (46u)
#define NvMConf_NvMBlockDescriptor_NV_PartNumberBlock                            (47u)
#define NvMConf_NvMBlockDescriptor_NV_ProgrammingAttemptCounterBlock             (48u)
#define NvMConf_NvMBlockDescriptor_NV_ProgrammingCounterBlock                    (49u)
#define NvMConf_NvMBlockDescriptor_NV_ResetResponseFlagBlock                     (50u)
#define NvMConf_NvMBlockDescriptor_NV_ValidityFlagsBlock                         (51u)
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_IOControl              (52u)
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_SystemFaultRank        (53u)
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_VehicleSpeed           (54u)
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ReadWritebyAddress         (55u)
#define NvMConf_NvMBlockDescriptor_NvM_BN_DID_D09A                               (56u)
#define NvMConf_NvMBlockDescriptor_NvM_BN_DID_F190                               (57u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_AngCorrectStored                       (58u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_AngEndCalData                          (59u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_AngValidEnd                            (60u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_BackupConfig                           (61u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_CCPVal                                 (62u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_CommonCRCStored                        (63u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_CurrentOffset                          (64u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_FunConfig                              (65u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_InitAngle                              (66u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_Mileage                                (67u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_PenProf                                (68u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_ResetFlag                              (69u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_RotorOffset                            (70u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_SoftwareConfig                         (71u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_StrAngZero                             (72u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_TOCStudyTrq                            (73u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_TestMode                               (74u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_VIN                                    (75u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_VehicleConfig                          (76u)
#define NvMConf_NvMBlockDescriptor_NvM_BR_VehicleName                            (77u)
#define NvMConf_NvMBlockDescriptor_NvM_NATIVE_IDS_1024                           (78u)
#define NvMConf_NvMBlockDescriptor_NvM_NativeBlock_2                             (79u)
#define NvMConf_NvMBlockDescriptor_NvM_NativeBlock_3                             (80u)

// ---------------------------------------------------------------------------------------------------------------------
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2801]
// Lengths of all configured blocks as define
// ---------------------------------------------------------------------------------------------------------------------

#define NVM_CFG_NV_BLOCK_LENGTH_NvM_MultiBlock                                   (1u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_ConfigId                                     (2u)
#define NVM_CFG_NV_BLOCK_LENGTH_ECUM_CFG_NVM_BLOCK                               (4u)
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_DEM_GENERIC_NV_DATA                       (DEM_SIZEOF_VAR(Dem_GenericNvData))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_0                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_1                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_10                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_11                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_12                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_13                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_14                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_15                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_16                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_17                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_18                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_19                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_2                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_20                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_21                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_22                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_23                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_24                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_25                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_26                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_27                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_28                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_29                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_3                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_30                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_31                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_32                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_33                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_34                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_35                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_36                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_37                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_38                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_39                              (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_4                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_5                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_6                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_7                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_8                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVMEM_LOC_9                               (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType))
#define NVM_CFG_NV_BLOCK_LENGTH_NVM_ID_EVT_STATUSBYTE                            (DEM_SIZEOF_VAR(Dem_AllEventsStatusByte))
#define NVM_CFG_NV_BLOCK_LENGTH_NV_CrcBlock                                      (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NV_ExternalReprogrammingRequestFlagBlock         (1u)
#define NVM_CFG_NV_BLOCK_LENGTH_NV_PartNumberBlock                               (32u)
#define NVM_CFG_NV_BLOCK_LENGTH_NV_ProgrammingAttemptCounterBlock                (4u)
#define NVM_CFG_NV_BLOCK_LENGTH_NV_ProgrammingCounterBlock                       (4u)
#define NVM_CFG_NV_BLOCK_LENGTH_NV_ResetResponseFlagBlock                        (1u)
#define NVM_CFG_NV_BLOCK_LENGTH_NV_ValidityFlagsBlock                            (1u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvMBlockDescriptor_DID_IOControl                 (17u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvMBlockDescriptor_DID_SystemFaultRank           (4u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvMBlockDescriptor_DID_VehicleSpeed              (17u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvMBlockDescriptor_ReadWritebyAddress            (4u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BN_DID_D09A                                  (2u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BN_DID_F190                                  (17u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_AngCorrectStored                          (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_AngEndCalData                             (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_AngValidEnd                               (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_BackupConfig                              (64u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_CCPVal                                    (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_CommonCRCStored                           (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_CurrentOffset                             (44u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_FunConfig                                 (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_InitAngle                                 (18u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_Mileage                                   (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_PenProf                                   (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_ResetFlag                                 (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_RotorOffset                               (34u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_SoftwareConfig                            (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_StrAngZero                                (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_TOCStudyTrq                               (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_TestMode                                  (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_VIN                                       (17u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_VehicleConfig                             (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_BR_VehicleName                               (8u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_NATIVE_IDS_1024                              (1024u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_NativeBlock_2                                (1024u)
#define NVM_CFG_NV_BLOCK_LENGTH_NvM_NativeBlock_3                                (1024u)

// ---------------------------------------------------------------------------------------------------------------------
// Miscellaneous other definitions
// ---------------------------------------------------------------------------------------------------------------------

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3028]
// Define directive for checking
// Runtime RAM Block Configuration feature enabled/disabled
#define NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG                                         (STD_OFF)

// RAM Mirror definitions
// NvM uses a RAM mirror (internal buffer) in following cases:
// - Explicit synchronization is enabled
// - NV CRC is enabled
// - Cryptographic services are enabled
#define NVM_PRV_SIZE_RAM_MIRROR_USER_CONF                                        (0u)
#define NVM_PRV_HAS_RAM_MIRROR                                                   (STD_ON)
#define NVM_PRV_EXPLICIT_SYNC                                                    (STD_ON)
// Block Length String used by Dem definitions
/* BSWEXT-293 */
#define NVM_DEM_BLOCK_LENGTH_STRING_USED                                         (STD_ON)
/* END BSWEXT-293 */
// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2870]
// The implementation of the maintenance operation is done as if this feature was configurable
// Enables/disables the maintenance of redundant blocks (internal definition)
#define NVM_PRV_MAINTAIN_REDUNDANT_BLOCKS                                        (STD_ON)

// Number of memory devices used by NvM
#define NVM_CFG_NR_MEMIF_DEVICES                                                 (1u)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3158]
// ID of the first used block
#define NVM_CFG_FIRST_USED_BLOCK                                                 (1u)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2849]
// ID of the last NvM user block
#define NVM_CFG_LAST_USER_BLOCK                                                  (80u)

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3159]
// Number of all configured blocks
#define NVM_CFG_NR_BLOCKS                                                        (81u)

// Additional internal helper definitions
#define NVM_PRV_NR_BLOCKS_ADMIN                                                  (81u)
#define NVM_PRV_NR_PERSISTENT_IDS                                                (80u)

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
/// Type definition for IDs of job resources used by NvM.
typedef uint8 NvM_Prv_idJobResource_tuo;

/// Enumeration which defines all possible values for job resource IDs in type NvM_Prv_IdJobResource_tuo.
enum
{
    NvM_Prv_idJobResource_MemIf_0_e,

    //----------------------------------------------------------------------------------------
    /// Number of job resource IDs available in NvM.
    ///
    /// This is actually no job resource ID,
    /// in fact this enum value defines count of job resource IDs available in NvM
    /// and can be used for array definitions.
    /// Additionally this value can be used as special ID to identify an invalid job resource.
    //----------------------------------------------------------------------------------------
    NvM_Prv_idJobResource_NrJobResources_e

};


#endif
