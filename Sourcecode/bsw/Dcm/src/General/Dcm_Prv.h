
#ifndef DCM_PRV_H
#define DCM_PRV_H

/*
 * ********************************************************************************************************************
 * Included header files
 **********************************************************************************************************************
*/
#include "Dcm_Prv_Types.h"
#include "Dcm_Prv_General.h"
#include "Dcm_Prv_Dsl.h"
#include "Dcm_Prv_Dsl_Inline.h"
#include "Dcm_Prv_Dsd.h"
#include "Dcm_Prv_Dsd_Inline.h"
#include "Dcm_Prv_Dsl_Authentication.h"
#include "DcmDspUds_Prv_Authentication.h"
#include "PduR_Dcm.h"
#include "DcmDspUds_Prv_Rc.h"

#include "rba_BswSrv.h"
#include "Dcm_Cfg_SchM.h"

/*
 ***************************************************************************************************
 * Protected Includes (package wide includes)
 ***************************************************************************************************
 */



#if((DCM_ROE_ENABLED != DCM_CFG_OFF)||(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF))
#include "DcmDspUds_Roe_Priv.h"
#include "DcmDspUds_Roe_Inf.h"
#endif

#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Uds_Prot.h"

#if((DCM_CFG_DSP_REQUESTUPLOAD_ENABLED != DCM_CFG_OFF)||(DCM_CFG_DSP_REQUESTTRANSFEREXIT_ENABLED != DCM_CFG_OFF))
#include "DcmDspUds_Memaddress_Calc_Prot.h"
#endif

#if(DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Seca_Prv.h"
#endif

#if(DCM_CFG_DSP_ECURESET_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Er_Prot.h"
#endif

#if(DCM_CFG_DSP_READDTCINFORMATION_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Rdtc_Priv.h"
#endif
#if(DCM_CFG_DSP_READDATABYPERIODICIDENTIFIER_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Rdpi_Prot.h"
#endif
#if(DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Rdbi_Prot.h"
#endif
#if(DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Iocbi_Prot.h"
#endif

#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Dsc_Prot.h"
#endif

#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_ECURESET_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Er_Prot.h"
#endif

#if((DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED != DCM_CFG_OFF))
#include "DcmDspUds_Cdtcs_Prot.h"
#endif

#if (DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_CC_Prot.h"
#endif

#endif
/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
*/
/* Macros to handle the Time Monitoring */
#define DCM_TimerStop(timer)            ((timer)=0xFFFFFFFFu)

#define DCM_TimerElapsed(timer)         ((timer)==0u)

#define DCM_TimerStopped(timer)         ((timer)==0xFFFFFFFFu)


/* OS Timer usage for Timer handling */
#if ( DCM_CFG_OSTIMER_USE != FALSE )
/* BSWEXT-533 */
#define DCM_TimerStart(timer,time,starttime,timerStatus) do                      /*Do while, to remove MISRA Warning 3458*/ \
                                            { \
                                            (timerStatus = Dcm_GetCounterValue(DCM_CFG_COUNTERID, (&(starttime)))); \
                                            SchM_Enter_Dcm_DsldTimer();\
                                            if( timerStatus == E_OK ) \
                                            { \
                                                ((timer) = (time)); \
                                            } \
                                            else \
                                            { \
                                                ((timer) = ((time) / DCM_CFG_TASK_TIME_US)); \
                                            } \
                                            SchM_Exit_Dcm_DsldTimer();\
                                            }while(0);

#define DCM_TimerProcess(timer,starttime,timerStatus)   do                    /*Do while, to remove MISRA Warning 3458*/ \
                                            { \
                                            if ( timerStatus == E_OK ) \
                                            { \
                                                timerStatus = Dcm_GetCounterValue(DCM_CFG_COUNTERID, (&Dcm_CurrTick_u32)); \
                                                SchM_Enter_Dcm_DsldTimer();\
                                                if ( timerStatus == E_OK ) \
                                                { \
                                                    if ( (DCM_CFG_TICKS2US_COUNTER(Dcm_CurrTick_u32 - (starttime))) >= (timer) ) \
                                                    { \
                                                        ((timer) = 0u); \
                                                    } \
                                                } \
                                                else \
                                                { \
                                                    /* This else part is added for future use */ \
                                                } \
                                                SchM_Exit_Dcm_DsldTimer();\
                                            } \
                                            else  \
                                            { \
                                                SchM_Enter_Dcm_DsldTimer();\
                                                if( ((timer)!=0u) && ((timer)!=0xFFFFFFFFu) ) \
                                                { \
                                                    (timer)--; \
                                                } \
                                                SchM_Exit_Dcm_DsldTimer();\
                                            } \
                                            }while(0);
/* This Macro used to set the new timing value of running timer */
/* Eg: After sending the response new value of P2 and P3 max is set */
/* Setting new P3 time is done in Dsp_DcmTxconfirm() function, before that */
/* old P3 max is set to the monitoring variable. from this Macro new time is set */
#define DCM_TimerSetNew(timer,time)   SchM_Enter_Dcm_DsldTimer();\
                                    if((timer)!=0u)           \
                                    {                         \
                                        (timer) = (time);     \
                                    }\
                                      SchM_Exit_Dcm_DsldTimer();


#else
/* Usage of Raster timer for timer monitoring */
#define DCM_TimerStart(timer,time,unused,timerStatus)  ((void)(timerStatus));\
                                                       SchM_Enter_Dcm_DsldTimer();\
                                                      ((timer) = (uint32)((time) / DCM_CFG_TASK_TIME_US));\
                                                      SchM_Exit_Dcm_DsldTimer();
#define DCM_TimerProcess(timer,unused,timerStatus)          \
                                            do                       /*Do while, to remove MISRA Warning 3458*/ \
                                            {   \
                                                ((void)(timerStatus));\
                                                SchM_Enter_Dcm_DsldTimer();\
                                            if( ((timer)!=0u) && ((timer)!=0xFFFFFFFFuL) ) \
                                            { \
                                                (timer)--; \
                                            } \
                                            SchM_Exit_Dcm_DsldTimer();\
                                            }\
                                            while(0);

/* This Macro used to set the new timing value of running timer */
/* Eg: After sending the response new value of P2 and P3 max is set */
/* Setting new P3 time is done in Dsp_DcmTxconfirm() function, before that */
/* old P3 max is set to the monitoring variable. from this Macro new time is set */
#define DCM_TimerSetNew(timer,time)        SchM_Enter_Dcm_DsldTimer();\
                                            ((timer) = ((time) / DCM_CFG_TASK_TIME_US));\
                                            SchM_Exit_Dcm_DsldTimer();
#endif
/* END BSWEXT-533 */

/* **********************************************************************************************************************
 * Typedefs
 **********************************************************************************************************************
 */


#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
extern Dcm_DsldTimingsType_tst Dcm_DsldTimer_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#if (DCM_CFG_OSTIMER_USE != FALSE)
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_P2OrS3StartTick_u32;
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
extern uint32 Dcm_OBDP2OrS3StartTick_u32;
#endif
extern uint32 Dcm_CurrTick_u32;
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
extern uint32 Dcm_PagedBufferStartTick_u32;    /* Starting tick value for paged buffer timer */
#endif

#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if ((DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF))
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_SysPrevTick_u32;   /* Previous tick value */
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_SysCurrTick_u32;   /* Current tick value */
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif
#endif

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
extern uint32 Dcm_TimerStartTick_u32;          /* Starting tick value for Roe timer */
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
#endif


/* FC_VariationPoint_START */
#if(DCM_CFG_RXPDU_SHARING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /* Adding this for memory mapping */
#include "Dcm_MemMap.h"
extern boolean Dcm_isObdRequestReceived_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /* Adding this for memory mapping */
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
extern boolean Dcm_acceptRequests_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
extern uint8 Dcm_tempMetaData_NRC21_u8[4];
extern uint8 Dcm_tempMetaData_u8[4];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
#if(DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
extern uint8 Dcm_tempOBDMetaData_NRC21_u8[4];
extern uint8 Dcm_tempOBDMetaData_u8[4];
#endif
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"


/*######################################  from DslDSD_Prot.h ###############################*/
/*
 ***************************************************************************************************
 *    Internal  definitions
 ***************************************************************************************************
 */
/* Endianness conversion for UINT16/SINT16 data */


#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern StatusType Dcm_P2OrS3TimerStatus_uchr; /* global variable to get the return value of GetCounterValue for Timer related funtions*/
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern StatusType Dcm_OBDP2OrS3TimerStatus_uchr;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_ProgConditionsType Dcm_ProgConditions_st;

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_BootLoaderStates_ten Dcm_BootLoaderState_en;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

/*
 ***************************************************************************************************
 *    Function prototypes (APIs of DCM which is used only in DSP)
 ***************************************************************************************************
 */

/* Location of default session ID in session array table */
#define DCM_DEFAULT_SESSION_IDX                        0x00u

/* Parallel Tpr  bytes */
#define DCM_DSLD_PARALLEL_TPR_BYTE1                    0x3eu
#define DCM_DSLD_PARALLEL_TPR_BYTE2                    0x80u
#define DCM_DSLD_PARALLEL_DCM_TPR_REQ_LENGTH           0x02u

/* NRC for wait pend negative response */
#define DCM_E_REQUESTCORRECTLYRECEIVED_RESPONSEPENDING 0x78u


/* Macro to check running protocol is KLINE type  */
/* If KLINE is disabled this macro returns FALSE  */
#if( DCM_CFG_KLINE_ENABLED != DCM_CFG_OFF )
    #define DCM_IS_KLINEPROT_ACTIVE() \
    (((Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].protocolid_u8) == DCM_CARB_ON_KLINE)\
/* FC_VariationPoint_START */\
    ||((Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].protocolid_u8) == DCM_OBD_ON_KLINE)\
/* FC_VariationPoint_END */\
    ||((Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].protocolid_u8) == DCM_KWP_ON_KLINE))
#else
#define DCM_IS_KLINEPROT_ACTIVE()    FALSE
#endif
/* Macro to check whether the ComM is in full communication mode for Drive and boot software */

#define DCM_CHKFULLCOMM_MODE(idx)  (Dcm_active_commode_e[idx].ComMState == DCM_DSLD_FULL_COM_MODE)

/* Macro to check whether the ComM is not in No communication mode for Drive and boot software */

#define DCM_CHKNOCOMM_MODE(idx) (Dcm_active_commode_e[idx].ComMState != DCM_DSLD_NO_COM_MODE)

#define DCM_PROTOCOL_ENDIANNESS (Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].Endianness_ConvEnabled_b)

/*
 ***************************************************************************************************
 *    Internal DCM Type definitions
 ***************************************************************************************************
 */






#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
/**
 * @ingroup DCMDSP_UDS_EXTENDED
 * ROE structure for logging the info related to the postponement of the ROE event .\n
 * Member elements/n
  * uint8  EventId_u8;
   * boolean Is_EventTrigerred;
*/

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const Dcm_Dsld_RoeRxToTestSrcMappingType Dcm_Dsld_RoeRxToTestSrcMappingTable[DCM_CFG_TOTAL_RX_PDUID];
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_DcmDspEventWaitlist_t Dcm_DcmDspEventQueue [DCM_MAX_SETUPROEEVENTS];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint8 DcmRoeQueueIndex_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif


/*
***************************************************************************************************
*    Variables prototypes
***************************************************************************************************
*/

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint8 Dcm_DslWaitPendBuffer_au8[8];
extern uint8 Dcm_CurProtocol_u8;
extern Dcm_SesCtrlType Dcm_CC_ActiveSession_u8;

#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const Dcm_Dsld_protocol_tableType * Dcm_DsldProtocol_pcst;
extern const uint8 * Dcm_DsldRxTable_pcu8;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

extern Dcm_DslRxPduArray_tst Dcm_DslRxPduArray_ast[DCM_CFG_TOTAL_RX_PDUID];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern boolean Dcm_isFuncTPOnOtherConnection_b;
extern boolean Dcm_isCancelTransmitInvoked_b;
extern boolean Dcm_isStopProtocolInvoked_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#if (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern boolean Dcm_ReadyForBoot_b;
extern boolean Dcm_SesChgOnWarmResp_b;

#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_DsldInternalStructureType_tst Dcm_DsldGlobal_st;

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern boolean Dcm_isGeneralRejectSent_b;

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
extern boolean Dcm_isFirstReponseSent_b;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern PduInfoType Dcm_DsldPduInfo_st ;

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const Dcm_Dsld_ServiceType * Dcm_DsldSrvTable_pcst;

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_MsgContextType Dcm_DsldMsgContext_st;

#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern const uint8 * Dcm_DsldSessionTable_pcu8;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_DsdStatesType_ten Dcm_DsdRoe2State_en;
extern Dcm_MsgContextType Dcm_Roe2MesContext_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
extern uint32 datRoeType2Timeout_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
#endif

#if(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_MsgContextType Dcm_Rdpi2MesContext_st;
extern Dcm_DsdResponseType_ten Dcm_Rdpi2ResponseType_en;
extern PduInfoType Dcm_DsldRdpi2pduinfo_ast[DCM_CFG_NUM_RDPITYPE2_TXPDU];
extern const Dcm_ProtocolExtendedInfo_type * Dcm_DsldRdpi2_pcst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if (DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_Dsld_KwpTimerServerType Dcm_DsldKwpReqTiming_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED/*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if (DCM_CFG_OSTIMER_USE != FALSE)
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_P2OrS3StartTick_u32;
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
extern uint32 Dcm_OBDP2OrS3StartTick_u32;
#endif
extern uint32 Dcm_CurrTick_u32;
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
extern uint32 Dcm_PagedBufferStartTick_u32;     /* Starting tick value for paged buffer timer */
#endif
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if ((DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF))
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_SysPrevTick_u32;   /* Previous tick value */
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_SysCurrTick_u32;   /* Current tick value */
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif
#endif

#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
extern uint32 dataTimerTimeout_u32;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern StatusType Dcm_PagedBufferTimerStatus_uchr; /* global variable to get the return value of GetCounterValue for Timer related funtions*/
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if((DCM_ROE_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF))
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern StatusType Dcm_CounterValueTimerStatus_uchr; /* global variable to get the return value of GetCounterValue for Timer related funtions*/
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern StatusType Dcm_RoeType2TimerStatus_uchr ; /* global variable to get the return value of GetCounterValue for Timer related funtions*/
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_INIT_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern boolean Dcm_LowPrioReject_b;
#define DCM_STOP_SEC_VAR_INIT_BOOLEAN
#include "Dcm_MemMap.h"

#if((DCM_CFG_DSPOBDSUPPORT_ENABLED!= DCM_CFG_OFF)&&(DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)&&\
    (DCM_CFG_INFOTYPE_SUPPORT != DCM_CFG_OFF))

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED  /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

extern boolean Dcm_SupportInfotype_b;

#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

/*
 ***************************************************************************************************
 *    Function prototypes
 ***************************************************************************************************
*/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


/************************DSL STATE MACHINE*****************************************************************************/
#if((DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF) && (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF))
#define DCM_NUMBER_OF_DSL_STATES                  (0x08u)
#elif((DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_OFF) && (DCM_PAGEDBUFFER_ENABLED == DCM_CFG_OFF))
#define DCM_NUMBER_OF_DSL_STATES                  (0x06u)
#elif((DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_OFF) || (DCM_PAGEDBUFFER_ENABLED == DCM_CFG_OFF))
#define DCM_NUMBER_OF_DSL_STATES                  (0x07u)
#endif


#define DSL_STATE_IDLE                            (0x00u)
#define DSL_STATE_WAITING_FOR_RXINDICATION        (0x01u)
#define DSL_STATE_REQUEST_RECEIVED                (0x02u)
#define DSL_STATE_RESPONSE_TRANSMISSION           (0x03u)
#define DSL_STATE_WAITING_FOR_TXCONFIRMATION      (0x04u)
#if((DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF) && (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF))
#define DSL_STATE_PROTOCOL_PREEMPTION             (0x05u)
#define DSL_STATE_PAGEDBUFFER_TRANSMISSION        (0x06u)
#define DSL_STATE_ROETYPE1_RECEIVED               (0x07u)
#elif((DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_OFF) && (DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF))
#define DSL_STATE_PAGEDBUFFER_TRANSMISSION        (0x05u)
#define DSL_STATE_ROETYPE1_RECEIVED               (0x06u)
#elif((DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF) && (DCM_PAGEDBUFFER_ENABLED == DCM_CFG_OFF))
#define DSL_STATE_PROTOCOL_PREEMPTION             (0x05u)
#define DSL_STATE_ROETYPE1_RECEIVED               (0x06u)
#elif((DCM_CFG_PROTOCOL_PREMPTION_ENABLED == DCM_CFG_OFF) && (DCM_PAGEDBUFFER_ENABLED == DCM_CFG_OFF))
#define DSL_STATE_ROETYPE1_RECEIVED               (0x05u)
#endif


#define DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING      (0x00u)
#define DSL_SUBSTATE_S3_OR_P3_TIMEOUT             (0x01u)
#define DSL_SUBSTATE_STOP_PROTOCOL                (0x02u)
#define DSL_SUBSTATE_STOP_PROTOCOL_RECEIVING      (0x03u)
#define DSL_SUBSTATE_STOP_ROE                     (0x04u)
#define DSL_SUBSTATE_START_PROTOCOL               (0x05u)
#define DSL_SUBSTATE_P2MAX_TIMEMONITORING         (0x06u)
#define DSL_SUBSTATE_SEND_PENDING_RESPONSE        (0x07u)
#define DSL_SUBSTATE_SEND_GENERAL_REJECT          (0x08u)
#define DSL_SUBSTATE_SEND_FINAL_RESPONSE          (0x09u)
#define DSL_SUBSTATE_DATA_READY                   (0x0Au)
#define DSL_SUBSTATE_WAIT_FOR_DATA                (0x0Bu)
#define DSL_SUBSTATE_WAIT_PAGE_TXCONFIRM          (0x0Cu)

extern void Dcm_Prv_DslStateMachine(void);


/**********************************************************************************************************************/


#if ( ( DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF ) && ( DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED != DCM_CFG_OFF ) )
extern void Dcm_Prv_CC_Mainfunction (void);
#endif
extern void Dcm_Prv_CC_TxConfirmation (void);

extern void Dcm_DslDsdRestoreSecaTimer(void);
extern Dcm_MsgItemType * Dcm_GetActiveBuffer(void);





#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
extern void Dcm_Prv_PagedBufferTimeout(void);
#endif

#if(DCM_ROE_ENABLED != DCM_CFG_OFF)
extern void Dcm_DsldRoeTimeOut(void);
extern void Dcm_Prv_ROEResetOnConfirmation(void);
#endif

#if((DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF) || (RBA_DCMPMA_CFG_PLANTMODEACTIVATION_ENABLED !=  DCM_CFG_OFF))
Std_ReturnType Dcm_Prv_CancelTransmit(void);
#endif

#if (DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF )
extern void Dcm_DsldResetRDPI(void);
#endif

#if((DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF) && (DCM_ROE_ENABLED != DCM_CFG_OFF))

extern BufReq_ReturnType Dcm_DsldPersistentRoeHandling_en(PduLengthType nrTpSduLength_u16, PduIdType DcmRxPduId);
#endif

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#if((DCM_CFG_DSPOBDSUPPORT_ENABLED!= DCM_CFG_OFF)&&(DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)&&\
    (DCM_CFG_INFOTYPE_SUPPORT != DCM_CFG_OFF))

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
void Dcm_Prv_SupportInfoTypecheck(void);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

/****************************************************************************************************
*        APPLICATION API DECLARATIONS
****************************************************************************************************/

#if(DCM_CFG_RDPI_ENABLED!=DCM_CFG_OFF)



#if(DCM_CFG_MAX_DID_SCHEDULER>0)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_PeriodicInfoType_tst Dcm_PeriodicInfo_st[DCM_CFG_MAX_DID_SCHEDULER];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint8 Dcm_NumOfActivePeriodicId_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if (DCM_ROE_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern void Dcm_DsldProcessRoeQueue(void);
#if(DCM_CFG_DSP_ROEONDTCSTATUSCHANGE_ENABLED != DCM_CFG_OFF)
extern void Dcm_RestoreROEDtcEvents(void);
#endif
#if(DCM_CFG_DSP_ROEDID_ENABLED!=DCM_CFG_OFF)
extern void Dcm_RestoreROEDidEvents(void);
#endif
extern void Dcm_ResetROEEvents(void);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif




/*###################################### end DslDSD_Prot.h ###############################*/

#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isProtocolPreemptionInitiated
 Syntax           : Dcm_Prv_isProtocolPreemptionInitiated(void)
 Description      : This function is used to check whether high priority protocol request is received
 Parameter        : None
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isProtocolPreemptionInitiated(void)
{
    Dcm_DslProtocolPreemptionStatesType_ten preemptionState;
    preemptionState=Dcm_Dsl_Prv_GetPreemptionState();
    return ((DSL_PREEMPTION_STOP_LOWPRIORITYPROTOCOL_E == Dcm_Dsl_Prv_GetPreemptionState()) || \
            (DSL_PREEMPTION_STOP_ROE_E == preemptionState ));
}
#endif









#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
extern boolean Dcm_BootSeqComplete_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"



#endif

