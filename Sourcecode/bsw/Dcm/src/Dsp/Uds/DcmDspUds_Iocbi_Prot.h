
#ifndef DCMDSPUDS_IOCBI_PROT_H
#define DCMDSPUDS_IOCBI_PROT_H


#if (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
*/

/***************************DCM_IOCBI_RETURNCONTROLTOECU***************************************************************/

/*synch c/s and control mask is NO_MASK/Internal*/
typedef Std_ReturnType (*ReturnControlEcu1_pfct) (Dcm_NegativeResponseCodeType * ErrorCode);

/*Asynch c/s and control mask is NO_MASK/Internal*/
typedef Std_ReturnType (*ReturnControlEcu2_pfct) (Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode);

/*synch c/s and control mask is external*/
typedef Std_ReturnType (*ReturnControlEcu3_pfct) (uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ReturnControlEcu4_pfct) (uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ReturnControlEcu5_pfct) (uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ReturnControlEcu9_pfct) (uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);


/*Asynch c/s and control mask is external*/
typedef Std_ReturnType (*ReturnControlEcu6_pfct) (Dcm_OpStatusType OpStatus,uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ReturnControlEcu7_pfct) (Dcm_OpStatusType OpStatus,uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ReturnControlEcu8_pfct) (Dcm_OpStatusType OpStatus,uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ReturnControlEcu10_pfct) (Dcm_OpStatusType OpStatus,uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);


/***************************DCM_IOCBI_RESETTODEFAULT*******************************************************************/


/*synch c/s fnc and control mask is NO_MASK/Internal*/
typedef Std_ReturnType (*ResetToDefault1_pfct) (Dcm_NegativeResponseCodeType * ErrorCode);

/*Asynch c/s fnc and control mask is NO_MASK/Internal*/
typedef Std_ReturnType (*ResetToDefault2_pfct) (Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode);

/*synch c/s and control mask is external*/
typedef Std_ReturnType (*ResetToDefault3_pfct) (uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ResetToDefault4_pfct) (uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ResetToDefault5_pfct) (uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ResetToDefault14_pfct) (uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);

/*Asynch c/s and control mask is external*/
typedef Std_ReturnType (*ResetToDefault6_pfct) (Dcm_OpStatusType OpStatus,uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ResetToDefault7_pfct) (Dcm_OpStatusType OpStatus,uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ResetToDefault8_pfct) (Dcm_OpStatusType OpStatus,uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ResetToDefault15_pfct) (Dcm_OpStatusType OpStatus,uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);

#if(DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
typedef Std_ReturnType (*ResetToDefault9_pfct) (Dcm_OpStatusType OpStatus);
typedef Std_ReturnType (*ResetToDefault10_pfct) (Dcm_OpStatusType OpStatus,uint8 controlMask);
typedef Std_ReturnType (*ResetToDefault11_pfct) (Dcm_OpStatusType OpStatus,uint16 controlMask);
typedef Std_ReturnType (*ResetToDefault12_pfct) (Dcm_OpStatusType OpStatus,uint32 controlMask);
typedef Std_ReturnType (*ResetToDefault13_pfct) (Dcm_NegativeResponseCodeType * ErrorCode);
#endif


/***************************DCM_IOCBI_FREEZECURRENTSTATE***************************************************************/

/*synch c/s and control mask is NO_MASK/Internal*/
typedef Std_ReturnType (*FreezeCurrentState1_pfct) (Dcm_NegativeResponseCodeType * ErrorCode);

/*Asynch c/s and control mask is NO_MASK/Internal*/
typedef Std_ReturnType (*FreezeCurrentState2_pfct) (Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode);

/*synch c/s and control mask is external*/
typedef Std_ReturnType (*FreezeCurrentState3_pfct) (uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*FreezeCurrentState4_pfct) (uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*FreezeCurrentState5_pfct) (uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*FreezeCurrentState14_pfct) (uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);

/*Asynch c/s and control mask is external*/
typedef Std_ReturnType (*FreezeCurrentState6_pfct) (Dcm_OpStatusType OpStatus,uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*FreezeCurrentState7_pfct) (Dcm_OpStatusType OpStatus,uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*FreezeCurrentState8_pfct) (Dcm_OpStatusType OpStatus,uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*FreezeCurrentState15_pfct) (Dcm_OpStatusType OpStatus,uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);


#if(DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
typedef Std_ReturnType (*FreezeCurrentState9_pfct) (Dcm_OpStatusType OpStatus);
typedef Std_ReturnType (*FreezeCurrentState10_pfct) (Dcm_OpStatusType OpStatus,uint8 controlMask);
typedef Std_ReturnType (*FreezeCurrentState11_pfct) (Dcm_OpStatusType OpStatus,uint16 controlMask);
typedef Std_ReturnType (*FreezeCurrentState12_pfct) (Dcm_OpStatusType OpStatus,uint32 controlMask);
typedef Std_ReturnType (*FreezeCurrentState13_pfct) (Dcm_NegativeResponseCodeType * ErrorCode);
#endif

/***************************DCM_IOCBI_SHORTTERMADJUSTMENT**************************************************************/

/*synch fnc and asycnh fnc and control mask is NO_MASK*/
typedef Std_ReturnType (*ShortTermAdjustment1_pfct) (const uint8 * ControlStateInfo,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ShortTermAdjustment2_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode);

/*synch c/s and control mask is external*/
typedef Std_ReturnType (*ShortTermAdjustment3_pfct) (const uint8 * ControlStateInfo,uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ShortTermAdjustment4_pfct) (const uint8 * ControlStateInfo,uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ShortTermAdjustment5_pfct) (const uint8 * ControlStateInfo,uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ShortTermAdjustment14_pfct) (const uint8 * ControlStateInfo,uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);

/*Asynch c/s and control mask is external*/
typedef Std_ReturnType (*ShortTermAdjustment6_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,uint8 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ShortTermAdjustment7_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,uint16 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ShortTermAdjustment8_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,uint32 controlMask,Dcm_NegativeResponseCodeType * ErrorCode);
typedef Std_ReturnType (*ShortTermAdjustment15_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,uint8 *ControlMaskArr,Dcm_NegativeResponseCodeType * ErrorCode);


#if(DCM_CFG_DSP_IOCBI_ASP_ENABLED != DCM_CFG_OFF)
typedef Std_ReturnType (*ShortTermAdjustment9_pfct)  (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus);
typedef Std_ReturnType (*ShortTermAdjustment10_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,uint8 controlMask);
typedef Std_ReturnType (*ShortTermAdjustment11_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,uint16 controlMask);
typedef Std_ReturnType (*ShortTermAdjustment12_pfct) (const uint8 * ControlStateInfo,Dcm_OpStatusType OpStatus,uint32 controlMask);
typedef Std_ReturnType (*ShortTermAdjustment13_pfct) (Dcm_NegativeResponseCodeType * ErrorCode);
#endif



typedef enum
{
    DCM_IOCBI_IDLESTATE,                              /* Idle state */
    DCM_IOCBI_FCS_ACTIVE,                        /* Freeze current state for a DID is active */
    DCM_IOCBI_FCS_PENDING,                        /* Freeze current state for a DID is pending */
    DCM_IOCBI_RTD_ACTIVE,                        /* Reset to default state for a DID is active */
    DCM_IOCBI_RTD_PENDING,                         /* Reset to default state for a DID is pending*/
    DCM_IOCBI_STA_ACTIVE,                          /* Short term adjustment for a DID is active */
    DCM_IOCBI_STA_PENDING,                         /* Short term adjustment for a DID is pending */
    DCM_IOCBI_RCE_ACTIVE,                          /* Return Control To Ecu for a DID is active*/
    DCM_IOCBI_RCE_PENDING                         /* Return Control To Ecu for a DID is pending*/
  }Dcm_Dsp_IocbiDidStatus_ten;


/*Structure to store the index of IOCBI DIDs and their status*/
typedef struct
{
    uint16        idxindex_u16;
    Dcm_Dsp_IocbiDidStatus_ten IocbiStatus_en;
} Dcm_Dsp_IocbiStatusType_tst;


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/
extern Dcm_Dsp_IocbiStatusType_tst DcmDsp_IocbiStatus_array[DCM_CFG_NUM_IOCBI_DIDS];

extern void Dcm_ResetActiveIoCtrl(uint32 dataSessionMask_u32,uint32 dataSecurityMask_u32,boolean flgSessChkReqd_b);
extern void Dcm_Prv_DspIOCBIConfirmation(uint8 sid_u8, uint8 reqType_u8,uint16 connectionId_u16,
                                            Dcm_ConfirmationStatusType confirmationStatus, Dcm_ProtocolType protocolType,uint16 testerSrcAddress_u16);

#endif
#endif   /* _DCMDSPUDS_IOCBI_PROT_H */

