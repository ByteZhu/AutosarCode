#ifndef NVM_PRV_JOB_TYPES_H
#define NVM_PRV_JOB_TYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM_Prv_InternalBuffer_Types.h"
#include "NvM_Prv_Crypto_ServiceTypes.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
/**
 * \brief
 * Definition of different states for all job state machines provided by NvM.
 * \details
 * The NvM provides following job types:
 * - write jobs
 * - read jobs
 * - restore jobs
 * - invalidate jobs
 * - maintain jobs
 * - validate jobs
 * - jobs to recalculate RAM block CRCs in background
 */
typedef enum
{
    //-------------------------------------------------------------------------
    // Common states for all jobs
    //-------------------------------------------------------------------------

    /// In this state current job is idle.
    /// Typically each job starts with this state.
    NvM_Prv_stJob_Idle_e,
    /// In this state NvM executes a cryptographic job during a NvM job.
    NvM_Prv_stJob_DoCrypto_e,
    /// In this state NvM manages keys required for a cryptographic job during a NvM job.
    NvM_Prv_stJob_DoCryptoKeySetting_e,
    /// In this state NvM executes a MemIf job during a NvM job.
    NvM_Prv_stJob_DoMemIf_e,
    /// In this state NvM polls a pending MemIf job during a NvM job.
    NvM_Prv_stJob_PollMemIf_e,
    /// In this state NvM recalculates a CRC during a NvM job.
    NvM_Prv_stJob_DoCrc_e,
    /// NvM reaches this state if current job has been finished and is waiting for evaluation.
    NvM_Prv_stJob_Finished_e,


    //-------------------------------------------------------------------------
    // States for cryptographic job for key setting
    //-------------------------------------------------------------------------
    /// In this state NvM sets the key element InitVector before encryption / authentication.
    /// This state is a substate of the state machine for key setting during a cryptographic job.
    NvM_Prv_stJobCryptoKey_SetInitVector_e,
    /// In this state NvM waits until the key element InitVector is set.
    /// This state is a substate of the state machine for key setting during a cryptographic job.
    NvM_Prv_stJobCryptoKey_PollSetInitVector_e,
    /// In this state NvM sets the key as valid before encryption / authentication.
    /// This state is a substate of the state machine for key setting during a cryptographic job.
    NvM_Prv_stJobCryptoKey_SetValid_e,
    /// In this state NvM waits until the key is set valid.
    /// This state is a substate of the state machine for key setting during a cryptographic job.
    NvM_Prv_stJobCryptoKey_PollSetValid_e,

    //-------------------------------------------------------------------------
    // States for write jobs
    //-------------------------------------------------------------------------
    NvM_Prv_stJobWrite_GetUserData_e,
    NvM_Prv_stJobWrite_RecalcUserDataCrc_e,
    NvM_Prv_stJobWrite_CalcNvBlkCrc_e,
    NvM_Prv_stJobWrite_AppendAdminData_e,
    NvM_Prv_stJobWrite_AppendBlockHeader_e,
    NvM_Prv_stJobWrite_CalcCrcBlockHeader_e,
    NvM_Prv_stJobWrite_InitiateMemIf_e,

    //---------------------------------------------------------------
    // Sub-states for cryptographic jobs within write jobs
    //---------------------------------------------------------------
    /// In this state NvM gets the key element InitVector if required
    /// for encryption / authentication.
    /// NvM leaves this state immediately.
    /// This state is a substate of the state machine for write jobs.
    NvM_Prv_stJobWrite_CryptoGetKeyInitVector_e,
    /// In this state NvM starts the data encryption.
    /// NvM leaves this state immediately.
    /// This state is a substate of the state machine for write jobs.
    NvM_Prv_stJobWrite_CryptoStartEncryption_e,
    /// In this state NvM waits until the data encryption completes.
    /// This state is a substate of the state machine for write jobs.
    NvM_Prv_stJobWrite_CryptoPollEncryption_e,
    /// In this state NvM starts the signature generation.
    /// NvM leaves this state immediately.
    /// This state is a substate of the state machine for write jobs.
    NvM_Prv_stJobWrite_CryptoStartGenerationSignature_e,
    /// In this state NvM waits until the signature generation completes.
    /// This state is a substate of the state machine for write jobs.
    NvM_Prv_stJobWrite_CryptoPollGenerationSignature_e,


    //-------------------------------------------------------------------------
    // States for read jobs
    //-------------------------------------------------------------------------
    NvM_Prv_stJobRead_Start_e,
    NvM_Prv_stJobRead_GetUserData_e,
    NvM_Prv_stJobRead_CrcCheck_e,
    NvM_Prv_stJobRead_InitiateMemIf_e,
    NvM_Prv_stJobRead_RecalcUserDataCrc_e,
    NvM_Prv_stJobRead_CalcNvBlkCrc_e,
    NvM_Prv_stJobRead_CalcCrcBlockHeader_e,
    NvM_Prv_stJobRead_ExtractAdminData_e,
    NvM_Prv_stJobRead_SetUserData_e,
    NvM_Prv_stJobRead_StartImplicitRecovery_e,

    //---------------------------------------------------------------
    // Sub-states for cryptographic jobs within read jobs
    //---------------------------------------------------------------
    /// In this state NvM starts the signature verification.
    /// NvM leaves this state immediately.
    /// This state is a substate of the state machine for read jobs.
    NvM_Prv_stJobRead_CryptoStartSignatureVerification_e,
    /// In this state NvM waits until the signature verification completes.
    /// This state is a substate of the state machine for read jobs.
    NvM_Prv_stJobRead_CryptoPollSignatureVerification_e,
    /// In this state NvM starts the data decryption.
    /// NvM leaves this state immediately.
    /// This state is a substate of the state machine for read jobs.
    NvM_Prv_stJobRead_CryptoStartDecryption_e,
    /// In this state NvM waits until the data decryption completes.
    /// This state is a substate of the state machine for read jobs.
    NvM_Prv_stJobRead_CryptoPollDecryption_e,

    //---------------------------------------------------------------
    // Sub-states for cryptographic jobs within random number generation jobs
    //---------------------------------------------------------------
    /// In this state NvM starts the random number generation.
    /// NvM leaves this state immediately.
    NvM_Prv_stJobGenerateRandomNr_CryptoStart_e,
    /// In this state NvM waits until the random number generation completes.
    NvM_Prv_stJobGenerateRandomNr_CryptoPoll_e,

    //-------------------------------------------------------------------------
    // States for restore jobs
    //-------------------------------------------------------------------------
    NvM_Prv_stJobRestore_Start_e,
    NvM_Prv_stJobRestore_CopyFromRom_e,
    NvM_Prv_stJobRestore_ExplicitSync_e,
    NvM_Prv_stJobRestore_InitCallback_e,
    NvM_Prv_stJobRestore_Crc_e,
    NvM_Prv_stJobRestore_StartWrite_e,

    //-------------------------------------------------------------------------
    // States for invalidate jobs
    //-------------------------------------------------------------------------
    NvM_Prv_stJobInvalidate_InitiateMemIf_e,

    //-------------------------------------------------------------------------
    // States for maintain jobs
    //-------------------------------------------------------------------------
    NvM_Prv_stJobMaintain_InitiateMemIf_e,

    //-------------------------------------------------------------------------
    // States for validate jobs
    //-------------------------------------------------------------------------
    NvM_Prv_stJobValidate_Start_e,

    //-------------------------------------------------------------------------
    // States for jobs to recalculate RAM block CRCs
    //-------------------------------------------------------------------------
    NvM_Prv_stRecalcRamBlkCrc_ExplicitSyncWriteToNvM_e,
    NvM_Prv_stRecalcRamBlkCrc_Do_e,

    //-------------------------------------------------------------------------
    // This is actually no job state,
    // in fact this enum value defines count of job states available in NvM and
    // can be used for array definition
    //-------------------------------------------------------------------------
    NvM_Prv_stJob_Count_e

} NvM_Prv_stJob_ten;

/**
 * Definition of enumeration for the job result type.
 */
typedef enum
{
    /// Job step has succeeded.
    NvM_Prv_JobResult_Succeeded_e,
    /// Job step is pending and job must be continued in the next cycle.
    NvM_Prv_JobResult_Pending_e,
    /// Job has failed.
    NvM_Prv_JobResult_Failed_e,
    /// Block processed in current job is inconsistent.
    NvM_Prv_JobResult_BlockInconsistent_e,
    /// Block processed in current job is invalidated.
    NvM_Prv_JobResult_BlockInvalidated_e,
    /// Block skipped in multi-block service
    NvM_Prv_JobResult_Skipped_e,
    /// Job finished without access to medium, e.g. due to RAM Block CRC usage
    NvM_Prv_JobResult_Succeeded_MemIfSkipped_e

} NvM_Prv_JobResult_ten;

/**
 * Definition of the structure for CRC calculation during a NvM job.
 */
typedef struct
{
    /// State of the CRC recalculation.
    /// Due to more efficient implementation NvM uses here the same type as for NVM jobs.
    /// CRC handling uses only the states NvM_Prv_JobStepResult_Succeeded_e and NvM_Prv_JobStepResult_Pending_e.
    NvM_Prv_JobResult_ten   stCalculation_en;
    /// Counter for bytes remaining during CRC recalculation
    uint16                  cntrCrcCalculation_uo;
    /// Set to TRUE to initiate a new CRC calculation with start value from CRC component.
    /// Set to FALSE when initiating a subsequent CRC calculation with a CRC used as start value.
    boolean                 isFirstCall_b;
    /// Length of the data in bytes for the CRC calculation.
    uint16                  Length_u16;
    /// Pointer to the buffer which contains data for the CRC calculation.
    uint8*                  Buffer_pu8;
    /// CRC calculated in last operation over data in the buffer defined by Buffer_pu8.
    NvM_Prv_Crc_tun         Crc_un;

} NvM_Prv_Job_CrcCalculation_tst;

/**
 * Definition of the structure for data required for CRC calculation during a NvM job.
 */
typedef struct
{
    NvM_Prv_Job_CrcCalculation_tst Calculation_st;
    /// CRC calculated over data in the permanent RAM block.
    /// Permanent RAM block contains only user data.
    // TRACE[SWS_NvM_00544] Allocate memory for largest CRC used by NvM.
    NvM_Prv_Crc_tun CrcRamBlk_un;

} NvM_Prv_Job_CrcData_tst;

/**
 * Definition of the structure for data required to process a NvM job.
 */
typedef struct
{
    /// ID of the job to be executed by the NvM (NVM_PRV_JOB_ID_IDLE if no job shall be executed)
    NvM_Prv_idJob_ten idJob_en;
    /// ID of the queue containing current job
    NvM_Prv_idQueue_tuo idQueue_uo;
    /// ID of the block service for which current job will be done
    NvM_Prv_idService_tuo idService_uo;
    /// Service bit for the block service for which current job will be done
    NvM_Prv_ServiceBit_tuo ServiceBit_uo;
    /// Id of the block used in current job
    NvM_BlockIdType idBlock_uo;
    /// Index of the dataset used in current job
    uint8 idxDataset_u8;

    /// Information whether current job will be done for a multi-block service
    boolean isMultiServiceActive_b;
    /// Information whether current job will be done for an auxiliary service
    boolean isAuxServiceActive_b;
    /// Information whether the permanent RAM block is used in current job.
    boolean isPRamBlockUsed_b;
    /// Information whether user data will be copied into the NvM internal buffer for current job.
    boolean isIntBufferToUse_b;
    /// Information whether encryption of user data is enabled.
    boolean isEncryptionEnabled_b;

    /// Counter for operations to copy user data into/from the NvM internal buffer during explicit synchronization.
    uint8 cntrExpSyncOperations_u8;

    /// Pointer to buffer for user data used in current job.
    /// For write jobs this buffer contains user data to be written
    /// (for explicit synchronization the NvM copies user data via callback into the internal buffer
    ///  before writing it).
    /// For read/restore jobs this buffer contains read/restored user data
    /// (for explicit synchronization NvM reads/restores user data into the internal buffer and
    ///  copies it via callback afterwards).
    NvM_Prv_ptrRamBlock_tun UserData_un;

    /// Pointer to the internal buffer structure used in current job if required by block configuration.
    NvM_Prv_InternalBuffer_st IntBuffer_st;

} NvM_Prv_JobData_tst;

/**
 * Definition of the structure for the result of a NvM job.
 */
typedef struct
{
    /// Result of the current job
    NvM_Prv_JobResult_ten Result_en;
    /// Detail error information of the current job
    NvM_Rb_ErrorInfoDetail_ten errorInfoDetail_en;
    /// Production errors detected during the current job
    uint8 ProductionError_u8;

    /// Data for CRC calculation during the current job.
    NvM_Prv_Job_CrcData_tst CrcData_st;

#if (NVM_CRYPTO_USED == STD_ON)
    /// Counter for Csm job retries.
    uint8 cntrCsmJobRetry_uo;

    ///Results of the current job related to cryptographic services.
    NvM_Prv_Crypto_ServiceResult_tst Crypto_st;
#endif

} NvM_Prv_JobResult_tst;

/**
 * Definition of the structure containing all data required for a NvM job.
 */
typedef struct
{
    /// All results of the NvM job
    NvM_Prv_JobResult_tst JobResult_st;

    /// All data required to process the NvM job
    NvM_Prv_JobData_tst JobData_st;

    /// Current state of the NvM job
    NvM_Prv_stJob_ten stJob_en;

} NvM_Prv_Job_tst;

/// Type definition of state functions for different NvM job state machines.
typedef void (*NvM_Prv_Job_State_tpfct)(NvM_Prv_stJob_ten* stJob_pen,
                                        NvM_Prv_JobResult_tst* JobResult_pst,
                                        NvM_Prv_JobData_tst const* JobData_pcst);

/// Type definition of state machine functions for different NvM jobs.
typedef NvM_Prv_Job_State_tpfct (*NvM_Prv_Job_StateMachine_tpfct)(NvM_Prv_stJob_ten* stJob_pen);

/* NVM_PRV_JOB_TYPES_H */
#endif

