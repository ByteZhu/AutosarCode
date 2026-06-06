/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Name: 
 * Description:
 * Version: 1.0
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : PSCM_AUTOSAR_BSW12_V1.0
 * Component: /SwComponentTypes/CDD_FVM
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 12.0.1
 * Author: Administrator
 * Date : ���� 7�� 28 15:28:50 2024
 ****************************************************************************/

#include "Rte_CDD_FVM.h"
#include "CDD_FVM.h"
#include "Crypto_SW.h"
#include "string.h"
#include "Dcm.h"
#include "Com_Prv.h"
#include "Com_Prv_Inl.h"
#include "Com_Cbk.h"
#include "EepromData.h"
#include "IdsM.h"
#include "common.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :SecOC_GeTxFreshness) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :SecOC_GeTxFreshness) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :SecOC_GeTxFreshness) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */

/*Development according the Autosar SWS SecOC R23-11*/
/*global trip counter and reset counter struct*/
FVM_Sync_Cnt_tst FVM_Sync_cnt_st; 
/*received secoc message struct*/
FVM_Rx_Pdu_tst FVM_Rx_Pdu_ast[SECOC_NUMBER_RX_PDU];
/*send secoc message struct*/
FVM_Tx_Pdu_tst FVM_Tx_Pdu_ast[SECOC_NUMBER_AUTH_PDU];

static Std_ReturnType cmp_and_contruct_fv(uint8 i, comp_offset_type offset, uint16 message_counter, uint64* fv);
#define CDD_FVM_START_SEC_CODE                   
#include "CDD_FVM_MemMap.h"
/*AUTOSAR DOC: 11.4.4.1 Processing of Initialization*/
void SecOC_FVM_Init(void)
{
	PduIdType idx_cuo;
	uint16 valueID_u16;
	uint8 i;
	/*first start: override to pass,*/
	if(Nvm_Bsw_Data[SECOC_OVERRIDE_FLAG_OFFSET] == 0)
	{
		for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
		{
			//SecOC_VerifyStatusOverride(i, SECOC_OVERRIDE_TO_PASS, 0);
		}
	}
	else if(Nvm_Bsw_Data[SECOC_OVERRIDE_FLAG_OFFSET] == 1)
	{
		for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
		{
			//SecOC_VerifyStatusOverride(i, SECOC_OVERRIDE_CANCEL, 0);
		}
	}
	else
	{
		//NULL
	}
	/*Set all the previously sent values and previously received values to 0.*/
	for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
	{
		// idx_cuo = SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->freshnessValueId_cst.idx_cuo;
		// valueID_u16 = (*SecOC_Prv_RxAuthenticPduContext_ast[i].pduConfig_pst->freshnessValueId_cst.value_pacu16)[idx_cuo];
		// FVM_Rx_Pdu_ast[i].fvid = valueID_u16;
		// FVM_Rx_Pdu_ast[i].previous_sync_rstcnt = 0;
		// FVM_Rx_Pdu_ast[i].previous_sync_tripcnt = 0;
		// FVM_Rx_Pdu_ast[i].construct_sync_rstcnt = 0;
		// FVM_Rx_Pdu_ast[i].construct_sync_tripcnt = 0;
		// FVM_Rx_Pdu_ast[i].message_cnt = 0;
		// FVM_Rx_Pdu_ast[i].last_message_cnt = 0;
		// FVM_Rx_Pdu_ast[i].failed_cnt = 0;
		
	}
	for(i = 0; i < SECOC_NUMBER_AUTH_PDU; i++)
	{
		// FVM_Tx_Pdu_ast[i].fvid = SecOC_Prv_TxAuthenticPduContext_ast[i].pduConfig_pst->freshnessValueId_u16;
		// FVM_Tx_Pdu_ast[i].previous_sync_rstcnt = 0;
		// FVM_Tx_Pdu_ast[i].previous_sync_tripcnt = 0;
		// FVM_Tx_Pdu_ast[i].message_cnt = 0;
	}
	FVM_Sync_cnt_st.lasted_sync_rstcnt = 0;
	/*Obtain the trip counter value that is stored in the non-volatile memory, 
	and then set it to the latest value. */
	memcpy(&(FVM_Sync_cnt_st.lasted_sync_tripcnt), &Nvm_Bsw_Data[TRIP_COUNTER_OFFSET], TRIP_COUNTER_SIZE);
	
}



FUNC(Std_ReturnType, CDD_FVM_CODE) SecOC_GeTxFreshness
(
		VAR(uint16, AUTOMATIC) freshnessValueId,
		P2VAR(SecOC_FreshnessArrayType, AUTOMATIC, RTE_APPL_DATA) freshnessValue,
		P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) freshnessValueLength
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :SecOC_GeTxFreshness) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i;
	uint64 lasted_sync_cnt = 0;
	uint64 previous_sync_cnt = 0;
	uint64 contruct_fv = 0;
	uint8 rst_flag = 0;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	for(i = 0; i < SECOC_NUMBER_AUTH_PDU; i++)
	{
		if(FVM_Tx_Pdu_ast[i].fvid == freshnessValueId)
		{
			/*AUTOSAR DOC: 11.4.4.3*/
			/*Compare the latest values and previously sent values of the (Trip Counter | Reset Counter). 
			The "|" symbol means a connection.*/
			lasted_sync_cnt = FVM_SYNC_COUNTER_CONNECT(FVM_Sync_cnt_st.lasted_sync_tripcnt, FVM_Sync_cnt_st.lasted_sync_rstcnt);
			previous_sync_cnt = FVM_SYNC_COUNTER_CONNECT(FVM_Tx_Pdu_ast[i].previous_sync_tripcnt, FVM_Tx_Pdu_ast[i].previous_sync_rstcnt);
			if(lasted_sync_cnt == previous_sync_cnt)
			{
				/*At the maximum value of the reset counter The sender ECU generates an 
				authenticator by fixing the message counter to the maximum value. The 
				receiver ECU verifies the authenticator by overwriting the message counter 
				with the maximum value.*/
				if((FVM_Tx_Pdu_ast[i].message_cnt == 0x3FFF) || (FVM_Sync_cnt_st.lasted_sync_rstcnt == 0xFF))
				{
					FVM_Tx_Pdu_ast[i].message_cnt = 0x3FFF;
				}
				else
				{
					FVM_Tx_Pdu_ast[i].message_cnt++;
				}
				/*Table 8 - Construction of Freshness Value (FV) for Tx*/
				rst_flag = FVM_Tx_Pdu_ast[i].previous_sync_rstcnt & 0x03;
				contruct_fv = FVM_CONTRUCT_FV(FVM_Tx_Pdu_ast[i].previous_sync_tripcnt, FVM_Tx_Pdu_ast[i].previous_sync_rstcnt, FVM_Tx_Pdu_ast[i].message_cnt, rst_flag);
			}
			else
			{
				if((FVM_Sync_cnt_st.lasted_sync_rstcnt == 0xFF))
				{
					FVM_Tx_Pdu_ast[i].message_cnt = 0x3FFF;
				}
				else
				{
					FVM_Tx_Pdu_ast[i].message_cnt = 1;
				}
				/*Table 8 - Construction of Freshness Value (FV) for Tx*/
				rst_flag = FVM_Sync_cnt_st.lasted_sync_rstcnt & 0x03;
				contruct_fv = FVM_CONTRUCT_FV(FVM_Sync_cnt_st.lasted_sync_tripcnt, FVM_Sync_cnt_st.lasted_sync_rstcnt, FVM_Tx_Pdu_ast[i].message_cnt, rst_flag);
			}
			break;
		}
	}
	*freshnessValueLength = 56;
	contruct_fv = SWAP_U64(contruct_fv);
	contruct_fv >>= 8;
	memcpy(*freshnessValue, &contruct_fv, 7);
	
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :SecOC_GeTxFreshness) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

	return retValue;

}
#define CDD_FVM_STOP_SEC_CODE  
#include "CDD_FVM_MemMap.h" 
void Get_Trip_Reset_Counter_Clear_Acceptance_Store_Trip(uint16 sync_rstcnt, uint32 sync_tripcnt)
{
	uint8 i;
	/*At the maximum value of the trip counter If both Conditions 1 and 2 below are established, 
	the synchronization message is received and authenticator verification is performed. If the 
	verification result is OK, the latest values of the trip counter and reset counter are updated 
	with the received trip counter and reset counter values. In addition, the previously sent value 
	and previously received value of each counter are returned to the initial values.*/
	if((FVM_Sync_cnt_st.lasted_sync_tripcnt <= (0xFFFFFF)) && (FVM_Sync_cnt_st.lasted_sync_tripcnt >= (0xFFFFFC)))
	{
		if((sync_tripcnt >= 0) && (sync_tripcnt <= 3))
		{
			FVM_Sync_cnt_st.lasted_sync_rstcnt = sync_rstcnt;
			FVM_Sync_cnt_st.lasted_sync_tripcnt = sync_tripcnt;
			/*Even when the trip counter changes from the maximum value to the initial value (see clause 11.4.1.2), 
			it is treated as an increment and is stored in the non-volatile memory.*/
			memcpy(&Nvm_Bsw_Data[TRIP_COUNTER_OFFSET], &(FVM_Sync_cnt_st.lasted_sync_tripcnt), TRIP_COUNTER_SIZE);
			//NvmSecuredDataWrite(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE);
			for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
			{
				FVM_Rx_Pdu_ast[i].previous_sync_rstcnt = 0;
				FVM_Rx_Pdu_ast[i].previous_sync_tripcnt = 0;
				FVM_Rx_Pdu_ast[i].construct_sync_rstcnt = 0;
				FVM_Rx_Pdu_ast[i].construct_sync_tripcnt = 0;
				FVM_Rx_Pdu_ast[i].message_cnt = 0;
				FVM_Rx_Pdu_ast[i].last_message_cnt = 0;
			}
			for(i = 0; i < SECOC_NUMBER_AUTH_PDU; i++)
			{
				FVM_Tx_Pdu_ast[i].previous_sync_rstcnt = 0;
				FVM_Tx_Pdu_ast[i].previous_sync_tripcnt = 0;
				FVM_Tx_Pdu_ast[i].message_cnt = 0;
			}
		}
		else 
		{
			/*When the trip counter is incremented, the application stores the incremented 
			value to the non-volatile memory.*/
			if(FVM_Sync_cnt_st.lasted_sync_tripcnt < sync_tripcnt)
			{
				memcpy(&Nvm_Bsw_Data[TRIP_COUNTER_OFFSET], &(sync_tripcnt), TRIP_COUNTER_SIZE);
				//NvmSecuredDataWrite(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE);
				/*lasted trip counter update to received value*/
				FVM_Sync_cnt_st.lasted_sync_rstcnt = sync_rstcnt;
				FVM_Sync_cnt_st.lasted_sync_tripcnt = sync_tripcnt;
			}
			else if(FVM_Sync_cnt_st.lasted_sync_tripcnt == sync_tripcnt)
			{
				if(FVM_Sync_cnt_st.lasted_sync_rstcnt <= sync_rstcnt)
				{
					FVM_Sync_cnt_st.lasted_sync_rstcnt = sync_rstcnt;
				}
			}
			else
			{
				//NULL
			}
		}
	}
	else
	{
		/*When the trip counter is incremented, the application stores the incremented 
		value to the non-volatile memory.*/
		if(FVM_Sync_cnt_st.lasted_sync_tripcnt < sync_tripcnt)
		{
			memcpy(&Nvm_Bsw_Data[TRIP_COUNTER_OFFSET], &(sync_tripcnt), TRIP_COUNTER_SIZE);
			//NvmSecuredDataWrite(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE);
			/*lasted trip counter update to received value*/
			FVM_Sync_cnt_st.lasted_sync_rstcnt = sync_rstcnt;
			FVM_Sync_cnt_st.lasted_sync_tripcnt = sync_tripcnt;
		}
		else if(FVM_Sync_cnt_st.lasted_sync_tripcnt == sync_tripcnt)
		{
			if(FVM_Sync_cnt_st.lasted_sync_rstcnt <= sync_rstcnt)
			{
				FVM_Sync_cnt_st.lasted_sync_rstcnt = sync_rstcnt;
			}
		}
		else
		{
			//NULL
		}
	}
	
	
}

/*Table 9 - Construction of Freshness Value (FV) for Rx*/
static Std_ReturnType cmp_and_contruct_fv(uint8 i, comp_offset_type offset, uint16 message_counter, uint64* fv)
{
    Std_ReturnType retValue = RTE_E_OK;
	uint64 lasted_sync_cnt = 0;
	uint64 previous_sync_cnt = 0;
	uint16 rst_counter = 0;
	uint8 rst_flag = 0;
	/*Trip counter | reset counter*/
	lasted_sync_cnt = FVM_SYNC_COUNTER_CONNECT(FVM_Sync_cnt_st.lasted_sync_tripcnt, FVM_Sync_cnt_st.lasted_sync_rstcnt);
	previous_sync_cnt = FVM_SYNC_COUNTER_CONNECT(FVM_Rx_Pdu_ast[i].previous_sync_tripcnt, FVM_Rx_Pdu_ast[i].previous_sync_rstcnt);
	
	if(offset == no_offset)
	{
		rst_counter = FVM_Sync_cnt_st.lasted_sync_rstcnt;
	}
	else if(offset == add_one)
	{
		lasted_sync_cnt += 1;
		rst_counter = FVM_Sync_cnt_st.lasted_sync_rstcnt + 1;
	}
	else if(offset == add_two)
	{
		lasted_sync_cnt += 2;
		rst_counter = FVM_Sync_cnt_st.lasted_sync_rstcnt + 2;
	}
	else if(offset == minus_one)
	{
		lasted_sync_cnt -= 1;
		rst_counter = FVM_Sync_cnt_st.lasted_sync_rstcnt - 1;
	}
	else if(offset == minus_two)
	{
		lasted_sync_cnt -= 2;
		rst_counter = FVM_Sync_cnt_st.lasted_sync_rstcnt - 2;
	}
	/*Trip counter | reset counter comparison*/
	if(lasted_sync_cnt == previous_sync_cnt)
	{
		FVM_Rx_Pdu_ast[i].construct_sync_tripcnt = FVM_Rx_Pdu_ast[i].previous_sync_tripcnt;
		FVM_Rx_Pdu_ast[i].construct_sync_rstcnt = FVM_Rx_Pdu_ast[i].previous_sync_rstcnt;
		rst_flag = FVM_Rx_Pdu_ast[i].construct_sync_rstcnt & 0x03;
		if(message_counter > FVM_Rx_Pdu_ast[i].last_message_cnt)
		{
			/*AUTOSAR DOC: 11.4.4.4 Construction of Freshness Value for Reception*/
			FVM_Rx_Pdu_ast[i].message_cnt = message_counter;
			*fv = FVM_CONTRUCT_FV(FVM_Rx_Pdu_ast[i].construct_sync_tripcnt, FVM_Rx_Pdu_ast[i].construct_sync_rstcnt, FVM_Rx_Pdu_ast[i].message_cnt, rst_flag);
		}
		else
		{
			retValue = RTE_E_INVALID;
		}
	}
	else if(lasted_sync_cnt > previous_sync_cnt)
	{
		FVM_Rx_Pdu_ast[i].construct_sync_tripcnt = FVM_Sync_cnt_st.lasted_sync_tripcnt;
		FVM_Rx_Pdu_ast[i].construct_sync_rstcnt = rst_counter;
		rst_flag = FVM_Rx_Pdu_ast[i].construct_sync_rstcnt & 0x03;
		/*AUTOSAR DOC: 11.4.4.4 Construction of Freshness Value for Reception*/
		FVM_Rx_Pdu_ast[i].message_cnt = message_counter;
		*fv = FVM_CONTRUCT_FV(FVM_Rx_Pdu_ast[i].construct_sync_tripcnt, FVM_Rx_Pdu_ast[i].construct_sync_rstcnt, FVM_Rx_Pdu_ast[i].message_cnt, rst_flag);
	}
	else
	{
		retValue = RTE_E_INVALID;
	}
	
	
	return retValue;
}
#define CDD_FVM_START_SEC_CODE                   
#include "CDD_FVM_MemMap.h"
FUNC(Std_ReturnType, CDD_FVM_CODE) SecOC_GetRxFreshness
(
		VAR(uint16, AUTOMATIC) freshnessValueId,
		P2CONST(SecOC_FreshnessArrayType, AUTOMATIC, RTE_APPL_DATA) truncatedFreshnessValue,
		VAR(uint32, AUTOMATIC) truncatedFreshnessValueLength,
		VAR(uint16, AUTOMATIC) authVerifyAttempts,
		P2VAR(SecOC_FreshnessArrayType, AUTOMATIC, RTE_APPL_DATA) freshnessValue,
		P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) freshnessValueLength
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :SecOC_GetRxFreshness) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i;
	uint8 rst_flag;
	uint8 lasted_rst_flag;
	uint16 message_cnt;
	uint64 contruct_fv = 0;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
	{
		if(FVM_Rx_Pdu_ast[i].fvid == freshnessValueId)
		{
			FVM_Rx_Pdu_ast[i].authVerifyAttempts = authVerifyAttempts;
			if(freshnessValueId != 4)
			{
				lasted_rst_flag = FVM_Sync_cnt_st.lasted_sync_rstcnt & 0x03;
				rst_flag = (*truncatedFreshnessValue)[1] & 0x03;
				message_cnt = ((((uint16)((*truncatedFreshnessValue)[0])) << 6) | ((*truncatedFreshnessValue)[1]) >> 2);
				
				/*Reset flag comparison*/
				if(lasted_rst_flag == rst_flag)
				{
					retValue = cmp_and_contruct_fv(i, no_offset, message_cnt, &contruct_fv);
				}
				else if((lasted_rst_flag - 1) == rst_flag)
				{
					retValue = cmp_and_contruct_fv(i, minus_one, message_cnt, &contruct_fv);
				}
				else if((lasted_rst_flag + 1) == rst_flag)
				{
					retValue = cmp_and_contruct_fv(i, add_one, message_cnt, &contruct_fv);
				}
				else if((lasted_rst_flag - 2) == rst_flag)
				{
					retValue = cmp_and_contruct_fv(i, minus_two, message_cnt, &contruct_fv);
				}
				else if((lasted_rst_flag + 2) == rst_flag)
				{
					retValue = cmp_and_contruct_fv(i, add_two, message_cnt, &contruct_fv);
				}
				else
				{
					retValue = RTE_E_INVALID;
				}
				*freshnessValueLength = 56;
				contruct_fv = SWAP_U64(contruct_fv);
				contruct_fv >>= 8;
				memcpy(*freshnessValue, &contruct_fv, 7);
				
			}
			else
			{
				*freshnessValueLength = 0;
			}
			break;
		}
	}
	
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :SecOC_GetRxFreshness) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

	return retValue;

}
#define CDD_FVM_STOP_SEC_CODE  
#include "CDD_FVM_MemMap.h" 
#define CDD_FVM_START_SEC_CODE                   
#include "CDD_FVM_MemMap.h"
FUNC (Std_ReturnType, CDD_FVM_CODE) SecOC_SPduTxConfirmation/* return value & FctID */
(
		VAR(uint16, AUTOMATIC) freshnessValueId
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :SecOC_SPduTxConfirmation) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	for(i = 0; i < SECOC_NUMBER_AUTH_PDU; i++)
	{
		if(FVM_Tx_Pdu_ast[i].fvid == freshnessValueId)
		{
			/*When SecOC sends a transmission start notification, FVM maintains the constructed 
			freshness value for transmission (trip counter, reset counter, message counter) as 
			the previously sent value.*/
			FVM_Tx_Pdu_ast[i].previous_sync_tripcnt = FVM_Sync_cnt_st.lasted_sync_tripcnt;
			FVM_Tx_Pdu_ast[i].previous_sync_rstcnt = FVM_Sync_cnt_st.lasted_sync_rstcnt;
		}
	}
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :SecOC_SPduTxConfirmation) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

	return retValue;

}
#define CDD_FVM_STOP_SEC_CODE  
#include "CDD_FVM_MemMap.h" 
#define CDD_FVM_START_SEC_CODE                   
#include "CDD_FVM_MemMap.h"
FUNC (Std_ReturnType, CDD_FVM_CODE) SecOC_verificationStatus/* return value & FctID */
(
		P2VAR(SecOC_VerificationStatusType, AUTOMATIC, RTE_APPL_DATA) verificationStatus
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :SecOC_verificationStatus) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
	{
		if(FVM_Rx_Pdu_ast[i].fvid == verificationStatus->freshnessValueID)
		{
			if(verificationStatus->verificationStatus == SECOC_VERIFICATIONSUCCESS)
			{
				if(FVM_Rx_Pdu_ast[i].fvid == 0x04)
				{
					Can_secoc_pr = 0xAA;
				}

				/*When SecOC sends a notification of the verification result (verification = OK), 
				FVM maintains the constructed freshness value for verification as the previously received value.*/
				FVM_Rx_Pdu_ast[i].previous_sync_tripcnt = FVM_Rx_Pdu_ast[i].construct_sync_tripcnt;
				FVM_Rx_Pdu_ast[i].previous_sync_rstcnt = FVM_Rx_Pdu_ast[i].construct_sync_rstcnt;
				FVM_Rx_Pdu_ast[i].last_message_cnt = FVM_Rx_Pdu_ast[i].message_cnt;
			}
			else
			{

				if(verificationStatus->verificationStatus == SECOC_AUTHENTICATIONBUILDFAILURE)//add-lv
				{
					Ids_SetSecurityEvent(IDS_SECOC_FRESHVAL_VERIFY_FAIL);
				}
				if(FVM_Rx_Pdu_ast[i].authVerifyAttempts == 2)//pno 61
				{
					Ids_SetSecurityEvent(IDS_SECOC_PDUMAC_VERIFY_FAIL_MEDIUM);//small--ids-judge
					if(FVM_Rx_Pdu_ast[i].failed_cnt < 0xFF)
					{
						
						FVM_Rx_Pdu_ast[i].failed_cnt++;
						//Dem_SetEventStatus(DemEvent_D0C568, DEM_EVENT_STATUS_FAILED);
						
					}
					else
					{
						//NULL, Keep the max value
					}

				}
			}
		}
	}
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :SecOC_verificationStatus) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

	return retValue;

}
#define CDD_FVM_STOP_SEC_CODE  
#include "CDD_FVM_MemMap.h" 
Std_ReturnType FVM_Deal_31_B051(uint8  dataIn1, uint8 OpStatus, uint8 * dataOut1, uint8 * ErrorCode)
{
	Std_ReturnType retValue_t = E_OK;
	uint8 i;
	if(dataIn1 == 0x01)
	{
		for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
		{
			FVM_Rx_Pdu_ast[i].previous_sync_rstcnt = 0;
			FVM_Rx_Pdu_ast[i].previous_sync_tripcnt = 0;
			FVM_Rx_Pdu_ast[i].construct_sync_rstcnt = 0;
			FVM_Rx_Pdu_ast[i].construct_sync_tripcnt = 0;
			FVM_Rx_Pdu_ast[i].message_cnt = 0;
			FVM_Rx_Pdu_ast[i].last_message_cnt = 0;
			
		}
		for(i = 0; i < SECOC_NUMBER_AUTH_PDU; i++)
		{
			FVM_Tx_Pdu_ast[i].previous_sync_rstcnt = 0;
			FVM_Tx_Pdu_ast[i].previous_sync_tripcnt = 0;
			FVM_Tx_Pdu_ast[i].message_cnt = 0;
		}
		FVM_Sync_cnt_st.lasted_sync_rstcnt = 0;
		FVM_Sync_cnt_st.lasted_sync_tripcnt = 0;
		memcpy(&Nvm_Bsw_Data[TRIP_COUNTER_OFFSET], &(FVM_Sync_cnt_st.lasted_sync_tripcnt), TRIP_COUNTER_SIZE);
		//NvmSecuredDataWrite(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE);
		*dataOut1 = 0x01;
		*ErrorCode = E_OK;
	}
	else
	{
		*dataOut1 = 0x00;
		*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_REQUESTOUTOFRANGE;
		retValue_t = E_NOT_OK;
	}
	return retValue_t;
}

Std_ReturnType FVM_Deal_2E_E567(uint8* Data, uint8* ErrorCode)
{
	Std_ReturnType retValue_t = E_OK;
	*ErrorCode = E_OK;
	uint8 i;
	if(*Data == 0)
	{
		for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
		{
			//SecOC_VerifyStatusOverride(i, SECOC_OVERRIDE_TO_PASS, 0);
			Nvm_Bsw_Data[SECOC_OVERRIDE_FLAG_OFFSET] = 0;
		}
		//NvmSecuredDataWrite(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE);
	}
	else if(*Data == 1)
	{
		for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
		{
			//SecOC_VerifyStatusOverride(i, SECOC_OVERRIDE_CANCEL, 0);
			Nvm_Bsw_Data[SECOC_OVERRIDE_FLAG_OFFSET] = 1;
		}
		//NvmSecuredDataWrite(Nvm_Bsw_Data, BSW_FEE_BLOCK_SIZE);
	}
	else
	{
		*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_REQUESTOUTOFRANGE;
		retValue_t = E_NOT_OK;
	}
	return retValue_t;
}

Std_ReturnType FVM_Deal_22_E554(uint8* data)
{
	Std_ReturnType retValue_t = E_OK;
	uint8 i;
	for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
	{
		if(FVM_Rx_Pdu_ast[i].failed_cnt >= SECOC_VERIFICATION_FAIL_LIMIT)//pno 21 23 26 27
		{
			*data = (*data) | (1 << i);
		}
	}
	return retValue_t;
}

Std_ReturnType FVM_Deal_22_E555(uint8* data)
{
	Std_ReturnType retValue_t = E_OK;
	uint8 i;
	for(i = 0; i < SECOC_NUMBER_RX_PDU; i++)
	{
		data[i] = FVM_Rx_Pdu_ast[i].failed_cnt;
	}
	return retValue_t;
}

Std_ReturnType FVM_Deal_2E_F10B(uint8* Data, uint8* ErrorCode)
{
	Std_ReturnType retValue_t = E_OK;
	*ErrorCode = E_OK;
	uint8 i = 0;
	if(Eeprom_PINCODE[23] ==  CRC8forSAEJ1850(Eeprom_PINCODE, 23))
	{
		retValue_t = E_NOT_OK;
		*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_CONDITIONSNOTCORRECT;		
	}
	else if(NvM_StoreRequest.bit.DemExtra == 0)
	{
		for (i = 0; i < 16; i++)
		{
			Eeprom_PINCODE[i] = Data[i];
		}
		for(i = 0; i < 8; i++)
		{
			Eeprom_PINCODE[i + 16] = 0;
		}
		Eeprom_PINCODE[23] =  CRC8forSAEJ1850(Eeprom_PINCODE, 23);
		NvM_StoreRequest.bit.DemExtra = 1;
	}
	else
	{
		retValue_t = E_NOT_OK;
		*ErrorCode = ( Dcm_NegativeResponseCodeType )DCM_E_GENERALPROGRAMMINGFAILURE;
	}
	return retValue_t;
}
/*PROTECTED REGION ID(FileHeaderUserDefinedFunctions :CDD_FVM) ENABLED START */
/* Start of user defined functions  - Do not remove this comment */
/* End of user defined functions - Do not remove this comment */
/*PROTECTED REGION END */

