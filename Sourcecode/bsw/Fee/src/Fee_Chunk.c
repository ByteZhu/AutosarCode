
#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"


/* Disable the Fee common part when not needed */
#if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

/* Disable this unit when not needed */
# if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS))

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Crc.h"
#include "Fee_Cfg_SchM.h"
#include "Fee_Prv_Chunk.h"
#include "Fee_Prv_ChunkTypes.h"
#include "Fee_Prv_Config.h"
#include "Fee_Prv_ConfigTypes.h"
#include "Fee_Prv_FsIf.h"
#include "Fee_Prv_Job.h"
#include "Fee_Prv_Lib.h"
#include "Fee_Prv_Order.h"
#include "Fee_Rb_Idx.h"
#include "rba_MemLib.h"

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
#include "rba_FeeFs1_Prv_Cfg.h"
#include "rba_FeeFs1_Prv.h"


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

#define FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"

/* Collection of all variables of this unit */
static Fee_Prv_ChunkGetJobResult_tpfct    Fee_Prv_ChunkGetJobResult_pfct;
static Fee_Prv_JobDesc_tst                Fee_Prv_ChunkJob_st;
static Fee_Prv_JobChunkInfo_tst           Fee_Prv_ChunkInfo_st;

#define FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"


/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

typedef union
{
    Fee_BlockPropertiesType_tst    const * xBlkPptyTbl_pcst;   /* Pointer to block property table in Fee1            */
    Fee_Rb_BlockPropertiesType_tst const * xRbBlkPptyTbl_pcst; /* Pointer to block property table in Fee1x/Fee2/Fee3 */
} Fee_Prv_Chunk_BlkPptyTbl_tun;


/* # if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED)) */
# else

typedef union
{
    Fee_Rb_BlockPropertiesType_tst const * xRbBlkPptyTbl_pcst; /* Pointer to block property table in Fee1x/Fee2/Fee3 */
} Fee_Prv_Chunk_BlkPptyTbl_tun;

/* # if(!defined(RBA_FEEFS1_PRV_CFG_ENABLED) || (FALSE ==  RBA_FEEFS1_PRV_CFG_ENABLED)) */
# endif


/*
 **********************************************************************************************************************
 * Static declarations
 **********************************************************************************************************************
*/

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

static uint16    Fee_Prv_ChunkGetBlockLengthByBlockNr (
        Fee_Rb_DeviceName_ten deviceName_en,
        uint16 nrBlk_u16,
        Fee_Rb_BlockPropertiesType_tst const * xBlkPptyTbl_pcst);

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
static Fee_Prv_ChunkGetJobResult_tpfct    Fee_Prv_ChunkGetJobResultFct (uint16 nrBlk_u16);
# endif

static Std_ReturnType    Fee_Prv_ChunkDetChkGnrl (
        Fee_Rb_DeviceName_ten deviceName_en,
        uint8 idApi_u8,
        uint8 const * dataBuf_pcu8,
        uint32 nrBytMax_u32,
        uint32 nrBytMin_u32);

static Std_ReturnType    Fee_Prv_ChunkDetChkFsSpc (
        Fee_Rb_DeviceName_ten deviceName_en,
        uint8 idApi_u8,
        Fee_Prv_ConfigDeviceTable_tst const * xCfgDevTbl_pcst,
        uint32 nrBytMax_u32,
        uint32 nrTotLen_u32);

static Std_ReturnType    Fee_Prv_ChunkPut (
        Fee_Rb_DeviceName_ten deviceName_en,
        uint8 idApi_u8,
        Fee_Prv_JobDesc_tst const * xJob_pcst);


/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
*/

LOCAL_INLINE Fee_Rb_BlockPropertiesType_tst const *
                       Fee_Prv_ChunkGetBlockPropertiesTable (Fee_Rb_DeviceName_ten deviceName_en);
LOCAL_INLINE uint16    Fee_Prv_ChunkGetNrOfBlocks           (Fee_Rb_DeviceName_ten deviceName_en);
LOCAL_INLINE uint16    Fee_Prv_ChunkGetDoubleStorageBitmask (Fee_Rb_DeviceName_ten deviceName_en);
LOCAL_INLINE uint16    Fee_Prv_ChunkGetSurvivalBitmask      (Fee_Rb_DeviceName_ten deviceName_en);
LOCAL_INLINE uint16    Fee_Prv_ChunkGetNoFallbackBitmask    (Fee_Rb_DeviceName_ten deviceName_en);

LOCAL_INLINE boolean    Fee_Prv_ChunkIsHdrVld (Fee_Prv_ChunkHdr_tst const * xHdr_pcst);
LOCAL_INLINE boolean    Fee_Prv_ChunkCreatHdr (
        Fee_Rb_DeviceName_ten deviceName_en,
        Fee_Prv_JobDesc_tst const * xJob_pcst,
        MemIf_JobResultType stRes_en);

LOCAL_INLINE Fee_Rb_JobMode_ten    Fee_Prv_ChunkGetJobMode (
        Fee_Rb_DeviceName_ten deviceName_en,
        Fee_Prv_ConfigDeviceTable_tst const * xCfgDevTbl_pcst,
        Fee_Rb_JobType_ten idJobType_en);


/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/

/**
 * \brief   Provide a pointer to the block properties table for a given device instance (temporary helper function
 *          extending Fee_Prv_FsIfGetBlockPropertiesTable to FeeFs1 until the latter is removed in near future)
 *
 * \param   deviceName_en   Device instance, for which the block properties table is requested
 *
 * \return  Pointer to block properties table for given device instance
*/
LOCAL_INLINE Fee_Rb_BlockPropertiesType_tst const * Fee_Prv_ChunkGetBlockPropertiesTable(
        Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    Fee_Prv_Chunk_BlkPptyTbl_tun    xBlkPptyTbl_un;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* Fee_Prv_FsIfGetBlockPropertiesTable isn't supported for FeeFs1, so take this table from rba_FeeFs1_Prv.h */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        xBlkPptyTbl_un.xBlkPptyTbl_pcst = &Fee_BlockProperties_st[0];
    }
    else
# endif
    {
        xBlkPptyTbl_un.xRbBlkPptyTbl_pcst = Fee_Prv_FsIfGetBlockPropertiesTable(deviceName_en);
    }

    return(xBlkPptyTbl_un.xRbBlkPptyTbl_pcst);
}


/**
 * \brief   Provide the number of configured blocks for a given device instance (temporary helper function extending
 *          Fee_Prv_FsIfGetNrOfBlocks to FeeFs1 until the latter is removed in near future)
 *
 * \param   deviceName_en   Device instance, for which the number of configured blocks is requested
 *
 * \return  Number of configured blocks for given device instance
*/
LOCAL_INLINE uint16 Fee_Prv_ChunkGetNrOfBlocks(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    uint16    nrOfBlocks_u16;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* Fee_Prv_FsIfGetNrOfBlocks isn't supported for FeeFs1, so take this number from rba_FeeFs1_Prv_Cfg.h */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        nrOfBlocks_u16 = FEE_NUM_BLOCKS;
    }
    else
# endif
    {
        nrOfBlocks_u16 = Fee_Prv_FsIfGetNrOfBlocks(deviceName_en);
    }

    return(nrOfBlocks_u16);
}


/**
 * \brief   Provide the double storage bitmask for a given device instance (temporary helper function extending
 *          Fee_Prv_FsIfGetDoubleStorageBitmask to FeeFs1 until the latter is removed in near future)
 *
 * \param   deviceName_en   Device instance, for which the double storage bitmask is requested
 *
 * \return  Double storage bitmask for given device instance
*/
LOCAL_INLINE uint16 Fee_Prv_ChunkGetDoubleStorageBitmask(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    uint16    flgDoubleStorage_u16;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* Fee_Prv_FsIfGetDoubleStorageBitmask isn't supported for FeeFs1, so take this mask from rba_FeeFs1_Prv.h. */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        flgDoubleStorage_u16 = FEE_FLAG_SEC_LEVEL_MSK;
    }
    else
# endif
    {
        flgDoubleStorage_u16 = Fee_Prv_FsIfGetDoubleStorageBitmask(deviceName_en);
    }

    return(flgDoubleStorage_u16);
}


/**
 * \brief   Provide the survival bitmask for a given device instance (temporary helper function extending
 *          Fee_Prv_FsIfGetNoFallbackBitmask to FeeFs1 until the latter is removed in near future)
 *
 * \param   deviceName_en   Device instance, for which the survival bitmask is requested
 *
 * \return  Survival bitmask for given device instance
*/
LOCAL_INLINE uint16 Fee_Prv_ChunkGetSurvivalBitmask(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    uint16    flgSurvival_u16;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* Fee_Prv_FsIfGetSurvivalBitmask isn't supported for FeeFs1, so take this mask from rba_FeeFs1_Prv.h. */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        flgSurvival_u16 = FEE_FLAG_SURV_ATTR_MSK;
    }
    else
# endif
    {
        flgSurvival_u16 = Fee_Prv_FsIfGetSurvivalBitmask(deviceName_en);
    }

    return(flgSurvival_u16);
}


/**
 * \brief   Provide the no-fallback bitmask for a given device instance (temporary helper function extending
 *          Fee_Prv_FsIfGetSurvivalBitmask to FeeFs1 until the latter is removed in near future)
 *
 * \param   deviceName_en   Device instance, for which the no-fallback bitmask is requested
 *
 * \return  No-fallback bitmask for given device instance
*/
LOCAL_INLINE uint16 Fee_Prv_ChunkGetNoFallbackBitmask (Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    uint16    flgNoFallback_u16;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* Fee_Prv_FsIfGetNoFallbackBitmask isn't supported for FeeFs1, so take this mask from rba_FeeFs1_Prv.h. */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        flgNoFallback_u16 = FEE_FLAG_NOFALLBACK_MSK;
    }
    else
# endif
    {
        flgNoFallback_u16 = Fee_Prv_FsIfGetNoFallbackBitmask(deviceName_en);
    }

    return(flgNoFallback_u16);
}


/**
 * \brief   Provide the length of a given block for a given device instance (temporary helper function extending
 *          Fee_Prv_ConfigGetBlockLengthByBlockNr to FeeFs1 until the latter is removed in near future)
 *
 * \param   deviceName_en      Device instance, for which the block number and properties table are given
 * \param   nrBlk_u16          Block number, for which the length is requested
 * \param   xBlkPptyTbl_pcst   Pointer to block properties table
 *
 * \return  Length of given block for given device instance
*/
static uint16 Fee_Prv_ChunkGetBlockLengthByBlockNr(
        Fee_Rb_DeviceName_ten deviceName_en,
        uint16 nrBlk_u16,
        Fee_Rb_BlockPropertiesType_tst const * xBlkPptyTbl_pcst)
{
    /* Return variable */
    uint16    nrLen_u16 = Fee_Prv_ConfigGetBlockLengthByBlockNr(nrBlk_u16, xBlkPptyTbl_pcst);

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE  ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* FeeFs1 includes data CRC32 into robust block length, but NvM/rba_MemBkup/... don't => length must be patched! */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        if(Fee_Prv_ConfigIsBlockRobustnessActiveByBlockNr(nrBlk_u16, FEE_FLAG_ROBUST_ATTR_MSK, xBlkPptyTbl_pcst))
        {
            nrLen_u16 -= (uint16)sizeof(uint32);
        }
        else
        {
            /* Keep configured length */
        }
    }
    else
    {
        /* Keep configured length */
    }
# else
    (void)deviceName_en;
# endif

    return(nrLen_u16);
}


/**
 * \brief   Provide a pointer to the GetJobResult function for a given block (temporary helper for FeeFs1 until the
 *          latter is removed in near future)
 *
 * \param   nrBlk_u16   Block number, for which the GetJobResult function is requested
 *
 * \return  Pointer to Fee_GetJobResult or Fee_Rb_GetAdapterJobResult depending on the given block's requester
*/
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
static Fee_Prv_ChunkGetJobResult_tpfct Fee_Prv_ChunkGetJobResultFct(uint16 nrBlk_u16)
{
    /* Return variable */
    Fee_Prv_ChunkGetJobResult_tpfct    xGetJobResult_pfct;

    /* Local variables */
    Fee_Prv_Chunk_BlkPptyTbl_tun    xBlkPptyTbl_un;
    Fee_Prv_ConfigRequester_ten     idRequester_en = FEE_PRV_REQUESTER_MAX_E;

    /* Block known? */
    if(FEE_PRV_MAX_UINT16 != nrBlk_u16)
    {
        /* Get block's requester */
        xBlkPptyTbl_un.xBlkPptyTbl_pcst = &Fee_BlockProperties_st[0];
        idRequester_en = Fee_Prv_ConfigGetBlockRequesterByBlockNr(nrBlk_u16, xBlkPptyTbl_un.xRbBlkPptyTbl_pcst);
    }
    else
    {
        /* Unknown block, i.e. the request is unknown as well */
        idRequester_en= FEE_PRV_REQUESTER_MAX_E;
    }

    /* Determine the job result function for the block's user
     * For a better readability, the coding rule CCode_BlockStyle_001 is not followed here on purpose. */
    switch(idRequester_en)
    {
        case FEE_PRV_REQUESTER_NVM_E     : {xGetJobResult_pfct = Fee_GetJobResult          ;} break;
        case FEE_PRV_REQUESTER_ADAPTER_E : {xGetJobResult_pfct = Fee_Rb_GetAdapterJobResult;} break;
        default                          : {xGetJobResult_pfct = NULL_PTR                  ;} break;
    }

    return(xGetJobResult_pfct);
}
# endif


/**
 * \brief   Check whether all general conditions are met to start or continue a chunk-wise job
 *
 * \param   deviceName_en   Device instance to be checked
 * \param   idApi_u8        API requesting this check (needed for Fee_Prv_LibDetReport in case of an error)
 * \param   dataBuf_pcu8    Buffer location to be checked
 * \param   nrBytMax_u32    Maximum number of bytes in buffer
 * \param   nrBytMin_u32    Minimum number of bytes expected
 *
 * \return  Result of check
 * \retval  E_OK      if all general conditions are met
 * \retval  E_NOT_OK  if any general condition is not met
*/
static Std_ReturnType Fee_Prv_ChunkDetChkGnrl(
        Fee_Rb_DeviceName_ten deviceName_en,
        uint8 idApi_u8,
        uint8 const * dataBuf_pcu8,
        uint32 nrBytMax_u32,
        uint32 nrBytMin_u32)
{
    /* Return variable */
    Std_ReturnType          stRet_u8;
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    uint8                   secondInstanceDeviceIdx_u8;
    Fee_Rb_DeviceName_ten   secondInstanceDeviceName_en;
# endif

    /* Device name okay? */
    stRet_u8 = Fee_Prv_OrderDetCheckDeviceName(deviceName_en, idApi_u8);
    if(E_OK == stRet_u8)
    {
        /* Fee not yet initialized or in stop mode? */
        if(E_OK != Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, idApi_u8))
        {
            stRet_u8 = E_NOT_OK;
        }
        else
        {
            /* When Fee1.0 is used, the static variables of Chunk unit should also be initialized before placing the request.
             * The variable is initialized during Fee_Init of the second instance. So before accepting any request for Fee1.0,
             * check if the second instance is initialized.
             * Without this change, all chunk jobs in Fee1.0 are rejected, if Fee_Init() is called more then once during
             * a driving cycle (CT tests of rba_MemBckUp fails without this change). */
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
            if(Fee_Rb_DeviceName == deviceName_en)
            {
                /* Order is for Fee1.0, check if the second instance is also initialized before accepting the request.
                 * To get the device index and device name for second instance the information is directly taken from the
                 * second instance of the device config table. This is ok because of the following reasons:
                 * 1. So far maximum of two instances are supported and
                 * 2. When multi instance is enabled with Fee1.0, the first instance is always Fee1.0 and second instance
                 * is always != Fee1.0 */
                secondInstanceDeviceIdx_u8 = Fee_Prv_ConfigDeviceTable_cast[1u].deviceIdx_u8;
                secondInstanceDeviceName_en = Fee_Rb_GetDeviceNameFromDeviceIndex(secondInstanceDeviceIdx_u8);

                /* Deviation: Not calling Fee_Prv_OrderDetCheckModuleInitAndStopMode() here. */
                /* Reason: It could be possible to continue to work with chunk operations for Fee1.0 even when other
                 * instance is put the stop mode. Important is that second instance has to be initialized correctly. */
                if(MEMIF_UNINIT == Fee_Rb_Idx_GetStatus(secondInstanceDeviceName_en))
                {
                    Fee_Prv_LibDetReport(secondInstanceDeviceName_en, idApi_u8, FEE_E_UNINIT);
                    stRet_u8 = E_NOT_OK;
                }
            }
# endif
        }

        /* Provided buffer invalid? */
        /* MR12 DIR 1.1 VIOLATION: uint8 * can always be converted safely to void * */
        if(E_OK != Fee_Prv_OrderDetCheckAdrPtr(deviceName_en, idApi_u8, (void const *)dataBuf_pcu8))
        {
            stRet_u8 = E_NOT_OK;
        }
        else
        {
            /* Keep stRet_u8 as is */
        }

        /* Data doesn't fit into chunk/provided buffer? */
        if(nrBytMin_u32 > nrBytMax_u32)
        {
            Fee_Prv_LibDetReport(deviceName_en, idApi_u8, FEE_E_INVALID_BUF_LEN);
            stRet_u8 = E_NOT_OK;
        }
        else
        {
            /* Keep stRet_u8 as is */
        }
    }
    else
    {
        /* Keep stRet_u8 = E_NOT_OK */
    }

    return(stRet_u8);
}


/**
 * \brief   Check whether all file system specific conditions are met to start a chunk-wise job
 *
 * \param   deviceName_en     Device instance, for which conditions are to be checked
 * \param   idApi_u8          API requesting this check (needed for Fee_Prv_LibDetReport in case of an error)
 * \param   xCfgDevTbl_pcst   Pointer to config table (not used for FeeFs1)
 * \param   nrBytMax_u32      Maximum number of bytes in buffer
 * \param   nrTotLen_u32      Total data length (counted over all chunks)
 *
 * \return  Result of check
 * \retval  E_OK      if all file system specific conditions are met
 * \retval  E_NOT_OK  if any file system specific condition is not met
*/
static Std_ReturnType Fee_Prv_ChunkDetChkFsSpc(
        Fee_Rb_DeviceName_ten deviceName_en,
        uint8 idApi_u8,
        Fee_Prv_ConfigDeviceTable_tst const * xCfgDevTbl_pcst,
        uint32 nrBytMax_u32,
        uint32 nrTotLen_u32)
{
    /* Return variable */
    Std_ReturnType    stRet_u8 = E_OK;

    /* Local variable */
    Fee_Prv_JobDesc_tst const *    xJob_pcst;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE  ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* FeeFs1 doesn't support a real chunk-wise job, i.e. complete payload + chunk header must fit into buffer */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        if(nrTotLen_u32 > nrBytMax_u32)
        {
            Fee_Prv_LibDetReport(deviceName_en, idApi_u8, FEE_E_INVALID_BUF_LEN);
            stRet_u8 = E_NOT_OK;
        }
        else
        {
            /* Keep stRet_u8 as is */
        }
    }
    else
# else
    (void)nrBytMax_u32;
    (void)nrTotLen_u32;
# endif
    {
        /* Get active job */
        xJob_pcst = Fee_Prv_JobGetActv(xCfgDevTbl_pcst, FEE_PRV_REQUESTER_CHUNK_E);

        /* Waiting to read/write next chunk? */
        if(FEE_RB_JOBTYPE_WAIT_NEXT_CHUNK_E == xJob_pcst->type_en)
        {
            /* Deny request in case we are waiting to read next chunk */
            Fee_Prv_LibDetReport(deviceName_en, idApi_u8, FEE_E_INVALID_SEQUENCE);
            stRet_u8 = E_NOT_OK;
        }
        else
        {
            /* Keep stRet_u8 = E_OK */
        }
    }

    return(stRet_u8);
}


/**
 * \brief   Check whether a given chunk header is valid
 *
 * \param   xHdr_pcst   Pointer to header to be checked
 *
 * \return  Result of check
 * \retval  TRUE   if header is valid
 * \retval  FALSE  if header is invalid
*/
LOCAL_INLINE boolean Fee_Prv_ChunkIsHdrVld(Fee_Prv_ChunkHdr_tst const * xHdr_pcst)
{
    /* Calculate CRC over chunk header */
    uint16    xCrc_u16 = Crc_CalculateCRC16(
                            (uint8 const *)xHdr_pcst,
                            sizeof(Fee_Prv_ChunkHdr_tst) - sizeof(xHdr_pcst->xCrc_u16),
                            CRC_INITIAL_VALUE16,
                            TRUE );

    /* The chunk header is valid, if its CRC is correct */
    return(xHdr_pcst->xCrc_u16 == xCrc_u16);
}


/**
 * \brief   Create chunk header in the read job's buffer for a given job result and device instance
 *
 * \param   deviceName_en   Device instance, for which chunk header is requested
 * \param   xJob_pcst       Pointer to job description
 * \param   stRes_en        Job result
 *
 * \return  Payload status of chunk-wise read
 * \retval  TRUE   if header has been created for a chunk-wise read containing payload
 * \retval  FALSE  if header has been created for a chunk-wise read containing no payload
*/
LOCAL_INLINE boolean Fee_Prv_ChunkCreatHdr(
        Fee_Rb_DeviceName_ten deviceName_en,
        Fee_Prv_JobDesc_tst const * xJob_pcst,
        MemIf_JobResultType stRes_en)
{
    /* Return variable */
    boolean    hasData_b = TRUE;

    /* Local variables */
    Fee_Prv_ChunkHdr_tst                      xHdr_st;
    Fee_Rb_BlockPropertiesType_tst const *    xBlkPptyTbl_pcst = Fee_Prv_ChunkGetBlockPropertiesTable(deviceName_en);

    /* Fill chunk header with block properties */
    xHdr_st.idPers_u16   = Fee_Prv_ConfigGetBlockPersistentIdByBlockNr(
                            xJob_pcst->blockNumber_u16,
                            xBlkPptyTbl_pcst );
    xHdr_st.nrLen_u16    = Fee_Prv_ChunkGetBlockLengthByBlockNr(
                            deviceName_en,
                            xJob_pcst->blockNumber_u16,
                            xBlkPptyTbl_pcst );
    xHdr_st.stFlg_u16    = 0u;
    xHdr_st.xResv_au8[0] = 0u;
    xHdr_st.xResv_au8[1] = 0u;

    /* Set double storage bit in chunk header's status byte depending on block property */
    if(Fee_Prv_ConfigIsBlockDoubleStorageActiveByBlockNr(
            xJob_pcst->blockNumber_u16,
            Fee_Prv_ChunkGetDoubleStorageBitmask(deviceName_en),
            xBlkPptyTbl_pcst) )
    {
        xHdr_st.stFlg_u16 |= FEE_PRV_CHUNK_DOUBLESTORAGE_BIT;
    }
    else
    {
        /* Keep FEE_PRV_CHUNK_DOUBLESTORAGE_BIT cleared */
    }

    /* Set survival bit in chunk header's status byte depending on block property */
    if(Fee_Prv_ConfigIsBlockSurvivalActiveByBlockNr(
            xJob_pcst->blockNumber_u16,
            Fee_Prv_ChunkGetSurvivalBitmask(deviceName_en),
            xBlkPptyTbl_pcst) )
    {
        xHdr_st.stFlg_u16 |= FEE_PRV_CHUNK_SURVIVAL_BIT;
    }
    else
    {
        /* Keep FEE_PRV_CHUNK_SURVIVAL_BIT cleared */
    }

    /* Set no-fallback bit in chunk header's status byte depending on block property */
    if(Fee_Prv_ConfigIsBlockNoFallbackActiveByBlockNr(
            xJob_pcst->blockNumber_u16,
            Fee_Prv_ChunkGetNoFallbackBitmask(deviceName_en),
            xBlkPptyTbl_pcst) )
    {
        xHdr_st.stFlg_u16 |= FEE_PRV_CHUNK_NOFALLBACK_BIT;
    }
    else
    {
        /* Keep FEE_PRV_CHUNK_NOFALLBACK_BIT cleared */
    }

    /* Set invalidate and erase bit in chunk header's status byte depending on block status.
     * For a better readability, the coding rule CCode_BlockStyle_001 is not followed here on purpose. */
    switch(stRes_en)
    {
        case MEMIF_BLOCK_INVALID:      {xHdr_st.stFlg_u16 |= FEE_PRV_CHUNK_INVALIDATE_BIT;    hasData_b = FALSE;} break;
        case MEMIF_BLOCK_INCONSISTENT: {xHdr_st.stFlg_u16 |= FEE_PRV_CHUNK_BLOCK_NOT_PRESENT_BIT; hasData_b = FALSE;} break;
        default:                       {   /* Keep both status bits cleared, and hasData_b = TRUE */   } break;
    }

    /* Append CRC behind chunk header */
    xHdr_st.xCrc_u16 = Crc_CalculateCRC16(
                            (uint8 const *)&xHdr_st,
                            sizeof(Fee_Prv_ChunkHdr_tst) - sizeof(xHdr_st.xCrc_u16),
                            CRC_INITIAL_VALUE16,
                            TRUE );

    /* Copy chunk header into user buffer */
    rba_MemLib_MemCopy(
            (uint8 *)&xHdr_st,
            xJob_pcst->bfr_pu8 - sizeof(Fee_Prv_ChunkHdr_tst),
            sizeof(Fee_Prv_ChunkHdr_tst) );

    return(hasData_b);
}


/**
 * \brief   Provide the job mode for a given job type and device instance (temporary helper function extending
 *          Fee_Prv_JobGetJobMode to FeeFs1 until the latter is removed in near future)
 *
 * \param   deviceName_en     Device instance, for which config table is provided
 * \param   xCfgDevTbl_pcst   Pointer to config table
 * \param   idJobType_en      Job type
 *
 * \return  Job mode for given job type and device instance
*/
LOCAL_INLINE Fee_Rb_JobMode_ten Fee_Prv_ChunkGetJobMode(
        Fee_Rb_DeviceName_ten deviceName_en,
        Fee_Prv_ConfigDeviceTable_tst const * xCfgDevTbl_pcst,
        Fee_Rb_JobType_ten idJobType_en)
{
    /* Return variable */
    Fee_Rb_JobMode_ten    idJobMode_en;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
    /* Fee_Prv_JobGetJobMode isn't supported for FeeFs1, value actually doesn't matter */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        idJobMode_en = FEE_RB_ALLJOBS_ALLSTEPS_E;
    }
    else
# else
    (void)deviceName_en;
# endif
    {
        idJobMode_en = Fee_Prv_JobGetJobMode(xCfgDevTbl_pcst, idJobType_en);
    }

    return(idJobMode_en);
}


/**
 * \brief   Request to process a job (temporary helper function extending Fee_Prv_JobPut to FeeFs1 until the latter
 *          is removed in near future)
 *
 * \param   deviceName_en   Device instance, for which job is requested
 * \param   idApi_u8        API requesting the job (needed for Fee_Prv_LibDetReport in case of an error)
 * \param   xJob_pcst       Pointer to job description
 *
 * \return  Request acceptance
 * \retval  E_OK      The request has been accepted, and the job processing is started
 * \retval  E_NOT_OK  The request has been erroneous and therefore been rejected
*/
static Std_ReturnType Fee_Prv_ChunkPut(
        Fee_Rb_DeviceName_ten deviceName_en,
        uint8 idApi_u8,
        Fee_Prv_JobDesc_tst const * xJob_pcst)
{
    /* Return variable */
    Std_ReturnType    stRet_u8;

# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))

    /* Local variables */
    Fee_Prv_ChunkGetJobResult_tpfct    xGetJobResult_pfct;
    Fee_Prv_LibBufferU8_tun            dataBuf_un;

    /* In FeeFs1, request the read/write/invalidate directly via its public interfaces */
    if(Fee_Rb_DeviceName == deviceName_en)
    {
        /* Slot available for job? */
        xGetJobResult_pfct = Fee_Prv_ChunkGetJobResultFct(xJob_pcst->blockNumber_u16);
        if(    (MEMIF_JOB_PENDING      != xGetJobResult_pfct())
            && (FEE_RB_CHUNK_PENDING_E != Fee_Prv_ChunkInfo_st.result_en) )
        {
            switch(xJob_pcst->type_en)
            {
                case FEE_RB_JOBTYPE_READ_E:
                {
                    stRet_u8 = Fee_Read(
                            xJob_pcst->blockNumber_u16,
                            xJob_pcst->offset_u16,
                            xJob_pcst->bfr_pu8,
                            xJob_pcst->length_u16);
                }
                break;

                case FEE_RB_JOBTYPE_WRITE_E:
                {
                    /* Avoid compiler warning "Passing argument 3 of 'Fee_Rb_Idx_Write'
                     * discards * 'const' qualifier from pointer target type. */
                    dataBuf_un.dataCon_pcu8 = xJob_pcst->bfr_pcu8;

                    stRet_u8 = Fee_Write(
                            xJob_pcst->blockNumber_u16,
                            dataBuf_un.dataChg_pu8);
                }
                break;

                case FEE_RB_JOBTYPE_INVALIDATE_E:
                {
                    stRet_u8 = Fee_InvalidateBlock(xJob_pcst->blockNumber_u16);
                }
                break;

                default:
                {
                    stRet_u8 = E_NOT_OK;
                }
                break;
            }
        }
        else
        {
            /* Deny request; job slot is occupied */
            Fee_Prv_LibDetReport(deviceName_en, idApi_u8, FEE_E_BUSY_INTERNAL);
            stRet_u8 = E_NOT_OK;
        }

        /* Request has been accepted? */
        if(E_OK == stRet_u8)
        {
            SchM_Enter_Fee_Order();

            /* Memorize GetJobResult function (this also indicates that a chunk is under processing) */
            Fee_Prv_ChunkGetJobResult_pfct = xGetJobResult_pfct;

            /* Reset chunk-wise job status */
            Fee_Prv_ChunkInfo_st.nrBytProc_u32 = 0uL;
            Fee_Prv_ChunkInfo_st.result_en     = FEE_RB_CHUNK_PENDING_E;

            SchM_Exit_Fee_Order();

            /* Memorize job details */
            Fee_Prv_ChunkJob_st = *xJob_pcst;
        }
        else
        {
            /* Do nothing */
        }
    }
    else
# endif
    {
        /* Start chunk-wise job */
        stRet_u8 = Fee_Prv_JobPut(deviceName_en, idApi_u8, xJob_pcst);
    }

    return(stRet_u8);
}


/**
 * \brief   Callback function to be called upon completion or termination of every processed chunk. It determines
 *          and provides the chunk status (i.e. result as well as number of processed bytes) in the given pointer.
 *          For the first chunk-wise read, it additionally provides the chunk header in the given job's buffer.
 *
 * \param   deviceName_en   Device instance, for which chunk processing has succeeded, failed or been terminated
 * \param   xJob_pcst       Pointer to job description
 * \param   stRes_en        Job result
 * \param   stChunk_pst     Pointer to location, where the chunk status is stored
*/
void Fee_Prv_ChunkDoneCbk(
        Fee_Rb_DeviceName_ten deviceName_en,
        Fee_Prv_JobDesc_tst const * xJob_pcst,
        MemIf_JobResultType stRes_en,
        Fee_Prv_JobChunkInfo_tst * stChunk_pst)
{
    /* Local variable */
    boolean    hasData_b = TRUE;

    /* Assume chunk without payload */
    stChunk_pst->nrBytProc_u32 = 0u;

    /* Fill chunk header and update chunk status */
    if(MEMIF_JOB_FAILED == stRes_en)
    {
        /* Update chunk result for failed chunk(-wise job) */
        stChunk_pst->result_en = FEE_RB_CHUNK_FAILED_E;
    }
    else if(MEMIF_JOB_CANCELED == stRes_en)
    {
        /* Update chunk result for terminated chunk(-wise job) */
        stChunk_pst->result_en = FEE_RB_CHUNK_TERMINATED_E;
    }
    else
    {
        /* First chunk? */
        if(0u == xJob_pcst->cntrBytDone_u16)
        {
            /* Chunk-wise read? */
            if(FEE_RB_JOBTYPE_READ_E == xJob_pcst->type_en)
            {
                /* Create chunk header in buffer, which the job is working on */
                hasData_b = Fee_Prv_ChunkCreatHdr(deviceName_en, xJob_pcst, stRes_en);
            }
            else if(FEE_RB_JOBTYPE_INVALIDATE_E == xJob_pcst->type_en)
            {
                /* Block invalidation => chunk without payload */
                hasData_b = FALSE;
            }
            else
            {
                /* First chunk of chunk-wise write; keep hasData_b = TRUE */
            }

            /* Consider chunk header in number of processed bytes for first chunk */
            stChunk_pst->nrBytProc_u32 = sizeof(Fee_Prv_ChunkHdr_tst);
        }
        else
        {
            /* For subsequent chunks, keep stChunk_pst->nrBytProc_u32 = 0uL and hasData_b = TRUE */
        }

        /* Chunk with payload? */
        if(hasData_b)
        {
            /* Consider payload in number of processed bytes */
            stChunk_pst->nrBytProc_u32 += xJob_pcst->length_u16;

            /* All payload processed? */
            if((xJob_pcst->cntrBytDone_u16 + xJob_pcst->length_u16) >= xJob_pcst->nrBytTot_u16)
            {
                /* We are completely done! */
                stChunk_pst->result_en = FEE_RB_CHUNK_ALL_OK_E;
            }
            else
            {
                /* We need to wait for the next chunk */
                stChunk_pst->result_en = FEE_RB_CHUNK_PART_OK_E;
            }
        }
        else
        {
            /* Chunk without payload; we are completely done! */
            stChunk_pst->result_en = FEE_RB_CHUNK_ALL_OK_E;
        }
    }

    return;
}


/**
 * \brief   Function called during Fee_Init(). Initializes all the variables of this unit.
 *  The below implementation is needed only when Fee1 is used and the static variables are needed.
 *  When Fee1.0 is not used, there are no static variables in Chunk unit and so the function could be dummy
 *  (dummy function implemented in header file Fee_Prv_Chunk.h).
 *
 * \param   none
 *
 * \return  none
*/
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
void Fee_Prv_ChunkInit(void)
{
    Fee_Prv_ChunkGetJobResult_pfct = NULL_PTR;

    Fee_Prv_ChunkJob_st.type_en = FEE_RB_JOBTYPE_MAX_E;

    Fee_Prv_ChunkInfo_st.nrBytProc_u32 = 0uL;
    Fee_Prv_ChunkInfo_st.result_en     = FEE_RB_CHUNK_ALL_OK_E;

}
# endif

/**
 * \brief   Request to start a chunk-wise read job with the first chunk
 *
 * \param   deviceName_en  Device instance, for which job is requested
 * \param   idPers_u16     Block's persistent ID (unique block identifier)
 * \param   nrBlkLen_u16   Block's payload length (in bytes, excluding CRC32)
 * \param   dataBuf_pu8    Buffer location, where chunk data is copied into
 * \param   nrBytMax_u32   Maximum number of bytes, which can be copied into buffer
 *
 * \return  Request acceptance
 * \retval  E_OK     The request has been accepted, and the job processing is started
 * \retval  E_NO_OK  The request has been erroneous and therefore been rejected
*/
Std_ReturnType Fee_Rb_Idx_ChunkReadFirst(
        Fee_Rb_DeviceName_ten deviceName_en,
        uint16 idPers_u16,
        uint16 nrBlkLen_u16,
        uint8 * dataBuf_pu8,
        uint32 nrBytMax_u32)
{
    /* Return variable */
    Std_ReturnType    stRet_u8;

    /* Local variables */
    Fee_Prv_ConfigDeviceTable_tst const *     xCfgDevTbl_pcst;
    Fee_Rb_BlockPropertiesType_tst const *    xBlkPptyTbl_pcst;
    uint16                                    nrOfBlks_u16, nrBlk_u16;
    Fee_Prv_JobDesc_tst                       xJob_st;

    /* Check request in general */
    stRet_u8 = Fee_Prv_ChunkDetChkGnrl(
                deviceName_en,
                FEE_SID_RB_CHUNK_READ_FIRST,
                dataBuf_pu8,
                nrBytMax_u32,
                sizeof(Fee_Prv_ChunkHdr_tst) + 1uL );
    if(E_OK == stRet_u8)
    {
        /* Get config table */
        xCfgDevTbl_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

        /* Convert persistent ID into block number */
        nrOfBlks_u16     = Fee_Prv_ChunkGetNrOfBlocks(deviceName_en);
        xBlkPptyTbl_pcst = Fee_Prv_ChunkGetBlockPropertiesTable(deviceName_en);
        nrBlk_u16        = Fee_Prv_ConfigGetBlockNrByPersistentId(idPers_u16, nrOfBlks_u16, xBlkPptyTbl_pcst);

        /* Block unknown? */
        if(FEE_PRV_MAX_UINT16 == nrBlk_u16)
        {
            /* Deny request; the chunk-wise read doesn't support unknown blocks (in none of the file systems) */
            Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_READ_FIRST, FEE_E_INVALID_BLOCK_NO);
            stRet_u8 = E_NOT_OK;
        }
        else
        {
            /* Check requested length against configured block length */
            stRet_u8 = Fee_Prv_OrderDetCheckBlkLen(
                        deviceName_en,
                        FEE_SID_RB_CHUNK_READ_FIRST,
                        nrBlk_u16,
                        0u,
                        nrBlkLen_u16,
                        xBlkPptyTbl_pcst );
        }

        /* Check request for file system specific conditions */
        if(E_OK != Fee_Prv_ChunkDetChkFsSpc(
                    deviceName_en,
                    FEE_SID_RB_CHUNK_READ_FIRST,
                    xCfgDevTbl_pcst,
                    nrBytMax_u32,
                    sizeof(Fee_Prv_ChunkHdr_tst)+(uint32)nrBlkLen_u16) )
        {
            /* Deny request, DET entry has been done by Fee_Prv_ChunkDetChkFsSpc */
            stRet_u8 = E_NOT_OK;
        }
        else
        {
            /* Keep stRet_u8 as is */
        }
    }
    else
    {
        /* Deny request and keep stRet_u8 = E_NOT_OK, DET entry done by Fee_Prv_ChunkDetChkGnrl */
    }

    /* Request valid? */
    if(E_OK == stRet_u8)
    {
        /* Setup descriptor for chunk-wise job */
        xJob_st.type_en         = FEE_RB_JOBTYPE_READ_E;
        xJob_st.jobMode_en      = Fee_Prv_ChunkGetJobMode(deviceName_en, xCfgDevTbl_pcst, xJob_st.type_en);
        xJob_st.bfr_pu8         = dataBuf_pu8 + sizeof(Fee_Prv_ChunkHdr_tst);
        xJob_st.bfr_pcu8        = NULL_PTR;
        xJob_st.idPers_u16      = idPers_u16;
        xJob_st.blockNumber_u16 = nrBlk_u16;
        xJob_st.length_u16      = (uint16)rba_MemLib_Min(nrBlkLen_u16, nrBytMax_u32 - sizeof(Fee_Prv_ChunkHdr_tst));
        xJob_st.offset_u16      = 0u;
        xJob_st.nrBytTot_u16    = nrBlkLen_u16;
        xJob_st.cntrBytDone_u16 = 0u;
        xJob_st.isChunkJob_b    = TRUE;
        xJob_st.statusFlag_u16  = 0u;    // dummy value. correct value to be picked up by FeeFsx
        xJob_st.isUnknownBlk_b  = FALSE; // currently only known block read operation is supported

        /* Start chunk-wise job */
        stRet_u8 = Fee_Prv_ChunkPut(deviceName_en, FEE_SID_RB_CHUNK_READ_FIRST, &xJob_st);
    }
    else
    {
        /* Keep stRet_u8 = E_NOT_OK */
    }

    return(stRet_u8);
}


/**
 * \brief   Request to start a chunk-wise write job with the first chunk
 *
 * \param   deviceName_en   Device instance, for which job is requested
 * \param   nrTotLen_u32    Total data length (counted over all chunks)
 * \param   dataBuf_pcu8    Buffer location, from where chunk data is copied
 * \param   nrBytMax_u32    Maximum number of bytes, which can be copied from buffer
 *
 * \return  Request acceptance
 * \retval  E_OK     The request has been accepted, and the job processing is started
 * \retval  E_NO_OK  The request has been erroneous and therefore been rejected
*/
Std_ReturnType Fee_Rb_Idx_ChunkWriteFirst(
        Fee_Rb_DeviceName_ten deviceName_en,
        uint32 nrTotLen_u32,
        uint8 const * dataBuf_pcu8,
        uint32 nrBytMax_u32)
{
    /* Return variable */
    Std_ReturnType    stRet_u8;

    /* Local variables */
    Fee_Prv_ConfigDeviceTable_tst const *     xCfgDevTbl_pcst;
    Fee_Prv_ChunkHdr_tst                      xHdr_st = {0};
    Fee_Rb_BlockPropertiesType_tst const *    xBlkPptyTbl_pcst;
    uint16                                    nrOfBlks_u16, nrBlk_u16;
    uint32                                    nrLen_u32;
    Fee_Prv_JobDesc_tst                       xJob_st;
    boolean                                   isUnknownBlk_b = FALSE;
    uint16                                    statusFlag_u16 = 0u;

    /* Check request in general
     * Note: A real chunk-wise write is not yet supported, i.e. complete payload+chunk header must fit into buffer.
     * When support is added, we can call Fee_Prv_ChunkDetChkGnrl with nrBytMin_u32 = sizeof(Fee_Prv_ChunkHdr_tst)
     * and nrBytMax_u32 = rba_MemLib_Min(nrBytMax_u32, nrTotLen_32). At that time, we can add the check for FeeFs1
     * into Fee_Prv_ChunkDetChkFsSpc, i.e. call it with nrBytMax_u32 instead of FEE_PRV_MAX_UINT32. */
    stRet_u8 = Fee_Prv_ChunkDetChkGnrl(
                deviceName_en,
                FEE_SID_RB_CHUNK_WRITE_FIRST,
                dataBuf_pcu8,
                nrBytMax_u32,
                nrTotLen_u32 );
    if(E_OK == stRet_u8)
    {
        /* Chunk header valid? Since the chunk header inside the user buffer might
         * not be aligned on a 16-bit boundary, we have to copy it onto stack. */
        rba_MemLib_MemCopy(dataBuf_pcu8, (uint8 *)&xHdr_st, sizeof(Fee_Prv_ChunkHdr_tst));
        if(Fee_Prv_ChunkIsHdrVld(&xHdr_st))
        {
            /* Get config table */
            xCfgDevTbl_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);

            /* Determine block length from request parameters */
            nrLen_u32 = nrTotLen_u32 - sizeof(Fee_Prv_ChunkHdr_tst);

            /* Convert persistent ID into block number */
            nrOfBlks_u16     = Fee_Prv_ChunkGetNrOfBlocks(deviceName_en);
            xBlkPptyTbl_pcst = Fee_Prv_ChunkGetBlockPropertiesTable(deviceName_en);
            nrBlk_u16        = Fee_Prv_ConfigGetBlockNrByPersistentId(
                                xHdr_st.idPers_u16,
                                nrOfBlks_u16,
                                xBlkPptyTbl_pcst );

            if(FEE_PRV_MAX_UINT16 == nrBlk_u16)
            {
                /*  Accept writing of unknown blocks only when either the 1. feature is supported by File system,
                 * 2. global after burner (boot mode) is enabled and 3. for survival block, the survival feature is enabled. */
                /* MR12 RULE 13.5 VIOLATION: Only getter without side effects */
                if((Fee_Prv_FsIfIsUnknownBlockWriteAllowed(deviceName_en)) ||
                   ((Fee_Prv_FsIfIsUnknownSurvivalBlockWriteAllowed(deviceName_en)) &&
                    (0u != (xHdr_st.stFlg_u16 & FEE_PRV_CHUNK_SURVIVAL_BIT))))
                {
                    /* Writing of unknown block is supported, prepare status flag to be sent along with the order */
                    if(0u != (xHdr_st.stFlg_u16 & FEE_PRV_CHUNK_DOUBLESTORAGE_BIT))
                    {
                        statusFlag_u16 |= Fee_Prv_ChunkGetDoubleStorageBitmask(deviceName_en);
                    }

                    if(0u != (xHdr_st.stFlg_u16 & FEE_PRV_CHUNK_SURVIVAL_BIT))
                    {
                        statusFlag_u16 |= Fee_Prv_ChunkGetSurvivalBitmask(deviceName_en);
                    }

                    if(0u != (xHdr_st.stFlg_u16 & FEE_PRV_CHUNK_NOFALLBACK_BIT))
                    {
                        statusFlag_u16 |= Fee_Prv_ChunkGetNoFallbackBitmask(deviceName_en);
                    }
                }
                else
                {
                    /* Deny request; the chunk-wise unkown block write is deactivated or not supported */
                    Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_WRITE_FIRST, FEE_E_INVALID_BLOCK_NO);
                    stRet_u8 = E_NOT_OK;
                }

                isUnknownBlk_b = TRUE;
            }
            else
            {
                /* For known blocks check requested against configured block length */
                stRet_u8 = Fee_Prv_OrderDetCheckBlkLen(
                            deviceName_en,
                            FEE_SID_RB_CHUNK_WRITE_FIRST,
                            nrBlk_u16,
                            0u,
                            xHdr_st.nrLen_u16,
                            xBlkPptyTbl_pcst );
            }

            /* Block present and not invalidated? */
            if( 0u == (xHdr_st.stFlg_u16 & (FEE_PRV_CHUNK_INVALIDATE_BIT|FEE_PRV_CHUNK_BLOCK_NOT_PRESENT_BIT)) )
            {
                /* Check requested length against block length inside chunk header */
                if((uint32)xHdr_st.nrLen_u16 != nrLen_u32)
                {
                    /* Deny request in case of a length mismatch */
                    Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_WRITE_FIRST, FEE_E_INVALID_MNGT_DATA);
                    stRet_u8 = E_NOT_OK;
                }
                else
                {
                    /* Keep stRet_u8 as is */
                }
            }
            else
            {
                /* Check requested length for an invalidated or erased block */
                if(0uL != nrLen_u32)
                {
                    /* Deny request in case of a length mismatch */
                    Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_WRITE_FIRST, FEE_E_INVALID_MNGT_DATA);
                    stRet_u8 = E_NOT_OK;
                }
                else
                {
                    /* Keep stRet_u8 as is */
                }
            }

            /* Check request for file system specific conditions */
            if(E_OK != Fee_Prv_ChunkDetChkFsSpc(
                        deviceName_en,
                        FEE_SID_RB_CHUNK_WRITE_FIRST,
                        xCfgDevTbl_pcst,
                        FEE_PRV_MAX_UINT32,
                        nrTotLen_u32) )
            {
                /* Deny request, DET entry has been done by Fee_Prv_ChunkDetChkFsSpc */
                stRet_u8 = E_NOT_OK;
            }
            else
            {
                /* Keep stRet_u8 as is */
            }
        }
        else
        {
            /* Deny request in case of an invalid header */
            Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_WRITE_FIRST, FEE_E_INVALID_MNGT_DATA);
            stRet_u8 = E_NOT_OK;
        }
    }
    else
    {
        /* Deny request and keep stRet_u8 = E_NOT_OK, DET entry done by Fee_Prv_ChunkDetChkGnrl */
    }

    /* Request valid? */
    if(E_OK == stRet_u8)
    {
        /* There is some block payload to write? */
        if(0uL < nrLen_u32)
        {
            /* Write  block */
            xJob_st.type_en      = FEE_RB_JOBTYPE_WRITE_E;
            xJob_st.nrBytTot_u16 = (uint16)nrLen_u32;
        }
        else
        {
            /* Invalidate block */
            xJob_st.type_en      = FEE_RB_JOBTYPE_INVALIDATE_E;
            xJob_st.nrBytTot_u16 = 0u;
        }

        /* Setup descriptor for chunk-wise job */
        xJob_st.jobMode_en      = Fee_Prv_ChunkGetJobMode(deviceName_en, xCfgDevTbl_pcst, xJob_st.type_en);
        xJob_st.bfr_pu8         = NULL_PTR;
        xJob_st.bfr_pcu8        = dataBuf_pcu8 + sizeof(Fee_Prv_ChunkHdr_tst);
        xJob_st.idPers_u16      = xHdr_st.idPers_u16;
        xJob_st.statusFlag_u16  = statusFlag_u16;
        xJob_st.isUnknownBlk_b  = isUnknownBlk_b;
        xJob_st.blockNumber_u16 = nrBlk_u16;
        xJob_st.length_u16      = (uint16)rba_MemLib_Min(nrLen_u32, nrBytMax_u32 - sizeof(Fee_Prv_ChunkHdr_tst));
        xJob_st.offset_u16      = 0u;
        xJob_st.cntrBytDone_u16 = 0u;
        xJob_st.isChunkJob_b    = TRUE;

        /* Start chunk-wise job */
        stRet_u8 = Fee_Prv_ChunkPut(deviceName_en, FEE_SID_RB_CHUNK_WRITE_FIRST, &xJob_st);
    }
    else
    {
        /* Keep stRet_u8 = E_NOT_OK */
    }

    return(stRet_u8);
}


/**
 * \brief   Request to continue an ongoing chunk-wise read job with the next chunk
 *
 * \param   deviceName_en  Device instance, for which job is requested
 * \param   dataBuf_pu8    Buffer location, where chunk data is copied into
 * \param   nrBytMax_u32   Maximum number of bytes, which can be copied into buffer
 *
 * \return  Request acceptance
 * \retval  E_OK     The request has been accepted, and the job processing is continued
 * \retval  E_NO_OK  The request has been erroneous and therefore been rejected
*/
Std_ReturnType Fee_Rb_Idx_ChunkReadNext(Fee_Rb_DeviceName_ten deviceName_en, uint8 * dataBuf_pu8, uint32 nrBytMax_u32)
{
    /* Return variable */
    Std_ReturnType    stRet_u8;

    /* Local variables */
    Fee_Prv_ConfigDeviceTable_tst const *    xCfgDevTbl_pcst;
    Fee_Prv_JobDesc_tst                      xJob_st;

    /* Check request in general (in subsequent chunks, we must be able to read at least one byte) */
    stRet_u8 = Fee_Prv_ChunkDetChkGnrl(deviceName_en, FEE_SID_RB_CHUNK_READ_NEXT, dataBuf_pu8, nrBytMax_u32, 1uL);
    if(E_OK == stRet_u8)
    {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE  ==  RBA_FEEFS1_PRV_CFG_ENABLED))
        /* Reading subsequent chunks is not supported for FeeFs1 */
        if(Fee_Rb_DeviceName == deviceName_en)
        {
            /* Deny request; chunk-wise read isn't ongoing */
            Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_READ_NEXT, FEE_E_INVALID_SEQUENCE);
            stRet_u8 = E_NOT_OK;
        }
        else
# endif
        {
            /* Copy active job */
            xCfgDevTbl_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
            xJob_st         = *Fee_Prv_JobGetActv(xCfgDevTbl_pcst, FEE_PRV_REQUESTER_CHUNK_E);

            /* Not waiting to read next chunk? */
            if( (FEE_RB_JOBTYPE_WAIT_NEXT_CHUNK_E != xJob_st.type_en) || (NULL_PTR == xJob_st.bfr_pu8) )
            {
                /* Deny request in case we are not waiting to read next chunk */
                Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_READ_NEXT, FEE_E_INVALID_SEQUENCE);
                stRet_u8 = E_NOT_OK;
            }
            else
            {
                /* Keep stRet_u8 = E_OK */
            }
        }
    }
    else
    {
        /* Deny request and keep stRet_u8 = E_NOT_OK, DET entry done by Fee_Prv_ChunkDetChkGnrl */
    }

    /* Request valid? */
    if(E_OK == stRet_u8)
    {
        /* Setup descriptor for chunk-wise job */
        xJob_st.type_en    = FEE_RB_JOBTYPE_READ_E;
        xJob_st.bfr_pu8    = dataBuf_pu8;
        xJob_st.length_u16 = (uint16)rba_MemLib_Min(
                                            xJob_st.nrBytTot_u16 - xJob_st.cntrBytDone_u16,
                                            nrBytMax_u32);
        xJob_st.offset_u16 = xJob_st.cntrBytDone_u16;

        /* Continue chunk-wise job */
        stRet_u8 = Fee_Prv_JobPut(deviceName_en, FEE_SID_RB_CHUNK_READ_NEXT, &xJob_st);
    }
    else
    {
        /* Keep stRet_u8 = E_NOT_OK */
    }

    return(stRet_u8);
}


/**
 * \brief   Request to continue an ongoing chunk-wise write job with the next chunk
 *
 * \param   deviceName_en  Device instance, for which job is requested
 * \param   dataBuf_pcu8   Buffer location, from where chunk data is copied
 * \param   nrBytMax_u32   Maximum number of bytes, which can be copied from buffer
 *
 * \return  Request acceptance
 * \retval  E_OK     The request has been accepted, and the job processing is continued
 * \retval  E_NO_OK  The request has been erroneous and therefore been rejected
*/
Std_ReturnType Fee_Rb_Idx_ChunkWriteNext(
        Fee_Rb_DeviceName_ten deviceName_en,
        uint8 const * dataBuf_pcu8,
        uint32 nrBytMax_u32)
{
    /* Return variable */
    Std_ReturnType    stRet_u8;

    /* Local variable */
    uint32    nrPageSize_u32;

    /* Avoid calling Fee_Prv_FsIfGetLogicalPageSize for an invalid device */
    if(Fee_Rb_Device_Max > deviceName_en)
    {
        nrPageSize_u32 = Fee_Prv_FsIfGetLogicalPageSize(deviceName_en);
    }
    else
    {
        nrPageSize_u32 = nrBytMax_u32;
    }

    /* Check request in general (in subsequent chunks, we must be able to write at least one logical page) */
    stRet_u8 = Fee_Prv_ChunkDetChkGnrl(
                deviceName_en,
                FEE_SID_RB_CHUNK_WRITE_NEXT,
                dataBuf_pcu8,
                nrBytMax_u32,
                nrPageSize_u32 );
    if(E_OK == stRet_u8)
    {
        /* Writing subsequent chunks is not yet supported */
        Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_WRITE_NEXT, FEE_E_INVALID_SEQUENCE);
        stRet_u8 = E_NOT_OK;
    }
    else
    {
        /* Keep stRet_u8 = E_NOT_OK */
    }

    return(stRet_u8);
}


/**
 * \brief   Request to return the result of the current/last chunk(-wise job)
 *
 * \param   deviceName_en  Device instance, for which the result is requested
 *
 * \return  Result of the current/last chunk(-wise job)
 * \retval  FEE_RB_CHUNK_ALL_OK_E      Processing of all chunks has succeeded, complete chunk-wise job is done
 * \retval  FEE_RB_CHUNK_PART_OK_E     Processing of last chunk has succeeded, ready for next chunk
 * \retval  FEE_RB_CHUNK_FAILED_E      Processing of chunk-wise job has failed
 * \retval  FEE_RB_CHUNK_PENDING_E     Processing of last/current chunk hasn't finished yet
 * \retval  FEE_RB_CHUNK_TERMINATED_E  Processing of chunk-wise job has been terminated by the user
*/
Fee_Rb_ChunkResult_ten Fee_Rb_Idx_ChunkGetResult(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    Fee_Rb_ChunkResult_ten    stResult_en;

    /* Device name okay? */
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_CHUNK_GET_RESULT))
    {
        /* Fee initialized and not in stop mode? */
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_CHUNK_GET_RESULT))
        {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE  ==  RBA_FEEFS1_PRV_CFG_ENABLED))
            /* In FeeFs1, we have to poll and determine the result ourselves. Reason is that it is a
             * deprecated file systems, where only bug fixes but no more new features are allowed. */
            if(Fee_Rb_DeviceName == deviceName_en)
            {
                /* Chunk under processing? */
                if(NULL_PTR != Fee_Prv_ChunkGetJobResult_pfct)
                {
                    /* Chunk done? */
                    MemIf_JobResultType    stRes_en = Fee_Prv_ChunkGetJobResult_pfct();
                    if(MEMIF_JOB_PENDING != stRes_en)
                    {
                        Fee_Prv_JobChunkInfo_tst    stChunk_st;

                        /* In FeeFs1, we also have to call the done-callback ourselves, reason is same as above. */
                        Fee_Prv_ChunkDoneCbk(deviceName_en, &Fee_Prv_ChunkJob_st, stRes_en, &stChunk_st);

                        SchM_Enter_Fee_Order();

                        /* Update status of chunk(-wise) job */
                        Fee_Prv_ChunkInfo_st = stChunk_st;

                        /* Memorize that chunk is done */
                        Fee_Prv_ChunkGetJobResult_pfct = NULL_PTR;

                        SchM_Exit_Fee_Order();
                    }
                    else
                    {
                        /* Do nothing (return Fee_Prv_ChunkInfo_st.result_en = FEE_RB_CHUNK_PENDING_E) */
                    }
                }
                else
                {
                    /* Do nothing (return Fee_Prv_ChunkInfo_st.result_en of last chunk-wise job) */
                }

                stResult_en = Fee_Prv_ChunkInfo_st.result_en;
            }
            else
# endif
            {
                /* In all other file systems, we obtain the result from the job unit */
                stResult_en = Fee_Prv_JobGetChunkResult(deviceName_en);
            }
        }
        else
        {
            /* Leave with error, DET entry done by Fee_Prv_OrderDetCheckModuleInitAndStopMode */
            stResult_en = FEE_RB_CHUNK_FAILED_E;
        }
    }
    else
    {
        /* Leave with error, DET entry done by Fee_Prv_OrderDetCheckDeviceName */
        stResult_en = FEE_RB_CHUNK_FAILED_E;
    }

    return(stResult_en);
}


/**
 * \brief   Request to return the number of bytes that have been processed in the current/last chunk
 *
 * \param   deviceName_en  Device instance, for which number of bytes is requested
 *
 * \return  Number of bytes that have been processed in the current/last chunk
 *
 * \attention  It is mandatory to query the number of processed bytes in the last chunk before continuing with the next
 *             chunk! Background: Both the chunk-wise read- as well as the chunk-wise write will not necessarily fill/
 *             process the given buffer completely. For a chunk-wise write, the user is responsible to (partially)
 *             provide the data again in case it couldn't be processed in the last chunk!
*/
uint32 Fee_Rb_Idx_ChunkGetNrBytProc(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    uint32    nrBytProc_u32 = 0uL;

    /* Device name okay? */
    if(E_OK == Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_CHUNK_GET_NR_BYT_PROC))
    {
        /* Fee initialized and not in stop mode? */
        if(E_OK == Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_CHUNK_GET_NR_BYT_PROC))
        {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE  ==  RBA_FEEFS1_PRV_CFG_ENABLED))
            /* In FeeFs1, we have to obtain the number of processed bytes from this unit's environment variables */
            if(Fee_Rb_DeviceName == deviceName_en)
            {
                nrBytProc_u32 = Fee_Prv_ChunkInfo_st.nrBytProc_u32;
            }
            else
# endif
            {
                /* In all other file systems, we obtain the number of processed bytes from the job unit */
                nrBytProc_u32 = Fee_Prv_JobGetChunkNrBytProc(deviceName_en);
            }
        }
        else
        {
            /*  Keep nrBytProc_u32 = 0uL, DET entry done by Fee_Prv_OrderDetCheckModuleInitAndStopMode */
        }
    }
    else
    {
        /*  Keep nrBytProc_u32 = 0uL, DET entry done by Fee_Prv_OrderDetCheckDeviceName */
    }

    return(nrBytProc_u32);
}


/**
 * \brief   Request to asynchronously terminate an ongoing chunk-wise read or write job that is waiting for the next
 *          chunk (result FEE_RB_CHUNK_PART_OK_E), e.g. if the user has run into problems while processing a read chunk
 *
 * \param   deviceName_en  Device instance, for which job termination is requested
 *
 * \return  Request acceptance
 * \retval  E_OK    The request has been accepted, and the job termination is started
 * \retval  E_NO_OK The request has been erroneous and therefore been rejected
*/
Std_ReturnType Fee_Rb_Idx_ChunkTerminate(Fee_Rb_DeviceName_ten deviceName_en)
{
    /* Return variable */
    Std_ReturnType    stRet_u8;

    /* Local variables */
    Fee_Prv_ConfigDeviceTable_tst const *    xCfgDevTbl_pcst;
    Fee_Prv_JobDesc_tst const *              xJob_pcst;
    Fee_Prv_JobDesc_tst                      xJob_st;

    /* Device name OK? */
    stRet_u8 = Fee_Prv_OrderDetCheckDeviceName(deviceName_en, FEE_SID_RB_CHUNK_TERMINATE);
    if(E_OK == stRet_u8)
    {
        /* Fee initialized and not in stop mode? */
        stRet_u8 = Fee_Prv_OrderDetCheckModuleInitAndStopMode(deviceName_en, FEE_SID_RB_CHUNK_TERMINATE);
        if(E_OK == stRet_u8)
        {
# if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE  ==  RBA_FEEFS1_PRV_CFG_ENABLED))
            /* Termination of chunk-wise job is not supported for FeeFs1 */
            if(Fee_Rb_DeviceName == deviceName_en)
            {
                Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_TERMINATE, FEE_E_INVALID_SEQUENCE);
                stRet_u8 = E_NOT_OK;
            }
            else
# endif
            {
                /* Get active job */
                xCfgDevTbl_pcst = Fee_Prv_ConfigGetAdrOfConfigTableFromDeviceName(deviceName_en);
                xJob_pcst       = Fee_Prv_JobGetActv(xCfgDevTbl_pcst, FEE_PRV_REQUESTER_CHUNK_E);

                /* Waiting to read/write next chunk? */
                if(FEE_RB_JOBTYPE_WAIT_NEXT_CHUNK_E != xJob_pcst->type_en)
                {
                    /* Deny request in case we are not waiting to read/write next chunk */
                    Fee_Prv_LibDetReport(deviceName_en, FEE_SID_RB_CHUNK_TERMINATE, FEE_E_INVALID_SEQUENCE);
                    stRet_u8 = E_NOT_OK;
                }
                else
                {
                    /* Keep stRet_u8 = E_OK */
                }
            }
        }
        else
        {
            /* Deny request and keep stRet_u8 = E_NOT_OK, DET entry done by Fee_Prv_OrderDetCheckDeviceName */
        }
    }
    else
    {
        /* Deny request and keep stRet_u8 = E_NOT_OK, DET entry done by Fee_Prv_OrderDetCheckModuleInitAndStopMode */
    }

    /* Request valid? */
    if(E_OK == stRet_u8)
    {
        /* Setup descriptor for chunk-wise job */
        xJob_st.type_en         = FEE_RB_JOBTYPE_TERMINATE_CHUNK_E;
        xJob_st.jobMode_en      = FEE_RB_ALLJOBS_ALLSTEPS_E;
        xJob_st.bfr_pu8         = NULL_PTR;
        xJob_st.bfr_pcu8        = NULL_PTR;
        xJob_st.idPers_u16      = 0u;
        xJob_st.blockNumber_u16 = FEE_PRV_MAX_UINT16;
        xJob_st.length_u16      = 0u;
        xJob_st.offset_u16      = 0u;
        xJob_st.nrBytTot_u16    = 0u;
        xJob_st.cntrBytDone_u16 = 0u;
        xJob_st.isChunkJob_b    = TRUE;

        /* Terminate chunk-wise job */
        stRet_u8 = Fee_Prv_JobPut(deviceName_en, FEE_SID_RB_CHUNK_TERMINATE, &xJob_st);
    }
    else
    {
        /* Keep stRet_u8 = E_NOT_OK */
    }

    return(stRet_u8);
}


#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/* #if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS)) */
#endif

/* #if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED)) */
#endif
