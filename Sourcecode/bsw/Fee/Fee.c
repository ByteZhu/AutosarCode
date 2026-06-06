
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fee_Rb_Types.h"   
#include "Fee_Rb_Idx.h"
#include "Fee_Cfg.h"
#include "Fee.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
 */

/*MR12 RULE 8.13 VIOLATION: AR4.2 defines this function prototype with a non-constant pointer*/
void Fee_Init(Fee_ConfigType const * CfgPtr_pst)
{
    Fee_Rb_Idx_Init(Fee_Rb_DeviceName,CfgPtr_pst);
}

void Fee_MainFunction(void)
{
    Fee_Rb_Idx_MainFunction(Fee_Rb_DeviceName);
}

void Fee_Rb_MainFunctionAndDependency(void)
{
    Fee_Rb_Idx_MainFunctionAndDependency(Fee_Rb_DeviceName);
}

Std_ReturnType Fee_Read(uint16 nrBlks_u16, uint16 nrBlkOffs_u16, uint8 * DataBuf_pu8, uint16 nrLen_u16)
{
    return(Fee_Rb_Idx_Read(Fee_Rb_DeviceName, nrBlks_u16, nrBlkOffs_u16, DataBuf_pu8, nrLen_u16));
}

Std_ReturnType Fee_Write(uint16 nrBlks_u16, uint8 * DataBuf_pu8)
{
    return(Fee_Rb_Idx_Write(Fee_Rb_DeviceName, nrBlks_u16, DataBuf_pu8));
}

Std_ReturnType Fee_InvalidateBlock(uint16 nrBlks_u16)
{
    return(Fee_Rb_Idx_InvalidateBlock(Fee_Rb_DeviceName, nrBlks_u16));
}

MemIf_StatusType Fee_GetStatus(void)
{
    return(Fee_Rb_Idx_GetStatus(Fee_Rb_DeviceName));
}

MemIf_JobResultType Fee_GetJobResult(void)
{
    return(Fee_Rb_Idx_GetJobResult(Fee_Rb_DeviceName));
}

Std_ReturnType Fee_EraseImmediateBlock(uint16 nrBlks_u16)
{
    return(Fee_Rb_Idx_EraseImmediateBlock(Fee_Rb_DeviceName, nrBlks_u16));
}

void Fee_Cancel(void)
{
    Fee_Rb_Idx_Cancel(Fee_Rb_DeviceName);
}

/* ### FeeSetModeSupported disabled - Fee_SetMode, Fee_Rb_GetMode API not available ### */

/* ### FeeVersionInfoApi disabled - Fee_GetVersionInfo API not available ### */

void Fee_Rb_EndInit(void)
{
    Fee_Rb_Idx_EndInit(Fee_Rb_DeviceName);
}

MemIf_JobResultType Fee_Rb_GetAdapterJobResult(void)
{
    return(Fee_Rb_Idx_GetAdapterJobResult(Fee_Rb_DeviceName));
}

uint32 Fee_Rb_GetSectChngCnt(void)
{
    return(Fee_Rb_Idx_GetSectChngCnt(Fee_Rb_DeviceName));
}

void Fee_Rb_DisableBackgroundOperation(void)
{
    Fee_Rb_Idx_DisableBackgroundOperation(Fee_Rb_DeviceName);
}

void Fee_Rb_EnableBackgroundOperation(void)
{
    Fee_Rb_Idx_EnableBackgroundOperation(Fee_Rb_DeviceName);
}

boolean Fee_Rb_IsBlockDoubleStorageActiveByBlockNr(uint16 blkNr_u16)
{
    return(Fee_Rb_Idx_IsBlockDoubleStorageActiveByBlockNr(Fee_Rb_DeviceName, blkNr_u16));
}

Fee_Rb_WorkingStateType_ten Fee_Rb_GetWorkingState(void)
{
    return(Fee_Rb_Idx_GetWorkingState(Fee_Rb_DeviceName));
}

Std_ReturnType Fee_Rb_BlockMaintenance(uint16 nrBlks_u16)
{
    return(Fee_Rb_Idx_BlockMaintenance(Fee_Rb_DeviceName, nrBlks_u16));
}

/* ### FeeRbVarBlockLength and FeeRbFirstReadDataMigration disabled for all blocks - Fee_Rb_VarLenRead API not available ### */

/* ### FeeRbVarBlockLength disabled for all blocks - Fee_Rb_VarLenWrite API not available ### */

/* ### FeeRbFirstReadDataMigration disabled for all blocks - Fee_Rb_GetMigrationResult API not available ### */

/* ### FeeRbDetailedBlkInfoApi disabled - Fee_Rb_GetDetailedBlkInfo API not available ### */

/* ### FeeRbTriggerReorgApi disabled - Fee_Rb_TriggerReorg API not available ### */

/* ### FeeRbGetNrSectorErases disabled - APIs for writing persistent data are not available ### */

/* ### FeeRbGetNrSectorErases disabled - APIs for accessing number of performed erase cycles not available ### */

/* ### FeeRbEnterStopModeApi disabled - Fee_Rb_EnterStopMode API not available ### */

/* ### FeeRbGetFreeSpaceApi disabled - Fee_Rb_GetNrFreeBytes API not available ### */

/* ### FeeRbGetNrFreeBytesAndFatEntriesApi disabled - Fee_Rb_GetNrFreeBytesAndFatEntries API not available ### */

/* ### FeeRbSetAndGetJobModeApi disabled - Fee_Rb_SetJobMode() and Fee_Rb_GetJobMode() APIs are not available ### */

