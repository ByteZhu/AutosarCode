
#ifndef FEE_PRV_LIBTYPES_H
#define FEE_PRV_LIBTYPES_H

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if (defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/* Union to combine read-only and read/write buffer */
typedef union
{
    uint8 *          dataChg_pu8;     /* Pointer to changeable buffer - e.g. for read jobs */
    uint8 const *    dataCon_pcu8;    /* Pointer to constant buffer - e.g. for write jobs  */
} Fee_Prv_LibBufferU8_tun;

/* The following operations are considered when limiting the duration of a main function call */
typedef enum
{
    FEE_PRV_LIMIT_CRCINRAM_CPYRAM_E = 0,    /* CRC calculation in RAM or copy process from RAM to RAM           */
    FEE_PRV_LIMIT_CRCINFLS_E        = 1,    /* CRC calculation in flash                                         */
    FEE_PRV_LIMIT_HDR_E             = 2,    /* Handling one FAT entry - no matter what "handling" exactly means */
    FEE_PRV_LIMIT_CACHEREORG_E      = 3,    /* Reorganizing the cache is expensive                              */
    FEE_PRV_LIMIT_MAX_E             = 4     /* Maximum enum value used for defining an array                    */
} Fee_Prv_LibEffortLimit_ten;

/* Struct to measure the amount of already executed effort. */
typedef struct
{
    uint32  effortCtr_u32;  /* Effort that can still be spent - if 0 the main function shall not continue   */
    boolean enabled_b;      /* Effort limitation enabled, TRUE = yes, FALSE = no                            */
} Fee_Prv_LibEffortMeasure_tst;

/* RAM variable for the unit. Here all the data objects of the unit are collected */
typedef struct
{
    Fee_Prv_LibEffortMeasure_tst    libEffortMeasure_st;
}Fee_Prv_LibData_tst;

# endif
#endif  /* FEE_PRV_LIBTYPES_H */
