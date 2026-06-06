#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"

#if (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
static PduLengthType Dcm_RemainingPageLength = 0x0;
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
static uint32 CurrentPageRespLength_u32 = 0x0;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
static boolean flagPagedBufferTxOn_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

/*This function pointer that stores the function for update page*/
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
void (*Dcm_adrUpdatePage_pfct) (Dcm_MsgType PageBufPtr,Dcm_MsgLenType PageLen);
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************************************************************************************************
 Function name    : Dcm_Prv_isPagedBufferTxStarted
 Syntax           : Dcm_Prv_isPagedBufferTxStarted(void)
 Description      : This Inline function is used to check whether paged buffer transmission hs stared
 Parameter        : None
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isPagedBufferTxStarted(void)
{
    return Dcm_Prv_Get_PagedBufferTxOn();
}

/***********************************************************************************************************************
 Function name    : DCM_Prv_PagedBufferTimerStart
 Syntax           : DCM_Prv_PagedBufferTimerStart(void)
 Description      : This Inline function is used to start paged buffer timer
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
LOCAL_INLINE void DCM_Prv_PagedBufferTimerStart(void)
{
    uint32 dataPagedBufferTimeoutMonitor_u32 = Dcm_Prv_Get_DataPagedBufferTimeOut();
    DCM_TimerStart(dataPagedBufferTimeoutMonitor_u32,0x00u,Dcm_PagedBufferStartTick_u32, Dcm_PagedBufferTimerStatus_uchr);
    Dcm_Prv_Set_DataPagedBufferTimeOut(dataPagedBufferTimeoutMonitor_u32);
}

/***********************************************************************************************************************
 Function name    : DCM_Prv_PagedBufferTimerProcess
 Syntax           : DCM_Prv_PagedBufferTimerProcess(void)
 Description      : This Inline function is used to process paged buffer timer
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
LOCAL_INLINE void DCM_Prv_PagedBufferTimerProcess(void)
{
    uint32 dataPagedBufferTimeoutMonitor_u32 = Dcm_Prv_Get_DataPagedBufferTimeOut();
    DCM_TimerProcess(dataPagedBufferTimeoutMonitor_u32,Dcm_PagedBufferStartTick_u32,Dcm_PagedBufferTimerStatus_uchr)
    Dcm_Prv_Set_DataPagedBufferTimeOut(dataPagedBufferTimeoutMonitor_u32);

}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_isPageLengthValid
 Syntax           : Dcm_Prv_isPageLengthValid(FilledPageLen)
 Description      : This Inline function is used to check whether page lenght is valid
 Parameter        : Dcm_MsgLenType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isPageLengthValid(Dcm_MsgLenType FilledPageLen)
{
    boolean isPageLenValid_b = FALSE;
    Dcm_DsdStatesType_ten stDsdStateTemp_en  = Dcm_Dsd_Prv_GetDsdState();

    if((FilledPageLen <= (Dcm_Prv_GetActiveTxBufferMaxLen()+1u)) && \
            (stDsdStateTemp_en == DSD_CALL_SERVICE_E))
    {
        isPageLenValid_b = TRUE;
    }

    return isPageLenValid_b;
}

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

void Dcm_Prv_PagedBufferInit(void)
{
    Dcm_RemainingPageLength = 0;
    Dcm_Prv_Reset_dataCurrentPageRespLength_u32();
    Dcm_Prv_Set_PagedBufferTxOn(FALSE);
    Dcm_adrUpdatePage_pfct = NULL_PTR;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_Set_RemainingPageLength
 Syntax           : Dcm_Prv_Set_RemainingPageLength(PduLengthType)
 Description      : On invocation of this function Remaining data left in the last page will be updated copied.
 Parameter        : PduLengthType RemainingPageLen
 Return value     : None
***********************************************************************************************************************/
void Dcm_Prv_Set_RemainingPageLength(PduLengthType RemainingPageLen)
{
    Dcm_RemainingPageLength = RemainingPageLen;
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_Get_RemainingPageLength
 Syntax           : Dcm_Prv_Get_RemainingPageLength(uint8 *)
 Description      : Remaining data left in the last page will be available on invocation of this function .
 Parameter        : PduLengthType RemainingPageLen
 Return value     : None
***********************************************************************************************************************/
void Dcm_Prv_Get_RemainingPageLength(PduLengthType *RemainingPageLen)
{
    *RemainingPageLen = Dcm_RemainingPageLength;
}

void Dcm_Prv_Set_PagedBufferTxOn(boolean pagedBufferTxOn_b)
{
    flagPagedBufferTxOn_b = pagedBufferTxOn_b;
}

boolean Dcm_Prv_Get_PagedBufferTxOn(void)
{
    return flagPagedBufferTxOn_b;
}

void Dcm_Prv_Set_dataCurrentPageRespLength_u32(uint32 dataCurrentPageRespLength_u32)
{
    CurrentPageRespLength_u32 = dataCurrentPageRespLength_u32;
}

uint32 Dcm_Prv_Get_dataCurrentPageRespLength_u32(void)
{
    return CurrentPageRespLength_u32;
}

void Dcm_Prv_Reset_dataCurrentPageRespLength_u32(void)
{
    CurrentPageRespLength_u32 = 0;
}
/**
 **************************************************************************************************
 * Dcm_Prv_PagedBufferTimeout : Static function to monitor the Paged buffer timeout
 *
 * \param           None
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void Dcm_Prv_PagedBufferTimeout(void)
{
    Dcm_IdContextType idContext_u8    = Dcm_Dsd_Prv_GetIdContext();

    if(FALSE != Dcm_Prv_isPagedBufferTxStarted())
    {
        /* Process paged buffer timer */
        DCM_Prv_PagedBufferTimerProcess();

        /* Check if paged buffer timer is elapsed */
        if(FALSE != DCM_TimerElapsed(Dcm_Prv_Get_DataPagedBufferTimeOut()))
        {
            Dcm_Prv_Det(DCM_PAGEDBUFFER_ID,DCM_E_INTERFACE_TIMEOUT);

            /* Lock required here to keep a consistency between DSL and DSD state */
            /* BSWEXT-533 */
            SchM_Enter_Dcm_Global();
            Dcm_Dsd_Prv_SetDsdState(DSD_IDLE_E);
            Dcm_Dsl_Prv_SetDslState(DSL_STATE_IDLE_E);
            /* BSWEXT-533 */
            SchM_Exit_Dcm_Global();

            /* To reset the service, call the callback application */
            DcmAppl_DcmCancelPagedBufferProcessing(idContext_u8);

            Dcm_Prv_Set_PagedBufferTxOn(FALSE);
        }
    }
}


/**
 **************************************************************************************************
 * Dcm_Prv_CheckTotalResponseLength : API called to check if the total response length has exceeded the
 * maximum possible response length for the API.
 *
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
boolean Dcm_Prv_CheckTotalResponseLength(Dcm_MsgLenType TotalResLen_u32)
{
    boolean isRespLenValid_b = FALSE;

    /* If the total response length is less than or equal to the maximum response lnegth configured for
     * paged buffer response -1(considering the SID)*/
    if(TotalResLen_u32 <= (Dcm_Prv_GetProtocolMaxResponseSize()-1uL))
    {
        isRespLenValid_b = TRUE;
    }

    return (isRespLenValid_b);
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessFirstPositiveResponse
 Syntax           : Dcm_Prv_ProcessFirstPositiveResponse(void)
 Description      : This function is used to Process first positive response for page transmission
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
static void Dcm_Prv_ProcessFirstPositiveResponse(void)
{
    /* This first call of Dcm_ProcessPage function. Frame positive response */
    uint8* responseBuffer_tpu8 =&Dcm_Prv_GetActiveTxBuffer()[2];
    Dcm_IdContextType  activeSid_u8 = Dcm_Dsd_Prv_GetIdContext();
    uint32 dataPagedBufferTimeoutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();
    boolean suppressPosResponse_b;
    const uint8* getmaximunresponsepending;
    getmaximunresponsepending= Dcm_Prv_GetMaxNumRespPending();
    responseBuffer_tpu8[0]  = activeSid_u8 | DCM_SERVICEID_ADDEND;

    /* Including Sid current page length increment by one */
    CurrentPageRespLength_u32++;

    /* Set the flag to indicate start of paged buffer */
    Dcm_Prv_Set_PagedBufferTxOn(TRUE);

    /* Change the DSD state to DSD_WAITFORTXCONF */
    Dcm_Dsd_Prv_SetDsdState(DSD_WAITFORTXCONF_E);

    /* Multicore: No Lock needed here as if Dcm gets Tx confirmation of waitpend before this line
     * DSL will be WaitForTxCOnfirm and will transmit the page immediately */
    /* And if the confirmation is received after this line then page is transmitted in the next DSL state machine */

    /* Check whether DSL is sending the wait pend or not */
    /* Multicore: No lock needed here as Dsl state is an atomic read operation */
    /* When this code is reached and paged buffer is actve there are no chances of parallel update to DSL state */

    suppressPosResponse_b = Dcm_Dsd_Prv_GetsuppressPosResponse();
    if(Dcm_Dsl_Prv_GetDslState() == DSL_STATE_WAITFOR_TXCONFIRMATION_E)
    {
        /* Empty if statement, intended here */
    }
    /*Check if positive response is sent and wait pending counter is set to Zero  */
    else if ((suppressPosResponse_b) && (*getmaximunresponsepending == 0u))
    {

        DCM_TimerStart(dataPagedBufferTimeoutMonitor_u32,0x00u,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr);
        /* Update the timeout timer */
        Dcm_Prv_Set_DataTimeOut(dataPagedBufferTimeoutMonitor_u32);
    }
    else
    {
        /* Update data in PDU structure to register total number bytes can send on paged buffer */
        Dcm_DsldPduInfo_st.SduDataPtr = &responseBuffer_tpu8[0];
        Dcm_DsldPduInfo_st.SduLength  = (PduLengthType) Dcm_Dsd_Prv_GetRespLength()+1u;
        Dcm_Prv_UpdateMetaDataPointer(Dcm_Prv_GetActiveRxPduId(),&Dcm_DsldPduInfo_st.MetaDataPtr);
        /* change the DSL such that in next call of Dcm_provideTxBuffer page should be transmitted */
        /* Multicore: No Lock needed here because when this code is reached, paged buffer is active hence
         * there are no chances of parallel update to DSL state */
        Dcm_Dsl_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION_E);
        Dcm_Dsl_Prv_SetDslSubState(DSL_SUBSTATE_DATA_READY_E);

        Dcm_Dsl_Prv_SetRespPendingCounterValue(DCM_DEFAULT_VALUE);

        Dcm_Prv_SendResponse(&Dcm_DsldPduInfo_st);
    }
}


/**
 **************************************************************************************************
 * Dcm_StartPagedProcessing : With this API, the application gives the complete response length to DCM
 *                          and starts PagedBuffer handling. Complete response length information
 *                          (in bytes) is given in pMsgContext-> resDataLen Callback functions are used
 *                          to provide paged buffer handling in DSP and RTE. More information can be found
 *                          in the sequence chart in chapter 9.3.6 Process Service Request with PagedBuffer.
 *
 * \param           pMsgContext: message context table given by the service
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
/* Violation of AUTOSAR to over come MISRA warning */
void Dcm_StartPagedProcessing (const Dcm_MsgContextType * pMsgContext )
{
    Dcm_MsgType activeTxBuffer =&Dcm_Prv_GetActiveTxBuffer()[3];

    /* Check whether the service is sending less than maximum allowed paged buffer response buffer size for the protocol
     *  and this function is called only once*/
    if(FALSE != Dcm_Prv_CheckTotalResponseLength(pMsgContext->resDataLen))
    {
        /* Inform the service to fill the data into page */
        if(Dcm_adrUpdatePage_pfct != NULL_PTR)
        {
            (*Dcm_adrUpdatePage_pfct)(&activeTxBuffer[0],Dcm_Dsd_Prv_GetRespMaxLength());
        }
    }
    else
    {
        Dcm_Prv_Det(DCM_PROCESSINGDONE_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
    }
}
/**
 **************************************************************************************************
 * Dcm_ProcessPage:Application requests transmission of filled page More information can be found
 *                 in the sequence chart in chapter 9.3.6 Process Service Request with PagedBuffer.
 * \param           FilledPageLen: Filled data length in current page
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void Dcm_ProcessPage(Dcm_MsgLenType FilledPageLen )
{
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
    if(FALSE == Dcm_Prv_isProtocolPreemptionInitiated())
#endif
    {
        if(FALSE != Dcm_Prv_isPageLengthValid(FilledPageLen))
        {
            Dcm_Prv_Set_dataCurrentPageRespLength_u32(FilledPageLen);

            if(FALSE != Dcm_Prv_isPagedBufferTxStarted())
            {
                if (FilledPageLen != 0u)
                {
                    /* Change the DSD state to DSD_WAITFORTXCONF
                     * Multicore: DSD state is changed only in MainFunction context OR
                     * in ROE/TxConfirmation APIs when DSD is IDLE/DSD is in SEND state.
                     * So there is no parallel writing when DSD is set to DSD_CALL_SERVICE
                     */

                    Dcm_Dsd_Prv_SetDsdState(DSD_WAITFORTXCONF_E);

                    /* This call is for sending the consecutive pages
                     * In next call of Dcm_provideTxBuffer this page will be sent
                     * Multicore: No lock needed here as Dsl state is an atomic operation
                     * Also when this part of code is reached there is no chance that
                     * there is a parallel update to DSL state as the state machine is blocked by paged buffer
                     */
                    Dcm_Dsl_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION_E);
                    Dcm_Dsl_Prv_SetDslSubState(DSL_SUBSTATE_DATA_READY_E);
                }
                else
                {
                    /* Start Paged buffer timeout timer */
                    Dcm_Prv_Reset_dataCurrentPageRespLength_u32();
                    DCM_Prv_PagedBufferTimerStart();
                    Dcm_Prv_PagedBufferTimeout();
                }
            }
            else
            {
                Dcm_Prv_ProcessFirstPositiveResponse();
            }
        }
    }
}


#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
