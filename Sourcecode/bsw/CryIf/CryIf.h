/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.CryIf
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CRYIF_H
#define CRYIF_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
//TRACE[SWS_CryIf_00008]
#include "Csm_Types.h"
#include "CryIf_Cfg.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/* Publish module IDs */
#define CRYIF_VENDOR_ID                   (6)
#define CRYIF_MODULE_ID                   (112)
#define CRYIF_INSTANCE_ID                 (0)

/* Publish Autosar versions */
#define CRYIF_AR_RELEASE_MAJOR_VERSION    (4)
#define CRYIF_AR_RELEASE_MINOR_VERSION    (5)
#define CRYIF_AR_RELEASE_REVISION_VERSION (0)

/* Publish sofware version numbers */
#define CRYIF_SW_MAJOR_VERSION            (2U)
#define CRYIF_SW_MINOR_VERSION            (0U)
#define CRYIF_SW_PATCH_VERSION            (0U)

/* Service IDs for DET interface */
#define CRYIF_SERVICE_ID_INIT                        (0x00U)
#define CRYIF_SERVICE_ID_GET_VERSION_INFO            (0x01U)
#define CRYIF_SERVICE_ID_PROCESS_JOB                 (0x03U)
#define CRYIF_SERVICE_ID_CANCEL_JOB                  (0x0EU)
#define CRYIF_SERVICE_ID_KEY_ELEMENT_SET             (0x04U)
#define CRYIF_SERVICE_ID_KEY_SET_VALID               (0x05U)
#define CRYIF_SERVICE_ID_KEY_ELEMENT_GET             (0x06U)
#define CRYIF_SERVICE_ID_KEY_ELEMENT_COPY            (0x0FU)
#define CRYIF_SERVICE_ID_KEY_COPY                    (0x10U)
#define CRYIF_SERVICE_ID_RANDOM_SEED                 (0x07U)
#define CRYIF_SERVICE_ID_KEY_GENERATE                (0x08U)
#define CRYIF_SERVICE_ID_KEY_DERIVE                  (0x09U)
#define CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_PUB_VAL   (0x0AU)
#define CRYIF_SERVICE_ID_KEY_EXCHANGE_CALC_SECRET    (0x0BU)
#define CRYIF_SERVICE_ID_CERTIFICATE_PARSE           (0x0CU)
#define CRYIF_SERVICE_ID_CERTIFICATE_VERIFY          (0x11U)
#define CRYIF_SERVICE_ID_CALLBACK_NOTIFICATION       (0x0DU)
#define CRYIF_SERVICE_ID_KEY_ELEMENT_COPY_PARTIAL    (0x12U)
#define CRYIF_SERVICE_ID_KEY_GET_STATUS              (0x13U)
#define RBA_CRYIF_SERVICE_ID_GENERIC                 (0xFFU)


/* DET Error IDs */
//TRACE[SWS_CryIf_00009]
#define CRYIF_E_UNINIT                        (0x00U)   /* API request called before initialization of Crypto Intf. */
#define CRYIF_E_INIT_FAILED                   (0x01U)   /* Initiation of Crypto Interface */
#define CRYIF_E_PARAM_POINTER                 (0x02U)   /* API request called with invalid parameter (Nullpointer). */
#define CRYIF_E_PARAM_HANDLE                  (0x03U)   /* API request called with invalid parameter (out of range). */
#define CRYIF_E_PARAM_VALUE                   (0x04U)   /* API request called with invalid parameter (invalid value). */
#define CRYIF_E_KEY_SIZE_MISMATCH             (0x05U)   /* Source key element size does not match the */
                                                        /* target key elements size. */
//Extended Errors
#define RBA_CRYIF_E_FUNCTION_UNAVAILABLE      (0xFFU)   /* Referenced crypto function unavailable */
#define RBA_CRYIF_E_NOT_SUPPORTED             (0xFEU)   /* Requested operation not supported */


/* Defines used for Testframework configuration */
#define CRYIF_PRV_TEST_GETVERSIONINFO     STD_OFF

/* Warning "unused parameter",
 * systematically produced as the abstract interfaces (if) have more parameters than the specific ones */
#define CRYIF_PARAM_UNUSED(param)          (void)(param)

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/* Configuration data structure of CryIf module */
//TRACE[SWS_CryIf_91118]
typedef struct
{
   uint8 dummy_u8;
} CryIf_ConfigType;

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/
#define CRYIF_START_SEC_CODE
#include "CryIf_MemMap.h"

//General Interface
extern void CryIf_Init(const CryIf_ConfigType* configPtr);
//Job Processing Interface
extern Std_ReturnType CryIf_ProcessJob(uint32 channelId, Crypto_JobType* job);
extern Std_ReturnType CryIf_CancelJob(uint32 channelId, Crypto_JobType* job);
//Call-back notifications
extern void CryIf_CallbackNotification(Crypto_JobType* job, Crypto_ResultType result);
//Key Management Interface
extern Std_ReturnType CryIf_KeyElementSet(uint32 cryIfKeyId, uint32 keyElementId, const uint8* keyPtr,
                                          uint32 keyLength);
extern Std_ReturnType CryIf_KeySetValid(uint32 cryIfKeyId);
extern Std_ReturnType CryIf_KeyGetStatus (uint32 cryIfKeyId, Crypto_KeyStatusType* keyStatusPtr);
extern Std_ReturnType CryIf_KeyElementGet(uint32 cryIfKeyId, uint32 keyElementId, uint8* resultPtr,
                                          uint32* resultLengthPtr);
extern Std_ReturnType CryIf_KeyElementCopy(uint32 cryIfKeyId, uint32 keyElementId, uint32 targetCryIfKeyId,
                                           uint32 targetKeyElementId);
extern Std_ReturnType CryIf_KeyElementCopyPartial(uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset,
                                                  uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId);
extern Std_ReturnType CryIf_KeyCopy(uint32 cryIfKeyId, uint32 targetCryIfKeyId);
extern Std_ReturnType CryIf_RandomSeed(uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength);
extern Std_ReturnType CryIf_KeyGenerate(uint32 cryIfKeyId);
extern Std_ReturnType CryIf_KeyDerive(uint32 cryIfKeyId, uint32 targetCryIfKeyId);
extern Std_ReturnType CryIf_KeyExchangeCalcPubVal(uint32 cryIfKeyId, uint8* publicValuePtr,
                                                  uint32* publicValueLengthPtr);
extern Std_ReturnType CryIf_KeyExchangeCalcSecret(uint32 cryIfKeyId, const uint8* partnerPublicValuePtr,
                                                  uint32 partnerPublicValueLength);
extern Std_ReturnType CryIf_CertificateParse(uint32 cryIfKeyId);
extern Std_ReturnType CryIf_CertificateVerify(uint32 cryIfKeyId, uint32 verifyCryIfKeyId,
                                              Crypto_VerifyResultType* verifyPtr);
extern Std_ReturnType CryIf_Rb_StorePermanentData(void);

#define CRYIF_STOP_SEC_CODE
#include "CryIf_MemMap.h"

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/

#endif /* CRYIF_H */
