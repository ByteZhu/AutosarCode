
/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"
#include "Dcm_Prv_Types.h"
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
static Dcm_AuthDefaultSessionIdleTimerInfoType_tst Dcm_AuthDefaultSessionIdleTimer_ast[DCM_CFG_AUTH_NUM_CONNECTION];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"


void Dcm_Prv_AuthTimerIni(void)
{
    uint8_least connIdx_qu8;

    if(Dcm_Cfg_AuthDefaultSessionTimeout_pu32 != NULL_PTR)
    {
        for(connIdx_qu8 = 0;connIdx_qu8 < DCM_CFG_AUTH_NUM_CONNECTION;connIdx_qu8++)
        {
            Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_qu8].isTimerActive_b = FALSE;
            Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_qu8].startTick_u32 =0x00u;
            Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_qu8].timerCounterStatus = 0x00u;
            Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_qu8].timer_u32 = 0x00u;

        }
    }
}


static void Dcm_AuthTimerStart(uint16 authConnectionIndex_u16)
{
    Dcm_SesCtrlType activeSession;

    if(authConnectionIndex_u16 < DCM_CFG_AUTH_NUM_CONNECTION)
    {
        if(Dcm_Cfg_AuthDefaultSessionTimeout_pu32 != NULL_PTR)
        {
            DCM_TimerStart(Dcm_AuthDefaultSessionIdleTimer_ast[authConnectionIndex_u16].timer_u32,
                    *Dcm_Cfg_AuthDefaultSessionTimeout_pu32,
                    Dcm_AuthDefaultSessionIdleTimer_ast[authConnectionIndex_u16].startTick_u32,
                    Dcm_AuthDefaultSessionIdleTimer_ast[authConnectionIndex_u16].timerCounterStatus)

            (void)Dcm_GetSesCtrlType(&activeSession);

            if((DCM_AUTHENTICATED == Dcm_Prv_GetAuthState(authConnectionIndex_u16)) &&
                    (activeSession == DCM_DEFAULT_SESSION))
            {
                Dcm_AuthDefaultSessionIdleTimer_ast[authConnectionIndex_u16].isTimerActive_b = TRUE;
            }
            else
            {
                Dcm_AuthDefaultSessionIdleTimer_ast[authConnectionIndex_u16].isTimerActive_b = FALSE;
            }
        }
    }
}


static void Dcm_AuthTimerProcess(void)
{
    uint16 connIdx_u16;

    for(connIdx_u16 = 0; connIdx_u16 < DCM_CFG_AUTH_NUM_CONNECTION; connIdx_u16++)
    {
        if(Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_u16].isTimerActive_b == TRUE)
        {
            if(DCM_TimerElapsed(Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_u16].timer_u32))
            {
              Dcm_Prv_ResetAccessRights(connIdx_u16);
              Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_u16].isTimerActive_b = FALSE;
            }
            else
            {
                DCM_TimerProcess(Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_u16].timer_u32,
                        Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_u16].startTick_u32,
                        Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_u16].timerCounterStatus)
            }
        }
    }

}


static void Dcm_AuthTimerStop(uint16 authConnectionIndex_u16)
{
    if(Dcm_Cfg_AuthDefaultSessionTimeout_pu32 != NULL_PTR)
    {
       Dcm_AuthDefaultSessionIdleTimer_ast[authConnectionIndex_u16].isTimerActive_b = FALSE;
    }
}


void Dcm_Prv_AuthS3ServerTimeout(void)
{
    uint16 connIdx_u16;

    for(connIdx_u16 = 0; connIdx_u16 < DCM_CFG_AUTH_NUM_CONNECTION; connIdx_u16++)
    {
        if(Dcm_AuthDefaultSessionIdleTimer_ast[connIdx_u16].isTimerActive_b == FALSE)
        {
            if(DCM_AUTHENTICATED == Dcm_Prv_GetAuthState(connIdx_u16))
            {
                Dcm_Prv_ResetAccessRights(connIdx_u16);
            }
        }
    }
}


void Dcm_Prv_AuthTimerHandling(Dcm_TimerActionType_ten timerAction_en, PduIdType dcmRxPduId)
{
    uint16 authConnectionIndex_u16=0;

    /*Get authenticationIndex only during start and stop of timer*/
    if((timerAction_en == DCM_TIMER_START) || (timerAction_en == DCM_TIMER_STOP))
    {
        if(E_OK == Dcm_Prv_GetAuthConnectionIndex(dcmRxPduId,&authConnectionIndex_u16))
        {
            if(timerAction_en == DCM_TIMER_START)
            {
                Dcm_AuthTimerStart(authConnectionIndex_u16);
            }
            else
            {
                Dcm_AuthTimerStop(authConnectionIndex_u16);
            }
        }
    }
    else if(timerAction_en == DCM_TIMER_PROCESS)
    {
        Dcm_AuthTimerProcess();
    }
    else
    {
        //Do nothing.Must never reach(Misra)
    }
}


#endif
