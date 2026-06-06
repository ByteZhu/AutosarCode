
#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"

#include "DcmDspUds_Rdbi_Inf.h"

#ifdef DCM_CFG_DSPRDBIOBDDID_ENABLED
#if (DCM_CFG_DSPRDBIOBDDID_ENABLED != DCM_CFG_OFF)

#define DSP_RDBI_MODE16BUFIDX  1U
#define DSP_RDBI_MODE9BUFIDX   2U

static Dcm_DspDspRdbi_Obd_st Dcm_DspDspRdbi_Obd;

uint8 Dcm_DspRdbiObdDidDataBuffer_a8[DCM_CFG_RDBIOBDDID_MAXBUFSIZE];

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/*
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20250]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20259]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20262]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20284]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20286]
* */

/**
***************************************************************************************************
* Dcm_Prv_DspRdbi_Obd_DIDInfo - Function to check if the requested DID is supported/get response length or
* response data of the requested DID
* \param       did_u16     - Requested DID
* \param       void       - Requested functionality(support/length/data)
* \retval      None
***************************************************************************************************
*/

static Std_ReturnType Dcm_Prv_DspRdbi_Obd_DIDInfo(Dcm_OpStatusType OpStatus)
{
    /* Local Variables */
    Std_ReturnType dataRetVal_u8;
    Dcm_MsgContextType          pMsgContext;
    Dcm_NegativeResponseCodeType dataNegRespCode_u8;
    uint16 did_u16;  /* Variable to store DID */
    uint8 mode_u8;   /* Variable to store the mode of the requested DID           */
    uint8 pid_u8;    /* Variable to store lower byte
                                                            (PID of OBD) of the requested DID   */
    dataRetVal_u8 = E_NOT_OK;

    mode_u8 = 0;

    Dcm_DspDspRdbi_Obd.rdbiObdDidDataBuffer_pu8 = &Dcm_DspRdbiObdDidDataBuffer_a8[0];

    /* Functionality */

    /* Check for the mode of the requested DID
    * If requested DID is in the range of 0xF4xx, then the mode is MODE_ONE
    * If requested DID is in the range of 0xF6xx, then the mode is MODE_SIX
    *
    */
    did_u16 = Dcm_DspDspRdbi_Obd.rdbiObdDid_u16;

    #if (DCM_CFG_DSP_OBDMODE1_ENABLED != DCM_CFG_OFF)
    /*Check if the requested DID is F4xx */
    if ((did_u16 & DCM_OBDDID_MASK_HB) == DCM_RDBIOBDMODE1_RANGE )
    {
        mode_u8 = DCM_RDBIOBDMODE1;
    }
    #endif

    #if (DCM_CFG_DSP_OBDMODE6_ENABLED != DCM_CFG_OFF)
    /*Check if the requested DID is F6xx */
    if((did_u16 & DCM_OBDDID_MASK_HB) == DCM_RDBIOBDMODE6_RANGE)
    {
        mode_u8 = DCM_RDBIOBDMODE6;
    }
    #endif

    #if (DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)
    /*Check if the requested DID is F8xx */
    if((did_u16 & DCM_OBDDID_MASK_HB) == DCM_RDBIOBDMODE9_RANGE)
    {
        mode_u8 = DCM_RDBIOBDMODE9;
    }
    #endif

    /* Get the lower byte of the DID
    *  Only lower byte of DID is required by OBD functions*/
    pid_u8 = (uint8)(did_u16 & DCM_OBDDID_MASK_LB);

    pMsgContext.resData = &Dcm_DspRdbiObdDidDataBuffer_a8[0];
    pMsgContext.reqData = &pid_u8;
    pMsgContext.reqDataLen = 1;
    pMsgContext.resMaxDataLen = DCM_CFG_RDBIOBDDID_MAXBUFSIZE;


    /* Based on the mode of requested DID, perform further */
    switch(mode_u8)
    {

        #if (DCM_CFG_DSP_OBDMODE1_ENABLED != DCM_CFG_OFF)
        /* Request is for Mode 1 */
    case DCM_RDBIOBDMODE1 :
        {
            /* Call function to read Obd mode 1 data  */
            dataRetVal_u8 = Dcm_Prv_DspObdMode01(OpStatus,&pMsgContext,&dataNegRespCode_u8);
        }
        break;
        #endif

        #if (DCM_CFG_DSP_OBDMODE6_ENABLED != DCM_CFG_OFF)
        /* Call function to read Obd mode 6 data  */
    case DCM_RDBIOBDMODE6 :
        {
            dataRetVal_u8 = Dcm_Prv_DspObdMode06(OpStatus,&pMsgContext,&dataNegRespCode_u8);
        }
        break;
        #endif

        #if (DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)
        /* Call function to read Obd mode 9 data  */
    case DCM_RDBIOBDMODE9 :
        {
            Dcm_Prv_DspObdMode09_Init();
            dataRetVal_u8 = Dcm_Prv_DspObdMode09(OpStatus,&pMsgContext,&dataNegRespCode_u8);
        }
        break;
        #endif

        default :
        {
            ; /* This state is only to avoid Compiler warning. Control never comes here  */
        }
        break;

    }/* End of switch statement */

    if(dataRetVal_u8 == E_OK)
    {
        Dcm_DspDspRdbi_Obd.rdbiObdDidSupport_u8 = DCM_DID_SUPPORTED;

        Dcm_DspDspRdbi_Obd.rdbiObdDidLength_u16 = pMsgContext.resDataLen;
    }

    return dataRetVal_u8;

}

/* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20283]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20282]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20281]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20262]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20250]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20259] */
/**
***************************************************************************************************
* Dcm_DspRdbi_Obd_IsDidAvailable - Function to check if the requested DID is available

* \param       DID            - Requested DID
* \param       OpStatus       - Status of the current operation
* \param       supported      - Pointer to store if DID is supported or not
* \retval      E_OK           - This function returns E_OK when DID is supported/unsupported
            DCM_E_PENDING     DCM_E_PENDING when Request is not yet finished
***************************************************************************************************
*/

Std_ReturnType Dcm_DspRdbi_Obd_IsDidAvailable (uint16 DID,Dcm_OpStatusType OpStatus,Dcm_DidSupportedType * supported)
{
    /* Local Variables */
    Std_ReturnType dataRetVal_u8; /* Return Variable                            */

    dataRetVal_u8 = E_OK;
    Dcm_DspDspRdbi_Obd.rdbiObdDidSupport_u8 = DCM_DID_NOT_SUPPORTED;

    if((OpStatus == DCM_INITIAL) || (OpStatus == DCM_PENDING))
    {
        Dcm_DspDspRdbi_Obd.rdbiObdDid_u16 = DID;

        /* Functionality */

        /* Call for a function to check if the requested DID is supported */
        dataRetVal_u8 = Dcm_Prv_DspRdbi_Obd_DIDInfo(OpStatus);

        supported[0] = Dcm_DspDspRdbi_Obd.rdbiObdDidSupport_u8;

        if(dataRetVal_u8 == E_NOT_OK)
        {
            dataRetVal_u8 = E_OK;
        }
    }

    return dataRetVal_u8;
}
/*
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20250]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20259] */
/**
***************************************************************************************************
* Dcm_DspRdbi_Obd_ReadDataLength - Function to get response length of the requested DID

* \param       DID           - Requested DID
* \param       OpStatus       - Status of the current operation
* \param       DidLength     - Pointer to store length of the response
* \retval      dataRetVal_u8 - This function always return E_OK if length is not zero else returns E_NOT_OK
***************************************************************************************************
*/

Std_ReturnType Dcm_DspRdbi_Obd_ReadDataLength(uint16 DID,Dcm_OpStatusType OpStatus,uint16 * DidLength)
{
    /* Local Variables */

    Std_ReturnType dataRetVal_u8; /* Return Variable                              */
    (void)OpStatus;

    /* Functionality */
    /* Copy the response length to local buffer */

    #if (DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)
    if(((DID & DCM_OBDDID_MASK_HB) == DCM_RDBIOBDMODE9_RANGE) && ((DID % 0x20) != 0x00))
    {
       /*  Skip ITID and NODI (1byte) in length */
       DidLength[0] = Dcm_DspDspRdbi_Obd.rdbiObdDidLength_u16 - DSP_RDBI_MODE9BUFIDX;
    }
    else
    #endif
    {
       /* Skip PID/OBDMID (1byte) in length */
       DidLength[0] = Dcm_DspDspRdbi_Obd.rdbiObdDidLength_u16 - DSP_RDBI_MODE16BUFIDX;
    }

    dataRetVal_u8 = E_OK;

    return dataRetVal_u8;
}

/*
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20250]
* TRACE[BSW_SWCS_DiagnosticCommunicationManager-20259] */

/**
***************************************************************************************************
* Dcm_DspRdbi_Obd_ReadData - Function to get data of the requested DID

* \param       DID        - Requested DID
* \param       DataLength   - Pointer to store length of the response
* \param       OpStatus     - To store status of request
* \param       ErrorCode     - To store status of error info
* \retval      E_OK           - This function returns E_OK for Positive response
* \retval      DCM_E_PENDING  - This function returns DCM_E_PENDING for Pending response
* \retval      E_NOT_OK       - This function returns E_NOT_OK for Negative response
***************************************************************************************************
*/

Std_ReturnType Dcm_DspRdbi_Obd_ReadData (uint16 DID,uint8* Data,Dcm_OpStatusType OpStatus,
uint16* DataLength, Dcm_NegativeResponseCodeType* ErrorCode)
{
    /* Local Variables */
    Std_ReturnType dataRetVal_u8;   /* Return Variable                            */
    uint16 bufcnt_u16;              /* Variable to hold the index of data buffer  */

    /* Initialisations */

    (void)ErrorCode;
    (void)OpStatus;

    /* Functionality */

    /* Copy the response length */
    #if (DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)
    if(((DID & DCM_OBDDID_MASK_HB) == DCM_RDBIOBDMODE9_RANGE) && ((DID % 0x20) != 0x00))
    {
       /*  Skip ITID and NODI (1byte) in length */
        DataLength[0] = Dcm_DspDspRdbi_Obd.rdbiObdDidLength_u16 - DSP_RDBI_MODE9BUFIDX;
    }
    else
    #endif
    {
       /* Skip PID/OBDMID (1byte) in length */
        DataLength[0] = Dcm_DspDspRdbi_Obd.rdbiObdDidLength_u16 - DSP_RDBI_MODE16BUFIDX;
    }

    /* Copy the data bytes to response buffer */
    for(bufcnt_u16 = 0;bufcnt_u16 < DataLength[0];bufcnt_u16++)
    {
        #if (DCM_CFG_DSP_OBDMODE9_ENABLED != DCM_CFG_OFF)
        if(((DID & DCM_OBDDID_MASK_HB) == DCM_RDBIOBDMODE9_RANGE) && ((DID % 0x20) != 0x00))
        {
            /*  Skip ITID and NODI value*/
            Data[bufcnt_u16] = Dcm_DspRdbiObdDidDataBuffer_a8[bufcnt_u16 + DSP_RDBI_MODE9BUFIDX];
        }
        else
        #endif
        {
            /* Skip PID/OBDMID value */
            Data[bufcnt_u16] = Dcm_DspRdbiObdDidDataBuffer_a8[bufcnt_u16 + DSP_RDBI_MODE16BUFIDX];
        }

    }

    dataRetVal_u8 = E_OK;

    return dataRetVal_u8;

}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif
#endif
