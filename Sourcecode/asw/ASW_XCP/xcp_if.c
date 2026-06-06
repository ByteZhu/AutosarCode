
/*****************************************************************************
| Project Name:   XCP on CAN demo for Infineon Tricore TC17x7
|    File Name:   
|
|  Description:  
|             XCP Slave with 500 Kbit/s, DTO-Id 0x200, CRO-Id 0x201
|             No Seed&Key
|             Dynamic DAQ lists
|             Events:
|               ADC_TASK 0 10ms
|               BACKGROUND_TASK 1 100ms
|             Calibration Concept
|               Transparent. On demand OVRAM overlay creation
|               8 Kbyte OVRAM, 16*512 Bytes overlay segments
|               BUILD_CHECKSUM, SET/GET_CAL_PAGE and COPY_CAL_PAGE supported
|
|-----------------------------------------------------------------------------
|               D E M O
|-----------------------------------------------------------------------------
|
|       Please note, that the demo and example programs 
|       only show special aspects of the software. 
|       With regard to the fact that these programs are meant 
|       for demonstration purposes only,
|       Vector Informatik's liability shall be expressly excluded in cases 
|       of ordinary negligence, to the extent admissible by law or statute.
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2010 by Vector Informatik GmbH.           All rights reserved.
|
|       This software is copyright protected and 
|       proporietary to Vector Informatik GmbH.
|       Vector Informatik GmbH grants to you only
|       those rights as set out in the license conditions.
|       All other rights remain with Vector Informatik GmbH.
| 
|       Diese Software ist urheberrechtlich geschuetzt. 
|       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
|       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
|       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|***************************************************************************/


#include "common.h"
#include "Ifx_reg.h"
#include "project.h"
#include <xcpBasic_User.h>
//------------------------------------------------------------------------------
// Slave device id

#if defined ( kXcpStationIdLength )
  V_MEMROM0 MEMORY_ROM vuint8 kXcpStationId[kXcpStationIdLength] = kXcpStationIdString;
#endif


extern uint8 ComXcp_Data[];
extern uint8 EtcToPscmDevelFr_UpdateFlag;
extern void MCan_Transmit03(uint8 *data);
//------------------------------------------------------------------------------
// Transport Layer


// Receive 
// Handle transmission done
void XcpHandler( void ) {

  // Check if the transmit has been done 
//  if (CAN_NSR0.B.TXOK > 0)//(CAN_ubRequestMsgObj())//TODO ÉÆºó´¦Àí
//  {
//	  CAN_NSR0.B.TXOK = 0;
    XcpSendCallBack();
//  }

  // Receive id 0x201
  if(EtcToPscmDevelFr_UpdateFlag == 0xAA) {
  	  //glbMainCAL_data = EtcToPscmDevelFr_UpdateFlag;
  	EtcToPscmDevelFr_UpdateFlag = 0x00;
	  XcpCommand((void*)&(ComXcp_Data[0]));
  }
}


// Transmit
void ApplXcpSend( uint8 len, MEMORY_ROM BYTEPTR msg ) {
     
     vuint8 i = 0;
  // Transmit id 0x200
     uint8 data[8] = {0,};
     if(len > 8)
     {
    	 len = 8;
     }
	for(i = 0;i < len;i++)
	{
		data[i] = msg[i];
	}
	for(i = len;i < 8;i++)
	{
		data[i] = 0;
	}
	MCan_Transmit03(data);

          
}


uint8 ApplXcpSendStall( void ) {

#define XCP_MAILBOX   3
	uint8 ret = 0;
  if((CAN0_TXBTO1.U &  (0x0001<< XCP_MAILBOX))> 0)
  {
	  ret = 1;
	  XcpSendCallBack();
  }

  return ret;
#undef XCP_MAILBOX
}



//------------------------------------------------------------------------------
// Platform dependend functions

// Convert a XCP address to a pointer
MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr ) {

  //addr_ext = addr_ext;
  return (MTABYTEPTR)addr;
}





/*----------------------------------------------------------------------------*/
/* Flash Programming by Flash Kernel */
#if defined ( XCP_ENABLE_BOOTLOADER_DOWNLOAD )

// Prepare flash programming bootloader download
// From PROGRAM_PREPARE
vuint8 ApplXcpDisableNormalOperation( MTABYTEPTR a, vuint16 s )
{
//  xcp.BootloaderStartAddr = (vuint32)a;
//
//  // Check if size and address for bootloader download area
//  // are not in conflict with anything else
//  if (!(xcp.BootloaderStartAddr+s-1<(vuint32)&xcp || xcp.BootloaderStartAddr>(vuint32)&xcp+sizeof(xcp)-1)) {
//    return 0; // Access denied
//  }

  return 1;
}


// Start XCP/CCP flash programming bootloader
// From PROGRAM_START
vuint8 ApplXcpStartBootLoader( MTABYTEPTR a ) {

  typedef void (*xcpBootLoader_t)(void);

  ((xcpBootLoader_t)a)();
 
  return 0;
}


#endif
