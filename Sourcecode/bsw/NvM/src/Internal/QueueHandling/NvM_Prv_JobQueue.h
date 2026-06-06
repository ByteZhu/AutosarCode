#ifndef NVM_PRV_JOBQUEUE_H
#define NVM_PRV_JOBQUEUE_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM_Prv_JobQueue_Types.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern void NvM_Prv_JobQueue_Initialize(void);

extern void NvM_Prv_JobQueue_Enqueue(NvM_Prv_Job_tst const* Job_pcst);

extern void NvM_Prv_JobQueue_Dequeue(NvM_Prv_Queue_idx_tst const* idxJob_pcst);

extern boolean NvM_Prv_JobQueue_IsFull(void);

extern boolean NvM_Prv_JobQueue_IsEmpty(void);

extern NvM_Prv_Queue_idx_tuo NvM_Prv_JobQueue_GetNrEntries(void);

extern NvM_Prv_Queue_idx_tuo NvM_Prv_JobQueue_GetIdxJob(uint8 nrJob_uo);

extern NvM_Prv_Job_tst* NvM_Prv_JobQueue_GetJob(uint8 nrJob_uo);

#if (defined(TESTCD_NVM_ENABLED) && (TESTCD_NVM_ENABLED == STD_ON))
extern uint8* NvM_Prv_JobQueue_GetUsedIntBfr(NvM_BlockIdType idBlock_uo, NvM_Prv_idService_tuo idService_uo);
extern NvM_Prv_JobData_tst* NvM_Prv_JobQueue_GetJobData(NvM_BlockIdType idBlock_uo,
                                                        NvM_Prv_idService_tuo idService_uo);
#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* NVM_PRV_JOBQUEUE_H */
#endif

