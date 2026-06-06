
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
 Function name    : CanNm_RequestSynchronizedPncShutdown
 Description      : Requests transmission of a NM-PDU with PNSR bit set to 1 (PN shutdown message)
 Parameter        : nmChannelHandle - Identifier of the NM-Channel where the given PNC (pncId) is assigned to
                  : pncId -Identifier of the PNC which is requested for a synchronized shutdown across the PN topology
 Return value     : E_OK - Request has been accepted
                  : E_NOT_OK - Request has not been accepted
 ***************************************************************************************************/

/* TRACE[SWS_CanNm_00467] : The API is available only if CANNM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED is enabled */
#if(CANNM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED == STD_ON)

#define CANNM_START_SEC_CODE
#include "CanNm_MemMap.h"

Std_ReturnType CanNm_RequestSynchronizedPncShutdown( NetworkHandleType nmChannelHandle, PNCHandleType pncId)
{
	/* pointer to RAM data */
    CanNm_RamType * RamPtr_ps;

    /* Variable to hold the network handle of CanNm */
    NetworkHandleType CanNm_NetworkHandle;

    /* pointer to configuration data */
    const CanNm_ChannelConfigType * ConfigPtr_pcs;

    /* Return value of the API */
    Std_ReturnType RetVal_en;

	/* Variable to hold the calculated byte index of the PNC ID's requested for shutdown */
	uint8 PN_ByteIndex;

#if (CANNM_CONFIGURATION_VARIANT == CANNM_VARIANT_POSTBUILD_SELECTABLE)
    /* Local variable to hold index of the CanNm channel*/
    NetworkHandleType tempChannel;
#endif

    /**** End Of Declarations ****/

#if (CANNM_CONFIGURATION_VARIANT == CANNM_VARIANT_POSTBUILD_SELECTABLE)

    /* Receive CanNm channel index from the received ComM ChannelID */
    tempChannel = CANNM_GET_HANDLE(nmChannelHandle);

    /* Obtain index of the CanNm channel in the current variant */
    CanNm_NetworkHandle = CanNm_GlobalConfigData_pcs->Channel_Mapping_Table[tempChannel];

#else
    /* Receive CanNm channel index from the received ComM ChannelID */
    CanNm_NetworkHandle = CANNM_GET_HANDLE(nmChannelHandle);
#endif

    /* Initialize the return value*/
	RetVal_en = E_NOT_OK;

	/* Initialize the byte index variable */
	PN_ByteIndex = 0x00u;

    /********************************* Start: DET *************************************/

    /* Report DET if CANNM is uninitialized */
    CANNM_DET_REPORT_ERROR_NOK((CanNm_RamData_s[CanNm_NetworkHandle].State_en == NM_STATE_UNINIT),
                            nmChannelHandle, CANNM_SID_REQUESTSYNCHRONIZEDPNCSHUTDOWN, CANNM_E_NO_INIT)

    /* Report DET if network handle is invalid */
    CANNM_DET_REPORT_ERROR_NOK((CanNm_NetworkHandle >= CANNM_NUMBER_OF_CHANNELS_CONFIGURED()),
                            nmChannelHandle, CANNM_SID_REQUESTSYNCHRONIZEDPNCSHUTDOWN, CANNM_E_INVALID_CHANNEL)


    /*********************************  End: DET  *************************************/

    /* Initialise the pointer to configuration data structure of channel NetworkHandle */
    ConfigPtr_pcs = CANNM_GET_CHANNEL_CONFIG(CanNm_NetworkHandle);

    /* Initialize the pointer to RAM data structure */
    RamPtr_ps = &CanNm_RamData_s[CanNm_NetworkHandle];

	/* Check if Synchronised PNC shutdown feature is enabled for the channel */
    if(ConfigPtr_pcs->SyncPncShutdownEnabled_b == TRUE)
    {
		/* Calculate the byte index within PN info range */
		PN_ByteIndex = (uint8)pncId / 8u;

		if((PN_ByteIndex >= CANNM_PN_INFO_OFFSET) && (PN_ByteIndex < (CANNM_PN_INFOLENGTH + CANNM_PN_INFO_OFFSET)))
        {
	        PN_ByteIndex = PN_ByteIndex - CANNM_PN_INFO_OFFSET;

		    /* Enter Critical Section */
		    SchM_Enter_CanNm_RequestSynchronizedPncShutdownNoNest();

			/* TRACE[SWS_CanNm_00462]: Aggregate and store the PNC shutdown request */
			CanNm_PnSynShutDownReq_au8[CanNm_NetworkHandle][PN_ByteIndex] = (CanNm_PnSynShutDownReq_au8[CanNm_NetworkHandle][PN_ByteIndex] | (uint8)(1U<<(pncId % 8u)));

			/* Store pending Synchronized Pnc Shutdown request for that channel */
			RamPtr_ps->SynPncShutDown_Req_State_b = TRUE;

			/* Exit Critical Section */
			SchM_Exit_CanNm_RequestSynchronizedPncShutdownNoNest();

			/* Return successful operation */
			RetVal_en = E_OK;
		}
	}

    return(RetVal_en);
}

#define CANNM_STOP_SEC_CODE
#include "CanNm_MemMap.h"

#endif

