
#ifndef FEE_PRV_CONFIGTYPES_H
#define FEE_PRV_CONFIGTYPES_H

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if (defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))
#include "Fee_Cfg.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

typedef enum
{
    FEE_PRV_REQUESTER_NVM_E = 0,
    FEE_PRV_REQUESTER_ADAPTER_E,
    FEE_PRV_REQUESTER_DEBUG_E,
    FEE_PRV_REQUESTER_CHUNK_E,
    FEE_PRV_REQUESTER_MAX_E
} Fee_Prv_ConfigRequester_ten;

typedef struct
{
    uint16  BlockPersistentId_u16;
    uint16  Flags_u16;
    uint16  Length_u16;
} Fee_Rb_BlockPropertiesType_tst;

typedef struct
{
    uint32  Fee_PhysStartAddress_u32;    /* Physical sector: start address */
    uint32  Fee_PhysEndAddress_u32;      /* Physical sector: end address   */
} Fee_Rb_FlashProp_tst;

typedef enum
{
    FEE_FS10 = 0,
    FEE_FS1X,
    FEE_FS2,
    FEE_FS3
}Fee_Prv_Fs_ten;

# endif
/* FEE_PRV_CONFIGTYPES_H */
#endif
