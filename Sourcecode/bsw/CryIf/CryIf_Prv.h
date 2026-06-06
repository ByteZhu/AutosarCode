/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.CryIf
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CRYIF_PRV_H
#define CRYIF_PRV_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "CryIf.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
#define CRYIF_PRV_COPY_MAX_KEYELEMENT_COUNT        (2U)

#define CRYIF_PRV_MAX_U32_VALUE                         (0xFFFFFFFFUL)
#define CRYIF_PRV_CHECK_U32_ADD_OVERFLOW(a_u32, b_u32)  ((a_u32) > (CRYIF_PRV_MAX_U32_VALUE - (b_u32)))


/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/

#define CRYIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CryIf_MemMap.h"

extern boolean CryIf_Initialized_b;

#define CRYIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CryIf_MemMap.h"


#define CRYIF_START_SEC_CODE
#include "CryIf_MemMap.h"

//Dummy functions, which are used for mapping when the target crypto component doesn't support the required api
extern Std_ReturnType CryIf_Prv_Dummy_ProcessJob(uint32 objectId, Crypto_JobType* job);
extern Std_ReturnType CryIf_Prv_Dummy_CancelJob(uint32 objectId, Crypto_JobType* job);
extern Std_ReturnType CryIf_Prv_Dummy_KeyElementSet(uint32 cryptoKeyId, uint32 keyElementId,
                                                   const uint8* keyPtr, uint32 keyLength);
extern Std_ReturnType CryIf_Prv_Dummy_KeySetValid(uint32 cryIfKeyId);
extern Std_ReturnType CryIf_Prv_Dummy_KeyGetStatus(uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr);
extern Std_ReturnType CryIf_Prv_Dummy_KeyElementGet(uint32 cryIfKeyId, uint32 keyElementId,
                                                   uint8* resultPtr, uint32* resultLengthPtr);
extern Std_ReturnType CryIf_Prv_Dummy_KeyElementCopy(uint32 cryIfKeyId, uint32 keyElementId,
                                                    uint32 targetCryIfKeyId, uint32 targetKeyElementId);
extern Std_ReturnType CryIf_Prv_Dummy_KeyElementCopyPartial(uint32 cryIfKeyId,
                                                           uint32 keyElementId,
                                                           uint32 keyElementSourceOffset,
                                                           uint32 keyElementTargetOffset,
                                                           uint32 keyElementCopyLength,
                                                           uint32 targetCryIfKeyId,
                                                           uint32 targetKeyElementId);
extern Std_ReturnType CryIf_Prv_Dummy_KeyCopy(uint32 cryIfKeyId, uint32 targetCryIfKeyId);
extern Std_ReturnType CryIf_Prv_Dummy_KeyElementIdsGet(uint32 cryIfKeyId,
                                                       uint32* keyElementIdsPtr,
                                                       uint32* keyElementIdsLengthPtr);
extern Std_ReturnType CryIf_Prv_Dummy_RandomSeed(uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength);
extern Std_ReturnType CryIf_Prv_Dummy_KeyGenerate(uint32 cryIfKeyId);
extern Std_ReturnType CryIf_Prv_Dummy_KeyDerive(uint32 cryIfKeyId, uint32 targetCryIfKeyId);
extern Std_ReturnType CryIf_Prv_Dummy_KeyExchangeCalcPubVal(uint32 cryIfKeyId,
                                                           uint8* publicValuePtr,
                                                           uint32* publicValueLengthPtr);
extern Std_ReturnType CryIf_Prv_Dummy_KeyExchangeCalcSecret(uint32 cryIfKeyId,
                                                           const uint8* partnerPublicValuePtr,
                                                           uint32 partnerPublicValueLength);
extern Std_ReturnType CryIf_Prv_Dummy_CertificateParse(uint32 cryIfKeyId);
extern Std_ReturnType CryIf_Prv_Dummy_CertificateVerify(uint32 cryIfKeyId,
                                                       uint32 verifyCryIfKeyId,
                                                       Crypto_VerifyResultType* verifyPtr);
extern Std_ReturnType CryIf_Prv_Dummy_Rb_StorePermanentData(void);

#define CRYIF_STOP_SEC_CODE
#include "CryIf_MemMap.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

//Structure type used to store Channel mapping configuration
typedef struct
{
    uint16  CryptoModuleIndex_u16;
    uint32  CryptoDriverObjectId_u32;
} CryIf_Prv_ChannelMappingType;

//Structure type used to store Key mapping configuration
typedef struct
{
    uint16  CryptoModuleIndex_u16;
    uint32  CryptoKeyId_u32;
} CryIf_Prv_KeyMappingType;

/*
 **********************************************************************************************************************
 * Exports
 **********************************************************************************************************************
*/
#define CRYIF_START_SEC_CONST_UNSPECIFIED
#include "CryIf_MemMap.h"

//CryIfChannel to CryptoDriverObject mappings
extern const CryIf_Prv_ChannelMappingType CryIf_ChannelMapping_acst[];

//CryIfKey to CryptoKey mappings
extern const CryIf_Prv_KeyMappingType CryIf_KeyMapping_acst[];

//Crypto_ProcessJob function pointers
extern Std_ReturnType (*const CryIf_ProcessJob_acpfct[]) (uint32 objectId, Crypto_JobType* job);

//Crypto_CancelJob function pointers
extern Std_ReturnType (*const CryIf_CancelJob_acpfct[]) (uint32 objectId, Crypto_JobType* job);

//Crypto_KeyElementSet function pointers
extern Std_ReturnType (*const CryIf_KeyElementSet_acpfct[]) (uint32 cryptoKeyId, uint32 keyElementId,
                       const uint8* keyPtr, uint32 keyLength);

//Crypto_KeySetValid function pointers
extern Std_ReturnType (*const CryIf_KeySetValid_acpfct[]) (uint32 cryIfKeyId);

//Crypto_KeyGetStatus function pointers
extern Std_ReturnType (*const CryIf_KeyGetStatus_acpfct[]) (uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr);

//Crypto_KeyElementGet function pointers
extern Std_ReturnType (*const CryIf_KeyElementGet_acpfct[]) (uint32 cryIfKeyId, uint32 keyElementId,
                       uint8* resultPtr, uint32* resultLengthPtr);

//Crypto_KeyElementCopy function pointers
extern Std_ReturnType (*const CryIf_KeyElementCopy_acpfct[]) (uint32 cryIfKeyId, uint32 keyElementId,
                       uint32 targetCryIfKeyId, uint32 targetKeyElementId);

//Crypto_KeyElementCopyPartial function pointers
extern Std_ReturnType (*const CryIf_KeyElementCopyPartial_acpfct[]) (uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset,
                        uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId);

//Crypto_KeyCopy function pointers
extern Std_ReturnType (*const CryIf_KeyCopy_acpfct[]) (uint32 cryIfKeyId, uint32 targetCryIfKeyId);

//Crypto_KeyElementIdsGet function pointers
extern Std_ReturnType (*const CryIf_KeyElementIdsGet_acpfct[]) (uint32 cryIfKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr);

//Crypto_RandomSeed function pointers
extern Std_ReturnType (*const CryIf_RandomSeed_acpfct[]) (uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength);

//Crypto_KeyGenerate function pointers
extern Std_ReturnType (*const CryIf_KeyGenerate_acpfct[]) (uint32 cryIfKeyId);

//Crypto_KeyDerive function pointers
extern Std_ReturnType (*const CryIf_KeyDerive_acpfct[]) (uint32 cryIfKeyId, uint32 targetCryIfKeyId);

//Crypto_KeyExchangeCalcPubVal function pointers
extern Std_ReturnType (*const CryIf_KeyExchangeCalcPubVal_acpfct[]) (uint32 cryIfKeyId, uint8* publicValuePtr,
                       uint32* publicValueLengthPtr);

//Crypto_KeyExchangeCalcSecret function pointers
extern Std_ReturnType (*const CryIf_KeyExchangeCalcSecret_acpfct[]) (uint32 cryIfKeyId,
                       const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength);

//Crypto_CertificateParse function pointers
extern Std_ReturnType (*const CryIf_CertificateParse_acpfct[]) (uint32 cryIfKeyId);

//Crypto_CertificateVerify function pointers
extern Std_ReturnType (*const CryIf_CertificateVerify_acpfct[]) (uint32 cryIfKeyId, uint32 verifyCryIfKeyId,
                       Crypto_VerifyResultType* verifyPtr);

//Crypto_Rb_StorePermanentData function pointers
extern Std_ReturnType (*const CryIf_Rb_StorePermanentData_acpfct[]) (void);

#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
#include "CryIf_MemMap.h"
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/

/**
 ***********************************************************************************************************************
 * CryIf_Prv_IsInitialized
 * \brief  The function returns the global init state of the component.
 * \return boolean     Init state: TRUE, FALSE
 ***********************************************************************************************************************
*/
LOCAL_INLINE boolean CryIf_Prv_IsInitialized(void)
{
    return(CryIf_Initialized_b);
}

/**
 **********************************************************************************************************************
 * CryIf_Prv_IsKeyIdInRange
 * \brief check to enable prevention out-of-bounds access for key mapping array
 * \param  keyId_u32     id of the key
 * \return boolean       TRUE: Ok  FALSE: Not ok
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean CryIf_Prv_IsKeyIdInRange(uint32 keyId_u32)
{
    return (keyId_u32 < CRYIF_CFG_KEY_COUNT);
}

/**
 **********************************************************************************************************************
 * CryIf_Prv_IsChannelIdInRange
 * \brief check to enable prevention out-of-bounds access for Channel/DriverObjectId mapping array
 * \param  channelId_u32  id of the channel
 * \return boolean        TRUE: Ok  FALSE: Not ok
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean CryIf_Prv_IsChannelIdInRange(uint32 channelId_u32)
{
    return (channelId_u32 < CRYIF_CFG_CHANNEL_COUNT);
}


#endif /* CRYIF_PRV_H */

