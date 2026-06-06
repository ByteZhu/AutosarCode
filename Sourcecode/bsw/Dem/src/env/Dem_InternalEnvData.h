
#ifndef DEM_INTERNALENVDATA_H
#define DEM_INTERNALENVDATA_H


#include "Dem_Types.h"
#include "Dem_EvMemTypes.h"

/**
 * Used to pass information about the event to internal data element read functions
 */
typedef struct
{
    /** Id of the event */
    Dem_EventIdType eventId;

    /** Monitor data */
    Dem_MonitorDataType monitorData0;
    Dem_MonitorDataType monitorData1;

    /** Event memory location of the event. Only set on retrieval (otherwise == NULL_PTR) */
    Dem_EvMemEventMemoryType *evMemLocation;
} Dem_InternalEnvData;


#endif

