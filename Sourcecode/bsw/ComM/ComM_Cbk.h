

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
#ifndef  COMM_CBK_H
#define  COMM_CBK_H

/* ---------------------------------------------------------------------*/
/* External declarations                                                */
/* ---------------------------------------------------------------------*/






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

extern void ComM_EIRACallBack_COMM_BUS_TYPE_CAN(void);


#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#endif  /* #ifndef  COMM_CBK_H  */
