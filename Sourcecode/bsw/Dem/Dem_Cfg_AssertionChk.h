
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ASSERTIONCHK_H
#define DEM_CFG_ASSERTIONCHK_H

#include "Dem_Lib.h"
#include "Dem_EventStatus.h"
#include "Dem_GenericNvData.h"
#include "Dem_DisturbanceMemory.h"
#include "Dem_Obd.h"


/* -------------------------------------------------- */
/* DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH       */
/* -------------------------------------------------- */
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON   STD_ON
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_OFF  STD_OFF
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH  DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON

#if(DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH == DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON)
/* Macros which defines the block size of each configured NvM Block */
#define  DEM_NVM_ID_DEM_GENERIC_NV_DATA_SIZE                DEM_SIZEOF_VAR(Dem_GenericNvData)

#define  DEM_NVM_ID_EVMEM_LOC_0_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_1_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_10_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_11_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_12_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_13_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_14_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_15_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_16_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_17_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_18_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_19_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_2_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_20_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_21_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_22_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_23_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_24_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_25_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_26_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_27_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_28_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_29_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_3_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_30_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_31_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_32_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_33_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_34_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_35_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_36_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_37_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_38_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_39_SIZE                       DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_4_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_5_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_6_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_7_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_8_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVMEM_LOC_9_SIZE                        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)

#define  DEM_NVM_ID_EVT_STATUSBYTE_SIZE                     DEM_SIZEOF_VAR(Dem_AllEventsStatusByte)


DEM_STATIC_ASSERT((DEM_SIZEOF_VAR(Dem_GenericNvData)==DEM_NVM_ID_DEM_GENERIC_NV_DATA_SIZE),DEM_NVM_ID_DEM_GENERIC_NV_DATA_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_0_SIZE),DEM_NVM_ID_EVMEM_LOC_0_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_1_SIZE),DEM_NVM_ID_EVMEM_LOC_1_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_10_SIZE),DEM_NVM_ID_EVMEM_LOC_10_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_11_SIZE),DEM_NVM_ID_EVMEM_LOC_11_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_12_SIZE),DEM_NVM_ID_EVMEM_LOC_12_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_13_SIZE),DEM_NVM_ID_EVMEM_LOC_13_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_14_SIZE),DEM_NVM_ID_EVMEM_LOC_14_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_15_SIZE),DEM_NVM_ID_EVMEM_LOC_15_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_16_SIZE),DEM_NVM_ID_EVMEM_LOC_16_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_17_SIZE),DEM_NVM_ID_EVMEM_LOC_17_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_18_SIZE),DEM_NVM_ID_EVMEM_LOC_18_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_19_SIZE),DEM_NVM_ID_EVMEM_LOC_19_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_2_SIZE),DEM_NVM_ID_EVMEM_LOC_2_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_20_SIZE),DEM_NVM_ID_EVMEM_LOC_20_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_21_SIZE),DEM_NVM_ID_EVMEM_LOC_21_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_22_SIZE),DEM_NVM_ID_EVMEM_LOC_22_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_23_SIZE),DEM_NVM_ID_EVMEM_LOC_23_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_24_SIZE),DEM_NVM_ID_EVMEM_LOC_24_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_25_SIZE),DEM_NVM_ID_EVMEM_LOC_25_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_26_SIZE),DEM_NVM_ID_EVMEM_LOC_26_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_27_SIZE),DEM_NVM_ID_EVMEM_LOC_27_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_28_SIZE),DEM_NVM_ID_EVMEM_LOC_28_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_29_SIZE),DEM_NVM_ID_EVMEM_LOC_29_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_3_SIZE),DEM_NVM_ID_EVMEM_LOC_3_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_30_SIZE),DEM_NVM_ID_EVMEM_LOC_30_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_31_SIZE),DEM_NVM_ID_EVMEM_LOC_31_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_32_SIZE),DEM_NVM_ID_EVMEM_LOC_32_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_33_SIZE),DEM_NVM_ID_EVMEM_LOC_33_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_34_SIZE),DEM_NVM_ID_EVMEM_LOC_34_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_35_SIZE),DEM_NVM_ID_EVMEM_LOC_35_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_36_SIZE),DEM_NVM_ID_EVMEM_LOC_36_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_37_SIZE),DEM_NVM_ID_EVMEM_LOC_37_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_38_SIZE),DEM_NVM_ID_EVMEM_LOC_38_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_39_SIZE),DEM_NVM_ID_EVMEM_LOC_39_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_4_SIZE),DEM_NVM_ID_EVMEM_LOC_4_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_5_SIZE),DEM_NVM_ID_EVMEM_LOC_5_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_6_SIZE),DEM_NVM_ID_EVMEM_LOC_6_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_7_SIZE),DEM_NVM_ID_EVMEM_LOC_7_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_8_SIZE),DEM_NVM_ID_EVMEM_LOC_8_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_9_SIZE),DEM_NVM_ID_EVMEM_LOC_9_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_VAR(Dem_AllEventsStatusByte)==DEM_NVM_ID_EVT_STATUSBYTE_SIZE),DEM_NVM_ID_EVT_STATUSBYTE_BlockLengthIsInvalid);

#endif

#endif

