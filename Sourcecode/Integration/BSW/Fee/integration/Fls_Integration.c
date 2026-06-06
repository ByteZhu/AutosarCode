/*

/* BSWEXT-544 */
#ifndef FLS_INTEGRATION_C
#define FLS_INTEGRATION_C

#include "Fls_Integration.h"
#if (FLS_AR_RELEASE_MINOR_VERSION == 0)

/******************************************************************************/

Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress,
                                         Fls_LengthType Length)
{
	Std_ReturnType RetVal;
    static uint8 compare_block[MAX_BLANK_CHECK_SIZE];
    uint32 blockIndex;
    for(blockIndex=0; blockIndex < Length; blockIndex++)
    {
    	compare_block[blockIndex] = (uint8)RBA_FEEFS1X_PRV_CFG_ERASE_PATTERN_8BIT;
    }

    RetVal = Fls_Compare((Fls_AddressType)TargetAddress, &compare_block[0] , Length );
	return RetVal;
}

#endif /*FLS_AR_RELEASE_MINOR_VERSION == 0*/
#endif /* FLS_INTEGRATION_C */
