/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"

/***********************************************************************************************************************
 *    Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

static boolean Dcm_ConditionChecksPassed (Dcm_ProtocolType * ActiveProtocol, const uint16 * ConnectionId, const uint16 * TesterSourceAddress);

/* Dcm_GetActiveProtocol : API to get the active protocol id */
Std_ReturnType Dcm_GetActiveProtocol(Dcm_ProtocolType * ActiveProtocol, uint16 * ConnectionId, uint16 * TesterSourceAddress)
{
    if(Dcm_ConditionChecksPassed(ActiveProtocol, ConnectionId, TesterSourceAddress))
    {
       *(ActiveProtocol) =  Dcm_Prv_GetActiveProtocolType();
       *(ConnectionId) =  Dcm_Prv_GetActiveConnectionId();
       *(TesterSourceAddress) =  Dcm_Prv_GetActiveTesterSrcAddress();
    }
    return(E_OK);
}

static boolean Dcm_ConditionChecksPassed (Dcm_ProtocolType * ActiveProtocol, const uint16 * ConnectionId, const uint16 * TesterSourceAddress)
{
    boolean checksPassed = TRUE;

    if(!Dcm_Prv_IsDcmInitialized())
    {
        checksPassed = FALSE;
        Dcm_Prv_Det(DCM_GETACTIVEPROTOCOL_ID, DCM_E_UNINIT);
    }

    else if ((ActiveProtocol == NULL_PTR) || (ConnectionId == NULL_PTR) || (TesterSourceAddress == NULL_PTR) )
    {
        checksPassed = FALSE;
        Dcm_Prv_Det(DCM_GETACTIVEPROTOCOL_ID, DCM_E_PARAM_POINTER);
    }

    else if (!Dcm_Prv_IsProtocolStarted())
    {
        checksPassed = FALSE;
        *(ActiveProtocol) = DCM_NO_ACTIVE_PROTOCOL;
    }

    else
    {
        /*no further actions needed. Just return true, if all checks passed*/
    }


    return checksPassed;
}



/* Dcm_GetActiveProtocolRxBufferSize : API to get the Active protocol RX buffer size */
Std_ReturnType Dcm_GetActiveProtocolRxBufferSize(Dcm_MsgLenType * const rxBufferLength)
{
    Std_ReturnType bufferSizeStatus = E_NOT_OK;

    if(NULL_PTR != rxBufferLength)
    {
        if(FALSE != Dcm_Prv_IsProtocolStarted())
        {
            *(rxBufferLength) = Dcm_Prv_GetActiveRxBufferMaxLen();
            bufferSizeStatus = E_OK;
        }
    }

    return (bufferSizeStatus);
}


/* Dcm_GetActiveServiceTable : API to get the service table id */
void Dcm_GetActiveServiceTable (uint8 * ActiveServiceTable)
{
    if(NULL_PTR != ActiveServiceTable)
    {
        *(ActiveServiceTable) = Dcm_Prv_GetActiveSrvTabId();
    }
}


#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)

/* Dcm_GetMediumOfActiveConnection: API to get Medium information(ie.Can,Flexray..etc) available in the ComMChannel the active connection.
 *                                  This is explicitly provided only for rba_DiagAdapt.
 *                                  This should be invoked only by rba_DiagAdapt only when new protocol request is received from Tester.*/
Std_ReturnType Dcm_GetMediumOfActiveConnection(\
        Dcm_DslDsd_MediumType_ten * const ActiveMediumId)
{
    /* Local variable */
    uint8 Channel_Idx_u8 = 0x0u;  /* To store the active ComM channel index */
    if(ActiveMediumId != NULL_PTR)
    {
        Channel_Idx_u8 = Dcm_Prv_GetActiveComMChannelIndex();
        /*Get the MediumId of the active connection*/
        *ActiveMediumId = Dcm_active_commode_e[Channel_Idx_u8].MediumId;
    }
    return(E_OK);
}

#endif

Std_ReturnType Dcm_StartProtocol(Dcm_ProtocolType ProtocolID,uint16 TesterSourceAddress, uint16 ConnectionId)
{
#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS !=0))
    uint32_least idxIndex_qu32;
#endif
    Std_ReturnType dataReturnType_u8;

    /* Call DcmAppl function to start the protocol */
    dataReturnType_u8 = DcmAppl_DcmStartProtocol(ProtocolID,TesterSourceAddress,ConnectionId);

#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS !=0))
    if(dataReturnType_u8 == E_OK)
    {
        /* Call all configured functions in RTE */
        for(idxIndex_qu32 = 0x00 ; idxIndex_qu32<Rte_NPorts_CallbackDCMRequestServices_R() ; idxIndex_qu32++)
        {
            dataReturnType_u8 =((Rte_Ports_CallbackDCMRequestServices_R())[idxIndex_qu32].Call_StartProtocol)(ProtocolID,TesterSourceAddress,ConnectionId);

            if(Dcm_IsInfrastructureErrorPresent_b(dataReturnType_u8) != FALSE )
            {
                dataReturnType_u8 = DCM_INFRASTRUCTURE_ERROR;

            }
            else if((dataReturnType_u8 == DCM_E_PROTOCOL_NOT_ALLOWED) || (dataReturnType_u8 == E_NOT_OK))
            {
                /* Do nothing */
            }
            else
            {
                dataReturnType_u8 = E_OK;
            }
            if(dataReturnType_u8 != E_OK)
            {
                break;
            }
        }
    }
#endif
    return(dataReturnType_u8);
}

void Dcm_StopProtocol(Dcm_ProtocolType ProtocolID,uint16 TesterSourceAddress, uint16 ConnectionId)
{
#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS !=0))
    uint32_least idxIndex_qu32;
#endif

    /* Call DcmAppl function to stop the protocol */
    (void)DcmAppl_DcmStopProtocol(ProtocolID,TesterSourceAddress,ConnectionId);

#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS!=0))
    for(idxIndex_qu32 =0x00 ; idxIndex_qu32<Rte_NPorts_CallbackDCMRequestServices_R() ; idxIndex_qu32++)
    {
        // Call all configured functions in RTE
        (void)((Rte_Ports_CallbackDCMRequestServices_R())[idxIndex_qu32].Call_StopProtocol)(ProtocolID,TesterSourceAddress,ConnectionId);
    }
#endif
}


#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
