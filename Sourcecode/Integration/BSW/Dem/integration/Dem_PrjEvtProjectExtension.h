/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */




#ifndef DEM_PRJEVTPROJECTEXTENSION_H
#define DEM_PRJEVTPROJECTEXTENSION_H

/**
 * \file
 * \ingroup DEM_PRJ_TPL
 * \brief Custom functionality on every event status report
 *
 * If DemRbEvtProjectExtension is enabled, this method will be called on every event status report
 */

/**
 * \brief Called whenever Dem_SetEventStatus() or their related methods are called.
 *
 * Called after parameters are validated and debouncing is handled.
 *
 * \param EventId Identification of event by ID
 * \param EventStatus  The reported status of the event (passed, failed, pre-passed, etc.) after debouncing is handled.
 *                     That means that a reported pre-failed could be qualified to failed in the debouncing and then
 *                     this parameter would be set to failed
 * \param debAction    The debounce action that was taken (see DEM_DEBACTION_*)
 */
DEM_INLINE void Dem_EvtProjectExtensionSetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus, uint8_least debAction)
{
    /* Do something very short here!!!
     * This function is called with every setEventStatus (PASSED/FAILED, PREFAILED/PREPASSED, ...).
     */

    /* also consider using locks in case of multitasking */
}


#endif /* INCLUDE_PROTECTION */
