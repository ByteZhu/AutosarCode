

#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "SchM_Dcm.h"
#include "Rte_Dcm.h"
#include "NvM.h"
#include "ComM_Dcm.h"




#include "DcmDspUds_Rdtc_Priv.h"

#include "DcmDspUds_Er_Prot.h"



#include "DcmDspUds_Cdtcs_Prot.h"



#include "Dcm_Prv.h"




/**
 ***************************************************************************************************
            Session Control (DSC) Service
 ***************************************************************************************************
*/
/* Initialization of the parameters for the supported sessions */
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
const Dcm_Dsp_Session_t Dcm_Dsp_Session[DCM_CFG_DSP_NUMSESSIONS] =
{

   /* session configuration for DEFAULT_SESSION*/
   {
        50000,                /* P2 Max time in us */
        5000000,                /* P2* Max time in us */
        0x1,                /* Session ID */
        RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
        DCM_NO_BOOT            /* Diagnostic session used for jump to Bootloader */
    },

   /* session configuration for PROGRAMMING_SESSION*/
   {
        25000,                /* P2 Max time in us */
        5000000,                /* P2* Max time in us */
        0x2,                /* Session ID */
        RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
        DCM_SYS_BOOT            /* Diagnostic session used for jump to Bootloader */
    },

   /* session configuration for EXTENDED_DIAGNOSTIC_SESSION*/
   {
        50000,                /* P2 Max time in us */
        5000000,                /* P2* Max time in us */
        0x3,                /* Session ID */
        RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
        DCM_NO_BOOT            /* Diagnostic session used for jump to Bootloader */
    }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"





/**
 ***************************************************************************************************
            Security Access (SECA) Service
 ***************************************************************************************************
*/
/* Initialization of the parameters for the supported security */
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
const Dcm_Dsp_Security_t Dcm_Dsp_Security[DCM_CFG_DSP_NUMSECURITY] =
{
   /* security configuration for DCM_SEC_LEV_L1*/
   {
   
        0x00u,          /* Delay timer on Power On in DcmTaskTime Counts*/   

        10000,            /* Delay time after failed security access in DcmTaskTime Counts */

        /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
        (void*)    &GetSeed_L1, /* Function for the GetSeed Function */
        /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
        (void*)    &CompareKey_L1, /* Function for the Compare Key Function */
        0x3,         /* Security Level */
        16,            /* Security Seed size */
        16,            /* Security Key size */
        2,            /* Number of failed security access after which delay time is active */
        0,            /* Number of failed security access after which security is locked */
        0,            /* Size of the Access Data Record in Seed Request */
        USE_ASYNCH_FNC,                          FALSE /* Flexible length handling is not needed for this security level */
    }

};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


/* this is the array contains the supported security level in this ECU                       */
/* security levels are configured here (eg: DCM_SEC_LEV_LOCKED =0x00)                        */
/* number of security levels here is one more than in SECA service                           */
/* this lookup table is used to calculate the bit mask from security level                   */
/* this ids are always in ascending order                                                    */
/* Allowed range of security levels are 0x00,0x01,0x02,.....0x3F                             */
#define DCM_START_SEC_CONST_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
static const uint8 Dcm_Dsld_supported_security_acu8[]= {    0x0,    0x3};
#define DCM_STOP_SEC_CONST_8  /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"















#if (DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF)
/**
 ***************************************************************************************************
            Routine control (RC) service - start
 ***************************************************************************************************
 */
#define DCM_RC_INVLDSIGINDEX        0u




#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
sint16 Dcm_RCDataOutN_as16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"




#define DCM_START_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"
sint32 Dcm_RCDataOutN_as32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
sint8 Dcm_RCDataOutN_as8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"




#define DCM_START_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"
uint32 Dcm_RCDataOutN_au32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
uint16 Dcm_RCDataOutN_au16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"



#define RID_0206_CheckProgrammingPreConditions_DcmDspStartRoutineOutSignal_0_StrtOut  0u
#define RID_307B_HandwheelAnglerimSet_DcmDspStartRoutineOutSignal_0_StrtOut  2u
#define RID_3080_HandwheelAngleTrimClear_DcmDspStartRoutineOutSignal_0_StrtOut  3u
#define RID_3082_CentreFindingAlgorithm_DcmDspStartRoutineOutSignal_0_StrtOut  4u
#define RID_3083_PullDriftCompensationClear_DcmDspStartRoutineOutSignal_0_StrtOut  5u
#define RID_3088_ResetRackEndLearning_DcmDspStartRoutineOutSignal_0_StrtOut  6u
#define RID_3089_ClearFrictionDetectionFault_DcmDspStartRoutineOutSignal_0_StrtOut  7u
#define RID_308A_ResetFrictionDetectionFault_DcmDspStartRoutineOutSignal_0_StrtOut  8u
#define RID_308B_ResetPSCMSteeringAnle_DcmDspStartRoutineOutSignal_0_StrtOut  9u
#define RID_30A8_ResetLimpHomeTimer_DcmDspStartRoutineOutSignal_0_StrtOut  10u
#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
uint8 Dcm_RCDataOutN_au8[11];
#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"






#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
sint16 Dcm_RCDataInN_as16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"
sint32 Dcm_RCDataInN_as32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
sint8 Dcm_RCDataInN_as8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_32
#include "Dcm_MemMap.h"
uint32 Dcm_RCDataInN_au32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
uint16 Dcm_RCDataInN_au16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
uint8 Dcm_RCDataInVar_au8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"
uint16 Dcm_RCDataVarLength_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16 
#include "Dcm_MemMap.h"


#define RID_3082_CentreFindingAlgorithm_DcmDspStartRoutineInSignal_0_StrtIn  0u

#define DCM_START_SEC_VAR_CLEARED_8 
#include "Dcm_MemMap.h"
uint8 Dcm_RCDataInN_au8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE 
#include "Dcm_MemMap.h"

uint32 Dcm_RCGetDataOut ( uint8 dataSigType_en, uint16 idxDataOut_u16 )
{
    uint32 dataSigVal_u32;
   
    
    {
        (void)dataSigType_en;
        (void)idxDataOut_u16;
        dataSigVal_u32 = 0;
    }

    return (dataSigVal_u32);
}


void Dcm_RCSetDataIn ( uint8 dataSigType_en, uint16 idxDataIn_u16, uint32 dataSigVal_u32)
{

    
    {
        (void)dataSigVal_u32;
        (void)idxDataIn_u16;
        (void)dataSigType_en;
    }
}

#define DCM_STOP_SEC_CODE 
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"
const Dcm_NormalRoutineConfigType_tst Dcm_Cfg_NormalRoutineConfig_cast[DCM_CFG_NUM_NORMAL_ROUTINES]=
{

    /* RID_0206_CheckProgrammingPreConditions */
    {
        0x206,  /* dataRId_u16 */
        
        0,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_307B_HandwheelAnglerimSet */
    {
        0x307b,  /* dataRId_u16 */
        
        1,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_3080_HandwheelAngleTrimClear */
    {
        0x3080,  /* dataRId_u16 */
        
        2,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_3082_CentreFindingAlgorithm */
    {
        0x3082,  /* dataRId_u16 */
        
        3,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_3083_PullDriftCompensationClear */
    {
        0x3083,  /* dataRId_u16 */
        
        4,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_3088_ResetRackEndLearning */
    {
        0x3088,  /* dataRId_u16 */
        
        5,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_3089_ClearFrictionDetectionFault */
    {
        0x3089,  /* dataRId_u16 */
        
        6,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_308A_ResetFrictionDetectionFault */
    {
        0x308a,  /* dataRId_u16 */
        
        7,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_308B_ResetPSCMSteeringAnle */
    {
        0x308b,  /* dataRId_u16 */
        
        8,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
,
    /* RID_30A8_ResetLimpHomeTimer */
    {
        0x30a8,  /* dataRId_u16 */
        
        9,  /* routineCommonIndex_u16 */     
        
        NULL_PTR  /* isNormalRoutineAvailable_pfct */
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_0206_CheckProgrammingPreConditions_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        16,  /* dataLength_u16 */
        (uint16)RID_0206_CheckProgrammingPreConditions_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_307B_HandwheelAnglerimSet_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_307B_HandwheelAnglerimSet_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_3080_HandwheelAngleTrimClear_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_3080_HandwheelAngleTrimClear_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};




static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_3082_CentreFindingAlgorithm_StartInSig_ast[]=
{
     {
        0,  /* posnStart_u16 */
        8,  /* dataLength_u16 */
        (uint16)RID_3082_CentreFindingAlgorithm_DcmDspStartRoutineInSignal_0_StrtIn,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
        DCM_UINT8_N  /* dataType_u8 */             
     }
};



static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_3082_CentreFindingAlgorithm_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_3082_CentreFindingAlgorithm_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_3083_PullDriftCompensationClear_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_3083_PullDriftCompensationClear_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_3088_ResetRackEndLearning_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_3088_ResetRackEndLearning_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_3089_ClearFrictionDetectionFault_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_3089_ClearFrictionDetectionFault_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_308A_ResetFrictionDetectionFault_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_308A_ResetFrictionDetectionFault_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_308B_ResetPSCMSteeringAnle_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_308B_ResetPSCMSteeringAnle_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};







static const Dcm_RoutineSignalConfigType_tst DcmDspRc_RID_30A8_ResetLimpHomeTimer_StartOutSig_ast[]=
{
   {
        0,  /* posnStart_u16 */  
        8,  /* dataLength_u16 */
        (uint16)RID_30A8_ResetLimpHomeTimer_DcmDspStartRoutineOutSignal_0_StrtOut,  /* idxSignal_u16 */
        DCM_OPAQUE,  /* dataEndianness_u8 */
       DCM_UINT8_N  /* dataType_u8 */       
    }
};





static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_0206_CheckProgrammingPreConditions_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_0206_CheckProgrammingPreConditions_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    2,  /* minStatusOptionRecordSize_u16 */

    2,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_307B_HandwheelAnglerimSet_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_307B_HandwheelAnglerimSet_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_3080_HandwheelAngleTrimClear_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_3080_HandwheelAngleTrimClear_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_3082_CentreFindingAlgorithm_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    &DcmDspRc_RID_3082_CentreFindingAlgorithm_StartInSig_ast[0],  /* inSignalConfig_past */
  
    &DcmDspRc_RID_3082_CentreFindingAlgorithm_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    1,  /* minControlOptionRecordSize_u16 */
  
    1,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    1,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_3083_PullDriftCompensationClear_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_3083_PullDriftCompensationClear_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_3088_ResetRackEndLearning_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_3088_ResetRackEndLearning_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_3089_ClearFrictionDetectionFault_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_3089_ClearFrictionDetectionFault_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_308A_ResetFrictionDetectionFault_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_308A_ResetFrictionDetectionFault_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_308B_ResetPSCMSteeringAnle_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_308B_ResetPSCMSteeringAnle_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};






static const Dcm_RoutineSubFunctionConfigType_tst Dcm_Cfg_RID_30A8_ResetLimpHomeTimer_Start_st =
{
    NULL_PTR,  /* modeCondition_pfct */
  
    NULL_PTR,  /* inSignalConfig_past */
  
    &DcmDspRc_RID_30A8_ResetLimpHomeTimer_StartOutSig_ast[0],  /* outSignalConfig_past */
  
    TRUE,  /* isControlOptionRecordSizeFixed_b */
  
    0,  /* minControlOptionRecordSize_u16 */
  
    0,  /* maxControlOptionRecordSize_u16 */
  
    1,  /* minStatusOptionRecordSize_u16 */

    1,  /* maxstatusOptionRecordSize_u16 */
  
    0,  /* numberOfInSignals_u8 */
  
    1  /* numberOfOutSignals_u8 */
};










#define DCM_STOP_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"


#define DCM_START_SEC_CODE 
#include "Dcm_MemMap.h"

static Std_ReturnType Dcm_Dsp_RC_RID_0206_CheckProgrammingPreConditions_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_0206_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_0206_CheckProgrammingPreConditions_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_307B_HandwheelAnglerimSet_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_307B_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_307B_HandwheelAnglerimSet_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_3080_HandwheelAngleTrimClear_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_3080_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_3080_HandwheelAngleTrimClear_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_3082_CentreFindingAlgorithm_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_3082_Start
                (
&Dcm_RCDataInN_au8[RID_3082_CentreFindingAlgorithm_DcmDspStartRoutineInSignal_0_StrtIn],
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_3082_CentreFindingAlgorithm_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_3083_PullDriftCompensationClear_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_3083_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_3083_PullDriftCompensationClear_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_3088_ResetRackEndLearning_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_3088_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_3088_ResetRackEndLearning_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_3089_ClearFrictionDetectionFault_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_3089_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_3089_ClearFrictionDetectionFault_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_308A_ResetFrictionDetectionFault_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_308A_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_308A_ResetFrictionDetectionFault_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_308B_ResetPSCMSteeringAnle_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_308B_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_308B_ResetPSCMSteeringAnle_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static Std_ReturnType Dcm_Dsp_RC_RID_30A8_ResetLimpHomeTimer_Func (uint8 subFunction_u8, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* dataNegRespCode_u8)
{
    Std_ReturnType dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (subFunction_u8)
    {
    case 1u:
        dataRetVal_u8 = DcmDspRoutine_30A8_Start
                (
                    OpStatus,
                    &(Dcm_RCDataOutN_au8[RID_30A8_ResetLimpHomeTimer_DcmDspStartRoutineOutSignal_0_StrtOut]),
                    dataNegRespCode_u8
                  );

        break;



    default:
        *dataNegRespCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}

#define DCM_STOP_SEC_CODE 
#include "Dcm_MemMap.h"





#define DCM_START_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"

const Dcm_RoutineExtendedConfigType_tst Dcm_Cfg_RoutineExtendedConfig_cast[DCM_CFG_NUM_TOTAL_ROUTINES] =
{

    /* RID_0206_CheckProgrammingPreConditions */
  {
    0x5uL,  /* allowedSessions_u32 */
  
    0xFFFFFFFFuL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_0206_CheckProgrammingPreConditions_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_0206_CheckProgrammingPreConditions_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_307B_HandwheelAnglerimSet */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_307B_HandwheelAnglerimSet_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_307B_HandwheelAnglerimSet_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_3080_HandwheelAngleTrimClear */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_3080_HandwheelAngleTrimClear_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_3080_HandwheelAngleTrimClear_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_3082_CentreFindingAlgorithm */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_3082_CentreFindingAlgorithm_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_3082_CentreFindingAlgorithm_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_3083_PullDriftCompensationClear */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_3083_PullDriftCompensationClear_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_3083_PullDriftCompensationClear_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_3088_ResetRackEndLearning */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_3088_ResetRackEndLearning_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_3088_ResetRackEndLearning_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_3089_ClearFrictionDetectionFault */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_3089_ClearFrictionDetectionFault_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_3089_ClearFrictionDetectionFault_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_308A_ResetFrictionDetectionFault */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_308A_ResetFrictionDetectionFault_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_308A_ResetFrictionDetectionFault_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_308B_ResetPSCMSteeringAnle */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_308B_ResetPSCMSteeringAnle_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_308B_ResetPSCMSteeringAnle_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }
,
    /* RID_30A8_ResetLimpHomeTimer */
  {
    0x4uL,  /* allowedSessions_u32 */
  
    0x2uL,  /* allowedSecurityLevels_u32 */
  
    0uL,                            /* allowedRoles_u32 */    
  
    NULL_PTR,  /* userModeCondition_pfct */
  
    &Dcm_Dsp_RC_RID_30A8_ResetLimpHomeTimer_Func,  /* routineHandler_pfct */
  
    &Dcm_Cfg_RID_30A8_ResetLimpHomeTimer_Start_st,  /* startConfig_pst */
  
    NULL_PTR,  /* stopConfig_pst */
  
    NULL_PTR,  /* requestResultsConfig_pst */
  
    FALSE,  /* usePort_b */
  
    FALSE,  /* stopRoutineOnSessionChange_b */
  
    TRUE  /* requestSequenceErrorSupported_b */
  }


};

#define DCM_STOP_SEC_CONST_UNSPECIFIED 
#include "Dcm_MemMap.h"


/**
 ***************************************************************************************************
            Routine control (RC) service - end
 ***************************************************************************************************
 */
 
#endif













/* Variables to store the Array of signals for different Data Types */
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
    

 



    


 



    



/*Handling of  Sender receiver supported IOCBI DIDs*/
 








/**
 **********************************************************************************************************************
           DID Signal Substructure Configuration for condition check for read and write and read datalength function
 **********************************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
const Dcm_SignalDIDSubStructConfig_tst Dcm_DspDid_ControlInfo_st[2]=
{
    {
        NULL_PTR,
        NULL_PTR
,
        NULL_PTR,         
        NULL_PTR,
        NULL_PTR
    },



    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
        (void*)&DID_D01C_WriteFnc,         /* Write Data Function */
            NULL_PTR,                                                 /* Write Data type variable */
            NULL_PTR,                                                  /* Get Signal function to copy data */

    }

};


#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/**
 ***************************************************************************************************
           DID Signal Configuration
 ***************************************************************************************************
**/

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
const Dcm_DataInfoConfig_tst Dcm_DspDataInfo_st [54]=
{
    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_2145_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_2146_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_2147_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           3,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_217D_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_217E_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_21AB_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_21AC_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_21AD_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_2221_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_3012_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_3017_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_302C_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           4,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_330C_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D005_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           60,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D01C_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           292,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           1,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_ASYNCH_FNC,     /*DataUsePort is USE_DATA_ASYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            NULL_PTR,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           NvMConf_NvMBlockDescriptor_NvM_BN_DID_D09A,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_BLOCK_ID,      /*DataUsePort is USE_BLOCK_ID*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D0B5_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           3,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D118_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D11C_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D134_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D900_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D901_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D902_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D904_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D905_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D906_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D908_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D909_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           4,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_D90A_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_DD00_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           4,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_DD01_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           3,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_DD02_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_DD06_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           2,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_DD07_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           6,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_DD0A_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_DD0C_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_E103_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           31,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F120_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           7,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F121_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           7,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F125_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           7,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F126_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           51,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F12A_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           7,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F12B_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           7,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F12E_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           43,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F186_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           1,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F18A_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           6,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F18C_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           4,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F1A0_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           8,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F1A1_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           8,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F1A5_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           8,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F1AA_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           8,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F1AB_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           8,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F1AE_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           49,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&DID_F1D0_ReadFnc,            /* Read Data Function */
            NULL_PTR,                                               /* Read Data type variable */
    
            NULL_PTR,                                                   /* API to store and assemble all signals data */
    
    
           7,                                                 /*Signal Data Byte Size */
           
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
    
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
           USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
      
     
     
    }
    
    
};






#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"



/**
 ***************************************************************************************************
           DID Signal Configuration
 ***************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


/* DID DID_0x2145 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_2145_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        0,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x2146 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_2146_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        1,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x2147 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_2147_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        2,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x217D signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_217D_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        3,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x217E signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_217E_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        4,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x21AB signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_21AB_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        5,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x21AC signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_21AC_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        6,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x21AD signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_21AD_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        7,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x2221 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_2221_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        8,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x3012 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_3012_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        9,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x3017 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_3017_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        10,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x302C signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_302C_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        11,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0x330C signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_330C_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        12,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD005 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D005_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        13,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD01C signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D01C_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        14,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD09A signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D09A_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        15,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD0B5 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D0B5_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        16,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD118 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D118_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        17,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD11C signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D11C_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        18,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD134 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D134_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        19,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD900 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D900_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        20,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD901 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D901_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        21,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD902 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D902_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        22,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD904 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D904_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        23,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD905 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D905_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        24,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD906 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D906_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        25,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD908 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D908_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        26,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD909 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D909_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        27,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xD90A signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_D90A_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        28,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xDD00 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_DD00_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        29,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xDD01 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_DD01_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        30,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xDD02 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_DD02_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        31,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xDD06 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_DD06_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        32,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xDD07 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_DD07_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        33,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xDD0A signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_DD0A_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        34,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xDD0C signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_DD0C_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        35,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xE103 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_E103_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        36,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF120 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F120_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        37,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF121 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F121_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        38,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF125 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F125_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        39,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF126 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F126_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        40,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF12A signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F12A_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        41,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF12B signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F12B_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        42,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF12E signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F12E_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        43,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF186 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F186_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        44,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF18A signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F18A_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        45,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF18C signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F18C_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        46,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF1A0 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F1A0_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        47,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF1A1 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F1A1_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        48,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF1A5 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F1A5_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        49,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF1AA signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F1AA_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        50,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF1AB signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F1AB_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        51,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF1AE signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F1AE_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        52,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xF1D0 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_F1D0_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Byte Position */
        53,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xED20 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_ED20_SigConf[5]=
{
 /* Signal DcmDspDidSignal_0 */
    {
        2,    /* Signal Byte Position */
        46,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_1 */
    {
        8,    /* Signal Byte Position */
        47,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_2 */
    {
        18,    /* Signal Byte Position */
        50,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_3 */
    {
        28,    /* Signal Byte Position */
        51,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_4 */
    {
        38,    /* Signal Byte Position */
        52,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};

/* DID DID_0xEDA0 signal configuration */
static const Dcm_SignalDIDConfig_tst DcmDspDid_EDA0_SigConf[5]=
{
 /* Signal DcmDspDidSignal */
    {
        2,    /* Signal Byte Position */
        37,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_0 */
    {
        11,    /* Signal Byte Position */
        41,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_1 */
    {
        20,    /* Signal Byte Position */
        42,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_2 */
    {
        29,    /* Signal Byte Position */
        43,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
, 
 /* Signal DcmDspDidSignal_3 */
    {
        74,    /* Signal Byte Position */
        46,
        NULL_PTR,
        NULL_PTR           /* Write Data Function */
    }
};



#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


/**
 ***************************************************************************************************
           DID Extended Configuration
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x2145_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x2146_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x2147_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x217D_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x217E_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x21AB_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x21AC_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x21AD_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x2221_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x3012_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x3017_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x302C_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0x330C_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD005_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD01C_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
    0x4uL, /* Allowed Write Session levels */
    0x2uL, /* Allowed Write Security levels */
     0uL,       /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD09A_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
    0x4uL, /* Allowed Write Session levels */
    0x2uL, /* Allowed Write Security levels */
     0uL,       /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD0B5_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD118_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD11C_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD134_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD900_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD901_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD902_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD904_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD905_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD906_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD908_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD909_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xD90A_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xDD00_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xDD01_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xDD02_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xDD06_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xDD07_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xDD0A_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xDD0C_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xE103_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF120_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF121_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF125_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF126_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF12A_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF12B_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF12E_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF186_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF18A_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF18C_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF1A0_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF1A1_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF1A5_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF1AA_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF1AB_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF1AE_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xF1D0_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xED20_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};

static const Dcm_ExtendedDIDConfig_tst Did_extendedConfig_DID_0xEDA0_info=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */   
     0uL,       /* Allowed Read Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        0x0uL,          /* Allowed Write Authentication Roles */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"



/**
 ***************************************************************************************************
           DID Configuration Structure
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"



const Dcm_DIDConfig_tst Dcm_DIDConfig []=
{

    {
        0x2145,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_2145_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x2145_info   /*ExtendedConfiguration*/
    }


,
    {
        0x2146,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_2146_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x2146_info   /*ExtendedConfiguration*/
    }


,
    {
        0x2147,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        3,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_2147_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x2147_info   /*ExtendedConfiguration*/
    }


,
    {
        0x217D,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_217D_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x217D_info   /*ExtendedConfiguration*/
    }


,
    {
        0x217E,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_217E_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x217E_info   /*ExtendedConfiguration*/
    }


,
    {
        0x21AB,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_21AB_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x21AB_info   /*ExtendedConfiguration*/
    }


,
    {
        0x21AC,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_21AC_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x21AC_info   /*ExtendedConfiguration*/
    }


,
    {
        0x21AD,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_21AD_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x21AD_info   /*ExtendedConfiguration*/
    }


,
    {
        0x2221,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_2221_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x2221_info   /*ExtendedConfiguration*/
    }


,
    {
        0x3012,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_3012_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x3012_info   /*ExtendedConfiguration*/
    }


,
    {
        0x3017,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_3017_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x3017_info   /*ExtendedConfiguration*/
    }


,
    {
        0x302C,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        4,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_302C_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x302C_info   /*ExtendedConfiguration*/
    }


,
    {
        0x330C,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_330C_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0x330C_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD005,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        60,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D005_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD005_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD01C,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        292,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D01C_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD01C_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD09A,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D09A_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD09A_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD0B5,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        3,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D0B5_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD0B5_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD118,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D118_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD118_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD11C,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D11C_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD11C_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD134,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D134_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD134_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD900,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D900_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD900_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD901,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D901_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD901_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD902,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D902_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD902_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD904,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D904_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD904_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD905,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D905_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD905_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD906,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D906_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD906_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD908,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D908_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD908_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD909,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        4,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D909_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD909_info   /*ExtendedConfiguration*/
    }


,
    {
        0xD90A,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_D90A_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xD90A_info   /*ExtendedConfiguration*/
    }


,
    {
        0xDD00,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        4,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_DD00_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xDD00_info   /*ExtendedConfiguration*/
    }


,
    {
        0xDD01,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        3,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_DD01_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xDD01_info   /*ExtendedConfiguration*/
    }


,
    {
        0xDD02,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_DD02_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xDD02_info   /*ExtendedConfiguration*/
    }


,
    {
        0xDD06,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        2,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_DD06_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xDD06_info   /*ExtendedConfiguration*/
    }


,
    {
        0xDD07,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        6,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_DD07_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xDD07_info   /*ExtendedConfiguration*/
    }


,
    {
        0xDD0A,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_DD0A_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xDD0A_info   /*ExtendedConfiguration*/
    }


,
    {
        0xDD0C,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_DD0C_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xDD0C_info   /*ExtendedConfiguration*/
    }


,
    {
        0xE103,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        31,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_E103_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xE103_info   /*ExtendedConfiguration*/
    }


,
    {
        0xED20,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        5,                          /*No of Signals*/
        87,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_ED20_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xED20_info   /*ExtendedConfiguration*/
    }


,
    {
        0xEDA0,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        5,                          /*No of Signals*/
        78,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_EDA0_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xEDA0_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF120,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        7,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F120_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF120_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF121,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        7,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F121_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF121_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF125,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        7,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F125_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF125_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF126,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        51,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F126_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF126_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF12A,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        7,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F12A_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF12A_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF12B,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        7,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F12B_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF12B_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF12E,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        43,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F12E_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF12E_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF186,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        1,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F186_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF186_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF18A,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        6,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F18A_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF18A_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF18C,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        4,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F18C_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF18C_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF1A0,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        8,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F1A0_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF1A0_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF1A1,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        8,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F1A1_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF1A1_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF1A5,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        8,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F1A5_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF1A5_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF1AA,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        8,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F1AA_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF1AA_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF1AB,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        8,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F1AB_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF1AB_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF1AE,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        49,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F1AE_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF1AE_info   /*ExtendedConfiguration*/
    }


,
    {
        0xF1D0,                        /*DID*/
        USE_DATA_ELEMENT_SPECIFIC_INTERFACES,      /*DidUsePort*/
        FALSE,       /* Flag to indicate Atomic/new SenderReceiver communication as per SWS 4.4.0 or SenderReceiver communication communication as per SWS 4.2.0 */
        1,                          /*No of Signals*/
        7,                                /*TotalByteSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F1D0_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif

        NULL_PTR,           /* IOControlRequest Function*/


        &Did_extendedConfig_DID_0xF1D0_info   /*ExtendedConfiguration*/
    }



};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
uint16 Dcm_DIDcalculateTableSize_u16(void)
{
  return ((uint32)(sizeof(Dcm_DIDConfig))/(uint16)(sizeof(Dcm_DIDConfig_tst)));
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"







#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
boolean Dcm_ControlDtcSettingModecheck_b(
/* MR12 RULE 8.13 VIOLATION: The object addressed by NegRespCode_u8 will be modified depending on different configurations */
Dcm_NegativeResponseCodeType * NegRespCode_u8)
{
    Std_ReturnType retVal_u8;
    boolean retVal_b;

    /* Call the DcmAppl API to check if the DTC Setting needs to be re-enabled */
    retVal_u8 =DcmAppl_UserDTCSettingEnableModeRuleService();

    if(retVal_u8!=E_OK)
    {
        (void)NegRespCode_u8;
        retVal_b = FALSE;
    }
    else
    {
        (void)NegRespCode_u8;
        retVal_b = TRUE;
    }
    return (retVal_b);

}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"




/**
 ***************************************************************************************************
            Ecu Reset (ER) Service
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* Initialization of the parameters for the supported Reset Types */
const Dcm_DspEcuReset_tst Dcm_DspEcuResetType_cast[DCM_CFG_DSP_NUMRESETTYPE] =
{

    {
        RTE_MODE_DcmEcuReset_HARD,         /* DcmEcuReset Mode  for the ResetType */
        0x1,                              /* ResetType */
        DCM_RESET_NO_BOOT

    }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"





/**
 ***************************************************************************************************
        Communication Control Service
 ***************************************************************************************************
*/

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
Std_ReturnType (*Dcm_ComMUserReEnableModeRuleRef) (void) = &DcmAppl_UserCommCtrlReEnableModeRuleService;
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

static boolean Dcm_Can_Network_0_Channel_Can_Network_0_IsModeDefault ( void )
{
    boolean dataRetValue_b;

    if ( SchM_Mode_Dcm_R_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0() != RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_TX_NORM_NM )
    {
        dataRetValue_b = FALSE;
    }
    else
    {
        dataRetValue_b = TRUE;
    }
    return (dataRetValue_b);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/* Function to map Dcm_CommunicationModeType to Rte_Communication Mode type for Can_Network_0_Channel_Can_Network_0 */
static Std_ReturnType Dcm_Can_Network_0_Channel_Can_Network_0_SwitchIndication ( Dcm_CommunicationModeType Mode )
{
    Std_ReturnType dataRetValue_u8;
    switch (Mode)
    {
        case DCM_ENABLE_RX_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0( RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_TX_NORM);
            break;
        case DCM_ENABLE_RX_DISABLE_TX_NORM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_DISABLE_TX_NORM);
            break;
        case DCM_DISABLE_RX_ENABLE_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_DISABLE_RX_ENABLE_TX_NORM);
            break;
        case DCM_DISABLE_RX_TX_NORMAL:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_DISABLE_RX_TX_NORM);
            break;
        case DCM_ENABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_TX_NM);
            break;
        case DCM_ENABLE_RX_DISABLE_TX_NM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0( RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_DISABLE_TX_NM);
            break;
        case DCM_DISABLE_RX_ENABLE_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_DISABLE_RX_ENABLE_TX_NM);
            break;
        case DCM_DISABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_DISABLE_RX_TX_NM);
            break;
        case DCM_ENABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_TX_NORM_NM);
            break;
        case DCM_ENABLE_RX_DISABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_DISABLE_TX_NORM_NM);
            break;
        case DCM_DISABLE_RX_ENABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_DISABLE_RX_ENABLE_TX_NORM_NM);
            break;
        case DCM_DISABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_DISABLE_RX_TX_NORM_NM);
            break;
        default: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0(RTE_MODE_DcmCommunicationControl_Can_Network_0_Channel_Can_Network_0_DCM_ENABLE_RX_TX_NORM);
            break;
    }
    return (dataRetValue_u8);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/*Array  stores the channelID info which is to be informed about the communication mode change if the subnet ID is 0  */
const Dcm_Dsld_AllChannelsInfoType Dcm_AllChannels_ForModeInfo[DCM_CFG_NUM_ALLCHANNELS_MODE_INFO]=
{
    {
        &Dcm_Can_Network_0_Channel_Can_Network_0_SwitchIndication,      /* Auto generated Dcm function to be called for invoking SchM Switch Indication */
        &Dcm_Can_Network_0_Channel_Can_Network_0_IsModeDefault,        /* Auto generated Dcm function to be called for checking if Active Mode is Default */
         ComMConf_ComMChannel_Can_Network_0_Channel_Can_Network_0
    }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"





/**
 ***************************************************************************************************
        Clear Diagnostic Information Service (0x14)
 ***************************************************************************************************
*/










