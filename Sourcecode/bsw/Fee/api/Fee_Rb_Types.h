
#ifndef FEE_RB_TYPES_H
#define FEE_RB_TYPES_H


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Std_Types.h"


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/* Error codes for API used for DET module (FEE010) */
#define FEE_E_UNINIT                                 0x01u    /* API service called when module was not initialized */
#define FEE_E_INVALID_BLOCK_NO                       0x02u    /* API service called with invalid block number */
#define FEE_E_INVALID_BLOCK_OFS                      0x03u    /* API service called with invalid block offset */
#define FEE_E_PARAM_POINTER                          0x04u    /* API service called with invalid data pointer */
#define FEE_E_INVALID_DATA_PTR                       FEE_E_PARAM_POINTER  /* Backward Compatibility for AR 4.0 */
#define FEE_E_INVALID_BLOCK_LEN                      0x05u    /* API service called with invalid length information */
#define FEE_E_BUSY                                   0x06u    /* API service called while module still busy */
#define FEE_E_BUSY_INTERNAL                          0x07u    /* API service called while module is busing doing internal management operation */
#define FEE_E_INCOMPATIBLE_VERSIONS                  0x08u    /* Included module versions are incompatible */
#define FEE_E_INIT_FAILED                            0x09u    /* API service called when Fee_Init fails */
#define FEE_E_INVALID_VAR_BLK_LEN_CFG                0xFFu    /* API service called with invalid variable block length configuration */
#define FEE_E_INVALID_MIGRATION_CFG                  0xFEu    /* API service called with invalid block migration configuration */
#define FEE_E_INVALID_BLOCK_CFG                      0xFDu    /* API service called with invalid block configuration */
#define FEE_E_INVALID_DEVICE_NAME                    0xFCu    /* API service called with invalid device name */
#define FEE_E_INVALID_USER                           0xFBu    /* API service called by an invalid user */
#define FEE_E_INVALID_SEQUENCE                       0xFAu    /* API service called in a wrong sequence */
#define FEE_E_INVALID_BUF_LEN                        0xF9u    /* API service called with invalid buffer length */
#define FEE_E_INVALID_MNGT_DATA                      0xF8u    /* API service called with invalid management data */
#define FEE_E_INVALID_JOB_MODE_REQUESTED             0xF7u    /* API service called with invalid job mode */
#define FEE_E_INVALID_SECT_NR                        0xF6u    /* API service called with invalid sector number */

/* API Service IDs used for DET module */
#define FEE_SID_INIT                                 0x00u    /* Service ID for the FEE Init function (unused) */
#define FEE_SID_SETMODE                              0x01u    /* Service ID for the FEE set mode function */
#define FEE_SID_READ                                 0x02u    /* Service ID for the FEE read function */
#define FEE_SID_WRITE                                0x03u    /* Service ID for the FEE write function */
#define FEE_SID_CANCEL                               0x04u    /* Service ID for the FEE job cancel function (unused) */
#define FEE_SID_GETSTATUS                            0x05u    /* Service ID for the FEE get status function (unused) */
#define FEE_SID_GETJOBRESULT                         0x06u    /* Service ID for the FEE get job result function for NvM requests */
#define FEE_SID_INVALIDATE                           0x07u    /* Service ID for the FEE invalidate function */
#define FEE_SID_GETVERSIONINFO                       0x08u    /* Service ID for the FEE get version info function */
#define FEE_SID_ERASEIMMEDIATEBLOCK                  0x09u    /* Service ID for the FEE erase immediate block function (unused) */
#define FEE_SID_JOBENDNOTIFICATION                   0x10u    /* Service ID for the FEE job end notification (unused) */
#define FEE_SID_JOBERRORNOTIFICATION                 0x11u    /* Service ID for the FEE job error notification (unused) */
#define FEE_SID_MAINFUNCTION                         0x12u    /* Service ID for the FEE main function (unused) */
#define FEE_SID_RB_GETDETAILEDBLKINFO                0xE1u    /* Service ID for the FEE to read the detailed block info */
#define FEE_SID_RB_GET_NR_OF_SUPRTD_ERASES           0xE2u    /* Service ID for the FEE get number of supported erases function */
#define FEE_SID_RB_GETJOBMODE                        0xE4u    /* Service ID for the FEE get job mode function */
#define FEE_SID_RB_SETJOBMODE                        0xE5u    /* Service ID for the FEE set job mode function */
#define FEE_SID_RB_CHUNK_READ_FIRST                  0xE6u    /* Service ID for the FEE read first chunk function */
#define FEE_SID_RB_CHUNK_READ_NEXT                   0xE7u    /* Service ID for the FEE read next chunk function */
#define FEE_SID_RB_CHUNK_WRITE_FIRST                 0xE8u    /* Service ID for the FEE write first chunk function */
#define FEE_SID_RB_CHUNK_WRITE_NEXT                  0xE9u    /* Service ID for the FEE write next chunk function */
#define FEE_SID_RB_CHUNK_GET_RESULT                  0xEAu    /* Service ID for the FEE get chunk result function */
#define FEE_SID_RB_CHUNK_GET_NR_BYT_PROC             0xEBu    /* Service ID for the FEE get number of processed chunk bytes function */
#define FEE_SID_RB_CHUNK_TERMINATE                   0xECu    /* Service ID for the FEE terminate chunk function */
#define FEE_SID_RB_ISBLOCKDOUBLESTORAGE              0xEDu    /* Service ID for the FEE is block double storage function */
#define FEE_SID_RB_GETMODE                           0xEEu    /* Service ID for the FEE get mode function */
#define FEE_SID_RB_WRITE_PERSISTENT_DATA             0xEFu    /* Service ID for the FEE write persistent data API */
#define FEE_SID_RB_INTERNAL_GETJOBRESULT             0xF0u    /* Service ID for the FEE get job result function for internal layer requests */
#define FEE_SID_RB_GET_SECT_ERASE_CNTR               0xF1u    /* Service ID for the FEE get sector erase counter API */
#define FEE_SID_RB_GET_WORKING_STATE                 0xF2u    /* Service ID for the FEE get working state API */
#define FEE_SID_RB_GET_NR_FREE_BYTES_AND_FAT_ENTRIES 0xF3u    /* Service ID for the FEE get free space and free FAT entries API */
#define FEE_SID_RB_END_INIT                          0xF4u    /* Service ID for the FEE end init function */
#define FEE_SID_RB_GET_NR_FREE_BYTES                 0xF5u    /* Service ID for the FEE get free space API */
#define FEE_SID_RB_GET_SECT_CHNG_CNT                 0xF6u    /* Service ID for the FEE get sector change counter API */
#define FEE_SID_RB_ENTER_STOP_MODE                   0xF7u    /* Service ID for the FEE stop mode function */
#define FEE_SID_RB_TRIGGER_REORG                     0xF8u    /* Service ID for the FEE forced sector reorganisation */
#define FEE_SID_RB_ENABLE_BG                         0xF9u    /* Service ID for the FEE enable background operations function */
#define FEE_SID_RB_DISABLE_BG                        0xFAu    /* Service ID for the FEE disable background operations function */
#define FEE_SID_RB_MAINTAIN                          0xFBu    /* Service ID for the FEE maintenance function */
#define FEE_SID_RB_ADAPTERGETJOBRESULT               0xFCu    /* Service ID for the FEE get job result function for adapter layer requests */
#define FEE_SID_RB_VARLENWRITE                       0xFDu    /* Service ID for the FEE Rb variable length write function */
#define FEE_SID_RB_VARLENREAD                        0xFEu    /* Service ID for the FEE Rb variable length read function */
#define FEE_SID_RB_GETMIGRATIONRESULT                0xFFu    /* Service ID for the FEE to read the migration result */


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/* Global Fee_MainFunction state machine type
 * Necessary in public header because it is needed by the Mx17 Adapter for the Eep_GetState function */
typedef enum
{
    FEE_RB_IDLE_E = 0,               /* Nothing to do, check order queue */
    FEE_RB_WRITE_MODE_E,             /* A write order is currently being proceeded */
    FEE_RB_READ_MODE_E,              /* A read order is currently being proceeded */
    FEE_RB_INVALIDATE_MODE_E,        /* An invalidation is requested */
    FEE_RB_MAINTAIN_MODE_E,          /* An block maintenance is requested */
    FEE_RB_SOFT_SECTOR_REORG_MODE_E, /* Perform a sector reorganization in the background */
    FEE_RB_HARD_SECTOR_REORG_MODE_E, /* Perform a sector reorganization without allowing interruptions */
    FEE_RB_SECTOR_ERASE_E,           /* The sector will be erased */
    FEE_RB_STOPMODE_E                /* Stop mode requested */
}Fee_Rb_WorkingStateType_ten;

/* Possible order types */
/* Note: To be removed when Fs1 is removed - keep it now for compatibility */
typedef enum
{
    FEE_NO_ORDER = 0,           /* there is no order active */
    FEE_READ_ORDER,             /* order-entry belongs to an read job */
    FEE_WRITE_ORDER,            /* order-entry belongs to an write job */
    FEE_INVALIDATE_ORDER,       /* order-entry belongs to an invalidate job */
    FEE_MAINTAIN_ORDER,         /* order-entry belongs to an maintenance job */
    FEE_FORCED_READ_ORDER       /* order-entry belongs to an forced read job */
}Fee_HlMode_ten;


/* Possible chunk-wise job results */
typedef enum
{
    FEE_RB_CHUNK_ALL_OK_E = 0,  /* Processing all chunks has finished successfully, complete chunk-wise job is done */
    FEE_RB_CHUNK_PART_OK_E,     /* Processing of last chunk has fishished successfully, ready for next chunk */
    FEE_RB_CHUNK_FAILED_E,      /* Processing of chunk-wise job has failed */
    FEE_RB_CHUNK_PENDING_E,     /* Processing of last order/chunk hasn't finished yet */
    FEE_RB_CHUNK_TERMINATED_E   /* Processing of chunk-wise job has been terminated by the user */
} Fee_Rb_ChunkResult_ten;


/* Different kind of Fee jobs. If needed there could be more jobs added in future like MainFunction, reorg and so on */
typedef enum
{
    FEE_RB_JOBTYPE_READ_E = 0,
    FEE_RB_JOBTYPE_WRITE_E,
    FEE_RB_JOBTYPE_INVALIDATE_E,
    FEE_RB_JOBTYPE_BLOCKMAINTENANCE_E,
    FEE_RB_JOBTYPE_TRIGGERREORG_E,
    FEE_RB_JOBTYPE_STOP_MODE_E,

    FEE_RB_JOBTYPE_MAX_E,               /* This enum should not be used by users. It is used internally to define the size of the job type array. */
    FEE_RB_JOBTYPE_WAIT_NEXT_CHUNK_E,   /* This enum is no real job and shall therefore be behind FEE_RB_JOBTYPE_MAX_E */
    FEE_RB_JOBTYPE_TERMINATE_CHUNK_E    /* This enum is no real job and shall therefore be behind FEE_RB_JOBTYPE_MAX_E */
}Fee_Rb_JobType_ten;

/* Different possible modes that could be set for the jobs */
typedef enum
{
    FEE_RB_ALLJOBS_ALLSTEPS_E = 0,        /* this is the default mode setting for all jobs. All standard steps are performed for each job */
    FEE_RB_WRITEJOB_WRITE_VERIFY_E,       /* skip check if data is different from already existing data copy, destroying of old copies for nofallback block, copying of the data into internal buffer (thereby removing the limitation of writing the data only in maximum chunk length = medium buffer size) */
    FEE_RB_WRITEJOB_WRITE_ONLY_E,         /* write the data without any further steps */
    FEE_RB_INVALIDATEJOB_WRITE_VERIFY_E,  /* skip check if block is already invalidated, destroying of old copies for nofallback block */
    FEE_RB_INVALIDATEJOB_WRITE_ONLY_E,    /* write the data without any further steps */

    FEE_RB_JOBMODE_MAX_E   /* This enum should not be used by users. It is used internally to valdiate the parameter passed by the user. */
}Fee_Rb_JobMode_ten;

typedef struct
{
    uint8    dummy_u8;    /* Postcompile configuration isn't supported; Fee_Init always has to get a NULL_PTR */
} Fee_ConfigType;


/* #ifndef FEE_RB_TYPES_H */
#endif
