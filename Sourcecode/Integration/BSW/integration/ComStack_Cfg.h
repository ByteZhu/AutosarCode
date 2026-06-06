 

/*
*******************************************************************************************************************
* Based on AUTOSAR_SWS_CommunicationStackTypes.pdf; AR4.2; Rev 2 and BSW_CodingGuidelines_Cur_v.1.10.pdf
*******************************************************************************************************************
*/

/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */
#ifndef NOT_READY_FOR_TESTING_OR_DEPLOYMENT
#error The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#else
#warning The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#endif /* NOT_READY_FOR_TESTING_OR_DEPLOYMENT */


/* TRACE[SWS_COMTYPE_00016]: protected against multiple inclusion. */
#ifndef COMSTACK_CFG_H
#define COMSTACK_CFG_H


/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

/* TRACE[Rule BSW_VersionInfo_004]: Software Version Number and AUTOSAR Specification Version Number. */
/* TRACE[SRS_BSW_00374]  */
#define COMTYPE_SW_MAJOR_VERSION 0x09u
#define COMTYPE_SW_MINOR_VERSION 0x00u
#define COMTYPE_SW_PATCH_VERSION 0x01u
#define COMTYPE_AR_RELEASE_MAJOR_VERSION 0x04u
#define COMTYPE_AR_RELEASE_MINOR_VERSION 0x05u
#define COMTYPE_AR_RELEASE_REVISION_VERSION 0x00u

 

/*
*******************************************************************************************************************
* Types and Defines
*******************************************************************************************************************
*/


/* TRACE[SWS_COMTYPE_00005], TRACE[SWS_COMTYPE_00029] and TRACE[SWS_COMTYPE_00030]:
  Type of PDU ID. Allowed ranges: uint8/uint16 */
typedef uint16    PduIdType;

/* TRACE[SWS_COMTYPE_00008], TRACE[SWS_COMTYPE_00029] and TRACE[SWS_COMTYPE_00030]:
  Type of PDU Length. Allowed ranges: uint8/uint16/uint32 */
typedef uint16    PduLengthType;



  
/*TRACE[SWS_COMTYPE_00011]:Variables of this type shall be used to store the basic information about a PDU of any type, 
namely a pointer variable pointing to its SDU (payload), a pointer to Meta Data of the PDU, 
and the corresponding length of the SDU in bytes. */

typedef struct
{
    uint8 * SduDataPtr;
    uint8 * MetaDataPtr;
    PduLengthType SduLength;
} PduInfoType;

#define ECUC_RB_METADATA_ENABLE (TRUE)

 


 


#endif /* COMSTACK_CFG_H */

