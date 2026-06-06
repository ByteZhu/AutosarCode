/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

/**
 * \brief Source file providing freshness interface of the SecOC module.
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC.h"
#include "SecOC_Prv.h"
#include "Rte_SecOC.h"
/*
 **********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************
*/

#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"
/**
 ***********************************************************************************************************************
 * SecOC_Prv_GetTxFreshness
 *
 * \brief Generates a freshness value with the defined bitlength and a truncated freshness value with the desired
 *        bitlength.
 *        The functions calls either the function GetTxFreshness or GetTxFreshnessTruncData depending of provided
 *        freshness interface. For this the PDU specific configuration parameter secOCProvideTxTruncatedFreshnessValue
 *        is checked which is given as parameter provideTxTruncatedFreshnessValue_b.
 *        If the truncated freshness value is not provided by the freshness manager the truncation of the complete
 *        freshness value is done in this function.
 *
 * \param[in]   freshnessValueId_u16
 *                             Id of the Freshness Value
 *
 * \param[out]  freshnessValue_pau8
 *                             Holds a pointer to the result buffer for the generated freshness value
 *
 * \param[in,out]   freshnessValueLengthBits_pu8
 *                             Length of the generated freshness value in bits
 *
 * \param[out]  truncatedFreshnessValue_pau8
 *                             Holds a pointer to the result buffer for the generated freshness value
 *
 * \param[in,out]   truncatedFreshnessValueLengthBits_pu8
 *                             Desired length for the generated truncated freshness value in bits
 *
 * \param[in]   provideTxTruncatedFreshnessValue_b
 *                             Flag to indicate if truncated freshness value is provided by freshness management
 *
 * \return  Std_ReturnType     Evaluates the work-flow of the function call.
 *                             E_NOT_OK: An error occurred
 *                             E_OK    : o.k.
 ***********************************************************************************************************************
*/
/* MR12 RULE 8.13 VIOLATION: AUTOSAR interface therefore parameter can not be set to 'pointer to const' */
Std_ReturnType SecOC_Prv_GetTxFreshness(uint16 freshnessValueId_u16,
                                        uint8* freshnessValue_pau8,
                                        uint8* freshnessValueLengthBits_pu8,
                                        uint8* truncatedFreshnessValue_pau8,
                                        uint8* truncatedFreshnessValueLengthBits_pu8,
                                        boolean provideTxTruncatedFreshnessValue_b)
{
    Std_ReturnType result_en = E_NOT_OK;
    uint32 minBufferSizeInBits_u32 = 0u;
    uint32 freshnessValueLengthBits_u32 = (uint32)(*freshnessValueLengthBits_pu8);
    uint32 truncatedFreshnessValueLengthBits_u32 = (uint32)(*truncatedFreshnessValueLengthBits_pu8);


    /* TRACE[SWS_SecOC_00221], TRACE[SWS_SecOC_00222], TRACE[SWS_SecOC_00223], TRACE[SWS_SecOC_00224], */
    /* TRACE[SWS_SecOC_00230], TRACE[SWS_SecOC_00231] */

    SECOC_PARAM_UNUSED(provideTxTruncatedFreshnessValue_b);
    {

        /* MR12 RULE 11.3 VIOLATION: freshnessValue is the result and can not be const */
        result_en = Rte_Call_RP_SecOC_FreshnessManagement_GetTxFreshness (
                            freshnessValueId_u16,
                            freshnessValue_pau8,
                            &freshnessValueLengthBits_u32);

        /* get truncated freshness derived of freshness value */
        if((truncatedFreshnessValueLengthBits_u32 > 0u) && (E_OK == result_en))
        {
            /* Calculate the amount of bytes required for the truncated bits result */
            minBufferSizeInBits_u32 = (uint32)((truncatedFreshnessValueLengthBits_u32 + 7U) & 0xFFFFFFF8uL);

            /* Copy the LSB from freshnessValue_au8 to the LSB of buffer for truncated freshness */
            SecOC_Prv_CopyBits(
                    truncatedFreshnessValue_pau8,                  /* out: destination */
                    (uint32)(minBufferSizeInBits_u32 -
                         truncatedFreshnessValueLengthBits_u32),   /*  in: dest bit position */
                    freshnessValue_pau8,                           /*  in: source */
                    (freshnessValueLengthBits_u32 -
                         truncatedFreshnessValueLengthBits_u32),   /*  in: source bit position */
                    truncatedFreshnessValueLengthBits_u32          /*  in: number of bits */
            );
        }
    }

    if (freshnessValueLengthBits_u32 < *freshnessValueLengthBits_pu8)
    {
        *freshnessValueLengthBits_pu8 = (uint8)freshnessValueLengthBits_u32;
    }
    if (truncatedFreshnessValueLengthBits_u32 < *truncatedFreshnessValueLengthBits_pu8)
    {
        *truncatedFreshnessValueLengthBits_pu8 = (uint8)truncatedFreshnessValueLengthBits_u32;
    }

    return (result_en);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_SPduTxConfirmation
 *
 * \brief This interface is used by the SecOC to indicate that the Secured I-PDU has been initiated for transmission.
 *
 * \param[in]   freshnessValueId_u16
 *                             Id of the Freshness Value
 *
 * \return      void
 ***********************************************************************************************************************
*/
void SecOC_Prv_SPduTxConfirmation(uint16 freshnessValueId_u16)
{
    /* TRACE[SWS_SecOC_00232], TRACE[SWS_SecOC_91005] */
    /* SRS_BSW_00357, SRS_BSW_00449: BSW Service APIs called by RTE shall return Std_ReturnType */
    (void)Rte_Call_RP_SecOC_FreshnessManagement_SPduTxConfirmation (freshnessValueId_u16);
}

/**
 ***********************************************************************************************************************
 * SecOC_Prv_GetRxFreshness
 *
 * \brief Takes the freshness value with the received reduced bitlength (data_pau8 and dataLengthBits_u32) and authentic
 *         data freshness value(data_pau8 and dataLengthBits_u32) as inputs, return the most likely version of the
 *         full length version of the received freshness value based on the current freshness value.
 *
 * \param[in]   freshnessValueId_u16
 *                             Id of the Freshness Value
 *
 * \param[in]   truncatedFreshnessValue_pau8
 *                             Holds a pointer to the buffer for the received truncated freshness value
 *
 * \param[in]   truncatedFreshnessValueLengthBits_u8
 *                             Length of the truncated freshness value in bits
 *
 * \param[out]  freshnessValue_pau8
 *                             Holds a pointer to the result buffer for the generated full freshness value
 *
 * \param[in]   authVerifyAttempts_u16
 *                             number of authentication verify attempts
 *
 * \param[in,out]   freshnessValueLengthBits_pu8
 *                             Length of the generated freshness value in bits
 *
 * \param[in]   authDataFreshnessValue_pau8
 *                             Holds a pointer to the buffer for the received authentic data freshness value
 *
 * \param[in]   authDataFreshnessValueLengthBits_u16
 *                             Length of the authentic data freshness value in bits
 *
 * \param[in]   useAuthDataFreshness_b
 *                             flag to indicate if a part of authentic I-PDU is used as freshness value
 *
 * \return  Std_ReturnType     Evaluates the work-flow of the function call.
 *                             E_NOT_OK: An error occurred
 *                             E_OK    : o.k.
 ***********************************************************************************************************************
*/
Std_ReturnType SecOC_Prv_GetRxFreshness( uint16 freshnessValueId_u16,
                                         const uint8* truncatedFreshnessValue_pau8,
                                         uint8 truncatedFreshnessValueLengthBits_u8,
                                         const uint8* authDataFreshnessValue_pau8,
                                         uint16 authDataFreshnessValueLengthBits_u16,
                                         uint16 authVerifyAttempts_u16,
                                         uint8* freshnessValue_pau8,
                                         uint8* freshnessValueLengthBits_pu8,
                                         boolean useAuthDataFreshness_b)
{
    Std_ReturnType result = E_NOT_OK;
    uint32 freshnessValueLengthBits_u32 = (uint32)(*freshnessValueLengthBits_pu8);
    uint32 truncatedFreshnessValueLengthBits_u32 = (uint32)truncatedFreshnessValueLengthBits_u8;

    /* TRACE[SWS_SecOC_00244], TRACE[SWS_SecOC_00245], TRACE[SWS_SecOC_00246], TRACE[SWS_SecOC_00249], */
    /* TRACE[SWS_SecOC_00250] */

    SECOC_PARAM_UNUSED(authDataFreshnessValue_pau8);
    SECOC_PARAM_UNUSED(authDataFreshnessValueLengthBits_u16);
    SECOC_PARAM_UNUSED(useAuthDataFreshness_b);
    {

        /* MR12 DIR 1.1 RULE 11.3 VIOLATION: freshnessValue is the result and can not be const */
        result = Rte_Call_RP_SecOC_FreshnessManagement_GetRxFreshness (
                                freshnessValueId_u16,
                                truncatedFreshnessValue_pau8,
                                truncatedFreshnessValueLengthBits_u32,
                                authVerifyAttempts_u16,
                                freshnessValue_pau8,
                                &freshnessValueLengthBits_u32);
    }

    /* Freshness manager supports fewer than requested bits, save new smaller length
       Freshness manager supports  more than requested bits, ignore returned length  */
    if (freshnessValueLengthBits_u32 < *freshnessValueLengthBits_pu8)
    {
        *freshnessValueLengthBits_pu8 = (uint8)freshnessValueLengthBits_u32;
    }


    return(result);
}

#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"
