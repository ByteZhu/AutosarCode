
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
LOCAL_INLINE boolean Dcm_isNormalResponseAvailable(PduIdType DcmTxPduId);

LOCAL_INLINE boolean Dcm_isNrc21ResponseAvailable(PduIdType DcmTxPduId,PduIdType DcmRxPduId);

static BufReq_ReturnType Dcm_CheckEnvironment(PduIdType DcmTxPduIndex, const PduInfoType * PduInfoPtr,
        const PduLengthType * PduAvailableDataPtr);

#if (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
LOCAL_INLINE boolean Dcm_isPagedBufferResponseAvailable(PduIdType DcmTxPduId);
static BufReq_ReturnType Dcm_ProcessPagedBufferResponse(const PduInfoType * PduInfoPtr,
        const RetryInfoType * RetryInfoPtr);
LOCAL_INLINE boolean Dcm_Prv_isCurrentPageTransmitted(PduLengthType SduLength,
        const RetryInfoType * RetryInfoPtr);
#endif

static BufReq_ReturnType Dcm_UpdateAvailableResponse(PduIdType DcmTxPduIndex, const PduInfoType * PduInfoPtr,
        const RetryInfoType * RetryInfoPtr,PduLengthType* availableDataPtr);
static boolean Dcm_isRetryRequestedAndValid(const RetryInfoType * RetryInfoPtr, const PduInfoType * PduInfoPtr,
        BufReq_ReturnType * RetValPtr);
static boolean Dcm_isRetryRequested(const RetryInfoType * RetryInfoPtr);



/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static uint8 Dcm_tempData_u8[3]; /* Response Data for NRC21 */
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
static uint8 ObdadrDataPtr_u8[3]; /* Response Data for OBD NRC21 */
#endif
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static PduInfoType * Dcm_PduInfo_pst;
static PduInfoType Dcm_adrDataPtr_pst;
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
static PduInfoType Dcm_ObdadrDataPtr_pst;
static PduInfoType* Dcm_ObdPduInfo_pst;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
static boolean Dcm_isOBDNrc21responseSet_b; // Nrc 21 to be sent for an OBD request
#endif
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/

/***********************************************************************************************************************
 *    Inline Function Definitions
 **********************************************************************************************************************/


LOCAL_INLINE boolean Dcm_isNormalResponseAvailable(PduIdType DcmTxPduId)
{
    Dcm_DslStatesType_ten s_Dcm_DslState_en = Dcm_Dsl_Prv_GetDslState();
    return((DcmTxPduId == Dcm_Prv_GetActiveTxPduId()) && \
           ((DSL_STATE_WAITFOR_TXCONFIRMATION_E == s_Dcm_DslState_en) ||
            (DSL_STATE_ROETYPE1_RECEIVED_E == s_Dcm_DslState_en)));
}

#if (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)

/***********************************************************************************************************************
 Function name    : Dcm_Prv_isPagedBufferResponseAvailable
 Syntax           : Dcm_Prv_isPagedBufferResponseAvailable(DcmTxPduId)
 Description      : This Inline function is used to check whether Paged buffer response is available
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_isPagedBufferResponseAvailable(PduIdType DcmTxPduId)
{
    PduIdType ActiveTxPduId  = Dcm_Prv_GetActiveTxPduId();
    Dcm_DslStatesType_ten getDslstate= Dcm_Dsl_Prv_GetDslState();
    return((DcmTxPduId == ActiveTxPduId) &&
            (getDslstate == DSL_STATE_PAGEDBUFFER_TRANSMISSION_E));
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_isCurrentPageTransmitted
 Syntax           : Dcm_Prv_isCurrentPageTransmitted(SduLength,&RetryInfoPtr)
 Description      : This Inline Function is used to check if Current page is Transmitted in case of paged buffer Tx
 Parameter        : PduLengthType,const RetryInfoType*
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isCurrentPageTransmitted(PduLengthType SduLength,const RetryInfoType * RetryInfoPtr)
{
    boolean pageStatus_b = FALSE;

    if(RetryInfoPtr != NULL_PTR)
    {
        if(RetryInfoPtr->TpDataState == TP_DATACONF)
        {
            pageStatus_b = TRUE;
        }
    }
    else if(SduLength == 0u)
    {
        pageStatus_b = TRUE;
    }
    else
    {
        /* Do Nothing */
    }

    return pageStatus_b;
}
#endif

LOCAL_INLINE boolean Dcm_isNrc21ResponseAvailable(PduIdType DcmTxPduId,PduIdType DcmRxPduId)
{
    boolean nrc21_b = FALSE;

    if(DcmRxPduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        nrc21_b = Dcm_Prv_GetRespOnSecondDeclinedRequest(DcmRxPduId);
    }

    return ((DcmTxPduId == Dcm_Prv_GetTxPduId(DcmRxPduId)) && (nrc21_b));
}


/***********************************************************************************************************************
 *    Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDisNrc21ResponseAvailable
 Syntax           : Dcm_Prv_OBDisNrc21ResponseAvailable(&ServiceIdPtr,DcmTxPduId)
 Description      : This Function is used to check whether NRC21 response is available for OBD
 Parameter        : uint16*, PduIdType
 Return value     : boolean
***********************************************************************************************************************/
static boolean Dcm_Prv_OBDisNrc21ResponseAvailable(uint8* ServiceIdPtr,PduIdType DcmTxPduId)
{
    boolean isNrc21Available_b = FALSE;
    PduIdType DcmRxPduId = Dcm_Prv_GetLowPrioNrc21RxPduId();

    *ServiceIdPtr = Dcm_DslOBDRxPduArray_ast[DcmRxPduId].Dcm_DslServiceId_u8;

    /* Nrc21 flag for the transmission is set to True */
    if (FALSE != Dcm_isNrc21ResponseAvailable(DcmTxPduId,DcmRxPduId))
    {
        isNrc21Available_b = TRUE;
    }

    return isNrc21Available_b;
}


static BufReq_ReturnType Dcm_Prv_OBDValidateCopyTxDataType(PduIdType DcmTxPduId)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
    uint8 serviceId_u8 = 0u;

    /* Set the NRC21 flag to FALSE */
    Dcm_isOBDNrc21responseSet_b = FALSE;

    if( (DcmTxPduId == Dcm_OBDGlobal_st.dataActiveTxPduId_u8)
        && (Dcm_Prv_GetOBDState() == DCM_OBD_WAITFORTXCONF) )
    {
        Dcm_ObdPduInfo_pst = &Dcm_OBDPduInfo_st;
        bufRequestStatus_en = BUFREQ_OK;
    }
    else
    {
        if(FALSE != Dcm_Prv_OBDisNrc21ResponseAvailable(&serviceId_u8,DcmTxPduId))
        {
            /* Set the flag when NRC21 Response is available */
            Dcm_isOBDNrc21responseSet_b = TRUE;
            bufRequestStatus_en = BUFREQ_OK;

            ObdadrDataPtr_u8[0] = DCM_NEGRESPONSE_INDICATOR;
            ObdadrDataPtr_u8[1] = serviceId_u8;
            ObdadrDataPtr_u8[2] = DCM_E_BUSYREPEATREQUEST;

            Dcm_ObdadrDataPtr_pst.SduLength = DCM_NEGATIVE_RESPONSE_LENGTH;
            Dcm_ObdadrDataPtr_pst.SduDataPtr = &ObdadrDataPtr_u8[0];

            /* update Obdpduinfo with valid address */
            Dcm_ObdPduInfo_pst = &Dcm_ObdadrDataPtr_pst;
        }
    }
    return bufRequestStatus_en;
}

#endif

/* Static Function to validate all parameter passed to API Dcm_CopyTxData from Lower layer*/
static BufReq_ReturnType Dcm_CheckEnvironment(PduIdType DcmTxPduIndex,
        const PduInfoType * PduInfoPtr,
        const PduLengthType * PduAvailableDataPtr)
{
    BufReq_ReturnType retEnvCheck_en = BUFREQ_E_NOT_OK;
    boolean context = DCM_UDSCONTEXT;
    PduIdType txPduId = Dcm_Prv_GetTxPduIdFromTxIndex(DcmTxPduIndex);
    PduIdType DcmTxPduId_nrc21 = Dcm_Prv_GetTxPduId(Dcm_Prv_GetLowPrioNrc21RxPduId());
    PduIdType ActiveTxPduId  = Dcm_Prv_GetActiveTxPduId();
#if(DCM_CFG_ROETYPE2_ENABLED == DCM_CFG_ON)
    const Dcm_DslRoeConnConfigType_tst* ActiveRoeConnection = Dcm_Prv_GetActiveRoeConnection();
    if(Dcm_DsdRoe2State_en == DSD_WAITFORTXCONF_E)
    {
        ActiveTxPduId = ActiveRoeConnection->roeTxPduId;
    }
#endif
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    context = (Dcm_Prv_IsTxPduIdOBD(txPduId)?DCM_OBDCONTEXT:DCM_UDSCONTEXT);
    if(context == DCM_OBDCONTEXT)
    {
        ActiveTxPduId = Dcm_Prv_GetObdActiveConnection()->txPduId;
    }
#endif

    if(PduInfoPtr == NULL_PTR)
    {
        Dcm_Prv_Det(DCM_COPYTXDATA_ID , DCM_E_PARAM_POINTER );
    }
    else if ((PduInfoPtr->SduLength != 0u) && (PduInfoPtr->SduDataPtr == NULL_PTR))
    {
        Dcm_Prv_Det(DCM_COPYTXDATA_ID , DCM_E_PARAM_POINTER);
    }
    else if (PduAvailableDataPtr == NULL_PTR)
    {
        Dcm_Prv_Det(DCM_COPYTXDATA_ID , DCM_E_PARAM_POINTER );
    }
    else if (DcmTxPduIndex >= DCM_CFG_INVALID_TX_PDUINDEX)
    {
        Dcm_Prv_Det(DCM_COPYTXDATA_ID ,DCM_E_PARAM);
    }
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    else if((context == DCM_OBDCONTEXT) && (txPduId != ActiveTxPduId) && (txPduId != DcmTxPduId_nrc21))
    {
        Dcm_Prv_Det(DCM_COPYTXDATA_ID ,DCM_E_PARAM);
    }
#endif
    else if ((context != DCM_OBDCONTEXT) && (txPduId != ActiveTxPduId) && (txPduId != DcmTxPduId_nrc21))
    {
        Dcm_Prv_Det(DCM_COPYTXDATA_ID ,DCM_E_PARAM);
    }
    else
    {
        retEnvCheck_en = BUFREQ_OK;
    }
    return retEnvCheck_en;
}

#if(DCM_CFG_ROETYPE2_ENABLED == DCM_CFG_ON)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isRoeType2ResponseAvailable
 Syntax           : Dcm_Prv_isRoeType2ResponseAvailable(DcmTxPduId)
 Description      : This funcion is used to
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isRoeType2ResponseAvailable(PduIdType DcmTxPduId)
{
    return (Dcm_Prv_GetActiveRoeConnection()->roeTxPduId == DcmTxPduId);
}
#endif

#if (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
/* Static Function to handle Paged buffer states and to process the response.*/
static BufReq_ReturnType Dcm_ProcessPagedBufferResponse(
        const PduInfoType * PduInfoPtr,
        const RetryInfoType * RetryInfoPtr)
{

    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
    Dcm_DslSubStatesType_ten subStateTemp_u8 = Dcm_Dsl_Prv_GetDslSubState();

    switch(subStateTemp_u8)
    {
        case DSL_SUBSTATE_DATA_READY_E :

            /* When the TP requests Dcm to copy payload, check if length indicated to copy is greater than the available
               Dcm response length.
               If yes then send DET error when first Dcm_TpCopyTxData fails for the paged buffer in the first page  */

            if(PduInfoPtr->SduLength <= (PduLengthType)Dcm_Prv_Get_dataCurrentPageRespLength_u32())
            {
                Dcm_DsldPduInfo_st.SduDataPtr = &Dcm_Prv_GetActiveTxBuffer()[2];
                Dcm_DsldPduInfo_st.SduLength  = (PduLengthType)Dcm_Prv_Get_dataCurrentPageRespLength_u32();

                Dcm_PduInfo_pst = &Dcm_DsldPduInfo_st;

                Dcm_Dsl_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION_E);
                Dcm_Dsl_Prv_SetDslSubState(DSL_SUBSTATE_WAIT_PAGE_TXCONFIRM_E);
                bufRequestStatus_en = BUFREQ_OK;
            }
            else
            {
                bufRequestStatus_en = BUFREQ_E_NOT_OK;
                Dcm_Prv_Det(DCM_COPYTXDATA_ID , DCM_E_INVALID_LENGTH );
            }
            break;


        /*TRACE[SWS_Dcm_01186]*/
        case DSL_SUBSTATE_WAIT_FOR_DATA_E :

            bufRequestStatus_en = BUFREQ_E_BUSY;
            break;



        case DSL_SUBSTATE_WAIT_PAGE_TXCONFIRM_E :

            /* Current page transmission is over. Give the page back to service to fill next page */
            if(FALSE != Dcm_Prv_isCurrentPageTransmitted(Dcm_DsldPduInfo_st.SduLength,RetryInfoPtr))
            {
                Dcm_Dsl_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION_E);
                Dcm_Dsl_Prv_SetDslSubState(DSL_SUBSTATE_WAIT_FOR_DATA_E);
                /* Get the data length left in the last page */
                Dcm_Prv_Set_RemainingPageLength(Dcm_DsldPduInfo_st.SduLength);
                bufRequestStatus_en = BUFREQ_E_BUSY;
            }
            else
            {
                boolean PagedBufferTxOn_b = Dcm_Prv_Get_PagedBufferTxOn();
                boolean RetryRequested_b = Dcm_isRetryRequested(RetryInfoPtr);
                if((Dcm_DsldPduInfo_st.SduLength < PduInfoPtr->SduLength ) && (PagedBufferTxOn_b) && (FALSE == RetryRequested_b))
                {
                    uint8* ResponseBuffer=&Dcm_Prv_GetActiveTxBuffer()[2];
                    /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMSET takes void pointer
                      as input and object type pointer is converted to void pointer*/
                    DCM_MEMSET(ResponseBuffer, (sint32)DCM_CFG_SIGNAL_DEFAULT_VALUE,
                            Dcm_DsldPduInfo_st.SduLength);

                    /* copy the reaming bytes to Start page address */
                    /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as input and object type
                    pointer is converted to void pointer*/
                    DCM_MEMCOPY(ResponseBuffer, Dcm_DsldPduInfo_st.SduDataPtr,
                            Dcm_DsldPduInfo_st.SduLength);

                    Dcm_Dsl_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION_E);
                    Dcm_Dsl_Prv_SetDslSubState(DSL_SUBSTATE_WAIT_FOR_DATA_E);
                    /* Get the data length left in the last page */
                    Dcm_Prv_Set_RemainingPageLength(Dcm_DsldPduInfo_st.SduLength);
                    bufRequestStatus_en = BUFREQ_E_BUSY;
                }
                else
                {
                    /* Current page transmission is not yet over. To copy the requested data */
                    Dcm_PduInfo_pst = &Dcm_DsldPduInfo_st;
                    bufRequestStatus_en = BUFREQ_OK;
                }
            }
            break;

        default :
            /*nothing to do*/
            break;

    }
    return bufRequestStatus_en;
}
#endif

/* Static Function to update available Response*/
static BufReq_ReturnType Dcm_UpdateAvailableResponse(PduIdType DcmTxPduIndex,
        const PduInfoType * PduInfoPtr,
        const RetryInfoType * RetryInfoPtr,
        PduLengthType* availableDataPtr)
{
    BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
    PduIdType DcmRxPduId = Dcm_Prv_GetLowPrioNrc21RxPduId();
    PduIdType DcmTxPduId = Dcm_Prv_GetTxPduIdFromTxIndex(DcmTxPduIndex); /*lower layer provides index for Tx Pdu table, not PduId itself*/

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)

    boolean context = (Dcm_Prv_IsTxPduIdOBD(DcmTxPduId)?DCM_OBDCONTEXT:DCM_UDSCONTEXT);

    if(context == DCM_OBDCONTEXT)
    {
        bufRequestStatus_en = Dcm_Prv_OBDValidateCopyTxDataType(DcmTxPduId);
        Dcm_PduInfo_pst = Dcm_ObdPduInfo_pst;
    }
    else
#endif
    {
        if(FALSE != Dcm_isNormalResponseAvailable(DcmTxPduId))
        {
            Dcm_PduInfo_pst = &Dcm_Dsl_Respone_st;
            bufRequestStatus_en = BUFREQ_OK;
        }
#if (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
        else if(FALSE != Dcm_isPagedBufferResponseAvailable(DcmTxPduId))
        {
            bufRequestStatus_en = Dcm_ProcessPagedBufferResponse(PduInfoPtr,RetryInfoPtr);
        }
#endif
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
        else if(FALSE != Dcm_Prv_isRoeType2ResponseAvailable(DcmTxPduId))
        {
            Dcm_PduInfo_pst = &Dcm_DsldRoe2PduInfo_st;
            bufRequestStatus_en = BUFREQ_OK;
        }
#endif
        else if (FALSE != Dcm_isNrc21ResponseAvailable(DcmTxPduId,DcmRxPduId))
        {
            bufRequestStatus_en = BUFREQ_OK;

            Dcm_tempData_u8[0] = DCM_NEGRESPONSE_INDICATOR;
            Dcm_tempData_u8[1] = Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_ServiceId_u8;
            Dcm_tempData_u8[2] = DCM_E_BUSYREPEATREQUEST;

            Dcm_adrDataPtr_pst.SduLength = DCM_NEGATIVE_RESPONSE_LENGTH;
            Dcm_adrDataPtr_pst.SduDataPtr = &Dcm_tempData_u8[0];

            //Dcm_Prv_SetResponsebyDSD(TRUE);
            Dcm_Prv_SetResponsetype(DCM_NEG_RESPONSE);

            Dcm_PduInfo_pst = &Dcm_adrDataPtr_pst;
        }
        else
        {
            /* Nothing to do here */
        }
    }

    if((Dcm_PduInfo_pst != NULL_PTR) && (BUFREQ_OK == bufRequestStatus_en))
    {
        if(PduInfoPtr->SduLength == 0u)
        {
            *(availableDataPtr ) = Dcm_PduInfo_pst->SduLength;
        }
        else
        {
            if(FALSE != Dcm_isRetryRequestedAndValid(RetryInfoPtr,PduInfoPtr,&bufRequestStatus_en))
            {
                Dcm_PduInfo_pst->SduDataPtr = Dcm_PduInfo_pst->SduDataPtr - RetryInfoPtr->TxTpDataCnt;
                Dcm_PduInfo_pst->SduLength = Dcm_PduInfo_pst->SduLength + RetryInfoPtr->TxTpDataCnt;
            }

            if((PduInfoPtr->SduLength <= Dcm_PduInfo_pst->SduLength) && (BUFREQ_OK == bufRequestStatus_en))
            {
                /*MR12 DIR 1.1 VIOLATION:This is required for implementation as DCM_MEMCOPY takes void pointer as
                input and object type pointer is converted to void pointer*/
                DCM_MEMCOPY(PduInfoPtr->SduDataPtr, Dcm_PduInfo_pst->SduDataPtr, PduInfoPtr->SduLength);
                Dcm_PduInfo_pst->SduDataPtr = Dcm_PduInfo_pst->SduDataPtr + PduInfoPtr->SduLength;
                if(FALSE != Dcm_isNrc21ResponseAvailable(DcmTxPduId,DcmRxPduId))
                {
                    *(availableDataPtr ) = 0u;
                }
                else
                {
                    Dcm_PduInfo_pst->SduLength = Dcm_PduInfo_pst->SduLength -PduInfoPtr->SduLength;
                    *(availableDataPtr ) = Dcm_PduInfo_pst->SduLength;
                }
            }
        }
    }
    return bufRequestStatus_en;
}

static boolean Dcm_isRetryRequested(const RetryInfoType * RetryInfoPtr)
{
    boolean isRetryRequested_b = FALSE;
    if((RetryInfoPtr != NULL_PTR) && (RetryInfoPtr->TpDataState ==TP_DATARETRY))
    {
        isRetryRequested_b = TRUE;
    }
    return isRetryRequested_b;
}

static boolean Dcm_isRetryRequestedAndValid(const RetryInfoType * RetryInfoPtr,
        const PduInfoType * PduInfoPtr,BufReq_ReturnType * RetValPtr)
{
    boolean isRetryRequestedAndValid_b = FALSE;
    if(FALSE != Dcm_isRetryRequested(RetryInfoPtr))
    {
        if(PduInfoPtr->SduDataPtr != NULL_PTR)
        {
            PduLengthType TxBufferMaxlen = (PduLengthType) (Dcm_Prv_GetActiveTxBufferMaxLen());
            if((RetryInfoPtr->TxTpDataCnt == 0u) || (RetryInfoPtr->TxTpDataCnt > TxBufferMaxlen))
            {
                Dcm_Prv_Det(DCM_COPYTXDATA_ID , DCM_E_PARAM);
                *RetValPtr = BUFREQ_E_NOT_OK;
            }
            else
            {
                isRetryRequestedAndValid_b = TRUE;
            }
        }
    }
    return isRetryRequestedAndValid_b;
}

/*This call-back function is invoked by medium specific TP (CanTp/FrTp) via PduR to inform the Dcm
 * once upon reception of each segment. Within this call, the received data is copied from the receive TP buffer to the
 * DCM receive buffer*/

BufReq_ReturnType Dcm_CopyTxData (PduIdType id,
        const PduInfoType* info,
        const RetryInfoType* retry,
        PduLengthType* availableDataPtr
)
{
    BufReq_ReturnType bufCopyTxDataStatus_en = BUFREQ_E_NOT_OK;

    if(BUFREQ_E_NOT_OK != Dcm_CheckEnvironment(id,info,availableDataPtr))
    {
        /* BSWEXT-533 */
        SchM_Enter_Dcm_Global();
        bufCopyTxDataStatus_en =  Dcm_UpdateAvailableResponse(id,info,retry,availableDataPtr);
        /* BSWEXT-533 */
        SchM_Exit_Dcm_Global();
    }
    return bufCopyTxDataStatus_en;
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
