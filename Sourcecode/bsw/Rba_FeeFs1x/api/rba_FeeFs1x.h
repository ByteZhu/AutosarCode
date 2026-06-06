
#ifndef RBA_FEEFS1X_H
#define RBA_FEEFS1X_H

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

# if(defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED))

/*
 ****************************************************************************************************
 * Includes
 ****************************************************************************************************
 */
#include "Fee_Prv_Job.h"
#include "MemIf_Types.h"
#include "Fee_Prv_Config.h"
#include "rba_FeeFs1x_Prv_Cfg.h"

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

extern Std_ReturnType       rba_FeeFs1x_Init(Fee_Rb_DeviceName_ten deviceName_en);

extern void                 rba_FeeFs1x_Read         (Fee_Prv_JobDesc_tst const * orderStruct_pcst);
extern void                 rba_FeeFs1x_Write        (Fee_Prv_JobDesc_tst const * orderStruct_pcst);
extern void                 rba_FeeFs1x_Invalidate   (Fee_Prv_JobDesc_tst const * orderStruct_pcst);
extern void                 rba_FeeFs1x_Rb_Maintain  (Fee_Prv_JobDesc_tst const * orderStruct_pcst);
extern MemIf_JobResultType  rba_FeeFs1x_BlockJobDo(void);

extern MemIf_JobResultType  rba_FeeFs1x_Background(void);

extern void                 rba_FeeFs1x_TriggerReorg(void);
extern MemIf_JobResultType  rba_FeeFs1x_TriggerReorgDo(void);

extern uint32               rba_FeeFs1x_GetSectorChgCntr(void);

extern uint32               rba_FeeFs1x_GetFreeSpace(void);

extern boolean              rba_FeeFs1x_IsSoftReorgOngoing(void);
extern boolean              rba_FeeFs1x_IsHardReorgOngoing(void);
extern boolean              rba_FeeFs1x_IsSectorEraseOngoing(void);

extern MemIf_Rb_DetailedBlkInfo_ten rba_FeeFs1x_GetDetailedBlkInfo(uint16 blockNumber_u16);

/*
 **********************************************************************************************************************
 * Public inline functions
 **********************************************************************************************************************
*/
LOCAL_INLINE uint16                                 rba_FeeFs1x_getDoubleStorageBitmask(void);
LOCAL_INLINE uint16                                 rba_FeeFs1x_getSurvivalBitmask(void);
LOCAL_INLINE uint16                                 rba_FeeFs1x_getNoFallbackBitmask(void);
LOCAL_INLINE uint16                                 rba_FeeFs1x_getNrOfBlocks(void);
LOCAL_INLINE uint8                                  rba_FeeFs1x_getNrOfSectors(void);
LOCAL_INLINE uint8                                  rba_FeeFs1x_getEraseValue(void);
LOCAL_INLINE boolean                                rba_FeeFs1x_isDirectMemoryReadAllowed(void);
LOCAL_INLINE boolean                                rba_FeeFs1x_isUnknownBlockWriteAllowed(void);
LOCAL_INLINE uint32                                 rba_FeeFs1x_getEmulationStartAdr(void);
LOCAL_INLINE uint32                                 rba_FeeFs1x_getEmulationEndAdr(void);
LOCAL_INLINE uint8                                  rba_FeeFs1x_getLogicalPageSize(void);
LOCAL_INLINE Fee_Rb_BlockPropertiesType_tst const * rba_FeeFs1x_getBlockPropertiesTable(void);
LOCAL_INLINE boolean                                rba_FeeFs1x_isJobModeSupported(Fee_Rb_JobType_ten jobType_en, Fee_Rb_JobMode_ten jobMode_en);
LOCAL_INLINE Fee_Rb_JobMode_ten                     rba_FeeFs1x_getJobModeForFastDriverMode(Fee_Rb_JobType_ten jobType_en);

/**
 *********************************************************************
 * rba_FeeFs1x_getDoubleStorageBitmask
 *
 * \return  The function returns the double storage bitmask for the block properties table.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint16 rba_FeeFs1x_getDoubleStorageBitmask(void)
{
    return (RBA_FEEFS1X_PRV_CFG_DOUBLESTORAGE_BITS);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getSurvivalBitmask
 *
 * \return  The function returns the survival bitmask for the block properties table.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint16 rba_FeeFs1x_getSurvivalBitmask(void)
{
    return (RBA_FEEFS1X_PRV_CFG_SURVIVAL_BITS);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getNoFallbackBitmask
 *
 * \return  The function returns the nofallback block bitmask for the block properties table.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint16 rba_FeeFs1x_getNoFallbackBitmask(void)
{
    return (RBA_FEEFS1X_PRV_CFG_NOFALLBACK_BITS);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getNrOfBlocks
 *
 * \return  The function returns the number of configured known blocks in given instance.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint16 rba_FeeFs1x_getNrOfBlocks(void)
{
    return (RBA_FEEFS1X_PRV_CFG_NR_OF_BLOCKS);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getNrOfSectors
 *
 * \return  The function returns the number of available sectors.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint8 rba_FeeFs1x_getNrOfSectors(void)
{
    return (RBA_FEEFS1X_PRV_CFG_NR_FLASH_BANKS_AVAILABLE);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getEraseValue
 *
 * \return  The function returns the erase value of the data flash.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint8 rba_FeeFs1x_getEraseValue(void)
{
    return (RBA_FEEFS1X_PRV_CFG_ERASE_PATTERN_8BIT);
}

/**
 *********************************************************************
 * rba_FeeFs1x_isDirectMemoryReadAllowed
 *
 * \return  The function returns if direct memory read access is allowed (to be used for fast initialisation).
 *          TRUE    : Direct memory access allowed
 *          FALSE   : Direct memory access not allowed
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE boolean rba_FeeFs1x_isDirectMemoryReadAllowed(void)
{
#  if defined(RBA_FEEFS1X_PRV_CFG_MED_ALLOW_DIRECT)
    return (RBA_FEEFS1X_PRV_CFG_MED_ALLOW_DIRECT);
#  else
    return (FALSE);
#  endif
}

/**
 *********************************************************************
 * rba_FeeFs1x_isUnknownBlockWriteAllowed
 * The function returns return if writing of unknown block feature is activated.
 *
 * \return
 * \retval  FALSE   writing of unknown block is deactivated
 * \retval  TRUE    writing of unknown block is activated
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE boolean rba_FeeFs1x_isUnknownBlockWriteAllowed(void)
{
#if defined(RBA_FEEFS1X_PRV_CFG_UNKNOWN_BLOCK_WRITE)
    return (RBA_FEEFS1X_PRV_CFG_UNKNOWN_BLOCK_WRITE);
#else
    return (FALSE);
#endif
}

/**
 *********************************************************************
 * rba_FeeFs1x_isUnknownSurvivalBlockWriteAllowed
 * The function returns return if writing of unknown survival block feature is activated.
 *
 * \return
 * \retval  FALSE   writing of unknown survival block is deactivated
 * \retval  TRUE    writing of unknown survival block is activated
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE boolean rba_FeeFs1x_isUnknownSurvivalBlockWriteAllowed(void)
{
#if defined(RBA_FEEFS1X_PRV_CFG_UNKNOWN_SURVIVAL_BLOCK_WRITE)
    return (RBA_FEEFS1X_PRV_CFG_UNKNOWN_SURVIVAL_BLOCK_WRITE);
#else
    return (FALSE);
#endif
}

/**
 *********************************************************************
 * rba_FeeFs1x_getEmulationStartAdr
 *
 * \return  The function returns the start address of the emulation area.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint32 rba_FeeFs1x_getEmulationStartAdr(void)
{
    return (RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getEmulationEndAdr
 * Emulation end address = Sector 0 start address + ((Logical Sector size) * Nr of Sectors)
 * \return  The function returns the end address of the emulation area.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint32 rba_FeeFs1x_getEmulationEndAdr(void)
{
    return ((RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0) +
            (((RBA_FEEFS1X_PRV_CFG_PHYS_SEC_END0 - RBA_FEEFS1X_PRV_CFG_PHYS_SEC_START0) + 1u) * RBA_FEEFS1X_PRV_CFG_NR_FLASH_BANKS_AVAILABLE) -
            1u);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getLogicalPageSize
 *
 * \return  The function returns the logical page size.
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE uint8 rba_FeeFs1x_getLogicalPageSize(void)
{
    return (RBA_FEEFS1X_PRV_CFG_LOGL_PAGE_SIZE);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getBlockPropertiesTable
 *
 * \return  The function returns the pointer to the block properties table
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE Fee_Rb_BlockPropertiesType_tst const * rba_FeeFs1x_getBlockPropertiesTable(void)
{
    return (rba_FeeFs1x_Prv_Cfg_BlockPropertiesTable_ast);
}

/**
 *********************************************************************
 * rba_FeeFs1x_isJobModeSupported
 * The function returns if passed job mode for the job type is supported or not.
 *
 * \param   jobType_en       Job type for which mode has to be set
 * \param   jobMode_en       Mode that is requested to be set for the passed job type
 *
 * \return
 *          TRUE    : passed mode allowed
 *          FALSE   : passed mode is not allowed
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE boolean rba_FeeFs1x_isJobModeSupported(Fee_Rb_JobType_ten jobType_en, Fee_Rb_JobMode_ten jobMode_en)
{
    boolean retVal_b = FALSE;

    // default mode is allowed for all valid job types
    if((FEE_RB_ALLJOBS_ALLSTEPS_E == jobMode_en) && (jobType_en < FEE_RB_JOBTYPE_MAX_E))
    {
        retVal_b = TRUE;
    }

    // check for allowed mode setting for write jobs
    if((FEE_RB_JOBTYPE_WRITE_E == jobType_en) &&
      ((FEE_RB_WRITEJOB_WRITE_VERIFY_E == jobMode_en) || (FEE_RB_WRITEJOB_WRITE_ONLY_E == jobMode_en)))
    {
        retVal_b = TRUE;
    }

    // check for allowed mode setting for invalidate jobs
    if((FEE_RB_JOBTYPE_INVALIDATE_E == jobType_en) &&
      ((FEE_RB_INVALIDATEJOB_WRITE_VERIFY_E == jobMode_en) || (FEE_RB_INVALIDATEJOB_WRITE_ONLY_E == jobMode_en)))
    {
        retVal_b = TRUE;
    }

    return(retVal_b);
}

/**
 *********************************************************************
 * rba_FeeFs1x_getJobModeForFastDriverMode
 * The function returns return the job mode to be used when the driver is working in MEMIF_FAST_MODE mode.
 *
 * \param   jobType_en       Job type for which mode has to be returned
 *
 * \return  mode to be used
 * \seealso
 * \usedresources
 *********************************************************************
 */
LOCAL_INLINE Fee_Rb_JobMode_ten rba_FeeFs1x_getJobModeForFastDriverMode(Fee_Rb_JobType_ten jobType_en)
{
    /* Set the variable to default value to be returned for all jobs which does not have MEMIF_FAST_MODE mode setting */
    Fee_Rb_JobMode_ten retVal_en = FEE_RB_ALLJOBS_ALLSTEPS_E;

    /* Currently, only the job mode for the write and invalidate jobs are different for fast mode */
    if(FEE_RB_JOBTYPE_WRITE_E == jobType_en)
    {
        retVal_en = FEE_RB_WRITEJOB_WRITE_VERIFY_E;
    }

    if(FEE_RB_JOBTYPE_INVALIDATE_E == jobType_en)
    {
        retVal_en = FEE_RB_INVALIDATEJOB_WRITE_VERIFY_E;
    }

    return (retVal_en);
}

# endif /* (defined(RBA_FEEFS1X_PRV_CFG_ENABLED) && (TRUE == RBA_FEEFS1X_PRV_CFG_ENABLED)) */

#endif

