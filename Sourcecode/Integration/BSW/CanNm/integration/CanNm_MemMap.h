/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */



/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

/* BSWEXT-111 */
#include "ComStack_Types.h"

/* Included for CANNM_CONFIGURATION_VARIANT,CANNM_VARIANT_PRE_COMPILE macro definition */
#include "CanNm_Cfg.h"

/* <component>_MemMap.h for AUTOSAR Memory Mapping */
/* MR12 DIR 4.10 VIOLATION: MemMap header concept - no protection against repeated inclusion intended */
#define MEMMAP_ERROR


#if(CANNM_CONFIGURATION_VARIANT == CANNM_VARIANT_PRE_COMPILE)
/* If Module is pre-compile , then map post-build memmap to pre-compile memmap*/
#ifdef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define CANNM_START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define CANNM_STOP_SEC_CONST_UNSPECIFIED
#endif
#ifdef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
    #define CANNM_START_SEC_CONST_8
#endif
#ifdef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #define CANNM_STOP_SEC_CONST_8
#endif
#endif /* #if(COMM_CONFIGURATION_VARIANT == COMM_VARIANT_PRECOMPILE)*/

#if defined CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* UNSPECIFIED */
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANNM_START_SEC_CONST_UNSPECIFIED
    /* Unspecified size */
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined CANNM_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_CONST_8
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR




#elif defined CANNM_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR

#elif defined CANNM_START_SEC_CODE
   #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
   #undef CANNM_START_SEC_CODE
   #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CODE
   #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
   #undef CANNM_STOP_SEC_CODE
   #undef MEMMAP_ERROR

/* PBL Constants */

#elif defined CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
     /*  8 bit */
    #define BSW_START_SEC_CONFIG_DATA_POSTBUILD_8
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_8
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #define BSW_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_8
    #undef MEMMAP_ERROR



#elif defined CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    /* Unspecified size */
    #define BSW_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #define BSW_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef CANNM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
    #undef MEMMAP_ERROR



#endif

#if defined MEMMAP_ERROR
   #error "CanNm_MemMap.h, wrong #pragma command"
#endif


