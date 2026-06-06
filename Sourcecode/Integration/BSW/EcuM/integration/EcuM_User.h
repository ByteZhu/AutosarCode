/***********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2020. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Component 	: EcuM_User.h
 * Created on	: Apr 15, 2021
 * Version   	: 1.0
 * Author		 Nguyen Thanh Binh
 *  * This file is implement user call out for wakeup source
 **********************************************************************************************************************/


#ifndef INTEGRATIon_ECUM_USER_H
#define INTEGRATIon_ECUM_USER_H

typedef enum{
  NO_REASON_WU = 0,
  KL15_WU_0,
  CANMSG_WU,
  RESERVED
} wakeup_src_t;

/* network state */
typedef enum
{
  NETSTATE_NORMAL,
  NETSTATE_SLEEP
}NetworkState_e;

FUNC( void, ECUM_CALLOUT_CODE ) EcuM_User_CheckWKSourceAll(void);

void CDD_WakeupSrc_Monitor(void);
void CDD_TrcvGoSleep(void);
void CDD_SetNetworkState(NetworkState_e state);
NetworkState_e CDD_GetNetworkState(void);

#endif /* INTEGRATIon_ECUM_USER_H */
