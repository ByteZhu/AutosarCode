/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Private source file providing helper functionality.
 * \addtogroup SecOC
 */


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"
#include "SecOC_Prv.h"
#include "SecOC_Prv_PduRIF.h"
#include "Rte_SecOC.h"
#include "Csm.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"

/**
 ***************************************************************************************************
 * SecOC_Prv_MemZero
 *
 * The function cleares the given number of bytes at the destination address.
 *
 * \param[in,out]  void* const dst_cpv      destination address
 *
 * \param[in]      uint32 length_u32        number of bytes to be cleared
 ***************************************************************************************************
 */
void SecOC_Prv_MemZero(void* const dst_cpv, uint32 length_u32)
{
    volatile uint8* dst_pvu8;
    volatile uint32* dst_pvu32;
    volatile uint16* dst_pvu16;


    /* MR12 RULE 11.4, 11.6 VIOLATION: Casting void pointer to check alignment */
    if ((0U == ((uint32)dst_cpv & 0x03U)) &&
        (length_u32 >= 4U))
    {
        /* MR12 RULE 11.5 VIOLATION: Casting volatile uint32 pointer type to do simple memory manipulation */
        dst_pvu32 = (volatile uint32*)dst_cpv;      // prevent compiler optimization

        /* memset as much bytes as possible with uint32 */
        do
        {
            *dst_pvu32 = 0U;
            dst_pvu32++;
            length_u32 -= 4U;
        } while (length_u32 >= 4U);

        /* MR12 RULE 11.3 VIOLATION: Casting from stricter alignment back to a less strict alignment */
        dst_pvu8 = (volatile uint8*)dst_pvu32;
    }
    /* if memset with uint32 is not possible, try to memset with uint16 */
    /* dst must be 2 byte aligned */
    /* MR12 RULE 11.4, 11.6 VIOLATION: Casting void pointer to check alignment */
    else if ((0U == ((uint32)dst_cpv & 0x01U)) &&
             (length_u32 >= 2U))
    {
        /* MR12 RULE 11.5 VIOLATION: Casting volatile uint16 pointer type to do simple memory manipulation */
        dst_pvu16 = (volatile uint16*)dst_cpv;      // prevent compiler optimization

        /* memset as much bytes as possible with uint16 */
        do
        {
            *dst_pvu16 = 0U;
            dst_pvu16++;
            length_u32 -= 2U;
        } while (length_u32 >= 2U);

        /* MR12 RULE 11.3 VIOLATION: Casting from stricter alignment back to a less strict alignment */
        dst_pvu8 = (volatile uint8*)dst_pvu16;
    }
    else
    {
        /* MR12 RULE 11.5 VIOLATION: Casting to uint8 pointer for byte to byte memset */
        dst_pvu8 = (volatile uint8*)dst_cpv;
    }

    /* memset rest of data byte by byte */
    while (length_u32 > 0U)
    {
        *dst_pvu8 = 0U;
        dst_pvu8++;
        length_u32--;
    }
}

/**
 ***************************************************************************************************
 * SecOC_Prv_MemCopy
 *
 * The function first checks if the input pointers are valid. If the pointers are null pointers
 * the function returns with E_NOT_OK. Otherwise it copies the given number of bytes from the
 * source address to the destination address.
 *
 * \param[out]  void*         dst_p         destination address
 *
 * \param[in]   const void*   src_p         source address
 *
 * \param[in]   uint32        length_u32    number of bytes to be copied
 *
 ***************************************************************************************************
 */
/* MR12 RULE 8.7 VIOLATION: Function is called in SecOC_Prv.c and in TestCd_SecOC */
void SecOC_Prv_MemCopy(void* dst_p,
                       const void* src_p,
                       uint32 length_u32)
{
    uint8* dst_pu8;
    const uint8* src_pu8;


    /* MR12 RULE 11.4, 11.6 VIOLATION: Casting void pointer to check alignment */
    if (0U == (( (uint32) dst_p | (uint32) src_p) & 0x03U))
    {
        /* MR12 RULE 11.5 VIOLATION: Casting pointer to bigger type for efficient memcopy */
        uint32* dst_pu32 = (uint32*)dst_p;
        /* MR12 RULE 11.5 VIOLATION: Casting pointer to bigger type for efficient memcopy */
        const uint32* src_pu32 = (const uint32*)src_p;

        /* copy as much bytes as possible with uint32 */
        while (length_u32 >= 4U)
        {
            /* MR12 RULE 1.3, 18.1, Dir 4.1 VIOLATION: It is ensured that the pointer values are correct by calling functions */
            *dst_pu32 = *src_pu32;
            dst_pu32++;
            src_pu32++;
            length_u32 -= 4U;
        }
        /* MR12 RULE 11.3 VIOLATION: Casting from stricter alignment back to a less strict alignment */
        dst_pu8 = (uint8*)dst_pu32;
        /* MR12 RULE 11.3 VIOLATION: Casting from stricter alignment back to a less strict alignment */
        src_pu8 = (const uint8*)src_pu32;
    }
    /* if copy with uint32 is not possible, try to copy with uint16 */
    /* src and dst must be 2 byte aligned */
    /* MR12 RULE 11.4, 11.6 VIOLATION: Casting void pointer to check alignment */
    else if (0U == (( (uint32) dst_p | (uint32) src_p) & 0x01U))
    {
        /* MR12 RULE 11.5 VIOLATION: Casting pointer to bigger type for efficient memcopy */
        uint16* dst_pu16 = (uint16*) dst_p;
        /* MR12 RULE 11.5 VIOLATION: Casting pointer to bigger type for efficient memcopy */
        const uint16* src_pu16 = (const uint16*) src_p;

        /* copy as much bytes as possible with uint16 */
        while (length_u32 >= 2U)
        {
            *dst_pu16 = *src_pu16;
            dst_pu16++;
            src_pu16++;
            length_u32 -= 2U;
        }
        /* MR12 RULE 11.3 VIOLATION: Casting from stricter alignment back to a less strict alignment */
        dst_pu8 = (uint8*)dst_pu16;
        /* MR12 RULE 11.3 VIOLATION: Casting from stricter alignment back to a less strict alignment */
        src_pu8 = (const uint8*)src_pu16;
    }
    else
    {
        /* MR12 RULE 11.5 VIOLATION: Casting to uint8 pointer for byte to byte copy*/
        dst_pu8 = (uint8*)dst_p;
        /* MR12 RULE 11.5 VIOLATION: Casting to uint8 pointer for byte to byte copy*/
        src_pu8 = (const uint8*)src_p;
    }

    /* copy rest of data byte by byte */
    while (length_u32 > 0U)
    {
        *dst_pu8 = *src_pu8;
        dst_pu8++;
        src_pu8++;
        length_u32--;
    }
}

/**
 ***************************************************************************************************
 * SecOC_Prv_CopyBits
 *
 * Internal function used for copying bits between two bit arrays (represented by uint8 arrays)
 *
 * \param[out]       uint8*  dst_pu8              Destination of the copy bit operation
 * \param[in]        uint32  dstBitPosition_u32   Position within the destination bit array, 0-based in bits
 * \param[in]  const uint8*  src_pcu8             Source of the copy bit operation
 * \param[in]        uint32  srcBitPosition_u32   Position within the source bit array, 0-based in bits
 * \param[in]        uint32  bitLength_u32        Amount of bits to be copied from source to destination
 *

 ***************************************************************************************************
*/
void SecOC_Prv_CopyBits(uint8* dst_pu8,
                        uint32 dstBitPosition_u32,
                        const uint8* src_pcu8,
                        uint32 srcBitPosition_u32,
                        uint32 bitLength_u32)
{
    uint32 srcPos_u32 = srcBitPosition_u32; /* Copy to local variable because we're not allowed to modify parameters. */
    uint32 bitCountLeft_u32 = bitLength_u32; /* Amount of bits left to be extracted from the source array, we can't use
                                                the bitLength parameter directly, because we're not allowed to modify
                                                function arguments. */
    uint32 dstbitPos_u8 = dstBitPosition_u32; /* Copy to local variable because we're not allowed to modify parameters. */
    uint32 srcPosByte_u32; /* Byte index in the source array */
    uint8 srcPosBit_u8; /* Bit position inside one source byte */
    uint8 bitMask_u8 = 0u; /* Bit mask applied to the source byte after extraction, used to mask out unwanted bits. */
    uint8 extractBitCount_u8 = 0u; /* Holds the amount of bits to be extracted from the current source byte. */
    uint8 bufferBits_u8 = 0u; /* Amount of bits collected in bitBuffer_u8 */
    uint8 bitBuffer_u8 = 0u; /* Temporary buffer to collect bits from the source array. */


    if (((dstBitPosition_u32 % 8u) == 0u) &&
        ((srcBitPosition_u32 % 8u) == 0u) &&
        ((bitLength_u32 % 8u) == 0u))
    {
        /* MR12 DIR 1.1 VIOLATION: Cast is safe, converting from uint8* to void* to uint8* (inside MemCopy) */
        SecOC_Prv_MemCopy(&dst_pu8[dstBitPosition_u32 / 8u],
                          &src_pcu8[srcBitPosition_u32 / 8u],
                          bitLength_u32 / 8u );
    }
    else
    {
        while (bitCountLeft_u32 > 0u)
        {
            srcPosBit_u8 = (uint8)(srcPos_u32 & 7u); /* Lowest 3 bits of the source position is the bit position in the source byte. */
            srcPosByte_u32 = srcPos_u32 >> 3u;       /* Upper 13 bits of the source position is the byte index in the source array. */

            extractBitCount_u8 = 8u - srcPosBit_u8; /* Ideally, we can extract all remaining bits from the source byte,
                                                     * depending on the bit position. */

            /* Restrict the amount of bits to be extracted to the amount of free bits in the bit buffer */
            if (srcPosBit_u8 < bufferBits_u8)
            {
                extractBitCount_u8 = 8u - bufferBits_u8;
            }

            /* Restrict the amount of bits to be extracted to the amount of bits left to be extracted in total. */
            if (extractBitCount_u8 > bitCountLeft_u32)
            {
                /* No truncation because the previous value of extractBitCount_u8 was already bigger than bitCountLeft_u32 */
                extractBitCount_u8 = (uint8) bitCountLeft_u32;
            }

            /* Mask for the source bits. Sets 'extractBitCount_u8' amount of '1' bits. */
            bitMask_u8 = (uint8)(1u << extractBitCount_u8) - 1u;

            /* Make room in the bit buffer */
            bitBuffer_u8 = (uint8)(bitBuffer_u8 << extractBitCount_u8);

            /* Add bits to the bit buffer */
            bitBuffer_u8 = bitBuffer_u8 | ((uint8)(src_pcu8[srcPosByte_u32] >> (8u - srcPosBit_u8 - extractBitCount_u8))
                                          & bitMask_u8);

            /* Adjust counters */
            bufferBits_u8 = bufferBits_u8 + extractBitCount_u8;
            srcPos_u32 = srcPos_u32 + extractBitCount_u8;
            bitCountLeft_u32 = bitCountLeft_u32 - extractBitCount_u8;

            /* If the bit buffer is full, use SecOC_Prv_SetBitsInByteBuffer to place them at the correct location in the
             * destination buffer
             */
            if (8u == bufferBits_u8)
            {
                SecOC_Prv_SetBitsInByteBuffer(dst_pu8, bitBuffer_u8, dstbitPos_u8, 8u);
                dstbitPos_u8 = dstbitPos_u8 + 8u;
                bufferBits_u8 = 0u;
            }
        }

        /* Copy the remaining bits into the destination buffer */
        if (0u != bufferBits_u8)
        {
            SecOC_Prv_SetBitsInByteBuffer(dst_pu8, bitBuffer_u8, dstbitPos_u8, bufferBits_u8);
        }
    }


    return;
}

/**
 ***************************************************************************************************
 * SecOC_Prv_SetBitsInByteBuffer
 *
 * Internal function used for packing the data.
 *
 * \param[out]  dest_pu8     destination buffer
 * \param[in]   src_u8       source byte
 * \param[in]   position_u32 start position of the data in the buffer in bits.
 * \param[in]   size_u8      size of the data in bits (0..8)
 *
 ***************************************************************************************************
*/
void SecOC_Prv_SetBitsInByteBuffer(uint8 *dest_pu8, uint8 src_u8, uint32 position_u32, uint8 size_u8)
{
    /* byte position inside the destination buffer. */
    uint32 bytePos_u32 = position_u32 >> 3u;
    /* 16 bit buffer to store the input data bit-shifted to the correct position. */
    uint16 bitBuffer_u16;
    /* bit position inside the byte of the destination buffer. */
    uint8 bitPos_u8 = (uint8)(position_u32 & 7u);
    /* bit mask for the input bits.  */
    uint8 dataMask_u8 = (uint8)(1u << size_u8) - 1u;
    /* amount of bits we need to shift the input bits inside the 16 bit buffer. */
    uint8 shiftAmount_u8 = (uint8)(16u - bitPos_u8 - size_u8);


    /* Load existing data into buffer */
    bitBuffer_u16 = ((uint16)dest_pu8[bytePos_u32] << (uint16)8u);

    /* Mask out the bits we want to set. */
    bitBuffer_u16 = bitBuffer_u16 & ~((uint16)dataMask_u8 << (uint16)shiftAmount_u8);

    /* Set the bits at the destination. The selected input bits are masked and then bit-shifted to
     * the correct location (calculated in shiftAmount_u8).
     */
    bitBuffer_u16 = bitBuffer_u16 | (((uint16)src_u8 & (uint16)dataMask_u8) << (uint16)shiftAmount_u8);

    /* Store the high-byte of the 16 bit buffer to the current position in the destination buffer. */
    dest_pu8[bytePos_u32] = (uint8) (bitBuffer_u16 >> 8u);

    /* Check if we have 'overflow' bits in the lower byte of the bit buffer, if so,
     * we need to store those in the next byte of the destination buffer. In this case we also need
     * to account for existing bits in the next byte.
     */
    if ((bitPos_u8 + size_u8) > 8u)
    {
        /* Mask out the existing bits */
        dest_pu8[bytePos_u32 + 1u] &= ((uint8)(1u << shiftAmount_u8)) - 1u;

        /* Store overflow bits at next byte. */
        dest_pu8[bytePos_u32 + 1u] |= (uint8)(bitBuffer_u16 & 0xFFu);
    }


    return;
}
#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"
