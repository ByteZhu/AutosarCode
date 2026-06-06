/*
 * This is Os_MemMap.h, auto-generated for:
 *   Project: TC397
 *   Target:  TC397
 *   Variant: ETAS Entry Platform
 *   Version: 3.0.3
 *   It should be either copied into MemMap.h by the integrator OR #included into it.
 */
/* Generator info: generate_always */
/* This file is a sample version of Os_MemMap.h that can be used
 * as a starting template.
 * [$UKS 652] [$UKS 653] [$UKS 655] [$UKS 656] [$UKS 657]
 */

#if defined (NOT_DEFINED)

/* OS Uninitialized RAM: trace data */
#elif defined (OS_START_SEC_VAR_TRACE)
  #undef      OS_START_SEC_VAR_TRACE
  #define OS_SHARED_START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_TRACE)
  #undef      OS_STOP_SEC_VAR_TRACE
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_UNSPECIFIED

/* OS Uninitialized RAM: boolean */
#elif defined (OS_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      OS_START_SEC_VAR_NO_INIT_BOOLEAN
  #define OS_SHARED_START_SEC_VAR_CLEARED_8
#elif defined (OS_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_8

/* OS Uninitialized RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_NO_INIT_8)
  #undef      OS_START_SEC_VAR_NO_INIT_8
  #define OS_SHARED_START_SEC_VAR_CLEARED_8
#elif defined (OS_STOP_SEC_VAR_NO_INIT_8)
  #undef      OS_STOP_SEC_VAR_NO_INIT_8
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_8

/* OS Uninitialized RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_NO_INIT_16)
  #undef      OS_START_SEC_VAR_NO_INIT_16
  #define OS_SHARED_START_SEC_VAR_CLEARED_16
#elif defined (OS_STOP_SEC_VAR_NO_INIT_16)
  #undef      OS_STOP_SEC_VAR_NO_INIT_16
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_16

/* OS Uninitialized RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_NO_INIT_32)
  #undef      OS_START_SEC_VAR_NO_INIT_32
  #define OS_SHARED_START_SEC_VAR_CLEARED_32
#elif defined (OS_STOP_SEC_VAR_NO_INIT_32)
  #undef      OS_STOP_SEC_VAR_NO_INIT_32
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_32

/* OS Uninitialized RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define OS_SHARED_START_SEC_VAR_CLEARED_UNSPECIFIED
  
#elif defined (OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  

/* OS reset cleared RAM: boolean */
#elif defined (OS_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      OS_START_SEC_VAR_CLEARED_BOOLEAN
  #define OS_SHARED_START_SEC_VAR_CLEARED_8
#elif defined (OS_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_CLEARED_BOOLEAN
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_8

/* OS reset cleared RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_CLEARED_8)
  #undef      OS_START_SEC_VAR_CLEARED_8
  #define OS_SHARED_START_SEC_VAR_CLEARED_8
#elif defined (OS_STOP_SEC_VAR_CLEARED_8)
  #undef      OS_STOP_SEC_VAR_CLEARED_8
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_8

/* OS reset cleared RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_CLEARED_16)
  #undef      OS_START_SEC_VAR_CLEARED_16
  #define OS_SHARED_START_SEC_VAR_CLEARED_16
#elif defined (OS_STOP_SEC_VAR_CLEARED_16)
  #undef      OS_STOP_SEC_VAR_CLEARED_16
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_16

/* OS reset cleared RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_CLEARED_32)
  #undef      OS_START_SEC_VAR_CLEARED_32
  #define OS_SHARED_START_SEC_VAR_CLEARED_32
#elif defined (OS_STOP_SEC_VAR_CLEARED_32)
  #undef      OS_STOP_SEC_VAR_CLEARED_32
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_32

/* OS reset cleared RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_CLEARED_UNSPECIFIED
  #define OS_SHARED_START_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined (OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_UNSPECIFIED

/* OS reset initialized RAM: boolean */
#elif defined (OS_START_SEC_VAR_INIT_BOOLEAN)
  #undef      OS_START_SEC_VAR_INIT_BOOLEAN
  #define OS_SHARED_START_SEC_VAR_INIT_8
#elif defined (OS_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_INIT_BOOLEAN
  #define OS_SHARED_STOP_SEC_VAR_INIT_8

/* OS reset initialized RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_INIT_8)
  #undef      OS_START_SEC_VAR_INIT_8
  #define OS_SHARED_START_SEC_VAR_INIT_8
#elif defined (OS_STOP_SEC_VAR_INIT_8)
  #undef      OS_STOP_SEC_VAR_INIT_8
  #define OS_SHARED_STOP_SEC_VAR_INIT_8

/* OS reset initialized RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_INIT_16)
  #undef      OS_START_SEC_VAR_INIT_16
  #define OS_SHARED_START_SEC_VAR_INIT_16
#elif defined (OS_STOP_SEC_VAR_INIT_16)
  #undef      OS_STOP_SEC_VAR_INIT_16
  #define OS_SHARED_STOP_SEC_VAR_INIT_16

/* OS reset initialized RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_INIT_32)
  #undef      OS_START_SEC_VAR_INIT_32
  #define OS_SHARED_START_SEC_VAR_INIT_32
#elif defined (OS_STOP_SEC_VAR_INIT_32)
  #undef      OS_STOP_SEC_VAR_INIT_32
  #define OS_SHARED_STOP_SEC_VAR_INIT_32

/* OS reset initialized RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_INIT_UNSPECIFIED
  #define OS_SHARED_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define OS_SHARED_STOP_SEC_VAR_INIT_UNSPECIFIED

/* OS Power-on cleared RAM: boolean */
#elif defined (OS_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef      OS_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #define OS_SHARED_START_SEC_VAR_CLEARED_8
#elif defined (OS_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_8

/* OS Power-on cleared RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef      OS_START_SEC_VAR_POWER_ON_CLEARED_8
  #define OS_SHARED_START_SEC_VAR_CLEARED_8
#elif defined (OS_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef      OS_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_8

/* OS Power-on cleared RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef      OS_START_SEC_VAR_POWER_ON_CLEARED_16
  #define OS_SHARED_START_SEC_VAR_CLEARED_16
#elif defined (OS_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef      OS_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_16

/* OS Power-on cleared RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_CLEARED_32)
  #undef      OS_START_SEC_VAR_POWER_ON_CLEARED_32
  #define OS_SHARED_START_SEC_VAR_CLEARED_32
#elif defined (OS_STOP_SEC_VAR_POWER_ON_CLEARED_32)
  #undef      OS_STOP_SEC_VAR_POWER_ON_CLEARED_32
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_16

/* OS Power-on cleared RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #define OS_SHARED_START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #define OS_SHARED_STOP_SEC_VAR_CLEARED_UNSPECIFIED

/* OS Power-on initialized RAM: boolean */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #define OS_SHARED_START_SEC_VAR_INIT_8
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #define OS_SHARED_STOP_SEC_VAR_INIT_8

/* OS Power-on initialized RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_8)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_8
  #define OS_SHARED_START_SEC_VAR_INIT_8
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_8)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_8
  #define OS_SHARED_STOP_SEC_VAR_INIT_8

/* OS Power-on initialized RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_16)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_16
  #define OS_SHARED_START_SEC_VAR_INIT_16
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_16)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_16
  #define OS_SHARED_STOP_SEC_VAR_INIT_16

/* OS Power-on initialized RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_32)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_32
  #define OS_SHARED_START_SEC_VAR_INIT_32
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_32)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_32
  #define OS_SHARED_STOP_SEC_VAR_INIT_32

/* OS Power-on initialized RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #define OS_SHARED_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #define OS_SHARED_STOP_SEC_VAR_INIT_UNSPECIFIED

/* OS Initialized RAM: boolean */
#elif defined (OS_START_SEC_VAR_BOOLEAN)
  #undef      OS_START_SEC_VAR_BOOLEAN
  #define OS_SHARED_START_SEC_VAR_BOOLEAN
#elif defined (OS_STOP_SEC_VAR_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_BOOLEAN
  #define OS_SHARED_STOP_SEC_VAR_BOOLEAN

/* OS Initialized RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_8)
  #undef      OS_START_SEC_VAR_8
  #define OS_SHARED_START_SEC_VAR_8
#elif defined (OS_STOP_SEC_VAR_8)
  #undef      OS_STOP_SEC_VAR_8
  #define OS_SHARED_STOP_SEC_VAR_8

/* OS Initialized RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_16)
  #undef      OS_START_SEC_VAR_16
  #define OS_SHARED_START_SEC_VAR_16
#elif defined (OS_STOP_SEC_VAR_16)
  #undef      OS_STOP_SEC_VAR_16
  #define OS_SHARED_STOP_SEC_VAR_16

/* OS Initialized RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_32)
  #undef      OS_START_SEC_VAR_32
  #define OS_SHARED_START_SEC_VAR_32
#elif defined (OS_STOP_SEC_VAR_32)
  #undef      OS_STOP_SEC_VAR_32
  #define OS_SHARED_STOP_SEC_VAR_32

/* OS Initialized RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_UNSPECIFIED
  #define OS_SHARED_START_SEC_VAR_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_UNSPECIFIED
  #define OS_SHARED_STOP_SEC_VAR_UNSPECIFIED

/* OS Initialized fast RAM: boolean */
#elif defined (OS_START_SEC_VAR_FAST_BOOLEAN)
  #undef      OS_START_SEC_VAR_FAST_BOOLEAN
  #define OS_SHARED_START_SEC_VAR_FAST_BOOLEAN
#elif defined (OS_STOP_SEC_VAR_FAST_BOOLEAN)
  #undef      OS_STOP_SEC_VAR_FAST_BOOLEAN
  #define OS_SHARED_STOP_SEC_VAR_FAST_BOOLEAN

/* OS Initialized fast RAM: 8 bit values */
#elif defined (OS_START_SEC_VAR_FAST_8)
  #undef      OS_START_SEC_VAR_FAST_8
  #define OS_SHARED_START_SEC_VAR_FAST_8
#elif defined (OS_STOP_SEC_VAR_FAST_8)
  #undef      OS_STOP_SEC_VAR_FAST_8
  #define OS_SHARED_STOP_SEC_VAR_FAST_8

/* OS Initialized fast RAM: 16 bit values */
#elif defined (OS_START_SEC_VAR_FAST_16)
  #undef      OS_START_SEC_VAR_FAST_16
  #define OS_SHARED_START_SEC_VAR_FAST_16
#elif defined (OS_STOP_SEC_VAR_FAST_16)
  #undef      OS_STOP_SEC_VAR_FAST_16
  #define OS_SHARED_STOP_SEC_VAR_FAST_16

/* OS Initialized fast RAM: 32 bit values */
#elif defined (OS_START_SEC_VAR_FAST_32)
  #undef      OS_START_SEC_VAR_FAST_32
  #define OS_SHARED_START_SEC_VAR_FAST_32
#elif defined (OS_STOP_SEC_VAR_FAST_32)
  #undef      OS_STOP_SEC_VAR_FAST_32
  #define OS_SHARED_STOP_SEC_VAR_FAST_32

/* OS Initialized fast RAM: unspecified size */
#elif defined (OS_START_SEC_VAR_FAST_UNSPECIFIED)
  #undef      OS_START_SEC_VAR_FAST_UNSPECIFIED
  #define OS_SHARED_START_SEC_VAR_FAST_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_FAST_UNSPECIFIED)
  #undef      OS_STOP_SEC_VAR_FAST_UNSPECIFIED
  #define OS_SHARED_STOP_SEC_VAR_FAST_UNSPECIFIED
/* OS Const (ROM): boolean */
#elif defined (OS_START_SEC_CONST_BOOLEAN)
  #undef      OS_START_SEC_CONST_BOOLEAN
  #define SHARED_START_SEC_CONST_8
#elif defined (OS_STOP_SEC_CONST_BOOLEAN)
  #undef      OS_STOP_SEC_CONST_BOOLEAN
  #define SHARED_STOP_SEC_CONST_8

/* OS Const (ROM): 8 bit values */
#elif defined (OS_START_SEC_CONST_8)
  #undef      OS_START_SEC_CONST_8
  #define SHARED_START_SEC_CONST_8
#elif defined (OS_STOP_SEC_CONST_8)
  #undef      OS_STOP_SEC_CONST_8
  #define SHARED_STOP_SEC_CONST_8

/* OS Const (ROM): 16 bit values */
#elif defined (OS_START_SEC_CONST_16)
  #undef      OS_START_SEC_CONST_16
  #define SHARED_START_SEC_CONST_16
#elif defined (OS_STOP_SEC_CONST_16)
  #undef      OS_STOP_SEC_CONST_16
  #define SHARED_STOP_SEC_CONST_16

/* OS Const (ROM): 32 bit values */
#elif defined (OS_START_SEC_CONST_32)
  #undef      OS_START_SEC_CONST_32
  #define SHARED_START_SEC_CONST_32
#elif defined (OS_STOP_SEC_CONST_32)
  #undef      OS_STOP_SEC_CONST_32
  #define SHARED_STOP_SEC_CONST_32

/* OS Const (ROM): Often accessed */
#elif defined (OS_START_SEC_CONST_FAST_UNSPECIFIED)
  #undef      OS_START_SEC_CONST_FAST_UNSPECIFIED
  #define SHARED_START_SEC_CONST_UNSPECIFIED
#elif defined (OS_STOP_SEC_CONST_FAST_UNSPECIFIED)
  #undef      OS_STOP_SEC_CONST_FAST_UNSPECIFIED
  #define SHARED_STOP_SEC_CONST_UNSPECIFIED
/* OS Const (ROM): unspecified size */
#elif defined (OS_START_SEC_CONST_UNSPECIFIED)
  #undef      OS_START_SEC_CONST_UNSPECIFIED
  #define SHARED_START_SEC_CONST_UNSPECIFIED
#elif defined (OS_STOP_SEC_CONST_UNSPECIFIED)
  #undef      OS_STOP_SEC_CONST_UNSPECIFIED
  #define SHARED_STOP_SEC_CONST_UNSPECIFIED

/* OS Code */
#elif defined (OS_START_SEC_CODE)
  #undef      OS_START_SEC_CODE
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE)
  #undef      OS_STOP_SEC_CODE
  #define SHARED_STOP_SEC_CODE

/* OS Fast Code */
#elif defined (OS_START_SEC_CODE_FAST)
  #undef      OS_START_SEC_CODE_FAST
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_FAST)
  #undef      OS_STOP_SEC_CODE_FAST
  #define SHARED_STOP_SEC_CODE

/* OS Slow Code */
#elif defined (OS_START_SEC_CODE_SLOW)
  #undef      OS_START_SEC_CODE_SLOW
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_SLOW)
  #undef      OS_STOP_SEC_CODE_SLOW
  #define SHARED_STOP_SEC_CODE

/* OS Library Code */
#elif defined (OS_START_SEC_CODE_LIB)
  #undef      OS_START_SEC_CODE_LIB
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_LIB)
  #undef      OS_STOP_SEC_CODE_LIB
  #define SHARED_STOP_SEC_CODE

/* OS Interrupt vectors */
#elif defined (OS_START_SEC_VECTORS)
  #undef      OS_START_SEC_VECTORS
  #define SHARED_START_SEC_VECTORS
#elif defined (OS_STOP_SEC_VECTORS)
  #undef      OS_STOP_SEC_VECTORS
  #define SHARED_STOP_SEC_VECTORS

/* (Compatability) Callouts from the OS. */
#elif defined (OS_START_SEC_APPL_CODE)
  #undef      OS_START_SEC_APPL_CODE
  #define SHARED_START_SEC_APPL_CODE
#elif defined (OS_STOP_SEC_APPL_CODE)
  #undef      OS_STOP_SEC_APPL_CODE
  #define SHARED_STOP_SEC_APPL_CODE
/* Callouts from the OS. */
#elif defined (OS_START_SEC_CALLOUT_CODE)
  #undef      OS_START_SEC_CALLOUT_CODE
  #define SHARED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CALLOUT_CODE)
  #undef      OS_STOP_SEC_CALLOUT_CODE
  #define SHARED_STOP_SEC_CODE

/* OS Core 0 Code */
#elif defined (OS_START_SEC_CODE_LIB_CORE0)
  #undef      OS_START_SEC_CODE_LIB_CORE0
  #define DEFAULT_START_SEC_CODE_LIB
#elif defined (OS_STOP_SEC_CODE_LIB_CORE0)
  #undef      OS_STOP_SEC_CODE_LIB_CORE0
  #define DEFAULT_STOP_SEC_CODE_LIB

/* OS Core 1 Code */
#elif defined (OS_START_SEC_CODE_LIB_CORE1)
  #undef      OS_START_SEC_CODE_LIB_CORE1
  #define DEFAULT_START_SEC_CODE_LIB
#elif defined (OS_STOP_SEC_CODE_LIB_CORE1)
  #undef      OS_STOP_SEC_CODE_LIB_CORE1
  #define DEFAULT_STOP_SEC_CODE_LIB

/* OS Core2 Code */
#elif defined (OS_START_SEC_CODE_LIB_CORE2)
  #undef      OS_START_SEC_CODE_LIB_CORE2
  #define DEFAULT_START_SEC_CODE_LIB
#elif defined (OS_STOP_SEC_CODE_LIB_CORE2)
  #undef      OS_STOP_SEC_CODE_LIB_CORE2
  #define DEFAULT_STOP_SEC_CODE_LIB
  
  /* Callouts */
#elif defined (OS_START_SEC_CALLOUT_CODE)
  #undef      OS_START_SEC_CALLOUT_CODE
#elif defined (OS_STOP_SEC_CALLOUT_CODE)
  #undef      OS_STOP_SEC_CALLOUT_CODE
  
  
/* OS code called by core 0 trusted Os-Application*/
#elif defined (OS_START_SEC_CODE_CORE0)
  #undef      OS_START_SEC_CODE_CORE0
  #define CPU0_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_CORE0)
  #undef      OS_STOP_SEC_CODE_CORE0
  #define CPU0_STOP_SEC_CODE

/* OS code called by core 0 untrusted Os-Application*/
#elif defined (OS_START_SEC_CODE_CORE0_UNTRUSTED)
  #undef      OS_START_SEC_CODE_CORE0_UNTRUSTED
  #define CPU0_UNTRUSTED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_CORE0_UNTRUSTED)
  #undef      OS_STOP_SEC_CODE_CORE0_UNTRUSTED
  #define CPU0_UNTRUSTED_STOP_SEC_CODE

/* OS code called by core 1 trusted Os-Application*/
#elif defined (OS_START_SEC_CODE_CORE1)
  #undef      OS_START_SEC_CODE_CORE1
  #define CPU1_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_CORE1)
  #undef      OS_STOP_SEC_CODE_CORE1
  #define CPU1_STOP_SEC_CODE

/* OS code called by core 1 untrusted Os-Application*/
#elif defined (OS_START_SEC_CODE_CORE1_UNTRUSTED)
  #undef      OS_START_SEC_CODE_CORE1_UNTRUSTED
  #define CPU1_UNTRUSTED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_CORE1_UNTRUSTED)
  #undef      OS_STOP_SEC_CODE_CORE1_UNTRUSTED
  #define CPU1_UNTRUSTED_STOP_SEC_CODE

/* OS code called by core 2 trusted Os-Application*/
#elif defined (OS_START_SEC_CODE_CORE2)
  #undef      OS_START_SEC_CODE_CORE2
  #define CPU2_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_CORE2)
  #undef      OS_STOP_SEC_CODE_CORE2
  #define CPU2_STOP_SEC_CODE

/* OS code called by core 2 untrusted Os-Application*/
#elif defined (OS_START_SEC_CODE_CORE2_UNTRUSTED)
  #undef      OS_START_SEC_CODE_CORE2_UNTRUSTED
  #define CPU2_UNTRUSTED_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_CORE2_UNTRUSTED)
  #undef      OS_STOP_SEC_CODE_CORE2_UNTRUSTED
  #define CPU2_UNTRUSTED_STOP_SEC_CODE

/* OS code called by core 3 */
#elif defined (OS_START_SEC_CODE_CORE3)
  #undef      OS_START_SEC_CODE_CORE3
  #define CPU3_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE_CORE3)
  #undef      OS_STOP_SEC_CODE_CORE3
  #define CPU3_STOP_SEC_CODE

#elif defined (OS_START_SEC_CONST_CORE0_LOCAL)
  #undef      OS_START_SEC_CONST_CORE0_LOCAL
  #define SHARED_START_SEC_CONST_8
#elif defined (OS_STOP_SEC_CONST_CORE0_LOCAL)
  #undef      OS_STOP_SEC_CONST_CORE0_LOCAL
  #define SHARED_STOP_SEC_CONST_8

#elif defined (OS_START_SEC_CONST_CORE1_LOCAL)
  #undef      OS_START_SEC_CONST_CORE1_LOCAL
  #define SHARED_START_SEC_CONST_8
#elif defined (OS_STOP_SEC_CONST_CORE1_LOCAL)
  #undef      OS_STOP_SEC_CONST_CORE1_LOCAL
  #define SHARED_STOP_SEC_CONST_8
  
  #elif defined (OS_START_SEC_CONST_CORE2_LOCAL)
  #undef      OS_START_SEC_CONST_CORE2_LOCAL
  #define SHARED_START_SEC_CONST_8
#elif defined (OS_STOP_SEC_CONST_CORE2_LOCAL)
  #undef      OS_STOP_SEC_CONST_CORE2_LOCAL
  #define SHARED_STOP_SEC_CONST_8

#elif defined (OS_START_SEC_CODE_CORE0_LOCAL)
  #undef      OS_START_SEC_CODE_CORE0_LOCAL
  #define SHARED_START_SEC_CODE_8
#elif defined (OS_STOP_SEC_CODE_CORE0_LOCAL)
  #undef      OS_STOP_SEC_CODE_CORE0_LOCAL
  #define SHARED_STOP_SEC_CODE_8

#elif defined (OS_START_SEC_CODE_CORE1_LOCAL)
  #undef      OS_START_SEC_CODE_CORE1_LOCAL
  #define SHARED_START_SEC_CODE_8
#elif defined (OS_STOP_SEC_CODE_CORE1_LOCAL)
  #undef      OS_STOP_SEC_CODE_CORE1_LOCAL
  #define SHARED_STOP_SEC_CODE_8
  
  #elif defined (OS_START_SEC_CODE_CORE2_LOCAL)
  #undef      OS_START_SEC_CODE_CORE2_LOCAL
  #define SHARED_START_SEC_CODE_8
#elif defined (OS_STOP_SEC_CODE_CORE2_LOCAL)
  #undef      OS_STOP_SEC_CODE_CORE2_LOCAL
  #define SHARED_STOP_SEC_CODE_8
#else
  #error "Os_MemMap.h, the section is undefined"

#endif

#include "MemMap.h"
