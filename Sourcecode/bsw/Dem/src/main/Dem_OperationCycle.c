
#include "Dem_Internal.h"
#include "Rte_Dem.h"

#include "Dem_OperationCycle.h"
#include "Dem_Events.h"
#include "Dem_Main.h"
#include "Dem_Lock.h"
#include "Dem_Mapping.h"
#include "Dem_EventStatus.h"
#include "Dem_ISO14229Byte.h"
#include "Dem_EvMem.h"
#include "Dem_EventRecheck.h"
#include "Dem_Obd.h"
#include "Dem_GenericNvData.h"
#if (DEM_CFG_OBD == DEM_CFG_OBD_ON)
#include "rba_DemObdBasic_Cfg_Main.h"
#endif

#include "Dem_Bfm.h"

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

static Dem_OperationCycleList Dem_OperationCycleQualified;
static Dem_OperationCycleList Dem_QualifyCycleCollectedTriggers;
static Dem_OperationCycleList Dem_RestartOperationCycleCollectedTriggers;

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

static boolean Dem_IsOperationCycleIdValid(uint8 OperationCycleId)
{
    return (OperationCycleId < DEM_OPERATIONCYCLE_COUNT);
}

static void Dem_OperationCycleTriggerNvmStorage(void)
{
    if (Dem_LibGetParamBool(DEM_CFG_OPERATIONCYCLESTATUSSTORAGE))
    {
        DEM_ENTERLOCK_MON();
        Dem_GenericNvData.OperationCycleQualified = Dem_OperationCycleQualified;

        /* notify to store in NVM */
        Dem_NvMWriteBlockOnShutdown(DEM_NVM_ID_DEM_GENERIC_NV_DATA);
        DEM_EXITLOCK_MON();
    }
}

Std_ReturnType Dem_GetCycleQualified(uint8 OperationCycleId, boolean* isQualified)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (!Dem_IsOperationCycleIdValid(OperationCycleId))
    {
        DEM_DET(DEM_DET_APIID_GETCYCLEQUALIFIED, DEM_E_WRONG_CONFIGURATION,0u);
    }
    else
    {
        *isQualified = DEM_OPERATIONCYCLE_ISBITSET(Dem_OperationCycleQualified, OperationCycleId);
        retVal = E_OK;
    }

    return retVal;
}

Std_ReturnType Dem_SetCycleQualified(uint8 OperationCycleId)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (!Dem_IsOperationCycleIdValid(OperationCycleId))
    {
        DEM_DET(DEM_DET_APIID_SETCYCLEQUALIFIED, DEM_E_WRONG_CONFIGURATION,0u);
    }
    else
    {
        DEM_ENTERLOCK_MON();
#if (DEM_CFG_OBD != DEM_CFG_OBD_OFF)
        /* Check WUC Condition is still not met in this DCY */
        if(!(DEM_OPERATIONCYCLE_ISBITSET(Dem_OperationCycleQualified, DEM_OPCYC_OBD_WarmUpCycle)))
        {
            rba_DemObdBasic_SetCycleQualified(OperationCycleId);
        }
#endif
        DEM_OPERATIONCYCLE_SETBIT(&Dem_OperationCycleQualified, OperationCycleId);
        DEM_OPERATIONCYCLE_SETBIT(&Dem_QualifyCycleCollectedTriggers, OperationCycleId);

        DEM_EXITLOCK_MON();

        retVal = E_OK;
    }

    return retVal;
}

Std_ReturnType Dem_ResetCycleQualified(uint8 OperationCycleId)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (!Dem_IsOperationCycleIdValid(OperationCycleId))
    {
        DEM_DET(DEM_DET_APIID_RESETCYCLEQUALIFIED, DEM_E_WRONG_CONFIGURATION,0u);
    }
    else
    {
        DEM_ENTERLOCK_MON();
        DEM_OPERATIONCYCLE_CLEARBIT(&Dem_OperationCycleQualified, OperationCycleId);
        DEM_OPERATIONCYCLE_CLEARBIT(&Dem_QualifyCycleCollectedTriggers, OperationCycleId);
        DEM_EXITLOCK_MON();

        Dem_OperationCycleTriggerNvmStorage();
        retVal = E_OK;
    }
    return retVal;
}

/* HIS METRIC PATH VIOLATION IN Dem_RestartOperationCycle: Analysis of received payload can not be avoided */
Std_ReturnType Dem_RestartOperationCycle( uint8 OperationCycleId )
{
    Std_ReturnType retVal = E_OK;
    Dem_OperationCycleList bitMaskOld = 0;
    Dem_OperationCycleList bitMask = 0;
    Dem_OperationCycleList bitMaskDependent = 0;
    uint8 cycleId;

    DEM_ENTRY_CONDITION_CHECK_DEM_PREINITIALIZED(DEM_DET_APIID_DEM_RESTARTOPERATIONCYCLE,E_NOT_OK);

    if (!Dem_IsOperationCycleIdValid(OperationCycleId))
    {
        DEM_DET(DEM_DET_APIID_DEM_RESTARTOPERATIONCYCLE, DEM_E_WRONG_CONFIGURATION,0u);
        DEM_ASSERT_ISNOTLOCKED();
        return E_NOT_OK;
    }

    /* A dependent cycle is only allowed to be started, if it is configured as "" */
    if (!Dem_Cfg_OperationCycle_GetIsAllowedToBeStartedDirectly(OperationCycleId))
    {

        DEM_ASSERT_ISNOTLOCKED();
        return E_NOT_OK;
    }

    DEM_ENTERLOCK_MON();

    DEM_OPERATIONCYCLE_SETBIT(&bitMask, OperationCycleId);

    do
    {
        /* Save current bitmask to see if any new dependent cycles were added */
        bitMaskOld = bitMask;

        for (cycleId = 0; cycleId < DEM_OPERATIONCYCLE_COUNT; cycleId++)
        {
            /* Either bitMaskOld or bitMask can be checked here.
             * But with bitMask we are maybe faster, since new cycles added could also be checked in the same iteration */
            if (DEM_OPERATIONCYCLE_ISBITSET(bitMask, cycleId))
            {
                bitMaskDependent = Dem_Cfg_OperationCycle_GetDependentCycleMask(cycleId);

                /* Filter cycles, only which are qualified must be started */
                DEM_OPERATIONCYCLE_MERGEBITMASK(&bitMaskDependent, Dem_OperationCycleQualified);

                /* Add new bitmask to existing one */
                DEM_OPERATIONCYCLE_SETBITMASK(&bitMask, bitMaskDependent);
            }
        }

    } while (bitMaskOld != bitMask); /* Bitmask changed? */

    /* Start all dependent qualified cycles */
    DEM_OPERATIONCYCLE_SETBITMASK(&Dem_RestartOperationCycleCollectedTriggers, bitMask);

    /* Reset qualified flag of these dependent cycles */
    DEM_OPERATIONCYCLE_CLEARBITMASK(&Dem_OperationCycleQualified, bitMask);
    DEM_OPERATIONCYCLE_CLEARBITMASK(&Dem_QualifyCycleCollectedTriggers, bitMask);

    DEM_EXITLOCK_MON();
    return retVal;
}

boolean Dem_OperationCyclesMainFunction(void)
{
    boolean retVal = FALSE;
    /* Local copies to be taken under lock */
    Dem_OperationCycleList opCycleStartTriggers;
#if (DEM_CFG_OBD != DEM_CFG_OBD_OFF)
    Dem_OperationCycleList opCycleQualifiedTriggers;
#endif

    if ((Dem_RestartOperationCycleCollectedTriggers != 0u) || (Dem_QualifyCycleCollectedTriggers != 0u))
    {
        DEM_ENTERLOCK_MON();
        opCycleStartTriggers = Dem_RestartOperationCycleCollectedTriggers;
#if (DEM_CFG_OBD != DEM_CFG_OBD_OFF)
        opCycleQualifiedTriggers = Dem_QualifyCycleCollectedTriggers;
#endif
        Dem_RestartOperationCycleCollectedTriggers = 0u;
        Dem_QualifyCycleCollectedTriggers = 0u;
        DEM_EXITLOCK_MON();

#if (DEM_CFG_OBD != DEM_CFG_OBD_OFF)
        /* check mil state before update of event status to get the state from last driving cycle! */
        rba_DemObdBasic_StartOperationCycle(opCycleStartTriggers, opCycleQualifiedTriggers);
#endif
        /* FC_VariationPoint_START */
#if( DEM_BFM_ENABLED == DEM_BFM_ON )
        rba_DemBfm_CounterAdvanceOperationCycle( opCycleStartTriggers );
#endif
        /* FC_VariationPoint_END */
        Dem_EvMemStartOperationCycleAllMem(opCycleStartTriggers);
        Dem_EvtAdvanceOperationCycle(opCycleStartTriggers);

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
        Dem_ComponentAdvanceOperationCycle(opCycleStartTriggers);
#endif

        Dem_RecheckComponentNotRecoverableRequest();

        /* trigger NvM storage */
        Dem_OperationCycleTriggerNvmStorage();

        retVal = TRUE;
    }

    return retVal;
}

void Dem_OperationCycleInit(void)
{
    /* Do processing of operation cycle states immediately in init, to have TestComplete set  */
    (void) Dem_OperationCyclesMainFunction();
}

void Dem_OperationCycleInitCheckNvm(void)
{
    if (Dem_LibGetParamBool(DEM_CFG_OPERATIONCYCLESTATUSSTORAGE))
    {
        /* get the Result of the NvM-Read (NvM_ReadAll) */

        if (DEM_NVM_SUCCESS == Dem_NvmGetStatus (DEM_NVM_ID_DEM_GENERIC_NV_DATA))
        {
            DEM_ENTERLOCK_MON();
            Dem_OperationCycleQualified |= Dem_GenericNvData.OperationCycleQualified;
            DEM_EXITLOCK_MON();
        }
        else
        {
            DEM_ENTERLOCK_MON();
            DEM_OPERATIONCYCLE_CLEARBITMASK(&Dem_OperationCycleQualified, DEM_OPERATIONCYCLE_ALL_BITMASK);
            DEM_EXITLOCK_MON();
        }
    }
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
