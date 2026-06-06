
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "E2EXf.h"
#include "E2EXf_Prv.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */

#define E2EXF_START_SEC_VAR_INIT_BOOLEAN
#include "E2EXf_MemMap.h"
/* TRACE[SWS_E2EXf_00130] */
boolean E2EXf_Prv_Initialized_b = FALSE;
#define E2EXF_STOP_SEC_VAR_INIT_BOOLEAN
#include "E2EXf_MemMap.h"
 
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
 */

/**
*******************************************************************************************************************
* E2EXf_GetVersionInfo
*
* \brief private routine to spend information about the version of the library
*
* Description:
*
* Restrictions:
*   -
*
* Dependencies:
*   -
*
* Resources:
*   -
*
* \param   Std_VersionInfoType *VersionInfo  Pointer to the version structure
* \return  void
*
*******************************************************************************************************************
*/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
/* TRACE[SWS_E2EXf_00036] */
void E2EXf_GetVersionInfo(Std_VersionInfoType * VersionInfo)
{
    if(NULL_PTR != VersionInfo)
    {
        VersionInfo->vendorID = E2EXF_VENDOR_ID;
        VersionInfo->moduleID = E2EXF_MODULE_ID;
        VersionInfo->sw_major_version = E2EXF_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = E2EXF_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version=  E2EXF_SW_PATCH_VERSION;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/**
*******************************************************************************************************************
* E2EXf_Init
*
* \brief Initializes the state of the E2E Transformer
*
* Description: Initializes the state of the E2E Transformer. The main part of it is the initialization of 
*              the E2E library state structures, which is done by calling all init-functions from E2E library.
* 
* Restrictions:
*   -
*
* Dependencies:
*   -
*
* Resources:
*   -
*
* \param   config       Pointer to a selected configuration structure, in the post-build-selectable variant. 
*                       NULL in link-time variant.
* \return  void
*
*******************************************************************************************************************
*/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
/* TRACE[SWS_E2EXf_00035] */
void E2EXf_Init(const E2EXf_ConfigType* config)
{
    Std_ReturnType return_en;
    
    
    (void)(config);
    /* TRACE[SWS_E2EXf_00021] */
    //Call Init of Link time configured E2EXf
    return_en = E2EXf_Prv_Lcfg_Init();
    /* TRACE[SWS_E2EXf_00130] */
    //Set init status when init was successful else clear;
    if(E_OK == return_en)
    {
        E2EXf_Prv_Initialized_b = TRUE;
    }
    else
    {
        E2EXf_Prv_Initialized_b = FALSE;
    }
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/**
*******************************************************************************************************************
* E2EXf_DeInit
*
* \brief Deinitializes the E2E transformer.
*
* Description: 
* 
* Restrictions:
*   -
*
* Dependencies:
*   -
*
* Resources:
*   -
*
* \param   void
* \return  void
*
*******************************************************************************************************************
*/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
/* TRACE[SWS_E2EXf_00138] */
void E2EXf_DeInit(void)
{
    /* TRACE[SWS_E2EXf_00132], TRACE[SWS_E2EXf_00148] */
    //Set init status
    E2EXf_Prv_Initialized_b = FALSE;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

