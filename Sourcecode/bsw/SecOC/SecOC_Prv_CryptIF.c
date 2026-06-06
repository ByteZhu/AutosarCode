/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Source file providing cryptographic interface of the SecOC module.
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"
#include "SecOC_Prv.h"

/*
**********************************************************************************************************************
* local declarations
**********************************************************************************************************************
*/
#define SECOC_START_SEC_VAR_HSM_SHARED_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
uint32 SecOC_Prv_locAuthLength_u32 = SECOC_CMAC_AES128v21_BLOCK_LEN;
#define SECOC_STOP_SEC_VAR_HSM_SHARED_INIT_UNSPECIFIED
#include "SecOC_MemMap.h"
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"
/**
 ***********************************************************************************************************************
 * SecOC_Prv_CancelCryptJob
 *
 * \brief Cancel a cryptographic job of csm interface
 *        The job is identified by the job identifier. The handling of a cancel request is the same for a generation
 *        and a verification job.
 *
 * \param[in]   uint32         CsmJobId_u32
 *                             identifier of the csm job
 ***********************************************************************************************************************
*/
void SecOC_Prv_CancelCryptJob(uint32 CsmJobId_u32)
{
    (void)Csm_CancelJob(CsmJobId_u32, CRYPTO_OPERATIONMODE_SINGLECALL);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_AuthGenerate
 *
 * \brief Generates an authenticator, CMAC or signature, for the given input data (data_pu8 and authDataBufferLength_u32)
 *        via the component CSM. The configured cryptographic method is hold in the configuration structure
 *        of the pdu.
 *
 * \param[in]   SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst
 *                             pointer to the context buffer of the PDU for which authentication data should be created
 *
 * \return  Std_ReturnType     See documentation for Csm_MacGenerate
 ***********************************************************************************************************************
*/
/* TRACE[SWS_SecOC_00035] */
Std_ReturnType SecOC_Prv_AuthGenerate(const SecOC_Prv_TxSecuredPduContext_tst *txPduCtx_pst)
{
    Std_ReturnType result_en = E_NOT_OK;

    SecOC_Prv_locAuthLength_u32 = SECOC_CMAC_AES128v21_BLOCK_LEN;

    /* Call mac generation function from component csm */
    result_en = Csm_MacGenerate(txPduCtx_pst->jobId_u32,                            /*  in: job identifier */
                                CRYPTO_OPERATIONMODE_SINGLECALL,                    /*  in: operation mode */
                                txPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,    /*  in: data for authentication */
                                txPduCtx_pst->authDataBufferLength_u32,             /*  in: length of authentication data */
                                txPduCtx_pst->pduConfig_pst->authenticator_pu8,     /* out: generated authenticator */
                                &SecOC_Prv_locAuthLength_u32);                                   /* out: length of generated authenticator */
    return(result_en);
}


/**
 ***********************************************************************************************************************
 * SecOC_Prv_AuthVerify
 *
 * \brief Verify an authenticator, CMAC or signature, for the given input data (data_pu8 and authDataBufferLength_u32)
 *        via the component CSM. The configured cryptographic method is hold in the configuration structure of the pdu.
 *
 * \param[in]   rxPduCtx_pst         Pointer to the context buffer that contains the PDU to be authenticated
 *
 * \return      See documentation for Csm_MacVerify
 ***********************************************************************************************************************
*/
/* TRACE[SWS_SecOC_00047] */
Std_ReturnType SecOC_Prv_AuthVerify(const SecOC_Prv_RxAuthenticPduContext_tst *rxPduCtx_pst)
{
    Std_ReturnType result_en = E_NOT_OK;
    PduIdType idx_cuo = rxPduCtx_pst->pduConfig_pst->authInfoTruncLen_cst.idx_cuo;
    uint16 authInfoTruncLen_u16 = (*rxPduCtx_pst->pduConfig_pst->authInfoTruncLen_cst.value_pacu16)[idx_cuo];

    *(rxPduCtx_pst->pduConfig_pst->macVerifyResult_pen) = CRYPTO_E_VER_NOT_OK;

    /* Call mac verification function from component csm */
    result_en = Csm_MacVerify(
                    rxPduCtx_pst->pduConfig_pst->jobId_u32,              /* in: job identifier */
                    CRYPTO_OPERATIONMODE_SINGLECALL,                     /* in: operation mode */
                    rxPduCtx_pst->pduConfig_pst->authDataBuffer_pu8,     /* in: data for authentication */
                    rxPduCtx_pst->authDataBufferLength_u32,              /* in: length of authentication data */
                    rxPduCtx_pst->pduConfig_pst->authenticator_pu8,      /* in: received authenticator */
                    (uint32)(authInfoTruncLen_u16),                      /* in: length of generated authenticator */
                    rxPduCtx_pst->pduConfig_pst->macVerifyResult_pen);   /* out: verification result */


    return(result_en);
}
#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"
