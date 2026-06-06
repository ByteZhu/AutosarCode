



/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: CanIf / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 * 
 

 </VersionHead>*/


/******************************************************************************/
/*                                  Include Section                                */
/******************************************************************************/
/* CanIf Private header */
#include "CanIf_Prv.h"



/*
 ******************************************************************************
 * Variables
 ******************************************************************************
 */









/*======================================================================================================================
 *                                VARIANT:  PRE_COMPILE
 *======================================================================================================================
*/







/*====================================================================================================================*/
/*
 *                                  CANIF CONTROLLER CONFIG STRUCTURE             
 *                                     
 * Structure contains following members:
 *{
 *#if(CANIF_PUBLIC_TXBUFFERING ==STD_ON) 
 *  (0) BufferIdPtr,
 *  (1) TotalBufferCount,
 *  (2) TxPduIdPtr,
 *  (3) TotalTxPduCount,
 *#endif
 *  (4) CtrlId,
 *  (5) CtrlCanCtrlRef,
 *  (6) CtrlWakeupSupport,
 *#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
 *  (7) PnCtrlEn            
 *#endif
 * #if CANIF_CFG_PUBLIC_MULTIPLE_DRIVER_SUPPORT == STD_ON
 * CanDrvIndx
 * #endif
 *}
*/


#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"

static const CanIf_Cfg_CtrlConfig_tst CanIf_CtrlGen_a[]=
{

/*0:Can_Network_CANNODE_0 */
{ /*(4)*/0,   /*(5)*/CanConf_CanController_Can_Network_CANNODE_0,   /*(6)*/FALSE  , /*(7)*/ FALSE   }
,
/*1:Can_Network_CANNODE_1 */
{ /*(4)*/1,   /*(5)*/CanConf_CanController_Can_Network_CANNODE_1,   /*(6)*/FALSE  , /*(7)*/ FALSE   }
,
/*2:Can_Network_CANNODE_2 */
{ /*(4)*/2,   /*(5)*/CanConf_CanController_Can_Network_CANNODE_2,   /*(6)*/FALSE  , /*(7)*/ FALSE   }
};





#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"



#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"


static const CanIf_Cfg_HthConfig_tst CanIf_HthGen_a[]=
{
/*,  *CanIf_CtrlConfigPtr,  CanObjectId,   CanHandleType */

/*0:Can_Network_CANNODE_0_Tx_Std_MailBox_1*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_1 }

,
/*1:Can_Network_CANNODE_0_Tx_Std_MailBox_10*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_10 }

,
/*2:Can_Network_CANNODE_0_Tx_Std_MailBox_11*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_11 }

,
/*3:Can_Network_CANNODE_0_Tx_Std_MailBox_12*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_12 }

,
/*4:Can_Network_CANNODE_0_Tx_Std_MailBox_13*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_13 }

,
/*5:Can_Network_CANNODE_0_Tx_Std_MailBox_14*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_14 }

,
/*6:Can_Network_CANNODE_0_Tx_Std_MailBox_15*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_15 }

,
/*7:Can_Network_CANNODE_0_Tx_Std_MailBox_16*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_16 }

,
/*8:Can_Network_CANNODE_0_Tx_Std_MailBox_2*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_2 }

,
/*9:Can_Network_CANNODE_0_Tx_Std_MailBox_3*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_3 }

,
/*10:Can_Network_CANNODE_0_Tx_Std_MailBox_4*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_4 }

,
/*11:Can_Network_CANNODE_0_Tx_Std_MailBox_5*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_5 }

,
/*12:Can_Network_CANNODE_0_Tx_Std_MailBox_6*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_6 }

,
/*13:Can_Network_CANNODE_0_Tx_Std_MailBox_7*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_7 }

,
/*14:Can_Network_CANNODE_0_Tx_Std_MailBox_8*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_8 }

,
/*15:Can_Network_CANNODE_0_Tx_Std_MailBox_9*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_0],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_0_Tx_Std_MailBox_9 }

,
/*16:Can_Network_CANNODE_1_Tx_Std_MailBox_1*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_1],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_1_Tx_Std_MailBox_1 }

,
/*17:Can_Network_CANNODE_2_Tx_Std_MailBox_1*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_2],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_2_Tx_Std_MailBox_1 }

,
/*18:Can_Network_CANNODE_2_Tx_Std_MailBox_2*/
{/*(0)*/ &CanIf_CtrlGen_a[CanIf_Ctrl_CustId_Can_Network_CANNODE_2],/*(1)*/ Can_17_McmCanConf_CanHardwareObject_Can_Network_CANNODE_2_Tx_Std_MailBox_2 }



};


#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"




/*                                  CANIF TXBUFFER CONFIG STRUCTURE       

 * Structure contains following members:
 *{
 * (0)*CanIf_HthConfigPtr
 *#if (CANIF_PUBLIC_TXBUFFERING == STD_ON)
 * (1)DataBuf
 * (2)CanIdBuf
 * (3)CanIfBufferId;
 * (4)CanIfBufferSize
 * (5)CanIfBufferMaxDataLength 
 *#endif
 *}
 */     

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
                                            
static const CanIf_Cfg_TxBufferConfig_tst CanIf_TxBufferGen_a[]=
{

/*0:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_1*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_1]}
,
/*1:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_10*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_10]}
,
/*2:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_11*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_11]}
,
/*3:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_12*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_12]}
,
/*4:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_13*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_13]}
,
/*5:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_14*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_14]}
,
/*6:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_15*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_15]}
,
/*7:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_16*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_16]}
,
/*8:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_2*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_2]}
,
/*9:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_3*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_3]}
,
/*10:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_4*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_4]}
,
/*11:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_5*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_5]}
,
/*12:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_6*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_6]}
,
/*13:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_7*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_7]}
,
/*14:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_8*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_8]}
,
/*15:Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_9*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_0_Tx_Std_MailBox_9]}
,
/*16:Bu_Can_Network_CANNODE_1_Tx_Std_MailBox_1*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_1_Tx_Std_MailBox_1]}
,
/*17:Bu_Can_Network_CANNODE_2_Tx_Std_MailBox_1*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_2_Tx_Std_MailBox_1]}
,
/*18:Bu_Can_Network_CANNODE_2_Tx_Std_MailBox_2*/
{/*(0)*/&CanIf_HthGen_a[CanIf_Hth_CustId_Can_Network_CANNODE_2_Tx_Std_MailBox_2]}
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"




/*                                  CANIF TXPDU CONFIG STRUCTURE       
 * Structure contains following members:
 *{
 * (0)*CanIf_TxBufferConfigPt
 *#if(CANIF_METADATA_SUPPORT == STD_ON)
 * (1)TxPduCanIdMask
 * (2)MetaDataLength          
 *#endif
 * (3)TxPduId
 * (4)TxPduTargetPduId       
 * (5)TxPduType                
 * (6)TxPduCanIdType
 * (7)TxPduTxUserUL
 * (8)Function pointer to TxPduTxUserULName
 * (9)TxPduCanId
 *
 *#if(CANIF_RB_NODE_CALIBRATION == STD_ON)
 *(10) getTxPduCanId
 *#endif
 *
 *#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
 * (11)TxPduPnFilterPdu
 *#endif
 *
 *#if (CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON)
 * (12)TxPduReadNotifyStatus
 *#endif
 *
 *#if(CANIF_TRIGGERTRANSMIT_SUPPORT== STD_ON)
 * (13)Function pointer to UserTriggerTransmitName
 * (14)TxPduTriggerTransmit
 *#endif
 *
 *#if(CANIF_RB_NODE_CALIBRATION == STD_ON)
 *(15)getTxPduDlc
 *#endif
 *
 *(16)TxTruncEnabled
 *(17)TxPduLength
 *}
 */  

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
                              

static const CanIf_Cfg_TxPduConfig_tst CanIf_TxPduGen_a[]=
{

/*0:CCP_Response_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_9],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_CCP_Response_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 0 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x202  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*1:Diag_Physical_response_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_2],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_Diag_Physical_response_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ CanTpConf_CanTpTxNPdu_Diag_Physical_response_Can_Network_CANNODE_0_Phys_CanTp2CanIf , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/CAN_TP,      /*UserTxConfirmation*/&CanTp_TxConfirmation, /*TxPduCanId*/ 0x670  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*2:EPS_AngleCalibrateResponse_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_7],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_EPS_AngleCalibrateResponse_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 1 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x71A  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*3:EPS_DebugMessage_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_8],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_EPS_DebugMessage_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 2 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x7FE  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*4:NM_VCU_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_1],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_NM_VCU_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 0 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/CAN_NM,      /*UserTxConfirmation*/&CanNm_TxConfirmation, /*TxPduCanId*/ 0x523  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*5:PSCBHIPBCanFD7Frame01_Can_Network_CANNODE_1_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_1_Tx_Std_MailBox_1],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PSCBHIPBCanFD7Frame01_Can_Network_CANNODE_1_OUT, /*TxPduTargetPduId*/ 3 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_FD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x11  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/64u}
,
/*6:PSCMTxCommonInfo_0x4A_Can_Network_CANNODE_2_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_2_Tx_Std_MailBox_1],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PSCMTxCommonInfo_0x4A_Can_Network_CANNODE_2_OUT, /*TxPduTargetPduId*/ 4 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_FD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x4A  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/64u}
,
/*7:PSCMTxCurrentAndCommand_0x2A_Can_Network_CANNODE_2_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_2_Tx_Std_MailBox_2],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PSCMTxCurrentAndCommand_0x2A_Can_Network_CANNODE_2_OUT, /*TxPduTargetPduId*/ 5 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_FD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x2A  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/64u}
,
/*8:PscmChas1Fr01_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_14],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PscmChas1Fr01_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 6 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0xF6  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*9:PscmChas1Fr02_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_12],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PscmChas1Fr02_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 7 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x46  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*10:PscmChas1Fr03_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_15],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PscmChas1Fr03_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 8 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x1BC  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*11:PscmChas1Fr06_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_16],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PscmChas1Fr06_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 9 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x3BB  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*12:PscmChas1Fr07_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_11],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PscmChas1Fr07_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 10 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x4E  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*13:PscmDevelpFr_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_13],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_PscmDevelpFr_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 11 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x596  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*14:TestResponse_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_10],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_TestResponse_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 12 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/PDUR,      /*UserTxConfirmation*/&PduR_CanIfTxConfirmation, /*TxPduCanId*/ 0x2  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*15:XCP_TX_DAQ0_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_3],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_XCP_TX_DAQ0_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 1 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/XCP,      /*UserTxConfirmation*/&Xcp_CanIfTxConfirmation, /*TxPduCanId*/ 0x778  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*16:XCP_TX_DAQ1_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_4],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_XCP_TX_DAQ1_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 2 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/XCP,      /*UserTxConfirmation*/&Xcp_CanIfTxConfirmation, /*TxPduCanId*/ 0x779  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*17:XCP_TX_DAQ2_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_5],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_XCP_TX_DAQ2_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 3 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/XCP,      /*UserTxConfirmation*/&Xcp_CanIfTxConfirmation, /*TxPduCanId*/ 0x77A  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
,
/*18:XCP_TX_RES_Can_Network_CANNODE_0_OUT*/

{ /*CanIf_TxBufferConfigPtr*/&CanIf_TxBufferGen_a[CanIf_Buffer_CustId_Bu_Can_Network_CANNODE_0_Tx_Std_MailBox_6],    /*TxPduId*/CanIfConf_CanIfTxPduCfg_XCP_TX_RES_Can_Network_CANNODE_0_OUT, /*TxPduTargetPduId*/ 0 , 
/*TxPduType*/CANIF_STATIC, /*TxPduCanIdType*/STANDARD_CAN,   /*TxPduTxUserUL*/XCP,      /*UserTxConfirmation*/&Xcp_CanIfTxConfirmation, /*TxPduCanId*/ 0x777  , /*TxPduPnFilterPdu*/FALSE          , /*TxPduReadNotifyStatus*/ FALSE    ,/*TxTruncEnabled*/ TRUE ,/*TxPduLength*/8u}
};


#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
/*=====================================================================================================================
 *=====================================================================================================================
 *=====================================================================================================================
 */











#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"

static const CanIf_Cfg_Hrhtype_tst CanIf_Prv_HrhConfig_tacst[42] =
{
          /*HrhInfo_e,    PduIdx_t,  NumRxPdus_u32,  HrhRangeMask_b,  ControllerId_u8 , CanId_t*/
    
/*0: Can_Network_CANNODE_0_Rx_Std_MailBox_1*/
    {CANIF_PRV_FULL_E,       0u,             1u,            FALSE,           0u    ,   2047u       },
/*1: Can_Network_CANNODE_0_Rx_Std_MailBox_2*/
    {CANIF_PRV_BASIC_RANGE_E,       0u,             1u,            FALSE,           0u    , 0xFFFFFFFFu       },
/*2: Can_Network_CANNODE_0_Rx_Std_MailBox_3*/
    {CANIF_PRV_FULL_E,       2u,             1u,            FALSE,           0u    ,   1904u       },
/*3: Can_Network_CANNODE_0_Rx_Std_MailBox_4*/
    {CANIF_PRV_FULL_E,       3u,             1u,            FALSE,           0u    ,   818u       },
/*4: Can_Network_CANNODE_0_Rx_Std_MailBox_5*/
    {CANIF_PRV_FULL_E,       4u,             1u,            FALSE,           0u    ,   819u       },
/*5: Can_Network_CANNODE_0_Rx_Std_MailBox_6*/
    {CANIF_PRV_FULL_E,       5u,             1u,            FALSE,           0u    ,   512u       },
/*6: Can_Network_CANNODE_0_Rx_Std_MailBox_7*/
    {CANIF_PRV_FULL_E,       6u,             1u,            FALSE,           0u    ,   1914u       },
/*7: Can_Network_CANNODE_0_Rx_Std_MailBox_8*/
    {CANIF_PRV_FULL_E,       7u,             1u,            FALSE,           0u    ,   1u       },
/*8: Can_Network_CANNODE_0_Rx_Std_MailBox_9*/
    {CANIF_PRV_FULL_E,       8u,             1u,            FALSE,           0u    ,   1431u       },
/*9: Can_Network_CANNODE_0_Rx_Std_MailBox_10*/
    {CANIF_PRV_FULL_E,       9u,             1u,            FALSE,           0u    ,   1111u       },
/*10: Can_Network_CANNODE_0_Rx_Std_MailBox_11*/
    {CANIF_PRV_FULL_E,       10u,             1u,            FALSE,           0u    ,   496u       },
/*11: Can_Network_CANNODE_0_Rx_Std_MailBox_12*/
    {CANIF_PRV_FULL_E,       11u,             1u,            FALSE,           0u    ,   1267u       },
/*12: Can_Network_CANNODE_0_Rx_Std_MailBox_13*/
    {CANIF_PRV_FULL_E,       12u,             1u,            FALSE,           0u    ,   51u       },
/*13: Can_Network_CANNODE_0_Rx_Std_MailBox_14*/
    {CANIF_PRV_FULL_E,       13u,             1u,            FALSE,           0u    ,   592u       },
/*14: Can_Network_CANNODE_0_Rx_Std_MailBox_15*/
    {CANIF_PRV_FULL_E,       14u,             1u,            FALSE,           0u    ,   342u       },
/*15: Can_Network_CANNODE_0_Rx_Std_MailBox_16*/
    {CANIF_PRV_FULL_E,       15u,             1u,            FALSE,           0u    ,   81u       },
/*16: Can_Network_CANNODE_0_Rx_Std_MailBox_17*/
    {CANIF_PRV_FULL_E,       16u,             1u,            FALSE,           0u    ,   400u       },
/*17: Can_Network_CANNODE_0_Rx_Std_MailBox_18*/
    {CANIF_PRV_FULL_E,       17u,             1u,            FALSE,           0u    ,   26u       },
/*18: Can_Network_CANNODE_0_Rx_Std_MailBox_19*/
    {CANIF_PRV_FULL_E,       18u,             1u,            FALSE,           0u    ,   736u       },
/*19: Can_Network_CANNODE_0_Rx_Std_MailBox_20*/
    {CANIF_PRV_FULL_E,       19u,             1u,            FALSE,           0u    ,   147u       },
/*20: Can_Network_CANNODE_0_Rx_Std_MailBox_21*/
    {CANIF_PRV_FULL_E,       20u,             1u,            FALSE,           0u    ,   686u       },
/*21: Can_Network_CANNODE_0_Rx_Std_MailBox_22*/
    {CANIF_PRV_FULL_E,       21u,             1u,            FALSE,           0u    ,   580u       },
/*22: Can_Network_CANNODE_0_Rx_Std_MailBox_23*/
    {CANIF_PRV_FULL_E,       22u,             1u,            FALSE,           0u    ,   235u       },
/*23: Can_Network_CANNODE_0_Rx_Std_MailBox_24*/
    {CANIF_PRV_FULL_E,       23u,             1u,            FALSE,           0u    ,   137u       },
/*24: Can_Network_CANNODE_0_Rx_Std_MailBox_25*/
    {CANIF_PRV_FULL_E,       24u,             1u,            FALSE,           0u    ,   433u       },
/*25: Can_Network_CANNODE_0_Rx_Std_MailBox_26*/
    {CANIF_PRV_FULL_E,       25u,             1u,            FALSE,           0u    ,   432u       },
/*26: Can_Network_CANNODE_0_Rx_Std_MailBox_27*/
    {CANIF_PRV_FULL_E,       26u,             1u,            FALSE,           0u    ,   1123u       },
/*27: Can_Network_CANNODE_0_Rx_Std_MailBox_28*/
    {CANIF_PRV_FULL_E,       27u,             1u,            FALSE,           0u    ,   338u       },
/*28: Can_Network_CANNODE_0_Rx_Std_MailBox_29*/
    {CANIF_PRV_FULL_E,       28u,             1u,            FALSE,           0u    ,   864u       },
/*29: Can_Network_CANNODE_0_Rx_Std_MailBox_30*/
    {CANIF_PRV_FULL_E,       29u,             1u,            FALSE,           0u    ,   1015u       },
/*30: Can_Network_CANNODE_0_Rx_Std_MailBox_31*/
    {CANIF_PRV_FULL_E,       30u,             1u,            FALSE,           0u    ,   896u       },
/*31: Can_Network_CANNODE_0_Rx_Std_MailBox_32*/
    {CANIF_PRV_FULL_E,       31u,             1u,            FALSE,           0u    ,   64u       },
/*32: Can_Network_CANNODE_0_Rx_Std_MailBox_33*/
    {CANIF_PRV_FULL_E,       32u,             1u,            FALSE,           0u    ,   439u       },
/*33: Can_Network_CANNODE_0_Rx_Std_MailBox_34*/
    {CANIF_PRV_FULL_E,       33u,             1u,            FALSE,           0u    ,   224u       },
/*34: Can_Network_CANNODE_0_Rx_Std_MailBox_35*/
    {CANIF_PRV_FULL_E,       34u,             1u,            FALSE,           0u    ,   160u       },
/*35: Can_Network_CANNODE_0_Rx_Std_MailBox_36*/
    {CANIF_PRV_FULL_E,       35u,             1u,            FALSE,           0u    ,   91u       },
/*36: Can_Network_CANNODE_0_Rx_Std_MailBox_37*/
    {CANIF_PRV_FULL_E,       36u,             1u,            FALSE,           0u    ,   1099u       },
/*37: Can_Network_CANNODE_0_Rx_Std_MailBox_38*/
    {CANIF_PRV_FULL_E,       37u,             1u,            FALSE,           0u    ,   1159u       },
/*38: Can_Network_CANNODE_1_Rx_Std_MailBox_1*/
    {CANIF_PRV_FULL_E,       38u,             1u,            FALSE,           1u    ,   416u       },
/*39: Can_Network_CANNODE_1_Rx_Std_MailBox_2*/
    {CANIF_PRV_FULL_E,       39u,             1u,            FALSE,           1u    ,   32u       },
/*40: Can_Network_CANNODE_2_Rx_Std_MailBox_1*/
    {CANIF_PRV_FULL_E,       40u,             1u,            FALSE,           2u    ,   47u       },
/*41: Can_Network_CANNODE_2_Rx_Std_MailBox_2*/
    {CANIF_PRV_FULL_E,       41u,             1u,            FALSE,           2u    ,   79u       }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"







#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
static const CanIf_Cfg_RxPduType_tst CanIf_Prv_RxPduConfig_tacst[42]=
{   
   /*RxPduReadNotifyReadDataStatus_u8       IndexForUL_u8   CanIdtype_u8    RxPduDlc_u8      RxPduCanId      Hrhref_t    RxPduTargetId_t 	*/
    
    /*0:Diag_Functional_request_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     2u,           0x20u,            8u,         2047u,       0,         CanTpConf_CanTpRxNPdu_Diag_Functional_request_Can_Network_CANNODE_0_Phys_CanIf2CanTp            },
    /*1:NM_VCU_Rx_ETAS_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     1u,           0x20u,            8u,     0xFFFFFFFFu,       1,         0            },
    /*2:Diag_Physical_request_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     2u,           0x20u,            8u,         1904u,       2,         CanTpConf_CanTpRxNPdu_Diag_Physical_request_Can_Network_CANNODE_0_Phys_CanIf2CanTp            },
    /*3:XCP_RX_Broadcast_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     7u,           0x30u,            0u,         818u,       3,         XcpConf_XcpRxPdu_XCP_RX_Broadcast            },
    /*4:XCP_RX_CMD_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     7u,           0x30u,            0u,         819u,       4,         XcpConf_XcpRxPdu_XCP_RX_CMD            },
    /*5:CCP_Request_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         512u,       5,         PduRConf_PduRSrcPdu_CCP_Request_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*6:EPS_AngleCalibrateRequest_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1914u,       6,         PduRConf_PduRSrcPdu_EPS_AngleCalibrateRequest_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*7:TestRequest_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1u,       7,         PduRConf_PduRSrcPdu_TestRequest_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*8:EtcToPscmDevelFr_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1431u,       8,         PduRConf_PduRSrcPdu_EtcToPscmDevelFr_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*9:EcmChas1Fr08_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1111u,       9,         PduRConf_PduRSrcPdu_EcmChas1Fr08_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*10:VddmChas1Fr53_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         496u,       10,         PduRConf_PduRSrcPdu_VddmChas1Fr53_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*11:VddmChas1Fr44_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1267u,       11,         PduRConf_PduRSrcPdu_VddmChas1Fr44_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*12:AsdmChas1Fr03_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         51u,       12,         PduRConf_PduRSrcPdu_AsdmChas1Fr03_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*13:VddmChas1Fr30_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         592u,       13,         PduRConf_PduRSrcPdu_VddmChas1Fr30_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*14:VcuChas1Fr06_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         342u,       14,         PduRConf_PduRSrcPdu_VcuChas1Fr06_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*15:VddmChas1Fr01_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         81u,       15,         PduRConf_PduRSrcPdu_VddmChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*16:VddmChas1Fr04_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         400u,       16,         PduRConf_PduRSrcPdu_VddmChas1Fr04_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*17:VddmChas1Fr47_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         26u,       17,         PduRConf_PduRSrcPdu_VddmChas1Fr47_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*18:VddmChas1Fr19_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         736u,       18,         PduRConf_PduRSrcPdu_VddmChas1Fr19_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*19:AsdmChas1Fr01_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         147u,       19,         PduRConf_PduRSrcPdu_AsdmChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*20:VddmChas1Fr41_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         686u,       20,         PduRConf_PduRSrcPdu_VddmChas1Fr41_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*21:VddmChas1Fr54_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         580u,       21,         PduRConf_PduRSrcPdu_VddmChas1Fr54_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*22:PasChas1Fr02_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         235u,       22,         PduRConf_PduRSrcPdu_PasChas1Fr02_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*23:VddmChas1Fr24_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         137u,       23,         PduRConf_PduRSrcPdu_VddmChas1Fr24_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*24:VddmChas1Fr10_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         433u,       24,         PduRConf_PduRSrcPdu_VddmChas1Fr10_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*25:VddmChas1Fr14_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         432u,       25,         PduRConf_PduRSrcPdu_VddmChas1Fr14_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*26:VddmChas1Fr22_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1123u,       26,         PduRConf_PduRSrcPdu_VddmChas1Fr22_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*27:ZcudChas1Fr02_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         338u,       27,         PduRConf_PduRSrcPdu_ZcudChas1Fr02_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*28:VddmChas1Fr49_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         864u,       28,         PduRConf_PduRSrcPdu_VddmChas1Fr49_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*29:VddmChas1Fr33_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1015u,       29,         PduRConf_PduRSrcPdu_VddmChas1Fr33_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*30:VddmChas1Fr50_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         896u,       30,         PduRConf_PduRSrcPdu_VddmChas1Fr50_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*31:SasChas1Fr01_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         64u,       31,         PduRConf_PduRSrcPdu_SasChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*32:VddmChas1Fr55_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         439u,       32,         PduRConf_PduRSrcPdu_VddmChas1Fr55_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*33:VddmChas1Fr05_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         224u,       33,         PduRConf_PduRSrcPdu_VddmChas1Fr05_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*34:VddmChas1Fr03_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         160u,       34,         PduRConf_PduRSrcPdu_VddmChas1Fr03_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*35:VdcuIemChas1Fr01_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         91u,       35,         PduRConf_PduRSrcPdu_VdcuIemChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*36:VddmChas1Fr46_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1099u,       36,         PduRConf_PduRSrcPdu_VddmChas1Fr46_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*37:VddmChas1Fr48_Can_Network_CANNODE_0_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x20u,            8u,         1159u,       37,         PduRConf_PduRSrcPdu_VddmChas1Fr48_CanIf2PduR_Can_Network_0_Channel_CAN            },
    /*38:CSCHIPBHIPBCANFD7Frame03_Can_Network_CANNODE_1_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x31u,            64u,         416u,       38,         PduRConf_PduRSrcPdu_CSCHIPBHIPBCANFD7Frame03_CanIf2PduR_Can_Network_1_Channel_CAN            },
    /*39:CSCHIPBHIPBCanFD7Frame10_Can_Network_CANNODE_1_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x31u,            64u,         32u,       39,         PduRConf_PduRSrcPdu_CSCHIPBHIPBCanFD7Frame10_CanIf2PduR_Can_Network_1_Channel_CAN            },
    /*40:PSCBTxCurrentAndCommand_0x2F_Can_Network_CANNODE_2_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x31u,            64u,         47u,       40,         PduRConf_PduRSrcPdu_PSCBTxCurrentAndCommand_0x2F_CanIf2PduR_Can_Network_2_Channel_CAN            },
    /*41:PSCBTxCommonInfo_0x4F_Can_Network_CANNODE_2_IN*/
    {
        CANIF_READ_NOTIFSTATUS,     6u,           0x31u,            64u,         79u,       41,         PduRConf_PduRSrcPdu_PSCBTxCommonInfo_0x4F_CanIf2PduR_Can_Network_2_Channel_CAN            }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"







/* Configuration for Rx Pdu's of Basic(Range) type */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
static const CanIf_RxPduRangeConfigType_tst CanIf_RxPduRangeConfig_tacst[] =
{
/*0*/
/*0:Can_Network_CANNODE_0_Rx_Std_MailBox_2*/    
    {
        
        /* LowerCanId_t */    /*UpperCanId_t */     /*PduIdx_t */
         0x500,                 0x53F,                 1
    }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"










/* Tx CanIds of CANNM */

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
static const Can_IdType CanIf_CanNmTxId[] =
{
    0x523
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"











#define CANIF_START_SEC_CONST_16
#include "CanIf_MemMap.h"

/* Array for mapping Hoh Id(CanObjectId) and Hrh */
static const uint16 CanIf_CFG_HrhIdMapping_au16[] =
{/*0:Can_Network_CANNODE_0_Rx_Std_MailBox_1*/
0,
/*1:Can_Network_CANNODE_0_Rx_Std_MailBox_2*/
1,
/*2:Can_Network_CANNODE_0_Rx_Std_MailBox_3*/
2,
/*3:Can_Network_CANNODE_0_Rx_Std_MailBox_4*/
3,
/*4:Can_Network_CANNODE_0_Rx_Std_MailBox_5*/
4,
/*5:Can_Network_CANNODE_0_Rx_Std_MailBox_6*/
5,
/*6:Can_Network_CANNODE_0_Rx_Std_MailBox_7*/
6,
/*7:Can_Network_CANNODE_0_Rx_Std_MailBox_8*/
7,
/*8:Can_Network_CANNODE_0_Rx_Std_MailBox_9*/
8,
/*9:Can_Network_CANNODE_0_Rx_Std_MailBox_10*/
9,
/*10:Can_Network_CANNODE_0_Rx_Std_MailBox_11*/
10,
/*11:Can_Network_CANNODE_0_Rx_Std_MailBox_12*/
11,
/*12:Can_Network_CANNODE_0_Rx_Std_MailBox_13*/
12,
/*13:Can_Network_CANNODE_0_Rx_Std_MailBox_14*/
13,
/*14:Can_Network_CANNODE_0_Rx_Std_MailBox_15*/
14,
/*15:Can_Network_CANNODE_0_Rx_Std_MailBox_16*/
15,
/*16:Can_Network_CANNODE_0_Rx_Std_MailBox_17*/
16,
/*17:Can_Network_CANNODE_0_Rx_Std_MailBox_18*/
17,
/*18:Can_Network_CANNODE_0_Rx_Std_MailBox_19*/
18,
/*19:Can_Network_CANNODE_0_Rx_Std_MailBox_20*/
19,
/*20:Can_Network_CANNODE_0_Rx_Std_MailBox_21*/
20,
/*21:Can_Network_CANNODE_0_Rx_Std_MailBox_22*/
21,
/*22:Can_Network_CANNODE_0_Rx_Std_MailBox_23*/
22,
/*23:Can_Network_CANNODE_0_Rx_Std_MailBox_24*/
23,
/*24:Can_Network_CANNODE_0_Rx_Std_MailBox_25*/
24,
/*25:Can_Network_CANNODE_0_Rx_Std_MailBox_26*/
25,
/*26:Can_Network_CANNODE_0_Rx_Std_MailBox_27*/
26,
/*27:Can_Network_CANNODE_0_Rx_Std_MailBox_28*/
27,
/*28:Can_Network_CANNODE_0_Rx_Std_MailBox_29*/
28,
/*29:Can_Network_CANNODE_0_Rx_Std_MailBox_30*/
29,
/*30:Can_Network_CANNODE_0_Rx_Std_MailBox_31*/
30,
/*31:Can_Network_CANNODE_0_Rx_Std_MailBox_32*/
31,
/*32:Can_Network_CANNODE_0_Rx_Std_MailBox_33*/
32,
/*33:Can_Network_CANNODE_0_Rx_Std_MailBox_34*/
33,
/*34:Can_Network_CANNODE_0_Rx_Std_MailBox_35*/
34,
/*35:Can_Network_CANNODE_0_Rx_Std_MailBox_36*/
35,
/*36:Can_Network_CANNODE_0_Rx_Std_MailBox_37*/
36,
/*37:Can_Network_CANNODE_0_Rx_Std_MailBox_38*/
37,
/*38:Can_Network_CANNODE_1_Rx_Std_MailBox_1*/
38,
/*39:Can_Network_CANNODE_1_Rx_Std_MailBox_2*/
39,
/*40:Can_Network_CANNODE_2_Rx_Std_MailBox_1*/
40,
/*41:Can_Network_CANNODE_2_Rx_Std_MailBox_2*/
41,
/*42:Can_Network_CANNODE_0_Tx_Std_MailBox_1*/
CANIF_INVALID_ID,
/*43:Can_Network_CANNODE_0_Tx_Std_MailBox_2*/
CANIF_INVALID_ID,
/*44:Can_Network_CANNODE_0_Tx_Std_MailBox_3*/
CANIF_INVALID_ID,
/*45:Can_Network_CANNODE_0_Tx_Std_MailBox_4*/
CANIF_INVALID_ID,
/*46:Can_Network_CANNODE_0_Tx_Std_MailBox_5*/
CANIF_INVALID_ID,
/*47:Can_Network_CANNODE_0_Tx_Std_MailBox_6*/
CANIF_INVALID_ID,
/*48:Can_Network_CANNODE_0_Tx_Std_MailBox_7*/
CANIF_INVALID_ID,
/*49:Can_Network_CANNODE_0_Tx_Std_MailBox_8*/
CANIF_INVALID_ID,
/*50:Can_Network_CANNODE_0_Tx_Std_MailBox_9*/
CANIF_INVALID_ID,
/*51:Can_Network_CANNODE_0_Tx_Std_MailBox_10*/
CANIF_INVALID_ID,
/*52:Can_Network_CANNODE_0_Tx_Std_MailBox_11*/
CANIF_INVALID_ID,
/*53:Can_Network_CANNODE_0_Tx_Std_MailBox_12*/
CANIF_INVALID_ID,
/*54:Can_Network_CANNODE_0_Tx_Std_MailBox_13*/
CANIF_INVALID_ID,
/*55:Can_Network_CANNODE_0_Tx_Std_MailBox_14*/
CANIF_INVALID_ID,
/*56:Can_Network_CANNODE_0_Tx_Std_MailBox_15*/
CANIF_INVALID_ID,
/*57:Can_Network_CANNODE_0_Tx_Std_MailBox_16*/
CANIF_INVALID_ID,
/*58:Can_Network_CANNODE_1_Tx_Std_MailBox_1*/
CANIF_INVALID_ID,
/*59:Can_Network_CANNODE_2_Tx_Std_MailBox_1*/
CANIF_INVALID_ID,
/*60:Can_Network_CANNODE_2_Tx_Std_MailBox_2*/
CANIF_INVALID_ID};


#define CANIF_STOP_SEC_CONST_16
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONST_16
#include "CanIf_MemMap.h"

/* Array for mapping CanIfRxpduId accross the variant */
static const uint16 CanIf_CFG_RxPduIdMapping_au16[] =
{
/*0:Diag_Functional_request_Can_Network_CANNODE_0_IN*/
0,
/*1:NM_VCU_Rx_ETAS_Can_Network_CANNODE_0_IN*/
1,
/*2:Diag_Physical_request_Can_Network_CANNODE_0_IN*/
2,
/*3:XCP_RX_Broadcast_Can_Network_CANNODE_0_IN*/
3,
/*4:XCP_RX_CMD_Can_Network_CANNODE_0_IN*/
4,
/*5:CCP_Request_Can_Network_CANNODE_0_IN*/
5,
/*6:EPS_AngleCalibrateRequest_Can_Network_CANNODE_0_IN*/
6,
/*7:TestRequest_Can_Network_CANNODE_0_IN*/
7,
/*8:EtcToPscmDevelFr_Can_Network_CANNODE_0_IN*/
8,
/*9:EcmChas1Fr08_Can_Network_CANNODE_0_IN*/
9,
/*10:VddmChas1Fr53_Can_Network_CANNODE_0_IN*/
10,
/*11:VddmChas1Fr44_Can_Network_CANNODE_0_IN*/
11,
/*12:AsdmChas1Fr03_Can_Network_CANNODE_0_IN*/
12,
/*13:VddmChas1Fr30_Can_Network_CANNODE_0_IN*/
13,
/*14:VcuChas1Fr06_Can_Network_CANNODE_0_IN*/
14,
/*15:VddmChas1Fr01_Can_Network_CANNODE_0_IN*/
15,
/*16:VddmChas1Fr04_Can_Network_CANNODE_0_IN*/
16,
/*17:VddmChas1Fr47_Can_Network_CANNODE_0_IN*/
17,
/*18:VddmChas1Fr19_Can_Network_CANNODE_0_IN*/
18,
/*19:AsdmChas1Fr01_Can_Network_CANNODE_0_IN*/
19,
/*20:VddmChas1Fr41_Can_Network_CANNODE_0_IN*/
20,
/*21:VddmChas1Fr54_Can_Network_CANNODE_0_IN*/
21,
/*22:PasChas1Fr02_Can_Network_CANNODE_0_IN*/
22,
/*23:VddmChas1Fr24_Can_Network_CANNODE_0_IN*/
23,
/*24:VddmChas1Fr10_Can_Network_CANNODE_0_IN*/
24,
/*25:VddmChas1Fr14_Can_Network_CANNODE_0_IN*/
25,
/*26:VddmChas1Fr22_Can_Network_CANNODE_0_IN*/
26,
/*27:ZcudChas1Fr02_Can_Network_CANNODE_0_IN*/
27,
/*28:VddmChas1Fr49_Can_Network_CANNODE_0_IN*/
28,
/*29:VddmChas1Fr33_Can_Network_CANNODE_0_IN*/
29,
/*30:VddmChas1Fr50_Can_Network_CANNODE_0_IN*/
30,
/*31:SasChas1Fr01_Can_Network_CANNODE_0_IN*/
31,
/*32:VddmChas1Fr55_Can_Network_CANNODE_0_IN*/
32,
/*33:VddmChas1Fr05_Can_Network_CANNODE_0_IN*/
33,
/*34:VddmChas1Fr03_Can_Network_CANNODE_0_IN*/
34,
/*35:VdcuIemChas1Fr01_Can_Network_CANNODE_0_IN*/
35,
/*36:VddmChas1Fr46_Can_Network_CANNODE_0_IN*/
36,
/*37:VddmChas1Fr48_Can_Network_CANNODE_0_IN*/
37,
/*38:CSCHIPBHIPBCANFD7Frame03_Can_Network_CANNODE_1_IN*/
38,
/*39:CSCHIPBHIPBCanFD7Frame10_Can_Network_CANNODE_1_IN*/
39,
/*40:PSCBTxCurrentAndCommand_0x2F_Can_Network_CANNODE_2_IN*/
40,
/*41:PSCBTxCommonInfo_0x4F_Can_Network_CANNODE_2_IN*/
41};


#define CANIF_STOP_SEC_CONST_16
#include "CanIf_MemMap.h"










/* array of function pointer which provies Callback name to the UL*/
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
static const CanIf_RxCbk_Prototype CanIf_Prv_ULName_ta__fct[] =
{
    {NULL_PTR},
    {&CanNm_RxIndication},
    {&CanTp_RxIndication},
    {NULL_PTR},
    {NULL_PTR},
    {NULL_PTR},
    {&PduR_CanIfRxIndication},
    {&Xcp_CanIfRxIndication},
    
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"










/* CANIF callback configuration */


#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "CanIf_MemMap.h"
const CanIf_CallbackFuncType CanIf_Callback =
{
    /*2:User_ClearTrcvWufFlagIndication*/
    NULL_PTR,
    /*3:User_CheckTrcvWakeFlagIndication*/
    NULL_PTR,
    /* 4:User_ConfirmPnAvailability */
    &CanSM_ConfirmPnAvailability,
   
    /*5: User_ControllerBusOff */
    &CanSM_ControllerBusOff,
    
    /* 6:User_ControllerModeIndication */
    &CanSM_ControllerModeIndication,
    /*7:User_ControllerErrorPassive*/
    NULL_PTR
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"









/*This mapping table is generated for finding invalid TxPduIs passed via CanIf APIs in Post-Build.
 *Size of the array is total number of Tx PDUs across the variants. Each element is the index of Tx Pdu config structure.
 * If a TxPdu is not present in this variant, an invalid value 0xFFFF is generated in the particular position.
 */
 
 #define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"



static const uint16 CanIf_TxPduId_MappingTable[] = 
{
      
/*CCP_Response_Can_Network_CANNODE_0_OUT*/
0,	      
/*Diag_Physical_response_Can_Network_CANNODE_0_OUT*/
1,	      
/*EPS_AngleCalibrateResponse_Can_Network_CANNODE_0_OUT*/
2,	      
/*EPS_DebugMessage_Can_Network_CANNODE_0_OUT*/
3,	      
/*NM_VCU_Can_Network_CANNODE_0_OUT*/
4,	      
/*PSCBHIPBCanFD7Frame01_Can_Network_CANNODE_1_OUT*/
5,	      
/*PSCMTxCommonInfo_0x4A_Can_Network_CANNODE_2_OUT*/
6,	      
/*PSCMTxCurrentAndCommand_0x2A_Can_Network_CANNODE_2_OUT*/
7,	      
/*PscmChas1Fr01_Can_Network_CANNODE_0_OUT*/
8,	      
/*PscmChas1Fr02_Can_Network_CANNODE_0_OUT*/
9,	      
/*PscmChas1Fr03_Can_Network_CANNODE_0_OUT*/
10,	      
/*PscmChas1Fr06_Can_Network_CANNODE_0_OUT*/
11,	      
/*PscmChas1Fr07_Can_Network_CANNODE_0_OUT*/
12,	      
/*PscmDevelpFr_Can_Network_CANNODE_0_OUT*/
13,	      
/*TestResponse_Can_Network_CANNODE_0_OUT*/
14,	      
/*XCP_TX_DAQ0_Can_Network_CANNODE_0_OUT*/
15,	      
/*XCP_TX_DAQ1_Can_Network_CANNODE_0_OUT*/
16,	      
/*XCP_TX_DAQ2_Can_Network_CANNODE_0_OUT*/
17,	      
/*XCP_TX_RES_Can_Network_CANNODE_0_OUT*/
18 
};  







#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"


/*This mapping table is generated for finding invalid CtrlIds passed via CanIf APIs in Post-Build.
 *Size of the array is total number of controllers across the variants. Each element is the index of Controller config structure.
 * If a CtrlId is not present in this variant, an invalid value 0xFF is generated in the particular position.
 */

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"



static const uint8 CanIf_CtrlId_MappingTable[] = 
{

/*Can_Network_CANNODE_0*/
0,	
/*Can_Network_CANNODE_1*/
1,	
/*Can_Network_CANNODE_2*/
2 
};  






#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"





/*Configuration structure for __KW_COMMON*/

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "CanIf_MemMap.h"
const CanIf_ConfigType CanIf_Config =
{
    
    /* HrhConfig_pcst */
    CanIf_Prv_HrhConfig_tacst,
    /* RxPduConfig_pcst */
    CanIf_Prv_RxPduConfig_tacst,
   /* NumCanRxPduId_t */
   42u,
   /*NumCanCtrl_u8*/
   3,
   /*NumCddRxPdus_t*/
   
   0,
   
   /*RangeCfg_tpst*/
   
   CanIf_RxPduRangeConfig_tacst,
   /*RxPduIdTable_Ptr*/
   &CanIf_CFG_RxPduIdMapping_au16[0],
   /*HrhPduIdTable_Ptr*/
   &CanIf_CFG_HrhIdMapping_au16[0],
   /*CfgSetIndex_u8*/
   0,
   &CanIf_TxPduGen_a[0u],             /*CanIf_TxPduConfigPtr*/
   &CanIf_TxBufferGen_a[0u],          /*CanIf_TxBufferConfigPtr*/
   &CanIf_CtrlGen_a[0u],              /*CanIf_CtrlConfigPtr*/
   19,      /*NumOfTxPdus*/
   19,        /*NumOfTxBuffers*/  
  &CanIf_TxPduId_MappingTable[0],      /*TxPduIdTable_Ptr*/
   &CanIf_CtrlId_MappingTable[0],
   /*RxAutosarUL_Ptr*/
   &CanIf_Prv_ULName_ta__fct[0],
    CanIf_CanNmTxId
     
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "CanIf_MemMap.h"







