/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"

#include "NvM_Prv_Crc.h"
#include "NvM_Prv_Csm.h"
#include "NvM_Prv_Crypto.h"
#include "NvM_Prv_ErrorDetection.h"

#if (defined(TESTCD_NVM_ENABLED) && (TESTCD_NVM_ENABLED == STD_ON))
# include "TestCd_NvM.h"
#endif

#if (NVM_CRYPTO_USED == STD_ON)

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
 */
LOCAL_INLINE void NvM_Prv_CryptoRead_PrepareDecryption(NvM_Prv_JobResult_tst* JobResult_pst,
                                                       NvM_Prv_JobData_tst const* JobData_pcst,
                                                       NvM_Prv_Crypto_ServiceData_tst* JobCryptoData_pst);

LOCAL_INLINE void NvM_Prv_CryptoRead_PrepareAuthentication(NvM_Prv_JobResult_tst* JobResult_pst,
                                                           NvM_Prv_JobData_tst const* JobData_pcst,
                                                           NvM_Prv_Crypto_ServiceData_tst* JobCryptoData_pst);

# define NVM_START_SEC_CODE
# include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Declarations
 **********************************************************************************************************************
 */
static void NvM_Prv_CryptoRead_StartSignatureVerification(NvM_Prv_stJob_ten* stJob_pen,
                                                          NvM_Prv_JobResult_tst* JobResult_pst,
                                                          NvM_Prv_JobData_tst const* JobData_pcst);

static void NvM_Prv_CryptoRead_PollSignatureVerification(NvM_Prv_stJob_ten* stJob_pen,
                                                         NvM_Prv_JobResult_tst* JobResult_pst,
                                                         NvM_Prv_JobData_tst const* JobData_pcst);

static void NvM_Prv_CryptoRead_DoKeySetting(NvM_Prv_stJob_ten* stJob_pen,
                                            NvM_Prv_JobResult_tst* JobResult_pst,
                                            NvM_Prv_JobData_tst const* JobData_pcst);

static void NvM_Prv_CryptoRead_StartDecryption(NvM_Prv_stJob_ten* stJob_pen,
                                               NvM_Prv_JobResult_tst* JobResult_pst,
                                               NvM_Prv_JobData_tst const* JobData_pcst);

static void NvM_Prv_CryptoRead_PollDecryption(NvM_Prv_stJob_ten* stJob_pen,
                                              NvM_Prv_JobResult_tst* JobResult_pst,
                                              NvM_Prv_JobData_tst const* JobData_pcst);

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
 */
/**
 * \brief
 * This private function returns the pointer to the job step for the current state of the cryptographic read job.
 * \details
 * This function is only available if usage of cryptographic services is enabled by NvM configuration.
 *
 * \param[IN] stJob_en
 * Current state of the cryptographic read job
 *
 * \return
 * Pointer to the job step
 */
NvM_Prv_Job_State_tpfct NvM_Prv_CryptoRead_GetStateFct(NvM_Prv_stJob_ten* stJob_pen)
{
    NvM_Prv_Job_State_tpfct JobStateCryptoRead_pfct = NULL_PTR;

    switch (*stJob_pen)
    {
        case NvM_Prv_stJob_DoCrypto_e:
        case NvM_Prv_stJobRead_CryptoStartSignatureVerification_e:
            JobStateCryptoRead_pfct = NvM_Prv_CryptoRead_StartSignatureVerification;
            // set job state to ease debugging and to avoid MISRA warning that stJob_pen can be a pointer to const
            *stJob_pen = NvM_Prv_stJobRead_CryptoStartSignatureVerification_e;
        break;

        case NvM_Prv_stJobRead_CryptoPollSignatureVerification_e:
            JobStateCryptoRead_pfct = NvM_Prv_CryptoRead_PollSignatureVerification;
        break;

        case NvM_Prv_stJob_DoCryptoKeySetting_e:
        case NvM_Prv_stJobCryptoKey_SetInitVector_e:
        case NvM_Prv_stJobCryptoKey_SetValid_e:
        case NvM_Prv_stJobCryptoKey_PollSetInitVector_e:
        case NvM_Prv_stJobCryptoKey_PollSetValid_e:
            JobStateCryptoRead_pfct = NvM_Prv_CryptoRead_DoKeySetting;
        break;

        case NvM_Prv_stJobRead_CryptoStartDecryption_e:
            JobStateCryptoRead_pfct = NvM_Prv_CryptoRead_StartDecryption;
        break;

        case NvM_Prv_stJobRead_CryptoPollDecryption_e:
            JobStateCryptoRead_pfct = NvM_Prv_CryptoRead_PollDecryption;
        break;

        default:
            JobStateCryptoRead_pfct = NULL_PTR;
        break;
    }

    return JobStateCryptoRead_pfct;
}

/**
 * This local private function is a cryptographic job step function and starts the cryptographic service
 * for the signature verification.
 * \details
 * This function is only available if usage of cryptographic services is enabled by NvM configuration.
 * This function only prepares all required data. The actual start is done by the function NvM_Prv_Crypto_StartService.
 *
 * Internal buffer contains data read from non-volatile memory which consists of following parts ordered as defined:
 * - user data (dependent on configuration encrypted or plain data)
 * - actual signature
 *
 * \param [inout] stJob_pen
 * State of the cryptographic job
 * \param [inout] JobResult_pst
 * Pointer to the result of the cryptographic job, possible values:
 * - NvM_Prv_JobResult_Pending_e   = signature verification cannot be started due to busy Csm -> retry in next cycle
 * - NvM_Prv_JobResult_Succeeded_e = start of signature verification has succeeded or no signature configured
 *                                   -> start data decryption
 * - NvM_Prv_JobResult_Failed_e    = start of signature verification has failed
 * \param [in] JobData_pcst
 * Pointer to the data of the current NvM job
 */
static void NvM_Prv_CryptoRead_StartSignatureVerification(NvM_Prv_stJob_ten* stJob_pen,
                                                          NvM_Prv_JobResult_tst* JobResult_pst,
                                                          NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_Prv_Crypto_dataServiceStart_tst dataJobStart_st;
    NvM_Prv_Crypto_ServiceData_tst jobCryptoData_st;
    uint32 lengthSignature_u16 = NvM_Prv_BlkDesc_GetLengthJobCsm(JobData_pcst->idBlock_uo,
                                                                 NvM_Prv_Crypto_idService_VerifySignature_e);

    // Prefill job results structure for signature verification
    JobResult_pst->Crypto_st.idServiceCrypto_en = NvM_Prv_Crypto_idService_VerifySignature_e;
    JobResult_pst->Crypto_st.idJobStarted_uo = NvM_Prv_BlkDesc_GetIdJobCsm(JobData_pcst->idBlock_uo,
                                                                           NvM_Prv_Crypto_idService_VerifySignature_e);
    // member idJobCallback_uo will be set in the callback if Csm job has completed
    JobResult_pst->Crypto_st.outputPrimaryLength_u32 = 0u;
    JobResult_pst->Crypto_st.outputPrimaryLengthConfigured_u32 = 0u;
    JobResult_pst->Crypto_st.outputSecondaryLength_u32 = 0u;            // not used for signature verification
    JobResult_pst->Crypto_st.outputSecondaryLengthConfigured_u32 = 0u;  // not used for signature verification
    // member Result_uo will be set in the callback if Csm job has completed
    JobResult_pst->Crypto_st.ResultVerification_uo = 0xFFu;

    // Prefill data structure for a cryptographic job
    jobCryptoData_st.inputPrimary_pcu8 = JobData_pcst->IntBuffer_st.Buffer_pu8;
    jobCryptoData_st.inputPrimaryLength_u32 = (  *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16
                                               - lengthSignature_u16);
    jobCryptoData_st.inputSecondary_pcu8 = &(JobData_pcst->IntBuffer_st.Buffer_pu8[  *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16
                                                                                   - lengthSignature_u16]);
    jobCryptoData_st.inputSecondaryLength_u32 = lengthSignature_u16;
    jobCryptoData_st.ResultVerification_puo = &JobResult_pst->Crypto_st.ResultVerification_uo;
    // all other members of jobCsmData_st are not required to start signature generation

    dataJobStart_st.stJobNextSuccess_en = NvM_Prv_stJobRead_CryptoPollSignatureVerification_e;
    dataJobStart_st.stJobNextSkipped_en = NvM_Prv_stJob_DoCryptoKeySetting_e;
    dataJobStart_st.isCryptoServiceConfigured_b = (0u != lengthSignature_u16);
    dataJobStart_st.idJobToStart_uo = JobResult_pst->Crypto_st.idJobStarted_uo;
    dataJobStart_st.StartJobCsm_pfct = NvM_Prv_Csm_StartSignatureVerification;

    NvM_Prv_Csm_StartJob(stJob_pen, JobResult_pst, JobData_pcst, &jobCryptoData_st, &dataJobStart_st);
}

/**
 * \brief
 * This local private function is a cryptographic job step function and polls results of cryptographic services
 * for signature verification.
 * \details
 * This function is only available if usage of cryptographic services is enabled by NvM configuration.
 * As soon as results of signature verification are available and plausible (see NvM_Prv_Csm_CheckJobResult)
 * this function updates the result of the job step.
 *
 * \param [inout] stJob_pen
 * State of the cryptographic job
 * \param [inout] JobResult_pst
 * Pointer to the result of the cryptographic job, possible values:
 * - NvM_Prv_JobResult_Pending_e            = signature verification still pending
 * - NvM_Prv_JobResult_Succeeded_e          = signature verification has succeeded
 * - NvM_Prv_JobResult_Failed_e             = signature verification has failed
 * \param [in] JobData_pcst
 * Pointer to the data of the current NvM job
 */
static void NvM_Prv_CryptoRead_PollSignatureVerification(NvM_Prv_stJob_ten* stJob_pen,
                                                         NvM_Prv_JobResult_tst* JobResult_pst,
                                                         NvM_Prv_JobData_tst const* JobData_pcst)
{
    // check whether the Csm job has completed and result is available
    if (NvM_Prv_Csm_CheckJobResult(JobResult_pst,
                                   JobData_pcst,
                                   NVM_PRV_NO_DET_ERROR,
                                   NVM_PRV_NO_DET_ERROR))
    {
        if (   (E_OK == JobResult_pst->Crypto_st.Result_uo)
            && (CRYPTO_E_VER_OK == JobResult_pst->Crypto_st.ResultVerification_uo))
        {
            uint16 LengthSignature_u16 = NvM_Prv_BlkDesc_GetLengthJobCsm(JobData_pcst->idBlock_uo,
                                                                         NvM_Prv_Crypto_idService_VerifySignature_e);
            *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16 = (uint16)(  *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16
                                                                        - LengthSignature_u16);
            JobResult_pst->Result_en = NvM_Prv_JobResult_Succeeded_e;
            *stJob_pen = NvM_Prv_stJob_DoCryptoKeySetting_e;
        }
        else
        {
            JobResult_pst->Result_en = NvM_Prv_JobResult_BlockInconsistent_e;
            *stJob_pen = NvM_Prv_stJob_DoCrypto_e;
        }
    }
    // as long as Csm job has not completed and no result is available NvM remains pending in current state
}

/**
 * \brief
 * This local private function is a cryptographic job step function and executes a sub-state machine to set key elements
 * required for user data decryption / authentication.
 * \details
 * This function is only available if usage of cryptographic services is enabled by NvM configuration.
 *
 * \param [inout] stJob_pen
 * State of the cryptographic job
 * \param [inout] JobResult_pst
 * Pointer to the result of the cryptographic job, possible values:
 * - NvM_Prv_JobResult_Succeeded_e = setting of key elements succeeded or
 *                                   no key elements configured for current block
 * - NvM_Prv_JobResult_Pending_e   = setting of key elements still pending -> continue in next cycle
 * - NvM_Prv_JobResult_Failed_e    = setting of key elements failed
 * \param [in] JobData_pcst
 * Pointer to the data of the current NvM job
 */
static void NvM_Prv_CryptoRead_DoKeySetting(NvM_Prv_stJob_ten* stJob_pen,
                                            NvM_Prv_JobResult_tst* JobResult_pst,
                                            NvM_Prv_JobData_tst const* JobData_pcst)
{
    JobResult_pst->Result_en = NvM_Prv_JobResult_Succeeded_e;

#if (NVM_CRYPTO_RANDOM_USED == STD_ON)
    NvM_Prv_CryptoKeySetting_DoStateMachine(stJob_pen, JobResult_pst, JobData_pcst);
#endif

    if (NvM_Prv_JobResult_Succeeded_e == JobResult_pst->Result_en)
    {
        // cryptographic services for key setting have succeeded or are not configured ->
        //
        *stJob_pen = NvM_Prv_stJobRead_CryptoStartDecryption_e;
    }
    // if cryptographic services for key setting have failed
    // -> cryptographic services for read job will finish in NvM_Prv_Crypto_DoStateMachine
    // if cryptographic services for key setting are still pending
    // -> cryptographic services for read job will remain in this state
}

/**
 * \brief
 * This local private function is a cryptographic job step function and starts the cryptographic service
 * for the data decryption / authentication.
 * \details
 * This function is only available if usage of cryptographic services is enabled by NvM configuration.
 * This function only prepares all required data. The actual start is done by the function NvM_Prv_Csm_StartService.
 *
 * Internal buffer contains only encrypted data (dependent on configuration with a tag (AEAD algorithm) or
 * without a tag (standard algorithm))
 *
 * \param [inout] stJob_pen
 * State of the cryptographic job
 * \param [inout] JobResult_pst
 * Pointer to the result of the cryptographic job, possible values:
 * - NvM_Prv_JobResult_Pending_e   = data decryption cannot be started due to busy Csm -> retry in next cycle
 * - NvM_Prv_JobResult_Succeeded_e = start of data decryption has succeeded or no data decryption configured
 *                                   -> finish cryptographic job
 * - NvM_Prv_JobResult_Failed_e    = start of data encryption has failed
 * \param [in] JobData_pcst
 * Pointer to the data of the current NvM job
 */
static void NvM_Prv_CryptoRead_StartDecryption(NvM_Prv_stJob_ten* stJob_pen,
                                               NvM_Prv_JobResult_tst* JobResult_pst,
                                               NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_Prv_Crypto_dataServiceStart_tst dataJobStart_st;
    NvM_Prv_Crypto_ServiceData_tst jobCryptoData_st =
            {NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR};
    uint16 LengthEncryptedData_u16 = NvM_Prv_BlkDesc_GetLengthJobCsm(JobData_pcst->idBlock_uo,
                                                                     NvM_Prv_Crypto_idService_Decrypt_e);
    uint16 LengthTag_u16 = NvM_Prv_BlkDesc_GetLengthJobCsmTag(JobData_pcst->idBlock_uo);

    // Prefill job results structure for data decryption
    JobResult_pst->Crypto_st.idServiceCrypto_en = NvM_Prv_Crypto_idService_Decrypt_e;
    JobResult_pst->Crypto_st.idJobStarted_uo = NvM_Prv_BlkDesc_GetIdJobCsm(JobData_pcst->idBlock_uo,
                                                                           NvM_Prv_Crypto_idService_Decrypt_e);
    // member idJobCallback_uo will be set in the callback if Csm job has completed
    JobResult_pst->Crypto_st.outputPrimaryLength_u32 = LengthEncryptedData_u16;
    JobResult_pst->Crypto_st.outputPrimaryLengthConfigured_u32 = LengthEncryptedData_u16;
    JobResult_pst->Crypto_st.outputSecondaryLength_u32 = 0u;            // not used for data decryption
    JobResult_pst->Crypto_st.outputSecondaryLengthConfigured_u32 = 0u;  // not used for data decryption
    // member Result_uo will be set in the callback if Csm job has completed
    JobResult_pst->Crypto_st.ResultVerification_uo = 0xFFu;

    // Prefill data structure for a cryptographic job dependent on encryption / authentication
    if (0u != LengthEncryptedData_u16)
    {
        // encryption is configured
        NvM_Prv_CryptoRead_PrepareDecryption(JobResult_pst, JobData_pcst, &jobCryptoData_st);
    }
    else
    {
        // no encryption is required
        // -> check authentication
        if (0u != LengthTag_u16)
        {
            // authentication is configured
            NvM_Prv_CryptoRead_PrepareAuthentication(JobResult_pst, JobData_pcst, &jobCryptoData_st);
        }
    }

    dataJobStart_st.stJobNextSuccess_en = NvM_Prv_stJobRead_CryptoPollDecryption_e;
    dataJobStart_st.stJobNextSkipped_en = NvM_Prv_stJob_DoCrypto_e;
    dataJobStart_st.isCryptoServiceConfigured_b = ((0u != LengthEncryptedData_u16) || (0u != LengthTag_u16));
    dataJobStart_st.idJobToStart_uo = JobResult_pst->Crypto_st.idJobStarted_uo;

    if (0u == LengthTag_u16)
    {
        // no authentication configured -> use standard data decryption
        dataJobStart_st.StartJobCsm_pfct = NvM_Prv_Csm_StartDecryption;
        // For standard encryption no authentication will be done -> preset verification result
        JobResult_pst->Crypto_st.ResultVerification_uo = CRYPTO_E_VER_OK;
    }
    else
    {
        // authentication configured -> use AEAD data decryption
        dataJobStart_st.StartJobCsm_pfct = NvM_Prv_Csm_StartDecryptionAead;
    }

    NvM_Prv_Csm_StartJob(stJob_pen, JobResult_pst, JobData_pcst, &jobCryptoData_st, &dataJobStart_st);
}

/**
 * \brief
 * This local private function is a cryptographic job step function and polls results of cryptographic services
 * for data decryption / authentication.
 * \details
 * This function is only available if usage of cryptographic services is enabled by NvM configuration.
 * As soon as results of data decryption / authentication are available and plausible (see NvM_Prv_Csm_CheckJobResult)
 * this function updates the result of the job step.
 *
 * \param [inout] stJob_pen
 * State of the cryptographic job
 * \param [inout] JobResult_pst
 * Pointer to the result of the cryptographic job, possible values:
 * - NvM_Prv_JobResult_Pending_e            = data decryption / authentication still pending
 * - NvM_Prv_JobResult_Succeeded_e          = data decryption / authentication has succeeded
 * - NvM_Prv_JobResult_Failed_e             = data decryption / authentication has failed
 * \param [in] JobData_pcst
 * Pointer to the data of the current NvM job
 */
static void NvM_Prv_CryptoRead_PollDecryption(NvM_Prv_stJob_ten* stJob_pen,
                                              NvM_Prv_JobResult_tst* JobResult_pst,
                                              NvM_Prv_JobData_tst const* JobData_pcst)
{
    // check whether the Csm job has completed and result is available
    if (NvM_Prv_Csm_CheckJobResult(JobResult_pst,
                                   JobData_pcst,
                                   NVM_PRV_NO_DET_ERROR,
                                   NVM_PRV_NO_DET_ERROR))
    {
        if (   (E_OK == JobResult_pst->Crypto_st.Result_uo)
            && (CRYPTO_E_VER_OK == JobResult_pst->Crypto_st.ResultVerification_uo))
        {
            uint16 LengthEncryptedData_u16 = NvM_Prv_BlkDesc_GetLengthJobCsm(JobData_pcst->idBlock_uo,
                                                                             NvM_Prv_Crypto_idService_Decrypt_e);
            uint16 PositionCrc_u16 =   JobData_pcst->IntBuffer_st.OffsetPlainData_u16
                                     + NvM_Prv_BlkDesc_GetSize(JobData_pcst->idBlock_uo);
            *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16 = LengthEncryptedData_u16;

            // -> check RAM CRC
            if (   NvM_Prv_BlkDesc_IsBlockSelected(JobData_pcst->idBlock_uo, NVM_PRV_BLOCK_FLAG_USE_RAM_CRC)
                && JobData_pcst->isEncryptionEnabled_b)
            {
                // RAM CRC is used for current block
                // -> move read CRC directly after decrypted data to be checked later in the read job
                rba_MemLib_MemCopy(&(JobData_pcst->IntBuffer_st.Buffer_pu8[LengthEncryptedData_u16]),
                                   &JobData_pcst->IntBuffer_st.Buffer_pu8[PositionCrc_u16],
                                   NvM_Prv_Crc_GetSizeCrc(NvM_Prv_BlkDesc_GetCrcType(JobData_pcst->idBlock_uo)));
            }

            JobResult_pst->Result_en = NvM_Prv_JobResult_Succeeded_e;
        }
        else
        {
            JobResult_pst->Result_en = NvM_Prv_JobResult_BlockInconsistent_e;
        }

        *stJob_pen = NvM_Prv_stJob_DoCrypto_e;
    }
    // as long as Csm job has not completed and no result is available NvM remains pending in current state
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline code
 **********************************************************************************************************************
 */
LOCAL_INLINE void NvM_Prv_CryptoRead_PrepareDecryption(NvM_Prv_JobResult_tst* JobResult_pst,
                                                       NvM_Prv_JobData_tst const* JobData_pcst,
                                                       NvM_Prv_Crypto_ServiceData_tst* JobCryptoData_pst)
{
    uint16 PositionTag_u16;
    uint16 LengthEncryptedData_u16 = NvM_Prv_BlkDesc_GetLengthJobCsm(JobData_pcst->idBlock_uo,
                                                                     NvM_Prv_Crypto_idService_Encrypt_e);
    uint16 LengthTag_u16 = NvM_Prv_BlkDesc_GetLengthJobCsmTag(JobData_pcst->idBlock_uo);

    PositionTag_u16 = *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16 - LengthTag_u16;

    // Prefill data structure for a cryptographic job
    JobCryptoData_pst->inputPrimary_pcu8 = JobData_pcst->IntBuffer_st.Buffer_pu8;
    JobCryptoData_pst->inputPrimaryLength_u32 = LengthEncryptedData_u16;
    JobCryptoData_pst->inputSecondary_pcu8 = NvM_Prv_BlkDesc_GetDataJobCsmAssociated(JobData_pcst->idBlock_uo);
    JobCryptoData_pst->inputSecondaryLength_u32 = NvM_Prv_BlkDesc_GetLengthJobCsmAssociated(JobData_pcst->idBlock_uo);
    JobCryptoData_pst->inputTertiary_pcu8 = &((JobData_pcst->IntBuffer_st.Buffer_pu8)[PositionTag_u16]);
    JobCryptoData_pst->inputTertiaryLength_u32 = LengthTag_u16;
    JobCryptoData_pst->outputPrimary_pu8 =
            &JobData_pcst->IntBuffer_st.Buffer_pu8[JobData_pcst->IntBuffer_st.OffsetPlainData_u16];
    JobCryptoData_pst->outputPrimaryLength_pu32 = &JobResult_pst->Crypto_st.outputPrimaryLength_u32;
    JobCryptoData_pst->ResultVerification_puo = &JobResult_pst->Crypto_st.ResultVerification_uo;
    // all other members of jobCryptoData_st are not required to start data decryption
}

LOCAL_INLINE void NvM_Prv_CryptoRead_PrepareAuthentication(NvM_Prv_JobResult_tst* JobResult_pst,
                                                           NvM_Prv_JobData_tst const* JobData_pcst,
                                                           NvM_Prv_Crypto_ServiceData_tst* JobCryptoData_pst)
{
    uint16 PositionTag_u16;
    uint16 LengthTag_u16 = NvM_Prv_BlkDesc_GetLengthJobCsmTag(JobData_pcst->idBlock_uo);
    uint16 PositionPlainUserData_uo = NvM_Prv_BlkDesc_GetBlockSizeStored(JobData_pcst->idBlock_uo) - NVM_RB_BLOCK_HEADER_LENGTH;
    uint16 PositionAssociatedData_uo = PositionPlainUserData_uo + NvM_Prv_BlkDesc_GetSize(JobData_pcst->idBlock_uo);

    PositionTag_u16 = *JobData_pcst->IntBuffer_st.UsedSizeInBytes_pu16 - LengthTag_u16;

    // -> copy plain user data and associated data directly after data to be stored
    rba_MemLib_MemCopy(JobData_pcst->IntBuffer_st.Buffer_pu8,
                       &(JobData_pcst->IntBuffer_st.Buffer_pu8[PositionPlainUserData_uo]),
                       NvM_Prv_BlkDesc_GetSize(JobData_pcst->idBlock_uo));

    rba_MemLib_MemCopy(NvM_Prv_BlkDesc_GetDataJobCsmAssociated(JobData_pcst->idBlock_uo),
                       &(JobData_pcst->IntBuffer_st.Buffer_pu8[PositionAssociatedData_uo]),
                       NvM_Prv_BlkDesc_GetLengthJobCsmAssociated(JobData_pcst->idBlock_uo));

    JobCryptoData_pst->inputPrimary_pcu8 = NULL_PTR;
    JobCryptoData_pst->inputPrimaryLength_u32 = 0u;
    JobCryptoData_pst->inputSecondary_pcu8 =
            &JobData_pcst->IntBuffer_st.Buffer_pu8[PositionPlainUserData_uo];
    JobCryptoData_pst->inputSecondaryLength_u32 =   NvM_Prv_BlkDesc_GetSize(JobData_pcst->idBlock_uo)
                                                  + NvM_Prv_BlkDesc_GetLengthJobCsmAssociated(JobData_pcst->idBlock_uo);
    JobCryptoData_pst->inputTertiary_pcu8 = &((JobData_pcst->IntBuffer_st.Buffer_pu8)[PositionTag_u16]);
    JobCryptoData_pst->inputTertiaryLength_u32 = LengthTag_u16;
    JobCryptoData_pst->outputPrimary_pu8 = NULL_PTR;
    JobCryptoData_pst->outputPrimaryLength_pu32 = NULL_PTR;
    JobCryptoData_pst->outputSecondary_pu8 = NULL_PTR;
    JobCryptoData_pst->outputSecondaryLength_pu32 = NULL_PTR;
    JobCryptoData_pst->ResultVerification_puo = &JobResult_pst->Crypto_st.ResultVerification_uo;
    // all other members of jobCryptoData_st are not required to start data encryption
}

#endif  // (NVM_CRYPTO_USED == STD_ON)
