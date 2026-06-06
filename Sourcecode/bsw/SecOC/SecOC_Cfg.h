/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.SecOC
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/

#ifndef SECOC_CFG_H
#define SECOC_CFG_H

/**
 * \brief Header file providing configuration parameters for the SecOC module.
 * \addtogroup SecOC
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "SecOC_Types.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/


#define SECOC_NR_CONFIGSETS 1
/* Declare index of SecOC_Config sets */
extern const SecOC_ConfigType SecOC_Config;


/*
 * Defines of symbolic names of Rx secured PDU
 */
 /* for function SecOC_RxIndication, SecOC_StartOfReception, SecOC_CopyRxData and SecOC_TpRxIndication */
#define SecOCConf_SecOCRxSecuredPdu_CSCBCMCore_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN 0U
#define SecOCConf_SecOCRxSecuredPdu_CSCBCMCore_SecCanFrame02_PduR2SecOC_Can_Network_0_Channel_CAN 1U
#define SecOCConf_SecOCRxSecuredPdu_CSCBCMCore_SecCanFrame03_PduR2SecOC_Can_Network_0_Channel_CAN 2U
#define SecOCConf_SecOCRxSecuredPdu_CSCBCMCore_SpecialSecFrame01_PduR2SecOC_Can_Network_0_Channel_CAN 3U



/*
 * Defines of symbolic names of Rx authentic PDU
 */
 /* for function SecOC_TpCancelReceive */
#define SecOCConf_SecOCRxAuthenticPduLayer_CSCBCMCore_SecCanFrame01_SecOC2PduR_Can_Network_0_Channel_CAN 0U
#define SecOCConf_SecOCRxAuthenticPduLayer_CSCBCMCore_SecCanFrame02_SecOC2PduR_Can_Network_0_Channel_CAN 1U
#define SecOCConf_SecOCRxAuthenticPduLayer_CSCBCMCore_SecCanFrame03_SecOC2PduR_Can_Network_0_Channel_CAN 2U
#define SecOCConf_SecOCRxAuthenticPduLayer_CSCBCMCore_SpecialSecFrame01_SecOC2PduR_Can_Network_0_Channel_CAN 3U

/*
 * Defines of symbolic names of Tx authentic PDU
 */
 /* for function SecOC_If|TpTransmit */
#define SecOCConf_SecOCTxAuthenticPduLayer_PSCMSACM_SecCanFrame01_PduR2SecOC_Can_Network_0_Channel_CAN 0U

/*
 * Defines of symbolic names of Tx secured PDU
 */
 /* for function SecOC_TxConfirmation, SecOC_CopyTxData, SecOC_TpTxConfirmation and SecOC_TriggerTransmit */
#define SecOCConf_SecOCTxSecuredPdu_PSCMSACM_SecCanFrame01_SecOC2PduR_Can_Network_0_Channel_CAN 0U

/*
 * Defines of symbolic names of Tx PDU collection
 */
 /* for function SecOC_TxConfirmation, SecOC_TpTxConfirmation and  SecOC_TriggerTransmit */


#endif /* SECOC_CFG_H */

