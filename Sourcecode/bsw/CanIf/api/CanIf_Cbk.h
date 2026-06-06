
#ifndef CANIF_CBK_H
#define CANIF_CBK_H

/***************************************************************************************************
**                      Include Section                                                           **
***************************************************************************************************/

/* BSWEXT-317 */
#include "CanIf_Integration.h"
/* END BSWEXT-317 */
#include "CanIf_Cfg.h"

/***************************************************************************************************
**                                   Global Callback Function Prototypes                          **
***************************************************************************************************/

/* Declaration of CanIf_RxIndication() API */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/* BSWEXT-317 */
extern void CanIf_RxIndication_Internal(const Can_HwType * Mailbox,
        const PduInfoType * PduInfoPtr);
/* [$DD_BSWCODE 40540] */
/* END BSWEXT-317 */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/* Declaration of CanIf_TrcvModeIndication() API */
#if CANIF_CFG_TRCV_DRV_SUPPORT==STD_ON
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern void CanIf_TrcvModeIndication( uint8 TransceiverId,
        CanTrcv_TrcvModeType TransceiverMode);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/* Declaration of CanIf_ClearTrcvWufFlagIndication() API */
#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
void CanIf_ClearTrcvWufFlagIndication( uint8 TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/* Declaration of CanIf_CheckTrcvWakeFlagIndication() API */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
void CanIf_CheckTrcvWakeFlagIndication( uint8 TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/* Declaration of CanIf_ConfirmPnAvailability() API */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
void CanIf_ConfirmPnAvailability( uint8 TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
#endif

/* Declaration of CanIf_TxConfirmation() API */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern void CanIf_TxConfirmation(PduIdType CanTxPduId );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"


/* Declaration of CanIf_ControllerBusOff() API */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern void CanIf_ControllerBusOff(uint8 ControllerId );
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/* BSWEXT-317 */
/* Declaration of CanIf_ControllerModeIndication_Internal() API */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern void CanIf_ControllerModeIndication_Internal( uint8 ControllerId, Can_ControllerStateType ControllerMode);
/* [$DD_BSWCODE 40543] */
/* END BSWEXT-317 */
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

/* Declaration of CanIf_ControllerErrorPassive() API */
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern void CanIf_ControllerErrorPassive( uint8 ControllerId);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif   /* CANIF_CBK_H */


