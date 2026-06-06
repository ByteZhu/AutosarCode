


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

#if !defined(COM_PBCFG_COMMON_H)
#define COM_PBCFG_COMMON_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#define COM_UPDATE_MAX      COM_MAX_U16_VALUE   /* max ipdu size */



/* In all the variants */
# define COM_NUM_OF_TXIPDU_IN_ALL_VARIANTS              14u
# define COM_NUM_OF_RXIPDU_IN_ALL_VARIANTS              38u

# define COM_NUM_OF_TXSIG_IN_ALL_VARIANTS               116u
# define COM_NUM_OF_RXSIG_IN_ALL_VARIANTS               269u

# define COM_NUM_OF_TXSIGGRP_IN_ALL_VARIANTS            0u
# define COM_NUM_OF_RXSIGGRP_IN_ALL_VARIANTS            0u

# define COM_NUM_OF_TXGRPSIG_IN_ALL_VARIANTS            0u
# define COM_NUM_OF_RXGRPSIG_IN_ALL_VARIANTS            0u

# define COM_NUM_OF_IPDUGRP_IN_ALL_VARIANTS             6u

# define COM_NUM_OF_TXIPDUGRP_IN_ALL_VARIANTS           3u
# define COM_NUM_OF_RXIPDUGRP_IN_ALL_VARIANTS           3u

# define COM_NUM_OF_TX_SIG_GRPSIG_IN_ALL_VARIANTS       (COM_NUM_OF_TXSIG_IN_ALL_VARIANTS + COM_NUM_OF_TXGRPSIG_IN_ALL_VARIANTS)
# define COM_NUM_OF_RX_SIG_GRPSIG_IN_ALL_VARIANTS       (COM_NUM_OF_RXSIG_IN_ALL_VARIANTS + COM_NUM_OF_RXGRPSIG_IN_ALL_VARIANTS)

/* max in any of the variant */
# define COM_MAX_NUM_OF_TXIPDU_IN_ANY_VARIANT           14u
# define COM_MAX_NUM_OF_RXIPDU_IN_ANY_VARIANT           38u

# define COM_MAX_NUM_OF_TXSIG_IN_ANY_VARIANT            116u
# define COM_MAX_NUM_OF_RXSIG_IN_ANY_VARIANT            269u

# define COM_MAX_NUM_OF_TXSIGGRP_IN_ANY_VARIANT         1u
# define COM_MAX_NUM_OF_RXSIGGRP_IN_ANY_VARIANT         1u

# define COM_MAX_NUM_OF_TXGRPSIG_IN_ANY_VARIANT         1u
# define COM_MAX_NUM_OF_RXGRPSIG_IN_ANY_VARIANT         1u




/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/


/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#ifdef COM_TP_IPDUTYPE
/* Used to store PduLength of the Tx-Ipdu just befor PduR_ComTransmit() is called. */
extern PduLengthType                                        Com_TpTxIpduLength_auo[];
#endif /* #ifdef COM_TP_IPDUTYPE */

#ifdef COM_RX_SIGNALGROUP
/* Array of Rx Signal group flags */
extern Com_RxSignalGrpFlagType_tst                          Com_RxSignalGrpFlag_ast[];
#endif /* #ifdef COM_RX_SIGNALGROUP */

#ifdef COM_TX_SIGNALGROUP
#if defined(COM_EffectiveSigGrpTOC) || defined(COM_SIGNALGROUPGATEWAY)

/* Array of Tx Signal group flags */
extern Com_TxSignalGrpFlagType_tst                          Com_TxSignalGrpFlag_ast[];
#endif /* #if defined(COM_EffectiveSigGrpTOC) || defined(COM_SIGNALGROUPGATEWAY) */

/* Array of Tx  group Signal flags */
extern Com_TxGrpSignalFlagType_tst                          Com_TxGrpSignalFlag_ast[];
#endif /* #ifdef COM_TX_SIGNALGROUP */

/* Array of Rx Ipdu Ram flags */
extern Com_RxIpduRamData_tst                                Com_RxIpduRam_ast[];

/* Array of Tx Ipdu Ram flags */
extern Com_TxIpduRamData_tst                                Com_TxIpduRam_ast[];

/* Array of Tx signal flags */
extern Com_TxSignalFlagType_tst                             Com_TxSignalFlag_ast[];

/* Array of Rx signal flags */
extern Com_RxSignalFlagType_tst                             Com_RxSignalFlag_ast[];

/* Gw Rx Ipdu queue */
extern PduIdType                                            Com_RxGwQueue_auo[];

/* Structure for Gw Rx queue */
extern Com_RxGwQueueRAMType_tst                             Com_RxGwQueue_st;


#ifdef COM_F_ONEEVERYN
extern Com_OneEveryN_tst                                    Com_OneEveryN_ast[];
#endif

#if defined(COM_EffectiveSigTOC) || defined(COM_EffectiveSigGrpTOC)
extern Com_OldValTrigOnChng_tauo                            Com_OldValTrigOnChng_auo[];
#endif


/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"


#ifdef COM_F_MASKEDNEWDIFFERSOLD

/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
extern uint32 Com_F_OldVal_au32[];

/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
#endif



/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
extern Com_IpduGroupIdType     Com_IPduGroupStatus_au16[];

#if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout)
extern Com_IpduGroupIdType     Com_IPduGrpDMStatus_au16[];
#endif /* #if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout) */

/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"



/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Counter for every Ipdu which gives number of Started Ipdu groups, this Ipdu is part of. */
extern uint8 Com_IpduCounter_au8[];

#if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout)
/* Counter for every Ipdu which gives number of Deadline monitoring enbaled Rx Ipdu groups, this Ipdu is part of. */
extern uint8 Com_IpduCounter_DM_au8[];
#endif /* #if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout) */

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"


/* START: I-PDU Buffers */

    /* Tx-Ipdu Local Buffers */

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_CCP_Response_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_EPS_DebugMessage_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_NM_VCU_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PscmChas1Fr01_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PscmChas1Fr02_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PscmChas1Fr03_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PscmChas1Fr06_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PscmChas1Fr07_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PscmDevelpFr_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_TestResponse_Can_Network_0_Channel_CAN_TxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
    /* Rx-Ipdu Local Buffers */

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_CCP_Request_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_EcmChas1Fr08_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_PasChas1Fr02_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_SasChas1Fr01_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_TestRequest_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VcuChas1Fr06_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr01_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr03_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr04_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr05_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr10_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr14_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr19_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr22_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr24_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr30_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr33_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr41_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr44_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr46_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr47_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr48_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr49_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr50_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr53_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr54_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_VddmChas1Fr55_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_dIP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_RxByte[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* END: I-PDU Buffers */

#ifdef COM_PRV_ENABLECONFIGINTERFACES

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_CCP_Req_Data_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpADMod_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpCtrlSts_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpDegraded_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpQf_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkpSts_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADL3FuncCtrlStsForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqForBkpADActiveReq_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqForBkpADDeactiveReq_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyADModeReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatCoDrvReqForBkpAsyLatCoDrvR_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatCoDrvReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatCoDrvReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatCoDrvReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatCoDrvReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqForBkpAsyPinionAgR_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyPinionAgReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatOvrdReqForBkpAsyLatOvrdReq_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatOvrdReqForBkpChks8_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatOvrdReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatOvrdReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyLatOvrdReqForBkp_UB_Can_Network_1_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SAS_RequestData_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_NM_EIRA_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_FaultStatus_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_checksum_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_counter_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_current1_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_current2_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_current3_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_current4_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_current5_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_sensor1_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_sensor2_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x4F_sensor3_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x2F_checksum_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x2F_command_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x2F_counter_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_test_0x2F_current_Can_Network_2_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest0_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest2_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest3_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest4_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest5_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest6_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TestModeRequest7_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerSetgPen_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_DrvModReq_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ULoWarnChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_EscStChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_EscStCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_EscStEscSt_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_EscSt_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehMtnStChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_CarTiGlb_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ProfPenSts1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehBattUSysU_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehBattU_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_Prv_RxSigS_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx_u8;

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
#endif /* end of COM_PRV_ENABLECONFIGINTERFACES */



/*Start: Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern uint8 Com_SigTypeCom_MainFunctionRx_ComMainFunctionRx_au8[];

/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
/*End: Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/
/*Start: Signal Buffer -----> uint16/sint16*/

/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
extern uint16 Com_SigTypeCom_MainFunctionRx_ComMainFunctionRx_au16[];

/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
/*End: Signal Buffer -----> uint16/sint16*/
/*Start: Signal Buffer -----> uint32/sint32*/

/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
extern uint32 Com_SigTypeCom_MainFunctionRx_ComMainFunctionRx_au32[];

/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
/*End: Signal Buffer -----> uint32/sint32*/
#ifdef COM_RXSIG_INT64
/*Start: Signal Buffer -----> uint64/sint64*/

/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_64
#include "Com_MemMap.h"
extern uint64 Com_SigTypeCom_MainFunctionRx_ComMainFunctionRx_au64[];

/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_64
#include "Com_MemMap.h"
/*End: Signal Buffer -----> uint64/sint64*/
#endif







#if defined (COM_TXSIG_INT64 ) || defined(COM_RXSIG_INT64) || defined(COM_TXGRPSIG_INT64) || defined(COM_RXGRPSIG_INT64)

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_64
#include "Com_MemMap.h"

extern const uint64 Com_Int64SigValues_acu64[];

/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_64
#include "Com_MemMap.h"
#endif


/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"


#if defined (COM_TXSIG_FLOAT64SUPP ) || defined(COM_TXGRPSIG_FLOAT64SUPP) || defined(COM_RXGRPSIG_FLOAT64SUPP) || defined(COM_RXSIG_FLOAT64SUPP)
extern const float64 Com_Float64SigValues_acf64[];
#endif

extern const Com_ByteArraySig_tst Com_ByteArraySigValues_acst[];

/* Set of Rx-buffers generated for each ComMainFunction */
extern const Com_Prv_xRxRamBuf_tst                          Com_Prv_xRxRamBuf_acst[];

#ifdef COM_TX_SIGNALGROUP

/* Set of Tx-GroupSignal shadow buffers generated for each ComMainFunction */
extern const Com_Prv_xTxSigGrpRamBuf_tst                    Com_Prv_xTxSigGrpRamBuf_acst[];
#endif /* #ifdef COM_TX_SIGNALGROUP */


/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"



#ifdef COM_INITVALOPTIMIZATION

/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_32
#include "Com_MemMap.h"

extern const uint32                                         Com_Prv_UniqueInitVal_acu32[];


/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_32
#include "Com_MemMap.h"
#endif /* end of #ifdef COM_INITVALOPTIMIZATION */





#endif   /* end of COM_PBCFG_COMMON_H */


