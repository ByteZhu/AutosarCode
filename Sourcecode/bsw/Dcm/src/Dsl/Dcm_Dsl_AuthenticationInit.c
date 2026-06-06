
/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"
#include "DcmAppl.h"

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"
static boolean  Dcm_PersistConnectionStatus_ab[DCM_CFG_AUTH_NUM_CONNECTION];
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_MemMap.h"

static void Dcm_PersistAuthentication(void);



void Dcm_Prv_Dsl_AuthenticationIni(void)
{
    Dcm_Prv_AccessRightsIni();

    Dcm_Prv_AuthTimerIni();

    Dcm_PersistAuthentication();

}


static void Dcm_PersistAuthentication(void)
{
    boolean modeChkRetval_b;
    Std_ReturnType persistentStatus=E_NOT_OK;
    uint16 authConnIdx_u16;
    uint16 connectionId_u16=0;
    PduIdType rxPduId;
    Dcm_NegativeResponseCodeType modeRuleNRC;
    const Dcm_AccessRightsTableType_tst *accessRightsTable_pcst;

    /*Check for moderule function to validate if authentication information was persisted*/
    if(Dcm_Cfg_AuthPersistentStateModeRule_pfct != NULL_PTR)
    {
        modeChkRetval_b = Dcm_Cfg_AuthPersistentStateModeRule_pfct(&modeRuleNRC);

        /*if authentication information was persisted regain them to access rights table*/
        if(modeChkRetval_b == TRUE)
        {
            Dcm_GetPersistedStatusOfAuthenticationConnections(DCM_CFG_AUTH_NUM_CONNECTION,&Dcm_PersistConnectionStatus_ab[0]);

            for(authConnIdx_u16 = 0;authConnIdx_u16 < DCM_CFG_AUTH_NUM_CONNECTION;authConnIdx_u16++)
            {
                accessRightsTable_pcst = &Dcm_AccessRightsTable_acst[authConnIdx_u16];

                if(Dcm_PersistConnectionStatus_ab[authConnIdx_u16] == TRUE)
                {

                    persistentStatus = Dcm_ReadAccessRights(authConnIdx_u16,
                            (uint8)DCM_ROLE,accessRightsTable_pcst->role_pau8, NULL_PTR, NULL_PTR);

                    if((accessRightsTable_pcst->whitelistService_pst != NULL_PTR) && (persistentStatus == E_OK))
                    {
                        persistentStatus = Dcm_ReadAccessRights(authConnIdx_u16,
                                                        (uint8)DCM_WHITELIST_SERVICE,
                                                        accessRightsTable_pcst->whitelistService_pst->whitelist_au8,
                                                        &accessRightsTable_pcst->whitelistService_pst->whitelistNumEntry_u8,
                                                        accessRightsTable_pcst->whitelistService_pst->whitelistOffset_au8);
                    }


                    if((accessRightsTable_pcst->whitelistDID_pst != NULL_PTR) && (persistentStatus == E_OK))
                    {
                        persistentStatus = Dcm_ReadAccessRights(authConnIdx_u16,
                                                        (uint8)DCM_WHITELIST_DID,
                                                        accessRightsTable_pcst->whitelistDID_pst->whitelist_au8,
                                                        &accessRightsTable_pcst->whitelistDID_pst->whitelistNumEntry_u8,
                                                        NULL_PTR);
                    }

                    if((accessRightsTable_pcst->whitelistRID_pst != NULL_PTR) && (persistentStatus == E_OK))
                    {
                        persistentStatus = Dcm_ReadAccessRights(authConnIdx_u16,
                                                        (uint8)DCM_WHITELIST_RID,
                                                        accessRightsTable_pcst->whitelistRID_pst->whitelist_au8,
                                                        &accessRightsTable_pcst->whitelistRID_pst->whitelistNumEntry_u8,
                                                        NULL_PTR);
                    }

                    if((accessRightsTable_pcst->whitelistMemSeln_pst != NULL_PTR) && (persistentStatus == E_OK))
                    {
                        persistentStatus = Dcm_ReadAccessRights(authConnIdx_u16,
                                                        (uint8)DCM_WHITELIST_MEMSELN,
                                                        accessRightsTable_pcst->whitelistMemSeln_pst->whitelist_au8,
                                                        &accessRightsTable_pcst->whitelistMemSeln_pst->whitelistNumEntry_u8,
                                                        NULL_PTR);
                    }


                    /*Reading any of the whitelist information failure shall result in complete clear of all
                     * whitelists for corresponding connection*/
                    if(persistentStatus == E_NOT_OK)
                    {
                        Dcm_Prv_ClearWhitelists(authConnIdx_u16);
                    }
                    else
                    {
                        /*Set to Authenticated state only if accessRightsTable has a valid persistent data*/
                        Dcm_Prv_SetAuthState(authConnIdx_u16, DCM_AUTHENTICATED);

                        connectionId_u16 = Dcm_Cfg_AuthConnectionMapping_acu16[authConnIdx_u16];

                        for(rxPduId=0;rxPduId<DCM_CFG_TOTAL_RX_PDUID;rxPduId++)
                        {
                            if(connectionId_u16 == Dcm_Prv_GetMainConnection(rxPduId)->rxConnId_u16)
                            {
                                Dcm_Prv_AuthTimerHandling(DCM_TIMER_START,rxPduId);
                                break;
                            }
                        }

                    }

                }

            }
        }
    }

}

#endif

