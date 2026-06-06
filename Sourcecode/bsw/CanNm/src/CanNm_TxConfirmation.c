/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanNm_Prv.h"

/**************************************************************************************************/
/* Global functions (declared in header files )                                                   */
/**************************************************************************************************/
/***************************************************************************************************
 Function name    : CanNm_TxConfirmation
 Description      : This is the AUTOSAR interface to notify confirmation of a tranmsitted NM message over CAN.
                    This function is called by the CanIf after a CAN NM I-PDU has been transmitted
 param            : TxPduId - Identification of the NM-channel
 Return value     : None
 ***************************************************************************************************/

/* CanNm_TxConfirmation is available only if CANNM_IMMEDIATE_TXCONF_ENABLED is set to FALSE */
#define CANNM_START_SEC_CODE
#include "CanNm_MemMap.h"
void CanNm_TxConfirmation( PduIdType TxPduId, Std_ReturnType result)
{
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF))

    #if (CANNM_COM_USER_DATA_SUPPORT != STD_OFF)
    /* pointer to configuration data */
    const CanNm_ChannelConfigType * ConfigPtr_pcs;
    #endif

    /* Pointer to RAM data */
    CanNm_RamType * RamPtr_ps;

#if(CANNM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED == STD_ON)
	/* Loop variable*/
    uint8 index_u8;
#endif

    /**** End Of Declarations ****/

#if (CANNM_CONFIGURATION_VARIANT == CANNM_VARIANT_POSTBUILD_SELECTABLE)
    TxPduId = CanNm_GlobalConfigData_pcs->Channel_Mapping_Table[TxPduId];
#endif

    /********************************* Start: DET *************************************/

    /* Report DET if TxPduId is Invalid */
    CANNM_DET_REPORT_ERROR((TxPduId >= CANNM_NUMBER_OF_CHANNELS_CONFIGURED()),
                            (uint8)TxPduId, CANNM_SID_TXCONFIRMATION, CANNM_E_INVALID_PDUID)

    /* Report DET if CANNM is Uninitialized */
    CANNM_DET_REPORT_ERROR((CanNm_RamData_s[TxPduId].State_en == NM_STATE_UNINIT),
                            (uint8)TxPduId, CANNM_SID_TXCONFIRMATION, CANNM_E_NO_INIT)

    /*********************************  End: DET  *************************************/

    #if (CANNM_COM_USER_DATA_SUPPORT != STD_OFF)
    /* Initialize pointer to configuration structure */
    ConfigPtr_pcs = CANNM_GET_CHANNEL_CONFIG(TxPduId);
    #endif

    /* Initialize pointer to RAM structure */
    RamPtr_ps = &CanNm_RamData_s[TxPduId];

    /* Start timeout timer if transmission has not stopped */
    if(RamPtr_ps->MsgTxStatus_b != FALSE)
    {
        RamPtr_ps->PrevMsgTimeoutTimestamp = RamPtr_ps->ctSwFrTimer;
    }

    /* Set the transmit confirmation status */
    RamPtr_ps->TxConfirmation_b = TRUE;

    /* Stop monitoring Msg timeout time after getting Tx confirmation */
    RamPtr_ps->TxTimeoutMonitoringActive_b = FALSE;

    #if (CANNM_COM_USER_DATA_SUPPORT != STD_OFF)
    PduR_CanNmTxConfirmation(ConfigPtr_pcs->PduRId,result);
    #endif

#if(CANNM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED == STD_ON)
	/* TRACE[SWS_CanNm_00464] : Reset the PNC shutdown request array once PNC shutdown message was transmitted successfully */
   	if(result == E_OK)
    {
   	    /* Enter Critical Section */
   	    SchM_Enter_CanNm_TxConfirmationNoNest();

		for(index_u8 = 0; index_u8 < CANNM_PN_INFOLENGTH; index_u8++)
		{
			CanNm_PnSynShutDownReq_au8[TxPduId][index_u8] = 0x00u;
		}

		/* Exit Critical Section */
		SchM_Exit_CanNm_TxConfirmationNoNest();

		/* Reset the PNSR bit after clearing the PN shutdown request array */
		RamPtr_ps->TxCtrlBitVector_u8 = (RamPtr_ps->TxCtrlBitVector_u8 & (~CANNM_PNC_SHUTDOWN_REQ_IND_MSK));

		/* Clear PNC shutdown request flag after successful transmission of PN shutdown message */
		RamPtr_ps->SynPncShutDown_Req_State_b = FALSE;
	}

	/* TRACE[SWS_CanNm_00465]: If Tx confirmation is E_NOT_OK, set a flag which is used in EIRA main function to reset the PNC shutdown request array */
	else if(result == E_NOT_OK)
	{
		/* Set a flag to indicate transmission of PDU was not successful */
		RamPtr_ps->TxConfirmationNOK_b = TRUE;
	}

	else
	{
	  	/* Do nothing */
	}
#endif

#else
    (void)TxPduId;
    (void)result;
#endif

    return;
}

#define CANNM_STOP_SEC_CODE
#include "CanNm_MemMap.h"



