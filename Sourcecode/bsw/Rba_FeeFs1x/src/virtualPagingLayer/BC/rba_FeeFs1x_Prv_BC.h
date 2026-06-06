
#ifndef RBA_FEEFS1X_PRV_BC_H
#define RBA_FEEFS1X_PRV_BC_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "rba_FeeFs1x_Prv.h"
#include "rba_FeeFs1x_Prv_PARead.h"
#include "Fee_Prv_Cfg.h"
#include "Fee_Rb_Types.h"

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


typedef enum
{
    rba_FeeFs1x_BC_Cpy_BlockJobs_Latest_e = 0u,
    rba_FeeFs1x_BC_Cpy_BlockJobs_Redundant_e,
    rba_FeeFs1x_BC_Cpy_BlockJobs_NewLatest_e,
    rba_FeeFs1x_BC_Cpy_BlockJobs_NewRedundant_e,
    rba_FeeFs1x_BC_Cpy_SectorReorg_Latest_e,
    rba_FeeFs1x_BC_Cpy_SectorReorg_Redundant_e,
    rba_FeeFs1x_BC_Cpy_SectorReorg_NewLatest_e,
    rba_FeeFs1x_BC_Cpy_SectorReorg_NewRedundant_e,
    /**
     * This copy is created when valid header is found in
     * rba_FeeFs1x_BlockCopy_extractHeader()
     */
    rba_FeeFs1x_BC_Cpy_Internal_e,

    rba_FeeFs1x_BC_Cpy_NrOfCopies_e /*Helper value for getting the amount of defined copies*/
}rba_FeeFs1x_BC_Cpy_blockCopyObject_ten;


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

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

LOCAL_INLINE void               rba_FeeFs1x_BC_getEndianedPreamble(uint32 * PreamblePattern_u32, uint32 * PreambleMask_u32);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_BC_extractHdrSync(uint32 readAddr_u32);

extern void                     rba_FeeFs1x_BC_init(void);
extern void                     rba_FeeFs1x_BC_initCopy(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en, uint16 persID_u16, uint32 pageNr_u32);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_initCopyDo(void);

extern void                     rba_FeeFs1x_BC_initCopySectReorgWr(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en, uint16 len_u16, uint16 persID_u16, uint16 statusByte_u16);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_initCopySectReorgWrDo(void);

extern void                     rba_FeeFs1x_BC_initCopyWr(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en, uint16 len_u16, uint16 persID_u16, uint16 statusByte_u16);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_initCopyWrDo(void);

extern boolean                  rba_FeeFs1x_BC_compare2Config(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en , uint16 confStatusByte_u16);
extern void                     rba_FeeFs1x_BC_compareBuffer2Copy(uint8 const * buffer_pu8, rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copyInFlash_en);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_compareBuffer2CopyDo(void);
extern void                     rba_FeeFs1x_BC_compareFls2Fls(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy1_en, rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy2_en);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_compareFls2FlsDo(void);

extern void                     rba_FeeFs1x_BC_destroy(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_destroyDo(void);

extern void                     rba_FeeFs1x_BC_invalidate(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en, Fee_Rb_JobMode_ten jobMode_en);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_invalidateDo(void);

extern void                     rba_FeeFs1x_BC_extractHdr(uint32 page_u32);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_extractHdrDo(void);



extern void                     rba_FeeFs1x_BC_validateHdr(boolean isCacheBuildup_b);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_validateHdrDo(void);

extern boolean              rba_FeeFs1x_BC_extract_isInternalCpyLengthMatching(uint16 nrBytesExpectedLength_u16);


extern void                 rba_FeeFs1x_BC_finalizeCopy(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);

extern uint32               rba_FeeFs1x_BC_getDataCRC(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern uint32               rba_FeeFs1x_BC_getPageNo(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern uint16               rba_FeeFs1x_BC_getPersID(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern boolean              rba_FeeFs1x_BC_getCpyRedBit(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern uint32               rba_FeeFs1x_BC_getPageNrOfLastPage(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern boolean              rba_FeeFs1x_BC_getCpyNoFBBitActive(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern boolean              rba_FeeFs1x_BC_getCpyInvBitActive(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern uint16               rba_FeeFs1x_BC_getBlkLength     (rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern uint8                rba_FeeFs1x_BC_getBlkDFLASHStatusByte (rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);

extern boolean              rba_FeeFs1x_BC_getCpySurvivalBit(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);

extern void                 rba_FeeFs1x_BC_readFls2Ram(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en, uint16 len_u16,
        uint16 ofs_u16, uint8 * userBuf_pu8);
extern rba_FeeFs1x_RetVal_ten  rba_FeeFs1x_BC_readFls2RamDo(void);

extern void                     rba_FeeFs1x_BC_reduceOwnPages(uint32 amountOfPages_u32);

extern void                     rba_FeeFs1x_BC_validateData(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten copy_en);
extern rba_FeeFs1x_RetVal_ten   rba_FeeFs1x_BC_validateDataDo(void);


extern void                     rba_FeeFs1x_BC_wrFls2Fls(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten srcCopy_en,
                                                         rba_FeeFs1x_BC_Cpy_blockCopyObject_ten destCopy_en,
                                                         boolean updateStatus_b,
                                                         uint16 newStatusByte_u16,
                                                         Fee_Rb_JobMode_ten jobMode_en);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_BC_wrFls2FlsDo(void);

extern void                     rba_FeeFs1x_BC_wrRam2Fls(rba_FeeFs1x_BC_Cpy_blockCopyObject_ten destCopy_en,
                                                         uint32 dataCrc_u32, uint8 const * userBuf_pcu8,
                                                         Fee_Rb_JobMode_ten jobMode_en);
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_BC_wrRam2FlsDo(void);
extern rba_FeeFs1x_RetVal_ten       rba_FeeFs1x_BC_wrData2FlsDo(void);

extern uint16                       rba_FeeFs1x_BC_calcBlkHdrCRC(uint16 persID_u16 , uint16 blkLength_u16 , uint16 statusByte_u16);

extern void rba_FeeFs1x_BC_extractHdrSync_UpdatePage            (uint32 nrPage_u32);
extern void rba_FeeFs1x_BC_extractHdrSync_CopyContent           (uint8 const * adrPageInBuffer_pcu8);


/*
 **********************************************************************************************************************
 * Inlines
 **********************************************************************************************************************
*/

#if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))

/**
 *********************************************************************
 * rba_FeeFs1x_BC_wrFls2FlsDo
 * This is the do function for fls to fls transfer operation.
 * \return  Returns status of the storage operation
 * \retval  rba_FeeFs1x_Pending_e       : Storage ongoing, call again during next cycle
 * \retval  rba_FeeFs1x_JobOK_e         : Data stored sucessfully
 * \retval  rba_FeeFs1x_ErrorInternal_e : Error during transfer operation
 * \retval  rba_FeeFs1x_ErrorExternal_e : processing error, validation wasn't completed
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten  rba_FeeFs1x_BC_wrFls2FlsDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    retVal_en = rba_FeeFs1x_BC_wrData2FlsDo();
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_BC_wrRam2FlsDo
 * This is the do function for writing the user buffer data to DFLASH.
 * \return  Returns status of the storage operation
 * \retval  rba_FeeFs1x_Pending_e       : Storage ongoing, call again during next cycle
 * \retval  rba_FeeFs1x_JobOK_e         : Data stored sucessfully
 * \retval  rba_FeeFs1x_ErrorInternal_e : Error during storage of the data
 * \retval  rba_FeeFs1x_ErrorExternal_e : processing error, validation wasn't completed
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten  rba_FeeFs1x_BC_wrRam2FlsDo(void)
{
    rba_FeeFs1x_RetVal_ten retVal_en;

    retVal_en = rba_FeeFs1x_BC_wrData2FlsDo();
    return retVal_en;
}

/**
 *********************************************************************
 * rba_FeeFs1x_BC_getEndianedPreamble
 * \return  block preamble as uint32 in endianness of the ECU
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE void rba_FeeFs1x_BC_getEndianedPreamble(uint32 * PreamblePattern_u32, uint32 * PreambleMask_u32)
{
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
    *PreamblePattern_u32 = 0xA53C96FFuL;
    *PreambleMask_u32    = 0x000000FFuL;
#else
    *PreamblePattern_u32 = 0xFF963CA5uL;
    *PreambleMask_u32    = 0xFF000000uL;
    #endif
}

/**
 *********************************************************************
 * rba_FeeFs1x_BC_extractHdrSync
 * Similar to extractHdr, extracts a page and checks whether this page contains a preamble
 * \return  address contains a preamble
 * \retval  rba_FeeFs1x_JobOK_e         page contains a preamble
 * \retval  rba_FeeFs1x_JobFailed_e     page doesn't contain a preamble
 * \retval  rba_FeeFs1x_ErrorExternal_e error returned by Fls jobs
 * \retval  rba_FeeFs1x_ErrorInternal_e internal processing error
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_BC_extractHdrSync(uint32 readAddr_u32)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    rba_FeeFs1x_RetVal_ten retValGetPageDo_en;

    uint32 const * adrPageInBuffer_pu32;

    uint32 PreamblePattern_u32;
    uint32 PreambleMask_u32;

    rba_FeeFs1x_BC_getEndianedPreamble(&PreamblePattern_u32, &PreambleMask_u32);

    // update the medium iterator to the next address
    retValGetPageDo_en = rba_FeeFs1x_PARead_getPagesBackwardsSync(readAddr_u32, &adrPageInBuffer_pu32);

    switch(retValGetPageDo_en)

    {

        case rba_FeeFs1x_JobOK_e:
        {
            uint32 PageContent_u32;

            // read finished successfully
            PageContent_u32 = *(adrPageInBuffer_pu32);
            // mask out the status byte
            PageContent_u32 |= PreambleMask_u32;

            // check the buffer for presence of a preamble
            if(PageContent_u32 == PreamblePattern_u32)
            {
                rba_FeeFs1x_BC_extractHdrSync_CopyContent((uint8 const *) adrPageInBuffer_pu32);

                retVal_en = rba_FeeFs1x_JobOK_e;
            }
            else
            {
                // page doesn't contain a preamble
                retVal_en = rba_FeeFs1x_JobFailed_e;
            }
            break;
        }
        case rba_FeeFs1x_ErrorExternal_e:
        {
            // read finished with an error, return this read error
            retVal_en = rba_FeeFs1x_ErrorExternal_e;

            break;
        }
        case rba_FeeFs1x_Pending_e:
        default:
        {
            // unexpected return value
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
            break;
        }

    }

    return retVal_en;

}

# endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif

