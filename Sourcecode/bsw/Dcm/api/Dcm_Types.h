

#ifndef DCM_TYPES_H
#define DCM_TYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#ifndef DCM_RES_POS_OK
#define DCM_RES_POS_OK                      0u
#endif

#ifndef DCM_RES_POS_NOT_OK
#define DCM_RES_POS_NOT_OK                  1u
#endif

#ifndef DCM_RES_NEG_OK
#define DCM_RES_NEG_OK                      2u
#endif

#ifndef DCM_RES_NEG_NOT_OK
#define DCM_RES_NEG_NOT_OK                  3u
#endif

#ifndef DCM_E_COMPARE_KEY_FAILED
#define DCM_E_COMPARE_KEY_FAILED    11u
#endif


#ifndef DCM_E_SESSION_NOT_ALLOWED
#define DCM_E_SESSION_NOT_ALLOWED   4u
#endif


#ifndef DCM_E_PROTOCOL_NOT_ALLOWED
#define DCM_E_PROTOCOL_NOT_ALLOWED  5u
#endif


#ifndef DCM_E_REQUEST_NOT_ACCEPTED
#define DCM_E_REQUEST_NOT_ACCEPTED  8u
#endif


#ifndef DCM_E_REQUEST_ENV_NOK
#define DCM_E_REQUEST_ENV_NOK       9u
#endif

#ifndef DCM_E_PENDING
#define DCM_E_PENDING               10u
#endif


#ifndef DCM_E_FORCE_RCRRP
#define DCM_E_FORCE_RCRRP           12u
#endif


#ifndef DCM_E_RDBI_DATA_PENDING
#define DCM_E_RDBI_DATA_PENDING  14u
#endif


#define DCM_PRV_AR_4_0_2                    0u              /* RTE Version AR 4.0.2 */
#define DCM_PRV_AR_4_0_2_HYBRID             1u              /* RTE Version AR 4.0.2 with some extensions from AR 4.0.3 */
#define DCM_PRV_AR_3_2_1                    2u              /* RTE version AR 3.2.1 */
#define DCM_PRV_AR_3_1_4                    3u              /* RTE version AR 3.1.4 */


#ifndef DCM_POSITIVE_RESPONSE
#define DCM_POSITIVE_RESPONSE 0x00u
#endif /* !DCM_POSITIVE_RESPONSE */

#ifndef DCM_E_GENERALREJECT
#define DCM_E_GENERALREJECT 0x10u
#endif

#ifndef DCM_E_SERVICENOTSUPPORTED
#define DCM_E_SERVICENOTSUPPORTED 0x11u
#endif

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#define DCM_E_SUBFUNCTIONNOTSUPPORTED 0x12u
#endif

#ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT 0x13u
#endif

#ifndef DCM_E_RESPONSETOOLONG
#define DCM_E_RESPONSETOOLONG 0x14u
#endif

#ifndef DCM_E_BUSYREPEATREQUEST
#define DCM_E_BUSYREPEATREQUEST 0x21u
#endif

#ifndef DCM_E_CONDITIONSNOTCORRECT
#define DCM_E_CONDITIONSNOTCORRECT 0x22u
#endif

#ifndef DCM_E_REQUESTSEQUENCEERROR
#define DCM_E_REQUESTSEQUENCEERROR 0x24u
#endif

#ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT 0x25u
#endif

#ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION 0x26u
#endif

#ifndef DCM_E_REQUESTOUTOFRANGE
#define DCM_E_REQUESTOUTOFRANGE 0x31u
#endif

#ifndef DCM_E_SECURITYACCESSDENIED
#define DCM_E_SECURITYACCESSDENIED 0x33u
#endif

#ifndef DCM_E_AUTHENTICATIONREQUIRED
#define DCM_E_AUTHENTICATIONREQUIRED 0x34u
#endif

#ifndef DCM_E_INVALIDKEY
#define DCM_E_INVALIDKEY 0x35u
#endif

#ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#define DCM_E_EXCEEDNUMBEROFATTEMPTS 0x36u
#endif

#ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED 0x37u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTIMEPERIOD
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTIMEPERIOD 0x50u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSIGNATURE
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSIGNATURE 0x51u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCHAINOFTRUST
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCHAINOFTRUST 0x52u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTYPE
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTYPE 0x53u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDFORMAT
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDFORMAT 0x54u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCONTENT
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCONTENT 0x55u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSCOPE
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSCOPE 0x56u
#endif

#ifndef DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCERTIFICATE
#define DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCERTIFICATE 0x57u
#endif

#ifndef DCM_E_OWNERSHIPVERIFICATIONFAILED
#define DCM_E_OWNERSHIPVERIFICATIONFAILED 0x58u
#endif

#ifndef DCM_E_CHALLENGECALCULATIONFAILED
#define DCM_E_CHALLENGECALCULATIONFAILED 0x59u
#endif

#ifndef DCM_E_SETTINGACCESSRIGHTSFAILED
#define DCM_E_SETTINGACCESSRIGHTSFAILED 0x5Au
#endif

#ifndef DCM_E_SESSIONKEYCREATIONDERIVATIONFAILED
#define DCM_E_SESSIONKEYCREATIONDERIVATIONFAILED 0x5Bu
#endif

#ifndef DCM_E_CONFIGURATIONDATAUSAGEFAILED
#define DCM_E_CONFIGURATIONDATAUSAGEFAILED 0x5Cu
#endif

#ifndef DCM_E_DEAUTHENTICATIONFAILED
#define DCM_E_DEAUTHENTICATIONFAILED 0x5Du
#endif

#ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED 0x70u
#endif

#ifndef DCM_E_TRANSFERDATASUSPENDED
#define DCM_E_TRANSFERDATASUSPENDED 0x71u
#endif

#ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#define DCM_E_GENERALPROGRAMMINGFAILURE 0x72u
#endif

#ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER 0x73u
#endif

#ifndef DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING
#define DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING 0x78u
#endif /* !DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING */

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION 0x7Eu
#endif

#ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION 0x7Fu
#endif


#ifndef DCM_E_RPMTOOHIGH
#define DCM_E_RPMTOOHIGH 0x81u
#endif

#ifndef DCM_E_RPMTOOLOW
#define DCM_E_RPMTOOLOW 0x82u
#endif


#ifndef DCM_E_ENGINEISRUNNING
#define DCM_E_ENGINEISRUNNING 0x83u
#endif


#ifndef DCM_E_ENGINEISNOTRUNNING
#define DCM_E_ENGINEISNOTRUNNING  0x84u
#endif


#ifndef DCM_E_ENGINERUNTIMETOOLOW
#define DCM_E_ENGINERUNTIMETOOLOW 0x85u
#endif

#ifndef DCM_E_TEMPERATURETOOHIGH
#define DCM_E_TEMPERATURETOOHIGH 0x86u
#endif

#ifndef DCM_E_TEMPERATURETOOLOW
#define DCM_E_TEMPERATURETOOLOW 0x87u
#endif

#ifndef DCM_E_VEHICLESPEEDTOOHIGH
#define DCM_E_VEHICLESPEEDTOOHIGH 0x88u
#endif

#ifndef DCM_E_VEHICLESPEEDTOOLOW
#define DCM_E_VEHICLESPEEDTOOLOW 0x89u
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#define DCM_E_THROTTLE_PEDALTOOHIGH 0x8Au
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOLOW
#define DCM_E_THROTTLE_PEDALTOOLOW 0x8Bu
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL 0x8Cu
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#define DCM_E_TRANSMISSIONRANGENOTINGEAR 0x8Du
#endif

#ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#define DCM_E_BRAKESWITCH_NOTCLOSED 0x8Fu
#endif

#ifndef DCM_E_SHIFTERLEVERNOTINPARK
#define DCM_E_SHIFTERLEVERNOTINPARK 0x90u
#endif

#ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED 0x91u
#endif

#ifndef DCM_E_VOLTAGETOOHIGH
#define DCM_E_VOLTAGETOOHIGH 0x92u
#endif

#ifndef DCM_E_VOLTAGETOOLOW
#define DCM_E_VOLTAGETOOLOW 0x93u
#endif

/* Box: "DCM_E_RESOURCETEMPORARILYNOTAVAILABLE" begin */
#ifndef DCM_E_RESOURCETEMPORARILYNOTAVAILABLE
#define DCM_E_RESOURCETEMPORARILYNOTAVAILABLE 0x94u
#endif /* !DCM_E_RESOURCETEMPORARILYNOTAVAILABLE */
/* Box: "DCM_E_RESOURCETEMPORARILYNOTAVAILABLE" end */
/* Box: "DCM_E_VMSCNC_0" begin */
#ifndef DCM_E_VMSCNC_0
#define DCM_E_VMSCNC_0 0xF0
#endif /* !DCM_E_VMSCNC_0 */
/* Box: "DCM_E_VMSCNC_0" end */
/* Box: "DCM_E_VMSCNC_1" begin */
#ifndef DCM_E_VMSCNC_1
#define DCM_E_VMSCNC_1 0xF1
#endif /* !DCM_E_VMSCNC_1 */
/* Box: "DCM_E_VMSCNC_1" end */
/* Box: "DCM_E_VMSCNC_2" begin */
#ifndef DCM_E_VMSCNC_2
#define DCM_E_VMSCNC_2 0xF2
#endif /* !DCM_E_VMSCNC_2 */
/* Box: "DCM_E_VMSCNC_2" end */
/* Box: "DCM_E_VMSCNC_3" begin */
#ifndef DCM_E_VMSCNC_3
#define DCM_E_VMSCNC_3 0xF3
#endif /* !DCM_E_VMSCNC_3 */
/* Box: "DCM_E_VMSCNC_3" end */
/* Box: "DCM_E_VMSCNC_4" begin */
#ifndef DCM_E_VMSCNC_4
#define DCM_E_VMSCNC_4 0xF4
#endif /* !DCM_E_VMSCNC_4 */
/* Box: "DCM_E_VMSCNC_4" end */
/* Box: "DCM_E_VMSCNC_5" begin */
#ifndef DCM_E_VMSCNC_5
#define DCM_E_VMSCNC_5 0xF5
#endif /* !DCM_E_VMSCNC_5 */
/* Box: "DCM_E_VMSCNC_5" end */
/* Box: "DCM_E_VMSCNC_6" begin */
#ifndef DCM_E_VMSCNC_6
#define DCM_E_VMSCNC_6 0xF6
#endif /* !DCM_E_VMSCNC_6 */
/* Box: "DCM_E_VMSCNC_6" end */
/* Box: "DCM_E_VMSCNC_7" begin */
#ifndef DCM_E_VMSCNC_7
#define DCM_E_VMSCNC_7 0xF7
#endif /* !DCM_E_VMSCNC_7 */
/* Box: "DCM_E_VMSCNC_7" end */
/* Box: "DCM_E_VMSCNC_8" begin */
#ifndef DCM_E_VMSCNC_8
#define DCM_E_VMSCNC_8 0xF8
#endif /* !DCM_E_VMSCNC_8 */
/* Box: "DCM_E_VMSCNC_8" end */
/* Box: "DCM_E_VMSCNC_9" begin */
#ifndef DCM_E_VMSCNC_9
#define DCM_E_VMSCNC_9 0xF9
#endif /* !DCM_E_VMSCNC_9 */
/* Box: "DCM_E_VMSCNC_9" end */
/* Box: "DCM_E_VMSCNC_A" begin */
#ifndef DCM_E_VMSCNC_A
#define DCM_E_VMSCNC_A 0xFA
#endif /* !DCM_E_VMSCNC_A */
/* Box: "DCM_E_VMSCNC_A" end */
/* Box: "DCM_E_VMSCNC_B" begin */
#ifndef DCM_E_VMSCNC_B
#define DCM_E_VMSCNC_B 0xFB
#endif /* !DCM_E_VMSCNC_B */
/* Box: "DCM_E_VMSCNC_B" end */
/* Box: "DCM_E_VMSCNC_C" begin */
#ifndef DCM_E_VMSCNC_C
#define DCM_E_VMSCNC_C 0xFC
#endif /* !DCM_E_VMSCNC_C */
/* Box: "DCM_E_VMSCNC_C" end */
/* Box: "DCM_E_VMSCNC_D" begin */
#ifndef DCM_E_VMSCNC_D
#define DCM_E_VMSCNC_D 0xFD
#endif /* !DCM_E_VMSCNC_D */
/* Box: "DCM_E_VMSCNC_D" end */
/* Box: "DCM_E_VMSCNC_E" begin */
#ifndef DCM_E_VMSCNC_E
#define DCM_E_VMSCNC_E 0xFE
#endif /* !DCM_E_VMSCNC_E */
/* Box: "DCM_E_VMSCNC_E" end */

#ifndef DCM_INITIAL
#define DCM_INITIAL 0x00u    /* Indicates the initial call to the operation */
#endif

#ifndef DCM_PENDING
#define DCM_PENDING 0x01u    /* Indicates that a pending return has been done on the previous call of the operation */
#endif

#ifndef DCM_CANCEL
#define DCM_CANCEL  0x02u    /* Indicates that the DCM requests to cancel the pending operation */
#endif

#ifndef DCM_FORCE_RCRRP_OK
#define DCM_FORCE_RCRRP_OK  0x03u   /* Confirm a response pending transmission */
#endif

#ifndef DCM_CHECKDATA
#define DCM_CHECKDATA 0x04u
#endif


#ifndef DCM_PROCESSSERVICE
#define DCM_PROCESSSERVICE  0x05u
#endif

#define  DCM_DSP_SID_INVALID                            0xFFu


/*
 **********************************************************************************************************************
 * Typedefs
 **********************************************************************************************************************
 */
typedef uint32 Dcm_MsgLenType;
typedef uint8 Dcm_MsgItemType;
typedef Dcm_MsgItemType * Dcm_MsgType;
typedef uint8 Dcm_IdContextType;
typedef uint8 Dcm_ExtendedOpStatusType;

typedef struct
{
    uint8 reqType;
    boolean suppressPosResponse;
    uint8     sourceofRequest;
}Dcm_MsgAddInfoType;

typedef struct
{
    Dcm_MsgType         resData;
    Dcm_MsgType         reqData;
    Dcm_MsgAddInfoType  msgAddInfo;
    Dcm_MsgLenType      resDataLen;
    Dcm_MsgLenType      reqDataLen;
    Dcm_MsgLenType      resMaxDataLen;
    Dcm_IdContextType   idContext;
    PduIdType           dcmRxPduId;
}Dcm_MsgContextType;


/*begin types from DcmDspUds_Uds_Pub.h */
typedef enum
{
    DCM_DDDI_CLEAR = 0,
    DCM_DDDI_CLEARALL,
    DCM_DDDI_WRITE
}Dcm_DddiWriteOrClear_ten;


typedef enum
{
    DCM_DDDI_READ_OK = 0, /* in case the read is successful */
    DCM_DDDI_READ_NOT_OK, /* in case there is no access or error while reading */
    DCM_DDDI_READ_NOTAVAILABLE /* in case the configured DDDID is not available in NVRAM */
}Dcm_RestoreDddiReturn_ten;


typedef struct
{
  uint16 dataSrcDid_u16;
  uint16 idxOfDid_u16; /* index in the Dcm_DIDConfig (calculated at definition time on base of the DID in the request) */
  uint8  posnInSourceDataRecord_u8;
  uint8  dataMemorySize_u8;
  boolean stCurrentDidRangeStatus_b;
} Dcm_DddiDefId_tst;

typedef struct
{
  uint32 adrDddiMem_u32;
  uint32 dataMemLength_u32;
} Dcm_DDDI_DEF_MEM_t;


typedef union              /* Struct used instead of Union, to remove MISRA warning 750*/
{
  Dcm_DDDI_DEF_MEM_t dataMemAccess_st;
  Dcm_DddiDefId_tst  dataIdAccess_st;
} Dcm_DddiDef_tst;

typedef struct
{
  Dcm_DddiDef_tst dataDddi_st;
  uint8 dataDefinitionType_u8;
} Dcm_DddiRecord_tst;


typedef struct
{
  /* current state of configuration for the ID */
  uint16 nrCurrentlyDefinedRecords_u16;
  /* currently ID is being processed */
  /* current processing status */
  uint16 posnCurrentPosInDataBuffer_u16;
  uint16 idxCurrentRecord_u16;
} Dcm_DddiIdContext_tst;


typedef struct
{
  Dcm_DddiRecord_tst * addrRecord_pst;
  Dcm_DddiIdContext_tst * dataDDDIRecordContext_pst;
  Dcm_DddiIdContext_tst * dataPDIRecordContext_pst;
  uint16 dataDddId_u16;
  uint16 nrMaxNumOfRecords_u16;
} Dcm_DddiMainConfig_tst;


typedef enum
{
    DCM_SUPPORT_READ,
    DCM_SUPPORT_WRITE,
    DCM_SUPPORT_IOCONTROL
} Dcm_Direction_t;


typedef enum
{
    DCM_SUPPORT_OK,
    DCM_SUPPORT_SESSION_VIOLATED,
    DCM_SUPPORT_SECURITY_VIOLATED,
    DCM_SUPPORT_CONDITION_VIOLATED,
    DCM_SUPPORT_CONDITION_PENDING
} Dcm_SupportRet_t;


typedef struct
{
    uint32 dataSignalLengthInfo_u32;
    uint16  nrNumofSignalsRead_u16;
    uint16  idxIndex_u16;
#if ( DCM_CFG_DIDRANGE_EXTENSION != DCM_CFG_OFF)
    uint16 dataRangeDid_16;
#endif
    Dcm_NegativeResponseCodeType dataNegRespCode_u8;
    boolean dataRange_b;
    boolean flgNvmReadPending_b;
    Dcm_OpStatusType dataopstatus_b;
#if(DCM_CFG_RDBIPAGEDBUFFERSUPPORT != DCM_CFG_OFF)
    boolean flagPageddid_b;     /*If this flag is set to true it indicates the DID is a paged DID or special DID, if false it indicates a normal did without paged functions*/
#endif
} Dcm_DIDIndexType_tst;


typedef enum
{
    DCM_READ_OK,
    DCM_READ_FAILED,
    DCM_READ_PENDING,
    DCM_READ_FORCE_RCRRP,
    DCM_READ_NOT_AVAILABLE
} Dcm_ReadMemoryRet_t;


typedef Dcm_ReadMemoryRet_t Dcm_ReturnReadMemoryType;


typedef enum
{
    DCM_WRITE_OK,
    DCM_WRITE_FAILED,
    DCM_WRITE_PENDING,
    DCM_WRITE_FORCE_RCRRP,
    DCM_WRITE_NOT_AVAILABLE
} Dcm_WriteMemoryRet_t;


typedef Dcm_WriteMemoryRet_t Dcm_ReturnWriteMemoryType;


typedef enum
{
    DCM_UPLOAD = 0,
    DCM_DOWNLOAD,
    DCM_TRANSFER_NOT_AVAILABLE
} Dcm_TrasferDirection_en;


/*end types from DcmCore_DslDsd_Pub.h*/


/*begin types from DcmDspUds_Uds_Pub.h*/
typedef uint8 Dcm_SrvOpStatusType;

typedef uint8 Dcm_EcuStartModeType;

typedef uint8 Dcm_CommunicationModeType;

typedef struct
{
    uint8  SecurityLevel;       /* Security Level */
    uint16 DelayCount;          /* Number of failed attempt count per security level */
    uint32 ResidualDelay;       /* The remaining delay per security level */
}Dcm_Dsp_Seca_t;


typedef struct
{
    uint8  ProtocolId;          /* Active Protocol ID */
    uint8  Sid;                  /* Active Service Identifier */
    uint8  SubFncId;             /* Active Subfunction Id */
    uint8  StoreType;            /* Storing Type used for Storing the information */
    uint8  SessionLevel;         /* Active Session */
    uint8  SecurityLevel;        /* Active Security */
    uint8  ReqResLen;            /* Request / Response Length */
    uint8  NumWaitPend;          /* Number of waitpends triggered */
    uint8  ReqResBuf[8];         /* Request / Response buffer */
    uint16 TesterSourceAddr;     /* Teseter address of the active Rx PduId */
    uint32 ElapsedTime;          /* Total elapsed time */
    boolean ReprogramingRequest; /* Reprograming of ecu requested or not*/
    boolean ApplUpdated;         /* Application has to be updated or not*/
    boolean ResponseRequired;    /* Response has to be sent by flashloader or application*/
#if(DCM_CFG_SECURITY_STOREDELAYCOUNTANDTIMERONJUMP != DCM_CFG_OFF)
    uint8 NumOfSecurityLevels;   /* Number of security levels configured */
    Dcm_Dsp_Seca_t SecurityInformation[DCM_CFG_NUM_SECURITY_LEVEL - 1u];  /* array of structure for storing the delay and the failed attempt count info per security level */
#endif
    uint8 freeForProjectUse[6];  /*6 bytes of free space is provided for projects to store additional information like CAN ID, BAUD Rate, etc..*/
}Dcm_ProgConditionsType;


typedef uint8 Dcm_StatusType;

typedef struct
{
    Dcm_MsgType txbuffer_ptr;                        /* Tx buffer */
    Dcm_MsgLenType txbuffer_length_u32;              /* Tx buffer length */
    uint8 premption_level_u8;                        /*Preemption Level*/
    uint8 servicetable_Id_u8;                        /* service table */
    uint8   protocolTransType_u8;
}Dcm_ProtocolExtendedInfo_type;


typedef struct
{
    PduIdType txpduid_num_u8;                        /* TxPduId number */
    Dcm_MsgType txbuffer_ptr;                        /* Tx buffer */
    boolean   isTxPduId_Busy;                              /* Roe type  */
    uint8 cntFreeTxPduRdpi2Cntr_u8;                 /**Counter to relieve the TxPduID once the configured timeout is reached*/
}Dcm_RdpiTxInfo_type;


/* protocol structure */
typedef struct
{
    Dcm_MsgType  tx_buffer_pa;                       /* Tx buffer address */
    Dcm_MsgType  rx_mainBuffer_pa;                   /* Main Rx buffer address */
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    Dcm_MsgType  rx_reserveBuffer_pa;                /* Reserve Rx buffer address */
#endif
#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
    const Dcm_ProtocolExtendedInfo_type * roe_info_pcs;        /* Ptr to ROE info structure */
#endif
#if(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF)
    const Dcm_ProtocolExtendedInfo_type * rdpi_info_pcs;       /* Ptr to RDPI info structure */
#endif
    Dcm_MsgLenType tx_buffer_size_u32;               /* Tx buffer size */
    Dcm_MsgLenType rx_buffer_size_u32;               /* Rx buffer size */
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    Dcm_MsgLenType maxResponseLength_u32;
#endif
    uint32 dataP2TmrAdjust;                          /* P2 server time adjust*/
    uint32 dataP2StarTmrAdjust;                      /* P2star server time adjust*/
    uint8  protocolid_u8;                            /* Protocol id */
    uint8  sid_tableid_u8;                           /* Id of distributor table */
    uint8  premption_level_u8;                       /* Preemption level */
    uint8  pduinfo_idx_u8;                           /* Index to the RAM Pduinfo structure */
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    uint8  timings_limit_idx_u8;                     /* Index to KWP default timing structure unused variable for UDS */
    uint8  timings_idx_u8;                           /* Index to KWP default timing structure unused variable for UDS */
#endif
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF )
    uint8 Config_Mask;                               /* Configuration mask to indicate the availability of protocol in different configsets*/
#endif
    uint8   demclientid;                             /* Reference to Dem Client ID */
    boolean nrc21_b;                                 /* React with NRC-21 if this protocol is received and rejected during pre-emption assertion */
    boolean sendRespPendTransToBoot;                 /* Resp Pend on Transit to Boot enabled or disabled for this protocol */
}Dcm_Dsld_protocol_tableType;


typedef boolean (*Dcm_ModeRuleType) (uint8* ErrorCode_u8);


typedef struct
{
    uint32 allowed_session_b32;                      /* Allowed sessions */
    uint32 allowed_security_b32;                     /* Allowed security levels */
    uint32 allowed_authenticationRoles_u32;          /* Allowed authentication roles */
#if((DCM_CFG_DSD_MODERULESUBFNC_ENABLED!=DCM_CFG_OFF))
    Dcm_ModeRuleType moderule_fp;                     /* Reference To configured Mode Rule */
#endif
    Std_ReturnType (*adrUserSubServiceModeRule_pfct) (Dcm_NegativeResponseCodeType * ErrorCode ,uint8 dataSid_u8 ,uint8 subservice_id_u8);
    Std_ReturnType (*SubFunc_fp) (Dcm_SrvOpStatusType OpStatus ,Dcm_MsgContextType * pMsgContext ,Dcm_NegativeResponseCodeType * dataNegRespCode );/* Function pointer for the subfunction*/
    uint8  subservice_id_u8;                         /* Subservice identifier */
    boolean isDspRDTCSubFnc_b;                  /* Is Dsp RDTC function or not*/
}Dcm_Dsld_SubServiceType;

typedef void (*Dcm_ConfirmationApiType)(Dcm_IdContextType dataIdContext_u8,PduIdType dataRxPduId,
        uint16 dataSourceAddress_u16,Dcm_ConfirmationStatusType status);

typedef struct
{
    uint32 allowed_session_b32;                      /* Allowed sessions */
    uint32 allowed_security_b32;                     /* Allowed security levels */
    uint32 allowed_authenticationRoles_u32;                     /* Allowed security levels */
#if((DCM_CFG_DSD_MODERULESERVICE_ENABLED!=DCM_CFG_OFF))
    Dcm_ModeRuleType moderule_fp;                   /* Reference to configured ModeRule */
#endif
    /* Service handler */
    Std_ReturnType (*service_handler_fp) (Dcm_SrvOpStatusType SrvOpStatus ,Dcm_MsgContextType *Dcm_DsldMsgContext_st  ,Dcm_NegativeResponseCodeType *dataNrc  );
    void (*Service_init_fp) (void);                 /* Init function of service */
    uint8 sid_u8;                                    /* Service id */
    boolean  subfunction_exist_b;                    /* Is sub function exist for this service ? */
    boolean servicelocator_b;                        /* Is Service existing in DSP? */
    const Dcm_Dsld_SubServiceType * ptr_subservice_table_pcs;  /* Reference subservice table */
    uint8 num_sf_u8;
    Std_ReturnType (*adrUserServiceModeRule_pfct) (Dcm_NegativeResponseCodeType *ErrorCode,uint8 dataSid_u8 );
     /*Confirmation Callbacks */
    Dcm_ConfirmationApiType Dcm_ConfirmationService;    /* Reference Service confirmation Apis */
} Dcm_Dsld_ServiceType;


typedef struct
{
    const Dcm_Dsld_ServiceType * ptr_service_table_pcs;     /* Reference service table */
    uint8 num_services_u8;                           /* No of services in table   */
    uint8 nrc_sessnot_supported_u8;                  /* NRC for service not supported in active session */
    uint8 cdtc_index_u8;                       /* Unused variable */
} Dcm_Dsld_sid_tableType;


typedef struct
{
    uint8 protocol_num_u8;                           /* Protocol number */
    PduIdType txpduid_num_u8;                        /* TxPduId number */
    PduIdType roetype2_txpdu_u8;                     /* ROE type2 tx pduid */
    PduIdType rdpitype2_txpdu_u8;                    /* RDPI type2 tx pduid */
    uint16 testaddr_u16;                             /* Tester source address */
    uint8   channel_idx_u8;                      /* Index of corresponding channelid */
    uint8   ConnectionIndex_u8;                      /* Index of corresponsing connections */
    uint8   NumberOfTxpdu_u8;                        /* Number of Txpdus in a connection */
} Dcm_Dsld_connType;


typedef struct
{
    PduIdType rxpduid_num_u8;                        /* RxPduId number */
    uint16 testsrcaddr_u16;                          /* Tester source address */
} Dcm_Dsld_RoeRxToTestSrcMappingType;


typedef enum
{
    DCM_NONE=0,            /* no medium */
    DCM_CAN,               /* CAN       */
    DCM_KLINE,             /* KLINE     */
    DCM_FLEX,              /* FLEX      */
    DCM_LIN,               /* LIN       */
    DCM_IP,                /* IP        */
    DCM_INTERNAL           /* INTERNAL  */
}Dcm_DslDsd_MediumType_ten;


typedef enum
{
    DCM_COMM_ACTIVE,                            /* No COM mode in COM manager */
    DCM_COMM_NOT_ACTIVE
}Dcm_Dsld_activediagnostic_ten;

/* DSD State Machine */
typedef enum
{
    DSD_IDLE_E=0,
    DSD_VERIFICATION_E,
    DSD_CALL_SERVICE_E,
    DSD_WAITFORTXCONF_E,
    DSD_SENDTXCONF_APPL_E,
    DSD_CANCEL_E
}Dcm_DsdStatesType_ten;

typedef struct
{
    uint32 P2_max_u32;                               /* P2 max time in micro second */
    uint32 P3_max_u32;                               /* P3 max time in micro second */
} Dcm_Dsld_KwpTimerServerType;


typedef enum
{
    DCM_CURRENT,                                    /* Current timing set             */
    DCM_LIMIT                                      /* Limit timing set               */
}Dcm_TimerModeType;


typedef struct
{
    /* Reference to Rx table array */
    const uint8 * ptr_rxtable_pca;
    /* Reference to Tx table array */
    const PduIdType * ptr_txtable_pca;
    /* Reference to Connection table structure */
    const Dcm_Dsld_connType * ptr_conntable_pcs;
    /* Reference to protocol table */
    const Dcm_Dsld_protocol_tableType * protocol_table_pcs;
    /* Reference to sid table */
    const Dcm_Dsld_sid_tableType * sid_table_pcs;
     /* Session look up table */
    const uint8 * session_lookup_table_pcau8;
    /* Security look up table */
    const uint8 * security_lookup_table_pcau8;
} Dcm_Dsld_confType;


/*end types from DcmCore_DslDsd_Pub.h*/

typedef struct
{
    uint32 allowedSubSrvRoles_u32;
}Dcm_DsdSubSrvPBConfigType_tst;

typedef struct
{
    uint32  allowedRole_u32;
    const Dcm_DsdSubSrvPBConfigType_tst *subSrvPbCfg_past;
}Dcm_DsdServicePBConfigType_tst;


typedef struct
{
    uint8  ConfigSetId;
    const Dcm_DsdServicePBConfigType_tst **sidTablesPbCfg_pcast;
}Dcm_ConfigType; /*relevant for PB*/

/* ########################  begin internal types, which are used by generated code ##############*/

typedef struct
{
    PduIdType txPduId;
    uint8 cntFreeTxPduRdpi2Cntr_u8;
    boolean   isTxPduId_Busy;
    uint8    *buffer_pu8;
}Dcm_DslPeriodicType2ConfigType_tst;

typedef struct
{
    const PduIdType roeTxPduId;
    uint8 protocolRowIdx_u8;
    uint8 srvTableId_u8;
    Dcm_MsgType buffer_ptr;
    Dcm_MsgLenType txBufferSize_u32;
}Dcm_DslRoeConnConfigType_tst;

typedef struct
{
    Dcm_DslPeriodicType2ConfigType_tst *periodicType2Config_past;
    Dcm_MsgLenType txBufferSize_u32;
    const uint16 totalTxPduId_u16;
    uint8 protocolRowIdx_u8;
}Dcm_DslPeriodicConnConfigType_tst;

typedef Std_ReturnType (*serviceHandler_tfp) (Dcm_SrvOpStatusType SrvOpStatus,
        Dcm_MsgContextType *Dcm_DsldMsgContext_st,Dcm_NegativeResponseCodeType *dataNrc);

typedef struct
{
    uint8   subServiceId_u8;
    uint32  allowedSession_u32;
    uint32  allowedSecurity_u32;
    uint32  allowedRole_u32;
    serviceHandler_tfp serviceFuncHandler_fp;
    boolean (*subServiceModeRule_pfct) (Dcm_NegativeResponseCodeType *errorCode);
    Std_ReturnType (*subServiceUserModeRule_pfct) (Dcm_NegativeResponseCodeType * Nrc_u8,
            uint8 Sid_u8,uint8 Subfunc_u8);
    boolean isDspRDTCSubFnc_b;                  /* Is Dsp RDTC function or not*/
}Dcm_DsdSubServiceConfigType_tst;

typedef struct
{
    uint8   sid_u8;
    boolean  subFncAvail_b;
    uint8   numOfSubFnc_u8;
    boolean internalDspService_b;
    uint8 NRC_ServiceNotSupported_ActSession_u8;
    uint32  allowedSession_u32;
    uint32  allowedSecurity_u32;
    uint32  allowedRole_u32;
    void  (*serviceInit_fp) (void);
    serviceHandler_tfp serviceHandler_fp;
    const Dcm_DsdSubServiceConfigType_tst *subSrvCfg_pcast;
    boolean (*serviceModeRule_pfct) (Dcm_NegativeResponseCodeType *errorCode);
    Std_ReturnType (*serviceUserModeRule_pfct) (Dcm_NegativeResponseCodeType * Nrc_u8, uint8 Sid_u8);
    void (*serviceConfirmatione_pfct) (uint8 SID, uint8 ReqType,uint16 ConnectionId,Dcm_ConfirmationStatusType ConfirmationStatus,
                                   Dcm_ProtocolType ProtocolType,uint16 TesterSourceAddress);
}Dcm_DsdServiceTableConfigType_tst;

typedef struct
{
    uint8 protocolRowIdx_u8;
    uint8 mainConnectionIdx_u8;
    const Dcm_DslPeriodicConnConfigType_tst *periodicConn_past;
    const Dcm_DslRoeConnConfigType_tst      *roeConn_past;
    boolean dcmDslConnectionIsGeneric_b; /* Is a Generic Connection T/F */
}Dcm_DslConnectionConfigType_tst;


typedef struct
{
   const Dcm_DsdServiceTableConfigType_tst *srvTable_pcast;
   uint8 numOfServices_u8;
   uint8 cdtc_index_u8;
}Dcm_DsdSidTableConfigType_tst;

typedef enum
{
    DCM_TRANSTYPE1_E=0,
    DCM_TRANSTYPE2_E,
    DCM_INVALID_TRANSTYPE_E
}Dcm_TransType_ten;

typedef struct
{
    Dcm_ProtocolType protocolType;
    uint8    demClientId_u8;
    Dcm_TransType_ten  transType_en;
    uint8    priority_u8;
    Dcm_MsgType rxBuffer_u8;
    Dcm_MsgType txBuffer_u8;
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    Dcm_MsgType rx_reserveBuffer_pa;
#endif
    Dcm_MsgLenType rxBufferSize_u32;
    Dcm_MsgLenType txBufferSize_u32;
    uint8    srvTableId_u8;
    boolean  nrc21_b;
    boolean  sendRespPendOnTransToBoot_b;
    uint32   timStrP2ServerAdjust_u32;
    uint32   timStrP2StarServerAdjust_u32;
    uint16   maximumResponseSize_u16;
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    uint8  timings_limit_idx_u8;
    uint8  timings_idx_u8;
#endif
    uint16 dcmDspProtocolEcuAddr_u16;
}Dcm_DslProtocolRowConfigType_tst;

typedef struct
{
    uint8           comMChannelId_u8;
    uint16          rxConnId_u16;
    const uint16   *rxTesterSrcAddr_pcu16;
    PduIdType       txPduId;
    uint8           channel_idx_u8;
}Dcm_DslMainConnConfigType_tst;


typedef struct
{
    const PduIdType *protocolRx_pc;
    const Dcm_DslConnectionConfigType_tst  *dslConnection_pcast;
    const Dcm_DslProtocolRowConfigType_tst *protocolRowCfg_pcast;
    const Dcm_DslMainConnConfigType_tst    *mainConnCfg_pcast;
    const uint8 *SessionLookupTable_pcau8;
    #if (DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    const uint8 *KWPSessionLookupTable_pcau8;
    #endif
    const uint8 *SecurityLookupTable_pcu8;
    const uint8  *maxNumRespPend_pu8;
}Dcm_DslConfigType_tst;

typedef Std_ReturnType (*Dcm_Notification_tfp) (
                                       uint8 sid_u8,
                                       const uint8 *requestData_pcu8,
                                       uint32 dataSize_u32,
                                       uint8 reqType_u8,
                                       uint16 connectionId_u16,
                                       Dcm_NegativeResponseCodeType * ErrorCode,
                                       Dcm_ProtocolType protocolType,
                                       uint16 testerSrcAddress_u16);

typedef Std_ReturnType (*Dcm_Confirmation_tfp) (
                                       uint8 sid_u8,
                                       uint8 reqType_u8,
                                       uint16 connectionId_u16,
                                       Dcm_ConfirmationStatusType confirmationStatus,
                                       Dcm_ProtocolType protocolType,
                                       uint16 testerSrcAddress_u16);


typedef struct
{
  const Dcm_DsdSidTableConfigType_tst *sidTables_pcast;
  const Dcm_Notification_tfp        *ManufactureNotification_afp;
  const Dcm_Confirmation_tfp        *ManufactureConfirmation_afp;
  const Dcm_Notification_tfp        *SupplierNotification_afp;
  const Dcm_Confirmation_tfp        *SupplierConfirmation_afp;
}Dcm_DsdConfigType_tst;


#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
typedef enum
{
    DCM_DEAUTHENTICATED = 0u,
    DCM_AUTHENTICATED = 1u
}Dcm_stAuthenticationType_ten;

typedef struct
{
  uint16 connectionId_u16;
  Std_ReturnType (*modeSwitchInterface_fp) (Dcm_stAuthenticationType_ten stAuthentication_en);
} Dcm_AuthModeSwitchInfo_tst;



typedef struct
{
    uint32 challengeServerGenerateJobId_u32;
    uint32 proofOfOwnershipClientVerifyJobId_u32;
    uint16 certificateClientId_u16;
    uint16 roleCertElementId_u16;
    const uint16 * whitelistServiceCertElementId_pu16;
    const uint16 * whitelistDIDCertElementId_pu16;
    const uint16 * whitelistRIDCertElementId_pu16;
    const uint16 * whitelistMemSelnCertElementId_pu16;
}Dcm_AuthConnectionConfigType_tst;

typedef struct
{
    uint32 proofOfOwnershipServerGenerateJobId_u32;
    uint16 certificateServerId;
}Dcm_AuthConnectionBiDirectionalConfigType_tst;

typedef struct
{
    uint8 whitelist_au8[DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE];
    uint8 whitelistOffset_au8[DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE];
    uint8 whitelistNumEntry_u8;
}Dcm_WhitelistServiceType_tst;

typedef struct
{
    uint8 whitelist_au8[DCM_CFG_AUTH_WHITELIST_DID_MAX_SIZE];
    uint8 whitelistNumEntry_u8;
}Dcm_WhitelistDIDType_tst;

typedef struct
{
    uint8 whitelist_au8[DCM_CFG_AUTH_WHITELIST_RID_MAX_SIZE];
    uint8 whitelistNumEntry_u8;
}Dcm_WhitelistRIDType_tst;

typedef struct
{
    uint8 whitelist_au8[DCM_CFG_AUTH_WHITELIST_MEMSELN_MAX_SIZE];
    uint8 whitelistNumEntry_u8;
}Dcm_WhitelistMemSelnType_tst;

typedef struct
{
    Dcm_stAuthenticationType_ten *Dcm_stAuthentication_pen;
    uint8 *role_pau8;
    Dcm_WhitelistServiceType_tst *whitelistService_pst;
    Dcm_WhitelistDIDType_tst *whitelistDID_pst;
    Dcm_WhitelistRIDType_tst *whitelistRID_pst;
    Dcm_WhitelistMemSelnType_tst *whitelistMemSeln_pst;
}Dcm_AccessRightsTableType_tst;

#endif /*(DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)*/

typedef struct
{
  uint8     faultMemId_u8;
  uint32    faultMemRole_u32;
} Dcm_DspRDTCUserDefinedFaultMemmoryType_tst;


typedef struct
{
    boolean routineRangeHasGaps_b;
    uint16 routineRangeUpperLimit_u16;
    uint16 routineRangeLowerLimit_u16;
    uint16 routineCommonIndex_u16;
    Std_ReturnType (*isRangeRoutineAvailable_pfct) (uint16 dataRId_u16 ,Dcm_NegativeResponseCodeType * NRC);
} Dcm_RangeRoutineConfigType_tst;

typedef struct
{
    uint16 dataRId_u16;
    uint16 routineCommonIndex_u16;
    Std_ReturnType (*isNormalRoutineAvailable_pfct) (uint16 dataRId_u16);
} Dcm_NormalRoutineConfigType_tst;

typedef struct
{
    uint16 posnStart_u16;
    uint16 dataLength_u16;
    uint16 idxSignal_u16;
    uint8 dataEndianness_u8;
    uint8 dataType_u8;
} Dcm_RoutineSignalConfigType_tst;

typedef struct
{
    boolean (*modeCondition_pfct) (uint8 *dataNegRespCode_u8 );
    const Dcm_RoutineSignalConfigType_tst * const inSignalConfig_past;
    const Dcm_RoutineSignalConfigType_tst * const outSignalConfig_past;
    boolean isControlOptionRecordSizeFixed_b;
    uint16 minControlOptionRecordSize_u16;
    uint16 maxControlOptionRecordSize_u16;
    uint16 minStatusOptionRecordSize_u16;
    uint16 maxStatusOptionRecordSize_u16;
    uint8 numberOfInSignals_u8;
    uint8 numberOfOutSignals_u8;
} Dcm_RoutineSubFunctionConfigType_tst;


typedef struct
{
    uint32 allowedSessions_u32;
    uint32 allowedSecurityLevels_u32;
    uint32 allowedRoles_u32;
    Std_ReturnType (*userModeCondition_pfct) (Dcm_NegativeResponseCodeType *dataNegRespCode ,uint16 dataRId_u16 ,uint8 dataSubFunc_u8);
    Std_ReturnType (*routineHandler_pfct) (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
    const Dcm_RoutineSubFunctionConfigType_tst * const startConfig_pst;
    const Dcm_RoutineSubFunctionConfigType_tst * const stopConfig_pst;
    const Dcm_RoutineSubFunctionConfigType_tst * const requestResultsConfig_pst;
    boolean usePort_b;
    boolean stopRoutineOnSessionChange_b;
    boolean requestSequenceErrorSupported_b;
} Dcm_RoutineExtendedConfigType_tst;


typedef enum
{
    DCM_DSLD_NO_COM_MODE,                            /* No COM mode in COM manager */
    DCM_DSLD_SILENT_COM_MODE,                        /* Silent COM mode in COM manager */
    DCM_DSLD_FULL_COM_MODE                           /* Full COM mode in COM manager */
}Dcm_Dsld_commodeType;

typedef struct
{
    uint8   ComMChannelId;
    Dcm_Dsld_commodeType ComMState;
#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)
    Dcm_DslDsd_MediumType_ten  MediumId;
#endif
}Dcm_Dsld_ComMChannel;



/* ########################  end internal types, which are used by generated code ##############*/

/* ########################  start internal types, which are used by DcmAppl code ##############*/

typedef enum
{
    DCM_ROE_CLEARED=0,              /* Initialisation state of ROE events*/
    DCM_ROE_STOPPED,              /* State of ROE events when a valid ROE set up request is received from the tester */
    DCM_ROE_STARTED               /* State of ROE events when a ROE start request is received from the tester */
}Dcm_DspRoeEventState_ten;

/* ########################  end internal types, which are used by DcmAppl code ##############*/

#endif /* DCM_TYPES_H */
