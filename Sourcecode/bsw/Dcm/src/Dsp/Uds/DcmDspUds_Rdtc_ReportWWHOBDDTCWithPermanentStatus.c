
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if(DCM_CFG_DSP_RDTCSUBFUNC_0x55_ENABLED != DCM_CFG_OFF)
#include "Dem.h"
#include "Dcm_Prv.h"

#define DSP_RDTC_55_MANDATORYRESPONSE_LENGTH   0x04U
#define RDTC_FILTEREDDTCANDSTATUS_LENGTH       0x04U
#define DSP_RDTC_55_SUBFUNCID    0x55U

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/***********************************************************************************************************************
 Function name    : Dcm_Dsp_Prv_55_RequestValidation
 Description      : Function is used to validate the request with below parameters
 * Request length
 * Functional group ID in request
 Parameter        : pMsgContext
                    dataNegRespCode_u8
 Return value     : void
 **********************************************************************************************************************/
/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-16869]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16839]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16840] */
static void Dcm_Dsp_Prv_55_RequestValidation(const Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    /* Initialize assuming no NRC */
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;

    /* Check if request length is correct, Request length should be 0x02(excluding SID)*/
    if(DSP_RDTC_55_REQLEN == pMsgContext->reqDataLen)
    {
        /* Functional group ID is incorrect, functional group ID should be 0x33 */
        if(DSP_RDTC_FUNCTIONALGROUPIDENTIFIER  != pMsgContext->reqData[1])
        {
            /* Send NRC 0x31(Request out of Range), if functional group ID is invalid*/
            *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    /* Request Length is incorrect */
    else
    {
        /* Send NRC 0x13(Invalid Format), if request length is invalid*/
        *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }

}

/***********************************************************************************************************************
 Function name    : Dcm_Dsp_Prv_55_SetDTCFilter
 Description      : The interface shall set the DTC filter to read DTC of permanent faults
 Parameter        : pMsgContext
                    dataNegRespCode_u8
 Return value     : void
 **********************************************************************************************************************/
/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-16843]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16923]
 */
static void Dcm_Dsp_Prv_55_SetDTCFilter(Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    Std_ReturnType retVal_u8;    /* variable to store the return value of API Dem_SetDTCFilter */

    /* Initialize assuming no NRC */
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;

    /* Call API to set the DTC filter to read DTC of permanent faults */
    retVal_u8 = Dem_SetDTCFilter(ClientId_u8, 0x00, DEM_DTC_FORMAT_UDS,
            DEM_DTC_ORIGIN_PERMANENT_MEMORY,FALSE,0x00,FALSE);

    /* If DTC filter not set successfully */
    if(E_OK != retVal_u8)
    {
        /* Send NRC 0x31(Request out of Range) */
        *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Dsp_Prv_55_FetchRespLen
 Description      : This function shall fetch number of Permanent faults
 Parameter        : Opstatus
                    pMsgContext
                    dataNegRespCode_u8
 Return value     : void
 **********************************************************************************************************************/
/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-16845]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16943]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16864]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16862]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16938]
 */
static Std_ReturnType Dcm_Dsp_Prv_55_FetchRespLen(Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    uint16 NumberOfFilteredDTC_u16;                   /* Number of permanent faluts */
    uint16 RespLen_u16;                   /* Response length */
    Std_ReturnType retVal_u8 = E_OK;      /* return value    */

    /* Initialize assuming no NRC */
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;

    /* Call API to fetch number of Permanent faults */
    retVal_u8 = Dem_GetNumberOfFilteredDTC(ClientId_u8, &NumberOfFilteredDTC_u16);

    /* If DTC selected successfully */
    switch (retVal_u8)
    {
        case E_OK:
        {
            /* Check if any Permanent faults exist */
            if(NumberOfFilteredDTC_u16 > 0U)
            {
                /* Calculate response length  */
                RespLen_u16 = (NumberOfFilteredDTC_u16 * RDTC_FILTEREDDTCANDSTATUS_LENGTH) +
                        DSP_RDTC_55_MANDATORYRESPONSE_LENGTH;

                /* Check if available response buffer size is sufficient to fill the response */
                if(RespLen_u16 > pMsgContext->resMaxDataLen)
                {
                    /* Send NRC 0x14(Response too long) */
                    *dataNegRespCode_u8 = DCM_E_RESPONSETOOLONG;

                    retVal_u8 = E_NOT_OK;
                }
                else
                {
                    /* Update response length */
                    pMsgContext->resDataLen = NumberOfFilteredDTC_u16 * RDTC_FILTEREDDTCANDSTATUS_LENGTH;
                }
            }
            break;
        }

        case DEM_PENDING:
        {
            /* return pending and call again during next call of Dcm_MainFunction()  */
            retVal_u8 = DCM_E_PENDING;
            break;

        }

        default:
        {
            /* Send NRC 0x10(General Reject)  */
            *dataNegRespCode_u8 = DCM_E_GENERALREJECT;

            retVal_u8 = E_NOT_OK;
            break;
        }
    }

    return retVal_u8;

}


/***********************************************************************************************************************
 Function name    : Dcm_Dsp_Prv_55_UpdtMandResponse
 Description      : This function shall update mandatory bytes for positive response
 Parameter        : pMsgContext
                    dataNegRespCode_u8
 Return value     : void
 **********************************************************************************************************************/
/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-16883]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16846]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16921]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16922]
 */
static void Dcm_Dsp_Prv_55_UpdtMandResponse(Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    uint8      dataStatusAvailMask_u8;        /* Variable to store status availability mask */
    uint8      dataTranslationTyp_u8;         /* Variable to store translation type         */

    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;  /* Initialise negative response as 0x00 */

    /* Call API to read status availability mask */
    if(E_OK == Dem_GetDTCStatusAvailabilityMask(ClientId_u8,&dataStatusAvailMask_u8, DEM_DTC_ORIGIN_PRIMARY_MEMORY))
    {
        /* Get the DTC Format Identifier and fill into the response buffer */
        dataTranslationTyp_u8 = Dem_GetTranslationType(ClientId_u8);

        /* Check if TranslationType is 0x02 or 0x04, as these are the only valid values */
        if((dataTranslationTyp_u8 == RDTC_DEM_DTC_TRANSLATION_SAEJ1939_73) ||
                (dataTranslationTyp_u8 == RDTC_DEM_DTC_TRANSLATION_J2012DA_FORMAT_04))
        {
            /* Update subfunction ID 0x55 */
            pMsgContext->resData[0] = DSP_RDTC_55_SUBFUNCID;

            /* Update Functional group ID */
            pMsgContext->resData[1] = DSP_RDTC_FUNCTIONALGROUPIDENTIFIER;

            /* Update Status availability Mask */
            pMsgContext->resData[2] = dataStatusAvailMask_u8;

            /* Get the DTC Format Identifier and fill into the response buffer */
            pMsgContext->resData[3] = dataTranslationTyp_u8;

            /* Increment response length by 4 */
            pMsgContext->resDataLen = pMsgContext->resDataLen + DSP_RDTC_55_MANDATORYRESPONSE_LENGTH;
        }
        else
        {
            /* Send NRC 0x10(General Reject) */
            *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
        }
    }
    else
    {
        /* Send NRC 0x10(General Reject) */
        *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
    }
}

/***********************************************************************************************************************
 Function name    : Dcm_Dsp_Prv_55_UpdtResponse
 Description      : This function shall update all permanent DTCs along with it's status
 Parameter        : pMsgContext
                    dataNegRespCode_u8
 Return value     : void
 **********************************************************************************************************************/
/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-16884]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16940]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16941]
 */
static Std_ReturnType Dcm_Dsp_Prv_55_UpdtResponse(const Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    Std_ReturnType  dataretGetNextFiltDTC_u8;   /* return type of Dem interface */
    Std_ReturnType  dataretVal_u8;              /* return type of this interface */
    uint32 bufidx_u32;                          /* Response buffer index */
    uint32 dataDTC_u32;                         /* Variable to read DTCs */
    uint8 stDTCStatus_u8;                       /* Variable to read status of DTC */

    dataretVal_u8 = E_OK;

    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;  /* Initialise negative response as 0x00 */

    bufidx_u32 = DSP_RDTC_55_MANDATORYRESPONSE_LENGTH;

    do
    {
        /* Call Dem API to fetch DTC and status */
        dataretGetNextFiltDTC_u8 = Dem_GetNextFilteredDTC(ClientId_u8,
                &dataDTC_u32,
                &stDTCStatus_u8);

        switch(dataretGetNextFiltDTC_u8)
        {
            case E_OK:
            {
                /* Fill the response buffer with DTC and status */
                pMsgContext->resData[bufidx_u32] = (uint8)(dataDTC_u32>>16u);
                bufidx_u32++;
                pMsgContext->resData[bufidx_u32] = (uint8)(dataDTC_u32>>8u);
                bufidx_u32++;
                pMsgContext->resData[bufidx_u32] = (uint8)(dataDTC_u32);
                bufidx_u32++;
                pMsgContext->resData[bufidx_u32] = stDTCStatus_u8;
                bufidx_u32++;

                break;
            }
            case DEM_PENDING:
            {
                /* return pending and call again during next call of Dcm_MainFunction()  */
                dataretVal_u8 = DCM_E_PENDING;
                break;
            }
            case DEM_NO_SUCH_ELEMENT:
            {
                /* Dem interface returns DEM_NO_SUCH_ELEMENT indicating copy of all DTCs is complete, hence
                 * update return value as E_OK */
                dataretVal_u8 = E_OK;
                break;
            }

            default :
            {
                /* Send NRC 0x10(General Reject)  */
                *dataNegRespCode_u8 = DCM_E_GENERALREJECT;

                /* Return E_NOT_OK as NRC is set */
                dataretVal_u8 = E_NOT_OK;
                break;
            }
        }
    }while(dataretGetNextFiltDTC_u8 == E_OK);

    return dataretVal_u8;

}

/***********************************************************************************************************************
 Function name    : Dcm_Dsp_RdtcReportWWHOBDDTCWithPermanentStatus
 Description      : API to report Permanent DTCs.
 Parameter        : Opstatus
                    pMsgContext
                    dataNegRespCode_u8
 Return value     : E_OK
                    E_NOT_OK
                    DCM_E_PENDING

 **********************************************************************************************************************/
Std_ReturnType Dcm_Dsp_RdtcReportWWHOBDDTCWithPermanentStatus(Dcm_SrvOpStatusType OpStatus,
        Dcm_MsgContextType * pMsgContext,
        Dcm_NegativeResponseCodeType * dataNegRespCode_u8)
{
    Std_ReturnType        retVal_u8;

    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;  /* Initialise negative response as 0x00 */
    retVal_u8           = E_OK;               /* Assume positive response and update return as E_OK */

    /* Check if Opstatus is Initial */
    if(OpStatus == DCM_INITIAL)
    {
        /* call function to validate request */
        Dcm_Dsp_Prv_55_RequestValidation(pMsgContext, dataNegRespCode_u8);

        /* If request is valid, call function to set DTC filter */
        if(*dataNegRespCode_u8 == 0u)
        {
            Dcm_Dsp_Prv_55_SetDTCFilter(dataNegRespCode_u8);
        }
    }

    /* If Opstatus is DCM_PENDING Dem_GetNumberOfFilteredDTC  */
    if((OpStatus == DCM_PENDING) || (*dataNegRespCode_u8 == 0u))
    {
        retVal_u8 = Dcm_Dsp_Prv_55_FetchRespLen(pMsgContext, dataNegRespCode_u8);

        if(retVal_u8 == E_OK)
        {
            /* Call API to update mandatory response bytes */
            Dcm_Dsp_Prv_55_UpdtMandResponse(pMsgContext, dataNegRespCode_u8);

            if((*dataNegRespCode_u8 == 0u) && (pMsgContext->resDataLen > RDTC_FILTEREDDTCANDSTATUS_LENGTH))
            {
                retVal_u8 = Dcm_Dsp_Prv_55_UpdtResponse(pMsgContext, dataNegRespCode_u8);
            }
        }
    }

    if(*dataNegRespCode_u8 != 0u)
    {
        retVal_u8 = E_NOT_OK;
    }

    /* Update the return value */
    return retVal_u8;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif


