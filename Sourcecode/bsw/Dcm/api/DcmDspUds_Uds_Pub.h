
#ifndef DCMDSPUDS_UDS_PUB_H
#define DCMDSPUDS_UDS_PUB_H

#if (DCM_CFG_DSP_READDTCINFORMATION_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Rdtc_Pub.h"
#endif

#if (DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Seca_Pub.h"
#endif

#if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Dsc_Pub.h"
#endif

#if(DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_CC_Pub.h"
#endif

#if(DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Cdtcs_Pub.h"
#endif

#if(DCM_CFG_DSP_WRITEMEMORYBYADDRESS_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Wmba_Pub.h"
#endif

#if(DCM_CFG_DSP_READMEMORYBYADDRESS_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Rmba_Pub.h"
#endif

#if(DCM_CFG_DSP_CLEARDIAGNOSTICINFORMATION_ENABLED != DCM_CFG_OFF)
#include "DcmDspUds_Cdi_Pub.h"
#endif
/* BSWEXT-127 */
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* END BSWEXT-127 */
/**
 **************************************************************************************************
 * @ingroup DCMCORE_DSLDSD_AUTOSAR
 * Dcm_DemTriggerOnDTCStatus :  This function is invoked by Dem on an interrupt context to inform DCM about the
 * status mask change for a particular DTC, this information can be used by DTC
 * to check if RDTC service has to be invoked or not based on the DTC if it was
 * setup by tester for ROE onchangeofDTC.
 *
 * @param [in]                 Dtc                 :   This is the DTC the change trigger is assigned
 * @param [in]                 DTCStatusOld        :   Old Status
 * @param [in]                 DTCStatusNew        :   New Status
 * @retval                     E_Ok      :   This value is always returned
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

extern Std_ReturnType Dcm_DemTriggerOnDTCStatus( uint32 Dtc, uint8 DTCStatusOld, uint8 DTCStatusNew );

/* BSWEXT-127 */
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
/* END BSWEXT-127 */


#if ((DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)        ||    \
     (DCM_CFG_DSP_WRITEDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)     ||    \
     (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)                     ||     \
     (DCM_CFG_DSP_DYNAMICALLYDEFINEIDENTIFIER_ENABLED != DCM_CFG_OFF))


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/**
 * @ingroup DCMDSP_UDS_EXTENDED
 * Dcm_GetIndexOfDID function is used to determine the index of did/range Did (which is an IN parameter), this function will write
 * the value of index of DID in  Dcm_DIDConfig structure array in case of normal DID /Dcm_DIDRangeConfig_cast structure array in case
 * of range DID on  to idxIndex_u16 which is an element in structure  idxDidIndexType_st(which is an out parameter).
 * The "dataRange_b" element of structure-idxDidIndexType_st is set to
 * FALSE in this function if DID is found in the DCM_DIDConfig structure array.
 *
 * @param[in]               did   : The did for which the index is requested\n
 * @param[out]              idxDidIndexType_st : Structure with index in Dcm_DIDConfig or Dcm_DIDRangeConfig based on the status of dataRange_b
 * @see                     Dcm_Dsp_GetIndexOfDDDI
 *
 */
extern Std_ReturnType Dcm_GetIndexOfDID (
                                                        uint16 did,
                                                        Dcm_DIDIndexType_tst * idxDidIndexType_st
                                                         );

/**
 * @ingroup DCMDSP_UDS_EXTENDED
 * Dcm_GetSupportOfIndex:Calculate if the ID at position index in the Dcm_DIDConfig is supported at this point in time or not.\n
 *
 * @param [in]            index      : index in Dcm_DIDConfig\n
 * @param [in]            direction  : check for read or write support: DCM_SUPPORT_READ,DCM_SUPPORT_WRITE\n
 * @param [out]           NegRespCode: Pointer to a Byte in which to store a negative Response code in case of detection of an error in the request.\n
 * @param [in]            rangestatus:Status to indicate if the Did is configured as a range Did
 * @retval                 DCM_SUPPORT_OK,                ID is supported\n
 *                       DCM_SUPPORT_SESSION_VIOLATED,  ID is not supported in the current session; negative response code is set to NegRespCode\n
 *                       DCM_SUPPORT_SECURITY_VIOLATED, ID is not supported in the current security level; negative response code is set to NegRespCode\n
 *                       DCM_SUPPORT_CONDITION_VIOLATED,ID is not supported as per configured callback function; negative response code is set to NegRespCode\n
 *                       DCM_SUPPORT_CONDITION_PENDING  checking needs more time. call again.
 */
#if ((DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)                ||        \
     (DCM_CFG_DSP_WRITEDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)                ||        \
     (DCM_CFG_DSP_DYNAMICALLYDEFINEIDENTIFIER_ENABLED != DCM_CFG_OFF))

extern Dcm_SupportRet_t Dcm_GetSupportOfIndex( Dcm_DIDIndexType_tst * idxDidIndexType_st,
                                                               Dcm_Direction_t direction,
                                                               Dcm_NegativeResponseCodeType * dataNegRespCode_u8);

#endif

/**
 * @ingroup DCMDSP_UDS_EXTENDED
 * Dcm_GetDIDRangeStatus:Calculations to check if the DID is in the DID Range limits
 * @param[in]       did: The did for which the length is requested
 * @param[out]      idxDidIndexType_st : Index of the requested DID in Dcm_DIDRangeConfig structure if it is a range DID.
 *
 * @retval
 *             E_OK: DID range limit check done successfully
 *             E_NOT_OK: DID not in the range DID limit
 */
#if ((DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)          ||  \
     (DCM_CFG_DSP_WRITEDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)         ||  \
     (DCM_CFG_DSP_DYNAMICALLYDEFINEIDENTIFIER_ENABLED != DCM_CFG_OFF))

extern Std_ReturnType Dcm_GetDIDRangeStatus (
                                                            uint16 did,
                                                            Dcm_DIDIndexType_tst * idxDidIndexType_st
                                                            );
#endif
/**
 * @ingroup DCMDSP_UDS_EXTENDED
 *
 *  Dcm_GetLengthOfDIDIndex:
 *  Calculate the length of the ID at position index in Dcm_DIDConfig
 *
 * @param [in]      idxDidIndexType_st    :     index in Dcm_DIDConfig or Dcm_DIDRangeConfig based on the dataRange_b parameter
 * @param [in]       did                     :     DID in the request
 * @param [out]     *length                :     length calculated in case E_OK is returned
 * @retval     E_OK: calculation finished successfully
 *             E_NOT_OK: error in configuration or in the called length calculating function
 * @see    Dcm_GetLengthOfDID_u8
 *
 **************************************************************************************************
 */
extern     Std_ReturnType Dcm_GetLengthOfDIDIndex(Dcm_DIDIndexType_tst * idxDidIndexType_st,
                                                               uint32 * length_u32,
                                                               uint16 did_u16);

#if((DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)|| (DCM_CFG_DSP_WRITEDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF) ||(DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF))
/**
 * @ingroup DCMDSP_UDS_EXTENDED
 *
 * Dcm_GetActiveDid:
 * This API will update the normal DID currently being processed by Dsp supported RDBI/WDBI/IOCBI services .The API can be polled from  Read/CondionCheckRead/ReadDataLength functions
 * during RDBI request processing, from Write function during WDBI request processing and from FreezeCurrentState/ResetToDefault/ShortTermAdjustment/ReturnControlToEcu/Read
 * function during IOCBI request processing.The API can be used to identify the appropriate data requested by the application.If the API is called from anywhere outside
 * the mentioned  application APIs while processing the requested services, the DID value may not be correct.In case the DID currently under process is a normal DID,
 * E_OK is returned and a valid value is filled in the parameter passed.In case the DID currently under process is a range DID, E_NOT_OK is returned.
 *
 * @param [out]     dataDid_u16: Pointer to a variable for updating of the DID under processing. The DID value returned is valid only if return value is E_OK.\n
 * @retval          E_OK : The DID under processing is a normal DID.The parameter dataDid_u16 contains valid DID in this case \n
 *                  E_NOT_OK: The DID under processing is a range DID. The parameter dataDid_u16 contains invalid data in this case. \n
 * @see
 *
 **************************************************************************************************
 */
extern Std_ReturnType Dcm_GetActiveDid(uint16 * dataDid_u16);

/**
 *******************************************************************************************************************************************************************
 * Dcm_GetActiveSourceDataId:
 *
 * This API will update the Source Data Identifiers sent during a 0x2c request.The API can be polled from  Read/CondionCheckRead/ReadDataLength functions
 * during RDBI request processing. If a DDDI is defined with one or more source DIDs using 0x2C request, when read, this API can be used to determine the current
 * source DID being processed.
 *
 *
 * \param     uint16* dataSrcDid_u16 : Parameter for updating of the Source DID under processing. The value returned is valid only if return value is E_OK.
 *            uint8*  posnSrcDataRec_u8 : Parameter to update the position in the source Data Record for DID under process
 *            uint8*  adrMemSize_u8 : Memory size/length of the source DID under progress.
 *
 * \retval    Std_ReturnType : E_OK : The source DID under processing is a normal DID.The parameter dataSrcDid_u16 contains valid Source DID value in this case.
 *                             E_NOT_OK: The DID under processing is a range DID. The parameter dataDid_u16 contains invalid data in this case.
 * \seealso
 *
 *******************************************************************************************************************************************************************
 */
extern Std_ReturnType Dcm_GetActiveSourceDataId(uint16 * dataSrcDid_u16,uint8 * posnSrcDataRec_u8, uint8 * adrMemSize_u8);

#endif
/**
 * @ingroup DCMDSP_UDS_EXTENDED
 * Dcm_GetDIDData:The function is used to read the DID data of the requested DID by calling the corresponding\n
 * configured function for reading the data. The DID value is not written in the buffer.
 *
 * @param[inout]           idxDidIndexType_st         : index in Dcm_DIDConfig or Dcm_DIDRangeConfig based on dataRange_b status
 * @param[out]          targetBuffer                    : Pointer to the buffer where the data is to be written\n
 *
 * @retval              Std_ReturnType : E_NOT_OK       : DID data was not read successfully
 *                                       E_OK           : DID data is read successfully\n
 *                                         DCM_E_PENDING  : More time is required to read the data\n
 *
 */
#if ((DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF)                            ||            \
     (DCM_CFG_DSP_DYNAMICALLYDEFINEIDENTIFIER_ENABLED != DCM_CFG_OFF)    ||            \
             (DCM_CFG_DSP_READDATABYPERIODICIDENTIFIER_ENABLED != DCM_CFG_OFF) ||   \
             (DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF))

extern Std_ReturnType Dcm_GetDIDData (Dcm_DIDIndexType_tst * idxDidIndexType_st,
                                                                                          uint8 * targetBuffer);
#endif



extern Std_ReturnType Dcm_GetVin (uint8 * Data);



#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#endif
#if(DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Std_ReturnType Dcm_GetActiveRid(uint16 * dataRid_u16);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#endif






#endif /* _DCMDSPUDS_UDS_PUB_H  */
