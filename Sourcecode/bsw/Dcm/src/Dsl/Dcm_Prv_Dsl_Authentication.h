#ifndef DCM_PRIV_DSL_AUTHENTICATION_H
#define DCM_PRIV_DSL_AUTHENTICATION_H

#include "Dcm_Prv_Types.h"

#if (DCM_CFG_DSP_AUTHENTICATION_ENABLED != DCM_CFG_OFF)

void Dcm_Prv_Dsl_AuthenticationIni(void);
void Dcm_Prv_AuthS3ServerTimeout(void);
void Dcm_Prv_AuthTimerHandling(Dcm_TimerActionType_ten timerAction_en, PduIdType dcmRxPduId);
void Dcm_Prv_AuthTimerIni(void);
void Dcm_Prv_AccessRightsIni(void);

Std_ReturnType Dcm_Prv_GetAuthConnectionIndex(PduIdType dcmRxPduId, uint16* authConnectionIndex_u16);
Dcm_stAuthenticationType_ten Dcm_Prv_GetAuthState(uint16 authConnectionIndex_u16);
void Dcm_Prv_ResetAccessRights(uint16 authConnectionIndex_u16);
void Dcm_Prv_SetAuthState(uint16 authConnectionIndex_u16, Dcm_stAuthenticationType_ten authState_en);
void Dcm_Prv_SetRole(uint16 authConnectionIndex_u16,const uint8* authenticationRole_pau8);
void Dcm_Prv_SetWhitelist(uint16 authConnectionIndex_u16, Dcm_CertElementType_ten whitelistType_en,
        const uint8* whitelistData_pau8, uint8 whitelistNumEntry_u8, const uint8* whitelistOffset_pau8) ;
void Dcm_Prv_ClearWhitelists(uint16 authConnectionIndex_u16);
Std_ReturnType Dcm_SetDeauthenticatedRole(uint16 ConnectionId, Dcm_AuthenticationRoleType deauthenticatedRoleValue);

#endif

Std_ReturnType Dcm_Prv_CheckAccessRights(Dcm_AccessRightsCheckType_ten checkType_en,uint32 allowedRole_u32,
        const Dcm_MsgContextType *pMsgContext ,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);

#endif /* _DCM_PRIV_DSL_AUTHENTICATION_H */
