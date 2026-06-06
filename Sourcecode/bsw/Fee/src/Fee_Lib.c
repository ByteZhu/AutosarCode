
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Std_Types.h"
#include "Fee_Prv_Cfg.h"

/* Disable the Fee common part when not needed */
# if (defined(FEE_PRV_CFG_COMMON_ENABLED) && (TRUE == FEE_PRV_CFG_COMMON_ENABLED))
#include "Fee_Prv_Lib.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

/* Array which weights the actions. Since this variable is constant for all instances. it is ok to keep this variable
 * locally in this unit and not move it to the Fee_Prv_Cfg unit. */
#define FEE_START_SEC_CONST_8
#include "Fee_MemMap.h"
uint8 const Fee_Prv_LibEffortWeights_au8[FEE_PRV_LIMIT_MAX_E] =
{
    0,  /* FEE_PRV_LIMIT_CRCINRAM_CPYRAM_E */
    1,  /* FEE_PRV_LIMIT_CRCINFLS_E        */
    5,  /* FEE_PRV_LIMIT_HDR_E             */
    10  /* FEE_PRV_LIMIT_CACHEREORG_E      */
};
#define FEE_STOP_SEC_CONST_8
#include "Fee_MemMap.h"

#endif
