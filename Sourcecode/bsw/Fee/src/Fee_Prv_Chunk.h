
#ifndef FEE_PRV_CHUNK_H
#define FEE_PRV_CHUNK_H


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"


/* Disable the Fee common part when not needed */
# if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))

/* Disable this unit when not needed */
#  if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS))

#include "Fee_Prv_JobTypes.h"
#include "MemIf_Types.h"

/*
 **********************************************************************************************************************
 * Inline declarations and implementations
 **********************************************************************************************************************
*/
#   if(defined(RBA_FEEFS1_PRV_CFG_ENABLED) && (TRUE ==  RBA_FEEFS1_PRV_CFG_ENABLED))
extern void Fee_Prv_ChunkInit(void);
#   else
#define Fee_Prv_ChunkInit()    // When Fee1.0 is not used, there are no static variables in chunk unit, so nothing to initalize
#   endif

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

extern void    Fee_Prv_ChunkDoneCbk (
        Fee_Rb_DeviceName_ten deviceName_en,
        Fee_Prv_JobDesc_tst const * xJob_pcst,
        MemIf_JobResultType stRes_en,
        Fee_Prv_JobChunkInfo_tst * stChunk_pst);

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


#  else
#define Fee_Prv_ChunkInit()    // When chunk is not active, there are no static variables in chunk unit, so nothing to initalize
/* #  if(defined(FEE_PRV_CFG_RB_CHUNK_JOBS) && (TRUE == FEE_PRV_CFG_RB_CHUNK_JOBS)) */
#  endif

/* # if(defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED)) */
# endif

/* #ifndef FEE_PRV_CHUNK_H */
#endif
