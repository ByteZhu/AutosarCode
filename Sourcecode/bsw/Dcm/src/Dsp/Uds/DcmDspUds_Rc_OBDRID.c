
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#ifdef DCM_CFG_DSPRCOBDRID_ENABLED
#if (DCM_CFG_DSPRCOBDRID_ENABLED!=DCM_CFG_OFF)
#include "Dcm_Prv.h"

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

Std_ReturnType Dcm_OBDRID_E000_Supportinfo(Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode)
{
    (void)OpStatus;
    *ErrorCode = 0x0;
    return E_OK;
}

Std_ReturnType Dcm_OBDRID_E001_StartRoutine(Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode)
{
    (void)OpStatus;
    *ErrorCode = 0x0;
    return E_OK;
}

Std_ReturnType Dcm_OBDRID_E002_StartRoutine(Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode)
{
    (void)OpStatus;
    *ErrorCode = 0x0;
    return E_OK;
}

Std_ReturnType Dcm_OBDRID_E003_StartRoutine(Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode)
{
    (void)OpStatus;
    *ErrorCode = 0x0;
    return E_OK;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
#endif
