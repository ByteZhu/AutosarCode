
/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "CanNm_Inl.h"

/**************************************************************************************************/
/* Global functions (declared in header files )                                                   */
/**************************************************************************************************/
/***************************************************************************************************
 Function name    : CanNm_TriggerTransmit
 Description      : Within this API, the upper layer module (called module) shall check whether
                    the available data fits into the buffer size reported by PduInfoPtr->SduLength.
                    If it fits, it shall copy its data into the buffer provided by
                    PduInfoPtr->SduDataPtr and update the length of the actual copied data in
                    PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
 Parameter        : TxPduId - ID of the SDU that is requested to be transmitted.
                  : PduInfoPtr   - Contains a pointer to a buffer (SduDataPtr) to where the SDU data
                    shall be copied, and the available buffer size in SduLengh. On return,
                    the service will indicate the length of the copied SDU data in SduLength.
 Return value     : E_OK     - SDU has been copied and SduLength indicates the number of copied bytes.
                  : E_NOT_OK - No SDU data has been copied. PduInfoPtr must not be used since
                                it may contain a NULL pointer or point to invalid data.
 ***************************************************************************************************/
#define CANNM_START_SEC_CODE
#include "CanNm_MemMap.h"

Std_ReturnType CanNm_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr)
{

    /* Pointer to local Tx buffer */
    uint8 * TxBufferPtr;

    /* Pointer to channel configuration data */
    const CanNm_ChannelConfigType * ConfigPtr_pcs;

    /* Pointer to RAM data */
    CanNm_RamType * RamPtr_ps;

#if(CANNM_USER_DATA_ENABLED == STD_ON)
    /* Pointer to user data */
    uint8 * UserDataPtr;

    /* Index of the User bytes in Tx buffer */
    uint8_least UserDataOffset;
#endif

#if (CANNM_COM_USER_DATA_SUPPORT != STD_OFF)
    /*Local buffer to fetch data from Com */
    uint8  TxDataBuffer_au8[CANNM_PDU_LENGTH_MAX];
    /* Pointer to local buffer */
   uint8 * TxDataBuffer_pu8;
#endif

    /* Variable to hold PduInfo */
#if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
     PduInfoType PduInfo_s;
#endif

    /* Return value of the API */
    Std_ReturnType RetVal_en;

#if(CANNM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED != STD_OFF)
	/* Loop variable*/
	uint8 index_u8;
#endif
    /**** End Of Declarations ****/

#if (CANNM_CONFIGURATION_VARIANT == CANNM_VARIANT_POSTBUILD_SELECTABLE)
    TxPduId = CanNm_GlobalConfigData_pcs->Channel_Mapping_Table[TxPduId];
#endif

    /********************************* Start: DET *************************************/
    /* Report DET if TxPduId is Invalid */
    CANNM_DET_REPORT_ERROR_NOK((TxPduId >= CANNM_NUMBER_OF_CHANNELS_CONFIGURED()),
                            (uint8)TxPduId, CANNM_SID_TRIGGERTRANSMIT, CANNM_E_INVALID_PDUID)

    /* Report DET if CANNM is uninitialized */
    CANNM_DET_REPORT_ERROR_NOK((CanNm_RamData_s[TxPduId].State_en == NM_STATE_UNINIT),
                            (uint8)TxPduId, CANNM_SID_TRIGGERTRANSMIT, CANNM_E_NO_INIT)

    /* Report DET if received pointer is a null pointer*/
    CANNM_DET_REPORT_ERROR_NOK((PduInfoPtr == NULL_PTR),
                            (uint8)TxPduId, CANNM_SID_TRIGGERTRANSMIT, CANNM_E_PARAM_POINTER)

   /*********************************  End: DET  *************************************/

    /* Initialize pointer to configuration structure */
    ConfigPtr_pcs = CANNM_GET_CHANNEL_CONFIG(TxPduId);

    /* Initialize pointer to RAM structure */
    RamPtr_ps = &CanNm_RamData_s[TxPduId];

    /* Initialize the return value of the API */
    RetVal_en = E_NOT_OK;

	    /* Get the userdata offset value to know from where data needs to be copy */
#if(CANNM_USER_DATA_ENABLED == STD_ON)
        UserDataOffset = ConfigPtr_pcs->PduLength_u8 - ConfigPtr_pcs->UserDataLength_u8;
        UserDataPtr = &(RamPtr_ps->UserDataBuffer_au8[0]);
#endif

    /* Check the Pdulength is less than or equal to sdulength provided by CanIf */
    if(ConfigPtr_pcs->PduLength_u8 <= PduInfoPtr->SduLength)
    {
        /* Get the user data bytes if COM User data is enabled */
#if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
	    PduInfo_s.SduDataPtr = TxDataBuffer_au8;
        PduInfo_s.SduLength  = ConfigPtr_pcs->PduLength_u8;
        (void)PduR_CanNmTriggerTransmit(ConfigPtr_pcs->PduRId,&PduInfo_s);


#if(CANNM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED != STD_OFF)
		/* Update CBV and user data for sending shutdown message */
        if((ConfigPtr_pcs->SyncPncShutdownEnabled_b != FALSE) && (RamPtr_ps->SynPncShutDown_Req_State_b != FALSE))
		{
			/* TRACE[SWS_CanNm_00469] : Update PNSR bit to 1 */
            RamPtr_ps->TxCtrlBitVector_u8 = (RamPtr_ps->TxCtrlBitVector_u8 | CANNM_PNC_SHUTDOWN_REQ_IND_MSK);

			/* TRACE[SWS_CanNm_00469] : Overwrite the PN information in the NM User data that has been fetched, by setting bits that corresponds to PNC IDs
				   stored as pending request for a synchronized PNC shutdown to 1 and all other bits to 0 */

            /* Enter Critical Section */
            SchM_Enter_CanNm_TriggerTransmitNoNest();

			for(index_u8 = 0u; index_u8< CANNM_PN_INFOLENGTH; index_u8++)
			{
				TxDataBuffer_au8[index_u8 + CANNM_PN_INFO_OFFSET] = CanNm_PnSynShutDownReq_au8[ConfigPtr_pcs->NetworkHandle][index_u8];
			}

            /* Enter Critical Section */
            SchM_Exit_CanNm_TriggerTransmitNoNest();
		}
#endif

	    /* Pointer to position where user data is present */
		TxDataBuffer_pu8 = &TxDataBuffer_au8[UserDataOffset];

		/* Copy user data received from Com to UserDataBuffer */
        CanNm_CopyBuffer(TxDataBuffer_pu8,RamPtr_ps->UserDataBuffer_au8,ConfigPtr_pcs->UserDataLength_u8);

#endif

        /* Check if CBV is configured */
        if(ConfigPtr_pcs->ControlBitVectorPos_u8 != CANNM_PDU_OFF)
        {
            /* Initialize the local TxBuffer */
            TxBufferPtr = &(RamPtr_ps->TxBuffer_au8[0]);

            /* Store the Control bit vector to be transmitted in the TxBuffer */
            TxBufferPtr[ConfigPtr_pcs->ControlBitVectorPos_u8] = RamPtr_ps->TxCtrlBitVector_u8 ;
        }
#if(CANNM_USER_DATA_ENABLED == STD_ON)
       /* Initialize the local TxBuffer */
       TxBufferPtr = &(RamPtr_ps->TxBuffer_au8[UserDataOffset]);

       /* This is an internal function with predictable run-time; hence doesn't affect interrupt lock */
       CanNm_CopyBuffer(UserDataPtr,TxBufferPtr,ConfigPtr_pcs->UserDataLength_u8);

       /* If data fits into the given buffer size then provide the copied data and length of the Pdu */
       PduInfoPtr->SduDataPtr = &RamPtr_ps->TxBuffer_au8[0];
       PduInfoPtr->SduLength  = ConfigPtr_pcs->PduLength_u8;

       /* Return value is E_OK */
       RetVal_en = E_OK;
#endif

    }
       /* Return value */
       return RetVal_en;
}

#define CANNM_STOP_SEC_CODE
#include "CanNm_MemMap.h"


