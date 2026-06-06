
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#if(DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
#include "SchM_Dcm.h"
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
#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static Dcm_ConfirmationStatusType ConfirmationStatus_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16
#include "Dcm_MemMap.h"
static uint16 Dcm_TesterSrcAddressTxConfirmation_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16
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

static void Dcm_DspConfirmation(uint8 SID, uint8 ReqType,uint16 ConnectionId,Dcm_ConfirmationStatusType ConfirmationStatus,Dcm_ProtocolType ProtocolType,uint16 TesterSourceAddress)
{
    uint8 idxService_u8;
    uint8 srvTabId_u8                                                   = Dcm_Prv_GetActiveSrvTabId();
    uint8 numOfServices_u8                                              = Dcm_Cfg_Dsd_pcst->sidTables_pcast[srvTabId_u8].numOfServices_u8;
    const Dcm_DsdServiceTableConfigType_tst *Dcm_DsdSrvTableCfg_pst     = Dcm_Prv_GetServiceTable();

    for(idxService_u8 =0;idxService_u8<numOfServices_u8;idxService_u8++)
    {
        if(SID == Dcm_DsdSrvTableCfg_pst[idxService_u8].sid_u8)
        {
            (Dcm_DsdSrvTableCfg_pst[idxService_u8].serviceConfirmatione_pfct)(SID,ReqType,ConnectionId,ConfirmationStatus,ProtocolType,TesterSourceAddress);
            break;
        }
    }

}


#if((DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF) && (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF))
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessSessionChangeOnWarmResp
 Syntax           : Dcm_Prv_ProcessSessionChangeOnWarmResp(void)
 Description      : This function is used to process session chnage after warm response
 Parameter        : None
 Return value     : None
 ***********************************************************************************************************************/
static void Dcm_Prv_ProcessSessionChangeOnWarmResp (void)
{
    Dcm_SesChgOnWarmResp_b = FALSE;


#if (DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
    (void)SchM_Switch_Dcm_DcmDiagnosticSessionControl(Dcm_Dsp_Session[Dcm_ctDiaSess_u8].SessionMode);
#endif
    (void)DcmAppl_Switch_DcmDiagnosticSessionControl(Dcm_Dsp_Session[Dcm_ctDiaSess_u8].session_level);

    /* Update the P2 Timer values */
    Dcm_DsldSetsessionTiming(Dcm_Dsp_Session[Dcm_ctDiaSess_u8].P2str_max_u32,Dcm_Dsp_Session[Dcm_ctDiaSess_u8].P2_max_u32);


    /* Activate New Session requested */
    Dcm_Prv_SetSesCtrlType(Dcm_Dsp_Session[Dcm_ctDiaSess_u8].session_level);
}
#endif

/***********************************************************************************************************************
 Function name    : Dcm_Dsd_Prv_Confirmation
 Syntax           : Dcm_Dsd_Prv_Confirmation(Std_ReturnType Transmissonresult)
 Description      : Function called from DSL after response transmission
 Parameter        : Std_ReturnType
 Return value     : void
 ***********************************************************************************************************************/

void Dcm_Dsd_Prv_Confirmation(Std_ReturnType Transmissonresult)
{

    Dcm_TesterSrcAddressTxConfirmation_u16    = Dcm_Prv_GetActiveTesterSrcAddress();

    ConfirmationStatus_u8 = (Transmissonresult == E_OK) ?
            ((Dcm_Prv_GetResponsetype() == DCM_POS_RESPONSE)?DCM_RES_POS_OK:DCM_RES_NEG_OK) :
            ((Dcm_Prv_GetResponsetype() == DCM_POS_RESPONSE)?DCM_RES_POS_NOT_OK:DCM_RES_NEG_NOT_OK);

    Dcm_Dsd_Prv_SetDsdState(DSD_SENDTXCONF_APPL_E);

#if((DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF) && (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF))
    if(Dcm_SesChgOnWarmResp_b == TRUE)
    {
        Dcm_Prv_ProcessSessionChangeOnWarmResp();
    }
#endif

    Dcm_Prv_InactivateComMChannel();

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_AuthTimerHandling(DCM_TIMER_START,Dcm_Prv_GetActiveRxPduId());
#endif

}

/***********************************************************************************************************************
 Function name    : Dcm_Dsd_Prv_SendTx_Confirmation
 Syntax           : Dcm_Dsd_Prv_SendTx_Confirmation(void)
 Description      : Function trigger Internal Confirmation and Application Confirmations
 Parameter        : void
 Return value     : void
 ***********************************************************************************************************************/

void Dcm_Dsd_Prv_SendTx_Confirmation(void)
{
#if(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF)
    PduIdType DcmRxPduId_u16          = Dcm_Prv_GetActiveRxPduId();
#endif
    uint8 ReqType_u8                  = Dcm_Prv_GetActiveReqType();
    uint16 ConnectionId_u16           = Dcm_Prv_GetActiveConnectionId();
    uint16 TesterSourceAddress_u16    = Dcm_TesterSrcAddressTxConfirmation_u16;
    Dcm_IdContextType idContext_u8    = Dcm_Dsd_Prv_GetIdContext();
    Dcm_ProtocolType ProtocolType_u8  = Dcm_Prv_GetActiveProtocolType();

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    /*Check if paged buffer flag is active*/
    if (Dcm_Prv_Get_PagedBufferTxOn() != FALSE)
    {
        /* Full response is sent on Paged buffer *
         *Set the paged buffer flag to False */
        Dcm_Prv_Set_PagedBufferTxOn(FALSE);
        if (ConfirmationStatus_u8 == DCM_RES_POS_NOT_OK)
        {
            /* Invoke callback function in case the paged buffer transmission is unsuccessful
             * since the service has not yet finished the processing */
            DcmAppl_DcmCancelPagedBufferProcessing(idContext_u8);
        }
    }
#endif

    if(DCM_UDS_TESTER_SOURCE == Dcm_Dsd_Prv_GetSourceofReq())
    {
        if (Dcm_Prv_GetResponsebyDSD() == FALSE)
        {
            /* Service exists in DSP. Give the confirmation to DSP */
            Dcm_DspConfirmation(idContext_u8, ReqType_u8, ConnectionId_u16,\
                    ConfirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);

        }
        else
        {
            if (Dcm_Prv_GetResponsetype()==DCM_MAXPENDING_EXEEDED)
            {
                DcmAppl_DcmConfirmation_GeneralReject(idContext_u8, ReqType_u8, ConnectionId_u16,\
                        ConfirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);
                Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest();
            }
            else
            {
                DcmAppl_DcmConfirmation_DcmNegResp(idContext_u8, ReqType_u8, ConnectionId_u16,\
                        ConfirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);
            }
        }

#if ((DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS!=0u)||(DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS!=0))
        Dcm_Dsd_Prv_CallRTEConfirmation(ConfirmationStatus_u8,TesterSourceAddress_u16,DCM_UDSCONTEXT);
#endif
    }
#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
    else if(DCM_ROE_SOURCE == Dcm_Dsd_Prv_GetSourceofReq())
    {
        Dcm_Prv_ROEResetOnConfirmation();
        DcmAppl_DcmConfirmation(idContext_u8, ReqType_u8, ConnectionId_u16,\
                ConfirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);
    }
#endif
#if(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF)
    else if(DCM_RDPI_SOURCE == Dcm_Dsd_Prv_GetSourceofReq())
    {
        /* Give the confirmation to application */
        DcmAppl_DcmConfirmationRDPI(DCM_RDPI_SID,DcmRxPduId_u16,ConfirmationStatus_u8);
    }
#endif
    else
    {
        /*empty else condition*/
    }

}

#if ((DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS!=0u)||(DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS!=0))
/***********************************************************************************************************************
 Function name    : Dcm_Dsd_Prv_CallRTEConfirmation
 Syntax           : Dcm_Dsd_Prv_CallRTEConfirmation(Dcm_ConfirmationStatusType ConfirmationStatus_u8,uint16 TesterSourceAddress,boolean Context)
 Description      : Function to give the confirmation to Supplier/Manufacturer in case the RTE is enabled
 Parameter        : Dcm_ConfirmationStatusType,uint16, boolean
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Dsd_Prv_CallRTEConfirmation(Dcm_ConfirmationStatusType confirmationStatus_u8,uint16 TesterSourceAddress, boolean Context)
{

    uint8 idxIndex_qu8;

    uint8 ReqType_u8 ;
    uint16 ConnectionId_u16;
    uint16 TesterSourceAddress_u16 = TesterSourceAddress;
    Dcm_IdContextType idContext_u8;
    Dcm_ProtocolType ProtocolType_u8;

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(Context == DCM_OBDCONTEXT)
    {
        ConnectionId_u16 = Dcm_Prv_GetObdActiveConnection()->rxConnId_u16;
        ProtocolType_u8 = Dcm_Prv_GetObdActiveProtocolRow()->protocolType;
        ReqType_u8 = Dcm_OBDMsgContext_st.msgAddInfo.reqType;
        idContext_u8 = Dcm_OBDMsgContext_st.idContext;
    }
    else
#endif
    {
        ReqType_u8                  = Dcm_Prv_GetActiveReqType();
        ConnectionId_u16            = Dcm_Prv_GetActiveConnectionId();
        idContext_u8                = Dcm_Dsd_Prv_GetIdContext();
        ProtocolType_u8             = Dcm_Prv_GetActiveProtocolType();
    }
#if (DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS!=0u)
    for(idxIndex_qu8=0x00u; idxIndex_qu8<DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS; idxIndex_qu8++)
    {
        (void)(*Dcm_Cfg_Dsd_pcst->ManufactureConfirmation_afp[idxIndex_qu8])(idContext_u8, ReqType_u8, ConnectionId_u16,\
                confirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);

    }

#endif

#if(DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS!=0)
    for(idxIndex_qu8=0x00u; idxIndex_qu8<DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS; idxIndex_qu8++)
    {
        (void)(*Dcm_Cfg_Dsd_pcst->SupplierConfirmation_afp[idxIndex_qu8])(idContext_u8, ReqType_u8, ConnectionId_u16,\
                confirmationStatus_u8, ProtocolType_u8,TesterSourceAddress_u16);

    }

#endif
#if (DCM_PARALLELPROCESSING_ENABLED == DCM_CFG_OFF)
    (void)Context;
#endif

}
#endif

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
