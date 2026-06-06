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


/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/

/* MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 2 */

/*
**********************************************************************************************************************
The following section checks which of the preprocessor constants are defined for
the memory layout. Each .c file will do the following for each function
definition:

1. define the CRYIF_START_SEC_<type>
2. include this file
3. define the function itself
4. define CRYIF_STOP_SEC_<type> after the function,
5. include this file again.

There are two options for layout definitions in this file:

1. The standard Memmap concept using a central definition in another file.
   Projects that do not use the RTA-BSW SW, In the case of a project using the
   RTA-BSW SW, the BSW memmap header file will be available e.g.

        #if defined CRYIF_START_SEC_<section name>
            #define  BSW_START_SEC_<section name>
            #include "Bsw_MemMap.h"
            #undef CRYIF_START_SEC_<section name>

2. Alternatively, the definition can be made directly in the CryIf module with a #pragma e.g.

        #elif defined (CRYIF_START_SEC_<section name>)
           #undef      CRYIF_START_SEC_<section name>
           #pragma section ".text.bsw" ax

There are many different section names possible. Only those currently used in the
CryIf module are defined below.
**********************************************************************************************************************
*/

/* MR12 RULE 4.10 VIOLATION: MemMap header concept - no protection against multiple inclusion intended */
/* Code */
#if defined CRYIF_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_CODE
#elif defined CRYIF_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_CODE

/* Code: Added again for older RTE */
#elif defined CryIf_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CryIf_START_SEC_CODE
#elif defined CryIf_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CryIf_STOP_SEC_CODE

/* Const (ROM): 8 bits */
#elif defined CRYIF_START_SEC_CONST_8
    #define BSW_START_SEC_CONST_8
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_CONST_8
#elif defined CRYIF_STOP_SEC_CONST_8
    #define BSW_STOP_SEC_CONST_8
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_CONST_8

/* Const (ROM): 16 bits */
#elif defined CRYIF_START_SEC_CONST_16
    #define BSW_START_SEC_CONST_16
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_CONST_16
#elif defined CRYIF_STOP_SEC_CONST_16
    #define BSW_STOP_SEC_CONST_16
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_CONST_16

/* Const (ROM): 32 bits */
#elif defined CRYIF_START_SEC_CONST_32
    #define BSW_START_SEC_CONST_32
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_CONST_32
#elif defined CRYIF_STOP_SEC_CONST_32
    #define BSW_STOP_SEC_CONST_32
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_CONST_32

/* Const (ROM): unspecified size */
#elif defined CRYIF_START_SEC_CONST_UNSPECIFIED
    #define BSW_START_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_CONST_UNSPECIFIED
#elif defined CRYIF_STOP_SEC_CONST_UNSPECIFIED
    #define BSW_STOP_SEC_CONST_UNSPECIFIED
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_CONST_UNSPECIFIED

/* Cleared RAM: 8 bit values */
#elif defined CRYIF_START_SEC_VAR_CLEARED_8
    #define BSW_START_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_CLEARED_8
#elif defined CRYIF_STOP_SEC_VAR_CLEARED_8
    #define BSW_STOP_SEC_VAR_CLEARED_8
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_CLEARED_8

/* Cleared RAM: 16 bit values */
#elif defined CRYIF_START_SEC_VAR_CLEARED_16
    #define BSW_START_SEC_VAR_CLEARED_16
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_CLEARED_16
#elif defined CRYIF_STOP_SEC_VAR_CLEARED_16
    #define BSW_STOP_SEC_VAR_CLEARED_16
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_CLEARED_16

/* Cleared RAM: 32 bit values */
#elif defined CRYIF_START_SEC_VAR_CLEARED_32
    #define BSW_START_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_CLEARED_32
#elif defined CRYIF_STOP_SEC_VAR_CLEARED_32
    #define BSW_STOP_SEC_VAR_CLEARED_32
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_CLEARED_32

/* Cleared RAM: unspecified size */
#elif defined CRYIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined CRYIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED

/* Initialized RAM: 8 bit values */
#elif defined CRYIF_START_SEC_VAR_INIT_8
    #define BSW_START_SEC_VAR_INIT_8
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_INIT_8
#elif defined CRYIF_STOP_SEC_VAR_INIT_8
    #define BSW_STOP_SEC_VAR_INIT_8
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_INIT_8

/* Initialized RAM: 16 bit values */
#elif defined CRYIF_START_SEC_VAR_INIT_16
    #define BSW_START_SEC_VAR_INIT_16
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_INIT_16
#elif defined CRYIF_STOP_SEC_VAR_INIT_16
    #define BSW_STOP_SEC_VAR_INIT_16
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_INIT_16

/* Initialized RAM: 32 bit values */
#elif defined CRYIF_START_SEC_VAR_INIT_32
    #define BSW_START_SEC_VAR_INIT_32
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_INIT_32
#elif defined CRYIF_STOP_SEC_VAR_INIT_32
    #define BSW_STOP_SEC_VAR_INIT_32
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_INIT_32

/* Initialized RAM: unspecified size */
#elif defined CRYIF_START_SEC_VAR_INIT_UNSPECIFIED
    #define BSW_START_SEC_VAR_INIT_UNSPECIFIED
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined CRYIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define BSW_STOP_SEC_VAR_INIT_UNSPECIFIED
    #include "Bsw_MemMap.h"
    /* PRQA S 0841 2 */ /* <Deviation: using #undef is intended here */
    #undef CRYIF_STOP_SEC_VAR_INIT_UNSPECIFIED

#else
/* MR12 RULE 1.2 VIOLATION: false positive (This file is part if the CAP-SST memmap concept.) */
    #error "No valid memmap constant defined before including CRYIF_MemMap.h"
#endif

/*
**********************************************************************************************************************
* Type definitions
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Variables
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/
