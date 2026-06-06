
#ifndef DCMDSPUDS_RDBI_PROT_H
#define DCMDSPUDS_RDBI_PROT_H


/**
 ***************************************************************************************************
            Read Data By Identifier (RDBI) service
 ***************************************************************************************************
 */

#if (DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF)

#define DCM_RDBI_SIZE_DID            (0x02u) /* Minimum length of request for RDBI */

/* Definitions of states of RDBI service */
typedef enum
{
    DCM_RDBI_IDLE,                      /* Idle state */
    DCM_RDBI_NEG_RESP,
    DCM_RDBI_PROCESS_NEW_DID,           /* "process new DID"  state */
    DCM_RDBI_CHECK_READACCESS,          /* "Check read access" state */
    DCM_RDBI_CHECK_CONDITIONS,          /* "Check conditions" state */
    DCM_RDBI_GET_LENGTH,                /* "Get length" state */
    DCM_RDBI_GET_DATA                   /* "Get data" state */
}Dcm_StRdbi_ten;
#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint16 Dcm_RdbiReqDidNb_u16; /* Number of requested DIDs          */
extern uint16 Dcm_NumOfIndices_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_StRdbi_ten Dcm_stRdbi_en;           /* State of RDBI state machine        */
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_TotalLength_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/* Condition Check Read Function Pointer Types */



typedef enum {
  DCM_LENCALC_RETVAL_OK,
  DCM_LENCALC_RETVAL_ERROR,
  DCM_LENCALC_RETVAL_PENDING
}
Dcm_LenCalcRet_ten;

typedef enum {
  DCM_LENCALC_STATUS_INIT,
  DCM_LENCALC_STATUS_GETINDEX,
  DCM_LENCALC_STATUS_GETLENGTH,
  DCM_LENCALC_STATUS_GETSUPPORT
}
Dcm_LenCalc_ten;

#ifdef DCM_CFG_DSPRDBIOBDDID_ENABLED
#if (DCM_CFG_DSPRDBIOBDDID_ENABLED != DCM_CFG_OFF)
typedef struct
{
    uint8*  rdbiObdDidDataBuffer_pu8;         /* To store DID data */
    uint16 rdbiObdDid_u16;    									       /* To store DID */
    uint16 rdbiObdDidLength_u16;                  					   /* Did Data Length */
    uint8  rdbiObdDidSupport_u8;                         			   /* Indicates if Did is supported */
} Dcm_DspDspRdbi_Obd_st;

#define DCM_OBDDID_MASK_HB (0xFF00) /* To mask higher byte of requested DID          */
#define DCM_OBDDID_MASK_LB (0x00FF) /* To mask lower byte of requested DID           */

/* Possible OBD DID modes */
#define DCM_RDBIOBDMODE1_RANGE   0xF400                     /* OBD Mode One DIDs */
#define DCM_RDBIOBDMODE6_RANGE   0xF600                     /* OBD Mode Six DIDs */
#define DCM_RDBIOBDMODE9_RANGE   0xF800                     /* OBD Mode Nine DIDs */

#define DCM_RDBIOBDMODE1   0xF4                     /* OBD Mode One DIDs */
#define DCM_RDBIOBDMODE6   0xF6                     /* OBD Mode Six DIDs */
#define DCM_RDBIOBDMODE9   0xF8                     /* OBD Mode Nine DIDs */

#endif
#endif

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_LenCalc_ten Dcm_StLenCalc_en;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint8 * Dcm_IdxList_pu8;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_NumberOfBytesInResponse_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint16 Dcm_NumberOfProcessedDIDs_u16;
extern uint16 Dcm_NumberOfAcceptedDIDs_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_OpStatusType Dcm_DspReadDidOpStatus_u8;    /* Variable to store the opstatus*/
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
Dcm_LenCalcRet_ten Dcm_DspGetTotalLengthOfDIDs_en(uint8 * adrSourceIds_pu8,
                                                             uint16 nrDids_u16,
                                                             uint16 * adrNumOfIndices_pu16,
                                                             uint32 * adrTotalLength_pu32,
                                                             Dcm_NegativeResponseCodeType * dataNegRespCode_u8);
extern void Dcm_Prv_DspRdbiConfirmation(uint8 sid_u8, uint8 reqType_u8,uint16 connectionId_u16,Dcm_ConfirmationStatusType confirmationStatus, Dcm_ProtocolType protocolType,uint16 testerSrcAddress_u16);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
typedef enum
  {
    DCM_GETDATA_RETVAL_OK,
    DCM_GETDATA_RETVAL_INTERNALERROR,
    DCM_GETDATA_RETVAL_PENDING,
#if(DCM_CFG_RDBIPAGEDBUFFERSUPPORT != DCM_CFG_OFF)
    DCM_GETDATA_PAGED_BUFFER_TX,
#endif
    DCM_GETDATA_RETVAL_INVALIDCONDITIONS
  } Dcm_GetDataRet_ten;

#if(DCM_CFG_RDBIPAGEDBUFFERSUPPORT != DCM_CFG_OFF)
  /**
   * @ingroup DCM_H
   * This macro will be RDBI service for paged buffer handling and used to transmit data available within the current page
   *
   *
   * DCM_E_REQUEST_PROCESS_COMPLETED\n
   *
   *
   */
  #ifndef DCM_E_DATA_PAGE_FILLED
  #define DCM_E_DATA_PAGE_FILLED  45u
  #endif
#endif

typedef enum
  {
    DCM_GETDATA_STATUS_INIT,
    DCM_GETDATA_STATUS_GETLENGTH,
#if(DCM_CFG_RDBIPAGEDBUFFERSUPPORT != DCM_CFG_OFF)
    DCM_GETDATA_STATUS_TRANSMITPAGE,
#endif
    DCM_GETDATA_STATUS_GETDATA
  } Dcm_GetData_ten;
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern Dcm_GetData_ten Dcm_GetDataState_en;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint16 Dcm_GetDataNumOfIndex_u16;
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
extern uint32 Dcm_GetDataTotalLength_u32;
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
#if(DCM_CFG_RDBIPAGEDBUFFERSUPPORT != DCM_CFG_OFF)
Dcm_GetDataRet_ten Dcm_GetData_en(const uint8 * adrIdBuffer_pcu8,
                                            uint8 * adrTargetBuffer_pu8,
                                            uint16 nrIndex_u16,
                                            Dcm_NegativeResponseCodeType * dataNegRespCode_u8
                                            );
#else
Dcm_GetDataRet_ten Dcm_GetData_en(const uint8 * adrIdBuffer_pcu8,
                                            uint8 * adrTargetBuffer_pu8,
                                            uint16 nrIndex_u16,
                                            Dcm_NegativeResponseCodeType * dataNegRespCode_u8,
                                            uint32 adrTotalLength_pu32);

#endif
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

#endif


#endif   /* _DCMDSPUDS_RDBI_PROT_H */

