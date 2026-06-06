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

/*
 **************************************************************************************************
 * Includes
 **************************************************************************************************
 */

#include "EcuM.h" 
#include "EcuM_User.h"
#include "CDD_TCAN1145.h"
#include "ComM.h"
#include "SleepLogic.h"

static wakeup_src_t CDD_Check_Wakeup_Src(void);
/*
 **************************************************************************************************
 * Variables
 **************************************************************************************************
 */
static boolean CDD_CanTrcvSleepFlag = FALSE;
static NetworkState_e CDD_NetworkState = NETSTATE_NORMAL;

/**********************************************************************************
  Function name     :   EcuM_User_CheckWKSourceAll
  Description       :   The ECU Manager Module calls EcuM_User_CheckWKSourceAll to check what is the wakeup source by calling the CDD API
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :   The CDD API for checking wakeup reason is a stub. The user shall implement the complete API in CDD.
***********************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"
FUNC( void, ECUM_CALLOUT_CODE ) EcuM_User_CheckWKSourceAll(void)
{
  // wakeup_src_t wakeup_src;
  // wakeup_src = CDD_Check_Wakeup_Src();
  // switch (wakeup_src) 
  // {
  //   case KL15_WU:
  //     EcuM_SetWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_KL15);
  //     break;
  //   case CANMSG_WU:
  //     EcuM_SetWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_CANMSG);
  //     break;
  //   default:
  //     break;
  // }
  EcuM_SetWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_KL15);
  EcuM_SetWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_CANMSG);
}

/**********************************************************************************
  Function name     :   CDD_Check_Wakeup_Src
  Description       :   This is a stub of API to check wakeup reason in CDD
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :   The CDD API for checking wakeup reason is a stub. The user shall implement the complete API in CDD.
***********************************************************************************/
static wakeup_src_t CDD_Check_Wakeup_Src(void)
{
  static volatile wakeup_src_t wakeup_src = CANMSG_WU;//KL15_WU;//CANMSG_WU;//KL15_WU; //by default is KL15 wakeup
  /* code to check wakeup source */
  return wakeup_src;
}

/**********************************************************************************
  Function name     :   CDD_WakeupSrc_Monitor
  Description       :   This is a stub of API to monitor wakeup source
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :
***********************************************************************************/
void CDD_WakeupSrc_Monitor(void)
{

  boolean igCurState = FALSE;
  static boolean igPreState = TRUE;
  static boolean igWakeupSrcCheck = TRUE;
  static boolean fullCommReq = FALSE;

  /* check wakeup source CAN */
	if (TRUE == CDD_CanTrcvSleepFlag)
	{
		if (TRUE == TCAN1145_GetCANWakeupInterruptStatusTransceiver1())
		{
			CDD_CanTrcvSleepFlag = FALSE;

			EcuM_SetWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_CANMSG);
		}
	}

	/* check wakeup source IG */
  igCurState = SleepLogic_GetIGkeyState();//IoHwAb_GetKL15_Status();

  if (TRUE == igWakeupSrcCheck)
  {
    if (TRUE == igCurState)
    {
      EcuM_ValidateWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_KL15);
      igWakeupSrcCheck = FALSE;

      //ComM_RequestComMode(ComMConf_ComMUser_ComMUser_Can_Network_0_Channel_Can_Network_0, COMM_FULL_COMMUNICATION);
      ComM_RequestComMode(ComMConf_ComMUser_ComMUser_Can_Network_0_PNC29, COMM_FULL_COMMUNICATION);
      fullCommReq = TRUE;
    }
  }

	if ((TRUE == igCurState) && (FALSE == igPreState))
	{
		igWakeupSrcCheck = TRUE;
    EcuM_SetWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_KL15);
    /* if tranceiver sleep flag is set */
    if (TRUE == CDD_CanTrcvSleepFlag)
    {
      CDD_CanTrcvSleepFlag = FALSE;
      TCAN1145_Init1();
    }
	}
  else if ((FALSE == igCurState) && (TRUE == igPreState))
  {
    igWakeupSrcCheck = FALSE;

    if (TRUE == fullCommReq)
    {
      fullCommReq = FALSE;
      //ComM_RequestComMode(ComMConf_ComMUser_ComMUser_Can_Network_0_Channel_Can_Network_0, COMM_NO_COMMUNICATION);
      ComM_RequestComMode(ComMConf_ComMUser_ComMUser_Can_Network_0_PNC29, COMM_NO_COMMUNICATION);
    }
  }
  igPreState = igCurState;
}

/**********************************************************************************
  Function name     :   CDD_TrcvGoSleep
  Description       :   This is a stub of API to control transceiver to go to sleep
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :
***********************************************************************************/
void CDD_TrcvGoSleep(void)
{
	CDD_CanTrcvSleepFlag = TRUE;
	(void)TCAN1145_GetCANWakeupInterruptStatusTransceiver1();
	(void)TCAN1145_GetCANWakeupInterruptStatusTransceiver2();
	EcuM_ClearWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_CANMSG);
	EcuM_ClearWakeupEvent(EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_KL15);

	(void)TCAN1145_SendAndReceive1(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x81);
	(void)TCAN1145_SendAndReceive2(TCAN1145_MODE_CNTRL, TCAN1145_W_CMD, 0x81);
}

/**********************************************************************************
  Function name     :   CDD_TrcvGoSleep
  Description       :   This is a stub of API to control transceiver to go to sleep
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :
***********************************************************************************/
void CDD_SetNetworkState(NetworkState_e state)
{
  CDD_NetworkState = state;
}


/**********************************************************************************
  Function name     :   CDD_GetNetworkState
  Description       :   This is a stub of API to get network state
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :
***********************************************************************************/
NetworkState_e CDD_GetNetworkState(void)
{
  return CDD_NetworkState;
}

#define ECUM_STOP_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"



