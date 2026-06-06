
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_EVMEM_H
#define DEM_CFG_EVMEM_H

#include "Dem_Cfg_Main.h"
#include "Dem_Cfg_DtcId.h"
#include "Dem_Cfg_Events.h"


/* ----------------------------------------------------------------------------
   Dynamic Configuration (BCT)
   ----------------------------------------------------------------------------
*/

/* definition of displacement strategies */
#define DEM_CFG_EVMEM_DISPLACEMENT_STRATEGY_AUTOSAR          1u
#define DEM_CFG_EVMEM_DISPLACEMENT_STRATEGY_FIFO             2u
#define DEM_CFG_EVMEM_DISPLACEMENT_STRATEGY_CUST             3u
#define DEM_CFG_EVMEM_DISPLACEMENT_STRATEGY_NONE             4u
/* event memory displacement strategy */
#define DEM_CFG_EVMEM_MEMORY_DISPLACEMENT_STRATEGY \
{ \
   DEM_CFG_EVMEM_DISPLACEMENT_STRATEGY_AUTOSAR  /* Primary memory memId */\
}
/* Is at least one memory is defined as custom displacement strategy */
#define DEM_CFG_EVMEM_IS_CUSTOM_DISPLACEMENT_STRATEGY        FALSE
#define DEM_CFG_EVMEM_MEMORY_DISPLACEMENT_STRATEGY_SIZE      (0u + 1u)

/* mirror memory displacement strategy */
#define DEM_CFG_EVMEM_MIRROR_DISPLACEMENT_STRATEGY           DEM_CFG_EVMEM_DISPLACEMENT_STRATEGY_AUTOSAR

/* event memory Entry Storage Trigger */
#define DEM_CFG_EVMEM_ENTRY_STORAGE_TRIGGER \
{ \
   DEM_TRIGGER_ON_CONFIRMED  /* Primary memory memId */\
}

/* Storage TestFailed */
#define DEM_CFG_EVMEM_STORAGE_TESTFAILED_SUPPORTED           TRUE

/* Status Byte Consistency Check Preference */
#define DEM_CFG_EVMEM_STATUS_BYTE_CONSISTENCY_PREFERENCE_STATUS_BYTE_BLOCK    1u
#define DEM_CFG_EVMEM_STATUS_BYTE_CONSISTENCY_PREFERENCE_EVENT_MEMORY         2u
#define DEM_CFG_EVMEM_STATUS_BYTE_CONSISTENCY_PREFERENCE                      DEM_CFG_EVMEM_STATUS_BYTE_CONSISTENCY_PREFERENCE_STATUS_BYTE_BLOCK

/* Occurrence Counter Processing */
#define DEM_CFG_EVMEM_OCCCOUNTER_TRIGGER_STSMASK \
{ \
   0u  /* Primary memory memId */\
}

#define DEM_CFG_EVMEM_OCCCOUNTER_TRIGGER_SIZE                (0u + 1u)

/* Support of Extended Data */
#define DEM_CFG_EVMEM_EXTENDED_DATA_SUPPORTED                TRUE
#define DEM_CFG_EVMEM_EXTENDED_DATA_ON_MIRROR_SUPPORTED      FALSE
#define DEM_CFG_EVMEM_EXTENDED_DATA_ON_PASSED_SUPPORTED      FALSE
#define DEM_CFG_EVMEM_TRIGGER_ON_FDC_SUPPORTED               FALSE

/* Support of Freeze Frame Data */
#define DEM_CFG_EVMEM_FREEZE_FRAME_SUPPORTED                 TRUE

/* Support of Test Failed This Failure Cycle */
#define DEM_CFG_EVMEM_TESTCOMPLETE_TFC_SUPPORTED             FALSE


/* Immediate NV Storage */
#define DEM_CFG_IMMEDIATE_NV_STORAGE_SUPPORTED               FALSE
#define DEM_CFG_IMMEDIATE_NV_STORAGE_LIMIT_SUPPORTED         FALSE
#define DEM_CFG_IMMEDIATE_NV_STORAGE_LIMIT                   0

/* Primary Memory */
#define DEM_CFG_MAX_NUMBER_EVENT_ENTRY_PRIMARY               40u

/* User defined memories */


#ifndef DEM_CFG_USERDEFINED_MEMORIES_NUMBER
#define DEM_CFG_USERDEFINED_MEMORIES_NUMBER                  0u
#endif

/* Mirror Memory */
#define DEM_CFG_MAX_NUMBER_EVENT_ENTRY_MIRROR                0u

/* Mirror Memory Type */
/* support of mirror memory method */
#define DEM_CFG_EVMEM_MIRROR_ON_FAILED                       1u
#define DEM_CFG_EVMEM_MIRROR_ON_CLEAR                        2u
#define DEM_CFG_EVMEM_MIRROR                                 DEM_CFG_EVMEM_MIRROR_ON_CLEAR
/* Mirror Memory Dtc Status */
#define DEM_CFG_EVMEM_MIRROR_MEMORY_DTC_STATUS_STORED        FALSE


/* Shadow Memory */
#define DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED                FALSE
#define DEM_CFG_EVMEM_MEMID_SHADOW                           DEM_CFG_EVMEM_MEMID_PRIMARY
/* Shadow Entries */
#define DEM_CFG_EVMEM_SHADOW_ENTRIES_VISIBLE                 FALSE
/* support & time-stamp for shadow entries */
#if (DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED || DEM_CFG_EVMEM_SHADOW_ENTRIES_VISIBLE)
#define DEM_CFG_EVMEM_SHADOW_ENTRIES_SUPPORTED               TRUE
#else
#define DEM_CFG_EVMEM_SHADOW_ENTRIES_SUPPORTED               FALSE
#endif
#define DEM_CFG_EVMEM_SHADOW_ENTRIES_TIMEID_SUPPORTED        DEM_CFG_EVMEM_SHADOW_ENTRIES_SUPPORTED

/* AgingCounter Type */
/* Aging counter method */
#define DEM_CFG_EVMEM_AGING_METHOD_COUNT_UP                  1u
#define DEM_CFG_EVMEM_AGING_METHOD_COUNT_DOWN                2u
#define DEM_CFG_EVMEM_AGING_METHOD_AGINGCYC_STORE            3u
#define DEM_CFG_EVMEM_AGING_METHOD_AGINGCYC_DIFF_UP          4u
#define DEM_CFG_EVMEM_AGING_METHOD_AGINGCYC_DIFF_DOWN        5u
#define DEM_CFG_EVMEM_AGING_METHOD_USER                      6u
/* support of aging counter for confirmed bit */
#define DEM_CFG_EVMEM_AGING_COUNTER_SUPPORTED                TRUE
#define DEM_CFG_EVMEM_AGING_METHOD                           DEM_CFG_EVMEM_AGING_METHOD_COUNT_UP
/* test failed this aging cycle supported */
#define DEM_CFG_EVMEM_TESTFAILED_TAC_SUPPORTED               TRUE
/* test complete this aging cycle supported */
#define DEM_CFG_EVMEM_TESTCOMPLETE_TAC_SUPPORTED             FALSE
/* aging counter max value (0x0001 ... 0xFFFF) */
#define DEM_CFG_EVMEM_AGING_COUNTER_MAX                      0xFF

/* OccurrenceCounter Type */
#define DEM_CFG_EVMEM_OCCURRENCE_COUNTER_SUPPORTED           TRUE

/* user defined storage & displacement strategy in event memory (primary and secondary) */
#define DEM_CFG_EVMEM_USERDEF_EVENT_MEM_STORAGE_STRATEGY     FALSE
/* user defined storage & displacement strategy in mirror memory */
#define DEM_CFG_EVMEM_USERDEF_MIRROR_MEM_STORAGE_STRATEGY    FALSE

/* reset confirmed bit on overflow in event memory */
#define DEM_CFG_EVMEM_RESET_CONFIRMED_BIT_ON_OVERFLOW        TRUE

#define DEM_CFG_EVMEM_PROJECT_EXTENSION                      FALSE

/* Enable additional synchronisation needed when event-related data is read synchronously from a different task */
#define DEM_CFG_EVMEM_READ_FROM_DIFFERENT_TASK               FALSE


/* ----------------------------------------------------------------------------
   Debug Configuration
   ----------------------------------------------------------------------------
*/
#if (DEM_CFG_BUILDTARGET == DEM_CFG_BUILDTARGET_DEMTESTSUITE)
   #define DEM_CFG_EVMEM_DEBUG_BITFIELDS                     TRUE
#else
   #define DEM_CFG_EVMEM_DEBUG_BITFIELDS                     FALSE
#endif

/* ----------------------------------------------------------------------------
   Static Configuration (may be changed manually)
   ----------------------------------------------------------------------------
*/
/* Service ReadDtcInformation - Subfunction 0x03: ReportDtcSnapshot Information  */
#define DEM_CFG_SERVICE_READDTCINFORMATION_SUBFUNC_0x03      TRUE
/* Service ReadDtcInformation - Subfunction 0x04: ReportDtcSnapshotRecordByDtcNumber  */
#define DEM_CFG_SERVICE_READDTCINFORMATION_SUBFUNC_0x04      TRUE
/* Service ReadDtcInformation - Subfunction 0x06: ReportDtcExtendedDataByDtcNumber */
#define DEM_CFG_SERVICE_READDTCINFORMATION_SUBFUNC_0x06      TRUE

/* event search strategy (effective for type 2) first <--> most recent */
#define DEM_CFG_EVMEM_EVENTSEARCH1_MOSTRECENT                1u
#define DEM_CFG_EVMEM_EVENTSEARCH1_FIRST                     2u
#define DEM_CFG_EVMEM_EVENTSEARCH1                           DEM_CFG_EVMEM_EVENTSEARCH1_MOSTRECENT

/* occurrence counter max value (0x0001 ... 0xFFFF) */
#define DEM_CFG_EVMEM_OCCURRENCE_COUNTER_MAX                 0xFFu

/* NV Storage */
#define DEM_CFG_EVMEM_SHUTDOWN_NV_STORAGE_SUPPORTED          TRUE

/* UserDefined Memories DTC Origin offset >= 0x100 */
#define DEM_CFG_EVMEM_USERDEFINED_DTC_ORIGIN_OFFSET          0x100u

/* Primary, Mirror, Permanent, obd relevant and invalid (UserDefined memories are not included as they are dynamic) */
#define DEM_CFG_EVMEM_ORIGIN2ID_LENGTH                       5u

/* ----------------------------------------------------------------------------
   NVRAM - Ids
   ----------------------------------------------------------------------------
*/
#define DEM_CFG_EVMEMNVMIDS \
{ \
   DEM_NVM_ID_EVMEM_LOC_0,\
   DEM_NVM_ID_EVMEM_LOC_1,\
   DEM_NVM_ID_EVMEM_LOC_2,\
   DEM_NVM_ID_EVMEM_LOC_3,\
   DEM_NVM_ID_EVMEM_LOC_4,\
   DEM_NVM_ID_EVMEM_LOC_5,\
   DEM_NVM_ID_EVMEM_LOC_6,\
   DEM_NVM_ID_EVMEM_LOC_7,\
   DEM_NVM_ID_EVMEM_LOC_8,\
   DEM_NVM_ID_EVMEM_LOC_9,\
   DEM_NVM_ID_EVMEM_LOC_10,\
   DEM_NVM_ID_EVMEM_LOC_11,\
   DEM_NVM_ID_EVMEM_LOC_12,\
   DEM_NVM_ID_EVMEM_LOC_13,\
   DEM_NVM_ID_EVMEM_LOC_14,\
   DEM_NVM_ID_EVMEM_LOC_15,\
   DEM_NVM_ID_EVMEM_LOC_16,\
   DEM_NVM_ID_EVMEM_LOC_17,\
   DEM_NVM_ID_EVMEM_LOC_18,\
   DEM_NVM_ID_EVMEM_LOC_19,\
   DEM_NVM_ID_EVMEM_LOC_20,\
   DEM_NVM_ID_EVMEM_LOC_21,\
   DEM_NVM_ID_EVMEM_LOC_22,\
   DEM_NVM_ID_EVMEM_LOC_23,\
   DEM_NVM_ID_EVMEM_LOC_24,\
   DEM_NVM_ID_EVMEM_LOC_25,\
   DEM_NVM_ID_EVMEM_LOC_26,\
   DEM_NVM_ID_EVMEM_LOC_27,\
   DEM_NVM_ID_EVMEM_LOC_28,\
   DEM_NVM_ID_EVMEM_LOC_29,\
   DEM_NVM_ID_EVMEM_LOC_30,\
   DEM_NVM_ID_EVMEM_LOC_31,\
   DEM_NVM_ID_EVMEM_LOC_32,\
   DEM_NVM_ID_EVMEM_LOC_33,\
   DEM_NVM_ID_EVMEM_LOC_34,\
   DEM_NVM_ID_EVMEM_LOC_35,\
   DEM_NVM_ID_EVMEM_LOC_36,\
   DEM_NVM_ID_EVMEM_LOC_37,\
   DEM_NVM_ID_EVMEM_LOC_38,\
   DEM_NVM_ID_EVMEM_LOC_39\
}

/* ----------------------------------------------------------------------------
   Event Memory IDs (BCT Dynamic)
   ----------------------------------------------------------------------------
*/

#define DEM_CFG_EVMEM_MEMID_PRIMARY                         (0u)

#define DEM_CFG_EVMEM_MEMID_MIRROR                           DEM_EVMEM_INVALID_MEMID
#define DEM_CFG_EVMEM_MIRROR_MEMORY_SUPPORTED                FALSE

#define DEM_CFG_EVMEM_MAX_MEMS                               1u

#define DEM_CFG_MAX_NUMBER_EVENT_ENTRY_USERDEFINED           0u /* Total event entry of userdefined memories combined */

#define DEM_CFG_MAX_NUMBER_EVENT_ENTRY_ALL                  (DEM_CFG_MAX_NUMBER_EVENT_ENTRY_PRIMARY + DEM_CFG_MAX_NUMBER_EVENT_ENTRY_USERDEFINED + DEM_CFG_MAX_NUMBER_EVENT_ENTRY_MIRROR)

/* ----------------------------------------------------------------------------
   User Defined Memories Mapping (BCT Dynamic)
   ----------------------------------------------------------------------------
*/

#define DEM_CFG_USERDEFINED_MEMORY_MAP \
{ \
\
}

/* ----------------------------------------------------------------------------
   Memories location ID Mapping (BCT Dynamic)
   ----------------------------------------------------------------------------
*/

/* User defined memories location ID */
/* Mirror memory location ID */
#if (DEM_CFG_MAX_NUMBER_EVENT_ENTRY_MIRROR > 0)
#define DEM_LOCIDLIST_INIT_MIRROR                    (DEM_CFG_MAX_NUMBER_EVENT_ENTRY_PRIMARY + DEM_CFG_MAX_NUMBER_EVENT_ENTRY_MIRROR)
#else
#define DEM_LOCIDLIST_INIT_MIRROR
#endif

/* User defined Memories will not be accepted without minimal size of 1 */
#define DEM_LOCIDLIST_INIT { \
        0u, \
        DEM_CFG_MAX_NUMBER_EVENT_ENTRY_PRIMARY, \
        DEM_LOCIDLIST_INIT_MIRROR \
}

/* ----------------------------------------------------------------------------
   sanity checks
   ----------------------------------------------------------------------------
*/


#if (DEM_CFG_EVMEM_SHADOW_MEMORY_SUPPORTED && DEM_CFG_EVMEM_MIRROR_MEMORY_SUPPORTED)
  #error only mirror memory OR shadow memory is supported
#endif

/* end of include protection */
#endif


