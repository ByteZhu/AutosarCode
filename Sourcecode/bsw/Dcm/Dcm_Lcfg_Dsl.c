
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "PduR_Dcm.h"

#include "Dem_Dcm.h"

#include "ComM_Dcm.h"
#include "Dcm_Prv.h"


#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
/* DSL protocol Buffers*/


/* Generation of Diagnosis Rx buffer */
static uint8 Dcm_RequestBuffer_au8[512+2];
static uint8 Dcm_RequestBufferQueue_au8[512+2];
/* Generation of Diagnosis Tx buffer */
static uint8 Dcm_ResponseBuffer_au8[512+2];

#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

/* Maximum Response pending buffer*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static const uint8 Dcm_Dsl_MaxNumRespPend_cu8 = DCM_CFG_MAX_WAITPEND;
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"




#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static const Dcm_DslProtocolRowConfigType_tst Dcm_Cfg_DslProtocolRow_acst[] =
{
   {
       DCM_UDS_ON_CAN,                                   /* ProtocolType*/   
         
       DemConf_DemClient_DemClient,   /* Referred Dem Client Id for the Protocol */
       DCM_INVALID_TRANSTYPE_E,                          /* TransType*/
       1,                                                /* ProtocolPriority*/
              &Dcm_RequestBuffer_au8[0],     /* Rx buffer address */
              &Dcm_ResponseBuffer_au8[0],     /* Tx buffer address */
              &Dcm_RequestBufferQueue_au8[0],     /* Rx Queue buffer address */
       512u,                                             /* ProtocolRxBufferSize*/
       512u,                                             /* ProtocolTxBufferSize*/
       0u,                                               /* SidTableId*/      
            FALSE,            /* Silently ignore new request on this protocol if received and rejected during pre-emption assertion */
       FALSE,                                            /* SendRespPendOnTransToBoot*/
       10000u,                                           /* P2ServerTimeAdjust*/
       10000u,                                           /* P2StarServerTimeAdjust*/
       20u,                                              /* ProtocolMaximumResponseSize*/ 
       0x00u,                                            /* Protocol ECU Target Address */
   }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"



#define DCM_START_SEC_CONST_16
#include "Dcm_MemMap.h"
/* Collection of RxRxTesterSourceAddr available from main connection */
static const uint16 Dcm_Cfg_DslRxTesterSourceAddr_acu16[] =
{
   0x0, 
};
#define DCM_STOP_SEC_CONST_16
#include "Dcm_MemMap.h"


#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static const Dcm_DslMainConnConfigType_tst Dcm_Cfg_DslMainConn_acst[] = 
{
 /* ProtocolRow DcmDslProtocolRow_UDS MainConnection 0*/
   {
       0,                                                /* comMChannelId */ 
       0,                                                /* RxConnectionId */                    
       &Dcm_Cfg_DslRxTesterSourceAddr_acu16[0],          /* RxTesterSourceAddr*/
       PduRConf_PduRSrcPdu_Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN, /* TxPduId */ 
       0x0,                                              /* Index of corresponding channelid */
   },
};


/* Roe connections for all Roe protocol Rows*/
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/* Periodic connections Type2 */
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* Periodic connections of all periodic Protocol Rows */
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*  Dcm_DslConnection without ROE and Periodic Protocols*/
static const Dcm_DslConnectionConfigType_tst Dcm_Cfg_DslConnection_acst[] =
{
   {
       DCM_CFG_DCMDSLPROTOCOLROW_UDS,                                        /* ProtcolRow Index */ 
       DCM_CFG_DCMDSLPROTOCOLROW_UDS_MAINCONNECTION_0,                       /* mainConnection Index */ 
       NULL_PTR,                                                             /* PeriodicConnection Reference */
       NULL_PTR,                                                             /* ROE Connection Reference */ 
       FALSE,                                                                /* Is not a Generic Connection */
   },
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*  List of RxPduIds for DCM*/
static const PduIdType Dcm_Cfg_DslProtocolRx_acu16[DCM_CFG_PROTOCOLRXTABLE_LENGTH]={
/* UDS OBD Functional PDU not shared */
DCM_CFG_DSL_CONNECTION_INDEX0,/*Rxpduid0 physicalPdu, DcmDslProtocolRow_UDS */
DCM_CFG_DSL_CONNECTION_INDEX0,/*Rxpduid1 functionalPdu, DcmDslProtocolRow_UDS */
DCM_CFG_INVALID_CONNECTION_INDEX
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_16
#include "Dcm_MemMap.h"
#define DCM_STOP_SEC_CONST_16
#include "Dcm_MemMap.h"



#define DCM_START_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* This is the array contains the supported sessions in this ECU                             */
/* sessions id are configured here (eg: default session=0x01, programming session=0x02)      */
/* number of sessions in DSC service is same as here                                         */
/* this lookup table is used to calculate the bit mask from session ID                       */
/* these ids are always in ascending order                                                    */

/* The DscmDsp session and security configuration is used for the UDS protocol */
static const uint8 Dcm_DsldSupportedSessions_cau8[]= {0x1,0x2,0x3};

#if (DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
const uint8 Dcm_Dsld_KWPsupported_sessions_acu8[]= {0x86};
#endif

#define DCM_STOP_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/* this is the array contains the supported security level in this ECU                       */
/* security levels are configured here (eg: DCM_SEC_LEV_LOCKED =0x00)                        */
/* number of security levels here is one more than in SECA service                           */
/* this lookup table is used to calculate the bit mask from security level                   */
/* this ids are always in ascending order                                                    */
/* Allowed range of security levels are 0x00,0x01,0x02,.....0x3F                             */
#define DCM_START_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
static const uint8 Dcm_Dsld_supported_security_acu8[]= {    0x0,    0x3};
#define DCM_STOP_SEC_CONST_8  /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static const Dcm_DslConfigType_tst Dcm_Cfg_Dsl_cst = 
{
    &Dcm_Cfg_DslProtocolRx_acu16[0],                  /* ProtocolRxPdus References*/ 
    &Dcm_Cfg_DslConnection_acst[0],                   /* DslConnection References*/ 
    &Dcm_Cfg_DslProtocolRow_acst[0],                  /* ProtocolRows References*/ 
    &Dcm_Cfg_DslMainConn_acst[0],                     /* MainConnection References*/ 
    &Dcm_DsldSupportedSessions_cau8[0],               /* Session References*/  
    #if (DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)   
    &Dcm_Dsld_KWPsupported_sessions_acu8[0],          /* KWP Session References*/ 
    #endif
    &Dcm_Dsld_supported_security_acu8[0],             /* Security References*/    
  
    &Dcm_Dsl_MaxNumRespPend_cu8,                      /* Diagnostic Maximum Respond Pending */ 
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
const Dcm_DslConfigType_tst *Dcm_Cfg_Dsl_pcst = &Dcm_Cfg_Dsl_cst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"



#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
const Dcm_Dsld_RoeRxToTestSrcMappingType Dcm_Dsld_RoeRxToTestSrcMappingTable[DCM_CFG_TOTAL_RX_PDUID]=
{
{
    0, 
    0
}
,
{
    1, 
    0
}
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* Array for storing ComM channels configured in DCM  and their states*/
Dcm_Dsld_ComMChannel Dcm_active_commode_e[DCM_NUM_COMM_CHANNEL]=
{

{ComMConf_ComMChannel_Can_Network_0_Channel_Can_Network_0,DCM_DSLD_NO_COM_MODE}

};
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* Const Array for storing ComM channels configured in DCM.The same will be used for initialising  Dcm_active_commode_e[]*/
const uint8 Dcm_Dsld_ComMChannelId_acu8[DCM_NUM_COMM_CHANNEL]={
ComMConf_ComMChannel_Can_Network_0_Channel_Can_Network_0,
};
#define DCM_STOP_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"



#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
const PduIdType Dcm_TxTable_cast[DCM_CFG_PDUIDTABLE_TX_LENGTH] =
{
    PduRConf_PduRSrcPdu_Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN,

    DCM_CFG_INVALID_TX_PDUID
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

