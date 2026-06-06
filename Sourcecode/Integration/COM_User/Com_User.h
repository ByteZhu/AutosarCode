#include "Std_Types.h"
//APP_rx
typedef enum {

  CANBUS_ID_0x50=0, /* Default value */
  CANBUS_ID_0x51,
  CANBUS_ID_0x52,
  CANBUS_ID_0x201,
  CANBUS_ID_0x62,
  CANBUS_ID_0x200,
  CANBUS_ID_0x400,
  CANBUS_ID_0x40,
  CANBUS_ID_0x234,
  CANBUS_ID_0x99,
  CANBUS_ID_0xfe,
  CANBUS_Num
} CANFlag;
extern uint8 COMTimeoutFlag[CANBUS_Num];
extern uint8 COMRxFlag[CANBUS_Num];
extern uint8 COMRxLostFlag[CANBUS_Num];
extern uint8 COMRxVailFlag[CANBUS_Num];
extern uint8 COMRxVailFlag1[CANBUS_Num];
extern uint8 COMRxVailFlag2[CANBUS_Num];
extern uint8 COMRxVailFlag3[CANBUS_Num];
extern uint8 COMRxVailFlag4[CANBUS_Num];
extern uint8 EtcToPscmDevelFr_UpdateFlag;
//ÖÜÆÚ·¢ËÍ´¥·¢±êÖ¾£¬ÓÃÓÚ¸üÐÂASW_COMÖÐµÄCounterÖµ
extern unsigned char Tx_SACM_SecCanFrame01_Flag;
extern unsigned char Tx_SACMFram01_Flag;
extern unsigned char Tx_SACMFram02_Flag;
extern unsigned char Tx_SFCMBCCanFDFrame01_Flag;
