#ifndef DCM_PRV_DSD_H
#define DCM_PRV_DSD_H

/*
 ***************************************************************************************************
 *    Internal DCM Type definitions
 ***************************************************************************************************
 */


/*
 **********************************************************************************************************************
 *  DSD Structures
 **********************************************************************************************************************
 */




/*
 **********************************************************************************************************************
 *  Defines
 **********************************************************************************************************************
 */
#define DCM_SUBFUNC_INDEX                                           0x01u
#define DCM_REMOVESUPPRESSRESPONSEBIT_MASK                          0x7Fu
#define DCM_REMOVEEVENTSTORAGEBIT_MASK                              0xBFu
#define DCM_SID_INDEX                                               0x00u
#define DCM_REQUESTWITHOUT_SID                                      0x00u
#define DCM_DEFAULT_VALUE                                           0x00u
#define DCM_RESPONSEBUFFER_INDEX                                    0x03u

#define DCM_DEFAULT_VALUE                   0x00u
#define DCM_SERVICE_ISO_LOWERLIMIT          0x40u
#define DCM_SERVICE_ISO_MIDLIMIT            0x7Fu
#define DCM_SERVICE_ISO_UPPERLIMIT          0xC0u
#define DCM_SID_LENGTH                      0x01u   /* Length of SID for any request */
#define DCM_REQUESTBUFFER_INDEX             0x00u   /* Index from where the Request data is to be considered  */
/* Mask value which will be varied depending on active session/security */
#define DCM_DEFAULT_MASKVALUE               0x00000001uL
#define DCM_RESPONSEBUFFER_INDEX            0x03u   /* Index from where the Response is to be updated*/

/*
 **********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************
 */
extern void Dcm_Dsd_Init(const Dcm_ConfigType* ConfigPtr);
extern void Dcm_Dsd_Main(void);
void Dcm_Dsd_Prv_StateMachine(void);

extern void Dcm_Dsd_Prv_SendTx_Confirmation(void);

const Dcm_DsdServiceTableConfigType_tst* Dcm_Prv_GetServiceTable(void);
const Dcm_DsdServicePBConfigType_tst** Dcm_Dsd_Prv_GetPBServiceTable(void);

Std_ReturnType Dcm_Dsd_Prv_Verification(const Dcm_MsgContextType *dcm_MsgContext_pst,
        Dcm_NegativeResponseCodeType *negativeResponseCode);
void Dcm_Dsd_Prv_AssembleResponse(Std_ReturnType Result_u8, Dcm_NegativeResponseCodeType ErrorCode_u8);
void Dcm_Dsd_Prv_Confirmation(Std_ReturnType Transmissonresult);

#if ((DCM_CFG_MANUFACTURERNOTIFICATION_NUM_PORTS!=0u)||(DCM_CFG_SUPPLIERNOTIFICATION_NUM_PORTS!=0))
extern void Dcm_Dsd_Prv_CallRTEConfirmation(Dcm_ConfirmationStatusType confirmationStatus_u8, uint16 TesterSourceAddress, boolean Context);
#endif

void Dcm_Dsd_Prv_CancelService(void);
void Dcm_Dsd_Prv_SetDsdState(Dcm_DsdStatesType_ten dsdState_en);
Dcm_DsdStatesType_ten Dcm_Dsd_Prv_GetDsdState(void);
Dcm_IdContextType Dcm_Dsd_Prv_GetIdContext(void);
Dcm_MsgLenType Dcm_Dsd_Prv_GetRespLength(void);
Dcm_MsgLenType Dcm_Dsd_Prv_GetRespMaxLength(void);
boolean Dcm_Dsd_Prv_GetsuppressPosResponse(void);
void Dcm_Dsd_Prv_ResetsuppressPosResponse(void);
uint8 Dcm_Dsd_Prv_GetReqType(void);
PduIdType Dcm_Dsd_Prv_GetdcmRxPduId(void);
Dcm_MsgContextType Dcm_Dsd_Prv_GetUdsMsgContext(void);
uint8 Dcm_Dsd_Prv_GetSourceofReq(void);
void Dcm_Dsd_Prv_SetSourceofReq(uint8 RequestSource);
void Dcm_Dsd_Prv_ResetAfterProcessingTesterRequest(void);

void Dcm_Prv_SetResponsebyDSD(boolean ResponsebyDSD);
boolean Dcm_Prv_GetResponsebyDSD(void);
void Dcm_Prv_SetResponsetype(Dcm_DsdResponseType_ten Responsetype);
Dcm_DsdResponseType_ten Dcm_Prv_GetResponsetype(void);
PduLengthType Dcm_Prv_GetActiveResponseLength(void);
void Dcm_Dsd_Prv_ServiceInit(uint8 ServiceTableIndex_u8);
void Dcm_Prv_SetRoeProtocolPduid(PduIdType RxpduId);
PduIdType Dcm_Prv_GetRoeProtocolPduid(void);

void Dcm_Prv_SetServiceTable(uint8 srvTabId);
#endif
