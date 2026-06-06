#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
static boolean s_IsDcmInitialized_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#if(DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
uint32 Dcm_Dsp_SecaGlobaltimer_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if((DCM_CFG_DSPOBDSUPPORT_ENABLED!= DCM_CFG_OFF)&&(DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_INFOTYPE_SUPPORT != DCM_CFG_OFF))
boolean Dcm_SupportInfotype_b;
Dcm_Dsp_Mode9BitMask_t Dcm_Dsp_Mode9Bitmask_acs[8];
#endif
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"


boolean Dcm_Prv_IsDcmInitialized(void)
{
    return s_IsDcmInitialized_b;
}

void Dcm_Prv_DcmInitialize(boolean value)
{
    s_IsDcmInitialized_b = value;
}

#if (DCM_CFG_RDPI_ENABLED == DCM_CFG_ON)
static void Dcm_Dsp_Prv_RdpiInit(void)
{
    const Dcm_DslConnectionConfigType_tst  *ActiveConnection_pacst = Dcm_Cfg_Dsl_pcst->dslConnection_pcast;
    const Dcm_DslPeriodicConnConfigType_tst *RdpiConnectionRef_pacst;

    if(NULL_PTR != ActiveConnection_pacst)
    {
        RdpiConnectionRef_pacst = ActiveConnection_pacst->periodicConn_past;

        if(NULL_PTR != RdpiConnectionRef_pacst)
        {
            Dcm_DsldPeriodicSchedulerIni();
        }
    }

}
#endif

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
static void Dcm_Prv_ROEInit(void)
{
    uint8_least idxIndex_qu8;
    const Dcm_DslConnectionConfigType_tst* ConnectionRef_pacst = Dcm_Cfg_Dsl_pcst->dslConnection_pcast;

    Dcm_Prv_SetRoeProtocolPduid(DCM_CFG_INVALID_RX_PDUID);

    /* Call the service ini of all ROE service table */
    for(idxIndex_qu8= 0x00u; idxIndex_qu8 <DCM_CFG_TOTAL_DSL_CONNECTIONS; idxIndex_qu8++)
    {

        if(NULL_PTR != ConnectionRef_pacst[idxIndex_qu8].roeConn_past)
        {
            /* Call initialisation of all services */
            Dcm_Dsd_Prv_ServiceInit(ConnectionRef_pacst[idxIndex_qu8].roeConn_past->srvTableId_u8);
        }


    }

#if(DCM_CFG_DSP_RESPONSEONEVENT_ENABLED == DCM_CFG_ON)
#if(DCM_CFG_DSP_ROEONDTCSTATUSCHANGE_ENABLED == DCM_CFG_ON)
    Dcm_RestoreROEDtcEvents();
#endif
#if(DCM_CFG_DSP_ROEDID_ENABLED == DCM_CFG_ON)
    Dcm_RestoreROEDidEvents();
#endif
#endif


#if(DCM_CFG_ROETYPE2_ENABLED == DCM_CFG_ON)
    Dcm_DsdRoe2State_en = DSD_IDLE_E;
#endif
}
#endif

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF) && (DCM_CFG_NUM_IOCBI_DIDS != 0x00u))
static void Dcm_Prv_IOCBIIinit(void)
{
    uint16 idxDid_u16;
    uint16 idxSig_u16;
    uint16 cntrIocbiDid_u16 = 0;
    uint16 DIDTablesize;

    DIDTablesize = Dcm_DIDcalculateTableSize_u16();
    /*Initialize the IOCBI DcmDsp_IocbiStatus_array */
    /*Loop through the complete DID structure to determine the index of all the IOCBI dids*/
    for(idxDid_u16=0; idxDid_u16<DIDTablesize; idxDid_u16++)
    {
        for(idxSig_u16=0; idxSig_u16<Dcm_DIDConfig[idxDid_u16].nrSig_u16; idxSig_u16++)
        {
            /*  Checking if the DID is meant for IO Control by checking if the session configured is not 0x00 */
            if((Dcm_DIDConfig[idxDid_u16].adrExtendedConfig_pcst->dataSessBitMask_u32!=0x00u) && (Dcm_DspDid_ControlInfo_st[Dcm_DspDataInfo_st[Dcm_DIDConfig[idxDid_u16].adrDidSignalConfig_pcst[idxSig_u16].idxDcmDspDatainfo_u16].idxDcmDspControlInfo_u16].idxDcmDspIocbiInfo_u16>0u))
            {
                break;
            }
        }
        if(idxSig_u16<Dcm_DIDConfig[idxDid_u16].nrSig_u16)
        {
            /*Store the index of IOCBI did from Dcm_DIDConfig structure*/
            DcmDsp_IocbiStatus_array[cntrIocbiDid_u16].idxindex_u16 = idxDid_u16;
            DcmDsp_IocbiStatus_array[cntrIocbiDid_u16].IocbiStatus_en = DCM_IOCBI_IDLESTATE;
            cntrIocbiDid_u16++;
#if( DCM_CFG_DSP_IOCBI_SR_ENABLED != DCM_CFG_OFF)
            if((TRUE == Dcm_DIDConfig[idxDid_u16].AtomicorNewSRCommunication_b) && \
                    ((USE_ATOMIC_SENDER_RECEIVER_INTERFACE == Dcm_DIDConfig[idxDid_u16].didUsePort_u8) || (USE_ATOMIC_SENDER_RECEIVER_INTERFACE_AS_SERVICE == Dcm_DIDConfig[idxDid_u16].didUsePort_u8)))
            {
                /*TRACE[SWS_Dcm_01436]*/
                /*TRACE[SWS_Dcm_01437]*/
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
                (void)(*(IOControlrequest_pfct)(Dcm_DIDConfig[idxDid_u16].ioControlRequest_cpv))(DCM_IOCBI_INIT,NULL_PTR,DCM_VALUE_NULL,DCM_VALUE_NULL,DCM_INITIAL,NULL_PTR);
            }
#endif
        }
    }
    /*By the end of this for loop it is expected that all the indexes of IOCBI DIDs are stored and status is saved.*/
}
#endif
static void Dcm_Dsp_Init(const Dcm_ConfigType* ConfigPtr)
{
    uint8 idxIndex_u8;
    (void) ConfigPtr;
    /* Dsp init function that initializes the information required by DSP submodule */

    /* set the default session time */
    /* BSWEXT-533 */
    /* Spin lock is not needed here as Dcm_Init is called in Init context */
    Dcm_DsldTimer_st.dataTimeoutP2max_u32    =  DCM_CFG_DEFAULT_P2MAX_TIME;
    Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 =  DCM_CFG_DEFAULT_P2STARMAX_TIME;

    /* Set to active diagnostics mode*/
    Dcm_ActiveDiagnosticState_en = DCM_COMM_ACTIVE;

    Dcm_CC_ActiveSession_u8 =  DCM_DEFAULT_SESSION;
    /*Initialising Dcm_DsldGlobal_st.active_commode_e.ComMState */
    /*Reset channel states */
    for(idxIndex_u8 = 0;idxIndex_u8<DCM_NUM_COMM_CHANNEL;idxIndex_u8++)
    {
        Dcm_active_commode_e[idxIndex_u8].ComMState =   DCM_DSLD_NO_COM_MODE;
        Dcm_active_commode_e[idxIndex_u8].ComMChannelId= Dcm_Dsld_ComMChannelId_acu8[idxIndex_u8];
    }
    /* Appl function to change the reference to the rx table*/
    DcmAppl_DcmUpdateRxTable();

#if(DCM_ROE_ENABLED == DCM_CFG_ON)
    Dcm_Prv_ROEInit();
#endif

#if (DCM_CFG_RDPI_ENABLED == DCM_CFG_ON)
    Dcm_Dsp_Prv_RdpiInit();
#endif

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF) && (DCM_CFG_NUM_IOCBI_DIDS != 0x00u))
    Dcm_Prv_IOCBIIinit();
#endif

}

/**
 **************************************************************************************************
 * Dcm_Prv_WarmStart : Calls Dcm_GetProgConditions to restore all the information for Warmstart;
 *                     checks ComM_Dcm_ActiveDiagnostic needs to be called or not id it is Warmrequest
 *                     or Warmresponse
 * \param[in]      None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
#if (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
static void Dcm_Prv_WarmStart(void)
{
    uint8 ComMChannelIdx_u8;
    Dcm_EcuStartModeType dataRetGetProgCond_u8;
    /* TRACE: [SWS_Dcm_00536] */
    /* TRACE: [SWS_Dcm_00544] */
    /* Call the API to restore the information for WARM start */
    dataRetGetProgCond_u8 = Dcm_GetProgConditions(&Dcm_ProgConditions_st);
    /* Check for the WARM START  */
    if(dataRetGetProgCond_u8 == DCM_WARM_START)
    {
        /*Initialize the variable to the value TRUE*/
        Dcm_ReadyForBoot_b = TRUE;

        if (( Dcm_ProgConditions_st.StoreType == DCM_WARMREQUEST_TYPE ) || ( Dcm_ProgConditions_st.StoreType == DCM_WARMRESPONSE_TYPE ))
        {
            Dcm_Prv_SetCurrentProtocol(Dcm_ProgConditions_st.ProtocolId);
            ComMChannelIdx_u8 = Dcm_Cfg_Dsl_pcst->mainConnCfg_pcast[Dcm_GetActiveConnectionIdx_u8()].channel_idx_u8;
            /* TRACE: [SWS_Dcm_00537] */
            Dcm_CheckActiveDiagnosticStatus(Dcm_active_commode_e[ComMChannelIdx_u8].ComMChannelId);
        }
    }
    else
    {
        /*Initialize the variable to the value FALSE*/
        Dcm_ReadyForBoot_b = FALSE;
        Dcm_ProgConditions_st.StoreType       = DCM_NOTVALID_TYPE;
    }

}
#endif


/**
 **************************************************************************************************
 * Dcm_Prv_SecaInit : Initialise Seca global timer to zero; Restore delay count; Clear seed;
 *                    Restore secatimer  and go to warmstart or power on delay function is
 *                    configured depending upon StoreType
 * \param[in]      None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
#if(DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)
static void Dcm_Prv_SecaInit(void)
{
    /* Initialize the required global variables */
#if (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
    /* Initialise Security Access Global Timer */
    Dcm_Dsp_SecaGlobaltimer_u32 = 0x0;
#endif


#if (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
#if (DCM_CFG_DSP_SECA_ATTEMPT_COUNTER!=DCM_CFG_OFF)
    /* Call DSP function to load the Delay count values of Security levels */
    Dcm_Dsp_RestoreDelayCount();
#if (DCM_CFG_DSP_SECA_STORESEED != DCM_CFG_OFF)
    Dcm_Dsp_SecaClearSeed();
#endif
#endif
#endif

#if(DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
    /* Restore the SECA timer for loading the SECA timers */
    Dcm_DslDsdRestoreSecaTimer();
#endif
}
#endif


/**
 **************************************************************************************************
 * Dcm_Prv_BufqueueInit : Initialising Buffer index to point to first buffer and Setting the Queue
 *                       state to IDLE state.
 * \param[in]      None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
static void Dcm_Prv_BufqueueInit(void)
{
    /* Initializing the buffer index to 1 so that it indices to the first buffer */
    Dcm_QueueStructure_st.idxBufferIndex_u8 = 1;
    /* Setting the Queue state to IDLE */
    Dcm_QueueStructure_st.Dcm_QueHandling_en = DCM_QUEUE_IDLE;
}
#endif

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3198] */
void Dcm_Init (const Dcm_ConfigType* ConfigPtr)
{

#if((DCM_CFG_DSPOBDSUPPORT_ENABLED!= DCM_CFG_OFF)&&(DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_INFOTYPE_SUPPORT != DCM_CFG_OFF))
uint8 countbitmaxarrayIdx;
uint8 sizeofbitmaxarray=0x08u;
#endif

    if(NULL_PTR == ConfigPtr)
    {
        ConfigPtr=Dcm_Cfg_pcst;
    }
    else
    {
        /* PostBuild. Currently not supported */
    }

    Dcm_General_Init();

    Dcm_Dsl_Init(ConfigPtr);

    Dcm_Dsd_Init(ConfigPtr);

    Dcm_Dsp_Init(ConfigPtr);


#if( DCM_BUFQUEUE_ENABLED!= DCM_CFG_OFF)
    Dcm_Prv_BufqueueInit();
#endif

#if (DCM_CFG_RESTORING_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_WarmStart();
#endif

#if(DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_SecaInit();
#endif

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_Dsl_AuthenticationIni();
#endif

#if((DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_SPLITRESPSUPPORTEDFORKWP != DCM_CFG_OFF))
    Dcm_isFirstReponseSent_b = FALSE;
#endif

#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    Dcm_Prv_PagedBufferInit();
#endif
    Dcm_DslTransmit_st.isForceResponsePendRequested_b   =  FALSE;
    Dcm_BootSeqComplete_b = FALSE;
    Dcm_Prv_DcmInitialize(TRUE);

#if((DCM_CFG_VIN_SUPPORTED != DCM_CFG_OFF) && (DCM_CFG_DIDSUPPORT != DCM_CFG_OFF))
    Dcm_VinReceived_b = FALSE;
    Dcm_GetvinConditionCheckRead = FALSE;
#endif

#if((DCM_CFG_DSPOBDSUPPORT_ENABLED!= DCM_CFG_OFF)&&(DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_INFOTYPE_SUPPORT != DCM_CFG_OFF))
    for(countbitmaxarrayIdx=0x00u;countbitmaxarrayIdx<sizeofbitmaxarray;countbitmaxarrayIdx++)
    {
        /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as input and object type pointer is converted to void pointer*/
        DCM_MEMCOPY(&Dcm_Dsp_Mode9Bitmask_acs[countbitmaxarrayIdx],&Dcm_Dsp_Cfg_Mode9Bitmask_acs[countbitmaxarrayIdx],sizeofbitmaxarray);
    }
    Dcm_SupportInfotype_b=TRUE;
#endif
    /* Variable Set to TRUE to indicate that Dcm is initialised and can accept tester requests */
    Dcm_acceptRequests_b= TRUE;
    /**Donot add any code below Dcm_acceptRequests_b=TRUE, whatever code needs to be added has to be done above this
     * statement, this is necessary since flag Dcm_acceptRequests_b is used in the Dcm_MainFunction() api to ensure
     * Dcm_Init and Dcm_Mainfunction does not run in parallel*/
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

