
/*
**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"
#include "DcmAppl.h"


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
#define     DCM_AUTH_STARTROUTINE                                                    1u
#define     DCM_AUTH_STOPROUTINE                                                     2u
#define     DCM_AUTH_REQUESTRESULTS                                                  3u

#define     DCM_RDTC_SUBFUNCUSERDEFINEDMEMORYSNAPSHORT                               0x18u
#define     DCM_RDTC_SUBFUNCUSERDEFINEDMEMORYEXTDATA                                 0x19u

#define     DCM_AUTH_DID_WHITELISTOFFSET                                             3u
#define     DCM_AUTH_RID_WHITELISTOFFSET                                             3u

#define     DCM_WHITELISTCHECKLEN1BYTE                                               1u
#define     DCM_WHITELISTCHECKLEN2BYTE                                               2u
#define     DCM_WHITELISTCHECKLEN3BYTE                                               3u
#define     DCM_WHITELISTCHECKLEN4BYTE                                               4u

#define DCM_START_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
static const uint8 Dcm_WhiteListReadAccess_cu8 =1u;
static const uint8 Dcm_WhiteListWriteAccess_cu8 =2u;
static const uint8 Dcm_WhiteListControlAccess_cu8 =4u;
static const uint8 Dcm_WhiteListStartRoutineAccess_cu8 =1u;
static const uint8 Dcm_WhiteListStopRoutineAccess_cu8 =2u;
static const uint8 Dcm_WhiteListRqstRoutineResultAccess_cu8 =4u;
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

/*
*********************************************************************************************************************
 * Variables
*********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static uint8 Dcm_AuthenticationDefaultRoleValue_au8[DCM_CFG_AUTH_ROLE_SIZE];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

static Std_ReturnType Dcm_CheckWhitelist(uint16 authConnectionIndex_u16, Dcm_AccessRightsCheckType_ten checkType_en,
        const uint8* checkData_pcau8);
static Std_ReturnType Dcm_SearchMemorySelectionWhitelist(uint16 authConnectionIndex_u16, const uint8* checkData_pcau8);
static Std_ReturnType Dcm_CheckRole(uint16 authConnectionIndex_u16,const uint8* allowedRoleValue_pcau8);
static Std_ReturnType Dcm_SearchRIDWhitelist(uint16 authConnectionIndex_u16, const uint8* checkData_pcau8);
static Std_ReturnType Dcm_SearchDIDWhitelist(uint16 authConnectionIndex_u16, const uint8* checkData_pcau8);
static Std_ReturnType Dcm_SearchServiceWhitelist(uint16 authConnectionIndex_u16,const uint8* checkData_pcau8);

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

void Dcm_Prv_AccessRightsIni(void)
{
    uint8 roleIdx_u8;
    uint16 authConnectionIndex_u16;

    for(roleIdx_u8 = 0; roleIdx_u8 < DCM_CFG_AUTH_ROLE_SIZE; roleIdx_u8++)
    {
        Dcm_AuthenticationDefaultRoleValue_au8[roleIdx_u8] = (uint8)((uint32)Dcm_Cfg_AuthDeauthenticatedRole_cu32>>(roleIdx_u8*8));
    }

    /* Reset all connection states in Access Right Table */
    for(authConnectionIndex_u16 = 0; authConnectionIndex_u16 < DCM_CFG_AUTH_NUM_CONNECTION; authConnectionIndex_u16++)
    {
        Dcm_Prv_SetAuthState(authConnectionIndex_u16,DCM_DEAUTHENTICATED);
        Dcm_Prv_SetRole(authConnectionIndex_u16,&Dcm_AuthenticationDefaultRoleValue_au8[0]);
        Dcm_Prv_ClearWhitelists(authConnectionIndex_u16);
    }
}


static Std_ReturnType Dcm_CheckWhitelist(uint16 authConnectionIndex_u16, Dcm_AccessRightsCheckType_ten checkType_en,const uint8* checkData_pcau8)
{
    Std_ReturnType checkWhitelistResult=E_NOT_OK;

    checkWhitelistResult = Dcm_SearchServiceWhitelist(authConnectionIndex_u16,checkData_pcau8);

   if( E_NOT_OK == checkWhitelistResult)
   {
       switch(checkType_en)
       {
           case DCM_CHECK_DID:
               checkWhitelistResult = Dcm_SearchDIDWhitelist(authConnectionIndex_u16,checkData_pcau8);
               break;
           case DCM_CHECK_RID:
               checkWhitelistResult = Dcm_SearchRIDWhitelist(authConnectionIndex_u16,checkData_pcau8);
               break;
           case DCM_CHECK_MEMSELN:
               checkWhitelistResult = Dcm_SearchMemorySelectionWhitelist(authConnectionIndex_u16,checkData_pcau8);
               break;
           default:
               checkWhitelistResult=E_NOT_OK;
               break;
       }

   }
    return checkWhitelistResult;
}

static Std_ReturnType Dcm_SearchServiceWhitelist(uint16 authConnectionIndex_u16,const uint8* checkData_pcau8)
{
    const Dcm_WhitelistServiceType_tst *whitelistService_pst;
    uint8_least numEntryIdx_qu8;
    uint8 whitelistIndex_u8=0;
    Std_ReturnType serviceWhitelistResult=E_NOT_OK;
    uint8 whitelistOffset_u8=0;

    whitelistService_pst = Dcm_AccessRightsTable_acst[authConnectionIndex_u16].whitelistService_pst;

    if((whitelistService_pst != NULL_PTR))
    {
        for(numEntryIdx_qu8 = 0;numEntryIdx_qu8< whitelistService_pst->whitelistNumEntry_u8;numEntryIdx_qu8++)
        {
            whitelistOffset_u8 = whitelistService_pst->whitelistOffset_au8[numEntryIdx_qu8];

            /*make sure elements are not accessed outside service whitelist array*/
            if((whitelistIndex_u8+whitelistOffset_u8)<= DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE)
            {
                /*Check for next service entry offset*/
                if(whitelistService_pst->whitelist_au8[whitelistIndex_u8] == checkData_pcau8[0])
                {
                    switch(whitelistOffset_u8)
                    {
                        case DCM_WHITELISTCHECKLEN1BYTE:
                              serviceWhitelistResult=E_OK;
                            break;
                        case DCM_WHITELISTCHECKLEN2BYTE:
                            if((checkData_pcau8[1] == whitelistService_pst->whitelist_au8[whitelistIndex_u8+1u]))
                            {
                              serviceWhitelistResult=E_OK;
                            }
                            break;
                        case DCM_WHITELISTCHECKLEN3BYTE:
                            if((checkData_pcau8[1] == whitelistService_pst->whitelist_au8[whitelistIndex_u8+1u]) &&
                                    (checkData_pcau8[2] == whitelistService_pst->whitelist_au8[whitelistIndex_u8+2u]))
                            {
                              serviceWhitelistResult=E_OK;
                            }
                            break;
                        case DCM_WHITELISTCHECKLEN4BYTE:
                            if((checkData_pcau8[1] == whitelistService_pst->whitelist_au8[whitelistIndex_u8+1u])&&
                                    (checkData_pcau8[2] == whitelistService_pst->whitelist_au8[whitelistIndex_u8+2u])&&
                                    (checkData_pcau8[3] == whitelistService_pst->whitelist_au8[whitelistIndex_u8+3u]))
                            {
                              serviceWhitelistResult=E_OK;
                            }
                            break;
                        default:
                            serviceWhitelistResult=E_NOT_OK;
                          break;
                    }

                }
                /*Check for next service entry offset based on size available in whitelistOffset_au8*/
                whitelistIndex_u8 +=  whitelistService_pst->whitelistOffset_au8[numEntryIdx_qu8];
            }
            else
            {
                break;
            }
        }
    }

    return serviceWhitelistResult;
}

static Std_ReturnType Dcm_SearchDIDWhitelist(uint16 authConnectionIndex_u16, const uint8* checkData_pcau8)
{
    const Dcm_WhitelistDIDType_tst *whitelistDID_pst;
    uint8 searchIdx_u8;
    uint8 whiteListAccessDefinition_u8=0;
    Std_ReturnType didWhitelistResult = E_NOT_OK;

    whitelistDID_pst =  Dcm_AccessRightsTable_acst[authConnectionIndex_u16].whitelistDID_pst;

    if((whitelistDID_pst != NULL_PTR) && (whitelistDID_pst->whitelistNumEntry_u8 != 0))
    {
        /*make sure elements are not accessed outside DID whitelist array*/
        if(((DCM_AUTH_DID_WHITELISTOFFSET*(whitelistDID_pst->whitelistNumEntry_u8-1))+2u)< DCM_CFG_AUTH_WHITELIST_DID_MAX_SIZE)
        {
            for(searchIdx_u8 = 0;searchIdx_u8< whitelistDID_pst->whitelistNumEntry_u8;searchIdx_u8++)
            {
               if((whitelistDID_pst->whitelist_au8[(DCM_AUTH_DID_WHITELISTOFFSET*searchIdx_u8)] == checkData_pcau8[1])
                        && (whitelistDID_pst->whitelist_au8[((DCM_AUTH_DID_WHITELISTOFFSET*searchIdx_u8)+1u)] == checkData_pcau8[2]))
                {
                    /*Get the access definition from 3rd byte in the whitelist*/
                    whiteListAccessDefinition_u8 = whitelistDID_pst->whitelist_au8[((DCM_AUTH_DID_WHITELISTOFFSET*searchIdx_u8)+2u)];
                    switch(checkData_pcau8[0])
                    {
                        case DCM_DSP_SID_READDATABYIDENTIFIER:
                        case DCM_DSP_SID_READDATABYPERIODICIDENTIFIER:
                        case DCM_DSP_SID_DYNAMICALLYDEFINEDATAIDENTIFIER:
                            if(Dcm_WhiteListReadAccess_cu8 == (whiteListAccessDefinition_u8 & Dcm_WhiteListReadAccess_cu8))
                            {
                              didWhitelistResult= E_OK;
                            }
                            break;
                        case DCM_DSP_SID_WRITEDATABYIDENTIFIER:
                            if(Dcm_WhiteListWriteAccess_cu8 == (whiteListAccessDefinition_u8 & Dcm_WhiteListWriteAccess_cu8))
                            {
                              didWhitelistResult= E_OK;
                            }
                            break;
                        case DCM_DSP_SID_INPUTOUTPUTCONTROLBYIDENTIFIER:
                            if(Dcm_WhiteListControlAccess_cu8 == (whiteListAccessDefinition_u8 & Dcm_WhiteListControlAccess_cu8))
                            {
                              didWhitelistResult= E_OK;
                            }
                            break;
                        default:
                            didWhitelistResult = E_NOT_OK;
                            break;

                    }
                  break; /*break to come out of searchIdx_u8 loop*/
                  }
             }
        }
    }
    return didWhitelistResult;
}


static Std_ReturnType Dcm_SearchRIDWhitelist(uint16 authConnectionIndex_u16, const uint8* checkData_pcau8)
{
    const Dcm_WhitelistRIDType_tst *whitelistRID_pst;
    uint8 searchIdx_u8;
    uint8 whiteListAccessDefinition_u8=0;
    Std_ReturnType ridWhitelistResult = E_NOT_OK;

    whitelistRID_pst = Dcm_AccessRightsTable_acst[authConnectionIndex_u16].whitelistRID_pst;

    if((whitelistRID_pst != NULL_PTR) && (whitelistRID_pst->whitelistNumEntry_u8 != 0))
    {
        /*make sure elements are not accessed outside RID whitelist array*/
        if(((DCM_AUTH_RID_WHITELISTOFFSET*(whitelistRID_pst->whitelistNumEntry_u8-1))+2u)< DCM_CFG_AUTH_WHITELIST_RID_MAX_SIZE)
        {
            for(searchIdx_u8 = 0;searchIdx_u8< whitelistRID_pst->whitelistNumEntry_u8;searchIdx_u8++)
            {
                if((whitelistRID_pst->whitelist_au8[(DCM_AUTH_RID_WHITELISTOFFSET*searchIdx_u8)] == checkData_pcau8[2])
                        && (whitelistRID_pst->whitelist_au8[((DCM_AUTH_RID_WHITELISTOFFSET*searchIdx_u8)+1u)] == checkData_pcau8[3]))
                {
                    /*Get the access definition from 3rd byte in the whitelist*/
                    whiteListAccessDefinition_u8 = whitelistRID_pst->whitelist_au8[((DCM_AUTH_DID_WHITELISTOFFSET*searchIdx_u8)+2u)];
                    switch(checkData_pcau8[1])
                    {
                        case DCM_AUTH_STARTROUTINE:
                            if(Dcm_WhiteListStartRoutineAccess_cu8 == (whiteListAccessDefinition_u8 & Dcm_WhiteListStartRoutineAccess_cu8))
                            {
                              ridWhitelistResult = E_OK;
                            }
                            break;
                        case DCM_AUTH_STOPROUTINE:
                            if(Dcm_WhiteListStopRoutineAccess_cu8 == (whiteListAccessDefinition_u8 & Dcm_WhiteListStopRoutineAccess_cu8))
                            {
                              ridWhitelistResult = E_OK;
                            }
                            break;
                        case DCM_AUTH_REQUESTRESULTS:
                            if(Dcm_WhiteListRqstRoutineResultAccess_cu8 == (whiteListAccessDefinition_u8 & Dcm_WhiteListRqstRoutineResultAccess_cu8))
                            {
                              ridWhitelistResult = E_OK;
                            }
                            break;
                        default:
                            ridWhitelistResult = E_NOT_OK;
                            break;
                    }
                  break; /*break to come out of search loop*/
                }
             }
        }
    }

    return ridWhitelistResult;
}


static Std_ReturnType Dcm_SearchMemorySelectionWhitelist(uint16 authConnectionIndex_u16,const uint8* checkData_pcau8)
{
    const Dcm_WhitelistMemSelnType_tst *whitelistMemSeln_pst;
    uint8_least searchIdx_qu8;
    uint8 checkMemSelnId_u8=0;
    Std_ReturnType memSelWhitelistResult=E_NOT_OK;

    whitelistMemSeln_pst = Dcm_AccessRightsTable_acst[authConnectionIndex_u16].whitelistMemSeln_pst;

    if((checkData_pcau8[1] == DCM_RDTC_SUBFUNCUSERDEFINEDMEMORYSNAPSHORT)
    || (checkData_pcau8[1] == DCM_RDTC_SUBFUNCUSERDEFINEDMEMORYEXTDATA))
    {
        checkMemSelnId_u8 = checkData_pcau8[6];
    }
    else
    {
        checkMemSelnId_u8 = checkData_pcau8[3];
    }

    if(whitelistMemSeln_pst != NULL_PTR)
    {
        /*make sure elements are not accessed outside Memory whitelist array*/
        if(whitelistMemSeln_pst->whitelistNumEntry_u8 <= DCM_CFG_AUTH_WHITELIST_MEMSELN_MAX_SIZE)
        {
            for(searchIdx_qu8 = 0;searchIdx_qu8< whitelistMemSeln_pst->whitelistNumEntry_u8;searchIdx_qu8++)
            {
                if(whitelistMemSeln_pst->whitelist_au8[searchIdx_qu8] == checkMemSelnId_u8)
                {
                  memSelWhitelistResult = E_OK;
                  break;
                }
            }
        }
    }

    return memSelWhitelistResult;
}


static Std_ReturnType Dcm_CheckRole(uint16 authConnectionIndex_u16,const uint8* allowedRoleValue_pcau8)
{
    const Dcm_AccessRightsTableType_tst *accessRightsTable_pcst;
    uint8_least roleIdx_qu8;
    Std_ReturnType roleResult=E_NOT_OK;

    accessRightsTable_pcst =  &Dcm_AccessRightsTable_acst[authConnectionIndex_u16];

    for(roleIdx_qu8 = 0; roleIdx_qu8 < DCM_CFG_AUTH_ROLE_SIZE; roleIdx_qu8++)
    {
        /*perform AND operation and check if atleast one role has the access */
       if((accessRightsTable_pcst->role_pau8[roleIdx_qu8] & allowedRoleValue_pcau8[roleIdx_qu8]) > 0)
        {
            roleResult = E_OK;
            break;
        }
    }

    return roleResult;
}


#if(DCM_CFG_RTESUPPORT_ENABLED!=DCM_CFG_OFF)
Std_ReturnType Dcm_SetDeauthenticatedRoleRTE(uint16 ConnectionId, const uint8* deauthenticatedRole)
{
    Dcm_AuthenticationRoleType deauthenticatedRoleValue;
    uint8_least loopIdx_qu8;

    for (loopIdx_qu8=0;loopIdx_qu8<DCM_CFG_AUTH_ROLE_SIZE;loopIdx_qu8++)
    {
        deauthenticatedRoleValue[loopIdx_qu8] = deauthenticatedRole[loopIdx_qu8];
    }

    return Dcm_SetDeauthenticatedRole(ConnectionId, deauthenticatedRoleValue);
}
#endif

/* MR12 RULE 8.13 VIOLATION: cast may discard const qualifier. So used as non constant pointer*/
Std_ReturnType Dcm_SetDeauthenticatedRole(uint16 ConnectionId, Dcm_AuthenticationRoleType deauthenticatedRoleValue)
{
    uint16 authConnectionIndex_u16;
    Std_ReturnType setRoleResult = E_OK;

    for(authConnectionIndex_u16=0;authConnectionIndex_u16< DCM_CFG_AUTH_NUM_CONNECTION;authConnectionIndex_u16++)
    {
        if(ConnectionId == Dcm_Cfg_AuthConnectionMapping_acu16[authConnectionIndex_u16])
        {
            if(DCM_DEAUTHENTICATED == Dcm_Prv_GetAuthState(authConnectionIndex_u16))
            {
                Dcm_Prv_SetRole(authConnectionIndex_u16,deauthenticatedRoleValue);
            }
            break;
        }
    }

    return setRoleResult;
}


Std_ReturnType Dcm_Prv_GetAuthConnectionIndex(PduIdType dcmRxPduId, uint16* authConnectionIndex_u16)
{
    uint16 authconnIdx_u16;
    Std_ReturnType authConnResult = E_NOT_OK;

    uint16 connectionId_u16 = Dcm_Prv_GetMainConnection(dcmRxPduId)->rxConnId_u16;

    for(authconnIdx_u16=0;authconnIdx_u16< DCM_CFG_AUTH_NUM_CONNECTION;authconnIdx_u16++)
    {
        if(connectionId_u16 == Dcm_Cfg_AuthConnectionMapping_acu16[authconnIdx_u16])
        {
            *authConnectionIndex_u16 = authconnIdx_u16;
             authConnResult = E_OK;
            break;
        }
    }

    return  authConnResult;
}


Dcm_stAuthenticationType_ten Dcm_Prv_GetAuthState(uint16 authConnectionIndex_u16)
{
    Dcm_stAuthenticationType_ten authenticationstate_en=DCM_DEAUTHENTICATED;


        authenticationstate_en = *Dcm_AccessRightsTable_acst[authConnectionIndex_u16].Dcm_stAuthentication_pen;

    return authenticationstate_en;
}


void Dcm_Prv_ResetAccessRights(uint16 authConnectionIndex_u16)
{
    const Dcm_AccessRightsTableType_tst *accessRightsTable_pcst;
    Std_ReturnType authPersistResult = E_NOT_OK;

    Dcm_Prv_SetRole(authConnectionIndex_u16,&Dcm_AuthenticationDefaultRoleValue_au8[0]);
    Dcm_Prv_ClearWhitelists(authConnectionIndex_u16);
    Dcm_Prv_SetAuthState(authConnectionIndex_u16,DCM_DEAUTHENTICATED);

    accessRightsTable_pcst =  &Dcm_AccessRightsTable_acst[authConnectionIndex_u16];


    authPersistResult = Dcm_WriteAccessRights(authConnectionIndex_u16,(uint8)DCM_ROLE,accessRightsTable_pcst->role_pau8,NULL_PTR,NULL_PTR);

    if(accessRightsTable_pcst->whitelistService_pst != NULL_PTR)
    {
        authPersistResult = Dcm_WriteAccessRights(authConnectionIndex_u16,(uint8)DCM_WHITELIST_SERVICE,
                accessRightsTable_pcst->whitelistService_pst->whitelist_au8,
                &accessRightsTable_pcst->whitelistService_pst->whitelistNumEntry_u8,
                accessRightsTable_pcst->whitelistService_pst->whitelistOffset_au8);
    }

    if(accessRightsTable_pcst->whitelistDID_pst != NULL_PTR)
    {
        authPersistResult = Dcm_WriteAccessRights(authConnectionIndex_u16,(uint8)DCM_WHITELIST_DID,
                accessRightsTable_pcst->whitelistDID_pst->whitelist_au8,
                &accessRightsTable_pcst->whitelistDID_pst->whitelistNumEntry_u8,
                NULL_PTR);
    }

    if(accessRightsTable_pcst->whitelistRID_pst != NULL_PTR)
    {
        authPersistResult = Dcm_WriteAccessRights(authConnectionIndex_u16,(uint8)DCM_WHITELIST_RID,
                accessRightsTable_pcst->whitelistRID_pst->whitelist_au8,
                &accessRightsTable_pcst->whitelistRID_pst->whitelistNumEntry_u8,
                NULL_PTR);
    }

    if(accessRightsTable_pcst->whitelistMemSeln_pst != NULL_PTR)
    {
        authPersistResult = Dcm_WriteAccessRights(authConnectionIndex_u16,(uint8)DCM_WHITELIST_MEMSELN,
                accessRightsTable_pcst->whitelistMemSeln_pst->whitelist_au8,
                &accessRightsTable_pcst->whitelistMemSeln_pst->whitelistNumEntry_u8,
                NULL_PTR);
    }

}


void Dcm_Prv_SetAuthState(uint16 authConnectionIndex_u16, Dcm_stAuthenticationType_ten authState_en)
{
    uint16 connIdx_u16=0;
    uint16 connectionId_u16;

        *Dcm_AccessRightsTable_acst[authConnectionIndex_u16].Dcm_stAuthentication_pen =  authState_en;

        connectionId_u16 = Dcm_Cfg_AuthConnectionMapping_acu16[authConnectionIndex_u16];

#if(DCM_CFG_RTESUPPORT_ENABLED!=DCM_CFG_OFF)
       for(connIdx_u16=0;connIdx_u16< DCM_CFG_TOTAL_DSL_CONNECTIONS;connIdx_u16++)
       {
           if(connectionId_u16 == Dcm_AuthModeSwitchInfo_st[connIdx_u16].connectionId_u16)
           {

             if(Dcm_AuthModeSwitchInfo_st[connIdx_u16].modeSwitchInterface_fp != NULL_PTR)
             {
                 (void)(Dcm_AuthModeSwitchInfo_st[connIdx_u16].modeSwitchInterface_fp)(authState_en);
             }

               break;
           }
       }
#else
       (void)connIdx_u16;
#endif
}


void Dcm_Prv_SetRole(uint16 authConnectionIndex_u16,const uint8* authenticationRole_pau8)
{
    uint8_least roleIdx_qu8;

        for(roleIdx_qu8 = 0; roleIdx_qu8 < DCM_CFG_AUTH_ROLE_SIZE; roleIdx_qu8++)
        {
            Dcm_AccessRightsTable_acst[authConnectionIndex_u16].role_pau8[roleIdx_qu8] = authenticationRole_pau8[roleIdx_qu8];
        }
}


void Dcm_Prv_SetWhitelist(uint16 authConnectionIndex_u16, Dcm_CertElementType_ten whitelistType_en,
        const uint8* whitelistData_pau8, uint8 whitelistNumEntry_u8,const uint8* whitelistOffset_pau8)
{
    const Dcm_AccessRightsTableType_tst *accessRightsTable_pcst;
    uint8_least whitelistIdx_qu8;

    if(authConnectionIndex_u16 < DCM_CFG_AUTH_NUM_CONNECTION)
    {
        accessRightsTable_pcst = &Dcm_AccessRightsTable_acst[authConnectionIndex_u16];

        switch(whitelistType_en)
        {
            case DCM_WHITELIST_SERVICE:
            {
                for(whitelistIdx_qu8 = 0; whitelistIdx_qu8 < DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE; whitelistIdx_qu8++)
                {
                    accessRightsTable_pcst->whitelistService_pst->whitelist_au8[whitelistIdx_qu8] = whitelistData_pau8[whitelistIdx_qu8];
                    accessRightsTable_pcst->whitelistService_pst->whitelistOffset_au8[whitelistIdx_qu8] = whitelistOffset_pau8[whitelistIdx_qu8];
                }
                 accessRightsTable_pcst->whitelistService_pst->whitelistNumEntry_u8 = whitelistNumEntry_u8;

                break;
            }
            case DCM_WHITELIST_DID:
            {
                for(whitelistIdx_qu8 = 0; whitelistIdx_qu8 < DCM_CFG_AUTH_WHITELIST_DID_MAX_SIZE; whitelistIdx_qu8++)
                {
                    accessRightsTable_pcst->whitelistDID_pst->whitelist_au8[whitelistIdx_qu8] = whitelistData_pau8[whitelistIdx_qu8];
                }

                accessRightsTable_pcst->whitelistDID_pst->whitelistNumEntry_u8 = whitelistNumEntry_u8;
                break;
            }
            case DCM_WHITELIST_RID:
            {
                for(whitelistIdx_qu8 = 0; whitelistIdx_qu8 < DCM_CFG_AUTH_WHITELIST_RID_MAX_SIZE; whitelistIdx_qu8++)
                {
                    accessRightsTable_pcst->whitelistRID_pst->whitelist_au8[whitelistIdx_qu8] = whitelistData_pau8[whitelistIdx_qu8];
                }
                accessRightsTable_pcst->whitelistRID_pst->whitelistNumEntry_u8 = whitelistNumEntry_u8;
                break;
            }
            case DCM_WHITELIST_MEMSELN:
            {
                for(whitelistIdx_qu8 = 0; whitelistIdx_qu8 < DCM_CFG_AUTH_WHITELIST_MEMSELN_MAX_SIZE; whitelistIdx_qu8++)
                {
                   accessRightsTable_pcst->whitelistMemSeln_pst->whitelist_au8[whitelistIdx_qu8] = whitelistData_pau8[whitelistIdx_qu8];
                }
                accessRightsTable_pcst->whitelistMemSeln_pst->whitelistNumEntry_u8 = whitelistNumEntry_u8;
                break;
            }
            default:
            {
               /*Must never reach here. Added for QAC*/
                break;
            }
        }


    }
}


void Dcm_Prv_ClearWhitelists(uint16 authConnectionIndex_u16)
{
    const Dcm_AccessRightsTableType_tst *accessRightsTable_pcst;
    uint8_least idxLoop_qu8;

        accessRightsTable_pcst = &Dcm_AccessRightsTable_acst[authConnectionIndex_u16];

        if(accessRightsTable_pcst->whitelistService_pst != NULL_PTR)
        {
            accessRightsTable_pcst->whitelistService_pst->whitelistNumEntry_u8 = 0x00;
            for(idxLoop_qu8 = 0; idxLoop_qu8 < DCM_CFG_AUTH_WHITELIST_SERVICE_MAX_SIZE; idxLoop_qu8++)
            {
                accessRightsTable_pcst->whitelistService_pst->whitelist_au8[idxLoop_qu8] = 0x00;
                accessRightsTable_pcst->whitelistService_pst->whitelistOffset_au8[idxLoop_qu8] = 0x00;
            }
        }

        if(accessRightsTable_pcst->whitelistDID_pst != NULL_PTR)
        {
            accessRightsTable_pcst->whitelistDID_pst->whitelistNumEntry_u8 = 0x00;
            for(idxLoop_qu8 = 0; idxLoop_qu8 < DCM_CFG_AUTH_WHITELIST_DID_MAX_SIZE; idxLoop_qu8++)
            {
                accessRightsTable_pcst->whitelistDID_pst->whitelist_au8[idxLoop_qu8] = 0x00;
            }
        }

        if(accessRightsTable_pcst->whitelistRID_pst != NULL_PTR)
        {
            accessRightsTable_pcst->whitelistRID_pst->whitelistNumEntry_u8 = 0x00;
            for(idxLoop_qu8 = 0; idxLoop_qu8 < DCM_CFG_AUTH_WHITELIST_RID_MAX_SIZE; idxLoop_qu8++)
            {
                accessRightsTable_pcst->whitelistRID_pst->whitelist_au8[idxLoop_qu8] = 0x00;
            }
        }

        if(accessRightsTable_pcst->whitelistMemSeln_pst != NULL_PTR)
        {
            accessRightsTable_pcst->whitelistMemSeln_pst->whitelistNumEntry_u8 = 0x00;
            for(idxLoop_qu8 = 0; idxLoop_qu8 < DCM_CFG_AUTH_WHITELIST_MEMSELN_MAX_SIZE; idxLoop_qu8++)
            {
                accessRightsTable_pcst->whitelistMemSeln_pst->whitelist_au8[idxLoop_qu8] = 0x00;
            }
        }
}


#endif

/* MR12 RULE 8.13 VIOLATION: The object addressed by pointer are modified under a particular usecase, and hence should be P2VAR */
Std_ReturnType Dcm_Prv_CheckAccessRights(Dcm_AccessRightsCheckType_ten checkType_en,
        uint32 allowedRole_u32,const Dcm_MsgContextType *pMsgContext ,Dcm_NegativeResponseCodeType * dataNegRespCode_u8)

{
    Std_ReturnType accessRightsResult = E_NOT_OK;
#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED == DCM_CFG_ON)
    uint16 authConnectionIndex_u16;
    uint8 roleIdx_u8;
    uint8 checkData_au8[7]={0};
    uint8 authenticationRoleValue_au8[DCM_CFG_AUTH_ROLE_SIZE];

    if((pMsgContext->idContext >= DCM_DSP_SID_DIAGNOSTICSESSIONCONTROL) && (pMsgContext->idContext != DCM_DSP_SID_TESTERPRESENT))
    {
        checkData_au8[0] = pMsgContext->idContext;
        checkData_au8[1] = pMsgContext->reqData[0];
        checkData_au8[2] = pMsgContext->reqData[1];
        checkData_au8[3] = pMsgContext->reqData[2];

        if(DCM_CHECK_MEMSELN == checkType_en)
        {
            if((pMsgContext->reqData[0] == DCM_RDTC_SUBFUNCUSERDEFINEDMEMORYSNAPSHORT)
            || (pMsgContext->reqData[0] == DCM_RDTC_SUBFUNCUSERDEFINEDMEMORYEXTDATA))
            {
                checkData_au8[4] = pMsgContext->reqData[3];
                checkData_au8[5] = pMsgContext->reqData[4];
                checkData_au8[6] = pMsgContext->reqData[5];
            }
        }

        for(roleIdx_u8 =0;roleIdx_u8<DCM_CFG_AUTH_ROLE_SIZE;roleIdx_u8++)
        {
            authenticationRoleValue_au8[roleIdx_u8] = (uint8)(((uint32)allowedRole_u32>>(roleIdx_u8*8)));
        }


        if(E_OK == Dcm_Prv_GetAuthConnectionIndex(pMsgContext->dcmRxPduId,&authConnectionIndex_u16))
        {
            if(Dcm_CheckRole(authConnectionIndex_u16,&authenticationRoleValue_au8[0]) == E_OK)
            {
                accessRightsResult =  E_OK;
            }
            else
            {
                if(DCM_AUTHENTICATED == Dcm_Prv_GetAuthState(authConnectionIndex_u16))
                {
                    accessRightsResult = Dcm_CheckWhitelist(authConnectionIndex_u16,checkType_en,&checkData_au8[0]);
                }
            }
        }
        else
        {
            accessRightsResult = E_OK;
        }

        if(accessRightsResult == E_NOT_OK)
        {
            *dataNegRespCode_u8 = DCM_E_AUTHENTICATIONREQUIRED;
        }
    }
    else
    {
        /*Provide Access to Tester Present always*/
        accessRightsResult = E_OK;
    }

#else
    accessRightsResult = E_OK;
    (void)pMsgContext;
    (void)checkType_en;
    (void)allowedRole_u32;
    (void)dataNegRespCode_u8;
#endif
    return accessRightsResult;
}
