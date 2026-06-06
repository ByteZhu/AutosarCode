
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if(DCM_CFG_DSP_ROUTINECONTROL_ENABLED == DCM_CFG_ON)
#include "rba_BswSrv.h"
#include "Dcm_Prv.h"
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
#define DCM_ROUTINE_SUBFUNCTION_INDEX                       0u
#define DCM_ROUTINE_ID_MSB_INDEX                            1u
#define DCM_ROUTINE_ID_LSB_INDEX                            2u
#define DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX       3u
#define DCM_ROUTINE_STATUS_OPTION_RECORD_START_INDEX        3u

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
static Std_ReturnType Dcm_RCInitial (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCProcess (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static void Dcm_RCCancel (const Dcm_MsgContextType* pMsgContext);
static Std_ReturnType Dcm_RCVerification (const Dcm_MsgContextType* pMsgContext, uint16* routineCommonIndex_pu16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCVerificationPart1(const Dcm_MsgContextType* pMsgContext, uint16* routineCommonIndex_pu16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCVerificationPart2(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCVerificationPart3(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCVerificationPart4(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCMinimumLengthCheck(Dcm_MsgLenType reqDataLen, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCIsRoutineSupported(uint16 routineID_u16, uint16* routineCommonIndex_pu16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCIsRoutineAvailable(uint16 routineID_u16, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCSessionCheck(uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCAuthenticationCheck(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCSecurityCheck(uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static void Dcm_RCGetRoutineSubFunctionConfig(uint8 subFunction_u8, uint16 routineCommonIndex_u16, const Dcm_RoutineSubFunctionConfigType_tst** routineSubFunctionConfig_ppst);
static Std_ReturnType Dcm_RCTotalLengthCheck(Dcm_MsgLenType reqDataLen, const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCControlOptionRecordCheck(const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCUserModeConditionCheck(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCModeConditionCheck(uint8 subFunction_u8, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCSequenceCheck(uint8 subFunction_u8, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static Std_ReturnType Dcm_RCGetRoutineCommonIndex(uint16* routineCommonIndex_pu16);
static void Dcm_RCSetCurrentlyProcessedRoutine(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16);
static Std_ReturnType Dcm_RCProcessRoutineResult(Std_ReturnType routineResult, Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static void Dcm_RCRoutineHandlerNRC(Std_ReturnType routineResult, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8);
static void Dcm_RCSetDataInVar(const Dcm_MsgContextType* pMsgContext, uint16 minControlOptionRecordSize_u16);
static void Dcm_RCCopyRequestToDataIn(const Dcm_MsgContextType* pMsgContext, const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst);
static void Dcm_RCCopyDataOutToResponse(Dcm_MsgContextType* pMsgContext, const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst);




/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static const uint8 Dcm_RoutineMinRequestLength_cu8 = 3u;
static const uint8 Dcm_RCNoNRC_cu8 = 0u;
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
static boolean Dcm_IsRoutineProcessingActive_b;
static boolean Dcm_IsRoutineConfirmationActive_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"
static uint16 Dcm_CurrentlyProcessedRID_u16;
static uint16 Dcm_RoutineCommonIndex_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_RoutineStatusType_ten Dcm_RoutineStatus_aen[DCM_CFG_NUM_TOTAL_ROUTINES];
static Dcm_OpStatusType Dcm_RoutineHanlderOpStatus;
uint8 * Dcm_RCDataOutVar_pau8;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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

void Dcm_Prv_DspRC_Init (void)
{
    /* NRC_u8 is not used because the routine is cancelled and so no response is required */
    Dcm_NegativeResponseCodeType NRC_u8;
    uint16 routineCommonIndex_u16;

    for(routineCommonIndex_u16 = 0; routineCommonIndex_u16 < DCM_CFG_NUM_TOTAL_ROUTINES; routineCommonIndex_u16++)
    {
        if(DCM_ROUTINE_STOP_PENDING == Dcm_RoutineStatus_aen[routineCommonIndex_u16])
        {
            /* This is needed here to set the correct Routine Id, because the application
             * can call Dcm_GetActiveRid() to get the Routine Id during the cancelling of the routine */
            Dcm_RCSetCurrentlyProcessedRoutine(NULL_PTR, routineCommonIndex_u16);

            /* The return value is ignored because the routine is cancelled and so no response is required */
            (void)(*Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].routineHandler_pfct)((uint8)DCM_STOP_ROUTINE, DCM_CANCEL, &NRC_u8);
            Dcm_IsRoutineProcessingActive_b = FALSE;
        }

        /* Set to IDLE, because this is a new diagnostic session */
        Dcm_RoutineStatus_aen[routineCommonIndex_u16] = DCM_ROUTINE_IDLE;
    }
}

void Dcm_Prv_RC_Mainfunction(void)
{
    /* NRC_u8 is not used because the routine is cancelled and so no response is required */
    Dcm_NegativeResponseCodeType NRC_u8;
    uint16 routineCommonIndex_u16;

    for(routineCommonIndex_u16 = 0; routineCommonIndex_u16 < DCM_CFG_NUM_TOTAL_ROUTINES; routineCommonIndex_u16++)
    {
        if(DCM_ROUTINE_STOP_PENDING == Dcm_RoutineStatus_aen[routineCommonIndex_u16])
        {
            /* This is needed here to set the correct Routine Id, because the application
             * can call Dcm_GetActiveRid() to get the Routine Id during the cancelling of the routine */
            Dcm_RCSetCurrentlyProcessedRoutine(NULL_PTR, routineCommonIndex_u16);

            /* The return value is ignored because the routine is cancelled and so no response is required */
            (void)(*Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].routineHandler_pfct)((uint8)DCM_STOP_ROUTINE, DCM_CANCEL, &NRC_u8);
            Dcm_IsRoutineProcessingActive_b = FALSE;

            /* Set to STARTED, because the STOP request is cancelled for an already STARTED routine */
            Dcm_RoutineStatus_aen[routineCommonIndex_u16] = DCM_ROUTINE_STARTED;
        }
    }
}

Std_ReturnType Dcm_Prv_DspRoutineControl (Dcm_SrvOpStatusType OpStatus, Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType serviceResult = E_NOT_OK;

    switch(OpStatus)
    {
        case DCM_CANCEL:
        Dcm_RCCancel(pMsgContext);
        serviceResult = E_OK;
        break;

        case DCM_INITIAL:
        serviceResult = Dcm_RCInitial(pMsgContext, dataNegRespCode_u8);
        if (serviceResult == E_OK)
        {
            Dcm_SrvOpstatus_u8= DCM_PROCESSSERVICE;
            /*MR12 RULE 16.3 VIOLATION: No Break statement here as the PROCESSSERVICE shall continue immediately after the DCM_INITIAL is completed sucessfully*/
        }
        else
        {
            break;
        }
        /*MR12 RULE 16.3 VIOLATION: No Break statement here as the PROCESSSERVICE shall continue immediately after the DCM_INITIAL is completed sucessfully*/
        case DCM_PROCESSSERVICE:
        serviceResult = Dcm_RCProcess(pMsgContext, dataNegRespCode_u8);
        break;

        default:
        /*default should not happen*/
        break;
    }

    return serviceResult;
}

static Std_ReturnType Dcm_RCInitial (const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType initialResult = E_NOT_OK;
    uint16 routineCommonIndex_u16 = 0;
    const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst = NULL_PTR;
    uint8 subFunction_u8 = pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX];

    if(E_OK == Dcm_RCVerification(pMsgContext, &routineCommonIndex_u16, dataNegRespCode_u8))
    {
        Dcm_RCSetCurrentlyProcessedRoutine(pMsgContext, routineCommonIndex_u16);
        Dcm_RCGetRoutineSubFunctionConfig(subFunction_u8, routineCommonIndex_u16, &routineSubFunctionConfig_pst);

        /* Else part handling is not required as the control will never reach there if the Dcm_RCVerification() returns E_OK.
         * This check is only done for robustness purpose. */
        if(NULL_PTR != routineSubFunctionConfig_pst)
        {
            Dcm_RCCopyRequestToDataIn(pMsgContext, routineSubFunctionConfig_pst);
            Dcm_RCDataOutVar_pau8 = &(pMsgContext->resData[DCM_ROUTINE_STATUS_OPTION_RECORD_START_INDEX+routineSubFunctionConfig_pst->minStatusOptionRecordSize_u16]);
            Dcm_RoutineHanlderOpStatus = DCM_INITIAL;
            initialResult = E_OK;
        }

    }
    return initialResult;
}

static Std_ReturnType Dcm_RCProcess (Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType processResult = E_NOT_OK;
    uint16 routineCommonIndex_u16;
    uint8 subFunction_u8 = pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX];

    if(E_OK == Dcm_RCGetRoutineCommonIndex(&routineCommonIndex_u16))
    {
        processResult = (*Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].routineHandler_pfct)(subFunction_u8, Dcm_RoutineHanlderOpStatus, dataNegRespCode_u8);

        if(DCM_E_PENDING == processResult)
        {
            Dcm_RoutineHanlderOpStatus = DCM_PENDING;
        }
        else if(DCM_E_FORCE_RCRRP == processResult)
        {
            Dcm_RoutineHanlderOpStatus = DCM_FORCE_RCRRP_OK;
        }
        else
        {
            processResult = Dcm_RCProcessRoutineResult(processResult, pMsgContext, routineCommonIndex_u16, dataNegRespCode_u8);
        }
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
    }
    return processResult;
}

static void Dcm_RCCancel (const Dcm_MsgContextType* pMsgContext)
{
    uint16 routineCommonIndex_u16;
    uint8 subFunction_u8 = pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX];
    /* NRC_u8 is not used because the routine is cancelled and so no response is required */
    Dcm_NegativeResponseCodeType NRC_u8;

    if(E_OK == Dcm_RCGetRoutineCommonIndex(&routineCommonIndex_u16))
    {
        /* This is needed here to set the correct Routine Id, because the application
         * can call Dcm_GetActiveRid() to get the Routinr Id during the cancelling of the routine */
        Dcm_RCSetCurrentlyProcessedRoutine(NULL_PTR, routineCommonIndex_u16);

        /* The return value is ignored because the routine is cancelled and so no response is required */
        (void)(*Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].routineHandler_pfct)(subFunction_u8, DCM_CANCEL, &NRC_u8);
        Dcm_IsRoutineProcessingActive_b = FALSE;
    }
}

static Std_ReturnType Dcm_RCVerification (const Dcm_MsgContextType* pMsgContext, uint16* routineCommonIndex_pu16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType verificationResult = E_NOT_OK;

    if(E_OK == Dcm_RCVerificationPart1(pMsgContext, routineCommonIndex_pu16, dataNegRespCode_u8))
    {
        if(E_OK == Dcm_RCVerificationPart2(pMsgContext, *routineCommonIndex_pu16, dataNegRespCode_u8))
        {
            if(E_OK == Dcm_RCVerificationPart3(pMsgContext, *routineCommonIndex_pu16, dataNegRespCode_u8))
            {
                if(E_OK == Dcm_RCVerificationPart4(pMsgContext, *routineCommonIndex_pu16, dataNegRespCode_u8))
                {
                    verificationResult = E_OK;
                }
            }
        }
    }
    return verificationResult;
}

static Std_ReturnType Dcm_RCVerificationPart1(const Dcm_MsgContextType* pMsgContext, uint16* routineCommonIndex_pu16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType verificationPart1Result = E_NOT_OK;
    uint16 routineID_u16;

    routineID_u16 = ((uint16)pMsgContext->reqData[DCM_ROUTINE_ID_MSB_INDEX] <<8);
    routineID_u16 = (routineID_u16 | (uint16)pMsgContext->reqData[DCM_ROUTINE_ID_LSB_INDEX]);

    if(E_OK == Dcm_RCMinimumLengthCheck(pMsgContext->reqDataLen, dataNegRespCode_u8))
    {
        if(E_OK == Dcm_RCIsRoutineSupported(routineID_u16, routineCommonIndex_pu16, dataNegRespCode_u8))
        {
            if(E_OK == Dcm_RCIsRoutineAvailable(routineID_u16, *routineCommonIndex_pu16, dataNegRespCode_u8))
            {
                verificationPart1Result = E_OK;
            }
        }
    }
    return verificationPart1Result;
}

static Std_ReturnType Dcm_RCVerificationPart2(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType verificationPart2Result = E_NOT_OK;

    if(E_OK == Dcm_RCSessionCheck(routineCommonIndex_u16, dataNegRespCode_u8))
    {
        if(E_OK == Dcm_RCAuthenticationCheck(pMsgContext, routineCommonIndex_u16, dataNegRespCode_u8))
        {
            if(E_OK == Dcm_RCSecurityCheck(routineCommonIndex_u16, dataNegRespCode_u8))
            {
                verificationPart2Result = E_OK;
            }
        }
    }
    return verificationPart2Result;
}

static Std_ReturnType Dcm_RCVerificationPart3(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType verificationPart3Result = E_NOT_OK;
    uint8 subFunction_u8 = pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX];
    const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst = NULL_PTR;

    Dcm_RCGetRoutineSubFunctionConfig(subFunction_u8, routineCommonIndex_u16, &routineSubFunctionConfig_pst);

    if(NULL_PTR != routineSubFunctionConfig_pst)
    {
        if(E_OK == Dcm_RCTotalLengthCheck(pMsgContext->reqDataLen, routineSubFunctionConfig_pst, dataNegRespCode_u8))
        {
            if(pMsgContext->reqDataLen > Dcm_RoutineMinRequestLength_cu8)
            {
                if(E_OK == Dcm_RCControlOptionRecordCheck(pMsgContext, dataNegRespCode_u8))
                {
                    verificationPart3Result = E_OK;
                }
            }
            else
            {
                verificationPart3Result = E_OK;
            }
        }
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }

    return verificationPart3Result;
}

static Std_ReturnType Dcm_RCVerificationPart4(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType verificationPart4Result = E_NOT_OK;
    uint8 subFunction_u8 = pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX];

    if(E_OK == Dcm_RCUserModeConditionCheck(pMsgContext, routineCommonIndex_u16, dataNegRespCode_u8))
    {
        if(E_OK == Dcm_RCModeConditionCheck(subFunction_u8, routineCommonIndex_u16, dataNegRespCode_u8))
        {
            if(E_OK == Dcm_RCSequenceCheck(subFunction_u8, routineCommonIndex_u16, dataNegRespCode_u8))
            {
                verificationPart4Result = E_OK;
            }
        }
    }
    return verificationPart4Result;
}

static Std_ReturnType Dcm_RCMinimumLengthCheck(Dcm_MsgLenType reqDataLen, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType minimumLengthCheckResult = E_NOT_OK;

    if(reqDataLen >= Dcm_RoutineMinRequestLength_cu8)
    {
        minimumLengthCheckResult = E_OK;
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    return minimumLengthCheckResult;
}

static Std_ReturnType Dcm_RCIsRoutineSupported(uint16 routineID_u16, uint16* routineCommonIndex_pu16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType isRoutineSupportedResult = E_NOT_OK;
#if(DCM_CFG_NUM_NORMAL_ROUTINES > 0)
    uint16 normalRoutineIndex;
#endif
#if(DCM_CFG_NUM_RANGE_ROUTINES > 0)
    uint16 rangeRoutineIndex;
#endif

#if(DCM_CFG_NUM_NORMAL_ROUTINES > 0)
    for(normalRoutineIndex=0; normalRoutineIndex < DCM_CFG_NUM_NORMAL_ROUTINES; normalRoutineIndex++)
    {
        if(Dcm_Cfg_NormalRoutineConfig_cast[normalRoutineIndex].dataRId_u16 == routineID_u16)
        {
            *routineCommonIndex_pu16 = Dcm_Cfg_NormalRoutineConfig_cast[normalRoutineIndex].routineCommonIndex_u16;
            isRoutineSupportedResult = E_OK;
            break;
        }
    }
#endif

#if(DCM_CFG_NUM_RANGE_ROUTINES > 0)
    if(E_NOT_OK == isRoutineSupportedResult)
    {
        for(rangeRoutineIndex=0; rangeRoutineIndex < DCM_CFG_NUM_RANGE_ROUTINES; rangeRoutineIndex++)
        {
            if((routineID_u16 >= Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex].routineRangeLowerLimit_u16) &&
                    (routineID_u16 <= Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex].routineRangeUpperLimit_u16))
            {
                *routineCommonIndex_pu16 = Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex].routineCommonIndex_u16;
                isRoutineSupportedResult = E_OK;
                break;
            }
        }
    }
#endif

    if(E_NOT_OK == isRoutineSupportedResult)
    {
        *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
    }

#if((DCM_CFG_NUM_NORMAL_ROUTINES == 0u) && (DCM_CFG_NUM_RANGE_ROUTINES == 0u))
    (void)routineID_u16;
    (void)routineCommonIndex_pu16;
#endif

    return isRoutineSupportedResult;
}

static Std_ReturnType Dcm_RCIsRoutineAvailable(uint16 routineID_u16, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType isRoutineAvailableResult = E_OK;
#if(DCM_CFG_NUM_NORMAL_ROUTINES > 0)
    uint16 normalRoutineIndex_u16;
#endif
#if(DCM_CFG_NUM_RANGE_ROUTINES > 0)
    uint16 rangeRoutineIndex_u16;
#endif

#if(DCM_CFG_NUM_NORMAL_ROUTINES > 0)
    if(routineCommonIndex_u16 < DCM_CFG_NUM_NORMAL_ROUTINES)
    {
        normalRoutineIndex_u16 = routineCommonIndex_u16;

        if(NULL_PTR != Dcm_Cfg_NormalRoutineConfig_cast[normalRoutineIndex_u16].isNormalRoutineAvailable_pfct)
        {
            isRoutineAvailableResult = (*Dcm_Cfg_NormalRoutineConfig_cast[normalRoutineIndex_u16].isNormalRoutineAvailable_pfct)(routineID_u16);
        }
    }
    (void)dataNegRespCode_u8;
#endif

#if(DCM_CFG_NUM_RANGE_ROUTINES > 0)
    if(routineCommonIndex_u16 >= DCM_CFG_NUM_NORMAL_ROUTINES)
    {
        rangeRoutineIndex_u16 = (uint16)(routineCommonIndex_u16 - DCM_CFG_NUM_NORMAL_ROUTINES);

        if((NULL_PTR != Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex_u16].isRangeRoutineAvailable_pfct) && (TRUE == Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex_u16].routineRangeHasGaps_b))
        {
            isRoutineAvailableResult = (*Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex_u16].isRangeRoutineAvailable_pfct)(routineID_u16, dataNegRespCode_u8);

        }
    }
#endif

    if((E_OK != isRoutineAvailableResult)&&(Dcm_RCNoNRC_cu8 == *dataNegRespCode_u8))
    {
        *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
    }

#if((DCM_CFG_NUM_NORMAL_ROUTINES == 0u) && (DCM_CFG_NUM_RANGE_ROUTINES == 0u))
    (void)routineID_u16;
    (void)routineCommonIndex_u16;
#endif

    return isRoutineAvailableResult;
}

static Std_ReturnType Dcm_RCSessionCheck(uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType sessionCheckResult = E_NOT_OK;

    if((Dcm_DsldGetActiveSessionMask_u32() & Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].allowedSessions_u32) != 0u)
    {
        sessionCheckResult = E_OK;
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
    }
    return sessionCheckResult;
}

static Std_ReturnType Dcm_RCAuthenticationCheck(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType authenticationCheckResult = E_NOT_OK;

    if(E_OK == Dcm_Prv_CheckAccessRights(DCM_CHECK_RID, Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].allowedRoles_u32, pMsgContext, dataNegRespCode_u8))
    {
        authenticationCheckResult = E_OK;
    }

    return authenticationCheckResult;
}

static Std_ReturnType Dcm_RCSecurityCheck(uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType securityCheckResult = E_NOT_OK;

    if((Dcm_DsldGetActiveSecurityMask_u32() & Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].allowedSecurityLevels_u32) != 0u)
    {
        securityCheckResult = E_OK;
    }
    else
    {
        *dataNegRespCode_u8 = DCM_E_SECURITYACCESSDENIED;
    }
    return securityCheckResult;
}

static void Dcm_RCGetRoutineSubFunctionConfig(uint8 subFunction_u8, uint16 routineCommonIndex_u16, const Dcm_RoutineSubFunctionConfigType_tst** routineSubFunctionConfig_ppst)
{
    switch(subFunction_u8)
    {
        case (uint8)DCM_START_ROUTINE:
        {
            *routineSubFunctionConfig_ppst = Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].startConfig_pst;
            break;
        }
        case (uint8)DCM_STOP_ROUTINE:
        {
            *routineSubFunctionConfig_ppst = Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].stopConfig_pst;
            break;
        }
        case (uint8)DCM_REQUEST_RESULTS:
        {
            *routineSubFunctionConfig_ppst = Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].requestResultsConfig_pst;
            break;
        }
        default:
        {
            *routineSubFunctionConfig_ppst = NULL_PTR;
            break;
        }
    }
}

static Std_ReturnType Dcm_RCTotalLengthCheck(Dcm_MsgLenType reqDataLen, const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType totalLengthCheckResult = E_NOT_OK;
    uint16 actualContolOptionRecordSize_u16;

    /* reqDataLen will be at least == DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX when control is here */
    actualContolOptionRecordSize_u16 = (uint16)(reqDataLen - DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX);

    if(TRUE == routineSubFunctionConfig_pst->isControlOptionRecordSizeFixed_b)
    {
        if(actualContolOptionRecordSize_u16 == routineSubFunctionConfig_pst->maxControlOptionRecordSize_u16)
        {
            totalLengthCheckResult = E_OK;
        }
    }
    else
    {
        if((actualContolOptionRecordSize_u16 <= routineSubFunctionConfig_pst->maxControlOptionRecordSize_u16) && (actualContolOptionRecordSize_u16 >= routineSubFunctionConfig_pst->minControlOptionRecordSize_u16))
        {
            totalLengthCheckResult = E_OK;
        }
    }

    if(E_NOT_OK == totalLengthCheckResult)
    {
        *dataNegRespCode_u8 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    return totalLengthCheckResult;
}

static Std_ReturnType Dcm_RCControlOptionRecordCheck(const Dcm_MsgContextType* pMsgContext, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType controlOptionRecordCheckResult = E_NOT_OK;
    uint16 routineID_u16;
    uint16 controlOptionRecordSize_u16 = (uint16)(pMsgContext->reqDataLen - 3u);

    routineID_u16 = ((uint16)pMsgContext->reqData[DCM_ROUTINE_ID_MSB_INDEX] <<8);
    routineID_u16 = (routineID_u16 | (uint16)pMsgContext->reqData[DCM_ROUTINE_ID_LSB_INDEX]);

    controlOptionRecordCheckResult = DcmAppl_DcmCheckRoutineControlOptionRecord(routineID_u16, pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX],
            &pMsgContext->reqData[DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX], controlOptionRecordSize_u16);

    if(E_OK != controlOptionRecordCheckResult)
    {
        *dataNegRespCode_u8 = DCM_E_REQUESTOUTOFRANGE;
    }
    return controlOptionRecordCheckResult;
}

static Std_ReturnType Dcm_RCUserModeConditionCheck(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType userModeConditionCheckResult = E_NOT_OK;
    uint16 routineID_u16;

    routineID_u16 = ((uint16)pMsgContext->reqData[DCM_ROUTINE_ID_MSB_INDEX] <<8);
    routineID_u16 = (routineID_u16 | (uint16)pMsgContext->reqData[DCM_ROUTINE_ID_LSB_INDEX]);

    if(NULL_PTR == Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].userModeCondition_pfct)
    {
        userModeConditionCheckResult = DcmAppl_UserRIDModeRuleService(dataNegRespCode_u8, routineID_u16, pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX]);
    }
    else
    {
        userModeConditionCheckResult = (*Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].userModeCondition_pfct)(dataNegRespCode_u8, routineID_u16, pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX]);
    }

    if((E_NOT_OK == userModeConditionCheckResult) && (Dcm_RCNoNRC_cu8 == *dataNegRespCode_u8))
    {
        *dataNegRespCode_u8 = DCM_E_CONDITIONSNOTCORRECT;
    }
    return userModeConditionCheckResult;
}

static Std_ReturnType Dcm_RCModeConditionCheck(uint8 subFunction_u8, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType modeConditionCheckResult = E_NOT_OK;
    const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst = NULL_PTR;

    Dcm_RCGetRoutineSubFunctionConfig(subFunction_u8, routineCommonIndex_u16, &routineSubFunctionConfig_pst);

    if(NULL_PTR != routineSubFunctionConfig_pst)
    {
        if(NULL_PTR != routineSubFunctionConfig_pst->modeCondition_pfct)
        {
            if((*routineSubFunctionConfig_pst->modeCondition_pfct)(dataNegRespCode_u8))
            {
                modeConditionCheckResult = E_OK;
            }
        }
        else
        {
            modeConditionCheckResult = E_OK;
        }
    }
    return modeConditionCheckResult;
}

static Std_ReturnType Dcm_RCSequenceCheck(uint8 subFunction_u8, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType sequenceCheckResult = E_OK;
    const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst = NULL_PTR;

    if(Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].requestSequenceErrorSupported_b)
    {
        if((uint8)DCM_START_ROUTINE != subFunction_u8)
        {
            Dcm_RCGetRoutineSubFunctionConfig((uint8)DCM_START_ROUTINE, routineCommonIndex_u16, &routineSubFunctionConfig_pst);

            /* Start Routine is configured for this routine */
            if(NULL_PTR != routineSubFunctionConfig_pst)
            {
                if( (DCM_ROUTINE_STARTED != Dcm_RoutineStatus_aen[routineCommonIndex_u16]) &&
                        ((DCM_ROUTINE_STOPPED != Dcm_RoutineStatus_aen[routineCommonIndex_u16]) || ((uint8)DCM_STOP_ROUTINE == subFunction_u8)) )
                {

                    *dataNegRespCode_u8 = DCM_E_REQUESTSEQUENCEERROR;
                    sequenceCheckResult = E_NOT_OK;
                }
            }
        }
    }
    return sequenceCheckResult;
}

static void Dcm_RCSetCurrentlyProcessedRoutine(const Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16)
{
    uint16 routineID_u16;
    boolean isRoutineIDFound_b = FALSE;
#if(DCM_CFG_NUM_NORMAL_ROUTINES > 0)
    uint16 normalRoutineIndex_u16;
#endif
#if(DCM_CFG_NUM_RANGE_ROUTINES > 0)
    uint16 rangeRoutineIndex_u16;
#endif


    if(NULL_PTR != pMsgContext)
    {
        routineID_u16 = ((uint16)pMsgContext->reqData[DCM_ROUTINE_ID_MSB_INDEX] <<8);
        routineID_u16 = (routineID_u16 | (uint16)pMsgContext->reqData[DCM_ROUTINE_ID_LSB_INDEX]);
        isRoutineIDFound_b = TRUE;
    }
    else
    {

#if(DCM_CFG_NUM_NORMAL_ROUTINES > 0)
        for(normalRoutineIndex_u16=0; normalRoutineIndex_u16 < DCM_CFG_NUM_NORMAL_ROUTINES; normalRoutineIndex_u16++)
        {
            if(Dcm_Cfg_NormalRoutineConfig_cast[normalRoutineIndex_u16].routineCommonIndex_u16 == routineCommonIndex_u16)
            {
                routineID_u16 = Dcm_Cfg_NormalRoutineConfig_cast[normalRoutineIndex_u16].dataRId_u16;
                isRoutineIDFound_b = TRUE;
                break;
            }
        }
#endif

#if(DCM_CFG_NUM_RANGE_ROUTINES > 0)
        if(!isRoutineIDFound_b)
        {
            for(rangeRoutineIndex_u16=0; rangeRoutineIndex_u16 < DCM_CFG_NUM_RANGE_ROUTINES; rangeRoutineIndex_u16++)
            {
                if(Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex_u16].routineCommonIndex_u16 == routineCommonIndex_u16)
                {
                    /* Lower Limit is used, as the exact routine ID is not available for a range routine */
                    routineID_u16 = Dcm_Cfg_RangeRoutineConfig_cast[rangeRoutineIndex_u16].routineRangeLowerLimit_u16;
                    isRoutineIDFound_b = TRUE;
                    break;
                }
            }
        }
#endif
    }

    if(isRoutineIDFound_b)
    {
        Dcm_RoutineCommonIndex_u16 = routineCommonIndex_u16;
        Dcm_IsRoutineProcessingActive_b = TRUE;
        Dcm_CurrentlyProcessedRID_u16 = routineID_u16;
    }
    else
    {
        Dcm_RoutineCommonIndex_u16 = 0u;
        Dcm_IsRoutineProcessingActive_b = FALSE;
        Dcm_CurrentlyProcessedRID_u16 = 0u;
    }
}

static Std_ReturnType Dcm_RCGetRoutineCommonIndex(uint16* routineCommonIndex_pu16)
{
    Std_ReturnType getRoutineCommonIndexResult = E_NOT_OK;

    if(Dcm_IsRoutineProcessingActive_b)
    {
        *routineCommonIndex_pu16 = Dcm_RoutineCommonIndex_u16;
        getRoutineCommonIndexResult = E_OK;
    }
    return getRoutineCommonIndexResult;
}

static void Dcm_RCCopyRequestToDataIn(const Dcm_MsgContextType* pMsgContext, const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst)
{
    uint8 inSignalDataType_u8;
    uint32 signalValue_u32;
    uint8 indexInSignal;

    for(indexInSignal = 0; indexInSignal < routineSubFunctionConfig_pst->numberOfInSignals_u8; indexInSignal++)
    {
        inSignalDataType_u8 = routineSubFunctionConfig_pst->inSignalConfig_past[indexInSignal].dataType_u8;

        /* Primitive data type */
        if(DCM_VARIABLE_LENGTH > inSignalDataType_u8)
        {
            signalValue_u32 = Dcm_GetSignal_u32(inSignalDataType_u8, routineSubFunctionConfig_pst->inSignalConfig_past[indexInSignal].posnStart_u16,
                    &(pMsgContext->reqData[DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX]), routineSubFunctionConfig_pst->inSignalConfig_past[indexInSignal].dataEndianness_u8);

            Dcm_RCSetDataIn(inSignalDataType_u8, routineSubFunctionConfig_pst->inSignalConfig_past[indexInSignal].idxSignal_u16,  signalValue_u32);
        }
        /* Array data type */
        else if (DCM_VARIABLE_LENGTH < inSignalDataType_u8)
        {
            Dcm_RCSetDataInArray(&routineSubFunctionConfig_pst->inSignalConfig_past[indexInSignal], &pMsgContext->reqData[DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX]);
        }
        /* Variable length */
        else
        {
            Dcm_RCSetDataInVar(pMsgContext, routineSubFunctionConfig_pst->minControlOptionRecordSize_u16);
        }
    }
}

static void Dcm_RCSetDataInVar(const Dcm_MsgContextType* pMsgContext, uint16 minControlOptionRecordSize_u16)
{
    uint16 variableControlOptionRecordStartIndex_u16;
    uint16 actualControlOptionRecordSize_u16;

    actualControlOptionRecordSize_u16 = (uint16)(pMsgContext->reqDataLen - DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX);
    Dcm_RCDataVarLength_u16 = actualControlOptionRecordSize_u16 - minControlOptionRecordSize_u16;

    if(Dcm_RCDataVarLength_u16 > 0u)
    {
        variableControlOptionRecordStartIndex_u16 = (uint16)((uint16)DCM_ROUTINE_CONTROL_OPTION_RECORD_START_INDEX + minControlOptionRecordSize_u16);

        /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as input and object type pointer is converted to void pointer*/
        DCM_MEMCOPY(&(Dcm_RCDataInVar_au8[0]), &pMsgContext->reqData[variableControlOptionRecordStartIndex_u16], Dcm_RCDataVarLength_u16);
    }
}

static Std_ReturnType Dcm_RCProcessRoutineResult(Std_ReturnType routineResult, Dcm_MsgContextType* pMsgContext, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType processRoutineResult = E_NOT_OK;
    uint8 subFunction_u8 = pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX];
    const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst = NULL_PTR;

    if(E_OK == routineResult)
    {
        Dcm_RCGetRoutineSubFunctionConfig(subFunction_u8, routineCommonIndex_u16, &routineSubFunctionConfig_pst);

        if(NULL_PTR != routineSubFunctionConfig_pst)
        {
            if((uint8)DCM_START_ROUTINE == subFunction_u8)
            {
                Dcm_RoutineStatus_aen[routineCommonIndex_u16] = DCM_ROUTINE_STARTED;
            }
            else if((uint8)DCM_STOP_ROUTINE == subFunction_u8)
            {
                Dcm_RoutineStatus_aen[routineCommonIndex_u16] = DCM_ROUTINE_STOPPED;
            }
            else
            {
                /* Do Nothing */
            }
            Dcm_RCCopyDataOutToResponse(pMsgContext, routineSubFunctionConfig_pst);
            processRoutineResult = E_OK;
        }
    }
    else
    {
        Dcm_RCRoutineHandlerNRC(routineResult, routineCommonIndex_u16, dataNegRespCode_u8);
    }

    Dcm_IsRoutineProcessingActive_b = FALSE;

    return processRoutineResult;
}

static void Dcm_RCCopyDataOutToResponse(Dcm_MsgContextType* pMsgContext, const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst)
{
    uint8 outSignalDataType_u8;
    uint32 signalValue_u32;
    uint8 subFunction_u8 = pMsgContext->reqData[DCM_ROUTINE_SUBFUNCTION_INDEX];
    uint8 indexOutSignal;

    pMsgContext->resData[DCM_ROUTINE_SUBFUNCTION_INDEX] = subFunction_u8;
    pMsgContext->resData[DCM_ROUTINE_ID_MSB_INDEX] = (uint8)(Dcm_CurrentlyProcessedRID_u16 >> 8u);
    pMsgContext->resData[DCM_ROUTINE_ID_LSB_INDEX] = (uint8)(Dcm_CurrentlyProcessedRID_u16 & 0x00ffu);
    pMsgContext->resDataLen = DCM_ROUTINE_STATUS_OPTION_RECORD_START_INDEX + (uint32)routineSubFunctionConfig_pst->minStatusOptionRecordSize_u16;

    for(indexOutSignal = 0; indexOutSignal < routineSubFunctionConfig_pst->numberOfOutSignals_u8; indexOutSignal++)
    {
        outSignalDataType_u8 = routineSubFunctionConfig_pst->outSignalConfig_past[indexOutSignal].dataType_u8;

        /* Primitive data type */
        if(DCM_VARIABLE_LENGTH > outSignalDataType_u8)
        {
            signalValue_u32 = Dcm_RCGetDataOut(outSignalDataType_u8, routineSubFunctionConfig_pst->outSignalConfig_past[indexOutSignal].idxSignal_u16);

            Dcm_StoreSignal(outSignalDataType_u8, routineSubFunctionConfig_pst->outSignalConfig_past[indexOutSignal].posnStart_u16,
                    &(pMsgContext->resData[DCM_ROUTINE_STATUS_OPTION_RECORD_START_INDEX]), signalValue_u32, routineSubFunctionConfig_pst->outSignalConfig_past[indexOutSignal].dataEndianness_u8 );
        }
        /* Array data type */
        else if (DCM_VARIABLE_LENGTH < outSignalDataType_u8)
        {
            Dcm_RCCopyDataOutArrayToResponse(&routineSubFunctionConfig_pst->outSignalConfig_past[indexOutSignal], &pMsgContext->resData[DCM_ROUTINE_STATUS_OPTION_RECORD_START_INDEX]);
        }
        else
        {
            /* The actual response is already updated directly by the routine handler using the Dcm_RCDataOutVar_pau8 */
            pMsgContext->resDataLen = pMsgContext->resDataLen + Dcm_RCDataVarLength_u16;
        }
    }
}

static void Dcm_RCRoutineHandlerNRC(Std_ReturnType routineResult, uint16 routineCommonIndex_u16, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    if((Dcm_IsInfrastructureErrorPresent_b(routineResult) != FALSE) && (Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].usePort_b != FALSE))
    {
        *dataNegRespCode_u8 = DCM_E_GENERALREJECT;
    }
    else if(Dcm_RCNoNRC_cu8 == *dataNegRespCode_u8)
    {
        *dataNegRespCode_u8 = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        /* Do Nothing */
    }
}

void Dcm_Prv_RCSessionChangeTrigger(Dcm_SesCtrlType newSession)
{
    const Dcm_RoutineSubFunctionConfigType_tst* routineSubFunctionConfig_pst = NULL_PTR;
    /* NRC_u8 is not used because the routine is stopped without any request and so no response is required */
    Dcm_NegativeResponseCodeType NRC_u8;
    Std_ReturnType statusRCsessioncheck;
    Dcm_SesCtrlType getDefaultsession;
    uint16 routineCommonIndex_u16;
    Std_ReturnType routineHandlerResult = E_NOT_OK;
    getDefaultsession = Dcm_Prv_GetSession(DCM_DEFAULT_SESSION_IDX);
    for(routineCommonIndex_u16 = 0; routineCommonIndex_u16 < DCM_CFG_NUM_TOTAL_ROUTINES; routineCommonIndex_u16++)
    {
        Dcm_RCGetRoutineSubFunctionConfig((uint8)DCM_STOP_ROUTINE, routineCommonIndex_u16, &routineSubFunctionConfig_pst);

        if(NULL_PTR != routineSubFunctionConfig_pst)
        {
            if((DCM_ROUTINE_STARTED == Dcm_RoutineStatus_aen[routineCommonIndex_u16]) &&
                    (Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].stopRoutineOnSessionChange_b))
            {
                statusRCsessioncheck = Dcm_RCSessionCheck(routineCommonIndex_u16, &NRC_u8);
                if((E_NOT_OK == statusRCsessioncheck) || (newSession == getDefaultsession ))
                {
                    Dcm_RCSetCurrentlyProcessedRoutine(NULL_PTR, routineCommonIndex_u16);
                    routineHandlerResult = (*Dcm_Cfg_RoutineExtendedConfig_cast[routineCommonIndex_u16].routineHandler_pfct)((uint8)DCM_STOP_ROUTINE, DCM_INITIAL, &NRC_u8);

                    if(DCM_E_PENDING == routineHandlerResult)
                    {
                        Dcm_RoutineStatus_aen[routineCommonIndex_u16] = DCM_ROUTINE_STOP_PENDING;
                    }
                    else if(E_OK == routineHandlerResult)
                    {
                        Dcm_RoutineStatus_aen[routineCommonIndex_u16] = DCM_ROUTINE_STOPPED;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                    Dcm_IsRoutineProcessingActive_b = FALSE;
                }
            }
        }
    }
}

/**
******************************************************************************************************************
 * This API has to be called from the application callbacks of Start, Stop and Req.Results routine configured for the project and also from the DcmAppl_DcmConfirmation.
 * Example scenarios:
 *  a) This API has to be called by the application
 *      a.1)during Start, Stop and Request Results operations for the normal tester request
 *      a.2)during canceling the pending operations either Start or Stop or Request Results due to CANCEL operation triggered by Dcm by setting the Opstatus to DCM_CANCEL in the RC Ini function.
 *      a.3)during the stop of the routines due to session transitions (either due to protocol start/stop or session time out/change).
 * By "Active RID", it means that the active RID index under processing and not the RIDs of already started routines.
******************************************************************************************************************
 */
Std_ReturnType Dcm_GetActiveRid(uint16* dataRid_u16)
{
    Std_ReturnType getActiveRidResult = E_NOT_OK;

    if(NULL_PTR != dataRid_u16)
    {
        if((Dcm_IsRoutineProcessingActive_b)||(Dcm_IsRoutineConfirmationActive_b))
        {
            *dataRid_u16 = Dcm_CurrentlyProcessedRID_u16;
            getActiveRidResult = E_OK;
        }
    }
    return getActiveRidResult;
}

 void Dcm_Prv_DspRCConfirmation(uint8 sid_u8,
                                 uint8 reqType_u8,
                                 uint16 connectionId_u16,
                                 Dcm_ConfirmationStatusType confirmationStatus,
                                 Dcm_ProtocolType protocolType,
                                 uint16 testerSrcAddress_u16)
{
     Dcm_IsRoutineConfirmationActive_b = TRUE;
     DcmAppl_DcmConfirmation(sid_u8,reqType_u8,connectionId_u16,confirmationStatus,protocolType,testerSrcAddress_u16);
     Dcm_IsRoutineConfirmationActive_b = FALSE;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
