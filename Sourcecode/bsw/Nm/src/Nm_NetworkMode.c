/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */
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


/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */

/**************************************************************************************************************
 * Function
 **************************************************************************************************************
 **************************************************************************************************************
 * Function Name: Nm_NetworkMode

 * Description:   This is the NM call-back interface notifying Network Mode, this is called by BusNm
 *                when it enters Network mode. This in turn notifies ComM.
 * Parameter:     NetworkHandle - Identification of the NM-channel
 * Return:        void
 *************************************************************************************************************/

#define NM_START_SEC_CODE
#include "Nm_MemMap.h"
void Nm_NetworkMode(NetworkHandleType NetworkHandle)
{
    /* #if (NM_COORDINATOR_SUPPORT_ENABLED != STD_OFF)
     * declare varibale for channel ,cluster
     * #endif
     * */
#if (NM_COORDINATOR_SUPPORT_ENABLED != STD_OFF)
    const Nm_ConfigType * ConfDataPtr_pcst;
    Nm_NetworkRamType_tst * MainNetworkRamDataPtr_pst;
    Nm_GlobalRamType_tst * GlobalRamDataPtr_pst;
#endif

    NetworkHandleType Nm_NetworkHandle_u8;
    /**** End of declarations ****/

    /* Receive the Internal NmChannel structure index from the received ComM NetworkHandle*/
    Nm_NetworkHandle_u8 = NM_GET_HANDLE(NetworkHandle);

    if (Nm_NetworkHandle_u8 < NM_NUMBER_OF_CHANNELS)
    {
        ComM_Nm_NetworkMode(NetworkHandle);

#if (NM_COORDINATOR_SUPPORT_ENABLED != STD_OFF)
        ConfDataPtr_pcst = &Nm_ConfData_cs[Nm_NetworkHandle_u8];
        if((ConfDataPtr_pcst->ClusterIdx != 0xFF))
        {

            MainNetworkRamDataPtr_pst = &Nm_ChannelData_s[Nm_NetworkHandle_u8];
            GlobalRamDataPtr_pst = &Nm_GlobalData_s[ConfDataPtr_pcst->ClusterIdx];

            SchM_Enter_Nm_ChangeStateNoNest();
            GlobalRamDataPtr_pst->AbortedShutdown_b = TRUE;
            SchM_Exit_Nm_ChangeStateNoNest();

        }
#endif

    }
}
#define NM_STOP_SEC_CODE
#include "Nm_MemMap.h"

