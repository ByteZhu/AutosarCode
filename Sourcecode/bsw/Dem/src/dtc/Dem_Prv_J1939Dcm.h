
#ifndef DEM_PRV_J1939DCM_H
#define DEM_PRV_J1939DCM_H

#include "Dem_Cfg_J1939Indicator.h"
#include "Dem_BitArray.h"
#include "Dem_Types.h"
#include "Dem_Array.h"
#include "Dem_Mapping.h"
#include "Dem_DTCStatusByte.h"
#include "Dem_Client.h"

#if(DEM_CFG_J1939DCM != DEM_CFG_J1939DCM_OFF)

#include "J1939Dcm.h"
#include "Dem_ISO14229Byte.h"

/* Malfunction Indicator Lamp, Red Stop Lamp, Amber Warning Lamp and Protect Lamp */
#define DEM_J1939DCM_MIL_LAMPSTATUS                 0x40u   //0b 0100 0000
#define DEM_J1939DCM_RED_LAMPSTATUS                 0x10u   //0b 0001 0000
#define DEM_J1939DCM_AMBER_LAMPSTATUS               0x04u   //0b 0000 0100
#define DEM_J1939DCM_PROTECT_LAMPSTATUS             0x01u   //0b 0000 0001
#define DEM_J1939DCM_FLASHLAMP_OFF                  0x00u   //0b 0000 0000

#define DEM_J1939DCM_MIL_RED_AMBER_PROTECT_OFF      0x0000u //0b 0000 0000 0000 0000

/* Malfunction Indicator Lamp */
#define DEM_J1939DCM_MIL_FAST_FLASH                 0x4040u //0b 0100 0000 0100 0000
#define DEM_J1939DCM_MIL_SLOW_FLASH                 0x4000u //0b 0100 0000 0000 0000
#define DEM_J1939DCM_MIL_CONTINUOUS                 0x40C0u //0b 0100 0000 1100 0000
#define DEM_J1939DCM_MIL_SHORT                      0x0000u //0b has do be defined
#define DEM_J1939DCM_MIL_ON_DEMAND                  0x0000u //0b has do be defined
#define DEM_J1939DCM_MIL_OFF                        0x0000u //0b 0000 0000 0000 0000

/* Red Stop Lamp */
#define DEM_J1939DCM_RED_FAST_FLASH                 0x1010u //0b 0001 0000 0001 0000
#define DEM_J1939DCM_RED_SLOW_FLASH                 0x1000u //0b 0001 0000 0000 0000
#define DEM_J1939DCM_RED_CONTINUOUS                 0x1030u //0b 0001 0000 0011 0000
#define DEM_J1939DCM_RED_OFF                        0x0000u //0b 0000 0000 0000 0000

/* Amber Warning Lamp */
#define DEM_J1939DCM_AMBER_FAST_FLASH               0x0404u //0b 0000 0100 0000 0100
#define DEM_J1939DCM_AMBER_SLOW_FLASH               0x0400u //0b 0000 0100 0000 0000
#define DEM_J1939DCM_AMBER_CONTINUOUS               0x040Cu //0b 0000 0100 0000 1100
#define DEM_J1939DCM_AMBER_OFF                      0x0000u //0b 0000 0000 0000 0000

/* Protect Lamp */
#define DEM_J1939DCM_PROTECT_FAST_FLASH             0x0101u //0b 0000 0001 0000 0001
#define DEM_J1939DCM_PROTECT_SLOW_FLASH             0x0100u //0b 0000 0001 0000 0000
#define DEM_J1939DCM_PROTECT_CONTINUOUS             0x0103u //0b 0000 0001 0000 0011
#define DEM_J1939DCM_PROTECT_OFF                    0x0000u //0b 0000 0000 0000 0000

#if (DEM_CFG_J1939DCM_READ_DTC_SUPPORT)

typedef struct
{
    boolean isNewFilterCriteria;
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter;
    Dem_DTCKindType DTCKind;
    uint16_least memId;
    Dem_J1939DcmLampStatusType* LampStatus;
    uint16 numberOfMatchingDTCs;
    Dem_DtcIdListIterator2 searchIt, retrieveIt;
} Dem_J1939DcmDTCFilterState;


#endif

#if (DEM_CFG_J1939DCM_DM31_SUPPORT)

typedef struct
{
    Dem_DtcIdListIterator2 retrieveIt;
} Dem_J1939DcmDTCRetrieveState;

#endif

#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)

typedef struct
{
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind;
} Dem_J1939FreezeFrameFilterState;

#endif /* DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT */

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"
#if (DEM_CFG_J1939DCM_READ_DTC_SUPPORT)
    extern Dem_J1939DcmDTCFilterState Dem_J1939DcmDTCFilter;
    DEM_BITARRAY_DECLARE(Dem_J1939DcmDTCFilterMatching, DEM_DTCID_ARRAYLENGTH);
#endif

#if (DEM_CFG_J1939DCM_DM31_SUPPORT)
    extern Dem_J1939DcmDTCRetrieveState Dem_J1939DcmDTCRetrieve;
#endif

#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)
	extern Dem_J1939FreezeFrameFilterState Dem_J1939FreezeFrameFilter;
#endif
#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

typedef struct {
    Dem_DtcCodeType code;
} Dem_J1939DtcParam32;

#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"

DEM_ARRAY_DECLARE_CONST(Dem_J1939DtcParam32, Dem_AllJ1939DTCsParam32, DEM_DTCID_ARRAYLENGTH);

#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

uint8 Dem_J1939GetOccurrenceCounterByDtcId(Dem_DtcIdType dtcId);

#if (DEM_CFG_EVT_INDICATOR != DEM_CFG_EVT_INDICATOR_OFF)
Dem_J1939DcmLampStatusType Dem_J1939DcmGetLampStatus(void);
#endif

#if (DEM_CFG_J1939DCM_READ_DTC_SUPPORT)
void Dem_J1939DcmDtcFilterInit(void);
#endif

DEM_INLINE Dem_DtcCodeType Dem_J1939DtcGetCode (Dem_DtcIdType dtcId)
{
    return Dem_AllJ1939DTCsParam32[dtcId].code;
}

#if(DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF)
Std_ReturnType Dem_J1939DcmClearDTCBody(Dem_J1939DcmSetClearFilterType DTCTypeFilter, Dem_DTCOriginType DTCOrigin);
void Dem_J1939DcmClearDTCMainFunction(void);
#endif  /* DEM_CFG_J1939DCM_CLEAR_SUPPORT */

#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)
void Dem_J1939DcmFreezeFrameFilterInit(void);
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)

DEM_INLINE Dem_boolean_least Dem_J1939IsFreezeFrameKindValid (Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind)
{
    Dem_boolean_least DemJ1939FFKindValid = FALSE;

#if(DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT)
    if (FreezeFrameKind == DEM_J1939DCM_FREEZEFRAME)
    {
        DemJ1939FFKindValid = TRUE;
    }
    else
#endif
#if(DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT)
        if (FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME)
        {
            DemJ1939FFKindValid = TRUE;
        }
        else
#endif
        {
            /*not supported*/
        }

    return DemJ1939FFKindValid;
}

#endif  /* DEM_CFG_J1939DCM_FREEZEFRAME_SUPPORT || DEM_CFG_J1939DCM_EXPANDED_FREEZEFRAME_SUPPORT */

/* Dummy function for getting J1939 Client event memroy set index */
DEM_INLINE uint8 Dem_J1939GetClientEventMemorySet(uint8 ClientId)
{
    DEM_UNUSED_PARAM(ClientId);
    /* as there is one memory set the index is 0 */
    return 0;
}

/* Dummy function for getting J1939 Dtc event memroy set index */
DEM_INLINE uint8 Dem_J1939GetDTCEventMemorySet(Dem_DtcIdType dtcId)
{
    DEM_UNUSED_PARAM(dtcId);
    /* as there is one memory set the index is 0 */
    return 0;
}

DEM_INLINE void Dem_J1939DTCStatusChangedIndicationCallback(Dem_DtcIdType dtcId, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew)
{
    Dem_ClientIdListIterator J1939ClientIdIterator;
    Dem_DtcCodeType J1939DTC = Dem_J1939DtcGetCode(dtcId);

    if ( (J1939DTC != DEM_DTCID_INVALID) && ((DTCStatusNew & DEM_ISO14229_BM_TESTFAILED)!=(DTCStatusOld & DEM_ISO14229_BM_TESTFAILED)) )
    {
        for (Dem_Client_ClientIdIteratorNew (&J1939ClientIdIterator);
                Dem_Client_ClientIdIteratorValid(&J1939ClientIdIterator);
                Dem_Client_ClientIdIteratorNext(&J1939ClientIdIterator))
        {
            if(Dem_J1939GetDTCEventMemorySet(dtcId) == Dem_J1939GetClientEventMemorySet(Dem_Client_ClientIdIteratorCurrent(&J1939ClientIdIterator)))
            {
                J1939Dcm_DemTriggerOnDTCStatus(J1939DTC, Dem_Client_ClientIdIteratorCurrent(&J1939ClientIdIterator));
                break;
            }
        }
    }
}

#if(DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF)
DEM_INLINE void Dem_ClearDTCWithJ1939DcmFilter(Dem_DtcIdType dtcId, Dem_DTCOriginType DTCOrigin, Dem_UdsStatusByteType status, Dem_J1939DcmSetClearFilterType DTCTypeFilter, Dem_ClientClearMachineType *Dem_ClientClearMachinePtr)
{
    if(DTCTypeFilter == DEM_J1939DTC_CLEAR_ACTIVE)
    {
        if((Dem_ISO14229ByteIsTestFailed(status) && Dem_ISO14229ByteIsConfirmedDTC(status)) || (Dem_ISO14229ByteIsWarningIndicatorRequested(status)))
        {
            Dem_ClearSingleDTC(dtcId, DTCOrigin, Dem_ClientClearMachinePtr);
        }
    }
    else if (DTCTypeFilter == DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE)
    {
        if((!Dem_ISO14229ByteIsTestFailed(status)) && Dem_ISO14229ByteIsConfirmedDTC(status) && (!Dem_ISO14229ByteIsWarningIndicatorRequested(status)))
        {
            Dem_ClearSingleDTC(dtcId, DTCOrigin, Dem_ClientClearMachinePtr);
        }
    }
    else if (DTCTypeFilter == DEM_J1939DTC_CLEAR_ACTIVE_AND_PREVIOUSLY_ACTIVE)
    {
        if( Dem_ISO14229ByteIsConfirmedDTC(status) || (Dem_ISO14229ByteIsWarningIndicatorRequested(status)) )
        {
            Dem_ClearSingleDTC(dtcId, DTCOrigin, Dem_ClientClearMachinePtr);
        }
    }
    else
    {
        /* Do nothing */
    }

}
#endif  /* DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF */

DEM_INLINE uint16 Dem_CombineJ1939DcmLampStatusType(Dem_J1939DcmLampStatusType lampStatusStruct)
{
    uint16 indicatorStatus;

    indicatorStatus = lampStatusStruct.LampStatus;
    indicatorStatus = indicatorStatus << 8u;
    indicatorStatus |= lampStatusStruct.FlashLampStatus;

    return indicatorStatus;
}

DEM_INLINE Dem_J1939DcmLampStatusType Dem_SplitJ1939DcmLampStatusType(uint16 lampIndicator)
{
    Dem_J1939DcmLampStatusType lampStatusStruct;

    lampStatusStruct.FlashLampStatus = (uint8)(lampIndicator & 0xFFu);
    lampStatusStruct.LampStatus = (uint8)(lampIndicator >> 8u);

    return lampStatusStruct;
}

#endif  /* DEM_CFG_J1939DCM */

#endif

