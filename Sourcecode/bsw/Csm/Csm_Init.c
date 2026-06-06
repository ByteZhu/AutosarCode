/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.Csm
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Csm.h"
#include "Csm_Prv.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define CSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"

boolean Csm_Initialized_b = FALSE;

#define CSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Csm_MemMap.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"

/**
 **********************************************************************************************************************
 * Csm_Init
 *
 * \brief Initializes the CSM module.
 *
 **********************************************************************************************************************
 */
//TRACE[SWS_Csm_00646]
void Csm_Init(const Csm_ConfigType* configPtr)
{
    uint32_least i;


    //TRACE[SWS_Csm_00186] it is always NULL_PTR so it won't be used
    CSM_PARAM_UNUSED(configPtr);
    // Check if Csm already initialized
    if (!Csm_Prv_IsInitialized())
    {
        // Reset all job states and related queues
        for (i = 0; i < CSM_CFG_JOB_COUNT; ++i)
        {
            Csm_Prv_Jobs_ast[i].jobState = CRYPTO_JOBSTATE_IDLE;
        }

        Csm_Prv_InitQueues(&Csm_Prv_QueueRefs_apst[0U], CSM_CFG_QUEUE_COUNT);
        Csm_Initialized_b = TRUE;
    }
    else
    {
        //TRACE[SWS_Csm_00659]|0
    }
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

