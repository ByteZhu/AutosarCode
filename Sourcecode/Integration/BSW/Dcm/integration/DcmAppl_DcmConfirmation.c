/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */


#include "Dcm_Cfg_Prot.h"
//#include "DcmCore_DslDsd_Inf.h"
#include "Dcm.h"
#include "Rte_Dcm.h"

#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)
#include "rba_DiagAdapt.h"
#endif



#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 * @ingroup DCM_TPL
 * DcmAppl_DcmConfirmation :-\n
 *  This function confirms the successful transmission or a transmission error of a diagnostic service.This is the right time to perform any application state transitions.\n
 *  The idContext and the dcmRxPduId are required to identify the message which was processed.This information can be used to figure out the relation to any data provided by the application.\n
 *  This function is only called if processing of the service itself was done within the application.Based on the "status" integrator can perform required actions.\n
 *
 *
 * @param[in]     idContext    : Current context identifier which can be used to retrieve the relation between request and confirmation.Within the confirmation, the Dcm_MsgContext\n
 *                                is no more available, so the idContext can be used to represent this relation.
 *
 * @param[in]     dcmRxPduId   : DcmRxPduId on which the request was received. The source of the request can have  consequences for message processing.The idContext is also part of the Dcm_MsgContext.\n
 *
 * @param[in]     SourceAddress : Tester source address\n
 * @param[in]     status        : Status indication about confirmation (differentiate failure indication and normal confirmation) / The parameter "Result" of "Dcm_TpTxConfirmation" shall be forwarded\n
 *                                 to status depending if a positive or negative responses was sent before.
 *
 * @param[out]    None
 * @retval        None
 *
 */
void DcmAppl_DcmConfirmation (uint8 SID, uint8 ReqType,uint16 ConnectionId,Dcm_ConfirmationStatusType ConfirmationStatus,
                              Dcm_ProtocolType ProtocolType,uint16 TesterSourceAddress)
{


    /* BSWEXT-470 */
#if ((DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF) || (RBA_DCMPMA_CFG_PLANTMODEACTIVATION_ENABLED != DCM_CFG_OFF))
#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)
    rba_DiagAdapt_Confirmation(ReqType, ConnectionId, ConfirmationStatus);
    (void)(TesterSourceAddress);
#endif
#if(RBA_DCMPMA_CFG_PLANTMODEACTIVATION_ENABLED != DCM_CFG_OFF)
    if (SID == RBA_DCMPMA_SID_PLANTMODEACTIVATION)
    {
        if((ConfirmationStatus == DCM_RES_POS_OK) && (rba_DcmPma_PlantModeActivation_en == RBA_DCMPMA_PLANTMODE_INIT2))
        {
            /* switch to plant mode*/

            rba_DcmPma_PlantModeActivation (TRUE);
        }
    }
 //   (void)dcmRxPduId;
 //   (void)SourceAddress;
#endif
#else
    /* dummy code to remove compiler warning. Actual code to be written by User */
//    (void)(SID);
    (void)(ReqType);
//    (void)(ConnectionId);
//    (void)(ConfirmationStatus);
    (void)(ProtocolType);
//    (void)(TesterSourceAddress);
	/*TESTCODE-START
	DcmTest_DcmAppl_DcmConfirmation(SID, ReqType,ConnectionId, ConfirmationStatus,ProtocolType,TesterSourceAddress);
	TESTCODE-END*/
    /* END BSWEXT-470 */
#endif
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

