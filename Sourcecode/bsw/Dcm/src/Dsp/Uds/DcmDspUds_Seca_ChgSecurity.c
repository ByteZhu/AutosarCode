#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
#if(DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)
#include "Rte_Dcm.h"
#include "DcmDspUds_Seca_Inf.h"
#include "Dcm_Prv.h"
#include "DcmDspUds_Seca_Prv.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 *******************************************************************************
 * Dcm_Prv_DspSecurityConfirmation : API used for confirmation of response sent
 *                                              for SecurityAccess (0x27) service.
 * \param           dataIdContext_u8      Service Id
 * \param           dataRxPduId_u8        PDU Id on which request is Received
 * \param           dataSourceAddress_u16 Tester Source address id
 * \param           status_u8                Status of Tx confirmation function
 *
 * \retval          None
 * \seealso
 *
 *******************************************************************************
 */
void Dcm_Prv_DspSecurityConfirmation(uint8 sid_u8,
        uint8 reqType_u8,
        uint16 connectionId_u16,
        Dcm_ConfirmationStatusType confirmationStatus,
        Dcm_ProtocolType protocolType,
        uint16 testerSrcAddress_u16)
{
    uint8 dataSecLevel_u8;

    /* The security level requested is activated for positive as well as negative
   confirmations of a positive response.This is to avoid a situation of
   instability if the Application has already prepared for a change in
   security,but the Tx confirmation of response to tester is negative*/
    /* Check if POS response sent successfully and Dcm_DspChgSecLevelis set to
   TRUE */
    if (((confirmationStatus == DCM_RES_POS_OK) || (confirmationStatus == DCM_RES_POS_NOT_OK))
            && (Dcm_DspChgSecLevel_b != FALSE))
    {
        /* Calculate the security level */
        dataSecLevel_u8 = (uint8)((Dcm_DspSecAccType_u8 + 1u)>>1u);

        /* Unlock security level */
        Dcm_Prv_SetSecurityLevel (dataSecLevel_u8);
        /* Resetting Stored AccessType */
        Dcm_DspSecAccType_u8 = 0x0;
        /* Resetting Security Index */
        Dcm_DspSecTabIdx_u8  = 0x0;
    }
#if(DCM_CFG_DSP_SECA_STORESEED != DCM_CFG_OFF)
    if ((confirmationStatus == DCM_RES_POS_NOT_OK)
                                            && (Dcm_DspChgSecLevel_b == FALSE))
    {
        Dcm_Dsp_SecaClearSeed();
    }
#endif
    /* Resetting Change Security */

    Dcm_DspChgSecLevel_b   = FALSE;

    DcmAppl_DcmConfirmation(sid_u8,reqType_u8,connectionId_u16,confirmationStatus,protocolType,testerSrcAddress_u16);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif
#endif

