
#ifndef DCM_LCFG_DSPUDS_H
#define DCM_LCFG_DSPUDS_H

/*
 ***************************************************************************************************
 *    DCM Appl API Prototyes generated from configuration
 ***************************************************************************************************
*/
#define DCM_START_SEC_CODE 
#include "Dcm_MemMap.h"
extern Std_ReturnType Dcm_DidServices_F186_ReadData(uint8 * adrData_pu8);
#define DCM_STOP_SEC_CODE 
#include "Dcm_MemMap.h"



#if (DCM_CFG_DSP_RDTCUSERDEFINEMEM_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"
extern const Dcm_DspRDTCUserDefinedFaultMemmoryType_tst Dcm_DspRDTCUserDefinedFaultMemory_ast[DCM_CFG_RDTC_NUM_USER_DEFINED_FAULT_MEMORY];
#define DCM_STOP_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_CODE 
#include "Dcm_MemMap.h"






    
                
    
    
    



/***Extern declarations to obtain NRC value from the application in case of E_NOT_OK return from ReadData API ***/
extern Std_ReturnType DcmAppl_DcmReadDataNRC(uint16 Did,uint32 DidSignalPosn,Dcm_NegativeResponseCodeType * ErrorCode);
/***Extern declarations for XXX_ReadData of type USE_DATA_ASYNCH_FNC ***/
extern Std_ReturnType DID_D01C_ReadFnc (Dcm_OpStatusType OpStatus,uint8 * Data);


 /***Extern declarations for XXX_ReadData of type USE_DATA_SYNCH_FNC ***/
extern Std_ReturnType DID_2145_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_2146_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_2147_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_217D_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_217E_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_21AB_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_21AC_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_21AD_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_2221_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_3012_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_3017_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_302C_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_330C_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D005_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D0B5_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D118_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D11C_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D134_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D900_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D901_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D902_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D904_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D905_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D906_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D908_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D909_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_D90A_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_DD00_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_DD01_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_DD02_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_DD06_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_DD07_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_DD0A_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_DD0C_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_E103_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F120_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F121_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F125_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F126_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F12A_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F12B_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F12E_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F186_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F18A_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F18C_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F1A0_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F1A1_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F1A5_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F1AA_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F1AB_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F1AE_ReadFnc (uint8 * Data);
extern Std_ReturnType DID_F1D0_ReadFnc (uint8 * Data);

 
 




/***Extern declarations for XXX_WriteData of type USE_DATA_ASYNCH_FNC  and of fixed length ***/
extern Std_ReturnType DID_D01C_WriteFnc (const uint8 * Data,Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode);














/***Routine control Appl functions***/






/*** Extern declaration for DcmDspRoutine_0206_Start ***/
extern Std_ReturnType DcmDspRoutine_0206_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_307B_Start ***/
extern Std_ReturnType DcmDspRoutine_307B_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_3080_Start ***/
extern Std_ReturnType DcmDspRoutine_3080_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_3082_Start ***/
extern Std_ReturnType DcmDspRoutine_3082_Start(
const uint8 *  dataIn1,
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_3083_Start ***/
extern Std_ReturnType DcmDspRoutine_3083_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_3088_Start ***/
extern Std_ReturnType DcmDspRoutine_3088_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_3089_Start ***/
extern Std_ReturnType DcmDspRoutine_3089_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_308A_Start ***/
extern Std_ReturnType DcmDspRoutine_308A_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_308B_Start ***/
extern Std_ReturnType DcmDspRoutine_308B_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);
/*** Extern declaration for DcmDspRoutine_30A8_Start ***/
extern Std_ReturnType DcmDspRoutine_30A8_Start(
                         Dcm_OpStatusType OpStatus,
                         uint8 * dataOut1,
                          Dcm_NegativeResponseCodeType * ErrorCode);

/***Routine control Appl functions for Range Routine***/






/***Seca dcmDspSecurityGetSeedFnc functions with Useport  USE_ASYNCH_FNC ***/

// prototypes for flexible length configuration

// prototypes for fixed length configuration
extern Std_ReturnType GetSeed_L1(Dcm_SecLevelType SecLevel_u8,uint32 Seedlen_u32,uint32 AccDataRecsize_u32,uint8 * SecurityAccessDataRecord,uint8 * Seed,Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode);


/***Seca dcmDspSecurityCompareKeyFnc functions with Useport  USE_ASYNCH_FNC ***/
extern Std_ReturnType CompareKey_L1(uint32 KeyLen_32,const uint8 * Key,Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode);



#define DCM_STOP_SEC_CODE 
#include "Dcm_MemMap.h"





extern Std_ReturnType DcmAppl_UserDIDModeRuleService(Dcm_NegativeResponseCodeType * Nrc_u8, uint16 did_u16,Dcm_Direction_t dataDirection_en);
extern Std_ReturnType DcmAppl_UserRIDModeRuleService(Dcm_NegativeResponseCodeType * Nrc_u8, uint16 rid_u16, uint8 subfunction_u8);
extern Std_ReturnType DcmAppl_UserCommCtrlReEnableModeRuleService(void);
extern Std_ReturnType DcmAppl_UserDTCSettingEnableModeRuleService(void);


#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"

#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"

#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"

#if (DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF)
#if(DCM_CFG_NUM_TOTAL_ROUTINES != 0u)
#define DCM_START_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"
#if(DCM_CFG_NUM_NORMAL_ROUTINES != 0u)
extern const Dcm_NormalRoutineConfigType_tst Dcm_Cfg_NormalRoutineConfig_cast[];
#endif
#if(DCM_CFG_NUM_RANGE_ROUTINES != 0u)
extern const Dcm_RangeRoutineConfigType_tst Dcm_Cfg_RangeRoutineConfig_cast[];
#endif
extern const Dcm_RoutineExtendedConfigType_tst Dcm_Cfg_RoutineExtendedConfig_cast[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"
#endif

extern uint32 Dcm_RCGetDataOut ( uint8 dataSigType_en, uint16 idxDataOut_u16 );
extern void Dcm_RCSetDataIn ( uint8 dataSigType_en, uint16 idxDataIn_u16, uint32 dataSigVal_u32);



/* Generated Out Buffers for RoutineControl service -> Array Data Types */

#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
extern sint16 Dcm_RCDataOutN_as16[];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"
extern sint32 Dcm_RCDataOutN_as32[];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
extern sint8 Dcm_RCDataOutN_as8[];
#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"
extern uint32 Dcm_RCDataOutN_au32[];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
extern uint16 Dcm_RCDataOutN_au16[];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
extern uint8 Dcm_RCDataOutN_au8[];
#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"


/* Generated In Buffers for RoutineControl service -> Array Data Types */

#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
extern sint16 Dcm_RCDataInN_as16[];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"
extern sint32 Dcm_RCDataInN_as32[];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
extern sint8 Dcm_RCDataInN_as8[];
#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
extern uint32 Dcm_RCDataInN_au32[];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
extern uint16 Dcm_RCDataInN_au16[];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
extern uint8 Dcm_RCDataInN_au8[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
extern uint8 Dcm_RCDataInVar_au8 [];
#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
extern uint16 Dcm_RCDataVarLength_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"

#endif
#endif /* DCM_LCFG_DSPUDS_H */
