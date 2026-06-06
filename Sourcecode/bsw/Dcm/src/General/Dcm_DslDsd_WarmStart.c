#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#if (DCM_CFG_DSP_BSWMDCM_ENABLED != DCM_CFG_OFF)
#include "BswM_Dcm.h"
#endif
#include "Dcm_Prv.h"

#if((DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)||(DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF))
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* Programming conditions information */
Dcm_ProgConditionsType Dcm_ProgConditions_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED/*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#if (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
 boolean Dcm_SesChgOnWarmResp_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 **************************************************************************************************
 * Dcm_GetActiveConnectionIdx_u8 : To retrieve the "Connection" Index of to be started Protocol so as
 * to inform ComM for Active Diagnosis
 * This Index is to be retrieved only in case of Warm request/Warm Response
 * \param           None
 * \retval          uint8 - Index to Connection of "to-be-started" Protocol
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

uint8 Dcm_GetActiveConnectionIdx_u8 (void)
{
    uint8_least idxProtcol_qu8;      /* Protocol index used in search loop */
    uint8 idxSession_qu8;      /* Session index used in search loop */
    PduIdType idxIndex1_qu8;
    uint8_least idxIndex2_qu8;
    uint8 idxConn_u8;
    idxConn_u8 = 0;


    /* Search all protocols available to start matching protocol */
    for (idxProtcol_qu8 = 0; idxProtcol_qu8 < DCM_CFG_NUM_PROTOCOL; idxProtcol_qu8++)
    {
        if (Dcm_ProgConditions_st.ProtocolId == Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[idxProtcol_qu8].protocolType)
        {   /* Matching protocol found */
            break;
        }
    }
    /* Check if there was a matching protocol */
    if (idxProtcol_qu8 >= DCM_CFG_NUM_PROTOCOL)
    {   /* Matching protocol was not found, use the first protocol configured to restore information */
        idxProtcol_qu8 = 0;
    }

    /* Find the programming session */
    /* Session Look up table is not available */
    for(idxSession_qu8 = 0; idxSession_qu8 < DCM_CFG_NUM_UDS_SESSIONS; idxSession_qu8++)
    {   /* Check whether the Session is configured */
        if (Dcm_ProgConditions_st.SessionLevel == Dcm_Prv_GetSession(idxSession_qu8))
        {    /*Matching session found*/
            break;
        }
    }
    if (idxSession_qu8 < DCM_CFG_NUM_UDS_SESSIONS)
    {
        /* Set the protocol index first */
        Dcm_Prv_Update_ProtocolIndex(idxProtcol_qu8);

        /* Find the connection index of the protocol to start */
        for(idxIndex1_qu8=0; idxIndex1_qu8 < DCM_CFG_TOTAL_RX_PDUID; idxIndex1_qu8++)
        {   /* Check the connection of the protocol belongs to the restored protocol */
            if(Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Cfg_Dsl_pcst->protocolRx_pc[idxIndex1_qu8]].protocolRowIdx_u8 == idxProtcol_qu8)
            {   /* Check if the tester address matches */
                if(Dcm_Prv_GetTesterSrcAddressFromRxPduId(idxIndex1_qu8) == Dcm_ProgConditions_st.TesterSourceAddr)
                {   /* Update the active connection variable */
                    idxConn_u8 = (uint8)(Dcm_Cfg_Dsl_pcst->protocolRx_pc[idxIndex1_qu8]);
                    break;
                }
            }
        }
        /* If the Tester address restored is invalid / not configured*/
        if(idxIndex1_qu8 >= DCM_CFG_TOTAL_RX_PDUID)
        {   /* Get the tester address from the first connection of this protocol */
            for(idxIndex2_qu8=0; idxIndex2_qu8<DCM_CFG_TOTAL_DSL_CONNECTIONS; idxIndex2_qu8++)
            {   /* If the protocol matches */
                if(Dcm_Prv_GetProtocolIndex((uint8)idxIndex2_qu8) == idxProtcol_qu8)
                {   /* Assign the first connection */
                    idxConn_u8 = (uint8)idxIndex2_qu8;
                    break;
                }
            }
        }
    }
    else
    {
        idxConn_u8 = 0;
    }

    for(idxIndex1_qu8=0; idxIndex1_qu8 < DCM_CFG_TOTAL_RX_PDUID; idxIndex1_qu8++)
    {
        if(Dcm_Cfg_Dsl_pcst->protocolRx_pc[idxIndex1_qu8] == idxConn_u8)
        {
            Dcm_Prv_SetActiveRxPduId(idxIndex1_qu8,Dcm_ProgConditions_st.ReqResLen);
            break;
        }
    }

    return idxConn_u8;
}

/**
 **************************************************************************************************
 * Dcm_DslDsdWarmStart : Warm Start initialization of DCM module.
 * This initialization is required only in case of Warm request/ Warm Init/ Warm Response
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void Dcm_DslDsdWarmStart(void)
{
    uint8_least idxProtcol_qu8;      /* Protocol index used in search loop */
    uint8 idxSession_qu8;      /* Session index used in search loop */
    uint8 dataSessionId_u8;      /* Session ID value */
    uint8_least nrReqLength_qu8;    /* Length of the request */
    PduIdType idxIndex1_qu8;
    uint8_least idxIndex2_qu8;
    uint8 *ResponseBuffer;
    uint32 DataTimeoutMonitor_u32;
    const Dcm_DslProtocolRowConfigType_tst * protocol_table_pcs; /* Pointer to protocol table */
    Dcm_SesChgOnWarmResp_b =FALSE;
    if (Dcm_ProgConditions_st.StoreType != DCM_NOTVALID_TYPE)
    {
        /* Retrieve the request length information */
        nrReqLength_qu8 = Dcm_ProgConditions_st.ReqResLen;

        /* Search all protocols available to start matching protocol */
        for (idxProtcol_qu8 = 0; idxProtcol_qu8 < DCM_CFG_NUM_PROTOCOL; idxProtcol_qu8++)
        {
            if (Dcm_ProgConditions_st.ProtocolId == Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[idxProtcol_qu8].protocolType)
            {   /* Matching protocol found */
                break;
            }
        }

        /* Check if there was a matching protocol */
        if (idxProtcol_qu8 >= DCM_CFG_NUM_PROTOCOL)
        {   /* Matching protocol was not found, use the first protocol configured to restore information */
            idxProtcol_qu8 = 0;
            /* Report development error "DCM_E_PROTOCOL_NOT_FOUND " to DET module if the DET module is enabled */
            Dcm_Prv_Det(DCM_WARMSTART_ID , DCM_E_PROTOCOL_NOT_FOUND );
            for(idxIndex1_qu8=0; idxIndex1_qu8 < DCM_CFG_TOTAL_DSL_CONNECTIONS; idxIndex1_qu8++)
            {   /* Check for the connection which has protocol index as 0 */
                if(Dcm_Prv_GetProtocolIndex((uint8)idxIndex1_qu8) == 0x0u)
                {   /* Loop to get the Tester Address of first connection in protocol index 0 */
                    Dcm_ProgConditions_st.TesterSourceAddr = Dcm_Prv_GetTesterSrcAddress((uint8)idxIndex1_qu8);
                    break;
                }
            }
        }
#if(DCM_CFG_DSP_ECURESET_ENABLED != DCM_CFG_OFF)
        if((Dcm_ProgConditions_st.Sid == DCM_DSP_SID_ECURESET) ||  (Dcm_ProgConditions_st.Sid == 0x51u))
        {
         idxSession_qu8 = DCM_DEFAULT_SESSION_IDX;
        }
        else
#endif
        {
            /* Find the programming session */
            /* Session Look Up Table not available */
            for(idxSession_qu8 = 0; idxSession_qu8 < DCM_CFG_NUM_UDS_SESSIONS; idxSession_qu8++)
            {   /* Check whether the Session is configured */
                if (Dcm_ProgConditions_st.SessionLevel == Dcm_Prv_GetSession(idxSession_qu8))
                {
                    /*Matching session found*/
                    break;
                }
            }
        }

        if (idxSession_qu8 < DCM_CFG_NUM_UDS_SESSIONS)
        {
            /* Set the protocol index first */
            Dcm_Prv_Update_ProtocolIndex(idxProtcol_qu8);

            /* Find the connection index of the protocol to start */
            for(idxIndex1_qu8=0; idxIndex1_qu8 < DCM_CFG_TOTAL_RX_PDUID; idxIndex1_qu8++)
            {   /* Check the connection of the protocol belongs to the restored protocol */
                if(Dcm_Cfg_Dsl_pcst->dslConnection_pcast[Dcm_Cfg_Dsl_pcst->protocolRx_pc[idxIndex1_qu8]].protocolRowIdx_u8 == idxProtcol_qu8)
                {   /* Check if the tester address matches */
                    if(Dcm_Prv_GetTesterSrcAddressFromRxPduId(idxIndex1_qu8) == Dcm_ProgConditions_st.TesterSourceAddr)
                    {
                        /* Update the active RxPduId variable for Generic Connection Handling*/
                        Dcm_Prv_SetActiveRxPduId(idxIndex1_qu8,Dcm_ProgConditions_st.ReqResLen);
                        /* Update the active connection variable */
                        Dcm_Prv_SetActiveConnectionIdx(idxIndex1_qu8,DCM_CFG_TOTAL_DSL_CONNECTIONS);
                        /* Update the Source and Target Address for Generic Connection Handling*/
                        Dcm_Prv_SetSourceAndTargetAddressWarmStart(Dcm_Prv_GetActiveConnectionIndex(),Dcm_ProgConditions_st.TesterSourceAddr);
                        break;
                    }
                }
            }
            /* If the Tester address restored is invalid / not configured*/
            if(idxIndex1_qu8 >= DCM_CFG_TOTAL_RX_PDUID)
            {   /* Get the tester address from the first connection of this protocol */
                for(idxIndex2_qu8=0; idxIndex2_qu8<DCM_CFG_TOTAL_DSL_CONNECTIONS; idxIndex2_qu8++)
                {   /* If the protocol matches */
                    if(Dcm_Prv_GetProtocolIndex((uint8)idxIndex2_qu8) == idxProtcol_qu8)
                    {   /* Assign the first connection */
                        Dcm_Prv_SetActiveConnectionIdx(idxIndex1_qu8,(PduIdType)idxIndex2_qu8);
                        /* Update the Source and Target Address for Generic Connection Handling*/
                        Dcm_Prv_SetSourceAndTargetAddressWarmStart(Dcm_Prv_GetActiveConnectionIndex(),Dcm_Prv_GetTesterSrcAddress((uint8) Dcm_Prv_GetActiveConnectionIndex()));
                        break;
                    }
                }
            }

            /* Set TxPduId and service table */
            Dcm_Prv_SetMainConnection(Dcm_Prv_GetActiveConnectionIndex());


#if(DCM_CFG_DSP_ECURESET_ENABLED != DCM_CFG_OFF)
            if((Dcm_ProgConditions_st.Sid == DCM_DSP_SID_ECURESET) ||  (Dcm_ProgConditions_st.Sid == 0x51u))
            {
                /* set the session as default session */
                Dcm_Prv_SetActiveSessionIdx(DCM_DEFAULT_SESSION_IDX );

                /* set the default session time */
                Dcm_DsldTimer_st.dataTimeoutP2max_u32    =  DCM_CFG_DEFAULT_P2MAX_TIME;
                Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 =  DCM_CFG_DEFAULT_P2STARMAX_TIME;
                /* lock the ECU */
                Dcm_Prv_SetActiveSecurityLevelIdx(DCM_SEC_LEV_LOCKED);

            }
            else
#endif
            {
                /* Set the active session information */
                Dcm_Prv_SetSesCtrlType(Dcm_Prv_GetSession(idxSession_qu8));
                /* Copy the session Id */
                dataSessionId_u8 = Dcm_ProgConditions_st.SessionLevel;

#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF)
                         /* Get the timings of the active session */
                        Dcm_GetP2Timings(&Dcm_DsldTimer_st.dataTimeoutP2max_u32, &Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32,
                                         (Dcm_SesCtrlType)dataSessionId_u8);
#else
                        DcmAppl_DcmGetP2Timings(&Dcm_DsldTimer_st.dataTimeoutP2max_u32, &Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32,
                                                (Dcm_SesCtrlType)dataSessionId_u8);
#endif
                /* Set the security value */

                       Dcm_Prv_SetSecurityLevel(Dcm_ProgConditions_st.SecurityLevel);
            }


            /* Check for Warm request type of jump */
            /*If nrRequest Length is valid and Response has to be sent by flashloader or application*/
            if ((Dcm_ProgConditions_st.StoreType == DCM_WARMREQUEST_TYPE) && (nrReqLength_qu8 != 0x0u) && (Dcm_ProgConditions_st.ResponseRequired != FALSE))
            {
                /* store the request length, including SID */
                Dcm_Dsl_Prv_SetActiveRequestDataLen((PduLengthType)nrReqLength_qu8);

                /* Get the Rx buffer and it's length */
                protocol_table_pcs = &Dcm_Cfg_Dsl_pcst->protocolRowCfg_pcast[idxProtcol_qu8];

                /* Copy SID to the Rx buffer */
                protocol_table_pcs->rxBuffer_u8[0] = Dcm_ProgConditions_st.Sid;
                nrReqLength_qu8--;
                /* If the sub-function is applicable */
                if(nrReqLength_qu8 > 0x0u)
                {
                    /* Copy the sub-function to Rx buffer */
                    protocol_table_pcs->rxBuffer_u8[1] = Dcm_ProgConditions_st.SubFncId;
                    nrReqLength_qu8--;
                }
              /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as input and object type pointer is converted to void pointer*/
                DCM_MEMCOPY(&(protocol_table_pcs->rxBuffer_u8[0x02]), Dcm_ProgConditions_st.ReqResBuf,nrReqLength_qu8);

                /* DcmAppl_DcmStartProtocol() is not called here as it is not a start of new protocol only a
                   a reinitialization */

                /* Mark that wait pend is sent, so that always a response goes to the tester. */
                Dcm_Dsl_Prv_SetRespPendingCounterValue(Dcm_ProgConditions_st.NumWaitPend);

                /* Change the state so that the service is called in the first execution of the Dcm_MainFunction */
                /* Multicore: No lock needed here as Dsl state is an atomic operation */
                /* DSL state machine handling ensures that there is no data consistency issues */
                Dcm_Dsl_Prv_SetDslState(DSL_STATE_REQUESTRECEIVED_STARTPROTOCOL_E);

                DataTimeoutMonitor_u32 = Dcm_Prv_Get_DataTimeOut();

                if(Dcm_Dsl_Prv_GetRespPendingCounterValue() != 0u)
                {
                    /* Start P2* timer */
                    /* BSWEXT-533 */
                    uint32 DataP2TimerServerAdjust_u32 = Dcm_Prv_GetActive_P2ServerTimeAdjust();
                    DCM_TimerStart(DataTimeoutMonitor_u32,
                                  (Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 - DataP2TimerServerAdjust_u32),
                                   Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
                    Dcm_Prv_Set_DataTimeOut(DataTimeoutMonitor_u32);
                }
                else
                {
                    /* Start P2 timer */

                    uint32 DataP2TimerServerAdjust_u32 = Dcm_Prv_GetActive_P2ServerTimeAdjust();
                    DCM_TimerStart(DataTimeoutMonitor_u32,
                                  (Dcm_DsldTimer_st.dataTimeoutP2max_u32 - DataP2TimerServerAdjust_u32),
                                   Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
                    Dcm_Prv_Set_DataTimeOut(DataTimeoutMonitor_u32);
                }
            }

           /* Check for Warm Init type of jump */
            if (Dcm_ProgConditions_st.StoreType == DCM_WARMINIT_TYPE)
            {
                /* Start S3 timer */
                Dcm_Prv_ReloadS3Timer();
            }

           /* Check for Warm response type of jump */
            /*If nrRequest Length is valid and Response has to be sent by flashloader or application*/
            if((Dcm_ProgConditions_st.StoreType == DCM_WARMRESPONSE_TYPE) && (nrReqLength_qu8 != 0x0u) && (Dcm_ProgConditions_st.ResponseRequired != FALSE))
            {

                ResponseBuffer = &Dcm_Prv_GetActiveTxBuffer()[2];


                /* Arrange the buffer to fill in SID and Sub-function */
                for(idxIndex1_qu8 = (uint8)(nrReqLength_qu8-1u); idxIndex1_qu8 > 0x1u; idxIndex1_qu8--)
                {
                    Dcm_ProgConditions_st.ReqResBuf[idxIndex1_qu8]= Dcm_ProgConditions_st.ReqResBuf[idxIndex1_qu8-0x2u];
                }
                /* Copy the sub-function and SID */
                Dcm_ProgConditions_st.ReqResBuf[0] = Dcm_ProgConditions_st.Sid;
                Dcm_ProgConditions_st.ReqResBuf[1] = Dcm_ProgConditions_st.SubFncId;
                /* MR12 DIR 1.1 VIOLATION: This is required for implementation as DCM_MEMCOPY takes void pointer as input
                 * and object type pointer is converted to void pointer */
                DCM_MEMCOPY(ResponseBuffer,Dcm_ProgConditions_st.ReqResBuf,nrReqLength_qu8);

                Dcm_Dsd_Prv_SetDsdState(DSD_WAITFORTXCONF_E);
                Dcm_Dsl_Prv_SetDslState(DSL_STATE_RESPONSETRANSMISSION_E);

                Dcm_Prv_TriggerTransmit((PduLengthType)nrReqLength_qu8);

#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF)
                /*Check if the service for which response to be send is DSC.check positive resp value*/
                if (Dcm_ProgConditions_st.Sid == 0x50u)
                {
                    /* Session Look up table not available */
                for(idxSession_qu8 = 0; idxSession_qu8 < DCM_CFG_NUM_UDS_SESSIONS; idxSession_qu8++)
                        {   /* Check whether the Session is configured */
                            if (Dcm_ProgConditions_st.SubFncId == Dcm_Prv_GetSession(idxSession_qu8))
                            {
                                /*Matching session found*/
                                break;
                            }
                        }
                        if (idxSession_qu8 < DCM_CFG_NUM_UDS_SESSIONS)
                        {
                            Dcm_ctDiaSess_u8=idxSession_qu8;
                            Dcm_SesChgOnWarmResp_b=TRUE;
                        }
                }
#endif
                /* DcmAppl_DcmStartProtocol() is not called here as it is not a start of new protocol only a
                   a reinitialization */

                /* Change the state so that next call of Dcm_MainFunction() send the warm response */
                /* DSD state should be updated to DSD_WAITFORTXCONF to give confirmation to application    */
                /* Multicore: No lock needed here as Dsl state is an atomic operation */
                /* DSL state machine handling ensures that there is no data consistency issues */

            }
            /* Communication is started */

            Dcm_Prv_SetProtocolStatus(TRUE);

            /* Get the active service table pointer from Sid table*/
            Dcm_Prv_SetServiceTable(Dcm_Prv_GetActiveSrvTabId());

            /* Call initialisation of all services */
            Dcm_Dsd_Prv_ServiceInit(Dcm_Prv_GetActiveSrvTabId());
        }
        else
        {
            /* !!!This part of code should not be reached */
            /* The programming session should used in drive should also exist in boot */
        }
        /* Check whether the application is reprogrammed*/

        if(Dcm_ProgConditions_st.ApplUpdated != FALSE)
        {
#if (DCM_CFG_DSP_BSWMDCM_ENABLED != DCM_CFG_OFF)
            /* TRACE: [SWS_Dcm_00768] */
            /* Inform BswM Module regarding the application software change*/
            BswM_Dcm_ApplicationUpdated();
#endif
            /* Clear the ApplUpdated flag*/

            Dcm_ProgConditions_st.ApplUpdated = FALSE;
         }
#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF)
         /*Check if  Reset the reprogramming flag to TRUE */

         if(Dcm_ProgConditions_st.ReprogramingRequest != FALSE)
         {
             /*Set the reprogramming flag to FALSE*/
             Dcm_ProgConditions_st.ReprogramingRequest = FALSE;
         }
#endif
         /* Reset the response required flag*/

         Dcm_ProgConditions_st.ResponseRequired = FALSE;
         /* Clear the Communication state descriptor and set it to INACTIVE */
         Dcm_ProgConditions_st.StoreType = DCM_NOTVALID_TYPE;
    }
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

