/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */


#ifndef CRYIF_CRYPTO_WRAPPER_H
#define CRYIF_CRYPTO_WRAPPER_H
/* BSW-8976 */
/*
**********************************************************************************************************************
* Includes
**********************************************************************************************************************
*/
/* Rename this import as necessary to import the crypto driver being integrated */
#include "Crypto_SW.h"

/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/

/* Example #defines shown here demonstrate how an integrator should find the function name from the Crypto driver
they are integrating and map it to the Autosar Crypto driver function name.*/
// #define Crypto_ProcessJob               Crypto_SW_ProcessJob
// #define Crypto_CancelJob                Crypto_SW_CancelJob
// #define Crypto_KeyElementSet            Crypto_SW_KeyElementSet
// #define Crypto_KeySetValid              Crypto_SW_KeySetValid
// #define Crypto_KeyElementGet            Crypto_SW_KeyElementGet
// #define Crypto_KeyElementCopy           Crypto_SW_KeyElementCopy
// #define Crypto_KeyCopy                  Crypto_SW_KeyCopy
// #define Crypto_KeyElementIdsGet         Crypto_SW_KeyElementIdsGet
// #define Crypto_KeyElementCopyPartial    Crypto_SW_KeyElementCopyPartial
// #define Crypto_RandomSeed               Crypto_SW_RandomSeed
// #define Crypto_KeyGenerate              Crypto_SW_KeyGenerate
// #define Crypto_KeyDerive                Crypto_SW_KeyDerive
// #define Crypto_KeyExchangeCalcPubVal    Crypto_SW_KeyExchangeCalcPubVal
// #define Crypto_KeyExchangeCalcSecret    Crypto_SW_KeyExchangeCalcSecret
// #define Crypto_CertificateParse         Crypto_SW_CertificateParse
// #define Crypto_CertificateVerify        Crypto_SW_CertificateVerify
// #define CryIf_Prv_Dummy_KeyGetStatus    CryIf_SW_Prv_Dummy_KeyGetStatus
// #define CryIf_Prv_Dummy_Rb_StorePermanentData CryIf_SW_Prv_Dummy_Rb_StorePermanentData

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
#endif /* CRYIF_CRYPTO_WRAPPER_H */
