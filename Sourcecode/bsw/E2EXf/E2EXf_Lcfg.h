


#ifndef E2EXF_LCFG_H
#define E2EXF_LCFG_H

/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/

#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
extern Std_ReturnType E2EXf_Prv_Lcfg_Init(void);

extern uint8 E2EXf_E2EXfRb_Transformer_DrvrSteerActv(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_E2EXfRb_Transformer_LatCtrlModCfmd(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_E2EXfRb_Transformer_PinionSteerAgGroup(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);

extern uint8 E2EXf_Inv_E2EXfRb_Transformer_ADataRawSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_AbsCtrlActv(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_AgDataRawSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyADL3FuncCtrlSts(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyADModeReq(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyDataWithCmpSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyPinionAgReqSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_BrkPedlPsd(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_EngRunngReqByParkAssi(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_EscSt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_IDcDcActLoSide(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_LatCtrlReqSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_PrkgPinionAgReqGroup(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_PtTqAtWhlFrntAct(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_StandStillMgrStsForHld(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_SteerWhlSnsr(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_ULoWarn(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_VehModMngtGlbSafe1(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_VehMtnSt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_VehSpdLgt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlFastSpdSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlRotToothCntr(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlSpdCircumlFrnt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);
extern uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlSpdCircumlRe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength);

#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */

#define E2EXF_START_SEC_CONST_UNSPECIFIED
#include "E2EXf_MemMap.h"
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_ADataRawSafe;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AbsCtrlActv;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AgDataRawSafe;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyADL3FuncCtrlSts;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyADModeReq;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyDataWithCmpSafe;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyPinionAgReqSafe;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_BrkPedlPsd;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_DrvrSteerActv;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_EngRunngReqByParkAssi;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_EscSt;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_IDcDcActLoSide;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlModCfmd;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlReqSafe;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PinionSteerAgGroup;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PrkgPinionAgReqGroup;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PtTqAtWhlFrntAct;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_StandStillMgrStsForHld;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_SteerWhlSnsr;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_ULoWarn;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehModMngtGlbSafe1;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehMtnSt;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehSpdLgt;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlFastSpdSafe;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlRotToothCntr;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlSpdCircumlFrnt;
extern const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlSpdCircumlRe;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_ADataRawSafe;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AbsCtrlActv;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AgDataRawSafe;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyADL3FuncCtrlSts;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyADModeReq;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyDataWithCmpSafe;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyPinionAgReqSafe;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_BrkPedlPsd;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_EngRunngReqByParkAssi;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_EscSt;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_IDcDcActLoSide;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_LatCtrlReqSafe;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_PrkgPinionAgReqGroup;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_PtTqAtWhlFrntAct;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_StandStillMgrStsForHld;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_SteerWhlSnsr;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_ULoWarn;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehModMngtGlbSafe1;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehMtnSt;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehSpdLgt;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlFastSpdSafe;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlRotToothCntr;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlSpdCircumlFrnt;
extern const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlSpdCircumlRe;
#define E2EXF_STOP_SEC_CONST_UNSPECIFIED
#include "E2EXf_MemMap.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */

#define E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "E2EXf_MemMap.h"
/* Profile Protect state holders */
extern E2E_P01ProtectStateType E2EXf_Prv_Protect_State_E2EXfRb_Transformer_DrvrSteerActv;
extern E2E_P01ProtectStateType E2EXf_Prv_Protect_State_E2EXfRb_Transformer_LatCtrlModCfmd;
extern E2E_P01ProtectStateType E2EXf_Prv_Protect_State_E2EXfRb_Transformer_PinionSteerAgGroup;

/* Profile Check state holders */
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_ADataRawSafe;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AbsCtrlActv;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AgDataRawSafe;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADModeReq;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyDataWithCmpSafe;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyPinionAgReqSafe;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_BrkPedlPsd;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_EngRunngReqByParkAssi;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_EscSt;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_IDcDcActLoSide;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_LatCtrlReqSafe;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_StandStillMgrStsForHld;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_SteerWhlSnsr;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_ULoWarn;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehModMngtGlbSafe1;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehMtnSt;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehSpdLgt;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlFastSpdSafe;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlRotToothCntr;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt;
extern E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlRe;

/* Statemachine state holders */
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_ADataRawSafe;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AbsCtrlActv;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AgDataRawSafe;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADModeReq;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyDataWithCmpSafe;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyPinionAgReqSafe;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_BrkPedlPsd;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_EngRunngReqByParkAssi;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_EscSt;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_IDcDcActLoSide;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_LatCtrlReqSafe;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_StandStillMgrStsForHld;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_SteerWhlSnsr;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_ULoWarn;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehModMngtGlbSafe1;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehMtnSt;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehSpdLgt;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlFastSpdSafe;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlRotToothCntr;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt;
extern E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlRe;

/* Statemachine status window buffers */

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_ADataRawSafe[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AbsCtrlActv[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AgDataRawSafe[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyADL3FuncCtrlSts[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyADModeReq[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyDataWithCmpSafe[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyPinionAgReqSafe[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_BrkPedlPsd[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_EngRunngReqByParkAssi[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_EscSt[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_IDcDcActLoSide[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_LatCtrlReqSafe[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_PrkgPinionAgReqGroup[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_PtTqAtWhlFrntAct[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_StandStillMgrStsForHld[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_SteerWhlSnsr[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_ULoWarn[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehModMngtGlbSafe1[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehMtnSt[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehSpdLgt[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlFastSpdSafe[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlRotToothCntr[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlSpdCircumlFrnt[1U];

extern uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlSpdCircumlRe[1U];
#define E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "E2EXf_MemMap.h"

/* E2EXF_LCFG_H */
#endif

