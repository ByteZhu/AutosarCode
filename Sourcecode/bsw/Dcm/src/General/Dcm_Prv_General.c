
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#if (DCM_CFG_DET_SUPPORT_ENABLED != DCM_CFG_OFF)
#include "Det.h"
#endif
#if (RBA_DCMPMA_CFG_PLANTMODEACTIVATION_ENABLED != DCM_CFG_OFF)
#include "rba_DcmPma.h"
#endif
#include "Dcm_Prv.h"

/*TODO: recheck placholders & place them into correct submodules*/

const Dcm_Dsld_protocol_tableType * Dcm_DsldProtocol_pcst; /*RDPI, KWP, Bootloader?*/
Dcm_DsldInternalStructureType_tst Dcm_DsldGlobal_st; /*many places*/

#ifndef DCM_CFG_NUM_RDPITYPE2_TXPDU
#define DCM_CFG_NUM_RDPITYPE2_TXPDU 1
#endif
Dcm_DslRxPduArray_tst Dcm_DslRxPduArray_ast[DCM_CFG_TOTAL_RX_PDUID];
Dcm_DslTxType_tst Dcm_DslTransmit_st;/*DSP, PagedBuffer?*/
PduInfoType Dcm_DsldPduInfo_st;
const Dcm_Dsld_confType Dcm_Dsld_Conf_cs =
{
   NULL_PTR,                 /* Reference to Rx table array */
   NULL_PTR,                      /* Reference to Tx table array */
   NULL_PTR,                /* Reference to Connection table array */
   NULL_PTR,                  /* Reference to protocol table */
   NULL_PTR,            /* Reference to sid table      */
   NULL_PTR,       /* Session look up table       */
   NULL_PTR        /* Security look up table      */
};
const uint8 * Dcm_DsldRxTable_pcu8;
const Dcm_Dsld_ServiceType * Dcm_DsldSrvTable_pcst;
Dcm_MsgContextType Dcm_DsldMsgContext_st;

/*############################# end #############################################*/

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

static const Dcm_DslProtocolRowConfigType_tst *Dcm_ActiveProtocolRowCfg_pcast;
static const Dcm_DslMainConnConfigType_tst    *Dcm_ActiveMainConnCfg_pcast;
static PduIdType Dcm_Uds_ActiveRxpduId;
static PduLengthType Dcm_Uds_ActiveRequestLength;
static PduIdType  Dcm_Uds_ActiveConnectionIdx;

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
uint8 Dcm_tempMetaData_NRC21_u8[4];
uint8 Dcm_tempMetaData_u8[4];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

static const Dcm_DslProtocolRowConfigType_tst *Dcm_ActiveObdProtocolRowCfg_pcast;
static const Dcm_DslMainConnConfigType_tst    *Dcm_ActiveObdMainConnCfg_pcast;
static PduLengthType Dcm_Obd_ActiveRequestLength;
static PduIdType  Dcm_Obd_ActiveConnectionIdx;

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
uint8 Dcm_tempOBDMetaData_NRC21_u8[4];
uint8 Dcm_tempOBDMetaData_u8[4];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
static PduIdType Dcm_Obd_ActiveRxpduId = DCM_CFG_INVALID_RX_PDUID;
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/*Variables to store the SA and TA for transmission of final response for Parallel Processing*/
static uint16 Dcm_OBD_MetaDataTx_SourceAddress_u16;
static uint16 Dcm_OBD_MetaDataTx_TargetAddress_u16;
/*Variables to store the SA and TA for transmission of NRC 21 for Parallel Processing*/
static uint16 Dcm_OBD_MetaDataTx_Nrc21_SourceAddress_u16;
static uint16 Dcm_OBD_MetaDataTx_Nrc21_TargetAddress_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#endif

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_MsgType  adrBufferPtr_pu8;      /* pointer to hold the address of the processing request buffer */
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static uint8 Dcm_Uds_ReqType_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static uint8 Dcm_Obd_ReqType_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
static uint8_least Dcm_CurrentProtocol_Idx_u8;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
static boolean IsProtocolStarted_b;
static boolean IsCommunicationActive_b;
static boolean IsP3TimerMonitorRequired_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"


static uint32 s_DataPagedBufferTimeOutMonitor_u32;

#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
static uint32 s_DataTimeOutMonitor_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/*Variables to store the SA and TA for transmission of final response*/
static uint16 Dcm_MetaDataTx_SourceAddress_u16;
static uint16 Dcm_MetaDataTx_TargetAddress_u16;
/*Variables to store the SA and TA for transmission of NRC 21*/
static uint16 Dcm_MetaDataTx_Nrc21_SourceAddress_u16;
static uint16 Dcm_MetaDataTx_Nrc21_TargetAddress_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/*
 **********************************************************************************************************************
 * Defines/Macros/function
 **********************************************************************************************************************
*/

void Dcm_General_Init(void)
{
    Dcm_ActiveProtocolRowCfg_pcast = NULL_PTR;
    Dcm_ActiveMainConnCfg_pcast = NULL_PTR;
    Dcm_Uds_ActiveRxpduId = DCM_CFG_INVALID_RX_PDUID;
    Dcm_Uds_ActiveRequestLength = 0u;
    Dcm_Uds_ActiveConnectionIdx = 0u;
    Dcm_Uds_ReqType_u8 = DCM_PHYSICAL_REQUEST;
    Dcm_CurrentProtocol_Idx_u8 = 0u;

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    Dcm_ActiveObdProtocolRowCfg_pcast = NULL_PTR;
    Dcm_ActiveObdMainConnCfg_pcast = NULL_PTR;
    Dcm_Obd_ActiveRxpduId = DCM_CFG_INVALID_RX_PDUID;
    Dcm_Obd_ActiveRequestLength = 0u;
    Dcm_Obd_ActiveConnectionIdx = 0u;
    Dcm_Obd_ReqType_u8 = DCM_PHYSICAL_REQUEST;
#endif

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
   adrBufferPtr_pu8 = NULL_PTR;
#endif

   IsProtocolStarted_b = FALSE;
   IsCommunicationActive_b = FALSE;
   IsP3TimerMonitorRequired_b = FALSE;

   #if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
   s_DataPagedBufferTimeOutMonitor_u32 = 0u;
   #endif
}

void Dcm_Prv_Det(uint8 DCM_ApiId,uint8 DCM_ErrorId)
{
#if(DCM_CFG_DET_SUPPORT_ENABLED)
   (void)Det_ReportError(DCM_MODULE_ID, DCM_INSTANCE_ID , DCM_ApiId, DCM_ErrorId);
#else
   (void)DCM_ApiId;
   (void)DCM_ErrorId;
#endif
}

#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
void Dcm_Prv_SetRxBuffer(Dcm_MsgType  Dcm_DslBufferPtr_pu8)
{
    adrBufferPtr_pu8 = Dcm_DslBufferPtr_pu8;
}
#endif


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
void Dcm_Prv_SetObdActiveRxPduId(PduIdType rxpduId, PduLengthType requestLength)
{
    const Dcm_DslConnectionConfigType_tst  *dslConnection_pcast;

    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        Dcm_Obd_ActiveRxpduId = rxpduId;
        Dcm_Obd_ActiveRequestLength = requestLength;
        Dcm_Obd_ActiveConnectionIdx = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
        dslConnection_pcast = &Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Obd_ActiveConnectionIdx];

        Dcm_ActiveObdProtocolRowCfg_pcast = &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[dslConnection_pcast->protocolRowIdx_u8];
        Dcm_ActiveObdMainConnCfg_pcast    = &Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[dslConnection_pcast->mainConnectionIdx_u8];

        if(Dcm_Obd_ActiveRxpduId >= DCM_CFG_INDEX_FUNC_RX_PDUID)
        {
            Dcm_Obd_ReqType_u8 = DCM_FUNCTIONAL_REQUEST;
        }
        else
        {
            Dcm_Obd_ReqType_u8 = DCM_PHYSICAL_REQUEST;
        }
    }

}


const Dcm_DslProtocolRowConfigType_tst * Dcm_Prv_GetObdActiveProtocolRow(void)
{
    return Dcm_ActiveObdProtocolRowCfg_pcast;
}

const Dcm_DslMainConnConfigType_tst * Dcm_Prv_GetObdActiveConnection(void)
{
    return Dcm_ActiveObdMainConnCfg_pcast;
}

PduIdType Dcm_Prv_GetObdActiveTxPduId(void)
{
    if(Dcm_ActiveObdMainConnCfg_pcast != NULL_PTR)
    {
        return Dcm_ActiveObdMainConnCfg_pcast->txPduId;
    }
    else
    {
        return DCM_CFG_INVALID_TX_PDUID;
    }
}


void Dcm_Prv_ResetObdActiveRxPduId(void)
{
    Dcm_Obd_ActiveRxpduId = DCM_CFG_INVALID_RX_PDUID;
}

uint8 Dcm_Prv_GetObdActiveProtocolPriority(void)
{
    return Dcm_ActiveObdProtocolRowCfg_pcast->priority_u8;
}

PduIdType Dcm_Prv_GetObdActiveRxPduId(void)
{
    return Dcm_Obd_ActiveRxpduId;
}

#endif

const Dcm_DslProtocolRowConfigType_tst* Dcm_Prv_GetProtocolRow(PduIdType rxpduId)
{
    PduIdType connectionIdx=0;
    uint8 protocolIdx_u8=0;
    const Dcm_DslProtocolRowConfigType_tst *protocolRowCfg = NULL_PTR;

    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        connectionIdx = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
        protocolIdx_u8   = Dcm_Cfg_Dsl_pcst->dslConnection_pcast[connectionIdx].protocolRowIdx_u8;
        protocolRowCfg = &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[protocolIdx_u8];
    }

    return protocolRowCfg;
}

uint8 Dcm_Prv_GetProtocolIndex(uint8 connectionIdx_u8)
{
    uint8 protocolIndex = 0;

    if(connectionIdx_u8 < DCM_CFG_TOTAL_DSL_CONNECTIONS)
    {
        protocolIndex = Dcm_Cfg_Dsl_pcst->dslConnection_pcast[connectionIdx_u8].protocolRowIdx_u8;
    }
    return protocolIndex;
}

PduIdType Dcm_Prv_GetConnectionIndex(PduIdType rxpduId)
{
    PduIdType connectionIndex =0;

    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        connectionIndex = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
    }
    return connectionIndex;
}

uint32 Dcm_Prv_GetRxBufferMaxLen(PduIdType rxpduId)
{
    return Dcm_Prv_GetProtocolRow(rxpduId)->rxBufferSize_u32;
}

uint8 Dcm_Prv_GetsrvTabId(uint16 connectionIdx_u8)
{
    uint8 protocolIdx_u8;
    uint8 srvTabId = 0;

    if(connectionIdx_u8 < DCM_CFG_TOTAL_DSL_CONNECTIONS)
    {
        protocolIdx_u8 = Dcm_Cfg_Dsl_pcst->dslConnection_pcast[connectionIdx_u8].protocolRowIdx_u8;
        srvTabId = Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[protocolIdx_u8].srvTableId_u8;
    }

    return srvTabId;
}


const Dcm_DslMainConnConfigType_tst* Dcm_Prv_GetMainConnection(PduIdType rxpduId)
{
    const Dcm_DslConnectionConfigType_tst  *dslConnection_pcast;
    PduIdType  ConnectionIdx;
    const Dcm_DslMainConnConfigType_tst *mainConnection_pcast = NULL_PTR;

    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        ConnectionIdx = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
        dslConnection_pcast    = &Dcm_Cfg_Dsl_pcst->dslConnection_pcast[ConnectionIdx];
        mainConnection_pcast = &Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[dslConnection_pcast->mainConnectionIdx_u8];
    }

    return mainConnection_pcast;
}


const Dcm_DslMainConnConfigType_tst * Dcm_Prv_GetActiveConnection(void)
{
    return Dcm_ActiveMainConnCfg_pcast;
}

void Dcm_Prv_SetActiveRxPduId(PduIdType rxpduId, PduLengthType requestLength)
{
    const Dcm_DslConnectionConfigType_tst  *dslConnection_pcast;

    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        Dcm_Uds_ActiveRxpduId = rxpduId;
        Dcm_Uds_ActiveRequestLength = requestLength;
        Dcm_Uds_ActiveConnectionIdx = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
        dslConnection_pcast = &Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Uds_ActiveConnectionIdx];

        Dcm_ActiveProtocolRowCfg_pcast = &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[dslConnection_pcast->protocolRowIdx_u8];
        Dcm_ActiveMainConnCfg_pcast    = &Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[dslConnection_pcast->mainConnectionIdx_u8];

        if(Dcm_Uds_ActiveRxpduId >= DCM_CFG_INDEX_FUNC_RX_PDUID)
        {
            Dcm_Uds_ReqType_u8 = DCM_FUNCTIONAL_REQUEST;
        }
        else
        {
            Dcm_Uds_ReqType_u8 = DCM_PHYSICAL_REQUEST;
        }
    }
}

void Dcm_Prv_SetActiveConnectionIdx(PduIdType rxpduId, PduIdType connectionIdx)
{
    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        Dcm_Uds_ActiveConnectionIdx = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
    }
    else if(connectionIdx < DCM_CFG_TOTAL_DSL_CONNECTIONS)
    {
        Dcm_Uds_ActiveConnectionIdx = connectionIdx;
    }
    else
    {
        /* Do Nothing */
    }
}

void Dcm_Prv_SetMainConnection(PduIdType connectionIdx)
{
    const Dcm_DslConnectionConfigType_tst  *dslConnection_pcast;

    if(connectionIdx < DCM_CFG_TOTAL_DSL_CONNECTIONS)
    {
        dslConnection_pcast = &Dcm_Cfg_Dsl_pcst->dslConnection_pcast[connectionIdx];
        Dcm_ActiveProtocolRowCfg_pcast = &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[dslConnection_pcast->protocolRowIdx_u8];
        Dcm_ActiveMainConnCfg_pcast    = &Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[dslConnection_pcast->mainConnectionIdx_u8];
    }
}


PduIdType Dcm_Prv_GetActiveRxPduId(void)
{
    return Dcm_Uds_ActiveRxpduId;
}

Dcm_MsgType Dcm_Prv_GetActiveRxBuffer(void)
{
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    return adrBufferPtr_pu8;
#else
    return Dcm_ActiveProtocolRowCfg_pcast->rxBuffer_u8;
#endif
}

Dcm_MsgType Dcm_Prv_GetActiveTxBuffer(void)
{
    return Dcm_ActiveProtocolRowCfg_pcast->txBuffer_u8;
}

uint32 Dcm_Prv_GetActiveRxBufferMaxLen(void)
{
    return Dcm_ActiveProtocolRowCfg_pcast->rxBufferSize_u32;
}

uint32 Dcm_Prv_GetActiveTxBufferMaxLen(void)
{
    return Dcm_ActiveProtocolRowCfg_pcast->txBufferSize_u32;
}

uint8 Dcm_Prv_GetActiveSrvTabId(void)
{
    uint8 activeSrvTabId_u8 = 0u;
#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    uint8 sourceofReq_u8=Dcm_Dsd_Prv_GetSourceofReq();
    Dcm_DslStatesType_ten getDslState=Dcm_Dsl_Prv_GetDslState();
#endif


#if (RBA_DCMPMA_CFG_PLANTMODEACTIVATION_ENABLED != DCM_CFG_OFF)

    if(rba_DcmPma_PlantModeStatus_b != FALSE)
      {
        activeSrvTabId_u8 = RBA_DCMPMA_CFG_SIDTABLE_RBACTIVE;
      }
    else
#endif
      {
        #if(DCM_ROE_ENABLED == DCM_CFG_ON)
        if((DSL_STATE_ROETYPE1_RECEIVED_E == getDslState) &&
          (DCM_ROE_SOURCE == sourceofReq_u8))
        {
            activeSrvTabId_u8 = Dcm_Prv_GetActiveRoeConnection()->srvTableId_u8;
        }
        else
        #endif
        {
          if(Dcm_ActiveProtocolRowCfg_pcast != NULL_PTR)
            {
              activeSrvTabId_u8 = Dcm_ActiveProtocolRowCfg_pcast->srvTableId_u8;
            }
        }
      } /*PMA Closing Braces*/

    return activeSrvTabId_u8;
}

uint8 Dcm_Prv_GetActiveReqType(void)
{
    return Dcm_Uds_ReqType_u8;
}

Dcm_ProtocolType Dcm_Prv_GetActiveProtocolType(void)
{
    if(Dcm_ActiveProtocolRowCfg_pcast==NULL_PTR)
    {
        return DCM_NO_ACTIVE_PROTOCOL;
    }
    else
    {
        return Dcm_ActiveProtocolRowCfg_pcast->protocolType;
    }

}

uint16 Dcm_Prv_GetProtocolMaxResponseSize(void)
{
  return Dcm_ActiveProtocolRowCfg_pcast->maximumResponseSize_u16;
}

uint8 Dcm_Prv_GetActiveDemClientId(void)
{
    uint8 activeDemClientId_u8 = 0u;
    if(Dcm_ActiveProtocolRowCfg_pcast != NULL_PTR)
    {
        activeDemClientId_u8 = Dcm_ActiveProtocolRowCfg_pcast->demClientId_u8;
    }

    return activeDemClientId_u8;
}

uint8 Dcm_Prv_GetActiveProtocolPriority(void)
{
    return Dcm_ActiveProtocolRowCfg_pcast->priority_u8;
}

uint32 Dcm_Prv_GetActive_P2ServerTimeAdjust(void)
{
    return Dcm_ActiveProtocolRowCfg_pcast->timStrP2ServerAdjust_u32;
}

uint32 Dcm_Prv_GetActive_P2StrServerTimeAdjust(void)
{
    return Dcm_ActiveProtocolRowCfg_pcast->timStrP2StarServerAdjust_u32;
}

uint16 Dcm_Prv_GetActiveConnectionId(void)
{
    return Dcm_ActiveMainConnCfg_pcast->rxConnId_u16;
}

uint8 Dcm_Prv_GetActiveComMChannelId(void)
{
    uint8 activeComMChannelId_u8 = 0;
    if(Dcm_ActiveMainConnCfg_pcast != NULL_PTR)
    {
        activeComMChannelId_u8=  Dcm_ActiveMainConnCfg_pcast->comMChannelId_u8;
    }
    return activeComMChannelId_u8;
}

uint8 Dcm_Prv_GetActiveComMChannelIndex(void)
{
    return Dcm_ActiveMainConnCfg_pcast->channel_idx_u8;
}

PduIdType Dcm_Prv_GetActiveTxPduId(void)
{
    if(Dcm_ActiveMainConnCfg_pcast != NULL_PTR)
    {
        return Dcm_ActiveMainConnCfg_pcast->txPduId;
    }
    else
    {
        return DCM_CFG_INVALID_TX_PDUID;
    }
}

PduIdType Dcm_Prv_GetTxPduId(PduIdType rxpduId)
{
    PduIdType connectionIdx_u16;
    const Dcm_DslConnectionConfigType_tst *connection_pcast;
    const  Dcm_DslMainConnConfigType_tst *mainConnCfg_pcast;
    PduIdType txpduid = DCM_CFG_INVALID_TX_PDUID;

    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        connectionIdx_u16 = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
        connection_pcast = &Dcm_Cfg_Dsl_pcst->dslConnection_pcast[connectionIdx_u16];
        mainConnCfg_pcast = &Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[connection_pcast->mainConnectionIdx_u8];

        if(mainConnCfg_pcast != NULL_PTR)
        {
            txpduid = mainConnCfg_pcast->txPduId;
        }
    }

    return txpduid;
}

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
uint16 Dcm_Prv_GetObdActiveTesterSrcAddress(void)
{
    uint16 Dcm_ActiveTesterSourceAddress_u16 =0;
    if(FALSE!=Dcm_Prv_IsDcmDslConnectionGeneric(Dcm_Prv_GetObdActiveRxPduId()))
    {
    	Dcm_ActiveTesterSourceAddress_u16= Dcm_OBD_MetaDataTx_TargetAddress_u16;
    }
    else
    {
    	Dcm_ActiveTesterSourceAddress_u16 = *(Dcm_Prv_GetObdActiveConnection()->rxTesterSrcAddr_pcu16);
    }
    return Dcm_ActiveTesterSourceAddress_u16;
}
#endif

uint16 Dcm_Prv_GetActiveTesterSrcAddress(void)
{
    uint16 Dcm_ActiveTesterSourceAddress_u16 =0;
    if(FALSE!=Dcm_Prv_IsDcmDslConnectionGeneric(Dcm_Prv_GetActiveRxPduId()))
    {
    	Dcm_ActiveTesterSourceAddress_u16=  Dcm_MetaDataTx_TargetAddress_u16;
    }
    else
    {
        if(Dcm_ActiveMainConnCfg_pcast->rxTesterSrcAddr_pcu16 != NULL_PTR)
        {
        	Dcm_ActiveTesterSourceAddress_u16= *Dcm_ActiveMainConnCfg_pcast->rxTesterSrcAddr_pcu16;
        }
    }
    return Dcm_ActiveTesterSourceAddress_u16;
}

uint16 Dcm_Prv_GetTesterSrcAddress(uint8 connectionIdx_u8)
{
    const Dcm_DslConnectionConfigType_tst *connection_pcast = NULL_PTR;
    const Dcm_DslMainConnConfigType_tst *mainConnCfg_pcast = NULL_PTR;
    uint16 testerSrcAddress = 0;

    if(connectionIdx_u8 < DCM_CFG_TOTAL_DSL_CONNECTIONS)
    {
        connection_pcast = &Dcm_Cfg_Dsl_pcst->dslConnection_pcast[connectionIdx_u8];
        mainConnCfg_pcast = &Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[connection_pcast->mainConnectionIdx_u8];
        testerSrcAddress = *mainConnCfg_pcast->rxTesterSrcAddr_pcu16;
    }

    return testerSrcAddress;
}

uint16 Dcm_Prv_GetTesterSrcAddressFromRxPduId(PduIdType rxpduId)
{
    const Dcm_DslConnectionConfigType_tst *connection_pcast = NULL_PTR;
    const Dcm_DslMainConnConfigType_tst *mainConnCfg_pcast = NULL_PTR;
    PduIdType connectionIdx_u16;
    uint16 testerSrcAddress = 0;

    if(rxpduId < DCM_CFG_TOTAL_RX_PDUID)
    {
        connectionIdx_u16 = Dcm_Cfg_Dsl_pcst->protocolRx_pc[rxpduId];
        connection_pcast = &Dcm_Cfg_Dsl_pcst->dslConnection_pcast[connectionIdx_u16];
        mainConnCfg_pcast = &Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[connection_pcast->mainConnectionIdx_u8];
        testerSrcAddress = *mainConnCfg_pcast->rxTesterSrcAddr_pcu16;
    }

    return testerSrcAddress;
}

PduIdType Dcm_Prv_GetActiveConnectionIndex(void)
{
    return Dcm_Uds_ActiveConnectionIdx;
}

const Dcm_DslPeriodicConnConfigType_tst* Dcm_Prv_GetActivePeriodicConnection(void)
{
    //User has to check for NULL_PTR(Since lower multiplicity is 0)
    return Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Uds_ActiveConnectionIdx].periodicConn_past;
}

const Dcm_DslRoeConnConfigType_tst* Dcm_Prv_GetActiveRoeConnection(void)
{
    //User has to check for NULL_PTR(Since lower multiplicity is 0)
    return Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Uds_ActiveConnectionIdx].roeConn_past;
}

const Dcm_DslProtocolRowConfigType_tst* Dcm_Prv_GetActiveRdpiProtocolRow(void)
{
    uint8 protocolIdx_u8=0;
    protocolIdx_u8 = Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Uds_ActiveConnectionIdx].periodicConn_past->protocolRowIdx_u8;
    return &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[protocolIdx_u8];
}

const Dcm_DslProtocolRowConfigType_tst* Dcm_Prv_GetActiveRoeProtocolRow(void)
{
    uint8 protocolIdx_u8=0;
    protocolIdx_u8   = Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Uds_ActiveConnectionIdx].roeConn_past->protocolRowIdx_u8;
    return &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[protocolIdx_u8];
}

const uint8* Dcm_Prv_GetMaxNumRespPending(void)
{
    //User has to check for NULL_PTR(Since lower multiplicity is 0)
    return Dcm_Cfg_Dsl_pcst->maxNumRespPend_pu8;
}

boolean Dcm_Prv_GetRespOnSecondDeclinedRequest(PduIdType rxpduId)
{
    return Dcm_Prv_GetProtocolRow(rxpduId)->nrc21_b;
}

void Dcm_Prv_SetProtocolStatus(boolean protocolStatus_b)
{
    IsProtocolStarted_b = protocolStatus_b;
}

boolean Dcm_Prv_IsProtocolStarted(void)
{
    return IsProtocolStarted_b;
}

PduLengthType Dcm_Dsl_Prv_GetActiveRequestDataLen(void)
{
    return Dcm_Uds_ActiveRequestLength;
}

void Dcm_Dsl_Prv_SetActiveRequestDataLen(PduLengthType reqDataLength)
{
    Dcm_Uds_ActiveRequestLength = reqDataLength;
}

uint8_least Dcm_Prv_Get_CurrentProtocolIndex(void)
{
    return Dcm_CurrentProtocol_Idx_u8;
}

void Dcm_Prv_Update_ProtocolIndex(uint8_least idxCurrentProtocol_u8)
{
    Dcm_CurrentProtocol_Idx_u8 = idxCurrentProtocol_u8;
}

const uint8 * Dcm_GetSecurityLookupTable(void)
{
    return Dcm_Cfg_Dsl_pcst->SecurityLookupTable_pcu8;
}

const uint8 * Dcm_GetSessionLookupTable(void)
{
    return Dcm_Cfg_Dsl_pcst->SessionLookupTable_pcau8;
}

const uint8 * Dcm_GetKWPSessionLookupTable(void)
{
#if( DCM_CFG_KWP_ENABLED != DCM_CFG_OFF )
    return Dcm_Cfg_Dsl_pcst->KWPSessionLookupTable_pcau8;
#else
    return NULL_PTR;
#endif
}

boolean Dcm_Prv_IsCommunicationActive(void)
{
    return IsCommunicationActive_b;
}

void Dcm_Prv_SetCommunicationState(boolean flagCommActive_b)
{
    IsCommunicationActive_b = flagCommActive_b;
}

boolean Dcm_Prv_IsP3TimerMonitorRequired(void)
{
    return IsP3TimerMonitorRequired_b;
}

void Dcm_Prv_SetP3TimerMonitorFlag(boolean flgMonitorP3timer_b)
{
    IsP3TimerMonitorRequired_b = flgMonitorP3timer_b;
}

uint32 Dcm_Prv_Get_DataTimeOut(void)
{
    return s_DataTimeOutMonitor_u32;
}

void Dcm_Prv_Set_DataTimeOut(uint32 dataTimeOutMonitor_u32)
{
    s_DataTimeOutMonitor_u32 = dataTimeOutMonitor_u32;
}

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
uint32 Dcm_Prv_Get_DataPagedBufferTimeOut(void)
{
    return s_DataPagedBufferTimeOutMonitor_u32;
}

void Dcm_Prv_Set_DataPagedBufferTimeOut(uint32 dataPagedBufferTimeOutMonitor_u32)
{
    s_DataPagedBufferTimeOutMonitor_u32 = dataPagedBufferTimeOutMonitor_u32;
}
#endif

boolean DCM_IS_KWPPROT_ACTIVE(void)
{
    boolean retval_b = FALSE;
#if( DCM_CFG_KWP_ENABLED != DCM_CFG_OFF )
    Dcm_ProtocolType activeProtocol = Dcm_Prv_GetActiveProtocolType();
    retval_b = ((activeProtocol & 0xF0u) == 0x80u);
#endif
    return retval_b;
}

void Dcm_Prv_ReloadS3Timer (void)
{

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)

    if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
    {
        /* if KWP is running protocol start P3 timer */

        DCM_TimerStart(s_DataTimeOutMonitor_u32, Dcm_DsldTimer_st.dataTimeoutP3max_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
    }
    else
    {
        /* if UDS is running protocol start S3 timer */

        DCM_TimerStart(s_DataTimeOutMonitor_u32, DCM_CFG_S3MAX_TIME,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
    }
#else
    /* if UDS is running protocol start S3 timer */

    DCM_TimerStart(s_DataTimeOutMonitor_u32, DCM_CFG_S3MAX_TIME,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
#endif

    Dcm_Prv_Set_DataTimeOut(s_DataTimeOutMonitor_u32);
}

boolean Dcm_Prv_isForcePendingResponse(void)
{
    return (Dcm_DslTransmit_st.isForceResponsePendRequested_b);
}
/**
 **************************************************************************************************
 * Dcm_IsInfrastructureErrorPresent_b : API to check for infrastructure error
 * \param           dataInfrastrutureCode_u8 : Parameter to be checked for infrastructure Error
 *
 *
 * \retval          TRUE : if infrastructure error is present
 *                  FALSE : if infrastructure error is not present
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

boolean Dcm_IsInfrastructureErrorPresent_b(uint8 dataInfrastrutureCode_u8)
{
    boolean stInfrastructStatus_b;
    if((dataInfrastrutureCode_u8 & 0x80u) != (0x00u))
    {
        /*Infrastructure Error status is set to TRUE*/
        stInfrastructStatus_b= TRUE;
    }
    else
    {
        /*Infrastructure Error status is set to FALSE*/
        stInfrastructStatus_b= FALSE;
    }
    return(stInfrastructStatus_b);
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_IsDcmDslConnectionGeneric
 Syntax           : Dcm_Prv_IsDcmDslConnectionGeneric(PduIdType DcmRxPduId)
 Description      : This INLINE API is used to check whether the request is received on a Generic Connection
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/
boolean Dcm_Prv_IsDcmDslConnectionGeneric(PduIdType DcmRxPduId)
{
    PduIdType Dcm_ActiveConnectionIdx = Dcm_Cfg_Dsl_pcst->protocolRx_pc[DcmRxPduId];
    return Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_ActiveConnectionIdx].dcmDslConnectionIsGeneric_b;
}


/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetSourceAndTargetAddress
 Syntax           : Dcm_Prv_SetSourceAndTargetAddress(PduIdType DcmRxPduId, const PduInfoType* info)
 Description      : This API is used to set the SA and TA for the final response to the received request
 Parameter        : PduIdType
                    PduInfoType*
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_SetSourceAndTargetAddress(PduIdType DcmRxPduId, const PduInfoType* info)
{
    if(FALSE!=Dcm_Prv_IsDcmDslConnectionGeneric(DcmRxPduId))
    {
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
        if(Dcm_Prv_IsRxPduIdOBD(DcmRxPduId))
        {
            Dcm_OBD_MetaDataTx_SourceAddress_u16 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->dcmDspProtocolEcuAddr_u16;
            Dcm_OBD_MetaDataTx_TargetAddress_u16 = ((uint16)(info->MetaDataPtr[0]<<8)|(info->MetaDataPtr[1]));
        }
        else
#endif
        {
            Dcm_MetaDataTx_SourceAddress_u16 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->dcmDspProtocolEcuAddr_u16;
            Dcm_MetaDataTx_TargetAddress_u16 = ((uint16)(info->MetaDataPtr[0]<<8)|(info->MetaDataPtr[1]));
        }
    }
    return;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetSourceAndTargetAddressWarmStart
 Syntax           : Dcm_Prv_SetSourceAndTargetAddressWarmStart(PduIdType DcmRxPduId, const PduInfoType* info)
 Description      : This API is used to set the SA and TA for the final response for warm start (WarmRequest/ WarmResponse)
 Parameter        : PduIdType
                    PduInfoType*
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_SetSourceAndTargetAddressWarmStart(PduIdType DcmDslConnectionIdx, uint16 TesterSourceAddress)
{
    uint8 protocolIdx_u8=0;
    const Dcm_DslProtocolRowConfigType_tst *protocolRowCfg = NULL_PTR;
    protocolIdx_u8   = Dcm_Cfg_Dsl_pcst->dslConnection_pcast[DcmDslConnectionIdx].protocolRowIdx_u8;
    protocolRowCfg = &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[protocolIdx_u8];

    if(FALSE!=Dcm_Cfg_Dsl_pcst->dslConnection_pcast[DcmDslConnectionIdx].dcmDslConnectionIsGeneric_b)
    {
        Dcm_MetaDataTx_SourceAddress_u16 = protocolRowCfg->dcmDspProtocolEcuAddr_u16;
        Dcm_MetaDataTx_TargetAddress_u16 = TesterSourceAddress;
    }
    return;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetSourceAndTargetAddress_NRC21
 Syntax           : Dcm_Prv_SetSourceAndTargetAddress_NRC21(PduIdType DcmRxPduId, const PduInfoType* info)
 Description      : This API is used to set the SA and TA for sending NRC 21 for the received request
 Parameter        : PduIdType
                    PduInfoType*
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_SetSourceAndTargetAddress_NRC21(PduIdType DcmRxPduId, const PduInfoType* info)
{
    if(FALSE!=Dcm_Prv_IsDcmDslConnectionGeneric(DcmRxPduId))
    {
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
        if(Dcm_Prv_IsRxPduIdOBD(DcmRxPduId))
        {
            Dcm_OBD_MetaDataTx_Nrc21_SourceAddress_u16 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->dcmDspProtocolEcuAddr_u16;
            Dcm_OBD_MetaDataTx_Nrc21_TargetAddress_u16 = ((uint16)(info->MetaDataPtr[0]<<8)|(info->MetaDataPtr[1]));
        }
        else
#endif
        {
            Dcm_MetaDataTx_Nrc21_SourceAddress_u16 = Dcm_Prv_GetProtocolRow(DcmRxPduId)->dcmDspProtocolEcuAddr_u16;
            Dcm_MetaDataTx_Nrc21_TargetAddress_u16 = ((uint16)(info->MetaDataPtr[0]<<8)|(info->MetaDataPtr[1]));
        }
    }
    return;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_UpdateMetaData_Nrc21
 Syntax           : Dcm_Prv_UpdateMetaData_Nrc21(PduIdType DcmRxPduId,uint8** MetaDataPtr)
 Description      : This API is used to update the MetaData Pointer for the transmission of NRC21
 Parameter        : PduInfoType*
                    PduIdType
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_UpdateMetaData_Nrc21(PduIdType DcmRxPduId,uint8** MetaDataPtr)
{
    if(FALSE!=Dcm_Prv_IsDcmDslConnectionGeneric(DcmRxPduId))
    {
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
		if(Dcm_Prv_IsRxPduIdOBD(DcmRxPduId))
		{
	        /*SA and TA updated in Big Endian Format for OBD Protocol*/
		    Dcm_tempOBDMetaData_NRC21_u8[0] = (uint8) (Dcm_OBD_MetaDataTx_Nrc21_SourceAddress_u16>>8u);
		    Dcm_tempOBDMetaData_NRC21_u8[1] = (uint8) Dcm_OBD_MetaDataTx_Nrc21_SourceAddress_u16;
		    Dcm_tempOBDMetaData_NRC21_u8[2] =  (uint8)(Dcm_OBD_MetaDataTx_Nrc21_TargetAddress_u16>>8u);
		    Dcm_tempOBDMetaData_NRC21_u8[3] = (uint8) Dcm_OBD_MetaDataTx_Nrc21_TargetAddress_u16;
		    *MetaDataPtr = &Dcm_tempOBDMetaData_NRC21_u8[0];
		}
		else
#endif
		{
		    /*SA and TA updated in Big Endian Format*/
		    Dcm_tempMetaData_NRC21_u8[0] = (uint8)(Dcm_MetaDataTx_Nrc21_SourceAddress_u16>>8u);
		    Dcm_tempMetaData_NRC21_u8[1] = (uint8) Dcm_MetaDataTx_Nrc21_SourceAddress_u16;
		    Dcm_tempMetaData_NRC21_u8[2] = (uint8)(Dcm_MetaDataTx_Nrc21_TargetAddress_u16 >>8u);
		    Dcm_tempMetaData_NRC21_u8[3] = (uint8) Dcm_MetaDataTx_Nrc21_TargetAddress_u16;
		    *MetaDataPtr = &Dcm_tempMetaData_NRC21_u8[0];
		}
    }
    return;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_UpdateMetaDataPointer
 Syntax           : Dcm_Prv_UpdateMetaDataPointer(uint8* MetaDataPtr)
 Description      : This API is used to update the MetaData Pointer for the transmission of final response
 Parameter        : PduInfoType*
 Return value     : void
 ***********************************************************************************************************************/
void Dcm_Prv_UpdateMetaDataPointer(PduIdType DcmRxPduId,uint8** MetaDataPtr)
{
    if(FALSE!=Dcm_Prv_IsDcmDslConnectionGeneric(DcmRxPduId))
    {
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
        if(Dcm_Prv_IsRxPduIdOBD(DcmRxPduId))
        {
            /*SA and TA updated in Big Endian Format for OBD Protocol*/
            Dcm_tempOBDMetaData_u8[0] = (uint8)(Dcm_OBD_MetaDataTx_SourceAddress_u16>>8u);
            Dcm_tempOBDMetaData_u8[1] = (uint8) Dcm_OBD_MetaDataTx_SourceAddress_u16;
            Dcm_tempOBDMetaData_u8[2] = (uint8)(Dcm_OBD_MetaDataTx_TargetAddress_u16>>8u);
            Dcm_tempOBDMetaData_u8[3] = (uint8) Dcm_OBD_MetaDataTx_TargetAddress_u16;
            *MetaDataPtr = &Dcm_tempOBDMetaData_u8[0];
        }
        else
#endif
        {
            /*SA and TA updated in Big Endian Format*/
            Dcm_tempMetaData_u8[0] = (uint8) (Dcm_MetaDataTx_SourceAddress_u16>>8u);
            Dcm_tempMetaData_u8[1] = (uint8)  Dcm_MetaDataTx_SourceAddress_u16;
            Dcm_tempMetaData_u8[2] = (uint8) (Dcm_MetaDataTx_TargetAddress_u16>>8u);
            Dcm_tempMetaData_u8[3] = (uint8)  Dcm_MetaDataTx_TargetAddress_u16;
            *MetaDataPtr = &Dcm_tempMetaData_u8[0];
        }
    }
    return;
}

