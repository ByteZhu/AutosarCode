/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */
#ifndef NOT_READY_FOR_TESTING_OR_DEPLOYMENT
#error The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#else
#warning The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#endif /* NOT_READY_FOR_TESTING_OR_DEPLOYMENT */



/* NOTE: All definitions within this headers have to be adjusted according to the project needs
 * Within the provided template only one example is provided.
 * Please consult the documentation of rba_MemLib for details of the functionality required.
 * Note: Default settings are defined within the rba_MemLib_Inl.h
 */

#ifndef RBA_MEMLIB_CFG_CALLOUTS_H
#define RBA_MEMLIB_CFG_CALLOUTS_H

/*
 ****************************************************************************************************
 * Includes
 ****************************************************************************************************
 */
#include "Std_Types.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Inlines
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Inlines Bypass
 **********************************************************************************************************************
*/


/** ***********************************************************************
 * \brief   Bypass for memory operations
 * It is possible to link individual services back to the rba_MemLib provided ones
 * This header is only used if the configuration is activated
 * RBA_MEMLIB_BYPASS_MEM_OPERATIONS is STD_ON
*/


/* In this example to select the rba_BswSrv implementation (if STD_ON is selected) */
#define RBA_MEMLIB_BYPASS_MEM_OPERATIONS_BSWSRV   (STD_OFF)

#if RBA_MEMLIB_BYPASS_MEM_OPERATIONS_BSWSRV == STD_ON
#include "rba_BswSrv.h"
#endif



/** ******************************************************************************************
 * \brief               Memory Copy
 * \param   src_pcu8    Pointer to the source buffer - no alignment constraint
 * \param   dst_pu8     Pointer to the destination buffer - no alignment constraint
 * \param   length_u32  Number of bytes to copy
*/
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE void rba_MemLib_Callout_MemCopy(uint8 const *src_pcu8, uint8 *dst_pu8, uint32 length_u32)
#if RBA_MEMLIB_BYPASS_MEM_OPERATIONS_BSWSRV == STD_ON
{
    (void)rba_BswSrv_MemCopy((void*)dst_pu8,(void const*)src_pcu8,length_u32);
}
#else
{
    rba_MemLib_MemCopy_Provided(src_pcu8,dst_pu8,length_u32);
}
#endif


/** ******************************************************************************************
 * \brief               Set a buffer to a defined value
 * \param   dst_pu8     Pointer to the destination buffer - no alignment constraint
 * \param   value_u8    Value to be set
 * \param   length_u32  Number of bytes to copy
*/
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE void rba_MemLib_Callout_MemSet(uint8 * dst_pu8, uint8 value_u8, uint32 length_u32)
#if RBA_MEMLIB_BYPASS_MEM_OPERATIONS_BSWSRV == STD_ON
{
    (void)rba_BswSrv_MemSet((void*)dst_pu8,(sint32)value_u8,length_u32);
}
#else
{
    rba_MemLib_MemSet_Provided(dst_pu8,value_u8,length_u32);
}
#endif

/** ******************************************************************************************
 * \brief               Compare two buffers
 * \param   bfr1_pcu8   Pointer to buffer 1 - no alignment constraint
 * \param   bfr2_pcu8   Pointer to buffer 2 - no alignment constraint
 * \param   length_u32  Number of bytes to compare
 * \retval  TRUE        Buffers are fully equal
 * \retval  FALSE       At least one entry in the buffers are not same
*/
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE boolean rba_MemLib_Callout_MemCompareBfr(uint8 const * bfr1_pcu8, uint8 const * bfr2_pcu8, uint32 length_u32)
#if RBA_MEMLIB_BYPASS_MEM_OPERATIONS_BSWSRV == STD_ON
{
    sint32 diff;
    diff=rba_BswSrv_MemCompare(bfr1_pcu8,bfr2_pcu8,length_u32);
    return(diff==0);
}
#else
{
    return(rba_MemLib_MemCompareBfr_Provided(bfr1_pcu8,bfr2_pcu8,length_u32));
}
#endif

/** ******************************************************************************************
 * \brief       Compare a buffer to a defined value
 * \param   bfr_pcu8    Pointer to the buffer - no alignment constraint
 * \param   value_u8    Value that should be compared to
 * \param   length_u32  Amount of bytes to check
 * \retval  TRUE        Whole buffer contains only value_u8
 * \retval  FALSE       At least one entry in the buffer is not equal to value_u8
*/
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE boolean rba_MemLib_Callout_MemCompareValue(uint8 const * bfr_pcu8, uint8 value_u8, uint32 length_u32)
#if RBA_MEMLIB_BYPASS_MEM_OPERATIONS_BSWSRV == STD_ON
{
    return(rba_MemLib_MemCompareValue_Provided(bfr_pcu8,value_u8,length_u32));
}
#else
{
    return(rba_MemLib_MemCompareValue_Provided(bfr_pcu8,value_u8,length_u32));
}
#endif



#endif      // Header multi-inclusion protection
