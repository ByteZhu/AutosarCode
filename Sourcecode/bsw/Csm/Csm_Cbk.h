/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CSM_CBK_H
#define CSM_CBK_H

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
#define  CSM_START_SEC_CODE
#include "Csm_MemMap.h"

extern void CsmCallback_GCM_DEC_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_GCM_ENC_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_Gen_SecOC_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_Gen_SecOC_1_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_Ver_SecOC_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_Ver_SecOC_1_Func(uint32 jobId, Crypto_ResultType result);
extern void IP_CSCBCMCore_SecCanFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId, Crypto_ResultType result);
extern void IP_CSCBCMCore_SecCanFrame02_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId, Crypto_ResultType result);
extern void IP_CSCBCMCore_SecCanFrame03_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId, Crypto_ResultType result);
extern void IP_CSCBCMCore_SpecialSecFrame01_Can_Network_0_Channel_CAN_Rx_RxCallback(uint32 jobId, Crypto_ResultType result);
extern void SecOCTxPduProcessing_TxCallback(uint32 jobId, Crypto_ResultType result);

#define  CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

#endif /* CSM_CBK_H */
