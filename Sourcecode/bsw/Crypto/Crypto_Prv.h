
#ifndef CRYPTO_PRV_H
#define CRYPTO_PRV_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Crypto_GeneralTypes.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#define CRYPTO_PRV_DER_TAG_INDEX                        0U
#define CRYPTO_PRV_DER_LENGTH_INDEX                     1U
#define CRYPTO_PRV_DER_MINIMUM_HEADER_LENGTH            2U
#define CRYPTO_PRV_RSA_PUBLIC_EXPONENT_LENGTH           4U
#define CRYPTO_PRV_DER_SHORT_FORMAT_MAX_LENGTH          127U
#define CRYPTO_PRV_DER_LONG_FORMAT_BYTE_COUNT_MASK      0x7FU
#define CRYPTO_PRV_DER_INVALID_LENGTH                   0xFFU

// ASN.1 tags and masks (DER encoded)
// constructed tag bit mask
#define CRYPTO_PRV_DER_TAG_CONSTRUCTED_MASK             0x20U
// INTEGER tag
#define CRYPTO_PRV_DER_TAG_INTEGER                      0x02U
// OCTET STRING tag
#define CRYPTO_PRV_DER_TAG_OCTET_STRING                 0x04U
// NULL tag
#define CRYPTO_PRV_DER_TAG_NULL                         0x05U
// OID tag
#define CRYPTO_PRV_DER_TAG_OID                          0x06U
// SEQUENCE tag
#define CRYPTO_PRV_DER_TAG_SEQUENCE                     (CRYPTO_PRV_DER_TAG_CONSTRUCTED_MASK | 0x10U)


// Maximum value for uint32
#define CRYPTO_PRV_MAX_U32_VALUE                        (0xFFFFFFFFUL)


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/

/***********************************************************************************************************************
 * CRYPTO_PRV_U8ARR_TO_U64_LITTLE_ENDIAN
 *
 * \brief   Get uint64 in little-endian format from uint8 array.
 *
 * \param[in]   in_pau8     Pointer to an uint8 array with at least eight bytes.
 * \return                  uint64 integer
 *
 **********************************************************************************************************************/
#define CRYPTO_PRV_U8ARR_TO_U64_LITTLE_ENDIAN(in_pau8) \
    ( ((uint64) ((in_pau8)[7U]) << 56U)  \
    | ((uint64) ((in_pau8)[6U]) << 48U)  \
    | ((uint64) ((in_pau8)[5U]) << 40U)  \
    | ((uint64) ((in_pau8)[4U]) << 32U)  \
    | ((uint64) ((in_pau8)[3U]) << 24U)  \
    | ((uint64) ((in_pau8)[2U]) << 16U)  \
    | ((uint64) ((in_pau8)[1U]) << 8U)   \
    | ((uint64) ((in_pau8)[0U])))

/***********************************************************************************************************************
 * CRYPTO_PRV_U64_TO_U8ARR_LITTLE_ENDIAN
 *
 * \brief   Write uint64 value in little endian format to uint8 array.
 *
 * \param[in]   value_u64   uint64 value
 * \param[in]   ptr_pau8    Pointer to uint8 array with at least 8 elements.
 *
 **********************************************************************************************************************/
#define CRYPTO_PRV_U64_TO_U8ARR_LITTLE_ENDIAN(value_u64, ptr_pau8)\
{                                                     \
    (ptr_pau8)[0U]  =   (uint8) (value_u64);          \
    (ptr_pau8)[1U]  =   (uint8) ((value_u64) >> 8U);  \
    (ptr_pau8)[2U]  =   (uint8) ((value_u64) >> 16U); \
    (ptr_pau8)[3U]  =   (uint8) ((value_u64) >> 24U); \
    (ptr_pau8)[4U]  =   (uint8) ((value_u64) >> 32U); \
    (ptr_pau8)[5U]  =   (uint8) ((value_u64) >> 40U); \
    (ptr_pau8)[6U]  =   (uint8) ((value_u64) >> 48U); \
    (ptr_pau8)[7U]  =   (uint8) ((value_u64) >> 56U); \
}

/***********************************************************************************************************************
 * CRYPTO_PRV_U8ARR_TO_U32_LITTLE_ENDIAN
 *
 * \brief   Get uint32 in little endian format from uint8 array.
 *
 * \param[in]   in_pau8     Pointer to an uint8 array with at least four bytes.
 * \return                  uint32 integer
 *
 **********************************************************************************************************************/
#define CRYPTO_PRV_U8ARR_TO_U32_LITTLE_ENDIAN(in_pau8) \
    ( ((uint32) ((in_pau8)[0U]))  \
    | ((uint32) ((in_pau8)[1U]) << 8U)  \
    | ((uint32) ((in_pau8)[2U]) << 16U)   \
    | ((uint32) ((in_pau8)[3U]) << 24U))

/***********************************************************************************************************************
 * CRYPTO_PRV_U32_TO_U8ARR_LITTLE_ENDIAN
 *
 * \brief   Write uint 32 value in little endian format to uint8 array.
 *
 * \param[in]   value_u32   uint32 value
 * \param[in]   ptr_pau8    Pointer to uint8 array with at least 4 elements.
 *
 **********************************************************************************************************************/
#define CRYPTO_PRV_U32_TO_U8ARR_LITTLE_ENDIAN(value_u32, ptr_pau8)\
{                                                     \
    (ptr_pau8)[0U]  =   (uint8) (value_u32);          \
    (ptr_pau8)[1U]  =   (uint8) ((value_u32) >> 8U);  \
    (ptr_pau8)[2U]  =   (uint8) ((value_u32) >> 16U); \
    (ptr_pau8)[3U]  =   (uint8) ((value_u32) >> 24U); \
}

/***********************************************************************************************************************
 * CRYPTO_PRV_U8ARR_TO_U32_BIG_ENDIAN
 *
 * \brief   Get uint32 in big endian format from uint8 array.
 *
 * \param[in]   in_pau8     Pointer to an uint8 array with at least four bytes.
 * \return                  uint32 integer
 *
 **********************************************************************************************************************/
#define CRYPTO_PRV_U8ARR_TO_U32_BIG_ENDIAN(in_pau8) \
    ( ((uint32) ((in_pau8)[0U]) << 24U)  \
    | ((uint32) ((in_pau8)[1U]) << 16U)  \
    | ((uint32) ((in_pau8)[2U]) << 8U)   \
    | ((uint32) ((in_pau8)[3U])))


/***********************************************************************************************************************
 * CRYPTO_PRV_CHECK_U32_ADD_OVERFLOW
 *
 * \brief   Check whether an overflow occurs when adding two u32 numbers
 *
 * \param[in]   a_u32     uint32 value
 * \param[in]   b_u32     uint32 value
 * \return                boolean TRUE: the addition overflows FALSE: no overflow occurs
 *
 **********************************************************************************************************************/
#define CRYPTO_PRV_CHECK_U32_ADD_OVERFLOW(a_u32, b_u32)  ((a_u32) > (CRYPTO_PRV_MAX_U32_VALUE - (b_u32)))


#endif /* CRYPTO_PRV_H */
