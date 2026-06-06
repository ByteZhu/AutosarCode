
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "SchM_Dcm.h"

#include "Rte_Dcm.h"
#include "Dcm_Prv.h"



#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubServiceConfigType_tst Dcm_Cfg_SrvTab0_Service0x10_SubSrv_acst[]=
{
  {
      0x1,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
,
  {
      0x2,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      &Dcm_DcmModeRule_NRC22,                           /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
,
  {
      0x3,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubServiceConfigType_tst Dcm_Cfg_SrvTab0_Service0x27_SubSrv_acst[]=
{
  {
      0x5,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
,
  {
      0x6,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubServiceConfigType_tst Dcm_Cfg_SrvTab0_Service0x11_SubSrv_acst[]=
{
  {
      0x1,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubServiceConfigType_tst Dcm_Cfg_SrvTab0_Service0x19_SubSrv_acst[]=
{
  {
      0x1,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        
            &Dcm_Dsp_ReportNumberOfDTC,/* Sub-service Handler*/
 /* Service Handler for Subfunction */
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
            TRUE,    /* DSP RDTC subfunction configured */
           
  }
,
  {
      0x2,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        
            &Dcm_Dsp_ReportSupportedDTC,/* Sub-service Handler*/
 /* Service Handler for Subfunction */
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
            TRUE,    /* DSP RDTC subfunction configured */
           
  }
,
  {
      0x3,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        
            &Dcm_Dsp_ReportDTCSnapshotRecordIdentification,/* Sub-service Handler*/
 /* Service Handler for Subfunction */
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
            TRUE,    /* DSP RDTC subfunction configured */
           
  }
,
  {
      0x4,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        
            &Dcm_Dsp_ReportSnapshotRecordByDTCNumber,/* Sub-service Handler*/
 /* Service Handler for Subfunction */
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
            TRUE,    /* DSP RDTC subfunction configured */
           
  }
,
  {
      0x6,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        
            &Dcm_Dsp_ReportExtendedDataRecordByDTCNumber,/* Sub-service Handler*/
 /* Service Handler for Subfunction */
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &Dcm_1906_User_Func,                              /* User specific Mode rule function*/  
      
            TRUE,    /* DSP RDTC subfunction configured */
           
  }
,
  {
      0xA,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        
            &Dcm_Dsp_ReportSupportedDTC,/* Sub-service Handler*/
 /* Service Handler for Subfunction */
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
            TRUE,    /* DSP RDTC subfunction configured */
           
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubServiceConfigType_tst Dcm_Cfg_SrvTab0_Service0x3E_SubSrv_acst[]=
{
  {
      0x0,                                              /* SubServiceId */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubServiceConfigType_tst Dcm_Cfg_SrvTab0_Service0x28_SubSrv_acst[]=
{
  {
      0x0,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      &Dcm_DcmModeRule_NRC22,                           /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
,
  {
      0x1,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
,
  {
      0x2,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
,
  {
      0x3,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubServiceConfigType_tst Dcm_Cfg_SrvTab0_Service0x85_SubSrv_acst[]=
{
  {
      0x1,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      &Dcm_DcmModeRule_NRC22,                           /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
,
  {
      0x2,                                              /* SubServiceId */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels */
      0uL,                                              /* Allowed in Authentication Roles */
      
        NULL_PTR, /* Service Handler for Subfunction */ 
      
      NULL_PTR,                                         /* ModeRule/Condition function*/
      &DcmAppl_UserSubServiceModeRuleService,           /* User specific Mode rule function*/  
      
        FALSE /* Is DSP subfunction or not*/ 
           
  }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static const Dcm_DsdServiceTableConfigType_tst Dcm_Cfg_DsdServiceTable0_acst[]=
{
    {
      0x10,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      3,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x7uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspDsc_Init,                              /* Init function of service  */
      Dcm_Prv_DspDiagnosticSessionControl,              /* Service handler    */
      Dcm_Cfg_SrvTab0_Service0x10_SubSrv_acst,          /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &Dcm_Prv_DspDscConfirmation                       /* Reference Service confirmation Apis */
    }
,
    {
      0x27,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      2,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspSeca_Init,                             /* Init function of service  */
      Dcm_Prv_DspSecurityAccess,                        /* Service handler    */
      Dcm_Cfg_SrvTab0_Service0x27_SubSrv_acst,          /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &Dcm_Prv_DspSecurityConfirmation                  /* Reference Service confirmation Apis */
    }
,
    {
      0x11,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      1,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspEcuReset_Init,                         /* Init function of service  */
      Dcm_Prv_DspEcuReset,                              /* Service handler    */
      Dcm_Cfg_SrvTab0_Service0x11_SubSrv_acst,          /* SubFunctionTableRef */
      &Dcm_DcmModeRule_NRC22,                           /* ModeRuleFunction */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &Dcm_Prv_DspEcuResetConfirmation                  /* Reference Service confirmation Apis */
    }
,
    {
      0x19,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      6,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspReadDTCInfo_Init,                      /* Init function of service  */
      Dcm_Prv_DspReadDTCInformation,                    /* Service handler    */
      Dcm_Cfg_SrvTab0_Service0x19_SubSrv_acst,          /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &Dcm_Prv_DspReadDTCInfoConfirmation               /* Reference Service confirmation Apis */
    }
,
    {
      0x14,                                             /* Service Identifier */
      FALSE,                                            /* SubFuncAvailable */
      0,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      NULL_PTR,                                         /* Init function of service  */
      Dcm_Prv_DspClearDiagnosticInformation,            /* Service handler    */
      NULL_PTR,                                         /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &DcmAppl_DcmConfirmation                          /* Reference Service confirmation Apis */
    }
,
    {
      0x22,                                             /* Service Identifier */
      FALSE,                                            /* SubFuncAvailable */
      0,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspRDBI_Init,                             /* Init function of service  */
      Dcm_Prv_DspReadDataByIdentifier,                  /* Service handler    */
      NULL_PTR,                                         /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &Dcm_Prv_DspRdbiConfirmation                      /* Reference Service confirmation Apis */
    }
,
    {
      0x2E,                                             /* Service Identifier */
      FALSE,                                            /* SubFuncAvailable */
      0,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x5uL,                                            /* Allowed sessions */
      0x2uL,                                            /* Allowed security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspWDBI_Init,                             /* Init function of service  */
      Dcm_Prv_DspWriteDataByIdentifier,                 /* Service handler    */
      NULL_PTR,                                         /* SubFunctionTableRef */
      &Dcm_DcmModeRule_NRC22,                           /* ModeRuleFunction */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &DcmAppl_DcmConfirmation                          /* Reference Service confirmation Apis */
    }
,
    {
      0x31,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      0,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspRC_Init,                               /* Init function of service  */
      Dcm_Prv_DspRoutineControl,                        /* Service handler    */
      NULL_PTR,                                         /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &Dcm_Prv_DspRCConfirmation                        /* Reference Service confirmation Apis */
    }
,
    {
      0x3E,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      1,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x5uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      NULL_PTR,                                         /* Init function of service  */
      Dcm_Prv_DspTesterPresent,                         /* Service handler    */
      Dcm_Cfg_SrvTab0_Service0x3E_SubSrv_acst,          /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &DcmAppl_DcmConfirmation                          /* Reference Service confirmation Apis */
    }
,
    {
      0x28,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      4,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      NULL_PTR,                                         /* Init function of service  */
      Dcm_Prv_DspCommunicationControl,                  /* Service handler    */
      Dcm_Cfg_SrvTab0_Service0x28_SubSrv_acst,          /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &Dcm_Prv_DspCommCntrlConfirmation                 /* Reference Service confirmation Apis */
    }
,
    {
      0x85,                                             /* Service Identifier */
      TRUE,                                             /* SubFuncAvailable */
      2,                                                /* NumberOfSubServices */
      TRUE,                                              /* Service is located within Dcm */
      0x7F,                                              /* NRC for service not supported in active session */
      0x4uL,                                            /* Allowed sessions */
      0xffffffffuL,                                     /* Allowed in all security levels*/
      0uL,                                              /* Allowed in Authentication Roles */
      Dcm_Prv_DspCDTCS_Init,                            /* Init function of service  */
      Dcm_Prv_DspControlDTCSetting,                     /* Service handler    */
      Dcm_Cfg_SrvTab0_Service0x85_SubSrv_acst,          /* SubFunctionTableRef */
      NULL_PTR,                                         /* ModeRuleFunction Not Configured */
      &DcmAppl_UserServiceModeRuleService,              /* No User specific mode rule function configured */
      &DcmAppl_DcmConfirmation                          /* Reference Service confirmation Apis */
    }

};

/* Sid table configuration */
static const Dcm_DsdSidTableConfigType_tst Dcm_Cfg_DsdSidTables_acst[]=
{
     /*ECU_EPS_ServiceTable*/
    {
      Dcm_Cfg_DsdServiceTable0_acst,   /* Pointer to service table */
      11,                              /* No of services in the Service table  */
      10 /* Index of the Dcm_Prv_DspControlDTCSetting service in the service table */
    }

};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"




#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*Dsd configuration*/
static const Dcm_DsdConfigType_tst Dcm_Cfg_Dsd_cst =
{
    &Dcm_Cfg_DsdSidTables_acst[0],                    /* ServiceTables Reference */
    NULL_PTR,                                         /* ManufacturerNotificationsNotConfigured*/
    NULL_PTR,                                         /* ManufacturerConfirmationsNotConfigured*/
    NULL_PTR,                                         /* SupplierNotificationsNotConfigured*/
    NULL_PTR,                                         /* SupplierConfirmationsNotConfigured*/
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"
const Dcm_DsdConfigType_tst *Dcm_Cfg_Dsd_pcst = &Dcm_Cfg_Dsd_cst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/*Mode rule definitions*/
/* Generating corresponding Check API's for each ModeRules */
static boolean Dcm_DcmModeCondition_NRC22(const uint8 *Nrc_u8)
{
            /* Flag to update the result of the check operation */
            boolean RetFlag_b;
             
        
        if(RTE_MODE_ModeDeclarationGroup_NRC22_ModeDeclaration_true == Rte_Mode_Rp_ModeDeclarationGroup_NRC22_MDGP_ModeDeclarationGroup_NRC22())
        {
           RetFlag_b = TRUE;
        }
        else
        {
           RetFlag_b = FALSE;
        }       
    (void)(Nrc_u8);
    /* Return the updated value of the Flag to indicate the result of the check operation */
    return RetFlag_b;
}
static boolean Dcm_DcmModeCondition_NRC72(const uint8 *Nrc_u8)
{
            /* Flag to update the result of the check operation */
            boolean RetFlag_b;
             
        
        if(RTE_MODE_ModeDeclarationGroup_NRC72_ModeDeclaration_true_72 == Rte_Mode_Rp_ModeDeclarationGroup_NRC72_MDGP_ModeDeclarationGroup_NRC72())
        {
           RetFlag_b = TRUE;
        }
        else
        {
           RetFlag_b = FALSE;
        }       
    (void)(Nrc_u8);
    /* Return the updated value of the Flag to indicate the result of the check operation */
    return RetFlag_b;
}
boolean Dcm_DcmModeRule_NRC22(uint8 *Nrc_u8)
{
/*MR12 RULE 13.5 VIOLATION: Right hand operand of '&&' or '||' is an expression with possible side effects. 
Pointer to NRC is passed to each moderule so that NRC can be updated by the first moderule which fails according to 
requirement. No side effects will be caused. MISRA C:2012 Rule-13.5*/
    if(Dcm_DcmModeCondition_NRC22(Nrc_u8))
    {
        *Nrc_u8=0;
        return(TRUE);
    }
    else
    {
        if(*Nrc_u8==0)
        {
            /* One of the ModeCondition or ModeRule referred by this ModeRule has failed but nrc is not yet set to a non-zero value */
            *Nrc_u8 = 34; /* User Specific NR Code */
        }
        return(FALSE);
    }
}
boolean Dcm_DcmModeRule_NRC72(uint8 *Nrc_u8)
{
/*MR12 RULE 13.5 VIOLATION: Right hand operand of '&&' or '||' is an expression with possible side effects. 
Pointer to NRC is passed to each moderule so that NRC can be updated by the first moderule which fails according to 
requirement. No side effects will be caused. MISRA C:2012 Rule-13.5*/
    if(Dcm_DcmModeCondition_NRC72(Nrc_u8))
    {
        *Nrc_u8=0;
        return(TRUE);
    }
    else
    {
        if(*Nrc_u8==0)
        {
            /* One of the ModeCondition or ModeRule referred by this ModeRule has failed but nrc is not yet set to a non-zero value */
            *Nrc_u8 = 114; /* User Specific NR Code */
        }
        return(FALSE);
    }
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

