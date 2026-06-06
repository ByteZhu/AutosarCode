
#ifndef RBA_FEEFS1X_PRV_PAREAD_H
#define RBA_FEEFS1X_PRV_PAREAD_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

# if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))
#include "rba_FeeFs1x_Prv.h"
#include "rba_FeeFs1x_Prv_Cfg.h"
#include "Fee_Prv_Medium.h"


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

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_PARead_getPagesBackwardsSync(uint32 readAddr_u32 , uint32 const * * adrPageInBuffer_ppu32);



extern void rba_FeeFs1x_PARead_setIteratorPreferences(boolean isBackwardBuffering_b , uint32 nrBytesPrefetch_u32);

extern void rba_FeeFs1x_PARead_getPages(uint32 nrPage_u32 , uint32 cntPages_u32 , uint8 const * * adrPageInBuffer_ppcu8);
extern rba_FeeFs1x_RetVal_ten rba_FeeFs1x_PARead_getPagesDo(void);

extern void rba_FeeFs1x_PARead_unbufferedRead(uint32 abstrPage_u32, uint16 nrOfBytes_u16, uint8 *buffer_pu8, uint8 startOfs_u8);
extern rba_FeeFs1x_RetVal_ten rba_FeeFs1x_PARead_unbufferedReadDo(void);

extern void rba_FeeFs1x_PARead_init(void);

/*
 **********************************************************************************************************************
 * Inlines
 **********************************************************************************************************************
*/







/**
 *********************************************************************
 * rba_FeeFs1x_PARead_getPagesBackwardsSync
 * Job acceptor function for getting a page from DFLASH syncronously
 * \param   nrPage_u32: requested page
 * \param   adrPageInBuffer_ppcu8: callByRef param to return a pointer to the location the data is stored at
 * \return  Job accepted
 * \retval  rba_FeeFs1x_JobOK_e : Job is successful
 * \retval  rba_FeeFs1x_ErrorInternal_e : Internal error occured
 * \retval  rba_FeeFs1x_ErrorExternal_e : External error occured
 *
 *********************************************************************
 */
/* MR12 RULE 8.13 VIOLATION: The parameter cannot be switched to const. It is passed to another function
 * as pointer to a pointer(p2p). This function is editing the pointer the p2p is pointing to
 * (setting it to an address within a buffer)*/
LOCAL_INLINE rba_FeeFs1x_RetVal_ten rba_FeeFs1x_PARead_getPagesBackwardsSync(uint32 readAddr_u32, uint32 const * * adrPageInBuffer_ppu32)
{
    rba_FeeFs1x_RetVal_ten retVal_en;
    MemIf_JobResultType retValMedium_en;


    uint32 const cntBytesRequested_cu32 = RBA_FEEFS1X_PRV_NR_OF_LOG_PAGES_USED_BY_BLK_HDR * RBA_FEEFS1X_PRV_CFG_LOGL_PAGE_SIZE;

    uint32 const nrBytesToPrefetch_cu32 = RBA_FEEFS1X_PRV_MAX_BUFFER_SIZE_TO_BE_PREFETCHED;

    // get the page content buffered or unbuffered

    /* MR12 RULE 11.3 VIOLATION: The accessed addresses in DFLASH and in the Medium buffer always are 32Bit aligned */
    retValMedium_en = Fee_Prv_MediumPreSync(Fee_Rb_DeviceName,
                                            readAddr_u32,
                                            cntBytesRequested_cu32,
                                            nrBytesToPrefetch_cu32,
                                            ((void const * *)(adrPageInBuffer_ppu32)));

    switch(retValMedium_en)
    {
        case MEMIF_JOB_OK:
        {

            retVal_en = rba_FeeFs1x_JobOK_e;

        }break;

        case MEMIF_JOB_PENDING:
        {
            retVal_en = rba_FeeFs1x_ErrorInternal_e;
        }break;

        case MEMIF_JOB_FAILED:
        case MEMIF_JOB_CANCELED:
        case MEMIF_BLOCK_INCONSISTENT:
        case MEMIF_BLOCK_INVALID:
        default:
        {
            retVal_en = rba_FeeFs1x_ErrorExternal_e;
        }break;
    }

    return(retVal_en);
}

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
# endif

#endif

