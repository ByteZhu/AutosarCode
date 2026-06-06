#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED  /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
Dcm_Dsld_activediagnostic_ten Dcm_ActiveDiagnosticState_en;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

Dcm_SesCtrlType Dcm_CC_ActiveSession_u8;

#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
boolean Dcm_IsCancelTransmitInvoked_b; /* Variable used for checking cancel transmit status */
boolean Dcm_BootSeqComplete_b;

#if (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
boolean Dcm_ReadyForBoot_b;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#if(DCM_CFG_VIN_SUPPORTED != DCM_CFG_OFF)

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

static uint8 s_VinWaitPendingCounter_u8 ;   /*Indicate pending response is returned while reading VIN DID */
static Std_ReturnType s_VinBufferInitStatus_u8 = E_OK; /*Indicate return status for reading VIN DID  */

#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#endif


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
Dcm_MsgContextType Dcm_OBDMsgContext_st; /* MsgContext Structure for OBD */
Dcm_OBDInternalStructureType_tst Dcm_OBDGlobal_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#if (DCM_CFG_OSTIMER_USE != FALSE)
#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
uint32 Dcm_OBDP2OrS3StartTick_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
boolean Dcm_ObdSendTxConfirmation_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#endif

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
boolean Dcm_acceptRequests_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_ROE_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF))
/**********************************************************************************************************************
 Function name    : Dcm_Prv_RoeMainFunction
 Syntax           : Dcm_Prv_RoeMainFunction()
 Description      : Invoke RoeStateMachine function in Dcm_MainFunction cyclically.
 Parameter        :
 Return value     : None
**********************************************************************************************************************/
static void Dcm_Prv_RoeMainFunction (void)
{
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
        if(Dcm_DsdRoe2State_en != DSD_IDLE_E)
        {
            /* Roe type 2 handling */
            Dcm_DsldRoe2StateMachine();
        }
        else
        {
           Dcm_DsldProcessRoeQueue();
        }
#else
        if(Dcm_Dsl_Prv_GetDslState() == DSL_STATE_IDLE_E)
        {
            if(Dcm_Dsd_Prv_GetDsdState() == DSD_IDLE_E)
            {
                Dcm_DsldProcessRoeQueue();
            }
        }
#endif
}
#endif



/***********************************************************************************************************************
 Function name    : Dcm_Prv_OBDMainFunction
 Description      : Function to manage OBD Portion when parallel processing is enabled
 Parameter        : void
 Return value     : void
***********************************************************************************************************************/
#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
static void Dcm_Prv_OBDMainFunction(void)
{
    /* TxConfirmation was received. Inform the application */
    if(Dcm_ObdSendTxConfirmation_b == TRUE)
    {
       Dcm_Prv_ConfirmationToOBDApl();
       Dcm_ObdSendTxConfirmation_b = FALSE;
    }
    /* Check OBD P2/P2* timer and further process it */
    Dcm_Prv_OBDTimerProcessing();
    // State Machine for OBD request processing
    Dcm_Prv_OBDStateMachine();
}
#endif

static void Dcm_Dsp_Main(void)
{

#if(DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_Cdtcs_Mainfunction();
#endif

#if ( ( DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF ) && ( DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED != DCM_CFG_OFF ) )
    Dcm_Prv_CC_Mainfunction();
#endif

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_ROE_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF))
    Dcm_Prv_RoeMainFunction();
#endif

#if(DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_RC_Mainfunction();
#endif
}


/**
 *************************************************************************************************
 * Dcm_Prv_Main_Warmstart :  Internal function to Main Function to check whether warmstart is required.
 *
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

#if (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
static void Dcm_Prv_Main_Warmstart(void)
{

    Std_ReturnType stGetPermTxWarmResp_u8; /* Variable to get return from DcmAppl API */


    /* Check for No Communication mode in DCM */

    if(Dcm_ProgConditions_st.StoreType != DCM_NOTVALID_TYPE)
    {

        if(Dcm_ProgConditions_st.StoreType == DCM_WARMINIT_TYPE)
        {


            /* No warm response needs to be transmitted */
            Dcm_DslDsdWarmStart();



            Dcm_ReadyForBoot_b = FALSE;
        }

        else
        {
            if(DCM_CHKFULLCOMM_MODE(Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[Dcm_GetActiveConnectionIdx_u8()].channel_idx_u8))
            {
                /* Call the application API to get the permissions for transmission */
                stGetPermTxWarmResp_u8 = DcmAppl_DcmGetPermTxWarmResp();

                switch(stGetPermTxWarmResp_u8)
                {
                    /* If the permission is given by application to transmit the warm response */
                    case E_OK :
                    {
                        Dcm_DslDsdWarmStart();
                        /* Reset the variable to FALSE to prevent re-entry to the loop as permission is received for transmitting response */\
                        Dcm_ReadyForBoot_b = FALSE;
                    }
                    break;

                    case DCM_E_PENDING:
                        break;

                    default :
                    {
                        /* Move to FULL COMM mode as the warm response cannot be sent */
                        /* Reset the Programming table contents */
                        Dcm_ProgConditions_st.StoreType = DCM_NOTVALID_TYPE;
                        /* Reset the variable to FALSE to prevent re-entry to the loop as permission is not received for transmitting response */
                        Dcm_ReadyForBoot_b = FALSE;
                    }
                    break;
                }

            }
        }
    }
    else
    {
        /* State transition to FULL-COMM will happen via Dcm call-back to ComM. Nothing to be done here */
        /* Reset the variable to FALSE as the StoreType is invalid */

        Dcm_ReadyForBoot_b = FALSE;
    }

}
#endif

/**
 *************************************************************************************************
 * Dcm_Prv_MainVINinit :  Internal function to Main Function to initialise VIN buffer
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

#if(DCM_CFG_VIN_SUPPORTED != DCM_CFG_OFF)
static void Dcm_Prv_MainVINinit (void)
{
    /* Read VIN DID During Startup */
          /* Check if VIN DID is already read */
          if(Dcm_VinReceived_b != TRUE)
          {
                /*Check if Dcm_VinBuffer_Init return status is E_OK or DCM_E_PENDING */
              if((s_VinBufferInitStatus_u8 == E_OK) || ((s_VinBufferInitStatus_u8 == DCM_E_PENDING) && ( s_VinWaitPendingCounter_u8 < DCM_CFG_WAIT_FOR_VIN)))
              {
                  s_VinBufferInitStatus_u8 = Dcm_VinBuffer_Init();
                   /*Increament counter value if server needs more time to read */
                  if(s_VinBufferInitStatus_u8 == DCM_E_PENDING)
                  {
                      s_VinWaitPendingCounter_u8++;
                  }
                  if(Dcm_VinReceived_b == TRUE)
                  {
                      /* Update the VIN wait pend counter with zero when VIN data is available */
                      s_VinWaitPendingCounter_u8 = 0x00;
                  }
              }
          }
}
#endif


/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3201] */
void Dcm_MainFunction(void)
{
    if(Dcm_Prv_IsDcmInitialized())
    {

#if (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)
        if(Dcm_Dsp_SecaGlobaltimer_u32 < 0xFFFFFFFFu)
        {
            /* If the SECA service is present in DSP */
            Dcm_Dsp_SecaGlobaltimer_u32++;
        }

#if(DCM_CFG_DSP_SECA_ATTEMPT_COUNTER!=DCM_CFG_OFF)
        if(Dcm_GetattemptCounterWaitCycle_u8 <= DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME)
        {
            /* Call DSP function to load the Delay count values of Security levels */
            Dcm_Dsp_RestoreDelayCount();
        }
#endif
#endif

#if (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
        if(Dcm_ReadyForBoot_b != FALSE)
        {
            Dcm_Prv_Main_Warmstart();
        }

        /*Check for No Communication mode in DCM*/
        if(Dcm_ReadyForBoot_b == FALSE)
        {
            /*Dcm is initialized*/
            Dcm_BootSeqComplete_b = TRUE;
        }
#else
        /*initialize the variable*/
        Dcm_BootSeqComplete_b = TRUE;
#endif

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_OBDMainFunction();
#endif
    if(DSL_PREEMPTION_HIGHPRIORITY_REQUESTRECEIVED_E != Dcm_Dsl_Prv_GetPreemptionState())
    {
        Dcm_Dsl_Main();

        Dcm_Dsd_Main();
    }

        Dcm_Dsp_Main();

#if(DCM_CFG_VIN_SUPPORTED != DCM_CFG_OFF)
        Dcm_Prv_MainVINinit ();
#endif


    }
    else
    {
        /* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3541] */
        Dcm_Prv_Det(DCM_MAINFUNCTION_ID, DCM_E_UNINIT);
    }

#if((DCM_CFG_DSPOBDSUPPORT_ENABLED!= DCM_CFG_OFF)&&(DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)&&\
        (DCM_CFG_INFOTYPE_SUPPORT != DCM_CFG_OFF))
        if(Dcm_SupportInfotype_b==TRUE)
        {
            Dcm_Prv_SupportInfoTypecheck();
            Dcm_SupportInfotype_b=FALSE;
        }
#endif

}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
