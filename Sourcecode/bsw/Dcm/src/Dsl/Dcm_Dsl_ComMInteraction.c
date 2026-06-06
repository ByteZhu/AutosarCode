#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "ComM_Dcm.h"
#include "Dcm_Prv.h"


/***********************************************************************************************************************
 *    Function Definition
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


/* Dcm_Prv_SetComMState: This INLINE function is used to Set whether Network Id is valid or not.*/
LOCAL_INLINE void Dcm_Prv_SetComMState(uint8 NetworkId,Dcm_Dsld_commodeType ComManagerState)
{
    uint8 idxNetwork_u8;
    for(idxNetwork_u8 = 0;idxNetwork_u8<DCM_NUM_COMM_CHANNEL;idxNetwork_u8++)
    {
        if(Dcm_active_commode_e[idxNetwork_u8].ComMChannelId == NetworkId)
        {
            break;
        }
    }
    if (idxNetwork_u8 < DCM_NUM_COMM_CHANNEL)
    {
        Dcm_active_commode_e[idxNetwork_u8].ComMState = ComManagerState;
    }
}


/* Dcm_ComM_FullComModeEntered: All kind of transmissions shall be enabled immediately. This means that
 * the ResponseOnEvent and PeriodicId. It will be a dummy function in boot as ComM is not available in boot */
void Dcm_ComM_FullComModeEntered(uint8 NetworkId)
{
    /*  Communication mode of the corresponding to  network is set to Full Communication mode */
    Dcm_Prv_SetComMState(NetworkId,DCM_DSLD_FULL_COM_MODE);
}


/* Dcm_ComM_NoComModeEntered: All kind of transmissions (receive and transmit) shall be stopped .
 * This means that the ResponseOnEvent and PeriodicId and also the transmission of the normal communication (PduR_DcmTransmit) shall be disabled.
 * It will be a dummy function in boot as ComM is not available in boot */
void Dcm_ComM_NoComModeEntered(uint8 NetworkId)
{
    /*  Communication mode of the corresponding to  network is set to No Communication mode */
    Dcm_Prv_SetComMState(NetworkId,DCM_DSLD_NO_COM_MODE);
}


/* Dcm_ComM_SilentComModeEntered: All outgoing transmissions shall be stopped immediately. This means that the
 * ResponseOnEvent and PeriodicId and also the transmission of the normal communication (PduR_DcmTransmit)
 * shall be disabled.
 * It will be a dummy function in boot as ComM is not available in boot */
void Dcm_ComM_SilentComModeEntered(uint8 NetworkId)
{
    /*  Communication mode of the corresponding to  network is set to silent  Communication mode */
    Dcm_Prv_SetComMState(NetworkId,DCM_DSLD_SILENT_COM_MODE);
}


/* Dcm_SetActiveDiagnostic: The call of this function allows to activate and deactivate the call of ComM_DCM_ActiveDiagnostic() function */
Std_ReturnType Dcm_SetActiveDiagnostic(boolean active)
{
    Dcm_ActiveDiagnosticState_en = (active == TRUE)? DCM_COMM_ACTIVE : DCM_COMM_NOT_ACTIVE;

    return(E_OK);
}


/* Dcm_CheckActiveDiagnosticStatus: The function checks whether ComM_DCM_ActiveDiagnostic()function needs to be called or not */
void Dcm_CheckActiveDiagnosticStatus(uint8 dataNetworkId)
{
    if(Dcm_ActiveDiagnosticState_en == DCM_COMM_ACTIVE)
    {
        ComM_DCM_ActiveDiagnostic(dataNetworkId);
    }
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
