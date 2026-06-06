/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Csm_Prv.h"
#include "Csm_Cbk.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/
#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
// Callbacks
//TRACE[SWS_Csm_00971]
void (* const Csm_Prv_CallbackConfig_acpfct[CSM_CFG_CALLBACK_COUNT])(uint32 jobId, Crypto_ResultType result) =
{
        &CsmCallback_GCM_DEC_Func,
        &CsmCallback_GCM_ENC_Func,
        &CsmCallback_Gen_SecOC_Func,
        &CsmCallback_Gen_SecOC_1_Func,
        &CsmCallback_Ver_SecOC_Func,
        &CsmCallback_Ver_SecOC_1_Func,
        &IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback,
        &IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback,
        &IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback,
        &IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback,
        &SecOCTxPduProcessing_TxCallback,
};

#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"


