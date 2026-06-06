

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
#if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

#include "Fee_Prv_Config.h"
#include "Fee_Cfg.h"

 
/*
 **********************************************************************************************************************
 * Generated Variables
 **********************************************************************************************************************
 */
/*
 * In case of all three conditions listed below are fulfilled
 * - DMA is writing into the buffer
 * - data cache controller (CC) is enabled
 * - buffer is linked to a cached memory region
 *
 * Fee_Prv_Cfg_MediumBuffer_un has to be fully cache line aligned (start address has to be aligned to the start of a
 * cache line and the buffer size has to be multiple of cache line size).
 * The DMA is always bypassing the CC and has to invalidate the cache lines before writing to it,
 * in order to keep cache coherence between DMA (direct writer without CC) and core (reader via CC).
 * Otherwise if the cache line is shared with data of another application, the data may get corrupted.
*/
#define FEE_START_SEC_VAR_CLEARED_SECURED_CACHE_LINE_ALIGNED_UNSPECIFIED
#include "Fee_MemMap.h"


static Fee_Prv_Cfg_MediumBuffer_tun     Fee_Prv_Cfg_MediumBuffer_un;
#define FEE_STOP_SEC_VAR_CLEARED_SECURED_CACHE_LINE_ALIGNED_UNSPECIFIED
#include "Fee_MemMap.h"

# if (defined(FLS_RB_ROBUST_PROG_STATUS_API) && (STD_OFF != FLS_RB_ROBUST_PROG_STATUS_API))
# define FEE_START_SEC_VAR_CLEARED_SECURED_8
# include "Fee_MemMap.h"
static uint8 Fee_Prv_Cfg_MediumRescueBfr_au8[RBA_FLS_WORDLINE_SIZE];
# define FEE_STOP_SEC_VAR_CLEARED_SECURED_8
# include "Fee_MemMap.h"
# endif
 
// Below table is the data model of Fee component.
#define FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"

static Fee_Prv_Data_tst     Fee_Prv_Data_st;

#define FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"

/*
 **********************************************************************************************************************
 * Generated Tables
 **********************************************************************************************************************
 */
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

/* instance specific buffer configuration table */
static const Fee_Prv_ConfigDeviceBufTable_tst Fee_Prv_ConfigDeviceBufTable_cast[Fee_Rb_Device_Max][1] =
{
    { 
        {
            Fee_Prv_Cfg_MediumBuffer_un.u8,  // pointer to first data buffer
            1024u,  // size of the first data buffer
        }
    },
};

/* instance specific configuration table */
const Fee_Prv_ConfigDeviceTable_tst Fee_Prv_ConfigDeviceTable_cast[Fee_Rb_Device_Max] = 
{
    {
        &Fee_Prv_Data_st,
        &Fee_Prv_ConfigDeviceBufTable_cast[0][0],
# if (defined(FLS_RB_ROBUST_PROG_STATUS_API) && (STD_OFF != FLS_RB_ROBUST_PROG_STATUS_API))
        Fee_Prv_Cfg_MediumRescueBfr_au8,
# else
        NULL_PTR,
# endif
        NULL_PTR,
        Fee_Rb_DeviceName,
        FEE_FS1X,
        0u, // block index of NA 
        0
    },
};     

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

#endif
