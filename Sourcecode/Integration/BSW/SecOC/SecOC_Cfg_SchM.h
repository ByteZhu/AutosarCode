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

#ifndef SECOC_CFG_SCHM_H
#define SECOC_CFG_SCHM_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
/* The integrator include the required header file */
/* e.g. #include "rba_BswSrv.h" */


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/
LOCAL_INLINE void SchM_Enter_SecOC_TxContext(PduLengthType pduId_uo);
LOCAL_INLINE void SchM_Exit_SecOC_TxContext(PduLengthType pduId_uo);
LOCAL_INLINE void SchM_Enter_SecOC_RxContext(PduLengthType pduId_uo);
LOCAL_INLINE void SchM_Exit_SecOC_RxContext(PduLengthType pduId_uo);
LOCAL_INLINE void SchM_Enter_SecOC_SameBuffer(void);
LOCAL_INLINE void SchM_Exit_SecOC_SameBuffer(void);
LOCAL_INLINE void SchM_Enter_SecOC_SaveVerifyStatusOverride(void);
LOCAL_INLINE void SchM_Exit_SecOC_SaveVerifyStatusOverride(void);
LOCAL_INLINE void SchM_Enter_SecOC_DefaultAuthenticationInformation(void);
LOCAL_INLINE void SchM_Exit_SecOC_DefaultAuthenticationInformation(void);

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
 */
/*
 * Exclusive area:
 * - This exclusive area protects all accesses to shared ressources within the SecOC module,
 *   in particular between the public service APIs and the SecOC_MainFunctionRx/Tx.
 * - On multi-core machines, a lock functionality is required which works across all cores which could invoke SecOC's
 *   public service APIs or schedules the SecOC_MainFunctionRx/Tx.
 *   On single core machines, a global interrupt lock or (possibly SecOC-specific) semaphore is sufficient.
 */
/* To be defined by the integrator
   Note: this instruction takes an integer (PduIdType) as argument in order to provide resource locking on a finer granularity.
   If this is implemented as a default common lock, runtime performance can suffer significant degradation. */
LOCAL_INLINE void SchM_Enter_SecOC_TxContext(PduLengthType pduId_uo)
{
    SECOC_PARAM_UNUSED(pduId_uo);
}

/* To be defined by the integrator
   Note: this instruction takes an integer (PduIdType) as argument in order to provide resource locking on a finer granularity.
   If this is implemented as a default common lock, runtime performance can suffer significant degradation. */

LOCAL_INLINE void SchM_Exit_SecOC_TxContext(PduLengthType pduId_uo)
{
    SECOC_PARAM_UNUSED(pduId_uo);
}

/* To be defined by the integrator
   Note: this instruction takes an integer (PduIdType) as argument in order to provide resource locking on a finer granularity.
   If this is implemented as a default common lock, runtime performance can suffer significant degradation. */
LOCAL_INLINE void SchM_Enter_SecOC_RxContext(PduLengthType pduId_uo)
{
    SECOC_PARAM_UNUSED(pduId_uo);
}

/* To be defined by the integrator
   Note: this instruction takes an integer (PduIdType) as argument in order to provide resource locking on a finer granularity.
   If this is implemented as a default common lock, runtime performance can suffer significant degradation. */

LOCAL_INLINE void SchM_Exit_SecOC_RxContext(PduLengthType pduId_uo)
{
    SECOC_PARAM_UNUSED(pduId_uo);
}

/* To be defined by the integrator */
LOCAL_INLINE void SchM_Enter_SecOC_SameBuffer(void)
{

}

/* To be defined by the integrator */
LOCAL_INLINE void SchM_Exit_SecOC_SameBuffer(void)
{

}

/* To be defined by the integrator */
LOCAL_INLINE void SchM_Enter_SecOC_SaveVerifyStatusOverride(void)
{

}

/* To be defined by the integrator */
LOCAL_INLINE void SchM_Exit_SecOC_SaveVerifyStatusOverride(void)
{

}

/* To be defined by the integrator */
LOCAL_INLINE void SchM_Enter_SecOC_DefaultAuthenticationInformation(void)
{

}

/* To be defined by the integrator */
LOCAL_INLINE void SchM_Exit_SecOC_DefaultAuthenticationInformation(void)
{

}

#endif /* SECOC_CFG_SCHM_H */
