

#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"


/*
 **********************************************************************************************************************
 * Static Global variables
 **********************************************************************************************************************
 */
#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static  Dcm_IdContextType  Sid;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
static  Dcm_MsgLenType RespLength;
static  Dcm_MsgLenType MaxRespLength;
static  PduLengthType TotalResponseLength;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static  uint8* ResponseBuffer;
static Dcm_DsdInternalStructureType_tst Dcm_DsdGlobal_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
 */
#define DCM_SUPPRESS_RESPONSE_LENGTH   (0x00u)

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/*
 **********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************
 */

static void Dcm_Dsd_PositiveResponseAssembler(void);
static void Dcm_Dsd_NegativeResponseAssembler(Dcm_NegativeResponseCodeType Nrc_u8);
static void Dcm_Dsd_RetrieveMsgContextandTxBuffer(void);

LOCAL_INLINE boolean Dcm_Dsd_isPositiveResponseSupressed(void)
{
    uint8 cntrWaitpendCounter_u8=0;

    cntrWaitpendCounter_u8 = Dcm_Dsl_Prv_GetRespPendingCounterValue();

    return (Dcm_Dsd_Prv_GetsuppressPosResponse() && (cntrWaitpendCounter_u8 == 0x00u));
}

static void Dcm_Dsd_RetrieveMsgContextandTxBuffer(void)
{
    Sid=Dcm_Dsd_Prv_GetIdContext();
    RespLength=Dcm_Dsd_Prv_GetRespLength();
    MaxRespLength=Dcm_Dsd_Prv_GetRespMaxLength();
    /* Acess TX buffer for Active Protocol.This is not from Msgcontext */
    ResponseBuffer=&Dcm_Prv_GetActiveTxBuffer()[2];
}

static void Dcm_Dsd_PositiveResponseAssembler(void)
{
    uint32 bufferSize_u32 = 0u;
    uint8  FirstbyteOfPositiveResponse;
    uint8  NrcValue_u8=0u;

    /* Application can add extra bytes to the service response */
    bufferSize_u32 = MaxRespLength - RespLength;
    DcmAppl_DcmModifyResponse(Sid, NrcValue_u8,&(ResponseBuffer[RespLength+1u]), &bufferSize_u32);

    if (Dcm_Dsd_isPositiveResponseSupressed())
    {
        /* In case of Suppress Positive Response-Total response legth is equal to 0 */
        TotalResponseLength=DCM_SUPPRESS_RESPONSE_LENGTH;

    }else
    {
        FirstbyteOfPositiveResponse=Sid|DCM_SERVICEID_ADDEND;
        ResponseBuffer[0]= FirstbyteOfPositiveResponse;
        TotalResponseLength= (PduLengthType) (RespLength+1u+bufferSize_u32);
    }
    /*This variable is used in confirmation to determine Dcm_ConfirmationStatusType*/
    Dcm_Prv_SetResponsetype(DCM_POS_RESPONSE);
    Dcm_Prv_TriggerTransmit(TotalResponseLength);
}

static void Dcm_Dsd_NegativeResponseAssembler(Dcm_NegativeResponseCodeType Nrc_u8)
{
    uint32 bufferSize_u32 = 0u;

    if(Dcm_Prv_GetResponsebyDSD()!=TRUE)
    {
        /* Application can add extra bytes to the service response */
        bufferSize_u32 = MaxRespLength - RespLength;
        DcmAppl_DcmModifyResponse(Sid, Nrc_u8,&ResponseBuffer[2], &bufferSize_u32);
        Nrc_u8 = (bufferSize_u32>0u) ? ResponseBuffer[2]:Nrc_u8;
    }

    if (Dcm_Dsd_isNegativeResponseSupressed(Nrc_u8))
    {
        TotalResponseLength=DCM_SUPPRESS_RESPONSE_LENGTH;

    }else
    {
        ResponseBuffer[0]= DCM_NEGRESPONSE_INDICATOR;
        ResponseBuffer[1]= Sid;
        ResponseBuffer[2]= Nrc_u8;
        TotalResponseLength=DCM_NEGATIVE_RESPONSE_LENGTH;
    }
    /*This variable is used in confirmation to determine Dcm_ConfirmationStatusType*/
    Dcm_Prv_SetResponsetype(DCM_NEG_RESPONSE);
    Dcm_Prv_TriggerTransmit(TotalResponseLength);
}

/***********************************************************************************************************************
 Function name    : Dcm_Dsd_Prv_AssembleResponse
 Syntax           : Dcm_Dsd_Prv_AssembleResponse(Result_u8,ErrorCode_u8)
 Description      : This is invoked to assemble all types of reponses.
 Parameters       : Std_ReturnType,Dcm_NegativeResponseCodeType
 Return value     : void
***********************************************************************************************************************/
void Dcm_Dsd_Prv_AssembleResponse(Std_ReturnType Result_u8, Dcm_NegativeResponseCodeType ErrorCode_u8)
{

    Dcm_Dsd_RetrieveMsgContextandTxBuffer();

    if (Result_u8 == E_OK)
    {
        Dcm_Dsd_PositiveResponseAssembler();
    }
    else if (Result_u8 == E_NOT_OK)
    {
        Dcm_Dsd_NegativeResponseAssembler(ErrorCode_u8);
    }
    else
    {
        (void)Dcm_Prv_SendForcePendingResponse();
    }
}

/***********************************************************************************************************************
 Below interfaces are needed for other modules to update Dcm_DsdInternalStructureType_tst
***********************************************************************************************************************/
void Dcm_Prv_SetResponsebyDSD(boolean ResponsebyDSD)
{
    Dcm_DsdGlobal_st.dataResponseByDsd_b=ResponsebyDSD;
}

boolean Dcm_Prv_GetResponsebyDSD(void)
{
    return Dcm_DsdGlobal_st.dataResponseByDsd_b;
}
void Dcm_Prv_SetResponsetype(Dcm_DsdResponseType_ten Responsetype)
{
    Dcm_DsdGlobal_st.stResponseType_en=Responsetype;
}

Dcm_DsdResponseType_ten Dcm_Prv_GetResponsetype(void)
{
    return Dcm_DsdGlobal_st.stResponseType_en;
}

PduLengthType Dcm_Prv_GetActiveResponseLength(void)
{
    return TotalResponseLength;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
