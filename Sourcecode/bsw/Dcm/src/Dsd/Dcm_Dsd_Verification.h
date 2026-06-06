#ifndef DCM_DSD_VERIFICATION_H
#define DCM_DSD_VERIFICATION_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Defines
 **********************************************************************************************************************
 */

#if(DCM_CFG_SUPPLIER_NOTIFICATION_ENABLED == DCM_CFG_ON)
#define DCM_SUPPLIER_NOTIFICATION(dcm_MsgContext_pst,negativeResponseCode,Context)  \
        Dcm_SupplierNotification(dcm_MsgContext_pst,negativeResponseCode,Context)
#else
#define DCM_SUPPLIER_NOTIFICATION(dcm_MsgContext_pst,negativeResponseCode,Context)  E_OK
#endif

#if(DCM_CFG_MANUFACTURER_NOTIFICATION_ENABLED == DCM_CFG_ON)
#define DCM_MANUFACTURER_NOTIFICATION(dcm_MsgContext_pst,negativeResponseCode,Context)\
        Dcm_ManufactureNotification(dcm_MsgContext_pst,negativeResponseCode,Context)
#else
#define DCM_MANUFACTURER_NOTIFICATION(dcm_MsgContext_pst,negativeResponseCode,Context)  E_OK
#endif

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3725]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3726]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3145]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4058]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4650]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3722]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3157]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3160]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3161] */
#if(DCM_CFG_SUPPLIER_NOTIFICATION_ENABLED == DCM_CFG_ON)
LOCAL_INLINE Std_ReturnType Dcm_SupplierNotification(const Dcm_MsgContextType *dcm_MsgContext_pst,
        Dcm_NegativeResponseCodeType *negativeResponseCode,boolean Context)

{
    Std_ReturnType notificationResult=E_NOT_OK;
    Dcm_NegativeResponseCodeType FirstIndicationNRC = DCM_DEFAULT_VALUE;
    uint16 connectionId_u16;
    Dcm_ProtocolType protocolType;
    uint16 testerSrcAddress_u16;
    uint8 Reqtype_u8;

#if(DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS!=0)
    Std_ReturnType notificationReturn=E_NOT_OK;
    uint32 portIdx_u32=0;
#endif


#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(Context == DCM_OBDCONTEXT)
    {
        connectionId_u16 = Dcm_Prv_GetObdActiveConnection()->rxConnId_u16;
        protocolType = Dcm_Prv_GetObdActiveProtocolRow()->protocolType;
        testerSrcAddress_u16 = *(Dcm_Prv_GetObdActiveConnection()->rxTesterSrcAddr_pcu16);
        Reqtype_u8 = dcm_MsgContext_pst->msgAddInfo.reqType;
    }
    else
#endif
    {
        connectionId_u16 = Dcm_Prv_GetActiveConnectionId();
        protocolType = Dcm_Prv_GetActiveProtocolType();
        testerSrcAddress_u16 = Dcm_Prv_GetActiveTesterSrcAddress();
        Reqtype_u8 = Dcm_Prv_GetActiveReqType();
    }

    notificationResult = DcmAppl_SupplierNotification(dcm_MsgContext_pst->idContext,
                                                      (const uint8*)&dcm_MsgContext_pst->reqData[DCM_REQUESTWITHOUT_SID],
                                                      dcm_MsgContext_pst->reqDataLen,
                                                      Reqtype_u8,
                                                      connectionId_u16,
                                                      negativeResponseCode,
                                                      protocolType,
                                                      testerSrcAddress_u16);

    if(E_NOT_OK == notificationResult)
    {
        FirstIndicationNRC = *negativeResponseCode;
    }

#if(DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS!=0)
    if(DCM_E_PENDING != notificationResult)
    {
        for(portIdx_u32=0x00u;portIdx_u32<DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS;portIdx_u32++)
        {
            notificationReturn =(*Dcm_Cfg_Dsd_pcst->SupplierNotification_afp[portIdx_u32])
                                                     (dcm_MsgContext_pst->idContext,
                                                      (const uint8*)&dcm_MsgContext_pst->reqData[DCM_REQUESTWITHOUT_SID],
                                                      dcm_MsgContext_pst->reqDataLen,
                                                      Reqtype_u8,
                                                      connectionId_u16,
                                                      negativeResponseCode,
                                                      protocolType,
                                                      testerSrcAddress_u16);

            if((E_NOT_OK == notificationReturn) && (DCM_DEFAULT_VALUE == FirstIndicationNRC))
            {
                FirstIndicationNRC = *negativeResponseCode;
            }

            /* Store the largest value amongst the two
             * DCM_E_REQUEST_NOT_ACCEPTED has highest priority followed by E_NOT_OK*/
            notificationResult = (notificationResult > notificationReturn)?notificationResult:notificationReturn;
        }
    }

    if(E_NOT_OK == notificationResult)
    {
        *negativeResponseCode = FirstIndicationNRC;
    }

    if(notificationResult == DCM_E_REQUEST_NOT_ACCEPTED)
    {
        Dcm_Dsd_Prv_CallRTEConfirmation(DCM_RES_POS_NOT_OK,testerSrcAddress_u16,Context);
    }
#endif

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(Context == DCM_OBDCONTEXT)
    {
        if((notificationResult == E_OK) || (DCM_E_PENDING == notificationResult))
        {
            /* Do nothing */
        }
        else if(notificationResult == DCM_E_REQUEST_NOT_ACCEPTED)
        {
            Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
        }
        else
        {
            Dcm_Prv_OBDDsdSendNegativeResponse(*negativeResponseCode);
        }
    }
#endif

    return notificationResult;
}
#endif


/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3119]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3721]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3722]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3723]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3724]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-4058]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3157]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3158]
 * TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3159] */
#if(DCM_CFG_MANUFACTURER_NOTIFICATION_ENABLED == DCM_CFG_ON)
LOCAL_INLINE Std_ReturnType Dcm_ManufactureNotification(const Dcm_MsgContextType *dcm_MsgContext_pst,
        Dcm_NegativeResponseCodeType *negativeResponseCode,boolean Context)
{
    Std_ReturnType notificationResult=E_NOT_OK;
    Dcm_NegativeResponseCodeType FirstIndicationNRC = DCM_DEFAULT_VALUE;
    uint16 connectionId_u16;
    Dcm_ProtocolType protocolType;
    uint16 testerSrcAddress_u16;
    uint8 Reqtype_u8;

#if(DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS!=0)
    Std_ReturnType notificationReturn=E_NOT_OK;
    uint32 portIdx_u32=0;
#endif

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(Context == DCM_OBDCONTEXT)
    {
        connectionId_u16 = Dcm_Prv_GetObdActiveConnection()->rxConnId_u16;
        protocolType = Dcm_Prv_GetObdActiveProtocolRow()->protocolType;
        testerSrcAddress_u16 = *(Dcm_Prv_GetObdActiveConnection()->rxTesterSrcAddr_pcu16);
        Reqtype_u8 = dcm_MsgContext_pst->msgAddInfo.reqType;
    }
    else
#endif
    {
        connectionId_u16 = Dcm_Prv_GetActiveConnectionId();
        protocolType = Dcm_Prv_GetActiveProtocolType();
        testerSrcAddress_u16 = Dcm_Prv_GetActiveTesterSrcAddress();
        Reqtype_u8 = Dcm_Prv_GetActiveReqType();
    }

    notificationResult = DcmAppl_ManufacturerNotification(dcm_MsgContext_pst->idContext,
                                                          (const uint8*)&dcm_MsgContext_pst->reqData[DCM_REQUESTWITHOUT_SID],
                                                          dcm_MsgContext_pst->reqDataLen,
                                                          Reqtype_u8,
                                                          connectionId_u16,
                                                          negativeResponseCode,
                                                          protocolType,
                                                          testerSrcAddress_u16);

    if(E_NOT_OK == notificationResult)
    {
        FirstIndicationNRC = *negativeResponseCode;
    }

#if(DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS!=0)
    if(DCM_E_PENDING != notificationResult)
    {
        for(portIdx_u32=0x00u;portIdx_u32<DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS;portIdx_u32++)
        {
            notificationReturn =(*Dcm_Cfg_Dsd_pcst->ManufactureNotification_afp[portIdx_u32])
                                                         (dcm_MsgContext_pst->idContext,
                                                          (const uint8*)&dcm_MsgContext_pst->reqData[DCM_REQUESTWITHOUT_SID],
                                                          dcm_MsgContext_pst->reqDataLen,
                                                          Reqtype_u8,
                                                          connectionId_u16,
                                                          negativeResponseCode,
                                                          protocolType,
                                                          testerSrcAddress_u16);

            if((E_NOT_OK == notificationReturn) && (DCM_DEFAULT_VALUE == FirstIndicationNRC))
            {
                FirstIndicationNRC = *negativeResponseCode;
            }

            /* Store the largest value amongst the two
             * DCM_E_REQUEST_NOT_ACCEPTED has highest priority followed by E_NOT_OK*/
            notificationResult = (notificationResult > notificationReturn)?notificationResult:notificationReturn;
        }
    }

    if(E_NOT_OK == notificationResult)
    {
        *negativeResponseCode = FirstIndicationNRC;
    }

    if(notificationResult == DCM_E_REQUEST_NOT_ACCEPTED)
    {
        Dcm_Dsd_Prv_CallRTEConfirmation(DCM_RES_POS_NOT_OK,testerSrcAddress_u16,Context);
    }
#endif

#if (DCM_PARALLELPROCESSING_ENABLED != DCM_CFG_OFF)
    if(Context == DCM_OBDCONTEXT)
    {
        if((notificationResult == E_OK) || (notificationResult == DCM_E_PENDING))
        {
            /* Do nothing */
        }
        else if(notificationResult == DCM_E_REQUEST_NOT_ACCEPTED)
        {
            Dcm_Prv_SetOBDState((DCM_OBD_IDLE));
        }
        else
        {
            Dcm_Prv_OBDDsdSendNegativeResponse(*negativeResponseCode);
        }
    }
#endif

#if (DCM_PARALLELPROCESSING_ENABLED == DCM_CFG_OFF)
    {
        (void)Context;
    }
#endif
    return notificationResult;
}
#endif

/* TRACE[BSW_SWS_AR4_5_R0_DiagnosticCommunicationManager_Ext-3092] */
LOCAL_INLINE Std_ReturnType Dcm_CheckRspAllRqst(uint8 sid_u8)
{
    Std_ReturnType VerificationResult = E_NOT_OK;

#if(DCM_CFG_RESPOND_ALLREQUEST != TRUE)
    if(((sid_u8 >=  DCM_SERVICE_ISO_LOWERLIMIT) && (sid_u8 <= DCM_SERVICE_ISO_MIDLIMIT))||
            (sid_u8 >= DCM_SERVICE_ISO_UPPERLIMIT))
    {
        VerificationResult = DCM_E_REQUEST_NOT_ACCEPTED;
    }
#else
    (void)sid_u8;
#endif

    return VerificationResult;
}

#endif
