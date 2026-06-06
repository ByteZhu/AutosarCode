/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */



/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm.h"
#include "DcmAppl.h"


#if(DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
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
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/**
 * @ingroup DCM_TPL
 * Dcm_ReadAccessRights :-\n
 * This api will be called to Read the access rights information such as Role and whitelist information from the non-volatile memory
 * @param[in]     authConnectionIndex_u16  : The index of the authentication connection for which the access rights information needs to be read from the non-volatile memory.
 * @param[in]     accessRightsType_u8      : The type of access rights that needs to be read
 *                                              0x00: ROLE
 *                                              0x01: WHITELIST SERVICE
 *                                              0x02: WHITELIST DID
 *                                              0x03: WHITELIST RID
 *                                              0x04: WHITELIST MEMSELN
 * @param[out]    accessRightsData_pau8    :  Pointer to a uint8 array in which the access rights data read from the non-volatile memory shall be written in to.
 *                                              The size of this array is dependent on the accessRightsType_u8.
 *                                              0x00: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationRoleSize}
 *                                              0x01: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListServicesMaxSize}
 *                                              0x02: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListDIDMaxSize}
 *                                              0x03: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListRIDMaxSize}
 *                                              0x04: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListMemorySelectionMaxSize}
 * @param[out]    accessRightsNumEntry_pu8 :  Pointer to the information where the number of access rights entries read from the non-volatile memory shall be written in to.
 *                                              This parameter is not relevant for accessRightsType_u8 = 0x00, so a NULL_PTR will be sent in this case.
 * @param[out]    accessRightsOffset_pau8  :  Pointer to a uint8 array in which the offset of the access rights data read from the non-volatile memory shall be written in to.
 *                                              This parameter is relevant only for the accessRightsType_u8 = 0x01. The size of this array is {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListServicesMaxSize}.
 *                                              For all the other accessRightsType_u8 this will be a NULL_PTR.
 * @retval        E_OK                     :  Read from the Non-Volatile memory is successful.
 * @retval        E_NOT_OK                 :  Read from the Non-Volatile memory is not successful due to some errors.
 */
Std_ReturnType Dcm_ReadAccessRights (uint16 authConnectionIndex_u16,
                                    uint8 accessRightsType_u8,
                                    uint8* accessRightsData_pau8,
                                    uint8* accessRightsNumEntry_pu8,
                                    uint8* accessRightsOffset_pau8)
{
    /* BSWEXT-470 */
    Std_ReturnType readResult = E_NOT_OK;
    /*TESTCODE-START
    readResult = DcmTest_Dcm_ReadAccessRights (authConnectionIndex_u16,accessRightsType_u8,accessRightsData_pau8,
                                               accessRightsNumEntry_pu8,accessRightsOffset_pau8);
    TESTCODE-END*/
    return (readResult);
}


/**
 * @ingroup DCM_TPL
 * Dcm_WriteAccessRights :-\n
 * This api will be called to Write the access rights information such as Role and whitelist information in to the non-volatile memory
 * @param[in]     authConnectionIndex_u16  : The index of the authentication connection for which the access rights information needs to be written in to the non-volatile memory.
 * @param[in]     accessRightsType_u8      : The type of access rights that needs to be written
 *                                              0x00: ROLE
 *                                              0x01: WHITELIST SERVICE
 *                                              0x02: WHITELIST DID
 *                                              0x03: WHITELIST RID
 *                                              0x04: WHITELIST MEMSELN
 * @param[in]    accessRightsData_pau8    :  Pointer to a uint8 array which contains the access rights data that needs to be written in to the non-volatile memory.
 *                                              The size of this array is dependent on the accessRightsType_u8.
 *                                              0x00: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationRoleSize}
 *                                              0x01: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListServicesMaxSize}
 *                                              0x02: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListDIDMaxSize}
 *                                              0x03: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListRIDMaxSize}
 *                                              0x04: {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListMemorySelectionMaxSize}
 * @param[in]    accessRightsNumEntry_pu8 :  Pointer to the information which contains the number of access rights entries that needs to be written in to the non-volatile memory.
 *                                              This parameter is not relevant for accessRightsType_u8 = 0x00, so a NULL_PTR will be sent in this case.
 * @param[in]    accessRightsOffset_pau8  :  Pointer to a uint8 array which contains the offset of the access rights data that needs to be written in to the non-volatile memory.
 *                                              This parameter is relevant only for the accessRightsType_u8 = 0x01. The size of this array is {ecuc(Dcm/DcmDsp/DcmDspAuthentication/DcmDspAuthenticationWhiteListServicesMaxSize}.
 *                                               For all the other accessRightsType_u8 this will be a NULL_PTR.
 * @retval        E_OK                     :  Write in to the Non-Volatile memory is successful.
 * @retval        E_NOT_OK                 :  Write in to the Non-Volatile memory is not successful due to some errors.
 */
Std_ReturnType Dcm_WriteAccessRights (uint16 authConnectionIndex_u16,
                                    uint8 accessRightsType_u8,
                                    const uint8* accessRightsData_pau8,
                                    const uint8* accessRightsNumEntry_pu8,
                                    const uint8* accessRightsOffset_pau8)
{
    /* BSWEXT-470 */
    Std_ReturnType writeResult =E_NOT_OK;
    /*TESTCODE-START
    writeResult = DcmTest_Dcm_WriteAccessRights(authConnectionIndex_u16,accessRightsType_u8,accessRightsData_pau8,
                                                accessRightsNumEntry_pu8,accessRightsOffset_pau8);
    TESTCODE-END*/
    return (writeResult);
}


/**
 * @ingroup DCM_TPL
 * Dcm_GetPersistedStatusOfAuthenticationConnections :-\n
 * This api will be called to get the persisted status of the access rights of each of the configured authentication connection which is stored in the Non-Volatile memory.
 * If any of the access rights data of an authentication connection is stored in the non-volatile memory, the corresponding index shall be set to TRUE in the array pointed by stPersisted_pab.
 * If none of the access rights data of an authentication connection is stored, then the corresponding index shall be set to FALSE
 * @param[in]       numAuthenticationConnection     :  Total number of configured authentication connections
 * @param[out]      stPersisted_pab                 :  Pointer to a boolean array of size numAuthenticationConnection, in which the persisted status of each of the configured authentication connection will be written.
 *                                                      TRUE  : Authentication connection persisted in the non-volatile memory
 *                                                      FALSE : Authentication connection not persisted in the non-volatile memory
 * @retval          void
 */
void Dcm_GetPersistedStatusOfAuthenticationConnections (uint16 numAuthenticationConnection, boolean*  stPersisted_pab)
{
    /* BSWEXT-470 */
    /*TESTCODE-START
     DcmTest_Dcm_GetPersistedStatusOfAuthenticationConnections(numAuthenticationConnection,stPersisted_pab);
    TESTCODE-END*/
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif /*( DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON) */
