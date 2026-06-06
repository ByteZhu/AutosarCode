
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_CONTROLMASK_EXTERNAL_ENABLED != DCM_CFG_OFF)
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

#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
static Std_ReturnType Dcm_Prv_IocbiInitExternalASP(void)
{
    void * ptrIOCBIFnc = NULL_PTR;
    Std_ReturnType Result = E_NOT_OK;

    uint8 ControlMask_u8   = 0u;
    uint16 ControlMask_u16 = 0u;
    uint32 ControlMask_u32 = 0u;

    const Dcm_DataInfoConfig_tst *ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    const Dcm_SignalDIDSubStructConfig_tst *ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];


    switch(Dcm_ControlParameter_u8)
    {
       case DCM_IOCBI_SHORTTERMADJUSTMENT:

              ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
              if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 == 1u)
              {
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result=(*(ShortTermAdjustment10_pfct)(ptrIOCBIFnc)) (NULL_PTR,DCM_CANCEL, ControlMask_u8);
              }
              else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 == 2u)
              {
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result=(*(ShortTermAdjustment11_pfct)(ptrIOCBIFnc)) (NULL_PTR,DCM_CANCEL, ControlMask_u16);
              }
              else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
              {
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result=(*(ShortTermAdjustment12_pfct)(ptrIOCBIFnc)) (NULL_PTR,DCM_CANCEL, ControlMask_u32);
              }
              else
              {
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result = (*(ShortTermAdjustment15_pfct)(ptrIOCBIFnc))(NULL_PTR,DCM_CANCEL,NULL_PTR,NULL_PTR);
              }
          break;

       case DCM_IOCBI_FREEZECURRENTSTATE:

               ptrIOCBIFnc     = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
               if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState10_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u8);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result=(*(FreezeCurrentState11_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u16);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState12_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u32);
               }
               else
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(FreezeCurrentState15_pfct)(ptrIOCBIFnc))(DCM_CANCEL,NULL_PTR,NULL_PTR);
               }
          break;

       case DCM_IOCBI_RESETTODEFAULT:

               ptrIOCBIFnc= Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
               if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault10_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u8);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault11_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u16);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault12_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u32);
               }
               else
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(ResetToDefault15_pfct)(ptrIOCBIFnc))(DCM_CANCEL,NULL_PTR,NULL_PTR);
               }
          break;

       default:
           Result = E_NOT_OK;
           break;
    }

    return Result;
}
#endif

Std_ReturnType Dcm_Prv_IocbiInitExternalMask(void)
{
    void * ptrIOCBIFnc = NULL_PTR;
    Std_ReturnType Result = E_NOT_OK;

    uint8 ControlMask_u8   = 0u;
    uint16 ControlMask_u16 = 0u;
    uint32 ControlMask_u32 = 0u;

    const Dcm_DataInfoConfig_tst *ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    const Dcm_SignalDIDSubStructConfig_tst *ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

    switch(ptrSigConfig->usePort_u8)
    {
        case USE_DATA_ASYNCH_CLIENT_SERVER  :
        case USE_DATA_ASYNCH_FNC:
#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
        if(ptrSigConfig->UseAsynchronousServerCallPoint_b)
        {
            Result = Dcm_Prv_IocbiInitExternalASP();
        }
        else
#endif
        {
            switch(Dcm_ControlParameter_u8)
            {
               case DCM_IOCBI_SHORTTERMADJUSTMENT:
                   ptrIOCBIFnc= Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
                   if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(ShortTermAdjustment6_pfct)(ptrIOCBIFnc)) (NULL_PTR,DCM_CANCEL,ControlMask_u8,NULL_PTR);
                   }
                   else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(ShortTermAdjustment7_pfct)(ptrIOCBIFnc)) (NULL_PTR,DCM_CANCEL,ControlMask_u16,NULL_PTR);
                   }
                   else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(ShortTermAdjustment8_pfct)(ptrIOCBIFnc)) (NULL_PTR,DCM_CANCEL,ControlMask_u32,NULL_PTR);
                   }
                   else
                   {
                       if(USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                       {
                           /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                           Result = (*(ShortTermAdjustment15_pfct)(ptrIOCBIFnc))(NULL_PTR,DCM_CANCEL,NULL_PTR,NULL_PTR);
                       }
                   }
                  break;

               case DCM_IOCBI_FREEZECURRENTSTATE:
                   ptrIOCBIFnc     = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
                   if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(FreezeCurrentState6_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u8,NULL_PTR);
                   }
                   else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 == 2u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(FreezeCurrentState7_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u16,NULL_PTR);
                   }
                   else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(FreezeCurrentState8_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u32,NULL_PTR);
                   }
                   else
                   {
                       if(USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                       {
                           /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                           Result = (*(FreezeCurrentState15_pfct)(ptrIOCBIFnc))(DCM_CANCEL,NULL_PTR,NULL_PTR);
                       }
                   }
                  break;

               case DCM_IOCBI_RESETTODEFAULT:
                   ptrIOCBIFnc= Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
                   if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(ResetToDefault6_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u8,NULL_PTR);
                   }
                   else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(ResetToDefault7_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u16,NULL_PTR);
                   }
                   else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result=(*(ResetToDefault8_pfct)(ptrIOCBIFnc))(DCM_CANCEL,ControlMask_u32,NULL_PTR);
                   }
                   else
                   {
                       if(USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                       {
                           /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                           Result = (*(ResetToDefault15_pfct)(ptrIOCBIFnc))(DCM_CANCEL,NULL_PTR,NULL_PTR);
                       }
                   }
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



static Std_ReturnType Dcm_ExecuteIoFunctionalitySYNCH_ExternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    uint8 ControlMask_u8   = 0u;
    uint16 ControlMask_u16 = 0u;
    uint32 ControlMask_u32 = 0u;

    void * ptrIOCBIFnc = NULL_PTR;
    Std_ReturnType Result = E_NOT_OK;

    const Dcm_DataInfoConfig_tst *ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    const Dcm_SignalDIDSubStructConfig_tst *ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

    switch(pMsgContext->reqData[2])
    {
        case DCM_IOCBI_SHORTTERMADJUSTMENT:
            ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;

            if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
            {
                ControlMask_u8 = pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result = (*(ShortTermAdjustment3_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],ControlMask_u8,ErrorCode);
            }
            else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
            {
                ControlMask_u16 = DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result = (*(ShortTermAdjustment4_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],ControlMask_u16,ErrorCode);
            }
            else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8<=4u)
            {
                ControlMask_u32 = DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result = (*(ShortTermAdjustment5_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],ControlMask_u32,ErrorCode);
            }
            else
            {
               if(USE_DATA_SYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(ShortTermAdjustment14_pfct)(ptrIOCBIFnc))(&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
               }
            }
            break;

        case DCM_IOCBI_FREEZECURRENTSTATE:
            ptrIOCBIFnc     = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
            if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
            {
                ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result=(*(FreezeCurrentState3_pfct)(ptrIOCBIFnc))(ControlMask_u8,ErrorCode);
            }
            else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
            {
                ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result=(*(FreezeCurrentState4_pfct)(ptrIOCBIFnc))(ControlMask_u16,ErrorCode);
            }
            else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <=4u)
            {
                ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result=(*(FreezeCurrentState5_pfct)(ptrIOCBIFnc))(ControlMask_u32,ErrorCode);
            }
            else
            {
                if(USE_DATA_SYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                {
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                    Result = (*(FreezeCurrentState14_pfct)(ptrIOCBIFnc))(&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
                }
            }
           break;

        case DCM_IOCBI_RESETTODEFAULT:
            ptrIOCBIFnc= Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
            if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
            {
                ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result=(*(ResetToDefault3_pfct)(ptrIOCBIFnc))(ControlMask_u8,ErrorCode);
            }
            else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
            {
                ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result=(*(ResetToDefault4_pfct)(ptrIOCBIFnc))(ControlMask_u16,ErrorCode);
            }
            else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
            {
                ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result=(*(ResetToDefault5_pfct)(ptrIOCBIFnc))(ControlMask_u32,ErrorCode);
            }
            else
            {
                if(USE_DATA_SYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                {
                    /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                    Result = (*(ResetToDefault14_pfct)(ptrIOCBIFnc))(&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
                }
            }

           break;

        default:
            Result = E_NOT_OK;
            break;
    }

    return Result;
}

#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
static Std_ReturnType Dcm_ExecuteIoFunctionalityASP(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    uint8 ControlMask_u8    = 0u;
    uint16 ControlMask_u16  = 0u;
    uint32 ControlMask_u32  = 0u;

    void * ptrIOCBIFnc = NULL_PTR;
    Std_ReturnType Result = E_NOT_OK;

    const Dcm_DataInfoConfig_tst * ptrSigConfig;
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig;

    ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

    switch(pMsgContext->reqData[2])
    {
       case DCM_IOCBI_SHORTTERMADJUSTMENT:
           if(!Dcm_IocbiRteCallPlaced_b)
           {
              ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
              if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
              {
                  ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result=(*(ShortTermAdjustment10_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,ControlMask_u8);
              }
              else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
              {
                  ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result=(*(ShortTermAdjustment11_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,ControlMask_u16);
              }
              else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
              {
                  ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                  pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result=(*(ShortTermAdjustment12_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,ControlMask_u32);
              }
              else
              {
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                  Result = (*(ShortTermAdjustment15_pfct)(ptrIOCBIFnc))(&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
              }
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
                ptrIOCBIFnc     = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
                if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
               {
                   ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState10_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u8);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
               {
                   ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState11_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u16);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
               {
                   ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                   pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState12_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u32);
               }
               else
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(FreezeCurrentState15_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
               }
            }
            else
            {
                ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentStateResults_cpv;
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result=(*(FreezeCurrentState13_pfct)(ptrIOCBIFnc)) (ErrorCode);
            }
          break;

       case DCM_IOCBI_RESETTODEFAULT:
           if(!Dcm_IocbiRteCallPlaced_b)
           {
               ptrIOCBIFnc= Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
               if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
               {
                  ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                  /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault10_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u8);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
               {
                   ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault11_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u16);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
               {
                   ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                   pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault12_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u32);
               }
               else
               {
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result = (*(ResetToDefault15_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
               }
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

    return Result;
}
#endif


static Std_ReturnType Dcm_ExecuteIoFunctionalityASYNCH_ExternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    uint8 ControlMask_u8    = 0u;
    uint16 ControlMask_u16  = 0u;
    uint32 ControlMask_u32  = 0u;

    void * ptrIOCBIFnc = NULL_PTR;
    Std_ReturnType Result = E_NOT_OK;

    const Dcm_DataInfoConfig_tst * ptrSigConfig;
    const Dcm_SignalDIDSubStructConfig_tst * ptrIOSigConfig;

    ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

#if (DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
    if(ptrSigConfig->UseAsynchronousServerCallPoint_b)
    {
        Result = Dcm_ExecuteIoFunctionalityASP(pMsgContext,ErrorCode);
    }
    else
#endif
    {
        switch(pMsgContext->reqData[2])
        {
           case DCM_IOCBI_SHORTTERMADJUSTMENT:
               ptrIOCBIFnc= Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrShortTermAdjustment_cpv;
               if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
               {
                   ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ShortTermAdjustment6_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,ControlMask_u8,ErrorCode);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
               {
                   ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ShortTermAdjustment7_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,ControlMask_u16,ErrorCode);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
               {
                   ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                   pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ShortTermAdjustment8_pfct)(ptrIOCBIFnc)) (&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,ControlMask_u32,ErrorCode);
               }
                else
                {
                    if(USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                    {
                        /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                        Result = (*(ShortTermAdjustment15_pfct)(ptrIOCBIFnc))(&pMsgContext->reqData[(DSP_IOCBI_MINREQLEN)],Dcm_DspIocbiOpStatus,&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
                    }
                }
              break;

           case DCM_IOCBI_FREEZECURRENTSTATE:
               ptrIOCBIFnc     = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrFreezeCurrentState_cpv;
               if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
               {
                   ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState6_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u8,ErrorCode);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
               {
                   ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState7_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u16,ErrorCode);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
               {
                   ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                           pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(FreezeCurrentState8_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u32,ErrorCode);
               }
               else
                {
                   if(USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result = (*(FreezeCurrentState15_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
                   }
                }
              break;

           case DCM_IOCBI_RESETTODEFAULT:
               ptrIOCBIFnc= Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrResetToDefault_cpv;
               if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==1u)
               {
                   ControlMask_u8=pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault6_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u8,ErrorCode);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8==2u)
               {
                   ControlMask_u16=DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault7_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u16,ErrorCode);
               }
               else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
               {
                   ControlMask_u32=DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],                  \
                   pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
                   /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                   Result=(*(ResetToDefault8_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,ControlMask_u32,ErrorCode);
               }
               else
               {
                   if(USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8)
                   {
                       /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                       Result = (*(ResetToDefault15_pfct)(ptrIOCBIFnc))(Dcm_DspIocbiOpStatus,&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
                   }
               }
              break;

           default:
               Result = E_NOT_OK;
               break;
        }
    }

    (void)ControlMask_u8;
    return Result;
}






static Std_ReturnType Dcm_ProcessIoFunctionality_ExternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    uint8 ControlMask_u8 = 0u ;
    uint16 ControlMask_u16 = 0u;
    uint32 ControlMask_u32 = 0u;

    void * ptrIOCBIFnc  = NULL_PTR;
    Std_ReturnType Result = E_NOT_OK;

    const Dcm_DataInfoConfig_tst * ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[Dcm_DidSignalIdx_u16].idxDcmDspDatainfo_u16];
    const Dcm_SignalDIDSubStructConfig_tst *ptrIOSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];

    if(pMsgContext->reqData[2] == DCM_IOCBI_RETURNCONTROLTOECU)
    {
        ptrIOCBIFnc = Dcm_DspIOControlInfo[ptrIOSigConfig->idxDcmDspIocbiInfo_u16].adrReturnControlEcu_cpv;

        /*As ReturnControlToEcu is a synchronous API , the same API is invoked for both Synch and ASynch Fnc and ClientServer Configuration */
        if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 == 1u)
        {
            ControlMask_u8 = pMsgContext->reqData[(pMsgContext->reqDataLen-1u)];
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
            Result=(*(ReturnControlEcu3_pfct)(ptrIOCBIFnc))(ControlMask_u8,ErrorCode);
        }
        else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 == 2u)
        {
            ControlMask_u16 = DSP_CONV_2U8_TO_U16(pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
            Result = (*(ReturnControlEcu4_pfct)(ptrIOCBIFnc))(ControlMask_u16,ErrorCode);
        }
        else if(ptrDidExtendedConfig->dataCtrlMaskSize_u8 <= 4u)
        {
            ControlMask_u32 = DSP_CONV_4U8_TO_U32(pMsgContext->reqData[(pMsgContext->reqDataLen-4u)],pMsgContext->reqData[(pMsgContext->reqDataLen-3u)],
            pMsgContext->reqData[(pMsgContext->reqDataLen-2u)],pMsgContext->reqData[(pMsgContext->reqDataLen-1u)]);
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
            Result = (*(ReturnControlEcu5_pfct)(ptrIOCBIFnc))(ControlMask_u32,ErrorCode);
        }
        else
        {
            if((USE_DATA_SYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8) || (USE_DATA_ASYNCH_CLIENT_SERVER == ptrSigConfig->usePort_u8))
            {
                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation Required for efficient RAM usage by using single void function pointer */
                Result = (*(ReturnControlEcu9_pfct)(ptrIOCBIFnc))(&pMsgContext->reqData[(pMsgContext->reqDataLen - ptrDidExtendedConfig->dataCtrlMaskSize_u8)],ErrorCode);
            }
        }
    }
    else
    {
        if((ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_CLIENT_SERVER)||(ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_FNC))
        {
            Result = Dcm_ExecuteIoFunctionalitySYNCH_ExternalMask(pMsgContext,ErrorCode);
        }
        if((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER)||(ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_FNC))
        {
            Result = Dcm_ExecuteIoFunctionalityASYNCH_ExternalMask(pMsgContext,ErrorCode);

            #if (DCM_CFG_DSP_IOCBI_ASP_ENABLED == DCM_CFG_ON)
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

    if(Result == E_OK)
    {
        *ErrorCode = 0u;
    }
    return Result;
}




Std_ReturnType Dcm_Prv_ProcessWithExternalMask(const Dcm_MsgContextType * pMsgContext,Dcm_NegativeResponseCodeType * ErrorCode)
{
    Std_ReturnType Result = E_NOT_OK;

#if( DCM_CFG_DSP_IOCBI_SR_ENABLED != DCM_CFG_OFF)
    if((ptrDidConfig->didUsePort_u8 == USE_ATOMIC_SENDER_RECEIVER_INTERFACE) || (ptrDidConfig->didUsePort_u8 == USE_ATOMIC_SENDER_RECEIVER_INTERFACE_AS_SERVICE))
    {
        Result = Dcm_GetLengthOfSignal(&Dcm_dataSignalLength_u16);
        if((NULL_PTR != ptrDidConfig->ioControlRequest_cpv) && (E_OK == Result))
        {
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
             * Required for efficient RAM usage by using single void function pointer */
            Result = (*(IOControlrequest_pfct)(ptrDidConfig->ioControlRequest_cpv))\
                    (Dcm_ControlParameter_u8,&pMsgContext->reqData[DSP_IOCBI_MINREQLEN],Dcm_dataSignalLength_u16,\
                            ptrDidExtendedConfig->dataCtrlMaskSize_u8,Dcm_DspIocbiOpStatus,ErrorCode);

            if(E_OK == Result)
            {
                Dcm_ReadSignalLength_u16 = Dcm_dataSignalLength_u16;
            }
        }
    }
    else
#endif
    {
        while((Dcm_DidSignalIdx_u16 < ptrDidConfig->nrSig_u16) && (*ErrorCode==0x0u))
        {
            if(DCM_E_PENDING != Dcm_ProcessIOResult)
            {
                Result = Dcm_GetLengthOfSignal(&Dcm_dataSignalLength_u16);
            }

            if ((E_OK == Result) || (DCM_E_PENDING == Dcm_ProcessIOResult))
            {
                Result = Dcm_ProcessIoFunctionality_ExternalMask(pMsgContext,ErrorCode);
                Dcm_ProcessIOResult = Result;
            }

            if (E_OK == Result)
            {
                Dcm_DspIocbiOpStatus = DCM_INITIAL;
                Dcm_ReadSignalLength_u16 += Dcm_dataSignalLength_u16;
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
    }

   return Result;





}




#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif      /* #if (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF) */

