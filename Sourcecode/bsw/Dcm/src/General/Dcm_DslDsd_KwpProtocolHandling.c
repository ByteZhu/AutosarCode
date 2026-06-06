#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"

Dcm_Dsld_KwpTimerServerType Dcm_DsldKwpReqTiming_st;

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/**
 **************************************************************************************************
 * Dcm_GetKwpTimingValues : API to get the different set of timings
 * \param           TimerMode (in): Mode of timing
 *                  TimerServerCurrent (out) : Pointer to structure where timings are written by DCM
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void Dcm_GetKwpTimingValues(Dcm_TimerModeType TimerMode, Dcm_Dsld_KwpTimerServerType * TimerServerCurrent)
{
    uint8 idxLimitTmg_u8;
    const Dcm_DslProtocolRowConfigType_tst * protocol_table_pcs; /* Pointer to protocol table */
    PduIdType rxPduId;
    rxPduId = Dcm_Prv_GetActiveRxPduId();
    protocol_table_pcs = Dcm_Prv_GetProtocolRow(rxPduId);

    if(TimerServerCurrent != NULL_PTR)
    {
        /* Get the index of the limit of timing structure */
        idxLimitTmg_u8 = protocol_table_pcs->timings_limit_idx_u8;

        if(TimerMode == DCM_CURRENT)
        {
            /* Fill the running P2 max and P3 max time */
            /* BSWEXT-533 */
            SchM_Enter_Dcm_DsldTimer();
            TimerServerCurrent-> P2_max_u32 = Dcm_DsldTimer_st.dataTimeoutP2max_u32;
            TimerServerCurrent-> P3_max_u32 = Dcm_DsldTimer_st.dataTimeoutP3max_u32;
            /* BSWEXT-533 */
            SchM_Exit_Dcm_DsldTimer();
        }
        else
        {
            /* Fill the limit P2 max and limit P3 max time */
            TimerServerCurrent-> P2_max_u32 = Dcm_Dsld_Limit_timings_acs[idxLimitTmg_u8].P2_max_u32;
            TimerServerCurrent-> P3_max_u32 = Dcm_Dsld_Limit_timings_acs[idxLimitTmg_u8].P3_max_u32;
        }
    }
    else
    {
        /* Report development error "DCM_E_PARAM_POINTER " to DET module if the DET module is enabled */
        Dcm_Prv_Det(DCM_KWPTIMING_ID , DCM_E_PARAM_POINTER );
    }
}

/**
 **************************************************************************************************
 * Dcm_PrepareKwpTimingValues : API to validate the given set of timings
 * \param           TimerServerNew (in): Pointer to structure which timings to be validated.
 *
 * \retval          DCM_E_OK: preparation successful,
 *                  DCM_E_TI_PREPARE_LIMITS: requested values are not within the defined limits
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
Dcm_StatusType Dcm_PrepareKwpTimingValues(const Dcm_Dsld_KwpTimerServerType * TimerServerNew)
{
    uint8 idxLimitTmg_u8;
    Dcm_StatusType dataReturnValue_u8;
    const Dcm_DslProtocolRowConfigType_tst * protocol_table_pcs; /* Pointer to protocol table */
    PduIdType rxPduId = Dcm_Prv_GetActiveRxPduId();
    protocol_table_pcs = Dcm_Prv_GetProtocolRow(rxPduId);

    /* By default made return value as out of limit */
    dataReturnValue_u8 = DCM_E_TI_PREPARE_LIMITS;

    if(TimerServerNew != NULL_PTR)
    {
        /* Get the index of the default timing structure */
        idxLimitTmg_u8 = protocol_table_pcs->timings_limit_idx_u8;

        /* Validate the timings. Given P2 max should be less than configured limit P2 max and Given P3 max */
        /* should be less than configured limit P3 max                                                    */
        if( (TimerServerNew->P2_max_u32 <= Dcm_Dsld_Limit_timings_acs[idxLimitTmg_u8].P2_max_u32)
             && (TimerServerNew->P3_max_u32 <= Dcm_Dsld_Limit_timings_acs[idxLimitTmg_u8].P3_max_u32))
        {
            /* Store the given validated timings in RAM variable */
            /* Dcm_SetKwpTimingValues can read these values, it may be required to read both P2, P3 without any data inconsistency */
            /* BSWEXT-533 */
            SchM_Enter_Dcm_DsldTimer();
            Dcm_DsldKwpReqTiming_st.P2_max_u32 = TimerServerNew-> P2_max_u32;
            Dcm_DsldKwpReqTiming_st.P3_max_u32 = TimerServerNew-> P3_max_u32;
            /* BSWEXT-533 */
            SchM_Exit_Dcm_DsldTimer();

            /* validation successfully completed */
            dataReturnValue_u8 = E_OK;
        }
    }
    return(dataReturnValue_u8);
}


/**
 **************************************************************************************************
 * Dcm_SetKwpDefaultTimingValues : API to Set the default timings
 * \param           None
 *
 * \retval          None
 *
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void Dcm_SetKwpDefaultTimingValues(void)
{
    uint8 idxDefaultTmg_u8;
    const Dcm_DslProtocolRowConfigType_tst * protocol_table_pcs; /* Pointer to protocol table */
    PduIdType rxPduId = Dcm_Prv_GetActiveRxPduId();
    protocol_table_pcs = Dcm_Prv_GetProtocolRow(rxPduId);

    /* This API is allowed only for KWP */
    /*Check if the return value is TRUE*/
    if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
    {
        /* Get the index of the default of timing structure */
        idxDefaultTmg_u8 = protocol_table_pcs->timings_idx_u8;;

        /* To maintain consistency between P2MAX, P3MAX and P2StarMax */
        /* BSWEXT-533 */
        SchM_Enter_Dcm_DsldTimer();

        /* Set the default timings from configured default time */
        Dcm_DsldTimer_st.dataTimeoutP2max_u32 = Dcm_Dsld_default_timings_acs[idxDefaultTmg_u8].P2_max_u32;
        Dcm_DsldTimer_st.dataTimeoutP3max_u32 = Dcm_Dsld_default_timings_acs[idxDefaultTmg_u8].P3_max_u32;
        /* For KWP P2* max is equal to P3 max */
        Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 = Dcm_DsldTimer_st.dataTimeoutP3max_u32;

        /* BSWEXT-500 */
        /* [$DD_BSWCODE 40605] */
        SchM_Exit_Dcm_DsldTimer();

        /* Old P3 max is getting monitored now. Change this to new P3 max */
        DCM_TimerSetNew(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32,Dcm_DsldTimer_st.dataTimeoutP3max_u32)
    }
}


/**
 **************************************************************************************************
 * Dcm_SetKwpTimingValues : API to Set the given set of timings
 * \param           None
 *
 * \retval          None
 *
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
void Dcm_SetKwpTimingValues (void)
{
    /* This API is allowed only for KWP */
    /*If the return value is TRUE*/
    if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
    {
        /* Set the previously stored timings */
        /* Dcm_PrepareKwpTimingValues can update these values in parallel */
        /* BSWEXT-533 */
        SchM_Enter_Dcm_DsldTimer();

        Dcm_DsldTimer_st.dataTimeoutP2max_u32 = Dcm_DsldKwpReqTiming_st.P2_max_u32;
        Dcm_DsldTimer_st.dataTimeoutP3max_u32 = Dcm_DsldKwpReqTiming_st.P3_max_u32;
        /* for KWP P2* max is equal to P3 max */
        Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 = Dcm_DsldTimer_st.dataTimeoutP3max_u32;

        /* BSWEXT-500 */
        /* [$DD_BSWCODE 40606] */
        SchM_Exit_Dcm_DsldTimer();

        /* Old P3 max is getting monitored now. Change this to new P3 max */
        DCM_TimerSetNew(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32,Dcm_DsldTimer_st.dataTimeoutP3max_u32)
    }
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

