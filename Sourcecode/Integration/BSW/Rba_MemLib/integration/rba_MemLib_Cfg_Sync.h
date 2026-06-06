/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */





#ifndef RBA_MEMLIB_CFG_SYNC_H
#define RBA_MEMLIB_CFG_SYNC_H

/**
 **********************************************************************************************************************
 * \file   rba_MemLib_Cfg_Sync.h
 * \brief  Integration code for access to memory-pipeline synchronization (details in Module Docu)
 * \par    none
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
/* Include if available */
#include "rba_BswSrv.h"


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */

/* To be defined by the integrator
 * *******************************
 * CPU and compiler dependent write memory barrier used to ensure that previous writes
 * are performed before this instruction.
 * Typically this is an instruction which is provided by intrinsic functions of the compiler
 * or some special service functions.
 * Note if no multi-core is used, then this macro can be defined "empty".
 */
#define RBA_MEMLIB_MSYNC()     RBA_BSWSRV_MSYNC()



#endif
