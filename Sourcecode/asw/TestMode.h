/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of MDL Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   MDL Technologies.
************************************************************************************************
*   File Name       : TESTMODE.h
************************************************************************************************
*   Project/Product : EPS Project
*   Title           : Standard Define 
*   Author          : QUN
************************************************************************************************
*   Description     : TESTMODE Module header file
*
************************************************************************************************
*   Limitations     : NONE
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version       Date         Initials     CR#           Descriptions
*   ---------   -----------  ------------  ----------  ---------------
*    0.1          31/01/12     QUN       N/A           Original
*
************************************************************************************************
*   END_FILE_HDR*/
#ifndef TESTMODE_H
#define TESTMODE_H

#include  "common.h"
//#include  "ssd_c90fl.h"

#ifdef 	TESTMODE_C
#define	TESTMODE_EXT 
#else
#define	TESTMODE_EXT extern
#endif

#define TESTMODE_SEGMENt_DEF    0
#define T212L_TESTMODE    1

#if TESTMODE_SEGMENt_DEF
#pragma push
#pragma force_active on
#pragma section const_type ".product_info" 
#endif
extern const MDLINT32U  glbProductInfo[16];
#if TESTMODE_SEGMENt_DEF
#pragma force_active off
#pragma pop
#endif

/*
#pragma push
#pragma force_active on
#pragma section sconst_type ".rom_checksum" 
extern const MDLINT32U initROM_CheckSum ;
#pragma force_active off

#pragma pop
*/
#define  CALI_PARA_NUM 				(MDLINT8U)8
#define  ANG0_PARA_NUM 				(MDLINT8U)4
#define EEPROM_INIT_MAXCCRA   (MDLINT16S)800//10deg


#define TESTMODE_CurrentLoopFlag 					0x7F3Du
#define TESTMODE_SpeedLoopFlag 		    	        0x9B2Cu
#define TESTMODE_OpenLoopFlag    					0x6B5Au
#define TESTMODE_ZeroLoopFlag    					0x0001u
#define TESTMODE_FCTsLoopFlag    			        0x3180u

#define TM_COMMUCATION_CHECK_CMD 					 0x0000u
#define TM_SELF_CHENK_CMD 							 0x0100u
#define TM_PSL_EE_9V 								 0x0200u
#define TM_PSL_EE_18V 					        	 0x0201u
#define TM_MAIN_RELAY_CMD 							 0x0300u
#define TM_PREDRIVER_CMD 							 0x0301u
#define TM_NORMAL_VOLTAGE_TORQUE_CMD 				 0x0400u
#define TM_LOW_VOLTAGE_TORQUE_CMD 					 0x0401u
#define TM_HIGH_VOLTAGE_TORQUE_CMD 				 	 0x0402u
#define TM_TEST_VOLTAGE_TORQUE_CMD                   0x04AAu
#define TM_MTR_CALMID_CMD 							 0x0500u
#define TM_MTR_CALAMP1_CMD 							 0x0501u
#define TM_MTR_CALAMP2_CMD 							 0x0502u
#define TM_MTR_WRITEVAL_CMD 					   	 0x0503u
#define TM_MTR_OPENLOOP_RUN_CMD 			         0x0504u
#define TM_RESOLVER_TEMPERATURE_CMD 				 0x0600u
#define TM_RESOLVER_INITANGLE_CMD 				 	 0x0601u
#define TM_MTR_CLOSELOOP_NrmPos_CMD 			     0x0700u
#define TM_MTR_CLOSELOOP_NrmNeg_CMD 	 			 0x0701u
#define TM_MTR_CLOSELOOP_LowPos_CMD   				 0x0702u
#define TM_MTR_CLOSELOOP_HghNeg_CMD					 0x0703u
#define TM_MTR_CLOSELOOP_SPEED_CMD					 0x0602u

#define TM_POWER_LATCH_CMD 						 	 0x0800u
#define TM_PRODUCT_INFORMATION_WAIT_CMD			     0x0900u

#define TM_FCT_INPUTOUTPUT_A_CMD					 0x0A00u	
#define TM_FCT_INPUTOUTPUT_N_CMD					 0x0B00u	
/* �����ϻ��������������2022.03.02 By TDJ */
#define TM_AGING_TEST_CHECK_CMD                      0x0C00u
#define TM_CALIB_DATA_CHECK_CMD                      0x0E00u
#define COMM_EEPR_AVAL_FLAG                          0x55u

#define SECURITY_FLASH_ADDR                          0x00203DE0ul
#define FLASH_SECURITY_KEY                           0x55AA1234ul
#define FLASH_UNSECURITY_KEY                         0x55AA55AAul

#define FLASH_JUMPFLAG_ADDR             			 0x00008000ul
#define FLASH_JUMPFLAG_VAL              			 0x55555555ul

TESTMODE_EXT void TESTmodeFun(void);
TESTMODE_EXT void TM_AssemblyTorqueFeedback(MDLINT8U enabled);

#endif /*#ifdef _COMMON_H_*/
