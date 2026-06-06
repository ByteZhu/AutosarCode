

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "E2EXf.h"
#include "E2EXf_Prv.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */

#define E2EXF_START_SEC_CONST_UNSPECIFIED
#include "E2EXf_MemMap.h"
/* TRACE[SWS_E2EXf_00126] */
/* Profile 01 configuration structure for E2EXfRb_Transformer_ADataRawSafe */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_ADataRawSafe =
{
     8,     0,     34,     12,     E2E_P01_DATAID_BOTH,     88,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_AbsCtrlActv */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AbsCtrlActv =
{
     8,     0,     3334,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_AgDataRawSafe */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AgDataRawSafe =
{
     8,     0,     35,     12,     E2E_P01_DATAID_BOTH,     64,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_AsyADL3FuncCtrlSts */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyADL3FuncCtrlSts =
{
     8,     0,     3351,     12,     E2E_P01_DATAID_BOTH,     56,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_AsyADModeReq */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyADModeReq =
{
     8,     0,     3352,     12,     E2E_P01_DATAID_BOTH,     32,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_AsyDataWithCmpSafe */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyDataWithCmpSafe =
{
     8,     0,     36,     12,     E2E_P01_DATAID_BOTH,     88,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_AsyPinionAgReqSafe */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_AsyPinionAgReqSafe =
{
     8,     0,     759,     12,     E2E_P01_DATAID_BOTH,     32,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_BrkPedlPsd */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_BrkPedlPsd =
{
     8,     0,     56,     12,     E2E_P01_DATAID_BOTH,     40,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_DrvrSteerActv */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_DrvrSteerActv =
{
     8,     0,     188,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_EngRunngReqByParkAssi */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_EngRunngReqByParkAssi =
{
     8,     0,     15,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_EscSt */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_EscSt =
{
     8,     0,     127,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt =
{
     8,     0,     6782,     12,     E2E_P01_DATAID_BOTH,     48,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_IDcDcActLoSide */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_IDcDcActLoSide =
{
     8,     0,     20,     12,     E2E_P01_DATAID_BOTH,     32,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_LatCtrlModCfmd */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlModCfmd =
{
     8,     0,     58,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_LatCtrlReqSafe */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlReqSafe =
{
     8,     0,     48,     12,     E2E_P01_DATAID_BOTH,     48,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_PinionSteerAgGroup */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PinionSteerAgGroup =
{
     8,     0,     1037,     12,     E2E_P01_DATAID_BOTH,     88,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_PrkgPinionAgReqGroup */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PrkgPinionAgReqGroup =
{
     8,     0,     433,     12,     E2E_P01_DATAID_BOTH,     40,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_PtTqAtWhlFrntAct */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PtTqAtWhlFrntAct =
{
     8,     0,     78,     12,     E2E_P01_DATAID_BOTH,     72,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_StandStillMgrStsForHld */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_StandStillMgrStsForHld =
{
     8,     0,     1096,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_SteerWhlSnsr */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_SteerWhlSnsr =
{
     8,     0,     51,     12,     E2E_P01_DATAID_BOTH,     56,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_ULoWarn */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_ULoWarn =
{
     8,     0,     67,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_VehModMngtGlbSafe1 */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehModMngtGlbSafe1 =
{
     8,     0,     116,     12,     E2E_P01_DATAID_BOTH,     80,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_VehMtnSt */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehMtnSt =
{
     8,     0,     54,     12,     E2E_P01_DATAID_BOTH,     24,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_VehSpdLgt */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_VehSpdLgt =
{
     8,     0,     55,     12,     E2E_P01_DATAID_BOTH,     40,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_WhlFastSpdSafe */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlFastSpdSafe =
{
     8,     0,     6514,     12,     E2E_P01_DATAID_BOTH,     40,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_WhlRotToothCntr */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlRotToothCntr =
{
     8,     0,     6600,     12,     E2E_P01_DATAID_BOTH,     48,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_WhlSpdCircumlFrnt */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlSpdCircumlFrnt =
{
     8,     0,     111,     12,     E2E_P01_DATAID_BOTH,     64,     2,     14,     1
};

/* Profile 01 configuration structure for E2EXfRb_Transformer_WhlSpdCircumlRe */
const E2E_P01ConfigType E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_WhlSpdCircumlRe =
{
     8,     0,     124,     12,     E2E_P01_DATAID_BOTH,     64,     2,     14,     1
};

/* TRACE[SWS_E2EXf_00126] */
/* Profile SM configuration structure for E2EXfRb_Transformer_ADataRawSafe */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_ADataRawSafe =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_AbsCtrlActv */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AbsCtrlActv =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_AgDataRawSafe */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AgDataRawSafe =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_AsyADL3FuncCtrlSts */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyADL3FuncCtrlSts =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_AsyADModeReq */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyADModeReq =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_AsyDataWithCmpSafe */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyDataWithCmpSafe =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_AsyPinionAgReqSafe */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyPinionAgReqSafe =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_BrkPedlPsd */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_BrkPedlPsd =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_EngRunngReqByParkAssi */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_EngRunngReqByParkAssi =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_EscSt */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_EscSt =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_IDcDcActLoSide */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_IDcDcActLoSide =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_LatCtrlReqSafe */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_LatCtrlReqSafe =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_PrkgPinionAgReqGroup */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_PrkgPinionAgReqGroup =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_PtTqAtWhlFrntAct */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_PtTqAtWhlFrntAct =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_StandStillMgrStsForHld */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_StandStillMgrStsForHld =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_SteerWhlSnsr */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_SteerWhlSnsr =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_ULoWarn */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_ULoWarn =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_VehModMngtGlbSafe1 */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehModMngtGlbSafe1 =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_VehMtnSt */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehMtnSt =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_VehSpdLgt */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehSpdLgt =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_WhlFastSpdSafe */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlFastSpdSafe =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_WhlRotToothCntr */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlRotToothCntr =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_WhlSpdCircumlFrnt */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlSpdCircumlFrnt =
{
    1,    0,    0,    0,    0,    0,    0
};

/* Profile SM configuration structure for E2EXfRb_Transformer_WhlSpdCircumlRe */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
const E2E_SMConfigType E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlSpdCircumlRe =
{
    1,    0,    0,    0,    0,    0,    0
};
#define E2EXF_STOP_SEC_CONST_UNSPECIFIED
#include "E2EXf_MemMap.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */

#define E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "E2EXf_MemMap.h"
/* TRACE[SWS_E2EXf_00125] */
/* Profile Protect state holders */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
E2E_P01ProtectStateType E2EXf_Prv_Protect_State_E2EXfRb_Transformer_DrvrSteerActv;
E2E_P01ProtectStateType E2EXf_Prv_Protect_State_E2EXfRb_Transformer_LatCtrlModCfmd;
E2E_P01ProtectStateType E2EXf_Prv_Protect_State_E2EXfRb_Transformer_PinionSteerAgGroup;

/* TRACE[SWS_E2EXf_00125] */
/* Profile Check state holders */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_ADataRawSafe;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AbsCtrlActv;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AgDataRawSafe;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADModeReq;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyDataWithCmpSafe;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyPinionAgReqSafe;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_BrkPedlPsd;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_EngRunngReqByParkAssi;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_EscSt;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_IDcDcActLoSide;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_LatCtrlReqSafe;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_StandStillMgrStsForHld;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_SteerWhlSnsr;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_ULoWarn;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehModMngtGlbSafe1;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehMtnSt;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehSpdLgt;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlFastSpdSafe;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlRotToothCntr;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt;
E2E_P01CheckStateType E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlRe;

/* TRACE[SWS_E2EXf_00125] */
/* Statemachine state holders */
/* MR12 RULE 8.7 VIOLATION: The object is only referenced in the translation unit where it is defined. Accepted for better generated code structure */
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_ADataRawSafe;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AbsCtrlActv;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AgDataRawSafe;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADModeReq;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyDataWithCmpSafe;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyPinionAgReqSafe;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_BrkPedlPsd;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_EngRunngReqByParkAssi;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_EscSt;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_IDcDcActLoSide;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_LatCtrlReqSafe;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_StandStillMgrStsForHld;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_SteerWhlSnsr;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_ULoWarn;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehModMngtGlbSafe1;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehMtnSt;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehSpdLgt;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlFastSpdSafe;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlRotToothCntr;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt;
E2E_SMCheckStateType E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlRe;

/* TRACE[SWS_E2EXf_00125] */
/* Statemachine status window buffers */

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_ADataRawSafe[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AbsCtrlActv[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AgDataRawSafe[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyADL3FuncCtrlSts[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyADModeReq[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyDataWithCmpSafe[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyPinionAgReqSafe[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_BrkPedlPsd[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_EngRunngReqByParkAssi[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_EscSt[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_IDcDcActLoSide[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_LatCtrlReqSafe[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_PrkgPinionAgReqGroup[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_PtTqAtWhlFrntAct[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_StandStillMgrStsForHld[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_SteerWhlSnsr[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_ULoWarn[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehModMngtGlbSafe1[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehMtnSt[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehSpdLgt[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlFastSpdSafe[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlRotToothCntr[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlSpdCircumlFrnt[1U];

uint8 E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlSpdCircumlRe[1U];
#define E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "E2EXf_MemMap.h"

/*
 **********************************************************************************************************************
 * Implementations
 **********************************************************************************************************************
 */

/**
***********************************************************************************************************************
* E2EXf_<transformerId>
*
* \brief Protects the array/buffer to be transmitted, using E2E protection
*
* Description:
* - Protects the array/buffer to be transmitted, using E2E protection
*
* Restrictions:
*   -
*
* Dependencies:
*   -
*
* Resources:
*   -
*
* \param   buffer                       This argument is only an INOUT argument for E2E transformers which are configured 
*                                       for in-place transformation. This is the buffer where the E2E transformer places 
*                                       its output data. If the E2E transformer is configured for in-place transformation, 
*                                       it also contains its input data. If the E2E transformer uses in-place transformation 
*                                       and has a headerLength different from 0, the output data of the previous transformer 
*                                       begin at position headerLength. This argument is only an OUT argument for E2E 
*                                       transformers configured for out-of-place transformation.     
*     
* \param   bufferLength                 Used length of the buffer (output data length in bytes)
*
* \param   [inputBuffer]                This argument only exists for E2E transformers configured for out-of-place 
*                                       transformation. This argument holds the E2E transformer's input data 
*                                       If executeDespiteDataUnavailability is set to true and the transformer is 
*                                       executed without valid input data and the length will be equal to 0.
*
* \param   inputBufferLength            This argument holds the length of the E2E transformer's input data length. (in bytes)
*
* \return  uint8                        Status of the function execution. 
*
***********************************************************************************************************************
*/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
/* TRACE[SWS_E2EXf_00032] , TRACE[SWS_E2EXf_00020] */
uint8 E2EXf_E2EXfRb_Transformer_DrvrSteerActv(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    Std_ReturnType protect_en = E2E_E_INTERR;


    //Check if E2EXf is initialized
    /* TRACE[SWS_E2EXf_00133] */
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        /* TRACE[SWS_E2EXf_00106] */
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           //Check is optimized because Upper Header Size is 0
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            //Perform transformation
            //[SWS_E2EXf_00109]|0
            //[SWS_E2EXf_00109][SWS_E2EXf_00115]
            E2EXf_Prv_MemCopyLeft(&buffer[2U], (const uint8*) &inputBuffer[0U], (uint32)(inputBufferLength - 0U));
            //Update buffer length
            //[SWS_E2EXf_00111]
            (*bufferLength) = inputBufferLength + 2U;
            //Check for correct datalength
            //[SWS_E2EXf_00139]|1
            if(E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_DrvrSteerActv.DataLength == ((*bufferLength) * 8U))
            {
                //[SWS_E2EXf_00155]|1
                buffer[1U] |= E2EXF_MASK_H_NIBBLE;
                //Perform E2E Protect operation
                //[SWS_E2EXf_00107]|1
                protect_en = E2E_P01Protect(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_DrvrSteerActv, 
                                            &E2EXf_Prv_Protect_State_E2EXfRb_Transformer_DrvrSteerActv, 
                                            &buffer[0U]);
                //Check Protect status
                //[SWS_E2EXf_00018]
                if(E2E_E_OK == protect_en)
                {
                    error_en = E_OK;
                }
            }
        }
    }    

    
    //[SWS_E2EXf_00122]
    return error_en;
}


uint8 E2EXf_E2EXfRb_Transformer_LatCtrlModCfmd(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    Std_ReturnType protect_en = E2E_E_INTERR;


    //Check if E2EXf is initialized
    /* TRACE[SWS_E2EXf_00133] */
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        /* TRACE[SWS_E2EXf_00106] */
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           //Check is optimized because Upper Header Size is 0
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            //Perform transformation
            //[SWS_E2EXf_00109]|0
            //[SWS_E2EXf_00109][SWS_E2EXf_00115]
            E2EXf_Prv_MemCopyLeft(&buffer[2U], (const uint8*) &inputBuffer[0U], (uint32)(inputBufferLength - 0U));
            //Update buffer length
            //[SWS_E2EXf_00111]
            (*bufferLength) = inputBufferLength + 2U;
            //Check for correct datalength
            //[SWS_E2EXf_00139]|1
            if(E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlModCfmd.DataLength == ((*bufferLength) * 8U))
            {
                //[SWS_E2EXf_00155]|1
                buffer[1U] |= E2EXF_MASK_H_NIBBLE;
                //Perform E2E Protect operation
                //[SWS_E2EXf_00107]|1
                protect_en = E2E_P01Protect(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_LatCtrlModCfmd, 
                                            &E2EXf_Prv_Protect_State_E2EXfRb_Transformer_LatCtrlModCfmd, 
                                            &buffer[0U]);
                //Check Protect status
                //[SWS_E2EXf_00018]
                if(E2E_E_OK == protect_en)
                {
                    error_en = E_OK;
                }
            }
        }
    }    

    
    //[SWS_E2EXf_00122]
    return error_en;
}


uint8 E2EXf_E2EXfRb_Transformer_PinionSteerAgGroup(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    Std_ReturnType protect_en = E2E_E_INTERR;


    //Check if E2EXf is initialized
    /* TRACE[SWS_E2EXf_00133] */
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        /* TRACE[SWS_E2EXf_00106] */
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           //Check is optimized because Upper Header Size is 0
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            //Perform transformation
            //[SWS_E2EXf_00109]|0
            //[SWS_E2EXf_00109][SWS_E2EXf_00115]
            E2EXf_Prv_MemCopyLeft(&buffer[2U], (const uint8*) &inputBuffer[0U], (uint32)(inputBufferLength - 0U));
            //Update buffer length
            //[SWS_E2EXf_00111]
            (*bufferLength) = inputBufferLength + 2U;
            //Check for correct datalength
            //[SWS_E2EXf_00139]|1
            if(E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PinionSteerAgGroup.DataLength == ((*bufferLength) * 8U))
            {
                //[SWS_E2EXf_00155]|1
                buffer[1U] |= E2EXF_MASK_H_NIBBLE;
                //Perform E2E Protect operation
                //[SWS_E2EXf_00107]|1
                protect_en = E2E_P01Protect(&E2EXf_Prv_Profile_Config_E2EXfRb_Transformer_PinionSteerAgGroup, 
                                            &E2EXf_Prv_Protect_State_E2EXfRb_Transformer_PinionSteerAgGroup, 
                                            &buffer[0U]);
                //Check Protect status
                //[SWS_E2EXf_00018]
                if(E2E_E_OK == protect_en)
                {
                    error_en = E_OK;
                }
            }
        }
    }    

    
    //[SWS_E2EXf_00122]
    return error_en;
}

#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/**
***********************************************************************************************************************
* E2EXf_Inv_<transformerId>
*
* \brief Checks the received data. If the data can be used by the caller, then the function returns E_OK.
*
* Description:
* - Checks the received data. If the data can be used by the caller, then the function returns E_OK.
*
* Restrictions:
*   -
*
* Dependencies:
*   -
*
* Resources:
*   -
*
* \param   buffer                       This argument is only an INOUT argument for E2E transformers, which are configured 
*                                       for in-place transformation. It is the buffer where the input data are placed by 
*                                       the caller and which is filled by the transformer with its output. This argument is 
*                                       only an OUT argument for E2E transformers configured for out-of-place transformation. 
*                                       It is the buffer allocated by the RTE, where the transformed data has to be stored 
*                                       by the transformer  
*     
* \param   bufferLength                 Used length of the output buffer (output data length in bytes)
*
* \param   [inputBuffer]                This argument only exists for E2E transformers configured for out-of-place 
*                                       transformation. It holds the input data for the transformer. If 
*                                       executeDespiteDataUnavailability is set to true, Rte will hand over a NULL_PTR pointer 
*                                       to the transformer.
*
* \param   inputBufferLength            This argument holds the length of the E2E transformer's input data length. (in bytes)
*
* \return  uint8                        The high nibble represents the state of the E2E state machine, the low nibble 
*                                       represents the status of the last E2E check.
*
***********************************************************************************************************************
*/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
//[SWS_E2EXf_00025][SWS_E2EXf_00034]
uint8 E2EXf_Inv_E2EXfRb_Transformer_ADataRawSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_AbsCtrlActv(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_AgDataRawSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyADL3FuncCtrlSts(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyADModeReq(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyDataWithCmpSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_AsyPinionAgReqSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_BrkPedlPsd(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_EngRunngReqByParkAssi(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_EscSt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_IDcDcActLoSide(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_LatCtrlReqSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_PrkgPinionAgReqGroup(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_PtTqAtWhlFrntAct(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_StandStillMgrStsForHld(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_SteerWhlSnsr(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_ULoWarn(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_VehModMngtGlbSafe1(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_VehMtnSt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_VehSpdLgt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlFastSpdSafe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlRotToothCntr(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlSpdCircumlFrnt(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}

uint8 E2EXf_Inv_E2EXfRb_Transformer_WhlSpdCircumlRe(uint8* buffer, uint16* bufferLength, const uint8* inputBuffer, uint16 inputBufferLength)
{
    uint8 error_en = E_SAFETY_HARD_RUNTIMEERROR;
    //[SWS_E2EXf_00154]|0

    //Check if E2EXf is initialized
    //[SWS_E2EXf_00133]
    if (TRUE == E2EXf_Prv_Initialized_b)
    {
        //[SWS_E2EXf_00103]
        if(((NULL_PTR == inputBuffer) && (inputBufferLength != 0U)) ||
           ((inputBuffer != NULL_PTR) && (inputBufferLength < 2U)) ||
           (NULL_PTR == buffer) ||
           (NULL_PTR == bufferLength))
        {
            //Status already initialized with Hard Runtime error
            //Nothing to do
        }
        else
        {
            {
                if(0U == inputBufferLength)
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = 0U;
                }
                else
                {
                    //E2E Check related operatios are disabled
                    //[SWS_E2EXf_00124][SWS_E2EXf_00123]|0
                    //[SWS_E2EXf_00140][SWS_E2EXf_00141]|0
                    //Update buffer length
                    //[SWS_E2EXf_00114]
                    (*bufferLength) = inputBufferLength - 2U;
                }
                //E2E Check related operatios are disabled
                //[SWS_E2EXf_00104][SWS_E2EXf_00028][SWS_E2EXf_00029]|0
                //Perform inverse transformation
                //Only when valid buffer pointer received
                if(inputBuffer != NULL_PTR)
                {
                    //[SWS_E2EXf_00113]|0
                    //[SWS_E2EXf_00116]
                    E2EXf_Prv_MemCopyLeft(&buffer[0U], (const uint8*) &inputBuffer[2U], (uint32)(inputBufferLength - 2U));
                }
                //Update execution status
                //[SWS_E2EXf_00027]|0
                error_en = E_OK;
            }
        }
    }

    //[SWS_E2EXf_00009]
    return error_en;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

/**
*******************************************************************************************************************
* E2EXf_Prv_Lcfg_Init
*
* \brief Initializes the state of the E2E Transformer when Link time configuration used
*
* Description: Initializes the state of the E2E Transformer. The main part of it is the initialization of 
*              the E2E library state structures, which is done by calling all init-functions from E2E library.
* 
* Restrictions:
*   -
*
* Dependencies:
*   -
*
* Resources:
*   -
*
* \param   void
* \return  void
*
*******************************************************************************************************************
*/
#define E2EXF_START_SEC_CODE
#include "E2EXf_MemMap.h"
//[SWS_E2EXf_00021]
Std_ReturnType E2EXf_Prv_Lcfg_Init(void)
{
    Std_ReturnType return_en = E_OK;

    /* Init Profile Protect state holders */
    return_en |= E2E_P01ProtectInit(&E2EXf_Prv_Protect_State_E2EXfRb_Transformer_DrvrSteerActv);
    return_en |= E2E_P01ProtectInit(&E2EXf_Prv_Protect_State_E2EXfRb_Transformer_LatCtrlModCfmd);
    return_en |= E2E_P01ProtectInit(&E2EXf_Prv_Protect_State_E2EXfRb_Transformer_PinionSteerAgGroup);

    /* Init Profile Check state holders */
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_ADataRawSafe);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_AbsCtrlActv);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_AgDataRawSafe);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyADModeReq);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyDataWithCmpSafe);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_AsyPinionAgReqSafe);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_BrkPedlPsd);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_EngRunngReqByParkAssi);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_EscSt);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_IDcDcActLoSide);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_LatCtrlReqSafe);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_StandStillMgrStsForHld);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_SteerWhlSnsr);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_ULoWarn);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehModMngtGlbSafe1);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehMtnSt);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_VehSpdLgt);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlFastSpdSafe);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlRotToothCntr);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt);
    return_en |= E2E_P01CheckInit(&E2EXf_Prv_Check_State_E2EXfRb_Transformer_WhlSpdCircumlRe);

    /* Assign window buffers to statemachine state structures */
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_ADataRawSafe.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_ADataRawSafe[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_AbsCtrlActv.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AbsCtrlActv[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_AgDataRawSafe.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AgDataRawSafe[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyADL3FuncCtrlSts[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADModeReq.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyADModeReq[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyDataWithCmpSafe.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyDataWithCmpSafe[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyPinionAgReqSafe.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_AsyPinionAgReqSafe[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_BrkPedlPsd.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_BrkPedlPsd[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_EngRunngReqByParkAssi.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_EngRunngReqByParkAssi[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_EscSt.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_EscSt[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_IDcDcActLoSide.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_IDcDcActLoSide[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_LatCtrlReqSafe.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_LatCtrlReqSafe[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_PrkgPinionAgReqGroup[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_PtTqAtWhlFrntAct[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_StandStillMgrStsForHld.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_StandStillMgrStsForHld[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_SteerWhlSnsr.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_SteerWhlSnsr[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_ULoWarn.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_ULoWarn[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehModMngtGlbSafe1.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehModMngtGlbSafe1[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehMtnSt.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehMtnSt[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehSpdLgt.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_VehSpdLgt[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlFastSpdSafe.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlFastSpdSafe[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlRotToothCntr.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlRotToothCntr[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlSpdCircumlFrnt[0U];
    E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlRe.ProfileStatusWindow = (uint8*)&E2EXf_Prv_SM_Window_E2EXfRb_Transformer_WhlSpdCircumlRe[0U];

    /* Init Statemachine state holders */
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_ADataRawSafe, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_ADataRawSafe);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_AbsCtrlActv, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AbsCtrlActv);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_AgDataRawSafe, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AgDataRawSafe);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADL3FuncCtrlSts, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyADL3FuncCtrlSts);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyADModeReq, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyADModeReq);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyDataWithCmpSafe, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyDataWithCmpSafe);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_AsyPinionAgReqSafe, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_AsyPinionAgReqSafe);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_BrkPedlPsd, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_BrkPedlPsd);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_EngRunngReqByParkAssi, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_EngRunngReqByParkAssi);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_EscSt, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_EscSt);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_GVMCSteerWhlAgReqFrnt);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_IDcDcActLoSide, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_IDcDcActLoSide);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_LatCtrlReqSafe, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_LatCtrlReqSafe);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_PrkgPinionAgReqGroup, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_PrkgPinionAgReqGroup);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_PtTqAtWhlFrntAct, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_PtTqAtWhlFrntAct);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_StandStillMgrStsForHld, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_StandStillMgrStsForHld);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_SteerWhlSnsr, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_SteerWhlSnsr);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_ULoWarn, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_ULoWarn);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehModMngtGlbSafe1, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehModMngtGlbSafe1);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehMtnSt, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehMtnSt);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_VehSpdLgt, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_VehSpdLgt);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlFastSpdSafe, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlFastSpdSafe);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlRotToothCntr, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlRotToothCntr);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlFrnt, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlSpdCircumlFrnt);
    return_en |= E2E_SMCheckInit(&E2EXf_Prv_SM_State_E2EXfRb_Transformer_WhlSpdCircumlRe, &E2EXf_Prv_SM_Config_E2EXfRb_Transformer_WhlSpdCircumlRe);

    //Check if there were any kind of error
    if(return_en != 0U)
    {
        //Then return own error code 
        return_en = E_SAFETY_HARD_RUNTIMEERROR;
    }
    //Else E_OK value returned
    return return_en;
}
#define E2EXF_STOP_SEC_CODE
#include "E2EXf_MemMap.h"

