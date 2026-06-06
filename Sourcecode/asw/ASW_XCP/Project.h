/*
 * Project.h
 *
 *  Created on: 2022-3-7
 *      Author: 17717
 */

#ifndef PROJECT_H_
#define PROJECT_H_

//#define XCP_CC_TC_OVRAM // Enable Tricore OVRAM calibration concept for XCP on CAN

#define VERSION 0x10
// Set the target type
// Please generate code for the associated .DAV file first (use TC1767.DAV for TC1387,TC1782)
// Set compiler project options to the correct microcontroller

// #define EASYKIT_TC1767 or TRIBOARD_TC1797 or TRIBOARD_TC1387	or TRIBOARD_TC1782
#define TRIBOARD_TC212X

// Only the TRIBOARD_TC1797 has external RAM
// Enable the external RAM on the TRIBOARD_TC1797 evaluation board at 0xD8000000
#ifdef TRIBOARD_TC1797
  #define EXTERNAL_RAM
#endif


extern void XcpHandler( void );

#endif /* PROJECT_H_ */
