
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
#if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

#include "MemIf_Types.h"
#include "rba_MemLib.h"
#include "Fee_Cfg_SchM.h"
#include "Fee_Cfg.h"             // to get the device name Fee_Rb_DeviceName_ten
#include "Fee_Rb_Types.h"
#include "Fee_Rb_Idx.h"
#include "Fee_Prv_Config.h"
#include "Fee_Prv_Dbg.h"
#include "Fee_Prv_FsIf.h"
#include "Fee_Prv_Job.h"
#include "Fee_Prv_Lib.h"
#include "Fee_Prv_Medium.h"
#include "Fee_Prv_Order.h"
#include "Fee_Prv_Proc.h"
#include "Fee_Prv_Chunk.h"
#include "Fee_PrvTypes.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

# if(defined(FEE_PRV_CFG_RB_PERSIST_DATA) && (FALSE != FEE_PRV_CFG_RB_PERSIST_DATA))
#define FEE_START_SEC_VAR_CLEARED_8
#include "Fee_MemMap.h"
/* Static */
static uint8 Fee_Prv_OrderWriteBuf_au8[FEE_PRV_CFG_RB_PERSIST_DATA_SIZE];
#define FEE_STOP_SEC_VAR_CLEARED_8
#include "Fee_MemMap.h"
# endif

/*
 **********************************************************************************************************************
 * Local macro declaration
 **********************************************************************************************************************
 */
# if(defined(RBA_FEEFS2_PRV_CFG_ENABLED) && (RBA_FEEFS2_PRV_CFG_ENABLED != FALSE))
#define FEE_ORDER_VARLEN_AND_MIG_BLK_CFG_CHECK  (TRUE)  // The feature VarLength and Migration are supported only for Fee2
# else
#define FEE_ORDER_VARLEN_AND_MIG_BLK_CFG_CHECK  (FALSE)  // The feature VarLength and Migration is currently not supported only for Fee1x and Fee3
# endif
/*
 **********************************************************************************************************************
 * Static declaration
 **********************************************************************************************************************
 */

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

static Std_ReturnType Fee_Prv_OrderDetCheckBlkCfg          (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past);
# if((defined(FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API) && (FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API != FALSE)) || (defined(FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API) && (FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API != FALSE)))
static Std_ReturnType Fee_Prv_OrderDetCheckBlkLenNull      (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkLen_u16                 );
# endif
# if(FEE_ORDER_VARLEN_AND_MIG_BLK_CFG_CHECK != FALSE)
static Std_ReturnType Fee_Prv_OrderDetCheckBlkVarLenCfg    (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past);
static Std_ReturnType Fee_Prv_OrderDetCheckBlkMigrationCfg (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past);
# else
// To save ROM, remap to dummy functions when feature is not supported return check is fine
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckBlkVarLenCfg (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past);
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckBlkVarLenCfg (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past)
{
    (void)deviceName_en;
    (void)apiId_u8;
    (void)blkNr_u16;
    (void)active_b;
    (void)blockPropertiesTable_past;
    return (E_OK);
}
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckBlkMigrationCfg (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past);
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckBlkMigrationCfg (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past)
{
    (void)deviceName_en;
    (void)apiId_u8;
    (void)blkNr_u16;
    (void)active_b;
    (void)blockPropertiesTable_past;
    return (E_OK);
}
# endif
# if(defined(FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE) && (FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE != FALSE))
static Std_ReturnType Fee_Prv_OrderDetCheckJobModeParameters(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, Fee_Rb_JobType_ten jobType_en, Fee_Rb_JobMode_ten jobMode_en);
# endif

/*
 **********************************************************************************************************************
 * Inline declaration
 **********************************************************************************************************************
 */

# if(STD_ON == FEE_PRV_CFG_SET_MODE_SUPPORTED)
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckModuleIdle (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8);
# endif
LOCAL_INLINE void Fee_Prv_OrderDetModuleInitFail(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8);
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckBlkOfs(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, uint16 blkOfs_u16, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past);
# if(defined(FEE_PRV_CFG_RB_GET_NR_SECTOR_ERASES) && (FEE_PRV_CFG_RB_GET_NR_SECTOR_ERASES != FALSE))
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckSectIdx(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint8 physSectIdx_u8);
#endif
LOCAL_INLINE void Fee_Prv_OrderReadPersistentData(Fee_Rb_DeviceName_ten deviceName_en);
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
 */

/**
 * \brief   Check whether the Device name (or device index) matches with what is passed.
 *
 * \param   deviceName_en    Device instance for which check has to be performed
 * \param   apiId_u8         The API which requests this check, needed for Det_ReportError in case of failure
 *
 * \retval  E_OK             Device name does exist
 * \retval  E_NOT_OK         Device name does not exist
 */
Std_ReturnType Fee_Prv_OrderDetCheckDeviceName (Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8)
{
    Std_ReturnType result_en = E_OK;
    if(deviceName_en >= Fee_Rb_Device_Max)
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_DEVICE_NAME);
        result_en = E_NOT_OK;
    }

    return(result_en);
}
/**
 * \brief   Check whether the Fee is initialized (Fee_Init was called) and if driver is in Stop mode.
 *
 * \param   deviceName_en    Device instance for which check has to be performed
 * \param   apiId_u8         The API which requests this check, needed for Det_ReportError in case of failure
 *
 * \retval  E_OK             Fee is initialized and not in stop mode
 * \retval  E_NOT_OK         Fee is not initialized or in stop mode
 */
Std_ReturnType Fee_Prv_OrderDetCheckModuleInitAndStopMode(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8)
{
    Std_ReturnType result_en;
    if(MEMIF_UNINIT == Fee_Rb_Idx_GetStatus(deviceName_en))
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_UNINIT);
        result_en = E_NOT_OK;
    }
    else
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            result_en = E_OK;
        }
        else
# endif
        {
            if(Fee_Prv_ProcIsStopModeActive(deviceName_en))
            {
                result_en = E_NOT_OK;
            }
            else
            {
                result_en = E_OK;
            }
        }
    }

    return(result_en);
}

# if(STD_ON == FEE_PRV_CFG_SET_MODE_SUPPORTED)
/**
 * \brief   Check whether the Fee is currently idle
 *          - Fee_Init was called
 *          - No internal or external action is being processed
 *
 * \param   deviceName_en    Device instance for which check has to be performed
 * \param   apiId_u8         The API which requests this check, needed for Det_ReportError in case of failure
 *
 * \retval  E_OK             Fee_Rb_Idx_GetStatus(deviceName_en) returns MEMIF_IDLE
 * \retval  E_NOT_OK         Fee_Rb_Idx_GetStatus(deviceName_en) does not return MEMIF_IDLE
 */
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckModuleIdle(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8)
{
    Std_ReturnType result_en;
    MemIf_StatusType status_en;

    status_en = Fee_Rb_Idx_GetStatus(deviceName_en);
    /* if the driver is busy, a job is requested, but eventually the job is not yet started */
    if(
            /* MR12 RULE 13.5 VIOLATION: Only getter without side effects */
            ((MEMIF_BUSY_INTERNAL == status_en) || (MEMIF_BUSY == status_en)) &&
            (FEE_PRV_PROC_DRIVERSTATE_IDLE_E == Fee_Prv_ProcGetDriverState(deviceName_en))
    )
    {
        /* driver is initialised, a job is requested, but the driver is still idle
           -> actions for idle state will be performed, no error will be reported */
        status_en = MEMIF_IDLE;
    }

    switch(status_en)
    {
        case MEMIF_IDLE:
            /* driver is initialised
             * a job (Nvm, Adapter or Debug) may be requested but the driver is still idle */
            result_en = E_OK;
            break;

        case MEMIF_UNINIT:
            Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_UNINIT);
            result_en = E_NOT_OK;
            break;

        case MEMIF_BUSY_INTERNAL:
#  if(FEE_PRV_CFG_AR_RELEASE_MAJOR_VERSION == 4) && (FEE_PRV_CFG_AR_RELEASE_MINOR_VERSION >=4)
            /* From Autosar 4.4 and newer */
            result_en = E_OK;
#  else
            Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_BUSY_INTERNAL);
            result_en = E_NOT_OK;
#  endif
            break;

        case MEMIF_BUSY:
            Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_BUSY);
            result_en = E_NOT_OK;
            break;

        default:
            result_en = E_NOT_OK;
            break;
    }

    return(result_en);
}
# endif

# if(defined(FEE_PRV_CFG_RB_GET_NR_SECTOR_ERASES) && (FEE_PRV_CFG_RB_GET_NR_SECTOR_ERASES != FALSE))
/**
 * \brief   Check if sector index is valid.
 *
 * \param   deviceName_en               Device instance for which check has to be performed
 * \param   apiId_u8                    The API which requests this check, needed for Det_ReportError in case of failure
 * \param   physSectIdx_u8              The sector number that shall be checked
 *
 * \retval  E_OK                        The sector number is valid
 * \retval  E_NOT_OK                    The sector number is not valid
 */
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckSectIdx(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint8 physSectIdx_u8)
{
    Std_ReturnType result_en = E_OK;

    if(Fee_Prv_FsIfRbGetNrOfSectors(deviceName_en) <= physSectIdx_u8)
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_SECT_NR);
        result_en = E_NOT_OK;
    }
    return(result_en);
}
#endif

/**
 * \brief   Check whether the request is valid for the given block number.
 *
 * \param   deviceName_en               Device instance for which check has to be performed
 * \param   apiId_u8                    The API which requests this check, needed for Det_ReportError in case of failure
 * \param   blkNr_u16                   The block number that shall be checked
 * \param   blockPropertiesTable_past   Pointer to the block properties table
 *
 * \retval  E_OK                        The block config is valid
 * \retval  E_NOT_OK                    The block config is not valid
 */
static Std_ReturnType Fee_Prv_OrderDetCheckBlkCfg(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past)
{
    Std_ReturnType result_en = E_OK;
    if(Fee_Prv_FsIfGetNrOfBlocks(deviceName_en) <= blkNr_u16)
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_BLOCK_NO);
        result_en = E_NOT_OK;
    }
    else
    {
        if(FEE_SID_RB_MAINTAIN == apiId_u8)
        {
            if(!Fee_Prv_ConfigIsBlockDoubleStorageActiveByBlockNr(blkNr_u16, Fee_Prv_FsIfGetDoubleStorageBitmask(deviceName_en), blockPropertiesTable_past))
            {
                // reject Maintain orders for non-redundant copies
                Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_BLOCK_CFG);
                result_en = E_NOT_OK;
            }
        }
    }
    return(result_en);
}

/**
 * \brief   Check whether a pointer is a NULL_PTR.
 *
 * \param   deviceName_en    Device instance for which check has to be performed
 * \param   apiId_u8         The API which requests this check, needed for Det_ReportError in case of failure
 * \param   bfr_pcv          The pointer that shall be checked
 *
 * \retval  E_OK             The pointer is not a NULL_PTR
 * \retval  E_NOT_OK         The pointer is a NULL_PTR
 */
Std_ReturnType Fee_Prv_OrderDetCheckAdrPtr(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, void const * bfr_pcv)
{
    Std_ReturnType result_en = E_OK;
    if(NULL_PTR == bfr_pcv)
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_PARAM_POINTER);
        result_en = E_NOT_OK;
    }
    return(result_en);
}

/**
 * \brief   Check whether an offset is longer or equal the block length.
 *
 * \param   deviceName_en               Device instance for which check has to be performed
 * \param   apiId_u8                    The API which requests this check, needed for Det_ReportError in case of failure
 * \param   blkNr_u16                   The block number
 * \param   blkOfs_u16                  The offset that shall be checked
 * \param   blockPropertiesTable_past   Pointer to the block properties table
 *
 * \retval  E_OK                        The offset is smaller than the length of the block
 * \retval  E_NOT_OK                    The offset is longer or equal the length of the block
 */
LOCAL_INLINE Std_ReturnType Fee_Prv_OrderDetCheckBlkOfs(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, uint16 blkOfs_u16, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past)
{
    Std_ReturnType result_en = E_OK;
    if(blkOfs_u16 >= Fee_Prv_ConfigGetBlockLengthByBlockNr(blkNr_u16, blockPropertiesTable_past))
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_BLOCK_OFS);
        result_en = E_NOT_OK;
    }
    return(result_en);
}

/**
 * \brief   Check that length + offset do not exceed block length.
 *
 * \param   deviceName_en               Device instance for which check has to be performed
 * \param   apiId_u8                    The API which requests this check, needed for Det_ReportError in case of failure
 * \param   blkNr_u16                   The block number
 * \param   blkOfs_u16                  The offset
 * \param   blkLen_u16                  The requested length
 * \param   blockPropertiesTable_past   Pointer to the block properties table
 *
 * \retval  E_OK                        Offset + Length are bigger than the block length
 * \retval  E_NOT_OK                    Offset + Length are smaller or equal the block length
 */
Std_ReturnType Fee_Prv_OrderDetCheckBlkLen(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, uint16 blkOfs_u16, uint16 blkLen_u16, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past)
{
    Std_ReturnType result_en = E_OK;
    if((blkOfs_u16 + blkLen_u16) > Fee_Prv_ConfigGetBlockLengthByBlockNr(blkNr_u16, blockPropertiesTable_past))
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_BLOCK_LEN);
        result_en = E_NOT_OK;
    }
    return(result_en);
}

# if((defined(FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API) && (FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API != FALSE)) || (defined(FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API) && (FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API != FALSE)))
/**
 * \brief   Check that requested block length is not zero.
 *
 * \param   deviceName_en    Device instance for which check has to be performed
 * \param   apiId_u8         The API which requests this check, needed for Det_ReportError in case of failure
 * \param   blkNr_u16        The block number
 * \param   blkLen_u16       The requested length
 *
 * \retval  E_OK             Requested length is bigger than zero
 * \retval  E_NOT_OK         Requested length is zero
 */
static Std_ReturnType Fee_Prv_OrderDetCheckBlkLenNull(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkLen_u16)
{
    Std_ReturnType result_en = E_OK;
    if(0u == blkLen_u16)
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_BLOCK_LEN);
        result_en = E_NOT_OK;
    }
    return(result_en);
}
# endif

# if(FEE_ORDER_VARLEN_AND_MIG_BLK_CFG_CHECK != FALSE)
/**
 * \brief   Checks that requested block is configured for variable block length.
 *
 * \param   deviceName_en               Device instance for which check has to be performed
 * \param   apiId_u8                    The API which requests this check, needed for Det_ReportError in case of failure
 * \param   blkNr_u16                   The block number
 * \param   active_b                    Under which condition the det error should be set
 * \param   blockPropertiesTable_past   Pointer to the block properties table
 *
 * \retval  E_OK                        Block is configured for variable block length
 * \retval  E_NOT_OK                    Block is not configured for variable block length
 */
static Std_ReturnType Fee_Prv_OrderDetCheckBlkVarLenCfg(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past)
{
    Std_ReturnType result_en = E_OK;
    if(active_b != Fee_Prv_ConfigIsBlockLengthVariableByBlockNr(blkNr_u16, Fee_Prv_FsIfGetVarLenBitmask(deviceName_en), blockPropertiesTable_past))
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_VAR_BLK_LEN_CFG);
        result_en = E_NOT_OK;
    }
    return(result_en);
}

/**
 * \brief   Checks that requested block is configured for migration.
 *
 * \param   deviceName_en               Device instance for which check has to be performed
 * \param   apiId_u8                    The API which requests this check, needed for Det_ReportError in case of failure
 * \param   blkNr_u16                   The block number
 * \param   active_b                    Under which condition the det error should be set
 * \param   blockPropertiesTable_past   Pointer to the block properties table
 *
 * \retval  E_OK                        Block is configured for migration
 * \retval  E_NOT_OK                    Block is not configured for migration
 */
static Std_ReturnType Fee_Prv_OrderDetCheckBlkMigrationCfg(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, uint16 blkNr_u16, boolean active_b, const Fee_Rb_BlockPropertiesType_tst* blockPropertiesTable_past)
{
    Std_ReturnType result_en            = E_OK;
    uint16         persistentId_u16     = Fee_Prv_ConfigGetBlockPersistentIdByBlockNr(blkNr_u16, blockPropertiesTable_past);
    uint16         nrOfBlks_u16         = Fee_Prv_FsIfGetNrOfBlocks(deviceName_en);
    uint16         migrationBitmask_u16 = Fee_Prv_FsIfGetMigrationBitmask(deviceName_en);

    if(active_b != Fee_Prv_ConfigIsBlockMigrationActiveByPersistentId(persistentId_u16, nrOfBlks_u16, migrationBitmask_u16, blockPropertiesTable_past))
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_MIGRATION_CFG);
        result_en = E_NOT_OK;
    }
    return(result_en);
}
# endif

# if(defined(FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE) && (FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE != FALSE))
/*
 * \brief   Validates if the requested mode setting for the passed job type is allowed or not
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   apiId_u8         The API which requests this check, needed for Det_ReportError in case of failure
 * \param   jobType_en       Job type for which mode has to be set
 * \param   jobMode_en       Mode that is requested to be set for the passed job type
 *
 */
static Std_ReturnType Fee_Prv_OrderDetCheckJobModeParameters(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8, Fee_Rb_JobType_ten jobType_en, Fee_Rb_JobMode_ten jobMode_en)
{
    Std_ReturnType retVal_en;

    retVal_en = E_NOT_OK;

    // check if the job mode is supported by the file system or not
    if(Fee_Prv_FsIfIsJobModeSupported(deviceName_en, jobType_en, jobMode_en))
    {
        retVal_en = E_OK;
    }

    if(E_NOT_OK == retVal_en)
    {
        Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INVALID_JOB_MODE_REQUESTED);
    }

    return(retVal_en);
}
# endif

/**
 * \brief   Raise init fail error (Fee_init fails).
 *
 * \param   deviceName_en    Device instance for which check has to be performed
 * \param   apiId_u8         The API which requests this check, needed for Det_ReportError in case of failure
 *
 */
LOCAL_INLINE void Fee_Prv_OrderDetModuleInitFail(Fee_Rb_DeviceName_ten deviceName_en, uint8 apiId_u8)
{
    Fee_Prv_LibDetReport(deviceName_en, apiId_u8, FEE_E_INIT_FAILED);
}

/**
 * \brief   Returns if the passed DeviceIndex belongs to Fee or not. The function is required when multi instance of Fee is used
 *
 * \param   DeviceIndex_u8  Device index which has to be evaluated
 *
 * \retval  TRUE            Passed Device Index belongs to Fee
 * \retval  FALSE           Passed Device Index does not belong to Fee
 */
boolean Fee_Rb_IsThisDeviceIndexFee(uint8 DeviceIndex_u8)
{
    boolean isFeeDevice_b;

    if(Fee_Rb_Device_Max != Fee_Rb_GetDeviceNameFromDeviceIndex(DeviceIndex_u8))
    {
        isFeeDevice_b = TRUE;
    }
    else
    {
        isFeeDevice_b = FALSE;
    }

    return(isFeeDevice_b);
}

/**
 * \brief   Get the Device name from the configured FeeRbGeneralDeviceIndex. This DeviceID name is then used while
 * accessing the corresponding instance via the API Fee_Rb_Idx_.
 * When device index is not found, Fee_Rb_FeeDevice_Max is returned -> indicating that the device does not exist.
 *
 * \param   feeDeviceIdx_u8         Device index as configured in paramdef FeeRbGeneralDeviceIndex
 *
 * \retval  Fee_Rb_DeviceName_ten   DeviceID name corresponding to the passed DeviceIndex
 */

Fee_Rb_DeviceName_ten Fee_Rb_GetDeviceNameFromDeviceIndex(uint8 feeDeviceIdx_u8)
{
    return (Fee_Prv_ConfigGetDeviceNameFromDeviceIndex(feeDeviceIdx_u8));
}


/*
 * \brief   Initializes the Fee.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   ConfigPtr:       Reference to postbuild variant. Has to be NULL_PTR because the Fee is not postbuild selectable.
 */
/*MR12 RULE 8.13 VIOLATION: AR4.2 defines this function prototype with a non-constant pointer*/
void Fee_Rb_Idx_Init(Fee_Rb_DeviceName_ten deviceName_en, Fee_ConfigType const * ConfigPtr)
{
    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst;
# if(FEE_PRV_CFG_AR42_API_COMPLIANCE == STD_ON)
    (void)ConfigPtr;
# endif

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_INIT))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
#  if(FEE_PRV_CFG_AR42_API_COMPLIANCE == STD_ON)
            Fee_Init(ConfigPtr);
#  else
            Fee_Init();
#  endif
        }
        else
# endif
        {
            /* Reset all variables inside Fee common component */
            /* Get the pointer to config data model */
            deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

            Fee_Prv_DbgInit(deviceConfigTable_pcst);
            Fee_Prv_LibInit(deviceConfigTable_pcst);
            Fee_Prv_MediumInit(deviceConfigTable_pcst);
            Fee_Prv_JobInit(deviceConfigTable_pcst);
            Fee_Prv_ProcInit(deviceConfigTable_pcst);
            Fee_Prv_ChunkInit();

            /* Measure the filesystem init time */
            Fee_Prv_DbgWatchStart(deviceName_en, FEE_PRV_DBG_TIMER_INIT_E);

            Fee_Prv_ProcSetDriverState(deviceConfigTable_pcst, FEE_PRV_PROC_DRIVERSTATE_INIT_E);

            /* Do not limit the effort to spend in the init - full speed is required */
            Fee_Prv_LibUseEffortLimit(deviceName_en, FALSE);

            /*
             * Set the medium synchronous.
             * That means the flash is polled and Fls_MainFunction calls are triggered until flash jobs are finished.
             */
            Fee_Prv_MediumSetSync(deviceConfigTable_pcst, TRUE);

            /* Initialize the file system - this will take the most time */
            if(E_OK == Fee_Prv_FsIfInit(deviceConfigTable_pcst))
            {
                /* Finally set the driver state to IDLE */
                Fee_Prv_ProcSetDriverState(deviceConfigTable_pcst, FEE_PRV_PROC_DRIVERSTATE_IDLE_E);

                Fee_Prv_DbgWatchStop(deviceName_en, FEE_PRV_DBG_TIMER_INIT_E, FALSE);

                /* If enabled read the debug block */
                Fee_Prv_DbgBlockRead(deviceName_en);

                /* Read Fs specific persistent data */
                Fee_Prv_OrderReadPersistentData(deviceName_en);

                /* Disable sync mode operation */
                Fee_Prv_MediumSetSync(deviceConfigTable_pcst, FALSE);
            }
            else
            {
                /* Driver init was not successful --> uninit the Fee */
                Fee_Prv_ProcSetDriverState(deviceConfigTable_pcst, FEE_PRV_PROC_DRIVERSTATE_UNINIT_E);

                /* Report DET error */
                Fee_Prv_OrderDetModuleInitFail(deviceName_en, FEE_SID_INIT);
            }
        }
    }
    return;
}

/*
 * \brief   Mark end of the Fee init. After calling this function background activities are allowed.
 *          Also the Fee is set in a more cooperative mode to make sure task duration constraints are not violated.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 */
void Fee_Rb_Idx_EndInit(Fee_Rb_DeviceName_ten deviceName_en)
{
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_END_INIT))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            Fee_Rb_EndInit();
        }
        else
# endif
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_END_INIT))
            {
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                Fee_Prv_LibUseEffortLimit(deviceName_en, TRUE);
                Fee_Prv_ProcEnableBackground(deviceConfigTable_pcst);
            }
        }
    }
    return;
}

/**
 * \brief   Start a read job.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Blocknumber      Block number as generated in Fee.h - This is not the persistent ID!
 * \param   BlockOffset      The offset where the read shall start from in bytes
 * \param   DataBufferPtr    Buffer to read data to
 * \param   Length           Amount of data to read in bytes
 *
 * \retval  E_OK             Order accepted, will be executed asynchronously
 * \retval  E_NOT_OK         Order not accepted
 */
Std_ReturnType Fee_Rb_Idx_Read(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint16 BlockOffset, uint8 * DataBufferPtr, uint16 Length)
{
    Std_ReturnType result_en = E_OK;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_READ))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            result_en = Fee_Read(Blocknumber, BlockOffset, DataBufferPtr, Length);
        }
        else
# endif
        {
            if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode (deviceName_en, FEE_SID_READ))
            {
                result_en = E_NOT_OK;
            }
            /* MR12 DIR 1.1 VIOLATION: uint8 * can always be converted safely to void * */
            if(E_OK != Fee_Prv_OrderDetCheckAdrPtr(deviceName_en, FEE_SID_READ, (void const *)DataBufferPtr))
            {
                result_en = E_NOT_OK;
            }
            if(E_OK == Fee_Prv_OrderDetCheckBlkCfg(deviceName_en, FEE_SID_READ, Blocknumber, blockPropertiesTable_past))
            {
                if(E_OK != Fee_Prv_OrderDetCheckBlkOfs(deviceName_en, FEE_SID_READ, Blocknumber, BlockOffset, blockPropertiesTable_past))
                {
                    result_en = E_NOT_OK;
                }
                if(E_OK != Fee_Prv_OrderDetCheckBlkLen (deviceName_en, FEE_SID_READ, Blocknumber, BlockOffset, Length, blockPropertiesTable_past))
                {
                    result_en = E_NOT_OK;
                }
                if(E_OK != Fee_Prv_OrderDetCheckBlkMigrationCfg (deviceName_en, FEE_SID_READ, Blocknumber, FALSE, blockPropertiesTable_past))
                {
                    result_en = E_NOT_OK;
                }
            }
            else
            {
                result_en = E_NOT_OK;
            }

            if(E_OK == result_en)
            {
                Fee_Prv_JobDesc_tst jobDesc_st;
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /*
                 * Prepare order and try to place it.
                 * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
                 */
                jobDesc_st.type_en         = FEE_RB_JOBTYPE_READ_E;
                jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_READ_E);
                jobDesc_st.bfr_pu8         = DataBufferPtr;
                jobDesc_st.bfr_pcu8        = NULL_PTR;
                jobDesc_st.blockNumber_u16 = Blocknumber;
                jobDesc_st.length_u16      = Length;
                jobDesc_st.offset_u16      = BlockOffset;
                jobDesc_st.nrBytTot_u16    = 0u;
                jobDesc_st.cntrBytDone_u16 = 0u;
                jobDesc_st.idPers_u16      = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.statusFlag_u16  = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.isChunkJob_b    = FALSE;
                jobDesc_st.isUnknownBlk_b  = FALSE;

                result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_READ, &jobDesc_st);
            }
        }
    }
    else
    {
        result_en = E_NOT_OK;
    }

    return(result_en);
}

# if((defined(FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API) && (FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API != FALSE)) || (defined(FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API) && (FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API != FALSE)))
/**
 * \brief   Starts a read job when block length is variable and calculated on runtime.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Blocknumber      Block number as generated in Fee.h - This is not the persistent ID!
 * \param   BlockOffset      The offset where the read shall start from in bytes
 * \param   DataBufferPtr    Buffer to read data to
 * \param   Length           Amount of data to read in bytes
 *
 * \retval  E_OK             Order accepted, will be executed asynchronously
 * \retval  E_NOT_OK         Order not accepted
 */
Std_ReturnType Fee_Rb_Idx_VarLenRead(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint16 BlockOffset, uint8 * DataBufferPtr, uint16 Length)
{
    Std_ReturnType result_en = E_OK;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const* blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    /* Check parameters */
    if(E_OK != Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_VARLENREAD))
    {
        result_en = E_NOT_OK;
    }

    if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_VARLENREAD))
    {
        result_en = E_NOT_OK;
    }
    /* MR12 DIR 1.1 VIOLATION: uint8 * can always be converted safely to void * */
    if(E_OK != Fee_Prv_OrderDetCheckAdrPtr(deviceName_en, FEE_SID_RB_VARLENREAD, (void const *)DataBufferPtr))
    {
        result_en = E_NOT_OK;
    }
    if(E_OK != Fee_Prv_OrderDetCheckBlkLenNull(deviceName_en, FEE_SID_RB_VARLENREAD, Length))
    {
        result_en = E_NOT_OK;
    }

    if(E_OK == Fee_Prv_OrderDetCheckBlkCfg(deviceName_en, FEE_SID_RB_VARLENREAD, Blocknumber, blockPropertiesTable_past))
    {
        if(E_OK != Fee_Prv_OrderDetCheckBlkMigrationCfg (deviceName_en, FEE_SID_RB_VARLENREAD, Blocknumber, TRUE, blockPropertiesTable_past) )
        {
            result_en = E_NOT_OK;
        }
    }
    else
    {
        result_en = E_NOT_OK;
    }

    if(E_OK == result_en)
    {
        Fee_Prv_JobDesc_tst jobDesc_st;
        /* Get the pointer to config data model */
        Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

        /*
         * Prepare order and try to place it.
         * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
         */
        jobDesc_st.type_en         = FEE_RB_JOBTYPE_READ_E;
        jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_READ_E);
        jobDesc_st.bfr_pu8         = DataBufferPtr;
        jobDesc_st.bfr_pcu8        = NULL_PTR;
        jobDesc_st.blockNumber_u16 = Blocknumber;
        jobDesc_st.length_u16      = Length;
        jobDesc_st.offset_u16      = BlockOffset;
        jobDesc_st.nrBytTot_u16    = 0u;
        jobDesc_st.cntrBytDone_u16 = 0u;
        jobDesc_st.idPers_u16      = 0u;    // dummy value. correct value to be picked up by FeeFsx
        jobDesc_st.statusFlag_u16  = 0u;    // dummy value. correct value to be picked up by FeeFsx
        jobDesc_st.isChunkJob_b    = FALSE;
        jobDesc_st.isUnknownBlk_b  = FALSE;

        result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_RB_VARLENREAD, &jobDesc_st);
    }

    return(result_en);
}
# endif

/**
 * \brief   Start a write job.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Blocknumber      Block number as generated in Fee.h - This is not the persistent ID!
 * \param   DataBufferPtr    Buffer to write data from
 *
 * \retval  E_OK             Order accepted, will be executed asynchronously
 * \retval  E_NOT_OK         Order not accepted
 */
/* MR12 RULE 8.13 VIOLATION: DataBufferPtr is not const because it is also not const in the public header file */
Std_ReturnType Fee_Rb_Idx_Write(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint8 * DataBufferPtr)
{
    Std_ReturnType result_en = E_OK;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_WRITE))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            result_en = Fee_Write(Blocknumber, DataBufferPtr);
        }
        else
# endif
        {
            if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode    (deviceName_en, FEE_SID_WRITE)) { result_en = E_NOT_OK; }
            /* MR12 DIR 1.1 VIOLATION: uint8 * can always be converted safely to void * */
            if(E_OK != Fee_Prv_OrderDetCheckAdrPtr        (deviceName_en, FEE_SID_WRITE, (void const *)DataBufferPtr))
            {
                result_en = E_NOT_OK;
            }

            if(E_OK == Fee_Prv_OrderDetCheckBlkCfg(deviceName_en, FEE_SID_WRITE, Blocknumber, blockPropertiesTable_past))
            {
                if(E_OK != Fee_Prv_OrderDetCheckBlkVarLenCfg  (deviceName_en, FEE_SID_WRITE, Blocknumber, FALSE, blockPropertiesTable_past))
                {
                    result_en = E_NOT_OK;
                }
            }
            else
            {
                result_en = E_NOT_OK;
            }

            if(E_OK == result_en)
            {
                Fee_Prv_JobDesc_tst jobDesc_st;
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /*
                 * Prepare order and try to place it.
                 * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
                 */
                jobDesc_st.type_en         = FEE_RB_JOBTYPE_WRITE_E;
                jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_WRITE_E);
                jobDesc_st.bfr_pu8         = NULL_PTR;
                jobDesc_st.bfr_pcu8        = DataBufferPtr;
                jobDesc_st.blockNumber_u16 = Blocknumber;
                jobDesc_st.length_u16      = Fee_Prv_ConfigGetBlockLengthByBlockNr(Blocknumber, blockPropertiesTable_past);
                jobDesc_st.offset_u16      = 0u;
                jobDesc_st.nrBytTot_u16    = 0u;
                jobDesc_st.cntrBytDone_u16 = 0u;
                jobDesc_st.idPers_u16      = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.statusFlag_u16  = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.isChunkJob_b    = FALSE;
                jobDesc_st.isUnknownBlk_b  = FALSE;

                result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_WRITE, &jobDesc_st);
            }
        }
    }
    else
    {
        result_en = E_NOT_OK;
    }

    return(result_en);
}

# if(defined(FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API) && (FEE_PRV_CFG_RB_VAR_LEN_READ_WRITE_API != FALSE))
/**
 * \brief   Starts a write job when block length is variable and calculated on runtime.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Blocknumber      Block number as generated in Fee.h - This is not the persistent ID!
 * \param   DataBufferPtr    Buffer to write data from
 * \param   Length           NV block length
 *
 * \retval  E_OK             Order accepted, will be executed asynchronously
 * \retval  E_NOT_OK         Order not accepted
 */
/* MR12 RULE 8.13 VIOLATION: DataBufferPtr is not const because it is also not const in the public header file */
Std_ReturnType Fee_Rb_Idx_VarLenWrite(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber, uint8 * DataBufferPtr, uint16 Length)
{
    Std_ReturnType result_en = E_OK;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    /* Check parameters */
    if(E_OK != Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_VARLENWRITE))
    {
        result_en = E_NOT_OK;
    }
    if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode    (deviceName_en, FEE_SID_RB_VARLENWRITE))
    {
        result_en = E_NOT_OK;
    }
    /* MR12 DIR 1.1 VIOLATION: uint8 * can always be converted safely to void * */
    if(E_OK != Fee_Prv_OrderDetCheckAdrPtr        (deviceName_en, FEE_SID_RB_VARLENWRITE, (void const *)DataBufferPtr)    )
    {
        result_en = E_NOT_OK;
    }
    if(E_OK != Fee_Prv_OrderDetCheckBlkLenNull    (deviceName_en, FEE_SID_RB_VARLENWRITE, Length))
    {
        result_en = E_NOT_OK;
    }

    if(E_OK == Fee_Prv_OrderDetCheckBlkCfg(deviceName_en, FEE_SID_RB_VARLENWRITE, Blocknumber, blockPropertiesTable_past))
    {
        if(E_OK != Fee_Prv_OrderDetCheckBlkVarLenCfg  (deviceName_en, FEE_SID_RB_VARLENWRITE, Blocknumber, TRUE, blockPropertiesTable_past))
        {
            result_en = E_NOT_OK;
        }
    }
    else
    {
        result_en = E_NOT_OK;
    }

    if(E_OK == result_en)
    {
        Fee_Prv_JobDesc_tst jobDesc_st;
        /* Get the pointer to config data model */
        Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

        /*
         * Prepare order and try to place it.
         * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
         */
        jobDesc_st.type_en         = FEE_RB_JOBTYPE_WRITE_E;
        jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_WRITE_E);
        jobDesc_st.bfr_pu8         = NULL_PTR;
        jobDesc_st.bfr_pcu8        = DataBufferPtr;
        jobDesc_st.blockNumber_u16 = Blocknumber;
        jobDesc_st.length_u16      = Length;
        jobDesc_st.offset_u16      = 0u;
        jobDesc_st.nrBytTot_u16    = 0u;
        jobDesc_st.cntrBytDone_u16 = 0u;
        jobDesc_st.idPers_u16      = 0u;    // dummy value. correct value to be picked up by FeeFsx
        jobDesc_st.statusFlag_u16  = 0u;    // dummy value. correct value to be picked up by FeeFsx
        jobDesc_st.isChunkJob_b    = FALSE;
        jobDesc_st.isUnknownBlk_b  = FALSE;

        result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_RB_VARLENWRITE, &jobDesc_st);
    }

    return(result_en);
}
# endif

/**
 * \brief   Start an invalidate job.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Blocknumber      Block number as generated in Fee.h - This is not the persistent ID!
 *
 * \retval  E_OK             Order accepted, will be executed asynchronously
 * \retval  E_NOT_OK         Order not accepted
 */
Std_ReturnType Fee_Rb_Idx_InvalidateBlock(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber)
{
    Std_ReturnType result_en = E_OK;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_INVALIDATE))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            result_en = Fee_InvalidateBlock(Blocknumber);
        }
        else
# endif
        {
            if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode (deviceName_en, FEE_SID_INVALIDATE))
            {
                result_en = E_NOT_OK;
            }
            if(E_OK != Fee_Prv_OrderDetCheckBlkCfg (deviceName_en, FEE_SID_INVALIDATE, Blocknumber, blockPropertiesTable_past))
            {
                result_en = E_NOT_OK;
            }

            if(E_OK == result_en)
            {
                Fee_Prv_JobDesc_tst jobDesc_st;
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /*
                 * Prepare order and try to place it.
                 * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
                 */
                jobDesc_st.type_en         = FEE_RB_JOBTYPE_INVALIDATE_E;
                jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_INVALIDATE_E);
                jobDesc_st.bfr_pu8         = NULL_PTR;
                jobDesc_st.bfr_pcu8        = NULL_PTR;
                jobDesc_st.blockNumber_u16 = Blocknumber;
                jobDesc_st.length_u16      = 0u;
                jobDesc_st.offset_u16      = 0u;
                jobDesc_st.nrBytTot_u16    = 0u;
                jobDesc_st.cntrBytDone_u16 = 0u;
                jobDesc_st.idPers_u16      = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.statusFlag_u16  = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.isChunkJob_b    = FALSE;
                jobDesc_st.isUnknownBlk_b  = FALSE;

                result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_INVALIDATE, &jobDesc_st);
            }
        }
    }
    else
    {
        result_en = E_NOT_OK;
    }

    return(result_en);
}

/**
 * \brief   Erase immediate data.
 *
 * \param   Blocknumber      Block number as generated in Fee.h - This is not the persistent ID!
 * \param   deviceName_en    Device instance for which job has to be performed
 *
 * \retval  E_OK             Order accepted, will be executed asynchronously
 * \retval  E_NOT_OK         Order not accepted
 *
 * \attention   Currently not supported!
 */
Std_ReturnType Fee_Rb_Idx_EraseImmediateBlock(Fee_Rb_DeviceName_ten deviceName_en, uint16 BlockNumber)
{
    (void)deviceName_en;
    (void)BlockNumber;
    return(E_NOT_OK);
}

/**
 * \brief   Cancel running operation.
 * \param   deviceName_en    Device instance for which job has to be performed
 *
 * \attention   Currently not supported!
 */
void Fee_Rb_Idx_Cancel(Fee_Rb_DeviceName_ten deviceName_en)
{
    (void)deviceName_en;
    return;
}

/**
 * \brief   Get the status of the Fee module.
 *
 * \param   deviceName_en       Device instance for which Fee status has to be returned
 *
 * \retval  MEMIF_UNINIT        The Fee_Init was not called yet
 * \retval  MEMIF_IDLE          The Fee_Init was called, NvM and adapter slots are free, no background operation running
 * \retval  MEMIF_BUSY_INTERNAL a) Adapter job is running
 *                              b) Background operation (maybe erase) is running
 *                              c) Fee_Init is running
 * \retval  MEMIF_BUSY          NvM order is running
 */
MemIf_StatusType Fee_Rb_Idx_GetStatus(Fee_Rb_DeviceName_ten deviceName_en)
{
    MemIf_StatusType                    result_en = MEMIF_UNINIT;
    Fee_Prv_ProcDriverState_ten         driverState_en;
    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_GETSTATUS))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            result_en = Fee_GetStatus();
        }
        else
# endif
        {
            driverState_en = Fee_Prv_ProcGetDriverState(deviceName_en);

            /* Get the pointer to config data model */
            deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

            if(FEE_PRV_PROC_DRIVERSTATE_INIT_E < driverState_en)
            {
                result_en = MEMIF_IDLE;
                if(FEE_RB_JOBTYPE_MAX_E != Fee_Prv_JobGetActvType(deviceConfigTable_pcst, FEE_PRV_REQUESTER_NVM_E))
                {
                    result_en = MEMIF_BUSY;
                }
                /* MR12 RULE 13.5 VIOLATION: Only getter without side effects */
                else if((FEE_RB_JOBTYPE_MAX_E != Fee_Prv_JobGetActvType(deviceConfigTable_pcst, FEE_PRV_REQUESTER_ADAPTER_E)) ||
                        (FEE_RB_JOBTYPE_MAX_E != Fee_Prv_JobGetActvType(deviceConfigTable_pcst, FEE_PRV_REQUESTER_DEBUG_E)))
                {
                    result_en = MEMIF_BUSY_INTERNAL;
                }
                else if(FEE_PRV_PROC_DRIVERSTATE_BACKGROUND_E == driverState_en)
                {
                    result_en = MEMIF_BUSY_INTERNAL;
                }
                else
                {
                    /* intentionally empty */
                }
            }
            else if(FEE_PRV_PROC_DRIVERSTATE_INIT_E == driverState_en)
            {
                result_en = MEMIF_BUSY_INTERNAL;
            }
            else
            {
                /* intentionally empty */
            }
        }
    }
    else
    {
        result_en = MEMIF_IDLE;
    }

    return(result_en);
}

/**
 * \brief   Return the result of the last NvM order.
 *
 * \param   deviceName_en               Device instance for which job result has to be returned
 *
 * \retval  MEMIF_JOB_OK                Last job executed successfully
 * \retval  MEMIF_JOB_FAILED            Last job failed unexpected
 * \retval  MEMIF_JOB_PENDING           Last job is still running
 * \retval  MEMIF_BLOCK_INCONSISTENT    Last job was a read and
 *                                      a) Not a single instance of all instances has consistent data
 *                                      b) The block is not present at all
 * \retval  MEMIF_BLOCK_INVALIDATED     Last job was a read and the block was invalidated intentionally
 *
 * \attention   Since the job result can change asynchronously a time consuming spin lock is needed!
 *              Please consider this when creating do/while wait loops for the Fee.
 */
MemIf_JobResultType Fee_Rb_Idx_GetJobResult(Fee_Rb_DeviceName_ten deviceName_en)
{
    MemIf_JobResultType result_en;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_GETJOBRESULT))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            result_en = Fee_GetJobResult();
        }
        else
# endif
        {
            if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_GETJOBRESULT))
            {
                result_en = MEMIF_JOB_FAILED;
            }
            else
            {
                result_en = Fee_Prv_JobGetResult(deviceName_en, FEE_PRV_REQUESTER_NVM_E);
            }
        }
    }
    else
    {
        result_en = MEMIF_JOB_FAILED;
    }

    return(result_en);
}

/**
 * \brief   Return the result of the last Adapter order.
 *
 * \param   deviceName_en               Device instance for which job result has to be returned
 *
 * \retval  MEMIF_JOB_OK                Last job executed successfully
 * \retval  MEMIF_JOB_FAILED            Last job failed unexpected
 * \retval  MEMIF_JOB_PENDING           Last job is still running
 * \retval  MEMIF_BLOCK_INCONSISTENT    Last job was a read and
 *                                      a) Not a single instance of all instances has consistent data
 *                                      b) The block is not present at all
 * \retval  MEMIF_BLOCK_INVALIDATED     Last job was a read and the block was invalidated intentionally
 */
MemIf_JobResultType Fee_Rb_Idx_GetAdapterJobResult(Fee_Rb_DeviceName_ten deviceName_en)
{
    MemIf_JobResultType result_en;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_ADAPTERGETJOBRESULT))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            result_en = Fee_Rb_GetAdapterJobResult();
        }
        else
# endif
        {
            /* Deviation: Not calling Fee_Prv_OrderDetCheckModuleInitAndStopMode() here */
            /* Reason:
             * 1. The deviation is done because GetAdapterJobResult() is called to return the status of previous
             * Stop mode request. So it is important that this request continues to work even when driver is stop mode.
             * 2. When Fee_Rb_Idx_GetAdapterJobResult() is called in wrong order, driver might be in
             * UNINIT state: In UNINIT it is not safe to call Fee_Prv_ProcIsStopModeActive(),
             * because when checking for stopmode, variable stopModeActive_b containing the stop mode info
             * might be still uninitialized - this can lead to unforseen behavior.
             * We need to give latest job result also if we are are in stop mode here.
             */
            if(MEMIF_UNINIT == Fee_Rb_Idx_GetStatus(deviceName_en))
            {
                Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_ADAPTERGETJOBRESULT, FEE_E_UNINIT);
                result_en = MEMIF_JOB_FAILED;
            }
            else {
                result_en = Fee_Prv_JobGetResult(deviceName_en, FEE_PRV_REQUESTER_ADAPTER_E);
            }
        }
    }
    else
    {
        result_en = MEMIF_JOB_FAILED;
    }
    return(result_en);
}


/**
 * \brief   Return the result of the last internal order.
 *
 * \param   deviceName_en               Device instance for which job result has to be returned
 *
 * \retval  MEMIF_JOB_OK                Last job executed successfully
 * \retval  MEMIF_JOB_FAILED            Last job failed unexpected
 * \retval  MEMIF_JOB_PENDING           Last job is still running
 * \retval  MEMIF_BLOCK_INCONSISTENT    Last job was a read and
 *                                      a) Not a single instance of all instances has consistent data
 *                                      b) The block is not present at all
 * \retval  MEMIF_BLOCK_INVALIDATED     Last job was a read and the block was invalidated intentionally
 */
MemIf_JobResultType Fee_Rb_Idx_GetInternalJobResult(Fee_Rb_DeviceName_ten deviceName_en)
{
    MemIf_JobResultType result_en;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_INTERNAL_GETJOBRESULT))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            /* not required for Fs1.0 */
            result_en = MEMIF_JOB_FAILED;
        }
        else
# endif
        {
            if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_INTERNAL_GETJOBRESULT))
            {
                result_en = MEMIF_JOB_FAILED;
            }
            else
            {
                result_en = Fee_Prv_JobGetResult(deviceName_en, FEE_PRV_REQUESTER_DEBUG_E);
            }
        }
    }
    else
    {
        result_en = MEMIF_JOB_FAILED;
    }
    return(result_en);
}

# if(defined(FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API) && (FEE_PRV_CFG_RB_GET_FIRST_READ_DATA_MIGRATION_API != FALSE))
/**
 * \brief   Returns the migration result of data reading during initialisation
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Blocknumber      Block number as generated in Fee.h
 *
 * \retval  MEMIF_RB_MIGRATION_RESULT_INIT_E               Initialization value, result not yet available
 * \retval  MEMIF_RB_MIGRATION_RESULT_NOT_NECESSARY_E      RAM size == EEPROM size (migration not necessary)
 * \retval  MEMIF_RB_MIGRATION_RESULT_TO_SMALLER_SIZE_E    RAM size < EEPROM size (remaining data discarded)
 * \retval  MEMIF_RB_MIGRATION_RESULT_TO_BIGGER_SIZE_E     RAM size > EEPROM size (remaining data filled with zero)
 * \retval  MEMIF_RB_MIGRATION_RESULT_NOT_DONE_E           Migration not done, because data were not read
 * \retval  MEMIF_RB_MIGRATION_RESULT_DEACTIVATED_E        Migrations is deactivated by configuration
 */
MemIf_Rb_MigrationResult_ten Fee_Rb_Idx_GetMigrationResult(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber)
{
    MemIf_Rb_MigrationResult_ten result_en;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GETMIGRATIONRESULT))
    {
        result_en = MEMIF_RB_MIGRATION_RESULT_INIT_E;
    }
    if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GETMIGRATIONRESULT))
    {
        result_en = MEMIF_RB_MIGRATION_RESULT_INIT_E;
    }
    else if(E_OK != Fee_Prv_OrderDetCheckBlkCfg(deviceName_en, FEE_SID_RB_GETMIGRATIONRESULT, Blocknumber, blockPropertiesTable_past))
    {
        result_en = MEMIF_RB_MIGRATION_RESULT_INIT_E;
    }
    else
    {
        result_en = Fee_Prv_FsIfRbGetMigrationResultForBlockNr(deviceName_en, Blocknumber);
    }

    return(result_en);
}
# endif

# if(defined(FEE_PRV_CFG_RB_DETAILED_BLK_INFO_API) && (FEE_PRV_CFG_RB_DETAILED_BLK_INFO_API != FALSE))
/**
 * \brief   Returns the detailed block info in case of block inconsistency
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   blkNr_u16  Block number as generated in Fee.h
 *
 * \retval  MEMIF_RB_DETAILED_BLK_INFO_NOT_AVAILABLE_E          Detailed block information not supported
 * \retval  MEMIF_RB_DETAILED_BLK_INFO_INIT_E                   Block was never read inconsistent - result not available OR wrong parameters OR Fee in UNINIT state
 * \retval  MEMIF_RB_DETAILED_BLK_INFO_INCONSISTENT_MISSING_E   MEMIF_BLOCK_INCONSISTENT: Valid block (header) was not found on the medium
 * \retval  MEMIF_RB_DETAILED_BLK_INFO_INCONSISTENT_DATA_E      MEMIF_BLOCK_INCONSISTENT: Data CRC of block is wrong
 */
MemIf_Rb_DetailedBlkInfo_ten Fee_Rb_Idx_GetDetailedBlkInfo(Fee_Rb_DeviceName_ten deviceName_en, uint16 blkNr_u16)
{
    MemIf_Rb_DetailedBlkInfo_ten result_en = MEMIF_RB_DETAILED_BLK_INFO_INIT_E;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GETDETAILEDBLKINFO))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            /* Not supported by Fs1 */
            result_en = MEMIF_RB_DETAILED_BLK_INFO_NOT_AVAILABLE_E;
        }
        else
# endif
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GETDETAILEDBLKINFO))
            {
                if(E_OK == Fee_Prv_OrderDetCheckBlkCfg(deviceName_en, FEE_SID_RB_GETDETAILEDBLKINFO, blkNr_u16, blockPropertiesTable_past))
                {
                    result_en = Fee_Prv_FsIfRbGetDetailedBlkInfo(deviceName_en, blkNr_u16);
                }
            }
        }
    }

    return(result_en);
}
# endif

/**
 * \brief   Set the mode of the Fee and the underlying flash driver.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Mode             New mode
 */
# if(defined(FEE_PRV_CFG_SET_MODE_SUPPORTED) && (FEE_PRV_CFG_SET_MODE_SUPPORTED != FALSE))
void Fee_Rb_Idx_SetMode(Fee_Rb_DeviceName_ten deviceName_en, MemIf_ModeType Mode)
{
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_SETMODE))
    {
#  if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1_PRV_CFG_ENABLED)) && \
        (defined(FEE_PRV_CFG_SET_MODE_API_FS1) && (STD_ON == FEE_PRV_CFG_SET_MODE_API_FS1))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            Fee_SetMode(Mode);
        }
        else
#  endif
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleIdle(deviceName_en, FEE_SID_SETMODE))
            {
                if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_SETMODE))
                {
                    /* Get the pointer to config data model */
                    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

#  if(FEE_PRV_CFG_AR_RELEASE_MAJOR_VERSION == 4) && (FEE_PRV_CFG_AR_RELEASE_MINOR_VERSION >= 4)
                    Fee_Prv_ProcSetDriverModeReq(deviceConfigTable_pcst, Mode);
#  else
                    /* Fee is still idle, so set the driver mode */
                    Fee_Prv_ProcSetDriverMode(deviceConfigTable_pcst, Mode);
# endif
                }
            }
        }
    }
}
# endif

/**
 * \brief   Get the mode of the Fee driver.
 *          In case of an error or if Fee is still uninitialized,
 *          the default value MEMIF_MODE_SLOW is returned.
 *
 * \param   deviceName_en    Device instance for which the mode shall be returned
 */

/* GetMode API is only useful, if also the SetMode API is available. Otherwise default mode is MEMIF_MODE_SLOW
 * To reduce configuration complexity, both functions are enabled/disabled by the SET_MODE macro */
# if(defined(FEE_PRV_CFG_SET_MODE_SUPPORTED) && (FEE_PRV_CFG_SET_MODE_SUPPORTED != FALSE))
MemIf_ModeType Fee_Rb_Idx_GetMode(Fee_Rb_DeviceName_ten deviceName_en)
{
    MemIf_ModeType retVal_en;

    retVal_en = MEMIF_MODE_SLOW;

    /* In Fs1 Fee_Rb_GetMode may be activated by setting FeeSetModeSupported = true
       Call of Fee_Prv_ProcGetDriverMode would lead to a null pointer access
       -> Only call Fee_Prv_ProcGetDriverMode if instance is not Fs1 (Fee_Rb_DeviceName) */
#  if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED)) && \
     (defined(FEE_PRV_CFG_SET_MODE_API_FS1) && (FEE_PRV_CFG_SET_MODE_API_FS1 != STD_OFF))
    if(Fee_Rb_DeviceName != deviceName_en)
#  endif
    {
        if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GETMODE))
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GETMODE))
            {
                retVal_en = Fee_Prv_ProcGetDriverMode(deviceName_en);
            }
        }
    }

    return retVal_en;
}
# endif

# if(defined(FEE_PRV_CFG_VERSION_INFO_API) && (FEE_PRV_CFG_VERSION_INFO_API != FALSE))
/**
 * \brief   Get version information about this Fee.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   VersionInfoPtr   Pointer to a standard version struct that shall be filled
 */
void Fee_Rb_Idx_GetVersionInfo(Fee_Rb_DeviceName_ten deviceName_en, Std_VersionInfoType * VersionInfoPtr)
{
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_GETVERSIONINFO))
    {
#  if((defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1_PRV_CFG_ENABLED)) && \
        (defined(FEE_PRV_CFG_VERSION_INFO_API_FS1) && (STD_ON == FEE_PRV_CFG_VERSION_INFO_API_FS1)))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            Fee_GetVersionInfo(VersionInfoPtr);
        }
        else
#  endif
        {
            /* MR12 DIR 1.1 VIOLATION: uint8 * can always be converted safely to void * */
            if(E_OK != Fee_Prv_OrderDetCheckAdrPtr(deviceName_en, FEE_SID_GETVERSIONINFO, (void const *)VersionInfoPtr))
            {
                /* Do nothing */
            }
            else
            {
                VersionInfoPtr->vendorID            = FEE_PRV_CFG_VENDOR_ID;
                VersionInfoPtr->moduleID            = FEE_PRV_CFG_MODULE_ID;
                VersionInfoPtr->sw_major_version    = FEE_PRV_CFG_SW_MAJOR_VERSION;
                VersionInfoPtr->sw_minor_version    = FEE_PRV_CFG_SW_MINOR_VERSION;
                VersionInfoPtr->sw_patch_version    = FEE_PRV_CFG_SW_PATCH_VERSION;
            }
        }
    }
}
# endif

# if(defined(FEE_PRV_CFG_RB_MAINTAIN) && (FEE_PRV_CFG_RB_MAINTAIN != FALSE))
/**
 * \brief   Make sure that the double storage of a specified block number is intact.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   Blocknumber      The block number as defined in Fee.h - This is not the persistent ID!
 *
 * \attention This API is currently not supported by all Fee file systems
 *            For an unsupported job, the job result will be set to failed during the job processing.
 */
Std_ReturnType Fee_Rb_Idx_BlockMaintenance(Fee_Rb_DeviceName_ten deviceName_en, uint16 Blocknumber)
{
    Std_ReturnType result_en = E_OK;
    // get the block pointer to the block properties table for the validaiton checks
    Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_MAINTAIN))
    {
#  if((defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED)) && \
        (defined(FEE_PRV_CFG_MAINTAIN_FS1) && (FEE_PRV_CFG_MAINTAIN_FS1 != FALSE)))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            // This request is for device index = 0, this means route this request to Fee1.0
            result_en = Fee_Rb_BlockMaintenance(Blocknumber);
        }
        else
#  endif
        {
            if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode (deviceName_en, FEE_SID_RB_MAINTAIN)             ) { result_en = E_NOT_OK; }
            if(E_OK != Fee_Prv_OrderDetCheckBlkCfg     (deviceName_en, FEE_SID_RB_MAINTAIN, Blocknumber, blockPropertiesTable_past)) { result_en = E_NOT_OK; }

            if(E_OK == result_en)
            {
                Fee_Prv_JobDesc_tst jobDesc_st;
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /*
                 * Prepare order and try to place it.
                 * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
                 */
                jobDesc_st.type_en         = FEE_RB_JOBTYPE_BLOCKMAINTENANCE_E;
                jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_BLOCKMAINTENANCE_E);
                jobDesc_st.bfr_pu8         = NULL_PTR;
                jobDesc_st.bfr_pcu8        = NULL_PTR;
                jobDesc_st.blockNumber_u16 = Blocknumber;
                jobDesc_st.length_u16      = Fee_Prv_ConfigGetBlockLengthByBlockNr(Blocknumber, blockPropertiesTable_past);
                jobDesc_st.offset_u16      = 0u;
                jobDesc_st.nrBytTot_u16    = 0u;
                jobDesc_st.cntrBytDone_u16 = 0u;
                jobDesc_st.idPers_u16      = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.statusFlag_u16  = 0u;    // dummy value. correct value to be picked up by FeeFsx
                jobDesc_st.isChunkJob_b    = FALSE;
                jobDesc_st.isUnknownBlk_b  = FALSE;

                result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_RB_MAINTAIN, &jobDesc_st);
            }
        }
    }
    else
    {
        result_en = E_NOT_OK;
    }

    return(result_en);
}
# endif

/**
 * \brief The function when called disables execution of background operations.
 *
 * Note: It does neither suspend nor stop the already ongoing background task but prevents further background operations
 * getting scheduled, i.e.:
 * If a sector reorganization operation has started and one job is currently being transferred,
 *    then the current block operation will be completed and next block will not be transferred.
 * If an erase is ongoing, then it will wait for the erase to
 *    be completed and next background operation will not be started.
 *
 * Background tasks could be resumed again by calling the API Fee_Rb_EnableBackgroundOperation()
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 */
void Fee_Rb_Idx_DisableBackgroundOperation(Fee_Rb_DeviceName_ten deviceName_en)
{
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_DISABLE_BG))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            Fee_Rb_DisableBackgroundOperation();
        }
        else
# endif
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_DISABLE_BG))
            {
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
                Fee_Prv_ProcDisableBackground(deviceConfigTable_pcst);
            }
        }
    }
}

/**
 * \brief The function when called enables execution of background operations.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 */
void Fee_Rb_Idx_EnableBackgroundOperation(Fee_Rb_DeviceName_ten deviceName_en)
{
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_ENABLE_BG))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            Fee_Rb_EnableBackgroundOperation();
        }
        else
# endif
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_ENABLE_BG))
            {
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const*   deviceConfigTable_pcst   = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
                Fee_Prv_ProcEnableBackground(deviceConfigTable_pcst);
            }
        }
    }
}

# if(defined(FEE_PRV_CFG_RB_TRIGGER_REORG) && (FEE_PRV_CFG_RB_TRIGGER_REORG != FALSE))
/**
 * \brief The function when called triggers one forced reorganisation.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 *
 * \return Job accepted?
 * \retval E_OK  job is accepted
 * \retval E_NOT_OK job is rejected
 */
Std_ReturnType Fee_Rb_Idx_TriggerReorg(Fee_Rb_DeviceName_ten deviceName_en)
{
    Std_ReturnType result_en = E_NOT_OK;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_TRIGGER_REORG))
    {
#  if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED)) && \
        (defined(FEE_PRV_CFG_TRIGGER_REORG_FS1) && (FEE_PRV_CFG_TRIGGER_REORG_FS1 != FALSE))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            // This request is for device index = 0, this means route this request to Fee1.0
            result_en = Fee_Rb_TriggerReorg();
        }
        else
#  endif
        {
            result_en = Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_TRIGGER_REORG);

            if(E_OK == result_en)
            {
                Fee_Prv_JobDesc_tst jobDesc_st;
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /*
                 * Prepare order and try to place it.
                 * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
                 */
                jobDesc_st.type_en         = FEE_RB_JOBTYPE_TRIGGERREORG_E;
                jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_TRIGGERREORG_E);
                jobDesc_st.bfr_pu8         = NULL_PTR;
                jobDesc_st.bfr_pcu8        = NULL_PTR;
                jobDesc_st.blockNumber_u16 = FEE_PRV_MAX_UINT16;
                jobDesc_st.length_u16      = 0u;
                jobDesc_st.offset_u16      = 0u;
                jobDesc_st.nrBytTot_u16    = 0u;
                jobDesc_st.cntrBytDone_u16 = 0u;
                jobDesc_st.idPers_u16      = 0u;
                jobDesc_st.statusFlag_u16  = 0u;
                jobDesc_st.isChunkJob_b    = FALSE;
                jobDesc_st.isUnknownBlk_b  = FALSE;

                result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_RB_TRIGGER_REORG, &jobDesc_st);
            }
        }
    }

    return(result_en);
}
# endif

# if(defined(FEE_PRV_CFG_RB_ENTER_STOP_MODE) && (FEE_PRV_CFG_RB_ENTER_STOP_MODE != FALSE))
/**
 * \brief The function puts the request for putting the Fee in stop mode at next possible synchronization point.
 * The ongoing job gets completed and only after that Fee would be put to stop mode and no jobs would be executed in
 * this drive cycle.
 *
 * \attention As soon as the Fee enters the stop mode, it cannot be left without reiniting the Fee.
 * The stop mode is able to (and supposed to be used to) alter the Fee emulation area in the flash.
 * Thus the Fee needs to analyse the DFLASH state again.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 */
Std_ReturnType Fee_Rb_Idx_EnterStopMode(Fee_Rb_DeviceName_ten deviceName_en)
{
    Std_ReturnType result_en = E_NOT_OK;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_ENTER_STOP_MODE))
    {
        // Fs1 does not have a Fee_Rb_EnterStopMode() API
        // But activation of FeeRbEnterStopModeApi in FS1 is allowed and may be necessary for using rba_FeeAddOnAS
        // Fs1 does only support stop mode by writing TRUE to public variable Fee_Rb_stRequestStopMode_b.
        // When using rba_FeeAddonsAS, FeeRbEnterStopModeApi needs to be activated
#  if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED)) && \
        (defined(FEE_PRV_CFG_ENTER_STOP_MODE_FS1) && (FEE_PRV_CFG_ENTER_STOP_MODE_FS1 != FALSE))
        if(Fee_Rb_DeviceName != deviceName_en)
#  endif
        {
            /* Deviation: Not calling Fee_Prv_OrderDetCheckModuleInitAndStopMode() here */
            /* Reason: We need to seperate between UNINIT and stop mode here so that it is possible to call
             * EnterStopMode API even when the driver is already in stop mode. */
            if(MEMIF_UNINIT == Fee_Rb_Idx_GetStatus(deviceName_en))
            {
                Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_ENTER_STOP_MODE, FEE_E_UNINIT);
            }
            else if(Fee_Prv_ProcIsStopModeActive(deviceName_en)) {
                /* Return E_OK if already in stop mode - last job result will always OK */
                result_en = E_OK;
            }
            else
            {
                Fee_Prv_JobDesc_tst jobDesc_st;
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /*
                 * Prepare order and try to place it.
                 * If placing the order is not possible E_NOT_OK is returned by Fee_Prv_JobPut.
                 */
                jobDesc_st.type_en         = FEE_RB_JOBTYPE_STOP_MODE_E;
                jobDesc_st.jobMode_en      = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, FEE_RB_JOBTYPE_STOP_MODE_E);
                jobDesc_st.bfr_pu8         = NULL_PTR;
                jobDesc_st.bfr_pcu8        = NULL_PTR;
                jobDesc_st.blockNumber_u16 = FEE_PRV_MAX_UINT16;
                jobDesc_st.length_u16      = 0u;
                jobDesc_st.offset_u16      = 0u;
                jobDesc_st.nrBytTot_u16    = 0u;
                jobDesc_st.cntrBytDone_u16 = 0u;
                jobDesc_st.idPers_u16      = 0u;
                jobDesc_st.statusFlag_u16  = 0u;
                jobDesc_st.isChunkJob_b    = FALSE;
                jobDesc_st.isUnknownBlk_b  = FALSE;

                result_en = Fee_Prv_JobPut(deviceName_en, FEE_SID_RB_ENTER_STOP_MODE, &jobDesc_st);
            }
        }
    }

    return(result_en);
}
# endif

/**
 * \brief   Get the maximum sector change counter. If the Fee is not initialized, the function returns 0.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 *
 * \return  Maximum sector change counter
 */
uint32 Fee_Rb_Idx_GetSectChngCnt(Fee_Rb_DeviceName_ten deviceName_en)
{
    uint32 cntrSectChanges_u32;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GET_SECT_CHNG_CNT))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            cntrSectChanges_u32 = Fee_Rb_GetSectChngCnt();
        }
        else
# endif
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GET_SECT_CHNG_CNT))
            {
                cntrSectChanges_u32 = Fee_Prv_FsIfRbGetSectorChgCntr(deviceName_en);
            }
            else
            {
                cntrSectChanges_u32 = 0u;
            }
        }
    }
    else
    {
        cntrSectChanges_u32 = 0u;
    }

    return(cntrSectChanges_u32);
}

# if(defined(FEE_PRV_CFG_RB_GET_NR_SECTOR_ERASES) && (FEE_PRV_CFG_RB_GET_NR_SECTOR_ERASES != FALSE))
/**
 * \brief   Get the number of erase cycles of a sector. If the Fee is not initialized, the function returns 0.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   physSectIdx_u8   Physical sector of which the number of erase cycles shall be returned
 *
 * \return  Number of erase cycles of the given physical sector
 */
uint32 Fee_Rb_Idx_GetSectEraseCntr(Fee_Rb_DeviceName_ten deviceName_en, uint8 physSectIdx_u8)
{
    uint32 cntrSectErases_u32;

    cntrSectErases_u32 = 0u;
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GET_SECT_ERASE_CNTR))
    {
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GET_SECT_ERASE_CNTR))
        {
            if(E_OK == Fee_Prv_OrderDetCheckSectIdx(deviceName_en, FEE_SID_RB_GET_SECT_ERASE_CNTR, physSectIdx_u8))
            {
                cntrSectErases_u32 = Fee_Prv_FsIfRbGetSectorEraseCntr(deviceName_en, physSectIdx_u8);
            }
        }
    }

    return(cntrSectErases_u32);
}

/**
 * \brief   Get the number of supported erase cycles. If the Fee is not initialized, the function returns 0.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 *
 * \return  Number of supported erase cycles
 */
uint32 Fee_Rb_Idx_GetNrOfSuprtdErases(Fee_Rb_DeviceName_ten deviceName_en)
{
    uint32 nrOfSuprtdErases_u32;
    Std_ReturnType retVal_en;
    Fls_Rb_SectorInfo_tst sectorInfo_st;
    Fls_Rb_AddressType emulationStartAdr_u32;
    Fls_Rb_FlsDevice_ten idDevice_en;
    Fee_Prv_ConfigDeviceTable_tst const * deviceConfigTable_pcst;

    nrOfSuprtdErases_u32 = 0u;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GET_NR_OF_SUPRTD_ERASES))
    {
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GET_NR_OF_SUPRTD_ERASES))
        {
            deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
            idDevice_en = Fls_Rb_GetDeviceIdFromDrvIndex(deviceConfigTable_pcst->deviceIdx_u8);

            emulationStartAdr_u32 = Fee_Prv_FsIfGetEmulationStartAdr(deviceName_en);
            /* Get the number of supported erase cycles from the first DFlash sector.
               Assuming value is identical for all DFlash sectors */
            retVal_en = Fee_Prv_Lib_Fls_Rb_GetSectorInfo(idDevice_en, emulationStartAdr_u32, &sectorInfo_st);

            if(E_OK == retVal_en)
            {
                nrOfSuprtdErases_u32 = sectorInfo_st.nrSpecifiedEraseCycles_u32;
            }

            /* In case of single instance, the deviceConfigTable pointer is not required
               To suppress compiler warning for single instance cast to void */
            (void)deviceConfigTable_pcst;
        }
    }

    return(nrOfSuprtdErases_u32);
}

#endif

/**
 * \brief   Get the amount of free space in DFLASH. If the Fee is not initialized, the function returns 0.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 *
 * \return  Amount of free space in bytes
 */
# if(defined(FEE_PRV_CFG_RB_GET_NR_FREE_BYTES) && (FEE_PRV_CFG_RB_GET_NR_FREE_BYTES != FALSE))
uint32 Fee_Rb_Idx_GetNrFreeBytes(Fee_Rb_DeviceName_ten deviceName_en)
{
    uint32 nrFreeBytes_u32 = 0u;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GET_NR_FREE_BYTES))
    {
#  if((defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED)) && \
        (defined(FEE_PRV_CFG_GET_NR_FREE_BYTES_FS1) && (FEE_PRV_CFG_GET_NR_FREE_BYTES_FS1 != FALSE)))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            nrFreeBytes_u32 = Fee_Rb_GetNrFreeBytes();
        }
        else
#  endif
        {
            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GET_NR_FREE_BYTES))
            {
                nrFreeBytes_u32 = Fee_Prv_FsIfRbGetFreeSpace(deviceName_en);
            }
        }
    }

    return(nrFreeBytes_u32);
}
# endif

# if(defined(FEE_PRV_CFG_RB_GET_NR_FREE_BYTES_AND_FAT_ENTRIES) && (FEE_PRV_CFG_RB_GET_NR_FREE_BYTES_AND_FAT_ENTRIES != FALSE))
/**
 * \brief   Get the amount of free user data space and number of free control data space (FAT entries) in DFLASH before a hard reorganization will be started.
 *          If erase operations are not accepted by the user, free non erased sectors will not be considered for user data space evaluation.
 *          If the Fee is not initialized, the function returns 0.
 *
 * \param   deviceName_en       Device instance for which job has to be performed
 * \param   nrFreeBytes_pu32       The pointer to the address, where the number of free data bytes information shall be written.
 * \param   nrFreeFatEntries_pu32  The pointer to the address, where the number of free FAT entries information shall be written.
 * \param   isEraseAccepted_b      Information how to handle free non erased sectors.
 *                                 TRUE:  Free non erased sectors shall be considered, erase operations may occur when writing the given number of bytes
 *                                 FALSE: Free non erased sectors shall not be considered, no erase operations when writing the given number of bytes
 */
void Fee_Rb_Idx_GetNrFreeBytesAndFatEntries(Fee_Rb_DeviceName_ten deviceName_en, uint32 * nrFreeBytes_pu32, uint32 * nrFreeFatEntries_pu32, boolean isEraseAccepted_b)
{
    // Check parameter
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GET_NR_FREE_BYTES_AND_FAT_ENTRIES))
    {
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GET_NR_FREE_BYTES_AND_FAT_ENTRIES))
        {
            Fee_Prv_FsIfRbGetNrFreeBytesAndFatEntries(deviceName_en, nrFreeBytes_pu32, nrFreeFatEntries_pu32, isEraseAccepted_b);
        }
        else
        {
            *nrFreeBytes_pu32      = 0u;
            *nrFreeFatEntries_pu32 = 0u;
        }
    }
    else
    {
        *nrFreeBytes_pu32      = 0u;
        *nrFreeFatEntries_pu32 = 0u;
    }
}
# endif

/**
 * \brief   Is a specified block stored twice in write or invalidate order?
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   blkNr_u16        Block number as generated in Fee.h - This is not the persistent ID!
 *
 * \retval  TRUE    The block is stored twice when writing or invalidating
 * \retval  FALSE   The block is single stored when writing or invalidating
 */
boolean Fee_Rb_Idx_IsBlockDoubleStorageActiveByBlockNr(Fee_Rb_DeviceName_ten deviceName_en, uint16 blkNr_u16)
{
    boolean result_b = FALSE;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_ISBLOCKDOUBLESTORAGE))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName != deviceName_en)
# endif
        {

            if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_ISBLOCKDOUBLESTORAGE))
            {
                // get the block pointer to the block properties table
                Fee_Rb_BlockPropertiesType_tst const * blockPropertiesTable_past = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);

                if(E_OK == Fee_Prv_OrderDetCheckBlkCfg(deviceName_en, FEE_SID_RB_ISBLOCKDOUBLESTORAGE, blkNr_u16, blockPropertiesTable_past))
                {
                    // get result if block is double storage
                    result_b = Fee_Prv_ConfigIsBlockDoubleStorageActiveByBlockNr(blkNr_u16, Fee_Prv_FsIfGetDoubleStorageBitmask(deviceName_en), blockPropertiesTable_past);
                }
                else {
                    Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_ISBLOCKDOUBLESTORAGE, FEE_E_INVALID_BLOCK_NO);
                    result_b = FALSE;
                }
            }
        }
    }

    return result_b;
}


/*
 * \brief   Returns the current Fee working state.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 */
Fee_Rb_WorkingStateType_ten Fee_Rb_Idx_GetWorkingState(Fee_Rb_DeviceName_ten deviceName_en)
{
    Fee_Rb_WorkingStateType_ten stRetVal_en = FEE_RB_IDLE_E;

    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GET_WORKING_STATE))
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            stRetVal_en = Fee_Rb_GetWorkingState();
        }
        else
# endif
        {
            /* Deviation: Not calling Fee_Prv_OrderDetCheckModuleInitAndStopMode() here */
            /* Reason: This API should also be working even when the driver is in stop mode
             * (so that the function returns correctly that the driver is no stop mode), so the function
             * Fee_Prv_OrderDetCheckModuleInitAndStopMode() is not called here like at all other places in the
             * API functions*/
            if(MEMIF_UNINIT == Fee_Rb_Idx_GetStatus(deviceName_en))
            {
                Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_GET_WORKING_STATE, FEE_E_UNINIT);
                stRetVal_en = FEE_RB_IDLE_E;
            }
            else
            {
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
                stRetVal_en = Fee_Prv_ProcGetWorkingState(deviceConfigTable_pcst);
            }
        }
    }
    return(stRetVal_en);
}


# if(defined(FEE_PRV_CFG_RB_PERSIST_DATA) && (FEE_PRV_CFG_RB_PERSIST_DATA != FALSE))
/*
 * \brief   Writes Fs specific persistent data block Fee_PersistentData to Dflash
 *
 * \param   deviceName_en       Device instance for which job has to be performed
 *
 * \retval  E_OK                Order accepted, will be executed asynchronously
 * \retval  E_NOT_OK            Order not accepted
 *
 */
Std_ReturnType Fee_Rb_Idx_WritePersistentData(Fee_Rb_DeviceName_ten deviceName_en)
{
    uint8 * dataBuf_pu8;
    Std_ReturnType retVal_en;
    uint16 length_u16;
    uint16 persistentDataBlockNr_u16;

    retVal_en = E_NOT_OK;
    // Check parameter
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_WRITE_PERSISTENT_DATA))
    {
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_WRITE_PERSISTENT_DATA))
        {
            /* Get the pointer to config data model */
            Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

            if(MEMIF_JOB_PENDING != Fee_Rb_Idx_GetInternalJobResult(deviceName_en))
            {
                /* No internal job is pending, so place the write request */

                dataBuf_pu8 = Fee_Prv_FsIfGetPersistentBufAdr(deviceName_en);
                /* for file systems without usage of persistent data, NULL_PTR is returned */
                if(dataBuf_pu8 != NULL_PTR)
                {
                    persistentDataBlockNr_u16 = deviceConfigTable_pcst->persistentDataBlkNr_u16;

                    length_u16 = Fee_Prv_ConfigGetBlockLengthByBlockNr(
                            persistentDataBlockNr_u16,
                            Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en)
                            );

                    /* Clear the buffer */
                    if(length_u16 < FEE_PRV_CFG_RB_PERSIST_DATA_SIZE)
                    {
                        rba_MemLib_MemSet(Fee_Prv_OrderWriteBuf_au8, 0u, FEE_PRV_CFG_RB_PERSIST_DATA_SIZE);
                    }
                    /* Copy data to the internal buffer to avoid data changes during write operation */
                    rba_MemLib_MemCopy(dataBuf_pu8, Fee_Prv_OrderWriteBuf_au8, length_u16);

                    retVal_en = Fee_Rb_Idx_Write(
                            deviceName_en,
                            persistentDataBlockNr_u16,
                            Fee_Prv_OrderWriteBuf_au8);
                }
            }
        }
    }
    return retVal_en;
}

/*
 * \brief   Reads Fs specific persistent data block Fee_PersistentData to RAM buffer
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 *
 */
LOCAL_INLINE void Fee_Prv_OrderReadPersistentData(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Local variables */
    uint16 length_u16;
    MemIf_JobResultType jobResult_en;
    uint8 * dataBuf_pu8;
    uint16 persistentDataBlockNr_u16;
    /* Get the pointer to config data model */
    Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

    dataBuf_pu8 = Fee_Prv_FsIfGetPersistentBufAdr(deviceName_en);

    /* For file systems without usage of persistent data, NULL_PTR is returned */
    if(dataBuf_pu8 != NULL_PTR)
    {
        persistentDataBlockNr_u16 = deviceConfigTable_pcst->persistentDataBlkNr_u16;

        /* Setup order */
        length_u16 = Fee_Prv_ConfigGetBlockLengthByBlockNr(
                persistentDataBlockNr_u16,
                Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en)
                );

        /* Perform the read */
        if(E_OK == Fee_Rb_Idx_Read(deviceName_en,
                                   persistentDataBlockNr_u16,
                                   0u,
                                   dataBuf_pu8,
                                   length_u16))
        {
            do
            {
                Fee_Rb_Idx_MainFunction(deviceName_en);


                /* Query job status */
                jobResult_en = Fee_Rb_Idx_GetInternalJobResult(deviceName_en);
            } while(MEMIF_JOB_PENDING == jobResult_en);
        }
        else
        {
            /* Read in ini shall always return E_OK */
            jobResult_en = MEMIF_JOB_FAILED;
        }

        /* Read has failed? */
        if(MEMIF_JOB_OK != jobResult_en)
        {
            /* Set all to 0 */
            rba_MemLib_MemSet(dataBuf_pu8, 0u, length_u16);
        }
    }
}
#else
/* Function is always called in the initialization, so provide this function also if feature is not available */
LOCAL_INLINE void Fee_Prv_OrderReadPersistentData(Fee_Rb_DeviceName_ten deviceName_en)
{
    (void)deviceName_en;
}

#endif

# if(defined(FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE) && (FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE != FALSE))
/*
 * \brief   Sets the mode for different jobs
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   jobType_en       Job type for which mode has to be set
 * \param   jobMode_en       Mode that is requested to be set for the passed job type
 *
 */
Std_ReturnType Fee_Rb_Idx_SetJobMode(Fee_Rb_DeviceName_ten deviceName_en, Fee_Rb_JobType_ten jobType_en, Fee_Rb_JobMode_ten jobMode_en)
{
    Std_ReturnType retVal_en;

    retVal_en = E_NOT_OK;

    // Check parameter
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_SETJOBMODE))
    {
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_SETJOBMODE))
        {
            if(E_OK == Fee_Prv_OrderDetCheckJobModeParameters(deviceName_en, FEE_SID_RB_SETJOBMODE, jobType_en, jobMode_en))
            {
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /* Store the requested job mode change */
                Fee_Prv_JobSetJobMode(deviceConfigTable_pcst, jobType_en, jobMode_en);

                retVal_en = E_OK;
            }
        }
    }

    return (retVal_en);
}

/*
 * \brief   Get the mode for the job type. When wrong paramter is passed, the function returns the default mode setting.
 *
 * \param   deviceName_en    Device instance for which job has to be performed
 * \param   jobType_en       Job type for which mode has to be returned
 *
 * \return
 *          jobMode_en       Currently active mode for the passed job type
 *
 */
Fee_Rb_JobMode_ten Fee_Rb_Idx_GetJobMode(Fee_Rb_DeviceName_ten deviceName_en, Fee_Rb_JobType_ten jobType_en)
{
    Fee_Rb_JobMode_ten jobMode_en;

    jobMode_en = FEE_RB_ALLJOBS_ALLSTEPS_E;

    // Check parameter
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_GETJOBMODE))
    {
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_GETJOBMODE))
        {
            /* Reuse the parameter check function with valid jobMode_en to validate jobType_en */
            if(E_OK == Fee_Prv_OrderDetCheckJobModeParameters(deviceName_en, FEE_SID_RB_GETJOBMODE, jobType_en, FEE_RB_ALLJOBS_ALLSTEPS_E))
            {
                /* Get the pointer to config data model */
                Fee_Prv_ConfigDeviceTable_tst const* deviceConfigTable_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

                /* return the requested job mode */
                jobMode_en = Fee_Prv_JobGetJobMode(deviceConfigTable_pcst, jobType_en);
            }
        }
    }

    return (jobMode_en);
}

# endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif
