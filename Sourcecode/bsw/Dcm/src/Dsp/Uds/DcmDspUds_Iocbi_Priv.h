
#ifndef DCMDSPUDS_IOCBI_PRIV_H
#define DCMDSPUDS_IOCBI_PRIV_H


#if (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
/* Minimum request length of IOCBI service excluding SID */
/* 2 bytes - DID; 1 byte - InputOutputControlParameter */
#define DSP_IOCBI_MINREQLEN           0x03u

#define DCM_IOCBI_RETURNCONTROLTOECU  0x0u
#define DCM_IOCBI_RESETTODEFAULT      0x1u
#define DCM_IOCBI_FREEZECURRENTSTATE  0x2u
#define DCM_IOCBI_SHORTTERMADJUSTMENT 0x3u



/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/
typedef enum
{
    DCM_IOCBI_PROCESS = 0x01u,
    DCM_IOCBI_RESPONSE
}Dcm_ProcessStates_ten;


typedef enum
{
    DCM_IOCBI_CHECKSESSION = 0x01u,
    DCM_IOCBI_CHECKLENGTH,
    DCM_IOCBI_CHECKSECURITY,
    DCM_IOCBI_CHECKMODERULE
}Dcm_ValidationStates_ten;


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/
extern Std_ReturnType Dcm_ProcessIOResult;
extern uint16 Dcm_dataSignalLength_u16;
extern uint8 Dcm_ControlParameter_u8;
extern uint16 Dcm_ReadSignalLength_u16;
extern const Dcm_ExtendedDIDConfig_tst * ptrDidExtendedConfig;
extern const Dcm_DIDConfig_tst * ptrDidConfig;
extern Dcm_DIDIndexType_tst Dcm_idxIocbiDidIndexType_st;
extern Dcm_OpStatusType Dcm_DspIocbiOpStatus;

#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
extern boolean Dcm_IocbiRteCallPlaced_b;
#endif

#if (DCM_CFG_DSP_READ_ASP_ENABLED != DCM_CFG_OFF)
extern boolean Dcm_IocbiReadLengthRteCallPlaced_b;
#endif


#if(DCM_CFG_DSP_NUMISDIDAVAIL>0)
extern boolean Dcm_Prv_CheckVariant(const Dcm_MsgContextType* pMsgContext,Dcm_DIDIndexType_tst Dcm_IocbiDidIndexType_st);
#endif

extern void Dcm_Prv_UpdateStatusArray(Std_ReturnType retValGetDid);
extern boolean Dcm_Prv_CheckIoControl(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType *ErrorCode);
extern Std_ReturnType Dcm_Prv_CheckTotalLength(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode);
extern Std_ReturnType Dcm_Prv_CheckCondition(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode);
extern Std_ReturnType Dcm_Prv_ProcessWithInternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode);
extern Std_ReturnType Dcm_Prv_ProcessWithExternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode);
extern Std_ReturnType Dcm_Prv_IocbiInitExternalMask(void);
extern Std_ReturnType Dcm_Prv_IocbiInitInternalMask(void);
extern Std_ReturnType Dcm_GetLengthOfSignal (uint16 * dataSigLength_u16);

#endif /* #if (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF) */

#endif /* #ifndef _DCMDSPUDS_IOCBI_PRIV_H */
