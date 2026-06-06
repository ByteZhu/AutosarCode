
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DCM_LCFG_DSLDSD_H
#define DCM_LCFG_DSLDSD_H



extern Std_ReturnType DcmAppl_UserServiceModeRuleService(Dcm_NegativeResponseCodeType * Nrc_u8, uint8 Sid_u8);
extern Std_ReturnType Dcm_1906_User_Func(Dcm_NegativeResponseCodeType * Nrc_u8, uint8 Sid_u8, uint8 Subfunc_u8);
extern Std_ReturnType DcmAppl_UserSubServiceModeRuleService(Dcm_NegativeResponseCodeType * Nrc_u8, uint8 Sid_u8,uint8 Subfunc_u8);

/* Extern declarations For DcmAppl SessionMode Switch function */
extern void DcmAppl_Switch_DcmDiagnosticSessionControl(Dcm_SesCtrlType SessionMode);
extern void DcmAppl_Switch_DcmExecuteDscReset(uint8 SessionLevel_u8);

/* Extern declarations For DcmAppl ResetMode Switch function */
extern void DcmAppl_Switch_DcmEcuReset(uint8 ResetMode);
extern void DcmAppl_Switch_DcmExecuteReset(void);
extern void DcmAppl_Switch_DcmExecuteEcuReset(uint8 ResetType_u8);
extern void DcmAppl_Switch_DcmBootLoaderReset(void);
extern void DcmAppl_Switch_DcmSysSupplierReset(void);

extern void DcmAppl_Switch_DcmDriveToDriveReset(void);

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

Std_ReturnType Dcm_Prv_DspDiagnosticSessionControl(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspSecurityAccess(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspEcuReset(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspReadDTCInformation(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspClearDiagnosticInformation(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspReadDataByIdentifier(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspWriteDataByIdentifier(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspRoutineControl(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspTesterPresent(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspCommunicationControl(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
Std_ReturnType Dcm_Prv_DspControlDTCSetting(Dcm_SrvOpStatusType OpStatus,Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * dataNegRespCode_u8);

void Dcm_Prv_DspDsc_Init(void);
void Dcm_Prv_DspSeca_Init(void);
void Dcm_Prv_DspEcuReset_Init(void);
void Dcm_Prv_DspReadDTCInfo_Init(void);
void Dcm_Prv_DspRDBI_Init(void);
void Dcm_Prv_DspWDBI_Init(void);
void Dcm_Prv_DspRC_Init(void);
void Dcm_Prv_DspCDTCS_Init(void);


extern boolean Dcm_DcmModeRule_NRC22(uint8 *Nrc_u8);
extern boolean Dcm_DcmModeRule_NRC72(uint8 *Nrc_u8);

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/**********************************************DCM Configurations extern declarations**********************************/


#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
extern const Dcm_DsdConfigType_tst *Dcm_Cfg_Dsd_pcst;
extern const Dcm_DslConfigType_tst *Dcm_Cfg_Dsl_pcst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#endif  /* DCM_LCFG_H */
