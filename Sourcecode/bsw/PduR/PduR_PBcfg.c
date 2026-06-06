
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: PduR  / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

#include "PduR_PBcfg.h"
#include "PduR_UpIf.h"

#include "PduR_LoIfTT.h"

#include "PduR_LoIf.h"
#include "PduR_LoTp.h"

#include "PduR_UpTp.h"

#include "PduR_Mc.h"
#include "PduR_Gw.h"

#include "PduR_Gw_Cfg.h"
/* Generating PbCfg_c::PduR_UpIfToLo_PBcfg_c::upIf_To_Lo */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFTX_LO)
#define PduR_comToLo   NULL_PTR
#else
static const PduR_RT_UpToLo PduR_comToLo[] =
		{ { CanIfConf_CanIfTxPduCfg_CCP_Response_Can_Network_CANNODE_0_OUT,
				(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
				(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*CCP_Response_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_EPS_AngleCalibrateResponse_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*EPS_AngleCalibrateResponse_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_EPS_DebugMessage_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*EPS_DebugMessage_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanNmConf_CanNmUserDataTxPdu_NM_VCU_UserData_Can_Network_Channel,
						(PduR_loTransmitFP) PduR_RF_CanNm_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*NM_VCU_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PSCBHIPBCanFD7Frame01_Can_Network_CANNODE_1_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PSCBHIPBCanFD7Frame01_Com2PduR_Can_Network_1_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PSCMTxCommonInfo_0x4A_Can_Network_CANNODE_2_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PSCMTxCommonInfo_0x4A_Com2PduR_Can_Network_2_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PSCMTxCurrentAndCommand_0x2A_Can_Network_CANNODE_2_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PSCMTxCurrentAndCommand_0x2A_Com2PduR_Can_Network_2_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PscmChas1Fr01_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PscmChas1Fr01_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PscmChas1Fr02_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PscmChas1Fr02_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PscmChas1Fr03_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PscmChas1Fr03_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PscmChas1Fr06_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PscmChas1Fr06_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PscmChas1Fr07_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PscmChas1Fr07_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_PscmDevelpFr_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit }, /*PscmDevelpFr_Com2PduR_Can_Network_0_Channel_CAN*/
				{
						CanIfConf_CanIfTxPduCfg_TestResponse_Can_Network_CANNODE_0_OUT,
						(PduR_loTransmitFP) PduR_RF_CanIf_Transmit,
						(PduR_loCancelTransmitFP) PduR_IH_CancelTransmit } /*TestResponse_Com2PduR_Can_Network_0_Channel_CAN*/

		};
#endif /* PDUR_CONFIG_SINGLE_IFTX_LO */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_UpTpToLo_PBcfg_c::upTp_To_Lo */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_TPTX_LO)
#define PduR_DcmToLo NULL_PTR
#else
static const PduR_RT_UpToLo PduR_DcmToLo[] =
		{
				{
						CanTpConf_CanTpTxNSdu_Diag_Physical_response_Can_Network_CANNODE_0_Phys_PduR2CanTp,
						(PduR_loTransmitFP) PduR_RF_CanTp_Transmit,
						(PduR_loCancelTransmitFP) PduR_RF_CanTp_CancelTransmit } /*Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN*/

		};
#endif /* PDUR_CONFIG_SINGLE_IFTX_LO */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_LoIfRxToUp_PBcfg_c::loIfRx_To_Up */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFRX)
#define PduR_CanIfRxToUp   NULL_PTR
#else
static const PduR_RT_LoIfRxToUp PduR_CanIfRxToUp[] = {

{ ComConf_ComIPdu_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*AsdmChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*AsdmChas1Fr03_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_CCP_Request_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*CCP_Request_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*CSCHIPBHIPBCANFD7Frame03_CanIf2PduR_Can_Network_1_Channel_CAN*/

{ ComConf_ComIPdu_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*CSCHIPBHIPBCanFD7Frame10_CanIf2PduR_Can_Network_1_Channel_CAN*/

{ ComConf_ComIPdu_IP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*EPS_AngleCalibrateRequest_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*EcmChas1Fr08_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*EtcToPscmDevelFr_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*PSCBTxCommonInfo_0x4F_CanIf2PduR_Can_Network_2_Channel_CAN*/

{ ComConf_ComIPdu_IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*PSCBTxCurrentAndCommand_0x2F_CanIf2PduR_Can_Network_2_Channel_CAN*/

{ ComConf_ComIPdu_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*PasChas1Fr02_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*SasChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_TestRequest_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*TestRequest_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VcuChas1Fr06_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VdcuIemChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr03_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr04_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr05_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr10_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr14_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr19_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr22_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr24_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr30_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr33_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr41_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr44_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr46_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr47_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr48_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr49_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr50_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr53_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr54_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }, /*VddmChas1Fr55_CanIf2PduR_Can_Network_0_Channel_CAN*/

{ ComConf_ComIPdu_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication } /*ZcudChas1Fr02_CanIf2PduR_Can_Network_0_Channel_CAN*/
};
#endif  /* PDUR_CONFIG_SINGLE_IFRX */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFRX)
#define PduR_CanNmRxToUp   NULL_PTR
#else
static const PduR_RT_LoIfRxToUp PduR_CanNmRxToUp[] = {

{ ComConf_ComIPdu_IP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_Rx,
		(PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication } /*NM_EIRA_Rx_CanNm2PduR_Can_Network_0_Channel_CAN*/
};
#endif  /* PDUR_CONFIG_SINGLE_IFRX */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_LoIfDTxToUp_PBcfg_c::loIf_DTxToUp */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFTX_UP )
#define PduR_CanIfTxToUp NULL_PTR
#else

static const PduR_RT_LoIfTxToUp PduR_CanIfTxToUp[] = { {
		ComConf_ComIPdu_IP_CCP_Response_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 0  SrcPdu: CCP_Response_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: CCP_Response_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 1  SrcPdu: EPS_AngleCalibrateResponse_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: EPS_AngleCalibrateResponse_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 2  SrcPdu: EPS_DebugMessage_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: EPS_DebugMessage_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 3  SrcPdu: PSCBHIPBCanFD7Frame01_Com2PduR_Can_Network_1_Channel_CAN  DestPdu: PSCBHIPBCanFD7Frame01_PduR2CanIf_Can_Network_1_Channel_CAN*/
{ ComConf_ComIPdu_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 4  SrcPdu: PSCMTxCommonInfo_0x4A_Com2PduR_Can_Network_2_Channel_CAN  DestPdu: PSCMTxCommonInfo_0x4A_PduR2CanIf_Can_Network_2_Channel_CAN*/
{ ComConf_ComIPdu_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 5  SrcPdu: PSCMTxCurrentAndCommand_0x2A_Com2PduR_Can_Network_2_Channel_CAN  DestPdu: PSCMTxCurrentAndCommand_0x2A_PduR2CanIf_Can_Network_2_Channel_CAN*/
{ ComConf_ComIPdu_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 6  SrcPdu: PscmChas1Fr01_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: PscmChas1Fr01_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 7  SrcPdu: PscmChas1Fr02_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: PscmChas1Fr02_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 8  SrcPdu: PscmChas1Fr03_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: PscmChas1Fr03_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 9  SrcPdu: PscmChas1Fr06_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: PscmChas1Fr06_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 10  SrcPdu: PscmChas1Fr07_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: PscmChas1Fr07_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }, /* Index: 11  SrcPdu: PscmDevelpFr_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: PscmDevelpFr_PduR2CanIf_Can_Network_0_Channel_CAN*/
{ ComConf_ComIPdu_IP_TestResponse_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation } /* Index: 12  SrcPdu: TestResponse_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: TestResponse_PduR2CanIf_Can_Network_0_Channel_CAN*/
};
#endif  /* PDUR_CONFIG_SINGLE_IFTX_UP */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_LoIfTTxToUp_PBcfg_c::loIf_TTxToUp */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFTX_UP )
#define PduR_CanNmTxToUp NULL_PTR
#else

static const PduR_RT_LoTtIfTxToUp PduR_CanNmTxToUp[] = { {
		ComConf_ComIPdu_IP_NM_VCU_Can_Network_0_Channel_CAN_Tx,
		(PduR_upIfTriggerTxFP) PduR_RF_Com_TriggerTransmit,
		(PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation } /* Index: 0  SrcPdu: NM_VCU_Com2PduR_Can_Network_0_Channel_CAN  DestPdu: NM_VCU_PduR2CanNm_Can_Network_0_Channel_CAN*/
};
#endif  /* PDUR_CONFIG_SINGLE_IFTX_UP */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_LoTpRxToUp_PBcfg_c::loTpRx_To_Up */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined ( PDUR_CONFIG_SINGLE_TPRX )
#define PduR_CanTpRxToUp   NULL_PTR
#else
static const PduR_RT_LoTpRxToUp PduR_CanTpRxToUp[] =
		{

				{
						DcmConf_DcmDslProtocolRx_Diag_Functional_request_PduR2Dcm_Can_Network_0_Channel_CAN,
						(PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,
						(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,
						(PduR_upTpRxIndicationFP) PduR_RF_Dcm_TpRxIndication }, /*Diag_Functional_request_CanTp2PduR_Can_Network_0_Channel_CAN*/

				{
						DcmConf_DcmDslProtocolRx_Diag_Physical_request_PduR2Dcm_Can_Network_0_Channel_CAN,
						(PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,
						(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,
						(PduR_upTpRxIndicationFP) PduR_RF_Dcm_TpRxIndication } /*Diag_Physical_request_CanTp2PduR_Can_Network_0_Channel_CAN*/
		};
#endif  /* PDUR_CONFIG_SINGLE_TPRX */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_LoTpTxToUp_PBcfg_c::loTpTx_To_Up */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_TPTX_UP )
#define PduR_CanTpTxToUp NULL_PTR
#else
static const PduR_RT_LoTpTxToUp PduR_CanTpTxToUp[] =
		{
				{
						DcmConf_DcmDslProtocolTx_Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN,
						(PduR_upTpProvideTxBufFP) PduR_RF_Dcm_CopyTxData,
						(PduR_upTpTxConfirmationFP) PduR_RF_Dcm_TpTxConfirmation } /*Index: 0 Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN */
		};
#endif  /* PDUR_CONFIG_SINGLE_TPTX_UP */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_Mc_UpTpToLo_PBcfg_c::mcUpTp_To_Lo */
/* Generating PbCfg_c::PduR_Mc_UpIfToLo_PBcfg_c::mcUpIf_To_Lo */

/* Generating PbCfg_c::PduR_Mc_TpTxToUp_PBcfg_c::xpandMcTpTxToUp */
/* Generating PbCfg_c::PduR_Mc_GwToLo_PBcfg_c::DisplayPduR_mcGwToLo */
/* Generating PbCfg_c::PduR_GwIfTx_PBcfg_c::display_GwIfTx */
/* Generating PbCfg_c::PduR_GwIf_PBcfg_c::display_GwIf */
/* Generating PbCfg_c::PduR_Gw_IfBuf_PBcfg_c::PduR_gw_Buf_If_structure */
/* Generating PbCfg_c::PduR_Rpg_PBcfg_c::display_PduR_RPG*/

#if defined(PDUR_MODE_DEPENDENT_ROUTING) && (PDUR_MODE_DEPENDENT_ROUTING != 0)



/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

static const PduR_RPGInfoType PduR_RPGInfo[] = {

    {
     NULL_PTR,
     NULL_PTR,
     PDUR_RPGID_NULL,
     0,
     0
    },   /* PDUR_RPGID_NULL */

    
};

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_8
#else
#define PDUR_START_SEC_CONFIG_DATA_8
#endif

#include "PduR_MemMap.h"

/* Routing enable disbale flag to control routing. */
const boolean PduR_RPG_EnRouting[] =
{
  TRUE, /*PDUR_RPGID_NULL*/
  
};

/* ------------------------------------------------------------------------ */
/* End section for constants */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_8
#else
#define PDUR_STOP_SEC_CONFIG_DATA_8
#endif
#include "PduR_MemMap.h"



#endif /* #if defined(PDUR_MODE_DEPENDENT_ROUTING) && (PDUR_MODE_DEPENDENT_ROUTING != 0) */

/* Generating PbCfg_c::PduR_Gw_TpBuf_PBcfg_c::PduR_gw_Buf_TP_structure*/
/* Generating PbCfg_c::PduR_GwTp_PBcfg_c::display_GwTp */
/* Generating PbCfg_c::PduR_RpgRxTp_PBcfg_c::display_RpgRxTp */
/* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::PduR_BswLoCfg */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

static const PduR_LoTpConfig PduR_LoTpCfg[] = { { PduR_CanTpRxToUp, /* CanTp */
PduR_CanTpTxToUp, /* CanTp */
NULL_PTR, NULL_PTR, 2, /* CanTp RxToUp Number Of Entries*/
1 /* CanTp TxToUp Number Of Entries*/
}, { NULL_PTR, /* SecOCTp */
NULL_PTR, /* SecOCTp */
NULL_PTR, NULL_PTR, 0, /* SecOCTp */
0 /* SecOCTp */
} };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

static const PduR_LoIfDConfig PduR_LoIfDCfg[] = { { PduR_CanIfRxToUp, /* CanIf */
PduR_CanIfTxToUp, /* CanIf */
NULL_PTR, NULL_PTR, 37, /* CanIf RxToUp NrEntries*/
13 /* CanIf TxToUp NrEntries*/
} };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

static const PduR_LoIfTTConfig PduR_LoIfTTCfg[] = { { PduR_CanNmRxToUp, /* CanNm */
PduR_CanNmTxToUp, /* CanNm */
NULL_PTR, NULL_PTR, 1, /* CanNm RxToUp NrEntries*/
1 /* CanNm TxToUp NrEntries*/
}, { NULL_PTR, /* SecOC */
NULL_PTR, /* SecOC */
NULL_PTR, NULL_PTR, 0, /* SecOC */
0 /* SecOC */
} };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
/* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::PduR_BswUpCfg */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
static const PduR_UpConfig PduR_UpTpCfg[] = { { PduR_DcmToLo, /* Dcm */
NULL_PTR, /* mcDcmToLo */
1 /* Dcm */
} };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
static const PduR_UpConfig PduR_UpIfCfg[] = { { PduR_comToLo, /* Com */
NULL_PTR, /* mcComToLo */
14 /* Com */
}, { NULL_PTR, /* SecOC */
NULL_PTR, /* mcSecOCToLo */
0 /* SecOC */
} };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
/* Generating PbCfg_c::PduR_Cdd_PBcfg_c::PduR_CddCfg */
/* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::PduR_BswUpToLoRxCfg */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

const PduR_RPTablesType PduR_RoutingPathTables =
		{ (const PduR_loTransmitFuncType*) PduR_loTransmitTable,
				(const PduR_loCancelReceiveFuncType*) PduR_loCancelRxTable,
				(const PduR_loCancelTransmitFuncType*) PduR_loCancelTransmitTable,
				(const PduR_upIfRxIndicationFuncType*) PduR_upIfRxIndicationTable,
				(const PduR_upIfTxConfirmationFuncType*) PduR_upIfTxConfirmationTable,
				(const PduR_upTpCopyRxDataFuncType*) PduR_upTpCopyRxDataTable,
				(const PduR_upTpStartOfReceptionFuncType*) PduR_upTpStartOfReceptionTable,
				(const PduR_upTpRxIndicationFuncType*) PduR_upTpRxIndicationTable,
				(const PduR_upTpCopyTxDataFuncType*) PduR_upTpCopyTxDataTable,
				(const PduR_upTpTxConfirmationFuncType*) PduR_upTpTxConfirmationTable,
				(const PduR_upIfTriggerTxFuncType*) PduR_upIfTriggerTxTable

		};

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/*
 These structures are generated by the code generator tool. Respective module's function names are generated
 only if it is present in the PduR_PbCfg.c file in any one of the entries.
 */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

const PduR_loTransmitFuncType PduR_loTransmitTable[] = { {
		&PduR_RF_CanIf_Transmit_Func }, { &PduR_RF_CanNm_Transmit_Func }, {
		&PduR_RF_CanTp_Transmit_Func } };

const PduR_loCancelReceiveFuncType PduR_loCancelRxTable[] = { { NULL_PTR } };

const PduR_loCancelTransmitFuncType PduR_loCancelTransmitTable[] = { {
		&PduR_IH_CancelTransmit_Func }, { &PduR_RF_CanTp_CancelTransmit_Func } };

const PduR_upIfRxIndicationFuncType PduR_upIfRxIndicationTable[] = { {
		&PduR_RF_Com_RxIndication_Func } };

const PduR_upIfTxConfirmationFuncType PduR_upIfTxConfirmationTable[] = { {
		&PduR_RF_Com_TxConfirmation_Func } };

const PduR_upIfTriggerTxFuncType PduR_upIfTriggerTxTable[] = { {
		&PduR_RF_Com_TriggerTransmit_Func } };

const PduR_upTpCopyRxDataFuncType PduR_upTpCopyRxDataTable[] = { {
		&PduR_RF_Dcm_CopyRxData_Func } };

const PduR_upTpStartOfReceptionFuncType PduR_upTpStartOfReceptionTable[] = { {
		&PduR_RF_Dcm_StartOfReception_Func } };

const PduR_upTpRxIndicationFuncType PduR_upTpRxIndicationTable[] = { {
		&PduR_RF_Dcm_TpRxIndication_Func } };

const PduR_upTpCopyTxDataFuncType PduR_upTpCopyTxDataTable[] = { {
		&PduR_RF_Dcm_CopyTxData_Func } };

const PduR_upTpTxConfirmationFuncType PduR_upTpTxConfirmationTable[] = { {
		&PduR_RF_Dcm_TpTxConfirmation_Func } };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
/* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::pdur_PBConfigType */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
const PduR_PBConfigType PduR_GlobalPBConfig = {
		(const PduR_CddConfig*) NULL_PTR, /* PduR_CddCfg */
		(const PduR_LoTpConfig*) PduR_LoTpCfg, /* Pointer to lowerlayer Tp config structure */
		(const PduR_LoIfDConfig*) PduR_LoIfDCfg, /* Pointer to Direct lowerlayer If config structure */
		(const PduR_LoIfTTConfig*) PduR_LoIfTTCfg, /* Pointer to TT lowerlayer If config structure */
		(const PduR_UpConfig*) PduR_UpIfCfg, /* Pointer to Upperlayer If config structure */
		(const PduR_UpConfig*) PduR_UpTpCfg, /* Pointer to Upperlayer Tp config structure */
		(const PduR_MT_UpToLo*) NULL_PTR, /* mcGwToLo */
		(const PduR_MT_LoIfTxToUp*) NULL_PTR, /* McIfRx */
		(const PduR_MT_LoTpTxToUp*) NULL_PTR, /* McTpTx */
		(PduR_MS_LoTpTxToUp*) NULL_PTR, /* PduR_msTpTxToUp*/
		(const PduR_GT_IfTx*) NULL_PTR, /* gwIfTx */
		(const PduR_GT_If*) NULL_PTR, /* gwIf        */
		(const PduR_GT_Tp*) NULL_PTR, /* GwTp */
		(const PduR_RPG_LoTpRxToUp*) NULL_PTR, /* rpgTp */
		(const PduR_RPTablesType*) &PduR_RoutingPathTables, /* PduR_RoutingPathTables */
#if defined(PDUR_TPGATEWAY_SUPPORT) && (PDUR_TPGATEWAY_SUPPORT != STD_OFF)
    (const PduR_GwTp_SessionListType * ) NULL_PTR, /*PduR_TpSession_Dynamic*/
#endif
#if defined(PDUR_MULTICAST_TO_IF_SUPPORT) && (PDUR_MULTICAST_TO_IF_SUPPORT != 0)
     (const PduR_UpIfTxConf_Config * ) PduR_UpIfTxConf_ConfigList,
#endif
#if defined(PDUR_MODE_DEPENDENT_ROUTING) && (PDUR_MODE_DEPENDENT_ROUTING != 0)
     (const PduR_RPGInfoType * )        PduR_RPGInfo,        /* RoutingPathGroup ConfigInfo */
     (const boolean * )   PduR_RPG_EnRouting,  /* RoutingControl StatusInfo */
     (boolean * )  PduR_RPG_Status,        /*RAM status for each RPG*/
     (PduR_RoutingPathGroupIdType)                              0,        /* Number of RPGs.*/
#endif
		(const PduR_UpTpToLoTpRxConfig*) NULL_PTR, /* Pointer to PduR_UpTpToLoTpRxConfig structure for supporting Cancel Receive API */
		0, /* PDUR_CONFIGURATION_ID */
		0, /*Total no of Gw Tp Routing Path*/
		0, /*Total no of Gw If Routing path*/
		(PduIdType) 0 /* McTpTx */
};

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"
const PduR_ConfigType PduR_Config = { NULL_PTR, /* Void pointer initialised with null pointer as PduR_Config will not be used in case of PDUR_VARIANT_PRE_COMPILE */
NULL_PTR };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#if ( PDUR_CONFIGURATION_VARIANT != PDUR_VARIANT_PRE_COMPILE )
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#else
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#include "PduR_MemMap.h"

