#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED == DCM_CFG_ON) && (DCM_CFG_DSP_RDTCSUBFUNC_0x42_ENABLED == DCM_CFG_ON))
#include "Dem.h"
#include "Dcm_Prv.h"

#define DSP_RDTC_SUBFUNCTION0x42_REQLEN                 0x04u
#define RDTC_SUBFUNCTION0x42_MANDATORYRESPONSE_LENGTH   0x05u
#define RDTC_FILTEREDDTCANDSEVERITY_LENGTH              0x05u

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-13429]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16877]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16925]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16878]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16926]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16880]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16927] */
/* MR12 RULE 8.13 VIOLATION: The object addressed by pointer are modified under a particular usecase, and hence should be P2VAR*/
static Std_ReturnType Dcm_Dsp_Prv_GetAvailabilityMaskAndTranslationType(Dcm_MsgContextType *pMsgContext,
                                                                        Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 DTCStatusMask = DCM_DEFAULT_VALUE;
    uint8 DTCSeverityMask = DCM_DEFAULT_VALUE;
    uint8 TranslationTypeResult = DCM_DEFAULT_VALUE;
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;

    /* Fetch DTCStatusAvailabilityMask */
    Result = Dem_GetDTCStatusAvailabilityMask(ClientId_u8,&DTCStatusMask,DEM_DTC_ORIGIN_PRIMARY_MEMORY);

    if(E_OK == Result)
    {
        /* Fetch DTCSeverityAvailabilityMask */
        Result = Dem_GetDTCSeverityAvailabilityMask(ClientId_u8,&DTCSeverityMask);

        if(E_OK == Result)
        {
            /* Fetch DTCFormatIdentifier */
            TranslationTypeResult = Dem_GetTranslationType(ClientId_u8);

            if((RDTC_DEM_DTC_TRANSLATION_SAEJ1939_73 == TranslationTypeResult) ||
               (RDTC_DEM_DTC_TRANSLATION_J2012DA_FORMAT_04 == TranslationTypeResult))
            {
                /* Update response with mandatory response bytes: SubfunctionId, Functional group identifier,
                 * DTCStatusMask, DTCSeverityMask and DTCFormatIdentifier(TranslationTypeResult) */
                pMsgContext->resData[0] = DSP_RDTC_REPORT_WWHOBDDTCBYMASKRECORD;
                pMsgContext->resData[1] = DSP_RDTC_FUNCTIONALGROUPIDENTIFIER;
                pMsgContext->resData[2] = DTCStatusMask;
                pMsgContext->resData[3] = DTCSeverityMask;
                pMsgContext->resData[4] = TranslationTypeResult;

                /* Reset subfunction state to Initial as processing is completed successfully */
                Dcm_DspRDTCSubFunc_en = DSP_RDTC_SFINIT;
            }
            else
            {
                /* Set NRC 0x10 when DTCFormatIdentifier(TranslationTypeResult) is other than 0x02 and 0x04 */
                *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
        }
        else
        {
            /* Set NRC 0x10 when Dem_GetDTCSeverityAvailabilityMask returns E_NOT_OK */
            *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        }
    }
    else
    {
        /* Set NRC 0x10 when Dem_GetDTCStatusAvailabilityMask returns E_NOT_OK */
        *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
    }

    return Result;

}

/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-13429]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-13433]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16929]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16930]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16931]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16847]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16848] */
static Std_ReturnType Dcm_Dsp_Prv_FetchFilteredDTCsAndSeverity(Dcm_MsgContextType *pMsgContext,
                                                               Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    Std_ReturnType Result = DCM_E_PENDING;
    Std_ReturnType NextFilteredDTCandSeverity_Result = E_NOT_OK;
    uint32 ResponseLength_u32 = pMsgContext->resDataLen;
    uint8 DTCFunctionalUnit = DCM_DEFAULT_VALUE;
    uint8 DTCStatus_u8 = DCM_DEFAULT_VALUE;
    uint32 DTC_u32 = DCM_DEFAULT_VALUE;
    Dem_DTCSeverityType DTCSeverity = DCM_DEFAULT_VALUE;
    uint8 Index_u8 = DCM_DEFAULT_VALUE;
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;


    do
    {
    	NextFilteredDTCandSeverity_Result = Dem_GetNextFilteredDTCAndSeverity(ClientId_u8,&DTC_u32,&DTCStatus_u8,&DTCSeverity,&DTCFunctionalUnit);

        if(E_OK == NextFilteredDTCandSeverity_Result)
        {
            if((ResponseLength_u32 + RDTC_FILTEREDDTCANDSEVERITY_LENGTH) <= pMsgContext->resMaxDataLen)
            {
                /* Update response buffer with filetered DTC and severity information */
                pMsgContext->resData[ResponseLength_u32] = DTCSeverity;
                ResponseLength_u32++;
                pMsgContext->resData[ResponseLength_u32] = (uint8)(DTC_u32>>16u);
                ResponseLength_u32++;
                pMsgContext->resData[ResponseLength_u32] = (uint8)(DTC_u32>>8u);
                ResponseLength_u32++;
                pMsgContext->resData[ResponseLength_u32] = (uint8)(DTC_u32);
                ResponseLength_u32++;
                pMsgContext->resData[ResponseLength_u32] = DTCStatus_u8;
                ResponseLength_u32++;
            }
            else
            {
                /* Set NRC 0x14 when response length is greater than maximum response length */
                *dataNegRespCode_u8 = DCM_E_RESPONSETOOLONG;
                Result = E_NOT_OK;
            }

        }
        else if(DEM_PENDING == NextFilteredDTCandSeverity_Result)
        {
            /* Do nothing. Call Dem_GetNextFilteredDTCAndSeverity again in next main cycle */
            Result = DCM_E_PENDING;
            break;
        }
        else if(DEM_NO_SUCH_ELEMENT == NextFilteredDTCandSeverity_Result)
        {
            /* Stop fetching filtered DTCs and severity. Change subfunction state to fetch DTCStatus and severity
             * availability mask and DTCFormat identifier */
            Index_u8 = DCM_CFG_RDTC_MAXNUMDTCREAD;
            Dcm_DspRDTCSubFunc_en = DSP_RDTC_GETAVAILABILITYMASK;
            Result = E_OK;
        }
        else
        {
            /* Set NRC 0x10 when Dem_GetNextFilteredDTCAndSeverity returns E_NOT_OK */
            *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        }

        Index_u8++;

    }while((Index_u8 < DCM_CFG_RDTC_MAXNUMDTCREAD) && (DCM_DEFAULT_VALUE == *dataNegRespCode_u8));

    /* Update response length once fetching filtered DTCs and severity is completed */
    pMsgContext->resDataLen = ResponseLength_u32;

    return Result;

}

/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-13435]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16932]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16933]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16946]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16950] */
static Std_ReturnType Dcm_Dsp_Prv_GetNumberOfFilteredDtcs(Dcm_MsgContextType *pMsgContext,
                                                          Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    Std_ReturnType Result = E_NOT_OK;
    uint32 ResponseLength_u32 = DCM_DEFAULT_VALUE;
    uint16 NumberOfFilteredDTC_u16 = DCM_DEFAULT_VALUE;
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;

    Result = Dem_GetNumberOfFilteredDTC(ClientId_u8,&NumberOfFilteredDTC_u16);

    if(E_OK == Result)
    {
        /* Check whether number of filtered DTCs are not 0x00 */
        if(DCM_DEFAULT_VALUE != NumberOfFilteredDTC_u16)
        {
            ResponseLength_u32 = (uint32)((NumberOfFilteredDTC_u16 * RDTC_FILTEREDDTCANDSEVERITY_LENGTH) + \
                                           RDTC_SUBFUNCTION0x42_MANDATORYRESPONSE_LENGTH);

            if(ResponseLength_u32 <= pMsgContext->resMaxDataLen)
            {
                /* If response length is valid, update subfunction state to fetch filtered DTCs and severity */
                pMsgContext->resDataLen = RDTC_SUBFUNCTION0x42_MANDATORYRESPONSE_LENGTH;
                Dcm_DspRDTCSubFunc_en = DSP_RDTC_SFFILLRESP;
            }
            else
            {
                /* When response length is greater than maximum response length, Dcm shall send NRC 0x14 */
                *dataNegRespCode_u8 = DCM_E_RESPONSETOOLONG;
                Result = E_NOT_OK;
            }
        }
        else
        {
            /* When number of filtered DTC equal to 0x00, Dcm shall send mandatory response without
             * DTCAndSeverityRecord */
            pMsgContext->resDataLen = RDTC_SUBFUNCTION0x42_MANDATORYRESPONSE_LENGTH;
            Dcm_DspRDTCSubFunc_en = DSP_RDTC_GETAVAILABILITYMASK;
        }
    }
    else if(DEM_PENDING == Result)
    {
        /* Do nothing. Call Dem_GetNumberOfFilteredDTC again in next main cycle */
        Result = DCM_E_PENDING;
    }
    else
    {
        /* Set NRC 0x10 when Dem_GetNumberOfFilteredDTC returns E_NOT_OK */
        *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
    }

    return Result;
}

/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-16934]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16935]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-13431]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-16928] */
static Std_ReturnType Dcm_Dsp_Prv_CheckMaskAndSetFilter(Dcm_MsgContextType *pMsgContext,
                                                        Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{
    Std_ReturnType Result = E_OK;
    uint8 DTCStatusMask_u8 = pMsgContext->reqData[2];
    uint8 DTCSeverityMask_u8 = pMsgContext->reqData[3];
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;

    /* Check whether DTCStatusMask and DTCSeverityMask is not 0x00 */
    if((DCM_DEFAULT_VALUE != DTCStatusMask_u8) && (DCM_DEFAULT_VALUE != DTCSeverityMask_u8))
    {
        Result = Dem_SetDTCFilter(ClientId_u8,DTCStatusMask_u8,DEM_DTC_FORMAT_UDS,DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY,
                                  TRUE,DTCSeverityMask_u8,FALSE);

        if(E_OK == Result)
        {
            /* Fetch number of filtered DTCs when Dem_SetDTCFilter returns E_OK */
            Dcm_DspRDTCSubFunc_en = DSP_RDTC_SFCALCNUMDTC;
        }
        else
        {
            /* Set NRC 0x31 when Dem_SetDTCFilter returns E_NOT_OK */
            *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        /* When DTCStatusMask or DTCSeverityMask is 0x00, Dcm shall send mandatory response without
         * DTCAndSeverityRecord. */
        pMsgContext->resDataLen = RDTC_SUBFUNCTION0x42_MANDATORYRESPONSE_LENGTH;
        Dcm_DspRDTCSubFunc_en = DSP_RDTC_GETAVAILABILITYMASK;
    }

    return Result;
}

/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-16868]
 * TRACE[BSW_SWCS_DiagnosticCommunicationManager-13428] */
static Std_ReturnType Dcm_Dsp_Prv_VerifyRequestInfo(Dcm_MsgContextType *pMsgContext,
                                                    Dcm_NegativeResponseCodeType *dataNegRespCode_u8)
{

    Std_ReturnType Result = E_NOT_OK;
    uint8 FunctionalGroupIdentifier_u8 = pMsgContext->reqData[1];
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;

    if(DSP_RDTC_SUBFUNCTION0x42_REQLEN == pMsgContext->reqDataLen)
    {
        /* Check whether Functional group identifer is 0x33 */
        if(DSP_RDTC_FUNCTIONALGROUPIDENTIFIER == FunctionalGroupIdentifier_u8)
        {
            Result = Dcm_Dsp_Prv_CheckMaskAndSetFilter(pMsgContext,dataNegRespCode_u8);
        }
        else
        {
            /* Set NRC 0x31 when Functional group identifier is not equal to 0x33 */
            *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        /* Set NRC 0x13 when the request length of subfunction 0x42 is not valid */
        *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }

    return Result;
}

Std_ReturnType Dcm_Dsp_ReportWWHOBDDTCByMaskRecord(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,
                                                   Dcm_NegativeResponseCodeType * dataNegRespCode_u8)
{

    Std_ReturnType Result = E_NOT_OK;
    *dataNegRespCode_u8 = DCM_DEFAULT_VALUE;
    (void)OpStatus;

    if(DSP_RDTC_SFINIT == Dcm_DspRDTCSubFunc_en)
    {
        Result = Dcm_Dsp_Prv_VerifyRequestInfo(pMsgContext,dataNegRespCode_u8);
    }

    if(DSP_RDTC_SFCALCNUMDTC == Dcm_DspRDTCSubFunc_en)
    {
        Result = Dcm_Dsp_Prv_GetNumberOfFilteredDtcs(pMsgContext,dataNegRespCode_u8);
    }

    if(DSP_RDTC_SFFILLRESP == Dcm_DspRDTCSubFunc_en)
    {
        Result = Dcm_Dsp_Prv_FetchFilteredDTCsAndSeverity(pMsgContext,dataNegRespCode_u8);
    }

    if(DSP_RDTC_GETAVAILABILITYMASK == Dcm_DspRDTCSubFunc_en)
    {
        Result = Dcm_Dsp_Prv_GetAvailabilityMaskAndTranslationType(pMsgContext,dataNegRespCode_u8);
    }

    if(DCM_DEFAULT_VALUE != *dataNegRespCode_u8)
    {
        /* Reset state in case NRC is set */
        Dcm_DspRDTCSubFunc_en = DSP_RDTC_SFINIT;
        Result = E_NOT_OK;
    }

    return Result;

}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif
