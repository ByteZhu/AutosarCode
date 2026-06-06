
#ifndef DCMDSPUDS_UDS_INF_H
#define DCMDSPUDS_UDS_INF_H


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

#if (DCM_CFG_DSP_ECURESET_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Er_Prot.h"
#endif

#if (DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_CC_Prot.h"
#endif

#if (DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Rdbi_Prot.h"
#endif

#if (DCM_CFG_DSP_REQUESTUPLOAD_ENABLED!=DCM_CFG_OFF)
#include "DcmDspUds_Memaddress_Calc_Prot.h"
#endif

#include "Dcm_Cfg_SchM.h"

/*
 ***************************************************************************************************
 * Other Inline Functions
 ***************************************************************************************************
 */

#endif
/* _DCMDSPUDS_UDS_INF_H                                                                          */
#endif
