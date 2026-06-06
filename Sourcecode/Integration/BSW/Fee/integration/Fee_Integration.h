/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */

/* BSWEXT-451 */
#ifndef FEE_INTEGRATION_H
#define FEE_INTEGRATION_H

/* This macro definition should align with Fls/FlsGeneral/FlsBlankCheckApi configuration */
#define FLS_BLANK_CHECK_API STD_ON

/* Note: Fls_Rb_AddressType and Fls_Rb_LengthType are defined from AUTOSAR 's Fls_AddressType and Fls_LengthType type definitions */
typedef Fls_AddressType Fls_Rb_AddressType;
typedef Fls_LengthType Fls_Rb_LengthType;

#endif  /* FEE_INTEGRATION_H */
