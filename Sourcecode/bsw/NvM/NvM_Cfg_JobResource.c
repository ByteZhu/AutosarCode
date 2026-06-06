
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"

#include "NvM_Prv_JobResource.h"
#include "NvM_Prv_Job_Types.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_MemIf.h"

/*
 **********************************************************************************************************************
 * Local declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

static boolean NvM_Prv_JobResource_IsRequiredDevice_0(NvM_BlockIdType idBlock_uo);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

static NvM_Prv_JobResource_IsRequired_tpfct const NvM_Prv_JobResource_IsRequired_acpfct[NvM_Prv_idJobResource_NrJobResources_e] =
{
    NvM_Prv_JobResource_IsRequiredDevice_0,
};

static NvM_Prv_Job_State_tpfct const NvM_Prv_JobResourceStateMachines_acpfct[NvM_Prv_idJobResource_NrJobResources_e] =
{
    NvM_Prv_MemIf_DoStateMachine,
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

boolean NvM_Prv_JobResource_IsRequired(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                       NvM_BlockIdType idBlock_uo)
{
    return (NvM_Prv_JobResource_IsRequired_acpfct[idJobResource_uo](idBlock_uo));
}

void NvM_Prv_JobResource_ExecuteStateMachine(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                             NvM_Prv_stJob_ten* stJob_pen,
                                             NvM_Prv_JobResult_tst* JobResult_pst,
                                             NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_Prv_JobResourceStateMachines_acpfct[idJobResource_uo](stJob_pen, JobResult_pst, JobData_pcst);
}

static boolean NvM_Prv_JobResource_IsRequiredDevice_0(NvM_BlockIdType idBlock_uo)
{
    return (0u == NvM_Prv_BlkDesc_GetIdDevice(idBlock_uo));
}


#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"


