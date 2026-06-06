/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/
/* MemMap.h for AUTOSAR Memory Mapping R4.0 Rev 1-2 */

/*
**********************************************************************************************************************
The following section checks which of the preprocessor constants are defined for
the memory layout. Each .c file will do the following for each function
definition:

1. define the E2E_START_SEC_<type>
2. include this file
3. define the function itself
4. define E2E_STOP_SEC_<type> after the function,
5. include this file again.

There are two options for layout definitions in this file:

1. The standard Memmap concept using a central definition in another file.
   Projects that do not use the RTA-BSW SW, In the case of a project using the
   RTA-BSW SW, the BSW memmap header file will be available e.g.

        #if defined E2E_START_SEC_<section name>
            #define  BSW_START_SEC_<section name>
            #include "Bsw_MemMap.h"
            #undef E2E_START_SEC_<section name>

2. Alternatively, the definition can be made directly in E2E with a #pragma e.g.

        #elif defined (E2E_START_SEC_<section name>)
           #undef      E2E_START_SEC_<section name>
           #pragma section ".text.bsw" ax

There are many different section names possible. Only those currently used in the
E2E module are defined below.
**********************************************************************************************************************
*/

/* Default code section */
/* MR12 RULE 1.2, DIR 4.10 VIOLATION: MemMap header concept - no protection against multiple inclusion intended */
#if defined E2E_START_SEC_CODE
    #define  BSW_START_SEC_CODE
    #include "Bsw_MemMap.h"
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
    #undef E2E_START_SEC_CODE
#elif defined E2E_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
    #include "Bsw_MemMap.h"
    #undef E2E_STOP_SEC_CODE

#else
    #error "No valid memmap constant defined before including E2E_MemMap.h"
#endif
