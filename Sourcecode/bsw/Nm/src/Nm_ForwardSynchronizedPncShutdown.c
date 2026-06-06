
/* NM Interface header file for declaration of callback notifications,
 * this is included by the <Bus>Nm modules */
#include "Nm_Cbk.h"
/* NM Interface private header file, this file is included only by Nm module */
#include "Nm_Priv.h"
/* Included to access ComM APIs related with NM */
#include "ComM.h"

#if(NM_ENABLE_INTER_MODULE_CHECKS)
# if (!defined(COMM_AR_RELEASE_MAJOR_VERSION) || (COMM_AR_RELEASE_MAJOR_VERSION != NM_AR_RELEASE_MAJOR_VERSION))
#  error "AUTOSAR major version undefined or mismatched"
# endif
# if (!defined(COMM_AR_RELEASE_MINOR_VERSION) || (COMM_AR_RELEASE_MINOR_VERSION != NM_AR_RELEASE_MINOR_VERSION))
#  error "AUTOSAR minor version undefined or mismatched"
# endif
#endif /* #if(NM_ENABLE_INTER_MODULE_CHECKS) */


/**************************************************************************************************************
 * Function
 **************************************************************************************************************
 **************************************************************************************************************
 * Function Name: Nm_ForwardSynchronizedPncShutdown

 * Description:   Notification that the network management has received a PN shutdown message on a
 *                particular NM-channel. This is used to grant a nearly synchronized PNC shutdown across the
 *                entire PN topology.
 * Parameter:     NetworkHandle- Identification of the NM-channel
 * Return:        Void
 *************************************************************************************************************/



#define NM_START_SEC_CODE
#include "Nm_MemMap.h"

void Nm_ForwardSynchronizedPncShutdown(NetworkHandleType NetworkHandle)
{
#if (NM_SYNCHRONIZED_PNC_SHUTDOWN != STD_OFF)
    NetworkHandleType Nm_NetworkHandle_u8;  /* Network handle is forwarded in ComM Comp*/

    /* Receive the Internal NmChannel structure index from the received ComM NetworkHandle*/
    Nm_NetworkHandle_u8 = NM_GET_HANDLE(NetworkHandle);

    /* Process only if the channel handle is within allowed range */
    if (Nm_NetworkHandle_u8 < NM_NUMBER_OF_CHANNELS)
    {
        ComM_Nm_ForwardSynchronizedPncShutdown(NetworkHandle);
    }
#else
    (void) NetworkHandle;
#endif/*#if (NM_SYNCHRONIZED_PNC_SHUTDOWN != STD_OFF)*/
}

#define NM_STOP_SEC_CODE
#include "Nm_MemMap.h"


