
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "Com_Prv.h"
#include "Com_Prv_Inl.h"

#ifdef COM_METADATA_SUPPORT

#if defined(COM_RX_DYNAMIC_SIGNAL_SUPPORT) || defined(COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT)
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/

#ifdef COM_RX_DYNAMIC_SIGNAL_SUPPORT
LOCAL_INLINE uint8 Com_Prv_ReceiveDynSignalWithMetaData(Com_SignalIdType idSignal_u16, void* signalDataPtr_pv,
                                                                uint16 * lengthPtr_pu16, uint8 * metaDataPtr_pu8);
#endif

#ifdef COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT
LOCAL_INLINE uint8 Com_Prv_ReceiveDynGroupSignalWithMetaData(Com_SignalIdType idSignal_u16, void * signalDataPtr_pv,
                                                                     uint16 * lengthPtr_pu16, uint8 * metaDataPtr_pu8);
#endif

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
 Function name    : Com_ReceiveDynSignalWithMetaData
 Description      : Service for receiving the signal, This API copies the data to the application buffer
 Parameter        : idSignal_u16            -> Id of the Signal
                  : signalDataPtr_pv        -> Pointer to the address where signal data needs to be copied.
                  : lengthPtr_pu16          -> Pointer to length of the recieved length.
                  : metaDataPtr_pu8         -> Received meta data is stored at the position given by metadataptr.
 Return value     : E_OK/E_NOT_OK/COM_SERVICE_NOT_AVAILABLE
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* MR12 RULE 8.13 VIOLATION: A pointer parameter(SignalDataPtr) in a function prototype should be declared as pointer
   to const if the pointer is not used to modify the addressed object. But AUTOSAR SWS specification signature is
   as below, hence suppressed */
uint8 Com_ReceiveDynSignalWithMetaData(Com_SignalIdType idSignal_u16, void * signalDataPtr_pv, uint16 * lengthPtr_pu16,
                                                                                               uint8 * metaDataPtr_pu8)
{

    uint8                       status_u8;        /* Return status */

    /* Returns with COM_SERVICE_NOT_AVAILABLE when IPDU Group is Stopped or
     * DET error occurs or when Type of the signal is not configured with UINT8_DYN */
    status_u8 = COM_SERVICE_NOT_AVAILABLE;

# if (COM_PRV_ERROR_HANDLING == STD_ON)
    if (Com_InitStatus_en == COM_UNINIT)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignalWithMetaData, COM_E_UNINIT);
    }
    else if ((signalDataPtr_pv == NULL_PTR) || (lengthPtr_pu16 == NULL_PTR) || (metaDataPtr_pu8 == NULL_PTR))
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignalWithMetaData, COM_E_PARAM_POINTER);
    }
    else
# endif /* end of COM_PRV_ERROR_HANDLING */
#ifdef COM_RX_DYNAMIC_SIGNAL_SUPPORT
    /* Check for dynamic signal */
    if(Com_Prv_IsValidRxSignalId(idSignal_u16))
    {
        status_u8 = Com_Prv_ReceiveDynSignalWithMetaData(idSignal_u16, signalDataPtr_pv, lengthPtr_pu16, metaDataPtr_pu8);
    }
    else
#endif
#ifdef COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT
    /* Check for dynamic group signal */
    if(Com_Prv_IsValidRxGroupSignalId(idSignal_u16))
    {
        status_u8 = Com_Prv_ReceiveDynGroupSignalWithMetaData(idSignal_u16, signalDataPtr_pv, lengthPtr_pu16, metaDataPtr_pu8);
    }
    else
#endif
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignalWithMetaData, COM_E_PARAM);
    }

    return(status_u8);
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


#ifdef COM_RX_DYNAMIC_SIGNAL_SUPPORT
/*
 **********************************************************************************************************************
 Function name    : Com_Prv_ReceiveDynSignalWithMetaData
 Description      : Service for receiving the dynamic signal, This API copies the data to the application buffer
 Parameter        : idSignal_u16        -> Id of the Signal
                  : signalDataPtr_pv    -> Pointer to the address where signal data needs to be copied.
                  : lengthPtr_pu16      -> Pointer to length of the received length.
                  : metaDataPtr_pu8     -> Received meta data is stored at the position given by metadataptr.
 Return value     : E_OK/E_NOT_OK/COM_SERVICE_NOT_AVAILABLE
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* MR12 RULE 8.13 VIOLATION: A pointer parameter(signalDataPtr_pv) in a function prototype should be declared as pointer
   to const if the pointer is not used to modify the addressed object. But AUTOSAR SWS specification signature is
   as below, hence suppressed */
LOCAL_INLINE uint8 Com_Prv_ReceiveDynSignalWithMetaData(Com_SignalIdType idSignal_u16, void* signalDataPtr_pv,
                                                                uint16 * lengthPtr_pu16, uint8 * metaDataPtr_pu8)
{

    Com_RxIpduCfg_tpcst         rxIpduConstPtr_pcst;
    Com_RxSigCfg_tpcst          rxSigConstPtr_pcst; /* Local pointer holds the address of Rx signal static configuration */
    PduIdType                   idIpdu_uo;
    uint8                       status_u8;        /* Return status */

    /* Initialize variable */
    status_u8  = COM_SERVICE_NOT_AVAILABLE;

    /* If PB variant is selected, then PduId which is passed to this function will be changed
     * to internal Id which is generated through configuration
     * If PC variant is selected, then no mapping table will be used. */
    idSignal_u16        = COM_GET_RXSIGNAL_ID(idSignal_u16);

    rxSigConstPtr_pcst  = COM_GET_RXSIG_CONSTDATA(idSignal_u16);
    idIpdu_uo           = rxSigConstPtr_pcst->idComIPdu_uo;
    rxIpduConstPtr_pcst = COM_GET_RX_IPDU_CONSTDATA(idIpdu_uo);

    status_u8 = Com_Prv_ReceiveDynSignal(idSignal_u16, signalDataPtr_pv, lengthPtr_pu16);

    /* Check if received signal is part of metadata I-PDU */
    if(Com_GetValue(RXIPDU,_IS_METADATAPDU,rxIpduConstPtr_pcst->rxIPduFields_u8)
       && (status_u8 == E_OK))
    {
        SchM_Enter_Com_RxIpduProtArea(RECEIVE_METADATA);

        /* Copy the given RxMetaData internal buffer to Metadata pointer */
        Com_ByteCopy(metaDataPtr_pu8,
                    (COM_GET_RXMETADATA(idIpdu_uo)->rxMetaDataValue_pau8),
                     COM_GET_RXMETADATA(idIpdu_uo)->rxMetaDataLength_u8);

        SchM_Exit_Com_RxIpduProtArea(RECEIVE_METADATA);
    }

    return(status_u8);
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#endif /* #ifdef COM_RX_DYNAMIC_SIGNAL_SUPPORT */

#ifdef COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT
/*
 **********************************************************************************************************************
 Function name    : Com_Prv_ReceiveDynGroupSignalWithMetaData
 Description      : Service for receiving the dynamic group signal, This API copies the data to the application buffer
 Parameter        : idSignal_u16        -> Id of the Signal
                  : signalDataPtr_pv    -> Pointer to the address where group signal data needs to be copied.
                  : lengthPtr_pu16      -> Pointer to length of the received length.
                  : metaDataPtr_pu8     -> Received meta data is stored at the position given by metadataptr.
 Return value     : E_OK/E_NOT_OK/COM_SERVICE_NOT_AVAILABLE
 **********************************************************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* MR12 RULE 8.13 VIOLATION: A pointer parameter(signalDataPtr_pv) in a function prototype should be declared as pointer
   to const if the pointer is not used to modify the addressed object. But AUTOSAR SWS specification signature is
   as below, hence suppressed */
LOCAL_INLINE uint8 Com_Prv_ReceiveDynGroupSignalWithMetaData(Com_SignalIdType idSignal_u16, void * signalDataPtr_pv,
                                                                     uint16 * lengthPtr_pu16, uint8 * metaDataPtr_pu8)
{

    Com_RxIpduCfg_tpcst             rxIpduConstPtr_pcst;
    /* Local pointer holds the address of Rx group signal static configuration */
    Com_RxGrpSigCfg_tpcst           rxGrpSigConstPtr_pcst;
    PduIdType                       idIpdu_uo;
    Com_SignalIdType                idGrpSignal_u16;
    uint8                           status_u8;        /* Return status */

    /* Initialize variable */
    status_u8               = COM_SERVICE_NOT_AVAILABLE;

    /* If PB variant is selected, then PduId which is passed to this function will be changed
     * to internal Id which is generated through configuration
     * If PC variant is selected, then no mapping table will be used. */
    idGrpSignal_u16         = COM_GET_RXGRPSIGNAL_ID(idSignal_u16);
    rxGrpSigConstPtr_pcst   = COM_GET_RXGRPSIG_CONSTDATA(idGrpSignal_u16);
    idIpdu_uo               = COM_GET_RXSIGGRP_CONSTDATA(rxGrpSigConstPtr_pcst->idSigGrp_uo)->idComIPdu_uo;
    rxIpduConstPtr_pcst     = COM_GET_RX_IPDU_CONSTDATA(idIpdu_uo);

    status_u8 = Com_Prv_ReceiveDynGroupSignal(idSignal_u16, signalDataPtr_pv, lengthPtr_pu16);

    /* Check if received signal is part of metadata I-PDU */
    if(Com_GetValue(RXIPDU,_IS_METADATAPDU,rxIpduConstPtr_pcst->rxIPduFields_u8)
       && (status_u8 == E_OK))
    {
        SchM_Enter_Com_RxIpduProtArea(RECEIVE_METADATA);

        /* Copy the given RxMetaData internal buffer to Metadata pointer */
        Com_ByteCopy(metaDataPtr_pu8,
                    (COM_GET_RXMETADATA(idIpdu_uo)->rxMetaDataValue_pau8),
                     COM_GET_RXMETADATA(idIpdu_uo)->rxMetaDataLength_u8);

        SchM_Exit_Com_RxIpduProtArea(RECEIVE_METADATA);
    }

    return(status_u8);
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* #ifdef COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT */

#endif /* #if defined(COM_RX_DYNAMIC_SIGNAL_SUPPORT) || defined(COM_RX_DYNAMIC_GROUPSIGNAL_SUPPORT) */

#endif /* #ifdef COM_METADATA_SUPPORT */
