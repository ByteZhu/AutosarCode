/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CSM_H
#define CSM_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Csm_Types.h"
#include "Csm_Cfg.h"

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h" /* permit multiple inclusion */

// General Interface
extern void Csm_Init(const Csm_ConfigType* configPtr);
extern void Csm_Rb_Deinit(void);
extern void Csm_MainFunction(void);
// Job cancel Interface
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
Std_ReturnType Csm_CancelJob(uint32 jobId, Crypto_OperationModeType mode);
// Callback Notifications Interface
extern void Csm_CallbackNotification(Crypto_JobType* job, Crypto_ResultType result);
// MAC Interface
extern Std_ReturnType Csm_MacGenerate( uint32 jobId, Crypto_OperationModeType mode, const uint8* dataPtr,
                                       uint32 dataLength, uint8* macPtr, uint32* macLengthPtr );
extern Std_ReturnType Csm_MacVerify( uint32 jobId, Crypto_OperationModeType mode, const uint8* dataPtr,
                                     uint32 dataLength, const uint8* macPtr, const uint32 macLength,
                                     Crypto_VerifyResultType* verifyPtr );


// Authenticated Encryption with Associated Data Interface
extern Std_ReturnType Csm_AEADEncrypt( uint32 jobId, Crypto_OperationModeType mode, const uint8* plaintextPtr,
                                       uint32 plaintextLength, const uint8* associatedDataPtr,
                                       uint32 associatedDataLength, uint8* ciphertextPtr, uint32* ciphertextLengthPtr,
                                       uint8* tagPtr, uint32* tagLengthPtr);
extern Std_ReturnType Csm_AEADDecrypt( uint32 jobId, Crypto_OperationModeType mode, const uint8* ciphertextPtr,
                                       uint32 ciphertextLength, const uint8* associatedDataPtr,
                                       uint32 associatedDataLength, const uint8* tagPtr, uint32 tagLength,
                                       uint8* plaintextPtr, uint32* plaintextLengthPtr,
                                       Crypto_VerifyResultType* verifyPtr);

// KeyManagement Interface
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyElementSet(uint32 keyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeySetValid(uint32 keyId);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyGetStatus (uint32 keyId, Crypto_KeyStatusType* keyStatusPtr);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, uint8* keyPtr, uint32* keyLengthPtr);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyElementCopy(uint32 keyId, uint32 keyElementId, uint32 targetKeyId,
                                         uint32 targetKeyElementId);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyElementCopyPartial(uint32 keyId, uint32 keyElementId,
                                                uint32 keyElementSourceOffset, uint32 keyElementTargetOffset,
                                                uint32 keyElementCopyLength,  uint32 targetKeyId,
                                                uint32 targetKeyElementId);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyCopy(uint32 keyId, uint32 targetKeyId);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_RandomSeed(uint32 keyId, const uint8* seedPtr, uint32 seedLength);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyGenerate(uint32 keyId);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyDerive(uint32 keyId, uint32 targetKeyId);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyExchangeCalcPubVal(uint32 keyId, uint8* publicValuePtr, uint32* publicValueLengthPtr);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_KeyExchangeCalcSecret(uint32 keyId, const uint8* partnerPublicValuePtr,
                                                uint32 partnerPublicValueLength);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_CertificateParse(uint32 keyId);
/* MR12 RULE 8.5 VIOLATION: Multiple declarations of external object or function. Second declarations are coming
 from RTE interface for internal usage. No negative effect. */
extern Std_ReturnType Csm_CertificateVerify(uint32 keyId, uint32 verifyKeyId, Crypto_VerifyResultType* verifyPtr);
extern Std_ReturnType Csm_Rb_StorePermanentData(void);
// SHE key management interfaces

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h" /* permit multiple inclusion */

#endif /* CSM_H */

