

#ifndef DEM_MAPPING_H
#define DEM_MAPPING_H


#include "Dem_Types.h"
#include "Dem_Lib.h"

#include "Dem_Cfg_EventId.h"
#include "Dem_Cfg_DtcId.h"
#include "Dem_Cfg_ComponentId.h"
#include "Dem_Cfg_Components.h"
#include "Dem_Cfg_EventIndicators.h"
#include "Dem_Cfg_DTC_DataStructures.h"
#include "Dem_Array.h"


/*** EVENTID *****************************************************************/

DEM_INLINE Dem_boolean_least Dem_isEventIdValid(Dem_EventIdType checkID)
{
   return ((0u < checkID) && (checkID <= DEM_EVENTID_COUNT));
}

/*Iterator for EventId*/

typedef uint16_least Dem_EventIdIterator; /* do not change to uint8_least */


#define DEM_EVENTIDITERATORNEW  1
DEM_INLINE void Dem_EventIdIteratorNew(Dem_EventIdIterator *it)
{
   (*it) = DEM_EVENTIDITERATORNEW;
}

DEM_INLINE Dem_boolean_least Dem_EventIdIteratorIsValid(const Dem_EventIdIterator *it)
{
   return (*it <= DEM_EVENTID_COUNT);
}

DEM_INLINE void Dem_EventIdIteratorNext(Dem_EventIdIterator *it)
{
   (*it)++;
}

DEM_INLINE Dem_EventIdType Dem_EventIdIteratorCurrent(const Dem_EventIdIterator *it)
{
   return (Dem_EventIdType)(*it);
}

/*** COMPONENTID *****************************************************************/

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)
#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
extern const Dem_ComponentIdType  Dem_MapEventIdToComponentId[DEM_EVENTID_ARRAYLENGTH];
extern const Dem_EventIdType Dem_MapComponentIdToEventId[DEM_COMPONENTID_ARRAYLENGTH];
extern const Dem_ComponentIdType  Dem_MapComponentIdToChildComponentId[DEM_CFG_CHILDCOMPONENT_LISTLENGTH];
extern const uint16 Dem_ComponentToChildComponentIndex [DEM_COMPONENTID_ARRAYLENGTH];
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"
#define DEM_COMPONENTIDITERATOR_NEW()       1


DEM_INLINE Dem_boolean_least Dem_ComponentIdIsValid (uint16 checkID)
{
   return ((0 < checkID) && (checkID <= DEM_COMPONENTID_COUNT));
}

/*Iterator for ComponentID*/

typedef uint16_least Dem_ComponentIdIterator; /* do not change to uint8_least */


DEM_INLINE void Dem_ComponentIdIteratorNew(Dem_ComponentIdIterator *it)
{
   (*it) = DEM_COMPONENTIDITERATOR_NEW();
}

DEM_INLINE Dem_boolean_least Dem_ComponentIdIteratorIsValid(const Dem_ComponentIdIterator *it)
{
   return (*it <= DEM_COMPONENTID_COUNT);
}

DEM_INLINE void Dem_ComponentIdIteratorNext(Dem_ComponentIdIterator *it)
{
   (*it)++;
}

DEM_INLINE Dem_ComponentIdType Dem_ComponentIdIteratorCurrent(const Dem_ComponentIdIterator *it)
{
   return (Dem_ComponentIdType)(*it);
}

DEM_INLINE Dem_ComponentIdType  Dem_ComponentIdFromEventId (Dem_EventIdType id)
{
   return Dem_MapEventIdToComponentId[id];
}



#else


DEM_INLINE Dem_ComponentIdType  Dem_ComponentIdFromEventId (Dem_EventIdType id)
{
	DEM_UNUSED_PARAM(id);
	return DEM_COMPONENTID_INVALID;
}

DEM_INLINE Dem_boolean_least Dem_ComponentIdIsValid (uint16 checkID)
{
	DEM_UNUSED_PARAM(checkID);
	return FALSE;
}


#endif


/*** DTCID *****************************************************************/


#if (DEM_CFG_EVCOMB == DEM_CFG_EVCOMB_DISABLED)

typedef Dem_EventIdType Dem_MapDtcIdToEventIdType;

#else

typedef struct {
   const Dem_EventIdType *mappingTable;
   uint16 length;
} Dem_MapDtcIdToEventIdType;

#endif
typedef Dem_DTCGroupIdType Dem_MapDtcIdToGroupIdType;
#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
extern const Dem_MapDtcIdToEventIdType  Dem_MapDtcIdToEventId[DEM_DTCID_ARRAYLENGTH];
extern const Dem_DtcIdType              Dem_MapEventIdToDtcId[DEM_EVENTID_ARRAYLENGTH];
DEM_ARRAY_DECLARE_CONST(uint8,Dem_MapEvMemToDTCGroupCount,DEM_CFG_EVMEM_DTCGROUPS_SIZE);
DEM_ARRAY_DECLARE_CONST(uint8,Dem_MapEvMemToDTCGroupOffset,DEM_CFG_EVMEM_DTCGROUPS_SIZE);
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"



DEM_INLINE Dem_boolean_least Dem_EventIdIsDtcAssigned (Dem_EventIdType id)
{
   return (Dem_MapEventIdToDtcId[id] != DEM_DTCID_INVALID);
}


DEM_INLINE Dem_boolean_least Dem_isDtcIdValid (Dem_DtcIdType id)
{
   return ((0u < id) && (id <= DEM_DTCID_COUNT));
}


DEM_INLINE Dem_DtcIdType  Dem_DtcIdFromEventId (Dem_EventIdType id)
{
   return Dem_MapEventIdToDtcId[id];
}


#if (DEM_CFG_EVCOMB == DEM_CFG_EVCOMB_DISABLED)

DEM_INLINE Dem_EventIdType Dem_DtcIdGetEventId (Dem_DtcIdType dtcid)
{
   return Dem_MapDtcIdToEventId[dtcid];
}

#endif


DEM_INLINE Dem_EventIdType Dem_DtcIdGetFirstEventId (Dem_DtcIdType dtcid)
{
#if (DEM_CFG_EVCOMB == DEM_CFG_EVCOMB_DISABLED)
   return Dem_DtcIdGetEventId(dtcid);
#else
   return Dem_MapDtcIdToEventId[dtcid].mappingTable[0];
#endif
}

DEM_INLINE uint16 Dem_DtcIdGetNumberOfEvents (Dem_DtcIdType dtcid)
{
#if (DEM_CFG_EVCOMB == DEM_CFG_EVCOMB_DISABLED)
	DEM_UNUSED_PARAM(dtcid);
	return 1;
#else
   return Dem_MapDtcIdToEventId[dtcid].length;
#endif

}


/* ITERATOR for DtcID: loop over all existing DtcIds */

typedef uint16_least Dem_DtcIdIterator; /* do not change to uint8_least */

#define DEM_DTCIDITERATOR_NEW()       1
#define DEM_DTCIDITERATOR_INVALID()   (DEM_DTCID_COUNT+1)

DEM_INLINE void Dem_DtcIdIteratorNew(Dem_DtcIdIterator *it)
{
   (*it) = DEM_DTCIDITERATOR_NEW();
}

DEM_INLINE Dem_boolean_least Dem_DtcIdIteratorIsValid(const Dem_DtcIdIterator *it)
{
   return ((0u < *it) && (*it <= DEM_DTCID_COUNT));
}

DEM_INLINE void Dem_DtcIdIteratorNext(Dem_DtcIdIterator *it)
{
   (*it)++;
}

DEM_INLINE Dem_DtcIdType Dem_DtcIdIteratorCurrent(const Dem_DtcIdIterator *it)
{
   return (Dem_DtcIdType)(*it);
}

DEM_INLINE void Dem_DtcIdIteratorInvalidate(Dem_DtcIdIterator *it)
{
   (*it) =0;
}

/*----Iterator for DTCGroup Id--------------------------------*/
#define DEM_DTCGROUPIDITERATOR_NEW()       1

typedef uint8_least Dem_DtcGroupIdIterator;

DEM_INLINE void Dem_DtcGroupIdIteratorNew(Dem_DtcGroupIdIterator *it)
{
   (*it) = DEM_DTCGROUPIDITERATOR_NEW();
}

DEM_INLINE Dem_boolean_least Dem_DtcGroupIdIteratorIsValid(const Dem_DtcGroupIdIterator *it, uint16_least memId)
{
   return (*it < Dem_MapEvMemToDTCGroupCount[memId]);
}

DEM_INLINE void Dem_DtcGroupIdIteratorNext(Dem_DtcGroupIdIterator *it)
{
   (*it)++;
}

DEM_INLINE Dem_DTCGroupIdType Dem_DtcGroupIdIteratorCurrent(const Dem_DtcGroupIdIterator *it)
{
   return (Dem_DTCGroupIdType)(*it);
}

DEM_INLINE Dem_boolean_least Dem_DtcGroupIdIsValid (Dem_DTCGroupIdType dtcGroupID, uint16_least memId)
{
    /*
     * As the value ZERO is defined as "INVALID_DTC_GROUP", it shall be handled as not valid id.
     */

    return ((dtcGroupID != DEM_DTCGROUPID_INVALID) && (dtcGroupID <= Dem_MapEvMemToDTCGroupCount[memId]));
}

/*----------------------------------------*/

/************** Iterator functions for Indicator Attributes **************************/
#if (DEM_CFG_EVT_INDICATOR == DEM_CFG_EVT_INDICATOR_ON)
typedef uint16_least Dem_EventIndicatorAttributeIterator;

DEM_INLINE void Dem_EventIndicatorAttributeIteratorNew(Dem_EventIdType EventId, Dem_EventIndicatorAttributeIterator *it)
{
   (*it) = ((EventId - 1u) * DEM_INDICATOR_ATTRIBUTE_MAX_PER_EVENT) ;
}

DEM_INLINE Dem_boolean_least Dem_EventIndicatorAttributeIsValid(Dem_EventIdType EventId, const Dem_EventIndicatorAttributeIterator *it)
{
   return (*it < (EventId * DEM_INDICATOR_ATTRIBUTE_MAX_PER_EVENT));
}

DEM_INLINE void Dem_EventIndicatorAttributeNext(Dem_EventIndicatorAttributeIterator *it)
{
   (*it)++;
}

DEM_INLINE uint16_least Dem_EventIndicatorAttributeCurrent(const Dem_EventIndicatorAttributeIterator *it)
{
   return (uint16_least)(*it);
}
#endif
/*******************Indicator Id validator function *************************************/
#if (DEM_CFG_INDICATOR == DEM_CFG_INDICATOR_ON)
DEM_INLINE Dem_boolean_least Dem_isIndicatorIdValid (uint8 checkID)
{
	return ((checkID  != DEM_INDICATORID_INVALID) && (checkID <= DEM_INDICATORID_COUNT));
}
#endif
/*************************************************************************************/


/*** LIST-ITERATORS ********************************************************/

/* ITERATOR for lists of EventIds: loop over all events assigned to a dtc/ */

typedef struct {
   const Dem_EventIdType* it;
   const Dem_EventIdType* end;
} Dem_EventIdListIterator;


DEM_INLINE void Dem_EventIdListIteratorNewFromDtcId(Dem_EventIdListIterator *it, Dem_DtcIdType dtcid)
{

   if (!(Dem_isDtcIdValid(dtcid)))
   {
 	  DEM_DET(DEM_DET_APIID_EVENTIDLISTITERATOR,0,0u);
   }
#if (DEM_CFG_EVCOMB == DEM_CFG_EVCOMB_DISABLED)
   it->it = &Dem_MapDtcIdToEventId[dtcid];
   it->end = &Dem_MapDtcIdToEventId[dtcid] + 1;
#else
   it->it = &Dem_MapDtcIdToEventId[dtcid].mappingTable[0];
   it->end = &Dem_MapDtcIdToEventId[dtcid].mappingTable[Dem_MapDtcIdToEventId[dtcid].length];
#endif
}

DEM_INLINE Dem_boolean_least Dem_EventIdListIteratorIsValid(const Dem_EventIdListIterator *it)
{
   return ((Dem_boolean_least)(it->it < it->end));
}

DEM_INLINE void Dem_EventIdListIteratorNext(Dem_EventIdListIterator *it)
{
   (it->it)++;
}

DEM_INLINE Dem_EventIdType Dem_EventIdListIteratorCurrent(const Dem_EventIdListIterator *it)
{
   return (Dem_EventIdType)(*(it->it));
}


/*** LIST-ITERATORS ********************************************************/

/* ITERATOR for lists of DtcIds: loop over all Dtcs assigned to a dtcGroup */

typedef struct {
	Dem_DtcIdType it;
	Dem_DtcIdType end;
} Dem_DtcIdListIterator;

typedef struct {
	Dem_DtcIdType dtcStartIndex;
	Dem_DtcIdType dtcEndIndex;
} Dem_DtcGroupIdMapToDtcIdType;
#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
DEM_ARRAY_DECLARE_CONST(Dem_DtcGroupIdMapToDtcIdType, Dem_DtcGroupIdMapToDtcId, DEM_DTCGROUPID_ARRAYLENGTH);
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"

DEM_INLINE void Dem_DtcIdListIteratorNewFromDtcGroup(Dem_DtcIdListIterator *it, Dem_DTCGroupIdType dtcGroup, uint16_least memId)
{
	if (!(Dem_DtcGroupIdIsValid(dtcGroup, memId)))
	{
		DEM_DET(DEM_DET_APIID_DTCGROUPIDIDLISTITERATOR,0,0u);
	}

	it->it = Dem_DtcGroupIdMapToDtcId[Dem_MapEvMemToDTCGroupOffset[memId] + dtcGroup].dtcStartIndex;
	it->end = Dem_DtcGroupIdMapToDtcId[Dem_MapEvMemToDTCGroupOffset[memId] + dtcGroup].dtcEndIndex;
}

DEM_INLINE Dem_boolean_least Dem_DtcIdListIteratorIsValid(const Dem_DtcIdListIterator *it)
{
   return (it->it <= it->end);
}

DEM_INLINE void Dem_DtcIdListIteratorNext(Dem_DtcIdListIterator *it)
{
   (it->it)++;
}

DEM_INLINE Dem_DtcIdType Dem_DtcIdListIteratorCurrent(const Dem_DtcIdListIterator *it)
{
   return (it->it);
}

/****************************DEMJ1939DTC************************************************/
#if(DEM_CFG_J1939DCM != DEM_CFG_J1939DCM_OFF)

typedef struct {
    const Dem_DtcIdType* it;
    const Dem_DtcIdType* end;
} Dem_DtcIdListIterator2;

typedef struct {
   const Dem_DtcIdType *mappingTable;
   uint16 length;
} Dem_J1939MemIDMapToDtcIdType;


#define DEM_START_SEC_CONST
#include "Dem_MemMap.h"
/* MR12 RULE 10.4 VIOLATION: Variable is defined the struct Dem_J1939MemIDMapToDtcIdType as uint16, no coversion issue */
extern const Dem_J1939MemIDMapToDtcIdType Dem_J1939MemIDMapToDtcId[DEM_J1939MEMID_ARRAYLENGTH + 1];
extern const Dem_DtcIdType Dem_J1939DtcId[DEM_J1939DTCID_ARRAYLENGTH];
#define DEM_STOP_SEC_CONST
#include "Dem_MemMap.h"

/*** LIST-ITERATOR ********************************************************/
/* ITERATOR for lists of DTCID: loop over all DTCs mapped to a memory*/

DEM_INLINE void Dem_J1939DtcIdListIteratorNewFromJ1939MemID(Dem_DtcIdListIterator2 *it, uint16_least memId)
{
    it->it = &Dem_J1939MemIDMapToDtcId[memId].mappingTable[0];
    it->end = &Dem_J1939MemIDMapToDtcId[memId].mappingTable[Dem_J1939MemIDMapToDtcId[memId].length];
}

DEM_INLINE void Dem_J1939DtcIdListIteratorNew(Dem_DtcIdListIterator2 *it)
{
    it->it = &Dem_J1939DtcId[0];
    it->end = &Dem_J1939DtcId[DEM_J1939DTCID_ARRAYLENGTH];
}

DEM_INLINE Dem_boolean_least Dem_J1939DtcIdListIteratorIsValid(const Dem_DtcIdListIterator2 *it)
{
   return (it->it < it->end);
}

DEM_INLINE void Dem_J1939DtcIdListIteratorNext(Dem_DtcIdListIterator2 *it)
{
   (it->it)++;
}

DEM_INLINE Dem_DtcIdType Dem_J1939DtcIdListIteratorCurrent(const Dem_DtcIdListIterator2 *it)
{
   return (Dem_DtcIdType)(*(it->it));
}

DEM_INLINE void Dem_J1939DtcIdIteratorDtcIdInvalidate(Dem_DtcIdListIterator2 *it)
{
    it->it = &Dem_J1939MemIDMapToDtcId[DEM_J1939MEMID_ARRAYLENGTH].mappingTable[0];
    it->end = &Dem_J1939MemIDMapToDtcId[DEM_J1939MEMID_ARRAYLENGTH].mappingTable[Dem_J1939MemIDMapToDtcId[DEM_J1939MEMID_ARRAYLENGTH].length];
}

#endif

/*** LIST-ITERATOR ********************************************************/

#if (DEM_CFG_DEPENDENCY == DEM_CFG_DEPENDENCY_ON)

/* ITERATOR for lists of EventIds: loop over all events assigned to a componentid */

typedef struct {
   Dem_EventIdType it;
   Dem_EventIdType end;
} Dem_EventIdListIterator2;


DEM_INLINE void Dem_EventIdListIterator2NewFromComponentId(Dem_EventIdListIterator2 *it, Dem_ComponentIdType componentid)
{
   if (!(Dem_ComponentIdIsValid(componentid)))
   {
 	  DEM_DET(DEM_DET_APIID_EVENTIDLISTITERATOR,1,0u);
   }
   it->it = Dem_MapComponentIdToEventId[componentid-1] + 1u;
   it->end = Dem_MapComponentIdToEventId[componentid];
}

DEM_INLINE Dem_boolean_least Dem_EventIdListIterator2IsValid(const Dem_EventIdListIterator2 *it)
{
   return (it->it <= it->end);
}

DEM_INLINE void Dem_EventIdListIterator2Next(Dem_EventIdListIterator2 *it)
{
   (it->it)++;
}

DEM_INLINE Dem_EventIdType Dem_EventIdListIterator2Current(const Dem_EventIdListIterator2 *it)
{
   return (it->it);
}


/*** LIST-ITERATORS ********************************************************/

/* ITERATOR for lists of componentIds: loop over all childcomponents of a component */

typedef struct {
	const Dem_ComponentIdType* it;
	const Dem_ComponentIdType* end;
} Dem_ComponentIdListIterator;


DEM_INLINE void Dem_ComponentIdListIteratorNewFromComponentId(Dem_ComponentIdListIterator *it, Dem_ComponentIdType componentid)
{
	if (!(Dem_ComponentIdIsValid(componentid)))
	{
		DEM_DET(DEM_DET_APIID_EVENTIDLISTITERATOR,2,0u);
	}
	it->it = &Dem_MapComponentIdToChildComponentId[Dem_ComponentToChildComponentIndex[componentid-1]];
	it->end = &Dem_MapComponentIdToChildComponentId[Dem_ComponentToChildComponentIndex[componentid]];
}

DEM_INLINE Dem_boolean_least Dem_ComponentIdListIteratorIsValid(const Dem_ComponentIdListIterator *it)
{
	return (Dem_boolean_least)(it->it < it->end);
}

DEM_INLINE void Dem_ComponentIdListIteratorNext(Dem_ComponentIdListIterator *it)
{
	(it->it)++;
}

DEM_INLINE Dem_ComponentIdType Dem_ComponentIdListIteratorCurrent(const Dem_ComponentIdListIterator *it)
{
	return (Dem_ComponentIdType)(*(it->it));
}

#endif

/*** LIST-ITERATORS ********************************************************/

/* ITERATOR for events belonging to emission related DTCs */

DEM_INLINE void Dem_EventIdIteratorNewEmissionRelated(Dem_EventIdIterator *it)
{
   (*it) = DEM_EVENTIDITERATORNEW;
   /* Skip non emission related DTCs: */
   while( (*it <= DEM_EVENTID_COUNT) &&
          ( !(Dem_EventIdIsDtcAssigned((Dem_EventIdType)*it)) ||
            (Dem_Cfg_Dtc_GetKind(Dem_DtcIdFromEventId((Dem_EventIdType)*it)) != DEM_DTC_KIND_EMISSION_REL_DTCS)))
   {
       (*it)++;
   }
}

DEM_INLINE void Dem_EventIdIteratorNextEmissionRelated(Dem_EventIdIterator *it)
{
   (*it)++;
   /* Skip non emission related DTCs: */
   while( (*it <= DEM_EVENTID_COUNT) &&
          ( !(Dem_EventIdIsDtcAssigned((Dem_EventIdType)*it)) ||
            (Dem_Cfg_Dtc_GetKind(Dem_DtcIdFromEventId((Dem_EventIdType)*it)) != DEM_DTC_KIND_EMISSION_REL_DTCS)))
   {
       (*it)++;
   }
}
#endif
