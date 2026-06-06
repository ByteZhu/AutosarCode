#ifndef NVM_PRV_BLOCKDESCRIPTOR_INL_H
#define NVM_PRV_BLOCKDESCRIPTOR_INL_H

#include "NvM_Types.h"
#include "rba_MemLib.h"

#if (defined(TESTCD_NVM_ENABLED) && (TESTCD_NVM_ENABLED == STD_ON))
# include "TestCd_NvM.h"
#endif

/*
**********************************************************************************************************************
* Inline functions declarations
**********************************************************************************************************************
*/
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsBlockHeaderEnabled(void);
LOCAL_INLINE void NvM_Prv_BlkDesc_AppendBlockHeader(NvM_BlockIdType idBlock_uo,
                                                    uint8* Buffer_pu8);
LOCAL_INLINE NvM_Prv_idJobResource_tuo NvM_Prv_BlkDesc_GetIdJobResource(NvM_BlockIdType idBlock_uo,
                                                                        NvM_Prv_JobResource_Cluster_ten Cluster_en);
LOCAL_INLINE uint8 NvM_Prv_BlkDesc_GetIdDevice(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsBlockSelected(NvM_BlockIdType idBlock_uo,
                                                     NvM_Prv_BlockConfiguration_ten SelectionMask_en);
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsDefaultDataAvailable(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsLengthValid(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE NvM_Prv_idQueue_tuo NvM_Prv_BlkDesc_GetIdQueueForModifyingServices(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE boolean NvM_Prv_BlkDesc_HasBlockImmediateJobPriority(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetSize(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetBlockSizeStored(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE NvM_BlockManagementType NvM_Prv_BlkDesc_GetType(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint8 NvM_Prv_BlkDesc_GetNrNonVolatileBlocks(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetNrDataIndexes(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE void * NvM_Prv_BlkDesc_GetPRamBlockAddress(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE void const* NvM_Prv_BlkDesc_GetRomBlockAddress(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetIdMemIf(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint8 NvM_Prv_BlkDesc_GetIdxDevice(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE NvM_Prv_Crc_Type_ten NvM_Prv_BlkDesc_GetCrcType(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetIdxRamBlockCrc(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetIdPersistent(uint16 idxPersistentId_u16);
LOCAL_INLINE NvM_BlockIdType NvM_Prv_BlkDesc_GetIdBlock(uint16 idxPersistentId_u16);
LOCAL_INLINE NvM_Prv_ExplicitSync_Copy_tpfct NvM_Prv_BlkDesc_GetCopyFctForRead(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE NvM_Prv_ExplicitSync_Copy_tpfct NvM_Prv_BlkDesc_GetCopyFctForWrite(NvM_BlockIdType idBlock_uo,
                                                                                uint8* InternalBuffer_pu8);
LOCAL_INLINE Std_ReturnType NvM_Prv_BlkDesc_InvokeInitBlockCallback(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeSingleBlockStartCallback(NvM_BlockIdType idBlock_uo,
                                                                 NvM_Prv_idService_tuo idService_uo);
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeSingleBlockCallback(NvM_BlockIdType idBlock_uo,
                                                            NvM_Prv_idService_tuo idService_uo,
                                                            NvM_RequestResultType Result_uo);
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeObserverCallback(NvM_BlockIdType idBlock_uo,
                                                         NvM_Prv_idService_tuo idService_uo,
                                                         NvM_RequestResultType Result_uo);
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeMultiStartCallback(NvM_Prv_idService_tuo idService_uo);
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeMultiCallback(NvM_Prv_idService_tuo idService_uo,
                                                      NvM_RequestResultType Result_uo);

#if (NVM_CRYPTO_USED == STD_ON)

LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetPersistantId(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetLengthJobCsm(NvM_BlockIdType idBlock_uo,
                                                    NvM_Prv_Crypto_idService_ten idServiceCrypto_en);
LOCAL_INLINE uint32 NvM_Prv_BlkDesc_GetIdJobCsm(NvM_BlockIdType idBlock_uo,
                                                NvM_Prv_Crypto_idService_ten idServiceCrypto_en);
LOCAL_INLINE uint8 const* NvM_Prv_BlkDesc_GetDataJobCsmAssociated(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetLengthJobCsmAssociated(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetLengthJobCsmTag(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetPositionJobCsmInitVector(NvM_BlockIdType idBlock_uo);

#endif

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */

typedef union
{
    Std_ReturnType (*ptrReadRamBlockFromNvmConst_pfct)(void const* NvMBuffer);
    Std_ReturnType (*ptrReadRamBlockFromNvm_pfct)(void* NvMBuffer);
} NvM_Prv_ReadRamBlockFromNvm_tun;

/*
**********************************************************************************************************************
* Inline functions
**********************************************************************************************************************
*/
/**
 * This function returns information whether the block header is configured or not.
 *
 * The purpose of this function is to simplify unit-testing of the NvM.
 *
 * \return
 * - TRUE = block header is enabled
 * - FALSE = block header disabled
 */
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsBlockHeaderEnabled(void)
{
    return (NVM_RB_BLOCK_HEADER > 0u);
}

/**
 * This function appends the block header to the given buffer.
 *
 * The caller of this function has to make sure that given buffer points exactly where the block header
 * has to be appended.
 * If user has not configured the block header then this function appends nothing.
 *
 * \param idBlock_uo
 * ID of the block for which the block header will be appended
 * \param Buffer_pu8
 * Pointer to the buffer where block header will be appended
 */
/* MR12 RULE 8.13 VIOLATION: The statements within the function can be disabled via a compiler-switch but the parameter
   is still required to be changeable if the statements within the function are active. */
LOCAL_INLINE void NvM_Prv_BlkDesc_AppendBlockHeader(NvM_BlockIdType idBlock_uo,
                                                    uint8* Buffer_pu8)
{
#if (NVM_RB_BLOCK_HEADER > 0u)

    rba_MemLib_MemCopy(NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockHeader_au8,
                       Buffer_pu8,
                       NVM_RB_BLOCK_HEADER_LENGTH);

#else

    (void)idBlock_uo;
    (void)Buffer_pu8;

#endif  // NVM_RB_BLOCK_HEADER > 0u
}

/**
 * \brief
 * This NvM private function returns for given block ID the job resource ID to be used for given job resource cluster.
 *
 * \param idBlock_uo
 * ID of the block for which device ID is required.
 * \param Cluster_en
 * Job resource cluster for which the job resource ID is required
 *
 * \return
 * ID of the job resource to be used for given job resource cluster
 */
LOCAL_INLINE NvM_Prv_idJobResource_tuo NvM_Prv_BlkDesc_GetIdJobResource(NvM_BlockIdType idBlock_uo,
                                                                        NvM_Prv_JobResource_Cluster_ten Cluster_en)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].idJobResource_auo[Cluster_en];
}

/**
 * \brief
 * This NvM private function returns the ID of the memory device where given block is located.
 *
 * \param idBlock_uo
 * ID of the block for which device ID is required.
 *
 * \return
 * ID of the memory device where given block is located.
 */
LOCAL_INLINE uint8 NvM_Prv_BlkDesc_GetIdDevice(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].idxDevice_u8;
}

/**
 * \brief
 * This NvM private function provides information whether a block is configured for the given feature.
 *
 * \param idBlock_uo
 * ID of the block for which the configuration information will be provided.
 * \param SelectionMask_en
 * Bit mask for the configuration information to be provided.
 *
 * \return
 * - TRUE = block is configured for the given feature
 * - FALSE = block is not configured for the given feature
 */
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsBlockSelected(NvM_BlockIdType idBlock_uo,
                                                     NvM_Prv_BlockConfiguration_ten SelectionMask_en)
{
    return ((NvM_Prv_BlockDescriptors_acst[idBlock_uo].stFlags_uo & ((uint32)SelectionMask_en)) != 0u);
}

/**
 * \brief
 * This NvM private function provides the information whether default data is available for the given block.
 *
 * \param idBlock_uo
 * ID of the block to provide the availability of the default data.
 *
 * \return
 * - TRUE = default data is available
 * - FALSE = default data is not available
 */
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsDefaultDataAvailable(NvM_BlockIdType idBlock_uo)
{
    return (((NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].adrRomBlock_pcv) ||
             (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].InitBlockCallback_pfct)));
}

/**
 * \brief
 * This NvM private function checks for the given block whether the configured block length is valid.
 *
 * \param idBlock
 * ID of the block for which the block length will be checked.
 *
 * \return
 * - TRUE = block length is valid
 * - FALSE = block length is invalid
 */
LOCAL_INLINE boolean NvM_Prv_BlkDesc_IsLengthValid(NvM_BlockIdType idBlock_uo)
{
    return (0u != *NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytes_pu16);
}

/**
 * \brief
 * This NvM private function returns the ID of the internal user request queue to be used for services
 * which modify a block.
 *
 * \details
 * Modifying services are:
 * - write block
 * - erase block
 * - invalidate block
 *
 * \attention
 * The caller of this function has to ensure that passed block ID is valid.
 *
 * \param idBlock_uo
 * ID of the block for which the ID of the internal user request queue is required.
 *
 * \return
 * ID of the internal user request queue
 */
LOCAL_INLINE NvM_Prv_idQueue_tuo NvM_Prv_BlkDesc_GetIdQueueForModifyingServices(NvM_BlockIdType idBlock_uo)
{
    NvM_Prv_idQueue_tuo idQueue_uo = NvM_Prv_idQueue_Standard_e;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    if (NVM_PRV_JOB_PRIORITY_IMMEDIATE == NvM_Prv_BlockDescriptors_acst[idBlock_uo].JobPriority_u8)
    {
        // TRACE[SWS_NvM_00378] Only single block write requests for immediate blocks are queued in the immediate queue
        //                      All other single block requests are queued in the standard queue.
        idQueue_uo = NvM_Prv_idQueue_Immediate_e;
    }
#else
    (void)idBlock_uo;
#endif

    return idQueue_uo;
}

/**
 * \brief
 * This NvM private function checks whether the given block is configured with immediate priority.
 *
 * \param idBlock_uo
 * ID of the block for which the priority will be checked.
 *
 * \return
 * - TRUE = block is configured with immediate priority
 * - FALSE = block is configured with standard priority
 */
LOCAL_INLINE boolean NvM_Prv_BlkDesc_HasBlockImmediateJobPriority(NvM_BlockIdType idBlock_uo)
{
    boolean HasBlockImmediateJobPriority_b = FALSE;

#if (NVM_JOB_PRIORITIZATION == STD_ON)
    if ((NVM_PRV_JOB_PRIORITY_IMMEDIATE == NvM_Prv_BlockDescriptors_acst[idBlock_uo].JobPriority_u8))
    {
        HasBlockImmediateJobPriority_b = TRUE;
    }
#else
    (void)idBlock_uo;
#endif
    return HasBlockImmediateJobPriority_b;
}

/**
 * \brief
 * This NvM private function returns the configured block size for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured block size will be returned.
 *
 * \return
 * Configured block size
 */
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetSize(NvM_BlockIdType idBlock_uo)
{
    return *NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytes_pu16;
}

/**
 * \brief
 * This NvM private function returns the configured block size stored on the medium for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured block size stored on the medium will be returned.
 *
 * \return
 * Configured block size stored on the medium
 */
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetBlockSizeStored(NvM_BlockIdType idBlock_uo)
{
    uint16 BlockSizeStored_u16 = 0u;

#if (defined(NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON))
        BlockSizeStored_u16 = *NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytes_pu16;
#else
        BlockSizeStored_u16 = NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytesStored_u16;
#endif

    return BlockSizeStored_u16;
}

/**
 * \brief
 * This NvM private function returns the configured block management type for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured block management type will be returned.
 *
 * \return
 * Configured block management type
 */
LOCAL_INLINE NvM_BlockManagementType NvM_Prv_BlkDesc_GetType(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockManagementType_en;
}

/**
 * \brief
 * This NvM private function returns the configured number of non-volatile data sets for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured number of non-volatile data sets will be returned.
 *
 * \return
 * Configured number of non-volatile data sets
 */
LOCAL_INLINE uint8 NvM_Prv_BlkDesc_GetNrNonVolatileBlocks(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrNvBlocks_u8;
}

/**
 * \brief
 * This NvM private function returns the configured overall number of data sets for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured overall number of data sets will be returned.
 *
 * \return
 * Configured number of data sets
 */
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetNrDataIndexes(NvM_BlockIdType idBlock_uo)
{
    uint8 nrDataIndexes = (NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrNvBlocks_u8 +
                           NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrRomBlocks_u8);

    return nrDataIndexes;
}

/**
 * \brief
 * This NvM private function returns the pointer to the configured permanent RAM block for the given block.
 *
 * \details
 * If no permanent RAM block is configured for a block then this function returns a NULL pointer.
 *
 * \param idBlock_uo
 * ID of the block for which the pointer to the configured permanent RAM block will be returned.
 *
 * \return
 * Pointer to the configured permanent RAM block
 */
LOCAL_INLINE void * NvM_Prv_BlkDesc_GetPRamBlockAddress(NvM_BlockIdType idBlock_uo)
{
    return *NvM_Prv_BlockDescriptors_acst[idBlock_uo].adrRamBlock_ppv;
}

/**
 * \brief
 * This NvM private function returns the pointer to the configured ROM block for the given block.
 *
 * \details
 * If no ROM block is configured for a block then this function returns a NULL pointer.
 *
 * \param idBlock_uo
 * ID of the block for which the pointer to the configured ROM block will be returned.
 *
 * \return
 * Pointer to the configured ROM block
 */
LOCAL_INLINE void const* NvM_Prv_BlkDesc_GetRomBlockAddress(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].adrRomBlock_pcv;
}

/**
 * \brief
 * This NvM private function returns the configured block ID used by the mem interface for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the block ID used by the mem interface will be returned.
 *
 * \return
 * Configured block ID used by the mem interface
 */
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetIdMemIf(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].idBlockMemIf_u16;
}

/**
 * \brief
 * This NvM private function returns the configured device index where the given block is located (Fee / Ea).
 *
 * \param idBlock_uo
 * ID of the block for which the configured device index will be returned.
 *
 * \return
 * Configured device index where the given block is located
 */
LOCAL_INLINE uint8 NvM_Prv_BlkDesc_GetIdxDevice(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].idxDevice_u8;
}

/**
 * \brief
 * This NvM private function returns the configured CRC type for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured device index will be returned.
 *
 * \return
 * Configured CRC type
 */
LOCAL_INLINE NvM_Prv_Crc_Type_ten NvM_Prv_BlkDesc_GetCrcType(NvM_BlockIdType idBlock_uo)
{
    NvM_Prv_Crc_Type_ten TypeCrc_en = NvM_Prv_Crc_Type_NoCrc_e;
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
    TypeCrc_en = NvM_Prv_BlockDescriptors_acst[idBlock_uo].TypeCrc_en;
#else
    (void)idBlock_uo;
#endif
    return TypeCrc_en;
}

/**
 * \brief
 * This NvM private function returns the configured index of the RAM block CRC for the given block.
 *
 * If CRC is generally disabled by configuration then this function always returns 0.
 *
 * \attention
 * The user shall make sure that return value of this function is used only if RAM block CRC is configured.
 *
 * \param[in] idBlock_uo
 * ID of the block for which the configured index of the RAM block CRC will be returned.
 *
 * \return
 * Configured index of the RAM block CRC
 */
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetIdxRamBlockCrc(NvM_BlockIdType idBlock_uo)
{
    uint16 idxRamBlockCrc_u16 = 0u;
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
    idxRamBlockCrc_u16 = NvM_Prv_BlockDescriptors_acst[idBlock_uo].idxRamBlockCrc_u16;
#else
    (void)idBlock_uo;
#endif
    return idxRamBlockCrc_u16;
}

/**
 * \brief
 * This NvM private function returns the configured persistent ID of a block identified by index for persistent IDs.
 *
 * \param idxPersistentId_u16
 * Index of the required persistent ID.
 *
 * \return
 * Configured persistent ID of a block identified by index for persistent IDs
 */
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetIdPersistent(uint16 idxPersistentId_u16)
{
    uint16 PersistentId_u16 = 0u;
    if (idxPersistentId_u16 < NVM_PRV_NR_PERSISTENT_IDS)
    {
        PersistentId_u16 = NvM_Prv_PersId_BlockId_acst[idxPersistentId_u16].PersistentId_u16;
    }
    return PersistentId_u16;
}

/**
 * \brief
 * This NvM private function returns the configured NvM ID of a block identified by index for persistent IDs.
 *
 * \param idxPersistentId_u16
 * Index of the required persistent ID.
 *
 * \return
 * Configured NvM ID of a block identified by index for persistent IDs
 */
LOCAL_INLINE NvM_BlockIdType NvM_Prv_BlkDesc_GetIdBlock(uint16 idxPersistentId_u16)
{
    uint16 BlockId_u16 = 0u;
    if (idxPersistentId_u16 < NVM_PRV_NR_PERSISTENT_IDS)
    {
        BlockId_u16 = NvM_Prv_PersId_BlockId_acst[idxPersistentId_u16].BlockId_u16;
    }
    return BlockId_u16;
}

/**
 * \brief
 * This NvM private function returns the configured pointer to the block specific callback function
 * to copy data from the NvM mirror to the application's RAM block. Using union to allow support for
 * read callback function using void* and void const* parameter.
 *
 * \param idBlock_uo
 * ID of the block for which the configured copy function will be returned.
 *
 * \return
 * Configured pointer to the copy function
 */
LOCAL_INLINE NvM_Prv_ExplicitSync_Copy_tpfct NvM_Prv_BlkDesc_GetCopyFctForRead(NvM_BlockIdType idBlock_uo)
{
    NvM_Prv_ReadRamBlockFromNvm_tun readFct_un;

#if (NVM_RB_EXPLICIT_SYNC_READ_WITH_CONST == STD_ON)
    readFct_un.ptrReadRamBlockFromNvmConst_pfct =  NvM_Prv_BlockDescriptors_acst[idBlock_uo].ReadRamBlockFromNvm_pfct;
#else
    readFct_un.ptrReadRamBlockFromNvm_pfct =  NvM_Prv_BlockDescriptors_acst[idBlock_uo].ReadRamBlockFromNvm_pfct;
#endif

    return readFct_un.ptrReadRamBlockFromNvm_pfct;
}

/**
 * \brief
 * This NvM private function returns the configured pointer to the block specific callback function
 * to copy data from the application's RAM block to the NvM mirror.
 *
 * \attention
 * The user shall make sure that this function is used only if explicit synchronization is configured.
 *
 * \param idBlock_uo
 * ID of the block for which the configured copy function will be returned.
 * \param InternalBuffer_pu8
 * Pointer to the internal buffer, if NvMRbInitBufferBeforeSyncWrite is enabled, the internal buffer is set to 0.
 *
 * \return
 * Configured pointer to the copy function
 */
/* MR12 RULE 8.13 VIOLATION: The statements within the function can be disabled via a compiler-switch but the parameter
   is still required to be changeable if the statements within the function are active. */
LOCAL_INLINE NvM_Prv_ExplicitSync_Copy_tpfct NvM_Prv_BlkDesc_GetCopyFctForWrite(NvM_BlockIdType idBlock_uo,
                                                                                uint8* InternalBuffer_pu8)
{
#if (NVM_RB_INIT_BUFFER_BEFORE_SYNC_WRITE == STD_ON)
    // TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3305] Set internal buffer to 0 if NvMRbInitBufferBeforeSyncWrite is enabled
    rba_MemLib_MemSet(InternalBuffer_pu8, 0x00u, NvM_Prv_BlkDesc_GetSize(idBlock_uo));
#else
    (void)*InternalBuffer_pu8;
#endif

    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].WriteRamBlockToNvm_pfct;
}

/**
 * \brief
 * This NvM private function returns the configured block specific initializaton callback function.
 * \details
 * If no initializaton callback function is configured for the passed block then this function does nothing and
 * returns E_NOT_OK.
 *
 * \param idBlock_uo
 * ID of the block for which the configured initialization callback function will be invoked.
 *
 * \return
 * E_OK = no initialization callback function is configured or has returned E_OK
 * E_NOT_OK = initialization callback function is configured and has returned E_NOT_OK
 */
LOCAL_INLINE Std_ReturnType NvM_Prv_BlkDesc_InvokeInitBlockCallback(NvM_BlockIdType idBlock_uo)
{
    Std_ReturnType RetValue = E_OK;
    if (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].InitBlockCallback_pfct)
    {
        RetValue = NvM_Prv_BlockDescriptors_acst[idBlock_uo].InitBlockCallback_pfct();
    }
    return RetValue;
}

/**
 * \brief
 * This NvM private function invokes the configured block specific single request start callback function.
 * \details
 * If no single request start callback function is configured for the passed block then this function does nothing.
 *
 * \param idBlock_uo
 * ID of the block for which the configured single request start callback function will be invoked.
 * \param idService_uo
 * Id of the request for which the start callback function will be invoked.
 */
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeSingleBlockStartCallback(NvM_BlockIdType idBlock_uo,
                                                                 NvM_Prv_idService_tuo idService_uo)
{
    if (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockStartCallback_pfct)
    {
        // Start callback function returns allways E_OK so return value can be dropped safely
        (void)(NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockStartCallback_pfct)(idService_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured block specific single request termination callback function.
 * \details
 * If no single request termination callback function is configured for the passed block then this function does nothing.
 *
 * \param idBlock_uo
 * ID of the block for which the configured termination callback function will be invoked.
 * \param idService_uo
 * Id of the request for which the termination callback function will be invoked.
 * \param Result_uo
 * Result of the terminated request.
 */
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeSingleBlockCallback(NvM_BlockIdType idBlock_uo,
                                                            NvM_Prv_idService_tuo idService_uo,
                                                            NvM_RequestResultType Result_uo)
{
    if (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockCallback_pfct)
    {
        // Termination callback function returns allways E_OK so return value can be dropped safely
        (void)(NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockCallback_pfct)(idService_uo, Result_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured observer callback function.
 * \details
 * If no observer callback function is configured for the NvM then this function does nothing.
 *
 * \param idBlock_uo
 * ID of the block to be passed to the configured observer callback function.
 * \param idService_uo
 * Id of the request to be passed to the configured observer callback function.
 * \param Result_uo
 * Result of the request to be passed to the configured observer callback function.
 */
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeObserverCallback(NvM_BlockIdType idBlock_uo,
                                                         NvM_Prv_idService_tuo idService_uo,
                                                         NvM_RequestResultType Result_uo)
{
    if (NULL_PTR != NvM_Prv_Common_cst.ObserverCallback_pfct)
    {
        // Observer callback function returns allways E_OK so return value can be dropped safely
        (void)(NvM_Prv_Common_cst.ObserverCallback_pfct)(idBlock_uo, idService_uo, Result_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured multi-block request start callback function.
 * \details
 * If no multi-block request start callback function is configured then this function does nothing.
 *
 * \param idService_uo
 * Id of the request for which the start callback function will be invoked.
 */
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeMultiStartCallback(NvM_Prv_idService_tuo idService_uo)
{
    if (NULL_PTR != NvM_Prv_Common_cst.RbMultiBlockStartCallback_pfct)
    {
        NvM_Prv_Common_cst.RbMultiBlockStartCallback_pfct(idService_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured multi-block request termination callback function.
 * \details
 * If no multi-block request termination callback function is configured then this function does nothing.
 *
 * \param idService_uo
 * Id of the request to be passed to the configured multi-block request termination callback function.
 * \param Result_uo
 * Result of the request to be passed to the configured multi-block request termination callback function.
 */
LOCAL_INLINE void NvM_Prv_BlkDesc_InvokeMultiCallback(NvM_Prv_idService_tuo idService_uo,
                                                      NvM_RequestResultType Result_uo)
{
    if (NULL_PTR != NvM_Prv_Common_cst.MultiBlockCallback_pfct)
    {
        NvM_Prv_Common_cst.MultiBlockCallback_pfct(idService_uo, Result_uo);
    }
}

/**
 * This function appends the block version to the given buffer and returns its size
 *
 * The caller of this function has to make sure that given buffer points exactly
 * where the block version has to be appended.
 *
 * \param idBlock_uo
 * ID of the block for which the block version will be appended
 * \param Buffer_pu8
 * Pointer to the buffer where the block version will be appended
 *
 * \return
 * Size of the appended block version
 */
/* MR12 RULE 8.13 VIOLATION: The statements within the function can be disabled via a compiler-switch but the parameter
   is still required to be changeable if the statements within the function are active. */
LOCAL_INLINE uint16 NvM_Prv_BlkDesc_AppendBlockVersion(NvM_BlockIdType idBlock_uo,
                                                       uint8* Buffer_pu8)
{
    uint16 BlockVersionSize_u16 = 0u;
#if (STD_ON == NVM_RB_BLOCK_VERSION)
    if (NvM_Prv_BlkDesc_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_BLOCK_VERSION))
    {
        BlockVersionSize_u16 = sizeof(NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockVersion_u8);
# if (defined(TESTCD_NVM_ENABLED) && (TESTCD_NVM_ENABLED == STD_ON)) && !defined(TESTCD_NO_INLINE)
        if ( TestCd_NvM_st.Arguments.EnablePatchBlockVersion_b &&
            (TestCd_NvM_st.Arguments.PatchedVersionBlockId_uo == idBlock_uo) )
        {
            *Buffer_pu8 = TestCd_NvM_st.Arguments.PatchedBlockVersion_u8;
            TestCd_NvM_st.Arguments.EnablePatchBlockVersion_b = FALSE;
        }
        else
        {
            *Buffer_pu8 = NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockVersion_u8;
        }

# else
        *Buffer_pu8 = NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockVersion_u8;
# endif
    }
#else
    (void)idBlock_uo;
    (void)*Buffer_pu8;
#endif // NVM_RB_BLOCK_VERSION
    return BlockVersionSize_u16;
}

/**
 * This function extracts the block version from the given buffer and returns whether it is valid or not
 * by checking if the extracted block version matches the configured block version or not.
 *
 * The caller of this function has to make sure that given buffer contains the block version at the end
 * of the given buffer.
 * If user has not configured the block version for the given block then this function extracts nothing
 * and returns TRUE.
 *
 * \param idBlock_uo
 * ID of the block for which the blockversion will be extracted
 * \param Buffer_pu8
 * Pointer to the buffer with the block version
 * \param SizeInBytes_pu16
 * Size of the buffer with the block version in bytes
 *
 * \return
 * - TRUE = block version is valid (matches with the configured one) or the block does not have a block version.
 * - FALSE = block version is invalid (missmatches with the configured one)
 */
/* MR12 RULE 8.13 VIOLATION: The statements within the function can be disabled via a compiler-switch but the parameter
   is still required to be changeable if the statements within the function are active. */
LOCAL_INLINE boolean NvM_Prv_BlkDesc_ExtractCheckBlockVersion(NvM_BlockIdType idBlock_uo,
                                                              uint8 const* Buffer_pu8,
                                                              uint16* SizeInBytes_pu16)
{
    boolean isBlockVersionValid_b = TRUE;
#if (STD_ON == NVM_RB_BLOCK_VERSION)

    if (NvM_Prv_BlkDesc_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_BLOCK_VERSION))
    {
        uint16 SizeBlockVersion_u16 = sizeof(NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockVersion_u8);
        *SizeInBytes_pu16 -= SizeBlockVersion_u16;

        if (NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockVersion_u8 != Buffer_pu8[*SizeInBytes_pu16])
        {
            isBlockVersionValid_b = FALSE;
        }
    }

#else

    (void)idBlock_uo;
    (void)*Buffer_pu8;
    (void)*SizeInBytes_pu16;

#endif  // NVM_RB_BLOCK_VERSION

    return isBlockVersionValid_b;
}


#if (NVM_CRYPTO_USED == STD_ON)

LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetPersistantId(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].PersistentId_u16;
}

LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetLengthJobCsm(NvM_BlockIdType idBlock_uo,
                                                    NvM_Prv_Crypto_idService_ten idServiceCrypto_en)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].CryptoConfig_st.LengthJobCsm_auo[idServiceCrypto_en];
}

LOCAL_INLINE uint32 NvM_Prv_BlkDesc_GetIdJobCsm(NvM_BlockIdType idBlock_uo,
                                                NvM_Prv_Crypto_idService_ten idServiceCrypto_en)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].CryptoConfig_st.idJobCsm_auo[idServiceCrypto_en];
}

LOCAL_INLINE uint8 const* NvM_Prv_BlkDesc_GetDataJobCsmAssociated(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].CryptoConfig_st.dataJobCsmAssociated_pcu8;
}

LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetLengthJobCsmAssociated(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].CryptoConfig_st.LengthJobCsmAssociated_uo;
}

LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetLengthJobCsmTag(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].CryptoConfig_st.LengthJobCsmTag_uo;
}

LOCAL_INLINE uint16 NvM_Prv_BlkDesc_GetPositionJobCsmInitVector(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_BlockDescriptors_acst[idBlock_uo].CryptoConfig_st.PositionKeyInitVector;
}

#endif

/* NVM_PRV_BLOCKDESCRIPTOR_INL_H */
#endif
