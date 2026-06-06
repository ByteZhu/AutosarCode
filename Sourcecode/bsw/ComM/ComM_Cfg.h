


/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * Generator__: ComM / AR45.2.0.0                Module Package Version
 * Editor_____: ISOLAR-A/B 12.0.1_12.0.1                Tool Version
 *
 </VersionHead>*/



#ifndef  COMM_CFG_H
#define  COMM_CFG_H


/***********************************************************************************/
/*                                        INCLUDES                                 */
/***********************************************************************************/
#include "ComM_Types.h"
#include "Rte_ComM_Type.h"




/*
 ***************************************************************************************************
 * Version Information Defines
 ***************************************************************************************************
 */
/* ComM module id(according to AUTOSAR BSW module list)  */
#define COMM_MODULE_ID                 12u
/* ComM module id(according to AUTOSAR BSW module list)    */
#define COMM_VENDOR_ID                 6u
/* Version of AUTOSAR ComM specification */
/* Major Version of AUTOSAR ComM specification    */
#define COMM_AR_RELEASE_MAJOR_VERSION             4u
/* Minor Version of AUTOSAR ComM specification  */
#define COMM_AR_RELEASE_MINOR_VERSION             2u
/* Revision Version of AUTOSAR ComM specification  */
#define COMM_AR_RELEASE_REVISION_VERSION          2u
/* Version of AUTOSAR ComM implementation */
#define COMM_SW_MAJOR_VERSION          2u
/* Minor Version of AUTOSAR ComM implementation  */
#define COMM_SW_MINOR_VERSION          0u
/* Patch Version of AUTOSAR ComM implementation  */
#define COMM_SW_PATCH_VERSION          0u



/***********************************************************************************/
/*                                        DEFINES                                  */
/***********************************************************************************/

/* Define for configuration variant of ComM */

/* Macros for different config variants */

#define COMM_VARIANT_PRECOMPILE                                         0x00

#define COMM_VARIANT_POSTBUILD_LOADABLE                                 0x01

#define COMM_CONFIGURATION_VARIANT                                      COMM_VARIANT_PRECOMPILE

#define COMM_ECUC_RB_RTE_IN_USE                                         STD_ON


/*************************************************************************************/
/*                              Channel Symbolic Names                               */
/*************************************************************************************/

#define         ComMConf_ComMChannel_Can_Network_0_Channel_Can_Network_0       ((NetworkHandleType)0)

#define         ComMConf_ComMChannel_Can_Network_1_Channel_Can_Network_1       ((NetworkHandleType)1)

#define         ComMConf_ComMChannel_Can_Network_2_Channel_Can_Network_2       ((NetworkHandleType)2)


/*************************************************************************************/
/*                              User Symbolic Names                               */
/*************************************************************************************/

#define     ComMConf_ComMUser_ComMUser_Can_Network_0_Channel_Can_Network_0        ((ComM_UserHandleType)(0)) /* Internal UserId : (0)*/

#define     ComMConf_ComMUser_ComMUser_Can_Network_1_Channel_Can_Network_1        ((ComM_UserHandleType)(1)) /* Internal UserId : (1)*/

#define     ComMConf_ComMUser_ComMUser_Can_Network_2_Channel_Can_Network_2        ((ComM_UserHandleType)(2)) /* Internal UserId : (2)*/

#define     ComMConf_ComMUser_ComMUser_Can_Network_0_PNC29        ((ComM_UserHandleType)(3)) /* Internal UserId : (3)*/


/*************************************************************************************/
/*                              Pnc Symbolic Names                                   */
/*************************************************************************************/

#define ComMConf_ComMPnc_ComMPnc  (0)




#endif  /* #ifndef  COMM_CFG_H  */
