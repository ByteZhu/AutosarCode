
#ifndef DCMDSPUDS_CC_PROT_H
#define DCMDSPUDS_CC_PROT_H

/**
 ***************************************************************************************************
            Communication Control service Protected Header
 ***************************************************************************************************
 */

/* Definitions of states of DSC service */
typedef enum
{
    DCM_DSP_CC_INITIAL  = 1,                          /* CC Initialization state         */
    DCM_DSP_CC_CHECKDATA,                             /* CC Service Check data           */
    DCM_DSP_CC_PROCESSSERVICE,                        /* Send Positive response state    */
    DCM_DSP_CC_ERROR                                  /* Send negative response state    */
}Dcm_CCStateType_ten;

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)&& (DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED != DCM_CFG_OFF))
extern void Dcm_Prv_DspCommCntrlConfirmation(uint8 sid_u8,
        uint8 reqType_u8,
        uint16 connectionId_u16,
        Dcm_ConfirmationStatusType confirmationStatus,
        Dcm_ProtocolType protocolType,
        uint16 testerSrcAddress_u16);







#endif
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif   /* DCMDSPUDS_CC_PROT_H */

