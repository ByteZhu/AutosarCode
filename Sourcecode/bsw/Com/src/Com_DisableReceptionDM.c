
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Com_Prv.h"
#include "Com_Prv_Inl.h"

#if (COM_CONTROL_IPDUGROUPS == STD_ON)

# if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout)

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#define COM_CLEAR_IPDUGRPDM_BIT(idIpduGrp)    ((COM_IPDUGRPDM_STATUS((idIpduGrp) >> (3u))) &= (~(COM_ONE << ((idIpduGrp) % (8u)))))
#define COM_CHECK_IPDUGRPDM_BIT(idIpduGrp)    (((COM_IPDUGRPDM_STATUS((idIpduGrp) >> (3u))) >> ((idIpduGrp) % (8u))) & (COM_ONE))

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 Function name    : Com_DisableReceptionDM
 Description      : Service disables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
 Parameter        : idIpduGrp_u16 - I-PDU group id.
 Return value     : None
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

void Com_DisableReceptionDM(Com_IpduGroupIdType idIpduGrp_u16)
{
#if (COM_PRV_ERROR_HANDLING == STD_ON)
    if (Com_InitStatus_en == COM_UNINIT)
    {
        COM_DET_REPORT_ERROR(COMServiceId_DisableReceptionDM, COM_E_UNINIT);
    }
    else if(!Com_Prv_IsValidIpduGroupId(idIpduGrp_u16))
    {
        COM_DET_REPORT_ERROR(COMServiceId_DisableReceptionDM, COM_E_PARAM);
    }
    else
#endif /* end of COM_PRV_ERROR_HANDLING */
    {
        if(Com_Prv_IsValidRxIpduGroupId(idIpduGrp_u16))
        {
            Com_Prv_DisableReceptionDM(idIpduGrp_u16);
        }
    }
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/*
 **********************************************************************************************************************
 Function name    : Com_Prv_DisableReceptionDM
 Description      : Service disables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
 Parameter        : idIpduGrp_u16 - I-PDU group id.
 Return value     : None
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

void Com_Prv_DisableReceptionDM(Com_IpduGroupIdType idIpduGrp_u16)
{

    /* Local pointer which holds the address of the array which stores the ipdu id */
    const Com_IpduId_tuo *      ipduRefPtr_pcuo;
    /* Local pointer to hold the address of Ipdu group structure */
    Com_IpduGrpCfg_tpcst        ipduGrpConstPtr_pcst;
    Com_RxIpduRam_tpst          rxIpduRamPtr_pst;
    uint16_least                numOfRxIpdus_qu16;
    uint8                       pduCounterVal_u8;

    pduCounterVal_u8  = COM_ZERO;
    numOfRxIpdus_qu16 = COM_ZERO;

    /* Check if IPduGroup DM bit is set */
    if(COM_CHECK_IPDUGRPDM_BIT(idIpduGrp_u16) == COM_ONE)
    {
        /* Clear the IPduGroup bit */
        COM_CLEAR_IPDUGRPDM_BIT(idIpduGrp_u16);

        /* Store the DM counter value to 0xFFu */
        pduCounterVal_u8     = (0xFFu);

        ipduGrpConstPtr_pcst = COM_GET_IPDUGRP_CONSTDATA(idIpduGrp_u16);

        ipduRefPtr_pcuo      = COM_GET_IPDUGRP_IPDUREF_CONSTDATA(ipduGrpConstPtr_pcst->idFirstIpdu_u16);

        numOfRxIpdus_qu16    = ipduGrpConstPtr_pcst->numOfRxPdus_u16;

        while (numOfRxIpdus_qu16 > COM_ZERO)
        {
            rxIpduRamPtr_pst = &COM_GET_RXPDURAM_S(*ipduRefPtr_pcuo);

            /* Below DM counter shall decrement if latest state is stopped */
            COM_GET_IPDUCOUNTER_DM(*ipduRefPtr_pcuo) =
            (uint8)(COM_GET_IPDUCOUNTER_DM(*ipduRefPtr_pcuo) + pduCounterVal_u8);

            /* If any of the Ipdu Group containing the IPdu is active,
            * i.e., counter will have non-zero value */
            if (COM_GET_IPDUCOUNTER_DM(*ipduRefPtr_pcuo) == COM_ZERO)
            {
                if (Com_GetRamValue(RXIPDU,_DMSTATUS,rxIpduRamPtr_pst->rxFlags_u8))
                {
                    Com_SetRamValue(RXIPDU,_DMSTATUS,rxIpduRamPtr_pst->rxFlags_u8, COM_STOP);
                }
            }
            rxIpduRamPtr_pst++;
            ipduRefPtr_pcuo++;
            numOfRxIpdus_qu16--;
        }/* while (numOfRxIpdus_qu16 > 0 ) */
    }
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* #if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout) */

#endif /* #if (COM_CONTROL_IPDUGROUPS == STD_ON) */
