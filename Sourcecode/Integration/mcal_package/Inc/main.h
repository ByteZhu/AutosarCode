/*
 * main.h
 *
 *  Created on: Aug 15, 2017
 */

#ifndef MAIN_H
#define MAIN_H

/* Global variables */
#define BSW_START_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"
extern uint32 OS_Counter_1ms;
#define BSW_STOP_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"

#define STARTUP_START_SEC_CODE
#include "MemMap.h"
extern void TargetEn_PeriodicInterrupt(void);
#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* MAIN_H */
