/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */


#ifndef CSM_CFG_EXTERNALCALLOUT_H
#define CSM_CFG_EXTERNALCALLOUT_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
/* To be defined by the integrator */

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/* To be defined by the integrator */
#define Csm_Rb_RandomSeed_ExternalCallout(keyId, seedPtr, seedLength)

/* To be defined by the integrator */
#define Csm_Rb_ProcessJob_ExternalCallout(job)

/* To be defined by the integrator */
#define Csm_Rb_CancelJob_ExternalCallout(job)

/* Integration Example

#define Csm_Rb_RandomSeed_ExternalCallout(keyId, seedPtr, seedLength) Csm_Rb_RandomSeed_Integration(keyId, seedPtr, seedLength)

LOCAL_INLINE Std_ReturnType Csm_Rb_RandomSeed_Integration(uint32 keyId, const uint8* seedPtr, uint32 seedLength)
{
    // declare variables
    Std_ReturnType error_u8 = E_NOT_OK;

    // keyId paramater is not used for random seed purposes (in the current scenario).
    CSM_PARAM_UNUSED(keyId);

    // call 3rd party library API for random seed purposes.
    if (0U == ThirdParty_RandomSeed(seedPtr, seedLength))
    {
        error_u8 = E_OK;
    }


    return (error_u8);
}

#define Csm_Rb_ProcessJob_ExternalCallout(job) Csm_Rb_ProcessJob_Integration(job)

LOCAL_INLINE Std_ReturnType Csm_Rb_ProcessJob_Integration(Crypto_JobType* job)
{
    // declare variables
    Std_ReturnType error_u8 = E_NOT_OK;
    uint8* randomData_pau8 = NULL_PTR;
    uint32* randomDataLength_pu32 = NULL_PTR;


    // extract job members to be used during random generation.
    randomData_pau8 = job->jobPrimitiveInputOutput.outputPtr;
    randomDataLength_pu32 = job->jobPrimitiveInputOutput.outputLengthPtr;

    // call 3rd party library API for random generation purposes (synchronous API).
    if (0U == ThirdParty_RandomGenerate(randomData_pau8, randomDataLength_pu32))
    {
        error_u8 = E_OK;
    }
    else
    {
        // do nothing
    }


    return (error_u8);
}

#define Csm_Rb_CancelJob_ExternalCallout(job) Csm_Rb_CancelJob_Integration(job)

LOCAL_INLINE Std_ReturnType Csm_Rb_CancelJob_Integration(Crypto_JobType* job)
{
    // declare variables
    Std_ReturnType error_u8 = E_NOT_OK;

    // in this example cleanup is mandatory by third party library.
    if (0U == ThirdParty_Cleanup())
    {
        error_u8 = E_OK;
    }


    return (error_u8);
}

*/
#endif /* CSM_CFG_EXTERNALCALLOUT_H */
