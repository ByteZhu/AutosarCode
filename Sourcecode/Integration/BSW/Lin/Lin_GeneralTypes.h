/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */

#ifndef LIN_GENERAL_TYPES
#define LIN_GENERAL_TYPES

/**
\defgroup LIN_GENERAL_TYPES    LINIF - AUTOSAR interfaces Upper Layer
*/
/*
 ***************************************************************************************************
 * Type definitions
 ***************************************************************************************************
 */

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This typedef is used to represent all valid protected identifier used by Lin_SendFrame(). \n
 *
 */
typedef uint8 Lin_FramePidType;                /* Protected Identifier  */

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This enum is used to specify the Checksum model to be used for the LIN Frame. \n
 *
 * typedef enum { \n
 *   LIN_ENHANCED_CS,                   Enhanced Checksum model \n
 *   LIN_CLASSIC_CS                     Classic Checksum model \n
 * }Lin_FrameCsModelType;
 */
typedef enum
{
    LIN_ENHANCED_CS,
    LIN_CLASSIC_CS
} Lin_FrameCsModelType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This enum is used to specify whether the frame processor is required to transmit the response part of the LIN frame. \n
 *
 * typedef enum { \n
 *   LIN_MASTER_RESPONSE,                   Response is generated from master node. \n
 *   LIN_SLAVE_RESPONSE,                    Response is generated from remote slave node \n
 *   LIN_SLAVE_TO_SLAVE,                    Response is generated from one Slave node to other slave \n
 *   LIN_UNKNOWN_RESPONSE                   Direction of Frame is not known \n
 * }Lin_FrameResponseType;
 */
typedef enum
{
    LIN_MASTER_RESPONSE,
    LIN_SLAVE_RESPONSE,
    LIN_SLAVE_TO_SLAVE,
    LIN_UNKNOWN_RESPONSE
} Lin_FrameResponseType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This typedef is used to specify the number of SDU data bytes to copy. \n
 *
 */
typedef uint8 Lin_FrameDlType;                /* Data length of a LIN frame   */

/**
 * @ingroup LIN_GENERAL_TYPES
 * This structure is used to provide PID, checksum model, data length, frame direction and SDU pointer from the LIN Interface to the LIN driver. \n
 *
 * typedef struct \n
 *  { \n
 *      const uint8 * SduPtr;      Pointer to SDU \n
 *      Lin_FrameCsModelType Cs;                        Checksum model type \n
 *      Lin_FrameResponseType Drc;                      Direction of Frame \n
 *      Lin_FramePidType  Pid;                          Protected identifier of Frame \n
 *      Lin_FrameDlType Dl;                             Data length of frame \n
 * } Lin_PduType ;
 */
typedef struct
{
   const uint8 * SduPtr;
   Lin_FrameCsModelType Cs;
   Lin_FrameResponseType Drc;
   Lin_FramePidType  Pid;
   Lin_FrameDlType Dl;

} Lin_PduType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This enum represents operation states for a LIN channel or frame, as returned by the API service Lin_GetStatus(). \n
 *
 * typedef enum { \n
 *  LIN_NOT_OK,                             Development or production error occurred \n
 *  LIN_TX_OK,                              successful Transmission \n
 *  LIN_TX_BUSY,                            Ongoing Transmission \n
 *  LIN_TX_HEADER_ERROR,                    Error in Header transmission \n
 *  LIN_TX_ERROR,                           Error in Response transmission \n
 *  LIN_RX_OK,                              Reception of Correct response \n
 *  LIN_RX_BUSY,                            Ongoing Reception \n
 *  LIN_RX_ERROR,                           Erroneous response reception \n
 *  LIN_RX_NO_RESPONSE,                     No response byte have received so far \n
 *  LIN_OPERATIONAL,                        Channel is ready for transmission and reception \n
 *  LIN_CH_SLEEP                            Sleep mode operation \n
 * }Lin_StatusType;
 */
typedef enum
{
    LIN_NOT_OK,
    LIN_TX_OK,
    LIN_TX_BUSY,
    LIN_TX_HEADER_ERROR,
    LIN_TX_ERROR,
    LIN_RX_OK,
    LIN_RX_BUSY,
    LIN_RX_ERROR,
    LIN_RX_NO_RESPONSE,
    LIN_OPERATIONAL,
    LIN_CH_SLEEP
} Lin_StatusType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This enum represents the different operating modes of the LIN Transceiver Driver. \n
 *
 * typedef enum { \n
 *   LINTRCV_TRCV_MODE_NORMAL,                  Transceiver mode NORMAL \n
 *   LINTRCV_TRCV_MODE_STANDBY,                 Transceiver mode STANDBY \n
 *   LINTRCV_TRCV_MODE_SLEEP                    Transceiver mode SLEEP \n
 * }LinTrcv_TrcvModeType;
 */
typedef enum
{
    LINTRCV_TRCV_MODE_NORMAL,
    LINTRCV_TRCV_MODE_STANDBY,
    LINTRCV_TRCV_MODE_SLEEP
} LinTrcv_TrcvModeType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This typedef is Index of the schedule table that is selectable and followed by LIN Interface. Value is unique per LIN channel/controller, but not per ECU.
 *  The number of schedule tables is limited to 255\n
 *
 */
typedef uint8   LinIf_SchHandleType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This enum denotes the wake up reason detected by the LIN transceiver in detail. \n
 *
 * typedef enum { \n
 *   LINIF_TRCV_WU_ERROR,                   Due to an error wake up reason was not detected. This value may only be reported when error was reported to DEM before. \n
 *   LINIF_TRCV_WU_NOT_SUPPORTED,           The transceiver does not support any information for the wake up reason. \n
 *   LINIF_TRCV_WU_BY_BUS,                  The transceiver has detected, that the network has caused the wake up of the ECU.  \n
 *   LINIF_TRCV_WU_BY_PIN,                  The transceiver has detected a wake-up event at one of the transceiver's pins (not at the LIN bus). \n
 *   LINIF_TRCV_WU_INTERNALLY,              The transceiver has detected, that the network has woken up by the ECU via a request to NORMAL mode. \n
 *   LINIF_TRCV_WU_RESET,                   The transceiver has detected, that the wake up is due to an ECU reset. \n
 *   LINIF_TRCV_WU_POWER_ON                 The transceiver has detected, that the wake up is due to an ECU reset after power on. \n
 * }LinIf_TrcvWakeupReasonType;
 */
typedef enum
{
    LINIF_TRCV_WU_ERROR,
    LINIF_TRCV_WU_NOT_SUPPORTED,
    LINIF_TRCV_WU_BY_BUS,
    LINIF_TRCV_WU_BY_PIN,
    LINIF_TRCV_WU_INTERNALLY,
    LINIF_TRCV_WU_RESET,
    LINIF_TRCV_WU_POWER_ON
} LinIf_TrcvWakeupReasonType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This enum is represents the wake up operating modes of the LIN Transceiver Driver. \n
 *
 * typedef enum { \n
 *   LINIF_TRCV_WU_ENABLE,                  The notification for wakeup events is enabled on the addressed network. \n
 *   LINIF_TRCV_WU_DISABLE,                 The notification for wakeup events is disabled on the addressed network. \n
 *   LINIF_TRCV_WU_CLEAR                    A stored wakeup event is cleared on the addressed network. \n
 * }LinIf_TrcvWakeupModeType;
 */
typedef enum
{
    LINIF_TRCV_WU_ENABLE,
    LINIF_TRCV_WU_DISABLE,
    LINIF_TRCV_WU_CLEAR
} LinIf_TrcvWakeupModeType;

/**
 * @ingroup LIN_GENERAL_TYPES
 *  This enum denotes which Schedule table can be requested by LIN TP during diagnostic session \n
 *
 * typedef enum { \n
 *   LINTP_APPLICATIVE_SCHEDULE,            Applicative schedule is selected \n
 *   LINTP_DIAG_REQUEST,                    Master request schedule table is selected \n
 *   LINTP_DIAG_RESPONSE                    Slave response schedule table is selected \n
 * }LinTp_Mode;
 */
typedef enum {
  LINTP_APPLICATIVE_SCHEDULE,
  LINTP_DIAG_REQUEST,
  LINTP_DIAG_RESPONSE
} LinTp_Mode;

#endif  /* LIN_GENERAL_TYPES */

