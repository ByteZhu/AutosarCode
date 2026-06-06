
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
#include "Rte_Dcm.h"
#include "KeyM.h"
#include "Csm.h"
#if (DCM_CFG_DET_SUPPORT_ENABLED != DCM_CFG_OFF)
#include "Det.h"
#endif
#include "Dcm_Prv.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_AuthAsynchOpStatusType_ten Dcm_AuthAsynchOpStatus_en;
static KeyM_CertificateIdType Dcm_AuthKeyMVerifyCertId;
static KeyM_CertificateStatusType Dcm_AuthKeyMVerifyCertResult;
static Crypto_ResultType Dcm_AuthCsmJobResult;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
static uint32 Dcm_AuthCsmJobId_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

Std_ReturnType Dcm_KeyMAsyncCertificateVerifyFinished(KeyM_CertificateIdType certId, KeyM_CertificateStatusType result)
{
    if(DCM_ASYNCH_OPERATION_ACTIVE == Dcm_AuthAsynchOpStatus_en)
    {
        Dcm_AuthKeyMVerifyCertId = certId;
        Dcm_AuthKeyMVerifyCertResult = result;
        Dcm_AuthAsynchOpStatus_en = DCM_ASYNCH_OPERATION_COMPLETED;
    }
    else
    {
        DCM_DET_RUNTIME_ERROR((uint8)DCM_KEYMASYNCCERTIFICATEVERIFYFINISHED_API_ID, DCM_E_INVALID_VALUE);
    }

    return E_OK;
}

void Dcm_CsmAsyncJobFinished(uint32 jobId, Crypto_ResultType result)
{
    if(DCM_ASYNCH_OPERATION_ACTIVE == Dcm_AuthAsynchOpStatus_en)
    {
        Dcm_AuthCsmJobId_u32 = jobId;
        Dcm_AuthCsmJobResult = result;
        Dcm_AuthAsynchOpStatus_en = DCM_ASYNCH_OPERATION_COMPLETED;
    }
    else
    {
        DCM_DET_RUNTIME_ERROR((uint8)DCM_CSMASYNCJOBFINISHED_API_ID, DCM_E_INVALID_VALUE);
    }
}

Std_ReturnType Dcm_Prv_GetCsmJobResult(uint32 jobId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType csmJobResult = E_NOT_OK;
    Dcm_AuthAsynchOpStatus_en = DCM_ASYNCH_OPERATION_INACTIVE;

    if(Dcm_AuthCsmJobId_u32 == jobId)
    {
        if(E_OK == (uint8)Dcm_AuthCsmJobResult)
        {
            csmJobResult = E_OK;
        }
        else if(CRYPTO_E_BUSY == Dcm_AuthCsmJobResult)
        {
            *dataNegRespCode_u8 = DCM_E_BUSYREPEATREQUEST;
        }
        else
        {
            /* For MISRA */
        }
    }
    else
    {
        DCM_DET_RUNTIME_ERROR((uint8)DCM_CSMASYNCJOBFINISHED_API_ID, DCM_E_INVALID_VALUE);
    }

    return csmJobResult;
}

Std_ReturnType Dcm_Prv_GetKeyMVerifyCertificateResult(KeyM_CertificateIdType certId, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType keyMVerifyCertifiateResult = E_NOT_OK;
    Dcm_AuthAsynchOpStatus_en = DCM_ASYNCH_OPERATION_INACTIVE;

    if(Dcm_AuthKeyMVerifyCertId == certId)
    {
        if(KEYM_CERTIFICATE_VALID != Dcm_AuthKeyMVerifyCertResult)
        {
            Dcm_Prv_CertificateInvalidNRCHandling(Dcm_AuthKeyMVerifyCertResult, dataNegRespCode_u8);
        }
        else
        {
            keyMVerifyCertifiateResult = E_OK;
        }
    }
    else
    {
        DCM_DET_RUNTIME_ERROR((uint8)DCM_KEYMASYNCCERTIFICATEVERIFYFINISHED_API_ID, DCM_E_INVALID_VALUE);
    }
    return keyMVerifyCertifiateResult;
}

void Dcm_Prv_CertificateInvalidNRCHandling(KeyM_CertificateStatusType certStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    switch (certStatus)
    {
        /* KEYM_CERTIFICATE_VALID,
         * KEYM_CERTIFICATE_NOT_PARSED,
         * KEYM_CERTIFICATE_PARSED_NOT_VALIDATED,
         * KEYM_CERTIFICATE_NOT_AVAILABLE are not expected here as the control reaches here only
         * if the certificate is set and parsed successfully but it is invalid */

        case KEYM_E_CERTIFICATE_SIGNATURE_FAIL:
        *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSIGNATURE;
        break;

        case KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST:
        *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCHAINOFTRUST;
        break;

        case KEYM_E_CERTIFICATE_INVALID_TYPE:
        *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTYPE;
        break;

        case KEYM_E_CERTIFICATE_INVALID_FORMAT:
        *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDFORMAT;
        break;

        case KEYM_E_CERTIFICATE_INVALID_CONTENT:
        *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSCOPE;
        break;

        case KEYM_E_CERTIFICATE_REVOKED:
        *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCERTIFICATE;
        break;

        case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
        *dataNegRespCode_u8 = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTIMEPERIOD;
        break;

        default:
        /* No specifc NRC set here */
        break;
    }
}

Dcm_AuthAsynchOpStatusType_ten Dcm_Prv_GetAuthAsynchOpStatus(void)
{
    return Dcm_AuthAsynchOpStatus_en;
}

void Dcm_Prv_SetAuthAsynchOpStatus(Dcm_AuthAsynchOpStatusType_ten asynchOpStatus_en)
{
    Dcm_AuthAsynchOpStatus_en = asynchOpStatus_en;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif  /* (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)  */
