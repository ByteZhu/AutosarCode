
/*
 * The Job unit stores the received orders in internal job slots.
 * The main function will poll jobs from the Job unit and inform the Job unit if a job is finished.
 */

#ifndef FEE_PRV_JOBTYPES_H
#define FEE_PRV_JOBTYPES_H

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

#include "MemIf_Types.h"
#include "Fee_Prv_ConfigTypes.h"
#include "Fee_Rb_Types.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/* Every job is stored in such a job struct */
typedef struct
{
    Fee_Rb_JobType_ten      type_en;         /* Read/Write/Invalidate job                                         */
    Fee_Rb_JobMode_ten      jobMode_en;      /* Mode in which current job has to be executed                      */
    uint8  *                bfr_pu8;         /* Pointer to a variable buffer - needed for read jobs               */
    uint8  const *          bfr_pcu8;        /* Pointer to a constant buffer - needed for write jobs              */
    uint16                  blockNumber_u16; /* Blocknumber as defined in Fee.h - this is NOT the persistent ID ! */
    uint16                  length_u16;      /* Length of the block operation                                     */
    uint16                  offset_u16;      /* Offset of the block operation                                     */
    uint16                  nrBytTot_u16;    /* Number of total payload bytes (in all chunks)                     */
    uint16                  cntrBytDone_u16; /* Payload bytes that have been processed so far (in all chunks)     */
    uint16                  idPers_u16;      /* Block's persistent ID (unique block identifier)                   */
    uint16                  statusFlag_u16;  /* Status flag (used for unknown block handling)                     */
    boolean                 isChunkJob_b;    /* When = TRUE, the job is coming from Chunk API                     */
    boolean                 isUnknownBlk_b;  /* when = TRUE, the job is for an unknown block                      */
} Fee_Prv_JobDesc_tst;

/* All jobs and their results */
typedef struct
{
    Fee_Prv_JobDesc_tst     jobs_ast[FEE_PRV_REQUESTER_MAX_E];        /* Current jobs              */
    MemIf_JobResultType     results_aen[FEE_PRV_REQUESTER_MAX_E];     /* Results of the last jobs  */
#  if((FEE_PRV_CFG_RB_SET_AND_GET_JOB_MODE != FALSE) || (STD_ON == FEE_PRV_CFG_SET_MODE_SUPPORTED))
    Fee_Rb_JobMode_ten      jobMode_en[FEE_RB_JOBTYPE_MAX_E]; /* Job mode for different jobs */
#  endif
} Fee_Prv_Job_tst;

/* Chunk-wise job status */
typedef struct
{
    uint32                    nrBytProc_u32;  /* Bytes processed in last/current chunk(-wise job), including header */
    Fee_Rb_ChunkResult_ten    result_en;      /* Result of last/current chunk(-wise job)                            */
} Fee_Prv_JobChunkInfo_tst;

/* RAM variable for the unit. Here all the data objects of the unit are collected */
typedef struct
{
    Fee_Prv_JobDesc_tst         jobDesc_st;
    Fee_Prv_Job_tst             job_st;
    Fee_Prv_JobChunkInfo_tst    chunkInfo_st;
}Fee_Prv_JobData_tst;

# endif

/* FEE_PRV_JOBTYPES_H */
#endif
