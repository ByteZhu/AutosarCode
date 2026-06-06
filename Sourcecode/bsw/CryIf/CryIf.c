/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.CryIf
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
//TRACE[SWS_CryIf_00008]
#include "CryIf.h"
//TRACE[SWS_CryIf_91101]TRACE[SWS_CryIf_91100]
#include "Det.h"
//TRACE[SWS_CryIf_91100]
#include "Csm.h"
#include "CryIf_Prv.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define CRYIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CryIf_MemMap.h"

boolean CryIf_Initialized_b = FALSE;

#define CRYIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CryIf_MemMap.h"

/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/
#define CRYIF_START_SEC_CODE
#include "CryIf_MemMap.h"

/**
 **********************************************************************************************************************
 * CryIf_Init
 *
 * \brief Initializes the CRYIF module.
 **********************************************************************************************************************
*/
 //TRACE[SWS_CryIf_91000]
void CryIf_Init(const CryIf_ConfigType* configPtr)
{
    //TRACE[SWS_CryIf_91019]
    //TRACE[SWS_CryIf_00014]
    //TRACE[SWS_CryIf_00015]
    CRYIF_PARAM_UNUSED(configPtr);
    CryIf_Initialized_b = TRUE;
}

/**
 **********************************************************************************************************************
 * CryIf_CallbackNotification
 *
 * \brief Notifies the CRYIF about the completion of the request with the result of the cryptographic operation.
 *
 * \param[in]  job      Points to the completed job's information structure. It contains a callbackID to identify
 *                      which job is finished.
 * \param[in]  result   Contains the result of the cryptographic operation.
 **********************************************************************************************************************
*/
//TRACE[SWS_CryIf_91013]
 /* MR12 RULE 8.13 VIOLATION: the pointer can not be const because this interface is defined by AUTOSAR */
void CryIf_CallbackNotification(Crypto_JobType* job, Crypto_ResultType result)
{
    //Check if component is not initialized
    if (!CryIf_Prv_IsInitialized())
    {
        //TRACE[SWS_CryIf_00107]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CALLBACK_NOTIFICATION, CRYIF_E_UNINIT);
    }
    //Check if job is invalid
    else if (NULL_PTR == job)
    {
        //TRACE[SWS_CryIf_00108]|1
        (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, CRYIF_SERVICE_ID_CALLBACK_NOTIFICATION, CRYIF_E_PARAM_POINTER);
    }
    //Forward callback to Csm
    else
    {
        //TRACE[SWS_CryIf_00109]
        /* MR12 RULE 11.8 VIOLATION: const converted to volatile because of AR spec. ,but it will be only read */
        Csm_CallbackNotification((Crypto_JobType*)job,result);
    }
}

#define CRYIF_STOP_SEC_CODE
#include "CryIf_MemMap.h"

