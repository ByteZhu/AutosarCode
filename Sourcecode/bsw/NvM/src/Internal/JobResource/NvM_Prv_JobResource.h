#ifndef NVM_PRV_JOBRESOURCE_H
#define NVM_PRV_JOBRESOURCE_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM_Prv_Job_Types.h"
#include "NvM_Prv_JobResource_Types.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern void NvM_Prv_JobResource_Init(void);

extern void NvM_Prv_JobResource_DoStateMachine(NvM_Prv_JobResource_Cluster_ten Cluster_en,
                                               NvM_Prv_stJob_ten* stJob_pen,
                                               NvM_Prv_JobResult_tst* JobResult_pst,
                                               NvM_Prv_JobData_tst const* JobData_pcst);

extern void NvM_Prv_JobResource_Claim(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                      NvM_BlockIdType idBlock_uo);

extern void NvM_Prv_JobResource_Unclaim(NvM_BlockIdType idBlock_uo);

extern boolean NvM_Prv_JobResource_IsClaimed(NvM_Prv_idJobResource_tuo idJobResource_uo);

extern boolean NvM_Prv_JobResource_IsRequired(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                              NvM_BlockIdType idBlock_uo);

extern void NvM_Prv_JobResource_ExecuteStateMachine(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                                    NvM_Prv_stJob_ten* stJob_pen,
                                                    NvM_Prv_JobResult_tst* JobResult_pst,
                                                    NvM_Prv_JobData_tst const* JobData_pcst);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* NVM_PRV_JOBRESOURCE_H */
#endif

