

#ifndef DCMDSPUDS_PRV_RC_H
#define DCMDSPUDS_PRV_RC_H

#if (DCM_CFG_DSP_ROUTINECONTROL_ENABLED == DCM_CFG_ON)
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
extern uint8 * Dcm_RCDataOutVar_pau8;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern void Dcm_Prv_RCSessionChangeTrigger (Dcm_SesCtrlType newSession);
extern void Dcm_Prv_DspRCConfirmation(uint8 sid_u8, uint8 reqType_u8,uint16 connectionId_u16,
                                        Dcm_ConfirmationStatusType confirmationStatus, Dcm_ProtocolType protocolType,uint16 testerSrcAddress_u16);
extern void Dcm_Prv_RC_Mainfunction(void);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"


#endif   /* (DCM_CFG_DSP_ROUTINECONTROL_ENABLED == DCM_CFG_ON) */
#endif  /* DCMDSPUDS_PRV_RC_H */
