/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */

#include "CanIf_Integration.h"


/***************************************************************************************************
 Function name    : CanIf_GetControllerMode_Integration

 Description      : This service uses to ensure that Can_GetControllerMode request is available in all AR versions.

    Can_GetControllerMode is not defined in AR version <= 4.2, so the function returns E_NOT_OK in that case.

 BSWEXT-317
 ***************************************************************************************************
 */

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

/* [$DD_BSWCODE 40549] */
Std_ReturnType CanIf_GetControllerMode_Integration( uint8 Controller, Can_ControllerStateType* ControllerModePtr)
{
    Std_ReturnType retVal = E_NOT_OK;

#if(CANIF_GETCONTROLLERMODE_INTEGRATION_VERSION > 2)
    /* [$DD_BSWCODE 40551] */
    retVal = Can_GetControllerMode(Controller, ControllerModePtr);
#endif
    /* [$DD_BSWCODE 40550] */

    return retVal;
}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
