
#ifndef DCMDSPUDS_DDDI_INF_H
#define DCMDSPUDS_DDDI_INF_H

/*
 ***************************************************************************************************
 * Public Includes
 ***************************************************************************************************
 */

#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
/*
 ***************************************************************************************************
 * Protected Includes (package wide includes)
 ***************************************************************************************************
 */


#include "DcmDspUds_Uds_Prot.h"
#if (DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Rdbi_Prot.h"
#endif
#include "DcmDspUds_Dddi_Prot.h"

#include "Dcm_Cfg_SchM.h"
#endif


/*
 ***************************************************************************************************
 * Other Inline Functions
 ***************************************************************************************************
 */


/* _DCMDSPUDS_DDDI_INF_H                                                                          */
#endif

