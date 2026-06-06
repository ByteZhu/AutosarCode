
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Com_Prv.h"
#include "Com_Prv_Inl.h"

#if (COM_CONTROL_IPDUGROUPS == STD_ON)
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#define COM_CLEAR_IPDUGRP_BIT(idIpduGrp)    ((COM_IPDUGROUP_STATUS((idIpduGrp) >> (3u))) &= (~(COM_ONE<< ((idIpduGrp) % (8u)))))
#define COM_CHECK_IPDUGRP_BIT(idIpduGrp)    (((COM_IPDUGROUP_STATUS((idIpduGrp) >> (3u))) >> ((idIpduGrp) % (8u))) & (COM_ONE))

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/

LOCAL_INLINE void Com_Prv_TxIpduGroupStop(Com_IpduGroupIdType idIpduGrp_u16);
LOCAL_INLINE void Com_Prv_RxIpduGroupStop(Com_IpduGroupIdType idIpduGrp_u16);

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
 Function name    : Com_IpduGroupStop
 Description      : Service for stopping the Ipdu's which comes under the Ipdu Group
 Parameter        : idIpduGrp_u16 - I-PDU group id.
 Return value     : None
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

void Com_IpduGroupStop(Com_IpduGroupIdType idIpduGrp_u16)
{

#if (COM_PRV_ERROR_HANDLING == STD_ON)
    if (Com_InitStatus_en == COM_UNINIT)
    {
        COM_DET_REPORT_ERROR(COMServiceId_IpduGroupStop, COM_E_UNINIT);
    }
    else if (!Com_Prv_IsValidIpduGroupId(idIpduGrp_u16))
    {
        COM_DET_REPORT_ERROR(COMServiceId_IpduGroupStop, COM_E_PARAM);
    }
    else
#endif /* end of COM_PRV_ERROR_HANDLING */
    {
        if(Com_Prv_IsValidTxIpduGroupId(idIpduGrp_u16))
        {
            Com_Prv_TxIpduGroupStop(idIpduGrp_u16);
        }
        else if(Com_Prv_IsValidRxIpduGroupId(idIpduGrp_u16))
        {
            Com_Prv_RxIpduGroupStop(idIpduGrp_u16);
        }
        else
        {
            /* Do nothing : IPduGroups does not contain IPdus */
        }
    }
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/*
 **********************************************************************************************************************
 Function name    : Com_Prv_TxIpduGroupStop
 Description      : Service for stopping the Ipdu's which comes under the Ipdu Group
 Parameter        : idIpduGrp_u16 - I-PDU group id.
 Return value     : None
 **********************************************************************************************************************
*/
LOCAL_INLINE void Com_Prv_TxIpduGroupStop(Com_IpduGroupIdType idIpduGrp_u16)
{

    /* Local pointer which holds the address of the array which stores the ipdu id */
    const Com_IpduId_tuo *      ipduRefPtr_pcuo;
    /* Local pointer to hold the address of Ipdu group structure */
    Com_IpduGrpCfg_tpcst        ipduGrpConstPtr_pcst;
    /* Local pointer to hold the address of Ipdu group structure */
    Com_TxIpduRam_tpst          txIpduRamPtr_pst;
    uint16_least                numOfPdus_qu16;
    uint8                       pduCounterVal_u8;

    pduCounterVal_u8  = COM_ZERO;
    numOfPdus_qu16    = COM_ZERO;

    /* Check if IPduGroup bit is set */
    if(COM_CHECK_IPDUGRP_BIT(idIpduGrp_u16) == COM_ONE)
    {
        /* Clear the IPduGroup bit */
        COM_CLEAR_IPDUGRP_BIT(idIpduGrp_u16);

        /* Store the counter value to 0xFFu */
        pduCounterVal_u8 = (0xFFu);

        ipduGrpConstPtr_pcst = COM_GET_IPDUGRP_CONSTDATA(idIpduGrp_u16);

        ipduRefPtr_pcuo      = COM_GET_IPDUGRP_IPDUREF_CONSTDATA(ipduGrpConstPtr_pcst->idFirstIpdu_u16);

        /* Is current IpduGroup is last member generated in the structure COM_GET_IPDUGRP_CONSTDATA */
        if (idIpduGrp_u16 != (COM_GET_NUM_TOTAL_IPDU_GRP - COM_ONE))
        {
            /* Difference between the current IPduGroup Index to the next Index provides
             * the total number of Pdus referred to the IPduGroup. */
            numOfPdus_qu16 = (ipduGrpConstPtr_pcst + COM_ONE)->idFirstIpdu_u16 - ipduGrpConstPtr_pcst->idFirstIpdu_u16;
        }
        else
        {
            /* In case,current IPduGroup is the last member in the generated table, then the total number
             * of Pdus are stored in the separate pre-processor directive */
            numOfPdus_qu16 = COM_GET_NUM_IPDUS_IN_LAST_IPDUGRP;
        }

        while (numOfPdus_qu16 > COM_ZERO)
        {
            txIpduRamPtr_pst = &COM_GET_TXPDURAM_S(*ipduRefPtr_pcuo - (COM_GET_NUM_RX_IPDU));

            /* Below counter shall decrement if latest state is stopped */
            COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) =
            (uint8)(COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) + pduCounterVal_u8);

            /* If any of the Ipdu Group containing the IPdu is active,
             * i.e., counter will have non-zero value */
            if (COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) == COM_ZERO)
            {
                /* If the PDU state is changed from START to STOP */
                if (Com_GetRamValue(TXIPDU,_PDUSTATUS,txIpduRamPtr_pst->txFlags_u16))
                {
                    /* NOTE: This below order is to be maintained, to avoid any interrupt related race conditions.
                     * REASON: If the below function call is interrupted, by any other API,
                     * as the _PDUSTATUS is set before the function call,
                     * the interrupting API returns without any effect */
                    Com_SetRamValue(TXIPDU,_PDUSTATUS,txIpduRamPtr_pst->txFlags_u16,COM_STOP);

                    Com_Prv_TxIPduStop((Com_IpduId_tuo)(*ipduRefPtr_pcuo - (COM_GET_NUM_RX_IPDU)));
                }
            }
            txIpduRamPtr_pst++;
            ipduRefPtr_pcuo++;
            numOfPdus_qu16--;
        }/* while (numOfPdus_qu16 > 0 ) */
    }
}


/*
 **********************************************************************************************************************
 Function name    : Com_Prv_RxIpduGroupStop
 Description      : Service for stopping the Ipdu's which comes under the Ipdu Group
 Parameter        : idIpduGrp_u16 - I-PDU group id.
 Return value     : None
 **********************************************************************************************************************
*/
LOCAL_INLINE void Com_Prv_RxIpduGroupStop(Com_IpduGroupIdType idIpduGrp_u16)
{

    /* Local pointer which holds the address of the array which stores the ipdu id */
    const Com_IpduId_tuo *      ipduRefPtr_pcuo;
    /* Local pointer to hold the address of Ipdu group structure */
    Com_IpduGrpCfg_tpcst        ipduGrpConstPtr_pcst;
    Com_RxIpduRam_tpst          rxIpduRamPtr_pst;
    uint16_least                numOfPdus_qu16;
    uint8                       pduCounterVal_u8;

    pduCounterVal_u8  = COM_ZERO;
    numOfPdus_qu16    = COM_ZERO;

    /* Check if IPduGroup bit is set */
    if(COM_CHECK_IPDUGRP_BIT(idIpduGrp_u16) == COM_ONE)
    {
        /* Clear the IPduGroup bit */
        COM_CLEAR_IPDUGRP_BIT(idIpduGrp_u16);

# if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout)
        Com_Prv_DisableReceptionDM(idIpduGrp_u16);
# endif

        /* Store the counter value to 0xFFu */
        pduCounterVal_u8     = (0xFFu);

        ipduGrpConstPtr_pcst = COM_GET_IPDUGRP_CONSTDATA(idIpduGrp_u16);

        ipduRefPtr_pcuo      = COM_GET_IPDUGRP_IPDUREF_CONSTDATA(ipduGrpConstPtr_pcst->idFirstIpdu_u16);

        /* Is current IpduGroup is last member generated in the structure COM_GET_IPDUGRP_CONSTDATA */
        if (idIpduGrp_u16 != (COM_GET_NUM_TOTAL_IPDU_GRP - COM_ONE))
        {
            /* Difference between the current IPduGroup Index to the next Index provides
             * the total number of Pdus referred to the IPduGroup. */
            numOfPdus_qu16 = (ipduGrpConstPtr_pcst + COM_ONE)->idFirstIpdu_u16 - ipduGrpConstPtr_pcst->idFirstIpdu_u16;
        }
        else
        {
            /* In case,current IPduGroup is the last member in the generated table, then the total number
             * of Pdus are stored in the separate pre-processor directive */
            numOfPdus_qu16 = COM_GET_NUM_IPDUS_IN_LAST_IPDUGRP;
        }

        while (numOfPdus_qu16 > COM_ZERO)
        {
            rxIpduRamPtr_pst = &COM_GET_RXPDURAM_S(*ipduRefPtr_pcuo);

            /* Below counter shall decrement if latest state is stopped */
            COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) =
            (uint8)(COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) + pduCounterVal_u8);

            /* If any of the Ipdu Group containing the IPdu is active,
             * i.e., counter will have non-zero value */
            if (COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) == COM_ZERO)
            {
                /* If the PDU state is changed from START to STOP */
                if (Com_GetRamValue(RXIPDU,_PDUSTATUS,rxIpduRamPtr_pst->rxFlags_u8))
                {
                    Com_SetRamValue(RXIPDU,_PDUSTATUS,rxIpduRamPtr_pst->rxFlags_u8,COM_STOP);

#ifdef COM_ENABLE_MAINFUNCTION_RX
                    Com_SetRamValue(RXIPDU,_INDICATION,rxIpduRamPtr_pst->rxFlags_u8,COM_FALSE);
#endif

                    /* Large Pdu Rx status is reset, No further calls for this reception are processed */
#ifdef COM_TP_IPDUTYPE
                    Com_SetRamValue(RXIPDU,_LARGEDATAINPROG,rxIpduRamPtr_pst->rxFlags_u8,COM_FALSE);
#endif
                }
            }
            rxIpduRamPtr_pst++;
            ipduRefPtr_pcuo++;
            numOfPdus_qu16--;
        }/* while (numOfPdus_qu16 > 0 ) */
    }
}


#endif /* #if (COM_CONTROL_IPDUGROUPS == STD_ON) */
