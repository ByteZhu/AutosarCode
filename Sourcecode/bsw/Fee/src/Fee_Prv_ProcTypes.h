
#ifndef FEE_PRV_PROCTYPES_H
#define FEE_PRV_PROCTYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if (defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))
#include "MemIf_Types.h"
#include "Fee_Rb_Types.h"
#include "Fee_Prv_JobTypes.h"
#include "Fee_Prv_ProcTypes.h"

/*
 **********************************************************************************************************************
 * Macros
 **********************************************************************************************************************
*/

/* Debouncing of background operations is active only for Fee2 */
#define FEE_PRV_PROC_MFCALLS_BEFORE_BACKGROUND_ACTION    (100u)

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

typedef enum
{
    FEE_PRV_PROC_DRIVERSTATE_UNINIT_E            = 0,    /* MEMIF_UNINIT                     */
    FEE_PRV_PROC_DRIVERSTATE_INIT_E              = 1,    /* MEMIF_BUSY_INTERNAL              */
    FEE_PRV_PROC_DRIVERSTATE_BACKGROUND_E        = 2,    /* MEMIF_BUSY_INTERNAL              */
    FEE_PRV_PROC_DRIVERSTATE_IDLE_E              = 3,    /* MEMIF_IDLE                       */
    FEE_PRV_PROC_DRIVERSTATE_EXT_JOB_E           = 4     /* MEMIF_BUSY/MEMIF_BUSY_INTERNAL   */
} Fee_Prv_ProcDriverState_ten;

typedef enum
{
    FEE_PRV_PROC_BACKGROUNDSTATE_DISABLED          = 0,  /* Background operations disabled                          */
    FEE_PRV_PROC_BACKGROUNDSTATE_ENABLED_ACTIVE    = 1,  /* Background operations enabled and still work to be done */
    FEE_PRV_PROC_BACKGROUNDSTATE_ENABLED_SLEEPING  = 2   /* Background operations enabled and no work to be done    */
} Fee_Prv_ProcBackgroundState_ten;

typedef struct
{
    Fee_Prv_ProcDriverState_ten     driverState_en;              /* State of the driver                                             */
    Fee_Prv_JobDesc_tst *           currentExtJob_pst;           /* Pointer to the external job which is currently being processed  */
    MemIf_ModeType                  driverModeActv_en;           /* Driver mode which is currently active                           */
#  if(FEE_PRV_CFG_AR_RELEASE_MAJOR_VERSION == 4) && (FEE_PRV_CFG_AR_RELEASE_MINOR_VERSION >=4)
    /* From Autosar 4.4 and newer */
    MemIf_ModeType                  driverModeReqd_en;           /* Requested driver mode                                           */
#  endif
    Fee_Prv_ProcBackgroundState_ten backgroundState_en;          /* Background scheduling state                                     */
    uint16                          backgroundDebounceCntr_u16;  /* Time delay before starting with expensive maintenance actions   */
    boolean                         backgroundCancelOngoing_b;   /* Identifies if cancelling of the background job is initiated     */
    boolean                         stopModeActive_b;            /* Reflects if the Fee processing has been stopped by the user     */
    boolean                         isWaitForNextChunk_b;        /* Reflects if the Fee processing is waiting for the next chunk    */
} Fee_Prv_Proc_tst;

typedef struct
{
    volatile boolean                flgUsedSema_vb;              /* Flag to hold the main function access status                    */
    volatile boolean                dbgReentrantMainFunction_vb; /* Flag to hold the debug information reentrant MainFunction       */
} Fee_Prv_ProcLock_tst;


/* RAM variable for the unit. Here all the data objects of the unit are collected */
typedef struct
{
    Fee_Prv_Proc_tst                proc_st;
    Fee_Prv_ProcLock_tst            procLock_st;
    Fee_Rb_WorkingStateType_ten     procWorkingState_en;
}Fee_Prv_ProcData_tst;

# endif
#endif

