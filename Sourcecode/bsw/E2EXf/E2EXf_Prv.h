


#ifndef E2EXF_PRV_H
#define E2EXF_PRV_H

/*
 ***************************************************************************************************
 * Global variables
 ***************************************************************************************************
 */

#define E2EXF_START_SEC_VAR_INIT_BOOLEAN
#include "E2EXf_MemMap.h"
extern boolean E2EXf_Prv_Initialized_b;
#define E2EXF_STOP_SEC_VAR_INIT_BOOLEAN
#include "E2EXf_MemMap.h"

/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */

#define E2EXF_MASK_H_NIBBLE   0xF0U    // Used in Profiles 01 and 02 specific bit masking operation
#define E2EXF_MASK_L_NIBBLE   0x0FU    // Used in Profiles 01 and 02 specific bit masking operation
/*
 ***************************************************************************************************
 * Inline function definitions
 ***************************************************************************************************
 */

/**
 ***************************************************************************************************
 * E2EXf_Prv_MemCopyLeft - copy overlapping memory by moving left
 *
 * Memory copy routine. Source and destination must not overlap.
 *
 * \param   xDest_pu8       destination address
 * \param   xSrc_pcu8       source address
 * \param   numBytes_u32    number of bytes to be copied
 *
 ***************************************************************************************************
 */
LOCAL_INLINE void E2EXf_Prv_MemCopyLeft(uint8* xDest_pu8, const uint8* xSrc_pcu8, uint32 numBytes_u32)
{
    for(; 0U != numBytes_u32; numBytes_u32--)
    {
        *xDest_pu8 = *xSrc_pcu8;
        xDest_pu8++;
        xSrc_pcu8++;
    }

    return;
}

/**
 ***************************************************************************************************
 * E2EXf_Prv_MemCopyRight - copy overlapping memory by moving right
 *
 * Memory copy routine. Source and destination must not overlap.
 *
 * \param   xDest_pu8       destination address
 * \param   xSrc_pcu8       source address
 * \param   numBytes_u32    number of bytes to be copied
 *
 ***************************************************************************************************
 */
LOCAL_INLINE void E2EXf_Prv_MemCopyRight(uint8* xDest_pu8, const uint8* xSrc_pcu8, uint32 numBytes_u32)
{
    xSrc_pcu8 = &xSrc_pcu8[numBytes_u32-1U];
    xDest_pu8 = &xDest_pu8[numBytes_u32-1U];
    for(; 0U != numBytes_u32 ; numBytes_u32--)
    {
        *xDest_pu8 = *xSrc_pcu8;
        xDest_pu8--;
        xSrc_pcu8--;
    }

    return;
}

/* E2EXF_PRV_H */
#endif

