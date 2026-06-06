

/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * Generator__: ComM / AR45.2.0.0                Module Package Version
 * Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 </VersionHead>*/



/* ---------------------------------------------------------------------*/
/* Include protection                                                   */
/* ---------------------------------------------------------------------*/
#ifndef  COMM_MAIN_H
#define  COMM_MAIN_H

#include "ComM_Cfg.h"

/* ---------------------------------------------------------------------*/
/* External declarations                                                */
/* ---------------------------------------------------------------------*/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/* ---------------------------------------------------------------------*/
/*  Name : ComM_MainFunction_Can_Network_0_Channel_Can_Network_0                                          */
/*  Description : Main function for Bus Type COMM_BUS_TYPE_CAN  channel Can_Network_0_Channel_Can_Network_0           */
/* ---------------------------------------------------------------------*/

#if ( COMM_ECUC_RB_RTE_IN_USE != STD_ON )
extern void ComM_MainFunction_Can_Network_0_Channel_Can_Network_0(void);
#endif

/* ---------------------------------------------------------------------*/
/*  Name : ComM_MainFunction_Can_Network_1_Channel_Can_Network_1                                          */
/*  Description : Main function for Bus Type COMM_BUS_TYPE_CAN  channel Can_Network_1_Channel_Can_Network_1           */
/* ---------------------------------------------------------------------*/

#if ( COMM_ECUC_RB_RTE_IN_USE != STD_ON )
extern void ComM_MainFunction_Can_Network_1_Channel_Can_Network_1(void);
#endif

/* ---------------------------------------------------------------------*/
/*  Name : ComM_MainFunction_Can_Network_2_Channel_Can_Network_2                                          */
/*  Description : Main function for Bus Type COMM_BUS_TYPE_CAN  channel Can_Network_2_Channel_Can_Network_2           */
/* ---------------------------------------------------------------------*/

#if ( COMM_ECUC_RB_RTE_IN_USE != STD_ON )
extern void ComM_MainFunction_Can_Network_2_Channel_Can_Network_2(void);
#endif

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/* ---------------------------------------------------------------------*/
/*  Name : ComM_MainFunc_PNC_ComMPnc                                          */
/*  Description : Main function for PNC ComMPnc           */
/* ---------------------------------------------------------------------*/
#if ( COMM_ECUC_RB_RTE_IN_USE != STD_ON )
extern void ComM_MainFunc_PNC_ComMPnc(void);
#endif

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"



#endif
