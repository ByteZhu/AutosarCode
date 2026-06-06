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
 Function name    : CanIf_SetControllerMode_Integration

 Description      : This service is used to ensure that Can_SetControllerMode request works well across AR versions.
    From AR 4.3, Can_SetControllerMode function accepts a Can_ControllerStateType parameter.

    For AR version <= 4.2, this API will:
                - Map requestedState of Can_ControllerStateType into Transition of Can_StateTransitionType
                - Support the SWS_CANIF_00487 requirement to generate CAN_T_WAKEUP
                - call the 4.2 AR Can_SetControllerMode API.
    For AR version > 4.2, this API will:
                - directly route the request to Can Driver
 BSWEXT-317
 ***************************************************************************************************
 */

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

/* [$DD_BSWCODE 40546] */
Std_ReturnType CanIf_SetControllerMode_Integration( uint8 Controller, Can_ControllerStateType requestedState, Can_ControllerStateType currentState)
{
    Std_ReturnType retVal = E_NOT_OK;
    Can_StateTransitionType requestedState1;

#if(CANIF_SETCONTROLLERMODE_INTEGRATION_VERSION > 2)
    /* [$DD_BSWCODE 40548] */
    if(requestedState == CAN_CS_STARTED)
        requestedState1 = CAN_T_START;
    else if((requestedState == CAN_CS_STOPPED)&&(currentState == CAN_CS_SLEEP))
        requestedState1 = CAN_T_WAKEUP;
    else if(requestedState == CAN_CS_STOPPED)
        requestedState1 = CAN_T_STOP;
    else if(requestedState == CAN_CS_SLEEP)
        requestedState1 = CAN_T_SLEEP;
    else 
        requestedState1 = CAN_T_STOP;
    retVal = Can_SetControllerMode(Controller, requestedState1);

#elif(CANIF_SETCONTROLLERMODE_INTEGRATION_VERSION <= 2)
    Can_StateTransitionType Transition;

    /* [$DD_BSWCODE 40547] */
    /* AR 4.3.1 and AR 4.2.2 defines Can_SetControllerMode function prototype differently in the second parameter
     * AR 4.2.2 uses Can_StateTransitionType; however, 4.3.1 uses Can_ControllerStateType
     * Below code is a mapping for them.
     */
    switch (requestedState)
    {
        case CAN_CS_STARTED:
            Transition = CAN_T_START;
            break;
        case CAN_CS_STOPPED:
            if (currentState == CAN_CS_SLEEP) {
                Transition = CAN_T_WAKEUP;
            } else {
                Transition = CAN_T_STOP;
            }
            break;
        case CAN_CS_SLEEP:
            Transition = CAN_T_SLEEP;
            break;
        default:
            Transition = CAN_T_STOP;
            break;
    }
    // enum definition of Can_ReturnType are of the same value and meaning with Std_ReturnType.
    // typecast to Can_ReturnType makes no change in term of meaning and functionality.
    retVal = (Can_ReturnType)Can_SetControllerMode(Controller, Transition);
#endif

    return retVal;
}


#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
