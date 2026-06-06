#ifndef NVM_PRV_REQUESTQUEUE_H
#define NVM_PRV_REQUESTQUEUE_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM_Prv_RequestQueue_Types.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern void NvM_Prv_RequestQueue_Initialize(boolean isSavedZoneDataLost_b);


/* Important Note:
 * the caller of the following functions has to ensure that
 *      idQueue_uo
 * is within the valid value range (to avoid AooB access)
 * */

extern boolean NvM_Prv_RequestQueue_Enqueue(NvM_Prv_idQueue_tuo idQueue_uo,
                                            NvM_Prv_Queue_idx_tuo* idxPosition_puo);

extern void NvM_Prv_RequestQueue_Insert(NvM_Prv_idQueue_tuo idQueue_uo,
                                        NvM_Prv_QueueEntry_tst const* QueueEntry_pcst,
                                        NvM_Prv_Queue_idx_tuo idxPosition_uo);

extern boolean NvM_Prv_RequestQueue_IsInserted(NvM_Prv_idQueue_tuo idQueue_uo, NvM_Prv_Queue_idx_tuo idxRequest_uo);

extern void NvM_Prv_RequestQueue_Dequeue(NvM_Prv_idQueue_tuo idQueue_uo, NvM_Prv_Queue_idx_tst const* idxRequest_pcst);

/* Note: this function is returning an AooB queue index only if *QueueEntry_ppst is NULL_PTR.
 * The caller has to avoid using the returned value if the point is NULL_PTR and vice-versa.
 * It is sufficient to check only one information.
 */
extern NvM_Prv_idQueue_tuo NvM_Prv_RequestQueue_GetEntryToProcess(NvM_Prv_idJobResource_tuo idJobResource_uo,
                                                                  NvM_Prv_QueueEntry_tst** QueueEntry_ppst,
                                                                  NvM_Prv_Queue_idx_tst* idxRequest_pst);

extern boolean NvM_Prv_RequestQueue_IsMultiEnqueued(NvM_Prv_idService_tuo idService_uo);

#if (defined(TESTCD_NVM_ENABLED) && (TESTCD_NVM_ENABLED == STD_ON))

extern boolean NvM_Prv_RequestQueue_IsEmpty(NvM_Prv_idQueue_tuo idQueue_uo);
extern NvM_Prv_Queue_idx_tuo NvM_Prv_RequestQueue_GetFreeEntries(NvM_Prv_idQueue_tuo idQueue_uo);

#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* NVM_PRV_REQUESTQUEUE_H */
#endif

