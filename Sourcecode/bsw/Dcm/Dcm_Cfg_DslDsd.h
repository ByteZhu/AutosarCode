

/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DCM_CFG_DSLDSD_H
#define DCM_CFG_DSLDSD_H


#define DCM_CFG_ON                                                                      1u
#define DCM_CFG_OFF                                                                     0u


/*************************************************DCM General**********************************************************/
#define DCM_CFG_DDDID_STORAGE                                                           FALSE
#define DCM_CFG_RESPOND_ALLREQUEST                                                      TRUE
#define DCM_CFG_TASK_TIME_US                                                            1000u
#define DCM_CFG_TASK_TIME_MS                                                            1u     
#define DCM_CFG_S3MAX_TIME                                                              5000000u  
/* Configuration status of GetVersionInfo API */
#define DCM_CFG_VERSIONINFO_SUPPORTED                                                   TRUE
/* Configuration status of development error detectioin and notification API */
#define DCM_CFG_DET_SUPPORT_ENABLED                                                     TRUE

/**********************************************RbGeneral Configurations**********************************************/
#define     DCM_CFG_RESTORING_ENABLED               DCM_CFG_OFF         /* Restoring of BootLoader information is Disabled */

#define     DCM_CFG_STORING_ENABLED                 DCM_CFG_ON          /* Storing of BootLoader information is Enabled */

#define     DCM_CFG_APPLTXCONF_REQ                  DCM_CFG_OFF         /* Call of DcmAppl_DcmConfirmation callback is disabled */

#define     DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED       DCM_CFG_OFF         /* DiagAdapt Support from DCM is disabled */

#define     DCM_CFG_RBA_DEM_SR_ENABLED       DCM_CFG_OFF         /* Sender-Receiver Interface for Dem is disabled */

#define     DCM_CFG_RESPOND_REQ_AFTERECURESET       DCM_CFG_ON          /* Respond to request after successful EcuReset service processing */


#define     DCM_CFG_ECURESET_TIME                   0u


#define     DCM_CFG_SECURITY_STOREDELAYCOUNTANDTIMERONJUMP          DCM_CFG_OFF         /* DelayCount and DelayTimer values shall not be stored during Boot Loader interactions */

#define     DCM_CFG_RTESUPPORT_ENABLED              DCM_CFG_ON          /* RTE Support within Dcm enabled */

#define     DCM_SEPARATEBUFFERFORTXANDRX_ENABLED            DCM_CFG_ON          /* Separate buffer for transmission and reception will be used */

#define     DCM_BUFQUEUE_ENABLED            DCM_CFG_ON          /* Queuing of requests in Dcm is enabled */

#define     DCM_CALLAPPLICATIONONREQRX_ENABLED            DCM_CFG_OFF         /* Calling the application while receiving the request in Dcm is disabled */

#define    DCM_PARALLELPROCESSING_ENABLED                 DCM_CFG_OFF /* Parallel Processing of protocols are disabled */



#define DCM_CFG_SUPPRESS_NRC(NegRespCode) (((NegRespCode) == 0x11u) ||((NegRespCode) == 0x12u) ||((NegRespCode) == 0x31u) ||((NegRespCode) == 0x7Eu) ||((NegRespCode) == 0x7Fu) )   /* Suppress NRCs during Functional addressing */


#define     DCM_CFG_WAIT_FOR_VIN                    DCM_CFG_MAX_WAITPEND               /* Max. no. of Wait Pend that can be sent before sending a General Reject NRC */

#define     DCM_CFG_OSTIMER_USE                     FALSE


#define     DCM_CFG_SIGNAL_DEFAULT_VALUE            0u    /* Default Value for Signals with Gap. To reset signal data with default value */


/**********************************************Dsl connection Configurations*******************************************/
#define DCM_CFG_TXPDUID_NOTCONFIGURED                                                   0xFFFFu                                   

#define DCM_CFG_BUFFERSIZE_NOTCONFIGURED                                                0x0u  
#define DCM_CFG_SIDTABLE_NOTCONFIGURED                                                  0xFFu 

#define DCM_CFG_TOTAL_DSL_CONNECTIONS                                                   1u

#define DCM_CFG_DSL_CONNECTION_INDEX0                                                   0u /* Protocol DcmDslProtocolRow_UDS Connection DcmDslConnection_CAN */
#define DCM_CFG_INVALID_CONNECTION_INDEX                                                 DCM_CFG_TOTAL_DSL_CONNECTIONS

/**********************************************ProtocolRow Configurations**********************************************/
#define DCM_CFG_DCMDSLPROTOCOLROW_UDS                                                   0u

#define     DCM_CFG_KWP_ENABLED                     DCM_CFG_OFF

#define     DCM_CFG_KLINE_ENABLED                   DCM_CFG_OFF


#define     DCM_CFG_PROTOCOL_PREMPTION_ENABLED      DCM_CFG_OFF



#define DCM_CFG_RXPDU_SHARING_ENABLED   DCM_CFG_OFF



#define DCM_ROE_ENABLED                 DCM_CFG_OFF             /* Enable or Disable ROE */




#define DCM_CFG_ROETYPE2_ENABLED            DCM_CFG_OFF     /* Enable or Disable ROE TYPE 2 */




#define DCM_CFG_RDPI_ENABLED           DCM_CFG_OFF     /* Enable or Disable RDPI TYPE 2 */


#define     DCM_CFG_DSL_BUFFER__DCMDSLBUFFER_UDS_TX 512   /* Buffer Size */
#define     DCM_CFG_DSL_BUFFER__DCMDSLBUFFER_UDS_RX 512   /* Buffer Size */

#define     DCM_CFG_INFINITE_WAITPEND_ENABLED       DCM_CFG_OFF
#define     DCM_CFG_MAX_WAITPEND                    5u                 /* Max. no. of Wait Pend that can be sent before sending a General Reject NRC */

#define DCM_UDS_DCMDSLPROTOCOLROW_UDS     0xF0           /*User specific Protocol ID */


/*********************************************MainConnection Configurations********************************************/
#define DCM_CFG_DCMDSLPROTOCOLROW_UDS_MAINCONNECTION_0                                  0u

/* Number of rx pdu ids DCM has */
#define DCM_CFG_TOTAL_RX_PDUID                                                          2u

#define DCM_CFG_INVALID_RX_PDUID                                                         DCM_CFG_TOTAL_RX_PDUID + 1u
#define DCM_CFG_INVALID_PROTOCOLRXTABLE_INDEX                                            DCM_CFG_TOTAL_RX_PDUID
#define DCM_CFG_PROTOCOLRXTABLE_LENGTH                                                   DCM_CFG_TOTAL_RX_PDUID + 1u

/* Total No. of Tx Pdu Ids supported within Dcm */
#define DCM_CFG_TOTAL_TX_PDUID                                                          1u 

#define DCM_CFG_INVALID_TX_PDUID                                                         DCM_CFG_TOTAL_TX_PDUID + 1u
#define DCM_CFG_INVALID_TX_PDUINDEX                                                      DCM_CFG_TOTAL_TX_PDUID
#define DCM_CFG_PDUIDTABLE_TX_LENGTH                                                     DCM_CFG_TOTAL_TX_PDUID + 1u

/* Index from where functional rx pdu id will starts */
#define DCM_CFG_INDEX_FUNC_RX_PDUID                                                     1u             
         
 /* Number of unique comm channel references in DCM */
#define DCM_NUM_COMM_CHANNEL                    1u

#define DCM_CFG_NUM_PROTOCOL                1u               /* Number of protocols DCM has */

#define DCM_CFG_NUMPDUINFO_STRUCT 1u  /*Number of Pdu Info Structure Required */


/* Number of Callback Ports to RTE */
#define     DCM_CFG_CALL_BACK_NUM_PORTS                0




/******************************************************Symbolic Name generation****************************************/

#ifdef DcmConf_DcmDslProtocolRx_Diag_Physical_request_PduR2Dcm_Can_Network_0_Channel_CAN
#error "Symbolic names generated for DcmDslProtocolRxPduId is incorrect as the short names of configured DcmDslProtocolRx in not unique, Run Generate Id and Config Code generation once again."
#else
#define DcmConf_DcmDslProtocolRx_Diag_Physical_request_PduR2Dcm_Can_Network_0_Channel_CAN       0x0      /*Rx PDU ID*/
#endif
#ifdef DcmConf_DcmDslProtocolRx_Diag_Functional_request_PduR2Dcm_Can_Network_0_Channel_CAN
#error "Symbolic names generated for DcmDslProtocolRxPduId is incorrect as the short names of configured DcmDslProtocolRx in not unique, Run Generate Id and Config Code generation once again."
#else
#define DcmConf_DcmDslProtocolRx_Diag_Functional_request_PduR2Dcm_Can_Network_0_Channel_CAN       0x1      /*Rx PDU ID*/
#endif

/* Symbolic Name generation for TxConfirmtionPduId */

#ifdef DcmConf_DcmDslProtocolTx_Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN
#error "Symbolic names generated for DcmDslTxConfirmationPduId is incorrect as the short names of configured DcmDslProtocolTx in not unique, Run Generate Id and Config Code generation once again."
#else
#define DcmConf_DcmDslProtocolTx_Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN         0x0 /*Tx Confirmation PDU ID*/
#endif


/* This is the macro the customer/production team have to modify the
************Enable or Disable the Postbuild support*****************/
#define     DCM_CFG_POSTBUILD_SUPPORT               DCM_CFG_OFF
/* Bit Masks for different DCM configuration sets */
#define     DCM_CFG_CONFIGSET1                      0x01                /*Bit mask for DCM configuration set1*/
#define     DCM_CFG_CONFIGSET2                      0x02                /*Bit mask for DCM configuration set2*/
#define     DCM_CFG_CONFIGSET3                      0x04                /*Bit mask for DCM configuration set3*/
#define     DCM_CFG_CONFIGSET4                      0x08                /*Bit mask for DCM configuration set4*/
#define     DCM_CFG_CONFIGSET5                      0x10                /*Bit mask for DCM configuration set5*/
#define     DCM_CFG_CONFIGSET6                      0x20                /*Bit mask for DCM configuration set6*/
#define     DCM_CFG_CONFIGSET7                      0x40                /*Bit mask for DCM configuration set7*/
#define     DCM_CFG_CONFIGSET8                      0x80                /*Bit mask for DCM configuration set8*/


/* Mapping old macros to coding guideline compliant macros to ensure backward compatibility */
            /* Obsolete */
#ifndef         DCM_S3MAX_TIME
#define     DCM_S3MAX_TIME                          DCM_CFG_S3MAX_TIME
#endif
#ifndef     DCM_DET_SUPPORT_ENABLED
#define     DCM_DET_SUPPORT_ENABLED                 DCM_CFG_DET_SUPPORT_ENABLED
#endif
#ifndef     DCM_TASK_TIME_US
#define     DCM_TASK_TIME_US                        DCM_CFG_TASK_TIME_US
#endif
#ifndef     DCM_TASK_TIME_MS
#define     DCM_TASK_TIME_MS                        DCM_CFG_TASK_TIME_MS
#endif
#ifndef     DCM_KWP_ENABLED
#define     DCM_KWP_ENABLED                         DCM_CFG_KWP_ENABLED
#endif
#ifndef     DCM_RESTORING_ENABLED
#define     DCM_RESTORING_ENABLED                   DCM_CFG_RESTORING_ENABLED
#endif
#ifndef     DCM_STORING_ENABLED
#define     DCM_STORING_ENABLED                     DCM_CFG_STORING_ENABLED
#endif

#ifndef     DCM_APPLTXCONF_REQ
#define     DCM_APPLTXCONF_REQ                      DCM_CFG_APPLTXCONF_REQ
#endif
#ifndef     DCM_VERSION_INFO_API
#define     DCM_VERSION_INFO_API                    DCM_CFG_VERSION_INFO_API
#endif
#ifndef     DCM_SUPPLIER_NOTIFICATION_ENABLED
#define     DCM_SUPPLIER_NOTIFICATION_ENABLED       DCM_CFG_SUPPLIER_NOTIFICATION_ENABLED
#endif
#ifndef     DCM_MANUFACTURER_NOTIFICATION_ENABLED
#define     DCM_MANUFACTURER_NOTIFICATION_ENABLED   DCM_CFG_MANUFACTURER_NOTIFICATION_ENABLED
#endif
#ifndef     DCM_RBA_DIAGADAPT_SUPPORT_ENABLED
#define     DCM_RBA_DIAGADAPT_SUPPORT_ENABLED       DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED
#endif
#ifndef     DCM_RESPOND_ALLREQUEST
#define     DCM_RESPOND_ALLREQUEST                  DCM_CFG_RESPOND_ALLREQUEST
#endif
#ifndef     DCM_RTESUPPORT_ENABLED
#define     DCM_RTESUPPORT_ENABLED                  DCM_CFG_RTESUPPORT_ENABLED
#endif

#ifndef     DCM_NUM_CONN
#define     DCM_NUM_CONN                            DCM_CFG_TOTAL_DSL_CONNECTIONS
#endif
#ifndef     DCM_NUM_RX_PDUID
#define     DCM_NUM_RX_PDUID                        DCM_CFG_TOTAL_RX_PDUID
#endif
#ifndef     DCM_NUM_PROTOCOL
#define     DCM_NUM_PROTOCOL                        DCM_CFG_NUM_PROTOCOL
#endif
#ifndef     DCM_NUM_SID_TABLE
#define     DCM_NUM_SID_TABLE                       DCM_CFG_NUM_SID_TABLE
#endif
#ifndef     DCM_NUMPDUINFO_STRUCT
#define     DCM_NUMPDUINFO_STRUCT                   DCM_CFG_NUMPDUINFO_STRUCT
#endif
#ifndef     DCM_MAX_WAITPEND
#define     DCM_MAX_WAITPEND                        DCM_CFG_MAX_WAITPEND
#endif
#ifndef     DCM_DEFAULT_P2MAX_TIME
#define     DCM_DEFAULT_P2MAX_TIME                  DCM_CFG_DEFAULT_P2MAX_TIME
#endif
#ifndef     DCM_DEFAULT_P2STARMAX_TIME
#define     DCM_DEFAULT_P2STARMAX_TIME              DCM_CFG_DEFAULT_P2STARMAX_TIME
#endif
#ifndef     DCM_NUM_UDS_SESSIONS
#define     DCM_NUM_UDS_SESSIONS                    DCM_CFG_NUM_UDS_SESSIONS
#endif
#ifndef     DCM_NUM_SECURITY_LEVEL
#define     DCM_NUM_SECURITY_LEVEL                  DCM_CFG_NUM_SECURITY_LEVEL
#endif
#ifndef     DCM_OSTIMER_USE
#define     DCM_OSTIMER_USE                         DCM_CFG_OSTIMER_USE
#endif
#ifndef     DCM_ROETYPE2_ENABLED
#define     DCM_ROETYPE2_ENABLED                    DCM_CFG_ROETYPE2_ENABLED
#endif
#ifndef     DCM_RDPI_ENABLED
#define     DCM_RDPI_ENABLED                        DCM_CFG_RDPI_ENABLED
#endif
#ifndef     DCM_MAX_PERIODIC_DID_READ
#define     DCM_MAX_PERIODIC_DID_READ               DCM_CFG_MAX_PERIODIC_DID_READ
#endif
#ifndef     DCM_MAX_DID_SCHEDULER
#define     DCM_MAX_DID_SCHEDULER                   DCM_CFG_MAX_DID_SCHEDULER
#endif
#ifndef     DCM_ROE_INTERMESSAGE_TIME
#define     DCM_ROE_INTERMESSAGE_TIME               DCM_CFG_ROE_INTERMESSAGE_TIME
#endif
#ifndef     DCM_PROTOCOL_PREMPTION_ENABLED
#define     DCM_PROTOCOL_PREMPTION_ENABLED          DCM_CFG_PROTOCOL_PREMPTION_ENABLED
#endif
#ifndef     DCM_DSL_BUFFER_DCMDSLBUFFER_0
#define     DCM_DSL_BUFFER_DCMDSLBUFFER_0           DCM_CFG_DSL_BUFFER__DCMDSLBUFFER_0
#endif
#ifndef     DCM_DSL_BUFFER_DCMDSLBUFFER_1
#define     DCM_DSL_BUFFER_DCMDSLBUFFER_1           DCM_CFG_DSL_BUFFER__DCMDSLBUFFER_1
#endif
#ifndef     DCM_DSL_BUFFER_DCMDSLBUFFER_2
#define     DCM_DSL_BUFFER_DCMDSLBUFFER_2           DCM_CFG_DSL_BUFFER__DCMDSLBUFFER_2
#endif
#ifndef     DCM_DSL_BUFFER_DCMDSLBUFFER_3
#define     DCM_DSL_BUFFER_DCMDSLBUFFER_3           DCM_CFG_DSL_BUFFER__DCMDSLBUFFER_3
#endif
#ifndef     DCM_DSL_BUFFER_DCMDSLBUFFER_4
#define     DCM_DSL_BUFFER_DCMDSLBUFFER_4           DCM_CFG_DSL_BUFFER__DCMDSLBUFFER_4
#endif
#ifndef     DCM_DSP_UDSSUPPORT_ENABLED
#define     DCM_DSP_UDSSUPPORT_ENABLED              DCM_CFG_DSPUDSSUPPORT_ENABLED
#endif
#ifndef     DCM_DSP_OBDSUPPORT_ENABLED
#define     DCM_DSP_OBDSUPPORT_ENABLED              DCM_CFG_DSPOBDSUPPORT_ENABLED
#endif
#ifndef     DCM_SIGNAL_DEFAULT_VALUE
#define     DCM_SIGNAL_DEFAULT_VALUE                DCM_CFG_SIGNAL_DEFAULT_VALUE
#endif
#ifndef     DCM_RXPDU_SHARING_ENABLED
#define     DCM_RXPDU_SHARING_ENABLED               DCM_CFG_RXPDU_SHARING_ENABLED
#endif
#ifndef     DCM_CONFIGSET1
#define     DCM_CONFIGSET1                          DCM_CFG_CONFIGSET1
#endif
#ifndef     DCM_CONFIGSET2
#define     DCM_CONFIGSET2                          DCM_CFG_CONFIGSET2
#endif
#ifndef     DCM_CONFIGSET3
#define     DCM_CONFIGSET3                          DCM_CFG_CONFIGSET3
#endif
#ifndef     DCM_CONFIGSET4
#define     DCM_CONFIGSET4                          DCM_CFG_CONFIGSET4
#endif
#ifndef     DCM_CONFIGSET5
#define     DCM_CONFIGSET5                          DCM_CFG_CONFIGSET5
#endif
#ifndef     DCM_CONFIGSET6
#define     DCM_CONFIGSET6                          DCM_CFG_CONFIGSET6
#endif
#ifndef     DCM_CONFIGSET7
#define     DCM_CONFIGSET7                          DCM_CFG_CONFIGSET7
#endif
#ifndef     DCM_CONFIGSET8
#define     DCM_CONFIGSET8                          DCM_CFG_CONFIGSET8
#endif
#ifndef     DCM_SHARED_RX_PDUID
#define     DCM_SHARED_RX_PDUID         DCM_CFG_SHARED_RX_PDUID
#endif
#ifndef     DCM_POSTBUILD_SUPPORT
#define     DCM_POSTBUILD_SUPPORT       DCM_CFG_POSTBUILD_SUPPORT
#endif
#ifndef     DCM_ROE_RESUME_RXPDUID
#define     DCM_ROE_RESUME_RXPDUID      DCM_CFG_ROE_RESUME_RXPDUID
#endif
#ifndef     DCM_ROERDPI_TIMEOUT
#define     DCM_ROERDPI_TIMEOUT         DCM_CFG_GET_TIMEOUT
#endif
#ifndef     DCM_NUM_RDPITYPE2_TXPDU
#define     DCM_NUM_RDPITYPE2_TXPDU     DCM_CFG_NUM_RDPITYPE2_TXPDU
#endif
#ifndef     DCM_PERIODICTX_SLOWRATE
#define     DCM_PERIODICTX_SLOWRATE     DCM_CFG_PERIODICTX_SLOWRATE
#endif
#ifndef     DCM_PERIODICTX_MEDIUMRATE
#define     DCM_PERIODICTX_MEDIUMRATE   DCM_CFG_PERIODICTX_MEDIUMRATE
#endif
#ifndef     DCM_PERIODICTX_FASTRATE
#define     DCM_PERIODICTX_FASTRATE     DCM_CFG_PERIODICTX_FASTRATE
#endif



/*************************************************DSD Configurations**************************************************/

/*************************************************Service tables************************************************/
#ifndef     DCM_ECU_EPS_SERVICETABLE
#define     DCM_ECU_EPS_SERVICETABLE     0x0
#endif


#define DCM_CFG_NUM_SID_TABLE              1u               /* Number of SID table configured */
/*************************************************Service configuration************************************************/
#define     DCM_CFG_DSPUDSSUPPORT_ENABLED           DCM_CFG_ON      /* Enable or Disable UDS services in DSP */



#define     DCM_CFG_DSPOBDSUPPORT_ENABLED           DCM_CFG_OFF     /* Enabled or Disabled based on OBD services configured in DSP */


#define DCM_CFG_DSP_OBDMODE01_ENABLED                                                   DCM_CFG_OFF 
#define DCM_CFG_DSP_OBDMODE02_ENABLED                                                   DCM_CFG_OFF 
#define DCM_CFG_DSP_OBDMODE37A_ENABLED                                                  DCM_CFG_OFF 
#define DCM_CFG_DSP_OBDMODE04_ENABLED                                                   DCM_CFG_OFF 
#define DCM_CFG_DSP_OBDMODE06_ENABLED                                                   DCM_CFG_OFF 
#define DCM_CFG_DSP_OBDMODE08_ENABLED                                                   DCM_CFG_OFF 
#define DCM_CFG_DSP_OBDMODE09_ENABLED                                                   DCM_CFG_OFF 
#define DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED                                    DCM_CFG_ON  
#define DCM_CFG_DSP_ECURESET_ENABLED                                                    DCM_CFG_ON  
#define DCM_CFG_DSP_CLEARDIAGNOSTICINFORMATION_ENABLED                                  DCM_CFG_ON  
#define DCM_CFG_DSP_READDTCINFORMATION_ENABLED                                          DCM_CFG_ON  
#define DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED                                        DCM_CFG_ON  
#define DCM_CFG_DSP_READMEMORYBYADDRESS_ENABLED                                         DCM_CFG_OFF 
#define DCM_CFG_DSP_SECURITYACCESS_ENABLED                                              DCM_CFG_ON  
#define DCM_CFG_DSP_AUTHENTICATION_ENABLED                                              DCM_CFG_OFF 
#define DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED                                        DCM_CFG_ON  
#define DCM_CFG_DSP_READDATABYPERIODICIDENTIFIER_ENABLED                                DCM_CFG_OFF 
#define DCM_CFG_DSP_DYNAMICALLYDEFINEIDENTIFIER_ENABLED                                 DCM_CFG_OFF 
#define DCM_CFG_DSP_WRITEDATABYIDENTIFIER_ENABLED                                       DCM_CFG_ON  
#define DCM_CFG_DSP_INPUTOUTPUTCONTROLBYIDENTIFIER_ENABLED                              DCM_CFG_OFF 
#define DCM_CFG_DSP_ROUTINECONTROL_ENABLED                                              DCM_CFG_ON  
#define DCM_CFG_DSP_REQUESTDOWNLOAD_ENABLED                                             DCM_CFG_OFF 
#define DCM_CFG_DSP_REQUESTUPLOAD_ENABLED                                               DCM_CFG_OFF 
#define DCM_CFG_DSP_TRANSFERDATA_ENABLED                                                DCM_CFG_OFF 
#define DCM_CFG_DSP_REQUESTTRANSFEREXIT_ENABLED                                         DCM_CFG_OFF 
#define DCM_CFG_DSP_WRITEMEMORYBYADDRESS_ENABLED                                        DCM_CFG_OFF 
#define DCM_CFG_DSP_TESTERPRESENT_ENABLED                                               DCM_CFG_ON  
#define DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED                                           DCM_CFG_ON  
#define DCM_CFG_DSP_RESPONSEONEVENT_ENABLED                                             DCM_CFG_OFF 

#define DCM_CFG_DSD_MODERULESERVICE_ENABLED         DCM_CFG_ON      /* Mode Rules are referred by services of Dcm */
#define DCM_CFG_DSD_MODERULESUBFNC_ENABLED         DCM_CFG_ON       /* Mode Rules are referred by Subservices of Dcm */

#define     DCM_CFG_DSP_DDDISTORINGTONVRAM_ENABLED          DCM_CFG_OFF         /* Storing/restoring of DDDID definition to/from NvM is disabled */


#define DCM_CFG_MANUFACTURER_NOTIFICATION_ENABLED   DCM_CFG_ON  /* Manufacturer Notification enabled */

/* Number of ServiceRequestManufacturerNotification Ports*/
#define DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS                                      0u

#define DCM_CFG_SUPPLIER_NOTIFICATION_ENABLED   DCM_CFG_OFF /* Supplier Notification disabled */

/* Number of ServiceRequestSupplierNotification Ports */
#define DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS                                          0u

#define     DCM_PAGEDBUFFER_ENABLED             DCM_CFG_ON          /* Paged buffer Support is enabled */


#endif  /* DCM_CFG_H */
