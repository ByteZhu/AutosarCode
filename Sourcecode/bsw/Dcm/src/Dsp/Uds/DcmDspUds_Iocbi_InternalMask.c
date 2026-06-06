
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Iocbi_Inf.h"
#include "Dcm_Prv.h"
#include "DcmDspUds_Iocbi_Priv.h"


/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"



Std_ReturnType Dcm_Prv_IocbiInitInternalMask(void)
{
    Std_ReturnType Result = E_NOT_OK;
    void * ptrIOCBIFnc = NULL_PTR;

    const Dcm_DataInfoConfig_tst *ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    const Dcm_SignalDIDSubStructConfig_tst *ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

    if(ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER)
    {
#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
        if(ptrSigConfig->UseAsynchronousServerCallPoint_b)
        {
            switch(Dcm_ControlParameter_u8)
            {
               case DCM_IOCBI_SHORTTERMADJUSTMENT:
                   ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(ShortTermAdjustment9_pfct)(ptrIOCBIFnc)) (NULL_PTR,DCM_CANCEL);
                  break;

               case DCM_IOCBI_FREEZECURRENTSTATE:
                   ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(FreezeCurrentState9_pfct)(ptrIOCBIFnc)) (DCM_CANCEL);
                  break;

               case DCM_IOCBI_RESETTODEFAULT:
                   ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(ResetToDefault9_pfct) (ptrIOCBIFnc))(DCM_CANCEL);
                  break;

               default:
                   Result = E_NOT_OK;
                   break;
            }
        }
        else
#endif
        {
            switch(Dcm_ControlParameter_u8)
            {
               case DCM_IOCBI_SHORTTERMADJUSTMENT:
                   ptrIOCBIFnc           = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(ShortTermAdjustment2_pfct)(ptrIOCBIFnc))  (NULL_PTR,DCM_CANCEL, NULL_PTR);
                  break;

               case DCM_IOCBI_FREEZECURRENTSTATE:
                   ptrIOCBIFnc          = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState2_pfct)(ptrIOCBIFnc))(DCM_CANCEL,NULL_PTR);
                  break;

               case DCM_IOCBI_RESETTODEFAULT:
                   ptrIOCBIFnc           = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(ResetToDefault2_pfct) (ptrIOCBIFnc))(DCM_CANCEL, NULL_PTR);
                  break;

               default:
                   Result = E_NOT_OK;
                   break;
            }
        }
    }

    return Result;
}




static Std_ReturnType Dcm_ExecuteIoFunctionality_InternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    void * ptrIOCBIFnc = NULL_PTR;
    Std_ReturnType Result = E_NOT_OK;
    const Dcm_DataInfoConfig_tst * ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];


    switch(ptrSigConfig->usePort_u8)
    {
        case USE_DATA_SYNCH_CLIENT_SERVER :
            switch(Dcm_ControlParameter_u8)
            {
                case DCM_IOCBI_SHORTTERMADJUSTMENT:
                    ptrIOCBIFnc           = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                    Result = (*(ShortTermAdjustment1_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN+Dcm_ReadSignalLength_u16)],ErrorCode);
                    break;

                case DCM_IOCBI_FREEZECURRENTSTATE:
                    ptrIOCBIFnc          = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                    Result=(*(FreezeCurrentState1_pfct)(ptrIOCBIFnc)) (ErrorCode);
                   break;

                case DCM_IOCBI_RESETTODEFAULT:
                    ptrIOCBIFnc           = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                    Result = (*(ResetToDefault1_pfct)(ptrIOCBIFnc)) (ErrorCode);
                   break;

                default:
                    Result = E_NOT_OK;
                    break;
            }
            break;


        case USE_DATA_ASYNCH_CLIENT_SERVER  :
#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
            if(ptrSigConfig->UseAsynchronousServerCallPoint_b)
            {
                switch(Dcm_ControlParameter_u8)
                {
                   case DCM_IOCBI_SHORTTERMADJUSTMENT:
                       if(!Dcm_IocbiRteCallPlaced_b)
                       {
                           ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
                           /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                           Result = (*(ShortTermAdjustment9_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN+Dcm_ReadSignalLength_u16)],Dcm_DspIocbiOpStatus);
                       }
                       else
                       {
                           ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustmentResults_cpv;
                           /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                           Result=(*(ShortTermAdjustment13_pfct)(ptrIOCBIFnc)) (ErrorCode);
                       }
                      break;

                   case DCM_IOCBI_FREEZECURRENTSTATE:
                        if(!Dcm_IocbiRteCallPlaced_b)
                        {
                            ptrIOCBIFnc          = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
                            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                            Result = (*(FreezeCurrentState9_pfct)(ptrIOCBIFnc)) (Dcm_DspIocbiOpStatus);
                        }
                        else
                        {
                            ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentStateResults_cpv;
                            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                            Result = (*(FreezeCurrentState13_pfct)(ptrIOCBIFnc)) (ErrorCode);
                        }
                      break;

                   case DCM_IOCBI_RESETTODEFAULT:
                       if(!Dcm_IocbiRteCallPlaced_b)
                       {
                           ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
                           /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                           Result=(*(ResetToDefault9_pfct)(ptrIOCBIFnc)) (Dcm_DspIocbiOpStatus);
                       }
                       else
                       {
                           ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefaultResults_cpv;
                           /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                           Result=(*(ResetToDefault13_pfct)(ptrIOCBIFnc)) (ErrorCode);
                       }

                      break;

                   default:
                       Result = E_NOT_OK;
                       break;
                }
            }
            else
#endif
            {
                switch(Dcm_ControlParameter_u8)
                {
                   case DCM_IOCBI_SHORTTERMADJUSTMENT:
                       ptrIOCBIFnc           = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(ShortTermAdjustment2_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN+Dcm_ReadSignalLength_u16)],Dcm_DspIocbiOpStatus, ErrorCode);
                      break;

                   case DCM_IOCBI_FREEZECURRENTSTATE:
                       ptrIOCBIFnc          = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(FreezeCurrentState2_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ErrorCode);
                      break;

                   case DCM_IOCBI_RESETTODEFAULT:
                       ptrIOCBIFnc           = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result = (*(ResetToDefault2_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ErrorCode);
                      break;

                   default:
                       Result = E_NOT_OK;
                       break;
                }
            }
            break;

        default:
            Result = E_NOT_OK;
            break;
    }
    return Result;
}




static boolean Dcm_isSignalMasked(const Dcm_MsgContextType * pMsgContext)
{
    boolean retValSignalMasked = FALSE;
    uint8 posnCtlMaskBit_u8 = 0x80;
    uint16 posnSigByte_u16;
    uint8 posnSigBit_u8;
    uint8 posnCtlMaskByte_u8;
    uint16 dataCtlMaskOffset_u16;

    /* Get the start index of the control mask */
    dataCtlMaskOffset_u16 = (uint16)(pMsgContext->reqDataLen - ((uint32)((ptrDidConfig->nrSig_u16-1u)/8u) + 1u));

    if(ptrDidConfig->nrSig_u16 > 1u)
    {
        /*Get the byte position of the signal*/
        posnSigByte_u16 = (uint16)(Dcm_DidSignalIdx_u16/8u);
        /*Get the bit position of the signal*/
        posnSigBit_u8 = (uint8)(Dcm_DidSignalIdx_u16%8u);
        /*Get the control mask value byte*/
        posnCtlMaskByte_u8 = pMsgContext->reqData[dataCtlMaskOffset_u16 + posnSigByte_u16];
        /*Get the control mask bit value for the signal*/
        posnCtlMaskBit_u8 = (uint8)(((uint8)(posnCtlMaskByte_u8 << posnSigBit_u8)) & ((uint8)0x80));
    }

    if(posnCtlMaskBit_u8 == 0x80u)
    {
        retValSignalMasked = TRUE;
    }

    return retValSignalMasked;
}






static Std_ReturnType Dcm_ProcessIoFunctionality_InternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    const Dcm_DataInfoConfig_tst * ptrSigConfig;
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig;
    Std_ReturnType Result = E_NOT_OK;
    void *ptrIOCBIFnc = NULL_PTR;

    ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

    if(DCM_IOCBI_RETURNCONTROLTOECU == Dcm_ControlParameter_u8)
    {
        /*ReturnControlToEcu is Always Synchronous irrespective of Port type*/
        ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrReturnControlEcu_cpv;
        /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
        Result = (*(ReturnControlEcu1_pfct)(ptrIOCBIFnc)) (ErrorCode);
    }
    else
    {
        if((ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_CLIENT_SERVER) || (ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER))
        {
            Result = Dcm_ExecuteIoFunctionality_InternalMask(pMsgContext,ErrorCode);

            #if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
            if (ptrSigConfig->UseAsynchronousServerCallPoint_b)
            {
                if (!Dcm_IocbiRteCallPlaced_b)
                {
                    if(Result == E_OK)
                    {
                        Dcm_IocbiRteCallPlaced_b = TRUE;
                        Result = DCM_E_PENDING;
                    }
                    else
                    {
                        *ErrorCode = DCM_E_GENERALREJECT;
                    }
                }
                else
                {
                    if((Result == E_OK)||(Result == DCM_E_PENDING))
                   {
                       Dcm_IocbiRteCallPlaced_b = FALSE;
                   }
                   else if(Result == RTE_E_NO_DATA)
                   {
                        Result = DCM_E_PENDING;
                   }
                   else
                   {
                       Dcm_IocbiRteCallPlaced_b = FALSE;
                   }
                }
            }
            #endif
        }
    }
    if((Dcm_IsInfrastructureErrorPresent_b(Result) != FALSE) && \
            ((ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_CLIENT_SERVER) || \
                    (ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER)))
    {
        *ErrorCode = DCM_E_GENERALREJECT;
    }
    else
    {
        if(Result == E_OK)
        {
            *ErrorCode = 0;
        }
    }

    return Result;
}




/*TRACE[Ext-4201][Ext-4228]*/
Std_ReturnType Dcm_Prv_ProcessWithInternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    Std_ReturnType Result = E_NOT_OK;

    while((Dcm_DidSignalIdx_u16 < ptrDidConfig->nrSig_u16) && (*ErrorCode==0x0u))
    {
        if(DCM_E_PENDING != Dcm_ProcessIOResult)
        {
            Result = Dcm_GetLengthOfSignal(&Dcm_dataSignalLength_u16);
        }

        if(FALSE != Dcm_isSignalMasked(pMsgContext))
        {
            if((E_OK == Result) || (DCM_E_PENDING == Dcm_ProcessIOResult))
            {
                Result = Dcm_ProcessIoFunctionality_InternalMask(pMsgContext,ErrorCode);
                Dcm_ProcessIOResult = Result;
            }
        }

        if(E_OK == Result)
        {
            Dcm_ReadSignalLength_u16 += Dcm_dataSignalLength_u16;
            Dcm_DspIocbiOpStatus = DCM_INITIAL;
        }
        else if(DCM_E_PENDING == Result)
        {
            break;
        }
        else
        {

            if(*ErrorCode == 0u)
            {
                *ErrorCode = DCM_E_GENERALREJECT;
            }
        }

        Dcm_DidSignalIdx_u16++;
    }

    return Result;
}



#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif      /* #if (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF) */

