
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

#define COM_SET_IPDUGRP_BIT(idIpduGrp)      ((COM_IPDUGROUP_STATUS((idIpduGrp) >> (3u))) |= ((COM_ONE << ((idIpduGrp) % (8u)))))
#define COM_CHECK_IPDUGRP_BIT(idIpduGrp)    (((COM_IPDUGROUP_STATUS((idIpduGrp) >> (3u))) >> ((idIpduGrp) % (8u))) & (COM_ONE))

/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/

LOCAL_INLINE void Com_Prv_TxIpduGroupStart(Com_IpduGroupIdType idIpduGrp_u16, boolean initialize_b);
LOCAL_INLINE void Com_Prv_RxIpduGroupStart(Com_IpduGroupIdType idIpduGrp_u16, boolean initialize_b);

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
 Function name    : Com_IpduGroupStart
 Description      : Service for starting the Ipdu's which comes under the Ipdu Group
 Parameter        : idIpduGrp_u16 - I-PDU group id.
                    initialize_b  - flag to request initialization of the I-PDUs which are newly started
 Return value     : None
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

void Com_IpduGroupStart(Com_IpduGroupIdType idIpduGrp_u16, boolean initialize_b)
{

#if (COM_PRV_ERROR_HANDLING == STD_ON)
    if (Com_InitStatus_en == COM_UNINIT)
    {
        COM_DET_REPORT_ERROR(COMServiceId_IpduGroupStart, COM_E_UNINIT);
    }
    else if (!Com_Prv_IsValidIpduGroupId(idIpduGrp_u16))
    {
        COM_DET_REPORT_ERROR(COMServiceId_IpduGroupStart, COM_E_PARAM);
    }
    else
#endif /* end of COM_PRV_ERROR_HANDLING */
    {
        if(Com_Prv_IsValidTxIpduGroupId(idIpduGrp_u16))
        {
            Com_Prv_TxIpduGroupStart(idIpduGrp_u16, initialize_b);
        }
        else if(Com_Prv_IsValidRxIpduGroupId(idIpduGrp_u16))
        {
            Com_Prv_RxIpduGroupStart(idIpduGrp_u16, initialize_b);
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
 Function name    : Com_Prv_TxIpduGroupStart
 Description      : Service for starting the Ipdu's which comes under the Ipdu Group
 Parameter        : idIpduGrp_u16 - I-PDU group id.
                    initialize_b  - flag to request initialization of the I-PDUs which are newly started
 Return value     : None
 **********************************************************************************************************************
*/
LOCAL_INLINE void Com_Prv_TxIpduGroupStart(Com_IpduGroupIdType idIpduGrp_u16, boolean initialize_b)
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

    /* Check if IPduGroup bit is already set */
    if(COM_CHECK_IPDUGRP_BIT(idIpduGrp_u16) == COM_ONE)
    {
        /* Do nothing: As IPduGroup is already started */
    }
    else
    {
        /* Set the IPduGroup bit */
        COM_SET_IPDUGRP_BIT(idIpduGrp_u16);

        /* Store the counter value to 0x01u */
        pduCounterVal_u8     = (COM_ONE);

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
            /* Below counter shall increment if latest state is started */
            COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) =
            (uint8)(COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) + pduCounterVal_u8);

            txIpduRamPtr_pst = &COM_GET_TXPDURAM_S(*ipduRefPtr_pcuo - (COM_GET_NUM_RX_IPDU));

            /* If the PDU state is changed from STOP to START */
            if (Com_GetRamValue(TXIPDU,_PDUSTATUS,txIpduRamPtr_pst->txFlags_u16) == COM_STOP)
            {
                /* NOTE: This below order is to be maintained, to avoid any interrupt related race conditions.
                 * REASON: If the below function call is interrupted, by any other API,
                 * as the _PDUSTATUS is set after the function returns,
                 * the interrupting API returns without any effect */
                Com_Prv_TxIPduStart((Com_IpduId_tuo)(*ipduRefPtr_pcuo - (COM_GET_NUM_RX_IPDU)),initialize_b);

                Com_SetRamValue(TXIPDU,_PDUSTATUS,txIpduRamPtr_pst->txFlags_u16,COM_START);
            }
            txIpduRamPtr_pst++;
            ipduRefPtr_pcuo++;
            numOfPdus_qu16--;
        }/* while (numOfPdus_qu16 > 0 ) */
    }
}


/*
 **********************************************************************************************************************
 Function name    : Com_Prv_RxIpduGroupStart
 Description      : Service for starting the Ipdu's which comes under the Ipdu Group
 Parameter        : idIpduGrp_u16 - I-PDU group id.
                    initialize_b  - flag to request initialization of the I-PDUs which are newly started
 Return value     : None
 **********************************************************************************************************************
*/
LOCAL_INLINE void Com_Prv_RxIpduGroupStart(Com_IpduGroupIdType idIpduGrp_u16, boolean initialize_b)
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

    /* Check if IPduGroup is already set */
    if(COM_CHECK_IPDUGRP_BIT(idIpduGrp_u16) == COM_ONE)
    {
        /* Do nothing: As IPduGroup is already started */
    }
    else
    {
        /* Set the IPduGroup bit */
        COM_SET_IPDUGRP_BIT(idIpduGrp_u16);

# if defined (COM_RxIPduTimeout) || defined (COM_RxSigUpdateTimeout) || defined (COM_RxSigGrpUpdateTimeout)
        /* Invoked enabling reception deadline monitoring */
        Com_Prv_EnableReceptionDM(idIpduGrp_u16);
# endif

        /* Store the counter value to 0x01u */
        pduCounterVal_u8     = (COM_ONE);

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
            /* Below counter shall increment if latest state is started */
            COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) =
            (uint8)(COM_GET_IPDUCOUNTER_S(*ipduRefPtr_pcuo) + pduCounterVal_u8);

            rxIpduRamPtr_pst = &COM_GET_RXPDURAM_S(*ipduRefPtr_pcuo);

            /* If the PDU state is changed from STOP to START */
            if (Com_GetRamValue(RXIPDU,_PDUSTATUS,rxIpduRamPtr_pst->rxFlags_u8) == COM_STOP)
            {
                 Com_Prv_RxIPduStart((Com_IpduId_tuo)(*ipduRefPtr_pcuo),initialize_b);

                 Com_SetRamValue(RXIPDU,_PDUSTATUS,rxIpduRamPtr_pst->rxFlags_u8,COM_START);
            }
            rxIpduRamPtr_pst++;
            ipduRefPtr_pcuo++;
            numOfPdus_qu16--;
        }/* while (numOfPdus_qu16 > 0 ) */
    }
}


#endif /* #if (COM_CONTROL_IPDUGROUPS == STD_ON) */
