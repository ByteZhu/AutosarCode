/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"

#include "NvM_Prv_JobResource.h"
#include "NvM_Prv_BlockData.h"

/*
 **********************************************************************************************************************
 * Declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

static boolean NvM_Prv_JobResource_Lock(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                        NvM_Prv_JobData_tst const* JobData_pcst);

static void NvM_Prv_JobResource_Release(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                        NvM_Prv_JobData_tst const* JobData_pcst);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

/// Definition of the array for all claimed job resources.
static NvM_BlockIdType NvM_Prv_JobResource_Claimed_auo[NvM_Prv_idJobResource_NrJobResources_e];

/// Definition of the array for all internal jobs processed on job resources in parallel.
static NvM_Prv_JobData_tst const* NvM_Prv_JobResources_apcst[NvM_Prv_idJobResource_NrJobResources_e];

#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

void NvM_Prv_JobResource_Init(void)
{
    NvM_Prv_idJobResource_tuo idJobResource_uo;
    for (idJobResource_uo = 0; idJobResource_uo < NvM_Prv_idJobResource_NrJobResources_e; ++idJobResource_uo)
    {
        NvM_Prv_JobResource_Claimed_auo[idJobResource_uo] = 0u;
        NvM_Prv_JobResources_apcst[idJobResource_uo] = NULL_PTR;
    }
}

void NvM_Prv_JobResource_DoStateMachine(NvM_Prv_JobResource_Cluster_ten Cluster_en,
                                        NvM_Prv_stJob_ten* stJob_pen,
                                        NvM_Prv_JobResult_tst* JobResult_pst,
                                        NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_Prv_idJobResource_tuo idJobResource_uo;

#if (NVM_CRYPTO_USED == STD_ON)
    if (NvM_Prv_idJob_GenerateRandomNr_e == JobData_pcst->idJob_en)
    {
        idJobResource_uo = NvM_Prv_idJobResource_Crypto_e;
    }
    else
#endif
    {
        idJobResource_uo = NvM_Prv_BlkDesc_GetIdJobResource(JobData_pcst->idBlock_uo, Cluster_en);
    }
    JobResult_pst->Result_en = NvM_Prv_JobResult_Pending_e;

    if (NvM_Prv_JobResource_Lock(idJobResource_uo, JobData_pcst))
    {
        NvM_Prv_JobResource_ExecuteStateMachine(idJobResource_uo, stJob_pen, JobResult_pst, JobData_pcst);

        if (NvM_Prv_JobResult_Pending_e != JobResult_pst->Result_en)
        {
            NvM_Prv_JobResource_Release(idJobResource_uo, JobData_pcst);
        }
    }
    // If current job cannot lock the required job resource then it will remain pending
}

void NvM_Prv_JobResource_Claim(NvM_Prv_idJobResource_tuo idJobResource_uo,
                               NvM_BlockIdType idBlock_uo)
{
    NvM_Prv_JobResource_Claimed_auo[idJobResource_uo] = idBlock_uo;
}

void NvM_Prv_JobResource_Unclaim(NvM_BlockIdType idBlock_uo)
{
    NvM_Prv_idJobResource_tuo idJobResource_uo;
    for (idJobResource_uo = 0u; idJobResource_uo < NvM_Prv_idJobResource_NrJobResources_e; ++idJobResource_uo)
    {
        if (idBlock_uo == NvM_Prv_JobResource_Claimed_auo[idJobResource_uo])
        {
            NvM_Prv_JobResource_Claimed_auo[idJobResource_uo] = 0u;
        }
    }
}

boolean NvM_Prv_JobResource_IsClaimed(NvM_Prv_idJobResource_tuo idJobResource_uo)
{
    return (NvM_Prv_JobResource_Claimed_auo[idJobResource_uo] > 0u);
}

static boolean NvM_Prv_JobResource_Lock(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                        NvM_Prv_JobData_tst const* JobData_pcst)
{
    boolean isLocked_b;
    if (NULL_PTR == NvM_Prv_JobResources_apcst[idJobResource_uo])
    {
        NvM_Prv_JobResources_apcst[idJobResource_uo] = JobData_pcst;
        if (JobData_pcst->idBlock_uo == NvM_Prv_JobResource_Claimed_auo[idJobResource_uo])
        {
            NvM_Prv_JobResource_Claimed_auo[idJobResource_uo] = 0u;
        }
        isLocked_b = TRUE;
    }
    else if (JobData_pcst == NvM_Prv_JobResources_apcst[idJobResource_uo])
    {
        isLocked_b = TRUE;
    }
    else
    {
        if (   NvM_Prv_JobResource_IsRequired(idJobResource_uo, JobData_pcst->idBlock_uo)
            && (0u == NvM_Prv_JobResource_Claimed_auo[idJobResource_uo]))
        {
            NvM_Prv_JobResource_Claimed_auo[idJobResource_uo] = JobData_pcst->idBlock_uo;
        }
        isLocked_b = FALSE;
    }
    return isLocked_b;
}

static void NvM_Prv_JobResource_Release(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                        NvM_Prv_JobData_tst const* JobData_pcst)
{
    if (JobData_pcst == NvM_Prv_JobResources_apcst[idJobResource_uo])
    {
        NvM_Prv_JobResources_apcst[idJobResource_uo] = NULL_PTR;
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

