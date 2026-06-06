


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR45.2.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 
 </VersionHead>*/

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Com_Prv.h"
#include "Com_Prv_Inl.h"
#include "Com_Cbk.h"


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

#ifdef COM_TXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
/* the Array to hold the Com Tx Ipdu control vector */
Com_TxIpduCtrlVector_tau8 Com_TxIpduControlVector_au8;
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* end of COM_TXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT */

#ifdef COM_RXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
/* the Array to hold the Com Rx Ipdu control vector */
Com_RxIpduCtrlVector_tau8 Com_RxIpduControlVector_au8;
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* end of COM_RXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT */

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/
/* START: TMS NONE Details  */

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
const Com_TransModeInfo_tst Com_NONE_TransModeInfo_cst =
{

    0, /* timePeriod_u16 */
    0, /* timeOffset_u16 */

    0, /* repetitionPeriod_u16 */
    0, /* numOfRepetitions_u8 */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_NONE, /* mode_u8 */
    COM_FALSE   /* mixedPhaseShift_b status */
#else

    COM_TXMODE_NONE /* mode_u8 */

#endif /* #ifdef COM_MIXEDPHASESHIFT */


};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

/* END: TMS NONE Details  */

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 Rx-MainFunction Timebase - 0.001 s
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

void Com_MainFunctionRx_ComMainFunctionRx(void)
{
#ifdef COM_ENABLE_MAINFUNCTION_RX
    Com_Prv_InternalMainFunctionRx( (Com_MainFunc_tuo)ComMainFunction_Internal_MainFunctionRxCom_MainFunctionRx_ComMainFunctionRx );
#endif
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/*
 **********************************************************************************************************************
 Tx-MainFunction Timebase - 0.001 s
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

void Com_MainFunctionTx_ComMainFunctionTx(void)
{
    Com_Prv_InternalMainFunctionTx( (Com_MainFunc_tuo)ComMainFunction_Internal_MainFunctionTxCom_MainFunctionTx_ComMainFunctionTx );
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/* START : Tx IPDU notification functions */
#ifdef COM_TxIPduNotification
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Tx Notification callback function for IPDU : IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx */
void Com_TxNotify_IP_PSCBHIPBCanFD7Frame01_Can_Network_1_Channel_CAN_Tx(void)
{
    ComNoti_Calback_TX_11();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#endif /* #ifdef COM_TxIPduNotification */
/* END : Tx IPDU notification functions */
/* START : Tx IPDU error notification functions */
/* END : Tx IPDU error notification functions */
/* START : Tx IPDU timeout  notification functions */
#ifdef COM_TxIPduTimeOutNotify
#endif /* #ifdef COM_TxIPduTimeOutNotify */
/* END : Tx IPDU timeout  notification functions */


/* START : Rx IPDU timeout  notification functions */
#ifdef COM_RxIPduTimeoutNotify
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_AsdmChas1Fr01_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_AsdmChas1Fr01();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsADMod_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsCtrlSts_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsDegraded_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlStsSts_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADL3FuncCtrlSts_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADModeReqADActiveReq_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADModeReqADDeactiveReq_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADModeReqChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADModeReqCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyADModeReq_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_AsdmChas1Fr03_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_AsdmChas1Fr03();

    Rte_COMCbkTOut_S_AgCtrlTqLowrLim_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgCtrlTqLowrLim_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgCtrlTqUpprLim_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgCtrlTqUpprLim_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyPinionAgReqSafeAsyPinionAgReq_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyPinionAgReqSafeAsyPinion_0000_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyPinionAgReqSafeAsyPinion_0001_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyPinionAgReqSafe_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_EcmChas1Fr08_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_EcmChas1Fr08();

    Rte_COMCbkTOut_S_PtTqAtWhlFrntActChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PtTqAtWhlFrntActCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtAxleFrntAc_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtWhlFrntLeA_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtWhlFrntRiA_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PtTqAtWhlFrntActPtTqAtWhlsFrntQl_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PtTqAtWhlFrntAct_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_PasChas1Fr02_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_PasChas1Fr02();

    Rte_COMCbkTOut_S_PrkgPinionAgReqGroupParkAss_0000_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PrkgPinionAgReqGroupParkAss_0001_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PrkgPinionAgReqGroupParkAssiPini_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PrkgPinionAgReqGroupQF_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_PrkgPinionAgReqGroup_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_UturnTrqRelsChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_UturnTrqRelsCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_UturnTrqRelsUturnTrqRels_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_UturnTrqRels_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_SasChas1Fr01_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_SasChas1Fr01();

    Rte_COMCbkTOut_S_SteerWhlSnsrAgSpd_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerWhlSnsrAg_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerWhlSnsrChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerWhlSnsrCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerWhlSnsrQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerWhlSnsr_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VcuChas1Fr06_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VcuChas1Fr06();

    Rte_COMCbkTOut_S_TiAndDateIndcnDataValid_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_TiAndDateIndcnDay_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_TiAndDateIndcnHr1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_TiAndDateIndcnMins1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_TiAndDateIndcnMth1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_TiAndDateIndcnSec1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_TiAndDateIndcnYr1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_TiAndDateIndcn_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VdcuIemChas1Fr01_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VdcuIemChas1Fr01();

    Rte_COMCbkTOut_S_CrabMovModStsChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_CrabMovModStsCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_CrabMovModStsTankTurnModSts_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_CrabMovModSts_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr01_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr01();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeALat1Qf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeALatWithCmp_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeGrdtOfALgt_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeYawRateQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafeYawRateWithCmp_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AsyDataWithCmpSafe_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr03_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr03();

    Rte_COMCbkTOut_S_ADataRawSafeALat1Qf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafeALat_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafeALgt1Qf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafeALgt_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafeAVertQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafeAVert_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafeChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafeCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ADataRawSafe_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr04_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr04();

    Rte_COMCbkTOut_S_AbsCtrlActvChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AbsCtrlActvCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AbsCtrlActvCtrlSts1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AbsCtrlActv_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_LatCtrlReqSafeChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_LatCtrlReqSafeCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_LatCtrlReqSafeLatCtrlModReq_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_LatCtrlReqSafeSteerTqReq_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_LatCtrlReqSafeSteerWhlHptcWarnRe_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_LatCtrlReqSafe_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr05_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr05();

    Rte_COMCbkTOut_S_VehSpdLgtA_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehSpdLgtChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehSpdLgtCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehSpdLgtQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehSpdLgt_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr10_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr10();

    Rte_COMCbkTOut_S_BrkPedlPsdBrkPedlNotPsdSafe_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_BrkPedlPsdBrkPedlPsd_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_BrkPedlPsdChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_BrkPedlPsdCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_BrkPedlPsdQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_BrkPedlPsd_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlFrntChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlFrntCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlFrntLeQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlFrntLe_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlFrntRiQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlFrntWhlSpdCircumlFr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlFrnt_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr14_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr14();

    Rte_COMCbkTOut_S_AgDataRawSafeChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataRawSafeCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataRawSafeRollRateQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataRawSafeRollRate_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataRawSafeYawRateQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataRawSafeYawRate_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataRawSafe_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr19_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr19();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1CarModSts1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1CarModSubtypWd_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1Chks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1Cntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1EgyLvlElecMai_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1EgyLvlElecSubt_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1FltEgyCnsWdSts_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1PwrLvlElecMai_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1PwrLvlElecSubt_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1UsgModSts_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehModMngtGlbSafe1_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr22_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr22();

    Rte_COMCbkTOut_S_SteerSetgPen_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerSetgSteerAsscLvl_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerSetgSteerMod_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SteerSetg_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr24_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr24();

    Rte_COMCbkTOut_S_WhlFastSpdSafeA_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlFastSpdSafeChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlFastSpdSafeCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlFastSpdSafeQF_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlFastSpdSafe_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr41_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr41();

    Rte_COMCbkTOut_S_DrvModReq_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_DrvModReq_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ULoWarnChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ULoWarnCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ULoWarnULoWarn_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ULoWarn_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr44_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr44();

    Rte_COMCbkTOut_S_EscStChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_EscStCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_EscStEscSt_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_EscSt_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr46_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr46();

    Rte_COMCbkTOut_S_BrkTracCtrlActv_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_BrkTracCtrlActv_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlRotToothCntrChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlRotToothCntrCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlRotToothCntrFrntLe_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlRotToothCntrFrntRi_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlRotToothCntrReLe_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlRotToothCntrReRi_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlRotToothCntr_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr47_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr47();

    Rte_COMCbkTOut_S_AgDataCmpQualityPitchRateCmpQual_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataCmpQualityRollRateCmpQuali_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataCmpQualityYawRateCmpQualit_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_AgDataCmpQuality_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr48_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr48();

    Rte_COMCbkTOut_S_VehMtnStChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehMtnStCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehMtnStVehMtnSt_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehMtnSt_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr49_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr49();

    Rte_COMCbkTOut_S_CarTiGlb_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_CarTiGlb_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ProfPenSts1_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_ProfPenSts1_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SaveSetgToMemPrmnt_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_SaveSetgToMemPrmnt_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr50_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr50();

    Rte_COMCbkTOut_S_VehBattUSysUQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehBattUSysU_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_VehBattU_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr53_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr53();

    Rte_COMCbkTOut_S_BkpOfDstTrvld_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_BkpOfDstTrvld_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_DrvModReqForChampnMod_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_DrvModReqForChampnMod_UB_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_RlyPwrDistbnCmd1WdIgnRlyCmd_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_RlyPwrDistbnCmd1WdIgnRlyCmd_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr54_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr54();

    Rte_COMCbkTOut_S_IDcDcActLoSideChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_IDcDcActLoSideCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_IDcDcActLoSideIDcDcActLoSide_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_IDcDcActLoSide_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx */
void Com_RxTONotify_IP_VddmChas1Fr55_Can_Network_0_Channel_CAN_Rx(void)
{
    Rte_COMTout_RxPdu_VddmChas1Fr55();

    Rte_COMCbkTOut_S_WhlSpdCircumlReChks_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlReCntr_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlReLeQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlReLe_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlReRiQf_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlReRi_Can_Network_0_Channel_CAN_Rx();

    Rte_COMCbkTOut_S_WhlSpdCircumlRe_UB_Can_Network_0_Channel_CAN_Rx();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* #ifdef COM_RxIPduTimeoutNotify */

/* END : Rx IPDU timeout  notification functions */




#ifdef COM_TXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT
/*
 **********************************************************************************************************************
 Function name    : Com_SetTxIPduControlViaRbaNdsEcuVariant
 Description      : Service called by rba_ComScl to set/reset the status of Tx Ipdu
 Parameter        : idIpdu_uo    -> ID of the Tx IPDU
                  : ipduStatus_b -> TxIpdu status maintained by rba_ComScl
 Return value     : none
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Com_SetTxIPduControlViaRbaNdsEcuVariant(PduIdType idIpdu_uo, boolean ipduStatus_b)
{
# if (COM_PRV_ERROR_HANDLING == STD_ON)
    if (Com_InitStatus_en == COM_UNINIT)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SetTxIPduControlViaRbaNdsEcuVariant, COM_E_UNINIT);
    }
    else if (!Com_Prv_IsValidTxIpduId(idIpdu_uo))
    {
        COM_DET_REPORT_ERROR(COMServiceId_SetTxIPduControlViaRbaNdsEcuVariant, COM_E_PARAM);
    }
    else
# endif /* end of COM_PRV_ERROR_HANDLING */
    {
        uint16   index_u16;
        uint8    bitOffset_u8;

        /* If PB variant is selected, then PduId which is passed to this function will be changed
        * to internal Id which is generated through configuration
        * If PC variant is selected, then no mapping table will be used. */
        idIpdu_uo = COM_GET_TX_IPDU_ID(idIpdu_uo);

        index_u16    = idIpdu_uo >> 3u;
        bitOffset_u8 = (uint8)(idIpdu_uo % 8u);

        if (ipduStatus_b)
        {
            Com_TxIpduControlVector_au8[index_u16] |= (uint8)(1u << bitOffset_u8);
        }
        else
        {
            Com_TxIpduControlVector_au8[index_u16] &= (uint8)(~((uint8)(1u << bitOffset_u8)));
        }
    }
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* end of COM_TXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT */
#ifdef COM_RXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT
/*
 **********************************************************************************************************************
 Function name    : Com_SetRxIPduControlViaRbaNdsEcuVariant
 Description      : Service called by rba_ComScl to set/reset the status of Rx Ipdu
 Parameter        : idIpdu_uo    -> ID of the Rx IPDU
                  : ipduStatus_b -> RxIpdu status maintained by rba_ComScl
 Return value     : none
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
void Com_SetRxIPduControlViaRbaNdsEcuVariant(PduIdType idIpdu_uo, boolean ipduStatus_b)
{
# if (COM_PRV_ERROR_HANDLING == STD_ON)
    if (Com_InitStatus_en == COM_UNINIT)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SetRxIPduControlViaRbaNdsEcuVariant, COM_E_UNINIT);
    }
    else if (!Com_Prv_IsValidRxIpduId(idIpdu_uo))
    {
        COM_DET_REPORT_ERROR(COMServiceId_SetRxIPduControlViaRbaNdsEcuVariant, COM_E_PARAM);
    }
    else
# endif /* end of COM_PRV_ERROR_HANDLING */
    {
        uint16   index_u16;
        uint8    bitOffset_u8;

        /* If PB variant is selected, then PduId which is passed to this function will be changed
        * to internal Id which is generated through configuration
        * If PC variant is selected, then no mapping table will be used. */
        idIpdu_uo = COM_GET_RX_IPDU_ID(idIpdu_uo);

        index_u16    = idIpdu_uo >> 3u;
        bitOffset_u8 = (uint8)(idIpdu_uo % 8u);

        if (ipduStatus_b)
        {
            Com_RxIpduControlVector_au8[index_u16] |= (uint8)(1u << bitOffset_u8);
        }
        else
        {
            Com_RxIpduControlVector_au8[index_u16] &= (uint8)(~((uint8)(1u << bitOffset_u8)));
        }
    }
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#endif /* end of COM_RXIPDUCONTROL_VIA_RBA_NDS_ECUVARIANT */




