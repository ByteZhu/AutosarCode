/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */



/* NOTE: All definitions within this headers have to be adjusted according to the project needs
 * Within the provided template only one example is provided.
 * Please consult the documentation of rba_MemLib for details of the functionality required.
 * Note: Default settings are defined within the rba_MemLib_Timer_Inl.h
 */

#ifndef RBA_MEMLIB_CFG_TIMER_CALLOUTS_H
#define RBA_MEMLIB_CFG_TIMER_CALLOUTS_H

/*
 ****************************************************************************************************
 * Includes
 ****************************************************************************************************
 */
#include "Std_Types.h"
#include "Mcu.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/** ***********************************************************************
 * \brief   Bit-size of the free-running timer
 * The result value of rba_MemLib_Callout_GetTimerTicks wraps around at 2**RBA_MEMLIB_TIMERBITSIZE.
 * The value range is therefore [0 .. (2**RBA_MEMLIB_TIMERBITSIZE)-1 ]
 * Highest value allowed is 32.
 * Smallest value allowed is 20.
 *
 * Example: RBA_MEMLIB_TIMERBITSIZE (32u)   for a 32bit free-running-time
 * Value range is then [0 .. (2**32)-1] = [0 .. 0xFFFFFFFF]
 *
*/
#define RBA_MEMLIB_TIMERBITSIZE   (32u)


/** ***********************************************************************
 * \brief   Activation of the BYPASS_TIMER_US feature is possible only
 *          IF rba_MemLib_Callout_BypassTimerUs provides a 1us resolution output.
 *          In that case the code and the runtime in the MemLib can be
 *          slightly reduced.
 * STD_ON:  User configures a 32bit upcounter with 1us resolution directly
 * STD_OFF: rba_MemLib is calculating the timer value (DEFAULT)
 *
*/
#define RBA_MEMLIB_BYPASS_TIMER_US  (STD_OFF)


/** ***********************************************************************
 * \brief   Activate timer check during initialization
 * In case the check fails the initialization is not finished.
 * This switch is only evaluated if RBA_MEMLIB_BYPASS_TIMER_US == STD_OFF
 * STD_ON:  Timer Functionality check is performed   (DEFAULT)
 * STD_OFF: Timer Functionality check is NOT performed (saves some code)
 *
*/
#define RBA_MEMLIB_USE_TIMER_CHECK   (STD_ON)


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

/*
 **********************************************************************************************************************
 * Inlines
 **********************************************************************************************************************
*/

/** ***********************************************************************
 * \brief   Get timer-ticks from a free-running/wrap-around timer (e.g. system-timer)
 * Attention: The timer has to be chosen in a way that
 *    1) timer-resolution <= 1us/LSB
 *    2) timer-resolution * (2**RBA_MEMLIB_TIMERBITSIZE) >= 1000000us = 1s
 * \return  current timer-ticks (resolution <= 1us/LSB), Bitsize see RBA_MEMLIB_TIMERBITSIZE
*/
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE uint32 rba_MemLib_Callout_GetTimerTicks(void)
{
    return(Mcu_Rb_GetSysTicks());
}

/** ***********************************************************************
 * \brief   Convert a timer-difference in timer-ticks to microseconds(us)
 * Note: no overflow handling is needed, overflows are handled by caller
 * \param   Timer-ticks
 * \return  Timer-ticks converted to microseconds
*/
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE uint32 rba_MemLib_Callout_ConvertTimerTicksToUs(uint32 tiTicks_u32)
{
    return(MCU_RB_TICKS_TO_US(tiTicks_u32));
}

/** ***********************************************************************
 * \brief   Convert microseconds to timer-ticks
 * \param   tiUs_u32  microsecond value, passed values <=1000000us=1s.
 * Note: no overflow handling is needed
 * \return  Microseconds converted to timer-ticks
*/
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE uint32 rba_MemLib_Callout_ConvertUsToTimerTicks(uint32 tiUs_u32)
{
    return(MCU_RB_US_TO_TICKS(tiUs_u32));
}


/*
 **********************************************************************************************************************
 * Inlines Bypass
 **********************************************************************************************************************
*/

/** ***********************************************************************
 * \brief   Bypass to provide a 32bit free-running upcounter with 1us resolution
 *          This is only needed if the system is providing such a timer (otherwise it is simulated by MemLib)
 *          only relevant if : (RBA_MEMLIB_USE_TIMER != STD_OFF) && (RBA_MEMLIB_BYPASS_TIMER_US != STD_OFF)
 * \return  Counter/Timer in 1us/LSB resolution (full 32bit range)
*/
#if (RBA_MEMLIB_BYPASS_TIMER_US != STD_OFF)
/* MR12 RULE 5.9 VIOLATION: declaration/definition of LOCAL_INLINE functions are split on different headers for hiding implementation - no issue */
LOCAL_INLINE uint32 rba_MemLib_Callout_BypassTimerUs(void)
{
    return(0u);
}
#endif




#endif      /* Header multi-inclusion protection */

