
#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H


#include "MemIf_Types.h"
#include "Fee.h"



/* Information regarding supplier of this software*/

#define MEMIF_VENDOR_ID                                      (6u)   /*  */
#define MEMIF_MODULE_ID                                      (22u)  /* Module ID of MemIf */
#define MEMIF_INSTANCE_ID                                    (0u)   /* Instance ID of MemIf */

/* MemIf Software Version */
#define MEMIF_SW_MAJOR_VERSION                               (19u)
#define MEMIF_SW_MINOR_VERSION                               (0u)
#define MEMIF_SW_PATCH_VERSION                               (0u)

/* MemIf compatible Autosar Version */
#define MEMIF_AR_RELEASE_MAJOR_VERSION                       (4u)
#define MEMIF_AR_RELEASE_MINOR_VERSION                       (5u)
#define MEMIF_AR_RELEASE_REVISION_VERSION                    (0u)

/*
* Switch for version info api 
*/
#define MEMIF_VERSION_INFO_API                               (STD_OFF)

/* Switch for dev error detect */
#define MEMIF_DEV_ERROR_DETECT                               (STD_ON)
#define MEMIF_FEE_USED                                       (STD_ON)
#define MEMIF_RB_RTE_MAINFUNC_USED                           (STD_ON)

#define MEMIF_NUM_OF_EA_DEVICES                              (0u)
#define MEMIF_MAX_NUM_DEVICES                                (1u)
#define MEMIF_RB_NUM_OF_FEE_DEVICES                          (1u)



#define MEMIF_MIN_NUM_DEVICES                                (0)
/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
 /*
 * if only Fee is used, macros for Fee
 */
#define MemIf_Read(DeviceIndex,BlockNumber,BlockOffset,DataBufferPtr,Length)            Fee_Read(BlockNumber,BlockOffset,DataBufferPtr,Length)
#define MemIf_Write(DeviceIndex,BlockNumber,DataBufferPtr)                              Fee_Write(BlockNumber,DataBufferPtr)
#define MemIf_InvalidateBlock(DeviceIndex,BlockNumber)                                  Fee_InvalidateBlock(BlockNumber)
#define MemIf_GetStatus(DeviceIndex)                                                    Fee_GetStatus()
#define MemIf_GetJobResult(DeviceIndex)                                                 Fee_GetJobResult()
#define MemIf_Cancel(DeviceIndex)                                                       Fee_Cancel()
#define MemIf_EraseImmediateBlock(DeviceIndex,BlockNumber)                              Fee_EraseImmediateBlock(BlockNumber)
#if(( !defined(FEE_RB_VAR_LEN_READ_WRITE_API) || (FEE_RB_VAR_LEN_READ_WRITE_API != FALSE)) || ( !defined(FEE_RB_FIRST_READ_DATA_MIGRATION_API) || (FEE_RB_FIRST_READ_DATA_MIGRATION_API != FALSE))) 
#define MemIf_Rb_VarLenRead(DeviceIndex,BlockNumber,BlockOffset,DataBufferPtr,Length)   Fee_Rb_VarLenRead(BlockNumber,BlockOffset,DataBufferPtr,Length)
#else
#define MemIf_Rb_VarLenRead(DeviceIndex,BlockNumber,BlockOffset,DataBufferPtr,Length)   (E_NOT_OK)
#endif
#if( !defined(FEE_RB_VAR_LEN_READ_WRITE_API) || (FEE_RB_VAR_LEN_READ_WRITE_API != FALSE)) 
#define MemIf_Rb_VarLenWrite(DeviceIndex,BlockNumber,DataBufferPtr,Length)              Fee_Rb_VarLenWrite(BlockNumber,DataBufferPtr,Length)
#else
#define MemIf_Rb_VarLenWrite(DeviceIndex,BlockNumber,DataBufferPtr,Length)              (E_NOT_OK)
#endif
#if( !defined(FEE_RB_FIRST_READ_DATA_MIGRATION_API) || (FEE_RB_FIRST_READ_DATA_MIGRATION_API != FALSE))
#define MemIf_Rb_GetMigrationResult(DeviceIndex,BlockNumber)                            Fee_Rb_GetMigrationResult(BlockNumber)
#else
#define MemIf_Rb_GetMigrationResult(DeviceIndex,BlockNumber)                            (MEMIF_RB_MIGRATION_RESULT_DEACTIVATED_E)
#endif
#if( !defined(FEE_RB_DETAILED_BLK_INFO_API) || (FEE_RB_DETAILED_BLK_INFO_API != FALSE))
#define MemIf_Rb_GetDetailedBlkInfo(DeviceIndex,BlockNumber)                            Fee_Rb_GetDetailedBlkInfo(BlockNumber)
#else
#define MemIf_Rb_GetDetailedBlkInfo(DeviceIndex,BlockNumber)                            (MEMIF_RB_DETAILED_BLK_INFO_NOT_AVAILABLE_E)
#endif
/* The Fee block maintenance API is not available under all conditions */
#if( !defined(FEE_RB_MAINTAIN) || (FEE_RB_MAINTAIN != FALSE))
#define MemIf_Rb_BlockMaintenance(DeviceIndex,BlockNumber)                              Fee_Rb_BlockMaintenance(BlockNumber)
#else
#define MemIf_Rb_BlockMaintenance(DeviceIndex,BlockNumber)                              (E_NOT_OK)
#endif


#define MEMIF_FEE_AND_EA_USED                                (STD_OFF)


#endif /* MEMIF_CFG_H */
