
#ifndef DCM_GENERAL_H
#define DCM_GENERAL_H

/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
*/
//#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
//#include "Dcm_MemMap.h"
//extern Dcm_DslDsd_TimerMointor Dcm_DsldTimerMonitor_st;
//#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
//#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern boolean Dcm_IsCancelTransmitInvoked_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

/*
 **********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************
 */
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_SrvOpStatusType Dcm_SrvOpstatus_u8;
extern Dcm_OpStatusType    Dcm_ExtSrvOpStatus_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

void Dcm_Init (const Dcm_ConfigType* ConfigPtr);


/**
 * @ingroup API
 *
 * Dcm_GetVersionInfo   Returns the version information of this module.
 *
 * @param versioninfo   Pointer to where to store the version information of this module.
 * @return              None
 */
#if (DCM_CFG_VERSIONINFO_SUPPORTED)
void Dcm_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif /* #if (DCM_CFG_VERSIONINFO_SUPPORTED) */

/**
 * @ingroup API
 * Dcm_ComM_FullComModeEntered - All kind of transmissions shall be enabled immediately. This means that
 * the ResponseOnEvent and PeriodicId. It will be a dummy function in boot as ComM is not available in boot.
 * @param[in]       NetworkId  Identifies the Channel for which the Communication mode changed.
 * @retval          None
 */
void Dcm_ComM_FullComModeEntered(uint8 NetworkId);

/* Called by ComM module */
/**
 * @ingroup API
 * All kind of transmissions (receive and transmit) shall be stopped . This means that the ResponseOnEvent
 * and PeriodicId and also the transmission of the normal communication (PduR_DcmTransmit) shall be disabled.
 * It will be a dummy function in boot as ComM is not available in boot.
 * @param[in]       NetworkId  Identifies the Channel for which the Communication mode changed.
 * @retval          None
 */
void Dcm_ComM_NoComModeEntered(uint8 NetworkId);

/**
 * @ingroup API
 * Dcm_ComM_SilentComModeEntered: All outgoing transmissions shall be stopped immediately. This means that the
 * ResponseOnEvent and PeriodicId and also the transmission of the normal communication (PduR_DcmTransmit)
 * shall be disabled.
 * It will be a dummy function in boot as ComM is not available in boot.
 * @param[in]       NetworkId  Identifies the Channel for which the Communication mode changed.
 * @retval          None
 */
void Dcm_ComM_SilentComModeEntered(uint8 NetworkId);

/**
 * @ingroup API
 * Dcm_SetActiveDiagnostic - The call of this function allows to activate and deactivate the call of ComM_DCM_ActiveDiagnostic() function
 *  @param[in]    active:  True Dcm will call ComM_DCM_ActiveDiagnostic() \n
 *                           False Dcm shall not call ComM_DCM_ActiveDiagnostic()
 *  @retval    E_OK : this value is always returned.
 */
#if(DCM_CFG_RTESUPPORT_ENABLED == DCM_CFG_OFF)
extern Std_ReturnType Dcm_SetActiveDiagnostic(boolean active);
#endif


Std_ReturnType Dcm_StartProtocol(Dcm_ProtocolType ProtocolID,uint16 TesterSourceAddress, uint16 ConnectionId);
void Dcm_StopProtocol(Dcm_ProtocolType ProtocolID,uint16 TesterSourceAddress, uint16 ConnectionId);

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif
