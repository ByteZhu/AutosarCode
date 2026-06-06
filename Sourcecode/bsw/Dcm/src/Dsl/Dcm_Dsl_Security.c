#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dcm_Prv.h"


#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"
static uint8 Dcm_ActiveSecurityLevelIdx_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

static Dcm_SecLevelType Dcm_GetActiveSecurityLevel(uint8 SecurityLevelIdx_u8)
{
    const uint8 * adrSecurityLookupTable_pcu8 = Dcm_GetSecurityLookupTable();

    return adrSecurityLookupTable_pcu8[SecurityLevelIdx_u8];
}

void Dcm_Prv_SetActiveSecurityLevelIdx(uint8 SecurityLevelIdx_u8)
{
    Dcm_ActiveSecurityLevelIdx_u8 = SecurityLevelIdx_u8;
}


uint8 Dcm_Prv_GetActiveSecurityLevelIdx(void)
{
    return Dcm_ActiveSecurityLevelIdx_u8;
}


Std_ReturnType Dcm_Dsl_Prv_VerifySecurityAccess(const uint32 allowedSecurity_u32,
        Dcm_NegativeResponseCodeType *negativeResponseCode)
{
    uint32 ActiveMask_u32;
    Std_ReturnType securityAccess = E_NOT_OK;
    /* generate bit mask for active security level */
    ActiveMask_u32 = (uint32) (DCM_DEFAULT_MASKVALUE << Dcm_Prv_GetActiveSecurityLevelIdx());

    if ((allowedSecurity_u32 & ActiveMask_u32) == (ActiveMask_u32))
    {
        securityAccess = E_OK;
    }
    else
    {
        *negativeResponseCode = DCM_E_SECURITYACCESSDENIED;
    }

    return securityAccess;
}


void Dcm_Prv_SetSecurityLevel (Dcm_SecLevelType dataSecurityLevel_u8)
{
    uint8 idxIndex_qu8;

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF))
    uint32 dataSecurityMask_u32;                         /*Active security Mask*/
#endif

    /* pointer to security look up table array */
    const uint8 * adrSecurityLookupTable_pcu8;

    /* get the look up table from configuration */
    adrSecurityLookupTable_pcu8 = Dcm_GetSecurityLookupTable();

    /* get the index of the requested security level in security look up table */
    for(idxIndex_qu8 = 0x0; idxIndex_qu8 < DCM_CFG_NUM_SECURITY_LEVEL ; idxIndex_qu8++)
    {
        if(adrSecurityLookupTable_pcu8[idxIndex_qu8]== dataSecurityLevel_u8)
        {
            /* requested security level found */
            break;
        }
    }

    if(idxIndex_qu8< DCM_CFG_NUM_SECURITY_LEVEL)
    {
        /* set security level index */
        Dcm_Prv_SetActiveSecurityLevelIdx(idxIndex_qu8);

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF))
        /**The code which would loop through all the IOCBI DIDs and call all the returncontrol to ECU functions to reset all the IOctrls which are not active in the current security level
        ***supported in the current security level or not*/
        dataSecurityMask_u32 = Dcm_DsldGetActiveSecurityMask_u32();
        /*Session MASK is sent as 0xFFFFFFFF because during security transition, session mask is not affected
         * there is no need to do session check, Hence 0xFFFFFFFF is sent which will always result in true,on security
         * transition there is no need to check for session mask, Hence FALSE is passed which will result in session check being disabled*/
    Dcm_ResetActiveIoCtrl(0xFFFFFFFFu,dataSecurityMask_u32,FALSE);
    #endif
#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) &&(DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF))
        if (Dcm_NumOfActivePeriodicId_u8>0u)
        {
                Dcm_RdpiSecurityCheck();
        }
#endif
    }
    else
    {
        /* Report development error "DCM_E_SECURITYLEVEL_NOT_CONFIGURED " to DET module if the DET module is enabled */
        Dcm_Prv_Det(DCM_SETSECURITYLEVEL , DCM_E_SECURITYLEVEL_OUTOFBOUNDS);
    }
}

/**
 **************************************************************************************************
 * Dcm_DsldGetActiveSessionMask_u32 : API to get the active session mask
 * \param           None
 *
 *
 * \retval          active session mask
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
uint32 Dcm_DsldGetActiveSecurityMask_u32 (void)
{
    return (uint32)(0x01uL<<Dcm_Prv_GetActiveSecurityLevelIdx());
}

/**
 **************************************************************************************************
 * Dcm_GetSecurityLevel : API to get the active security level
 * \param           None
 *
 *
 * \retval          active security
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
Std_ReturnType Dcm_GetSecurityLevel (Dcm_SecLevelType * SecLevel)
{
    if(SecLevel != NULL_PTR)
    {
        *SecLevel = Dcm_GetActiveSecurityLevel(Dcm_Prv_GetActiveSecurityLevelIdx());
    }
    else
    {
        /* DET ERROR REPORT */
        Dcm_Prv_Det(DCM_BOOTLOADER_ID, DCM_E_PARAM_POINTER);
    }
    return (E_OK);
}






#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
