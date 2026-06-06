


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

#if !defined(COM_CBK_H)
#define COM_CBK_H

#include "Com.h"

/************* Com Notification in Tx side ************************/

/* Start: ComNotification for Signals */


/* End: ComNotification for Signals */

/* Start: ComNotification for Signals Groups */


/* End: ComNotification for Signals Groups */

/* Start : IPDU notification for TX IPDUs */

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void ComNoti_Calback_TX_11(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/* End : IPDU notification for TX IPDUs */

/******************************************************************/

/************* Com Notification in Rx side ************************/

/* Start: ComNotification for Signals */

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void ComM_EIRACallBack_COMM_BUS_TYPE_CAN(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TestModeRequest7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_DrvModReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ULoWarnChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_EscStChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_EscStCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_EscStEscSt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_EscSt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_CarTiGlb_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ProfPenSts1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehBattUSysU_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehBattU_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbk_S_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/* End: ComNotification for Signals */

/* Start: ComNotification for Signals Groups */


/* End: ComNotification for Signals Groups */

/* Start: ComNotification for Rx IPdus */

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void ComNoti_Calback_0x1A0(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void ComNoti_Calback_0x20(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/* End: ComNotification for Rx IPdus */


/******************************************************************/

/************* Com Error Notification in Tx side ************************/

/* Start: ComErrorNotification for Tx-Signals */


/* End: ComErrorNotification for Tx-Signals */

/* Start: ComErrorNotification for Tx-Signals Groups */


/* End: ComErrorNotification for Tx-Signals Groups */

/******************************************************************/

/************* Com Timeout Notification in Tx side ************************/

/* Start: ComTimeoutNotification for Signals */


/* End: ComTimeoutNotification for Signals */

/* Start: ComTimeoutNotification for Signals Groups */


/* End: ComTimeoutNotification for Signals Groups */

/* Start: ComTimeoutNotification For Ipdu's */

/* End: ComTimeoutNotification for Ipdu's */

/******************************************************************/

/************* Timeout Notification in Rx side ************************/

/* Start: ComTimeoutNotification for Signals */

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SAS_RequestData_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Fu_0000_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Fu_0001_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Fu_0002_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Fu_0003_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Fu_0004_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Fu_0005_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Fu_0006_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PSCMdevelpsignalgroupreq1Functio_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest0_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TestModeRequest7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmCCPBytePosn2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmCCPBytePosn3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmCCPBytePosn4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmCCPBytePosn5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmCCPBytePosn6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmCCPBytePosn7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmCCPBytePosn8_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtBlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtCCPBytePosn2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtCCPBytePosn3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtCCPBytePosn4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtCCPBytePosn5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtCCPBytePosn6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtCCPBytePosn7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExtCCPBytePosn8_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_DrvModReq_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ULoWarnChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_EscStChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_EscStCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_EscStEscSt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_EscSt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_CarTiGlb_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ProfPenSts1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehBattUSysU_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehBattU_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2BlkIDBytePosn1_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2CCPBytePosn2_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2CCPBytePosn3_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2CCPBytePosn4_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2CCPBytePosn5_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2CCPBytePosn6_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2CCPBytePosn7_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMCbkTOut_S_VehCfgPrmExt2CCPBytePosn8_Can_Network_0_Channel_CAN_Rx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/* End: ComTimeoutNotification for Signals */

/* Start: ComTimeoutNotification for Signals Groups */

/* End: ComTimeoutNotification for Signals Groups */

/* Start: ComTimeoutNotification For Ipdu's */
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_AsdmChas1Fr01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_AsdmChas1Fr03(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_EcmChas1Fr08(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_PasChas1Fr02(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_SasChas1Fr01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VcuChas1Fr06(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VdcuIemChas1Fr01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr03(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr04(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr05(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr10(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr14(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr19(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr22(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr24(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr41(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr44(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr46(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr47(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr48(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr49(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr50(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr53(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr54(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Rte_COMTout_RxPdu_VddmChas1Fr55(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/* End: ComTimeoutNotification For Ipdu's */

/******************************************************************/

/************* Com Invalid Notification for Rx************************/

/* Start: ComInvalidNotification for Signals */

/* End: ComInvalidNotification for Signals */

/* Start: ComInvalidNotification for Signals Groups */

/* End: ComInvalidNotification for Signals Groups */

/******************************************************************/

/************* Com Ipdu Callouts ************************/


#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_AsdmChas1Fr01(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_AsdmChas1Fr03(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_EcmChas1Fr08(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_EtcToPscmDevelFr(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_PasChas1Fr02(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_SasChas1Fr01(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VcuChas1Fr06(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VdcuIemChas1Fr01(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr01(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr03(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr04(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr05(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr10(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr14(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr19(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr22(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr24(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr30(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr33(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr41(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr44(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr46(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr47(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr48(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr49(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr50(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr53(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr54(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_VddmChas1Fr55(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_RxPdu_ZcudChas1Fr02(PduIdType id, const PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"



#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_TxPdu_PscmChas1Fr01(PduIdType id, PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_TxPdu_PscmChas1Fr02(PduIdType id, PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_TxPdu_PscmChas1Fr03(PduIdType id, PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_TxPdu_PscmChas1Fr06(PduIdType id, PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_TxPdu_PscmChas1Fr07(PduIdType id, PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Rte_COMCbk_TxPdu_PscmDevelpFr(PduIdType id, PduInfoType * ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/******************************************************************/

/* Start: ComIPduCounterErrorNotification */



/* End: ComIPduCounterErrorNotification */


#endif /* COM_CBK_H */


