

// TRACE[NVM321]
// NvM file containing all configuration parameters which are to be implemented as constants

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "NvM_Cfg.h"
#include "NvM_Prv_HideRteApi.h"

#if (defined(TESTCD_NVM_ENABLED) && (TESTCD_NVM_ENABLED == STD_ON))
/* prevent inclusion of TestCd_NvM.h to avoid warnings */
# define TESTCD_NVM_H
# define TESTCD_NO_INLINE
#endif

#include "MemIf.h"
// TRACE[NVM089]
// Check version compatibility of included header files
#if (!defined(MEMIF_AR_RELEASE_MAJOR_VERSION) || (MEMIF_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION))
    #error "AUTOSAR major version undefined or mismatched"
#endif

#if (NVM_CRYPTO_USED == STD_ON)
# include "Csm.h"
// TRACE[NVM089] Check version compatibility of included header files
# if (!defined(CSM_AR_RELEASE_MAJOR_VERSION) || (CSM_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION))
#  error "AUTOSAR major version undefined or mismatched"
# endif
# if (!defined(CSM_AR_RELEASE_MINOR_VERSION) || (CSM_AR_RELEASE_MINOR_VERSION < 3))
#  error "AUTOSAR minor version undefined or mismatched"
# endif
#endif

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_InternalBuffer.h"

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-2997]
// Include customer/user specific declarations
#include "EcuM.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/
// Explicit sync read callback of NVRAM block NVM_ID_DEM_GENERIC_NV_DATA
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_GenericNVDataReadRamBlockFromNvCallback(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_DEM_GENERIC_NV_DATA
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_GenericNVDataWriteRamBlockToNvCallback(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_0
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback0(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_0
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback0(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_1
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback1(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_1
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback1(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_10
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback10(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_10
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback10(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_11
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback11(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_11
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback11(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_12
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback12(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_12
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback12(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_13
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback13(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_13
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback13(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_14
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback14(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_14
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback14(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_15
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback15(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_15
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback15(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_16
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback16(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_16
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback16(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_17
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback17(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_17
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback17(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_18
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback18(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_18
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback18(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_19
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback19(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_19
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback19(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_2
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback2(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_2
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback2(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_20
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback20(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_20
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback20(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_21
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback21(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_21
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback21(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_22
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback22(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_22
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback22(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_23
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback23(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_23
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback23(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_24
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback24(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_24
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback24(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_25
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback25(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_25
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback25(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_26
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback26(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_26
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback26(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_27
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback27(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_27
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback27(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_28
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback28(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_28
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback28(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_29
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback29(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_29
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback29(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_3
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback3(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_3
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback3(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_30
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback30(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_30
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback30(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_31
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback31(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_31
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback31(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_32
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback32(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_32
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback32(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_33
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback33(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_33
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback33(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_34
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback34(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_34
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback34(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_35
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback35(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_35
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback35(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_36
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback36(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_36
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback36(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_37
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback37(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_37
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback37(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_38
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback38(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_38
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback38(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_39
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback39(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_39
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback39(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_4
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback4(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_4
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback4(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_5
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback5(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_5
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback5(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_6
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback6(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_6
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback6(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_7
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback7(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_7
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback7(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_8
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback8(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_8
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback8(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVMEM_LOC_9
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback9(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVMEM_LOC_9
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback9(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NVM_ID_EVT_STATUSBYTE
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EventStatusByteReadRamBlockFromNvCallback(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NVM_ID_EVT_STATUSBYTE
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern Std_ReturnType Dem_EventStatusByteWriteRamBlockToNvCallback(void* NvMBuffer);

// RAM block of NVRAM block NV_CrcBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Fbl_DataM_RamMirrorNV_CrcBlock[];

// ROM block start address of NVRAM block NV_CrcBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Fbl_DataM_RomDataNV_CrcBlock[];

// RAM block of NVRAM block NV_ExternalReprogrammingRequestFlagBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Fbl_DataM_RamMirrorNV_ReprogrammingRequestFlagBlock[];

// ROM block start address of NVRAM block NV_ExternalReprogrammingRequestFlagBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Fbl_DataM_RomDataNV_ReprogrammingRequestFlagBlock[];

// RAM block of NVRAM block NV_PartNumberBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Fbl_DataM_RamMirrorNV_PartNumberBlock[];

// ROM block start address of NVRAM block NV_PartNumberBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Fbl_DataM_RomDataNV_PartNumberBlock[];

// RAM block of NVRAM block NV_ProgrammingAttemptCounterBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Fbl_DataM_RamMirrorNV_ProgrammingAttemptCounterBlock[];

// ROM block start address of NVRAM block NV_ProgrammingAttemptCounterBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Fbl_DataM_RomDataNV_ProgrammingAttemptCounterBlock[];

// RAM block of NVRAM block NV_ProgrammingCounterBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Fbl_DataM_RamMirrorNV_ProgrammingCounterBlock[];

// ROM block start address of NVRAM block NV_ProgrammingCounterBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Fbl_DataM_RomDataNV_ProgrammingCounterBlock[];

// RAM block of NVRAM block NV_ResetResponseFlagBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Fbl_DataM_RamMirrorNV_ResetResponseBlock[];

// ROM block start address of NVRAM block NV_ResetResponseFlagBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Fbl_DataM_RomDataNV_ResetResponseBlock[];

// RAM block of NVRAM block NV_ValidityFlagsBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Fbl_DataM_RamMirrorNV_ValidityFlagsBlock[];

// ROM block start address of NVRAM block NV_ValidityFlagsBlock
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Fbl_DataM_RomDataNV_ValidityFlagsBlock[];

// RAM block of NVRAM block NvMBlockDescriptor_DID_IOControl
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 RamBlock_DID_IOControl[];

// RAM block of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 RamBlock_DID_SystemFaultRank[];

// RAM block of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 RamBlock_DID_VehicleSpeed[];

// RAM block of NVRAM block NvMBlockDescriptor_ReadWritebyAddress
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 RamBlock_DID_ReadWritebyAddress[];

// RAM block of NVRAM block NvM_BN_DID_D09A
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BN_DID_D09A[];

// ROM block start address of NVRAM block NvM_BN_DID_D09A
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BN_D09A[];

// RAM block of NVRAM block NvM_BN_DID_F190
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BN_DID_F190[];

// ROM block start address of NVRAM block NvM_BN_DID_F190
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BN_F190[];

// RAM block of NVRAM block NvM_BR_AngCorrectStored
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored[];

// ROM block start address of NVRAM block NvM_BR_AngCorrectStored
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngCorrectStored[];

// RAM block of NVRAM block NvM_BR_AngEndCalData
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData[];

// ROM block start address of NVRAM block NvM_BR_AngEndCalData
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngEndCalData[];

// RAM block of NVRAM block NvM_BR_AngValidEnd
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd[];

// ROM block start address of NVRAM block NvM_BR_AngValidEnd
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_AngValidEnd[];

// RAM block of NVRAM block NvM_BR_BackupConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_BackupConfig[];

// ROM block start address of NVRAM block NvM_BR_BackupConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_BackupConfig[];

// RAM block of NVRAM block NvM_BR_CCPVal
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal[];

// ROM block start address of NVRAM block NvM_BR_CCPVal
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CCPVal[];

// RAM block of NVRAM block NvM_BR_CommonCRCStored
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored[];

// ROM block start address of NVRAM block NvM_BR_CommonCRCStored
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CommonCRCStored[];

// RAM block of NVRAM block NvM_BR_CurrentOffset
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset[];

// ROM block start address of NVRAM block NvM_BR_CurrentOffset
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_CurrentOffset[];

// RAM block of NVRAM block NvM_BR_FunConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_FunConfig[];

// ROM block start address of NVRAM block NvM_BR_FunConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_FunConfig[];

// RAM block of NVRAM block NvM_BR_InitAngle
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle[];

// ROM block start address of NVRAM block NvM_BR_InitAngle
// Same ROM block as used in NVRAM block NvM_BR_CurrentOffset

// RAM block of NVRAM block NvM_BR_Mileage
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_Mileage[];

// ROM block start address of NVRAM block NvM_BR_Mileage
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_Mileage[];

// RAM block of NVRAM block NvM_BR_PenProf
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf[];

// ROM block start address of NVRAM block NvM_BR_PenProf
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_PenProf[];

// RAM block of NVRAM block NvM_BR_ResetFlag
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_ResetFlag[];

// ROM block start address of NVRAM block NvM_BR_ResetFlag
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_ResetFlag[];

// RAM block of NVRAM block NvM_BR_RotorOffset
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset[];

// ROM block start address of NVRAM block NvM_BR_RotorOffset
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_RotorOffset[];

// RAM block of NVRAM block NvM_BR_SoftwareConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_SoftwareConfig[];

// ROM block start address of NVRAM block NvM_BR_SoftwareConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_SoftwareConfig[];

// RAM block of NVRAM block NvM_BR_StrAngZero
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero[];

// ROM block start address of NVRAM block NvM_BR_StrAngZero
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_StrAngZero[];

// RAM block of NVRAM block NvM_BR_TOCStudyTrq
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_TOCStudyTrq[];

// ROM block start address of NVRAM block NvM_BR_TOCStudyTrq
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_TOCStudyTrq[];

// RAM block of NVRAM block NvM_BR_TestMode
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_TestMode[];

// ROM block start address of NVRAM block NvM_BR_TestMode
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_TestMode[];

// RAM block of NVRAM block NvM_BR_VIN
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_VIN[];

// ROM block start address of NVRAM block NvM_BR_VIN
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VIN[];

// RAM block of NVRAM block NvM_BR_VehicleConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_VehicleConfig[];

// ROM block start address of NVRAM block NvM_BR_VehicleConfig
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleConfig[];

// RAM block of NVRAM block NvM_BR_VehicleName
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BR_VehicleName[];

// ROM block start address of NVRAM block NvM_BR_VehicleName
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleName[];

// RAM block of NVRAM block NvM_NATIVE_IDS_1024
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_IDS_1024[];

// ROM block start address of NVRAM block NvM_NATIVE_IDS_1024
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNativeIDS_1024[];

// RAM block of NVRAM block NvM_NativeBlock_2
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_1[];

// ROM block start address of NVRAM block NvM_NativeBlock_2
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_1[];

// RAM block of NVRAM block NvM_NativeBlock_3
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[];

// ROM block start address of NVRAM block NvM_NativeBlock_3
/* MR12 RULE 8.5, 8.6, DIR 1.1 VIOLATION: If we declared this in NvM_Cfg.h,
   we would effectively re-export this to all NvM users.
   Either use short identifier or configure the compiler to differentiate more than 63 chars. */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_2[];


/*
 **********************************************************************************************************************
 * Assertions
 **********************************************************************************************************************
*/
/* Block length check for Ram block data address of NVRAM block ECUM_CFG_NVM_BLOCK
   Checks the configured block length against the actual data size determined by the included header-file. */
/* MR12 DIR 1.1, RULE 1.1, 8.6, 14.3 VIOLATION: RB compiler assert is using mechanisms which makes the violations necessary. */
COMPILER_RB_ASSERT_GLOBAL(sizeof(EcuM_Rb_dataShutdownInfo_st)==(4u), ECUM_CFG_NVM_BLOCK_CheckRamBlockLength)

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

// Array containing (persistent Id, block Id) couples sorted by ascendant persistent Ids
const NvM_Prv_PersId_BlockId_tst NvM_Prv_PersId_BlockId_acst[NVM_PRV_NR_PERSISTENT_IDS] =
{
    //{PersId, BlockId}
    {32u, 58u},          // NvMConf_NvMBlockDescriptor_NvM_BR_AngCorrectStored
    {560u, 38u},         // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_4
    {945u, 39u},         // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_5
    {3127u, 51u},        // NvMConf_NvMBlockDescriptor_NV_ValidityFlagsBlock
    {4104u, 69u},        // NvMConf_NvMBlockDescriptor_NvM_BR_ResetFlag
    {4154u, 41u},        // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_7
    {4539u, 40u},        // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_6
    {5793u, 47u},        // NvMConf_NvMBlockDescriptor_NV_PartNumberBlock
    {6158u, 76u},        // NvMConf_NvMBlockDescriptor_NvM_BR_VehicleConfig
    {6815u, 63u},        // NvMConf_NvMBlockDescriptor_NvM_BR_CommonCRCStored
    {7577u, 73u},        // NvMConf_NvMBlockDescriptor_NvM_BR_TOCStudyTrq
    {8494u, 62u},        // NvMConf_NvMBlockDescriptor_NvM_BR_CCPVal
    {9383u, 5u},         // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_1
    {9510u, 4u},         // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_0
    {11709u, 14u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_18
    {11967u, 26u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_29
    {12094u, 37u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_39
    {13997u, 16u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_2
    {14124u, 27u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_3
    {15541u, 15u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_19
    {15926u, 36u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_38
    {16311u, 25u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_28
    {16680u, 53u},       // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_SystemFaultRank
    {19105u, 3u},        // NvMConf_NvMBlockDescriptor_NVM_ID_DEM_GENERIC_NV_DATA
    {19119u, 49u},       // NvMConf_NvMBlockDescriptor_NV_ProgrammingCounterBlock
    {19359u, 74u},       // NvMConf_NvMBlockDescriptor_NvM_BR_TestMode
    {20742u, 44u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVT_STATUSBYTE
    {20903u, 77u},       // NvMConf_NvMBlockDescriptor_NvM_BR_VehicleName
    {21762u, 45u},       // NvMConf_NvMBlockDescriptor_NV_CrcBlock
    {25370u, 72u},       // NvMConf_NvMBlockDescriptor_NvM_BR_StrAngZero
    {27275u, 43u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_9
    {27402u, 42u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_8
    {30244u, 1u},        // NvMConf_NvMBlockDescriptor_NvM_ConfigId
    {31280u, 65u},       // NvMConf_NvMBlockDescriptor_NvM_BR_FunConfig
    {32657u, 64u},       // NvMConf_NvMBlockDescriptor_NvM_BR_CurrentOffset
    {32702u, 46u},       // NvMConf_NvMBlockDescriptor_NV_ExternalReprogrammingRequestFlagBlock
    {33896u, 29u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_31
    {34281u, 18u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_21
    {34539u, 6u},        // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_10
    {35799u, 60u},       // NvMConf_NvMBlockDescriptor_NvM_BR_AngValidEnd
    {38113u, 17u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_20
    {38240u, 28u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_30
    {38883u, 7u},        // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_11
    {39665u, 56u},       // NvMConf_NvMBlockDescriptor_NvM_BN_DID_D09A
    {39806u, 55u},       // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ReadWritebyAddress
    {40404u, 52u},       // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_IOControl
    {41675u, 79u},       // NvMConf_NvMBlockDescriptor_NvM_NativeBlock_2
    {42106u, 8u},        // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_12
    {42745u, 31u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_33
    {42872u, 20u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_23
    {45679u, 54u},       // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_VehicleSpeed
    {45890u, 80u},       // NvMConf_NvMBlockDescriptor_NvM_NativeBlock_3
    {46450u, 9u},        // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_13
    {46704u, 19u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_22
    {46837u, 48u},       // NvMConf_NvMBlockDescriptor_NV_ProgrammingAttemptCounterBlock
    {47089u, 30u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_32
    {49355u, 32u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_34
    {49482u, 21u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_24
    {49736u, 11u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_15
    {50040u, 66u},       // NvMConf_NvMBlockDescriptor_NvM_BR_InitAngle
    {53203u, 78u},       // NvMConf_NvMBlockDescriptor_NvM_NATIVE_IDS_1024
    {53314u, 22u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_25
    {53699u, 33u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_35
    {53959u, 70u},       // NvMConf_NvMBlockDescriptor_NvM_BR_RotorOffset
    {54080u, 10u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_14
    {54898u, 67u},       // NvMConf_NvMBlockDescriptor_NvM_BR_Mileage
    {55314u, 61u},       // NvMConf_NvMBlockDescriptor_NvM_BR_BackupConfig
    {55531u, 68u},       // NvMConf_NvMBlockDescriptor_NvM_BR_PenProf
    {56189u, 57u},       // NvMConf_NvMBlockDescriptor_NvM_BN_DID_F190
    {56787u, 71u},       // NvMConf_NvMBlockDescriptor_NvM_BR_SoftwareConfig
    {57561u, 13u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_17
    {57946u, 34u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_36
    {58101u, 59u},       // NvMConf_NvMBlockDescriptor_NvM_BR_AngEndCalData
    {58331u, 23u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_26
    {59481u, 50u},       // NvMConf_NvMBlockDescriptor_NV_ResetResponseFlagBlock
    {61905u, 12u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_16
    {62163u, 24u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_27
    {62199u, 2u},        // NvMConf_NvMBlockDescriptor_ECUM_CFG_NVM_BLOCK
    {62290u, 35u},       // NvMConf_NvMBlockDescriptor_NVM_ID_EVMEM_LOC_37
    {64117u, 75u},       // NvMConf_NvMBlockDescriptor_NvM_BR_VIN
};

// TRACE[NVM028_Conf]
// Structure containing common configuration options
const NvM_Prv_Common_tst NvM_Prv_Common_cst =
{
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};

// TRACE[NVM061_Conf]
// Array containing block descriptors
// TRACE[NVM140]
// The block descriptor contents are completely determined by configuration
const NvM_Prv_BlockDescriptor_tst NvM_Prv_BlockDescriptors_acst[NVM_CFG_NR_BLOCKS] =
{
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_MultiBlock (NvM block ID: 0):
        0u, // MemIf block ID (this block is not stored on any memory device)
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[0]), // Block length calculated on compile time
        1u, // block length in bytes stored on the medium
        0u, // Device index (here: not applicable)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[0]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        0u,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        0u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_ConfigId (NvM block ID: 1, persistent ID: 30244):
        FeeConf_FeeBlockConfiguration_NvM_ConfigId, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[1]), // Block length calculated on compile time
        2u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[1]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        30244u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 2, persistent ID: 62199):
        FeeConf_FeeBlockConfiguration_ECUM_CFG_NVM_BLOCK, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[2]), // Block length calculated on compile time
        4u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[2]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        &EcuM_Rb_NvMSingleBlockCallbackFunction, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        62199u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_DEM_GENERIC_NV_DATA (NvM block ID: 3, persistent ID: 19105):
        FeeConf_FeeBlockConfiguration_NVM_ID_DEM_GENERIC_NV_DATA, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[3]), // Block length calculated on compile time
        (DEM_SIZEOF_VAR(Dem_GenericNvData) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[3]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_GenericNVDataReadRamBlockFromNvCallback, // Explicit sync read callback
        &Dem_GenericNVDataWriteRamBlockToNvCallback, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        19105u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_0 (NvM block ID: 4, persistent ID: 9510):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_0, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[4]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[4]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback0, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback0, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        9510u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_1 (NvM block ID: 5, persistent ID: 9383):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_1, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[5]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[5]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback1, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback1, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        9383u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_10 (NvM block ID: 6, persistent ID: 34539):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_10, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[6]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[6]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback10, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback10, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        34539u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_11 (NvM block ID: 7, persistent ID: 38883):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_11, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[7]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[7]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback11, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback11, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        38883u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_12 (NvM block ID: 8, persistent ID: 42106):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_12, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[8]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[8]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback12, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback12, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        42106u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_13 (NvM block ID: 9, persistent ID: 46450):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_13, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[9]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[9]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback13, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback13, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        46450u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_14 (NvM block ID: 10, persistent ID: 54080):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_14, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[10]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[10]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback14, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback14, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        54080u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_15 (NvM block ID: 11, persistent ID: 49736):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_15, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[11]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[11]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback15, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback15, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        49736u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_16 (NvM block ID: 12, persistent ID: 61905):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_16, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[12]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[12]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback16, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback16, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        61905u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_17 (NvM block ID: 13, persistent ID: 57561):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_17, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[13]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[13]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback17, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback17, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        57561u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_18 (NvM block ID: 14, persistent ID: 11709):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_18, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[14]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[14]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback18, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback18, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        11709u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_19 (NvM block ID: 15, persistent ID: 15541):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_19, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[15]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[15]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback19, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback19, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        15541u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_2 (NvM block ID: 16, persistent ID: 13997):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_2, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[16]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[16]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback2, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback2, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        13997u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_20 (NvM block ID: 17, persistent ID: 38113):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_20, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[17]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[17]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback20, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback20, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        38113u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_21 (NvM block ID: 18, persistent ID: 34281):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_21, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[18]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[18]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback21, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback21, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        34281u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_22 (NvM block ID: 19, persistent ID: 46704):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_22, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[19]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[19]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback22, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback22, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        46704u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_23 (NvM block ID: 20, persistent ID: 42872):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_23, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[20]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[20]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback23, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback23, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        42872u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_24 (NvM block ID: 21, persistent ID: 49482):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_24, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[21]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[21]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback24, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback24, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        49482u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_25 (NvM block ID: 22, persistent ID: 53314):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_25, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[22]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[22]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback25, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback25, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        53314u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_26 (NvM block ID: 23, persistent ID: 58331):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_26, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[23]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[23]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback26, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback26, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        58331u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_27 (NvM block ID: 24, persistent ID: 62163):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_27, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[24]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[24]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback27, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback27, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        62163u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_28 (NvM block ID: 25, persistent ID: 16311):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_28, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[25]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[25]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback28, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback28, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        16311u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_29 (NvM block ID: 26, persistent ID: 11967):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_29, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[26]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[26]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback29, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback29, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        11967u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_3 (NvM block ID: 27, persistent ID: 14124):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_3, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[27]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[27]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback3, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback3, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        14124u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_30 (NvM block ID: 28, persistent ID: 38240):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_30, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[28]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[28]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback30, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback30, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        38240u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_31 (NvM block ID: 29, persistent ID: 33896):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_31, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[29]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[29]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback31, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback31, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        33896u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_32 (NvM block ID: 30, persistent ID: 47089):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_32, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[30]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[30]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback32, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback32, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        47089u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_33 (NvM block ID: 31, persistent ID: 42745):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_33, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[31]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[31]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback33, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback33, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        42745u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_34 (NvM block ID: 32, persistent ID: 49355):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_34, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[32]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[32]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback34, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback34, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        49355u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_35 (NvM block ID: 33, persistent ID: 53699):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_35, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[33]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[33]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback35, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback35, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        53699u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_36 (NvM block ID: 34, persistent ID: 57946):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_36, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[34]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[34]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback36, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback36, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        57946u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_37 (NvM block ID: 35, persistent ID: 62290):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_37, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[35]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[35]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback37, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback37, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        62290u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_38 (NvM block ID: 36, persistent ID: 15926):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_38, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[36]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[36]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback38, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback38, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        15926u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_39 (NvM block ID: 37, persistent ID: 12094):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_39, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[37]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[37]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback39, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback39, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        12094u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_4 (NvM block ID: 38, persistent ID: 560):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_4, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[38]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[38]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback4, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback4, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        560u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_5 (NvM block ID: 39, persistent ID: 945):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_5, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[39]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[39]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback5, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback5, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        945u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_6 (NvM block ID: 40, persistent ID: 4539):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_6, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[40]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[40]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback6, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback6, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        4539u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_7 (NvM block ID: 41, persistent ID: 4154):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_7, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[41]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[41]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback7, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback7, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        4154u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_8 (NvM block ID: 42, persistent ID: 27402):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_8, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[42]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[42]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback8, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback8, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        27402u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVMEM_LOC_9 (NvM block ID: 43, persistent ID: 27275):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVMEM_LOC_9, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[43]), // Block length calculated on compile time
        (DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[43]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback9, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback9, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        27275u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NVM_ID_EVT_STATUSBYTE (NvM block ID: 44, persistent ID: 20742):
        FeeConf_FeeBlockConfiguration_NVM_ID_EVT_STATUSBYTE, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[44]), // Block length calculated on compile time
        (DEM_SIZEOF_VAR(Dem_AllEventsStatusByte) + 0), // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[44]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EventStatusByteReadRamBlockFromNvCallback, // Explicit sync read callback
        &Dem_EventStatusByteWriteRamBlockToNvCallback, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint32)NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        20742u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NV_CrcBlock (NvM block ID: 45, persistent ID: 21762):
        FeeConf_FeeBlockConfiguration_NV_CrcBlock, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[45]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[45]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Fbl_DataM_RomDataNV_CrcBlock), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        21762u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NV_ExternalReprogrammingRequestFlagBlock (NvM block ID: 46, persistent ID: 32702):
        FeeConf_FeeBlockConfiguration_NV_ExternalReprogrammingRequestFlagBlock, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[46]), // Block length calculated on compile time
        1u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[46]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Fbl_DataM_RomDataNV_ReprogrammingRequestFlagBlock), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        32702u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NV_PartNumberBlock (NvM block ID: 47, persistent ID: 5793):
        FeeConf_FeeBlockConfiguration_NV_PartNumberBlock, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[47]), // Block length calculated on compile time
        32u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[47]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Fbl_DataM_RomDataNV_PartNumberBlock), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_RAM_INIT_UNCONDITIONAL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        5793u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NV_ProgrammingAttemptCounterBlock (NvM block ID: 48, persistent ID: 46837):
        FeeConf_FeeBlockConfiguration_NV_ProgrammingAttemptCounterBlock, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[48]), // Block length calculated on compile time
        4u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[48]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Fbl_DataM_RomDataNV_ProgrammingAttemptCounterBlock), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        46837u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NV_ProgrammingCounterBlock (NvM block ID: 49, persistent ID: 19119):
        FeeConf_FeeBlockConfiguration_NV_ProgrammingCounterBlock, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[49]), // Block length calculated on compile time
        4u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[49]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Fbl_DataM_RomDataNV_ProgrammingCounterBlock), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        19119u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NV_ResetResponseFlagBlock (NvM block ID: 50, persistent ID: 59481):
        FeeConf_FeeBlockConfiguration_NV_ResetResponseFlagBlock, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[50]), // Block length calculated on compile time
        1u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[50]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Fbl_DataM_RomDataNV_ResetResponseBlock), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        59481u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NV_ValidityFlagsBlock (NvM block ID: 51, persistent ID: 3127):
        FeeConf_FeeBlockConfiguration_NV_ValidityFlagsBlock, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[51]), // Block length calculated on compile time
        1u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[51]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Fbl_DataM_RomDataNV_ValidityFlagsBlock), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        3127u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvMBlockDescriptor_DID_IOControl (NvM block ID: 52, persistent ID: 40404):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_IOControl, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[52]), // Block length calculated on compile time
        17u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[52]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        40404u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank (NvM block ID: 53, persistent ID: 16680):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_SystemFaultRank, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[53]), // Block length calculated on compile time
        4u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[53]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        16680u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed (NvM block ID: 54, persistent ID: 45679):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_VehicleSpeed, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[54]), // Block length calculated on compile time
        17u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[54]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        45679u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvMBlockDescriptor_ReadWritebyAddress (NvM block ID: 55, persistent ID: 39806):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_ReadWritebyAddress, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[55]), // Block length calculated on compile time
        4u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        0u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[55]), // RAM block data address calculated on compile time
        NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        39806u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BN_DID_D09A (NvM block ID: 56, persistent ID: 39665):
        FeeConf_FeeBlockConfiguration_NvM_BN_DID_D09A, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[56]), // Block length calculated on compile time
        2u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[56]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BN_D09A), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        39665u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BN_DID_F190 (NvM block ID: 57, persistent ID: 56189):
        FeeConf_FeeBlockConfiguration_NvM_BN_DID_F190, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[57]), // Block length calculated on compile time
        17u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[57]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BN_F190), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        56189u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_AngCorrectStored (NvM block ID: 58, persistent ID: 32):
        FeeConf_FeeBlockConfiguration_NvM_BR_AngCorrectStored, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[58]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[58]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_AngCorrectStored), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        32u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_AngEndCalData (NvM block ID: 59, persistent ID: 58101):
        FeeConf_FeeBlockConfiguration_NvM_BR_AngEndCalData, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[59]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[59]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_AngEndCalData), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        58101u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_AngValidEnd (NvM block ID: 60, persistent ID: 35799):
        FeeConf_FeeBlockConfiguration_NvM_BR_AngValidEnd, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[60]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[60]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_AngValidEnd), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        35799u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_BackupConfig (NvM block ID: 61, persistent ID: 55314):
        FeeConf_FeeBlockConfiguration_NvM_BR_BackupConfig, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[61]), // Block length calculated on compile time
        64u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[61]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_BackupConfig), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        55314u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_CCPVal (NvM block ID: 62, persistent ID: 8494):
        FeeConf_FeeBlockConfiguration_NvM_BR_CCPVal, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[62]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[62]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_CCPVal), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        8494u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_CommonCRCStored (NvM block ID: 63, persistent ID: 6815):
        FeeConf_FeeBlockConfiguration_NvM_BR_CommonCRCStored, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[63]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[63]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_CommonCRCStored), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        6815u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_CurrentOffset (NvM block ID: 64, persistent ID: 32657):
        FeeConf_FeeBlockConfiguration_NvM_BR_CurrentOffset, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[64]), // Block length calculated on compile time
        44u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[64]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_CurrentOffset), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        32657u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_FunConfig (NvM block ID: 65, persistent ID: 31280):
        FeeConf_FeeBlockConfiguration_NvM_BR_FunConfig, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[65]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[65]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_FunConfig), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        31280u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_InitAngle (NvM block ID: 66, persistent ID: 50040):
        FeeConf_FeeBlockConfiguration_NvM_BR_InitAngle, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[66]), // Block length calculated on compile time
        18u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[66]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_CurrentOffset), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        50040u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_Mileage (NvM block ID: 67, persistent ID: 54898):
        FeeConf_FeeBlockConfiguration_NvM_BR_Mileage, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[67]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[67]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_Mileage), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        54898u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_PenProf (NvM block ID: 68, persistent ID: 55531):
        FeeConf_FeeBlockConfiguration_NvM_BR_PenProf, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[68]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[68]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_PenProf), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        55531u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_ResetFlag (NvM block ID: 69, persistent ID: 4104):
        FeeConf_FeeBlockConfiguration_NvM_BR_ResetFlag, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[69]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[69]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_ResetFlag), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        4104u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_RotorOffset (NvM block ID: 70, persistent ID: 53959):
        FeeConf_FeeBlockConfiguration_NvM_BR_RotorOffset, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[70]), // Block length calculated on compile time
        34u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[70]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_RotorOffset), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        53959u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_SoftwareConfig (NvM block ID: 71, persistent ID: 56787):
        FeeConf_FeeBlockConfiguration_NvM_BR_SoftwareConfig, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[71]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[71]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_SoftwareConfig), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        56787u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_StrAngZero (NvM block ID: 72, persistent ID: 25370):
        FeeConf_FeeBlockConfiguration_NvM_BR_StrAngZero, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[72]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[72]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_StrAngZero), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        25370u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_TOCStudyTrq (NvM block ID: 73, persistent ID: 7577):
        FeeConf_FeeBlockConfiguration_NvM_BR_TOCStudyTrq, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[73]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[73]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_TOCStudyTrq), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        7577u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_TestMode (NvM block ID: 74, persistent ID: 19359):
        FeeConf_FeeBlockConfiguration_NvM_BR_TestMode, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[74]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[74]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_TestMode), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        19359u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_VIN (NvM block ID: 75, persistent ID: 64117):
        FeeConf_FeeBlockConfiguration_NvM_BR_VIN, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[75]), // Block length calculated on compile time
        17u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[75]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_VIN), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        64117u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_VehicleConfig (NvM block ID: 76, persistent ID: 6158):
        FeeConf_FeeBlockConfiguration_NvM_BR_VehicleConfig, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[76]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[76]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleConfig), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        6158u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_BR_VehicleName (NvM block ID: 77, persistent ID: 20903):
        FeeConf_FeeBlockConfiguration_NvM_BR_VehicleName, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[77]), // Block length calculated on compile time
        8u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        2u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[77]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BR_VehicleName), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_REDUNDANT, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        20903u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_NATIVE_IDS_1024 (NvM block ID: 78, persistent ID: 53203):
        FeeConf_FeeBlockConfiguration_NvM_NATIVE_IDS_1024, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[78]), // Block length calculated on compile time
        1024u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[78]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BlockNativeIDS_1024), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        53203u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_NativeBlock_2 (NvM block ID: 79, persistent ID: 41675):
        FeeConf_FeeBlockConfiguration_NvM_NativeBlock_2, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[79]), // Block length calculated on compile time
        1024u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[79]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_1), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        41675u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
    {
#if (defined(NVM_RB_BLOCK_VERSION) && (STD_ON == NVM_RB_BLOCK_VERSION))
        0u, // block specific version
#endif
        // Block descriptor of NVRAM block NvM_NativeBlock_3 (NvM block ID: 80, persistent ID: 45890):
        FeeConf_FeeBlockConfiguration_NvM_NativeBlock_3, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[80]), // Block length calculated on compile time
        1024u, // block length in bytes stored on the medium
        0u, // Device index (here: Fee)
        1u, // Number of NV blocks
        1u, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[80]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_2), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1u, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint32)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL,
        // Definition of job resource IDs used for different job resource clusters
        {
            // ID of the job resource used for MemIf jobs
            NvM_Prv_idJobResource_MemIf_0_e,
            // ID of the job resource used for CryptoStack jobs
            NvM_Prv_idJobResource_NrJobResources_e,    // crypto not used for this block
        },
#if (defined(NVM_CALC_CRC) && (NVM_CALC_CRC == STD_ON))
        NvM_Prv_Crc_Type_NoCrc_e, // CRC type used for this block
        0u, // Index of the RAM block CRC in the corresponding array with same CRC type
#endif
#if (NVM_CRYPTO_USED == STD_ON)
        45890u, // Persistent ID
        {
            /* MR12 DIR 1.1, 11.6, RULE 11.5 VIOLATION: Casting to byte pointer can always be done safely */
            (uint8 const*)NULL_PTR,                               // Pointer to associated data used for AEAD encryption
            {
                0u,                                               // Csm job ID to encrypt user data
                0u,                                               // Csm job ID to decrypt user data
                0u,                                               // Csm job ID to generate signature
                0u,                                               // Csm job ID to verify signature
                0u,                                               // Csm key ID to be used for encryption / authentication
            },
            {
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of encrypted user data
                0u,                                               // Length of the signature
                0u,                                               // Length of the signature
                0u,                                               // Length of the key initialization vector used for data encryption / authentication
            },
            0u,                                                   // Length of associated data used for data authentication
            0u,                                                   // Length of the tag stored for for data authentication
            0u,                                                   // Position of the key initialization vector within internal buffer
        },
#endif
    },
};

#if (defined(NVM_CFG_CRC_NR_RAM_BLOCKS) && (NVM_CFG_CRC_NR_RAM_BLOCKS > 0u))
NvM_BlockIdType const NvM_Prv_idBlockRamCrc_cauo[NVM_CFG_CRC_NR_RAM_BLOCKS] =
{
};
#endif

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3028]
// Runtime Calculation feature disabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_OFF)
// Used to calculate the NV block lengths on compile time
// This variable is mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
const uint16 NvM_Prv_BlockLengths_acu16[NVM_CFG_NR_BLOCKS] =
{
    // Block length of NVRAM block NvM_MultiBlock (NvM block ID: 0)
        1u,
    // Block length of NVRAM block NvM_ConfigId (NvM block ID: 1)
        2u,
    // Block length of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 2)
        4u,
    // Block length of NVRAM block NVM_ID_DEM_GENERIC_NV_DATA (NvM block ID: 3)
        DEM_SIZEOF_VAR(Dem_GenericNvData),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_0 (NvM block ID: 4)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_1 (NvM block ID: 5)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_10 (NvM block ID: 6)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_11 (NvM block ID: 7)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_12 (NvM block ID: 8)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_13 (NvM block ID: 9)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_14 (NvM block ID: 10)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_15 (NvM block ID: 11)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_16 (NvM block ID: 12)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_17 (NvM block ID: 13)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_18 (NvM block ID: 14)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_19 (NvM block ID: 15)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_2 (NvM block ID: 16)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_20 (NvM block ID: 17)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_21 (NvM block ID: 18)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_22 (NvM block ID: 19)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_23 (NvM block ID: 20)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_24 (NvM block ID: 21)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_25 (NvM block ID: 22)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_26 (NvM block ID: 23)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_27 (NvM block ID: 24)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_28 (NvM block ID: 25)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_29 (NvM block ID: 26)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_3 (NvM block ID: 27)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_30 (NvM block ID: 28)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_31 (NvM block ID: 29)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_32 (NvM block ID: 30)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_33 (NvM block ID: 31)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_34 (NvM block ID: 32)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_35 (NvM block ID: 33)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_36 (NvM block ID: 34)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_37 (NvM block ID: 35)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_38 (NvM block ID: 36)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_39 (NvM block ID: 37)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_4 (NvM block ID: 38)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_5 (NvM block ID: 39)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_6 (NvM block ID: 40)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_7 (NvM block ID: 41)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_8 (NvM block ID: 42)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVMEM_LOC_9 (NvM block ID: 43)
        DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType),
    // Block length of NVRAM block NVM_ID_EVT_STATUSBYTE (NvM block ID: 44)
        DEM_SIZEOF_VAR(Dem_AllEventsStatusByte),
    // Block length of NVRAM block NV_CrcBlock (NvM block ID: 45)
        8u,
    // Block length of NVRAM block NV_ExternalReprogrammingRequestFlagBlock (NvM block ID: 46)
        1u,
    // Block length of NVRAM block NV_PartNumberBlock (NvM block ID: 47)
        32u,
    // Block length of NVRAM block NV_ProgrammingAttemptCounterBlock (NvM block ID: 48)
        4u,
    // Block length of NVRAM block NV_ProgrammingCounterBlock (NvM block ID: 49)
        4u,
    // Block length of NVRAM block NV_ResetResponseFlagBlock (NvM block ID: 50)
        1u,
    // Block length of NVRAM block NV_ValidityFlagsBlock (NvM block ID: 51)
        1u,
    // Block length of NVRAM block NvMBlockDescriptor_DID_IOControl (NvM block ID: 52)
        17u,
    // Block length of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank (NvM block ID: 53)
        4u,
    // Block length of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed (NvM block ID: 54)
        17u,
    // Block length of NVRAM block NvMBlockDescriptor_ReadWritebyAddress (NvM block ID: 55)
        4u,
    // Block length of NVRAM block NvM_BN_DID_D09A (NvM block ID: 56)
        2u,
    // Block length of NVRAM block NvM_BN_DID_F190 (NvM block ID: 57)
        17u,
    // Block length of NVRAM block NvM_BR_AngCorrectStored (NvM block ID: 58)
        8u,
    // Block length of NVRAM block NvM_BR_AngEndCalData (NvM block ID: 59)
        8u,
    // Block length of NVRAM block NvM_BR_AngValidEnd (NvM block ID: 60)
        8u,
    // Block length of NVRAM block NvM_BR_BackupConfig (NvM block ID: 61)
        64u,
    // Block length of NVRAM block NvM_BR_CCPVal (NvM block ID: 62)
        8u,
    // Block length of NVRAM block NvM_BR_CommonCRCStored (NvM block ID: 63)
        8u,
    // Block length of NVRAM block NvM_BR_CurrentOffset (NvM block ID: 64)
        44u,
    // Block length of NVRAM block NvM_BR_FunConfig (NvM block ID: 65)
        8u,
    // Block length of NVRAM block NvM_BR_InitAngle (NvM block ID: 66)
        18u,
    // Block length of NVRAM block NvM_BR_Mileage (NvM block ID: 67)
        8u,
    // Block length of NVRAM block NvM_BR_PenProf (NvM block ID: 68)
        8u,
    // Block length of NVRAM block NvM_BR_ResetFlag (NvM block ID: 69)
        8u,
    // Block length of NVRAM block NvM_BR_RotorOffset (NvM block ID: 70)
        34u,
    // Block length of NVRAM block NvM_BR_SoftwareConfig (NvM block ID: 71)
        8u,
    // Block length of NVRAM block NvM_BR_StrAngZero (NvM block ID: 72)
        8u,
    // Block length of NVRAM block NvM_BR_TOCStudyTrq (NvM block ID: 73)
        8u,
    // Block length of NVRAM block NvM_BR_TestMode (NvM block ID: 74)
        8u,
    // Block length of NVRAM block NvM_BR_VIN (NvM block ID: 75)
        17u,
    // Block length of NVRAM block NvM_BR_VehicleConfig (NvM block ID: 76)
        8u,
    // Block length of NVRAM block NvM_BR_VehicleName (NvM block ID: 77)
        8u,
    // Block length of NVRAM block NvM_NATIVE_IDS_1024 (NvM block ID: 78)
        1024u,
    // Block length of NVRAM block NvM_NativeBlock_2 (NvM block ID: 79)
        1024u,
    // Block length of NVRAM block NvM_NativeBlock_3 (NvM block ID: 80)
        1024u,
};
// Used to calculate the RAM block data addresses on compile runtime
// This variable is mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
void * const NvM_Prv_RamBlockAdr_acpv[NVM_CFG_NR_BLOCKS] =
{
    // Permanent RAM address of NVRAM block NvM_MultiBlock (NvM block ID: 0)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NULL_PTR,
    // Permanent RAM address of NVRAM block NvM_ConfigId (NvM block ID: 1)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(NvM_Prv_idConfigStored_u16),
    // Permanent RAM address of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 2)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(EcuM_Rb_dataShutdownInfo_st),
    // Permanent RAM address of NVRAM block NVM_ID_DEM_GENERIC_NV_DATA (NvM block ID: 3)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_0 (NvM block ID: 4)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_1 (NvM block ID: 5)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_10 (NvM block ID: 6)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_11 (NvM block ID: 7)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_12 (NvM block ID: 8)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_13 (NvM block ID: 9)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_14 (NvM block ID: 10)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_15 (NvM block ID: 11)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_16 (NvM block ID: 12)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_17 (NvM block ID: 13)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_18 (NvM block ID: 14)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_19 (NvM block ID: 15)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_2 (NvM block ID: 16)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_20 (NvM block ID: 17)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_21 (NvM block ID: 18)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_22 (NvM block ID: 19)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_23 (NvM block ID: 20)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_24 (NvM block ID: 21)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_25 (NvM block ID: 22)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_26 (NvM block ID: 23)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_27 (NvM block ID: 24)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_28 (NvM block ID: 25)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_29 (NvM block ID: 26)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_3 (NvM block ID: 27)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_30 (NvM block ID: 28)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_31 (NvM block ID: 29)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_32 (NvM block ID: 30)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_33 (NvM block ID: 31)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_34 (NvM block ID: 32)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_35 (NvM block ID: 33)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_36 (NvM block ID: 34)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_37 (NvM block ID: 35)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_38 (NvM block ID: 36)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_39 (NvM block ID: 37)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_4 (NvM block ID: 38)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_5 (NvM block ID: 39)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_6 (NvM block ID: 40)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_7 (NvM block ID: 41)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_8 (NvM block ID: 42)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVMEM_LOC_9 (NvM block ID: 43)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NVM_ID_EVT_STATUSBYTE (NvM block ID: 44)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NV_CrcBlock (NvM block ID: 45)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Fbl_DataM_RamMirrorNV_CrcBlock),
    // Permanent RAM address of NVRAM block NV_ExternalReprogrammingRequestFlagBlock (NvM block ID: 46)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Fbl_DataM_RamMirrorNV_ReprogrammingRequestFlagBlock),
    // Permanent RAM address of NVRAM block NV_PartNumberBlock (NvM block ID: 47)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Fbl_DataM_RamMirrorNV_PartNumberBlock),
    // Permanent RAM address of NVRAM block NV_ProgrammingAttemptCounterBlock (NvM block ID: 48)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Fbl_DataM_RamMirrorNV_ProgrammingAttemptCounterBlock),
    // Permanent RAM address of NVRAM block NV_ProgrammingCounterBlock (NvM block ID: 49)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Fbl_DataM_RamMirrorNV_ProgrammingCounterBlock),
    // Permanent RAM address of NVRAM block NV_ResetResponseFlagBlock (NvM block ID: 50)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Fbl_DataM_RamMirrorNV_ResetResponseBlock),
    // Permanent RAM address of NVRAM block NV_ValidityFlagsBlock (NvM block ID: 51)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Fbl_DataM_RamMirrorNV_ValidityFlagsBlock),
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_DID_IOControl (NvM block ID: 52)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(RamBlock_DID_IOControl),
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank (NvM block ID: 53)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(RamBlock_DID_SystemFaultRank),
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed (NvM block ID: 54)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(RamBlock_DID_VehicleSpeed),
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_ReadWritebyAddress (NvM block ID: 55)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(RamBlock_DID_ReadWritebyAddress),
    // Permanent RAM address of NVRAM block NvM_BN_DID_D09A (NvM block ID: 56)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BN_DID_D09A),
    // Permanent RAM address of NVRAM block NvM_BN_DID_F190 (NvM block ID: 57)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BN_DID_F190),
    // Permanent RAM address of NVRAM block NvM_BR_AngCorrectStored (NvM block ID: 58)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngCorrectStored),
    // Permanent RAM address of NVRAM block NvM_BR_AngEndCalData (NvM block ID: 59)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngEndCalData),
    // Permanent RAM address of NVRAM block NvM_BR_AngValidEnd (NvM block ID: 60)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_AngValidEnd),
    // Permanent RAM address of NVRAM block NvM_BR_BackupConfig (NvM block ID: 61)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_BackupConfig),
    // Permanent RAM address of NVRAM block NvM_BR_CCPVal (NvM block ID: 62)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_CCPVal),
    // Permanent RAM address of NVRAM block NvM_BR_CommonCRCStored (NvM block ID: 63)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_CommonCRCStored),
    // Permanent RAM address of NVRAM block NvM_BR_CurrentOffset (NvM block ID: 64)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_CurrentOffset),
    // Permanent RAM address of NVRAM block NvM_BR_FunConfig (NvM block ID: 65)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_FunConfig),
    // Permanent RAM address of NVRAM block NvM_BR_InitAngle (NvM block ID: 66)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_InitAngle),
    // Permanent RAM address of NVRAM block NvM_BR_Mileage (NvM block ID: 67)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_Mileage),
    // Permanent RAM address of NVRAM block NvM_BR_PenProf (NvM block ID: 68)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_PenProf),
    // Permanent RAM address of NVRAM block NvM_BR_ResetFlag (NvM block ID: 69)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_ResetFlag),
    // Permanent RAM address of NVRAM block NvM_BR_RotorOffset (NvM block ID: 70)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_RotorOffset),
    // Permanent RAM address of NVRAM block NvM_BR_SoftwareConfig (NvM block ID: 71)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_SoftwareConfig),
    // Permanent RAM address of NVRAM block NvM_BR_StrAngZero (NvM block ID: 72)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_StrAngZero),
    // Permanent RAM address of NVRAM block NvM_BR_TOCStudyTrq (NvM block ID: 73)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_TOCStudyTrq),
    // Permanent RAM address of NVRAM block NvM_BR_TestMode (NvM block ID: 74)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_TestMode),
    // Permanent RAM address of NVRAM block NvM_BR_VIN (NvM block ID: 75)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_VIN),
    // Permanent RAM address of NVRAM block NvM_BR_VehicleConfig (NvM block ID: 76)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_VehicleConfig),
    // Permanent RAM address of NVRAM block NvM_BR_VehicleName (NvM block ID: 77)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BR_VehicleName),
    // Permanent RAM address of NVRAM block NvM_NATIVE_IDS_1024 (NvM block ID: 78)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_IDS_1024),
    // Permanent RAM address of NVRAM block NvM_NativeBlock_2 (NvM block ID: 79)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_1),
    // Permanent RAM address of NVRAM block NvM_NativeBlock_3 (NvM block ID: 80)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2),
};
#endif

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

// TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3028]
// Runtime Calculation feature enabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
# define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"
// Used to calculate the NV block lengths and RAM block data addresses on runtime
// These variables are mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
uint16 NvM_Prv_BlockLengths_au16[NVM_CFG_NR_BLOCKS];
void *NvM_Prv_RamBlockAdr_apv[NVM_CFG_NR_BLOCKS];
# define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"
#endif

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
# define NVM_START_SEC_CODE
# include "NvM_MemMap.h"
/********************************************************************************************
 * Initialization of NV block length and RAM block data address (permanent RAM address)     *
 *                                                                                          *
 * In this case NvMRbRuntimeRamBlockConfiguration is enabled                                *
 * + NV block length is defined either by NvMRbNvBlockLengthString or NvMNvBlockLength      *
 * + RAM block data address is still defined by NvMRamBlockDataAddress but now              *
 *   NvMRamBlockDataAddress can also contain C expressions                                  *
 *                                                                                          *
 * Furthermore if explicit sync feature is enabled the explicit sync buffer is defined here *
 * by setting the start address and calculating the buffer size                             *
 * Start address and end address is defined by user in common options with the parameters   *
 * + NvMRbRuntimeRamBufferAddressStart                                                      *
 * + NvMRbRuntimeRamBufferAddressEnd                                                        *
 *                                                                                          *
 * ******************************************************************************************
*/
/* HIS METRIC STMT VIOLATION IN NvM_Prv_InitRamBlockProperties: Due to the configuration this generated function may be empty */
void NvM_Prv_InitRamBlockProperties(void)
{
    // TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3028]
    // Runtime Calculation feature enabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
# if (NVM_PRV_EXPLICIT_SYNC == STD_ON)
    // Calculate explicit synchronization RAM buffer size
    /* MR12 RULE 11.4 VIOLATION: Cast to an integral type is necessary to calculate the size of the object*/
    uint32 RuntimeRamMirrorSize_u32 = (uint32)(0) - (uint32)(0);

    // TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3029] Calculate explicit synchronization RAM buffer
    // TRACE[BSW_SWCS_AR_NVRAMManager_Ext-3030] Calculate explicit synchronization RAM buffer
    // Set explicit synchronization RAM buffer start address and its size
    NvM_Prv_InitRuntimeRamMirror((uint8 *)(0),
                                 RuntimeRamMirrorSize_u32);
# endif

#endif
}
# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h"
