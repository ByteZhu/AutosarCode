
#ifndef CSM_CALLBACK_TYPES_H_
#define CSM_CALLBACK_TYPES_H_
#include "Std_Types.h"
#include "Rte_Type.h"
extern void CsmCallback_GCM_DEC_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_GCM_ENC_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_Gen_SecOC_Func(uint32 jobId, Crypto_ResultType result);
extern void CsmCallback_Ver_SecOC_Func(uint32 jobId, Crypto_ResultType result);
#endif

