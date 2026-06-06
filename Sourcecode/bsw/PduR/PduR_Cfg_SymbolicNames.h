
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: PduR  / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

#ifndef PDUR_CFG_SYMBOLICNAMES_H
#define PDUR_CFG_SYMBOLICNAMES_H

/* Note: Module variant generation is done here, specifically to make below macros available on the inclusion of 
 * PduR_memmap.h header file by other modules without PduR_Cfg.h inclusion */

#define PDUR_VARIANT_PRE_COMPILE    (0)

#define PDUR_VARIANT_POSTBUILD_LOADABLE    (1)

#if !defined(PDUR_CONFIGURATION_VARIANT)
#define PDUR_CONFIGURATION_VARIANT    PDUR_VARIANT_PRE_COMPILE
#endif /* PDUR_CONFIGURATION_VARIANT */

/* For PduRRoutingTable: Symbolic Name reference are generated for Tx Paths and Rx paths
 For TxPaths:
 PduRConf_PduRSrcPdu_<shortname of PduRSrcPdu> will be used by module which gives PduR_<UpperLayer>Transmit request e.g Com,Dcm,Up-Cdd
 PduRConf_PduRDestPdu_<shortname of PduRDestPdu> will be used by module which gives PduR_<LowerLayer>TxConfirmation callback e.g CanIf,CanTp,Low-Cdd

 For RxPaths:
 PduRConf_PduRSrcPdu_<shortname of PduRSrcPdu> will be used by module which gives PduR_<LowerLayer>RxIndication callback e.g CanIf,CanTp,Low-Cdd */

#define PduRConf_PduRSrcPdu_AsdmChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN    0

#define PduRConf_PduRSrcPdu_AsdmChas1Fr03_CanIf2PduR_Can_Network_0_Channel_CAN    1

#define PduRConf_PduRSrcPdu_CCP_Request_CanIf2PduR_Can_Network_0_Channel_CAN    2

#define PduRConf_PduRSrcPdu_CCP_Response_Com2PduR_Can_Network_0_Channel_CAN    0
#define PduRConf_PduRDestPdu_CCP_Response_PduR2CanIf_Can_Network_0_Channel_CAN  0

#define PduRConf_PduRSrcPdu_CSCHIPBHIPBCANFD7Frame03_CanIf2PduR_Can_Network_1_Channel_CAN    3

#define PduRConf_PduRSrcPdu_CSCHIPBHIPBCanFD7Frame10_CanIf2PduR_Can_Network_1_Channel_CAN    4

#define PduRConf_PduRSrcPdu_Diag_Functional_request_CanTp2PduR_Can_Network_0_Channel_CAN    0
#define PduRConf_PduRDestPdu_Diag_Functional_request_PduR2Dcm_Can_Network_0_Channel_CAN  0

#define PduRConf_PduRSrcPdu_Diag_Physical_request_CanTp2PduR_Can_Network_0_Channel_CAN    1
#define PduRConf_PduRDestPdu_Diag_Physical_request_PduR2Dcm_Can_Network_0_Channel_CAN  1

#define PduRConf_PduRSrcPdu_Diag_Physical_response_Phys_Dcm2PduR_Can_Network_0_Channel_CAN    0
#define PduRConf_PduRDestPdu_Diag_Physical_response_Phys_PduR2CanTp_Can_Network_0_Channel_CAN  0

#define PduRConf_PduRSrcPdu_EPS_AngleCalibrateRequest_CanIf2PduR_Can_Network_0_Channel_CAN    5

#define PduRConf_PduRSrcPdu_EPS_AngleCalibrateResponse_Com2PduR_Can_Network_0_Channel_CAN    1
#define PduRConf_PduRDestPdu_EPS_AngleCalibrateResponse_PduR2CanIf_Can_Network_0_Channel_CAN  1

#define PduRConf_PduRSrcPdu_EPS_DebugMessage_Com2PduR_Can_Network_0_Channel_CAN    2
#define PduRConf_PduRDestPdu_EPS_DebugMessage_PduR2CanIf_Can_Network_0_Channel_CAN  2

#define PduRConf_PduRSrcPdu_EcmChas1Fr08_CanIf2PduR_Can_Network_0_Channel_CAN    6

#define PduRConf_PduRSrcPdu_EtcToPscmDevelFr_CanIf2PduR_Can_Network_0_Channel_CAN    7

#define PduRConf_PduRSrcPdu_PduRSrcPdu    0

#define PduRConf_PduRSrcPdu_NM_VCU_Com2PduR_Can_Network_0_Channel_CAN    3
#define PduRConf_PduRDestPdu_NM_VCU_PduR2CanNm_Can_Network_0_Channel_CAN  0

#define PduRConf_PduRSrcPdu_PSCBHIPBCanFD7Frame01_Com2PduR_Can_Network_1_Channel_CAN    4
#define PduRConf_PduRDestPdu_PSCBHIPBCanFD7Frame01_PduR2CanIf_Can_Network_1_Channel_CAN  3

#define PduRConf_PduRSrcPdu_PSCBTxCommonInfo_0x4F_CanIf2PduR_Can_Network_2_Channel_CAN    8

#define PduRConf_PduRSrcPdu_PSCBTxCurrentAndCommand_0x2F_CanIf2PduR_Can_Network_2_Channel_CAN    9

#define PduRConf_PduRSrcPdu_PSCMTxCommonInfo_0x4A_Com2PduR_Can_Network_2_Channel_CAN    5
#define PduRConf_PduRDestPdu_PSCMTxCommonInfo_0x4A_PduR2CanIf_Can_Network_2_Channel_CAN  4

#define PduRConf_PduRSrcPdu_PSCMTxCurrentAndCommand_0x2A_Com2PduR_Can_Network_2_Channel_CAN    6
#define PduRConf_PduRDestPdu_PSCMTxCurrentAndCommand_0x2A_PduR2CanIf_Can_Network_2_Channel_CAN  5

#define PduRConf_PduRSrcPdu_PasChas1Fr02_CanIf2PduR_Can_Network_0_Channel_CAN    10

#define PduRConf_PduRSrcPdu_PscmChas1Fr01_Com2PduR_Can_Network_0_Channel_CAN    7
#define PduRConf_PduRDestPdu_PscmChas1Fr01_PduR2CanIf_Can_Network_0_Channel_CAN  6

#define PduRConf_PduRSrcPdu_PscmChas1Fr02_Com2PduR_Can_Network_0_Channel_CAN    8
#define PduRConf_PduRDestPdu_PscmChas1Fr02_PduR2CanIf_Can_Network_0_Channel_CAN  7

#define PduRConf_PduRSrcPdu_PscmChas1Fr03_Com2PduR_Can_Network_0_Channel_CAN    9
#define PduRConf_PduRDestPdu_PscmChas1Fr03_PduR2CanIf_Can_Network_0_Channel_CAN  8

#define PduRConf_PduRSrcPdu_PscmChas1Fr06_Com2PduR_Can_Network_0_Channel_CAN    10
#define PduRConf_PduRDestPdu_PscmChas1Fr06_PduR2CanIf_Can_Network_0_Channel_CAN  9

#define PduRConf_PduRSrcPdu_PscmChas1Fr07_Com2PduR_Can_Network_0_Channel_CAN    11
#define PduRConf_PduRDestPdu_PscmChas1Fr07_PduR2CanIf_Can_Network_0_Channel_CAN  10

#define PduRConf_PduRSrcPdu_PscmDevelpFr_Com2PduR_Can_Network_0_Channel_CAN    12
#define PduRConf_PduRDestPdu_PscmDevelpFr_PduR2CanIf_Can_Network_0_Channel_CAN  11

#define PduRConf_PduRSrcPdu_SasChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN    11

#define PduRConf_PduRSrcPdu_TestRequest_CanIf2PduR_Can_Network_0_Channel_CAN    12

#define PduRConf_PduRSrcPdu_TestResponse_Com2PduR_Can_Network_0_Channel_CAN    13
#define PduRConf_PduRDestPdu_TestResponse_PduR2CanIf_Can_Network_0_Channel_CAN  12

#define PduRConf_PduRSrcPdu_VcuChas1Fr06_CanIf2PduR_Can_Network_0_Channel_CAN    13

#define PduRConf_PduRSrcPdu_VdcuIemChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN    14

#define PduRConf_PduRSrcPdu_VddmChas1Fr01_CanIf2PduR_Can_Network_0_Channel_CAN    15

#define PduRConf_PduRSrcPdu_VddmChas1Fr03_CanIf2PduR_Can_Network_0_Channel_CAN    16

#define PduRConf_PduRSrcPdu_VddmChas1Fr04_CanIf2PduR_Can_Network_0_Channel_CAN    17

#define PduRConf_PduRSrcPdu_VddmChas1Fr05_CanIf2PduR_Can_Network_0_Channel_CAN    18

#define PduRConf_PduRSrcPdu_VddmChas1Fr10_CanIf2PduR_Can_Network_0_Channel_CAN    19

#define PduRConf_PduRSrcPdu_VddmChas1Fr14_CanIf2PduR_Can_Network_0_Channel_CAN    20

#define PduRConf_PduRSrcPdu_VddmChas1Fr19_CanIf2PduR_Can_Network_0_Channel_CAN    21

#define PduRConf_PduRSrcPdu_VddmChas1Fr22_CanIf2PduR_Can_Network_0_Channel_CAN    22

#define PduRConf_PduRSrcPdu_VddmChas1Fr24_CanIf2PduR_Can_Network_0_Channel_CAN    23

#define PduRConf_PduRSrcPdu_VddmChas1Fr30_CanIf2PduR_Can_Network_0_Channel_CAN    24

#define PduRConf_PduRSrcPdu_VddmChas1Fr33_CanIf2PduR_Can_Network_0_Channel_CAN    25

#define PduRConf_PduRSrcPdu_VddmChas1Fr41_CanIf2PduR_Can_Network_0_Channel_CAN    26

#define PduRConf_PduRSrcPdu_VddmChas1Fr44_CanIf2PduR_Can_Network_0_Channel_CAN    27

#define PduRConf_PduRSrcPdu_VddmChas1Fr46_CanIf2PduR_Can_Network_0_Channel_CAN    28

#define PduRConf_PduRSrcPdu_VddmChas1Fr47_CanIf2PduR_Can_Network_0_Channel_CAN    29

#define PduRConf_PduRSrcPdu_VddmChas1Fr48_CanIf2PduR_Can_Network_0_Channel_CAN    30

#define PduRConf_PduRSrcPdu_VddmChas1Fr49_CanIf2PduR_Can_Network_0_Channel_CAN    31

#define PduRConf_PduRSrcPdu_VddmChas1Fr50_CanIf2PduR_Can_Network_0_Channel_CAN    32

#define PduRConf_PduRSrcPdu_VddmChas1Fr53_CanIf2PduR_Can_Network_0_Channel_CAN    33

#define PduRConf_PduRSrcPdu_VddmChas1Fr54_CanIf2PduR_Can_Network_0_Channel_CAN    34

#define PduRConf_PduRSrcPdu_VddmChas1Fr55_CanIf2PduR_Can_Network_0_Channel_CAN    35

#define PduRConf_PduRSrcPdu_ZcudChas1Fr02_CanIf2PduR_Can_Network_0_Channel_CAN    36

#endif /* PDUR_CFG_SYMBOLICNAMES_H */
