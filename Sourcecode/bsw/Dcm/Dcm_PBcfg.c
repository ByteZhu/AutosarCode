
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"


#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubSrvPBConfigType_tst Dcm_PBcfg_SrvTab0_Service0x10_SubSrv_acst[]=
{
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubSrvPBConfigType_tst Dcm_PBcfg_SrvTab0_Service0x27_SubSrv_acst[]=
{
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubSrvPBConfigType_tst Dcm_PBcfg_SrvTab0_Service0x11_SubSrv_acst[]=
{
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubSrvPBConfigType_tst Dcm_PBcfg_SrvTab0_Service0x19_SubSrv_acst[]=
{
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubSrvPBConfigType_tst Dcm_PBcfg_SrvTab0_Service0x3E_SubSrv_acst[]=
{
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubSrvPBConfigType_tst Dcm_PBcfg_SrvTab0_Service0x28_SubSrv_acst[]=
{
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
};
/*ECU_EPS_ServiceTable*/
static const Dcm_DsdSubSrvPBConfigType_tst Dcm_PBcfg_SrvTab0_Service0x85_SubSrv_acst[]=
{
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
,
  {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
  }
};

static const Dcm_DsdServicePBConfigType_tst Dcm_PBCfg_DsdService0_acst[]=
{
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      Dcm_PBcfg_SrvTab0_Service0x10_SubSrv_acst,        /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      Dcm_PBcfg_SrvTab0_Service0x27_SubSrv_acst,        /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      Dcm_PBcfg_SrvTab0_Service0x11_SubSrv_acst,        /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      Dcm_PBcfg_SrvTab0_Service0x19_SubSrv_acst,        /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      NULL_PTR,                                         /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      NULL_PTR,                                         /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      NULL_PTR,                                         /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      NULL_PTR,                                         /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      Dcm_PBcfg_SrvTab0_Service0x3E_SubSrv_acst,        /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      Dcm_PBcfg_SrvTab0_Service0x28_SubSrv_acst,        /* SubFunctionTableRef */
    }
,
    {
      0uL,                                              /* AuthenticationRoleNotConfigured*/
      Dcm_PBcfg_SrvTab0_Service0x85_SubSrv_acst,        /* SubFunctionTableRef */
    }
};

/* Sid table configuration */
static const Dcm_DsdServicePBConfigType_tst *Dcm_PBCfg_DsdSidTables_pcast[]=
{
 Dcm_PBCfg_DsdService0_acst,       /*ECU_EPS_ServiceTable*/
};





static const Dcm_ConfigType Dcm_Cfg_cst = 
{
    0,
    &Dcm_PBCfg_DsdSidTables_pcast[0]

};

const Dcm_ConfigType *Dcm_Cfg_pcst = &Dcm_Cfg_cst;
