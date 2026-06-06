#ifndef BSWM_CFG_LE_H
#define BSWM_CFG_LE_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"

#include "Stubs.h"

#include "Rte_Main.h"

#include "Fee.h"

#include "EcuM_User.h"

#include "CDD_TPS653852A.h"

#include "CanSM_ComM.h"

#include "CanIf.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */

/******************************     BswM Logical Expression    *****************************************/

#define BSWMLOGEXP_BSWM_LE_APPREQUESTSHUTDOWN  \
                                         ( ( RTE_MODE_MDG_App_Mode_SWC_REQUEST_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].dataMode_u16 )  \
                                         && ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_POST_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_APPRUN  \
                                         ( ( CANSM_BSWM_FULL_COMMUNICATION  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].dataMode_en )  \
                                         && ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_APP_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_CH0_COMCONTROLDISABLED  \
                                        ( CANSM_BSWM_NO_COMMUNICATION  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_CH0_COMCONTROLENABLED  \
                                        ( CANSM_BSWM_FULL_COMMUNICATION  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_NM  \
                                        ( DCM_DISABLE_RX_TX_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NM  \
                                        ( DCM_DISABLE_RX_ENABLE_TX_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM  \
                                        ( DCM_DISABLE_RX_ENABLE_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM  \
                                        ( DCM_DISABLE_RX_ENABLE_TX_NORM_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_TX_NORM  \
                                        ( DCM_DISABLE_RX_TX_NORMAL  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_TX_NORM_NM  \
                                        ( DCM_DISABLE_RX_TX_NORM_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_NM  \
                                        ( DCM_ENABLE_RX_TX_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NM  \
                                        ( DCM_ENABLE_RX_DISABLE_TX_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM  \
                                        ( DCM_ENABLE_RX_DISABLE_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM  \
                                        ( DCM_ENABLE_RX_DISABLE_TX_NORM_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_TX_NORM  \
                                        ( DCM_ENABLE_RX_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_TX_NORM_NM  \
                                        ( DCM_ENABLE_RX_TX_NORM_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_NETWORKRELEASE  \
                                        ( RTE_MODE_ComMMode_COMM_NO_COMMUNICATION  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_NETWORKREQUEST  \
                                        ( RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_NOWAKEUPSOURCES  \
                                         ( ( ECUM_WKSTATUS_PENDING  !=  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_KL15].dataState )  \
                                         && ( ECUM_WKSTATUS_PENDING  !=  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_CANMSG].dataState ) )

#define BSWMLOGEXP_BSWM_LE_NVMREADALLCOMPLETEOREXPIRED  \
                                        ( NVM_REQ_PENDING  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMREADALLCOMPLETE].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_NVMWRITEALLCOMPLETEOREXPIRED  \
                                        ( NVM_REQ_PENDING  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMWRITEALLCOMPLETE].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_PNC29_NOCOM  \
                                        ( COMM_PNC_NO_COMMUNICATION  ==  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_PNC29_PREPARESLEEP  \
                                        ( COMM_PNC_PREPARE_SLEEP  ==  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_PNC29_READYSLEEP  \
                                        ( COMM_PNC_READY_SLEEP  ==  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_PNC29_REQUESTED  \
                                        ( COMM_PNC_REQUESTED  ==  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].dataMode_en )

#define BSWMLOGEXP_BSWM_LE_POSTRUN2RUN  \
                                         ( ( CANSM_BSWM_FULL_COMMUNICATION  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].dataMode_en )  \
                                         && ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_PREPSHUTDOWN  \
                                         ( ( CANSM_BSWM_NO_COMMUNICATION  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].dataMode_en )  \
                                         && ( RTE_MODE_MDG_App_Mode_SWC_REQUEST_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].dataMode_u16 )  \
                     && BSWMLOGEXP_BSWM_LE_NOWAKEUPSOURCES  \
                                         && ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_RUN  \
                                        ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_RUN2POSTRUN  \
                                         ( ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )  \
                                         && ( CANSM_BSWM_NO_COMMUNICATION  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].dataMode_en )  \
                     && BSWMLOGEXP_BSWM_LE_NOWAKEUPSOURCES )

#define BSWMLOGEXP_BSWM_LE_RUN_WAKEUP_CANMSG  \
                                         ( ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )  \
                                         && ( ECUM_WKSTATUS_VALIDATED  ==  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_CANMSG].dataState ) )

#define BSWMLOGEXP_BSWM_LE_RUN_WAKEUP_KL15  \
                                         ( ( ECUM_WKSTATUS_VALIDATED  ==  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_KL15].dataState )  \
                                         && ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_SHUTDOWN  \
                                         ( ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )  \
                     && BSWMLOGEXP_BSWM_LE_NVMWRITEALLCOMPLETEOREXPIRED )

#define BSWMLOGEXP_BSWM_LE_STARTUPONE  \
                                        ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_ONE  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_STARTUPTWO  \
                                         ( ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )  \
                                         && ( NVM_REQ_PENDING  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMREADALLCOMPLETE].dataMode_en ) )

#define BSWMLOGEXP_BSWM_LE_TIMEREXPIREDORSTOPPED  \
                                         ( ( BSWM_TIMER_EXPIRED  ==  BswM_Cfg_BswMTimerInfo_ast[BSWM_IDX_BSWM_MRP_TIMER].dataMode_en )  \
                                         || ( BSWM_TIMER_STOPPED  ==  BswM_Cfg_BswMTimerInfo_ast[BSWM_IDX_BSWM_MRP_TIMER].dataMode_en ) )

/******************   Macros for checking whether the ModeValues are defined   ******************************/

#define BSWMMODEVALUE_BSWM_LE_APPREQUESTSHUTDOWN  \
                                      ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_APPRUN  \
                                      ( ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_CH0_COMCONTROLDISABLED  \
                                      ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_CH0_COMCONTROLENABLED  \
                                      ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_TX_NORM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_TX_NORM_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_TX_NORM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_TX_NORM_NM  \
                                      ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_NETWORKRELEASE  \
                                      ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_NETWORKREQUEST  \
                                      ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_NOWAKEUPSOURCES  \
                                      ( ( FALSE  !=  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_KL15].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_CANMSG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_NVMREADALLCOMPLETEOREXPIRED  \
                                      ( FALSE  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMREADALLCOMPLETE].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_NVMWRITEALLCOMPLETEOREXPIRED  \
                                      ( FALSE  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMWRITEALLCOMPLETE].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_PNC29_NOCOM  \
                                      ( FALSE  !=  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_PNC29_PREPARESLEEP  \
                                      ( FALSE  !=  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_PNC29_READYSLEEP  \
                                      ( FALSE  !=  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_PNC29_REQUESTED  \
                                      ( FALSE  !=  BswM_Cfg_ComMPncRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_COMM_PNC29].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_POSTRUN2RUN  \
                                      ( ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_PREPSHUTDOWN  \
                                      ( ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].isValidModePresent_b )  \
         && BSWMMODEVALUE_BSWM_LE_NOWAKEUPSOURCES  \
                                       && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_RUN  \
                                      ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_RUN2POSTRUN  \
                                      ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEINDICATION].isValidModePresent_b )  \
         && BSWMMODEVALUE_BSWM_LE_NOWAKEUPSOURCES )

#define BSWMMODEVALUE_BSWM_LE_RUN_WAKEUP_CANMSG  \
                                      ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_CANMSG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_RUN_WAKEUP_KL15  \
                                      ( ( FALSE  !=  BswM_Cfg_EcuMWkpSrcInfo_ast[BSWM_IDX_BSWM_MRP_WKSOURCE_KL15].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_SHUTDOWN  \
                                      ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )  \
         && BSWMMODEVALUE_BSWM_LE_NVMWRITEALLCOMPLETEOREXPIRED )

#define BSWMMODEVALUE_BSWM_LE_STARTUPONE  \
                                      ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_STARTUPTWO  \
                                      ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMREADALLCOMPLETE].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_TIMEREXPIREDORSTOPPED  \
                                      ( ( FALSE  !=  BswM_Cfg_BswMTimerInfo_ast[BSWM_IDX_BSWM_MRP_TIMER].isValidModePresent_b )  \
                                       && ( FALSE  !=  BswM_Cfg_BswMTimerInfo_ast[BSWM_IDX_BSWM_MRP_TIMER].isValidModePresent_b ) )

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */

/********************************  LogicalExpressionEvaluateFunctions  ***************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern void BswM_Cfg_LE_BswM_LE_AppRequestShutdown(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_AppRun(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_CH0_ComControlDisabled(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_CH0_ComControlEnabled(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_NM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM_NM(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_NetworkRelease(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_NetworkRequest(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_NoWakeupSources(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_NvMReadAllCompleteOrExpired(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_NvMWriteAllCompleteOrExpired(
		boolean *isValidMode_pb, boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_PNC29_NoCom(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_PNC29_PrepareSleep(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_PNC29_ReadySleep(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_PNC29_Requested(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_PostRun2Run(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_PrepShutdown(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_Run(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_Run2PostRun(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_Run_Wakeup_CanMsg(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_Run_Wakeup_KL15(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_Shutdown(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_StartupOne(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_StartupTwo(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);
extern void BswM_Cfg_LE_BswM_LE_TimerExpiredOrStopped(boolean *isValidMode_pb,
		boolean *hasLogExpRes_pb);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#endif  /* BSWM_CFG_LE_H */
/**********************************************************************************************************************
 * End of header file
 **********************************************************************************************************************/
