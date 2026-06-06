
#ifndef DEM_CLIENT_H
#define DEM_CLIENT_H

#include "Dem_ClientHandlingTypes.h"
#include "Dem_Array.h"
#include "Dem_EvMemTypes.h"
#include "Dem_EnvRecordIterator.h"
#include "Dem_Lib.h"

/******************************************************************************************/
/**************** Dem Clients  ***************************************************************/
typedef struct
{
    boolean IsCopyValid;    // Indicates that Evmem Copy was taken or not(Eg: Because of DTC not being stored)
    Dem_EvMemEventMemoryType EvMemCopy;
} Dem_ClientSelectED_FFDataType;

typedef struct
{
    Dem_DTCFormatType DTCFormat;
    Dem_DTCOriginType DTCOrigin;
    boolean IsDTCRecordUpdateDisabled;
    uint8 SelectED_FF_MachineState;
    boolean IsED_FFSelectionPending;
    boolean IsGetNextDataCalled;
    volatile uint8 DTCStatus;
    uint32 DTC;
    Dem_ClientSelectED_FFDataType SelectED_FFData;
    Dem_EnvRecordIteratorType SelectED_FFIt;
} Dem_ClientState_Standard;

typedef struct
{
#if(DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF)
    Dem_J1939DcmSetClearFilterType J1939DTCTypeFilter;
    Dem_DTCOriginType J1939DTCOrigin;
#else
    uint8 Dem_Dummy;     /* dummy variable to avoid empty structure error in some compilers in case J1939 is not supported*/
#endif
} Dem_ClientState_J1939;

typedef struct
{
    volatile uint8 client_state;
    volatile Dem_ClientRequestType request;
    volatile Dem_ClientResultType result;
    Dem_ClientSelectionType selection;
    union
    {
        Dem_ClientState_Standard standard;
        Dem_ClientState_J1939 j1939;
    } data;
#if(DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF)
    boolean IsClientJ1939;
#endif
} Dem_ClientState;

#define DEM_START_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

DEM_ARRAY_DECLARE(Dem_ClientState, Dem_AllClientsState, DEM_CLIENTID_ARRAYLENGTH_STD);

#define DEM_STOP_SEC_VAR_CLEARED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

typedef struct {
    Dem_ClientIdType it;
    Dem_ClientIdType end;
} Dem_ClientIdListIterator;

void Dem_Client_SetClientState(Dem_ClientIdType ClientId, uint8 state);
uint8 Dem_Client_GetClientState(Dem_ClientIdType ClientId);

DEM_INLINE void Dem_Client_ClientIdIteratorNew(Dem_ClientIdListIterator *ClientIdIt)
{
    ClientIdIt->it = 1;
    ClientIdIt->end = DEM_CLIENTID_ARRAYLENGTH_STD;
}

DEM_INLINE Dem_boolean_least Dem_Client_ClientIdIteratorValid(const Dem_ClientIdListIterator *ClientIdIt)
{
    return ((Dem_boolean_least)(ClientIdIt->it < ClientIdIt->end ));
}

DEM_INLINE void Dem_Client_ClientIdIteratorNext(Dem_ClientIdListIterator *ClientIdIt)
{
    (ClientIdIt->it)++;
}

DEM_INLINE Dem_ClientIdType Dem_Client_ClientIdIteratorCurrent(const Dem_ClientIdListIterator *ClientIdIt)
{
   return (Dem_ClientIdType)(ClientIdIt->it);
}

/* ClientId Validation check*/
DEM_INLINE Dem_boolean_least Dem_isClientIdValid(Dem_ClientIdType clientId)
{
   return ((clientId != DEM_CLIENTID_INVALID) && (clientId < DEM_CLIENTID_ARRAYLENGTH_STD));
}

void Dem_ClientInit(void);

DEM_INLINE Dem_ClientState* Dem_Client_getClient (Dem_ClientIdType ClientId)
{
    return (&Dem_AllClientsState[ClientId]);
}

Std_ReturnType Dem_Client_Operation(uint8 ClientId, uint8 requestId, uint8 ApiId);

#if(DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF)
Std_ReturnType Dem_SelectJ1939Parameters(Dem_J1939DcmSetClearFilterType DTCTypeFilter, Dem_DTCOriginType DTCOrigin, uint8 ClientId);
boolean Dem_Client_AreJ1939ParametersAlreadyRequested(Dem_J1939DcmSetClearFilterType DTCTypeFilter, Dem_DTCOriginType DTCOrigin, uint8 ClientId);
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif
