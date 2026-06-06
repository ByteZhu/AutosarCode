#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Dcm_Prv.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/*
 **************************************************************************************************
 * Dcm_GetVersionInfo
 * Returns the version information of this module.
 **************************************************************************************************
 */
#if (DCM_CFG_VERSIONINFO_SUPPORTED)
/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3664]*/
void Dcm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    if (versioninfo != NULL_PTR)
    {
        versioninfo->vendorID = DCM_VENDOR_ID;
        versioninfo->moduleID = DCM_MODULE_ID;
        versioninfo->sw_major_version = DCM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DCM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DCM_SW_PATCH_VERSION;
    }
    else
    {
        /* throw the error DCM_E_PARAM_POINTER */
        Dcm_Prv_Det(DCM_GETVERSIONINFO_ID, DCM_E_PARAM_POINTER);
    }
}
#endif

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
