
#ifndef CRYPTO_GENERALTYPES_H
#define CRYPTO_GENERALTYPES_H


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Std_Types.h"
#include "Rte_Csm_Type.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

typedef uint8 Crypto_ReturnType;

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

//TRACE[SWS_Csm_Rb_06489]
#define CRYPTO_E_PENDING                0x02U

/* Curve OID length */
#define CRYPTO_OID_NIST_P256_LENGTH     8U
#define CRYPTO_OID_NIST_P384_LENGTH     5U


/* Key element index definitions */
//TRACE[SWS_Csm_01022][SWS_Csm_Rb_01022][SWS_Csm_00952]
//Mac
#define CRYPTO_KE_MAC_KEY                           1U
#define CRYPTO_KE_MAC_PROOF                         2U
#define CRYPTO_KE_KEYGENERATE_SEED                  16U
//Signature
#define CRYPTO_KE_SIGNATURE_KEY                     1U
#define CRYPTO_KE_SIGNATURE_CURVETYPE               29U
#define CRYPTO_KE_SIGNATURE_SALT                    1001U
//Random
#define CRYPTO_KE_RANDOM_SEED                       2U
#define CRYPTO_KE_RANDOM_SEED_STATE                 3U
#define CRYPTO_KE_RANDOM_ALGORITHM                  4U
//Cipher/AEAD
#define CRYPTO_KE_CIPHER_KEY                        1U
#define CRYPTO_KE_CIPHER_IV                         5U
#define CRYPTO_KE_CIPHER_PROOF                      6U
#define CRYPTO_KE_CIPHER_2NDKEY                     7U
//Key Exchange
#define CRYPTO_KE_KEYEXCHANGE_BASE                  8U
#define CRYPTO_KE_KEYEXCHANGE_PRIVKEY               9U
#define CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY             10U
#define CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE           1U
#define CRYPTO_KE_KEYEXCHANGE_ALGORITHM             12U
#define CRYPTO_KE_KEYEXCHANGE_CURVETYPE             29U
//Key Derivation
#define CRYPTO_KE_KEYDERIVATION_PASSWORD            1U
#define CRYPTO_KE_KEYDERIVATION_SALT                13U
#define CRYPTO_KE_KEYDERIVATION_ITERATIONS          14U
#define CRYPTO_KE_KEYDERIVATION_ALGORITHM           15U
#define CRYPTO_KE_KEYDERIVATION_CURVETYPE           29U
#define CRYPTO_KE_KEYDERIVATION_RB_INFO             1002U
//Key Generate
#define CRYPTO_KE_KEYGENERATE_KEY                   1U
#define CRYPTO_KE_KEYGENERATE_SEED                  16U
#define CRYPTO_KE_KEYGENERATE_ALGORITHM             17U
#define CRYPTO_KE_KEYGENERATE_CURVETYPE             29U
//Certificate Parsing
#define CRYPTO_KE_CERTIFICATE_DATA                  0U
#define CRYPTO_KE_CERTIFICATE_PARSING_FORMAT        18U
#define CRYPTO_KE_CERTIFICATE_CURRENT_TIME          19U
#define CRYPTO_KE_CERTIFICATE_VERSION               20U
#define CRYPTO_KE_CERTIFICATE_SERIALNUMBER          21U
#define CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM   22U
#define CRYPTO_KE_CERTIFICATE_ISSUER                23U
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE   24U
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER    25U
#define CRYPTO_KE_CERTIFICATE_SUBJECT               26U
#define CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY    1U
#define CRYPTO_KE_CERTIFICATE_EXTENSIONS            27U
#define CRYPTO_KE_CERTIFICATE_SIGNATURE             28U
#define CRYPTO_KE_CERTIFICATE_DATA_HOST             1000U

/* Algorithm Key element value definitions */
#define CRYPTO_RB_ALGOVAL_KDFX963        0x25U
#define CRYPTO_RB_ALGOVAL_HKDF_SHA256    0x30U

//[ECUC_Crypto_00024]
/* read access */
#define CRYPTO_RA_ALLOWED               0x00U
#define CRYPTO_RA_ENCRYPTED             0x01U
#define CRYPTO_RA_INTERNAL_COPY         0x02U
#define CRYPTO_RA_DENIED                0x03U

//[ECUC_Crypto_00027]
/* write access */
#define CRYPTO_WA_ALLOWED               0x00U
#define CRYPTO_WA_ENCRYPTED             0x01U
#define CRYPTO_WA_INTERNAL_COPY         0x02U
#define CRYPTO_WA_DENIED                0x03U

/* Invalid priority level */
#define CRYPTO_INVALID_PRIO_LEVEL       0xFFFFFFFFU

/* Key and element lengths */
#define CRYPTO_MAC_KEY_LENGTH                                      128U
#define CRYPTO_HMAC_SHA160_MIN_KEY_LENGTH                          80U
#define CRYPTO_HMAC_SHA256_MIN_KEY_LENGTH                          128U
#define CRYPTO_HMAC_SHA512_MIN_KEY_LENGTH                          256U
#define CRYPTO_MAC_POLY1305_KEY_LENGTH                             256U

#define CRYPTO_AES128_KEY_LENGTH                                   128U
#define CRYPTO_AES192_KEY_LENGTH                                   192U
#define CRYPTO_AES256_KEY_LENGTH                                   256U

#define CRYPTO_EDDSA_ED25519_KEY_LENGTH                            256U
#define CRYPTO_ECDSA_SECP384R1_PRIV_KEY_LENGTH                     384U
#define CRYPTO_ECDSA_SECP384R1_PUB_KEY_LENGTH                     (2U * CRYPTO_ECDSA_SECP384R1_PRIV_KEY_LENGTH)
#define CRYPTO_ECDSA_SECP256R1_PRIV_KEY_LENGTH                     256U
#define CRYPTO_ECDSA_SECP256R1_PUB_KEY_LENGTH                     (2U * CRYPTO_ECDSA_SECP256R1_PRIV_KEY_LENGTH)
#define CRYPTO_RSA2048_PRIV_KEY_LENGTH                            (2U * 2048U)
#define CRYPTO_RSA2048_PUB_KEY_LENGTH                             (2048U + 32U)
#define CRYPTO_RSA3072_PRIV_KEY_LENGTH                            (2U * 3072U)
#define CRYPTO_RSA3072_PUB_KEY_LENGTH                             (3072U + 32U)
#define CRYPTO_RSA4096_PRIV_KEY_LENGTH                            (2U * 4096U)
#define CRYPTO_RSA4096_PUB_KEY_LENGTH                             (4096U + 32U)
#define CRYPTO_RSA_SALT_LENGTH                                    (32U)

#define CRYPTO_RSA2048_MODULUS_LENGTH                              256U
#define CRYPTO_RSA2048_PRIV_EXP_LENGTH                             256U
#define CRYPTO_RSA3072_MODULUS_LENGTH                              384U
#define CRYPTO_RSA3072_PRIV_EXP_LENGTH                             384U
#define CRYPTO_RSA4096_MODULUS_LENGTH                              512U
#define CRYPTO_RSA4096_PRIV_EXP_LENGTH                             512U
#define CRYPTO_RSA_PUB_EXPONENT_LENGTH                             4U

/* Error flags */
//TRACE[SWS_Csm_91043]TRACE[SWS_Csm_91044]
#ifndef CRYPTO_E_BUSY                           // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_BUSY                   2U      /* The service request failed because the service is still busy. */
#endif
#ifndef CRYPTO_E_ENTROPY_EXHAUSTED              // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_ENTROPY_EXHAUSTED      3U      /* The service request failed because the entropy of the random number
                                                   generator is exhausted. */
#endif
#ifndef CRYPTO_E_RE_NVM_ACCESS_FAILED           // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_RE_NVM_ACCESS_FAILED   4U      /* The service request failed because NVM access failed. */
#endif
#ifndef CRYPTO_E_KEY_READ_FAIL                  // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_KEY_READ_FAIL          6U      /* The service request failed because read access failed. */
#endif
#ifndef CRYPTO_E_KEY_WRITE_FAIL                 // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_KEY_WRITE_FAIL         7U      /* The service request failed because write access failed. */
#endif
#ifndef CRYPTO_E_KEY_NOT_AVAILABLE              // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_KEY_NOT_AVAILABLE      8U      /* The service request failed because the key is not available. */
#endif
#ifndef CRYPTO_E_KEY_NOT_VALID                  // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_KEY_NOT_VALID          9U      /* The service request failed because at least one needed key element
                                                   is invalid. */
#endif
#ifndef CRYPTO_E_KEY_SIZE_MISMATCH              // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_KEY_SIZE_MISMATCH      10U     /* The service request failed because the key element is not partially
                                                   accessible and the provided key element length is too short or too
                                                   long for that key element. */
#endif
#ifndef CRYPTO_E_JOB_CANCELED                   // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_JOB_CANCELED           12U     /* The job request was canceled. */
#endif
#ifndef CRYPTO_E_KEY_EMPTY                      // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_KEY_EMPTY              13U     /* The service request failed because of uninitialized source key element. */
#endif

/* SHE ERC codes - derived from SHE HIS Specification v1.1 */
#ifndef RBA_CRYPTO_E_SHE_NO_ERROR                       // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_NO_ERROR               0u      /* SHE request successful (same value as E_OK) - ERC_NO_ERROR */
#endif
#ifndef RBA_CRYPTO_E_SHE_BUSY                           // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_BUSY                   2u      /* SHE request failed, service is still busy (same value as CRYPTO_E_BUSY) - ERC_BUSY */
#endif
#ifndef RBA_CRYPTO_E_SHE_GENERAL_ERROR                  // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_GENERAL_ERROR          34u     /* SHE general error - ERC_GENERAL_ERROR */
#endif
#ifndef RBA_CRYPTO_E_SHE_KEY_EMPTY                      // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_KEY_EMPTY              35u     /* SHE key empty error - ERC_KEY_EMPTY */
#endif
#ifndef RBA_CRYPTO_E_SHE_KEY_INVALID                    // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_KEY_INVALID            36U     /* SHE key invalid error - ERC_KEY_INVALID */
#endif
#ifndef RBA_CRYPTO_E_SHE_KEY_NOT_AVAILABLE              // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_KEY_NOT_AVAILABLE      37U     /* SHE key not available error - ERC_KEY_NOT_AVAILABLE */
#endif
#ifndef RBA_CRYPTO_E_SHE_KEY_UPDATE_ERROR               // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_KEY_UPDATE_ERROR       38U     /* SHE key update error - ERC_KEY_UPDATE_ERROR */
#endif
#ifndef RBA_CRYPTO_E_SHE_KEY_WRITE_PROTECTED            // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_KEY_WRITE_PROTECTED    39U     /* SHE key write protected error - ERC_KEY_WRITE_PROTECTED */
#endif
#ifndef RBA_CRYPTO_E_SHE_MEMORY_FAILURE                 // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_MEMORY_FAILURE         40U     /* SHE memory failure error - ERC_MEMORY_FAILURE */
#endif
#ifndef RBA_CRYPTO_E_SHE_SEQUENCE_ERROR                 // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define RBA_CRYPTO_E_SHE_SEQUENCE_ERROR         44U     /* SHE sequence error - ERC_SEQUENCE_ERROR */
#endif

// Crypto_OperationModeType values
//TRACE[SWS_Csm_01029]
#ifndef CRYPTO_OPERATIONMODE_START                  // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_OPERATIONMODE_START        0x01U     /* Operation Mode is "Start". The job's state shall be reset, i.e.
                                                       previous input data and intermediate results shall be deleted. */
#endif
#ifndef CRYPTO_OPERATIONMODE_UPDATE                 // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_OPERATIONMODE_UPDATE       0x02U     /* Operation Mode is "Update". Used to calculate
                                                       intermediate results. */
#endif
#ifndef CRYPTO_OPERATIONMODE_STREAMSTART            // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_OPERATIONMODE_STREAMSTART  0x03U     /* Operation Mode is "Stream Start". Mixture of "Start" and "Update"
                                                       Used for streaming. */
#endif
#ifndef CRYPTO_OPERATIONMODE_FINISH                 // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_OPERATIONMODE_FINISH       0x04U     /* Operation Mode is "Finish". The calculations shall be finalized*/
#endif
#ifndef CRYPTO_OPERATIONMODE_SINGLECALL             // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_OPERATIONMODE_SINGLECALL   0x07U     /* Operation Mode is "Single Call". Mixture of "Start", "Update" and
                                                       "Finish". */
#endif
/* Crypto_VerifyResultType values */
//TRACE[SWS_Csm_01024]
#ifndef CRYPTO_E_VER_OK      // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_VER_OK           0x00U         /* The result of the verification is "true", i.e. the two compared
                                                   elements are identical. This return code shall be given as
                                                   value "0" */
#endif
#ifndef CRYPTO_E_VER_NOT_OK  // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_E_VER_NOT_OK       0x01U         /* The result of the verification is "false", i.e. the two compared
                                                   elements are not identical. This return code shall be given as
                                                   value "1". */
#endif

/* Crypto_KeyStatusType values */
//TRACE[SWS_Csm_91102]
#ifndef CRYPTO_KEYSTATUS_INVALID                             // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_KEYSTATUS_INVALID                0x00U        /* The status of the key is invalid.
                                                                This return code shall be given as value "0" */
#endif
#ifndef CRYPTO_KEYSTATUS_VALID                               // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_KEYSTATUS_VALID                  0x01U        /* The status of the key is valid.
                                                                This return code shall be given as value "1". */
#endif
#ifndef CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS                  // May be already defined in Rte_Csm_Type.h if used in RTE Interface
#define CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS     0x02U        /* The key is was changed but still awaiting an NvM write.
                                                                This return code shall be given as value "2". */
#endif

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/
//TRACE[SWS_Crypto_00042]

/* Enumeration of the algorithm family. */
//TRACE[SWS_Csm_01047][SWS_Csm_Rb_01047]
typedef enum
{
    CRYPTO_ALGOFAM_NOT_SET                          = 0x00,    /* Algorithm family is not set */
    CRYPTO_ALGOFAM_SHA1                             = 0x01,    /* SHA1 hash                   */
    CRYPTO_ALGOFAM_SHA2_224                         = 0x02,    /* SHA2-224 hash               */
    CRYPTO_ALGOFAM_SHA2_256                         = 0x03,    /* SHA2-256 hash               */
    CRYPTO_ALGOFAM_SHA2_384                         = 0x04,    /* SHA2-384 hash               */
    CRYPTO_ALGOFAM_SHA2_512                         = 0x05,    /* SHA2-512 hash               */
    CRYPTO_ALGOFAM_SHA2_512_224                     = 0x06,    /* SHA2-512/224 hash           */
    CRYPTO_ALGOFAM_SHA2_512_256                     = 0x07,    /* SHA2-512/256 hash           */
    CRYPTO_ALGOFAM_SHA3_224                         = 0x08,    /* SHA3-224 hash               */
    CRYPTO_ALGOFAM_SHA3_256                         = 0x09,    /* SHA3-256 hash               */
    CRYPTO_ALGOFAM_SHA3_384                         = 0x0A,    /* SHA3-384 hash               */
    CRYPTO_ALGOFAM_SHA3_512                         = 0x0B,    /* SHA3-512 hash               */
    CRYPTO_ALGOFAM_SHAKE128                         = 0x0C,    /* SHAKE128 hash               */
    CRYPTO_ALGOFAM_SHAKE256                         = 0x0D,    /* SHAKE256 hash               */
    CRYPTO_ALGOFAM_RIPEMD160                        = 0x0E,    /* RIPEMD hash                 */
    CRYPTO_ALGOFAM_BLAKE_1_256                      = 0x0F,    /* BLAKE-1-256 hash            */
    CRYPTO_ALGOFAM_BLAKE_1_512                      = 0x10,    /* BLAKE-1-512 hash            */
    CRYPTO_ALGOFAM_BLAKE_2s_256                     = 0x11,    /* BLAKE-2s-256 hash           */
    CRYPTO_ALGOFAM_BLAKE_2s_512                     = 0x12,    /* BLAKE-2s-512 hash           */
    CRYPTO_ALGOFAM_3DES                             = 0x13,    /* 3DES cipher                 */
    CRYPTO_ALGOFAM_AES                              = 0x14,    /* AES cipher                  */
    CRYPTO_ALGOFAM_CHACHA                           = 0x15,    /* ChaCha cipher               */
    CRYPTO_ALGOFAM_RSA                              = 0x16,    /* RSA cipher                  */
    CRYPTO_ALGOFAM_ED25519                          = 0x17,    /* ED25519 elliptic curve      */
    CRYPTO_ALGOFAM_BRAINPOOL                        = 0x18,    /* Brainpool elliptic curve    */
    CRYPTO_ALGOFAM_ECCNIST                          = 0x19,    /* NIST ECC elliptic curves    */
    CRYPTO_ALGOFAM_RNG                              = 0x1B,    /* Random Number Generator     */
    CRYPTO_ALGOFAM_SIPHASH                          = 0x1C,    /* SipHash                     */
    CRYPTO_ALGOFAM_ECCANSI                          = 0x1E,    /* Elliptic curve according to ANSI X9.62 */
    CRYPTO_ALGOFAM_ECCSEC                           = 0x1F,    /* Elliptic curve according to SECG */
    CRYPTO_ALGOFAM_DRBG                             = 0x20,    /* Random number generator according to NIST SP800-90A */
    CRYPTO_ALGOFAM_FIPS186                          = 0x21,    /* Random number generator according to FIPS 186. */
    CRYPTO_ALGOFAM_PADDING_PKCS7                    = 0x22,    /* Cipher padding according to PKCS.7 */
    CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS             = 0x23,    /* Cipher padding mode. Fill/verify data with 0 */
    CRYPTO_ALGOFAM_PBKDF2                           = 0x24,    /* Password-Based Key Derivation Function 2*/
    CRYPTO_ALGOFAM_KDFX963                          = 0x25,    /* ANSI X9.63 Public Key Cryptography */
    CRYPTO_ALGOFAM_DH                               = 0x26,    /* Diffie-Hellman */
    CRYPTO_ALGOFAM_ECDSA                            = 0x2C,    /* Elliptic-curve Digital Signatures */
// preliminary definitions, not yet specified
    CRYPTO_ALGOFAM_ECDSA_SECP384R1                  = 0x80,    /* ECDSA with curve secp384r1  */
    CRYPTO_ALGOFAM_ECDSA_SECP256R1                  = 0x81,    /* ECDSA with Curve secp256r1  */
    CRYPTO_ALGOFAM_DETERMINISTIC_ECDSA_SECP384R1    = 0x82,    /* Deterministic ECDSA with curve secp384r1 (RFC  6979)*/
    CRYPTO_ALGOFAM_ECDH                             = 0x83,    /* Diffie-Hellman with Elliptic Curves*/
    CRYPTO_ALGOFAM_EC_CURVE25519                    = 0x84,    /* EC Curve25519 */
    CRYPTO_ALGOFAM_EC_SECP384R1                     = 0x85,    /* EC Curve P384 */
    CRYPTO_ALGOFAM_POLY1305                         = 0x86,    /* POLY1305      */
    CRYPTO_ALGOFAM_HKDF                             = 0x87,    /* HKDF, rfc5869 */
    CRYPTO_ALGOFAM_EC_SECP256R1                     = 0x88,    /* EC Curve P256 */ /* BSWEXT-84 */
    CRYPTO_ALGOFAM_DETERMINISTIC_ECDSA              = 0x89,    /* Deterministic ECDSA with curve secp384r1 (RFC  6979)*/
// end of preliminary definitions
// value must not exceed 0xFF
    CRYPTO_ALGOFAM_CUSTOM                           = 0xFF     /* Custom algorithm family     */
} Crypto_AlgorithmFamilyType;

/* Enumeration of the algorithm mode */
//TRACE[SWS_Csm_01048][SWS_Csm_Rb_01048]
typedef enum
{
    CRYPTO_ALGOMODE_NOT_SET           = 0x00,     /* Algorithm key is not set    */
    CRYPTO_ALGOMODE_ECB               = 0x01,     /* Blockmode: Electronic Code Book */
    CRYPTO_ALGOMODE_CBC               = 0x02,     /* Blockmode: Cipher Block Chaining */
    CRYPTO_ALGOMODE_CFB               = 0x03,     /* Blockmode: Cipher Feedback Mode  */
    CRYPTO_ALGOMODE_OFB               = 0x04,     /* Blockmode: Output Feedback Mode  */
    CRYPTO_ALGOMODE_CTR               = 0x05,     /* Blockmode: Counter Modex  */
    CRYPTO_ALGOMODE_GCM               = 0x06,     /* Blockmode: Galois/Counter Mode */
    CRYPTO_ALGOMODE_XTS               = 0x07,     /* XOR-encryption-based tweaked-codebook mode
                                                     with ciphertext stealing */
    CRYPTO_ALGOMODE_RSAES_OAEP        = 0x08,     /* RSA Optimal Asymmetric Encryption Padding */
    CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5  = 0x09,     /* RSA encryption/decryption with PKCS#1 v1.5 padding */
    CRYPTO_ALGOMODE_RSASSA_PSS        = 0x0A,     /* RSA Probabilistic Signature Scheme */
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 = 0x0B,     /* RSA signature with PKCS#1 v1.5 */
    CRYPTO_ALGOMODE_8ROUNDS           = 0x0C,     /* 8 rounds (e.g. ChaCha8) */
    CRYPTO_ALGOMODE_12ROUNDS          = 0x0D,     /* 12 rounds (e.g. ChaCha12) */
    CRYPTO_ALGOMODE_20ROUNDS          = 0x0E,     /* 20 rounds (e.g. ChaCha20) */
    CRYPTO_ALGOMODE_HMAC              = 0x0F,     /* Hashed-based MAC */
    CRYPTO_ALGOMODE_CMAC              = 0x10,     /* Cipher-based MAC */
    CRYPTO_ALGOMODE_GMAC              = 0x11,     /* Galois MAC */
    CRYPTO_ALGOMODE_CTRDRBG           = 0x12,     /* Counter-based Deterministic Random Bit Generator */
    CRYPTO_ALGOMODE_SIPHASH_2_4       = 0x13,     /* iphash-2-4 */
    CRYPTO_ALGOMODE_SIPHASH_4_8       = 0x14,     /* Siphash-4-8 */
    CRYPTO_ALOGMODE_PXXXR1            = 0x15,     /* ANSI R1 Curve */
// preliminary definitions, not yet specified
    CRYPTO_ALGOMODE_CBC_NONE          = 0xF0,     /* Cipher Block Chaining with no padding */
    CRYPTO_ALGOMODE_CBC_PKCS7_v1_5    = 0xF1,     /* Cipher Block Chaining with PKCS#7 padding */
    CRYPTO_ALGOMODE_CBC_NIST_SP800_38A= 0xF2,     /* Cipher Block Chaining with NIST SP800-38A padding */
    CRYPTO_ALGOMODE_CBC_ZERO          = 0xF3,     /* Cipher Block Chaining with zero padding */
    CRYPTO_ALGOMODE_ECB_NONE          = 0xF4,     /* Electronic Code Book with no padding */
    CRYPTO_ALGOMODE_ECB_PKCS7_v1_5    = 0xF5,     /* Electronic Code Book with PKCS#7 padding */
    CRYPTO_ALGOMODE_ECB_NIST_SP800_38A= 0xF6,     /* Electronic Code Book with NIST SP800-38A padding */
    CRYPTO_ALGOMODE_EXTERNAL_CALLOUT  = 0xF7,     /* External Callout */
    CRYPTO_ALGOMODE_PURE              = 0xF8,     /* Signature pure mode*/
    CRYPTO_ALGOMODE_PREHASHED         = 0xF9,     /* Signature prehashed mode*/
    CRYPTO_ALGOMODE_CUSTOM            = 0xFF      /* Custom algorithm mode */
} Crypto_AlgorithmModeType;

/* Defines which of the input/output parameters are re-directed to a key element.
   The values can be combined to define a bit field.*/
//TRACE[SWS_Csm_91024]
typedef enum
{
    CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT    = 0x01U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT  = 0x02U,
    CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT   = 0x04U,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT   = 0x10U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT = 0x20U
} Crypto_InputOutputRedirectionConfigType;

/* Enumeration of the kind of the service. */
//TRACE[SWS_Csm_Rb_01031]
typedef enum
{
    CRYPTO_HASH                  = 0x00,   /* Hash Service                   */
    CRYPTO_MACGENERATE           = 0x01,   /* MacGenerate Service            */
    CRYPTO_MACVERIFY             = 0x02,   /* MacVerify Service              */
    CRYPTO_ENCRYPT               = 0x03,   /* Encrypt Service                */
    CRYPTO_DECRYPT               = 0x04,   /* Decrypt Service                */
    CRYPTO_AEADENCRYPT           = 0x05,   /* AEADEncrypt Service            */
    CRYPTO_AEADDECRYPT           = 0x06,   /* AEADDecrypt Service            */
    CRYPTO_SIGNATUREGENERATE     = 0x07,   /* SignatureGenerate Service      */
    CRYPTO_SIGNATUREVERIFY       = 0x08,   /* SignatureVerify Service        */
    CRYPTO_RANDOMGENERATE        = 0x0B,   /* RandomGenerate Service         */
    CRYPTO_RANDOMSEED            = 0x0C,   /* RandomSeed Service             */
    CRYPTO_KEYGENERATE           = 0x0D,   /* KeyGenerate Service            */
    CRYPTO_KEYDERIVE             = 0x0E,   /* KeyDerive Service              */
    CRYPTO_KEYEXCHANGECALCPUBVAL = 0x0F,   /* KeyExchangeCalcPubVal Service  */
    CRYPTO_KEYEXCHANGECALCSECRET = 0x10,   /* KeyExchangeCalcSecret Service  */
    CRYPTO_CERTIFICATEPARSE      = 0x11,   /* CertificateParse Service       */
    CRYPTO_CERTIFICATEVERIFY     = 0x12,   /* CertificateVerify Service      */
    CRYPTO_KEYSETVALID           = 0x13,   /* KeySetValid Service            */
    // everything between CRYPTO_SHEGETID and CRYPTO_SHEEXPORTRAMKEY is a block which must not be modified!
    CRYPTO_SHEGETID              = 0x14,   /* SheGetId Service               */
    CRYPTO_SHELOADKEY            = 0x15,   /* SheLoadKey Service             */
    CRYPTO_SHELOADKEYSLOT        = 0x16,   /* SheLoadKeySlot Service         */
    CRYPTO_SHELOADPLAINKEY       = 0x17,   /* SheLoadPlainKey Service        */
    CRYPTO_SHEEXPORTRAMKEY       = 0x18,   /* SheExportRamKey Service        */
    CRYPTO_KEYELEMENTGET         = 0x19,   /* KeyElementGet Service          */
    CRYPTO_KEYELEMENTSET         = 0x1A,   /* KeyElementSet Service          */
    CRYPTO_SERVICETYPE_CUSTOM    = 0x1B    /* Custom service type */
} Crypto_ServiceInfoType;

/* Enumeration of the processing type. */
//TRACE[SWS_Csm_01049]
typedef enum
{
    CRYPTO_PROCESSING_ASYNC = 0x00,        /* Asynchronous job processing */
    CRYPTO_PROCESSING_SYNC  = 0x01         /* Synchronous job processing  */
} Crypto_ProcessingType;

/* Enumeration of the current job state.  */
//TRACE[SWS_Csm_Rb_04943]
// atomic access required
typedef enum
{
    CRYPTO_JOBSTATE_IDLE = 0x00,           /* Job is in the state "idle". This state is reached after Csm_Init() or when
                                              the "Finish" state is finished. */
    CRYPTO_JOBSTATE_ACTIVE = 0x01,         /* Job is in the state "active". There was already some input or there are
                                              intermediate results. This state is reached, when the "update" or "start"
                                              operation finishes. */
    /* RB specific extension */
    CRYPTO_JOBSTATE_WAITING = 0x02,        /* Job executing has been requested and the job is waiting in CryptoStack to
                                              be executed. */
    CRYPTO_JOBSTATE_RUNNING = 0x04,        /* Job is currently executed in Crypto */
    CRYPTO_JOBSTATE_ACTIVE_RUNNING = 0x05  /* Job is currently executed in Crypto. Previous state was ACTIVE */
} Crypto_JobStateType;

/* Structure which determines the exact algorithm. */
//TRACE[SWS_Csm_01008]
typedef struct
{
    uint32 keyLength;                             /* The key length in bits to be used with that algorithm */
    Crypto_AlgorithmFamilyType family;            /* The family of the algorithm */
    Crypto_AlgorithmFamilyType secondaryFamily;   /* The secondary family of the algorithm */
    Crypto_AlgorithmModeType mode;                /* The operation mode to be used with that algorithm */
} Crypto_AlgorithmInfoType;

/* Structure which contains job information */
//TRACE[SWS_Csm_01010]
typedef struct
{
    const uint32 jobId;
    const uint32 jobPriority;        /* Specifies the importance of the job (the higher, the more important) */
} Crypto_JobInfoType;

/* Structure which contains basic information about the crypto primitive */
//TRACE[SWS_Csm_01011]
typedef struct
{
    const uint32 resultLength;                     /* Contains the result length in bytes. */
    const Crypto_ServiceInfoType service;          /* Contains the enum of the used service, e.g. Encrypt */
    const Crypto_AlgorithmInfoType algorithm;      /* Contains the information of the used algorithm */
} Crypto_PrimitiveInfoType;

/* Structure which contains further information, which depends on the job and the crypto primitive. */
//TRACE[SWS_Csm_01012]
typedef struct
{
    const uint32 callbackId;                        /* Identifier of the callback function, to be called, if the
                                                       configured service finished. */
    const Crypto_PrimitiveInfoType *primitiveInfo;  /* Pointer to a structure containing further configuration of the
                                                       crypto primitives */
    const uint32 cryIfKeyId;                        /* Identifier of the CryIf key. */
    const Crypto_ProcessingType processingType;     /* Determines the synchronous or asynchronous behavior. */
} Crypto_JobPrimitiveInfoType;

/* Structure which holds the identifiers of the keys and key elements which shall be used as input and output for a job
   and a bit structure which indicates which buffers shall be redirected to those key elements. */
//TRACE[SWS_Csm_91026]
typedef struct
{
    uint32 inputKeyId;                  /* Identifier of the key which shall be used as input */
    uint32 inputKeyElementId;           /* Identifier of the key element which shall be used as input */
    uint32 secondaryInputKeyId;         /* Identifier of the key which shall be used as secondary input */
    uint32 secondaryInputKeyElementId;  /* Identifier of the key element which shall be used as secondary input */
    uint32 tertiaryInputKeyId;          /* Identifier of the key which shall be used as tertiary input */
    uint32 tertiaryInputKeyElementId;   /* Identifier of the key element which shall be used as tertiary input */
    uint32 outputKeyId;                 /* Identifier of the key which shall be used as output */
    uint32 outputKeyElementId;          /* Identifier of the key element which shall be used as output */
    uint32 secondaryOutputKeyId;        /* Identifier of the key which shall be used as secondary output */
    uint32 secondaryOutputKeyElementId; /* Identifier of the key element which shall be used as secondary output */
    uint8 redirectionConfig;            /* Bit structure which indicates which buffer shall be redirected to a key
                                           element. */
} Crypto_JobRedirectionInfoType;

/* Structure which contains input and output information depending on the job
   and the crypto primitive. */
//TRACE[SWS_Csm_01009][SWS_Csm_Rb_01009]
typedef struct
{
    const uint8 *inputPtr;              /* Pointer to the input data. */
    uint32 inputLength;                 /* Contains the input length in bytes. */
    const uint8 *secondaryInputPtr;     /* Pointer to the secondary input data (for MacVerify, SignatureVerify). */
    uint32 secondaryInputLength;        /* Contains the secondary input length in bytes. */
    const uint8 *tertiaryInputPtr;      /* Pointer to the tertiary input data. */
    uint32 tertiaryInputLength;         /* Contains the tertiary input length in bytes.*/
    uint8  *outputPtr;                  /* Pointer to the output data. */
    uint32 *outputLengthPtr;            /* Holds a pointer to a memory location containing the output length in bytes */
    uint8 *secondaryOutputPtr;          /* Pointer to the secondary output data. */
    uint32 *secondaryOutputLengthPtr;   /* Holds a pointer to a memory location containing the secondary output length in bytes. */
    Crypto_VerifyResultType *verifyPtr; /* Output pointer to a memory location holding a Crypto_VerifyResultType */
    Crypto_OperationModeType mode;      /* Indicator of the mode(s)/operation(s) to be performed */
    uint32 cryIfKeyId;                  /* Holds the CryIf key id for key operation services. */
    uint32 targetCryIfKeyId;            /* Holds the target CryIf key id for key operation services. */
    uint32 keyElementId;                /* Holds the key element id for key operation services. */
    // elements not implemented because unused
    // uint64  input64
    // uint64* output64Ptr
} Crypto_JobPrimitiveInputOutputType;

/* Structure which contains further information, which depends on the job and the crypto primitive. */
//TRACE[SWS_Csm_01013][SWS_Csm_Rb_01013]
typedef struct
{
    const uint32 jobId;                                      /* Identifier for the job structure. */
    const Crypto_JobPrimitiveInfoType *jobPrimitiveInfo;     /* Pointer to a structure containing further information,
                                                                which depends on the job and the crypto primitive */
    const Crypto_JobInfoType *jobInfo;                       /* Pointer to a structure containing further information,
                                                                which depends on the job and the crypto primitive */
    uint32 cryptoKeyId;                                      /* Identifier of the Crypto Driver key. The identifier
                                                                shall be written by the Crypto Interface */
    const Crypto_JobRedirectionInfoType *jobRedirectionInfoRef; /* Pointer to a structure containing further information
                                                                on the usage of keys as input and output for jobs */
    uint32 targetCryptoKeyId;                                /* Target identifier of the Crypto Driver key.
                                                                The identifier shall be written by the Crypto Interface. */
    Crypto_JobPrimitiveInputOutputType jobPrimitiveInputOutput; /* Structure containing input and output information
                                                                   depending on the job and the crypto primitive. */
    Crypto_JobStateType jobState;                            /* Determines the current job state. */
    /* RB specific extension */
    boolean jobCanceled_b;                                   /* Shows if job cancel was requested. */
    boolean callbackFinished_b;                              /* Used for async jobs only:
                                                                Shows if job callback was processed completely. */
    const boolean bufferedCallbackEnabled_cb;                /* Used for async jobs only:
                                                                Indicate if the job result shall be buffered by Csm and
                                                                provided to the upper layer in the context of
                                                                Csm_MainFunction_<instance>. */
    Crypto_ResultType result_en;                             /* Used for async jobs only:
                                                                Stores the result value in order to be processed later
                                                                in the context of Csm_MainFunction_<instance>. */
} Crypto_JobType;

//TRACE[ECUC_Crypto_00041]
typedef enum
{
     CRYPTO_KE_FORMAT_BIN_OCTET                     = 1U,
     CRYPTO_KE_FORMAT_BIN_SHEKEYS                   = 2U,
     CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8    = 3U,
     CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY           = 4U,
     CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY            = 5U,
     CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY             = 6U,
     CRYPTO_KE_FORMAT_BIN_CERT_X509_V3              = 7U,
     CRYPTO_KE_FORMAT_BIN_CERT_CVC                  = 8U
} Crypto_KeyElement_Format_ten;

typedef enum
{
    CRYPTO_ELEMENT_TYPE_SYMMETRIC_128               = 0U,
    CRYPTO_ELEMENT_TYPE_EDDSA_ED25519_PRIV_KEY      = 1U,
    CRYPTO_ELEMENT_TYPE_EDDSA_ED25519_PUB_KEY       = 2U,
    CRYPTO_ELEMENT_TYPE_EDDSA_ED25519_KEYPAIR       = 3U,
    CRYPTO_ELEMENT_TYPE_ECDSA_SECP384R1_PRIV_KEY    = 4U,
    CRYPTO_ELEMENT_TYPE_ECDSA_SECP384R1_PUB_KEY     = 5U,
    CRYPTO_ELEMENT_TYPE_ECDSA_SECP384R1_KEYPAIR     = 6U,
    CRYPTO_ELEMENT_TYPE_ECDSA_SECP256R1_PRIV_KEY    = 7U,
    CRYPTO_ELEMENT_TYPE_ECDSA_SECP256R1_PUB_KEY     = 8U,
    CRYPTO_ELEMENT_TYPE_ECDSA_SECP256R1_KEYPAIR     = 9U,
    CRYPTO_ELEMENT_TYPE_CERT_X509                   = 10U,
    CRYPTO_ELEMENT_TYPE_VKMS_GET_KEY                = 11U,
    CRYPTO_ELEMENT_TYPE_VKMS_GET_METADATA           = 12U,
    CRYPTO_ELEMENT_TYPE_VKMS_GET_STATUS             = 13U,
    CRYPTO_ELEMENT_TYPE_VKMS_GET_TRAININGCOUNTER    = 14U,
    CRYPTO_ELEMENT_TYPE_VKMS_GET_VIN                = 15U,
    CRYPTO_ELEMENT_TYPE_RSA2048_PRIV_KEY            = 16U,
    CRYPTO_ELEMENT_TYPE_RSA2048_PUB_KEY             = 17U,
    CRYPTO_ELEMENT_TYPE_RSA3072_PRIV_KEY            = 18U,
    CRYPTO_ELEMENT_TYPE_RSA3072_PUB_KEY             = 19U,
    CRYPTO_ELEMENT_TYPE_RSA4096_PRIV_KEY            = 20U,
    CRYPTO_ELEMENT_TYPE_RSA4096_PUB_KEY             = 21U
} Crypto_KeyElement_Type_ten;

/* Structure which contains FIFO information, and references the FIFO buffer */
typedef struct
{
    const uint32 fifoSize_cu32;
    Crypto_JobType ** const jobs_apst;       /* client access to job [(writeIndex_vu32 + 1) % request count]
                                                protected by locking writeIndex_vu32 if not in multicore mode */
    volatile uint32 writeIndex_vu32;         /* set in client context, client access locked if not in multicore mode */
    volatile uint32 readIndex_vu32;          /* set in the component's MainFunction context, read in client context;
                                                atomic access required(-> alignment) ! if not in multicore mode */
} Crypto_FIFO_tst;

 /* Structure which contains Queue information, it is a list of FIFOS ordered by priority */
typedef struct
{
    const uint32 levels_cu32;
    Crypto_FIFO_tst * const * const fifos_capst;
} Crypto_Queue_tst;

#endif /* CRYPTO_GENERALTYPES_HTYPES_H */


