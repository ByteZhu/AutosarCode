
/* NM Interface private header file, this file is included only by Nm module */
#include "Nm_Priv.h"


/**************************************************************************************************************
 * Function
 **************************************************************************************************************
 **************************************************************************************************************
 * Function Name: Nm_RequestSynchronizedPncShutdown

 * Description:   This function forward the request for a synchronized PNC shutdown of a particular PNC given
 * by PncId to the affected <Bus>Nm by calling <Bus>Nm_RequestSynchronizedPncShutdown
 * The function call is only valid if NmStandardBusType is not set to NM_BUSNM_LOCALNM (e.g.
 * CanNm_RequestSynchronizedPncShutdown function is called for NM_BUSNM_CANNM).
 *
 * Parameter:     NetworkHandle- Identification of the NM-channel
 *                PncId- Identification of the Pnc which is requested for a synchronized
 *                shutdown across the PNC network topology
 *
 * Return:  Std_ReturnType
 * RetVal:  E_OK: No error
 *          E_NOT_OK: Request for a synchronized PNC shutdown has failed, e.g.
 *          NetworkHandle does not exist (development only)
 *          Module not yet initialized (development only)
 *************************************************************************************************************/



#define NM_START_SEC_CODE
#include "Nm_MemMap.h"

Std_ReturnType Nm_RequestSynchronizedPncShutdown(NetworkHandleType NetworkHandle,
        PNCHandleType PncId)
{

#if (NM_SYNCHRONIZED_PNC_SHUTDOWN != STD_OFF)
    const Nm_ConfigType * ConfDataPtr_pcst;     /* Configuration pointer holds referrence of configuration data */
    const Nm_BusNmApiType_tst * FuncPtr_pcst;   /* Pointer to Bus specific APIs */

    Std_ReturnType RetVal_u8;
    NetworkHandleType Nm_NetworkHandle_u8;
    /**** End of declarations ****/

    /* Receive the Internal NmChannel structure index from the received ComM NetworkHandle*/
    Nm_NetworkHandle_u8 = NM_GET_HANDLE(NetworkHandle);

    RetVal_u8 = E_NOT_OK;
    /* process only if the channel handle is within allowed range */
    if (Nm_NetworkHandle_u8 < NM_NUMBER_OF_CHANNELS)
    {
        /* Configuration pointer initialization */
        ConfDataPtr_pcst = &Nm_ConfData_cs[Nm_NetworkHandle_u8];

        FuncPtr_pcst = &Nm_BusNmApi[ConfDataPtr_pcst->BusNmType];

        RetVal_u8 = (*FuncPtr_pcst->BusNm_RequestSynchronizedPncShutdown_pfct)(NetworkHandle,PncId);
    }
    else
    {
        /* Report to DET as the network handle parameter is not a configured network handle */
        NM_DET_REPORT_ERROR(NetworkHandle, NM_SID_REQUESTSYNCHRONIZEDPNCSHUTDOWN, NM_E_INVALID_CHANNEL);
    }
    return(RetVal_u8);
#else
    (void)NetworkHandle;
    (void)PncId;
    return E_NOT_OK;

#endif/*#if (NM_SYNCHRONIZED_PNC_SHUTDOWN != STD_OFF)*/
}

#define NM_STOP_SEC_CODE
#include "Nm_MemMap.h"


