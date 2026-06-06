#ifndef DCM_PRV_DSL_RECEPTION_H
#define DCM_PRV_DSL_RECEPTION_H


/* Tester Present bytes */
#define DCM_DSLD_PARALLEL_TPR_BYTE1                    0x3eu
#define DCM_DSLD_PARALLEL_TPR_BYTE2                    0x80u
#define DCM_DSLD_PARALLEL_DCM_TPR_REQ_LENGTH           0x02u
#define DCM_HIGHPRIORITYREQUEST_NOT_PRESENT            0xFFu
#define DCM_NEGATIVE_LENGTH_RESPONSE                   0x03u
#define DCM_DEFAULT_SERVICEID                          0xFFu

/* OBD service Ids */
#define DCM_OBDSERVICEID_0x01                        (0x01u)
#define DCM_OBDSERVICEID_0x0A                        (0x0Au)

/*
 **********************************************************************************************************************
 *  Variables and structure
 **********************************************************************************************************************
 */
typedef struct
{
#if(DCM_BUFQUEUE_ENABLED != DCM_CFG_OFF)
    Dcm_MsgType  Dcm_DslBufferPtr_pu8;        /* pointer to hold the address of the normal buffer(non-queue) */
#endif
    boolean Dcm_FuncTesterPresent_b;
    boolean Dcm_RequestProcessingFlag_b;
    PduIdType Dcm_RxPduId;
    uint8 Dcm_ServiceId_u8;
}Dcm_RequestInfoType_tst;
extern Dcm_RequestInfoType_tst Dcm_ReceptionInfo_ast[DCM_CFG_TOTAL_RX_PDUID];
extern PduInfoType  Dcm_PduInfo_ast[DCM_CFG_TOTAL_RX_PDUID];

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern PduIdType Dcm_HighPriorityPduId_u8;
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/***********************************************************************************************************************
 *    Inline Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
void Dcm_Prv_SetLowPrioNrc21RxPduId(PduIdType DcmRxPduId);
PduIdType Dcm_Prv_GetLowPrioNrc21RxPduId(void);
PduLengthType Dcm_Prv_Get_CurrentRequestLength(void);
void Dcm_Prv_Set_CurrentRequestLength(PduLengthType currentrequestlength);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetServiceId
 Syntax           : void Dcm_Prv_SetServiceId (uint8 Dcm_ServiceId , PduIdType DcmRxPduId)
 Description      : This Function is used to set the serviceId
 Parameter        : uint8,PduIdType
 Return value     : void
 ***********************************************************************************************************************/

LOCAL_INLINE void Dcm_Prv_SetServiceId (uint8 Dcm_ServiceId , PduIdType DcmRxPduId)
{
    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_ServiceId_u8=Dcm_ServiceId;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_GetServiceId
 Syntax           : uint8 Dcm_Prv_GetServiceId (PduIdType DcmRxPduId)
 Description      : This Function is used to get the serviceId
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/

LOCAL_INLINE uint8 Dcm_Prv_GetServiceId (PduIdType DcmRxPduId)
{
    return Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_ServiceId_u8;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_GetRequestProcessingFlag
 Syntax           : boolean Dcm_Prv_GetRequestProcessingFlag ( PduIdType DcmRxPduId)
 Description      : This Function is used to get the requestprocessing flag status
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/

LOCAL_INLINE boolean Dcm_Prv_GetRequestProcessingFlag ( PduIdType DcmRxPduId)
{
    return Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_RequestProcessingFlag_b;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetHighPrioPduid
 Syntax           : void Dcm_Prv_SetHighPrioPduid ( PduIdType RxpduId)
 Description      : This Function is used to set the Highprio PduId
 Parameter        : PduIdType
 Return value     : void
 ***********************************************************************************************************************/

LOCAL_INLINE void Dcm_Prv_SetHighPrioPduid ( PduIdType RxpduId)
{
    Dcm_HighPriorityPduId_u8=RxpduId;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_GetFunctionalTPStatusFlag
 Syntax           : boolean Dcm_Prv_GetFunctionalTPStatusFlag (PduIdType DcmRxPduId)
 Description      : This Function is used to get functional testerpresent status
 Parameter        : PduIdType
 Return value     : boolean
 ***********************************************************************************************************************/

LOCAL_INLINE boolean Dcm_Prv_GetFunctionalTPStatusFlag (PduIdType DcmRxPduId)
{
    return Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_FuncTesterPresent_b;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_GetHighPrioPduid
 Syntax           : void Dcm_Prv_GetHighPrioPduid (void)
 Description      : This Function is used to get the Highprio PduId
 Parameter        : void
 Return value     : PduIdType
 ***********************************************************************************************************************/
LOCAL_INLINE PduIdType Dcm_Prv_GetHighPrioPduid(void)
{
    return Dcm_HighPriorityPduId_u8;
}

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetFunctionalTPStatusFlag
 Syntax           : void Dcm_Prv_SetFunctionalTPStatusFlag (PduIdType DcmRxPduId  , boolean value )
 Description      : This Function is used to set the functional testerpresent flag
 Parameter        : PduIdType,boolean
 Return value     : void
 ***********************************************************************************************************************/

LOCAL_INLINE void Dcm_Prv_SetFunctionalTPStatusFlag (PduIdType DcmRxPduId  , boolean value )
{
    Dcm_ReceptionInfo_ast[DcmRxPduId].Dcm_FuncTesterPresent_b=value;
}

LOCAL_INLINE boolean Dcm_Prv_isRequestReceivedOnOtherConnection(PduIdType DcmRxPduId)
{
    boolean returnstatus_b;
    returnstatus_b=FALSE;
    if(Dcm_Prv_GetConnectionIndex(DcmRxPduId) != Dcm_Prv_GetConnectionIndex(Dcm_Prv_GetActiveRxPduId()))
    {
        returnstatus_b=TRUE;
    }
    return returnstatus_b;
}

#if(DCM_CFG_RXPDU_SHARING_ENABLED == DCM_CFG_ON)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isRxPduShared
 Syntax           : Dcm_Prv_isRxPduShared(DcmRxPduId,ServiceId)
 Description      : This Inline function is used to check whether pduid is shared between OBD and UDS
 Parameter        : PduIdType ,uint8
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE boolean Dcm_Prv_isRxPduShared(PduIdType DcmRxPduId, uint8 ServiceId)
{
    return((DcmRxPduId < (DCM_CFG_TOTAL_RX_PDUID-1u)) && (DcmRxPduId == DCM_CFG_SHARED_RX_PDUID) && \
            (ServiceId >= DCM_OBDSERVICEID_0x01) && (ServiceId <= DCM_OBDSERVICEID_0x0A));

}
#endif


#endif
