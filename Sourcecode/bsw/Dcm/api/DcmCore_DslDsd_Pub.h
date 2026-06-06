

#ifndef DCMCORE_DSLDSD_PUB_H
#define DCMCORE_DSLDSD_PUB_H

/************************************************************************************************/
/* Included  header files                                                                       */
/************************************************************************************************/

/*
 ***************************************************************************************************
 *    definitions and Typedefs
 ***************************************************************************************************
 */

/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 *
 * Definitions of DID/PID Signal DataTypes\n
 *
 *
 */
#define DCM_BOOLEAN                     0x00u
#define DCM_UINT8                       0x01u
#define DCM_UINT16                      0x02u
#define DCM_UINT32                      0x03u
#define DCM_SINT8                       0x04u
#define DCM_SINT16                      0x05u
#define DCM_SINT32                      0x06u
#define DCM_VARIABLE_LENGTH             0x07u
#define DCM_UINT8_N                     0x08u
#define DCM_UINT16_N                    0x09u
#define DCM_UINT32_N                    0x0Au
#define DCM_SINT8_N                     0x0Bu
#define DCM_SINT16_N                    0x0Cu
#define DCM_SINT32_N                    0x0Du


/* Value from which the Array Data Types for Routine Control Starts */
#define DCM_RCARRAYINDEX  0x08u

/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 *
 * Definitions of DID/PID/RID Endianness Types\n
 *
 *
 */
#define DCM_LITTLE_ENDIAN               0x00u
#define DCM_BIG_ENDIAN                  0x01u
#define DCM_OPAQUE                      0x02u

/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 * This will specify the Ecu Start mode.If it  is set ,the Ecu starts from a bootloader jump.
 * If it is zero,Ecu starts normally.
 * DCM_COLD_START\n
 * DCM_WARM_START\n
 *
 *
 */


#define DCM_COLD_START   0x0u /* The ECU starts normally */
#define DCM_WARM_START   0x1u /* The ECU starts from a bootloader jump */



/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * define for  functional request
 *
 */
#define DCM_PRV_FUNCTIONAL_REQUEST          1u
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * define for  physical request
 *
 */
#define DCM_PRV_PHYSICAL_REQUEST            0u

/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Defines for maximum number of dcm config sets
 *
 */
#define DCM_PRV_MAXNUM_OF_CONFIG            8u

/*  Base item type to transport status information.
 *
 *                                             */


/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 * Base item type to transport status information.\n
 * DCM_E_OK This value is representing a successful operation.\n
 * DCM_E_TI_PREPARE_LIMITS New timing parameters are not ok, since requested values are not within the defined limits (used at API: Dcm_PrepareSesTimingValues()).\n
 * DCM_E_TI_PREPARE_INCONSTENT New timing parameters are not ok, since requested values are not consistent (e.g. P2min not smaller than P2max)(used at API: Dcm_PrepareSesTimingValues())\n
 * DCM_E_ROE_NOT_ACCEPTED ResponseOnOneEvent request is not accepted by DCM (e.g. old ResponseOnOneEvent is not finished) (used at API: Dcm_Prv_ResponseOnOneEvent())\n
 * DCM_E_PERIODICID_NOT_ACCEPTED Periodic transmission request is not accepted by DCM (e.g. old Periodic transmission is not finished) (used at API: Dcm_ResponseOnOneDataByPeriodicId ())\n
 *
 */


/* positive case return by the Appl fucntion                                                    */
#define DCM_E_OK                        0u

/* New timing parameter are not ok, since requested values are not within the defined limits    */
#define DCM_E_TI_PREPARE_LIMITS         2u

/* New timing parameter are not ok, since requested values are not consistent(e.g.P2min not     */
/* smaller than P2max)                                                                          */
#define DCM_E_TI_PREPARE_INCONSTENT     3u

/* ResponseOnOneEvent request is not accepted by DCM (e.g. old ResponseOnOneEvent is            */
/* not finished)                                                                                */
#define DCM_E_ROE_NOT_ACCEPTED          6u

/* Periodic transmission request is not accepted by DCM (e.g. old Periodic transmission is      */
/* not finished)                                                                                */
#define DCM_E_PERIODICID_NOT_ACCEPTED   7u

/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Seed sent by application is not correct
 *
 */

#define DCM_E_SEED_NOK                   11u
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Time Monitoring is required for SECA request
 *
 */
#define DCM_E_MONITORING_REQ             12u
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Time Monitoring is not required for SECA request
 *
 */

#define DCM_E_MONITORING_NOTREQ          13u


#define DCM_UNUSED_PARAM(P)   ((void)(P))






#ifndef DEFAULT_SESSION
/* Macro according to SWS.2.1.1 */
/**
 *   @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Session type definition:This type is defined in Rte_Dcm_Type.h header file, which is generated by the RTE generator\n
 *  Default session\n
 *  DEFAULT_SESSION 0x01\n
 */
#define DEFAULT_SESSION DCM_DEFAULT_SESSION
#endif

#ifndef PROGRAMMING_SESSION
/* Macro according to SWS.2.1.1 */
/**
 *   @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Session type definition:This type is defined in Rte_Dcm_Type.h header file, which is generated by the RTE generator\n
 *  Programming session\n
 *  PROGRAMMING_SESSION 0x02\n
 */
#define PROGRAMMING_SESSION  DCM_PROGRAMMING_SESSION
#endif

#ifndef EXTENDED_DIAGNOSTIC_SESSION
/* Macro according to SWS.2.1.1 */
/**
 *   @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Session type definition:This type is defined in Rte_Dcm_Type.h header file, which is generated by the RTE generator\n
 *  Extended diagnostic session\n
 *  EXTENDED_DIAGNOSTIC_SESSION 0x03\n
 */
#define EXTENDED_DIAGNOSTIC_SESSION    DCM_EXTENDED_DIAGNOSTIC_SESSION
#endif

#ifndef SAFETY_SYSTEM_DIAGNOSTIC_SESSION
/* Macro according to SWS.2.1.1 */
/**
 *   @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Session type definition:This type is defined in Rte_Dcm_Type.h header file, which is generated by the RTE generator\n
 *  Safety  system diagnostics session\n
 *  SAFETY_SYSTEM_DIAGNOSTICS_SESSION 0x04\n
 */
#define SAFETY_SYSTEM_DIAGNOSTIC_SESSION  DCM_SAFETY_SYSTEM_DIAGNOSTICS_SESSION
#endif

#ifndef DCM_ALL_SESSION_LEVEL
/**
 *   @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Session type definition:This type is defined in Rte_Dcm_Type.h header file, which is generated by the RTE generator\n
 *  All sessions\n
 *  DCM_ALL_SESSION_LEVEL 0xFF\n
 *  (Reserved by Document 0x7F...0xFE)
 */
#define DCM_ALL_SESSION_LEVEL 0xFFu
#endif

#ifndef DCM_SEC_LEV_LOCKED
/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Security level type definition:This type is defined in Rte_Dcm_Type.h header file, which is generated by the RTE generator\n
 *  Security level locked\n
 *  DCM_SEC_LEV_LOCKED 0x00\n
 */
#define DCM_SEC_LEV_LOCKED  0x00u
#endif

#ifndef DCM_SEC_LEV_ALL
/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Security level type definition:This type is defined in Rte_Dcm_Type.h header file, which is generated by the RTE generator\n
 *  Security level all\n
 *  DCM_SEC_LEV_ALL     0xFF\n
 */
#define DCM_SEC_LEV_ALL     0xFFu
#endif

#ifndef DCM_RES_POS_OK
/* POS response sent successfully */
#define DCM_RES_POS_OK      0u
#endif

#ifndef DCM_RES_POS_NOT_OK
/* unable to sent POS response   */
#define DCM_RES_POS_NOT_OK  1u
#endif

#ifndef DCM_RES_NEG_OK
/* NEG response sent successfully */
#define DCM_RES_NEG_OK      2u
#endif

#ifndef DCM_RES_NEG_NOT_OK
/* unable to sent NEG response   */
#define DCM_RES_NEG_NOT_OK  3u
#endif


#ifndef DCM_UDS_TESTER_SOURCE
/* Source of request is tester */
#define DCM_UDS_TESTER_SOURCE   0u
#endif

#ifndef DCM_ROE_SOURCE
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 *  Source of request is ROE application\n
 */
#define DCM_ROE_SOURCE          1u
#endif


#ifndef DCM_RDPI_SOURCE
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 *  Source of request is RDPI application\n
 */
#define DCM_RDPI_SOURCE          2u
#endif

#ifndef DCM_RDPI_SID
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 *  Service Identifier for RDPI\n
 */
#define DCM_RDPI_SID        0x2Au
#endif
/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 *  Dcm_CommunicationModeType:\n
 *  DCM_ENABLE_RX_TX_NORM 0x00  Enable the Rx and Tx for normal communication\n
 *  DCM_ENABLE_RX_DISABLE_TX_NORM 0x01 Enable the Rx and disable the Tx for normal communication\n
 *  DCM_DISABLE_RX_ENABLE_TX_NORM 0x02 Disable the Rx and enable the Tx for normal communication\n
 *  DCM_DISABLE_RX_TX_NORMAL 0x03 Disable Rx and Tx for normal communication\n
 *  DCM_ENABLE_RX_TX_NM  0x04 Enable the Rx and Tx for network management communication\n
 *  DCM_ENABLE_RX_DISABLE_TX_NM 0x05 Enable Rx and disable the Tx for network management communication\n
 *  DCM_DISABLE_RX_ENABLE_TX_NM 0x06 Disable the Rx and enable the Tx for network management communication\n
 *  DCM_DISABLE_RX_TX_NM 0x07 Diable Rx and Tx for network management communication\n
 *  DCM_ENABLE_RX_TX_NORM_NM 0x08 Enable Rx and Tx for normal and network management communication\n
 *  DCM_ENABLE_RX_DISABLE_TX_NORM_NM 0x09 Enable the Rx and disable the Tx for normal and network management communication\n
 *  DCM_DISABLE_RX_ENABLE_TX_NORM_NM 0x0A Disable the Rx and enable the Tx for normal and network management communication\n
 *  DCM_DISABLE_RX_TX_NORM_NM 0x0B Disable Rx and Tx for normal and network management communication.
 */


#ifndef DCM_ENABLE_RX_TX_NORM
#define DCM_ENABLE_RX_TX_NORM 0x00u
#endif

#ifndef DCM_ENABLE_RX_DISABLE_TX_NORM
#define DCM_ENABLE_RX_DISABLE_TX_NORM 0x01u
#endif

#ifndef DCM_DISABLE_RX_ENABLE_TX_NORM
#define DCM_DISABLE_RX_ENABLE_TX_NORM 0x02u
#endif

#ifndef DCM_DISABLE_RX_TX_NORMAL
#define DCM_DISABLE_RX_TX_NORMAL 0x03u
#endif

#ifndef DCM_ENABLE_RX_TX_NM
#define DCM_ENABLE_RX_TX_NM 0x04u
#endif

#ifndef DCM_ENABLE_RX_DISABLE_TX_NM
#define DCM_ENABLE_RX_DISABLE_TX_NM 0x05u
#endif

#ifndef DCM_DISABLE_RX_ENABLE_TX_NM
#define DCM_DISABLE_RX_ENABLE_TX_NM 0x06u
#endif

#ifndef DCM_DISABLE_RX_TX_NM
#define DCM_DISABLE_RX_TX_NM 0x07u
#endif

#ifndef DCM_ENABLE_RX_TX_NORM_NM
#define DCM_ENABLE_RX_TX_NORM_NM 0x08u
#endif

#ifndef DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM 0x09u
#endif

#ifndef DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM 0x0Au
#endif

#ifndef DCM_DISABLE_RX_TX_NORM_NM
#define DCM_DISABLE_RX_TX_NORM_NM 0x0Bu
#endif

/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 *
 *Service has to finish the filling of data into current page with in these many call of service.
*/
#define DCM_PRV_PAGEBUFFER_TIMEIN_CYCLES ((DCM_PAGEDBUFFER_TIMEOUT)/(DCM_CFG_TASK_TIME_US))


/* *******************************************************************************************************************/

#if((DCM_ROE_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF))


/* ROE or RDPI types */
#define DCM_PRV_DSLD_TYPE1      0x01u
#define DCM_PRV_DSLD_TYPE2      0x02u



#endif



#if(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF)


/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Protocol's RDPI TYPE2 TX information array.
 */


#endif
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * protocol structure :This structure will contain all the protocol related information.\n
 * Dcm_MsgType  tx_buffer_pa;                        Tx buffer address \n
 * Dcm_MsgType  rx_buffer_pa;                        Rx buffer address \n
 * const Dcm_ProtocolExtendedInfo_type * roe_info_pcs;   Ptr to ROE info structure \n
 * const Dcm_ProtocolExtendedInfo_type * rdpi_info_pcs;        Ptr to RDPI info structure \n
 * Dcm_MsgLenType tx_buffer_size_u32;                Tx buffer size \n
 * Dcm_MsgLenType rx_buffer_size_u32;              Rx buffer size \n
 * uint8  protocolid_u8;                           Protocol id\n
 * uint8  sid_tableid_u8;                           Id of distributor table\n
 * uint8  premption_level_u8;                        Preemption level\n
 * uint8  pduinfo_idx_u8;                           Index to the RAM Pduinfo structure\n
 * uint8  timings_limit_idx_u8;                     Index to KWP default timing structure unused variable for UDS\n
 * uint8  timings_idx_u8;                            Index to KWP default timing structure unused variable for UDS\n
 * boolean Endianness_ConvEnabled_b;                  Endianness Conversion enabled ro disabled for this protocol\n
 * uint8 Config_Mask;                                 Configuration mask to indicate the availability of protocol in different configsets\n
 * boolean nrc21_b;                                  React with NRC-21 if this protocol is received and rejected during pre-emption assertion\n
 * boolean sendRespPendTransToBoot;                  Resp Pend on Transit to Boot enabled or disabled for this protocol
*/

/* FC_VariationPoint_START */
                    /*Obsolete*/
#ifndef     DCM_FUNCTIONAL_REQUEST
#define     DCM_FUNCTIONAL_REQUEST      DCM_PRV_FUNCTIONAL_REQUEST
#endif
#ifndef     DCM_PHYSICAL_REQUEST
#define     DCM_PHYSICAL_REQUEST        DCM_PRV_PHYSICAL_REQUEST
#endif
#ifndef     DCM_MAXNUM_OF_CONFIG
#define     DCM_MAXNUM_OF_CONFIG        DCM_PRV_MAXNUM_OF_CONFIG
#endif
#ifndef     DCM_PAGEBUFFER_TIMEIN_CYCLES
#define     DCM_PAGEBUFFER_TIMEIN_CYCLES DCM_PRV_PAGEBUFFER_TIMEIN_CYCLES
#endif
#ifndef     DCM_DSLD_TYPE1
#define     DCM_DSLD_TYPE1              DCM_PRV_DSLD_TYPE1
#endif
#ifndef     DCM_DSLD_TYPE2
#define     DCM_DSLD_TYPE2              DCM_PRV_DSLD_TYPE2
#endif
/* FC_VariationPoint_END */

/*
 ***************************************************************************************************
 *    Variables prototypes
 ***************************************************************************************************
 */
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF )
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * GLobal variable which will hold the current active configuration
 */
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint8 Dcm_ActiveConfiguration_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Global variable which will hold the current active diagnostic state
 */
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_Dsld_activediagnostic_ten Dcm_ActiveDiagnosticState_en;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * final structre of DSL-DSD
 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
extern const Dcm_Dsld_confType Dcm_Dsld_Conf_cs;
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF )
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const Dcm_ConfigType * Dcm_ActiveConfigSet_Ptr;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CONST_8/*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const uint8 Dcm_Dsld_KWPsupported_sessions_acu8[];
#define DCM_STOP_SEC_CONST_8/*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CONST_UNSPECIFIED/*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const Dcm_Dsld_KwpTimerServerType Dcm_Dsld_default_timings_acs[];
extern const Dcm_Dsld_KwpTimerServerType Dcm_Dsld_Limit_timings_acs[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED/*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif


/*
 ***************************************************************************************************
 *    Function prototypes (APIs of DCM)
 ***************************************************************************************************
 */


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
extern void Dcm_OBDProcessingDone(const Dcm_MsgContextType* pMsgContext);
#endif

#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 * Dcm_Prv_ResponseOnOneEvent : Function called by the ROE service whenever the event occurred.
 *                          This function is not reentrant function and it not called in other than
 *                          Dcm_MainFunction() task.
 *
 * @param[in]                Dcm_MsgType MsgPtr :    Pointer to buffer which containing the request
 * @param[in]                Dcm_MsgLenType MsgLen : Length of the request
 * @param[in]                PduIdType DcmRxPduId  : Rx pduid on which ROE request is received.
 *
 * @retval                   DCM_E_OK: ResponseOnOneEvent request is accepted by DCM ,
 *                           DCM_E_ROE_NOT_ACCEPTED: ResponseOnOneEvent request is not accepted by DCM
 */
extern Dcm_StatusType Dcm_Prv_ResponseOnOneEvent( const Dcm_MsgType MsgPtr,
                                                      Dcm_MsgLenType MsgLen,
                                                      uint16 TesterSrcAddr);
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_RoeSendFinalResponse_u8 :This API will be called by the application to transmit the Final response
 *                           when the window timer expires in application.
 * @param [in]    Dcm_MsgType MsgPtr    :  Pointer to buffer which containg the response.
 * @param [in]    Dcm_MsgLenType MsgLen : Length of the response.
 * @param [in]    PduIdType DcmRxPduId  :Rx pduid on which ROE request is received
 * @retval        Std_ReturnType
 */
extern Std_ReturnType Dcm_RoeSendFinalResponse ( const Dcm_MsgType MsgPtr,
                                                                Dcm_MsgLenType MsgLen,
                                                                PduIdType DcmRxPduId);
#endif
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_StartPagedProcessing : With this API, the application gives the complete response length to DCM
 *                          and starts PagedBuffer handling. Complete response length information
 *                          (in bytes) is given in pMsgContext-> resDataLen Callback functions are used
 *                          to provide paged buffer handling in DSP and RTE. More information can be found
 *                          in the sequence chart in chapter 9.3.6 Process Service Request with PagedBuffer.
 *
 * @param[in]       pMsgContext: message context table given by the service.
 * @retval          None
 */
extern void Dcm_StartPagedProcessing (const Dcm_MsgContextType * pMsgContext);
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_ProcessPage: Application requests transmission of filled page More information can be found
 *                  in the sequence chart in chapter 9.3.6 Process Service Request with PagedBuffer.
 * @param[in]       FilledPageLen  : Filled data length in current page.
 * @retval          None
 */
extern void Dcm_ProcessPage(Dcm_MsgLenType FilledPageLen );
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_RestartP3timer : Function called by Kline TP to restart P3 timer after getting the first
 *                      byte of request
 * @param           None
 * @retval          None
 */
extern void Dcm_RestartP3timer(void);
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_GetKwpTimingValues : API to get the different set of timings
 * @param           TimerMode (in): Mode of timing
 *                  TimerServerCurrent (out) : Pointer to structure where timings are written by DCM
 * @retval          None
 */
extern void Dcm_GetKwpTimingValues(
                                     Dcm_TimerModeType TimerMode,
                                     Dcm_Dsld_KwpTimerServerType * TimerServerCurrent
                                                 );
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_PrepareKwpTimingValues : API to validate the given set of timings
 * @param[in]       TimerServerNew (in): Pointer to structure which timings to be validated.
 *
 * @retval          DCM_E_OK: preparation successful,
 *                  DCM_E_TI_PREPARE_LIMITS: requested values are not within the defined limits
 */
extern Dcm_StatusType Dcm_PrepareKwpTimingValues(
                                        const Dcm_Dsld_KwpTimerServerType * TimerServerNew
                                                               );
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_SetKwpTimingValues : API to Set the given set of timings.
 * @param           None
 *
 * @retval          None
 */
extern void Dcm_SetKwpTimingValues (void);
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_SetKwpDefaultTimingValues : API to Set the default timings
 * @param           None
 * @retval          None
 */
extern void Dcm_SetKwpDefaultTimingValues(void);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_SetP3MaxMonitoring : Function called by service to enable the P3 monitoring.
 *
 * @param[in]              active  TRUE  : P3 monitoring required.
 *                                 FALSE : P3 monitoring not required.
 * @retval                 None
 */
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern void Dcm_SetP3MaxMonitoring (boolean active);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define Dcm_SetS3MaxMonitoring Dcm_SetP3MaxMonitoring
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_GetActiveServiceTable : API to get the service table id
 * @param[out]      ActiveServiceTable: Address of global variable Passed by the appl.
 * @retval          None
 */
extern void Dcm_GetActiveServiceTable (uint8 * ActiveServiceTable);

/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_GetActiveProtocolRxBufferSize : API to get the Active protocol RX buffer size.
 *
 * @param[out]      rxBufferLength : Address of global variable in which the buffer size should be written.
 * @retval          E_OK           : RX buffer size read sucessfully
 *                  E_NOT_OK       : RX Buffer size not read, possibly because of no active protocol
 */

extern Std_ReturnType Dcm_GetActiveProtocolRxBufferSize
                            (Dcm_MsgLenType * const rxBufferLength);

/**
 * @ingroup DCMCORE_DSLDSD_EXTENDED
 * Dcm_Dsld_ForceRespPend : API used to trigger wait pend response by the Service.
 * @param           None
 * @retval          Std_ReturnType :E_NOT_OK/E_OK
 */



#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)
/**
 @ingroup DCMCORE_DSLDSD_AUTOSAR
 * Dcm_GetMediumOfActiveConnection: API to get Medium information(ie.Can,Flexray..etc) available in the ComMChannel for the active connection.
 *                                  This is explicitly provided only for rba_DiagAdapt.This should be called by only rba_DiagAdapt when a new protocol request is triggered from the Tester.

 * @param[out]           ActiveMediumId  : Variable Passed by the rba_DiagAdapt to get active Medium information of ComMChannel for the active connection.
 *
 *
 *@retval                E_OK

 */

extern Std_ReturnType Dcm_GetMediumOfActiveConnection(Dcm_DslDsd_MediumType_ten * const ActiveMediumId);
#endif
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/*
 ***************************************************************************************************
 *    Function prototypes                                                                          */
/**************************************************************************************************/



#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
extern const Dcm_ConfigType Dcm_Config[DCM_PRV_MAXNUM_OF_CONFIG];
#endif
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#ifndef CHECK_APICONSISTENCY
/**
* @ingroup DCMCORE_DSLDSD_AUTOSAR
*  Dcm_TriggerOnEvent: The call to this function allows to trigger an event linked to a ResponseOnEvent request.
*  On the function call, the DCM will execute the associated service. This function
*  shall be called only if the associated event has been activated through a xxx_ActivateEvent() call.
*
*  @param [in]                   : RoeEventId
*  @retval                       : E_OK
*/
/* MR12 RULE 8.5 VIOLATION:This is required for providing Dcm_TriggerOnEvent declaration to rba_DiagAdapt RTE AR4.0 enabled configuration */
extern Std_ReturnType Dcm_TriggerOnEvent( uint8 RoeEventId );



extern Std_ReturnType Dcm_GetActiveProtocol(Dcm_ProtocolType * ActiveProtocol, uint16 * ConnectionId, uint16 * TesterSourceAddress);
/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 * Dcm_GetSecurityLevel : API to get the active session id
 * @param[in]           :SesCtrlType: Address of global variable Passed by the appl.
 * @retval              : E_OK
 */
extern Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType * SesCtrlType);
/**
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 * Dcm_GetSecurityLevel : API to get the active security level
 * @param[in]           :SecLevel: Address of global variable Passed by the appl.
 * @retval              :E_OK
 */
extern Std_ReturnType Dcm_GetSecurityLevel(Dcm_SecLevelType * SecLevel);
/**
* @ingroup DCMCORE_DSLDSD_AUTOSAR
*  Dcm_ResetToDefaultSession: The call to this function allows the application to reset the current session to
*  Default Session.
*  @param                   : None
*  @retval                  : E_OK - The request for resetting the session to default session is accepted.The session transition will be processed in the next Dcm main function
*                             E_NOT_OK - If Dcm is not free and processing some other request.The application has to call the service again in this case to Reset the session to Default
*/
/* MR12 RULE 8.5 VIOLATION:This is required for providing Dcm_ResetToDefaultSession declaration to rba_DiagAdapt RTE AR4.0 enabled configuration */
extern Std_ReturnType Dcm_ResetToDefaultSession(void);
#endif

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_Dsld_ComMChannel Dcm_active_commode_e[DCM_NUM_COMM_CHANNEL];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* Const Array for storing ComM channels configured in DCM.The same will be used for initialising  Dcm_active_commode_e[]*/
extern  const uint8 Dcm_Dsld_ComMChannelId_acu8[DCM_NUM_COMM_CHANNEL];
#define DCM_STOP_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif   /* _DCMCORE_DSLDSD_PUB_H  */
