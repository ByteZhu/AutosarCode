

/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * Generator__: ComM / AR45.2.0.0                Module Package Version
 * Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 </VersionHead>*/



/* ---------------------------------------------------------------------*/
/* Inlcude section                                                      */
/* ---------------------------------------------------------------------*/
#include "ComM_Priv.h"


#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/*
 *  Name : ComM_MainFunction_Can_Network_0_Channel_Can_Network_0
 *  Description : Main function for Bus Type COMM_BUS_TYPE_CAN channel Can_Network_0_Channel_Can_Network_0
 *
 */
void ComM_MainFunction_Can_Network_0_Channel_Can_Network_0(void)
{
    ComM_Prv_ChannelMainFunction(0) ;
}

/*
 *  Name : ComM_MainFunction_Can_Network_1_Channel_Can_Network_1
 *  Description : Main function for Bus Type COMM_BUS_TYPE_CAN channel Can_Network_1_Channel_Can_Network_1
 *
 */
void ComM_MainFunction_Can_Network_1_Channel_Can_Network_1(void)
{
    ComM_Prv_ChannelMainFunction(1) ;
}

/*
 *  Name : ComM_MainFunction_Can_Network_2_Channel_Can_Network_2
 *  Description : Main function for Bus Type COMM_BUS_TYPE_CAN channel Can_Network_2_Channel_Can_Network_2
 *
 */
void ComM_MainFunction_Can_Network_2_Channel_Can_Network_2(void)
{
    ComM_Prv_ChannelMainFunction(2) ;
}

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"



#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"


/*
 *  Name : ComM_MainFunc_PNCComMPnc
 *  Description : Main function for PNC ComMPnc
 */
void ComM_MainFunc_PNC_ComMPnc(void)
{   
     /*Configured ComMPncId : (29) , Internal ComMPncId : (0)*/  
    ComM_Prv_PncMainFunction(0) ;
}


#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#if (COMM_PNC_GW_ENABLED == STD_ON)



#endif /*  #if (COMM_PNC_GW_ENABLED == STD_ON)  */

#if (COMM_PNC_ENABLED == STD_ON)


/* EIRA call backs are generated for all possible bus types, depending on the bus types configred in
   ComMChannel container. This is to ensure that call backs are always available in Post-build configuration.
   Precompile : same approach is followed to keep the code same. */
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/*
 *  Name : ComM_EIRACallBack_COMM_BUS_TYPE_CAN
 *  Description : EIRA callback for bus type COMM_BUS_TYPE_CAN
 *                  This function will be called whenever EIRA signal for this bus type changes
 */

void ComM_EIRACallBack_COMM_BUS_TYPE_CAN(void)
{
    ComM_Prv_EIRA_CallBack(0);
}

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#endif /* #if (COMM_PNC_ENABLED == STD_ON)  */

/*----------------------------------------------------------------------*/

/************************************************************************/
