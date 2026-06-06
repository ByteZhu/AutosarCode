/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef SECOC_PRV_FRESHIF_H
#define SECOC_PRV_FRESHIF_H

/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/

extern Std_ReturnType SecOC_Prv_GetTxFreshness(uint16 freshnessValueId_u16,
                                                        uint8* freshnessValue_pau8,
                                                        uint8* freshnessValueLengthBits_pu8,
                                                        uint8* truncatedFreshnessValue_pau8,
                                                        uint8* truncatedFreshnessValueLengthBits_pu8,
                                                        boolean provideTxTruncatedFreshnessValue_b);

extern void SecOC_Prv_SPduTxConfirmation(uint16 freshnessValueId_u16);

extern Std_ReturnType SecOC_Prv_GetRxFreshness(uint16 freshnessValueId_u16,
                                               const uint8* truncatedFreshnessValue_pau8,
                                               uint8 truncatedFreshnessValueLengthBits_u8,
                                               const uint8* authDataFreshnessValue_pau8,
                                               uint16 authDataFreshnessValueLengthBits_u16,
                                               uint16 authVerifyAttempts_u16,
                                               uint8* freshnessValue_pau8,
                                               uint8* freshnessValueLengthBits_pu8,
                                               boolean useAuthDataFreshness_b);
/* SECOC_PRV_FRESHIF_H */
#endif
