


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

#if !defined(COM_CFG_SYMBOLICNAMES_H)
# define COM_CFG_SYMBOLICNAMES_H


/* if COM_DontUseExternalSymbolicNames is defined while including this file, then the below symbolic names will not
   be visible in the including file */
# if !defined(COM_DontUseExternalSymbolicNames)

/* ------------------------------------------------------------------------ */
/* Begin section for IPdu symbolic names */

/* Tx IPdus */
        #  define ComConf_ComIPdu_IP_PSCMTxCurrentAndCommand_0x2A_Can_Network_2_Channel_CAN_Tx 0
        #  define ComConf_ComIPdu_IP_PSCMTxCommonInfo_0x4A_Can_Network_2_Channel_CAN_Tx 1
        #  define ComConf_ComIPdu_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx 2
        #  define ComConf_ComIPdu_IP_PscmChas1Fr01_Can_Network_0_Channel_CAN_Tx 3
        #  define ComConf_ComIPdu_IP_PscmChas1Fr07_Can_Network_0_Channel_CAN_Tx 4
        #  define ComConf_ComIPdu_IP_PscmChas1Fr02_Can_Network_0_Channel_CAN_Tx 5
        #  define ComConf_ComIPdu_IP_PscmChas1Fr03_Can_Network_0_Channel_CAN_Tx 6
        #  define ComConf_ComIPdu_IP_PscmChas1Fr06_Can_Network_0_Channel_CAN_Tx 7
        #  define ComConf_ComIPdu_IP_CCP_Response_Can_Network_0_Channel_CAN_Tx 8
        #  define ComConf_ComIPdu_IP_EPS_AngleCalibrateResponse_Can_Network_0_Channel_CAN_Tx 9
        #  define ComConf_ComIPdu_IP_EPS_DebugMessage_Can_Network_0_Channel_CAN_Tx 10
        #  define ComConf_ComIPdu_IP_NM_VCU_Can_Network_0_Channel_CAN_Tx 11
        #  define ComConf_ComIPdu_IP_PscmDevelpFr_Can_Network_0_Channel_CAN_Tx 12
        #  define ComConf_ComIPdu_IP_TestResponse_Can_Network_0_Channel_CAN_Tx 13
    /* Rx IPdus */
        #  define ComConf_ComIPdu_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx 0
        #  define ComConf_ComIPdu_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx 1
        #  define ComConf_ComIPdu_IP_CCP_Request_Can_Network_0_Channel_CAN_Rx 2
        #  define ComConf_ComIPdu_IP_CSCHIPBHIPBCANFD7Frame03_Can_Network_1_Channel_CAN_Rx 3
        #  define ComConf_ComIPdu_IP_CSCHIPBHIPBCanFD7Frame10_Can_Network_1_Channel_CAN_Rx 4
        #  define ComConf_ComIPdu_IP_EPS_AngleCalibrateRequest_Can_Network_0_Channel_CAN_Rx 5
        #  define ComConf_ComIPdu_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx 6
        #  define ComConf_ComIPdu_IP_EtcToPscmDevelFr_Can_Network_0_Channel_CAN_Rx 7
        #  define ComConf_ComIPdu_IP_NM_EPS_EIRA_Can_Network_0_Channel_CAN_Rx 8
        #  define ComConf_ComIPdu_IP_PSCBTxCommonInfo_0x4F_Can_Network_2_Channel_CAN_Rx 9
        #  define ComConf_ComIPdu_IP_PSCBTxCurrentAndCommand_0x2F_Can_Network_2_Channel_CAN_Rx 10
        #  define ComConf_ComIPdu_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx 11
        #  define ComConf_ComIPdu_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx 12
        #  define ComConf_ComIPdu_IP_TestRequest_Can_Network_0_Channel_CAN_Rx 13
        #  define ComConf_ComIPdu_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx 14
        #  define ComConf_ComIPdu_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx 15
        #  define ComConf_ComIPdu_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx 16
        #  define ComConf_ComIPdu_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx 17
        #  define ComConf_ComIPdu_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx 18
        #  define ComConf_ComIPdu_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx 19
        #  define ComConf_ComIPdu_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx 20
        #  define ComConf_ComIPdu_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx 21
        #  define ComConf_ComIPdu_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx 22
        #  define ComConf_ComIPdu_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx 23
        #  define ComConf_ComIPdu_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx 24
        #  define ComConf_ComIPdu_IP_VddmChas1Fr30_Can_Network_0_Channel_CAN_Rx 25
        #  define ComConf_ComIPdu_IP_VddmChas1Fr33_Can_Network_0_Channel_CAN_Rx 26
        #  define ComConf_ComIPdu_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx 27
        #  define ComConf_ComIPdu_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx 28
        #  define ComConf_ComIPdu_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx 29
        #  define ComConf_ComIPdu_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx 30
        #  define ComConf_ComIPdu_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx 31
        #  define ComConf_ComIPdu_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx 32
        #  define ComConf_ComIPdu_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx 33
        #  define ComConf_ComIPdu_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx 34
        #  define ComConf_ComIPdu_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx 35
        #  define ComConf_ComIPdu_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx 36
        #  define ComConf_ComIPdu_IP_ZcudChas1Fr02_Can_Network_0_Channel_CAN_Rx 37

/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Signal symbolic names */



/* Signal IDs*/
/* Tx Signal ID*/
    #  define ComConf_ComSignal_S_test_0x2A_checksum_Can_Network_2_Channel_CAN_Tx 0
    #  define ComConf_ComSignal_S_test_0x2A_command_Can_Network_2_Channel_CAN_Tx 1
    #  define ComConf_ComSignal_S_test_0x2A_counter_Can_Network_2_Channel_CAN_Tx 2
    #  define ComConf_ComSignal_S_test_0x2A_current_Can_Network_2_Channel_CAN_Tx 3
    #  define ComConf_ComSignal_S_test_0x4A_FaultStatus_Can_Network_2_Channel_CAN_Tx 4
    #  define ComConf_ComSignal_S_test_0x4A_checksum_Can_Network_2_Channel_CAN_Tx 5
    #  define ComConf_ComSignal_S_test_0x4A_counter_Can_Network_2_Channel_CAN_Tx 6
    #  define ComConf_ComSignal_S_test_0x4A_current1_Can_Network_2_Channel_CAN_Tx 7
    #  define ComConf_ComSignal_S_test_0x4A_current2_Can_Network_2_Channel_CAN_Tx 8
    #  define ComConf_ComSignal_S_test_0x4A_current3_Can_Network_2_Channel_CAN_Tx 9
    #  define ComConf_ComSignal_S_test_0x4A_current4_Can_Network_2_Channel_CAN_Tx 10
    #  define ComConf_ComSignal_S_test_0x4A_current5_Can_Network_2_Channel_CAN_Tx 11
    #  define ComConf_ComSignal_S_test_0x4A_sensor1_Can_Network_2_Channel_CAN_Tx 12
    #  define ComConf_ComSignal_S_test_0x4A_sensor2_Can_Network_2_Channel_CAN_Tx 13
    #  define ComConf_ComSignal_S_test_0x4A_sensor3_Can_Network_2_Channel_CAN_Tx 14
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpADMo_Can_Network_1_Channel_CAN_Tx 15
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpChks_Can_Network_1_Channel_CAN_Tx 16
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpCntr_Can_Network_1_Channel_CAN_Tx 17
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpCtrl_Can_Network_1_Channel_CAN_Tx 18
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpData_Can_Network_1_Channel_CAN_Tx 19
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpDegr_Can_Network_1_Channel_CAN_Tx 20
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpLatC_Can_Network_1_Channel_CAN_Tx 21
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpQf_Can_Network_1_Channel_CAN_Tx 22
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkpSts_Can_Network_1_Channel_CAN_Tx 23
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsForCoDrvForBkp_UB_Can_Network_1_Channel_CAN_Tx 24
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpChks8_Can_Network_1_Channel_CAN_Tx 25
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpCntr4_Can_Network_1_Channel_CAN_Tx 26
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpDataID4_Can_Network_1_Channel_CAN_Tx 27
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpPin_0000_Can_Network_1_Channel_CAN_Tx 28
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpPin_0001_Can_Network_1_Channel_CAN_Tx 29
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpPin_0002_Can_Network_1_Channel_CAN_Tx 30
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpPinionSt_Can_Network_1_Channel_CAN_Tx 31
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpSte_0000_Can_Network_1_Channel_CAN_Tx 32
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkpSteerWhl_Can_Network_1_Channel_CAN_Tx 33
    #  define ComConf_ComSignal_S_PinionSteerAgGroupForBkp_UB_Can_Network_1_Channel_CAN_Tx 34
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsADMod_Can_Network_0_Channel_CAN_Tx 35
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsChks_Can_Network_0_Channel_CAN_Tx 36
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsCntr_Can_Network_0_Channel_CAN_Tx 37
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Tx 38
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsDegraded_Can_Network_0_Channel_CAN_Tx 39
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsQf_Can_Network_0_Channel_CAN_Tx 40
    #  define ComConf_ComSignal_S_ADL3LatCtrlStsSts_Can_Network_0_Channel_CAN_Tx 41
    #  define ComConf_ComSignal_S_ADL3LatCtrlSts_UB_Can_Network_0_Channel_CAN_Tx 42
    #  define ComConf_ComSignal_S_DrvrSteerActvChks_Can_Network_0_Channel_CAN_Tx 43
    #  define ComConf_ComSignal_S_DrvrSteerActvCntr_Can_Network_0_Channel_CAN_Tx 44
    #  define ComConf_ComSignal_S_DrvrSteerActvDrvrSteerActv_Can_Network_0_Channel_CAN_Tx 45
    #  define ComConf_ComSignal_S_DrvrSteerActv_UB_Can_Network_0_Channel_CAN_Tx 46
    #  define ComConf_ComSignal_S_FrntSteerFEstimd1_Can_Network_0_Channel_CAN_Tx 47
    #  define ComConf_ComSignal_S_FrntSteerFEstimd1_UB_Can_Network_0_Channel_CAN_Tx 48
    #  define ComConf_ComSignal_S_SteerStsToCrabMov_Can_Network_0_Channel_CAN_Tx 49
    #  define ComConf_ComSignal_S_SteerStsToCrabMov_UB_Can_Network_0_Channel_CAN_Tx 50
    #  define ComConf_ComSignal_S_UBoostReqBySteerFrnt_Can_Network_0_Channel_CAN_Tx 51
    #  define ComConf_ComSignal_S_UBoostReqBySteerFrnt_UB_Can_Network_0_Channel_CAN_Tx 52
    #  define ComConf_ComSignal_S_PinionSteerAgGroupChks_Can_Network_0_Channel_CAN_Tx 53
    #  define ComConf_ComSignal_S_PinionSteerAgGroupCntr_Can_Network_0_Channel_CAN_Tx 54
    #  define ComConf_ComSignal_S_PinionSteerAgGroupPinionSte_0000_Can_Network_0_Channel_CAN_Tx 55
    #  define ComConf_ComSignal_S_PinionSteerAgGroupPinionSte_0001_Can_Network_0_Channel_CAN_Tx 56
    #  define ComConf_ComSignal_S_PinionSteerAgGroupPinionSteerAg1_Can_Network_0_Channel_CAN_Tx 57
    #  define ComConf_ComSignal_S_PinionSteerAgGroupPinionSteerAgS_Can_Network_0_Channel_CAN_Tx 58
    #  define ComConf_ComSignal_S_PinionSteerAgGroupSteerWhlTqQf_Can_Network_0_Channel_CAN_Tx 59
    #  define ComConf_ComSignal_S_PinionSteerAgGroupSteerWhlTq_Can_Network_0_Channel_CAN_Tx 60
    #  define ComConf_ComSignal_S_PinionSteerAgGroup_UB_Can_Network_0_Channel_CAN_Tx 61
    #  define ComConf_ComSignal_S_LatCtrlModCfmdChks_Can_Network_0_Channel_CAN_Tx 62
    #  define ComConf_ComSignal_S_LatCtrlModCfmdCntr_Can_Network_0_Channel_CAN_Tx 63
    #  define ComConf_ComSignal_S_LatCtrlModCfmdLatCtrlMod_Can_Network_0_Channel_CAN_Tx 64
    #  define ComConf_ComSignal_S_LatCtrlModCfmd_UB_Can_Network_0_Channel_CAN_Tx 65
    #  define ComConf_ComSignal_S_SteerServoSts_Can_Network_0_Channel_CAN_Tx 66
    #  define ComConf_ComSignal_S_SteerServoSts_UB_Can_Network_0_Channel_CAN_Tx 67
    #  define ComConf_ComSignal_S_SteerWhlTqAddl_Can_Network_0_Channel_CAN_Tx 68
    #  define ComConf_ComSignal_S_SteerWhlTqAddl_UB_Can_Network_0_Channel_CAN_Tx 69
    #  define ComConf_ComSignal_S_TqAssAddl_Can_Network_0_Channel_CAN_Tx 70
    #  define ComConf_ComSignal_S_TqAssAddl_UB_Can_Network_0_Channel_CAN_Tx 71
    #  define ComConf_ComSignal_S_DrvrSteerWhlHldGroupDrvrSte_0000_Can_Network_0_Channel_CAN_Tx 72
    #  define ComConf_ComSignal_S_DrvrSteerWhlHldGroupDrvrSteerWhl_Can_Network_0_Channel_CAN_Tx 73
    #  define ComConf_ComSignal_S_DrvrSteerWhlHldGroup_UB_Can_Network_0_Channel_CAN_Tx 74
    #  define ComConf_ComSignal_S_SteerErrReq_Can_Network_0_Channel_CAN_Tx 75
    #  define ComConf_ComSignal_S_SteerErrReq_UB_Can_Network_0_Channel_CAN_Tx 76
    #  define ComConf_ComSignal_S_SteerExtFctStsChks_Can_Network_0_Channel_CAN_Tx 77
    #  define ComConf_ComSignal_S_SteerExtFctStsCntr_Can_Network_0_Channel_CAN_Tx 78
    #  define ComConf_ComSignal_S_SteerExtFctStsDrvrSteerOvrd_Can_Network_0_Channel_CAN_Tx 79
    #  define ComConf_ComSignal_S_SteerExtFctStsExtFctLowerLimActi_Can_Network_0_Channel_CAN_Tx 80
    #  define ComConf_ComSignal_S_SteerExtFctStsExtFctRateLimActiv_Can_Network_0_Channel_CAN_Tx 81
    #  define ComConf_ComSignal_S_SteerExtFctStsExtFctUpperLimActi_Can_Network_0_Channel_CAN_Tx 82
    #  define ComConf_ComSignal_S_SteerExtFctStsExtSafeLimActive_Can_Network_0_Channel_CAN_Tx 83
    #  define ComConf_ComSignal_S_SteerExtFctStsLatAgReqNotInRange_Can_Network_0_Channel_CAN_Tx 84
    #  define ComConf_ComSignal_S_SteerExtFctStsLatCtrlReqNotInRan_Can_Network_0_Channel_CAN_Tx 85
    #  define ComConf_ComSignal_S_SteerExtFctSts_UB_Can_Network_0_Channel_CAN_Tx 86
    #  define ComConf_ComSignal_S_SteerSftyLimrSts_Can_Network_0_Channel_CAN_Tx 87
    #  define ComConf_ComSignal_S_SteerSftyLimrSts_UB_Can_Network_0_Channel_CAN_Tx 88
    #  define ComConf_ComSignal_S_SteerStsToParkAssi_Can_Network_0_Channel_CAN_Tx 89
    #  define ComConf_ComSignal_S_SteerStsToParkAssi_UB_Can_Network_0_Channel_CAN_Tx 90
    #  define ComConf_ComSignal_S_PinionSteerAgMax1_Can_Network_0_Channel_CAN_Tx 91
    #  define ComConf_ComSignal_S_PinionSteerAgMax1_UB_Can_Network_0_Channel_CAN_Tx 92
    #  define ComConf_ComSignal_S_CCP_Res_Data_Can_Network_0_Channel_CAN_Tx 93
    #  define ComConf_ComSignal_S_SAS_ResponseData_Can_Network_0_Channel_CAN_Tx 94
    #  define ComConf_ComSignal_S_Debug_infor_1_Can_Network_0_Channel_CAN_Tx 95
    #  define ComConf_ComSignal_S_Debug_infor_2_Can_Network_0_Channel_CAN_Tx 96
    #  define ComConf_ComSignal_S_Debug_infor_3_Can_Network_0_Channel_CAN_Tx 97
    #  define ComConf_ComSignal_S_Debug_infor_4_Can_Network_0_Channel_CAN_Tx 98
    #  define ComConf_ComSignal_S_NM_User_Data_Can_Network_0_Channel_CAN_Tx 99
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1F_0000_Can_Network_0_Channel_CAN_Tx 100
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1F_0001_Can_Network_0_Channel_CAN_Tx 101
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1F_0002_Can_Network_0_Channel_CAN_Tx 102
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1F_0003_Can_Network_0_Channel_CAN_Tx 103
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1F_0004_Can_Network_0_Channel_CAN_Tx 104
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1F_0005_Can_Network_0_Channel_CAN_Tx 105
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1F_0006_Can_Network_0_Channel_CAN_Tx 106
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupresp1Functi_Can_Network_0_Channel_CAN_Tx 107
    #  define ComConf_ComSignal_S_TestModeResponse0_Can_Network_0_Channel_CAN_Tx 108
    #  define ComConf_ComSignal_S_TestModeResponse1_Can_Network_0_Channel_CAN_Tx 109
    #  define ComConf_ComSignal_S_TestModeResponse2_Can_Network_0_Channel_CAN_Tx 110
    #  define ComConf_ComSignal_S_TestModeResponse3_Can_Network_0_Channel_CAN_Tx 111
    #  define ComConf_ComSignal_S_TestModeResponse4_Can_Network_0_Channel_CAN_Tx 112
    #  define ComConf_ComSignal_S_TestModeResponse5_Can_Network_0_Channel_CAN_Tx 113
    #  define ComConf_ComSignal_S_TestModeResponse6_Can_Network_0_Channel_CAN_Tx 114
    #  define ComConf_ComSignal_S_TestModeResponse7_Can_Network_0_Channel_CAN_Tx 115

/* Rx Signal ID*/
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx 0
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx 1
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx 2
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx 3
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx 4
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx 5
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx 6
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx 7
    #  define ComConf_ComSignal_S_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx 8
    #  define ComConf_ComSignal_S_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx 9
    #  define ComConf_ComSignal_S_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx 10
    #  define ComConf_ComSignal_S_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx 11
    #  define ComConf_ComSignal_S_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx 12
    #  define ComConf_ComSignal_S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx 13
    #  define ComConf_ComSignal_S_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx 14
    #  define ComConf_ComSignal_S_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx 15
    #  define ComConf_ComSignal_S_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx 16
    #  define ComConf_ComSignal_S_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx 17
    #  define ComConf_ComSignal_S_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx 18
    #  define ComConf_ComSignal_S_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx 19
    #  define ComConf_ComSignal_S_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx 20
    #  define ComConf_ComSignal_S_CCP_Req_Data_Can_Network_0_Channel_CAN_Rx 21
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpADMod_Can_Network_1_Channel_CAN_Rx 22
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpChks8_Can_Network_1_Channel_CAN_Rx 23
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpCntr4_Can_Network_1_Channel_CAN_Rx 24
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpCtrlSts_Can_Network_1_Channel_CAN_Rx 25
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpDataID4_Can_Network_1_Channel_CAN_Rx 26
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpDegraded_Can_Network_1_Channel_CAN_Rx 27
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpQf_Can_Network_1_Channel_CAN_Rx 28
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkpSts_Can_Network_1_Channel_CAN_Rx 29
    #  define ComConf_ComSignal_S_AsyADL3FuncCtrlStsForBkp_UB_Can_Network_1_Channel_CAN_Rx 30
    #  define ComConf_ComSignal_S_AsyADModeReqForBkpADActiveReq_Can_Network_1_Channel_CAN_Rx 31
    #  define ComConf_ComSignal_S_AsyADModeReqForBkpADDeactiveReq_Can_Network_1_Channel_CAN_Rx 32
    #  define ComConf_ComSignal_S_AsyADModeReqForBkpChks8_Can_Network_1_Channel_CAN_Rx 33
    #  define ComConf_ComSignal_S_AsyADModeReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx 34
    #  define ComConf_ComSignal_S_AsyADModeReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx 35
    #  define ComConf_ComSignal_S_AsyADModeReqForBkp_UB_Can_Network_1_Channel_CAN_Rx 36
    #  define ComConf_ComSignal_S_AsyLatCoDrvReqForBkpAsyLatCoDrvR_Can_Network_1_Channel_CAN_Rx 37
    #  define ComConf_ComSignal_S_AsyLatCoDrvReqForBkpChks8_Can_Network_1_Channel_CAN_Rx 38
    #  define ComConf_ComSignal_S_AsyLatCoDrvReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx 39
    #  define ComConf_ComSignal_S_AsyLatCoDrvReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx 40
    #  define ComConf_ComSignal_S_AsyLatCoDrvReqForBkp_UB_Can_Network_1_Channel_CAN_Rx 41
    #  define ComConf_ComSignal_S_AsyPinionAgReqForBkpAsyPinionAgR_Can_Network_1_Channel_CAN_Rx 42
    #  define ComConf_ComSignal_S_AsyPinionAgReqForBkpChks8_Can_Network_1_Channel_CAN_Rx 43
    #  define ComConf_ComSignal_S_AsyPinionAgReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx 44
    #  define ComConf_ComSignal_S_AsyPinionAgReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx 45
    #  define ComConf_ComSignal_S_AsyPinionAgReqForBkp_UB_Can_Network_1_Channel_CAN_Rx 46
    #  define ComConf_ComSignal_S_AsyLatOvrdReqForBkpAsyLatOvrdReq_Can_Network_1_Channel_CAN_Rx 47
    #  define ComConf_ComSignal_S_AsyLatOvrdReqForBkpChks8_Can_Network_1_Channel_CAN_Rx 48
    #  define ComConf_ComSignal_S_AsyLatOvrdReqForBkpCntr4_Can_Network_1_Channel_CAN_Rx 49
    #  define ComConf_ComSignal_S_AsyLatOvrdReqForBkpDataID4_Can_Network_1_Channel_CAN_Rx 50
    #  define ComConf_ComSignal_S_AsyLatOvrdReqForBkp_UB_Can_Network_1_Channel_CAN_Rx 51
    #  define ComConf_ComSignal_S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx 52
    #  define ComConf_ComSignal_S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx 53
    #  define ComConf_ComSignal_S_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx 54
    #  define ComConf_ComSignal_S_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx 55
    #  define ComConf_ComSignal_S_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx 56
    #  define ComConf_ComSignal_S_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx 57
    #  define ComConf_ComSignal_S_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx 58
    #  define ComConf_ComSignal_S_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx 59
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx 60
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx 61
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx 62
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx 63
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx 64
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx 65
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx 66
    #  define ComConf_ComSignal_S_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx 67
    #  define ComConf_ComSignal_S_NM_EIRA_Can_Network_0_Channel_CAN_Rx 68
    #  define ComConf_ComSignal_S_test_0x4F_FaultStatus_Can_Network_2_Channel_CAN_Rx 69
    #  define ComConf_ComSignal_S_test_0x4F_checksum_Can_Network_2_Channel_CAN_Rx 70
    #  define ComConf_ComSignal_S_test_0x4F_counter_Can_Network_2_Channel_CAN_Rx 71
    #  define ComConf_ComSignal_S_test_0x4F_current1_Can_Network_2_Channel_CAN_Rx 72
    #  define ComConf_ComSignal_S_test_0x4F_current2_Can_Network_2_Channel_CAN_Rx 73
    #  define ComConf_ComSignal_S_test_0x4F_current3_Can_Network_2_Channel_CAN_Rx 74
    #  define ComConf_ComSignal_S_test_0x4F_current4_Can_Network_2_Channel_CAN_Rx 75
    #  define ComConf_ComSignal_S_test_0x4F_current5_Can_Network_2_Channel_CAN_Rx 76
    #  define ComConf_ComSignal_S_test_0x4F_sensor1_Can_Network_2_Channel_CAN_Rx 77
    #  define ComConf_ComSignal_S_test_0x4F_sensor2_Can_Network_2_Channel_CAN_Rx 78
    #  define ComConf_ComSignal_S_test_0x4F_sensor3_Can_Network_2_Channel_CAN_Rx 79
    #  define ComConf_ComSignal_S_test_0x2F_checksum_Can_Network_2_Channel_CAN_Rx 80
    #  define ComConf_ComSignal_S_test_0x2F_command_Can_Network_2_Channel_CAN_Rx 81
    #  define ComConf_ComSignal_S_test_0x2F_counter_Can_Network_2_Channel_CAN_Rx 82
    #  define ComConf_ComSignal_S_test_0x2F_current_Can_Network_2_Channel_CAN_Rx 83
    #  define ComConf_ComSignal_S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx 84
    #  define ComConf_ComSignal_S_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx 85
    #  define ComConf_ComSignal_S_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx 86
    #  define ComConf_ComSignal_S_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx 87
    #  define ComConf_ComSignal_S_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx 88
    #  define ComConf_ComSignal_S_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx 89
    #  define ComConf_ComSignal_S_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx 90
    #  define ComConf_ComSignal_S_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx 91
    #  define ComConf_ComSignal_S_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx 92
    #  define ComConf_ComSignal_S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx 93
    #  define ComConf_ComSignal_S_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx 94
    #  define ComConf_ComSignal_S_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx 95
    #  define ComConf_ComSignal_S_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx 96
    #  define ComConf_ComSignal_S_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx 97
    #  define ComConf_ComSignal_S_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx 98
    #  define ComConf_ComSignal_S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx 99
    #  define ComConf_ComSignal_S_TestModeRequest1_Can_Network_0_Channel_CAN_Rx 100
    #  define ComConf_ComSignal_S_TestModeRequest2_Can_Network_0_Channel_CAN_Rx 101
    #  define ComConf_ComSignal_S_TestModeRequest3_Can_Network_0_Channel_CAN_Rx 102
    #  define ComConf_ComSignal_S_TestModeRequest4_Can_Network_0_Channel_CAN_Rx 103
    #  define ComConf_ComSignal_S_TestModeRequest5_Can_Network_0_Channel_CAN_Rx 104
    #  define ComConf_ComSignal_S_TestModeRequest6_Can_Network_0_Channel_CAN_Rx 105
    #  define ComConf_ComSignal_S_TestModeRequest7_Can_Network_0_Channel_CAN_Rx 106
    #  define ComConf_ComSignal_S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx 107
    #  define ComConf_ComSignal_S_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx 108
    #  define ComConf_ComSignal_S_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx 109
    #  define ComConf_ComSignal_S_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx 110
    #  define ComConf_ComSignal_S_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx 111
    #  define ComConf_ComSignal_S_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx 112
    #  define ComConf_ComSignal_S_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx 113
    #  define ComConf_ComSignal_S_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx 114
    #  define ComConf_ComSignal_S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx 115
    #  define ComConf_ComSignal_S_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx 116
    #  define ComConf_ComSignal_S_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx 117
    #  define ComConf_ComSignal_S_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx 118
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx 119
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx 120
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx 121
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx 122
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx 123
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx 124
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx 125
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx 126
    #  define ComConf_ComSignal_S_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx 127
    #  define ComConf_ComSignal_S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx 128
    #  define ComConf_ComSignal_S_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx 129
    #  define ComConf_ComSignal_S_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx 130
    #  define ComConf_ComSignal_S_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx 131
    #  define ComConf_ComSignal_S_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx 132
    #  define ComConf_ComSignal_S_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx 133
    #  define ComConf_ComSignal_S_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx 134
    #  define ComConf_ComSignal_S_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx 135
    #  define ComConf_ComSignal_S_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx 136
    #  define ComConf_ComSignal_S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx 137
    #  define ComConf_ComSignal_S_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx 138
    #  define ComConf_ComSignal_S_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx 139
    #  define ComConf_ComSignal_S_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx 140
    #  define ComConf_ComSignal_S_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx 141
    #  define ComConf_ComSignal_S_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx 142
    #  define ComConf_ComSignal_S_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx 143
    #  define ComConf_ComSignal_S_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx 144
    #  define ComConf_ComSignal_S_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx 145
    #  define ComConf_ComSignal_S_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx 146
    #  define ComConf_ComSignal_S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx 147
    #  define ComConf_ComSignal_S_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx 148
    #  define ComConf_ComSignal_S_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx 149
    #  define ComConf_ComSignal_S_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx 150
    #  define ComConf_ComSignal_S_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx 151
    #  define ComConf_ComSignal_S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx 152
    #  define ComConf_ComSignal_S_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx 153
    #  define ComConf_ComSignal_S_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx 154
    #  define ComConf_ComSignal_S_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx 155
    #  define ComConf_ComSignal_S_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx 156
    #  define ComConf_ComSignal_S_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx 157
    #  define ComConf_ComSignal_S_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx 158
    #  define ComConf_ComSignal_S_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx 159
    #  define ComConf_ComSignal_S_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx 160
    #  define ComConf_ComSignal_S_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx 161
    #  define ComConf_ComSignal_S_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx 162
    #  define ComConf_ComSignal_S_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx 163
    #  define ComConf_ComSignal_S_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx 164
    #  define ComConf_ComSignal_S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx 165
    #  define ComConf_ComSignal_S_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx 166
    #  define ComConf_ComSignal_S_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx 167
    #  define ComConf_ComSignal_S_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx 168
    #  define ComConf_ComSignal_S_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx 169
    #  define ComConf_ComSignal_S_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx 170
    #  define ComConf_ComSignal_S_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx 171
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx 172
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx 173
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx 174
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx 175
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx 176
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx 177
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx 178
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx 179
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx 180
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx 181
    #  define ComConf_ComSignal_S_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx 182
    #  define ComConf_ComSignal_S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx 183
    #  define ComConf_ComSignal_S_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx 184
    #  define ComConf_ComSignal_S_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx 185
    #  define ComConf_ComSignal_S_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx 186
    #  define ComConf_ComSignal_S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx 187
    #  define ComConf_ComSignal_S_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx 188
    #  define ComConf_ComSignal_S_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx 189
    #  define ComConf_ComSignal_S_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx 190
    #  define ComConf_ComSignal_S_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx 191
    #  define ComConf_ComSignal_S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx 192
    #  define ComConf_ComSignal_S_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx 193
    #  define ComConf_ComSignal_S_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx 194
    #  define ComConf_ComSignal_S_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx 195
    #  define ComConf_ComSignal_S_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx 196
    #  define ComConf_ComSignal_S_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx 197
    #  define ComConf_ComSignal_S_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx 198
    #  define ComConf_ComSignal_S_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx 199
    #  define ComConf_ComSignal_S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx 200
    #  define ComConf_ComSignal_S_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx 201
    #  define ComConf_ComSignal_S_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx 202
    #  define ComConf_ComSignal_S_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx 203
    #  define ComConf_ComSignal_S_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx 204
    #  define ComConf_ComSignal_S_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx 205
    #  define ComConf_ComSignal_S_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx 206
    #  define ComConf_ComSignal_S_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx 207
    #  define ComConf_ComSignal_S_DrvModReq_Can_Network_0_Channel_CAN_Rx 208
    #  define ComConf_ComSignal_S_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx 209
    #  define ComConf_ComSignal_S_ULoWarnChks_Can_Network_0_Channel_CAN_Rx 210
    #  define ComConf_ComSignal_S_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx 211
    #  define ComConf_ComSignal_S_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx 212
    #  define ComConf_ComSignal_S_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx 213
    #  define ComConf_ComSignal_S_EscStChks_Can_Network_0_Channel_CAN_Rx 214
    #  define ComConf_ComSignal_S_EscStCntr_Can_Network_0_Channel_CAN_Rx 215
    #  define ComConf_ComSignal_S_EscStEscSt_Can_Network_0_Channel_CAN_Rx 216
    #  define ComConf_ComSignal_S_EscSt_UB_Can_Network_0_Channel_CAN_Rx 217
    #  define ComConf_ComSignal_S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx 218
    #  define ComConf_ComSignal_S_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx 219
    #  define ComConf_ComSignal_S_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx 220
    #  define ComConf_ComSignal_S_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx 221
    #  define ComConf_ComSignal_S_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx 222
    #  define ComConf_ComSignal_S_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx 223
    #  define ComConf_ComSignal_S_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx 224
    #  define ComConf_ComSignal_S_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx 225
    #  define ComConf_ComSignal_S_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx 226
    #  define ComConf_ComSignal_S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx 227
    #  define ComConf_ComSignal_S_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx 228
    #  define ComConf_ComSignal_S_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx 229
    #  define ComConf_ComSignal_S_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx 230
    #  define ComConf_ComSignal_S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx 231
    #  define ComConf_ComSignal_S_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx 232
    #  define ComConf_ComSignal_S_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx 233
    #  define ComConf_ComSignal_S_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx 234
    #  define ComConf_ComSignal_S_CarTiGlb_Can_Network_0_Channel_CAN_Rx 235
    #  define ComConf_ComSignal_S_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx 236
    #  define ComConf_ComSignal_S_ProfPenSts1_Can_Network_0_Channel_CAN_Rx 237
    #  define ComConf_ComSignal_S_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx 238
    #  define ComConf_ComSignal_S_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx 239
    #  define ComConf_ComSignal_S_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx 240
    #  define ComConf_ComSignal_S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx 241
    #  define ComConf_ComSignal_S_VehBattUSysU_Can_Network_0_Channel_CAN_Rx 242
    #  define ComConf_ComSignal_S_VehBattU_UB_Can_Network_0_Channel_CAN_Rx 243
    #  define ComConf_ComSignal_S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx 244
    #  define ComConf_ComSignal_S_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx 245
    #  define ComConf_ComSignal_S_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx 246
    #  define ComConf_ComSignal_S_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx 247
    #  define ComConf_ComSignal_S_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx 248
    #  define ComConf_ComSignal_S_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx 249
    #  define ComConf_ComSignal_S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx 250
    #  define ComConf_ComSignal_S_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx 251
    #  define ComConf_ComSignal_S_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx 252
    #  define ComConf_ComSignal_S_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx 253
    #  define ComConf_ComSignal_S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx 254
    #  define ComConf_ComSignal_S_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx 255
    #  define ComConf_ComSignal_S_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx 256
    #  define ComConf_ComSignal_S_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx 257
    #  define ComConf_ComSignal_S_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx 258
    #  define ComConf_ComSignal_S_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx 259
    #  define ComConf_ComSignal_S_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx 260
    #  define ComConf_ComSignal_S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx 261
    #  define ComConf_ComSignal_S_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx 262
    #  define ComConf_ComSignal_S_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx 263
    #  define ComConf_ComSignal_S_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx 264
    #  define ComConf_ComSignal_S_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx 265
    #  define ComConf_ComSignal_S_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx 266
    #  define ComConf_ComSignal_S_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx 267
    #  define ComConf_ComSignal_S_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx 268



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Signal group symbolic names */



/* Tx SignalGroup ID*/

/* Rx SignalGroup ID*/





/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Group signal symbolic names */



/* Tx GroupSignal ID*/

/* Rx GroupSignal ID*/




/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for IPdu group symbolic names */


/* IPduGroup ID*/
    #  define ComConf_ComIPduGroup_ComIPduGroup_NM_User_Data_Rx 0
    #  define ComConf_ComIPduGroup_ComIPduGroup_Rx 1
    #  define ComConf_ComIPduGroup_ComIPduGroup_Rx_PNC29 2
    #  define ComConf_ComIPduGroup_ComIPduGroup_NM_User_Data_Tx 3
    #  define ComConf_ComIPduGroup_ComIPduGroup_Tx 4
    #  define ComConf_ComIPduGroup_ComIPduGroup_Tx_PNC29 5
/* ------------------------------------------------------------------------ */
/* End section */

# endif /* end of COM_DontUseExternalSymbolicNames */


#endif /* COM_CFG_SYMBOLICNAMES_H */


