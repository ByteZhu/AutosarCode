/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */


#ifndef CSM_CFG_SCHM_H
#define CSM_CFG_SCHM_H

/*
 **********************************************************************************************************************
 * Readme
 **********************************************************************************************************************
*/
/*
0) locking does not need special configuration, locking duration is independent of cryptostack configuration
- info: locking function calls are generated if and only if at least one asynchronous job is configured
- info: the queues are local to Csm_MainFunction, no synchronisation needed here
- info: locking access to a request FIFO is only used, if at least one asynchronous job is associated with the corresponding
  queue
1) access to a queue's request FIFO in client context is synchronized
  - exclusive area: ClientsAccessFIFO
    - currently, the same exclusive area with common lock is used for all FIFOs of queues with async jobs
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



#define SchM_Enter_Csm_JobQueueAccess(lock)
#define SchM_Exit_Csm_JobQueueAccess(lock)

/* The integrator shall implement the particular services SchM_Enter and SchM_Exit.*/

LOCAL_INLINE FUNC(void, CSM_CODE) SchM_Enter_Csm_ClientsAccessFIFO(void);
LOCAL_INLINE FUNC(void, CSM_CODE) SchM_Exit_Csm_ClientsAccessFIFO(void);

LOCAL_INLINE FUNC(void, CSM_CODE) SchM_Enter_Csm_ClientsAccessFIFO(void)
{
	/*The integrator shall place his code here which would disable/lock the interrupt*/
}

LOCAL_INLINE FUNC(void, CSM_CODE) SchM_Exit_Csm_ClientsAccessFIFO(void)
{
	/* The integrator shall place here the code which would unlock the interrupts */
}

#endif /* CSM_CFG_SCHM_H */
