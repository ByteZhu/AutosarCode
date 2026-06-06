/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */
// #ifndef NOT_READY_FOR_TESTING_OR_DEPLOYMENT
// #error The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
// #else
// #warning The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
// #endif /* NOT_READY_FOR_TESTING_OR_DEPLOYMENT */


#define MEMMAP_ERROR
/* MR12 RULE 4.10, 20.5 VIOLATION:  4.10: Memmap file must be included multiple times,  20.5: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
#if defined SECOC_START_SEC_CODE
/* BSWEXT-355 */
/* removed GHS-specific pragma section text=default */
  #undef SECOC_START_SEC_CODE
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_CODE
/* BSWEXT-355 */
/* removed GHS-specific pragma section text=default */
  #undef SECOC_STOP_SEC_CODE
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_CONST_16
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_START_SEC_CONST_16
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_CONST_16
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_STOP_SEC_CONST_16
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_CONST_32
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_START_SEC_CONST_32
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_CONST_32
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_STOP_SEC_CONST_32
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_CONST_8
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_START_SEC_CONST_8
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_CONST_8
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_STOP_SEC_CONST_8
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_CONST_UNSPECIFIED
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_CONST_UNSPECIFIED
/* BSWEXT-355 */
/* removed GHS-specific pragma section rodata=default */
  #undef SECOC_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_CLEARED_16
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_START_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_CLEARED_16
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_STOP_SEC_VAR_CLEARED_16
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_CLEARED_32
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_START_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_CLEARED_32
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_STOP_SEC_VAR_CLEARED_32
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_CLEARED_8
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_START_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_CLEARED_8
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_STOP_SEC_VAR_CLEARED_8
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_CLEARED_UNSPECIFIED
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/* BSWEXT-355 */
/* removed GHS-specific pragma section bss=default */
  #undef SECOC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_HSM_SHARED_CLEARED_UNSPECIFIED

  #undef SECOC_START_SEC_VAR_HSM_SHARED_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_HSM_SHARED_CLEARED_UNSPECIFIED

  #undef SECOC_STOP_SEC_VAR_HSM_SHARED_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_HSM_SHARED_INIT_UNSPECIFIED

  #undef SECOC_START_SEC_VAR_HSM_SHARED_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_HSM_SHARED_INIT_UNSPECIFIED

  #undef SECOC_STOP_SEC_VAR_HSM_SHARED_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED

  #undef SECOC_START_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED

  #undef SECOC_STOP_SEC_VAR_HSM_SHARED_READONLY_CLEARED_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_HSM_SHARED_READONLY_INIT_UNSPECIFIED

  #undef SECOC_START_SEC_VAR_HSM_SHARED_READONLY_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_HSM_SHARED_READONLY_INIT_UNSPECIFIED

  #undef SECOC_STOP_SEC_VAR_HSM_SHARED_READONLY_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_INIT_16
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_START_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_INIT_16
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_STOP_SEC_VAR_INIT_16
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_INIT_32
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_START_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_INIT_32
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_STOP_SEC_VAR_INIT_32
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_INIT_8
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_START_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_INIT_8
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_STOP_SEC_VAR_INIT_8
  #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_INIT_UNSPECIFIED
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
/* BSWEXT-355 */
/* removed GHS-specific pragma section data=default */
  #undef SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#elif defined SecOC_START_SEC_CODE
/* BSWEXT-355 */
/* removed GHS-specific pragma section text=default */
  #undef SecOC_START_SEC_CODE
  #undef MEMMAP_ERROR
#elif defined SecOC_STOP_SEC_CODE
/* BSWEXT-355 */
/* removed GHS-specific pragma section text=default */
  #undef SecOC_STOP_SEC_CODE
  #undef MEMMAP_ERROR
/* BSWEXT-273 */
// Defines for CSM_CRYPTO third party crypto integrations
#elif defined SECOC_START_SEC_VAR_CSM_CRYPTO_SHARED_CLEARED_UNSPECIFIED
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef SECOC_START_SEC_VAR_CSM_CRYPTO_SHARED_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_CSM_CRYPTO_SHARED_CLEARED_UNSPECIFIED
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef SECOC_STOP_SEC_VAR_CSM_CRYPTO_SHARED_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined SECOC_START_SEC_VAR_CSM_CRYPTO_SHARED_INIT_UNSPECIFIED
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef SECOC_START_SEC_VAR_CSM_CRYPTO_SHARED_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#elif defined SECOC_STOP_SEC_VAR_CSM_CRYPTO_SHARED_INIT_UNSPECIFIED
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef SECOC_STOP_SEC_VAR_CSM_CRYPTO_SHARED_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
/* END BSWEXT-273 */
#endif
#ifdef MEMMAP_ERROR
#error "SecOC_MemMap.h, wrong pragma command"
#endif
