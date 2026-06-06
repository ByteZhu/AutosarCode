
#ifndef RBA_FEEFS1X_PRV_BCTYPES_H
#define RBA_FEEFS1X_PRV_BCTYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "rba_FeeFs1x_Prv.h"
#include "Fee_Rb_Types.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
#define RBA_FEEFS1X_BC_DATABYTES_IN_HDR     (2uL)


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */


typedef enum
{
    rba_FeeFs1x_BC_HdrPgValueMap_preamble0_e    = 0u,
    rba_FeeFs1x_BC_HdrPgValueMap_preamble1_e    ,
    rba_FeeFs1x_BC_HdrPgValueMap_preamble2_e    ,
    rba_FeeFs1x_BC_HdrPgValueMap_statusB_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_persID0_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_persID1_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_len0_e         ,
    rba_FeeFs1x_BC_HdrPgValueMap_len1_e         ,
    rba_FeeFs1x_BC_HdrPgValueMap_hdrCRC0_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_hdrCRC1_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_datCRC0_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_datCRC1_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_datCRC2_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_datCRC3_e      ,
    rba_FeeFs1x_BC_HdrPgValueMap_dat0_e         ,
    rba_FeeFs1x_BC_HdrPgValueMap_dat1_e
} rba_FeeFs1x_BC_HdrPgValueMap_ten;

typedef enum
{
    rba_FeeFs1x_BC_initCopy_stm_idle_e,
    rba_FeeFs1x_BC_initCopy_stm_extract_e,
    rba_FeeFs1x_BC_initCopy_stm_validate_e,
    rba_FeeFs1x_BC_initCopy_stm_end_e

} rba_FeeFs1x_BC_initCopy_stm_ten;

typedef struct
{
    rba_FeeFs1x_BC_initCopy_stm_ten state_en;
    boolean entry_b;
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en;
}rba_FeeFs1x_BC_initCopy_stm_tst;

typedef struct
{
    uint16 persID_u16;
    uint16 blkLength_u16;
    uint32 pageNr_u32;
    uint16 HdrCrc_u16;
    uint32 dataCrc_u32;
    uint8 first2DatB_au8[RBA_FEEFS1X_BC_DATABYTES_IN_HDR];  /*first two data bytes within the header pages*/
    boolean isInitailized_b;                                /*Is Block copy initialized */

    uint16 statusByte_u16;

}  rba_FeeFs1x_BC_Cpy_tst;

// state machine for invalidate request
typedef enum
{
    rba_FeeFs1x_BC_invalidateDoStates_idle_e,
    rba_FeeFs1x_BC_invalidateDoStates_prepareHdr_e   ,       // Prepare Header page
    rba_FeeFs1x_BC_invalidateDoStates_wrHdr_e               // Write header page

}rba_FeeFs1x_BC_invalidateDoStates_ten;

// working variable for invalidate request
typedef struct
{
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten  copy_en;
    rba_FeeFs1x_BC_invalidateDoStates_ten   state_en;
    Fee_Rb_JobMode_ten                      jobMode_en;
    boolean                                 entry_b;
}rba_FeeFs1x_BC_invalidate_tst;


// state machine for reading from FLS to RAM
typedef enum
{
    rba_FeeFs1x_BC_readFls2RamStates_idle_e,
    rba_FeeFs1x_BC_readFls2RamStates_readDataInHdrPage_e   ,
    rba_FeeFs1x_BC_readFls2RamStates_readDataFromDataPages_e
}rba_FeeFs1x_BC_readFls2RamStates_ten;

typedef struct
{
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten  copy_en;
    uint16                                  len_u16;
    uint16                                  ofs_u16;
    uint8 *                                 userBuf_pu8;
    rba_FeeFs1x_BC_readFls2RamStates_ten    state_en;
    boolean                                 entry_b;
}rba_FeeFs1x_BC_readFls2Ram_tst;

// state machine for validate data
typedef enum
{
    rba_FeeFs1x_BC_validateDataStates_idle_e,
    rba_FeeFs1x_BC_validateDataStates_dataCrcForFirst2DataBytes_e   ,
    rba_FeeFs1x_BC_validateDataStates_dataCrcForRemainingDataBytes_e  ,
    rba_FeeFs1x_BC_validateDataStates_compareDataCrcs_e  ,
    rba_FeeFs1x_BC_validateDataStates_compareLegacyRobDataCrcs_e

}rba_FeeFs1x_BC_validateDataStates_ten;

typedef struct
{
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten  copy_en;
    uint32                                  dataCRC_u32;
    uint32                                  legacyRobDataCRC_u32;
    uint16                                  dataBlkLength_u16;  // This is the actual data length considering ROB checksum as well
    rba_FeeFs1x_BC_validateDataStates_ten   state_en;
    boolean                                 entry_b;
}rba_FeeFs1x_BC_validateData_tst;

typedef enum
{
    rba_FeeFs1x_BC_extractNValHdrStates_idle_e,
    rba_FeeFs1x_BC_extractNValHdrStates_extract_e   ,
    rba_FeeFs1x_BC_extractNValHdrStates_firstChk_e  ,
    rba_FeeFs1x_BC_extractNValHdrStates_crc_e       ,
    rba_FeeFs1x_BC_extractNValHdrStates_fullyProg_e ,
    rba_FeeFs1x_BC_extractNValHdrStates_NoFBPatternChk_e ,
    rba_FeeFs1x_BC_extractNValHdrStates_NoFBdestr_e

}rba_FeeFs1x_BC_extractNValHdrStates_ten;

typedef struct
{
    uint32 page_u32;
    boolean isExtractActive_b;
    uint8 const * adrPageInBuffer_pcu8;
    boolean isCacheBuildup_b;
    rba_FeeFs1x_BC_extractNValHdrStates_ten state_en;
    boolean entry_b;
} rba_FeeFs1x_BC_extractNValHdr_tst;


typedef struct
{
    uint8 * Buff_pu8;
}rba_FeeFs1x_BC_JobData_tst;

// Struct for initWr operation
typedef struct
{
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten  copy_en;
    boolean                                 validBCWasMovedDuringReorg_b; // bit to indicate a possible underflow during sector reorg
}rba_FeeFs1x_BC_initCopyWr_tst;

// Struct for initSectReorgWr operation
typedef struct
{
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en;
}rba_FeeFs1x_BC_initCopySectReorgWr_tst;

/* State machine for rba_FeeFs1x_BC_wrData2FlsDo */
typedef enum
{
    rba_FeeFs1x_BC_wrData2FlsDoStates_idle_e,               // Default state of the state machine
    rba_FeeFs1x_BC_wrData2FlsDoStates_prepareHdrFromFls_e,  // Prepare Header page for Fls2Fls transfer
    rba_FeeFs1x_BC_wrData2FlsDoStates_prepareHdrFromRam_e,  // Prepare Header page for Ram2Fls transfer
    rba_FeeFs1x_BC_wrData2FlsDoStates_wrDataPagesFromFls_e, // Write all data pages, Fls2Fls transfer
    rba_FeeFs1x_BC_wrData2FlsDoStates_wrDataPagesFromRam_e, // Write all data pages, Ram2Fls transfer
    rba_FeeFs1x_BC_wrData2FlsDoStates_recomputeDataCrc_e,   // check and recompute the data Crc
    rba_FeeFs1x_BC_wrData2FlsDoStates_wrHdr_e,              // Write header page
    rba_FeeFs1x_BC_wrData2FlsDoStates_wrDummyHdr_e          // Some error during transfer of data pages, fill up the header page with dummy values
}rba_FeeFs1x_BC_wrData2FlsDoStates_ten;

// Struct for wrData2Fls operation
typedef struct
{
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten  srcCopy_en;                 // Source copy for the write operation
    rba_FeeFs1x_BC_Cpy_blockCopyObject_ten  destCopy_en;                // Copy to be created in DFLASH
    const uint8 *                           buf_pcu8;                   // Pointer to user buffer
    uint16                                  newStatusByte_u16;          // New status flag
    uint32                                  newDataCrc_u32;             // New data crc value with new status bytes
    rba_FeeFs1x_BC_wrData2FlsDoStates_ten   state_en;                   // State machine variable
    Fee_Rb_JobMode_ten                      jobMode_en;                 // mode in which job has to be executed
    boolean                                 updateStatus_b;
    boolean                                 entry_b;                    // Entry variable for the states of the state machine
    boolean                                 updateWrPgDuringHdrWr_b;    // to indicate update of write page for blocks <= 2 bytes
} rba_FeeFs1x_BC_wrData2Fls_tst;

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


#endif

