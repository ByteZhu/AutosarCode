// ----------------------------------------------------------------------------
//! \file
//! \brief Common Exclusive Area Handling
//!
//! $Source: Config/SchM/SchM_Default.h $
//! $Author: HZN4SGH $
//! $Revision: 51374 $
//! $Date: 2023-05-04 22:34:05 +0800 (Thu, 04 May 2023) $
//!
//! To ease Configuring Exclusive Area Handling the component specific handling
//! is mapped to a common handling. Only in case if a component specific
//! handling is required the component specific file "SchM_<MSN>.h" has to be
//! adapted.
//! Design specification: AUTOSAR_SWS_BSW_Scheduler.pdf Version 3.1 Rev0001
// ----------------------------------------------------------------------------



#ifndef SCHM_DEFAULT_H
#define SCHM_DEFAULT_H

#include "Os.h"
//#include "SchM.h"
#include "Compiler.h"

// ---- Includes --------------------------------------------------------------

#define SCHM_ENTER_DEFAULT()    SuspendAllInterrupts()

#define SCHM_EXIT_DEFAULT()     ResumeAllInterrupts()


#endif /* SCHM_DEFAULT_H */

// -------- END OF FILE -------------------------------------------------------
