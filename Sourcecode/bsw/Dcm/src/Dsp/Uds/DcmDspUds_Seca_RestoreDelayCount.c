#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF))
#include "Rte_Dcm.h"
#include "DcmDspUds_Seca_Inf.h"
#include "Dcm_Prv.h"
#if (DCM_CFG_DSP_SECA_ATTEMPT_COUNTER!=DCM_CFG_OFF)
#include "DcmDspUds_Seca_Prv.h"

#if(DCM_CFG_DSP_SECA_ATTEMPT_COUNTER!=DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
uint8 Dcm_GetattemptCounterWaitCycle_u8;/*The counter for wait cycles of  GetSecurityAttemptCounter*/
/*if any of the getAttemptCounter API returned PENDING,then corresponding element in the array will be set to one*/
static uint8 waitRequestedIdx_qu8[DCM_CFG_DSP_NUMSECURITY];
static Std_ReturnType dataRetValue_u8;
static uint8 attemptCounter_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
/* Flag to indicate whether any of the getAttemptCounter API returned PENDING*/
static boolean waitRequested_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


/**
 ***********************************************************************************************************************
 * Dcm_Prv_SecaGetattemptCounterCheck : Function to check GetAttemptCounter API return value
 *                                    TRUE: increment the wait counter value
 *                                    FALSE: Initialization of PowerOn delay timer for all security levels configured
 *                                           And set the wait counter value as the maximum wait cycle value +1
 * \param           None
 *
 * \retval          None
 ***********************************************************************************************************************
 */
static void Dcm_Prv_SecaGetattemptCounterCheck(void)
{
    /*Check if any of the GetAttemptCounter API returned PENDING ,then increment the wait counter value.*/
    if(waitRequested_b != FALSE)
    {
        Dcm_GetattemptCounterWaitCycle_u8++ ;
    }
    else
    {
        /*Initialization of PowerOn delay timer for all security levels configured*/
        Dcm_Dsp_SecaPowerOnDelayIni();
        /*if none of the GetAttemptCounter API returned PENDING ,then set the wait counter value as the maximum
         *wait cycle value +1, so that in the next main function call GetAttemptcounter won't be called.*/
        Dcm_GetattemptCounterWaitCycle_u8 = ((DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME)+1u);
    }
}
/**
 ***********************************************************************************************************************
 * Dcm_Prv_GetattemptCounterWaitCycleExhaused : Wait cycle counter Dcm_GetattemptCounterWaitCycle_u8 is exhausted ,
 *                                            therefore cancel all the PENDING GetAttemptCounter APIs
 *
 * \param           None
 *
 * \retval          None
 ***********************************************************************************************************************
 */
static void Dcm_Prv_GetattemptCounterWaitCycleExhaused(void)
{
    uint8_least l_idxSeca_qu8;      /* Local Index to loop the security table */
    /* cancel all the PENDING GetAttemptCounter APIs*/
    for(l_idxSeca_qu8 = 0x0; l_idxSeca_qu8 < DCM_CFG_DSP_NUMSECURITY; l_idxSeca_qu8++)
    {
        if ((Dcm_Dsp_Security[l_idxSeca_qu8].Dsp_GetAttempCounter_fp!=NULL_PTR)&&
        (waitRequestedIdx_qu8[l_idxSeca_qu8] != 0))
        {
            Dcm_Dsp_Seca[l_idxSeca_qu8].FailedAtm_cnt_u8 = Dcm_Dsp_Security[l_idxSeca_qu8].NumAttDelay_u8;
#if (DCM_CFG_DSP_SECA_ASP_ENABLED != DCM_CFG_OFF)
            if(Dcm_Dsp_Security[l_idxSeca_qu8].UseAsynchronousServerCallPoint_b)
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                 * Required for efficient RAM usage by using single void function pointer */
                dataRetValue_u8 = (*(Dcm_GetSecurityAttemptCounter1_pfct)
                (Dcm_Dsp_Security[l_idxSeca_qu8].Dsp_GetAttempCounter_fp))(DCM_CANCEL);
            }
            else
#endif
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                Required for efficient RAM usage by using single void function pointer */
                dataRetValue_u8 = (*(Dcm_GetSecurityAttemptCounter_pfct)
                (Dcm_Dsp_Security[l_idxSeca_qu8].Dsp_GetAttempCounter_fp))(DCM_CANCEL,&attemptCounter_u8);
            }
        }
    }
}
/**
 ***********************************************************************************************************************
 * Dcm_Prv_SecaDelayCountRead : Restore delay count value for configured security level
 *
 * \param           None
 *
 * \retval          None
 ***********************************************************************************************************************
 */
static void Dcm_Prv_SecaDelayCountRead(void)
{
    static  uint8_least idxSeca_qu8;      /* Index to loop the security table */

    /* Loop for all the security levels configured in SECA service */
    for(idxSeca_qu8 = 0x0; idxSeca_qu8 < DCM_CFG_DSP_NUMSECURITY; idxSeca_qu8++)
    {
        if (Dcm_Dsp_Security[idxSeca_qu8].Dsp_GetAttempCounter_fp!=NULL_PTR)
        {
#if (DCM_CFG_DSP_SECA_ASP_ENABLED != DCM_CFG_OFF)
            if(Dcm_Dsp_Security[idxSeca_qu8].UseAsynchronousServerCallPoint_b)
            {
                if(waitRequestedIdx_qu8[idxSeca_qu8] == DCM_GETATTEMPTCNTR_INITIAL)
                {
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                     * Required for efficient RAM usage by using single void function pointer */
                    /* Call the application  API to restore the Delay count values from NVM */
                    dataRetValue_u8 = (*(Dcm_GetSecurityAttemptCounter1_pfct)
                            (Dcm_Dsp_Security[idxSeca_qu8].Dsp_GetAttempCounter_fp))(DCM_INITIAL);
                    if (dataRetValue_u8 == RTE_E_OK)
                    {
                        waitRequested_b =TRUE;
                        dataRetValue_u8 = DCM_E_PENDING;
                        waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_RESULTPENDING;
                    }
                    else
                    {
                        dataRetValue_u8 = E_NOT_OK;
                        /*Assign failed attempt counter with the configuration paramenter DcmDspSecurityNumAttDelay */
                        Dcm_Dsp_Seca[idxSeca_qu8].FailedAtm_cnt_u8 = Dcm_Dsp_Security[idxSeca_qu8].NumAttDelay_u8;

                    }
                }
                else
                {
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                     * Required for efficient RAM usage by using single void function pointer */
                    dataRetValue_u8 = (*(Dcm_GetSecurityAttemptCounter2_pfct)
                            (Dcm_Dsp_Security[idxSeca_qu8].Dsp_GetAttempCounter_Resultfp))(&attemptCounter_u8);
                    if (dataRetValue_u8 == RTE_E_OK)
                    {
                        dataRetValue_u8 = E_OK;
                        /*The API returned successfully,update the counter value */
                        Dcm_Dsp_Seca[idxSeca_qu8].FailedAtm_cnt_u8 = attemptCounter_u8;
                        /*Reset the status array value  corresponding to the security level which will indicate that
                          the API GetAttemptcouner not in the PENDING state currently  */
                        waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_INITIAL;
                    }
                    else if(dataRetValue_u8 == RTE_E_NO_DATA)
                    {
                        waitRequested_b =TRUE;
                        /*Rte_Result to be called again in the next cycle*/
                        dataRetValue_u8 = DCM_E_PENDING;
                    }
                    else if(dataRetValue_u8 == DCM_E_PENDING)
                    {
                        waitRequested_b =TRUE;
                        /*Reset status to Initial to invoke RTE_Call for this index once again*/
                        waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_INITIAL;
                    }
                    else
                    {
                        dataRetValue_u8 = E_NOT_OK;
                        /*Assign failed attempt counter with the configuration paramenter DcmDspSecurityNumAttDelay */
                        Dcm_Dsp_Seca[idxSeca_qu8].FailedAtm_cnt_u8 = Dcm_Dsp_Security[idxSeca_qu8].NumAttDelay_u8;
                        /*Reset the status array value  corresponding to the security level which will indicate that
                          the API GetAttemptcouner not in the PENDING state currently  */
                        waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_INITIAL;
                    }
                }
            }
            else
#endif
            {
                if(waitRequestedIdx_qu8[idxSeca_qu8] != DCM_GETATTEMPTCNTR_INITIAL)
                {
                    /* Call the application  API to restore the Delay count values from NVM */
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                    Required for efficient RAM usage by using single void function pointer */
                    dataRetValue_u8 = (*(Dcm_GetSecurityAttemptCounter_pfct)
                    (Dcm_Dsp_Security[idxSeca_qu8].Dsp_GetAttempCounter_fp))(DCM_PENDING,&attemptCounter_u8);
                }
                else
                {
                    /* If the GetAttemptCounter is getting called for the first time ,
                       then call the API with opstatus set to DCM_INITIAL*/
                    /* Call the application  API to restore the Delay count values from NVM */
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                    Required for efficient RAM usage by using single void function pointer */
                    dataRetValue_u8 = (*(Dcm_GetSecurityAttemptCounter_pfct)
                    (Dcm_Dsp_Security[idxSeca_qu8].Dsp_GetAttempCounter_fp))(DCM_INITIAL,&attemptCounter_u8);
                }


            switch(dataRetValue_u8)
            {
                case E_OK:
                {
                   /*The API returned successfully,update the counter value */
                   Dcm_Dsp_Seca[idxSeca_qu8].FailedAtm_cnt_u8 = attemptCounter_u8;
                   /*Reset the status array value  corresponding to the security level which will indicate that
                   the API GetAttemptcouner not in the PENDING state currently  */
                   waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_INITIAL;
                }
                break;

                case DCM_E_PENDING:
                {
                   waitRequested_b =TRUE;
                   /*Set the status array value to 1 corresponding to the security level which will indicate that
                   the API GetAttemptcouner in the PENDING state currently  */
                   waitRequestedIdx_qu8[idxSeca_qu8] = DCM_GETATTEMPTCNTR_RESULTPENDING;
                }
                break;

                case E_NOT_OK:
                {
                    /*Assign failed attempt counter with the configuration paramenter DcmDspSecurityNumAttDelay */
                    Dcm_Dsp_Seca[idxSeca_qu8].FailedAtm_cnt_u8 = Dcm_Dsp_Security[idxSeca_qu8].NumAttDelay_u8;
                    /*Reset the status array value  corresponding to the security level which will indicate that
                   the API GetAttemptcouner not in the PENDING state currently  */
                    waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_INITIAL;
                }
                break;

                default:

                {


                    Dcm_Dsp_Seca[idxSeca_qu8].FailedAtm_cnt_u8 =0;
                    waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_INITIAL;
                }
                break;
            }
            }
        }
        else
        {
            /* Assign failed attempt counter to zero to indicate no incorrect attempts have been made*/
            Dcm_Dsp_Seca[idxSeca_qu8].FailedAtm_cnt_u8 = 0u;
            /*Reset the status array value  corresponding to the security level which will indicate that
            * the API GetAttemptcouner not in the PENDING state currently  */
            waitRequestedIdx_qu8[idxSeca_qu8]=DCM_GETATTEMPTCNTR_INITIAL;
        }
    }
}
/**
 ***********************************************************************************************************************
 * Dcm_Dsp_RestoreDelayCount : Function for restoring the Delay count values for each security
 *                             level configured in Security Access service.
 *
 * \param           None
 *
 * \retval          None
************************************************************************************************************************
 */
void Dcm_Dsp_RestoreDelayCount(void)
{
    dataRetValue_u8 =E_NOT_OK;
    waitRequested_b=FALSE;

    /*Check if the wait cycle counter for Get attempt counter is exhausted*/
    if(Dcm_GetattemptCounterWaitCycle_u8 < DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME)
    {
        /* Restore delay count value for configured security level */
        Dcm_Prv_SecaDelayCountRead();
        /* Function to check GetAttemptCounter API return value */
        Dcm_Prv_SecaGetattemptCounterCheck();
    }
    else
    {
        /*Wait cycle counter Dcm_GetattemptCounterWaitCycle_u8 is exhausted ,
        * therefore cancel all the PENDING GetAttemptCounter APIs*/
        Dcm_Prv_GetattemptCounterWaitCycleExhaused();
        /*Initialization of PowerOn delay timer for all security levels configured*/
        Dcm_Dsp_SecaPowerOnDelayIni();
        /*Set the wait counter value as the maximum wait cycle value +1*/
        Dcm_GetattemptCounterWaitCycle_u8++;
    }
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif /* (DCM_CFG_DSP_SECA_ATTEMPT_COUNTER!=DCM_CFG_OFF) */
#endif /*(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF) */

