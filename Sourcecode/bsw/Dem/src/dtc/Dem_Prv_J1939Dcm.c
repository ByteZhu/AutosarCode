

#include "Dem_J1939Dcm.h"

#include "Dem_Prv_J1939Dcm.h"
#include "Dem_Types.h"
#include "Dem_Clear.h"
#include "Dem_Nvm.h"
#include "Dem_Dependencies.h"
#include "Dem_StorageCondition.h"
#include "Dem_ISO14229Byte.h"
#include "Dem_Events.h"
#include "Dem_DTCs.h"
#include "Dem_EvMemBase.h"
#include "Dem_EvMem.h"
#include "Dem_Cfg_EvMem.h"
#include "Dem_J1939EnvFreezeFrame.h"


#if(DEM_CFG_J1939DCM != DEM_CFG_J1939DCM_OFF)

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"
#if (DEM_CFG_J1939DCM_READ_DTC_SUPPORT)
    Dem_J1939DcmDTCFilterState Dem_J1939DcmDTCFilter;
    DEM_BITARRAY_DEFINE(Dem_J1939DcmDTCFilterMatching, DEM_DTCID_ARRAYLENGTH);
#endif

#if (DEM_CFG_J1939DCM_DM31_SUPPORT)
    Dem_J1939DcmDTCRetrieveState Dem_J1939DcmDTCRetrieve;
#endif

#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)
    Dem_J1939FreezeFrameFilterState Dem_J1939FreezeFrameFilter;
    static uint16_least Dem_J1939FreezeFrameFilterLocId;
#endif
#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
/* MR12 RULE 20.7 VIOLATION: Due to the fact that array content and array size are both generated based on the same input it is ensured that the data always fit in to the array */
DEM_ARRAY_DEFINE_CONST(Dem_J1939DtcParam32, Dem_AllJ1939DTCsParam32, DEM_DTCID_ARRAYLENGTH, DEM_CFG_J1939DTCPARAMS32);
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"


uint8 Dem_J1939GetOccurrenceCounterByDtcId(Dem_DtcIdType dtcId)
{
    uint16_least LocId;
    Dem_EventIdListIterator eventIt;
    Dem_EventIdType eventId;
    uint8 occurrenceCounter = 0, maxOccurrenceCounter = 0;

    for (Dem_EventIdListIteratorNewFromDtcId(&eventIt, dtcId); Dem_EventIdListIteratorIsValid(&eventIt);
            Dem_EventIdListIteratorNext(&eventIt))
    {
        eventId = Dem_EventIdListIteratorCurrent(&eventIt);
        LocId = Dem_EvMemGetLocationOfEventFromEventMemory(eventId);

        if (Dem_EvMemIsEventMemLocIdValid(LocId))
        {
            maxOccurrenceCounter = (uint8)Dem_EvMemGetEventMemOccurrenceCounter(LocId);
            DEM_A_MAX_AB(occurrenceCounter, maxOccurrenceCounter);
        }
    }

    if (occurrenceCounter > 126)
    {
        // Occurrence Counter value is greter than 126, Provide 126 as occurrence Counter value
        occurrenceCounter = 126;
    }
    else if (occurrenceCounter == 0)
    {
        // Occurrence Counter value is not available, Provide 127 as occurrence Counter value
        occurrenceCounter = 127;
    }
    else
    {
        //To avoid Misra Warning
    }
    return occurrenceCounter;
}

#if (DEM_CFG_EVT_INDICATOR == DEM_CFG_EVT_INDICATOR_ON)
static Dem_IndicatorStatusType Dem_EvtGetIndicatorStatusJ1939DcmLampType(uint8 lampType)
{
    Dem_IndicatorStatusType indicatorStatus = 0u;

    if (lampType == DEM_J1939DCM_MIL_LAMPSTATUS)
    {
        indicatorStatus = Dem_EvtGetIndicatorStatus(DEM_CFG_J1939_MIL);
    }

    if (lampType == DEM_J1939DCM_RED_LAMPSTATUS)
    {
        indicatorStatus = Dem_EvtGetIndicatorStatus(DEM_CFG_J1939_RED_STOP_LAMP);
    }

    if (lampType == DEM_J1939DCM_AMBER_LAMPSTATUS)
    {
        indicatorStatus = Dem_EvtGetIndicatorStatus(DEM_CFG_J1939_AMBER_WARNING_LAMP);
    }

    if (lampType == DEM_J1939DCM_PROTECT_LAMPSTATUS)
    {
        indicatorStatus = Dem_EvtGetIndicatorStatus(DEM_CFG_J1939_PROTECT_LAMP);
    }

    return indicatorStatus;
}

static uint16 Dem_J1939DcmGetLampStatusByLampType(uint8 lampType)
{
    Dem_IndicatorStatusType indicatorStatus;
    uint8 basicValue = 0u;
    uint8 milShiftValue = 0u;
    uint8 redShiftValue = 0u;
    uint8 amberShiftValue = 0u;
    uint8 flashLampStatus = 0u;
    uint16 lampStatus = 0u;

    milShiftValue = 6u;
    redShiftValue = 4u;
    amberShiftValue = 2u;
    /* protectShiftValue = 0u */

    lampStatus = DEM_J1939DCM_MIL_RED_AMBER_PROTECT_OFF;

    indicatorStatus = Dem_EvtGetIndicatorStatusJ1939DcmLampType(lampType);

    if(indicatorStatus != DEM_INDICATOR_OFF)
    {
        if (indicatorStatus == DEM_INDICATOR_SLOW_FLASH)
        {
            basicValue = 0u;
        }
        else if (indicatorStatus == DEM_INDICATOR_FAST_FLASH)
        {
            basicValue = 1u;
        }
        else if (indicatorStatus == DEM_INDICATOR_CONTINUOUS)
        {
            basicValue = 3u;
        }
        else
        {
            //To avoid Misra Warning
        }

        switch (lampType)
        {
            case DEM_J1939DCM_MIL_LAMPSTATUS:
                flashLampStatus = basicValue << milShiftValue;
                break;

            case DEM_J1939DCM_RED_LAMPSTATUS:
                flashLampStatus = basicValue << redShiftValue;
                break;

            case DEM_J1939DCM_AMBER_LAMPSTATUS:
                flashLampStatus = basicValue << amberShiftValue;
                break;

            case DEM_J1939DCM_PROTECT_LAMPSTATUS:
                flashLampStatus = basicValue;
                break;
            default:
                //Nothing to do, just avoid Misra Warning
                break;
        }

        lampStatus = lampType;
        lampStatus = lampStatus << 8;
        lampStatus |= flashLampStatus;
    }
    return lampStatus;
}

Dem_J1939DcmLampStatusType Dem_J1939DcmGetLampStatus(void)
{
    Dem_J1939DcmLampStatusType compositeLampStatus;
    uint16 lampStatusMIL, lampStatusRed, lampStatusAmber, lampStatusProtect, combinedLampStatus;

    compositeLampStatus.LampStatus = DEM_J1939DCM_FLASHLAMP_OFF;
    compositeLampStatus.FlashLampStatus = DEM_J1939DCM_FLASHLAMP_OFF;

    if (Dem_LibGetParamBool(DEM_CFG_J1939_MIL != 0u))
    {
        lampStatusMIL = Dem_J1939DcmGetLampStatusByLampType(DEM_J1939DCM_MIL_LAMPSTATUS);
    }
    else
    {
        lampStatusMIL = DEM_J1939DCM_MIL_OFF;
    }

    if (Dem_LibGetParamBool(DEM_CFG_J1939_RED_STOP_LAMP != 0u))
    {
        lampStatusRed = Dem_J1939DcmGetLampStatusByLampType(DEM_J1939DCM_RED_LAMPSTATUS);
    }
    else
    {
        lampStatusRed = DEM_J1939DCM_RED_OFF;
    }

    if (Dem_LibGetParamBool(DEM_CFG_J1939_AMBER_WARNING_LAMP != 0u))
    {
        lampStatusAmber = Dem_J1939DcmGetLampStatusByLampType(DEM_J1939DCM_AMBER_LAMPSTATUS);
    }
    else
    {
        lampStatusAmber = DEM_J1939DCM_AMBER_OFF;
    }

    if (Dem_LibGetParamBool(DEM_CFG_J1939_PROTECT_LAMP != 0u))
    {
        lampStatusProtect = Dem_J1939DcmGetLampStatusByLampType(DEM_J1939DCM_PROTECT_LAMPSTATUS);
    }
    else
    {
        lampStatusProtect = DEM_J1939DCM_PROTECT_OFF;
    }

    combinedLampStatus = lampStatusMIL | lampStatusAmber | lampStatusRed | lampStatusProtect;

    compositeLampStatus = Dem_SplitJ1939DcmLampStatusType(combinedLampStatus);

    return compositeLampStatus;
}

#endif

#if (DEM_CFG_J1939DCM_READ_DTC_SUPPORT)

static Dem_boolean_least Dem_J1939DcmIsDTCStatusTypeFilterValid(Dem_J1939DcmDTCStatusFilterType DTCStatusFilter)
{
    return ((DTCStatusFilter == DEM_J1939DTC_ACTIVE) || (DTCStatusFilter == DEM_J1939DTC_PREVIOUSLY_ACTIVE)
            || (DTCStatusFilter == DEM_J1939DTC_PENDING) || (DTCStatusFilter == DEM_J1939DTC_CURRENTLY_ACTIVE));
}

static Dem_boolean_least Dem_IsJ1939DcmDTCFiltermatching(Dem_DtcIdType dtcId, Dem_J1939DcmDTCStatusFilterType DTCStatusFilter)
{
    Dem_boolean_least retVal = FALSE;
    Dem_UdsStatusByteType status;

    status = Dem_DtcStatusByteRetrieve(dtcId);

    if (DTCStatusFilter == DEM_J1939DTC_ACTIVE)
    {
        if ((Dem_ISO14229ByteIsTestFailed(status) && Dem_ISO14229ByteIsConfirmedDTC(status))
                || Dem_ISO14229ByteIsWarningIndicatorRequested(status))
        {
            retVal = TRUE;
        }
    }
    else if (DTCStatusFilter == DEM_J1939DTC_PREVIOUSLY_ACTIVE)
    {
        if ((!Dem_ISO14229ByteIsTestFailed(status)) && Dem_ISO14229ByteIsConfirmedDTC(status)
                && (!Dem_ISO14229ByteIsWarningIndicatorRequested(status)))
        {
            retVal = TRUE;
        }
    }
    else if (DTCStatusFilter == DEM_J1939DTC_PENDING)
    {
        if (Dem_ISO14229ByteIsPendingDTC(status))
        {
            retVal = TRUE;
        }
    }
    else if (DTCStatusFilter == DEM_J1939DTC_CURRENTLY_ACTIVE)
    {
        if (Dem_ISO14229ByteIsTestFailed(status))
        {
            retVal = TRUE;
        }
    }
    else
    {
        /* To satisfy misra */
    }
    return retVal;
}

static Dem_boolean_least Dem_J1939DcmDTCFilterMatches(Dem_DtcIdType dtcId)
{
    Dem_boolean_least matches = TRUE;

    if (!(Dem_IsJ1939DcmDTCFiltermatching(dtcId, Dem_J1939DcmDTCFilter.DTCStatusFilter)))
    {
        matches = FALSE;
    }

    if ((matches) && (Dem_J1939DcmDTCFilter.DTCKind != DEM_DTC_KIND_ALL_DTCS))
    {
        matches = (Dem_Cfg_Dtc_GetKind(dtcId) == Dem_J1939DcmDTCFilter.DTCKind);
    }

    return matches;
}

void Dem_J1939DcmDTCFilterMainFunction(void)
{
    const sint32 epc = (sint32)DEM_DTC_FILTER_NUMBER_OF_EVENTS_PER_CYCLE;
    sint32 i = epc;
    Dem_DtcIdListIterator2 searchItCopy;
    Dem_DtcIdType dtcId;
    Dem_boolean_least matches;
    sint32 numberOfEvents;

    DEM_ENTERLOCK_DCM();
    Dem_J1939DcmDTCFilter.isNewFilterCriteria = FALSE;
    searchItCopy = Dem_J1939DcmDTCFilter.searchIt;
    DEM_EXITLOCK_DCM();

    while (i > 0)
    {
        if (Dem_J1939DtcIdListIteratorIsValid(&searchItCopy))
        {
            dtcId = Dem_J1939DtcIdListIteratorCurrent(&searchItCopy);

            if (!Dem_isDtcIdValid(dtcId))
            {
                return;
            }

            if (!Dem_DtcIsSuppressed(dtcId))
            {
                numberOfEvents = (sint32) Dem_DtcIdGetNumberOfEvents(dtcId);
                /* only execute if number of events of current DTC does not exceed the total number of events allowed in this cycle or it is the first DTC in this cycle */
                if ((numberOfEvents > i) && (i != epc))
                {
                    break;
                }
                i = i - numberOfEvents;
                matches = Dem_J1939DcmDTCFilterMatches(dtcId);
            }
            else
            {
                i = i - 1;
                matches = FALSE;
            }

            DEM_ENTERLOCK_DCM();
            if (!Dem_J1939DcmDTCFilter.isNewFilterCriteria)
            {
                if (matches)
                {
                    Dem_BitArraySetBit(Dem_J1939DcmDTCFilterMatching, dtcId);
                    Dem_J1939DcmDTCFilter.numberOfMatchingDTCs++;
                }

                /* advance iterator to next dtcId */
                Dem_J1939DtcIdListIteratorNext(&Dem_J1939DcmDTCFilter.searchIt);
                searchItCopy = Dem_J1939DcmDTCFilter.searchIt;
            }
            else
            {
                i = 0;
            }
            DEM_EXITLOCK_DCM();
        }
        else
        {
            i = 0;
        }
    }
}

void Dem_J1939DcmDtcFilterInit(void)
{
    Dem_J1939DtcIdIteratorDtcIdInvalidate(&Dem_J1939DcmDTCFilter.searchIt);
    Dem_J1939DtcIdIteratorDtcIdInvalidate(&Dem_J1939DcmDTCFilter.retrieveIt);

    Dem_J1939DcmDTCFilter.isNewFilterCriteria = TRUE;
}

Std_ReturnType Dem_J1939DcmSetDTCFilter(Dem_J1939DcmDTCStatusFilterType DTCStatusFilter, Dem_DTCKindType DTCKind,
                                                 Dem_DTCOriginType DTCOrigin, uint8 ClientId,
                                                 Dem_J1939DcmLampStatusType* LampStatus)
{
    Std_ReturnType returnVal = E_OK;
    DEM_ASSERT((LampStatus != NULL_PTR),DEM_DET_APIID_J1939DCMSETDTCFILTER, DEM_E_PARAM_POINTER);
    DEM_ENTERLOCK_DCM();

    /* As there is one clientId for J1939 per event memory set no need to use clientId*/
    if (!Dem_isClientIdValid(ClientId))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMSETDTCFILTER, DEM_E_WRONG_CONFIGURATION,0u);
        returnVal = DEM_WRONG_CLIENTID;
    }

    Dem_J1939DcmDtcFilterInit();

    if (!(Dem_EvMemIsDtcOriginValid(&DTCOrigin) && Dem_J1939DcmIsDTCStatusTypeFilterValid(DTCStatusFilter) && Dem_EvMemIsDtcKindValid(DTCKind)))
    {
        returnVal = E_NOT_OK;
    }

    if (returnVal == E_OK)
    {
        Dem_J1939DcmDTCFilter.DTCStatusFilter = DTCStatusFilter;
        Dem_J1939DcmDTCFilter.DTCKind = DTCKind;
        Dem_J1939DcmDTCFilter.memId = Dem_EvMemGetMemIdForDTCOrigin(DTCOrigin);
        Dem_J1939DcmDTCFilter.numberOfMatchingDTCs = 0;

        Dem_J1939DtcIdListIteratorNewFromJ1939MemID(&Dem_J1939DcmDTCFilter.searchIt, Dem_J1939DcmDTCFilter.memId);
        Dem_J1939DtcIdListIteratorNewFromJ1939MemID(&Dem_J1939DcmDTCFilter.retrieveIt, Dem_J1939DcmDTCFilter.memId);

        Dem_BitArrayClearAll(Dem_J1939DcmDTCFilterMatching, DEM_DTCID_ARRAYLENGTH);
    }

    DEM_EXITLOCK_DCM();

    if (returnVal == E_OK)
    {
#if (DEM_CFG_EVT_INDICATOR != DEM_CFG_EVT_INDICATOR_OFF)
        *LampStatus = Dem_J1939DcmGetLampStatus();
#else
        //  make the lamp status as OFF for invalid case
        *LampStatus = DEM_J1939DCM_MIL_RED_AMBER_PROTECT_OFF;
#endif
    }

    return returnVal;
}

Std_ReturnType Dem_J1939DcmGetNumberOfFilteredDTC(uint16* NumberOfFilteredDTC, uint8 ClientId)
{
    DEM_ASSERT((NumberOfFilteredDTC != NULL_PTR),DEM_DET_APIID_J1939DCMGETNUMBEROFFILTEREDDTC, DEM_E_PARAM_POINTER);

    /* As there is one clientId for J1939 per event memory set no need to use clientId*/
    if (!Dem_isClientIdValid(ClientId))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMGETNUMBEROFFILTEREDDTC, DEM_E_WRONG_CONFIGURATION,0u);
        return DEM_WRONG_CLIENTID;
    }

    if (Dem_J1939DtcIdListIteratorIsValid(&Dem_J1939DcmDTCFilter.searchIt))
    {
        return DEM_PENDING;
    }

    *NumberOfFilteredDTC = Dem_J1939DcmDTCFilter.numberOfMatchingDTCs;
    return E_OK;
}

Std_ReturnType Dem_J1939DcmGetNextFilteredDTC(uint32* J1939DTC,uint8* OccurenceCounter, uint8 ClientId)
{
    Dem_DtcIdType dtcId = 0u;
    uint16_least i = DEM_DTC_FILTER_RETRIEVE_NUMBER_OF_DTCS;

    /* As there is one clientId for J1939 per event memory set no need to use clientId*/
    if (!Dem_isClientIdValid(ClientId))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMGETNEXTFILTEREDDTC, DEM_E_WRONG_CONFIGURATION,0u);
        return DEM_WRONG_CLIENTID;
    }

    DEM_ASSERT(((J1939DTC != NULL_PTR) && (OccurenceCounter != NULL_PTR)),DEM_DET_APIID_J1939DCMGETNEXTFILTEREDDTC, DEM_E_PARAM_POINTER);

    while (i > 0u)
    {
        if (!Dem_J1939DtcIdListIteratorIsValid(&Dem_J1939DcmDTCFilter.retrieveIt))
        {
            return DEM_NO_SUCH_ELEMENT;
        }

        if (Dem_J1939DcmDTCFilter.retrieveIt.it == Dem_J1939DcmDTCFilter.searchIt.it)
        {
            return DEM_PENDING;
        }

        dtcId = Dem_J1939DtcIdListIteratorCurrent(&Dem_J1939DcmDTCFilter.retrieveIt);

        if (Dem_BitArrayIsBitSet(Dem_J1939DcmDTCFilterMatching, dtcId))
        {
            *J1939DTC = Dem_J1939DtcGetCode(dtcId);

            /* Bit 8 - SPN Conversion Method (CM) shall be set to 0 as specified by Autosar */
            *OccurenceCounter = (Dem_J1939GetOccurrenceCounterByDtcId(dtcId) & 0x7Fu);

            Dem_J1939DtcIdListIteratorNext(&Dem_J1939DcmDTCFilter.retrieveIt);
            return E_OK;
        }
        i--;
        Dem_J1939DtcIdListIteratorNext(&Dem_J1939DcmDTCFilter.retrieveIt);
    }
    return DEM_PENDING;
}

#endif

#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)

void Dem_J1939DcmFreezeFrameFilterInit(void)
{
    Dem_EvMemEventMemoryLocIteratorInvalidate(&Dem_J1939FreezeFrameFilterLocId, DEM_CFG_EVMEM_MEMID_PRIMARY);
}

Std_ReturnType Dem_J1939DcmSetFreezeFrameFilter(Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,uint8 ClientId)
{
    Std_ReturnType returnVal = E_OK;

    /* As there is one clientId for J1939 per event memory set no need to use clientId*/
    if (!Dem_isClientIdValid(ClientId))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMSETFREEZEFRAMEFILTER, DEM_E_WRONG_CONFIGURATION,0u);
        returnVal = DEM_WRONG_CLIENTID;
    }

    if(!Dem_J1939IsFreezeFrameKindValid(FreezeFrameKind))
    {
        returnVal = E_NOT_OK;
    }

    if (returnVal != E_NOT_OK)
    {
        Dem_J1939FreezeFrameFilter.FreezeFrameKind = FreezeFrameKind;
        Dem_EvMemEventMemoryLocIteratorNew (&Dem_J1939FreezeFrameFilterLocId, DEM_CFG_EVMEM_MEMID_PRIMARY);
    }

    return returnVal;
}

/* HIS METRIC PATH VIOLATION IN Dem_J1939DcmGetNextFreezeFrame: The function is optimized for many usecases */
Std_ReturnType Dem_J1939DcmGetNextFreezeFrame(uint32* J1939DTC,uint8* OccurenceCounter,uint8* DestBuffer,uint16* BufSize, uint8 ClientId)
{
    Dem_DtcIdType dtcId;
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind;
    uint16_least LocId;
    Dem_EventIdType EventId;
    Dem_DtcIdListIterator2 J1939DtcIdlist;
    boolean DTCFound;
    boolean FilterContinue;

    /* As there is one clientId for J1939 per event memory set no need to use clientId for now*/
    if (!Dem_isClientIdValid(ClientId))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMGETNEXTFREEZEFRAME, DEM_E_WRONG_CONFIGURATION,0u);
        return DEM_WRONG_CLIENTID;/* Autosar spec does not specify what to return in this case but DEM_NO_SUCH_ELEMENT */
    }

    DEM_ASSERT(((J1939DTC != NULL_PTR) && (OccurenceCounter != NULL_PTR)),DEM_DET_APIID_DEM_J1939DCMGETNEXTFREEZEFRAME, DEM_E_PARAM_POINTER);

    if ((DestBuffer==NULL_PTR) || (BufSize==NULL_PTR))
    {
        return DEM_BUFFER_TOO_SMALL;
    }

    FreezeFrameKind = Dem_J1939FreezeFrameFilter.FreezeFrameKind;

    if (!Dem_J1939IsFreezeFrameKindValid(FreezeFrameKind))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMGETNEXTFREEZEFRAME, DEM_E_WRONG_CONDITION,0u);
        return DEM_NO_SUCH_ELEMENT;
    }

    while (Dem_EvMemEventMemoryLocIteratorIsValid (&Dem_J1939FreezeFrameFilterLocId, DEM_CFG_EVMEM_MEMID_PRIMARY))
    {
        DTCFound = FALSE;
        FilterContinue = FALSE;

        if (Dem_EvMemIsStored(Dem_EvMemGetEventMemStatus(Dem_J1939FreezeFrameFilterLocId)))
        {
            EventId = Dem_EvMemGetEventMemEventId (Dem_J1939FreezeFrameFilterLocId);
            dtcId = Dem_DtcIdFromEventId(EventId);

            if (!Dem_DtcIsSuppressed (dtcId)) /* DTC is not Suppressed*/
            {
#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT)
                if ((FreezeFrameKind == DEM_J1939DCM_FREEZEFRAME) && (Dem_J1939EnvHasFreezeFrame(EventId)))
                {
                    FilterContinue = TRUE;
                }
                else
#endif
#if(DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)
                    if ((FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME) && (Dem_J1939EnvHasExpFreezeFrame(EventId)))
                    {
                        FilterContinue = TRUE;
                    }
                    else
#endif
                    {
                        /*Relevant FreezeFrame Data NotAvailable */
                    }
            }

            if (FilterContinue)
            {

                for (Dem_J1939DtcIdListIteratorNew (&J1939DtcIdlist);
                        Dem_J1939DtcIdListIteratorIsValid(&J1939DtcIdlist);
                        Dem_J1939DtcIdListIteratorNext(&J1939DtcIdlist))
                {
                    if(Dem_J1939DtcIdListIteratorCurrent(&J1939DtcIdlist) == dtcId)
                    {
                        DTCFound = TRUE;
                        break;
                    }
                }

                if(DTCFound)
                {
                    LocId = Dem_J1939FreezeFrameFilterLocId;

                    if (Dem_LibGetParamUI8(DEM_CFG_EVCOMB) == Dem_LibGetParamUI8(DEM_CFG_EVCOMB_ONRETRIEVAL))
                    {
                        LocId = Dem_EvMemGetEventMemoryLocIdOfDtcWithVisibility(Dem_DtcIdFromEventId(EventId),
                                DEM_CFG_EVMEM_MEMID_PRIMARY, FALSE);
                    }

                    if (Dem_J1939FreezeFrameFilterLocId == LocId)
                    {
                        *J1939DTC = Dem_J1939DtcGetCode(dtcId);
                        *OccurenceCounter = Dem_J1939GetOccurrenceCounterByDtcId(dtcId);

                        Dem_EvMemEventMemoryLocIteratorNext (&Dem_J1939FreezeFrameFilterLocId, DEM_CFG_EVMEM_MEMID_PRIMARY);

                        return Dem_J1939EnvRetrieveFreezeFrame(FreezeFrameKind, EventId, DestBuffer, BufSize, Dem_EvMemGetEventMemData(LocId), &Dem_EvMemEventMemory[LocId]);
                    }
                }
            }
        }
        Dem_EvMemEventMemoryLocIteratorNext (&Dem_J1939FreezeFrameFilterLocId, DEM_CFG_EVMEM_MEMID_PRIMARY);
    }

    return DEM_NO_SUCH_ELEMENT;
}

#if(DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)
/* MR12 RULE 8.13 VIOLATION: The warning can be ignored since the interface is not completely implemented */
Std_ReturnType Dem_J1939DcmGetNextSPNInFreezeFrame(uint32* SPNSupported,uint8* SPNDataLength, uint8 ClientId)
{
    DEM_UNUSED_PARAM(ClientId);
    DEM_UNUSED_PARAM(SPNSupported);
    DEM_UNUSED_PARAM(SPNDataLength);

    return DEM_NO_SUCH_ELEMENT;
}
#endif /* DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT */

#endif /* DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT */

#if (DEM_CFG_J1939DCM_DM31_SUPPORT)

void Dem_J1939DcmFirstDTCwithLampStatus(uint8 ClientId)
{
    /* As there is one clientId for J1939 per event memory set no need to use clientId */
    if (Dem_isClientIdValid(ClientId))
    {
        DEM_ENTERLOCK_DCM();
        Dem_J1939DtcIdListIteratorNew(&Dem_J1939DcmDTCRetrieve.retrieveIt);
        DEM_EXITLOCK_DCM();
    }
    else
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS, DEM_E_WRONG_CONFIGURATION,0u);
    }
}

/* MR12 RULE 8.13 VIOLATION: The warning can be ignored since the interface is not completely implemented */
Std_ReturnType Dem_J1939DcmGetNextDTCwithLampStatus(Dem_J1939DcmLampStatusType* LampStatus,uint32* J1939DTC,uint8* OccurenceCounter, uint8 ClientId)
{
    Dem_DtcIdType dtcId = 0u;

    /* As there is one clientId for J1939 per event memory set no need to use clientId*/
    if (!Dem_isClientIdValid(ClientId))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS, DEM_E_WRONG_CONFIGURATION,0u);
        return DEM_WRONG_CLIENTID;
    }

    DEM_ASSERT(((LampStatus != NULL_PTR) && (J1939DTC != NULL_PTR) && (OccurenceCounter != NULL_PTR)),DEM_DET_APIID_J1939DCMGETNEXTDTCWITHLAMPSTATUS, DEM_E_PARAM_POINTER);


    if (!Dem_J1939DtcIdListIteratorIsValid(&Dem_J1939DcmDTCRetrieve.retrieveIt))
    {
        return DEM_NO_SUCH_ELEMENT;
    }

    dtcId = Dem_J1939DtcIdListIteratorCurrent(&Dem_J1939DcmDTCRetrieve.retrieveIt);

#if (DEM_CFG_EVT_INDICATOR != DEM_CFG_EVT_INDICATOR_OFF)
    *LampStatus = Dem_J1939DcmGetLampStatus();
#else
    //  make the lamp status as OFF for invalid case
    *LampStatus = DEM_J1939DCM_MIL_RED_AMBER_PROTECT_OFF;
#endif

    *J1939DTC = Dem_J1939DtcGetCode(dtcId);

    /* Bit 8 - SPN Conversion Method (CM) shall be set to 0 as specified by Autosar */
    *OccurenceCounter = (Dem_J1939GetOccurrenceCounterByDtcId(dtcId) & 0x7Fu);

    Dem_J1939DtcIdListIteratorNext(&Dem_J1939DcmDTCRetrieve.retrieveIt);
    return E_OK;
}

#endif

#if(DEM_CFG_OBD != DEM_CFG_OBD_OFF)

/* MR12 RULE 8.13 VIOLATION: The warning can be ignored since the interface is not completely implemented */
Std_ReturnType Dem_J1939DcmSetRatioFilter(uint16* IgnitionCycleCounter,uint16* OBDMonitoringConditionsEncountered,uint8 ClientId)
{
    DEM_UNUSED_PARAM(IgnitionCycleCounter);
    DEM_UNUSED_PARAM(OBDMonitoringConditionsEncountered);
    DEM_UNUSED_PARAM(ClientId);

    return E_NOT_OK;
}

/* MR12 RULE 8.13 VIOLATION: The warning can be ignored since the interface is not completely implemented */
Std_ReturnType Dem_J1939DcmGetNextFilteredRatio(uint16* SPN,uint16* Numerator,uint16* Denominator,uint8 ClientId)
{
    DEM_UNUSED_PARAM(SPN);
    DEM_UNUSED_PARAM(Numerator);
    DEM_UNUSED_PARAM(Denominator);
    DEM_UNUSED_PARAM(ClientId);

    return DEM_NO_SUCH_ELEMENT;
}

/* MR12 RULE 8.13 VIOLATION: The warning can be ignored since the interface is not completely implemented */
Std_ReturnType Dem_J1939DcmReadDiagnosticReadiness1(Dem_J1939DcmDiagnosticReadiness1Type* DataValue,uint8 ClientId)
{
    DEM_UNUSED_PARAM(DataValue);
    DEM_UNUSED_PARAM(ClientId);

    return E_NOT_OK;
}

/* MR12 RULE 8.13 VIOLATION: The warning can be ignored since the interface is not completely implemented */
Std_ReturnType Dem_J1939DcmReadDiagnosticReadiness2(Dem_J1939DcmDiagnosticReadiness2Type* DataValue,uint8 ClientId)
{
    DEM_UNUSED_PARAM(DataValue);
    DEM_UNUSED_PARAM(ClientId);

    return E_NOT_OK;
}

/* MR12 RULE 8.13 VIOLATION: The warning can be ignored since the interface is not completely implemented */
Std_ReturnType Dem_J1939DcmReadDiagnosticReadiness3(Dem_J1939DcmDiagnosticReadiness3Type* DataValue,uint8 ClientId)
{
    DEM_UNUSED_PARAM(DataValue);
    DEM_UNUSED_PARAM(ClientId);

    return E_NOT_OK;
}
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if(DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF)

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

Std_ReturnType Dem_J1939DcmClearDTCBody(Dem_J1939DcmSetClearFilterType DTCTypeFilter, Dem_DTCOriginType DTCOrigin)
{
    Dem_DtcIdType dtcId;
    Dem_UdsStatusByteType status;
    uint16_least memId;

    /* Initialization */
    Dem_ClientClearMachine.IsClearInterrupted = FALSE;
    Dem_ClientClearMachine.NumberOfEventsProcessed = 0;

    /* Check whether the Clear is requested newly */
	/* MR12 RULE 13.5 VIOLATION: The operator is free from persistent side effects. Use of #pragma is not allowed. */
    if ((Dem_ClientClearMachine.IsNewClearRequest) || (!Dem_J1939DtcIdListIteratorIsValid(&(Dem_ClientClearMachine.DtcIt2))))
    {
        memId = Dem_EvMemGetMemIdForDTCOrigin(DTCOrigin);
        if(memId < DEM_J1939MEMID_ARRAYLENGTH)
        {
            Dem_J1939DtcIdListIteratorNewFromJ1939MemID(&(Dem_ClientClearMachine.DtcIt2), memId);
        }
        else
        {
            return DEM_WRONG_DTCORIGIN;
        }
    }

    while (Dem_J1939DtcIdListIteratorIsValid(&(Dem_ClientClearMachine.DtcIt2)))
    {
        dtcId = Dem_J1939DtcIdListIteratorCurrent(&(Dem_ClientClearMachine.DtcIt2));
        status = Dem_DtcStatusByteRetrieve(dtcId);

        Dem_ClearDTCWithJ1939DcmFilter(dtcId, DTCOrigin, status, DTCTypeFilter, &Dem_ClientClearMachine);
        if (!Dem_ClientClearMachine.IsClearInterrupted)
        {
            Dem_J1939DtcIdListIteratorNext(&(Dem_ClientClearMachine.DtcIt2));
        }
        else
        {
            return DEM_PENDING;
        }
    }

    if (!Dem_ClientClearMachine.IsClearInterrupted)
    {
        return E_OK;
    }
    return DEM_PENDING;
}

static boolean Dem_J1939DcmIsDTCTypeFilterValid(Dem_J1939DcmSetClearFilterType DTCTypeFilter)
{
    return ((DTCTypeFilter == DEM_J1939DTC_CLEAR_ACTIVE) || (DTCTypeFilter == DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE) || (DTCTypeFilter == DEM_J1939DTC_CLEAR_ACTIVE_AND_PREVIOUSLY_ACTIVE));
}

Std_ReturnType Dem_J1939DcmClearDTC(Dem_J1939DcmSetClearFilterType DTCTypeFilter, Dem_DTCOriginType DTCOrigin, uint8 ClientId)
{
    Std_ReturnType returnSts = E_OK;

    if (!Dem_isClientIdValid(ClientId))
    {
        DEM_DET(DEM_DET_APIID_DEM_J1939DcmClearDTC, DEM_E_WRONG_CONFIGURATION,0u);
        return DEM_WRONG_CLIENTID;
    }

    if (!Dem_J1939DcmIsDTCTypeFilterValid(DTCTypeFilter))
    {
        return DEM_CLEAR_FAILED;
    }

    if (!Dem_EvMemIsDtcOriginValid(&DTCOrigin))
    {
        return DEM_WRONG_DTCORIGIN;
    }

    Dem_ClientClearMachine.IsClientJ1939 = TRUE;
    Dem_AllClientsState[ClientId].IsClientJ1939 = TRUE;

    if (!Dem_Client_AreJ1939ParametersAlreadyRequested(DTCTypeFilter, DTCOrigin, ClientId))
    {
        returnSts = Dem_SelectJ1939Parameters(DTCTypeFilter, DTCOrigin, ClientId);
        if (returnSts != E_OK)
        {
            return returnSts;
        }
    }

    if (Dem_Client_GetClientState(ClientId) == DEM_CLIENT_STATE_PARAMETERS_SET)
    {
        Dem_ClientRequestType_setRequest(&Dem_AllClientsState[ClientId].request, DEM_CLIENT_REQUEST_CLEAR);
        Dem_Client_SetClientState(ClientId, DEM_CLIENT_STATE_REQUESTED_OPERATION);

        return DEM_PENDING;
    }
    /* MR12 RULE 13.5 VIOLATION: Getter function is identified as an expression causing side effect. This warning can be ignored. */
    else if ((Dem_Client_GetClientState(ClientId) == DEM_CLIENT_STATE_REQUESTED_OPERATION)
            || (Dem_Client_GetClientState(ClientId) == DEM_CLIENT_STATE_INIT))
    {
        if (!(Dem_ClientRequestType_isRequestInProgress(ClientId)))
        {
            Dem_Client_SetClientState(ClientId, DEM_CLIENT_STATE_PARAMETERS_SET);
            return Dem_ClientResultType_getResult(Dem_AllClientsState[ClientId].result);
        }
        else
        {
            return DEM_PENDING;
        }
    }
    else
    {
        /* should never occur */
        DEM_ASSERT(Dem_LibGetParamBool(FALSE), DEM_DET_APIID_DEM_J1939DcmClearDTC, 0);
        return DEM_CLEAR_FAILED;
    }
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

#endif

