/* Multicast support functions */

#ifndef PDUR_MC_H
#define PDUR_MC_H
/**
\defgroup PDUR_MC_H    PDUR - Protocol Data Unit Router
*/
#include "PduR_Cfg_Internal.h"
#include "PduR_Types.h"
#if defined(PDUR_MULTICAST_TO_IF_SUPPORT) && PDUR_MULTICAST_TO_IF_SUPPORT == 1
#include "PduR_Multicast_TxConfirmation.h"
#endif
/* ------------------------------------------------------------------------ */
/**
 * @ingroup PDUR_MC_H
 *
 * Begin section for code
 */


#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/*begin */

/**
 * @ingroup PDUR_MC_H
 *
 *  This function is Support function to handle multicast from upper layers to lower layers \n
 *
 *  @param  In:      upToLoTable - This parameter represents Multicast routing table \n
 *  @param  In:      mcId - This parameter represents ID of I-PDU to be transmitted \n
 *  @param  Out:     info - This parameter represents a pointer to PduInfoStructure containing SDU data pointer and
 *                          SDU length of a transmit buffer. \n
 *
 *
 *  @return          E_OK: if the request is accepted\n
 *                   E_NOT_OK: if the request is not accepted  just for testing\n
 *
 */
extern Std_ReturnType PduR_MF_UpToLo( const PduR_MT_UpToLo * upToLoTable,
                                                         PduIdType mcId,
                                                         const PduInfoType * info);

/**
 * @ingroup PDUR_MC_H
 *
 *      Support function to handle Cancel Transmission request for multicast routes \n
 *
 * @param  In:      PduR_MT_UpToLo upToLoTable: Multicast routing table \n
 * @param  In:      PduIdType mcId            : ID of I-PDU to be transmitted \n
 *
 * @return          E_OK: if the request is accepted \n
 *                  E_NOT_OK: if the request is not accepted  just for testing \n
 *
 **************************************************************************************************
 */
extern Std_ReturnType PduR_MF_CancelTransmit_UpToLo(const PduR_MT_UpToLo * upToLoTable,
                                                 PduIdType mcId);

/**
 * @ingroup PDUR_MC_H
 *
 *  This function is Support function for multicast transmission via CanIf layers \n
 *
 *  @param  In:      id - This parameter represents the multicast transmission for Can If ID \n
 *
 *  @return None \n
 */
extern void PduR_MF_McIfTx_CanIf_TxConfirmation(PduIdType id,Std_ReturnType result);

/**
 * @ingroup PDUR_MC_H
 *
 *  This function is Support function for multicast transmission via FrIf layers \n
 *
 *  @param  In:      id - This parameter represents the multicast transmission for FrIf ID \n
 *
 *  @return None \n
 */
extern void PduR_MF_McIfTx_FrIf_TxConfirmation( PduIdType id,Std_ReturnType result);

/**
 * @ingroup PDUR_MC_H
 *
 *  This function is Support function for multicast transmission via LinIF layers \n
 *
 *  @param  In:      id - This parameter represents the multicast transmission for LinIF ID \n
 *
 *  @return None \n
 */
extern void PduR_MF_McIfTx_LinIf_TxConfirmation(PduIdType id,Std_ReturnType result);


/* Support functions for multicast transmission via If layers
 * Only needed when combining gatewaying and multicast */
/**
 * @ingroup PDUR_MC_H
 *
 *  This function is Support functions for multicast transmission via If layers
 *  Only needed when combining gatewaying and multicast \n
 *
 *  @param  In:      id - This parameter represents the multicast transmission ID \n
 *  @param  Out:     ptr- This parameter represents the Tx Trigger pointer \n
 *
 *  @return None \n
 */
extern void PduR_MF_McIfTx_TriggerTransmit(PduIdType id, PduInfoType * ptr);
/* CanIf does not support TriggerTransmit */
/**
 * @ingroup PDUR_MC_H
 *
 * FrIf Trigger Transmit
 */
#define PduR_MF_McIfTx_FrIf_TriggerTransmit  PduR_MF_McIfTx_TriggerTransmit

/**
 * @ingroup PDUR_MC_H
 *
 * LinIf Trigger Transmit
 */
#define PduR_MF_McIfTx_LinIf_TriggerTransmit PduR_MF_McIfTx_TriggerTransmit


/* Support functions for multicast transmission via Tp layers */
/* extern BufReq_ReturnType PduR_MF_McTpTx_ProvideTxBuffer( PduIdType mcId,
                                                                            PduInfoType ** ptr,
                                                                            uint16 len);*/

/**
 * @ingroup PDUR_MC_H
 *
 *  Provide the support functions for mapping TpTx callbacks to the upper layer \n
 *
 *  @param  In:      mcId - This parameter represents the multicast ID that has to be transmitted \n
 *  @param  In:      len - This parameter represents the length of the requested transmit buffer \n
 *  @param  Out:     ptr- This parameter represents the pointer to PduInfoStructure containing SDU data pointer and
 *                        SDU length of a transmit buffer. \n
 *
 *  @return         BUFREQ_OK- Buffer request accomplished successful \n
 *  @return         BUFREQ_E_BUSY - Currently no buffer of the requested size is available \n
 *  @return         BUFREQ_E_NOT_OK - Buffer request not successful, no buffer provided \n
 */
extern BufReq_ReturnType PduR_MF_McTpTx_CopyTxData( PduIdType mcId,
                                                                             const PduInfoType * info,
                                                                             const RetryInfoType * retry,
                                                                             PduLengthType * availableDataPtr );

/**
 * @ingroup PDUR_MC_H
 *
 *  Provide the support functions for mapping TpTx callbacks to the upper layer \n
 *
 *  @param  In:      mcId - This parameter represents the multicast ID that has to be transmitted \n
 *  @param  In:      layerId - This parameter represents the layer ID \n
 *  @param  In:      result- Result of the TP reception. \n
 *
 * @return None \n
 */
extern void PduR_MF_McTpTx_TxConfirmation( PduR_LayerType layerId,
                                                              PduIdType mcId,
                                                              Std_ReturnType result);

/**
 * @ingroup PDUR_MC_H
 *
 *  Provide support for multicast transmission via CanTp \n
 *
 *  @param  In:      mcId - multicast ID that has been transmitted \n
 *  @param  Out:     result- Result of the Tx confirmation. \n
 *
 *  @return None \n
 */
extern void PduR_MF_McTpTx_CanTp_TxConfirmation_Func(PduIdType mcId, Std_ReturnType result);

/**
 * @ingroup PDUR_MC_H
 *
 *  Provide support for multicast transmission via FrTp \n
 *
 *  @param  In:      mcId - multicast ID that has been transmitted \n
 *  @param  Out:     result- Result of the Tx confirmation. \n
 *
 *  @return None \n
 */
extern void PduR_MF_McTpTx_FrTp_TxConfirmation_Func( PduIdType mcId, Std_ReturnType result);

/**
 * @ingroup PDUR_MC_H
 *
 *  Provide support for multicast transmission via LinTp \n
 *
 *  @param  In:      mcId - multicast ID that has been transmitted \n
 *  @param  Out:     result- Result of the Tx confirmation. \n
 *
 *  @return None \n
 */
extern void PduR_MF_McTpTx_LinTp_TxConfirmation_Func(PduIdType mcId, Std_ReturnType result);

/**
 * @ingroup PDUR_MC_H
 *
 *  Provide support for multicast transmission via J1939Tp \n
 *
 *  @param  In:      mcId - multicast ID that has been transmitted \n
 *  @param  Out:     result- Result of the Tx confirmation. \n
 *
 *  @return None \n
 */
extern void PduR_MF_McTpTx_J1939Tp_TxConfirmation_Func( PduIdType mcId, Std_ReturnType result);

/**
 * @ingroup PDUR_MC_H
 *
 * CanTp Copy Tx Data
 */
#define PduR_MF_McTpTx_CanTp_CopyTxData_Func  PduR_MF_McTpTx_CopyTxData

/**
 * @ingroup PDUR_MC_H
 *
 * FrTp Copy Tx Data
 */
#define PduR_MF_McTpTx_FrTp_CopyTxData_Func   PduR_MF_McTpTx_CopyTxData

/**
 * @ingroup PDUR_MC_H
 *
 * LinTp Copy Tx Data
 */
#define PduR_MF_McTpTx_LinTp_CopyTxData_Func  PduR_MF_McTpTx_CopyTxData

/*end */

/* ------------------------------------------------------------------------ */
/**
 * @ingroup PDUR_MC_H
 *
 * End section for code
 */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

#endif /* PDUR_MC_H */

