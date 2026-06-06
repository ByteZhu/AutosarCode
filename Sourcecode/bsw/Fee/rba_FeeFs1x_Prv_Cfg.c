

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "rba_FeeFs1x_Prv_Cfg.h"
#include "Fee_Prv_ConfigTypes.h"
/* BSWEXT-293 */
#include "NvM_Prv_SizeRamMirror.h"

/*
 **********************************************************************************************************************
 * Generated Tables
 **********************************************************************************************************************
 */

/* Properties of flash sectors */
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
const Fee_Rb_FlashProp_tst rba_FeeFs1x_Prv_Cfg_FlashPropTable_cast[RBA_FEEFS1X_PRV_CFG_NR_FLASH_BANKS_AVAILABLE] = {
     { RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0, RBA_FEEFS1X_PRV_CFG_PHYS_SEC_END0 },
     { RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START1, RBA_FEEFS1X_PRV_CFG_PHYS_SEC_END1 }
};
#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
Fee_Rb_BlockPropertiesType_tst rba_FeeFs1x_Prv_Cfg_BlockPropertiesTable_ast[RBA_FEEFS1X_PRV_CFG_NR_OF_BLOCKS] = {
/* BSWEXT-293 */
    { 0x0020u, 0x0101u, 0x0008u },    /*   (0)     NvM_BR_AngCorrectStored */
/* BSWEXT-293 */
    { 0x0230u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (1)     NVM_ID_EVMEM_LOC_4 */
/* BSWEXT-293 */
    { 0x03B1u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (2)     NVM_ID_EVMEM_LOC_5 */
/* BSWEXT-293 */
    { 0x0C37u, 0x0100u, 0x0001u },    /*   (3)     NV_ValidityFlagsBlock */
/* BSWEXT-293 */
    { 0x1008u, 0x0101u, 0x0008u },    /*   (4)     NvM_BR_ResetFlag */
/* BSWEXT-293 */
    { 0x103Au, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (5)     NVM_ID_EVMEM_LOC_7 */
/* BSWEXT-293 */
    { 0x11BBu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (6)     NVM_ID_EVMEM_LOC_6 */
/* BSWEXT-293 */
    { 0x16A1u, 0x0140u, 0x0020u },    /*   (7)     NV_PartNumberBlock */
/* BSWEXT-293 */
    { 0x180Eu, 0x0101u, 0x0008u },    /*   (8)     NvM_BR_VehicleConfig */
/* BSWEXT-293 */
    { 0x1A9Fu, 0x0101u, 0x0008u },    /*   (9)     NvM_BR_CommonCRCStored */
/* BSWEXT-293 */
    { 0x1D99u, 0x0101u, 0x0008u },    /*   (10)    NvM_BR_TOCStudyTrq */
/* BSWEXT-293 */
    { 0x212Eu, 0x0101u, 0x0008u },    /*   (11)    NvM_BR_CCPVal */
/* BSWEXT-293 */
    { 0x24A7u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (12)    NVM_ID_EVMEM_LOC_1 */
/* BSWEXT-293 */
    { 0x2526u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (13)    NVM_ID_EVMEM_LOC_0 */
/* BSWEXT-293 */
    { 0x2DBDu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (14)    NVM_ID_EVMEM_LOC_18 */
/* BSWEXT-293 */
    { 0x2EBFu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (15)    NVM_ID_EVMEM_LOC_29 */
/* BSWEXT-293 */
    { 0x2F3Eu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (16)    NVM_ID_EVMEM_LOC_39 */
/* BSWEXT-293 */
    { 0x36ADu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (17)    NVM_ID_EVMEM_LOC_2 */
/* BSWEXT-293 */
    { 0x372Cu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (18)    NVM_ID_EVMEM_LOC_3 */
/* BSWEXT-293 */
    { 0x3CB5u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (19)    NVM_ID_EVMEM_LOC_19 */
/* BSWEXT-293 */
    { 0x3E36u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (20)    NVM_ID_EVMEM_LOC_38 */
/* BSWEXT-293 */
    { 0x3FB7u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (21)    NVM_ID_EVMEM_LOC_28 */
/* BSWEXT-293 */
    { 0x4128u, 0x0100u, 0x0004u },    /*   (22)    NvMBlockDescriptor_DID_SystemFaultRank */
/* BSWEXT-293 */
    { 0x4AA1u, 0x0100u, (DEM_SIZEOF_VAR(Dem_GenericNvData) + 0) },    /*   (23)    NVM_ID_DEM_GENERIC_NV_DATA */
/* BSWEXT-293 */
    { 0x4AAFu, 0x0100u, 0x0004u },    /*   (24)    NV_ProgrammingCounterBlock */
/* BSWEXT-293 */
    { 0x4B9Fu, 0x0101u, 0x0008u },    /*   (25)    NvM_BR_TestMode */
/* BSWEXT-293 */
    { 0x5106u, 0x0100u, (DEM_SIZEOF_VAR(Dem_AllEventsStatusByte) + 0) },    /*   (26)    NVM_ID_EVT_STATUSBYTE */
/* BSWEXT-293 */
    { 0x51A7u, 0x0101u, 0x0008u },    /*   (27)    NvM_BR_VehicleName */
/* BSWEXT-293 */
    { 0x5502u, 0x0100u, 0x0008u },    /*   (28)    NV_CrcBlock */
/* BSWEXT-293 */
    { 0x631Au, 0x0101u, 0x0008u },    /*   (29)    NvM_BR_StrAngZero */
/* BSWEXT-293 */
    { 0x6A8Bu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (30)    NVM_ID_EVMEM_LOC_9 */
/* BSWEXT-293 */
    { 0x6B0Au, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (31)    NVM_ID_EVMEM_LOC_8 */
/* BSWEXT-293 */
    { 0x7624u, 0x0100u, 0x0002u },    /*   (32)    NvM_ConfigId */
/* BSWEXT-293 */
    { 0x7A30u, 0x0101u, 0x0008u },    /*   (33)    NvM_BR_FunConfig */
/* BSWEXT-293 */
    { 0x7F91u, 0x0101u, 0x002Cu },    /*   (34)    NvM_BR_CurrentOffset */
/* BSWEXT-293 */
    { 0x7FBEu, 0x0100u, 0x0001u },    /*   (35)    NV_ExternalReprogrammingRequestFlagBlock */
/* BSWEXT-293 */
    { 0x8468u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (36)    NVM_ID_EVMEM_LOC_31 */
/* BSWEXT-293 */
    { 0x85E9u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (37)    NVM_ID_EVMEM_LOC_21 */
/* BSWEXT-293 */
    { 0x86EBu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (38)    NVM_ID_EVMEM_LOC_10 */
/* BSWEXT-293 */
    { 0x8BD7u, 0x0101u, 0x0008u },    /*   (39)    NvM_BR_AngValidEnd */
/* BSWEXT-293 */
    { 0x94E1u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (40)    NVM_ID_EVMEM_LOC_20 */
/* BSWEXT-293 */
    { 0x9560u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (41)    NVM_ID_EVMEM_LOC_30 */
/* BSWEXT-293 */
    { 0x97E3u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (42)    NVM_ID_EVMEM_LOC_11 */
/* BSWEXT-293 */
    { 0x9AF1u, 0x0100u, 0x0002u },    /*   (43)    NvM_BN_DID_D09A */
/* BSWEXT-293 */
    { 0x9B7Eu, 0x0100u, 0x0004u },    /*   (44)    NvMBlockDescriptor_ReadWritebyAddress */
/* BSWEXT-293 */
    { 0x9DD4u, 0x0100u, 0x0011u },    /*   (45)    NvMBlockDescriptor_DID_IOControl */
/* BSWEXT-293 */
    { 0xA2CBu, 0x0100u, 0x0400u },    /*   (46)    NvM_NativeBlock_2 */
/* BSWEXT-293 */
    { 0xA47Au, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (47)    NVM_ID_EVMEM_LOC_12 */
/* BSWEXT-293 */
    { 0xA6F9u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (48)    NVM_ID_EVMEM_LOC_33 */
/* BSWEXT-293 */
    { 0xA778u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (49)    NVM_ID_EVMEM_LOC_23 */
/* BSWEXT-293 */
    { 0xB26Fu, 0x0100u, 0x0011u },    /*   (50)    NvMBlockDescriptor_DID_VehicleSpeed */
/* BSWEXT-293 */
    { 0xB342u, 0x0100u, 0x0400u },    /*   (51)    NvM_NativeBlock_3 */
/* BSWEXT-293 */
    { 0xB572u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (52)    NVM_ID_EVMEM_LOC_13 */
/* BSWEXT-293 */
    { 0xB670u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (53)    NVM_ID_EVMEM_LOC_22 */
/* BSWEXT-293 */
    { 0xB6F5u, 0x0100u, 0x0004u },    /*   (54)    NV_ProgrammingAttemptCounterBlock */
/* BSWEXT-293 */
    { 0xB7F1u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (55)    NVM_ID_EVMEM_LOC_32 */
/* BSWEXT-293 */
    { 0xC0CBu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (56)    NVM_ID_EVMEM_LOC_34 */
/* BSWEXT-293 */
    { 0xC14Au, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (57)    NVM_ID_EVMEM_LOC_24 */
/* BSWEXT-293 */
    { 0xC248u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (58)    NVM_ID_EVMEM_LOC_15 */
/* BSWEXT-293 */
    { 0xC378u, 0x0101u, 0x0012u },    /*   (59)    NvM_BR_InitAngle */
/* BSWEXT-293 */
    { 0xCFD3u, 0x0100u, 0x0400u },    /*   (60)    NvM_NATIVE_IDS_1024 */
/* BSWEXT-293 */
    { 0xD042u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (61)    NVM_ID_EVMEM_LOC_25 */
/* BSWEXT-293 */
    { 0xD1C3u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (62)    NVM_ID_EVMEM_LOC_35 */
/* BSWEXT-293 */
    { 0xD2C7u, 0x0101u, 0x0022u },    /*   (63)    NvM_BR_RotorOffset */
/* BSWEXT-293 */
    { 0xD340u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (64)    NVM_ID_EVMEM_LOC_14 */
/* BSWEXT-293 */
    { 0xD672u, 0x0101u, 0x0008u },    /*   (65)    NvM_BR_Mileage */
/* BSWEXT-293 */
    { 0xD812u, 0x0101u, 0x0040u },    /*   (66)    NvM_BR_BackupConfig */
/* BSWEXT-293 */
    { 0xD8EBu, 0x0101u, 0x0008u },    /*   (67)    NvM_BR_PenProf */
/* BSWEXT-293 */
    { 0xDB7Du, 0x0100u, 0x0011u },    /*   (68)    NvM_BN_DID_F190 */
/* BSWEXT-293 */
    { 0xDDD3u, 0x0101u, 0x0008u },    /*   (69)    NvM_BR_SoftwareConfig */
/* BSWEXT-293 */
    { 0xE0D9u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (70)    NVM_ID_EVMEM_LOC_17 */
/* BSWEXT-293 */
    { 0xE25Au, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (71)    NVM_ID_EVMEM_LOC_36 */
/* BSWEXT-293 */
    { 0xE2F5u, 0x0101u, 0x0008u },    /*   (72)    NvM_BR_AngEndCalData */
/* BSWEXT-293 */
    { 0xE3DBu, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (73)    NVM_ID_EVMEM_LOC_26 */
/* BSWEXT-293 */
    { 0xE859u, 0x0100u, 0x0001u },    /*   (74)    NV_ResetResponseFlagBlock */
/* BSWEXT-293 */
    { 0xF1D1u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (75)    NVM_ID_EVMEM_LOC_16 */
/* BSWEXT-293 */
    { 0xF2D3u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (76)    NVM_ID_EVMEM_LOC_27 */
/* BSWEXT-293 */
    { 0xF2F7u, 0x0100u, 0x0004u },    /*   (77)    ECUM_CFG_NVM_BLOCK */
/* BSWEXT-293 */
    { 0xF352u, 0x0100u, (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0) },    /*   (78)    NVM_ID_EVMEM_LOC_37 */
/* BSWEXT-293 */
    { 0xFA75u, 0x0101u, 0x0011u }     /*   (79)    NvM_BR_VIN */
};
#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

/*
 **********************************************************************************************************************
 * Generated Fs-specifc Variables
 **********************************************************************************************************************
 */


/* List of blocks with Redundant flag enabled */
#define FEE_START_SEC_CONST_16 
#include "Fee_MemMap.h" 
const uint16 rba_FeeFs1x_Prv_Cfg_RedBlks_acu16[RBA_FEEFS1X_PRV_CFG_NR_RDNT_BLOCKS] = 
{ 
    /*  0 */         0u,  /* NvM_BR_AngCorrectStored */
    /*  1 */         4u,  /* NvM_BR_ResetFlag */
    /*  2 */         8u,  /* NvM_BR_VehicleConfig */
    /*  3 */         9u,  /* NvM_BR_CommonCRCStored */
    /*  4 */        10u,  /* NvM_BR_TOCStudyTrq */
    /*  5 */        11u,  /* NvM_BR_CCPVal */
    /*  6 */        25u,  /* NvM_BR_TestMode */
    /*  7 */        27u,  /* NvM_BR_VehicleName */
    /*  8 */        29u,  /* NvM_BR_StrAngZero */
    /*  9 */        33u,  /* NvM_BR_FunConfig */
    /* 10 */        34u,  /* NvM_BR_CurrentOffset */
    /* 11 */        39u,  /* NvM_BR_AngValidEnd */
    /* 12 */        59u,  /* NvM_BR_InitAngle */
    /* 13 */        63u,  /* NvM_BR_RotorOffset */
    /* 14 */        65u,  /* NvM_BR_Mileage */
    /* 15 */        66u,  /* NvM_BR_BackupConfig */
    /* 16 */        67u,  /* NvM_BR_PenProf */
    /* 17 */        69u,  /* NvM_BR_SoftwareConfig */
    /* 18 */        72u,  /* NvM_BR_AngEndCalData */
    /* 19 */        79u,  /* NvM_BR_VIN */
}; 
#define FEE_STOP_SEC_CONST_16 
#include "Fee_MemMap.h"
