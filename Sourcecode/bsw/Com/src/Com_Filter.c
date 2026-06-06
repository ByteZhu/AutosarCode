
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Com_Prv.h"


#ifdef COM_FILTERS
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#if !(defined(COM_F_MASKEDNEWEQUALSX) || defined(COM_F_MASKEDNEWDIFFERSX) || defined(COM_F_MASKEDNEWDIFFERSOLD) || \
       defined(COM_F_NEWISWITHIN_POS)  || defined(COM_F_NEWISWITHIN_NEG)   || defined(COM_F_NEWISOUTSIDE_POS) || \
       defined(COM_F_NEWISOUTSIDE_NEG) || defined(COM_F_ONEEVERYN))
 #define COM_FILTER_C_FilterIndex_IS_NOT_USED
#endif

#if !(defined(COM_F_MASKEDNEWEQUALSX) || defined(COM_F_MASKEDNEWDIFFERSX) || defined(COM_F_MASKEDNEWDIFFERSOLD) || \
       defined(COM_F_NEWISWITHIN_POS)  || defined(COM_F_NEWISWITHIN_NEG)   || defined(COM_F_NEWISOUTSIDE_POS) || \
       defined(COM_F_NEWISOUTSIDE_NEG))
 #define COM_FILTER_C_NewVal_IS_NOT_USED
#endif


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 Function name    : Com_Prv_Filter
 Description      : Service used for filtering the signal depending on the conditions
 Parameter        : newVal_u32              -> New value for filtering
                  : algorithm_u8            -> Filter type
                  : idxFilter_uo            -> Filter Index
                  : notFromIpduGrpStart_b   -> indicates if the call is from IpduGroup start functions
 Return value     : COM_TRUE/COM_FALSE
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
boolean Com_Prv_Filter(
                uint32              newVal_u32,
                uint8               algorithm_u8,
                Com_Filter_tuo      idxFilter_uo,
                boolean             notFromIpduGrpStart_b
                  )
{
    boolean     state_b;

    /* type-cast unused parameters to 'void' to prevent warnings */
#ifdef COM_FILTER_C_NewVal_IS_NOT_USED
    (void)newVal_u32;
#endif
#ifdef COM_FILTER_C_FilterIndex_IS_NOT_USED
    (void)idxFilter_uo;
#endif
#ifndef COM_F_ONEEVERYN
    (void)notFromIpduGrpStart_b;
#endif

    /* If algorithm is COM_ALWAYS, State is initialized to true, otherwise with false */
    state_b = (algorithm_u8 == COM_ALWAYS);

    switch (algorithm_u8)
    {
#ifdef COM_F_MASKEDNEWEQUALSX
        case COM_MASKED_NEW_EQUALS_X:
        {
            state_b = ((newVal_u32 & COM_GET_MASK_X(idxFilter_uo).mask_u32) == COM_GET_MASK_X(idxFilter_uo).xval_u32);
        }
        break;
#endif /* #ifdef COM_F_MASKEDNEWEQUALSX */

#ifdef COM_F_MASKEDNEWDIFFERSX
        case COM_MASKED_NEW_DIFFERS_X:
        {
            state_b = ((newVal_u32 & COM_GET_MASK_X(idxFilter_uo).mask_u32) != COM_GET_MASK_X(idxFilter_uo).xval_u32);
        }
        break;
#endif /* #ifdef COM_F_MASKEDNEWDIFFERSX */

#ifdef COM_F_MASKEDNEWDIFFERSOLD
        case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        {
            state_b = ((newVal_u32 & COM_GET_MASK(idxFilter_uo)) != (COM_GET_F_OLDVALUE(idxFilter_uo) & COM_GET_MASK(idxFilter_uo)));
            if (state_b)
            {
                /* TRACE[SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to true, (value is not
                 * filtered out) then the AUTOSAR COM module shall place the value of that signal into old_value */
                COM_GET_F_OLDVALUE(idxFilter_uo) = newVal_u32;
            }
        }
        break;
#endif /* COM_F_MASKEDNEWDIFFERSOLD */

#ifdef COM_F_NEWISWITHIN_POS
        case COM_NEW_IS_WITHIN_POS:
        {
            state_b = ((COM_GET_POSMINMAX(idxFilter_uo).min_u32 <= newVal_u32) && (newVal_u32 <= COM_GET_POSMINMAX(idxFilter_uo).max_u32));
        }
        break;
#endif /* #ifdef COM_F_NEWISWITHIN_POS */

#ifdef COM_F_NEWISWITHIN_NEG
        case COM_NEW_IS_WITHIN_NEG:
        {
            state_b = ((COM_GET_NEGMINMAX(idxFilter_uo).min_s32 <= (sint32)newVal_u32) &&
                     ((sint32)newVal_u32 <= COM_GET_NEGMINMAX(idxFilter_uo).max_s32));
        }
        break;
#endif /* #ifdef COM_F_NEWISWITHIN_NEG */

#ifdef COM_F_NEWISOUTSIDE_POS
        case COM_NEW_IS_OUTSIDE_POS:
        {
            state_b = ((newVal_u32 < COM_GET_POSMINMAX(idxFilter_uo).min_u32) ||
                     (newVal_u32 > COM_GET_POSMINMAX(idxFilter_uo).max_u32));
        }
        break;
#endif /* #ifdef COM_F_NEWISOUTSIDE_POS */

#ifdef COM_F_NEWISOUTSIDE_NEG
        case COM_NEW_IS_OUTSIDE_NEG:
        {
            state_b = (((sint32)newVal_u32 < COM_GET_NEGMINMAX(idxFilter_uo).min_s32) ||
                     ((sint32)newVal_u32 > COM_GET_NEGMINMAX(idxFilter_uo).max_s32));
        }
        break;
#endif /* #ifdef COM_F_NEWISOUTSIDE_NEG */

#ifdef COM_F_ONEEVERYN
        case COM_ONE_EVERY_N:
        {
            /* TRACE[SWS_Com_00231] In the case of ComFilterAlgorithm is configured to ONE_EVERY_N,
             * the AUTOSAR COM module shall
             * - set FILTER to true, when OCCURRENCE == OFFSET
             * - increment OCCURRENCE after filter processing
             * - set OCCURRENCE to zero when OCCURRENCE == PERIOD
             */
            state_b = (COM_GET_ONEEVERYN(idxFilter_uo).occurrence_u8 == COM_GET_ONEEVERYN(idxFilter_uo).offset_u32);

            /* if call is not from Com_Init/Com_IPduGroupControl, occurrence value has to be incremented by one. */
            if (notFromIpduGrpStart_b)
            {
                COM_GET_ONEEVERYN(idxFilter_uo).occurrence_u8++;
            }
            if (COM_GET_ONEEVERYN(idxFilter_uo).occurrence_u8 == COM_GET_ONEEVERYN(idxFilter_uo).period_u32)
            {
                COM_GET_ONEEVERYN(idxFilter_uo).occurrence_u8 = COM_ZERO;
            }
        }
        break;
#endif /* #ifdef COM_F_ONEEVERYN */

        default:
        {
            /* Default case covers COM_NEVER algorithm, hence there is no explicit case for COM_NEVER */
        }
        break;
    }

    return state_b;
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* #ifdef COM_FILTERS */

